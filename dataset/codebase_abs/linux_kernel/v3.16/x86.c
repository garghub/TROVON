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
T_3 T_4 void F_23 ( void )
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
T_5 V_81 , void * V_37 , int V_82 , int V_83 ,
T_1 V_84 )
{
T_5 V_85 ;
T_6 V_86 ;
V_86 = F_41 ( V_81 ) ;
V_85 = V_75 -> V_87 ( V_2 , V_86 , V_84 ) ;
if ( V_85 == V_88 )
return - V_89 ;
V_85 = F_42 ( V_85 ) ;
return F_43 ( V_2 -> V_90 , V_85 , V_37 , V_82 , V_83 ) ;
}
int F_44 ( struct V_1 * V_2 , T_5 V_91 ,
void * V_37 , int V_82 , int V_83 , T_1 V_84 )
{
return F_40 ( V_2 , V_2 -> V_5 . V_92 , V_91 ,
V_37 , V_82 , V_83 , V_84 ) ;
}
int F_45 ( struct V_1 * V_2 , struct V_80 * V_75 , unsigned long V_93 )
{
T_5 V_94 = V_93 >> V_95 ;
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
T_5 V_91 ;
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
T_2 V_130 = V_133 ;
T_2 V_134 = V_2 -> V_5 . V_130 ;
T_2 V_135 ;
if ( V_132 != V_129 )
return 1 ;
if ( ! ( V_130 & V_136 ) )
return 1 ;
if ( ( V_130 & V_137 ) && ! ( V_130 & V_138 ) )
return 1 ;
V_135 = V_2 -> V_5 . V_139 | V_136 ;
if ( V_130 & ~ V_135 )
return 1 ;
if ( ( ! ( V_130 & V_140 ) ) != ( ! ( V_130 & V_141 ) ) )
return 1 ;
F_65 ( V_2 ) ;
V_2 -> V_5 . V_130 = V_130 ;
if ( ( V_130 ^ V_134 ) & V_142 )
F_67 ( V_2 ) ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 , T_1 V_132 , T_2 V_133 )
{
if ( V_64 -> V_79 ( V_2 ) != 0 ||
F_66 ( V_2 , V_132 , V_133 ) ) {
F_31 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_69 ( struct V_1 * V_2 , unsigned long V_143 )
{
unsigned long V_144 = F_70 ( V_2 ) ;
unsigned long V_145 = V_146 | V_147 |
V_148 | V_149 ;
if ( V_143 & V_150 )
return 1 ;
if ( ! F_71 ( V_2 ) && ( V_143 & V_127 ) )
return 1 ;
if ( ! F_72 ( V_2 ) && ( V_143 & V_149 ) )
return 1 ;
if ( ! F_73 ( V_2 ) && ( V_143 & V_151 ) )
return 1 ;
if ( ! F_74 ( V_2 ) && ( V_143 & V_152 ) )
return 1 ;
if ( F_50 ( V_2 ) ) {
if ( ! ( V_143 & V_148 ) )
return 1 ;
} else if ( F_57 ( V_2 ) && ( V_143 & V_148 )
&& ( ( V_143 ^ V_144 ) & V_145 )
&& ! F_45 ( V_2 , V_2 -> V_5 . V_92 ,
F_53 ( V_2 ) ) )
return 1 ;
if ( ( V_143 & V_124 ) && ! ( V_144 & V_124 ) ) {
if ( ! F_75 ( V_2 ) )
return 1 ;
if ( ( F_53 ( V_2 ) & V_153 ) || ! F_50 ( V_2 ) )
return 1 ;
}
if ( V_64 -> V_154 ( V_2 , V_143 ) )
return 1 ;
if ( ( ( V_143 ^ V_144 ) & V_145 ) ||
( ! ( V_143 & V_124 ) && ( V_144 & V_124 ) ) )
F_60 ( V_2 ) ;
if ( ( V_143 ^ V_144 ) & V_151 )
F_76 ( V_2 , V_2 -> V_5 . V_92 , false ) ;
if ( ( V_143 ^ V_144 ) & V_127 )
F_67 ( V_2 ) ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 , unsigned long V_93 )
{
if ( V_93 == F_53 ( V_2 ) && ! F_49 ( V_2 ) ) {
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
return 0 ;
}
if ( F_50 ( V_2 ) ) {
if ( V_93 & V_155 )
return 1 ;
} else if ( F_51 ( V_2 ) && F_57 ( V_2 ) &&
! F_45 ( V_2 , V_2 -> V_5 . V_92 , V_93 ) )
return 1 ;
V_2 -> V_5 . V_93 = V_93 ;
F_48 ( V_156 , ( V_157 * ) & V_2 -> V_5 . V_105 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
int F_81 ( struct V_1 * V_2 , unsigned long V_158 )
{
if ( V_158 & V_159 )
return 1 ;
if ( F_82 ( V_2 -> V_90 ) )
F_83 ( V_2 , V_158 ) ;
else
V_2 -> V_5 . V_158 = V_158 ;
return 0 ;
}
unsigned long F_84 ( struct V_1 * V_2 )
{
if ( F_82 ( V_2 -> V_90 ) )
return F_85 ( V_2 ) ;
else
return V_2 -> V_5 . V_158 ;
}
static void F_86 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_160 & V_161 ) )
V_64 -> V_162 ( V_2 , V_2 -> V_5 . V_163 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
unsigned long V_164 ;
if ( V_2 -> V_160 & V_161 )
V_164 = V_2 -> V_5 . V_165 ;
else
V_164 = V_2 -> V_5 . V_164 ;
V_64 -> V_166 ( V_2 , V_164 ) ;
V_2 -> V_5 . V_167 &= ~ V_168 ;
if ( V_164 & V_169 )
V_2 -> V_5 . V_167 |= V_168 ;
}
static int F_88 ( struct V_1 * V_2 , int V_170 , unsigned long V_171 )
{
switch ( V_170 ) {
case 0 ... 3 :
V_2 -> V_5 . V_172 [ V_170 ] = V_171 ;
if ( ! ( V_2 -> V_160 & V_161 ) )
V_2 -> V_5 . V_173 [ V_170 ] = V_171 ;
break;
case 4 :
if ( F_58 ( V_2 , V_174 ) )
return 1 ;
case 6 :
if ( V_171 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_163 = ( V_171 & V_175 ) | V_176 ;
F_86 ( V_2 ) ;
break;
case 5 :
if ( F_58 ( V_2 , V_174 ) )
return 1 ;
default:
if ( V_171 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_164 = ( V_171 & V_177 ) | V_178 ;
F_87 ( V_2 ) ;
break;
}
return 0 ;
}
int F_89 ( struct V_1 * V_2 , int V_170 , unsigned long V_171 )
{
int V_179 ;
V_179 = F_88 ( V_2 , V_170 , V_171 ) ;
if ( V_179 > 0 )
F_28 ( V_2 , V_180 ) ;
else if ( V_179 < 0 )
F_31 ( V_2 , 0 ) ;
return V_179 ;
}
static int F_90 ( struct V_1 * V_2 , int V_170 , unsigned long * V_171 )
{
switch ( V_170 ) {
case 0 ... 3 :
* V_171 = V_2 -> V_5 . V_172 [ V_170 ] ;
break;
case 4 :
if ( F_58 ( V_2 , V_174 ) )
return 1 ;
case 6 :
if ( V_2 -> V_160 & V_161 )
* V_171 = V_2 -> V_5 . V_163 ;
else
* V_171 = V_64 -> V_181 ( V_2 ) ;
break;
case 5 :
if ( F_58 ( V_2 , V_174 ) )
return 1 ;
default:
* V_171 = V_2 -> V_5 . V_164 ;
break;
}
return 0 ;
}
int F_91 ( struct V_1 * V_2 , int V_170 , unsigned long * V_171 )
{
if ( F_90 ( V_2 , V_170 , V_171 ) ) {
F_28 ( V_2 , V_180 ) ;
return 1 ;
}
return 0 ;
}
bool F_92 ( struct V_1 * V_2 )
{
T_1 V_182 = F_93 ( V_2 , V_183 ) ;
T_2 V_37 ;
int V_63 ;
V_63 = F_94 ( V_2 , V_182 , & V_37 ) ;
if ( V_63 )
return V_63 ;
F_95 ( V_2 , V_184 , ( T_1 ) V_37 ) ;
F_95 ( V_2 , V_185 , V_37 >> 32 ) ;
return V_63 ;
}
bool F_96 ( struct V_1 * V_2 , T_2 V_119 )
{
if ( V_119 & V_186 )
return false ;
if ( V_119 & V_187 ) {
struct V_188 * V_189 ;
V_189 = F_97 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_189 || ! ( V_189 -> V_190 & F_98 ( V_191 ) ) )
return false ;
}
if ( V_119 & V_192 ) {
struct V_188 * V_189 ;
V_189 = F_97 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_189 || ! ( V_189 -> V_182 & F_98 ( V_193 ) ) )
return false ;
}
return true ;
}
static int F_99 ( struct V_1 * V_2 , T_2 V_119 )
{
T_2 V_194 = V_2 -> V_5 . V_119 ;
if ( ! F_96 ( V_2 , V_119 ) )
return 1 ;
if ( F_57 ( V_2 )
&& ( V_2 -> V_5 . V_119 & V_120 ) != ( V_119 & V_120 ) )
return 1 ;
V_119 &= ~ V_195 ;
V_119 |= V_2 -> V_5 . V_119 & V_195 ;
V_64 -> F_99 ( V_2 , V_119 ) ;
if ( ( V_119 ^ V_194 ) & V_196 )
F_60 ( V_2 ) ;
return 0 ;
}
void F_100 ( T_2 V_27 )
{
V_186 &= ~ V_27 ;
}
int F_101 ( struct V_1 * V_2 , struct V_31 * V_21 )
{
return V_64 -> V_197 ( V_2 , V_21 ) ;
}
static int F_102 ( struct V_1 * V_2 , unsigned V_132 , T_2 * V_37 )
{
struct V_31 V_21 ;
V_21 . V_37 = * V_37 ;
V_21 . V_132 = V_132 ;
V_21 . V_39 = true ;
return F_101 ( V_2 , & V_21 ) ;
}
static void F_103 ( struct V_198 * V_199 )
{
struct V_200 * V_201 = & V_200 ;
F_104 ( & V_201 -> V_202 ) ;
V_201 -> clock . V_203 = V_199 -> clock -> V_204 . V_203 ;
V_201 -> clock . V_205 = V_199 -> clock -> V_205 ;
V_201 -> clock . V_27 = V_199 -> clock -> V_27 ;
V_201 -> clock . V_206 = V_199 -> V_206 ;
V_201 -> clock . V_207 = V_199 -> V_207 ;
V_201 -> V_208 = V_199 -> V_209
+ V_199 -> V_210 . V_211 ;
V_201 -> V_212 = V_199 -> V_213
+ ( V_199 -> V_210 . V_214
<< V_199 -> V_207 ) ;
while ( V_201 -> V_212 >=
( ( ( T_2 ) V_215 ) << V_199 -> V_207 ) ) {
V_201 -> V_212 -=
( ( T_2 ) V_215 ) << V_199 -> V_207 ;
V_201 -> V_208 ++ ;
}
F_105 ( & V_201 -> V_202 ) ;
}
static void F_106 ( struct V_90 * V_90 , T_6 V_216 )
{
int V_217 ;
int V_108 ;
struct V_218 V_219 ;
struct V_220 V_221 ;
if ( ! V_216 )
return;
V_108 = F_107 ( V_90 , V_216 , & V_217 , sizeof( V_217 ) ) ;
if ( V_108 )
return;
if ( V_217 & 1 )
++ V_217 ;
++ V_217 ;
F_108 ( V_90 , V_216 , & V_217 , sizeof( V_217 ) ) ;
F_109 ( & V_221 ) ;
if ( V_90 -> V_5 . V_222 ) {
struct V_220 V_223 = F_110 ( V_90 -> V_5 . V_222 ) ;
V_221 = F_111 ( V_221 , V_223 ) ;
}
V_219 . V_224 = V_221 . V_211 ;
V_219 . V_225 = V_221 . V_214 ;
V_219 . V_217 = V_217 ;
F_108 ( V_90 , V_216 , & V_219 , sizeof( V_219 ) ) ;
V_217 ++ ;
F_108 ( V_90 , V_216 , & V_217 , sizeof( V_217 ) ) ;
}
static T_7 F_112 ( T_7 V_226 , T_7 V_227 )
{
T_7 V_228 , V_229 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_228 ;
}
static void F_113 ( T_7 V_230 , T_7 V_231 ,
T_8 * V_232 , T_1 * V_233 )
{
T_9 V_234 ;
T_10 V_207 = 0 ;
T_9 V_235 ;
T_7 V_236 ;
V_235 = V_231 * 1000LL ;
V_234 = V_230 * 1000LL ;
while ( V_235 > V_234 * 2 || V_235 & 0xffffffff00000000ULL ) {
V_235 >>= 1 ;
V_207 -- ;
}
V_236 = ( T_7 ) V_235 ;
while ( V_236 <= V_234 || V_234 & 0xffffffff00000000ULL ) {
if ( V_234 & 0xffffffff00000000ULL || V_236 & 0x80000000 )
V_234 >>= 1 ;
else
V_236 <<= 1 ;
V_207 ++ ;
}
* V_232 = V_207 ;
* V_233 = F_112 ( V_234 , V_236 ) ;
F_114 ( L_2 ,
V_237 , V_231 , V_230 , V_207 , * V_233 ) ;
}
static inline T_2 F_115 ( void )
{
struct V_220 V_223 ;
F_116 ( & V_223 ) ;
F_117 ( & V_223 ) ;
return F_118 ( & V_223 ) ;
}
static inline T_2 F_119 ( struct V_1 * V_2 , T_2 V_225 )
{
return F_120 ( V_225 , V_2 -> V_5 . V_238 ,
V_2 -> V_5 . V_239 ) ;
}
static T_1 F_121 ( T_1 V_240 , T_11 V_241 )
{
T_2 V_242 = ( T_2 ) V_240 * ( 1000000 + V_241 ) ;
F_122 ( V_242 , 1000000 ) ;
return V_242 ;
}
static void F_123 ( struct V_1 * V_2 , T_1 V_243 )
{
T_1 V_244 , V_245 ;
int V_246 = 0 ;
if ( V_243 == 0 )
return;
F_113 ( V_243 , V_215 / 1000 ,
& V_2 -> V_5 . V_239 ,
& V_2 -> V_5 . V_238 ) ;
V_2 -> V_5 . V_247 = V_243 ;
V_244 = F_121 ( V_248 , - V_249 ) ;
V_245 = F_121 ( V_248 , V_249 ) ;
if ( V_243 < V_244 || V_243 > V_245 ) {
F_114 ( L_3 , V_243 , V_244 , V_245 ) ;
V_246 = 1 ;
}
V_64 -> V_250 ( V_2 , V_243 , V_246 ) ;
}
static T_2 F_124 ( struct V_1 * V_2 , T_12 V_251 )
{
T_2 V_252 = F_120 ( V_251 - V_2 -> V_5 . V_253 ,
V_2 -> V_5 . V_238 ,
V_2 -> V_5 . V_239 ) ;
V_252 += V_2 -> V_5 . V_254 ;
return V_252 ;
}
void F_125 ( struct V_1 * V_2 )
{
#ifdef F_56
bool V_255 ;
bool V_256 = false ;
struct V_257 * V_258 = & V_2 -> V_90 -> V_5 ;
struct V_200 * V_259 = & V_200 ;
V_255 = ( V_258 -> V_260 + 1 ==
F_126 ( & V_2 -> V_90 -> V_261 ) ) ;
if ( V_255 && V_259 -> clock . V_203 == V_262 )
if ( ! V_258 -> V_263 )
V_256 = 1 ;
if ( ! V_255 && V_258 -> V_263 )
V_256 = 1 ;
if ( V_256 )
F_27 ( V_264 , V_2 ) ;
F_127 ( V_2 -> V_265 , V_258 -> V_260 ,
F_126 ( & V_2 -> V_90 -> V_261 ) ,
V_258 -> V_263 , V_259 -> clock . V_203 ) ;
#endif
}
static void F_128 ( struct V_1 * V_2 , T_12 V_82 )
{
T_2 V_266 = V_64 -> V_267 ( V_2 ) ;
V_2 -> V_5 . V_268 += V_82 - V_266 ;
}
void F_129 ( struct V_1 * V_2 , struct V_31 * V_21 )
{
struct V_90 * V_90 = V_2 -> V_90 ;
T_2 V_82 , V_269 , V_270 ;
unsigned long V_271 ;
T_12 V_272 ;
bool V_273 ;
T_2 V_37 = V_21 -> V_37 ;
F_130 ( & V_90 -> V_5 . V_274 , V_271 ) ;
V_82 = V_64 -> V_275 ( V_2 , V_37 ) ;
V_269 = F_115 () ;
V_270 = V_269 - V_90 -> V_5 . V_276 ;
if ( V_2 -> V_5 . V_247 ) {
int V_277 = 0 ;
V_272 = V_37 - V_90 -> V_5 . V_278 ;
#ifdef F_56
V_272 = ( V_272 * 1000 ) / V_2 -> V_5 . V_247 ;
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
F_122 ( V_270 , 1000 ) ;
V_272 -= V_270 ;
if ( V_272 < 0 )
V_272 = - V_272 ;
if ( V_277 )
V_272 = V_279 ;
} else
V_272 = V_279 ;
if ( V_272 < V_279 &&
V_2 -> V_5 . V_247 == V_90 -> V_5 . V_280 ) {
if ( ! F_131 () ) {
V_82 = V_90 -> V_5 . V_281 ;
F_114 ( L_4 , V_37 ) ;
} else {
T_2 V_282 = F_119 ( V_2 , V_270 ) ;
V_37 += V_282 ;
V_82 = V_64 -> V_275 ( V_2 , V_37 ) ;
F_114 ( L_5 , V_282 ) ;
}
V_273 = true ;
} else {
V_90 -> V_5 . V_283 ++ ;
V_90 -> V_5 . V_284 = V_269 ;
V_90 -> V_5 . V_285 = V_37 ;
V_90 -> V_5 . V_281 = V_82 ;
V_273 = false ;
F_114 ( L_6 ,
V_90 -> V_5 . V_283 , V_37 ) ;
}
V_90 -> V_5 . V_276 = V_269 ;
V_90 -> V_5 . V_278 = V_37 ;
V_90 -> V_5 . V_280 = V_2 -> V_5 . V_247 ;
V_2 -> V_5 . V_286 = V_37 ;
V_2 -> V_5 . V_287 = V_90 -> V_5 . V_283 ;
V_2 -> V_5 . V_253 = V_90 -> V_5 . V_284 ;
V_2 -> V_5 . V_254 = V_90 -> V_5 . V_285 ;
if ( F_132 ( V_2 ) && ! V_21 -> V_39 )
F_128 ( V_2 , V_82 ) ;
V_64 -> V_288 ( V_2 , V_82 ) ;
F_133 ( & V_90 -> V_5 . V_274 , V_271 ) ;
F_134 ( & V_90 -> V_5 . V_289 ) ;
if ( V_273 )
V_90 -> V_5 . V_260 ++ ;
else
V_90 -> V_5 . V_260 = 0 ;
F_125 ( V_2 ) ;
F_135 ( & V_90 -> V_5 . V_289 ) ;
}
static T_13 F_136 ( void )
{
T_13 V_97 ;
T_2 V_290 ;
F_137 () ;
V_97 = ( T_13 ) F_138 () ;
V_290 = V_200 . clock . V_205 ;
if ( F_139 ( V_97 >= V_290 ) )
return V_97 ;
asm volatile ("");
return V_290 ;
}
static inline T_2 F_140 ( T_13 * V_291 )
{
long V_242 ;
struct V_200 * V_259 = & V_200 ;
* V_291 = F_136 () ;
V_242 = ( * V_291 - V_259 -> clock . V_205 ) & V_259 -> clock . V_27 ;
return V_242 * V_259 -> clock . V_206 ;
}
static int F_141 ( struct V_220 * V_223 , T_13 * V_291 )
{
unsigned long V_202 ;
T_2 V_269 ;
int V_292 ;
struct V_200 * V_259 = & V_200 ;
V_223 -> V_214 = 0 ;
do {
V_202 = F_142 ( & V_259 -> V_202 ) ;
V_292 = V_259 -> clock . V_203 ;
V_223 -> V_211 = V_259 -> V_208 ;
V_269 = V_259 -> V_212 ;
V_269 += F_140 ( V_291 ) ;
V_269 >>= V_259 -> clock . V_207 ;
} while ( F_143 ( F_144 ( & V_259 -> V_202 , V_202 ) ) );
F_145 ( V_223 , V_269 ) ;
return V_292 ;
}
static bool F_146 ( T_12 * V_251 , T_13 * V_291 )
{
struct V_220 V_223 ;
if ( V_200 . clock . V_203 != V_262 )
return false ;
if ( F_141 ( & V_223 , V_291 ) != V_262 )
return false ;
F_117 ( & V_223 ) ;
* V_251 = F_118 ( & V_223 ) ;
return true ;
}
static void F_147 ( struct V_90 * V_90 )
{
#ifdef F_56
struct V_257 * V_258 = & V_90 -> V_5 ;
int V_203 ;
bool V_293 , V_255 ;
V_255 = ( V_258 -> V_260 + 1 ==
F_126 ( & V_90 -> V_261 ) ) ;
V_293 = F_146 (
& V_258 -> V_294 ,
& V_258 -> V_295 ) ;
V_258 -> V_263 = V_293 && V_255
&& ! V_296 ;
if ( V_258 -> V_263 )
F_148 ( & V_297 , 1 ) ;
V_203 = V_200 . clock . V_203 ;
F_149 ( V_258 -> V_263 , V_203 ,
V_255 ) ;
#endif
}
static void F_150 ( struct V_90 * V_90 )
{
#ifdef F_56
int V_3 ;
struct V_1 * V_2 ;
struct V_257 * V_258 = & V_90 -> V_5 ;
F_134 ( & V_258 -> V_289 ) ;
F_151 ( V_90 ) ;
F_147 ( V_90 ) ;
F_152 (i, vcpu, kvm)
F_153 ( V_298 , & V_2 -> V_299 ) ;
F_152 (i, vcpu, kvm)
F_154 ( V_300 , & V_2 -> V_299 ) ;
F_135 ( & V_258 -> V_289 ) ;
#endif
}
static int F_155 ( struct V_1 * V_242 )
{
unsigned long V_271 , V_243 ;
struct V_301 * V_2 = & V_242 -> V_5 ;
struct V_257 * V_258 = & V_242 -> V_90 -> V_5 ;
T_12 V_251 ;
T_2 V_302 , V_303 ;
struct V_304 V_305 ;
T_14 V_306 ;
bool V_263 ;
V_251 = 0 ;
V_303 = 0 ;
F_134 ( & V_258 -> V_289 ) ;
V_263 = V_258 -> V_263 ;
if ( V_263 ) {
V_303 = V_258 -> V_295 ;
V_251 = V_258 -> V_294 ;
}
F_135 ( & V_258 -> V_289 ) ;
F_156 ( V_271 ) ;
V_243 = F_157 ( V_307 ) ;
if ( F_143 ( V_243 == 0 ) ) {
F_158 ( V_271 ) ;
F_27 ( V_298 , V_242 ) ;
return 1 ;
}
if ( ! V_263 ) {
V_303 = F_159 () ;
V_251 = F_115 () ;
}
V_302 = V_64 -> V_308 ( V_242 , V_303 ) ;
if ( V_2 -> V_309 ) {
T_2 V_252 = F_124 ( V_242 , V_251 ) ;
if ( V_252 > V_302 ) {
F_160 ( V_242 , V_252 - V_302 ) ;
V_302 = V_252 ;
}
}
F_158 ( V_271 ) ;
if ( ! V_2 -> V_310 )
return 0 ;
if ( F_143 ( V_2 -> V_311 != V_243 ) ) {
F_113 ( V_215 / 1000 , V_243 ,
& V_2 -> V_312 . V_313 ,
& V_2 -> V_312 . V_314 ) ;
V_2 -> V_311 = V_243 ;
}
V_2 -> V_312 . V_302 = V_302 ;
V_2 -> V_312 . V_315 = V_251 + V_242 -> V_90 -> V_5 . V_222 ;
V_2 -> V_286 = V_302 ;
V_2 -> V_312 . V_217 += 2 ;
if ( F_143 ( F_161 ( V_242 -> V_90 , & V_2 -> V_316 ,
& V_305 , sizeof( V_305 ) ) ) )
return 0 ;
V_306 = ( V_305 . V_271 & V_317 ) ;
if ( V_2 -> V_318 ) {
V_306 |= V_317 ;
V_2 -> V_318 = false ;
}
if ( V_263 )
V_306 |= V_319 ;
V_2 -> V_312 . V_271 = V_306 ;
F_162 ( V_242 -> V_90 , & V_2 -> V_316 ,
& V_2 -> V_312 ,
sizeof( V_2 -> V_312 ) ) ;
return 0 ;
}
static void F_163 ( struct V_320 * V_321 )
{
int V_3 ;
struct V_322 * V_323 = F_164 ( V_321 ) ;
struct V_257 * V_258 = F_4 ( V_323 , struct V_257 ,
V_324 ) ;
struct V_90 * V_90 = F_4 ( V_258 , struct V_90 , V_5 ) ;
struct V_1 * V_2 ;
F_152 (i, vcpu, kvm) {
F_153 ( V_298 , & V_2 -> V_299 ) ;
F_165 ( V_2 ) ;
}
}
static void F_166 ( struct V_1 * V_242 )
{
struct V_90 * V_90 = V_242 -> V_90 ;
F_153 ( V_298 , & V_242 -> V_299 ) ;
F_167 ( & V_90 -> V_5 . V_324 ,
V_325 ) ;
}
static void F_168 ( struct V_320 * V_321 )
{
struct V_322 * V_323 = F_164 ( V_321 ) ;
struct V_257 * V_258 = F_4 ( V_323 , struct V_257 ,
V_326 ) ;
struct V_90 * V_90 = F_4 ( V_258 , struct V_90 , V_5 ) ;
F_167 ( & V_90 -> V_5 . V_324 , 0 ) ;
F_167 ( & V_90 -> V_5 . V_326 ,
V_327 ) ;
}
static bool F_169 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_328 - 1 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_170 ( unsigned V_342 )
{
return V_342 < 8 && ( 1 << V_342 ) & 0xf3 ;
}
static bool F_171 ( unsigned V_342 )
{
return V_342 < 8 && ( 1 << V_342 ) & 0x73 ;
}
static bool F_172 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
int V_3 ;
if ( ! F_169 ( V_21 ) )
return false ;
if ( V_21 == V_341 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_170 ( ( V_37 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_340 ) {
if ( V_37 & ~ 0xcff )
return false ;
return F_171 ( V_37 & 0xff ) ;
} else if ( V_21 >= V_329 && V_21 <= V_339 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_171 ( ( V_37 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_171 ( V_37 & 0xff ) ;
}
static int F_173 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
T_2 * V_343 = ( T_2 * ) & V_2 -> V_5 . V_344 . V_345 ;
if ( ! F_172 ( V_2 , V_21 , V_37 ) )
return 1 ;
if ( V_21 == V_340 ) {
V_2 -> V_5 . V_344 . V_346 = V_37 ;
V_2 -> V_5 . V_344 . V_347 = ( V_37 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_329 )
V_343 [ 0 ] = V_37 ;
else if ( V_21 == V_330 || V_21 == V_331 )
V_343 [ 1 + V_21 - V_330 ] = V_37 ;
else if ( V_21 >= V_332 && V_21 <= V_339 )
V_343 [ 3 + V_21 - V_332 ] = V_37 ;
else if ( V_21 == V_341 )
V_2 -> V_5 . V_348 = V_37 ;
else {
int V_349 , V_350 ;
T_2 * V_351 ;
V_349 = ( V_21 - 0x200 ) / 2 ;
V_350 = V_21 - 0x200 - 2 * V_349 ;
if ( ! V_350 )
V_351 =
( T_2 * ) & V_2 -> V_5 . V_344 . V_352 [ V_349 ] . V_353 ;
else
V_351 =
( T_2 * ) & V_2 -> V_5 . V_344 . V_352 [ V_349 ] . V_354 ;
* V_351 = V_37 ;
}
F_60 ( V_2 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
T_2 V_355 = V_2 -> V_5 . V_355 ;
unsigned V_356 = V_355 & 0xff ;
switch ( V_21 ) {
case V_357 :
V_2 -> V_5 . V_358 = V_37 ;
break;
case V_359 :
if ( ! ( V_355 & V_360 ) )
return 1 ;
if ( V_37 != 0 && V_37 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_361 = V_37 ;
break;
default:
if ( V_21 >= V_362 &&
V_21 < V_362 + 4 * V_356 ) {
T_1 V_82 = V_21 - V_362 ;
if ( ( V_82 & 0x3 ) == 0 &&
V_37 != 0 && ( V_37 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_363 [ V_82 ] = V_37 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_175 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_90 * V_90 = V_2 -> V_90 ;
int V_364 = F_50 ( V_2 ) ;
T_14 * V_365 = V_364 ? ( T_14 * ) ( long ) V_90 -> V_5 . F_175 . V_366
: ( T_14 * ) ( long ) V_90 -> V_5 . F_175 . V_367 ;
T_14 V_368 = V_364 ? V_90 -> V_5 . F_175 . V_369
: V_90 -> V_5 . F_175 . V_370 ;
T_1 V_371 = V_37 & ~ V_372 ;
T_2 V_373 = V_37 & V_372 ;
T_14 * V_374 ;
int V_108 ;
V_108 = - V_375 ;
if ( V_371 >= V_368 )
goto V_102;
V_108 = - V_376 ;
V_374 = F_176 ( V_365 + ( V_371 * V_96 ) , V_96 ) ;
if ( F_177 ( V_374 ) ) {
V_108 = F_178 ( V_374 ) ;
goto V_102;
}
if ( F_108 ( V_90 , V_373 , V_374 , V_96 ) )
goto V_377;
V_108 = 0 ;
V_377:
F_179 ( V_374 ) ;
V_102:
return V_108 ;
}
static bool F_180 ( struct V_90 * V_90 )
{
return V_90 -> V_5 . V_378 & V_379 ;
}
static bool F_181 ( T_1 V_21 )
{
bool V_108 = false ;
switch ( V_21 ) {
case V_380 :
case V_381 :
case V_382 :
case V_383 :
V_108 = true ;
break;
}
return V_108 ;
}
static int F_182 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
struct V_90 * V_90 = V_2 -> V_90 ;
switch ( V_21 ) {
case V_380 :
V_90 -> V_5 . V_384 = V_37 ;
if ( ! V_90 -> V_5 . V_384 )
V_90 -> V_5 . V_378 &= ~ V_379 ;
break;
case V_381 : {
T_2 V_91 ;
unsigned long V_385 ;
T_14 V_386 [ 4 ] ;
if ( ! V_90 -> V_5 . V_384 )
break;
if ( ! ( V_37 & V_379 ) ) {
V_90 -> V_5 . V_378 = V_37 ;
break;
}
V_91 = V_37 >> V_387 ;
V_385 = F_183 ( V_90 , V_91 ) ;
if ( F_184 ( V_385 ) )
return 1 ;
V_64 -> V_388 ( V_2 , V_386 ) ;
( ( unsigned char * ) V_386 ) [ 3 ] = 0xc3 ;
if ( F_185 ( ( void V_389 * ) V_385 , V_386 , 4 ) )
return 1 ;
V_90 -> V_5 . V_378 = V_37 ;
F_186 ( V_90 , V_91 ) ;
break;
}
case V_382 : {
T_2 V_91 ;
T_15 V_390 ;
memset ( & V_390 , 0 , sizeof( V_390 ) ) ;
V_90 -> V_5 . V_391 = V_37 ;
if ( ! ( V_37 & V_392 ) )
break;
V_91 = V_37 >> V_393 ;
if ( F_108 ( V_90 , V_91 << V_393 ,
& V_390 , sizeof( V_390 ) ) )
return 1 ;
F_186 ( V_90 , V_91 ) ;
break;
}
default:
F_187 ( V_2 , L_7
L_8 , V_21 , V_37 ) ;
return 1 ;
}
return 0 ;
}
static int F_188 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
switch ( V_21 ) {
case V_394 : {
T_2 V_91 ;
unsigned long V_385 ;
if ( ! ( V_37 & V_395 ) ) {
V_2 -> V_5 . V_396 = V_37 ;
if ( F_189 ( V_2 , 0 ) )
return 1 ;
break;
}
V_91 = V_37 >> V_397 ;
V_385 = F_183 ( V_2 -> V_90 , V_91 ) ;
if ( F_184 ( V_385 ) )
return 1 ;
if ( F_190 ( ( void V_389 * ) V_385 , V_96 ) )
return 1 ;
V_2 -> V_5 . V_396 = V_37 ;
F_186 ( V_2 -> V_90 , V_91 ) ;
if ( F_189 ( V_2 , F_41 ( V_91 ) | V_398 ) )
return 1 ;
break;
}
case V_399 :
return F_191 ( V_2 , V_400 , V_37 ) ;
case V_401 :
return F_191 ( V_2 , V_402 , V_37 ) ;
case V_403 :
return F_191 ( V_2 , V_404 , V_37 ) ;
default:
F_187 ( V_2 , L_7
L_8 , V_21 , V_37 ) ;
return 1 ;
}
return 0 ;
}
static int F_192 ( struct V_1 * V_2 , T_2 V_37 )
{
T_6 V_405 = V_37 & ~ 0x3f ;
if ( V_37 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_406 = V_37 ;
if ( ! ( V_37 & V_407 ) ) {
F_59 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_193 ( V_2 -> V_90 , & V_2 -> V_5 . V_6 . V_37 , V_405 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_408 = ! ( V_37 & V_409 ) ;
F_194 ( V_2 ) ;
return 0 ;
}
static void F_195 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_310 = false ;
}
static void F_196 ( struct V_1 * V_2 )
{
T_2 V_282 ;
if ( ! ( V_2 -> V_5 . V_410 . V_406 & V_398 ) )
return;
V_282 = V_411 -> V_412 . V_413 - V_2 -> V_5 . V_410 . V_414 ;
V_2 -> V_5 . V_410 . V_414 = V_411 -> V_412 . V_413 ;
V_2 -> V_5 . V_410 . V_415 = V_282 ;
}
static void F_197 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_410 . V_406 & V_398 ) )
return;
if ( F_143 ( F_161 ( V_2 -> V_90 , & V_2 -> V_5 . V_410 . V_416 ,
& V_2 -> V_5 . V_410 . V_417 , sizeof( struct V_418 ) ) ) )
return;
V_2 -> V_5 . V_410 . V_417 . V_417 += V_2 -> V_5 . V_410 . V_415 ;
V_2 -> V_5 . V_410 . V_417 . V_217 += 2 ;
V_2 -> V_5 . V_410 . V_415 = 0 ;
F_162 ( V_2 -> V_90 , & V_2 -> V_5 . V_410 . V_416 ,
& V_2 -> V_5 . V_410 . V_417 , sizeof( struct V_418 ) ) ;
}
int F_198 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
bool V_419 = false ;
T_1 V_21 = V_32 -> V_132 ;
T_2 V_37 = V_32 -> V_37 ;
switch ( V_21 ) {
case V_420 :
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
break;
case V_426 :
return F_99 ( V_2 , V_37 ) ;
case V_427 :
V_37 &= ~ ( T_2 ) 0x40 ;
V_37 &= ~ ( T_2 ) 0x100 ;
V_37 &= ~ ( T_2 ) 0x8 ;
if ( V_37 != 0 ) {
F_187 ( V_2 , L_9 ,
V_37 ) ;
return 1 ;
}
break;
case V_428 :
if ( V_37 != 0 ) {
F_187 ( V_2 , L_10
L_11 , V_37 ) ;
return 1 ;
}
break;
case V_429 :
if ( ! V_37 ) {
break;
} else if ( V_37 & ~ ( V_430 | V_431 ) ) {
return 1 ;
}
F_187 ( V_2 , L_12 ,
V_237 , V_37 ) ;
break;
case 0x200 ... 0x2ff :
return F_173 ( V_2 , V_21 , V_37 ) ;
case V_432 :
return F_19 ( V_2 , V_32 ) ;
case V_433 ... V_433 + 0x3ff :
return F_199 ( V_2 , V_21 , V_37 ) ;
case V_434 :
F_200 ( V_2 , V_37 ) ;
break;
case V_435 :
if ( F_132 ( V_2 ) ) {
if ( ! V_32 -> V_39 ) {
T_2 V_436 = V_37 - V_2 -> V_5 . V_268 ;
V_64 -> V_437 ( V_2 , V_436 , true ) ;
}
V_2 -> V_5 . V_268 = V_37 ;
}
break;
case V_438 :
V_2 -> V_5 . V_439 = V_37 ;
break;
case V_440 :
case V_441 :
V_2 -> V_90 -> V_5 . V_216 = V_37 ;
F_106 ( V_2 -> V_90 , V_37 ) ;
break;
case V_442 :
case V_443 : {
T_2 V_444 ;
F_195 ( V_2 ) ;
V_2 -> V_5 . time = V_37 ;
F_27 ( V_445 , V_2 ) ;
if ( ! ( V_37 & 1 ) )
break;
V_444 = V_37 & ~ ( V_372 | 1 ) ;
if ( F_193 ( V_2 -> V_90 ,
& V_2 -> V_5 . V_316 , V_37 & ~ 1ULL ,
sizeof( struct V_304 ) ) )
V_2 -> V_5 . V_310 = false ;
else
V_2 -> V_5 . V_310 = true ;
break;
}
case V_446 :
if ( F_192 ( V_2 , V_37 ) )
return 1 ;
break;
case V_447 :
if ( F_143 ( ! F_201 () ) )
return 1 ;
if ( V_37 & V_448 )
return 1 ;
if ( F_193 ( V_2 -> V_90 , & V_2 -> V_5 . V_410 . V_416 ,
V_37 & V_449 ,
sizeof( struct V_418 ) ) )
return 1 ;
V_2 -> V_5 . V_410 . V_406 = V_37 ;
if ( ! ( V_37 & V_398 ) )
break;
V_2 -> V_5 . V_410 . V_414 = V_411 -> V_412 . V_413 ;
F_202 () ;
F_196 ( V_2 ) ;
F_203 () ;
F_27 ( V_450 , V_2 ) ;
break;
case V_451 :
if ( F_189 ( V_2 , V_37 ) )
return 1 ;
break;
case V_359 :
case V_357 :
case V_362 ... V_362 + 4 * V_452 - 1 :
return F_174 ( V_2 , V_21 , V_37 ) ;
case V_453 :
case V_454 :
case V_455 :
case V_456 :
if ( V_37 != 0 )
F_187 ( V_2 , L_13
L_14 , V_21 , V_37 ) ;
break;
case V_457 :
case V_458 :
case V_459 :
case V_460 :
F_187 ( V_2 , L_13
L_14 , V_21 , V_37 ) ;
break;
case V_461 :
case V_462 :
V_419 = true ;
case V_463 :
case V_464 :
if ( F_204 ( V_2 , V_21 ) )
return F_205 ( V_2 , V_32 ) ;
if ( V_419 || V_37 != 0 )
F_187 ( V_2 , L_15
L_14 , V_21 , V_37 ) ;
break;
case V_465 :
break;
case V_380 ... V_466 :
if ( F_181 ( V_21 ) ) {
int V_108 ;
F_206 ( & V_2 -> V_90 -> V_467 ) ;
V_108 = F_182 ( V_2 , V_21 , V_37 ) ;
F_207 ( & V_2 -> V_90 -> V_467 ) ;
return V_108 ;
} else
return F_188 ( V_2 , V_21 , V_37 ) ;
break;
case V_468 :
F_187 ( V_2 , L_16 , V_21 , V_37 ) ;
break;
case V_469 :
if ( ! F_208 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_470 . V_471 = V_37 ;
break;
case V_472 :
if ( ! F_208 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_470 . V_473 = V_37 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_90 -> V_5 . F_175 . V_21 ) )
return F_175 ( V_2 , V_37 ) ;
if ( F_204 ( V_2 , V_21 ) )
return F_205 ( V_2 , V_32 ) ;
if ( ! V_474 ) {
F_187 ( V_2 , L_17 ,
V_21 , V_37 ) ;
return 1 ;
} else {
F_187 ( V_2 , L_16 ,
V_21 , V_37 ) ;
break;
}
}
return 0 ;
}
int F_209 ( struct V_1 * V_2 , T_1 V_475 , T_2 * V_476 )
{
return V_64 -> V_477 ( V_2 , V_475 , V_476 ) ;
}
static int F_210 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_476 )
{
T_2 * V_343 = ( T_2 * ) & V_2 -> V_5 . V_344 . V_345 ;
if ( ! F_169 ( V_21 ) )
return 1 ;
if ( V_21 == V_340 )
* V_476 = V_2 -> V_5 . V_344 . V_346 +
( V_2 -> V_5 . V_344 . V_347 << 10 ) ;
else if ( V_21 == V_329 )
* V_476 = V_343 [ 0 ] ;
else if ( V_21 == V_330 || V_21 == V_331 )
* V_476 = V_343 [ 1 + V_21 - V_330 ] ;
else if ( V_21 >= V_332 && V_21 <= V_339 )
* V_476 = V_343 [ 3 + V_21 - V_332 ] ;
else if ( V_21 == V_341 )
* V_476 = V_2 -> V_5 . V_348 ;
else {
int V_349 , V_350 ;
T_2 * V_351 ;
V_349 = ( V_21 - 0x200 ) / 2 ;
V_350 = V_21 - 0x200 - 2 * V_349 ;
if ( ! V_350 )
V_351 =
( T_2 * ) & V_2 -> V_5 . V_344 . V_352 [ V_349 ] . V_353 ;
else
V_351 =
( T_2 * ) & V_2 -> V_5 . V_344 . V_352 [ V_349 ] . V_354 ;
* V_476 = * V_351 ;
}
return 0 ;
}
static int F_211 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_476 )
{
T_2 V_37 ;
T_2 V_355 = V_2 -> V_5 . V_355 ;
unsigned V_356 = V_355 & 0xff ;
switch ( V_21 ) {
case V_478 :
case V_479 :
V_37 = 0 ;
break;
case V_480 :
V_37 = V_2 -> V_5 . V_355 ;
break;
case V_359 :
if ( ! ( V_355 & V_360 ) )
return 1 ;
V_37 = V_2 -> V_5 . V_361 ;
break;
case V_357 :
V_37 = V_2 -> V_5 . V_358 ;
break;
default:
if ( V_21 >= V_362 &&
V_21 < V_362 + 4 * V_356 ) {
T_1 V_82 = V_21 - V_362 ;
V_37 = V_2 -> V_5 . V_363 [ V_82 ] ;
break;
}
return 1 ;
}
* V_476 = V_37 ;
return 0 ;
}
static int F_212 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_476 )
{
T_2 V_37 = 0 ;
struct V_90 * V_90 = V_2 -> V_90 ;
switch ( V_21 ) {
case V_380 :
V_37 = V_90 -> V_5 . V_384 ;
break;
case V_381 :
V_37 = V_90 -> V_5 . V_378 ;
break;
case V_383 : {
V_37 =
F_213 ( F_115 () + V_90 -> V_5 . V_222 , 100 ) ;
break;
}
case V_382 :
V_37 = V_90 -> V_5 . V_391 ;
break;
default:
F_187 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_476 = V_37 ;
return 0 ;
}
static int F_214 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_476 )
{
T_2 V_37 = 0 ;
switch ( V_21 ) {
case V_481 : {
int V_108 ;
struct V_1 * V_242 ;
F_152 (r, v, vcpu->kvm) {
if ( V_242 == V_2 ) {
V_37 = V_108 ;
break;
}
}
break;
}
case V_399 :
return F_215 ( V_2 , V_400 , V_476 ) ;
case V_401 :
return F_215 ( V_2 , V_402 , V_476 ) ;
case V_403 :
return F_215 ( V_2 , V_404 , V_476 ) ;
case V_394 :
V_37 = V_2 -> V_5 . V_396 ;
break;
default:
F_187 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_476 = V_37 ;
return 0 ;
}
int F_216 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_476 )
{
T_2 V_37 ;
switch ( V_21 ) {
case V_482 :
case V_483 :
case V_429 :
case V_484 :
case V_485 :
case V_486 :
case V_487 :
case V_488 :
case V_427 :
case V_423 :
case V_453 :
case V_457 :
case V_489 :
case V_420 :
case V_428 :
case V_425 :
V_37 = 0 ;
break;
case V_461 :
case V_462 :
case V_463 :
case V_464 :
if ( F_204 ( V_2 , V_21 ) )
return F_217 ( V_2 , V_21 , V_476 ) ;
V_37 = 0 ;
break;
case V_421 :
V_37 = 0x100000000ULL ;
break;
case V_490 :
V_37 = 0x500 | V_328 ;
break;
case 0x200 ... 0x2ff :
return F_210 ( V_2 , V_21 , V_476 ) ;
case 0xcd :
V_37 = 3 ;
break;
case V_491 :
V_37 = 1 << 24 ;
break;
case V_432 :
V_37 = F_18 ( V_2 ) ;
break;
case V_433 ... V_433 + 0x3ff :
return F_218 ( V_2 , V_21 , V_476 ) ;
break;
case V_434 :
V_37 = F_219 ( V_2 ) ;
break;
case V_435 :
V_37 = ( T_2 ) V_2 -> V_5 . V_268 ;
break;
case V_438 :
V_37 = V_2 -> V_5 . V_439 ;
break;
case V_492 :
V_37 = 1000ULL ;
V_37 |= ( ( ( T_9 ) 4ULL ) << 40 ) ;
break;
case V_426 :
V_37 = V_2 -> V_5 . V_119 ;
break;
case V_441 :
case V_440 :
V_37 = V_2 -> V_90 -> V_5 . V_216 ;
break;
case V_443 :
case V_442 :
V_37 = V_2 -> V_5 . time ;
break;
case V_446 :
V_37 = V_2 -> V_5 . V_6 . V_406 ;
break;
case V_447 :
V_37 = V_2 -> V_5 . V_410 . V_406 ;
break;
case V_451 :
V_37 = V_2 -> V_5 . V_493 . V_406 ;
break;
case V_478 :
case V_479 :
case V_480 :
case V_359 :
case V_357 :
case V_362 ... V_362 + 4 * V_452 - 1 :
return F_211 ( V_2 , V_21 , V_476 ) ;
case V_465 :
V_37 = 0x20000000 ;
break;
case V_380 ... V_466 :
if ( F_181 ( V_21 ) ) {
int V_108 ;
F_206 ( & V_2 -> V_90 -> V_467 ) ;
V_108 = F_212 ( V_2 , V_21 , V_476 ) ;
F_207 ( & V_2 -> V_90 -> V_467 ) ;
return V_108 ;
} else
return F_214 ( V_2 , V_21 , V_476 ) ;
break;
case V_468 :
V_37 = 0xbe702111 ;
break;
case V_469 :
if ( ! F_208 ( V_2 ) )
return 1 ;
V_37 = V_2 -> V_5 . V_470 . V_471 ;
break;
case V_472 :
if ( ! F_208 ( V_2 ) )
return 1 ;
V_37 = V_2 -> V_5 . V_470 . V_473 ;
break;
default:
if ( F_204 ( V_2 , V_21 ) )
return F_217 ( V_2 , V_21 , V_476 ) ;
if ( ! V_474 ) {
F_187 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_187 ( V_2 , L_20 , V_21 ) ;
V_37 = 0 ;
}
break;
}
* V_476 = V_37 ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 , struct V_494 * V_19 ,
struct V_495 * V_496 ,
int (* F_221)( struct V_1 * V_2 ,
unsigned V_132 , T_2 * V_37 ) )
{
int V_3 , V_349 ;
V_349 = F_222 ( & V_2 -> V_90 -> V_497 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_498 ; ++ V_3 )
if ( F_221 ( V_2 , V_496 [ V_3 ] . V_132 , & V_496 [ V_3 ] . V_37 ) )
break;
F_223 ( & V_2 -> V_90 -> V_497 , V_349 ) ;
return V_3 ;
}
static int F_224 ( struct V_1 * V_2 , struct V_494 V_389 * V_499 ,
int (* F_221)( struct V_1 * V_2 ,
unsigned V_132 , T_2 * V_37 ) ,
int V_500 )
{
struct V_494 V_19 ;
struct V_495 * V_496 ;
int V_108 , V_501 ;
unsigned V_502 ;
V_108 = - V_89 ;
if ( F_225 ( & V_19 , V_499 , sizeof V_19 ) )
goto V_102;
V_108 = - V_375 ;
if ( V_19 . V_498 >= V_503 )
goto V_102;
V_502 = sizeof( struct V_495 ) * V_19 . V_498 ;
V_496 = F_176 ( V_499 -> V_496 , V_502 ) ;
if ( F_177 ( V_496 ) ) {
V_108 = F_178 ( V_496 ) ;
goto V_102;
}
V_108 = V_501 = F_220 ( V_2 , & V_19 , V_496 , F_221 ) ;
if ( V_108 < 0 )
goto V_377;
V_108 = - V_89 ;
if ( V_500 && F_226 ( V_499 -> V_496 , V_496 , V_502 ) )
goto V_377;
V_108 = V_501 ;
V_377:
F_179 ( V_496 ) ;
V_102:
return V_108 ;
}
int F_227 ( long V_504 )
{
int V_108 ;
switch ( V_504 ) {
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
#ifdef F_228
case V_541 :
case V_542 :
#endif
V_108 = 1 ;
break;
case V_543 :
V_108 = V_544 ;
break;
case V_545 :
V_108 = ! V_64 -> V_546 () ;
break;
case V_547 :
V_108 = V_548 ;
break;
case V_549 :
V_108 = V_550 ;
break;
case V_551 :
V_108 = V_552 ;
break;
case V_553 :
V_108 = 0 ;
break;
#ifdef F_228
case V_554 :
V_108 = F_229 ( & V_555 ) ;
break;
#endif
case V_556 :
V_108 = V_452 ;
break;
case V_557 :
V_108 = V_558 ;
break;
case V_559 :
V_108 = V_560 ;
break;
case V_561 :
V_108 = F_230 ( V_562 ) ;
break;
default:
V_108 = 0 ;
break;
}
return V_108 ;
}
long F_231 ( struct V_563 * V_564 ,
unsigned int V_565 , unsigned long V_566 )
{
void V_389 * V_567 = ( void V_389 * ) V_566 ;
long V_108 ;
switch ( V_565 ) {
case V_568 : {
struct V_569 V_389 * V_570 = V_567 ;
struct V_569 V_571 ;
unsigned V_501 ;
V_108 = - V_89 ;
if ( F_225 ( & V_571 , V_570 , sizeof V_571 ) )
goto V_102;
V_501 = V_571 . V_498 ;
V_571 . V_498 = V_572 + F_46 ( V_573 ) ;
if ( F_226 ( V_570 , & V_571 , sizeof V_571 ) )
goto V_102;
V_108 = - V_375 ;
if ( V_501 < V_571 . V_498 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_570 -> V_574 , & V_575 ,
V_572 * sizeof( T_1 ) ) )
goto V_102;
if ( F_226 ( V_570 -> V_574 + V_572 ,
& V_573 ,
F_46 ( V_573 ) * sizeof( T_1 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_576 :
case V_577 : {
struct V_578 V_389 * V_579 = V_567 ;
struct V_578 V_580 ;
V_108 = - V_89 ;
if ( F_225 ( & V_580 , V_579 , sizeof V_580 ) )
goto V_102;
V_108 = F_232 ( & V_580 , V_579 -> V_496 ,
V_565 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_579 , & V_580 , sizeof V_580 ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_581 : {
T_2 V_582 ;
V_582 = V_583 ;
V_108 = - V_89 ;
if ( F_226 ( V_567 , & V_582 , sizeof V_582 ) )
goto V_102;
V_108 = 0 ;
break;
}
default:
V_108 = - V_584 ;
}
V_102:
return V_108 ;
}
static void F_233 ( void * V_585 )
{
F_234 () ;
}
static bool F_235 ( struct V_1 * V_2 )
{
return F_236 ( V_2 -> V_90 ) ;
}
void F_237 ( struct V_1 * V_2 , int V_23 )
{
if ( F_235 ( V_2 ) ) {
if ( V_64 -> V_586 () )
F_238 ( V_23 , V_2 -> V_5 . V_587 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_239 ( V_2 -> V_23 ,
F_233 , NULL , 1 ) ;
}
V_64 -> V_588 ( V_2 , V_23 ) ;
if ( F_143 ( V_2 -> V_5 . V_589 ) ) {
F_240 ( V_2 , V_2 -> V_5 . V_589 ) ;
V_2 -> V_5 . V_589 = 0 ;
F_153 ( V_298 , & V_2 -> V_299 ) ;
}
if ( F_143 ( V_2 -> V_23 != V_23 ) || F_131 () ) {
T_12 V_590 = ! V_2 -> V_5 . V_591 ? 0 :
F_159 () - V_2 -> V_5 . V_591 ;
if ( V_590 < 0 )
F_241 ( L_21 ) ;
if ( F_131 () ) {
T_2 V_82 = V_64 -> V_275 ( V_2 ,
V_2 -> V_5 . V_286 ) ;
V_64 -> V_288 ( V_2 , V_82 ) ;
V_2 -> V_5 . V_309 = 1 ;
}
if ( ! V_2 -> V_90 -> V_5 . V_263 || V_2 -> V_23 == - 1 )
F_27 ( V_445 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_242 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_196 ( V_2 ) ;
F_27 ( V_450 , V_2 ) ;
}
void F_243 ( struct V_1 * V_2 )
{
V_64 -> V_592 ( V_2 ) ;
F_244 ( V_2 ) ;
V_2 -> V_5 . V_591 = F_159 () ;
}
static int F_245 ( struct V_1 * V_2 ,
struct V_593 * V_594 )
{
V_64 -> V_595 ( V_2 ) ;
memcpy ( V_594 -> V_596 , V_2 -> V_5 . V_597 -> V_596 , sizeof *V_594 ) ;
return 0 ;
}
static int F_246 ( struct V_1 * V_2 ,
struct V_593 * V_594 )
{
F_247 ( V_2 , V_594 ) ;
F_248 ( V_2 ) ;
return 0 ;
}
static int F_249 ( struct V_1 * V_2 ,
struct V_598 * V_599 )
{
if ( V_599 -> V_599 >= V_600 )
return - V_584 ;
if ( F_82 ( V_2 -> V_90 ) )
return - V_601 ;
F_250 ( V_2 , V_599 -> V_599 , false ) ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
static int F_251 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
return 0 ;
}
static int F_252 ( struct V_1 * V_2 ,
struct V_602 * V_603 )
{
if ( V_603 -> V_271 )
return - V_584 ;
V_2 -> V_5 . V_604 = ! ! V_603 -> V_347 ;
return 0 ;
}
static int F_253 ( struct V_1 * V_2 ,
T_2 V_355 )
{
int V_108 ;
unsigned V_356 = V_355 & 0xff , V_605 ;
V_108 = - V_584 ;
if ( ! V_356 || V_356 >= V_452 )
goto V_102;
if ( V_355 & ~ ( V_583 | 0xff | 0xff0000 ) )
goto V_102;
V_108 = 0 ;
V_2 -> V_5 . V_355 = V_355 ;
if ( V_355 & V_360 )
V_2 -> V_5 . V_361 = ~ ( T_2 ) 0 ;
for ( V_605 = 0 ; V_605 < V_356 ; V_605 ++ )
V_2 -> V_5 . V_363 [ V_605 * 4 ] = ~ ( T_2 ) 0 ;
V_102:
return V_108 ;
}
static int F_254 ( struct V_1 * V_2 ,
struct V_606 * V_607 )
{
T_2 V_355 = V_2 -> V_5 . V_355 ;
unsigned V_356 = V_355 & 0xff ;
T_2 * V_608 = V_2 -> V_5 . V_363 ;
if ( V_607 -> V_605 >= V_356 || ! ( V_607 -> V_473 & V_609 ) )
return - V_584 ;
if ( ( V_607 -> V_473 & V_610 ) && ( V_355 & V_360 ) &&
V_2 -> V_5 . V_361 != ~ ( T_2 ) 0 )
return 0 ;
V_608 += 4 * V_607 -> V_605 ;
if ( ( V_607 -> V_473 & V_610 ) && V_608 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_607 -> V_473 & V_610 ) {
if ( ( V_2 -> V_5 . V_358 & V_611 ) ||
! F_58 ( V_2 , V_612 ) ) {
F_27 ( V_62 , V_2 ) ;
return 0 ;
}
if ( V_608 [ 1 ] & V_609 )
V_607 -> V_473 |= V_613 ;
V_608 [ 2 ] = V_607 -> V_385 ;
V_608 [ 3 ] = V_607 -> V_614 ;
V_2 -> V_5 . V_358 = V_607 -> V_358 ;
V_608 [ 1 ] = V_607 -> V_473 ;
F_28 ( V_2 , V_615 ) ;
} else if ( ! ( V_608 [ 1 ] & V_609 )
|| ! ( V_608 [ 1 ] & V_610 ) ) {
if ( V_608 [ 1 ] & V_609 )
V_607 -> V_473 |= V_613 ;
V_608 [ 2 ] = V_607 -> V_385 ;
V_608 [ 3 ] = V_607 -> V_614 ;
V_608 [ 1 ] = V_607 -> V_473 ;
} else
V_608 [ 1 ] |= V_613 ;
return 0 ;
}
static void F_255 ( struct V_1 * V_2 ,
struct V_616 * V_617 )
{
F_256 ( V_2 ) ;
V_617 -> V_57 . V_618 =
V_2 -> V_5 . V_57 . V_58 &&
! F_257 ( V_2 -> V_5 . V_57 . V_16 ) ;
V_617 -> V_57 . V_16 = V_2 -> V_5 . V_57 . V_16 ;
V_617 -> V_57 . V_60 = V_2 -> V_5 . V_57 . V_60 ;
V_617 -> V_57 . V_619 = 0 ;
V_617 -> V_57 . V_51 = V_2 -> V_5 . V_57 . V_51 ;
V_617 -> V_620 . V_618 =
V_2 -> V_5 . V_620 . V_58 && ! V_2 -> V_5 . V_620 . V_621 ;
V_617 -> V_620 . V_16 = V_2 -> V_5 . V_620 . V_16 ;
V_617 -> V_620 . V_621 = 0 ;
V_617 -> V_620 . V_622 =
V_64 -> V_623 ( V_2 ,
V_624 | V_625 ) ;
V_617 -> V_626 . V_618 = V_2 -> V_5 . V_627 ;
V_617 -> V_626 . V_58 = V_2 -> V_5 . V_628 != 0 ;
V_617 -> V_626 . V_629 = V_64 -> V_630 ( V_2 ) ;
V_617 -> V_626 . V_619 = 0 ;
V_617 -> V_631 = 0 ;
V_617 -> V_271 = ( V_632
| V_633 ) ;
memset ( & V_617 -> V_634 , 0 , sizeof( V_617 -> V_634 ) ) ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_616 * V_617 )
{
if ( V_617 -> V_271 & ~ ( V_632
| V_635
| V_633 ) )
return - V_584 ;
F_256 ( V_2 ) ;
V_2 -> V_5 . V_57 . V_58 = V_617 -> V_57 . V_618 ;
V_2 -> V_5 . V_57 . V_16 = V_617 -> V_57 . V_16 ;
V_2 -> V_5 . V_57 . V_60 = V_617 -> V_57 . V_60 ;
V_2 -> V_5 . V_57 . V_51 = V_617 -> V_57 . V_51 ;
V_2 -> V_5 . V_620 . V_58 = V_617 -> V_620 . V_618 ;
V_2 -> V_5 . V_620 . V_16 = V_617 -> V_620 . V_16 ;
V_2 -> V_5 . V_620 . V_621 = V_617 -> V_620 . V_621 ;
if ( V_617 -> V_271 & V_633 )
V_64 -> V_636 ( V_2 ,
V_617 -> V_620 . V_622 ) ;
V_2 -> V_5 . V_627 = V_617 -> V_626 . V_618 ;
if ( V_617 -> V_271 & V_632 )
V_2 -> V_5 . V_628 = V_617 -> V_626 . V_58 ;
V_64 -> V_637 ( V_2 , V_617 -> V_626 . V_629 ) ;
if ( V_617 -> V_271 & V_635 &&
F_259 ( V_2 ) )
V_2 -> V_5 . V_597 -> V_631 = V_617 -> V_631 ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
static void F_260 ( struct V_1 * V_2 ,
struct V_638 * V_639 )
{
unsigned long V_171 ;
memcpy ( V_639 -> V_172 , V_2 -> V_5 . V_172 , sizeof( V_2 -> V_5 . V_172 ) ) ;
F_90 ( V_2 , 6 , & V_171 ) ;
V_639 -> V_163 = V_171 ;
V_639 -> V_164 = V_2 -> V_5 . V_164 ;
V_639 -> V_271 = 0 ;
memset ( & V_639 -> V_634 , 0 , sizeof( V_639 -> V_634 ) ) ;
}
static int F_261 ( struct V_1 * V_2 ,
struct V_638 * V_639 )
{
if ( V_639 -> V_271 )
return - V_584 ;
memcpy ( V_2 -> V_5 . V_172 , V_639 -> V_172 , sizeof( V_2 -> V_5 . V_172 ) ) ;
V_2 -> V_5 . V_163 = V_639 -> V_163 ;
F_86 ( V_2 ) ;
V_2 -> V_5 . V_164 = V_639 -> V_164 ;
F_87 ( V_2 ) ;
return 0 ;
}
static void F_262 ( struct V_1 * V_2 ,
struct V_640 * V_641 )
{
if ( V_558 ) {
memcpy ( V_641 -> V_642 ,
& V_2 -> V_5 . V_643 . V_644 -> V_645 ,
V_2 -> V_5 . V_646 ) ;
* ( T_2 * ) & V_641 -> V_642 [ V_647 / sizeof( T_1 ) ] &=
V_2 -> V_5 . V_139 | V_648 ;
} else {
memcpy ( V_641 -> V_642 ,
& V_2 -> V_5 . V_643 . V_644 -> V_649 ,
sizeof( struct V_650 ) ) ;
* ( T_2 * ) & V_641 -> V_642 [ V_647 / sizeof( T_1 ) ] =
V_648 ;
}
}
static int F_263 ( struct V_1 * V_2 ,
struct V_640 * V_641 )
{
T_2 V_651 =
* ( T_2 * ) & V_641 -> V_642 [ V_647 / sizeof( T_1 ) ] ;
if ( V_558 ) {
if ( V_651 & ~ F_264 () )
return - V_584 ;
memcpy ( & V_2 -> V_5 . V_643 . V_644 -> V_645 ,
V_641 -> V_642 , V_2 -> V_5 . V_646 ) ;
} else {
if ( V_651 & ~ V_648 )
return - V_584 ;
memcpy ( & V_2 -> V_5 . V_643 . V_644 -> V_649 ,
V_641 -> V_642 , sizeof( struct V_650 ) ) ;
}
return 0 ;
}
static void F_265 ( struct V_1 * V_2 ,
struct V_652 * V_653 )
{
if ( ! V_558 ) {
V_653 -> V_654 = 0 ;
return;
}
V_653 -> V_654 = 1 ;
V_653 -> V_271 = 0 ;
V_653 -> V_655 [ 0 ] . V_133 = V_129 ;
V_653 -> V_655 [ 0 ] . V_22 = V_2 -> V_5 . V_130 ;
}
static int F_266 ( struct V_1 * V_2 ,
struct V_652 * V_653 )
{
int V_3 , V_108 = 0 ;
if ( ! V_558 )
return - V_584 ;
if ( V_653 -> V_654 > V_656 || V_653 -> V_271 )
return - V_584 ;
for ( V_3 = 0 ; V_3 < V_653 -> V_654 ; V_3 ++ )
if ( V_653 -> V_655 [ V_3 ] . V_133 == V_129 ) {
V_108 = F_66 ( V_2 , V_129 ,
V_653 -> V_655 [ V_3 ] . V_22 ) ;
break;
}
if ( V_108 )
V_108 = - V_584 ;
return V_108 ;
}
static int F_267 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_310 )
return - V_584 ;
V_2 -> V_5 . V_318 = true ;
F_27 ( V_298 , V_2 ) ;
return 0 ;
}
long F_268 ( struct V_563 * V_564 ,
unsigned int V_565 , unsigned long V_566 )
{
struct V_1 * V_2 = V_564 -> V_657 ;
void V_389 * V_567 = ( void V_389 * ) V_566 ;
int V_108 ;
union {
struct V_593 * V_658 ;
struct V_640 * V_645 ;
struct V_652 * V_655 ;
void * V_659 ;
} V_660 ;
V_660 . V_659 = NULL ;
switch ( V_565 ) {
case V_661 : {
V_108 = - V_584 ;
if ( ! V_2 -> V_5 . V_597 )
goto V_102;
V_660 . V_658 = F_269 ( sizeof( struct V_593 ) , V_662 ) ;
V_108 = - V_376 ;
if ( ! V_660 . V_658 )
goto V_102;
V_108 = F_245 ( V_2 , V_660 . V_658 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_567 , V_660 . V_658 , sizeof( struct V_593 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_663 : {
V_108 = - V_584 ;
if ( ! V_2 -> V_5 . V_597 )
goto V_102;
V_660 . V_658 = F_176 ( V_567 , sizeof( * V_660 . V_658 ) ) ;
if ( F_177 ( V_660 . V_658 ) )
return F_178 ( V_660 . V_658 ) ;
V_108 = F_246 ( V_2 , V_660 . V_658 ) ;
break;
}
case V_664 : {
struct V_598 V_599 ;
V_108 = - V_89 ;
if ( F_225 ( & V_599 , V_567 , sizeof V_599 ) )
goto V_102;
V_108 = F_249 ( V_2 , & V_599 ) ;
break;
}
case V_665 : {
V_108 = F_251 ( V_2 ) ;
break;
}
case V_666 : {
struct V_667 V_389 * V_579 = V_567 ;
struct V_667 V_580 ;
V_108 = - V_89 ;
if ( F_225 ( & V_580 , V_579 , sizeof V_580 ) )
goto V_102;
V_108 = F_270 ( V_2 , & V_580 , V_579 -> V_496 ) ;
break;
}
case V_668 : {
struct V_578 V_389 * V_579 = V_567 ;
struct V_578 V_580 ;
V_108 = - V_89 ;
if ( F_225 ( & V_580 , V_579 , sizeof V_580 ) )
goto V_102;
V_108 = F_271 ( V_2 , & V_580 ,
V_579 -> V_496 ) ;
break;
}
case V_669 : {
struct V_578 V_389 * V_579 = V_567 ;
struct V_578 V_580 ;
V_108 = - V_89 ;
if ( F_225 ( & V_580 , V_579 , sizeof V_580 ) )
goto V_102;
V_108 = F_272 ( V_2 , & V_580 ,
V_579 -> V_496 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_579 , & V_580 , sizeof V_580 ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_670 :
V_108 = F_224 ( V_2 , V_567 , F_209 , 1 ) ;
break;
case V_671 :
V_108 = F_224 ( V_2 , V_567 , F_102 , 0 ) ;
break;
case V_672 : {
struct V_602 V_603 ;
V_108 = - V_89 ;
if ( F_225 ( & V_603 , V_567 , sizeof V_603 ) )
goto V_102;
V_108 = F_252 ( V_2 , & V_603 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_567 , & V_603 , sizeof V_603 ) )
goto V_102;
V_108 = 0 ;
break;
} ;
case V_673 : {
struct V_674 V_675 ;
V_108 = - V_584 ;
if ( ! F_82 ( V_2 -> V_90 ) )
goto V_102;
V_108 = - V_89 ;
if ( F_225 ( & V_675 , V_567 , sizeof V_675 ) )
goto V_102;
V_108 = F_273 ( V_2 , V_675 . V_676 ) ;
break;
}
case V_677 : {
T_2 V_355 ;
V_108 = - V_89 ;
if ( F_225 ( & V_355 , V_567 , sizeof V_355 ) )
goto V_102;
V_108 = F_253 ( V_2 , V_355 ) ;
break;
}
case V_678 : {
struct V_606 V_607 ;
V_108 = - V_89 ;
if ( F_225 ( & V_607 , V_567 , sizeof V_607 ) )
goto V_102;
V_108 = F_254 ( V_2 , & V_607 ) ;
break;
}
case V_679 : {
struct V_616 V_617 ;
F_255 ( V_2 , & V_617 ) ;
V_108 = - V_89 ;
if ( F_226 ( V_567 , & V_617 , sizeof( struct V_616 ) ) )
break;
V_108 = 0 ;
break;
}
case V_680 : {
struct V_616 V_617 ;
V_108 = - V_89 ;
if ( F_225 ( & V_617 , V_567 , sizeof( struct V_616 ) ) )
break;
V_108 = F_258 ( V_2 , & V_617 ) ;
break;
}
case V_681 : {
struct V_638 V_639 ;
F_260 ( V_2 , & V_639 ) ;
V_108 = - V_89 ;
if ( F_226 ( V_567 , & V_639 ,
sizeof( struct V_638 ) ) )
break;
V_108 = 0 ;
break;
}
case V_682 : {
struct V_638 V_639 ;
V_108 = - V_89 ;
if ( F_225 ( & V_639 , V_567 ,
sizeof( struct V_638 ) ) )
break;
V_108 = F_261 ( V_2 , & V_639 ) ;
break;
}
case V_683 : {
V_660 . V_645 = F_269 ( sizeof( struct V_640 ) , V_662 ) ;
V_108 = - V_376 ;
if ( ! V_660 . V_645 )
break;
F_262 ( V_2 , V_660 . V_645 ) ;
V_108 = - V_89 ;
if ( F_226 ( V_567 , V_660 . V_645 , sizeof( struct V_640 ) ) )
break;
V_108 = 0 ;
break;
}
case V_684 : {
V_660 . V_645 = F_176 ( V_567 , sizeof( * V_660 . V_645 ) ) ;
if ( F_177 ( V_660 . V_645 ) )
return F_178 ( V_660 . V_645 ) ;
V_108 = F_263 ( V_2 , V_660 . V_645 ) ;
break;
}
case V_685 : {
V_660 . V_655 = F_269 ( sizeof( struct V_652 ) , V_662 ) ;
V_108 = - V_376 ;
if ( ! V_660 . V_655 )
break;
F_265 ( V_2 , V_660 . V_655 ) ;
V_108 = - V_89 ;
if ( F_226 ( V_567 , V_660 . V_655 ,
sizeof( struct V_652 ) ) )
break;
V_108 = 0 ;
break;
}
case V_686 : {
V_660 . V_655 = F_176 ( V_567 , sizeof( * V_660 . V_655 ) ) ;
if ( F_177 ( V_660 . V_655 ) )
return F_178 ( V_660 . V_655 ) ;
V_108 = F_266 ( V_2 , V_660 . V_655 ) ;
break;
}
case V_687 : {
T_1 V_688 ;
V_108 = - V_584 ;
V_688 = ( T_1 ) V_566 ;
if ( V_688 >= V_689 )
goto V_102;
if ( V_688 == 0 )
V_688 = V_248 ;
F_123 ( V_2 , V_688 ) ;
V_108 = 0 ;
goto V_102;
}
case V_690 : {
V_108 = V_2 -> V_5 . V_247 ;
goto V_102;
}
case V_691 : {
V_108 = F_267 ( V_2 ) ;
goto V_102;
}
default:
V_108 = - V_584 ;
}
V_102:
F_179 ( V_660 . V_659 ) ;
return V_108 ;
}
int F_274 ( struct V_1 * V_2 , struct V_692 * V_693 )
{
return V_694 ;
}
static int F_275 ( struct V_90 * V_90 , unsigned long V_385 )
{
int V_97 ;
if ( V_385 > ( unsigned int ) ( - 3 * V_96 ) )
return - V_584 ;
V_97 = V_64 -> V_695 ( V_90 , V_385 ) ;
return V_97 ;
}
static int F_276 ( struct V_90 * V_90 ,
T_2 V_696 )
{
V_90 -> V_5 . V_697 = V_696 ;
return 0 ;
}
static int F_277 ( struct V_90 * V_90 ,
T_1 V_698 )
{
if ( V_698 < V_699 )
return - V_584 ;
F_206 ( & V_90 -> V_700 ) ;
F_278 ( V_90 , V_698 ) ;
V_90 -> V_5 . V_701 = V_698 ;
F_207 ( & V_90 -> V_700 ) ;
return 0 ;
}
static int F_279 ( struct V_90 * V_90 )
{
return V_90 -> V_5 . V_702 ;
}
static int F_280 ( struct V_90 * V_90 , struct V_703 * V_704 )
{
int V_108 ;
V_108 = 0 ;
switch ( V_704 -> V_705 ) {
case V_706 :
memcpy ( & V_704 -> V_704 . V_707 ,
& F_281 ( V_90 ) -> V_708 [ 0 ] ,
sizeof( struct V_709 ) ) ;
break;
case V_710 :
memcpy ( & V_704 -> V_704 . V_707 ,
& F_281 ( V_90 ) -> V_708 [ 1 ] ,
sizeof( struct V_709 ) ) ;
break;
case V_711 :
V_108 = F_282 ( V_90 , & V_704 -> V_704 . V_712 ) ;
break;
default:
V_108 = - V_584 ;
break;
}
return V_108 ;
}
static int F_283 ( struct V_90 * V_90 , struct V_703 * V_704 )
{
int V_108 ;
V_108 = 0 ;
switch ( V_704 -> V_705 ) {
case V_706 :
F_134 ( & F_281 ( V_90 ) -> V_467 ) ;
memcpy ( & F_281 ( V_90 ) -> V_708 [ 0 ] ,
& V_704 -> V_704 . V_707 ,
sizeof( struct V_709 ) ) ;
F_135 ( & F_281 ( V_90 ) -> V_467 ) ;
break;
case V_710 :
F_134 ( & F_281 ( V_90 ) -> V_467 ) ;
memcpy ( & F_281 ( V_90 ) -> V_708 [ 1 ] ,
& V_704 -> V_704 . V_707 ,
sizeof( struct V_709 ) ) ;
F_135 ( & F_281 ( V_90 ) -> V_467 ) ;
break;
case V_711 :
V_108 = F_284 ( V_90 , & V_704 -> V_704 . V_712 ) ;
break;
default:
V_108 = - V_584 ;
break;
}
F_285 ( F_281 ( V_90 ) ) ;
return V_108 ;
}
static int F_286 ( struct V_90 * V_90 , struct V_713 * V_714 )
{
int V_108 = 0 ;
F_206 ( & V_90 -> V_5 . V_715 -> V_716 . V_467 ) ;
memcpy ( V_714 , & V_90 -> V_5 . V_715 -> V_716 , sizeof( struct V_713 ) ) ;
F_207 ( & V_90 -> V_5 . V_715 -> V_716 . V_467 ) ;
return V_108 ;
}
static int F_287 ( struct V_90 * V_90 , struct V_713 * V_714 )
{
int V_108 = 0 ;
F_206 ( & V_90 -> V_5 . V_715 -> V_716 . V_467 ) ;
memcpy ( & V_90 -> V_5 . V_715 -> V_716 , V_714 , sizeof( struct V_713 ) ) ;
F_288 ( V_90 , 0 , V_714 -> V_717 [ 0 ] . V_718 , 0 ) ;
F_207 ( & V_90 -> V_5 . V_715 -> V_716 . V_467 ) ;
return V_108 ;
}
static int F_289 ( struct V_90 * V_90 , struct V_719 * V_714 )
{
int V_108 = 0 ;
F_206 ( & V_90 -> V_5 . V_715 -> V_716 . V_467 ) ;
memcpy ( V_714 -> V_717 , & V_90 -> V_5 . V_715 -> V_716 . V_717 ,
sizeof( V_714 -> V_717 ) ) ;
V_714 -> V_271 = V_90 -> V_5 . V_715 -> V_716 . V_271 ;
F_207 ( & V_90 -> V_5 . V_715 -> V_716 . V_467 ) ;
memset ( & V_714 -> V_634 , 0 , sizeof( V_714 -> V_634 ) ) ;
return V_108 ;
}
static int F_290 ( struct V_90 * V_90 , struct V_719 * V_714 )
{
int V_108 = 0 , V_720 = 0 ;
T_1 V_721 , V_722 ;
F_206 ( & V_90 -> V_5 . V_715 -> V_716 . V_467 ) ;
V_721 = V_90 -> V_5 . V_715 -> V_716 . V_271 & V_723 ;
V_722 = V_714 -> V_271 & V_723 ;
if ( ! V_721 && V_722 )
V_720 = 1 ;
memcpy ( & V_90 -> V_5 . V_715 -> V_716 . V_717 , & V_714 -> V_717 ,
sizeof( V_90 -> V_5 . V_715 -> V_716 . V_717 ) ) ;
V_90 -> V_5 . V_715 -> V_716 . V_271 = V_714 -> V_271 ;
F_288 ( V_90 , 0 , V_90 -> V_5 . V_715 -> V_716 . V_717 [ 0 ] . V_718 , V_720 ) ;
F_207 ( & V_90 -> V_5 . V_715 -> V_716 . V_467 ) ;
return V_108 ;
}
static int F_291 ( struct V_90 * V_90 ,
struct V_724 * V_725 )
{
if ( ! V_90 -> V_5 . V_715 )
return - V_601 ;
F_206 ( & V_90 -> V_5 . V_715 -> V_716 . V_467 ) ;
V_90 -> V_5 . V_715 -> V_716 . V_52 = V_725 -> V_726 ;
F_207 ( & V_90 -> V_5 . V_715 -> V_716 . V_467 ) ;
return 0 ;
}
int F_292 ( struct V_90 * V_90 , struct V_727 * log )
{
int V_108 ;
struct V_728 * V_729 ;
unsigned long V_501 , V_3 ;
unsigned long * V_730 ;
unsigned long * V_731 ;
bool V_732 = false ;
F_206 ( & V_90 -> V_700 ) ;
V_108 = - V_584 ;
if ( log -> V_10 >= V_552 )
goto V_102;
V_729 = F_293 ( V_90 -> V_733 , log -> V_10 ) ;
V_730 = V_729 -> V_730 ;
V_108 = - V_734 ;
if ( ! V_730 )
goto V_102;
V_501 = F_294 ( V_729 ) ;
V_731 = V_730 + V_501 / sizeof( long ) ;
memset ( V_731 , 0 , V_501 ) ;
F_134 ( & V_90 -> V_735 ) ;
for ( V_3 = 0 ; V_3 < V_501 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_27 ;
T_5 V_82 ;
if ( ! V_730 [ V_3 ] )
continue;
V_732 = true ;
V_27 = F_295 ( & V_730 [ V_3 ] , 0 ) ;
V_731 [ V_3 ] = V_27 ;
V_82 = V_3 * V_736 ;
F_296 ( V_90 , V_729 , V_82 , V_27 ) ;
}
F_135 ( & V_90 -> V_735 ) ;
F_297 ( & V_90 -> V_700 ) ;
if ( V_732 )
F_298 ( V_90 ) ;
V_108 = - V_89 ;
if ( F_226 ( log -> V_730 , V_731 , V_501 ) )
goto V_102;
V_108 = 0 ;
V_102:
F_207 ( & V_90 -> V_700 ) ;
return V_108 ;
}
int F_299 ( struct V_90 * V_90 , struct V_737 * V_738 ,
bool V_739 )
{
if ( ! F_82 ( V_90 ) )
return - V_601 ;
V_738 -> V_473 = F_300 ( V_90 , V_740 ,
V_738 -> V_599 , V_738 -> V_741 ,
V_739 ) ;
return 0 ;
}
long F_301 ( struct V_563 * V_564 ,
unsigned int V_565 , unsigned long V_566 )
{
struct V_90 * V_90 = V_564 -> V_657 ;
void V_389 * V_567 = ( void V_389 * ) V_566 ;
int V_108 = - V_742 ;
union {
struct V_713 V_714 ;
struct V_719 V_743 ;
struct V_744 V_745 ;
} V_660 ;
switch ( V_565 ) {
case V_746 :
V_108 = F_275 ( V_90 , V_566 ) ;
break;
case V_747 : {
T_2 V_696 ;
V_108 = - V_89 ;
if ( F_225 ( & V_696 , V_567 , sizeof V_696 ) )
goto V_102;
V_108 = F_276 ( V_90 , V_696 ) ;
break;
}
case V_748 :
V_108 = F_277 ( V_90 , V_566 ) ;
break;
case V_749 :
V_108 = F_279 ( V_90 ) ;
break;
case V_750 : {
struct V_751 * V_752 ;
F_206 ( & V_90 -> V_467 ) ;
V_108 = - V_753 ;
if ( V_90 -> V_5 . V_752 )
goto V_754;
V_108 = - V_584 ;
if ( F_126 ( & V_90 -> V_261 ) )
goto V_754;
V_108 = - V_376 ;
V_752 = F_302 ( V_90 ) ;
if ( V_752 ) {
V_108 = F_303 ( V_90 ) ;
if ( V_108 ) {
F_206 ( & V_90 -> V_700 ) ;
F_304 ( V_90 , V_755 ,
& V_752 -> V_756 ) ;
F_304 ( V_90 , V_755 ,
& V_752 -> V_757 ) ;
F_304 ( V_90 , V_755 ,
& V_752 -> V_758 ) ;
F_207 ( & V_90 -> V_700 ) ;
F_179 ( V_752 ) ;
goto V_754;
}
} else
goto V_754;
F_13 () ;
V_90 -> V_5 . V_752 = V_752 ;
F_13 () ;
V_108 = F_305 ( V_90 ) ;
if ( V_108 ) {
F_206 ( & V_90 -> V_700 ) ;
F_206 ( & V_90 -> V_759 ) ;
F_306 ( V_90 ) ;
F_307 ( V_90 ) ;
F_207 ( & V_90 -> V_759 ) ;
F_207 ( & V_90 -> V_700 ) ;
}
V_754:
F_207 ( & V_90 -> V_467 ) ;
break;
}
case V_760 :
V_660 . V_745 . V_271 = V_761 ;
goto V_762;
case V_763 :
V_108 = - V_89 ;
if ( F_225 ( & V_660 . V_745 , V_567 ,
sizeof( struct V_744 ) ) )
goto V_102;
V_762:
F_206 ( & V_90 -> V_700 ) ;
V_108 = - V_753 ;
if ( V_90 -> V_5 . V_715 )
goto V_764;
V_108 = - V_376 ;
V_90 -> V_5 . V_715 = F_308 ( V_90 , V_660 . V_745 . V_271 ) ;
if ( V_90 -> V_5 . V_715 )
V_108 = 0 ;
V_764:
F_207 ( & V_90 -> V_700 ) ;
break;
case V_765 : {
struct V_703 * V_704 ;
V_704 = F_176 ( V_567 , sizeof( * V_704 ) ) ;
if ( F_177 ( V_704 ) ) {
V_108 = F_178 ( V_704 ) ;
goto V_102;
}
V_108 = - V_601 ;
if ( ! F_82 ( V_90 ) )
goto V_766;
V_108 = F_280 ( V_90 , V_704 ) ;
if ( V_108 )
goto V_766;
V_108 = - V_89 ;
if ( F_226 ( V_567 , V_704 , sizeof *V_704 ) )
goto V_766;
V_108 = 0 ;
V_766:
F_179 ( V_704 ) ;
break;
}
case V_767 : {
struct V_703 * V_704 ;
V_704 = F_176 ( V_567 , sizeof( * V_704 ) ) ;
if ( F_177 ( V_704 ) ) {
V_108 = F_178 ( V_704 ) ;
goto V_102;
}
V_108 = - V_601 ;
if ( ! F_82 ( V_90 ) )
goto V_768;
V_108 = F_283 ( V_90 , V_704 ) ;
if ( V_108 )
goto V_768;
V_108 = 0 ;
V_768:
F_179 ( V_704 ) ;
break;
}
case V_769 : {
V_108 = - V_89 ;
if ( F_225 ( & V_660 . V_714 , V_567 , sizeof( struct V_713 ) ) )
goto V_102;
V_108 = - V_601 ;
if ( ! V_90 -> V_5 . V_715 )
goto V_102;
V_108 = F_286 ( V_90 , & V_660 . V_714 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_567 , & V_660 . V_714 , sizeof( struct V_713 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_770 : {
V_108 = - V_89 ;
if ( F_225 ( & V_660 . V_714 , V_567 , sizeof V_660 . V_714 ) )
goto V_102;
V_108 = - V_601 ;
if ( ! V_90 -> V_5 . V_715 )
goto V_102;
V_108 = F_287 ( V_90 , & V_660 . V_714 ) ;
break;
}
case V_771 : {
V_108 = - V_601 ;
if ( ! V_90 -> V_5 . V_715 )
goto V_102;
V_108 = F_289 ( V_90 , & V_660 . V_743 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_567 , & V_660 . V_743 , sizeof( V_660 . V_743 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_772 : {
V_108 = - V_89 ;
if ( F_225 ( & V_660 . V_743 , V_567 , sizeof( V_660 . V_743 ) ) )
goto V_102;
V_108 = - V_601 ;
if ( ! V_90 -> V_5 . V_715 )
goto V_102;
V_108 = F_290 ( V_90 , & V_660 . V_743 ) ;
break;
}
case V_773 : {
struct V_724 V_725 ;
V_108 = - V_89 ;
if ( F_225 ( & V_725 , V_567 , sizeof( V_725 ) ) )
goto V_102;
V_108 = F_291 ( V_90 , & V_725 ) ;
break;
}
case V_774 : {
V_108 = - V_89 ;
if ( F_225 ( & V_90 -> V_5 . F_175 , V_567 ,
sizeof( struct V_775 ) ) )
goto V_102;
V_108 = - V_584 ;
if ( V_90 -> V_5 . F_175 . V_271 )
goto V_102;
V_108 = 0 ;
break;
}
case V_776 : {
struct V_777 V_778 ;
T_2 V_779 ;
T_12 V_282 ;
V_108 = - V_89 ;
if ( F_225 ( & V_778 , V_567 , sizeof( V_778 ) ) )
goto V_102;
V_108 = - V_584 ;
if ( V_778 . V_271 )
goto V_102;
V_108 = 0 ;
F_309 () ;
V_779 = F_115 () ;
V_282 = V_778 . clock - V_779 ;
F_310 () ;
V_90 -> V_5 . V_222 = V_282 ;
F_150 ( V_90 ) ;
break;
}
case V_780 : {
struct V_777 V_778 ;
T_2 V_779 ;
F_309 () ;
V_779 = F_115 () ;
V_778 . clock = V_90 -> V_5 . V_222 + V_779 ;
F_310 () ;
V_778 . V_271 = 0 ;
memset ( & V_778 . V_619 , 0 , sizeof( V_778 . V_619 ) ) ;
V_108 = - V_89 ;
if ( F_226 ( V_567 , & V_778 , sizeof( V_778 ) ) )
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
static void F_311 ( void )
{
T_1 V_781 [ 2 ] ;
unsigned V_3 , V_782 ;
for ( V_3 = V_782 = V_783 ; V_3 < F_46 ( V_575 ) ; V_3 ++ ) {
if ( F_312 ( V_575 [ V_3 ] , & V_781 [ 0 ] , & V_781 [ 1 ] ) < 0 )
continue;
switch ( V_575 [ V_3 ] ) {
case V_784 :
if ( ! V_64 -> V_785 () )
continue;
break;
default:
break;
}
if ( V_782 < V_3 )
V_575 [ V_782 ] = V_575 [ V_3 ] ;
V_782 ++ ;
}
V_572 = V_782 ;
}
static int F_313 ( struct V_1 * V_2 , T_6 V_385 , int V_83 ,
const void * V_242 )
{
int V_786 = 0 ;
int V_501 ;
do {
V_501 = F_314 ( V_83 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_597 &&
! F_315 ( & V_2 -> V_5 . V_597 -> V_787 , V_385 , V_501 , V_242 ) )
&& F_316 ( V_2 -> V_90 , V_788 , V_385 , V_501 , V_242 ) )
break;
V_786 += V_501 ;
V_385 += V_501 ;
V_83 -= V_501 ;
V_242 += V_501 ;
} while ( V_83 );
return V_786 ;
}
static int F_317 ( struct V_1 * V_2 , T_6 V_385 , int V_83 , void * V_242 )
{
int V_786 = 0 ;
int V_501 ;
do {
V_501 = F_314 ( V_83 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_597 &&
! F_318 ( & V_2 -> V_5 . V_597 -> V_787 , V_385 , V_501 , V_242 ) )
&& F_319 ( V_2 -> V_90 , V_788 , V_385 , V_501 , V_242 ) )
break;
F_320 ( V_789 , V_501 , V_385 , * ( T_2 * ) V_242 ) ;
V_786 += V_501 ;
V_385 += V_501 ;
V_83 -= V_501 ;
V_242 += V_501 ;
} while ( V_83 );
return V_786 ;
}
static void F_321 ( struct V_1 * V_2 ,
struct V_790 * V_791 , int V_792 )
{
V_64 -> V_793 ( V_2 , V_791 , V_792 ) ;
}
void F_322 ( struct V_1 * V_2 ,
struct V_790 * V_791 , int V_792 )
{
V_64 -> V_794 ( V_2 , V_791 , V_792 ) ;
}
T_6 F_323 ( struct V_1 * V_2 , T_6 V_405 , T_1 V_84 )
{
T_6 V_795 ;
struct V_66 V_57 ;
F_324 ( ! F_35 ( V_2 ) ) ;
V_84 |= V_100 ;
V_795 = V_2 -> V_5 . V_75 . V_796 ( V_2 , V_405 , V_84 , & V_57 ) ;
return V_795 ;
}
T_6 F_325 ( struct V_1 * V_2 , T_16 V_797 ,
struct V_66 * V_57 )
{
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
return V_2 -> V_5 . V_92 -> V_796 ( V_2 , V_797 , V_84 , V_57 ) ;
}
T_6 F_326 ( struct V_1 * V_2 , T_16 V_797 ,
struct V_66 * V_57 )
{
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
V_84 |= V_798 ;
return V_2 -> V_5 . V_92 -> V_796 ( V_2 , V_797 , V_84 , V_57 ) ;
}
T_6 F_327 ( struct V_1 * V_2 , T_16 V_797 ,
struct V_66 * V_57 )
{
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
V_84 |= V_101 ;
return V_2 -> V_5 . V_92 -> V_796 ( V_2 , V_797 , V_84 , V_57 ) ;
}
T_6 F_328 ( struct V_1 * V_2 , T_16 V_797 ,
struct V_66 * V_57 )
{
return V_2 -> V_5 . V_92 -> V_796 ( V_2 , V_797 , 0 , V_57 ) ;
}
static int F_329 ( T_16 V_385 , void * V_171 , unsigned int V_799 ,
struct V_1 * V_2 , T_1 V_84 ,
struct V_66 * V_57 )
{
void * V_37 = V_171 ;
int V_108 = V_800 ;
while ( V_799 ) {
T_6 V_405 = V_2 -> V_5 . V_92 -> V_796 ( V_2 , V_385 , V_84 ,
V_57 ) ;
unsigned V_82 = V_385 & ( V_96 - 1 ) ;
unsigned V_801 = F_314 ( V_799 , ( unsigned ) V_96 - V_82 ) ;
int V_97 ;
if ( V_405 == V_88 )
return V_802 ;
V_97 = F_107 ( V_2 -> V_90 , V_405 , V_37 , V_801 ) ;
if ( V_97 < 0 ) {
V_108 = V_803 ;
goto V_102;
}
V_799 -= V_801 ;
V_37 += V_801 ;
V_385 += V_801 ;
}
V_102:
return V_108 ;
}
static int F_330 ( struct V_804 * V_805 ,
T_16 V_385 , void * V_171 , unsigned int V_799 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
return F_329 ( V_385 , V_171 , V_799 , V_2 ,
V_84 | V_798 ,
V_57 ) ;
}
int F_332 ( struct V_804 * V_805 ,
T_16 V_385 , void * V_171 , unsigned int V_799 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
return F_329 ( V_385 , V_171 , V_799 , V_2 , V_84 ,
V_57 ) ;
}
static int F_333 ( struct V_804 * V_805 ,
T_16 V_385 , void * V_171 , unsigned int V_799 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
return F_329 ( V_385 , V_171 , V_799 , V_2 , 0 , V_57 ) ;
}
int F_334 ( struct V_804 * V_805 ,
T_16 V_385 , void * V_171 ,
unsigned int V_799 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
void * V_37 = V_171 ;
int V_108 = V_800 ;
while ( V_799 ) {
T_6 V_405 = V_2 -> V_5 . V_92 -> V_796 ( V_2 , V_385 ,
V_101 ,
V_57 ) ;
unsigned V_82 = V_385 & ( V_96 - 1 ) ;
unsigned V_806 = F_314 ( V_799 , ( unsigned ) V_96 - V_82 ) ;
int V_97 ;
if ( V_405 == V_88 )
return V_802 ;
V_97 = F_108 ( V_2 -> V_90 , V_405 , V_37 , V_806 ) ;
if ( V_97 < 0 ) {
V_108 = V_803 ;
goto V_102;
}
V_799 -= V_806 ;
V_37 += V_806 ;
V_385 += V_806 ;
}
V_102:
return V_108 ;
}
static int F_335 ( struct V_1 * V_2 , unsigned long V_797 ,
T_6 * V_405 , struct V_66 * V_57 ,
bool V_807 )
{
T_1 V_84 = ( ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 )
| ( V_807 ? V_101 : 0 ) ;
if ( F_336 ( V_2 , V_797 )
&& ! F_337 ( V_2 , V_2 -> V_5 . V_92 ,
V_2 -> V_5 . V_84 , V_84 ) ) {
* V_405 = V_2 -> V_5 . V_808 << V_95 |
( V_797 & ( V_96 - 1 ) ) ;
F_338 ( V_797 , * V_405 , V_807 , false ) ;
return 1 ;
}
* V_405 = V_2 -> V_5 . V_92 -> V_796 ( V_2 , V_797 , V_84 , V_57 ) ;
if ( * V_405 == V_88 )
return - 1 ;
if ( ( * V_405 & V_372 ) == V_809 )
return 1 ;
if ( F_339 ( V_2 , * V_405 ) ) {
F_338 ( V_797 , * V_405 , V_807 , true ) ;
return 1 ;
}
return 0 ;
}
int F_340 ( struct V_1 * V_2 , T_6 V_405 ,
const void * V_171 , int V_799 )
{
int V_97 ;
V_97 = F_108 ( V_2 -> V_90 , V_405 , V_171 , V_799 ) ;
if ( V_97 < 0 )
return 0 ;
F_341 ( V_2 , V_405 , V_171 , V_799 ) ;
return 1 ;
}
static int F_342 ( struct V_1 * V_2 , void * V_171 , int V_799 )
{
if ( V_2 -> V_810 ) {
F_320 ( V_789 , V_799 ,
V_2 -> V_811 [ 0 ] . V_405 , * ( T_2 * ) V_171 ) ;
V_2 -> V_810 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_343 ( struct V_1 * V_2 , T_6 V_405 ,
void * V_171 , int V_799 )
{
return ! F_107 ( V_2 -> V_90 , V_405 , V_171 , V_799 ) ;
}
static int F_344 ( struct V_1 * V_2 , T_6 V_405 ,
void * V_171 , int V_799 )
{
return F_340 ( V_2 , V_405 , V_171 , V_799 ) ;
}
static int F_345 ( struct V_1 * V_2 , T_6 V_405 , int V_799 , void * V_171 )
{
F_320 ( V_812 , V_799 , V_405 , * ( T_2 * ) V_171 ) ;
return F_313 ( V_2 , V_405 , V_799 , V_171 ) ;
}
static int F_346 ( struct V_1 * V_2 , T_6 V_405 ,
void * V_171 , int V_799 )
{
F_320 ( V_813 , V_799 , V_405 , 0 ) ;
return V_803 ;
}
static int F_347 ( struct V_1 * V_2 , T_6 V_405 ,
void * V_171 , int V_799 )
{
struct V_814 * V_815 = & V_2 -> V_811 [ 0 ] ;
memcpy ( V_2 -> V_816 -> V_817 . V_37 , V_815 -> V_37 , F_314 ( 8u , V_815 -> V_83 ) ) ;
return V_800 ;
}
static int F_348 ( unsigned long V_385 , void * V_171 ,
unsigned int V_799 ,
struct V_66 * V_57 ,
struct V_1 * V_2 ,
const struct V_818 * V_819 )
{
T_6 V_405 ;
int V_786 , V_97 ;
bool V_807 = V_819 -> V_807 ;
struct V_814 * V_815 ;
V_97 = F_335 ( V_2 , V_385 , & V_405 , V_57 , V_807 ) ;
if ( V_97 < 0 )
return V_802 ;
if ( V_97 )
goto V_817;
if ( V_819 -> V_820 ( V_2 , V_405 , V_171 , V_799 ) )
return V_800 ;
V_817:
V_786 = V_819 -> V_821 ( V_2 , V_405 , V_799 , V_171 ) ;
if ( V_786 == V_799 )
return V_800 ;
V_405 += V_786 ;
V_799 -= V_786 ;
V_171 += V_786 ;
F_349 ( V_2 -> V_822 >= V_823 ) ;
V_815 = & V_2 -> V_811 [ V_2 -> V_822 ++ ] ;
V_815 -> V_405 = V_405 ;
V_815 -> V_37 = V_171 ;
V_815 -> V_83 = V_799 ;
return V_800 ;
}
int F_350 ( struct V_804 * V_805 , unsigned long V_385 ,
void * V_171 , unsigned int V_799 ,
struct V_66 * V_57 ,
const struct V_818 * V_819 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
T_6 V_405 ;
int V_824 ;
if ( V_819 -> V_825 &&
V_819 -> V_825 ( V_2 , V_171 , V_799 ) )
return V_800 ;
V_2 -> V_822 = 0 ;
if ( ( ( V_385 + V_799 - 1 ) ^ V_385 ) & V_372 ) {
int V_826 ;
V_826 = - V_385 & ~ V_372 ;
V_824 = F_348 ( V_385 , V_171 , V_826 , V_57 ,
V_2 , V_819 ) ;
if ( V_824 != V_800 )
return V_824 ;
V_385 += V_826 ;
V_171 += V_826 ;
V_799 -= V_826 ;
}
V_824 = F_348 ( V_385 , V_171 , V_799 , V_57 ,
V_2 , V_819 ) ;
if ( V_824 != V_800 )
return V_824 ;
if ( ! V_2 -> V_822 )
return V_824 ;
V_405 = V_2 -> V_811 [ 0 ] . V_405 ;
V_2 -> V_827 = 1 ;
V_2 -> V_828 = 0 ;
V_2 -> V_816 -> V_817 . V_83 = F_314 ( 8u , V_2 -> V_811 [ 0 ] . V_83 ) ;
V_2 -> V_816 -> V_817 . V_829 = V_2 -> V_830 = V_819 -> V_807 ;
V_2 -> V_816 -> V_831 = V_832 ;
V_2 -> V_816 -> V_817 . V_833 = V_405 ;
return V_819 -> V_834 ( V_2 , V_405 , V_171 , V_799 ) ;
}
static int F_351 ( struct V_804 * V_805 ,
unsigned long V_385 ,
void * V_171 ,
unsigned int V_799 ,
struct V_66 * V_57 )
{
return F_350 ( V_805 , V_385 , V_171 , V_799 ,
V_57 , & V_835 ) ;
}
int F_352 ( struct V_804 * V_805 ,
unsigned long V_385 ,
const void * V_171 ,
unsigned int V_799 ,
struct V_66 * V_57 )
{
return F_350 ( V_805 , V_385 , ( void * ) V_171 , V_799 ,
V_57 , & V_836 ) ;
}
static int F_353 ( struct V_804 * V_805 ,
unsigned long V_385 ,
const void * V_837 ,
const void * V_838 ,
unsigned int V_799 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
T_6 V_405 ;
struct V_374 * V_374 ;
char * V_839 ;
bool V_840 ;
if ( V_799 > 8 || ( V_799 & ( V_799 - 1 ) ) )
goto V_841;
V_405 = F_327 ( V_2 , V_385 , NULL ) ;
if ( V_405 == V_88 ||
( V_405 & V_372 ) == V_809 )
goto V_841;
if ( ( ( V_405 + V_799 - 1 ) & V_372 ) != ( V_405 & V_372 ) )
goto V_841;
V_374 = F_354 ( V_2 -> V_90 , V_405 >> V_95 ) ;
if ( F_355 ( V_374 ) )
goto V_841;
V_839 = F_356 ( V_374 ) ;
V_839 += F_357 ( V_405 ) ;
switch ( V_799 ) {
case 1 :
V_840 = F_358 ( T_14 , V_839 , V_837 , V_838 ) ;
break;
case 2 :
V_840 = F_358 ( V_842 , V_839 , V_837 , V_838 ) ;
break;
case 4 :
V_840 = F_358 ( T_1 , V_839 , V_837 , V_838 ) ;
break;
case 8 :
V_840 = F_359 ( V_839 , V_837 , V_838 ) ;
break;
default:
F_24 () ;
}
F_360 ( V_839 ) ;
F_361 ( V_374 ) ;
if ( ! V_840 )
return V_843 ;
F_186 ( V_2 -> V_90 , V_405 >> V_95 ) ;
F_341 ( V_2 , V_405 , V_838 , V_799 ) ;
return V_800 ;
V_841:
F_362 ( V_844 L_22 ) ;
return F_352 ( V_805 , V_385 , V_838 , V_799 , V_57 ) ;
}
static int F_363 ( struct V_1 * V_2 , void * V_845 )
{
int V_108 ;
if ( V_2 -> V_5 . V_846 . V_847 )
V_108 = F_319 ( V_2 -> V_90 , V_755 , V_2 -> V_5 . V_846 . V_848 ,
V_2 -> V_5 . V_846 . V_502 , V_845 ) ;
else
V_108 = F_316 ( V_2 -> V_90 , V_755 ,
V_2 -> V_5 . V_846 . V_848 , V_2 -> V_5 . V_846 . V_502 ,
V_845 ) ;
return V_108 ;
}
static int F_364 ( struct V_1 * V_2 , int V_502 ,
unsigned short V_848 , void * V_171 ,
unsigned int V_718 , bool V_847 )
{
V_2 -> V_5 . V_846 . V_848 = V_848 ;
V_2 -> V_5 . V_846 . V_847 = V_847 ;
V_2 -> V_5 . V_846 . V_718 = V_718 ;
V_2 -> V_5 . V_846 . V_502 = V_502 ;
if ( ! F_363 ( V_2 , V_2 -> V_5 . V_849 ) ) {
V_2 -> V_5 . V_846 . V_718 = 0 ;
return 1 ;
}
V_2 -> V_816 -> V_831 = V_850 ;
V_2 -> V_816 -> V_851 . V_852 = V_847 ? V_853 : V_854 ;
V_2 -> V_816 -> V_851 . V_502 = V_502 ;
V_2 -> V_816 -> V_851 . V_855 = V_856 * V_96 ;
V_2 -> V_816 -> V_851 . V_718 = V_718 ;
V_2 -> V_816 -> V_851 . V_848 = V_848 ;
return 0 ;
}
static int F_365 ( struct V_804 * V_805 ,
int V_502 , unsigned short V_848 , void * V_171 ,
unsigned int V_718 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
int V_97 ;
if ( V_2 -> V_5 . V_846 . V_718 )
goto V_857;
V_97 = F_364 ( V_2 , V_502 , V_848 , V_171 , V_718 , true ) ;
if ( V_97 ) {
V_857:
memcpy ( V_171 , V_2 -> V_5 . V_849 , V_502 * V_718 ) ;
F_366 ( V_858 , V_848 , V_502 , V_718 , V_2 -> V_5 . V_849 ) ;
V_2 -> V_5 . V_846 . V_718 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_367 ( struct V_804 * V_805 ,
int V_502 , unsigned short V_848 ,
const void * V_171 , unsigned int V_718 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
memcpy ( V_2 -> V_5 . V_849 , V_171 , V_502 * V_718 ) ;
F_366 ( V_859 , V_848 , V_502 , V_718 , V_2 -> V_5 . V_849 ) ;
return F_364 ( V_2 , V_502 , V_848 , ( void * ) V_171 , V_718 , false ) ;
}
static unsigned long F_368 ( struct V_1 * V_2 , int V_792 )
{
return V_64 -> F_368 ( V_2 , V_792 ) ;
}
static void F_369 ( struct V_804 * V_805 , V_157 V_71 )
{
F_370 ( F_331 ( V_805 ) , V_71 ) ;
}
int F_371 ( struct V_1 * V_2 )
{
if ( ! F_235 ( V_2 ) )
return V_800 ;
if ( V_64 -> V_586 () ) {
int V_23 = F_372 () ;
F_238 ( V_23 , V_2 -> V_5 . V_587 ) ;
F_373 ( V_2 -> V_5 . V_587 ,
F_233 , NULL , 1 ) ;
F_374 () ;
F_375 ( V_2 -> V_5 . V_587 ) ;
} else
F_234 () ;
return V_800 ;
}
static void F_376 ( struct V_804 * V_805 )
{
F_371 ( F_331 ( V_805 ) ) ;
}
int F_377 ( struct V_804 * V_805 , int V_170 , unsigned long * V_860 )
{
return F_90 ( F_331 ( V_805 ) , V_170 , V_860 ) ;
}
int F_378 ( struct V_804 * V_805 , int V_170 , unsigned long V_22 )
{
return F_88 ( F_331 ( V_805 ) , V_170 , V_22 ) ;
}
static T_2 F_379 ( T_2 V_861 , T_1 V_862 )
{
return ( V_861 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_862 ;
}
static unsigned long F_380 ( struct V_804 * V_805 , int V_863 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
unsigned long V_22 ;
switch ( V_863 ) {
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
V_22 = F_70 ( V_2 ) ;
break;
case 8 :
V_22 = F_84 ( V_2 ) ;
break;
default:
F_381 ( L_23 , V_237 , V_863 ) ;
return 0 ;
}
return V_22 ;
}
static int F_382 ( struct V_804 * V_805 , int V_863 , V_157 V_171 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
int V_179 = 0 ;
switch ( V_863 ) {
case 0 :
V_179 = F_54 ( V_2 , F_379 ( F_55 ( V_2 ) , V_171 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_70 = V_171 ;
break;
case 3 :
V_179 = F_77 ( V_2 , V_171 ) ;
break;
case 4 :
V_179 = F_69 ( V_2 , F_379 ( F_70 ( V_2 ) , V_171 ) ) ;
break;
case 8 :
V_179 = F_81 ( V_2 , V_171 ) ;
break;
default:
F_381 ( L_23 , V_237 , V_863 ) ;
V_179 = - 1 ;
}
return V_179 ;
}
static int F_383 ( struct V_804 * V_805 )
{
return V_64 -> V_79 ( F_331 ( V_805 ) ) ;
}
static void F_384 ( struct V_804 * V_805 , struct V_864 * V_865 )
{
V_64 -> V_866 ( F_331 ( V_805 ) , V_865 ) ;
}
static void F_385 ( struct V_804 * V_805 , struct V_864 * V_865 )
{
V_64 -> V_867 ( F_331 ( V_805 ) , V_865 ) ;
}
static void F_386 ( struct V_804 * V_805 , struct V_864 * V_865 )
{
V_64 -> V_868 ( F_331 ( V_805 ) , V_865 ) ;
}
static void F_387 ( struct V_804 * V_805 , struct V_864 * V_865 )
{
V_64 -> V_869 ( F_331 ( V_805 ) , V_865 ) ;
}
static unsigned long F_388 (
struct V_804 * V_805 , int V_792 )
{
return F_368 ( F_331 ( V_805 ) , V_792 ) ;
}
static bool F_389 ( struct V_804 * V_805 , V_842 * V_870 ,
struct V_871 * V_872 , T_1 * V_873 ,
int V_792 )
{
struct V_790 V_791 ;
F_322 ( F_331 ( V_805 ) , & V_791 , V_792 ) ;
* V_870 = V_791 . V_870 ;
if ( V_791 . V_874 ) {
memset ( V_872 , 0 , sizeof( * V_872 ) ) ;
return false ;
}
if ( V_791 . V_875 )
V_791 . V_876 >>= 12 ;
F_390 ( V_872 , V_791 . V_876 ) ;
F_391 ( V_872 , ( unsigned long ) V_791 . V_877 ) ;
#ifdef F_56
if ( V_873 )
* V_873 = V_791 . V_877 >> 32 ;
#endif
V_872 -> type = V_791 . type ;
V_872 -> V_594 = V_791 . V_594 ;
V_872 -> V_878 = V_791 . V_878 ;
V_872 -> V_343 = V_791 . V_879 ;
V_872 -> V_880 = V_791 . V_880 ;
V_872 -> V_881 = V_791 . V_881 ;
V_872 -> V_882 = V_791 . V_172 ;
V_872 -> V_875 = V_791 . V_875 ;
return true ;
}
static void F_392 ( struct V_804 * V_805 , V_842 V_870 ,
struct V_871 * V_872 , T_1 V_873 ,
int V_792 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
struct V_790 V_791 ;
V_791 . V_870 = V_870 ;
V_791 . V_877 = F_393 ( V_872 ) ;
#ifdef F_56
V_791 . V_877 |= ( ( T_2 ) V_873 ) << 32 ;
#endif
V_791 . V_876 = F_394 ( V_872 ) ;
if ( V_872 -> V_875 )
V_791 . V_876 = ( V_791 . V_876 << 12 ) | 0xfff ;
V_791 . type = V_872 -> type ;
V_791 . V_879 = V_872 -> V_343 ;
V_791 . V_878 = V_872 -> V_878 ;
V_791 . V_172 = V_872 -> V_882 ;
V_791 . V_594 = V_872 -> V_594 ;
V_791 . V_881 = V_872 -> V_881 ;
V_791 . V_875 = V_872 -> V_875 ;
V_791 . V_880 = V_872 -> V_880 ;
V_791 . V_879 = V_872 -> V_343 ;
V_791 . V_874 = ! V_791 . V_879 ;
V_791 . V_883 = 0 ;
F_321 ( V_2 , & V_791 , V_792 ) ;
return;
}
static int F_395 ( struct V_804 * V_805 ,
T_1 V_475 , T_2 * V_476 )
{
return F_209 ( F_331 ( V_805 ) , V_475 , V_476 ) ;
}
static int F_396 ( struct V_804 * V_805 ,
T_1 V_475 , T_2 V_37 )
{
struct V_31 V_21 ;
V_21 . V_37 = V_37 ;
V_21 . V_132 = V_475 ;
V_21 . V_39 = false ;
return F_101 ( F_331 ( V_805 ) , & V_21 ) ;
}
static int F_397 ( struct V_804 * V_805 ,
T_1 V_884 , T_2 * V_476 )
{
return F_94 ( F_331 ( V_805 ) , V_884 , V_476 ) ;
}
static void F_398 ( struct V_804 * V_805 )
{
F_331 ( V_805 ) -> V_5 . V_885 = 1 ;
}
static void F_399 ( struct V_804 * V_805 )
{
F_202 () ;
F_400 ( F_331 ( V_805 ) ) ;
F_401 () ;
}
static void F_402 ( struct V_804 * V_805 )
{
F_203 () ;
}
static int F_403 ( struct V_804 * V_805 ,
struct V_886 * V_887 ,
enum V_888 V_889 )
{
return V_64 -> V_890 ( F_331 ( V_805 ) , V_887 , V_889 ) ;
}
static void F_404 ( struct V_804 * V_805 ,
T_1 * V_891 , T_1 * V_892 , T_1 * V_182 , T_1 * V_190 )
{
V_667 ( F_331 ( V_805 ) , V_891 , V_892 , V_182 , V_190 ) ;
}
static V_157 F_405 ( struct V_804 * V_805 , unsigned V_893 )
{
return F_93 ( F_331 ( V_805 ) , V_893 ) ;
}
static void F_406 ( struct V_804 * V_805 , unsigned V_893 , V_157 V_171 )
{
F_95 ( F_331 ( V_805 ) , V_893 , V_171 ) ;
}
static void F_407 ( struct V_1 * V_2 , T_1 V_27 )
{
T_1 V_894 = V_64 -> V_623 ( V_2 , V_27 ) ;
if ( ! ( V_894 & V_27 ) )
V_64 -> V_636 ( V_2 , V_27 ) ;
}
static void F_408 ( struct V_1 * V_2 )
{
struct V_804 * V_805 = & V_2 -> V_5 . V_895 ;
if ( V_805 -> V_57 . V_40 == V_41 )
F_34 ( V_2 , & V_805 -> V_57 ) ;
else if ( V_805 -> V_57 . V_896 )
F_33 ( V_2 , V_805 -> V_57 . V_40 ,
V_805 -> V_57 . V_51 ) ;
else
F_28 ( V_2 , V_805 -> V_57 . V_40 ) ;
}
static void F_409 ( struct V_804 * V_805 )
{
memset ( & V_805 -> V_897 , 0 ,
( void * ) & V_805 -> V_898 - ( void * ) & V_805 -> V_897 ) ;
V_805 -> V_899 . V_720 = 0 ;
V_805 -> V_899 . V_900 = 0 ;
V_805 -> V_901 . V_902 = 0 ;
V_805 -> V_901 . V_900 = 0 ;
V_805 -> V_903 . V_902 = 0 ;
V_805 -> V_903 . V_900 = 0 ;
}
static void F_410 ( struct V_1 * V_2 )
{
struct V_804 * V_805 = & V_2 -> V_5 . V_895 ;
int V_121 , V_122 ;
V_64 -> V_123 ( V_2 , & V_121 , & V_122 ) ;
V_805 -> V_904 = F_411 ( V_2 ) ;
V_805 -> V_905 = F_412 ( V_2 ) ;
V_805 -> V_292 = ( ! F_413 ( V_2 ) ) ? V_906 :
( V_805 -> V_904 & V_907 ) ? V_908 :
( V_122 && F_50 ( V_2 ) ) ? V_909 :
V_121 ? V_910 :
V_911 ;
V_805 -> V_912 = F_414 ( V_2 ) ;
F_409 ( V_805 ) ;
V_2 -> V_5 . V_913 = false ;
}
int F_415 ( struct V_1 * V_2 , int V_599 , int V_914 )
{
struct V_804 * V_805 = & V_2 -> V_5 . V_895 ;
int V_97 ;
F_410 ( V_2 ) ;
V_805 -> V_915 = 2 ;
V_805 -> V_916 = 2 ;
V_805 -> V_917 = V_805 -> V_905 + V_914 ;
V_97 = F_416 ( V_805 , V_599 ) ;
if ( V_97 != V_800 )
return V_918 ;
V_805 -> V_905 = V_805 -> V_917 ;
F_417 ( V_2 , V_805 -> V_905 ) ;
F_418 ( V_2 , V_805 -> V_904 ) ;
if ( V_599 == V_919 )
V_2 -> V_5 . V_628 = 0 ;
else
V_2 -> V_5 . V_620 . V_58 = false ;
return V_920 ;
}
static int F_419 ( struct V_1 * V_2 )
{
int V_108 = V_920 ;
++ V_2 -> V_68 . V_921 ;
F_420 ( V_2 ) ;
if ( ! F_414 ( V_2 ) ) {
V_2 -> V_816 -> V_831 = V_922 ;
V_2 -> V_816 -> V_923 . V_924 = V_925 ;
V_2 -> V_816 -> V_923 . V_926 = 0 ;
V_108 = V_918 ;
}
F_28 ( V_2 , V_180 ) ;
return V_108 ;
}
static bool F_421 ( struct V_1 * V_2 , T_16 V_70 ,
bool V_927 ,
int V_928 )
{
T_6 V_405 = V_70 ;
T_17 V_929 ;
if ( V_928 & V_930 )
return false ;
if ( ! V_2 -> V_5 . V_75 . V_931 ) {
V_405 = F_327 ( V_2 , V_70 , NULL ) ;
if ( V_405 == V_88 )
return true ;
}
V_929 = F_422 ( V_2 -> V_90 , F_42 ( V_405 ) ) ;
if ( F_423 ( V_929 ) )
return false ;
F_424 ( V_929 ) ;
if ( V_2 -> V_5 . V_75 . V_931 ) {
unsigned int V_932 ;
F_134 ( & V_2 -> V_90 -> V_735 ) ;
V_932 = V_2 -> V_90 -> V_5 . V_932 ;
F_135 ( & V_2 -> V_90 -> V_735 ) ;
if ( V_932 )
F_425 ( V_2 -> V_90 , F_42 ( V_405 ) ) ;
return true ;
}
F_425 ( V_2 -> V_90 , F_42 ( V_405 ) ) ;
return ! V_927 ;
}
static bool F_426 ( struct V_804 * V_805 ,
unsigned long V_70 , int V_928 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
unsigned long V_933 , V_934 , V_405 = V_70 ;
V_933 = V_2 -> V_5 . V_933 ;
V_934 = V_2 -> V_5 . V_934 ;
V_2 -> V_5 . V_933 = V_2 -> V_5 . V_934 = 0 ;
if ( ! ( V_928 & V_935 ) )
return false ;
if ( F_427 ( V_805 ) )
return false ;
if ( V_805 -> V_905 == V_933 && V_934 == V_70 )
return false ;
V_2 -> V_5 . V_933 = V_805 -> V_905 ;
V_2 -> V_5 . V_934 = V_70 ;
if ( ! V_2 -> V_5 . V_75 . V_931 )
V_405 = F_327 ( V_2 , V_70 , NULL ) ;
F_425 ( V_2 -> V_90 , F_42 ( V_405 ) ) ;
return true ;
}
static int F_428 ( unsigned long V_385 , T_1 type , T_1 V_164 ,
unsigned long * V_172 )
{
T_1 V_163 = 0 ;
int V_3 ;
T_1 V_936 , V_937 ;
V_936 = V_164 ;
V_937 = V_164 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_936 >>= 2 , V_937 >>= 4 )
if ( ( V_936 & 3 ) && ( V_937 & 15 ) == type && V_172 [ V_3 ] == V_385 )
V_163 |= ( 1 << V_3 ) ;
return V_163 ;
}
static void F_429 ( struct V_1 * V_2 , int * V_108 )
{
struct V_938 * V_938 = V_2 -> V_816 ;
unsigned long V_939 = V_64 -> V_940 ( V_2 ) ;
if ( F_143 ( V_939 & V_941 ) ) {
if ( V_2 -> V_160 & V_942 ) {
V_938 -> V_943 . V_5 . V_163 = V_944 | V_176 ;
V_938 -> V_943 . V_5 . V_945 = V_2 -> V_5 . V_946 ;
V_938 -> V_943 . V_5 . V_57 = V_947 ;
V_938 -> V_831 = V_948 ;
* V_108 = V_949 ;
} else {
V_2 -> V_5 . V_895 . V_904 &= ~ V_941 ;
V_2 -> V_5 . V_163 &= ~ 15 ;
V_2 -> V_5 . V_163 |= V_944 ;
F_28 ( V_2 , V_947 ) ;
}
}
}
static bool F_430 ( struct V_1 * V_2 , int * V_108 )
{
struct V_938 * V_938 = V_2 -> V_816 ;
unsigned long V_905 = V_2 -> V_5 . V_895 . V_905 ;
T_1 V_163 = 0 ;
if ( F_143 ( V_2 -> V_160 & V_161 ) &&
( V_2 -> V_5 . V_165 & V_169 ) ) {
V_163 = F_428 ( V_905 , 0 ,
V_2 -> V_5 . V_165 ,
V_2 -> V_5 . V_173 ) ;
if ( V_163 != 0 ) {
V_938 -> V_943 . V_5 . V_163 = V_163 | V_176 ;
V_938 -> V_943 . V_5 . V_945 = F_412 ( V_2 ) +
F_368 ( V_2 , V_950 ) ;
V_938 -> V_943 . V_5 . V_57 = V_947 ;
V_938 -> V_831 = V_948 ;
* V_108 = V_949 ;
return true ;
}
}
if ( F_143 ( V_2 -> V_5 . V_164 & V_169 ) ) {
V_163 = F_428 ( V_905 , 0 ,
V_2 -> V_5 . V_164 ,
V_2 -> V_5 . V_172 ) ;
if ( V_163 != 0 ) {
V_2 -> V_5 . V_163 &= ~ 15 ;
V_2 -> V_5 . V_163 |= V_163 ;
F_28 ( V_2 , V_947 ) ;
* V_108 = V_920 ;
return true ;
}
}
return false ;
}
int F_431 ( struct V_1 * V_2 ,
unsigned long V_70 ,
int V_928 ,
void * V_951 ,
int V_952 )
{
int V_108 ;
struct V_804 * V_805 = & V_2 -> V_5 . V_895 ;
bool V_500 = true ;
bool V_953 = V_2 -> V_5 . V_927 ;
V_2 -> V_5 . V_927 = false ;
F_432 ( V_2 ) ;
if ( ! ( V_928 & V_954 ) ) {
F_410 ( V_2 ) ;
if ( F_430 ( V_2 , & V_108 ) )
return V_108 ;
V_805 -> V_955 = 0 ;
V_805 -> V_956 = false ;
V_805 -> V_957 = false ;
V_805 -> V_958 = V_928 & V_959 ;
V_108 = F_433 ( V_805 , V_951 , V_952 ) ;
F_434 ( V_2 ) ;
++ V_2 -> V_68 . V_960 ;
if ( V_108 != V_961 ) {
if ( V_928 & V_959 )
return V_918 ;
if ( F_421 ( V_2 , V_70 , V_953 ,
V_928 ) )
return V_920 ;
if ( V_928 & V_962 )
return V_918 ;
return F_419 ( V_2 ) ;
}
}
if ( V_928 & V_962 ) {
F_417 ( V_2 , V_805 -> V_917 ) ;
return V_920 ;
}
if ( F_426 ( V_805 , V_70 , V_928 ) )
return V_920 ;
if ( V_2 -> V_5 . V_913 ) {
V_2 -> V_5 . V_913 = false ;
F_435 ( V_805 ) ;
}
V_963:
V_108 = F_436 ( V_805 ) ;
if ( V_108 == V_964 )
return V_920 ;
if ( V_108 == V_965 ) {
if ( F_421 ( V_2 , V_70 , V_953 ,
V_928 ) )
return V_920 ;
return F_419 ( V_2 ) ;
}
if ( V_805 -> V_956 ) {
F_408 ( V_2 ) ;
V_108 = V_920 ;
} else if ( V_2 -> V_5 . V_846 . V_718 ) {
if ( ! V_2 -> V_5 . V_846 . V_847 ) {
V_2 -> V_5 . V_846 . V_718 = 0 ;
} else {
V_500 = false ;
V_2 -> V_5 . V_966 = V_967 ;
}
V_108 = V_949 ;
} else if ( V_2 -> V_827 ) {
if ( ! V_2 -> V_830 )
V_500 = false ;
V_108 = V_949 ;
V_2 -> V_5 . V_966 = V_968 ;
} else if ( V_108 == V_969 )
goto V_963;
else
V_108 = V_920 ;
if ( V_500 ) {
F_407 ( V_2 , V_805 -> V_955 ) ;
F_27 ( V_56 , V_2 ) ;
V_2 -> V_5 . V_970 = false ;
F_417 ( V_2 , V_805 -> V_905 ) ;
if ( V_108 == V_920 )
F_429 ( V_2 , & V_108 ) ;
F_418 ( V_2 , V_805 -> V_904 ) ;
} else
V_2 -> V_5 . V_970 = true ;
return V_108 ;
}
int F_437 ( struct V_1 * V_2 , int V_502 , unsigned short V_848 )
{
unsigned long V_171 = F_93 ( V_2 , V_184 ) ;
int V_97 = F_367 ( & V_2 -> V_5 . V_895 ,
V_502 , V_848 , & V_171 , 1 ) ;
V_2 -> V_5 . V_846 . V_718 = 0 ;
return V_97 ;
}
static void F_438 ( void * V_887 )
{
F_439 ( V_307 , 0 ) ;
}
static void F_440 ( void * V_37 )
{
struct V_971 * V_972 = V_37 ;
unsigned long V_240 = 0 ;
if ( V_37 )
V_240 = V_972 -> V_838 ;
else if ( ! F_230 ( V_973 ) )
V_240 = F_441 ( F_442 () ) ;
if ( ! V_240 )
V_240 = V_248 ;
F_439 ( V_307 , V_240 ) ;
}
static int F_443 ( struct V_974 * V_975 , unsigned long V_171 ,
void * V_37 )
{
struct V_971 * V_972 = V_37 ;
struct V_90 * V_90 ;
struct V_1 * V_2 ;
int V_3 , V_976 = 0 ;
if ( V_171 == V_977 && V_972 -> V_837 > V_972 -> V_838 )
return 0 ;
if ( V_171 == V_978 && V_972 -> V_837 < V_972 -> V_838 )
return 0 ;
F_239 ( V_972 -> V_23 , F_440 , V_972 , 1 ) ;
F_134 ( & V_979 ) ;
F_444 (kvm, &vm_list, vm_list) {
F_152 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_972 -> V_23 )
continue;
F_27 ( V_298 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_976 = 1 ;
}
}
F_135 ( & V_979 ) ;
if ( V_972 -> V_837 < V_972 -> V_838 && V_976 ) {
F_239 ( V_972 -> V_23 , F_440 , V_972 , 1 ) ;
}
return 0 ;
}
static int F_445 ( struct V_974 * V_980 ,
unsigned long V_981 , void * V_982 )
{
unsigned int V_23 = ( unsigned long ) V_982 ;
switch ( V_981 ) {
case V_983 :
case V_984 :
F_239 ( V_23 , F_440 , NULL , 1 ) ;
break;
case V_985 :
F_239 ( V_23 , F_438 , NULL , 1 ) ;
break;
}
return V_986 ;
}
static void F_446 ( void )
{
int V_23 ;
V_987 = V_248 ;
F_447 () ;
if ( ! F_230 ( V_973 ) ) {
#ifdef F_448
struct V_988 V_989 ;
memset ( & V_989 , 0 , sizeof( V_989 ) ) ;
V_23 = F_372 () ;
F_449 ( & V_989 , V_23 ) ;
if ( V_989 . V_990 . V_991 )
V_987 = V_989 . V_990 . V_991 ;
F_374 () ;
#endif
F_450 ( & V_992 ,
V_993 ) ;
}
F_114 ( L_24 , V_987 ) ;
F_451 (cpu)
F_239 ( V_23 , F_440 , NULL , 1 ) ;
F_452 ( & V_994 ) ;
F_453 () ;
}
int F_454 ( void )
{
return F_455 ( V_995 ) != NULL ;
}
static int F_456 ( void )
{
int V_996 = 3 ;
if ( F_455 ( V_995 ) )
V_996 = V_64 -> V_79 ( F_455 ( V_995 ) ) ;
return V_996 != 0 ;
}
static unsigned long F_457 ( void )
{
unsigned long V_997 = 0 ;
if ( F_455 ( V_995 ) )
V_997 = F_412 ( F_455 ( V_995 ) ) ;
return V_997 ;
}
void F_458 ( struct V_1 * V_2 )
{
F_439 ( V_995 , V_2 ) ;
}
void F_459 ( struct V_1 * V_2 )
{
F_439 ( V_995 , NULL ) ;
}
static void F_460 ( void )
{
T_2 V_27 ;
int V_998 = V_999 . V_1000 ;
V_27 = ( ( 1ull << ( 51 - V_998 + 1 ) ) - 1 ) << V_998 ;
V_27 |= 0x3ull << 62 ;
V_27 |= 1ull ;
#ifdef F_56
if ( V_998 == 52 )
V_27 &= ~ 1ull ;
#endif
F_461 ( V_27 ) ;
}
static void F_462 ( struct V_320 * V_321 )
{
struct V_90 * V_90 ;
struct V_1 * V_2 ;
int V_3 ;
F_134 ( & V_979 ) ;
F_444 (kvm, &vm_list, vm_list)
F_152 (i, vcpu, kvm)
F_153 ( V_264 , & V_2 -> V_299 ) ;
F_148 ( & V_297 , 0 ) ;
F_135 ( & V_979 ) ;
}
static int F_463 ( struct V_974 * V_975 , unsigned long V_1001 ,
void * V_1002 )
{
struct V_200 * V_259 = & V_200 ;
struct V_198 * V_199 = V_1002 ;
F_103 ( V_199 ) ;
if ( V_259 -> clock . V_203 != V_262 &&
F_126 ( & V_297 ) != 0 )
F_464 ( V_1003 , & V_1004 ) ;
return 0 ;
}
int F_465 ( void * V_1005 )
{
int V_108 ;
struct V_64 * V_819 = V_1005 ;
if ( V_64 ) {
F_10 ( V_26 L_25 ) ;
V_108 = - V_753 ;
goto V_102;
}
if ( ! V_819 -> V_1006 () ) {
F_10 ( V_26 L_26 ) ;
V_108 = - V_1007 ;
goto V_102;
}
if ( V_819 -> V_1008 () ) {
F_10 ( V_26 L_27 ) ;
V_108 = - V_1007 ;
goto V_102;
}
V_108 = - V_376 ;
V_25 = F_466 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_102;
}
V_108 = F_467 () ;
if ( V_108 )
goto V_1009;
F_460 () ;
V_64 = V_819 ;
F_311 () ;
F_468 ( V_1010 , V_1011 ,
V_1012 , V_1013 , 0 ) ;
F_446 () ;
F_469 ( & V_1014 ) ;
if ( V_558 )
V_131 = F_470 ( V_129 ) ;
F_471 () ;
#ifdef F_56
F_472 ( & V_1015 ) ;
#endif
return 0 ;
V_1009:
F_473 ( V_25 ) ;
V_102:
return V_108 ;
}
void F_474 ( void )
{
F_475 ( & V_1014 ) ;
if ( ! F_230 ( V_973 ) )
F_476 ( & V_992 ,
V_993 ) ;
F_477 ( & V_994 ) ;
#ifdef F_56
F_478 ( & V_1015 ) ;
#endif
V_64 = NULL ;
F_479 () ;
F_473 ( V_25 ) ;
}
int F_480 ( struct V_1 * V_2 )
{
++ V_2 -> V_68 . V_1016 ;
if ( F_82 ( V_2 -> V_90 ) ) {
V_2 -> V_5 . V_1017 = V_1018 ;
return 1 ;
} else {
V_2 -> V_816 -> V_831 = V_1019 ;
return 0 ;
}
}
int F_481 ( struct V_1 * V_2 )
{
T_2 V_1020 , V_1021 , V_1022 , V_97 ;
T_18 V_1023 , V_1024 , V_1025 , V_179 = V_1026 , V_1027 = 0 ;
bool V_1028 , V_1029 ;
int V_121 , V_122 ;
if ( V_64 -> V_79 ( V_2 ) != 0 || ! F_413 ( V_2 ) ) {
F_28 ( V_2 , V_180 ) ;
return 0 ;
}
V_64 -> V_123 ( V_2 , & V_121 , & V_122 ) ;
V_1029 = F_50 ( V_2 ) && V_122 == 1 ;
if ( ! V_1029 ) {
V_1020 = ( ( T_2 ) F_93 ( V_2 , V_185 ) << 32 ) |
( F_93 ( V_2 , V_184 ) & 0xffffffff ) ;
V_1021 = ( ( T_2 ) F_93 ( V_2 , V_1030 ) << 32 ) |
( F_93 ( V_2 , V_183 ) & 0xffffffff ) ;
V_1022 = ( ( T_2 ) F_93 ( V_2 , V_1031 ) << 32 ) |
( F_93 ( V_2 , V_1032 ) & 0xffffffff ) ;
}
#ifdef F_56
else {
V_1020 = F_93 ( V_2 , V_183 ) ;
V_1021 = F_93 ( V_2 , V_185 ) ;
V_1022 = F_93 ( V_2 , V_1033 ) ;
}
#endif
V_1023 = V_1020 & 0xffff ;
V_1028 = ( V_1020 >> 16 ) & 0x1 ;
V_1025 = ( V_1020 >> 32 ) & 0xfff ;
V_1024 = ( V_1020 >> 48 ) & 0xfff ;
F_482 ( V_1023 , V_1028 , V_1025 , V_1024 , V_1021 , V_1022 ) ;
switch ( V_1023 ) {
case V_1034 :
F_483 ( V_2 ) ;
break;
default:
V_179 = V_1035 ;
break;
}
V_97 = V_179 | ( ( ( T_2 ) V_1027 & 0xfff ) << 32 ) ;
if ( V_1029 ) {
F_95 ( V_2 , V_184 , V_97 ) ;
} else {
F_95 ( V_2 , V_185 , V_97 >> 32 ) ;
F_95 ( V_2 , V_184 , V_97 & 0xffffffff ) ;
}
return 1 ;
}
static void F_484 ( struct V_90 * V_90 , unsigned long V_271 , int V_1036 )
{
struct V_1037 V_1038 ;
V_1038 . V_1039 = 0 ;
V_1038 . V_1040 = 0 ;
V_1038 . V_1041 = V_1036 ;
V_1038 . V_1042 = V_1043 ;
F_485 ( V_90 , 0 , & V_1038 , NULL ) ;
}
int F_486 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1044 , V_1045 , V_1046 , V_1047 , V_97 ;
int V_108 = 1 ;
if ( F_180 ( V_2 -> V_90 ) )
return F_481 ( V_2 ) ;
V_16 = F_93 ( V_2 , V_184 ) ;
V_1044 = F_93 ( V_2 , V_1030 ) ;
V_1045 = F_93 ( V_2 , V_183 ) ;
V_1046 = F_93 ( V_2 , V_185 ) ;
V_1047 = F_93 ( V_2 , V_1032 ) ;
F_487 ( V_16 , V_1044 , V_1045 , V_1046 , V_1047 ) ;
if ( ! F_50 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_1044 &= 0xFFFFFFFF ;
V_1045 &= 0xFFFFFFFF ;
V_1046 &= 0xFFFFFFFF ;
V_1047 &= 0xFFFFFFFF ;
}
if ( V_64 -> V_79 ( V_2 ) != 0 ) {
V_97 = - V_1048 ;
goto V_102;
}
switch ( V_16 ) {
case V_1049 :
V_97 = 0 ;
break;
case V_1050 :
F_484 ( V_2 -> V_90 , V_1044 , V_1045 ) ;
V_97 = 0 ;
break;
default:
V_97 = - V_1051 ;
break;
}
V_102:
F_95 ( V_2 , V_184 , V_97 ) ;
++ V_2 -> V_68 . V_1052 ;
return V_108 ;
}
static int F_488 ( struct V_804 * V_805 )
{
struct V_1 * V_2 = F_331 ( V_805 ) ;
char V_1053 [ 3 ] ;
unsigned long V_1054 = F_412 ( V_2 ) ;
V_64 -> V_388 ( V_2 , V_1053 ) ;
return F_352 ( V_805 , V_1054 , V_1053 , 3 , NULL ) ;
}
static int F_489 ( struct V_1 * V_2 )
{
return ( ! F_82 ( V_2 -> V_90 ) && ! F_490 ( V_2 ) &&
V_2 -> V_816 -> V_1055 &&
F_491 ( V_2 ) ) ;
}
static void F_492 ( struct V_1 * V_2 )
{
struct V_938 * V_938 = V_2 -> V_816 ;
V_938 -> V_1056 = ( F_411 ( V_2 ) & V_1057 ) != 0 ;
V_938 -> V_158 = F_84 ( V_2 ) ;
V_938 -> V_30 = F_18 ( V_2 ) ;
if ( F_82 ( V_2 -> V_90 ) )
V_938 -> V_1058 = 1 ;
else
V_938 -> V_1058 =
F_491 ( V_2 ) &&
! F_490 ( V_2 ) &&
! F_493 ( V_2 ) ;
}
static void F_248 ( struct V_1 * V_2 )
{
int V_1059 , V_1060 ;
if ( ! V_64 -> F_248 )
return;
if ( ! V_2 -> V_5 . V_597 )
return;
if ( ! V_2 -> V_5 . V_597 -> V_676 )
V_1059 = F_494 ( V_2 ) ;
else
V_1059 = - 1 ;
if ( V_1059 != - 1 )
V_1059 >>= 4 ;
V_1060 = F_85 ( V_2 ) ;
V_64 -> F_248 ( V_2 , V_1060 , V_1059 ) ;
}
static int F_495 ( struct V_1 * V_2 , bool V_1061 )
{
int V_108 ;
if ( V_2 -> V_5 . V_57 . V_58 ) {
F_496 ( V_2 -> V_5 . V_57 . V_16 ,
V_2 -> V_5 . V_57 . V_60 ,
V_2 -> V_5 . V_57 . V_51 ) ;
V_64 -> V_1062 ( V_2 , V_2 -> V_5 . V_57 . V_16 ,
V_2 -> V_5 . V_57 . V_60 ,
V_2 -> V_5 . V_57 . V_51 ,
V_2 -> V_5 . V_57 . V_52 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_627 ) {
V_64 -> V_1063 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_620 . V_58 ) {
V_64 -> V_1064 ( V_2 ) ;
return 0 ;
}
if ( F_414 ( V_2 ) && V_64 -> V_1065 ) {
V_108 = V_64 -> V_1065 ( V_2 , V_1061 ) ;
if ( V_108 != 0 )
return V_108 ;
}
if ( V_2 -> V_5 . V_628 ) {
if ( V_64 -> V_1066 ( V_2 ) ) {
-- V_2 -> V_5 . V_628 ;
V_2 -> V_5 . V_627 = true ;
V_64 -> V_1063 ( V_2 ) ;
}
} else if ( F_497 ( V_2 ) ) {
if ( F_414 ( V_2 ) && V_64 -> V_1065 ) {
V_108 = V_64 -> V_1065 ( V_2 , V_1061 ) ;
if ( V_108 != 0 )
return V_108 ;
}
if ( V_64 -> V_1067 ( V_2 ) ) {
F_250 ( V_2 , F_498 ( V_2 ) ,
false ) ;
V_64 -> V_1064 ( V_2 ) ;
}
}
return 0 ;
}
static void F_256 ( struct V_1 * V_2 )
{
unsigned V_876 = 2 ;
if ( V_64 -> V_630 ( V_2 ) || V_2 -> V_5 . V_627 )
V_876 = 1 ;
V_2 -> V_5 . V_628 += F_499 ( & V_2 -> V_5 . V_76 , 0 ) ;
V_2 -> V_5 . V_628 = F_314 ( V_2 -> V_5 . V_628 , V_876 ) ;
F_27 ( V_56 , V_2 ) ;
}
static void F_500 ( struct V_1 * V_2 )
{
T_2 V_1068 [ 4 ] ;
T_1 V_1069 [ 8 ] ;
if ( ! F_501 ( V_2 -> V_5 . V_597 ) )
return;
memset ( V_1068 , 0 , 32 ) ;
memset ( V_1069 , 0 , 32 ) ;
F_502 ( V_2 , V_1068 , V_1069 ) ;
V_64 -> V_1070 ( V_2 , V_1068 ) ;
F_503 ( V_2 , V_1069 ) ;
}
static int F_504 ( struct V_1 * V_2 )
{
int V_108 ;
bool V_1061 = ! F_82 ( V_2 -> V_90 ) &&
V_2 -> V_816 -> V_1055 ;
bool V_1071 = false ;
if ( V_2 -> V_299 ) {
if ( F_505 ( V_1072 , V_2 ) )
F_506 ( V_2 ) ;
if ( F_505 ( V_1073 , V_2 ) )
F_507 ( V_2 ) ;
if ( F_505 ( V_264 , V_2 ) )
F_150 ( V_2 -> V_90 ) ;
if ( F_505 ( V_445 , V_2 ) )
F_166 ( V_2 ) ;
if ( F_505 ( V_298 , V_2 ) ) {
V_108 = F_155 ( V_2 ) ;
if ( F_143 ( V_108 ) )
goto V_102;
}
if ( F_505 ( V_1074 , V_2 ) )
F_78 ( V_2 ) ;
if ( F_505 ( V_1075 , V_2 ) )
V_64 -> V_1076 ( V_2 ) ;
if ( F_505 ( V_1077 , V_2 ) ) {
V_2 -> V_816 -> V_831 = V_1078 ;
V_108 = 0 ;
goto V_102;
}
if ( F_505 ( V_62 , V_2 ) ) {
V_2 -> V_816 -> V_831 = V_1079 ;
V_108 = 0 ;
goto V_102;
}
if ( F_505 ( V_1080 , V_2 ) ) {
V_2 -> V_1081 = 0 ;
V_64 -> V_1082 ( V_2 ) ;
}
if ( F_505 ( V_1083 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1084 = true ;
V_108 = 1 ;
goto V_102;
}
if ( F_505 ( V_450 , V_2 ) )
F_197 ( V_2 ) ;
if ( F_505 ( V_77 , V_2 ) )
F_256 ( V_2 ) ;
if ( F_505 ( V_1085 , V_2 ) )
F_508 ( V_2 ) ;
if ( F_505 ( V_1086 , V_2 ) )
F_509 ( V_2 ) ;
if ( F_505 ( V_1087 , V_2 ) )
F_500 ( V_2 ) ;
}
if ( F_505 ( V_56 , V_2 ) || V_1061 ) {
F_510 ( V_2 ) ;
if ( V_2 -> V_5 . V_1017 == V_1088 ) {
V_108 = 1 ;
goto V_102;
}
if ( F_495 ( V_2 , V_1061 ) != 0 )
V_1071 = true ;
else if ( V_2 -> V_5 . V_628 )
V_64 -> V_1089 ( V_2 ) ;
else if ( F_497 ( V_2 ) || V_1061 )
V_64 -> V_1090 ( V_2 ) ;
if ( F_511 ( V_2 ) ) {
if ( V_64 -> V_1091 )
V_64 -> V_1091 ( V_2 ,
F_494 ( V_2 ) ) ;
F_248 ( V_2 ) ;
F_512 ( V_2 ) ;
}
}
V_108 = F_513 ( V_2 ) ;
if ( F_143 ( V_108 ) ) {
goto V_1092;
}
F_202 () ;
V_64 -> V_1093 ( V_2 ) ;
if ( V_2 -> V_1081 )
F_400 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_292 = V_1094 ;
F_223 ( & V_2 -> V_90 -> V_497 , V_2 -> V_1095 ) ;
F_514 () ;
F_309 () ;
if ( V_2 -> V_292 == V_1096 || V_2 -> V_299
|| F_515 () || F_516 ( V_411 ) ) {
V_2 -> V_292 = V_1097 ;
F_13 () ;
F_310 () ;
F_203 () ;
V_2 -> V_1095 = F_222 ( & V_2 -> V_90 -> V_497 ) ;
V_108 = 1 ;
goto V_1092;
}
if ( V_1071 )
F_517 ( V_2 -> V_23 ) ;
F_518 () ;
if ( F_143 ( V_2 -> V_5 . V_167 ) ) {
F_519 ( 0 , 7 ) ;
F_519 ( V_2 -> V_5 . V_173 [ 0 ] , 0 ) ;
F_519 ( V_2 -> V_5 . V_173 [ 1 ] , 1 ) ;
F_519 ( V_2 -> V_5 . V_173 [ 2 ] , 2 ) ;
F_519 ( V_2 -> V_5 . V_173 [ 3 ] , 3 ) ;
F_519 ( V_2 -> V_5 . V_163 , 6 ) ;
}
F_520 ( V_2 -> V_265 ) ;
V_64 -> V_816 ( V_2 ) ;
if ( F_143 ( V_2 -> V_5 . V_167 & V_1098 ) ) {
int V_3 ;
F_349 ( V_2 -> V_160 & V_161 ) ;
V_64 -> V_1099 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_1100 ; V_3 ++ )
V_2 -> V_5 . V_173 [ V_3 ] = V_2 -> V_5 . V_172 [ V_3 ] ;
}
if ( F_521 () )
F_522 () ;
V_2 -> V_5 . V_286 = V_64 -> V_308 ( V_2 ,
F_159 () ) ;
V_2 -> V_292 = V_1097 ;
F_13 () ;
V_64 -> V_1101 ( V_2 ) ;
++ V_2 -> V_68 . V_1102 ;
F_523 () ;
F_524 () ;
F_203 () ;
V_2 -> V_1095 = F_222 ( & V_2 -> V_90 -> V_497 ) ;
if ( F_143 ( V_1103 == V_1104 ) ) {
unsigned long V_1054 = F_412 ( V_2 ) ;
F_525 ( V_1104 , ( void * ) V_1054 ) ;
}
if ( F_143 ( V_2 -> V_5 . V_1105 ) )
F_27 ( V_298 , V_2 ) ;
if ( V_2 -> V_5 . V_1106 )
F_526 ( V_2 ) ;
V_108 = V_64 -> V_1107 ( V_2 ) ;
return V_108 ;
V_1092:
V_64 -> V_1092 ( V_2 ) ;
if ( F_143 ( V_2 -> V_5 . V_1106 ) )
F_526 ( V_2 ) ;
V_102:
return V_108 ;
}
static int F_527 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_90 * V_90 = V_2 -> V_90 ;
V_2 -> V_1095 = F_222 ( & V_90 -> V_497 ) ;
V_108 = 1 ;
while ( V_108 > 0 ) {
if ( V_2 -> V_5 . V_1017 == V_1108 &&
! V_2 -> V_5 . V_6 . V_1084 )
V_108 = F_504 ( V_2 ) ;
else {
F_223 ( & V_90 -> V_497 , V_2 -> V_1095 ) ;
F_528 ( V_2 ) ;
V_2 -> V_1095 = F_222 ( & V_90 -> V_497 ) ;
if ( F_505 ( V_1109 , V_2 ) ) {
F_510 ( V_2 ) ;
switch( V_2 -> V_5 . V_1017 ) {
case V_1018 :
V_2 -> V_5 . V_1110 . V_1111 = false ;
V_2 -> V_5 . V_1017 =
V_1108 ;
case V_1108 :
V_2 -> V_5 . V_6 . V_1084 = false ;
break;
case V_1088 :
break;
default:
V_108 = - V_1112 ;
break;
}
}
}
if ( V_108 <= 0 )
break;
F_154 ( V_1113 , & V_2 -> V_299 ) ;
if ( F_529 ( V_2 ) )
F_530 ( V_2 ) ;
if ( F_489 ( V_2 ) ) {
V_108 = - V_1112 ;
V_2 -> V_816 -> V_831 = V_1114 ;
++ V_2 -> V_68 . V_1115 ;
}
F_531 ( V_2 ) ;
if ( F_516 ( V_411 ) ) {
V_108 = - V_1112 ;
V_2 -> V_816 -> V_831 = V_1114 ;
++ V_2 -> V_68 . V_1116 ;
}
if ( F_515 () ) {
F_223 ( & V_90 -> V_497 , V_2 -> V_1095 ) ;
F_532 () ;
V_2 -> V_1095 = F_222 ( & V_90 -> V_497 ) ;
}
}
F_223 ( & V_90 -> V_497 , V_2 -> V_1095 ) ;
return V_108 ;
}
static inline int F_533 ( struct V_1 * V_2 )
{
int V_108 ;
V_2 -> V_1095 = F_222 ( & V_2 -> V_90 -> V_497 ) ;
V_108 = F_534 ( V_2 , V_954 ) ;
F_223 ( & V_2 -> V_90 -> V_497 , V_2 -> V_1095 ) ;
if ( V_108 != V_920 )
return 0 ;
return 1 ;
}
static int V_967 ( struct V_1 * V_2 )
{
F_324 ( ! V_2 -> V_5 . V_846 . V_718 ) ;
return F_533 ( V_2 ) ;
}
static int V_968 ( struct V_1 * V_2 )
{
struct V_938 * V_816 = V_2 -> V_816 ;
struct V_814 * V_815 ;
unsigned V_83 ;
F_324 ( ! V_2 -> V_827 ) ;
V_815 = & V_2 -> V_811 [ V_2 -> V_828 ] ;
V_83 = F_314 ( 8u , V_815 -> V_83 ) ;
if ( ! V_2 -> V_830 )
memcpy ( V_815 -> V_37 , V_816 -> V_817 . V_37 , V_83 ) ;
if ( V_815 -> V_83 <= 8 ) {
V_815 ++ ;
V_2 -> V_828 ++ ;
} else {
V_815 -> V_37 += V_83 ;
V_815 -> V_405 += V_83 ;
V_815 -> V_83 -= V_83 ;
}
if ( V_2 -> V_828 >= V_2 -> V_822 ) {
V_2 -> V_827 = 0 ;
if ( V_2 -> V_830 )
return 1 ;
V_2 -> V_810 = 1 ;
return F_533 ( V_2 ) ;
}
V_816 -> V_831 = V_832 ;
V_816 -> V_817 . V_833 = V_815 -> V_405 ;
if ( V_2 -> V_830 )
memcpy ( V_816 -> V_817 . V_37 , V_815 -> V_37 , F_314 ( 8u , V_815 -> V_83 ) ) ;
V_816 -> V_817 . V_83 = F_314 ( 8u , V_815 -> V_83 ) ;
V_816 -> V_817 . V_829 = V_2 -> V_830 ;
V_2 -> V_5 . V_966 = V_968 ;
return 0 ;
}
int F_535 ( struct V_1 * V_2 , struct V_938 * V_938 )
{
int V_108 ;
T_19 V_1117 ;
if ( ! F_536 ( V_411 ) && F_537 ( V_411 ) )
return - V_376 ;
if ( V_2 -> V_1118 )
F_538 ( V_1119 , & V_2 -> V_1120 , & V_1117 ) ;
if ( F_143 ( V_2 -> V_5 . V_1017 == V_1121 ) ) {
F_528 ( V_2 ) ;
F_510 ( V_2 ) ;
F_154 ( V_1109 , & V_2 -> V_299 ) ;
V_108 = - V_1122 ;
goto V_102;
}
if ( ! F_82 ( V_2 -> V_90 ) ) {
if ( F_81 ( V_2 , V_938 -> V_158 ) != 0 ) {
V_108 = - V_584 ;
goto V_102;
}
}
if ( F_143 ( V_2 -> V_5 . V_966 ) ) {
int (* F_539)( struct V_1 * ) = V_2 -> V_5 . V_966 ;
V_2 -> V_5 . V_966 = NULL ;
V_108 = F_539 ( V_2 ) ;
if ( V_108 <= 0 )
goto V_102;
} else
F_349 ( V_2 -> V_5 . V_846 . V_718 || V_2 -> V_827 ) ;
V_108 = F_527 ( V_2 ) ;
V_102:
F_492 ( V_2 ) ;
if ( V_2 -> V_1118 )
F_538 ( V_1119 , & V_1117 , NULL ) ;
return V_108 ;
}
int F_540 ( struct V_1 * V_2 , struct V_1123 * V_596 )
{
if ( V_2 -> V_5 . V_970 ) {
F_541 ( & V_2 -> V_5 . V_895 ) ;
V_2 -> V_5 . V_970 = false ;
}
V_596 -> V_1124 = F_93 ( V_2 , V_184 ) ;
V_596 -> V_1125 = F_93 ( V_2 , V_1030 ) ;
V_596 -> V_1126 = F_93 ( V_2 , V_183 ) ;
V_596 -> V_1127 = F_93 ( V_2 , V_185 ) ;
V_596 -> V_1128 = F_93 ( V_2 , V_1032 ) ;
V_596 -> V_1129 = F_93 ( V_2 , V_1031 ) ;
V_596 -> V_1130 = F_93 ( V_2 , V_1131 ) ;
V_596 -> V_1132 = F_93 ( V_2 , V_1133 ) ;
#ifdef F_56
V_596 -> V_1134 = F_93 ( V_2 , V_1033 ) ;
V_596 -> V_1135 = F_93 ( V_2 , V_1136 ) ;
V_596 -> V_1137 = F_93 ( V_2 , V_1138 ) ;
V_596 -> V_1139 = F_93 ( V_2 , V_1140 ) ;
V_596 -> V_1141 = F_93 ( V_2 , V_1142 ) ;
V_596 -> V_1143 = F_93 ( V_2 , V_1144 ) ;
V_596 -> V_1145 = F_93 ( V_2 , V_1146 ) ;
V_596 -> V_1147 = F_93 ( V_2 , V_1148 ) ;
#endif
V_596 -> V_1054 = F_412 ( V_2 ) ;
V_596 -> V_939 = F_411 ( V_2 ) ;
return 0 ;
}
int F_542 ( struct V_1 * V_2 , struct V_1123 * V_596 )
{
V_2 -> V_5 . V_913 = true ;
V_2 -> V_5 . V_970 = false ;
F_95 ( V_2 , V_184 , V_596 -> V_1124 ) ;
F_95 ( V_2 , V_1030 , V_596 -> V_1125 ) ;
F_95 ( V_2 , V_183 , V_596 -> V_1126 ) ;
F_95 ( V_2 , V_185 , V_596 -> V_1127 ) ;
F_95 ( V_2 , V_1032 , V_596 -> V_1128 ) ;
F_95 ( V_2 , V_1031 , V_596 -> V_1129 ) ;
F_95 ( V_2 , V_1131 , V_596 -> V_1130 ) ;
F_95 ( V_2 , V_1133 , V_596 -> V_1132 ) ;
#ifdef F_56
F_95 ( V_2 , V_1033 , V_596 -> V_1134 ) ;
F_95 ( V_2 , V_1136 , V_596 -> V_1135 ) ;
F_95 ( V_2 , V_1138 , V_596 -> V_1137 ) ;
F_95 ( V_2 , V_1140 , V_596 -> V_1139 ) ;
F_95 ( V_2 , V_1142 , V_596 -> V_1141 ) ;
F_95 ( V_2 , V_1144 , V_596 -> V_1143 ) ;
F_95 ( V_2 , V_1146 , V_596 -> V_1145 ) ;
F_95 ( V_2 , V_1148 , V_596 -> V_1147 ) ;
#endif
F_417 ( V_2 , V_596 -> V_1054 ) ;
F_418 ( V_2 , V_596 -> V_939 ) ;
V_2 -> V_5 . V_57 . V_58 = false ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
void F_543 ( struct V_1 * V_2 , int * V_172 , int * V_881 )
{
struct V_790 V_1149 ;
F_322 ( V_2 , & V_1149 , V_950 ) ;
* V_172 = V_1149 . V_172 ;
* V_881 = V_1149 . V_881 ;
}
int F_544 ( struct V_1 * V_2 ,
struct V_1150 * V_1151 )
{
struct V_864 V_865 ;
F_322 ( V_2 , & V_1151 -> V_1149 , V_950 ) ;
F_322 ( V_2 , & V_1151 -> V_1152 , V_1153 ) ;
F_322 ( V_2 , & V_1151 -> V_1154 , V_1155 ) ;
F_322 ( V_2 , & V_1151 -> V_1156 , V_1157 ) ;
F_322 ( V_2 , & V_1151 -> V_1158 , V_1159 ) ;
F_322 ( V_2 , & V_1151 -> V_1160 , V_1161 ) ;
F_322 ( V_2 , & V_1151 -> V_1162 , V_1163 ) ;
F_322 ( V_2 , & V_1151 -> V_1164 , V_1165 ) ;
V_64 -> V_867 ( V_2 , & V_865 ) ;
V_1151 -> V_1166 . V_876 = V_865 . V_502 ;
V_1151 -> V_1166 . V_877 = V_865 . V_71 ;
V_64 -> V_866 ( V_2 , & V_865 ) ;
V_1151 -> V_1167 . V_876 = V_865 . V_502 ;
V_1151 -> V_1167 . V_877 = V_865 . V_71 ;
V_1151 -> V_109 = F_55 ( V_2 ) ;
V_1151 -> V_70 = V_2 -> V_5 . V_70 ;
V_1151 -> V_93 = F_53 ( V_2 ) ;
V_1151 -> V_143 = F_70 ( V_2 ) ;
V_1151 -> V_158 = F_84 ( V_2 ) ;
V_1151 -> V_119 = V_2 -> V_5 . V_119 ;
V_1151 -> V_30 = F_18 ( V_2 ) ;
memset ( V_1151 -> V_1168 , 0 , sizeof V_1151 -> V_1168 ) ;
if ( V_2 -> V_5 . V_620 . V_58 && ! V_2 -> V_5 . V_620 . V_621 )
F_153 ( V_2 -> V_5 . V_620 . V_16 ,
( unsigned long * ) V_1151 -> V_1168 ) ;
return 0 ;
}
int F_545 ( struct V_1 * V_2 ,
struct V_1169 * V_1017 )
{
F_510 ( V_2 ) ;
if ( V_2 -> V_5 . V_1017 == V_1018 &&
V_2 -> V_5 . V_1110 . V_1111 )
V_1017 -> V_1017 = V_1108 ;
else
V_1017 -> V_1017 = V_2 -> V_5 . V_1017 ;
return 0 ;
}
int F_546 ( struct V_1 * V_2 ,
struct V_1169 * V_1017 )
{
if ( ! F_259 ( V_2 ) &&
V_1017 -> V_1017 != V_1108 )
return - V_584 ;
if ( V_1017 -> V_1017 == V_1170 ) {
V_2 -> V_5 . V_1017 = V_1088 ;
F_153 ( V_1171 , & V_2 -> V_5 . V_597 -> V_1172 ) ;
} else
V_2 -> V_5 . V_1017 = V_1017 -> V_1017 ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
int F_547 ( struct V_1 * V_2 , V_842 V_1173 , int V_1174 ,
int V_1175 , bool V_60 , T_1 V_51 )
{
struct V_804 * V_805 = & V_2 -> V_5 . V_895 ;
int V_97 ;
F_410 ( V_2 ) ;
V_97 = F_548 ( V_805 , V_1173 , V_1174 , V_1175 ,
V_60 , V_51 ) ;
if ( V_97 )
return V_918 ;
F_417 ( V_2 , V_805 -> V_905 ) ;
F_418 ( V_2 , V_805 -> V_904 ) ;
F_27 ( V_56 , V_2 ) ;
return V_920 ;
}
int F_549 ( struct V_1 * V_2 ,
struct V_1150 * V_1151 )
{
struct V_31 V_1176 ;
int V_1177 = 0 ;
int V_1178 , V_1179 , V_349 ;
struct V_864 V_865 ;
if ( ! F_71 ( V_2 ) && ( V_1151 -> V_143 & V_127 ) )
return - V_584 ;
V_865 . V_502 = V_1151 -> V_1166 . V_876 ;
V_865 . V_71 = V_1151 -> V_1166 . V_877 ;
V_64 -> V_869 ( V_2 , & V_865 ) ;
V_865 . V_502 = V_1151 -> V_1167 . V_876 ;
V_865 . V_71 = V_1151 -> V_1167 . V_877 ;
V_64 -> V_868 ( V_2 , & V_865 ) ;
V_2 -> V_5 . V_70 = V_1151 -> V_70 ;
V_1177 |= F_53 ( V_2 ) != V_1151 -> V_93 ;
V_2 -> V_5 . V_93 = V_1151 -> V_93 ;
F_48 ( V_156 , ( V_157 * ) & V_2 -> V_5 . V_105 ) ;
F_81 ( V_2 , V_1151 -> V_158 ) ;
V_1177 |= V_2 -> V_5 . V_119 != V_1151 -> V_119 ;
V_64 -> F_99 ( V_2 , V_1151 -> V_119 ) ;
V_1176 . V_37 = V_1151 -> V_30 ;
V_1176 . V_39 = true ;
F_19 ( V_2 , & V_1176 ) ;
V_1177 |= F_55 ( V_2 ) != V_1151 -> V_109 ;
V_64 -> V_125 ( V_2 , V_1151 -> V_109 ) ;
V_2 -> V_5 . V_109 = V_1151 -> V_109 ;
V_1177 |= F_70 ( V_2 ) != V_1151 -> V_143 ;
V_64 -> V_154 ( V_2 , V_1151 -> V_143 ) ;
if ( V_1151 -> V_143 & V_127 )
F_67 ( V_2 ) ;
V_349 = F_222 ( & V_2 -> V_90 -> V_497 ) ;
if ( ! F_50 ( V_2 ) && F_51 ( V_2 ) ) {
F_45 ( V_2 , V_2 -> V_5 . V_92 , F_53 ( V_2 ) ) ;
V_1177 = 1 ;
}
F_223 ( & V_2 -> V_90 -> V_497 , V_349 ) ;
if ( V_1177 )
F_60 ( V_2 ) ;
V_1179 = V_600 ;
V_1178 = F_550 (
( const unsigned long * ) V_1151 -> V_1168 , V_1179 ) ;
if ( V_1178 < V_1179 ) {
F_250 ( V_2 , V_1178 , false ) ;
F_114 ( L_29 , V_1178 ) ;
}
F_321 ( V_2 , & V_1151 -> V_1149 , V_950 ) ;
F_321 ( V_2 , & V_1151 -> V_1152 , V_1153 ) ;
F_321 ( V_2 , & V_1151 -> V_1154 , V_1155 ) ;
F_321 ( V_2 , & V_1151 -> V_1156 , V_1157 ) ;
F_321 ( V_2 , & V_1151 -> V_1158 , V_1159 ) ;
F_321 ( V_2 , & V_1151 -> V_1160 , V_1161 ) ;
F_321 ( V_2 , & V_1151 -> V_1162 , V_1163 ) ;
F_321 ( V_2 , & V_1151 -> V_1164 , V_1165 ) ;
F_248 ( V_2 ) ;
if ( F_551 ( V_2 ) && F_412 ( V_2 ) == 0xfff0 &&
V_1151 -> V_1149 . V_870 == 0xf000 && V_1151 -> V_1149 . V_877 == 0xffff0000 &&
! F_413 ( V_2 ) )
V_2 -> V_5 . V_1017 = V_1108 ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
int F_552 ( struct V_1 * V_2 ,
struct V_1180 * V_1181 )
{
unsigned long V_939 ;
int V_3 , V_108 ;
if ( V_1181 -> V_725 & ( V_1182 | V_1183 ) ) {
V_108 = - V_1184 ;
if ( V_2 -> V_5 . V_57 . V_58 )
goto V_102;
if ( V_1181 -> V_725 & V_1182 )
F_28 ( V_2 , V_947 ) ;
else
F_28 ( V_2 , V_1185 ) ;
}
V_939 = F_411 ( V_2 ) ;
V_2 -> V_160 = V_1181 -> V_725 ;
if ( ! ( V_2 -> V_160 & V_1186 ) )
V_2 -> V_160 = 0 ;
if ( V_2 -> V_160 & V_161 ) {
for ( V_3 = 0 ; V_3 < V_1100 ; ++ V_3 )
V_2 -> V_5 . V_173 [ V_3 ] = V_1181 -> V_5 . V_1187 [ V_3 ] ;
V_2 -> V_5 . V_165 = V_1181 -> V_5 . V_1187 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1100 ; V_3 ++ )
V_2 -> V_5 . V_173 [ V_3 ] = V_2 -> V_5 . V_172 [ V_3 ] ;
}
F_87 ( V_2 ) ;
if ( V_2 -> V_160 & V_942 )
V_2 -> V_5 . V_946 = F_412 ( V_2 ) +
F_368 ( V_2 , V_950 ) ;
F_418 ( V_2 , V_939 ) ;
V_64 -> V_1188 ( V_2 ) ;
V_108 = 0 ;
V_102:
return V_108 ;
}
int F_553 ( struct V_1 * V_2 ,
struct V_1189 * V_1162 )
{
unsigned long V_1190 = V_1162 -> V_1191 ;
T_6 V_405 ;
int V_349 ;
V_349 = F_222 ( & V_2 -> V_90 -> V_497 ) ;
V_405 = F_328 ( V_2 , V_1190 , NULL ) ;
F_223 ( & V_2 -> V_90 -> V_497 , V_349 ) ;
V_1162 -> V_1192 = V_405 ;
V_1162 -> V_1193 = V_405 != V_88 ;
V_1162 -> V_1194 = 1 ;
V_1162 -> V_1195 = 0 ;
return 0 ;
}
int F_554 ( struct V_1 * V_2 , struct V_1196 * V_1197 )
{
struct V_650 * V_649 =
& V_2 -> V_5 . V_643 . V_644 -> V_649 ;
memcpy ( V_1197 -> V_1198 , V_649 -> V_1199 , 128 ) ;
V_1197 -> V_1200 = V_649 -> V_1201 ;
V_1197 -> V_1202 = V_649 -> V_1203 ;
V_1197 -> V_1204 = V_649 -> V_1205 ;
V_1197 -> V_1206 = V_649 -> V_1207 ;
V_1197 -> V_1208 = V_649 -> V_1054 ;
V_1197 -> V_1209 = V_649 -> V_1210 ;
memcpy ( V_1197 -> V_1211 , V_649 -> V_1212 , sizeof V_649 -> V_1212 ) ;
return 0 ;
}
int F_555 ( struct V_1 * V_2 , struct V_1196 * V_1197 )
{
struct V_650 * V_649 =
& V_2 -> V_5 . V_643 . V_644 -> V_649 ;
memcpy ( V_649 -> V_1199 , V_1197 -> V_1198 , 128 ) ;
V_649 -> V_1201 = V_1197 -> V_1200 ;
V_649 -> V_1203 = V_1197 -> V_1202 ;
V_649 -> V_1205 = V_1197 -> V_1204 ;
V_649 -> V_1207 = V_1197 -> V_1206 ;
V_649 -> V_1054 = V_1197 -> V_1208 ;
V_649 -> V_1210 = V_1197 -> V_1209 ;
memcpy ( V_649 -> V_1212 , V_1197 -> V_1211 , sizeof V_649 -> V_1212 ) ;
return 0 ;
}
int F_556 ( struct V_1 * V_2 )
{
int V_63 ;
V_63 = F_557 ( & V_2 -> V_5 . V_643 ) ;
if ( V_63 )
return V_63 ;
F_558 ( & V_2 -> V_5 . V_643 ) ;
V_2 -> V_5 . V_130 = V_136 ;
V_2 -> V_5 . V_109 |= V_116 ;
return 0 ;
}
static void F_559 ( struct V_1 * V_2 )
{
F_560 ( & V_2 -> V_5 . V_643 ) ;
}
void F_400 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1213 )
return;
F_65 ( V_2 ) ;
V_2 -> V_1213 = 1 ;
F_561 () ;
F_562 ( & V_2 -> V_5 . V_643 ) ;
F_563 ( 1 ) ;
}
void F_244 ( struct V_1 * V_2 )
{
F_65 ( V_2 ) ;
if ( ! V_2 -> V_1213 )
return;
V_2 -> V_1213 = 0 ;
F_564 ( & V_2 -> V_5 . V_643 ) ;
F_565 () ;
++ V_2 -> V_68 . V_1214 ;
F_27 ( V_1080 , V_2 ) ;
F_563 ( 0 ) ;
}
void F_566 ( struct V_1 * V_2 )
{
F_195 ( V_2 ) ;
F_567 ( V_2 -> V_5 . V_587 ) ;
F_559 ( V_2 ) ;
V_64 -> V_1215 ( V_2 ) ;
}
struct V_1 * F_568 ( struct V_90 * V_90 ,
unsigned int V_1216 )
{
if ( F_131 () && F_126 ( & V_90 -> V_261 ) != 0 )
F_362 ( V_844
L_30
L_31 ) ;
return V_64 -> V_1217 ( V_90 , V_1216 ) ;
}
int F_569 ( struct V_1 * V_2 )
{
int V_108 ;
V_2 -> V_5 . V_344 . V_1218 = 1 ;
V_108 = V_588 ( V_2 ) ;
if ( V_108 )
return V_108 ;
F_570 ( V_2 ) ;
F_571 ( V_2 ) ;
V_592 ( V_2 ) ;
return V_108 ;
}
int F_572 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_31 V_21 ;
struct V_90 * V_90 = V_2 -> V_90 ;
V_108 = V_588 ( V_2 ) ;
if ( V_108 )
return V_108 ;
V_21 . V_37 = 0x0 ;
V_21 . V_132 = V_1219 ;
V_21 . V_39 = true ;
F_129 ( V_2 , & V_21 ) ;
V_592 ( V_2 ) ;
F_167 ( & V_90 -> V_5 . V_326 ,
V_327 ) ;
return V_108 ;
}
void F_573 ( struct V_1 * V_2 )
{
int V_108 ;
V_2 -> V_5 . V_6 . V_406 = 0 ;
V_108 = V_588 ( V_2 ) ;
F_324 ( V_108 ) ;
F_506 ( V_2 ) ;
V_592 ( V_2 ) ;
F_559 ( V_2 ) ;
V_64 -> V_1215 ( V_2 ) ;
}
void F_570 ( struct V_1 * V_2 )
{
F_148 ( & V_2 -> V_5 . V_76 , 0 ) ;
V_2 -> V_5 . V_628 = 0 ;
V_2 -> V_5 . V_627 = false ;
memset ( V_2 -> V_5 . V_172 , 0 , sizeof( V_2 -> V_5 . V_172 ) ) ;
V_2 -> V_5 . V_163 = V_176 ;
F_86 ( V_2 ) ;
V_2 -> V_5 . V_164 = V_178 ;
F_87 ( V_2 ) ;
F_27 ( V_56 , V_2 ) ;
V_2 -> V_5 . V_6 . V_406 = 0 ;
V_2 -> V_5 . V_410 . V_406 = 0 ;
F_195 ( V_2 ) ;
F_59 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1084 = false ;
F_574 ( V_2 ) ;
memset ( V_2 -> V_5 . V_596 , 0 , sizeof( V_2 -> V_5 . V_596 ) ) ;
V_2 -> V_5 . V_105 = ~ 0 ;
V_2 -> V_5 . V_106 = ~ 0 ;
V_64 -> V_1220 ( V_2 ) ;
}
void F_575 ( struct V_1 * V_2 , unsigned int V_40 )
{
struct V_790 V_1149 ;
F_322 ( V_2 , & V_1149 , V_950 ) ;
V_1149 . V_870 = V_40 << 8 ;
V_1149 . V_877 = V_40 << 12 ;
F_321 ( V_2 , & V_1149 , V_950 ) ;
F_417 ( V_2 , 0 ) ;
}
int F_576 ( void * V_585 )
{
struct V_90 * V_90 ;
struct V_1 * V_2 ;
int V_3 ;
int V_97 ;
T_2 V_1221 ;
T_2 V_1222 = 0 ;
bool V_1223 , V_1224 = false ;
F_14 () ;
V_97 = V_64 -> V_1225 ( V_585 ) ;
if ( V_97 != 0 )
return V_97 ;
V_1221 = F_159 () ;
V_1223 = ! F_131 () ;
F_444 (kvm, &vm_list, vm_list) {
F_152 (i, vcpu, kvm) {
if ( ! V_1223 && V_2 -> V_23 == F_8 () )
F_153 ( V_298 , & V_2 -> V_299 ) ;
if ( V_1223 && V_2 -> V_5 . V_591 > V_1221 ) {
V_1224 = true ;
if ( V_2 -> V_5 . V_591 > V_1222 )
V_1222 = V_2 -> V_5 . V_591 ;
}
}
}
if ( V_1224 ) {
T_2 V_1226 = V_1222 - V_1221 ;
V_296 = true ;
F_444 (kvm, &vm_list, vm_list) {
F_152 (i, vcpu, kvm) {
V_2 -> V_5 . V_589 += V_1226 ;
V_2 -> V_5 . V_591 = V_1221 ;
F_153 ( V_264 ,
& V_2 -> V_299 ) ;
}
V_90 -> V_5 . V_276 = 0 ;
V_90 -> V_5 . V_278 = 0 ;
}
}
return 0 ;
}
void F_577 ( void * V_585 )
{
V_64 -> V_1227 ( V_585 ) ;
F_17 ( V_585 ) ;
}
int F_578 ( void )
{
return V_64 -> V_1228 () ;
}
void F_579 ( void )
{
V_64 -> V_1229 () ;
}
void F_580 ( void * V_1230 )
{
V_64 -> V_1231 ( V_1230 ) ;
}
bool F_581 ( struct V_1 * V_2 )
{
return F_82 ( V_2 -> V_90 ) == ( V_2 -> V_5 . V_597 != NULL ) ;
}
int F_582 ( struct V_1 * V_2 )
{
struct V_374 * V_374 ;
struct V_90 * V_90 ;
int V_108 ;
F_324 ( V_2 -> V_90 == NULL ) ;
V_90 = V_2 -> V_90 ;
V_2 -> V_5 . V_1110 . V_1111 = false ;
V_2 -> V_5 . V_895 . V_819 = & V_1232 ;
if ( ! F_82 ( V_90 ) || F_551 ( V_2 ) )
V_2 -> V_5 . V_1017 = V_1108 ;
else
V_2 -> V_5 . V_1017 = V_1121 ;
V_374 = F_583 ( V_662 | V_1233 ) ;
if ( ! V_374 ) {
V_108 = - V_376 ;
goto V_1234;
}
V_2 -> V_5 . V_849 = F_584 ( V_374 ) ;
F_123 ( V_2 , V_987 ) ;
V_108 = F_585 ( V_2 ) ;
if ( V_108 < 0 )
goto V_1235;
if ( F_82 ( V_90 ) ) {
V_108 = F_586 ( V_2 ) ;
if ( V_108 < 0 )
goto V_1236;
} else
F_587 ( & V_1237 ) ;
V_2 -> V_5 . V_363 = F_269 ( V_452 * sizeof( T_2 ) * 4 ,
V_662 ) ;
if ( ! V_2 -> V_5 . V_363 ) {
V_108 = - V_376 ;
goto V_1238;
}
V_2 -> V_5 . V_355 = V_452 ;
if ( ! F_588 ( & V_2 -> V_5 . V_587 , V_662 ) ) {
V_108 = - V_376 ;
goto V_1239;
}
V_108 = F_556 ( V_2 ) ;
if ( V_108 )
goto V_1240;
V_2 -> V_5 . V_268 = 0x0 ;
V_2 -> V_5 . V_310 = false ;
V_2 -> V_5 . V_139 = 0 ;
V_2 -> V_5 . V_646 = V_1241 + V_647 ;
F_1 ( V_2 ) ;
F_589 ( V_2 ) ;
return 0 ;
V_1240:
F_567 ( V_2 -> V_5 . V_587 ) ;
V_1239:
F_179 ( V_2 -> V_5 . V_363 ) ;
V_1238:
F_590 ( V_2 ) ;
V_1236:
F_591 ( V_2 ) ;
V_1235:
F_592 ( ( unsigned long ) V_2 -> V_5 . V_849 ) ;
V_1234:
return V_108 ;
}
void F_593 ( struct V_1 * V_2 )
{
int V_349 ;
F_594 ( V_2 ) ;
F_179 ( V_2 -> V_5 . V_363 ) ;
F_590 ( V_2 ) ;
V_349 = F_222 ( & V_2 -> V_90 -> V_497 ) ;
F_591 ( V_2 ) ;
F_223 ( & V_2 -> V_90 -> V_497 , V_349 ) ;
F_592 ( ( unsigned long ) V_2 -> V_5 . V_849 ) ;
if ( ! F_82 ( V_2 -> V_90 ) )
F_595 ( & V_1237 ) ;
}
int F_596 ( struct V_90 * V_90 , unsigned long type )
{
if ( type )
return - V_584 ;
F_597 ( & V_90 -> V_5 . V_1242 ) ;
F_597 ( & V_90 -> V_5 . V_1243 ) ;
F_597 ( & V_90 -> V_5 . V_1244 ) ;
F_148 ( & V_90 -> V_5 . V_1245 , 0 ) ;
F_153 ( V_740 , & V_90 -> V_5 . V_1246 ) ;
F_153 ( V_1247 ,
& V_90 -> V_5 . V_1246 ) ;
F_598 ( & V_90 -> V_5 . V_274 ) ;
F_599 ( & V_90 -> V_5 . V_1248 ) ;
F_600 ( & V_90 -> V_5 . V_289 ) ;
F_147 ( V_90 ) ;
F_601 ( & V_90 -> V_5 . V_324 , F_163 ) ;
F_601 ( & V_90 -> V_5 . V_326 , F_168 ) ;
return 0 ;
}
static void F_602 ( struct V_1 * V_2 )
{
int V_108 ;
V_108 = V_588 ( V_2 ) ;
F_324 ( V_108 ) ;
F_506 ( V_2 ) ;
V_592 ( V_2 ) ;
}
static void F_603 ( struct V_90 * V_90 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_152 (i, vcpu, kvm) {
F_59 ( V_2 ) ;
F_602 ( V_2 ) ;
}
F_152 (i, vcpu, kvm)
F_566 ( V_2 ) ;
F_206 ( & V_90 -> V_467 ) ;
for ( V_3 = 0 ; V_3 < F_126 ( & V_90 -> V_261 ) ; V_3 ++ )
V_90 -> V_1249 [ V_3 ] = NULL ;
F_148 ( & V_90 -> V_261 , 0 ) ;
F_207 ( & V_90 -> V_467 ) ;
}
void F_604 ( struct V_90 * V_90 )
{
F_605 ( & V_90 -> V_5 . V_326 ) ;
F_605 ( & V_90 -> V_5 . V_324 ) ;
F_606 ( V_90 ) ;
F_607 ( V_90 ) ;
}
void F_608 ( struct V_90 * V_90 )
{
if ( V_411 -> V_1250 == V_90 -> V_1250 ) {
struct V_1251 V_1252 ;
memset ( & V_1252 , 0 , sizeof( V_1252 ) ) ;
V_1252 . V_10 = V_1253 ;
F_609 ( V_90 , & V_1252 ) ;
V_1252 . V_10 = V_1254 ;
F_609 ( V_90 , & V_1252 ) ;
V_1252 . V_10 = V_1255 ;
F_609 ( V_90 , & V_1252 ) ;
}
F_610 ( V_90 ) ;
F_179 ( V_90 -> V_5 . V_752 ) ;
F_179 ( V_90 -> V_5 . V_1256 ) ;
F_603 ( V_90 ) ;
if ( V_90 -> V_5 . V_1257 )
F_611 ( V_90 -> V_5 . V_1257 ) ;
if ( V_90 -> V_5 . V_1258 )
F_611 ( V_90 -> V_5 . V_1258 ) ;
F_179 ( F_612 ( V_90 -> V_5 . V_1259 , 1 ) ) ;
}
void F_613 ( struct V_90 * V_90 , struct V_728 * free ,
struct V_728 * V_1260 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1261 ; ++ V_3 ) {
if ( ! V_1260 || free -> V_5 . V_1262 [ V_3 ] != V_1260 -> V_5 . V_1262 [ V_3 ] ) {
F_614 ( free -> V_5 . V_1262 [ V_3 ] ) ;
free -> V_5 . V_1262 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1260 || free -> V_5 . V_1263 [ V_3 - 1 ] !=
V_1260 -> V_5 . V_1263 [ V_3 - 1 ] ) {
F_614 ( free -> V_5 . V_1263 [ V_3 - 1 ] ) ;
free -> V_5 . V_1263 [ V_3 - 1 ] = NULL ;
}
}
}
int F_615 ( struct V_90 * V_90 , struct V_728 * V_10 ,
unsigned long V_1264 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1261 ; ++ V_3 ) {
unsigned long V_1265 ;
int V_1266 ;
int V_741 = V_3 + 1 ;
V_1266 = F_616 ( V_10 -> V_1267 + V_1264 - 1 ,
V_10 -> V_1267 , V_741 ) + 1 ;
V_10 -> V_5 . V_1262 [ V_3 ] =
F_617 ( V_1266 * sizeof( * V_10 -> V_5 . V_1262 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1262 [ V_3 ] )
goto V_377;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1263 [ V_3 - 1 ] = F_617 ( V_1266 *
sizeof( * V_10 -> V_5 . V_1263 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1263 [ V_3 - 1 ] )
goto V_377;
if ( V_10 -> V_1267 & ( F_618 ( V_741 ) - 1 ) )
V_10 -> V_5 . V_1263 [ V_3 - 1 ] [ 0 ] . V_1268 = 1 ;
if ( ( V_10 -> V_1267 + V_1264 ) & ( F_618 ( V_741 ) - 1 ) )
V_10 -> V_5 . V_1263 [ V_3 - 1 ] [ V_1266 - 1 ] . V_1268 = 1 ;
V_1265 = V_10 -> V_1269 >> V_95 ;
if ( ( V_10 -> V_1267 ^ V_1265 ) & ( F_618 ( V_741 ) - 1 ) ||
! F_619 () ) {
unsigned long V_782 ;
for ( V_782 = 0 ; V_782 < V_1266 ; ++ V_782 )
V_10 -> V_5 . V_1263 [ V_3 - 1 ] [ V_782 ] . V_1268 = 1 ;
}
}
return 0 ;
V_377:
for ( V_3 = 0 ; V_3 < V_1261 ; ++ V_3 ) {
F_614 ( V_10 -> V_5 . V_1262 [ V_3 ] ) ;
V_10 -> V_5 . V_1262 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_614 ( V_10 -> V_5 . V_1263 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1263 [ V_3 - 1 ] = NULL ;
}
return - V_376 ;
}
void F_620 ( struct V_90 * V_90 )
{
F_621 ( V_90 ) ;
}
int F_622 ( struct V_90 * V_90 ,
struct V_728 * V_729 ,
struct V_1251 * V_1252 ,
enum V_1270 V_1271 )
{
if ( ( V_729 -> V_1216 >= V_552 ) && ( V_1271 == V_1272 ) ) {
unsigned long V_1269 ;
V_1269 = F_623 ( NULL , 0 , V_729 -> V_1264 * V_96 ,
V_1273 | V_1274 ,
V_1275 | V_1276 , 0 ) ;
if ( F_177 ( ( void * ) V_1269 ) )
return F_178 ( ( void * ) V_1269 ) ;
V_729 -> V_1269 = V_1269 ;
}
return 0 ;
}
void F_624 ( struct V_90 * V_90 ,
struct V_1251 * V_1252 ,
const struct V_728 * V_837 ,
enum V_1270 V_1271 )
{
int V_1277 = 0 ;
if ( ( V_1252 -> V_10 >= V_552 ) && ( V_1271 == V_1278 ) ) {
int V_97 ;
V_97 = F_625 ( V_837 -> V_1269 ,
V_837 -> V_1264 * V_96 ) ;
if ( V_97 < 0 )
F_10 ( V_844
L_32
L_33 ) ;
}
if ( ! V_90 -> V_5 . V_701 )
V_1277 = F_626 ( V_90 ) ;
if ( V_1277 )
F_278 ( V_90 , V_1277 ) ;
if ( ( V_1271 != V_1278 ) && ( V_1252 -> V_271 & V_1279 ) )
F_627 ( V_90 , V_1252 -> V_10 ) ;
}
void F_628 ( struct V_90 * V_90 )
{
F_629 ( V_90 ) ;
}
void F_630 ( struct V_90 * V_90 ,
struct V_728 * V_10 )
{
F_629 ( V_90 ) ;
}
int F_631 ( struct V_1 * V_2 )
{
if ( F_414 ( V_2 ) && V_64 -> V_1065 )
V_64 -> V_1065 ( V_2 , false ) ;
return ( V_2 -> V_5 . V_1017 == V_1108 &&
! V_2 -> V_5 . V_6 . V_1084 )
|| ! F_632 ( & V_2 -> V_1280 . V_1281 )
|| F_633 ( V_2 )
|| V_2 -> V_5 . V_1110 . V_1111
|| F_126 ( & V_2 -> V_5 . V_76 ) ||
( F_491 ( V_2 ) &&
F_490 ( V_2 ) ) ;
}
int F_634 ( struct V_1 * V_2 )
{
return F_635 ( V_2 ) == V_1094 ;
}
int F_491 ( struct V_1 * V_2 )
{
return V_64 -> V_1067 ( V_2 ) ;
}
bool F_636 ( struct V_1 * V_2 , unsigned long V_1282 )
{
unsigned long V_1283 = F_412 ( V_2 ) +
F_368 ( V_2 , V_950 ) ;
return V_1283 == V_1282 ;
}
unsigned long F_411 ( struct V_1 * V_2 )
{
unsigned long V_939 ;
V_939 = V_64 -> V_940 ( V_2 ) ;
if ( V_2 -> V_160 & V_942 )
V_939 &= ~ V_941 ;
return V_939 ;
}
void F_418 ( struct V_1 * V_2 , unsigned long V_939 )
{
if ( V_2 -> V_160 & V_942 &&
F_636 ( V_2 , V_2 -> V_5 . V_946 ) )
V_939 |= V_941 ;
V_64 -> V_1284 ( V_2 , V_939 ) ;
F_27 ( V_56 , V_2 ) ;
}
void F_637 ( struct V_1 * V_2 , struct V_1285 * V_321 )
{
int V_108 ;
if ( ( V_2 -> V_5 . V_75 . V_931 != V_321 -> V_5 . V_931 ) ||
V_321 -> V_1286 )
return;
V_108 = F_513 ( V_2 ) ;
if ( F_143 ( V_108 ) )
return;
if ( ! V_2 -> V_5 . V_75 . V_931 &&
V_321 -> V_5 . V_93 != V_2 -> V_5 . V_75 . V_1287 ( V_2 ) )
return;
V_2 -> V_5 . V_75 . V_1288 ( V_2 , V_321 -> V_797 , 0 , true ) ;
}
static inline T_1 F_638 ( T_5 V_91 )
{
return F_639 ( V_91 & 0xffffffff , F_640 ( V_4 ) ) ;
}
static inline T_1 F_641 ( T_1 V_1289 )
{
return ( V_1289 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_642 ( struct V_1 * V_2 , T_5 V_91 )
{
T_1 V_1289 = F_638 ( V_91 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1289 ] != ~ 0 )
V_1289 = F_641 ( V_1289 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1289 ] = V_91 ;
}
static T_1 F_643 ( struct V_1 * V_2 , T_5 V_91 )
{
int V_3 ;
T_1 V_1289 = F_638 ( V_91 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1289 ] != V_91 &&
V_2 -> V_5 . V_6 . V_7 [ V_1289 ] != ~ 0 ) ; V_3 ++ )
V_1289 = F_641 ( V_1289 ) ;
return V_1289 ;
}
bool F_644 ( struct V_1 * V_2 , T_5 V_91 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_643 ( V_2 , V_91 ) ] == V_91 ;
}
static void F_645 ( struct V_1 * V_2 , T_5 V_91 )
{
T_1 V_3 , V_782 , V_1290 ;
V_3 = V_782 = F_643 ( V_2 , V_91 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_782 = F_641 ( V_782 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_782 ] == ~ 0 )
return;
V_1290 = F_638 ( V_2 -> V_5 . V_6 . V_7 [ V_782 ] ) ;
} while ( ( V_3 <= V_782 ) ? ( V_3 < V_1290 && V_1290 <= V_782 ) : ( V_3 < V_1290 || V_1290 <= V_782 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_782 ] ;
V_3 = V_782 ;
}
}
static int F_646 ( struct V_1 * V_2 , T_1 V_171 )
{
return F_162 ( V_2 -> V_90 , & V_2 -> V_5 . V_6 . V_37 , & V_171 ,
sizeof( V_171 ) ) ;
}
void F_647 ( struct V_1 * V_2 ,
struct V_1285 * V_321 )
{
struct V_66 V_67 ;
F_648 ( V_321 -> V_5 . V_1291 , V_321 -> V_797 ) ;
F_642 ( V_2 , V_321 -> V_5 . V_91 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_406 & V_407 ) ||
( V_2 -> V_5 . V_6 . V_408 &&
V_64 -> V_79 ( V_2 ) == 0 ) )
F_27 ( V_1083 , V_2 ) ;
else if ( ! F_646 ( V_2 , V_1292 ) ) {
V_67 . V_40 = V_41 ;
V_67 . V_896 = true ;
V_67 . V_51 = 0 ;
V_67 . V_72 = false ;
V_67 . V_71 = V_321 -> V_5 . V_1291 ;
F_32 ( V_2 , & V_67 ) ;
}
}
void F_649 ( struct V_1 * V_2 ,
struct V_1285 * V_321 )
{
struct V_66 V_67 ;
F_650 ( V_321 -> V_5 . V_1291 , V_321 -> V_797 ) ;
if ( V_321 -> V_1286 )
V_321 -> V_5 . V_1291 = ~ 0 ;
else
F_645 ( V_2 , V_321 -> V_5 . V_91 ) ;
if ( ( V_2 -> V_5 . V_6 . V_406 & V_407 ) &&
! F_646 ( V_2 , V_1293 ) ) {
V_67 . V_40 = V_41 ;
V_67 . V_896 = true ;
V_67 . V_51 = 0 ;
V_67 . V_72 = false ;
V_67 . V_71 = V_321 -> V_5 . V_1291 ;
F_32 ( V_2 , & V_67 ) ;
}
V_2 -> V_5 . V_6 . V_1084 = false ;
V_2 -> V_5 . V_1017 = V_1108 ;
}
bool F_651 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_406 & V_407 ) )
return true ;
else
return ! F_493 ( V_2 ) &&
V_64 -> V_1067 ( V_2 ) ;
}
void F_652 ( struct V_90 * V_90 )
{
F_37 ( & V_90 -> V_5 . V_1245 ) ;
}
void F_653 ( struct V_90 * V_90 )
{
F_654 ( & V_90 -> V_5 . V_1245 ) ;
}
bool F_236 ( struct V_90 * V_90 )
{
return F_126 ( & V_90 -> V_5 . V_1245 ) ;
}
