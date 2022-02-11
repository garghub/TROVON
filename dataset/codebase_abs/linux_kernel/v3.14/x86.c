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
int F_19 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
T_2 V_33 = V_2 -> V_5 . V_30 &
( V_34 | V_35 ) ;
T_2 V_36 = V_32 -> V_37 &
( V_34 | V_35 ) ;
T_2 V_38 = ( ( ~ 0ULL ) << F_20 ( V_2 ) ) |
0x2ff | ( F_21 ( V_2 ) ? 0 : V_35 ) ;
if ( ! V_32 -> V_39 &&
( ( V_32 -> V_37 & V_38 ) != 0 ||
V_36 == V_35 ||
( V_36 == V_34 &&
V_33 == ( V_34 | V_35 ) ) ||
( V_36 == ( V_34 | V_35 ) &&
V_33 == 0 ) ) )
return 1 ;
F_22 ( V_2 , V_32 -> V_37 ) ;
return 0 ;
}
T_3 void F_23 ( void )
{
F_24 () ;
}
static int F_25 ( int V_40 )
{
switch ( V_40 ) {
case V_41 :
return V_42 ;
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
return V_48 ;
default:
break;
}
return V_49 ;
}
static void F_26 ( struct V_1 * V_2 ,
unsigned V_16 , bool V_50 , T_1 V_51 ,
bool V_52 )
{
T_1 V_53 ;
int V_54 , V_55 ;
F_27 ( V_56 , V_2 ) ;
if ( ! V_2 -> V_5 . V_57 . V_58 ) {
V_59:
V_2 -> V_5 . V_57 . V_58 = true ;
V_2 -> V_5 . V_57 . V_60 = V_50 ;
V_2 -> V_5 . V_57 . V_16 = V_16 ;
V_2 -> V_5 . V_57 . V_51 = V_51 ;
V_2 -> V_5 . V_57 . V_52 = V_52 ;
return;
}
V_53 = V_2 -> V_5 . V_57 . V_16 ;
if ( V_53 == V_61 ) {
F_27 ( V_62 , V_2 ) ;
return;
}
V_54 = F_25 ( V_53 ) ;
V_55 = F_25 ( V_16 ) ;
if ( ( V_54 == V_48 && V_55 == V_48 )
|| ( V_54 == V_42 && V_55 != V_49 ) ) {
V_2 -> V_5 . V_57 . V_58 = true ;
V_2 -> V_5 . V_57 . V_60 = true ;
V_2 -> V_5 . V_57 . V_16 = V_61 ;
V_2 -> V_5 . V_57 . V_51 = 0 ;
} else
goto V_59;
}
void F_28 ( struct V_1 * V_2 , unsigned V_16 )
{
F_26 ( V_2 , V_16 , false , 0 , false ) ;
}
void F_29 ( struct V_1 * V_2 , unsigned V_16 )
{
F_26 ( V_2 , V_16 , false , 0 , true ) ;
}
void F_30 ( struct V_1 * V_2 , int V_63 )
{
if ( V_63 )
F_31 ( V_2 , 0 ) ;
else
V_64 -> V_65 ( V_2 ) ;
}
void F_32 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
++ V_2 -> V_68 . V_69 ;
V_2 -> V_5 . V_70 = V_67 -> V_71 ;
F_33 ( V_2 , V_41 , V_67 -> V_51 ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
if ( F_35 ( V_2 ) && ! V_67 -> V_72 )
V_2 -> V_5 . V_73 . V_74 ( V_2 , V_67 ) ;
else
V_2 -> V_5 . V_75 . V_74 ( V_2 , V_67 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_5 . V_76 ) ;
F_27 ( V_77 , V_2 ) ;
}
void F_33 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_51 )
{
F_26 ( V_2 , V_16 , true , V_51 , false ) ;
}
void F_38 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_51 )
{
F_26 ( V_2 , V_16 , true , V_51 , true ) ;
}
bool F_39 ( struct V_1 * V_2 , int V_78 )
{
if ( V_64 -> V_79 ( V_2 ) <= V_78 )
return true ;
F_33 ( V_2 , V_47 , 0 ) ;
return false ;
}
int F_40 ( struct V_1 * V_2 , struct V_80 * V_75 ,
T_4 V_81 , void * V_37 , int V_82 , int V_83 ,
T_1 V_84 )
{
T_4 V_85 ;
T_5 V_86 ;
V_86 = F_41 ( V_81 ) ;
V_85 = V_75 -> V_87 ( V_2 , V_86 , V_84 ) ;
if ( V_85 == V_88 )
return - V_89 ;
V_85 = F_42 ( V_85 ) ;
return F_43 ( V_2 -> V_90 , V_85 , V_37 , V_82 , V_83 ) ;
}
int F_44 ( struct V_1 * V_2 , T_4 V_91 ,
void * V_37 , int V_82 , int V_83 , T_1 V_84 )
{
return F_40 ( V_2 , V_2 -> V_5 . V_92 , V_91 ,
V_37 , V_82 , V_83 , V_84 ) ;
}
int F_45 ( struct V_1 * V_2 , struct V_80 * V_75 , unsigned long V_93 )
{
T_4 V_94 = V_93 >> V_95 ;
unsigned V_82 = ( ( V_93 & ( V_96 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_97 ;
T_2 V_98 [ F_46 ( V_75 -> V_99 ) ] ;
V_97 = F_40 ( V_2 , V_75 , V_94 , V_98 ,
V_82 * sizeof( T_2 ) , sizeof( V_98 ) ,
V_100 | V_101 ) ;
if ( V_97 < 0 ) {
V_97 = 0 ;
goto V_102;
}
for ( V_3 = 0 ; V_3 < F_46 ( V_98 ) ; ++ V_3 ) {
if ( F_47 ( V_98 [ V_3 ] ) &&
( V_98 [ V_3 ] & V_2 -> V_5 . V_75 . V_103 [ 0 ] [ 2 ] ) ) {
V_97 = 0 ;
goto V_102;
}
}
V_97 = 1 ;
memcpy ( V_75 -> V_99 , V_98 , sizeof( V_75 -> V_99 ) ) ;
F_48 ( V_104 ,
( unsigned long * ) & V_2 -> V_5 . V_105 ) ;
F_48 ( V_104 ,
( unsigned long * ) & V_2 -> V_5 . V_106 ) ;
V_102:
return V_97 ;
}
static bool F_49 ( struct V_1 * V_2 )
{
T_2 V_98 [ F_46 ( V_2 -> V_5 . V_92 -> V_99 ) ] ;
bool V_107 = true ;
int V_82 ;
T_4 V_91 ;
int V_108 ;
if ( F_50 ( V_2 ) || ! F_51 ( V_2 ) )
return false ;
if ( ! F_52 ( V_104 ,
( unsigned long * ) & V_2 -> V_5 . V_105 ) )
return true ;
V_91 = ( F_53 ( V_2 ) & ~ 31u ) >> V_95 ;
V_82 = ( F_53 ( V_2 ) & ~ 31u ) & ( V_96 - 1 ) ;
V_108 = F_44 ( V_2 , V_91 , V_98 , V_82 , sizeof( V_98 ) ,
V_100 | V_101 ) ;
if ( V_108 < 0 )
goto V_102;
V_107 = memcmp ( V_98 , V_2 -> V_5 . V_92 -> V_99 , sizeof( V_98 ) ) != 0 ;
V_102:
return V_107 ;
}
int F_54 ( struct V_1 * V_2 , unsigned long V_109 )
{
unsigned long V_110 = F_55 ( V_2 ) ;
unsigned long V_111 = V_112 | V_113 |
V_114 | V_115 ;
V_109 |= V_116 ;
#ifdef F_56
if ( V_109 & 0xffffffff00000000UL )
return 1 ;
#endif
V_109 &= ~ V_117 ;
if ( ( V_109 & V_115 ) && ! ( V_109 & V_114 ) )
return 1 ;
if ( ( V_109 & V_112 ) && ! ( V_109 & V_118 ) )
return 1 ;
if ( ! F_57 ( V_2 ) && ( V_109 & V_112 ) ) {
#ifdef F_56
if ( ( V_2 -> V_5 . V_119 & V_120 ) ) {
int V_121 , V_122 ;
if ( ! F_51 ( V_2 ) )
return 1 ;
V_64 -> V_123 ( V_2 , & V_121 , & V_122 ) ;
if ( V_122 )
return 1 ;
} else
#endif
if ( F_51 ( V_2 ) && ! F_45 ( V_2 , V_2 -> V_5 . V_92 ,
F_53 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_109 & V_112 ) && F_58 ( V_2 , V_124 ) )
return 1 ;
V_64 -> V_125 ( V_2 , V_109 ) ;
if ( ( V_109 ^ V_110 ) & V_112 ) {
F_59 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_109 ^ V_110 ) & V_111 )
F_60 ( V_2 ) ;
return 0 ;
}
void F_61 ( struct V_1 * V_2 , unsigned long V_126 )
{
( void ) F_54 ( V_2 , F_62 ( V_2 , ~ 0x0eul ) | ( V_126 & 0x0f ) ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
if ( F_58 ( V_2 , V_127 ) &&
! V_2 -> V_128 ) {
F_64 ( V_129 , V_2 -> V_5 . V_130 ) ;
V_2 -> V_128 = 1 ;
}
}
static void F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_128 ) {
if ( V_2 -> V_5 . V_130 != V_131 )
F_64 ( V_129 , V_131 ) ;
V_2 -> V_128 = 0 ;
}
}
int F_66 ( struct V_1 * V_2 , T_1 V_132 , T_2 V_133 )
{
T_2 V_130 ;
T_2 V_134 ;
if ( V_132 != V_129 )
return 1 ;
V_130 = V_133 ;
if ( ! ( V_130 & V_135 ) )
return 1 ;
if ( ( V_130 & V_136 ) && ! ( V_130 & V_137 ) )
return 1 ;
V_134 = V_2 -> V_5 . V_138 | V_135 ;
if ( V_130 & ~ V_134 )
return 1 ;
F_65 ( V_2 ) ;
V_2 -> V_5 . V_130 = V_130 ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 , T_1 V_132 , T_2 V_133 )
{
if ( V_64 -> V_79 ( V_2 ) != 0 ||
F_66 ( V_2 , V_132 , V_133 ) ) {
F_31 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_68 ( struct V_1 * V_2 , unsigned long V_139 )
{
unsigned long V_140 = F_69 ( V_2 ) ;
unsigned long V_141 = V_142 | V_143 |
V_144 | V_145 ;
if ( V_139 & V_146 )
return 1 ;
if ( ! F_70 ( V_2 ) && ( V_139 & V_127 ) )
return 1 ;
if ( ! F_71 ( V_2 ) && ( V_139 & V_145 ) )
return 1 ;
if ( ! F_72 ( V_2 ) && ( V_139 & V_147 ) )
return 1 ;
if ( F_50 ( V_2 ) ) {
if ( ! ( V_139 & V_144 ) )
return 1 ;
} else if ( F_57 ( V_2 ) && ( V_139 & V_144 )
&& ( ( V_139 ^ V_140 ) & V_141 )
&& ! F_45 ( V_2 , V_2 -> V_5 . V_92 ,
F_53 ( V_2 ) ) )
return 1 ;
if ( ( V_139 & V_124 ) && ! ( V_140 & V_124 ) ) {
if ( ! F_73 ( V_2 ) )
return 1 ;
if ( ( F_53 ( V_2 ) & V_148 ) || ! F_50 ( V_2 ) )
return 1 ;
}
if ( V_64 -> V_149 ( V_2 , V_139 ) )
return 1 ;
if ( ( ( V_139 ^ V_140 ) & V_141 ) ||
( ! ( V_139 & V_124 ) && ( V_140 & V_124 ) ) )
F_60 ( V_2 ) ;
if ( ( V_139 ^ V_140 ) & V_127 )
F_74 ( V_2 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 , unsigned long V_93 )
{
if ( V_93 == F_53 ( V_2 ) && ! F_49 ( V_2 ) ) {
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
return 0 ;
}
if ( F_50 ( V_2 ) ) {
if ( F_58 ( V_2 , V_124 ) ) {
if ( V_93 & V_150 )
return 1 ;
} else
if ( V_93 & V_151 )
return 1 ;
} else {
if ( F_51 ( V_2 ) ) {
if ( V_93 & V_152 )
return 1 ;
if ( F_57 ( V_2 ) &&
! F_45 ( V_2 , V_2 -> V_5 . V_92 , V_93 ) )
return 1 ;
}
}
V_2 -> V_5 . V_93 = V_93 ;
F_48 ( V_153 , ( V_154 * ) & V_2 -> V_5 . V_105 ) ;
F_78 ( V_2 ) ;
return 0 ;
}
int F_79 ( struct V_1 * V_2 , unsigned long V_155 )
{
if ( V_155 & V_156 )
return 1 ;
if ( F_80 ( V_2 -> V_90 ) )
F_81 ( V_2 , V_155 ) ;
else
V_2 -> V_5 . V_155 = V_155 ;
return 0 ;
}
unsigned long F_82 ( struct V_1 * V_2 )
{
if ( F_80 ( V_2 -> V_90 ) )
return F_83 ( V_2 ) ;
else
return V_2 -> V_5 . V_155 ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_157 & V_158 ) )
V_64 -> V_159 ( V_2 , V_2 -> V_5 . V_160 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
unsigned long V_161 ;
if ( V_2 -> V_157 & V_158 )
V_161 = V_2 -> V_5 . V_162 ;
else
V_161 = V_2 -> V_5 . V_161 ;
V_64 -> V_163 ( V_2 , V_161 ) ;
V_2 -> V_5 . V_164 = ( V_161 & V_165 ) ;
}
static int F_86 ( struct V_1 * V_2 , int V_166 , unsigned long V_167 )
{
switch ( V_166 ) {
case 0 ... 3 :
V_2 -> V_5 . V_168 [ V_166 ] = V_167 ;
if ( ! ( V_2 -> V_157 & V_158 ) )
V_2 -> V_5 . V_169 [ V_166 ] = V_167 ;
break;
case 4 :
if ( F_58 ( V_2 , V_170 ) )
return 1 ;
case 6 :
if ( V_167 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_160 = ( V_167 & V_171 ) | V_172 ;
F_84 ( V_2 ) ;
break;
case 5 :
if ( F_58 ( V_2 , V_170 ) )
return 1 ;
default:
if ( V_167 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_161 = ( V_167 & V_173 ) | V_174 ;
F_85 ( V_2 ) ;
break;
}
return 0 ;
}
int F_87 ( struct V_1 * V_2 , int V_166 , unsigned long V_167 )
{
int V_175 ;
V_175 = F_86 ( V_2 , V_166 , V_167 ) ;
if ( V_175 > 0 )
F_28 ( V_2 , V_176 ) ;
else if ( V_175 < 0 )
F_31 ( V_2 , 0 ) ;
return V_175 ;
}
static int F_88 ( struct V_1 * V_2 , int V_166 , unsigned long * V_167 )
{
switch ( V_166 ) {
case 0 ... 3 :
* V_167 = V_2 -> V_5 . V_168 [ V_166 ] ;
break;
case 4 :
if ( F_58 ( V_2 , V_170 ) )
return 1 ;
case 6 :
if ( V_2 -> V_157 & V_158 )
* V_167 = V_2 -> V_5 . V_160 ;
else
* V_167 = V_64 -> V_177 ( V_2 ) ;
break;
case 5 :
if ( F_58 ( V_2 , V_170 ) )
return 1 ;
default:
* V_167 = V_2 -> V_5 . V_161 ;
break;
}
return 0 ;
}
int F_89 ( struct V_1 * V_2 , int V_166 , unsigned long * V_167 )
{
if ( F_88 ( V_2 , V_166 , V_167 ) ) {
F_28 ( V_2 , V_176 ) ;
return 1 ;
}
return 0 ;
}
bool F_90 ( struct V_1 * V_2 )
{
T_1 V_178 = F_91 ( V_2 , V_179 ) ;
T_2 V_37 ;
int V_63 ;
V_63 = F_92 ( V_2 , V_178 , & V_37 ) ;
if ( V_63 )
return V_63 ;
F_93 ( V_2 , V_180 , ( T_1 ) V_37 ) ;
F_93 ( V_2 , V_181 , V_37 >> 32 ) ;
return V_63 ;
}
bool F_94 ( struct V_1 * V_2 , T_2 V_119 )
{
if ( V_119 & V_182 )
return false ;
if ( V_119 & V_183 ) {
struct V_184 * V_185 ;
V_185 = F_95 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_185 || ! ( V_185 -> V_186 & F_96 ( V_187 ) ) )
return false ;
}
if ( V_119 & V_188 ) {
struct V_184 * V_185 ;
V_185 = F_95 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_185 || ! ( V_185 -> V_178 & F_96 ( V_189 ) ) )
return false ;
}
return true ;
}
static int F_97 ( struct V_1 * V_2 , T_2 V_119 )
{
T_2 V_190 = V_2 -> V_5 . V_119 ;
if ( ! F_94 ( V_2 , V_119 ) )
return 1 ;
if ( F_57 ( V_2 )
&& ( V_2 -> V_5 . V_119 & V_120 ) != ( V_119 & V_120 ) )
return 1 ;
V_119 &= ~ V_191 ;
V_119 |= V_2 -> V_5 . V_119 & V_191 ;
V_64 -> F_97 ( V_2 , V_119 ) ;
if ( ( V_119 ^ V_190 ) & V_192 )
F_60 ( V_2 ) ;
return 0 ;
}
void F_98 ( T_2 V_27 )
{
V_182 &= ~ V_27 ;
}
int F_99 ( struct V_1 * V_2 , struct V_31 * V_21 )
{
return V_64 -> V_193 ( V_2 , V_21 ) ;
}
static int F_100 ( struct V_1 * V_2 , unsigned V_132 , T_2 * V_37 )
{
struct V_31 V_21 ;
V_21 . V_37 = * V_37 ;
V_21 . V_132 = V_132 ;
V_21 . V_39 = true ;
return F_99 ( V_2 , & V_21 ) ;
}
static void F_101 ( struct V_194 * V_195 )
{
struct V_196 * V_197 = & V_196 ;
F_102 ( & V_197 -> V_198 ) ;
V_197 -> clock . V_199 = V_195 -> clock -> V_200 . V_199 ;
V_197 -> clock . V_201 = V_195 -> clock -> V_201 ;
V_197 -> clock . V_27 = V_195 -> clock -> V_27 ;
V_197 -> clock . V_202 = V_195 -> V_202 ;
V_197 -> clock . V_203 = V_195 -> V_203 ;
V_197 -> V_204 = V_195 -> V_205
+ V_195 -> V_206 . V_207 ;
V_197 -> V_208 = V_195 -> V_209
+ ( V_195 -> V_206 . V_210
<< V_195 -> V_203 ) ;
while ( V_197 -> V_208 >=
( ( ( T_2 ) V_211 ) << V_195 -> V_203 ) ) {
V_197 -> V_208 -=
( ( T_2 ) V_211 ) << V_195 -> V_203 ;
V_197 -> V_204 ++ ;
}
F_103 ( & V_197 -> V_198 ) ;
}
static void F_104 ( struct V_90 * V_90 , T_5 V_212 )
{
int V_213 ;
int V_108 ;
struct V_214 V_215 ;
struct V_216 V_217 ;
if ( ! V_212 )
return;
V_108 = F_105 ( V_90 , V_212 , & V_213 , sizeof( V_213 ) ) ;
if ( V_108 )
return;
if ( V_213 & 1 )
++ V_213 ;
++ V_213 ;
F_106 ( V_90 , V_212 , & V_213 , sizeof( V_213 ) ) ;
F_107 ( & V_217 ) ;
if ( V_90 -> V_5 . V_218 ) {
struct V_216 V_219 = F_108 ( V_90 -> V_5 . V_218 ) ;
V_217 = F_109 ( V_217 , V_219 ) ;
}
V_215 . V_220 = V_217 . V_207 ;
V_215 . V_221 = V_217 . V_210 ;
V_215 . V_213 = V_213 ;
F_106 ( V_90 , V_212 , & V_215 , sizeof( V_215 ) ) ;
V_213 ++ ;
F_106 ( V_90 , V_212 , & V_213 , sizeof( V_213 ) ) ;
}
static T_6 F_110 ( T_6 V_222 , T_6 V_223 )
{
T_6 V_224 , V_225 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_224 ;
}
static void F_111 ( T_6 V_226 , T_6 V_227 ,
T_7 * V_228 , T_1 * V_229 )
{
T_8 V_230 ;
T_9 V_203 = 0 ;
T_8 V_231 ;
T_6 V_232 ;
V_231 = V_227 * 1000LL ;
V_230 = V_226 * 1000LL ;
while ( V_231 > V_230 * 2 || V_231 & 0xffffffff00000000ULL ) {
V_231 >>= 1 ;
V_203 -- ;
}
V_232 = ( T_6 ) V_231 ;
while ( V_232 <= V_230 || V_230 & 0xffffffff00000000ULL ) {
if ( V_230 & 0xffffffff00000000ULL || V_232 & 0x80000000 )
V_230 >>= 1 ;
else
V_232 <<= 1 ;
V_203 ++ ;
}
* V_228 = V_203 ;
* V_229 = F_110 ( V_230 , V_232 ) ;
F_112 ( L_2 ,
V_233 , V_227 , V_226 , V_203 , * V_229 ) ;
}
static inline T_2 F_113 ( void )
{
struct V_216 V_219 ;
F_114 ( F_115 () ) ;
F_116 ( & V_219 ) ;
F_117 ( & V_219 ) ;
return F_118 ( & V_219 ) ;
}
static inline T_2 F_119 ( struct V_1 * V_2 , T_2 V_221 )
{
return F_120 ( V_221 , V_2 -> V_5 . V_234 ,
V_2 -> V_5 . V_235 ) ;
}
static T_1 F_121 ( T_1 V_236 , T_10 V_237 )
{
T_2 V_238 = ( T_2 ) V_236 * ( 1000000 + V_237 ) ;
F_122 ( V_238 , 1000000 ) ;
return V_238 ;
}
static void F_123 ( struct V_1 * V_2 , T_1 V_239 )
{
T_1 V_240 , V_241 ;
int V_242 = 0 ;
if ( V_239 == 0 )
return;
F_111 ( V_239 , V_211 / 1000 ,
& V_2 -> V_5 . V_235 ,
& V_2 -> V_5 . V_234 ) ;
V_2 -> V_5 . V_243 = V_239 ;
V_240 = F_121 ( V_244 , - V_245 ) ;
V_241 = F_121 ( V_244 , V_245 ) ;
if ( V_239 < V_240 || V_239 > V_241 ) {
F_112 ( L_3 , V_239 , V_240 , V_241 ) ;
V_242 = 1 ;
}
V_64 -> V_246 ( V_2 , V_239 , V_242 ) ;
}
static T_2 F_124 ( struct V_1 * V_2 , T_11 V_247 )
{
T_2 V_248 = F_120 ( V_247 - V_2 -> V_5 . V_249 ,
V_2 -> V_5 . V_234 ,
V_2 -> V_5 . V_235 ) ;
V_248 += V_2 -> V_5 . V_250 ;
return V_248 ;
}
void F_125 ( struct V_1 * V_2 )
{
#ifdef F_56
bool V_251 ;
bool V_252 = false ;
struct V_253 * V_254 = & V_2 -> V_90 -> V_5 ;
struct V_196 * V_255 = & V_196 ;
V_251 = ( V_254 -> V_256 + 1 ==
F_126 ( & V_2 -> V_90 -> V_257 ) ) ;
if ( V_251 && V_255 -> clock . V_199 == V_258 )
if ( ! V_254 -> V_259 )
V_252 = 1 ;
if ( ! V_251 && V_254 -> V_259 )
V_252 = 1 ;
if ( V_252 )
F_27 ( V_260 , V_2 ) ;
F_127 ( V_2 -> V_261 , V_254 -> V_256 ,
F_126 ( & V_2 -> V_90 -> V_257 ) ,
V_254 -> V_259 , V_255 -> clock . V_199 ) ;
#endif
}
static void F_128 ( struct V_1 * V_2 , T_11 V_82 )
{
T_2 V_262 = V_64 -> V_263 ( V_2 ) ;
V_2 -> V_5 . V_264 += V_82 - V_262 ;
}
void F_129 ( struct V_1 * V_2 , struct V_31 * V_21 )
{
struct V_90 * V_90 = V_2 -> V_90 ;
T_2 V_82 , V_265 , V_266 ;
unsigned long V_267 ;
T_11 V_268 ;
bool V_269 ;
T_2 V_37 = V_21 -> V_37 ;
F_130 ( & V_90 -> V_5 . V_270 , V_267 ) ;
V_82 = V_64 -> V_271 ( V_2 , V_37 ) ;
V_265 = F_113 () ;
V_266 = V_265 - V_90 -> V_5 . V_272 ;
if ( V_2 -> V_5 . V_243 ) {
int V_273 = 0 ;
V_268 = V_37 - V_90 -> V_5 . V_274 ;
#ifdef F_56
V_268 = ( V_268 * 1000 ) / V_2 -> V_5 . V_243 ;
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
F_122 ( V_266 , 1000 ) ;
V_268 -= V_266 ;
if ( V_268 < 0 )
V_268 = - V_268 ;
if ( V_273 )
V_268 = V_275 ;
} else
V_268 = V_275 ;
if ( V_268 < V_275 &&
V_2 -> V_5 . V_243 == V_90 -> V_5 . V_276 ) {
if ( ! F_131 () ) {
V_82 = V_90 -> V_5 . V_277 ;
F_112 ( L_4 , V_37 ) ;
} else {
T_2 V_278 = F_119 ( V_2 , V_266 ) ;
V_37 += V_278 ;
V_82 = V_64 -> V_271 ( V_2 , V_37 ) ;
F_112 ( L_5 , V_278 ) ;
}
V_269 = true ;
} else {
V_90 -> V_5 . V_279 ++ ;
V_90 -> V_5 . V_280 = V_265 ;
V_90 -> V_5 . V_281 = V_37 ;
V_90 -> V_5 . V_277 = V_82 ;
V_269 = false ;
F_112 ( L_6 ,
V_90 -> V_5 . V_279 , V_37 ) ;
}
V_90 -> V_5 . V_272 = V_265 ;
V_90 -> V_5 . V_274 = V_37 ;
V_90 -> V_5 . V_276 = V_2 -> V_5 . V_243 ;
V_2 -> V_5 . V_282 = V_37 ;
V_2 -> V_5 . V_283 = V_90 -> V_5 . V_279 ;
V_2 -> V_5 . V_249 = V_90 -> V_5 . V_280 ;
V_2 -> V_5 . V_250 = V_90 -> V_5 . V_281 ;
if ( F_132 ( V_2 ) && ! V_21 -> V_39 )
F_128 ( V_2 , V_82 ) ;
V_64 -> V_284 ( V_2 , V_82 ) ;
F_133 ( & V_90 -> V_5 . V_270 , V_267 ) ;
F_134 ( & V_90 -> V_5 . V_285 ) ;
if ( V_269 )
V_90 -> V_5 . V_256 ++ ;
else
V_90 -> V_5 . V_256 = 0 ;
F_125 ( V_2 ) ;
F_135 ( & V_90 -> V_5 . V_285 ) ;
}
static T_12 F_136 ( void )
{
T_12 V_97 ;
T_2 V_286 ;
F_137 () ;
V_97 = ( T_12 ) F_138 () ;
V_286 = V_196 . clock . V_201 ;
if ( F_139 ( V_97 >= V_286 ) )
return V_97 ;
asm volatile ("");
return V_286 ;
}
static inline T_2 F_140 ( T_12 * V_287 )
{
long V_238 ;
struct V_196 * V_255 = & V_196 ;
* V_287 = F_136 () ;
V_238 = ( * V_287 - V_255 -> clock . V_201 ) & V_255 -> clock . V_27 ;
return V_238 * V_255 -> clock . V_202 ;
}
static int F_141 ( struct V_216 * V_219 , T_12 * V_287 )
{
unsigned long V_198 ;
T_2 V_265 ;
int V_288 ;
struct V_196 * V_255 = & V_196 ;
V_219 -> V_210 = 0 ;
do {
V_198 = F_142 ( & V_255 -> V_198 ) ;
V_288 = V_255 -> clock . V_199 ;
V_219 -> V_207 = V_255 -> V_204 ;
V_265 = V_255 -> V_208 ;
V_265 += F_140 ( V_287 ) ;
V_265 >>= V_255 -> clock . V_203 ;
} while ( F_143 ( F_144 ( & V_255 -> V_198 , V_198 ) ) );
F_145 ( V_219 , V_265 ) ;
return V_288 ;
}
static bool F_146 ( T_11 * V_247 , T_12 * V_287 )
{
struct V_216 V_219 ;
if ( V_196 . clock . V_199 != V_258 )
return false ;
if ( F_141 ( & V_219 , V_287 ) != V_258 )
return false ;
F_117 ( & V_219 ) ;
* V_247 = F_118 ( & V_219 ) ;
return true ;
}
static void F_147 ( struct V_90 * V_90 )
{
#ifdef F_56
struct V_253 * V_254 = & V_90 -> V_5 ;
int V_199 ;
bool V_289 , V_251 ;
V_251 = ( V_254 -> V_256 + 1 ==
F_126 ( & V_90 -> V_257 ) ) ;
V_289 = F_146 (
& V_254 -> V_290 ,
& V_254 -> V_291 ) ;
V_254 -> V_259 = V_289 & V_251 ;
if ( V_254 -> V_259 )
F_148 ( & V_292 , 1 ) ;
V_199 = V_196 . clock . V_199 ;
F_149 ( V_254 -> V_259 , V_199 ,
V_251 ) ;
#endif
}
static void F_150 ( struct V_90 * V_90 )
{
#ifdef F_56
int V_3 ;
struct V_1 * V_2 ;
struct V_253 * V_254 = & V_90 -> V_5 ;
F_134 ( & V_254 -> V_285 ) ;
F_151 ( V_90 ) ;
F_147 ( V_90 ) ;
F_152 (i, vcpu, kvm)
F_153 ( V_293 , & V_2 -> V_294 ) ;
F_152 (i, vcpu, kvm)
F_154 ( V_295 , & V_2 -> V_294 ) ;
F_135 ( & V_254 -> V_285 ) ;
#endif
}
static int F_155 ( struct V_1 * V_238 )
{
unsigned long V_267 , V_239 ;
struct V_296 * V_2 = & V_238 -> V_5 ;
struct V_253 * V_254 = & V_238 -> V_90 -> V_5 ;
T_11 V_247 ;
T_2 V_297 , V_298 ;
struct V_299 V_300 ;
T_13 V_301 ;
bool V_259 ;
V_247 = 0 ;
V_298 = 0 ;
F_134 ( & V_254 -> V_285 ) ;
V_259 = V_254 -> V_259 ;
if ( V_259 ) {
V_298 = V_254 -> V_291 ;
V_247 = V_254 -> V_290 ;
}
F_135 ( & V_254 -> V_285 ) ;
F_156 ( V_267 ) ;
V_239 = F_157 ( V_302 ) ;
if ( F_143 ( V_239 == 0 ) ) {
F_158 ( V_267 ) ;
F_27 ( V_293 , V_238 ) ;
return 1 ;
}
if ( ! V_259 ) {
V_298 = F_159 () ;
V_247 = F_113 () ;
}
V_297 = V_64 -> V_303 ( V_238 , V_298 ) ;
if ( V_2 -> V_304 ) {
T_2 V_248 = F_124 ( V_238 , V_247 ) ;
if ( V_248 > V_297 ) {
F_160 ( V_238 , V_248 - V_297 ) ;
V_297 = V_248 ;
}
}
F_158 ( V_267 ) ;
if ( ! V_2 -> V_305 )
return 0 ;
if ( F_143 ( V_2 -> V_306 != V_239 ) ) {
F_111 ( V_211 / 1000 , V_239 ,
& V_2 -> V_307 . V_308 ,
& V_2 -> V_307 . V_309 ) ;
V_2 -> V_306 = V_239 ;
}
V_2 -> V_307 . V_297 = V_297 ;
V_2 -> V_307 . V_310 = V_247 + V_238 -> V_90 -> V_5 . V_218 ;
V_2 -> V_311 = V_247 ;
V_2 -> V_282 = V_297 ;
V_2 -> V_307 . V_213 += 2 ;
if ( F_143 ( F_161 ( V_238 -> V_90 , & V_2 -> V_312 ,
& V_300 , sizeof( V_300 ) ) ) )
return 0 ;
V_301 = ( V_300 . V_267 & V_313 ) ;
if ( V_2 -> V_314 ) {
V_301 |= V_313 ;
V_2 -> V_314 = false ;
}
if ( V_259 )
V_301 |= V_315 ;
V_2 -> V_307 . V_267 = V_301 ;
F_162 ( V_238 -> V_90 , & V_2 -> V_312 ,
& V_2 -> V_307 ,
sizeof( V_2 -> V_307 ) ) ;
return 0 ;
}
static void F_163 ( struct V_1 * V_238 )
{
int V_3 ;
struct V_90 * V_90 = V_238 -> V_90 ;
struct V_1 * V_2 ;
F_152 (i, vcpu, kvm) {
F_153 ( V_293 , & V_2 -> V_294 ) ;
F_164 ( V_2 ) ;
}
}
static bool F_165 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_316 - 1 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_166 ( unsigned V_330 )
{
return V_330 < 8 && ( 1 << V_330 ) & 0xf3 ;
}
static bool F_167 ( unsigned V_330 )
{
return V_330 < 8 && ( 1 << V_330 ) & 0x73 ;
}
static bool F_168 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
int V_3 ;
if ( ! F_165 ( V_21 ) )
return false ;
if ( V_21 == V_329 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_166 ( ( V_37 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_328 ) {
if ( V_37 & ~ 0xcff )
return false ;
return F_167 ( V_37 & 0xff ) ;
} else if ( V_21 >= V_317 && V_21 <= V_327 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_167 ( ( V_37 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_167 ( V_37 & 0xff ) ;
}
static int F_169 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
T_2 * V_331 = ( T_2 * ) & V_2 -> V_5 . V_332 . V_333 ;
if ( ! F_168 ( V_2 , V_21 , V_37 ) )
return 1 ;
if ( V_21 == V_328 ) {
V_2 -> V_5 . V_332 . V_334 = V_37 ;
V_2 -> V_5 . V_332 . V_335 = ( V_37 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_317 )
V_331 [ 0 ] = V_37 ;
else if ( V_21 == V_318 || V_21 == V_319 )
V_331 [ 1 + V_21 - V_318 ] = V_37 ;
else if ( V_21 >= V_320 && V_21 <= V_327 )
V_331 [ 3 + V_21 - V_320 ] = V_37 ;
else if ( V_21 == V_329 )
V_2 -> V_5 . V_336 = V_37 ;
else {
int V_337 , V_338 ;
T_2 * V_339 ;
V_337 = ( V_21 - 0x200 ) / 2 ;
V_338 = V_21 - 0x200 - 2 * V_337 ;
if ( ! V_338 )
V_339 =
( T_2 * ) & V_2 -> V_5 . V_332 . V_340 [ V_337 ] . V_341 ;
else
V_339 =
( T_2 * ) & V_2 -> V_5 . V_332 . V_340 [ V_337 ] . V_342 ;
* V_339 = V_37 ;
}
F_60 ( V_2 ) ;
return 0 ;
}
static int F_170 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
T_2 V_343 = V_2 -> V_5 . V_343 ;
unsigned V_344 = V_343 & 0xff ;
switch ( V_21 ) {
case V_345 :
V_2 -> V_5 . V_346 = V_37 ;
break;
case V_347 :
if ( ! ( V_343 & V_348 ) )
return 1 ;
if ( V_37 != 0 && V_37 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_349 = V_37 ;
break;
default:
if ( V_21 >= V_350 &&
V_21 < V_350 + 4 * V_344 ) {
T_1 V_82 = V_21 - V_350 ;
if ( ( V_82 & 0x3 ) == 0 &&
V_37 != 0 && ( V_37 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_351 [ V_82 ] = V_37 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_171 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_90 * V_90 = V_2 -> V_90 ;
int V_352 = F_50 ( V_2 ) ;
T_13 * V_353 = V_352 ? ( T_13 * ) ( long ) V_90 -> V_5 . F_171 . V_354
: ( T_13 * ) ( long ) V_90 -> V_5 . F_171 . V_355 ;
T_13 V_356 = V_352 ? V_90 -> V_5 . F_171 . V_357
: V_90 -> V_5 . F_171 . V_358 ;
T_1 V_359 = V_37 & ~ V_360 ;
T_2 V_361 = V_37 & V_360 ;
T_13 * V_362 ;
int V_108 ;
V_108 = - V_363 ;
if ( V_359 >= V_356 )
goto V_102;
V_108 = - V_364 ;
V_362 = F_172 ( V_353 + ( V_359 * V_96 ) , V_96 ) ;
if ( F_173 ( V_362 ) ) {
V_108 = F_174 ( V_362 ) ;
goto V_102;
}
if ( F_106 ( V_90 , V_361 , V_362 , V_96 ) )
goto V_365;
V_108 = 0 ;
V_365:
F_175 ( V_362 ) ;
V_102:
return V_108 ;
}
static bool F_176 ( struct V_90 * V_90 )
{
return V_90 -> V_5 . V_366 & V_367 ;
}
static bool F_177 ( T_1 V_21 )
{
bool V_108 = false ;
switch ( V_21 ) {
case V_368 :
case V_369 :
case V_370 :
case V_371 :
V_108 = true ;
break;
}
return V_108 ;
}
static int F_178 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
struct V_90 * V_90 = V_2 -> V_90 ;
switch ( V_21 ) {
case V_368 :
V_90 -> V_5 . V_372 = V_37 ;
if ( ! V_90 -> V_5 . V_372 )
V_90 -> V_5 . V_366 &= ~ V_367 ;
break;
case V_369 : {
T_2 V_91 ;
unsigned long V_373 ;
T_13 V_374 [ 4 ] ;
if ( ! V_90 -> V_5 . V_372 )
break;
if ( ! ( V_37 & V_367 ) ) {
V_90 -> V_5 . V_366 = V_37 ;
break;
}
V_91 = V_37 >> V_375 ;
V_373 = F_179 ( V_90 , V_91 ) ;
if ( F_180 ( V_373 ) )
return 1 ;
V_64 -> V_376 ( V_2 , V_374 ) ;
( ( unsigned char * ) V_374 ) [ 3 ] = 0xc3 ;
if ( F_181 ( ( void V_377 * ) V_373 , V_374 , 4 ) )
return 1 ;
V_90 -> V_5 . V_366 = V_37 ;
F_182 ( V_90 , V_91 ) ;
break;
}
case V_370 : {
T_2 V_91 ;
T_14 V_378 ;
memset ( & V_378 , 0 , sizeof( V_378 ) ) ;
V_90 -> V_5 . V_379 = V_37 ;
if ( ! ( V_37 & V_380 ) )
break;
V_91 = V_37 >> V_381 ;
if ( F_106 ( V_90 , V_37 ,
& V_378 , sizeof( V_378 ) ) )
return 1 ;
F_182 ( V_90 , V_91 ) ;
break;
}
default:
F_183 ( V_2 , L_7
L_8 , V_21 , V_37 ) ;
return 1 ;
}
return 0 ;
}
static int F_184 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
switch ( V_21 ) {
case V_382 : {
T_2 V_91 ;
unsigned long V_373 ;
if ( ! ( V_37 & V_383 ) ) {
V_2 -> V_5 . V_384 = V_37 ;
break;
}
V_91 = V_37 >> V_385 ;
V_373 = F_179 ( V_2 -> V_90 , V_91 ) ;
if ( F_180 ( V_373 ) )
return 1 ;
if ( F_185 ( ( void V_377 * ) V_373 , V_96 ) )
return 1 ;
V_2 -> V_5 . V_384 = V_37 ;
F_182 ( V_2 -> V_90 , V_91 ) ;
break;
}
case V_386 :
return F_186 ( V_2 , V_387 , V_37 ) ;
case V_388 :
return F_186 ( V_2 , V_389 , V_37 ) ;
case V_390 :
return F_186 ( V_2 , V_391 , V_37 ) ;
default:
F_183 ( V_2 , L_7
L_8 , V_21 , V_37 ) ;
return 1 ;
}
return 0 ;
}
static int F_187 ( struct V_1 * V_2 , T_2 V_37 )
{
T_5 V_392 = V_37 & ~ 0x3f ;
if ( V_37 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_393 = V_37 ;
if ( ! ( V_37 & V_394 ) ) {
F_59 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_188 ( V_2 -> V_90 , & V_2 -> V_5 . V_6 . V_37 , V_392 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_395 = ! ( V_37 & V_396 ) ;
F_189 ( V_2 ) ;
return 0 ;
}
static void F_190 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_305 = false ;
}
static void F_191 ( struct V_1 * V_2 )
{
T_2 V_278 ;
if ( ! ( V_2 -> V_5 . V_397 . V_393 & V_398 ) )
return;
V_278 = V_399 -> V_400 . V_401 - V_2 -> V_5 . V_397 . V_402 ;
V_2 -> V_5 . V_397 . V_402 = V_399 -> V_400 . V_401 ;
V_2 -> V_5 . V_397 . V_403 = V_278 ;
}
static void F_192 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_397 . V_393 & V_398 ) )
return;
if ( F_143 ( F_161 ( V_2 -> V_90 , & V_2 -> V_5 . V_397 . V_404 ,
& V_2 -> V_5 . V_397 . V_405 , sizeof( struct V_406 ) ) ) )
return;
V_2 -> V_5 . V_397 . V_405 . V_405 += V_2 -> V_5 . V_397 . V_403 ;
V_2 -> V_5 . V_397 . V_405 . V_213 += 2 ;
V_2 -> V_5 . V_397 . V_403 = 0 ;
F_162 ( V_2 -> V_90 , & V_2 -> V_5 . V_397 . V_404 ,
& V_2 -> V_5 . V_397 . V_405 , sizeof( struct V_406 ) ) ;
}
int F_193 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
bool V_407 = false ;
T_1 V_21 = V_32 -> V_132 ;
T_2 V_37 = V_32 -> V_37 ;
switch ( V_21 ) {
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
break;
case V_414 :
return F_97 ( V_2 , V_37 ) ;
case V_415 :
V_37 &= ~ ( T_2 ) 0x40 ;
V_37 &= ~ ( T_2 ) 0x100 ;
V_37 &= ~ ( T_2 ) 0x8 ;
if ( V_37 != 0 ) {
F_183 ( V_2 , L_9 ,
V_37 ) ;
return 1 ;
}
break;
case V_416 :
if ( V_37 != 0 ) {
F_183 ( V_2 , L_10
L_11 , V_37 ) ;
return 1 ;
}
break;
case V_417 :
if ( ! V_37 ) {
break;
} else if ( V_37 & ~ ( V_418 | V_419 ) ) {
return 1 ;
}
F_183 ( V_2 , L_12 ,
V_233 , V_37 ) ;
break;
case 0x200 ... 0x2ff :
return F_169 ( V_2 , V_21 , V_37 ) ;
case V_420 :
return F_19 ( V_2 , V_32 ) ;
case V_421 ... V_421 + 0x3ff :
return F_194 ( V_2 , V_21 , V_37 ) ;
case V_422 :
F_195 ( V_2 , V_37 ) ;
break;
case V_423 :
if ( F_132 ( V_2 ) ) {
if ( ! V_32 -> V_39 ) {
T_2 V_424 = V_37 - V_2 -> V_5 . V_264 ;
V_64 -> V_425 ( V_2 , V_424 , true ) ;
}
V_2 -> V_5 . V_264 = V_37 ;
}
break;
case V_426 :
V_2 -> V_5 . V_427 = V_37 ;
break;
case V_428 :
case V_429 :
V_2 -> V_90 -> V_5 . V_212 = V_37 ;
F_104 ( V_2 -> V_90 , V_37 ) ;
break;
case V_430 :
case V_431 : {
T_2 V_432 ;
F_190 ( V_2 ) ;
V_2 -> V_5 . time = V_37 ;
F_27 ( V_433 , V_2 ) ;
if ( ! ( V_37 & 1 ) )
break;
V_432 = V_37 & ~ ( V_360 | 1 ) ;
if ( F_188 ( V_2 -> V_90 ,
& V_2 -> V_5 . V_312 , V_37 & ~ 1ULL ,
sizeof( struct V_299 ) ) )
V_2 -> V_5 . V_305 = false ;
else
V_2 -> V_5 . V_305 = true ;
break;
}
case V_434 :
if ( F_187 ( V_2 , V_37 ) )
return 1 ;
break;
case V_435 :
if ( F_143 ( ! F_196 () ) )
return 1 ;
if ( V_37 & V_436 )
return 1 ;
if ( F_188 ( V_2 -> V_90 , & V_2 -> V_5 . V_397 . V_404 ,
V_37 & V_437 ,
sizeof( struct V_406 ) ) )
return 1 ;
V_2 -> V_5 . V_397 . V_393 = V_37 ;
if ( ! ( V_37 & V_398 ) )
break;
V_2 -> V_5 . V_397 . V_402 = V_399 -> V_400 . V_401 ;
F_197 () ;
F_191 ( V_2 ) ;
F_198 () ;
F_27 ( V_438 , V_2 ) ;
break;
case V_439 :
if ( F_199 ( V_2 , V_37 ) )
return 1 ;
break;
case V_347 :
case V_345 :
case V_350 ... V_350 + 4 * V_440 - 1 :
return F_170 ( V_2 , V_21 , V_37 ) ;
case V_441 :
case V_442 :
case V_443 :
case V_444 :
if ( V_37 != 0 )
F_183 ( V_2 , L_13
L_14 , V_21 , V_37 ) ;
break;
case V_445 :
case V_446 :
case V_447 :
case V_448 :
F_183 ( V_2 , L_13
L_14 , V_21 , V_37 ) ;
break;
case V_449 :
case V_450 :
V_407 = true ;
case V_451 :
case V_452 :
if ( F_200 ( V_2 , V_21 ) )
return F_201 ( V_2 , V_32 ) ;
if ( V_407 || V_37 != 0 )
F_183 ( V_2 , L_15
L_14 , V_21 , V_37 ) ;
break;
case V_453 :
break;
case V_368 ... V_454 :
if ( F_177 ( V_21 ) ) {
int V_108 ;
F_202 ( & V_2 -> V_90 -> V_455 ) ;
V_108 = F_178 ( V_2 , V_21 , V_37 ) ;
F_203 ( & V_2 -> V_90 -> V_455 ) ;
return V_108 ;
} else
return F_184 ( V_2 , V_21 , V_37 ) ;
break;
case V_456 :
F_183 ( V_2 , L_16 , V_21 , V_37 ) ;
break;
case V_457 :
if ( ! F_204 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_458 . V_459 = V_37 ;
break;
case V_460 :
if ( ! F_204 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_458 . V_461 = V_37 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_90 -> V_5 . F_171 . V_21 ) )
return F_171 ( V_2 , V_37 ) ;
if ( F_200 ( V_2 , V_21 ) )
return F_201 ( V_2 , V_32 ) ;
if ( ! V_462 ) {
F_183 ( V_2 , L_17 ,
V_21 , V_37 ) ;
return 1 ;
} else {
F_183 ( V_2 , L_16 ,
V_21 , V_37 ) ;
break;
}
}
return 0 ;
}
int F_205 ( struct V_1 * V_2 , T_1 V_463 , T_2 * V_464 )
{
return V_64 -> V_465 ( V_2 , V_463 , V_464 ) ;
}
static int F_206 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_464 )
{
T_2 * V_331 = ( T_2 * ) & V_2 -> V_5 . V_332 . V_333 ;
if ( ! F_165 ( V_21 ) )
return 1 ;
if ( V_21 == V_328 )
* V_464 = V_2 -> V_5 . V_332 . V_334 +
( V_2 -> V_5 . V_332 . V_335 << 10 ) ;
else if ( V_21 == V_317 )
* V_464 = V_331 [ 0 ] ;
else if ( V_21 == V_318 || V_21 == V_319 )
* V_464 = V_331 [ 1 + V_21 - V_318 ] ;
else if ( V_21 >= V_320 && V_21 <= V_327 )
* V_464 = V_331 [ 3 + V_21 - V_320 ] ;
else if ( V_21 == V_329 )
* V_464 = V_2 -> V_5 . V_336 ;
else {
int V_337 , V_338 ;
T_2 * V_339 ;
V_337 = ( V_21 - 0x200 ) / 2 ;
V_338 = V_21 - 0x200 - 2 * V_337 ;
if ( ! V_338 )
V_339 =
( T_2 * ) & V_2 -> V_5 . V_332 . V_340 [ V_337 ] . V_341 ;
else
V_339 =
( T_2 * ) & V_2 -> V_5 . V_332 . V_340 [ V_337 ] . V_342 ;
* V_464 = * V_339 ;
}
return 0 ;
}
static int F_207 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_464 )
{
T_2 V_37 ;
T_2 V_343 = V_2 -> V_5 . V_343 ;
unsigned V_344 = V_343 & 0xff ;
switch ( V_21 ) {
case V_466 :
case V_467 :
V_37 = 0 ;
break;
case V_468 :
V_37 = V_2 -> V_5 . V_343 ;
break;
case V_347 :
if ( ! ( V_343 & V_348 ) )
return 1 ;
V_37 = V_2 -> V_5 . V_349 ;
break;
case V_345 :
V_37 = V_2 -> V_5 . V_346 ;
break;
default:
if ( V_21 >= V_350 &&
V_21 < V_350 + 4 * V_344 ) {
T_1 V_82 = V_21 - V_350 ;
V_37 = V_2 -> V_5 . V_351 [ V_82 ] ;
break;
}
return 1 ;
}
* V_464 = V_37 ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_464 )
{
T_2 V_37 = 0 ;
struct V_90 * V_90 = V_2 -> V_90 ;
switch ( V_21 ) {
case V_368 :
V_37 = V_90 -> V_5 . V_372 ;
break;
case V_369 :
V_37 = V_90 -> V_5 . V_366 ;
break;
case V_371 : {
V_37 =
F_209 ( F_113 () + V_90 -> V_5 . V_218 , 100 ) ;
break;
}
case V_370 :
V_37 = V_90 -> V_5 . V_379 ;
break;
default:
F_183 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_464 = V_37 ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_464 )
{
T_2 V_37 = 0 ;
switch ( V_21 ) {
case V_469 : {
int V_108 ;
struct V_1 * V_238 ;
F_152 (r, v, vcpu->kvm)
if ( V_238 == V_2 )
V_37 = V_108 ;
break;
}
case V_386 :
return F_211 ( V_2 , V_387 , V_464 ) ;
case V_388 :
return F_211 ( V_2 , V_389 , V_464 ) ;
case V_390 :
return F_211 ( V_2 , V_391 , V_464 ) ;
case V_382 :
V_37 = V_2 -> V_5 . V_384 ;
break;
default:
F_183 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_464 = V_37 ;
return 0 ;
}
int F_212 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_464 )
{
T_2 V_37 ;
switch ( V_21 ) {
case V_470 :
case V_471 :
case V_417 :
case V_472 :
case V_473 :
case V_474 :
case V_475 :
case V_476 :
case V_415 :
case V_411 :
case V_441 :
case V_445 :
case V_477 :
case V_408 :
case V_416 :
case V_413 :
V_37 = 0 ;
break;
case V_449 :
case V_450 :
case V_451 :
case V_452 :
if ( F_200 ( V_2 , V_21 ) )
return F_213 ( V_2 , V_21 , V_464 ) ;
V_37 = 0 ;
break;
case V_409 :
V_37 = 0x100000000ULL ;
break;
case V_478 :
V_37 = 0x500 | V_316 ;
break;
case 0x200 ... 0x2ff :
return F_206 ( V_2 , V_21 , V_464 ) ;
case 0xcd :
V_37 = 3 ;
break;
case V_479 :
V_37 = 1 << 24 ;
break;
case V_420 :
V_37 = F_18 ( V_2 ) ;
break;
case V_421 ... V_421 + 0x3ff :
return F_214 ( V_2 , V_21 , V_464 ) ;
break;
case V_422 :
V_37 = F_215 ( V_2 ) ;
break;
case V_423 :
V_37 = ( T_2 ) V_2 -> V_5 . V_264 ;
break;
case V_426 :
V_37 = V_2 -> V_5 . V_427 ;
break;
case V_480 :
V_37 = 1000ULL ;
V_37 |= ( ( ( T_8 ) 4ULL ) << 40 ) ;
break;
case V_414 :
V_37 = V_2 -> V_5 . V_119 ;
break;
case V_429 :
case V_428 :
V_37 = V_2 -> V_90 -> V_5 . V_212 ;
break;
case V_431 :
case V_430 :
V_37 = V_2 -> V_5 . time ;
break;
case V_434 :
V_37 = V_2 -> V_5 . V_6 . V_393 ;
break;
case V_435 :
V_37 = V_2 -> V_5 . V_397 . V_393 ;
break;
case V_439 :
V_37 = V_2 -> V_5 . V_481 . V_393 ;
break;
case V_466 :
case V_467 :
case V_468 :
case V_347 :
case V_345 :
case V_350 ... V_350 + 4 * V_440 - 1 :
return F_207 ( V_2 , V_21 , V_464 ) ;
case V_453 :
V_37 = 0x20000000 ;
break;
case V_368 ... V_454 :
if ( F_177 ( V_21 ) ) {
int V_108 ;
F_202 ( & V_2 -> V_90 -> V_455 ) ;
V_108 = F_208 ( V_2 , V_21 , V_464 ) ;
F_203 ( & V_2 -> V_90 -> V_455 ) ;
return V_108 ;
} else
return F_210 ( V_2 , V_21 , V_464 ) ;
break;
case V_456 :
V_37 = 0xbe702111 ;
break;
case V_457 :
if ( ! F_204 ( V_2 ) )
return 1 ;
V_37 = V_2 -> V_5 . V_458 . V_459 ;
break;
case V_460 :
if ( ! F_204 ( V_2 ) )
return 1 ;
V_37 = V_2 -> V_5 . V_458 . V_461 ;
break;
default:
if ( F_200 ( V_2 , V_21 ) )
return F_213 ( V_2 , V_21 , V_464 ) ;
if ( ! V_462 ) {
F_183 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_183 ( V_2 , L_20 , V_21 ) ;
V_37 = 0 ;
}
break;
}
* V_464 = V_37 ;
return 0 ;
}
static int F_216 ( struct V_1 * V_2 , struct V_482 * V_19 ,
struct V_483 * V_484 ,
int (* F_217)( struct V_1 * V_2 ,
unsigned V_132 , T_2 * V_37 ) )
{
int V_3 , V_337 ;
V_337 = F_218 ( & V_2 -> V_90 -> V_485 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_486 ; ++ V_3 )
if ( F_217 ( V_2 , V_484 [ V_3 ] . V_132 , & V_484 [ V_3 ] . V_37 ) )
break;
F_219 ( & V_2 -> V_90 -> V_485 , V_337 ) ;
return V_3 ;
}
static int F_220 ( struct V_1 * V_2 , struct V_482 V_377 * V_487 ,
int (* F_217)( struct V_1 * V_2 ,
unsigned V_132 , T_2 * V_37 ) ,
int V_488 )
{
struct V_482 V_19 ;
struct V_483 * V_484 ;
int V_108 , V_489 ;
unsigned V_490 ;
V_108 = - V_89 ;
if ( F_221 ( & V_19 , V_487 , sizeof V_19 ) )
goto V_102;
V_108 = - V_363 ;
if ( V_19 . V_486 >= V_491 )
goto V_102;
V_490 = sizeof( struct V_483 ) * V_19 . V_486 ;
V_484 = F_172 ( V_487 -> V_484 , V_490 ) ;
if ( F_173 ( V_484 ) ) {
V_108 = F_174 ( V_484 ) ;
goto V_102;
}
V_108 = V_489 = F_216 ( V_2 , & V_19 , V_484 , F_217 ) ;
if ( V_108 < 0 )
goto V_365;
V_108 = - V_89 ;
if ( V_488 && F_222 ( V_487 -> V_484 , V_484 , V_490 ) )
goto V_365;
V_108 = V_489 ;
V_365:
F_175 ( V_484 ) ;
V_102:
return V_108 ;
}
int F_223 ( long V_492 )
{
int V_108 ;
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
#ifdef F_224
case V_527 :
case V_528 :
#endif
V_108 = 1 ;
break;
case V_529 :
V_108 = V_530 ;
break;
case V_531 :
V_108 = ! V_64 -> V_532 () ;
break;
case V_533 :
V_108 = V_534 ;
break;
case V_535 :
V_108 = V_536 ;
break;
case V_537 :
V_108 = V_538 ;
break;
case V_539 :
V_108 = 0 ;
break;
#ifdef F_224
case V_540 :
V_108 = F_225 ( & V_541 ) ;
break;
#endif
case V_542 :
V_108 = V_440 ;
break;
case V_543 :
V_108 = V_544 ;
break;
case V_545 :
V_108 = V_546 ;
break;
case V_547 :
V_108 = F_226 ( V_548 ) ;
break;
default:
V_108 = 0 ;
break;
}
return V_108 ;
}
long F_227 ( struct V_549 * V_550 ,
unsigned int V_551 , unsigned long V_552 )
{
void V_377 * V_553 = ( void V_377 * ) V_552 ;
long V_108 ;
switch ( V_551 ) {
case V_554 : {
struct V_555 V_377 * V_556 = V_553 ;
struct V_555 V_557 ;
unsigned V_489 ;
V_108 = - V_89 ;
if ( F_221 ( & V_557 , V_556 , sizeof V_557 ) )
goto V_102;
V_489 = V_557 . V_486 ;
V_557 . V_486 = V_558 + F_46 ( V_559 ) ;
if ( F_222 ( V_556 , & V_557 , sizeof V_557 ) )
goto V_102;
V_108 = - V_363 ;
if ( V_489 < V_557 . V_486 )
goto V_102;
V_108 = - V_89 ;
if ( F_222 ( V_556 -> V_560 , & V_561 ,
V_558 * sizeof( T_1 ) ) )
goto V_102;
if ( F_222 ( V_556 -> V_560 + V_558 ,
& V_559 ,
F_46 ( V_559 ) * sizeof( T_1 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_562 :
case V_563 : {
struct V_564 V_377 * V_565 = V_553 ;
struct V_564 V_566 ;
V_108 = - V_89 ;
if ( F_221 ( & V_566 , V_565 , sizeof V_566 ) )
goto V_102;
V_108 = F_228 ( & V_566 , V_565 -> V_484 ,
V_551 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_222 ( V_565 , & V_566 , sizeof V_566 ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_567 : {
T_2 V_568 ;
V_568 = V_569 ;
V_108 = - V_89 ;
if ( F_222 ( V_553 , & V_568 , sizeof V_568 ) )
goto V_102;
V_108 = 0 ;
break;
}
default:
V_108 = - V_570 ;
}
V_102:
return V_108 ;
}
static void F_229 ( void * V_571 )
{
F_230 () ;
}
static bool F_231 ( struct V_1 * V_2 )
{
return F_232 ( V_2 -> V_90 ) ;
}
void F_233 ( struct V_1 * V_2 , int V_23 )
{
if ( F_231 ( V_2 ) ) {
if ( V_64 -> V_572 () )
F_234 ( V_23 , V_2 -> V_5 . V_573 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_235 ( V_2 -> V_23 ,
F_229 , NULL , 1 ) ;
}
V_64 -> V_574 ( V_2 , V_23 ) ;
if ( F_143 ( V_2 -> V_5 . V_575 ) ) {
F_236 ( V_2 , V_2 -> V_5 . V_575 ) ;
V_2 -> V_5 . V_575 = 0 ;
F_153 ( V_293 , & V_2 -> V_294 ) ;
}
if ( F_143 ( V_2 -> V_23 != V_23 ) || F_131 () ) {
T_11 V_576 = ! V_2 -> V_5 . V_577 ? 0 :
F_159 () - V_2 -> V_5 . V_577 ;
if ( V_576 < 0 )
F_237 ( L_21 ) ;
if ( F_131 () ) {
T_2 V_82 = V_64 -> V_271 ( V_2 ,
V_2 -> V_5 . V_282 ) ;
V_64 -> V_284 ( V_2 , V_82 ) ;
V_2 -> V_5 . V_304 = 1 ;
}
if ( ! V_2 -> V_90 -> V_5 . V_259 || V_2 -> V_23 == - 1 )
F_27 ( V_433 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_238 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_191 ( V_2 ) ;
F_27 ( V_438 , V_2 ) ;
}
void F_239 ( struct V_1 * V_2 )
{
V_64 -> V_578 ( V_2 ) ;
F_240 ( V_2 ) ;
V_2 -> V_5 . V_577 = F_159 () ;
}
static int F_241 ( struct V_1 * V_2 ,
struct V_579 * V_580 )
{
V_64 -> V_581 ( V_2 ) ;
memcpy ( V_580 -> V_582 , V_2 -> V_5 . V_583 -> V_582 , sizeof *V_580 ) ;
return 0 ;
}
static int F_242 ( struct V_1 * V_2 ,
struct V_579 * V_580 )
{
F_243 ( V_2 , V_580 ) ;
F_244 ( V_2 ) ;
return 0 ;
}
static int F_245 ( struct V_1 * V_2 ,
struct V_584 * V_585 )
{
if ( V_585 -> V_585 >= V_586 )
return - V_570 ;
if ( F_80 ( V_2 -> V_90 ) )
return - V_587 ;
F_246 ( V_2 , V_585 -> V_585 , false ) ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
static int F_247 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
return 0 ;
}
static int F_248 ( struct V_1 * V_2 ,
struct V_588 * V_589 )
{
if ( V_589 -> V_267 )
return - V_570 ;
V_2 -> V_5 . V_590 = ! ! V_589 -> V_335 ;
return 0 ;
}
static int F_249 ( struct V_1 * V_2 ,
T_2 V_343 )
{
int V_108 ;
unsigned V_344 = V_343 & 0xff , V_591 ;
V_108 = - V_570 ;
if ( ! V_344 || V_344 >= V_440 )
goto V_102;
if ( V_343 & ~ ( V_569 | 0xff | 0xff0000 ) )
goto V_102;
V_108 = 0 ;
V_2 -> V_5 . V_343 = V_343 ;
if ( V_343 & V_348 )
V_2 -> V_5 . V_349 = ~ ( T_2 ) 0 ;
for ( V_591 = 0 ; V_591 < V_344 ; V_591 ++ )
V_2 -> V_5 . V_351 [ V_591 * 4 ] = ~ ( T_2 ) 0 ;
V_102:
return V_108 ;
}
static int F_250 ( struct V_1 * V_2 ,
struct V_592 * V_593 )
{
T_2 V_343 = V_2 -> V_5 . V_343 ;
unsigned V_344 = V_343 & 0xff ;
T_2 * V_594 = V_2 -> V_5 . V_351 ;
if ( V_593 -> V_591 >= V_344 || ! ( V_593 -> V_461 & V_595 ) )
return - V_570 ;
if ( ( V_593 -> V_461 & V_596 ) && ( V_343 & V_348 ) &&
V_2 -> V_5 . V_349 != ~ ( T_2 ) 0 )
return 0 ;
V_594 += 4 * V_593 -> V_591 ;
if ( ( V_593 -> V_461 & V_596 ) && V_594 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_593 -> V_461 & V_596 ) {
if ( ( V_2 -> V_5 . V_346 & V_597 ) ||
! F_58 ( V_2 , V_598 ) ) {
F_27 ( V_62 , V_2 ) ;
return 0 ;
}
if ( V_594 [ 1 ] & V_595 )
V_593 -> V_461 |= V_599 ;
V_594 [ 2 ] = V_593 -> V_373 ;
V_594 [ 3 ] = V_593 -> V_600 ;
V_2 -> V_5 . V_346 = V_593 -> V_346 ;
V_594 [ 1 ] = V_593 -> V_461 ;
F_28 ( V_2 , V_601 ) ;
} else if ( ! ( V_594 [ 1 ] & V_595 )
|| ! ( V_594 [ 1 ] & V_596 ) ) {
if ( V_594 [ 1 ] & V_595 )
V_593 -> V_461 |= V_599 ;
V_594 [ 2 ] = V_593 -> V_373 ;
V_594 [ 3 ] = V_593 -> V_600 ;
V_594 [ 1 ] = V_593 -> V_461 ;
} else
V_594 [ 1 ] |= V_599 ;
return 0 ;
}
static void F_251 ( struct V_1 * V_2 ,
struct V_602 * V_603 )
{
F_252 ( V_2 ) ;
V_603 -> V_57 . V_604 =
V_2 -> V_5 . V_57 . V_58 &&
! F_253 ( V_2 -> V_5 . V_57 . V_16 ) ;
V_603 -> V_57 . V_16 = V_2 -> V_5 . V_57 . V_16 ;
V_603 -> V_57 . V_60 = V_2 -> V_5 . V_57 . V_60 ;
V_603 -> V_57 . V_605 = 0 ;
V_603 -> V_57 . V_51 = V_2 -> V_5 . V_57 . V_51 ;
V_603 -> V_606 . V_604 =
V_2 -> V_5 . V_606 . V_58 && ! V_2 -> V_5 . V_606 . V_607 ;
V_603 -> V_606 . V_16 = V_2 -> V_5 . V_606 . V_16 ;
V_603 -> V_606 . V_607 = 0 ;
V_603 -> V_606 . V_608 =
V_64 -> V_609 ( V_2 ,
V_610 | V_611 ) ;
V_603 -> V_612 . V_604 = V_2 -> V_5 . V_613 ;
V_603 -> V_612 . V_58 = V_2 -> V_5 . V_614 != 0 ;
V_603 -> V_612 . V_615 = V_64 -> V_616 ( V_2 ) ;
V_603 -> V_612 . V_605 = 0 ;
V_603 -> V_617 = 0 ;
V_603 -> V_267 = ( V_618
| V_619 ) ;
memset ( & V_603 -> V_620 , 0 , sizeof( V_603 -> V_620 ) ) ;
}
static int F_254 ( struct V_1 * V_2 ,
struct V_602 * V_603 )
{
if ( V_603 -> V_267 & ~ ( V_618
| V_621
| V_619 ) )
return - V_570 ;
F_252 ( V_2 ) ;
V_2 -> V_5 . V_57 . V_58 = V_603 -> V_57 . V_604 ;
V_2 -> V_5 . V_57 . V_16 = V_603 -> V_57 . V_16 ;
V_2 -> V_5 . V_57 . V_60 = V_603 -> V_57 . V_60 ;
V_2 -> V_5 . V_57 . V_51 = V_603 -> V_57 . V_51 ;
V_2 -> V_5 . V_606 . V_58 = V_603 -> V_606 . V_604 ;
V_2 -> V_5 . V_606 . V_16 = V_603 -> V_606 . V_16 ;
V_2 -> V_5 . V_606 . V_607 = V_603 -> V_606 . V_607 ;
if ( V_603 -> V_267 & V_619 )
V_64 -> V_622 ( V_2 ,
V_603 -> V_606 . V_608 ) ;
V_2 -> V_5 . V_613 = V_603 -> V_612 . V_604 ;
if ( V_603 -> V_267 & V_618 )
V_2 -> V_5 . V_614 = V_603 -> V_612 . V_58 ;
V_64 -> V_623 ( V_2 , V_603 -> V_612 . V_615 ) ;
if ( V_603 -> V_267 & V_621 &&
F_255 ( V_2 ) )
V_2 -> V_5 . V_583 -> V_617 = V_603 -> V_617 ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
static void F_256 ( struct V_1 * V_2 ,
struct V_624 * V_625 )
{
unsigned long V_167 ;
memcpy ( V_625 -> V_168 , V_2 -> V_5 . V_168 , sizeof( V_2 -> V_5 . V_168 ) ) ;
F_88 ( V_2 , 6 , & V_167 ) ;
V_625 -> V_160 = V_167 ;
V_625 -> V_161 = V_2 -> V_5 . V_161 ;
V_625 -> V_267 = 0 ;
memset ( & V_625 -> V_620 , 0 , sizeof( V_625 -> V_620 ) ) ;
}
static int F_257 ( struct V_1 * V_2 ,
struct V_624 * V_625 )
{
if ( V_625 -> V_267 )
return - V_570 ;
memcpy ( V_2 -> V_5 . V_168 , V_625 -> V_168 , sizeof( V_2 -> V_5 . V_168 ) ) ;
V_2 -> V_5 . V_160 = V_625 -> V_160 ;
F_84 ( V_2 ) ;
V_2 -> V_5 . V_161 = V_625 -> V_161 ;
F_85 ( V_2 ) ;
return 0 ;
}
static void F_258 ( struct V_1 * V_2 ,
struct V_626 * V_627 )
{
if ( V_544 ) {
memcpy ( V_627 -> V_628 ,
& V_2 -> V_5 . V_629 . V_630 -> V_631 ,
V_2 -> V_5 . V_632 ) ;
* ( T_2 * ) & V_627 -> V_628 [ V_633 / sizeof( T_1 ) ] &=
V_2 -> V_5 . V_138 | V_634 ;
} else {
memcpy ( V_627 -> V_628 ,
& V_2 -> V_5 . V_629 . V_630 -> V_635 ,
sizeof( struct V_636 ) ) ;
* ( T_2 * ) & V_627 -> V_628 [ V_633 / sizeof( T_1 ) ] =
V_634 ;
}
}
static int F_259 ( struct V_1 * V_2 ,
struct V_626 * V_627 )
{
T_2 V_637 =
* ( T_2 * ) & V_627 -> V_628 [ V_633 / sizeof( T_1 ) ] ;
if ( V_544 ) {
if ( V_637 & ~ V_638 )
return - V_570 ;
if ( V_637 & ~ V_131 )
return - V_570 ;
memcpy ( & V_2 -> V_5 . V_629 . V_630 -> V_631 ,
V_627 -> V_628 , V_2 -> V_5 . V_632 ) ;
} else {
if ( V_637 & ~ V_634 )
return - V_570 ;
memcpy ( & V_2 -> V_5 . V_629 . V_630 -> V_635 ,
V_627 -> V_628 , sizeof( struct V_636 ) ) ;
}
return 0 ;
}
static void F_260 ( struct V_1 * V_2 ,
struct V_639 * V_640 )
{
if ( ! V_544 ) {
V_640 -> V_641 = 0 ;
return;
}
V_640 -> V_641 = 1 ;
V_640 -> V_267 = 0 ;
V_640 -> V_642 [ 0 ] . V_133 = V_129 ;
V_640 -> V_642 [ 0 ] . V_22 = V_2 -> V_5 . V_130 ;
}
static int F_261 ( struct V_1 * V_2 ,
struct V_639 * V_640 )
{
int V_3 , V_108 = 0 ;
if ( ! V_544 )
return - V_570 ;
if ( V_640 -> V_641 > V_643 || V_640 -> V_267 )
return - V_570 ;
for ( V_3 = 0 ; V_3 < V_640 -> V_641 ; V_3 ++ )
if ( V_640 -> V_642 [ V_3 ] . V_133 == V_129 ) {
V_108 = F_66 ( V_2 , V_129 ,
V_640 -> V_642 [ V_3 ] . V_22 ) ;
break;
}
if ( V_108 )
V_108 = - V_570 ;
return V_108 ;
}
static int F_262 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_305 )
return - V_570 ;
V_2 -> V_5 . V_314 = true ;
F_27 ( V_293 , V_2 ) ;
return 0 ;
}
long F_263 ( struct V_549 * V_550 ,
unsigned int V_551 , unsigned long V_552 )
{
struct V_1 * V_2 = V_550 -> V_644 ;
void V_377 * V_553 = ( void V_377 * ) V_552 ;
int V_108 ;
union {
struct V_579 * V_645 ;
struct V_626 * V_631 ;
struct V_639 * V_642 ;
void * V_646 ;
} V_647 ;
V_647 . V_646 = NULL ;
switch ( V_551 ) {
case V_648 : {
V_108 = - V_570 ;
if ( ! V_2 -> V_5 . V_583 )
goto V_102;
V_647 . V_645 = F_264 ( sizeof( struct V_579 ) , V_649 ) ;
V_108 = - V_364 ;
if ( ! V_647 . V_645 )
goto V_102;
V_108 = F_241 ( V_2 , V_647 . V_645 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_222 ( V_553 , V_647 . V_645 , sizeof( struct V_579 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_650 : {
V_108 = - V_570 ;
if ( ! V_2 -> V_5 . V_583 )
goto V_102;
V_647 . V_645 = F_172 ( V_553 , sizeof( * V_647 . V_645 ) ) ;
if ( F_173 ( V_647 . V_645 ) )
return F_174 ( V_647 . V_645 ) ;
V_108 = F_242 ( V_2 , V_647 . V_645 ) ;
break;
}
case V_651 : {
struct V_584 V_585 ;
V_108 = - V_89 ;
if ( F_221 ( & V_585 , V_553 , sizeof V_585 ) )
goto V_102;
V_108 = F_245 ( V_2 , & V_585 ) ;
break;
}
case V_652 : {
V_108 = F_247 ( V_2 ) ;
break;
}
case V_653 : {
struct V_654 V_377 * V_565 = V_553 ;
struct V_654 V_566 ;
V_108 = - V_89 ;
if ( F_221 ( & V_566 , V_565 , sizeof V_566 ) )
goto V_102;
V_108 = F_265 ( V_2 , & V_566 , V_565 -> V_484 ) ;
break;
}
case V_655 : {
struct V_564 V_377 * V_565 = V_553 ;
struct V_564 V_566 ;
V_108 = - V_89 ;
if ( F_221 ( & V_566 , V_565 , sizeof V_566 ) )
goto V_102;
V_108 = F_266 ( V_2 , & V_566 ,
V_565 -> V_484 ) ;
break;
}
case V_656 : {
struct V_564 V_377 * V_565 = V_553 ;
struct V_564 V_566 ;
V_108 = - V_89 ;
if ( F_221 ( & V_566 , V_565 , sizeof V_566 ) )
goto V_102;
V_108 = F_267 ( V_2 , & V_566 ,
V_565 -> V_484 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_222 ( V_565 , & V_566 , sizeof V_566 ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_657 :
V_108 = F_220 ( V_2 , V_553 , F_205 , 1 ) ;
break;
case V_658 :
V_108 = F_220 ( V_2 , V_553 , F_100 , 0 ) ;
break;
case V_659 : {
struct V_588 V_589 ;
V_108 = - V_89 ;
if ( F_221 ( & V_589 , V_553 , sizeof V_589 ) )
goto V_102;
V_108 = F_248 ( V_2 , & V_589 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_222 ( V_553 , & V_589 , sizeof V_589 ) )
goto V_102;
V_108 = 0 ;
break;
} ;
case V_660 : {
struct V_661 V_662 ;
V_108 = - V_570 ;
if ( ! F_80 ( V_2 -> V_90 ) )
goto V_102;
V_108 = - V_89 ;
if ( F_221 ( & V_662 , V_553 , sizeof V_662 ) )
goto V_102;
V_108 = F_268 ( V_2 , V_662 . V_663 ) ;
break;
}
case V_664 : {
T_2 V_343 ;
V_108 = - V_89 ;
if ( F_221 ( & V_343 , V_553 , sizeof V_343 ) )
goto V_102;
V_108 = F_249 ( V_2 , V_343 ) ;
break;
}
case V_665 : {
struct V_592 V_593 ;
V_108 = - V_89 ;
if ( F_221 ( & V_593 , V_553 , sizeof V_593 ) )
goto V_102;
V_108 = F_250 ( V_2 , & V_593 ) ;
break;
}
case V_666 : {
struct V_602 V_603 ;
F_251 ( V_2 , & V_603 ) ;
V_108 = - V_89 ;
if ( F_222 ( V_553 , & V_603 , sizeof( struct V_602 ) ) )
break;
V_108 = 0 ;
break;
}
case V_667 : {
struct V_602 V_603 ;
V_108 = - V_89 ;
if ( F_221 ( & V_603 , V_553 , sizeof( struct V_602 ) ) )
break;
V_108 = F_254 ( V_2 , & V_603 ) ;
break;
}
case V_668 : {
struct V_624 V_625 ;
F_256 ( V_2 , & V_625 ) ;
V_108 = - V_89 ;
if ( F_222 ( V_553 , & V_625 ,
sizeof( struct V_624 ) ) )
break;
V_108 = 0 ;
break;
}
case V_669 : {
struct V_624 V_625 ;
V_108 = - V_89 ;
if ( F_221 ( & V_625 , V_553 ,
sizeof( struct V_624 ) ) )
break;
V_108 = F_257 ( V_2 , & V_625 ) ;
break;
}
case V_670 : {
V_647 . V_631 = F_264 ( sizeof( struct V_626 ) , V_649 ) ;
V_108 = - V_364 ;
if ( ! V_647 . V_631 )
break;
F_258 ( V_2 , V_647 . V_631 ) ;
V_108 = - V_89 ;
if ( F_222 ( V_553 , V_647 . V_631 , sizeof( struct V_626 ) ) )
break;
V_108 = 0 ;
break;
}
case V_671 : {
V_647 . V_631 = F_172 ( V_553 , sizeof( * V_647 . V_631 ) ) ;
if ( F_173 ( V_647 . V_631 ) )
return F_174 ( V_647 . V_631 ) ;
V_108 = F_259 ( V_2 , V_647 . V_631 ) ;
break;
}
case V_672 : {
V_647 . V_642 = F_264 ( sizeof( struct V_639 ) , V_649 ) ;
V_108 = - V_364 ;
if ( ! V_647 . V_642 )
break;
F_260 ( V_2 , V_647 . V_642 ) ;
V_108 = - V_89 ;
if ( F_222 ( V_553 , V_647 . V_642 ,
sizeof( struct V_639 ) ) )
break;
V_108 = 0 ;
break;
}
case V_673 : {
V_647 . V_642 = F_172 ( V_553 , sizeof( * V_647 . V_642 ) ) ;
if ( F_173 ( V_647 . V_642 ) )
return F_174 ( V_647 . V_642 ) ;
V_108 = F_261 ( V_2 , V_647 . V_642 ) ;
break;
}
case V_674 : {
T_1 V_675 ;
V_108 = - V_570 ;
V_675 = ( T_1 ) V_552 ;
if ( V_675 >= V_676 )
goto V_102;
if ( V_675 == 0 )
V_675 = V_244 ;
F_123 ( V_2 , V_675 ) ;
V_108 = 0 ;
goto V_102;
}
case V_677 : {
V_108 = V_2 -> V_5 . V_243 ;
goto V_102;
}
case V_678 : {
V_108 = F_262 ( V_2 ) ;
goto V_102;
}
default:
V_108 = - V_570 ;
}
V_102:
F_175 ( V_647 . V_646 ) ;
return V_108 ;
}
int F_269 ( struct V_1 * V_2 , struct V_679 * V_680 )
{
return V_681 ;
}
static int F_270 ( struct V_90 * V_90 , unsigned long V_373 )
{
int V_97 ;
if ( V_373 > ( unsigned int ) ( - 3 * V_96 ) )
return - V_570 ;
V_97 = V_64 -> V_682 ( V_90 , V_373 ) ;
return V_97 ;
}
static int F_271 ( struct V_90 * V_90 ,
T_2 V_683 )
{
V_90 -> V_5 . V_684 = V_683 ;
return 0 ;
}
static int F_272 ( struct V_90 * V_90 ,
T_1 V_685 )
{
if ( V_685 < V_686 )
return - V_570 ;
F_202 ( & V_90 -> V_687 ) ;
F_273 ( V_90 , V_685 ) ;
V_90 -> V_5 . V_688 = V_685 ;
F_203 ( & V_90 -> V_687 ) ;
return 0 ;
}
static int F_274 ( struct V_90 * V_90 )
{
return V_90 -> V_5 . V_689 ;
}
static int F_275 ( struct V_90 * V_90 , struct V_690 * V_691 )
{
int V_108 ;
V_108 = 0 ;
switch ( V_691 -> V_692 ) {
case V_693 :
memcpy ( & V_691 -> V_691 . V_694 ,
& F_276 ( V_90 ) -> V_695 [ 0 ] ,
sizeof( struct V_696 ) ) ;
break;
case V_697 :
memcpy ( & V_691 -> V_691 . V_694 ,
& F_276 ( V_90 ) -> V_695 [ 1 ] ,
sizeof( struct V_696 ) ) ;
break;
case V_698 :
V_108 = F_277 ( V_90 , & V_691 -> V_691 . V_699 ) ;
break;
default:
V_108 = - V_570 ;
break;
}
return V_108 ;
}
static int F_278 ( struct V_90 * V_90 , struct V_690 * V_691 )
{
int V_108 ;
V_108 = 0 ;
switch ( V_691 -> V_692 ) {
case V_693 :
F_134 ( & F_276 ( V_90 ) -> V_455 ) ;
memcpy ( & F_276 ( V_90 ) -> V_695 [ 0 ] ,
& V_691 -> V_691 . V_694 ,
sizeof( struct V_696 ) ) ;
F_135 ( & F_276 ( V_90 ) -> V_455 ) ;
break;
case V_697 :
F_134 ( & F_276 ( V_90 ) -> V_455 ) ;
memcpy ( & F_276 ( V_90 ) -> V_695 [ 1 ] ,
& V_691 -> V_691 . V_694 ,
sizeof( struct V_696 ) ) ;
F_135 ( & F_276 ( V_90 ) -> V_455 ) ;
break;
case V_698 :
V_108 = F_279 ( V_90 , & V_691 -> V_691 . V_699 ) ;
break;
default:
V_108 = - V_570 ;
break;
}
F_280 ( F_276 ( V_90 ) ) ;
return V_108 ;
}
static int F_281 ( struct V_90 * V_90 , struct V_700 * V_701 )
{
int V_108 = 0 ;
F_202 ( & V_90 -> V_5 . V_702 -> V_703 . V_455 ) ;
memcpy ( V_701 , & V_90 -> V_5 . V_702 -> V_703 , sizeof( struct V_700 ) ) ;
F_203 ( & V_90 -> V_5 . V_702 -> V_703 . V_455 ) ;
return V_108 ;
}
static int F_282 ( struct V_90 * V_90 , struct V_700 * V_701 )
{
int V_108 = 0 ;
F_202 ( & V_90 -> V_5 . V_702 -> V_703 . V_455 ) ;
memcpy ( & V_90 -> V_5 . V_702 -> V_703 , V_701 , sizeof( struct V_700 ) ) ;
F_283 ( V_90 , 0 , V_701 -> V_704 [ 0 ] . V_705 , 0 ) ;
F_203 ( & V_90 -> V_5 . V_702 -> V_703 . V_455 ) ;
return V_108 ;
}
static int F_284 ( struct V_90 * V_90 , struct V_706 * V_701 )
{
int V_108 = 0 ;
F_202 ( & V_90 -> V_5 . V_702 -> V_703 . V_455 ) ;
memcpy ( V_701 -> V_704 , & V_90 -> V_5 . V_702 -> V_703 . V_704 ,
sizeof( V_701 -> V_704 ) ) ;
V_701 -> V_267 = V_90 -> V_5 . V_702 -> V_703 . V_267 ;
F_203 ( & V_90 -> V_5 . V_702 -> V_703 . V_455 ) ;
memset ( & V_701 -> V_620 , 0 , sizeof( V_701 -> V_620 ) ) ;
return V_108 ;
}
static int F_285 ( struct V_90 * V_90 , struct V_706 * V_701 )
{
int V_108 = 0 , V_707 = 0 ;
T_1 V_708 , V_709 ;
F_202 ( & V_90 -> V_5 . V_702 -> V_703 . V_455 ) ;
V_708 = V_90 -> V_5 . V_702 -> V_703 . V_267 & V_710 ;
V_709 = V_701 -> V_267 & V_710 ;
if ( ! V_708 && V_709 )
V_707 = 1 ;
memcpy ( & V_90 -> V_5 . V_702 -> V_703 . V_704 , & V_701 -> V_704 ,
sizeof( V_90 -> V_5 . V_702 -> V_703 . V_704 ) ) ;
V_90 -> V_5 . V_702 -> V_703 . V_267 = V_701 -> V_267 ;
F_283 ( V_90 , 0 , V_90 -> V_5 . V_702 -> V_703 . V_704 [ 0 ] . V_705 , V_707 ) ;
F_203 ( & V_90 -> V_5 . V_702 -> V_703 . V_455 ) ;
return V_108 ;
}
static int F_286 ( struct V_90 * V_90 ,
struct V_711 * V_712 )
{
if ( ! V_90 -> V_5 . V_702 )
return - V_587 ;
F_202 ( & V_90 -> V_5 . V_702 -> V_703 . V_455 ) ;
V_90 -> V_5 . V_702 -> V_703 . V_52 = V_712 -> V_713 ;
F_203 ( & V_90 -> V_5 . V_702 -> V_703 . V_455 ) ;
return 0 ;
}
int F_287 ( struct V_90 * V_90 , struct V_714 * log )
{
int V_108 ;
struct V_715 * V_716 ;
unsigned long V_489 , V_3 ;
unsigned long * V_717 ;
unsigned long * V_718 ;
bool V_719 = false ;
F_202 ( & V_90 -> V_687 ) ;
V_108 = - V_570 ;
if ( log -> V_10 >= V_538 )
goto V_102;
V_716 = F_288 ( V_90 -> V_720 , log -> V_10 ) ;
V_717 = V_716 -> V_717 ;
V_108 = - V_721 ;
if ( ! V_717 )
goto V_102;
V_489 = F_289 ( V_716 ) ;
V_718 = V_717 + V_489 / sizeof( long ) ;
memset ( V_718 , 0 , V_489 ) ;
F_134 ( & V_90 -> V_722 ) ;
for ( V_3 = 0 ; V_3 < V_489 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_27 ;
T_4 V_82 ;
if ( ! V_717 [ V_3 ] )
continue;
V_719 = true ;
V_27 = F_290 ( & V_717 [ V_3 ] , 0 ) ;
V_718 [ V_3 ] = V_27 ;
V_82 = V_3 * V_723 ;
F_291 ( V_90 , V_716 , V_82 , V_27 ) ;
}
if ( V_719 )
F_292 ( V_90 ) ;
F_135 ( & V_90 -> V_722 ) ;
V_108 = - V_89 ;
if ( F_222 ( log -> V_717 , V_718 , V_489 ) )
goto V_102;
V_108 = 0 ;
V_102:
F_203 ( & V_90 -> V_687 ) ;
return V_108 ;
}
int F_293 ( struct V_90 * V_90 , struct V_724 * V_725 ,
bool V_726 )
{
if ( ! F_80 ( V_90 ) )
return - V_587 ;
V_725 -> V_461 = F_294 ( V_90 , V_727 ,
V_725 -> V_585 , V_725 -> V_728 ,
V_726 ) ;
return 0 ;
}
long F_295 ( struct V_549 * V_550 ,
unsigned int V_551 , unsigned long V_552 )
{
struct V_90 * V_90 = V_550 -> V_644 ;
void V_377 * V_553 = ( void V_377 * ) V_552 ;
int V_108 = - V_729 ;
union {
struct V_700 V_701 ;
struct V_706 V_730 ;
struct V_731 V_732 ;
} V_647 ;
switch ( V_551 ) {
case V_733 :
V_108 = F_270 ( V_90 , V_552 ) ;
break;
case V_734 : {
T_2 V_683 ;
V_108 = - V_89 ;
if ( F_221 ( & V_683 , V_553 , sizeof V_683 ) )
goto V_102;
V_108 = F_271 ( V_90 , V_683 ) ;
break;
}
case V_735 :
V_108 = F_272 ( V_90 , V_552 ) ;
break;
case V_736 :
V_108 = F_274 ( V_90 ) ;
break;
case V_737 : {
struct V_738 * V_739 ;
F_202 ( & V_90 -> V_455 ) ;
V_108 = - V_740 ;
if ( V_90 -> V_5 . V_739 )
goto V_741;
V_108 = - V_570 ;
if ( F_126 ( & V_90 -> V_257 ) )
goto V_741;
V_108 = - V_364 ;
V_739 = F_296 ( V_90 ) ;
if ( V_739 ) {
V_108 = F_297 ( V_90 ) ;
if ( V_108 ) {
F_202 ( & V_90 -> V_687 ) ;
F_298 ( V_90 , V_742 ,
& V_739 -> V_743 ) ;
F_298 ( V_90 , V_742 ,
& V_739 -> V_744 ) ;
F_298 ( V_90 , V_742 ,
& V_739 -> V_745 ) ;
F_203 ( & V_90 -> V_687 ) ;
F_175 ( V_739 ) ;
goto V_741;
}
} else
goto V_741;
F_13 () ;
V_90 -> V_5 . V_739 = V_739 ;
F_13 () ;
V_108 = F_299 ( V_90 ) ;
if ( V_108 ) {
F_202 ( & V_90 -> V_687 ) ;
F_202 ( & V_90 -> V_746 ) ;
F_300 ( V_90 ) ;
F_301 ( V_90 ) ;
F_203 ( & V_90 -> V_746 ) ;
F_203 ( & V_90 -> V_687 ) ;
}
V_741:
F_203 ( & V_90 -> V_455 ) ;
break;
}
case V_747 :
V_647 . V_732 . V_267 = V_748 ;
goto V_749;
case V_750 :
V_108 = - V_89 ;
if ( F_221 ( & V_647 . V_732 , V_553 ,
sizeof( struct V_731 ) ) )
goto V_102;
V_749:
F_202 ( & V_90 -> V_687 ) ;
V_108 = - V_740 ;
if ( V_90 -> V_5 . V_702 )
goto V_751;
V_108 = - V_364 ;
V_90 -> V_5 . V_702 = F_302 ( V_90 , V_647 . V_732 . V_267 ) ;
if ( V_90 -> V_5 . V_702 )
V_108 = 0 ;
V_751:
F_203 ( & V_90 -> V_687 ) ;
break;
case V_752 : {
struct V_690 * V_691 ;
V_691 = F_172 ( V_553 , sizeof( * V_691 ) ) ;
if ( F_173 ( V_691 ) ) {
V_108 = F_174 ( V_691 ) ;
goto V_102;
}
V_108 = - V_587 ;
if ( ! F_80 ( V_90 ) )
goto V_753;
V_108 = F_275 ( V_90 , V_691 ) ;
if ( V_108 )
goto V_753;
V_108 = - V_89 ;
if ( F_222 ( V_553 , V_691 , sizeof *V_691 ) )
goto V_753;
V_108 = 0 ;
V_753:
F_175 ( V_691 ) ;
break;
}
case V_754 : {
struct V_690 * V_691 ;
V_691 = F_172 ( V_553 , sizeof( * V_691 ) ) ;
if ( F_173 ( V_691 ) ) {
V_108 = F_174 ( V_691 ) ;
goto V_102;
}
V_108 = - V_587 ;
if ( ! F_80 ( V_90 ) )
goto V_755;
V_108 = F_278 ( V_90 , V_691 ) ;
if ( V_108 )
goto V_755;
V_108 = 0 ;
V_755:
F_175 ( V_691 ) ;
break;
}
case V_756 : {
V_108 = - V_89 ;
if ( F_221 ( & V_647 . V_701 , V_553 , sizeof( struct V_700 ) ) )
goto V_102;
V_108 = - V_587 ;
if ( ! V_90 -> V_5 . V_702 )
goto V_102;
V_108 = F_281 ( V_90 , & V_647 . V_701 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_222 ( V_553 , & V_647 . V_701 , sizeof( struct V_700 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_757 : {
V_108 = - V_89 ;
if ( F_221 ( & V_647 . V_701 , V_553 , sizeof V_647 . V_701 ) )
goto V_102;
V_108 = - V_587 ;
if ( ! V_90 -> V_5 . V_702 )
goto V_102;
V_108 = F_282 ( V_90 , & V_647 . V_701 ) ;
break;
}
case V_758 : {
V_108 = - V_587 ;
if ( ! V_90 -> V_5 . V_702 )
goto V_102;
V_108 = F_284 ( V_90 , & V_647 . V_730 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_222 ( V_553 , & V_647 . V_730 , sizeof( V_647 . V_730 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_759 : {
V_108 = - V_89 ;
if ( F_221 ( & V_647 . V_730 , V_553 , sizeof( V_647 . V_730 ) ) )
goto V_102;
V_108 = - V_587 ;
if ( ! V_90 -> V_5 . V_702 )
goto V_102;
V_108 = F_285 ( V_90 , & V_647 . V_730 ) ;
break;
}
case V_760 : {
struct V_711 V_712 ;
V_108 = - V_89 ;
if ( F_221 ( & V_712 , V_553 , sizeof( V_712 ) ) )
goto V_102;
V_108 = F_286 ( V_90 , & V_712 ) ;
break;
}
case V_761 : {
V_108 = - V_89 ;
if ( F_221 ( & V_90 -> V_5 . F_171 , V_553 ,
sizeof( struct V_762 ) ) )
goto V_102;
V_108 = - V_570 ;
if ( V_90 -> V_5 . F_171 . V_267 )
goto V_102;
V_108 = 0 ;
break;
}
case V_763 : {
struct V_764 V_765 ;
T_2 V_766 ;
T_11 V_278 ;
V_108 = - V_89 ;
if ( F_221 ( & V_765 , V_553 , sizeof( V_765 ) ) )
goto V_102;
V_108 = - V_570 ;
if ( V_765 . V_267 )
goto V_102;
V_108 = 0 ;
F_303 () ;
V_766 = F_113 () ;
V_278 = V_765 . clock - V_766 ;
F_304 () ;
V_90 -> V_5 . V_218 = V_278 ;
F_150 ( V_90 ) ;
break;
}
case V_767 : {
struct V_764 V_765 ;
T_2 V_766 ;
F_303 () ;
V_766 = F_113 () ;
V_765 . clock = V_90 -> V_5 . V_218 + V_766 ;
F_304 () ;
V_765 . V_267 = 0 ;
memset ( & V_765 . V_605 , 0 , sizeof( V_765 . V_605 ) ) ;
V_108 = - V_89 ;
if ( F_222 ( V_553 , & V_765 , sizeof( V_765 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
default:
;
}
V_102:
return V_108 ;
}
static void F_305 ( void )
{
T_1 V_768 [ 2 ] ;
unsigned V_3 , V_769 ;
for ( V_3 = V_769 = V_770 ; V_3 < F_46 ( V_561 ) ; V_3 ++ ) {
if ( F_306 ( V_561 [ V_3 ] , & V_768 [ 0 ] , & V_768 [ 1 ] ) < 0 )
continue;
if ( V_769 < V_3 )
V_561 [ V_769 ] = V_561 [ V_3 ] ;
V_769 ++ ;
}
V_558 = V_769 ;
}
static int F_307 ( struct V_1 * V_2 , T_5 V_373 , int V_83 ,
const void * V_238 )
{
int V_771 = 0 ;
int V_489 ;
do {
V_489 = F_308 ( V_83 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_583 &&
! F_309 ( & V_2 -> V_5 . V_583 -> V_772 , V_373 , V_489 , V_238 ) )
&& F_310 ( V_2 -> V_90 , V_773 , V_373 , V_489 , V_238 ) )
break;
V_771 += V_489 ;
V_373 += V_489 ;
V_83 -= V_489 ;
V_238 += V_489 ;
} while ( V_83 );
return V_771 ;
}
static int F_311 ( struct V_1 * V_2 , T_5 V_373 , int V_83 , void * V_238 )
{
int V_771 = 0 ;
int V_489 ;
do {
V_489 = F_308 ( V_83 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_583 &&
! F_312 ( & V_2 -> V_5 . V_583 -> V_772 , V_373 , V_489 , V_238 ) )
&& F_313 ( V_2 -> V_90 , V_773 , V_373 , V_489 , V_238 ) )
break;
F_314 ( V_774 , V_489 , V_373 , * ( T_2 * ) V_238 ) ;
V_771 += V_489 ;
V_373 += V_489 ;
V_83 -= V_489 ;
V_238 += V_489 ;
} while ( V_83 );
return V_771 ;
}
static void F_315 ( struct V_1 * V_2 ,
struct V_775 * V_776 , int V_777 )
{
V_64 -> V_778 ( V_2 , V_776 , V_777 ) ;
}
void F_316 ( struct V_1 * V_2 ,
struct V_775 * V_776 , int V_777 )
{
V_64 -> V_779 ( V_2 , V_776 , V_777 ) ;
}
T_5 F_317 ( struct V_1 * V_2 , T_5 V_392 , T_1 V_84 )
{
T_5 V_780 ;
struct V_66 V_57 ;
F_318 ( ! F_35 ( V_2 ) ) ;
V_84 |= V_100 ;
V_780 = V_2 -> V_5 . V_75 . V_781 ( V_2 , V_392 , V_84 , & V_57 ) ;
return V_780 ;
}
T_5 F_319 ( struct V_1 * V_2 , T_15 V_782 ,
struct V_66 * V_57 )
{
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
return V_2 -> V_5 . V_92 -> V_781 ( V_2 , V_782 , V_84 , V_57 ) ;
}
T_5 F_320 ( struct V_1 * V_2 , T_15 V_782 ,
struct V_66 * V_57 )
{
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
V_84 |= V_783 ;
return V_2 -> V_5 . V_92 -> V_781 ( V_2 , V_782 , V_84 , V_57 ) ;
}
T_5 F_321 ( struct V_1 * V_2 , T_15 V_782 ,
struct V_66 * V_57 )
{
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
V_84 |= V_101 ;
return V_2 -> V_5 . V_92 -> V_781 ( V_2 , V_782 , V_84 , V_57 ) ;
}
T_5 F_322 ( struct V_1 * V_2 , T_15 V_782 ,
struct V_66 * V_57 )
{
return V_2 -> V_5 . V_92 -> V_781 ( V_2 , V_782 , 0 , V_57 ) ;
}
static int F_323 ( T_15 V_373 , void * V_167 , unsigned int V_784 ,
struct V_1 * V_2 , T_1 V_84 ,
struct V_66 * V_57 )
{
void * V_37 = V_167 ;
int V_108 = V_785 ;
while ( V_784 ) {
T_5 V_392 = V_2 -> V_5 . V_92 -> V_781 ( V_2 , V_373 , V_84 ,
V_57 ) ;
unsigned V_82 = V_373 & ( V_96 - 1 ) ;
unsigned V_786 = F_308 ( V_784 , ( unsigned ) V_96 - V_82 ) ;
int V_97 ;
if ( V_392 == V_88 )
return V_787 ;
V_97 = F_105 ( V_2 -> V_90 , V_392 , V_37 , V_786 ) ;
if ( V_97 < 0 ) {
V_108 = V_788 ;
goto V_102;
}
V_784 -= V_786 ;
V_37 += V_786 ;
V_373 += V_786 ;
}
V_102:
return V_108 ;
}
static int F_324 ( struct V_789 * V_790 ,
T_15 V_373 , void * V_167 , unsigned int V_784 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
return F_323 ( V_373 , V_167 , V_784 , V_2 ,
V_84 | V_783 ,
V_57 ) ;
}
int F_326 ( struct V_789 * V_790 ,
T_15 V_373 , void * V_167 , unsigned int V_784 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
return F_323 ( V_373 , V_167 , V_784 , V_2 , V_84 ,
V_57 ) ;
}
static int F_327 ( struct V_789 * V_790 ,
T_15 V_373 , void * V_167 , unsigned int V_784 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
return F_323 ( V_373 , V_167 , V_784 , V_2 , 0 , V_57 ) ;
}
int F_328 ( struct V_789 * V_790 ,
T_15 V_373 , void * V_167 ,
unsigned int V_784 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
void * V_37 = V_167 ;
int V_108 = V_785 ;
while ( V_784 ) {
T_5 V_392 = V_2 -> V_5 . V_92 -> V_781 ( V_2 , V_373 ,
V_101 ,
V_57 ) ;
unsigned V_82 = V_373 & ( V_96 - 1 ) ;
unsigned V_791 = F_308 ( V_784 , ( unsigned ) V_96 - V_82 ) ;
int V_97 ;
if ( V_392 == V_88 )
return V_787 ;
V_97 = F_106 ( V_2 -> V_90 , V_392 , V_37 , V_791 ) ;
if ( V_97 < 0 ) {
V_108 = V_788 ;
goto V_102;
}
V_784 -= V_791 ;
V_37 += V_791 ;
V_373 += V_791 ;
}
V_102:
return V_108 ;
}
static int F_329 ( struct V_1 * V_2 , unsigned long V_782 ,
T_5 * V_392 , struct V_66 * V_57 ,
bool V_792 )
{
T_1 V_84 = ( ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 )
| ( V_792 ? V_101 : 0 ) ;
if ( F_330 ( V_2 , V_782 )
&& ! F_331 ( V_2 -> V_5 . V_92 , V_2 -> V_5 . V_84 , V_84 ) ) {
* V_392 = V_2 -> V_5 . V_793 << V_95 |
( V_782 & ( V_96 - 1 ) ) ;
F_332 ( V_782 , * V_392 , V_792 , false ) ;
return 1 ;
}
* V_392 = V_2 -> V_5 . V_92 -> V_781 ( V_2 , V_782 , V_84 , V_57 ) ;
if ( * V_392 == V_88 )
return - 1 ;
if ( ( * V_392 & V_360 ) == V_794 )
return 1 ;
if ( F_333 ( V_2 , * V_392 ) ) {
F_332 ( V_782 , * V_392 , V_792 , true ) ;
return 1 ;
}
return 0 ;
}
int F_334 ( struct V_1 * V_2 , T_5 V_392 ,
const void * V_167 , int V_784 )
{
int V_97 ;
V_97 = F_106 ( V_2 -> V_90 , V_392 , V_167 , V_784 ) ;
if ( V_97 < 0 )
return 0 ;
F_335 ( V_2 , V_392 , V_167 , V_784 ) ;
return 1 ;
}
static int F_336 ( struct V_1 * V_2 , void * V_167 , int V_784 )
{
if ( V_2 -> V_795 ) {
F_314 ( V_774 , V_784 ,
V_2 -> V_796 [ 0 ] . V_392 , * ( T_2 * ) V_167 ) ;
V_2 -> V_795 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_337 ( struct V_1 * V_2 , T_5 V_392 ,
void * V_167 , int V_784 )
{
return ! F_105 ( V_2 -> V_90 , V_392 , V_167 , V_784 ) ;
}
static int F_338 ( struct V_1 * V_2 , T_5 V_392 ,
void * V_167 , int V_784 )
{
return F_334 ( V_2 , V_392 , V_167 , V_784 ) ;
}
static int F_339 ( struct V_1 * V_2 , T_5 V_392 , int V_784 , void * V_167 )
{
F_314 ( V_797 , V_784 , V_392 , * ( T_2 * ) V_167 ) ;
return F_307 ( V_2 , V_392 , V_784 , V_167 ) ;
}
static int F_340 ( struct V_1 * V_2 , T_5 V_392 ,
void * V_167 , int V_784 )
{
F_314 ( V_798 , V_784 , V_392 , 0 ) ;
return V_788 ;
}
static int F_341 ( struct V_1 * V_2 , T_5 V_392 ,
void * V_167 , int V_784 )
{
struct V_799 * V_800 = & V_2 -> V_796 [ 0 ] ;
memcpy ( V_2 -> V_801 -> V_802 . V_37 , V_800 -> V_37 , F_308 ( 8u , V_800 -> V_83 ) ) ;
return V_785 ;
}
static int F_342 ( unsigned long V_373 , void * V_167 ,
unsigned int V_784 ,
struct V_66 * V_57 ,
struct V_1 * V_2 ,
const struct V_803 * V_804 )
{
T_5 V_392 ;
int V_771 , V_97 ;
bool V_792 = V_804 -> V_792 ;
struct V_799 * V_800 ;
V_97 = F_329 ( V_2 , V_373 , & V_392 , V_57 , V_792 ) ;
if ( V_97 < 0 )
return V_787 ;
if ( V_97 )
goto V_802;
if ( V_804 -> V_805 ( V_2 , V_392 , V_167 , V_784 ) )
return V_785 ;
V_802:
V_771 = V_804 -> V_806 ( V_2 , V_392 , V_784 , V_167 ) ;
if ( V_771 == V_784 )
return V_785 ;
V_392 += V_771 ;
V_784 -= V_771 ;
V_167 += V_771 ;
F_114 ( V_2 -> V_807 >= V_808 ) ;
V_800 = & V_2 -> V_796 [ V_2 -> V_807 ++ ] ;
V_800 -> V_392 = V_392 ;
V_800 -> V_37 = V_167 ;
V_800 -> V_83 = V_784 ;
return V_785 ;
}
int F_343 ( struct V_789 * V_790 , unsigned long V_373 ,
void * V_167 , unsigned int V_784 ,
struct V_66 * V_57 ,
const struct V_803 * V_804 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
T_5 V_392 ;
int V_809 ;
if ( V_804 -> V_810 &&
V_804 -> V_810 ( V_2 , V_167 , V_784 ) )
return V_785 ;
V_2 -> V_807 = 0 ;
if ( ( ( V_373 + V_784 - 1 ) ^ V_373 ) & V_360 ) {
int V_811 ;
V_811 = - V_373 & ~ V_360 ;
V_809 = F_342 ( V_373 , V_167 , V_811 , V_57 ,
V_2 , V_804 ) ;
if ( V_809 != V_785 )
return V_809 ;
V_373 += V_811 ;
V_167 += V_811 ;
V_784 -= V_811 ;
}
V_809 = F_342 ( V_373 , V_167 , V_784 , V_57 ,
V_2 , V_804 ) ;
if ( V_809 != V_785 )
return V_809 ;
if ( ! V_2 -> V_807 )
return V_809 ;
V_392 = V_2 -> V_796 [ 0 ] . V_392 ;
V_2 -> V_812 = 1 ;
V_2 -> V_813 = 0 ;
V_2 -> V_801 -> V_802 . V_83 = F_308 ( 8u , V_2 -> V_796 [ 0 ] . V_83 ) ;
V_2 -> V_801 -> V_802 . V_814 = V_2 -> V_815 = V_804 -> V_792 ;
V_2 -> V_801 -> V_816 = V_817 ;
V_2 -> V_801 -> V_802 . V_818 = V_392 ;
return V_804 -> V_819 ( V_2 , V_392 , V_167 , V_784 ) ;
}
static int F_344 ( struct V_789 * V_790 ,
unsigned long V_373 ,
void * V_167 ,
unsigned int V_784 ,
struct V_66 * V_57 )
{
return F_343 ( V_790 , V_373 , V_167 , V_784 ,
V_57 , & V_820 ) ;
}
int F_345 ( struct V_789 * V_790 ,
unsigned long V_373 ,
const void * V_167 ,
unsigned int V_784 ,
struct V_66 * V_57 )
{
return F_343 ( V_790 , V_373 , ( void * ) V_167 , V_784 ,
V_57 , & V_821 ) ;
}
static int F_346 ( struct V_789 * V_790 ,
unsigned long V_373 ,
const void * V_822 ,
const void * V_823 ,
unsigned int V_784 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
T_5 V_392 ;
struct V_362 * V_362 ;
char * V_824 ;
bool V_825 ;
if ( V_784 > 8 || ( V_784 & ( V_784 - 1 ) ) )
goto V_826;
V_392 = F_321 ( V_2 , V_373 , NULL ) ;
if ( V_392 == V_88 ||
( V_392 & V_360 ) == V_794 )
goto V_826;
if ( ( ( V_392 + V_784 - 1 ) & V_360 ) != ( V_392 & V_360 ) )
goto V_826;
V_362 = F_347 ( V_2 -> V_90 , V_392 >> V_95 ) ;
if ( F_348 ( V_362 ) )
goto V_826;
V_824 = F_349 ( V_362 ) ;
V_824 += F_350 ( V_392 ) ;
switch ( V_784 ) {
case 1 :
V_825 = F_351 ( T_13 , V_824 , V_822 , V_823 ) ;
break;
case 2 :
V_825 = F_351 ( V_827 , V_824 , V_822 , V_823 ) ;
break;
case 4 :
V_825 = F_351 ( T_1 , V_824 , V_822 , V_823 ) ;
break;
case 8 :
V_825 = F_352 ( V_824 , V_822 , V_823 ) ;
break;
default:
F_24 () ;
}
F_353 ( V_824 ) ;
F_354 ( V_362 ) ;
if ( ! V_825 )
return V_828 ;
F_335 ( V_2 , V_392 , V_823 , V_784 ) ;
return V_785 ;
V_826:
F_355 ( V_829 L_22 ) ;
return F_345 ( V_790 , V_373 , V_823 , V_784 , V_57 ) ;
}
static int F_356 ( struct V_1 * V_2 , void * V_830 )
{
int V_108 ;
if ( V_2 -> V_5 . V_831 . V_832 )
V_108 = F_313 ( V_2 -> V_90 , V_742 , V_2 -> V_5 . V_831 . V_833 ,
V_2 -> V_5 . V_831 . V_490 , V_830 ) ;
else
V_108 = F_310 ( V_2 -> V_90 , V_742 ,
V_2 -> V_5 . V_831 . V_833 , V_2 -> V_5 . V_831 . V_490 ,
V_830 ) ;
return V_108 ;
}
static int F_357 ( struct V_1 * V_2 , int V_490 ,
unsigned short V_833 , void * V_167 ,
unsigned int V_705 , bool V_832 )
{
F_358 ( ! V_832 , V_833 , V_490 , V_705 ) ;
V_2 -> V_5 . V_831 . V_833 = V_833 ;
V_2 -> V_5 . V_831 . V_832 = V_832 ;
V_2 -> V_5 . V_831 . V_705 = V_705 ;
V_2 -> V_5 . V_831 . V_490 = V_490 ;
if ( ! F_356 ( V_2 , V_2 -> V_5 . V_834 ) ) {
V_2 -> V_5 . V_831 . V_705 = 0 ;
return 1 ;
}
V_2 -> V_801 -> V_816 = V_835 ;
V_2 -> V_801 -> V_836 . V_837 = V_832 ? V_838 : V_839 ;
V_2 -> V_801 -> V_836 . V_490 = V_490 ;
V_2 -> V_801 -> V_836 . V_840 = V_841 * V_96 ;
V_2 -> V_801 -> V_836 . V_705 = V_705 ;
V_2 -> V_801 -> V_836 . V_833 = V_833 ;
return 0 ;
}
static int F_359 ( struct V_789 * V_790 ,
int V_490 , unsigned short V_833 , void * V_167 ,
unsigned int V_705 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
int V_97 ;
if ( V_2 -> V_5 . V_831 . V_705 )
goto V_842;
V_97 = F_357 ( V_2 , V_490 , V_833 , V_167 , V_705 , true ) ;
if ( V_97 ) {
V_842:
memcpy ( V_167 , V_2 -> V_5 . V_834 , V_490 * V_705 ) ;
V_2 -> V_5 . V_831 . V_705 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_360 ( struct V_789 * V_790 ,
int V_490 , unsigned short V_833 ,
const void * V_167 , unsigned int V_705 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
memcpy ( V_2 -> V_5 . V_834 , V_167 , V_490 * V_705 ) ;
return F_357 ( V_2 , V_490 , V_833 , ( void * ) V_167 , V_705 , false ) ;
}
static unsigned long F_361 ( struct V_1 * V_2 , int V_777 )
{
return V_64 -> F_361 ( V_2 , V_777 ) ;
}
static void F_362 ( struct V_789 * V_790 , V_154 V_71 )
{
F_363 ( F_325 ( V_790 ) , V_71 ) ;
}
int F_364 ( struct V_1 * V_2 )
{
if ( ! F_231 ( V_2 ) )
return V_785 ;
if ( V_64 -> V_572 () ) {
int V_23 = F_365 () ;
F_234 ( V_23 , V_2 -> V_5 . V_573 ) ;
F_366 ( V_2 -> V_5 . V_573 ,
F_229 , NULL , 1 ) ;
F_367 () ;
F_368 ( V_2 -> V_5 . V_573 ) ;
} else
F_230 () ;
return V_785 ;
}
static void F_369 ( struct V_789 * V_790 )
{
F_364 ( F_325 ( V_790 ) ) ;
}
int F_370 ( struct V_789 * V_790 , int V_166 , unsigned long * V_843 )
{
return F_88 ( F_325 ( V_790 ) , V_166 , V_843 ) ;
}
int F_371 ( struct V_789 * V_790 , int V_166 , unsigned long V_22 )
{
return F_86 ( F_325 ( V_790 ) , V_166 , V_22 ) ;
}
static T_2 F_372 ( T_2 V_844 , T_1 V_845 )
{
return ( V_844 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_845 ;
}
static unsigned long F_373 ( struct V_789 * V_790 , int V_846 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
unsigned long V_22 ;
switch ( V_846 ) {
case 0 :
V_22 = F_55 ( V_2 ) ;
break;
case 2 :
V_22 = V_2 -> V_5 . V_70 ;
break;
case 3 :
V_22 = F_53 ( V_2 ) ;
break;
case 4 :
V_22 = F_69 ( V_2 ) ;
break;
case 8 :
V_22 = F_82 ( V_2 ) ;
break;
default:
F_374 ( L_23 , V_233 , V_846 ) ;
return 0 ;
}
return V_22 ;
}
static int F_375 ( struct V_789 * V_790 , int V_846 , V_154 V_167 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
int V_175 = 0 ;
switch ( V_846 ) {
case 0 :
V_175 = F_54 ( V_2 , F_372 ( F_55 ( V_2 ) , V_167 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_70 = V_167 ;
break;
case 3 :
V_175 = F_75 ( V_2 , V_167 ) ;
break;
case 4 :
V_175 = F_68 ( V_2 , F_372 ( F_69 ( V_2 ) , V_167 ) ) ;
break;
case 8 :
V_175 = F_79 ( V_2 , V_167 ) ;
break;
default:
F_374 ( L_23 , V_233 , V_846 ) ;
V_175 = - 1 ;
}
return V_175 ;
}
static void F_376 ( struct V_789 * V_790 , V_154 V_167 )
{
F_377 ( F_325 ( V_790 ) , V_167 ) ;
}
static int F_378 ( struct V_789 * V_790 )
{
return V_64 -> V_79 ( F_325 ( V_790 ) ) ;
}
static void F_379 ( struct V_789 * V_790 , struct V_847 * V_848 )
{
V_64 -> V_849 ( F_325 ( V_790 ) , V_848 ) ;
}
static void F_380 ( struct V_789 * V_790 , struct V_847 * V_848 )
{
V_64 -> V_850 ( F_325 ( V_790 ) , V_848 ) ;
}
static void F_381 ( struct V_789 * V_790 , struct V_847 * V_848 )
{
V_64 -> V_851 ( F_325 ( V_790 ) , V_848 ) ;
}
static void F_382 ( struct V_789 * V_790 , struct V_847 * V_848 )
{
V_64 -> V_852 ( F_325 ( V_790 ) , V_848 ) ;
}
static unsigned long F_383 (
struct V_789 * V_790 , int V_777 )
{
return F_361 ( F_325 ( V_790 ) , V_777 ) ;
}
static bool F_384 ( struct V_789 * V_790 , V_827 * V_853 ,
struct V_854 * V_855 , T_1 * V_856 ,
int V_777 )
{
struct V_775 V_776 ;
F_316 ( F_325 ( V_790 ) , & V_776 , V_777 ) ;
* V_853 = V_776 . V_853 ;
if ( V_776 . V_857 ) {
memset ( V_855 , 0 , sizeof( * V_855 ) ) ;
return false ;
}
if ( V_776 . V_858 )
V_776 . V_859 >>= 12 ;
F_385 ( V_855 , V_776 . V_859 ) ;
F_386 ( V_855 , ( unsigned long ) V_776 . V_860 ) ;
#ifdef F_56
if ( V_856 )
* V_856 = V_776 . V_860 >> 32 ;
#endif
V_855 -> type = V_776 . type ;
V_855 -> V_580 = V_776 . V_580 ;
V_855 -> V_861 = V_776 . V_861 ;
V_855 -> V_331 = V_776 . V_862 ;
V_855 -> V_863 = V_776 . V_863 ;
V_855 -> V_864 = V_776 . V_864 ;
V_855 -> V_865 = V_776 . V_168 ;
V_855 -> V_858 = V_776 . V_858 ;
return true ;
}
static void F_387 ( struct V_789 * V_790 , V_827 V_853 ,
struct V_854 * V_855 , T_1 V_856 ,
int V_777 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
struct V_775 V_776 ;
V_776 . V_853 = V_853 ;
V_776 . V_860 = F_388 ( V_855 ) ;
#ifdef F_56
V_776 . V_860 |= ( ( T_2 ) V_856 ) << 32 ;
#endif
V_776 . V_859 = F_389 ( V_855 ) ;
if ( V_855 -> V_858 )
V_776 . V_859 = ( V_776 . V_859 << 12 ) | 0xfff ;
V_776 . type = V_855 -> type ;
V_776 . V_862 = V_855 -> V_331 ;
V_776 . V_861 = V_855 -> V_861 ;
V_776 . V_168 = V_855 -> V_865 ;
V_776 . V_580 = V_855 -> V_580 ;
V_776 . V_864 = V_855 -> V_864 ;
V_776 . V_858 = V_855 -> V_858 ;
V_776 . V_863 = V_855 -> V_863 ;
V_776 . V_862 = V_855 -> V_331 ;
V_776 . V_857 = ! V_776 . V_862 ;
V_776 . V_866 = 0 ;
F_315 ( V_2 , & V_776 , V_777 ) ;
return;
}
static int F_390 ( struct V_789 * V_790 ,
T_1 V_463 , T_2 * V_464 )
{
return F_205 ( F_325 ( V_790 ) , V_463 , V_464 ) ;
}
static int F_391 ( struct V_789 * V_790 ,
T_1 V_463 , T_2 V_37 )
{
struct V_31 V_21 ;
V_21 . V_37 = V_37 ;
V_21 . V_132 = V_463 ;
V_21 . V_39 = false ;
return F_99 ( F_325 ( V_790 ) , & V_21 ) ;
}
static int F_392 ( struct V_789 * V_790 ,
T_1 V_867 , T_2 * V_464 )
{
return F_92 ( F_325 ( V_790 ) , V_867 , V_464 ) ;
}
static void F_393 ( struct V_789 * V_790 )
{
F_325 ( V_790 ) -> V_5 . V_868 = 1 ;
}
static void F_394 ( struct V_789 * V_790 )
{
F_197 () ;
F_395 ( F_325 ( V_790 ) ) ;
F_396 () ;
}
static void F_397 ( struct V_789 * V_790 )
{
F_198 () ;
}
static int F_398 ( struct V_789 * V_790 ,
struct V_869 * V_870 ,
enum V_871 V_872 )
{
return V_64 -> V_873 ( F_325 ( V_790 ) , V_870 , V_872 ) ;
}
static void F_399 ( struct V_789 * V_790 ,
T_1 * V_874 , T_1 * V_875 , T_1 * V_178 , T_1 * V_186 )
{
V_654 ( F_325 ( V_790 ) , V_874 , V_875 , V_178 , V_186 ) ;
}
static V_154 F_400 ( struct V_789 * V_790 , unsigned V_876 )
{
return F_91 ( F_325 ( V_790 ) , V_876 ) ;
}
static void F_401 ( struct V_789 * V_790 , unsigned V_876 , V_154 V_167 )
{
F_93 ( F_325 ( V_790 ) , V_876 , V_167 ) ;
}
static void F_402 ( struct V_1 * V_2 , T_1 V_27 )
{
T_1 V_877 = V_64 -> V_609 ( V_2 , V_27 ) ;
if ( ! ( V_877 & V_27 ) )
V_64 -> V_622 ( V_2 , V_27 ) ;
}
static void F_403 ( struct V_1 * V_2 )
{
struct V_789 * V_790 = & V_2 -> V_5 . V_878 ;
if ( V_790 -> V_57 . V_40 == V_41 )
F_34 ( V_2 , & V_790 -> V_57 ) ;
else if ( V_790 -> V_57 . V_879 )
F_33 ( V_2 , V_790 -> V_57 . V_40 ,
V_790 -> V_57 . V_51 ) ;
else
F_28 ( V_2 , V_790 -> V_57 . V_40 ) ;
}
static void F_404 ( struct V_789 * V_790 )
{
memset ( & V_790 -> V_880 , 0 ,
( void * ) & V_790 -> V_881 - ( void * ) & V_790 -> V_880 ) ;
V_790 -> V_882 . V_707 = 0 ;
V_790 -> V_882 . V_883 = 0 ;
V_790 -> V_884 . V_885 = 0 ;
V_790 -> V_884 . V_883 = 0 ;
V_790 -> V_886 . V_885 = 0 ;
V_790 -> V_886 . V_883 = 0 ;
}
static void F_405 ( struct V_1 * V_2 )
{
struct V_789 * V_790 = & V_2 -> V_5 . V_878 ;
int V_121 , V_122 ;
V_64 -> V_123 ( V_2 , & V_121 , & V_122 ) ;
V_790 -> V_887 = F_406 ( V_2 ) ;
V_790 -> V_888 = F_407 ( V_2 ) ;
V_790 -> V_288 = ( ! F_408 ( V_2 ) ) ? V_889 :
( V_790 -> V_887 & V_890 ) ? V_891 :
V_122 ? V_892 :
V_121 ? V_893 :
V_894 ;
V_790 -> V_895 = F_409 ( V_2 ) ;
F_404 ( V_790 ) ;
V_2 -> V_5 . V_896 = false ;
}
int F_410 ( struct V_1 * V_2 , int V_585 , int V_897 )
{
struct V_789 * V_790 = & V_2 -> V_5 . V_878 ;
int V_97 ;
F_405 ( V_2 ) ;
V_790 -> V_898 = 2 ;
V_790 -> V_899 = 2 ;
V_790 -> V_900 = V_790 -> V_888 + V_897 ;
V_97 = F_411 ( V_790 , V_585 ) ;
if ( V_97 != V_785 )
return V_901 ;
V_790 -> V_888 = V_790 -> V_900 ;
F_412 ( V_2 , V_790 -> V_888 ) ;
F_377 ( V_2 , V_790 -> V_887 ) ;
if ( V_585 == V_902 )
V_2 -> V_5 . V_614 = 0 ;
else
V_2 -> V_5 . V_606 . V_58 = false ;
return V_903 ;
}
static int F_413 ( struct V_1 * V_2 )
{
int V_108 = V_903 ;
++ V_2 -> V_68 . V_904 ;
F_414 ( V_2 ) ;
if ( ! F_409 ( V_2 ) ) {
V_2 -> V_801 -> V_816 = V_905 ;
V_2 -> V_801 -> V_906 . V_907 = V_908 ;
V_2 -> V_801 -> V_906 . V_909 = 0 ;
V_108 = V_901 ;
}
F_28 ( V_2 , V_176 ) ;
return V_108 ;
}
static bool F_415 ( struct V_1 * V_2 , T_15 V_70 ,
bool V_910 ,
int V_911 )
{
T_5 V_392 = V_70 ;
T_16 V_912 ;
if ( V_911 & V_913 )
return false ;
if ( ! V_2 -> V_5 . V_75 . V_914 ) {
V_392 = F_321 ( V_2 , V_70 , NULL ) ;
if ( V_392 == V_88 )
return true ;
}
V_912 = F_416 ( V_2 -> V_90 , F_42 ( V_392 ) ) ;
if ( F_417 ( V_912 ) )
return false ;
F_418 ( V_912 ) ;
if ( V_2 -> V_5 . V_75 . V_914 ) {
unsigned int V_915 ;
F_134 ( & V_2 -> V_90 -> V_722 ) ;
V_915 = V_2 -> V_90 -> V_5 . V_915 ;
F_135 ( & V_2 -> V_90 -> V_722 ) ;
if ( V_915 )
F_419 ( V_2 -> V_90 , F_42 ( V_392 ) ) ;
return true ;
}
F_419 ( V_2 -> V_90 , F_42 ( V_392 ) ) ;
return ! V_910 ;
}
static bool F_420 ( struct V_789 * V_790 ,
unsigned long V_70 , int V_911 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
unsigned long V_916 , V_917 , V_392 = V_70 ;
V_916 = V_2 -> V_5 . V_916 ;
V_917 = V_2 -> V_5 . V_917 ;
V_2 -> V_5 . V_916 = V_2 -> V_5 . V_917 = 0 ;
if ( ! ( V_911 & V_918 ) )
return false ;
if ( F_421 ( V_790 ) )
return false ;
if ( V_790 -> V_888 == V_916 && V_917 == V_70 )
return false ;
V_2 -> V_5 . V_916 = V_790 -> V_888 ;
V_2 -> V_5 . V_917 = V_70 ;
if ( ! V_2 -> V_5 . V_75 . V_914 )
V_392 = F_321 ( V_2 , V_70 , NULL ) ;
F_419 ( V_2 -> V_90 , F_42 ( V_392 ) ) ;
return true ;
}
static int F_422 ( unsigned long V_373 , T_1 type , T_1 V_161 ,
unsigned long * V_168 )
{
T_1 V_160 = 0 ;
int V_3 ;
T_1 V_919 , V_920 ;
V_919 = V_161 ;
V_920 = V_161 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_919 >>= 2 , V_920 >>= 4 )
if ( ( V_919 & 3 ) && ( V_920 & 15 ) == type && V_168 [ V_3 ] == V_373 )
V_160 |= ( 1 << V_3 ) ;
return V_160 ;
}
static void F_423 ( struct V_1 * V_2 , int * V_108 )
{
struct V_921 * V_921 = V_2 -> V_801 ;
unsigned long V_922 = V_64 -> V_923 ( V_2 ) ;
if ( F_143 ( V_922 & V_924 ) ) {
if ( V_2 -> V_157 & V_925 ) {
V_921 -> V_926 . V_5 . V_160 = V_927 | V_172 ;
V_921 -> V_926 . V_5 . V_928 = V_2 -> V_5 . V_929 ;
V_921 -> V_926 . V_5 . V_57 = V_930 ;
V_921 -> V_816 = V_931 ;
* V_108 = V_932 ;
} else {
V_2 -> V_5 . V_878 . V_887 &= ~ V_924 ;
V_2 -> V_5 . V_160 &= ~ 15 ;
V_2 -> V_5 . V_160 |= V_927 ;
F_28 ( V_2 , V_930 ) ;
}
}
}
static bool F_424 ( struct V_1 * V_2 , int * V_108 )
{
struct V_921 * V_921 = V_2 -> V_801 ;
unsigned long V_888 = V_2 -> V_5 . V_878 . V_888 ;
T_1 V_160 = 0 ;
if ( F_143 ( V_2 -> V_157 & V_158 ) &&
( V_2 -> V_5 . V_162 & V_165 ) ) {
V_160 = F_422 ( V_888 , 0 ,
V_2 -> V_5 . V_162 ,
V_2 -> V_5 . V_169 ) ;
if ( V_160 != 0 ) {
V_921 -> V_926 . V_5 . V_160 = V_160 | V_172 ;
V_921 -> V_926 . V_5 . V_928 = F_407 ( V_2 ) +
F_361 ( V_2 , V_933 ) ;
V_921 -> V_926 . V_5 . V_57 = V_930 ;
V_921 -> V_816 = V_931 ;
* V_108 = V_932 ;
return true ;
}
}
if ( F_143 ( V_2 -> V_5 . V_161 & V_165 ) ) {
V_160 = F_422 ( V_888 , 0 ,
V_2 -> V_5 . V_161 ,
V_2 -> V_5 . V_168 ) ;
if ( V_160 != 0 ) {
V_2 -> V_5 . V_160 &= ~ 15 ;
V_2 -> V_5 . V_160 |= V_160 ;
F_28 ( V_2 , V_930 ) ;
* V_108 = V_903 ;
return true ;
}
}
return false ;
}
int F_425 ( struct V_1 * V_2 ,
unsigned long V_70 ,
int V_911 ,
void * V_934 ,
int V_935 )
{
int V_108 ;
struct V_789 * V_790 = & V_2 -> V_5 . V_878 ;
bool V_488 = true ;
bool V_936 = V_2 -> V_5 . V_910 ;
V_2 -> V_5 . V_910 = false ;
F_426 ( V_2 ) ;
if ( ! ( V_911 & V_937 ) ) {
F_405 ( V_2 ) ;
if ( F_424 ( V_2 , & V_108 ) )
return V_108 ;
V_790 -> V_938 = 0 ;
V_790 -> V_939 = false ;
V_790 -> V_940 = false ;
V_790 -> V_941 = V_911 & V_942 ;
V_108 = F_427 ( V_790 , V_934 , V_935 ) ;
F_428 ( V_2 ) ;
++ V_2 -> V_68 . V_943 ;
if ( V_108 != V_944 ) {
if ( V_911 & V_942 )
return V_901 ;
if ( F_415 ( V_2 , V_70 , V_936 ,
V_911 ) )
return V_903 ;
if ( V_911 & V_945 )
return V_901 ;
return F_413 ( V_2 ) ;
}
}
if ( V_911 & V_945 ) {
F_412 ( V_2 , V_790 -> V_900 ) ;
return V_903 ;
}
if ( F_420 ( V_790 , V_70 , V_911 ) )
return V_903 ;
if ( V_2 -> V_5 . V_896 ) {
V_2 -> V_5 . V_896 = false ;
F_429 ( V_790 ) ;
}
V_946:
V_108 = F_430 ( V_790 ) ;
if ( V_108 == V_947 )
return V_903 ;
if ( V_108 == V_948 ) {
if ( F_415 ( V_2 , V_70 , V_936 ,
V_911 ) )
return V_903 ;
return F_413 ( V_2 ) ;
}
if ( V_790 -> V_939 ) {
F_403 ( V_2 ) ;
V_108 = V_903 ;
} else if ( V_2 -> V_5 . V_831 . V_705 ) {
if ( ! V_2 -> V_5 . V_831 . V_832 ) {
V_2 -> V_5 . V_831 . V_705 = 0 ;
} else {
V_488 = false ;
V_2 -> V_5 . V_949 = V_950 ;
}
V_108 = V_932 ;
} else if ( V_2 -> V_812 ) {
if ( ! V_2 -> V_815 )
V_488 = false ;
V_108 = V_932 ;
V_2 -> V_5 . V_949 = V_951 ;
} else if ( V_108 == V_952 )
goto V_946;
else
V_108 = V_903 ;
if ( V_488 ) {
F_402 ( V_2 , V_790 -> V_938 ) ;
F_27 ( V_56 , V_2 ) ;
V_2 -> V_5 . V_953 = false ;
F_412 ( V_2 , V_790 -> V_888 ) ;
if ( V_108 == V_903 )
F_423 ( V_2 , & V_108 ) ;
F_377 ( V_2 , V_790 -> V_887 ) ;
} else
V_2 -> V_5 . V_953 = true ;
return V_108 ;
}
int F_431 ( struct V_1 * V_2 , int V_490 , unsigned short V_833 )
{
unsigned long V_167 = F_91 ( V_2 , V_180 ) ;
int V_97 = F_360 ( & V_2 -> V_5 . V_878 ,
V_490 , V_833 , & V_167 , 1 ) ;
V_2 -> V_5 . V_831 . V_705 = 0 ;
return V_97 ;
}
static void F_432 ( void * V_870 )
{
F_433 ( V_302 , 0 ) ;
}
static void F_434 ( void * V_37 )
{
struct V_954 * V_955 = V_37 ;
unsigned long V_236 = 0 ;
if ( V_37 )
V_236 = V_955 -> V_823 ;
else if ( ! F_226 ( V_956 ) )
V_236 = F_435 ( F_436 () ) ;
if ( ! V_236 )
V_236 = V_244 ;
F_433 ( V_302 , V_236 ) ;
}
static int F_437 ( struct V_957 * V_958 , unsigned long V_167 ,
void * V_37 )
{
struct V_954 * V_955 = V_37 ;
struct V_90 * V_90 ;
struct V_1 * V_2 ;
int V_3 , V_959 = 0 ;
if ( V_167 == V_960 && V_955 -> V_822 > V_955 -> V_823 )
return 0 ;
if ( V_167 == V_961 && V_955 -> V_822 < V_955 -> V_823 )
return 0 ;
F_235 ( V_955 -> V_23 , F_434 , V_955 , 1 ) ;
F_134 ( & V_962 ) ;
F_438 (kvm, &vm_list, vm_list) {
F_152 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_955 -> V_23 )
continue;
F_27 ( V_293 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_959 = 1 ;
}
}
F_135 ( & V_962 ) ;
if ( V_955 -> V_822 < V_955 -> V_823 && V_959 ) {
F_235 ( V_955 -> V_23 , F_434 , V_955 , 1 ) ;
}
return 0 ;
}
static int F_439 ( struct V_957 * V_963 ,
unsigned long V_964 , void * V_965 )
{
unsigned int V_23 = ( unsigned long ) V_965 ;
switch ( V_964 ) {
case V_966 :
case V_967 :
F_235 ( V_23 , F_434 , NULL , 1 ) ;
break;
case V_968 :
F_235 ( V_23 , F_432 , NULL , 1 ) ;
break;
}
return V_969 ;
}
static void F_440 ( void )
{
int V_23 ;
V_970 = V_244 ;
F_441 ( & V_971 ) ;
if ( ! F_226 ( V_956 ) ) {
#ifdef F_442
struct V_972 V_973 ;
memset ( & V_973 , 0 , sizeof( V_973 ) ) ;
V_23 = F_365 () ;
F_443 ( & V_973 , V_23 ) ;
if ( V_973 . V_974 . V_975 )
V_970 = V_973 . V_974 . V_975 ;
F_367 () ;
#endif
F_444 ( & V_976 ,
V_977 ) ;
}
F_112 ( L_24 , V_970 ) ;
F_445 (cpu)
F_235 ( V_23 , F_434 , NULL , 1 ) ;
}
int F_446 ( void )
{
return F_447 ( V_978 ) != NULL ;
}
static int F_448 ( void )
{
int V_979 = 3 ;
if ( F_447 ( V_978 ) )
V_979 = V_64 -> V_79 ( F_447 ( V_978 ) ) ;
return V_979 != 0 ;
}
static unsigned long F_449 ( void )
{
unsigned long V_980 = 0 ;
if ( F_447 ( V_978 ) )
V_980 = F_407 ( F_447 ( V_978 ) ) ;
return V_980 ;
}
void F_450 ( struct V_1 * V_2 )
{
F_433 ( V_978 , V_2 ) ;
}
void F_451 ( struct V_1 * V_2 )
{
F_433 ( V_978 , NULL ) ;
}
static void F_452 ( void )
{
T_2 V_27 ;
int V_981 = V_982 . V_983 ;
V_27 = ( ( 1ull << ( 51 - V_981 + 1 ) ) - 1 ) << V_981 ;
V_27 |= 0x3ull << 62 ;
V_27 |= 1ull ;
#ifdef F_56
if ( V_981 == 52 )
V_27 &= ~ 1ull ;
#endif
F_453 ( V_27 ) ;
}
static void F_454 ( struct V_984 * V_985 )
{
struct V_90 * V_90 ;
struct V_1 * V_2 ;
int V_3 ;
F_134 ( & V_962 ) ;
F_438 (kvm, &vm_list, vm_list)
F_152 (i, vcpu, kvm)
F_153 ( V_260 , & V_2 -> V_294 ) ;
F_148 ( & V_292 , 0 ) ;
F_135 ( & V_962 ) ;
}
static int F_455 ( struct V_957 * V_958 , unsigned long V_986 ,
void * V_987 )
{
struct V_196 * V_255 = & V_196 ;
struct V_194 * V_195 = V_987 ;
F_101 ( V_195 ) ;
if ( V_255 -> clock . V_199 != V_258 &&
F_126 ( & V_292 ) != 0 )
F_456 ( V_988 , & V_989 ) ;
return 0 ;
}
int F_457 ( void * V_990 )
{
int V_108 ;
struct V_64 * V_804 = V_990 ;
if ( V_64 ) {
F_10 ( V_26 L_25 ) ;
V_108 = - V_740 ;
goto V_102;
}
if ( ! V_804 -> V_991 () ) {
F_10 ( V_26 L_26 ) ;
V_108 = - V_992 ;
goto V_102;
}
if ( V_804 -> V_993 () ) {
F_10 ( V_26 L_27 ) ;
V_108 = - V_992 ;
goto V_102;
}
V_108 = - V_364 ;
V_25 = F_458 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_102;
}
V_108 = F_459 () ;
if ( V_108 )
goto V_994;
F_452 () ;
F_305 () ;
V_64 = V_804 ;
F_460 ( V_995 , V_996 ,
V_997 , V_998 , 0 ) ;
F_440 () ;
F_461 ( & V_999 ) ;
if ( V_544 )
V_131 = F_462 ( V_129 ) ;
F_463 () ;
#ifdef F_56
F_464 ( & V_1000 ) ;
#endif
return 0 ;
V_994:
F_465 ( V_25 ) ;
V_102:
return V_108 ;
}
void F_466 ( void )
{
F_467 ( & V_999 ) ;
if ( ! F_226 ( V_956 ) )
F_468 ( & V_976 ,
V_977 ) ;
F_469 ( & V_971 ) ;
#ifdef F_56
F_470 ( & V_1000 ) ;
#endif
V_64 = NULL ;
F_471 () ;
F_465 ( V_25 ) ;
}
int F_472 ( struct V_1 * V_2 )
{
++ V_2 -> V_68 . V_1001 ;
if ( F_80 ( V_2 -> V_90 ) ) {
V_2 -> V_5 . V_1002 = V_1003 ;
return 1 ;
} else {
V_2 -> V_801 -> V_816 = V_1004 ;
return 0 ;
}
}
int F_473 ( struct V_1 * V_2 )
{
T_2 V_1005 , V_1006 , V_1007 , V_97 ;
T_17 V_1008 , V_1009 , V_1010 , V_175 = V_1011 , V_1012 = 0 ;
bool V_1013 , V_1014 ;
int V_121 , V_122 ;
if ( V_64 -> V_79 ( V_2 ) != 0 || ! F_408 ( V_2 ) ) {
F_28 ( V_2 , V_176 ) ;
return 0 ;
}
V_64 -> V_123 ( V_2 , & V_121 , & V_122 ) ;
V_1014 = F_50 ( V_2 ) && V_122 == 1 ;
if ( ! V_1014 ) {
V_1005 = ( ( T_2 ) F_91 ( V_2 , V_181 ) << 32 ) |
( F_91 ( V_2 , V_180 ) & 0xffffffff ) ;
V_1006 = ( ( T_2 ) F_91 ( V_2 , V_1015 ) << 32 ) |
( F_91 ( V_2 , V_179 ) & 0xffffffff ) ;
V_1007 = ( ( T_2 ) F_91 ( V_2 , V_1016 ) << 32 ) |
( F_91 ( V_2 , V_1017 ) & 0xffffffff ) ;
}
#ifdef F_56
else {
V_1005 = F_91 ( V_2 , V_179 ) ;
V_1006 = F_91 ( V_2 , V_181 ) ;
V_1007 = F_91 ( V_2 , V_1018 ) ;
}
#endif
V_1008 = V_1005 & 0xffff ;
V_1013 = ( V_1005 >> 16 ) & 0x1 ;
V_1010 = ( V_1005 >> 32 ) & 0xfff ;
V_1009 = ( V_1005 >> 48 ) & 0xfff ;
F_474 ( V_1008 , V_1013 , V_1010 , V_1009 , V_1006 , V_1007 ) ;
switch ( V_1008 ) {
case V_1019 :
F_475 ( V_2 ) ;
break;
default:
V_175 = V_1020 ;
break;
}
V_97 = V_175 | ( ( ( T_2 ) V_1012 & 0xfff ) << 32 ) ;
if ( V_1014 ) {
F_93 ( V_2 , V_180 , V_97 ) ;
} else {
F_93 ( V_2 , V_181 , V_97 >> 32 ) ;
F_93 ( V_2 , V_180 , V_97 & 0xffffffff ) ;
}
return 1 ;
}
static void F_476 ( struct V_90 * V_90 , unsigned long V_267 , int V_1021 )
{
struct V_1022 V_1023 ;
V_1023 . V_1024 = 0 ;
V_1023 . V_1025 = 0 ;
V_1023 . V_1026 = V_1021 ;
V_1023 . V_1027 = V_1028 ;
F_477 ( V_90 , 0 , & V_1023 , NULL ) ;
}
int F_478 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1029 , V_1030 , V_1031 , V_1032 , V_97 ;
int V_108 = 1 ;
if ( F_176 ( V_2 -> V_90 ) )
return F_473 ( V_2 ) ;
V_16 = F_91 ( V_2 , V_180 ) ;
V_1029 = F_91 ( V_2 , V_1015 ) ;
V_1030 = F_91 ( V_2 , V_179 ) ;
V_1031 = F_91 ( V_2 , V_181 ) ;
V_1032 = F_91 ( V_2 , V_1017 ) ;
F_479 ( V_16 , V_1029 , V_1030 , V_1031 , V_1032 ) ;
if ( ! F_50 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_1029 &= 0xFFFFFFFF ;
V_1030 &= 0xFFFFFFFF ;
V_1031 &= 0xFFFFFFFF ;
V_1032 &= 0xFFFFFFFF ;
}
if ( V_64 -> V_79 ( V_2 ) != 0 ) {
V_97 = - V_1033 ;
goto V_102;
}
switch ( V_16 ) {
case V_1034 :
V_97 = 0 ;
break;
case V_1035 :
F_476 ( V_2 -> V_90 , V_1029 , V_1030 ) ;
V_97 = 0 ;
break;
default:
V_97 = - V_1036 ;
break;
}
V_102:
F_93 ( V_2 , V_180 , V_97 ) ;
++ V_2 -> V_68 . V_1037 ;
return V_108 ;
}
static int F_480 ( struct V_789 * V_790 )
{
struct V_1 * V_2 = F_325 ( V_790 ) ;
char V_1038 [ 3 ] ;
unsigned long V_1039 = F_407 ( V_2 ) ;
V_64 -> V_376 ( V_2 , V_1038 ) ;
return F_345 ( V_790 , V_1039 , V_1038 , 3 , NULL ) ;
}
static int F_481 ( struct V_1 * V_2 )
{
return ( ! F_80 ( V_2 -> V_90 ) && ! F_482 ( V_2 ) &&
V_2 -> V_801 -> V_1040 &&
F_483 ( V_2 ) ) ;
}
static void F_484 ( struct V_1 * V_2 )
{
struct V_921 * V_921 = V_2 -> V_801 ;
V_921 -> V_1041 = ( F_406 ( V_2 ) & V_1042 ) != 0 ;
V_921 -> V_155 = F_82 ( V_2 ) ;
V_921 -> V_30 = F_18 ( V_2 ) ;
if ( F_80 ( V_2 -> V_90 ) )
V_921 -> V_1043 = 1 ;
else
V_921 -> V_1043 =
F_483 ( V_2 ) &&
! F_482 ( V_2 ) &&
! F_485 ( V_2 ) ;
}
static void F_244 ( struct V_1 * V_2 )
{
int V_1044 , V_1045 ;
if ( ! V_64 -> F_244 )
return;
if ( ! V_2 -> V_5 . V_583 )
return;
if ( ! V_2 -> V_5 . V_583 -> V_663 )
V_1044 = F_486 ( V_2 ) ;
else
V_1044 = - 1 ;
if ( V_1044 != - 1 )
V_1044 >>= 4 ;
V_1045 = F_83 ( V_2 ) ;
V_64 -> F_244 ( V_2 , V_1045 , V_1044 ) ;
}
static void F_487 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_57 . V_58 ) {
F_488 ( V_2 -> V_5 . V_57 . V_16 ,
V_2 -> V_5 . V_57 . V_60 ,
V_2 -> V_5 . V_57 . V_51 ) ;
V_64 -> V_1046 ( V_2 , V_2 -> V_5 . V_57 . V_16 ,
V_2 -> V_5 . V_57 . V_60 ,
V_2 -> V_5 . V_57 . V_51 ,
V_2 -> V_5 . V_57 . V_52 ) ;
return;
}
if ( V_2 -> V_5 . V_613 ) {
V_64 -> V_1047 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_606 . V_58 ) {
V_64 -> V_1048 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_614 ) {
if ( V_64 -> V_1049 ( V_2 ) ) {
-- V_2 -> V_5 . V_614 ;
V_2 -> V_5 . V_613 = true ;
V_64 -> V_1047 ( V_2 ) ;
}
} else if ( F_489 ( V_2 ) ) {
if ( V_64 -> V_1050 ( V_2 ) ) {
F_246 ( V_2 , F_490 ( V_2 ) ,
false ) ;
V_64 -> V_1048 ( V_2 ) ;
}
}
}
static void F_252 ( struct V_1 * V_2 )
{
unsigned V_859 = 2 ;
if ( V_64 -> V_616 ( V_2 ) || V_2 -> V_5 . V_613 )
V_859 = 1 ;
V_2 -> V_5 . V_614 += F_491 ( & V_2 -> V_5 . V_76 , 0 ) ;
V_2 -> V_5 . V_614 = F_308 ( V_2 -> V_5 . V_614 , V_859 ) ;
F_27 ( V_56 , V_2 ) ;
}
static void F_492 ( struct V_1 * V_2 )
{
T_2 V_1051 [ 4 ] ;
T_1 V_1052 [ 8 ] ;
if ( ! F_493 ( V_2 -> V_5 . V_583 ) )
return;
memset ( V_1051 , 0 , 32 ) ;
memset ( V_1052 , 0 , 32 ) ;
F_494 ( V_2 , V_1051 , V_1052 ) ;
V_64 -> V_1053 ( V_2 , V_1051 ) ;
F_495 ( V_2 , V_1052 ) ;
}
static int F_496 ( struct V_1 * V_2 )
{
int V_108 ;
bool V_1054 = ! F_80 ( V_2 -> V_90 ) &&
V_2 -> V_801 -> V_1040 ;
bool V_1055 = false ;
if ( V_2 -> V_294 ) {
if ( F_497 ( V_1056 , V_2 ) )
F_498 ( V_2 ) ;
if ( F_497 ( V_1057 , V_2 ) )
F_499 ( V_2 ) ;
if ( F_497 ( V_260 , V_2 ) )
F_150 ( V_2 -> V_90 ) ;
if ( F_497 ( V_433 , V_2 ) )
F_163 ( V_2 ) ;
if ( F_497 ( V_293 , V_2 ) ) {
V_108 = F_155 ( V_2 ) ;
if ( F_143 ( V_108 ) )
goto V_102;
}
if ( F_497 ( V_1058 , V_2 ) )
F_76 ( V_2 ) ;
if ( F_497 ( V_1059 , V_2 ) )
V_64 -> V_1060 ( V_2 ) ;
if ( F_497 ( V_1061 , V_2 ) ) {
V_2 -> V_801 -> V_816 = V_1062 ;
V_108 = 0 ;
goto V_102;
}
if ( F_497 ( V_62 , V_2 ) ) {
V_2 -> V_801 -> V_816 = V_1063 ;
V_108 = 0 ;
goto V_102;
}
if ( F_497 ( V_1064 , V_2 ) ) {
V_2 -> V_1065 = 0 ;
V_64 -> V_1066 ( V_2 ) ;
}
if ( F_497 ( V_1067 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1068 = true ;
V_108 = 1 ;
goto V_102;
}
if ( F_497 ( V_438 , V_2 ) )
F_192 ( V_2 ) ;
if ( F_497 ( V_77 , V_2 ) )
F_252 ( V_2 ) ;
if ( F_497 ( V_1069 , V_2 ) )
F_500 ( V_2 ) ;
if ( F_497 ( V_1070 , V_2 ) )
F_501 ( V_2 ) ;
if ( F_497 ( V_1071 , V_2 ) )
F_492 ( V_2 ) ;
}
if ( F_497 ( V_56 , V_2 ) || V_1054 ) {
F_502 ( V_2 ) ;
if ( V_2 -> V_5 . V_1002 == V_1072 ) {
V_108 = 1 ;
goto V_102;
}
F_487 ( V_2 ) ;
if ( V_2 -> V_5 . V_614 )
V_1055 =
V_64 -> V_1073 ( V_2 ) != 0 ;
else if ( F_489 ( V_2 ) || V_1054 )
V_1055 =
V_64 -> V_1074 ( V_2 ) != 0 ;
if ( F_503 ( V_2 ) ) {
if ( V_64 -> V_1075 )
V_64 -> V_1075 ( V_2 ,
F_486 ( V_2 ) ) ;
F_244 ( V_2 ) ;
F_504 ( V_2 ) ;
}
}
V_108 = F_505 ( V_2 ) ;
if ( F_143 ( V_108 ) ) {
goto V_1076;
}
F_197 () ;
V_64 -> V_1077 ( V_2 ) ;
if ( V_2 -> V_1065 )
F_395 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_288 = V_1078 ;
F_219 ( & V_2 -> V_90 -> V_485 , V_2 -> V_1079 ) ;
F_506 () ;
F_303 () ;
if ( V_2 -> V_288 == V_1080 || V_2 -> V_294
|| F_507 () || F_508 ( V_399 ) ) {
V_2 -> V_288 = V_1081 ;
F_13 () ;
F_304 () ;
F_198 () ;
V_2 -> V_1079 = F_218 ( & V_2 -> V_90 -> V_485 ) ;
V_108 = 1 ;
goto V_1076;
}
if ( V_1055 )
F_509 ( V_2 -> V_23 ) ;
F_510 () ;
if ( F_143 ( V_2 -> V_5 . V_164 ) ) {
F_511 ( 0 , 7 ) ;
F_511 ( V_2 -> V_5 . V_169 [ 0 ] , 0 ) ;
F_511 ( V_2 -> V_5 . V_169 [ 1 ] , 1 ) ;
F_511 ( V_2 -> V_5 . V_169 [ 2 ] , 2 ) ;
F_511 ( V_2 -> V_5 . V_169 [ 3 ] , 3 ) ;
}
F_512 ( V_2 -> V_261 ) ;
V_64 -> V_801 ( V_2 ) ;
if ( F_513 () )
F_514 () ;
V_2 -> V_5 . V_282 = V_64 -> V_303 ( V_2 ,
F_159 () ) ;
V_2 -> V_288 = V_1081 ;
F_13 () ;
V_64 -> V_1082 ( V_2 ) ;
++ V_2 -> V_68 . V_1083 ;
F_515 () ;
F_516 () ;
F_198 () ;
V_2 -> V_1079 = F_218 ( & V_2 -> V_90 -> V_485 ) ;
if ( F_143 ( V_1084 == V_1085 ) ) {
unsigned long V_1039 = F_407 ( V_2 ) ;
F_517 ( V_1085 , ( void * ) V_1039 ) ;
}
if ( F_143 ( V_2 -> V_5 . V_1086 ) )
F_27 ( V_293 , V_2 ) ;
if ( V_2 -> V_5 . V_1087 )
F_518 ( V_2 ) ;
V_108 = V_64 -> V_1088 ( V_2 ) ;
return V_108 ;
V_1076:
V_64 -> V_1076 ( V_2 ) ;
if ( F_143 ( V_2 -> V_5 . V_1087 ) )
F_518 ( V_2 ) ;
V_102:
return V_108 ;
}
static int F_519 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_90 * V_90 = V_2 -> V_90 ;
V_2 -> V_1079 = F_218 ( & V_90 -> V_485 ) ;
V_108 = 1 ;
while ( V_108 > 0 ) {
if ( V_2 -> V_5 . V_1002 == V_1089 &&
! V_2 -> V_5 . V_6 . V_1068 )
V_108 = F_496 ( V_2 ) ;
else {
F_219 ( & V_90 -> V_485 , V_2 -> V_1079 ) ;
F_520 ( V_2 ) ;
V_2 -> V_1079 = F_218 ( & V_90 -> V_485 ) ;
if ( F_497 ( V_1090 , V_2 ) ) {
F_502 ( V_2 ) ;
switch( V_2 -> V_5 . V_1002 ) {
case V_1003 :
V_2 -> V_5 . V_1091 . V_1092 = false ;
V_2 -> V_5 . V_1002 =
V_1089 ;
case V_1089 :
V_2 -> V_5 . V_6 . V_1068 = false ;
break;
case V_1072 :
break;
default:
V_108 = - V_1093 ;
break;
}
}
}
if ( V_108 <= 0 )
break;
F_154 ( V_1094 , & V_2 -> V_294 ) ;
if ( F_521 ( V_2 ) )
F_522 ( V_2 ) ;
if ( F_481 ( V_2 ) ) {
V_108 = - V_1093 ;
V_2 -> V_801 -> V_816 = V_1095 ;
++ V_2 -> V_68 . V_1096 ;
}
F_523 ( V_2 ) ;
if ( F_508 ( V_399 ) ) {
V_108 = - V_1093 ;
V_2 -> V_801 -> V_816 = V_1095 ;
++ V_2 -> V_68 . V_1097 ;
}
if ( F_507 () ) {
F_219 ( & V_90 -> V_485 , V_2 -> V_1079 ) ;
F_524 () ;
V_2 -> V_1079 = F_218 ( & V_90 -> V_485 ) ;
}
}
F_219 ( & V_90 -> V_485 , V_2 -> V_1079 ) ;
return V_108 ;
}
static inline int F_525 ( struct V_1 * V_2 )
{
int V_108 ;
V_2 -> V_1079 = F_218 ( & V_2 -> V_90 -> V_485 ) ;
V_108 = F_526 ( V_2 , V_937 ) ;
F_219 ( & V_2 -> V_90 -> V_485 , V_2 -> V_1079 ) ;
if ( V_108 != V_903 )
return 0 ;
return 1 ;
}
static int V_950 ( struct V_1 * V_2 )
{
F_318 ( ! V_2 -> V_5 . V_831 . V_705 ) ;
return F_525 ( V_2 ) ;
}
static int V_951 ( struct V_1 * V_2 )
{
struct V_921 * V_801 = V_2 -> V_801 ;
struct V_799 * V_800 ;
unsigned V_83 ;
F_318 ( ! V_2 -> V_812 ) ;
V_800 = & V_2 -> V_796 [ V_2 -> V_813 ] ;
V_83 = F_308 ( 8u , V_800 -> V_83 ) ;
if ( ! V_2 -> V_815 )
memcpy ( V_800 -> V_37 , V_801 -> V_802 . V_37 , V_83 ) ;
if ( V_800 -> V_83 <= 8 ) {
V_800 ++ ;
V_2 -> V_813 ++ ;
} else {
V_800 -> V_37 += V_83 ;
V_800 -> V_392 += V_83 ;
V_800 -> V_83 -= V_83 ;
}
if ( V_2 -> V_813 >= V_2 -> V_807 ) {
V_2 -> V_812 = 0 ;
if ( V_2 -> V_815 )
return 1 ;
V_2 -> V_795 = 1 ;
return F_525 ( V_2 ) ;
}
V_801 -> V_816 = V_817 ;
V_801 -> V_802 . V_818 = V_800 -> V_392 ;
if ( V_2 -> V_815 )
memcpy ( V_801 -> V_802 . V_37 , V_800 -> V_37 , F_308 ( 8u , V_800 -> V_83 ) ) ;
V_801 -> V_802 . V_83 = F_308 ( 8u , V_800 -> V_83 ) ;
V_801 -> V_802 . V_814 = V_2 -> V_815 ;
V_2 -> V_5 . V_949 = V_951 ;
return 0 ;
}
int F_527 ( struct V_1 * V_2 , struct V_921 * V_921 )
{
int V_108 ;
T_18 V_1098 ;
if ( ! F_528 ( V_399 ) && F_529 ( V_399 ) )
return - V_364 ;
if ( V_2 -> V_1099 )
F_530 ( V_1100 , & V_2 -> V_1101 , & V_1098 ) ;
if ( F_143 ( V_2 -> V_5 . V_1002 == V_1102 ) ) {
F_520 ( V_2 ) ;
F_502 ( V_2 ) ;
F_154 ( V_1090 , & V_2 -> V_294 ) ;
V_108 = - V_1103 ;
goto V_102;
}
if ( ! F_80 ( V_2 -> V_90 ) ) {
if ( F_79 ( V_2 , V_921 -> V_155 ) != 0 ) {
V_108 = - V_570 ;
goto V_102;
}
}
if ( F_143 ( V_2 -> V_5 . V_949 ) ) {
int (* F_531)( struct V_1 * ) = V_2 -> V_5 . V_949 ;
V_2 -> V_5 . V_949 = NULL ;
V_108 = F_531 ( V_2 ) ;
if ( V_108 <= 0 )
goto V_102;
} else
F_114 ( V_2 -> V_5 . V_831 . V_705 || V_2 -> V_812 ) ;
V_108 = F_519 ( V_2 ) ;
V_102:
F_484 ( V_2 ) ;
if ( V_2 -> V_1099 )
F_530 ( V_1100 , & V_1098 , NULL ) ;
return V_108 ;
}
int F_532 ( struct V_1 * V_2 , struct V_1104 * V_582 )
{
if ( V_2 -> V_5 . V_953 ) {
F_533 ( & V_2 -> V_5 . V_878 ) ;
V_2 -> V_5 . V_953 = false ;
}
V_582 -> V_1105 = F_91 ( V_2 , V_180 ) ;
V_582 -> V_1106 = F_91 ( V_2 , V_1015 ) ;
V_582 -> V_1107 = F_91 ( V_2 , V_179 ) ;
V_582 -> V_1108 = F_91 ( V_2 , V_181 ) ;
V_582 -> V_1109 = F_91 ( V_2 , V_1017 ) ;
V_582 -> V_1110 = F_91 ( V_2 , V_1016 ) ;
V_582 -> V_1111 = F_91 ( V_2 , V_1112 ) ;
V_582 -> V_1113 = F_91 ( V_2 , V_1114 ) ;
#ifdef F_56
V_582 -> V_1115 = F_91 ( V_2 , V_1018 ) ;
V_582 -> V_1116 = F_91 ( V_2 , V_1117 ) ;
V_582 -> V_1118 = F_91 ( V_2 , V_1119 ) ;
V_582 -> V_1120 = F_91 ( V_2 , V_1121 ) ;
V_582 -> V_1122 = F_91 ( V_2 , V_1123 ) ;
V_582 -> V_1124 = F_91 ( V_2 , V_1125 ) ;
V_582 -> V_1126 = F_91 ( V_2 , V_1127 ) ;
V_582 -> V_1128 = F_91 ( V_2 , V_1129 ) ;
#endif
V_582 -> V_1039 = F_407 ( V_2 ) ;
V_582 -> V_922 = F_406 ( V_2 ) ;
return 0 ;
}
int F_534 ( struct V_1 * V_2 , struct V_1104 * V_582 )
{
V_2 -> V_5 . V_896 = true ;
V_2 -> V_5 . V_953 = false ;
F_93 ( V_2 , V_180 , V_582 -> V_1105 ) ;
F_93 ( V_2 , V_1015 , V_582 -> V_1106 ) ;
F_93 ( V_2 , V_179 , V_582 -> V_1107 ) ;
F_93 ( V_2 , V_181 , V_582 -> V_1108 ) ;
F_93 ( V_2 , V_1017 , V_582 -> V_1109 ) ;
F_93 ( V_2 , V_1016 , V_582 -> V_1110 ) ;
F_93 ( V_2 , V_1112 , V_582 -> V_1111 ) ;
F_93 ( V_2 , V_1114 , V_582 -> V_1113 ) ;
#ifdef F_56
F_93 ( V_2 , V_1018 , V_582 -> V_1115 ) ;
F_93 ( V_2 , V_1117 , V_582 -> V_1116 ) ;
F_93 ( V_2 , V_1119 , V_582 -> V_1118 ) ;
F_93 ( V_2 , V_1121 , V_582 -> V_1120 ) ;
F_93 ( V_2 , V_1123 , V_582 -> V_1122 ) ;
F_93 ( V_2 , V_1125 , V_582 -> V_1124 ) ;
F_93 ( V_2 , V_1127 , V_582 -> V_1126 ) ;
F_93 ( V_2 , V_1129 , V_582 -> V_1128 ) ;
#endif
F_412 ( V_2 , V_582 -> V_1039 ) ;
F_377 ( V_2 , V_582 -> V_922 ) ;
V_2 -> V_5 . V_57 . V_58 = false ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
void F_535 ( struct V_1 * V_2 , int * V_168 , int * V_864 )
{
struct V_775 V_1130 ;
F_316 ( V_2 , & V_1130 , V_933 ) ;
* V_168 = V_1130 . V_168 ;
* V_864 = V_1130 . V_864 ;
}
int F_536 ( struct V_1 * V_2 ,
struct V_1131 * V_1132 )
{
struct V_847 V_848 ;
F_316 ( V_2 , & V_1132 -> V_1130 , V_933 ) ;
F_316 ( V_2 , & V_1132 -> V_1133 , V_1134 ) ;
F_316 ( V_2 , & V_1132 -> V_1135 , V_1136 ) ;
F_316 ( V_2 , & V_1132 -> V_1137 , V_1138 ) ;
F_316 ( V_2 , & V_1132 -> V_1139 , V_1140 ) ;
F_316 ( V_2 , & V_1132 -> V_1141 , V_1142 ) ;
F_316 ( V_2 , & V_1132 -> V_1143 , V_1144 ) ;
F_316 ( V_2 , & V_1132 -> V_1145 , V_1146 ) ;
V_64 -> V_850 ( V_2 , & V_848 ) ;
V_1132 -> V_1147 . V_859 = V_848 . V_490 ;
V_1132 -> V_1147 . V_860 = V_848 . V_71 ;
V_64 -> V_849 ( V_2 , & V_848 ) ;
V_1132 -> V_1148 . V_859 = V_848 . V_490 ;
V_1132 -> V_1148 . V_860 = V_848 . V_71 ;
V_1132 -> V_109 = F_55 ( V_2 ) ;
V_1132 -> V_70 = V_2 -> V_5 . V_70 ;
V_1132 -> V_93 = F_53 ( V_2 ) ;
V_1132 -> V_139 = F_69 ( V_2 ) ;
V_1132 -> V_155 = F_82 ( V_2 ) ;
V_1132 -> V_119 = V_2 -> V_5 . V_119 ;
V_1132 -> V_30 = F_18 ( V_2 ) ;
memset ( V_1132 -> V_1149 , 0 , sizeof V_1132 -> V_1149 ) ;
if ( V_2 -> V_5 . V_606 . V_58 && ! V_2 -> V_5 . V_606 . V_607 )
F_153 ( V_2 -> V_5 . V_606 . V_16 ,
( unsigned long * ) V_1132 -> V_1149 ) ;
return 0 ;
}
int F_537 ( struct V_1 * V_2 ,
struct V_1150 * V_1002 )
{
F_502 ( V_2 ) ;
if ( V_2 -> V_5 . V_1002 == V_1003 &&
V_2 -> V_5 . V_1091 . V_1092 )
V_1002 -> V_1002 = V_1089 ;
else
V_1002 -> V_1002 = V_2 -> V_5 . V_1002 ;
return 0 ;
}
int F_538 ( struct V_1 * V_2 ,
struct V_1150 * V_1002 )
{
if ( ! F_255 ( V_2 ) &&
V_1002 -> V_1002 != V_1089 )
return - V_570 ;
if ( V_1002 -> V_1002 == V_1151 ) {
V_2 -> V_5 . V_1002 = V_1072 ;
F_153 ( V_1152 , & V_2 -> V_5 . V_583 -> V_1153 ) ;
} else
V_2 -> V_5 . V_1002 = V_1002 -> V_1002 ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
int F_539 ( struct V_1 * V_2 , V_827 V_1154 , int V_1155 ,
int V_1156 , bool V_60 , T_1 V_51 )
{
struct V_789 * V_790 = & V_2 -> V_5 . V_878 ;
int V_97 ;
F_405 ( V_2 ) ;
V_97 = F_540 ( V_790 , V_1154 , V_1155 , V_1156 ,
V_60 , V_51 ) ;
if ( V_97 )
return V_901 ;
F_412 ( V_2 , V_790 -> V_888 ) ;
F_377 ( V_2 , V_790 -> V_887 ) ;
F_27 ( V_56 , V_2 ) ;
return V_903 ;
}
int F_541 ( struct V_1 * V_2 ,
struct V_1131 * V_1132 )
{
struct V_31 V_1157 ;
int V_1158 = 0 ;
int V_1159 , V_1160 , V_337 ;
struct V_847 V_848 ;
if ( ! F_70 ( V_2 ) && ( V_1132 -> V_139 & V_127 ) )
return - V_570 ;
V_848 . V_490 = V_1132 -> V_1147 . V_859 ;
V_848 . V_71 = V_1132 -> V_1147 . V_860 ;
V_64 -> V_852 ( V_2 , & V_848 ) ;
V_848 . V_490 = V_1132 -> V_1148 . V_859 ;
V_848 . V_71 = V_1132 -> V_1148 . V_860 ;
V_64 -> V_851 ( V_2 , & V_848 ) ;
V_2 -> V_5 . V_70 = V_1132 -> V_70 ;
V_1158 |= F_53 ( V_2 ) != V_1132 -> V_93 ;
V_2 -> V_5 . V_93 = V_1132 -> V_93 ;
F_48 ( V_153 , ( V_154 * ) & V_2 -> V_5 . V_105 ) ;
F_79 ( V_2 , V_1132 -> V_155 ) ;
V_1158 |= V_2 -> V_5 . V_119 != V_1132 -> V_119 ;
V_64 -> F_97 ( V_2 , V_1132 -> V_119 ) ;
V_1157 . V_37 = V_1132 -> V_30 ;
V_1157 . V_39 = true ;
F_19 ( V_2 , & V_1157 ) ;
V_1158 |= F_55 ( V_2 ) != V_1132 -> V_109 ;
V_64 -> V_125 ( V_2 , V_1132 -> V_109 ) ;
V_2 -> V_5 . V_109 = V_1132 -> V_109 ;
V_1158 |= F_69 ( V_2 ) != V_1132 -> V_139 ;
V_64 -> V_149 ( V_2 , V_1132 -> V_139 ) ;
if ( V_1132 -> V_139 & V_127 )
F_74 ( V_2 ) ;
V_337 = F_218 ( & V_2 -> V_90 -> V_485 ) ;
if ( ! F_50 ( V_2 ) && F_51 ( V_2 ) ) {
F_45 ( V_2 , V_2 -> V_5 . V_92 , F_53 ( V_2 ) ) ;
V_1158 = 1 ;
}
F_219 ( & V_2 -> V_90 -> V_485 , V_337 ) ;
if ( V_1158 )
F_60 ( V_2 ) ;
V_1160 = V_586 ;
V_1159 = F_542 (
( const unsigned long * ) V_1132 -> V_1149 , V_1160 ) ;
if ( V_1159 < V_1160 ) {
F_246 ( V_2 , V_1159 , false ) ;
F_112 ( L_29 , V_1159 ) ;
}
F_315 ( V_2 , & V_1132 -> V_1130 , V_933 ) ;
F_315 ( V_2 , & V_1132 -> V_1133 , V_1134 ) ;
F_315 ( V_2 , & V_1132 -> V_1135 , V_1136 ) ;
F_315 ( V_2 , & V_1132 -> V_1137 , V_1138 ) ;
F_315 ( V_2 , & V_1132 -> V_1139 , V_1140 ) ;
F_315 ( V_2 , & V_1132 -> V_1141 , V_1142 ) ;
F_315 ( V_2 , & V_1132 -> V_1143 , V_1144 ) ;
F_315 ( V_2 , & V_1132 -> V_1145 , V_1146 ) ;
F_244 ( V_2 ) ;
if ( F_543 ( V_2 ) && F_407 ( V_2 ) == 0xfff0 &&
V_1132 -> V_1130 . V_853 == 0xf000 && V_1132 -> V_1130 . V_860 == 0xffff0000 &&
! F_408 ( V_2 ) )
V_2 -> V_5 . V_1002 = V_1089 ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
int F_544 ( struct V_1 * V_2 ,
struct V_1161 * V_1162 )
{
unsigned long V_922 ;
int V_3 , V_108 ;
if ( V_1162 -> V_712 & ( V_1163 | V_1164 ) ) {
V_108 = - V_1165 ;
if ( V_2 -> V_5 . V_57 . V_58 )
goto V_102;
if ( V_1162 -> V_712 & V_1163 )
F_28 ( V_2 , V_930 ) ;
else
F_28 ( V_2 , V_1166 ) ;
}
V_922 = F_406 ( V_2 ) ;
V_2 -> V_157 = V_1162 -> V_712 ;
if ( ! ( V_2 -> V_157 & V_1167 ) )
V_2 -> V_157 = 0 ;
if ( V_2 -> V_157 & V_158 ) {
for ( V_3 = 0 ; V_3 < V_1168 ; ++ V_3 )
V_2 -> V_5 . V_169 [ V_3 ] = V_1162 -> V_5 . V_1169 [ V_3 ] ;
V_2 -> V_5 . V_162 = V_1162 -> V_5 . V_1169 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1168 ; V_3 ++ )
V_2 -> V_5 . V_169 [ V_3 ] = V_2 -> V_5 . V_168 [ V_3 ] ;
}
F_85 ( V_2 ) ;
if ( V_2 -> V_157 & V_925 )
V_2 -> V_5 . V_929 = F_407 ( V_2 ) +
F_361 ( V_2 , V_933 ) ;
F_377 ( V_2 , V_922 ) ;
V_64 -> V_1170 ( V_2 ) ;
V_108 = 0 ;
V_102:
return V_108 ;
}
int F_545 ( struct V_1 * V_2 ,
struct V_1171 * V_1143 )
{
unsigned long V_1172 = V_1143 -> V_1173 ;
T_5 V_392 ;
int V_337 ;
V_337 = F_218 ( & V_2 -> V_90 -> V_485 ) ;
V_392 = F_322 ( V_2 , V_1172 , NULL ) ;
F_219 ( & V_2 -> V_90 -> V_485 , V_337 ) ;
V_1143 -> V_1174 = V_392 ;
V_1143 -> V_1175 = V_392 != V_88 ;
V_1143 -> V_1176 = 1 ;
V_1143 -> V_1177 = 0 ;
return 0 ;
}
int F_546 ( struct V_1 * V_2 , struct V_1178 * V_1179 )
{
struct V_636 * V_635 =
& V_2 -> V_5 . V_629 . V_630 -> V_635 ;
memcpy ( V_1179 -> V_1180 , V_635 -> V_1181 , 128 ) ;
V_1179 -> V_1182 = V_635 -> V_1183 ;
V_1179 -> V_1184 = V_635 -> V_1185 ;
V_1179 -> V_1186 = V_635 -> V_1187 ;
V_1179 -> V_1188 = V_635 -> V_1189 ;
V_1179 -> V_1190 = V_635 -> V_1039 ;
V_1179 -> V_1191 = V_635 -> V_1192 ;
memcpy ( V_1179 -> V_1193 , V_635 -> V_1194 , sizeof V_635 -> V_1194 ) ;
return 0 ;
}
int F_547 ( struct V_1 * V_2 , struct V_1178 * V_1179 )
{
struct V_636 * V_635 =
& V_2 -> V_5 . V_629 . V_630 -> V_635 ;
memcpy ( V_635 -> V_1181 , V_1179 -> V_1180 , 128 ) ;
V_635 -> V_1183 = V_1179 -> V_1182 ;
V_635 -> V_1185 = V_1179 -> V_1184 ;
V_635 -> V_1187 = V_1179 -> V_1186 ;
V_635 -> V_1189 = V_1179 -> V_1188 ;
V_635 -> V_1039 = V_1179 -> V_1190 ;
V_635 -> V_1192 = V_1179 -> V_1191 ;
memcpy ( V_635 -> V_1194 , V_1179 -> V_1193 , sizeof V_635 -> V_1194 ) ;
return 0 ;
}
int F_548 ( struct V_1 * V_2 )
{
int V_63 ;
V_63 = F_549 ( & V_2 -> V_5 . V_629 ) ;
if ( V_63 )
return V_63 ;
F_550 ( & V_2 -> V_5 . V_629 ) ;
V_2 -> V_5 . V_130 = V_135 ;
V_2 -> V_5 . V_109 |= V_116 ;
return 0 ;
}
static void F_551 ( struct V_1 * V_2 )
{
F_552 ( & V_2 -> V_5 . V_629 ) ;
}
void F_395 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1195 )
return;
F_65 ( V_2 ) ;
V_2 -> V_1195 = 1 ;
F_553 () ;
F_554 ( & V_2 -> V_5 . V_629 ) ;
F_555 ( 1 ) ;
}
void F_240 ( struct V_1 * V_2 )
{
F_65 ( V_2 ) ;
if ( ! V_2 -> V_1195 )
return;
V_2 -> V_1195 = 0 ;
F_556 ( & V_2 -> V_5 . V_629 ) ;
F_557 () ;
++ V_2 -> V_68 . V_1196 ;
F_27 ( V_1064 , V_2 ) ;
F_555 ( 0 ) ;
}
void F_558 ( struct V_1 * V_2 )
{
F_190 ( V_2 ) ;
F_559 ( V_2 -> V_5 . V_573 ) ;
F_551 ( V_2 ) ;
V_64 -> V_1197 ( V_2 ) ;
}
struct V_1 * F_560 ( struct V_90 * V_90 ,
unsigned int V_1198 )
{
if ( F_131 () && F_126 ( & V_90 -> V_257 ) != 0 )
F_355 ( V_829
L_30
L_31 ) ;
return V_64 -> V_1199 ( V_90 , V_1198 ) ;
}
int F_561 ( struct V_1 * V_2 )
{
int V_108 ;
V_2 -> V_5 . V_332 . V_1200 = 1 ;
V_108 = V_574 ( V_2 ) ;
if ( V_108 )
return V_108 ;
F_562 ( V_2 ) ;
F_563 ( V_2 ) ;
V_578 ( V_2 ) ;
return V_108 ;
}
int F_564 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_31 V_21 ;
V_108 = V_574 ( V_2 ) ;
if ( V_108 )
return V_108 ;
V_21 . V_37 = 0x0 ;
V_21 . V_132 = V_1201 ;
V_21 . V_39 = true ;
F_129 ( V_2 , & V_21 ) ;
V_578 ( V_2 ) ;
return V_108 ;
}
void F_565 ( struct V_1 * V_2 )
{
int V_108 ;
V_2 -> V_5 . V_6 . V_393 = 0 ;
V_108 = V_574 ( V_2 ) ;
F_318 ( V_108 ) ;
F_498 ( V_2 ) ;
V_578 ( V_2 ) ;
F_551 ( V_2 ) ;
V_64 -> V_1197 ( V_2 ) ;
}
void F_562 ( struct V_1 * V_2 )
{
F_148 ( & V_2 -> V_5 . V_76 , 0 ) ;
V_2 -> V_5 . V_614 = 0 ;
V_2 -> V_5 . V_613 = false ;
memset ( V_2 -> V_5 . V_168 , 0 , sizeof( V_2 -> V_5 . V_168 ) ) ;
V_2 -> V_5 . V_160 = V_172 ;
F_84 ( V_2 ) ;
V_2 -> V_5 . V_161 = V_174 ;
F_85 ( V_2 ) ;
F_27 ( V_56 , V_2 ) ;
V_2 -> V_5 . V_6 . V_393 = 0 ;
V_2 -> V_5 . V_397 . V_393 = 0 ;
F_190 ( V_2 ) ;
F_59 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1068 = false ;
F_566 ( V_2 ) ;
memset ( V_2 -> V_5 . V_582 , 0 , sizeof( V_2 -> V_5 . V_582 ) ) ;
V_2 -> V_5 . V_105 = ~ 0 ;
V_2 -> V_5 . V_106 = ~ 0 ;
V_64 -> V_1202 ( V_2 ) ;
}
void F_567 ( struct V_1 * V_2 , unsigned int V_40 )
{
struct V_775 V_1130 ;
F_316 ( V_2 , & V_1130 , V_933 ) ;
V_1130 . V_853 = V_40 << 8 ;
V_1130 . V_860 = V_40 << 12 ;
F_315 ( V_2 , & V_1130 , V_933 ) ;
F_412 ( V_2 , 0 ) ;
}
int F_568 ( void * V_571 )
{
struct V_90 * V_90 ;
struct V_1 * V_2 ;
int V_3 ;
int V_97 ;
T_2 V_1203 ;
T_2 V_1204 = 0 ;
bool V_1205 , V_1206 = false ;
F_14 () ;
V_97 = V_64 -> V_1207 ( V_571 ) ;
if ( V_97 != 0 )
return V_97 ;
V_1203 = F_159 () ;
V_1205 = ! F_131 () ;
F_438 (kvm, &vm_list, vm_list) {
F_152 (i, vcpu, kvm) {
if ( ! V_1205 && V_2 -> V_23 == F_8 () )
F_153 ( V_293 , & V_2 -> V_294 ) ;
if ( V_1205 && V_2 -> V_5 . V_577 > V_1203 ) {
V_1206 = true ;
if ( V_2 -> V_5 . V_577 > V_1204 )
V_1204 = V_2 -> V_5 . V_577 ;
}
}
}
if ( V_1206 ) {
T_2 V_1208 = V_1204 - V_1203 ;
F_438 (kvm, &vm_list, vm_list) {
F_152 (i, vcpu, kvm) {
V_2 -> V_5 . V_575 += V_1208 ;
V_2 -> V_5 . V_577 = V_1203 ;
F_153 ( V_260 ,
& V_2 -> V_294 ) ;
}
V_90 -> V_5 . V_272 = 0 ;
V_90 -> V_5 . V_274 = 0 ;
}
}
return 0 ;
}
void F_569 ( void * V_571 )
{
V_64 -> V_1209 ( V_571 ) ;
F_17 ( V_571 ) ;
}
int F_570 ( void )
{
return V_64 -> V_1210 () ;
}
void F_571 ( void )
{
V_64 -> V_1211 () ;
}
void F_572 ( void * V_1212 )
{
V_64 -> V_1213 ( V_1212 ) ;
}
bool F_573 ( struct V_1 * V_2 )
{
return F_80 ( V_2 -> V_90 ) == ( V_2 -> V_5 . V_583 != NULL ) ;
}
int F_574 ( struct V_1 * V_2 )
{
struct V_362 * V_362 ;
struct V_90 * V_90 ;
int V_108 ;
F_318 ( V_2 -> V_90 == NULL ) ;
V_90 = V_2 -> V_90 ;
V_2 -> V_5 . V_1091 . V_1092 = false ;
V_2 -> V_5 . V_878 . V_804 = & V_1214 ;
if ( ! F_80 ( V_90 ) || F_543 ( V_2 ) )
V_2 -> V_5 . V_1002 = V_1089 ;
else
V_2 -> V_5 . V_1002 = V_1102 ;
V_362 = F_575 ( V_649 | V_1215 ) ;
if ( ! V_362 ) {
V_108 = - V_364 ;
goto V_1216;
}
V_2 -> V_5 . V_834 = F_576 ( V_362 ) ;
F_123 ( V_2 , V_970 ) ;
V_108 = F_577 ( V_2 ) ;
if ( V_108 < 0 )
goto V_1217;
if ( F_80 ( V_90 ) ) {
V_108 = F_578 ( V_2 ) ;
if ( V_108 < 0 )
goto V_1218;
} else
F_579 ( & V_1219 ) ;
V_2 -> V_5 . V_351 = F_264 ( V_440 * sizeof( T_2 ) * 4 ,
V_649 ) ;
if ( ! V_2 -> V_5 . V_351 ) {
V_108 = - V_364 ;
goto V_1220;
}
V_2 -> V_5 . V_343 = V_440 ;
if ( ! F_580 ( & V_2 -> V_5 . V_573 , V_649 ) ) {
V_108 = - V_364 ;
goto V_1221;
}
V_108 = F_548 ( V_2 ) ;
if ( V_108 )
goto V_1222;
V_2 -> V_5 . V_264 = 0x0 ;
V_2 -> V_5 . V_305 = false ;
V_2 -> V_5 . V_138 = 0 ;
V_2 -> V_5 . V_632 = V_1223 + V_633 ;
F_1 ( V_2 ) ;
F_581 ( V_2 ) ;
return 0 ;
V_1222:
F_559 ( V_2 -> V_5 . V_573 ) ;
V_1221:
F_175 ( V_2 -> V_5 . V_351 ) ;
V_1220:
F_582 ( V_2 ) ;
V_1218:
F_583 ( V_2 ) ;
V_1217:
F_584 ( ( unsigned long ) V_2 -> V_5 . V_834 ) ;
V_1216:
return V_108 ;
}
void F_585 ( struct V_1 * V_2 )
{
int V_337 ;
F_586 ( V_2 ) ;
F_175 ( V_2 -> V_5 . V_351 ) ;
F_582 ( V_2 ) ;
V_337 = F_218 ( & V_2 -> V_90 -> V_485 ) ;
F_583 ( V_2 ) ;
F_219 ( & V_2 -> V_90 -> V_485 , V_337 ) ;
F_584 ( ( unsigned long ) V_2 -> V_5 . V_834 ) ;
if ( ! F_80 ( V_2 -> V_90 ) )
F_587 ( & V_1219 ) ;
}
int F_588 ( struct V_90 * V_90 , unsigned long type )
{
if ( type )
return - V_570 ;
F_589 ( & V_90 -> V_5 . V_1224 ) ;
F_589 ( & V_90 -> V_5 . V_1225 ) ;
F_589 ( & V_90 -> V_5 . V_1226 ) ;
F_148 ( & V_90 -> V_5 . V_1227 , 0 ) ;
F_153 ( V_727 , & V_90 -> V_5 . V_1228 ) ;
F_153 ( V_1229 ,
& V_90 -> V_5 . V_1228 ) ;
F_590 ( & V_90 -> V_5 . V_270 ) ;
F_591 ( & V_90 -> V_5 . V_1230 ) ;
F_592 ( & V_90 -> V_5 . V_285 ) ;
F_147 ( V_90 ) ;
return 0 ;
}
static void F_593 ( struct V_1 * V_2 )
{
int V_108 ;
V_108 = V_574 ( V_2 ) ;
F_318 ( V_108 ) ;
F_498 ( V_2 ) ;
V_578 ( V_2 ) ;
}
static void F_594 ( struct V_90 * V_90 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_152 (i, vcpu, kvm) {
F_59 ( V_2 ) ;
F_593 ( V_2 ) ;
}
F_152 (i, vcpu, kvm)
F_558 ( V_2 ) ;
F_202 ( & V_90 -> V_455 ) ;
for ( V_3 = 0 ; V_3 < F_126 ( & V_90 -> V_257 ) ; V_3 ++ )
V_90 -> V_1231 [ V_3 ] = NULL ;
F_148 ( & V_90 -> V_257 , 0 ) ;
F_203 ( & V_90 -> V_455 ) ;
}
void F_595 ( struct V_90 * V_90 )
{
F_596 ( V_90 ) ;
F_597 ( V_90 ) ;
}
void F_598 ( struct V_90 * V_90 )
{
if ( V_399 -> V_1232 == V_90 -> V_1232 ) {
struct V_1233 V_1234 ;
memset ( & V_1234 , 0 , sizeof( V_1234 ) ) ;
V_1234 . V_10 = V_1235 ;
F_599 ( V_90 , & V_1234 ) ;
V_1234 . V_10 = V_1236 ;
F_599 ( V_90 , & V_1234 ) ;
V_1234 . V_10 = V_1237 ;
F_599 ( V_90 , & V_1234 ) ;
}
F_600 ( V_90 ) ;
F_175 ( V_90 -> V_5 . V_739 ) ;
F_175 ( V_90 -> V_5 . V_1238 ) ;
F_594 ( V_90 ) ;
if ( V_90 -> V_5 . V_1239 )
F_601 ( V_90 -> V_5 . V_1239 ) ;
if ( V_90 -> V_5 . V_1240 )
F_601 ( V_90 -> V_5 . V_1240 ) ;
F_175 ( F_602 ( V_90 -> V_5 . V_1241 , 1 ) ) ;
}
void F_603 ( struct V_90 * V_90 , struct V_715 * free ,
struct V_715 * V_1242 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1243 ; ++ V_3 ) {
if ( ! V_1242 || free -> V_5 . V_1244 [ V_3 ] != V_1242 -> V_5 . V_1244 [ V_3 ] ) {
F_604 ( free -> V_5 . V_1244 [ V_3 ] ) ;
free -> V_5 . V_1244 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1242 || free -> V_5 . V_1245 [ V_3 - 1 ] !=
V_1242 -> V_5 . V_1245 [ V_3 - 1 ] ) {
F_604 ( free -> V_5 . V_1245 [ V_3 - 1 ] ) ;
free -> V_5 . V_1245 [ V_3 - 1 ] = NULL ;
}
}
}
int F_605 ( struct V_90 * V_90 , struct V_715 * V_10 ,
unsigned long V_1246 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1243 ; ++ V_3 ) {
unsigned long V_1247 ;
int V_1248 ;
int V_728 = V_3 + 1 ;
V_1248 = F_606 ( V_10 -> V_1249 + V_1246 - 1 ,
V_10 -> V_1249 , V_728 ) + 1 ;
V_10 -> V_5 . V_1244 [ V_3 ] =
F_607 ( V_1248 * sizeof( * V_10 -> V_5 . V_1244 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1244 [ V_3 ] )
goto V_365;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1245 [ V_3 - 1 ] = F_607 ( V_1248 *
sizeof( * V_10 -> V_5 . V_1245 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1245 [ V_3 - 1 ] )
goto V_365;
if ( V_10 -> V_1249 & ( F_608 ( V_728 ) - 1 ) )
V_10 -> V_5 . V_1245 [ V_3 - 1 ] [ 0 ] . V_1250 = 1 ;
if ( ( V_10 -> V_1249 + V_1246 ) & ( F_608 ( V_728 ) - 1 ) )
V_10 -> V_5 . V_1245 [ V_3 - 1 ] [ V_1248 - 1 ] . V_1250 = 1 ;
V_1247 = V_10 -> V_1251 >> V_95 ;
if ( ( V_10 -> V_1249 ^ V_1247 ) & ( F_608 ( V_728 ) - 1 ) ||
! F_609 () ) {
unsigned long V_769 ;
for ( V_769 = 0 ; V_769 < V_1248 ; ++ V_769 )
V_10 -> V_5 . V_1245 [ V_3 - 1 ] [ V_769 ] . V_1250 = 1 ;
}
}
return 0 ;
V_365:
for ( V_3 = 0 ; V_3 < V_1243 ; ++ V_3 ) {
F_604 ( V_10 -> V_5 . V_1244 [ V_3 ] ) ;
V_10 -> V_5 . V_1244 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_604 ( V_10 -> V_5 . V_1245 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1245 [ V_3 - 1 ] = NULL ;
}
return - V_364 ;
}
void F_610 ( struct V_90 * V_90 )
{
F_611 ( V_90 ) ;
}
int F_612 ( struct V_90 * V_90 ,
struct V_715 * V_716 ,
struct V_1233 * V_1234 ,
enum V_1252 V_1253 )
{
if ( ( V_716 -> V_1198 >= V_538 ) && ( V_1253 == V_1254 ) ) {
unsigned long V_1251 ;
V_1251 = F_613 ( NULL , 0 , V_716 -> V_1246 * V_96 ,
V_1255 | V_1256 ,
V_1257 | V_1258 , 0 ) ;
if ( F_173 ( ( void * ) V_1251 ) )
return F_174 ( ( void * ) V_1251 ) ;
V_716 -> V_1251 = V_1251 ;
}
return 0 ;
}
void F_614 ( struct V_90 * V_90 ,
struct V_1233 * V_1234 ,
const struct V_715 * V_822 ,
enum V_1252 V_1253 )
{
int V_1259 = 0 ;
if ( ( V_1234 -> V_10 >= V_538 ) && ( V_1253 == V_1260 ) ) {
int V_97 ;
V_97 = F_615 ( V_822 -> V_1251 ,
V_822 -> V_1246 * V_96 ) ;
if ( V_97 < 0 )
F_10 ( V_829
L_32
L_33 ) ;
}
if ( ! V_90 -> V_5 . V_688 )
V_1259 = F_616 ( V_90 ) ;
if ( V_1259 )
F_273 ( V_90 , V_1259 ) ;
if ( ( V_1253 != V_1260 ) && ( V_1234 -> V_267 & V_1261 ) )
F_617 ( V_90 , V_1234 -> V_10 ) ;
}
void F_618 ( struct V_90 * V_90 )
{
F_619 ( V_90 ) ;
}
void F_620 ( struct V_90 * V_90 ,
struct V_715 * V_10 )
{
F_619 ( V_90 ) ;
}
int F_621 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_1002 == V_1089 &&
! V_2 -> V_5 . V_6 . V_1068 )
|| ! F_622 ( & V_2 -> V_1262 . V_1263 )
|| F_623 ( V_2 )
|| V_2 -> V_5 . V_1091 . V_1092
|| F_126 ( & V_2 -> V_5 . V_76 ) ||
( F_483 ( V_2 ) &&
F_482 ( V_2 ) ) ;
}
int F_624 ( struct V_1 * V_2 )
{
return F_625 ( V_2 ) == V_1078 ;
}
int F_483 ( struct V_1 * V_2 )
{
return V_64 -> V_1050 ( V_2 ) ;
}
bool F_626 ( struct V_1 * V_2 , unsigned long V_1264 )
{
unsigned long V_1265 = F_407 ( V_2 ) +
F_361 ( V_2 , V_933 ) ;
return V_1265 == V_1264 ;
}
unsigned long F_406 ( struct V_1 * V_2 )
{
unsigned long V_922 ;
V_922 = V_64 -> V_923 ( V_2 ) ;
if ( V_2 -> V_157 & V_925 )
V_922 &= ~ V_924 ;
return V_922 ;
}
void F_377 ( struct V_1 * V_2 , unsigned long V_922 )
{
if ( V_2 -> V_157 & V_925 &&
F_626 ( V_2 , V_2 -> V_5 . V_929 ) )
V_922 |= V_924 ;
V_64 -> V_1266 ( V_2 , V_922 ) ;
F_27 ( V_56 , V_2 ) ;
}
void F_627 ( struct V_1 * V_2 , struct V_1267 * V_985 )
{
int V_108 ;
if ( ( V_2 -> V_5 . V_75 . V_914 != V_985 -> V_5 . V_914 ) ||
V_985 -> V_1268 )
return;
V_108 = F_505 ( V_2 ) ;
if ( F_143 ( V_108 ) )
return;
if ( ! V_2 -> V_5 . V_75 . V_914 &&
V_985 -> V_5 . V_93 != V_2 -> V_5 . V_75 . V_1269 ( V_2 ) )
return;
V_2 -> V_5 . V_75 . V_1270 ( V_2 , V_985 -> V_782 , 0 , true ) ;
}
static inline T_1 F_628 ( T_4 V_91 )
{
return F_629 ( V_91 & 0xffffffff , F_630 ( V_4 ) ) ;
}
static inline T_1 F_631 ( T_1 V_1271 )
{
return ( V_1271 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_632 ( struct V_1 * V_2 , T_4 V_91 )
{
T_1 V_1271 = F_628 ( V_91 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1271 ] != ~ 0 )
V_1271 = F_631 ( V_1271 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1271 ] = V_91 ;
}
static T_1 F_633 ( struct V_1 * V_2 , T_4 V_91 )
{
int V_3 ;
T_1 V_1271 = F_628 ( V_91 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1271 ] != V_91 &&
V_2 -> V_5 . V_6 . V_7 [ V_1271 ] != ~ 0 ) ; V_3 ++ )
V_1271 = F_631 ( V_1271 ) ;
return V_1271 ;
}
bool F_634 ( struct V_1 * V_2 , T_4 V_91 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_633 ( V_2 , V_91 ) ] == V_91 ;
}
static void F_635 ( struct V_1 * V_2 , T_4 V_91 )
{
T_1 V_3 , V_769 , V_1272 ;
V_3 = V_769 = F_633 ( V_2 , V_91 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_769 = F_631 ( V_769 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_769 ] == ~ 0 )
return;
V_1272 = F_628 ( V_2 -> V_5 . V_6 . V_7 [ V_769 ] ) ;
} while ( ( V_3 <= V_769 ) ? ( V_3 < V_1272 && V_1272 <= V_769 ) : ( V_3 < V_1272 || V_1272 <= V_769 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_769 ] ;
V_3 = V_769 ;
}
}
static int F_636 ( struct V_1 * V_2 , T_1 V_167 )
{
return F_162 ( V_2 -> V_90 , & V_2 -> V_5 . V_6 . V_37 , & V_167 ,
sizeof( V_167 ) ) ;
}
void F_637 ( struct V_1 * V_2 ,
struct V_1267 * V_985 )
{
struct V_66 V_67 ;
F_638 ( V_985 -> V_5 . V_1273 , V_985 -> V_782 ) ;
F_632 ( V_2 , V_985 -> V_5 . V_91 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_393 & V_394 ) ||
( V_2 -> V_5 . V_6 . V_395 &&
V_64 -> V_79 ( V_2 ) == 0 ) )
F_27 ( V_1067 , V_2 ) ;
else if ( ! F_636 ( V_2 , V_1274 ) ) {
V_67 . V_40 = V_41 ;
V_67 . V_879 = true ;
V_67 . V_51 = 0 ;
V_67 . V_72 = false ;
V_67 . V_71 = V_985 -> V_5 . V_1273 ;
F_32 ( V_2 , & V_67 ) ;
}
}
void F_639 ( struct V_1 * V_2 ,
struct V_1267 * V_985 )
{
struct V_66 V_67 ;
F_640 ( V_985 -> V_5 . V_1273 , V_985 -> V_782 ) ;
if ( V_985 -> V_1268 )
V_985 -> V_5 . V_1273 = ~ 0 ;
else
F_635 ( V_2 , V_985 -> V_5 . V_91 ) ;
if ( ( V_2 -> V_5 . V_6 . V_393 & V_394 ) &&
! F_636 ( V_2 , V_1275 ) ) {
V_67 . V_40 = V_41 ;
V_67 . V_879 = true ;
V_67 . V_51 = 0 ;
V_67 . V_72 = false ;
V_67 . V_71 = V_985 -> V_5 . V_1273 ;
F_32 ( V_2 , & V_67 ) ;
}
V_2 -> V_5 . V_6 . V_1068 = false ;
V_2 -> V_5 . V_1002 = V_1089 ;
}
bool F_641 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_393 & V_394 ) )
return true ;
else
return ! F_485 ( V_2 ) &&
V_64 -> V_1050 ( V_2 ) ;
}
void F_642 ( struct V_90 * V_90 )
{
F_37 ( & V_90 -> V_5 . V_1227 ) ;
}
void F_643 ( struct V_90 * V_90 )
{
F_644 ( & V_90 -> V_5 . V_1227 ) ;
}
bool F_232 ( struct V_90 * V_90 )
{
return F_126 ( & V_90 -> V_5 . V_1227 ) ;
}
