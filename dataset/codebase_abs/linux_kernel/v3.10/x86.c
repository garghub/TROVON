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
if ( F_76 ( ! F_77 ( V_2 -> V_82 , V_85 >> V_87 ) ) )
return 1 ;
V_2 -> V_5 . V_85 = V_85 ;
F_46 ( V_143 , ( V_144 * ) & V_2 -> V_5 . V_97 ) ;
V_2 -> V_5 . V_67 . V_145 ( V_2 ) ;
return 0 ;
}
int F_78 ( struct V_1 * V_2 , unsigned long V_146 )
{
if ( V_146 & V_147 )
return 1 ;
if ( F_79 ( V_2 -> V_82 ) )
F_80 ( V_2 , V_146 ) ;
else
V_2 -> V_5 . V_146 = V_146 ;
return 0 ;
}
unsigned long F_81 ( struct V_1 * V_2 )
{
if ( F_79 ( V_2 -> V_82 ) )
return F_82 ( V_2 ) ;
else
return V_2 -> V_5 . V_146 ;
}
static void F_83 ( struct V_1 * V_2 )
{
unsigned long V_148 ;
if ( V_2 -> V_149 & V_150 )
V_148 = V_2 -> V_5 . V_151 ;
else
V_148 = V_2 -> V_5 . V_148 ;
V_56 -> V_152 ( V_2 , V_148 ) ;
V_2 -> V_5 . V_153 = ( V_148 & V_154 ) ;
}
static int F_84 ( struct V_1 * V_2 , int V_155 , unsigned long V_156 )
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
F_83 ( V_2 ) ;
break;
}
return 0 ;
}
int F_85 ( struct V_1 * V_2 , int V_155 , unsigned long V_156 )
{
int V_165 ;
V_165 = F_84 ( V_2 , V_155 , V_156 ) ;
if ( V_165 > 0 )
F_26 ( V_2 , V_166 ) ;
else if ( V_165 < 0 )
F_29 ( V_2 , 0 ) ;
return V_165 ;
}
static int F_86 ( struct V_1 * V_2 , int V_155 , unsigned long * V_156 )
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
int F_87 ( struct V_1 * V_2 , int V_155 , unsigned long * V_156 )
{
if ( F_86 ( V_2 , V_155 , V_156 ) ) {
F_26 ( V_2 , V_166 ) ;
return 1 ;
}
return 0 ;
}
bool F_88 ( struct V_1 * V_2 )
{
T_1 V_167 = F_89 ( V_2 , V_168 ) ;
T_2 V_31 ;
int V_55 ;
V_55 = F_90 ( V_2 , V_167 , & V_31 ) ;
if ( V_55 )
return V_55 ;
F_91 ( V_2 , V_169 , ( T_1 ) V_31 ) ;
F_91 ( V_2 , V_170 , V_31 >> 32 ) ;
return V_55 ;
}
bool F_92 ( struct V_1 * V_2 , T_2 V_111 )
{
if ( V_111 & V_171 )
return false ;
if ( V_111 & V_172 ) {
struct V_173 * V_174 ;
V_174 = F_93 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_174 || ! ( V_174 -> V_175 & F_94 ( V_176 ) ) )
return false ;
}
if ( V_111 & V_177 ) {
struct V_173 * V_174 ;
V_174 = F_93 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_174 || ! ( V_174 -> V_167 & F_94 ( V_178 ) ) )
return false ;
}
return true ;
}
static int F_95 ( struct V_1 * V_2 , T_2 V_111 )
{
T_2 V_179 = V_2 -> V_5 . V_111 ;
if ( ! F_92 ( V_2 , V_111 ) )
return 1 ;
if ( F_55 ( V_2 )
&& ( V_2 -> V_5 . V_111 & V_112 ) != ( V_111 & V_112 ) )
return 1 ;
V_111 &= ~ V_180 ;
V_111 |= V_2 -> V_5 . V_111 & V_180 ;
V_56 -> F_95 ( V_2 , V_111 ) ;
if ( ( V_111 ^ V_179 ) & V_181 )
F_58 ( V_2 ) ;
return 0 ;
}
void F_96 ( T_2 V_27 )
{
V_171 &= ~ V_27 ;
}
int F_97 ( struct V_1 * V_2 , struct V_182 * V_21 )
{
return V_56 -> V_183 ( V_2 , V_21 ) ;
}
static int F_98 ( struct V_1 * V_2 , unsigned V_124 , T_2 * V_31 )
{
struct V_182 V_21 ;
V_21 . V_31 = * V_31 ;
V_21 . V_124 = V_124 ;
V_21 . V_184 = true ;
return F_97 ( V_2 , & V_21 ) ;
}
static void F_99 ( struct V_185 * V_186 )
{
struct V_187 * V_188 = & V_187 ;
F_100 ( & V_188 -> V_189 ) ;
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
F_101 ( & V_188 -> V_189 ) ;
}
static void F_102 ( struct V_82 * V_82 , T_5 V_203 )
{
int V_204 ;
int V_100 ;
struct V_205 V_206 ;
struct V_207 V_208 ;
if ( ! V_203 )
return;
V_100 = F_103 ( V_82 , V_203 , & V_204 , sizeof( V_204 ) ) ;
if ( V_100 )
return;
if ( V_204 & 1 )
++ V_204 ;
++ V_204 ;
F_104 ( V_82 , V_203 , & V_204 , sizeof( V_204 ) ) ;
F_105 ( & V_208 ) ;
if ( V_82 -> V_5 . V_209 ) {
struct V_207 V_210 = F_106 ( V_82 -> V_5 . V_209 ) ;
V_208 = F_107 ( V_208 , V_210 ) ;
}
V_206 . V_211 = V_208 . V_198 ;
V_206 . V_212 = V_208 . V_201 ;
V_206 . V_204 = V_204 ;
F_104 ( V_82 , V_203 , & V_206 , sizeof( V_206 ) ) ;
V_204 ++ ;
F_104 ( V_82 , V_203 , & V_204 , sizeof( V_204 ) ) ;
}
static T_6 F_108 ( T_6 V_213 , T_6 V_214 )
{
T_6 V_215 , V_216 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_215 ;
}
static void F_109 ( T_6 V_217 , T_6 V_218 ,
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
* V_220 = F_108 ( V_221 , V_223 ) ;
F_110 ( L_2 ,
V_224 , V_218 , V_217 , V_194 , * V_220 ) ;
}
static inline T_2 F_111 ( void )
{
struct V_207 V_210 ;
F_112 ( F_113 () ) ;
F_114 ( & V_210 ) ;
F_115 ( & V_210 ) ;
return F_116 ( & V_210 ) ;
}
static inline T_2 F_117 ( struct V_1 * V_2 , T_2 V_212 )
{
return F_118 ( V_212 , V_2 -> V_5 . V_225 ,
V_2 -> V_5 . V_226 ) ;
}
static T_1 F_119 ( T_1 V_227 , T_10 V_228 )
{
T_2 V_229 = ( T_2 ) V_227 * ( 1000000 + V_228 ) ;
F_120 ( V_229 , 1000000 ) ;
return V_229 ;
}
static void F_121 ( struct V_1 * V_2 , T_1 V_230 )
{
T_1 V_231 , V_232 ;
int V_233 = 0 ;
if ( V_230 == 0 )
return;
F_109 ( V_230 , V_202 / 1000 ,
& V_2 -> V_5 . V_226 ,
& V_2 -> V_5 . V_225 ) ;
V_2 -> V_5 . V_234 = V_230 ;
V_231 = F_119 ( V_235 , - V_236 ) ;
V_232 = F_119 ( V_235 , V_236 ) ;
if ( V_230 < V_231 || V_230 > V_232 ) {
F_110 ( L_3 , V_230 , V_231 , V_232 ) ;
V_233 = 1 ;
}
V_56 -> V_237 ( V_2 , V_230 , V_233 ) ;
}
static T_2 F_122 ( struct V_1 * V_2 , T_11 V_238 )
{
T_2 V_239 = F_118 ( V_238 - V_2 -> V_5 . V_240 ,
V_2 -> V_5 . V_225 ,
V_2 -> V_5 . V_226 ) ;
V_239 += V_2 -> V_5 . V_241 ;
return V_239 ;
}
void F_123 ( struct V_1 * V_2 )
{
#ifdef F_54
bool V_242 ;
bool V_243 = false ;
struct V_244 * V_245 = & V_2 -> V_82 -> V_5 ;
struct V_187 * V_246 = & V_187 ;
V_242 = ( V_245 -> V_247 + 1 ==
F_124 ( & V_2 -> V_82 -> V_248 ) ) ;
if ( V_242 && V_246 -> clock . V_190 == V_249 )
if ( ! V_245 -> V_250 )
V_243 = 1 ;
if ( ! V_242 && V_245 -> V_250 )
V_243 = 1 ;
if ( V_243 )
F_25 ( V_251 , V_2 ) ;
F_125 ( V_2 -> V_252 , V_245 -> V_247 ,
F_124 ( & V_2 -> V_82 -> V_248 ) ,
V_245 -> V_250 , V_246 -> clock . V_190 ) ;
#endif
}
static void F_126 ( struct V_1 * V_2 , T_11 V_74 )
{
T_2 V_253 = V_56 -> V_254 ( V_2 ) ;
V_2 -> V_5 . V_255 += V_74 - V_253 ;
}
void F_127 ( struct V_1 * V_2 , struct V_182 * V_21 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
T_2 V_74 , V_256 , V_257 ;
unsigned long V_258 ;
T_11 V_259 ;
bool V_260 ;
T_2 V_31 = V_21 -> V_31 ;
F_128 ( & V_82 -> V_5 . V_261 , V_258 ) ;
V_74 = V_56 -> V_262 ( V_2 , V_31 ) ;
V_256 = F_111 () ;
V_257 = V_256 - V_82 -> V_5 . V_263 ;
if ( V_2 -> V_5 . V_234 ) {
V_259 = V_31 - V_82 -> V_5 . V_264 ;
#ifdef F_54
V_259 = ( V_259 * 1000 ) / V_2 -> V_5 . V_234 ;
#else
asm("idivl %2; xor %%edx, %%edx"
: "=A"(usdiff)
: "A"(usdiff * 1000), "rm"(vcpu->arch.virtual_tsc_khz));
#endif
F_120 ( V_257 , 1000 ) ;
V_259 -= V_257 ;
if ( V_259 < 0 )
V_259 = - V_259 ;
} else
V_259 = V_265 ;
if ( V_259 < V_265 &&
V_2 -> V_5 . V_234 == V_82 -> V_5 . V_266 ) {
if ( ! F_129 () ) {
V_74 = V_82 -> V_5 . V_267 ;
F_110 ( L_4 , V_31 ) ;
} else {
T_2 V_268 = F_117 ( V_2 , V_257 ) ;
V_31 += V_268 ;
V_74 = V_56 -> V_262 ( V_2 , V_31 ) ;
F_110 ( L_5 , V_268 ) ;
}
V_260 = true ;
} else {
V_82 -> V_5 . V_269 ++ ;
V_82 -> V_5 . V_270 = V_256 ;
V_82 -> V_5 . V_271 = V_31 ;
V_82 -> V_5 . V_267 = V_74 ;
V_260 = false ;
F_110 ( L_6 ,
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
if ( F_130 ( V_2 ) && ! V_21 -> V_184 )
F_126 ( V_2 , V_74 ) ;
V_56 -> V_276 ( V_2 , V_74 ) ;
F_131 ( & V_82 -> V_5 . V_261 , V_258 ) ;
F_132 ( & V_82 -> V_5 . V_277 ) ;
if ( V_260 )
V_82 -> V_5 . V_247 ++ ;
else
V_82 -> V_5 . V_247 = 0 ;
F_123 ( V_2 ) ;
F_133 ( & V_82 -> V_5 . V_277 ) ;
}
static T_12 F_134 ( void )
{
T_12 V_89 ;
T_2 V_278 ;
F_135 () ;
V_89 = ( T_12 ) F_136 () ;
V_278 = V_187 . clock . V_192 ;
if ( F_137 ( V_89 >= V_278 ) )
return V_89 ;
asm volatile ("");
return V_278 ;
}
static inline T_2 F_138 ( T_12 * V_279 )
{
long V_229 ;
struct V_187 * V_246 = & V_187 ;
* V_279 = F_134 () ;
V_229 = ( * V_279 - V_246 -> clock . V_192 ) & V_246 -> clock . V_27 ;
return V_229 * V_246 -> clock . V_193 ;
}
static int F_139 ( struct V_207 * V_210 , T_12 * V_279 )
{
unsigned long V_189 ;
T_2 V_256 ;
int V_280 ;
struct V_187 * V_246 = & V_187 ;
V_210 -> V_201 = 0 ;
do {
V_189 = F_140 ( & V_246 -> V_189 ) ;
V_280 = V_246 -> clock . V_190 ;
V_210 -> V_198 = V_246 -> V_195 ;
V_256 = V_246 -> V_199 ;
V_256 += F_138 ( V_279 ) ;
V_256 >>= V_246 -> clock . V_194 ;
} while ( F_76 ( F_141 ( & V_246 -> V_189 , V_189 ) ) );
F_142 ( V_210 , V_256 ) ;
return V_280 ;
}
static bool F_143 ( T_11 * V_238 , T_12 * V_279 )
{
struct V_207 V_210 ;
if ( V_187 . clock . V_190 != V_249 )
return false ;
if ( F_139 ( & V_210 , V_279 ) != V_249 )
return false ;
F_115 ( & V_210 ) ;
* V_238 = F_116 ( & V_210 ) ;
return true ;
}
static void F_144 ( struct V_82 * V_82 )
{
#ifdef F_54
struct V_244 * V_245 = & V_82 -> V_5 ;
int V_190 ;
bool V_281 , V_242 ;
V_242 = ( V_245 -> V_247 + 1 ==
F_124 ( & V_82 -> V_248 ) ) ;
V_281 = F_143 (
& V_245 -> V_282 ,
& V_245 -> V_283 ) ;
V_245 -> V_250 = V_281 & V_242 ;
if ( V_245 -> V_250 )
F_145 ( & V_284 , 1 ) ;
V_190 = V_187 . clock . V_190 ;
F_146 ( V_245 -> V_250 , V_190 ,
V_242 ) ;
#endif
}
static int F_147 ( struct V_1 * V_229 )
{
unsigned long V_258 , V_230 ;
struct V_285 * V_2 = & V_229 -> V_5 ;
struct V_244 * V_245 = & V_229 -> V_82 -> V_5 ;
T_11 V_238 , V_286 ;
T_2 V_273 , V_287 ;
struct V_288 V_289 ;
T_13 V_290 ;
bool V_250 ;
V_238 = 0 ;
V_287 = 0 ;
F_132 ( & V_245 -> V_277 ) ;
V_250 = V_245 -> V_250 ;
if ( V_250 ) {
V_287 = V_245 -> V_283 ;
V_238 = V_245 -> V_282 ;
}
F_133 ( & V_245 -> V_277 ) ;
F_148 ( V_258 ) ;
V_230 = F_149 ( V_291 ) ;
if ( F_76 ( V_230 == 0 ) ) {
F_150 ( V_258 ) ;
F_25 ( V_292 , V_229 ) ;
return 1 ;
}
if ( ! V_250 ) {
V_287 = F_151 () ;
V_238 = F_111 () ;
}
V_273 = V_56 -> V_293 ( V_229 , V_287 ) ;
if ( V_2 -> V_294 ) {
T_2 V_239 = F_122 ( V_229 , V_238 ) ;
if ( V_239 > V_273 ) {
F_152 ( V_229 , V_239 - V_273 ) ;
V_273 = V_239 ;
}
}
F_150 ( V_258 ) ;
if ( ! V_2 -> V_295 )
return 0 ;
V_286 = 0 ;
if ( V_2 -> V_272 . V_273 ) {
V_286 = V_2 -> V_274 -
V_2 -> V_272 . V_273 ;
V_286 = F_118 ( V_286 ,
V_2 -> V_272 . V_296 ,
V_2 -> V_272 . V_297 ) ;
V_286 += V_2 -> V_298 ;
}
if ( F_76 ( V_2 -> V_299 != V_230 ) ) {
F_109 ( V_202 / 1000 , V_230 ,
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
if ( F_76 ( F_153 ( V_229 -> V_82 , & V_2 -> V_301 ,
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
F_154 ( V_229 -> V_82 , & V_2 -> V_301 ,
& V_2 -> V_272 ,
sizeof( V_2 -> V_272 ) ) ;
return 0 ;
}
static bool F_155 ( unsigned V_21 )
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
static bool F_156 ( unsigned V_319 )
{
return V_319 < 8 && ( 1 << V_319 ) & 0xf3 ;
}
static bool F_157 ( unsigned V_319 )
{
return V_319 < 8 && ( 1 << V_319 ) & 0x73 ;
}
static bool F_158 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
int V_3 ;
if ( ! F_155 ( V_21 ) )
return false ;
if ( V_21 == V_318 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_156 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_317 ) {
if ( V_31 & ~ 0xcff )
return false ;
return F_157 ( V_31 & 0xff ) ;
} else if ( V_21 >= V_306 && V_21 <= V_316 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_157 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_157 ( V_31 & 0xff ) ;
}
static int F_159 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 * V_320 = ( T_2 * ) & V_2 -> V_5 . V_321 . V_322 ;
if ( ! F_158 ( V_2 , V_21 , V_31 ) )
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
F_58 ( V_2 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
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
static int F_161 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
int V_341 = F_48 ( V_2 ) ;
T_13 * V_342 = V_341 ? ( T_13 * ) ( long ) V_82 -> V_5 . F_161 . V_343
: ( T_13 * ) ( long ) V_82 -> V_5 . F_161 . V_344 ;
T_13 V_345 = V_341 ? V_82 -> V_5 . F_161 . V_346
: V_82 -> V_5 . F_161 . V_347 ;
T_1 V_348 = V_31 & ~ V_349 ;
T_2 V_350 = V_31 & V_349 ;
T_13 * V_351 ;
int V_100 ;
V_100 = - V_352 ;
if ( V_348 >= V_345 )
goto V_94;
V_100 = - V_353 ;
V_351 = F_162 ( V_342 + ( V_348 * V_88 ) , V_88 ) ;
if ( F_163 ( V_351 ) ) {
V_100 = F_164 ( V_351 ) ;
goto V_94;
}
if ( F_104 ( V_82 , V_350 , V_351 , V_88 ) )
goto V_354;
V_100 = 0 ;
V_354:
F_165 ( V_351 ) ;
V_94:
return V_100 ;
}
static bool F_166 ( struct V_82 * V_82 )
{
return V_82 -> V_5 . V_355 & V_356 ;
}
static bool F_167 ( T_1 V_21 )
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
static int F_168 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
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
T_13 V_361 [ 4 ] ;
if ( ! V_82 -> V_5 . V_359 )
break;
if ( ! ( V_31 & V_356 ) ) {
V_82 -> V_5 . V_355 = V_31 ;
break;
}
V_83 = V_31 >> V_362 ;
V_360 = F_169 ( V_82 , V_83 ) ;
if ( F_170 ( V_360 ) )
return 1 ;
V_56 -> V_363 ( V_2 , V_361 ) ;
( ( unsigned char * ) V_361 ) [ 3 ] = 0xc3 ;
if ( F_171 ( ( void V_364 * ) V_360 , V_361 , 4 ) )
return 1 ;
V_82 -> V_5 . V_355 = V_31 ;
break;
}
default:
F_172 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_173 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_365 : {
unsigned long V_360 ;
if ( ! ( V_31 & V_366 ) ) {
V_2 -> V_5 . V_367 = V_31 ;
break;
}
V_360 = F_169 ( V_2 -> V_82 , V_31 >>
V_368 ) ;
if ( F_170 ( V_360 ) )
return 1 ;
if ( F_174 ( ( void V_364 * ) V_360 , V_88 ) )
return 1 ;
V_2 -> V_5 . V_367 = V_31 ;
break;
}
case V_369 :
return F_175 ( V_2 , V_370 , V_31 ) ;
case V_371 :
return F_175 ( V_2 , V_372 , V_31 ) ;
case V_373 :
return F_175 ( V_2 , V_374 , V_31 ) ;
default:
F_172 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_176 ( struct V_1 * V_2 , T_2 V_31 )
{
T_5 V_375 = V_31 & ~ 0x3f ;
if ( V_31 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_376 = V_31 ;
if ( ! ( V_31 & V_377 ) ) {
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_177 ( V_2 -> V_82 , & V_2 -> V_5 . V_6 . V_31 , V_375 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_378 = ! ( V_31 & V_379 ) ;
F_178 ( V_2 ) ;
return 0 ;
}
static void F_179 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_295 = false ;
}
static void F_180 ( struct V_1 * V_2 )
{
T_2 V_268 ;
if ( ! ( V_2 -> V_5 . V_380 . V_376 & V_381 ) )
return;
V_268 = V_382 -> V_383 . V_384 - V_2 -> V_5 . V_380 . V_385 ;
V_2 -> V_5 . V_380 . V_385 = V_382 -> V_383 . V_384 ;
V_2 -> V_5 . V_380 . V_386 = V_268 ;
}
static void F_181 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_380 . V_376 & V_381 ) )
return;
if ( F_76 ( F_153 ( V_2 -> V_82 , & V_2 -> V_5 . V_380 . V_387 ,
& V_2 -> V_5 . V_380 . V_388 , sizeof( struct V_389 ) ) ) )
return;
V_2 -> V_5 . V_380 . V_388 . V_388 += V_2 -> V_5 . V_380 . V_386 ;
V_2 -> V_5 . V_380 . V_388 . V_204 += 2 ;
V_2 -> V_5 . V_380 . V_386 = 0 ;
F_154 ( V_2 -> V_82 , & V_2 -> V_5 . V_380 . V_387 ,
& V_2 -> V_5 . V_380 . V_388 , sizeof( struct V_389 ) ) ;
}
int F_182 ( struct V_1 * V_2 , struct V_182 * V_390 )
{
bool V_391 = false ;
T_1 V_21 = V_390 -> V_124 ;
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
return F_95 ( V_2 , V_31 ) ;
case V_399 :
V_31 &= ~ ( T_2 ) 0x40 ;
V_31 &= ~ ( T_2 ) 0x100 ;
V_31 &= ~ ( T_2 ) 0x8 ;
if ( V_31 != 0 ) {
F_172 ( V_2 , L_9 ,
V_31 ) ;
return 1 ;
}
break;
case V_400 :
if ( V_31 != 0 ) {
F_172 ( V_2 , L_10
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
F_172 ( V_2 , L_12 ,
V_224 , V_31 ) ;
break;
case 0x200 ... 0x2ff :
return F_159 ( V_2 , V_21 , V_31 ) ;
case V_404 :
F_19 ( V_2 , V_31 ) ;
break;
case V_405 ... V_405 + 0x3ff :
return F_183 ( V_2 , V_21 , V_31 ) ;
case V_406 :
F_184 ( V_2 , V_31 ) ;
break;
case V_407 :
if ( F_130 ( V_2 ) ) {
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
F_102 ( V_2 -> V_82 , V_31 ) ;
break;
case V_414 :
case V_415 : {
T_2 V_416 ;
F_179 ( V_2 ) ;
V_2 -> V_5 . time = V_31 ;
F_25 ( V_292 , V_2 ) ;
if ( ! ( V_31 & 1 ) )
break;
V_416 = V_31 & ~ ( V_349 | 1 ) ;
if ( F_177 ( V_2 -> V_82 ,
& V_2 -> V_5 . V_301 , V_31 & ~ 1ULL ,
sizeof( struct V_288 ) ) )
V_2 -> V_5 . V_295 = false ;
else
V_2 -> V_5 . V_295 = true ;
break;
}
case V_417 :
if ( F_176 ( V_2 , V_31 ) )
return 1 ;
break;
case V_418 :
if ( F_76 ( ! F_185 () ) )
return 1 ;
if ( V_31 & V_419 )
return 1 ;
if ( F_177 ( V_2 -> V_82 , & V_2 -> V_5 . V_380 . V_387 ,
V_31 & V_420 ,
sizeof( struct V_389 ) ) )
return 1 ;
V_2 -> V_5 . V_380 . V_376 = V_31 ;
if ( ! ( V_31 & V_381 ) )
break;
V_2 -> V_5 . V_380 . V_385 = V_382 -> V_383 . V_384 ;
F_186 () ;
F_180 ( V_2 ) ;
F_187 () ;
F_25 ( V_421 , V_2 ) ;
break;
case V_422 :
if ( F_188 ( V_2 , V_31 ) )
return 1 ;
break;
case V_336 :
case V_334 :
case V_339 ... V_339 + 4 * V_423 - 1 :
return F_160 ( V_2 , V_21 , V_31 ) ;
case V_424 :
case V_425 :
case V_426 :
case V_427 :
if ( V_31 != 0 )
F_172 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_428 :
case V_429 :
case V_430 :
case V_431 :
F_172 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_432 :
case V_433 :
V_391 = true ;
case V_434 :
case V_435 :
if ( F_189 ( V_2 , V_21 ) )
return F_190 ( V_2 , V_390 ) ;
if ( V_391 || V_31 != 0 )
F_172 ( V_2 , L_15
L_14 , V_21 , V_31 ) ;
break;
case V_436 :
break;
case V_357 ... V_437 :
if ( F_167 ( V_21 ) ) {
int V_100 ;
F_191 ( & V_2 -> V_82 -> V_438 ) ;
V_100 = F_168 ( V_2 , V_21 , V_31 ) ;
F_192 ( & V_2 -> V_82 -> V_438 ) ;
return V_100 ;
} else
return F_173 ( V_2 , V_21 , V_31 ) ;
break;
case V_439 :
F_172 ( V_2 , L_16 , V_21 , V_31 ) ;
break;
case V_440 :
if ( ! F_193 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_441 . V_442 = V_31 ;
break;
case V_443 :
if ( ! F_193 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_441 . V_444 = V_31 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_82 -> V_5 . F_161 . V_21 ) )
return F_161 ( V_2 , V_31 ) ;
if ( F_189 ( V_2 , V_21 ) )
return F_190 ( V_2 , V_390 ) ;
if ( ! V_445 ) {
F_172 ( V_2 , L_17 ,
V_21 , V_31 ) ;
return 1 ;
} else {
F_172 ( V_2 , L_16 ,
V_21 , V_31 ) ;
break;
}
}
return 0 ;
}
int F_194 ( struct V_1 * V_2 , T_1 V_446 , T_2 * V_447 )
{
return V_56 -> V_448 ( V_2 , V_446 , V_447 ) ;
}
static int F_195 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_447 )
{
T_2 * V_320 = ( T_2 * ) & V_2 -> V_5 . V_321 . V_322 ;
if ( ! F_155 ( V_21 ) )
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
static int F_196 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_447 )
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
static int F_197 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_447 )
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
F_172 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_447 = V_31 ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_447 )
{
T_2 V_31 = 0 ;
switch ( V_21 ) {
case V_452 : {
int V_100 ;
struct V_1 * V_229 ;
F_199 (r, v, vcpu->kvm)
if ( V_229 == V_2 )
V_31 = V_100 ;
break;
}
case V_369 :
return F_200 ( V_2 , V_370 , V_447 ) ;
case V_371 :
return F_200 ( V_2 , V_372 , V_447 ) ;
case V_373 :
return F_200 ( V_2 , V_374 , V_447 ) ;
case V_365 :
V_31 = V_2 -> V_5 . V_367 ;
break;
default:
F_172 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_447 = V_31 ;
return 0 ;
}
int F_201 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_447 )
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
if ( F_189 ( V_2 , V_21 ) )
return F_202 ( V_2 , V_21 , V_447 ) ;
V_31 = 0 ;
break;
case V_393 :
V_31 = 0x100000000ULL ;
break;
case V_461 :
V_31 = 0x500 | V_305 ;
break;
case 0x200 ... 0x2ff :
return F_195 ( V_2 , V_21 , V_447 ) ;
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
return F_203 ( V_2 , V_21 , V_447 ) ;
break;
case V_406 :
V_31 = F_204 ( V_2 ) ;
break;
case V_407 :
V_31 = ( T_2 ) V_2 -> V_5 . V_255 ;
break;
case V_410 :
V_31 = V_2 -> V_5 . V_411 ;
break;
case V_463 :
V_31 = 1000ULL ;
V_31 |= ( ( ( T_8 ) 4ULL ) << 40 ) ;
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
return F_196 ( V_2 , V_21 , V_447 ) ;
case V_436 :
V_31 = 0x20000000 ;
break;
case V_357 ... V_437 :
if ( F_167 ( V_21 ) ) {
int V_100 ;
F_191 ( & V_2 -> V_82 -> V_438 ) ;
V_100 = F_197 ( V_2 , V_21 , V_447 ) ;
F_192 ( & V_2 -> V_82 -> V_438 ) ;
return V_100 ;
} else
return F_198 ( V_2 , V_21 , V_447 ) ;
break;
case V_439 :
V_31 = 0xbe702111 ;
break;
case V_440 :
if ( ! F_193 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_441 . V_442 ;
break;
case V_443 :
if ( ! F_193 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_441 . V_444 ;
break;
default:
if ( F_189 ( V_2 , V_21 ) )
return F_202 ( V_2 , V_21 , V_447 ) ;
if ( ! V_445 ) {
F_172 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_172 ( V_2 , L_20 , V_21 ) ;
V_31 = 0 ;
}
break;
}
* V_447 = V_31 ;
return 0 ;
}
static int F_205 ( struct V_1 * V_2 , struct V_465 * V_19 ,
struct V_466 * V_467 ,
int (* F_206)( struct V_1 * V_2 ,
unsigned V_124 , T_2 * V_31 ) )
{
int V_3 , V_326 ;
V_326 = F_207 ( & V_2 -> V_82 -> V_468 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_469 ; ++ V_3 )
if ( F_206 ( V_2 , V_467 [ V_3 ] . V_124 , & V_467 [ V_3 ] . V_31 ) )
break;
F_208 ( & V_2 -> V_82 -> V_468 , V_326 ) ;
return V_3 ;
}
static int F_209 ( struct V_1 * V_2 , struct V_465 V_364 * V_470 ,
int (* F_206)( struct V_1 * V_2 ,
unsigned V_124 , T_2 * V_31 ) ,
int V_471 )
{
struct V_465 V_19 ;
struct V_466 * V_467 ;
int V_100 , V_472 ;
unsigned V_473 ;
V_100 = - V_81 ;
if ( F_210 ( & V_19 , V_470 , sizeof V_19 ) )
goto V_94;
V_100 = - V_352 ;
if ( V_19 . V_469 >= V_474 )
goto V_94;
V_473 = sizeof( struct V_466 ) * V_19 . V_469 ;
V_467 = F_162 ( V_470 -> V_467 , V_473 ) ;
if ( F_163 ( V_467 ) ) {
V_100 = F_164 ( V_467 ) ;
goto V_94;
}
V_100 = V_472 = F_205 ( V_2 , & V_19 , V_467 , F_206 ) ;
if ( V_100 < 0 )
goto V_354;
V_100 = - V_81 ;
if ( V_471 && F_211 ( V_470 -> V_467 , V_467 , V_473 ) )
goto V_354;
V_100 = V_472 ;
V_354:
F_165 ( V_467 ) ;
V_94:
return V_100 ;
}
int F_212 ( long V_475 )
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
#ifdef F_213
case V_508 :
case V_509 :
#endif
V_100 = 1 ;
break;
case V_510 :
V_100 = V_511 ;
break;
case V_512 :
V_100 = ! V_56 -> V_513 () ;
break;
case V_514 :
V_100 = V_515 ;
break;
case V_516 :
V_100 = V_517 ;
break;
case V_518 :
V_100 = V_519 ;
break;
case V_520 :
V_100 = 0 ;
break;
#ifdef F_213
case V_521 :
V_100 = F_214 ( & V_522 ) ;
break;
#endif
case V_523 :
V_100 = V_423 ;
break;
case V_524 :
V_100 = V_525 ;
break;
case V_526 :
V_100 = V_527 ;
break;
case V_528 :
V_100 = F_215 ( V_529 ) ;
break;
default:
V_100 = 0 ;
break;
}
return V_100 ;
}
long F_216 ( struct V_530 * V_531 ,
unsigned int V_532 , unsigned long V_533 )
{
void V_364 * V_534 = ( void V_364 * ) V_533 ;
long V_100 ;
switch ( V_532 ) {
case V_535 : {
struct V_536 V_364 * V_537 = V_534 ;
struct V_536 V_538 ;
unsigned V_472 ;
V_100 = - V_81 ;
if ( F_210 ( & V_538 , V_537 , sizeof V_538 ) )
goto V_94;
V_472 = V_538 . V_469 ;
V_538 . V_469 = V_539 + F_44 ( V_540 ) ;
if ( F_211 ( V_537 , & V_538 , sizeof V_538 ) )
goto V_94;
V_100 = - V_352 ;
if ( V_472 < V_538 . V_469 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_537 -> V_541 , & V_542 ,
V_539 * sizeof( T_1 ) ) )
goto V_94;
if ( F_211 ( V_537 -> V_541 + V_539 ,
& V_540 ,
F_44 ( V_540 ) * sizeof( T_1 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_543 : {
struct V_544 V_364 * V_545 = V_534 ;
struct V_544 V_546 ;
V_100 = - V_81 ;
if ( F_210 ( & V_546 , V_545 , sizeof V_546 ) )
goto V_94;
V_100 = F_217 ( & V_546 ,
V_545 -> V_467 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_545 , & V_546 , sizeof V_546 ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_547 : {
T_2 V_548 ;
V_548 = V_549 ;
V_100 = - V_81 ;
if ( F_211 ( V_534 , & V_548 , sizeof V_548 ) )
goto V_94;
V_100 = 0 ;
break;
}
default:
V_100 = - V_550 ;
}
V_94:
return V_100 ;
}
static void F_218 ( void * V_551 )
{
F_219 () ;
}
static bool F_220 ( struct V_1 * V_2 )
{
return V_2 -> V_82 -> V_5 . V_552 &&
! ( V_2 -> V_82 -> V_5 . V_553 & V_554 ) ;
}
void F_221 ( struct V_1 * V_2 , int V_23 )
{
if ( F_220 ( V_2 ) ) {
if ( V_56 -> V_555 () )
F_222 ( V_23 , V_2 -> V_5 . V_556 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_223 ( V_2 -> V_23 ,
F_218 , NULL , 1 ) ;
}
V_56 -> V_557 ( V_2 , V_23 ) ;
if ( F_76 ( V_2 -> V_5 . V_558 ) ) {
F_224 ( V_2 , V_2 -> V_5 . V_558 ) ;
V_2 -> V_5 . V_558 = 0 ;
F_225 ( V_292 , & V_2 -> V_559 ) ;
}
if ( F_76 ( V_2 -> V_23 != V_23 ) || F_129 () ) {
T_11 V_560 = ! V_2 -> V_5 . V_561 ? 0 :
F_151 () - V_2 -> V_5 . V_561 ;
if ( V_560 < 0 )
F_226 ( L_21 ) ;
if ( F_129 () ) {
T_2 V_74 = V_56 -> V_262 ( V_2 ,
V_2 -> V_5 . V_274 ) ;
V_56 -> V_276 ( V_2 , V_74 ) ;
V_2 -> V_5 . V_294 = 1 ;
}
if ( ! V_2 -> V_82 -> V_5 . V_250 || V_2 -> V_23 == - 1 )
F_25 ( V_292 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_227 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_180 ( V_2 ) ;
F_25 ( V_421 , V_2 ) ;
}
void F_228 ( struct V_1 * V_2 )
{
V_56 -> V_562 ( V_2 ) ;
F_229 ( V_2 ) ;
V_2 -> V_5 . V_561 = F_151 () ;
}
static int F_230 ( struct V_1 * V_2 ,
struct V_563 * V_564 )
{
V_56 -> V_565 ( V_2 ) ;
memcpy ( V_564 -> V_566 , V_2 -> V_5 . V_567 -> V_566 , sizeof *V_564 ) ;
return 0 ;
}
static int F_231 ( struct V_1 * V_2 ,
struct V_563 * V_564 )
{
F_232 ( V_2 , V_564 ) ;
F_233 ( V_2 ) ;
return 0 ;
}
static int F_234 ( struct V_1 * V_2 ,
struct V_568 * V_569 )
{
if ( V_569 -> V_569 >= V_570 )
return - V_550 ;
if ( F_79 ( V_2 -> V_82 ) )
return - V_571 ;
F_235 ( V_2 , V_569 -> V_569 , false ) ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_236 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
return 0 ;
}
static int F_237 ( struct V_1 * V_2 ,
struct V_572 * V_573 )
{
if ( V_573 -> V_258 )
return - V_550 ;
V_2 -> V_5 . V_574 = ! ! V_573 -> V_324 ;
return 0 ;
}
static int F_238 ( struct V_1 * V_2 ,
T_2 V_332 )
{
int V_100 ;
unsigned V_333 = V_332 & 0xff , V_575 ;
V_100 = - V_550 ;
if ( ! V_333 || V_333 >= V_423 )
goto V_94;
if ( V_332 & ~ ( V_549 | 0xff | 0xff0000 ) )
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
static int F_239 ( struct V_1 * V_2 ,
struct V_576 * V_577 )
{
T_2 V_332 = V_2 -> V_5 . V_332 ;
unsigned V_333 = V_332 & 0xff ;
T_2 * V_578 = V_2 -> V_5 . V_340 ;
if ( V_577 -> V_575 >= V_333 || ! ( V_577 -> V_444 & V_579 ) )
return - V_550 ;
if ( ( V_577 -> V_444 & V_580 ) && ( V_332 & V_337 ) &&
V_2 -> V_5 . V_338 != ~ ( T_2 ) 0 )
return 0 ;
V_578 += 4 * V_577 -> V_575 ;
if ( ( V_577 -> V_444 & V_580 ) && V_578 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_577 -> V_444 & V_580 ) {
if ( ( V_2 -> V_5 . V_335 & V_581 ) ||
! F_56 ( V_2 , V_582 ) ) {
F_25 ( V_54 , V_2 ) ;
return 0 ;
}
if ( V_578 [ 1 ] & V_579 )
V_577 -> V_444 |= V_583 ;
V_578 [ 2 ] = V_577 -> V_360 ;
V_578 [ 3 ] = V_577 -> V_584 ;
V_2 -> V_5 . V_335 = V_577 -> V_335 ;
V_578 [ 1 ] = V_577 -> V_444 ;
F_26 ( V_2 , V_585 ) ;
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
static void F_240 ( struct V_1 * V_2 ,
struct V_586 * V_587 )
{
F_241 ( V_2 ) ;
V_587 -> V_49 . V_588 =
V_2 -> V_5 . V_49 . V_50 &&
! F_242 ( V_2 -> V_5 . V_49 . V_16 ) ;
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
V_587 -> V_601 = 0 ;
V_587 -> V_258 = ( V_602
| V_603 ) ;
memset ( & V_587 -> V_604 , 0 , sizeof( V_587 -> V_604 ) ) ;
}
static int F_243 ( struct V_1 * V_2 ,
struct V_586 * V_587 )
{
if ( V_587 -> V_258 & ~ ( V_602
| V_605
| V_603 ) )
return - V_550 ;
F_241 ( V_2 ) ;
V_2 -> V_5 . V_49 . V_50 = V_587 -> V_49 . V_588 ;
V_2 -> V_5 . V_49 . V_16 = V_587 -> V_49 . V_16 ;
V_2 -> V_5 . V_49 . V_52 = V_587 -> V_49 . V_52 ;
V_2 -> V_5 . V_49 . V_43 = V_587 -> V_49 . V_43 ;
V_2 -> V_5 . V_590 . V_50 = V_587 -> V_590 . V_588 ;
V_2 -> V_5 . V_590 . V_16 = V_587 -> V_590 . V_16 ;
V_2 -> V_5 . V_590 . V_591 = V_587 -> V_590 . V_591 ;
if ( V_587 -> V_258 & V_603 )
V_56 -> V_606 ( V_2 ,
V_587 -> V_590 . V_592 ) ;
V_2 -> V_5 . V_597 = V_587 -> V_596 . V_588 ;
if ( V_587 -> V_258 & V_602 )
V_2 -> V_5 . V_598 = V_587 -> V_596 . V_50 ;
V_56 -> V_607 ( V_2 , V_587 -> V_596 . V_599 ) ;
if ( V_587 -> V_258 & V_605 &&
F_244 ( V_2 ) )
V_2 -> V_5 . V_567 -> V_601 = V_587 -> V_601 ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
static void F_245 ( struct V_1 * V_2 ,
struct V_608 * V_609 )
{
memcpy ( V_609 -> V_157 , V_2 -> V_5 . V_157 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_609 -> V_160 = V_2 -> V_5 . V_160 ;
V_609 -> V_148 = V_2 -> V_5 . V_148 ;
V_609 -> V_258 = 0 ;
memset ( & V_609 -> V_604 , 0 , sizeof( V_609 -> V_604 ) ) ;
}
static int F_246 ( struct V_1 * V_2 ,
struct V_608 * V_609 )
{
if ( V_609 -> V_258 )
return - V_550 ;
memcpy ( V_2 -> V_5 . V_157 , V_609 -> V_157 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_2 -> V_5 . V_160 = V_609 -> V_160 ;
V_2 -> V_5 . V_148 = V_609 -> V_148 ;
return 0 ;
}
static void F_247 ( struct V_1 * V_2 ,
struct V_610 * V_611 )
{
if ( V_525 )
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
static int F_248 ( struct V_1 * V_2 ,
struct V_610 * V_611 )
{
T_2 V_621 =
* ( T_2 * ) & V_611 -> V_612 [ V_619 / sizeof( T_1 ) ] ;
if ( V_525 )
memcpy ( & V_2 -> V_5 . V_613 . V_614 -> V_615 ,
V_611 -> V_612 , V_616 ) ;
else {
if ( V_621 & ~ V_620 )
return - V_550 ;
memcpy ( & V_2 -> V_5 . V_613 . V_614 -> V_617 ,
V_611 -> V_612 , sizeof( struct V_618 ) ) ;
}
return 0 ;
}
static void F_249 ( struct V_1 * V_2 ,
struct V_622 * V_623 )
{
if ( ! V_525 ) {
V_623 -> V_624 = 0 ;
return;
}
V_623 -> V_624 = 1 ;
V_623 -> V_258 = 0 ;
V_623 -> V_625 [ 0 ] . V_125 = V_121 ;
V_623 -> V_625 [ 0 ] . V_22 = V_2 -> V_5 . V_122 ;
}
static int F_250 ( struct V_1 * V_2 ,
struct V_622 * V_623 )
{
int V_3 , V_100 = 0 ;
if ( ! V_525 )
return - V_550 ;
if ( V_623 -> V_624 > V_626 || V_623 -> V_258 )
return - V_550 ;
for ( V_3 = 0 ; V_3 < V_623 -> V_624 ; V_3 ++ )
if ( V_623 -> V_625 [ 0 ] . V_125 == V_121 ) {
V_100 = F_64 ( V_2 , V_121 ,
V_623 -> V_625 [ 0 ] . V_22 ) ;
break;
}
if ( V_100 )
V_100 = - V_550 ;
return V_100 ;
}
static int F_251 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_295 )
return - V_550 ;
V_2 -> V_5 . V_303 = true ;
F_25 ( V_292 , V_2 ) ;
return 0 ;
}
long F_252 ( struct V_530 * V_531 ,
unsigned int V_532 , unsigned long V_533 )
{
struct V_1 * V_2 = V_531 -> V_627 ;
void V_364 * V_534 = ( void V_364 * ) V_533 ;
int V_100 ;
union {
struct V_563 * V_628 ;
struct V_610 * V_615 ;
struct V_622 * V_625 ;
void * V_629 ;
} V_630 ;
V_630 . V_629 = NULL ;
switch ( V_532 ) {
case V_631 : {
V_100 = - V_550 ;
if ( ! V_2 -> V_5 . V_567 )
goto V_94;
V_630 . V_628 = F_253 ( sizeof( struct V_563 ) , V_632 ) ;
V_100 = - V_353 ;
if ( ! V_630 . V_628 )
goto V_94;
V_100 = F_230 ( V_2 , V_630 . V_628 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_534 , V_630 . V_628 , sizeof( struct V_563 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_633 : {
V_100 = - V_550 ;
if ( ! V_2 -> V_5 . V_567 )
goto V_94;
V_630 . V_628 = F_162 ( V_534 , sizeof( * V_630 . V_628 ) ) ;
if ( F_163 ( V_630 . V_628 ) )
return F_164 ( V_630 . V_628 ) ;
V_100 = F_231 ( V_2 , V_630 . V_628 ) ;
break;
}
case V_634 : {
struct V_568 V_569 ;
V_100 = - V_81 ;
if ( F_210 ( & V_569 , V_534 , sizeof V_569 ) )
goto V_94;
V_100 = F_234 ( V_2 , & V_569 ) ;
break;
}
case V_635 : {
V_100 = F_236 ( V_2 ) ;
break;
}
case V_636 : {
struct V_637 V_364 * V_545 = V_534 ;
struct V_637 V_546 ;
V_100 = - V_81 ;
if ( F_210 ( & V_546 , V_545 , sizeof V_546 ) )
goto V_94;
V_100 = F_254 ( V_2 , & V_546 , V_545 -> V_467 ) ;
break;
}
case V_638 : {
struct V_544 V_364 * V_545 = V_534 ;
struct V_544 V_546 ;
V_100 = - V_81 ;
if ( F_210 ( & V_546 , V_545 , sizeof V_546 ) )
goto V_94;
V_100 = F_255 ( V_2 , & V_546 ,
V_545 -> V_467 ) ;
break;
}
case V_639 : {
struct V_544 V_364 * V_545 = V_534 ;
struct V_544 V_546 ;
V_100 = - V_81 ;
if ( F_210 ( & V_546 , V_545 , sizeof V_546 ) )
goto V_94;
V_100 = F_256 ( V_2 , & V_546 ,
V_545 -> V_467 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_545 , & V_546 , sizeof V_546 ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_640 :
V_100 = F_209 ( V_2 , V_534 , F_194 , 1 ) ;
break;
case V_641 :
V_100 = F_209 ( V_2 , V_534 , F_98 , 0 ) ;
break;
case V_642 : {
struct V_572 V_573 ;
V_100 = - V_81 ;
if ( F_210 ( & V_573 , V_534 , sizeof V_573 ) )
goto V_94;
V_100 = F_237 ( V_2 , & V_573 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_534 , & V_573 , sizeof V_573 ) )
goto V_94;
V_100 = 0 ;
break;
} ;
case V_643 : {
struct V_644 V_645 ;
V_100 = - V_550 ;
if ( ! F_79 ( V_2 -> V_82 ) )
goto V_94;
V_100 = - V_81 ;
if ( F_210 ( & V_645 , V_534 , sizeof V_645 ) )
goto V_94;
V_100 = 0 ;
F_257 ( V_2 , V_645 . V_646 ) ;
break;
}
case V_647 : {
T_2 V_332 ;
V_100 = - V_81 ;
if ( F_210 ( & V_332 , V_534 , sizeof V_332 ) )
goto V_94;
V_100 = F_238 ( V_2 , V_332 ) ;
break;
}
case V_648 : {
struct V_576 V_577 ;
V_100 = - V_81 ;
if ( F_210 ( & V_577 , V_534 , sizeof V_577 ) )
goto V_94;
V_100 = F_239 ( V_2 , & V_577 ) ;
break;
}
case V_649 : {
struct V_586 V_587 ;
F_240 ( V_2 , & V_587 ) ;
V_100 = - V_81 ;
if ( F_211 ( V_534 , & V_587 , sizeof( struct V_586 ) ) )
break;
V_100 = 0 ;
break;
}
case V_650 : {
struct V_586 V_587 ;
V_100 = - V_81 ;
if ( F_210 ( & V_587 , V_534 , sizeof( struct V_586 ) ) )
break;
V_100 = F_243 ( V_2 , & V_587 ) ;
break;
}
case V_651 : {
struct V_608 V_609 ;
F_245 ( V_2 , & V_609 ) ;
V_100 = - V_81 ;
if ( F_211 ( V_534 , & V_609 ,
sizeof( struct V_608 ) ) )
break;
V_100 = 0 ;
break;
}
case V_652 : {
struct V_608 V_609 ;
V_100 = - V_81 ;
if ( F_210 ( & V_609 , V_534 ,
sizeof( struct V_608 ) ) )
break;
V_100 = F_246 ( V_2 , & V_609 ) ;
break;
}
case V_653 : {
V_630 . V_615 = F_253 ( sizeof( struct V_610 ) , V_632 ) ;
V_100 = - V_353 ;
if ( ! V_630 . V_615 )
break;
F_247 ( V_2 , V_630 . V_615 ) ;
V_100 = - V_81 ;
if ( F_211 ( V_534 , V_630 . V_615 , sizeof( struct V_610 ) ) )
break;
V_100 = 0 ;
break;
}
case V_654 : {
V_630 . V_615 = F_162 ( V_534 , sizeof( * V_630 . V_615 ) ) ;
if ( F_163 ( V_630 . V_615 ) )
return F_164 ( V_630 . V_615 ) ;
V_100 = F_248 ( V_2 , V_630 . V_615 ) ;
break;
}
case V_655 : {
V_630 . V_625 = F_253 ( sizeof( struct V_622 ) , V_632 ) ;
V_100 = - V_353 ;
if ( ! V_630 . V_625 )
break;
F_249 ( V_2 , V_630 . V_625 ) ;
V_100 = - V_81 ;
if ( F_211 ( V_534 , V_630 . V_625 ,
sizeof( struct V_622 ) ) )
break;
V_100 = 0 ;
break;
}
case V_656 : {
V_630 . V_625 = F_162 ( V_534 , sizeof( * V_630 . V_625 ) ) ;
if ( F_163 ( V_630 . V_625 ) )
return F_164 ( V_630 . V_625 ) ;
V_100 = F_250 ( V_2 , V_630 . V_625 ) ;
break;
}
case V_657 : {
T_1 V_658 ;
V_100 = - V_550 ;
V_658 = ( T_1 ) V_533 ;
if ( V_658 >= V_659 )
goto V_94;
if ( V_658 == 0 )
V_658 = V_235 ;
F_121 ( V_2 , V_658 ) ;
V_100 = 0 ;
goto V_94;
}
case V_660 : {
V_100 = V_2 -> V_5 . V_234 ;
goto V_94;
}
case V_661 : {
V_100 = F_251 ( V_2 ) ;
goto V_94;
}
default:
V_100 = - V_550 ;
}
V_94:
F_165 ( V_630 . V_629 ) ;
return V_100 ;
}
int F_258 ( struct V_1 * V_2 , struct V_662 * V_663 )
{
return V_664 ;
}
static int F_259 ( struct V_82 * V_82 , unsigned long V_360 )
{
int V_89 ;
if ( V_360 > ( unsigned int ) ( - 3 * V_88 ) )
return - V_550 ;
V_89 = V_56 -> V_665 ( V_82 , V_360 ) ;
return V_89 ;
}
static int F_260 ( struct V_82 * V_82 ,
T_2 V_666 )
{
V_82 -> V_5 . V_667 = V_666 ;
return 0 ;
}
static int F_261 ( struct V_82 * V_82 ,
T_1 V_668 )
{
if ( V_668 < V_669 )
return - V_550 ;
F_191 ( & V_82 -> V_670 ) ;
F_262 ( V_82 , V_668 ) ;
V_82 -> V_5 . V_671 = V_668 ;
F_192 ( & V_82 -> V_670 ) ;
return 0 ;
}
static int F_263 ( struct V_82 * V_82 )
{
return V_82 -> V_5 . V_672 ;
}
static int F_264 ( struct V_82 * V_82 , struct V_673 * V_674 )
{
int V_100 ;
V_100 = 0 ;
switch ( V_674 -> V_675 ) {
case V_676 :
memcpy ( & V_674 -> V_674 . V_677 ,
& F_265 ( V_82 ) -> V_678 [ 0 ] ,
sizeof( struct V_679 ) ) ;
break;
case V_680 :
memcpy ( & V_674 -> V_674 . V_677 ,
& F_265 ( V_82 ) -> V_678 [ 1 ] ,
sizeof( struct V_679 ) ) ;
break;
case V_681 :
V_100 = F_266 ( V_82 , & V_674 -> V_674 . V_682 ) ;
break;
default:
V_100 = - V_550 ;
break;
}
return V_100 ;
}
static int F_267 ( struct V_82 * V_82 , struct V_673 * V_674 )
{
int V_100 ;
V_100 = 0 ;
switch ( V_674 -> V_675 ) {
case V_676 :
F_132 ( & F_265 ( V_82 ) -> V_438 ) ;
memcpy ( & F_265 ( V_82 ) -> V_678 [ 0 ] ,
& V_674 -> V_674 . V_677 ,
sizeof( struct V_679 ) ) ;
F_133 ( & F_265 ( V_82 ) -> V_438 ) ;
break;
case V_680 :
F_132 ( & F_265 ( V_82 ) -> V_438 ) ;
memcpy ( & F_265 ( V_82 ) -> V_678 [ 1 ] ,
& V_674 -> V_674 . V_677 ,
sizeof( struct V_679 ) ) ;
F_133 ( & F_265 ( V_82 ) -> V_438 ) ;
break;
case V_681 :
V_100 = F_268 ( V_82 , & V_674 -> V_674 . V_682 ) ;
break;
default:
V_100 = - V_550 ;
break;
}
F_269 ( F_265 ( V_82 ) ) ;
return V_100 ;
}
static int F_270 ( struct V_82 * V_82 , struct V_683 * V_684 )
{
int V_100 = 0 ;
F_191 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
memcpy ( V_684 , & V_82 -> V_5 . V_685 -> V_686 , sizeof( struct V_683 ) ) ;
F_192 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
return V_100 ;
}
static int F_271 ( struct V_82 * V_82 , struct V_683 * V_684 )
{
int V_100 = 0 ;
F_191 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
memcpy ( & V_82 -> V_5 . V_685 -> V_686 , V_684 , sizeof( struct V_683 ) ) ;
F_272 ( V_82 , 0 , V_684 -> V_687 [ 0 ] . V_688 , 0 ) ;
F_192 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
return V_100 ;
}
static int F_273 ( struct V_82 * V_82 , struct V_689 * V_684 )
{
int V_100 = 0 ;
F_191 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
memcpy ( V_684 -> V_687 , & V_82 -> V_5 . V_685 -> V_686 . V_687 ,
sizeof( V_684 -> V_687 ) ) ;
V_684 -> V_258 = V_82 -> V_5 . V_685 -> V_686 . V_258 ;
F_192 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
memset ( & V_684 -> V_604 , 0 , sizeof( V_684 -> V_604 ) ) ;
return V_100 ;
}
static int F_274 ( struct V_82 * V_82 , struct V_689 * V_684 )
{
int V_100 = 0 , V_690 = 0 ;
T_1 V_691 , V_692 ;
F_191 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
V_691 = V_82 -> V_5 . V_685 -> V_686 . V_258 & V_693 ;
V_692 = V_684 -> V_258 & V_693 ;
if ( ! V_691 && V_692 )
V_690 = 1 ;
memcpy ( & V_82 -> V_5 . V_685 -> V_686 . V_687 , & V_684 -> V_687 ,
sizeof( V_82 -> V_5 . V_685 -> V_686 . V_687 ) ) ;
V_82 -> V_5 . V_685 -> V_686 . V_258 = V_684 -> V_258 ;
F_272 ( V_82 , 0 , V_82 -> V_5 . V_685 -> V_686 . V_687 [ 0 ] . V_688 , V_690 ) ;
F_192 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
return V_100 ;
}
static int F_275 ( struct V_82 * V_82 ,
struct V_694 * V_695 )
{
if ( ! V_82 -> V_5 . V_685 )
return - V_571 ;
F_191 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
V_82 -> V_5 . V_685 -> V_686 . V_44 = V_695 -> V_696 ;
F_192 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
return 0 ;
}
int F_276 ( struct V_82 * V_82 , struct V_697 * log )
{
int V_100 ;
struct V_698 * V_699 ;
unsigned long V_472 , V_3 ;
unsigned long * V_700 ;
unsigned long * V_701 ;
bool V_702 = false ;
F_191 ( & V_82 -> V_670 ) ;
V_100 = - V_550 ;
if ( log -> V_10 >= V_519 )
goto V_94;
V_699 = F_277 ( V_82 -> V_703 , log -> V_10 ) ;
V_700 = V_699 -> V_700 ;
V_100 = - V_704 ;
if ( ! V_700 )
goto V_94;
V_472 = F_278 ( V_699 ) ;
V_701 = V_700 + V_472 / sizeof( long ) ;
memset ( V_701 , 0 , V_472 ) ;
F_132 ( & V_82 -> V_705 ) ;
for ( V_3 = 0 ; V_3 < V_472 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_27 ;
T_4 V_74 ;
if ( ! V_700 [ V_3 ] )
continue;
V_702 = true ;
V_27 = F_279 ( & V_700 [ V_3 ] , 0 ) ;
V_701 [ V_3 ] = V_27 ;
V_74 = V_3 * V_706 ;
F_280 ( V_82 , V_699 , V_74 , V_27 ) ;
}
if ( V_702 )
F_281 ( V_82 ) ;
F_133 ( & V_82 -> V_705 ) ;
V_100 = - V_81 ;
if ( F_211 ( log -> V_700 , V_701 , V_472 ) )
goto V_94;
V_100 = 0 ;
V_94:
F_192 ( & V_82 -> V_670 ) ;
return V_100 ;
}
int F_282 ( struct V_82 * V_82 , struct V_707 * V_708 ,
bool V_709 )
{
if ( ! F_79 ( V_82 ) )
return - V_571 ;
V_708 -> V_444 = F_283 ( V_82 , V_710 ,
V_708 -> V_569 , V_708 -> V_711 ,
V_709 ) ;
return 0 ;
}
long F_284 ( struct V_530 * V_531 ,
unsigned int V_532 , unsigned long V_533 )
{
struct V_82 * V_82 = V_531 -> V_627 ;
void V_364 * V_534 = ( void V_364 * ) V_533 ;
int V_100 = - V_712 ;
union {
struct V_683 V_684 ;
struct V_689 V_713 ;
struct V_714 V_715 ;
} V_630 ;
switch ( V_532 ) {
case V_716 :
V_100 = F_259 ( V_82 , V_533 ) ;
break;
case V_717 : {
T_2 V_666 ;
V_100 = - V_81 ;
if ( F_210 ( & V_666 , V_534 , sizeof V_666 ) )
goto V_94;
V_100 = F_260 ( V_82 , V_666 ) ;
break;
}
case V_718 :
V_100 = F_261 ( V_82 , V_533 ) ;
break;
case V_719 :
V_100 = F_263 ( V_82 ) ;
break;
case V_720 : {
struct V_721 * V_722 ;
F_191 ( & V_82 -> V_438 ) ;
V_100 = - V_723 ;
if ( V_82 -> V_5 . V_722 )
goto V_724;
V_100 = - V_550 ;
if ( F_124 ( & V_82 -> V_248 ) )
goto V_724;
V_100 = - V_353 ;
V_722 = F_285 ( V_82 ) ;
if ( V_722 ) {
V_100 = F_286 ( V_82 ) ;
if ( V_100 ) {
F_191 ( & V_82 -> V_670 ) ;
F_287 ( V_82 , V_725 ,
& V_722 -> V_726 ) ;
F_287 ( V_82 , V_725 ,
& V_722 -> V_727 ) ;
F_287 ( V_82 , V_725 ,
& V_722 -> V_728 ) ;
F_192 ( & V_82 -> V_670 ) ;
F_165 ( V_722 ) ;
goto V_724;
}
} else
goto V_724;
F_13 () ;
V_82 -> V_5 . V_722 = V_722 ;
F_13 () ;
V_100 = F_288 ( V_82 ) ;
if ( V_100 ) {
F_191 ( & V_82 -> V_670 ) ;
F_191 ( & V_82 -> V_729 ) ;
F_289 ( V_82 ) ;
F_290 ( V_82 ) ;
F_192 ( & V_82 -> V_729 ) ;
F_192 ( & V_82 -> V_670 ) ;
}
V_724:
F_192 ( & V_82 -> V_438 ) ;
break;
}
case V_730 :
V_630 . V_715 . V_258 = V_731 ;
goto V_732;
case V_733 :
V_100 = - V_81 ;
if ( F_210 ( & V_630 . V_715 , V_534 ,
sizeof( struct V_714 ) ) )
goto V_94;
V_732:
F_191 ( & V_82 -> V_670 ) ;
V_100 = - V_723 ;
if ( V_82 -> V_5 . V_685 )
goto V_734;
V_100 = - V_353 ;
V_82 -> V_5 . V_685 = F_291 ( V_82 , V_630 . V_715 . V_258 ) ;
if ( V_82 -> V_5 . V_685 )
V_100 = 0 ;
V_734:
F_192 ( & V_82 -> V_670 ) ;
break;
case V_735 : {
struct V_673 * V_674 ;
V_674 = F_162 ( V_534 , sizeof( * V_674 ) ) ;
if ( F_163 ( V_674 ) ) {
V_100 = F_164 ( V_674 ) ;
goto V_94;
}
V_100 = - V_571 ;
if ( ! F_79 ( V_82 ) )
goto V_736;
V_100 = F_264 ( V_82 , V_674 ) ;
if ( V_100 )
goto V_736;
V_100 = - V_81 ;
if ( F_211 ( V_534 , V_674 , sizeof *V_674 ) )
goto V_736;
V_100 = 0 ;
V_736:
F_165 ( V_674 ) ;
break;
}
case V_737 : {
struct V_673 * V_674 ;
V_674 = F_162 ( V_534 , sizeof( * V_674 ) ) ;
if ( F_163 ( V_674 ) ) {
V_100 = F_164 ( V_674 ) ;
goto V_94;
}
V_100 = - V_571 ;
if ( ! F_79 ( V_82 ) )
goto V_738;
V_100 = F_267 ( V_82 , V_674 ) ;
if ( V_100 )
goto V_738;
V_100 = 0 ;
V_738:
F_165 ( V_674 ) ;
break;
}
case V_739 : {
V_100 = - V_81 ;
if ( F_210 ( & V_630 . V_684 , V_534 , sizeof( struct V_683 ) ) )
goto V_94;
V_100 = - V_571 ;
if ( ! V_82 -> V_5 . V_685 )
goto V_94;
V_100 = F_270 ( V_82 , & V_630 . V_684 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_534 , & V_630 . V_684 , sizeof( struct V_683 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_740 : {
V_100 = - V_81 ;
if ( F_210 ( & V_630 . V_684 , V_534 , sizeof V_630 . V_684 ) )
goto V_94;
V_100 = - V_571 ;
if ( ! V_82 -> V_5 . V_685 )
goto V_94;
V_100 = F_271 ( V_82 , & V_630 . V_684 ) ;
break;
}
case V_741 : {
V_100 = - V_571 ;
if ( ! V_82 -> V_5 . V_685 )
goto V_94;
V_100 = F_273 ( V_82 , & V_630 . V_713 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_211 ( V_534 , & V_630 . V_713 , sizeof( V_630 . V_713 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_742 : {
V_100 = - V_81 ;
if ( F_210 ( & V_630 . V_713 , V_534 , sizeof( V_630 . V_713 ) ) )
goto V_94;
V_100 = - V_571 ;
if ( ! V_82 -> V_5 . V_685 )
goto V_94;
V_100 = F_274 ( V_82 , & V_630 . V_713 ) ;
break;
}
case V_743 : {
struct V_694 V_695 ;
V_100 = - V_81 ;
if ( F_210 ( & V_695 , V_534 , sizeof( V_695 ) ) )
goto V_94;
V_100 = F_275 ( V_82 , & V_695 ) ;
break;
}
case V_744 : {
V_100 = - V_81 ;
if ( F_210 ( & V_82 -> V_5 . F_161 , V_534 ,
sizeof( struct V_745 ) ) )
goto V_94;
V_100 = - V_550 ;
if ( V_82 -> V_5 . F_161 . V_258 )
goto V_94;
V_100 = 0 ;
break;
}
case V_746 : {
struct V_747 V_748 ;
T_2 V_749 ;
T_11 V_268 ;
V_100 = - V_81 ;
if ( F_210 ( & V_748 , V_534 , sizeof( V_748 ) ) )
goto V_94;
V_100 = - V_550 ;
if ( V_748 . V_258 )
goto V_94;
V_100 = 0 ;
F_292 () ;
V_749 = F_111 () ;
V_268 = V_748 . clock - V_749 ;
F_293 () ;
V_82 -> V_5 . V_209 = V_268 ;
break;
}
case V_750 : {
struct V_747 V_748 ;
T_2 V_749 ;
F_292 () ;
V_749 = F_111 () ;
V_748 . clock = V_82 -> V_5 . V_209 + V_749 ;
F_293 () ;
V_748 . V_258 = 0 ;
memset ( & V_748 . V_589 , 0 , sizeof( V_748 . V_589 ) ) ;
V_100 = - V_81 ;
if ( F_211 ( V_534 , & V_748 , sizeof( V_748 ) ) )
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
static void F_294 ( void )
{
T_1 V_751 [ 2 ] ;
unsigned V_3 , V_752 ;
for ( V_3 = V_752 = V_753 ; V_3 < F_44 ( V_542 ) ; V_3 ++ ) {
if ( F_295 ( V_542 [ V_3 ] , & V_751 [ 0 ] , & V_751 [ 1 ] ) < 0 )
continue;
if ( V_752 < V_3 )
V_542 [ V_752 ] = V_542 [ V_3 ] ;
V_752 ++ ;
}
V_539 = V_752 ;
}
static int F_296 ( struct V_1 * V_2 , T_5 V_360 , int V_75 ,
const void * V_229 )
{
int V_754 = 0 ;
int V_472 ;
do {
V_472 = F_297 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_567 &&
! F_298 ( & V_2 -> V_5 . V_567 -> V_755 , V_360 , V_472 , V_229 ) )
&& F_299 ( V_2 -> V_82 , V_756 , V_360 , V_472 , V_229 ) )
break;
V_754 += V_472 ;
V_360 += V_472 ;
V_75 -= V_472 ;
V_229 += V_472 ;
} while ( V_75 );
return V_754 ;
}
static int F_300 ( struct V_1 * V_2 , T_5 V_360 , int V_75 , void * V_229 )
{
int V_754 = 0 ;
int V_472 ;
do {
V_472 = F_297 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_567 &&
! F_301 ( & V_2 -> V_5 . V_567 -> V_755 , V_360 , V_472 , V_229 ) )
&& F_302 ( V_2 -> V_82 , V_756 , V_360 , V_472 , V_229 ) )
break;
F_303 ( V_757 , V_472 , V_360 , * ( T_2 * ) V_229 ) ;
V_754 += V_472 ;
V_360 += V_472 ;
V_75 -= V_472 ;
V_229 += V_472 ;
} while ( V_75 );
return V_754 ;
}
static void F_304 ( struct V_1 * V_2 ,
struct V_758 * V_759 , int V_760 )
{
V_56 -> V_761 ( V_2 , V_759 , V_760 ) ;
}
void F_305 ( struct V_1 * V_2 ,
struct V_758 * V_759 , int V_760 )
{
V_56 -> V_762 ( V_2 , V_759 , V_760 ) ;
}
T_5 F_306 ( struct V_1 * V_2 , T_5 V_375 , T_1 V_76 )
{
T_5 V_763 ;
struct V_58 V_49 ;
F_307 ( ! F_33 ( V_2 ) ) ;
V_76 |= V_92 ;
V_763 = V_2 -> V_5 . V_67 . V_764 ( V_2 , V_375 , V_76 , & V_49 ) ;
return V_763 ;
}
T_5 F_308 ( struct V_1 * V_2 , T_14 V_765 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return V_2 -> V_5 . V_84 -> V_764 ( V_2 , V_765 , V_76 , V_49 ) ;
}
T_5 F_309 ( struct V_1 * V_2 , T_14 V_765 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
V_76 |= V_766 ;
return V_2 -> V_5 . V_84 -> V_764 ( V_2 , V_765 , V_76 , V_49 ) ;
}
T_5 F_310 ( struct V_1 * V_2 , T_14 V_765 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
V_76 |= V_93 ;
return V_2 -> V_5 . V_84 -> V_764 ( V_2 , V_765 , V_76 , V_49 ) ;
}
T_5 F_311 ( struct V_1 * V_2 , T_14 V_765 ,
struct V_58 * V_49 )
{
return V_2 -> V_5 . V_84 -> V_764 ( V_2 , V_765 , 0 , V_49 ) ;
}
static int F_312 ( T_14 V_360 , void * V_156 , unsigned int V_767 ,
struct V_1 * V_2 , T_1 V_76 ,
struct V_58 * V_49 )
{
void * V_31 = V_156 ;
int V_100 = V_768 ;
while ( V_767 ) {
T_5 V_375 = V_2 -> V_5 . V_84 -> V_764 ( V_2 , V_360 , V_76 ,
V_49 ) ;
unsigned V_74 = V_360 & ( V_88 - 1 ) ;
unsigned V_769 = F_297 ( V_767 , ( unsigned ) V_88 - V_74 ) ;
int V_89 ;
if ( V_375 == V_80 )
return V_770 ;
V_89 = F_103 ( V_2 -> V_82 , V_375 , V_31 , V_769 ) ;
if ( V_89 < 0 ) {
V_100 = V_771 ;
goto V_94;
}
V_767 -= V_769 ;
V_31 += V_769 ;
V_360 += V_769 ;
}
V_94:
return V_100 ;
}
static int F_313 ( struct V_772 * V_773 ,
T_14 V_360 , void * V_156 , unsigned int V_767 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return F_312 ( V_360 , V_156 , V_767 , V_2 ,
V_76 | V_766 ,
V_49 ) ;
}
int F_315 ( struct V_772 * V_773 ,
T_14 V_360 , void * V_156 , unsigned int V_767 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return F_312 ( V_360 , V_156 , V_767 , V_2 , V_76 ,
V_49 ) ;
}
static int F_316 ( struct V_772 * V_773 ,
T_14 V_360 , void * V_156 , unsigned int V_767 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
return F_312 ( V_360 , V_156 , V_767 , V_2 , 0 , V_49 ) ;
}
int F_317 ( struct V_772 * V_773 ,
T_14 V_360 , void * V_156 ,
unsigned int V_767 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
void * V_31 = V_156 ;
int V_100 = V_768 ;
while ( V_767 ) {
T_5 V_375 = V_2 -> V_5 . V_84 -> V_764 ( V_2 , V_360 ,
V_93 ,
V_49 ) ;
unsigned V_74 = V_360 & ( V_88 - 1 ) ;
unsigned V_774 = F_297 ( V_767 , ( unsigned ) V_88 - V_74 ) ;
int V_89 ;
if ( V_375 == V_80 )
return V_770 ;
V_89 = F_104 ( V_2 -> V_82 , V_375 , V_31 , V_774 ) ;
if ( V_89 < 0 ) {
V_100 = V_771 ;
goto V_94;
}
V_767 -= V_774 ;
V_31 += V_774 ;
V_360 += V_774 ;
}
V_94:
return V_100 ;
}
static int F_318 ( struct V_1 * V_2 , unsigned long V_765 ,
T_5 * V_375 , struct V_58 * V_49 ,
bool V_775 )
{
T_1 V_76 = ( ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 )
| ( V_775 ? V_93 : 0 ) ;
if ( F_319 ( V_2 , V_765 )
&& ! F_320 ( V_2 -> V_5 . V_84 , V_2 -> V_5 . V_76 , V_76 ) ) {
* V_375 = V_2 -> V_5 . V_776 << V_87 |
( V_765 & ( V_88 - 1 ) ) ;
F_321 ( V_765 , * V_375 , V_775 , false ) ;
return 1 ;
}
* V_375 = V_2 -> V_5 . V_84 -> V_764 ( V_2 , V_765 , V_76 , V_49 ) ;
if ( * V_375 == V_80 )
return - 1 ;
if ( ( * V_375 & V_349 ) == V_777 )
return 1 ;
if ( F_322 ( V_2 , * V_375 ) ) {
F_321 ( V_765 , * V_375 , V_775 , true ) ;
return 1 ;
}
return 0 ;
}
int F_323 ( struct V_1 * V_2 , T_5 V_375 ,
const void * V_156 , int V_767 )
{
int V_89 ;
V_89 = F_104 ( V_2 -> V_82 , V_375 , V_156 , V_767 ) ;
if ( V_89 < 0 )
return 0 ;
F_324 ( V_2 , V_375 , V_156 , V_767 ) ;
return 1 ;
}
static int F_325 ( struct V_1 * V_2 , void * V_156 , int V_767 )
{
if ( V_2 -> V_778 ) {
F_303 ( V_757 , V_767 ,
V_2 -> V_779 [ 0 ] . V_375 , * ( T_2 * ) V_156 ) ;
V_2 -> V_778 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_326 ( struct V_1 * V_2 , T_5 V_375 ,
void * V_156 , int V_767 )
{
return ! F_103 ( V_2 -> V_82 , V_375 , V_156 , V_767 ) ;
}
static int F_327 ( struct V_1 * V_2 , T_5 V_375 ,
void * V_156 , int V_767 )
{
return F_323 ( V_2 , V_375 , V_156 , V_767 ) ;
}
static int F_328 ( struct V_1 * V_2 , T_5 V_375 , int V_767 , void * V_156 )
{
F_303 ( V_780 , V_767 , V_375 , * ( T_2 * ) V_156 ) ;
return F_296 ( V_2 , V_375 , V_767 , V_156 ) ;
}
static int F_329 ( struct V_1 * V_2 , T_5 V_375 ,
void * V_156 , int V_767 )
{
F_303 ( V_781 , V_767 , V_375 , 0 ) ;
return V_771 ;
}
static int F_330 ( struct V_1 * V_2 , T_5 V_375 ,
void * V_156 , int V_767 )
{
struct V_782 * V_783 = & V_2 -> V_779 [ 0 ] ;
memcpy ( V_2 -> V_784 -> V_785 . V_31 , V_783 -> V_31 , F_297 ( 8u , V_783 -> V_75 ) ) ;
return V_768 ;
}
static int F_331 ( unsigned long V_360 , void * V_156 ,
unsigned int V_767 ,
struct V_58 * V_49 ,
struct V_1 * V_2 ,
const struct V_786 * V_787 )
{
T_5 V_375 ;
int V_754 , V_89 ;
bool V_775 = V_787 -> V_775 ;
struct V_782 * V_783 ;
V_89 = F_318 ( V_2 , V_360 , & V_375 , V_49 , V_775 ) ;
if ( V_89 < 0 )
return V_770 ;
if ( V_89 )
goto V_785;
if ( V_787 -> V_788 ( V_2 , V_375 , V_156 , V_767 ) )
return V_768 ;
V_785:
V_754 = V_787 -> V_789 ( V_2 , V_375 , V_767 , V_156 ) ;
if ( V_754 == V_767 )
return V_768 ;
V_375 += V_754 ;
V_767 -= V_754 ;
V_156 += V_754 ;
F_112 ( V_2 -> V_790 >= V_791 ) ;
V_783 = & V_2 -> V_779 [ V_2 -> V_790 ++ ] ;
V_783 -> V_375 = V_375 ;
V_783 -> V_31 = V_156 ;
V_783 -> V_75 = V_767 ;
return V_768 ;
}
int F_332 ( struct V_772 * V_773 , unsigned long V_360 ,
void * V_156 , unsigned int V_767 ,
struct V_58 * V_49 ,
const struct V_786 * V_787 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
T_5 V_375 ;
int V_792 ;
if ( V_787 -> V_793 &&
V_787 -> V_793 ( V_2 , V_156 , V_767 ) )
return V_768 ;
V_2 -> V_790 = 0 ;
if ( ( ( V_360 + V_767 - 1 ) ^ V_360 ) & V_349 ) {
int V_794 ;
V_794 = - V_360 & ~ V_349 ;
V_792 = F_331 ( V_360 , V_156 , V_794 , V_49 ,
V_2 , V_787 ) ;
if ( V_792 != V_768 )
return V_792 ;
V_360 += V_794 ;
V_156 += V_794 ;
V_767 -= V_794 ;
}
V_792 = F_331 ( V_360 , V_156 , V_767 , V_49 ,
V_2 , V_787 ) ;
if ( V_792 != V_768 )
return V_792 ;
if ( ! V_2 -> V_790 )
return V_792 ;
V_375 = V_2 -> V_779 [ 0 ] . V_375 ;
V_2 -> V_795 = 1 ;
V_2 -> V_796 = 0 ;
V_2 -> V_784 -> V_785 . V_75 = F_297 ( 8u , V_2 -> V_779 [ 0 ] . V_75 ) ;
V_2 -> V_784 -> V_785 . V_797 = V_2 -> V_798 = V_787 -> V_775 ;
V_2 -> V_784 -> V_799 = V_800 ;
V_2 -> V_784 -> V_785 . V_801 = V_375 ;
return V_787 -> V_802 ( V_2 , V_375 , V_156 , V_767 ) ;
}
static int F_333 ( struct V_772 * V_773 ,
unsigned long V_360 ,
void * V_156 ,
unsigned int V_767 ,
struct V_58 * V_49 )
{
return F_332 ( V_773 , V_360 , V_156 , V_767 ,
V_49 , & V_803 ) ;
}
int F_334 ( struct V_772 * V_773 ,
unsigned long V_360 ,
const void * V_156 ,
unsigned int V_767 ,
struct V_58 * V_49 )
{
return F_332 ( V_773 , V_360 , ( void * ) V_156 , V_767 ,
V_49 , & V_804 ) ;
}
static int F_335 ( struct V_772 * V_773 ,
unsigned long V_360 ,
const void * V_805 ,
const void * V_806 ,
unsigned int V_767 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
T_5 V_375 ;
struct V_351 * V_351 ;
char * V_807 ;
bool V_808 ;
if ( V_767 > 8 || ( V_767 & ( V_767 - 1 ) ) )
goto V_809;
V_375 = F_310 ( V_2 , V_360 , NULL ) ;
if ( V_375 == V_80 ||
( V_375 & V_349 ) == V_777 )
goto V_809;
if ( ( ( V_375 + V_767 - 1 ) & V_349 ) != ( V_375 & V_349 ) )
goto V_809;
V_351 = F_336 ( V_2 -> V_82 , V_375 >> V_87 ) ;
if ( F_337 ( V_351 ) )
goto V_809;
V_807 = F_338 ( V_351 ) ;
V_807 += F_339 ( V_375 ) ;
switch ( V_767 ) {
case 1 :
V_808 = F_340 ( T_13 , V_807 , V_805 , V_806 ) ;
break;
case 2 :
V_808 = F_340 ( V_810 , V_807 , V_805 , V_806 ) ;
break;
case 4 :
V_808 = F_340 ( T_1 , V_807 , V_805 , V_806 ) ;
break;
case 8 :
V_808 = F_341 ( V_807 , V_805 , V_806 ) ;
break;
default:
F_22 () ;
}
F_342 ( V_807 ) ;
F_343 ( V_351 ) ;
if ( ! V_808 )
return V_811 ;
F_324 ( V_2 , V_375 , V_806 , V_767 ) ;
return V_768 ;
V_809:
F_344 ( V_812 L_22 ) ;
return F_334 ( V_773 , V_360 , V_806 , V_767 , V_49 ) ;
}
static int F_345 ( struct V_1 * V_2 , void * V_813 )
{
int V_100 ;
if ( V_2 -> V_5 . V_814 . V_815 )
V_100 = F_302 ( V_2 -> V_82 , V_725 , V_2 -> V_5 . V_814 . V_816 ,
V_2 -> V_5 . V_814 . V_473 , V_813 ) ;
else
V_100 = F_299 ( V_2 -> V_82 , V_725 ,
V_2 -> V_5 . V_814 . V_816 , V_2 -> V_5 . V_814 . V_473 ,
V_813 ) ;
return V_100 ;
}
static int F_346 ( struct V_1 * V_2 , int V_473 ,
unsigned short V_816 , void * V_156 ,
unsigned int V_688 , bool V_815 )
{
F_347 ( ! V_815 , V_816 , V_473 , V_688 ) ;
V_2 -> V_5 . V_814 . V_816 = V_816 ;
V_2 -> V_5 . V_814 . V_815 = V_815 ;
V_2 -> V_5 . V_814 . V_688 = V_688 ;
V_2 -> V_5 . V_814 . V_473 = V_473 ;
if ( ! F_345 ( V_2 , V_2 -> V_5 . V_817 ) ) {
V_2 -> V_5 . V_814 . V_688 = 0 ;
return 1 ;
}
V_2 -> V_784 -> V_799 = V_818 ;
V_2 -> V_784 -> V_819 . V_820 = V_815 ? V_821 : V_822 ;
V_2 -> V_784 -> V_819 . V_473 = V_473 ;
V_2 -> V_784 -> V_819 . V_823 = V_824 * V_88 ;
V_2 -> V_784 -> V_819 . V_688 = V_688 ;
V_2 -> V_784 -> V_819 . V_816 = V_816 ;
return 0 ;
}
static int F_348 ( struct V_772 * V_773 ,
int V_473 , unsigned short V_816 , void * V_156 ,
unsigned int V_688 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
int V_89 ;
if ( V_2 -> V_5 . V_814 . V_688 )
goto V_825;
V_89 = F_346 ( V_2 , V_473 , V_816 , V_156 , V_688 , true ) ;
if ( V_89 ) {
V_825:
memcpy ( V_156 , V_2 -> V_5 . V_817 , V_473 * V_688 ) ;
V_2 -> V_5 . V_814 . V_688 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_349 ( struct V_772 * V_773 ,
int V_473 , unsigned short V_816 ,
const void * V_156 , unsigned int V_688 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
memcpy ( V_2 -> V_5 . V_817 , V_156 , V_473 * V_688 ) ;
return F_346 ( V_2 , V_473 , V_816 , ( void * ) V_156 , V_688 , false ) ;
}
static unsigned long F_350 ( struct V_1 * V_2 , int V_760 )
{
return V_56 -> F_350 ( V_2 , V_760 ) ;
}
static void F_351 ( struct V_772 * V_773 , V_144 V_63 )
{
F_352 ( F_314 ( V_773 ) , V_63 ) ;
}
int F_353 ( struct V_1 * V_2 )
{
if ( ! F_220 ( V_2 ) )
return V_768 ;
if ( V_56 -> V_555 () ) {
int V_23 = F_354 () ;
F_222 ( V_23 , V_2 -> V_5 . V_556 ) ;
F_355 ( V_2 -> V_5 . V_556 ,
F_218 , NULL , 1 ) ;
F_356 () ;
F_357 ( V_2 -> V_5 . V_556 ) ;
} else
F_219 () ;
return V_768 ;
}
static void F_358 ( struct V_772 * V_773 )
{
F_353 ( F_314 ( V_773 ) ) ;
}
int F_359 ( struct V_772 * V_773 , int V_155 , unsigned long * V_826 )
{
return F_86 ( F_314 ( V_773 ) , V_155 , V_826 ) ;
}
int F_360 ( struct V_772 * V_773 , int V_155 , unsigned long V_22 )
{
return F_84 ( F_314 ( V_773 ) , V_155 , V_22 ) ;
}
static T_2 F_361 ( T_2 V_827 , T_1 V_828 )
{
return ( V_827 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_828 ;
}
static unsigned long F_362 ( struct V_772 * V_773 , int V_829 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
unsigned long V_22 ;
switch ( V_829 ) {
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
V_22 = F_81 ( V_2 ) ;
break;
default:
F_363 ( L_23 , V_224 , V_829 ) ;
return 0 ;
}
return V_22 ;
}
static int F_364 ( struct V_772 * V_773 , int V_829 , V_144 V_156 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
int V_165 = 0 ;
switch ( V_829 ) {
case 0 :
V_165 = F_52 ( V_2 , F_361 ( F_53 ( V_2 ) , V_156 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_62 = V_156 ;
break;
case 3 :
V_165 = F_73 ( V_2 , V_156 ) ;
break;
case 4 :
V_165 = F_66 ( V_2 , F_361 ( F_67 ( V_2 ) , V_156 ) ) ;
break;
case 8 :
V_165 = F_78 ( V_2 , V_156 ) ;
break;
default:
F_363 ( L_23 , V_224 , V_829 ) ;
V_165 = - 1 ;
}
return V_165 ;
}
static void F_365 ( struct V_772 * V_773 , V_144 V_156 )
{
F_366 ( F_314 ( V_773 ) , V_156 ) ;
}
static int F_367 ( struct V_772 * V_773 )
{
return V_56 -> V_71 ( F_314 ( V_773 ) ) ;
}
static void F_368 ( struct V_772 * V_773 , struct V_830 * V_831 )
{
V_56 -> V_832 ( F_314 ( V_773 ) , V_831 ) ;
}
static void F_369 ( struct V_772 * V_773 , struct V_830 * V_831 )
{
V_56 -> V_833 ( F_314 ( V_773 ) , V_831 ) ;
}
static void F_370 ( struct V_772 * V_773 , struct V_830 * V_831 )
{
V_56 -> V_834 ( F_314 ( V_773 ) , V_831 ) ;
}
static void F_371 ( struct V_772 * V_773 , struct V_830 * V_831 )
{
V_56 -> V_835 ( F_314 ( V_773 ) , V_831 ) ;
}
static unsigned long F_372 (
struct V_772 * V_773 , int V_760 )
{
return F_350 ( F_314 ( V_773 ) , V_760 ) ;
}
static bool F_373 ( struct V_772 * V_773 , V_810 * V_836 ,
struct V_837 * V_838 , T_1 * V_839 ,
int V_760 )
{
struct V_758 V_759 ;
F_305 ( F_314 ( V_773 ) , & V_759 , V_760 ) ;
* V_836 = V_759 . V_836 ;
if ( V_759 . V_840 ) {
memset ( V_838 , 0 , sizeof( * V_838 ) ) ;
return false ;
}
if ( V_759 . V_841 )
V_759 . V_842 >>= 12 ;
F_374 ( V_838 , V_759 . V_842 ) ;
F_375 ( V_838 , ( unsigned long ) V_759 . V_843 ) ;
#ifdef F_54
if ( V_839 )
* V_839 = V_759 . V_843 >> 32 ;
#endif
V_838 -> type = V_759 . type ;
V_838 -> V_564 = V_759 . V_564 ;
V_838 -> V_844 = V_759 . V_844 ;
V_838 -> V_320 = V_759 . V_845 ;
V_838 -> V_846 = V_759 . V_846 ;
V_838 -> V_847 = V_759 . V_847 ;
V_838 -> V_848 = V_759 . V_157 ;
V_838 -> V_841 = V_759 . V_841 ;
return true ;
}
static void F_376 ( struct V_772 * V_773 , V_810 V_836 ,
struct V_837 * V_838 , T_1 V_839 ,
int V_760 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
struct V_758 V_759 ;
V_759 . V_836 = V_836 ;
V_759 . V_843 = F_377 ( V_838 ) ;
#ifdef F_54
V_759 . V_843 |= ( ( T_2 ) V_839 ) << 32 ;
#endif
V_759 . V_842 = F_378 ( V_838 ) ;
if ( V_838 -> V_841 )
V_759 . V_842 = ( V_759 . V_842 << 12 ) | 0xfff ;
V_759 . type = V_838 -> type ;
V_759 . V_845 = V_838 -> V_320 ;
V_759 . V_844 = V_838 -> V_844 ;
V_759 . V_157 = V_838 -> V_848 ;
V_759 . V_564 = V_838 -> V_564 ;
V_759 . V_847 = V_838 -> V_847 ;
V_759 . V_841 = V_838 -> V_841 ;
V_759 . V_846 = V_838 -> V_846 ;
V_759 . V_845 = V_838 -> V_320 ;
V_759 . V_840 = ! V_759 . V_845 ;
V_759 . V_849 = 0 ;
F_304 ( V_2 , & V_759 , V_760 ) ;
return;
}
static int F_379 ( struct V_772 * V_773 ,
T_1 V_446 , T_2 * V_447 )
{
return F_194 ( F_314 ( V_773 ) , V_446 , V_447 ) ;
}
static int F_380 ( struct V_772 * V_773 ,
T_1 V_446 , T_2 V_31 )
{
struct V_182 V_21 ;
V_21 . V_31 = V_31 ;
V_21 . V_124 = V_446 ;
V_21 . V_184 = false ;
return F_97 ( F_314 ( V_773 ) , & V_21 ) ;
}
static int F_381 ( struct V_772 * V_773 ,
T_1 V_850 , T_2 * V_447 )
{
return F_90 ( F_314 ( V_773 ) , V_850 , V_447 ) ;
}
static void F_382 ( struct V_772 * V_773 )
{
F_314 ( V_773 ) -> V_5 . V_851 = 1 ;
}
static void F_383 ( struct V_772 * V_773 )
{
F_186 () ;
F_384 ( F_314 ( V_773 ) ) ;
F_385 () ;
}
static void F_386 ( struct V_772 * V_773 )
{
F_187 () ;
}
static int F_387 ( struct V_772 * V_773 ,
struct V_852 * V_853 ,
enum V_854 V_855 )
{
return V_56 -> V_856 ( F_314 ( V_773 ) , V_853 , V_855 ) ;
}
static void F_388 ( struct V_772 * V_773 ,
T_1 * V_857 , T_1 * V_858 , T_1 * V_167 , T_1 * V_175 )
{
V_637 ( F_314 ( V_773 ) , V_857 , V_858 , V_167 , V_175 ) ;
}
static V_144 F_389 ( struct V_772 * V_773 , unsigned V_859 )
{
return F_89 ( F_314 ( V_773 ) , V_859 ) ;
}
static void F_390 ( struct V_772 * V_773 , unsigned V_859 , V_144 V_156 )
{
F_91 ( F_314 ( V_773 ) , V_859 , V_156 ) ;
}
static void F_391 ( struct V_1 * V_2 , T_1 V_27 )
{
T_1 V_860 = V_56 -> V_593 ( V_2 , V_27 ) ;
if ( ! ( V_860 & V_27 ) )
V_56 -> V_606 ( V_2 , V_27 ) ;
}
static void F_392 ( struct V_1 * V_2 )
{
struct V_772 * V_773 = & V_2 -> V_5 . V_861 ;
if ( V_773 -> V_49 . V_32 == V_33 )
F_32 ( V_2 , & V_773 -> V_49 ) ;
else if ( V_773 -> V_49 . V_862 )
F_31 ( V_2 , V_773 -> V_49 . V_32 ,
V_773 -> V_49 . V_43 ) ;
else
F_26 ( V_2 , V_773 -> V_49 . V_32 ) ;
}
static void F_393 ( struct V_772 * V_773 )
{
memset ( & V_773 -> V_863 , 0 ,
( void * ) & V_773 -> V_864 - ( void * ) & V_773 -> V_863 ) ;
V_773 -> V_865 . V_690 = 0 ;
V_773 -> V_865 . V_866 = 0 ;
V_773 -> V_867 . V_868 = 0 ;
V_773 -> V_867 . V_866 = 0 ;
V_773 -> V_869 . V_868 = 0 ;
V_773 -> V_869 . V_866 = 0 ;
}
static void F_394 ( struct V_1 * V_2 )
{
struct V_772 * V_773 = & V_2 -> V_5 . V_861 ;
int V_113 , V_114 ;
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
V_773 -> V_870 = F_395 ( V_2 ) ;
V_773 -> V_871 = F_396 ( V_2 ) ;
V_773 -> V_280 = ( ! F_397 ( V_2 ) ) ? V_872 :
( V_773 -> V_870 & V_873 ) ? V_874 :
V_114 ? V_875 :
V_113 ? V_876 :
V_877 ;
V_773 -> V_878 = F_398 ( V_2 ) ;
F_393 ( V_773 ) ;
V_2 -> V_5 . V_879 = false ;
}
int F_399 ( struct V_1 * V_2 , int V_569 , int V_880 )
{
struct V_772 * V_773 = & V_2 -> V_5 . V_861 ;
int V_89 ;
F_394 ( V_2 ) ;
V_773 -> V_881 = 2 ;
V_773 -> V_882 = 2 ;
V_773 -> V_883 = V_773 -> V_871 + V_880 ;
V_89 = F_400 ( V_773 , V_569 ) ;
if ( V_89 != V_768 )
return V_884 ;
V_773 -> V_871 = V_773 -> V_883 ;
F_401 ( V_2 , V_773 -> V_871 ) ;
F_366 ( V_2 , V_773 -> V_870 ) ;
if ( V_569 == V_885 )
V_2 -> V_5 . V_598 = 0 ;
else
V_2 -> V_5 . V_590 . V_50 = false ;
return V_886 ;
}
static int F_402 ( struct V_1 * V_2 )
{
int V_100 = V_886 ;
++ V_2 -> V_60 . V_887 ;
F_403 ( V_2 ) ;
if ( ! F_398 ( V_2 ) ) {
V_2 -> V_784 -> V_799 = V_888 ;
V_2 -> V_784 -> V_889 . V_890 = V_891 ;
V_2 -> V_784 -> V_889 . V_892 = 0 ;
V_100 = V_884 ;
}
F_26 ( V_2 , V_166 ) ;
return V_100 ;
}
static bool F_404 ( struct V_1 * V_2 , T_14 V_62 ,
bool V_893 ,
int V_894 )
{
T_5 V_375 = V_62 ;
T_15 V_895 ;
if ( V_894 & V_896 )
return false ;
if ( ! V_2 -> V_5 . V_67 . V_897 ) {
V_375 = F_310 ( V_2 , V_62 , NULL ) ;
if ( V_375 == V_80 )
return true ;
}
V_895 = F_405 ( V_2 -> V_82 , F_40 ( V_375 ) ) ;
if ( F_406 ( V_895 ) )
return false ;
F_407 ( V_895 ) ;
if ( V_2 -> V_5 . V_67 . V_897 ) {
unsigned int V_898 ;
F_132 ( & V_2 -> V_82 -> V_705 ) ;
V_898 = V_2 -> V_82 -> V_5 . V_898 ;
F_133 ( & V_2 -> V_82 -> V_705 ) ;
if ( V_898 )
F_408 ( V_2 -> V_82 , F_40 ( V_375 ) ) ;
return true ;
}
F_408 ( V_2 -> V_82 , F_40 ( V_375 ) ) ;
return ! V_893 ;
}
static bool F_409 ( struct V_772 * V_773 ,
unsigned long V_62 , int V_894 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
unsigned long V_899 , V_900 , V_375 = V_62 ;
V_899 = V_2 -> V_5 . V_899 ;
V_900 = V_2 -> V_5 . V_900 ;
V_2 -> V_5 . V_899 = V_2 -> V_5 . V_900 = 0 ;
if ( ! ( V_894 & V_901 ) )
return false ;
if ( F_410 ( V_773 ) )
return false ;
if ( V_773 -> V_871 == V_899 && V_900 == V_62 )
return false ;
V_2 -> V_5 . V_899 = V_773 -> V_871 ;
V_2 -> V_5 . V_900 = V_62 ;
if ( ! V_2 -> V_5 . V_67 . V_897 )
V_375 = F_310 ( V_2 , V_62 , NULL ) ;
F_408 ( V_2 -> V_82 , F_40 ( V_375 ) ) ;
return true ;
}
int F_411 ( struct V_1 * V_2 ,
unsigned long V_62 ,
int V_894 ,
void * V_902 ,
int V_903 )
{
int V_100 ;
struct V_772 * V_773 = & V_2 -> V_5 . V_861 ;
bool V_471 = true ;
bool V_904 = V_2 -> V_5 . V_893 ;
V_2 -> V_5 . V_893 = false ;
F_412 ( V_2 ) ;
if ( ! ( V_894 & V_905 ) ) {
F_394 ( V_2 ) ;
V_773 -> V_906 = 0 ;
V_773 -> V_907 = false ;
V_773 -> V_908 = false ;
V_773 -> V_909
= V_894 & V_910 ;
V_100 = F_413 ( V_773 , V_902 , V_903 ) ;
F_414 ( V_2 ) ;
++ V_2 -> V_60 . V_911 ;
if ( V_100 != V_912 ) {
if ( V_894 & V_910 )
return V_884 ;
if ( F_404 ( V_2 , V_62 , V_904 ,
V_894 ) )
return V_886 ;
if ( V_894 & V_913 )
return V_884 ;
return F_402 ( V_2 ) ;
}
}
if ( V_894 & V_913 ) {
F_401 ( V_2 , V_773 -> V_883 ) ;
return V_886 ;
}
if ( F_409 ( V_773 , V_62 , V_894 ) )
return V_886 ;
if ( V_2 -> V_5 . V_879 ) {
V_2 -> V_5 . V_879 = false ;
F_415 ( V_773 ) ;
}
V_914:
V_100 = F_416 ( V_773 ) ;
if ( V_100 == V_915 )
return V_886 ;
if ( V_100 == V_916 ) {
if ( F_404 ( V_2 , V_62 , V_904 ,
V_894 ) )
return V_886 ;
return F_402 ( V_2 ) ;
}
if ( V_773 -> V_907 ) {
F_392 ( V_2 ) ;
V_100 = V_886 ;
} else if ( V_2 -> V_5 . V_814 . V_688 ) {
if ( ! V_2 -> V_5 . V_814 . V_815 )
V_2 -> V_5 . V_814 . V_688 = 0 ;
else {
V_471 = false ;
V_2 -> V_5 . V_917 = V_918 ;
}
V_100 = V_919 ;
} else if ( V_2 -> V_795 ) {
if ( ! V_2 -> V_798 )
V_471 = false ;
V_100 = V_919 ;
V_2 -> V_5 . V_917 = V_920 ;
} else if ( V_100 == V_921 )
goto V_914;
else
V_100 = V_886 ;
if ( V_471 ) {
F_391 ( V_2 , V_773 -> V_906 ) ;
F_366 ( V_2 , V_773 -> V_870 ) ;
F_25 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_922 = false ;
F_401 ( V_2 , V_773 -> V_871 ) ;
} else
V_2 -> V_5 . V_922 = true ;
return V_100 ;
}
int F_417 ( struct V_1 * V_2 , int V_473 , unsigned short V_816 )
{
unsigned long V_156 = F_89 ( V_2 , V_169 ) ;
int V_89 = F_349 ( & V_2 -> V_5 . V_861 ,
V_473 , V_816 , & V_156 , 1 ) ;
V_2 -> V_5 . V_814 . V_688 = 0 ;
return V_89 ;
}
static void F_418 ( void * V_853 )
{
F_419 ( V_291 , 0 ) ;
}
static void F_420 ( void * V_31 )
{
struct V_923 * V_924 = V_31 ;
unsigned long V_227 = 0 ;
if ( V_31 )
V_227 = V_924 -> V_806 ;
else if ( ! F_215 ( V_925 ) )
V_227 = F_421 ( F_422 () ) ;
if ( ! V_227 )
V_227 = V_235 ;
F_419 ( V_291 , V_227 ) ;
}
static int F_423 ( struct V_926 * V_927 , unsigned long V_156 ,
void * V_31 )
{
struct V_923 * V_924 = V_31 ;
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 , V_928 = 0 ;
if ( V_156 == V_929 && V_924 -> V_805 > V_924 -> V_806 )
return 0 ;
if ( V_156 == V_930 && V_924 -> V_805 < V_924 -> V_806 )
return 0 ;
F_223 ( V_924 -> V_23 , F_420 , V_924 , 1 ) ;
F_424 ( & V_931 ) ;
F_425 (kvm, &vm_list, vm_list) {
F_199 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_924 -> V_23 )
continue;
F_25 ( V_292 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_928 = 1 ;
}
}
F_426 ( & V_931 ) ;
if ( V_924 -> V_805 < V_924 -> V_806 && V_928 ) {
F_223 ( V_924 -> V_23 , F_420 , V_924 , 1 ) ;
}
return 0 ;
}
static int F_427 ( struct V_926 * V_932 ,
unsigned long V_933 , void * V_934 )
{
unsigned int V_23 = ( unsigned long ) V_934 ;
switch ( V_933 ) {
case V_935 :
case V_936 :
F_223 ( V_23 , F_420 , NULL , 1 ) ;
break;
case V_937 :
F_223 ( V_23 , F_418 , NULL , 1 ) ;
break;
}
return V_938 ;
}
static void F_428 ( void )
{
int V_23 ;
V_939 = V_235 ;
F_429 ( & V_940 ) ;
if ( ! F_215 ( V_925 ) ) {
#ifdef F_430
struct V_941 V_942 ;
memset ( & V_942 , 0 , sizeof( V_942 ) ) ;
V_23 = F_354 () ;
F_431 ( & V_942 , V_23 ) ;
if ( V_942 . V_943 . V_944 )
V_939 = V_942 . V_943 . V_944 ;
F_356 () ;
#endif
F_432 ( & V_945 ,
V_946 ) ;
}
F_110 ( L_24 , V_939 ) ;
F_433 (cpu)
F_223 ( V_23 , F_420 , NULL , 1 ) ;
}
int F_434 ( void )
{
return F_435 ( V_947 ) != NULL ;
}
static int F_436 ( void )
{
int V_948 = 3 ;
if ( F_435 ( V_947 ) )
V_948 = V_56 -> V_71 ( F_435 ( V_947 ) ) ;
return V_948 != 0 ;
}
static unsigned long F_437 ( void )
{
unsigned long V_949 = 0 ;
if ( F_435 ( V_947 ) )
V_949 = F_396 ( F_435 ( V_947 ) ) ;
return V_949 ;
}
void F_438 ( struct V_1 * V_2 )
{
F_419 ( V_947 , V_2 ) ;
}
void F_439 ( struct V_1 * V_2 )
{
F_419 ( V_947 , NULL ) ;
}
static void F_440 ( void )
{
T_2 V_27 ;
int V_950 = V_951 . V_952 ;
V_27 = ( ( 1ull << ( 62 - V_950 + 1 ) ) - 1 ) << V_950 ;
V_27 |= 1ull ;
#ifdef F_54
if ( V_950 == 52 )
V_27 &= ~ 1ull ;
#endif
F_441 ( V_27 ) ;
}
static void F_442 ( struct V_953 * V_954 )
{
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 ;
F_424 ( & V_931 ) ;
F_425 (kvm, &vm_list, vm_list)
F_199 (i, vcpu, kvm)
F_225 ( V_251 , & V_2 -> V_559 ) ;
F_145 ( & V_284 , 0 ) ;
F_426 ( & V_931 ) ;
}
static int F_443 ( struct V_926 * V_927 , unsigned long V_955 ,
void * V_956 )
{
struct V_187 * V_246 = & V_187 ;
struct V_185 * V_186 = V_956 ;
F_99 ( V_186 ) ;
if ( V_246 -> clock . V_190 != V_249 &&
F_124 ( & V_284 ) != 0 )
F_444 ( V_957 , & V_958 ) ;
return 0 ;
}
int F_445 ( void * V_959 )
{
int V_100 ;
struct V_56 * V_787 = (struct V_56 * ) V_959 ;
if ( V_56 ) {
F_10 ( V_26 L_25 ) ;
V_100 = - V_723 ;
goto V_94;
}
if ( ! V_787 -> V_960 () ) {
F_10 ( V_26 L_26 ) ;
V_100 = - V_961 ;
goto V_94;
}
if ( V_787 -> V_962 () ) {
F_10 ( V_26 L_27 ) ;
V_100 = - V_961 ;
goto V_94;
}
V_100 = - V_353 ;
V_25 = F_446 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_94;
}
V_100 = F_447 () ;
if ( V_100 )
goto V_963;
F_440 () ;
F_294 () ;
V_56 = V_787 ;
F_448 ( V_964 , V_965 ,
V_966 , V_967 , 0 ) ;
F_428 () ;
F_449 ( & V_968 ) ;
if ( V_525 )
V_123 = F_450 ( V_121 ) ;
F_451 () ;
#ifdef F_54
F_452 ( & V_969 ) ;
#endif
return 0 ;
V_963:
F_453 ( V_25 ) ;
V_94:
return V_100 ;
}
void F_454 ( void )
{
F_455 ( & V_968 ) ;
if ( ! F_215 ( V_925 ) )
F_456 ( & V_945 ,
V_946 ) ;
F_457 ( & V_940 ) ;
#ifdef F_54
F_458 ( & V_969 ) ;
#endif
V_56 = NULL ;
F_459 () ;
F_453 ( V_25 ) ;
}
int F_460 ( struct V_1 * V_2 )
{
++ V_2 -> V_60 . V_970 ;
if ( F_79 ( V_2 -> V_82 ) ) {
V_2 -> V_5 . V_971 = V_972 ;
return 1 ;
} else {
V_2 -> V_784 -> V_799 = V_973 ;
return 0 ;
}
}
int F_461 ( struct V_1 * V_2 )
{
T_2 V_974 , V_975 , V_976 , V_89 ;
T_16 V_977 , V_978 , V_979 , V_165 = V_980 , V_981 = 0 ;
bool V_982 , V_983 ;
int V_113 , V_114 ;
if ( V_56 -> V_71 ( V_2 ) != 0 || ! F_397 ( V_2 ) ) {
F_26 ( V_2 , V_166 ) ;
return 0 ;
}
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
V_983 = F_48 ( V_2 ) && V_114 == 1 ;
if ( ! V_983 ) {
V_974 = ( ( T_2 ) F_89 ( V_2 , V_170 ) << 32 ) |
( F_89 ( V_2 , V_169 ) & 0xffffffff ) ;
V_975 = ( ( T_2 ) F_89 ( V_2 , V_984 ) << 32 ) |
( F_89 ( V_2 , V_168 ) & 0xffffffff ) ;
V_976 = ( ( T_2 ) F_89 ( V_2 , V_985 ) << 32 ) |
( F_89 ( V_2 , V_986 ) & 0xffffffff ) ;
}
#ifdef F_54
else {
V_974 = F_89 ( V_2 , V_168 ) ;
V_975 = F_89 ( V_2 , V_170 ) ;
V_976 = F_89 ( V_2 , V_987 ) ;
}
#endif
V_977 = V_974 & 0xffff ;
V_982 = ( V_974 >> 16 ) & 0x1 ;
V_979 = ( V_974 >> 32 ) & 0xfff ;
V_978 = ( V_974 >> 48 ) & 0xfff ;
F_462 ( V_977 , V_982 , V_979 , V_978 , V_975 , V_976 ) ;
switch ( V_977 ) {
case V_988 :
F_463 ( V_2 ) ;
break;
default:
V_165 = V_989 ;
break;
}
V_89 = V_165 | ( ( ( T_2 ) V_981 & 0xfff ) << 32 ) ;
if ( V_983 ) {
F_91 ( V_2 , V_169 , V_89 ) ;
} else {
F_91 ( V_2 , V_170 , V_89 >> 32 ) ;
F_91 ( V_2 , V_169 , V_89 & 0xffffffff ) ;
}
return 1 ;
}
int F_464 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_990 , V_991 , V_992 , V_993 , V_89 ;
int V_100 = 1 ;
if ( F_166 ( V_2 -> V_82 ) )
return F_461 ( V_2 ) ;
V_16 = F_89 ( V_2 , V_169 ) ;
V_990 = F_89 ( V_2 , V_984 ) ;
V_991 = F_89 ( V_2 , V_168 ) ;
V_992 = F_89 ( V_2 , V_170 ) ;
V_993 = F_89 ( V_2 , V_986 ) ;
F_465 ( V_16 , V_990 , V_991 , V_992 , V_993 ) ;
if ( ! F_48 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_990 &= 0xFFFFFFFF ;
V_991 &= 0xFFFFFFFF ;
V_992 &= 0xFFFFFFFF ;
V_993 &= 0xFFFFFFFF ;
}
if ( V_56 -> V_71 ( V_2 ) != 0 ) {
V_89 = - V_994 ;
goto V_94;
}
switch ( V_16 ) {
case V_995 :
V_89 = 0 ;
break;
default:
V_89 = - V_996 ;
break;
}
V_94:
F_91 ( V_2 , V_169 , V_89 ) ;
++ V_2 -> V_60 . V_997 ;
return V_100 ;
}
static int F_466 ( struct V_772 * V_773 )
{
struct V_1 * V_2 = F_314 ( V_773 ) ;
char V_998 [ 3 ] ;
unsigned long V_999 = F_396 ( V_2 ) ;
F_467 ( V_2 -> V_82 ) ;
V_56 -> V_363 ( V_2 , V_998 ) ;
return F_334 ( V_773 , V_999 , V_998 , 3 , NULL ) ;
}
static int F_468 ( struct V_1 * V_2 )
{
return ( ! F_79 ( V_2 -> V_82 ) && ! F_469 ( V_2 ) &&
V_2 -> V_784 -> V_1000 &&
F_470 ( V_2 ) ) ;
}
static void F_471 ( struct V_1 * V_2 )
{
struct V_1001 * V_1001 = V_2 -> V_784 ;
V_1001 -> V_1002 = ( F_395 ( V_2 ) & V_1003 ) != 0 ;
V_1001 -> V_146 = F_81 ( V_2 ) ;
V_1001 -> V_30 = F_18 ( V_2 ) ;
if ( F_79 ( V_2 -> V_82 ) )
V_1001 -> V_1004 = 1 ;
else
V_1001 -> V_1004 =
F_470 ( V_2 ) &&
! F_469 ( V_2 ) &&
! F_472 ( V_2 ) ;
}
static int F_473 ( struct V_1 * V_2 )
{
struct V_1005 * V_567 = V_2 -> V_5 . V_567 ;
struct V_351 * V_351 ;
if ( ! V_567 || ! V_567 -> V_646 )
return 0 ;
V_351 = F_336 ( V_2 -> V_82 , V_567 -> V_646 >> V_87 ) ;
if ( F_337 ( V_351 ) )
return - V_81 ;
V_2 -> V_5 . V_567 -> V_1006 = V_351 ;
return 0 ;
}
static void F_474 ( struct V_1 * V_2 )
{
struct V_1005 * V_567 = V_2 -> V_5 . V_567 ;
int V_326 ;
if ( ! V_567 || ! V_567 -> V_646 )
return;
V_326 = F_207 ( & V_2 -> V_82 -> V_468 ) ;
F_343 ( V_567 -> V_1006 ) ;
F_475 ( V_2 -> V_82 , V_567 -> V_646 >> V_87 ) ;
F_208 ( & V_2 -> V_82 -> V_468 , V_326 ) ;
}
static void F_233 ( struct V_1 * V_2 )
{
int V_1007 , V_1008 ;
if ( ! V_56 -> F_233 )
return;
if ( ! V_2 -> V_5 . V_567 )
return;
if ( ! V_2 -> V_5 . V_567 -> V_646 )
V_1007 = F_476 ( V_2 ) ;
else
V_1007 = - 1 ;
if ( V_1007 != - 1 )
V_1007 >>= 4 ;
V_1008 = F_82 ( V_2 ) ;
V_56 -> F_233 ( V_2 , V_1008 , V_1007 ) ;
}
static void F_477 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_49 . V_50 ) {
F_478 ( V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ) ;
V_56 -> V_1009 ( V_2 , V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ,
V_2 -> V_5 . V_49 . V_44 ) ;
return;
}
if ( V_2 -> V_5 . V_597 ) {
V_56 -> V_1010 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_590 . V_50 ) {
V_56 -> V_1011 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_598 ) {
if ( V_56 -> V_1012 ( V_2 ) ) {
-- V_2 -> V_5 . V_598 ;
V_2 -> V_5 . V_597 = true ;
V_56 -> V_1010 ( V_2 ) ;
}
} else if ( F_479 ( V_2 ) ) {
if ( V_56 -> V_1013 ( V_2 ) ) {
F_235 ( V_2 , F_480 ( V_2 ) ,
false ) ;
V_56 -> V_1011 ( V_2 ) ;
}
}
}
static void F_241 ( struct V_1 * V_2 )
{
unsigned V_842 = 2 ;
if ( V_56 -> V_600 ( V_2 ) || V_2 -> V_5 . V_597 )
V_842 = 1 ;
V_2 -> V_5 . V_598 += F_481 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_598 = F_297 ( V_2 -> V_5 . V_598 , V_842 ) ;
F_25 ( V_48 , V_2 ) ;
}
static void F_482 ( struct V_82 * V_82 )
{
#ifdef F_54
int V_3 ;
struct V_1 * V_2 ;
struct V_244 * V_245 = & V_82 -> V_5 ;
F_132 ( & V_245 -> V_277 ) ;
F_483 ( V_82 ) ;
F_144 ( V_82 ) ;
F_199 (i, vcpu, kvm)
F_225 ( V_292 , & V_2 -> V_559 ) ;
F_199 (i, vcpu, kvm)
F_484 ( V_1014 , & V_2 -> V_559 ) ;
F_133 ( & V_245 -> V_277 ) ;
#endif
}
static void F_485 ( struct V_1 * V_2 )
{
T_2 V_1015 [ 4 ] ;
T_1 V_1016 [ 8 ] ;
if ( ! F_486 ( V_2 -> V_5 . V_567 ) )
return;
memset ( V_1015 , 0 , 32 ) ;
memset ( V_1016 , 0 , 32 ) ;
F_487 ( V_2 , V_1015 , V_1016 ) ;
V_56 -> V_1017 ( V_2 , V_1015 ) ;
F_488 ( V_2 , V_1016 ) ;
}
static int F_489 ( struct V_1 * V_2 )
{
int V_100 ;
bool V_1018 = ! F_79 ( V_2 -> V_82 ) &&
V_2 -> V_784 -> V_1000 ;
bool V_1019 = false ;
if ( V_2 -> V_559 ) {
if ( F_490 ( V_1020 , V_2 ) )
F_491 ( V_2 ) ;
if ( F_490 ( V_1021 , V_2 ) )
F_492 ( V_2 ) ;
if ( F_490 ( V_251 , V_2 ) )
F_482 ( V_2 -> V_82 ) ;
if ( F_490 ( V_292 , V_2 ) ) {
V_100 = F_147 ( V_2 ) ;
if ( F_76 ( V_100 ) )
goto V_94;
}
if ( F_490 ( V_1022 , V_2 ) )
F_74 ( V_2 ) ;
if ( F_490 ( V_1023 , V_2 ) )
V_56 -> V_1024 ( V_2 ) ;
if ( F_490 ( V_1025 , V_2 ) ) {
V_2 -> V_784 -> V_799 = V_1026 ;
V_100 = 0 ;
goto V_94;
}
if ( F_490 ( V_54 , V_2 ) ) {
V_2 -> V_784 -> V_799 = V_1027 ;
V_100 = 0 ;
goto V_94;
}
if ( F_490 ( V_1028 , V_2 ) ) {
V_2 -> V_1029 = 0 ;
V_56 -> V_1030 ( V_2 ) ;
}
if ( F_490 ( V_1031 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1032 = true ;
V_100 = 1 ;
goto V_94;
}
if ( F_490 ( V_421 , V_2 ) )
F_181 ( V_2 ) ;
if ( F_490 ( V_69 , V_2 ) )
F_241 ( V_2 ) ;
if ( F_490 ( V_1033 , V_2 ) )
F_493 ( V_2 ) ;
if ( F_490 ( V_1034 , V_2 ) )
F_494 ( V_2 ) ;
if ( F_490 ( V_1035 , V_2 ) )
F_485 ( V_2 ) ;
}
if ( F_490 ( V_48 , V_2 ) || V_1018 ) {
F_495 ( V_2 ) ;
if ( V_2 -> V_5 . V_971 == V_1036 ) {
V_100 = 1 ;
goto V_94;
}
F_477 ( V_2 ) ;
if ( V_2 -> V_5 . V_598 )
V_1019 =
V_56 -> V_1037 ( V_2 ) != 0 ;
else if ( F_479 ( V_2 ) || V_1018 )
V_1019 =
V_56 -> V_1038 ( V_2 ) != 0 ;
if ( F_496 ( V_2 ) ) {
if ( V_56 -> V_1039 )
V_56 -> V_1039 ( V_2 ,
F_476 ( V_2 ) ) ;
F_233 ( V_2 ) ;
F_497 ( V_2 ) ;
}
}
V_100 = F_498 ( V_2 ) ;
if ( F_76 ( V_100 ) ) {
goto V_1040;
}
F_186 () ;
V_56 -> V_1041 ( V_2 ) ;
if ( V_2 -> V_1029 )
F_384 ( V_2 ) ;
F_61 ( V_2 ) ;
V_2 -> V_280 = V_1042 ;
F_499 () ;
F_292 () ;
if ( V_2 -> V_280 == V_1043 || V_2 -> V_559
|| F_500 () || F_501 ( V_382 ) ) {
V_2 -> V_280 = V_1044 ;
F_13 () ;
F_293 () ;
F_187 () ;
V_100 = 1 ;
goto V_1040;
}
F_208 ( & V_2 -> V_82 -> V_468 , V_2 -> V_1045 ) ;
if ( V_1019 )
F_502 ( V_2 -> V_23 ) ;
F_503 () ;
if ( F_76 ( V_2 -> V_5 . V_153 ) ) {
F_504 ( 0 , 7 ) ;
F_504 ( V_2 -> V_5 . V_158 [ 0 ] , 0 ) ;
F_504 ( V_2 -> V_5 . V_158 [ 1 ] , 1 ) ;
F_504 ( V_2 -> V_5 . V_158 [ 2 ] , 2 ) ;
F_504 ( V_2 -> V_5 . V_158 [ 3 ] , 3 ) ;
}
F_505 ( V_2 -> V_252 ) ;
V_56 -> V_784 ( V_2 ) ;
if ( F_506 () )
F_507 () ;
V_2 -> V_5 . V_274 = V_56 -> V_293 ( V_2 ,
F_151 () ) ;
V_2 -> V_280 = V_1044 ;
F_13 () ;
V_56 -> V_1046 ( V_2 ) ;
++ V_2 -> V_60 . V_1047 ;
F_508 () ;
F_509 () ;
F_187 () ;
V_2 -> V_1045 = F_207 ( & V_2 -> V_82 -> V_468 ) ;
if ( F_76 ( V_1048 == V_1049 ) ) {
unsigned long V_999 = F_396 ( V_2 ) ;
F_510 ( V_1049 , ( void * ) V_999 ) ;
}
if ( F_76 ( V_2 -> V_5 . V_1050 ) )
F_25 ( V_292 , V_2 ) ;
if ( V_2 -> V_5 . V_1051 )
F_511 ( V_2 ) ;
V_100 = V_56 -> V_1052 ( V_2 ) ;
return V_100 ;
V_1040:
V_56 -> V_1040 ( V_2 ) ;
if ( F_76 ( V_2 -> V_5 . V_1051 ) )
F_511 ( V_2 ) ;
V_94:
return V_100 ;
}
static int F_512 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_82 * V_82 = V_2 -> V_82 ;
V_2 -> V_1045 = F_207 ( & V_82 -> V_468 ) ;
V_100 = F_473 ( V_2 ) ;
if ( V_100 ) {
F_208 ( & V_82 -> V_468 , V_2 -> V_1045 ) ;
return V_100 ;
}
V_100 = 1 ;
while ( V_100 > 0 ) {
if ( V_2 -> V_5 . V_971 == V_1053 &&
! V_2 -> V_5 . V_6 . V_1032 )
V_100 = F_489 ( V_2 ) ;
else {
F_208 ( & V_82 -> V_468 , V_2 -> V_1045 ) ;
F_513 ( V_2 ) ;
V_2 -> V_1045 = F_207 ( & V_82 -> V_468 ) ;
if ( F_490 ( V_1054 , V_2 ) ) {
F_495 ( V_2 ) ;
switch( V_2 -> V_5 . V_971 ) {
case V_972 :
V_2 -> V_5 . V_971 =
V_1053 ;
case V_1053 :
V_2 -> V_5 . V_6 . V_1032 = false ;
break;
case V_1036 :
break;
default:
V_100 = - V_1055 ;
break;
}
}
}
if ( V_100 <= 0 )
break;
F_484 ( V_1056 , & V_2 -> V_559 ) ;
if ( F_514 ( V_2 ) )
F_515 ( V_2 ) ;
if ( F_468 ( V_2 ) ) {
V_100 = - V_1055 ;
V_2 -> V_784 -> V_799 = V_1057 ;
++ V_2 -> V_60 . V_1058 ;
}
F_516 ( V_2 ) ;
if ( F_501 ( V_382 ) ) {
V_100 = - V_1055 ;
V_2 -> V_784 -> V_799 = V_1057 ;
++ V_2 -> V_60 . V_1059 ;
}
if ( F_500 () ) {
F_208 ( & V_82 -> V_468 , V_2 -> V_1045 ) ;
F_517 ( V_2 ) ;
V_2 -> V_1045 = F_207 ( & V_82 -> V_468 ) ;
}
}
F_208 ( & V_82 -> V_468 , V_2 -> V_1045 ) ;
F_474 ( V_2 ) ;
return V_100 ;
}
static inline int F_518 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_1045 = F_207 ( & V_2 -> V_82 -> V_468 ) ;
V_100 = F_519 ( V_2 , V_905 ) ;
F_208 ( & V_2 -> V_82 -> V_468 , V_2 -> V_1045 ) ;
if ( V_100 != V_886 )
return 0 ;
return 1 ;
}
static int V_918 ( struct V_1 * V_2 )
{
F_307 ( ! V_2 -> V_5 . V_814 . V_688 ) ;
return F_518 ( V_2 ) ;
}
static int V_920 ( struct V_1 * V_2 )
{
struct V_1001 * V_784 = V_2 -> V_784 ;
struct V_782 * V_783 ;
unsigned V_75 ;
F_307 ( ! V_2 -> V_795 ) ;
V_783 = & V_2 -> V_779 [ V_2 -> V_796 ] ;
V_75 = F_297 ( 8u , V_783 -> V_75 ) ;
if ( ! V_2 -> V_798 )
memcpy ( V_783 -> V_31 , V_784 -> V_785 . V_31 , V_75 ) ;
if ( V_783 -> V_75 <= 8 ) {
V_783 ++ ;
V_2 -> V_796 ++ ;
} else {
V_783 -> V_31 += V_75 ;
V_783 -> V_375 += V_75 ;
V_783 -> V_75 -= V_75 ;
}
if ( V_2 -> V_796 == V_2 -> V_790 ) {
V_2 -> V_795 = 0 ;
if ( V_2 -> V_798 )
return 1 ;
V_2 -> V_778 = 1 ;
return F_518 ( V_2 ) ;
}
V_784 -> V_799 = V_800 ;
V_784 -> V_785 . V_801 = V_783 -> V_375 ;
if ( V_2 -> V_798 )
memcpy ( V_784 -> V_785 . V_31 , V_783 -> V_31 , F_297 ( 8u , V_783 -> V_75 ) ) ;
V_784 -> V_785 . V_75 = F_297 ( 8u , V_783 -> V_75 ) ;
V_784 -> V_785 . V_797 = V_2 -> V_798 ;
V_2 -> V_5 . V_917 = V_920 ;
return 0 ;
}
int F_520 ( struct V_1 * V_2 , struct V_1001 * V_1001 )
{
int V_100 ;
T_17 V_1060 ;
if ( ! F_521 ( V_382 ) && F_522 ( V_382 ) )
return - V_353 ;
if ( V_2 -> V_1061 )
F_523 ( V_1062 , & V_2 -> V_1063 , & V_1060 ) ;
if ( F_76 ( V_2 -> V_5 . V_971 == V_1064 ) ) {
F_513 ( V_2 ) ;
F_495 ( V_2 ) ;
F_484 ( V_1054 , & V_2 -> V_559 ) ;
V_100 = - V_1065 ;
goto V_94;
}
if ( ! F_79 ( V_2 -> V_82 ) ) {
if ( F_78 ( V_2 , V_1001 -> V_146 ) != 0 ) {
V_100 = - V_550 ;
goto V_94;
}
}
if ( F_76 ( V_2 -> V_5 . V_917 ) ) {
int (* F_524)( struct V_1 * ) = V_2 -> V_5 . V_917 ;
V_2 -> V_5 . V_917 = NULL ;
V_100 = F_524 ( V_2 ) ;
if ( V_100 <= 0 )
goto V_94;
} else
F_112 ( V_2 -> V_5 . V_814 . V_688 || V_2 -> V_795 ) ;
V_100 = F_512 ( V_2 ) ;
V_94:
F_471 ( V_2 ) ;
if ( V_2 -> V_1061 )
F_523 ( V_1062 , & V_1060 , NULL ) ;
return V_100 ;
}
int F_525 ( struct V_1 * V_2 , struct V_1066 * V_566 )
{
if ( V_2 -> V_5 . V_922 ) {
F_526 ( & V_2 -> V_5 . V_861 ) ;
V_2 -> V_5 . V_922 = false ;
}
V_566 -> V_1067 = F_89 ( V_2 , V_169 ) ;
V_566 -> V_1068 = F_89 ( V_2 , V_984 ) ;
V_566 -> V_1069 = F_89 ( V_2 , V_168 ) ;
V_566 -> V_1070 = F_89 ( V_2 , V_170 ) ;
V_566 -> V_1071 = F_89 ( V_2 , V_986 ) ;
V_566 -> V_1072 = F_89 ( V_2 , V_985 ) ;
V_566 -> V_1073 = F_89 ( V_2 , V_1074 ) ;
V_566 -> V_1075 = F_89 ( V_2 , V_1076 ) ;
#ifdef F_54
V_566 -> V_1077 = F_89 ( V_2 , V_987 ) ;
V_566 -> V_1078 = F_89 ( V_2 , V_1079 ) ;
V_566 -> V_1080 = F_89 ( V_2 , V_1081 ) ;
V_566 -> V_1082 = F_89 ( V_2 , V_1083 ) ;
V_566 -> V_1084 = F_89 ( V_2 , V_1085 ) ;
V_566 -> V_1086 = F_89 ( V_2 , V_1087 ) ;
V_566 -> V_1088 = F_89 ( V_2 , V_1089 ) ;
V_566 -> V_1090 = F_89 ( V_2 , V_1091 ) ;
#endif
V_566 -> V_999 = F_396 ( V_2 ) ;
V_566 -> V_1092 = F_395 ( V_2 ) ;
return 0 ;
}
int F_527 ( struct V_1 * V_2 , struct V_1066 * V_566 )
{
V_2 -> V_5 . V_879 = true ;
V_2 -> V_5 . V_922 = false ;
F_91 ( V_2 , V_169 , V_566 -> V_1067 ) ;
F_91 ( V_2 , V_984 , V_566 -> V_1068 ) ;
F_91 ( V_2 , V_168 , V_566 -> V_1069 ) ;
F_91 ( V_2 , V_170 , V_566 -> V_1070 ) ;
F_91 ( V_2 , V_986 , V_566 -> V_1071 ) ;
F_91 ( V_2 , V_985 , V_566 -> V_1072 ) ;
F_91 ( V_2 , V_1074 , V_566 -> V_1073 ) ;
F_91 ( V_2 , V_1076 , V_566 -> V_1075 ) ;
#ifdef F_54
F_91 ( V_2 , V_987 , V_566 -> V_1077 ) ;
F_91 ( V_2 , V_1079 , V_566 -> V_1078 ) ;
F_91 ( V_2 , V_1081 , V_566 -> V_1080 ) ;
F_91 ( V_2 , V_1083 , V_566 -> V_1082 ) ;
F_91 ( V_2 , V_1085 , V_566 -> V_1084 ) ;
F_91 ( V_2 , V_1087 , V_566 -> V_1086 ) ;
F_91 ( V_2 , V_1089 , V_566 -> V_1088 ) ;
F_91 ( V_2 , V_1091 , V_566 -> V_1090 ) ;
#endif
F_401 ( V_2 , V_566 -> V_999 ) ;
F_366 ( V_2 , V_566 -> V_1092 ) ;
V_2 -> V_5 . V_49 . V_50 = false ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
void F_528 ( struct V_1 * V_2 , int * V_157 , int * V_847 )
{
struct V_758 V_1093 ;
F_305 ( V_2 , & V_1093 , V_1094 ) ;
* V_157 = V_1093 . V_157 ;
* V_847 = V_1093 . V_847 ;
}
int F_529 ( struct V_1 * V_2 ,
struct V_1095 * V_1096 )
{
struct V_830 V_831 ;
F_305 ( V_2 , & V_1096 -> V_1093 , V_1094 ) ;
F_305 ( V_2 , & V_1096 -> V_1097 , V_1098 ) ;
F_305 ( V_2 , & V_1096 -> V_1099 , V_1100 ) ;
F_305 ( V_2 , & V_1096 -> V_1101 , V_1102 ) ;
F_305 ( V_2 , & V_1096 -> V_1103 , V_1104 ) ;
F_305 ( V_2 , & V_1096 -> V_1105 , V_1106 ) ;
F_305 ( V_2 , & V_1096 -> V_1107 , V_1108 ) ;
F_305 ( V_2 , & V_1096 -> V_1109 , V_1110 ) ;
V_56 -> V_833 ( V_2 , & V_831 ) ;
V_1096 -> V_1111 . V_842 = V_831 . V_473 ;
V_1096 -> V_1111 . V_843 = V_831 . V_63 ;
V_56 -> V_832 ( V_2 , & V_831 ) ;
V_1096 -> V_1112 . V_842 = V_831 . V_473 ;
V_1096 -> V_1112 . V_843 = V_831 . V_63 ;
V_1096 -> V_101 = F_53 ( V_2 ) ;
V_1096 -> V_62 = V_2 -> V_5 . V_62 ;
V_1096 -> V_85 = F_51 ( V_2 ) ;
V_1096 -> V_129 = F_67 ( V_2 ) ;
V_1096 -> V_146 = F_81 ( V_2 ) ;
V_1096 -> V_111 = V_2 -> V_5 . V_111 ;
V_1096 -> V_30 = F_18 ( V_2 ) ;
memset ( V_1096 -> V_1113 , 0 , sizeof V_1096 -> V_1113 ) ;
if ( V_2 -> V_5 . V_590 . V_50 && ! V_2 -> V_5 . V_590 . V_591 )
F_225 ( V_2 -> V_5 . V_590 . V_16 ,
( unsigned long * ) V_1096 -> V_1113 ) ;
return 0 ;
}
int F_530 ( struct V_1 * V_2 ,
struct V_1114 * V_971 )
{
F_495 ( V_2 ) ;
V_971 -> V_971 = V_2 -> V_5 . V_971 ;
return 0 ;
}
int F_531 ( struct V_1 * V_2 ,
struct V_1114 * V_971 )
{
if ( ! F_244 ( V_2 ) &&
V_971 -> V_971 != V_1053 )
return - V_550 ;
if ( V_971 -> V_971 == V_1115 ) {
V_2 -> V_5 . V_971 = V_1036 ;
F_225 ( V_1116 , & V_2 -> V_5 . V_567 -> V_1117 ) ;
} else
V_2 -> V_5 . V_971 = V_971 -> V_971 ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
int F_532 ( struct V_1 * V_2 , V_810 V_1118 , int V_1119 ,
int V_1120 , bool V_52 , T_1 V_43 )
{
struct V_772 * V_773 = & V_2 -> V_5 . V_861 ;
int V_89 ;
F_394 ( V_2 ) ;
V_89 = F_533 ( V_773 , V_1118 , V_1119 , V_1120 ,
V_52 , V_43 ) ;
if ( V_89 )
return V_884 ;
F_401 ( V_2 , V_773 -> V_871 ) ;
F_366 ( V_2 , V_773 -> V_870 ) ;
F_25 ( V_48 , V_2 ) ;
return V_886 ;
}
int F_534 ( struct V_1 * V_2 ,
struct V_1095 * V_1096 )
{
int V_1121 = 0 ;
int V_1122 , V_1123 , V_326 ;
struct V_830 V_831 ;
if ( ! F_68 ( V_2 ) && ( V_1096 -> V_129 & V_119 ) )
return - V_550 ;
V_831 . V_473 = V_1096 -> V_1111 . V_842 ;
V_831 . V_63 = V_1096 -> V_1111 . V_843 ;
V_56 -> V_835 ( V_2 , & V_831 ) ;
V_831 . V_473 = V_1096 -> V_1112 . V_842 ;
V_831 . V_63 = V_1096 -> V_1112 . V_843 ;
V_56 -> V_834 ( V_2 , & V_831 ) ;
V_2 -> V_5 . V_62 = V_1096 -> V_62 ;
V_1121 |= F_51 ( V_2 ) != V_1096 -> V_85 ;
V_2 -> V_5 . V_85 = V_1096 -> V_85 ;
F_46 ( V_143 , ( V_144 * ) & V_2 -> V_5 . V_97 ) ;
F_78 ( V_2 , V_1096 -> V_146 ) ;
V_1121 |= V_2 -> V_5 . V_111 != V_1096 -> V_111 ;
V_56 -> F_95 ( V_2 , V_1096 -> V_111 ) ;
F_19 ( V_2 , V_1096 -> V_30 ) ;
V_1121 |= F_53 ( V_2 ) != V_1096 -> V_101 ;
V_56 -> V_117 ( V_2 , V_1096 -> V_101 ) ;
V_2 -> V_5 . V_101 = V_1096 -> V_101 ;
V_1121 |= F_67 ( V_2 ) != V_1096 -> V_129 ;
V_56 -> V_139 ( V_2 , V_1096 -> V_129 ) ;
if ( V_1096 -> V_129 & V_119 )
F_72 ( V_2 ) ;
V_326 = F_207 ( & V_2 -> V_82 -> V_468 ) ;
if ( ! F_48 ( V_2 ) && F_49 ( V_2 ) ) {
F_43 ( V_2 , V_2 -> V_5 . V_84 , F_51 ( V_2 ) ) ;
V_1121 = 1 ;
}
F_208 ( & V_2 -> V_82 -> V_468 , V_326 ) ;
if ( V_1121 )
F_58 ( V_2 ) ;
V_1123 = V_570 ;
V_1122 = F_535 (
( const unsigned long * ) V_1096 -> V_1113 , V_1123 ) ;
if ( V_1122 < V_1123 ) {
F_235 ( V_2 , V_1122 , false ) ;
F_110 ( L_29 , V_1122 ) ;
}
F_304 ( V_2 , & V_1096 -> V_1093 , V_1094 ) ;
F_304 ( V_2 , & V_1096 -> V_1097 , V_1098 ) ;
F_304 ( V_2 , & V_1096 -> V_1099 , V_1100 ) ;
F_304 ( V_2 , & V_1096 -> V_1101 , V_1102 ) ;
F_304 ( V_2 , & V_1096 -> V_1103 , V_1104 ) ;
F_304 ( V_2 , & V_1096 -> V_1105 , V_1106 ) ;
F_304 ( V_2 , & V_1096 -> V_1107 , V_1108 ) ;
F_304 ( V_2 , & V_1096 -> V_1109 , V_1110 ) ;
F_233 ( V_2 ) ;
if ( F_536 ( V_2 ) && F_396 ( V_2 ) == 0xfff0 &&
V_1096 -> V_1093 . V_836 == 0xf000 && V_1096 -> V_1093 . V_843 == 0xffff0000 &&
! F_397 ( V_2 ) )
V_2 -> V_5 . V_971 = V_1053 ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
int F_537 ( struct V_1 * V_2 ,
struct V_1124 * V_1125 )
{
unsigned long V_1092 ;
int V_3 , V_100 ;
if ( V_1125 -> V_695 & ( V_1126 | V_1127 ) ) {
V_100 = - V_1128 ;
if ( V_2 -> V_5 . V_49 . V_50 )
goto V_94;
if ( V_1125 -> V_695 & V_1126 )
F_26 ( V_2 , V_1129 ) ;
else
F_26 ( V_2 , V_1130 ) ;
}
V_1092 = F_395 ( V_2 ) ;
V_2 -> V_149 = V_1125 -> V_695 ;
if ( ! ( V_2 -> V_149 & V_1131 ) )
V_2 -> V_149 = 0 ;
if ( V_2 -> V_149 & V_150 ) {
for ( V_3 = 0 ; V_3 < V_1132 ; ++ V_3 )
V_2 -> V_5 . V_158 [ V_3 ] = V_1125 -> V_5 . V_1133 [ V_3 ] ;
V_2 -> V_5 . V_151 = V_1125 -> V_5 . V_1133 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1132 ; V_3 ++ )
V_2 -> V_5 . V_158 [ V_3 ] = V_2 -> V_5 . V_157 [ V_3 ] ;
}
F_83 ( V_2 ) ;
if ( V_2 -> V_149 & V_1134 )
V_2 -> V_5 . V_1135 = F_396 ( V_2 ) +
F_350 ( V_2 , V_1094 ) ;
F_366 ( V_2 , V_1092 ) ;
V_56 -> V_1136 ( V_2 ) ;
V_100 = 0 ;
V_94:
return V_100 ;
}
int F_538 ( struct V_1 * V_2 ,
struct V_1137 * V_1107 )
{
unsigned long V_1138 = V_1107 -> V_1139 ;
T_5 V_375 ;
int V_326 ;
V_326 = F_207 ( & V_2 -> V_82 -> V_468 ) ;
V_375 = F_311 ( V_2 , V_1138 , NULL ) ;
F_208 ( & V_2 -> V_82 -> V_468 , V_326 ) ;
V_1107 -> V_1140 = V_375 ;
V_1107 -> V_1141 = V_375 != V_80 ;
V_1107 -> V_1142 = 1 ;
V_1107 -> V_1143 = 0 ;
return 0 ;
}
int F_539 ( struct V_1 * V_2 , struct V_1144 * V_1145 )
{
struct V_618 * V_617 =
& V_2 -> V_5 . V_613 . V_614 -> V_617 ;
memcpy ( V_1145 -> V_1146 , V_617 -> V_1147 , 128 ) ;
V_1145 -> V_1148 = V_617 -> V_1149 ;
V_1145 -> V_1150 = V_617 -> V_1151 ;
V_1145 -> V_1152 = V_617 -> V_1153 ;
V_1145 -> V_1154 = V_617 -> V_1155 ;
V_1145 -> V_1156 = V_617 -> V_999 ;
V_1145 -> V_1157 = V_617 -> V_1158 ;
memcpy ( V_1145 -> V_1159 , V_617 -> V_1160 , sizeof V_617 -> V_1160 ) ;
return 0 ;
}
int F_540 ( struct V_1 * V_2 , struct V_1144 * V_1145 )
{
struct V_618 * V_617 =
& V_2 -> V_5 . V_613 . V_614 -> V_617 ;
memcpy ( V_617 -> V_1147 , V_1145 -> V_1146 , 128 ) ;
V_617 -> V_1149 = V_1145 -> V_1148 ;
V_617 -> V_1151 = V_1145 -> V_1150 ;
V_617 -> V_1153 = V_1145 -> V_1152 ;
V_617 -> V_1155 = V_1145 -> V_1154 ;
V_617 -> V_999 = V_1145 -> V_1156 ;
V_617 -> V_1158 = V_1145 -> V_1157 ;
memcpy ( V_617 -> V_1160 , V_1145 -> V_1159 , sizeof V_617 -> V_1160 ) ;
return 0 ;
}
int F_541 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_542 ( & V_2 -> V_5 . V_613 ) ;
if ( V_55 )
return V_55 ;
F_543 ( & V_2 -> V_5 . V_613 ) ;
V_2 -> V_5 . V_122 = V_126 ;
V_2 -> V_5 . V_101 |= V_108 ;
return 0 ;
}
static void F_544 ( struct V_1 * V_2 )
{
F_545 ( & V_2 -> V_5 . V_613 ) ;
}
void F_384 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1161 )
return;
F_63 ( V_2 ) ;
V_2 -> V_1161 = 1 ;
F_546 () ;
F_547 ( & V_2 -> V_5 . V_613 ) ;
F_548 ( 1 ) ;
}
void F_229 ( struct V_1 * V_2 )
{
F_63 ( V_2 ) ;
if ( ! V_2 -> V_1161 )
return;
V_2 -> V_1161 = 0 ;
F_549 ( & V_2 -> V_5 . V_613 ) ;
F_550 () ;
++ V_2 -> V_60 . V_1162 ;
F_25 ( V_1028 , V_2 ) ;
F_548 ( 0 ) ;
}
void F_551 ( struct V_1 * V_2 )
{
F_179 ( V_2 ) ;
F_552 ( V_2 -> V_5 . V_556 ) ;
F_544 ( V_2 ) ;
V_56 -> V_1163 ( V_2 ) ;
}
struct V_1 * F_553 ( struct V_82 * V_82 ,
unsigned int V_1164 )
{
if ( F_129 () && F_124 ( & V_82 -> V_248 ) != 0 )
F_344 ( V_812
L_30
L_31 ) ;
return V_56 -> V_1165 ( V_82 , V_1164 ) ;
}
int F_554 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_5 . V_321 . V_1166 = 1 ;
V_100 = V_557 ( V_2 ) ;
if ( V_100 )
return V_100 ;
F_555 ( V_2 ) ;
V_100 = F_556 ( V_2 ) ;
V_562 ( V_2 ) ;
return V_100 ;
}
int F_557 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_182 V_21 ;
V_100 = V_557 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_21 . V_31 = 0x0 ;
V_21 . V_124 = V_1167 ;
V_21 . V_184 = true ;
F_127 ( V_2 , & V_21 ) ;
V_562 ( V_2 ) ;
return V_100 ;
}
void F_558 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_5 . V_6 . V_376 = 0 ;
V_100 = V_557 ( V_2 ) ;
F_307 ( V_100 ) ;
F_491 ( V_2 ) ;
V_562 ( V_2 ) ;
F_544 ( V_2 ) ;
V_56 -> V_1163 ( V_2 ) ;
}
void F_555 ( struct V_1 * V_2 )
{
F_145 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_598 = 0 ;
V_2 -> V_5 . V_597 = false ;
memset ( V_2 -> V_5 . V_157 , 0 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_2 -> V_5 . V_160 = V_162 ;
V_2 -> V_5 . V_148 = V_164 ;
F_83 ( V_2 ) ;
F_25 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_6 . V_376 = 0 ;
V_2 -> V_5 . V_380 . V_376 = 0 ;
F_179 ( V_2 ) ;
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1032 = false ;
F_559 ( V_2 ) ;
memset ( V_2 -> V_5 . V_566 , 0 , sizeof( V_2 -> V_5 . V_566 ) ) ;
V_2 -> V_5 . V_97 = ~ 0 ;
V_2 -> V_5 . V_98 = ~ 0 ;
V_56 -> V_1168 ( V_2 ) ;
}
void F_560 ( struct V_1 * V_2 , unsigned int V_32 )
{
struct V_758 V_1093 ;
F_305 ( V_2 , & V_1093 , V_1094 ) ;
V_1093 . V_836 = V_32 << 8 ;
V_1093 . V_843 = V_32 << 12 ;
F_304 ( V_2 , & V_1093 , V_1094 ) ;
F_401 ( V_2 , 0 ) ;
}
int F_561 ( void * V_551 )
{
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 ;
int V_89 ;
T_2 V_1169 ;
T_2 V_1170 = 0 ;
bool V_1171 , V_1172 = false ;
F_14 () ;
V_89 = V_56 -> V_1173 ( V_551 ) ;
if ( V_89 != 0 )
return V_89 ;
V_1169 = F_151 () ;
V_1171 = ! F_129 () ;
F_425 (kvm, &vm_list, vm_list) {
F_199 (i, vcpu, kvm) {
if ( ! V_1171 && V_2 -> V_23 == F_8 () )
F_225 ( V_292 , & V_2 -> V_559 ) ;
if ( V_1171 && V_2 -> V_5 . V_561 > V_1169 ) {
V_1172 = true ;
if ( V_2 -> V_5 . V_561 > V_1170 )
V_1170 = V_2 -> V_5 . V_561 ;
}
}
}
if ( V_1172 ) {
T_2 V_1174 = V_1170 - V_1169 ;
F_425 (kvm, &vm_list, vm_list) {
F_199 (i, vcpu, kvm) {
V_2 -> V_5 . V_558 += V_1174 ;
V_2 -> V_5 . V_561 = V_1169 ;
F_225 ( V_251 ,
& V_2 -> V_559 ) ;
}
V_82 -> V_5 . V_263 = 0 ;
V_82 -> V_5 . V_264 = 0 ;
}
}
return 0 ;
}
void F_562 ( void * V_551 )
{
V_56 -> V_1175 ( V_551 ) ;
F_17 ( V_551 ) ;
}
int F_563 ( void )
{
return V_56 -> V_1176 () ;
}
void F_564 ( void )
{
V_56 -> V_1177 () ;
}
void F_565 ( void * V_1178 )
{
V_56 -> V_1179 ( V_1178 ) ;
}
bool F_566 ( struct V_1 * V_2 )
{
return F_79 ( V_2 -> V_82 ) == ( V_2 -> V_5 . V_567 != NULL ) ;
}
int F_567 ( struct V_1 * V_2 )
{
struct V_351 * V_351 ;
struct V_82 * V_82 ;
int V_100 ;
F_307 ( V_2 -> V_82 == NULL ) ;
V_82 = V_2 -> V_82 ;
V_2 -> V_5 . V_861 . V_787 = & V_1180 ;
if ( ! F_79 ( V_82 ) || F_536 ( V_2 ) )
V_2 -> V_5 . V_971 = V_1053 ;
else
V_2 -> V_5 . V_971 = V_1064 ;
V_351 = F_568 ( V_632 | V_1181 ) ;
if ( ! V_351 ) {
V_100 = - V_353 ;
goto V_1182;
}
V_2 -> V_5 . V_817 = F_569 ( V_351 ) ;
F_121 ( V_2 , V_939 ) ;
V_100 = F_570 ( V_2 ) ;
if ( V_100 < 0 )
goto V_1183;
if ( F_79 ( V_82 ) ) {
V_100 = F_571 ( V_2 ) ;
if ( V_100 < 0 )
goto V_1184;
} else
F_572 ( & V_1185 ) ;
V_2 -> V_5 . V_340 = F_253 ( V_423 * sizeof( T_2 ) * 4 ,
V_632 ) ;
if ( ! V_2 -> V_5 . V_340 ) {
V_100 = - V_353 ;
goto V_1186;
}
V_2 -> V_5 . V_332 = V_423 ;
if ( ! F_573 ( & V_2 -> V_5 . V_556 , V_632 ) ) {
V_100 = - V_353 ;
goto V_1187;
}
V_100 = F_541 ( V_2 ) ;
if ( V_100 )
goto V_1188;
V_2 -> V_5 . V_255 = 0x0 ;
V_2 -> V_5 . V_295 = false ;
F_1 ( V_2 ) ;
F_574 ( V_2 ) ;
return 0 ;
V_1188:
F_552 ( V_2 -> V_5 . V_556 ) ;
V_1187:
F_165 ( V_2 -> V_5 . V_340 ) ;
V_1186:
F_575 ( V_2 ) ;
V_1184:
F_576 ( V_2 ) ;
V_1183:
F_577 ( ( unsigned long ) V_2 -> V_5 . V_817 ) ;
V_1182:
return V_100 ;
}
void F_578 ( struct V_1 * V_2 )
{
int V_326 ;
F_579 ( V_2 ) ;
F_165 ( V_2 -> V_5 . V_340 ) ;
F_575 ( V_2 ) ;
V_326 = F_207 ( & V_2 -> V_82 -> V_468 ) ;
F_576 ( V_2 ) ;
F_208 ( & V_2 -> V_82 -> V_468 , V_326 ) ;
F_577 ( ( unsigned long ) V_2 -> V_5 . V_817 ) ;
if ( ! F_79 ( V_2 -> V_82 ) )
F_580 ( & V_1185 ) ;
}
int F_581 ( struct V_82 * V_82 , unsigned long type )
{
if ( type )
return - V_550 ;
F_582 ( & V_82 -> V_5 . V_1189 ) ;
F_582 ( & V_82 -> V_5 . V_1190 ) ;
F_225 ( V_710 , & V_82 -> V_5 . V_1191 ) ;
F_225 ( V_1192 ,
& V_82 -> V_5 . V_1191 ) ;
F_583 ( & V_82 -> V_5 . V_261 ) ;
F_584 ( & V_82 -> V_5 . V_1193 ) ;
F_585 ( & V_82 -> V_5 . V_277 ) ;
F_144 ( V_82 ) ;
return 0 ;
}
static void F_586 ( struct V_1 * V_2 )
{
int V_100 ;
V_100 = V_557 ( V_2 ) ;
F_307 ( V_100 ) ;
F_491 ( V_2 ) ;
V_562 ( V_2 ) ;
}
static void F_587 ( struct V_82 * V_82 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_199 (i, vcpu, kvm) {
F_57 ( V_2 ) ;
F_586 ( V_2 ) ;
}
F_199 (i, vcpu, kvm)
F_551 ( V_2 ) ;
F_191 ( & V_82 -> V_438 ) ;
for ( V_3 = 0 ; V_3 < F_124 ( & V_82 -> V_248 ) ; V_3 ++ )
V_82 -> V_1194 [ V_3 ] = NULL ;
F_145 ( & V_82 -> V_248 , 0 ) ;
F_192 ( & V_82 -> V_438 ) ;
}
void F_588 ( struct V_82 * V_82 )
{
F_589 ( V_82 ) ;
F_590 ( V_82 ) ;
}
void F_591 ( struct V_82 * V_82 )
{
if ( V_382 -> V_1195 == V_82 -> V_1195 ) {
struct V_1196 V_1197 ;
memset ( & V_1197 , 0 , sizeof( V_1197 ) ) ;
V_1197 . V_10 = V_1198 ;
F_592 ( V_82 , & V_1197 ) ;
V_1197 . V_10 = V_1199 ;
F_592 ( V_82 , & V_1197 ) ;
V_1197 . V_10 = V_1200 ;
F_592 ( V_82 , & V_1197 ) ;
}
F_593 ( V_82 ) ;
F_165 ( V_82 -> V_5 . V_722 ) ;
F_165 ( V_82 -> V_5 . V_1201 ) ;
F_587 ( V_82 ) ;
if ( V_82 -> V_5 . V_1202 )
F_594 ( V_82 -> V_5 . V_1202 ) ;
if ( V_82 -> V_5 . V_1203 )
F_594 ( V_82 -> V_5 . V_1203 ) ;
F_165 ( F_595 ( V_82 -> V_5 . V_1204 , 1 ) ) ;
}
void F_596 ( struct V_698 * free ,
struct V_698 * V_1205 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1206 ; ++ V_3 ) {
if ( ! V_1205 || free -> V_5 . V_1207 [ V_3 ] != V_1205 -> V_5 . V_1207 [ V_3 ] ) {
F_597 ( free -> V_5 . V_1207 [ V_3 ] ) ;
free -> V_5 . V_1207 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1205 || free -> V_5 . V_1208 [ V_3 - 1 ] !=
V_1205 -> V_5 . V_1208 [ V_3 - 1 ] ) {
F_597 ( free -> V_5 . V_1208 [ V_3 - 1 ] ) ;
free -> V_5 . V_1208 [ V_3 - 1 ] = NULL ;
}
}
}
int F_598 ( struct V_698 * V_10 , unsigned long V_1209 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1206 ; ++ V_3 ) {
unsigned long V_1210 ;
int V_1211 ;
int V_711 = V_3 + 1 ;
V_1211 = F_599 ( V_10 -> V_1212 + V_1209 - 1 ,
V_10 -> V_1212 , V_711 ) + 1 ;
V_10 -> V_5 . V_1207 [ V_3 ] =
F_600 ( V_1211 * sizeof( * V_10 -> V_5 . V_1207 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1207 [ V_3 ] )
goto V_354;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1208 [ V_3 - 1 ] = F_600 ( V_1211 *
sizeof( * V_10 -> V_5 . V_1208 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1208 [ V_3 - 1 ] )
goto V_354;
if ( V_10 -> V_1212 & ( F_601 ( V_711 ) - 1 ) )
V_10 -> V_5 . V_1208 [ V_3 - 1 ] [ 0 ] . V_1213 = 1 ;
if ( ( V_10 -> V_1212 + V_1209 ) & ( F_601 ( V_711 ) - 1 ) )
V_10 -> V_5 . V_1208 [ V_3 - 1 ] [ V_1211 - 1 ] . V_1213 = 1 ;
V_1210 = V_10 -> V_1214 >> V_87 ;
if ( ( V_10 -> V_1212 ^ V_1210 ) & ( F_601 ( V_711 ) - 1 ) ||
! F_602 () ) {
unsigned long V_752 ;
for ( V_752 = 0 ; V_752 < V_1211 ; ++ V_752 )
V_10 -> V_5 . V_1208 [ V_3 - 1 ] [ V_752 ] . V_1213 = 1 ;
}
}
return 0 ;
V_354:
for ( V_3 = 0 ; V_3 < V_1206 ; ++ V_3 ) {
F_597 ( V_10 -> V_5 . V_1207 [ V_3 ] ) ;
V_10 -> V_5 . V_1207 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_597 ( V_10 -> V_5 . V_1208 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1208 [ V_3 - 1 ] = NULL ;
}
return - V_353 ;
}
int F_603 ( struct V_82 * V_82 ,
struct V_698 * V_699 ,
struct V_1196 * V_1197 ,
enum V_1215 V_1216 )
{
if ( ( V_699 -> V_1164 >= V_519 ) && ( V_1216 == V_1217 ) ) {
unsigned long V_1214 ;
V_1214 = F_604 ( NULL , 0 , V_699 -> V_1209 * V_88 ,
V_1218 | V_1219 ,
V_1220 | V_1221 , 0 ) ;
if ( F_163 ( ( void * ) V_1214 ) )
return F_164 ( ( void * ) V_1214 ) ;
V_699 -> V_1214 = V_1214 ;
}
return 0 ;
}
void F_605 ( struct V_82 * V_82 ,
struct V_1196 * V_1197 ,
const struct V_698 * V_805 ,
enum V_1215 V_1216 )
{
int V_1222 = 0 ;
if ( ( V_1197 -> V_10 >= V_519 ) && ( V_1216 == V_1223 ) ) {
int V_89 ;
V_89 = F_606 ( V_805 -> V_1214 ,
V_805 -> V_1209 * V_88 ) ;
if ( V_89 < 0 )
F_10 ( V_812
L_32
L_33 ) ;
}
if ( ! V_82 -> V_5 . V_671 )
V_1222 = F_607 ( V_82 ) ;
if ( V_1222 )
F_262 ( V_82 , V_1222 ) ;
if ( ( V_1216 != V_1223 ) && ( V_1197 -> V_258 & V_1224 ) )
F_608 ( V_82 , V_1197 -> V_10 ) ;
if ( ( V_1216 == V_1217 ) || ( V_1216 == V_1225 ) ) {
F_609 ( V_82 ) ;
F_610 ( V_82 ) ;
}
}
void F_611 ( struct V_82 * V_82 )
{
F_467 ( V_82 ) ;
F_610 ( V_82 ) ;
}
void F_612 ( struct V_82 * V_82 ,
struct V_698 * V_10 )
{
F_611 ( V_82 ) ;
}
int F_613 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_971 == V_1053 &&
! V_2 -> V_5 . V_6 . V_1032 )
|| ! F_614 ( & V_2 -> V_1226 . V_1227 )
|| F_615 ( V_2 )
|| F_124 ( & V_2 -> V_5 . V_68 ) ||
( F_470 ( V_2 ) &&
F_469 ( V_2 ) ) ;
}
int F_616 ( struct V_1 * V_2 )
{
return F_617 ( V_2 ) == V_1042 ;
}
int F_470 ( struct V_1 * V_2 )
{
return V_56 -> V_1013 ( V_2 ) ;
}
bool F_618 ( struct V_1 * V_2 , unsigned long V_1228 )
{
unsigned long V_1229 = F_396 ( V_2 ) +
F_350 ( V_2 , V_1094 ) ;
return V_1229 == V_1228 ;
}
unsigned long F_395 ( struct V_1 * V_2 )
{
unsigned long V_1092 ;
V_1092 = V_56 -> V_1230 ( V_2 ) ;
if ( V_2 -> V_149 & V_1134 )
V_1092 &= ~ V_1231 ;
return V_1092 ;
}
void F_366 ( struct V_1 * V_2 , unsigned long V_1092 )
{
if ( V_2 -> V_149 & V_1134 &&
F_618 ( V_2 , V_2 -> V_5 . V_1135 ) )
V_1092 |= V_1231 ;
V_56 -> V_1232 ( V_2 , V_1092 ) ;
F_25 ( V_48 , V_2 ) ;
}
void F_619 ( struct V_1 * V_2 , struct V_1233 * V_954 )
{
int V_100 ;
if ( ( V_2 -> V_5 . V_67 . V_897 != V_954 -> V_5 . V_897 ) ||
F_337 ( V_954 -> V_351 ) )
return;
V_100 = F_498 ( V_2 ) ;
if ( F_76 ( V_100 ) )
return;
if ( ! V_2 -> V_5 . V_67 . V_897 &&
V_954 -> V_5 . V_85 != V_2 -> V_5 . V_67 . V_1234 ( V_2 ) )
return;
V_2 -> V_5 . V_67 . V_1235 ( V_2 , V_954 -> V_765 , 0 , true ) ;
}
static inline T_1 F_620 ( T_4 V_83 )
{
return F_621 ( V_83 & 0xffffffff , F_622 ( V_4 ) ) ;
}
static inline T_1 F_623 ( T_1 V_1236 )
{
return ( V_1236 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_624 ( struct V_1 * V_2 , T_4 V_83 )
{
T_1 V_1236 = F_620 ( V_83 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1236 ] != ~ 0 )
V_1236 = F_623 ( V_1236 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1236 ] = V_83 ;
}
static T_1 F_625 ( struct V_1 * V_2 , T_4 V_83 )
{
int V_3 ;
T_1 V_1236 = F_620 ( V_83 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1236 ] != V_83 &&
V_2 -> V_5 . V_6 . V_7 [ V_1236 ] != ~ 0 ) ; V_3 ++ )
V_1236 = F_623 ( V_1236 ) ;
return V_1236 ;
}
bool F_626 ( struct V_1 * V_2 , T_4 V_83 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_625 ( V_2 , V_83 ) ] == V_83 ;
}
static void F_627 ( struct V_1 * V_2 , T_4 V_83 )
{
T_1 V_3 , V_752 , V_1237 ;
V_3 = V_752 = F_625 ( V_2 , V_83 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_752 = F_623 ( V_752 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_752 ] == ~ 0 )
return;
V_1237 = F_620 ( V_2 -> V_5 . V_6 . V_7 [ V_752 ] ) ;
} while ( ( V_3 <= V_752 ) ? ( V_3 < V_1237 && V_1237 <= V_752 ) : ( V_3 < V_1237 || V_1237 <= V_752 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_752 ] ;
V_3 = V_752 ;
}
}
static int F_628 ( struct V_1 * V_2 , T_1 V_156 )
{
return F_154 ( V_2 -> V_82 , & V_2 -> V_5 . V_6 . V_31 , & V_156 ,
sizeof( V_156 ) ) ;
}
void F_629 ( struct V_1 * V_2 ,
struct V_1233 * V_954 )
{
struct V_58 V_59 ;
F_630 ( V_954 -> V_5 . V_1238 , V_954 -> V_765 ) ;
F_624 ( V_2 , V_954 -> V_5 . V_83 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_376 & V_377 ) ||
( V_2 -> V_5 . V_6 . V_378 &&
V_56 -> V_71 ( V_2 ) == 0 ) )
F_25 ( V_1031 , V_2 ) ;
else if ( ! F_628 ( V_2 , V_1239 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_862 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_954 -> V_5 . V_1238 ;
F_30 ( V_2 , & V_59 ) ;
}
}
void F_631 ( struct V_1 * V_2 ,
struct V_1233 * V_954 )
{
struct V_58 V_59 ;
F_632 ( V_954 -> V_5 . V_1238 , V_954 -> V_765 ) ;
if ( F_337 ( V_954 -> V_351 ) )
V_954 -> V_5 . V_1238 = ~ 0 ;
else
F_627 ( V_2 , V_954 -> V_5 . V_83 ) ;
if ( ( V_2 -> V_5 . V_6 . V_376 & V_377 ) &&
! F_628 ( V_2 , V_1240 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_862 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_954 -> V_5 . V_1238 ;
F_30 ( V_2 , & V_59 ) ;
}
V_2 -> V_5 . V_6 . V_1032 = false ;
V_2 -> V_5 . V_971 = V_1053 ;
}
bool F_633 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_376 & V_377 ) )
return true ;
else
return ! F_472 ( V_2 ) &&
V_56 -> V_1013 ( V_2 ) ;
}
