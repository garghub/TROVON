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
T_3 void F_21 ( void )
{
F_22 () ;
}
static int F_23 ( int V_32 )
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
static void F_24 ( struct V_1 * V_2 ,
unsigned V_16 , bool V_42 , T_1 V_43 ,
bool V_44 )
{
T_1 V_45 ;
int V_46 , V_47 ;
F_25 ( V_48 , V_2 ) ;
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
F_25 ( V_54 , V_2 ) ;
return;
}
V_46 = F_23 ( V_45 ) ;
V_47 = F_23 ( V_16 ) ;
if ( ( V_46 == V_40 && V_47 == V_40 )
|| ( V_46 == V_34 && V_47 != V_41 ) ) {
V_2 -> V_5 . V_49 . V_50 = true ;
V_2 -> V_5 . V_49 . V_52 = true ;
V_2 -> V_5 . V_49 . V_16 = V_53 ;
V_2 -> V_5 . V_49 . V_43 = 0 ;
} else
goto V_51;
}
void F_26 ( struct V_1 * V_2 , unsigned V_16 )
{
F_24 ( V_2 , V_16 , false , 0 , false ) ;
}
void F_27 ( struct V_1 * V_2 , unsigned V_16 )
{
F_24 ( V_2 , V_16 , false , 0 , true ) ;
}
void F_28 ( struct V_1 * V_2 , int V_55 )
{
if ( V_55 )
F_29 ( V_2 , 0 ) ;
else
V_56 -> V_57 ( V_2 ) ;
}
void F_30 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
++ V_2 -> V_60 . V_61 ;
V_2 -> V_5 . V_62 = V_59 -> V_63 ;
F_31 ( V_2 , V_33 , V_59 -> V_43 ) ;
}
void F_32 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
if ( F_33 ( V_2 ) && ! V_59 -> V_64 )
V_2 -> V_5 . V_65 . V_66 ( V_2 , V_59 ) ;
else
V_2 -> V_5 . V_67 . V_66 ( V_2 , V_59 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_5 . V_68 ) ;
F_25 ( V_69 , V_2 ) ;
}
void F_31 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_43 )
{
F_24 ( V_2 , V_16 , true , V_43 , false ) ;
}
void F_36 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_43 )
{
F_24 ( V_2 , V_16 , true , V_43 , true ) ;
}
bool F_37 ( struct V_1 * V_2 , int V_70 )
{
if ( V_56 -> V_71 ( V_2 ) <= V_70 )
return true ;
F_31 ( V_2 , V_39 , 0 ) ;
return false ;
}
int F_38 ( struct V_1 * V_2 , struct V_72 * V_67 ,
T_4 V_73 , void * V_31 , int V_74 , int V_75 ,
T_1 V_76 )
{
T_4 V_77 ;
T_5 V_78 ;
V_78 = F_39 ( V_73 ) ;
V_77 = V_67 -> V_79 ( V_2 , V_78 , V_76 ) ;
if ( V_77 == V_80 )
return - V_81 ;
V_77 = F_40 ( V_77 ) ;
return F_41 ( V_2 -> V_82 , V_77 , V_31 , V_74 , V_75 ) ;
}
int F_42 ( struct V_1 * V_2 , T_4 V_83 ,
void * V_31 , int V_74 , int V_75 , T_1 V_76 )
{
return F_38 ( V_2 , V_2 -> V_5 . V_84 , V_83 ,
V_31 , V_74 , V_75 , V_76 ) ;
}
int F_43 ( struct V_1 * V_2 , struct V_72 * V_67 , unsigned long V_85 )
{
T_4 V_86 = V_85 >> V_87 ;
unsigned V_74 = ( ( V_85 & ( V_88 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_89 ;
T_2 V_90 [ F_44 ( V_67 -> V_91 ) ] ;
V_89 = F_38 ( V_2 , V_67 , V_86 , V_90 ,
V_74 * sizeof( T_2 ) , sizeof( V_90 ) ,
V_92 | V_93 ) ;
if ( V_89 < 0 ) {
V_89 = 0 ;
goto V_94;
}
for ( V_3 = 0 ; V_3 < F_44 ( V_90 ) ; ++ V_3 ) {
if ( F_45 ( V_90 [ V_3 ] ) &&
( V_90 [ V_3 ] & V_2 -> V_5 . V_67 . V_95 [ 0 ] [ 2 ] ) ) {
V_89 = 0 ;
goto V_94;
}
}
V_89 = 1 ;
memcpy ( V_67 -> V_91 , V_90 , sizeof( V_67 -> V_91 ) ) ;
F_46 ( V_96 ,
( unsigned long * ) & V_2 -> V_5 . V_97 ) ;
F_46 ( V_96 ,
( unsigned long * ) & V_2 -> V_5 . V_98 ) ;
V_94:
return V_89 ;
}
static bool F_47 ( struct V_1 * V_2 )
{
T_2 V_90 [ F_44 ( V_2 -> V_5 . V_84 -> V_91 ) ] ;
bool V_99 = true ;
int V_74 ;
T_4 V_83 ;
int V_100 ;
if ( F_48 ( V_2 ) || ! F_49 ( V_2 ) )
return false ;
if ( ! F_50 ( V_96 ,
( unsigned long * ) & V_2 -> V_5 . V_97 ) )
return true ;
V_83 = ( F_51 ( V_2 ) & ~ 31u ) >> V_87 ;
V_74 = ( F_51 ( V_2 ) & ~ 31u ) & ( V_88 - 1 ) ;
V_100 = F_42 ( V_2 , V_83 , V_90 , V_74 , sizeof( V_90 ) ,
V_92 | V_93 ) ;
if ( V_100 < 0 )
goto V_94;
V_99 = memcmp ( V_90 , V_2 -> V_5 . V_84 -> V_91 , sizeof( V_90 ) ) != 0 ;
V_94:
return V_99 ;
}
int F_52 ( struct V_1 * V_2 , unsigned long V_101 )
{
unsigned long V_102 = F_53 ( V_2 ) ;
unsigned long V_103 = V_104 | V_105 |
V_106 | V_107 ;
V_101 |= V_108 ;
#ifdef F_54
if ( V_101 & 0xffffffff00000000UL )
return 1 ;
#endif
V_101 &= ~ V_109 ;
if ( ( V_101 & V_107 ) && ! ( V_101 & V_106 ) )
return 1 ;
if ( ( V_101 & V_104 ) && ! ( V_101 & V_110 ) )
return 1 ;
if ( ! F_55 ( V_2 ) && ( V_101 & V_104 ) ) {
#ifdef F_54
if ( ( V_2 -> V_5 . V_111 & V_112 ) ) {
int V_113 , V_114 ;
if ( ! F_49 ( V_2 ) )
return 1 ;
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
if ( V_114 )
return 1 ;
} else
#endif
if ( F_49 ( V_2 ) && ! F_43 ( V_2 , V_2 -> V_5 . V_84 ,
F_51 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_101 & V_104 ) && F_56 ( V_2 , V_116 ) )
return 1 ;
V_56 -> V_117 ( V_2 , V_101 ) ;
if ( ( V_101 ^ V_102 ) & V_104 ) {
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_101 ^ V_102 ) & V_103 )
F_58 ( V_2 ) ;
return 0 ;
}
void F_59 ( struct V_1 * V_2 , unsigned long V_118 )
{
( void ) F_52 ( V_2 , F_60 ( V_2 , ~ 0x0eul ) | ( V_118 & 0x0f ) ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( F_56 ( V_2 , V_119 ) &&
! V_2 -> V_120 ) {
F_62 ( V_121 , V_2 -> V_5 . V_122 ) ;
V_2 -> V_120 = 1 ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_120 ) {
if ( V_2 -> V_5 . V_122 != V_123 )
F_62 ( V_121 , V_123 ) ;
V_2 -> V_120 = 0 ;
}
}
int F_64 ( struct V_1 * V_2 , T_1 V_124 , T_2 V_125 )
{
T_2 V_122 ;
T_2 V_126 ;
if ( V_124 != V_121 )
return 1 ;
V_122 = V_125 ;
if ( ! ( V_122 & V_127 ) )
return 1 ;
if ( ( V_122 & V_128 ) && ! ( V_122 & V_129 ) )
return 1 ;
V_126 = V_2 -> V_5 . V_130 | V_127 ;
if ( V_122 & ~ V_126 )
return 1 ;
F_63 ( V_2 ) ;
V_2 -> V_5 . V_122 = V_122 ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 , T_1 V_124 , T_2 V_125 )
{
if ( V_56 -> V_71 ( V_2 ) != 0 ||
F_64 ( V_2 , V_124 , V_125 ) ) {
F_29 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_66 ( struct V_1 * V_2 , unsigned long V_131 )
{
unsigned long V_132 = F_67 ( V_2 ) ;
unsigned long V_133 = V_134 | V_135 |
V_136 | V_137 ;
if ( V_131 & V_138 )
return 1 ;
if ( ! F_68 ( V_2 ) && ( V_131 & V_119 ) )
return 1 ;
if ( ! F_69 ( V_2 ) && ( V_131 & V_137 ) )
return 1 ;
if ( ! F_70 ( V_2 ) && ( V_131 & V_139 ) )
return 1 ;
if ( F_48 ( V_2 ) ) {
if ( ! ( V_131 & V_136 ) )
return 1 ;
} else if ( F_55 ( V_2 ) && ( V_131 & V_136 )
&& ( ( V_131 ^ V_132 ) & V_133 )
&& ! F_43 ( V_2 , V_2 -> V_5 . V_84 ,
F_51 ( V_2 ) ) )
return 1 ;
if ( ( V_131 & V_116 ) && ! ( V_132 & V_116 ) ) {
if ( ! F_71 ( V_2 ) )
return 1 ;
if ( ( F_51 ( V_2 ) & V_140 ) || ! F_48 ( V_2 ) )
return 1 ;
}
if ( V_56 -> V_141 ( V_2 , V_131 ) )
return 1 ;
if ( ( ( V_131 ^ V_132 ) & V_133 ) ||
( ! ( V_131 & V_116 ) && ( V_132 & V_116 ) ) )
F_58 ( V_2 ) ;
if ( ( V_131 ^ V_132 ) & V_119 )
F_72 ( V_2 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 , unsigned long V_85 )
{
if ( V_85 == F_51 ( V_2 ) && ! F_47 ( V_2 ) ) {
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
return 0 ;
}
if ( F_48 ( V_2 ) ) {
if ( F_56 ( V_2 , V_116 ) ) {
if ( V_85 & V_142 )
return 1 ;
} else
if ( V_85 & V_143 )
return 1 ;
} else {
if ( F_49 ( V_2 ) ) {
if ( V_85 & V_144 )
return 1 ;
if ( F_55 ( V_2 ) &&
! F_43 ( V_2 , V_2 -> V_5 . V_84 , V_85 ) )
return 1 ;
}
}
V_2 -> V_5 . V_85 = V_85 ;
F_46 ( V_145 , ( V_146 * ) & V_2 -> V_5 . V_97 ) ;
F_76 ( V_2 ) ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 , unsigned long V_147 )
{
if ( V_147 & V_148 )
return 1 ;
if ( F_78 ( V_2 -> V_82 ) )
F_79 ( V_2 , V_147 ) ;
else
V_2 -> V_5 . V_147 = V_147 ;
return 0 ;
}
unsigned long F_80 ( struct V_1 * V_2 )
{
if ( F_78 ( V_2 -> V_82 ) )
return F_81 ( V_2 ) ;
else
return V_2 -> V_5 . V_147 ;
}
static void F_82 ( struct V_1 * V_2 )
{
unsigned long V_149 ;
if ( V_2 -> V_150 & V_151 )
V_149 = V_2 -> V_5 . V_152 ;
else
V_149 = V_2 -> V_5 . V_149 ;
V_56 -> V_153 ( V_2 , V_149 ) ;
V_2 -> V_5 . V_154 = ( V_149 & V_155 ) ;
}
static int F_83 ( struct V_1 * V_2 , int V_156 , unsigned long V_157 )
{
switch ( V_156 ) {
case 0 ... 3 :
V_2 -> V_5 . V_158 [ V_156 ] = V_157 ;
if ( ! ( V_2 -> V_150 & V_151 ) )
V_2 -> V_5 . V_159 [ V_156 ] = V_157 ;
break;
case 4 :
if ( F_56 ( V_2 , V_160 ) )
return 1 ;
case 6 :
if ( V_157 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_161 = ( V_157 & V_162 ) | V_163 ;
break;
case 5 :
if ( F_56 ( V_2 , V_160 ) )
return 1 ;
default:
if ( V_157 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_149 = ( V_157 & V_164 ) | V_165 ;
F_82 ( V_2 ) ;
break;
}
return 0 ;
}
int F_84 ( struct V_1 * V_2 , int V_156 , unsigned long V_157 )
{
int V_166 ;
V_166 = F_83 ( V_2 , V_156 , V_157 ) ;
if ( V_166 > 0 )
F_26 ( V_2 , V_167 ) ;
else if ( V_166 < 0 )
F_29 ( V_2 , 0 ) ;
return V_166 ;
}
static int F_85 ( struct V_1 * V_2 , int V_156 , unsigned long * V_157 )
{
switch ( V_156 ) {
case 0 ... 3 :
* V_157 = V_2 -> V_5 . V_158 [ V_156 ] ;
break;
case 4 :
if ( F_56 ( V_2 , V_160 ) )
return 1 ;
case 6 :
* V_157 = V_2 -> V_5 . V_161 ;
break;
case 5 :
if ( F_56 ( V_2 , V_160 ) )
return 1 ;
default:
* V_157 = V_2 -> V_5 . V_149 ;
break;
}
return 0 ;
}
int F_86 ( struct V_1 * V_2 , int V_156 , unsigned long * V_157 )
{
if ( F_85 ( V_2 , V_156 , V_157 ) ) {
F_26 ( V_2 , V_167 ) ;
return 1 ;
}
return 0 ;
}
bool F_87 ( struct V_1 * V_2 )
{
T_1 V_168 = F_88 ( V_2 , V_169 ) ;
T_2 V_31 ;
int V_55 ;
V_55 = F_89 ( V_2 , V_168 , & V_31 ) ;
if ( V_55 )
return V_55 ;
F_90 ( V_2 , V_170 , ( T_1 ) V_31 ) ;
F_90 ( V_2 , V_171 , V_31 >> 32 ) ;
return V_55 ;
}
bool F_91 ( struct V_1 * V_2 , T_2 V_111 )
{
if ( V_111 & V_172 )
return false ;
if ( V_111 & V_173 ) {
struct V_174 * V_175 ;
V_175 = F_92 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_175 || ! ( V_175 -> V_176 & F_93 ( V_177 ) ) )
return false ;
}
if ( V_111 & V_178 ) {
struct V_174 * V_175 ;
V_175 = F_92 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_175 || ! ( V_175 -> V_168 & F_93 ( V_179 ) ) )
return false ;
}
return true ;
}
static int F_94 ( struct V_1 * V_2 , T_2 V_111 )
{
T_2 V_180 = V_2 -> V_5 . V_111 ;
if ( ! F_91 ( V_2 , V_111 ) )
return 1 ;
if ( F_55 ( V_2 )
&& ( V_2 -> V_5 . V_111 & V_112 ) != ( V_111 & V_112 ) )
return 1 ;
V_111 &= ~ V_181 ;
V_111 |= V_2 -> V_5 . V_111 & V_181 ;
V_56 -> F_94 ( V_2 , V_111 ) ;
if ( ( V_111 ^ V_180 ) & V_182 )
F_58 ( V_2 ) ;
return 0 ;
}
void F_95 ( T_2 V_27 )
{
V_172 &= ~ V_27 ;
}
int F_96 ( struct V_1 * V_2 , struct V_183 * V_21 )
{
return V_56 -> V_184 ( V_2 , V_21 ) ;
}
static int F_97 ( struct V_1 * V_2 , unsigned V_124 , T_2 * V_31 )
{
struct V_183 V_21 ;
V_21 . V_31 = * V_31 ;
V_21 . V_124 = V_124 ;
V_21 . V_185 = true ;
return F_96 ( V_2 , & V_21 ) ;
}
static void F_98 ( struct V_186 * V_187 )
{
struct V_188 * V_189 = & V_188 ;
F_99 ( & V_189 -> V_190 ) ;
V_189 -> clock . V_191 = V_187 -> clock -> V_192 . V_191 ;
V_189 -> clock . V_193 = V_187 -> clock -> V_193 ;
V_189 -> clock . V_27 = V_187 -> clock -> V_27 ;
V_189 -> clock . V_194 = V_187 -> V_194 ;
V_189 -> clock . V_195 = V_187 -> V_195 ;
V_189 -> V_196 = V_187 -> V_197
+ V_187 -> V_198 . V_199 ;
V_189 -> V_200 = V_187 -> V_201
+ ( V_187 -> V_198 . V_202
<< V_187 -> V_195 ) ;
while ( V_189 -> V_200 >=
( ( ( T_2 ) V_203 ) << V_187 -> V_195 ) ) {
V_189 -> V_200 -=
( ( T_2 ) V_203 ) << V_187 -> V_195 ;
V_189 -> V_196 ++ ;
}
F_100 ( & V_189 -> V_190 ) ;
}
static void F_101 ( struct V_82 * V_82 , T_5 V_204 )
{
int V_205 ;
int V_100 ;
struct V_206 V_207 ;
struct V_208 V_209 ;
if ( ! V_204 )
return;
V_100 = F_102 ( V_82 , V_204 , & V_205 , sizeof( V_205 ) ) ;
if ( V_100 )
return;
if ( V_205 & 1 )
++ V_205 ;
++ V_205 ;
F_103 ( V_82 , V_204 , & V_205 , sizeof( V_205 ) ) ;
F_104 ( & V_209 ) ;
if ( V_82 -> V_5 . V_210 ) {
struct V_208 V_211 = F_105 ( V_82 -> V_5 . V_210 ) ;
V_209 = F_106 ( V_209 , V_211 ) ;
}
V_207 . V_212 = V_209 . V_199 ;
V_207 . V_213 = V_209 . V_202 ;
V_207 . V_205 = V_205 ;
F_103 ( V_82 , V_204 , & V_207 , sizeof( V_207 ) ) ;
V_205 ++ ;
F_103 ( V_82 , V_204 , & V_205 , sizeof( V_205 ) ) ;
}
static T_6 F_107 ( T_6 V_214 , T_6 V_215 )
{
T_6 V_216 , V_217 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_216 ;
}
static void F_108 ( T_6 V_218 , T_6 V_219 ,
T_7 * V_220 , T_1 * V_221 )
{
T_8 V_222 ;
T_9 V_195 = 0 ;
T_8 V_223 ;
T_6 V_224 ;
V_223 = V_219 * 1000LL ;
V_222 = V_218 * 1000LL ;
while ( V_223 > V_222 * 2 || V_223 & 0xffffffff00000000ULL ) {
V_223 >>= 1 ;
V_195 -- ;
}
V_224 = ( T_6 ) V_223 ;
while ( V_224 <= V_222 || V_222 & 0xffffffff00000000ULL ) {
if ( V_222 & 0xffffffff00000000ULL || V_224 & 0x80000000 )
V_222 >>= 1 ;
else
V_224 <<= 1 ;
V_195 ++ ;
}
* V_220 = V_195 ;
* V_221 = F_107 ( V_222 , V_224 ) ;
F_109 ( L_2 ,
V_225 , V_219 , V_218 , V_195 , * V_221 ) ;
}
static inline T_2 F_110 ( void )
{
struct V_208 V_211 ;
F_111 ( F_112 () ) ;
F_113 ( & V_211 ) ;
F_114 ( & V_211 ) ;
return F_115 ( & V_211 ) ;
}
static inline T_2 F_116 ( struct V_1 * V_2 , T_2 V_213 )
{
return F_117 ( V_213 , V_2 -> V_5 . V_226 ,
V_2 -> V_5 . V_227 ) ;
}
static T_1 F_118 ( T_1 V_228 , T_10 V_229 )
{
T_2 V_230 = ( T_2 ) V_228 * ( 1000000 + V_229 ) ;
F_119 ( V_230 , 1000000 ) ;
return V_230 ;
}
static void F_120 ( struct V_1 * V_2 , T_1 V_231 )
{
T_1 V_232 , V_233 ;
int V_234 = 0 ;
if ( V_231 == 0 )
return;
F_108 ( V_231 , V_203 / 1000 ,
& V_2 -> V_5 . V_227 ,
& V_2 -> V_5 . V_226 ) ;
V_2 -> V_5 . V_235 = V_231 ;
V_232 = F_118 ( V_236 , - V_237 ) ;
V_233 = F_118 ( V_236 , V_237 ) ;
if ( V_231 < V_232 || V_231 > V_233 ) {
F_109 ( L_3 , V_231 , V_232 , V_233 ) ;
V_234 = 1 ;
}
V_56 -> V_238 ( V_2 , V_231 , V_234 ) ;
}
static T_2 F_121 ( struct V_1 * V_2 , T_11 V_239 )
{
T_2 V_240 = F_117 ( V_239 - V_2 -> V_5 . V_241 ,
V_2 -> V_5 . V_226 ,
V_2 -> V_5 . V_227 ) ;
V_240 += V_2 -> V_5 . V_242 ;
return V_240 ;
}
void F_122 ( struct V_1 * V_2 )
{
#ifdef F_54
bool V_243 ;
bool V_244 = false ;
struct V_245 * V_246 = & V_2 -> V_82 -> V_5 ;
struct V_188 * V_247 = & V_188 ;
V_243 = ( V_246 -> V_248 + 1 ==
F_123 ( & V_2 -> V_82 -> V_249 ) ) ;
if ( V_243 && V_247 -> clock . V_191 == V_250 )
if ( ! V_246 -> V_251 )
V_244 = 1 ;
if ( ! V_243 && V_246 -> V_251 )
V_244 = 1 ;
if ( V_244 )
F_25 ( V_252 , V_2 ) ;
F_124 ( V_2 -> V_253 , V_246 -> V_248 ,
F_123 ( & V_2 -> V_82 -> V_249 ) ,
V_246 -> V_251 , V_247 -> clock . V_191 ) ;
#endif
}
static void F_125 ( struct V_1 * V_2 , T_11 V_74 )
{
T_2 V_254 = V_56 -> V_255 ( V_2 ) ;
V_2 -> V_5 . V_256 += V_74 - V_254 ;
}
void F_126 ( struct V_1 * V_2 , struct V_183 * V_21 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
T_2 V_74 , V_257 , V_258 ;
unsigned long V_259 ;
T_11 V_260 ;
bool V_261 ;
T_2 V_31 = V_21 -> V_31 ;
F_127 ( & V_82 -> V_5 . V_262 , V_259 ) ;
V_74 = V_56 -> V_263 ( V_2 , V_31 ) ;
V_257 = F_110 () ;
V_258 = V_257 - V_82 -> V_5 . V_264 ;
if ( V_2 -> V_5 . V_235 ) {
int V_265 = 0 ;
V_260 = V_31 - V_82 -> V_5 . V_266 ;
#ifdef F_54
V_260 = ( V_260 * 1000 ) / V_2 -> V_5 . V_235 ;
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
F_119 ( V_258 , 1000 ) ;
V_260 -= V_258 ;
if ( V_260 < 0 )
V_260 = - V_260 ;
if ( V_265 )
V_260 = V_267 ;
} else
V_260 = V_267 ;
if ( V_260 < V_267 &&
V_2 -> V_5 . V_235 == V_82 -> V_5 . V_268 ) {
if ( ! F_128 () ) {
V_74 = V_82 -> V_5 . V_269 ;
F_109 ( L_4 , V_31 ) ;
} else {
T_2 V_270 = F_116 ( V_2 , V_258 ) ;
V_31 += V_270 ;
V_74 = V_56 -> V_263 ( V_2 , V_31 ) ;
F_109 ( L_5 , V_270 ) ;
}
V_261 = true ;
} else {
V_82 -> V_5 . V_271 ++ ;
V_82 -> V_5 . V_272 = V_257 ;
V_82 -> V_5 . V_273 = V_31 ;
V_82 -> V_5 . V_269 = V_74 ;
V_261 = false ;
F_109 ( L_6 ,
V_82 -> V_5 . V_271 , V_31 ) ;
}
V_82 -> V_5 . V_264 = V_257 ;
V_82 -> V_5 . V_266 = V_31 ;
V_82 -> V_5 . V_268 = V_2 -> V_5 . V_235 ;
V_2 -> V_5 . V_274 . V_275 = 0 ;
V_2 -> V_5 . V_276 = V_31 ;
V_2 -> V_5 . V_277 = V_82 -> V_5 . V_271 ;
V_2 -> V_5 . V_241 = V_82 -> V_5 . V_272 ;
V_2 -> V_5 . V_242 = V_82 -> V_5 . V_273 ;
if ( F_129 ( V_2 ) && ! V_21 -> V_185 )
F_125 ( V_2 , V_74 ) ;
V_56 -> V_278 ( V_2 , V_74 ) ;
F_130 ( & V_82 -> V_5 . V_262 , V_259 ) ;
F_131 ( & V_82 -> V_5 . V_279 ) ;
if ( V_261 )
V_82 -> V_5 . V_248 ++ ;
else
V_82 -> V_5 . V_248 = 0 ;
F_122 ( V_2 ) ;
F_132 ( & V_82 -> V_5 . V_279 ) ;
}
static T_12 F_133 ( void )
{
T_12 V_89 ;
T_2 V_280 ;
F_134 () ;
V_89 = ( T_12 ) F_135 () ;
V_280 = V_188 . clock . V_193 ;
if ( F_136 ( V_89 >= V_280 ) )
return V_89 ;
asm volatile ("");
return V_280 ;
}
static inline T_2 F_137 ( T_12 * V_281 )
{
long V_230 ;
struct V_188 * V_247 = & V_188 ;
* V_281 = F_133 () ;
V_230 = ( * V_281 - V_247 -> clock . V_193 ) & V_247 -> clock . V_27 ;
return V_230 * V_247 -> clock . V_194 ;
}
static int F_138 ( struct V_208 * V_211 , T_12 * V_281 )
{
unsigned long V_190 ;
T_2 V_257 ;
int V_282 ;
struct V_188 * V_247 = & V_188 ;
V_211 -> V_202 = 0 ;
do {
V_190 = F_139 ( & V_247 -> V_190 ) ;
V_282 = V_247 -> clock . V_191 ;
V_211 -> V_199 = V_247 -> V_196 ;
V_257 = V_247 -> V_200 ;
V_257 += F_137 ( V_281 ) ;
V_257 >>= V_247 -> clock . V_195 ;
} while ( F_140 ( F_141 ( & V_247 -> V_190 , V_190 ) ) );
F_142 ( V_211 , V_257 ) ;
return V_282 ;
}
static bool F_143 ( T_11 * V_239 , T_12 * V_281 )
{
struct V_208 V_211 ;
if ( V_188 . clock . V_191 != V_250 )
return false ;
if ( F_138 ( & V_211 , V_281 ) != V_250 )
return false ;
F_114 ( & V_211 ) ;
* V_239 = F_115 ( & V_211 ) ;
return true ;
}
static void F_144 ( struct V_82 * V_82 )
{
#ifdef F_54
struct V_245 * V_246 = & V_82 -> V_5 ;
int V_191 ;
bool V_283 , V_243 ;
V_243 = ( V_246 -> V_248 + 1 ==
F_123 ( & V_82 -> V_249 ) ) ;
V_283 = F_143 (
& V_246 -> V_284 ,
& V_246 -> V_285 ) ;
V_246 -> V_251 = V_283 & V_243 ;
if ( V_246 -> V_251 )
F_145 ( & V_286 , 1 ) ;
V_191 = V_188 . clock . V_191 ;
F_146 ( V_246 -> V_251 , V_191 ,
V_243 ) ;
#endif
}
static void F_147 ( struct V_82 * V_82 )
{
#ifdef F_54
int V_3 ;
struct V_1 * V_2 ;
struct V_245 * V_246 = & V_82 -> V_5 ;
F_131 ( & V_246 -> V_279 ) ;
F_148 ( V_82 ) ;
F_144 ( V_82 ) ;
F_149 (i, vcpu, kvm)
F_150 ( V_287 , & V_2 -> V_288 ) ;
F_149 (i, vcpu, kvm)
F_151 ( V_289 , & V_2 -> V_288 ) ;
F_132 ( & V_246 -> V_279 ) ;
#endif
}
static int F_152 ( struct V_1 * V_230 )
{
unsigned long V_259 , V_231 ;
struct V_290 * V_2 = & V_230 -> V_5 ;
struct V_245 * V_246 = & V_230 -> V_82 -> V_5 ;
T_11 V_239 , V_291 ;
T_2 V_275 , V_292 ;
struct V_293 V_294 ;
T_13 V_295 ;
bool V_251 ;
V_239 = 0 ;
V_292 = 0 ;
F_131 ( & V_246 -> V_279 ) ;
V_251 = V_246 -> V_251 ;
if ( V_251 ) {
V_292 = V_246 -> V_285 ;
V_239 = V_246 -> V_284 ;
}
F_132 ( & V_246 -> V_279 ) ;
F_153 ( V_259 ) ;
V_231 = F_154 ( V_296 ) ;
if ( F_140 ( V_231 == 0 ) ) {
F_155 ( V_259 ) ;
F_25 ( V_287 , V_230 ) ;
return 1 ;
}
if ( ! V_251 ) {
V_292 = F_156 () ;
V_239 = F_110 () ;
}
V_275 = V_56 -> V_297 ( V_230 , V_292 ) ;
if ( V_2 -> V_298 ) {
T_2 V_240 = F_121 ( V_230 , V_239 ) ;
if ( V_240 > V_275 ) {
F_157 ( V_230 , V_240 - V_275 ) ;
V_275 = V_240 ;
}
}
F_155 ( V_259 ) ;
if ( ! V_2 -> V_299 )
return 0 ;
V_291 = 0 ;
if ( V_2 -> V_274 . V_275 ) {
V_291 = V_2 -> V_276 -
V_2 -> V_274 . V_275 ;
V_291 = F_117 ( V_291 ,
V_2 -> V_274 . V_300 ,
V_2 -> V_274 . V_301 ) ;
V_291 += V_2 -> V_302 ;
}
if ( F_140 ( V_2 -> V_303 != V_231 ) ) {
F_108 ( V_203 / 1000 , V_231 ,
& V_2 -> V_274 . V_301 ,
& V_2 -> V_274 . V_300 ) ;
V_2 -> V_303 = V_231 ;
}
if ( ! V_251 ) {
if ( V_291 > V_239 )
V_239 = V_291 ;
}
V_2 -> V_274 . V_275 = V_275 ;
V_2 -> V_274 . V_304 = V_239 + V_230 -> V_82 -> V_5 . V_210 ;
V_2 -> V_302 = V_239 ;
V_2 -> V_276 = V_275 ;
V_2 -> V_274 . V_205 += 2 ;
if ( F_140 ( F_158 ( V_230 -> V_82 , & V_2 -> V_305 ,
& V_294 , sizeof( V_294 ) ) ) )
return 0 ;
V_295 = ( V_294 . V_259 & V_306 ) ;
if ( V_2 -> V_307 ) {
V_295 |= V_306 ;
V_2 -> V_307 = false ;
}
if ( V_251 )
V_295 |= V_308 ;
V_2 -> V_274 . V_259 = V_295 ;
F_159 ( V_230 -> V_82 , & V_2 -> V_305 ,
& V_2 -> V_274 ,
sizeof( V_2 -> V_274 ) ) ;
return 0 ;
}
static void F_160 ( struct V_1 * V_230 )
{
int V_3 ;
struct V_82 * V_82 = V_230 -> V_82 ;
struct V_1 * V_2 ;
F_149 (i, vcpu, kvm) {
F_150 ( V_287 , & V_2 -> V_288 ) ;
F_161 ( V_2 ) ;
}
}
static bool F_162 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_309 - 1 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_163 ( unsigned V_323 )
{
return V_323 < 8 && ( 1 << V_323 ) & 0xf3 ;
}
static bool F_164 ( unsigned V_323 )
{
return V_323 < 8 && ( 1 << V_323 ) & 0x73 ;
}
static bool F_165 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
int V_3 ;
if ( ! F_162 ( V_21 ) )
return false ;
if ( V_21 == V_322 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_163 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_321 ) {
if ( V_31 & ~ 0xcff )
return false ;
return F_164 ( V_31 & 0xff ) ;
} else if ( V_21 >= V_310 && V_21 <= V_320 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_164 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_164 ( V_31 & 0xff ) ;
}
static int F_166 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 * V_324 = ( T_2 * ) & V_2 -> V_5 . V_325 . V_326 ;
if ( ! F_165 ( V_2 , V_21 , V_31 ) )
return 1 ;
if ( V_21 == V_321 ) {
V_2 -> V_5 . V_325 . V_327 = V_31 ;
V_2 -> V_5 . V_325 . V_328 = ( V_31 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_310 )
V_324 [ 0 ] = V_31 ;
else if ( V_21 == V_311 || V_21 == V_312 )
V_324 [ 1 + V_21 - V_311 ] = V_31 ;
else if ( V_21 >= V_313 && V_21 <= V_320 )
V_324 [ 3 + V_21 - V_313 ] = V_31 ;
else if ( V_21 == V_322 )
V_2 -> V_5 . V_329 = V_31 ;
else {
int V_330 , V_331 ;
T_2 * V_332 ;
V_330 = ( V_21 - 0x200 ) / 2 ;
V_331 = V_21 - 0x200 - 2 * V_330 ;
if ( ! V_331 )
V_332 =
( T_2 * ) & V_2 -> V_5 . V_325 . V_333 [ V_330 ] . V_334 ;
else
V_332 =
( T_2 * ) & V_2 -> V_5 . V_325 . V_333 [ V_330 ] . V_335 ;
* V_332 = V_31 ;
}
F_58 ( V_2 ) ;
return 0 ;
}
static int F_167 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 V_336 = V_2 -> V_5 . V_336 ;
unsigned V_337 = V_336 & 0xff ;
switch ( V_21 ) {
case V_338 :
V_2 -> V_5 . V_339 = V_31 ;
break;
case V_340 :
if ( ! ( V_336 & V_341 ) )
return 1 ;
if ( V_31 != 0 && V_31 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_342 = V_31 ;
break;
default:
if ( V_21 >= V_343 &&
V_21 < V_343 + 4 * V_337 ) {
T_1 V_74 = V_21 - V_343 ;
if ( ( V_74 & 0x3 ) == 0 &&
V_31 != 0 && ( V_31 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_344 [ V_74 ] = V_31 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_168 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
int V_345 = F_48 ( V_2 ) ;
T_13 * V_346 = V_345 ? ( T_13 * ) ( long ) V_82 -> V_5 . F_168 . V_347
: ( T_13 * ) ( long ) V_82 -> V_5 . F_168 . V_348 ;
T_13 V_349 = V_345 ? V_82 -> V_5 . F_168 . V_350
: V_82 -> V_5 . F_168 . V_351 ;
T_1 V_352 = V_31 & ~ V_353 ;
T_2 V_354 = V_31 & V_353 ;
T_13 * V_355 ;
int V_100 ;
V_100 = - V_356 ;
if ( V_352 >= V_349 )
goto V_94;
V_100 = - V_357 ;
V_355 = F_169 ( V_346 + ( V_352 * V_88 ) , V_88 ) ;
if ( F_170 ( V_355 ) ) {
V_100 = F_171 ( V_355 ) ;
goto V_94;
}
if ( F_103 ( V_82 , V_354 , V_355 , V_88 ) )
goto V_358;
V_100 = 0 ;
V_358:
F_172 ( V_355 ) ;
V_94:
return V_100 ;
}
static bool F_173 ( struct V_82 * V_82 )
{
return V_82 -> V_5 . V_359 & V_360 ;
}
static bool F_174 ( T_1 V_21 )
{
bool V_100 = false ;
switch ( V_21 ) {
case V_361 :
case V_362 :
V_100 = true ;
break;
}
return V_100 ;
}
static int F_175 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
switch ( V_21 ) {
case V_361 :
V_82 -> V_5 . V_363 = V_31 ;
if ( ! V_82 -> V_5 . V_363 )
V_82 -> V_5 . V_359 &= ~ V_360 ;
break;
case V_362 : {
T_2 V_83 ;
unsigned long V_364 ;
T_13 V_365 [ 4 ] ;
if ( ! V_82 -> V_5 . V_363 )
break;
if ( ! ( V_31 & V_360 ) ) {
V_82 -> V_5 . V_359 = V_31 ;
break;
}
V_83 = V_31 >> V_366 ;
V_364 = F_176 ( V_82 , V_83 ) ;
if ( F_177 ( V_364 ) )
return 1 ;
V_56 -> V_367 ( V_2 , V_365 ) ;
( ( unsigned char * ) V_365 ) [ 3 ] = 0xc3 ;
if ( F_178 ( ( void V_368 * ) V_364 , V_365 , 4 ) )
return 1 ;
V_82 -> V_5 . V_359 = V_31 ;
break;
}
default:
F_179 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_180 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_369 : {
unsigned long V_364 ;
if ( ! ( V_31 & V_370 ) ) {
V_2 -> V_5 . V_371 = V_31 ;
break;
}
V_364 = F_176 ( V_2 -> V_82 , V_31 >>
V_372 ) ;
if ( F_177 ( V_364 ) )
return 1 ;
if ( F_181 ( ( void V_368 * ) V_364 , V_88 ) )
return 1 ;
V_2 -> V_5 . V_371 = V_31 ;
break;
}
case V_373 :
return F_182 ( V_2 , V_374 , V_31 ) ;
case V_375 :
return F_182 ( V_2 , V_376 , V_31 ) ;
case V_377 :
return F_182 ( V_2 , V_378 , V_31 ) ;
default:
F_179 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_183 ( struct V_1 * V_2 , T_2 V_31 )
{
T_5 V_379 = V_31 & ~ 0x3f ;
if ( V_31 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_380 = V_31 ;
if ( ! ( V_31 & V_381 ) ) {
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_184 ( V_2 -> V_82 , & V_2 -> V_5 . V_6 . V_31 , V_379 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_382 = ! ( V_31 & V_383 ) ;
F_185 ( V_2 ) ;
return 0 ;
}
static void F_186 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_299 = false ;
}
static void F_187 ( struct V_1 * V_2 )
{
T_2 V_270 ;
if ( ! ( V_2 -> V_5 . V_384 . V_380 & V_385 ) )
return;
V_270 = V_386 -> V_387 . V_388 - V_2 -> V_5 . V_384 . V_389 ;
V_2 -> V_5 . V_384 . V_389 = V_386 -> V_387 . V_388 ;
V_2 -> V_5 . V_384 . V_390 = V_270 ;
}
static void F_188 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_384 . V_380 & V_385 ) )
return;
if ( F_140 ( F_158 ( V_2 -> V_82 , & V_2 -> V_5 . V_384 . V_391 ,
& V_2 -> V_5 . V_384 . V_392 , sizeof( struct V_393 ) ) ) )
return;
V_2 -> V_5 . V_384 . V_392 . V_392 += V_2 -> V_5 . V_384 . V_390 ;
V_2 -> V_5 . V_384 . V_392 . V_205 += 2 ;
V_2 -> V_5 . V_384 . V_390 = 0 ;
F_159 ( V_2 -> V_82 , & V_2 -> V_5 . V_384 . V_391 ,
& V_2 -> V_5 . V_384 . V_392 , sizeof( struct V_393 ) ) ;
}
int F_189 ( struct V_1 * V_2 , struct V_183 * V_394 )
{
bool V_395 = false ;
T_1 V_21 = V_394 -> V_124 ;
T_2 V_31 = V_394 -> V_31 ;
switch ( V_21 ) {
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
break;
case V_402 :
return F_94 ( V_2 , V_31 ) ;
case V_403 :
V_31 &= ~ ( T_2 ) 0x40 ;
V_31 &= ~ ( T_2 ) 0x100 ;
V_31 &= ~ ( T_2 ) 0x8 ;
if ( V_31 != 0 ) {
F_179 ( V_2 , L_9 ,
V_31 ) ;
return 1 ;
}
break;
case V_404 :
if ( V_31 != 0 ) {
F_179 ( V_2 , L_10
L_11 , V_31 ) ;
return 1 ;
}
break;
case V_405 :
if ( ! V_31 ) {
break;
} else if ( V_31 & ~ ( V_406 | V_407 ) ) {
return 1 ;
}
F_179 ( V_2 , L_12 ,
V_225 , V_31 ) ;
break;
case 0x200 ... 0x2ff :
return F_166 ( V_2 , V_21 , V_31 ) ;
case V_408 :
F_19 ( V_2 , V_31 ) ;
break;
case V_409 ... V_409 + 0x3ff :
return F_190 ( V_2 , V_21 , V_31 ) ;
case V_410 :
F_191 ( V_2 , V_31 ) ;
break;
case V_411 :
if ( F_129 ( V_2 ) ) {
if ( ! V_394 -> V_185 ) {
T_2 V_412 = V_31 - V_2 -> V_5 . V_256 ;
V_56 -> V_413 ( V_2 , V_412 , true ) ;
}
V_2 -> V_5 . V_256 = V_31 ;
}
break;
case V_414 :
V_2 -> V_5 . V_415 = V_31 ;
break;
case V_416 :
case V_417 :
V_2 -> V_82 -> V_5 . V_204 = V_31 ;
F_101 ( V_2 -> V_82 , V_31 ) ;
break;
case V_418 :
case V_419 : {
T_2 V_420 ;
F_186 ( V_2 ) ;
V_2 -> V_5 . time = V_31 ;
F_25 ( V_421 , V_2 ) ;
if ( ! ( V_31 & 1 ) )
break;
V_420 = V_31 & ~ ( V_353 | 1 ) ;
if ( F_184 ( V_2 -> V_82 ,
& V_2 -> V_5 . V_305 , V_31 & ~ 1ULL ,
sizeof( struct V_293 ) ) )
V_2 -> V_5 . V_299 = false ;
else
V_2 -> V_5 . V_299 = true ;
break;
}
case V_422 :
if ( F_183 ( V_2 , V_31 ) )
return 1 ;
break;
case V_423 :
if ( F_140 ( ! F_192 () ) )
return 1 ;
if ( V_31 & V_424 )
return 1 ;
if ( F_184 ( V_2 -> V_82 , & V_2 -> V_5 . V_384 . V_391 ,
V_31 & V_425 ,
sizeof( struct V_393 ) ) )
return 1 ;
V_2 -> V_5 . V_384 . V_380 = V_31 ;
if ( ! ( V_31 & V_385 ) )
break;
V_2 -> V_5 . V_384 . V_389 = V_386 -> V_387 . V_388 ;
F_193 () ;
F_187 ( V_2 ) ;
F_194 () ;
F_25 ( V_426 , V_2 ) ;
break;
case V_427 :
if ( F_195 ( V_2 , V_31 ) )
return 1 ;
break;
case V_340 :
case V_338 :
case V_343 ... V_343 + 4 * V_428 - 1 :
return F_167 ( V_2 , V_21 , V_31 ) ;
case V_429 :
case V_430 :
case V_431 :
case V_432 :
if ( V_31 != 0 )
F_179 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_433 :
case V_434 :
case V_435 :
case V_436 :
F_179 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_437 :
case V_438 :
V_395 = true ;
case V_439 :
case V_440 :
if ( F_196 ( V_2 , V_21 ) )
return F_197 ( V_2 , V_394 ) ;
if ( V_395 || V_31 != 0 )
F_179 ( V_2 , L_15
L_14 , V_21 , V_31 ) ;
break;
case V_441 :
break;
case V_361 ... V_442 :
if ( F_174 ( V_21 ) ) {
int V_100 ;
F_198 ( & V_2 -> V_82 -> V_443 ) ;
V_100 = F_175 ( V_2 , V_21 , V_31 ) ;
F_199 ( & V_2 -> V_82 -> V_443 ) ;
return V_100 ;
} else
return F_180 ( V_2 , V_21 , V_31 ) ;
break;
case V_444 :
F_179 ( V_2 , L_16 , V_21 , V_31 ) ;
break;
case V_445 :
if ( ! F_200 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_446 . V_447 = V_31 ;
break;
case V_448 :
if ( ! F_200 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_446 . V_449 = V_31 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_82 -> V_5 . F_168 . V_21 ) )
return F_168 ( V_2 , V_31 ) ;
if ( F_196 ( V_2 , V_21 ) )
return F_197 ( V_2 , V_394 ) ;
if ( ! V_450 ) {
F_179 ( V_2 , L_17 ,
V_21 , V_31 ) ;
return 1 ;
} else {
F_179 ( V_2 , L_16 ,
V_21 , V_31 ) ;
break;
}
}
return 0 ;
}
int F_201 ( struct V_1 * V_2 , T_1 V_451 , T_2 * V_452 )
{
return V_56 -> V_453 ( V_2 , V_451 , V_452 ) ;
}
static int F_202 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_452 )
{
T_2 * V_324 = ( T_2 * ) & V_2 -> V_5 . V_325 . V_326 ;
if ( ! F_162 ( V_21 ) )
return 1 ;
if ( V_21 == V_321 )
* V_452 = V_2 -> V_5 . V_325 . V_327 +
( V_2 -> V_5 . V_325 . V_328 << 10 ) ;
else if ( V_21 == V_310 )
* V_452 = V_324 [ 0 ] ;
else if ( V_21 == V_311 || V_21 == V_312 )
* V_452 = V_324 [ 1 + V_21 - V_311 ] ;
else if ( V_21 >= V_313 && V_21 <= V_320 )
* V_452 = V_324 [ 3 + V_21 - V_313 ] ;
else if ( V_21 == V_322 )
* V_452 = V_2 -> V_5 . V_329 ;
else {
int V_330 , V_331 ;
T_2 * V_332 ;
V_330 = ( V_21 - 0x200 ) / 2 ;
V_331 = V_21 - 0x200 - 2 * V_330 ;
if ( ! V_331 )
V_332 =
( T_2 * ) & V_2 -> V_5 . V_325 . V_333 [ V_330 ] . V_334 ;
else
V_332 =
( T_2 * ) & V_2 -> V_5 . V_325 . V_333 [ V_330 ] . V_335 ;
* V_452 = * V_332 ;
}
return 0 ;
}
static int F_203 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_452 )
{
T_2 V_31 ;
T_2 V_336 = V_2 -> V_5 . V_336 ;
unsigned V_337 = V_336 & 0xff ;
switch ( V_21 ) {
case V_454 :
case V_455 :
V_31 = 0 ;
break;
case V_456 :
V_31 = V_2 -> V_5 . V_336 ;
break;
case V_340 :
if ( ! ( V_336 & V_341 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_342 ;
break;
case V_338 :
V_31 = V_2 -> V_5 . V_339 ;
break;
default:
if ( V_21 >= V_343 &&
V_21 < V_343 + 4 * V_337 ) {
T_1 V_74 = V_21 - V_343 ;
V_31 = V_2 -> V_5 . V_344 [ V_74 ] ;
break;
}
return 1 ;
}
* V_452 = V_31 ;
return 0 ;
}
static int F_204 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_452 )
{
T_2 V_31 = 0 ;
struct V_82 * V_82 = V_2 -> V_82 ;
switch ( V_21 ) {
case V_361 :
V_31 = V_82 -> V_5 . V_363 ;
break;
case V_362 :
V_31 = V_82 -> V_5 . V_359 ;
break;
default:
F_179 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_452 = V_31 ;
return 0 ;
}
static int F_205 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_452 )
{
T_2 V_31 = 0 ;
switch ( V_21 ) {
case V_457 : {
int V_100 ;
struct V_1 * V_230 ;
F_149 (r, v, vcpu->kvm)
if ( V_230 == V_2 )
V_31 = V_100 ;
break;
}
case V_373 :
return F_206 ( V_2 , V_374 , V_452 ) ;
case V_375 :
return F_206 ( V_2 , V_376 , V_452 ) ;
case V_377 :
return F_206 ( V_2 , V_378 , V_452 ) ;
case V_369 :
V_31 = V_2 -> V_5 . V_371 ;
break;
default:
F_179 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_452 = V_31 ;
return 0 ;
}
int F_207 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_452 )
{
T_2 V_31 ;
switch ( V_21 ) {
case V_458 :
case V_459 :
case V_405 :
case V_460 :
case V_461 :
case V_462 :
case V_463 :
case V_464 :
case V_403 :
case V_399 :
case V_429 :
case V_433 :
case V_465 :
case V_396 :
case V_404 :
case V_401 :
V_31 = 0 ;
break;
case V_437 :
case V_438 :
case V_439 :
case V_440 :
if ( F_196 ( V_2 , V_21 ) )
return F_208 ( V_2 , V_21 , V_452 ) ;
V_31 = 0 ;
break;
case V_397 :
V_31 = 0x100000000ULL ;
break;
case V_466 :
V_31 = 0x500 | V_309 ;
break;
case 0x200 ... 0x2ff :
return F_202 ( V_2 , V_21 , V_452 ) ;
case 0xcd :
V_31 = 3 ;
break;
case V_467 :
V_31 = 1 << 24 ;
break;
case V_408 :
V_31 = F_18 ( V_2 ) ;
break;
case V_409 ... V_409 + 0x3ff :
return F_209 ( V_2 , V_21 , V_452 ) ;
break;
case V_410 :
V_31 = F_210 ( V_2 ) ;
break;
case V_411 :
V_31 = ( T_2 ) V_2 -> V_5 . V_256 ;
break;
case V_414 :
V_31 = V_2 -> V_5 . V_415 ;
break;
case V_468 :
V_31 = 1000ULL ;
V_31 |= ( ( ( T_8 ) 4ULL ) << 40 ) ;
break;
case V_402 :
V_31 = V_2 -> V_5 . V_111 ;
break;
case V_417 :
case V_416 :
V_31 = V_2 -> V_82 -> V_5 . V_204 ;
break;
case V_419 :
case V_418 :
V_31 = V_2 -> V_5 . time ;
break;
case V_422 :
V_31 = V_2 -> V_5 . V_6 . V_380 ;
break;
case V_423 :
V_31 = V_2 -> V_5 . V_384 . V_380 ;
break;
case V_427 :
V_31 = V_2 -> V_5 . V_469 . V_380 ;
break;
case V_454 :
case V_455 :
case V_456 :
case V_340 :
case V_338 :
case V_343 ... V_343 + 4 * V_428 - 1 :
return F_203 ( V_2 , V_21 , V_452 ) ;
case V_441 :
V_31 = 0x20000000 ;
break;
case V_361 ... V_442 :
if ( F_174 ( V_21 ) ) {
int V_100 ;
F_198 ( & V_2 -> V_82 -> V_443 ) ;
V_100 = F_204 ( V_2 , V_21 , V_452 ) ;
F_199 ( & V_2 -> V_82 -> V_443 ) ;
return V_100 ;
} else
return F_205 ( V_2 , V_21 , V_452 ) ;
break;
case V_444 :
V_31 = 0xbe702111 ;
break;
case V_445 :
if ( ! F_200 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_446 . V_447 ;
break;
case V_448 :
if ( ! F_200 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_446 . V_449 ;
break;
default:
if ( F_196 ( V_2 , V_21 ) )
return F_208 ( V_2 , V_21 , V_452 ) ;
if ( ! V_450 ) {
F_179 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_179 ( V_2 , L_20 , V_21 ) ;
V_31 = 0 ;
}
break;
}
* V_452 = V_31 ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 , struct V_470 * V_19 ,
struct V_471 * V_472 ,
int (* F_212)( struct V_1 * V_2 ,
unsigned V_124 , T_2 * V_31 ) )
{
int V_3 , V_330 ;
V_330 = F_213 ( & V_2 -> V_82 -> V_473 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_474 ; ++ V_3 )
if ( F_212 ( V_2 , V_472 [ V_3 ] . V_124 , & V_472 [ V_3 ] . V_31 ) )
break;
F_214 ( & V_2 -> V_82 -> V_473 , V_330 ) ;
return V_3 ;
}
static int F_215 ( struct V_1 * V_2 , struct V_470 V_368 * V_475 ,
int (* F_212)( struct V_1 * V_2 ,
unsigned V_124 , T_2 * V_31 ) ,
int V_476 )
{
struct V_470 V_19 ;
struct V_471 * V_472 ;
int V_100 , V_477 ;
unsigned V_478 ;
V_100 = - V_81 ;
if ( F_216 ( & V_19 , V_475 , sizeof V_19 ) )
goto V_94;
V_100 = - V_356 ;
if ( V_19 . V_474 >= V_479 )
goto V_94;
V_478 = sizeof( struct V_471 ) * V_19 . V_474 ;
V_472 = F_169 ( V_475 -> V_472 , V_478 ) ;
if ( F_170 ( V_472 ) ) {
V_100 = F_171 ( V_472 ) ;
goto V_94;
}
V_100 = V_477 = F_211 ( V_2 , & V_19 , V_472 , F_212 ) ;
if ( V_100 < 0 )
goto V_358;
V_100 = - V_81 ;
if ( V_476 && F_217 ( V_475 -> V_472 , V_472 , V_478 ) )
goto V_358;
V_100 = V_477 ;
V_358:
F_172 ( V_472 ) ;
V_94:
return V_100 ;
}
int F_218 ( long V_480 )
{
int V_100 ;
switch ( V_480 ) {
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
case V_511 :
case V_512 :
case V_513 :
#ifdef F_219
case V_514 :
case V_515 :
#endif
V_100 = 1 ;
break;
case V_516 :
V_100 = V_517 ;
break;
case V_518 :
V_100 = ! V_56 -> V_519 () ;
break;
case V_520 :
V_100 = V_521 ;
break;
case V_522 :
V_100 = V_523 ;
break;
case V_524 :
V_100 = V_525 ;
break;
case V_526 :
V_100 = 0 ;
break;
#ifdef F_219
case V_527 :
V_100 = F_220 ( & V_528 ) ;
break;
#endif
case V_529 :
V_100 = V_428 ;
break;
case V_530 :
V_100 = V_531 ;
break;
case V_532 :
V_100 = V_533 ;
break;
case V_534 :
V_100 = F_221 ( V_535 ) ;
break;
default:
V_100 = 0 ;
break;
}
return V_100 ;
}
long F_222 ( struct V_536 * V_537 ,
unsigned int V_538 , unsigned long V_539 )
{
void V_368 * V_540 = ( void V_368 * ) V_539 ;
long V_100 ;
switch ( V_538 ) {
case V_541 : {
struct V_542 V_368 * V_543 = V_540 ;
struct V_542 V_544 ;
unsigned V_477 ;
V_100 = - V_81 ;
if ( F_216 ( & V_544 , V_543 , sizeof V_544 ) )
goto V_94;
V_477 = V_544 . V_474 ;
V_544 . V_474 = V_545 + F_44 ( V_546 ) ;
if ( F_217 ( V_543 , & V_544 , sizeof V_544 ) )
goto V_94;
V_100 = - V_356 ;
if ( V_477 < V_544 . V_474 )
goto V_94;
V_100 = - V_81 ;
if ( F_217 ( V_543 -> V_547 , & V_548 ,
V_545 * sizeof( T_1 ) ) )
goto V_94;
if ( F_217 ( V_543 -> V_547 + V_545 ,
& V_546 ,
F_44 ( V_546 ) * sizeof( T_1 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_549 :
case V_550 : {
struct V_551 V_368 * V_552 = V_540 ;
struct V_551 V_553 ;
V_100 = - V_81 ;
if ( F_216 ( & V_553 , V_552 , sizeof V_553 ) )
goto V_94;
V_100 = F_223 ( & V_553 , V_552 -> V_472 ,
V_538 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_217 ( V_552 , & V_553 , sizeof V_553 ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_554 : {
T_2 V_555 ;
V_555 = V_556 ;
V_100 = - V_81 ;
if ( F_217 ( V_540 , & V_555 , sizeof V_555 ) )
goto V_94;
V_100 = 0 ;
break;
}
default:
V_100 = - V_557 ;
}
V_94:
return V_100 ;
}
static void F_224 ( void * V_558 )
{
F_225 () ;
}
static bool F_226 ( struct V_1 * V_2 )
{
return F_227 ( V_2 -> V_82 ) ;
}
void F_228 ( struct V_1 * V_2 , int V_23 )
{
if ( F_226 ( V_2 ) ) {
if ( V_56 -> V_559 () )
F_229 ( V_23 , V_2 -> V_5 . V_560 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_230 ( V_2 -> V_23 ,
F_224 , NULL , 1 ) ;
}
V_56 -> V_561 ( V_2 , V_23 ) ;
if ( F_140 ( V_2 -> V_5 . V_562 ) ) {
F_231 ( V_2 , V_2 -> V_5 . V_562 ) ;
V_2 -> V_5 . V_562 = 0 ;
F_150 ( V_287 , & V_2 -> V_288 ) ;
}
if ( F_140 ( V_2 -> V_23 != V_23 ) || F_128 () ) {
T_11 V_563 = ! V_2 -> V_5 . V_564 ? 0 :
F_156 () - V_2 -> V_5 . V_564 ;
if ( V_563 < 0 )
F_232 ( L_21 ) ;
if ( F_128 () ) {
T_2 V_74 = V_56 -> V_263 ( V_2 ,
V_2 -> V_5 . V_276 ) ;
V_56 -> V_278 ( V_2 , V_74 ) ;
V_2 -> V_5 . V_298 = 1 ;
}
if ( ! V_2 -> V_82 -> V_5 . V_251 || V_2 -> V_23 == - 1 )
F_25 ( V_421 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_233 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_187 ( V_2 ) ;
F_25 ( V_426 , V_2 ) ;
}
void F_234 ( struct V_1 * V_2 )
{
V_56 -> V_565 ( V_2 ) ;
F_235 ( V_2 ) ;
V_2 -> V_5 . V_564 = F_156 () ;
}
static int F_236 ( struct V_1 * V_2 ,
struct V_566 * V_567 )
{
V_56 -> V_568 ( V_2 ) ;
memcpy ( V_567 -> V_569 , V_2 -> V_5 . V_570 -> V_569 , sizeof *V_567 ) ;
return 0 ;
}
static int F_237 ( struct V_1 * V_2 ,
struct V_566 * V_567 )
{
F_238 ( V_2 , V_567 ) ;
F_239 ( V_2 ) ;
return 0 ;
}
static int F_240 ( struct V_1 * V_2 ,
struct V_571 * V_572 )
{
if ( V_572 -> V_572 >= V_573 )
return - V_557 ;
if ( F_78 ( V_2 -> V_82 ) )
return - V_574 ;
F_241 ( V_2 , V_572 -> V_572 , false ) ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_242 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
return 0 ;
}
static int F_243 ( struct V_1 * V_2 ,
struct V_575 * V_576 )
{
if ( V_576 -> V_259 )
return - V_557 ;
V_2 -> V_5 . V_577 = ! ! V_576 -> V_328 ;
return 0 ;
}
static int F_244 ( struct V_1 * V_2 ,
T_2 V_336 )
{
int V_100 ;
unsigned V_337 = V_336 & 0xff , V_578 ;
V_100 = - V_557 ;
if ( ! V_337 || V_337 >= V_428 )
goto V_94;
if ( V_336 & ~ ( V_556 | 0xff | 0xff0000 ) )
goto V_94;
V_100 = 0 ;
V_2 -> V_5 . V_336 = V_336 ;
if ( V_336 & V_341 )
V_2 -> V_5 . V_342 = ~ ( T_2 ) 0 ;
for ( V_578 = 0 ; V_578 < V_337 ; V_578 ++ )
V_2 -> V_5 . V_344 [ V_578 * 4 ] = ~ ( T_2 ) 0 ;
V_94:
return V_100 ;
}
static int F_245 ( struct V_1 * V_2 ,
struct V_579 * V_580 )
{
T_2 V_336 = V_2 -> V_5 . V_336 ;
unsigned V_337 = V_336 & 0xff ;
T_2 * V_581 = V_2 -> V_5 . V_344 ;
if ( V_580 -> V_578 >= V_337 || ! ( V_580 -> V_449 & V_582 ) )
return - V_557 ;
if ( ( V_580 -> V_449 & V_583 ) && ( V_336 & V_341 ) &&
V_2 -> V_5 . V_342 != ~ ( T_2 ) 0 )
return 0 ;
V_581 += 4 * V_580 -> V_578 ;
if ( ( V_580 -> V_449 & V_583 ) && V_581 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_580 -> V_449 & V_583 ) {
if ( ( V_2 -> V_5 . V_339 & V_584 ) ||
! F_56 ( V_2 , V_585 ) ) {
F_25 ( V_54 , V_2 ) ;
return 0 ;
}
if ( V_581 [ 1 ] & V_582 )
V_580 -> V_449 |= V_586 ;
V_581 [ 2 ] = V_580 -> V_364 ;
V_581 [ 3 ] = V_580 -> V_587 ;
V_2 -> V_5 . V_339 = V_580 -> V_339 ;
V_581 [ 1 ] = V_580 -> V_449 ;
F_26 ( V_2 , V_588 ) ;
} else if ( ! ( V_581 [ 1 ] & V_582 )
|| ! ( V_581 [ 1 ] & V_583 ) ) {
if ( V_581 [ 1 ] & V_582 )
V_580 -> V_449 |= V_586 ;
V_581 [ 2 ] = V_580 -> V_364 ;
V_581 [ 3 ] = V_580 -> V_587 ;
V_581 [ 1 ] = V_580 -> V_449 ;
} else
V_581 [ 1 ] |= V_586 ;
return 0 ;
}
static void F_246 ( struct V_1 * V_2 ,
struct V_589 * V_590 )
{
F_247 ( V_2 ) ;
V_590 -> V_49 . V_591 =
V_2 -> V_5 . V_49 . V_50 &&
! F_248 ( V_2 -> V_5 . V_49 . V_16 ) ;
V_590 -> V_49 . V_16 = V_2 -> V_5 . V_49 . V_16 ;
V_590 -> V_49 . V_52 = V_2 -> V_5 . V_49 . V_52 ;
V_590 -> V_49 . V_592 = 0 ;
V_590 -> V_49 . V_43 = V_2 -> V_5 . V_49 . V_43 ;
V_590 -> V_593 . V_591 =
V_2 -> V_5 . V_593 . V_50 && ! V_2 -> V_5 . V_593 . V_594 ;
V_590 -> V_593 . V_16 = V_2 -> V_5 . V_593 . V_16 ;
V_590 -> V_593 . V_594 = 0 ;
V_590 -> V_593 . V_595 =
V_56 -> V_596 ( V_2 ,
V_597 | V_598 ) ;
V_590 -> V_599 . V_591 = V_2 -> V_5 . V_600 ;
V_590 -> V_599 . V_50 = V_2 -> V_5 . V_601 != 0 ;
V_590 -> V_599 . V_602 = V_56 -> V_603 ( V_2 ) ;
V_590 -> V_599 . V_592 = 0 ;
V_590 -> V_604 = 0 ;
V_590 -> V_259 = ( V_605
| V_606 ) ;
memset ( & V_590 -> V_607 , 0 , sizeof( V_590 -> V_607 ) ) ;
}
static int F_249 ( struct V_1 * V_2 ,
struct V_589 * V_590 )
{
if ( V_590 -> V_259 & ~ ( V_605
| V_608
| V_606 ) )
return - V_557 ;
F_247 ( V_2 ) ;
V_2 -> V_5 . V_49 . V_50 = V_590 -> V_49 . V_591 ;
V_2 -> V_5 . V_49 . V_16 = V_590 -> V_49 . V_16 ;
V_2 -> V_5 . V_49 . V_52 = V_590 -> V_49 . V_52 ;
V_2 -> V_5 . V_49 . V_43 = V_590 -> V_49 . V_43 ;
V_2 -> V_5 . V_593 . V_50 = V_590 -> V_593 . V_591 ;
V_2 -> V_5 . V_593 . V_16 = V_590 -> V_593 . V_16 ;
V_2 -> V_5 . V_593 . V_594 = V_590 -> V_593 . V_594 ;
if ( V_590 -> V_259 & V_606 )
V_56 -> V_609 ( V_2 ,
V_590 -> V_593 . V_595 ) ;
V_2 -> V_5 . V_600 = V_590 -> V_599 . V_591 ;
if ( V_590 -> V_259 & V_605 )
V_2 -> V_5 . V_601 = V_590 -> V_599 . V_50 ;
V_56 -> V_610 ( V_2 , V_590 -> V_599 . V_602 ) ;
if ( V_590 -> V_259 & V_608 &&
F_250 ( V_2 ) )
V_2 -> V_5 . V_570 -> V_604 = V_590 -> V_604 ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
static void F_251 ( struct V_1 * V_2 ,
struct V_611 * V_612 )
{
memcpy ( V_612 -> V_158 , V_2 -> V_5 . V_158 , sizeof( V_2 -> V_5 . V_158 ) ) ;
V_612 -> V_161 = V_2 -> V_5 . V_161 ;
V_612 -> V_149 = V_2 -> V_5 . V_149 ;
V_612 -> V_259 = 0 ;
memset ( & V_612 -> V_607 , 0 , sizeof( V_612 -> V_607 ) ) ;
}
static int F_252 ( struct V_1 * V_2 ,
struct V_611 * V_612 )
{
if ( V_612 -> V_259 )
return - V_557 ;
memcpy ( V_2 -> V_5 . V_158 , V_612 -> V_158 , sizeof( V_2 -> V_5 . V_158 ) ) ;
V_2 -> V_5 . V_161 = V_612 -> V_161 ;
V_2 -> V_5 . V_149 = V_612 -> V_149 ;
return 0 ;
}
static void F_253 ( struct V_1 * V_2 ,
struct V_613 * V_614 )
{
if ( V_531 ) {
memcpy ( V_614 -> V_615 ,
& V_2 -> V_5 . V_616 . V_617 -> V_618 ,
V_2 -> V_5 . V_619 ) ;
* ( T_2 * ) & V_614 -> V_615 [ V_620 / sizeof( T_1 ) ] &=
V_2 -> V_5 . V_130 | V_621 ;
} else {
memcpy ( V_614 -> V_615 ,
& V_2 -> V_5 . V_616 . V_617 -> V_622 ,
sizeof( struct V_623 ) ) ;
* ( T_2 * ) & V_614 -> V_615 [ V_620 / sizeof( T_1 ) ] =
V_621 ;
}
}
static int F_254 ( struct V_1 * V_2 ,
struct V_613 * V_614 )
{
T_2 V_624 =
* ( T_2 * ) & V_614 -> V_615 [ V_620 / sizeof( T_1 ) ] ;
if ( V_531 ) {
if ( V_624 & ~ V_625 )
return - V_557 ;
if ( V_624 & ~ V_123 )
return - V_557 ;
memcpy ( & V_2 -> V_5 . V_616 . V_617 -> V_618 ,
V_614 -> V_615 , V_2 -> V_5 . V_619 ) ;
} else {
if ( V_624 & ~ V_621 )
return - V_557 ;
memcpy ( & V_2 -> V_5 . V_616 . V_617 -> V_622 ,
V_614 -> V_615 , sizeof( struct V_623 ) ) ;
}
return 0 ;
}
static void F_255 ( struct V_1 * V_2 ,
struct V_626 * V_627 )
{
if ( ! V_531 ) {
V_627 -> V_628 = 0 ;
return;
}
V_627 -> V_628 = 1 ;
V_627 -> V_259 = 0 ;
V_627 -> V_629 [ 0 ] . V_125 = V_121 ;
V_627 -> V_629 [ 0 ] . V_22 = V_2 -> V_5 . V_122 ;
}
static int F_256 ( struct V_1 * V_2 ,
struct V_626 * V_627 )
{
int V_3 , V_100 = 0 ;
if ( ! V_531 )
return - V_557 ;
if ( V_627 -> V_628 > V_630 || V_627 -> V_259 )
return - V_557 ;
for ( V_3 = 0 ; V_3 < V_627 -> V_628 ; V_3 ++ )
if ( V_627 -> V_629 [ V_3 ] . V_125 == V_121 ) {
V_100 = F_64 ( V_2 , V_121 ,
V_627 -> V_629 [ V_3 ] . V_22 ) ;
break;
}
if ( V_100 )
V_100 = - V_557 ;
return V_100 ;
}
static int F_257 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_299 )
return - V_557 ;
V_2 -> V_5 . V_307 = true ;
F_25 ( V_287 , V_2 ) ;
return 0 ;
}
long F_258 ( struct V_536 * V_537 ,
unsigned int V_538 , unsigned long V_539 )
{
struct V_1 * V_2 = V_537 -> V_631 ;
void V_368 * V_540 = ( void V_368 * ) V_539 ;
int V_100 ;
union {
struct V_566 * V_632 ;
struct V_613 * V_618 ;
struct V_626 * V_629 ;
void * V_633 ;
} V_634 ;
V_634 . V_633 = NULL ;
switch ( V_538 ) {
case V_635 : {
V_100 = - V_557 ;
if ( ! V_2 -> V_5 . V_570 )
goto V_94;
V_634 . V_632 = F_259 ( sizeof( struct V_566 ) , V_636 ) ;
V_100 = - V_357 ;
if ( ! V_634 . V_632 )
goto V_94;
V_100 = F_236 ( V_2 , V_634 . V_632 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_217 ( V_540 , V_634 . V_632 , sizeof( struct V_566 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_637 : {
V_100 = - V_557 ;
if ( ! V_2 -> V_5 . V_570 )
goto V_94;
V_634 . V_632 = F_169 ( V_540 , sizeof( * V_634 . V_632 ) ) ;
if ( F_170 ( V_634 . V_632 ) )
return F_171 ( V_634 . V_632 ) ;
V_100 = F_237 ( V_2 , V_634 . V_632 ) ;
break;
}
case V_638 : {
struct V_571 V_572 ;
V_100 = - V_81 ;
if ( F_216 ( & V_572 , V_540 , sizeof V_572 ) )
goto V_94;
V_100 = F_240 ( V_2 , & V_572 ) ;
break;
}
case V_639 : {
V_100 = F_242 ( V_2 ) ;
break;
}
case V_640 : {
struct V_641 V_368 * V_552 = V_540 ;
struct V_641 V_553 ;
V_100 = - V_81 ;
if ( F_216 ( & V_553 , V_552 , sizeof V_553 ) )
goto V_94;
V_100 = F_260 ( V_2 , & V_553 , V_552 -> V_472 ) ;
break;
}
case V_642 : {
struct V_551 V_368 * V_552 = V_540 ;
struct V_551 V_553 ;
V_100 = - V_81 ;
if ( F_216 ( & V_553 , V_552 , sizeof V_553 ) )
goto V_94;
V_100 = F_261 ( V_2 , & V_553 ,
V_552 -> V_472 ) ;
break;
}
case V_643 : {
struct V_551 V_368 * V_552 = V_540 ;
struct V_551 V_553 ;
V_100 = - V_81 ;
if ( F_216 ( & V_553 , V_552 , sizeof V_553 ) )
goto V_94;
V_100 = F_262 ( V_2 , & V_553 ,
V_552 -> V_472 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_217 ( V_552 , & V_553 , sizeof V_553 ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_644 :
V_100 = F_215 ( V_2 , V_540 , F_201 , 1 ) ;
break;
case V_645 :
V_100 = F_215 ( V_2 , V_540 , F_97 , 0 ) ;
break;
case V_646 : {
struct V_575 V_576 ;
V_100 = - V_81 ;
if ( F_216 ( & V_576 , V_540 , sizeof V_576 ) )
goto V_94;
V_100 = F_243 ( V_2 , & V_576 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_217 ( V_540 , & V_576 , sizeof V_576 ) )
goto V_94;
V_100 = 0 ;
break;
} ;
case V_647 : {
struct V_648 V_649 ;
V_100 = - V_557 ;
if ( ! F_78 ( V_2 -> V_82 ) )
goto V_94;
V_100 = - V_81 ;
if ( F_216 ( & V_649 , V_540 , sizeof V_649 ) )
goto V_94;
V_100 = F_263 ( V_2 , V_649 . V_650 ) ;
break;
}
case V_651 : {
T_2 V_336 ;
V_100 = - V_81 ;
if ( F_216 ( & V_336 , V_540 , sizeof V_336 ) )
goto V_94;
V_100 = F_244 ( V_2 , V_336 ) ;
break;
}
case V_652 : {
struct V_579 V_580 ;
V_100 = - V_81 ;
if ( F_216 ( & V_580 , V_540 , sizeof V_580 ) )
goto V_94;
V_100 = F_245 ( V_2 , & V_580 ) ;
break;
}
case V_653 : {
struct V_589 V_590 ;
F_246 ( V_2 , & V_590 ) ;
V_100 = - V_81 ;
if ( F_217 ( V_540 , & V_590 , sizeof( struct V_589 ) ) )
break;
V_100 = 0 ;
break;
}
case V_654 : {
struct V_589 V_590 ;
V_100 = - V_81 ;
if ( F_216 ( & V_590 , V_540 , sizeof( struct V_589 ) ) )
break;
V_100 = F_249 ( V_2 , & V_590 ) ;
break;
}
case V_655 : {
struct V_611 V_612 ;
F_251 ( V_2 , & V_612 ) ;
V_100 = - V_81 ;
if ( F_217 ( V_540 , & V_612 ,
sizeof( struct V_611 ) ) )
break;
V_100 = 0 ;
break;
}
case V_656 : {
struct V_611 V_612 ;
V_100 = - V_81 ;
if ( F_216 ( & V_612 , V_540 ,
sizeof( struct V_611 ) ) )
break;
V_100 = F_252 ( V_2 , & V_612 ) ;
break;
}
case V_657 : {
V_634 . V_618 = F_259 ( sizeof( struct V_613 ) , V_636 ) ;
V_100 = - V_357 ;
if ( ! V_634 . V_618 )
break;
F_253 ( V_2 , V_634 . V_618 ) ;
V_100 = - V_81 ;
if ( F_217 ( V_540 , V_634 . V_618 , sizeof( struct V_613 ) ) )
break;
V_100 = 0 ;
break;
}
case V_658 : {
V_634 . V_618 = F_169 ( V_540 , sizeof( * V_634 . V_618 ) ) ;
if ( F_170 ( V_634 . V_618 ) )
return F_171 ( V_634 . V_618 ) ;
V_100 = F_254 ( V_2 , V_634 . V_618 ) ;
break;
}
case V_659 : {
V_634 . V_629 = F_259 ( sizeof( struct V_626 ) , V_636 ) ;
V_100 = - V_357 ;
if ( ! V_634 . V_629 )
break;
F_255 ( V_2 , V_634 . V_629 ) ;
V_100 = - V_81 ;
if ( F_217 ( V_540 , V_634 . V_629 ,
sizeof( struct V_626 ) ) )
break;
V_100 = 0 ;
break;
}
case V_660 : {
V_634 . V_629 = F_169 ( V_540 , sizeof( * V_634 . V_629 ) ) ;
if ( F_170 ( V_634 . V_629 ) )
return F_171 ( V_634 . V_629 ) ;
V_100 = F_256 ( V_2 , V_634 . V_629 ) ;
break;
}
case V_661 : {
T_1 V_662 ;
V_100 = - V_557 ;
V_662 = ( T_1 ) V_539 ;
if ( V_662 >= V_663 )
goto V_94;
if ( V_662 == 0 )
V_662 = V_236 ;
F_120 ( V_2 , V_662 ) ;
V_100 = 0 ;
goto V_94;
}
case V_664 : {
V_100 = V_2 -> V_5 . V_235 ;
goto V_94;
}
case V_665 : {
V_100 = F_257 ( V_2 ) ;
goto V_94;
}
default:
V_100 = - V_557 ;
}
V_94:
F_172 ( V_634 . V_633 ) ;
return V_100 ;
}
int F_264 ( struct V_1 * V_2 , struct V_666 * V_667 )
{
return V_668 ;
}
static int F_265 ( struct V_82 * V_82 , unsigned long V_364 )
{
int V_89 ;
if ( V_364 > ( unsigned int ) ( - 3 * V_88 ) )
return - V_557 ;
V_89 = V_56 -> V_669 ( V_82 , V_364 ) ;
return V_89 ;
}
static int F_266 ( struct V_82 * V_82 ,
T_2 V_670 )
{
V_82 -> V_5 . V_671 = V_670 ;
return 0 ;
}
static int F_267 ( struct V_82 * V_82 ,
T_1 V_672 )
{
if ( V_672 < V_673 )
return - V_557 ;
F_198 ( & V_82 -> V_674 ) ;
F_268 ( V_82 , V_672 ) ;
V_82 -> V_5 . V_675 = V_672 ;
F_199 ( & V_82 -> V_674 ) ;
return 0 ;
}
static int F_269 ( struct V_82 * V_82 )
{
return V_82 -> V_5 . V_676 ;
}
static int F_270 ( struct V_82 * V_82 , struct V_677 * V_678 )
{
int V_100 ;
V_100 = 0 ;
switch ( V_678 -> V_679 ) {
case V_680 :
memcpy ( & V_678 -> V_678 . V_681 ,
& F_271 ( V_82 ) -> V_682 [ 0 ] ,
sizeof( struct V_683 ) ) ;
break;
case V_684 :
memcpy ( & V_678 -> V_678 . V_681 ,
& F_271 ( V_82 ) -> V_682 [ 1 ] ,
sizeof( struct V_683 ) ) ;
break;
case V_685 :
V_100 = F_272 ( V_82 , & V_678 -> V_678 . V_686 ) ;
break;
default:
V_100 = - V_557 ;
break;
}
return V_100 ;
}
static int F_273 ( struct V_82 * V_82 , struct V_677 * V_678 )
{
int V_100 ;
V_100 = 0 ;
switch ( V_678 -> V_679 ) {
case V_680 :
F_131 ( & F_271 ( V_82 ) -> V_443 ) ;
memcpy ( & F_271 ( V_82 ) -> V_682 [ 0 ] ,
& V_678 -> V_678 . V_681 ,
sizeof( struct V_683 ) ) ;
F_132 ( & F_271 ( V_82 ) -> V_443 ) ;
break;
case V_684 :
F_131 ( & F_271 ( V_82 ) -> V_443 ) ;
memcpy ( & F_271 ( V_82 ) -> V_682 [ 1 ] ,
& V_678 -> V_678 . V_681 ,
sizeof( struct V_683 ) ) ;
F_132 ( & F_271 ( V_82 ) -> V_443 ) ;
break;
case V_685 :
V_100 = F_274 ( V_82 , & V_678 -> V_678 . V_686 ) ;
break;
default:
V_100 = - V_557 ;
break;
}
F_275 ( F_271 ( V_82 ) ) ;
return V_100 ;
}
static int F_276 ( struct V_82 * V_82 , struct V_687 * V_688 )
{
int V_100 = 0 ;
F_198 ( & V_82 -> V_5 . V_689 -> V_690 . V_443 ) ;
memcpy ( V_688 , & V_82 -> V_5 . V_689 -> V_690 , sizeof( struct V_687 ) ) ;
F_199 ( & V_82 -> V_5 . V_689 -> V_690 . V_443 ) ;
return V_100 ;
}
static int F_277 ( struct V_82 * V_82 , struct V_687 * V_688 )
{
int V_100 = 0 ;
F_198 ( & V_82 -> V_5 . V_689 -> V_690 . V_443 ) ;
memcpy ( & V_82 -> V_5 . V_689 -> V_690 , V_688 , sizeof( struct V_687 ) ) ;
F_278 ( V_82 , 0 , V_688 -> V_691 [ 0 ] . V_692 , 0 ) ;
F_199 ( & V_82 -> V_5 . V_689 -> V_690 . V_443 ) ;
return V_100 ;
}
static int F_279 ( struct V_82 * V_82 , struct V_693 * V_688 )
{
int V_100 = 0 ;
F_198 ( & V_82 -> V_5 . V_689 -> V_690 . V_443 ) ;
memcpy ( V_688 -> V_691 , & V_82 -> V_5 . V_689 -> V_690 . V_691 ,
sizeof( V_688 -> V_691 ) ) ;
V_688 -> V_259 = V_82 -> V_5 . V_689 -> V_690 . V_259 ;
F_199 ( & V_82 -> V_5 . V_689 -> V_690 . V_443 ) ;
memset ( & V_688 -> V_607 , 0 , sizeof( V_688 -> V_607 ) ) ;
return V_100 ;
}
static int F_280 ( struct V_82 * V_82 , struct V_693 * V_688 )
{
int V_100 = 0 , V_694 = 0 ;
T_1 V_695 , V_696 ;
F_198 ( & V_82 -> V_5 . V_689 -> V_690 . V_443 ) ;
V_695 = V_82 -> V_5 . V_689 -> V_690 . V_259 & V_697 ;
V_696 = V_688 -> V_259 & V_697 ;
if ( ! V_695 && V_696 )
V_694 = 1 ;
memcpy ( & V_82 -> V_5 . V_689 -> V_690 . V_691 , & V_688 -> V_691 ,
sizeof( V_82 -> V_5 . V_689 -> V_690 . V_691 ) ) ;
V_82 -> V_5 . V_689 -> V_690 . V_259 = V_688 -> V_259 ;
F_278 ( V_82 , 0 , V_82 -> V_5 . V_689 -> V_690 . V_691 [ 0 ] . V_692 , V_694 ) ;
F_199 ( & V_82 -> V_5 . V_689 -> V_690 . V_443 ) ;
return V_100 ;
}
static int F_281 ( struct V_82 * V_82 ,
struct V_698 * V_699 )
{
if ( ! V_82 -> V_5 . V_689 )
return - V_574 ;
F_198 ( & V_82 -> V_5 . V_689 -> V_690 . V_443 ) ;
V_82 -> V_5 . V_689 -> V_690 . V_44 = V_699 -> V_700 ;
F_199 ( & V_82 -> V_5 . V_689 -> V_690 . V_443 ) ;
return 0 ;
}
int F_282 ( struct V_82 * V_82 , struct V_701 * log )
{
int V_100 ;
struct V_702 * V_703 ;
unsigned long V_477 , V_3 ;
unsigned long * V_704 ;
unsigned long * V_705 ;
bool V_706 = false ;
F_198 ( & V_82 -> V_674 ) ;
V_100 = - V_557 ;
if ( log -> V_10 >= V_525 )
goto V_94;
V_703 = F_283 ( V_82 -> V_707 , log -> V_10 ) ;
V_704 = V_703 -> V_704 ;
V_100 = - V_708 ;
if ( ! V_704 )
goto V_94;
V_477 = F_284 ( V_703 ) ;
V_705 = V_704 + V_477 / sizeof( long ) ;
memset ( V_705 , 0 , V_477 ) ;
F_131 ( & V_82 -> V_709 ) ;
for ( V_3 = 0 ; V_3 < V_477 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_27 ;
T_4 V_74 ;
if ( ! V_704 [ V_3 ] )
continue;
V_706 = true ;
V_27 = F_285 ( & V_704 [ V_3 ] , 0 ) ;
V_705 [ V_3 ] = V_27 ;
V_74 = V_3 * V_710 ;
F_286 ( V_82 , V_703 , V_74 , V_27 ) ;
}
if ( V_706 )
F_287 ( V_82 ) ;
F_132 ( & V_82 -> V_709 ) ;
V_100 = - V_81 ;
if ( F_217 ( log -> V_704 , V_705 , V_477 ) )
goto V_94;
V_100 = 0 ;
V_94:
F_199 ( & V_82 -> V_674 ) ;
return V_100 ;
}
int F_288 ( struct V_82 * V_82 , struct V_711 * V_712 ,
bool V_713 )
{
if ( ! F_78 ( V_82 ) )
return - V_574 ;
V_712 -> V_449 = F_289 ( V_82 , V_714 ,
V_712 -> V_572 , V_712 -> V_715 ,
V_713 ) ;
return 0 ;
}
long F_290 ( struct V_536 * V_537 ,
unsigned int V_538 , unsigned long V_539 )
{
struct V_82 * V_82 = V_537 -> V_631 ;
void V_368 * V_540 = ( void V_368 * ) V_539 ;
int V_100 = - V_716 ;
union {
struct V_687 V_688 ;
struct V_693 V_717 ;
struct V_718 V_719 ;
} V_634 ;
switch ( V_538 ) {
case V_720 :
V_100 = F_265 ( V_82 , V_539 ) ;
break;
case V_721 : {
T_2 V_670 ;
V_100 = - V_81 ;
if ( F_216 ( & V_670 , V_540 , sizeof V_670 ) )
goto V_94;
V_100 = F_266 ( V_82 , V_670 ) ;
break;
}
case V_722 :
V_100 = F_267 ( V_82 , V_539 ) ;
break;
case V_723 :
V_100 = F_269 ( V_82 ) ;
break;
case V_724 : {
struct V_725 * V_726 ;
F_198 ( & V_82 -> V_443 ) ;
V_100 = - V_727 ;
if ( V_82 -> V_5 . V_726 )
goto V_728;
V_100 = - V_557 ;
if ( F_123 ( & V_82 -> V_249 ) )
goto V_728;
V_100 = - V_357 ;
V_726 = F_291 ( V_82 ) ;
if ( V_726 ) {
V_100 = F_292 ( V_82 ) ;
if ( V_100 ) {
F_198 ( & V_82 -> V_674 ) ;
F_293 ( V_82 , V_729 ,
& V_726 -> V_730 ) ;
F_293 ( V_82 , V_729 ,
& V_726 -> V_731 ) ;
F_293 ( V_82 , V_729 ,
& V_726 -> V_732 ) ;
F_199 ( & V_82 -> V_674 ) ;
F_172 ( V_726 ) ;
goto V_728;
}
} else
goto V_728;
F_13 () ;
V_82 -> V_5 . V_726 = V_726 ;
F_13 () ;
V_100 = F_294 ( V_82 ) ;
if ( V_100 ) {
F_198 ( & V_82 -> V_674 ) ;
F_198 ( & V_82 -> V_733 ) ;
F_295 ( V_82 ) ;
F_296 ( V_82 ) ;
F_199 ( & V_82 -> V_733 ) ;
F_199 ( & V_82 -> V_674 ) ;
}
V_728:
F_199 ( & V_82 -> V_443 ) ;
break;
}
case V_734 :
V_634 . V_719 . V_259 = V_735 ;
goto V_736;
case V_737 :
V_100 = - V_81 ;
if ( F_216 ( & V_634 . V_719 , V_540 ,
sizeof( struct V_718 ) ) )
goto V_94;
V_736:
F_198 ( & V_82 -> V_674 ) ;
V_100 = - V_727 ;
if ( V_82 -> V_5 . V_689 )
goto V_738;
V_100 = - V_357 ;
V_82 -> V_5 . V_689 = F_297 ( V_82 , V_634 . V_719 . V_259 ) ;
if ( V_82 -> V_5 . V_689 )
V_100 = 0 ;
V_738:
F_199 ( & V_82 -> V_674 ) ;
break;
case V_739 : {
struct V_677 * V_678 ;
V_678 = F_169 ( V_540 , sizeof( * V_678 ) ) ;
if ( F_170 ( V_678 ) ) {
V_100 = F_171 ( V_678 ) ;
goto V_94;
}
V_100 = - V_574 ;
if ( ! F_78 ( V_82 ) )
goto V_740;
V_100 = F_270 ( V_82 , V_678 ) ;
if ( V_100 )
goto V_740;
V_100 = - V_81 ;
if ( F_217 ( V_540 , V_678 , sizeof *V_678 ) )
goto V_740;
V_100 = 0 ;
V_740:
F_172 ( V_678 ) ;
break;
}
case V_741 : {
struct V_677 * V_678 ;
V_678 = F_169 ( V_540 , sizeof( * V_678 ) ) ;
if ( F_170 ( V_678 ) ) {
V_100 = F_171 ( V_678 ) ;
goto V_94;
}
V_100 = - V_574 ;
if ( ! F_78 ( V_82 ) )
goto V_742;
V_100 = F_273 ( V_82 , V_678 ) ;
if ( V_100 )
goto V_742;
V_100 = 0 ;
V_742:
F_172 ( V_678 ) ;
break;
}
case V_743 : {
V_100 = - V_81 ;
if ( F_216 ( & V_634 . V_688 , V_540 , sizeof( struct V_687 ) ) )
goto V_94;
V_100 = - V_574 ;
if ( ! V_82 -> V_5 . V_689 )
goto V_94;
V_100 = F_276 ( V_82 , & V_634 . V_688 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_217 ( V_540 , & V_634 . V_688 , sizeof( struct V_687 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_744 : {
V_100 = - V_81 ;
if ( F_216 ( & V_634 . V_688 , V_540 , sizeof V_634 . V_688 ) )
goto V_94;
V_100 = - V_574 ;
if ( ! V_82 -> V_5 . V_689 )
goto V_94;
V_100 = F_277 ( V_82 , & V_634 . V_688 ) ;
break;
}
case V_745 : {
V_100 = - V_574 ;
if ( ! V_82 -> V_5 . V_689 )
goto V_94;
V_100 = F_279 ( V_82 , & V_634 . V_717 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_217 ( V_540 , & V_634 . V_717 , sizeof( V_634 . V_717 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_746 : {
V_100 = - V_81 ;
if ( F_216 ( & V_634 . V_717 , V_540 , sizeof( V_634 . V_717 ) ) )
goto V_94;
V_100 = - V_574 ;
if ( ! V_82 -> V_5 . V_689 )
goto V_94;
V_100 = F_280 ( V_82 , & V_634 . V_717 ) ;
break;
}
case V_747 : {
struct V_698 V_699 ;
V_100 = - V_81 ;
if ( F_216 ( & V_699 , V_540 , sizeof( V_699 ) ) )
goto V_94;
V_100 = F_281 ( V_82 , & V_699 ) ;
break;
}
case V_748 : {
V_100 = - V_81 ;
if ( F_216 ( & V_82 -> V_5 . F_168 , V_540 ,
sizeof( struct V_749 ) ) )
goto V_94;
V_100 = - V_557 ;
if ( V_82 -> V_5 . F_168 . V_259 )
goto V_94;
V_100 = 0 ;
break;
}
case V_750 : {
struct V_751 V_752 ;
T_2 V_753 ;
T_11 V_270 ;
V_100 = - V_81 ;
if ( F_216 ( & V_752 , V_540 , sizeof( V_752 ) ) )
goto V_94;
V_100 = - V_557 ;
if ( V_752 . V_259 )
goto V_94;
V_100 = 0 ;
F_298 () ;
V_753 = F_110 () ;
V_270 = V_752 . clock - V_753 ;
F_299 () ;
V_82 -> V_5 . V_210 = V_270 ;
F_147 ( V_82 ) ;
break;
}
case V_754 : {
struct V_751 V_752 ;
T_2 V_753 ;
F_298 () ;
V_753 = F_110 () ;
V_752 . clock = V_82 -> V_5 . V_210 + V_753 ;
F_299 () ;
V_752 . V_259 = 0 ;
memset ( & V_752 . V_592 , 0 , sizeof( V_752 . V_592 ) ) ;
V_100 = - V_81 ;
if ( F_217 ( V_540 , & V_752 , sizeof( V_752 ) ) )
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
static void F_300 ( void )
{
T_1 V_755 [ 2 ] ;
unsigned V_3 , V_756 ;
for ( V_3 = V_756 = V_757 ; V_3 < F_44 ( V_548 ) ; V_3 ++ ) {
if ( F_301 ( V_548 [ V_3 ] , & V_755 [ 0 ] , & V_755 [ 1 ] ) < 0 )
continue;
if ( V_756 < V_3 )
V_548 [ V_756 ] = V_548 [ V_3 ] ;
V_756 ++ ;
}
V_545 = V_756 ;
}
static int F_302 ( struct V_1 * V_2 , T_5 V_364 , int V_75 ,
const void * V_230 )
{
int V_758 = 0 ;
int V_477 ;
do {
V_477 = F_303 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_570 &&
! F_304 ( & V_2 -> V_5 . V_570 -> V_759 , V_364 , V_477 , V_230 ) )
&& F_305 ( V_2 -> V_82 , V_760 , V_364 , V_477 , V_230 ) )
break;
V_758 += V_477 ;
V_364 += V_477 ;
V_75 -= V_477 ;
V_230 += V_477 ;
} while ( V_75 );
return V_758 ;
}
static int F_306 ( struct V_1 * V_2 , T_5 V_364 , int V_75 , void * V_230 )
{
int V_758 = 0 ;
int V_477 ;
do {
V_477 = F_303 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_570 &&
! F_307 ( & V_2 -> V_5 . V_570 -> V_759 , V_364 , V_477 , V_230 ) )
&& F_308 ( V_2 -> V_82 , V_760 , V_364 , V_477 , V_230 ) )
break;
F_309 ( V_761 , V_477 , V_364 , * ( T_2 * ) V_230 ) ;
V_758 += V_477 ;
V_364 += V_477 ;
V_75 -= V_477 ;
V_230 += V_477 ;
} while ( V_75 );
return V_758 ;
}
static void F_310 ( struct V_1 * V_2 ,
struct V_762 * V_763 , int V_764 )
{
V_56 -> V_765 ( V_2 , V_763 , V_764 ) ;
}
void F_311 ( struct V_1 * V_2 ,
struct V_762 * V_763 , int V_764 )
{
V_56 -> V_766 ( V_2 , V_763 , V_764 ) ;
}
T_5 F_312 ( struct V_1 * V_2 , T_5 V_379 , T_1 V_76 )
{
T_5 V_767 ;
struct V_58 V_49 ;
F_313 ( ! F_33 ( V_2 ) ) ;
V_76 |= V_92 ;
V_767 = V_2 -> V_5 . V_67 . V_768 ( V_2 , V_379 , V_76 , & V_49 ) ;
return V_767 ;
}
T_5 F_314 ( struct V_1 * V_2 , T_14 V_769 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return V_2 -> V_5 . V_84 -> V_768 ( V_2 , V_769 , V_76 , V_49 ) ;
}
T_5 F_315 ( struct V_1 * V_2 , T_14 V_769 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
V_76 |= V_770 ;
return V_2 -> V_5 . V_84 -> V_768 ( V_2 , V_769 , V_76 , V_49 ) ;
}
T_5 F_316 ( struct V_1 * V_2 , T_14 V_769 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
V_76 |= V_93 ;
return V_2 -> V_5 . V_84 -> V_768 ( V_2 , V_769 , V_76 , V_49 ) ;
}
T_5 F_317 ( struct V_1 * V_2 , T_14 V_769 ,
struct V_58 * V_49 )
{
return V_2 -> V_5 . V_84 -> V_768 ( V_2 , V_769 , 0 , V_49 ) ;
}
static int F_318 ( T_14 V_364 , void * V_157 , unsigned int V_771 ,
struct V_1 * V_2 , T_1 V_76 ,
struct V_58 * V_49 )
{
void * V_31 = V_157 ;
int V_100 = V_772 ;
while ( V_771 ) {
T_5 V_379 = V_2 -> V_5 . V_84 -> V_768 ( V_2 , V_364 , V_76 ,
V_49 ) ;
unsigned V_74 = V_364 & ( V_88 - 1 ) ;
unsigned V_773 = F_303 ( V_771 , ( unsigned ) V_88 - V_74 ) ;
int V_89 ;
if ( V_379 == V_80 )
return V_774 ;
V_89 = F_102 ( V_2 -> V_82 , V_379 , V_31 , V_773 ) ;
if ( V_89 < 0 ) {
V_100 = V_775 ;
goto V_94;
}
V_771 -= V_773 ;
V_31 += V_773 ;
V_364 += V_773 ;
}
V_94:
return V_100 ;
}
static int F_319 ( struct V_776 * V_777 ,
T_14 V_364 , void * V_157 , unsigned int V_771 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return F_318 ( V_364 , V_157 , V_771 , V_2 ,
V_76 | V_770 ,
V_49 ) ;
}
int F_321 ( struct V_776 * V_777 ,
T_14 V_364 , void * V_157 , unsigned int V_771 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return F_318 ( V_364 , V_157 , V_771 , V_2 , V_76 ,
V_49 ) ;
}
static int F_322 ( struct V_776 * V_777 ,
T_14 V_364 , void * V_157 , unsigned int V_771 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
return F_318 ( V_364 , V_157 , V_771 , V_2 , 0 , V_49 ) ;
}
int F_323 ( struct V_776 * V_777 ,
T_14 V_364 , void * V_157 ,
unsigned int V_771 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
void * V_31 = V_157 ;
int V_100 = V_772 ;
while ( V_771 ) {
T_5 V_379 = V_2 -> V_5 . V_84 -> V_768 ( V_2 , V_364 ,
V_93 ,
V_49 ) ;
unsigned V_74 = V_364 & ( V_88 - 1 ) ;
unsigned V_778 = F_303 ( V_771 , ( unsigned ) V_88 - V_74 ) ;
int V_89 ;
if ( V_379 == V_80 )
return V_774 ;
V_89 = F_103 ( V_2 -> V_82 , V_379 , V_31 , V_778 ) ;
if ( V_89 < 0 ) {
V_100 = V_775 ;
goto V_94;
}
V_771 -= V_778 ;
V_31 += V_778 ;
V_364 += V_778 ;
}
V_94:
return V_100 ;
}
static int F_324 ( struct V_1 * V_2 , unsigned long V_769 ,
T_5 * V_379 , struct V_58 * V_49 ,
bool V_779 )
{
T_1 V_76 = ( ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 )
| ( V_779 ? V_93 : 0 ) ;
if ( F_325 ( V_2 , V_769 )
&& ! F_326 ( V_2 -> V_5 . V_84 , V_2 -> V_5 . V_76 , V_76 ) ) {
* V_379 = V_2 -> V_5 . V_780 << V_87 |
( V_769 & ( V_88 - 1 ) ) ;
F_327 ( V_769 , * V_379 , V_779 , false ) ;
return 1 ;
}
* V_379 = V_2 -> V_5 . V_84 -> V_768 ( V_2 , V_769 , V_76 , V_49 ) ;
if ( * V_379 == V_80 )
return - 1 ;
if ( ( * V_379 & V_353 ) == V_781 )
return 1 ;
if ( F_328 ( V_2 , * V_379 ) ) {
F_327 ( V_769 , * V_379 , V_779 , true ) ;
return 1 ;
}
return 0 ;
}
int F_329 ( struct V_1 * V_2 , T_5 V_379 ,
const void * V_157 , int V_771 )
{
int V_89 ;
V_89 = F_103 ( V_2 -> V_82 , V_379 , V_157 , V_771 ) ;
if ( V_89 < 0 )
return 0 ;
F_330 ( V_2 , V_379 , V_157 , V_771 ) ;
return 1 ;
}
static int F_331 ( struct V_1 * V_2 , void * V_157 , int V_771 )
{
if ( V_2 -> V_782 ) {
F_309 ( V_761 , V_771 ,
V_2 -> V_783 [ 0 ] . V_379 , * ( T_2 * ) V_157 ) ;
V_2 -> V_782 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_332 ( struct V_1 * V_2 , T_5 V_379 ,
void * V_157 , int V_771 )
{
return ! F_102 ( V_2 -> V_82 , V_379 , V_157 , V_771 ) ;
}
static int F_333 ( struct V_1 * V_2 , T_5 V_379 ,
void * V_157 , int V_771 )
{
return F_329 ( V_2 , V_379 , V_157 , V_771 ) ;
}
static int F_334 ( struct V_1 * V_2 , T_5 V_379 , int V_771 , void * V_157 )
{
F_309 ( V_784 , V_771 , V_379 , * ( T_2 * ) V_157 ) ;
return F_302 ( V_2 , V_379 , V_771 , V_157 ) ;
}
static int F_335 ( struct V_1 * V_2 , T_5 V_379 ,
void * V_157 , int V_771 )
{
F_309 ( V_785 , V_771 , V_379 , 0 ) ;
return V_775 ;
}
static int F_336 ( struct V_1 * V_2 , T_5 V_379 ,
void * V_157 , int V_771 )
{
struct V_786 * V_787 = & V_2 -> V_783 [ 0 ] ;
memcpy ( V_2 -> V_788 -> V_789 . V_31 , V_787 -> V_31 , F_303 ( 8u , V_787 -> V_75 ) ) ;
return V_772 ;
}
static int F_337 ( unsigned long V_364 , void * V_157 ,
unsigned int V_771 ,
struct V_58 * V_49 ,
struct V_1 * V_2 ,
const struct V_790 * V_791 )
{
T_5 V_379 ;
int V_758 , V_89 ;
bool V_779 = V_791 -> V_779 ;
struct V_786 * V_787 ;
V_89 = F_324 ( V_2 , V_364 , & V_379 , V_49 , V_779 ) ;
if ( V_89 < 0 )
return V_774 ;
if ( V_89 )
goto V_789;
if ( V_791 -> V_792 ( V_2 , V_379 , V_157 , V_771 ) )
return V_772 ;
V_789:
V_758 = V_791 -> V_793 ( V_2 , V_379 , V_771 , V_157 ) ;
if ( V_758 == V_771 )
return V_772 ;
V_379 += V_758 ;
V_771 -= V_758 ;
V_157 += V_758 ;
F_111 ( V_2 -> V_794 >= V_795 ) ;
V_787 = & V_2 -> V_783 [ V_2 -> V_794 ++ ] ;
V_787 -> V_379 = V_379 ;
V_787 -> V_31 = V_157 ;
V_787 -> V_75 = V_771 ;
return V_772 ;
}
int F_338 ( struct V_776 * V_777 , unsigned long V_364 ,
void * V_157 , unsigned int V_771 ,
struct V_58 * V_49 ,
const struct V_790 * V_791 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
T_5 V_379 ;
int V_796 ;
if ( V_791 -> V_797 &&
V_791 -> V_797 ( V_2 , V_157 , V_771 ) )
return V_772 ;
V_2 -> V_794 = 0 ;
if ( ( ( V_364 + V_771 - 1 ) ^ V_364 ) & V_353 ) {
int V_798 ;
V_798 = - V_364 & ~ V_353 ;
V_796 = F_337 ( V_364 , V_157 , V_798 , V_49 ,
V_2 , V_791 ) ;
if ( V_796 != V_772 )
return V_796 ;
V_364 += V_798 ;
V_157 += V_798 ;
V_771 -= V_798 ;
}
V_796 = F_337 ( V_364 , V_157 , V_771 , V_49 ,
V_2 , V_791 ) ;
if ( V_796 != V_772 )
return V_796 ;
if ( ! V_2 -> V_794 )
return V_796 ;
V_379 = V_2 -> V_783 [ 0 ] . V_379 ;
V_2 -> V_799 = 1 ;
V_2 -> V_800 = 0 ;
V_2 -> V_788 -> V_789 . V_75 = F_303 ( 8u , V_2 -> V_783 [ 0 ] . V_75 ) ;
V_2 -> V_788 -> V_789 . V_801 = V_2 -> V_802 = V_791 -> V_779 ;
V_2 -> V_788 -> V_803 = V_804 ;
V_2 -> V_788 -> V_789 . V_805 = V_379 ;
return V_791 -> V_806 ( V_2 , V_379 , V_157 , V_771 ) ;
}
static int F_339 ( struct V_776 * V_777 ,
unsigned long V_364 ,
void * V_157 ,
unsigned int V_771 ,
struct V_58 * V_49 )
{
return F_338 ( V_777 , V_364 , V_157 , V_771 ,
V_49 , & V_807 ) ;
}
int F_340 ( struct V_776 * V_777 ,
unsigned long V_364 ,
const void * V_157 ,
unsigned int V_771 ,
struct V_58 * V_49 )
{
return F_338 ( V_777 , V_364 , ( void * ) V_157 , V_771 ,
V_49 , & V_808 ) ;
}
static int F_341 ( struct V_776 * V_777 ,
unsigned long V_364 ,
const void * V_809 ,
const void * V_810 ,
unsigned int V_771 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
T_5 V_379 ;
struct V_355 * V_355 ;
char * V_811 ;
bool V_812 ;
if ( V_771 > 8 || ( V_771 & ( V_771 - 1 ) ) )
goto V_813;
V_379 = F_316 ( V_2 , V_364 , NULL ) ;
if ( V_379 == V_80 ||
( V_379 & V_353 ) == V_781 )
goto V_813;
if ( ( ( V_379 + V_771 - 1 ) & V_353 ) != ( V_379 & V_353 ) )
goto V_813;
V_355 = F_342 ( V_2 -> V_82 , V_379 >> V_87 ) ;
if ( F_343 ( V_355 ) )
goto V_813;
V_811 = F_344 ( V_355 ) ;
V_811 += F_345 ( V_379 ) ;
switch ( V_771 ) {
case 1 :
V_812 = F_346 ( T_13 , V_811 , V_809 , V_810 ) ;
break;
case 2 :
V_812 = F_346 ( V_814 , V_811 , V_809 , V_810 ) ;
break;
case 4 :
V_812 = F_346 ( T_1 , V_811 , V_809 , V_810 ) ;
break;
case 8 :
V_812 = F_347 ( V_811 , V_809 , V_810 ) ;
break;
default:
F_22 () ;
}
F_348 ( V_811 ) ;
F_349 ( V_355 ) ;
if ( ! V_812 )
return V_815 ;
F_330 ( V_2 , V_379 , V_810 , V_771 ) ;
return V_772 ;
V_813:
F_350 ( V_816 L_22 ) ;
return F_340 ( V_777 , V_364 , V_810 , V_771 , V_49 ) ;
}
static int F_351 ( struct V_1 * V_2 , void * V_817 )
{
int V_100 ;
if ( V_2 -> V_5 . V_818 . V_819 )
V_100 = F_308 ( V_2 -> V_82 , V_729 , V_2 -> V_5 . V_818 . V_820 ,
V_2 -> V_5 . V_818 . V_478 , V_817 ) ;
else
V_100 = F_305 ( V_2 -> V_82 , V_729 ,
V_2 -> V_5 . V_818 . V_820 , V_2 -> V_5 . V_818 . V_478 ,
V_817 ) ;
return V_100 ;
}
static int F_352 ( struct V_1 * V_2 , int V_478 ,
unsigned short V_820 , void * V_157 ,
unsigned int V_692 , bool V_819 )
{
F_353 ( ! V_819 , V_820 , V_478 , V_692 ) ;
V_2 -> V_5 . V_818 . V_820 = V_820 ;
V_2 -> V_5 . V_818 . V_819 = V_819 ;
V_2 -> V_5 . V_818 . V_692 = V_692 ;
V_2 -> V_5 . V_818 . V_478 = V_478 ;
if ( ! F_351 ( V_2 , V_2 -> V_5 . V_821 ) ) {
V_2 -> V_5 . V_818 . V_692 = 0 ;
return 1 ;
}
V_2 -> V_788 -> V_803 = V_822 ;
V_2 -> V_788 -> V_823 . V_824 = V_819 ? V_825 : V_826 ;
V_2 -> V_788 -> V_823 . V_478 = V_478 ;
V_2 -> V_788 -> V_823 . V_827 = V_828 * V_88 ;
V_2 -> V_788 -> V_823 . V_692 = V_692 ;
V_2 -> V_788 -> V_823 . V_820 = V_820 ;
return 0 ;
}
static int F_354 ( struct V_776 * V_777 ,
int V_478 , unsigned short V_820 , void * V_157 ,
unsigned int V_692 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
int V_89 ;
if ( V_2 -> V_5 . V_818 . V_692 )
goto V_829;
V_89 = F_352 ( V_2 , V_478 , V_820 , V_157 , V_692 , true ) ;
if ( V_89 ) {
V_829:
memcpy ( V_157 , V_2 -> V_5 . V_821 , V_478 * V_692 ) ;
V_2 -> V_5 . V_818 . V_692 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_355 ( struct V_776 * V_777 ,
int V_478 , unsigned short V_820 ,
const void * V_157 , unsigned int V_692 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
memcpy ( V_2 -> V_5 . V_821 , V_157 , V_478 * V_692 ) ;
return F_352 ( V_2 , V_478 , V_820 , ( void * ) V_157 , V_692 , false ) ;
}
static unsigned long F_356 ( struct V_1 * V_2 , int V_764 )
{
return V_56 -> F_356 ( V_2 , V_764 ) ;
}
static void F_357 ( struct V_776 * V_777 , V_146 V_63 )
{
F_358 ( F_320 ( V_777 ) , V_63 ) ;
}
int F_359 ( struct V_1 * V_2 )
{
if ( ! F_226 ( V_2 ) )
return V_772 ;
if ( V_56 -> V_559 () ) {
int V_23 = F_360 () ;
F_229 ( V_23 , V_2 -> V_5 . V_560 ) ;
F_361 ( V_2 -> V_5 . V_560 ,
F_224 , NULL , 1 ) ;
F_362 () ;
F_363 ( V_2 -> V_5 . V_560 ) ;
} else
F_225 () ;
return V_772 ;
}
static void F_364 ( struct V_776 * V_777 )
{
F_359 ( F_320 ( V_777 ) ) ;
}
int F_365 ( struct V_776 * V_777 , int V_156 , unsigned long * V_830 )
{
return F_85 ( F_320 ( V_777 ) , V_156 , V_830 ) ;
}
int F_366 ( struct V_776 * V_777 , int V_156 , unsigned long V_22 )
{
return F_83 ( F_320 ( V_777 ) , V_156 , V_22 ) ;
}
static T_2 F_367 ( T_2 V_831 , T_1 V_832 )
{
return ( V_831 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_832 ;
}
static unsigned long F_368 ( struct V_776 * V_777 , int V_833 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
unsigned long V_22 ;
switch ( V_833 ) {
case 0 :
V_22 = F_53 ( V_2 ) ;
break;
case 2 :
V_22 = V_2 -> V_5 . V_62 ;
break;
case 3 :
V_22 = F_51 ( V_2 ) ;
break;
case 4 :
V_22 = F_67 ( V_2 ) ;
break;
case 8 :
V_22 = F_80 ( V_2 ) ;
break;
default:
F_369 ( L_23 , V_225 , V_833 ) ;
return 0 ;
}
return V_22 ;
}
static int F_370 ( struct V_776 * V_777 , int V_833 , V_146 V_157 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
int V_166 = 0 ;
switch ( V_833 ) {
case 0 :
V_166 = F_52 ( V_2 , F_367 ( F_53 ( V_2 ) , V_157 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_62 = V_157 ;
break;
case 3 :
V_166 = F_73 ( V_2 , V_157 ) ;
break;
case 4 :
V_166 = F_66 ( V_2 , F_367 ( F_67 ( V_2 ) , V_157 ) ) ;
break;
case 8 :
V_166 = F_77 ( V_2 , V_157 ) ;
break;
default:
F_369 ( L_23 , V_225 , V_833 ) ;
V_166 = - 1 ;
}
return V_166 ;
}
static void F_371 ( struct V_776 * V_777 , V_146 V_157 )
{
F_372 ( F_320 ( V_777 ) , V_157 ) ;
}
static int F_373 ( struct V_776 * V_777 )
{
return V_56 -> V_71 ( F_320 ( V_777 ) ) ;
}
static void F_374 ( struct V_776 * V_777 , struct V_834 * V_835 )
{
V_56 -> V_836 ( F_320 ( V_777 ) , V_835 ) ;
}
static void F_375 ( struct V_776 * V_777 , struct V_834 * V_835 )
{
V_56 -> V_837 ( F_320 ( V_777 ) , V_835 ) ;
}
static void F_376 ( struct V_776 * V_777 , struct V_834 * V_835 )
{
V_56 -> V_838 ( F_320 ( V_777 ) , V_835 ) ;
}
static void F_377 ( struct V_776 * V_777 , struct V_834 * V_835 )
{
V_56 -> V_839 ( F_320 ( V_777 ) , V_835 ) ;
}
static unsigned long F_378 (
struct V_776 * V_777 , int V_764 )
{
return F_356 ( F_320 ( V_777 ) , V_764 ) ;
}
static bool F_379 ( struct V_776 * V_777 , V_814 * V_840 ,
struct V_841 * V_842 , T_1 * V_843 ,
int V_764 )
{
struct V_762 V_763 ;
F_311 ( F_320 ( V_777 ) , & V_763 , V_764 ) ;
* V_840 = V_763 . V_840 ;
if ( V_763 . V_844 ) {
memset ( V_842 , 0 , sizeof( * V_842 ) ) ;
return false ;
}
if ( V_763 . V_845 )
V_763 . V_846 >>= 12 ;
F_380 ( V_842 , V_763 . V_846 ) ;
F_381 ( V_842 , ( unsigned long ) V_763 . V_847 ) ;
#ifdef F_54
if ( V_843 )
* V_843 = V_763 . V_847 >> 32 ;
#endif
V_842 -> type = V_763 . type ;
V_842 -> V_567 = V_763 . V_567 ;
V_842 -> V_848 = V_763 . V_848 ;
V_842 -> V_324 = V_763 . V_849 ;
V_842 -> V_850 = V_763 . V_850 ;
V_842 -> V_851 = V_763 . V_851 ;
V_842 -> V_852 = V_763 . V_158 ;
V_842 -> V_845 = V_763 . V_845 ;
return true ;
}
static void F_382 ( struct V_776 * V_777 , V_814 V_840 ,
struct V_841 * V_842 , T_1 V_843 ,
int V_764 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
struct V_762 V_763 ;
V_763 . V_840 = V_840 ;
V_763 . V_847 = F_383 ( V_842 ) ;
#ifdef F_54
V_763 . V_847 |= ( ( T_2 ) V_843 ) << 32 ;
#endif
V_763 . V_846 = F_384 ( V_842 ) ;
if ( V_842 -> V_845 )
V_763 . V_846 = ( V_763 . V_846 << 12 ) | 0xfff ;
V_763 . type = V_842 -> type ;
V_763 . V_849 = V_842 -> V_324 ;
V_763 . V_848 = V_842 -> V_848 ;
V_763 . V_158 = V_842 -> V_852 ;
V_763 . V_567 = V_842 -> V_567 ;
V_763 . V_851 = V_842 -> V_851 ;
V_763 . V_845 = V_842 -> V_845 ;
V_763 . V_850 = V_842 -> V_850 ;
V_763 . V_849 = V_842 -> V_324 ;
V_763 . V_844 = ! V_763 . V_849 ;
V_763 . V_853 = 0 ;
F_310 ( V_2 , & V_763 , V_764 ) ;
return;
}
static int F_385 ( struct V_776 * V_777 ,
T_1 V_451 , T_2 * V_452 )
{
return F_201 ( F_320 ( V_777 ) , V_451 , V_452 ) ;
}
static int F_386 ( struct V_776 * V_777 ,
T_1 V_451 , T_2 V_31 )
{
struct V_183 V_21 ;
V_21 . V_31 = V_31 ;
V_21 . V_124 = V_451 ;
V_21 . V_185 = false ;
return F_96 ( F_320 ( V_777 ) , & V_21 ) ;
}
static int F_387 ( struct V_776 * V_777 ,
T_1 V_854 , T_2 * V_452 )
{
return F_89 ( F_320 ( V_777 ) , V_854 , V_452 ) ;
}
static void F_388 ( struct V_776 * V_777 )
{
F_320 ( V_777 ) -> V_5 . V_855 = 1 ;
}
static void F_389 ( struct V_776 * V_777 )
{
F_193 () ;
F_390 ( F_320 ( V_777 ) ) ;
F_391 () ;
}
static void F_392 ( struct V_776 * V_777 )
{
F_194 () ;
}
static int F_393 ( struct V_776 * V_777 ,
struct V_856 * V_857 ,
enum V_858 V_859 )
{
return V_56 -> V_860 ( F_320 ( V_777 ) , V_857 , V_859 ) ;
}
static void F_394 ( struct V_776 * V_777 ,
T_1 * V_861 , T_1 * V_862 , T_1 * V_168 , T_1 * V_176 )
{
V_641 ( F_320 ( V_777 ) , V_861 , V_862 , V_168 , V_176 ) ;
}
static V_146 F_395 ( struct V_776 * V_777 , unsigned V_863 )
{
return F_88 ( F_320 ( V_777 ) , V_863 ) ;
}
static void F_396 ( struct V_776 * V_777 , unsigned V_863 , V_146 V_157 )
{
F_90 ( F_320 ( V_777 ) , V_863 , V_157 ) ;
}
static void F_397 ( struct V_1 * V_2 , T_1 V_27 )
{
T_1 V_864 = V_56 -> V_596 ( V_2 , V_27 ) ;
if ( ! ( V_864 & V_27 ) )
V_56 -> V_609 ( V_2 , V_27 ) ;
}
static void F_398 ( struct V_1 * V_2 )
{
struct V_776 * V_777 = & V_2 -> V_5 . V_865 ;
if ( V_777 -> V_49 . V_32 == V_33 )
F_32 ( V_2 , & V_777 -> V_49 ) ;
else if ( V_777 -> V_49 . V_866 )
F_31 ( V_2 , V_777 -> V_49 . V_32 ,
V_777 -> V_49 . V_43 ) ;
else
F_26 ( V_2 , V_777 -> V_49 . V_32 ) ;
}
static void F_399 ( struct V_776 * V_777 )
{
memset ( & V_777 -> V_867 , 0 ,
( void * ) & V_777 -> V_868 - ( void * ) & V_777 -> V_867 ) ;
V_777 -> V_869 . V_694 = 0 ;
V_777 -> V_869 . V_870 = 0 ;
V_777 -> V_871 . V_872 = 0 ;
V_777 -> V_871 . V_870 = 0 ;
V_777 -> V_873 . V_872 = 0 ;
V_777 -> V_873 . V_870 = 0 ;
}
static void F_400 ( struct V_1 * V_2 )
{
struct V_776 * V_777 = & V_2 -> V_5 . V_865 ;
int V_113 , V_114 ;
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
V_777 -> V_874 = F_401 ( V_2 ) ;
V_777 -> V_875 = F_402 ( V_2 ) ;
V_777 -> V_282 = ( ! F_403 ( V_2 ) ) ? V_876 :
( V_777 -> V_874 & V_877 ) ? V_878 :
V_114 ? V_879 :
V_113 ? V_880 :
V_881 ;
V_777 -> V_882 = F_404 ( V_2 ) ;
F_399 ( V_777 ) ;
V_2 -> V_5 . V_883 = false ;
}
int F_405 ( struct V_1 * V_2 , int V_572 , int V_884 )
{
struct V_776 * V_777 = & V_2 -> V_5 . V_865 ;
int V_89 ;
F_400 ( V_2 ) ;
V_777 -> V_885 = 2 ;
V_777 -> V_886 = 2 ;
V_777 -> V_887 = V_777 -> V_875 + V_884 ;
V_89 = F_406 ( V_777 , V_572 ) ;
if ( V_89 != V_772 )
return V_888 ;
V_777 -> V_875 = V_777 -> V_887 ;
F_407 ( V_2 , V_777 -> V_875 ) ;
F_372 ( V_2 , V_777 -> V_874 ) ;
if ( V_572 == V_889 )
V_2 -> V_5 . V_601 = 0 ;
else
V_2 -> V_5 . V_593 . V_50 = false ;
return V_890 ;
}
static int F_408 ( struct V_1 * V_2 )
{
int V_100 = V_890 ;
++ V_2 -> V_60 . V_891 ;
F_409 ( V_2 ) ;
if ( ! F_404 ( V_2 ) ) {
V_2 -> V_788 -> V_803 = V_892 ;
V_2 -> V_788 -> V_893 . V_894 = V_895 ;
V_2 -> V_788 -> V_893 . V_896 = 0 ;
V_100 = V_888 ;
}
F_26 ( V_2 , V_167 ) ;
return V_100 ;
}
static bool F_410 ( struct V_1 * V_2 , T_14 V_62 ,
bool V_897 ,
int V_898 )
{
T_5 V_379 = V_62 ;
T_15 V_899 ;
if ( V_898 & V_900 )
return false ;
if ( ! V_2 -> V_5 . V_67 . V_901 ) {
V_379 = F_316 ( V_2 , V_62 , NULL ) ;
if ( V_379 == V_80 )
return true ;
}
V_899 = F_411 ( V_2 -> V_82 , F_40 ( V_379 ) ) ;
if ( F_412 ( V_899 ) )
return false ;
F_413 ( V_899 ) ;
if ( V_2 -> V_5 . V_67 . V_901 ) {
unsigned int V_902 ;
F_131 ( & V_2 -> V_82 -> V_709 ) ;
V_902 = V_2 -> V_82 -> V_5 . V_902 ;
F_132 ( & V_2 -> V_82 -> V_709 ) ;
if ( V_902 )
F_414 ( V_2 -> V_82 , F_40 ( V_379 ) ) ;
return true ;
}
F_414 ( V_2 -> V_82 , F_40 ( V_379 ) ) ;
return ! V_897 ;
}
static bool F_415 ( struct V_776 * V_777 ,
unsigned long V_62 , int V_898 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
unsigned long V_903 , V_904 , V_379 = V_62 ;
V_903 = V_2 -> V_5 . V_903 ;
V_904 = V_2 -> V_5 . V_904 ;
V_2 -> V_5 . V_903 = V_2 -> V_5 . V_904 = 0 ;
if ( ! ( V_898 & V_905 ) )
return false ;
if ( F_416 ( V_777 ) )
return false ;
if ( V_777 -> V_875 == V_903 && V_904 == V_62 )
return false ;
V_2 -> V_5 . V_903 = V_777 -> V_875 ;
V_2 -> V_5 . V_904 = V_62 ;
if ( ! V_2 -> V_5 . V_67 . V_901 )
V_379 = F_316 ( V_2 , V_62 , NULL ) ;
F_414 ( V_2 -> V_82 , F_40 ( V_379 ) ) ;
return true ;
}
static int F_417 ( unsigned long V_364 , T_1 type , T_1 V_149 ,
unsigned long * V_158 )
{
T_1 V_161 = 0 ;
int V_3 ;
T_1 V_906 , V_907 ;
V_906 = V_149 ;
V_907 = V_149 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_906 >>= 2 , V_907 >>= 4 )
if ( ( V_906 & 3 ) && ( V_907 & 15 ) == type && V_158 [ V_3 ] == V_364 )
V_161 |= ( 1 << V_3 ) ;
return V_161 ;
}
static void F_418 ( struct V_1 * V_2 , int * V_100 )
{
struct V_908 * V_908 = V_2 -> V_788 ;
unsigned long V_909 = V_56 -> V_910 ( V_2 ) ;
if ( F_140 ( V_909 & V_911 ) ) {
if ( V_2 -> V_150 & V_912 ) {
V_908 -> V_913 . V_5 . V_161 = V_914 | V_163 ;
V_908 -> V_913 . V_5 . V_915 = V_2 -> V_5 . V_916 ;
V_908 -> V_913 . V_5 . V_49 = V_917 ;
V_908 -> V_803 = V_918 ;
* V_100 = V_919 ;
} else {
V_2 -> V_5 . V_865 . V_874 &= ~ V_911 ;
V_2 -> V_5 . V_161 &= ~ 15 ;
V_2 -> V_5 . V_161 |= V_914 ;
F_26 ( V_2 , V_917 ) ;
}
}
}
static bool F_419 ( struct V_1 * V_2 , int * V_100 )
{
struct V_908 * V_908 = V_2 -> V_788 ;
unsigned long V_875 = V_2 -> V_5 . V_865 . V_875 ;
T_1 V_161 = 0 ;
if ( F_140 ( V_2 -> V_150 & V_151 ) &&
( V_2 -> V_5 . V_152 & V_155 ) ) {
V_161 = F_417 ( V_875 , 0 ,
V_2 -> V_5 . V_152 ,
V_2 -> V_5 . V_159 ) ;
if ( V_161 != 0 ) {
V_908 -> V_913 . V_5 . V_161 = V_161 | V_163 ;
V_908 -> V_913 . V_5 . V_915 = F_402 ( V_2 ) +
F_356 ( V_2 , V_920 ) ;
V_908 -> V_913 . V_5 . V_49 = V_917 ;
V_908 -> V_803 = V_918 ;
* V_100 = V_919 ;
return true ;
}
}
if ( F_140 ( V_2 -> V_5 . V_149 & V_155 ) ) {
V_161 = F_417 ( V_875 , 0 ,
V_2 -> V_5 . V_149 ,
V_2 -> V_5 . V_158 ) ;
if ( V_161 != 0 ) {
V_2 -> V_5 . V_161 &= ~ 15 ;
V_2 -> V_5 . V_161 |= V_161 ;
F_26 ( V_2 , V_917 ) ;
* V_100 = V_890 ;
return true ;
}
}
return false ;
}
int F_420 ( struct V_1 * V_2 ,
unsigned long V_62 ,
int V_898 ,
void * V_921 ,
int V_922 )
{
int V_100 ;
struct V_776 * V_777 = & V_2 -> V_5 . V_865 ;
bool V_476 = true ;
bool V_923 = V_2 -> V_5 . V_897 ;
V_2 -> V_5 . V_897 = false ;
F_421 ( V_2 ) ;
if ( ! ( V_898 & V_924 ) ) {
F_400 ( V_2 ) ;
if ( F_419 ( V_2 , & V_100 ) )
return V_100 ;
V_777 -> V_925 = 0 ;
V_777 -> V_926 = false ;
V_777 -> V_927 = false ;
V_777 -> V_928 = V_898 & V_929 ;
V_100 = F_422 ( V_777 , V_921 , V_922 ) ;
F_423 ( V_2 ) ;
++ V_2 -> V_60 . V_930 ;
if ( V_100 != V_931 ) {
if ( V_898 & V_929 )
return V_888 ;
if ( F_410 ( V_2 , V_62 , V_923 ,
V_898 ) )
return V_890 ;
if ( V_898 & V_932 )
return V_888 ;
return F_408 ( V_2 ) ;
}
}
if ( V_898 & V_932 ) {
F_407 ( V_2 , V_777 -> V_887 ) ;
return V_890 ;
}
if ( F_415 ( V_777 , V_62 , V_898 ) )
return V_890 ;
if ( V_2 -> V_5 . V_883 ) {
V_2 -> V_5 . V_883 = false ;
F_424 ( V_777 ) ;
}
V_933:
V_100 = F_425 ( V_777 ) ;
if ( V_100 == V_934 )
return V_890 ;
if ( V_100 == V_935 ) {
if ( F_410 ( V_2 , V_62 , V_923 ,
V_898 ) )
return V_890 ;
return F_408 ( V_2 ) ;
}
if ( V_777 -> V_926 ) {
F_398 ( V_2 ) ;
V_100 = V_890 ;
} else if ( V_2 -> V_5 . V_818 . V_692 ) {
if ( ! V_2 -> V_5 . V_818 . V_819 ) {
V_2 -> V_5 . V_818 . V_692 = 0 ;
} else {
V_476 = false ;
V_2 -> V_5 . V_936 = V_937 ;
}
V_100 = V_919 ;
} else if ( V_2 -> V_799 ) {
if ( ! V_2 -> V_802 )
V_476 = false ;
V_100 = V_919 ;
V_2 -> V_5 . V_936 = V_938 ;
} else if ( V_100 == V_939 )
goto V_933;
else
V_100 = V_890 ;
if ( V_476 ) {
F_397 ( V_2 , V_777 -> V_925 ) ;
F_25 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_940 = false ;
F_407 ( V_2 , V_777 -> V_875 ) ;
if ( V_100 == V_890 )
F_418 ( V_2 , & V_100 ) ;
F_372 ( V_2 , V_777 -> V_874 ) ;
} else
V_2 -> V_5 . V_940 = true ;
return V_100 ;
}
int F_426 ( struct V_1 * V_2 , int V_478 , unsigned short V_820 )
{
unsigned long V_157 = F_88 ( V_2 , V_170 ) ;
int V_89 = F_355 ( & V_2 -> V_5 . V_865 ,
V_478 , V_820 , & V_157 , 1 ) ;
V_2 -> V_5 . V_818 . V_692 = 0 ;
return V_89 ;
}
static void F_427 ( void * V_857 )
{
F_428 ( V_296 , 0 ) ;
}
static void F_429 ( void * V_31 )
{
struct V_941 * V_942 = V_31 ;
unsigned long V_228 = 0 ;
if ( V_31 )
V_228 = V_942 -> V_810 ;
else if ( ! F_221 ( V_943 ) )
V_228 = F_430 ( F_431 () ) ;
if ( ! V_228 )
V_228 = V_236 ;
F_428 ( V_296 , V_228 ) ;
}
static int F_432 ( struct V_944 * V_945 , unsigned long V_157 ,
void * V_31 )
{
struct V_941 * V_942 = V_31 ;
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 , V_946 = 0 ;
if ( V_157 == V_947 && V_942 -> V_809 > V_942 -> V_810 )
return 0 ;
if ( V_157 == V_948 && V_942 -> V_809 < V_942 -> V_810 )
return 0 ;
F_230 ( V_942 -> V_23 , F_429 , V_942 , 1 ) ;
F_131 ( & V_949 ) ;
F_433 (kvm, &vm_list, vm_list) {
F_149 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_942 -> V_23 )
continue;
F_25 ( V_287 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_946 = 1 ;
}
}
F_132 ( & V_949 ) ;
if ( V_942 -> V_809 < V_942 -> V_810 && V_946 ) {
F_230 ( V_942 -> V_23 , F_429 , V_942 , 1 ) ;
}
return 0 ;
}
static int F_434 ( struct V_944 * V_950 ,
unsigned long V_951 , void * V_952 )
{
unsigned int V_23 = ( unsigned long ) V_952 ;
switch ( V_951 ) {
case V_953 :
case V_954 :
F_230 ( V_23 , F_429 , NULL , 1 ) ;
break;
case V_955 :
F_230 ( V_23 , F_427 , NULL , 1 ) ;
break;
}
return V_956 ;
}
static void F_435 ( void )
{
int V_23 ;
V_957 = V_236 ;
F_436 ( & V_958 ) ;
if ( ! F_221 ( V_943 ) ) {
#ifdef F_437
struct V_959 V_960 ;
memset ( & V_960 , 0 , sizeof( V_960 ) ) ;
V_23 = F_360 () ;
F_438 ( & V_960 , V_23 ) ;
if ( V_960 . V_961 . V_962 )
V_957 = V_960 . V_961 . V_962 ;
F_362 () ;
#endif
F_439 ( & V_963 ,
V_964 ) ;
}
F_109 ( L_24 , V_957 ) ;
F_440 (cpu)
F_230 ( V_23 , F_429 , NULL , 1 ) ;
}
int F_441 ( void )
{
return F_442 ( V_965 ) != NULL ;
}
static int F_443 ( void )
{
int V_966 = 3 ;
if ( F_442 ( V_965 ) )
V_966 = V_56 -> V_71 ( F_442 ( V_965 ) ) ;
return V_966 != 0 ;
}
static unsigned long F_444 ( void )
{
unsigned long V_967 = 0 ;
if ( F_442 ( V_965 ) )
V_967 = F_402 ( F_442 ( V_965 ) ) ;
return V_967 ;
}
void F_445 ( struct V_1 * V_2 )
{
F_428 ( V_965 , V_2 ) ;
}
void F_446 ( struct V_1 * V_2 )
{
F_428 ( V_965 , NULL ) ;
}
static void F_447 ( void )
{
T_2 V_27 ;
int V_968 = V_969 . V_970 ;
V_27 = ( ( 1ull << ( 51 - V_968 + 1 ) ) - 1 ) << V_968 ;
V_27 |= 0x3ull << 62 ;
V_27 |= 1ull ;
#ifdef F_54
if ( V_968 == 52 )
V_27 &= ~ 1ull ;
#endif
F_448 ( V_27 ) ;
}
static void F_449 ( struct V_971 * V_972 )
{
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 ;
F_131 ( & V_949 ) ;
F_433 (kvm, &vm_list, vm_list)
F_149 (i, vcpu, kvm)
F_150 ( V_252 , & V_2 -> V_288 ) ;
F_145 ( & V_286 , 0 ) ;
F_132 ( & V_949 ) ;
}
static int F_450 ( struct V_944 * V_945 , unsigned long V_973 ,
void * V_974 )
{
struct V_188 * V_247 = & V_188 ;
struct V_186 * V_187 = V_974 ;
F_98 ( V_187 ) ;
if ( V_247 -> clock . V_191 != V_250 &&
F_123 ( & V_286 ) != 0 )
F_451 ( V_975 , & V_976 ) ;
return 0 ;
}
int F_452 ( void * V_977 )
{
int V_100 ;
struct V_56 * V_791 = V_977 ;
if ( V_56 ) {
F_10 ( V_26 L_25 ) ;
V_100 = - V_727 ;
goto V_94;
}
if ( ! V_791 -> V_978 () ) {
F_10 ( V_26 L_26 ) ;
V_100 = - V_979 ;
goto V_94;
}
if ( V_791 -> V_980 () ) {
F_10 ( V_26 L_27 ) ;
V_100 = - V_979 ;
goto V_94;
}
V_100 = - V_357 ;
V_25 = F_453 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_94;
}
V_100 = F_454 () ;
if ( V_100 )
goto V_981;
F_447 () ;
F_300 () ;
V_56 = V_791 ;
F_455 ( V_982 , V_983 ,
V_984 , V_985 , 0 ) ;
F_435 () ;
F_456 ( & V_986 ) ;
if ( V_531 )
V_123 = F_457 ( V_121 ) ;
F_458 () ;
#ifdef F_54
F_459 ( & V_987 ) ;
#endif
return 0 ;
V_981:
F_460 ( V_25 ) ;
V_94:
return V_100 ;
}
void F_461 ( void )
{
F_462 ( & V_986 ) ;
if ( ! F_221 ( V_943 ) )
F_463 ( & V_963 ,
V_964 ) ;
F_464 ( & V_958 ) ;
#ifdef F_54
F_465 ( & V_987 ) ;
#endif
V_56 = NULL ;
F_466 () ;
F_460 ( V_25 ) ;
}
int F_467 ( struct V_1 * V_2 )
{
++ V_2 -> V_60 . V_988 ;
if ( F_78 ( V_2 -> V_82 ) ) {
V_2 -> V_5 . V_989 = V_990 ;
return 1 ;
} else {
V_2 -> V_788 -> V_803 = V_991 ;
return 0 ;
}
}
int F_468 ( struct V_1 * V_2 )
{
T_2 V_992 , V_993 , V_994 , V_89 ;
T_16 V_995 , V_996 , V_997 , V_166 = V_998 , V_999 = 0 ;
bool V_1000 , V_1001 ;
int V_113 , V_114 ;
if ( V_56 -> V_71 ( V_2 ) != 0 || ! F_403 ( V_2 ) ) {
F_26 ( V_2 , V_167 ) ;
return 0 ;
}
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
V_1001 = F_48 ( V_2 ) && V_114 == 1 ;
if ( ! V_1001 ) {
V_992 = ( ( T_2 ) F_88 ( V_2 , V_171 ) << 32 ) |
( F_88 ( V_2 , V_170 ) & 0xffffffff ) ;
V_993 = ( ( T_2 ) F_88 ( V_2 , V_1002 ) << 32 ) |
( F_88 ( V_2 , V_169 ) & 0xffffffff ) ;
V_994 = ( ( T_2 ) F_88 ( V_2 , V_1003 ) << 32 ) |
( F_88 ( V_2 , V_1004 ) & 0xffffffff ) ;
}
#ifdef F_54
else {
V_992 = F_88 ( V_2 , V_169 ) ;
V_993 = F_88 ( V_2 , V_171 ) ;
V_994 = F_88 ( V_2 , V_1005 ) ;
}
#endif
V_995 = V_992 & 0xffff ;
V_1000 = ( V_992 >> 16 ) & 0x1 ;
V_997 = ( V_992 >> 32 ) & 0xfff ;
V_996 = ( V_992 >> 48 ) & 0xfff ;
F_469 ( V_995 , V_1000 , V_997 , V_996 , V_993 , V_994 ) ;
switch ( V_995 ) {
case V_1006 :
F_470 ( V_2 ) ;
break;
default:
V_166 = V_1007 ;
break;
}
V_89 = V_166 | ( ( ( T_2 ) V_999 & 0xfff ) << 32 ) ;
if ( V_1001 ) {
F_90 ( V_2 , V_170 , V_89 ) ;
} else {
F_90 ( V_2 , V_171 , V_89 >> 32 ) ;
F_90 ( V_2 , V_170 , V_89 & 0xffffffff ) ;
}
return 1 ;
}
static void F_471 ( struct V_82 * V_82 , unsigned long V_259 , int V_1008 )
{
struct V_1009 V_1010 ;
V_1010 . V_1011 = 0 ;
V_1010 . V_1012 = 0 ;
V_1010 . V_1013 = V_1008 ;
V_1010 . V_1014 = V_1015 ;
F_472 ( V_82 , 0 , & V_1010 , NULL ) ;
}
int F_473 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1016 , V_1017 , V_1018 , V_1019 , V_89 ;
int V_100 = 1 ;
if ( F_173 ( V_2 -> V_82 ) )
return F_468 ( V_2 ) ;
V_16 = F_88 ( V_2 , V_170 ) ;
V_1016 = F_88 ( V_2 , V_1002 ) ;
V_1017 = F_88 ( V_2 , V_169 ) ;
V_1018 = F_88 ( V_2 , V_171 ) ;
V_1019 = F_88 ( V_2 , V_1004 ) ;
F_474 ( V_16 , V_1016 , V_1017 , V_1018 , V_1019 ) ;
if ( ! F_48 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_1016 &= 0xFFFFFFFF ;
V_1017 &= 0xFFFFFFFF ;
V_1018 &= 0xFFFFFFFF ;
V_1019 &= 0xFFFFFFFF ;
}
if ( V_56 -> V_71 ( V_2 ) != 0 ) {
V_89 = - V_1020 ;
goto V_94;
}
switch ( V_16 ) {
case V_1021 :
V_89 = 0 ;
break;
case V_1022 :
F_471 ( V_2 -> V_82 , V_1016 , V_1017 ) ;
V_89 = 0 ;
break;
default:
V_89 = - V_1023 ;
break;
}
V_94:
F_90 ( V_2 , V_170 , V_89 ) ;
++ V_2 -> V_60 . V_1024 ;
return V_100 ;
}
static int F_475 ( struct V_776 * V_777 )
{
struct V_1 * V_2 = F_320 ( V_777 ) ;
char V_1025 [ 3 ] ;
unsigned long V_1026 = F_402 ( V_2 ) ;
V_56 -> V_367 ( V_2 , V_1025 ) ;
return F_340 ( V_777 , V_1026 , V_1025 , 3 , NULL ) ;
}
static int F_476 ( struct V_1 * V_2 )
{
return ( ! F_78 ( V_2 -> V_82 ) && ! F_477 ( V_2 ) &&
V_2 -> V_788 -> V_1027 &&
F_478 ( V_2 ) ) ;
}
static void F_479 ( struct V_1 * V_2 )
{
struct V_908 * V_908 = V_2 -> V_788 ;
V_908 -> V_1028 = ( F_401 ( V_2 ) & V_1029 ) != 0 ;
V_908 -> V_147 = F_80 ( V_2 ) ;
V_908 -> V_30 = F_18 ( V_2 ) ;
if ( F_78 ( V_2 -> V_82 ) )
V_908 -> V_1030 = 1 ;
else
V_908 -> V_1030 =
F_478 ( V_2 ) &&
! F_477 ( V_2 ) &&
! F_480 ( V_2 ) ;
}
static void F_239 ( struct V_1 * V_2 )
{
int V_1031 , V_1032 ;
if ( ! V_56 -> F_239 )
return;
if ( ! V_2 -> V_5 . V_570 )
return;
if ( ! V_2 -> V_5 . V_570 -> V_650 )
V_1031 = F_481 ( V_2 ) ;
else
V_1031 = - 1 ;
if ( V_1031 != - 1 )
V_1031 >>= 4 ;
V_1032 = F_81 ( V_2 ) ;
V_56 -> F_239 ( V_2 , V_1032 , V_1031 ) ;
}
static void F_482 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_49 . V_50 ) {
F_483 ( V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ) ;
V_56 -> V_1033 ( V_2 , V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ,
V_2 -> V_5 . V_49 . V_44 ) ;
return;
}
if ( V_2 -> V_5 . V_600 ) {
V_56 -> V_1034 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_593 . V_50 ) {
V_56 -> V_1035 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_601 ) {
if ( V_56 -> V_1036 ( V_2 ) ) {
-- V_2 -> V_5 . V_601 ;
V_2 -> V_5 . V_600 = true ;
V_56 -> V_1034 ( V_2 ) ;
}
} else if ( F_484 ( V_2 ) ) {
if ( V_56 -> V_1037 ( V_2 ) ) {
F_241 ( V_2 , F_485 ( V_2 ) ,
false ) ;
V_56 -> V_1035 ( V_2 ) ;
}
}
}
static void F_247 ( struct V_1 * V_2 )
{
unsigned V_846 = 2 ;
if ( V_56 -> V_603 ( V_2 ) || V_2 -> V_5 . V_600 )
V_846 = 1 ;
V_2 -> V_5 . V_601 += F_486 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_601 = F_303 ( V_2 -> V_5 . V_601 , V_846 ) ;
F_25 ( V_48 , V_2 ) ;
}
static void F_487 ( struct V_1 * V_2 )
{
T_2 V_1038 [ 4 ] ;
T_1 V_1039 [ 8 ] ;
if ( ! F_488 ( V_2 -> V_5 . V_570 ) )
return;
memset ( V_1038 , 0 , 32 ) ;
memset ( V_1039 , 0 , 32 ) ;
F_489 ( V_2 , V_1038 , V_1039 ) ;
V_56 -> V_1040 ( V_2 , V_1038 ) ;
F_490 ( V_2 , V_1039 ) ;
}
static int F_491 ( struct V_1 * V_2 )
{
int V_100 ;
bool V_1041 = ! F_78 ( V_2 -> V_82 ) &&
V_2 -> V_788 -> V_1027 ;
bool V_1042 = false ;
if ( V_2 -> V_288 ) {
if ( F_492 ( V_1043 , V_2 ) )
F_493 ( V_2 ) ;
if ( F_492 ( V_1044 , V_2 ) )
F_494 ( V_2 ) ;
if ( F_492 ( V_252 , V_2 ) )
F_147 ( V_2 -> V_82 ) ;
if ( F_492 ( V_421 , V_2 ) )
F_160 ( V_2 ) ;
if ( F_492 ( V_287 , V_2 ) ) {
V_100 = F_152 ( V_2 ) ;
if ( F_140 ( V_100 ) )
goto V_94;
}
if ( F_492 ( V_1045 , V_2 ) )
F_74 ( V_2 ) ;
if ( F_492 ( V_1046 , V_2 ) )
V_56 -> V_1047 ( V_2 ) ;
if ( F_492 ( V_1048 , V_2 ) ) {
V_2 -> V_788 -> V_803 = V_1049 ;
V_100 = 0 ;
goto V_94;
}
if ( F_492 ( V_54 , V_2 ) ) {
V_2 -> V_788 -> V_803 = V_1050 ;
V_100 = 0 ;
goto V_94;
}
if ( F_492 ( V_1051 , V_2 ) ) {
V_2 -> V_1052 = 0 ;
V_56 -> V_1053 ( V_2 ) ;
}
if ( F_492 ( V_1054 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1055 = true ;
V_100 = 1 ;
goto V_94;
}
if ( F_492 ( V_426 , V_2 ) )
F_188 ( V_2 ) ;
if ( F_492 ( V_69 , V_2 ) )
F_247 ( V_2 ) ;
if ( F_492 ( V_1056 , V_2 ) )
F_495 ( V_2 ) ;
if ( F_492 ( V_1057 , V_2 ) )
F_496 ( V_2 ) ;
if ( F_492 ( V_1058 , V_2 ) )
F_487 ( V_2 ) ;
}
if ( F_492 ( V_48 , V_2 ) || V_1041 ) {
F_497 ( V_2 ) ;
if ( V_2 -> V_5 . V_989 == V_1059 ) {
V_100 = 1 ;
goto V_94;
}
F_482 ( V_2 ) ;
if ( V_2 -> V_5 . V_601 )
V_1042 =
V_56 -> V_1060 ( V_2 ) != 0 ;
else if ( F_484 ( V_2 ) || V_1041 )
V_1042 =
V_56 -> V_1061 ( V_2 ) != 0 ;
if ( F_498 ( V_2 ) ) {
if ( V_56 -> V_1062 )
V_56 -> V_1062 ( V_2 ,
F_481 ( V_2 ) ) ;
F_239 ( V_2 ) ;
F_499 ( V_2 ) ;
}
}
V_100 = F_500 ( V_2 ) ;
if ( F_140 ( V_100 ) ) {
goto V_1063;
}
F_193 () ;
V_56 -> V_1064 ( V_2 ) ;
if ( V_2 -> V_1052 )
F_390 ( V_2 ) ;
F_61 ( V_2 ) ;
V_2 -> V_282 = V_1065 ;
F_214 ( & V_2 -> V_82 -> V_473 , V_2 -> V_1066 ) ;
F_501 () ;
F_298 () ;
if ( V_2 -> V_282 == V_1067 || V_2 -> V_288
|| F_502 () || F_503 ( V_386 ) ) {
V_2 -> V_282 = V_1068 ;
F_13 () ;
F_299 () ;
F_194 () ;
V_2 -> V_1066 = F_213 ( & V_2 -> V_82 -> V_473 ) ;
V_100 = 1 ;
goto V_1063;
}
if ( V_1042 )
F_504 ( V_2 -> V_23 ) ;
F_505 () ;
if ( F_140 ( V_2 -> V_5 . V_154 ) ) {
F_506 ( 0 , 7 ) ;
F_506 ( V_2 -> V_5 . V_159 [ 0 ] , 0 ) ;
F_506 ( V_2 -> V_5 . V_159 [ 1 ] , 1 ) ;
F_506 ( V_2 -> V_5 . V_159 [ 2 ] , 2 ) ;
F_506 ( V_2 -> V_5 . V_159 [ 3 ] , 3 ) ;
}
F_507 ( V_2 -> V_253 ) ;
V_56 -> V_788 ( V_2 ) ;
if ( F_508 () )
F_509 () ;
V_2 -> V_5 . V_276 = V_56 -> V_297 ( V_2 ,
F_156 () ) ;
V_2 -> V_282 = V_1068 ;
F_13 () ;
V_56 -> V_1069 ( V_2 ) ;
++ V_2 -> V_60 . V_1070 ;
F_510 () ;
F_511 () ;
F_194 () ;
V_2 -> V_1066 = F_213 ( & V_2 -> V_82 -> V_473 ) ;
if ( F_140 ( V_1071 == V_1072 ) ) {
unsigned long V_1026 = F_402 ( V_2 ) ;
F_512 ( V_1072 , ( void * ) V_1026 ) ;
}
if ( F_140 ( V_2 -> V_5 . V_1073 ) )
F_25 ( V_287 , V_2 ) ;
if ( V_2 -> V_5 . V_1074 )
F_513 ( V_2 ) ;
V_100 = V_56 -> V_1075 ( V_2 ) ;
return V_100 ;
V_1063:
V_56 -> V_1063 ( V_2 ) ;
if ( F_140 ( V_2 -> V_5 . V_1074 ) )
F_513 ( V_2 ) ;
V_94:
return V_100 ;
}
static int F_514 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_82 * V_82 = V_2 -> V_82 ;
V_2 -> V_1066 = F_213 ( & V_82 -> V_473 ) ;
V_100 = 1 ;
while ( V_100 > 0 ) {
if ( V_2 -> V_5 . V_989 == V_1076 &&
! V_2 -> V_5 . V_6 . V_1055 )
V_100 = F_491 ( V_2 ) ;
else {
F_214 ( & V_82 -> V_473 , V_2 -> V_1066 ) ;
F_515 ( V_2 ) ;
V_2 -> V_1066 = F_213 ( & V_82 -> V_473 ) ;
if ( F_492 ( V_1077 , V_2 ) ) {
F_497 ( V_2 ) ;
switch( V_2 -> V_5 . V_989 ) {
case V_990 :
V_2 -> V_5 . V_1078 . V_1079 = false ;
V_2 -> V_5 . V_989 =
V_1076 ;
case V_1076 :
V_2 -> V_5 . V_6 . V_1055 = false ;
break;
case V_1059 :
break;
default:
V_100 = - V_1080 ;
break;
}
}
}
if ( V_100 <= 0 )
break;
F_151 ( V_1081 , & V_2 -> V_288 ) ;
if ( F_516 ( V_2 ) )
F_517 ( V_2 ) ;
if ( F_476 ( V_2 ) ) {
V_100 = - V_1080 ;
V_2 -> V_788 -> V_803 = V_1082 ;
++ V_2 -> V_60 . V_1083 ;
}
F_518 ( V_2 ) ;
if ( F_503 ( V_386 ) ) {
V_100 = - V_1080 ;
V_2 -> V_788 -> V_803 = V_1082 ;
++ V_2 -> V_60 . V_1084 ;
}
if ( F_502 () ) {
F_214 ( & V_82 -> V_473 , V_2 -> V_1066 ) ;
F_519 ( V_2 ) ;
V_2 -> V_1066 = F_213 ( & V_82 -> V_473 ) ;
}
}
F_214 ( & V_82 -> V_473 , V_2 -> V_1066 ) ;
return V_100 ;
}
static inline int F_520 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_1066 = F_213 ( & V_2 -> V_82 -> V_473 ) ;
V_100 = F_521 ( V_2 , V_924 ) ;
F_214 ( & V_2 -> V_82 -> V_473 , V_2 -> V_1066 ) ;
if ( V_100 != V_890 )
return 0 ;
return 1 ;
}
static int V_937 ( struct V_1 * V_2 )
{
F_313 ( ! V_2 -> V_5 . V_818 . V_692 ) ;
return F_520 ( V_2 ) ;
}
static int V_938 ( struct V_1 * V_2 )
{
struct V_908 * V_788 = V_2 -> V_788 ;
struct V_786 * V_787 ;
unsigned V_75 ;
F_313 ( ! V_2 -> V_799 ) ;
V_787 = & V_2 -> V_783 [ V_2 -> V_800 ] ;
V_75 = F_303 ( 8u , V_787 -> V_75 ) ;
if ( ! V_2 -> V_802 )
memcpy ( V_787 -> V_31 , V_788 -> V_789 . V_31 , V_75 ) ;
if ( V_787 -> V_75 <= 8 ) {
V_787 ++ ;
V_2 -> V_800 ++ ;
} else {
V_787 -> V_31 += V_75 ;
V_787 -> V_379 += V_75 ;
V_787 -> V_75 -= V_75 ;
}
if ( V_2 -> V_800 == V_2 -> V_794 ) {
V_2 -> V_799 = 0 ;
if ( V_2 -> V_802 )
return 1 ;
V_2 -> V_782 = 1 ;
return F_520 ( V_2 ) ;
}
V_788 -> V_803 = V_804 ;
V_788 -> V_789 . V_805 = V_787 -> V_379 ;
if ( V_2 -> V_802 )
memcpy ( V_788 -> V_789 . V_31 , V_787 -> V_31 , F_303 ( 8u , V_787 -> V_75 ) ) ;
V_788 -> V_789 . V_75 = F_303 ( 8u , V_787 -> V_75 ) ;
V_788 -> V_789 . V_801 = V_2 -> V_802 ;
V_2 -> V_5 . V_936 = V_938 ;
return 0 ;
}
int F_522 ( struct V_1 * V_2 , struct V_908 * V_908 )
{
int V_100 ;
T_17 V_1085 ;
if ( ! F_523 ( V_386 ) && F_524 ( V_386 ) )
return - V_357 ;
if ( V_2 -> V_1086 )
F_525 ( V_1087 , & V_2 -> V_1088 , & V_1085 ) ;
if ( F_140 ( V_2 -> V_5 . V_989 == V_1089 ) ) {
F_515 ( V_2 ) ;
F_497 ( V_2 ) ;
F_151 ( V_1077 , & V_2 -> V_288 ) ;
V_100 = - V_1090 ;
goto V_94;
}
if ( ! F_78 ( V_2 -> V_82 ) ) {
if ( F_77 ( V_2 , V_908 -> V_147 ) != 0 ) {
V_100 = - V_557 ;
goto V_94;
}
}
if ( F_140 ( V_2 -> V_5 . V_936 ) ) {
int (* F_526)( struct V_1 * ) = V_2 -> V_5 . V_936 ;
V_2 -> V_5 . V_936 = NULL ;
V_100 = F_526 ( V_2 ) ;
if ( V_100 <= 0 )
goto V_94;
} else
F_111 ( V_2 -> V_5 . V_818 . V_692 || V_2 -> V_799 ) ;
V_100 = F_514 ( V_2 ) ;
V_94:
F_479 ( V_2 ) ;
if ( V_2 -> V_1086 )
F_525 ( V_1087 , & V_1085 , NULL ) ;
return V_100 ;
}
int F_527 ( struct V_1 * V_2 , struct V_1091 * V_569 )
{
if ( V_2 -> V_5 . V_940 ) {
F_528 ( & V_2 -> V_5 . V_865 ) ;
V_2 -> V_5 . V_940 = false ;
}
V_569 -> V_1092 = F_88 ( V_2 , V_170 ) ;
V_569 -> V_1093 = F_88 ( V_2 , V_1002 ) ;
V_569 -> V_1094 = F_88 ( V_2 , V_169 ) ;
V_569 -> V_1095 = F_88 ( V_2 , V_171 ) ;
V_569 -> V_1096 = F_88 ( V_2 , V_1004 ) ;
V_569 -> V_1097 = F_88 ( V_2 , V_1003 ) ;
V_569 -> V_1098 = F_88 ( V_2 , V_1099 ) ;
V_569 -> V_1100 = F_88 ( V_2 , V_1101 ) ;
#ifdef F_54
V_569 -> V_1102 = F_88 ( V_2 , V_1005 ) ;
V_569 -> V_1103 = F_88 ( V_2 , V_1104 ) ;
V_569 -> V_1105 = F_88 ( V_2 , V_1106 ) ;
V_569 -> V_1107 = F_88 ( V_2 , V_1108 ) ;
V_569 -> V_1109 = F_88 ( V_2 , V_1110 ) ;
V_569 -> V_1111 = F_88 ( V_2 , V_1112 ) ;
V_569 -> V_1113 = F_88 ( V_2 , V_1114 ) ;
V_569 -> V_1115 = F_88 ( V_2 , V_1116 ) ;
#endif
V_569 -> V_1026 = F_402 ( V_2 ) ;
V_569 -> V_909 = F_401 ( V_2 ) ;
return 0 ;
}
int F_529 ( struct V_1 * V_2 , struct V_1091 * V_569 )
{
V_2 -> V_5 . V_883 = true ;
V_2 -> V_5 . V_940 = false ;
F_90 ( V_2 , V_170 , V_569 -> V_1092 ) ;
F_90 ( V_2 , V_1002 , V_569 -> V_1093 ) ;
F_90 ( V_2 , V_169 , V_569 -> V_1094 ) ;
F_90 ( V_2 , V_171 , V_569 -> V_1095 ) ;
F_90 ( V_2 , V_1004 , V_569 -> V_1096 ) ;
F_90 ( V_2 , V_1003 , V_569 -> V_1097 ) ;
F_90 ( V_2 , V_1099 , V_569 -> V_1098 ) ;
F_90 ( V_2 , V_1101 , V_569 -> V_1100 ) ;
#ifdef F_54
F_90 ( V_2 , V_1005 , V_569 -> V_1102 ) ;
F_90 ( V_2 , V_1104 , V_569 -> V_1103 ) ;
F_90 ( V_2 , V_1106 , V_569 -> V_1105 ) ;
F_90 ( V_2 , V_1108 , V_569 -> V_1107 ) ;
F_90 ( V_2 , V_1110 , V_569 -> V_1109 ) ;
F_90 ( V_2 , V_1112 , V_569 -> V_1111 ) ;
F_90 ( V_2 , V_1114 , V_569 -> V_1113 ) ;
F_90 ( V_2 , V_1116 , V_569 -> V_1115 ) ;
#endif
F_407 ( V_2 , V_569 -> V_1026 ) ;
F_372 ( V_2 , V_569 -> V_909 ) ;
V_2 -> V_5 . V_49 . V_50 = false ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
void F_530 ( struct V_1 * V_2 , int * V_158 , int * V_851 )
{
struct V_762 V_1117 ;
F_311 ( V_2 , & V_1117 , V_920 ) ;
* V_158 = V_1117 . V_158 ;
* V_851 = V_1117 . V_851 ;
}
int F_531 ( struct V_1 * V_2 ,
struct V_1118 * V_1119 )
{
struct V_834 V_835 ;
F_311 ( V_2 , & V_1119 -> V_1117 , V_920 ) ;
F_311 ( V_2 , & V_1119 -> V_1120 , V_1121 ) ;
F_311 ( V_2 , & V_1119 -> V_1122 , V_1123 ) ;
F_311 ( V_2 , & V_1119 -> V_1124 , V_1125 ) ;
F_311 ( V_2 , & V_1119 -> V_1126 , V_1127 ) ;
F_311 ( V_2 , & V_1119 -> V_1128 , V_1129 ) ;
F_311 ( V_2 , & V_1119 -> V_1130 , V_1131 ) ;
F_311 ( V_2 , & V_1119 -> V_1132 , V_1133 ) ;
V_56 -> V_837 ( V_2 , & V_835 ) ;
V_1119 -> V_1134 . V_846 = V_835 . V_478 ;
V_1119 -> V_1134 . V_847 = V_835 . V_63 ;
V_56 -> V_836 ( V_2 , & V_835 ) ;
V_1119 -> V_1135 . V_846 = V_835 . V_478 ;
V_1119 -> V_1135 . V_847 = V_835 . V_63 ;
V_1119 -> V_101 = F_53 ( V_2 ) ;
V_1119 -> V_62 = V_2 -> V_5 . V_62 ;
V_1119 -> V_85 = F_51 ( V_2 ) ;
V_1119 -> V_131 = F_67 ( V_2 ) ;
V_1119 -> V_147 = F_80 ( V_2 ) ;
V_1119 -> V_111 = V_2 -> V_5 . V_111 ;
V_1119 -> V_30 = F_18 ( V_2 ) ;
memset ( V_1119 -> V_1136 , 0 , sizeof V_1119 -> V_1136 ) ;
if ( V_2 -> V_5 . V_593 . V_50 && ! V_2 -> V_5 . V_593 . V_594 )
F_150 ( V_2 -> V_5 . V_593 . V_16 ,
( unsigned long * ) V_1119 -> V_1136 ) ;
return 0 ;
}
int F_532 ( struct V_1 * V_2 ,
struct V_1137 * V_989 )
{
F_497 ( V_2 ) ;
if ( V_2 -> V_5 . V_989 == V_990 &&
V_2 -> V_5 . V_1078 . V_1079 )
V_989 -> V_989 = V_1076 ;
else
V_989 -> V_989 = V_2 -> V_5 . V_989 ;
return 0 ;
}
int F_533 ( struct V_1 * V_2 ,
struct V_1137 * V_989 )
{
if ( ! F_250 ( V_2 ) &&
V_989 -> V_989 != V_1076 )
return - V_557 ;
if ( V_989 -> V_989 == V_1138 ) {
V_2 -> V_5 . V_989 = V_1059 ;
F_150 ( V_1139 , & V_2 -> V_5 . V_570 -> V_1140 ) ;
} else
V_2 -> V_5 . V_989 = V_989 -> V_989 ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
int F_534 ( struct V_1 * V_2 , V_814 V_1141 , int V_1142 ,
int V_1143 , bool V_52 , T_1 V_43 )
{
struct V_776 * V_777 = & V_2 -> V_5 . V_865 ;
int V_89 ;
F_400 ( V_2 ) ;
V_89 = F_535 ( V_777 , V_1141 , V_1142 , V_1143 ,
V_52 , V_43 ) ;
if ( V_89 )
return V_888 ;
F_407 ( V_2 , V_777 -> V_875 ) ;
F_372 ( V_2 , V_777 -> V_874 ) ;
F_25 ( V_48 , V_2 ) ;
return V_890 ;
}
int F_536 ( struct V_1 * V_2 ,
struct V_1118 * V_1119 )
{
int V_1144 = 0 ;
int V_1145 , V_1146 , V_330 ;
struct V_834 V_835 ;
if ( ! F_68 ( V_2 ) && ( V_1119 -> V_131 & V_119 ) )
return - V_557 ;
V_835 . V_478 = V_1119 -> V_1134 . V_846 ;
V_835 . V_63 = V_1119 -> V_1134 . V_847 ;
V_56 -> V_839 ( V_2 , & V_835 ) ;
V_835 . V_478 = V_1119 -> V_1135 . V_846 ;
V_835 . V_63 = V_1119 -> V_1135 . V_847 ;
V_56 -> V_838 ( V_2 , & V_835 ) ;
V_2 -> V_5 . V_62 = V_1119 -> V_62 ;
V_1144 |= F_51 ( V_2 ) != V_1119 -> V_85 ;
V_2 -> V_5 . V_85 = V_1119 -> V_85 ;
F_46 ( V_145 , ( V_146 * ) & V_2 -> V_5 . V_97 ) ;
F_77 ( V_2 , V_1119 -> V_147 ) ;
V_1144 |= V_2 -> V_5 . V_111 != V_1119 -> V_111 ;
V_56 -> F_94 ( V_2 , V_1119 -> V_111 ) ;
F_19 ( V_2 , V_1119 -> V_30 ) ;
V_1144 |= F_53 ( V_2 ) != V_1119 -> V_101 ;
V_56 -> V_117 ( V_2 , V_1119 -> V_101 ) ;
V_2 -> V_5 . V_101 = V_1119 -> V_101 ;
V_1144 |= F_67 ( V_2 ) != V_1119 -> V_131 ;
V_56 -> V_141 ( V_2 , V_1119 -> V_131 ) ;
if ( V_1119 -> V_131 & V_119 )
F_72 ( V_2 ) ;
V_330 = F_213 ( & V_2 -> V_82 -> V_473 ) ;
if ( ! F_48 ( V_2 ) && F_49 ( V_2 ) ) {
F_43 ( V_2 , V_2 -> V_5 . V_84 , F_51 ( V_2 ) ) ;
V_1144 = 1 ;
}
F_214 ( & V_2 -> V_82 -> V_473 , V_330 ) ;
if ( V_1144 )
F_58 ( V_2 ) ;
V_1146 = V_573 ;
V_1145 = F_537 (
( const unsigned long * ) V_1119 -> V_1136 , V_1146 ) ;
if ( V_1145 < V_1146 ) {
F_241 ( V_2 , V_1145 , false ) ;
F_109 ( L_29 , V_1145 ) ;
}
F_310 ( V_2 , & V_1119 -> V_1117 , V_920 ) ;
F_310 ( V_2 , & V_1119 -> V_1120 , V_1121 ) ;
F_310 ( V_2 , & V_1119 -> V_1122 , V_1123 ) ;
F_310 ( V_2 , & V_1119 -> V_1124 , V_1125 ) ;
F_310 ( V_2 , & V_1119 -> V_1126 , V_1127 ) ;
F_310 ( V_2 , & V_1119 -> V_1128 , V_1129 ) ;
F_310 ( V_2 , & V_1119 -> V_1130 , V_1131 ) ;
F_310 ( V_2 , & V_1119 -> V_1132 , V_1133 ) ;
F_239 ( V_2 ) ;
if ( F_538 ( V_2 ) && F_402 ( V_2 ) == 0xfff0 &&
V_1119 -> V_1117 . V_840 == 0xf000 && V_1119 -> V_1117 . V_847 == 0xffff0000 &&
! F_403 ( V_2 ) )
V_2 -> V_5 . V_989 = V_1076 ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
int F_539 ( struct V_1 * V_2 ,
struct V_1147 * V_1148 )
{
unsigned long V_909 ;
int V_3 , V_100 ;
if ( V_1148 -> V_699 & ( V_1149 | V_1150 ) ) {
V_100 = - V_1151 ;
if ( V_2 -> V_5 . V_49 . V_50 )
goto V_94;
if ( V_1148 -> V_699 & V_1149 )
F_26 ( V_2 , V_917 ) ;
else
F_26 ( V_2 , V_1152 ) ;
}
V_909 = F_401 ( V_2 ) ;
V_2 -> V_150 = V_1148 -> V_699 ;
if ( ! ( V_2 -> V_150 & V_1153 ) )
V_2 -> V_150 = 0 ;
if ( V_2 -> V_150 & V_151 ) {
for ( V_3 = 0 ; V_3 < V_1154 ; ++ V_3 )
V_2 -> V_5 . V_159 [ V_3 ] = V_1148 -> V_5 . V_1155 [ V_3 ] ;
V_2 -> V_5 . V_152 = V_1148 -> V_5 . V_1155 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1154 ; V_3 ++ )
V_2 -> V_5 . V_159 [ V_3 ] = V_2 -> V_5 . V_158 [ V_3 ] ;
}
F_82 ( V_2 ) ;
if ( V_2 -> V_150 & V_912 )
V_2 -> V_5 . V_916 = F_402 ( V_2 ) +
F_356 ( V_2 , V_920 ) ;
F_372 ( V_2 , V_909 ) ;
V_56 -> V_1156 ( V_2 ) ;
V_100 = 0 ;
V_94:
return V_100 ;
}
int F_540 ( struct V_1 * V_2 ,
struct V_1157 * V_1130 )
{
unsigned long V_1158 = V_1130 -> V_1159 ;
T_5 V_379 ;
int V_330 ;
V_330 = F_213 ( & V_2 -> V_82 -> V_473 ) ;
V_379 = F_317 ( V_2 , V_1158 , NULL ) ;
F_214 ( & V_2 -> V_82 -> V_473 , V_330 ) ;
V_1130 -> V_1160 = V_379 ;
V_1130 -> V_1161 = V_379 != V_80 ;
V_1130 -> V_1162 = 1 ;
V_1130 -> V_1163 = 0 ;
return 0 ;
}
int F_541 ( struct V_1 * V_2 , struct V_1164 * V_1165 )
{
struct V_623 * V_622 =
& V_2 -> V_5 . V_616 . V_617 -> V_622 ;
memcpy ( V_1165 -> V_1166 , V_622 -> V_1167 , 128 ) ;
V_1165 -> V_1168 = V_622 -> V_1169 ;
V_1165 -> V_1170 = V_622 -> V_1171 ;
V_1165 -> V_1172 = V_622 -> V_1173 ;
V_1165 -> V_1174 = V_622 -> V_1175 ;
V_1165 -> V_1176 = V_622 -> V_1026 ;
V_1165 -> V_1177 = V_622 -> V_1178 ;
memcpy ( V_1165 -> V_1179 , V_622 -> V_1180 , sizeof V_622 -> V_1180 ) ;
return 0 ;
}
int F_542 ( struct V_1 * V_2 , struct V_1164 * V_1165 )
{
struct V_623 * V_622 =
& V_2 -> V_5 . V_616 . V_617 -> V_622 ;
memcpy ( V_622 -> V_1167 , V_1165 -> V_1166 , 128 ) ;
V_622 -> V_1169 = V_1165 -> V_1168 ;
V_622 -> V_1171 = V_1165 -> V_1170 ;
V_622 -> V_1173 = V_1165 -> V_1172 ;
V_622 -> V_1175 = V_1165 -> V_1174 ;
V_622 -> V_1026 = V_1165 -> V_1176 ;
V_622 -> V_1178 = V_1165 -> V_1177 ;
memcpy ( V_622 -> V_1180 , V_1165 -> V_1179 , sizeof V_622 -> V_1180 ) ;
return 0 ;
}
int F_543 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_544 ( & V_2 -> V_5 . V_616 ) ;
if ( V_55 )
return V_55 ;
F_545 ( & V_2 -> V_5 . V_616 ) ;
V_2 -> V_5 . V_122 = V_127 ;
V_2 -> V_5 . V_101 |= V_108 ;
return 0 ;
}
static void F_546 ( struct V_1 * V_2 )
{
F_547 ( & V_2 -> V_5 . V_616 ) ;
}
void F_390 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1181 )
return;
F_63 ( V_2 ) ;
V_2 -> V_1181 = 1 ;
F_548 () ;
F_549 ( & V_2 -> V_5 . V_616 ) ;
F_550 ( 1 ) ;
}
void F_235 ( struct V_1 * V_2 )
{
F_63 ( V_2 ) ;
if ( ! V_2 -> V_1181 )
return;
V_2 -> V_1181 = 0 ;
F_551 ( & V_2 -> V_5 . V_616 ) ;
F_552 () ;
++ V_2 -> V_60 . V_1182 ;
F_25 ( V_1051 , V_2 ) ;
F_550 ( 0 ) ;
}
void F_553 ( struct V_1 * V_2 )
{
F_186 ( V_2 ) ;
F_554 ( V_2 -> V_5 . V_560 ) ;
F_546 ( V_2 ) ;
V_56 -> V_1183 ( V_2 ) ;
}
struct V_1 * F_555 ( struct V_82 * V_82 ,
unsigned int V_1184 )
{
if ( F_128 () && F_123 ( & V_82 -> V_249 ) != 0 )
F_350 ( V_816
L_30
L_31 ) ;
return V_56 -> V_1185 ( V_82 , V_1184 ) ;
}
int F_556 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_5 . V_325 . V_1186 = 1 ;
V_100 = V_561 ( V_2 ) ;
if ( V_100 )
return V_100 ;
F_557 ( V_2 ) ;
F_558 ( V_2 ) ;
V_565 ( V_2 ) ;
return V_100 ;
}
int F_559 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_183 V_21 ;
V_100 = V_561 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_21 . V_31 = 0x0 ;
V_21 . V_124 = V_1187 ;
V_21 . V_185 = true ;
F_126 ( V_2 , & V_21 ) ;
V_565 ( V_2 ) ;
return V_100 ;
}
void F_560 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_5 . V_6 . V_380 = 0 ;
V_100 = V_561 ( V_2 ) ;
F_313 ( V_100 ) ;
F_493 ( V_2 ) ;
V_565 ( V_2 ) ;
F_546 ( V_2 ) ;
V_56 -> V_1183 ( V_2 ) ;
}
void F_557 ( struct V_1 * V_2 )
{
F_145 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_601 = 0 ;
V_2 -> V_5 . V_600 = false ;
memset ( V_2 -> V_5 . V_158 , 0 , sizeof( V_2 -> V_5 . V_158 ) ) ;
V_2 -> V_5 . V_161 = V_163 ;
V_2 -> V_5 . V_149 = V_165 ;
F_82 ( V_2 ) ;
F_25 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_6 . V_380 = 0 ;
V_2 -> V_5 . V_384 . V_380 = 0 ;
F_186 ( V_2 ) ;
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1055 = false ;
F_561 ( V_2 ) ;
memset ( V_2 -> V_5 . V_569 , 0 , sizeof( V_2 -> V_5 . V_569 ) ) ;
V_2 -> V_5 . V_97 = ~ 0 ;
V_2 -> V_5 . V_98 = ~ 0 ;
V_56 -> V_1188 ( V_2 ) ;
}
void F_562 ( struct V_1 * V_2 , unsigned int V_32 )
{
struct V_762 V_1117 ;
F_311 ( V_2 , & V_1117 , V_920 ) ;
V_1117 . V_840 = V_32 << 8 ;
V_1117 . V_847 = V_32 << 12 ;
F_310 ( V_2 , & V_1117 , V_920 ) ;
F_407 ( V_2 , 0 ) ;
}
int F_563 ( void * V_558 )
{
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 ;
int V_89 ;
T_2 V_1189 ;
T_2 V_1190 = 0 ;
bool V_1191 , V_1192 = false ;
F_14 () ;
V_89 = V_56 -> V_1193 ( V_558 ) ;
if ( V_89 != 0 )
return V_89 ;
V_1189 = F_156 () ;
V_1191 = ! F_128 () ;
F_433 (kvm, &vm_list, vm_list) {
F_149 (i, vcpu, kvm) {
if ( ! V_1191 && V_2 -> V_23 == F_8 () )
F_150 ( V_287 , & V_2 -> V_288 ) ;
if ( V_1191 && V_2 -> V_5 . V_564 > V_1189 ) {
V_1192 = true ;
if ( V_2 -> V_5 . V_564 > V_1190 )
V_1190 = V_2 -> V_5 . V_564 ;
}
}
}
if ( V_1192 ) {
T_2 V_1194 = V_1190 - V_1189 ;
F_433 (kvm, &vm_list, vm_list) {
F_149 (i, vcpu, kvm) {
V_2 -> V_5 . V_562 += V_1194 ;
V_2 -> V_5 . V_564 = V_1189 ;
F_150 ( V_252 ,
& V_2 -> V_288 ) ;
}
V_82 -> V_5 . V_264 = 0 ;
V_82 -> V_5 . V_266 = 0 ;
}
}
return 0 ;
}
void F_564 ( void * V_558 )
{
V_56 -> V_1195 ( V_558 ) ;
F_17 ( V_558 ) ;
}
int F_565 ( void )
{
return V_56 -> V_1196 () ;
}
void F_566 ( void )
{
V_56 -> V_1197 () ;
}
void F_567 ( void * V_1198 )
{
V_56 -> V_1199 ( V_1198 ) ;
}
bool F_568 ( struct V_1 * V_2 )
{
return F_78 ( V_2 -> V_82 ) == ( V_2 -> V_5 . V_570 != NULL ) ;
}
int F_569 ( struct V_1 * V_2 )
{
struct V_355 * V_355 ;
struct V_82 * V_82 ;
int V_100 ;
F_313 ( V_2 -> V_82 == NULL ) ;
V_82 = V_2 -> V_82 ;
V_2 -> V_5 . V_1078 . V_1079 = false ;
V_2 -> V_5 . V_865 . V_791 = & V_1200 ;
if ( ! F_78 ( V_82 ) || F_538 ( V_2 ) )
V_2 -> V_5 . V_989 = V_1076 ;
else
V_2 -> V_5 . V_989 = V_1089 ;
V_355 = F_570 ( V_636 | V_1201 ) ;
if ( ! V_355 ) {
V_100 = - V_357 ;
goto V_1202;
}
V_2 -> V_5 . V_821 = F_571 ( V_355 ) ;
F_120 ( V_2 , V_957 ) ;
V_100 = F_572 ( V_2 ) ;
if ( V_100 < 0 )
goto V_1203;
if ( F_78 ( V_82 ) ) {
V_100 = F_573 ( V_2 ) ;
if ( V_100 < 0 )
goto V_1204;
} else
F_574 ( & V_1205 ) ;
V_2 -> V_5 . V_344 = F_259 ( V_428 * sizeof( T_2 ) * 4 ,
V_636 ) ;
if ( ! V_2 -> V_5 . V_344 ) {
V_100 = - V_357 ;
goto V_1206;
}
V_2 -> V_5 . V_336 = V_428 ;
if ( ! F_575 ( & V_2 -> V_5 . V_560 , V_636 ) ) {
V_100 = - V_357 ;
goto V_1207;
}
V_100 = F_543 ( V_2 ) ;
if ( V_100 )
goto V_1208;
V_2 -> V_5 . V_256 = 0x0 ;
V_2 -> V_5 . V_299 = false ;
V_2 -> V_5 . V_130 = 0 ;
V_2 -> V_5 . V_619 = V_1209 + V_620 ;
F_1 ( V_2 ) ;
F_576 ( V_2 ) ;
return 0 ;
V_1208:
F_554 ( V_2 -> V_5 . V_560 ) ;
V_1207:
F_172 ( V_2 -> V_5 . V_344 ) ;
V_1206:
F_577 ( V_2 ) ;
V_1204:
F_578 ( V_2 ) ;
V_1203:
F_579 ( ( unsigned long ) V_2 -> V_5 . V_821 ) ;
V_1202:
return V_100 ;
}
void F_580 ( struct V_1 * V_2 )
{
int V_330 ;
F_581 ( V_2 ) ;
F_172 ( V_2 -> V_5 . V_344 ) ;
F_577 ( V_2 ) ;
V_330 = F_213 ( & V_2 -> V_82 -> V_473 ) ;
F_578 ( V_2 ) ;
F_214 ( & V_2 -> V_82 -> V_473 , V_330 ) ;
F_579 ( ( unsigned long ) V_2 -> V_5 . V_821 ) ;
if ( ! F_78 ( V_2 -> V_82 ) )
F_582 ( & V_1205 ) ;
}
int F_583 ( struct V_82 * V_82 , unsigned long type )
{
if ( type )
return - V_557 ;
F_584 ( & V_82 -> V_5 . V_1210 ) ;
F_584 ( & V_82 -> V_5 . V_1211 ) ;
F_584 ( & V_82 -> V_5 . V_1212 ) ;
F_145 ( & V_82 -> V_5 . V_1213 , 0 ) ;
F_150 ( V_714 , & V_82 -> V_5 . V_1214 ) ;
F_150 ( V_1215 ,
& V_82 -> V_5 . V_1214 ) ;
F_585 ( & V_82 -> V_5 . V_262 ) ;
F_586 ( & V_82 -> V_5 . V_1216 ) ;
F_587 ( & V_82 -> V_5 . V_279 ) ;
F_144 ( V_82 ) ;
return 0 ;
}
static void F_588 ( struct V_1 * V_2 )
{
int V_100 ;
V_100 = V_561 ( V_2 ) ;
F_313 ( V_100 ) ;
F_493 ( V_2 ) ;
V_565 ( V_2 ) ;
}
static void F_589 ( struct V_82 * V_82 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_149 (i, vcpu, kvm) {
F_57 ( V_2 ) ;
F_588 ( V_2 ) ;
}
F_149 (i, vcpu, kvm)
F_553 ( V_2 ) ;
F_198 ( & V_82 -> V_443 ) ;
for ( V_3 = 0 ; V_3 < F_123 ( & V_82 -> V_249 ) ; V_3 ++ )
V_82 -> V_1217 [ V_3 ] = NULL ;
F_145 ( & V_82 -> V_249 , 0 ) ;
F_199 ( & V_82 -> V_443 ) ;
}
void F_590 ( struct V_82 * V_82 )
{
F_591 ( V_82 ) ;
F_592 ( V_82 ) ;
}
void F_593 ( struct V_82 * V_82 )
{
if ( V_386 -> V_1218 == V_82 -> V_1218 ) {
struct V_1219 V_1220 ;
memset ( & V_1220 , 0 , sizeof( V_1220 ) ) ;
V_1220 . V_10 = V_1221 ;
F_594 ( V_82 , & V_1220 ) ;
V_1220 . V_10 = V_1222 ;
F_594 ( V_82 , & V_1220 ) ;
V_1220 . V_10 = V_1223 ;
F_594 ( V_82 , & V_1220 ) ;
}
F_595 ( V_82 ) ;
F_172 ( V_82 -> V_5 . V_726 ) ;
F_172 ( V_82 -> V_5 . V_1224 ) ;
F_589 ( V_82 ) ;
if ( V_82 -> V_5 . V_1225 )
F_596 ( V_82 -> V_5 . V_1225 ) ;
if ( V_82 -> V_5 . V_1226 )
F_596 ( V_82 -> V_5 . V_1226 ) ;
F_172 ( F_597 ( V_82 -> V_5 . V_1227 , 1 ) ) ;
}
void F_598 ( struct V_82 * V_82 , struct V_702 * free ,
struct V_702 * V_1228 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1229 ; ++ V_3 ) {
if ( ! V_1228 || free -> V_5 . V_1230 [ V_3 ] != V_1228 -> V_5 . V_1230 [ V_3 ] ) {
F_599 ( free -> V_5 . V_1230 [ V_3 ] ) ;
free -> V_5 . V_1230 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1228 || free -> V_5 . V_1231 [ V_3 - 1 ] !=
V_1228 -> V_5 . V_1231 [ V_3 - 1 ] ) {
F_599 ( free -> V_5 . V_1231 [ V_3 - 1 ] ) ;
free -> V_5 . V_1231 [ V_3 - 1 ] = NULL ;
}
}
}
int F_600 ( struct V_82 * V_82 , struct V_702 * V_10 ,
unsigned long V_1232 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1229 ; ++ V_3 ) {
unsigned long V_1233 ;
int V_1234 ;
int V_715 = V_3 + 1 ;
V_1234 = F_601 ( V_10 -> V_1235 + V_1232 - 1 ,
V_10 -> V_1235 , V_715 ) + 1 ;
V_10 -> V_5 . V_1230 [ V_3 ] =
F_602 ( V_1234 * sizeof( * V_10 -> V_5 . V_1230 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1230 [ V_3 ] )
goto V_358;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1231 [ V_3 - 1 ] = F_602 ( V_1234 *
sizeof( * V_10 -> V_5 . V_1231 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1231 [ V_3 - 1 ] )
goto V_358;
if ( V_10 -> V_1235 & ( F_603 ( V_715 ) - 1 ) )
V_10 -> V_5 . V_1231 [ V_3 - 1 ] [ 0 ] . V_1236 = 1 ;
if ( ( V_10 -> V_1235 + V_1232 ) & ( F_603 ( V_715 ) - 1 ) )
V_10 -> V_5 . V_1231 [ V_3 - 1 ] [ V_1234 - 1 ] . V_1236 = 1 ;
V_1233 = V_10 -> V_1237 >> V_87 ;
if ( ( V_10 -> V_1235 ^ V_1233 ) & ( F_603 ( V_715 ) - 1 ) ||
! F_604 () ) {
unsigned long V_756 ;
for ( V_756 = 0 ; V_756 < V_1234 ; ++ V_756 )
V_10 -> V_5 . V_1231 [ V_3 - 1 ] [ V_756 ] . V_1236 = 1 ;
}
}
return 0 ;
V_358:
for ( V_3 = 0 ; V_3 < V_1229 ; ++ V_3 ) {
F_599 ( V_10 -> V_5 . V_1230 [ V_3 ] ) ;
V_10 -> V_5 . V_1230 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_599 ( V_10 -> V_5 . V_1231 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1231 [ V_3 - 1 ] = NULL ;
}
return - V_357 ;
}
void F_605 ( struct V_82 * V_82 )
{
F_606 ( V_82 ) ;
}
int F_607 ( struct V_82 * V_82 ,
struct V_702 * V_703 ,
struct V_1219 * V_1220 ,
enum V_1238 V_1239 )
{
if ( ( V_703 -> V_1184 >= V_525 ) && ( V_1239 == V_1240 ) ) {
unsigned long V_1237 ;
V_1237 = F_608 ( NULL , 0 , V_703 -> V_1232 * V_88 ,
V_1241 | V_1242 ,
V_1243 | V_1244 , 0 ) ;
if ( F_170 ( ( void * ) V_1237 ) )
return F_171 ( ( void * ) V_1237 ) ;
V_703 -> V_1237 = V_1237 ;
}
return 0 ;
}
void F_609 ( struct V_82 * V_82 ,
struct V_1219 * V_1220 ,
const struct V_702 * V_809 ,
enum V_1238 V_1239 )
{
int V_1245 = 0 ;
if ( ( V_1220 -> V_10 >= V_525 ) && ( V_1239 == V_1246 ) ) {
int V_89 ;
V_89 = F_610 ( V_809 -> V_1237 ,
V_809 -> V_1232 * V_88 ) ;
if ( V_89 < 0 )
F_10 ( V_816
L_32
L_33 ) ;
}
if ( ! V_82 -> V_5 . V_675 )
V_1245 = F_611 ( V_82 ) ;
if ( V_1245 )
F_268 ( V_82 , V_1245 ) ;
if ( ( V_1239 != V_1246 ) && ( V_1220 -> V_259 & V_1247 ) )
F_612 ( V_82 , V_1220 -> V_10 ) ;
}
void F_613 ( struct V_82 * V_82 )
{
F_614 ( V_82 ) ;
}
void F_615 ( struct V_82 * V_82 ,
struct V_702 * V_10 )
{
F_614 ( V_82 ) ;
}
int F_616 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_989 == V_1076 &&
! V_2 -> V_5 . V_6 . V_1055 )
|| ! F_617 ( & V_2 -> V_1248 . V_1249 )
|| F_618 ( V_2 )
|| V_2 -> V_5 . V_1078 . V_1079
|| F_123 ( & V_2 -> V_5 . V_68 ) ||
( F_478 ( V_2 ) &&
F_477 ( V_2 ) ) ;
}
int F_619 ( struct V_1 * V_2 )
{
return F_620 ( V_2 ) == V_1065 ;
}
int F_478 ( struct V_1 * V_2 )
{
return V_56 -> V_1037 ( V_2 ) ;
}
bool F_621 ( struct V_1 * V_2 , unsigned long V_1250 )
{
unsigned long V_1251 = F_402 ( V_2 ) +
F_356 ( V_2 , V_920 ) ;
return V_1251 == V_1250 ;
}
unsigned long F_401 ( struct V_1 * V_2 )
{
unsigned long V_909 ;
V_909 = V_56 -> V_910 ( V_2 ) ;
if ( V_2 -> V_150 & V_912 )
V_909 &= ~ V_911 ;
return V_909 ;
}
void F_372 ( struct V_1 * V_2 , unsigned long V_909 )
{
if ( V_2 -> V_150 & V_912 &&
F_621 ( V_2 , V_2 -> V_5 . V_916 ) )
V_909 |= V_911 ;
V_56 -> V_1252 ( V_2 , V_909 ) ;
F_25 ( V_48 , V_2 ) ;
}
void F_622 ( struct V_1 * V_2 , struct V_1253 * V_972 )
{
int V_100 ;
if ( ( V_2 -> V_5 . V_67 . V_901 != V_972 -> V_5 . V_901 ) ||
V_972 -> V_1254 )
return;
V_100 = F_500 ( V_2 ) ;
if ( F_140 ( V_100 ) )
return;
if ( ! V_2 -> V_5 . V_67 . V_901 &&
V_972 -> V_5 . V_85 != V_2 -> V_5 . V_67 . V_1255 ( V_2 ) )
return;
V_2 -> V_5 . V_67 . V_1256 ( V_2 , V_972 -> V_769 , 0 , true ) ;
}
static inline T_1 F_623 ( T_4 V_83 )
{
return F_624 ( V_83 & 0xffffffff , F_625 ( V_4 ) ) ;
}
static inline T_1 F_626 ( T_1 V_1257 )
{
return ( V_1257 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_627 ( struct V_1 * V_2 , T_4 V_83 )
{
T_1 V_1257 = F_623 ( V_83 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1257 ] != ~ 0 )
V_1257 = F_626 ( V_1257 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1257 ] = V_83 ;
}
static T_1 F_628 ( struct V_1 * V_2 , T_4 V_83 )
{
int V_3 ;
T_1 V_1257 = F_623 ( V_83 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1257 ] != V_83 &&
V_2 -> V_5 . V_6 . V_7 [ V_1257 ] != ~ 0 ) ; V_3 ++ )
V_1257 = F_626 ( V_1257 ) ;
return V_1257 ;
}
bool F_629 ( struct V_1 * V_2 , T_4 V_83 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_628 ( V_2 , V_83 ) ] == V_83 ;
}
static void F_630 ( struct V_1 * V_2 , T_4 V_83 )
{
T_1 V_3 , V_756 , V_1258 ;
V_3 = V_756 = F_628 ( V_2 , V_83 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_756 = F_626 ( V_756 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_756 ] == ~ 0 )
return;
V_1258 = F_623 ( V_2 -> V_5 . V_6 . V_7 [ V_756 ] ) ;
} while ( ( V_3 <= V_756 ) ? ( V_3 < V_1258 && V_1258 <= V_756 ) : ( V_3 < V_1258 || V_1258 <= V_756 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_756 ] ;
V_3 = V_756 ;
}
}
static int F_631 ( struct V_1 * V_2 , T_1 V_157 )
{
return F_159 ( V_2 -> V_82 , & V_2 -> V_5 . V_6 . V_31 , & V_157 ,
sizeof( V_157 ) ) ;
}
void F_632 ( struct V_1 * V_2 ,
struct V_1253 * V_972 )
{
struct V_58 V_59 ;
F_633 ( V_972 -> V_5 . V_1259 , V_972 -> V_769 ) ;
F_627 ( V_2 , V_972 -> V_5 . V_83 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_380 & V_381 ) ||
( V_2 -> V_5 . V_6 . V_382 &&
V_56 -> V_71 ( V_2 ) == 0 ) )
F_25 ( V_1054 , V_2 ) ;
else if ( ! F_631 ( V_2 , V_1260 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_866 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_972 -> V_5 . V_1259 ;
F_30 ( V_2 , & V_59 ) ;
}
}
void F_634 ( struct V_1 * V_2 ,
struct V_1253 * V_972 )
{
struct V_58 V_59 ;
F_635 ( V_972 -> V_5 . V_1259 , V_972 -> V_769 ) ;
if ( V_972 -> V_1254 )
V_972 -> V_5 . V_1259 = ~ 0 ;
else
F_630 ( V_2 , V_972 -> V_5 . V_83 ) ;
if ( ( V_2 -> V_5 . V_6 . V_380 & V_381 ) &&
! F_631 ( V_2 , V_1261 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_866 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_972 -> V_5 . V_1259 ;
F_30 ( V_2 , & V_59 ) ;
}
V_2 -> V_5 . V_6 . V_1055 = false ;
V_2 -> V_5 . V_989 = V_1076 ;
}
bool F_636 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_380 & V_381 ) )
return true ;
else
return ! F_480 ( V_2 ) &&
V_56 -> V_1037 ( V_2 ) ;
}
void F_637 ( struct V_82 * V_82 )
{
F_35 ( & V_82 -> V_5 . V_1213 ) ;
}
void F_638 ( struct V_82 * V_82 )
{
F_639 ( & V_82 -> V_5 . V_1213 ) ;
}
bool F_227 ( struct V_82 * V_82 )
{
return F_123 ( & V_82 -> V_5 . V_1213 ) ;
}
