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
if ( F_58 ( V_2 , V_124 ) ) {
if ( V_93 & V_155 )
return 1 ;
} else
if ( V_93 & V_156 )
return 1 ;
} else {
if ( F_51 ( V_2 ) ) {
if ( V_93 & V_157 )
return 1 ;
if ( F_57 ( V_2 ) &&
! F_45 ( V_2 , V_2 -> V_5 . V_92 , V_93 ) )
return 1 ;
}
}
V_2 -> V_5 . V_93 = V_93 ;
F_48 ( V_158 , ( V_159 * ) & V_2 -> V_5 . V_105 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
int F_81 ( struct V_1 * V_2 , unsigned long V_160 )
{
if ( V_160 & V_161 )
return 1 ;
if ( F_82 ( V_2 -> V_90 ) )
F_83 ( V_2 , V_160 ) ;
else
V_2 -> V_5 . V_160 = V_160 ;
return 0 ;
}
unsigned long F_84 ( struct V_1 * V_2 )
{
if ( F_82 ( V_2 -> V_90 ) )
return F_85 ( V_2 ) ;
else
return V_2 -> V_5 . V_160 ;
}
static void F_86 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_162 & V_163 ) )
V_64 -> V_164 ( V_2 , V_2 -> V_5 . V_165 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
unsigned long V_166 ;
if ( V_2 -> V_162 & V_163 )
V_166 = V_2 -> V_5 . V_167 ;
else
V_166 = V_2 -> V_5 . V_166 ;
V_64 -> V_168 ( V_2 , V_166 ) ;
V_2 -> V_5 . V_169 &= ~ V_170 ;
if ( V_166 & V_171 )
V_2 -> V_5 . V_169 |= V_170 ;
}
static int F_88 ( struct V_1 * V_2 , int V_172 , unsigned long V_173 )
{
switch ( V_172 ) {
case 0 ... 3 :
V_2 -> V_5 . V_174 [ V_172 ] = V_173 ;
if ( ! ( V_2 -> V_162 & V_163 ) )
V_2 -> V_5 . V_175 [ V_172 ] = V_173 ;
break;
case 4 :
if ( F_58 ( V_2 , V_176 ) )
return 1 ;
case 6 :
if ( V_173 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_165 = ( V_173 & V_177 ) | V_178 ;
F_86 ( V_2 ) ;
break;
case 5 :
if ( F_58 ( V_2 , V_176 ) )
return 1 ;
default:
if ( V_173 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_166 = ( V_173 & V_179 ) | V_180 ;
F_87 ( V_2 ) ;
break;
}
return 0 ;
}
int F_89 ( struct V_1 * V_2 , int V_172 , unsigned long V_173 )
{
int V_181 ;
V_181 = F_88 ( V_2 , V_172 , V_173 ) ;
if ( V_181 > 0 )
F_28 ( V_2 , V_182 ) ;
else if ( V_181 < 0 )
F_31 ( V_2 , 0 ) ;
return V_181 ;
}
static int F_90 ( struct V_1 * V_2 , int V_172 , unsigned long * V_173 )
{
switch ( V_172 ) {
case 0 ... 3 :
* V_173 = V_2 -> V_5 . V_174 [ V_172 ] ;
break;
case 4 :
if ( F_58 ( V_2 , V_176 ) )
return 1 ;
case 6 :
if ( V_2 -> V_162 & V_163 )
* V_173 = V_2 -> V_5 . V_165 ;
else
* V_173 = V_64 -> V_183 ( V_2 ) ;
break;
case 5 :
if ( F_58 ( V_2 , V_176 ) )
return 1 ;
default:
* V_173 = V_2 -> V_5 . V_166 ;
break;
}
return 0 ;
}
int F_91 ( struct V_1 * V_2 , int V_172 , unsigned long * V_173 )
{
if ( F_90 ( V_2 , V_172 , V_173 ) ) {
F_28 ( V_2 , V_182 ) ;
return 1 ;
}
return 0 ;
}
bool F_92 ( struct V_1 * V_2 )
{
T_1 V_184 = F_93 ( V_2 , V_185 ) ;
T_2 V_37 ;
int V_63 ;
V_63 = F_94 ( V_2 , V_184 , & V_37 ) ;
if ( V_63 )
return V_63 ;
F_95 ( V_2 , V_186 , ( T_1 ) V_37 ) ;
F_95 ( V_2 , V_187 , V_37 >> 32 ) ;
return V_63 ;
}
bool F_96 ( struct V_1 * V_2 , T_2 V_119 )
{
if ( V_119 & V_188 )
return false ;
if ( V_119 & V_189 ) {
struct V_190 * V_191 ;
V_191 = F_97 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_191 || ! ( V_191 -> V_192 & F_98 ( V_193 ) ) )
return false ;
}
if ( V_119 & V_194 ) {
struct V_190 * V_191 ;
V_191 = F_97 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_191 || ! ( V_191 -> V_184 & F_98 ( V_195 ) ) )
return false ;
}
return true ;
}
static int F_99 ( struct V_1 * V_2 , T_2 V_119 )
{
T_2 V_196 = V_2 -> V_5 . V_119 ;
if ( ! F_96 ( V_2 , V_119 ) )
return 1 ;
if ( F_57 ( V_2 )
&& ( V_2 -> V_5 . V_119 & V_120 ) != ( V_119 & V_120 ) )
return 1 ;
V_119 &= ~ V_197 ;
V_119 |= V_2 -> V_5 . V_119 & V_197 ;
V_64 -> F_99 ( V_2 , V_119 ) ;
if ( ( V_119 ^ V_196 ) & V_198 )
F_60 ( V_2 ) ;
return 0 ;
}
void F_100 ( T_2 V_27 )
{
V_188 &= ~ V_27 ;
}
int F_101 ( struct V_1 * V_2 , struct V_31 * V_21 )
{
return V_64 -> V_199 ( V_2 , V_21 ) ;
}
static int F_102 ( struct V_1 * V_2 , unsigned V_132 , T_2 * V_37 )
{
struct V_31 V_21 ;
V_21 . V_37 = * V_37 ;
V_21 . V_132 = V_132 ;
V_21 . V_39 = true ;
return F_101 ( V_2 , & V_21 ) ;
}
static void F_103 ( struct V_200 * V_201 )
{
struct V_202 * V_203 = & V_202 ;
F_104 ( & V_203 -> V_204 ) ;
V_203 -> clock . V_205 = V_201 -> clock -> V_206 . V_205 ;
V_203 -> clock . V_207 = V_201 -> clock -> V_207 ;
V_203 -> clock . V_27 = V_201 -> clock -> V_27 ;
V_203 -> clock . V_208 = V_201 -> V_208 ;
V_203 -> clock . V_209 = V_201 -> V_209 ;
V_203 -> V_210 = V_201 -> V_211
+ V_201 -> V_212 . V_213 ;
V_203 -> V_214 = V_201 -> V_215
+ ( V_201 -> V_212 . V_216
<< V_201 -> V_209 ) ;
while ( V_203 -> V_214 >=
( ( ( T_2 ) V_217 ) << V_201 -> V_209 ) ) {
V_203 -> V_214 -=
( ( T_2 ) V_217 ) << V_201 -> V_209 ;
V_203 -> V_210 ++ ;
}
F_105 ( & V_203 -> V_204 ) ;
}
static void F_106 ( struct V_90 * V_90 , T_6 V_218 )
{
int V_219 ;
int V_108 ;
struct V_220 V_221 ;
struct V_222 V_223 ;
if ( ! V_218 )
return;
V_108 = F_107 ( V_90 , V_218 , & V_219 , sizeof( V_219 ) ) ;
if ( V_108 )
return;
if ( V_219 & 1 )
++ V_219 ;
++ V_219 ;
F_108 ( V_90 , V_218 , & V_219 , sizeof( V_219 ) ) ;
F_109 ( & V_223 ) ;
if ( V_90 -> V_5 . V_224 ) {
struct V_222 V_225 = F_110 ( V_90 -> V_5 . V_224 ) ;
V_223 = F_111 ( V_223 , V_225 ) ;
}
V_221 . V_226 = V_223 . V_213 ;
V_221 . V_227 = V_223 . V_216 ;
V_221 . V_219 = V_219 ;
F_108 ( V_90 , V_218 , & V_221 , sizeof( V_221 ) ) ;
V_219 ++ ;
F_108 ( V_90 , V_218 , & V_219 , sizeof( V_219 ) ) ;
}
static T_7 F_112 ( T_7 V_228 , T_7 V_229 )
{
T_7 V_230 , V_231 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_230 ;
}
static void F_113 ( T_7 V_232 , T_7 V_233 ,
T_8 * V_234 , T_1 * V_235 )
{
T_9 V_236 ;
T_10 V_209 = 0 ;
T_9 V_237 ;
T_7 V_238 ;
V_237 = V_233 * 1000LL ;
V_236 = V_232 * 1000LL ;
while ( V_237 > V_236 * 2 || V_237 & 0xffffffff00000000ULL ) {
V_237 >>= 1 ;
V_209 -- ;
}
V_238 = ( T_7 ) V_237 ;
while ( V_238 <= V_236 || V_236 & 0xffffffff00000000ULL ) {
if ( V_236 & 0xffffffff00000000ULL || V_238 & 0x80000000 )
V_236 >>= 1 ;
else
V_238 <<= 1 ;
V_209 ++ ;
}
* V_234 = V_209 ;
* V_235 = F_112 ( V_236 , V_238 ) ;
F_114 ( L_2 ,
V_239 , V_233 , V_232 , V_209 , * V_235 ) ;
}
static inline T_2 F_115 ( void )
{
struct V_222 V_225 ;
F_116 ( & V_225 ) ;
F_117 ( & V_225 ) ;
return F_118 ( & V_225 ) ;
}
static inline T_2 F_119 ( struct V_1 * V_2 , T_2 V_227 )
{
return F_120 ( V_227 , V_2 -> V_5 . V_240 ,
V_2 -> V_5 . V_241 ) ;
}
static T_1 F_121 ( T_1 V_242 , T_11 V_243 )
{
T_2 V_244 = ( T_2 ) V_242 * ( 1000000 + V_243 ) ;
F_122 ( V_244 , 1000000 ) ;
return V_244 ;
}
static void F_123 ( struct V_1 * V_2 , T_1 V_245 )
{
T_1 V_246 , V_247 ;
int V_248 = 0 ;
if ( V_245 == 0 )
return;
F_113 ( V_245 , V_217 / 1000 ,
& V_2 -> V_5 . V_241 ,
& V_2 -> V_5 . V_240 ) ;
V_2 -> V_5 . V_249 = V_245 ;
V_246 = F_121 ( V_250 , - V_251 ) ;
V_247 = F_121 ( V_250 , V_251 ) ;
if ( V_245 < V_246 || V_245 > V_247 ) {
F_114 ( L_3 , V_245 , V_246 , V_247 ) ;
V_248 = 1 ;
}
V_64 -> V_252 ( V_2 , V_245 , V_248 ) ;
}
static T_2 F_124 ( struct V_1 * V_2 , T_12 V_253 )
{
T_2 V_254 = F_120 ( V_253 - V_2 -> V_5 . V_255 ,
V_2 -> V_5 . V_240 ,
V_2 -> V_5 . V_241 ) ;
V_254 += V_2 -> V_5 . V_256 ;
return V_254 ;
}
void F_125 ( struct V_1 * V_2 )
{
#ifdef F_56
bool V_257 ;
bool V_258 = false ;
struct V_259 * V_260 = & V_2 -> V_90 -> V_5 ;
struct V_202 * V_261 = & V_202 ;
V_257 = ( V_260 -> V_262 + 1 ==
F_126 ( & V_2 -> V_90 -> V_263 ) ) ;
if ( V_257 && V_261 -> clock . V_205 == V_264 )
if ( ! V_260 -> V_265 )
V_258 = 1 ;
if ( ! V_257 && V_260 -> V_265 )
V_258 = 1 ;
if ( V_258 )
F_27 ( V_266 , V_2 ) ;
F_127 ( V_2 -> V_267 , V_260 -> V_262 ,
F_126 ( & V_2 -> V_90 -> V_263 ) ,
V_260 -> V_265 , V_261 -> clock . V_205 ) ;
#endif
}
static void F_128 ( struct V_1 * V_2 , T_12 V_82 )
{
T_2 V_268 = V_64 -> V_269 ( V_2 ) ;
V_2 -> V_5 . V_270 += V_82 - V_268 ;
}
void F_129 ( struct V_1 * V_2 , struct V_31 * V_21 )
{
struct V_90 * V_90 = V_2 -> V_90 ;
T_2 V_82 , V_271 , V_272 ;
unsigned long V_273 ;
T_12 V_274 ;
bool V_275 ;
T_2 V_37 = V_21 -> V_37 ;
F_130 ( & V_90 -> V_5 . V_276 , V_273 ) ;
V_82 = V_64 -> V_277 ( V_2 , V_37 ) ;
V_271 = F_115 () ;
V_272 = V_271 - V_90 -> V_5 . V_278 ;
if ( V_2 -> V_5 . V_249 ) {
int V_279 = 0 ;
V_274 = V_37 - V_90 -> V_5 . V_280 ;
#ifdef F_56
V_274 = ( V_274 * 1000 ) / V_2 -> V_5 . V_249 ;
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
F_122 ( V_272 , 1000 ) ;
V_274 -= V_272 ;
if ( V_274 < 0 )
V_274 = - V_274 ;
if ( V_279 )
V_274 = V_281 ;
} else
V_274 = V_281 ;
if ( V_274 < V_281 &&
V_2 -> V_5 . V_249 == V_90 -> V_5 . V_282 ) {
if ( ! F_131 () ) {
V_82 = V_90 -> V_5 . V_283 ;
F_114 ( L_4 , V_37 ) ;
} else {
T_2 V_284 = F_119 ( V_2 , V_272 ) ;
V_37 += V_284 ;
V_82 = V_64 -> V_277 ( V_2 , V_37 ) ;
F_114 ( L_5 , V_284 ) ;
}
V_275 = true ;
} else {
V_90 -> V_5 . V_285 ++ ;
V_90 -> V_5 . V_286 = V_271 ;
V_90 -> V_5 . V_287 = V_37 ;
V_90 -> V_5 . V_283 = V_82 ;
V_275 = false ;
F_114 ( L_6 ,
V_90 -> V_5 . V_285 , V_37 ) ;
}
V_90 -> V_5 . V_278 = V_271 ;
V_90 -> V_5 . V_280 = V_37 ;
V_90 -> V_5 . V_282 = V_2 -> V_5 . V_249 ;
V_2 -> V_5 . V_288 = V_37 ;
V_2 -> V_5 . V_289 = V_90 -> V_5 . V_285 ;
V_2 -> V_5 . V_255 = V_90 -> V_5 . V_286 ;
V_2 -> V_5 . V_256 = V_90 -> V_5 . V_287 ;
if ( F_132 ( V_2 ) && ! V_21 -> V_39 )
F_128 ( V_2 , V_82 ) ;
V_64 -> V_290 ( V_2 , V_82 ) ;
F_133 ( & V_90 -> V_5 . V_276 , V_273 ) ;
F_134 ( & V_90 -> V_5 . V_291 ) ;
if ( V_275 )
V_90 -> V_5 . V_262 ++ ;
else
V_90 -> V_5 . V_262 = 0 ;
F_125 ( V_2 ) ;
F_135 ( & V_90 -> V_5 . V_291 ) ;
}
static T_13 F_136 ( void )
{
T_13 V_97 ;
T_2 V_292 ;
F_137 () ;
V_97 = ( T_13 ) F_138 () ;
V_292 = V_202 . clock . V_207 ;
if ( F_139 ( V_97 >= V_292 ) )
return V_97 ;
asm volatile ("");
return V_292 ;
}
static inline T_2 F_140 ( T_13 * V_293 )
{
long V_244 ;
struct V_202 * V_261 = & V_202 ;
* V_293 = F_136 () ;
V_244 = ( * V_293 - V_261 -> clock . V_207 ) & V_261 -> clock . V_27 ;
return V_244 * V_261 -> clock . V_208 ;
}
static int F_141 ( struct V_222 * V_225 , T_13 * V_293 )
{
unsigned long V_204 ;
T_2 V_271 ;
int V_294 ;
struct V_202 * V_261 = & V_202 ;
V_225 -> V_216 = 0 ;
do {
V_204 = F_142 ( & V_261 -> V_204 ) ;
V_294 = V_261 -> clock . V_205 ;
V_225 -> V_213 = V_261 -> V_210 ;
V_271 = V_261 -> V_214 ;
V_271 += F_140 ( V_293 ) ;
V_271 >>= V_261 -> clock . V_209 ;
} while ( F_143 ( F_144 ( & V_261 -> V_204 , V_204 ) ) );
F_145 ( V_225 , V_271 ) ;
return V_294 ;
}
static bool F_146 ( T_12 * V_253 , T_13 * V_293 )
{
struct V_222 V_225 ;
if ( V_202 . clock . V_205 != V_264 )
return false ;
if ( F_141 ( & V_225 , V_293 ) != V_264 )
return false ;
F_117 ( & V_225 ) ;
* V_253 = F_118 ( & V_225 ) ;
return true ;
}
static void F_147 ( struct V_90 * V_90 )
{
#ifdef F_56
struct V_259 * V_260 = & V_90 -> V_5 ;
int V_205 ;
bool V_295 , V_257 ;
V_257 = ( V_260 -> V_262 + 1 ==
F_126 ( & V_90 -> V_263 ) ) ;
V_295 = F_146 (
& V_260 -> V_296 ,
& V_260 -> V_297 ) ;
V_260 -> V_265 = V_295 && V_257
&& ! V_298 ;
if ( V_260 -> V_265 )
F_148 ( & V_299 , 1 ) ;
V_205 = V_202 . clock . V_205 ;
F_149 ( V_260 -> V_265 , V_205 ,
V_257 ) ;
#endif
}
static void F_150 ( struct V_90 * V_90 )
{
#ifdef F_56
int V_3 ;
struct V_1 * V_2 ;
struct V_259 * V_260 = & V_90 -> V_5 ;
F_134 ( & V_260 -> V_291 ) ;
F_151 ( V_90 ) ;
F_147 ( V_90 ) ;
F_152 (i, vcpu, kvm)
F_153 ( V_300 , & V_2 -> V_301 ) ;
F_152 (i, vcpu, kvm)
F_154 ( V_302 , & V_2 -> V_301 ) ;
F_135 ( & V_260 -> V_291 ) ;
#endif
}
static int F_155 ( struct V_1 * V_244 )
{
unsigned long V_273 , V_245 ;
struct V_303 * V_2 = & V_244 -> V_5 ;
struct V_259 * V_260 = & V_244 -> V_90 -> V_5 ;
T_12 V_253 ;
T_2 V_304 , V_305 ;
struct V_306 V_307 ;
T_14 V_308 ;
bool V_265 ;
V_253 = 0 ;
V_305 = 0 ;
F_134 ( & V_260 -> V_291 ) ;
V_265 = V_260 -> V_265 ;
if ( V_265 ) {
V_305 = V_260 -> V_297 ;
V_253 = V_260 -> V_296 ;
}
F_135 ( & V_260 -> V_291 ) ;
F_156 ( V_273 ) ;
V_245 = F_157 ( V_309 ) ;
if ( F_143 ( V_245 == 0 ) ) {
F_158 ( V_273 ) ;
F_27 ( V_300 , V_244 ) ;
return 1 ;
}
if ( ! V_265 ) {
V_305 = F_159 () ;
V_253 = F_115 () ;
}
V_304 = V_64 -> V_310 ( V_244 , V_305 ) ;
if ( V_2 -> V_311 ) {
T_2 V_254 = F_124 ( V_244 , V_253 ) ;
if ( V_254 > V_304 ) {
F_160 ( V_244 , V_254 - V_304 ) ;
V_304 = V_254 ;
}
}
F_158 ( V_273 ) ;
if ( ! V_2 -> V_312 )
return 0 ;
if ( F_143 ( V_2 -> V_313 != V_245 ) ) {
F_113 ( V_217 / 1000 , V_245 ,
& V_2 -> V_314 . V_315 ,
& V_2 -> V_314 . V_316 ) ;
V_2 -> V_313 = V_245 ;
}
V_2 -> V_314 . V_304 = V_304 ;
V_2 -> V_314 . V_317 = V_253 + V_244 -> V_90 -> V_5 . V_224 ;
V_2 -> V_288 = V_304 ;
V_2 -> V_314 . V_219 += 2 ;
if ( F_143 ( F_161 ( V_244 -> V_90 , & V_2 -> V_318 ,
& V_307 , sizeof( V_307 ) ) ) )
return 0 ;
V_308 = ( V_307 . V_273 & V_319 ) ;
if ( V_2 -> V_320 ) {
V_308 |= V_319 ;
V_2 -> V_320 = false ;
}
if ( V_265 )
V_308 |= V_321 ;
V_2 -> V_314 . V_273 = V_308 ;
F_162 ( V_244 -> V_90 , & V_2 -> V_318 ,
& V_2 -> V_314 ,
sizeof( V_2 -> V_314 ) ) ;
return 0 ;
}
static void F_163 ( struct V_322 * V_323 )
{
int V_3 ;
struct V_324 * V_325 = F_164 ( V_323 ) ;
struct V_259 * V_260 = F_4 ( V_325 , struct V_259 ,
V_326 ) ;
struct V_90 * V_90 = F_4 ( V_260 , struct V_90 , V_5 ) ;
struct V_1 * V_2 ;
F_152 (i, vcpu, kvm) {
F_153 ( V_300 , & V_2 -> V_301 ) ;
F_165 ( V_2 ) ;
}
}
static void F_166 ( struct V_1 * V_244 )
{
struct V_90 * V_90 = V_244 -> V_90 ;
F_153 ( V_300 , & V_244 -> V_301 ) ;
F_167 ( & V_90 -> V_5 . V_326 ,
V_327 ) ;
}
static void F_168 ( struct V_322 * V_323 )
{
struct V_324 * V_325 = F_164 ( V_323 ) ;
struct V_259 * V_260 = F_4 ( V_325 , struct V_259 ,
V_328 ) ;
struct V_90 * V_90 = F_4 ( V_260 , struct V_90 , V_5 ) ;
F_167 ( & V_90 -> V_5 . V_326 , 0 ) ;
F_167 ( & V_90 -> V_5 . V_328 ,
V_329 ) ;
}
static bool F_169 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_330 - 1 :
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
case V_342 :
case V_343 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_170 ( unsigned V_344 )
{
return V_344 < 8 && ( 1 << V_344 ) & 0xf3 ;
}
static bool F_171 ( unsigned V_344 )
{
return V_344 < 8 && ( 1 << V_344 ) & 0x73 ;
}
static bool F_172 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
int V_3 ;
if ( ! F_169 ( V_21 ) )
return false ;
if ( V_21 == V_343 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_170 ( ( V_37 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_342 ) {
if ( V_37 & ~ 0xcff )
return false ;
return F_171 ( V_37 & 0xff ) ;
} else if ( V_21 >= V_331 && V_21 <= V_341 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_171 ( ( V_37 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_171 ( V_37 & 0xff ) ;
}
static int F_173 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
T_2 * V_345 = ( T_2 * ) & V_2 -> V_5 . V_346 . V_347 ;
if ( ! F_172 ( V_2 , V_21 , V_37 ) )
return 1 ;
if ( V_21 == V_342 ) {
V_2 -> V_5 . V_346 . V_348 = V_37 ;
V_2 -> V_5 . V_346 . V_349 = ( V_37 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_331 )
V_345 [ 0 ] = V_37 ;
else if ( V_21 == V_332 || V_21 == V_333 )
V_345 [ 1 + V_21 - V_332 ] = V_37 ;
else if ( V_21 >= V_334 && V_21 <= V_341 )
V_345 [ 3 + V_21 - V_334 ] = V_37 ;
else if ( V_21 == V_343 )
V_2 -> V_5 . V_350 = V_37 ;
else {
int V_351 , V_352 ;
T_2 * V_353 ;
V_351 = ( V_21 - 0x200 ) / 2 ;
V_352 = V_21 - 0x200 - 2 * V_351 ;
if ( ! V_352 )
V_353 =
( T_2 * ) & V_2 -> V_5 . V_346 . V_354 [ V_351 ] . V_355 ;
else
V_353 =
( T_2 * ) & V_2 -> V_5 . V_346 . V_354 [ V_351 ] . V_356 ;
* V_353 = V_37 ;
}
F_60 ( V_2 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
T_2 V_357 = V_2 -> V_5 . V_357 ;
unsigned V_358 = V_357 & 0xff ;
switch ( V_21 ) {
case V_359 :
V_2 -> V_5 . V_360 = V_37 ;
break;
case V_361 :
if ( ! ( V_357 & V_362 ) )
return 1 ;
if ( V_37 != 0 && V_37 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_363 = V_37 ;
break;
default:
if ( V_21 >= V_364 &&
V_21 < V_364 + 4 * V_358 ) {
T_1 V_82 = V_21 - V_364 ;
if ( ( V_82 & 0x3 ) == 0 &&
V_37 != 0 && ( V_37 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_365 [ V_82 ] = V_37 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_175 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_90 * V_90 = V_2 -> V_90 ;
int V_366 = F_50 ( V_2 ) ;
T_14 * V_367 = V_366 ? ( T_14 * ) ( long ) V_90 -> V_5 . F_175 . V_368
: ( T_14 * ) ( long ) V_90 -> V_5 . F_175 . V_369 ;
T_14 V_370 = V_366 ? V_90 -> V_5 . F_175 . V_371
: V_90 -> V_5 . F_175 . V_372 ;
T_1 V_373 = V_37 & ~ V_374 ;
T_2 V_375 = V_37 & V_374 ;
T_14 * V_376 ;
int V_108 ;
V_108 = - V_377 ;
if ( V_373 >= V_370 )
goto V_102;
V_108 = - V_378 ;
V_376 = F_176 ( V_367 + ( V_373 * V_96 ) , V_96 ) ;
if ( F_177 ( V_376 ) ) {
V_108 = F_178 ( V_376 ) ;
goto V_102;
}
if ( F_108 ( V_90 , V_375 , V_376 , V_96 ) )
goto V_379;
V_108 = 0 ;
V_379:
F_179 ( V_376 ) ;
V_102:
return V_108 ;
}
static bool F_180 ( struct V_90 * V_90 )
{
return V_90 -> V_5 . V_380 & V_381 ;
}
static bool F_181 ( T_1 V_21 )
{
bool V_108 = false ;
switch ( V_21 ) {
case V_382 :
case V_383 :
case V_384 :
case V_385 :
V_108 = true ;
break;
}
return V_108 ;
}
static int F_182 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_37 )
{
struct V_90 * V_90 = V_2 -> V_90 ;
switch ( V_21 ) {
case V_382 :
V_90 -> V_5 . V_386 = V_37 ;
if ( ! V_90 -> V_5 . V_386 )
V_90 -> V_5 . V_380 &= ~ V_381 ;
break;
case V_383 : {
T_2 V_91 ;
unsigned long V_387 ;
T_14 V_388 [ 4 ] ;
if ( ! V_90 -> V_5 . V_386 )
break;
if ( ! ( V_37 & V_381 ) ) {
V_90 -> V_5 . V_380 = V_37 ;
break;
}
V_91 = V_37 >> V_389 ;
V_387 = F_183 ( V_90 , V_91 ) ;
if ( F_184 ( V_387 ) )
return 1 ;
V_64 -> V_390 ( V_2 , V_388 ) ;
( ( unsigned char * ) V_388 ) [ 3 ] = 0xc3 ;
if ( F_185 ( ( void V_391 * ) V_387 , V_388 , 4 ) )
return 1 ;
V_90 -> V_5 . V_380 = V_37 ;
F_186 ( V_90 , V_91 ) ;
break;
}
case V_384 : {
T_2 V_91 ;
T_15 V_392 ;
memset ( & V_392 , 0 , sizeof( V_392 ) ) ;
V_90 -> V_5 . V_393 = V_37 ;
if ( ! ( V_37 & V_394 ) )
break;
V_91 = V_37 >> V_395 ;
if ( F_108 ( V_90 , V_37 ,
& V_392 , sizeof( V_392 ) ) )
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
case V_396 : {
T_2 V_91 ;
unsigned long V_387 ;
if ( ! ( V_37 & V_397 ) ) {
V_2 -> V_5 . V_398 = V_37 ;
break;
}
V_91 = V_37 >> V_399 ;
V_387 = F_183 ( V_2 -> V_90 , V_91 ) ;
if ( F_184 ( V_387 ) )
return 1 ;
if ( F_189 ( ( void V_391 * ) V_387 , V_96 ) )
return 1 ;
V_2 -> V_5 . V_398 = V_37 ;
F_186 ( V_2 -> V_90 , V_91 ) ;
break;
}
case V_400 :
return F_190 ( V_2 , V_401 , V_37 ) ;
case V_402 :
return F_190 ( V_2 , V_403 , V_37 ) ;
case V_404 :
return F_190 ( V_2 , V_405 , V_37 ) ;
default:
F_187 ( V_2 , L_7
L_8 , V_21 , V_37 ) ;
return 1 ;
}
return 0 ;
}
static int F_191 ( struct V_1 * V_2 , T_2 V_37 )
{
T_6 V_406 = V_37 & ~ 0x3f ;
if ( V_37 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_407 = V_37 ;
if ( ! ( V_37 & V_408 ) ) {
F_59 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_192 ( V_2 -> V_90 , & V_2 -> V_5 . V_6 . V_37 , V_406 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_409 = ! ( V_37 & V_410 ) ;
F_193 ( V_2 ) ;
return 0 ;
}
static void F_194 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_312 = false ;
}
static void F_195 ( struct V_1 * V_2 )
{
T_2 V_284 ;
if ( ! ( V_2 -> V_5 . V_411 . V_407 & V_412 ) )
return;
V_284 = V_413 -> V_414 . V_415 - V_2 -> V_5 . V_411 . V_416 ;
V_2 -> V_5 . V_411 . V_416 = V_413 -> V_414 . V_415 ;
V_2 -> V_5 . V_411 . V_417 = V_284 ;
}
static void F_196 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_411 . V_407 & V_412 ) )
return;
if ( F_143 ( F_161 ( V_2 -> V_90 , & V_2 -> V_5 . V_411 . V_418 ,
& V_2 -> V_5 . V_411 . V_419 , sizeof( struct V_420 ) ) ) )
return;
V_2 -> V_5 . V_411 . V_419 . V_419 += V_2 -> V_5 . V_411 . V_417 ;
V_2 -> V_5 . V_411 . V_419 . V_219 += 2 ;
V_2 -> V_5 . V_411 . V_417 = 0 ;
F_162 ( V_2 -> V_90 , & V_2 -> V_5 . V_411 . V_418 ,
& V_2 -> V_5 . V_411 . V_419 , sizeof( struct V_420 ) ) ;
}
int F_197 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
bool V_421 = false ;
T_1 V_21 = V_32 -> V_132 ;
T_2 V_37 = V_32 -> V_37 ;
switch ( V_21 ) {
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
break;
case V_428 :
return F_99 ( V_2 , V_37 ) ;
case V_429 :
V_37 &= ~ ( T_2 ) 0x40 ;
V_37 &= ~ ( T_2 ) 0x100 ;
V_37 &= ~ ( T_2 ) 0x8 ;
if ( V_37 != 0 ) {
F_187 ( V_2 , L_9 ,
V_37 ) ;
return 1 ;
}
break;
case V_430 :
if ( V_37 != 0 ) {
F_187 ( V_2 , L_10
L_11 , V_37 ) ;
return 1 ;
}
break;
case V_431 :
if ( ! V_37 ) {
break;
} else if ( V_37 & ~ ( V_432 | V_433 ) ) {
return 1 ;
}
F_187 ( V_2 , L_12 ,
V_239 , V_37 ) ;
break;
case 0x200 ... 0x2ff :
return F_173 ( V_2 , V_21 , V_37 ) ;
case V_434 :
return F_19 ( V_2 , V_32 ) ;
case V_435 ... V_435 + 0x3ff :
return F_198 ( V_2 , V_21 , V_37 ) ;
case V_436 :
F_199 ( V_2 , V_37 ) ;
break;
case V_437 :
if ( F_132 ( V_2 ) ) {
if ( ! V_32 -> V_39 ) {
T_2 V_438 = V_37 - V_2 -> V_5 . V_270 ;
V_64 -> V_439 ( V_2 , V_438 , true ) ;
}
V_2 -> V_5 . V_270 = V_37 ;
}
break;
case V_440 :
V_2 -> V_5 . V_441 = V_37 ;
break;
case V_442 :
case V_443 :
V_2 -> V_90 -> V_5 . V_218 = V_37 ;
F_106 ( V_2 -> V_90 , V_37 ) ;
break;
case V_444 :
case V_445 : {
T_2 V_446 ;
F_194 ( V_2 ) ;
V_2 -> V_5 . time = V_37 ;
F_27 ( V_447 , V_2 ) ;
if ( ! ( V_37 & 1 ) )
break;
V_446 = V_37 & ~ ( V_374 | 1 ) ;
if ( F_192 ( V_2 -> V_90 ,
& V_2 -> V_5 . V_318 , V_37 & ~ 1ULL ,
sizeof( struct V_306 ) ) )
V_2 -> V_5 . V_312 = false ;
else
V_2 -> V_5 . V_312 = true ;
break;
}
case V_448 :
if ( F_191 ( V_2 , V_37 ) )
return 1 ;
break;
case V_449 :
if ( F_143 ( ! F_200 () ) )
return 1 ;
if ( V_37 & V_450 )
return 1 ;
if ( F_192 ( V_2 -> V_90 , & V_2 -> V_5 . V_411 . V_418 ,
V_37 & V_451 ,
sizeof( struct V_420 ) ) )
return 1 ;
V_2 -> V_5 . V_411 . V_407 = V_37 ;
if ( ! ( V_37 & V_412 ) )
break;
V_2 -> V_5 . V_411 . V_416 = V_413 -> V_414 . V_415 ;
F_201 () ;
F_195 ( V_2 ) ;
F_202 () ;
F_27 ( V_452 , V_2 ) ;
break;
case V_453 :
if ( F_203 ( V_2 , V_37 ) )
return 1 ;
break;
case V_361 :
case V_359 :
case V_364 ... V_364 + 4 * V_454 - 1 :
return F_174 ( V_2 , V_21 , V_37 ) ;
case V_455 :
case V_456 :
case V_457 :
case V_458 :
if ( V_37 != 0 )
F_187 ( V_2 , L_13
L_14 , V_21 , V_37 ) ;
break;
case V_459 :
case V_460 :
case V_461 :
case V_462 :
F_187 ( V_2 , L_13
L_14 , V_21 , V_37 ) ;
break;
case V_463 :
case V_464 :
V_421 = true ;
case V_465 :
case V_466 :
if ( F_204 ( V_2 , V_21 ) )
return F_205 ( V_2 , V_32 ) ;
if ( V_421 || V_37 != 0 )
F_187 ( V_2 , L_15
L_14 , V_21 , V_37 ) ;
break;
case V_467 :
break;
case V_382 ... V_468 :
if ( F_181 ( V_21 ) ) {
int V_108 ;
F_206 ( & V_2 -> V_90 -> V_469 ) ;
V_108 = F_182 ( V_2 , V_21 , V_37 ) ;
F_207 ( & V_2 -> V_90 -> V_469 ) ;
return V_108 ;
} else
return F_188 ( V_2 , V_21 , V_37 ) ;
break;
case V_470 :
F_187 ( V_2 , L_16 , V_21 , V_37 ) ;
break;
case V_471 :
if ( ! F_208 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_472 . V_473 = V_37 ;
break;
case V_474 :
if ( ! F_208 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_472 . V_475 = V_37 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_90 -> V_5 . F_175 . V_21 ) )
return F_175 ( V_2 , V_37 ) ;
if ( F_204 ( V_2 , V_21 ) )
return F_205 ( V_2 , V_32 ) ;
if ( ! V_476 ) {
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
int F_209 ( struct V_1 * V_2 , T_1 V_477 , T_2 * V_478 )
{
return V_64 -> V_479 ( V_2 , V_477 , V_478 ) ;
}
static int F_210 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_478 )
{
T_2 * V_345 = ( T_2 * ) & V_2 -> V_5 . V_346 . V_347 ;
if ( ! F_169 ( V_21 ) )
return 1 ;
if ( V_21 == V_342 )
* V_478 = V_2 -> V_5 . V_346 . V_348 +
( V_2 -> V_5 . V_346 . V_349 << 10 ) ;
else if ( V_21 == V_331 )
* V_478 = V_345 [ 0 ] ;
else if ( V_21 == V_332 || V_21 == V_333 )
* V_478 = V_345 [ 1 + V_21 - V_332 ] ;
else if ( V_21 >= V_334 && V_21 <= V_341 )
* V_478 = V_345 [ 3 + V_21 - V_334 ] ;
else if ( V_21 == V_343 )
* V_478 = V_2 -> V_5 . V_350 ;
else {
int V_351 , V_352 ;
T_2 * V_353 ;
V_351 = ( V_21 - 0x200 ) / 2 ;
V_352 = V_21 - 0x200 - 2 * V_351 ;
if ( ! V_352 )
V_353 =
( T_2 * ) & V_2 -> V_5 . V_346 . V_354 [ V_351 ] . V_355 ;
else
V_353 =
( T_2 * ) & V_2 -> V_5 . V_346 . V_354 [ V_351 ] . V_356 ;
* V_478 = * V_353 ;
}
return 0 ;
}
static int F_211 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_478 )
{
T_2 V_37 ;
T_2 V_357 = V_2 -> V_5 . V_357 ;
unsigned V_358 = V_357 & 0xff ;
switch ( V_21 ) {
case V_480 :
case V_481 :
V_37 = 0 ;
break;
case V_482 :
V_37 = V_2 -> V_5 . V_357 ;
break;
case V_361 :
if ( ! ( V_357 & V_362 ) )
return 1 ;
V_37 = V_2 -> V_5 . V_363 ;
break;
case V_359 :
V_37 = V_2 -> V_5 . V_360 ;
break;
default:
if ( V_21 >= V_364 &&
V_21 < V_364 + 4 * V_358 ) {
T_1 V_82 = V_21 - V_364 ;
V_37 = V_2 -> V_5 . V_365 [ V_82 ] ;
break;
}
return 1 ;
}
* V_478 = V_37 ;
return 0 ;
}
static int F_212 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_478 )
{
T_2 V_37 = 0 ;
struct V_90 * V_90 = V_2 -> V_90 ;
switch ( V_21 ) {
case V_382 :
V_37 = V_90 -> V_5 . V_386 ;
break;
case V_383 :
V_37 = V_90 -> V_5 . V_380 ;
break;
case V_385 : {
V_37 =
F_213 ( F_115 () + V_90 -> V_5 . V_224 , 100 ) ;
break;
}
case V_384 :
V_37 = V_90 -> V_5 . V_393 ;
break;
default:
F_187 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_478 = V_37 ;
return 0 ;
}
static int F_214 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_478 )
{
T_2 V_37 = 0 ;
switch ( V_21 ) {
case V_483 : {
int V_108 ;
struct V_1 * V_244 ;
F_152 (r, v, vcpu->kvm) {
if ( V_244 == V_2 ) {
V_37 = V_108 ;
break;
}
}
break;
}
case V_400 :
return F_215 ( V_2 , V_401 , V_478 ) ;
case V_402 :
return F_215 ( V_2 , V_403 , V_478 ) ;
case V_404 :
return F_215 ( V_2 , V_405 , V_478 ) ;
case V_396 :
V_37 = V_2 -> V_5 . V_398 ;
break;
default:
F_187 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_478 = V_37 ;
return 0 ;
}
int F_216 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_478 )
{
T_2 V_37 ;
switch ( V_21 ) {
case V_484 :
case V_485 :
case V_431 :
case V_486 :
case V_487 :
case V_488 :
case V_489 :
case V_490 :
case V_429 :
case V_425 :
case V_455 :
case V_459 :
case V_491 :
case V_422 :
case V_430 :
case V_427 :
V_37 = 0 ;
break;
case V_463 :
case V_464 :
case V_465 :
case V_466 :
if ( F_204 ( V_2 , V_21 ) )
return F_217 ( V_2 , V_21 , V_478 ) ;
V_37 = 0 ;
break;
case V_423 :
V_37 = 0x100000000ULL ;
break;
case V_492 :
V_37 = 0x500 | V_330 ;
break;
case 0x200 ... 0x2ff :
return F_210 ( V_2 , V_21 , V_478 ) ;
case 0xcd :
V_37 = 3 ;
break;
case V_493 :
V_37 = 1 << 24 ;
break;
case V_434 :
V_37 = F_18 ( V_2 ) ;
break;
case V_435 ... V_435 + 0x3ff :
return F_218 ( V_2 , V_21 , V_478 ) ;
break;
case V_436 :
V_37 = F_219 ( V_2 ) ;
break;
case V_437 :
V_37 = ( T_2 ) V_2 -> V_5 . V_270 ;
break;
case V_440 :
V_37 = V_2 -> V_5 . V_441 ;
break;
case V_494 :
V_37 = 1000ULL ;
V_37 |= ( ( ( T_9 ) 4ULL ) << 40 ) ;
break;
case V_428 :
V_37 = V_2 -> V_5 . V_119 ;
break;
case V_443 :
case V_442 :
V_37 = V_2 -> V_90 -> V_5 . V_218 ;
break;
case V_445 :
case V_444 :
V_37 = V_2 -> V_5 . time ;
break;
case V_448 :
V_37 = V_2 -> V_5 . V_6 . V_407 ;
break;
case V_449 :
V_37 = V_2 -> V_5 . V_411 . V_407 ;
break;
case V_453 :
V_37 = V_2 -> V_5 . V_495 . V_407 ;
break;
case V_480 :
case V_481 :
case V_482 :
case V_361 :
case V_359 :
case V_364 ... V_364 + 4 * V_454 - 1 :
return F_211 ( V_2 , V_21 , V_478 ) ;
case V_467 :
V_37 = 0x20000000 ;
break;
case V_382 ... V_468 :
if ( F_181 ( V_21 ) ) {
int V_108 ;
F_206 ( & V_2 -> V_90 -> V_469 ) ;
V_108 = F_212 ( V_2 , V_21 , V_478 ) ;
F_207 ( & V_2 -> V_90 -> V_469 ) ;
return V_108 ;
} else
return F_214 ( V_2 , V_21 , V_478 ) ;
break;
case V_470 :
V_37 = 0xbe702111 ;
break;
case V_471 :
if ( ! F_208 ( V_2 ) )
return 1 ;
V_37 = V_2 -> V_5 . V_472 . V_473 ;
break;
case V_474 :
if ( ! F_208 ( V_2 ) )
return 1 ;
V_37 = V_2 -> V_5 . V_472 . V_475 ;
break;
default:
if ( F_204 ( V_2 , V_21 ) )
return F_217 ( V_2 , V_21 , V_478 ) ;
if ( ! V_476 ) {
F_187 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_187 ( V_2 , L_20 , V_21 ) ;
V_37 = 0 ;
}
break;
}
* V_478 = V_37 ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 , struct V_496 * V_19 ,
struct V_497 * V_498 ,
int (* F_221)( struct V_1 * V_2 ,
unsigned V_132 , T_2 * V_37 ) )
{
int V_3 , V_351 ;
V_351 = F_222 ( & V_2 -> V_90 -> V_499 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_500 ; ++ V_3 )
if ( F_221 ( V_2 , V_498 [ V_3 ] . V_132 , & V_498 [ V_3 ] . V_37 ) )
break;
F_223 ( & V_2 -> V_90 -> V_499 , V_351 ) ;
return V_3 ;
}
static int F_224 ( struct V_1 * V_2 , struct V_496 V_391 * V_501 ,
int (* F_221)( struct V_1 * V_2 ,
unsigned V_132 , T_2 * V_37 ) ,
int V_502 )
{
struct V_496 V_19 ;
struct V_497 * V_498 ;
int V_108 , V_503 ;
unsigned V_504 ;
V_108 = - V_89 ;
if ( F_225 ( & V_19 , V_501 , sizeof V_19 ) )
goto V_102;
V_108 = - V_377 ;
if ( V_19 . V_500 >= V_505 )
goto V_102;
V_504 = sizeof( struct V_497 ) * V_19 . V_500 ;
V_498 = F_176 ( V_501 -> V_498 , V_504 ) ;
if ( F_177 ( V_498 ) ) {
V_108 = F_178 ( V_498 ) ;
goto V_102;
}
V_108 = V_503 = F_220 ( V_2 , & V_19 , V_498 , F_221 ) ;
if ( V_108 < 0 )
goto V_379;
V_108 = - V_89 ;
if ( V_502 && F_226 ( V_501 -> V_498 , V_498 , V_504 ) )
goto V_379;
V_108 = V_503 ;
V_379:
F_179 ( V_498 ) ;
V_102:
return V_108 ;
}
int F_227 ( long V_506 )
{
int V_108 ;
switch ( V_506 ) {
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
#ifdef F_228
case V_542 :
case V_543 :
#endif
V_108 = 1 ;
break;
case V_544 :
V_108 = V_545 ;
break;
case V_546 :
V_108 = ! V_64 -> V_547 () ;
break;
case V_548 :
V_108 = V_549 ;
break;
case V_550 :
V_108 = V_551 ;
break;
case V_552 :
V_108 = V_553 ;
break;
case V_554 :
V_108 = 0 ;
break;
#ifdef F_228
case V_555 :
V_108 = F_229 ( & V_556 ) ;
break;
#endif
case V_557 :
V_108 = V_454 ;
break;
case V_558 :
V_108 = V_559 ;
break;
case V_560 :
V_108 = V_561 ;
break;
case V_562 :
V_108 = F_230 ( V_563 ) ;
break;
default:
V_108 = 0 ;
break;
}
return V_108 ;
}
long F_231 ( struct V_564 * V_565 ,
unsigned int V_566 , unsigned long V_567 )
{
void V_391 * V_568 = ( void V_391 * ) V_567 ;
long V_108 ;
switch ( V_566 ) {
case V_569 : {
struct V_570 V_391 * V_571 = V_568 ;
struct V_570 V_572 ;
unsigned V_503 ;
V_108 = - V_89 ;
if ( F_225 ( & V_572 , V_571 , sizeof V_572 ) )
goto V_102;
V_503 = V_572 . V_500 ;
V_572 . V_500 = V_573 + F_46 ( V_574 ) ;
if ( F_226 ( V_571 , & V_572 , sizeof V_572 ) )
goto V_102;
V_108 = - V_377 ;
if ( V_503 < V_572 . V_500 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_571 -> V_575 , & V_576 ,
V_573 * sizeof( T_1 ) ) )
goto V_102;
if ( F_226 ( V_571 -> V_575 + V_573 ,
& V_574 ,
F_46 ( V_574 ) * sizeof( T_1 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_577 :
case V_578 : {
struct V_579 V_391 * V_580 = V_568 ;
struct V_579 V_581 ;
V_108 = - V_89 ;
if ( F_225 ( & V_581 , V_580 , sizeof V_581 ) )
goto V_102;
V_108 = F_232 ( & V_581 , V_580 -> V_498 ,
V_566 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_580 , & V_581 , sizeof V_581 ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_582 : {
T_2 V_583 ;
V_583 = V_584 ;
V_108 = - V_89 ;
if ( F_226 ( V_568 , & V_583 , sizeof V_583 ) )
goto V_102;
V_108 = 0 ;
break;
}
default:
V_108 = - V_585 ;
}
V_102:
return V_108 ;
}
static void F_233 ( void * V_586 )
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
if ( V_64 -> V_587 () )
F_238 ( V_23 , V_2 -> V_5 . V_588 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_239 ( V_2 -> V_23 ,
F_233 , NULL , 1 ) ;
}
V_64 -> V_589 ( V_2 , V_23 ) ;
if ( F_143 ( V_2 -> V_5 . V_590 ) ) {
F_240 ( V_2 , V_2 -> V_5 . V_590 ) ;
V_2 -> V_5 . V_590 = 0 ;
F_153 ( V_300 , & V_2 -> V_301 ) ;
}
if ( F_143 ( V_2 -> V_23 != V_23 ) || F_131 () ) {
T_12 V_591 = ! V_2 -> V_5 . V_592 ? 0 :
F_159 () - V_2 -> V_5 . V_592 ;
if ( V_591 < 0 )
F_241 ( L_21 ) ;
if ( F_131 () ) {
T_2 V_82 = V_64 -> V_277 ( V_2 ,
V_2 -> V_5 . V_288 ) ;
V_64 -> V_290 ( V_2 , V_82 ) ;
V_2 -> V_5 . V_311 = 1 ;
}
if ( ! V_2 -> V_90 -> V_5 . V_265 || V_2 -> V_23 == - 1 )
F_27 ( V_447 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_242 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_195 ( V_2 ) ;
F_27 ( V_452 , V_2 ) ;
}
void F_243 ( struct V_1 * V_2 )
{
V_64 -> V_593 ( V_2 ) ;
F_244 ( V_2 ) ;
V_2 -> V_5 . V_592 = F_159 () ;
}
static int F_245 ( struct V_1 * V_2 ,
struct V_594 * V_595 )
{
V_64 -> V_596 ( V_2 ) ;
memcpy ( V_595 -> V_597 , V_2 -> V_5 . V_598 -> V_597 , sizeof *V_595 ) ;
return 0 ;
}
static int F_246 ( struct V_1 * V_2 ,
struct V_594 * V_595 )
{
F_247 ( V_2 , V_595 ) ;
F_248 ( V_2 ) ;
return 0 ;
}
static int F_249 ( struct V_1 * V_2 ,
struct V_599 * V_600 )
{
if ( V_600 -> V_600 >= V_601 )
return - V_585 ;
if ( F_82 ( V_2 -> V_90 ) )
return - V_602 ;
F_250 ( V_2 , V_600 -> V_600 , false ) ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
static int F_251 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
return 0 ;
}
static int F_252 ( struct V_1 * V_2 ,
struct V_603 * V_604 )
{
if ( V_604 -> V_273 )
return - V_585 ;
V_2 -> V_5 . V_605 = ! ! V_604 -> V_349 ;
return 0 ;
}
static int F_253 ( struct V_1 * V_2 ,
T_2 V_357 )
{
int V_108 ;
unsigned V_358 = V_357 & 0xff , V_606 ;
V_108 = - V_585 ;
if ( ! V_358 || V_358 >= V_454 )
goto V_102;
if ( V_357 & ~ ( V_584 | 0xff | 0xff0000 ) )
goto V_102;
V_108 = 0 ;
V_2 -> V_5 . V_357 = V_357 ;
if ( V_357 & V_362 )
V_2 -> V_5 . V_363 = ~ ( T_2 ) 0 ;
for ( V_606 = 0 ; V_606 < V_358 ; V_606 ++ )
V_2 -> V_5 . V_365 [ V_606 * 4 ] = ~ ( T_2 ) 0 ;
V_102:
return V_108 ;
}
static int F_254 ( struct V_1 * V_2 ,
struct V_607 * V_608 )
{
T_2 V_357 = V_2 -> V_5 . V_357 ;
unsigned V_358 = V_357 & 0xff ;
T_2 * V_609 = V_2 -> V_5 . V_365 ;
if ( V_608 -> V_606 >= V_358 || ! ( V_608 -> V_475 & V_610 ) )
return - V_585 ;
if ( ( V_608 -> V_475 & V_611 ) && ( V_357 & V_362 ) &&
V_2 -> V_5 . V_363 != ~ ( T_2 ) 0 )
return 0 ;
V_609 += 4 * V_608 -> V_606 ;
if ( ( V_608 -> V_475 & V_611 ) && V_609 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_608 -> V_475 & V_611 ) {
if ( ( V_2 -> V_5 . V_360 & V_612 ) ||
! F_58 ( V_2 , V_613 ) ) {
F_27 ( V_62 , V_2 ) ;
return 0 ;
}
if ( V_609 [ 1 ] & V_610 )
V_608 -> V_475 |= V_614 ;
V_609 [ 2 ] = V_608 -> V_387 ;
V_609 [ 3 ] = V_608 -> V_615 ;
V_2 -> V_5 . V_360 = V_608 -> V_360 ;
V_609 [ 1 ] = V_608 -> V_475 ;
F_28 ( V_2 , V_616 ) ;
} else if ( ! ( V_609 [ 1 ] & V_610 )
|| ! ( V_609 [ 1 ] & V_611 ) ) {
if ( V_609 [ 1 ] & V_610 )
V_608 -> V_475 |= V_614 ;
V_609 [ 2 ] = V_608 -> V_387 ;
V_609 [ 3 ] = V_608 -> V_615 ;
V_609 [ 1 ] = V_608 -> V_475 ;
} else
V_609 [ 1 ] |= V_614 ;
return 0 ;
}
static void F_255 ( struct V_1 * V_2 ,
struct V_617 * V_618 )
{
F_256 ( V_2 ) ;
V_618 -> V_57 . V_619 =
V_2 -> V_5 . V_57 . V_58 &&
! F_257 ( V_2 -> V_5 . V_57 . V_16 ) ;
V_618 -> V_57 . V_16 = V_2 -> V_5 . V_57 . V_16 ;
V_618 -> V_57 . V_60 = V_2 -> V_5 . V_57 . V_60 ;
V_618 -> V_57 . V_620 = 0 ;
V_618 -> V_57 . V_51 = V_2 -> V_5 . V_57 . V_51 ;
V_618 -> V_621 . V_619 =
V_2 -> V_5 . V_621 . V_58 && ! V_2 -> V_5 . V_621 . V_622 ;
V_618 -> V_621 . V_16 = V_2 -> V_5 . V_621 . V_16 ;
V_618 -> V_621 . V_622 = 0 ;
V_618 -> V_621 . V_623 =
V_64 -> V_624 ( V_2 ,
V_625 | V_626 ) ;
V_618 -> V_627 . V_619 = V_2 -> V_5 . V_628 ;
V_618 -> V_627 . V_58 = V_2 -> V_5 . V_629 != 0 ;
V_618 -> V_627 . V_630 = V_64 -> V_631 ( V_2 ) ;
V_618 -> V_627 . V_620 = 0 ;
V_618 -> V_632 = 0 ;
V_618 -> V_273 = ( V_633
| V_634 ) ;
memset ( & V_618 -> V_635 , 0 , sizeof( V_618 -> V_635 ) ) ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_617 * V_618 )
{
if ( V_618 -> V_273 & ~ ( V_633
| V_636
| V_634 ) )
return - V_585 ;
F_256 ( V_2 ) ;
V_2 -> V_5 . V_57 . V_58 = V_618 -> V_57 . V_619 ;
V_2 -> V_5 . V_57 . V_16 = V_618 -> V_57 . V_16 ;
V_2 -> V_5 . V_57 . V_60 = V_618 -> V_57 . V_60 ;
V_2 -> V_5 . V_57 . V_51 = V_618 -> V_57 . V_51 ;
V_2 -> V_5 . V_621 . V_58 = V_618 -> V_621 . V_619 ;
V_2 -> V_5 . V_621 . V_16 = V_618 -> V_621 . V_16 ;
V_2 -> V_5 . V_621 . V_622 = V_618 -> V_621 . V_622 ;
if ( V_618 -> V_273 & V_634 )
V_64 -> V_637 ( V_2 ,
V_618 -> V_621 . V_623 ) ;
V_2 -> V_5 . V_628 = V_618 -> V_627 . V_619 ;
if ( V_618 -> V_273 & V_633 )
V_2 -> V_5 . V_629 = V_618 -> V_627 . V_58 ;
V_64 -> V_638 ( V_2 , V_618 -> V_627 . V_630 ) ;
if ( V_618 -> V_273 & V_636 &&
F_259 ( V_2 ) )
V_2 -> V_5 . V_598 -> V_632 = V_618 -> V_632 ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
static void F_260 ( struct V_1 * V_2 ,
struct V_639 * V_640 )
{
unsigned long V_173 ;
memcpy ( V_640 -> V_174 , V_2 -> V_5 . V_174 , sizeof( V_2 -> V_5 . V_174 ) ) ;
F_90 ( V_2 , 6 , & V_173 ) ;
V_640 -> V_165 = V_173 ;
V_640 -> V_166 = V_2 -> V_5 . V_166 ;
V_640 -> V_273 = 0 ;
memset ( & V_640 -> V_635 , 0 , sizeof( V_640 -> V_635 ) ) ;
}
static int F_261 ( struct V_1 * V_2 ,
struct V_639 * V_640 )
{
if ( V_640 -> V_273 )
return - V_585 ;
memcpy ( V_2 -> V_5 . V_174 , V_640 -> V_174 , sizeof( V_2 -> V_5 . V_174 ) ) ;
V_2 -> V_5 . V_165 = V_640 -> V_165 ;
F_86 ( V_2 ) ;
V_2 -> V_5 . V_166 = V_640 -> V_166 ;
F_87 ( V_2 ) ;
return 0 ;
}
static void F_262 ( struct V_1 * V_2 ,
struct V_641 * V_642 )
{
if ( V_559 ) {
memcpy ( V_642 -> V_643 ,
& V_2 -> V_5 . V_644 . V_645 -> V_646 ,
V_2 -> V_5 . V_647 ) ;
* ( T_2 * ) & V_642 -> V_643 [ V_648 / sizeof( T_1 ) ] &=
V_2 -> V_5 . V_139 | V_649 ;
} else {
memcpy ( V_642 -> V_643 ,
& V_2 -> V_5 . V_644 . V_645 -> V_650 ,
sizeof( struct V_651 ) ) ;
* ( T_2 * ) & V_642 -> V_643 [ V_648 / sizeof( T_1 ) ] =
V_649 ;
}
}
static int F_263 ( struct V_1 * V_2 ,
struct V_641 * V_642 )
{
T_2 V_652 =
* ( T_2 * ) & V_642 -> V_643 [ V_648 / sizeof( T_1 ) ] ;
if ( V_559 ) {
if ( V_652 & ~ F_264 () )
return - V_585 ;
memcpy ( & V_2 -> V_5 . V_644 . V_645 -> V_646 ,
V_642 -> V_643 , V_2 -> V_5 . V_647 ) ;
} else {
if ( V_652 & ~ V_649 )
return - V_585 ;
memcpy ( & V_2 -> V_5 . V_644 . V_645 -> V_650 ,
V_642 -> V_643 , sizeof( struct V_651 ) ) ;
}
return 0 ;
}
static void F_265 ( struct V_1 * V_2 ,
struct V_653 * V_654 )
{
if ( ! V_559 ) {
V_654 -> V_655 = 0 ;
return;
}
V_654 -> V_655 = 1 ;
V_654 -> V_273 = 0 ;
V_654 -> V_656 [ 0 ] . V_133 = V_129 ;
V_654 -> V_656 [ 0 ] . V_22 = V_2 -> V_5 . V_130 ;
}
static int F_266 ( struct V_1 * V_2 ,
struct V_653 * V_654 )
{
int V_3 , V_108 = 0 ;
if ( ! V_559 )
return - V_585 ;
if ( V_654 -> V_655 > V_657 || V_654 -> V_273 )
return - V_585 ;
for ( V_3 = 0 ; V_3 < V_654 -> V_655 ; V_3 ++ )
if ( V_654 -> V_656 [ V_3 ] . V_133 == V_129 ) {
V_108 = F_66 ( V_2 , V_129 ,
V_654 -> V_656 [ V_3 ] . V_22 ) ;
break;
}
if ( V_108 )
V_108 = - V_585 ;
return V_108 ;
}
static int F_267 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_312 )
return - V_585 ;
V_2 -> V_5 . V_320 = true ;
F_27 ( V_300 , V_2 ) ;
return 0 ;
}
long F_268 ( struct V_564 * V_565 ,
unsigned int V_566 , unsigned long V_567 )
{
struct V_1 * V_2 = V_565 -> V_658 ;
void V_391 * V_568 = ( void V_391 * ) V_567 ;
int V_108 ;
union {
struct V_594 * V_659 ;
struct V_641 * V_646 ;
struct V_653 * V_656 ;
void * V_660 ;
} V_661 ;
V_661 . V_660 = NULL ;
switch ( V_566 ) {
case V_662 : {
V_108 = - V_585 ;
if ( ! V_2 -> V_5 . V_598 )
goto V_102;
V_661 . V_659 = F_269 ( sizeof( struct V_594 ) , V_663 ) ;
V_108 = - V_378 ;
if ( ! V_661 . V_659 )
goto V_102;
V_108 = F_245 ( V_2 , V_661 . V_659 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_568 , V_661 . V_659 , sizeof( struct V_594 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_664 : {
V_108 = - V_585 ;
if ( ! V_2 -> V_5 . V_598 )
goto V_102;
V_661 . V_659 = F_176 ( V_568 , sizeof( * V_661 . V_659 ) ) ;
if ( F_177 ( V_661 . V_659 ) )
return F_178 ( V_661 . V_659 ) ;
V_108 = F_246 ( V_2 , V_661 . V_659 ) ;
break;
}
case V_665 : {
struct V_599 V_600 ;
V_108 = - V_89 ;
if ( F_225 ( & V_600 , V_568 , sizeof V_600 ) )
goto V_102;
V_108 = F_249 ( V_2 , & V_600 ) ;
break;
}
case V_666 : {
V_108 = F_251 ( V_2 ) ;
break;
}
case V_667 : {
struct V_668 V_391 * V_580 = V_568 ;
struct V_668 V_581 ;
V_108 = - V_89 ;
if ( F_225 ( & V_581 , V_580 , sizeof V_581 ) )
goto V_102;
V_108 = F_270 ( V_2 , & V_581 , V_580 -> V_498 ) ;
break;
}
case V_669 : {
struct V_579 V_391 * V_580 = V_568 ;
struct V_579 V_581 ;
V_108 = - V_89 ;
if ( F_225 ( & V_581 , V_580 , sizeof V_581 ) )
goto V_102;
V_108 = F_271 ( V_2 , & V_581 ,
V_580 -> V_498 ) ;
break;
}
case V_670 : {
struct V_579 V_391 * V_580 = V_568 ;
struct V_579 V_581 ;
V_108 = - V_89 ;
if ( F_225 ( & V_581 , V_580 , sizeof V_581 ) )
goto V_102;
V_108 = F_272 ( V_2 , & V_581 ,
V_580 -> V_498 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_580 , & V_581 , sizeof V_581 ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_671 :
V_108 = F_224 ( V_2 , V_568 , F_209 , 1 ) ;
break;
case V_672 :
V_108 = F_224 ( V_2 , V_568 , F_102 , 0 ) ;
break;
case V_673 : {
struct V_603 V_604 ;
V_108 = - V_89 ;
if ( F_225 ( & V_604 , V_568 , sizeof V_604 ) )
goto V_102;
V_108 = F_252 ( V_2 , & V_604 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_568 , & V_604 , sizeof V_604 ) )
goto V_102;
V_108 = 0 ;
break;
} ;
case V_674 : {
struct V_675 V_676 ;
V_108 = - V_585 ;
if ( ! F_82 ( V_2 -> V_90 ) )
goto V_102;
V_108 = - V_89 ;
if ( F_225 ( & V_676 , V_568 , sizeof V_676 ) )
goto V_102;
V_108 = F_273 ( V_2 , V_676 . V_677 ) ;
break;
}
case V_678 : {
T_2 V_357 ;
V_108 = - V_89 ;
if ( F_225 ( & V_357 , V_568 , sizeof V_357 ) )
goto V_102;
V_108 = F_253 ( V_2 , V_357 ) ;
break;
}
case V_679 : {
struct V_607 V_608 ;
V_108 = - V_89 ;
if ( F_225 ( & V_608 , V_568 , sizeof V_608 ) )
goto V_102;
V_108 = F_254 ( V_2 , & V_608 ) ;
break;
}
case V_680 : {
struct V_617 V_618 ;
F_255 ( V_2 , & V_618 ) ;
V_108 = - V_89 ;
if ( F_226 ( V_568 , & V_618 , sizeof( struct V_617 ) ) )
break;
V_108 = 0 ;
break;
}
case V_681 : {
struct V_617 V_618 ;
V_108 = - V_89 ;
if ( F_225 ( & V_618 , V_568 , sizeof( struct V_617 ) ) )
break;
V_108 = F_258 ( V_2 , & V_618 ) ;
break;
}
case V_682 : {
struct V_639 V_640 ;
F_260 ( V_2 , & V_640 ) ;
V_108 = - V_89 ;
if ( F_226 ( V_568 , & V_640 ,
sizeof( struct V_639 ) ) )
break;
V_108 = 0 ;
break;
}
case V_683 : {
struct V_639 V_640 ;
V_108 = - V_89 ;
if ( F_225 ( & V_640 , V_568 ,
sizeof( struct V_639 ) ) )
break;
V_108 = F_261 ( V_2 , & V_640 ) ;
break;
}
case V_684 : {
V_661 . V_646 = F_269 ( sizeof( struct V_641 ) , V_663 ) ;
V_108 = - V_378 ;
if ( ! V_661 . V_646 )
break;
F_262 ( V_2 , V_661 . V_646 ) ;
V_108 = - V_89 ;
if ( F_226 ( V_568 , V_661 . V_646 , sizeof( struct V_641 ) ) )
break;
V_108 = 0 ;
break;
}
case V_685 : {
V_661 . V_646 = F_176 ( V_568 , sizeof( * V_661 . V_646 ) ) ;
if ( F_177 ( V_661 . V_646 ) )
return F_178 ( V_661 . V_646 ) ;
V_108 = F_263 ( V_2 , V_661 . V_646 ) ;
break;
}
case V_686 : {
V_661 . V_656 = F_269 ( sizeof( struct V_653 ) , V_663 ) ;
V_108 = - V_378 ;
if ( ! V_661 . V_656 )
break;
F_265 ( V_2 , V_661 . V_656 ) ;
V_108 = - V_89 ;
if ( F_226 ( V_568 , V_661 . V_656 ,
sizeof( struct V_653 ) ) )
break;
V_108 = 0 ;
break;
}
case V_687 : {
V_661 . V_656 = F_176 ( V_568 , sizeof( * V_661 . V_656 ) ) ;
if ( F_177 ( V_661 . V_656 ) )
return F_178 ( V_661 . V_656 ) ;
V_108 = F_266 ( V_2 , V_661 . V_656 ) ;
break;
}
case V_688 : {
T_1 V_689 ;
V_108 = - V_585 ;
V_689 = ( T_1 ) V_567 ;
if ( V_689 >= V_690 )
goto V_102;
if ( V_689 == 0 )
V_689 = V_250 ;
F_123 ( V_2 , V_689 ) ;
V_108 = 0 ;
goto V_102;
}
case V_691 : {
V_108 = V_2 -> V_5 . V_249 ;
goto V_102;
}
case V_692 : {
V_108 = F_267 ( V_2 ) ;
goto V_102;
}
default:
V_108 = - V_585 ;
}
V_102:
F_179 ( V_661 . V_660 ) ;
return V_108 ;
}
int F_274 ( struct V_1 * V_2 , struct V_693 * V_694 )
{
return V_695 ;
}
static int F_275 ( struct V_90 * V_90 , unsigned long V_387 )
{
int V_97 ;
if ( V_387 > ( unsigned int ) ( - 3 * V_96 ) )
return - V_585 ;
V_97 = V_64 -> V_696 ( V_90 , V_387 ) ;
return V_97 ;
}
static int F_276 ( struct V_90 * V_90 ,
T_2 V_697 )
{
V_90 -> V_5 . V_698 = V_697 ;
return 0 ;
}
static int F_277 ( struct V_90 * V_90 ,
T_1 V_699 )
{
if ( V_699 < V_700 )
return - V_585 ;
F_206 ( & V_90 -> V_701 ) ;
F_278 ( V_90 , V_699 ) ;
V_90 -> V_5 . V_702 = V_699 ;
F_207 ( & V_90 -> V_701 ) ;
return 0 ;
}
static int F_279 ( struct V_90 * V_90 )
{
return V_90 -> V_5 . V_703 ;
}
static int F_280 ( struct V_90 * V_90 , struct V_704 * V_705 )
{
int V_108 ;
V_108 = 0 ;
switch ( V_705 -> V_706 ) {
case V_707 :
memcpy ( & V_705 -> V_705 . V_708 ,
& F_281 ( V_90 ) -> V_709 [ 0 ] ,
sizeof( struct V_710 ) ) ;
break;
case V_711 :
memcpy ( & V_705 -> V_705 . V_708 ,
& F_281 ( V_90 ) -> V_709 [ 1 ] ,
sizeof( struct V_710 ) ) ;
break;
case V_712 :
V_108 = F_282 ( V_90 , & V_705 -> V_705 . V_713 ) ;
break;
default:
V_108 = - V_585 ;
break;
}
return V_108 ;
}
static int F_283 ( struct V_90 * V_90 , struct V_704 * V_705 )
{
int V_108 ;
V_108 = 0 ;
switch ( V_705 -> V_706 ) {
case V_707 :
F_134 ( & F_281 ( V_90 ) -> V_469 ) ;
memcpy ( & F_281 ( V_90 ) -> V_709 [ 0 ] ,
& V_705 -> V_705 . V_708 ,
sizeof( struct V_710 ) ) ;
F_135 ( & F_281 ( V_90 ) -> V_469 ) ;
break;
case V_711 :
F_134 ( & F_281 ( V_90 ) -> V_469 ) ;
memcpy ( & F_281 ( V_90 ) -> V_709 [ 1 ] ,
& V_705 -> V_705 . V_708 ,
sizeof( struct V_710 ) ) ;
F_135 ( & F_281 ( V_90 ) -> V_469 ) ;
break;
case V_712 :
V_108 = F_284 ( V_90 , & V_705 -> V_705 . V_713 ) ;
break;
default:
V_108 = - V_585 ;
break;
}
F_285 ( F_281 ( V_90 ) ) ;
return V_108 ;
}
static int F_286 ( struct V_90 * V_90 , struct V_714 * V_715 )
{
int V_108 = 0 ;
F_206 ( & V_90 -> V_5 . V_716 -> V_717 . V_469 ) ;
memcpy ( V_715 , & V_90 -> V_5 . V_716 -> V_717 , sizeof( struct V_714 ) ) ;
F_207 ( & V_90 -> V_5 . V_716 -> V_717 . V_469 ) ;
return V_108 ;
}
static int F_287 ( struct V_90 * V_90 , struct V_714 * V_715 )
{
int V_108 = 0 ;
F_206 ( & V_90 -> V_5 . V_716 -> V_717 . V_469 ) ;
memcpy ( & V_90 -> V_5 . V_716 -> V_717 , V_715 , sizeof( struct V_714 ) ) ;
F_288 ( V_90 , 0 , V_715 -> V_718 [ 0 ] . V_719 , 0 ) ;
F_207 ( & V_90 -> V_5 . V_716 -> V_717 . V_469 ) ;
return V_108 ;
}
static int F_289 ( struct V_90 * V_90 , struct V_720 * V_715 )
{
int V_108 = 0 ;
F_206 ( & V_90 -> V_5 . V_716 -> V_717 . V_469 ) ;
memcpy ( V_715 -> V_718 , & V_90 -> V_5 . V_716 -> V_717 . V_718 ,
sizeof( V_715 -> V_718 ) ) ;
V_715 -> V_273 = V_90 -> V_5 . V_716 -> V_717 . V_273 ;
F_207 ( & V_90 -> V_5 . V_716 -> V_717 . V_469 ) ;
memset ( & V_715 -> V_635 , 0 , sizeof( V_715 -> V_635 ) ) ;
return V_108 ;
}
static int F_290 ( struct V_90 * V_90 , struct V_720 * V_715 )
{
int V_108 = 0 , V_721 = 0 ;
T_1 V_722 , V_723 ;
F_206 ( & V_90 -> V_5 . V_716 -> V_717 . V_469 ) ;
V_722 = V_90 -> V_5 . V_716 -> V_717 . V_273 & V_724 ;
V_723 = V_715 -> V_273 & V_724 ;
if ( ! V_722 && V_723 )
V_721 = 1 ;
memcpy ( & V_90 -> V_5 . V_716 -> V_717 . V_718 , & V_715 -> V_718 ,
sizeof( V_90 -> V_5 . V_716 -> V_717 . V_718 ) ) ;
V_90 -> V_5 . V_716 -> V_717 . V_273 = V_715 -> V_273 ;
F_288 ( V_90 , 0 , V_90 -> V_5 . V_716 -> V_717 . V_718 [ 0 ] . V_719 , V_721 ) ;
F_207 ( & V_90 -> V_5 . V_716 -> V_717 . V_469 ) ;
return V_108 ;
}
static int F_291 ( struct V_90 * V_90 ,
struct V_725 * V_726 )
{
if ( ! V_90 -> V_5 . V_716 )
return - V_602 ;
F_206 ( & V_90 -> V_5 . V_716 -> V_717 . V_469 ) ;
V_90 -> V_5 . V_716 -> V_717 . V_52 = V_726 -> V_727 ;
F_207 ( & V_90 -> V_5 . V_716 -> V_717 . V_469 ) ;
return 0 ;
}
int F_292 ( struct V_90 * V_90 , struct V_728 * log )
{
int V_108 ;
struct V_729 * V_730 ;
unsigned long V_503 , V_3 ;
unsigned long * V_731 ;
unsigned long * V_732 ;
bool V_733 = false ;
F_206 ( & V_90 -> V_701 ) ;
V_108 = - V_585 ;
if ( log -> V_10 >= V_553 )
goto V_102;
V_730 = F_293 ( V_90 -> V_734 , log -> V_10 ) ;
V_731 = V_730 -> V_731 ;
V_108 = - V_735 ;
if ( ! V_731 )
goto V_102;
V_503 = F_294 ( V_730 ) ;
V_732 = V_731 + V_503 / sizeof( long ) ;
memset ( V_732 , 0 , V_503 ) ;
F_134 ( & V_90 -> V_736 ) ;
for ( V_3 = 0 ; V_3 < V_503 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_27 ;
T_5 V_82 ;
if ( ! V_731 [ V_3 ] )
continue;
V_733 = true ;
V_27 = F_295 ( & V_731 [ V_3 ] , 0 ) ;
V_732 [ V_3 ] = V_27 ;
V_82 = V_3 * V_737 ;
F_296 ( V_90 , V_730 , V_82 , V_27 ) ;
}
if ( V_733 )
F_297 ( V_90 ) ;
F_135 ( & V_90 -> V_736 ) ;
V_108 = - V_89 ;
if ( F_226 ( log -> V_731 , V_732 , V_503 ) )
goto V_102;
V_108 = 0 ;
V_102:
F_207 ( & V_90 -> V_701 ) ;
return V_108 ;
}
int F_298 ( struct V_90 * V_90 , struct V_738 * V_739 ,
bool V_740 )
{
if ( ! F_82 ( V_90 ) )
return - V_602 ;
V_739 -> V_475 = F_299 ( V_90 , V_741 ,
V_739 -> V_600 , V_739 -> V_742 ,
V_740 ) ;
return 0 ;
}
long F_300 ( struct V_564 * V_565 ,
unsigned int V_566 , unsigned long V_567 )
{
struct V_90 * V_90 = V_565 -> V_658 ;
void V_391 * V_568 = ( void V_391 * ) V_567 ;
int V_108 = - V_743 ;
union {
struct V_714 V_715 ;
struct V_720 V_744 ;
struct V_745 V_746 ;
} V_661 ;
switch ( V_566 ) {
case V_747 :
V_108 = F_275 ( V_90 , V_567 ) ;
break;
case V_748 : {
T_2 V_697 ;
V_108 = - V_89 ;
if ( F_225 ( & V_697 , V_568 , sizeof V_697 ) )
goto V_102;
V_108 = F_276 ( V_90 , V_697 ) ;
break;
}
case V_749 :
V_108 = F_277 ( V_90 , V_567 ) ;
break;
case V_750 :
V_108 = F_279 ( V_90 ) ;
break;
case V_751 : {
struct V_752 * V_753 ;
F_206 ( & V_90 -> V_469 ) ;
V_108 = - V_754 ;
if ( V_90 -> V_5 . V_753 )
goto V_755;
V_108 = - V_585 ;
if ( F_126 ( & V_90 -> V_263 ) )
goto V_755;
V_108 = - V_378 ;
V_753 = F_301 ( V_90 ) ;
if ( V_753 ) {
V_108 = F_302 ( V_90 ) ;
if ( V_108 ) {
F_206 ( & V_90 -> V_701 ) ;
F_303 ( V_90 , V_756 ,
& V_753 -> V_757 ) ;
F_303 ( V_90 , V_756 ,
& V_753 -> V_758 ) ;
F_303 ( V_90 , V_756 ,
& V_753 -> V_759 ) ;
F_207 ( & V_90 -> V_701 ) ;
F_179 ( V_753 ) ;
goto V_755;
}
} else
goto V_755;
F_13 () ;
V_90 -> V_5 . V_753 = V_753 ;
F_13 () ;
V_108 = F_304 ( V_90 ) ;
if ( V_108 ) {
F_206 ( & V_90 -> V_701 ) ;
F_206 ( & V_90 -> V_760 ) ;
F_305 ( V_90 ) ;
F_306 ( V_90 ) ;
F_207 ( & V_90 -> V_760 ) ;
F_207 ( & V_90 -> V_701 ) ;
}
V_755:
F_207 ( & V_90 -> V_469 ) ;
break;
}
case V_761 :
V_661 . V_746 . V_273 = V_762 ;
goto V_763;
case V_764 :
V_108 = - V_89 ;
if ( F_225 ( & V_661 . V_746 , V_568 ,
sizeof( struct V_745 ) ) )
goto V_102;
V_763:
F_206 ( & V_90 -> V_701 ) ;
V_108 = - V_754 ;
if ( V_90 -> V_5 . V_716 )
goto V_765;
V_108 = - V_378 ;
V_90 -> V_5 . V_716 = F_307 ( V_90 , V_661 . V_746 . V_273 ) ;
if ( V_90 -> V_5 . V_716 )
V_108 = 0 ;
V_765:
F_207 ( & V_90 -> V_701 ) ;
break;
case V_766 : {
struct V_704 * V_705 ;
V_705 = F_176 ( V_568 , sizeof( * V_705 ) ) ;
if ( F_177 ( V_705 ) ) {
V_108 = F_178 ( V_705 ) ;
goto V_102;
}
V_108 = - V_602 ;
if ( ! F_82 ( V_90 ) )
goto V_767;
V_108 = F_280 ( V_90 , V_705 ) ;
if ( V_108 )
goto V_767;
V_108 = - V_89 ;
if ( F_226 ( V_568 , V_705 , sizeof *V_705 ) )
goto V_767;
V_108 = 0 ;
V_767:
F_179 ( V_705 ) ;
break;
}
case V_768 : {
struct V_704 * V_705 ;
V_705 = F_176 ( V_568 , sizeof( * V_705 ) ) ;
if ( F_177 ( V_705 ) ) {
V_108 = F_178 ( V_705 ) ;
goto V_102;
}
V_108 = - V_602 ;
if ( ! F_82 ( V_90 ) )
goto V_769;
V_108 = F_283 ( V_90 , V_705 ) ;
if ( V_108 )
goto V_769;
V_108 = 0 ;
V_769:
F_179 ( V_705 ) ;
break;
}
case V_770 : {
V_108 = - V_89 ;
if ( F_225 ( & V_661 . V_715 , V_568 , sizeof( struct V_714 ) ) )
goto V_102;
V_108 = - V_602 ;
if ( ! V_90 -> V_5 . V_716 )
goto V_102;
V_108 = F_286 ( V_90 , & V_661 . V_715 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_568 , & V_661 . V_715 , sizeof( struct V_714 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_771 : {
V_108 = - V_89 ;
if ( F_225 ( & V_661 . V_715 , V_568 , sizeof V_661 . V_715 ) )
goto V_102;
V_108 = - V_602 ;
if ( ! V_90 -> V_5 . V_716 )
goto V_102;
V_108 = F_287 ( V_90 , & V_661 . V_715 ) ;
break;
}
case V_772 : {
V_108 = - V_602 ;
if ( ! V_90 -> V_5 . V_716 )
goto V_102;
V_108 = F_289 ( V_90 , & V_661 . V_744 ) ;
if ( V_108 )
goto V_102;
V_108 = - V_89 ;
if ( F_226 ( V_568 , & V_661 . V_744 , sizeof( V_661 . V_744 ) ) )
goto V_102;
V_108 = 0 ;
break;
}
case V_773 : {
V_108 = - V_89 ;
if ( F_225 ( & V_661 . V_744 , V_568 , sizeof( V_661 . V_744 ) ) )
goto V_102;
V_108 = - V_602 ;
if ( ! V_90 -> V_5 . V_716 )
goto V_102;
V_108 = F_290 ( V_90 , & V_661 . V_744 ) ;
break;
}
case V_774 : {
struct V_725 V_726 ;
V_108 = - V_89 ;
if ( F_225 ( & V_726 , V_568 , sizeof( V_726 ) ) )
goto V_102;
V_108 = F_291 ( V_90 , & V_726 ) ;
break;
}
case V_775 : {
V_108 = - V_89 ;
if ( F_225 ( & V_90 -> V_5 . F_175 , V_568 ,
sizeof( struct V_776 ) ) )
goto V_102;
V_108 = - V_585 ;
if ( V_90 -> V_5 . F_175 . V_273 )
goto V_102;
V_108 = 0 ;
break;
}
case V_777 : {
struct V_778 V_779 ;
T_2 V_780 ;
T_12 V_284 ;
V_108 = - V_89 ;
if ( F_225 ( & V_779 , V_568 , sizeof( V_779 ) ) )
goto V_102;
V_108 = - V_585 ;
if ( V_779 . V_273 )
goto V_102;
V_108 = 0 ;
F_308 () ;
V_780 = F_115 () ;
V_284 = V_779 . clock - V_780 ;
F_309 () ;
V_90 -> V_5 . V_224 = V_284 ;
F_150 ( V_90 ) ;
break;
}
case V_781 : {
struct V_778 V_779 ;
T_2 V_780 ;
F_308 () ;
V_780 = F_115 () ;
V_779 . clock = V_90 -> V_5 . V_224 + V_780 ;
F_309 () ;
V_779 . V_273 = 0 ;
memset ( & V_779 . V_620 , 0 , sizeof( V_779 . V_620 ) ) ;
V_108 = - V_89 ;
if ( F_226 ( V_568 , & V_779 , sizeof( V_779 ) ) )
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
static void F_310 ( void )
{
T_1 V_782 [ 2 ] ;
unsigned V_3 , V_783 ;
for ( V_3 = V_783 = V_784 ; V_3 < F_46 ( V_576 ) ; V_3 ++ ) {
if ( F_311 ( V_576 [ V_3 ] , & V_782 [ 0 ] , & V_782 [ 1 ] ) < 0 )
continue;
switch ( V_576 [ V_3 ] ) {
case V_785 :
if ( ! V_64 -> V_786 () )
continue;
break;
default:
break;
}
if ( V_783 < V_3 )
V_576 [ V_783 ] = V_576 [ V_3 ] ;
V_783 ++ ;
}
V_573 = V_783 ;
}
static int F_312 ( struct V_1 * V_2 , T_6 V_387 , int V_83 ,
const void * V_244 )
{
int V_787 = 0 ;
int V_503 ;
do {
V_503 = F_313 ( V_83 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_598 &&
! F_314 ( & V_2 -> V_5 . V_598 -> V_788 , V_387 , V_503 , V_244 ) )
&& F_315 ( V_2 -> V_90 , V_789 , V_387 , V_503 , V_244 ) )
break;
V_787 += V_503 ;
V_387 += V_503 ;
V_83 -= V_503 ;
V_244 += V_503 ;
} while ( V_83 );
return V_787 ;
}
static int F_316 ( struct V_1 * V_2 , T_6 V_387 , int V_83 , void * V_244 )
{
int V_787 = 0 ;
int V_503 ;
do {
V_503 = F_313 ( V_83 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_598 &&
! F_317 ( & V_2 -> V_5 . V_598 -> V_788 , V_387 , V_503 , V_244 ) )
&& F_318 ( V_2 -> V_90 , V_789 , V_387 , V_503 , V_244 ) )
break;
F_319 ( V_790 , V_503 , V_387 , * ( T_2 * ) V_244 ) ;
V_787 += V_503 ;
V_387 += V_503 ;
V_83 -= V_503 ;
V_244 += V_503 ;
} while ( V_83 );
return V_787 ;
}
static void F_320 ( struct V_1 * V_2 ,
struct V_791 * V_792 , int V_793 )
{
V_64 -> V_794 ( V_2 , V_792 , V_793 ) ;
}
void F_321 ( struct V_1 * V_2 ,
struct V_791 * V_792 , int V_793 )
{
V_64 -> V_795 ( V_2 , V_792 , V_793 ) ;
}
T_6 F_322 ( struct V_1 * V_2 , T_6 V_406 , T_1 V_84 )
{
T_6 V_796 ;
struct V_66 V_57 ;
F_323 ( ! F_35 ( V_2 ) ) ;
V_84 |= V_100 ;
V_796 = V_2 -> V_5 . V_75 . V_797 ( V_2 , V_406 , V_84 , & V_57 ) ;
return V_796 ;
}
T_6 F_324 ( struct V_1 * V_2 , T_16 V_798 ,
struct V_66 * V_57 )
{
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
return V_2 -> V_5 . V_92 -> V_797 ( V_2 , V_798 , V_84 , V_57 ) ;
}
T_6 F_325 ( struct V_1 * V_2 , T_16 V_798 ,
struct V_66 * V_57 )
{
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
V_84 |= V_799 ;
return V_2 -> V_5 . V_92 -> V_797 ( V_2 , V_798 , V_84 , V_57 ) ;
}
T_6 F_326 ( struct V_1 * V_2 , T_16 V_798 ,
struct V_66 * V_57 )
{
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
V_84 |= V_101 ;
return V_2 -> V_5 . V_92 -> V_797 ( V_2 , V_798 , V_84 , V_57 ) ;
}
T_6 F_327 ( struct V_1 * V_2 , T_16 V_798 ,
struct V_66 * V_57 )
{
return V_2 -> V_5 . V_92 -> V_797 ( V_2 , V_798 , 0 , V_57 ) ;
}
static int F_328 ( T_16 V_387 , void * V_173 , unsigned int V_800 ,
struct V_1 * V_2 , T_1 V_84 ,
struct V_66 * V_57 )
{
void * V_37 = V_173 ;
int V_108 = V_801 ;
while ( V_800 ) {
T_6 V_406 = V_2 -> V_5 . V_92 -> V_797 ( V_2 , V_387 , V_84 ,
V_57 ) ;
unsigned V_82 = V_387 & ( V_96 - 1 ) ;
unsigned V_802 = F_313 ( V_800 , ( unsigned ) V_96 - V_82 ) ;
int V_97 ;
if ( V_406 == V_88 )
return V_803 ;
V_97 = F_107 ( V_2 -> V_90 , V_406 , V_37 , V_802 ) ;
if ( V_97 < 0 ) {
V_108 = V_804 ;
goto V_102;
}
V_800 -= V_802 ;
V_37 += V_802 ;
V_387 += V_802 ;
}
V_102:
return V_108 ;
}
static int F_329 ( struct V_805 * V_806 ,
T_16 V_387 , void * V_173 , unsigned int V_800 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
return F_328 ( V_387 , V_173 , V_800 , V_2 ,
V_84 | V_799 ,
V_57 ) ;
}
int F_331 ( struct V_805 * V_806 ,
T_16 V_387 , void * V_173 , unsigned int V_800 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
T_1 V_84 = ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 ;
return F_328 ( V_387 , V_173 , V_800 , V_2 , V_84 ,
V_57 ) ;
}
static int F_332 ( struct V_805 * V_806 ,
T_16 V_387 , void * V_173 , unsigned int V_800 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
return F_328 ( V_387 , V_173 , V_800 , V_2 , 0 , V_57 ) ;
}
int F_333 ( struct V_805 * V_806 ,
T_16 V_387 , void * V_173 ,
unsigned int V_800 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
void * V_37 = V_173 ;
int V_108 = V_801 ;
while ( V_800 ) {
T_6 V_406 = V_2 -> V_5 . V_92 -> V_797 ( V_2 , V_387 ,
V_101 ,
V_57 ) ;
unsigned V_82 = V_387 & ( V_96 - 1 ) ;
unsigned V_807 = F_313 ( V_800 , ( unsigned ) V_96 - V_82 ) ;
int V_97 ;
if ( V_406 == V_88 )
return V_803 ;
V_97 = F_108 ( V_2 -> V_90 , V_406 , V_37 , V_807 ) ;
if ( V_97 < 0 ) {
V_108 = V_804 ;
goto V_102;
}
V_800 -= V_807 ;
V_37 += V_807 ;
V_387 += V_807 ;
}
V_102:
return V_108 ;
}
static int F_334 ( struct V_1 * V_2 , unsigned long V_798 ,
T_6 * V_406 , struct V_66 * V_57 ,
bool V_808 )
{
T_1 V_84 = ( ( V_64 -> V_79 ( V_2 ) == 3 ) ? V_100 : 0 )
| ( V_808 ? V_101 : 0 ) ;
if ( F_335 ( V_2 , V_798 )
&& ! F_336 ( V_2 , V_2 -> V_5 . V_92 ,
V_2 -> V_5 . V_84 , V_84 ) ) {
* V_406 = V_2 -> V_5 . V_809 << V_95 |
( V_798 & ( V_96 - 1 ) ) ;
F_337 ( V_798 , * V_406 , V_808 , false ) ;
return 1 ;
}
* V_406 = V_2 -> V_5 . V_92 -> V_797 ( V_2 , V_798 , V_84 , V_57 ) ;
if ( * V_406 == V_88 )
return - 1 ;
if ( ( * V_406 & V_374 ) == V_810 )
return 1 ;
if ( F_338 ( V_2 , * V_406 ) ) {
F_337 ( V_798 , * V_406 , V_808 , true ) ;
return 1 ;
}
return 0 ;
}
int F_339 ( struct V_1 * V_2 , T_6 V_406 ,
const void * V_173 , int V_800 )
{
int V_97 ;
V_97 = F_108 ( V_2 -> V_90 , V_406 , V_173 , V_800 ) ;
if ( V_97 < 0 )
return 0 ;
F_340 ( V_2 , V_406 , V_173 , V_800 ) ;
return 1 ;
}
static int F_341 ( struct V_1 * V_2 , void * V_173 , int V_800 )
{
if ( V_2 -> V_811 ) {
F_319 ( V_790 , V_800 ,
V_2 -> V_812 [ 0 ] . V_406 , * ( T_2 * ) V_173 ) ;
V_2 -> V_811 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_342 ( struct V_1 * V_2 , T_6 V_406 ,
void * V_173 , int V_800 )
{
return ! F_107 ( V_2 -> V_90 , V_406 , V_173 , V_800 ) ;
}
static int F_343 ( struct V_1 * V_2 , T_6 V_406 ,
void * V_173 , int V_800 )
{
return F_339 ( V_2 , V_406 , V_173 , V_800 ) ;
}
static int F_344 ( struct V_1 * V_2 , T_6 V_406 , int V_800 , void * V_173 )
{
F_319 ( V_813 , V_800 , V_406 , * ( T_2 * ) V_173 ) ;
return F_312 ( V_2 , V_406 , V_800 , V_173 ) ;
}
static int F_345 ( struct V_1 * V_2 , T_6 V_406 ,
void * V_173 , int V_800 )
{
F_319 ( V_814 , V_800 , V_406 , 0 ) ;
return V_804 ;
}
static int F_346 ( struct V_1 * V_2 , T_6 V_406 ,
void * V_173 , int V_800 )
{
struct V_815 * V_816 = & V_2 -> V_812 [ 0 ] ;
memcpy ( V_2 -> V_817 -> V_818 . V_37 , V_816 -> V_37 , F_313 ( 8u , V_816 -> V_83 ) ) ;
return V_801 ;
}
static int F_347 ( unsigned long V_387 , void * V_173 ,
unsigned int V_800 ,
struct V_66 * V_57 ,
struct V_1 * V_2 ,
const struct V_819 * V_820 )
{
T_6 V_406 ;
int V_787 , V_97 ;
bool V_808 = V_820 -> V_808 ;
struct V_815 * V_816 ;
V_97 = F_334 ( V_2 , V_387 , & V_406 , V_57 , V_808 ) ;
if ( V_97 < 0 )
return V_803 ;
if ( V_97 )
goto V_818;
if ( V_820 -> V_821 ( V_2 , V_406 , V_173 , V_800 ) )
return V_801 ;
V_818:
V_787 = V_820 -> V_822 ( V_2 , V_406 , V_800 , V_173 ) ;
if ( V_787 == V_800 )
return V_801 ;
V_406 += V_787 ;
V_800 -= V_787 ;
V_173 += V_787 ;
F_348 ( V_2 -> V_823 >= V_824 ) ;
V_816 = & V_2 -> V_812 [ V_2 -> V_823 ++ ] ;
V_816 -> V_406 = V_406 ;
V_816 -> V_37 = V_173 ;
V_816 -> V_83 = V_800 ;
return V_801 ;
}
int F_349 ( struct V_805 * V_806 , unsigned long V_387 ,
void * V_173 , unsigned int V_800 ,
struct V_66 * V_57 ,
const struct V_819 * V_820 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
T_6 V_406 ;
int V_825 ;
if ( V_820 -> V_826 &&
V_820 -> V_826 ( V_2 , V_173 , V_800 ) )
return V_801 ;
V_2 -> V_823 = 0 ;
if ( ( ( V_387 + V_800 - 1 ) ^ V_387 ) & V_374 ) {
int V_827 ;
V_827 = - V_387 & ~ V_374 ;
V_825 = F_347 ( V_387 , V_173 , V_827 , V_57 ,
V_2 , V_820 ) ;
if ( V_825 != V_801 )
return V_825 ;
V_387 += V_827 ;
V_173 += V_827 ;
V_800 -= V_827 ;
}
V_825 = F_347 ( V_387 , V_173 , V_800 , V_57 ,
V_2 , V_820 ) ;
if ( V_825 != V_801 )
return V_825 ;
if ( ! V_2 -> V_823 )
return V_825 ;
V_406 = V_2 -> V_812 [ 0 ] . V_406 ;
V_2 -> V_828 = 1 ;
V_2 -> V_829 = 0 ;
V_2 -> V_817 -> V_818 . V_83 = F_313 ( 8u , V_2 -> V_812 [ 0 ] . V_83 ) ;
V_2 -> V_817 -> V_818 . V_830 = V_2 -> V_831 = V_820 -> V_808 ;
V_2 -> V_817 -> V_832 = V_833 ;
V_2 -> V_817 -> V_818 . V_834 = V_406 ;
return V_820 -> V_835 ( V_2 , V_406 , V_173 , V_800 ) ;
}
static int F_350 ( struct V_805 * V_806 ,
unsigned long V_387 ,
void * V_173 ,
unsigned int V_800 ,
struct V_66 * V_57 )
{
return F_349 ( V_806 , V_387 , V_173 , V_800 ,
V_57 , & V_836 ) ;
}
int F_351 ( struct V_805 * V_806 ,
unsigned long V_387 ,
const void * V_173 ,
unsigned int V_800 ,
struct V_66 * V_57 )
{
return F_349 ( V_806 , V_387 , ( void * ) V_173 , V_800 ,
V_57 , & V_837 ) ;
}
static int F_352 ( struct V_805 * V_806 ,
unsigned long V_387 ,
const void * V_838 ,
const void * V_839 ,
unsigned int V_800 ,
struct V_66 * V_57 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
T_6 V_406 ;
struct V_376 * V_376 ;
char * V_840 ;
bool V_841 ;
if ( V_800 > 8 || ( V_800 & ( V_800 - 1 ) ) )
goto V_842;
V_406 = F_326 ( V_2 , V_387 , NULL ) ;
if ( V_406 == V_88 ||
( V_406 & V_374 ) == V_810 )
goto V_842;
if ( ( ( V_406 + V_800 - 1 ) & V_374 ) != ( V_406 & V_374 ) )
goto V_842;
V_376 = F_353 ( V_2 -> V_90 , V_406 >> V_95 ) ;
if ( F_354 ( V_376 ) )
goto V_842;
V_840 = F_355 ( V_376 ) ;
V_840 += F_356 ( V_406 ) ;
switch ( V_800 ) {
case 1 :
V_841 = F_357 ( T_14 , V_840 , V_838 , V_839 ) ;
break;
case 2 :
V_841 = F_357 ( V_843 , V_840 , V_838 , V_839 ) ;
break;
case 4 :
V_841 = F_357 ( T_1 , V_840 , V_838 , V_839 ) ;
break;
case 8 :
V_841 = F_358 ( V_840 , V_838 , V_839 ) ;
break;
default:
F_24 () ;
}
F_359 ( V_840 ) ;
F_360 ( V_376 ) ;
if ( ! V_841 )
return V_844 ;
F_186 ( V_2 -> V_90 , V_406 >> V_95 ) ;
F_340 ( V_2 , V_406 , V_839 , V_800 ) ;
return V_801 ;
V_842:
F_361 ( V_845 L_22 ) ;
return F_351 ( V_806 , V_387 , V_839 , V_800 , V_57 ) ;
}
static int F_362 ( struct V_1 * V_2 , void * V_846 )
{
int V_108 ;
if ( V_2 -> V_5 . V_847 . V_848 )
V_108 = F_318 ( V_2 -> V_90 , V_756 , V_2 -> V_5 . V_847 . V_849 ,
V_2 -> V_5 . V_847 . V_504 , V_846 ) ;
else
V_108 = F_315 ( V_2 -> V_90 , V_756 ,
V_2 -> V_5 . V_847 . V_849 , V_2 -> V_5 . V_847 . V_504 ,
V_846 ) ;
return V_108 ;
}
static int F_363 ( struct V_1 * V_2 , int V_504 ,
unsigned short V_849 , void * V_173 ,
unsigned int V_719 , bool V_848 )
{
F_364 ( ! V_848 , V_849 , V_504 , V_719 ) ;
V_2 -> V_5 . V_847 . V_849 = V_849 ;
V_2 -> V_5 . V_847 . V_848 = V_848 ;
V_2 -> V_5 . V_847 . V_719 = V_719 ;
V_2 -> V_5 . V_847 . V_504 = V_504 ;
if ( ! F_362 ( V_2 , V_2 -> V_5 . V_850 ) ) {
V_2 -> V_5 . V_847 . V_719 = 0 ;
return 1 ;
}
V_2 -> V_817 -> V_832 = V_851 ;
V_2 -> V_817 -> V_852 . V_853 = V_848 ? V_854 : V_855 ;
V_2 -> V_817 -> V_852 . V_504 = V_504 ;
V_2 -> V_817 -> V_852 . V_856 = V_857 * V_96 ;
V_2 -> V_817 -> V_852 . V_719 = V_719 ;
V_2 -> V_817 -> V_852 . V_849 = V_849 ;
return 0 ;
}
static int F_365 ( struct V_805 * V_806 ,
int V_504 , unsigned short V_849 , void * V_173 ,
unsigned int V_719 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
int V_97 ;
if ( V_2 -> V_5 . V_847 . V_719 )
goto V_858;
V_97 = F_363 ( V_2 , V_504 , V_849 , V_173 , V_719 , true ) ;
if ( V_97 ) {
V_858:
memcpy ( V_173 , V_2 -> V_5 . V_850 , V_504 * V_719 ) ;
V_2 -> V_5 . V_847 . V_719 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_366 ( struct V_805 * V_806 ,
int V_504 , unsigned short V_849 ,
const void * V_173 , unsigned int V_719 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
memcpy ( V_2 -> V_5 . V_850 , V_173 , V_504 * V_719 ) ;
return F_363 ( V_2 , V_504 , V_849 , ( void * ) V_173 , V_719 , false ) ;
}
static unsigned long F_367 ( struct V_1 * V_2 , int V_793 )
{
return V_64 -> F_367 ( V_2 , V_793 ) ;
}
static void F_368 ( struct V_805 * V_806 , V_159 V_71 )
{
F_369 ( F_330 ( V_806 ) , V_71 ) ;
}
int F_370 ( struct V_1 * V_2 )
{
if ( ! F_235 ( V_2 ) )
return V_801 ;
if ( V_64 -> V_587 () ) {
int V_23 = F_371 () ;
F_238 ( V_23 , V_2 -> V_5 . V_588 ) ;
F_372 ( V_2 -> V_5 . V_588 ,
F_233 , NULL , 1 ) ;
F_373 () ;
F_374 ( V_2 -> V_5 . V_588 ) ;
} else
F_234 () ;
return V_801 ;
}
static void F_375 ( struct V_805 * V_806 )
{
F_370 ( F_330 ( V_806 ) ) ;
}
int F_376 ( struct V_805 * V_806 , int V_172 , unsigned long * V_859 )
{
return F_90 ( F_330 ( V_806 ) , V_172 , V_859 ) ;
}
int F_377 ( struct V_805 * V_806 , int V_172 , unsigned long V_22 )
{
return F_88 ( F_330 ( V_806 ) , V_172 , V_22 ) ;
}
static T_2 F_378 ( T_2 V_860 , T_1 V_861 )
{
return ( V_860 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_861 ;
}
static unsigned long F_379 ( struct V_805 * V_806 , int V_862 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
unsigned long V_22 ;
switch ( V_862 ) {
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
F_380 ( L_23 , V_239 , V_862 ) ;
return 0 ;
}
return V_22 ;
}
static int F_381 ( struct V_805 * V_806 , int V_862 , V_159 V_173 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
int V_181 = 0 ;
switch ( V_862 ) {
case 0 :
V_181 = F_54 ( V_2 , F_378 ( F_55 ( V_2 ) , V_173 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_70 = V_173 ;
break;
case 3 :
V_181 = F_77 ( V_2 , V_173 ) ;
break;
case 4 :
V_181 = F_69 ( V_2 , F_378 ( F_70 ( V_2 ) , V_173 ) ) ;
break;
case 8 :
V_181 = F_81 ( V_2 , V_173 ) ;
break;
default:
F_380 ( L_23 , V_239 , V_862 ) ;
V_181 = - 1 ;
}
return V_181 ;
}
static void F_382 ( struct V_805 * V_806 , V_159 V_173 )
{
F_383 ( F_330 ( V_806 ) , V_173 ) ;
}
static int F_384 ( struct V_805 * V_806 )
{
return V_64 -> V_79 ( F_330 ( V_806 ) ) ;
}
static void F_385 ( struct V_805 * V_806 , struct V_863 * V_864 )
{
V_64 -> V_865 ( F_330 ( V_806 ) , V_864 ) ;
}
static void F_386 ( struct V_805 * V_806 , struct V_863 * V_864 )
{
V_64 -> V_866 ( F_330 ( V_806 ) , V_864 ) ;
}
static void F_387 ( struct V_805 * V_806 , struct V_863 * V_864 )
{
V_64 -> V_867 ( F_330 ( V_806 ) , V_864 ) ;
}
static void F_388 ( struct V_805 * V_806 , struct V_863 * V_864 )
{
V_64 -> V_868 ( F_330 ( V_806 ) , V_864 ) ;
}
static unsigned long F_389 (
struct V_805 * V_806 , int V_793 )
{
return F_367 ( F_330 ( V_806 ) , V_793 ) ;
}
static bool F_390 ( struct V_805 * V_806 , V_843 * V_869 ,
struct V_870 * V_871 , T_1 * V_872 ,
int V_793 )
{
struct V_791 V_792 ;
F_321 ( F_330 ( V_806 ) , & V_792 , V_793 ) ;
* V_869 = V_792 . V_869 ;
if ( V_792 . V_873 ) {
memset ( V_871 , 0 , sizeof( * V_871 ) ) ;
return false ;
}
if ( V_792 . V_874 )
V_792 . V_875 >>= 12 ;
F_391 ( V_871 , V_792 . V_875 ) ;
F_392 ( V_871 , ( unsigned long ) V_792 . V_876 ) ;
#ifdef F_56
if ( V_872 )
* V_872 = V_792 . V_876 >> 32 ;
#endif
V_871 -> type = V_792 . type ;
V_871 -> V_595 = V_792 . V_595 ;
V_871 -> V_877 = V_792 . V_877 ;
V_871 -> V_345 = V_792 . V_878 ;
V_871 -> V_879 = V_792 . V_879 ;
V_871 -> V_880 = V_792 . V_880 ;
V_871 -> V_881 = V_792 . V_174 ;
V_871 -> V_874 = V_792 . V_874 ;
return true ;
}
static void F_393 ( struct V_805 * V_806 , V_843 V_869 ,
struct V_870 * V_871 , T_1 V_872 ,
int V_793 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
struct V_791 V_792 ;
V_792 . V_869 = V_869 ;
V_792 . V_876 = F_394 ( V_871 ) ;
#ifdef F_56
V_792 . V_876 |= ( ( T_2 ) V_872 ) << 32 ;
#endif
V_792 . V_875 = F_395 ( V_871 ) ;
if ( V_871 -> V_874 )
V_792 . V_875 = ( V_792 . V_875 << 12 ) | 0xfff ;
V_792 . type = V_871 -> type ;
V_792 . V_878 = V_871 -> V_345 ;
V_792 . V_877 = V_871 -> V_877 ;
V_792 . V_174 = V_871 -> V_881 ;
V_792 . V_595 = V_871 -> V_595 ;
V_792 . V_880 = V_871 -> V_880 ;
V_792 . V_874 = V_871 -> V_874 ;
V_792 . V_879 = V_871 -> V_879 ;
V_792 . V_878 = V_871 -> V_345 ;
V_792 . V_873 = ! V_792 . V_878 ;
V_792 . V_882 = 0 ;
F_320 ( V_2 , & V_792 , V_793 ) ;
return;
}
static int F_396 ( struct V_805 * V_806 ,
T_1 V_477 , T_2 * V_478 )
{
return F_209 ( F_330 ( V_806 ) , V_477 , V_478 ) ;
}
static int F_397 ( struct V_805 * V_806 ,
T_1 V_477 , T_2 V_37 )
{
struct V_31 V_21 ;
V_21 . V_37 = V_37 ;
V_21 . V_132 = V_477 ;
V_21 . V_39 = false ;
return F_101 ( F_330 ( V_806 ) , & V_21 ) ;
}
static int F_398 ( struct V_805 * V_806 ,
T_1 V_883 , T_2 * V_478 )
{
return F_94 ( F_330 ( V_806 ) , V_883 , V_478 ) ;
}
static void F_399 ( struct V_805 * V_806 )
{
F_330 ( V_806 ) -> V_5 . V_884 = 1 ;
}
static void F_400 ( struct V_805 * V_806 )
{
F_201 () ;
F_401 ( F_330 ( V_806 ) ) ;
F_402 () ;
}
static void F_403 ( struct V_805 * V_806 )
{
F_202 () ;
}
static int F_404 ( struct V_805 * V_806 ,
struct V_885 * V_886 ,
enum V_887 V_888 )
{
return V_64 -> V_889 ( F_330 ( V_806 ) , V_886 , V_888 ) ;
}
static void F_405 ( struct V_805 * V_806 ,
T_1 * V_890 , T_1 * V_891 , T_1 * V_184 , T_1 * V_192 )
{
V_668 ( F_330 ( V_806 ) , V_890 , V_891 , V_184 , V_192 ) ;
}
static V_159 F_406 ( struct V_805 * V_806 , unsigned V_892 )
{
return F_93 ( F_330 ( V_806 ) , V_892 ) ;
}
static void F_407 ( struct V_805 * V_806 , unsigned V_892 , V_159 V_173 )
{
F_95 ( F_330 ( V_806 ) , V_892 , V_173 ) ;
}
static void F_408 ( struct V_1 * V_2 , T_1 V_27 )
{
T_1 V_893 = V_64 -> V_624 ( V_2 , V_27 ) ;
if ( ! ( V_893 & V_27 ) )
V_64 -> V_637 ( V_2 , V_27 ) ;
}
static void F_409 ( struct V_1 * V_2 )
{
struct V_805 * V_806 = & V_2 -> V_5 . V_894 ;
if ( V_806 -> V_57 . V_40 == V_41 )
F_34 ( V_2 , & V_806 -> V_57 ) ;
else if ( V_806 -> V_57 . V_895 )
F_33 ( V_2 , V_806 -> V_57 . V_40 ,
V_806 -> V_57 . V_51 ) ;
else
F_28 ( V_2 , V_806 -> V_57 . V_40 ) ;
}
static void F_410 ( struct V_805 * V_806 )
{
memset ( & V_806 -> V_896 , 0 ,
( void * ) & V_806 -> V_897 - ( void * ) & V_806 -> V_896 ) ;
V_806 -> V_898 . V_721 = 0 ;
V_806 -> V_898 . V_899 = 0 ;
V_806 -> V_900 . V_901 = 0 ;
V_806 -> V_900 . V_899 = 0 ;
V_806 -> V_902 . V_901 = 0 ;
V_806 -> V_902 . V_899 = 0 ;
}
static void F_411 ( struct V_1 * V_2 )
{
struct V_805 * V_806 = & V_2 -> V_5 . V_894 ;
int V_121 , V_122 ;
V_64 -> V_123 ( V_2 , & V_121 , & V_122 ) ;
V_806 -> V_903 = F_412 ( V_2 ) ;
V_806 -> V_904 = F_413 ( V_2 ) ;
V_806 -> V_294 = ( ! F_414 ( V_2 ) ) ? V_905 :
( V_806 -> V_903 & V_906 ) ? V_907 :
V_122 ? V_908 :
V_121 ? V_909 :
V_910 ;
V_806 -> V_911 = F_415 ( V_2 ) ;
F_410 ( V_806 ) ;
V_2 -> V_5 . V_912 = false ;
}
int F_416 ( struct V_1 * V_2 , int V_600 , int V_913 )
{
struct V_805 * V_806 = & V_2 -> V_5 . V_894 ;
int V_97 ;
F_411 ( V_2 ) ;
V_806 -> V_914 = 2 ;
V_806 -> V_915 = 2 ;
V_806 -> V_916 = V_806 -> V_904 + V_913 ;
V_97 = F_417 ( V_806 , V_600 ) ;
if ( V_97 != V_801 )
return V_917 ;
V_806 -> V_904 = V_806 -> V_916 ;
F_418 ( V_2 , V_806 -> V_904 ) ;
F_383 ( V_2 , V_806 -> V_903 ) ;
if ( V_600 == V_918 )
V_2 -> V_5 . V_629 = 0 ;
else
V_2 -> V_5 . V_621 . V_58 = false ;
return V_919 ;
}
static int F_419 ( struct V_1 * V_2 )
{
int V_108 = V_919 ;
++ V_2 -> V_68 . V_920 ;
F_420 ( V_2 ) ;
if ( ! F_415 ( V_2 ) ) {
V_2 -> V_817 -> V_832 = V_921 ;
V_2 -> V_817 -> V_922 . V_923 = V_924 ;
V_2 -> V_817 -> V_922 . V_925 = 0 ;
V_108 = V_917 ;
}
F_28 ( V_2 , V_182 ) ;
return V_108 ;
}
static bool F_421 ( struct V_1 * V_2 , T_16 V_70 ,
bool V_926 ,
int V_927 )
{
T_6 V_406 = V_70 ;
T_17 V_928 ;
if ( V_927 & V_929 )
return false ;
if ( ! V_2 -> V_5 . V_75 . V_930 ) {
V_406 = F_326 ( V_2 , V_70 , NULL ) ;
if ( V_406 == V_88 )
return true ;
}
V_928 = F_422 ( V_2 -> V_90 , F_42 ( V_406 ) ) ;
if ( F_423 ( V_928 ) )
return false ;
F_424 ( V_928 ) ;
if ( V_2 -> V_5 . V_75 . V_930 ) {
unsigned int V_931 ;
F_134 ( & V_2 -> V_90 -> V_736 ) ;
V_931 = V_2 -> V_90 -> V_5 . V_931 ;
F_135 ( & V_2 -> V_90 -> V_736 ) ;
if ( V_931 )
F_425 ( V_2 -> V_90 , F_42 ( V_406 ) ) ;
return true ;
}
F_425 ( V_2 -> V_90 , F_42 ( V_406 ) ) ;
return ! V_926 ;
}
static bool F_426 ( struct V_805 * V_806 ,
unsigned long V_70 , int V_927 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
unsigned long V_932 , V_933 , V_406 = V_70 ;
V_932 = V_2 -> V_5 . V_932 ;
V_933 = V_2 -> V_5 . V_933 ;
V_2 -> V_5 . V_932 = V_2 -> V_5 . V_933 = 0 ;
if ( ! ( V_927 & V_934 ) )
return false ;
if ( F_427 ( V_806 ) )
return false ;
if ( V_806 -> V_904 == V_932 && V_933 == V_70 )
return false ;
V_2 -> V_5 . V_932 = V_806 -> V_904 ;
V_2 -> V_5 . V_933 = V_70 ;
if ( ! V_2 -> V_5 . V_75 . V_930 )
V_406 = F_326 ( V_2 , V_70 , NULL ) ;
F_425 ( V_2 -> V_90 , F_42 ( V_406 ) ) ;
return true ;
}
static int F_428 ( unsigned long V_387 , T_1 type , T_1 V_166 ,
unsigned long * V_174 )
{
T_1 V_165 = 0 ;
int V_3 ;
T_1 V_935 , V_936 ;
V_935 = V_166 ;
V_936 = V_166 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_935 >>= 2 , V_936 >>= 4 )
if ( ( V_935 & 3 ) && ( V_936 & 15 ) == type && V_174 [ V_3 ] == V_387 )
V_165 |= ( 1 << V_3 ) ;
return V_165 ;
}
static void F_429 ( struct V_1 * V_2 , int * V_108 )
{
struct V_937 * V_937 = V_2 -> V_817 ;
unsigned long V_938 = V_64 -> V_939 ( V_2 ) ;
if ( F_143 ( V_938 & V_940 ) ) {
if ( V_2 -> V_162 & V_941 ) {
V_937 -> V_942 . V_5 . V_165 = V_943 | V_178 ;
V_937 -> V_942 . V_5 . V_944 = V_2 -> V_5 . V_945 ;
V_937 -> V_942 . V_5 . V_57 = V_946 ;
V_937 -> V_832 = V_947 ;
* V_108 = V_948 ;
} else {
V_2 -> V_5 . V_894 . V_903 &= ~ V_940 ;
V_2 -> V_5 . V_165 &= ~ 15 ;
V_2 -> V_5 . V_165 |= V_943 ;
F_28 ( V_2 , V_946 ) ;
}
}
}
static bool F_430 ( struct V_1 * V_2 , int * V_108 )
{
struct V_937 * V_937 = V_2 -> V_817 ;
unsigned long V_904 = V_2 -> V_5 . V_894 . V_904 ;
T_1 V_165 = 0 ;
if ( F_143 ( V_2 -> V_162 & V_163 ) &&
( V_2 -> V_5 . V_167 & V_171 ) ) {
V_165 = F_428 ( V_904 , 0 ,
V_2 -> V_5 . V_167 ,
V_2 -> V_5 . V_175 ) ;
if ( V_165 != 0 ) {
V_937 -> V_942 . V_5 . V_165 = V_165 | V_178 ;
V_937 -> V_942 . V_5 . V_944 = F_413 ( V_2 ) +
F_367 ( V_2 , V_949 ) ;
V_937 -> V_942 . V_5 . V_57 = V_946 ;
V_937 -> V_832 = V_947 ;
* V_108 = V_948 ;
return true ;
}
}
if ( F_143 ( V_2 -> V_5 . V_166 & V_171 ) ) {
V_165 = F_428 ( V_904 , 0 ,
V_2 -> V_5 . V_166 ,
V_2 -> V_5 . V_174 ) ;
if ( V_165 != 0 ) {
V_2 -> V_5 . V_165 &= ~ 15 ;
V_2 -> V_5 . V_165 |= V_165 ;
F_28 ( V_2 , V_946 ) ;
* V_108 = V_919 ;
return true ;
}
}
return false ;
}
int F_431 ( struct V_1 * V_2 ,
unsigned long V_70 ,
int V_927 ,
void * V_950 ,
int V_951 )
{
int V_108 ;
struct V_805 * V_806 = & V_2 -> V_5 . V_894 ;
bool V_502 = true ;
bool V_952 = V_2 -> V_5 . V_926 ;
V_2 -> V_5 . V_926 = false ;
F_432 ( V_2 ) ;
if ( ! ( V_927 & V_953 ) ) {
F_411 ( V_2 ) ;
if ( F_430 ( V_2 , & V_108 ) )
return V_108 ;
V_806 -> V_954 = 0 ;
V_806 -> V_955 = false ;
V_806 -> V_956 = false ;
V_806 -> V_957 = V_927 & V_958 ;
V_108 = F_433 ( V_806 , V_950 , V_951 ) ;
F_434 ( V_2 ) ;
++ V_2 -> V_68 . V_959 ;
if ( V_108 != V_960 ) {
if ( V_927 & V_958 )
return V_917 ;
if ( F_421 ( V_2 , V_70 , V_952 ,
V_927 ) )
return V_919 ;
if ( V_927 & V_961 )
return V_917 ;
return F_419 ( V_2 ) ;
}
}
if ( V_927 & V_961 ) {
F_418 ( V_2 , V_806 -> V_916 ) ;
return V_919 ;
}
if ( F_426 ( V_806 , V_70 , V_927 ) )
return V_919 ;
if ( V_2 -> V_5 . V_912 ) {
V_2 -> V_5 . V_912 = false ;
F_435 ( V_806 ) ;
}
V_962:
V_108 = F_436 ( V_806 ) ;
if ( V_108 == V_963 )
return V_919 ;
if ( V_108 == V_964 ) {
if ( F_421 ( V_2 , V_70 , V_952 ,
V_927 ) )
return V_919 ;
return F_419 ( V_2 ) ;
}
if ( V_806 -> V_955 ) {
F_409 ( V_2 ) ;
V_108 = V_919 ;
} else if ( V_2 -> V_5 . V_847 . V_719 ) {
if ( ! V_2 -> V_5 . V_847 . V_848 ) {
V_2 -> V_5 . V_847 . V_719 = 0 ;
} else {
V_502 = false ;
V_2 -> V_5 . V_965 = V_966 ;
}
V_108 = V_948 ;
} else if ( V_2 -> V_828 ) {
if ( ! V_2 -> V_831 )
V_502 = false ;
V_108 = V_948 ;
V_2 -> V_5 . V_965 = V_967 ;
} else if ( V_108 == V_968 )
goto V_962;
else
V_108 = V_919 ;
if ( V_502 ) {
F_408 ( V_2 , V_806 -> V_954 ) ;
F_27 ( V_56 , V_2 ) ;
V_2 -> V_5 . V_969 = false ;
F_418 ( V_2 , V_806 -> V_904 ) ;
if ( V_108 == V_919 )
F_429 ( V_2 , & V_108 ) ;
F_383 ( V_2 , V_806 -> V_903 ) ;
} else
V_2 -> V_5 . V_969 = true ;
return V_108 ;
}
int F_437 ( struct V_1 * V_2 , int V_504 , unsigned short V_849 )
{
unsigned long V_173 = F_93 ( V_2 , V_186 ) ;
int V_97 = F_366 ( & V_2 -> V_5 . V_894 ,
V_504 , V_849 , & V_173 , 1 ) ;
V_2 -> V_5 . V_847 . V_719 = 0 ;
return V_97 ;
}
static void F_438 ( void * V_886 )
{
F_439 ( V_309 , 0 ) ;
}
static void F_440 ( void * V_37 )
{
struct V_970 * V_971 = V_37 ;
unsigned long V_242 = 0 ;
if ( V_37 )
V_242 = V_971 -> V_839 ;
else if ( ! F_230 ( V_972 ) )
V_242 = F_441 ( F_442 () ) ;
if ( ! V_242 )
V_242 = V_250 ;
F_439 ( V_309 , V_242 ) ;
}
static int F_443 ( struct V_973 * V_974 , unsigned long V_173 ,
void * V_37 )
{
struct V_970 * V_971 = V_37 ;
struct V_90 * V_90 ;
struct V_1 * V_2 ;
int V_3 , V_975 = 0 ;
if ( V_173 == V_976 && V_971 -> V_838 > V_971 -> V_839 )
return 0 ;
if ( V_173 == V_977 && V_971 -> V_838 < V_971 -> V_839 )
return 0 ;
F_239 ( V_971 -> V_23 , F_440 , V_971 , 1 ) ;
F_134 ( & V_978 ) ;
F_444 (kvm, &vm_list, vm_list) {
F_152 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_971 -> V_23 )
continue;
F_27 ( V_300 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_975 = 1 ;
}
}
F_135 ( & V_978 ) ;
if ( V_971 -> V_838 < V_971 -> V_839 && V_975 ) {
F_239 ( V_971 -> V_23 , F_440 , V_971 , 1 ) ;
}
return 0 ;
}
static int F_445 ( struct V_973 * V_979 ,
unsigned long V_980 , void * V_981 )
{
unsigned int V_23 = ( unsigned long ) V_981 ;
switch ( V_980 ) {
case V_982 :
case V_983 :
F_239 ( V_23 , F_440 , NULL , 1 ) ;
break;
case V_984 :
F_239 ( V_23 , F_438 , NULL , 1 ) ;
break;
}
return V_985 ;
}
static void F_446 ( void )
{
int V_23 ;
V_986 = V_250 ;
F_447 () ;
if ( ! F_230 ( V_972 ) ) {
#ifdef F_448
struct V_987 V_988 ;
memset ( & V_988 , 0 , sizeof( V_988 ) ) ;
V_23 = F_371 () ;
F_449 ( & V_988 , V_23 ) ;
if ( V_988 . V_989 . V_990 )
V_986 = V_988 . V_989 . V_990 ;
F_373 () ;
#endif
F_450 ( & V_991 ,
V_992 ) ;
}
F_114 ( L_24 , V_986 ) ;
F_451 (cpu)
F_239 ( V_23 , F_440 , NULL , 1 ) ;
F_452 ( & V_993 ) ;
F_453 () ;
}
int F_454 ( void )
{
return F_455 ( V_994 ) != NULL ;
}
static int F_456 ( void )
{
int V_995 = 3 ;
if ( F_455 ( V_994 ) )
V_995 = V_64 -> V_79 ( F_455 ( V_994 ) ) ;
return V_995 != 0 ;
}
static unsigned long F_457 ( void )
{
unsigned long V_996 = 0 ;
if ( F_455 ( V_994 ) )
V_996 = F_413 ( F_455 ( V_994 ) ) ;
return V_996 ;
}
void F_458 ( struct V_1 * V_2 )
{
F_439 ( V_994 , V_2 ) ;
}
void F_459 ( struct V_1 * V_2 )
{
F_439 ( V_994 , NULL ) ;
}
static void F_460 ( void )
{
T_2 V_27 ;
int V_997 = V_998 . V_999 ;
V_27 = ( ( 1ull << ( 51 - V_997 + 1 ) ) - 1 ) << V_997 ;
V_27 |= 0x3ull << 62 ;
V_27 |= 1ull ;
#ifdef F_56
if ( V_997 == 52 )
V_27 &= ~ 1ull ;
#endif
F_461 ( V_27 ) ;
}
static void F_462 ( struct V_322 * V_323 )
{
struct V_90 * V_90 ;
struct V_1 * V_2 ;
int V_3 ;
F_134 ( & V_978 ) ;
F_444 (kvm, &vm_list, vm_list)
F_152 (i, vcpu, kvm)
F_153 ( V_266 , & V_2 -> V_301 ) ;
F_148 ( & V_299 , 0 ) ;
F_135 ( & V_978 ) ;
}
static int F_463 ( struct V_973 * V_974 , unsigned long V_1000 ,
void * V_1001 )
{
struct V_202 * V_261 = & V_202 ;
struct V_200 * V_201 = V_1001 ;
F_103 ( V_201 ) ;
if ( V_261 -> clock . V_205 != V_264 &&
F_126 ( & V_299 ) != 0 )
F_464 ( V_1002 , & V_1003 ) ;
return 0 ;
}
int F_465 ( void * V_1004 )
{
int V_108 ;
struct V_64 * V_820 = V_1004 ;
if ( V_64 ) {
F_10 ( V_26 L_25 ) ;
V_108 = - V_754 ;
goto V_102;
}
if ( ! V_820 -> V_1005 () ) {
F_10 ( V_26 L_26 ) ;
V_108 = - V_1006 ;
goto V_102;
}
if ( V_820 -> V_1007 () ) {
F_10 ( V_26 L_27 ) ;
V_108 = - V_1006 ;
goto V_102;
}
V_108 = - V_378 ;
V_25 = F_466 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_102;
}
V_108 = F_467 () ;
if ( V_108 )
goto V_1008;
F_460 () ;
V_64 = V_820 ;
F_310 () ;
F_468 ( V_1009 , V_1010 ,
V_1011 , V_1012 , 0 ) ;
F_446 () ;
F_469 ( & V_1013 ) ;
if ( V_559 )
V_131 = F_470 ( V_129 ) ;
F_471 () ;
#ifdef F_56
F_472 ( & V_1014 ) ;
#endif
return 0 ;
V_1008:
F_473 ( V_25 ) ;
V_102:
return V_108 ;
}
void F_474 ( void )
{
F_475 ( & V_1013 ) ;
if ( ! F_230 ( V_972 ) )
F_476 ( & V_991 ,
V_992 ) ;
F_477 ( & V_993 ) ;
#ifdef F_56
F_478 ( & V_1014 ) ;
#endif
V_64 = NULL ;
F_479 () ;
F_473 ( V_25 ) ;
}
int F_480 ( struct V_1 * V_2 )
{
++ V_2 -> V_68 . V_1015 ;
if ( F_82 ( V_2 -> V_90 ) ) {
V_2 -> V_5 . V_1016 = V_1017 ;
return 1 ;
} else {
V_2 -> V_817 -> V_832 = V_1018 ;
return 0 ;
}
}
int F_481 ( struct V_1 * V_2 )
{
T_2 V_1019 , V_1020 , V_1021 , V_97 ;
T_18 V_1022 , V_1023 , V_1024 , V_181 = V_1025 , V_1026 = 0 ;
bool V_1027 , V_1028 ;
int V_121 , V_122 ;
if ( V_64 -> V_79 ( V_2 ) != 0 || ! F_414 ( V_2 ) ) {
F_28 ( V_2 , V_182 ) ;
return 0 ;
}
V_64 -> V_123 ( V_2 , & V_121 , & V_122 ) ;
V_1028 = F_50 ( V_2 ) && V_122 == 1 ;
if ( ! V_1028 ) {
V_1019 = ( ( T_2 ) F_93 ( V_2 , V_187 ) << 32 ) |
( F_93 ( V_2 , V_186 ) & 0xffffffff ) ;
V_1020 = ( ( T_2 ) F_93 ( V_2 , V_1029 ) << 32 ) |
( F_93 ( V_2 , V_185 ) & 0xffffffff ) ;
V_1021 = ( ( T_2 ) F_93 ( V_2 , V_1030 ) << 32 ) |
( F_93 ( V_2 , V_1031 ) & 0xffffffff ) ;
}
#ifdef F_56
else {
V_1019 = F_93 ( V_2 , V_185 ) ;
V_1020 = F_93 ( V_2 , V_187 ) ;
V_1021 = F_93 ( V_2 , V_1032 ) ;
}
#endif
V_1022 = V_1019 & 0xffff ;
V_1027 = ( V_1019 >> 16 ) & 0x1 ;
V_1024 = ( V_1019 >> 32 ) & 0xfff ;
V_1023 = ( V_1019 >> 48 ) & 0xfff ;
F_482 ( V_1022 , V_1027 , V_1024 , V_1023 , V_1020 , V_1021 ) ;
switch ( V_1022 ) {
case V_1033 :
F_483 ( V_2 ) ;
break;
default:
V_181 = V_1034 ;
break;
}
V_97 = V_181 | ( ( ( T_2 ) V_1026 & 0xfff ) << 32 ) ;
if ( V_1028 ) {
F_95 ( V_2 , V_186 , V_97 ) ;
} else {
F_95 ( V_2 , V_187 , V_97 >> 32 ) ;
F_95 ( V_2 , V_186 , V_97 & 0xffffffff ) ;
}
return 1 ;
}
static void F_484 ( struct V_90 * V_90 , unsigned long V_273 , int V_1035 )
{
struct V_1036 V_1037 ;
V_1037 . V_1038 = 0 ;
V_1037 . V_1039 = 0 ;
V_1037 . V_1040 = V_1035 ;
V_1037 . V_1041 = V_1042 ;
F_485 ( V_90 , 0 , & V_1037 , NULL ) ;
}
int F_486 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1043 , V_1044 , V_1045 , V_1046 , V_97 ;
int V_108 = 1 ;
if ( F_180 ( V_2 -> V_90 ) )
return F_481 ( V_2 ) ;
V_16 = F_93 ( V_2 , V_186 ) ;
V_1043 = F_93 ( V_2 , V_1029 ) ;
V_1044 = F_93 ( V_2 , V_185 ) ;
V_1045 = F_93 ( V_2 , V_187 ) ;
V_1046 = F_93 ( V_2 , V_1031 ) ;
F_487 ( V_16 , V_1043 , V_1044 , V_1045 , V_1046 ) ;
if ( ! F_50 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_1043 &= 0xFFFFFFFF ;
V_1044 &= 0xFFFFFFFF ;
V_1045 &= 0xFFFFFFFF ;
V_1046 &= 0xFFFFFFFF ;
}
if ( V_64 -> V_79 ( V_2 ) != 0 ) {
V_97 = - V_1047 ;
goto V_102;
}
switch ( V_16 ) {
case V_1048 :
V_97 = 0 ;
break;
case V_1049 :
F_484 ( V_2 -> V_90 , V_1043 , V_1044 ) ;
V_97 = 0 ;
break;
default:
V_97 = - V_1050 ;
break;
}
V_102:
F_95 ( V_2 , V_186 , V_97 ) ;
++ V_2 -> V_68 . V_1051 ;
return V_108 ;
}
static int F_488 ( struct V_805 * V_806 )
{
struct V_1 * V_2 = F_330 ( V_806 ) ;
char V_1052 [ 3 ] ;
unsigned long V_1053 = F_413 ( V_2 ) ;
V_64 -> V_390 ( V_2 , V_1052 ) ;
return F_351 ( V_806 , V_1053 , V_1052 , 3 , NULL ) ;
}
static int F_489 ( struct V_1 * V_2 )
{
return ( ! F_82 ( V_2 -> V_90 ) && ! F_490 ( V_2 ) &&
V_2 -> V_817 -> V_1054 &&
F_491 ( V_2 ) ) ;
}
static void F_492 ( struct V_1 * V_2 )
{
struct V_937 * V_937 = V_2 -> V_817 ;
V_937 -> V_1055 = ( F_412 ( V_2 ) & V_1056 ) != 0 ;
V_937 -> V_160 = F_84 ( V_2 ) ;
V_937 -> V_30 = F_18 ( V_2 ) ;
if ( F_82 ( V_2 -> V_90 ) )
V_937 -> V_1057 = 1 ;
else
V_937 -> V_1057 =
F_491 ( V_2 ) &&
! F_490 ( V_2 ) &&
! F_493 ( V_2 ) ;
}
static void F_248 ( struct V_1 * V_2 )
{
int V_1058 , V_1059 ;
if ( ! V_64 -> F_248 )
return;
if ( ! V_2 -> V_5 . V_598 )
return;
if ( ! V_2 -> V_5 . V_598 -> V_677 )
V_1058 = F_494 ( V_2 ) ;
else
V_1058 = - 1 ;
if ( V_1058 != - 1 )
V_1058 >>= 4 ;
V_1059 = F_85 ( V_2 ) ;
V_64 -> F_248 ( V_2 , V_1059 , V_1058 ) ;
}
static int F_495 ( struct V_1 * V_2 , bool V_1060 )
{
int V_108 ;
if ( V_2 -> V_5 . V_57 . V_58 ) {
F_496 ( V_2 -> V_5 . V_57 . V_16 ,
V_2 -> V_5 . V_57 . V_60 ,
V_2 -> V_5 . V_57 . V_51 ) ;
V_64 -> V_1061 ( V_2 , V_2 -> V_5 . V_57 . V_16 ,
V_2 -> V_5 . V_57 . V_60 ,
V_2 -> V_5 . V_57 . V_51 ,
V_2 -> V_5 . V_57 . V_52 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_628 ) {
V_64 -> V_1062 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_621 . V_58 ) {
V_64 -> V_1063 ( V_2 ) ;
return 0 ;
}
if ( F_415 ( V_2 ) && V_64 -> V_1064 ) {
V_108 = V_64 -> V_1064 ( V_2 , V_1060 ) ;
if ( V_108 != 0 )
return V_108 ;
}
if ( V_2 -> V_5 . V_629 ) {
if ( V_64 -> V_1065 ( V_2 ) ) {
-- V_2 -> V_5 . V_629 ;
V_2 -> V_5 . V_628 = true ;
V_64 -> V_1062 ( V_2 ) ;
}
} else if ( F_497 ( V_2 ) ) {
if ( V_64 -> V_1066 ( V_2 ) ) {
F_250 ( V_2 , F_498 ( V_2 ) ,
false ) ;
V_64 -> V_1063 ( V_2 ) ;
}
}
return 0 ;
}
static void F_256 ( struct V_1 * V_2 )
{
unsigned V_875 = 2 ;
if ( V_64 -> V_631 ( V_2 ) || V_2 -> V_5 . V_628 )
V_875 = 1 ;
V_2 -> V_5 . V_629 += F_499 ( & V_2 -> V_5 . V_76 , 0 ) ;
V_2 -> V_5 . V_629 = F_313 ( V_2 -> V_5 . V_629 , V_875 ) ;
F_27 ( V_56 , V_2 ) ;
}
static void F_500 ( struct V_1 * V_2 )
{
T_2 V_1067 [ 4 ] ;
T_1 V_1068 [ 8 ] ;
if ( ! F_501 ( V_2 -> V_5 . V_598 ) )
return;
memset ( V_1067 , 0 , 32 ) ;
memset ( V_1068 , 0 , 32 ) ;
F_502 ( V_2 , V_1067 , V_1068 ) ;
V_64 -> V_1069 ( V_2 , V_1067 ) ;
F_503 ( V_2 , V_1068 ) ;
}
static int F_504 ( struct V_1 * V_2 )
{
int V_108 ;
bool V_1060 = ! F_82 ( V_2 -> V_90 ) &&
V_2 -> V_817 -> V_1054 ;
bool V_1070 = false ;
if ( V_2 -> V_301 ) {
if ( F_505 ( V_1071 , V_2 ) )
F_506 ( V_2 ) ;
if ( F_505 ( V_1072 , V_2 ) )
F_507 ( V_2 ) ;
if ( F_505 ( V_266 , V_2 ) )
F_150 ( V_2 -> V_90 ) ;
if ( F_505 ( V_447 , V_2 ) )
F_166 ( V_2 ) ;
if ( F_505 ( V_300 , V_2 ) ) {
V_108 = F_155 ( V_2 ) ;
if ( F_143 ( V_108 ) )
goto V_102;
}
if ( F_505 ( V_1073 , V_2 ) )
F_78 ( V_2 ) ;
if ( F_505 ( V_1074 , V_2 ) )
V_64 -> V_1075 ( V_2 ) ;
if ( F_505 ( V_1076 , V_2 ) ) {
V_2 -> V_817 -> V_832 = V_1077 ;
V_108 = 0 ;
goto V_102;
}
if ( F_505 ( V_62 , V_2 ) ) {
V_2 -> V_817 -> V_832 = V_1078 ;
V_108 = 0 ;
goto V_102;
}
if ( F_505 ( V_1079 , V_2 ) ) {
V_2 -> V_1080 = 0 ;
V_64 -> V_1081 ( V_2 ) ;
}
if ( F_505 ( V_1082 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1083 = true ;
V_108 = 1 ;
goto V_102;
}
if ( F_505 ( V_452 , V_2 ) )
F_196 ( V_2 ) ;
if ( F_505 ( V_77 , V_2 ) )
F_256 ( V_2 ) ;
if ( F_505 ( V_1084 , V_2 ) )
F_508 ( V_2 ) ;
if ( F_505 ( V_1085 , V_2 ) )
F_509 ( V_2 ) ;
if ( F_505 ( V_1086 , V_2 ) )
F_500 ( V_2 ) ;
}
if ( F_505 ( V_56 , V_2 ) || V_1060 ) {
F_510 ( V_2 ) ;
if ( V_2 -> V_5 . V_1016 == V_1087 ) {
V_108 = 1 ;
goto V_102;
}
if ( F_495 ( V_2 , V_1060 ) != 0 )
V_1070 = true ;
else if ( V_2 -> V_5 . V_629 )
V_64 -> V_1088 ( V_2 ) ;
else if ( F_497 ( V_2 ) || V_1060 )
V_64 -> V_1089 ( V_2 ) ;
if ( F_511 ( V_2 ) ) {
if ( V_64 -> V_1090 )
V_64 -> V_1090 ( V_2 ,
F_494 ( V_2 ) ) ;
F_248 ( V_2 ) ;
F_512 ( V_2 ) ;
}
}
V_108 = F_513 ( V_2 ) ;
if ( F_143 ( V_108 ) ) {
goto V_1091;
}
F_201 () ;
V_64 -> V_1092 ( V_2 ) ;
if ( V_2 -> V_1080 )
F_401 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_294 = V_1093 ;
F_223 ( & V_2 -> V_90 -> V_499 , V_2 -> V_1094 ) ;
F_514 () ;
F_308 () ;
if ( V_2 -> V_294 == V_1095 || V_2 -> V_301
|| F_515 () || F_516 ( V_413 ) ) {
V_2 -> V_294 = V_1096 ;
F_13 () ;
F_309 () ;
F_202 () ;
V_2 -> V_1094 = F_222 ( & V_2 -> V_90 -> V_499 ) ;
V_108 = 1 ;
goto V_1091;
}
if ( V_1070 )
F_517 ( V_2 -> V_23 ) ;
F_518 () ;
if ( F_143 ( V_2 -> V_5 . V_169 ) ) {
F_519 ( 0 , 7 ) ;
F_519 ( V_2 -> V_5 . V_175 [ 0 ] , 0 ) ;
F_519 ( V_2 -> V_5 . V_175 [ 1 ] , 1 ) ;
F_519 ( V_2 -> V_5 . V_175 [ 2 ] , 2 ) ;
F_519 ( V_2 -> V_5 . V_175 [ 3 ] , 3 ) ;
F_519 ( V_2 -> V_5 . V_165 , 6 ) ;
}
F_520 ( V_2 -> V_267 ) ;
V_64 -> V_817 ( V_2 ) ;
if ( F_143 ( V_2 -> V_5 . V_169 & V_1097 ) ) {
int V_3 ;
F_348 ( V_2 -> V_162 & V_163 ) ;
V_64 -> V_1098 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_1099 ; V_3 ++ )
V_2 -> V_5 . V_175 [ V_3 ] = V_2 -> V_5 . V_174 [ V_3 ] ;
}
if ( F_521 () )
F_522 () ;
V_2 -> V_5 . V_288 = V_64 -> V_310 ( V_2 ,
F_159 () ) ;
V_2 -> V_294 = V_1096 ;
F_13 () ;
V_64 -> V_1100 ( V_2 ) ;
++ V_2 -> V_68 . V_1101 ;
F_523 () ;
F_524 () ;
F_202 () ;
V_2 -> V_1094 = F_222 ( & V_2 -> V_90 -> V_499 ) ;
if ( F_143 ( V_1102 == V_1103 ) ) {
unsigned long V_1053 = F_413 ( V_2 ) ;
F_525 ( V_1103 , ( void * ) V_1053 ) ;
}
if ( F_143 ( V_2 -> V_5 . V_1104 ) )
F_27 ( V_300 , V_2 ) ;
if ( V_2 -> V_5 . V_1105 )
F_526 ( V_2 ) ;
V_108 = V_64 -> V_1106 ( V_2 ) ;
return V_108 ;
V_1091:
V_64 -> V_1091 ( V_2 ) ;
if ( F_143 ( V_2 -> V_5 . V_1105 ) )
F_526 ( V_2 ) ;
V_102:
return V_108 ;
}
static int F_527 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_90 * V_90 = V_2 -> V_90 ;
V_2 -> V_1094 = F_222 ( & V_90 -> V_499 ) ;
V_108 = 1 ;
while ( V_108 > 0 ) {
if ( V_2 -> V_5 . V_1016 == V_1107 &&
! V_2 -> V_5 . V_6 . V_1083 )
V_108 = F_504 ( V_2 ) ;
else {
F_223 ( & V_90 -> V_499 , V_2 -> V_1094 ) ;
F_528 ( V_2 ) ;
V_2 -> V_1094 = F_222 ( & V_90 -> V_499 ) ;
if ( F_505 ( V_1108 , V_2 ) ) {
F_510 ( V_2 ) ;
switch( V_2 -> V_5 . V_1016 ) {
case V_1017 :
V_2 -> V_5 . V_1109 . V_1110 = false ;
V_2 -> V_5 . V_1016 =
V_1107 ;
case V_1107 :
V_2 -> V_5 . V_6 . V_1083 = false ;
break;
case V_1087 :
break;
default:
V_108 = - V_1111 ;
break;
}
}
}
if ( V_108 <= 0 )
break;
F_154 ( V_1112 , & V_2 -> V_301 ) ;
if ( F_529 ( V_2 ) )
F_530 ( V_2 ) ;
if ( F_489 ( V_2 ) ) {
V_108 = - V_1111 ;
V_2 -> V_817 -> V_832 = V_1113 ;
++ V_2 -> V_68 . V_1114 ;
}
F_531 ( V_2 ) ;
if ( F_516 ( V_413 ) ) {
V_108 = - V_1111 ;
V_2 -> V_817 -> V_832 = V_1113 ;
++ V_2 -> V_68 . V_1115 ;
}
if ( F_515 () ) {
F_223 ( & V_90 -> V_499 , V_2 -> V_1094 ) ;
F_532 () ;
V_2 -> V_1094 = F_222 ( & V_90 -> V_499 ) ;
}
}
F_223 ( & V_90 -> V_499 , V_2 -> V_1094 ) ;
return V_108 ;
}
static inline int F_533 ( struct V_1 * V_2 )
{
int V_108 ;
V_2 -> V_1094 = F_222 ( & V_2 -> V_90 -> V_499 ) ;
V_108 = F_534 ( V_2 , V_953 ) ;
F_223 ( & V_2 -> V_90 -> V_499 , V_2 -> V_1094 ) ;
if ( V_108 != V_919 )
return 0 ;
return 1 ;
}
static int V_966 ( struct V_1 * V_2 )
{
F_323 ( ! V_2 -> V_5 . V_847 . V_719 ) ;
return F_533 ( V_2 ) ;
}
static int V_967 ( struct V_1 * V_2 )
{
struct V_937 * V_817 = V_2 -> V_817 ;
struct V_815 * V_816 ;
unsigned V_83 ;
F_323 ( ! V_2 -> V_828 ) ;
V_816 = & V_2 -> V_812 [ V_2 -> V_829 ] ;
V_83 = F_313 ( 8u , V_816 -> V_83 ) ;
if ( ! V_2 -> V_831 )
memcpy ( V_816 -> V_37 , V_817 -> V_818 . V_37 , V_83 ) ;
if ( V_816 -> V_83 <= 8 ) {
V_816 ++ ;
V_2 -> V_829 ++ ;
} else {
V_816 -> V_37 += V_83 ;
V_816 -> V_406 += V_83 ;
V_816 -> V_83 -= V_83 ;
}
if ( V_2 -> V_829 >= V_2 -> V_823 ) {
V_2 -> V_828 = 0 ;
if ( V_2 -> V_831 )
return 1 ;
V_2 -> V_811 = 1 ;
return F_533 ( V_2 ) ;
}
V_817 -> V_832 = V_833 ;
V_817 -> V_818 . V_834 = V_816 -> V_406 ;
if ( V_2 -> V_831 )
memcpy ( V_817 -> V_818 . V_37 , V_816 -> V_37 , F_313 ( 8u , V_816 -> V_83 ) ) ;
V_817 -> V_818 . V_83 = F_313 ( 8u , V_816 -> V_83 ) ;
V_817 -> V_818 . V_830 = V_2 -> V_831 ;
V_2 -> V_5 . V_965 = V_967 ;
return 0 ;
}
int F_535 ( struct V_1 * V_2 , struct V_937 * V_937 )
{
int V_108 ;
T_19 V_1116 ;
if ( ! F_536 ( V_413 ) && F_537 ( V_413 ) )
return - V_378 ;
if ( V_2 -> V_1117 )
F_538 ( V_1118 , & V_2 -> V_1119 , & V_1116 ) ;
if ( F_143 ( V_2 -> V_5 . V_1016 == V_1120 ) ) {
F_528 ( V_2 ) ;
F_510 ( V_2 ) ;
F_154 ( V_1108 , & V_2 -> V_301 ) ;
V_108 = - V_1121 ;
goto V_102;
}
if ( ! F_82 ( V_2 -> V_90 ) ) {
if ( F_81 ( V_2 , V_937 -> V_160 ) != 0 ) {
V_108 = - V_585 ;
goto V_102;
}
}
if ( F_143 ( V_2 -> V_5 . V_965 ) ) {
int (* F_539)( struct V_1 * ) = V_2 -> V_5 . V_965 ;
V_2 -> V_5 . V_965 = NULL ;
V_108 = F_539 ( V_2 ) ;
if ( V_108 <= 0 )
goto V_102;
} else
F_348 ( V_2 -> V_5 . V_847 . V_719 || V_2 -> V_828 ) ;
V_108 = F_527 ( V_2 ) ;
V_102:
F_492 ( V_2 ) ;
if ( V_2 -> V_1117 )
F_538 ( V_1118 , & V_1116 , NULL ) ;
return V_108 ;
}
int F_540 ( struct V_1 * V_2 , struct V_1122 * V_597 )
{
if ( V_2 -> V_5 . V_969 ) {
F_541 ( & V_2 -> V_5 . V_894 ) ;
V_2 -> V_5 . V_969 = false ;
}
V_597 -> V_1123 = F_93 ( V_2 , V_186 ) ;
V_597 -> V_1124 = F_93 ( V_2 , V_1029 ) ;
V_597 -> V_1125 = F_93 ( V_2 , V_185 ) ;
V_597 -> V_1126 = F_93 ( V_2 , V_187 ) ;
V_597 -> V_1127 = F_93 ( V_2 , V_1031 ) ;
V_597 -> V_1128 = F_93 ( V_2 , V_1030 ) ;
V_597 -> V_1129 = F_93 ( V_2 , V_1130 ) ;
V_597 -> V_1131 = F_93 ( V_2 , V_1132 ) ;
#ifdef F_56
V_597 -> V_1133 = F_93 ( V_2 , V_1032 ) ;
V_597 -> V_1134 = F_93 ( V_2 , V_1135 ) ;
V_597 -> V_1136 = F_93 ( V_2 , V_1137 ) ;
V_597 -> V_1138 = F_93 ( V_2 , V_1139 ) ;
V_597 -> V_1140 = F_93 ( V_2 , V_1141 ) ;
V_597 -> V_1142 = F_93 ( V_2 , V_1143 ) ;
V_597 -> V_1144 = F_93 ( V_2 , V_1145 ) ;
V_597 -> V_1146 = F_93 ( V_2 , V_1147 ) ;
#endif
V_597 -> V_1053 = F_413 ( V_2 ) ;
V_597 -> V_938 = F_412 ( V_2 ) ;
return 0 ;
}
int F_542 ( struct V_1 * V_2 , struct V_1122 * V_597 )
{
V_2 -> V_5 . V_912 = true ;
V_2 -> V_5 . V_969 = false ;
F_95 ( V_2 , V_186 , V_597 -> V_1123 ) ;
F_95 ( V_2 , V_1029 , V_597 -> V_1124 ) ;
F_95 ( V_2 , V_185 , V_597 -> V_1125 ) ;
F_95 ( V_2 , V_187 , V_597 -> V_1126 ) ;
F_95 ( V_2 , V_1031 , V_597 -> V_1127 ) ;
F_95 ( V_2 , V_1030 , V_597 -> V_1128 ) ;
F_95 ( V_2 , V_1130 , V_597 -> V_1129 ) ;
F_95 ( V_2 , V_1132 , V_597 -> V_1131 ) ;
#ifdef F_56
F_95 ( V_2 , V_1032 , V_597 -> V_1133 ) ;
F_95 ( V_2 , V_1135 , V_597 -> V_1134 ) ;
F_95 ( V_2 , V_1137 , V_597 -> V_1136 ) ;
F_95 ( V_2 , V_1139 , V_597 -> V_1138 ) ;
F_95 ( V_2 , V_1141 , V_597 -> V_1140 ) ;
F_95 ( V_2 , V_1143 , V_597 -> V_1142 ) ;
F_95 ( V_2 , V_1145 , V_597 -> V_1144 ) ;
F_95 ( V_2 , V_1147 , V_597 -> V_1146 ) ;
#endif
F_418 ( V_2 , V_597 -> V_1053 ) ;
F_383 ( V_2 , V_597 -> V_938 ) ;
V_2 -> V_5 . V_57 . V_58 = false ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
void F_543 ( struct V_1 * V_2 , int * V_174 , int * V_880 )
{
struct V_791 V_1148 ;
F_321 ( V_2 , & V_1148 , V_949 ) ;
* V_174 = V_1148 . V_174 ;
* V_880 = V_1148 . V_880 ;
}
int F_544 ( struct V_1 * V_2 ,
struct V_1149 * V_1150 )
{
struct V_863 V_864 ;
F_321 ( V_2 , & V_1150 -> V_1148 , V_949 ) ;
F_321 ( V_2 , & V_1150 -> V_1151 , V_1152 ) ;
F_321 ( V_2 , & V_1150 -> V_1153 , V_1154 ) ;
F_321 ( V_2 , & V_1150 -> V_1155 , V_1156 ) ;
F_321 ( V_2 , & V_1150 -> V_1157 , V_1158 ) ;
F_321 ( V_2 , & V_1150 -> V_1159 , V_1160 ) ;
F_321 ( V_2 , & V_1150 -> V_1161 , V_1162 ) ;
F_321 ( V_2 , & V_1150 -> V_1163 , V_1164 ) ;
V_64 -> V_866 ( V_2 , & V_864 ) ;
V_1150 -> V_1165 . V_875 = V_864 . V_504 ;
V_1150 -> V_1165 . V_876 = V_864 . V_71 ;
V_64 -> V_865 ( V_2 , & V_864 ) ;
V_1150 -> V_1166 . V_875 = V_864 . V_504 ;
V_1150 -> V_1166 . V_876 = V_864 . V_71 ;
V_1150 -> V_109 = F_55 ( V_2 ) ;
V_1150 -> V_70 = V_2 -> V_5 . V_70 ;
V_1150 -> V_93 = F_53 ( V_2 ) ;
V_1150 -> V_143 = F_70 ( V_2 ) ;
V_1150 -> V_160 = F_84 ( V_2 ) ;
V_1150 -> V_119 = V_2 -> V_5 . V_119 ;
V_1150 -> V_30 = F_18 ( V_2 ) ;
memset ( V_1150 -> V_1167 , 0 , sizeof V_1150 -> V_1167 ) ;
if ( V_2 -> V_5 . V_621 . V_58 && ! V_2 -> V_5 . V_621 . V_622 )
F_153 ( V_2 -> V_5 . V_621 . V_16 ,
( unsigned long * ) V_1150 -> V_1167 ) ;
return 0 ;
}
int F_545 ( struct V_1 * V_2 ,
struct V_1168 * V_1016 )
{
F_510 ( V_2 ) ;
if ( V_2 -> V_5 . V_1016 == V_1017 &&
V_2 -> V_5 . V_1109 . V_1110 )
V_1016 -> V_1016 = V_1107 ;
else
V_1016 -> V_1016 = V_2 -> V_5 . V_1016 ;
return 0 ;
}
int F_546 ( struct V_1 * V_2 ,
struct V_1168 * V_1016 )
{
if ( ! F_259 ( V_2 ) &&
V_1016 -> V_1016 != V_1107 )
return - V_585 ;
if ( V_1016 -> V_1016 == V_1169 ) {
V_2 -> V_5 . V_1016 = V_1087 ;
F_153 ( V_1170 , & V_2 -> V_5 . V_598 -> V_1171 ) ;
} else
V_2 -> V_5 . V_1016 = V_1016 -> V_1016 ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
int F_547 ( struct V_1 * V_2 , V_843 V_1172 , int V_1173 ,
int V_1174 , bool V_60 , T_1 V_51 )
{
struct V_805 * V_806 = & V_2 -> V_5 . V_894 ;
int V_97 ;
F_411 ( V_2 ) ;
V_97 = F_548 ( V_806 , V_1172 , V_1173 , V_1174 ,
V_60 , V_51 ) ;
if ( V_97 )
return V_917 ;
F_418 ( V_2 , V_806 -> V_904 ) ;
F_383 ( V_2 , V_806 -> V_903 ) ;
F_27 ( V_56 , V_2 ) ;
return V_919 ;
}
int F_549 ( struct V_1 * V_2 ,
struct V_1149 * V_1150 )
{
struct V_31 V_1175 ;
int V_1176 = 0 ;
int V_1177 , V_1178 , V_351 ;
struct V_863 V_864 ;
if ( ! F_71 ( V_2 ) && ( V_1150 -> V_143 & V_127 ) )
return - V_585 ;
V_864 . V_504 = V_1150 -> V_1165 . V_875 ;
V_864 . V_71 = V_1150 -> V_1165 . V_876 ;
V_64 -> V_868 ( V_2 , & V_864 ) ;
V_864 . V_504 = V_1150 -> V_1166 . V_875 ;
V_864 . V_71 = V_1150 -> V_1166 . V_876 ;
V_64 -> V_867 ( V_2 , & V_864 ) ;
V_2 -> V_5 . V_70 = V_1150 -> V_70 ;
V_1176 |= F_53 ( V_2 ) != V_1150 -> V_93 ;
V_2 -> V_5 . V_93 = V_1150 -> V_93 ;
F_48 ( V_158 , ( V_159 * ) & V_2 -> V_5 . V_105 ) ;
F_81 ( V_2 , V_1150 -> V_160 ) ;
V_1176 |= V_2 -> V_5 . V_119 != V_1150 -> V_119 ;
V_64 -> F_99 ( V_2 , V_1150 -> V_119 ) ;
V_1175 . V_37 = V_1150 -> V_30 ;
V_1175 . V_39 = true ;
F_19 ( V_2 , & V_1175 ) ;
V_1176 |= F_55 ( V_2 ) != V_1150 -> V_109 ;
V_64 -> V_125 ( V_2 , V_1150 -> V_109 ) ;
V_2 -> V_5 . V_109 = V_1150 -> V_109 ;
V_1176 |= F_70 ( V_2 ) != V_1150 -> V_143 ;
V_64 -> V_154 ( V_2 , V_1150 -> V_143 ) ;
if ( V_1150 -> V_143 & V_127 )
F_67 ( V_2 ) ;
V_351 = F_222 ( & V_2 -> V_90 -> V_499 ) ;
if ( ! F_50 ( V_2 ) && F_51 ( V_2 ) ) {
F_45 ( V_2 , V_2 -> V_5 . V_92 , F_53 ( V_2 ) ) ;
V_1176 = 1 ;
}
F_223 ( & V_2 -> V_90 -> V_499 , V_351 ) ;
if ( V_1176 )
F_60 ( V_2 ) ;
V_1178 = V_601 ;
V_1177 = F_550 (
( const unsigned long * ) V_1150 -> V_1167 , V_1178 ) ;
if ( V_1177 < V_1178 ) {
F_250 ( V_2 , V_1177 , false ) ;
F_114 ( L_29 , V_1177 ) ;
}
F_320 ( V_2 , & V_1150 -> V_1148 , V_949 ) ;
F_320 ( V_2 , & V_1150 -> V_1151 , V_1152 ) ;
F_320 ( V_2 , & V_1150 -> V_1153 , V_1154 ) ;
F_320 ( V_2 , & V_1150 -> V_1155 , V_1156 ) ;
F_320 ( V_2 , & V_1150 -> V_1157 , V_1158 ) ;
F_320 ( V_2 , & V_1150 -> V_1159 , V_1160 ) ;
F_320 ( V_2 , & V_1150 -> V_1161 , V_1162 ) ;
F_320 ( V_2 , & V_1150 -> V_1163 , V_1164 ) ;
F_248 ( V_2 ) ;
if ( F_551 ( V_2 ) && F_413 ( V_2 ) == 0xfff0 &&
V_1150 -> V_1148 . V_869 == 0xf000 && V_1150 -> V_1148 . V_876 == 0xffff0000 &&
! F_414 ( V_2 ) )
V_2 -> V_5 . V_1016 = V_1107 ;
F_27 ( V_56 , V_2 ) ;
return 0 ;
}
int F_552 ( struct V_1 * V_2 ,
struct V_1179 * V_1180 )
{
unsigned long V_938 ;
int V_3 , V_108 ;
if ( V_1180 -> V_726 & ( V_1181 | V_1182 ) ) {
V_108 = - V_1183 ;
if ( V_2 -> V_5 . V_57 . V_58 )
goto V_102;
if ( V_1180 -> V_726 & V_1181 )
F_28 ( V_2 , V_946 ) ;
else
F_28 ( V_2 , V_1184 ) ;
}
V_938 = F_412 ( V_2 ) ;
V_2 -> V_162 = V_1180 -> V_726 ;
if ( ! ( V_2 -> V_162 & V_1185 ) )
V_2 -> V_162 = 0 ;
if ( V_2 -> V_162 & V_163 ) {
for ( V_3 = 0 ; V_3 < V_1099 ; ++ V_3 )
V_2 -> V_5 . V_175 [ V_3 ] = V_1180 -> V_5 . V_1186 [ V_3 ] ;
V_2 -> V_5 . V_167 = V_1180 -> V_5 . V_1186 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1099 ; V_3 ++ )
V_2 -> V_5 . V_175 [ V_3 ] = V_2 -> V_5 . V_174 [ V_3 ] ;
}
F_87 ( V_2 ) ;
if ( V_2 -> V_162 & V_941 )
V_2 -> V_5 . V_945 = F_413 ( V_2 ) +
F_367 ( V_2 , V_949 ) ;
F_383 ( V_2 , V_938 ) ;
V_64 -> V_1187 ( V_2 ) ;
V_108 = 0 ;
V_102:
return V_108 ;
}
int F_553 ( struct V_1 * V_2 ,
struct V_1188 * V_1161 )
{
unsigned long V_1189 = V_1161 -> V_1190 ;
T_6 V_406 ;
int V_351 ;
V_351 = F_222 ( & V_2 -> V_90 -> V_499 ) ;
V_406 = F_327 ( V_2 , V_1189 , NULL ) ;
F_223 ( & V_2 -> V_90 -> V_499 , V_351 ) ;
V_1161 -> V_1191 = V_406 ;
V_1161 -> V_1192 = V_406 != V_88 ;
V_1161 -> V_1193 = 1 ;
V_1161 -> V_1194 = 0 ;
return 0 ;
}
int F_554 ( struct V_1 * V_2 , struct V_1195 * V_1196 )
{
struct V_651 * V_650 =
& V_2 -> V_5 . V_644 . V_645 -> V_650 ;
memcpy ( V_1196 -> V_1197 , V_650 -> V_1198 , 128 ) ;
V_1196 -> V_1199 = V_650 -> V_1200 ;
V_1196 -> V_1201 = V_650 -> V_1202 ;
V_1196 -> V_1203 = V_650 -> V_1204 ;
V_1196 -> V_1205 = V_650 -> V_1206 ;
V_1196 -> V_1207 = V_650 -> V_1053 ;
V_1196 -> V_1208 = V_650 -> V_1209 ;
memcpy ( V_1196 -> V_1210 , V_650 -> V_1211 , sizeof V_650 -> V_1211 ) ;
return 0 ;
}
int F_555 ( struct V_1 * V_2 , struct V_1195 * V_1196 )
{
struct V_651 * V_650 =
& V_2 -> V_5 . V_644 . V_645 -> V_650 ;
memcpy ( V_650 -> V_1198 , V_1196 -> V_1197 , 128 ) ;
V_650 -> V_1200 = V_1196 -> V_1199 ;
V_650 -> V_1202 = V_1196 -> V_1201 ;
V_650 -> V_1204 = V_1196 -> V_1203 ;
V_650 -> V_1206 = V_1196 -> V_1205 ;
V_650 -> V_1053 = V_1196 -> V_1207 ;
V_650 -> V_1209 = V_1196 -> V_1208 ;
memcpy ( V_650 -> V_1211 , V_1196 -> V_1210 , sizeof V_650 -> V_1211 ) ;
return 0 ;
}
int F_556 ( struct V_1 * V_2 )
{
int V_63 ;
V_63 = F_557 ( & V_2 -> V_5 . V_644 ) ;
if ( V_63 )
return V_63 ;
F_558 ( & V_2 -> V_5 . V_644 ) ;
V_2 -> V_5 . V_130 = V_136 ;
V_2 -> V_5 . V_109 |= V_116 ;
return 0 ;
}
static void F_559 ( struct V_1 * V_2 )
{
F_560 ( & V_2 -> V_5 . V_644 ) ;
}
void F_401 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1212 )
return;
F_65 ( V_2 ) ;
V_2 -> V_1212 = 1 ;
F_561 () ;
F_562 ( & V_2 -> V_5 . V_644 ) ;
F_563 ( 1 ) ;
}
void F_244 ( struct V_1 * V_2 )
{
F_65 ( V_2 ) ;
if ( ! V_2 -> V_1212 )
return;
V_2 -> V_1212 = 0 ;
F_564 ( & V_2 -> V_5 . V_644 ) ;
F_565 () ;
++ V_2 -> V_68 . V_1213 ;
F_27 ( V_1079 , V_2 ) ;
F_563 ( 0 ) ;
}
void F_566 ( struct V_1 * V_2 )
{
F_194 ( V_2 ) ;
F_567 ( V_2 -> V_5 . V_588 ) ;
F_559 ( V_2 ) ;
V_64 -> V_1214 ( V_2 ) ;
}
struct V_1 * F_568 ( struct V_90 * V_90 ,
unsigned int V_1215 )
{
if ( F_131 () && F_126 ( & V_90 -> V_263 ) != 0 )
F_361 ( V_845
L_30
L_31 ) ;
return V_64 -> V_1216 ( V_90 , V_1215 ) ;
}
int F_569 ( struct V_1 * V_2 )
{
int V_108 ;
V_2 -> V_5 . V_346 . V_1217 = 1 ;
V_108 = V_589 ( V_2 ) ;
if ( V_108 )
return V_108 ;
F_570 ( V_2 ) ;
F_571 ( V_2 ) ;
V_593 ( V_2 ) ;
return V_108 ;
}
int F_572 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_31 V_21 ;
struct V_90 * V_90 = V_2 -> V_90 ;
V_108 = V_589 ( V_2 ) ;
if ( V_108 )
return V_108 ;
V_21 . V_37 = 0x0 ;
V_21 . V_132 = V_1218 ;
V_21 . V_39 = true ;
F_129 ( V_2 , & V_21 ) ;
V_593 ( V_2 ) ;
F_167 ( & V_90 -> V_5 . V_328 ,
V_329 ) ;
return V_108 ;
}
void F_573 ( struct V_1 * V_2 )
{
int V_108 ;
V_2 -> V_5 . V_6 . V_407 = 0 ;
V_108 = V_589 ( V_2 ) ;
F_323 ( V_108 ) ;
F_506 ( V_2 ) ;
V_593 ( V_2 ) ;
F_559 ( V_2 ) ;
V_64 -> V_1214 ( V_2 ) ;
}
void F_570 ( struct V_1 * V_2 )
{
F_148 ( & V_2 -> V_5 . V_76 , 0 ) ;
V_2 -> V_5 . V_629 = 0 ;
V_2 -> V_5 . V_628 = false ;
memset ( V_2 -> V_5 . V_174 , 0 , sizeof( V_2 -> V_5 . V_174 ) ) ;
V_2 -> V_5 . V_165 = V_178 ;
F_86 ( V_2 ) ;
V_2 -> V_5 . V_166 = V_180 ;
F_87 ( V_2 ) ;
F_27 ( V_56 , V_2 ) ;
V_2 -> V_5 . V_6 . V_407 = 0 ;
V_2 -> V_5 . V_411 . V_407 = 0 ;
F_194 ( V_2 ) ;
F_59 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1083 = false ;
F_574 ( V_2 ) ;
memset ( V_2 -> V_5 . V_597 , 0 , sizeof( V_2 -> V_5 . V_597 ) ) ;
V_2 -> V_5 . V_105 = ~ 0 ;
V_2 -> V_5 . V_106 = ~ 0 ;
V_64 -> V_1219 ( V_2 ) ;
}
void F_575 ( struct V_1 * V_2 , unsigned int V_40 )
{
struct V_791 V_1148 ;
F_321 ( V_2 , & V_1148 , V_949 ) ;
V_1148 . V_869 = V_40 << 8 ;
V_1148 . V_876 = V_40 << 12 ;
F_320 ( V_2 , & V_1148 , V_949 ) ;
F_418 ( V_2 , 0 ) ;
}
int F_576 ( void * V_586 )
{
struct V_90 * V_90 ;
struct V_1 * V_2 ;
int V_3 ;
int V_97 ;
T_2 V_1220 ;
T_2 V_1221 = 0 ;
bool V_1222 , V_1223 = false ;
F_14 () ;
V_97 = V_64 -> V_1224 ( V_586 ) ;
if ( V_97 != 0 )
return V_97 ;
V_1220 = F_159 () ;
V_1222 = ! F_131 () ;
F_444 (kvm, &vm_list, vm_list) {
F_152 (i, vcpu, kvm) {
if ( ! V_1222 && V_2 -> V_23 == F_8 () )
F_153 ( V_300 , & V_2 -> V_301 ) ;
if ( V_1222 && V_2 -> V_5 . V_592 > V_1220 ) {
V_1223 = true ;
if ( V_2 -> V_5 . V_592 > V_1221 )
V_1221 = V_2 -> V_5 . V_592 ;
}
}
}
if ( V_1223 ) {
T_2 V_1225 = V_1221 - V_1220 ;
V_298 = true ;
F_444 (kvm, &vm_list, vm_list) {
F_152 (i, vcpu, kvm) {
V_2 -> V_5 . V_590 += V_1225 ;
V_2 -> V_5 . V_592 = V_1220 ;
F_153 ( V_266 ,
& V_2 -> V_301 ) ;
}
V_90 -> V_5 . V_278 = 0 ;
V_90 -> V_5 . V_280 = 0 ;
}
}
return 0 ;
}
void F_577 ( void * V_586 )
{
V_64 -> V_1226 ( V_586 ) ;
F_17 ( V_586 ) ;
}
int F_578 ( void )
{
return V_64 -> V_1227 () ;
}
void F_579 ( void )
{
V_64 -> V_1228 () ;
}
void F_580 ( void * V_1229 )
{
V_64 -> V_1230 ( V_1229 ) ;
}
bool F_581 ( struct V_1 * V_2 )
{
return F_82 ( V_2 -> V_90 ) == ( V_2 -> V_5 . V_598 != NULL ) ;
}
int F_582 ( struct V_1 * V_2 )
{
struct V_376 * V_376 ;
struct V_90 * V_90 ;
int V_108 ;
F_323 ( V_2 -> V_90 == NULL ) ;
V_90 = V_2 -> V_90 ;
V_2 -> V_5 . V_1109 . V_1110 = false ;
V_2 -> V_5 . V_894 . V_820 = & V_1231 ;
if ( ! F_82 ( V_90 ) || F_551 ( V_2 ) )
V_2 -> V_5 . V_1016 = V_1107 ;
else
V_2 -> V_5 . V_1016 = V_1120 ;
V_376 = F_583 ( V_663 | V_1232 ) ;
if ( ! V_376 ) {
V_108 = - V_378 ;
goto V_1233;
}
V_2 -> V_5 . V_850 = F_584 ( V_376 ) ;
F_123 ( V_2 , V_986 ) ;
V_108 = F_585 ( V_2 ) ;
if ( V_108 < 0 )
goto V_1234;
if ( F_82 ( V_90 ) ) {
V_108 = F_586 ( V_2 ) ;
if ( V_108 < 0 )
goto V_1235;
} else
F_587 ( & V_1236 ) ;
V_2 -> V_5 . V_365 = F_269 ( V_454 * sizeof( T_2 ) * 4 ,
V_663 ) ;
if ( ! V_2 -> V_5 . V_365 ) {
V_108 = - V_378 ;
goto V_1237;
}
V_2 -> V_5 . V_357 = V_454 ;
if ( ! F_588 ( & V_2 -> V_5 . V_588 , V_663 ) ) {
V_108 = - V_378 ;
goto V_1238;
}
V_108 = F_556 ( V_2 ) ;
if ( V_108 )
goto V_1239;
V_2 -> V_5 . V_270 = 0x0 ;
V_2 -> V_5 . V_312 = false ;
V_2 -> V_5 . V_139 = 0 ;
V_2 -> V_5 . V_647 = V_1240 + V_648 ;
F_1 ( V_2 ) ;
F_589 ( V_2 ) ;
return 0 ;
V_1239:
F_567 ( V_2 -> V_5 . V_588 ) ;
V_1238:
F_179 ( V_2 -> V_5 . V_365 ) ;
V_1237:
F_590 ( V_2 ) ;
V_1235:
F_591 ( V_2 ) ;
V_1234:
F_592 ( ( unsigned long ) V_2 -> V_5 . V_850 ) ;
V_1233:
return V_108 ;
}
void F_593 ( struct V_1 * V_2 )
{
int V_351 ;
F_594 ( V_2 ) ;
F_179 ( V_2 -> V_5 . V_365 ) ;
F_590 ( V_2 ) ;
V_351 = F_222 ( & V_2 -> V_90 -> V_499 ) ;
F_591 ( V_2 ) ;
F_223 ( & V_2 -> V_90 -> V_499 , V_351 ) ;
F_592 ( ( unsigned long ) V_2 -> V_5 . V_850 ) ;
if ( ! F_82 ( V_2 -> V_90 ) )
F_595 ( & V_1236 ) ;
}
int F_596 ( struct V_90 * V_90 , unsigned long type )
{
if ( type )
return - V_585 ;
F_597 ( & V_90 -> V_5 . V_1241 ) ;
F_597 ( & V_90 -> V_5 . V_1242 ) ;
F_597 ( & V_90 -> V_5 . V_1243 ) ;
F_148 ( & V_90 -> V_5 . V_1244 , 0 ) ;
F_153 ( V_741 , & V_90 -> V_5 . V_1245 ) ;
F_153 ( V_1246 ,
& V_90 -> V_5 . V_1245 ) ;
F_598 ( & V_90 -> V_5 . V_276 ) ;
F_599 ( & V_90 -> V_5 . V_1247 ) ;
F_600 ( & V_90 -> V_5 . V_291 ) ;
F_147 ( V_90 ) ;
F_601 ( & V_90 -> V_5 . V_326 , F_163 ) ;
F_601 ( & V_90 -> V_5 . V_328 , F_168 ) ;
return 0 ;
}
static void F_602 ( struct V_1 * V_2 )
{
int V_108 ;
V_108 = V_589 ( V_2 ) ;
F_323 ( V_108 ) ;
F_506 ( V_2 ) ;
V_593 ( V_2 ) ;
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
F_206 ( & V_90 -> V_469 ) ;
for ( V_3 = 0 ; V_3 < F_126 ( & V_90 -> V_263 ) ; V_3 ++ )
V_90 -> V_1248 [ V_3 ] = NULL ;
F_148 ( & V_90 -> V_263 , 0 ) ;
F_207 ( & V_90 -> V_469 ) ;
}
void F_604 ( struct V_90 * V_90 )
{
F_605 ( & V_90 -> V_5 . V_328 ) ;
F_605 ( & V_90 -> V_5 . V_326 ) ;
F_606 ( V_90 ) ;
F_607 ( V_90 ) ;
}
void F_608 ( struct V_90 * V_90 )
{
if ( V_413 -> V_1249 == V_90 -> V_1249 ) {
struct V_1250 V_1251 ;
memset ( & V_1251 , 0 , sizeof( V_1251 ) ) ;
V_1251 . V_10 = V_1252 ;
F_609 ( V_90 , & V_1251 ) ;
V_1251 . V_10 = V_1253 ;
F_609 ( V_90 , & V_1251 ) ;
V_1251 . V_10 = V_1254 ;
F_609 ( V_90 , & V_1251 ) ;
}
F_610 ( V_90 ) ;
F_179 ( V_90 -> V_5 . V_753 ) ;
F_179 ( V_90 -> V_5 . V_1255 ) ;
F_603 ( V_90 ) ;
if ( V_90 -> V_5 . V_1256 )
F_611 ( V_90 -> V_5 . V_1256 ) ;
if ( V_90 -> V_5 . V_1257 )
F_611 ( V_90 -> V_5 . V_1257 ) ;
F_179 ( F_612 ( V_90 -> V_5 . V_1258 , 1 ) ) ;
}
void F_613 ( struct V_90 * V_90 , struct V_729 * free ,
struct V_729 * V_1259 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1260 ; ++ V_3 ) {
if ( ! V_1259 || free -> V_5 . V_1261 [ V_3 ] != V_1259 -> V_5 . V_1261 [ V_3 ] ) {
F_614 ( free -> V_5 . V_1261 [ V_3 ] ) ;
free -> V_5 . V_1261 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1259 || free -> V_5 . V_1262 [ V_3 - 1 ] !=
V_1259 -> V_5 . V_1262 [ V_3 - 1 ] ) {
F_614 ( free -> V_5 . V_1262 [ V_3 - 1 ] ) ;
free -> V_5 . V_1262 [ V_3 - 1 ] = NULL ;
}
}
}
int F_615 ( struct V_90 * V_90 , struct V_729 * V_10 ,
unsigned long V_1263 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1260 ; ++ V_3 ) {
unsigned long V_1264 ;
int V_1265 ;
int V_742 = V_3 + 1 ;
V_1265 = F_616 ( V_10 -> V_1266 + V_1263 - 1 ,
V_10 -> V_1266 , V_742 ) + 1 ;
V_10 -> V_5 . V_1261 [ V_3 ] =
F_617 ( V_1265 * sizeof( * V_10 -> V_5 . V_1261 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1261 [ V_3 ] )
goto V_379;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1262 [ V_3 - 1 ] = F_617 ( V_1265 *
sizeof( * V_10 -> V_5 . V_1262 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1262 [ V_3 - 1 ] )
goto V_379;
if ( V_10 -> V_1266 & ( F_618 ( V_742 ) - 1 ) )
V_10 -> V_5 . V_1262 [ V_3 - 1 ] [ 0 ] . V_1267 = 1 ;
if ( ( V_10 -> V_1266 + V_1263 ) & ( F_618 ( V_742 ) - 1 ) )
V_10 -> V_5 . V_1262 [ V_3 - 1 ] [ V_1265 - 1 ] . V_1267 = 1 ;
V_1264 = V_10 -> V_1268 >> V_95 ;
if ( ( V_10 -> V_1266 ^ V_1264 ) & ( F_618 ( V_742 ) - 1 ) ||
! F_619 () ) {
unsigned long V_783 ;
for ( V_783 = 0 ; V_783 < V_1265 ; ++ V_783 )
V_10 -> V_5 . V_1262 [ V_3 - 1 ] [ V_783 ] . V_1267 = 1 ;
}
}
return 0 ;
V_379:
for ( V_3 = 0 ; V_3 < V_1260 ; ++ V_3 ) {
F_614 ( V_10 -> V_5 . V_1261 [ V_3 ] ) ;
V_10 -> V_5 . V_1261 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_614 ( V_10 -> V_5 . V_1262 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1262 [ V_3 - 1 ] = NULL ;
}
return - V_378 ;
}
void F_620 ( struct V_90 * V_90 )
{
F_621 ( V_90 ) ;
}
int F_622 ( struct V_90 * V_90 ,
struct V_729 * V_730 ,
struct V_1250 * V_1251 ,
enum V_1269 V_1270 )
{
if ( ( V_730 -> V_1215 >= V_553 ) && ( V_1270 == V_1271 ) ) {
unsigned long V_1268 ;
V_1268 = F_623 ( NULL , 0 , V_730 -> V_1263 * V_96 ,
V_1272 | V_1273 ,
V_1274 | V_1275 , 0 ) ;
if ( F_177 ( ( void * ) V_1268 ) )
return F_178 ( ( void * ) V_1268 ) ;
V_730 -> V_1268 = V_1268 ;
}
return 0 ;
}
void F_624 ( struct V_90 * V_90 ,
struct V_1250 * V_1251 ,
const struct V_729 * V_838 ,
enum V_1269 V_1270 )
{
int V_1276 = 0 ;
if ( ( V_1251 -> V_10 >= V_553 ) && ( V_1270 == V_1277 ) ) {
int V_97 ;
V_97 = F_625 ( V_838 -> V_1268 ,
V_838 -> V_1263 * V_96 ) ;
if ( V_97 < 0 )
F_10 ( V_845
L_32
L_33 ) ;
}
if ( ! V_90 -> V_5 . V_702 )
V_1276 = F_626 ( V_90 ) ;
if ( V_1276 )
F_278 ( V_90 , V_1276 ) ;
if ( ( V_1270 != V_1277 ) && ( V_1251 -> V_273 & V_1278 ) )
F_627 ( V_90 , V_1251 -> V_10 ) ;
}
void F_628 ( struct V_90 * V_90 )
{
F_629 ( V_90 ) ;
}
void F_630 ( struct V_90 * V_90 ,
struct V_729 * V_10 )
{
F_629 ( V_90 ) ;
}
int F_631 ( struct V_1 * V_2 )
{
if ( F_415 ( V_2 ) && V_64 -> V_1064 )
V_64 -> V_1064 ( V_2 , false ) ;
return ( V_2 -> V_5 . V_1016 == V_1107 &&
! V_2 -> V_5 . V_6 . V_1083 )
|| ! F_632 ( & V_2 -> V_1279 . V_1280 )
|| F_633 ( V_2 )
|| V_2 -> V_5 . V_1109 . V_1110
|| F_126 ( & V_2 -> V_5 . V_76 ) ||
( F_491 ( V_2 ) &&
F_490 ( V_2 ) ) ;
}
int F_634 ( struct V_1 * V_2 )
{
return F_635 ( V_2 ) == V_1093 ;
}
int F_491 ( struct V_1 * V_2 )
{
return V_64 -> V_1066 ( V_2 ) ;
}
bool F_636 ( struct V_1 * V_2 , unsigned long V_1281 )
{
unsigned long V_1282 = F_413 ( V_2 ) +
F_367 ( V_2 , V_949 ) ;
return V_1282 == V_1281 ;
}
unsigned long F_412 ( struct V_1 * V_2 )
{
unsigned long V_938 ;
V_938 = V_64 -> V_939 ( V_2 ) ;
if ( V_2 -> V_162 & V_941 )
V_938 &= ~ V_940 ;
return V_938 ;
}
void F_383 ( struct V_1 * V_2 , unsigned long V_938 )
{
if ( V_2 -> V_162 & V_941 &&
F_636 ( V_2 , V_2 -> V_5 . V_945 ) )
V_938 |= V_940 ;
V_64 -> V_1283 ( V_2 , V_938 ) ;
F_27 ( V_56 , V_2 ) ;
}
void F_637 ( struct V_1 * V_2 , struct V_1284 * V_323 )
{
int V_108 ;
if ( ( V_2 -> V_5 . V_75 . V_930 != V_323 -> V_5 . V_930 ) ||
V_323 -> V_1285 )
return;
V_108 = F_513 ( V_2 ) ;
if ( F_143 ( V_108 ) )
return;
if ( ! V_2 -> V_5 . V_75 . V_930 &&
V_323 -> V_5 . V_93 != V_2 -> V_5 . V_75 . V_1286 ( V_2 ) )
return;
V_2 -> V_5 . V_75 . V_1287 ( V_2 , V_323 -> V_798 , 0 , true ) ;
}
static inline T_1 F_638 ( T_5 V_91 )
{
return F_639 ( V_91 & 0xffffffff , F_640 ( V_4 ) ) ;
}
static inline T_1 F_641 ( T_1 V_1288 )
{
return ( V_1288 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_642 ( struct V_1 * V_2 , T_5 V_91 )
{
T_1 V_1288 = F_638 ( V_91 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1288 ] != ~ 0 )
V_1288 = F_641 ( V_1288 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1288 ] = V_91 ;
}
static T_1 F_643 ( struct V_1 * V_2 , T_5 V_91 )
{
int V_3 ;
T_1 V_1288 = F_638 ( V_91 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1288 ] != V_91 &&
V_2 -> V_5 . V_6 . V_7 [ V_1288 ] != ~ 0 ) ; V_3 ++ )
V_1288 = F_641 ( V_1288 ) ;
return V_1288 ;
}
bool F_644 ( struct V_1 * V_2 , T_5 V_91 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_643 ( V_2 , V_91 ) ] == V_91 ;
}
static void F_645 ( struct V_1 * V_2 , T_5 V_91 )
{
T_1 V_3 , V_783 , V_1289 ;
V_3 = V_783 = F_643 ( V_2 , V_91 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_783 = F_641 ( V_783 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_783 ] == ~ 0 )
return;
V_1289 = F_638 ( V_2 -> V_5 . V_6 . V_7 [ V_783 ] ) ;
} while ( ( V_3 <= V_783 ) ? ( V_3 < V_1289 && V_1289 <= V_783 ) : ( V_3 < V_1289 || V_1289 <= V_783 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_783 ] ;
V_3 = V_783 ;
}
}
static int F_646 ( struct V_1 * V_2 , T_1 V_173 )
{
return F_162 ( V_2 -> V_90 , & V_2 -> V_5 . V_6 . V_37 , & V_173 ,
sizeof( V_173 ) ) ;
}
void F_647 ( struct V_1 * V_2 ,
struct V_1284 * V_323 )
{
struct V_66 V_67 ;
F_648 ( V_323 -> V_5 . V_1290 , V_323 -> V_798 ) ;
F_642 ( V_2 , V_323 -> V_5 . V_91 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_407 & V_408 ) ||
( V_2 -> V_5 . V_6 . V_409 &&
V_64 -> V_79 ( V_2 ) == 0 ) )
F_27 ( V_1082 , V_2 ) ;
else if ( ! F_646 ( V_2 , V_1291 ) ) {
V_67 . V_40 = V_41 ;
V_67 . V_895 = true ;
V_67 . V_51 = 0 ;
V_67 . V_72 = false ;
V_67 . V_71 = V_323 -> V_5 . V_1290 ;
F_32 ( V_2 , & V_67 ) ;
}
}
void F_649 ( struct V_1 * V_2 ,
struct V_1284 * V_323 )
{
struct V_66 V_67 ;
F_650 ( V_323 -> V_5 . V_1290 , V_323 -> V_798 ) ;
if ( V_323 -> V_1285 )
V_323 -> V_5 . V_1290 = ~ 0 ;
else
F_645 ( V_2 , V_323 -> V_5 . V_91 ) ;
if ( ( V_2 -> V_5 . V_6 . V_407 & V_408 ) &&
! F_646 ( V_2 , V_1292 ) ) {
V_67 . V_40 = V_41 ;
V_67 . V_895 = true ;
V_67 . V_51 = 0 ;
V_67 . V_72 = false ;
V_67 . V_71 = V_323 -> V_5 . V_1290 ;
F_32 ( V_2 , & V_67 ) ;
}
V_2 -> V_5 . V_6 . V_1083 = false ;
V_2 -> V_5 . V_1016 = V_1107 ;
}
bool F_651 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_407 & V_408 ) )
return true ;
else
return ! F_493 ( V_2 ) &&
V_64 -> V_1066 ( V_2 ) ;
}
void F_652 ( struct V_90 * V_90 )
{
F_37 ( & V_90 -> V_5 . V_1244 ) ;
}
void F_653 ( struct V_90 * V_90 )
{
F_654 ( & V_90 -> V_5 . V_1244 ) ;
}
bool F_236 ( struct V_90 * V_90 )
{
return F_126 ( & V_90 -> V_5 . V_1244 ) ;
}
