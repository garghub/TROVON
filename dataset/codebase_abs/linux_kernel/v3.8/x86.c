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
V_2 -> V_5 . V_67 . V_181 . V_182 = ( V_111 & V_183 ) && ! V_184 ;
if ( ( V_111 ^ V_171 ) & V_183 )
F_56 ( V_2 ) ;
return 0 ;
}
void F_90 ( T_2 V_27 )
{
V_172 &= ~ V_27 ;
}
int F_91 ( struct V_1 * V_2 , struct V_185 * V_21 )
{
return V_56 -> V_186 ( V_2 , V_21 ) ;
}
static int F_92 ( struct V_1 * V_2 , unsigned V_119 , T_2 * V_31 )
{
struct V_185 V_21 ;
V_21 . V_31 = * V_31 ;
V_21 . V_119 = V_119 ;
V_21 . V_187 = true ;
return F_91 ( V_2 , & V_21 ) ;
}
static void F_93 ( struct V_188 * V_189 )
{
struct V_190 * V_191 = & V_190 ;
F_94 ( & V_191 -> V_192 ) ;
V_191 -> clock . V_193 = V_189 -> clock -> V_194 . V_193 ;
V_191 -> clock . V_195 = V_189 -> clock -> V_195 ;
V_191 -> clock . V_27 = V_189 -> clock -> V_27 ;
V_191 -> clock . V_196 = V_189 -> V_196 ;
V_191 -> clock . V_197 = V_189 -> V_197 ;
V_191 -> V_198 = V_189 -> V_199
+ V_189 -> V_200 . V_201 ;
V_191 -> V_202 = V_189 -> V_203
+ ( V_189 -> V_200 . V_204
<< V_189 -> V_197 ) ;
while ( V_191 -> V_202 >=
( ( ( T_2 ) V_205 ) << V_189 -> V_197 ) ) {
V_191 -> V_202 -=
( ( T_2 ) V_205 ) << V_189 -> V_197 ;
V_191 -> V_198 ++ ;
}
F_95 ( & V_191 -> V_192 ) ;
}
static void F_96 ( struct V_82 * V_82 , T_4 V_206 )
{
int V_207 ;
int V_100 ;
struct V_208 V_209 ;
struct V_210 V_211 ;
if ( ! V_206 )
return;
V_100 = F_97 ( V_82 , V_206 , & V_207 , sizeof( V_207 ) ) ;
if ( V_100 )
return;
if ( V_207 & 1 )
++ V_207 ;
++ V_207 ;
F_98 ( V_82 , V_206 , & V_207 , sizeof( V_207 ) ) ;
F_99 ( & V_211 ) ;
if ( V_82 -> V_5 . V_212 ) {
struct V_210 V_213 = F_100 ( V_82 -> V_5 . V_212 ) ;
V_211 = F_101 ( V_211 , V_213 ) ;
}
V_209 . V_214 = V_211 . V_201 ;
V_209 . V_215 = V_211 . V_204 ;
V_209 . V_207 = V_207 ;
F_98 ( V_82 , V_206 , & V_209 , sizeof( V_209 ) ) ;
V_207 ++ ;
F_98 ( V_82 , V_206 , & V_207 , sizeof( V_207 ) ) ;
}
static T_5 F_102 ( T_5 V_216 , T_5 V_217 )
{
T_5 V_218 , V_219 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_218 ;
}
static void F_103 ( T_5 V_220 , T_5 V_221 ,
T_6 * V_222 , T_1 * V_223 )
{
T_7 V_224 ;
T_8 V_197 = 0 ;
T_7 V_225 ;
T_5 V_226 ;
V_225 = V_221 * 1000LL ;
V_224 = V_220 * 1000LL ;
while ( V_225 > V_224 * 2 || V_225 & 0xffffffff00000000ULL ) {
V_225 >>= 1 ;
V_197 -- ;
}
V_226 = ( T_5 ) V_225 ;
while ( V_226 <= V_224 || V_224 & 0xffffffff00000000ULL ) {
if ( V_224 & 0xffffffff00000000ULL || V_226 & 0x80000000 )
V_224 >>= 1 ;
else
V_226 <<= 1 ;
V_197 ++ ;
}
* V_222 = V_197 ;
* V_223 = F_102 ( V_224 , V_226 ) ;
F_104 ( L_2 ,
V_227 , V_221 , V_220 , V_197 , * V_223 ) ;
}
static inline T_2 F_105 ( void )
{
struct V_210 V_213 ;
F_106 ( F_107 () ) ;
F_108 ( & V_213 ) ;
F_109 ( & V_213 ) ;
return F_110 ( & V_213 ) ;
}
static inline T_2 F_111 ( struct V_1 * V_2 , T_2 V_215 )
{
return F_112 ( V_215 , V_2 -> V_5 . V_228 ,
V_2 -> V_5 . V_229 ) ;
}
static T_1 F_113 ( T_1 V_230 , T_9 V_231 )
{
T_2 V_232 = ( T_2 ) V_230 * ( 1000000 + V_231 ) ;
F_114 ( V_232 , 1000000 ) ;
return V_232 ;
}
static void F_115 ( struct V_1 * V_2 , T_1 V_233 )
{
T_1 V_234 , V_235 ;
int V_236 = 0 ;
F_103 ( V_233 , V_205 / 1000 ,
& V_2 -> V_5 . V_229 ,
& V_2 -> V_5 . V_228 ) ;
V_2 -> V_5 . V_237 = V_233 ;
V_234 = F_113 ( V_238 , - V_239 ) ;
V_235 = F_113 ( V_238 , V_239 ) ;
if ( V_233 < V_234 || V_233 > V_235 ) {
F_104 ( L_3 , V_233 , V_234 , V_235 ) ;
V_236 = 1 ;
}
V_56 -> V_240 ( V_2 , V_233 , V_236 ) ;
}
static T_2 F_116 ( struct V_1 * V_2 , T_10 V_241 )
{
T_2 V_242 = F_112 ( V_241 - V_2 -> V_5 . V_243 ,
V_2 -> V_5 . V_228 ,
V_2 -> V_5 . V_229 ) ;
V_242 += V_2 -> V_5 . V_244 ;
return V_242 ;
}
void F_117 ( struct V_1 * V_2 )
{
#ifdef F_52
bool V_245 ;
bool V_246 = false ;
struct V_247 * V_248 = & V_2 -> V_82 -> V_5 ;
struct V_190 * V_249 = & V_190 ;
V_245 = ( V_248 -> V_250 + 1 ==
F_118 ( & V_2 -> V_82 -> V_251 ) ) ;
if ( V_245 && V_249 -> clock . V_193 == V_252 )
if ( ! V_248 -> V_253 )
V_246 = 1 ;
if ( ! V_245 && V_248 -> V_253 )
V_246 = 1 ;
if ( V_246 )
F_23 ( V_254 , V_2 ) ;
F_119 ( V_2 -> V_255 , V_248 -> V_250 ,
F_118 ( & V_2 -> V_82 -> V_251 ) ,
V_248 -> V_253 , V_249 -> clock . V_193 ) ;
#endif
}
static void F_120 ( struct V_1 * V_2 , T_10 V_74 )
{
T_2 V_256 = V_56 -> V_257 ( V_2 ) ;
V_2 -> V_5 . V_258 += V_74 - V_256 ;
}
void F_121 ( struct V_1 * V_2 , struct V_185 * V_21 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
T_2 V_74 , V_259 , V_260 ;
unsigned long V_261 ;
T_10 V_262 ;
bool V_263 ;
T_2 V_31 = V_21 -> V_31 ;
F_122 ( & V_82 -> V_5 . V_264 , V_261 ) ;
V_74 = V_56 -> V_265 ( V_2 , V_31 ) ;
V_259 = F_105 () ;
V_260 = V_259 - V_82 -> V_5 . V_266 ;
V_262 = V_31 - V_82 -> V_5 . V_267 ;
#ifdef F_52
V_262 = ( V_262 * 1000 ) / V_2 -> V_5 . V_237 ;
#else
asm("idivl %2; xor %%edx, %%edx"
: "=A"(usdiff)
: "A"(usdiff * 1000), "rm"(vcpu->arch.virtual_tsc_khz));
#endif
F_114 ( V_260 , 1000 ) ;
V_262 -= V_260 ;
if ( V_262 < 0 )
V_262 = - V_262 ;
if ( V_262 < V_268 &&
V_2 -> V_5 . V_237 == V_82 -> V_5 . V_269 ) {
if ( ! F_123 () ) {
V_74 = V_82 -> V_5 . V_270 ;
F_104 ( L_4 , V_31 ) ;
} else {
T_2 V_271 = F_111 ( V_2 , V_260 ) ;
V_31 += V_271 ;
V_74 = V_56 -> V_265 ( V_2 , V_31 ) ;
F_104 ( L_5 , V_271 ) ;
}
V_263 = true ;
} else {
V_82 -> V_5 . V_272 ++ ;
V_82 -> V_5 . V_273 = V_259 ;
V_82 -> V_5 . V_274 = V_31 ;
V_82 -> V_5 . V_270 = V_74 ;
V_263 = false ;
F_104 ( L_6 ,
V_82 -> V_5 . V_272 , V_31 ) ;
}
V_82 -> V_5 . V_266 = V_259 ;
V_82 -> V_5 . V_267 = V_31 ;
V_82 -> V_5 . V_269 = V_2 -> V_5 . V_237 ;
V_2 -> V_5 . V_275 . V_276 = 0 ;
V_2 -> V_5 . V_277 = V_31 ;
V_2 -> V_5 . V_278 = V_82 -> V_5 . V_272 ;
V_2 -> V_5 . V_243 = V_82 -> V_5 . V_273 ;
V_2 -> V_5 . V_244 = V_82 -> V_5 . V_274 ;
if ( F_124 ( V_2 ) && ! V_21 -> V_187 )
F_120 ( V_2 , V_74 ) ;
V_56 -> V_279 ( V_2 , V_74 ) ;
F_125 ( & V_82 -> V_5 . V_264 , V_261 ) ;
F_126 ( & V_82 -> V_5 . V_280 ) ;
if ( V_263 )
V_82 -> V_5 . V_250 ++ ;
else
V_82 -> V_5 . V_250 = 0 ;
F_117 ( V_2 ) ;
F_127 ( & V_82 -> V_5 . V_280 ) ;
}
static T_11 F_128 ( void )
{
T_11 V_89 ;
T_2 V_281 ;
F_129 () ;
V_89 = ( T_11 ) F_130 () ;
V_281 = V_190 . clock . V_195 ;
if ( F_131 ( V_89 >= V_281 ) )
return V_89 ;
asm volatile ("");
return V_281 ;
}
static inline T_2 F_132 ( T_11 * V_282 )
{
long V_232 ;
struct V_190 * V_249 = & V_190 ;
* V_282 = F_128 () ;
V_232 = ( * V_282 - V_249 -> clock . V_195 ) & V_249 -> clock . V_27 ;
return V_232 * V_249 -> clock . V_196 ;
}
static int F_133 ( struct V_210 * V_213 , T_11 * V_282 )
{
unsigned long V_192 ;
T_2 V_259 ;
int V_283 ;
struct V_190 * V_249 = & V_190 ;
V_213 -> V_204 = 0 ;
do {
V_192 = F_134 ( & V_249 -> V_192 ) ;
V_283 = V_249 -> clock . V_193 ;
V_213 -> V_201 = V_249 -> V_198 ;
V_259 = V_249 -> V_202 ;
V_259 += F_132 ( V_282 ) ;
V_259 >>= V_249 -> clock . V_197 ;
} while ( F_71 ( F_135 ( & V_249 -> V_192 , V_192 ) ) );
F_136 ( V_213 , V_259 ) ;
return V_283 ;
}
static bool F_137 ( T_10 * V_241 , T_11 * V_282 )
{
struct V_210 V_213 ;
if ( V_190 . clock . V_193 != V_252 )
return false ;
if ( F_133 ( & V_213 , V_282 ) != V_252 )
return false ;
F_109 ( & V_213 ) ;
* V_241 = F_110 ( & V_213 ) ;
return true ;
}
static void F_138 ( struct V_82 * V_82 )
{
#ifdef F_52
struct V_247 * V_248 = & V_82 -> V_5 ;
int V_193 ;
bool V_284 , V_245 ;
V_245 = ( V_248 -> V_250 + 1 ==
F_118 ( & V_82 -> V_251 ) ) ;
V_284 = F_137 (
& V_248 -> V_285 ,
& V_248 -> V_286 ) ;
V_248 -> V_253 = V_284 & V_245 ;
if ( V_248 -> V_253 )
F_139 ( & V_287 , 1 ) ;
V_193 = V_190 . clock . V_193 ;
F_140 ( V_248 -> V_253 , V_193 ,
V_245 ) ;
#endif
}
static int F_141 ( struct V_1 * V_232 )
{
unsigned long V_261 , V_233 ;
struct V_288 * V_2 = & V_232 -> V_5 ;
struct V_247 * V_248 = & V_232 -> V_82 -> V_5 ;
void * V_289 ;
T_10 V_241 , V_290 ;
T_2 V_276 , V_291 ;
struct V_292 * V_293 ;
T_12 V_294 ;
bool V_253 ;
V_241 = 0 ;
V_291 = 0 ;
F_142 ( V_261 ) ;
V_233 = F_143 ( V_295 ) ;
if ( F_71 ( V_233 == 0 ) ) {
F_144 ( V_261 ) ;
F_23 ( V_296 , V_232 ) ;
return 1 ;
}
F_126 ( & V_248 -> V_280 ) ;
V_253 = V_248 -> V_253 ;
if ( V_253 ) {
V_291 = V_248 -> V_286 ;
V_241 = V_248 -> V_285 ;
}
F_127 ( & V_248 -> V_280 ) ;
if ( ! V_253 ) {
V_291 = F_145 () ;
V_241 = F_105 () ;
}
V_276 = V_56 -> V_297 ( V_232 , V_291 ) ;
if ( V_2 -> V_298 ) {
T_2 V_242 = F_116 ( V_232 , V_241 ) ;
if ( V_242 > V_276 ) {
F_146 ( V_232 , V_242 - V_276 ) ;
V_276 = V_242 ;
}
}
F_144 ( V_261 ) ;
if ( ! V_2 -> V_299 )
return 0 ;
V_290 = 0 ;
if ( V_2 -> V_275 . V_276 ) {
V_290 = V_2 -> V_277 -
V_2 -> V_275 . V_276 ;
V_290 = F_112 ( V_290 ,
V_2 -> V_275 . V_300 ,
V_2 -> V_275 . V_301 ) ;
V_290 += V_2 -> V_302 ;
}
if ( F_71 ( V_2 -> V_303 != V_233 ) ) {
F_103 ( V_205 / 1000 , V_233 ,
& V_2 -> V_275 . V_301 ,
& V_2 -> V_275 . V_300 ) ;
V_2 -> V_303 = V_233 ;
}
if ( ! V_253 ) {
if ( V_290 > V_241 )
V_241 = V_290 ;
}
V_2 -> V_275 . V_276 = V_276 ;
V_2 -> V_275 . V_304 = V_241 + V_232 -> V_82 -> V_5 . V_212 ;
V_2 -> V_302 = V_241 ;
V_2 -> V_277 = V_276 ;
V_2 -> V_275 . V_207 += 2 ;
V_289 = F_147 ( V_2 -> V_299 ) ;
V_293 = V_289 + V_2 -> V_305 ;
V_294 = ( V_293 -> V_261 & V_306 ) ;
if ( V_2 -> V_307 ) {
V_294 |= V_306 ;
V_2 -> V_307 = false ;
}
if ( V_253 )
V_294 |= V_308 ;
V_2 -> V_275 . V_261 = V_294 ;
memcpy ( V_289 + V_2 -> V_305 , & V_2 -> V_275 ,
sizeof( V_2 -> V_275 ) ) ;
F_148 ( V_289 ) ;
F_149 ( V_232 -> V_82 , V_2 -> time >> V_87 ) ;
return 0 ;
}
static bool F_150 ( unsigned V_21 )
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
static bool F_151 ( unsigned V_323 )
{
return V_323 < 8 && ( 1 << V_323 ) & 0xf3 ;
}
static bool F_152 ( unsigned V_323 )
{
return V_323 < 8 && ( 1 << V_323 ) & 0x73 ;
}
static bool F_153 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
int V_3 ;
if ( ! F_150 ( V_21 ) )
return false ;
if ( V_21 == V_322 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_151 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_321 ) {
if ( V_31 & ~ 0xcff )
return false ;
return F_152 ( V_31 & 0xff ) ;
} else if ( V_21 >= V_310 && V_21 <= V_320 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_152 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_152 ( V_31 & 0xff ) ;
}
static int F_154 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 * V_324 = ( T_2 * ) & V_2 -> V_5 . V_325 . V_326 ;
if ( ! F_153 ( V_2 , V_21 , V_31 ) )
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
F_56 ( V_2 ) ;
return 0 ;
}
static int F_155 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
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
static int F_156 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
int V_345 = F_46 ( V_2 ) ;
T_12 * V_346 = V_345 ? ( T_12 * ) ( long ) V_82 -> V_5 . F_156 . V_347
: ( T_12 * ) ( long ) V_82 -> V_5 . F_156 . V_348 ;
T_12 V_349 = V_345 ? V_82 -> V_5 . F_156 . V_350
: V_82 -> V_5 . F_156 . V_351 ;
T_1 V_352 = V_31 & ~ V_353 ;
T_2 V_354 = V_31 & V_353 ;
T_12 * V_355 ;
int V_100 ;
V_100 = - V_356 ;
if ( V_352 >= V_349 )
goto V_94;
V_100 = - V_357 ;
V_355 = F_157 ( V_346 + ( V_352 * V_88 ) , V_88 ) ;
if ( F_158 ( V_355 ) ) {
V_100 = F_159 ( V_355 ) ;
goto V_94;
}
if ( F_98 ( V_82 , V_354 , V_355 , V_88 ) )
goto V_358;
V_100 = 0 ;
V_358:
F_160 ( V_355 ) ;
V_94:
return V_100 ;
}
static bool F_161 ( struct V_82 * V_82 )
{
return V_82 -> V_5 . V_359 & V_360 ;
}
static bool F_162 ( T_1 V_21 )
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
static int F_163 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
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
T_12 V_365 [ 4 ] ;
if ( ! V_82 -> V_5 . V_363 )
break;
if ( ! ( V_31 & V_360 ) ) {
V_82 -> V_5 . V_359 = V_31 ;
break;
}
V_83 = V_31 >> V_366 ;
V_364 = F_164 ( V_82 , V_83 ) ;
if ( F_165 ( V_364 ) )
return 1 ;
V_56 -> V_367 ( V_2 , V_365 ) ;
( ( unsigned char * ) V_365 ) [ 3 ] = 0xc3 ;
if ( F_166 ( ( void V_368 * ) V_364 , V_365 , 4 ) )
return 1 ;
V_82 -> V_5 . V_359 = V_31 ;
break;
}
default:
F_167 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_168 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_369 : {
unsigned long V_364 ;
if ( ! ( V_31 & V_370 ) ) {
V_2 -> V_5 . V_371 = V_31 ;
break;
}
V_364 = F_164 ( V_2 -> V_82 , V_31 >>
V_372 ) ;
if ( F_165 ( V_364 ) )
return 1 ;
if ( F_169 ( ( void V_368 * ) V_364 , V_88 ) )
return 1 ;
V_2 -> V_5 . V_371 = V_31 ;
break;
}
case V_373 :
return F_170 ( V_2 , V_374 , V_31 ) ;
case V_375 :
return F_170 ( V_2 , V_376 , V_31 ) ;
case V_377 :
return F_170 ( V_2 , V_378 , V_31 ) ;
default:
F_167 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_171 ( struct V_1 * V_2 , T_2 V_31 )
{
T_4 V_379 = V_31 & ~ 0x3f ;
if ( V_31 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_380 = V_31 ;
if ( ! ( V_31 & V_381 ) ) {
F_55 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_172 ( V_2 -> V_82 , & V_2 -> V_5 . V_6 . V_31 , V_379 ) )
return 1 ;
V_2 -> V_5 . V_6 . V_382 = ! ( V_31 & V_383 ) ;
F_173 ( V_2 ) ;
return 0 ;
}
static void F_174 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_299 ) {
F_175 ( V_2 -> V_5 . V_299 ) ;
V_2 -> V_5 . V_299 = NULL ;
}
}
static void F_176 ( struct V_1 * V_2 )
{
T_2 V_271 ;
if ( ! ( V_2 -> V_5 . V_384 . V_380 & V_385 ) )
return;
V_271 = V_386 -> V_387 . V_388 - V_2 -> V_5 . V_384 . V_389 ;
V_2 -> V_5 . V_384 . V_389 = V_386 -> V_387 . V_388 ;
V_2 -> V_5 . V_384 . V_390 = V_271 ;
}
static void F_177 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_384 . V_380 & V_385 ) )
return;
if ( F_71 ( F_178 ( V_2 -> V_82 , & V_2 -> V_5 . V_384 . V_391 ,
& V_2 -> V_5 . V_384 . V_392 , sizeof( struct V_393 ) ) ) )
return;
V_2 -> V_5 . V_384 . V_392 . V_392 += V_2 -> V_5 . V_384 . V_390 ;
V_2 -> V_5 . V_384 . V_392 . V_207 += 2 ;
V_2 -> V_5 . V_384 . V_390 = 0 ;
F_179 ( V_2 -> V_82 , & V_2 -> V_5 . V_384 . V_391 ,
& V_2 -> V_5 . V_384 . V_392 , sizeof( struct V_393 ) ) ;
}
int F_180 ( struct V_1 * V_2 , struct V_185 * V_394 )
{
bool V_395 = false ;
T_1 V_21 = V_394 -> V_119 ;
T_2 V_31 = V_394 -> V_31 ;
switch ( V_21 ) {
case V_396 :
return F_87 ( V_2 , V_31 ) ;
case V_397 :
V_31 &= ~ ( T_2 ) 0x40 ;
V_31 &= ~ ( T_2 ) 0x100 ;
V_31 &= ~ ( T_2 ) 0x8 ;
if ( V_31 != 0 ) {
F_167 ( V_2 , L_9 ,
V_31 ) ;
return 1 ;
}
break;
case V_398 :
if ( V_31 != 0 ) {
F_167 ( V_2 , L_10
L_11 , V_31 ) ;
return 1 ;
}
break;
case V_399 :
break;
case V_400 :
if ( ! V_31 ) {
break;
} else if ( V_31 & ~ ( V_401 | V_402 ) ) {
return 1 ;
}
F_167 ( V_2 , L_12 ,
V_227 , V_31 ) ;
break;
case V_403 :
case V_404 :
case V_405 :
case V_406 :
break;
case 0x200 ... 0x2ff :
return F_154 ( V_2 , V_21 , V_31 ) ;
case V_407 :
F_19 ( V_2 , V_31 ) ;
break;
case V_408 ... V_408 + 0x3ff :
return F_181 ( V_2 , V_21 , V_31 ) ;
case V_409 :
F_182 ( V_2 , V_31 ) ;
break;
case V_410 :
if ( F_124 ( V_2 ) ) {
if ( ! V_394 -> V_187 ) {
T_2 V_411 = V_31 - V_2 -> V_5 . V_258 ;
V_56 -> V_412 ( V_2 , V_411 , true ) ;
}
V_2 -> V_5 . V_258 = V_31 ;
}
break;
case V_413 :
V_2 -> V_5 . V_414 = V_31 ;
break;
case V_415 :
case V_416 :
V_2 -> V_82 -> V_5 . V_206 = V_31 ;
F_96 ( V_2 -> V_82 , V_31 ) ;
break;
case V_417 :
case V_418 : {
F_174 ( V_2 ) ;
V_2 -> V_5 . time = V_31 ;
F_23 ( V_296 , V_2 ) ;
if ( ! ( V_31 & 1 ) )
break;
V_2 -> V_5 . V_305 = V_31 & ~ ( V_353 | 1 ) ;
V_2 -> V_5 . V_299 =
F_183 ( V_2 -> V_82 , V_31 >> V_87 ) ;
if ( F_184 ( V_2 -> V_5 . V_299 ) )
V_2 -> V_5 . V_299 = NULL ;
break;
}
case V_419 :
if ( F_171 ( V_2 , V_31 ) )
return 1 ;
break;
case V_420 :
if ( F_71 ( ! F_185 () ) )
return 1 ;
if ( V_31 & V_421 )
return 1 ;
if ( F_172 ( V_2 -> V_82 , & V_2 -> V_5 . V_384 . V_391 ,
V_31 & V_422 ) )
return 1 ;
V_2 -> V_5 . V_384 . V_380 = V_31 ;
if ( ! ( V_31 & V_385 ) )
break;
V_2 -> V_5 . V_384 . V_389 = V_386 -> V_387 . V_388 ;
F_186 () ;
F_176 ( V_2 ) ;
F_187 () ;
F_23 ( V_423 , V_2 ) ;
break;
case V_424 :
if ( F_188 ( V_2 , V_31 ) )
return 1 ;
break;
case V_340 :
case V_338 :
case V_343 ... V_343 + 4 * V_425 - 1 :
return F_155 ( V_2 , V_21 , V_31 ) ;
case V_426 :
case V_427 :
case V_428 :
case V_429 :
if ( V_31 != 0 )
F_167 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_430 :
case V_431 :
case V_432 :
case V_433 :
F_167 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_434 :
case V_435 :
V_395 = true ;
case V_436 :
case V_437 :
if ( F_189 ( V_2 , V_21 ) )
return F_190 ( V_2 , V_21 , V_31 ) ;
if ( V_395 || V_31 != 0 )
F_167 ( V_2 , L_15
L_14 , V_21 , V_31 ) ;
break;
case V_438 :
break;
case V_361 ... V_439 :
if ( F_162 ( V_21 ) ) {
int V_100 ;
F_191 ( & V_2 -> V_82 -> V_440 ) ;
V_100 = F_163 ( V_2 , V_21 , V_31 ) ;
F_192 ( & V_2 -> V_82 -> V_440 ) ;
return V_100 ;
} else
return F_168 ( V_2 , V_21 , V_31 ) ;
break;
case V_441 :
F_167 ( V_2 , L_16 , V_21 , V_31 ) ;
break;
case V_442 :
if ( ! F_193 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_443 . V_444 = V_31 ;
break;
case V_445 :
if ( ! F_193 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_443 . V_446 = V_31 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_82 -> V_5 . F_156 . V_21 ) )
return F_156 ( V_2 , V_31 ) ;
if ( F_189 ( V_2 , V_21 ) )
return F_190 ( V_2 , V_21 , V_31 ) ;
if ( ! V_447 ) {
F_167 ( V_2 , L_17 ,
V_21 , V_31 ) ;
return 1 ;
} else {
F_167 ( V_2 , L_16 ,
V_21 , V_31 ) ;
break;
}
}
return 0 ;
}
int F_194 ( struct V_1 * V_2 , T_1 V_448 , T_2 * V_449 )
{
return V_56 -> V_450 ( V_2 , V_448 , V_449 ) ;
}
static int F_195 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_449 )
{
T_2 * V_324 = ( T_2 * ) & V_2 -> V_5 . V_325 . V_326 ;
if ( ! F_150 ( V_21 ) )
return 1 ;
if ( V_21 == V_321 )
* V_449 = V_2 -> V_5 . V_325 . V_327 +
( V_2 -> V_5 . V_325 . V_328 << 10 ) ;
else if ( V_21 == V_310 )
* V_449 = V_324 [ 0 ] ;
else if ( V_21 == V_311 || V_21 == V_312 )
* V_449 = V_324 [ 1 + V_21 - V_311 ] ;
else if ( V_21 >= V_313 && V_21 <= V_320 )
* V_449 = V_324 [ 3 + V_21 - V_313 ] ;
else if ( V_21 == V_322 )
* V_449 = V_2 -> V_5 . V_329 ;
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
* V_449 = * V_332 ;
}
return 0 ;
}
static int F_196 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_449 )
{
T_2 V_31 ;
T_2 V_336 = V_2 -> V_5 . V_336 ;
unsigned V_337 = V_336 & 0xff ;
switch ( V_21 ) {
case V_451 :
case V_452 :
V_31 = 0 ;
break;
case V_453 :
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
* V_449 = V_31 ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_449 )
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
F_167 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_449 = V_31 ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_449 )
{
T_2 V_31 = 0 ;
switch ( V_21 ) {
case V_454 : {
int V_100 ;
struct V_1 * V_232 ;
F_199 (r, v, vcpu->kvm)
if ( V_232 == V_2 )
V_31 = V_100 ;
break;
}
case V_373 :
return F_200 ( V_2 , V_374 , V_449 ) ;
case V_375 :
return F_200 ( V_2 , V_376 , V_449 ) ;
case V_377 :
return F_200 ( V_2 , V_378 , V_449 ) ;
case V_369 :
V_31 = V_2 -> V_5 . V_371 ;
break;
default:
F_167 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_449 = V_31 ;
return 0 ;
}
int F_201 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_449 )
{
T_2 V_31 ;
switch ( V_21 ) {
case V_455 :
case V_456 :
case V_400 :
case V_457 :
case V_458 :
case V_459 :
case V_460 :
case V_461 :
case V_397 :
case V_405 :
case V_426 :
case V_430 :
case V_462 :
case V_399 :
case V_398 :
V_31 = 0 ;
break;
case V_434 :
case V_435 :
case V_436 :
case V_437 :
if ( F_189 ( V_2 , V_21 ) )
return F_202 ( V_2 , V_21 , V_449 ) ;
V_31 = 0 ;
break;
case V_403 :
V_31 = 0x100000000ULL ;
break;
case V_463 :
V_31 = 0x500 | V_309 ;
break;
case 0x200 ... 0x2ff :
return F_195 ( V_2 , V_21 , V_449 ) ;
case 0xcd :
V_31 = 3 ;
break;
case V_464 :
V_31 = 1 << 24 ;
break;
case V_407 :
V_31 = F_18 ( V_2 ) ;
break;
case V_408 ... V_408 + 0x3ff :
return F_203 ( V_2 , V_21 , V_449 ) ;
break;
case V_409 :
V_31 = F_204 ( V_2 ) ;
break;
case V_410 :
V_31 = ( T_2 ) V_2 -> V_5 . V_258 ;
break;
case V_413 :
V_31 = V_2 -> V_5 . V_414 ;
break;
case V_465 :
V_31 = 1000ULL ;
V_31 |= ( ( ( T_7 ) 4ULL ) << 40 ) ;
break;
case V_396 :
V_31 = V_2 -> V_5 . V_111 ;
break;
case V_416 :
case V_415 :
V_31 = V_2 -> V_82 -> V_5 . V_206 ;
break;
case V_418 :
case V_417 :
V_31 = V_2 -> V_5 . time ;
break;
case V_419 :
V_31 = V_2 -> V_5 . V_6 . V_380 ;
break;
case V_420 :
V_31 = V_2 -> V_5 . V_384 . V_380 ;
break;
case V_424 :
V_31 = V_2 -> V_5 . V_466 . V_380 ;
break;
case V_451 :
case V_452 :
case V_453 :
case V_340 :
case V_338 :
case V_343 ... V_343 + 4 * V_425 - 1 :
return F_196 ( V_2 , V_21 , V_449 ) ;
case V_438 :
V_31 = 0x20000000 ;
break;
case V_361 ... V_439 :
if ( F_162 ( V_21 ) ) {
int V_100 ;
F_191 ( & V_2 -> V_82 -> V_440 ) ;
V_100 = F_197 ( V_2 , V_21 , V_449 ) ;
F_192 ( & V_2 -> V_82 -> V_440 ) ;
return V_100 ;
} else
return F_198 ( V_2 , V_21 , V_449 ) ;
break;
case V_441 :
V_31 = 0xbe702111 ;
break;
case V_442 :
if ( ! F_193 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_443 . V_444 ;
break;
case V_445 :
if ( ! F_193 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_443 . V_446 ;
break;
default:
if ( F_189 ( V_2 , V_21 ) )
return F_202 ( V_2 , V_21 , V_449 ) ;
if ( ! V_447 ) {
F_167 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_167 ( V_2 , L_20 , V_21 ) ;
V_31 = 0 ;
}
break;
}
* V_449 = V_31 ;
return 0 ;
}
static int F_205 ( struct V_1 * V_2 , struct V_467 * V_19 ,
struct V_468 * V_469 ,
int (* F_206)( struct V_1 * V_2 ,
unsigned V_119 , T_2 * V_31 ) )
{
int V_3 , V_330 ;
V_330 = F_207 ( & V_2 -> V_82 -> V_470 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_471 ; ++ V_3 )
if ( F_206 ( V_2 , V_469 [ V_3 ] . V_119 , & V_469 [ V_3 ] . V_31 ) )
break;
F_208 ( & V_2 -> V_82 -> V_470 , V_330 ) ;
return V_3 ;
}
static int F_209 ( struct V_1 * V_2 , struct V_467 V_368 * V_472 ,
int (* F_206)( struct V_1 * V_2 ,
unsigned V_119 , T_2 * V_31 ) ,
int V_473 )
{
struct V_467 V_19 ;
struct V_468 * V_469 ;
int V_100 , V_474 ;
unsigned V_475 ;
V_100 = - V_81 ;
if ( F_210 ( & V_19 , V_472 , sizeof V_19 ) )
goto V_94;
V_100 = - V_356 ;
if ( V_19 . V_471 >= V_476 )
goto V_94;
V_475 = sizeof( struct V_468 ) * V_19 . V_471 ;
V_469 = F_157 ( V_472 -> V_469 , V_475 ) ;
if ( F_158 ( V_469 ) ) {
V_100 = F_159 ( V_469 ) ;
goto V_94;
}
V_100 = V_474 = F_205 ( V_2 , & V_19 , V_469 , F_206 ) ;
if ( V_100 < 0 )
goto V_358;
V_100 = - V_81 ;
if ( V_473 && F_211 ( V_472 -> V_469 , V_469 , V_475 ) )
goto V_358;
V_100 = V_474 ;
V_358:
F_160 ( V_469 ) ;
V_94:
return V_100 ;
}
int F_212 ( long V_477 )
{
int V_100 ;
switch ( V_477 ) {
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
case V_511 :
case V_512 :
V_100 = 1 ;
break;
case V_513 :
V_100 = V_514 ;
break;
case V_515 :
V_100 = ! V_56 -> V_516 () ;
break;
case V_517 :
V_100 = V_518 ;
break;
case V_519 :
V_100 = V_520 ;
break;
case V_521 :
V_100 = V_522 ;
break;
case V_523 :
V_100 = 0 ;
break;
case V_524 :
V_100 = F_213 ( & V_525 ) ;
break;
case V_526 :
V_100 = V_425 ;
break;
case V_527 :
V_100 = V_528 ;
break;
case V_529 :
V_100 = V_530 ;
break;
case V_531 :
V_100 = F_214 ( V_532 ) ;
break;
default:
V_100 = 0 ;
break;
}
return V_100 ;
}
long F_215 ( struct V_533 * V_534 ,
unsigned int V_535 , unsigned long V_536 )
{
void V_368 * V_537 = ( void V_368 * ) V_536 ;
long V_100 ;
switch ( V_535 ) {
case V_538 : {
struct V_539 V_368 * V_540 = V_537 ;
struct V_539 V_541 ;
unsigned V_474 ;
V_100 = - V_81 ;
if ( F_210 ( & V_541 , V_540 , sizeof V_541 ) )
goto V_94;
V_474 = V_541 . V_471 ;
V_541 . V_471 = V_542 + F_42 ( V_543 ) ;
if ( F_211 ( V_540 , & V_541 , sizeof V_541 ) )
goto V_94;
V_100 = - V_356 ;
if ( V_474 < V_541 . V_471 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_540 -> V_544 , & V_545 ,
V_542 * sizeof( T_1 ) ) )
goto V_94;
if ( F_211 ( V_540 -> V_544 + V_542 ,
& V_543 ,
F_42 ( V_543 ) * sizeof( T_1 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_546 : {
struct V_547 V_368 * V_548 = V_537 ;
struct V_547 V_549 ;
V_100 = - V_81 ;
if ( F_210 ( & V_549 , V_548 , sizeof V_549 ) )
goto V_94;
V_100 = F_216 ( & V_549 ,
V_548 -> V_469 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_548 , & V_549 , sizeof V_549 ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_550 : {
T_2 V_551 ;
V_551 = V_552 ;
V_100 = - V_81 ;
if ( F_211 ( V_537 , & V_551 , sizeof V_551 ) )
goto V_94;
V_100 = 0 ;
break;
}
default:
V_100 = - V_553 ;
}
V_94:
return V_100 ;
}
static void F_217 ( void * V_554 )
{
F_218 () ;
}
static bool F_219 ( struct V_1 * V_2 )
{
return V_2 -> V_82 -> V_5 . V_555 &&
! ( V_2 -> V_82 -> V_5 . V_556 & V_557 ) ;
}
void F_220 ( struct V_1 * V_2 , int V_23 )
{
if ( F_219 ( V_2 ) ) {
if ( V_56 -> V_558 () )
F_221 ( V_23 , V_2 -> V_5 . V_559 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_222 ( V_2 -> V_23 ,
F_217 , NULL , 1 ) ;
}
V_56 -> V_560 ( V_2 , V_23 ) ;
if ( F_71 ( V_2 -> V_5 . V_561 ) ) {
F_223 ( V_2 , V_2 -> V_5 . V_561 ) ;
V_2 -> V_5 . V_561 = 0 ;
F_224 ( V_296 , & V_2 -> V_562 ) ;
}
if ( F_71 ( V_2 -> V_23 != V_23 ) || F_123 () ) {
T_10 V_563 = ! V_2 -> V_5 . V_564 ? 0 :
F_145 () - V_2 -> V_5 . V_564 ;
if ( V_563 < 0 )
F_225 ( L_21 ) ;
if ( F_123 () ) {
T_2 V_74 = V_56 -> V_265 ( V_2 ,
V_2 -> V_5 . V_277 ) ;
V_56 -> V_279 ( V_2 , V_74 ) ;
V_2 -> V_5 . V_298 = 1 ;
}
if ( ! V_2 -> V_82 -> V_5 . V_253 || V_2 -> V_23 == - 1 )
F_23 ( V_296 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_226 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_176 ( V_2 ) ;
F_23 ( V_423 , V_2 ) ;
}
void F_227 ( struct V_1 * V_2 )
{
V_56 -> V_565 ( V_2 ) ;
F_228 ( V_2 ) ;
V_2 -> V_5 . V_564 = F_145 () ;
}
static int F_229 ( struct V_1 * V_2 ,
struct V_566 * V_567 )
{
memcpy ( V_567 -> V_568 , V_2 -> V_5 . V_569 -> V_568 , sizeof *V_567 ) ;
return 0 ;
}
static int F_230 ( struct V_1 * V_2 ,
struct V_566 * V_567 )
{
F_231 ( V_2 , V_567 ) ;
F_232 ( V_2 ) ;
return 0 ;
}
static int F_233 ( struct V_1 * V_2 ,
struct V_570 * V_571 )
{
if ( V_571 -> V_571 < 0 || V_571 -> V_571 >= V_572 )
return - V_553 ;
if ( F_74 ( V_2 -> V_82 ) )
return - V_573 ;
F_234 ( V_2 , V_571 -> V_571 , false ) ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_235 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
return 0 ;
}
static int F_236 ( struct V_1 * V_2 ,
struct V_574 * V_575 )
{
if ( V_575 -> V_261 )
return - V_553 ;
V_2 -> V_5 . V_576 = ! ! V_575 -> V_328 ;
return 0 ;
}
static int F_237 ( struct V_1 * V_2 ,
T_2 V_336 )
{
int V_100 ;
unsigned V_337 = V_336 & 0xff , V_577 ;
V_100 = - V_553 ;
if ( ! V_337 || V_337 >= V_425 )
goto V_94;
if ( V_336 & ~ ( V_552 | 0xff | 0xff0000 ) )
goto V_94;
V_100 = 0 ;
V_2 -> V_5 . V_336 = V_336 ;
if ( V_336 & V_341 )
V_2 -> V_5 . V_342 = ~ ( T_2 ) 0 ;
for ( V_577 = 0 ; V_577 < V_337 ; V_577 ++ )
V_2 -> V_5 . V_344 [ V_577 * 4 ] = ~ ( T_2 ) 0 ;
V_94:
return V_100 ;
}
static int F_238 ( struct V_1 * V_2 ,
struct V_578 * V_579 )
{
T_2 V_336 = V_2 -> V_5 . V_336 ;
unsigned V_337 = V_336 & 0xff ;
T_2 * V_580 = V_2 -> V_5 . V_344 ;
if ( V_579 -> V_577 >= V_337 || ! ( V_579 -> V_446 & V_581 ) )
return - V_553 ;
if ( ( V_579 -> V_446 & V_582 ) && ( V_336 & V_341 ) &&
V_2 -> V_5 . V_342 != ~ ( T_2 ) 0 )
return 0 ;
V_580 += 4 * V_579 -> V_577 ;
if ( ( V_579 -> V_446 & V_582 ) && V_580 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_579 -> V_446 & V_582 ) {
if ( ( V_2 -> V_5 . V_339 & V_583 ) ||
! F_54 ( V_2 , V_584 ) ) {
F_23 ( V_54 , V_2 ) ;
return 0 ;
}
if ( V_580 [ 1 ] & V_581 )
V_579 -> V_446 |= V_585 ;
V_580 [ 2 ] = V_579 -> V_364 ;
V_580 [ 3 ] = V_579 -> V_586 ;
V_2 -> V_5 . V_339 = V_579 -> V_339 ;
V_580 [ 1 ] = V_579 -> V_446 ;
F_24 ( V_2 , V_587 ) ;
} else if ( ! ( V_580 [ 1 ] & V_581 )
|| ! ( V_580 [ 1 ] & V_582 ) ) {
if ( V_580 [ 1 ] & V_581 )
V_579 -> V_446 |= V_585 ;
V_580 [ 2 ] = V_579 -> V_364 ;
V_580 [ 3 ] = V_579 -> V_586 ;
V_580 [ 1 ] = V_579 -> V_446 ;
} else
V_580 [ 1 ] |= V_585 ;
return 0 ;
}
static void F_239 ( struct V_1 * V_2 ,
struct V_588 * V_589 )
{
F_240 ( V_2 ) ;
V_589 -> V_49 . V_590 =
V_2 -> V_5 . V_49 . V_50 &&
! F_241 ( V_2 -> V_5 . V_49 . V_16 ) ;
V_589 -> V_49 . V_16 = V_2 -> V_5 . V_49 . V_16 ;
V_589 -> V_49 . V_52 = V_2 -> V_5 . V_49 . V_52 ;
V_589 -> V_49 . V_591 = 0 ;
V_589 -> V_49 . V_43 = V_2 -> V_5 . V_49 . V_43 ;
V_589 -> V_592 . V_590 =
V_2 -> V_5 . V_592 . V_50 && ! V_2 -> V_5 . V_592 . V_593 ;
V_589 -> V_592 . V_16 = V_2 -> V_5 . V_592 . V_16 ;
V_589 -> V_592 . V_593 = 0 ;
V_589 -> V_592 . V_594 =
V_56 -> V_595 ( V_2 ,
V_596 | V_597 ) ;
V_589 -> V_598 . V_590 = V_2 -> V_5 . V_599 ;
V_589 -> V_598 . V_50 = V_2 -> V_5 . V_600 != 0 ;
V_589 -> V_598 . V_601 = V_56 -> V_602 ( V_2 ) ;
V_589 -> V_598 . V_591 = 0 ;
V_589 -> V_603 = V_2 -> V_5 . V_603 ;
V_589 -> V_261 = ( V_604
| V_605
| V_606 ) ;
memset ( & V_589 -> V_607 , 0 , sizeof( V_589 -> V_607 ) ) ;
}
static int F_242 ( struct V_1 * V_2 ,
struct V_588 * V_589 )
{
if ( V_589 -> V_261 & ~ ( V_604
| V_605
| V_606 ) )
return - V_553 ;
F_240 ( V_2 ) ;
V_2 -> V_5 . V_49 . V_50 = V_589 -> V_49 . V_590 ;
V_2 -> V_5 . V_49 . V_16 = V_589 -> V_49 . V_16 ;
V_2 -> V_5 . V_49 . V_52 = V_589 -> V_49 . V_52 ;
V_2 -> V_5 . V_49 . V_43 = V_589 -> V_49 . V_43 ;
V_2 -> V_5 . V_592 . V_50 = V_589 -> V_592 . V_590 ;
V_2 -> V_5 . V_592 . V_16 = V_589 -> V_592 . V_16 ;
V_2 -> V_5 . V_592 . V_593 = V_589 -> V_592 . V_593 ;
if ( V_589 -> V_261 & V_606 )
V_56 -> V_608 ( V_2 ,
V_589 -> V_592 . V_594 ) ;
V_2 -> V_5 . V_599 = V_589 -> V_598 . V_590 ;
if ( V_589 -> V_261 & V_604 )
V_2 -> V_5 . V_600 = V_589 -> V_598 . V_50 ;
V_56 -> V_609 ( V_2 , V_589 -> V_598 . V_601 ) ;
if ( V_589 -> V_261 & V_605 )
V_2 -> V_5 . V_603 = V_589 -> V_603 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static void F_243 ( struct V_1 * V_2 ,
struct V_610 * V_611 )
{
memcpy ( V_611 -> V_157 , V_2 -> V_5 . V_157 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_611 -> V_160 = V_2 -> V_5 . V_160 ;
V_611 -> V_148 = V_2 -> V_5 . V_148 ;
V_611 -> V_261 = 0 ;
memset ( & V_611 -> V_607 , 0 , sizeof( V_611 -> V_607 ) ) ;
}
static int F_244 ( struct V_1 * V_2 ,
struct V_610 * V_611 )
{
if ( V_611 -> V_261 )
return - V_553 ;
memcpy ( V_2 -> V_5 . V_157 , V_611 -> V_157 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_2 -> V_5 . V_160 = V_611 -> V_160 ;
V_2 -> V_5 . V_148 = V_611 -> V_148 ;
return 0 ;
}
static void F_245 ( struct V_1 * V_2 ,
struct V_612 * V_613 )
{
if ( V_528 )
memcpy ( V_613 -> V_614 ,
& V_2 -> V_5 . V_615 . V_616 -> V_617 ,
V_618 ) ;
else {
memcpy ( V_613 -> V_614 ,
& V_2 -> V_5 . V_615 . V_616 -> V_619 ,
sizeof( struct V_620 ) ) ;
* ( T_2 * ) & V_613 -> V_614 [ V_621 / sizeof( T_1 ) ] =
V_622 ;
}
}
static int F_246 ( struct V_1 * V_2 ,
struct V_612 * V_613 )
{
T_2 V_623 =
* ( T_2 * ) & V_613 -> V_614 [ V_621 / sizeof( T_1 ) ] ;
if ( V_528 )
memcpy ( & V_2 -> V_5 . V_615 . V_616 -> V_617 ,
V_613 -> V_614 , V_618 ) ;
else {
if ( V_623 & ~ V_622 )
return - V_553 ;
memcpy ( & V_2 -> V_5 . V_615 . V_616 -> V_619 ,
V_613 -> V_614 , sizeof( struct V_620 ) ) ;
}
return 0 ;
}
static void F_247 ( struct V_1 * V_2 ,
struct V_624 * V_625 )
{
if ( ! V_528 ) {
V_625 -> V_626 = 0 ;
return;
}
V_625 -> V_626 = 1 ;
V_625 -> V_261 = 0 ;
V_625 -> V_627 [ 0 ] . V_120 = V_122 ;
V_625 -> V_627 [ 0 ] . V_22 = V_2 -> V_5 . V_121 ;
}
static int F_248 ( struct V_1 * V_2 ,
struct V_624 * V_625 )
{
int V_3 , V_100 = 0 ;
if ( ! V_528 )
return - V_553 ;
if ( V_625 -> V_626 > V_628 || V_625 -> V_261 )
return - V_553 ;
for ( V_3 = 0 ; V_3 < V_625 -> V_626 ; V_3 ++ )
if ( V_625 -> V_627 [ 0 ] . V_120 == V_122 ) {
V_100 = F_59 ( V_2 , V_122 ,
V_625 -> V_627 [ 0 ] . V_22 ) ;
break;
}
if ( V_100 )
V_100 = - V_553 ;
return V_100 ;
}
static int F_249 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_299 )
return - V_553 ;
V_2 -> V_5 . V_307 = true ;
F_23 ( V_296 , V_2 ) ;
return 0 ;
}
long F_250 ( struct V_533 * V_534 ,
unsigned int V_535 , unsigned long V_536 )
{
struct V_1 * V_2 = V_534 -> V_629 ;
void V_368 * V_537 = ( void V_368 * ) V_536 ;
int V_100 ;
union {
struct V_566 * V_630 ;
struct V_612 * V_617 ;
struct V_624 * V_627 ;
void * V_631 ;
} V_632 ;
V_632 . V_631 = NULL ;
switch ( V_535 ) {
case V_633 : {
V_100 = - V_553 ;
if ( ! V_2 -> V_5 . V_569 )
goto V_94;
V_632 . V_630 = F_251 ( sizeof( struct V_566 ) , V_634 ) ;
V_100 = - V_357 ;
if ( ! V_632 . V_630 )
goto V_94;
V_100 = F_229 ( V_2 , V_632 . V_630 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_537 , V_632 . V_630 , sizeof( struct V_566 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_635 : {
V_100 = - V_553 ;
if ( ! V_2 -> V_5 . V_569 )
goto V_94;
V_632 . V_630 = F_157 ( V_537 , sizeof( * V_632 . V_630 ) ) ;
if ( F_158 ( V_632 . V_630 ) )
return F_159 ( V_632 . V_630 ) ;
V_100 = F_230 ( V_2 , V_632 . V_630 ) ;
break;
}
case V_636 : {
struct V_570 V_571 ;
V_100 = - V_81 ;
if ( F_210 ( & V_571 , V_537 , sizeof V_571 ) )
goto V_94;
V_100 = F_233 ( V_2 , & V_571 ) ;
break;
}
case V_637 : {
V_100 = F_235 ( V_2 ) ;
break;
}
case V_638 : {
struct V_639 V_368 * V_548 = V_537 ;
struct V_639 V_549 ;
V_100 = - V_81 ;
if ( F_210 ( & V_549 , V_548 , sizeof V_549 ) )
goto V_94;
V_100 = F_252 ( V_2 , & V_549 , V_548 -> V_469 ) ;
break;
}
case V_640 : {
struct V_547 V_368 * V_548 = V_537 ;
struct V_547 V_549 ;
V_100 = - V_81 ;
if ( F_210 ( & V_549 , V_548 , sizeof V_549 ) )
goto V_94;
V_100 = F_253 ( V_2 , & V_549 ,
V_548 -> V_469 ) ;
break;
}
case V_641 : {
struct V_547 V_368 * V_548 = V_537 ;
struct V_547 V_549 ;
V_100 = - V_81 ;
if ( F_210 ( & V_549 , V_548 , sizeof V_549 ) )
goto V_94;
V_100 = F_254 ( V_2 , & V_549 ,
V_548 -> V_469 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_548 , & V_549 , sizeof V_549 ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_642 :
V_100 = F_209 ( V_2 , V_537 , F_194 , 1 ) ;
break;
case V_643 :
V_100 = F_209 ( V_2 , V_537 , F_92 , 0 ) ;
break;
case V_644 : {
struct V_574 V_575 ;
V_100 = - V_81 ;
if ( F_210 ( & V_575 , V_537 , sizeof V_575 ) )
goto V_94;
V_100 = F_236 ( V_2 , & V_575 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_537 , & V_575 , sizeof V_575 ) )
goto V_94;
V_100 = 0 ;
break;
} ;
case V_645 : {
struct V_646 V_647 ;
V_100 = - V_553 ;
if ( ! F_74 ( V_2 -> V_82 ) )
goto V_94;
V_100 = - V_81 ;
if ( F_210 ( & V_647 , V_537 , sizeof V_647 ) )
goto V_94;
V_100 = 0 ;
F_255 ( V_2 , V_647 . V_648 ) ;
break;
}
case V_649 : {
T_2 V_336 ;
V_100 = - V_81 ;
if ( F_210 ( & V_336 , V_537 , sizeof V_336 ) )
goto V_94;
V_100 = F_237 ( V_2 , V_336 ) ;
break;
}
case V_650 : {
struct V_578 V_579 ;
V_100 = - V_81 ;
if ( F_210 ( & V_579 , V_537 , sizeof V_579 ) )
goto V_94;
V_100 = F_238 ( V_2 , & V_579 ) ;
break;
}
case V_651 : {
struct V_588 V_589 ;
F_239 ( V_2 , & V_589 ) ;
V_100 = - V_81 ;
if ( F_211 ( V_537 , & V_589 , sizeof( struct V_588 ) ) )
break;
V_100 = 0 ;
break;
}
case V_652 : {
struct V_588 V_589 ;
V_100 = - V_81 ;
if ( F_210 ( & V_589 , V_537 , sizeof( struct V_588 ) ) )
break;
V_100 = F_242 ( V_2 , & V_589 ) ;
break;
}
case V_653 : {
struct V_610 V_611 ;
F_243 ( V_2 , & V_611 ) ;
V_100 = - V_81 ;
if ( F_211 ( V_537 , & V_611 ,
sizeof( struct V_610 ) ) )
break;
V_100 = 0 ;
break;
}
case V_654 : {
struct V_610 V_611 ;
V_100 = - V_81 ;
if ( F_210 ( & V_611 , V_537 ,
sizeof( struct V_610 ) ) )
break;
V_100 = F_244 ( V_2 , & V_611 ) ;
break;
}
case V_655 : {
V_632 . V_617 = F_251 ( sizeof( struct V_612 ) , V_634 ) ;
V_100 = - V_357 ;
if ( ! V_632 . V_617 )
break;
F_245 ( V_2 , V_632 . V_617 ) ;
V_100 = - V_81 ;
if ( F_211 ( V_537 , V_632 . V_617 , sizeof( struct V_612 ) ) )
break;
V_100 = 0 ;
break;
}
case V_656 : {
V_632 . V_617 = F_157 ( V_537 , sizeof( * V_632 . V_617 ) ) ;
if ( F_158 ( V_632 . V_617 ) )
return F_159 ( V_632 . V_617 ) ;
V_100 = F_246 ( V_2 , V_632 . V_617 ) ;
break;
}
case V_657 : {
V_632 . V_627 = F_251 ( sizeof( struct V_624 ) , V_634 ) ;
V_100 = - V_357 ;
if ( ! V_632 . V_627 )
break;
F_247 ( V_2 , V_632 . V_627 ) ;
V_100 = - V_81 ;
if ( F_211 ( V_537 , V_632 . V_627 ,
sizeof( struct V_624 ) ) )
break;
V_100 = 0 ;
break;
}
case V_658 : {
V_632 . V_627 = F_157 ( V_537 , sizeof( * V_632 . V_627 ) ) ;
if ( F_158 ( V_632 . V_627 ) )
return F_159 ( V_632 . V_627 ) ;
V_100 = F_248 ( V_2 , V_632 . V_627 ) ;
break;
}
case V_659 : {
T_1 V_660 ;
V_100 = - V_553 ;
V_660 = ( T_1 ) V_536 ;
if ( V_660 >= V_661 )
goto V_94;
if ( V_660 == 0 )
V_660 = V_238 ;
F_115 ( V_2 , V_660 ) ;
V_100 = 0 ;
goto V_94;
}
case V_662 : {
V_100 = V_2 -> V_5 . V_237 ;
goto V_94;
}
case V_663 : {
V_100 = F_249 ( V_2 ) ;
goto V_94;
}
default:
V_100 = - V_553 ;
}
V_94:
F_160 ( V_632 . V_631 ) ;
return V_100 ;
}
int F_256 ( struct V_1 * V_2 , struct V_664 * V_665 )
{
return V_666 ;
}
static int F_257 ( struct V_82 * V_82 , unsigned long V_364 )
{
int V_89 ;
if ( V_364 > ( unsigned int ) ( - 3 * V_88 ) )
return - V_553 ;
V_89 = V_56 -> V_667 ( V_82 , V_364 ) ;
return V_89 ;
}
static int F_258 ( struct V_82 * V_82 ,
T_2 V_668 )
{
V_82 -> V_5 . V_669 = V_668 ;
return 0 ;
}
static int F_259 ( struct V_82 * V_82 ,
T_1 V_670 )
{
if ( V_670 < V_671 )
return - V_553 ;
F_191 ( & V_82 -> V_672 ) ;
F_126 ( & V_82 -> V_673 ) ;
F_260 ( V_82 , V_670 ) ;
V_82 -> V_5 . V_674 = V_670 ;
F_127 ( & V_82 -> V_673 ) ;
F_192 ( & V_82 -> V_672 ) ;
return 0 ;
}
static int F_261 ( struct V_82 * V_82 )
{
return V_82 -> V_5 . V_675 ;
}
static int F_262 ( struct V_82 * V_82 , struct V_676 * V_677 )
{
int V_100 ;
V_100 = 0 ;
switch ( V_677 -> V_678 ) {
case V_679 :
memcpy ( & V_677 -> V_677 . V_680 ,
& F_263 ( V_82 ) -> V_681 [ 0 ] ,
sizeof( struct V_682 ) ) ;
break;
case V_683 :
memcpy ( & V_677 -> V_677 . V_680 ,
& F_263 ( V_82 ) -> V_681 [ 1 ] ,
sizeof( struct V_682 ) ) ;
break;
case V_684 :
V_100 = F_264 ( V_82 , & V_677 -> V_677 . V_685 ) ;
break;
default:
V_100 = - V_553 ;
break;
}
return V_100 ;
}
static int F_265 ( struct V_82 * V_82 , struct V_676 * V_677 )
{
int V_100 ;
V_100 = 0 ;
switch ( V_677 -> V_678 ) {
case V_679 :
F_126 ( & F_263 ( V_82 ) -> V_440 ) ;
memcpy ( & F_263 ( V_82 ) -> V_681 [ 0 ] ,
& V_677 -> V_677 . V_680 ,
sizeof( struct V_682 ) ) ;
F_127 ( & F_263 ( V_82 ) -> V_440 ) ;
break;
case V_683 :
F_126 ( & F_263 ( V_82 ) -> V_440 ) ;
memcpy ( & F_263 ( V_82 ) -> V_681 [ 1 ] ,
& V_677 -> V_677 . V_680 ,
sizeof( struct V_682 ) ) ;
F_127 ( & F_263 ( V_82 ) -> V_440 ) ;
break;
case V_684 :
V_100 = F_266 ( V_82 , & V_677 -> V_677 . V_685 ) ;
break;
default:
V_100 = - V_553 ;
break;
}
F_267 ( F_263 ( V_82 ) ) ;
return V_100 ;
}
static int F_268 ( struct V_82 * V_82 , struct V_686 * V_687 )
{
int V_100 = 0 ;
F_191 ( & V_82 -> V_5 . V_688 -> V_689 . V_440 ) ;
memcpy ( V_687 , & V_82 -> V_5 . V_688 -> V_689 , sizeof( struct V_686 ) ) ;
F_192 ( & V_82 -> V_5 . V_688 -> V_689 . V_440 ) ;
return V_100 ;
}
static int F_269 ( struct V_82 * V_82 , struct V_686 * V_687 )
{
int V_100 = 0 ;
F_191 ( & V_82 -> V_5 . V_688 -> V_689 . V_440 ) ;
memcpy ( & V_82 -> V_5 . V_688 -> V_689 , V_687 , sizeof( struct V_686 ) ) ;
F_270 ( V_82 , 0 , V_687 -> V_690 [ 0 ] . V_691 , 0 ) ;
F_192 ( & V_82 -> V_5 . V_688 -> V_689 . V_440 ) ;
return V_100 ;
}
static int F_271 ( struct V_82 * V_82 , struct V_692 * V_687 )
{
int V_100 = 0 ;
F_191 ( & V_82 -> V_5 . V_688 -> V_689 . V_440 ) ;
memcpy ( V_687 -> V_690 , & V_82 -> V_5 . V_688 -> V_689 . V_690 ,
sizeof( V_687 -> V_690 ) ) ;
V_687 -> V_261 = V_82 -> V_5 . V_688 -> V_689 . V_261 ;
F_192 ( & V_82 -> V_5 . V_688 -> V_689 . V_440 ) ;
memset ( & V_687 -> V_607 , 0 , sizeof( V_687 -> V_607 ) ) ;
return V_100 ;
}
static int F_272 ( struct V_82 * V_82 , struct V_692 * V_687 )
{
int V_100 = 0 , V_693 = 0 ;
T_1 V_694 , V_695 ;
F_191 ( & V_82 -> V_5 . V_688 -> V_689 . V_440 ) ;
V_694 = V_82 -> V_5 . V_688 -> V_689 . V_261 & V_696 ;
V_695 = V_687 -> V_261 & V_696 ;
if ( ! V_694 && V_695 )
V_693 = 1 ;
memcpy ( & V_82 -> V_5 . V_688 -> V_689 . V_690 , & V_687 -> V_690 ,
sizeof( V_82 -> V_5 . V_688 -> V_689 . V_690 ) ) ;
V_82 -> V_5 . V_688 -> V_689 . V_261 = V_687 -> V_261 ;
F_270 ( V_82 , 0 , V_82 -> V_5 . V_688 -> V_689 . V_690 [ 0 ] . V_691 , V_693 ) ;
F_192 ( & V_82 -> V_5 . V_688 -> V_689 . V_440 ) ;
return V_100 ;
}
static int F_273 ( struct V_82 * V_82 ,
struct V_697 * V_698 )
{
if ( ! V_82 -> V_5 . V_688 )
return - V_573 ;
F_191 ( & V_82 -> V_5 . V_688 -> V_689 . V_440 ) ;
V_82 -> V_5 . V_688 -> V_689 . V_44 = V_698 -> V_699 ;
F_192 ( & V_82 -> V_5 . V_688 -> V_689 . V_440 ) ;
return 0 ;
}
int F_274 ( struct V_82 * V_82 , struct V_700 * log )
{
int V_100 ;
struct V_701 * V_702 ;
unsigned long V_474 , V_3 ;
unsigned long * V_703 ;
unsigned long * V_704 ;
bool V_705 = false ;
F_191 ( & V_82 -> V_672 ) ;
V_100 = - V_553 ;
if ( log -> V_10 >= V_522 )
goto V_94;
V_702 = F_275 ( V_82 -> V_706 , log -> V_10 ) ;
V_703 = V_702 -> V_703 ;
V_100 = - V_707 ;
if ( ! V_703 )
goto V_94;
V_474 = F_276 ( V_702 ) ;
V_704 = V_703 + V_474 / sizeof( long ) ;
memset ( V_704 , 0 , V_474 ) ;
F_126 ( & V_82 -> V_673 ) ;
for ( V_3 = 0 ; V_3 < V_474 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_27 ;
T_3 V_74 ;
if ( ! V_703 [ V_3 ] )
continue;
V_705 = true ;
V_27 = F_277 ( & V_703 [ V_3 ] , 0 ) ;
V_704 [ V_3 ] = V_27 ;
V_74 = V_3 * V_708 ;
F_278 ( V_82 , V_702 , V_74 , V_27 ) ;
}
if ( V_705 )
F_279 ( V_82 ) ;
F_127 ( & V_82 -> V_673 ) ;
V_100 = - V_81 ;
if ( F_211 ( log -> V_703 , V_704 , V_474 ) )
goto V_94;
V_100 = 0 ;
V_94:
F_192 ( & V_82 -> V_672 ) ;
return V_100 ;
}
int F_280 ( struct V_82 * V_82 , struct V_709 * V_710 )
{
if ( ! F_74 ( V_82 ) )
return - V_573 ;
V_710 -> V_446 = F_281 ( V_82 , V_711 ,
V_710 -> V_571 , V_710 -> V_712 ) ;
return 0 ;
}
long F_282 ( struct V_533 * V_534 ,
unsigned int V_535 , unsigned long V_536 )
{
struct V_82 * V_82 = V_534 -> V_629 ;
void V_368 * V_537 = ( void V_368 * ) V_536 ;
int V_100 = - V_713 ;
union {
struct V_686 V_687 ;
struct V_692 V_714 ;
struct V_715 V_716 ;
} V_632 ;
switch ( V_535 ) {
case V_717 :
V_100 = F_257 ( V_82 , V_536 ) ;
break;
case V_718 : {
T_2 V_668 ;
V_100 = - V_81 ;
if ( F_210 ( & V_668 , V_537 , sizeof V_668 ) )
goto V_94;
V_100 = F_258 ( V_82 , V_668 ) ;
break;
}
case V_719 :
V_100 = F_259 ( V_82 , V_536 ) ;
break;
case V_720 :
V_100 = F_261 ( V_82 ) ;
break;
case V_721 : {
struct V_722 * V_723 ;
F_191 ( & V_82 -> V_440 ) ;
V_100 = - V_724 ;
if ( V_82 -> V_5 . V_723 )
goto V_725;
V_100 = - V_553 ;
if ( F_118 ( & V_82 -> V_251 ) )
goto V_725;
V_100 = - V_357 ;
V_723 = F_283 ( V_82 ) ;
if ( V_723 ) {
V_100 = F_284 ( V_82 ) ;
if ( V_100 ) {
F_191 ( & V_82 -> V_672 ) ;
F_285 ( V_82 , V_726 ,
& V_723 -> V_727 ) ;
F_285 ( V_82 , V_726 ,
& V_723 -> V_728 ) ;
F_285 ( V_82 , V_726 ,
& V_723 -> V_729 ) ;
F_192 ( & V_82 -> V_672 ) ;
F_160 ( V_723 ) ;
goto V_725;
}
} else
goto V_725;
F_13 () ;
V_82 -> V_5 . V_723 = V_723 ;
F_13 () ;
V_100 = F_286 ( V_82 ) ;
if ( V_100 ) {
F_191 ( & V_82 -> V_672 ) ;
F_191 ( & V_82 -> V_730 ) ;
F_287 ( V_82 ) ;
F_288 ( V_82 ) ;
F_192 ( & V_82 -> V_730 ) ;
F_192 ( & V_82 -> V_672 ) ;
}
V_725:
F_192 ( & V_82 -> V_440 ) ;
break;
}
case V_731 :
V_632 . V_716 . V_261 = V_732 ;
goto V_733;
case V_734 :
V_100 = - V_81 ;
if ( F_210 ( & V_632 . V_716 , V_537 ,
sizeof( struct V_715 ) ) )
goto V_94;
V_733:
F_191 ( & V_82 -> V_672 ) ;
V_100 = - V_724 ;
if ( V_82 -> V_5 . V_688 )
goto V_735;
V_100 = - V_357 ;
V_82 -> V_5 . V_688 = F_289 ( V_82 , V_632 . V_716 . V_261 ) ;
if ( V_82 -> V_5 . V_688 )
V_100 = 0 ;
V_735:
F_192 ( & V_82 -> V_672 ) ;
break;
case V_736 : {
struct V_676 * V_677 ;
V_677 = F_157 ( V_537 , sizeof( * V_677 ) ) ;
if ( F_158 ( V_677 ) ) {
V_100 = F_159 ( V_677 ) ;
goto V_94;
}
V_100 = - V_573 ;
if ( ! F_74 ( V_82 ) )
goto V_737;
V_100 = F_262 ( V_82 , V_677 ) ;
if ( V_100 )
goto V_737;
V_100 = - V_81 ;
if ( F_211 ( V_537 , V_677 , sizeof *V_677 ) )
goto V_737;
V_100 = 0 ;
V_737:
F_160 ( V_677 ) ;
break;
}
case V_738 : {
struct V_676 * V_677 ;
V_677 = F_157 ( V_537 , sizeof( * V_677 ) ) ;
if ( F_158 ( V_677 ) ) {
V_100 = F_159 ( V_677 ) ;
goto V_94;
}
V_100 = - V_573 ;
if ( ! F_74 ( V_82 ) )
goto V_739;
V_100 = F_265 ( V_82 , V_677 ) ;
if ( V_100 )
goto V_739;
V_100 = 0 ;
V_739:
F_160 ( V_677 ) ;
break;
}
case V_740 : {
V_100 = - V_81 ;
if ( F_210 ( & V_632 . V_687 , V_537 , sizeof( struct V_686 ) ) )
goto V_94;
V_100 = - V_573 ;
if ( ! V_82 -> V_5 . V_688 )
goto V_94;
V_100 = F_268 ( V_82 , & V_632 . V_687 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_537 , & V_632 . V_687 , sizeof( struct V_686 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_741 : {
V_100 = - V_81 ;
if ( F_210 ( & V_632 . V_687 , V_537 , sizeof V_632 . V_687 ) )
goto V_94;
V_100 = - V_573 ;
if ( ! V_82 -> V_5 . V_688 )
goto V_94;
V_100 = F_269 ( V_82 , & V_632 . V_687 ) ;
break;
}
case V_742 : {
V_100 = - V_573 ;
if ( ! V_82 -> V_5 . V_688 )
goto V_94;
V_100 = F_271 ( V_82 , & V_632 . V_714 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_537 , & V_632 . V_714 , sizeof( V_632 . V_714 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_743 : {
V_100 = - V_81 ;
if ( F_210 ( & V_632 . V_714 , V_537 , sizeof( V_632 . V_714 ) ) )
goto V_94;
V_100 = - V_573 ;
if ( ! V_82 -> V_5 . V_688 )
goto V_94;
V_100 = F_272 ( V_82 , & V_632 . V_714 ) ;
break;
}
case V_744 : {
struct V_697 V_698 ;
V_100 = - V_81 ;
if ( F_210 ( & V_698 , V_537 , sizeof( V_698 ) ) )
goto V_94;
V_100 = F_273 ( V_82 , & V_698 ) ;
break;
}
case V_745 : {
V_100 = - V_81 ;
if ( F_210 ( & V_82 -> V_5 . F_156 , V_537 ,
sizeof( struct V_746 ) ) )
goto V_94;
V_100 = - V_553 ;
if ( V_82 -> V_5 . F_156 . V_261 )
goto V_94;
V_100 = 0 ;
break;
}
case V_747 : {
struct V_748 V_749 ;
T_2 V_750 ;
T_10 V_271 ;
V_100 = - V_81 ;
if ( F_210 ( & V_749 , V_537 , sizeof( V_749 ) ) )
goto V_94;
V_100 = - V_553 ;
if ( V_749 . V_261 )
goto V_94;
V_100 = 0 ;
F_290 () ;
V_750 = F_105 () ;
V_271 = V_749 . clock - V_750 ;
F_291 () ;
V_82 -> V_5 . V_212 = V_271 ;
break;
}
case V_751 : {
struct V_748 V_749 ;
T_2 V_750 ;
F_290 () ;
V_750 = F_105 () ;
V_749 . clock = V_82 -> V_5 . V_212 + V_750 ;
F_291 () ;
V_749 . V_261 = 0 ;
memset ( & V_749 . V_591 , 0 , sizeof( V_749 . V_591 ) ) ;
V_100 = - V_81 ;
if ( F_211 ( V_537 , & V_749 , sizeof( V_749 ) ) )
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
static void F_292 ( void )
{
T_1 V_752 [ 2 ] ;
unsigned V_3 , V_753 ;
for ( V_3 = V_753 = V_754 ; V_3 < F_42 ( V_545 ) ; V_3 ++ ) {
if ( F_293 ( V_545 [ V_3 ] , & V_752 [ 0 ] , & V_752 [ 1 ] ) < 0 )
continue;
if ( V_753 < V_3 )
V_545 [ V_753 ] = V_545 [ V_3 ] ;
V_753 ++ ;
}
V_542 = V_753 ;
}
static int F_294 ( struct V_1 * V_2 , T_4 V_364 , int V_75 ,
const void * V_232 )
{
int V_755 = 0 ;
int V_474 ;
do {
V_474 = F_295 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_569 &&
! F_296 ( & V_2 -> V_5 . V_569 -> V_756 , V_364 , V_474 , V_232 ) )
&& F_297 ( V_2 -> V_82 , V_757 , V_364 , V_474 , V_232 ) )
break;
V_755 += V_474 ;
V_364 += V_474 ;
V_75 -= V_474 ;
V_232 += V_474 ;
} while ( V_75 );
return V_755 ;
}
static int F_298 ( struct V_1 * V_2 , T_4 V_364 , int V_75 , void * V_232 )
{
int V_755 = 0 ;
int V_474 ;
do {
V_474 = F_295 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_569 &&
! F_299 ( & V_2 -> V_5 . V_569 -> V_756 , V_364 , V_474 , V_232 ) )
&& F_300 ( V_2 -> V_82 , V_757 , V_364 , V_474 , V_232 ) )
break;
F_301 ( V_758 , V_474 , V_364 , * ( T_2 * ) V_232 ) ;
V_755 += V_474 ;
V_364 += V_474 ;
V_75 -= V_474 ;
V_232 += V_474 ;
} while ( V_75 );
return V_755 ;
}
static void F_302 ( struct V_1 * V_2 ,
struct V_759 * V_760 , int V_761 )
{
V_56 -> V_762 ( V_2 , V_760 , V_761 ) ;
}
void F_303 ( struct V_1 * V_2 ,
struct V_759 * V_760 , int V_761 )
{
V_56 -> V_763 ( V_2 , V_760 , V_761 ) ;
}
T_4 F_304 ( struct V_1 * V_2 , T_4 V_379 , T_1 V_76 )
{
T_4 V_764 ;
struct V_58 V_49 ;
F_305 ( ! F_31 ( V_2 ) ) ;
V_76 |= V_92 ;
V_764 = V_2 -> V_5 . V_67 . V_765 ( V_2 , V_379 , V_76 , & V_49 ) ;
return V_764 ;
}
T_4 F_306 ( struct V_1 * V_2 , T_13 V_766 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return V_2 -> V_5 . V_84 -> V_765 ( V_2 , V_766 , V_76 , V_49 ) ;
}
T_4 F_307 ( struct V_1 * V_2 , T_13 V_766 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
V_76 |= V_767 ;
return V_2 -> V_5 . V_84 -> V_765 ( V_2 , V_766 , V_76 , V_49 ) ;
}
T_4 F_308 ( struct V_1 * V_2 , T_13 V_766 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
V_76 |= V_93 ;
return V_2 -> V_5 . V_84 -> V_765 ( V_2 , V_766 , V_76 , V_49 ) ;
}
T_4 F_309 ( struct V_1 * V_2 , T_13 V_766 ,
struct V_58 * V_49 )
{
return V_2 -> V_5 . V_84 -> V_765 ( V_2 , V_766 , 0 , V_49 ) ;
}
static int F_310 ( T_13 V_364 , void * V_156 , unsigned int V_768 ,
struct V_1 * V_2 , T_1 V_76 ,
struct V_58 * V_49 )
{
void * V_31 = V_156 ;
int V_100 = V_769 ;
while ( V_768 ) {
T_4 V_379 = V_2 -> V_5 . V_84 -> V_765 ( V_2 , V_364 , V_76 ,
V_49 ) ;
unsigned V_74 = V_364 & ( V_88 - 1 ) ;
unsigned V_770 = F_295 ( V_768 , ( unsigned ) V_88 - V_74 ) ;
int V_89 ;
if ( V_379 == V_80 )
return V_771 ;
V_89 = F_97 ( V_2 -> V_82 , V_379 , V_31 , V_770 ) ;
if ( V_89 < 0 ) {
V_100 = V_772 ;
goto V_94;
}
V_768 -= V_770 ;
V_31 += V_770 ;
V_364 += V_770 ;
}
V_94:
return V_100 ;
}
static int F_311 ( struct V_773 * V_774 ,
T_13 V_364 , void * V_156 , unsigned int V_768 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return F_310 ( V_364 , V_156 , V_768 , V_2 ,
V_76 | V_767 ,
V_49 ) ;
}
int F_313 ( struct V_773 * V_774 ,
T_13 V_364 , void * V_156 , unsigned int V_768 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return F_310 ( V_364 , V_156 , V_768 , V_2 , V_76 ,
V_49 ) ;
}
static int F_314 ( struct V_773 * V_774 ,
T_13 V_364 , void * V_156 , unsigned int V_768 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
return F_310 ( V_364 , V_156 , V_768 , V_2 , 0 , V_49 ) ;
}
int F_315 ( struct V_773 * V_774 ,
T_13 V_364 , void * V_156 ,
unsigned int V_768 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
void * V_31 = V_156 ;
int V_100 = V_769 ;
while ( V_768 ) {
T_4 V_379 = V_2 -> V_5 . V_84 -> V_765 ( V_2 , V_364 ,
V_93 ,
V_49 ) ;
unsigned V_74 = V_364 & ( V_88 - 1 ) ;
unsigned V_775 = F_295 ( V_768 , ( unsigned ) V_88 - V_74 ) ;
int V_89 ;
if ( V_379 == V_80 )
return V_771 ;
V_89 = F_98 ( V_2 -> V_82 , V_379 , V_31 , V_775 ) ;
if ( V_89 < 0 ) {
V_100 = V_772 ;
goto V_94;
}
V_768 -= V_775 ;
V_31 += V_775 ;
V_364 += V_775 ;
}
V_94:
return V_100 ;
}
static int F_316 ( struct V_1 * V_2 , unsigned long V_766 ,
T_4 * V_379 , struct V_58 * V_49 ,
bool V_776 )
{
T_1 V_76 = ( ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 )
| ( V_776 ? V_93 : 0 ) ;
if ( F_317 ( V_2 , V_766 )
&& ! F_318 ( V_2 -> V_5 . V_84 , V_2 -> V_5 . V_76 , V_76 ) ) {
* V_379 = V_2 -> V_5 . V_777 << V_87 |
( V_766 & ( V_88 - 1 ) ) ;
F_319 ( V_766 , * V_379 , V_776 , false ) ;
return 1 ;
}
* V_379 = V_2 -> V_5 . V_84 -> V_765 ( V_2 , V_766 , V_76 , V_49 ) ;
if ( * V_379 == V_80 )
return - 1 ;
if ( ( * V_379 & V_353 ) == V_778 )
return 1 ;
if ( F_320 ( V_2 , * V_379 ) ) {
F_319 ( V_766 , * V_379 , V_776 , true ) ;
return 1 ;
}
return 0 ;
}
int F_321 ( struct V_1 * V_2 , T_4 V_379 ,
const void * V_156 , int V_768 )
{
int V_89 ;
V_89 = F_98 ( V_2 -> V_82 , V_379 , V_156 , V_768 ) ;
if ( V_89 < 0 )
return 0 ;
F_322 ( V_2 , V_379 , V_156 , V_768 ) ;
return 1 ;
}
static int F_323 ( struct V_1 * V_2 , void * V_156 , int V_768 )
{
if ( V_2 -> V_779 ) {
F_301 ( V_758 , V_768 ,
V_2 -> V_780 [ 0 ] . V_379 , * ( T_2 * ) V_156 ) ;
V_2 -> V_779 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_324 ( struct V_1 * V_2 , T_4 V_379 ,
void * V_156 , int V_768 )
{
return ! F_97 ( V_2 -> V_82 , V_379 , V_156 , V_768 ) ;
}
static int F_325 ( struct V_1 * V_2 , T_4 V_379 ,
void * V_156 , int V_768 )
{
return F_321 ( V_2 , V_379 , V_156 , V_768 ) ;
}
static int F_326 ( struct V_1 * V_2 , T_4 V_379 , int V_768 , void * V_156 )
{
F_301 ( V_781 , V_768 , V_379 , * ( T_2 * ) V_156 ) ;
return F_294 ( V_2 , V_379 , V_768 , V_156 ) ;
}
static int F_327 ( struct V_1 * V_2 , T_4 V_379 ,
void * V_156 , int V_768 )
{
F_301 ( V_782 , V_768 , V_379 , 0 ) ;
return V_772 ;
}
static int F_328 ( struct V_1 * V_2 , T_4 V_379 ,
void * V_156 , int V_768 )
{
struct V_783 * V_784 = & V_2 -> V_780 [ 0 ] ;
memcpy ( V_2 -> V_785 -> V_786 . V_31 , V_784 -> V_31 , F_295 ( 8u , V_784 -> V_75 ) ) ;
return V_769 ;
}
static int F_329 ( unsigned long V_364 , void * V_156 ,
unsigned int V_768 ,
struct V_58 * V_49 ,
struct V_1 * V_2 ,
const struct V_787 * V_788 )
{
T_4 V_379 ;
int V_755 , V_89 ;
bool V_776 = V_788 -> V_776 ;
struct V_783 * V_784 ;
V_89 = F_316 ( V_2 , V_364 , & V_379 , V_49 , V_776 ) ;
if ( V_89 < 0 )
return V_771 ;
if ( V_89 )
goto V_786;
if ( V_788 -> V_789 ( V_2 , V_379 , V_156 , V_768 ) )
return V_769 ;
V_786:
V_755 = V_788 -> V_790 ( V_2 , V_379 , V_768 , V_156 ) ;
if ( V_755 == V_768 )
return V_769 ;
V_379 += V_755 ;
V_768 -= V_755 ;
V_156 += V_755 ;
F_106 ( V_2 -> V_791 >= V_792 ) ;
V_784 = & V_2 -> V_780 [ V_2 -> V_791 ++ ] ;
V_784 -> V_379 = V_379 ;
V_784 -> V_31 = V_156 ;
V_784 -> V_75 = V_768 ;
return V_769 ;
}
int F_330 ( struct V_773 * V_774 , unsigned long V_364 ,
void * V_156 , unsigned int V_768 ,
struct V_58 * V_49 ,
const struct V_787 * V_788 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
T_4 V_379 ;
int V_793 ;
if ( V_788 -> V_794 &&
V_788 -> V_794 ( V_2 , V_156 , V_768 ) )
return V_769 ;
V_2 -> V_791 = 0 ;
if ( ( ( V_364 + V_768 - 1 ) ^ V_364 ) & V_353 ) {
int V_795 ;
V_795 = - V_364 & ~ V_353 ;
V_793 = F_329 ( V_364 , V_156 , V_795 , V_49 ,
V_2 , V_788 ) ;
if ( V_793 != V_769 )
return V_793 ;
V_364 += V_795 ;
V_156 += V_795 ;
V_768 -= V_795 ;
}
V_793 = F_329 ( V_364 , V_156 , V_768 , V_49 ,
V_2 , V_788 ) ;
if ( V_793 != V_769 )
return V_793 ;
if ( ! V_2 -> V_791 )
return V_793 ;
V_379 = V_2 -> V_780 [ 0 ] . V_379 ;
V_2 -> V_796 = 1 ;
V_2 -> V_797 = 0 ;
V_2 -> V_785 -> V_786 . V_75 = F_295 ( 8u , V_2 -> V_780 [ 0 ] . V_75 ) ;
V_2 -> V_785 -> V_786 . V_798 = V_2 -> V_799 = V_788 -> V_776 ;
V_2 -> V_785 -> V_800 = V_801 ;
V_2 -> V_785 -> V_786 . V_802 = V_379 ;
return V_788 -> V_803 ( V_2 , V_379 , V_156 , V_768 ) ;
}
static int F_331 ( struct V_773 * V_774 ,
unsigned long V_364 ,
void * V_156 ,
unsigned int V_768 ,
struct V_58 * V_49 )
{
return F_330 ( V_774 , V_364 , V_156 , V_768 ,
V_49 , & V_804 ) ;
}
int F_332 ( struct V_773 * V_774 ,
unsigned long V_364 ,
const void * V_156 ,
unsigned int V_768 ,
struct V_58 * V_49 )
{
return F_330 ( V_774 , V_364 , ( void * ) V_156 , V_768 ,
V_49 , & V_805 ) ;
}
static int F_333 ( struct V_773 * V_774 ,
unsigned long V_364 ,
const void * V_806 ,
const void * V_807 ,
unsigned int V_768 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
T_4 V_379 ;
struct V_355 * V_355 ;
char * V_808 ;
bool V_809 ;
if ( V_768 > 8 || ( V_768 & ( V_768 - 1 ) ) )
goto V_810;
V_379 = F_308 ( V_2 , V_364 , NULL ) ;
if ( V_379 == V_80 ||
( V_379 & V_353 ) == V_778 )
goto V_810;
if ( ( ( V_379 + V_768 - 1 ) & V_353 ) != ( V_379 & V_353 ) )
goto V_810;
V_355 = F_183 ( V_2 -> V_82 , V_379 >> V_87 ) ;
if ( F_184 ( V_355 ) )
goto V_810;
V_808 = F_147 ( V_355 ) ;
V_808 += F_334 ( V_379 ) ;
switch ( V_768 ) {
case 1 :
V_809 = F_335 ( T_12 , V_808 , V_806 , V_807 ) ;
break;
case 2 :
V_809 = F_335 ( V_811 , V_808 , V_806 , V_807 ) ;
break;
case 4 :
V_809 = F_335 ( T_1 , V_808 , V_806 , V_807 ) ;
break;
case 8 :
V_809 = F_336 ( V_808 , V_806 , V_807 ) ;
break;
default:
F_337 () ;
}
F_148 ( V_808 ) ;
F_175 ( V_355 ) ;
if ( ! V_809 )
return V_812 ;
F_322 ( V_2 , V_379 , V_807 , V_768 ) ;
return V_769 ;
V_810:
F_338 ( V_813 L_22 ) ;
return F_332 ( V_774 , V_364 , V_807 , V_768 , V_49 ) ;
}
static int F_339 ( struct V_1 * V_2 , void * V_814 )
{
int V_100 ;
if ( V_2 -> V_5 . V_815 . V_816 )
V_100 = F_300 ( V_2 -> V_82 , V_726 , V_2 -> V_5 . V_815 . V_817 ,
V_2 -> V_5 . V_815 . V_475 , V_814 ) ;
else
V_100 = F_297 ( V_2 -> V_82 , V_726 ,
V_2 -> V_5 . V_815 . V_817 , V_2 -> V_5 . V_815 . V_475 ,
V_814 ) ;
return V_100 ;
}
static int F_340 ( struct V_1 * V_2 , int V_475 ,
unsigned short V_817 , void * V_156 ,
unsigned int V_691 , bool V_816 )
{
F_341 ( ! V_816 , V_817 , V_475 , V_691 ) ;
V_2 -> V_5 . V_815 . V_817 = V_817 ;
V_2 -> V_5 . V_815 . V_816 = V_816 ;
V_2 -> V_5 . V_815 . V_691 = V_691 ;
V_2 -> V_5 . V_815 . V_475 = V_475 ;
if ( ! F_339 ( V_2 , V_2 -> V_5 . V_818 ) ) {
V_2 -> V_5 . V_815 . V_691 = 0 ;
return 1 ;
}
V_2 -> V_785 -> V_800 = V_819 ;
V_2 -> V_785 -> V_820 . V_821 = V_816 ? V_822 : V_823 ;
V_2 -> V_785 -> V_820 . V_475 = V_475 ;
V_2 -> V_785 -> V_820 . V_824 = V_825 * V_88 ;
V_2 -> V_785 -> V_820 . V_691 = V_691 ;
V_2 -> V_785 -> V_820 . V_817 = V_817 ;
return 0 ;
}
static int F_342 ( struct V_773 * V_774 ,
int V_475 , unsigned short V_817 , void * V_156 ,
unsigned int V_691 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
int V_89 ;
if ( V_2 -> V_5 . V_815 . V_691 )
goto V_826;
V_89 = F_340 ( V_2 , V_475 , V_817 , V_156 , V_691 , true ) ;
if ( V_89 ) {
V_826:
memcpy ( V_156 , V_2 -> V_5 . V_818 , V_475 * V_691 ) ;
V_2 -> V_5 . V_815 . V_691 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_343 ( struct V_773 * V_774 ,
int V_475 , unsigned short V_817 ,
const void * V_156 , unsigned int V_691 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
memcpy ( V_2 -> V_5 . V_818 , V_156 , V_475 * V_691 ) ;
return F_340 ( V_2 , V_475 , V_817 , ( void * ) V_156 , V_691 , false ) ;
}
static unsigned long F_344 ( struct V_1 * V_2 , int V_761 )
{
return V_56 -> F_344 ( V_2 , V_761 ) ;
}
static void F_345 ( struct V_773 * V_774 , V_144 V_63 )
{
F_346 ( F_312 ( V_774 ) , V_63 ) ;
}
int F_347 ( struct V_1 * V_2 )
{
if ( ! F_219 ( V_2 ) )
return V_769 ;
if ( V_56 -> V_558 () ) {
int V_23 = F_348 () ;
F_221 ( V_23 , V_2 -> V_5 . V_559 ) ;
F_349 ( V_2 -> V_5 . V_559 ,
F_217 , NULL , 1 ) ;
F_350 () ;
F_351 ( V_2 -> V_5 . V_559 ) ;
} else
F_218 () ;
return V_769 ;
}
static void F_352 ( struct V_773 * V_774 )
{
F_347 ( F_312 ( V_774 ) ) ;
}
int F_353 ( struct V_773 * V_774 , int V_155 , unsigned long * V_827 )
{
return F_81 ( F_312 ( V_774 ) , V_155 , V_827 ) ;
}
int F_354 ( struct V_773 * V_774 , int V_155 , unsigned long V_22 )
{
return F_79 ( F_312 ( V_774 ) , V_155 , V_22 ) ;
}
static T_2 F_355 ( T_2 V_828 , T_1 V_829 )
{
return ( V_828 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_829 ;
}
static unsigned long F_356 ( struct V_773 * V_774 , int V_830 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
unsigned long V_22 ;
switch ( V_830 ) {
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
F_357 ( L_23 , V_227 , V_830 ) ;
return 0 ;
}
return V_22 ;
}
static int F_358 ( struct V_773 * V_774 , int V_830 , V_144 V_156 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
int V_165 = 0 ;
switch ( V_830 ) {
case 0 :
V_165 = F_50 ( V_2 , F_355 ( F_51 ( V_2 ) , V_156 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_62 = V_156 ;
break;
case 3 :
V_165 = F_68 ( V_2 , V_156 ) ;
break;
case 4 :
V_165 = F_61 ( V_2 , F_355 ( F_62 ( V_2 ) , V_156 ) ) ;
break;
case 8 :
V_165 = F_73 ( V_2 , V_156 ) ;
break;
default:
F_357 ( L_23 , V_227 , V_830 ) ;
V_165 = - 1 ;
}
return V_165 ;
}
static void F_359 ( struct V_773 * V_774 , V_144 V_156 )
{
F_360 ( F_312 ( V_774 ) , V_156 ) ;
}
static int F_361 ( struct V_773 * V_774 )
{
return V_56 -> V_71 ( F_312 ( V_774 ) ) ;
}
static void F_362 ( struct V_773 * V_774 , struct V_831 * V_832 )
{
V_56 -> V_833 ( F_312 ( V_774 ) , V_832 ) ;
}
static void F_363 ( struct V_773 * V_774 , struct V_831 * V_832 )
{
V_56 -> V_834 ( F_312 ( V_774 ) , V_832 ) ;
}
static void F_364 ( struct V_773 * V_774 , struct V_831 * V_832 )
{
V_56 -> V_835 ( F_312 ( V_774 ) , V_832 ) ;
}
static void F_365 ( struct V_773 * V_774 , struct V_831 * V_832 )
{
V_56 -> V_836 ( F_312 ( V_774 ) , V_832 ) ;
}
static unsigned long F_366 (
struct V_773 * V_774 , int V_761 )
{
return F_344 ( F_312 ( V_774 ) , V_761 ) ;
}
static bool F_367 ( struct V_773 * V_774 , V_811 * V_837 ,
struct V_838 * V_839 , T_1 * V_840 ,
int V_761 )
{
struct V_759 V_760 ;
F_303 ( F_312 ( V_774 ) , & V_760 , V_761 ) ;
* V_837 = V_760 . V_837 ;
if ( V_760 . V_841 )
return false ;
if ( V_760 . V_842 )
V_760 . V_843 >>= 12 ;
F_368 ( V_839 , V_760 . V_843 ) ;
F_369 ( V_839 , ( unsigned long ) V_760 . V_844 ) ;
#ifdef F_52
if ( V_840 )
* V_840 = V_760 . V_844 >> 32 ;
#endif
V_839 -> type = V_760 . type ;
V_839 -> V_567 = V_760 . V_567 ;
V_839 -> V_845 = V_760 . V_845 ;
V_839 -> V_324 = V_760 . V_846 ;
V_839 -> V_847 = V_760 . V_847 ;
V_839 -> V_848 = V_760 . V_848 ;
V_839 -> V_849 = V_760 . V_157 ;
V_839 -> V_842 = V_760 . V_842 ;
return true ;
}
static void F_370 ( struct V_773 * V_774 , V_811 V_837 ,
struct V_838 * V_839 , T_1 V_840 ,
int V_761 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
struct V_759 V_760 ;
V_760 . V_837 = V_837 ;
V_760 . V_844 = F_371 ( V_839 ) ;
#ifdef F_52
V_760 . V_844 |= ( ( T_2 ) V_840 ) << 32 ;
#endif
V_760 . V_843 = F_372 ( V_839 ) ;
if ( V_839 -> V_842 )
V_760 . V_843 = ( V_760 . V_843 << 12 ) | 0xfff ;
V_760 . type = V_839 -> type ;
V_760 . V_846 = V_839 -> V_324 ;
V_760 . V_845 = V_839 -> V_845 ;
V_760 . V_157 = V_839 -> V_849 ;
V_760 . V_567 = V_839 -> V_567 ;
V_760 . V_848 = V_839 -> V_848 ;
V_760 . V_842 = V_839 -> V_842 ;
V_760 . V_847 = V_839 -> V_847 ;
V_760 . V_846 = V_839 -> V_324 ;
V_760 . V_841 = ! V_760 . V_846 ;
V_760 . V_850 = 0 ;
F_302 ( V_2 , & V_760 , V_761 ) ;
return;
}
static int F_373 ( struct V_773 * V_774 ,
T_1 V_448 , T_2 * V_449 )
{
return F_194 ( F_312 ( V_774 ) , V_448 , V_449 ) ;
}
static int F_374 ( struct V_773 * V_774 ,
T_1 V_448 , T_2 V_31 )
{
struct V_185 V_21 ;
V_21 . V_31 = V_31 ;
V_21 . V_119 = V_448 ;
V_21 . V_187 = false ;
return F_91 ( F_312 ( V_774 ) , & V_21 ) ;
}
static int F_375 ( struct V_773 * V_774 ,
T_1 V_851 , T_2 * V_449 )
{
return F_85 ( F_312 ( V_774 ) , V_851 , V_449 ) ;
}
static void F_376 ( struct V_773 * V_774 )
{
F_312 ( V_774 ) -> V_5 . V_852 = 1 ;
}
static void F_377 ( struct V_773 * V_774 )
{
F_186 () ;
F_378 ( F_312 ( V_774 ) ) ;
F_379 () ;
}
static void F_380 ( struct V_773 * V_774 )
{
F_187 () ;
}
static int F_381 ( struct V_773 * V_774 ,
struct V_853 * V_854 ,
enum V_855 V_856 )
{
return V_56 -> V_857 ( F_312 ( V_774 ) , V_854 , V_856 ) ;
}
static void F_382 ( struct V_773 * V_774 ,
T_1 * V_858 , T_1 * V_859 , T_1 * V_167 , T_1 * V_176 )
{
V_639 ( F_312 ( V_774 ) , V_858 , V_859 , V_167 , V_176 ) ;
}
static V_144 F_383 ( struct V_773 * V_774 , unsigned V_860 )
{
return F_84 ( F_312 ( V_774 ) , V_860 ) ;
}
static void F_384 ( struct V_773 * V_774 , unsigned V_860 , V_144 V_156 )
{
F_86 ( F_312 ( V_774 ) , V_860 , V_156 ) ;
}
static void F_385 ( struct V_1 * V_2 , T_1 V_27 )
{
T_1 V_861 = V_56 -> V_595 ( V_2 , V_27 ) ;
if ( ! ( V_861 & V_27 ) )
V_56 -> V_608 ( V_2 , V_27 ) ;
}
static void F_386 ( struct V_1 * V_2 )
{
struct V_773 * V_774 = & V_2 -> V_5 . V_862 ;
if ( V_774 -> V_49 . V_32 == V_33 )
F_30 ( V_2 , & V_774 -> V_49 ) ;
else if ( V_774 -> V_49 . V_863 )
F_29 ( V_2 , V_774 -> V_49 . V_32 ,
V_774 -> V_49 . V_43 ) ;
else
F_24 ( V_2 , V_774 -> V_49 . V_32 ) ;
}
static void F_387 ( struct V_773 * V_774 )
{
memset ( & V_774 -> V_864 , 0 ,
( void * ) & V_774 -> V_865 - ( void * ) & V_774 -> V_864 ) ;
V_774 -> V_866 . V_693 = 0 ;
V_774 -> V_866 . V_867 = 0 ;
V_774 -> V_868 . V_869 = 0 ;
V_774 -> V_868 . V_867 = 0 ;
V_774 -> V_870 . V_869 = 0 ;
V_774 -> V_870 . V_867 = 0 ;
}
static void F_388 ( struct V_1 * V_2 )
{
struct V_773 * V_774 = & V_2 -> V_5 . V_862 ;
int V_113 , V_114 ;
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
V_774 -> V_871 = F_389 ( V_2 ) ;
V_774 -> V_872 = F_390 ( V_2 ) ;
V_774 -> V_283 = ( ! F_391 ( V_2 ) ) ? V_873 :
( V_774 -> V_871 & V_874 ) ? V_875 :
V_114 ? V_876 :
V_113 ? V_877 :
V_878 ;
V_774 -> V_879 = F_392 ( V_2 ) ;
F_387 ( V_774 ) ;
V_2 -> V_5 . V_880 = false ;
}
int F_393 ( struct V_1 * V_2 , int V_571 , int V_881 )
{
struct V_773 * V_774 = & V_2 -> V_5 . V_862 ;
int V_89 ;
F_388 ( V_2 ) ;
V_774 -> V_882 = 2 ;
V_774 -> V_883 = 2 ;
V_774 -> V_884 = V_774 -> V_872 + V_881 ;
V_89 = F_394 ( V_774 , V_571 ) ;
if ( V_89 != V_769 )
return V_885 ;
V_774 -> V_872 = V_774 -> V_884 ;
F_395 ( V_2 , V_774 -> V_872 ) ;
F_360 ( V_2 , V_774 -> V_871 ) ;
if ( V_571 == V_886 )
V_2 -> V_5 . V_600 = 0 ;
else
V_2 -> V_5 . V_592 . V_50 = false ;
return V_887 ;
}
static int F_396 ( struct V_1 * V_2 )
{
int V_100 = V_887 ;
++ V_2 -> V_60 . V_888 ;
F_397 ( V_2 ) ;
if ( ! F_392 ( V_2 ) ) {
V_2 -> V_785 -> V_800 = V_889 ;
V_2 -> V_785 -> V_890 . V_891 = V_892 ;
V_2 -> V_785 -> V_890 . V_893 = 0 ;
V_100 = V_885 ;
}
F_24 ( V_2 , V_166 ) ;
return V_100 ;
}
static bool F_398 ( struct V_1 * V_2 , T_13 V_766 )
{
T_4 V_379 ;
T_14 V_894 ;
if ( V_184 )
return false ;
if ( F_399 ( V_2 , V_766 ) )
return true ;
V_379 = F_309 ( V_2 , V_766 , NULL ) ;
if ( V_379 == V_80 )
return true ;
V_894 = F_400 ( V_2 -> V_82 , F_38 ( V_379 ) ) ;
if ( ! F_401 ( V_894 ) ) {
F_402 ( V_894 ) ;
return true ;
}
return false ;
}
static bool F_403 ( struct V_773 * V_774 ,
unsigned long V_62 , int V_895 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
unsigned long V_896 , V_897 , V_379 = V_62 ;
V_896 = V_2 -> V_5 . V_896 ;
V_897 = V_2 -> V_5 . V_897 ;
V_2 -> V_5 . V_896 = V_2 -> V_5 . V_897 = 0 ;
if ( ! ( V_895 & V_898 ) )
return false ;
if ( F_404 ( V_774 ) )
return false ;
if ( V_774 -> V_872 == V_896 && V_897 == V_62 )
return false ;
V_2 -> V_5 . V_896 = V_774 -> V_872 ;
V_2 -> V_5 . V_897 = V_62 ;
if ( ! V_2 -> V_5 . V_67 . V_899 )
V_379 = F_308 ( V_2 , V_62 , NULL ) ;
F_405 ( V_2 -> V_82 , V_379 >> V_87 ) ;
return true ;
}
int F_406 ( struct V_1 * V_2 ,
unsigned long V_62 ,
int V_895 ,
void * V_900 ,
int V_901 )
{
int V_100 ;
struct V_773 * V_774 = & V_2 -> V_5 . V_862 ;
bool V_473 = true ;
F_407 ( V_2 ) ;
if ( ! ( V_895 & V_902 ) ) {
F_388 ( V_2 ) ;
V_774 -> V_903 = 0 ;
V_774 -> V_904 = false ;
V_774 -> V_905 = false ;
V_774 -> V_906
= V_895 & V_907 ;
V_100 = F_408 ( V_774 , V_900 , V_901 ) ;
F_409 ( V_2 ) ;
++ V_2 -> V_60 . V_908 ;
if ( V_100 != V_909 ) {
if ( V_895 & V_907 )
return V_885 ;
if ( F_398 ( V_2 , V_62 ) )
return V_887 ;
if ( V_895 & V_910 )
return V_885 ;
return F_396 ( V_2 ) ;
}
}
if ( V_895 & V_910 ) {
F_395 ( V_2 , V_774 -> V_884 ) ;
return V_887 ;
}
if ( F_403 ( V_774 , V_62 , V_895 ) )
return V_887 ;
if ( V_2 -> V_5 . V_880 ) {
V_2 -> V_5 . V_880 = false ;
F_410 ( V_774 ) ;
}
V_911:
V_100 = F_411 ( V_774 ) ;
if ( V_100 == V_912 )
return V_887 ;
if ( V_100 == V_913 ) {
if ( F_398 ( V_2 , V_62 ) )
return V_887 ;
return F_396 ( V_2 ) ;
}
if ( V_774 -> V_904 ) {
F_386 ( V_2 ) ;
V_100 = V_887 ;
} else if ( V_2 -> V_5 . V_815 . V_691 ) {
if ( ! V_2 -> V_5 . V_815 . V_816 )
V_2 -> V_5 . V_815 . V_691 = 0 ;
else {
V_473 = false ;
V_2 -> V_5 . V_914 = V_915 ;
}
V_100 = V_916 ;
} else if ( V_2 -> V_796 ) {
if ( ! V_2 -> V_799 )
V_473 = false ;
V_100 = V_916 ;
V_2 -> V_5 . V_914 = V_917 ;
} else if ( V_100 == V_918 )
goto V_911;
else
V_100 = V_887 ;
if ( V_473 ) {
F_385 ( V_2 , V_774 -> V_903 ) ;
F_360 ( V_2 , V_774 -> V_871 ) ;
F_23 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_919 = false ;
F_395 ( V_2 , V_774 -> V_872 ) ;
} else
V_2 -> V_5 . V_919 = true ;
return V_100 ;
}
int F_412 ( struct V_1 * V_2 , int V_475 , unsigned short V_817 )
{
unsigned long V_156 = F_84 ( V_2 , V_169 ) ;
int V_89 = F_343 ( & V_2 -> V_5 . V_862 ,
V_475 , V_817 , & V_156 , 1 ) ;
V_2 -> V_5 . V_815 . V_691 = 0 ;
return V_89 ;
}
static void F_413 ( void * V_854 )
{
F_414 ( V_295 , 0 ) ;
}
static void F_415 ( void * V_31 )
{
struct V_920 * V_921 = V_31 ;
unsigned long V_230 = 0 ;
if ( V_31 )
V_230 = V_921 -> V_807 ;
else if ( ! F_214 ( V_922 ) )
V_230 = F_416 ( F_417 () ) ;
if ( ! V_230 )
V_230 = V_238 ;
F_414 ( V_295 , V_230 ) ;
}
static int F_418 ( struct V_923 * V_924 , unsigned long V_156 ,
void * V_31 )
{
struct V_920 * V_921 = V_31 ;
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 , V_925 = 0 ;
if ( V_156 == V_926 && V_921 -> V_806 > V_921 -> V_807 )
return 0 ;
if ( V_156 == V_927 && V_921 -> V_806 < V_921 -> V_807 )
return 0 ;
F_222 ( V_921 -> V_23 , F_415 , V_921 , 1 ) ;
F_419 ( & V_928 ) ;
F_420 (kvm, &vm_list, vm_list) {
F_199 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_921 -> V_23 )
continue;
F_23 ( V_296 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_925 = 1 ;
}
}
F_421 ( & V_928 ) ;
if ( V_921 -> V_806 < V_921 -> V_807 && V_925 ) {
F_222 ( V_921 -> V_23 , F_415 , V_921 , 1 ) ;
}
return 0 ;
}
static int F_422 ( struct V_923 * V_929 ,
unsigned long V_930 , void * V_931 )
{
unsigned int V_23 = ( unsigned long ) V_931 ;
switch ( V_930 ) {
case V_932 :
case V_933 :
F_222 ( V_23 , F_415 , NULL , 1 ) ;
break;
case V_934 :
F_222 ( V_23 , F_413 , NULL , 1 ) ;
break;
}
return V_935 ;
}
static void F_423 ( void )
{
int V_23 ;
V_936 = V_238 ;
F_424 ( & V_937 ) ;
if ( ! F_214 ( V_922 ) ) {
#ifdef F_425
struct V_938 V_939 ;
memset ( & V_939 , 0 , sizeof( V_939 ) ) ;
V_23 = F_348 () ;
F_426 ( & V_939 , V_23 ) ;
if ( V_939 . V_940 . V_941 )
V_936 = V_939 . V_940 . V_941 ;
F_350 () ;
#endif
F_427 ( & V_942 ,
V_943 ) ;
}
F_104 ( L_24 , V_936 ) ;
F_428 (cpu)
F_222 ( V_23 , F_415 , NULL , 1 ) ;
}
int F_429 ( void )
{
return F_430 ( V_944 ) != NULL ;
}
static int F_431 ( void )
{
int V_945 = 3 ;
if ( F_430 ( V_944 ) )
V_945 = V_56 -> V_71 ( F_430 ( V_944 ) ) ;
return V_945 != 0 ;
}
static unsigned long F_432 ( void )
{
unsigned long V_946 = 0 ;
if ( F_430 ( V_944 ) )
V_946 = F_390 ( F_430 ( V_944 ) ) ;
return V_946 ;
}
void F_433 ( struct V_1 * V_2 )
{
F_414 ( V_944 , V_2 ) ;
}
void F_434 ( struct V_1 * V_2 )
{
F_414 ( V_944 , NULL ) ;
}
static void F_435 ( void )
{
T_2 V_27 ;
int V_947 = V_948 . V_949 ;
V_27 = ( ( 1ull << ( 62 - V_947 + 1 ) ) - 1 ) << V_947 ;
V_27 |= 1ull ;
#ifdef F_52
if ( V_947 == 52 )
V_27 &= ~ 1ull ;
#endif
F_436 ( V_27 ) ;
}
static void F_437 ( struct V_950 * V_951 )
{
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 ;
F_419 ( & V_928 ) ;
F_420 (kvm, &vm_list, vm_list)
F_199 (i, vcpu, kvm)
F_224 ( V_254 , & V_2 -> V_562 ) ;
F_139 ( & V_287 , 0 ) ;
F_421 ( & V_928 ) ;
}
static int F_438 ( struct V_923 * V_924 , unsigned long V_952 ,
void * V_953 )
{
struct V_190 * V_249 = & V_190 ;
struct V_188 * V_189 = V_953 ;
F_93 ( V_189 ) ;
if ( V_249 -> clock . V_193 != V_252 &&
F_118 ( & V_287 ) != 0 )
F_439 ( V_954 , & V_955 ) ;
return 0 ;
}
int F_440 ( void * V_956 )
{
int V_100 ;
struct V_56 * V_788 = (struct V_56 * ) V_956 ;
if ( V_56 ) {
F_10 ( V_26 L_25 ) ;
V_100 = - V_724 ;
goto V_94;
}
if ( ! V_788 -> V_957 () ) {
F_10 ( V_26 L_26 ) ;
V_100 = - V_958 ;
goto V_94;
}
if ( V_788 -> V_959 () ) {
F_10 ( V_26 L_27 ) ;
V_100 = - V_958 ;
goto V_94;
}
V_100 = - V_357 ;
V_25 = F_441 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_94;
}
V_100 = F_442 () ;
if ( V_100 )
goto V_960;
F_435 () ;
F_292 () ;
V_56 = V_788 ;
F_443 ( V_961 , V_962 ,
V_963 , V_964 , 0 ) ;
F_423 () ;
F_444 ( & V_965 ) ;
if ( V_528 )
V_126 = F_445 ( V_122 ) ;
F_446 () ;
#ifdef F_52
F_447 ( & V_966 ) ;
#endif
return 0 ;
V_960:
F_448 ( V_25 ) ;
V_94:
return V_100 ;
}
void F_449 ( void )
{
F_450 ( & V_965 ) ;
if ( ! F_214 ( V_922 ) )
F_451 ( & V_942 ,
V_943 ) ;
F_452 ( & V_937 ) ;
#ifdef F_52
F_453 ( & V_966 ) ;
#endif
V_56 = NULL ;
F_454 () ;
F_448 ( V_25 ) ;
}
int F_455 ( struct V_1 * V_2 )
{
++ V_2 -> V_60 . V_967 ;
if ( F_74 ( V_2 -> V_82 ) ) {
V_2 -> V_5 . V_968 = V_969 ;
return 1 ;
} else {
V_2 -> V_785 -> V_800 = V_970 ;
return 0 ;
}
}
int F_456 ( struct V_1 * V_2 )
{
T_2 V_971 , V_972 , V_973 , V_89 ;
T_15 V_974 , V_975 , V_976 , V_165 = V_977 , V_978 = 0 ;
bool V_979 , V_980 ;
int V_113 , V_114 ;
if ( V_56 -> V_71 ( V_2 ) != 0 || ! F_391 ( V_2 ) ) {
F_24 ( V_2 , V_166 ) ;
return 0 ;
}
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
V_980 = F_46 ( V_2 ) && V_114 == 1 ;
if ( ! V_980 ) {
V_971 = ( ( T_2 ) F_84 ( V_2 , V_170 ) << 32 ) |
( F_84 ( V_2 , V_169 ) & 0xffffffff ) ;
V_972 = ( ( T_2 ) F_84 ( V_2 , V_981 ) << 32 ) |
( F_84 ( V_2 , V_168 ) & 0xffffffff ) ;
V_973 = ( ( T_2 ) F_84 ( V_2 , V_982 ) << 32 ) |
( F_84 ( V_2 , V_983 ) & 0xffffffff ) ;
}
#ifdef F_52
else {
V_971 = F_84 ( V_2 , V_168 ) ;
V_972 = F_84 ( V_2 , V_170 ) ;
V_973 = F_84 ( V_2 , V_984 ) ;
}
#endif
V_974 = V_971 & 0xffff ;
V_979 = ( V_971 >> 16 ) & 0x1 ;
V_976 = ( V_971 >> 32 ) & 0xfff ;
V_975 = ( V_971 >> 48 ) & 0xfff ;
F_457 ( V_974 , V_979 , V_976 , V_975 , V_972 , V_973 ) ;
switch ( V_974 ) {
case V_985 :
F_458 ( V_2 ) ;
break;
default:
V_165 = V_986 ;
break;
}
V_89 = V_165 | ( ( ( T_2 ) V_978 & 0xfff ) << 32 ) ;
if ( V_980 ) {
F_86 ( V_2 , V_169 , V_89 ) ;
} else {
F_86 ( V_2 , V_170 , V_89 >> 32 ) ;
F_86 ( V_2 , V_169 , V_89 & 0xffffffff ) ;
}
return 1 ;
}
int F_459 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_987 , V_988 , V_989 , V_990 , V_89 ;
int V_100 = 1 ;
if ( F_161 ( V_2 -> V_82 ) )
return F_456 ( V_2 ) ;
V_16 = F_84 ( V_2 , V_169 ) ;
V_987 = F_84 ( V_2 , V_981 ) ;
V_988 = F_84 ( V_2 , V_168 ) ;
V_989 = F_84 ( V_2 , V_170 ) ;
V_990 = F_84 ( V_2 , V_983 ) ;
F_460 ( V_16 , V_987 , V_988 , V_989 , V_990 ) ;
if ( ! F_46 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_987 &= 0xFFFFFFFF ;
V_988 &= 0xFFFFFFFF ;
V_989 &= 0xFFFFFFFF ;
V_990 &= 0xFFFFFFFF ;
}
if ( V_56 -> V_71 ( V_2 ) != 0 ) {
V_89 = - V_991 ;
goto V_94;
}
switch ( V_16 ) {
case V_992 :
V_89 = 0 ;
break;
default:
V_89 = - V_993 ;
break;
}
V_94:
F_86 ( V_2 , V_169 , V_89 ) ;
++ V_2 -> V_60 . V_994 ;
return V_100 ;
}
static int F_461 ( struct V_773 * V_774 )
{
struct V_1 * V_2 = F_312 ( V_774 ) ;
char V_995 [ 3 ] ;
unsigned long V_996 = F_390 ( V_2 ) ;
F_462 ( V_2 -> V_82 ) ;
V_56 -> V_367 ( V_2 , V_995 ) ;
return F_332 ( V_774 , V_996 , V_995 , 3 , NULL ) ;
}
static int F_463 ( struct V_1 * V_2 )
{
return ( ! F_74 ( V_2 -> V_82 ) && ! F_464 ( V_2 ) &&
V_2 -> V_785 -> V_997 &&
F_465 ( V_2 ) ) ;
}
static void F_466 ( struct V_1 * V_2 )
{
struct V_998 * V_998 = V_2 -> V_785 ;
V_998 -> V_999 = ( F_389 ( V_2 ) & V_1000 ) != 0 ;
V_998 -> V_146 = F_76 ( V_2 ) ;
V_998 -> V_30 = F_18 ( V_2 ) ;
if ( F_74 ( V_2 -> V_82 ) )
V_998 -> V_1001 = 1 ;
else
V_998 -> V_1001 =
F_465 ( V_2 ) &&
! F_464 ( V_2 ) &&
! F_467 ( V_2 ) ;
}
static int F_468 ( struct V_1 * V_2 )
{
struct V_1002 * V_569 = V_2 -> V_5 . V_569 ;
struct V_355 * V_355 ;
if ( ! V_569 || ! V_569 -> V_648 )
return 0 ;
V_355 = F_183 ( V_2 -> V_82 , V_569 -> V_648 >> V_87 ) ;
if ( F_184 ( V_355 ) )
return - V_81 ;
V_2 -> V_5 . V_569 -> V_1003 = V_355 ;
return 0 ;
}
static void F_469 ( struct V_1 * V_2 )
{
struct V_1002 * V_569 = V_2 -> V_5 . V_569 ;
int V_330 ;
if ( ! V_569 || ! V_569 -> V_648 )
return;
V_330 = F_207 ( & V_2 -> V_82 -> V_470 ) ;
F_175 ( V_569 -> V_1003 ) ;
F_149 ( V_2 -> V_82 , V_569 -> V_648 >> V_87 ) ;
F_208 ( & V_2 -> V_82 -> V_470 , V_330 ) ;
}
static void F_232 ( struct V_1 * V_2 )
{
int V_1004 , V_1005 ;
if ( ! V_56 -> F_232 )
return;
if ( ! V_2 -> V_5 . V_569 )
return;
if ( ! V_2 -> V_5 . V_569 -> V_648 )
V_1004 = F_470 ( V_2 ) ;
else
V_1004 = - 1 ;
if ( V_1004 != - 1 )
V_1004 >>= 4 ;
V_1005 = F_77 ( V_2 ) ;
V_56 -> F_232 ( V_2 , V_1005 , V_1004 ) ;
}
static void F_471 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_49 . V_50 ) {
F_472 ( V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ) ;
V_56 -> V_1006 ( V_2 , V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ,
V_2 -> V_5 . V_49 . V_44 ) ;
return;
}
if ( V_2 -> V_5 . V_599 ) {
V_56 -> V_1007 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_592 . V_50 ) {
V_56 -> V_1008 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_600 ) {
if ( V_56 -> V_1009 ( V_2 ) ) {
-- V_2 -> V_5 . V_600 ;
V_2 -> V_5 . V_599 = true ;
V_56 -> V_1007 ( V_2 ) ;
}
} else if ( F_464 ( V_2 ) ) {
if ( V_56 -> V_1010 ( V_2 ) ) {
F_234 ( V_2 , F_473 ( V_2 ) ,
false ) ;
V_56 -> V_1008 ( V_2 ) ;
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
static void F_240 ( struct V_1 * V_2 )
{
unsigned V_843 = 2 ;
if ( V_56 -> V_602 ( V_2 ) || V_2 -> V_5 . V_599 )
V_843 = 1 ;
V_2 -> V_5 . V_600 += F_477 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_600 = F_295 ( V_2 -> V_5 . V_600 , V_843 ) ;
F_23 ( V_48 , V_2 ) ;
}
static void F_478 ( struct V_82 * V_82 )
{
#ifdef F_52
int V_3 ;
struct V_1 * V_2 ;
struct V_247 * V_248 = & V_82 -> V_5 ;
F_126 ( & V_248 -> V_280 ) ;
F_479 ( V_82 ) ;
F_138 ( V_82 ) ;
F_199 (i, vcpu, kvm)
F_224 ( V_296 , & V_2 -> V_562 ) ;
F_199 (i, vcpu, kvm)
F_480 ( V_1011 , & V_2 -> V_562 ) ;
F_127 ( & V_248 -> V_280 ) ;
#endif
}
static int F_481 ( struct V_1 * V_2 )
{
int V_100 ;
bool V_1012 = ! F_74 ( V_2 -> V_82 ) &&
V_2 -> V_785 -> V_997 ;
bool V_1013 = 0 ;
if ( V_2 -> V_562 ) {
if ( F_482 ( V_1014 , V_2 ) )
F_483 ( V_2 ) ;
if ( F_482 ( V_1015 , V_2 ) )
F_484 ( V_2 ) ;
if ( F_482 ( V_254 , V_2 ) )
F_478 ( V_2 -> V_82 ) ;
if ( F_482 ( V_296 , V_2 ) ) {
V_100 = F_141 ( V_2 ) ;
if ( F_71 ( V_100 ) )
goto V_94;
}
if ( F_482 ( V_1016 , V_2 ) )
F_69 ( V_2 ) ;
if ( F_482 ( V_1017 , V_2 ) )
V_56 -> V_1018 ( V_2 ) ;
if ( F_482 ( V_1019 , V_2 ) ) {
V_2 -> V_785 -> V_800 = V_1020 ;
V_100 = 0 ;
goto V_94;
}
if ( F_482 ( V_54 , V_2 ) ) {
V_2 -> V_785 -> V_800 = V_1021 ;
V_100 = 0 ;
goto V_94;
}
if ( F_482 ( V_1022 , V_2 ) ) {
V_2 -> V_1023 = 0 ;
V_56 -> V_1024 ( V_2 ) ;
}
if ( F_482 ( V_1025 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1026 = true ;
V_100 = 1 ;
goto V_94;
}
if ( F_482 ( V_423 , V_2 ) )
F_177 ( V_2 ) ;
if ( F_482 ( V_69 , V_2 ) )
F_240 ( V_2 ) ;
V_1013 =
F_482 ( V_1027 , V_2 ) ;
if ( F_482 ( V_1028 , V_2 ) )
F_485 ( V_2 ) ;
if ( F_482 ( V_1029 , V_2 ) )
F_486 ( V_2 ) ;
}
if ( F_482 ( V_48 , V_2 ) || V_1012 ) {
F_471 ( V_2 ) ;
if ( V_2 -> V_5 . V_600 )
V_56 -> V_1030 ( V_2 ) ;
else if ( F_464 ( V_2 ) || V_1012 )
V_56 -> V_1031 ( V_2 ) ;
if ( F_487 ( V_2 ) ) {
F_232 ( V_2 ) ;
F_488 ( V_2 ) ;
}
}
V_100 = F_489 ( V_2 ) ;
if ( F_71 ( V_100 ) ) {
goto V_1032;
}
F_186 () ;
V_56 -> V_1033 ( V_2 ) ;
if ( V_2 -> V_1023 )
F_378 ( V_2 ) ;
F_474 ( V_2 ) ;
V_2 -> V_283 = V_1034 ;
F_490 () ;
F_290 () ;
if ( V_2 -> V_283 == V_1035 || V_2 -> V_562
|| F_491 () || F_492 ( V_386 ) ) {
V_2 -> V_283 = V_1036 ;
F_13 () ;
F_291 () ;
F_187 () ;
V_100 = 1 ;
goto V_1032;
}
F_208 ( & V_2 -> V_82 -> V_470 , V_2 -> V_1037 ) ;
if ( V_1013 )
F_493 ( V_2 -> V_23 ) ;
F_494 () ;
if ( F_71 ( V_2 -> V_5 . V_153 ) ) {
F_495 ( 0 , 7 ) ;
F_495 ( V_2 -> V_5 . V_158 [ 0 ] , 0 ) ;
F_495 ( V_2 -> V_5 . V_158 [ 1 ] , 1 ) ;
F_495 ( V_2 -> V_5 . V_158 [ 2 ] , 2 ) ;
F_495 ( V_2 -> V_5 . V_158 [ 3 ] , 3 ) ;
}
F_496 ( V_2 -> V_255 ) ;
V_56 -> V_785 ( V_2 ) ;
if ( F_497 () )
F_498 () ;
V_2 -> V_5 . V_277 = V_56 -> V_297 ( V_2 ,
F_145 () ) ;
V_2 -> V_283 = V_1036 ;
F_13 () ;
F_291 () ;
++ V_2 -> V_60 . V_1038 ;
F_499 () ;
F_500 () ;
F_187 () ;
V_2 -> V_1037 = F_207 ( & V_2 -> V_82 -> V_470 ) ;
if ( F_71 ( V_1039 == V_1040 ) ) {
unsigned long V_996 = F_390 ( V_2 ) ;
F_501 ( V_1040 , ( void * ) V_996 ) ;
}
if ( F_71 ( V_2 -> V_5 . V_1041 ) )
F_23 ( V_296 , V_2 ) ;
if ( V_2 -> V_5 . V_1042 )
F_502 ( V_2 ) ;
V_100 = V_56 -> V_1043 ( V_2 ) ;
return V_100 ;
V_1032:
V_56 -> V_1032 ( V_2 ) ;
if ( F_71 ( V_2 -> V_5 . V_1042 ) )
F_502 ( V_2 ) ;
V_94:
return V_100 ;
}
static int F_503 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_82 * V_82 = V_2 -> V_82 ;
if ( F_71 ( V_2 -> V_5 . V_968 == V_1044 ) ) {
F_104 ( L_29 ,
V_2 -> V_255 , V_2 -> V_5 . V_603 ) ;
F_504 ( V_2 ) ;
V_100 = F_505 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_2 -> V_5 . V_968 = V_1045 ;
}
V_2 -> V_1037 = F_207 ( & V_82 -> V_470 ) ;
V_100 = F_468 ( V_2 ) ;
if ( V_100 ) {
F_208 ( & V_82 -> V_470 , V_2 -> V_1037 ) ;
return V_100 ;
}
V_100 = 1 ;
while ( V_100 > 0 ) {
if ( V_2 -> V_5 . V_968 == V_1045 &&
! V_2 -> V_5 . V_6 . V_1026 )
V_100 = F_481 ( V_2 ) ;
else {
F_208 ( & V_82 -> V_470 , V_2 -> V_1037 ) ;
F_506 ( V_2 ) ;
V_2 -> V_1037 = F_207 ( & V_82 -> V_470 ) ;
if ( F_482 ( V_1046 , V_2 ) )
{
switch( V_2 -> V_5 . V_968 ) {
case V_969 :
V_2 -> V_5 . V_968 =
V_1045 ;
case V_1045 :
V_2 -> V_5 . V_6 . V_1026 = false ;
break;
case V_1044 :
default:
V_100 = - V_1047 ;
break;
}
}
}
if ( V_100 <= 0 )
break;
F_480 ( V_1048 , & V_2 -> V_562 ) ;
if ( F_507 ( V_2 ) )
F_508 ( V_2 ) ;
if ( F_463 ( V_2 ) ) {
V_100 = - V_1047 ;
V_2 -> V_785 -> V_800 = V_1049 ;
++ V_2 -> V_60 . V_1050 ;
}
F_509 ( V_2 ) ;
if ( F_492 ( V_386 ) ) {
V_100 = - V_1047 ;
V_2 -> V_785 -> V_800 = V_1049 ;
++ V_2 -> V_60 . V_1051 ;
}
if ( F_491 () ) {
F_208 ( & V_82 -> V_470 , V_2 -> V_1037 ) ;
F_510 ( V_2 ) ;
V_2 -> V_1037 = F_207 ( & V_82 -> V_470 ) ;
}
}
F_208 ( & V_82 -> V_470 , V_2 -> V_1037 ) ;
F_469 ( V_2 ) ;
return V_100 ;
}
static inline int F_511 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_1037 = F_207 ( & V_2 -> V_82 -> V_470 ) ;
V_100 = F_512 ( V_2 , V_902 ) ;
F_208 ( & V_2 -> V_82 -> V_470 , V_2 -> V_1037 ) ;
if ( V_100 != V_887 )
return 0 ;
return 1 ;
}
static int V_915 ( struct V_1 * V_2 )
{
F_305 ( ! V_2 -> V_5 . V_815 . V_691 ) ;
return F_511 ( V_2 ) ;
}
static int V_917 ( struct V_1 * V_2 )
{
struct V_998 * V_785 = V_2 -> V_785 ;
struct V_783 * V_784 ;
unsigned V_75 ;
F_305 ( ! V_2 -> V_796 ) ;
V_784 = & V_2 -> V_780 [ V_2 -> V_797 ] ;
V_75 = F_295 ( 8u , V_784 -> V_75 ) ;
if ( ! V_2 -> V_799 )
memcpy ( V_784 -> V_31 , V_785 -> V_786 . V_31 , V_75 ) ;
if ( V_784 -> V_75 <= 8 ) {
V_784 ++ ;
V_2 -> V_797 ++ ;
} else {
V_784 -> V_31 += V_75 ;
V_784 -> V_379 += V_75 ;
V_784 -> V_75 -= V_75 ;
}
if ( V_2 -> V_797 == V_2 -> V_791 ) {
V_2 -> V_796 = 0 ;
if ( V_2 -> V_799 )
return 1 ;
V_2 -> V_779 = 1 ;
return F_511 ( V_2 ) ;
}
V_785 -> V_800 = V_801 ;
V_785 -> V_786 . V_802 = V_784 -> V_379 ;
if ( V_2 -> V_799 )
memcpy ( V_785 -> V_786 . V_31 , V_784 -> V_31 , F_295 ( 8u , V_784 -> V_75 ) ) ;
V_785 -> V_786 . V_75 = F_295 ( 8u , V_784 -> V_75 ) ;
V_785 -> V_786 . V_798 = V_2 -> V_799 ;
V_2 -> V_5 . V_914 = V_917 ;
return 0 ;
}
int F_513 ( struct V_1 * V_2 , struct V_998 * V_998 )
{
int V_100 ;
T_16 V_1052 ;
if ( ! F_514 ( V_386 ) && F_515 ( V_386 ) )
return - V_357 ;
if ( V_2 -> V_1053 )
F_516 ( V_1054 , & V_2 -> V_1055 , & V_1052 ) ;
if ( F_71 ( V_2 -> V_5 . V_968 == V_1056 ) ) {
F_506 ( V_2 ) ;
F_480 ( V_1046 , & V_2 -> V_562 ) ;
V_100 = - V_1057 ;
goto V_94;
}
if ( ! F_74 ( V_2 -> V_82 ) ) {
if ( F_73 ( V_2 , V_998 -> V_146 ) != 0 ) {
V_100 = - V_553 ;
goto V_94;
}
}
if ( F_71 ( V_2 -> V_5 . V_914 ) ) {
int (* F_517)( struct V_1 * ) = V_2 -> V_5 . V_914 ;
V_2 -> V_5 . V_914 = NULL ;
V_100 = F_517 ( V_2 ) ;
if ( V_100 <= 0 )
goto V_94;
} else
F_106 ( V_2 -> V_5 . V_815 . V_691 || V_2 -> V_796 ) ;
V_100 = F_503 ( V_2 ) ;
V_94:
F_466 ( V_2 ) ;
if ( V_2 -> V_1053 )
F_516 ( V_1054 , & V_1052 , NULL ) ;
return V_100 ;
}
int F_518 ( struct V_1 * V_2 , struct V_1058 * V_568 )
{
if ( V_2 -> V_5 . V_919 ) {
F_519 ( & V_2 -> V_5 . V_862 ) ;
V_2 -> V_5 . V_919 = false ;
}
V_568 -> V_1059 = F_84 ( V_2 , V_169 ) ;
V_568 -> V_1060 = F_84 ( V_2 , V_981 ) ;
V_568 -> V_1061 = F_84 ( V_2 , V_168 ) ;
V_568 -> V_1062 = F_84 ( V_2 , V_170 ) ;
V_568 -> V_1063 = F_84 ( V_2 , V_983 ) ;
V_568 -> V_1064 = F_84 ( V_2 , V_982 ) ;
V_568 -> V_1065 = F_84 ( V_2 , V_1066 ) ;
V_568 -> V_1067 = F_84 ( V_2 , V_1068 ) ;
#ifdef F_52
V_568 -> V_1069 = F_84 ( V_2 , V_984 ) ;
V_568 -> V_1070 = F_84 ( V_2 , V_1071 ) ;
V_568 -> V_1072 = F_84 ( V_2 , V_1073 ) ;
V_568 -> V_1074 = F_84 ( V_2 , V_1075 ) ;
V_568 -> V_1076 = F_84 ( V_2 , V_1077 ) ;
V_568 -> V_1078 = F_84 ( V_2 , V_1079 ) ;
V_568 -> V_1080 = F_84 ( V_2 , V_1081 ) ;
V_568 -> V_1082 = F_84 ( V_2 , V_1083 ) ;
#endif
V_568 -> V_996 = F_390 ( V_2 ) ;
V_568 -> V_1084 = F_389 ( V_2 ) ;
return 0 ;
}
int F_520 ( struct V_1 * V_2 , struct V_1058 * V_568 )
{
V_2 -> V_5 . V_880 = true ;
V_2 -> V_5 . V_919 = false ;
F_86 ( V_2 , V_169 , V_568 -> V_1059 ) ;
F_86 ( V_2 , V_981 , V_568 -> V_1060 ) ;
F_86 ( V_2 , V_168 , V_568 -> V_1061 ) ;
F_86 ( V_2 , V_170 , V_568 -> V_1062 ) ;
F_86 ( V_2 , V_983 , V_568 -> V_1063 ) ;
F_86 ( V_2 , V_982 , V_568 -> V_1064 ) ;
F_86 ( V_2 , V_1066 , V_568 -> V_1065 ) ;
F_86 ( V_2 , V_1068 , V_568 -> V_1067 ) ;
#ifdef F_52
F_86 ( V_2 , V_984 , V_568 -> V_1069 ) ;
F_86 ( V_2 , V_1071 , V_568 -> V_1070 ) ;
F_86 ( V_2 , V_1073 , V_568 -> V_1072 ) ;
F_86 ( V_2 , V_1075 , V_568 -> V_1074 ) ;
F_86 ( V_2 , V_1077 , V_568 -> V_1076 ) ;
F_86 ( V_2 , V_1079 , V_568 -> V_1078 ) ;
F_86 ( V_2 , V_1081 , V_568 -> V_1080 ) ;
F_86 ( V_2 , V_1083 , V_568 -> V_1082 ) ;
#endif
F_395 ( V_2 , V_568 -> V_996 ) ;
F_360 ( V_2 , V_568 -> V_1084 ) ;
V_2 -> V_5 . V_49 . V_50 = false ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
void F_521 ( struct V_1 * V_2 , int * V_157 , int * V_848 )
{
struct V_759 V_1085 ;
F_303 ( V_2 , & V_1085 , V_1086 ) ;
* V_157 = V_1085 . V_157 ;
* V_848 = V_1085 . V_848 ;
}
int F_522 ( struct V_1 * V_2 ,
struct V_1087 * V_1088 )
{
struct V_831 V_832 ;
F_303 ( V_2 , & V_1088 -> V_1085 , V_1086 ) ;
F_303 ( V_2 , & V_1088 -> V_1089 , V_1090 ) ;
F_303 ( V_2 , & V_1088 -> V_1091 , V_1092 ) ;
F_303 ( V_2 , & V_1088 -> V_1093 , V_1094 ) ;
F_303 ( V_2 , & V_1088 -> V_1095 , V_1096 ) ;
F_303 ( V_2 , & V_1088 -> V_1097 , V_1098 ) ;
F_303 ( V_2 , & V_1088 -> V_1099 , V_1100 ) ;
F_303 ( V_2 , & V_1088 -> V_1101 , V_1102 ) ;
V_56 -> V_834 ( V_2 , & V_832 ) ;
V_1088 -> V_1103 . V_843 = V_832 . V_475 ;
V_1088 -> V_1103 . V_844 = V_832 . V_63 ;
V_56 -> V_833 ( V_2 , & V_832 ) ;
V_1088 -> V_1104 . V_843 = V_832 . V_475 ;
V_1088 -> V_1104 . V_844 = V_832 . V_63 ;
V_1088 -> V_101 = F_51 ( V_2 ) ;
V_1088 -> V_62 = V_2 -> V_5 . V_62 ;
V_1088 -> V_85 = F_49 ( V_2 ) ;
V_1088 -> V_128 = F_62 ( V_2 ) ;
V_1088 -> V_146 = F_76 ( V_2 ) ;
V_1088 -> V_111 = V_2 -> V_5 . V_111 ;
V_1088 -> V_30 = F_18 ( V_2 ) ;
memset ( V_1088 -> V_1105 , 0 , sizeof V_1088 -> V_1105 ) ;
if ( V_2 -> V_5 . V_592 . V_50 && ! V_2 -> V_5 . V_592 . V_593 )
F_224 ( V_2 -> V_5 . V_592 . V_16 ,
( unsigned long * ) V_1088 -> V_1105 ) ;
return 0 ;
}
int F_523 ( struct V_1 * V_2 ,
struct V_1106 * V_968 )
{
V_968 -> V_968 = V_2 -> V_5 . V_968 ;
return 0 ;
}
int F_524 ( struct V_1 * V_2 ,
struct V_1106 * V_968 )
{
V_2 -> V_5 . V_968 = V_968 -> V_968 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_525 ( struct V_1 * V_2 , V_811 V_1107 , int V_1108 ,
int V_1109 , bool V_52 , T_1 V_43 )
{
struct V_773 * V_774 = & V_2 -> V_5 . V_862 ;
int V_89 ;
F_388 ( V_2 ) ;
V_89 = F_526 ( V_774 , V_1107 , V_1108 , V_1109 ,
V_52 , V_43 ) ;
if ( V_89 )
return V_885 ;
F_395 ( V_2 , V_774 -> V_872 ) ;
F_360 ( V_2 , V_774 -> V_871 ) ;
F_23 ( V_48 , V_2 ) ;
return V_887 ;
}
int F_527 ( struct V_1 * V_2 ,
struct V_1087 * V_1088 )
{
int V_1110 = 0 ;
int V_1111 , V_1112 , V_330 ;
struct V_831 V_832 ;
if ( ! F_63 ( V_2 ) && ( V_1088 -> V_128 & V_136 ) )
return - V_553 ;
V_832 . V_475 = V_1088 -> V_1103 . V_843 ;
V_832 . V_63 = V_1088 -> V_1103 . V_844 ;
V_56 -> V_836 ( V_2 , & V_832 ) ;
V_832 . V_475 = V_1088 -> V_1104 . V_843 ;
V_832 . V_63 = V_1088 -> V_1104 . V_844 ;
V_56 -> V_835 ( V_2 , & V_832 ) ;
V_2 -> V_5 . V_62 = V_1088 -> V_62 ;
V_1110 |= F_49 ( V_2 ) != V_1088 -> V_85 ;
V_2 -> V_5 . V_85 = V_1088 -> V_85 ;
F_44 ( V_143 , ( V_144 * ) & V_2 -> V_5 . V_97 ) ;
F_73 ( V_2 , V_1088 -> V_146 ) ;
V_1110 |= V_2 -> V_5 . V_111 != V_1088 -> V_111 ;
V_56 -> F_87 ( V_2 , V_1088 -> V_111 ) ;
F_19 ( V_2 , V_1088 -> V_30 ) ;
V_1110 |= F_51 ( V_2 ) != V_1088 -> V_101 ;
V_56 -> V_117 ( V_2 , V_1088 -> V_101 ) ;
V_2 -> V_5 . V_101 = V_1088 -> V_101 ;
V_1110 |= F_62 ( V_2 ) != V_1088 -> V_128 ;
V_56 -> V_139 ( V_2 , V_1088 -> V_128 ) ;
if ( V_1088 -> V_128 & V_136 )
F_67 ( V_2 ) ;
V_330 = F_207 ( & V_2 -> V_82 -> V_470 ) ;
if ( ! F_46 ( V_2 ) && F_47 ( V_2 ) ) {
F_41 ( V_2 , V_2 -> V_5 . V_84 , F_49 ( V_2 ) ) ;
V_1110 = 1 ;
}
F_208 ( & V_2 -> V_82 -> V_470 , V_330 ) ;
if ( V_1110 )
F_56 ( V_2 ) ;
V_1112 = V_572 ;
V_1111 = F_528 (
( const unsigned long * ) V_1088 -> V_1105 , V_1112 ) ;
if ( V_1111 < V_1112 ) {
F_234 ( V_2 , V_1111 , false ) ;
F_104 ( L_30 , V_1111 ) ;
}
F_302 ( V_2 , & V_1088 -> V_1085 , V_1086 ) ;
F_302 ( V_2 , & V_1088 -> V_1089 , V_1090 ) ;
F_302 ( V_2 , & V_1088 -> V_1091 , V_1092 ) ;
F_302 ( V_2 , & V_1088 -> V_1093 , V_1094 ) ;
F_302 ( V_2 , & V_1088 -> V_1095 , V_1096 ) ;
F_302 ( V_2 , & V_1088 -> V_1097 , V_1098 ) ;
F_302 ( V_2 , & V_1088 -> V_1099 , V_1100 ) ;
F_302 ( V_2 , & V_1088 -> V_1101 , V_1102 ) ;
F_232 ( V_2 ) ;
if ( F_529 ( V_2 ) && F_390 ( V_2 ) == 0xfff0 &&
V_1088 -> V_1085 . V_837 == 0xf000 && V_1088 -> V_1085 . V_844 == 0xffff0000 &&
! F_391 ( V_2 ) )
V_2 -> V_5 . V_968 = V_1045 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_530 ( struct V_1 * V_2 ,
struct V_1113 * V_1114 )
{
unsigned long V_1084 ;
int V_3 , V_100 ;
if ( V_1114 -> V_698 & ( V_1115 | V_1116 ) ) {
V_100 = - V_1117 ;
if ( V_2 -> V_5 . V_49 . V_50 )
goto V_94;
if ( V_1114 -> V_698 & V_1115 )
F_24 ( V_2 , V_1118 ) ;
else
F_24 ( V_2 , V_1119 ) ;
}
V_1084 = F_389 ( V_2 ) ;
V_2 -> V_149 = V_1114 -> V_698 ;
if ( ! ( V_2 -> V_149 & V_1120 ) )
V_2 -> V_149 = 0 ;
if ( V_2 -> V_149 & V_150 ) {
for ( V_3 = 0 ; V_3 < V_1121 ; ++ V_3 )
V_2 -> V_5 . V_158 [ V_3 ] = V_1114 -> V_5 . V_1122 [ V_3 ] ;
V_2 -> V_5 . V_151 = V_1114 -> V_5 . V_1122 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1121 ; V_3 ++ )
V_2 -> V_5 . V_158 [ V_3 ] = V_2 -> V_5 . V_157 [ V_3 ] ;
}
F_78 ( V_2 ) ;
if ( V_2 -> V_149 & V_1123 )
V_2 -> V_5 . V_1124 = F_390 ( V_2 ) +
F_344 ( V_2 , V_1086 ) ;
F_360 ( V_2 , V_1084 ) ;
V_56 -> V_1125 ( V_2 ) ;
V_100 = 0 ;
V_94:
return V_100 ;
}
int F_531 ( struct V_1 * V_2 ,
struct V_1126 * V_1099 )
{
unsigned long V_1127 = V_1099 -> V_1128 ;
T_4 V_379 ;
int V_330 ;
V_330 = F_207 ( & V_2 -> V_82 -> V_470 ) ;
V_379 = F_309 ( V_2 , V_1127 , NULL ) ;
F_208 ( & V_2 -> V_82 -> V_470 , V_330 ) ;
V_1099 -> V_1129 = V_379 ;
V_1099 -> V_1130 = V_379 != V_80 ;
V_1099 -> V_1131 = 1 ;
V_1099 -> V_1132 = 0 ;
return 0 ;
}
int F_532 ( struct V_1 * V_2 , struct V_1133 * V_1134 )
{
struct V_620 * V_619 =
& V_2 -> V_5 . V_615 . V_616 -> V_619 ;
memcpy ( V_1134 -> V_1135 , V_619 -> V_1136 , 128 ) ;
V_1134 -> V_1137 = V_619 -> V_1138 ;
V_1134 -> V_1139 = V_619 -> V_1140 ;
V_1134 -> V_1141 = V_619 -> V_1142 ;
V_1134 -> V_1143 = V_619 -> V_1144 ;
V_1134 -> V_1145 = V_619 -> V_996 ;
V_1134 -> V_1146 = V_619 -> V_1147 ;
memcpy ( V_1134 -> V_1148 , V_619 -> V_1149 , sizeof V_619 -> V_1149 ) ;
return 0 ;
}
int F_533 ( struct V_1 * V_2 , struct V_1133 * V_1134 )
{
struct V_620 * V_619 =
& V_2 -> V_5 . V_615 . V_616 -> V_619 ;
memcpy ( V_619 -> V_1136 , V_1134 -> V_1135 , 128 ) ;
V_619 -> V_1138 = V_1134 -> V_1137 ;
V_619 -> V_1140 = V_1134 -> V_1139 ;
V_619 -> V_1142 = V_1134 -> V_1141 ;
V_619 -> V_1144 = V_1134 -> V_1143 ;
V_619 -> V_996 = V_1134 -> V_1145 ;
V_619 -> V_1147 = V_1134 -> V_1146 ;
memcpy ( V_619 -> V_1149 , V_1134 -> V_1148 , sizeof V_619 -> V_1149 ) ;
return 0 ;
}
int F_534 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_535 ( & V_2 -> V_5 . V_615 ) ;
if ( V_55 )
return V_55 ;
F_536 ( & V_2 -> V_5 . V_615 ) ;
V_2 -> V_5 . V_121 = V_123 ;
V_2 -> V_5 . V_101 |= V_108 ;
return 0 ;
}
static void F_537 ( struct V_1 * V_2 )
{
F_538 ( & V_2 -> V_5 . V_615 ) ;
}
void F_378 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1150 )
return;
F_476 ( V_2 ) ;
V_2 -> V_1150 = 1 ;
F_539 () ;
F_540 ( & V_2 -> V_5 . V_615 ) ;
F_541 ( 1 ) ;
}
void F_228 ( struct V_1 * V_2 )
{
F_476 ( V_2 ) ;
if ( ! V_2 -> V_1150 )
return;
V_2 -> V_1150 = 0 ;
F_542 ( & V_2 -> V_5 . V_615 ) ;
F_543 () ;
++ V_2 -> V_60 . V_1151 ;
F_23 ( V_1022 , V_2 ) ;
F_541 ( 0 ) ;
}
void F_544 ( struct V_1 * V_2 )
{
F_174 ( V_2 ) ;
F_545 ( V_2 -> V_5 . V_559 ) ;
F_537 ( V_2 ) ;
V_56 -> V_1152 ( V_2 ) ;
}
struct V_1 * F_546 ( struct V_82 * V_82 ,
unsigned int V_1153 )
{
if ( F_123 () && F_118 ( & V_82 -> V_251 ) != 0 )
F_338 ( V_813
L_31
L_32 ) ;
return V_56 -> V_1154 ( V_82 , V_1153 ) ;
}
int F_547 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_5 . V_325 . V_1155 = 1 ;
V_100 = V_560 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_100 = F_505 ( V_2 ) ;
if ( V_100 == 0 )
V_100 = F_548 ( V_2 ) ;
V_565 ( V_2 ) ;
return V_100 ;
}
int F_549 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_185 V_21 ;
V_100 = V_560 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_21 . V_31 = 0x0 ;
V_21 . V_119 = V_1156 ;
V_21 . V_187 = true ;
F_121 ( V_2 , & V_21 ) ;
V_565 ( V_2 ) ;
return V_100 ;
}
void F_550 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_5 . V_6 . V_380 = 0 ;
V_100 = V_560 ( V_2 ) ;
F_305 ( V_100 ) ;
F_483 ( V_2 ) ;
V_565 ( V_2 ) ;
F_537 ( V_2 ) ;
V_56 -> V_1152 ( V_2 ) ;
}
static int F_505 ( struct V_1 * V_2 )
{
F_139 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_600 = 0 ;
V_2 -> V_5 . V_599 = false ;
memset ( V_2 -> V_5 . V_157 , 0 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_2 -> V_5 . V_160 = V_162 ;
V_2 -> V_5 . V_148 = V_164 ;
F_78 ( V_2 ) ;
F_23 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_6 . V_380 = 0 ;
V_2 -> V_5 . V_384 . V_380 = 0 ;
F_174 ( V_2 ) ;
F_55 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1026 = false ;
F_551 ( V_2 ) ;
memset ( V_2 -> V_5 . V_568 , 0 , sizeof( V_2 -> V_5 . V_568 ) ) ;
V_2 -> V_5 . V_97 = ~ 0 ;
V_2 -> V_5 . V_98 = ~ 0 ;
return V_56 -> V_1157 ( V_2 ) ;
}
int F_552 ( void * V_554 )
{
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 ;
int V_89 ;
T_2 V_1158 ;
T_2 V_1159 = 0 ;
bool V_1160 , V_1161 = false ;
F_14 () ;
V_89 = V_56 -> V_1162 ( V_554 ) ;
if ( V_89 != 0 )
return V_89 ;
V_1158 = F_145 () ;
V_1160 = ! F_123 () ;
F_420 (kvm, &vm_list, vm_list) {
F_199 (i, vcpu, kvm) {
if ( ! V_1160 && V_2 -> V_23 == F_8 () )
F_224 ( V_296 , & V_2 -> V_562 ) ;
if ( V_1160 && V_2 -> V_5 . V_564 > V_1158 ) {
V_1161 = true ;
if ( V_2 -> V_5 . V_564 > V_1159 )
V_1159 = V_2 -> V_5 . V_564 ;
}
}
}
if ( V_1161 ) {
T_2 V_1163 = V_1159 - V_1158 ;
F_420 (kvm, &vm_list, vm_list) {
F_199 (i, vcpu, kvm) {
V_2 -> V_5 . V_561 += V_1163 ;
V_2 -> V_5 . V_564 = V_1158 ;
F_224 ( V_254 ,
& V_2 -> V_562 ) ;
}
V_82 -> V_5 . V_266 = 0 ;
V_82 -> V_5 . V_267 = 0 ;
}
}
return 0 ;
}
void F_553 ( void * V_554 )
{
V_56 -> V_1164 ( V_554 ) ;
F_17 ( V_554 ) ;
}
int F_554 ( void )
{
return V_56 -> V_1165 () ;
}
void F_555 ( void )
{
V_56 -> V_1166 () ;
}
void F_556 ( void * V_1167 )
{
V_56 -> V_1168 ( V_1167 ) ;
}
bool F_557 ( struct V_1 * V_2 )
{
return F_74 ( V_2 -> V_82 ) == ( V_2 -> V_5 . V_569 != NULL ) ;
}
int F_558 ( struct V_1 * V_2 )
{
struct V_355 * V_355 ;
struct V_82 * V_82 ;
int V_100 ;
F_305 ( V_2 -> V_82 == NULL ) ;
V_82 = V_2 -> V_82 ;
V_2 -> V_5 . V_862 . V_788 = & V_1169 ;
if ( ! F_74 ( V_82 ) || F_529 ( V_2 ) )
V_2 -> V_5 . V_968 = V_1045 ;
else
V_2 -> V_5 . V_968 = V_1056 ;
V_355 = F_559 ( V_634 | V_1170 ) ;
if ( ! V_355 ) {
V_100 = - V_357 ;
goto V_1171;
}
V_2 -> V_5 . V_818 = F_560 ( V_355 ) ;
F_115 ( V_2 , V_936 ) ;
V_100 = F_561 ( V_2 ) ;
if ( V_100 < 0 )
goto V_1172;
if ( F_74 ( V_82 ) ) {
V_100 = F_562 ( V_2 ) ;
if ( V_100 < 0 )
goto V_1173;
} else
F_563 ( & V_1174 ) ;
V_2 -> V_5 . V_344 = F_251 ( V_425 * sizeof( T_2 ) * 4 ,
V_634 ) ;
if ( ! V_2 -> V_5 . V_344 ) {
V_100 = - V_357 ;
goto V_1175;
}
V_2 -> V_5 . V_336 = V_425 ;
if ( ! F_564 ( & V_2 -> V_5 . V_559 , V_634 ) )
goto V_1176;
V_100 = F_534 ( V_2 ) ;
if ( V_100 )
goto V_1177;
V_2 -> V_5 . V_258 = 0x0 ;
F_1 ( V_2 ) ;
F_565 ( V_2 ) ;
return 0 ;
V_1177:
F_545 ( V_2 -> V_5 . V_559 ) ;
V_1176:
F_160 ( V_2 -> V_5 . V_344 ) ;
V_1175:
F_566 ( V_2 ) ;
V_1173:
F_567 ( V_2 ) ;
V_1172:
F_568 ( ( unsigned long ) V_2 -> V_5 . V_818 ) ;
V_1171:
return V_100 ;
}
void F_569 ( struct V_1 * V_2 )
{
int V_330 ;
F_570 ( V_2 ) ;
F_160 ( V_2 -> V_5 . V_344 ) ;
F_566 ( V_2 ) ;
V_330 = F_207 ( & V_2 -> V_82 -> V_470 ) ;
F_567 ( V_2 ) ;
F_208 ( & V_2 -> V_82 -> V_470 , V_330 ) ;
F_568 ( ( unsigned long ) V_2 -> V_5 . V_818 ) ;
if ( ! F_74 ( V_2 -> V_82 ) )
F_571 ( & V_1174 ) ;
}
int F_572 ( struct V_82 * V_82 , unsigned long type )
{
if ( type )
return - V_553 ;
F_573 ( & V_82 -> V_5 . V_1178 ) ;
F_573 ( & V_82 -> V_5 . V_1179 ) ;
F_224 ( V_711 , & V_82 -> V_5 . V_1180 ) ;
F_224 ( V_1181 ,
& V_82 -> V_5 . V_1180 ) ;
F_574 ( & V_82 -> V_5 . V_264 ) ;
F_575 ( & V_82 -> V_5 . V_1182 ) ;
F_576 ( & V_82 -> V_5 . V_280 ) ;
F_138 ( V_82 ) ;
return 0 ;
}
static void F_577 ( struct V_1 * V_2 )
{
int V_100 ;
V_100 = V_560 ( V_2 ) ;
F_305 ( V_100 ) ;
F_483 ( V_2 ) ;
V_565 ( V_2 ) ;
}
static void F_578 ( struct V_82 * V_82 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_199 (i, vcpu, kvm) {
F_55 ( V_2 ) ;
F_577 ( V_2 ) ;
}
F_199 (i, vcpu, kvm)
F_544 ( V_2 ) ;
F_191 ( & V_82 -> V_440 ) ;
for ( V_3 = 0 ; V_3 < F_118 ( & V_82 -> V_251 ) ; V_3 ++ )
V_82 -> V_1183 [ V_3 ] = NULL ;
F_139 ( & V_82 -> V_251 , 0 ) ;
F_192 ( & V_82 -> V_440 ) ;
}
void F_579 ( struct V_82 * V_82 )
{
F_580 ( V_82 ) ;
F_581 ( V_82 ) ;
}
void F_582 ( struct V_82 * V_82 )
{
F_583 ( V_82 ) ;
F_160 ( V_82 -> V_5 . V_723 ) ;
F_160 ( V_82 -> V_5 . V_1184 ) ;
F_578 ( V_82 ) ;
if ( V_82 -> V_5 . V_1185 )
F_584 ( V_82 -> V_5 . V_1185 ) ;
if ( V_82 -> V_5 . V_1186 )
F_584 ( V_82 -> V_5 . V_1186 ) ;
F_160 ( F_585 ( V_82 -> V_5 . V_1187 , 1 ) ) ;
}
void F_586 ( struct V_701 * free ,
struct V_701 * V_1188 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1189 ; ++ V_3 ) {
if ( ! V_1188 || free -> V_5 . V_1190 [ V_3 ] != V_1188 -> V_5 . V_1190 [ V_3 ] ) {
F_587 ( free -> V_5 . V_1190 [ V_3 ] ) ;
free -> V_5 . V_1190 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1188 || free -> V_5 . V_1191 [ V_3 - 1 ] !=
V_1188 -> V_5 . V_1191 [ V_3 - 1 ] ) {
F_587 ( free -> V_5 . V_1191 [ V_3 - 1 ] ) ;
free -> V_5 . V_1191 [ V_3 - 1 ] = NULL ;
}
}
}
int F_588 ( struct V_701 * V_10 , unsigned long V_1192 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1189 ; ++ V_3 ) {
unsigned long V_1193 ;
int V_1194 ;
int V_712 = V_3 + 1 ;
V_1194 = F_589 ( V_10 -> V_1195 + V_1192 - 1 ,
V_10 -> V_1195 , V_712 ) + 1 ;
V_10 -> V_5 . V_1190 [ V_3 ] =
F_590 ( V_1194 * sizeof( * V_10 -> V_5 . V_1190 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1190 [ V_3 ] )
goto V_358;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1191 [ V_3 - 1 ] = F_590 ( V_1194 *
sizeof( * V_10 -> V_5 . V_1191 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1191 [ V_3 - 1 ] )
goto V_358;
if ( V_10 -> V_1195 & ( F_591 ( V_712 ) - 1 ) )
V_10 -> V_5 . V_1191 [ V_3 - 1 ] [ 0 ] . V_1196 = 1 ;
if ( ( V_10 -> V_1195 + V_1192 ) & ( F_591 ( V_712 ) - 1 ) )
V_10 -> V_5 . V_1191 [ V_3 - 1 ] [ V_1194 - 1 ] . V_1196 = 1 ;
V_1193 = V_10 -> V_1197 >> V_87 ;
if ( ( V_10 -> V_1195 ^ V_1193 ) & ( F_591 ( V_712 ) - 1 ) ||
! F_592 () ) {
unsigned long V_753 ;
for ( V_753 = 0 ; V_753 < V_1194 ; ++ V_753 )
V_10 -> V_5 . V_1191 [ V_3 - 1 ] [ V_753 ] . V_1196 = 1 ;
}
}
return 0 ;
V_358:
for ( V_3 = 0 ; V_3 < V_1189 ; ++ V_3 ) {
F_587 ( V_10 -> V_5 . V_1190 [ V_3 ] ) ;
V_10 -> V_5 . V_1190 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_587 ( V_10 -> V_5 . V_1191 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1191 [ V_3 - 1 ] = NULL ;
}
return - V_357 ;
}
int F_593 ( struct V_82 * V_82 ,
struct V_701 * V_702 ,
struct V_701 V_806 ,
struct V_1198 * V_1199 ,
int V_1200 )
{
int V_1192 = V_702 -> V_1192 ;
int V_1201 = V_1202 | V_1203 ;
if ( V_702 -> V_1153 >= V_522 )
V_1201 = V_1204 | V_1203 ;
if ( ! V_1200 ) {
if ( V_1192 && ! V_806 . V_1192 ) {
unsigned long V_1197 ;
V_1197 = F_594 ( NULL , 0 ,
V_1192 * V_88 ,
V_1205 | V_1206 ,
V_1201 ,
0 ) ;
if ( F_158 ( ( void * ) V_1197 ) )
return F_159 ( ( void * ) V_1197 ) ;
V_702 -> V_1197 = V_1197 ;
}
}
return 0 ;
}
void F_595 ( struct V_82 * V_82 ,
struct V_1198 * V_1199 ,
struct V_701 V_806 ,
int V_1200 )
{
int V_1207 = 0 , V_1192 = V_1199 -> V_1208 >> V_87 ;
if ( ! V_1200 && ! V_806 . V_1200 && V_806 . V_1192 && ! V_1192 ) {
int V_89 ;
V_89 = F_596 ( V_806 . V_1197 ,
V_806 . V_1192 * V_88 ) ;
if ( V_89 < 0 )
F_10 ( V_813
L_33
L_34 ) ;
}
if ( ! V_82 -> V_5 . V_674 )
V_1207 = F_597 ( V_82 ) ;
F_126 ( & V_82 -> V_673 ) ;
if ( V_1207 )
F_260 ( V_82 , V_1207 ) ;
F_598 ( V_82 , V_1199 -> V_10 ) ;
F_127 ( & V_82 -> V_673 ) ;
if ( V_1192 && V_806 . V_1195 != V_1199 -> V_1209 >> V_87 ) {
F_462 ( V_82 ) ;
F_599 ( V_82 ) ;
}
}
void F_600 ( struct V_82 * V_82 )
{
F_462 ( V_82 ) ;
F_599 ( V_82 ) ;
}
void F_601 ( struct V_82 * V_82 ,
struct V_701 * V_10 )
{
F_600 ( V_82 ) ;
}
int F_602 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_968 == V_1045 &&
! V_2 -> V_5 . V_6 . V_1026 )
|| ! F_603 ( & V_2 -> V_1210 . V_1211 )
|| V_2 -> V_5 . V_968 == V_1044
|| F_118 ( & V_2 -> V_5 . V_68 ) ||
( F_465 ( V_2 ) &&
F_464 ( V_2 ) ) ;
}
int F_604 ( struct V_1 * V_2 )
{
return F_605 ( V_2 ) == V_1034 ;
}
int F_465 ( struct V_1 * V_2 )
{
return V_56 -> V_1010 ( V_2 ) ;
}
bool F_606 ( struct V_1 * V_2 , unsigned long V_1212 )
{
unsigned long V_1213 = F_390 ( V_2 ) +
F_344 ( V_2 , V_1086 ) ;
return V_1213 == V_1212 ;
}
unsigned long F_389 ( struct V_1 * V_2 )
{
unsigned long V_1084 ;
V_1084 = V_56 -> V_1214 ( V_2 ) ;
if ( V_2 -> V_149 & V_1123 )
V_1084 &= ~ V_1215 ;
return V_1084 ;
}
void F_360 ( struct V_1 * V_2 , unsigned long V_1084 )
{
if ( V_2 -> V_149 & V_1123 &&
F_606 ( V_2 , V_2 -> V_5 . V_1124 ) )
V_1084 |= V_1215 ;
V_56 -> V_1216 ( V_2 , V_1084 ) ;
F_23 ( V_48 , V_2 ) ;
}
void F_607 ( struct V_1 * V_2 , struct V_1217 * V_951 )
{
int V_100 ;
if ( ( V_2 -> V_5 . V_67 . V_899 != V_951 -> V_5 . V_899 ) ||
F_184 ( V_951 -> V_355 ) )
return;
V_100 = F_489 ( V_2 ) ;
if ( F_71 ( V_100 ) )
return;
if ( ! V_2 -> V_5 . V_67 . V_899 &&
V_951 -> V_5 . V_85 != V_2 -> V_5 . V_67 . V_1218 ( V_2 ) )
return;
V_2 -> V_5 . V_67 . V_1219 ( V_2 , V_951 -> V_766 , 0 , true ) ;
}
static inline T_1 F_608 ( T_3 V_83 )
{
return F_609 ( V_83 & 0xffffffff , F_610 ( V_4 ) ) ;
}
static inline T_1 F_611 ( T_1 V_1220 )
{
return ( V_1220 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_612 ( struct V_1 * V_2 , T_3 V_83 )
{
T_1 V_1220 = F_608 ( V_83 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1220 ] != ~ 0 )
V_1220 = F_611 ( V_1220 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1220 ] = V_83 ;
}
static T_1 F_613 ( struct V_1 * V_2 , T_3 V_83 )
{
int V_3 ;
T_1 V_1220 = F_608 ( V_83 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1220 ] != V_83 &&
V_2 -> V_5 . V_6 . V_7 [ V_1220 ] != ~ 0 ) ; V_3 ++ )
V_1220 = F_611 ( V_1220 ) ;
return V_1220 ;
}
bool F_614 ( struct V_1 * V_2 , T_3 V_83 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_613 ( V_2 , V_83 ) ] == V_83 ;
}
static void F_615 ( struct V_1 * V_2 , T_3 V_83 )
{
T_1 V_3 , V_753 , V_1221 ;
V_3 = V_753 = F_613 ( V_2 , V_83 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_753 = F_611 ( V_753 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_753 ] == ~ 0 )
return;
V_1221 = F_608 ( V_2 -> V_5 . V_6 . V_7 [ V_753 ] ) ;
} while ( ( V_3 <= V_753 ) ? ( V_3 < V_1221 && V_1221 <= V_753 ) : ( V_3 < V_1221 || V_1221 <= V_753 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_753 ] ;
V_3 = V_753 ;
}
}
static int F_616 ( struct V_1 * V_2 , T_1 V_156 )
{
return F_179 ( V_2 -> V_82 , & V_2 -> V_5 . V_6 . V_31 , & V_156 ,
sizeof( V_156 ) ) ;
}
void F_617 ( struct V_1 * V_2 ,
struct V_1217 * V_951 )
{
struct V_58 V_59 ;
F_618 ( V_951 -> V_5 . V_1222 , V_951 -> V_766 ) ;
F_612 ( V_2 , V_951 -> V_5 . V_83 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_380 & V_381 ) ||
( V_2 -> V_5 . V_6 . V_382 &&
V_56 -> V_71 ( V_2 ) == 0 ) )
F_23 ( V_1025 , V_2 ) ;
else if ( ! F_616 ( V_2 , V_1223 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_863 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_951 -> V_5 . V_1222 ;
F_28 ( V_2 , & V_59 ) ;
}
}
void F_619 ( struct V_1 * V_2 ,
struct V_1217 * V_951 )
{
struct V_58 V_59 ;
F_620 ( V_951 -> V_5 . V_1222 , V_951 -> V_766 ) ;
if ( F_184 ( V_951 -> V_355 ) )
V_951 -> V_5 . V_1222 = ~ 0 ;
else
F_615 ( V_2 , V_951 -> V_5 . V_83 ) ;
if ( ( V_2 -> V_5 . V_6 . V_380 & V_381 ) &&
! F_616 ( V_2 , V_1224 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_863 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_951 -> V_5 . V_1222 ;
F_28 ( V_2 , & V_59 ) ;
}
V_2 -> V_5 . V_6 . V_1026 = false ;
V_2 -> V_5 . V_968 = V_1045 ;
}
bool F_621 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_380 & V_381 ) )
return true ;
else
return ! F_467 ( V_2 ) &&
V_56 -> V_1010 ( V_2 ) ;
}
