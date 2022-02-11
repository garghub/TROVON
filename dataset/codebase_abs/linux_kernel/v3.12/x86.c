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
if ( V_124 != V_121 )
return 1 ;
V_122 = V_125 ;
if ( ! ( V_122 & V_126 ) )
return 1 ;
if ( ( V_122 & V_127 ) && ! ( V_122 & V_128 ) )
return 1 ;
if ( V_122 & ~ V_123 )
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
int F_66 ( struct V_1 * V_2 , unsigned long V_129 )
{
unsigned long V_130 = F_67 ( V_2 ) ;
unsigned long V_131 = V_132 | V_133 |
V_134 | V_135 ;
if ( V_129 & V_136 )
return 1 ;
if ( ! F_68 ( V_2 ) && ( V_129 & V_119 ) )
return 1 ;
if ( ! F_69 ( V_2 ) && ( V_129 & V_135 ) )
return 1 ;
if ( ! F_70 ( V_2 ) && ( V_129 & V_137 ) )
return 1 ;
if ( F_48 ( V_2 ) ) {
if ( ! ( V_129 & V_134 ) )
return 1 ;
} else if ( F_55 ( V_2 ) && ( V_129 & V_134 )
&& ( ( V_129 ^ V_130 ) & V_131 )
&& ! F_43 ( V_2 , V_2 -> V_5 . V_84 ,
F_51 ( V_2 ) ) )
return 1 ;
if ( ( V_129 & V_116 ) && ! ( V_130 & V_116 ) ) {
if ( ! F_71 ( V_2 ) )
return 1 ;
if ( ( F_51 ( V_2 ) & V_138 ) || ! F_48 ( V_2 ) )
return 1 ;
}
if ( V_56 -> V_139 ( V_2 , V_129 ) )
return 1 ;
if ( ( ( V_129 ^ V_130 ) & V_131 ) ||
( ! ( V_129 & V_116 ) && ( V_130 & V_116 ) ) )
F_58 ( V_2 ) ;
if ( ( V_129 ^ V_130 ) & V_119 )
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
if ( V_85 & V_140 )
return 1 ;
} else
if ( V_85 & V_141 )
return 1 ;
} else {
if ( F_49 ( V_2 ) ) {
if ( V_85 & V_142 )
return 1 ;
if ( F_55 ( V_2 ) &&
! F_43 ( V_2 , V_2 -> V_5 . V_84 , V_85 ) )
return 1 ;
}
}
V_2 -> V_5 . V_85 = V_85 ;
F_46 ( V_143 , ( V_144 * ) & V_2 -> V_5 . V_97 ) ;
V_2 -> V_5 . V_67 . V_145 ( V_2 ) ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 , unsigned long V_146 )
{
if ( V_146 & V_147 )
return 1 ;
if ( F_77 ( V_2 -> V_82 ) )
F_78 ( V_2 , V_146 ) ;
else
V_2 -> V_5 . V_146 = V_146 ;
return 0 ;
}
unsigned long F_79 ( struct V_1 * V_2 )
{
if ( F_77 ( V_2 -> V_82 ) )
return F_80 ( V_2 ) ;
else
return V_2 -> V_5 . V_146 ;
}
static void F_81 ( struct V_1 * V_2 )
{
unsigned long V_148 ;
if ( V_2 -> V_149 & V_150 )
V_148 = V_2 -> V_5 . V_151 ;
else
V_148 = V_2 -> V_5 . V_148 ;
V_56 -> V_152 ( V_2 , V_148 ) ;
V_2 -> V_5 . V_153 = ( V_148 & V_154 ) ;
}
static int F_82 ( struct V_1 * V_2 , int V_155 , unsigned long V_156 )
{
switch ( V_155 ) {
case 0 ... 3 :
V_2 -> V_5 . V_157 [ V_155 ] = V_156 ;
if ( ! ( V_2 -> V_149 & V_150 ) )
V_2 -> V_5 . V_158 [ V_155 ] = V_156 ;
break;
case 4 :
if ( F_56 ( V_2 , V_159 ) )
return 1 ;
case 6 :
if ( V_156 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_160 = ( V_156 & V_161 ) | V_162 ;
break;
case 5 :
if ( F_56 ( V_2 , V_159 ) )
return 1 ;
default:
if ( V_156 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_148 = ( V_156 & V_163 ) | V_164 ;
F_81 ( V_2 ) ;
break;
}
return 0 ;
}
int F_83 ( struct V_1 * V_2 , int V_155 , unsigned long V_156 )
{
int V_165 ;
V_165 = F_82 ( V_2 , V_155 , V_156 ) ;
if ( V_165 > 0 )
F_26 ( V_2 , V_166 ) ;
else if ( V_165 < 0 )
F_29 ( V_2 , 0 ) ;
return V_165 ;
}
static int F_84 ( struct V_1 * V_2 , int V_155 , unsigned long * V_156 )
{
switch ( V_155 ) {
case 0 ... 3 :
* V_156 = V_2 -> V_5 . V_157 [ V_155 ] ;
break;
case 4 :
if ( F_56 ( V_2 , V_159 ) )
return 1 ;
case 6 :
* V_156 = V_2 -> V_5 . V_160 ;
break;
case 5 :
if ( F_56 ( V_2 , V_159 ) )
return 1 ;
default:
* V_156 = V_2 -> V_5 . V_148 ;
break;
}
return 0 ;
}
int F_85 ( struct V_1 * V_2 , int V_155 , unsigned long * V_156 )
{
if ( F_84 ( V_2 , V_155 , V_156 ) ) {
F_26 ( V_2 , V_166 ) ;
return 1 ;
}
return 0 ;
}
bool F_86 ( struct V_1 * V_2 )
{
T_1 V_167 = F_87 ( V_2 , V_168 ) ;
T_2 V_31 ;
int V_55 ;
V_55 = F_88 ( V_2 , V_167 , & V_31 ) ;
if ( V_55 )
return V_55 ;
F_89 ( V_2 , V_169 , ( T_1 ) V_31 ) ;
F_89 ( V_2 , V_170 , V_31 >> 32 ) ;
return V_55 ;
}
bool F_90 ( struct V_1 * V_2 , T_2 V_111 )
{
if ( V_111 & V_171 )
return false ;
if ( V_111 & V_172 ) {
struct V_173 * V_174 ;
V_174 = F_91 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_174 || ! ( V_174 -> V_175 & F_92 ( V_176 ) ) )
return false ;
}
if ( V_111 & V_177 ) {
struct V_173 * V_174 ;
V_174 = F_91 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_174 || ! ( V_174 -> V_167 & F_92 ( V_178 ) ) )
return false ;
}
return true ;
}
static int F_93 ( struct V_1 * V_2 , T_2 V_111 )
{
T_2 V_179 = V_2 -> V_5 . V_111 ;
if ( ! F_90 ( V_2 , V_111 ) )
return 1 ;
if ( F_55 ( V_2 )
&& ( V_2 -> V_5 . V_111 & V_112 ) != ( V_111 & V_112 ) )
return 1 ;
V_111 &= ~ V_180 ;
V_111 |= V_2 -> V_5 . V_111 & V_180 ;
V_56 -> F_93 ( V_2 , V_111 ) ;
if ( ( V_111 ^ V_179 ) & V_181 )
F_58 ( V_2 ) ;
return 0 ;
}
void F_94 ( T_2 V_27 )
{
V_171 &= ~ V_27 ;
}
int F_95 ( struct V_1 * V_2 , struct V_182 * V_21 )
{
return V_56 -> V_183 ( V_2 , V_21 ) ;
}
static int F_96 ( struct V_1 * V_2 , unsigned V_124 , T_2 * V_31 )
{
struct V_182 V_21 ;
V_21 . V_31 = * V_31 ;
V_21 . V_124 = V_124 ;
V_21 . V_184 = true ;
return F_95 ( V_2 , & V_21 ) ;
}
static void F_97 ( struct V_185 * V_186 )
{
struct V_187 * V_188 = & V_187 ;
F_98 ( & V_188 -> V_189 ) ;
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
F_99 ( & V_188 -> V_189 ) ;
}
static void F_100 ( struct V_82 * V_82 , T_5 V_203 )
{
int V_204 ;
int V_100 ;
struct V_205 V_206 ;
struct V_207 V_208 ;
if ( ! V_203 )
return;
V_100 = F_101 ( V_82 , V_203 , & V_204 , sizeof( V_204 ) ) ;
if ( V_100 )
return;
if ( V_204 & 1 )
++ V_204 ;
++ V_204 ;
F_102 ( V_82 , V_203 , & V_204 , sizeof( V_204 ) ) ;
F_103 ( & V_208 ) ;
if ( V_82 -> V_5 . V_209 ) {
struct V_207 V_210 = F_104 ( V_82 -> V_5 . V_209 ) ;
V_208 = F_105 ( V_208 , V_210 ) ;
}
V_206 . V_211 = V_208 . V_198 ;
V_206 . V_212 = V_208 . V_201 ;
V_206 . V_204 = V_204 ;
F_102 ( V_82 , V_203 , & V_206 , sizeof( V_206 ) ) ;
V_204 ++ ;
F_102 ( V_82 , V_203 , & V_204 , sizeof( V_204 ) ) ;
}
static T_6 F_106 ( T_6 V_213 , T_6 V_214 )
{
T_6 V_215 , V_216 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_215 ;
}
static void F_107 ( T_6 V_217 , T_6 V_218 ,
T_7 * V_219 , T_1 * V_220 )
{
T_8 V_221 ;
T_9 V_194 = 0 ;
T_8 V_222 ;
T_6 V_223 ;
V_222 = V_218 * 1000LL ;
V_221 = V_217 * 1000LL ;
while ( V_222 > V_221 * 2 || V_222 & 0xffffffff00000000ULL ) {
V_222 >>= 1 ;
V_194 -- ;
}
V_223 = ( T_6 ) V_222 ;
while ( V_223 <= V_221 || V_221 & 0xffffffff00000000ULL ) {
if ( V_221 & 0xffffffff00000000ULL || V_223 & 0x80000000 )
V_221 >>= 1 ;
else
V_223 <<= 1 ;
V_194 ++ ;
}
* V_219 = V_194 ;
* V_220 = F_106 ( V_221 , V_223 ) ;
F_108 ( L_2 ,
V_224 , V_218 , V_217 , V_194 , * V_220 ) ;
}
static inline T_2 F_109 ( void )
{
struct V_207 V_210 ;
F_110 ( F_111 () ) ;
F_112 ( & V_210 ) ;
F_113 ( & V_210 ) ;
return F_114 ( & V_210 ) ;
}
static inline T_2 F_115 ( struct V_1 * V_2 , T_2 V_212 )
{
return F_116 ( V_212 , V_2 -> V_5 . V_225 ,
V_2 -> V_5 . V_226 ) ;
}
static T_1 F_117 ( T_1 V_227 , T_10 V_228 )
{
T_2 V_229 = ( T_2 ) V_227 * ( 1000000 + V_228 ) ;
F_118 ( V_229 , 1000000 ) ;
return V_229 ;
}
static void F_119 ( struct V_1 * V_2 , T_1 V_230 )
{
T_1 V_231 , V_232 ;
int V_233 = 0 ;
if ( V_230 == 0 )
return;
F_107 ( V_230 , V_202 / 1000 ,
& V_2 -> V_5 . V_226 ,
& V_2 -> V_5 . V_225 ) ;
V_2 -> V_5 . V_234 = V_230 ;
V_231 = F_117 ( V_235 , - V_236 ) ;
V_232 = F_117 ( V_235 , V_236 ) ;
if ( V_230 < V_231 || V_230 > V_232 ) {
F_108 ( L_3 , V_230 , V_231 , V_232 ) ;
V_233 = 1 ;
}
V_56 -> V_237 ( V_2 , V_230 , V_233 ) ;
}
static T_2 F_120 ( struct V_1 * V_2 , T_11 V_238 )
{
T_2 V_239 = F_116 ( V_238 - V_2 -> V_5 . V_240 ,
V_2 -> V_5 . V_225 ,
V_2 -> V_5 . V_226 ) ;
V_239 += V_2 -> V_5 . V_241 ;
return V_239 ;
}
void F_121 ( struct V_1 * V_2 )
{
#ifdef F_54
bool V_242 ;
bool V_243 = false ;
struct V_244 * V_245 = & V_2 -> V_82 -> V_5 ;
struct V_187 * V_246 = & V_187 ;
V_242 = ( V_245 -> V_247 + 1 ==
F_122 ( & V_2 -> V_82 -> V_248 ) ) ;
if ( V_242 && V_246 -> clock . V_190 == V_249 )
if ( ! V_245 -> V_250 )
V_243 = 1 ;
if ( ! V_242 && V_245 -> V_250 )
V_243 = 1 ;
if ( V_243 )
F_25 ( V_251 , V_2 ) ;
F_123 ( V_2 -> V_252 , V_245 -> V_247 ,
F_122 ( & V_2 -> V_82 -> V_248 ) ,
V_245 -> V_250 , V_246 -> clock . V_190 ) ;
#endif
}
static void F_124 ( struct V_1 * V_2 , T_11 V_74 )
{
T_2 V_253 = V_56 -> V_254 ( V_2 ) ;
V_2 -> V_5 . V_255 += V_74 - V_253 ;
}
void F_125 ( struct V_1 * V_2 , struct V_182 * V_21 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
T_2 V_74 , V_256 , V_257 ;
unsigned long V_258 ;
T_11 V_259 ;
bool V_260 ;
T_2 V_31 = V_21 -> V_31 ;
F_126 ( & V_82 -> V_5 . V_261 , V_258 ) ;
V_74 = V_56 -> V_262 ( V_2 , V_31 ) ;
V_256 = F_109 () ;
V_257 = V_256 - V_82 -> V_5 . V_263 ;
if ( V_2 -> V_5 . V_234 ) {
int V_264 = 0 ;
V_259 = V_31 - V_82 -> V_5 . V_265 ;
#ifdef F_54
V_259 = ( V_259 * 1000 ) / V_2 -> V_5 . V_234 ;
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
F_118 ( V_257 , 1000 ) ;
V_259 -= V_257 ;
if ( V_259 < 0 )
V_259 = - V_259 ;
if ( V_264 )
V_259 = V_266 ;
} else
V_259 = V_266 ;
if ( V_259 < V_266 &&
V_2 -> V_5 . V_234 == V_82 -> V_5 . V_267 ) {
if ( ! F_127 () ) {
V_74 = V_82 -> V_5 . V_268 ;
F_108 ( L_4 , V_31 ) ;
} else {
T_2 V_269 = F_115 ( V_2 , V_257 ) ;
V_31 += V_269 ;
V_74 = V_56 -> V_262 ( V_2 , V_31 ) ;
F_108 ( L_5 , V_269 ) ;
}
V_260 = true ;
} else {
V_82 -> V_5 . V_270 ++ ;
V_82 -> V_5 . V_271 = V_256 ;
V_82 -> V_5 . V_272 = V_31 ;
V_82 -> V_5 . V_268 = V_74 ;
V_260 = false ;
F_108 ( L_6 ,
V_82 -> V_5 . V_270 , V_31 ) ;
}
V_82 -> V_5 . V_263 = V_256 ;
V_82 -> V_5 . V_265 = V_31 ;
V_82 -> V_5 . V_267 = V_2 -> V_5 . V_234 ;
V_2 -> V_5 . V_273 . V_274 = 0 ;
V_2 -> V_5 . V_275 = V_31 ;
V_2 -> V_5 . V_276 = V_82 -> V_5 . V_270 ;
V_2 -> V_5 . V_240 = V_82 -> V_5 . V_271 ;
V_2 -> V_5 . V_241 = V_82 -> V_5 . V_272 ;
if ( F_128 ( V_2 ) && ! V_21 -> V_184 )
F_124 ( V_2 , V_74 ) ;
V_56 -> V_277 ( V_2 , V_74 ) ;
F_129 ( & V_82 -> V_5 . V_261 , V_258 ) ;
F_130 ( & V_82 -> V_5 . V_278 ) ;
if ( V_260 )
V_82 -> V_5 . V_247 ++ ;
else
V_82 -> V_5 . V_247 = 0 ;
F_121 ( V_2 ) ;
F_131 ( & V_82 -> V_5 . V_278 ) ;
}
static T_12 F_132 ( void )
{
T_12 V_89 ;
T_2 V_279 ;
F_133 () ;
V_89 = ( T_12 ) F_134 () ;
V_279 = V_187 . clock . V_192 ;
if ( F_135 ( V_89 >= V_279 ) )
return V_89 ;
asm volatile ("");
return V_279 ;
}
static inline T_2 F_136 ( T_12 * V_280 )
{
long V_229 ;
struct V_187 * V_246 = & V_187 ;
* V_280 = F_132 () ;
V_229 = ( * V_280 - V_246 -> clock . V_192 ) & V_246 -> clock . V_27 ;
return V_229 * V_246 -> clock . V_193 ;
}
static int F_137 ( struct V_207 * V_210 , T_12 * V_280 )
{
unsigned long V_189 ;
T_2 V_256 ;
int V_281 ;
struct V_187 * V_246 = & V_187 ;
V_210 -> V_201 = 0 ;
do {
V_189 = F_138 ( & V_246 -> V_189 ) ;
V_281 = V_246 -> clock . V_190 ;
V_210 -> V_198 = V_246 -> V_195 ;
V_256 = V_246 -> V_199 ;
V_256 += F_136 ( V_280 ) ;
V_256 >>= V_246 -> clock . V_194 ;
} while ( F_139 ( F_140 ( & V_246 -> V_189 , V_189 ) ) );
F_141 ( V_210 , V_256 ) ;
return V_281 ;
}
static bool F_142 ( T_11 * V_238 , T_12 * V_280 )
{
struct V_207 V_210 ;
if ( V_187 . clock . V_190 != V_249 )
return false ;
if ( F_137 ( & V_210 , V_280 ) != V_249 )
return false ;
F_113 ( & V_210 ) ;
* V_238 = F_114 ( & V_210 ) ;
return true ;
}
static void F_143 ( struct V_82 * V_82 )
{
#ifdef F_54
struct V_244 * V_245 = & V_82 -> V_5 ;
int V_190 ;
bool V_282 , V_242 ;
V_242 = ( V_245 -> V_247 + 1 ==
F_122 ( & V_82 -> V_248 ) ) ;
V_282 = F_142 (
& V_245 -> V_283 ,
& V_245 -> V_284 ) ;
V_245 -> V_250 = V_282 & V_242 ;
if ( V_245 -> V_250 )
F_144 ( & V_285 , 1 ) ;
V_190 = V_187 . clock . V_190 ;
F_145 ( V_245 -> V_250 , V_190 ,
V_242 ) ;
#endif
}
static void F_146 ( struct V_82 * V_82 )
{
#ifdef F_54
int V_3 ;
struct V_1 * V_2 ;
struct V_244 * V_245 = & V_82 -> V_5 ;
F_130 ( & V_245 -> V_278 ) ;
F_147 ( V_82 ) ;
F_143 ( V_82 ) ;
F_148 (i, vcpu, kvm)
F_149 ( V_286 , & V_2 -> V_287 ) ;
F_148 (i, vcpu, kvm)
F_150 ( V_288 , & V_2 -> V_287 ) ;
F_131 ( & V_245 -> V_278 ) ;
#endif
}
static int F_151 ( struct V_1 * V_229 )
{
unsigned long V_258 , V_230 ;
struct V_289 * V_2 = & V_229 -> V_5 ;
struct V_244 * V_245 = & V_229 -> V_82 -> V_5 ;
T_11 V_238 , V_290 ;
T_2 V_274 , V_291 ;
struct V_292 V_293 ;
T_13 V_294 ;
bool V_250 ;
V_238 = 0 ;
V_291 = 0 ;
F_130 ( & V_245 -> V_278 ) ;
V_250 = V_245 -> V_250 ;
if ( V_250 ) {
V_291 = V_245 -> V_284 ;
V_238 = V_245 -> V_283 ;
}
F_131 ( & V_245 -> V_278 ) ;
F_152 ( V_258 ) ;
V_230 = F_153 ( V_295 ) ;
if ( F_139 ( V_230 == 0 ) ) {
F_154 ( V_258 ) ;
F_25 ( V_286 , V_229 ) ;
return 1 ;
}
if ( ! V_250 ) {
V_291 = F_155 () ;
V_238 = F_109 () ;
}
V_274 = V_56 -> V_296 ( V_229 , V_291 ) ;
if ( V_2 -> V_297 ) {
T_2 V_239 = F_120 ( V_229 , V_238 ) ;
if ( V_239 > V_274 ) {
F_156 ( V_229 , V_239 - V_274 ) ;
V_274 = V_239 ;
}
}
F_154 ( V_258 ) ;
if ( ! V_2 -> V_298 )
return 0 ;
V_290 = 0 ;
if ( V_2 -> V_273 . V_274 ) {
V_290 = V_2 -> V_275 -
V_2 -> V_273 . V_274 ;
V_290 = F_116 ( V_290 ,
V_2 -> V_273 . V_299 ,
V_2 -> V_273 . V_300 ) ;
V_290 += V_2 -> V_301 ;
}
if ( F_139 ( V_2 -> V_302 != V_230 ) ) {
F_107 ( V_202 / 1000 , V_230 ,
& V_2 -> V_273 . V_300 ,
& V_2 -> V_273 . V_299 ) ;
V_2 -> V_302 = V_230 ;
}
if ( ! V_250 ) {
if ( V_290 > V_238 )
V_238 = V_290 ;
}
V_2 -> V_273 . V_274 = V_274 ;
V_2 -> V_273 . V_303 = V_238 + V_229 -> V_82 -> V_5 . V_209 ;
V_2 -> V_301 = V_238 ;
V_2 -> V_275 = V_274 ;
V_2 -> V_273 . V_204 += 2 ;
if ( F_139 ( F_157 ( V_229 -> V_82 , & V_2 -> V_304 ,
& V_293 , sizeof( V_293 ) ) ) )
return 0 ;
V_294 = ( V_293 . V_258 & V_305 ) ;
if ( V_2 -> V_306 ) {
V_294 |= V_305 ;
V_2 -> V_306 = false ;
}
if ( V_250 )
V_294 |= V_307 ;
V_2 -> V_273 . V_258 = V_294 ;
F_158 ( V_229 -> V_82 , & V_2 -> V_304 ,
& V_2 -> V_273 ,
sizeof( V_2 -> V_273 ) ) ;
return 0 ;
}
static void F_159 ( struct V_1 * V_229 )
{
int V_3 ;
struct V_82 * V_82 = V_229 -> V_82 ;
struct V_1 * V_2 ;
F_148 (i, vcpu, kvm) {
F_149 ( V_286 , & V_2 -> V_287 ) ;
F_160 ( V_2 ) ;
}
}
static bool F_161 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_308 - 1 :
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
case V_319 :
case V_320 :
case V_321 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_162 ( unsigned V_322 )
{
return V_322 < 8 && ( 1 << V_322 ) & 0xf3 ;
}
static bool F_163 ( unsigned V_322 )
{
return V_322 < 8 && ( 1 << V_322 ) & 0x73 ;
}
static bool F_164 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
int V_3 ;
if ( ! F_161 ( V_21 ) )
return false ;
if ( V_21 == V_321 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_162 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_320 ) {
if ( V_31 & ~ 0xcff )
return false ;
return F_163 ( V_31 & 0xff ) ;
} else if ( V_21 >= V_309 && V_21 <= V_319 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_163 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_163 ( V_31 & 0xff ) ;
}
static int F_165 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 * V_323 = ( T_2 * ) & V_2 -> V_5 . V_324 . V_325 ;
if ( ! F_164 ( V_2 , V_21 , V_31 ) )
return 1 ;
if ( V_21 == V_320 ) {
V_2 -> V_5 . V_324 . V_326 = V_31 ;
V_2 -> V_5 . V_324 . V_327 = ( V_31 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_309 )
V_323 [ 0 ] = V_31 ;
else if ( V_21 == V_310 || V_21 == V_311 )
V_323 [ 1 + V_21 - V_310 ] = V_31 ;
else if ( V_21 >= V_312 && V_21 <= V_319 )
V_323 [ 3 + V_21 - V_312 ] = V_31 ;
else if ( V_21 == V_321 )
V_2 -> V_5 . V_328 = V_31 ;
else {
int V_329 , V_330 ;
T_2 * V_331 ;
V_329 = ( V_21 - 0x200 ) / 2 ;
V_330 = V_21 - 0x200 - 2 * V_329 ;
if ( ! V_330 )
V_331 =
( T_2 * ) & V_2 -> V_5 . V_324 . V_332 [ V_329 ] . V_333 ;
else
V_331 =
( T_2 * ) & V_2 -> V_5 . V_324 . V_332 [ V_329 ] . V_334 ;
* V_331 = V_31 ;
}
F_58 ( V_2 ) ;
return 0 ;
}
static int F_166 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 V_335 = V_2 -> V_5 . V_335 ;
unsigned V_336 = V_335 & 0xff ;
switch ( V_21 ) {
case V_337 :
V_2 -> V_5 . V_338 = V_31 ;
break;
case V_339 :
if ( ! ( V_335 & V_340 ) )
return 1 ;
if ( V_31 != 0 && V_31 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_341 = V_31 ;
break;
default:
if ( V_21 >= V_342 &&
V_21 < V_342 + 4 * V_336 ) {
T_1 V_74 = V_21 - V_342 ;
if ( ( V_74 & 0x3 ) == 0 &&
V_31 != 0 && ( V_31 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_343 [ V_74 ] = V_31 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_167 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
int V_344 = F_48 ( V_2 ) ;
T_13 * V_345 = V_344 ? ( T_13 * ) ( long ) V_82 -> V_5 . F_167 . V_346
: ( T_13 * ) ( long ) V_82 -> V_5 . F_167 . V_347 ;
T_13 V_348 = V_344 ? V_82 -> V_5 . F_167 . V_349
: V_82 -> V_5 . F_167 . V_350 ;
T_1 V_351 = V_31 & ~ V_352 ;
T_2 V_353 = V_31 & V_352 ;
T_13 * V_354 ;
int V_100 ;
V_100 = - V_355 ;
if ( V_351 >= V_348 )
goto V_94;
V_100 = - V_356 ;
V_354 = F_168 ( V_345 + ( V_351 * V_88 ) , V_88 ) ;
if ( F_169 ( V_354 ) ) {
V_100 = F_170 ( V_354 ) ;
goto V_94;
}
if ( F_102 ( V_82 , V_353 , V_354 , V_88 ) )
goto V_357;
V_100 = 0 ;
V_357:
F_171 ( V_354 ) ;
V_94:
return V_100 ;
}
static bool F_172 ( struct V_82 * V_82 )
{
return V_82 -> V_5 . V_358 & V_359 ;
}
static bool F_173 ( T_1 V_21 )
{
bool V_100 = false ;
switch ( V_21 ) {
case V_360 :
case V_361 :
V_100 = true ;
break;
}
return V_100 ;
}
static int F_174 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
switch ( V_21 ) {
case V_360 :
V_82 -> V_5 . V_362 = V_31 ;
if ( ! V_82 -> V_5 . V_362 )
V_82 -> V_5 . V_358 &= ~ V_359 ;
break;
case V_361 : {
T_2 V_83 ;
unsigned long V_363 ;
T_13 V_364 [ 4 ] ;
if ( ! V_82 -> V_5 . V_362 )
break;
if ( ! ( V_31 & V_359 ) ) {
V_82 -> V_5 . V_358 = V_31 ;
break;
}
V_83 = V_31 >> V_365 ;
V_363 = F_175 ( V_82 , V_83 ) ;
if ( F_176 ( V_363 ) )
return 1 ;
V_56 -> V_366 ( V_2 , V_364 ) ;
( ( unsigned char * ) V_364 ) [ 3 ] = 0xc3 ;
if ( F_177 ( ( void V_367 * ) V_363 , V_364 , 4 ) )
return 1 ;
V_82 -> V_5 . V_358 = V_31 ;
break;
}
default:
F_178 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_179 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_368 : {
unsigned long V_363 ;
if ( ! ( V_31 & V_369 ) ) {
V_2 -> V_5 . V_370 = V_31 ;
break;
}
V_363 = F_175 ( V_2 -> V_82 , V_31 >>
V_371 ) ;
if ( F_176 ( V_363 ) )
return 1 ;
if ( F_180 ( ( void V_367 * ) V_363 , V_88 ) )
return 1 ;
V_2 -> V_5 . V_370 = V_31 ;
break;
}
case V_372 :
return F_181 ( V_2 , V_373 , V_31 ) ;
case V_374 :
return F_181 ( V_2 , V_375 , V_31 ) ;
case V_376 :
return F_181 ( V_2 , V_377 , V_31 ) ;
default:
F_178 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_182 ( struct V_1 * V_2 , T_2 V_31 )
{
T_5 V_378 = V_31 & ~ 0x3f ;
if ( V_31 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_379 = V_31 ;
if ( ! ( V_31 & V_380 ) ) {
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_183 ( V_2 -> V_82 , & V_2 -> V_5 . V_6 . V_31 , V_378 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_381 = ! ( V_31 & V_382 ) ;
F_184 ( V_2 ) ;
return 0 ;
}
static void F_185 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_298 = false ;
}
static void F_186 ( struct V_1 * V_2 )
{
T_2 V_269 ;
if ( ! ( V_2 -> V_5 . V_383 . V_379 & V_384 ) )
return;
V_269 = V_385 -> V_386 . V_387 - V_2 -> V_5 . V_383 . V_388 ;
V_2 -> V_5 . V_383 . V_388 = V_385 -> V_386 . V_387 ;
V_2 -> V_5 . V_383 . V_389 = V_269 ;
}
static void F_187 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_383 . V_379 & V_384 ) )
return;
if ( F_139 ( F_157 ( V_2 -> V_82 , & V_2 -> V_5 . V_383 . V_390 ,
& V_2 -> V_5 . V_383 . V_391 , sizeof( struct V_392 ) ) ) )
return;
V_2 -> V_5 . V_383 . V_391 . V_391 += V_2 -> V_5 . V_383 . V_389 ;
V_2 -> V_5 . V_383 . V_391 . V_204 += 2 ;
V_2 -> V_5 . V_383 . V_389 = 0 ;
F_158 ( V_2 -> V_82 , & V_2 -> V_5 . V_383 . V_390 ,
& V_2 -> V_5 . V_383 . V_391 , sizeof( struct V_392 ) ) ;
}
int F_188 ( struct V_1 * V_2 , struct V_182 * V_393 )
{
bool V_394 = false ;
T_1 V_21 = V_393 -> V_124 ;
T_2 V_31 = V_393 -> V_31 ;
switch ( V_21 ) {
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
break;
case V_401 :
return F_93 ( V_2 , V_31 ) ;
case V_402 :
V_31 &= ~ ( T_2 ) 0x40 ;
V_31 &= ~ ( T_2 ) 0x100 ;
V_31 &= ~ ( T_2 ) 0x8 ;
if ( V_31 != 0 ) {
F_178 ( V_2 , L_9 ,
V_31 ) ;
return 1 ;
}
break;
case V_403 :
if ( V_31 != 0 ) {
F_178 ( V_2 , L_10
L_11 , V_31 ) ;
return 1 ;
}
break;
case V_404 :
if ( ! V_31 ) {
break;
} else if ( V_31 & ~ ( V_405 | V_406 ) ) {
return 1 ;
}
F_178 ( V_2 , L_12 ,
V_224 , V_31 ) ;
break;
case 0x200 ... 0x2ff :
return F_165 ( V_2 , V_21 , V_31 ) ;
case V_407 :
F_19 ( V_2 , V_31 ) ;
break;
case V_408 ... V_408 + 0x3ff :
return F_189 ( V_2 , V_21 , V_31 ) ;
case V_409 :
F_190 ( V_2 , V_31 ) ;
break;
case V_410 :
if ( F_128 ( V_2 ) ) {
if ( ! V_393 -> V_184 ) {
T_2 V_411 = V_31 - V_2 -> V_5 . V_255 ;
V_56 -> V_412 ( V_2 , V_411 , true ) ;
}
V_2 -> V_5 . V_255 = V_31 ;
}
break;
case V_413 :
V_2 -> V_5 . V_414 = V_31 ;
break;
case V_415 :
case V_416 :
V_2 -> V_82 -> V_5 . V_203 = V_31 ;
F_100 ( V_2 -> V_82 , V_31 ) ;
break;
case V_417 :
case V_418 : {
T_2 V_419 ;
F_185 ( V_2 ) ;
V_2 -> V_5 . time = V_31 ;
F_25 ( V_420 , V_2 ) ;
if ( ! ( V_31 & 1 ) )
break;
V_419 = V_31 & ~ ( V_352 | 1 ) ;
if ( F_183 ( V_2 -> V_82 ,
& V_2 -> V_5 . V_304 , V_31 & ~ 1ULL ,
sizeof( struct V_292 ) ) )
V_2 -> V_5 . V_298 = false ;
else
V_2 -> V_5 . V_298 = true ;
break;
}
case V_421 :
if ( F_182 ( V_2 , V_31 ) )
return 1 ;
break;
case V_422 :
if ( F_139 ( ! F_191 () ) )
return 1 ;
if ( V_31 & V_423 )
return 1 ;
if ( F_183 ( V_2 -> V_82 , & V_2 -> V_5 . V_383 . V_390 ,
V_31 & V_424 ,
sizeof( struct V_392 ) ) )
return 1 ;
V_2 -> V_5 . V_383 . V_379 = V_31 ;
if ( ! ( V_31 & V_384 ) )
break;
V_2 -> V_5 . V_383 . V_388 = V_385 -> V_386 . V_387 ;
F_192 () ;
F_186 ( V_2 ) ;
F_193 () ;
F_25 ( V_425 , V_2 ) ;
break;
case V_426 :
if ( F_194 ( V_2 , V_31 ) )
return 1 ;
break;
case V_339 :
case V_337 :
case V_342 ... V_342 + 4 * V_427 - 1 :
return F_166 ( V_2 , V_21 , V_31 ) ;
case V_428 :
case V_429 :
case V_430 :
case V_431 :
if ( V_31 != 0 )
F_178 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_432 :
case V_433 :
case V_434 :
case V_435 :
F_178 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_436 :
case V_437 :
V_394 = true ;
case V_438 :
case V_439 :
if ( F_195 ( V_2 , V_21 ) )
return F_196 ( V_2 , V_393 ) ;
if ( V_394 || V_31 != 0 )
F_178 ( V_2 , L_15
L_14 , V_21 , V_31 ) ;
break;
case V_440 :
break;
case V_360 ... V_441 :
if ( F_173 ( V_21 ) ) {
int V_100 ;
F_197 ( & V_2 -> V_82 -> V_442 ) ;
V_100 = F_174 ( V_2 , V_21 , V_31 ) ;
F_198 ( & V_2 -> V_82 -> V_442 ) ;
return V_100 ;
} else
return F_179 ( V_2 , V_21 , V_31 ) ;
break;
case V_443 :
F_178 ( V_2 , L_16 , V_21 , V_31 ) ;
break;
case V_444 :
if ( ! F_199 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_445 . V_446 = V_31 ;
break;
case V_447 :
if ( ! F_199 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_445 . V_448 = V_31 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_82 -> V_5 . F_167 . V_21 ) )
return F_167 ( V_2 , V_31 ) ;
if ( F_195 ( V_2 , V_21 ) )
return F_196 ( V_2 , V_393 ) ;
if ( ! V_449 ) {
F_178 ( V_2 , L_17 ,
V_21 , V_31 ) ;
return 1 ;
} else {
F_178 ( V_2 , L_16 ,
V_21 , V_31 ) ;
break;
}
}
return 0 ;
}
int F_200 ( struct V_1 * V_2 , T_1 V_450 , T_2 * V_451 )
{
return V_56 -> V_452 ( V_2 , V_450 , V_451 ) ;
}
static int F_201 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_451 )
{
T_2 * V_323 = ( T_2 * ) & V_2 -> V_5 . V_324 . V_325 ;
if ( ! F_161 ( V_21 ) )
return 1 ;
if ( V_21 == V_320 )
* V_451 = V_2 -> V_5 . V_324 . V_326 +
( V_2 -> V_5 . V_324 . V_327 << 10 ) ;
else if ( V_21 == V_309 )
* V_451 = V_323 [ 0 ] ;
else if ( V_21 == V_310 || V_21 == V_311 )
* V_451 = V_323 [ 1 + V_21 - V_310 ] ;
else if ( V_21 >= V_312 && V_21 <= V_319 )
* V_451 = V_323 [ 3 + V_21 - V_312 ] ;
else if ( V_21 == V_321 )
* V_451 = V_2 -> V_5 . V_328 ;
else {
int V_329 , V_330 ;
T_2 * V_331 ;
V_329 = ( V_21 - 0x200 ) / 2 ;
V_330 = V_21 - 0x200 - 2 * V_329 ;
if ( ! V_330 )
V_331 =
( T_2 * ) & V_2 -> V_5 . V_324 . V_332 [ V_329 ] . V_333 ;
else
V_331 =
( T_2 * ) & V_2 -> V_5 . V_324 . V_332 [ V_329 ] . V_334 ;
* V_451 = * V_331 ;
}
return 0 ;
}
static int F_202 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_451 )
{
T_2 V_31 ;
T_2 V_335 = V_2 -> V_5 . V_335 ;
unsigned V_336 = V_335 & 0xff ;
switch ( V_21 ) {
case V_453 :
case V_454 :
V_31 = 0 ;
break;
case V_455 :
V_31 = V_2 -> V_5 . V_335 ;
break;
case V_339 :
if ( ! ( V_335 & V_340 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_341 ;
break;
case V_337 :
V_31 = V_2 -> V_5 . V_338 ;
break;
default:
if ( V_21 >= V_342 &&
V_21 < V_342 + 4 * V_336 ) {
T_1 V_74 = V_21 - V_342 ;
V_31 = V_2 -> V_5 . V_343 [ V_74 ] ;
break;
}
return 1 ;
}
* V_451 = V_31 ;
return 0 ;
}
static int F_203 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_451 )
{
T_2 V_31 = 0 ;
struct V_82 * V_82 = V_2 -> V_82 ;
switch ( V_21 ) {
case V_360 :
V_31 = V_82 -> V_5 . V_362 ;
break;
case V_361 :
V_31 = V_82 -> V_5 . V_358 ;
break;
default:
F_178 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_451 = V_31 ;
return 0 ;
}
static int F_204 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_451 )
{
T_2 V_31 = 0 ;
switch ( V_21 ) {
case V_456 : {
int V_100 ;
struct V_1 * V_229 ;
F_148 (r, v, vcpu->kvm)
if ( V_229 == V_2 )
V_31 = V_100 ;
break;
}
case V_372 :
return F_205 ( V_2 , V_373 , V_451 ) ;
case V_374 :
return F_205 ( V_2 , V_375 , V_451 ) ;
case V_376 :
return F_205 ( V_2 , V_377 , V_451 ) ;
case V_368 :
V_31 = V_2 -> V_5 . V_370 ;
break;
default:
F_178 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_451 = V_31 ;
return 0 ;
}
int F_206 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_451 )
{
T_2 V_31 ;
switch ( V_21 ) {
case V_457 :
case V_458 :
case V_404 :
case V_459 :
case V_460 :
case V_461 :
case V_462 :
case V_463 :
case V_402 :
case V_398 :
case V_428 :
case V_432 :
case V_464 :
case V_395 :
case V_403 :
case V_400 :
V_31 = 0 ;
break;
case V_436 :
case V_437 :
case V_438 :
case V_439 :
if ( F_195 ( V_2 , V_21 ) )
return F_207 ( V_2 , V_21 , V_451 ) ;
V_31 = 0 ;
break;
case V_396 :
V_31 = 0x100000000ULL ;
break;
case V_465 :
V_31 = 0x500 | V_308 ;
break;
case 0x200 ... 0x2ff :
return F_201 ( V_2 , V_21 , V_451 ) ;
case 0xcd :
V_31 = 3 ;
break;
case V_466 :
V_31 = 1 << 24 ;
break;
case V_407 :
V_31 = F_18 ( V_2 ) ;
break;
case V_408 ... V_408 + 0x3ff :
return F_208 ( V_2 , V_21 , V_451 ) ;
break;
case V_409 :
V_31 = F_209 ( V_2 ) ;
break;
case V_410 :
V_31 = ( T_2 ) V_2 -> V_5 . V_255 ;
break;
case V_413 :
V_31 = V_2 -> V_5 . V_414 ;
break;
case V_467 :
V_31 = 1000ULL ;
V_31 |= ( ( ( T_8 ) 4ULL ) << 40 ) ;
break;
case V_401 :
V_31 = V_2 -> V_5 . V_111 ;
break;
case V_416 :
case V_415 :
V_31 = V_2 -> V_82 -> V_5 . V_203 ;
break;
case V_418 :
case V_417 :
V_31 = V_2 -> V_5 . time ;
break;
case V_421 :
V_31 = V_2 -> V_5 . V_6 . V_379 ;
break;
case V_422 :
V_31 = V_2 -> V_5 . V_383 . V_379 ;
break;
case V_426 :
V_31 = V_2 -> V_5 . V_468 . V_379 ;
break;
case V_453 :
case V_454 :
case V_455 :
case V_339 :
case V_337 :
case V_342 ... V_342 + 4 * V_427 - 1 :
return F_202 ( V_2 , V_21 , V_451 ) ;
case V_440 :
V_31 = 0x20000000 ;
break;
case V_360 ... V_441 :
if ( F_173 ( V_21 ) ) {
int V_100 ;
F_197 ( & V_2 -> V_82 -> V_442 ) ;
V_100 = F_203 ( V_2 , V_21 , V_451 ) ;
F_198 ( & V_2 -> V_82 -> V_442 ) ;
return V_100 ;
} else
return F_204 ( V_2 , V_21 , V_451 ) ;
break;
case V_443 :
V_31 = 0xbe702111 ;
break;
case V_444 :
if ( ! F_199 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_445 . V_446 ;
break;
case V_447 :
if ( ! F_199 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_445 . V_448 ;
break;
default:
if ( F_195 ( V_2 , V_21 ) )
return F_207 ( V_2 , V_21 , V_451 ) ;
if ( ! V_449 ) {
F_178 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_178 ( V_2 , L_20 , V_21 ) ;
V_31 = 0 ;
}
break;
}
* V_451 = V_31 ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 , struct V_469 * V_19 ,
struct V_470 * V_471 ,
int (* F_211)( struct V_1 * V_2 ,
unsigned V_124 , T_2 * V_31 ) )
{
int V_3 , V_329 ;
V_329 = F_212 ( & V_2 -> V_82 -> V_472 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_473 ; ++ V_3 )
if ( F_211 ( V_2 , V_471 [ V_3 ] . V_124 , & V_471 [ V_3 ] . V_31 ) )
break;
F_213 ( & V_2 -> V_82 -> V_472 , V_329 ) ;
return V_3 ;
}
static int F_214 ( struct V_1 * V_2 , struct V_469 V_367 * V_474 ,
int (* F_211)( struct V_1 * V_2 ,
unsigned V_124 , T_2 * V_31 ) ,
int V_475 )
{
struct V_469 V_19 ;
struct V_470 * V_471 ;
int V_100 , V_476 ;
unsigned V_477 ;
V_100 = - V_81 ;
if ( F_215 ( & V_19 , V_474 , sizeof V_19 ) )
goto V_94;
V_100 = - V_355 ;
if ( V_19 . V_473 >= V_478 )
goto V_94;
V_477 = sizeof( struct V_470 ) * V_19 . V_473 ;
V_471 = F_168 ( V_474 -> V_471 , V_477 ) ;
if ( F_169 ( V_471 ) ) {
V_100 = F_170 ( V_471 ) ;
goto V_94;
}
V_100 = V_476 = F_210 ( V_2 , & V_19 , V_471 , F_211 ) ;
if ( V_100 < 0 )
goto V_357;
V_100 = - V_81 ;
if ( V_475 && F_216 ( V_474 -> V_471 , V_471 , V_477 ) )
goto V_357;
V_100 = V_476 ;
V_357:
F_171 ( V_471 ) ;
V_94:
return V_100 ;
}
int F_217 ( long V_479 )
{
int V_100 ;
switch ( V_479 ) {
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
#ifdef F_218
case V_512 :
case V_513 :
#endif
V_100 = 1 ;
break;
case V_514 :
V_100 = V_515 ;
break;
case V_516 :
V_100 = ! V_56 -> V_517 () ;
break;
case V_518 :
V_100 = V_519 ;
break;
case V_520 :
V_100 = V_521 ;
break;
case V_522 :
V_100 = V_523 ;
break;
case V_524 :
V_100 = 0 ;
break;
#ifdef F_218
case V_525 :
V_100 = F_219 ( & V_526 ) ;
break;
#endif
case V_527 :
V_100 = V_427 ;
break;
case V_528 :
V_100 = V_529 ;
break;
case V_530 :
V_100 = V_531 ;
break;
case V_532 :
V_100 = F_220 ( V_533 ) ;
break;
default:
V_100 = 0 ;
break;
}
return V_100 ;
}
long F_221 ( struct V_534 * V_535 ,
unsigned int V_536 , unsigned long V_537 )
{
void V_367 * V_538 = ( void V_367 * ) V_537 ;
long V_100 ;
switch ( V_536 ) {
case V_539 : {
struct V_540 V_367 * V_541 = V_538 ;
struct V_540 V_542 ;
unsigned V_476 ;
V_100 = - V_81 ;
if ( F_215 ( & V_542 , V_541 , sizeof V_542 ) )
goto V_94;
V_476 = V_542 . V_473 ;
V_542 . V_473 = V_543 + F_44 ( V_544 ) ;
if ( F_216 ( V_541 , & V_542 , sizeof V_542 ) )
goto V_94;
V_100 = - V_355 ;
if ( V_476 < V_542 . V_473 )
goto V_94;
V_100 = - V_81 ;
if ( F_216 ( V_541 -> V_545 , & V_546 ,
V_543 * sizeof( T_1 ) ) )
goto V_94;
if ( F_216 ( V_541 -> V_545 + V_543 ,
& V_544 ,
F_44 ( V_544 ) * sizeof( T_1 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_547 : {
struct V_548 V_367 * V_549 = V_538 ;
struct V_548 V_550 ;
V_100 = - V_81 ;
if ( F_215 ( & V_550 , V_549 , sizeof V_550 ) )
goto V_94;
V_100 = F_222 ( & V_550 ,
V_549 -> V_471 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_216 ( V_549 , & V_550 , sizeof V_550 ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_551 : {
T_2 V_552 ;
V_552 = V_553 ;
V_100 = - V_81 ;
if ( F_216 ( V_538 , & V_552 , sizeof V_552 ) )
goto V_94;
V_100 = 0 ;
break;
}
default:
V_100 = - V_554 ;
}
V_94:
return V_100 ;
}
static void F_223 ( void * V_555 )
{
F_224 () ;
}
static bool F_225 ( struct V_1 * V_2 )
{
return V_2 -> V_82 -> V_5 . V_556 &&
! ( V_2 -> V_82 -> V_5 . V_557 & V_558 ) ;
}
void F_226 ( struct V_1 * V_2 , int V_23 )
{
if ( F_225 ( V_2 ) ) {
if ( V_56 -> V_559 () )
F_227 ( V_23 , V_2 -> V_5 . V_560 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_228 ( V_2 -> V_23 ,
F_223 , NULL , 1 ) ;
}
V_56 -> V_561 ( V_2 , V_23 ) ;
if ( F_139 ( V_2 -> V_5 . V_562 ) ) {
F_229 ( V_2 , V_2 -> V_5 . V_562 ) ;
V_2 -> V_5 . V_562 = 0 ;
F_149 ( V_286 , & V_2 -> V_287 ) ;
}
if ( F_139 ( V_2 -> V_23 != V_23 ) || F_127 () ) {
T_11 V_563 = ! V_2 -> V_5 . V_564 ? 0 :
F_155 () - V_2 -> V_5 . V_564 ;
if ( V_563 < 0 )
F_230 ( L_21 ) ;
if ( F_127 () ) {
T_2 V_74 = V_56 -> V_262 ( V_2 ,
V_2 -> V_5 . V_275 ) ;
V_56 -> V_277 ( V_2 , V_74 ) ;
V_2 -> V_5 . V_297 = 1 ;
}
if ( ! V_2 -> V_82 -> V_5 . V_250 || V_2 -> V_23 == - 1 )
F_25 ( V_420 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_231 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_186 ( V_2 ) ;
F_25 ( V_425 , V_2 ) ;
}
void F_232 ( struct V_1 * V_2 )
{
V_56 -> V_565 ( V_2 ) ;
F_233 ( V_2 ) ;
V_2 -> V_5 . V_564 = F_155 () ;
}
static int F_234 ( struct V_1 * V_2 ,
struct V_566 * V_567 )
{
V_56 -> V_568 ( V_2 ) ;
memcpy ( V_567 -> V_569 , V_2 -> V_5 . V_570 -> V_569 , sizeof *V_567 ) ;
return 0 ;
}
static int F_235 ( struct V_1 * V_2 ,
struct V_566 * V_567 )
{
F_236 ( V_2 , V_567 ) ;
F_237 ( V_2 ) ;
return 0 ;
}
static int F_238 ( struct V_1 * V_2 ,
struct V_571 * V_572 )
{
if ( V_572 -> V_572 >= V_573 )
return - V_554 ;
if ( F_77 ( V_2 -> V_82 ) )
return - V_574 ;
F_239 ( V_2 , V_572 -> V_572 , false ) ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_240 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
return 0 ;
}
static int F_241 ( struct V_1 * V_2 ,
struct V_575 * V_576 )
{
if ( V_576 -> V_258 )
return - V_554 ;
V_2 -> V_5 . V_577 = ! ! V_576 -> V_327 ;
return 0 ;
}
static int F_242 ( struct V_1 * V_2 ,
T_2 V_335 )
{
int V_100 ;
unsigned V_336 = V_335 & 0xff , V_578 ;
V_100 = - V_554 ;
if ( ! V_336 || V_336 >= V_427 )
goto V_94;
if ( V_335 & ~ ( V_553 | 0xff | 0xff0000 ) )
goto V_94;
V_100 = 0 ;
V_2 -> V_5 . V_335 = V_335 ;
if ( V_335 & V_340 )
V_2 -> V_5 . V_341 = ~ ( T_2 ) 0 ;
for ( V_578 = 0 ; V_578 < V_336 ; V_578 ++ )
V_2 -> V_5 . V_343 [ V_578 * 4 ] = ~ ( T_2 ) 0 ;
V_94:
return V_100 ;
}
static int F_243 ( struct V_1 * V_2 ,
struct V_579 * V_580 )
{
T_2 V_335 = V_2 -> V_5 . V_335 ;
unsigned V_336 = V_335 & 0xff ;
T_2 * V_581 = V_2 -> V_5 . V_343 ;
if ( V_580 -> V_578 >= V_336 || ! ( V_580 -> V_448 & V_582 ) )
return - V_554 ;
if ( ( V_580 -> V_448 & V_583 ) && ( V_335 & V_340 ) &&
V_2 -> V_5 . V_341 != ~ ( T_2 ) 0 )
return 0 ;
V_581 += 4 * V_580 -> V_578 ;
if ( ( V_580 -> V_448 & V_583 ) && V_581 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_580 -> V_448 & V_583 ) {
if ( ( V_2 -> V_5 . V_338 & V_584 ) ||
! F_56 ( V_2 , V_585 ) ) {
F_25 ( V_54 , V_2 ) ;
return 0 ;
}
if ( V_581 [ 1 ] & V_582 )
V_580 -> V_448 |= V_586 ;
V_581 [ 2 ] = V_580 -> V_363 ;
V_581 [ 3 ] = V_580 -> V_587 ;
V_2 -> V_5 . V_338 = V_580 -> V_338 ;
V_581 [ 1 ] = V_580 -> V_448 ;
F_26 ( V_2 , V_588 ) ;
} else if ( ! ( V_581 [ 1 ] & V_582 )
|| ! ( V_581 [ 1 ] & V_583 ) ) {
if ( V_581 [ 1 ] & V_582 )
V_580 -> V_448 |= V_586 ;
V_581 [ 2 ] = V_580 -> V_363 ;
V_581 [ 3 ] = V_580 -> V_587 ;
V_581 [ 1 ] = V_580 -> V_448 ;
} else
V_581 [ 1 ] |= V_586 ;
return 0 ;
}
static void F_244 ( struct V_1 * V_2 ,
struct V_589 * V_590 )
{
F_245 ( V_2 ) ;
V_590 -> V_49 . V_591 =
V_2 -> V_5 . V_49 . V_50 &&
! F_246 ( V_2 -> V_5 . V_49 . V_16 ) ;
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
V_590 -> V_258 = ( V_605
| V_606 ) ;
memset ( & V_590 -> V_607 , 0 , sizeof( V_590 -> V_607 ) ) ;
}
static int F_247 ( struct V_1 * V_2 ,
struct V_589 * V_590 )
{
if ( V_590 -> V_258 & ~ ( V_605
| V_608
| V_606 ) )
return - V_554 ;
F_245 ( V_2 ) ;
V_2 -> V_5 . V_49 . V_50 = V_590 -> V_49 . V_591 ;
V_2 -> V_5 . V_49 . V_16 = V_590 -> V_49 . V_16 ;
V_2 -> V_5 . V_49 . V_52 = V_590 -> V_49 . V_52 ;
V_2 -> V_5 . V_49 . V_43 = V_590 -> V_49 . V_43 ;
V_2 -> V_5 . V_593 . V_50 = V_590 -> V_593 . V_591 ;
V_2 -> V_5 . V_593 . V_16 = V_590 -> V_593 . V_16 ;
V_2 -> V_5 . V_593 . V_594 = V_590 -> V_593 . V_594 ;
if ( V_590 -> V_258 & V_606 )
V_56 -> V_609 ( V_2 ,
V_590 -> V_593 . V_595 ) ;
V_2 -> V_5 . V_600 = V_590 -> V_599 . V_591 ;
if ( V_590 -> V_258 & V_605 )
V_2 -> V_5 . V_601 = V_590 -> V_599 . V_50 ;
V_56 -> V_610 ( V_2 , V_590 -> V_599 . V_602 ) ;
if ( V_590 -> V_258 & V_608 &&
F_248 ( V_2 ) )
V_2 -> V_5 . V_570 -> V_604 = V_590 -> V_604 ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
static void F_249 ( struct V_1 * V_2 ,
struct V_611 * V_612 )
{
memcpy ( V_612 -> V_157 , V_2 -> V_5 . V_157 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_612 -> V_160 = V_2 -> V_5 . V_160 ;
V_612 -> V_148 = V_2 -> V_5 . V_148 ;
V_612 -> V_258 = 0 ;
memset ( & V_612 -> V_607 , 0 , sizeof( V_612 -> V_607 ) ) ;
}
static int F_250 ( struct V_1 * V_2 ,
struct V_611 * V_612 )
{
if ( V_612 -> V_258 )
return - V_554 ;
memcpy ( V_2 -> V_5 . V_157 , V_612 -> V_157 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_2 -> V_5 . V_160 = V_612 -> V_160 ;
V_2 -> V_5 . V_148 = V_612 -> V_148 ;
return 0 ;
}
static void F_251 ( struct V_1 * V_2 ,
struct V_613 * V_614 )
{
if ( V_529 )
memcpy ( V_614 -> V_615 ,
& V_2 -> V_5 . V_616 . V_617 -> V_618 ,
V_619 ) ;
else {
memcpy ( V_614 -> V_615 ,
& V_2 -> V_5 . V_616 . V_617 -> V_620 ,
sizeof( struct V_621 ) ) ;
* ( T_2 * ) & V_614 -> V_615 [ V_622 / sizeof( T_1 ) ] =
V_623 ;
}
}
static int F_252 ( struct V_1 * V_2 ,
struct V_613 * V_614 )
{
T_2 V_624 =
* ( T_2 * ) & V_614 -> V_615 [ V_622 / sizeof( T_1 ) ] ;
if ( V_529 )
memcpy ( & V_2 -> V_5 . V_616 . V_617 -> V_618 ,
V_614 -> V_615 , V_619 ) ;
else {
if ( V_624 & ~ V_623 )
return - V_554 ;
memcpy ( & V_2 -> V_5 . V_616 . V_617 -> V_620 ,
V_614 -> V_615 , sizeof( struct V_621 ) ) ;
}
return 0 ;
}
static void F_253 ( struct V_1 * V_2 ,
struct V_625 * V_626 )
{
if ( ! V_529 ) {
V_626 -> V_627 = 0 ;
return;
}
V_626 -> V_627 = 1 ;
V_626 -> V_258 = 0 ;
V_626 -> V_628 [ 0 ] . V_125 = V_121 ;
V_626 -> V_628 [ 0 ] . V_22 = V_2 -> V_5 . V_122 ;
}
static int F_254 ( struct V_1 * V_2 ,
struct V_625 * V_626 )
{
int V_3 , V_100 = 0 ;
if ( ! V_529 )
return - V_554 ;
if ( V_626 -> V_627 > V_629 || V_626 -> V_258 )
return - V_554 ;
for ( V_3 = 0 ; V_3 < V_626 -> V_627 ; V_3 ++ )
if ( V_626 -> V_628 [ 0 ] . V_125 == V_121 ) {
V_100 = F_64 ( V_2 , V_121 ,
V_626 -> V_628 [ 0 ] . V_22 ) ;
break;
}
if ( V_100 )
V_100 = - V_554 ;
return V_100 ;
}
static int F_255 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_298 )
return - V_554 ;
V_2 -> V_5 . V_306 = true ;
F_25 ( V_286 , V_2 ) ;
return 0 ;
}
long F_256 ( struct V_534 * V_535 ,
unsigned int V_536 , unsigned long V_537 )
{
struct V_1 * V_2 = V_535 -> V_630 ;
void V_367 * V_538 = ( void V_367 * ) V_537 ;
int V_100 ;
union {
struct V_566 * V_631 ;
struct V_613 * V_618 ;
struct V_625 * V_628 ;
void * V_632 ;
} V_633 ;
V_633 . V_632 = NULL ;
switch ( V_536 ) {
case V_634 : {
V_100 = - V_554 ;
if ( ! V_2 -> V_5 . V_570 )
goto V_94;
V_633 . V_631 = F_257 ( sizeof( struct V_566 ) , V_635 ) ;
V_100 = - V_356 ;
if ( ! V_633 . V_631 )
goto V_94;
V_100 = F_234 ( V_2 , V_633 . V_631 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_216 ( V_538 , V_633 . V_631 , sizeof( struct V_566 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_636 : {
V_100 = - V_554 ;
if ( ! V_2 -> V_5 . V_570 )
goto V_94;
V_633 . V_631 = F_168 ( V_538 , sizeof( * V_633 . V_631 ) ) ;
if ( F_169 ( V_633 . V_631 ) )
return F_170 ( V_633 . V_631 ) ;
V_100 = F_235 ( V_2 , V_633 . V_631 ) ;
break;
}
case V_637 : {
struct V_571 V_572 ;
V_100 = - V_81 ;
if ( F_215 ( & V_572 , V_538 , sizeof V_572 ) )
goto V_94;
V_100 = F_238 ( V_2 , & V_572 ) ;
break;
}
case V_638 : {
V_100 = F_240 ( V_2 ) ;
break;
}
case V_639 : {
struct V_640 V_367 * V_549 = V_538 ;
struct V_640 V_550 ;
V_100 = - V_81 ;
if ( F_215 ( & V_550 , V_549 , sizeof V_550 ) )
goto V_94;
V_100 = F_258 ( V_2 , & V_550 , V_549 -> V_471 ) ;
break;
}
case V_641 : {
struct V_548 V_367 * V_549 = V_538 ;
struct V_548 V_550 ;
V_100 = - V_81 ;
if ( F_215 ( & V_550 , V_549 , sizeof V_550 ) )
goto V_94;
V_100 = F_259 ( V_2 , & V_550 ,
V_549 -> V_471 ) ;
break;
}
case V_642 : {
struct V_548 V_367 * V_549 = V_538 ;
struct V_548 V_550 ;
V_100 = - V_81 ;
if ( F_215 ( & V_550 , V_549 , sizeof V_550 ) )
goto V_94;
V_100 = F_260 ( V_2 , & V_550 ,
V_549 -> V_471 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_216 ( V_549 , & V_550 , sizeof V_550 ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_643 :
V_100 = F_214 ( V_2 , V_538 , F_200 , 1 ) ;
break;
case V_644 :
V_100 = F_214 ( V_2 , V_538 , F_96 , 0 ) ;
break;
case V_645 : {
struct V_575 V_576 ;
V_100 = - V_81 ;
if ( F_215 ( & V_576 , V_538 , sizeof V_576 ) )
goto V_94;
V_100 = F_241 ( V_2 , & V_576 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_216 ( V_538 , & V_576 , sizeof V_576 ) )
goto V_94;
V_100 = 0 ;
break;
} ;
case V_646 : {
struct V_647 V_648 ;
V_100 = - V_554 ;
if ( ! F_77 ( V_2 -> V_82 ) )
goto V_94;
V_100 = - V_81 ;
if ( F_215 ( & V_648 , V_538 , sizeof V_648 ) )
goto V_94;
V_100 = 0 ;
F_261 ( V_2 , V_648 . V_649 ) ;
break;
}
case V_650 : {
T_2 V_335 ;
V_100 = - V_81 ;
if ( F_215 ( & V_335 , V_538 , sizeof V_335 ) )
goto V_94;
V_100 = F_242 ( V_2 , V_335 ) ;
break;
}
case V_651 : {
struct V_579 V_580 ;
V_100 = - V_81 ;
if ( F_215 ( & V_580 , V_538 , sizeof V_580 ) )
goto V_94;
V_100 = F_243 ( V_2 , & V_580 ) ;
break;
}
case V_652 : {
struct V_589 V_590 ;
F_244 ( V_2 , & V_590 ) ;
V_100 = - V_81 ;
if ( F_216 ( V_538 , & V_590 , sizeof( struct V_589 ) ) )
break;
V_100 = 0 ;
break;
}
case V_653 : {
struct V_589 V_590 ;
V_100 = - V_81 ;
if ( F_215 ( & V_590 , V_538 , sizeof( struct V_589 ) ) )
break;
V_100 = F_247 ( V_2 , & V_590 ) ;
break;
}
case V_654 : {
struct V_611 V_612 ;
F_249 ( V_2 , & V_612 ) ;
V_100 = - V_81 ;
if ( F_216 ( V_538 , & V_612 ,
sizeof( struct V_611 ) ) )
break;
V_100 = 0 ;
break;
}
case V_655 : {
struct V_611 V_612 ;
V_100 = - V_81 ;
if ( F_215 ( & V_612 , V_538 ,
sizeof( struct V_611 ) ) )
break;
V_100 = F_250 ( V_2 , & V_612 ) ;
break;
}
case V_656 : {
V_633 . V_618 = F_257 ( sizeof( struct V_613 ) , V_635 ) ;
V_100 = - V_356 ;
if ( ! V_633 . V_618 )
break;
F_251 ( V_2 , V_633 . V_618 ) ;
V_100 = - V_81 ;
if ( F_216 ( V_538 , V_633 . V_618 , sizeof( struct V_613 ) ) )
break;
V_100 = 0 ;
break;
}
case V_657 : {
V_633 . V_618 = F_168 ( V_538 , sizeof( * V_633 . V_618 ) ) ;
if ( F_169 ( V_633 . V_618 ) )
return F_170 ( V_633 . V_618 ) ;
V_100 = F_252 ( V_2 , V_633 . V_618 ) ;
break;
}
case V_658 : {
V_633 . V_628 = F_257 ( sizeof( struct V_625 ) , V_635 ) ;
V_100 = - V_356 ;
if ( ! V_633 . V_628 )
break;
F_253 ( V_2 , V_633 . V_628 ) ;
V_100 = - V_81 ;
if ( F_216 ( V_538 , V_633 . V_628 ,
sizeof( struct V_625 ) ) )
break;
V_100 = 0 ;
break;
}
case V_659 : {
V_633 . V_628 = F_168 ( V_538 , sizeof( * V_633 . V_628 ) ) ;
if ( F_169 ( V_633 . V_628 ) )
return F_170 ( V_633 . V_628 ) ;
V_100 = F_254 ( V_2 , V_633 . V_628 ) ;
break;
}
case V_660 : {
T_1 V_661 ;
V_100 = - V_554 ;
V_661 = ( T_1 ) V_537 ;
if ( V_661 >= V_662 )
goto V_94;
if ( V_661 == 0 )
V_661 = V_235 ;
F_119 ( V_2 , V_661 ) ;
V_100 = 0 ;
goto V_94;
}
case V_663 : {
V_100 = V_2 -> V_5 . V_234 ;
goto V_94;
}
case V_664 : {
V_100 = F_255 ( V_2 ) ;
goto V_94;
}
default:
V_100 = - V_554 ;
}
V_94:
F_171 ( V_633 . V_632 ) ;
return V_100 ;
}
int F_262 ( struct V_1 * V_2 , struct V_665 * V_666 )
{
return V_667 ;
}
static int F_263 ( struct V_82 * V_82 , unsigned long V_363 )
{
int V_89 ;
if ( V_363 > ( unsigned int ) ( - 3 * V_88 ) )
return - V_554 ;
V_89 = V_56 -> V_668 ( V_82 , V_363 ) ;
return V_89 ;
}
static int F_264 ( struct V_82 * V_82 ,
T_2 V_669 )
{
V_82 -> V_5 . V_670 = V_669 ;
return 0 ;
}
static int F_265 ( struct V_82 * V_82 ,
T_1 V_671 )
{
if ( V_671 < V_672 )
return - V_554 ;
F_197 ( & V_82 -> V_673 ) ;
F_266 ( V_82 , V_671 ) ;
V_82 -> V_5 . V_674 = V_671 ;
F_198 ( & V_82 -> V_673 ) ;
return 0 ;
}
static int F_267 ( struct V_82 * V_82 )
{
return V_82 -> V_5 . V_675 ;
}
static int F_268 ( struct V_82 * V_82 , struct V_676 * V_677 )
{
int V_100 ;
V_100 = 0 ;
switch ( V_677 -> V_678 ) {
case V_679 :
memcpy ( & V_677 -> V_677 . V_680 ,
& F_269 ( V_82 ) -> V_681 [ 0 ] ,
sizeof( struct V_682 ) ) ;
break;
case V_683 :
memcpy ( & V_677 -> V_677 . V_680 ,
& F_269 ( V_82 ) -> V_681 [ 1 ] ,
sizeof( struct V_682 ) ) ;
break;
case V_684 :
V_100 = F_270 ( V_82 , & V_677 -> V_677 . V_685 ) ;
break;
default:
V_100 = - V_554 ;
break;
}
return V_100 ;
}
static int F_271 ( struct V_82 * V_82 , struct V_676 * V_677 )
{
int V_100 ;
V_100 = 0 ;
switch ( V_677 -> V_678 ) {
case V_679 :
F_130 ( & F_269 ( V_82 ) -> V_442 ) ;
memcpy ( & F_269 ( V_82 ) -> V_681 [ 0 ] ,
& V_677 -> V_677 . V_680 ,
sizeof( struct V_682 ) ) ;
F_131 ( & F_269 ( V_82 ) -> V_442 ) ;
break;
case V_683 :
F_130 ( & F_269 ( V_82 ) -> V_442 ) ;
memcpy ( & F_269 ( V_82 ) -> V_681 [ 1 ] ,
& V_677 -> V_677 . V_680 ,
sizeof( struct V_682 ) ) ;
F_131 ( & F_269 ( V_82 ) -> V_442 ) ;
break;
case V_684 :
V_100 = F_272 ( V_82 , & V_677 -> V_677 . V_685 ) ;
break;
default:
V_100 = - V_554 ;
break;
}
F_273 ( F_269 ( V_82 ) ) ;
return V_100 ;
}
static int F_274 ( struct V_82 * V_82 , struct V_686 * V_687 )
{
int V_100 = 0 ;
F_197 ( & V_82 -> V_5 . V_688 -> V_689 . V_442 ) ;
memcpy ( V_687 , & V_82 -> V_5 . V_688 -> V_689 , sizeof( struct V_686 ) ) ;
F_198 ( & V_82 -> V_5 . V_688 -> V_689 . V_442 ) ;
return V_100 ;
}
static int F_275 ( struct V_82 * V_82 , struct V_686 * V_687 )
{
int V_100 = 0 ;
F_197 ( & V_82 -> V_5 . V_688 -> V_689 . V_442 ) ;
memcpy ( & V_82 -> V_5 . V_688 -> V_689 , V_687 , sizeof( struct V_686 ) ) ;
F_276 ( V_82 , 0 , V_687 -> V_690 [ 0 ] . V_691 , 0 ) ;
F_198 ( & V_82 -> V_5 . V_688 -> V_689 . V_442 ) ;
return V_100 ;
}
static int F_277 ( struct V_82 * V_82 , struct V_692 * V_687 )
{
int V_100 = 0 ;
F_197 ( & V_82 -> V_5 . V_688 -> V_689 . V_442 ) ;
memcpy ( V_687 -> V_690 , & V_82 -> V_5 . V_688 -> V_689 . V_690 ,
sizeof( V_687 -> V_690 ) ) ;
V_687 -> V_258 = V_82 -> V_5 . V_688 -> V_689 . V_258 ;
F_198 ( & V_82 -> V_5 . V_688 -> V_689 . V_442 ) ;
memset ( & V_687 -> V_607 , 0 , sizeof( V_687 -> V_607 ) ) ;
return V_100 ;
}
static int F_278 ( struct V_82 * V_82 , struct V_692 * V_687 )
{
int V_100 = 0 , V_693 = 0 ;
T_1 V_694 , V_695 ;
F_197 ( & V_82 -> V_5 . V_688 -> V_689 . V_442 ) ;
V_694 = V_82 -> V_5 . V_688 -> V_689 . V_258 & V_696 ;
V_695 = V_687 -> V_258 & V_696 ;
if ( ! V_694 && V_695 )
V_693 = 1 ;
memcpy ( & V_82 -> V_5 . V_688 -> V_689 . V_690 , & V_687 -> V_690 ,
sizeof( V_82 -> V_5 . V_688 -> V_689 . V_690 ) ) ;
V_82 -> V_5 . V_688 -> V_689 . V_258 = V_687 -> V_258 ;
F_276 ( V_82 , 0 , V_82 -> V_5 . V_688 -> V_689 . V_690 [ 0 ] . V_691 , V_693 ) ;
F_198 ( & V_82 -> V_5 . V_688 -> V_689 . V_442 ) ;
return V_100 ;
}
static int F_279 ( struct V_82 * V_82 ,
struct V_697 * V_698 )
{
if ( ! V_82 -> V_5 . V_688 )
return - V_574 ;
F_197 ( & V_82 -> V_5 . V_688 -> V_689 . V_442 ) ;
V_82 -> V_5 . V_688 -> V_689 . V_44 = V_698 -> V_699 ;
F_198 ( & V_82 -> V_5 . V_688 -> V_689 . V_442 ) ;
return 0 ;
}
int F_280 ( struct V_82 * V_82 , struct V_700 * log )
{
int V_100 ;
struct V_701 * V_702 ;
unsigned long V_476 , V_3 ;
unsigned long * V_703 ;
unsigned long * V_704 ;
bool V_705 = false ;
F_197 ( & V_82 -> V_673 ) ;
V_100 = - V_554 ;
if ( log -> V_10 >= V_523 )
goto V_94;
V_702 = F_281 ( V_82 -> V_706 , log -> V_10 ) ;
V_703 = V_702 -> V_703 ;
V_100 = - V_707 ;
if ( ! V_703 )
goto V_94;
V_476 = F_282 ( V_702 ) ;
V_704 = V_703 + V_476 / sizeof( long ) ;
memset ( V_704 , 0 , V_476 ) ;
F_130 ( & V_82 -> V_708 ) ;
for ( V_3 = 0 ; V_3 < V_476 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_27 ;
T_4 V_74 ;
if ( ! V_703 [ V_3 ] )
continue;
V_705 = true ;
V_27 = F_283 ( & V_703 [ V_3 ] , 0 ) ;
V_704 [ V_3 ] = V_27 ;
V_74 = V_3 * V_709 ;
F_284 ( V_82 , V_702 , V_74 , V_27 ) ;
}
if ( V_705 )
F_285 ( V_82 ) ;
F_131 ( & V_82 -> V_708 ) ;
V_100 = - V_81 ;
if ( F_216 ( log -> V_703 , V_704 , V_476 ) )
goto V_94;
V_100 = 0 ;
V_94:
F_198 ( & V_82 -> V_673 ) ;
return V_100 ;
}
int F_286 ( struct V_82 * V_82 , struct V_710 * V_711 ,
bool V_712 )
{
if ( ! F_77 ( V_82 ) )
return - V_574 ;
V_711 -> V_448 = F_287 ( V_82 , V_713 ,
V_711 -> V_572 , V_711 -> V_714 ,
V_712 ) ;
return 0 ;
}
long F_288 ( struct V_534 * V_535 ,
unsigned int V_536 , unsigned long V_537 )
{
struct V_82 * V_82 = V_535 -> V_630 ;
void V_367 * V_538 = ( void V_367 * ) V_537 ;
int V_100 = - V_715 ;
union {
struct V_686 V_687 ;
struct V_692 V_716 ;
struct V_717 V_718 ;
} V_633 ;
switch ( V_536 ) {
case V_719 :
V_100 = F_263 ( V_82 , V_537 ) ;
break;
case V_720 : {
T_2 V_669 ;
V_100 = - V_81 ;
if ( F_215 ( & V_669 , V_538 , sizeof V_669 ) )
goto V_94;
V_100 = F_264 ( V_82 , V_669 ) ;
break;
}
case V_721 :
V_100 = F_265 ( V_82 , V_537 ) ;
break;
case V_722 :
V_100 = F_267 ( V_82 ) ;
break;
case V_723 : {
struct V_724 * V_725 ;
F_197 ( & V_82 -> V_442 ) ;
V_100 = - V_726 ;
if ( V_82 -> V_5 . V_725 )
goto V_727;
V_100 = - V_554 ;
if ( F_122 ( & V_82 -> V_248 ) )
goto V_727;
V_100 = - V_356 ;
V_725 = F_289 ( V_82 ) ;
if ( V_725 ) {
V_100 = F_290 ( V_82 ) ;
if ( V_100 ) {
F_197 ( & V_82 -> V_673 ) ;
F_291 ( V_82 , V_728 ,
& V_725 -> V_729 ) ;
F_291 ( V_82 , V_728 ,
& V_725 -> V_730 ) ;
F_291 ( V_82 , V_728 ,
& V_725 -> V_731 ) ;
F_198 ( & V_82 -> V_673 ) ;
F_171 ( V_725 ) ;
goto V_727;
}
} else
goto V_727;
F_13 () ;
V_82 -> V_5 . V_725 = V_725 ;
F_13 () ;
V_100 = F_292 ( V_82 ) ;
if ( V_100 ) {
F_197 ( & V_82 -> V_673 ) ;
F_197 ( & V_82 -> V_732 ) ;
F_293 ( V_82 ) ;
F_294 ( V_82 ) ;
F_198 ( & V_82 -> V_732 ) ;
F_198 ( & V_82 -> V_673 ) ;
}
V_727:
F_198 ( & V_82 -> V_442 ) ;
break;
}
case V_733 :
V_633 . V_718 . V_258 = V_734 ;
goto V_735;
case V_736 :
V_100 = - V_81 ;
if ( F_215 ( & V_633 . V_718 , V_538 ,
sizeof( struct V_717 ) ) )
goto V_94;
V_735:
F_197 ( & V_82 -> V_673 ) ;
V_100 = - V_726 ;
if ( V_82 -> V_5 . V_688 )
goto V_737;
V_100 = - V_356 ;
V_82 -> V_5 . V_688 = F_295 ( V_82 , V_633 . V_718 . V_258 ) ;
if ( V_82 -> V_5 . V_688 )
V_100 = 0 ;
V_737:
F_198 ( & V_82 -> V_673 ) ;
break;
case V_738 : {
struct V_676 * V_677 ;
V_677 = F_168 ( V_538 , sizeof( * V_677 ) ) ;
if ( F_169 ( V_677 ) ) {
V_100 = F_170 ( V_677 ) ;
goto V_94;
}
V_100 = - V_574 ;
if ( ! F_77 ( V_82 ) )
goto V_739;
V_100 = F_268 ( V_82 , V_677 ) ;
if ( V_100 )
goto V_739;
V_100 = - V_81 ;
if ( F_216 ( V_538 , V_677 , sizeof *V_677 ) )
goto V_739;
V_100 = 0 ;
V_739:
F_171 ( V_677 ) ;
break;
}
case V_740 : {
struct V_676 * V_677 ;
V_677 = F_168 ( V_538 , sizeof( * V_677 ) ) ;
if ( F_169 ( V_677 ) ) {
V_100 = F_170 ( V_677 ) ;
goto V_94;
}
V_100 = - V_574 ;
if ( ! F_77 ( V_82 ) )
goto V_741;
V_100 = F_271 ( V_82 , V_677 ) ;
if ( V_100 )
goto V_741;
V_100 = 0 ;
V_741:
F_171 ( V_677 ) ;
break;
}
case V_742 : {
V_100 = - V_81 ;
if ( F_215 ( & V_633 . V_687 , V_538 , sizeof( struct V_686 ) ) )
goto V_94;
V_100 = - V_574 ;
if ( ! V_82 -> V_5 . V_688 )
goto V_94;
V_100 = F_274 ( V_82 , & V_633 . V_687 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_216 ( V_538 , & V_633 . V_687 , sizeof( struct V_686 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_743 : {
V_100 = - V_81 ;
if ( F_215 ( & V_633 . V_687 , V_538 , sizeof V_633 . V_687 ) )
goto V_94;
V_100 = - V_574 ;
if ( ! V_82 -> V_5 . V_688 )
goto V_94;
V_100 = F_275 ( V_82 , & V_633 . V_687 ) ;
break;
}
case V_744 : {
V_100 = - V_574 ;
if ( ! V_82 -> V_5 . V_688 )
goto V_94;
V_100 = F_277 ( V_82 , & V_633 . V_716 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_216 ( V_538 , & V_633 . V_716 , sizeof( V_633 . V_716 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_745 : {
V_100 = - V_81 ;
if ( F_215 ( & V_633 . V_716 , V_538 , sizeof( V_633 . V_716 ) ) )
goto V_94;
V_100 = - V_574 ;
if ( ! V_82 -> V_5 . V_688 )
goto V_94;
V_100 = F_278 ( V_82 , & V_633 . V_716 ) ;
break;
}
case V_746 : {
struct V_697 V_698 ;
V_100 = - V_81 ;
if ( F_215 ( & V_698 , V_538 , sizeof( V_698 ) ) )
goto V_94;
V_100 = F_279 ( V_82 , & V_698 ) ;
break;
}
case V_747 : {
V_100 = - V_81 ;
if ( F_215 ( & V_82 -> V_5 . F_167 , V_538 ,
sizeof( struct V_748 ) ) )
goto V_94;
V_100 = - V_554 ;
if ( V_82 -> V_5 . F_167 . V_258 )
goto V_94;
V_100 = 0 ;
break;
}
case V_749 : {
struct V_750 V_751 ;
T_2 V_752 ;
T_11 V_269 ;
V_100 = - V_81 ;
if ( F_215 ( & V_751 , V_538 , sizeof( V_751 ) ) )
goto V_94;
V_100 = - V_554 ;
if ( V_751 . V_258 )
goto V_94;
V_100 = 0 ;
F_296 () ;
V_752 = F_109 () ;
V_269 = V_751 . clock - V_752 ;
F_297 () ;
V_82 -> V_5 . V_209 = V_269 ;
F_146 ( V_82 ) ;
break;
}
case V_753 : {
struct V_750 V_751 ;
T_2 V_752 ;
F_296 () ;
V_752 = F_109 () ;
V_751 . clock = V_82 -> V_5 . V_209 + V_752 ;
F_297 () ;
V_751 . V_258 = 0 ;
memset ( & V_751 . V_592 , 0 , sizeof( V_751 . V_592 ) ) ;
V_100 = - V_81 ;
if ( F_216 ( V_538 , & V_751 , sizeof( V_751 ) ) )
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
static void F_298 ( void )
{
T_1 V_754 [ 2 ] ;
unsigned V_3 , V_755 ;
for ( V_3 = V_755 = V_756 ; V_3 < F_44 ( V_546 ) ; V_3 ++ ) {
if ( F_299 ( V_546 [ V_3 ] , & V_754 [ 0 ] , & V_754 [ 1 ] ) < 0 )
continue;
if ( V_755 < V_3 )
V_546 [ V_755 ] = V_546 [ V_3 ] ;
V_755 ++ ;
}
V_543 = V_755 ;
}
static int F_300 ( struct V_1 * V_2 , T_5 V_363 , int V_75 ,
const void * V_229 )
{
int V_757 = 0 ;
int V_476 ;
do {
V_476 = F_301 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_570 &&
! F_302 ( & V_2 -> V_5 . V_570 -> V_758 , V_363 , V_476 , V_229 ) )
&& F_303 ( V_2 -> V_82 , V_759 , V_363 , V_476 , V_229 ) )
break;
V_757 += V_476 ;
V_363 += V_476 ;
V_75 -= V_476 ;
V_229 += V_476 ;
} while ( V_75 );
return V_757 ;
}
static int F_304 ( struct V_1 * V_2 , T_5 V_363 , int V_75 , void * V_229 )
{
int V_757 = 0 ;
int V_476 ;
do {
V_476 = F_301 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_570 &&
! F_305 ( & V_2 -> V_5 . V_570 -> V_758 , V_363 , V_476 , V_229 ) )
&& F_306 ( V_2 -> V_82 , V_759 , V_363 , V_476 , V_229 ) )
break;
F_307 ( V_760 , V_476 , V_363 , * ( T_2 * ) V_229 ) ;
V_757 += V_476 ;
V_363 += V_476 ;
V_75 -= V_476 ;
V_229 += V_476 ;
} while ( V_75 );
return V_757 ;
}
static void F_308 ( struct V_1 * V_2 ,
struct V_761 * V_762 , int V_763 )
{
V_56 -> V_764 ( V_2 , V_762 , V_763 ) ;
}
void F_309 ( struct V_1 * V_2 ,
struct V_761 * V_762 , int V_763 )
{
V_56 -> V_765 ( V_2 , V_762 , V_763 ) ;
}
T_5 F_310 ( struct V_1 * V_2 , T_5 V_378 , T_1 V_76 )
{
T_5 V_766 ;
struct V_58 V_49 ;
F_311 ( ! F_33 ( V_2 ) ) ;
V_76 |= V_92 ;
V_766 = V_2 -> V_5 . V_67 . V_767 ( V_2 , V_378 , V_76 , & V_49 ) ;
return V_766 ;
}
T_5 F_312 ( struct V_1 * V_2 , T_14 V_768 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return V_2 -> V_5 . V_84 -> V_767 ( V_2 , V_768 , V_76 , V_49 ) ;
}
T_5 F_313 ( struct V_1 * V_2 , T_14 V_768 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
V_76 |= V_769 ;
return V_2 -> V_5 . V_84 -> V_767 ( V_2 , V_768 , V_76 , V_49 ) ;
}
T_5 F_314 ( struct V_1 * V_2 , T_14 V_768 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
V_76 |= V_93 ;
return V_2 -> V_5 . V_84 -> V_767 ( V_2 , V_768 , V_76 , V_49 ) ;
}
T_5 F_315 ( struct V_1 * V_2 , T_14 V_768 ,
struct V_58 * V_49 )
{
return V_2 -> V_5 . V_84 -> V_767 ( V_2 , V_768 , 0 , V_49 ) ;
}
static int F_316 ( T_14 V_363 , void * V_156 , unsigned int V_770 ,
struct V_1 * V_2 , T_1 V_76 ,
struct V_58 * V_49 )
{
void * V_31 = V_156 ;
int V_100 = V_771 ;
while ( V_770 ) {
T_5 V_378 = V_2 -> V_5 . V_84 -> V_767 ( V_2 , V_363 , V_76 ,
V_49 ) ;
unsigned V_74 = V_363 & ( V_88 - 1 ) ;
unsigned V_772 = F_301 ( V_770 , ( unsigned ) V_88 - V_74 ) ;
int V_89 ;
if ( V_378 == V_80 )
return V_773 ;
V_89 = F_101 ( V_2 -> V_82 , V_378 , V_31 , V_772 ) ;
if ( V_89 < 0 ) {
V_100 = V_774 ;
goto V_94;
}
V_770 -= V_772 ;
V_31 += V_772 ;
V_363 += V_772 ;
}
V_94:
return V_100 ;
}
static int F_317 ( struct V_775 * V_776 ,
T_14 V_363 , void * V_156 , unsigned int V_770 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return F_316 ( V_363 , V_156 , V_770 , V_2 ,
V_76 | V_769 ,
V_49 ) ;
}
int F_319 ( struct V_775 * V_776 ,
T_14 V_363 , void * V_156 , unsigned int V_770 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return F_316 ( V_363 , V_156 , V_770 , V_2 , V_76 ,
V_49 ) ;
}
static int F_320 ( struct V_775 * V_776 ,
T_14 V_363 , void * V_156 , unsigned int V_770 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
return F_316 ( V_363 , V_156 , V_770 , V_2 , 0 , V_49 ) ;
}
int F_321 ( struct V_775 * V_776 ,
T_14 V_363 , void * V_156 ,
unsigned int V_770 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
void * V_31 = V_156 ;
int V_100 = V_771 ;
while ( V_770 ) {
T_5 V_378 = V_2 -> V_5 . V_84 -> V_767 ( V_2 , V_363 ,
V_93 ,
V_49 ) ;
unsigned V_74 = V_363 & ( V_88 - 1 ) ;
unsigned V_777 = F_301 ( V_770 , ( unsigned ) V_88 - V_74 ) ;
int V_89 ;
if ( V_378 == V_80 )
return V_773 ;
V_89 = F_102 ( V_2 -> V_82 , V_378 , V_31 , V_777 ) ;
if ( V_89 < 0 ) {
V_100 = V_774 ;
goto V_94;
}
V_770 -= V_777 ;
V_31 += V_777 ;
V_363 += V_777 ;
}
V_94:
return V_100 ;
}
static int F_322 ( struct V_1 * V_2 , unsigned long V_768 ,
T_5 * V_378 , struct V_58 * V_49 ,
bool V_778 )
{
T_1 V_76 = ( ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 )
| ( V_778 ? V_93 : 0 ) ;
if ( F_323 ( V_2 , V_768 )
&& ! F_324 ( V_2 -> V_5 . V_84 , V_2 -> V_5 . V_76 , V_76 ) ) {
* V_378 = V_2 -> V_5 . V_779 << V_87 |
( V_768 & ( V_88 - 1 ) ) ;
F_325 ( V_768 , * V_378 , V_778 , false ) ;
return 1 ;
}
* V_378 = V_2 -> V_5 . V_84 -> V_767 ( V_2 , V_768 , V_76 , V_49 ) ;
if ( * V_378 == V_80 )
return - 1 ;
if ( ( * V_378 & V_352 ) == V_780 )
return 1 ;
if ( F_326 ( V_2 , * V_378 ) ) {
F_325 ( V_768 , * V_378 , V_778 , true ) ;
return 1 ;
}
return 0 ;
}
int F_327 ( struct V_1 * V_2 , T_5 V_378 ,
const void * V_156 , int V_770 )
{
int V_89 ;
V_89 = F_102 ( V_2 -> V_82 , V_378 , V_156 , V_770 ) ;
if ( V_89 < 0 )
return 0 ;
F_328 ( V_2 , V_378 , V_156 , V_770 ) ;
return 1 ;
}
static int F_329 ( struct V_1 * V_2 , void * V_156 , int V_770 )
{
if ( V_2 -> V_781 ) {
F_307 ( V_760 , V_770 ,
V_2 -> V_782 [ 0 ] . V_378 , * ( T_2 * ) V_156 ) ;
V_2 -> V_781 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_330 ( struct V_1 * V_2 , T_5 V_378 ,
void * V_156 , int V_770 )
{
return ! F_101 ( V_2 -> V_82 , V_378 , V_156 , V_770 ) ;
}
static int F_331 ( struct V_1 * V_2 , T_5 V_378 ,
void * V_156 , int V_770 )
{
return F_327 ( V_2 , V_378 , V_156 , V_770 ) ;
}
static int F_332 ( struct V_1 * V_2 , T_5 V_378 , int V_770 , void * V_156 )
{
F_307 ( V_783 , V_770 , V_378 , * ( T_2 * ) V_156 ) ;
return F_300 ( V_2 , V_378 , V_770 , V_156 ) ;
}
static int F_333 ( struct V_1 * V_2 , T_5 V_378 ,
void * V_156 , int V_770 )
{
F_307 ( V_784 , V_770 , V_378 , 0 ) ;
return V_774 ;
}
static int F_334 ( struct V_1 * V_2 , T_5 V_378 ,
void * V_156 , int V_770 )
{
struct V_785 * V_786 = & V_2 -> V_782 [ 0 ] ;
memcpy ( V_2 -> V_787 -> V_788 . V_31 , V_786 -> V_31 , F_301 ( 8u , V_786 -> V_75 ) ) ;
return V_771 ;
}
static int F_335 ( unsigned long V_363 , void * V_156 ,
unsigned int V_770 ,
struct V_58 * V_49 ,
struct V_1 * V_2 ,
const struct V_789 * V_790 )
{
T_5 V_378 ;
int V_757 , V_89 ;
bool V_778 = V_790 -> V_778 ;
struct V_785 * V_786 ;
V_89 = F_322 ( V_2 , V_363 , & V_378 , V_49 , V_778 ) ;
if ( V_89 < 0 )
return V_773 ;
if ( V_89 )
goto V_788;
if ( V_790 -> V_791 ( V_2 , V_378 , V_156 , V_770 ) )
return V_771 ;
V_788:
V_757 = V_790 -> V_792 ( V_2 , V_378 , V_770 , V_156 ) ;
if ( V_757 == V_770 )
return V_771 ;
V_378 += V_757 ;
V_770 -= V_757 ;
V_156 += V_757 ;
F_110 ( V_2 -> V_793 >= V_794 ) ;
V_786 = & V_2 -> V_782 [ V_2 -> V_793 ++ ] ;
V_786 -> V_378 = V_378 ;
V_786 -> V_31 = V_156 ;
V_786 -> V_75 = V_770 ;
return V_771 ;
}
int F_336 ( struct V_775 * V_776 , unsigned long V_363 ,
void * V_156 , unsigned int V_770 ,
struct V_58 * V_49 ,
const struct V_789 * V_790 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
T_5 V_378 ;
int V_795 ;
if ( V_790 -> V_796 &&
V_790 -> V_796 ( V_2 , V_156 , V_770 ) )
return V_771 ;
V_2 -> V_793 = 0 ;
if ( ( ( V_363 + V_770 - 1 ) ^ V_363 ) & V_352 ) {
int V_797 ;
V_797 = - V_363 & ~ V_352 ;
V_795 = F_335 ( V_363 , V_156 , V_797 , V_49 ,
V_2 , V_790 ) ;
if ( V_795 != V_771 )
return V_795 ;
V_363 += V_797 ;
V_156 += V_797 ;
V_770 -= V_797 ;
}
V_795 = F_335 ( V_363 , V_156 , V_770 , V_49 ,
V_2 , V_790 ) ;
if ( V_795 != V_771 )
return V_795 ;
if ( ! V_2 -> V_793 )
return V_795 ;
V_378 = V_2 -> V_782 [ 0 ] . V_378 ;
V_2 -> V_798 = 1 ;
V_2 -> V_799 = 0 ;
V_2 -> V_787 -> V_788 . V_75 = F_301 ( 8u , V_2 -> V_782 [ 0 ] . V_75 ) ;
V_2 -> V_787 -> V_788 . V_800 = V_2 -> V_801 = V_790 -> V_778 ;
V_2 -> V_787 -> V_802 = V_803 ;
V_2 -> V_787 -> V_788 . V_804 = V_378 ;
return V_790 -> V_805 ( V_2 , V_378 , V_156 , V_770 ) ;
}
static int F_337 ( struct V_775 * V_776 ,
unsigned long V_363 ,
void * V_156 ,
unsigned int V_770 ,
struct V_58 * V_49 )
{
return F_336 ( V_776 , V_363 , V_156 , V_770 ,
V_49 , & V_806 ) ;
}
int F_338 ( struct V_775 * V_776 ,
unsigned long V_363 ,
const void * V_156 ,
unsigned int V_770 ,
struct V_58 * V_49 )
{
return F_336 ( V_776 , V_363 , ( void * ) V_156 , V_770 ,
V_49 , & V_807 ) ;
}
static int F_339 ( struct V_775 * V_776 ,
unsigned long V_363 ,
const void * V_808 ,
const void * V_809 ,
unsigned int V_770 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
T_5 V_378 ;
struct V_354 * V_354 ;
char * V_810 ;
bool V_811 ;
if ( V_770 > 8 || ( V_770 & ( V_770 - 1 ) ) )
goto V_812;
V_378 = F_314 ( V_2 , V_363 , NULL ) ;
if ( V_378 == V_80 ||
( V_378 & V_352 ) == V_780 )
goto V_812;
if ( ( ( V_378 + V_770 - 1 ) & V_352 ) != ( V_378 & V_352 ) )
goto V_812;
V_354 = F_340 ( V_2 -> V_82 , V_378 >> V_87 ) ;
if ( F_341 ( V_354 ) )
goto V_812;
V_810 = F_342 ( V_354 ) ;
V_810 += F_343 ( V_378 ) ;
switch ( V_770 ) {
case 1 :
V_811 = F_344 ( T_13 , V_810 , V_808 , V_809 ) ;
break;
case 2 :
V_811 = F_344 ( V_813 , V_810 , V_808 , V_809 ) ;
break;
case 4 :
V_811 = F_344 ( T_1 , V_810 , V_808 , V_809 ) ;
break;
case 8 :
V_811 = F_345 ( V_810 , V_808 , V_809 ) ;
break;
default:
F_22 () ;
}
F_346 ( V_810 ) ;
F_347 ( V_354 ) ;
if ( ! V_811 )
return V_814 ;
F_328 ( V_2 , V_378 , V_809 , V_770 ) ;
return V_771 ;
V_812:
F_348 ( V_815 L_22 ) ;
return F_338 ( V_776 , V_363 , V_809 , V_770 , V_49 ) ;
}
static int F_349 ( struct V_1 * V_2 , void * V_816 )
{
int V_100 ;
if ( V_2 -> V_5 . V_817 . V_818 )
V_100 = F_306 ( V_2 -> V_82 , V_728 , V_2 -> V_5 . V_817 . V_819 ,
V_2 -> V_5 . V_817 . V_477 , V_816 ) ;
else
V_100 = F_303 ( V_2 -> V_82 , V_728 ,
V_2 -> V_5 . V_817 . V_819 , V_2 -> V_5 . V_817 . V_477 ,
V_816 ) ;
return V_100 ;
}
static int F_350 ( struct V_1 * V_2 , int V_477 ,
unsigned short V_819 , void * V_156 ,
unsigned int V_691 , bool V_818 )
{
F_351 ( ! V_818 , V_819 , V_477 , V_691 ) ;
V_2 -> V_5 . V_817 . V_819 = V_819 ;
V_2 -> V_5 . V_817 . V_818 = V_818 ;
V_2 -> V_5 . V_817 . V_691 = V_691 ;
V_2 -> V_5 . V_817 . V_477 = V_477 ;
if ( ! F_349 ( V_2 , V_2 -> V_5 . V_820 ) ) {
V_2 -> V_5 . V_817 . V_691 = 0 ;
return 1 ;
}
V_2 -> V_787 -> V_802 = V_821 ;
V_2 -> V_787 -> V_822 . V_823 = V_818 ? V_824 : V_825 ;
V_2 -> V_787 -> V_822 . V_477 = V_477 ;
V_2 -> V_787 -> V_822 . V_826 = V_827 * V_88 ;
V_2 -> V_787 -> V_822 . V_691 = V_691 ;
V_2 -> V_787 -> V_822 . V_819 = V_819 ;
return 0 ;
}
static int F_352 ( struct V_775 * V_776 ,
int V_477 , unsigned short V_819 , void * V_156 ,
unsigned int V_691 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
int V_89 ;
if ( V_2 -> V_5 . V_817 . V_691 )
goto V_828;
V_89 = F_350 ( V_2 , V_477 , V_819 , V_156 , V_691 , true ) ;
if ( V_89 ) {
V_828:
memcpy ( V_156 , V_2 -> V_5 . V_820 , V_477 * V_691 ) ;
V_2 -> V_5 . V_817 . V_691 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_353 ( struct V_775 * V_776 ,
int V_477 , unsigned short V_819 ,
const void * V_156 , unsigned int V_691 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
memcpy ( V_2 -> V_5 . V_820 , V_156 , V_477 * V_691 ) ;
return F_350 ( V_2 , V_477 , V_819 , ( void * ) V_156 , V_691 , false ) ;
}
static unsigned long F_354 ( struct V_1 * V_2 , int V_763 )
{
return V_56 -> F_354 ( V_2 , V_763 ) ;
}
static void F_355 ( struct V_775 * V_776 , V_144 V_63 )
{
F_356 ( F_318 ( V_776 ) , V_63 ) ;
}
int F_357 ( struct V_1 * V_2 )
{
if ( ! F_225 ( V_2 ) )
return V_771 ;
if ( V_56 -> V_559 () ) {
int V_23 = F_358 () ;
F_227 ( V_23 , V_2 -> V_5 . V_560 ) ;
F_359 ( V_2 -> V_5 . V_560 ,
F_223 , NULL , 1 ) ;
F_360 () ;
F_361 ( V_2 -> V_5 . V_560 ) ;
} else
F_224 () ;
return V_771 ;
}
static void F_362 ( struct V_775 * V_776 )
{
F_357 ( F_318 ( V_776 ) ) ;
}
int F_363 ( struct V_775 * V_776 , int V_155 , unsigned long * V_829 )
{
return F_84 ( F_318 ( V_776 ) , V_155 , V_829 ) ;
}
int F_364 ( struct V_775 * V_776 , int V_155 , unsigned long V_22 )
{
return F_82 ( F_318 ( V_776 ) , V_155 , V_22 ) ;
}
static T_2 F_365 ( T_2 V_830 , T_1 V_831 )
{
return ( V_830 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_831 ;
}
static unsigned long F_366 ( struct V_775 * V_776 , int V_832 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
unsigned long V_22 ;
switch ( V_832 ) {
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
V_22 = F_79 ( V_2 ) ;
break;
default:
F_367 ( L_23 , V_224 , V_832 ) ;
return 0 ;
}
return V_22 ;
}
static int F_368 ( struct V_775 * V_776 , int V_832 , V_144 V_156 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
int V_165 = 0 ;
switch ( V_832 ) {
case 0 :
V_165 = F_52 ( V_2 , F_365 ( F_53 ( V_2 ) , V_156 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_62 = V_156 ;
break;
case 3 :
V_165 = F_73 ( V_2 , V_156 ) ;
break;
case 4 :
V_165 = F_66 ( V_2 , F_365 ( F_67 ( V_2 ) , V_156 ) ) ;
break;
case 8 :
V_165 = F_76 ( V_2 , V_156 ) ;
break;
default:
F_367 ( L_23 , V_224 , V_832 ) ;
V_165 = - 1 ;
}
return V_165 ;
}
static void F_369 ( struct V_775 * V_776 , V_144 V_156 )
{
F_370 ( F_318 ( V_776 ) , V_156 ) ;
}
static int F_371 ( struct V_775 * V_776 )
{
return V_56 -> V_71 ( F_318 ( V_776 ) ) ;
}
static void F_372 ( struct V_775 * V_776 , struct V_833 * V_834 )
{
V_56 -> V_835 ( F_318 ( V_776 ) , V_834 ) ;
}
static void F_373 ( struct V_775 * V_776 , struct V_833 * V_834 )
{
V_56 -> V_836 ( F_318 ( V_776 ) , V_834 ) ;
}
static void F_374 ( struct V_775 * V_776 , struct V_833 * V_834 )
{
V_56 -> V_837 ( F_318 ( V_776 ) , V_834 ) ;
}
static void F_375 ( struct V_775 * V_776 , struct V_833 * V_834 )
{
V_56 -> V_838 ( F_318 ( V_776 ) , V_834 ) ;
}
static unsigned long F_376 (
struct V_775 * V_776 , int V_763 )
{
return F_354 ( F_318 ( V_776 ) , V_763 ) ;
}
static bool F_377 ( struct V_775 * V_776 , V_813 * V_839 ,
struct V_840 * V_841 , T_1 * V_842 ,
int V_763 )
{
struct V_761 V_762 ;
F_309 ( F_318 ( V_776 ) , & V_762 , V_763 ) ;
* V_839 = V_762 . V_839 ;
if ( V_762 . V_843 ) {
memset ( V_841 , 0 , sizeof( * V_841 ) ) ;
return false ;
}
if ( V_762 . V_844 )
V_762 . V_845 >>= 12 ;
F_378 ( V_841 , V_762 . V_845 ) ;
F_379 ( V_841 , ( unsigned long ) V_762 . V_846 ) ;
#ifdef F_54
if ( V_842 )
* V_842 = V_762 . V_846 >> 32 ;
#endif
V_841 -> type = V_762 . type ;
V_841 -> V_567 = V_762 . V_567 ;
V_841 -> V_847 = V_762 . V_847 ;
V_841 -> V_323 = V_762 . V_848 ;
V_841 -> V_849 = V_762 . V_849 ;
V_841 -> V_850 = V_762 . V_850 ;
V_841 -> V_851 = V_762 . V_157 ;
V_841 -> V_844 = V_762 . V_844 ;
return true ;
}
static void F_380 ( struct V_775 * V_776 , V_813 V_839 ,
struct V_840 * V_841 , T_1 V_842 ,
int V_763 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
struct V_761 V_762 ;
V_762 . V_839 = V_839 ;
V_762 . V_846 = F_381 ( V_841 ) ;
#ifdef F_54
V_762 . V_846 |= ( ( T_2 ) V_842 ) << 32 ;
#endif
V_762 . V_845 = F_382 ( V_841 ) ;
if ( V_841 -> V_844 )
V_762 . V_845 = ( V_762 . V_845 << 12 ) | 0xfff ;
V_762 . type = V_841 -> type ;
V_762 . V_848 = V_841 -> V_323 ;
V_762 . V_847 = V_841 -> V_847 ;
V_762 . V_157 = V_841 -> V_851 ;
V_762 . V_567 = V_841 -> V_567 ;
V_762 . V_850 = V_841 -> V_850 ;
V_762 . V_844 = V_841 -> V_844 ;
V_762 . V_849 = V_841 -> V_849 ;
V_762 . V_848 = V_841 -> V_323 ;
V_762 . V_843 = ! V_762 . V_848 ;
V_762 . V_852 = 0 ;
F_308 ( V_2 , & V_762 , V_763 ) ;
return;
}
static int F_383 ( struct V_775 * V_776 ,
T_1 V_450 , T_2 * V_451 )
{
return F_200 ( F_318 ( V_776 ) , V_450 , V_451 ) ;
}
static int F_384 ( struct V_775 * V_776 ,
T_1 V_450 , T_2 V_31 )
{
struct V_182 V_21 ;
V_21 . V_31 = V_31 ;
V_21 . V_124 = V_450 ;
V_21 . V_184 = false ;
return F_95 ( F_318 ( V_776 ) , & V_21 ) ;
}
static int F_385 ( struct V_775 * V_776 ,
T_1 V_853 , T_2 * V_451 )
{
return F_88 ( F_318 ( V_776 ) , V_853 , V_451 ) ;
}
static void F_386 ( struct V_775 * V_776 )
{
F_318 ( V_776 ) -> V_5 . V_854 = 1 ;
}
static void F_387 ( struct V_775 * V_776 )
{
F_192 () ;
F_388 ( F_318 ( V_776 ) ) ;
F_389 () ;
}
static void F_390 ( struct V_775 * V_776 )
{
F_193 () ;
}
static int F_391 ( struct V_775 * V_776 ,
struct V_855 * V_856 ,
enum V_857 V_858 )
{
return V_56 -> V_859 ( F_318 ( V_776 ) , V_856 , V_858 ) ;
}
static void F_392 ( struct V_775 * V_776 ,
T_1 * V_860 , T_1 * V_861 , T_1 * V_167 , T_1 * V_175 )
{
V_640 ( F_318 ( V_776 ) , V_860 , V_861 , V_167 , V_175 ) ;
}
static V_144 F_393 ( struct V_775 * V_776 , unsigned V_862 )
{
return F_87 ( F_318 ( V_776 ) , V_862 ) ;
}
static void F_394 ( struct V_775 * V_776 , unsigned V_862 , V_144 V_156 )
{
F_89 ( F_318 ( V_776 ) , V_862 , V_156 ) ;
}
static void F_395 ( struct V_1 * V_2 , T_1 V_27 )
{
T_1 V_863 = V_56 -> V_596 ( V_2 , V_27 ) ;
if ( ! ( V_863 & V_27 ) )
V_56 -> V_609 ( V_2 , V_27 ) ;
}
static void F_396 ( struct V_1 * V_2 )
{
struct V_775 * V_776 = & V_2 -> V_5 . V_864 ;
if ( V_776 -> V_49 . V_32 == V_33 )
F_32 ( V_2 , & V_776 -> V_49 ) ;
else if ( V_776 -> V_49 . V_865 )
F_31 ( V_2 , V_776 -> V_49 . V_32 ,
V_776 -> V_49 . V_43 ) ;
else
F_26 ( V_2 , V_776 -> V_49 . V_32 ) ;
}
static void F_397 ( struct V_775 * V_776 )
{
memset ( & V_776 -> V_866 , 0 ,
( void * ) & V_776 -> V_867 - ( void * ) & V_776 -> V_866 ) ;
V_776 -> V_868 . V_693 = 0 ;
V_776 -> V_868 . V_869 = 0 ;
V_776 -> V_870 . V_871 = 0 ;
V_776 -> V_870 . V_869 = 0 ;
V_776 -> V_872 . V_871 = 0 ;
V_776 -> V_872 . V_869 = 0 ;
}
static void F_398 ( struct V_1 * V_2 )
{
struct V_775 * V_776 = & V_2 -> V_5 . V_864 ;
int V_113 , V_114 ;
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
V_776 -> V_873 = F_399 ( V_2 ) ;
V_776 -> V_874 = F_400 ( V_2 ) ;
V_776 -> V_281 = ( ! F_401 ( V_2 ) ) ? V_875 :
( V_776 -> V_873 & V_876 ) ? V_877 :
V_114 ? V_878 :
V_113 ? V_879 :
V_880 ;
V_776 -> V_881 = F_402 ( V_2 ) ;
F_397 ( V_776 ) ;
V_2 -> V_5 . V_882 = false ;
}
int F_403 ( struct V_1 * V_2 , int V_572 , int V_883 )
{
struct V_775 * V_776 = & V_2 -> V_5 . V_864 ;
int V_89 ;
F_398 ( V_2 ) ;
V_776 -> V_884 = 2 ;
V_776 -> V_885 = 2 ;
V_776 -> V_886 = V_776 -> V_874 + V_883 ;
V_89 = F_404 ( V_776 , V_572 ) ;
if ( V_89 != V_771 )
return V_887 ;
V_776 -> V_874 = V_776 -> V_886 ;
F_405 ( V_2 , V_776 -> V_874 ) ;
F_370 ( V_2 , V_776 -> V_873 ) ;
if ( V_572 == V_888 )
V_2 -> V_5 . V_601 = 0 ;
else
V_2 -> V_5 . V_593 . V_50 = false ;
return V_889 ;
}
static int F_406 ( struct V_1 * V_2 )
{
int V_100 = V_889 ;
++ V_2 -> V_60 . V_890 ;
F_407 ( V_2 ) ;
if ( ! F_402 ( V_2 ) ) {
V_2 -> V_787 -> V_802 = V_891 ;
V_2 -> V_787 -> V_892 . V_893 = V_894 ;
V_2 -> V_787 -> V_892 . V_895 = 0 ;
V_100 = V_887 ;
}
F_26 ( V_2 , V_166 ) ;
return V_100 ;
}
static bool F_408 ( struct V_1 * V_2 , T_14 V_62 ,
bool V_896 ,
int V_897 )
{
T_5 V_378 = V_62 ;
T_15 V_898 ;
if ( V_897 & V_899 )
return false ;
if ( ! V_2 -> V_5 . V_67 . V_900 ) {
V_378 = F_314 ( V_2 , V_62 , NULL ) ;
if ( V_378 == V_80 )
return true ;
}
V_898 = F_409 ( V_2 -> V_82 , F_40 ( V_378 ) ) ;
if ( F_410 ( V_898 ) )
return false ;
F_411 ( V_898 ) ;
if ( V_2 -> V_5 . V_67 . V_900 ) {
unsigned int V_901 ;
F_130 ( & V_2 -> V_82 -> V_708 ) ;
V_901 = V_2 -> V_82 -> V_5 . V_901 ;
F_131 ( & V_2 -> V_82 -> V_708 ) ;
if ( V_901 )
F_412 ( V_2 -> V_82 , F_40 ( V_378 ) ) ;
return true ;
}
F_412 ( V_2 -> V_82 , F_40 ( V_378 ) ) ;
return ! V_896 ;
}
static bool F_413 ( struct V_775 * V_776 ,
unsigned long V_62 , int V_897 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
unsigned long V_902 , V_903 , V_378 = V_62 ;
V_902 = V_2 -> V_5 . V_902 ;
V_903 = V_2 -> V_5 . V_903 ;
V_2 -> V_5 . V_902 = V_2 -> V_5 . V_903 = 0 ;
if ( ! ( V_897 & V_904 ) )
return false ;
if ( F_414 ( V_776 ) )
return false ;
if ( V_776 -> V_874 == V_902 && V_903 == V_62 )
return false ;
V_2 -> V_5 . V_902 = V_776 -> V_874 ;
V_2 -> V_5 . V_903 = V_62 ;
if ( ! V_2 -> V_5 . V_67 . V_900 )
V_378 = F_314 ( V_2 , V_62 , NULL ) ;
F_412 ( V_2 -> V_82 , F_40 ( V_378 ) ) ;
return true ;
}
static int F_415 ( unsigned long V_363 , T_1 type , T_1 V_148 ,
unsigned long * V_157 )
{
T_1 V_160 = 0 ;
int V_3 ;
T_1 V_905 , V_906 ;
V_905 = V_148 ;
V_906 = V_148 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_905 >>= 2 , V_906 >>= 4 )
if ( ( V_905 & 3 ) && ( V_906 & 15 ) == type && V_157 [ V_3 ] == V_363 )
V_160 |= ( 1 << V_3 ) ;
return V_160 ;
}
static void F_416 ( struct V_1 * V_2 , int * V_100 )
{
struct V_907 * V_907 = V_2 -> V_787 ;
unsigned long V_908 = V_56 -> V_909 ( V_2 ) ;
if ( F_139 ( V_908 & V_910 ) ) {
if ( V_2 -> V_149 & V_911 ) {
V_907 -> V_912 . V_5 . V_160 = V_913 | V_162 ;
V_907 -> V_912 . V_5 . V_914 = V_2 -> V_5 . V_915 ;
V_907 -> V_912 . V_5 . V_49 = V_916 ;
V_907 -> V_802 = V_917 ;
* V_100 = V_918 ;
} else {
V_2 -> V_5 . V_864 . V_873 &= ~ V_910 ;
V_2 -> V_5 . V_160 &= ~ 15 ;
V_2 -> V_5 . V_160 |= V_913 ;
F_26 ( V_2 , V_916 ) ;
}
}
}
static bool F_417 ( struct V_1 * V_2 , int * V_100 )
{
struct V_907 * V_907 = V_2 -> V_787 ;
unsigned long V_874 = V_2 -> V_5 . V_864 . V_874 ;
T_1 V_160 = 0 ;
if ( F_139 ( V_2 -> V_149 & V_150 ) &&
( V_2 -> V_5 . V_151 & V_154 ) ) {
V_160 = F_415 ( V_874 , 0 ,
V_2 -> V_5 . V_151 ,
V_2 -> V_5 . V_158 ) ;
if ( V_160 != 0 ) {
V_907 -> V_912 . V_5 . V_160 = V_160 | V_162 ;
V_907 -> V_912 . V_5 . V_914 = F_400 ( V_2 ) +
F_354 ( V_2 , V_919 ) ;
V_907 -> V_912 . V_5 . V_49 = V_916 ;
V_907 -> V_802 = V_917 ;
* V_100 = V_918 ;
return true ;
}
}
if ( F_139 ( V_2 -> V_5 . V_148 & V_154 ) ) {
V_160 = F_415 ( V_874 , 0 ,
V_2 -> V_5 . V_148 ,
V_2 -> V_5 . V_157 ) ;
if ( V_160 != 0 ) {
V_2 -> V_5 . V_160 &= ~ 15 ;
V_2 -> V_5 . V_160 |= V_160 ;
F_26 ( V_2 , V_916 ) ;
* V_100 = V_889 ;
return true ;
}
}
return false ;
}
int F_418 ( struct V_1 * V_2 ,
unsigned long V_62 ,
int V_897 ,
void * V_920 ,
int V_921 )
{
int V_100 ;
struct V_775 * V_776 = & V_2 -> V_5 . V_864 ;
bool V_475 = true ;
bool V_922 = V_2 -> V_5 . V_896 ;
V_2 -> V_5 . V_896 = false ;
F_419 ( V_2 ) ;
if ( ! ( V_897 & V_923 ) ) {
F_398 ( V_2 ) ;
if ( F_417 ( V_2 , & V_100 ) )
return V_100 ;
V_776 -> V_924 = 0 ;
V_776 -> V_925 = false ;
V_776 -> V_926 = false ;
V_776 -> V_927
= V_897 & V_928 ;
V_100 = F_420 ( V_776 , V_920 , V_921 ) ;
F_421 ( V_2 ) ;
++ V_2 -> V_60 . V_929 ;
if ( V_100 != V_930 ) {
if ( V_897 & V_928 )
return V_887 ;
if ( F_408 ( V_2 , V_62 , V_922 ,
V_897 ) )
return V_889 ;
if ( V_897 & V_931 )
return V_887 ;
return F_406 ( V_2 ) ;
}
}
if ( V_897 & V_931 ) {
F_405 ( V_2 , V_776 -> V_886 ) ;
return V_889 ;
}
if ( F_413 ( V_776 , V_62 , V_897 ) )
return V_889 ;
if ( V_2 -> V_5 . V_882 ) {
V_2 -> V_5 . V_882 = false ;
F_422 ( V_776 ) ;
}
V_932:
V_100 = F_423 ( V_776 ) ;
if ( V_100 == V_933 )
return V_889 ;
if ( V_100 == V_934 ) {
if ( F_408 ( V_2 , V_62 , V_922 ,
V_897 ) )
return V_889 ;
return F_406 ( V_2 ) ;
}
if ( V_776 -> V_925 ) {
F_396 ( V_2 ) ;
V_100 = V_889 ;
} else if ( V_2 -> V_5 . V_817 . V_691 ) {
if ( ! V_2 -> V_5 . V_817 . V_818 ) {
V_2 -> V_5 . V_817 . V_691 = 0 ;
} else {
V_475 = false ;
V_2 -> V_5 . V_935 = V_936 ;
}
V_100 = V_918 ;
} else if ( V_2 -> V_798 ) {
if ( ! V_2 -> V_801 )
V_475 = false ;
V_100 = V_918 ;
V_2 -> V_5 . V_935 = V_937 ;
} else if ( V_100 == V_938 )
goto V_932;
else
V_100 = V_889 ;
if ( V_475 ) {
F_395 ( V_2 , V_776 -> V_924 ) ;
F_25 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_939 = false ;
F_405 ( V_2 , V_776 -> V_874 ) ;
if ( V_100 == V_889 )
F_416 ( V_2 , & V_100 ) ;
F_370 ( V_2 , V_776 -> V_873 ) ;
} else
V_2 -> V_5 . V_939 = true ;
return V_100 ;
}
int F_424 ( struct V_1 * V_2 , int V_477 , unsigned short V_819 )
{
unsigned long V_156 = F_87 ( V_2 , V_169 ) ;
int V_89 = F_353 ( & V_2 -> V_5 . V_864 ,
V_477 , V_819 , & V_156 , 1 ) ;
V_2 -> V_5 . V_817 . V_691 = 0 ;
return V_89 ;
}
static void F_425 ( void * V_856 )
{
F_426 ( V_295 , 0 ) ;
}
static void F_427 ( void * V_31 )
{
struct V_940 * V_941 = V_31 ;
unsigned long V_227 = 0 ;
if ( V_31 )
V_227 = V_941 -> V_809 ;
else if ( ! F_220 ( V_942 ) )
V_227 = F_428 ( F_429 () ) ;
if ( ! V_227 )
V_227 = V_235 ;
F_426 ( V_295 , V_227 ) ;
}
static int F_430 ( struct V_943 * V_944 , unsigned long V_156 ,
void * V_31 )
{
struct V_940 * V_941 = V_31 ;
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 , V_945 = 0 ;
if ( V_156 == V_946 && V_941 -> V_808 > V_941 -> V_809 )
return 0 ;
if ( V_156 == V_947 && V_941 -> V_808 < V_941 -> V_809 )
return 0 ;
F_228 ( V_941 -> V_23 , F_427 , V_941 , 1 ) ;
F_431 ( & V_948 ) ;
F_432 (kvm, &vm_list, vm_list) {
F_148 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_941 -> V_23 )
continue;
F_25 ( V_286 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_945 = 1 ;
}
}
F_433 ( & V_948 ) ;
if ( V_941 -> V_808 < V_941 -> V_809 && V_945 ) {
F_228 ( V_941 -> V_23 , F_427 , V_941 , 1 ) ;
}
return 0 ;
}
static int F_434 ( struct V_943 * V_949 ,
unsigned long V_950 , void * V_951 )
{
unsigned int V_23 = ( unsigned long ) V_951 ;
switch ( V_950 ) {
case V_952 :
case V_953 :
F_228 ( V_23 , F_427 , NULL , 1 ) ;
break;
case V_954 :
F_228 ( V_23 , F_425 , NULL , 1 ) ;
break;
}
return V_955 ;
}
static void F_435 ( void )
{
int V_23 ;
V_956 = V_235 ;
F_436 ( & V_957 ) ;
if ( ! F_220 ( V_942 ) ) {
#ifdef F_437
struct V_958 V_959 ;
memset ( & V_959 , 0 , sizeof( V_959 ) ) ;
V_23 = F_358 () ;
F_438 ( & V_959 , V_23 ) ;
if ( V_959 . V_960 . V_961 )
V_956 = V_959 . V_960 . V_961 ;
F_360 () ;
#endif
F_439 ( & V_962 ,
V_963 ) ;
}
F_108 ( L_24 , V_956 ) ;
F_440 (cpu)
F_228 ( V_23 , F_427 , NULL , 1 ) ;
}
int F_441 ( void )
{
return F_442 ( V_964 ) != NULL ;
}
static int F_443 ( void )
{
int V_965 = 3 ;
if ( F_442 ( V_964 ) )
V_965 = V_56 -> V_71 ( F_442 ( V_964 ) ) ;
return V_965 != 0 ;
}
static unsigned long F_444 ( void )
{
unsigned long V_966 = 0 ;
if ( F_442 ( V_964 ) )
V_966 = F_400 ( F_442 ( V_964 ) ) ;
return V_966 ;
}
void F_445 ( struct V_1 * V_2 )
{
F_426 ( V_964 , V_2 ) ;
}
void F_446 ( struct V_1 * V_2 )
{
F_426 ( V_964 , NULL ) ;
}
static void F_447 ( void )
{
T_2 V_27 ;
int V_967 = V_968 . V_969 ;
V_27 = ( ( 1ull << ( 51 - V_967 + 1 ) ) - 1 ) << V_967 ;
V_27 |= 0x3ull << 62 ;
V_27 |= 1ull ;
#ifdef F_54
if ( V_967 == 52 )
V_27 &= ~ 1ull ;
#endif
F_448 ( V_27 ) ;
}
static void F_449 ( struct V_970 * V_971 )
{
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 ;
F_431 ( & V_948 ) ;
F_432 (kvm, &vm_list, vm_list)
F_148 (i, vcpu, kvm)
F_149 ( V_251 , & V_2 -> V_287 ) ;
F_144 ( & V_285 , 0 ) ;
F_433 ( & V_948 ) ;
}
static int F_450 ( struct V_943 * V_944 , unsigned long V_972 ,
void * V_973 )
{
struct V_187 * V_246 = & V_187 ;
struct V_185 * V_186 = V_973 ;
F_97 ( V_186 ) ;
if ( V_246 -> clock . V_190 != V_249 &&
F_122 ( & V_285 ) != 0 )
F_451 ( V_974 , & V_975 ) ;
return 0 ;
}
int F_452 ( void * V_976 )
{
int V_100 ;
struct V_56 * V_790 = V_976 ;
if ( V_56 ) {
F_10 ( V_26 L_25 ) ;
V_100 = - V_726 ;
goto V_94;
}
if ( ! V_790 -> V_977 () ) {
F_10 ( V_26 L_26 ) ;
V_100 = - V_978 ;
goto V_94;
}
if ( V_790 -> V_979 () ) {
F_10 ( V_26 L_27 ) ;
V_100 = - V_978 ;
goto V_94;
}
V_100 = - V_356 ;
V_25 = F_453 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_94;
}
V_100 = F_454 () ;
if ( V_100 )
goto V_980;
F_447 () ;
F_298 () ;
V_56 = V_790 ;
F_455 ( V_981 , V_982 ,
V_983 , V_984 , 0 ) ;
F_435 () ;
F_456 ( & V_985 ) ;
if ( V_529 )
V_123 = F_457 ( V_121 ) ;
F_458 () ;
#ifdef F_54
F_459 ( & V_986 ) ;
#endif
return 0 ;
V_980:
F_460 ( V_25 ) ;
V_94:
return V_100 ;
}
void F_461 ( void )
{
F_462 ( & V_985 ) ;
if ( ! F_220 ( V_942 ) )
F_463 ( & V_962 ,
V_963 ) ;
F_464 ( & V_957 ) ;
#ifdef F_54
F_465 ( & V_986 ) ;
#endif
V_56 = NULL ;
F_466 () ;
F_460 ( V_25 ) ;
}
int F_467 ( struct V_1 * V_2 )
{
++ V_2 -> V_60 . V_987 ;
if ( F_77 ( V_2 -> V_82 ) ) {
V_2 -> V_5 . V_988 = V_989 ;
return 1 ;
} else {
V_2 -> V_787 -> V_802 = V_990 ;
return 0 ;
}
}
int F_468 ( struct V_1 * V_2 )
{
T_2 V_991 , V_992 , V_993 , V_89 ;
T_16 V_994 , V_995 , V_996 , V_165 = V_997 , V_998 = 0 ;
bool V_999 , V_1000 ;
int V_113 , V_114 ;
if ( V_56 -> V_71 ( V_2 ) != 0 || ! F_401 ( V_2 ) ) {
F_26 ( V_2 , V_166 ) ;
return 0 ;
}
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
V_1000 = F_48 ( V_2 ) && V_114 == 1 ;
if ( ! V_1000 ) {
V_991 = ( ( T_2 ) F_87 ( V_2 , V_170 ) << 32 ) |
( F_87 ( V_2 , V_169 ) & 0xffffffff ) ;
V_992 = ( ( T_2 ) F_87 ( V_2 , V_1001 ) << 32 ) |
( F_87 ( V_2 , V_168 ) & 0xffffffff ) ;
V_993 = ( ( T_2 ) F_87 ( V_2 , V_1002 ) << 32 ) |
( F_87 ( V_2 , V_1003 ) & 0xffffffff ) ;
}
#ifdef F_54
else {
V_991 = F_87 ( V_2 , V_168 ) ;
V_992 = F_87 ( V_2 , V_170 ) ;
V_993 = F_87 ( V_2 , V_1004 ) ;
}
#endif
V_994 = V_991 & 0xffff ;
V_999 = ( V_991 >> 16 ) & 0x1 ;
V_996 = ( V_991 >> 32 ) & 0xfff ;
V_995 = ( V_991 >> 48 ) & 0xfff ;
F_469 ( V_994 , V_999 , V_996 , V_995 , V_992 , V_993 ) ;
switch ( V_994 ) {
case V_1005 :
F_470 ( V_2 ) ;
break;
default:
V_165 = V_1006 ;
break;
}
V_89 = V_165 | ( ( ( T_2 ) V_998 & 0xfff ) << 32 ) ;
if ( V_1000 ) {
F_89 ( V_2 , V_169 , V_89 ) ;
} else {
F_89 ( V_2 , V_170 , V_89 >> 32 ) ;
F_89 ( V_2 , V_169 , V_89 & 0xffffffff ) ;
}
return 1 ;
}
static void F_471 ( struct V_82 * V_82 , unsigned long V_258 , int V_1007 )
{
struct V_1008 V_1009 ;
V_1009 . V_1010 = 0 ;
V_1009 . V_1011 = 0 ;
V_1009 . V_1012 = V_1007 ;
V_1009 . V_1013 = V_1014 ;
F_472 ( V_82 , 0 , & V_1009 , NULL ) ;
}
int F_473 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1015 , V_1016 , V_1017 , V_1018 , V_89 ;
int V_100 = 1 ;
if ( F_172 ( V_2 -> V_82 ) )
return F_468 ( V_2 ) ;
V_16 = F_87 ( V_2 , V_169 ) ;
V_1015 = F_87 ( V_2 , V_1001 ) ;
V_1016 = F_87 ( V_2 , V_168 ) ;
V_1017 = F_87 ( V_2 , V_170 ) ;
V_1018 = F_87 ( V_2 , V_1003 ) ;
F_474 ( V_16 , V_1015 , V_1016 , V_1017 , V_1018 ) ;
if ( ! F_48 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_1015 &= 0xFFFFFFFF ;
V_1016 &= 0xFFFFFFFF ;
V_1017 &= 0xFFFFFFFF ;
V_1018 &= 0xFFFFFFFF ;
}
if ( V_56 -> V_71 ( V_2 ) != 0 ) {
V_89 = - V_1019 ;
goto V_94;
}
switch ( V_16 ) {
case V_1020 :
V_89 = 0 ;
break;
case V_1021 :
F_471 ( V_2 -> V_82 , V_1015 , V_1016 ) ;
V_89 = 0 ;
break;
default:
V_89 = - V_1022 ;
break;
}
V_94:
F_89 ( V_2 , V_169 , V_89 ) ;
++ V_2 -> V_60 . V_1023 ;
return V_100 ;
}
static int F_475 ( struct V_775 * V_776 )
{
struct V_1 * V_2 = F_318 ( V_776 ) ;
char V_1024 [ 3 ] ;
unsigned long V_1025 = F_400 ( V_2 ) ;
V_56 -> V_366 ( V_2 , V_1024 ) ;
return F_338 ( V_776 , V_1025 , V_1024 , 3 , NULL ) ;
}
static int F_476 ( struct V_1 * V_2 )
{
return ( ! F_77 ( V_2 -> V_82 ) && ! F_477 ( V_2 ) &&
V_2 -> V_787 -> V_1026 &&
F_478 ( V_2 ) ) ;
}
static void F_479 ( struct V_1 * V_2 )
{
struct V_907 * V_907 = V_2 -> V_787 ;
V_907 -> V_1027 = ( F_399 ( V_2 ) & V_1028 ) != 0 ;
V_907 -> V_146 = F_79 ( V_2 ) ;
V_907 -> V_30 = F_18 ( V_2 ) ;
if ( F_77 ( V_2 -> V_82 ) )
V_907 -> V_1029 = 1 ;
else
V_907 -> V_1029 =
F_478 ( V_2 ) &&
! F_477 ( V_2 ) &&
! F_480 ( V_2 ) ;
}
static int F_481 ( struct V_1 * V_2 )
{
struct V_1030 * V_570 = V_2 -> V_5 . V_570 ;
struct V_354 * V_354 ;
if ( ! V_570 || ! V_570 -> V_649 )
return 0 ;
V_354 = F_340 ( V_2 -> V_82 , V_570 -> V_649 >> V_87 ) ;
if ( F_341 ( V_354 ) )
return - V_81 ;
V_2 -> V_5 . V_570 -> V_1031 = V_354 ;
return 0 ;
}
static void F_482 ( struct V_1 * V_2 )
{
struct V_1030 * V_570 = V_2 -> V_5 . V_570 ;
int V_329 ;
if ( ! V_570 || ! V_570 -> V_649 )
return;
V_329 = F_212 ( & V_2 -> V_82 -> V_472 ) ;
F_347 ( V_570 -> V_1031 ) ;
F_483 ( V_2 -> V_82 , V_570 -> V_649 >> V_87 ) ;
F_213 ( & V_2 -> V_82 -> V_472 , V_329 ) ;
}
static void F_237 ( struct V_1 * V_2 )
{
int V_1032 , V_1033 ;
if ( ! V_56 -> F_237 )
return;
if ( ! V_2 -> V_5 . V_570 )
return;
if ( ! V_2 -> V_5 . V_570 -> V_649 )
V_1032 = F_484 ( V_2 ) ;
else
V_1032 = - 1 ;
if ( V_1032 != - 1 )
V_1032 >>= 4 ;
V_1033 = F_80 ( V_2 ) ;
V_56 -> F_237 ( V_2 , V_1033 , V_1032 ) ;
}
static void F_485 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_49 . V_50 ) {
F_486 ( V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ) ;
V_56 -> V_1034 ( V_2 , V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ,
V_2 -> V_5 . V_49 . V_44 ) ;
return;
}
if ( V_2 -> V_5 . V_600 ) {
V_56 -> V_1035 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_593 . V_50 ) {
V_56 -> V_1036 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_601 ) {
if ( V_56 -> V_1037 ( V_2 ) ) {
-- V_2 -> V_5 . V_601 ;
V_2 -> V_5 . V_600 = true ;
V_56 -> V_1035 ( V_2 ) ;
}
} else if ( F_487 ( V_2 ) ) {
if ( V_56 -> V_1038 ( V_2 ) ) {
F_239 ( V_2 , F_488 ( V_2 ) ,
false ) ;
V_56 -> V_1036 ( V_2 ) ;
}
}
}
static void F_245 ( struct V_1 * V_2 )
{
unsigned V_845 = 2 ;
if ( V_56 -> V_603 ( V_2 ) || V_2 -> V_5 . V_600 )
V_845 = 1 ;
V_2 -> V_5 . V_601 += F_489 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_601 = F_301 ( V_2 -> V_5 . V_601 , V_845 ) ;
F_25 ( V_48 , V_2 ) ;
}
static void F_490 ( struct V_1 * V_2 )
{
T_2 V_1039 [ 4 ] ;
T_1 V_1040 [ 8 ] ;
if ( ! F_491 ( V_2 -> V_5 . V_570 ) )
return;
memset ( V_1039 , 0 , 32 ) ;
memset ( V_1040 , 0 , 32 ) ;
F_492 ( V_2 , V_1039 , V_1040 ) ;
V_56 -> V_1041 ( V_2 , V_1039 ) ;
F_493 ( V_2 , V_1040 ) ;
}
static int F_494 ( struct V_1 * V_2 )
{
int V_100 ;
bool V_1042 = ! F_77 ( V_2 -> V_82 ) &&
V_2 -> V_787 -> V_1026 ;
bool V_1043 = false ;
if ( V_2 -> V_287 ) {
if ( F_495 ( V_1044 , V_2 ) )
F_496 ( V_2 ) ;
if ( F_495 ( V_1045 , V_2 ) )
F_497 ( V_2 ) ;
if ( F_495 ( V_251 , V_2 ) )
F_146 ( V_2 -> V_82 ) ;
if ( F_495 ( V_420 , V_2 ) )
F_159 ( V_2 ) ;
if ( F_495 ( V_286 , V_2 ) ) {
V_100 = F_151 ( V_2 ) ;
if ( F_139 ( V_100 ) )
goto V_94;
}
if ( F_495 ( V_1046 , V_2 ) )
F_74 ( V_2 ) ;
if ( F_495 ( V_1047 , V_2 ) )
V_56 -> V_1048 ( V_2 ) ;
if ( F_495 ( V_1049 , V_2 ) ) {
V_2 -> V_787 -> V_802 = V_1050 ;
V_100 = 0 ;
goto V_94;
}
if ( F_495 ( V_54 , V_2 ) ) {
V_2 -> V_787 -> V_802 = V_1051 ;
V_100 = 0 ;
goto V_94;
}
if ( F_495 ( V_1052 , V_2 ) ) {
V_2 -> V_1053 = 0 ;
V_56 -> V_1054 ( V_2 ) ;
}
if ( F_495 ( V_1055 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1056 = true ;
V_100 = 1 ;
goto V_94;
}
if ( F_495 ( V_425 , V_2 ) )
F_187 ( V_2 ) ;
if ( F_495 ( V_69 , V_2 ) )
F_245 ( V_2 ) ;
if ( F_495 ( V_1057 , V_2 ) )
F_498 ( V_2 ) ;
if ( F_495 ( V_1058 , V_2 ) )
F_499 ( V_2 ) ;
if ( F_495 ( V_1059 , V_2 ) )
F_490 ( V_2 ) ;
}
if ( F_495 ( V_48 , V_2 ) || V_1042 ) {
F_500 ( V_2 ) ;
if ( V_2 -> V_5 . V_988 == V_1060 ) {
V_100 = 1 ;
goto V_94;
}
F_485 ( V_2 ) ;
if ( V_2 -> V_5 . V_601 )
V_1043 =
V_56 -> V_1061 ( V_2 ) != 0 ;
else if ( F_487 ( V_2 ) || V_1042 )
V_1043 =
V_56 -> V_1062 ( V_2 ) != 0 ;
if ( F_501 ( V_2 ) ) {
if ( V_56 -> V_1063 )
V_56 -> V_1063 ( V_2 ,
F_484 ( V_2 ) ) ;
F_237 ( V_2 ) ;
F_502 ( V_2 ) ;
}
}
V_100 = F_503 ( V_2 ) ;
if ( F_139 ( V_100 ) ) {
goto V_1064;
}
F_192 () ;
V_56 -> V_1065 ( V_2 ) ;
if ( V_2 -> V_1053 )
F_388 ( V_2 ) ;
F_61 ( V_2 ) ;
V_2 -> V_281 = V_1066 ;
F_504 () ;
F_296 () ;
if ( V_2 -> V_281 == V_1067 || V_2 -> V_287
|| F_505 () || F_506 ( V_385 ) ) {
V_2 -> V_281 = V_1068 ;
F_13 () ;
F_297 () ;
F_193 () ;
V_100 = 1 ;
goto V_1064;
}
F_213 ( & V_2 -> V_82 -> V_472 , V_2 -> V_1069 ) ;
if ( V_1043 )
F_507 ( V_2 -> V_23 ) ;
F_508 () ;
if ( F_139 ( V_2 -> V_5 . V_153 ) ) {
F_509 ( 0 , 7 ) ;
F_509 ( V_2 -> V_5 . V_158 [ 0 ] , 0 ) ;
F_509 ( V_2 -> V_5 . V_158 [ 1 ] , 1 ) ;
F_509 ( V_2 -> V_5 . V_158 [ 2 ] , 2 ) ;
F_509 ( V_2 -> V_5 . V_158 [ 3 ] , 3 ) ;
}
F_510 ( V_2 -> V_252 ) ;
V_56 -> V_787 ( V_2 ) ;
if ( F_511 () )
F_512 () ;
V_2 -> V_5 . V_275 = V_56 -> V_296 ( V_2 ,
F_155 () ) ;
V_2 -> V_281 = V_1068 ;
F_13 () ;
V_56 -> V_1070 ( V_2 ) ;
++ V_2 -> V_60 . V_1071 ;
F_513 () ;
F_514 () ;
F_193 () ;
V_2 -> V_1069 = F_212 ( & V_2 -> V_82 -> V_472 ) ;
if ( F_139 ( V_1072 == V_1073 ) ) {
unsigned long V_1025 = F_400 ( V_2 ) ;
F_515 ( V_1073 , ( void * ) V_1025 ) ;
}
if ( F_139 ( V_2 -> V_5 . V_1074 ) )
F_25 ( V_286 , V_2 ) ;
if ( V_2 -> V_5 . V_1075 )
F_516 ( V_2 ) ;
V_100 = V_56 -> V_1076 ( V_2 ) ;
return V_100 ;
V_1064:
V_56 -> V_1064 ( V_2 ) ;
if ( F_139 ( V_2 -> V_5 . V_1075 ) )
F_516 ( V_2 ) ;
V_94:
return V_100 ;
}
static int F_517 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_82 * V_82 = V_2 -> V_82 ;
V_2 -> V_1069 = F_212 ( & V_82 -> V_472 ) ;
V_100 = F_481 ( V_2 ) ;
if ( V_100 ) {
F_213 ( & V_82 -> V_472 , V_2 -> V_1069 ) ;
return V_100 ;
}
V_100 = 1 ;
while ( V_100 > 0 ) {
if ( V_2 -> V_5 . V_988 == V_1077 &&
! V_2 -> V_5 . V_6 . V_1056 )
V_100 = F_494 ( V_2 ) ;
else {
F_213 ( & V_82 -> V_472 , V_2 -> V_1069 ) ;
F_518 ( V_2 ) ;
V_2 -> V_1069 = F_212 ( & V_82 -> V_472 ) ;
if ( F_495 ( V_1078 , V_2 ) ) {
F_500 ( V_2 ) ;
switch( V_2 -> V_5 . V_988 ) {
case V_989 :
V_2 -> V_5 . V_1079 . V_1080 = false ;
V_2 -> V_5 . V_988 =
V_1077 ;
case V_1077 :
V_2 -> V_5 . V_6 . V_1056 = false ;
break;
case V_1060 :
break;
default:
V_100 = - V_1081 ;
break;
}
}
}
if ( V_100 <= 0 )
break;
F_150 ( V_1082 , & V_2 -> V_287 ) ;
if ( F_519 ( V_2 ) )
F_520 ( V_2 ) ;
if ( F_476 ( V_2 ) ) {
V_100 = - V_1081 ;
V_2 -> V_787 -> V_802 = V_1083 ;
++ V_2 -> V_60 . V_1084 ;
}
F_521 ( V_2 ) ;
if ( F_506 ( V_385 ) ) {
V_100 = - V_1081 ;
V_2 -> V_787 -> V_802 = V_1083 ;
++ V_2 -> V_60 . V_1085 ;
}
if ( F_505 () ) {
F_213 ( & V_82 -> V_472 , V_2 -> V_1069 ) ;
F_522 ( V_2 ) ;
V_2 -> V_1069 = F_212 ( & V_82 -> V_472 ) ;
}
}
F_213 ( & V_82 -> V_472 , V_2 -> V_1069 ) ;
F_482 ( V_2 ) ;
return V_100 ;
}
static inline int F_523 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_1069 = F_212 ( & V_2 -> V_82 -> V_472 ) ;
V_100 = F_524 ( V_2 , V_923 ) ;
F_213 ( & V_2 -> V_82 -> V_472 , V_2 -> V_1069 ) ;
if ( V_100 != V_889 )
return 0 ;
return 1 ;
}
static int V_936 ( struct V_1 * V_2 )
{
F_311 ( ! V_2 -> V_5 . V_817 . V_691 ) ;
return F_523 ( V_2 ) ;
}
static int V_937 ( struct V_1 * V_2 )
{
struct V_907 * V_787 = V_2 -> V_787 ;
struct V_785 * V_786 ;
unsigned V_75 ;
F_311 ( ! V_2 -> V_798 ) ;
V_786 = & V_2 -> V_782 [ V_2 -> V_799 ] ;
V_75 = F_301 ( 8u , V_786 -> V_75 ) ;
if ( ! V_2 -> V_801 )
memcpy ( V_786 -> V_31 , V_787 -> V_788 . V_31 , V_75 ) ;
if ( V_786 -> V_75 <= 8 ) {
V_786 ++ ;
V_2 -> V_799 ++ ;
} else {
V_786 -> V_31 += V_75 ;
V_786 -> V_378 += V_75 ;
V_786 -> V_75 -= V_75 ;
}
if ( V_2 -> V_799 == V_2 -> V_793 ) {
V_2 -> V_798 = 0 ;
if ( V_2 -> V_801 )
return 1 ;
V_2 -> V_781 = 1 ;
return F_523 ( V_2 ) ;
}
V_787 -> V_802 = V_803 ;
V_787 -> V_788 . V_804 = V_786 -> V_378 ;
if ( V_2 -> V_801 )
memcpy ( V_787 -> V_788 . V_31 , V_786 -> V_31 , F_301 ( 8u , V_786 -> V_75 ) ) ;
V_787 -> V_788 . V_75 = F_301 ( 8u , V_786 -> V_75 ) ;
V_787 -> V_788 . V_800 = V_2 -> V_801 ;
V_2 -> V_5 . V_935 = V_937 ;
return 0 ;
}
int F_525 ( struct V_1 * V_2 , struct V_907 * V_907 )
{
int V_100 ;
T_17 V_1086 ;
if ( ! F_526 ( V_385 ) && F_527 ( V_385 ) )
return - V_356 ;
if ( V_2 -> V_1087 )
F_528 ( V_1088 , & V_2 -> V_1089 , & V_1086 ) ;
if ( F_139 ( V_2 -> V_5 . V_988 == V_1090 ) ) {
F_518 ( V_2 ) ;
F_500 ( V_2 ) ;
F_150 ( V_1078 , & V_2 -> V_287 ) ;
V_100 = - V_1091 ;
goto V_94;
}
if ( ! F_77 ( V_2 -> V_82 ) ) {
if ( F_76 ( V_2 , V_907 -> V_146 ) != 0 ) {
V_100 = - V_554 ;
goto V_94;
}
}
if ( F_139 ( V_2 -> V_5 . V_935 ) ) {
int (* F_529)( struct V_1 * ) = V_2 -> V_5 . V_935 ;
V_2 -> V_5 . V_935 = NULL ;
V_100 = F_529 ( V_2 ) ;
if ( V_100 <= 0 )
goto V_94;
} else
F_110 ( V_2 -> V_5 . V_817 . V_691 || V_2 -> V_798 ) ;
V_100 = F_517 ( V_2 ) ;
V_94:
F_479 ( V_2 ) ;
if ( V_2 -> V_1087 )
F_528 ( V_1088 , & V_1086 , NULL ) ;
return V_100 ;
}
int F_530 ( struct V_1 * V_2 , struct V_1092 * V_569 )
{
if ( V_2 -> V_5 . V_939 ) {
F_531 ( & V_2 -> V_5 . V_864 ) ;
V_2 -> V_5 . V_939 = false ;
}
V_569 -> V_1093 = F_87 ( V_2 , V_169 ) ;
V_569 -> V_1094 = F_87 ( V_2 , V_1001 ) ;
V_569 -> V_1095 = F_87 ( V_2 , V_168 ) ;
V_569 -> V_1096 = F_87 ( V_2 , V_170 ) ;
V_569 -> V_1097 = F_87 ( V_2 , V_1003 ) ;
V_569 -> V_1098 = F_87 ( V_2 , V_1002 ) ;
V_569 -> V_1099 = F_87 ( V_2 , V_1100 ) ;
V_569 -> V_1101 = F_87 ( V_2 , V_1102 ) ;
#ifdef F_54
V_569 -> V_1103 = F_87 ( V_2 , V_1004 ) ;
V_569 -> V_1104 = F_87 ( V_2 , V_1105 ) ;
V_569 -> V_1106 = F_87 ( V_2 , V_1107 ) ;
V_569 -> V_1108 = F_87 ( V_2 , V_1109 ) ;
V_569 -> V_1110 = F_87 ( V_2 , V_1111 ) ;
V_569 -> V_1112 = F_87 ( V_2 , V_1113 ) ;
V_569 -> V_1114 = F_87 ( V_2 , V_1115 ) ;
V_569 -> V_1116 = F_87 ( V_2 , V_1117 ) ;
#endif
V_569 -> V_1025 = F_400 ( V_2 ) ;
V_569 -> V_908 = F_399 ( V_2 ) ;
return 0 ;
}
int F_532 ( struct V_1 * V_2 , struct V_1092 * V_569 )
{
V_2 -> V_5 . V_882 = true ;
V_2 -> V_5 . V_939 = false ;
F_89 ( V_2 , V_169 , V_569 -> V_1093 ) ;
F_89 ( V_2 , V_1001 , V_569 -> V_1094 ) ;
F_89 ( V_2 , V_168 , V_569 -> V_1095 ) ;
F_89 ( V_2 , V_170 , V_569 -> V_1096 ) ;
F_89 ( V_2 , V_1003 , V_569 -> V_1097 ) ;
F_89 ( V_2 , V_1002 , V_569 -> V_1098 ) ;
F_89 ( V_2 , V_1100 , V_569 -> V_1099 ) ;
F_89 ( V_2 , V_1102 , V_569 -> V_1101 ) ;
#ifdef F_54
F_89 ( V_2 , V_1004 , V_569 -> V_1103 ) ;
F_89 ( V_2 , V_1105 , V_569 -> V_1104 ) ;
F_89 ( V_2 , V_1107 , V_569 -> V_1106 ) ;
F_89 ( V_2 , V_1109 , V_569 -> V_1108 ) ;
F_89 ( V_2 , V_1111 , V_569 -> V_1110 ) ;
F_89 ( V_2 , V_1113 , V_569 -> V_1112 ) ;
F_89 ( V_2 , V_1115 , V_569 -> V_1114 ) ;
F_89 ( V_2 , V_1117 , V_569 -> V_1116 ) ;
#endif
F_405 ( V_2 , V_569 -> V_1025 ) ;
F_370 ( V_2 , V_569 -> V_908 ) ;
V_2 -> V_5 . V_49 . V_50 = false ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
void F_533 ( struct V_1 * V_2 , int * V_157 , int * V_850 )
{
struct V_761 V_1118 ;
F_309 ( V_2 , & V_1118 , V_919 ) ;
* V_157 = V_1118 . V_157 ;
* V_850 = V_1118 . V_850 ;
}
int F_534 ( struct V_1 * V_2 ,
struct V_1119 * V_1120 )
{
struct V_833 V_834 ;
F_309 ( V_2 , & V_1120 -> V_1118 , V_919 ) ;
F_309 ( V_2 , & V_1120 -> V_1121 , V_1122 ) ;
F_309 ( V_2 , & V_1120 -> V_1123 , V_1124 ) ;
F_309 ( V_2 , & V_1120 -> V_1125 , V_1126 ) ;
F_309 ( V_2 , & V_1120 -> V_1127 , V_1128 ) ;
F_309 ( V_2 , & V_1120 -> V_1129 , V_1130 ) ;
F_309 ( V_2 , & V_1120 -> V_1131 , V_1132 ) ;
F_309 ( V_2 , & V_1120 -> V_1133 , V_1134 ) ;
V_56 -> V_836 ( V_2 , & V_834 ) ;
V_1120 -> V_1135 . V_845 = V_834 . V_477 ;
V_1120 -> V_1135 . V_846 = V_834 . V_63 ;
V_56 -> V_835 ( V_2 , & V_834 ) ;
V_1120 -> V_1136 . V_845 = V_834 . V_477 ;
V_1120 -> V_1136 . V_846 = V_834 . V_63 ;
V_1120 -> V_101 = F_53 ( V_2 ) ;
V_1120 -> V_62 = V_2 -> V_5 . V_62 ;
V_1120 -> V_85 = F_51 ( V_2 ) ;
V_1120 -> V_129 = F_67 ( V_2 ) ;
V_1120 -> V_146 = F_79 ( V_2 ) ;
V_1120 -> V_111 = V_2 -> V_5 . V_111 ;
V_1120 -> V_30 = F_18 ( V_2 ) ;
memset ( V_1120 -> V_1137 , 0 , sizeof V_1120 -> V_1137 ) ;
if ( V_2 -> V_5 . V_593 . V_50 && ! V_2 -> V_5 . V_593 . V_594 )
F_149 ( V_2 -> V_5 . V_593 . V_16 ,
( unsigned long * ) V_1120 -> V_1137 ) ;
return 0 ;
}
int F_535 ( struct V_1 * V_2 ,
struct V_1138 * V_988 )
{
F_500 ( V_2 ) ;
if ( V_2 -> V_5 . V_988 == V_989 &&
V_2 -> V_5 . V_1079 . V_1080 )
V_988 -> V_988 = V_1077 ;
else
V_988 -> V_988 = V_2 -> V_5 . V_988 ;
return 0 ;
}
int F_536 ( struct V_1 * V_2 ,
struct V_1138 * V_988 )
{
if ( ! F_248 ( V_2 ) &&
V_988 -> V_988 != V_1077 )
return - V_554 ;
if ( V_988 -> V_988 == V_1139 ) {
V_2 -> V_5 . V_988 = V_1060 ;
F_149 ( V_1140 , & V_2 -> V_5 . V_570 -> V_1141 ) ;
} else
V_2 -> V_5 . V_988 = V_988 -> V_988 ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
int F_537 ( struct V_1 * V_2 , V_813 V_1142 , int V_1143 ,
int V_1144 , bool V_52 , T_1 V_43 )
{
struct V_775 * V_776 = & V_2 -> V_5 . V_864 ;
int V_89 ;
F_398 ( V_2 ) ;
V_89 = F_538 ( V_776 , V_1142 , V_1143 , V_1144 ,
V_52 , V_43 ) ;
if ( V_89 )
return V_887 ;
F_405 ( V_2 , V_776 -> V_874 ) ;
F_370 ( V_2 , V_776 -> V_873 ) ;
F_25 ( V_48 , V_2 ) ;
return V_889 ;
}
int F_539 ( struct V_1 * V_2 ,
struct V_1119 * V_1120 )
{
int V_1145 = 0 ;
int V_1146 , V_1147 , V_329 ;
struct V_833 V_834 ;
if ( ! F_68 ( V_2 ) && ( V_1120 -> V_129 & V_119 ) )
return - V_554 ;
V_834 . V_477 = V_1120 -> V_1135 . V_845 ;
V_834 . V_63 = V_1120 -> V_1135 . V_846 ;
V_56 -> V_838 ( V_2 , & V_834 ) ;
V_834 . V_477 = V_1120 -> V_1136 . V_845 ;
V_834 . V_63 = V_1120 -> V_1136 . V_846 ;
V_56 -> V_837 ( V_2 , & V_834 ) ;
V_2 -> V_5 . V_62 = V_1120 -> V_62 ;
V_1145 |= F_51 ( V_2 ) != V_1120 -> V_85 ;
V_2 -> V_5 . V_85 = V_1120 -> V_85 ;
F_46 ( V_143 , ( V_144 * ) & V_2 -> V_5 . V_97 ) ;
F_76 ( V_2 , V_1120 -> V_146 ) ;
V_1145 |= V_2 -> V_5 . V_111 != V_1120 -> V_111 ;
V_56 -> F_93 ( V_2 , V_1120 -> V_111 ) ;
F_19 ( V_2 , V_1120 -> V_30 ) ;
V_1145 |= F_53 ( V_2 ) != V_1120 -> V_101 ;
V_56 -> V_117 ( V_2 , V_1120 -> V_101 ) ;
V_2 -> V_5 . V_101 = V_1120 -> V_101 ;
V_1145 |= F_67 ( V_2 ) != V_1120 -> V_129 ;
V_56 -> V_139 ( V_2 , V_1120 -> V_129 ) ;
if ( V_1120 -> V_129 & V_119 )
F_72 ( V_2 ) ;
V_329 = F_212 ( & V_2 -> V_82 -> V_472 ) ;
if ( ! F_48 ( V_2 ) && F_49 ( V_2 ) ) {
F_43 ( V_2 , V_2 -> V_5 . V_84 , F_51 ( V_2 ) ) ;
V_1145 = 1 ;
}
F_213 ( & V_2 -> V_82 -> V_472 , V_329 ) ;
if ( V_1145 )
F_58 ( V_2 ) ;
V_1147 = V_573 ;
V_1146 = F_540 (
( const unsigned long * ) V_1120 -> V_1137 , V_1147 ) ;
if ( V_1146 < V_1147 ) {
F_239 ( V_2 , V_1146 , false ) ;
F_108 ( L_29 , V_1146 ) ;
}
F_308 ( V_2 , & V_1120 -> V_1118 , V_919 ) ;
F_308 ( V_2 , & V_1120 -> V_1121 , V_1122 ) ;
F_308 ( V_2 , & V_1120 -> V_1123 , V_1124 ) ;
F_308 ( V_2 , & V_1120 -> V_1125 , V_1126 ) ;
F_308 ( V_2 , & V_1120 -> V_1127 , V_1128 ) ;
F_308 ( V_2 , & V_1120 -> V_1129 , V_1130 ) ;
F_308 ( V_2 , & V_1120 -> V_1131 , V_1132 ) ;
F_308 ( V_2 , & V_1120 -> V_1133 , V_1134 ) ;
F_237 ( V_2 ) ;
if ( F_541 ( V_2 ) && F_400 ( V_2 ) == 0xfff0 &&
V_1120 -> V_1118 . V_839 == 0xf000 && V_1120 -> V_1118 . V_846 == 0xffff0000 &&
! F_401 ( V_2 ) )
V_2 -> V_5 . V_988 = V_1077 ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
int F_542 ( struct V_1 * V_2 ,
struct V_1148 * V_1149 )
{
unsigned long V_908 ;
int V_3 , V_100 ;
if ( V_1149 -> V_698 & ( V_1150 | V_1151 ) ) {
V_100 = - V_1152 ;
if ( V_2 -> V_5 . V_49 . V_50 )
goto V_94;
if ( V_1149 -> V_698 & V_1150 )
F_26 ( V_2 , V_916 ) ;
else
F_26 ( V_2 , V_1153 ) ;
}
V_908 = F_399 ( V_2 ) ;
V_2 -> V_149 = V_1149 -> V_698 ;
if ( ! ( V_2 -> V_149 & V_1154 ) )
V_2 -> V_149 = 0 ;
if ( V_2 -> V_149 & V_150 ) {
for ( V_3 = 0 ; V_3 < V_1155 ; ++ V_3 )
V_2 -> V_5 . V_158 [ V_3 ] = V_1149 -> V_5 . V_1156 [ V_3 ] ;
V_2 -> V_5 . V_151 = V_1149 -> V_5 . V_1156 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1155 ; V_3 ++ )
V_2 -> V_5 . V_158 [ V_3 ] = V_2 -> V_5 . V_157 [ V_3 ] ;
}
F_81 ( V_2 ) ;
if ( V_2 -> V_149 & V_911 )
V_2 -> V_5 . V_915 = F_400 ( V_2 ) +
F_354 ( V_2 , V_919 ) ;
F_370 ( V_2 , V_908 ) ;
V_56 -> V_1157 ( V_2 ) ;
V_100 = 0 ;
V_94:
return V_100 ;
}
int F_543 ( struct V_1 * V_2 ,
struct V_1158 * V_1131 )
{
unsigned long V_1159 = V_1131 -> V_1160 ;
T_5 V_378 ;
int V_329 ;
V_329 = F_212 ( & V_2 -> V_82 -> V_472 ) ;
V_378 = F_315 ( V_2 , V_1159 , NULL ) ;
F_213 ( & V_2 -> V_82 -> V_472 , V_329 ) ;
V_1131 -> V_1161 = V_378 ;
V_1131 -> V_1162 = V_378 != V_80 ;
V_1131 -> V_1163 = 1 ;
V_1131 -> V_1164 = 0 ;
return 0 ;
}
int F_544 ( struct V_1 * V_2 , struct V_1165 * V_1166 )
{
struct V_621 * V_620 =
& V_2 -> V_5 . V_616 . V_617 -> V_620 ;
memcpy ( V_1166 -> V_1167 , V_620 -> V_1168 , 128 ) ;
V_1166 -> V_1169 = V_620 -> V_1170 ;
V_1166 -> V_1171 = V_620 -> V_1172 ;
V_1166 -> V_1173 = V_620 -> V_1174 ;
V_1166 -> V_1175 = V_620 -> V_1176 ;
V_1166 -> V_1177 = V_620 -> V_1025 ;
V_1166 -> V_1178 = V_620 -> V_1179 ;
memcpy ( V_1166 -> V_1180 , V_620 -> V_1181 , sizeof V_620 -> V_1181 ) ;
return 0 ;
}
int F_545 ( struct V_1 * V_2 , struct V_1165 * V_1166 )
{
struct V_621 * V_620 =
& V_2 -> V_5 . V_616 . V_617 -> V_620 ;
memcpy ( V_620 -> V_1168 , V_1166 -> V_1167 , 128 ) ;
V_620 -> V_1170 = V_1166 -> V_1169 ;
V_620 -> V_1172 = V_1166 -> V_1171 ;
V_620 -> V_1174 = V_1166 -> V_1173 ;
V_620 -> V_1176 = V_1166 -> V_1175 ;
V_620 -> V_1025 = V_1166 -> V_1177 ;
V_620 -> V_1179 = V_1166 -> V_1178 ;
memcpy ( V_620 -> V_1181 , V_1166 -> V_1180 , sizeof V_620 -> V_1181 ) ;
return 0 ;
}
int F_546 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_547 ( & V_2 -> V_5 . V_616 ) ;
if ( V_55 )
return V_55 ;
F_548 ( & V_2 -> V_5 . V_616 ) ;
V_2 -> V_5 . V_122 = V_126 ;
V_2 -> V_5 . V_101 |= V_108 ;
return 0 ;
}
static void F_549 ( struct V_1 * V_2 )
{
F_550 ( & V_2 -> V_5 . V_616 ) ;
}
void F_388 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1182 )
return;
F_63 ( V_2 ) ;
V_2 -> V_1182 = 1 ;
F_551 () ;
F_552 ( & V_2 -> V_5 . V_616 ) ;
F_553 ( 1 ) ;
}
void F_233 ( struct V_1 * V_2 )
{
F_63 ( V_2 ) ;
if ( ! V_2 -> V_1182 )
return;
V_2 -> V_1182 = 0 ;
F_554 ( & V_2 -> V_5 . V_616 ) ;
F_555 () ;
++ V_2 -> V_60 . V_1183 ;
F_25 ( V_1052 , V_2 ) ;
F_553 ( 0 ) ;
}
void F_556 ( struct V_1 * V_2 )
{
F_185 ( V_2 ) ;
F_557 ( V_2 -> V_5 . V_560 ) ;
F_549 ( V_2 ) ;
V_56 -> V_1184 ( V_2 ) ;
}
struct V_1 * F_558 ( struct V_82 * V_82 ,
unsigned int V_1185 )
{
if ( F_127 () && F_122 ( & V_82 -> V_248 ) != 0 )
F_348 ( V_815
L_30
L_31 ) ;
return V_56 -> V_1186 ( V_82 , V_1185 ) ;
}
int F_559 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_5 . V_324 . V_1187 = 1 ;
V_100 = V_561 ( V_2 ) ;
if ( V_100 )
return V_100 ;
F_560 ( V_2 ) ;
V_100 = F_561 ( V_2 ) ;
V_565 ( V_2 ) ;
return V_100 ;
}
int F_562 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_182 V_21 ;
V_100 = V_561 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_21 . V_31 = 0x0 ;
V_21 . V_124 = V_1188 ;
V_21 . V_184 = true ;
F_125 ( V_2 , & V_21 ) ;
V_565 ( V_2 ) ;
return V_100 ;
}
void F_563 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_5 . V_6 . V_379 = 0 ;
V_100 = V_561 ( V_2 ) ;
F_311 ( V_100 ) ;
F_496 ( V_2 ) ;
V_565 ( V_2 ) ;
F_549 ( V_2 ) ;
V_56 -> V_1184 ( V_2 ) ;
}
void F_560 ( struct V_1 * V_2 )
{
F_144 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_601 = 0 ;
V_2 -> V_5 . V_600 = false ;
memset ( V_2 -> V_5 . V_157 , 0 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_2 -> V_5 . V_160 = V_162 ;
V_2 -> V_5 . V_148 = V_164 ;
F_81 ( V_2 ) ;
F_25 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_6 . V_379 = 0 ;
V_2 -> V_5 . V_383 . V_379 = 0 ;
F_185 ( V_2 ) ;
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1056 = false ;
F_564 ( V_2 ) ;
memset ( V_2 -> V_5 . V_569 , 0 , sizeof( V_2 -> V_5 . V_569 ) ) ;
V_2 -> V_5 . V_97 = ~ 0 ;
V_2 -> V_5 . V_98 = ~ 0 ;
V_56 -> V_1189 ( V_2 ) ;
}
void F_565 ( struct V_1 * V_2 , unsigned int V_32 )
{
struct V_761 V_1118 ;
F_309 ( V_2 , & V_1118 , V_919 ) ;
V_1118 . V_839 = V_32 << 8 ;
V_1118 . V_846 = V_32 << 12 ;
F_308 ( V_2 , & V_1118 , V_919 ) ;
F_405 ( V_2 , 0 ) ;
}
int F_566 ( void * V_555 )
{
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 ;
int V_89 ;
T_2 V_1190 ;
T_2 V_1191 = 0 ;
bool V_1192 , V_1193 = false ;
F_14 () ;
V_89 = V_56 -> V_1194 ( V_555 ) ;
if ( V_89 != 0 )
return V_89 ;
V_1190 = F_155 () ;
V_1192 = ! F_127 () ;
F_432 (kvm, &vm_list, vm_list) {
F_148 (i, vcpu, kvm) {
if ( ! V_1192 && V_2 -> V_23 == F_8 () )
F_149 ( V_286 , & V_2 -> V_287 ) ;
if ( V_1192 && V_2 -> V_5 . V_564 > V_1190 ) {
V_1193 = true ;
if ( V_2 -> V_5 . V_564 > V_1191 )
V_1191 = V_2 -> V_5 . V_564 ;
}
}
}
if ( V_1193 ) {
T_2 V_1195 = V_1191 - V_1190 ;
F_432 (kvm, &vm_list, vm_list) {
F_148 (i, vcpu, kvm) {
V_2 -> V_5 . V_562 += V_1195 ;
V_2 -> V_5 . V_564 = V_1190 ;
F_149 ( V_251 ,
& V_2 -> V_287 ) ;
}
V_82 -> V_5 . V_263 = 0 ;
V_82 -> V_5 . V_265 = 0 ;
}
}
return 0 ;
}
void F_567 ( void * V_555 )
{
V_56 -> V_1196 ( V_555 ) ;
F_17 ( V_555 ) ;
}
int F_568 ( void )
{
return V_56 -> V_1197 () ;
}
void F_569 ( void )
{
V_56 -> V_1198 () ;
}
void F_570 ( void * V_1199 )
{
V_56 -> V_1200 ( V_1199 ) ;
}
bool F_571 ( struct V_1 * V_2 )
{
return F_77 ( V_2 -> V_82 ) == ( V_2 -> V_5 . V_570 != NULL ) ;
}
int F_572 ( struct V_1 * V_2 )
{
struct V_354 * V_354 ;
struct V_82 * V_82 ;
int V_100 ;
F_311 ( V_2 -> V_82 == NULL ) ;
V_82 = V_2 -> V_82 ;
V_2 -> V_5 . V_1079 . V_1080 = false ;
V_2 -> V_5 . V_864 . V_790 = & V_1201 ;
if ( ! F_77 ( V_82 ) || F_541 ( V_2 ) )
V_2 -> V_5 . V_988 = V_1077 ;
else
V_2 -> V_5 . V_988 = V_1090 ;
V_354 = F_573 ( V_635 | V_1202 ) ;
if ( ! V_354 ) {
V_100 = - V_356 ;
goto V_1203;
}
V_2 -> V_5 . V_820 = F_574 ( V_354 ) ;
F_119 ( V_2 , V_956 ) ;
V_100 = F_575 ( V_2 ) ;
if ( V_100 < 0 )
goto V_1204;
if ( F_77 ( V_82 ) ) {
V_100 = F_576 ( V_2 ) ;
if ( V_100 < 0 )
goto V_1205;
} else
F_577 ( & V_1206 ) ;
V_2 -> V_5 . V_343 = F_257 ( V_427 * sizeof( T_2 ) * 4 ,
V_635 ) ;
if ( ! V_2 -> V_5 . V_343 ) {
V_100 = - V_356 ;
goto V_1207;
}
V_2 -> V_5 . V_335 = V_427 ;
if ( ! F_578 ( & V_2 -> V_5 . V_560 , V_635 ) ) {
V_100 = - V_356 ;
goto V_1208;
}
V_100 = F_546 ( V_2 ) ;
if ( V_100 )
goto V_1209;
V_2 -> V_5 . V_255 = 0x0 ;
V_2 -> V_5 . V_298 = false ;
F_1 ( V_2 ) ;
F_579 ( V_2 ) ;
return 0 ;
V_1209:
F_557 ( V_2 -> V_5 . V_560 ) ;
V_1208:
F_171 ( V_2 -> V_5 . V_343 ) ;
V_1207:
F_580 ( V_2 ) ;
V_1205:
F_581 ( V_2 ) ;
V_1204:
F_582 ( ( unsigned long ) V_2 -> V_5 . V_820 ) ;
V_1203:
return V_100 ;
}
void F_583 ( struct V_1 * V_2 )
{
int V_329 ;
F_584 ( V_2 ) ;
F_171 ( V_2 -> V_5 . V_343 ) ;
F_580 ( V_2 ) ;
V_329 = F_212 ( & V_2 -> V_82 -> V_472 ) ;
F_581 ( V_2 ) ;
F_213 ( & V_2 -> V_82 -> V_472 , V_329 ) ;
F_582 ( ( unsigned long ) V_2 -> V_5 . V_820 ) ;
if ( ! F_77 ( V_2 -> V_82 ) )
F_585 ( & V_1206 ) ;
}
int F_586 ( struct V_82 * V_82 , unsigned long type )
{
if ( type )
return - V_554 ;
F_587 ( & V_82 -> V_5 . V_1210 ) ;
F_587 ( & V_82 -> V_5 . V_1211 ) ;
F_587 ( & V_82 -> V_5 . V_1212 ) ;
F_149 ( V_713 , & V_82 -> V_5 . V_1213 ) ;
F_149 ( V_1214 ,
& V_82 -> V_5 . V_1213 ) ;
F_588 ( & V_82 -> V_5 . V_261 ) ;
F_589 ( & V_82 -> V_5 . V_1215 ) ;
F_590 ( & V_82 -> V_5 . V_278 ) ;
F_143 ( V_82 ) ;
return 0 ;
}
static void F_591 ( struct V_1 * V_2 )
{
int V_100 ;
V_100 = V_561 ( V_2 ) ;
F_311 ( V_100 ) ;
F_496 ( V_2 ) ;
V_565 ( V_2 ) ;
}
static void F_592 ( struct V_82 * V_82 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_148 (i, vcpu, kvm) {
F_57 ( V_2 ) ;
F_591 ( V_2 ) ;
}
F_148 (i, vcpu, kvm)
F_556 ( V_2 ) ;
F_197 ( & V_82 -> V_442 ) ;
for ( V_3 = 0 ; V_3 < F_122 ( & V_82 -> V_248 ) ; V_3 ++ )
V_82 -> V_1216 [ V_3 ] = NULL ;
F_144 ( & V_82 -> V_248 , 0 ) ;
F_198 ( & V_82 -> V_442 ) ;
}
void F_593 ( struct V_82 * V_82 )
{
F_594 ( V_82 ) ;
F_595 ( V_82 ) ;
}
void F_596 ( struct V_82 * V_82 )
{
if ( V_385 -> V_1217 == V_82 -> V_1217 ) {
struct V_1218 V_1219 ;
memset ( & V_1219 , 0 , sizeof( V_1219 ) ) ;
V_1219 . V_10 = V_1220 ;
F_597 ( V_82 , & V_1219 ) ;
V_1219 . V_10 = V_1221 ;
F_597 ( V_82 , & V_1219 ) ;
V_1219 . V_10 = V_1222 ;
F_597 ( V_82 , & V_1219 ) ;
}
F_598 ( V_82 ) ;
F_171 ( V_82 -> V_5 . V_725 ) ;
F_171 ( V_82 -> V_5 . V_1223 ) ;
F_592 ( V_82 ) ;
if ( V_82 -> V_5 . V_1224 )
F_599 ( V_82 -> V_5 . V_1224 ) ;
if ( V_82 -> V_5 . V_1225 )
F_599 ( V_82 -> V_5 . V_1225 ) ;
F_171 ( F_600 ( V_82 -> V_5 . V_1226 , 1 ) ) ;
}
void F_601 ( struct V_701 * free ,
struct V_701 * V_1227 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1228 ; ++ V_3 ) {
if ( ! V_1227 || free -> V_5 . V_1229 [ V_3 ] != V_1227 -> V_5 . V_1229 [ V_3 ] ) {
F_602 ( free -> V_5 . V_1229 [ V_3 ] ) ;
free -> V_5 . V_1229 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1227 || free -> V_5 . V_1230 [ V_3 - 1 ] !=
V_1227 -> V_5 . V_1230 [ V_3 - 1 ] ) {
F_602 ( free -> V_5 . V_1230 [ V_3 - 1 ] ) ;
free -> V_5 . V_1230 [ V_3 - 1 ] = NULL ;
}
}
}
int F_603 ( struct V_701 * V_10 , unsigned long V_1231 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1228 ; ++ V_3 ) {
unsigned long V_1232 ;
int V_1233 ;
int V_714 = V_3 + 1 ;
V_1233 = F_604 ( V_10 -> V_1234 + V_1231 - 1 ,
V_10 -> V_1234 , V_714 ) + 1 ;
V_10 -> V_5 . V_1229 [ V_3 ] =
F_605 ( V_1233 * sizeof( * V_10 -> V_5 . V_1229 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1229 [ V_3 ] )
goto V_357;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1230 [ V_3 - 1 ] = F_605 ( V_1233 *
sizeof( * V_10 -> V_5 . V_1230 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1230 [ V_3 - 1 ] )
goto V_357;
if ( V_10 -> V_1234 & ( F_606 ( V_714 ) - 1 ) )
V_10 -> V_5 . V_1230 [ V_3 - 1 ] [ 0 ] . V_1235 = 1 ;
if ( ( V_10 -> V_1234 + V_1231 ) & ( F_606 ( V_714 ) - 1 ) )
V_10 -> V_5 . V_1230 [ V_3 - 1 ] [ V_1233 - 1 ] . V_1235 = 1 ;
V_1232 = V_10 -> V_1236 >> V_87 ;
if ( ( V_10 -> V_1234 ^ V_1232 ) & ( F_606 ( V_714 ) - 1 ) ||
! F_607 () ) {
unsigned long V_755 ;
for ( V_755 = 0 ; V_755 < V_1233 ; ++ V_755 )
V_10 -> V_5 . V_1230 [ V_3 - 1 ] [ V_755 ] . V_1235 = 1 ;
}
}
return 0 ;
V_357:
for ( V_3 = 0 ; V_3 < V_1228 ; ++ V_3 ) {
F_602 ( V_10 -> V_5 . V_1229 [ V_3 ] ) ;
V_10 -> V_5 . V_1229 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_602 ( V_10 -> V_5 . V_1230 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1230 [ V_3 - 1 ] = NULL ;
}
return - V_356 ;
}
void F_608 ( struct V_82 * V_82 )
{
F_609 ( V_82 ) ;
}
int F_610 ( struct V_82 * V_82 ,
struct V_701 * V_702 ,
struct V_1218 * V_1219 ,
enum V_1237 V_1238 )
{
if ( ( V_702 -> V_1185 >= V_523 ) && ( V_1238 == V_1239 ) ) {
unsigned long V_1236 ;
V_1236 = F_611 ( NULL , 0 , V_702 -> V_1231 * V_88 ,
V_1240 | V_1241 ,
V_1242 | V_1243 , 0 ) ;
if ( F_169 ( ( void * ) V_1236 ) )
return F_170 ( ( void * ) V_1236 ) ;
V_702 -> V_1236 = V_1236 ;
}
return 0 ;
}
void F_612 ( struct V_82 * V_82 ,
struct V_1218 * V_1219 ,
const struct V_701 * V_808 ,
enum V_1237 V_1238 )
{
int V_1244 = 0 ;
if ( ( V_1219 -> V_10 >= V_523 ) && ( V_1238 == V_1245 ) ) {
int V_89 ;
V_89 = F_613 ( V_808 -> V_1236 ,
V_808 -> V_1231 * V_88 ) ;
if ( V_89 < 0 )
F_10 ( V_815
L_32
L_33 ) ;
}
if ( ! V_82 -> V_5 . V_674 )
V_1244 = F_614 ( V_82 ) ;
if ( V_1244 )
F_266 ( V_82 , V_1244 ) ;
if ( ( V_1238 != V_1245 ) && ( V_1219 -> V_258 & V_1246 ) )
F_615 ( V_82 , V_1219 -> V_10 ) ;
}
void F_616 ( struct V_82 * V_82 )
{
F_617 ( V_82 ) ;
}
void F_618 ( struct V_82 * V_82 ,
struct V_701 * V_10 )
{
F_617 ( V_82 ) ;
}
int F_619 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_988 == V_1077 &&
! V_2 -> V_5 . V_6 . V_1056 )
|| ! F_620 ( & V_2 -> V_1247 . V_1248 )
|| F_621 ( V_2 )
|| V_2 -> V_5 . V_1079 . V_1080
|| F_122 ( & V_2 -> V_5 . V_68 ) ||
( F_478 ( V_2 ) &&
F_477 ( V_2 ) ) ;
}
int F_622 ( struct V_1 * V_2 )
{
return F_623 ( V_2 ) == V_1066 ;
}
int F_478 ( struct V_1 * V_2 )
{
return V_56 -> V_1038 ( V_2 ) ;
}
bool F_624 ( struct V_1 * V_2 , unsigned long V_1249 )
{
unsigned long V_1250 = F_400 ( V_2 ) +
F_354 ( V_2 , V_919 ) ;
return V_1250 == V_1249 ;
}
unsigned long F_399 ( struct V_1 * V_2 )
{
unsigned long V_908 ;
V_908 = V_56 -> V_909 ( V_2 ) ;
if ( V_2 -> V_149 & V_911 )
V_908 &= ~ V_910 ;
return V_908 ;
}
void F_370 ( struct V_1 * V_2 , unsigned long V_908 )
{
if ( V_2 -> V_149 & V_911 &&
F_624 ( V_2 , V_2 -> V_5 . V_915 ) )
V_908 |= V_910 ;
V_56 -> V_1251 ( V_2 , V_908 ) ;
F_25 ( V_48 , V_2 ) ;
}
void F_625 ( struct V_1 * V_2 , struct V_1252 * V_971 )
{
int V_100 ;
if ( ( V_2 -> V_5 . V_67 . V_900 != V_971 -> V_5 . V_900 ) ||
F_341 ( V_971 -> V_354 ) )
return;
V_100 = F_503 ( V_2 ) ;
if ( F_139 ( V_100 ) )
return;
if ( ! V_2 -> V_5 . V_67 . V_900 &&
V_971 -> V_5 . V_85 != V_2 -> V_5 . V_67 . V_1253 ( V_2 ) )
return;
V_2 -> V_5 . V_67 . V_1254 ( V_2 , V_971 -> V_768 , 0 , true ) ;
}
static inline T_1 F_626 ( T_4 V_83 )
{
return F_627 ( V_83 & 0xffffffff , F_628 ( V_4 ) ) ;
}
static inline T_1 F_629 ( T_1 V_1255 )
{
return ( V_1255 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_630 ( struct V_1 * V_2 , T_4 V_83 )
{
T_1 V_1255 = F_626 ( V_83 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1255 ] != ~ 0 )
V_1255 = F_629 ( V_1255 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1255 ] = V_83 ;
}
static T_1 F_631 ( struct V_1 * V_2 , T_4 V_83 )
{
int V_3 ;
T_1 V_1255 = F_626 ( V_83 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1255 ] != V_83 &&
V_2 -> V_5 . V_6 . V_7 [ V_1255 ] != ~ 0 ) ; V_3 ++ )
V_1255 = F_629 ( V_1255 ) ;
return V_1255 ;
}
bool F_632 ( struct V_1 * V_2 , T_4 V_83 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_631 ( V_2 , V_83 ) ] == V_83 ;
}
static void F_633 ( struct V_1 * V_2 , T_4 V_83 )
{
T_1 V_3 , V_755 , V_1256 ;
V_3 = V_755 = F_631 ( V_2 , V_83 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_755 = F_629 ( V_755 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_755 ] == ~ 0 )
return;
V_1256 = F_626 ( V_2 -> V_5 . V_6 . V_7 [ V_755 ] ) ;
} while ( ( V_3 <= V_755 ) ? ( V_3 < V_1256 && V_1256 <= V_755 ) : ( V_3 < V_1256 || V_1256 <= V_755 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_755 ] ;
V_3 = V_755 ;
}
}
static int F_634 ( struct V_1 * V_2 , T_1 V_156 )
{
return F_158 ( V_2 -> V_82 , & V_2 -> V_5 . V_6 . V_31 , & V_156 ,
sizeof( V_156 ) ) ;
}
void F_635 ( struct V_1 * V_2 ,
struct V_1252 * V_971 )
{
struct V_58 V_59 ;
F_636 ( V_971 -> V_5 . V_1257 , V_971 -> V_768 ) ;
F_630 ( V_2 , V_971 -> V_5 . V_83 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_379 & V_380 ) ||
( V_2 -> V_5 . V_6 . V_381 &&
V_56 -> V_71 ( V_2 ) == 0 ) )
F_25 ( V_1055 , V_2 ) ;
else if ( ! F_634 ( V_2 , V_1258 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_865 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_971 -> V_5 . V_1257 ;
F_30 ( V_2 , & V_59 ) ;
}
}
void F_637 ( struct V_1 * V_2 ,
struct V_1252 * V_971 )
{
struct V_58 V_59 ;
F_638 ( V_971 -> V_5 . V_1257 , V_971 -> V_768 ) ;
if ( F_341 ( V_971 -> V_354 ) )
V_971 -> V_5 . V_1257 = ~ 0 ;
else
F_633 ( V_2 , V_971 -> V_5 . V_83 ) ;
if ( ( V_2 -> V_5 . V_6 . V_379 & V_380 ) &&
! F_634 ( V_2 , V_1259 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_865 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_971 -> V_5 . V_1257 ;
F_30 ( V_2 , & V_59 ) ;
}
V_2 -> V_5 . V_6 . V_1056 = false ;
V_2 -> V_5 . V_988 = V_1077 ;
}
bool F_639 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_379 & V_380 ) )
return true ;
else
return ! F_480 ( V_2 ) &&
V_56 -> V_1038 ( V_2 ) ;
}
