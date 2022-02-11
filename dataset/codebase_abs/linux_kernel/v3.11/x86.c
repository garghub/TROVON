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
F_120 ( V_257 , 1000 ) ;
V_259 -= V_257 ;
if ( V_259 < 0 )
V_259 = - V_259 ;
if ( V_264 )
V_259 = V_266 ;
} else
V_259 = V_266 ;
if ( V_259 < V_266 &&
V_2 -> V_5 . V_234 == V_82 -> V_5 . V_267 ) {
if ( ! F_129 () ) {
V_74 = V_82 -> V_5 . V_268 ;
F_110 ( L_4 , V_31 ) ;
} else {
T_2 V_269 = F_117 ( V_2 , V_257 ) ;
V_31 += V_269 ;
V_74 = V_56 -> V_262 ( V_2 , V_31 ) ;
F_110 ( L_5 , V_269 ) ;
}
V_260 = true ;
} else {
V_82 -> V_5 . V_270 ++ ;
V_82 -> V_5 . V_271 = V_256 ;
V_82 -> V_5 . V_272 = V_31 ;
V_82 -> V_5 . V_268 = V_74 ;
V_260 = false ;
F_110 ( L_6 ,
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
if ( F_130 ( V_2 ) && ! V_21 -> V_184 )
F_126 ( V_2 , V_74 ) ;
V_56 -> V_277 ( V_2 , V_74 ) ;
F_131 ( & V_82 -> V_5 . V_261 , V_258 ) ;
F_132 ( & V_82 -> V_5 . V_278 ) ;
if ( V_260 )
V_82 -> V_5 . V_247 ++ ;
else
V_82 -> V_5 . V_247 = 0 ;
F_123 ( V_2 ) ;
F_133 ( & V_82 -> V_5 . V_278 ) ;
}
static T_12 F_134 ( void )
{
T_12 V_89 ;
T_2 V_279 ;
F_135 () ;
V_89 = ( T_12 ) F_136 () ;
V_279 = V_187 . clock . V_192 ;
if ( F_137 ( V_89 >= V_279 ) )
return V_89 ;
asm volatile ("");
return V_279 ;
}
static inline T_2 F_138 ( T_12 * V_280 )
{
long V_229 ;
struct V_187 * V_246 = & V_187 ;
* V_280 = F_134 () ;
V_229 = ( * V_280 - V_246 -> clock . V_192 ) & V_246 -> clock . V_27 ;
return V_229 * V_246 -> clock . V_193 ;
}
static int F_139 ( struct V_207 * V_210 , T_12 * V_280 )
{
unsigned long V_189 ;
T_2 V_256 ;
int V_281 ;
struct V_187 * V_246 = & V_187 ;
V_210 -> V_201 = 0 ;
do {
V_189 = F_140 ( & V_246 -> V_189 ) ;
V_281 = V_246 -> clock . V_190 ;
V_210 -> V_198 = V_246 -> V_195 ;
V_256 = V_246 -> V_199 ;
V_256 += F_138 ( V_280 ) ;
V_256 >>= V_246 -> clock . V_194 ;
} while ( F_76 ( F_141 ( & V_246 -> V_189 , V_189 ) ) );
F_142 ( V_210 , V_256 ) ;
return V_281 ;
}
static bool F_143 ( T_11 * V_238 , T_12 * V_280 )
{
struct V_207 V_210 ;
if ( V_187 . clock . V_190 != V_249 )
return false ;
if ( F_139 ( & V_210 , V_280 ) != V_249 )
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
bool V_282 , V_242 ;
V_242 = ( V_245 -> V_247 + 1 ==
F_124 ( & V_82 -> V_248 ) ) ;
V_282 = F_143 (
& V_245 -> V_283 ,
& V_245 -> V_284 ) ;
V_245 -> V_250 = V_282 & V_242 ;
if ( V_245 -> V_250 )
F_145 ( & V_285 , 1 ) ;
V_190 = V_187 . clock . V_190 ;
F_146 ( V_245 -> V_250 , V_190 ,
V_242 ) ;
#endif
}
static int F_147 ( struct V_1 * V_229 )
{
unsigned long V_258 , V_230 ;
struct V_286 * V_2 = & V_229 -> V_5 ;
struct V_244 * V_245 = & V_229 -> V_82 -> V_5 ;
T_11 V_238 , V_287 ;
T_2 V_274 , V_288 ;
struct V_289 V_290 ;
T_13 V_291 ;
bool V_250 ;
V_238 = 0 ;
V_288 = 0 ;
F_132 ( & V_245 -> V_278 ) ;
V_250 = V_245 -> V_250 ;
if ( V_250 ) {
V_288 = V_245 -> V_284 ;
V_238 = V_245 -> V_283 ;
}
F_133 ( & V_245 -> V_278 ) ;
F_148 ( V_258 ) ;
V_230 = F_149 ( V_292 ) ;
if ( F_76 ( V_230 == 0 ) ) {
F_150 ( V_258 ) ;
F_25 ( V_293 , V_229 ) ;
return 1 ;
}
if ( ! V_250 ) {
V_288 = F_151 () ;
V_238 = F_111 () ;
}
V_274 = V_56 -> V_294 ( V_229 , V_288 ) ;
if ( V_2 -> V_295 ) {
T_2 V_239 = F_122 ( V_229 , V_238 ) ;
if ( V_239 > V_274 ) {
F_152 ( V_229 , V_239 - V_274 ) ;
V_274 = V_239 ;
}
}
F_150 ( V_258 ) ;
if ( ! V_2 -> V_296 )
return 0 ;
V_287 = 0 ;
if ( V_2 -> V_273 . V_274 ) {
V_287 = V_2 -> V_275 -
V_2 -> V_273 . V_274 ;
V_287 = F_118 ( V_287 ,
V_2 -> V_273 . V_297 ,
V_2 -> V_273 . V_298 ) ;
V_287 += V_2 -> V_299 ;
}
if ( F_76 ( V_2 -> V_300 != V_230 ) ) {
F_109 ( V_202 / 1000 , V_230 ,
& V_2 -> V_273 . V_298 ,
& V_2 -> V_273 . V_297 ) ;
V_2 -> V_300 = V_230 ;
}
if ( ! V_250 ) {
if ( V_287 > V_238 )
V_238 = V_287 ;
}
V_2 -> V_273 . V_274 = V_274 ;
V_2 -> V_273 . V_301 = V_238 + V_229 -> V_82 -> V_5 . V_209 ;
V_2 -> V_299 = V_238 ;
V_2 -> V_275 = V_274 ;
V_2 -> V_273 . V_204 += 2 ;
if ( F_76 ( F_153 ( V_229 -> V_82 , & V_2 -> V_302 ,
& V_290 , sizeof( V_290 ) ) ) )
return 0 ;
V_291 = ( V_290 . V_258 & V_303 ) ;
if ( V_2 -> V_304 ) {
V_291 |= V_303 ;
V_2 -> V_304 = false ;
}
if ( V_250 )
V_291 |= V_305 ;
V_2 -> V_273 . V_258 = V_291 ;
F_154 ( V_229 -> V_82 , & V_2 -> V_302 ,
& V_2 -> V_273 ,
sizeof( V_2 -> V_273 ) ) ;
return 0 ;
}
static void F_155 ( struct V_1 * V_229 )
{
int V_3 ;
struct V_82 * V_82 = V_229 -> V_82 ;
struct V_1 * V_2 ;
F_156 (i, vcpu, kvm) {
F_157 ( V_293 , & V_2 -> V_306 ) ;
F_158 ( V_2 ) ;
}
}
static bool F_159 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_307 - 1 :
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
case V_319 :
case V_320 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_160 ( unsigned V_321 )
{
return V_321 < 8 && ( 1 << V_321 ) & 0xf3 ;
}
static bool F_161 ( unsigned V_321 )
{
return V_321 < 8 && ( 1 << V_321 ) & 0x73 ;
}
static bool F_162 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
int V_3 ;
if ( ! F_159 ( V_21 ) )
return false ;
if ( V_21 == V_320 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_160 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_319 ) {
if ( V_31 & ~ 0xcff )
return false ;
return F_161 ( V_31 & 0xff ) ;
} else if ( V_21 >= V_308 && V_21 <= V_318 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_161 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_161 ( V_31 & 0xff ) ;
}
static int F_163 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 * V_322 = ( T_2 * ) & V_2 -> V_5 . V_323 . V_324 ;
if ( ! F_162 ( V_2 , V_21 , V_31 ) )
return 1 ;
if ( V_21 == V_319 ) {
V_2 -> V_5 . V_323 . V_325 = V_31 ;
V_2 -> V_5 . V_323 . V_326 = ( V_31 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_308 )
V_322 [ 0 ] = V_31 ;
else if ( V_21 == V_309 || V_21 == V_310 )
V_322 [ 1 + V_21 - V_309 ] = V_31 ;
else if ( V_21 >= V_311 && V_21 <= V_318 )
V_322 [ 3 + V_21 - V_311 ] = V_31 ;
else if ( V_21 == V_320 )
V_2 -> V_5 . V_327 = V_31 ;
else {
int V_328 , V_329 ;
T_2 * V_330 ;
V_328 = ( V_21 - 0x200 ) / 2 ;
V_329 = V_21 - 0x200 - 2 * V_328 ;
if ( ! V_329 )
V_330 =
( T_2 * ) & V_2 -> V_5 . V_323 . V_331 [ V_328 ] . V_332 ;
else
V_330 =
( T_2 * ) & V_2 -> V_5 . V_323 . V_331 [ V_328 ] . V_333 ;
* V_330 = V_31 ;
}
F_58 ( V_2 ) ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 V_334 = V_2 -> V_5 . V_334 ;
unsigned V_335 = V_334 & 0xff ;
switch ( V_21 ) {
case V_336 :
V_2 -> V_5 . V_337 = V_31 ;
break;
case V_338 :
if ( ! ( V_334 & V_339 ) )
return 1 ;
if ( V_31 != 0 && V_31 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_340 = V_31 ;
break;
default:
if ( V_21 >= V_341 &&
V_21 < V_341 + 4 * V_335 ) {
T_1 V_74 = V_21 - V_341 ;
if ( ( V_74 & 0x3 ) == 0 &&
V_31 != 0 && ( V_31 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_342 [ V_74 ] = V_31 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_165 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
int V_343 = F_48 ( V_2 ) ;
T_13 * V_344 = V_343 ? ( T_13 * ) ( long ) V_82 -> V_5 . F_165 . V_345
: ( T_13 * ) ( long ) V_82 -> V_5 . F_165 . V_346 ;
T_13 V_347 = V_343 ? V_82 -> V_5 . F_165 . V_348
: V_82 -> V_5 . F_165 . V_349 ;
T_1 V_350 = V_31 & ~ V_351 ;
T_2 V_352 = V_31 & V_351 ;
T_13 * V_353 ;
int V_100 ;
V_100 = - V_354 ;
if ( V_350 >= V_347 )
goto V_94;
V_100 = - V_355 ;
V_353 = F_166 ( V_344 + ( V_350 * V_88 ) , V_88 ) ;
if ( F_167 ( V_353 ) ) {
V_100 = F_168 ( V_353 ) ;
goto V_94;
}
if ( F_104 ( V_82 , V_352 , V_353 , V_88 ) )
goto V_356;
V_100 = 0 ;
V_356:
F_169 ( V_353 ) ;
V_94:
return V_100 ;
}
static bool F_170 ( struct V_82 * V_82 )
{
return V_82 -> V_5 . V_357 & V_358 ;
}
static bool F_171 ( T_1 V_21 )
{
bool V_100 = false ;
switch ( V_21 ) {
case V_359 :
case V_360 :
V_100 = true ;
break;
}
return V_100 ;
}
static int F_172 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
switch ( V_21 ) {
case V_359 :
V_82 -> V_5 . V_361 = V_31 ;
if ( ! V_82 -> V_5 . V_361 )
V_82 -> V_5 . V_357 &= ~ V_358 ;
break;
case V_360 : {
T_2 V_83 ;
unsigned long V_362 ;
T_13 V_363 [ 4 ] ;
if ( ! V_82 -> V_5 . V_361 )
break;
if ( ! ( V_31 & V_358 ) ) {
V_82 -> V_5 . V_357 = V_31 ;
break;
}
V_83 = V_31 >> V_364 ;
V_362 = F_173 ( V_82 , V_83 ) ;
if ( F_174 ( V_362 ) )
return 1 ;
V_56 -> V_365 ( V_2 , V_363 ) ;
( ( unsigned char * ) V_363 ) [ 3 ] = 0xc3 ;
if ( F_175 ( ( void V_366 * ) V_362 , V_363 , 4 ) )
return 1 ;
V_82 -> V_5 . V_357 = V_31 ;
break;
}
default:
F_176 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_367 : {
unsigned long V_362 ;
if ( ! ( V_31 & V_368 ) ) {
V_2 -> V_5 . V_369 = V_31 ;
break;
}
V_362 = F_173 ( V_2 -> V_82 , V_31 >>
V_370 ) ;
if ( F_174 ( V_362 ) )
return 1 ;
if ( F_178 ( ( void V_366 * ) V_362 , V_88 ) )
return 1 ;
V_2 -> V_5 . V_369 = V_31 ;
break;
}
case V_371 :
return F_179 ( V_2 , V_372 , V_31 ) ;
case V_373 :
return F_179 ( V_2 , V_374 , V_31 ) ;
case V_375 :
return F_179 ( V_2 , V_376 , V_31 ) ;
default:
F_176 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_180 ( struct V_1 * V_2 , T_2 V_31 )
{
T_5 V_377 = V_31 & ~ 0x3f ;
if ( V_31 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_378 = V_31 ;
if ( ! ( V_31 & V_379 ) ) {
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_181 ( V_2 -> V_82 , & V_2 -> V_5 . V_6 . V_31 , V_377 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_380 = ! ( V_31 & V_381 ) ;
F_182 ( V_2 ) ;
return 0 ;
}
static void F_183 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_296 = false ;
}
static void F_184 ( struct V_1 * V_2 )
{
T_2 V_269 ;
if ( ! ( V_2 -> V_5 . V_382 . V_378 & V_383 ) )
return;
V_269 = V_384 -> V_385 . V_386 - V_2 -> V_5 . V_382 . V_387 ;
V_2 -> V_5 . V_382 . V_387 = V_384 -> V_385 . V_386 ;
V_2 -> V_5 . V_382 . V_388 = V_269 ;
}
static void F_185 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_382 . V_378 & V_383 ) )
return;
if ( F_76 ( F_153 ( V_2 -> V_82 , & V_2 -> V_5 . V_382 . V_389 ,
& V_2 -> V_5 . V_382 . V_390 , sizeof( struct V_391 ) ) ) )
return;
V_2 -> V_5 . V_382 . V_390 . V_390 += V_2 -> V_5 . V_382 . V_388 ;
V_2 -> V_5 . V_382 . V_390 . V_204 += 2 ;
V_2 -> V_5 . V_382 . V_388 = 0 ;
F_154 ( V_2 -> V_82 , & V_2 -> V_5 . V_382 . V_389 ,
& V_2 -> V_5 . V_382 . V_390 , sizeof( struct V_391 ) ) ;
}
int F_186 ( struct V_1 * V_2 , struct V_182 * V_392 )
{
bool V_393 = false ;
T_1 V_21 = V_392 -> V_124 ;
T_2 V_31 = V_392 -> V_31 ;
switch ( V_21 ) {
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
break;
case V_400 :
return F_95 ( V_2 , V_31 ) ;
case V_401 :
V_31 &= ~ ( T_2 ) 0x40 ;
V_31 &= ~ ( T_2 ) 0x100 ;
V_31 &= ~ ( T_2 ) 0x8 ;
if ( V_31 != 0 ) {
F_176 ( V_2 , L_9 ,
V_31 ) ;
return 1 ;
}
break;
case V_402 :
if ( V_31 != 0 ) {
F_176 ( V_2 , L_10
L_11 , V_31 ) ;
return 1 ;
}
break;
case V_403 :
if ( ! V_31 ) {
break;
} else if ( V_31 & ~ ( V_404 | V_405 ) ) {
return 1 ;
}
F_176 ( V_2 , L_12 ,
V_224 , V_31 ) ;
break;
case 0x200 ... 0x2ff :
return F_163 ( V_2 , V_21 , V_31 ) ;
case V_406 :
F_19 ( V_2 , V_31 ) ;
break;
case V_407 ... V_407 + 0x3ff :
return F_187 ( V_2 , V_21 , V_31 ) ;
case V_408 :
F_188 ( V_2 , V_31 ) ;
break;
case V_409 :
if ( F_130 ( V_2 ) ) {
if ( ! V_392 -> V_184 ) {
T_2 V_410 = V_31 - V_2 -> V_5 . V_255 ;
V_56 -> V_411 ( V_2 , V_410 , true ) ;
}
V_2 -> V_5 . V_255 = V_31 ;
}
break;
case V_412 :
V_2 -> V_5 . V_413 = V_31 ;
break;
case V_414 :
case V_415 :
V_2 -> V_82 -> V_5 . V_203 = V_31 ;
F_102 ( V_2 -> V_82 , V_31 ) ;
break;
case V_416 :
case V_417 : {
T_2 V_418 ;
F_183 ( V_2 ) ;
V_2 -> V_5 . time = V_31 ;
F_25 ( V_419 , V_2 ) ;
if ( ! ( V_31 & 1 ) )
break;
V_418 = V_31 & ~ ( V_351 | 1 ) ;
if ( F_181 ( V_2 -> V_82 ,
& V_2 -> V_5 . V_302 , V_31 & ~ 1ULL ,
sizeof( struct V_289 ) ) )
V_2 -> V_5 . V_296 = false ;
else
V_2 -> V_5 . V_296 = true ;
break;
}
case V_420 :
if ( F_180 ( V_2 , V_31 ) )
return 1 ;
break;
case V_421 :
if ( F_76 ( ! F_189 () ) )
return 1 ;
if ( V_31 & V_422 )
return 1 ;
if ( F_181 ( V_2 -> V_82 , & V_2 -> V_5 . V_382 . V_389 ,
V_31 & V_423 ,
sizeof( struct V_391 ) ) )
return 1 ;
V_2 -> V_5 . V_382 . V_378 = V_31 ;
if ( ! ( V_31 & V_383 ) )
break;
V_2 -> V_5 . V_382 . V_387 = V_384 -> V_385 . V_386 ;
F_190 () ;
F_184 ( V_2 ) ;
F_191 () ;
F_25 ( V_424 , V_2 ) ;
break;
case V_425 :
if ( F_192 ( V_2 , V_31 ) )
return 1 ;
break;
case V_338 :
case V_336 :
case V_341 ... V_341 + 4 * V_426 - 1 :
return F_164 ( V_2 , V_21 , V_31 ) ;
case V_427 :
case V_428 :
case V_429 :
case V_430 :
if ( V_31 != 0 )
F_176 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_431 :
case V_432 :
case V_433 :
case V_434 :
F_176 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_435 :
case V_436 :
V_393 = true ;
case V_437 :
case V_438 :
if ( F_193 ( V_2 , V_21 ) )
return F_194 ( V_2 , V_392 ) ;
if ( V_393 || V_31 != 0 )
F_176 ( V_2 , L_15
L_14 , V_21 , V_31 ) ;
break;
case V_439 :
break;
case V_359 ... V_440 :
if ( F_171 ( V_21 ) ) {
int V_100 ;
F_195 ( & V_2 -> V_82 -> V_441 ) ;
V_100 = F_172 ( V_2 , V_21 , V_31 ) ;
F_196 ( & V_2 -> V_82 -> V_441 ) ;
return V_100 ;
} else
return F_177 ( V_2 , V_21 , V_31 ) ;
break;
case V_442 :
F_176 ( V_2 , L_16 , V_21 , V_31 ) ;
break;
case V_443 :
if ( ! F_197 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_444 . V_445 = V_31 ;
break;
case V_446 :
if ( ! F_197 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_444 . V_447 = V_31 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_82 -> V_5 . F_165 . V_21 ) )
return F_165 ( V_2 , V_31 ) ;
if ( F_193 ( V_2 , V_21 ) )
return F_194 ( V_2 , V_392 ) ;
if ( ! V_448 ) {
F_176 ( V_2 , L_17 ,
V_21 , V_31 ) ;
return 1 ;
} else {
F_176 ( V_2 , L_16 ,
V_21 , V_31 ) ;
break;
}
}
return 0 ;
}
int F_198 ( struct V_1 * V_2 , T_1 V_449 , T_2 * V_450 )
{
return V_56 -> V_451 ( V_2 , V_449 , V_450 ) ;
}
static int F_199 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_450 )
{
T_2 * V_322 = ( T_2 * ) & V_2 -> V_5 . V_323 . V_324 ;
if ( ! F_159 ( V_21 ) )
return 1 ;
if ( V_21 == V_319 )
* V_450 = V_2 -> V_5 . V_323 . V_325 +
( V_2 -> V_5 . V_323 . V_326 << 10 ) ;
else if ( V_21 == V_308 )
* V_450 = V_322 [ 0 ] ;
else if ( V_21 == V_309 || V_21 == V_310 )
* V_450 = V_322 [ 1 + V_21 - V_309 ] ;
else if ( V_21 >= V_311 && V_21 <= V_318 )
* V_450 = V_322 [ 3 + V_21 - V_311 ] ;
else if ( V_21 == V_320 )
* V_450 = V_2 -> V_5 . V_327 ;
else {
int V_328 , V_329 ;
T_2 * V_330 ;
V_328 = ( V_21 - 0x200 ) / 2 ;
V_329 = V_21 - 0x200 - 2 * V_328 ;
if ( ! V_329 )
V_330 =
( T_2 * ) & V_2 -> V_5 . V_323 . V_331 [ V_328 ] . V_332 ;
else
V_330 =
( T_2 * ) & V_2 -> V_5 . V_323 . V_331 [ V_328 ] . V_333 ;
* V_450 = * V_330 ;
}
return 0 ;
}
static int F_200 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_450 )
{
T_2 V_31 ;
T_2 V_334 = V_2 -> V_5 . V_334 ;
unsigned V_335 = V_334 & 0xff ;
switch ( V_21 ) {
case V_452 :
case V_453 :
V_31 = 0 ;
break;
case V_454 :
V_31 = V_2 -> V_5 . V_334 ;
break;
case V_338 :
if ( ! ( V_334 & V_339 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_340 ;
break;
case V_336 :
V_31 = V_2 -> V_5 . V_337 ;
break;
default:
if ( V_21 >= V_341 &&
V_21 < V_341 + 4 * V_335 ) {
T_1 V_74 = V_21 - V_341 ;
V_31 = V_2 -> V_5 . V_342 [ V_74 ] ;
break;
}
return 1 ;
}
* V_450 = V_31 ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_450 )
{
T_2 V_31 = 0 ;
struct V_82 * V_82 = V_2 -> V_82 ;
switch ( V_21 ) {
case V_359 :
V_31 = V_82 -> V_5 . V_361 ;
break;
case V_360 :
V_31 = V_82 -> V_5 . V_357 ;
break;
default:
F_176 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_450 = V_31 ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_450 )
{
T_2 V_31 = 0 ;
switch ( V_21 ) {
case V_455 : {
int V_100 ;
struct V_1 * V_229 ;
F_156 (r, v, vcpu->kvm)
if ( V_229 == V_2 )
V_31 = V_100 ;
break;
}
case V_371 :
return F_203 ( V_2 , V_372 , V_450 ) ;
case V_373 :
return F_203 ( V_2 , V_374 , V_450 ) ;
case V_375 :
return F_203 ( V_2 , V_376 , V_450 ) ;
case V_367 :
V_31 = V_2 -> V_5 . V_369 ;
break;
default:
F_176 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_450 = V_31 ;
return 0 ;
}
int F_204 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_450 )
{
T_2 V_31 ;
switch ( V_21 ) {
case V_456 :
case V_457 :
case V_403 :
case V_458 :
case V_459 :
case V_460 :
case V_461 :
case V_462 :
case V_401 :
case V_397 :
case V_427 :
case V_431 :
case V_463 :
case V_394 :
case V_402 :
case V_399 :
V_31 = 0 ;
break;
case V_435 :
case V_436 :
case V_437 :
case V_438 :
if ( F_193 ( V_2 , V_21 ) )
return F_205 ( V_2 , V_21 , V_450 ) ;
V_31 = 0 ;
break;
case V_395 :
V_31 = 0x100000000ULL ;
break;
case V_464 :
V_31 = 0x500 | V_307 ;
break;
case 0x200 ... 0x2ff :
return F_199 ( V_2 , V_21 , V_450 ) ;
case 0xcd :
V_31 = 3 ;
break;
case V_465 :
V_31 = 1 << 24 ;
break;
case V_406 :
V_31 = F_18 ( V_2 ) ;
break;
case V_407 ... V_407 + 0x3ff :
return F_206 ( V_2 , V_21 , V_450 ) ;
break;
case V_408 :
V_31 = F_207 ( V_2 ) ;
break;
case V_409 :
V_31 = ( T_2 ) V_2 -> V_5 . V_255 ;
break;
case V_412 :
V_31 = V_2 -> V_5 . V_413 ;
break;
case V_466 :
V_31 = 1000ULL ;
V_31 |= ( ( ( T_8 ) 4ULL ) << 40 ) ;
break;
case V_400 :
V_31 = V_2 -> V_5 . V_111 ;
break;
case V_415 :
case V_414 :
V_31 = V_2 -> V_82 -> V_5 . V_203 ;
break;
case V_417 :
case V_416 :
V_31 = V_2 -> V_5 . time ;
break;
case V_420 :
V_31 = V_2 -> V_5 . V_6 . V_378 ;
break;
case V_421 :
V_31 = V_2 -> V_5 . V_382 . V_378 ;
break;
case V_425 :
V_31 = V_2 -> V_5 . V_467 . V_378 ;
break;
case V_452 :
case V_453 :
case V_454 :
case V_338 :
case V_336 :
case V_341 ... V_341 + 4 * V_426 - 1 :
return F_200 ( V_2 , V_21 , V_450 ) ;
case V_439 :
V_31 = 0x20000000 ;
break;
case V_359 ... V_440 :
if ( F_171 ( V_21 ) ) {
int V_100 ;
F_195 ( & V_2 -> V_82 -> V_441 ) ;
V_100 = F_201 ( V_2 , V_21 , V_450 ) ;
F_196 ( & V_2 -> V_82 -> V_441 ) ;
return V_100 ;
} else
return F_202 ( V_2 , V_21 , V_450 ) ;
break;
case V_442 :
V_31 = 0xbe702111 ;
break;
case V_443 :
if ( ! F_197 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_444 . V_445 ;
break;
case V_446 :
if ( ! F_197 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_444 . V_447 ;
break;
default:
if ( F_193 ( V_2 , V_21 ) )
return F_205 ( V_2 , V_21 , V_450 ) ;
if ( ! V_448 ) {
F_176 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_176 ( V_2 , L_20 , V_21 ) ;
V_31 = 0 ;
}
break;
}
* V_450 = V_31 ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 , struct V_468 * V_19 ,
struct V_469 * V_470 ,
int (* F_209)( struct V_1 * V_2 ,
unsigned V_124 , T_2 * V_31 ) )
{
int V_3 , V_328 ;
V_328 = F_210 ( & V_2 -> V_82 -> V_471 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_472 ; ++ V_3 )
if ( F_209 ( V_2 , V_470 [ V_3 ] . V_124 , & V_470 [ V_3 ] . V_31 ) )
break;
F_211 ( & V_2 -> V_82 -> V_471 , V_328 ) ;
return V_3 ;
}
static int F_212 ( struct V_1 * V_2 , struct V_468 V_366 * V_473 ,
int (* F_209)( struct V_1 * V_2 ,
unsigned V_124 , T_2 * V_31 ) ,
int V_474 )
{
struct V_468 V_19 ;
struct V_469 * V_470 ;
int V_100 , V_475 ;
unsigned V_476 ;
V_100 = - V_81 ;
if ( F_213 ( & V_19 , V_473 , sizeof V_19 ) )
goto V_94;
V_100 = - V_354 ;
if ( V_19 . V_472 >= V_477 )
goto V_94;
V_476 = sizeof( struct V_469 ) * V_19 . V_472 ;
V_470 = F_166 ( V_473 -> V_470 , V_476 ) ;
if ( F_167 ( V_470 ) ) {
V_100 = F_168 ( V_470 ) ;
goto V_94;
}
V_100 = V_475 = F_208 ( V_2 , & V_19 , V_470 , F_209 ) ;
if ( V_100 < 0 )
goto V_356;
V_100 = - V_81 ;
if ( V_474 && F_214 ( V_473 -> V_470 , V_470 , V_476 ) )
goto V_356;
V_100 = V_475 ;
V_356:
F_169 ( V_470 ) ;
V_94:
return V_100 ;
}
int F_215 ( long V_478 )
{
int V_100 ;
switch ( V_478 ) {
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
#ifdef F_216
case V_511 :
case V_512 :
#endif
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
#ifdef F_216
case V_524 :
V_100 = F_217 ( & V_525 ) ;
break;
#endif
case V_526 :
V_100 = V_426 ;
break;
case V_527 :
V_100 = V_528 ;
break;
case V_529 :
V_100 = V_530 ;
break;
case V_531 :
V_100 = F_218 ( V_532 ) ;
break;
default:
V_100 = 0 ;
break;
}
return V_100 ;
}
long F_219 ( struct V_533 * V_534 ,
unsigned int V_535 , unsigned long V_536 )
{
void V_366 * V_537 = ( void V_366 * ) V_536 ;
long V_100 ;
switch ( V_535 ) {
case V_538 : {
struct V_539 V_366 * V_540 = V_537 ;
struct V_539 V_541 ;
unsigned V_475 ;
V_100 = - V_81 ;
if ( F_213 ( & V_541 , V_540 , sizeof V_541 ) )
goto V_94;
V_475 = V_541 . V_472 ;
V_541 . V_472 = V_542 + F_44 ( V_543 ) ;
if ( F_214 ( V_540 , & V_541 , sizeof V_541 ) )
goto V_94;
V_100 = - V_354 ;
if ( V_475 < V_541 . V_472 )
goto V_94;
V_100 = - V_81 ;
if ( F_214 ( V_540 -> V_544 , & V_545 ,
V_542 * sizeof( T_1 ) ) )
goto V_94;
if ( F_214 ( V_540 -> V_544 + V_542 ,
& V_543 ,
F_44 ( V_543 ) * sizeof( T_1 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_546 : {
struct V_547 V_366 * V_548 = V_537 ;
struct V_547 V_549 ;
V_100 = - V_81 ;
if ( F_213 ( & V_549 , V_548 , sizeof V_549 ) )
goto V_94;
V_100 = F_220 ( & V_549 ,
V_548 -> V_470 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_214 ( V_548 , & V_549 , sizeof V_549 ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_550 : {
T_2 V_551 ;
V_551 = V_552 ;
V_100 = - V_81 ;
if ( F_214 ( V_537 , & V_551 , sizeof V_551 ) )
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
static void F_221 ( void * V_554 )
{
F_222 () ;
}
static bool F_223 ( struct V_1 * V_2 )
{
return V_2 -> V_82 -> V_5 . V_555 &&
! ( V_2 -> V_82 -> V_5 . V_556 & V_557 ) ;
}
void F_224 ( struct V_1 * V_2 , int V_23 )
{
if ( F_223 ( V_2 ) ) {
if ( V_56 -> V_558 () )
F_225 ( V_23 , V_2 -> V_5 . V_559 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_226 ( V_2 -> V_23 ,
F_221 , NULL , 1 ) ;
}
V_56 -> V_560 ( V_2 , V_23 ) ;
if ( F_76 ( V_2 -> V_5 . V_561 ) ) {
F_227 ( V_2 , V_2 -> V_5 . V_561 ) ;
V_2 -> V_5 . V_561 = 0 ;
F_157 ( V_293 , & V_2 -> V_306 ) ;
}
if ( F_76 ( V_2 -> V_23 != V_23 ) || F_129 () ) {
T_11 V_562 = ! V_2 -> V_5 . V_563 ? 0 :
F_151 () - V_2 -> V_5 . V_563 ;
if ( V_562 < 0 )
F_228 ( L_21 ) ;
if ( F_129 () ) {
T_2 V_74 = V_56 -> V_262 ( V_2 ,
V_2 -> V_5 . V_275 ) ;
V_56 -> V_277 ( V_2 , V_74 ) ;
V_2 -> V_5 . V_295 = 1 ;
}
if ( ! V_2 -> V_82 -> V_5 . V_250 || V_2 -> V_23 == - 1 )
F_25 ( V_419 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_229 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_184 ( V_2 ) ;
F_25 ( V_424 , V_2 ) ;
}
void F_230 ( struct V_1 * V_2 )
{
V_56 -> V_564 ( V_2 ) ;
F_231 ( V_2 ) ;
V_2 -> V_5 . V_563 = F_151 () ;
}
static int F_232 ( struct V_1 * V_2 ,
struct V_565 * V_566 )
{
V_56 -> V_567 ( V_2 ) ;
memcpy ( V_566 -> V_568 , V_2 -> V_5 . V_569 -> V_568 , sizeof *V_566 ) ;
return 0 ;
}
static int F_233 ( struct V_1 * V_2 ,
struct V_565 * V_566 )
{
F_234 ( V_2 , V_566 ) ;
F_235 ( V_2 ) ;
return 0 ;
}
static int F_236 ( struct V_1 * V_2 ,
struct V_570 * V_571 )
{
if ( V_571 -> V_571 >= V_572 )
return - V_553 ;
if ( F_79 ( V_2 -> V_82 ) )
return - V_573 ;
F_237 ( V_2 , V_571 -> V_571 , false ) ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_238 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
return 0 ;
}
static int F_239 ( struct V_1 * V_2 ,
struct V_574 * V_575 )
{
if ( V_575 -> V_258 )
return - V_553 ;
V_2 -> V_5 . V_576 = ! ! V_575 -> V_326 ;
return 0 ;
}
static int F_240 ( struct V_1 * V_2 ,
T_2 V_334 )
{
int V_100 ;
unsigned V_335 = V_334 & 0xff , V_577 ;
V_100 = - V_553 ;
if ( ! V_335 || V_335 >= V_426 )
goto V_94;
if ( V_334 & ~ ( V_552 | 0xff | 0xff0000 ) )
goto V_94;
V_100 = 0 ;
V_2 -> V_5 . V_334 = V_334 ;
if ( V_334 & V_339 )
V_2 -> V_5 . V_340 = ~ ( T_2 ) 0 ;
for ( V_577 = 0 ; V_577 < V_335 ; V_577 ++ )
V_2 -> V_5 . V_342 [ V_577 * 4 ] = ~ ( T_2 ) 0 ;
V_94:
return V_100 ;
}
static int F_241 ( struct V_1 * V_2 ,
struct V_578 * V_579 )
{
T_2 V_334 = V_2 -> V_5 . V_334 ;
unsigned V_335 = V_334 & 0xff ;
T_2 * V_580 = V_2 -> V_5 . V_342 ;
if ( V_579 -> V_577 >= V_335 || ! ( V_579 -> V_447 & V_581 ) )
return - V_553 ;
if ( ( V_579 -> V_447 & V_582 ) && ( V_334 & V_339 ) &&
V_2 -> V_5 . V_340 != ~ ( T_2 ) 0 )
return 0 ;
V_580 += 4 * V_579 -> V_577 ;
if ( ( V_579 -> V_447 & V_582 ) && V_580 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_579 -> V_447 & V_582 ) {
if ( ( V_2 -> V_5 . V_337 & V_583 ) ||
! F_56 ( V_2 , V_584 ) ) {
F_25 ( V_54 , V_2 ) ;
return 0 ;
}
if ( V_580 [ 1 ] & V_581 )
V_579 -> V_447 |= V_585 ;
V_580 [ 2 ] = V_579 -> V_362 ;
V_580 [ 3 ] = V_579 -> V_586 ;
V_2 -> V_5 . V_337 = V_579 -> V_337 ;
V_580 [ 1 ] = V_579 -> V_447 ;
F_26 ( V_2 , V_587 ) ;
} else if ( ! ( V_580 [ 1 ] & V_581 )
|| ! ( V_580 [ 1 ] & V_582 ) ) {
if ( V_580 [ 1 ] & V_581 )
V_579 -> V_447 |= V_585 ;
V_580 [ 2 ] = V_579 -> V_362 ;
V_580 [ 3 ] = V_579 -> V_586 ;
V_580 [ 1 ] = V_579 -> V_447 ;
} else
V_580 [ 1 ] |= V_585 ;
return 0 ;
}
static void F_242 ( struct V_1 * V_2 ,
struct V_588 * V_589 )
{
F_243 ( V_2 ) ;
V_589 -> V_49 . V_590 =
V_2 -> V_5 . V_49 . V_50 &&
! F_244 ( V_2 -> V_5 . V_49 . V_16 ) ;
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
V_589 -> V_603 = 0 ;
V_589 -> V_258 = ( V_604
| V_605 ) ;
memset ( & V_589 -> V_606 , 0 , sizeof( V_589 -> V_606 ) ) ;
}
static int F_245 ( struct V_1 * V_2 ,
struct V_588 * V_589 )
{
if ( V_589 -> V_258 & ~ ( V_604
| V_607
| V_605 ) )
return - V_553 ;
F_243 ( V_2 ) ;
V_2 -> V_5 . V_49 . V_50 = V_589 -> V_49 . V_590 ;
V_2 -> V_5 . V_49 . V_16 = V_589 -> V_49 . V_16 ;
V_2 -> V_5 . V_49 . V_52 = V_589 -> V_49 . V_52 ;
V_2 -> V_5 . V_49 . V_43 = V_589 -> V_49 . V_43 ;
V_2 -> V_5 . V_592 . V_50 = V_589 -> V_592 . V_590 ;
V_2 -> V_5 . V_592 . V_16 = V_589 -> V_592 . V_16 ;
V_2 -> V_5 . V_592 . V_593 = V_589 -> V_592 . V_593 ;
if ( V_589 -> V_258 & V_605 )
V_56 -> V_608 ( V_2 ,
V_589 -> V_592 . V_594 ) ;
V_2 -> V_5 . V_599 = V_589 -> V_598 . V_590 ;
if ( V_589 -> V_258 & V_604 )
V_2 -> V_5 . V_600 = V_589 -> V_598 . V_50 ;
V_56 -> V_609 ( V_2 , V_589 -> V_598 . V_601 ) ;
if ( V_589 -> V_258 & V_607 &&
F_246 ( V_2 ) )
V_2 -> V_5 . V_569 -> V_603 = V_589 -> V_603 ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
static void F_247 ( struct V_1 * V_2 ,
struct V_610 * V_611 )
{
memcpy ( V_611 -> V_157 , V_2 -> V_5 . V_157 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_611 -> V_160 = V_2 -> V_5 . V_160 ;
V_611 -> V_148 = V_2 -> V_5 . V_148 ;
V_611 -> V_258 = 0 ;
memset ( & V_611 -> V_606 , 0 , sizeof( V_611 -> V_606 ) ) ;
}
static int F_248 ( struct V_1 * V_2 ,
struct V_610 * V_611 )
{
if ( V_611 -> V_258 )
return - V_553 ;
memcpy ( V_2 -> V_5 . V_157 , V_611 -> V_157 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_2 -> V_5 . V_160 = V_611 -> V_160 ;
V_2 -> V_5 . V_148 = V_611 -> V_148 ;
return 0 ;
}
static void F_249 ( struct V_1 * V_2 ,
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
static int F_250 ( struct V_1 * V_2 ,
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
static void F_251 ( struct V_1 * V_2 ,
struct V_624 * V_625 )
{
if ( ! V_528 ) {
V_625 -> V_626 = 0 ;
return;
}
V_625 -> V_626 = 1 ;
V_625 -> V_258 = 0 ;
V_625 -> V_627 [ 0 ] . V_125 = V_121 ;
V_625 -> V_627 [ 0 ] . V_22 = V_2 -> V_5 . V_122 ;
}
static int F_252 ( struct V_1 * V_2 ,
struct V_624 * V_625 )
{
int V_3 , V_100 = 0 ;
if ( ! V_528 )
return - V_553 ;
if ( V_625 -> V_626 > V_628 || V_625 -> V_258 )
return - V_553 ;
for ( V_3 = 0 ; V_3 < V_625 -> V_626 ; V_3 ++ )
if ( V_625 -> V_627 [ 0 ] . V_125 == V_121 ) {
V_100 = F_64 ( V_2 , V_121 ,
V_625 -> V_627 [ 0 ] . V_22 ) ;
break;
}
if ( V_100 )
V_100 = - V_553 ;
return V_100 ;
}
static int F_253 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_296 )
return - V_553 ;
V_2 -> V_5 . V_304 = true ;
F_25 ( V_293 , V_2 ) ;
return 0 ;
}
long F_254 ( struct V_533 * V_534 ,
unsigned int V_535 , unsigned long V_536 )
{
struct V_1 * V_2 = V_534 -> V_629 ;
void V_366 * V_537 = ( void V_366 * ) V_536 ;
int V_100 ;
union {
struct V_565 * V_630 ;
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
V_632 . V_630 = F_255 ( sizeof( struct V_565 ) , V_634 ) ;
V_100 = - V_355 ;
if ( ! V_632 . V_630 )
goto V_94;
V_100 = F_232 ( V_2 , V_632 . V_630 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_214 ( V_537 , V_632 . V_630 , sizeof( struct V_565 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_635 : {
V_100 = - V_553 ;
if ( ! V_2 -> V_5 . V_569 )
goto V_94;
V_632 . V_630 = F_166 ( V_537 , sizeof( * V_632 . V_630 ) ) ;
if ( F_167 ( V_632 . V_630 ) )
return F_168 ( V_632 . V_630 ) ;
V_100 = F_233 ( V_2 , V_632 . V_630 ) ;
break;
}
case V_636 : {
struct V_570 V_571 ;
V_100 = - V_81 ;
if ( F_213 ( & V_571 , V_537 , sizeof V_571 ) )
goto V_94;
V_100 = F_236 ( V_2 , & V_571 ) ;
break;
}
case V_637 : {
V_100 = F_238 ( V_2 ) ;
break;
}
case V_638 : {
struct V_639 V_366 * V_548 = V_537 ;
struct V_639 V_549 ;
V_100 = - V_81 ;
if ( F_213 ( & V_549 , V_548 , sizeof V_549 ) )
goto V_94;
V_100 = F_256 ( V_2 , & V_549 , V_548 -> V_470 ) ;
break;
}
case V_640 : {
struct V_547 V_366 * V_548 = V_537 ;
struct V_547 V_549 ;
V_100 = - V_81 ;
if ( F_213 ( & V_549 , V_548 , sizeof V_549 ) )
goto V_94;
V_100 = F_257 ( V_2 , & V_549 ,
V_548 -> V_470 ) ;
break;
}
case V_641 : {
struct V_547 V_366 * V_548 = V_537 ;
struct V_547 V_549 ;
V_100 = - V_81 ;
if ( F_213 ( & V_549 , V_548 , sizeof V_549 ) )
goto V_94;
V_100 = F_258 ( V_2 , & V_549 ,
V_548 -> V_470 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_214 ( V_548 , & V_549 , sizeof V_549 ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_642 :
V_100 = F_212 ( V_2 , V_537 , F_198 , 1 ) ;
break;
case V_643 :
V_100 = F_212 ( V_2 , V_537 , F_98 , 0 ) ;
break;
case V_644 : {
struct V_574 V_575 ;
V_100 = - V_81 ;
if ( F_213 ( & V_575 , V_537 , sizeof V_575 ) )
goto V_94;
V_100 = F_239 ( V_2 , & V_575 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_214 ( V_537 , & V_575 , sizeof V_575 ) )
goto V_94;
V_100 = 0 ;
break;
} ;
case V_645 : {
struct V_646 V_647 ;
V_100 = - V_553 ;
if ( ! F_79 ( V_2 -> V_82 ) )
goto V_94;
V_100 = - V_81 ;
if ( F_213 ( & V_647 , V_537 , sizeof V_647 ) )
goto V_94;
V_100 = 0 ;
F_259 ( V_2 , V_647 . V_648 ) ;
break;
}
case V_649 : {
T_2 V_334 ;
V_100 = - V_81 ;
if ( F_213 ( & V_334 , V_537 , sizeof V_334 ) )
goto V_94;
V_100 = F_240 ( V_2 , V_334 ) ;
break;
}
case V_650 : {
struct V_578 V_579 ;
V_100 = - V_81 ;
if ( F_213 ( & V_579 , V_537 , sizeof V_579 ) )
goto V_94;
V_100 = F_241 ( V_2 , & V_579 ) ;
break;
}
case V_651 : {
struct V_588 V_589 ;
F_242 ( V_2 , & V_589 ) ;
V_100 = - V_81 ;
if ( F_214 ( V_537 , & V_589 , sizeof( struct V_588 ) ) )
break;
V_100 = 0 ;
break;
}
case V_652 : {
struct V_588 V_589 ;
V_100 = - V_81 ;
if ( F_213 ( & V_589 , V_537 , sizeof( struct V_588 ) ) )
break;
V_100 = F_245 ( V_2 , & V_589 ) ;
break;
}
case V_653 : {
struct V_610 V_611 ;
F_247 ( V_2 , & V_611 ) ;
V_100 = - V_81 ;
if ( F_214 ( V_537 , & V_611 ,
sizeof( struct V_610 ) ) )
break;
V_100 = 0 ;
break;
}
case V_654 : {
struct V_610 V_611 ;
V_100 = - V_81 ;
if ( F_213 ( & V_611 , V_537 ,
sizeof( struct V_610 ) ) )
break;
V_100 = F_248 ( V_2 , & V_611 ) ;
break;
}
case V_655 : {
V_632 . V_617 = F_255 ( sizeof( struct V_612 ) , V_634 ) ;
V_100 = - V_355 ;
if ( ! V_632 . V_617 )
break;
F_249 ( V_2 , V_632 . V_617 ) ;
V_100 = - V_81 ;
if ( F_214 ( V_537 , V_632 . V_617 , sizeof( struct V_612 ) ) )
break;
V_100 = 0 ;
break;
}
case V_656 : {
V_632 . V_617 = F_166 ( V_537 , sizeof( * V_632 . V_617 ) ) ;
if ( F_167 ( V_632 . V_617 ) )
return F_168 ( V_632 . V_617 ) ;
V_100 = F_250 ( V_2 , V_632 . V_617 ) ;
break;
}
case V_657 : {
V_632 . V_627 = F_255 ( sizeof( struct V_624 ) , V_634 ) ;
V_100 = - V_355 ;
if ( ! V_632 . V_627 )
break;
F_251 ( V_2 , V_632 . V_627 ) ;
V_100 = - V_81 ;
if ( F_214 ( V_537 , V_632 . V_627 ,
sizeof( struct V_624 ) ) )
break;
V_100 = 0 ;
break;
}
case V_658 : {
V_632 . V_627 = F_166 ( V_537 , sizeof( * V_632 . V_627 ) ) ;
if ( F_167 ( V_632 . V_627 ) )
return F_168 ( V_632 . V_627 ) ;
V_100 = F_252 ( V_2 , V_632 . V_627 ) ;
break;
}
case V_659 : {
T_1 V_660 ;
V_100 = - V_553 ;
V_660 = ( T_1 ) V_536 ;
if ( V_660 >= V_661 )
goto V_94;
if ( V_660 == 0 )
V_660 = V_235 ;
F_121 ( V_2 , V_660 ) ;
V_100 = 0 ;
goto V_94;
}
case V_662 : {
V_100 = V_2 -> V_5 . V_234 ;
goto V_94;
}
case V_663 : {
V_100 = F_253 ( V_2 ) ;
goto V_94;
}
default:
V_100 = - V_553 ;
}
V_94:
F_169 ( V_632 . V_631 ) ;
return V_100 ;
}
int F_260 ( struct V_1 * V_2 , struct V_664 * V_665 )
{
return V_666 ;
}
static int F_261 ( struct V_82 * V_82 , unsigned long V_362 )
{
int V_89 ;
if ( V_362 > ( unsigned int ) ( - 3 * V_88 ) )
return - V_553 ;
V_89 = V_56 -> V_667 ( V_82 , V_362 ) ;
return V_89 ;
}
static int F_262 ( struct V_82 * V_82 ,
T_2 V_668 )
{
V_82 -> V_5 . V_669 = V_668 ;
return 0 ;
}
static int F_263 ( struct V_82 * V_82 ,
T_1 V_670 )
{
if ( V_670 < V_671 )
return - V_553 ;
F_195 ( & V_82 -> V_672 ) ;
F_264 ( V_82 , V_670 ) ;
V_82 -> V_5 . V_673 = V_670 ;
F_196 ( & V_82 -> V_672 ) ;
return 0 ;
}
static int F_265 ( struct V_82 * V_82 )
{
return V_82 -> V_5 . V_674 ;
}
static int F_266 ( struct V_82 * V_82 , struct V_675 * V_676 )
{
int V_100 ;
V_100 = 0 ;
switch ( V_676 -> V_677 ) {
case V_678 :
memcpy ( & V_676 -> V_676 . V_679 ,
& F_267 ( V_82 ) -> V_680 [ 0 ] ,
sizeof( struct V_681 ) ) ;
break;
case V_682 :
memcpy ( & V_676 -> V_676 . V_679 ,
& F_267 ( V_82 ) -> V_680 [ 1 ] ,
sizeof( struct V_681 ) ) ;
break;
case V_683 :
V_100 = F_268 ( V_82 , & V_676 -> V_676 . V_684 ) ;
break;
default:
V_100 = - V_553 ;
break;
}
return V_100 ;
}
static int F_269 ( struct V_82 * V_82 , struct V_675 * V_676 )
{
int V_100 ;
V_100 = 0 ;
switch ( V_676 -> V_677 ) {
case V_678 :
F_132 ( & F_267 ( V_82 ) -> V_441 ) ;
memcpy ( & F_267 ( V_82 ) -> V_680 [ 0 ] ,
& V_676 -> V_676 . V_679 ,
sizeof( struct V_681 ) ) ;
F_133 ( & F_267 ( V_82 ) -> V_441 ) ;
break;
case V_682 :
F_132 ( & F_267 ( V_82 ) -> V_441 ) ;
memcpy ( & F_267 ( V_82 ) -> V_680 [ 1 ] ,
& V_676 -> V_676 . V_679 ,
sizeof( struct V_681 ) ) ;
F_133 ( & F_267 ( V_82 ) -> V_441 ) ;
break;
case V_683 :
V_100 = F_270 ( V_82 , & V_676 -> V_676 . V_684 ) ;
break;
default:
V_100 = - V_553 ;
break;
}
F_271 ( F_267 ( V_82 ) ) ;
return V_100 ;
}
static int F_272 ( struct V_82 * V_82 , struct V_685 * V_686 )
{
int V_100 = 0 ;
F_195 ( & V_82 -> V_5 . V_687 -> V_688 . V_441 ) ;
memcpy ( V_686 , & V_82 -> V_5 . V_687 -> V_688 , sizeof( struct V_685 ) ) ;
F_196 ( & V_82 -> V_5 . V_687 -> V_688 . V_441 ) ;
return V_100 ;
}
static int F_273 ( struct V_82 * V_82 , struct V_685 * V_686 )
{
int V_100 = 0 ;
F_195 ( & V_82 -> V_5 . V_687 -> V_688 . V_441 ) ;
memcpy ( & V_82 -> V_5 . V_687 -> V_688 , V_686 , sizeof( struct V_685 ) ) ;
F_274 ( V_82 , 0 , V_686 -> V_689 [ 0 ] . V_690 , 0 ) ;
F_196 ( & V_82 -> V_5 . V_687 -> V_688 . V_441 ) ;
return V_100 ;
}
static int F_275 ( struct V_82 * V_82 , struct V_691 * V_686 )
{
int V_100 = 0 ;
F_195 ( & V_82 -> V_5 . V_687 -> V_688 . V_441 ) ;
memcpy ( V_686 -> V_689 , & V_82 -> V_5 . V_687 -> V_688 . V_689 ,
sizeof( V_686 -> V_689 ) ) ;
V_686 -> V_258 = V_82 -> V_5 . V_687 -> V_688 . V_258 ;
F_196 ( & V_82 -> V_5 . V_687 -> V_688 . V_441 ) ;
memset ( & V_686 -> V_606 , 0 , sizeof( V_686 -> V_606 ) ) ;
return V_100 ;
}
static int F_276 ( struct V_82 * V_82 , struct V_691 * V_686 )
{
int V_100 = 0 , V_692 = 0 ;
T_1 V_693 , V_694 ;
F_195 ( & V_82 -> V_5 . V_687 -> V_688 . V_441 ) ;
V_693 = V_82 -> V_5 . V_687 -> V_688 . V_258 & V_695 ;
V_694 = V_686 -> V_258 & V_695 ;
if ( ! V_693 && V_694 )
V_692 = 1 ;
memcpy ( & V_82 -> V_5 . V_687 -> V_688 . V_689 , & V_686 -> V_689 ,
sizeof( V_82 -> V_5 . V_687 -> V_688 . V_689 ) ) ;
V_82 -> V_5 . V_687 -> V_688 . V_258 = V_686 -> V_258 ;
F_274 ( V_82 , 0 , V_82 -> V_5 . V_687 -> V_688 . V_689 [ 0 ] . V_690 , V_692 ) ;
F_196 ( & V_82 -> V_5 . V_687 -> V_688 . V_441 ) ;
return V_100 ;
}
static int F_277 ( struct V_82 * V_82 ,
struct V_696 * V_697 )
{
if ( ! V_82 -> V_5 . V_687 )
return - V_573 ;
F_195 ( & V_82 -> V_5 . V_687 -> V_688 . V_441 ) ;
V_82 -> V_5 . V_687 -> V_688 . V_44 = V_697 -> V_698 ;
F_196 ( & V_82 -> V_5 . V_687 -> V_688 . V_441 ) ;
return 0 ;
}
int F_278 ( struct V_82 * V_82 , struct V_699 * log )
{
int V_100 ;
struct V_700 * V_701 ;
unsigned long V_475 , V_3 ;
unsigned long * V_702 ;
unsigned long * V_703 ;
bool V_704 = false ;
F_195 ( & V_82 -> V_672 ) ;
V_100 = - V_553 ;
if ( log -> V_10 >= V_522 )
goto V_94;
V_701 = F_279 ( V_82 -> V_705 , log -> V_10 ) ;
V_702 = V_701 -> V_702 ;
V_100 = - V_706 ;
if ( ! V_702 )
goto V_94;
V_475 = F_280 ( V_701 ) ;
V_703 = V_702 + V_475 / sizeof( long ) ;
memset ( V_703 , 0 , V_475 ) ;
F_132 ( & V_82 -> V_707 ) ;
for ( V_3 = 0 ; V_3 < V_475 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_27 ;
T_4 V_74 ;
if ( ! V_702 [ V_3 ] )
continue;
V_704 = true ;
V_27 = F_281 ( & V_702 [ V_3 ] , 0 ) ;
V_703 [ V_3 ] = V_27 ;
V_74 = V_3 * V_708 ;
F_282 ( V_82 , V_701 , V_74 , V_27 ) ;
}
if ( V_704 )
F_283 ( V_82 ) ;
F_133 ( & V_82 -> V_707 ) ;
V_100 = - V_81 ;
if ( F_214 ( log -> V_702 , V_703 , V_475 ) )
goto V_94;
V_100 = 0 ;
V_94:
F_196 ( & V_82 -> V_672 ) ;
return V_100 ;
}
int F_284 ( struct V_82 * V_82 , struct V_709 * V_710 ,
bool V_711 )
{
if ( ! F_79 ( V_82 ) )
return - V_573 ;
V_710 -> V_447 = F_285 ( V_82 , V_712 ,
V_710 -> V_571 , V_710 -> V_713 ,
V_711 ) ;
return 0 ;
}
long F_286 ( struct V_533 * V_534 ,
unsigned int V_535 , unsigned long V_536 )
{
struct V_82 * V_82 = V_534 -> V_629 ;
void V_366 * V_537 = ( void V_366 * ) V_536 ;
int V_100 = - V_714 ;
union {
struct V_685 V_686 ;
struct V_691 V_715 ;
struct V_716 V_717 ;
} V_632 ;
switch ( V_535 ) {
case V_718 :
V_100 = F_261 ( V_82 , V_536 ) ;
break;
case V_719 : {
T_2 V_668 ;
V_100 = - V_81 ;
if ( F_213 ( & V_668 , V_537 , sizeof V_668 ) )
goto V_94;
V_100 = F_262 ( V_82 , V_668 ) ;
break;
}
case V_720 :
V_100 = F_263 ( V_82 , V_536 ) ;
break;
case V_721 :
V_100 = F_265 ( V_82 ) ;
break;
case V_722 : {
struct V_723 * V_724 ;
F_195 ( & V_82 -> V_441 ) ;
V_100 = - V_725 ;
if ( V_82 -> V_5 . V_724 )
goto V_726;
V_100 = - V_553 ;
if ( F_124 ( & V_82 -> V_248 ) )
goto V_726;
V_100 = - V_355 ;
V_724 = F_287 ( V_82 ) ;
if ( V_724 ) {
V_100 = F_288 ( V_82 ) ;
if ( V_100 ) {
F_195 ( & V_82 -> V_672 ) ;
F_289 ( V_82 , V_727 ,
& V_724 -> V_728 ) ;
F_289 ( V_82 , V_727 ,
& V_724 -> V_729 ) ;
F_289 ( V_82 , V_727 ,
& V_724 -> V_730 ) ;
F_196 ( & V_82 -> V_672 ) ;
F_169 ( V_724 ) ;
goto V_726;
}
} else
goto V_726;
F_13 () ;
V_82 -> V_5 . V_724 = V_724 ;
F_13 () ;
V_100 = F_290 ( V_82 ) ;
if ( V_100 ) {
F_195 ( & V_82 -> V_672 ) ;
F_195 ( & V_82 -> V_731 ) ;
F_291 ( V_82 ) ;
F_292 ( V_82 ) ;
F_196 ( & V_82 -> V_731 ) ;
F_196 ( & V_82 -> V_672 ) ;
}
V_726:
F_196 ( & V_82 -> V_441 ) ;
break;
}
case V_732 :
V_632 . V_717 . V_258 = V_733 ;
goto V_734;
case V_735 :
V_100 = - V_81 ;
if ( F_213 ( & V_632 . V_717 , V_537 ,
sizeof( struct V_716 ) ) )
goto V_94;
V_734:
F_195 ( & V_82 -> V_672 ) ;
V_100 = - V_725 ;
if ( V_82 -> V_5 . V_687 )
goto V_736;
V_100 = - V_355 ;
V_82 -> V_5 . V_687 = F_293 ( V_82 , V_632 . V_717 . V_258 ) ;
if ( V_82 -> V_5 . V_687 )
V_100 = 0 ;
V_736:
F_196 ( & V_82 -> V_672 ) ;
break;
case V_737 : {
struct V_675 * V_676 ;
V_676 = F_166 ( V_537 , sizeof( * V_676 ) ) ;
if ( F_167 ( V_676 ) ) {
V_100 = F_168 ( V_676 ) ;
goto V_94;
}
V_100 = - V_573 ;
if ( ! F_79 ( V_82 ) )
goto V_738;
V_100 = F_266 ( V_82 , V_676 ) ;
if ( V_100 )
goto V_738;
V_100 = - V_81 ;
if ( F_214 ( V_537 , V_676 , sizeof *V_676 ) )
goto V_738;
V_100 = 0 ;
V_738:
F_169 ( V_676 ) ;
break;
}
case V_739 : {
struct V_675 * V_676 ;
V_676 = F_166 ( V_537 , sizeof( * V_676 ) ) ;
if ( F_167 ( V_676 ) ) {
V_100 = F_168 ( V_676 ) ;
goto V_94;
}
V_100 = - V_573 ;
if ( ! F_79 ( V_82 ) )
goto V_740;
V_100 = F_269 ( V_82 , V_676 ) ;
if ( V_100 )
goto V_740;
V_100 = 0 ;
V_740:
F_169 ( V_676 ) ;
break;
}
case V_741 : {
V_100 = - V_81 ;
if ( F_213 ( & V_632 . V_686 , V_537 , sizeof( struct V_685 ) ) )
goto V_94;
V_100 = - V_573 ;
if ( ! V_82 -> V_5 . V_687 )
goto V_94;
V_100 = F_272 ( V_82 , & V_632 . V_686 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_214 ( V_537 , & V_632 . V_686 , sizeof( struct V_685 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_742 : {
V_100 = - V_81 ;
if ( F_213 ( & V_632 . V_686 , V_537 , sizeof V_632 . V_686 ) )
goto V_94;
V_100 = - V_573 ;
if ( ! V_82 -> V_5 . V_687 )
goto V_94;
V_100 = F_273 ( V_82 , & V_632 . V_686 ) ;
break;
}
case V_743 : {
V_100 = - V_573 ;
if ( ! V_82 -> V_5 . V_687 )
goto V_94;
V_100 = F_275 ( V_82 , & V_632 . V_715 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_214 ( V_537 , & V_632 . V_715 , sizeof( V_632 . V_715 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_744 : {
V_100 = - V_81 ;
if ( F_213 ( & V_632 . V_715 , V_537 , sizeof( V_632 . V_715 ) ) )
goto V_94;
V_100 = - V_573 ;
if ( ! V_82 -> V_5 . V_687 )
goto V_94;
V_100 = F_276 ( V_82 , & V_632 . V_715 ) ;
break;
}
case V_745 : {
struct V_696 V_697 ;
V_100 = - V_81 ;
if ( F_213 ( & V_697 , V_537 , sizeof( V_697 ) ) )
goto V_94;
V_100 = F_277 ( V_82 , & V_697 ) ;
break;
}
case V_746 : {
V_100 = - V_81 ;
if ( F_213 ( & V_82 -> V_5 . F_165 , V_537 ,
sizeof( struct V_747 ) ) )
goto V_94;
V_100 = - V_553 ;
if ( V_82 -> V_5 . F_165 . V_258 )
goto V_94;
V_100 = 0 ;
break;
}
case V_748 : {
struct V_749 V_750 ;
T_2 V_751 ;
T_11 V_269 ;
V_100 = - V_81 ;
if ( F_213 ( & V_750 , V_537 , sizeof( V_750 ) ) )
goto V_94;
V_100 = - V_553 ;
if ( V_750 . V_258 )
goto V_94;
V_100 = 0 ;
F_294 () ;
V_751 = F_111 () ;
V_269 = V_750 . clock - V_751 ;
F_295 () ;
V_82 -> V_5 . V_209 = V_269 ;
break;
}
case V_752 : {
struct V_749 V_750 ;
T_2 V_751 ;
F_294 () ;
V_751 = F_111 () ;
V_750 . clock = V_82 -> V_5 . V_209 + V_751 ;
F_295 () ;
V_750 . V_258 = 0 ;
memset ( & V_750 . V_591 , 0 , sizeof( V_750 . V_591 ) ) ;
V_100 = - V_81 ;
if ( F_214 ( V_537 , & V_750 , sizeof( V_750 ) ) )
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
static void F_296 ( void )
{
T_1 V_753 [ 2 ] ;
unsigned V_3 , V_754 ;
for ( V_3 = V_754 = V_755 ; V_3 < F_44 ( V_545 ) ; V_3 ++ ) {
if ( F_297 ( V_545 [ V_3 ] , & V_753 [ 0 ] , & V_753 [ 1 ] ) < 0 )
continue;
if ( V_754 < V_3 )
V_545 [ V_754 ] = V_545 [ V_3 ] ;
V_754 ++ ;
}
V_542 = V_754 ;
}
static int F_298 ( struct V_1 * V_2 , T_5 V_362 , int V_75 ,
const void * V_229 )
{
int V_756 = 0 ;
int V_475 ;
do {
V_475 = F_299 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_569 &&
! F_300 ( & V_2 -> V_5 . V_569 -> V_757 , V_362 , V_475 , V_229 ) )
&& F_301 ( V_2 -> V_82 , V_758 , V_362 , V_475 , V_229 ) )
break;
V_756 += V_475 ;
V_362 += V_475 ;
V_75 -= V_475 ;
V_229 += V_475 ;
} while ( V_75 );
return V_756 ;
}
static int F_302 ( struct V_1 * V_2 , T_5 V_362 , int V_75 , void * V_229 )
{
int V_756 = 0 ;
int V_475 ;
do {
V_475 = F_299 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_569 &&
! F_303 ( & V_2 -> V_5 . V_569 -> V_757 , V_362 , V_475 , V_229 ) )
&& F_304 ( V_2 -> V_82 , V_758 , V_362 , V_475 , V_229 ) )
break;
F_305 ( V_759 , V_475 , V_362 , * ( T_2 * ) V_229 ) ;
V_756 += V_475 ;
V_362 += V_475 ;
V_75 -= V_475 ;
V_229 += V_475 ;
} while ( V_75 );
return V_756 ;
}
static void F_306 ( struct V_1 * V_2 ,
struct V_760 * V_761 , int V_762 )
{
V_56 -> V_763 ( V_2 , V_761 , V_762 ) ;
}
void F_307 ( struct V_1 * V_2 ,
struct V_760 * V_761 , int V_762 )
{
V_56 -> V_764 ( V_2 , V_761 , V_762 ) ;
}
T_5 F_308 ( struct V_1 * V_2 , T_5 V_377 , T_1 V_76 )
{
T_5 V_765 ;
struct V_58 V_49 ;
F_309 ( ! F_33 ( V_2 ) ) ;
V_76 |= V_92 ;
V_765 = V_2 -> V_5 . V_67 . V_766 ( V_2 , V_377 , V_76 , & V_49 ) ;
return V_765 ;
}
T_5 F_310 ( struct V_1 * V_2 , T_14 V_767 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return V_2 -> V_5 . V_84 -> V_766 ( V_2 , V_767 , V_76 , V_49 ) ;
}
T_5 F_311 ( struct V_1 * V_2 , T_14 V_767 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
V_76 |= V_768 ;
return V_2 -> V_5 . V_84 -> V_766 ( V_2 , V_767 , V_76 , V_49 ) ;
}
T_5 F_312 ( struct V_1 * V_2 , T_14 V_767 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
V_76 |= V_93 ;
return V_2 -> V_5 . V_84 -> V_766 ( V_2 , V_767 , V_76 , V_49 ) ;
}
T_5 F_313 ( struct V_1 * V_2 , T_14 V_767 ,
struct V_58 * V_49 )
{
return V_2 -> V_5 . V_84 -> V_766 ( V_2 , V_767 , 0 , V_49 ) ;
}
static int F_314 ( T_14 V_362 , void * V_156 , unsigned int V_769 ,
struct V_1 * V_2 , T_1 V_76 ,
struct V_58 * V_49 )
{
void * V_31 = V_156 ;
int V_100 = V_770 ;
while ( V_769 ) {
T_5 V_377 = V_2 -> V_5 . V_84 -> V_766 ( V_2 , V_362 , V_76 ,
V_49 ) ;
unsigned V_74 = V_362 & ( V_88 - 1 ) ;
unsigned V_771 = F_299 ( V_769 , ( unsigned ) V_88 - V_74 ) ;
int V_89 ;
if ( V_377 == V_80 )
return V_772 ;
V_89 = F_103 ( V_2 -> V_82 , V_377 , V_31 , V_771 ) ;
if ( V_89 < 0 ) {
V_100 = V_773 ;
goto V_94;
}
V_769 -= V_771 ;
V_31 += V_771 ;
V_362 += V_771 ;
}
V_94:
return V_100 ;
}
static int F_315 ( struct V_774 * V_775 ,
T_14 V_362 , void * V_156 , unsigned int V_769 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return F_314 ( V_362 , V_156 , V_769 , V_2 ,
V_76 | V_768 ,
V_49 ) ;
}
int F_317 ( struct V_774 * V_775 ,
T_14 V_362 , void * V_156 , unsigned int V_769 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return F_314 ( V_362 , V_156 , V_769 , V_2 , V_76 ,
V_49 ) ;
}
static int F_318 ( struct V_774 * V_775 ,
T_14 V_362 , void * V_156 , unsigned int V_769 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
return F_314 ( V_362 , V_156 , V_769 , V_2 , 0 , V_49 ) ;
}
int F_319 ( struct V_774 * V_775 ,
T_14 V_362 , void * V_156 ,
unsigned int V_769 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
void * V_31 = V_156 ;
int V_100 = V_770 ;
while ( V_769 ) {
T_5 V_377 = V_2 -> V_5 . V_84 -> V_766 ( V_2 , V_362 ,
V_93 ,
V_49 ) ;
unsigned V_74 = V_362 & ( V_88 - 1 ) ;
unsigned V_776 = F_299 ( V_769 , ( unsigned ) V_88 - V_74 ) ;
int V_89 ;
if ( V_377 == V_80 )
return V_772 ;
V_89 = F_104 ( V_2 -> V_82 , V_377 , V_31 , V_776 ) ;
if ( V_89 < 0 ) {
V_100 = V_773 ;
goto V_94;
}
V_769 -= V_776 ;
V_31 += V_776 ;
V_362 += V_776 ;
}
V_94:
return V_100 ;
}
static int F_320 ( struct V_1 * V_2 , unsigned long V_767 ,
T_5 * V_377 , struct V_58 * V_49 ,
bool V_777 )
{
T_1 V_76 = ( ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 )
| ( V_777 ? V_93 : 0 ) ;
if ( F_321 ( V_2 , V_767 )
&& ! F_322 ( V_2 -> V_5 . V_84 , V_2 -> V_5 . V_76 , V_76 ) ) {
* V_377 = V_2 -> V_5 . V_778 << V_87 |
( V_767 & ( V_88 - 1 ) ) ;
F_323 ( V_767 , * V_377 , V_777 , false ) ;
return 1 ;
}
* V_377 = V_2 -> V_5 . V_84 -> V_766 ( V_2 , V_767 , V_76 , V_49 ) ;
if ( * V_377 == V_80 )
return - 1 ;
if ( ( * V_377 & V_351 ) == V_779 )
return 1 ;
if ( F_324 ( V_2 , * V_377 ) ) {
F_323 ( V_767 , * V_377 , V_777 , true ) ;
return 1 ;
}
return 0 ;
}
int F_325 ( struct V_1 * V_2 , T_5 V_377 ,
const void * V_156 , int V_769 )
{
int V_89 ;
V_89 = F_104 ( V_2 -> V_82 , V_377 , V_156 , V_769 ) ;
if ( V_89 < 0 )
return 0 ;
F_326 ( V_2 , V_377 , V_156 , V_769 ) ;
return 1 ;
}
static int F_327 ( struct V_1 * V_2 , void * V_156 , int V_769 )
{
if ( V_2 -> V_780 ) {
F_305 ( V_759 , V_769 ,
V_2 -> V_781 [ 0 ] . V_377 , * ( T_2 * ) V_156 ) ;
V_2 -> V_780 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_328 ( struct V_1 * V_2 , T_5 V_377 ,
void * V_156 , int V_769 )
{
return ! F_103 ( V_2 -> V_82 , V_377 , V_156 , V_769 ) ;
}
static int F_329 ( struct V_1 * V_2 , T_5 V_377 ,
void * V_156 , int V_769 )
{
return F_325 ( V_2 , V_377 , V_156 , V_769 ) ;
}
static int F_330 ( struct V_1 * V_2 , T_5 V_377 , int V_769 , void * V_156 )
{
F_305 ( V_782 , V_769 , V_377 , * ( T_2 * ) V_156 ) ;
return F_298 ( V_2 , V_377 , V_769 , V_156 ) ;
}
static int F_331 ( struct V_1 * V_2 , T_5 V_377 ,
void * V_156 , int V_769 )
{
F_305 ( V_783 , V_769 , V_377 , 0 ) ;
return V_773 ;
}
static int F_332 ( struct V_1 * V_2 , T_5 V_377 ,
void * V_156 , int V_769 )
{
struct V_784 * V_785 = & V_2 -> V_781 [ 0 ] ;
memcpy ( V_2 -> V_786 -> V_787 . V_31 , V_785 -> V_31 , F_299 ( 8u , V_785 -> V_75 ) ) ;
return V_770 ;
}
static int F_333 ( unsigned long V_362 , void * V_156 ,
unsigned int V_769 ,
struct V_58 * V_49 ,
struct V_1 * V_2 ,
const struct V_788 * V_789 )
{
T_5 V_377 ;
int V_756 , V_89 ;
bool V_777 = V_789 -> V_777 ;
struct V_784 * V_785 ;
V_89 = F_320 ( V_2 , V_362 , & V_377 , V_49 , V_777 ) ;
if ( V_89 < 0 )
return V_772 ;
if ( V_89 )
goto V_787;
if ( V_789 -> V_790 ( V_2 , V_377 , V_156 , V_769 ) )
return V_770 ;
V_787:
V_756 = V_789 -> V_791 ( V_2 , V_377 , V_769 , V_156 ) ;
if ( V_756 == V_769 )
return V_770 ;
V_377 += V_756 ;
V_769 -= V_756 ;
V_156 += V_756 ;
F_112 ( V_2 -> V_792 >= V_793 ) ;
V_785 = & V_2 -> V_781 [ V_2 -> V_792 ++ ] ;
V_785 -> V_377 = V_377 ;
V_785 -> V_31 = V_156 ;
V_785 -> V_75 = V_769 ;
return V_770 ;
}
int F_334 ( struct V_774 * V_775 , unsigned long V_362 ,
void * V_156 , unsigned int V_769 ,
struct V_58 * V_49 ,
const struct V_788 * V_789 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
T_5 V_377 ;
int V_794 ;
if ( V_789 -> V_795 &&
V_789 -> V_795 ( V_2 , V_156 , V_769 ) )
return V_770 ;
V_2 -> V_792 = 0 ;
if ( ( ( V_362 + V_769 - 1 ) ^ V_362 ) & V_351 ) {
int V_796 ;
V_796 = - V_362 & ~ V_351 ;
V_794 = F_333 ( V_362 , V_156 , V_796 , V_49 ,
V_2 , V_789 ) ;
if ( V_794 != V_770 )
return V_794 ;
V_362 += V_796 ;
V_156 += V_796 ;
V_769 -= V_796 ;
}
V_794 = F_333 ( V_362 , V_156 , V_769 , V_49 ,
V_2 , V_789 ) ;
if ( V_794 != V_770 )
return V_794 ;
if ( ! V_2 -> V_792 )
return V_794 ;
V_377 = V_2 -> V_781 [ 0 ] . V_377 ;
V_2 -> V_797 = 1 ;
V_2 -> V_798 = 0 ;
V_2 -> V_786 -> V_787 . V_75 = F_299 ( 8u , V_2 -> V_781 [ 0 ] . V_75 ) ;
V_2 -> V_786 -> V_787 . V_799 = V_2 -> V_800 = V_789 -> V_777 ;
V_2 -> V_786 -> V_801 = V_802 ;
V_2 -> V_786 -> V_787 . V_803 = V_377 ;
return V_789 -> V_804 ( V_2 , V_377 , V_156 , V_769 ) ;
}
static int F_335 ( struct V_774 * V_775 ,
unsigned long V_362 ,
void * V_156 ,
unsigned int V_769 ,
struct V_58 * V_49 )
{
return F_334 ( V_775 , V_362 , V_156 , V_769 ,
V_49 , & V_805 ) ;
}
int F_336 ( struct V_774 * V_775 ,
unsigned long V_362 ,
const void * V_156 ,
unsigned int V_769 ,
struct V_58 * V_49 )
{
return F_334 ( V_775 , V_362 , ( void * ) V_156 , V_769 ,
V_49 , & V_806 ) ;
}
static int F_337 ( struct V_774 * V_775 ,
unsigned long V_362 ,
const void * V_807 ,
const void * V_808 ,
unsigned int V_769 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
T_5 V_377 ;
struct V_353 * V_353 ;
char * V_809 ;
bool V_810 ;
if ( V_769 > 8 || ( V_769 & ( V_769 - 1 ) ) )
goto V_811;
V_377 = F_312 ( V_2 , V_362 , NULL ) ;
if ( V_377 == V_80 ||
( V_377 & V_351 ) == V_779 )
goto V_811;
if ( ( ( V_377 + V_769 - 1 ) & V_351 ) != ( V_377 & V_351 ) )
goto V_811;
V_353 = F_338 ( V_2 -> V_82 , V_377 >> V_87 ) ;
if ( F_339 ( V_353 ) )
goto V_811;
V_809 = F_340 ( V_353 ) ;
V_809 += F_341 ( V_377 ) ;
switch ( V_769 ) {
case 1 :
V_810 = F_342 ( T_13 , V_809 , V_807 , V_808 ) ;
break;
case 2 :
V_810 = F_342 ( V_812 , V_809 , V_807 , V_808 ) ;
break;
case 4 :
V_810 = F_342 ( T_1 , V_809 , V_807 , V_808 ) ;
break;
case 8 :
V_810 = F_343 ( V_809 , V_807 , V_808 ) ;
break;
default:
F_22 () ;
}
F_344 ( V_809 ) ;
F_345 ( V_353 ) ;
if ( ! V_810 )
return V_813 ;
F_326 ( V_2 , V_377 , V_808 , V_769 ) ;
return V_770 ;
V_811:
F_346 ( V_814 L_22 ) ;
return F_336 ( V_775 , V_362 , V_808 , V_769 , V_49 ) ;
}
static int F_347 ( struct V_1 * V_2 , void * V_815 )
{
int V_100 ;
if ( V_2 -> V_5 . V_816 . V_817 )
V_100 = F_304 ( V_2 -> V_82 , V_727 , V_2 -> V_5 . V_816 . V_818 ,
V_2 -> V_5 . V_816 . V_476 , V_815 ) ;
else
V_100 = F_301 ( V_2 -> V_82 , V_727 ,
V_2 -> V_5 . V_816 . V_818 , V_2 -> V_5 . V_816 . V_476 ,
V_815 ) ;
return V_100 ;
}
static int F_348 ( struct V_1 * V_2 , int V_476 ,
unsigned short V_818 , void * V_156 ,
unsigned int V_690 , bool V_817 )
{
F_349 ( ! V_817 , V_818 , V_476 , V_690 ) ;
V_2 -> V_5 . V_816 . V_818 = V_818 ;
V_2 -> V_5 . V_816 . V_817 = V_817 ;
V_2 -> V_5 . V_816 . V_690 = V_690 ;
V_2 -> V_5 . V_816 . V_476 = V_476 ;
if ( ! F_347 ( V_2 , V_2 -> V_5 . V_819 ) ) {
V_2 -> V_5 . V_816 . V_690 = 0 ;
return 1 ;
}
V_2 -> V_786 -> V_801 = V_820 ;
V_2 -> V_786 -> V_821 . V_822 = V_817 ? V_823 : V_824 ;
V_2 -> V_786 -> V_821 . V_476 = V_476 ;
V_2 -> V_786 -> V_821 . V_825 = V_826 * V_88 ;
V_2 -> V_786 -> V_821 . V_690 = V_690 ;
V_2 -> V_786 -> V_821 . V_818 = V_818 ;
return 0 ;
}
static int F_350 ( struct V_774 * V_775 ,
int V_476 , unsigned short V_818 , void * V_156 ,
unsigned int V_690 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
int V_89 ;
if ( V_2 -> V_5 . V_816 . V_690 )
goto V_827;
V_89 = F_348 ( V_2 , V_476 , V_818 , V_156 , V_690 , true ) ;
if ( V_89 ) {
V_827:
memcpy ( V_156 , V_2 -> V_5 . V_819 , V_476 * V_690 ) ;
V_2 -> V_5 . V_816 . V_690 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_351 ( struct V_774 * V_775 ,
int V_476 , unsigned short V_818 ,
const void * V_156 , unsigned int V_690 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
memcpy ( V_2 -> V_5 . V_819 , V_156 , V_476 * V_690 ) ;
return F_348 ( V_2 , V_476 , V_818 , ( void * ) V_156 , V_690 , false ) ;
}
static unsigned long F_352 ( struct V_1 * V_2 , int V_762 )
{
return V_56 -> F_352 ( V_2 , V_762 ) ;
}
static void F_353 ( struct V_774 * V_775 , V_144 V_63 )
{
F_354 ( F_316 ( V_775 ) , V_63 ) ;
}
int F_355 ( struct V_1 * V_2 )
{
if ( ! F_223 ( V_2 ) )
return V_770 ;
if ( V_56 -> V_558 () ) {
int V_23 = F_356 () ;
F_225 ( V_23 , V_2 -> V_5 . V_559 ) ;
F_357 ( V_2 -> V_5 . V_559 ,
F_221 , NULL , 1 ) ;
F_358 () ;
F_359 ( V_2 -> V_5 . V_559 ) ;
} else
F_222 () ;
return V_770 ;
}
static void F_360 ( struct V_774 * V_775 )
{
F_355 ( F_316 ( V_775 ) ) ;
}
int F_361 ( struct V_774 * V_775 , int V_155 , unsigned long * V_828 )
{
return F_86 ( F_316 ( V_775 ) , V_155 , V_828 ) ;
}
int F_362 ( struct V_774 * V_775 , int V_155 , unsigned long V_22 )
{
return F_84 ( F_316 ( V_775 ) , V_155 , V_22 ) ;
}
static T_2 F_363 ( T_2 V_829 , T_1 V_830 )
{
return ( V_829 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_830 ;
}
static unsigned long F_364 ( struct V_774 * V_775 , int V_831 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
unsigned long V_22 ;
switch ( V_831 ) {
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
F_365 ( L_23 , V_224 , V_831 ) ;
return 0 ;
}
return V_22 ;
}
static int F_366 ( struct V_774 * V_775 , int V_831 , V_144 V_156 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
int V_165 = 0 ;
switch ( V_831 ) {
case 0 :
V_165 = F_52 ( V_2 , F_363 ( F_53 ( V_2 ) , V_156 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_62 = V_156 ;
break;
case 3 :
V_165 = F_73 ( V_2 , V_156 ) ;
break;
case 4 :
V_165 = F_66 ( V_2 , F_363 ( F_67 ( V_2 ) , V_156 ) ) ;
break;
case 8 :
V_165 = F_78 ( V_2 , V_156 ) ;
break;
default:
F_365 ( L_23 , V_224 , V_831 ) ;
V_165 = - 1 ;
}
return V_165 ;
}
static void F_367 ( struct V_774 * V_775 , V_144 V_156 )
{
F_368 ( F_316 ( V_775 ) , V_156 ) ;
}
static int F_369 ( struct V_774 * V_775 )
{
return V_56 -> V_71 ( F_316 ( V_775 ) ) ;
}
static void F_370 ( struct V_774 * V_775 , struct V_832 * V_833 )
{
V_56 -> V_834 ( F_316 ( V_775 ) , V_833 ) ;
}
static void F_371 ( struct V_774 * V_775 , struct V_832 * V_833 )
{
V_56 -> V_835 ( F_316 ( V_775 ) , V_833 ) ;
}
static void F_372 ( struct V_774 * V_775 , struct V_832 * V_833 )
{
V_56 -> V_836 ( F_316 ( V_775 ) , V_833 ) ;
}
static void F_373 ( struct V_774 * V_775 , struct V_832 * V_833 )
{
V_56 -> V_837 ( F_316 ( V_775 ) , V_833 ) ;
}
static unsigned long F_374 (
struct V_774 * V_775 , int V_762 )
{
return F_352 ( F_316 ( V_775 ) , V_762 ) ;
}
static bool F_375 ( struct V_774 * V_775 , V_812 * V_838 ,
struct V_839 * V_840 , T_1 * V_841 ,
int V_762 )
{
struct V_760 V_761 ;
F_307 ( F_316 ( V_775 ) , & V_761 , V_762 ) ;
* V_838 = V_761 . V_838 ;
if ( V_761 . V_842 ) {
memset ( V_840 , 0 , sizeof( * V_840 ) ) ;
return false ;
}
if ( V_761 . V_843 )
V_761 . V_844 >>= 12 ;
F_376 ( V_840 , V_761 . V_844 ) ;
F_377 ( V_840 , ( unsigned long ) V_761 . V_845 ) ;
#ifdef F_54
if ( V_841 )
* V_841 = V_761 . V_845 >> 32 ;
#endif
V_840 -> type = V_761 . type ;
V_840 -> V_566 = V_761 . V_566 ;
V_840 -> V_846 = V_761 . V_846 ;
V_840 -> V_322 = V_761 . V_847 ;
V_840 -> V_848 = V_761 . V_848 ;
V_840 -> V_849 = V_761 . V_849 ;
V_840 -> V_850 = V_761 . V_157 ;
V_840 -> V_843 = V_761 . V_843 ;
return true ;
}
static void F_378 ( struct V_774 * V_775 , V_812 V_838 ,
struct V_839 * V_840 , T_1 V_841 ,
int V_762 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
struct V_760 V_761 ;
V_761 . V_838 = V_838 ;
V_761 . V_845 = F_379 ( V_840 ) ;
#ifdef F_54
V_761 . V_845 |= ( ( T_2 ) V_841 ) << 32 ;
#endif
V_761 . V_844 = F_380 ( V_840 ) ;
if ( V_840 -> V_843 )
V_761 . V_844 = ( V_761 . V_844 << 12 ) | 0xfff ;
V_761 . type = V_840 -> type ;
V_761 . V_847 = V_840 -> V_322 ;
V_761 . V_846 = V_840 -> V_846 ;
V_761 . V_157 = V_840 -> V_850 ;
V_761 . V_566 = V_840 -> V_566 ;
V_761 . V_849 = V_840 -> V_849 ;
V_761 . V_843 = V_840 -> V_843 ;
V_761 . V_848 = V_840 -> V_848 ;
V_761 . V_847 = V_840 -> V_322 ;
V_761 . V_842 = ! V_761 . V_847 ;
V_761 . V_851 = 0 ;
F_306 ( V_2 , & V_761 , V_762 ) ;
return;
}
static int F_381 ( struct V_774 * V_775 ,
T_1 V_449 , T_2 * V_450 )
{
return F_198 ( F_316 ( V_775 ) , V_449 , V_450 ) ;
}
static int F_382 ( struct V_774 * V_775 ,
T_1 V_449 , T_2 V_31 )
{
struct V_182 V_21 ;
V_21 . V_31 = V_31 ;
V_21 . V_124 = V_449 ;
V_21 . V_184 = false ;
return F_97 ( F_316 ( V_775 ) , & V_21 ) ;
}
static int F_383 ( struct V_774 * V_775 ,
T_1 V_852 , T_2 * V_450 )
{
return F_90 ( F_316 ( V_775 ) , V_852 , V_450 ) ;
}
static void F_384 ( struct V_774 * V_775 )
{
F_316 ( V_775 ) -> V_5 . V_853 = 1 ;
}
static void F_385 ( struct V_774 * V_775 )
{
F_190 () ;
F_386 ( F_316 ( V_775 ) ) ;
F_387 () ;
}
static void F_388 ( struct V_774 * V_775 )
{
F_191 () ;
}
static int F_389 ( struct V_774 * V_775 ,
struct V_854 * V_855 ,
enum V_856 V_857 )
{
return V_56 -> V_858 ( F_316 ( V_775 ) , V_855 , V_857 ) ;
}
static void F_390 ( struct V_774 * V_775 ,
T_1 * V_859 , T_1 * V_860 , T_1 * V_167 , T_1 * V_175 )
{
V_639 ( F_316 ( V_775 ) , V_859 , V_860 , V_167 , V_175 ) ;
}
static V_144 F_391 ( struct V_774 * V_775 , unsigned V_861 )
{
return F_89 ( F_316 ( V_775 ) , V_861 ) ;
}
static void F_392 ( struct V_774 * V_775 , unsigned V_861 , V_144 V_156 )
{
F_91 ( F_316 ( V_775 ) , V_861 , V_156 ) ;
}
static void F_393 ( struct V_1 * V_2 , T_1 V_27 )
{
T_1 V_862 = V_56 -> V_595 ( V_2 , V_27 ) ;
if ( ! ( V_862 & V_27 ) )
V_56 -> V_608 ( V_2 , V_27 ) ;
}
static void F_394 ( struct V_1 * V_2 )
{
struct V_774 * V_775 = & V_2 -> V_5 . V_863 ;
if ( V_775 -> V_49 . V_32 == V_33 )
F_32 ( V_2 , & V_775 -> V_49 ) ;
else if ( V_775 -> V_49 . V_864 )
F_31 ( V_2 , V_775 -> V_49 . V_32 ,
V_775 -> V_49 . V_43 ) ;
else
F_26 ( V_2 , V_775 -> V_49 . V_32 ) ;
}
static void F_395 ( struct V_774 * V_775 )
{
memset ( & V_775 -> V_865 , 0 ,
( void * ) & V_775 -> V_866 - ( void * ) & V_775 -> V_865 ) ;
V_775 -> V_867 . V_692 = 0 ;
V_775 -> V_867 . V_868 = 0 ;
V_775 -> V_869 . V_870 = 0 ;
V_775 -> V_869 . V_868 = 0 ;
V_775 -> V_871 . V_870 = 0 ;
V_775 -> V_871 . V_868 = 0 ;
}
static void F_396 ( struct V_1 * V_2 )
{
struct V_774 * V_775 = & V_2 -> V_5 . V_863 ;
int V_113 , V_114 ;
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
V_775 -> V_872 = F_397 ( V_2 ) ;
V_775 -> V_873 = F_398 ( V_2 ) ;
V_775 -> V_281 = ( ! F_399 ( V_2 ) ) ? V_874 :
( V_775 -> V_872 & V_875 ) ? V_876 :
V_114 ? V_877 :
V_113 ? V_878 :
V_879 ;
V_775 -> V_880 = F_400 ( V_2 ) ;
F_395 ( V_775 ) ;
V_2 -> V_5 . V_881 = false ;
}
int F_401 ( struct V_1 * V_2 , int V_571 , int V_882 )
{
struct V_774 * V_775 = & V_2 -> V_5 . V_863 ;
int V_89 ;
F_396 ( V_2 ) ;
V_775 -> V_883 = 2 ;
V_775 -> V_884 = 2 ;
V_775 -> V_885 = V_775 -> V_873 + V_882 ;
V_89 = F_402 ( V_775 , V_571 ) ;
if ( V_89 != V_770 )
return V_886 ;
V_775 -> V_873 = V_775 -> V_885 ;
F_403 ( V_2 , V_775 -> V_873 ) ;
F_368 ( V_2 , V_775 -> V_872 ) ;
if ( V_571 == V_887 )
V_2 -> V_5 . V_600 = 0 ;
else
V_2 -> V_5 . V_592 . V_50 = false ;
return V_888 ;
}
static int F_404 ( struct V_1 * V_2 )
{
int V_100 = V_888 ;
++ V_2 -> V_60 . V_889 ;
F_405 ( V_2 ) ;
if ( ! F_400 ( V_2 ) ) {
V_2 -> V_786 -> V_801 = V_890 ;
V_2 -> V_786 -> V_891 . V_892 = V_893 ;
V_2 -> V_786 -> V_891 . V_894 = 0 ;
V_100 = V_886 ;
}
F_26 ( V_2 , V_166 ) ;
return V_100 ;
}
static bool F_406 ( struct V_1 * V_2 , T_14 V_62 ,
bool V_895 ,
int V_896 )
{
T_5 V_377 = V_62 ;
T_15 V_897 ;
if ( V_896 & V_898 )
return false ;
if ( ! V_2 -> V_5 . V_67 . V_899 ) {
V_377 = F_312 ( V_2 , V_62 , NULL ) ;
if ( V_377 == V_80 )
return true ;
}
V_897 = F_407 ( V_2 -> V_82 , F_40 ( V_377 ) ) ;
if ( F_408 ( V_897 ) )
return false ;
F_409 ( V_897 ) ;
if ( V_2 -> V_5 . V_67 . V_899 ) {
unsigned int V_900 ;
F_132 ( & V_2 -> V_82 -> V_707 ) ;
V_900 = V_2 -> V_82 -> V_5 . V_900 ;
F_133 ( & V_2 -> V_82 -> V_707 ) ;
if ( V_900 )
F_410 ( V_2 -> V_82 , F_40 ( V_377 ) ) ;
return true ;
}
F_410 ( V_2 -> V_82 , F_40 ( V_377 ) ) ;
return ! V_895 ;
}
static bool F_411 ( struct V_774 * V_775 ,
unsigned long V_62 , int V_896 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
unsigned long V_901 , V_902 , V_377 = V_62 ;
V_901 = V_2 -> V_5 . V_901 ;
V_902 = V_2 -> V_5 . V_902 ;
V_2 -> V_5 . V_901 = V_2 -> V_5 . V_902 = 0 ;
if ( ! ( V_896 & V_903 ) )
return false ;
if ( F_412 ( V_775 ) )
return false ;
if ( V_775 -> V_873 == V_901 && V_902 == V_62 )
return false ;
V_2 -> V_5 . V_901 = V_775 -> V_873 ;
V_2 -> V_5 . V_902 = V_62 ;
if ( ! V_2 -> V_5 . V_67 . V_899 )
V_377 = F_312 ( V_2 , V_62 , NULL ) ;
F_410 ( V_2 -> V_82 , F_40 ( V_377 ) ) ;
return true ;
}
int F_413 ( struct V_1 * V_2 ,
unsigned long V_62 ,
int V_896 ,
void * V_904 ,
int V_905 )
{
int V_100 ;
struct V_774 * V_775 = & V_2 -> V_5 . V_863 ;
bool V_474 = true ;
bool V_906 = V_2 -> V_5 . V_895 ;
V_2 -> V_5 . V_895 = false ;
F_414 ( V_2 ) ;
if ( ! ( V_896 & V_907 ) ) {
F_396 ( V_2 ) ;
V_775 -> V_908 = 0 ;
V_775 -> V_909 = false ;
V_775 -> V_910 = false ;
V_775 -> V_911
= V_896 & V_912 ;
V_100 = F_415 ( V_775 , V_904 , V_905 ) ;
F_416 ( V_2 ) ;
++ V_2 -> V_60 . V_913 ;
if ( V_100 != V_914 ) {
if ( V_896 & V_912 )
return V_886 ;
if ( F_406 ( V_2 , V_62 , V_906 ,
V_896 ) )
return V_888 ;
if ( V_896 & V_915 )
return V_886 ;
return F_404 ( V_2 ) ;
}
}
if ( V_896 & V_915 ) {
F_403 ( V_2 , V_775 -> V_885 ) ;
return V_888 ;
}
if ( F_411 ( V_775 , V_62 , V_896 ) )
return V_888 ;
if ( V_2 -> V_5 . V_881 ) {
V_2 -> V_5 . V_881 = false ;
F_417 ( V_775 ) ;
}
V_916:
V_100 = F_418 ( V_775 ) ;
if ( V_100 == V_917 )
return V_888 ;
if ( V_100 == V_918 ) {
if ( F_406 ( V_2 , V_62 , V_906 ,
V_896 ) )
return V_888 ;
return F_404 ( V_2 ) ;
}
if ( V_775 -> V_909 ) {
F_394 ( V_2 ) ;
V_100 = V_888 ;
} else if ( V_2 -> V_5 . V_816 . V_690 ) {
if ( ! V_2 -> V_5 . V_816 . V_817 )
V_2 -> V_5 . V_816 . V_690 = 0 ;
else {
V_474 = false ;
V_2 -> V_5 . V_919 = V_920 ;
}
V_100 = V_921 ;
} else if ( V_2 -> V_797 ) {
if ( ! V_2 -> V_800 )
V_474 = false ;
V_100 = V_921 ;
V_2 -> V_5 . V_919 = V_922 ;
} else if ( V_100 == V_923 )
goto V_916;
else
V_100 = V_888 ;
if ( V_474 ) {
F_393 ( V_2 , V_775 -> V_908 ) ;
F_368 ( V_2 , V_775 -> V_872 ) ;
F_25 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_924 = false ;
F_403 ( V_2 , V_775 -> V_873 ) ;
} else
V_2 -> V_5 . V_924 = true ;
return V_100 ;
}
int F_419 ( struct V_1 * V_2 , int V_476 , unsigned short V_818 )
{
unsigned long V_156 = F_89 ( V_2 , V_169 ) ;
int V_89 = F_351 ( & V_2 -> V_5 . V_863 ,
V_476 , V_818 , & V_156 , 1 ) ;
V_2 -> V_5 . V_816 . V_690 = 0 ;
return V_89 ;
}
static void F_420 ( void * V_855 )
{
F_421 ( V_292 , 0 ) ;
}
static void F_422 ( void * V_31 )
{
struct V_925 * V_926 = V_31 ;
unsigned long V_227 = 0 ;
if ( V_31 )
V_227 = V_926 -> V_808 ;
else if ( ! F_218 ( V_927 ) )
V_227 = F_423 ( F_424 () ) ;
if ( ! V_227 )
V_227 = V_235 ;
F_421 ( V_292 , V_227 ) ;
}
static int F_425 ( struct V_928 * V_929 , unsigned long V_156 ,
void * V_31 )
{
struct V_925 * V_926 = V_31 ;
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 , V_930 = 0 ;
if ( V_156 == V_931 && V_926 -> V_807 > V_926 -> V_808 )
return 0 ;
if ( V_156 == V_932 && V_926 -> V_807 < V_926 -> V_808 )
return 0 ;
F_226 ( V_926 -> V_23 , F_422 , V_926 , 1 ) ;
F_426 ( & V_933 ) ;
F_427 (kvm, &vm_list, vm_list) {
F_156 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_926 -> V_23 )
continue;
F_25 ( V_293 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_930 = 1 ;
}
}
F_428 ( & V_933 ) ;
if ( V_926 -> V_807 < V_926 -> V_808 && V_930 ) {
F_226 ( V_926 -> V_23 , F_422 , V_926 , 1 ) ;
}
return 0 ;
}
static int F_429 ( struct V_928 * V_934 ,
unsigned long V_935 , void * V_936 )
{
unsigned int V_23 = ( unsigned long ) V_936 ;
switch ( V_935 ) {
case V_937 :
case V_938 :
F_226 ( V_23 , F_422 , NULL , 1 ) ;
break;
case V_939 :
F_226 ( V_23 , F_420 , NULL , 1 ) ;
break;
}
return V_940 ;
}
static void F_430 ( void )
{
int V_23 ;
V_941 = V_235 ;
F_431 ( & V_942 ) ;
if ( ! F_218 ( V_927 ) ) {
#ifdef F_432
struct V_943 V_944 ;
memset ( & V_944 , 0 , sizeof( V_944 ) ) ;
V_23 = F_356 () ;
F_433 ( & V_944 , V_23 ) ;
if ( V_944 . V_945 . V_946 )
V_941 = V_944 . V_945 . V_946 ;
F_358 () ;
#endif
F_434 ( & V_947 ,
V_948 ) ;
}
F_110 ( L_24 , V_941 ) ;
F_435 (cpu)
F_226 ( V_23 , F_422 , NULL , 1 ) ;
}
int F_436 ( void )
{
return F_437 ( V_949 ) != NULL ;
}
static int F_438 ( void )
{
int V_950 = 3 ;
if ( F_437 ( V_949 ) )
V_950 = V_56 -> V_71 ( F_437 ( V_949 ) ) ;
return V_950 != 0 ;
}
static unsigned long F_439 ( void )
{
unsigned long V_951 = 0 ;
if ( F_437 ( V_949 ) )
V_951 = F_398 ( F_437 ( V_949 ) ) ;
return V_951 ;
}
void F_440 ( struct V_1 * V_2 )
{
F_421 ( V_949 , V_2 ) ;
}
void F_441 ( struct V_1 * V_2 )
{
F_421 ( V_949 , NULL ) ;
}
static void F_442 ( void )
{
T_2 V_27 ;
int V_952 = V_953 . V_954 ;
V_27 = ( ( 1ull << ( 51 - V_952 + 1 ) ) - 1 ) << V_952 ;
V_27 |= 0x3ull << 62 ;
V_27 |= 1ull ;
#ifdef F_54
if ( V_952 == 52 )
V_27 &= ~ 1ull ;
#endif
F_443 ( V_27 ) ;
}
static void F_444 ( struct V_955 * V_956 )
{
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 ;
F_426 ( & V_933 ) ;
F_427 (kvm, &vm_list, vm_list)
F_156 (i, vcpu, kvm)
F_157 ( V_251 , & V_2 -> V_306 ) ;
F_145 ( & V_285 , 0 ) ;
F_428 ( & V_933 ) ;
}
static int F_445 ( struct V_928 * V_929 , unsigned long V_957 ,
void * V_958 )
{
struct V_187 * V_246 = & V_187 ;
struct V_185 * V_186 = V_958 ;
F_99 ( V_186 ) ;
if ( V_246 -> clock . V_190 != V_249 &&
F_124 ( & V_285 ) != 0 )
F_446 ( V_959 , & V_960 ) ;
return 0 ;
}
int F_447 ( void * V_961 )
{
int V_100 ;
struct V_56 * V_789 = (struct V_56 * ) V_961 ;
if ( V_56 ) {
F_10 ( V_26 L_25 ) ;
V_100 = - V_725 ;
goto V_94;
}
if ( ! V_789 -> V_962 () ) {
F_10 ( V_26 L_26 ) ;
V_100 = - V_963 ;
goto V_94;
}
if ( V_789 -> V_964 () ) {
F_10 ( V_26 L_27 ) ;
V_100 = - V_963 ;
goto V_94;
}
V_100 = - V_355 ;
V_25 = F_448 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_94;
}
V_100 = F_449 () ;
if ( V_100 )
goto V_965;
F_442 () ;
F_296 () ;
V_56 = V_789 ;
F_450 ( V_966 , V_967 ,
V_968 , V_969 , 0 ) ;
F_430 () ;
F_451 ( & V_970 ) ;
if ( V_528 )
V_123 = F_452 ( V_121 ) ;
F_453 () ;
#ifdef F_54
F_454 ( & V_971 ) ;
#endif
return 0 ;
V_965:
F_455 ( V_25 ) ;
V_94:
return V_100 ;
}
void F_456 ( void )
{
F_457 ( & V_970 ) ;
if ( ! F_218 ( V_927 ) )
F_458 ( & V_947 ,
V_948 ) ;
F_459 ( & V_942 ) ;
#ifdef F_54
F_460 ( & V_971 ) ;
#endif
V_56 = NULL ;
F_461 () ;
F_455 ( V_25 ) ;
}
int F_462 ( struct V_1 * V_2 )
{
++ V_2 -> V_60 . V_972 ;
if ( F_79 ( V_2 -> V_82 ) ) {
V_2 -> V_5 . V_973 = V_974 ;
return 1 ;
} else {
V_2 -> V_786 -> V_801 = V_975 ;
return 0 ;
}
}
int F_463 ( struct V_1 * V_2 )
{
T_2 V_976 , V_977 , V_978 , V_89 ;
T_16 V_979 , V_980 , V_981 , V_165 = V_982 , V_983 = 0 ;
bool V_984 , V_985 ;
int V_113 , V_114 ;
if ( V_56 -> V_71 ( V_2 ) != 0 || ! F_399 ( V_2 ) ) {
F_26 ( V_2 , V_166 ) ;
return 0 ;
}
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
V_985 = F_48 ( V_2 ) && V_114 == 1 ;
if ( ! V_985 ) {
V_976 = ( ( T_2 ) F_89 ( V_2 , V_170 ) << 32 ) |
( F_89 ( V_2 , V_169 ) & 0xffffffff ) ;
V_977 = ( ( T_2 ) F_89 ( V_2 , V_986 ) << 32 ) |
( F_89 ( V_2 , V_168 ) & 0xffffffff ) ;
V_978 = ( ( T_2 ) F_89 ( V_2 , V_987 ) << 32 ) |
( F_89 ( V_2 , V_988 ) & 0xffffffff ) ;
}
#ifdef F_54
else {
V_976 = F_89 ( V_2 , V_168 ) ;
V_977 = F_89 ( V_2 , V_170 ) ;
V_978 = F_89 ( V_2 , V_989 ) ;
}
#endif
V_979 = V_976 & 0xffff ;
V_984 = ( V_976 >> 16 ) & 0x1 ;
V_981 = ( V_976 >> 32 ) & 0xfff ;
V_980 = ( V_976 >> 48 ) & 0xfff ;
F_464 ( V_979 , V_984 , V_981 , V_980 , V_977 , V_978 ) ;
switch ( V_979 ) {
case V_990 :
F_465 ( V_2 ) ;
break;
default:
V_165 = V_991 ;
break;
}
V_89 = V_165 | ( ( ( T_2 ) V_983 & 0xfff ) << 32 ) ;
if ( V_985 ) {
F_91 ( V_2 , V_169 , V_89 ) ;
} else {
F_91 ( V_2 , V_170 , V_89 >> 32 ) ;
F_91 ( V_2 , V_169 , V_89 & 0xffffffff ) ;
}
return 1 ;
}
int F_466 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_992 , V_993 , V_994 , V_995 , V_89 ;
int V_100 = 1 ;
if ( F_170 ( V_2 -> V_82 ) )
return F_463 ( V_2 ) ;
V_16 = F_89 ( V_2 , V_169 ) ;
V_992 = F_89 ( V_2 , V_986 ) ;
V_993 = F_89 ( V_2 , V_168 ) ;
V_994 = F_89 ( V_2 , V_170 ) ;
V_995 = F_89 ( V_2 , V_988 ) ;
F_467 ( V_16 , V_992 , V_993 , V_994 , V_995 ) ;
if ( ! F_48 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_992 &= 0xFFFFFFFF ;
V_993 &= 0xFFFFFFFF ;
V_994 &= 0xFFFFFFFF ;
V_995 &= 0xFFFFFFFF ;
}
if ( V_56 -> V_71 ( V_2 ) != 0 ) {
V_89 = - V_996 ;
goto V_94;
}
switch ( V_16 ) {
case V_997 :
V_89 = 0 ;
break;
default:
V_89 = - V_998 ;
break;
}
V_94:
F_91 ( V_2 , V_169 , V_89 ) ;
++ V_2 -> V_60 . V_999 ;
return V_100 ;
}
static int F_468 ( struct V_774 * V_775 )
{
struct V_1 * V_2 = F_316 ( V_775 ) ;
char V_1000 [ 3 ] ;
unsigned long V_1001 = F_398 ( V_2 ) ;
V_56 -> V_365 ( V_2 , V_1000 ) ;
return F_336 ( V_775 , V_1001 , V_1000 , 3 , NULL ) ;
}
static int F_469 ( struct V_1 * V_2 )
{
return ( ! F_79 ( V_2 -> V_82 ) && ! F_470 ( V_2 ) &&
V_2 -> V_786 -> V_1002 &&
F_471 ( V_2 ) ) ;
}
static void F_472 ( struct V_1 * V_2 )
{
struct V_1003 * V_1003 = V_2 -> V_786 ;
V_1003 -> V_1004 = ( F_397 ( V_2 ) & V_1005 ) != 0 ;
V_1003 -> V_146 = F_81 ( V_2 ) ;
V_1003 -> V_30 = F_18 ( V_2 ) ;
if ( F_79 ( V_2 -> V_82 ) )
V_1003 -> V_1006 = 1 ;
else
V_1003 -> V_1006 =
F_471 ( V_2 ) &&
! F_470 ( V_2 ) &&
! F_473 ( V_2 ) ;
}
static int F_474 ( struct V_1 * V_2 )
{
struct V_1007 * V_569 = V_2 -> V_5 . V_569 ;
struct V_353 * V_353 ;
if ( ! V_569 || ! V_569 -> V_648 )
return 0 ;
V_353 = F_338 ( V_2 -> V_82 , V_569 -> V_648 >> V_87 ) ;
if ( F_339 ( V_353 ) )
return - V_81 ;
V_2 -> V_5 . V_569 -> V_1008 = V_353 ;
return 0 ;
}
static void F_475 ( struct V_1 * V_2 )
{
struct V_1007 * V_569 = V_2 -> V_5 . V_569 ;
int V_328 ;
if ( ! V_569 || ! V_569 -> V_648 )
return;
V_328 = F_210 ( & V_2 -> V_82 -> V_471 ) ;
F_345 ( V_569 -> V_1008 ) ;
F_476 ( V_2 -> V_82 , V_569 -> V_648 >> V_87 ) ;
F_211 ( & V_2 -> V_82 -> V_471 , V_328 ) ;
}
static void F_235 ( struct V_1 * V_2 )
{
int V_1009 , V_1010 ;
if ( ! V_56 -> F_235 )
return;
if ( ! V_2 -> V_5 . V_569 )
return;
if ( ! V_2 -> V_5 . V_569 -> V_648 )
V_1009 = F_477 ( V_2 ) ;
else
V_1009 = - 1 ;
if ( V_1009 != - 1 )
V_1009 >>= 4 ;
V_1010 = F_82 ( V_2 ) ;
V_56 -> F_235 ( V_2 , V_1010 , V_1009 ) ;
}
static void F_478 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_49 . V_50 ) {
F_479 ( V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ) ;
V_56 -> V_1011 ( V_2 , V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ,
V_2 -> V_5 . V_49 . V_44 ) ;
return;
}
if ( V_2 -> V_5 . V_599 ) {
V_56 -> V_1012 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_592 . V_50 ) {
V_56 -> V_1013 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_600 ) {
if ( V_56 -> V_1014 ( V_2 ) ) {
-- V_2 -> V_5 . V_600 ;
V_2 -> V_5 . V_599 = true ;
V_56 -> V_1012 ( V_2 ) ;
}
} else if ( F_480 ( V_2 ) ) {
if ( V_56 -> V_1015 ( V_2 ) ) {
F_237 ( V_2 , F_481 ( V_2 ) ,
false ) ;
V_56 -> V_1013 ( V_2 ) ;
}
}
}
static void F_243 ( struct V_1 * V_2 )
{
unsigned V_844 = 2 ;
if ( V_56 -> V_602 ( V_2 ) || V_2 -> V_5 . V_599 )
V_844 = 1 ;
V_2 -> V_5 . V_600 += F_482 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_600 = F_299 ( V_2 -> V_5 . V_600 , V_844 ) ;
F_25 ( V_48 , V_2 ) ;
}
static void F_483 ( struct V_82 * V_82 )
{
#ifdef F_54
int V_3 ;
struct V_1 * V_2 ;
struct V_244 * V_245 = & V_82 -> V_5 ;
F_132 ( & V_245 -> V_278 ) ;
F_484 ( V_82 ) ;
F_144 ( V_82 ) ;
F_156 (i, vcpu, kvm)
F_157 ( V_293 , & V_2 -> V_306 ) ;
F_156 (i, vcpu, kvm)
F_485 ( V_1016 , & V_2 -> V_306 ) ;
F_133 ( & V_245 -> V_278 ) ;
#endif
}
static void F_486 ( struct V_1 * V_2 )
{
T_2 V_1017 [ 4 ] ;
T_1 V_1018 [ 8 ] ;
if ( ! F_487 ( V_2 -> V_5 . V_569 ) )
return;
memset ( V_1017 , 0 , 32 ) ;
memset ( V_1018 , 0 , 32 ) ;
F_488 ( V_2 , V_1017 , V_1018 ) ;
V_56 -> V_1019 ( V_2 , V_1017 ) ;
F_489 ( V_2 , V_1018 ) ;
}
static int F_490 ( struct V_1 * V_2 )
{
int V_100 ;
bool V_1020 = ! F_79 ( V_2 -> V_82 ) &&
V_2 -> V_786 -> V_1002 ;
bool V_1021 = false ;
if ( V_2 -> V_306 ) {
if ( F_491 ( V_1022 , V_2 ) )
F_492 ( V_2 ) ;
if ( F_491 ( V_1023 , V_2 ) )
F_493 ( V_2 ) ;
if ( F_491 ( V_251 , V_2 ) )
F_483 ( V_2 -> V_82 ) ;
if ( F_491 ( V_419 , V_2 ) )
F_155 ( V_2 ) ;
if ( F_491 ( V_293 , V_2 ) ) {
V_100 = F_147 ( V_2 ) ;
if ( F_76 ( V_100 ) )
goto V_94;
}
if ( F_491 ( V_1024 , V_2 ) )
F_74 ( V_2 ) ;
if ( F_491 ( V_1025 , V_2 ) )
V_56 -> V_1026 ( V_2 ) ;
if ( F_491 ( V_1027 , V_2 ) ) {
V_2 -> V_786 -> V_801 = V_1028 ;
V_100 = 0 ;
goto V_94;
}
if ( F_491 ( V_54 , V_2 ) ) {
V_2 -> V_786 -> V_801 = V_1029 ;
V_100 = 0 ;
goto V_94;
}
if ( F_491 ( V_1030 , V_2 ) ) {
V_2 -> V_1031 = 0 ;
V_56 -> V_1032 ( V_2 ) ;
}
if ( F_491 ( V_1033 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1034 = true ;
V_100 = 1 ;
goto V_94;
}
if ( F_491 ( V_424 , V_2 ) )
F_185 ( V_2 ) ;
if ( F_491 ( V_69 , V_2 ) )
F_243 ( V_2 ) ;
if ( F_491 ( V_1035 , V_2 ) )
F_494 ( V_2 ) ;
if ( F_491 ( V_1036 , V_2 ) )
F_495 ( V_2 ) ;
if ( F_491 ( V_1037 , V_2 ) )
F_486 ( V_2 ) ;
}
if ( F_491 ( V_48 , V_2 ) || V_1020 ) {
F_496 ( V_2 ) ;
if ( V_2 -> V_5 . V_973 == V_1038 ) {
V_100 = 1 ;
goto V_94;
}
F_478 ( V_2 ) ;
if ( V_2 -> V_5 . V_600 )
V_1021 =
V_56 -> V_1039 ( V_2 ) != 0 ;
else if ( F_480 ( V_2 ) || V_1020 )
V_1021 =
V_56 -> V_1040 ( V_2 ) != 0 ;
if ( F_497 ( V_2 ) ) {
if ( V_56 -> V_1041 )
V_56 -> V_1041 ( V_2 ,
F_477 ( V_2 ) ) ;
F_235 ( V_2 ) ;
F_498 ( V_2 ) ;
}
}
V_100 = F_499 ( V_2 ) ;
if ( F_76 ( V_100 ) ) {
goto V_1042;
}
F_190 () ;
V_56 -> V_1043 ( V_2 ) ;
if ( V_2 -> V_1031 )
F_386 ( V_2 ) ;
F_61 ( V_2 ) ;
V_2 -> V_281 = V_1044 ;
F_500 () ;
F_294 () ;
if ( V_2 -> V_281 == V_1045 || V_2 -> V_306
|| F_501 () || F_502 ( V_384 ) ) {
V_2 -> V_281 = V_1046 ;
F_13 () ;
F_295 () ;
F_191 () ;
V_100 = 1 ;
goto V_1042;
}
F_211 ( & V_2 -> V_82 -> V_471 , V_2 -> V_1047 ) ;
if ( V_1021 )
F_503 ( V_2 -> V_23 ) ;
F_504 () ;
if ( F_76 ( V_2 -> V_5 . V_153 ) ) {
F_505 ( 0 , 7 ) ;
F_505 ( V_2 -> V_5 . V_158 [ 0 ] , 0 ) ;
F_505 ( V_2 -> V_5 . V_158 [ 1 ] , 1 ) ;
F_505 ( V_2 -> V_5 . V_158 [ 2 ] , 2 ) ;
F_505 ( V_2 -> V_5 . V_158 [ 3 ] , 3 ) ;
}
F_506 ( V_2 -> V_252 ) ;
V_56 -> V_786 ( V_2 ) ;
if ( F_507 () )
F_508 () ;
V_2 -> V_5 . V_275 = V_56 -> V_294 ( V_2 ,
F_151 () ) ;
V_2 -> V_281 = V_1046 ;
F_13 () ;
V_56 -> V_1048 ( V_2 ) ;
++ V_2 -> V_60 . V_1049 ;
F_509 () ;
F_510 () ;
F_191 () ;
V_2 -> V_1047 = F_210 ( & V_2 -> V_82 -> V_471 ) ;
if ( F_76 ( V_1050 == V_1051 ) ) {
unsigned long V_1001 = F_398 ( V_2 ) ;
F_511 ( V_1051 , ( void * ) V_1001 ) ;
}
if ( F_76 ( V_2 -> V_5 . V_1052 ) )
F_25 ( V_293 , V_2 ) ;
if ( V_2 -> V_5 . V_1053 )
F_512 ( V_2 ) ;
V_100 = V_56 -> V_1054 ( V_2 ) ;
return V_100 ;
V_1042:
V_56 -> V_1042 ( V_2 ) ;
if ( F_76 ( V_2 -> V_5 . V_1053 ) )
F_512 ( V_2 ) ;
V_94:
return V_100 ;
}
static int F_513 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_82 * V_82 = V_2 -> V_82 ;
V_2 -> V_1047 = F_210 ( & V_82 -> V_471 ) ;
V_100 = F_474 ( V_2 ) ;
if ( V_100 ) {
F_211 ( & V_82 -> V_471 , V_2 -> V_1047 ) ;
return V_100 ;
}
V_100 = 1 ;
while ( V_100 > 0 ) {
if ( V_2 -> V_5 . V_973 == V_1055 &&
! V_2 -> V_5 . V_6 . V_1034 )
V_100 = F_490 ( V_2 ) ;
else {
F_211 ( & V_82 -> V_471 , V_2 -> V_1047 ) ;
F_514 ( V_2 ) ;
V_2 -> V_1047 = F_210 ( & V_82 -> V_471 ) ;
if ( F_491 ( V_1056 , V_2 ) ) {
F_496 ( V_2 ) ;
switch( V_2 -> V_5 . V_973 ) {
case V_974 :
V_2 -> V_5 . V_973 =
V_1055 ;
case V_1055 :
V_2 -> V_5 . V_6 . V_1034 = false ;
break;
case V_1038 :
break;
default:
V_100 = - V_1057 ;
break;
}
}
}
if ( V_100 <= 0 )
break;
F_485 ( V_1058 , & V_2 -> V_306 ) ;
if ( F_515 ( V_2 ) )
F_516 ( V_2 ) ;
if ( F_469 ( V_2 ) ) {
V_100 = - V_1057 ;
V_2 -> V_786 -> V_801 = V_1059 ;
++ V_2 -> V_60 . V_1060 ;
}
F_517 ( V_2 ) ;
if ( F_502 ( V_384 ) ) {
V_100 = - V_1057 ;
V_2 -> V_786 -> V_801 = V_1059 ;
++ V_2 -> V_60 . V_1061 ;
}
if ( F_501 () ) {
F_211 ( & V_82 -> V_471 , V_2 -> V_1047 ) ;
F_518 ( V_2 ) ;
V_2 -> V_1047 = F_210 ( & V_82 -> V_471 ) ;
}
}
F_211 ( & V_82 -> V_471 , V_2 -> V_1047 ) ;
F_475 ( V_2 ) ;
return V_100 ;
}
static inline int F_519 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_1047 = F_210 ( & V_2 -> V_82 -> V_471 ) ;
V_100 = F_520 ( V_2 , V_907 ) ;
F_211 ( & V_2 -> V_82 -> V_471 , V_2 -> V_1047 ) ;
if ( V_100 != V_888 )
return 0 ;
return 1 ;
}
static int V_920 ( struct V_1 * V_2 )
{
F_309 ( ! V_2 -> V_5 . V_816 . V_690 ) ;
return F_519 ( V_2 ) ;
}
static int V_922 ( struct V_1 * V_2 )
{
struct V_1003 * V_786 = V_2 -> V_786 ;
struct V_784 * V_785 ;
unsigned V_75 ;
F_309 ( ! V_2 -> V_797 ) ;
V_785 = & V_2 -> V_781 [ V_2 -> V_798 ] ;
V_75 = F_299 ( 8u , V_785 -> V_75 ) ;
if ( ! V_2 -> V_800 )
memcpy ( V_785 -> V_31 , V_786 -> V_787 . V_31 , V_75 ) ;
if ( V_785 -> V_75 <= 8 ) {
V_785 ++ ;
V_2 -> V_798 ++ ;
} else {
V_785 -> V_31 += V_75 ;
V_785 -> V_377 += V_75 ;
V_785 -> V_75 -= V_75 ;
}
if ( V_2 -> V_798 == V_2 -> V_792 ) {
V_2 -> V_797 = 0 ;
if ( V_2 -> V_800 )
return 1 ;
V_2 -> V_780 = 1 ;
return F_519 ( V_2 ) ;
}
V_786 -> V_801 = V_802 ;
V_786 -> V_787 . V_803 = V_785 -> V_377 ;
if ( V_2 -> V_800 )
memcpy ( V_786 -> V_787 . V_31 , V_785 -> V_31 , F_299 ( 8u , V_785 -> V_75 ) ) ;
V_786 -> V_787 . V_75 = F_299 ( 8u , V_785 -> V_75 ) ;
V_786 -> V_787 . V_799 = V_2 -> V_800 ;
V_2 -> V_5 . V_919 = V_922 ;
return 0 ;
}
int F_521 ( struct V_1 * V_2 , struct V_1003 * V_1003 )
{
int V_100 ;
T_17 V_1062 ;
if ( ! F_522 ( V_384 ) && F_523 ( V_384 ) )
return - V_355 ;
if ( V_2 -> V_1063 )
F_524 ( V_1064 , & V_2 -> V_1065 , & V_1062 ) ;
if ( F_76 ( V_2 -> V_5 . V_973 == V_1066 ) ) {
F_514 ( V_2 ) ;
F_496 ( V_2 ) ;
F_485 ( V_1056 , & V_2 -> V_306 ) ;
V_100 = - V_1067 ;
goto V_94;
}
if ( ! F_79 ( V_2 -> V_82 ) ) {
if ( F_78 ( V_2 , V_1003 -> V_146 ) != 0 ) {
V_100 = - V_553 ;
goto V_94;
}
}
if ( F_76 ( V_2 -> V_5 . V_919 ) ) {
int (* F_525)( struct V_1 * ) = V_2 -> V_5 . V_919 ;
V_2 -> V_5 . V_919 = NULL ;
V_100 = F_525 ( V_2 ) ;
if ( V_100 <= 0 )
goto V_94;
} else
F_112 ( V_2 -> V_5 . V_816 . V_690 || V_2 -> V_797 ) ;
V_100 = F_513 ( V_2 ) ;
V_94:
F_472 ( V_2 ) ;
if ( V_2 -> V_1063 )
F_524 ( V_1064 , & V_1062 , NULL ) ;
return V_100 ;
}
int F_526 ( struct V_1 * V_2 , struct V_1068 * V_568 )
{
if ( V_2 -> V_5 . V_924 ) {
F_527 ( & V_2 -> V_5 . V_863 ) ;
V_2 -> V_5 . V_924 = false ;
}
V_568 -> V_1069 = F_89 ( V_2 , V_169 ) ;
V_568 -> V_1070 = F_89 ( V_2 , V_986 ) ;
V_568 -> V_1071 = F_89 ( V_2 , V_168 ) ;
V_568 -> V_1072 = F_89 ( V_2 , V_170 ) ;
V_568 -> V_1073 = F_89 ( V_2 , V_988 ) ;
V_568 -> V_1074 = F_89 ( V_2 , V_987 ) ;
V_568 -> V_1075 = F_89 ( V_2 , V_1076 ) ;
V_568 -> V_1077 = F_89 ( V_2 , V_1078 ) ;
#ifdef F_54
V_568 -> V_1079 = F_89 ( V_2 , V_989 ) ;
V_568 -> V_1080 = F_89 ( V_2 , V_1081 ) ;
V_568 -> V_1082 = F_89 ( V_2 , V_1083 ) ;
V_568 -> V_1084 = F_89 ( V_2 , V_1085 ) ;
V_568 -> V_1086 = F_89 ( V_2 , V_1087 ) ;
V_568 -> V_1088 = F_89 ( V_2 , V_1089 ) ;
V_568 -> V_1090 = F_89 ( V_2 , V_1091 ) ;
V_568 -> V_1092 = F_89 ( V_2 , V_1093 ) ;
#endif
V_568 -> V_1001 = F_398 ( V_2 ) ;
V_568 -> V_1094 = F_397 ( V_2 ) ;
return 0 ;
}
int F_528 ( struct V_1 * V_2 , struct V_1068 * V_568 )
{
V_2 -> V_5 . V_881 = true ;
V_2 -> V_5 . V_924 = false ;
F_91 ( V_2 , V_169 , V_568 -> V_1069 ) ;
F_91 ( V_2 , V_986 , V_568 -> V_1070 ) ;
F_91 ( V_2 , V_168 , V_568 -> V_1071 ) ;
F_91 ( V_2 , V_170 , V_568 -> V_1072 ) ;
F_91 ( V_2 , V_988 , V_568 -> V_1073 ) ;
F_91 ( V_2 , V_987 , V_568 -> V_1074 ) ;
F_91 ( V_2 , V_1076 , V_568 -> V_1075 ) ;
F_91 ( V_2 , V_1078 , V_568 -> V_1077 ) ;
#ifdef F_54
F_91 ( V_2 , V_989 , V_568 -> V_1079 ) ;
F_91 ( V_2 , V_1081 , V_568 -> V_1080 ) ;
F_91 ( V_2 , V_1083 , V_568 -> V_1082 ) ;
F_91 ( V_2 , V_1085 , V_568 -> V_1084 ) ;
F_91 ( V_2 , V_1087 , V_568 -> V_1086 ) ;
F_91 ( V_2 , V_1089 , V_568 -> V_1088 ) ;
F_91 ( V_2 , V_1091 , V_568 -> V_1090 ) ;
F_91 ( V_2 , V_1093 , V_568 -> V_1092 ) ;
#endif
F_403 ( V_2 , V_568 -> V_1001 ) ;
F_368 ( V_2 , V_568 -> V_1094 ) ;
V_2 -> V_5 . V_49 . V_50 = false ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
void F_529 ( struct V_1 * V_2 , int * V_157 , int * V_849 )
{
struct V_760 V_1095 ;
F_307 ( V_2 , & V_1095 , V_1096 ) ;
* V_157 = V_1095 . V_157 ;
* V_849 = V_1095 . V_849 ;
}
int F_530 ( struct V_1 * V_2 ,
struct V_1097 * V_1098 )
{
struct V_832 V_833 ;
F_307 ( V_2 , & V_1098 -> V_1095 , V_1096 ) ;
F_307 ( V_2 , & V_1098 -> V_1099 , V_1100 ) ;
F_307 ( V_2 , & V_1098 -> V_1101 , V_1102 ) ;
F_307 ( V_2 , & V_1098 -> V_1103 , V_1104 ) ;
F_307 ( V_2 , & V_1098 -> V_1105 , V_1106 ) ;
F_307 ( V_2 , & V_1098 -> V_1107 , V_1108 ) ;
F_307 ( V_2 , & V_1098 -> V_1109 , V_1110 ) ;
F_307 ( V_2 , & V_1098 -> V_1111 , V_1112 ) ;
V_56 -> V_835 ( V_2 , & V_833 ) ;
V_1098 -> V_1113 . V_844 = V_833 . V_476 ;
V_1098 -> V_1113 . V_845 = V_833 . V_63 ;
V_56 -> V_834 ( V_2 , & V_833 ) ;
V_1098 -> V_1114 . V_844 = V_833 . V_476 ;
V_1098 -> V_1114 . V_845 = V_833 . V_63 ;
V_1098 -> V_101 = F_53 ( V_2 ) ;
V_1098 -> V_62 = V_2 -> V_5 . V_62 ;
V_1098 -> V_85 = F_51 ( V_2 ) ;
V_1098 -> V_129 = F_67 ( V_2 ) ;
V_1098 -> V_146 = F_81 ( V_2 ) ;
V_1098 -> V_111 = V_2 -> V_5 . V_111 ;
V_1098 -> V_30 = F_18 ( V_2 ) ;
memset ( V_1098 -> V_1115 , 0 , sizeof V_1098 -> V_1115 ) ;
if ( V_2 -> V_5 . V_592 . V_50 && ! V_2 -> V_5 . V_592 . V_593 )
F_157 ( V_2 -> V_5 . V_592 . V_16 ,
( unsigned long * ) V_1098 -> V_1115 ) ;
return 0 ;
}
int F_531 ( struct V_1 * V_2 ,
struct V_1116 * V_973 )
{
F_496 ( V_2 ) ;
V_973 -> V_973 = V_2 -> V_5 . V_973 ;
return 0 ;
}
int F_532 ( struct V_1 * V_2 ,
struct V_1116 * V_973 )
{
if ( ! F_246 ( V_2 ) &&
V_973 -> V_973 != V_1055 )
return - V_553 ;
if ( V_973 -> V_973 == V_1117 ) {
V_2 -> V_5 . V_973 = V_1038 ;
F_157 ( V_1118 , & V_2 -> V_5 . V_569 -> V_1119 ) ;
} else
V_2 -> V_5 . V_973 = V_973 -> V_973 ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
int F_533 ( struct V_1 * V_2 , V_812 V_1120 , int V_1121 ,
int V_1122 , bool V_52 , T_1 V_43 )
{
struct V_774 * V_775 = & V_2 -> V_5 . V_863 ;
int V_89 ;
F_396 ( V_2 ) ;
V_89 = F_534 ( V_775 , V_1120 , V_1121 , V_1122 ,
V_52 , V_43 ) ;
if ( V_89 )
return V_886 ;
F_403 ( V_2 , V_775 -> V_873 ) ;
F_368 ( V_2 , V_775 -> V_872 ) ;
F_25 ( V_48 , V_2 ) ;
return V_888 ;
}
int F_535 ( struct V_1 * V_2 ,
struct V_1097 * V_1098 )
{
int V_1123 = 0 ;
int V_1124 , V_1125 , V_328 ;
struct V_832 V_833 ;
if ( ! F_68 ( V_2 ) && ( V_1098 -> V_129 & V_119 ) )
return - V_553 ;
V_833 . V_476 = V_1098 -> V_1113 . V_844 ;
V_833 . V_63 = V_1098 -> V_1113 . V_845 ;
V_56 -> V_837 ( V_2 , & V_833 ) ;
V_833 . V_476 = V_1098 -> V_1114 . V_844 ;
V_833 . V_63 = V_1098 -> V_1114 . V_845 ;
V_56 -> V_836 ( V_2 , & V_833 ) ;
V_2 -> V_5 . V_62 = V_1098 -> V_62 ;
V_1123 |= F_51 ( V_2 ) != V_1098 -> V_85 ;
V_2 -> V_5 . V_85 = V_1098 -> V_85 ;
F_46 ( V_143 , ( V_144 * ) & V_2 -> V_5 . V_97 ) ;
F_78 ( V_2 , V_1098 -> V_146 ) ;
V_1123 |= V_2 -> V_5 . V_111 != V_1098 -> V_111 ;
V_56 -> F_95 ( V_2 , V_1098 -> V_111 ) ;
F_19 ( V_2 , V_1098 -> V_30 ) ;
V_1123 |= F_53 ( V_2 ) != V_1098 -> V_101 ;
V_56 -> V_117 ( V_2 , V_1098 -> V_101 ) ;
V_2 -> V_5 . V_101 = V_1098 -> V_101 ;
V_1123 |= F_67 ( V_2 ) != V_1098 -> V_129 ;
V_56 -> V_139 ( V_2 , V_1098 -> V_129 ) ;
if ( V_1098 -> V_129 & V_119 )
F_72 ( V_2 ) ;
V_328 = F_210 ( & V_2 -> V_82 -> V_471 ) ;
if ( ! F_48 ( V_2 ) && F_49 ( V_2 ) ) {
F_43 ( V_2 , V_2 -> V_5 . V_84 , F_51 ( V_2 ) ) ;
V_1123 = 1 ;
}
F_211 ( & V_2 -> V_82 -> V_471 , V_328 ) ;
if ( V_1123 )
F_58 ( V_2 ) ;
V_1125 = V_572 ;
V_1124 = F_536 (
( const unsigned long * ) V_1098 -> V_1115 , V_1125 ) ;
if ( V_1124 < V_1125 ) {
F_237 ( V_2 , V_1124 , false ) ;
F_110 ( L_29 , V_1124 ) ;
}
F_306 ( V_2 , & V_1098 -> V_1095 , V_1096 ) ;
F_306 ( V_2 , & V_1098 -> V_1099 , V_1100 ) ;
F_306 ( V_2 , & V_1098 -> V_1101 , V_1102 ) ;
F_306 ( V_2 , & V_1098 -> V_1103 , V_1104 ) ;
F_306 ( V_2 , & V_1098 -> V_1105 , V_1106 ) ;
F_306 ( V_2 , & V_1098 -> V_1107 , V_1108 ) ;
F_306 ( V_2 , & V_1098 -> V_1109 , V_1110 ) ;
F_306 ( V_2 , & V_1098 -> V_1111 , V_1112 ) ;
F_235 ( V_2 ) ;
if ( F_537 ( V_2 ) && F_398 ( V_2 ) == 0xfff0 &&
V_1098 -> V_1095 . V_838 == 0xf000 && V_1098 -> V_1095 . V_845 == 0xffff0000 &&
! F_399 ( V_2 ) )
V_2 -> V_5 . V_973 = V_1055 ;
F_25 ( V_48 , V_2 ) ;
return 0 ;
}
int F_538 ( struct V_1 * V_2 ,
struct V_1126 * V_1127 )
{
unsigned long V_1094 ;
int V_3 , V_100 ;
if ( V_1127 -> V_697 & ( V_1128 | V_1129 ) ) {
V_100 = - V_1130 ;
if ( V_2 -> V_5 . V_49 . V_50 )
goto V_94;
if ( V_1127 -> V_697 & V_1128 )
F_26 ( V_2 , V_1131 ) ;
else
F_26 ( V_2 , V_1132 ) ;
}
V_1094 = F_397 ( V_2 ) ;
V_2 -> V_149 = V_1127 -> V_697 ;
if ( ! ( V_2 -> V_149 & V_1133 ) )
V_2 -> V_149 = 0 ;
if ( V_2 -> V_149 & V_150 ) {
for ( V_3 = 0 ; V_3 < V_1134 ; ++ V_3 )
V_2 -> V_5 . V_158 [ V_3 ] = V_1127 -> V_5 . V_1135 [ V_3 ] ;
V_2 -> V_5 . V_151 = V_1127 -> V_5 . V_1135 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1134 ; V_3 ++ )
V_2 -> V_5 . V_158 [ V_3 ] = V_2 -> V_5 . V_157 [ V_3 ] ;
}
F_83 ( V_2 ) ;
if ( V_2 -> V_149 & V_1136 )
V_2 -> V_5 . V_1137 = F_398 ( V_2 ) +
F_352 ( V_2 , V_1096 ) ;
F_368 ( V_2 , V_1094 ) ;
V_56 -> V_1138 ( V_2 ) ;
V_100 = 0 ;
V_94:
return V_100 ;
}
int F_539 ( struct V_1 * V_2 ,
struct V_1139 * V_1109 )
{
unsigned long V_1140 = V_1109 -> V_1141 ;
T_5 V_377 ;
int V_328 ;
V_328 = F_210 ( & V_2 -> V_82 -> V_471 ) ;
V_377 = F_313 ( V_2 , V_1140 , NULL ) ;
F_211 ( & V_2 -> V_82 -> V_471 , V_328 ) ;
V_1109 -> V_1142 = V_377 ;
V_1109 -> V_1143 = V_377 != V_80 ;
V_1109 -> V_1144 = 1 ;
V_1109 -> V_1145 = 0 ;
return 0 ;
}
int F_540 ( struct V_1 * V_2 , struct V_1146 * V_1147 )
{
struct V_620 * V_619 =
& V_2 -> V_5 . V_615 . V_616 -> V_619 ;
memcpy ( V_1147 -> V_1148 , V_619 -> V_1149 , 128 ) ;
V_1147 -> V_1150 = V_619 -> V_1151 ;
V_1147 -> V_1152 = V_619 -> V_1153 ;
V_1147 -> V_1154 = V_619 -> V_1155 ;
V_1147 -> V_1156 = V_619 -> V_1157 ;
V_1147 -> V_1158 = V_619 -> V_1001 ;
V_1147 -> V_1159 = V_619 -> V_1160 ;
memcpy ( V_1147 -> V_1161 , V_619 -> V_1162 , sizeof V_619 -> V_1162 ) ;
return 0 ;
}
int F_541 ( struct V_1 * V_2 , struct V_1146 * V_1147 )
{
struct V_620 * V_619 =
& V_2 -> V_5 . V_615 . V_616 -> V_619 ;
memcpy ( V_619 -> V_1149 , V_1147 -> V_1148 , 128 ) ;
V_619 -> V_1151 = V_1147 -> V_1150 ;
V_619 -> V_1153 = V_1147 -> V_1152 ;
V_619 -> V_1155 = V_1147 -> V_1154 ;
V_619 -> V_1157 = V_1147 -> V_1156 ;
V_619 -> V_1001 = V_1147 -> V_1158 ;
V_619 -> V_1160 = V_1147 -> V_1159 ;
memcpy ( V_619 -> V_1162 , V_1147 -> V_1161 , sizeof V_619 -> V_1162 ) ;
return 0 ;
}
int F_542 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_543 ( & V_2 -> V_5 . V_615 ) ;
if ( V_55 )
return V_55 ;
F_544 ( & V_2 -> V_5 . V_615 ) ;
V_2 -> V_5 . V_122 = V_126 ;
V_2 -> V_5 . V_101 |= V_108 ;
return 0 ;
}
static void F_545 ( struct V_1 * V_2 )
{
F_546 ( & V_2 -> V_5 . V_615 ) ;
}
void F_386 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1163 )
return;
F_63 ( V_2 ) ;
V_2 -> V_1163 = 1 ;
F_547 () ;
F_548 ( & V_2 -> V_5 . V_615 ) ;
F_549 ( 1 ) ;
}
void F_231 ( struct V_1 * V_2 )
{
F_63 ( V_2 ) ;
if ( ! V_2 -> V_1163 )
return;
V_2 -> V_1163 = 0 ;
F_550 ( & V_2 -> V_5 . V_615 ) ;
F_551 () ;
++ V_2 -> V_60 . V_1164 ;
F_25 ( V_1030 , V_2 ) ;
F_549 ( 0 ) ;
}
void F_552 ( struct V_1 * V_2 )
{
F_183 ( V_2 ) ;
F_553 ( V_2 -> V_5 . V_559 ) ;
F_545 ( V_2 ) ;
V_56 -> V_1165 ( V_2 ) ;
}
struct V_1 * F_554 ( struct V_82 * V_82 ,
unsigned int V_1166 )
{
if ( F_129 () && F_124 ( & V_82 -> V_248 ) != 0 )
F_346 ( V_814
L_30
L_31 ) ;
return V_56 -> V_1167 ( V_82 , V_1166 ) ;
}
int F_555 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_5 . V_323 . V_1168 = 1 ;
V_100 = V_560 ( V_2 ) ;
if ( V_100 )
return V_100 ;
F_556 ( V_2 ) ;
V_100 = F_557 ( V_2 ) ;
V_564 ( V_2 ) ;
return V_100 ;
}
int F_558 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_182 V_21 ;
V_100 = V_560 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_21 . V_31 = 0x0 ;
V_21 . V_124 = V_1169 ;
V_21 . V_184 = true ;
F_127 ( V_2 , & V_21 ) ;
V_564 ( V_2 ) ;
return V_100 ;
}
void F_559 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_5 . V_6 . V_378 = 0 ;
V_100 = V_560 ( V_2 ) ;
F_309 ( V_100 ) ;
F_492 ( V_2 ) ;
V_564 ( V_2 ) ;
F_545 ( V_2 ) ;
V_56 -> V_1165 ( V_2 ) ;
}
void F_556 ( struct V_1 * V_2 )
{
F_145 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_600 = 0 ;
V_2 -> V_5 . V_599 = false ;
memset ( V_2 -> V_5 . V_157 , 0 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_2 -> V_5 . V_160 = V_162 ;
V_2 -> V_5 . V_148 = V_164 ;
F_83 ( V_2 ) ;
F_25 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_6 . V_378 = 0 ;
V_2 -> V_5 . V_382 . V_378 = 0 ;
F_183 ( V_2 ) ;
F_57 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1034 = false ;
F_560 ( V_2 ) ;
memset ( V_2 -> V_5 . V_568 , 0 , sizeof( V_2 -> V_5 . V_568 ) ) ;
V_2 -> V_5 . V_97 = ~ 0 ;
V_2 -> V_5 . V_98 = ~ 0 ;
V_56 -> V_1170 ( V_2 ) ;
}
void F_561 ( struct V_1 * V_2 , unsigned int V_32 )
{
struct V_760 V_1095 ;
F_307 ( V_2 , & V_1095 , V_1096 ) ;
V_1095 . V_838 = V_32 << 8 ;
V_1095 . V_845 = V_32 << 12 ;
F_306 ( V_2 , & V_1095 , V_1096 ) ;
F_403 ( V_2 , 0 ) ;
}
int F_562 ( void * V_554 )
{
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 ;
int V_89 ;
T_2 V_1171 ;
T_2 V_1172 = 0 ;
bool V_1173 , V_1174 = false ;
F_14 () ;
V_89 = V_56 -> V_1175 ( V_554 ) ;
if ( V_89 != 0 )
return V_89 ;
V_1171 = F_151 () ;
V_1173 = ! F_129 () ;
F_427 (kvm, &vm_list, vm_list) {
F_156 (i, vcpu, kvm) {
if ( ! V_1173 && V_2 -> V_23 == F_8 () )
F_157 ( V_293 , & V_2 -> V_306 ) ;
if ( V_1173 && V_2 -> V_5 . V_563 > V_1171 ) {
V_1174 = true ;
if ( V_2 -> V_5 . V_563 > V_1172 )
V_1172 = V_2 -> V_5 . V_563 ;
}
}
}
if ( V_1174 ) {
T_2 V_1176 = V_1172 - V_1171 ;
F_427 (kvm, &vm_list, vm_list) {
F_156 (i, vcpu, kvm) {
V_2 -> V_5 . V_561 += V_1176 ;
V_2 -> V_5 . V_563 = V_1171 ;
F_157 ( V_251 ,
& V_2 -> V_306 ) ;
}
V_82 -> V_5 . V_263 = 0 ;
V_82 -> V_5 . V_265 = 0 ;
}
}
return 0 ;
}
void F_563 ( void * V_554 )
{
V_56 -> V_1177 ( V_554 ) ;
F_17 ( V_554 ) ;
}
int F_564 ( void )
{
return V_56 -> V_1178 () ;
}
void F_565 ( void )
{
V_56 -> V_1179 () ;
}
void F_566 ( void * V_1180 )
{
V_56 -> V_1181 ( V_1180 ) ;
}
bool F_567 ( struct V_1 * V_2 )
{
return F_79 ( V_2 -> V_82 ) == ( V_2 -> V_5 . V_569 != NULL ) ;
}
int F_568 ( struct V_1 * V_2 )
{
struct V_353 * V_353 ;
struct V_82 * V_82 ;
int V_100 ;
F_309 ( V_2 -> V_82 == NULL ) ;
V_82 = V_2 -> V_82 ;
V_2 -> V_5 . V_863 . V_789 = & V_1182 ;
if ( ! F_79 ( V_82 ) || F_537 ( V_2 ) )
V_2 -> V_5 . V_973 = V_1055 ;
else
V_2 -> V_5 . V_973 = V_1066 ;
V_353 = F_569 ( V_634 | V_1183 ) ;
if ( ! V_353 ) {
V_100 = - V_355 ;
goto V_1184;
}
V_2 -> V_5 . V_819 = F_570 ( V_353 ) ;
F_121 ( V_2 , V_941 ) ;
V_100 = F_571 ( V_2 ) ;
if ( V_100 < 0 )
goto V_1185;
if ( F_79 ( V_82 ) ) {
V_100 = F_572 ( V_2 ) ;
if ( V_100 < 0 )
goto V_1186;
} else
F_573 ( & V_1187 ) ;
V_2 -> V_5 . V_342 = F_255 ( V_426 * sizeof( T_2 ) * 4 ,
V_634 ) ;
if ( ! V_2 -> V_5 . V_342 ) {
V_100 = - V_355 ;
goto V_1188;
}
V_2 -> V_5 . V_334 = V_426 ;
if ( ! F_574 ( & V_2 -> V_5 . V_559 , V_634 ) ) {
V_100 = - V_355 ;
goto V_1189;
}
V_100 = F_542 ( V_2 ) ;
if ( V_100 )
goto V_1190;
V_2 -> V_5 . V_255 = 0x0 ;
V_2 -> V_5 . V_296 = false ;
F_1 ( V_2 ) ;
F_575 ( V_2 ) ;
return 0 ;
V_1190:
F_553 ( V_2 -> V_5 . V_559 ) ;
V_1189:
F_169 ( V_2 -> V_5 . V_342 ) ;
V_1188:
F_576 ( V_2 ) ;
V_1186:
F_577 ( V_2 ) ;
V_1185:
F_578 ( ( unsigned long ) V_2 -> V_5 . V_819 ) ;
V_1184:
return V_100 ;
}
void F_579 ( struct V_1 * V_2 )
{
int V_328 ;
F_580 ( V_2 ) ;
F_169 ( V_2 -> V_5 . V_342 ) ;
F_576 ( V_2 ) ;
V_328 = F_210 ( & V_2 -> V_82 -> V_471 ) ;
F_577 ( V_2 ) ;
F_211 ( & V_2 -> V_82 -> V_471 , V_328 ) ;
F_578 ( ( unsigned long ) V_2 -> V_5 . V_819 ) ;
if ( ! F_79 ( V_2 -> V_82 ) )
F_581 ( & V_1187 ) ;
}
int F_582 ( struct V_82 * V_82 , unsigned long type )
{
if ( type )
return - V_553 ;
F_583 ( & V_82 -> V_5 . V_1191 ) ;
F_583 ( & V_82 -> V_5 . V_1192 ) ;
F_583 ( & V_82 -> V_5 . V_1193 ) ;
F_157 ( V_712 , & V_82 -> V_5 . V_1194 ) ;
F_157 ( V_1195 ,
& V_82 -> V_5 . V_1194 ) ;
F_584 ( & V_82 -> V_5 . V_261 ) ;
F_585 ( & V_82 -> V_5 . V_1196 ) ;
F_586 ( & V_82 -> V_5 . V_278 ) ;
F_144 ( V_82 ) ;
return 0 ;
}
static void F_587 ( struct V_1 * V_2 )
{
int V_100 ;
V_100 = V_560 ( V_2 ) ;
F_309 ( V_100 ) ;
F_492 ( V_2 ) ;
V_564 ( V_2 ) ;
}
static void F_588 ( struct V_82 * V_82 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_156 (i, vcpu, kvm) {
F_57 ( V_2 ) ;
F_587 ( V_2 ) ;
}
F_156 (i, vcpu, kvm)
F_552 ( V_2 ) ;
F_195 ( & V_82 -> V_441 ) ;
for ( V_3 = 0 ; V_3 < F_124 ( & V_82 -> V_248 ) ; V_3 ++ )
V_82 -> V_1197 [ V_3 ] = NULL ;
F_145 ( & V_82 -> V_248 , 0 ) ;
F_196 ( & V_82 -> V_441 ) ;
}
void F_589 ( struct V_82 * V_82 )
{
F_590 ( V_82 ) ;
F_591 ( V_82 ) ;
}
void F_592 ( struct V_82 * V_82 )
{
if ( V_384 -> V_1198 == V_82 -> V_1198 ) {
struct V_1199 V_1200 ;
memset ( & V_1200 , 0 , sizeof( V_1200 ) ) ;
V_1200 . V_10 = V_1201 ;
F_593 ( V_82 , & V_1200 ) ;
V_1200 . V_10 = V_1202 ;
F_593 ( V_82 , & V_1200 ) ;
V_1200 . V_10 = V_1203 ;
F_593 ( V_82 , & V_1200 ) ;
}
F_594 ( V_82 ) ;
F_169 ( V_82 -> V_5 . V_724 ) ;
F_169 ( V_82 -> V_5 . V_1204 ) ;
F_588 ( V_82 ) ;
if ( V_82 -> V_5 . V_1205 )
F_595 ( V_82 -> V_5 . V_1205 ) ;
if ( V_82 -> V_5 . V_1206 )
F_595 ( V_82 -> V_5 . V_1206 ) ;
F_169 ( F_596 ( V_82 -> V_5 . V_1207 , 1 ) ) ;
}
void F_597 ( struct V_700 * free ,
struct V_700 * V_1208 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1209 ; ++ V_3 ) {
if ( ! V_1208 || free -> V_5 . V_1210 [ V_3 ] != V_1208 -> V_5 . V_1210 [ V_3 ] ) {
F_598 ( free -> V_5 . V_1210 [ V_3 ] ) ;
free -> V_5 . V_1210 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1208 || free -> V_5 . V_1211 [ V_3 - 1 ] !=
V_1208 -> V_5 . V_1211 [ V_3 - 1 ] ) {
F_598 ( free -> V_5 . V_1211 [ V_3 - 1 ] ) ;
free -> V_5 . V_1211 [ V_3 - 1 ] = NULL ;
}
}
}
int F_599 ( struct V_700 * V_10 , unsigned long V_1212 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1209 ; ++ V_3 ) {
unsigned long V_1213 ;
int V_1214 ;
int V_713 = V_3 + 1 ;
V_1214 = F_600 ( V_10 -> V_1215 + V_1212 - 1 ,
V_10 -> V_1215 , V_713 ) + 1 ;
V_10 -> V_5 . V_1210 [ V_3 ] =
F_601 ( V_1214 * sizeof( * V_10 -> V_5 . V_1210 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1210 [ V_3 ] )
goto V_356;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1211 [ V_3 - 1 ] = F_601 ( V_1214 *
sizeof( * V_10 -> V_5 . V_1211 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1211 [ V_3 - 1 ] )
goto V_356;
if ( V_10 -> V_1215 & ( F_602 ( V_713 ) - 1 ) )
V_10 -> V_5 . V_1211 [ V_3 - 1 ] [ 0 ] . V_1216 = 1 ;
if ( ( V_10 -> V_1215 + V_1212 ) & ( F_602 ( V_713 ) - 1 ) )
V_10 -> V_5 . V_1211 [ V_3 - 1 ] [ V_1214 - 1 ] . V_1216 = 1 ;
V_1213 = V_10 -> V_1217 >> V_87 ;
if ( ( V_10 -> V_1215 ^ V_1213 ) & ( F_602 ( V_713 ) - 1 ) ||
! F_603 () ) {
unsigned long V_754 ;
for ( V_754 = 0 ; V_754 < V_1214 ; ++ V_754 )
V_10 -> V_5 . V_1211 [ V_3 - 1 ] [ V_754 ] . V_1216 = 1 ;
}
}
return 0 ;
V_356:
for ( V_3 = 0 ; V_3 < V_1209 ; ++ V_3 ) {
F_598 ( V_10 -> V_5 . V_1210 [ V_3 ] ) ;
V_10 -> V_5 . V_1210 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_598 ( V_10 -> V_5 . V_1211 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1211 [ V_3 - 1 ] = NULL ;
}
return - V_355 ;
}
int F_604 ( struct V_82 * V_82 ,
struct V_700 * V_701 ,
struct V_1199 * V_1200 ,
enum V_1218 V_1219 )
{
if ( ( V_701 -> V_1166 >= V_522 ) && ( V_1219 == V_1220 ) ) {
unsigned long V_1217 ;
V_1217 = F_605 ( NULL , 0 , V_701 -> V_1212 * V_88 ,
V_1221 | V_1222 ,
V_1223 | V_1224 , 0 ) ;
if ( F_167 ( ( void * ) V_1217 ) )
return F_168 ( ( void * ) V_1217 ) ;
V_701 -> V_1217 = V_1217 ;
}
return 0 ;
}
void F_606 ( struct V_82 * V_82 ,
struct V_1199 * V_1200 ,
const struct V_700 * V_807 ,
enum V_1218 V_1219 )
{
int V_1225 = 0 ;
if ( ( V_1200 -> V_10 >= V_522 ) && ( V_1219 == V_1226 ) ) {
int V_89 ;
V_89 = F_607 ( V_807 -> V_1217 ,
V_807 -> V_1212 * V_88 ) ;
if ( V_89 < 0 )
F_10 ( V_814
L_32
L_33 ) ;
}
if ( ! V_82 -> V_5 . V_673 )
V_1225 = F_608 ( V_82 ) ;
if ( V_1225 )
F_264 ( V_82 , V_1225 ) ;
if ( ( V_1219 != V_1226 ) && ( V_1200 -> V_258 & V_1227 ) )
F_609 ( V_82 , V_1200 -> V_10 ) ;
F_610 ( V_82 ) ;
}
void F_611 ( struct V_82 * V_82 )
{
F_612 ( V_82 ) ;
}
void F_613 ( struct V_82 * V_82 ,
struct V_700 * V_10 )
{
F_612 ( V_82 ) ;
}
int F_614 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_973 == V_1055 &&
! V_2 -> V_5 . V_6 . V_1034 )
|| ! F_615 ( & V_2 -> V_1228 . V_1229 )
|| F_616 ( V_2 )
|| F_124 ( & V_2 -> V_5 . V_68 ) ||
( F_471 ( V_2 ) &&
F_470 ( V_2 ) ) ;
}
int F_617 ( struct V_1 * V_2 )
{
return F_618 ( V_2 ) == V_1044 ;
}
int F_471 ( struct V_1 * V_2 )
{
return V_56 -> V_1015 ( V_2 ) ;
}
bool F_619 ( struct V_1 * V_2 , unsigned long V_1230 )
{
unsigned long V_1231 = F_398 ( V_2 ) +
F_352 ( V_2 , V_1096 ) ;
return V_1231 == V_1230 ;
}
unsigned long F_397 ( struct V_1 * V_2 )
{
unsigned long V_1094 ;
V_1094 = V_56 -> V_1232 ( V_2 ) ;
if ( V_2 -> V_149 & V_1136 )
V_1094 &= ~ V_1233 ;
return V_1094 ;
}
void F_368 ( struct V_1 * V_2 , unsigned long V_1094 )
{
if ( V_2 -> V_149 & V_1136 &&
F_619 ( V_2 , V_2 -> V_5 . V_1137 ) )
V_1094 |= V_1233 ;
V_56 -> V_1234 ( V_2 , V_1094 ) ;
F_25 ( V_48 , V_2 ) ;
}
void F_620 ( struct V_1 * V_2 , struct V_1235 * V_956 )
{
int V_100 ;
if ( ( V_2 -> V_5 . V_67 . V_899 != V_956 -> V_5 . V_899 ) ||
F_339 ( V_956 -> V_353 ) )
return;
V_100 = F_499 ( V_2 ) ;
if ( F_76 ( V_100 ) )
return;
if ( ! V_2 -> V_5 . V_67 . V_899 &&
V_956 -> V_5 . V_85 != V_2 -> V_5 . V_67 . V_1236 ( V_2 ) )
return;
V_2 -> V_5 . V_67 . V_1237 ( V_2 , V_956 -> V_767 , 0 , true ) ;
}
static inline T_1 F_621 ( T_4 V_83 )
{
return F_622 ( V_83 & 0xffffffff , F_623 ( V_4 ) ) ;
}
static inline T_1 F_624 ( T_1 V_1238 )
{
return ( V_1238 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_625 ( struct V_1 * V_2 , T_4 V_83 )
{
T_1 V_1238 = F_621 ( V_83 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1238 ] != ~ 0 )
V_1238 = F_624 ( V_1238 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1238 ] = V_83 ;
}
static T_1 F_626 ( struct V_1 * V_2 , T_4 V_83 )
{
int V_3 ;
T_1 V_1238 = F_621 ( V_83 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1238 ] != V_83 &&
V_2 -> V_5 . V_6 . V_7 [ V_1238 ] != ~ 0 ) ; V_3 ++ )
V_1238 = F_624 ( V_1238 ) ;
return V_1238 ;
}
bool F_627 ( struct V_1 * V_2 , T_4 V_83 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_626 ( V_2 , V_83 ) ] == V_83 ;
}
static void F_628 ( struct V_1 * V_2 , T_4 V_83 )
{
T_1 V_3 , V_754 , V_1239 ;
V_3 = V_754 = F_626 ( V_2 , V_83 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_754 = F_624 ( V_754 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_754 ] == ~ 0 )
return;
V_1239 = F_621 ( V_2 -> V_5 . V_6 . V_7 [ V_754 ] ) ;
} while ( ( V_3 <= V_754 ) ? ( V_3 < V_1239 && V_1239 <= V_754 ) : ( V_3 < V_1239 || V_1239 <= V_754 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_754 ] ;
V_3 = V_754 ;
}
}
static int F_629 ( struct V_1 * V_2 , T_1 V_156 )
{
return F_154 ( V_2 -> V_82 , & V_2 -> V_5 . V_6 . V_31 , & V_156 ,
sizeof( V_156 ) ) ;
}
void F_630 ( struct V_1 * V_2 ,
struct V_1235 * V_956 )
{
struct V_58 V_59 ;
F_631 ( V_956 -> V_5 . V_1240 , V_956 -> V_767 ) ;
F_625 ( V_2 , V_956 -> V_5 . V_83 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_378 & V_379 ) ||
( V_2 -> V_5 . V_6 . V_380 &&
V_56 -> V_71 ( V_2 ) == 0 ) )
F_25 ( V_1033 , V_2 ) ;
else if ( ! F_629 ( V_2 , V_1241 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_864 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_956 -> V_5 . V_1240 ;
F_30 ( V_2 , & V_59 ) ;
}
}
void F_632 ( struct V_1 * V_2 ,
struct V_1235 * V_956 )
{
struct V_58 V_59 ;
F_633 ( V_956 -> V_5 . V_1240 , V_956 -> V_767 ) ;
if ( F_339 ( V_956 -> V_353 ) )
V_956 -> V_5 . V_1240 = ~ 0 ;
else
F_628 ( V_2 , V_956 -> V_5 . V_83 ) ;
if ( ( V_2 -> V_5 . V_6 . V_378 & V_379 ) &&
! F_629 ( V_2 , V_1242 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_864 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_956 -> V_5 . V_1240 ;
F_30 ( V_2 , & V_59 ) ;
}
V_2 -> V_5 . V_6 . V_1034 = false ;
V_2 -> V_5 . V_973 = V_1055 ;
}
bool F_634 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_378 & V_379 ) )
return true ;
else
return ! F_473 ( V_2 ) &&
V_56 -> V_1015 ( V_2 ) ;
}
