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
F_13 ( V_10 >= V_27 ) ;
if ( V_10 >= V_15 . V_16 )
V_15 . V_16 = V_10 + 1 ;
V_15 . V_19 [ V_10 ] = V_21 ;
F_14 () ;
}
static void F_15 ( void )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_15 . V_16 ; ++ V_3 )
F_7 ( V_3 , V_15 . V_19 [ V_3 ] ) ;
}
int F_16 ( unsigned V_10 , T_2 V_22 , T_2 V_28 )
{
unsigned int V_23 = F_8 () ;
struct V_11 * V_24 = F_9 ( V_25 , V_23 ) ;
int V_29 ;
if ( ( ( V_22 ^ V_24 -> V_14 [ V_10 ] . V_18 ) & V_28 ) == 0 )
return 0 ;
V_24 -> V_14 [ V_10 ] . V_18 = V_22 ;
V_29 = F_17 ( V_15 . V_19 [ V_10 ] , V_22 ) ;
if ( V_29 )
return 1 ;
if ( ! V_24 -> V_20 ) {
V_24 -> V_9 . V_30 = F_3 ;
F_18 ( & V_24 -> V_9 ) ;
V_24 -> V_20 = true ;
}
return 0 ;
}
static void F_19 ( void )
{
unsigned int V_23 = F_8 () ;
struct V_11 * V_24 = F_9 ( V_25 , V_23 ) ;
if ( V_24 -> V_20 )
F_3 ( & V_24 -> V_9 ) ;
}
T_2 F_20 ( struct V_1 * V_2 )
{
return V_2 -> V_5 . V_31 ;
}
int F_21 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
T_2 V_34 = V_2 -> V_5 . V_31 &
( V_35 | V_36 ) ;
T_2 V_37 = V_33 -> V_38 &
( V_35 | V_36 ) ;
T_2 V_39 = ( ( ~ 0ULL ) << F_22 ( V_2 ) ) |
0x2ff | ( F_23 ( V_2 ) ? 0 : V_36 ) ;
if ( ! V_33 -> V_40 &&
( ( V_33 -> V_38 & V_39 ) != 0 ||
V_37 == V_36 ||
( V_37 == V_35 &&
V_34 == ( V_35 | V_36 ) ) ||
( V_37 == ( V_35 | V_36 ) &&
V_34 == 0 ) ) )
return 1 ;
F_24 ( V_2 , V_33 -> V_38 ) ;
return 0 ;
}
T_3 T_4 void F_25 ( void )
{
F_26 () ;
}
static int F_27 ( int V_41 )
{
switch ( V_41 ) {
case V_42 :
return V_43 ;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
return V_49 ;
default:
break;
}
return V_50 ;
}
static int F_28 ( int V_41 )
{
unsigned int V_28 ;
if ( F_29 ( V_41 > 31 || V_41 == V_51 ) )
return V_52 ;
V_28 = 1 << V_41 ;
if ( V_28 & ( ( 1 << V_53 ) | ( 1 << V_54 ) | ( 1 << V_55 ) ) )
return V_56 ;
if ( V_28 & ( ( 1 << V_57 ) | ( 1 << V_58 ) ) )
return V_59 ;
return V_60 ;
}
static void F_30 ( struct V_1 * V_2 ,
unsigned V_16 , bool V_61 , T_1 V_62 ,
bool V_63 )
{
T_1 V_64 ;
int V_65 , V_66 ;
F_31 ( V_67 , V_2 ) ;
if ( ! V_2 -> V_5 . V_68 . V_69 ) {
V_70:
V_2 -> V_5 . V_68 . V_69 = true ;
V_2 -> V_5 . V_68 . V_71 = V_61 ;
V_2 -> V_5 . V_68 . V_16 = V_16 ;
V_2 -> V_5 . V_68 . V_62 = V_62 ;
V_2 -> V_5 . V_68 . V_63 = V_63 ;
return;
}
V_64 = V_2 -> V_5 . V_68 . V_16 ;
if ( V_64 == V_57 ) {
F_31 ( V_72 , V_2 ) ;
return;
}
V_65 = F_27 ( V_64 ) ;
V_66 = F_27 ( V_16 ) ;
if ( ( V_65 == V_49 && V_66 == V_49 )
|| ( V_65 == V_43 && V_66 != V_50 ) ) {
V_2 -> V_5 . V_68 . V_69 = true ;
V_2 -> V_5 . V_68 . V_71 = true ;
V_2 -> V_5 . V_68 . V_16 = V_57 ;
V_2 -> V_5 . V_68 . V_62 = 0 ;
} else
goto V_70;
}
void F_32 ( struct V_1 * V_2 , unsigned V_16 )
{
F_30 ( V_2 , V_16 , false , 0 , false ) ;
}
void F_33 ( struct V_1 * V_2 , unsigned V_16 )
{
F_30 ( V_2 , V_16 , false , 0 , true ) ;
}
void F_34 ( struct V_1 * V_2 , int V_29 )
{
if ( V_29 )
F_35 ( V_2 , 0 ) ;
else
V_73 -> V_74 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
++ V_2 -> V_77 . V_78 ;
V_2 -> V_5 . V_79 = V_76 -> V_80 ;
F_37 ( V_2 , V_42 , V_76 -> V_62 ) ;
}
static bool F_38 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
if ( F_39 ( V_2 ) && ! V_76 -> V_81 )
V_2 -> V_5 . V_82 . V_83 ( V_2 , V_76 ) ;
else
V_2 -> V_5 . V_84 . V_83 ( V_2 , V_76 ) ;
return V_76 -> V_81 ;
}
void F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_5 . V_85 ) ;
F_31 ( V_86 , V_2 ) ;
}
void F_37 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_62 )
{
F_30 ( V_2 , V_16 , true , V_62 , false ) ;
}
void F_42 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_62 )
{
F_30 ( V_2 , V_16 , true , V_62 , true ) ;
}
bool F_43 ( struct V_1 * V_2 , int V_87 )
{
if ( V_73 -> V_88 ( V_2 ) <= V_87 )
return true ;
F_37 ( V_2 , V_48 , 0 ) ;
return false ;
}
int F_44 ( struct V_1 * V_2 , struct V_89 * V_84 ,
T_5 V_90 , void * V_38 , int V_91 , int V_92 ,
T_1 V_93 )
{
struct V_75 V_68 ;
T_5 V_94 ;
T_6 V_95 ;
V_95 = F_45 ( V_90 ) ;
V_94 = V_84 -> V_96 ( V_2 , V_95 , V_93 , & V_68 ) ;
if ( V_94 == V_97 )
return - V_98 ;
V_94 = F_46 ( V_94 ) ;
return F_47 ( V_2 -> V_99 , V_94 , V_38 , V_91 , V_92 ) ;
}
int F_48 ( struct V_1 * V_2 , T_5 V_100 ,
void * V_38 , int V_91 , int V_92 , T_1 V_93 )
{
return F_44 ( V_2 , V_2 -> V_5 . V_101 , V_100 ,
V_38 , V_91 , V_92 , V_93 ) ;
}
int F_49 ( struct V_1 * V_2 , struct V_89 * V_84 , unsigned long V_102 )
{
T_5 V_103 = V_102 >> V_104 ;
unsigned V_91 = ( ( V_102 & ( V_105 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_106 ;
T_2 V_107 [ F_50 ( V_84 -> V_108 ) ] ;
V_106 = F_44 ( V_2 , V_84 , V_103 , V_107 ,
V_91 * sizeof( T_2 ) , sizeof( V_107 ) ,
V_109 | V_110 ) ;
if ( V_106 < 0 ) {
V_106 = 0 ;
goto V_111;
}
for ( V_3 = 0 ; V_3 < F_50 ( V_107 ) ; ++ V_3 ) {
if ( F_51 ( V_107 [ V_3 ] ) &&
( V_107 [ V_3 ] & V_2 -> V_5 . V_84 . V_112 [ 0 ] [ 2 ] ) ) {
V_106 = 0 ;
goto V_111;
}
}
V_106 = 1 ;
memcpy ( V_84 -> V_108 , V_107 , sizeof( V_84 -> V_108 ) ) ;
F_52 ( V_113 ,
( unsigned long * ) & V_2 -> V_5 . V_114 ) ;
F_52 ( V_113 ,
( unsigned long * ) & V_2 -> V_5 . V_115 ) ;
V_111:
return V_106 ;
}
static bool F_53 ( struct V_1 * V_2 )
{
T_2 V_107 [ F_50 ( V_2 -> V_5 . V_101 -> V_108 ) ] ;
bool V_116 = true ;
int V_91 ;
T_5 V_100 ;
int V_117 ;
if ( F_54 ( V_2 ) || ! F_55 ( V_2 ) )
return false ;
if ( ! F_56 ( V_113 ,
( unsigned long * ) & V_2 -> V_5 . V_114 ) )
return true ;
V_100 = ( F_57 ( V_2 ) & ~ 31u ) >> V_104 ;
V_91 = ( F_57 ( V_2 ) & ~ 31u ) & ( V_105 - 1 ) ;
V_117 = F_48 ( V_2 , V_100 , V_107 , V_91 , sizeof( V_107 ) ,
V_109 | V_110 ) ;
if ( V_117 < 0 )
goto V_111;
V_116 = memcmp ( V_107 , V_2 -> V_5 . V_101 -> V_108 , sizeof( V_107 ) ) != 0 ;
V_111:
return V_116 ;
}
int F_58 ( struct V_1 * V_2 , unsigned long V_118 )
{
unsigned long V_119 = F_59 ( V_2 ) ;
unsigned long V_120 = V_121 | V_122 |
V_123 | V_124 ;
V_118 |= V_125 ;
#ifdef F_60
if ( V_118 & 0xffffffff00000000UL )
return 1 ;
#endif
V_118 &= ~ V_126 ;
if ( ( V_118 & V_124 ) && ! ( V_118 & V_123 ) )
return 1 ;
if ( ( V_118 & V_121 ) && ! ( V_118 & V_127 ) )
return 1 ;
if ( ! F_61 ( V_2 ) && ( V_118 & V_121 ) ) {
#ifdef F_60
if ( ( V_2 -> V_5 . V_128 & V_129 ) ) {
int V_130 , V_131 ;
if ( ! F_55 ( V_2 ) )
return 1 ;
V_73 -> V_132 ( V_2 , & V_130 , & V_131 ) ;
if ( V_131 )
return 1 ;
} else
#endif
if ( F_55 ( V_2 ) && ! F_49 ( V_2 , V_2 -> V_5 . V_101 ,
F_57 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_118 & V_121 ) && F_62 ( V_2 , V_133 ) )
return 1 ;
V_73 -> V_134 ( V_2 , V_118 ) ;
if ( ( V_118 ^ V_119 ) & V_121 ) {
F_63 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_118 ^ V_119 ) & V_120 )
F_64 ( V_2 ) ;
return 0 ;
}
void F_65 ( struct V_1 * V_2 , unsigned long V_135 )
{
( void ) F_58 ( V_2 , F_66 ( V_2 , ~ 0x0eul ) | ( V_135 & 0x0f ) ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
if ( F_62 ( V_2 , V_136 ) &&
! V_2 -> V_137 ) {
F_68 ( V_138 , V_2 -> V_5 . V_139 ) ;
V_2 -> V_137 = 1 ;
}
}
static void F_69 ( struct V_1 * V_2 )
{
if ( V_2 -> V_137 ) {
if ( V_2 -> V_5 . V_139 != V_140 )
F_68 ( V_138 , V_140 ) ;
V_2 -> V_137 = 0 ;
}
}
int F_70 ( struct V_1 * V_2 , T_1 V_141 , T_2 V_142 )
{
T_2 V_139 = V_142 ;
T_2 V_143 = V_2 -> V_5 . V_139 ;
T_2 V_144 ;
if ( V_141 != V_138 )
return 1 ;
if ( ! ( V_139 & V_145 ) )
return 1 ;
if ( ( V_139 & V_146 ) && ! ( V_139 & V_147 ) )
return 1 ;
V_144 = V_2 -> V_5 . V_148 | V_145 ;
if ( V_139 & ~ V_144 )
return 1 ;
if ( ( ! ( V_139 & V_149 ) ) != ( ! ( V_139 & V_150 ) ) )
return 1 ;
F_69 ( V_2 ) ;
V_2 -> V_5 . V_139 = V_139 ;
if ( ( V_139 ^ V_143 ) & V_151 )
F_71 ( V_2 ) ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 , T_1 V_141 , T_2 V_142 )
{
if ( V_73 -> V_88 ( V_2 ) != 0 ||
F_70 ( V_2 , V_141 , V_142 ) ) {
F_35 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_73 ( struct V_1 * V_2 , unsigned long V_152 )
{
unsigned long V_153 = F_74 ( V_2 ) ;
unsigned long V_154 = V_155 | V_156 |
V_157 | V_158 ;
if ( V_152 & V_159 )
return 1 ;
if ( ! F_75 ( V_2 ) && ( V_152 & V_136 ) )
return 1 ;
if ( ! F_76 ( V_2 ) && ( V_152 & V_158 ) )
return 1 ;
if ( ! F_77 ( V_2 ) && ( V_152 & V_160 ) )
return 1 ;
if ( ! F_78 ( V_2 ) && ( V_152 & V_161 ) )
return 1 ;
if ( F_54 ( V_2 ) ) {
if ( ! ( V_152 & V_157 ) )
return 1 ;
} else if ( F_61 ( V_2 ) && ( V_152 & V_157 )
&& ( ( V_152 ^ V_153 ) & V_154 )
&& ! F_49 ( V_2 , V_2 -> V_5 . V_101 ,
F_57 ( V_2 ) ) )
return 1 ;
if ( ( V_152 & V_133 ) && ! ( V_153 & V_133 ) ) {
if ( ! F_79 ( V_2 ) )
return 1 ;
if ( ( F_57 ( V_2 ) & V_162 ) || ! F_54 ( V_2 ) )
return 1 ;
}
if ( V_73 -> V_163 ( V_2 , V_152 ) )
return 1 ;
if ( ( ( V_152 ^ V_153 ) & V_154 ) ||
( ! ( V_152 & V_133 ) && ( V_153 & V_133 ) ) )
F_64 ( V_2 ) ;
if ( ( V_152 ^ V_153 ) & V_160 )
F_80 ( V_2 , V_2 -> V_5 . V_101 , false ) ;
if ( ( V_152 ^ V_153 ) & V_136 )
F_71 ( V_2 ) ;
return 0 ;
}
int F_81 ( struct V_1 * V_2 , unsigned long V_102 )
{
if ( V_102 == F_57 ( V_2 ) && ! F_53 ( V_2 ) ) {
F_82 ( V_2 ) ;
F_31 ( V_164 , V_2 ) ;
return 0 ;
}
if ( F_54 ( V_2 ) ) {
if ( V_102 & V_165 )
return 1 ;
} else if ( F_55 ( V_2 ) && F_61 ( V_2 ) &&
! F_49 ( V_2 , V_2 -> V_5 . V_101 , V_102 ) )
return 1 ;
V_2 -> V_5 . V_102 = V_102 ;
F_52 ( V_166 , ( V_167 * ) & V_2 -> V_5 . V_114 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 , unsigned long V_168 )
{
if ( V_168 & V_169 )
return 1 ;
if ( F_85 ( V_2 -> V_99 ) )
F_86 ( V_2 , V_168 ) ;
else
V_2 -> V_5 . V_168 = V_168 ;
return 0 ;
}
unsigned long F_87 ( struct V_1 * V_2 )
{
if ( F_85 ( V_2 -> V_99 ) )
return F_88 ( V_2 ) ;
else
return V_2 -> V_5 . V_168 ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_170 & V_171 ) )
V_73 -> V_172 ( V_2 , V_2 -> V_5 . V_173 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
unsigned long V_174 ;
if ( V_2 -> V_170 & V_171 )
V_174 = V_2 -> V_5 . V_175 ;
else
V_174 = V_2 -> V_5 . V_174 ;
V_73 -> V_176 ( V_2 , V_174 ) ;
V_2 -> V_5 . V_177 &= ~ V_178 ;
if ( V_174 & V_179 )
V_2 -> V_5 . V_177 |= V_178 ;
}
static T_2 F_91 ( struct V_1 * V_2 )
{
T_2 V_180 = V_181 ;
if ( ! F_92 ( V_2 ) )
V_180 |= V_182 ;
return V_180 ;
}
static int F_93 ( struct V_1 * V_2 , int V_183 , unsigned long V_184 )
{
switch ( V_183 ) {
case 0 ... 3 :
V_2 -> V_5 . V_185 [ V_183 ] = V_184 ;
if ( ! ( V_2 -> V_170 & V_171 ) )
V_2 -> V_5 . V_186 [ V_183 ] = V_184 ;
break;
case 4 :
if ( F_62 ( V_2 , V_187 ) )
return 1 ;
case 6 :
if ( V_184 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_173 = ( V_184 & V_188 ) | F_91 ( V_2 ) ;
F_89 ( V_2 ) ;
break;
case 5 :
if ( F_62 ( V_2 , V_187 ) )
return 1 ;
default:
if ( V_184 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_174 = ( V_184 & V_189 ) | V_190 ;
F_90 ( V_2 ) ;
break;
}
return 0 ;
}
int F_94 ( struct V_1 * V_2 , int V_183 , unsigned long V_184 )
{
int V_191 ;
V_191 = F_93 ( V_2 , V_183 , V_184 ) ;
if ( V_191 > 0 )
F_32 ( V_2 , V_192 ) ;
else if ( V_191 < 0 )
F_35 ( V_2 , 0 ) ;
return V_191 ;
}
static int F_95 ( struct V_1 * V_2 , int V_183 , unsigned long * V_184 )
{
switch ( V_183 ) {
case 0 ... 3 :
* V_184 = V_2 -> V_5 . V_185 [ V_183 ] ;
break;
case 4 :
if ( F_62 ( V_2 , V_187 ) )
return 1 ;
case 6 :
if ( V_2 -> V_170 & V_171 )
* V_184 = V_2 -> V_5 . V_173 ;
else
* V_184 = V_73 -> V_193 ( V_2 ) ;
break;
case 5 :
if ( F_62 ( V_2 , V_187 ) )
return 1 ;
default:
* V_184 = V_2 -> V_5 . V_174 ;
break;
}
return 0 ;
}
int F_96 ( struct V_1 * V_2 , int V_183 , unsigned long * V_184 )
{
if ( F_95 ( V_2 , V_183 , V_184 ) ) {
F_32 ( V_2 , V_192 ) ;
return 1 ;
}
return 0 ;
}
bool F_97 ( struct V_1 * V_2 )
{
T_1 V_194 = F_98 ( V_2 , V_195 ) ;
T_2 V_38 ;
int V_29 ;
V_29 = F_99 ( V_2 , V_194 , & V_38 ) ;
if ( V_29 )
return V_29 ;
F_100 ( V_2 , V_196 , ( T_1 ) V_38 ) ;
F_100 ( V_2 , V_197 , V_38 >> 32 ) ;
return V_29 ;
}
bool F_101 ( struct V_1 * V_2 , T_2 V_128 )
{
if ( V_128 & V_198 )
return false ;
if ( V_128 & V_199 ) {
struct V_200 * V_201 ;
V_201 = F_102 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_201 || ! ( V_201 -> V_202 & F_103 ( V_203 ) ) )
return false ;
}
if ( V_128 & V_204 ) {
struct V_200 * V_201 ;
V_201 = F_102 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_201 || ! ( V_201 -> V_194 & F_103 ( V_205 ) ) )
return false ;
}
return true ;
}
static int F_104 ( struct V_1 * V_2 , T_2 V_128 )
{
T_2 V_206 = V_2 -> V_5 . V_128 ;
if ( ! F_101 ( V_2 , V_128 ) )
return 1 ;
if ( F_61 ( V_2 )
&& ( V_2 -> V_5 . V_128 & V_129 ) != ( V_128 & V_129 ) )
return 1 ;
V_128 &= ~ V_207 ;
V_128 |= V_2 -> V_5 . V_128 & V_207 ;
V_73 -> F_104 ( V_2 , V_128 ) ;
if ( ( V_128 ^ V_206 ) & V_208 )
F_64 ( V_2 ) ;
return 0 ;
}
void F_105 ( T_2 V_28 )
{
V_198 &= ~ V_28 ;
}
int F_106 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
switch ( V_21 -> V_141 ) {
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
if ( F_107 ( V_21 -> V_38 ) )
return 1 ;
break;
case V_214 :
case V_215 :
V_21 -> V_38 = F_108 ( V_21 -> V_38 ) ;
}
return V_73 -> V_216 ( V_2 , V_21 ) ;
}
static int F_109 ( struct V_1 * V_2 , unsigned V_141 , T_2 * V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = * V_38 ;
V_21 . V_141 = V_141 ;
V_21 . V_40 = true ;
return F_106 ( V_2 , & V_21 ) ;
}
static void F_110 ( struct V_217 * V_218 )
{
struct V_219 * V_220 = & V_219 ;
T_2 V_221 ;
V_221 = F_111 ( F_112 ( V_218 -> V_222 . V_223 , V_218 -> V_224 ) ) ;
F_113 ( & V_220 -> V_225 ) ;
V_220 -> clock . V_226 = V_218 -> V_222 . clock -> V_227 . V_226 ;
V_220 -> clock . V_228 = V_218 -> V_222 . V_228 ;
V_220 -> clock . V_28 = V_218 -> V_222 . V_28 ;
V_220 -> clock . V_229 = V_218 -> V_222 . V_229 ;
V_220 -> clock . V_230 = V_218 -> V_222 . V_230 ;
V_220 -> V_221 = V_221 ;
V_220 -> V_231 = V_218 -> V_222 . V_232 ;
F_114 ( & V_220 -> V_225 ) ;
}
static void F_115 ( struct V_99 * V_99 , T_6 V_233 )
{
int V_234 ;
int V_117 ;
struct V_235 V_236 ;
struct V_237 V_238 ;
if ( ! V_233 )
return;
V_117 = F_116 ( V_99 , V_233 , & V_234 , sizeof( V_234 ) ) ;
if ( V_117 )
return;
if ( V_234 & 1 )
++ V_234 ;
++ V_234 ;
F_117 ( V_99 , V_233 , & V_234 , sizeof( V_234 ) ) ;
F_118 ( & V_238 ) ;
if ( V_99 -> V_5 . V_239 ) {
struct V_237 V_240 = F_119 ( V_99 -> V_5 . V_239 ) ;
V_238 = F_120 ( V_238 , V_240 ) ;
}
V_236 . V_241 = V_238 . V_242 ;
V_236 . V_243 = V_238 . V_244 ;
V_236 . V_234 = V_234 ;
F_117 ( V_99 , V_233 , & V_236 , sizeof( V_236 ) ) ;
V_234 ++ ;
F_117 ( V_99 , V_233 , & V_234 , sizeof( V_234 ) ) ;
}
static T_7 F_121 ( T_7 V_245 , T_7 V_246 )
{
T_7 V_247 , V_248 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_247 ;
}
static void F_122 ( T_7 V_249 , T_7 V_250 ,
T_8 * V_251 , T_1 * V_252 )
{
T_9 V_253 ;
T_10 V_230 = 0 ;
T_9 V_254 ;
T_7 V_255 ;
V_254 = V_250 * 1000LL ;
V_253 = V_249 * 1000LL ;
while ( V_254 > V_253 * 2 || V_254 & 0xffffffff00000000ULL ) {
V_254 >>= 1 ;
V_230 -- ;
}
V_255 = ( T_7 ) V_254 ;
while ( V_255 <= V_253 || V_253 & 0xffffffff00000000ULL ) {
if ( V_253 & 0xffffffff00000000ULL || V_255 & 0x80000000 )
V_253 >>= 1 ;
else
V_255 <<= 1 ;
V_230 ++ ;
}
* V_251 = V_230 ;
* V_252 = F_121 ( V_253 , V_255 ) ;
F_123 ( L_2 ,
V_256 , V_250 , V_249 , V_230 , * V_252 ) ;
}
static inline T_2 F_124 ( void )
{
return F_125 () ;
}
static inline T_2 F_126 ( struct V_1 * V_2 , T_2 V_243 )
{
return F_127 ( V_243 , V_2 -> V_5 . V_257 ,
V_2 -> V_5 . V_258 ) ;
}
static T_1 F_128 ( T_1 V_259 , T_11 V_260 )
{
T_2 V_261 = ( T_2 ) V_259 * ( 1000000 + V_260 ) ;
F_129 ( V_261 , 1000000 ) ;
return V_261 ;
}
static void F_130 ( struct V_1 * V_2 , T_1 V_262 )
{
T_1 V_263 , V_264 ;
int V_265 = 0 ;
if ( V_262 == 0 )
return;
F_122 ( V_262 , V_266 / 1000 ,
& V_2 -> V_5 . V_258 ,
& V_2 -> V_5 . V_257 ) ;
V_2 -> V_5 . V_267 = V_262 ;
V_263 = F_128 ( V_268 , - V_269 ) ;
V_264 = F_128 ( V_268 , V_269 ) ;
if ( V_262 < V_263 || V_262 > V_264 ) {
F_123 ( L_3 , V_262 , V_263 , V_264 ) ;
V_265 = 1 ;
}
V_73 -> V_270 ( V_2 , V_262 , V_265 ) ;
}
static T_2 F_131 ( struct V_1 * V_2 , T_12 V_271 )
{
T_2 V_272 = F_127 ( V_271 - V_2 -> V_5 . V_273 ,
V_2 -> V_5 . V_257 ,
V_2 -> V_5 . V_258 ) ;
V_272 += V_2 -> V_5 . V_274 ;
return V_272 ;
}
void F_132 ( struct V_1 * V_2 )
{
#ifdef F_60
bool V_275 ;
bool V_276 = false ;
struct V_277 * V_278 = & V_2 -> V_99 -> V_5 ;
struct V_219 * V_279 = & V_219 ;
V_275 = ( V_278 -> V_280 + 1 ==
F_133 ( & V_2 -> V_99 -> V_281 ) ) ;
if ( V_275 && V_279 -> clock . V_226 == V_282 )
if ( ! V_278 -> V_283 )
V_276 = 1 ;
if ( ! V_275 && V_278 -> V_283 )
V_276 = 1 ;
if ( V_276 )
F_31 ( V_284 , V_2 ) ;
F_134 ( V_2 -> V_285 , V_278 -> V_280 ,
F_133 ( & V_2 -> V_99 -> V_281 ) ,
V_278 -> V_283 , V_279 -> clock . V_226 ) ;
#endif
}
static void F_135 ( struct V_1 * V_2 , T_12 V_91 )
{
T_2 V_286 = V_73 -> V_287 ( V_2 ) ;
V_2 -> V_5 . V_288 += V_91 - V_286 ;
}
void F_136 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
struct V_99 * V_99 = V_2 -> V_99 ;
T_2 V_91 , V_289 , V_290 ;
unsigned long V_291 ;
T_12 V_292 ;
bool V_293 ;
bool V_294 ;
T_2 V_38 = V_21 -> V_38 ;
F_137 ( & V_99 -> V_5 . V_295 , V_291 ) ;
V_91 = V_73 -> V_296 ( V_2 , V_38 ) ;
V_289 = F_124 () ;
V_290 = V_289 - V_99 -> V_5 . V_297 ;
if ( V_2 -> V_5 . V_267 ) {
int V_298 = 0 ;
V_292 = V_38 - V_99 -> V_5 . V_299 ;
#ifdef F_60
V_292 = ( V_292 * 1000 ) / V_2 -> V_5 . V_267 ;
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
F_129 ( V_290 , 1000 ) ;
V_292 -= V_290 ;
if ( V_292 < 0 )
V_292 = - V_292 ;
if ( V_298 )
V_292 = V_300 ;
} else
V_292 = V_300 ;
if ( V_292 < V_300 &&
V_2 -> V_5 . V_267 == V_99 -> V_5 . V_301 ) {
if ( ! F_138 () ) {
V_91 = V_99 -> V_5 . V_302 ;
F_123 ( L_4 , V_38 ) ;
} else {
T_2 V_303 = F_126 ( V_2 , V_290 ) ;
V_38 += V_303 ;
V_91 = V_73 -> V_296 ( V_2 , V_38 ) ;
F_123 ( L_5 , V_303 ) ;
}
V_293 = true ;
V_294 = ( V_2 -> V_5 . V_304 == V_99 -> V_5 . V_305 ) ;
} else {
V_99 -> V_5 . V_305 ++ ;
V_99 -> V_5 . V_306 = V_289 ;
V_99 -> V_5 . V_307 = V_38 ;
V_99 -> V_5 . V_302 = V_91 ;
V_293 = false ;
F_123 ( L_6 ,
V_99 -> V_5 . V_305 , V_38 ) ;
}
V_99 -> V_5 . V_297 = V_289 ;
V_99 -> V_5 . V_299 = V_38 ;
V_99 -> V_5 . V_301 = V_2 -> V_5 . V_267 ;
V_2 -> V_5 . V_308 = V_38 ;
V_2 -> V_5 . V_304 = V_99 -> V_5 . V_305 ;
V_2 -> V_5 . V_273 = V_99 -> V_5 . V_306 ;
V_2 -> V_5 . V_274 = V_99 -> V_5 . V_307 ;
if ( F_139 ( V_2 ) && ! V_21 -> V_40 )
F_135 ( V_2 , V_91 ) ;
V_73 -> V_309 ( V_2 , V_91 ) ;
F_140 ( & V_99 -> V_5 . V_295 , V_291 ) ;
F_141 ( & V_99 -> V_5 . V_310 ) ;
if ( ! V_293 ) {
V_99 -> V_5 . V_280 = 0 ;
} else if ( ! V_294 ) {
V_99 -> V_5 . V_280 ++ ;
}
F_132 ( V_2 ) ;
F_142 ( & V_99 -> V_5 . V_310 ) ;
}
static T_13 F_143 ( void )
{
T_13 V_106 ;
T_2 V_311 ;
F_144 () ;
V_106 = ( T_13 ) F_145 () ;
V_311 = V_219 . clock . V_228 ;
if ( F_146 ( V_106 >= V_311 ) )
return V_106 ;
asm volatile ("");
return V_311 ;
}
static inline T_2 F_147 ( T_13 * V_312 )
{
long V_261 ;
struct V_219 * V_279 = & V_219 ;
* V_312 = F_143 () ;
V_261 = ( * V_312 - V_279 -> clock . V_228 ) & V_279 -> clock . V_28 ;
return V_261 * V_279 -> clock . V_229 ;
}
static int F_148 ( T_12 * V_313 , T_13 * V_312 )
{
struct V_219 * V_279 = & V_219 ;
unsigned long V_225 ;
int V_314 ;
T_2 V_289 ;
do {
V_225 = F_149 ( & V_279 -> V_225 ) ;
V_314 = V_279 -> clock . V_226 ;
V_289 = V_279 -> V_231 ;
V_289 += F_147 ( V_312 ) ;
V_289 >>= V_279 -> clock . V_230 ;
V_289 += V_279 -> V_221 ;
} while ( F_150 ( F_151 ( & V_279 -> V_225 , V_225 ) ) );
* V_313 = V_289 ;
return V_314 ;
}
static bool F_152 ( T_12 * V_271 , T_13 * V_312 )
{
if ( V_219 . clock . V_226 != V_282 )
return false ;
return F_148 ( V_271 , V_312 ) == V_282 ;
}
static void F_153 ( struct V_99 * V_99 )
{
#ifdef F_60
struct V_277 * V_278 = & V_99 -> V_5 ;
int V_226 ;
bool V_315 , V_275 ;
V_275 = ( V_278 -> V_280 + 1 ==
F_133 ( & V_99 -> V_281 ) ) ;
V_315 = F_152 (
& V_278 -> V_316 ,
& V_278 -> V_317 ) ;
V_278 -> V_283 = V_315 && V_275
&& ! V_318 ;
if ( V_278 -> V_283 )
F_154 ( & V_319 , 1 ) ;
V_226 = V_219 . clock . V_226 ;
F_155 ( V_278 -> V_283 , V_226 ,
V_275 ) ;
#endif
}
static void F_156 ( struct V_99 * V_99 )
{
#ifdef F_60
int V_3 ;
struct V_1 * V_2 ;
struct V_277 * V_278 = & V_99 -> V_5 ;
F_141 ( & V_278 -> V_310 ) ;
F_157 ( V_99 ) ;
F_153 ( V_99 ) ;
F_158 (i, vcpu, kvm)
F_31 ( V_320 , V_2 ) ;
F_158 (i, vcpu, kvm)
F_159 ( V_321 , & V_2 -> V_322 ) ;
F_142 ( & V_278 -> V_310 ) ;
#endif
}
static int F_160 ( struct V_1 * V_261 )
{
unsigned long V_291 , V_262 ;
struct V_323 * V_2 = & V_261 -> V_5 ;
struct V_277 * V_278 = & V_261 -> V_99 -> V_5 ;
T_12 V_271 ;
T_2 V_324 , V_325 ;
struct V_326 V_327 ;
T_14 V_328 ;
bool V_283 ;
V_271 = 0 ;
V_325 = 0 ;
F_141 ( & V_278 -> V_310 ) ;
V_283 = V_278 -> V_283 ;
if ( V_283 ) {
V_325 = V_278 -> V_317 ;
V_271 = V_278 -> V_316 ;
}
F_142 ( & V_278 -> V_310 ) ;
F_161 ( V_291 ) ;
V_262 = F_162 ( V_329 ) ;
if ( F_150 ( V_262 == 0 ) ) {
F_163 ( V_291 ) ;
F_31 ( V_320 , V_261 ) ;
return 1 ;
}
if ( ! V_283 ) {
V_325 = F_164 () ;
V_271 = F_124 () ;
}
V_324 = V_73 -> V_330 ( V_261 , V_325 ) ;
if ( V_2 -> V_331 ) {
T_2 V_272 = F_131 ( V_261 , V_271 ) ;
if ( V_272 > V_324 ) {
F_165 ( V_261 , V_272 - V_324 ) ;
V_324 = V_272 ;
}
}
F_163 ( V_291 ) ;
if ( ! V_2 -> V_332 )
return 0 ;
if ( F_150 ( V_2 -> V_333 != V_262 ) ) {
F_122 ( V_266 / 1000 , V_262 ,
& V_2 -> V_334 . V_335 ,
& V_2 -> V_334 . V_336 ) ;
V_2 -> V_333 = V_262 ;
}
V_2 -> V_334 . V_324 = V_324 ;
V_2 -> V_334 . V_337 = V_271 + V_261 -> V_99 -> V_5 . V_239 ;
V_2 -> V_308 = V_324 ;
V_2 -> V_334 . V_234 += 2 ;
if ( F_150 ( F_166 ( V_261 -> V_99 , & V_2 -> V_338 ,
& V_327 , sizeof( V_327 ) ) ) )
return 0 ;
V_328 = ( V_327 . V_291 & V_339 ) ;
if ( V_2 -> V_340 ) {
V_328 |= V_339 ;
V_2 -> V_340 = false ;
}
if ( V_283 )
V_328 |= V_341 ;
V_2 -> V_334 . V_291 = V_328 ;
F_167 ( V_261 -> V_99 , & V_2 -> V_338 ,
& V_2 -> V_334 ,
sizeof( V_2 -> V_334 ) ) ;
return 0 ;
}
static void F_168 ( struct V_342 * V_343 )
{
int V_3 ;
struct V_344 * V_345 = F_169 ( V_343 ) ;
struct V_277 * V_278 = F_4 ( V_345 , struct V_277 ,
V_346 ) ;
struct V_99 * V_99 = F_4 ( V_278 , struct V_99 , V_5 ) ;
struct V_1 * V_2 ;
F_158 (i, vcpu, kvm) {
F_31 ( V_320 , V_2 ) ;
F_170 ( V_2 ) ;
}
}
static void F_171 ( struct V_1 * V_261 )
{
struct V_99 * V_99 = V_261 -> V_99 ;
F_31 ( V_320 , V_261 ) ;
F_172 ( & V_99 -> V_5 . V_346 ,
V_347 ) ;
}
static void F_173 ( struct V_342 * V_343 )
{
struct V_344 * V_345 = F_169 ( V_343 ) ;
struct V_277 * V_278 = F_4 ( V_345 , struct V_277 ,
V_348 ) ;
struct V_99 * V_99 = F_4 ( V_278 , struct V_99 , V_5 ) ;
F_172 ( & V_99 -> V_5 . V_346 , 0 ) ;
F_172 ( & V_99 -> V_5 . V_348 ,
V_349 ) ;
}
static bool F_174 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_350 - 1 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_175 ( unsigned V_313 )
{
return V_313 < 8 && ( 1 << V_313 ) & 0xf3 ;
}
static bool F_176 ( unsigned V_313 )
{
return V_313 < 8 && ( 1 << V_313 ) & 0x73 ;
}
bool F_177 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
int V_3 ;
T_2 V_28 ;
if ( ! F_174 ( V_21 ) )
return false ;
if ( V_21 == V_363 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_175 ( ( V_38 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_362 ) {
if ( V_38 & ~ 0xcff )
return false ;
return F_176 ( V_38 & 0xff ) ;
} else if ( V_21 >= V_351 && V_21 <= V_361 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_176 ( ( V_38 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
F_29 ( ! ( V_21 >= 0x200 && V_21 < 0x200 + 2 * V_350 ) ) ;
V_28 = ( ~ 0ULL ) << F_22 ( V_2 ) ;
if ( ( V_21 & 1 ) == 0 ) {
if ( ! F_176 ( V_38 & 0xff ) )
return false ;
V_28 |= 0xf00 ;
} else
V_28 |= 0x7ff ;
if ( V_38 & V_28 ) {
F_35 ( V_2 , 0 ) ;
return false ;
}
return true ;
}
static int F_178 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 * V_364 = ( T_2 * ) & V_2 -> V_5 . V_365 . V_366 ;
if ( ! F_177 ( V_2 , V_21 , V_38 ) )
return 1 ;
if ( V_21 == V_362 ) {
V_2 -> V_5 . V_365 . V_367 = V_38 ;
V_2 -> V_5 . V_365 . V_368 = ( V_38 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_351 )
V_364 [ 0 ] = V_38 ;
else if ( V_21 == V_352 || V_21 == V_353 )
V_364 [ 1 + V_21 - V_352 ] = V_38 ;
else if ( V_21 >= V_354 && V_21 <= V_361 )
V_364 [ 3 + V_21 - V_354 ] = V_38 ;
else if ( V_21 == V_363 )
V_2 -> V_5 . V_369 = V_38 ;
else {
int V_370 , V_371 ;
T_2 * V_372 ;
V_370 = ( V_21 - 0x200 ) / 2 ;
V_371 = V_21 - 0x200 - 2 * V_370 ;
if ( ! V_371 )
V_372 =
( T_2 * ) & V_2 -> V_5 . V_365 . V_373 [ V_370 ] . V_374 ;
else
V_372 =
( T_2 * ) & V_2 -> V_5 . V_365 . V_373 [ V_370 ] . V_375 ;
* V_372 = V_38 ;
}
F_64 ( V_2 ) ;
return 0 ;
}
static int F_179 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 V_376 = V_2 -> V_5 . V_376 ;
unsigned V_377 = V_376 & 0xff ;
switch ( V_21 ) {
case V_378 :
V_2 -> V_5 . V_379 = V_38 ;
break;
case V_380 :
if ( ! ( V_376 & V_381 ) )
return 1 ;
if ( V_38 != 0 && V_38 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_382 = V_38 ;
break;
default:
if ( V_21 >= V_383 &&
V_21 < F_180 ( V_377 ) ) {
T_1 V_91 = V_21 - V_383 ;
if ( ( V_91 & 0x3 ) == 0 &&
V_38 != 0 && ( V_38 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_384 [ V_91 ] = V_38 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_181 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_99 * V_99 = V_2 -> V_99 ;
int V_385 = F_54 ( V_2 ) ;
T_14 * V_386 = V_385 ? ( T_14 * ) ( long ) V_99 -> V_5 . F_181 . V_387
: ( T_14 * ) ( long ) V_99 -> V_5 . F_181 . V_388 ;
T_14 V_389 = V_385 ? V_99 -> V_5 . F_181 . V_390
: V_99 -> V_5 . F_181 . V_391 ;
T_1 V_392 = V_38 & ~ V_393 ;
T_2 V_394 = V_38 & V_393 ;
T_14 * V_395 ;
int V_117 ;
V_117 = - V_396 ;
if ( V_392 >= V_389 )
goto V_111;
V_117 = - V_397 ;
V_395 = F_182 ( V_386 + ( V_392 * V_105 ) , V_105 ) ;
if ( F_183 ( V_395 ) ) {
V_117 = F_184 ( V_395 ) ;
goto V_111;
}
if ( F_117 ( V_99 , V_394 , V_395 , V_105 ) )
goto V_398;
V_117 = 0 ;
V_398:
F_185 ( V_395 ) ;
V_111:
return V_117 ;
}
static bool F_186 ( struct V_99 * V_99 )
{
return V_99 -> V_5 . V_399 & V_400 ;
}
static bool F_187 ( T_1 V_21 )
{
bool V_117 = false ;
switch ( V_21 ) {
case V_401 :
case V_402 :
case V_403 :
case V_404 :
V_117 = true ;
break;
}
return V_117 ;
}
static int F_188 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
struct V_99 * V_99 = V_2 -> V_99 ;
switch ( V_21 ) {
case V_401 :
V_99 -> V_5 . V_405 = V_38 ;
if ( ! V_99 -> V_5 . V_405 )
V_99 -> V_5 . V_399 &= ~ V_400 ;
break;
case V_402 : {
T_2 V_100 ;
unsigned long V_406 ;
T_14 V_407 [ 4 ] ;
if ( ! V_99 -> V_5 . V_405 )
break;
if ( ! ( V_38 & V_400 ) ) {
V_99 -> V_5 . V_399 = V_38 ;
break;
}
V_100 = V_38 >> V_408 ;
V_406 = F_189 ( V_99 , V_100 ) ;
if ( F_190 ( V_406 ) )
return 1 ;
V_73 -> V_409 ( V_2 , V_407 ) ;
( ( unsigned char * ) V_407 ) [ 3 ] = 0xc3 ;
if ( F_191 ( ( void V_410 * ) V_406 , V_407 , 4 ) )
return 1 ;
V_99 -> V_5 . V_399 = V_38 ;
F_192 ( V_99 , V_100 ) ;
break;
}
case V_403 : {
T_2 V_100 ;
T_15 V_411 ;
memset ( & V_411 , 0 , sizeof( V_411 ) ) ;
V_99 -> V_5 . V_412 = V_38 ;
if ( ! ( V_38 & V_413 ) )
break;
V_100 = V_38 >> V_414 ;
if ( F_117 ( V_99 , V_100 << V_414 ,
& V_411 , sizeof( V_411 ) ) )
return 1 ;
F_192 ( V_99 , V_100 ) ;
break;
}
default:
F_193 ( V_2 , L_7
L_8 , V_21 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_194 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
switch ( V_21 ) {
case V_415 : {
T_2 V_100 ;
unsigned long V_406 ;
if ( ! ( V_38 & V_416 ) ) {
V_2 -> V_5 . V_417 = V_38 ;
if ( F_195 ( V_2 , 0 ) )
return 1 ;
break;
}
V_100 = V_38 >> V_418 ;
V_406 = F_189 ( V_2 -> V_99 , V_100 ) ;
if ( F_190 ( V_406 ) )
return 1 ;
if ( F_196 ( ( void V_410 * ) V_406 , V_105 ) )
return 1 ;
V_2 -> V_5 . V_417 = V_38 ;
F_192 ( V_2 -> V_99 , V_100 ) ;
if ( F_195 ( V_2 , F_45 ( V_100 ) | V_419 ) )
return 1 ;
break;
}
case V_420 :
return F_197 ( V_2 , V_421 , V_38 ) ;
case V_422 :
return F_197 ( V_2 , V_423 , V_38 ) ;
case V_424 :
return F_197 ( V_2 , V_425 , V_38 ) ;
default:
F_193 ( V_2 , L_7
L_8 , V_21 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_198 ( struct V_1 * V_2 , T_2 V_38 )
{
T_6 V_426 = V_38 & ~ 0x3f ;
if ( V_38 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_427 = V_38 ;
if ( ! ( V_38 & V_428 ) ) {
F_63 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_199 ( V_2 -> V_99 , & V_2 -> V_5 . V_6 . V_38 , V_426 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_429 = ! ( V_38 & V_430 ) ;
F_200 ( V_2 ) ;
return 0 ;
}
static void F_201 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_332 = false ;
}
static void F_202 ( struct V_1 * V_2 )
{
T_2 V_303 ;
if ( ! ( V_2 -> V_5 . V_431 . V_427 & V_419 ) )
return;
V_303 = V_432 -> V_433 . V_434 - V_2 -> V_5 . V_431 . V_435 ;
V_2 -> V_5 . V_431 . V_435 = V_432 -> V_433 . V_434 ;
V_2 -> V_5 . V_431 . V_436 = V_303 ;
}
static void F_203 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_431 . V_427 & V_419 ) )
return;
if ( F_150 ( F_166 ( V_2 -> V_99 , & V_2 -> V_5 . V_431 . V_437 ,
& V_2 -> V_5 . V_431 . V_438 , sizeof( struct V_439 ) ) ) )
return;
V_2 -> V_5 . V_431 . V_438 . V_438 += V_2 -> V_5 . V_431 . V_436 ;
V_2 -> V_5 . V_431 . V_438 . V_234 += 2 ;
V_2 -> V_5 . V_431 . V_436 = 0 ;
F_167 ( V_2 -> V_99 , & V_2 -> V_5 . V_431 . V_437 ,
& V_2 -> V_5 . V_431 . V_438 , sizeof( struct V_439 ) ) ;
}
int F_204 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
bool V_440 = false ;
T_1 V_21 = V_33 -> V_141 ;
T_2 V_38 = V_33 -> V_38 ;
switch ( V_21 ) {
case V_441 :
case V_442 :
case V_443 :
case V_444 :
case V_445 :
case V_446 :
break;
case V_447 :
return F_104 ( V_2 , V_38 ) ;
case V_448 :
V_38 &= ~ ( T_2 ) 0x40 ;
V_38 &= ~ ( T_2 ) 0x100 ;
V_38 &= ~ ( T_2 ) 0x8 ;
V_38 &= ~ ( T_2 ) 0x40000 ;
if ( V_38 != 0 ) {
F_193 ( V_2 , L_9 ,
V_38 ) ;
return 1 ;
}
break;
case V_449 :
if ( V_38 != 0 ) {
F_193 ( V_2 , L_10
L_11 , V_38 ) ;
return 1 ;
}
break;
case V_450 :
if ( ! V_38 ) {
break;
} else if ( V_38 & ~ ( V_451 | V_452 ) ) {
return 1 ;
}
F_193 ( V_2 , L_12 ,
V_256 , V_38 ) ;
break;
case 0x200 ... 0x2ff :
return F_178 ( V_2 , V_21 , V_38 ) ;
case V_453 :
return F_21 ( V_2 , V_33 ) ;
case V_454 ... V_454 + 0x3ff :
return F_205 ( V_2 , V_21 , V_38 ) ;
case V_455 :
F_206 ( V_2 , V_38 ) ;
break;
case V_456 :
if ( F_139 ( V_2 ) ) {
if ( ! V_33 -> V_40 ) {
T_2 V_457 = V_38 - V_2 -> V_5 . V_288 ;
V_73 -> V_458 ( V_2 , V_457 , true ) ;
}
V_2 -> V_5 . V_288 = V_38 ;
}
break;
case V_459 :
V_2 -> V_5 . V_460 = V_38 ;
break;
case V_461 :
case V_462 :
V_2 -> V_99 -> V_5 . V_233 = V_38 ;
F_115 ( V_2 -> V_99 , V_38 ) ;
break;
case V_463 :
case V_464 : {
T_2 V_465 ;
F_201 ( V_2 ) ;
V_2 -> V_5 . time = V_38 ;
F_31 ( V_466 , V_2 ) ;
if ( ! ( V_38 & 1 ) )
break;
V_465 = V_38 & ~ ( V_393 | 1 ) ;
if ( F_199 ( V_2 -> V_99 ,
& V_2 -> V_5 . V_338 , V_38 & ~ 1ULL ,
sizeof( struct V_326 ) ) )
V_2 -> V_5 . V_332 = false ;
else
V_2 -> V_5 . V_332 = true ;
break;
}
case V_467 :
if ( F_198 ( V_2 , V_38 ) )
return 1 ;
break;
case V_468 :
if ( F_150 ( ! F_207 () ) )
return 1 ;
if ( V_38 & V_469 )
return 1 ;
if ( F_199 ( V_2 -> V_99 , & V_2 -> V_5 . V_431 . V_437 ,
V_38 & V_470 ,
sizeof( struct V_439 ) ) )
return 1 ;
V_2 -> V_5 . V_431 . V_427 = V_38 ;
if ( ! ( V_38 & V_419 ) )
break;
V_2 -> V_5 . V_431 . V_435 = V_432 -> V_433 . V_434 ;
F_208 () ;
F_202 ( V_2 ) ;
F_209 () ;
F_31 ( V_471 , V_2 ) ;
break;
case V_472 :
if ( F_195 ( V_2 , V_38 ) )
return 1 ;
break;
case V_380 :
case V_378 :
case V_383 ... F_180 ( V_473 ) - 1 :
return F_179 ( V_2 , V_21 , V_38 ) ;
case V_474 :
case V_475 :
case V_476 :
case V_477 :
if ( V_38 != 0 )
F_193 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_478 :
case V_479 :
case V_480 :
case V_481 :
F_193 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_482 :
case V_483 :
V_440 = true ;
case V_484 :
case V_485 :
if ( F_210 ( V_2 , V_21 ) )
return F_211 ( V_2 , V_33 ) ;
if ( V_440 || V_38 != 0 )
F_193 ( V_2 , L_15
L_14 , V_21 , V_38 ) ;
break;
case V_486 :
break;
case V_401 ... V_487 :
if ( F_187 ( V_21 ) ) {
int V_117 ;
F_212 ( & V_2 -> V_99 -> V_488 ) ;
V_117 = F_188 ( V_2 , V_21 , V_38 ) ;
F_213 ( & V_2 -> V_99 -> V_488 ) ;
return V_117 ;
} else
return F_194 ( V_2 , V_21 , V_38 ) ;
break;
case V_489 :
F_193 ( V_2 , L_16 , V_21 , V_38 ) ;
break;
case V_490 :
if ( ! F_214 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_491 . V_492 = V_38 ;
break;
case V_493 :
if ( ! F_214 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_491 . V_494 = V_38 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_99 -> V_5 . F_181 . V_21 ) )
return F_181 ( V_2 , V_38 ) ;
if ( F_210 ( V_2 , V_21 ) )
return F_211 ( V_2 , V_33 ) ;
if ( ! V_495 ) {
F_193 ( V_2 , L_17 ,
V_21 , V_38 ) ;
return 1 ;
} else {
F_193 ( V_2 , L_16 ,
V_21 , V_38 ) ;
break;
}
}
return 0 ;
}
int F_215 ( struct V_1 * V_2 , T_1 V_496 , T_2 * V_497 )
{
return V_73 -> V_498 ( V_2 , V_496 , V_497 ) ;
}
static int F_216 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_497 )
{
T_2 * V_364 = ( T_2 * ) & V_2 -> V_5 . V_365 . V_366 ;
if ( ! F_174 ( V_21 ) )
return 1 ;
if ( V_21 == V_362 )
* V_497 = V_2 -> V_5 . V_365 . V_367 +
( V_2 -> V_5 . V_365 . V_368 << 10 ) ;
else if ( V_21 == V_351 )
* V_497 = V_364 [ 0 ] ;
else if ( V_21 == V_352 || V_21 == V_353 )
* V_497 = V_364 [ 1 + V_21 - V_352 ] ;
else if ( V_21 >= V_354 && V_21 <= V_361 )
* V_497 = V_364 [ 3 + V_21 - V_354 ] ;
else if ( V_21 == V_363 )
* V_497 = V_2 -> V_5 . V_369 ;
else {
int V_370 , V_371 ;
T_2 * V_372 ;
V_370 = ( V_21 - 0x200 ) / 2 ;
V_371 = V_21 - 0x200 - 2 * V_370 ;
if ( ! V_371 )
V_372 =
( T_2 * ) & V_2 -> V_5 . V_365 . V_373 [ V_370 ] . V_374 ;
else
V_372 =
( T_2 * ) & V_2 -> V_5 . V_365 . V_373 [ V_370 ] . V_375 ;
* V_497 = * V_372 ;
}
return 0 ;
}
static int F_217 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_497 )
{
T_2 V_38 ;
T_2 V_376 = V_2 -> V_5 . V_376 ;
unsigned V_377 = V_376 & 0xff ;
switch ( V_21 ) {
case V_499 :
case V_500 :
V_38 = 0 ;
break;
case V_501 :
V_38 = V_2 -> V_5 . V_376 ;
break;
case V_380 :
if ( ! ( V_376 & V_381 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_382 ;
break;
case V_378 :
V_38 = V_2 -> V_5 . V_379 ;
break;
default:
if ( V_21 >= V_383 &&
V_21 < F_180 ( V_377 ) ) {
T_1 V_91 = V_21 - V_383 ;
V_38 = V_2 -> V_5 . V_384 [ V_91 ] ;
break;
}
return 1 ;
}
* V_497 = V_38 ;
return 0 ;
}
static int F_218 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_497 )
{
T_2 V_38 = 0 ;
struct V_99 * V_99 = V_2 -> V_99 ;
switch ( V_21 ) {
case V_401 :
V_38 = V_99 -> V_5 . V_405 ;
break;
case V_402 :
V_38 = V_99 -> V_5 . V_399 ;
break;
case V_404 : {
V_38 =
F_219 ( F_124 () + V_99 -> V_5 . V_239 , 100 ) ;
break;
}
case V_403 :
V_38 = V_99 -> V_5 . V_412 ;
break;
default:
F_193 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_497 = V_38 ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_497 )
{
T_2 V_38 = 0 ;
switch ( V_21 ) {
case V_502 : {
int V_117 ;
struct V_1 * V_261 ;
F_158 (r, v, vcpu->kvm) {
if ( V_261 == V_2 ) {
V_38 = V_117 ;
break;
}
}
break;
}
case V_420 :
return F_221 ( V_2 , V_421 , V_497 ) ;
case V_422 :
return F_221 ( V_2 , V_423 , V_497 ) ;
case V_424 :
return F_221 ( V_2 , V_425 , V_497 ) ;
case V_415 :
V_38 = V_2 -> V_5 . V_417 ;
break;
default:
F_193 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_497 = V_38 ;
return 0 ;
}
int F_222 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_497 )
{
T_2 V_38 ;
switch ( V_21 ) {
case V_503 :
case V_504 :
case V_450 :
case V_505 :
case V_506 :
case V_507 :
case V_508 :
case V_509 :
case V_448 :
case V_444 :
case V_474 :
case V_475 :
case V_476 :
case V_477 :
case V_478 :
case V_479 :
case V_480 :
case V_481 :
case V_510 :
case V_441 :
case V_449 :
case V_446 :
V_38 = 0 ;
break;
case V_482 :
case V_483 :
case V_484 :
case V_485 :
if ( F_210 ( V_2 , V_21 ) )
return F_223 ( V_2 , V_21 , V_497 ) ;
V_38 = 0 ;
break;
case V_442 :
V_38 = 0x100000000ULL ;
break;
case V_511 :
V_38 = 0x500 | V_350 ;
break;
case 0x200 ... 0x2ff :
return F_216 ( V_2 , V_21 , V_497 ) ;
case 0xcd :
V_38 = 3 ;
break;
case V_512 :
V_38 = 1 << 24 ;
break;
case V_453 :
V_38 = F_20 ( V_2 ) ;
break;
case V_454 ... V_454 + 0x3ff :
return F_224 ( V_2 , V_21 , V_497 ) ;
break;
case V_455 :
V_38 = F_225 ( V_2 ) ;
break;
case V_456 :
V_38 = ( T_2 ) V_2 -> V_5 . V_288 ;
break;
case V_459 :
V_38 = V_2 -> V_5 . V_460 ;
break;
case V_513 :
V_38 = 1000ULL ;
V_38 |= ( ( ( T_9 ) 4ULL ) << 40 ) ;
break;
case V_447 :
V_38 = V_2 -> V_5 . V_128 ;
break;
case V_462 :
case V_461 :
V_38 = V_2 -> V_99 -> V_5 . V_233 ;
break;
case V_464 :
case V_463 :
V_38 = V_2 -> V_5 . time ;
break;
case V_467 :
V_38 = V_2 -> V_5 . V_6 . V_427 ;
break;
case V_468 :
V_38 = V_2 -> V_5 . V_431 . V_427 ;
break;
case V_472 :
V_38 = V_2 -> V_5 . V_514 . V_427 ;
break;
case V_499 :
case V_500 :
case V_501 :
case V_380 :
case V_378 :
case V_383 ... F_180 ( V_473 ) - 1 :
return F_217 ( V_2 , V_21 , V_497 ) ;
case V_486 :
V_38 = 0x20000000 ;
break;
case V_401 ... V_487 :
if ( F_187 ( V_21 ) ) {
int V_117 ;
F_212 ( & V_2 -> V_99 -> V_488 ) ;
V_117 = F_218 ( V_2 , V_21 , V_497 ) ;
F_213 ( & V_2 -> V_99 -> V_488 ) ;
return V_117 ;
} else
return F_220 ( V_2 , V_21 , V_497 ) ;
break;
case V_489 :
V_38 = 0xbe702111 ;
break;
case V_490 :
if ( ! F_214 ( V_2 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_491 . V_492 ;
break;
case V_493 :
if ( ! F_214 ( V_2 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_491 . V_494 ;
break;
default:
if ( F_210 ( V_2 , V_21 ) )
return F_223 ( V_2 , V_21 , V_497 ) ;
if ( ! V_495 ) {
F_193 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_193 ( V_2 , L_20 , V_21 ) ;
V_38 = 0 ;
}
break;
}
* V_497 = V_38 ;
return 0 ;
}
static int F_226 ( struct V_1 * V_2 , struct V_515 * V_19 ,
struct V_516 * V_517 ,
int (* F_227)( struct V_1 * V_2 ,
unsigned V_141 , T_2 * V_38 ) )
{
int V_3 , V_370 ;
V_370 = F_228 ( & V_2 -> V_99 -> V_518 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_519 ; ++ V_3 )
if ( F_227 ( V_2 , V_517 [ V_3 ] . V_141 , & V_517 [ V_3 ] . V_38 ) )
break;
F_229 ( & V_2 -> V_99 -> V_518 , V_370 ) ;
return V_3 ;
}
static int F_230 ( struct V_1 * V_2 , struct V_515 V_410 * V_520 ,
int (* F_227)( struct V_1 * V_2 ,
unsigned V_141 , T_2 * V_38 ) ,
int V_521 )
{
struct V_515 V_19 ;
struct V_516 * V_517 ;
int V_117 , V_522 ;
unsigned V_523 ;
V_117 = - V_98 ;
if ( F_231 ( & V_19 , V_520 , sizeof V_19 ) )
goto V_111;
V_117 = - V_396 ;
if ( V_19 . V_519 >= V_524 )
goto V_111;
V_523 = sizeof( struct V_516 ) * V_19 . V_519 ;
V_517 = F_182 ( V_520 -> V_517 , V_523 ) ;
if ( F_183 ( V_517 ) ) {
V_117 = F_184 ( V_517 ) ;
goto V_111;
}
V_117 = V_522 = F_226 ( V_2 , & V_19 , V_517 , F_227 ) ;
if ( V_117 < 0 )
goto V_398;
V_117 = - V_98 ;
if ( V_521 && F_232 ( V_520 -> V_517 , V_517 , V_523 ) )
goto V_398;
V_117 = V_522 ;
V_398:
F_185 ( V_517 ) ;
V_111:
return V_117 ;
}
int F_233 ( struct V_99 * V_99 , long V_525 )
{
int V_117 ;
switch ( V_525 ) {
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
case V_543 :
case V_544 :
case V_545 :
case V_546 :
case V_547 :
case V_548 :
case V_549 :
case V_550 :
case V_551 :
case V_552 :
case V_553 :
case V_554 :
case V_555 :
case V_556 :
case V_557 :
case V_558 :
case V_559 :
case V_560 :
case V_561 :
#ifdef F_234
case V_562 :
case V_563 :
#endif
V_117 = 1 ;
break;
case V_564 :
V_117 = V_565 ;
break;
case V_566 :
V_117 = ! V_73 -> V_567 () ;
break;
case V_568 :
V_117 = V_569 ;
break;
case V_570 :
V_117 = V_571 ;
break;
case V_572 :
V_117 = V_573 ;
break;
case V_574 :
V_117 = 0 ;
break;
#ifdef F_234
case V_575 :
V_117 = F_235 ( & V_576 ) ;
break;
#endif
case V_577 :
V_117 = V_473 ;
break;
case V_578 :
V_117 = V_579 ;
break;
case V_580 :
V_117 = V_581 ;
break;
case V_582 :
V_117 = F_236 ( V_583 ) ;
break;
default:
V_117 = 0 ;
break;
}
return V_117 ;
}
long F_237 ( struct V_584 * V_585 ,
unsigned int V_586 , unsigned long V_587 )
{
void V_410 * V_588 = ( void V_410 * ) V_587 ;
long V_117 ;
switch ( V_586 ) {
case V_589 : {
struct V_590 V_410 * V_591 = V_588 ;
struct V_590 V_592 ;
unsigned V_522 ;
V_117 = - V_98 ;
if ( F_231 ( & V_592 , V_591 , sizeof V_592 ) )
goto V_111;
V_522 = V_592 . V_519 ;
V_592 . V_519 = V_593 + F_50 ( V_594 ) ;
if ( F_232 ( V_591 , & V_592 , sizeof V_592 ) )
goto V_111;
V_117 = - V_396 ;
if ( V_522 < V_592 . V_519 )
goto V_111;
V_117 = - V_98 ;
if ( F_232 ( V_591 -> V_595 , & V_596 ,
V_593 * sizeof( T_1 ) ) )
goto V_111;
if ( F_232 ( V_591 -> V_595 + V_593 ,
& V_594 ,
F_50 ( V_594 ) * sizeof( T_1 ) ) )
goto V_111;
V_117 = 0 ;
break;
}
case V_597 :
case V_598 : {
struct V_599 V_410 * V_600 = V_588 ;
struct V_599 V_601 ;
V_117 = - V_98 ;
if ( F_231 ( & V_601 , V_600 , sizeof V_601 ) )
goto V_111;
V_117 = F_238 ( & V_601 , V_600 -> V_517 ,
V_586 ) ;
if ( V_117 )
goto V_111;
V_117 = - V_98 ;
if ( F_232 ( V_600 , & V_601 , sizeof V_601 ) )
goto V_111;
V_117 = 0 ;
break;
}
case V_602 : {
T_2 V_603 ;
V_603 = V_604 ;
V_117 = - V_98 ;
if ( F_232 ( V_588 , & V_603 , sizeof V_603 ) )
goto V_111;
V_117 = 0 ;
break;
}
default:
V_117 = - V_605 ;
}
V_111:
return V_117 ;
}
static void F_239 ( void * V_606 )
{
F_240 () ;
}
static bool F_241 ( struct V_1 * V_2 )
{
return F_242 ( V_2 -> V_99 ) ;
}
void F_243 ( struct V_1 * V_2 , int V_23 )
{
if ( F_241 ( V_2 ) ) {
if ( V_73 -> V_607 () )
F_244 ( V_23 , V_2 -> V_5 . V_608 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_245 ( V_2 -> V_23 ,
F_239 , NULL , 1 ) ;
}
V_73 -> V_609 ( V_2 , V_23 ) ;
if ( F_150 ( V_2 -> V_5 . V_610 ) ) {
F_246 ( V_2 , V_2 -> V_5 . V_610 ) ;
V_2 -> V_5 . V_610 = 0 ;
F_31 ( V_320 , V_2 ) ;
}
if ( F_150 ( V_2 -> V_23 != V_23 ) || F_138 () ) {
T_12 V_611 = ! V_2 -> V_5 . V_612 ? 0 :
F_164 () - V_2 -> V_5 . V_612 ;
if ( V_611 < 0 )
F_247 ( L_21 ) ;
if ( F_138 () ) {
T_2 V_91 = V_73 -> V_296 ( V_2 ,
V_2 -> V_5 . V_308 ) ;
V_73 -> V_309 ( V_2 , V_91 ) ;
V_2 -> V_5 . V_331 = 1 ;
}
if ( ! V_2 -> V_99 -> V_5 . V_283 || V_2 -> V_23 == - 1 )
F_31 ( V_466 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_248 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_202 ( V_2 ) ;
F_31 ( V_471 , V_2 ) ;
}
void F_249 ( struct V_1 * V_2 )
{
V_73 -> V_613 ( V_2 ) ;
F_250 ( V_2 ) ;
V_2 -> V_5 . V_612 = F_164 () ;
}
static int F_251 ( struct V_1 * V_2 ,
struct V_614 * V_615 )
{
V_73 -> V_616 ( V_2 ) ;
memcpy ( V_615 -> V_617 , V_2 -> V_5 . V_618 -> V_617 , sizeof *V_615 ) ;
return 0 ;
}
static int F_252 ( struct V_1 * V_2 ,
struct V_614 * V_615 )
{
F_253 ( V_2 , V_615 ) ;
F_254 ( V_2 ) ;
return 0 ;
}
static int F_255 ( struct V_1 * V_2 ,
struct V_619 * V_620 )
{
if ( V_620 -> V_620 >= V_621 )
return - V_605 ;
if ( F_85 ( V_2 -> V_99 ) )
return - V_622 ;
F_256 ( V_2 , V_620 -> V_620 , false ) ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
static int F_257 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
return 0 ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_623 * V_624 )
{
if ( V_624 -> V_291 )
return - V_605 ;
V_2 -> V_5 . V_625 = ! ! V_624 -> V_368 ;
return 0 ;
}
static int F_259 ( struct V_1 * V_2 ,
T_2 V_376 )
{
int V_117 ;
unsigned V_377 = V_376 & 0xff , V_626 ;
V_117 = - V_605 ;
if ( ! V_377 || V_377 >= V_473 )
goto V_111;
if ( V_376 & ~ ( V_604 | 0xff | 0xff0000 ) )
goto V_111;
V_117 = 0 ;
V_2 -> V_5 . V_376 = V_376 ;
if ( V_376 & V_381 )
V_2 -> V_5 . V_382 = ~ ( T_2 ) 0 ;
for ( V_626 = 0 ; V_626 < V_377 ; V_626 ++ )
V_2 -> V_5 . V_384 [ V_626 * 4 ] = ~ ( T_2 ) 0 ;
V_111:
return V_117 ;
}
static int F_260 ( struct V_1 * V_2 ,
struct V_627 * V_628 )
{
T_2 V_376 = V_2 -> V_5 . V_376 ;
unsigned V_377 = V_376 & 0xff ;
T_2 * V_629 = V_2 -> V_5 . V_384 ;
if ( V_628 -> V_626 >= V_377 || ! ( V_628 -> V_494 & V_630 ) )
return - V_605 ;
if ( ( V_628 -> V_494 & V_631 ) && ( V_376 & V_381 ) &&
V_2 -> V_5 . V_382 != ~ ( T_2 ) 0 )
return 0 ;
V_629 += 4 * V_628 -> V_626 ;
if ( ( V_628 -> V_494 & V_631 ) && V_629 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_628 -> V_494 & V_631 ) {
if ( ( V_2 -> V_5 . V_379 & V_632 ) ||
! F_62 ( V_2 , V_633 ) ) {
F_31 ( V_72 , V_2 ) ;
return 0 ;
}
if ( V_629 [ 1 ] & V_630 )
V_628 -> V_494 |= V_634 ;
V_629 [ 2 ] = V_628 -> V_406 ;
V_629 [ 3 ] = V_628 -> V_635 ;
V_2 -> V_5 . V_379 = V_628 -> V_379 ;
V_629 [ 1 ] = V_628 -> V_494 ;
F_32 ( V_2 , V_58 ) ;
} else if ( ! ( V_629 [ 1 ] & V_630 )
|| ! ( V_629 [ 1 ] & V_631 ) ) {
if ( V_629 [ 1 ] & V_630 )
V_628 -> V_494 |= V_634 ;
V_629 [ 2 ] = V_628 -> V_406 ;
V_629 [ 3 ] = V_628 -> V_635 ;
V_629 [ 1 ] = V_628 -> V_494 ;
} else
V_629 [ 1 ] |= V_634 ;
return 0 ;
}
static void F_261 ( struct V_1 * V_2 ,
struct V_636 * V_637 )
{
F_262 ( V_2 ) ;
V_637 -> V_68 . V_638 =
V_2 -> V_5 . V_68 . V_69 &&
! F_263 ( V_2 -> V_5 . V_68 . V_16 ) ;
V_637 -> V_68 . V_16 = V_2 -> V_5 . V_68 . V_16 ;
V_637 -> V_68 . V_71 = V_2 -> V_5 . V_68 . V_71 ;
V_637 -> V_68 . V_639 = 0 ;
V_637 -> V_68 . V_62 = V_2 -> V_5 . V_68 . V_62 ;
V_637 -> V_640 . V_638 =
V_2 -> V_5 . V_640 . V_69 && ! V_2 -> V_5 . V_640 . V_641 ;
V_637 -> V_640 . V_16 = V_2 -> V_5 . V_640 . V_16 ;
V_637 -> V_640 . V_641 = 0 ;
V_637 -> V_640 . V_642 = V_73 -> V_643 ( V_2 ) ;
V_637 -> V_644 . V_638 = V_2 -> V_5 . V_645 ;
V_637 -> V_644 . V_69 = V_2 -> V_5 . V_646 != 0 ;
V_637 -> V_644 . V_647 = V_73 -> V_648 ( V_2 ) ;
V_637 -> V_644 . V_639 = 0 ;
V_637 -> V_649 = 0 ;
V_637 -> V_291 = ( V_650
| V_651 ) ;
memset ( & V_637 -> V_652 , 0 , sizeof( V_637 -> V_652 ) ) ;
}
static int F_264 ( struct V_1 * V_2 ,
struct V_636 * V_637 )
{
if ( V_637 -> V_291 & ~ ( V_650
| V_653
| V_651 ) )
return - V_605 ;
F_262 ( V_2 ) ;
V_2 -> V_5 . V_68 . V_69 = V_637 -> V_68 . V_638 ;
V_2 -> V_5 . V_68 . V_16 = V_637 -> V_68 . V_16 ;
V_2 -> V_5 . V_68 . V_71 = V_637 -> V_68 . V_71 ;
V_2 -> V_5 . V_68 . V_62 = V_637 -> V_68 . V_62 ;
V_2 -> V_5 . V_640 . V_69 = V_637 -> V_640 . V_638 ;
V_2 -> V_5 . V_640 . V_16 = V_637 -> V_640 . V_16 ;
V_2 -> V_5 . V_640 . V_641 = V_637 -> V_640 . V_641 ;
if ( V_637 -> V_291 & V_651 )
V_73 -> V_654 ( V_2 ,
V_637 -> V_640 . V_642 ) ;
V_2 -> V_5 . V_645 = V_637 -> V_644 . V_638 ;
if ( V_637 -> V_291 & V_650 )
V_2 -> V_5 . V_646 = V_637 -> V_644 . V_69 ;
V_73 -> V_655 ( V_2 , V_637 -> V_644 . V_647 ) ;
if ( V_637 -> V_291 & V_653 &&
F_265 ( V_2 ) )
V_2 -> V_5 . V_618 -> V_649 = V_637 -> V_649 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
static void F_266 ( struct V_1 * V_2 ,
struct V_656 * V_657 )
{
unsigned long V_184 ;
memcpy ( V_657 -> V_185 , V_2 -> V_5 . V_185 , sizeof( V_2 -> V_5 . V_185 ) ) ;
F_95 ( V_2 , 6 , & V_184 ) ;
V_657 -> V_173 = V_184 ;
V_657 -> V_174 = V_2 -> V_5 . V_174 ;
V_657 -> V_291 = 0 ;
memset ( & V_657 -> V_652 , 0 , sizeof( V_657 -> V_652 ) ) ;
}
static int F_267 ( struct V_1 * V_2 ,
struct V_656 * V_657 )
{
if ( V_657 -> V_291 )
return - V_605 ;
memcpy ( V_2 -> V_5 . V_185 , V_657 -> V_185 , sizeof( V_2 -> V_5 . V_185 ) ) ;
V_2 -> V_5 . V_173 = V_657 -> V_173 ;
F_89 ( V_2 ) ;
V_2 -> V_5 . V_174 = V_657 -> V_174 ;
F_90 ( V_2 ) ;
return 0 ;
}
static void F_268 ( struct V_1 * V_2 ,
struct V_658 * V_659 )
{
if ( V_579 ) {
memcpy ( V_659 -> V_660 ,
& V_2 -> V_5 . V_661 . V_662 -> V_663 ,
V_2 -> V_5 . V_664 ) ;
* ( T_2 * ) & V_659 -> V_660 [ V_665 / sizeof( T_1 ) ] &=
V_2 -> V_5 . V_148 | V_666 ;
} else {
memcpy ( V_659 -> V_660 ,
& V_2 -> V_5 . V_661 . V_662 -> V_667 ,
sizeof( struct V_668 ) ) ;
* ( T_2 * ) & V_659 -> V_660 [ V_665 / sizeof( T_1 ) ] =
V_666 ;
}
}
static int F_269 ( struct V_1 * V_2 ,
struct V_658 * V_659 )
{
T_2 V_669 =
* ( T_2 * ) & V_659 -> V_660 [ V_665 / sizeof( T_1 ) ] ;
if ( V_579 ) {
if ( V_669 & ~ F_270 () )
return - V_605 ;
memcpy ( & V_2 -> V_5 . V_661 . V_662 -> V_663 ,
V_659 -> V_660 , V_2 -> V_5 . V_664 ) ;
} else {
if ( V_669 & ~ V_666 )
return - V_605 ;
memcpy ( & V_2 -> V_5 . V_661 . V_662 -> V_667 ,
V_659 -> V_660 , sizeof( struct V_668 ) ) ;
}
return 0 ;
}
static void F_271 ( struct V_1 * V_2 ,
struct V_670 * V_671 )
{
if ( ! V_579 ) {
V_671 -> V_672 = 0 ;
return;
}
V_671 -> V_672 = 1 ;
V_671 -> V_291 = 0 ;
V_671 -> V_673 [ 0 ] . V_142 = V_138 ;
V_671 -> V_673 [ 0 ] . V_22 = V_2 -> V_5 . V_139 ;
}
static int F_272 ( struct V_1 * V_2 ,
struct V_670 * V_671 )
{
int V_3 , V_117 = 0 ;
if ( ! V_579 )
return - V_605 ;
if ( V_671 -> V_672 > V_674 || V_671 -> V_291 )
return - V_605 ;
for ( V_3 = 0 ; V_3 < V_671 -> V_672 ; V_3 ++ )
if ( V_671 -> V_673 [ V_3 ] . V_142 == V_138 ) {
V_117 = F_70 ( V_2 , V_138 ,
V_671 -> V_673 [ V_3 ] . V_22 ) ;
break;
}
if ( V_117 )
V_117 = - V_605 ;
return V_117 ;
}
static int F_273 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_332 )
return - V_605 ;
V_2 -> V_5 . V_340 = true ;
F_31 ( V_320 , V_2 ) ;
return 0 ;
}
long F_274 ( struct V_584 * V_585 ,
unsigned int V_586 , unsigned long V_587 )
{
struct V_1 * V_2 = V_585 -> V_675 ;
void V_410 * V_588 = ( void V_410 * ) V_587 ;
int V_117 ;
union {
struct V_614 * V_676 ;
struct V_658 * V_663 ;
struct V_670 * V_673 ;
void * V_677 ;
} V_678 ;
V_678 . V_677 = NULL ;
switch ( V_586 ) {
case V_679 : {
V_117 = - V_605 ;
if ( ! V_2 -> V_5 . V_618 )
goto V_111;
V_678 . V_676 = F_275 ( sizeof( struct V_614 ) , V_680 ) ;
V_117 = - V_397 ;
if ( ! V_678 . V_676 )
goto V_111;
V_117 = F_251 ( V_2 , V_678 . V_676 ) ;
if ( V_117 )
goto V_111;
V_117 = - V_98 ;
if ( F_232 ( V_588 , V_678 . V_676 , sizeof( struct V_614 ) ) )
goto V_111;
V_117 = 0 ;
break;
}
case V_681 : {
V_117 = - V_605 ;
if ( ! V_2 -> V_5 . V_618 )
goto V_111;
V_678 . V_676 = F_182 ( V_588 , sizeof( * V_678 . V_676 ) ) ;
if ( F_183 ( V_678 . V_676 ) )
return F_184 ( V_678 . V_676 ) ;
V_117 = F_252 ( V_2 , V_678 . V_676 ) ;
break;
}
case V_682 : {
struct V_619 V_620 ;
V_117 = - V_98 ;
if ( F_231 ( & V_620 , V_588 , sizeof V_620 ) )
goto V_111;
V_117 = F_255 ( V_2 , & V_620 ) ;
break;
}
case V_683 : {
V_117 = F_257 ( V_2 ) ;
break;
}
case V_684 : {
struct V_685 V_410 * V_600 = V_588 ;
struct V_685 V_601 ;
V_117 = - V_98 ;
if ( F_231 ( & V_601 , V_600 , sizeof V_601 ) )
goto V_111;
V_117 = F_276 ( V_2 , & V_601 , V_600 -> V_517 ) ;
break;
}
case V_686 : {
struct V_599 V_410 * V_600 = V_588 ;
struct V_599 V_601 ;
V_117 = - V_98 ;
if ( F_231 ( & V_601 , V_600 , sizeof V_601 ) )
goto V_111;
V_117 = F_277 ( V_2 , & V_601 ,
V_600 -> V_517 ) ;
break;
}
case V_687 : {
struct V_599 V_410 * V_600 = V_588 ;
struct V_599 V_601 ;
V_117 = - V_98 ;
if ( F_231 ( & V_601 , V_600 , sizeof V_601 ) )
goto V_111;
V_117 = F_278 ( V_2 , & V_601 ,
V_600 -> V_517 ) ;
if ( V_117 )
goto V_111;
V_117 = - V_98 ;
if ( F_232 ( V_600 , & V_601 , sizeof V_601 ) )
goto V_111;
V_117 = 0 ;
break;
}
case V_688 :
V_117 = F_230 ( V_2 , V_588 , F_215 , 1 ) ;
break;
case V_689 :
V_117 = F_230 ( V_2 , V_588 , F_109 , 0 ) ;
break;
case V_690 : {
struct V_623 V_624 ;
V_117 = - V_98 ;
if ( F_231 ( & V_624 , V_588 , sizeof V_624 ) )
goto V_111;
V_117 = F_258 ( V_2 , & V_624 ) ;
if ( V_117 )
goto V_111;
V_117 = - V_98 ;
if ( F_232 ( V_588 , & V_624 , sizeof V_624 ) )
goto V_111;
V_117 = 0 ;
break;
} ;
case V_691 : {
struct V_692 V_693 ;
V_117 = - V_605 ;
if ( ! F_85 ( V_2 -> V_99 ) )
goto V_111;
V_117 = - V_98 ;
if ( F_231 ( & V_693 , V_588 , sizeof V_693 ) )
goto V_111;
V_117 = F_279 ( V_2 , V_693 . V_694 ) ;
break;
}
case V_695 : {
T_2 V_376 ;
V_117 = - V_98 ;
if ( F_231 ( & V_376 , V_588 , sizeof V_376 ) )
goto V_111;
V_117 = F_259 ( V_2 , V_376 ) ;
break;
}
case V_696 : {
struct V_627 V_628 ;
V_117 = - V_98 ;
if ( F_231 ( & V_628 , V_588 , sizeof V_628 ) )
goto V_111;
V_117 = F_260 ( V_2 , & V_628 ) ;
break;
}
case V_697 : {
struct V_636 V_637 ;
F_261 ( V_2 , & V_637 ) ;
V_117 = - V_98 ;
if ( F_232 ( V_588 , & V_637 , sizeof( struct V_636 ) ) )
break;
V_117 = 0 ;
break;
}
case V_698 : {
struct V_636 V_637 ;
V_117 = - V_98 ;
if ( F_231 ( & V_637 , V_588 , sizeof( struct V_636 ) ) )
break;
V_117 = F_264 ( V_2 , & V_637 ) ;
break;
}
case V_699 : {
struct V_656 V_657 ;
F_266 ( V_2 , & V_657 ) ;
V_117 = - V_98 ;
if ( F_232 ( V_588 , & V_657 ,
sizeof( struct V_656 ) ) )
break;
V_117 = 0 ;
break;
}
case V_700 : {
struct V_656 V_657 ;
V_117 = - V_98 ;
if ( F_231 ( & V_657 , V_588 ,
sizeof( struct V_656 ) ) )
break;
V_117 = F_267 ( V_2 , & V_657 ) ;
break;
}
case V_701 : {
V_678 . V_663 = F_275 ( sizeof( struct V_658 ) , V_680 ) ;
V_117 = - V_397 ;
if ( ! V_678 . V_663 )
break;
F_268 ( V_2 , V_678 . V_663 ) ;
V_117 = - V_98 ;
if ( F_232 ( V_588 , V_678 . V_663 , sizeof( struct V_658 ) ) )
break;
V_117 = 0 ;
break;
}
case V_702 : {
V_678 . V_663 = F_182 ( V_588 , sizeof( * V_678 . V_663 ) ) ;
if ( F_183 ( V_678 . V_663 ) )
return F_184 ( V_678 . V_663 ) ;
V_117 = F_269 ( V_2 , V_678 . V_663 ) ;
break;
}
case V_703 : {
V_678 . V_673 = F_275 ( sizeof( struct V_670 ) , V_680 ) ;
V_117 = - V_397 ;
if ( ! V_678 . V_673 )
break;
F_271 ( V_2 , V_678 . V_673 ) ;
V_117 = - V_98 ;
if ( F_232 ( V_588 , V_678 . V_673 ,
sizeof( struct V_670 ) ) )
break;
V_117 = 0 ;
break;
}
case V_704 : {
V_678 . V_673 = F_182 ( V_588 , sizeof( * V_678 . V_673 ) ) ;
if ( F_183 ( V_678 . V_673 ) )
return F_184 ( V_678 . V_673 ) ;
V_117 = F_272 ( V_2 , V_678 . V_673 ) ;
break;
}
case V_705 : {
T_1 V_706 ;
V_117 = - V_605 ;
V_706 = ( T_1 ) V_587 ;
if ( V_706 >= V_707 )
goto V_111;
if ( V_706 == 0 )
V_706 = V_268 ;
F_130 ( V_2 , V_706 ) ;
V_117 = 0 ;
goto V_111;
}
case V_708 : {
V_117 = V_2 -> V_5 . V_267 ;
goto V_111;
}
case V_709 : {
V_117 = F_273 ( V_2 ) ;
goto V_111;
}
default:
V_117 = - V_605 ;
}
V_111:
F_185 ( V_678 . V_677 ) ;
return V_117 ;
}
int F_280 ( struct V_1 * V_2 , struct V_710 * V_711 )
{
return V_712 ;
}
static int F_281 ( struct V_99 * V_99 , unsigned long V_406 )
{
int V_106 ;
if ( V_406 > ( unsigned int ) ( - 3 * V_105 ) )
return - V_605 ;
V_106 = V_73 -> V_713 ( V_99 , V_406 ) ;
return V_106 ;
}
static int F_282 ( struct V_99 * V_99 ,
T_2 V_714 )
{
V_99 -> V_5 . V_715 = V_714 ;
return 0 ;
}
static int F_283 ( struct V_99 * V_99 ,
T_1 V_716 )
{
if ( V_716 < V_717 )
return - V_605 ;
F_212 ( & V_99 -> V_718 ) ;
F_284 ( V_99 , V_716 ) ;
V_99 -> V_5 . V_719 = V_716 ;
F_213 ( & V_99 -> V_718 ) ;
return 0 ;
}
static int F_285 ( struct V_99 * V_99 )
{
return V_99 -> V_5 . V_720 ;
}
static int F_286 ( struct V_99 * V_99 , struct V_721 * V_722 )
{
int V_117 ;
V_117 = 0 ;
switch ( V_722 -> V_723 ) {
case V_724 :
memcpy ( & V_722 -> V_722 . V_725 ,
& F_287 ( V_99 ) -> V_726 [ 0 ] ,
sizeof( struct V_727 ) ) ;
break;
case V_728 :
memcpy ( & V_722 -> V_722 . V_725 ,
& F_287 ( V_99 ) -> V_726 [ 1 ] ,
sizeof( struct V_727 ) ) ;
break;
case V_729 :
V_117 = F_288 ( V_99 , & V_722 -> V_722 . V_730 ) ;
break;
default:
V_117 = - V_605 ;
break;
}
return V_117 ;
}
static int F_289 ( struct V_99 * V_99 , struct V_721 * V_722 )
{
int V_117 ;
V_117 = 0 ;
switch ( V_722 -> V_723 ) {
case V_724 :
F_141 ( & F_287 ( V_99 ) -> V_488 ) ;
memcpy ( & F_287 ( V_99 ) -> V_726 [ 0 ] ,
& V_722 -> V_722 . V_725 ,
sizeof( struct V_727 ) ) ;
F_142 ( & F_287 ( V_99 ) -> V_488 ) ;
break;
case V_728 :
F_141 ( & F_287 ( V_99 ) -> V_488 ) ;
memcpy ( & F_287 ( V_99 ) -> V_726 [ 1 ] ,
& V_722 -> V_722 . V_725 ,
sizeof( struct V_727 ) ) ;
F_142 ( & F_287 ( V_99 ) -> V_488 ) ;
break;
case V_729 :
V_117 = F_290 ( V_99 , & V_722 -> V_722 . V_730 ) ;
break;
default:
V_117 = - V_605 ;
break;
}
F_291 ( F_287 ( V_99 ) ) ;
return V_117 ;
}
static int F_292 ( struct V_99 * V_99 , struct V_731 * V_732 )
{
int V_117 = 0 ;
F_212 ( & V_99 -> V_5 . V_733 -> V_734 . V_488 ) ;
memcpy ( V_732 , & V_99 -> V_5 . V_733 -> V_734 , sizeof( struct V_731 ) ) ;
F_213 ( & V_99 -> V_5 . V_733 -> V_734 . V_488 ) ;
return V_117 ;
}
static int F_293 ( struct V_99 * V_99 , struct V_731 * V_732 )
{
int V_117 = 0 ;
F_212 ( & V_99 -> V_5 . V_733 -> V_734 . V_488 ) ;
memcpy ( & V_99 -> V_5 . V_733 -> V_734 , V_732 , sizeof( struct V_731 ) ) ;
F_294 ( V_99 , 0 , V_732 -> V_735 [ 0 ] . V_736 , 0 ) ;
F_213 ( & V_99 -> V_5 . V_733 -> V_734 . V_488 ) ;
return V_117 ;
}
static int F_295 ( struct V_99 * V_99 , struct V_737 * V_732 )
{
int V_117 = 0 ;
F_212 ( & V_99 -> V_5 . V_733 -> V_734 . V_488 ) ;
memcpy ( V_732 -> V_735 , & V_99 -> V_5 . V_733 -> V_734 . V_735 ,
sizeof( V_732 -> V_735 ) ) ;
V_732 -> V_291 = V_99 -> V_5 . V_733 -> V_734 . V_291 ;
F_213 ( & V_99 -> V_5 . V_733 -> V_734 . V_488 ) ;
memset ( & V_732 -> V_652 , 0 , sizeof( V_732 -> V_652 ) ) ;
return V_117 ;
}
static int F_296 ( struct V_99 * V_99 , struct V_737 * V_732 )
{
int V_117 = 0 , V_738 = 0 ;
T_1 V_739 , V_740 ;
F_212 ( & V_99 -> V_5 . V_733 -> V_734 . V_488 ) ;
V_739 = V_99 -> V_5 . V_733 -> V_734 . V_291 & V_741 ;
V_740 = V_732 -> V_291 & V_741 ;
if ( ! V_739 && V_740 )
V_738 = 1 ;
memcpy ( & V_99 -> V_5 . V_733 -> V_734 . V_735 , & V_732 -> V_735 ,
sizeof( V_99 -> V_5 . V_733 -> V_734 . V_735 ) ) ;
V_99 -> V_5 . V_733 -> V_734 . V_291 = V_732 -> V_291 ;
F_294 ( V_99 , 0 , V_99 -> V_5 . V_733 -> V_734 . V_735 [ 0 ] . V_736 , V_738 ) ;
F_213 ( & V_99 -> V_5 . V_733 -> V_734 . V_488 ) ;
return V_117 ;
}
static int F_297 ( struct V_99 * V_99 ,
struct V_742 * V_743 )
{
if ( ! V_99 -> V_5 . V_733 )
return - V_622 ;
F_212 ( & V_99 -> V_5 . V_733 -> V_734 . V_488 ) ;
V_99 -> V_5 . V_733 -> V_734 . V_63 = V_743 -> V_744 ;
F_213 ( & V_99 -> V_5 . V_733 -> V_734 . V_488 ) ;
return 0 ;
}
int F_298 ( struct V_99 * V_99 , struct V_745 * log )
{
int V_117 ;
struct V_746 * V_747 ;
unsigned long V_522 , V_3 ;
unsigned long * V_748 ;
unsigned long * V_749 ;
bool V_750 = false ;
F_212 ( & V_99 -> V_718 ) ;
V_117 = - V_605 ;
if ( log -> V_10 >= V_573 )
goto V_111;
V_747 = F_299 ( V_99 -> V_751 , log -> V_10 ) ;
V_748 = V_747 -> V_748 ;
V_117 = - V_752 ;
if ( ! V_748 )
goto V_111;
V_522 = F_300 ( V_747 ) ;
V_749 = V_748 + V_522 / sizeof( long ) ;
memset ( V_749 , 0 , V_522 ) ;
F_141 ( & V_99 -> V_753 ) ;
for ( V_3 = 0 ; V_3 < V_522 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_28 ;
T_5 V_91 ;
if ( ! V_748 [ V_3 ] )
continue;
V_750 = true ;
V_28 = F_301 ( & V_748 [ V_3 ] , 0 ) ;
V_749 [ V_3 ] = V_28 ;
V_91 = V_3 * V_754 ;
F_302 ( V_99 , V_747 , V_91 , V_28 ) ;
}
F_142 ( & V_99 -> V_753 ) ;
F_303 ( & V_99 -> V_718 ) ;
if ( V_750 )
F_304 ( V_99 ) ;
V_117 = - V_98 ;
if ( F_232 ( log -> V_748 , V_749 , V_522 ) )
goto V_111;
V_117 = 0 ;
V_111:
F_213 ( & V_99 -> V_718 ) ;
return V_117 ;
}
int F_305 ( struct V_99 * V_99 , struct V_755 * V_756 ,
bool V_757 )
{
if ( ! F_85 ( V_99 ) )
return - V_622 ;
V_756 -> V_494 = F_306 ( V_99 , V_758 ,
V_756 -> V_620 , V_756 -> V_759 ,
V_757 ) ;
return 0 ;
}
long F_307 ( struct V_584 * V_585 ,
unsigned int V_586 , unsigned long V_587 )
{
struct V_99 * V_99 = V_585 -> V_675 ;
void V_410 * V_588 = ( void V_410 * ) V_587 ;
int V_117 = - V_760 ;
union {
struct V_731 V_732 ;
struct V_737 V_761 ;
struct V_762 V_763 ;
} V_678 ;
switch ( V_586 ) {
case V_764 :
V_117 = F_281 ( V_99 , V_587 ) ;
break;
case V_765 : {
T_2 V_714 ;
V_117 = - V_98 ;
if ( F_231 ( & V_714 , V_588 , sizeof V_714 ) )
goto V_111;
V_117 = F_282 ( V_99 , V_714 ) ;
break;
}
case V_766 :
V_117 = F_283 ( V_99 , V_587 ) ;
break;
case V_767 :
V_117 = F_285 ( V_99 ) ;
break;
case V_768 : {
struct V_769 * V_770 ;
F_212 ( & V_99 -> V_488 ) ;
V_117 = - V_771 ;
if ( V_99 -> V_5 . V_770 )
goto V_772;
V_117 = - V_605 ;
if ( F_133 ( & V_99 -> V_281 ) )
goto V_772;
V_117 = - V_397 ;
V_770 = F_308 ( V_99 ) ;
if ( V_770 ) {
V_117 = F_309 ( V_99 ) ;
if ( V_117 ) {
F_212 ( & V_99 -> V_718 ) ;
F_310 ( V_99 , V_773 ,
& V_770 -> V_774 ) ;
F_310 ( V_99 , V_773 ,
& V_770 -> V_775 ) ;
F_310 ( V_99 , V_773 ,
& V_770 -> V_776 ) ;
F_213 ( & V_99 -> V_718 ) ;
F_185 ( V_770 ) ;
goto V_772;
}
} else
goto V_772;
F_14 () ;
V_99 -> V_5 . V_770 = V_770 ;
F_14 () ;
V_117 = F_311 ( V_99 ) ;
if ( V_117 ) {
F_212 ( & V_99 -> V_718 ) ;
F_212 ( & V_99 -> V_777 ) ;
F_312 ( V_99 ) ;
F_313 ( V_99 ) ;
F_213 ( & V_99 -> V_777 ) ;
F_213 ( & V_99 -> V_718 ) ;
}
V_772:
F_213 ( & V_99 -> V_488 ) ;
break;
}
case V_778 :
V_678 . V_763 . V_291 = V_779 ;
goto V_780;
case V_781 :
V_117 = - V_98 ;
if ( F_231 ( & V_678 . V_763 , V_588 ,
sizeof( struct V_762 ) ) )
goto V_111;
V_780:
F_212 ( & V_99 -> V_718 ) ;
V_117 = - V_771 ;
if ( V_99 -> V_5 . V_733 )
goto V_782;
V_117 = - V_397 ;
V_99 -> V_5 . V_733 = F_314 ( V_99 , V_678 . V_763 . V_291 ) ;
if ( V_99 -> V_5 . V_733 )
V_117 = 0 ;
V_782:
F_213 ( & V_99 -> V_718 ) ;
break;
case V_783 : {
struct V_721 * V_722 ;
V_722 = F_182 ( V_588 , sizeof( * V_722 ) ) ;
if ( F_183 ( V_722 ) ) {
V_117 = F_184 ( V_722 ) ;
goto V_111;
}
V_117 = - V_622 ;
if ( ! F_85 ( V_99 ) )
goto V_784;
V_117 = F_286 ( V_99 , V_722 ) ;
if ( V_117 )
goto V_784;
V_117 = - V_98 ;
if ( F_232 ( V_588 , V_722 , sizeof *V_722 ) )
goto V_784;
V_117 = 0 ;
V_784:
F_185 ( V_722 ) ;
break;
}
case V_785 : {
struct V_721 * V_722 ;
V_722 = F_182 ( V_588 , sizeof( * V_722 ) ) ;
if ( F_183 ( V_722 ) ) {
V_117 = F_184 ( V_722 ) ;
goto V_111;
}
V_117 = - V_622 ;
if ( ! F_85 ( V_99 ) )
goto V_786;
V_117 = F_289 ( V_99 , V_722 ) ;
if ( V_117 )
goto V_786;
V_117 = 0 ;
V_786:
F_185 ( V_722 ) ;
break;
}
case V_787 : {
V_117 = - V_98 ;
if ( F_231 ( & V_678 . V_732 , V_588 , sizeof( struct V_731 ) ) )
goto V_111;
V_117 = - V_622 ;
if ( ! V_99 -> V_5 . V_733 )
goto V_111;
V_117 = F_292 ( V_99 , & V_678 . V_732 ) ;
if ( V_117 )
goto V_111;
V_117 = - V_98 ;
if ( F_232 ( V_588 , & V_678 . V_732 , sizeof( struct V_731 ) ) )
goto V_111;
V_117 = 0 ;
break;
}
case V_788 : {
V_117 = - V_98 ;
if ( F_231 ( & V_678 . V_732 , V_588 , sizeof V_678 . V_732 ) )
goto V_111;
V_117 = - V_622 ;
if ( ! V_99 -> V_5 . V_733 )
goto V_111;
V_117 = F_293 ( V_99 , & V_678 . V_732 ) ;
break;
}
case V_789 : {
V_117 = - V_622 ;
if ( ! V_99 -> V_5 . V_733 )
goto V_111;
V_117 = F_295 ( V_99 , & V_678 . V_761 ) ;
if ( V_117 )
goto V_111;
V_117 = - V_98 ;
if ( F_232 ( V_588 , & V_678 . V_761 , sizeof( V_678 . V_761 ) ) )
goto V_111;
V_117 = 0 ;
break;
}
case V_790 : {
V_117 = - V_98 ;
if ( F_231 ( & V_678 . V_761 , V_588 , sizeof( V_678 . V_761 ) ) )
goto V_111;
V_117 = - V_622 ;
if ( ! V_99 -> V_5 . V_733 )
goto V_111;
V_117 = F_296 ( V_99 , & V_678 . V_761 ) ;
break;
}
case V_791 : {
struct V_742 V_743 ;
V_117 = - V_98 ;
if ( F_231 ( & V_743 , V_588 , sizeof( V_743 ) ) )
goto V_111;
V_117 = F_297 ( V_99 , & V_743 ) ;
break;
}
case V_792 : {
V_117 = - V_98 ;
if ( F_231 ( & V_99 -> V_5 . F_181 , V_588 ,
sizeof( struct V_793 ) ) )
goto V_111;
V_117 = - V_605 ;
if ( V_99 -> V_5 . F_181 . V_291 )
goto V_111;
V_117 = 0 ;
break;
}
case V_794 : {
struct V_795 V_796 ;
T_2 V_797 ;
T_12 V_303 ;
V_117 = - V_98 ;
if ( F_231 ( & V_796 , V_588 , sizeof( V_796 ) ) )
goto V_111;
V_117 = - V_605 ;
if ( V_796 . V_291 )
goto V_111;
V_117 = 0 ;
F_315 () ;
V_797 = F_124 () ;
V_303 = V_796 . clock - V_797 ;
F_316 () ;
V_99 -> V_5 . V_239 = V_303 ;
F_156 ( V_99 ) ;
break;
}
case V_798 : {
struct V_795 V_796 ;
T_2 V_797 ;
F_315 () ;
V_797 = F_124 () ;
V_796 . clock = V_99 -> V_5 . V_239 + V_797 ;
F_316 () ;
V_796 . V_291 = 0 ;
memset ( & V_796 . V_639 , 0 , sizeof( V_796 . V_639 ) ) ;
V_117 = - V_98 ;
if ( F_232 ( V_588 , & V_796 , sizeof( V_796 ) ) )
goto V_111;
V_117 = 0 ;
break;
}
default:
;
}
V_111:
return V_117 ;
}
static void F_317 ( void )
{
T_1 V_799 [ 2 ] ;
unsigned V_3 , V_800 ;
for ( V_3 = V_800 = V_801 ; V_3 < F_50 ( V_596 ) ; V_3 ++ ) {
if ( F_318 ( V_596 [ V_3 ] , & V_799 [ 0 ] , & V_799 [ 1 ] ) < 0 )
continue;
switch ( V_596 [ V_3 ] ) {
case V_802 :
if ( ! V_73 -> V_803 () )
continue;
break;
default:
break;
}
if ( V_800 < V_3 )
V_596 [ V_800 ] = V_596 [ V_3 ] ;
V_800 ++ ;
}
V_593 = V_800 ;
}
static int F_319 ( struct V_1 * V_2 , T_6 V_406 , int V_92 ,
const void * V_261 )
{
int V_804 = 0 ;
int V_522 ;
do {
V_522 = F_320 ( V_92 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_618 &&
! F_321 ( & V_2 -> V_5 . V_618 -> V_805 , V_406 , V_522 , V_261 ) )
&& F_322 ( V_2 -> V_99 , V_806 , V_406 , V_522 , V_261 ) )
break;
V_804 += V_522 ;
V_406 += V_522 ;
V_92 -= V_522 ;
V_261 += V_522 ;
} while ( V_92 );
return V_804 ;
}
static int F_323 ( struct V_1 * V_2 , T_6 V_406 , int V_92 , void * V_261 )
{
int V_804 = 0 ;
int V_522 ;
do {
V_522 = F_320 ( V_92 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_618 &&
! F_324 ( & V_2 -> V_5 . V_618 -> V_805 , V_406 , V_522 , V_261 ) )
&& F_325 ( V_2 -> V_99 , V_806 , V_406 , V_522 , V_261 ) )
break;
F_326 ( V_807 , V_522 , V_406 , * ( T_2 * ) V_261 ) ;
V_804 += V_522 ;
V_406 += V_522 ;
V_92 -= V_522 ;
V_261 += V_522 ;
} while ( V_92 );
return V_804 ;
}
static void F_327 ( struct V_1 * V_2 ,
struct V_808 * V_809 , int V_810 )
{
V_73 -> V_811 ( V_2 , V_809 , V_810 ) ;
}
void F_328 ( struct V_1 * V_2 ,
struct V_808 * V_809 , int V_810 )
{
V_73 -> V_812 ( V_2 , V_809 , V_810 ) ;
}
T_6 F_329 ( struct V_1 * V_2 , T_6 V_426 , T_1 V_93 ,
struct V_75 * V_68 )
{
T_6 V_813 ;
F_13 ( ! F_39 ( V_2 ) ) ;
V_93 |= V_109 ;
V_813 = V_2 -> V_5 . V_84 . V_814 ( V_2 , V_426 , V_93 , V_68 ) ;
return V_813 ;
}
T_6 F_330 ( struct V_1 * V_2 , T_16 V_815 ,
struct V_75 * V_68 )
{
T_1 V_93 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_109 : 0 ;
return V_2 -> V_5 . V_101 -> V_814 ( V_2 , V_815 , V_93 , V_68 ) ;
}
T_6 F_331 ( struct V_1 * V_2 , T_16 V_815 ,
struct V_75 * V_68 )
{
T_1 V_93 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_109 : 0 ;
V_93 |= V_816 ;
return V_2 -> V_5 . V_101 -> V_814 ( V_2 , V_815 , V_93 , V_68 ) ;
}
T_6 F_332 ( struct V_1 * V_2 , T_16 V_815 ,
struct V_75 * V_68 )
{
T_1 V_93 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_109 : 0 ;
V_93 |= V_110 ;
return V_2 -> V_5 . V_101 -> V_814 ( V_2 , V_815 , V_93 , V_68 ) ;
}
T_6 F_333 ( struct V_1 * V_2 , T_16 V_815 ,
struct V_75 * V_68 )
{
return V_2 -> V_5 . V_101 -> V_814 ( V_2 , V_815 , 0 , V_68 ) ;
}
static int F_334 ( T_16 V_406 , void * V_184 , unsigned int V_817 ,
struct V_1 * V_2 , T_1 V_93 ,
struct V_75 * V_68 )
{
void * V_38 = V_184 ;
int V_117 = V_818 ;
while ( V_817 ) {
T_6 V_426 = V_2 -> V_5 . V_101 -> V_814 ( V_2 , V_406 , V_93 ,
V_68 ) ;
unsigned V_91 = V_406 & ( V_105 - 1 ) ;
unsigned V_819 = F_320 ( V_817 , ( unsigned ) V_105 - V_91 ) ;
int V_106 ;
if ( V_426 == V_97 )
return V_820 ;
V_106 = F_47 ( V_2 -> V_99 , V_426 >> V_104 , V_38 ,
V_91 , V_819 ) ;
if ( V_106 < 0 ) {
V_117 = V_821 ;
goto V_111;
}
V_817 -= V_819 ;
V_38 += V_819 ;
V_406 += V_819 ;
}
V_111:
return V_117 ;
}
static int F_335 ( struct V_822 * V_823 ,
T_16 V_406 , void * V_184 , unsigned int V_817 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
T_1 V_93 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_109 : 0 ;
unsigned V_91 ;
int V_106 ;
T_6 V_426 = V_2 -> V_5 . V_101 -> V_814 ( V_2 , V_406 , V_93 | V_816 ,
V_68 ) ;
if ( F_150 ( V_426 == V_97 ) )
return V_820 ;
V_91 = V_406 & ( V_105 - 1 ) ;
if ( F_29 ( V_91 + V_817 > V_105 ) )
V_817 = ( unsigned ) V_105 - V_91 ;
V_106 = F_47 ( V_2 -> V_99 , V_426 >> V_104 , V_184 ,
V_91 , V_817 ) ;
if ( F_150 ( V_106 < 0 ) )
return V_821 ;
return V_818 ;
}
int F_337 ( struct V_822 * V_823 ,
T_16 V_406 , void * V_184 , unsigned int V_817 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
T_1 V_93 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_109 : 0 ;
return F_334 ( V_406 , V_184 , V_817 , V_2 , V_93 ,
V_68 ) ;
}
static int F_338 ( struct V_822 * V_823 ,
T_16 V_406 , void * V_184 , unsigned int V_817 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
return F_334 ( V_406 , V_184 , V_817 , V_2 , 0 , V_68 ) ;
}
int F_339 ( struct V_822 * V_823 ,
T_16 V_406 , void * V_184 ,
unsigned int V_817 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
void * V_38 = V_184 ;
int V_117 = V_818 ;
while ( V_817 ) {
T_6 V_426 = V_2 -> V_5 . V_101 -> V_814 ( V_2 , V_406 ,
V_110 ,
V_68 ) ;
unsigned V_91 = V_406 & ( V_105 - 1 ) ;
unsigned V_824 = F_320 ( V_817 , ( unsigned ) V_105 - V_91 ) ;
int V_106 ;
if ( V_426 == V_97 )
return V_820 ;
V_106 = F_117 ( V_2 -> V_99 , V_426 , V_38 , V_824 ) ;
if ( V_106 < 0 ) {
V_117 = V_821 ;
goto V_111;
}
V_817 -= V_824 ;
V_38 += V_824 ;
V_406 += V_824 ;
}
V_111:
return V_117 ;
}
static int F_340 ( struct V_1 * V_2 , unsigned long V_815 ,
T_6 * V_426 , struct V_75 * V_68 ,
bool V_825 )
{
T_1 V_93 = ( ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_109 : 0 )
| ( V_825 ? V_110 : 0 ) ;
if ( F_341 ( V_2 , V_815 )
&& ! F_342 ( V_2 , V_2 -> V_5 . V_101 ,
V_2 -> V_5 . V_93 , V_93 ) ) {
* V_426 = V_2 -> V_5 . V_826 << V_104 |
( V_815 & ( V_105 - 1 ) ) ;
F_343 ( V_815 , * V_426 , V_825 , false ) ;
return 1 ;
}
* V_426 = V_2 -> V_5 . V_101 -> V_814 ( V_2 , V_815 , V_93 , V_68 ) ;
if ( * V_426 == V_97 )
return - 1 ;
if ( ( * V_426 & V_393 ) == V_827 )
return 1 ;
if ( F_344 ( V_2 , * V_426 ) ) {
F_343 ( V_815 , * V_426 , V_825 , true ) ;
return 1 ;
}
return 0 ;
}
int F_345 ( struct V_1 * V_2 , T_6 V_426 ,
const void * V_184 , int V_817 )
{
int V_106 ;
V_106 = F_117 ( V_2 -> V_99 , V_426 , V_184 , V_817 ) ;
if ( V_106 < 0 )
return 0 ;
F_346 ( V_2 , V_426 , V_184 , V_817 ) ;
return 1 ;
}
static int F_347 ( struct V_1 * V_2 , void * V_184 , int V_817 )
{
if ( V_2 -> V_828 ) {
F_326 ( V_807 , V_817 ,
V_2 -> V_829 [ 0 ] . V_426 , * ( T_2 * ) V_184 ) ;
V_2 -> V_828 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_348 ( struct V_1 * V_2 , T_6 V_426 ,
void * V_184 , int V_817 )
{
return ! F_116 ( V_2 -> V_99 , V_426 , V_184 , V_817 ) ;
}
static int F_349 ( struct V_1 * V_2 , T_6 V_426 ,
void * V_184 , int V_817 )
{
return F_345 ( V_2 , V_426 , V_184 , V_817 ) ;
}
static int F_350 ( struct V_1 * V_2 , T_6 V_426 , int V_817 , void * V_184 )
{
F_326 ( V_830 , V_817 , V_426 , * ( T_2 * ) V_184 ) ;
return F_319 ( V_2 , V_426 , V_817 , V_184 ) ;
}
static int F_351 ( struct V_1 * V_2 , T_6 V_426 ,
void * V_184 , int V_817 )
{
F_326 ( V_831 , V_817 , V_426 , 0 ) ;
return V_821 ;
}
static int F_352 ( struct V_1 * V_2 , T_6 V_426 ,
void * V_184 , int V_817 )
{
struct V_832 * V_833 = & V_2 -> V_829 [ 0 ] ;
memcpy ( V_2 -> V_834 -> V_835 . V_38 , V_833 -> V_38 , F_320 ( 8u , V_833 -> V_92 ) ) ;
return V_818 ;
}
static int F_353 ( unsigned long V_406 , void * V_184 ,
unsigned int V_817 ,
struct V_75 * V_68 ,
struct V_1 * V_2 ,
const struct V_836 * V_837 )
{
T_6 V_426 ;
int V_804 , V_106 ;
bool V_825 = V_837 -> V_825 ;
struct V_832 * V_833 ;
V_106 = F_340 ( V_2 , V_406 , & V_426 , V_68 , V_825 ) ;
if ( V_106 < 0 )
return V_820 ;
if ( V_106 )
goto V_835;
if ( V_837 -> V_838 ( V_2 , V_426 , V_184 , V_817 ) )
return V_818 ;
V_835:
V_804 = V_837 -> V_839 ( V_2 , V_426 , V_817 , V_184 ) ;
if ( V_804 == V_817 )
return V_818 ;
V_426 += V_804 ;
V_817 -= V_804 ;
V_184 += V_804 ;
F_29 ( V_2 -> V_840 >= V_841 ) ;
V_833 = & V_2 -> V_829 [ V_2 -> V_840 ++ ] ;
V_833 -> V_426 = V_426 ;
V_833 -> V_38 = V_184 ;
V_833 -> V_92 = V_817 ;
return V_818 ;
}
int F_354 ( struct V_822 * V_823 , unsigned long V_406 ,
void * V_184 , unsigned int V_817 ,
struct V_75 * V_68 ,
const struct V_836 * V_837 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
T_6 V_426 ;
int V_842 ;
if ( V_837 -> V_843 &&
V_837 -> V_843 ( V_2 , V_184 , V_817 ) )
return V_818 ;
V_2 -> V_840 = 0 ;
if ( ( ( V_406 + V_817 - 1 ) ^ V_406 ) & V_393 ) {
int V_844 ;
V_844 = - V_406 & ~ V_393 ;
V_842 = F_353 ( V_406 , V_184 , V_844 , V_68 ,
V_2 , V_837 ) ;
if ( V_842 != V_818 )
return V_842 ;
V_406 += V_844 ;
V_184 += V_844 ;
V_817 -= V_844 ;
}
V_842 = F_353 ( V_406 , V_184 , V_817 , V_68 ,
V_2 , V_837 ) ;
if ( V_842 != V_818 )
return V_842 ;
if ( ! V_2 -> V_840 )
return V_842 ;
V_426 = V_2 -> V_829 [ 0 ] . V_426 ;
V_2 -> V_845 = 1 ;
V_2 -> V_846 = 0 ;
V_2 -> V_834 -> V_835 . V_92 = F_320 ( 8u , V_2 -> V_829 [ 0 ] . V_92 ) ;
V_2 -> V_834 -> V_835 . V_847 = V_2 -> V_848 = V_837 -> V_825 ;
V_2 -> V_834 -> V_849 = V_850 ;
V_2 -> V_834 -> V_835 . V_851 = V_426 ;
return V_837 -> V_852 ( V_2 , V_426 , V_184 , V_817 ) ;
}
static int F_355 ( struct V_822 * V_823 ,
unsigned long V_406 ,
void * V_184 ,
unsigned int V_817 ,
struct V_75 * V_68 )
{
return F_354 ( V_823 , V_406 , V_184 , V_817 ,
V_68 , & V_853 ) ;
}
int F_356 ( struct V_822 * V_823 ,
unsigned long V_406 ,
const void * V_184 ,
unsigned int V_817 ,
struct V_75 * V_68 )
{
return F_354 ( V_823 , V_406 , ( void * ) V_184 , V_817 ,
V_68 , & V_854 ) ;
}
static int F_357 ( struct V_822 * V_823 ,
unsigned long V_406 ,
const void * V_855 ,
const void * V_856 ,
unsigned int V_817 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
T_6 V_426 ;
struct V_395 * V_395 ;
char * V_857 ;
bool V_858 ;
if ( V_817 > 8 || ( V_817 & ( V_817 - 1 ) ) )
goto V_859;
V_426 = F_332 ( V_2 , V_406 , NULL ) ;
if ( V_426 == V_97 ||
( V_426 & V_393 ) == V_827 )
goto V_859;
if ( ( ( V_426 + V_817 - 1 ) & V_393 ) != ( V_426 & V_393 ) )
goto V_859;
V_395 = F_358 ( V_2 -> V_99 , V_426 >> V_104 ) ;
if ( F_359 ( V_395 ) )
goto V_859;
V_857 = F_360 ( V_395 ) ;
V_857 += F_361 ( V_426 ) ;
switch ( V_817 ) {
case 1 :
V_858 = F_362 ( T_14 , V_857 , V_855 , V_856 ) ;
break;
case 2 :
V_858 = F_362 ( V_860 , V_857 , V_855 , V_856 ) ;
break;
case 4 :
V_858 = F_362 ( T_1 , V_857 , V_855 , V_856 ) ;
break;
case 8 :
V_858 = F_363 ( V_857 , V_855 , V_856 ) ;
break;
default:
F_26 () ;
}
F_364 ( V_857 ) ;
F_365 ( V_395 ) ;
if ( ! V_858 )
return V_861 ;
F_192 ( V_2 -> V_99 , V_426 >> V_104 ) ;
F_346 ( V_2 , V_426 , V_856 , V_817 ) ;
return V_818 ;
V_859:
F_366 ( V_862 L_22 ) ;
return F_356 ( V_823 , V_406 , V_856 , V_817 , V_68 ) ;
}
static int F_367 ( struct V_1 * V_2 , void * V_863 )
{
int V_117 ;
if ( V_2 -> V_5 . V_864 . V_865 )
V_117 = F_325 ( V_2 -> V_99 , V_773 , V_2 -> V_5 . V_864 . V_866 ,
V_2 -> V_5 . V_864 . V_523 , V_863 ) ;
else
V_117 = F_322 ( V_2 -> V_99 , V_773 ,
V_2 -> V_5 . V_864 . V_866 , V_2 -> V_5 . V_864 . V_523 ,
V_863 ) ;
return V_117 ;
}
static int F_368 ( struct V_1 * V_2 , int V_523 ,
unsigned short V_866 , void * V_184 ,
unsigned int V_736 , bool V_865 )
{
V_2 -> V_5 . V_864 . V_866 = V_866 ;
V_2 -> V_5 . V_864 . V_865 = V_865 ;
V_2 -> V_5 . V_864 . V_736 = V_736 ;
V_2 -> V_5 . V_864 . V_523 = V_523 ;
if ( ! F_367 ( V_2 , V_2 -> V_5 . V_867 ) ) {
V_2 -> V_5 . V_864 . V_736 = 0 ;
return 1 ;
}
V_2 -> V_834 -> V_849 = V_868 ;
V_2 -> V_834 -> V_869 . V_870 = V_865 ? V_871 : V_872 ;
V_2 -> V_834 -> V_869 . V_523 = V_523 ;
V_2 -> V_834 -> V_869 . V_873 = V_874 * V_105 ;
V_2 -> V_834 -> V_869 . V_736 = V_736 ;
V_2 -> V_834 -> V_869 . V_866 = V_866 ;
return 0 ;
}
static int F_369 ( struct V_822 * V_823 ,
int V_523 , unsigned short V_866 , void * V_184 ,
unsigned int V_736 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
int V_106 ;
if ( V_2 -> V_5 . V_864 . V_736 )
goto V_875;
V_106 = F_368 ( V_2 , V_523 , V_866 , V_184 , V_736 , true ) ;
if ( V_106 ) {
V_875:
memcpy ( V_184 , V_2 -> V_5 . V_867 , V_523 * V_736 ) ;
F_370 ( V_876 , V_866 , V_523 , V_736 , V_2 -> V_5 . V_867 ) ;
V_2 -> V_5 . V_864 . V_736 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_371 ( struct V_822 * V_823 ,
int V_523 , unsigned short V_866 ,
const void * V_184 , unsigned int V_736 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
memcpy ( V_2 -> V_5 . V_867 , V_184 , V_523 * V_736 ) ;
F_370 ( V_877 , V_866 , V_523 , V_736 , V_2 -> V_5 . V_867 ) ;
return F_368 ( V_2 , V_523 , V_866 , ( void * ) V_184 , V_736 , false ) ;
}
static unsigned long F_372 ( struct V_1 * V_2 , int V_810 )
{
return V_73 -> F_372 ( V_2 , V_810 ) ;
}
static void F_373 ( struct V_822 * V_823 , V_167 V_80 )
{
F_374 ( F_336 ( V_823 ) , V_80 ) ;
}
int F_375 ( struct V_1 * V_2 )
{
if ( ! F_241 ( V_2 ) )
return V_818 ;
if ( V_73 -> V_607 () ) {
int V_23 = F_376 () ;
F_244 ( V_23 , V_2 -> V_5 . V_608 ) ;
F_377 ( V_2 -> V_5 . V_608 ,
F_239 , NULL , 1 ) ;
F_378 () ;
F_379 ( V_2 -> V_5 . V_608 ) ;
} else
F_240 () ;
return V_818 ;
}
static void F_380 ( struct V_822 * V_823 )
{
F_375 ( F_336 ( V_823 ) ) ;
}
int F_381 ( struct V_822 * V_823 , int V_183 , unsigned long * V_878 )
{
return F_95 ( F_336 ( V_823 ) , V_183 , V_878 ) ;
}
int F_382 ( struct V_822 * V_823 , int V_183 , unsigned long V_22 )
{
return F_93 ( F_336 ( V_823 ) , V_183 , V_22 ) ;
}
static T_2 F_383 ( T_2 V_879 , T_1 V_880 )
{
return ( V_879 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_880 ;
}
static unsigned long F_384 ( struct V_822 * V_823 , int V_881 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
unsigned long V_22 ;
switch ( V_881 ) {
case 0 :
V_22 = F_59 ( V_2 ) ;
break;
case 2 :
V_22 = V_2 -> V_5 . V_79 ;
break;
case 3 :
V_22 = F_57 ( V_2 ) ;
break;
case 4 :
V_22 = F_74 ( V_2 ) ;
break;
case 8 :
V_22 = F_87 ( V_2 ) ;
break;
default:
F_385 ( L_23 , V_256 , V_881 ) ;
return 0 ;
}
return V_22 ;
}
static int F_386 ( struct V_822 * V_823 , int V_881 , V_167 V_184 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
int V_191 = 0 ;
switch ( V_881 ) {
case 0 :
V_191 = F_58 ( V_2 , F_383 ( F_59 ( V_2 ) , V_184 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_79 = V_184 ;
break;
case 3 :
V_191 = F_81 ( V_2 , V_184 ) ;
break;
case 4 :
V_191 = F_73 ( V_2 , F_383 ( F_74 ( V_2 ) , V_184 ) ) ;
break;
case 8 :
V_191 = F_84 ( V_2 , V_184 ) ;
break;
default:
F_385 ( L_23 , V_256 , V_881 ) ;
V_191 = - 1 ;
}
return V_191 ;
}
static int F_387 ( struct V_822 * V_823 )
{
return V_73 -> V_88 ( F_336 ( V_823 ) ) ;
}
static void F_388 ( struct V_822 * V_823 , struct V_882 * V_883 )
{
V_73 -> V_884 ( F_336 ( V_823 ) , V_883 ) ;
}
static void F_389 ( struct V_822 * V_823 , struct V_882 * V_883 )
{
V_73 -> V_885 ( F_336 ( V_823 ) , V_883 ) ;
}
static void F_390 ( struct V_822 * V_823 , struct V_882 * V_883 )
{
V_73 -> V_886 ( F_336 ( V_823 ) , V_883 ) ;
}
static void F_391 ( struct V_822 * V_823 , struct V_882 * V_883 )
{
V_73 -> V_887 ( F_336 ( V_823 ) , V_883 ) ;
}
static unsigned long F_392 (
struct V_822 * V_823 , int V_810 )
{
return F_372 ( F_336 ( V_823 ) , V_810 ) ;
}
static bool F_393 ( struct V_822 * V_823 , V_860 * V_888 ,
struct V_889 * V_890 , T_1 * V_891 ,
int V_810 )
{
struct V_808 V_809 ;
F_328 ( F_336 ( V_823 ) , & V_809 , V_810 ) ;
* V_888 = V_809 . V_888 ;
if ( V_809 . V_892 ) {
memset ( V_890 , 0 , sizeof( * V_890 ) ) ;
return false ;
}
if ( V_809 . V_893 )
V_809 . V_894 >>= 12 ;
F_394 ( V_890 , V_809 . V_894 ) ;
F_395 ( V_890 , ( unsigned long ) V_809 . V_895 ) ;
#ifdef F_60
if ( V_891 )
* V_891 = V_809 . V_895 >> 32 ;
#endif
V_890 -> type = V_809 . type ;
V_890 -> V_615 = V_809 . V_615 ;
V_890 -> V_896 = V_809 . V_896 ;
V_890 -> V_364 = V_809 . V_897 ;
V_890 -> V_898 = V_809 . V_898 ;
V_890 -> V_899 = V_809 . V_899 ;
V_890 -> V_900 = V_809 . V_185 ;
V_890 -> V_893 = V_809 . V_893 ;
return true ;
}
static void F_396 ( struct V_822 * V_823 , V_860 V_888 ,
struct V_889 * V_890 , T_1 V_891 ,
int V_810 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
struct V_808 V_809 ;
V_809 . V_888 = V_888 ;
V_809 . V_895 = F_397 ( V_890 ) ;
#ifdef F_60
V_809 . V_895 |= ( ( T_2 ) V_891 ) << 32 ;
#endif
V_809 . V_894 = F_398 ( V_890 ) ;
if ( V_890 -> V_893 )
V_809 . V_894 = ( V_809 . V_894 << 12 ) | 0xfff ;
V_809 . type = V_890 -> type ;
V_809 . V_896 = V_890 -> V_896 ;
V_809 . V_185 = V_890 -> V_900 ;
V_809 . V_615 = V_890 -> V_615 ;
V_809 . V_899 = V_890 -> V_899 ;
V_809 . V_893 = V_890 -> V_893 ;
V_809 . V_898 = V_890 -> V_898 ;
V_809 . V_897 = V_890 -> V_364 ;
V_809 . V_892 = ! V_809 . V_897 ;
V_809 . V_901 = 0 ;
F_327 ( V_2 , & V_809 , V_810 ) ;
return;
}
static int F_399 ( struct V_822 * V_823 ,
T_1 V_496 , T_2 * V_497 )
{
return F_215 ( F_336 ( V_823 ) , V_496 , V_497 ) ;
}
static int F_400 ( struct V_822 * V_823 ,
T_1 V_496 , T_2 V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = V_38 ;
V_21 . V_141 = V_496 ;
V_21 . V_40 = false ;
return F_106 ( F_336 ( V_823 ) , & V_21 ) ;
}
static int F_401 ( struct V_822 * V_823 ,
T_1 V_902 )
{
return F_402 ( F_336 ( V_823 ) , V_902 ) ;
}
static int F_403 ( struct V_822 * V_823 ,
T_1 V_902 , T_2 * V_497 )
{
return F_99 ( F_336 ( V_823 ) , V_902 , V_497 ) ;
}
static void F_404 ( struct V_822 * V_823 )
{
F_336 ( V_823 ) -> V_5 . V_903 = 1 ;
}
static void F_405 ( struct V_822 * V_823 )
{
F_208 () ;
F_406 ( F_336 ( V_823 ) ) ;
F_407 () ;
}
static void F_408 ( struct V_822 * V_823 )
{
F_209 () ;
}
static int F_409 ( struct V_822 * V_823 ,
struct V_904 * V_905 ,
enum V_906 V_907 )
{
return V_73 -> V_908 ( F_336 ( V_823 ) , V_905 , V_907 ) ;
}
static void F_410 ( struct V_822 * V_823 ,
T_1 * V_909 , T_1 * V_910 , T_1 * V_194 , T_1 * V_202 )
{
V_685 ( F_336 ( V_823 ) , V_909 , V_910 , V_194 , V_202 ) ;
}
static V_167 F_411 ( struct V_822 * V_823 , unsigned V_911 )
{
return F_98 ( F_336 ( V_823 ) , V_911 ) ;
}
static void F_412 ( struct V_822 * V_823 , unsigned V_911 , V_167 V_184 )
{
F_100 ( F_336 ( V_823 ) , V_911 , V_184 ) ;
}
static void F_413 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_912 = V_73 -> V_643 ( V_2 ) ;
if ( V_912 & V_28 )
V_28 = 0 ;
if ( F_150 ( V_912 || V_28 ) ) {
V_73 -> V_654 ( V_2 , V_28 ) ;
if ( ! V_28 )
F_31 ( V_67 , V_2 ) ;
}
}
static bool F_414 ( struct V_1 * V_2 )
{
struct V_822 * V_823 = & V_2 -> V_5 . V_913 ;
if ( V_823 -> V_68 . V_41 == V_42 )
return F_38 ( V_2 , & V_823 -> V_68 ) ;
if ( V_823 -> V_68 . V_914 )
F_37 ( V_2 , V_823 -> V_68 . V_41 ,
V_823 -> V_68 . V_62 ) ;
else
F_32 ( V_2 , V_823 -> V_68 . V_41 ) ;
return false ;
}
static void F_415 ( struct V_1 * V_2 )
{
struct V_822 * V_823 = & V_2 -> V_5 . V_913 ;
int V_130 , V_131 ;
V_73 -> V_132 ( V_2 , & V_130 , & V_131 ) ;
V_823 -> V_915 = F_416 ( V_2 ) ;
V_823 -> V_916 = F_417 ( V_2 ) ;
V_823 -> V_314 = ( ! F_418 ( V_2 ) ) ? V_917 :
( V_823 -> V_915 & V_918 ) ? V_919 :
( V_131 && F_54 ( V_2 ) ) ? V_920 :
V_130 ? V_921 :
V_922 ;
V_823 -> V_923 = F_419 ( V_2 ) ;
F_420 ( V_823 ) ;
V_2 -> V_5 . V_924 = false ;
}
int F_421 ( struct V_1 * V_2 , int V_620 , int V_925 )
{
struct V_822 * V_823 = & V_2 -> V_5 . V_913 ;
int V_106 ;
F_415 ( V_2 ) ;
V_823 -> V_926 = 2 ;
V_823 -> V_927 = 2 ;
V_823 -> V_928 = V_823 -> V_916 + V_925 ;
V_106 = F_422 ( V_823 , V_620 ) ;
if ( V_106 != V_818 )
return V_929 ;
V_823 -> V_916 = V_823 -> V_928 ;
F_423 ( V_2 , V_823 -> V_916 ) ;
F_424 ( V_2 , V_823 -> V_915 ) ;
if ( V_620 == V_51 )
V_2 -> V_5 . V_646 = 0 ;
else
V_2 -> V_5 . V_640 . V_69 = false ;
return V_930 ;
}
static int F_425 ( struct V_1 * V_2 )
{
int V_117 = V_930 ;
++ V_2 -> V_77 . V_931 ;
F_426 ( V_2 ) ;
if ( ! F_419 ( V_2 ) && V_73 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_834 -> V_849 = V_932 ;
V_2 -> V_834 -> V_933 . V_934 = V_935 ;
V_2 -> V_834 -> V_933 . V_936 = 0 ;
V_117 = V_929 ;
}
F_32 ( V_2 , V_192 ) ;
return V_117 ;
}
static bool F_427 ( struct V_1 * V_2 , T_16 V_79 ,
bool V_937 ,
int V_938 )
{
T_6 V_426 = V_79 ;
T_17 V_939 ;
if ( V_938 & V_940 )
return false ;
if ( ! V_2 -> V_5 . V_84 . V_941 ) {
V_426 = F_332 ( V_2 , V_79 , NULL ) ;
if ( V_426 == V_97 )
return true ;
}
V_939 = F_428 ( V_2 -> V_99 , F_46 ( V_426 ) ) ;
if ( F_429 ( V_939 ) )
return false ;
F_430 ( V_939 ) ;
if ( V_2 -> V_5 . V_84 . V_941 ) {
unsigned int V_942 ;
F_141 ( & V_2 -> V_99 -> V_753 ) ;
V_942 = V_2 -> V_99 -> V_5 . V_942 ;
F_142 ( & V_2 -> V_99 -> V_753 ) ;
if ( V_942 )
F_431 ( V_2 -> V_99 , F_46 ( V_426 ) ) ;
return true ;
}
F_431 ( V_2 -> V_99 , F_46 ( V_426 ) ) ;
return ! V_937 ;
}
static bool F_432 ( struct V_822 * V_823 ,
unsigned long V_79 , int V_938 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
unsigned long V_943 , V_944 , V_426 = V_79 ;
V_943 = V_2 -> V_5 . V_943 ;
V_944 = V_2 -> V_5 . V_944 ;
V_2 -> V_5 . V_943 = V_2 -> V_5 . V_944 = 0 ;
if ( ! ( V_938 & V_945 ) )
return false ;
if ( F_433 ( V_823 ) )
return false ;
if ( V_823 -> V_916 == V_943 && V_944 == V_79 )
return false ;
V_2 -> V_5 . V_943 = V_823 -> V_916 ;
V_2 -> V_5 . V_944 = V_79 ;
if ( ! V_2 -> V_5 . V_84 . V_941 )
V_426 = F_332 ( V_2 , V_79 , NULL ) ;
F_431 ( V_2 -> V_99 , F_46 ( V_426 ) ) ;
return true ;
}
static int F_434 ( unsigned long V_406 , T_1 type , T_1 V_174 ,
unsigned long * V_185 )
{
T_1 V_173 = 0 ;
int V_3 ;
T_1 V_946 , V_947 ;
V_946 = V_174 ;
V_947 = V_174 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_946 >>= 2 , V_947 >>= 4 )
if ( ( V_946 & 3 ) && ( V_947 & 15 ) == type && V_185 [ V_3 ] == V_406 )
V_173 |= ( 1 << V_3 ) ;
return V_173 ;
}
static void F_435 ( struct V_1 * V_2 , unsigned long V_948 , int * V_117 )
{
struct V_949 * V_949 = V_2 -> V_834 ;
if ( F_150 ( V_948 & V_950 ) ) {
if ( V_2 -> V_170 & V_951 ) {
V_949 -> V_952 . V_5 . V_173 = V_953 | V_181 |
V_182 ;
V_949 -> V_952 . V_5 . V_954 = V_2 -> V_5 . V_955 ;
V_949 -> V_952 . V_5 . V_68 = V_53 ;
V_949 -> V_849 = V_956 ;
* V_117 = V_957 ;
} else {
V_2 -> V_5 . V_913 . V_915 &= ~ V_950 ;
V_2 -> V_5 . V_173 &= ~ 15 ;
V_2 -> V_5 . V_173 |= V_953 | V_182 ;
F_32 ( V_2 , V_53 ) ;
}
}
}
static bool F_436 ( struct V_1 * V_2 , int * V_117 )
{
struct V_949 * V_949 = V_2 -> V_834 ;
unsigned long V_916 = V_2 -> V_5 . V_913 . V_916 ;
T_1 V_173 = 0 ;
if ( F_150 ( V_2 -> V_170 & V_171 ) &&
( V_2 -> V_5 . V_175 & V_179 ) ) {
V_173 = F_434 ( V_916 , 0 ,
V_2 -> V_5 . V_175 ,
V_2 -> V_5 . V_186 ) ;
if ( V_173 != 0 ) {
V_949 -> V_952 . V_5 . V_173 = V_173 | V_181 | V_182 ;
V_949 -> V_952 . V_5 . V_954 = F_417 ( V_2 ) +
F_372 ( V_2 , V_958 ) ;
V_949 -> V_952 . V_5 . V_68 = V_53 ;
V_949 -> V_849 = V_956 ;
* V_117 = V_957 ;
return true ;
}
}
if ( F_150 ( V_2 -> V_5 . V_174 & V_179 ) &&
! ( F_416 ( V_2 ) & V_959 ) ) {
V_173 = F_434 ( V_916 , 0 ,
V_2 -> V_5 . V_174 ,
V_2 -> V_5 . V_185 ) ;
if ( V_173 != 0 ) {
V_2 -> V_5 . V_173 &= ~ 15 ;
V_2 -> V_5 . V_173 |= V_173 | V_182 ;
F_32 ( V_2 , V_53 ) ;
* V_117 = V_930 ;
return true ;
}
}
return false ;
}
int F_437 ( struct V_1 * V_2 ,
unsigned long V_79 ,
int V_938 ,
void * V_960 ,
int V_961 )
{
int V_117 ;
struct V_822 * V_823 = & V_2 -> V_5 . V_913 ;
bool V_521 = true ;
bool V_962 = V_2 -> V_5 . V_937 ;
V_2 -> V_5 . V_937 = false ;
F_438 ( V_2 ) ;
if ( ! ( V_938 & V_963 ) ) {
F_415 ( V_2 ) ;
if ( F_436 ( V_2 , & V_117 ) )
return V_117 ;
V_823 -> V_964 = 0 ;
V_823 -> V_965 = false ;
V_823 -> V_68 . V_41 = - 1 ;
V_823 -> V_966 = false ;
V_823 -> V_967 = V_938 & V_968 ;
V_117 = F_439 ( V_823 , V_960 , V_961 ) ;
F_440 ( V_2 ) ;
++ V_2 -> V_77 . V_969 ;
if ( V_117 != V_970 ) {
if ( V_938 & V_968 )
return V_929 ;
if ( F_427 ( V_2 , V_79 , V_962 ,
V_938 ) )
return V_930 ;
if ( V_938 & V_971 )
return V_929 ;
return F_425 ( V_2 ) ;
}
}
if ( V_938 & V_971 ) {
F_423 ( V_2 , V_823 -> V_928 ) ;
if ( V_823 -> V_915 & V_959 )
F_424 ( V_2 , V_823 -> V_915 & ~ V_959 ) ;
return V_930 ;
}
if ( F_432 ( V_823 , V_79 , V_938 ) )
return V_930 ;
if ( V_2 -> V_5 . V_924 ) {
V_2 -> V_5 . V_924 = false ;
F_441 ( V_823 ) ;
}
V_972:
V_117 = F_442 ( V_823 ) ;
if ( V_117 == V_973 )
return V_930 ;
if ( V_117 == V_974 ) {
if ( F_427 ( V_2 , V_79 , V_962 ,
V_938 ) )
return V_930 ;
return F_425 ( V_2 ) ;
}
if ( V_823 -> V_965 ) {
V_117 = V_930 ;
if ( F_414 ( V_2 ) )
return V_117 ;
} else if ( V_2 -> V_5 . V_864 . V_736 ) {
if ( ! V_2 -> V_5 . V_864 . V_865 ) {
V_2 -> V_5 . V_864 . V_736 = 0 ;
} else {
V_521 = false ;
V_2 -> V_5 . V_975 = V_976 ;
}
V_117 = V_957 ;
} else if ( V_2 -> V_845 ) {
if ( ! V_2 -> V_848 )
V_521 = false ;
V_117 = V_957 ;
V_2 -> V_5 . V_975 = V_977 ;
} else if ( V_117 == V_978 )
goto V_972;
else
V_117 = V_930 ;
if ( V_521 ) {
unsigned long V_948 = V_73 -> V_979 ( V_2 ) ;
F_413 ( V_2 , V_823 -> V_964 ) ;
V_2 -> V_5 . V_980 = false ;
F_423 ( V_2 , V_823 -> V_916 ) ;
if ( V_117 == V_930 )
F_435 ( V_2 , V_948 , & V_117 ) ;
F_443 ( V_2 , V_823 -> V_915 ) ;
if ( F_150 ( ( V_823 -> V_915 & ~ V_948 ) & V_981 ) )
F_31 ( V_67 , V_2 ) ;
} else
V_2 -> V_5 . V_980 = true ;
return V_117 ;
}
int F_444 ( struct V_1 * V_2 , int V_523 , unsigned short V_866 )
{
unsigned long V_184 = F_98 ( V_2 , V_196 ) ;
int V_106 = F_371 ( & V_2 -> V_5 . V_913 ,
V_523 , V_866 , & V_184 , 1 ) ;
V_2 -> V_5 . V_864 . V_736 = 0 ;
return V_106 ;
}
static void F_445 ( void * V_905 )
{
F_446 ( V_329 , 0 ) ;
}
static void F_447 ( void * V_38 )
{
struct V_982 * V_983 = V_38 ;
unsigned long V_259 = 0 ;
if ( V_38 )
V_259 = V_983 -> V_856 ;
else if ( ! F_236 ( V_984 ) )
V_259 = F_448 ( F_449 () ) ;
if ( ! V_259 )
V_259 = V_268 ;
F_446 ( V_329 , V_259 ) ;
}
static int F_450 ( struct V_985 * V_986 , unsigned long V_184 ,
void * V_38 )
{
struct V_982 * V_983 = V_38 ;
struct V_99 * V_99 ;
struct V_1 * V_2 ;
int V_3 , V_987 = 0 ;
if ( V_184 == V_988 && V_983 -> V_855 > V_983 -> V_856 )
return 0 ;
if ( V_184 == V_989 && V_983 -> V_855 < V_983 -> V_856 )
return 0 ;
F_245 ( V_983 -> V_23 , F_447 , V_983 , 1 ) ;
F_141 ( & V_990 ) ;
F_451 (kvm, &vm_list, vm_list) {
F_158 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_983 -> V_23 )
continue;
F_31 ( V_320 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_987 = 1 ;
}
}
F_142 ( & V_990 ) ;
if ( V_983 -> V_855 < V_983 -> V_856 && V_987 ) {
F_245 ( V_983 -> V_23 , F_447 , V_983 , 1 ) ;
}
return 0 ;
}
static int F_452 ( struct V_985 * V_991 ,
unsigned long V_992 , void * V_993 )
{
unsigned int V_23 = ( unsigned long ) V_993 ;
switch ( V_992 ) {
case V_994 :
case V_995 :
F_245 ( V_23 , F_447 , NULL , 1 ) ;
break;
case V_996 :
F_245 ( V_23 , F_445 , NULL , 1 ) ;
break;
}
return V_997 ;
}
static void F_453 ( void )
{
int V_23 ;
V_998 = V_268 ;
F_454 () ;
if ( ! F_236 ( V_984 ) ) {
#ifdef F_455
struct V_999 V_1000 ;
memset ( & V_1000 , 0 , sizeof( V_1000 ) ) ;
V_23 = F_376 () ;
F_456 ( & V_1000 , V_23 ) ;
if ( V_1000 . V_1001 . V_1002 )
V_998 = V_1000 . V_1001 . V_1002 ;
F_378 () ;
#endif
F_457 ( & V_1003 ,
V_1004 ) ;
}
F_123 ( L_24 , V_998 ) ;
F_458 (cpu)
F_245 ( V_23 , F_447 , NULL , 1 ) ;
F_459 ( & V_1005 ) ;
F_460 () ;
}
int F_461 ( void )
{
return F_162 ( V_1006 ) != NULL ;
}
static int F_462 ( void )
{
int V_1007 = 3 ;
if ( F_162 ( V_1006 ) )
V_1007 = V_73 -> V_88 ( F_162 ( V_1006 ) ) ;
return V_1007 != 0 ;
}
static unsigned long F_463 ( void )
{
unsigned long V_1008 = 0 ;
if ( F_162 ( V_1006 ) )
V_1008 = F_417 ( F_162 ( V_1006 ) ) ;
return V_1008 ;
}
void F_464 ( struct V_1 * V_2 )
{
F_446 ( V_1006 , V_2 ) ;
}
void F_465 ( struct V_1 * V_2 )
{
F_446 ( V_1006 , NULL ) ;
}
static void F_466 ( void )
{
T_2 V_28 ;
int V_1009 = V_1010 . V_1011 ;
V_28 = F_467 ( V_1009 , 51 ) ;
V_28 |= 0x3ull << 62 ;
V_28 |= 1ull ;
#ifdef F_60
if ( V_1009 == 52 )
V_28 &= ~ 1ull ;
#endif
F_468 ( V_28 ) ;
}
static void F_469 ( struct V_342 * V_343 )
{
struct V_99 * V_99 ;
struct V_1 * V_2 ;
int V_3 ;
F_141 ( & V_990 ) ;
F_451 (kvm, &vm_list, vm_list)
F_158 (i, vcpu, kvm)
F_31 ( V_284 , V_2 ) ;
F_154 ( & V_319 , 0 ) ;
F_142 ( & V_990 ) ;
}
static int F_470 ( struct V_985 * V_986 , unsigned long V_1012 ,
void * V_1013 )
{
struct V_219 * V_279 = & V_219 ;
struct V_217 * V_218 = V_1013 ;
F_110 ( V_218 ) ;
if ( V_279 -> clock . V_226 != V_282 &&
F_133 ( & V_319 ) != 0 )
F_471 ( V_1014 , & V_1015 ) ;
return 0 ;
}
int F_472 ( void * V_1016 )
{
int V_117 ;
struct V_73 * V_837 = V_1016 ;
if ( V_73 ) {
F_10 ( V_26 L_25 ) ;
V_117 = - V_771 ;
goto V_111;
}
if ( ! V_837 -> V_1017 () ) {
F_10 ( V_26 L_26 ) ;
V_117 = - V_1018 ;
goto V_111;
}
if ( V_837 -> V_1019 () ) {
F_10 ( V_26 L_27 ) ;
V_117 = - V_1018 ;
goto V_111;
}
V_117 = - V_397 ;
V_25 = F_473 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_111;
}
V_117 = F_474 () ;
if ( V_117 )
goto V_1020;
F_466 () ;
V_73 = V_837 ;
F_317 () ;
F_475 ( V_1021 , V_1022 ,
V_1023 , V_1024 , 0 ) ;
F_453 () ;
F_476 ( & V_1025 ) ;
if ( V_579 )
V_140 = F_477 ( V_138 ) ;
F_478 () ;
#ifdef F_60
F_479 ( & V_1026 ) ;
#endif
return 0 ;
V_1020:
F_480 ( V_25 ) ;
V_111:
return V_117 ;
}
void F_481 ( void )
{
F_482 ( & V_1025 ) ;
if ( ! F_236 ( V_984 ) )
F_483 ( & V_1003 ,
V_1004 ) ;
F_484 ( & V_1005 ) ;
#ifdef F_60
F_485 ( & V_1026 ) ;
#endif
V_73 = NULL ;
F_486 () ;
F_480 ( V_25 ) ;
}
int F_487 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1027 ;
if ( F_85 ( V_2 -> V_99 ) ) {
V_2 -> V_5 . V_1028 = V_1029 ;
return 1 ;
} else {
V_2 -> V_834 -> V_849 = V_1030 ;
return 0 ;
}
}
int F_488 ( struct V_1 * V_2 )
{
T_2 V_1031 , V_1032 , V_1033 , V_106 ;
T_18 V_1034 , V_1035 , V_1036 , V_191 = V_1037 , V_1038 = 0 ;
bool V_1039 , V_1040 ;
if ( V_73 -> V_88 ( V_2 ) != 0 || ! F_418 ( V_2 ) ) {
F_32 ( V_2 , V_192 ) ;
return 0 ;
}
V_1040 = F_489 ( V_2 ) ;
if ( ! V_1040 ) {
V_1031 = ( ( T_2 ) F_98 ( V_2 , V_197 ) << 32 ) |
( F_98 ( V_2 , V_196 ) & 0xffffffff ) ;
V_1032 = ( ( T_2 ) F_98 ( V_2 , V_1041 ) << 32 ) |
( F_98 ( V_2 , V_195 ) & 0xffffffff ) ;
V_1033 = ( ( T_2 ) F_98 ( V_2 , V_1042 ) << 32 ) |
( F_98 ( V_2 , V_1043 ) & 0xffffffff ) ;
}
#ifdef F_60
else {
V_1031 = F_98 ( V_2 , V_195 ) ;
V_1032 = F_98 ( V_2 , V_197 ) ;
V_1033 = F_98 ( V_2 , V_1044 ) ;
}
#endif
V_1034 = V_1031 & 0xffff ;
V_1039 = ( V_1031 >> 16 ) & 0x1 ;
V_1036 = ( V_1031 >> 32 ) & 0xfff ;
V_1035 = ( V_1031 >> 48 ) & 0xfff ;
F_490 ( V_1034 , V_1039 , V_1036 , V_1035 , V_1032 , V_1033 ) ;
switch ( V_1034 ) {
case V_1045 :
F_491 ( V_2 ) ;
break;
default:
V_191 = V_1046 ;
break;
}
V_106 = V_191 | ( ( ( T_2 ) V_1038 & 0xfff ) << 32 ) ;
if ( V_1040 ) {
F_100 ( V_2 , V_196 , V_106 ) ;
} else {
F_100 ( V_2 , V_197 , V_106 >> 32 ) ;
F_100 ( V_2 , V_196 , V_106 & 0xffffffff ) ;
}
return 1 ;
}
static void F_492 ( struct V_99 * V_99 , unsigned long V_291 , int V_1047 )
{
struct V_1048 V_1049 ;
V_1049 . V_1050 = 0 ;
V_1049 . V_1051 = 0 ;
V_1049 . V_1052 = V_1047 ;
V_1049 . V_1053 = V_1054 ;
F_493 ( V_99 , 0 , & V_1049 , NULL ) ;
}
int F_494 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1055 , V_1056 , V_1057 , V_1058 , V_106 ;
int V_1059 , V_117 = 1 ;
if ( F_186 ( V_2 -> V_99 ) )
return F_488 ( V_2 ) ;
V_16 = F_98 ( V_2 , V_196 ) ;
V_1055 = F_98 ( V_2 , V_1041 ) ;
V_1056 = F_98 ( V_2 , V_195 ) ;
V_1057 = F_98 ( V_2 , V_197 ) ;
V_1058 = F_98 ( V_2 , V_1043 ) ;
F_495 ( V_16 , V_1055 , V_1056 , V_1057 , V_1058 ) ;
V_1059 = F_489 ( V_2 ) ;
if ( ! V_1059 ) {
V_16 &= 0xFFFFFFFF ;
V_1055 &= 0xFFFFFFFF ;
V_1056 &= 0xFFFFFFFF ;
V_1057 &= 0xFFFFFFFF ;
V_1058 &= 0xFFFFFFFF ;
}
if ( V_73 -> V_88 ( V_2 ) != 0 ) {
V_106 = - V_1060 ;
goto V_111;
}
switch ( V_16 ) {
case V_1061 :
V_106 = 0 ;
break;
case V_1062 :
F_492 ( V_2 -> V_99 , V_1055 , V_1056 ) ;
V_106 = 0 ;
break;
default:
V_106 = - V_1063 ;
break;
}
V_111:
if ( ! V_1059 )
V_106 = ( T_1 ) V_106 ;
F_100 ( V_2 , V_196 , V_106 ) ;
++ V_2 -> V_77 . V_1064 ;
return V_117 ;
}
static int F_496 ( struct V_822 * V_823 )
{
struct V_1 * V_2 = F_336 ( V_823 ) ;
char V_1065 [ 3 ] ;
unsigned long V_1066 = F_417 ( V_2 ) ;
V_73 -> V_409 ( V_2 , V_1065 ) ;
return F_356 ( V_823 , V_1066 , V_1065 , 3 , NULL ) ;
}
static int F_497 ( struct V_1 * V_2 )
{
return ( ! F_85 ( V_2 -> V_99 ) && ! F_498 ( V_2 ) &&
V_2 -> V_834 -> V_1067 &&
F_499 ( V_2 ) ) ;
}
static void F_500 ( struct V_1 * V_2 )
{
struct V_949 * V_949 = V_2 -> V_834 ;
V_949 -> V_1068 = ( F_416 ( V_2 ) & V_981 ) != 0 ;
V_949 -> V_168 = F_87 ( V_2 ) ;
V_949 -> V_31 = F_20 ( V_2 ) ;
if ( F_85 ( V_2 -> V_99 ) )
V_949 -> V_1069 = 1 ;
else
V_949 -> V_1069 =
F_499 ( V_2 ) &&
! F_498 ( V_2 ) &&
! F_501 ( V_2 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
int V_1070 , V_1071 ;
if ( ! V_73 -> F_254 )
return;
if ( ! V_2 -> V_5 . V_618 )
return;
if ( ! V_2 -> V_5 . V_618 -> V_694 )
V_1070 = F_502 ( V_2 ) ;
else
V_1070 = - 1 ;
if ( V_1070 != - 1 )
V_1070 >>= 4 ;
V_1071 = F_88 ( V_2 ) ;
V_73 -> F_254 ( V_2 , V_1071 , V_1070 ) ;
}
static int F_503 ( struct V_1 * V_2 , bool V_1072 )
{
int V_117 ;
if ( V_2 -> V_5 . V_68 . V_69 ) {
F_504 ( V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ) ;
if ( F_28 ( V_2 -> V_5 . V_68 . V_16 ) == V_60 )
F_443 ( V_2 , F_416 ( V_2 ) |
V_959 ) ;
V_73 -> V_1073 ( V_2 , V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ,
V_2 -> V_5 . V_68 . V_63 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_645 ) {
V_73 -> V_1074 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_640 . V_69 ) {
V_73 -> V_1075 ( V_2 ) ;
return 0 ;
}
if ( F_419 ( V_2 ) && V_73 -> V_1076 ) {
V_117 = V_73 -> V_1076 ( V_2 , V_1072 ) ;
if ( V_117 != 0 )
return V_117 ;
}
if ( V_2 -> V_5 . V_646 ) {
if ( V_73 -> V_1077 ( V_2 ) ) {
-- V_2 -> V_5 . V_646 ;
V_2 -> V_5 . V_645 = true ;
V_73 -> V_1074 ( V_2 ) ;
}
} else if ( F_505 ( V_2 ) ) {
if ( F_419 ( V_2 ) && V_73 -> V_1076 ) {
V_117 = V_73 -> V_1076 ( V_2 , V_1072 ) ;
if ( V_117 != 0 )
return V_117 ;
}
if ( V_73 -> V_1078 ( V_2 ) ) {
F_256 ( V_2 , F_506 ( V_2 ) ,
false ) ;
V_73 -> V_1075 ( V_2 ) ;
}
}
return 0 ;
}
static void F_262 ( struct V_1 * V_2 )
{
unsigned V_894 = 2 ;
if ( V_73 -> V_648 ( V_2 ) || V_2 -> V_5 . V_645 )
V_894 = 1 ;
V_2 -> V_5 . V_646 += F_507 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_646 = F_320 ( V_2 -> V_5 . V_646 , V_894 ) ;
F_31 ( V_67 , V_2 ) ;
}
static void F_508 ( struct V_1 * V_2 )
{
T_2 V_1079 [ 4 ] ;
T_1 V_1080 [ 8 ] ;
if ( ! F_509 ( V_2 -> V_5 . V_618 ) )
return;
memset ( V_1079 , 0 , 32 ) ;
memset ( V_1080 , 0 , 32 ) ;
F_510 ( V_2 , V_1079 , V_1080 ) ;
V_73 -> V_1081 ( V_2 , V_1079 ) ;
F_511 ( V_2 , V_1080 ) ;
}
static void F_512 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1082 ;
V_73 -> V_1082 ( V_2 ) ;
}
void F_513 ( struct V_1 * V_2 )
{
struct V_395 * V_395 = NULL ;
if ( ! F_85 ( V_2 -> V_99 ) )
return;
if ( ! V_73 -> V_1083 )
return;
V_395 = F_358 ( V_2 -> V_99 , V_827 >> V_104 ) ;
V_73 -> V_1083 ( V_2 , F_514 ( V_395 ) ) ;
F_515 ( V_395 ) ;
}
void F_516 ( struct V_99 * V_99 ,
unsigned long V_80 )
{
if ( V_80 == F_189 ( V_99 , V_827 >> V_104 ) )
F_517 ( V_99 , V_1084 ) ;
}
static int F_518 ( struct V_1 * V_2 )
{
int V_117 ;
bool V_1072 = ! F_85 ( V_2 -> V_99 ) &&
V_2 -> V_834 -> V_1067 ;
bool V_1085 = false ;
if ( V_2 -> V_322 ) {
if ( F_519 ( V_1086 , V_2 ) )
F_520 ( V_2 ) ;
if ( F_519 ( V_1087 , V_2 ) )
F_521 ( V_2 ) ;
if ( F_519 ( V_284 , V_2 ) )
F_156 ( V_2 -> V_99 ) ;
if ( F_519 ( V_466 , V_2 ) )
F_171 ( V_2 ) ;
if ( F_519 ( V_320 , V_2 ) ) {
V_117 = F_160 ( V_2 ) ;
if ( F_150 ( V_117 ) )
goto V_111;
}
if ( F_519 ( V_1088 , V_2 ) )
F_82 ( V_2 ) ;
if ( F_519 ( V_164 , V_2 ) )
F_512 ( V_2 ) ;
if ( F_519 ( V_1089 , V_2 ) ) {
V_2 -> V_834 -> V_849 = V_1090 ;
V_117 = 0 ;
goto V_111;
}
if ( F_519 ( V_72 , V_2 ) ) {
V_2 -> V_834 -> V_849 = V_1091 ;
V_117 = 0 ;
goto V_111;
}
if ( F_519 ( V_1092 , V_2 ) ) {
V_2 -> V_1093 = 0 ;
V_73 -> V_1094 ( V_2 ) ;
}
if ( F_519 ( V_1095 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1096 = true ;
V_117 = 1 ;
goto V_111;
}
if ( F_519 ( V_471 , V_2 ) )
F_203 ( V_2 ) ;
if ( F_519 ( V_86 , V_2 ) )
F_262 ( V_2 ) ;
if ( F_519 ( V_1097 , V_2 ) )
F_522 ( V_2 ) ;
if ( F_519 ( V_1098 , V_2 ) )
F_523 ( V_2 ) ;
if ( F_519 ( V_1099 , V_2 ) )
F_508 ( V_2 ) ;
if ( F_519 ( V_1084 , V_2 ) )
F_513 ( V_2 ) ;
}
if ( F_519 ( V_67 , V_2 ) || V_1072 ) {
F_524 ( V_2 ) ;
if ( V_2 -> V_5 . V_1028 == V_1100 ) {
V_117 = 1 ;
goto V_111;
}
if ( F_503 ( V_2 , V_1072 ) != 0 )
V_1085 = true ;
else if ( V_2 -> V_5 . V_646 )
V_73 -> V_1101 ( V_2 ) ;
else if ( F_505 ( V_2 ) || V_1072 )
V_73 -> V_1102 ( V_2 ) ;
if ( F_525 ( V_2 ) ) {
if ( V_73 -> V_1103 )
V_73 -> V_1103 ( V_2 ,
F_502 ( V_2 ) ) ;
F_254 ( V_2 ) ;
F_526 ( V_2 ) ;
}
}
V_117 = F_527 ( V_2 ) ;
if ( F_150 ( V_117 ) ) {
goto V_1104;
}
F_208 () ;
V_73 -> V_1105 ( V_2 ) ;
if ( V_2 -> V_1093 )
F_406 ( V_2 ) ;
F_67 ( V_2 ) ;
V_2 -> V_314 = V_1106 ;
F_229 ( & V_2 -> V_99 -> V_518 , V_2 -> V_1107 ) ;
F_528 () ;
F_315 () ;
if ( V_2 -> V_314 == V_1108 || V_2 -> V_322
|| F_529 () || F_530 ( V_432 ) ) {
V_2 -> V_314 = V_1109 ;
F_14 () ;
F_316 () ;
F_209 () ;
V_2 -> V_1107 = F_228 ( & V_2 -> V_99 -> V_518 ) ;
V_117 = 1 ;
goto V_1104;
}
if ( V_1085 )
F_531 ( V_2 -> V_23 ) ;
F_532 () ;
if ( F_150 ( V_2 -> V_5 . V_177 ) ) {
F_533 ( 0 , 7 ) ;
F_533 ( V_2 -> V_5 . V_186 [ 0 ] , 0 ) ;
F_533 ( V_2 -> V_5 . V_186 [ 1 ] , 1 ) ;
F_533 ( V_2 -> V_5 . V_186 [ 2 ] , 2 ) ;
F_533 ( V_2 -> V_5 . V_186 [ 3 ] , 3 ) ;
F_533 ( V_2 -> V_5 . V_173 , 6 ) ;
}
F_534 ( V_2 -> V_285 ) ;
V_73 -> V_834 ( V_2 ) ;
if ( F_150 ( V_2 -> V_5 . V_177 & V_1110 ) ) {
int V_3 ;
F_29 ( V_2 -> V_170 & V_171 ) ;
V_73 -> V_1111 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_1112 ; V_3 ++ )
V_2 -> V_5 . V_186 [ V_3 ] = V_2 -> V_5 . V_185 [ V_3 ] ;
}
if ( F_535 () )
F_536 () ;
V_2 -> V_5 . V_308 = V_73 -> V_330 ( V_2 ,
F_164 () ) ;
V_2 -> V_314 = V_1109 ;
F_14 () ;
V_73 -> V_1113 ( V_2 ) ;
++ V_2 -> V_77 . V_1114 ;
F_537 () ;
F_538 () ;
F_209 () ;
V_2 -> V_1107 = F_228 ( & V_2 -> V_99 -> V_518 ) ;
if ( F_150 ( V_1115 == V_1116 ) ) {
unsigned long V_1066 = F_417 ( V_2 ) ;
F_539 ( V_1116 , ( void * ) V_1066 ) ;
}
if ( F_150 ( V_2 -> V_5 . V_1117 ) )
F_31 ( V_320 , V_2 ) ;
if ( V_2 -> V_5 . V_1118 )
F_540 ( V_2 ) ;
V_117 = V_73 -> V_1119 ( V_2 ) ;
return V_117 ;
V_1104:
V_73 -> V_1104 ( V_2 ) ;
if ( F_150 ( V_2 -> V_5 . V_1118 ) )
F_540 ( V_2 ) ;
V_111:
return V_117 ;
}
static int F_541 ( struct V_1 * V_2 )
{
int V_117 ;
struct V_99 * V_99 = V_2 -> V_99 ;
V_2 -> V_1107 = F_228 ( & V_99 -> V_518 ) ;
V_117 = 1 ;
while ( V_117 > 0 ) {
if ( V_2 -> V_5 . V_1028 == V_1120 &&
! V_2 -> V_5 . V_6 . V_1096 )
V_117 = F_518 ( V_2 ) ;
else {
F_229 ( & V_99 -> V_518 , V_2 -> V_1107 ) ;
F_542 ( V_2 ) ;
V_2 -> V_1107 = F_228 ( & V_99 -> V_518 ) ;
if ( F_519 ( V_1121 , V_2 ) ) {
F_524 ( V_2 ) ;
switch( V_2 -> V_5 . V_1028 ) {
case V_1029 :
V_2 -> V_5 . V_1122 . V_1123 = false ;
V_2 -> V_5 . V_1028 =
V_1120 ;
case V_1120 :
V_2 -> V_5 . V_6 . V_1096 = false ;
break;
case V_1100 :
break;
default:
V_117 = - V_1124 ;
break;
}
}
}
if ( V_117 <= 0 )
break;
F_159 ( V_1125 , & V_2 -> V_322 ) ;
if ( F_543 ( V_2 ) )
F_544 ( V_2 ) ;
if ( F_497 ( V_2 ) ) {
V_117 = - V_1124 ;
V_2 -> V_834 -> V_849 = V_1126 ;
++ V_2 -> V_77 . V_1127 ;
}
F_545 ( V_2 ) ;
if ( F_530 ( V_432 ) ) {
V_117 = - V_1124 ;
V_2 -> V_834 -> V_849 = V_1126 ;
++ V_2 -> V_77 . V_1128 ;
}
if ( F_529 () ) {
F_229 ( & V_99 -> V_518 , V_2 -> V_1107 ) ;
F_546 () ;
V_2 -> V_1107 = F_228 ( & V_99 -> V_518 ) ;
}
}
F_229 ( & V_99 -> V_518 , V_2 -> V_1107 ) ;
return V_117 ;
}
static inline int F_547 ( struct V_1 * V_2 )
{
int V_117 ;
V_2 -> V_1107 = F_228 ( & V_2 -> V_99 -> V_518 ) ;
V_117 = F_548 ( V_2 , V_963 ) ;
F_229 ( & V_2 -> V_99 -> V_518 , V_2 -> V_1107 ) ;
if ( V_117 != V_930 )
return 0 ;
return 1 ;
}
static int V_976 ( struct V_1 * V_2 )
{
F_13 ( ! V_2 -> V_5 . V_864 . V_736 ) ;
return F_547 ( V_2 ) ;
}
static int V_977 ( struct V_1 * V_2 )
{
struct V_949 * V_834 = V_2 -> V_834 ;
struct V_832 * V_833 ;
unsigned V_92 ;
F_13 ( ! V_2 -> V_845 ) ;
V_833 = & V_2 -> V_829 [ V_2 -> V_846 ] ;
V_92 = F_320 ( 8u , V_833 -> V_92 ) ;
if ( ! V_2 -> V_848 )
memcpy ( V_833 -> V_38 , V_834 -> V_835 . V_38 , V_92 ) ;
if ( V_833 -> V_92 <= 8 ) {
V_833 ++ ;
V_2 -> V_846 ++ ;
} else {
V_833 -> V_38 += V_92 ;
V_833 -> V_426 += V_92 ;
V_833 -> V_92 -= V_92 ;
}
if ( V_2 -> V_846 >= V_2 -> V_840 ) {
V_2 -> V_845 = 0 ;
if ( V_2 -> V_848 )
return 1 ;
V_2 -> V_828 = 1 ;
return F_547 ( V_2 ) ;
}
V_834 -> V_849 = V_850 ;
V_834 -> V_835 . V_851 = V_833 -> V_426 ;
if ( V_2 -> V_848 )
memcpy ( V_834 -> V_835 . V_38 , V_833 -> V_38 , F_320 ( 8u , V_833 -> V_92 ) ) ;
V_834 -> V_835 . V_92 = F_320 ( 8u , V_833 -> V_92 ) ;
V_834 -> V_835 . V_847 = V_2 -> V_848 ;
V_2 -> V_5 . V_975 = V_977 ;
return 0 ;
}
int F_549 ( struct V_1 * V_2 , struct V_949 * V_949 )
{
int V_117 ;
T_19 V_1129 ;
if ( ! F_550 ( V_432 ) && F_551 ( V_432 ) )
return - V_397 ;
if ( V_2 -> V_1130 )
F_552 ( V_1131 , & V_2 -> V_1132 , & V_1129 ) ;
if ( F_150 ( V_2 -> V_5 . V_1028 == V_1133 ) ) {
F_542 ( V_2 ) ;
F_524 ( V_2 ) ;
F_159 ( V_1121 , & V_2 -> V_322 ) ;
V_117 = - V_1134 ;
goto V_111;
}
if ( ! F_85 ( V_2 -> V_99 ) ) {
if ( F_84 ( V_2 , V_949 -> V_168 ) != 0 ) {
V_117 = - V_605 ;
goto V_111;
}
}
if ( F_150 ( V_2 -> V_5 . V_975 ) ) {
int (* F_553)( struct V_1 * ) = V_2 -> V_5 . V_975 ;
V_2 -> V_5 . V_975 = NULL ;
V_117 = F_553 ( V_2 ) ;
if ( V_117 <= 0 )
goto V_111;
} else
F_29 ( V_2 -> V_5 . V_864 . V_736 || V_2 -> V_845 ) ;
V_117 = F_541 ( V_2 ) ;
V_111:
F_500 ( V_2 ) ;
if ( V_2 -> V_1130 )
F_552 ( V_1131 , & V_1129 , NULL ) ;
return V_117 ;
}
int F_554 ( struct V_1 * V_2 , struct V_1135 * V_617 )
{
if ( V_2 -> V_5 . V_980 ) {
F_555 ( & V_2 -> V_5 . V_913 ) ;
V_2 -> V_5 . V_980 = false ;
}
V_617 -> V_1136 = F_98 ( V_2 , V_196 ) ;
V_617 -> V_1137 = F_98 ( V_2 , V_1041 ) ;
V_617 -> V_1138 = F_98 ( V_2 , V_195 ) ;
V_617 -> V_1139 = F_98 ( V_2 , V_197 ) ;
V_617 -> V_1140 = F_98 ( V_2 , V_1043 ) ;
V_617 -> V_1141 = F_98 ( V_2 , V_1042 ) ;
V_617 -> V_1142 = F_98 ( V_2 , V_1143 ) ;
V_617 -> V_1144 = F_98 ( V_2 , V_1145 ) ;
#ifdef F_60
V_617 -> V_1146 = F_98 ( V_2 , V_1044 ) ;
V_617 -> V_1147 = F_98 ( V_2 , V_1148 ) ;
V_617 -> V_1149 = F_98 ( V_2 , V_1150 ) ;
V_617 -> V_1151 = F_98 ( V_2 , V_1152 ) ;
V_617 -> V_1153 = F_98 ( V_2 , V_1154 ) ;
V_617 -> V_1155 = F_98 ( V_2 , V_1156 ) ;
V_617 -> V_1157 = F_98 ( V_2 , V_1158 ) ;
V_617 -> V_1159 = F_98 ( V_2 , V_1160 ) ;
#endif
V_617 -> V_1066 = F_417 ( V_2 ) ;
V_617 -> V_948 = F_416 ( V_2 ) ;
return 0 ;
}
int F_556 ( struct V_1 * V_2 , struct V_1135 * V_617 )
{
V_2 -> V_5 . V_924 = true ;
V_2 -> V_5 . V_980 = false ;
F_100 ( V_2 , V_196 , V_617 -> V_1136 ) ;
F_100 ( V_2 , V_1041 , V_617 -> V_1137 ) ;
F_100 ( V_2 , V_195 , V_617 -> V_1138 ) ;
F_100 ( V_2 , V_197 , V_617 -> V_1139 ) ;
F_100 ( V_2 , V_1043 , V_617 -> V_1140 ) ;
F_100 ( V_2 , V_1042 , V_617 -> V_1141 ) ;
F_100 ( V_2 , V_1143 , V_617 -> V_1142 ) ;
F_100 ( V_2 , V_1145 , V_617 -> V_1144 ) ;
#ifdef F_60
F_100 ( V_2 , V_1044 , V_617 -> V_1146 ) ;
F_100 ( V_2 , V_1148 , V_617 -> V_1147 ) ;
F_100 ( V_2 , V_1150 , V_617 -> V_1149 ) ;
F_100 ( V_2 , V_1152 , V_617 -> V_1151 ) ;
F_100 ( V_2 , V_1154 , V_617 -> V_1153 ) ;
F_100 ( V_2 , V_1156 , V_617 -> V_1155 ) ;
F_100 ( V_2 , V_1158 , V_617 -> V_1157 ) ;
F_100 ( V_2 , V_1160 , V_617 -> V_1159 ) ;
#endif
F_423 ( V_2 , V_617 -> V_1066 ) ;
F_424 ( V_2 , V_617 -> V_948 ) ;
V_2 -> V_5 . V_68 . V_69 = false ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
void F_557 ( struct V_1 * V_2 , int * V_185 , int * V_899 )
{
struct V_808 V_1161 ;
F_328 ( V_2 , & V_1161 , V_958 ) ;
* V_185 = V_1161 . V_185 ;
* V_899 = V_1161 . V_899 ;
}
int F_558 ( struct V_1 * V_2 ,
struct V_1162 * V_1163 )
{
struct V_882 V_883 ;
F_328 ( V_2 , & V_1163 -> V_1161 , V_958 ) ;
F_328 ( V_2 , & V_1163 -> V_1164 , V_1165 ) ;
F_328 ( V_2 , & V_1163 -> V_1166 , V_1167 ) ;
F_328 ( V_2 , & V_1163 -> V_1168 , V_1169 ) ;
F_328 ( V_2 , & V_1163 -> V_1170 , V_1171 ) ;
F_328 ( V_2 , & V_1163 -> V_1172 , V_1173 ) ;
F_328 ( V_2 , & V_1163 -> V_1174 , V_1175 ) ;
F_328 ( V_2 , & V_1163 -> V_1176 , V_1177 ) ;
V_73 -> V_885 ( V_2 , & V_883 ) ;
V_1163 -> V_1178 . V_894 = V_883 . V_523 ;
V_1163 -> V_1178 . V_895 = V_883 . V_80 ;
V_73 -> V_884 ( V_2 , & V_883 ) ;
V_1163 -> V_1179 . V_894 = V_883 . V_523 ;
V_1163 -> V_1179 . V_895 = V_883 . V_80 ;
V_1163 -> V_118 = F_59 ( V_2 ) ;
V_1163 -> V_79 = V_2 -> V_5 . V_79 ;
V_1163 -> V_102 = F_57 ( V_2 ) ;
V_1163 -> V_152 = F_74 ( V_2 ) ;
V_1163 -> V_168 = F_87 ( V_2 ) ;
V_1163 -> V_128 = V_2 -> V_5 . V_128 ;
V_1163 -> V_31 = F_20 ( V_2 ) ;
memset ( V_1163 -> V_1180 , 0 , sizeof V_1163 -> V_1180 ) ;
if ( V_2 -> V_5 . V_640 . V_69 && ! V_2 -> V_5 . V_640 . V_641 )
F_559 ( V_2 -> V_5 . V_640 . V_16 ,
( unsigned long * ) V_1163 -> V_1180 ) ;
return 0 ;
}
int F_560 ( struct V_1 * V_2 ,
struct V_1181 * V_1028 )
{
F_524 ( V_2 ) ;
if ( V_2 -> V_5 . V_1028 == V_1029 &&
V_2 -> V_5 . V_1122 . V_1123 )
V_1028 -> V_1028 = V_1120 ;
else
V_1028 -> V_1028 = V_2 -> V_5 . V_1028 ;
return 0 ;
}
int F_561 ( struct V_1 * V_2 ,
struct V_1181 * V_1028 )
{
if ( ! F_265 ( V_2 ) &&
V_1028 -> V_1028 != V_1120 )
return - V_605 ;
if ( V_1028 -> V_1028 == V_1182 ) {
V_2 -> V_5 . V_1028 = V_1100 ;
F_559 ( V_1183 , & V_2 -> V_5 . V_618 -> V_1184 ) ;
} else
V_2 -> V_5 . V_1028 = V_1028 -> V_1028 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
int F_562 ( struct V_1 * V_2 , V_860 V_1185 , int V_1186 ,
int V_1187 , bool V_71 , T_1 V_62 )
{
struct V_822 * V_823 = & V_2 -> V_5 . V_913 ;
int V_106 ;
F_415 ( V_2 ) ;
V_106 = F_563 ( V_823 , V_1185 , V_1186 , V_1187 ,
V_71 , V_62 ) ;
if ( V_106 )
return V_929 ;
F_423 ( V_2 , V_823 -> V_916 ) ;
F_424 ( V_2 , V_823 -> V_915 ) ;
F_31 ( V_67 , V_2 ) ;
return V_930 ;
}
int F_564 ( struct V_1 * V_2 ,
struct V_1162 * V_1163 )
{
struct V_32 V_1188 ;
int V_1189 = 0 ;
int V_1190 , V_1191 , V_370 ;
struct V_882 V_883 ;
if ( ! F_75 ( V_2 ) && ( V_1163 -> V_152 & V_136 ) )
return - V_605 ;
V_883 . V_523 = V_1163 -> V_1178 . V_894 ;
V_883 . V_80 = V_1163 -> V_1178 . V_895 ;
V_73 -> V_887 ( V_2 , & V_883 ) ;
V_883 . V_523 = V_1163 -> V_1179 . V_894 ;
V_883 . V_80 = V_1163 -> V_1179 . V_895 ;
V_73 -> V_886 ( V_2 , & V_883 ) ;
V_2 -> V_5 . V_79 = V_1163 -> V_79 ;
V_1189 |= F_57 ( V_2 ) != V_1163 -> V_102 ;
V_2 -> V_5 . V_102 = V_1163 -> V_102 ;
F_52 ( V_166 , ( V_167 * ) & V_2 -> V_5 . V_114 ) ;
F_84 ( V_2 , V_1163 -> V_168 ) ;
V_1189 |= V_2 -> V_5 . V_128 != V_1163 -> V_128 ;
V_73 -> F_104 ( V_2 , V_1163 -> V_128 ) ;
V_1188 . V_38 = V_1163 -> V_31 ;
V_1188 . V_40 = true ;
F_21 ( V_2 , & V_1188 ) ;
V_1189 |= F_59 ( V_2 ) != V_1163 -> V_118 ;
V_73 -> V_134 ( V_2 , V_1163 -> V_118 ) ;
V_2 -> V_5 . V_118 = V_1163 -> V_118 ;
V_1189 |= F_74 ( V_2 ) != V_1163 -> V_152 ;
V_73 -> V_163 ( V_2 , V_1163 -> V_152 ) ;
if ( V_1163 -> V_152 & V_136 )
F_71 ( V_2 ) ;
V_370 = F_228 ( & V_2 -> V_99 -> V_518 ) ;
if ( ! F_54 ( V_2 ) && F_55 ( V_2 ) ) {
F_49 ( V_2 , V_2 -> V_5 . V_101 , F_57 ( V_2 ) ) ;
V_1189 = 1 ;
}
F_229 ( & V_2 -> V_99 -> V_518 , V_370 ) ;
if ( V_1189 )
F_64 ( V_2 ) ;
V_1191 = V_621 ;
V_1190 = F_565 (
( const unsigned long * ) V_1163 -> V_1180 , V_1191 ) ;
if ( V_1190 < V_1191 ) {
F_256 ( V_2 , V_1190 , false ) ;
F_123 ( L_29 , V_1190 ) ;
}
F_327 ( V_2 , & V_1163 -> V_1161 , V_958 ) ;
F_327 ( V_2 , & V_1163 -> V_1164 , V_1165 ) ;
F_327 ( V_2 , & V_1163 -> V_1166 , V_1167 ) ;
F_327 ( V_2 , & V_1163 -> V_1168 , V_1169 ) ;
F_327 ( V_2 , & V_1163 -> V_1170 , V_1171 ) ;
F_327 ( V_2 , & V_1163 -> V_1172 , V_1173 ) ;
F_327 ( V_2 , & V_1163 -> V_1174 , V_1175 ) ;
F_327 ( V_2 , & V_1163 -> V_1176 , V_1177 ) ;
F_254 ( V_2 ) ;
if ( F_566 ( V_2 ) && F_417 ( V_2 ) == 0xfff0 &&
V_1163 -> V_1161 . V_888 == 0xf000 && V_1163 -> V_1161 . V_895 == 0xffff0000 &&
! F_418 ( V_2 ) )
V_2 -> V_5 . V_1028 = V_1120 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
int F_567 ( struct V_1 * V_2 ,
struct V_1192 * V_1193 )
{
unsigned long V_948 ;
int V_3 , V_117 ;
if ( V_1193 -> V_743 & ( V_1194 | V_1195 ) ) {
V_117 = - V_1196 ;
if ( V_2 -> V_5 . V_68 . V_69 )
goto V_111;
if ( V_1193 -> V_743 & V_1194 )
F_32 ( V_2 , V_53 ) ;
else
F_32 ( V_2 , V_54 ) ;
}
V_948 = F_416 ( V_2 ) ;
V_2 -> V_170 = V_1193 -> V_743 ;
if ( ! ( V_2 -> V_170 & V_1197 ) )
V_2 -> V_170 = 0 ;
if ( V_2 -> V_170 & V_171 ) {
for ( V_3 = 0 ; V_3 < V_1112 ; ++ V_3 )
V_2 -> V_5 . V_186 [ V_3 ] = V_1193 -> V_5 . V_1198 [ V_3 ] ;
V_2 -> V_5 . V_175 = V_1193 -> V_5 . V_1198 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1112 ; V_3 ++ )
V_2 -> V_5 . V_186 [ V_3 ] = V_2 -> V_5 . V_185 [ V_3 ] ;
}
F_90 ( V_2 ) ;
if ( V_2 -> V_170 & V_951 )
V_2 -> V_5 . V_955 = F_417 ( V_2 ) +
F_372 ( V_2 , V_958 ) ;
F_424 ( V_2 , V_948 ) ;
V_73 -> V_1199 ( V_2 ) ;
V_117 = 0 ;
V_111:
return V_117 ;
}
int F_568 ( struct V_1 * V_2 ,
struct V_1200 * V_1174 )
{
unsigned long V_1201 = V_1174 -> V_1202 ;
T_6 V_426 ;
int V_370 ;
V_370 = F_228 ( & V_2 -> V_99 -> V_518 ) ;
V_426 = F_333 ( V_2 , V_1201 , NULL ) ;
F_229 ( & V_2 -> V_99 -> V_518 , V_370 ) ;
V_1174 -> V_1203 = V_426 ;
V_1174 -> V_1204 = V_426 != V_97 ;
V_1174 -> V_1205 = 1 ;
V_1174 -> V_1206 = 0 ;
return 0 ;
}
int F_569 ( struct V_1 * V_2 , struct V_1207 * V_1208 )
{
struct V_668 * V_667 =
& V_2 -> V_5 . V_661 . V_662 -> V_667 ;
memcpy ( V_1208 -> V_1209 , V_667 -> V_1210 , 128 ) ;
V_1208 -> V_1211 = V_667 -> V_1212 ;
V_1208 -> V_1213 = V_667 -> V_1214 ;
V_1208 -> V_1215 = V_667 -> V_1216 ;
V_1208 -> V_1217 = V_667 -> V_1218 ;
V_1208 -> V_1219 = V_667 -> V_1066 ;
V_1208 -> V_1220 = V_667 -> V_1221 ;
memcpy ( V_1208 -> V_1222 , V_667 -> V_1223 , sizeof V_667 -> V_1223 ) ;
return 0 ;
}
int F_570 ( struct V_1 * V_2 , struct V_1207 * V_1208 )
{
struct V_668 * V_667 =
& V_2 -> V_5 . V_661 . V_662 -> V_667 ;
memcpy ( V_667 -> V_1210 , V_1208 -> V_1209 , 128 ) ;
V_667 -> V_1212 = V_1208 -> V_1211 ;
V_667 -> V_1214 = V_1208 -> V_1213 ;
V_667 -> V_1216 = V_1208 -> V_1215 ;
V_667 -> V_1218 = V_1208 -> V_1217 ;
V_667 -> V_1066 = V_1208 -> V_1219 ;
V_667 -> V_1221 = V_1208 -> V_1220 ;
memcpy ( V_667 -> V_1223 , V_1208 -> V_1222 , sizeof V_667 -> V_1223 ) ;
return 0 ;
}
int F_571 ( struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_572 ( & V_2 -> V_5 . V_661 ) ;
if ( V_29 )
return V_29 ;
F_573 ( & V_2 -> V_5 . V_661 ) ;
V_2 -> V_5 . V_139 = V_145 ;
V_2 -> V_5 . V_118 |= V_125 ;
return 0 ;
}
static void F_574 ( struct V_1 * V_2 )
{
F_575 ( & V_2 -> V_5 . V_661 ) ;
}
void F_406 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1224 )
return;
F_69 ( V_2 ) ;
V_2 -> V_1224 = 1 ;
F_576 () ;
F_577 ( & V_2 -> V_5 . V_661 ) ;
F_578 ( 1 ) ;
}
void F_250 ( struct V_1 * V_2 )
{
F_69 ( V_2 ) ;
if ( ! V_2 -> V_1224 )
return;
V_2 -> V_1224 = 0 ;
F_579 ( & V_2 -> V_5 . V_661 ) ;
F_580 () ;
++ V_2 -> V_77 . V_1225 ;
F_31 ( V_1092 , V_2 ) ;
F_578 ( 0 ) ;
}
void F_581 ( struct V_1 * V_2 )
{
F_201 ( V_2 ) ;
F_582 ( V_2 -> V_5 . V_608 ) ;
F_574 ( V_2 ) ;
V_73 -> V_1226 ( V_2 ) ;
}
struct V_1 * F_583 ( struct V_99 * V_99 ,
unsigned int V_1227 )
{
if ( F_138 () && F_133 ( & V_99 -> V_281 ) != 0 )
F_366 ( V_862
L_30
L_31 ) ;
return V_73 -> V_1228 ( V_99 , V_1227 ) ;
}
int F_584 ( struct V_1 * V_2 )
{
int V_117 ;
V_2 -> V_5 . V_365 . V_1229 = 1 ;
V_117 = V_609 ( V_2 ) ;
if ( V_117 )
return V_117 ;
F_585 ( V_2 ) ;
F_586 ( V_2 ) ;
V_613 ( V_2 ) ;
return V_117 ;
}
int F_587 ( struct V_1 * V_2 )
{
int V_117 ;
struct V_32 V_21 ;
struct V_99 * V_99 = V_2 -> V_99 ;
V_117 = V_609 ( V_2 ) ;
if ( V_117 )
return V_117 ;
V_21 . V_38 = 0x0 ;
V_21 . V_141 = V_1230 ;
V_21 . V_40 = true ;
F_136 ( V_2 , & V_21 ) ;
V_613 ( V_2 ) ;
F_172 ( & V_99 -> V_5 . V_348 ,
V_349 ) ;
return V_117 ;
}
void F_588 ( struct V_1 * V_2 )
{
int V_117 ;
V_2 -> V_5 . V_6 . V_427 = 0 ;
V_117 = V_609 ( V_2 ) ;
F_13 ( V_117 ) ;
F_520 ( V_2 ) ;
V_613 ( V_2 ) ;
F_574 ( V_2 ) ;
V_73 -> V_1226 ( V_2 ) ;
}
void F_585 ( struct V_1 * V_2 )
{
F_154 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_646 = 0 ;
V_2 -> V_5 . V_645 = false ;
F_589 ( V_2 ) ;
F_438 ( V_2 ) ;
memset ( V_2 -> V_5 . V_185 , 0 , sizeof( V_2 -> V_5 . V_185 ) ) ;
V_2 -> V_5 . V_173 = V_1231 ;
F_89 ( V_2 ) ;
V_2 -> V_5 . V_174 = V_190 ;
F_90 ( V_2 ) ;
F_31 ( V_67 , V_2 ) ;
V_2 -> V_5 . V_6 . V_427 = 0 ;
V_2 -> V_5 . V_431 . V_427 = 0 ;
F_201 ( V_2 ) ;
F_63 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1096 = false ;
F_590 ( V_2 ) ;
memset ( V_2 -> V_5 . V_617 , 0 , sizeof( V_2 -> V_5 . V_617 ) ) ;
V_2 -> V_5 . V_114 = ~ 0 ;
V_2 -> V_5 . V_115 = ~ 0 ;
V_73 -> V_1232 ( V_2 ) ;
}
void F_591 ( struct V_1 * V_2 , unsigned int V_41 )
{
struct V_808 V_1161 ;
F_328 ( V_2 , & V_1161 , V_958 ) ;
V_1161 . V_888 = V_41 << 8 ;
V_1161 . V_895 = V_41 << 12 ;
F_327 ( V_2 , & V_1161 , V_958 ) ;
F_423 ( V_2 , 0 ) ;
}
int F_592 ( void )
{
struct V_99 * V_99 ;
struct V_1 * V_2 ;
int V_3 ;
int V_106 ;
T_2 V_1233 ;
T_2 V_1234 = 0 ;
bool V_1235 , V_1236 = false ;
F_15 () ;
V_106 = V_73 -> V_1237 () ;
if ( V_106 != 0 )
return V_106 ;
V_1233 = F_164 () ;
V_1235 = ! F_138 () ;
F_451 (kvm, &vm_list, vm_list) {
F_158 (i, vcpu, kvm) {
if ( ! V_1235 && V_2 -> V_23 == F_8 () )
F_31 ( V_320 , V_2 ) ;
if ( V_1235 && V_2 -> V_5 . V_612 > V_1233 ) {
V_1236 = true ;
if ( V_2 -> V_5 . V_612 > V_1234 )
V_1234 = V_2 -> V_5 . V_612 ;
}
}
}
if ( V_1236 ) {
T_2 V_1238 = V_1234 - V_1233 ;
V_318 = true ;
F_451 (kvm, &vm_list, vm_list) {
F_158 (i, vcpu, kvm) {
V_2 -> V_5 . V_610 += V_1238 ;
V_2 -> V_5 . V_612 = V_1233 ;
F_31 ( V_284 , V_2 ) ;
}
V_99 -> V_5 . V_297 = 0 ;
V_99 -> V_5 . V_299 = 0 ;
}
}
return 0 ;
}
void F_593 ( void )
{
V_73 -> V_1239 () ;
F_19 () ;
}
int F_594 ( void )
{
return V_73 -> V_1240 () ;
}
void F_595 ( void )
{
V_73 -> V_1241 () ;
}
void F_596 ( void * V_1242 )
{
V_73 -> V_1243 ( V_1242 ) ;
}
bool F_597 ( struct V_1 * V_2 )
{
return F_85 ( V_2 -> V_99 ) == ( V_2 -> V_5 . V_618 != NULL ) ;
}
int F_598 ( struct V_1 * V_2 )
{
struct V_395 * V_395 ;
struct V_99 * V_99 ;
int V_117 ;
F_13 ( V_2 -> V_99 == NULL ) ;
V_99 = V_2 -> V_99 ;
V_2 -> V_5 . V_1122 . V_1123 = false ;
V_2 -> V_5 . V_913 . V_837 = & V_1244 ;
if ( ! F_85 ( V_99 ) || F_566 ( V_2 ) )
V_2 -> V_5 . V_1028 = V_1120 ;
else
V_2 -> V_5 . V_1028 = V_1133 ;
V_395 = F_599 ( V_680 | V_1245 ) ;
if ( ! V_395 ) {
V_117 = - V_397 ;
goto V_1246;
}
V_2 -> V_5 . V_867 = F_600 ( V_395 ) ;
F_130 ( V_2 , V_998 ) ;
V_117 = F_601 ( V_2 ) ;
if ( V_117 < 0 )
goto V_1247;
if ( F_85 ( V_99 ) ) {
V_117 = F_602 ( V_2 ) ;
if ( V_117 < 0 )
goto V_1248;
} else
F_603 ( & V_1249 ) ;
V_2 -> V_5 . V_384 = F_275 ( V_473 * sizeof( T_2 ) * 4 ,
V_680 ) ;
if ( ! V_2 -> V_5 . V_384 ) {
V_117 = - V_397 ;
goto V_1250;
}
V_2 -> V_5 . V_376 = V_473 ;
if ( ! F_604 ( & V_2 -> V_5 . V_608 , V_680 ) ) {
V_117 = - V_397 ;
goto V_1251;
}
V_117 = F_571 ( V_2 ) ;
if ( V_117 )
goto V_1252;
V_2 -> V_5 . V_288 = 0x0 ;
V_2 -> V_5 . V_332 = false ;
V_2 -> V_5 . V_148 = 0 ;
V_2 -> V_5 . V_664 = V_1253 + V_665 ;
F_1 ( V_2 ) ;
F_605 ( V_2 ) ;
return 0 ;
V_1252:
F_582 ( V_2 -> V_5 . V_608 ) ;
V_1251:
F_185 ( V_2 -> V_5 . V_384 ) ;
V_1250:
F_606 ( V_2 ) ;
V_1248:
F_607 ( V_2 ) ;
V_1247:
F_608 ( ( unsigned long ) V_2 -> V_5 . V_867 ) ;
V_1246:
return V_117 ;
}
void F_609 ( struct V_1 * V_2 )
{
int V_370 ;
F_610 ( V_2 ) ;
F_185 ( V_2 -> V_5 . V_384 ) ;
F_606 ( V_2 ) ;
V_370 = F_228 ( & V_2 -> V_99 -> V_518 ) ;
F_607 ( V_2 ) ;
F_229 ( & V_2 -> V_99 -> V_518 , V_370 ) ;
F_608 ( ( unsigned long ) V_2 -> V_5 . V_867 ) ;
if ( ! F_85 ( V_2 -> V_99 ) )
F_611 ( & V_1249 ) ;
}
void F_612 ( struct V_1 * V_2 , int V_23 )
{
V_73 -> V_1254 ( V_2 , V_23 ) ;
}
int F_613 ( struct V_99 * V_99 , unsigned long type )
{
if ( type )
return - V_605 ;
F_614 ( & V_99 -> V_5 . V_1255 ) ;
F_614 ( & V_99 -> V_5 . V_1256 ) ;
F_614 ( & V_99 -> V_5 . V_1257 ) ;
F_154 ( & V_99 -> V_5 . V_1258 , 0 ) ;
F_559 ( V_758 , & V_99 -> V_5 . V_1259 ) ;
F_559 ( V_1260 ,
& V_99 -> V_5 . V_1259 ) ;
F_615 ( & V_99 -> V_5 . V_295 ) ;
F_616 ( & V_99 -> V_5 . V_1261 ) ;
F_617 ( & V_99 -> V_5 . V_310 ) ;
F_153 ( V_99 ) ;
F_618 ( & V_99 -> V_5 . V_346 , F_168 ) ;
F_618 ( & V_99 -> V_5 . V_348 , F_173 ) ;
return 0 ;
}
static void F_619 ( struct V_1 * V_2 )
{
int V_117 ;
V_117 = V_609 ( V_2 ) ;
F_13 ( V_117 ) ;
F_520 ( V_2 ) ;
V_613 ( V_2 ) ;
}
static void F_620 ( struct V_99 * V_99 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_158 (i, vcpu, kvm) {
F_63 ( V_2 ) ;
F_619 ( V_2 ) ;
}
F_158 (i, vcpu, kvm)
F_581 ( V_2 ) ;
F_212 ( & V_99 -> V_488 ) ;
for ( V_3 = 0 ; V_3 < F_133 ( & V_99 -> V_281 ) ; V_3 ++ )
V_99 -> V_1262 [ V_3 ] = NULL ;
F_154 ( & V_99 -> V_281 , 0 ) ;
F_213 ( & V_99 -> V_488 ) ;
}
void F_621 ( struct V_99 * V_99 )
{
F_622 ( & V_99 -> V_5 . V_348 ) ;
F_622 ( & V_99 -> V_5 . V_346 ) ;
F_623 ( V_99 ) ;
F_624 ( V_99 ) ;
}
void F_625 ( struct V_99 * V_99 )
{
if ( V_432 -> V_1263 == V_99 -> V_1263 ) {
struct V_1264 V_1265 ;
memset ( & V_1265 , 0 , sizeof( V_1265 ) ) ;
V_1265 . V_10 = V_1266 ;
F_626 ( V_99 , & V_1265 ) ;
V_1265 . V_10 = V_1267 ;
F_626 ( V_99 , & V_1265 ) ;
V_1265 . V_10 = V_1268 ;
F_626 ( V_99 , & V_1265 ) ;
}
F_627 ( V_99 ) ;
F_185 ( V_99 -> V_5 . V_770 ) ;
F_185 ( V_99 -> V_5 . V_1269 ) ;
F_620 ( V_99 ) ;
F_185 ( F_628 ( V_99 -> V_5 . V_1270 , 1 ) ) ;
}
void F_629 ( struct V_99 * V_99 , struct V_746 * free ,
struct V_746 * V_1271 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1272 ; ++ V_3 ) {
if ( ! V_1271 || free -> V_5 . V_1273 [ V_3 ] != V_1271 -> V_5 . V_1273 [ V_3 ] ) {
F_630 ( free -> V_5 . V_1273 [ V_3 ] ) ;
free -> V_5 . V_1273 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1271 || free -> V_5 . V_1274 [ V_3 - 1 ] !=
V_1271 -> V_5 . V_1274 [ V_3 - 1 ] ) {
F_630 ( free -> V_5 . V_1274 [ V_3 - 1 ] ) ;
free -> V_5 . V_1274 [ V_3 - 1 ] = NULL ;
}
}
}
int F_631 ( struct V_99 * V_99 , struct V_746 * V_10 ,
unsigned long V_1275 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1272 ; ++ V_3 ) {
unsigned long V_1276 ;
int V_1277 ;
int V_759 = V_3 + 1 ;
V_1277 = F_632 ( V_10 -> V_1278 + V_1275 - 1 ,
V_10 -> V_1278 , V_759 ) + 1 ;
V_10 -> V_5 . V_1273 [ V_3 ] =
F_633 ( V_1277 * sizeof( * V_10 -> V_5 . V_1273 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1273 [ V_3 ] )
goto V_398;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1274 [ V_3 - 1 ] = F_633 ( V_1277 *
sizeof( * V_10 -> V_5 . V_1274 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1274 [ V_3 - 1 ] )
goto V_398;
if ( V_10 -> V_1278 & ( F_634 ( V_759 ) - 1 ) )
V_10 -> V_5 . V_1274 [ V_3 - 1 ] [ 0 ] . V_1279 = 1 ;
if ( ( V_10 -> V_1278 + V_1275 ) & ( F_634 ( V_759 ) - 1 ) )
V_10 -> V_5 . V_1274 [ V_3 - 1 ] [ V_1277 - 1 ] . V_1279 = 1 ;
V_1276 = V_10 -> V_1280 >> V_104 ;
if ( ( V_10 -> V_1278 ^ V_1276 ) & ( F_634 ( V_759 ) - 1 ) ||
! F_635 () ) {
unsigned long V_800 ;
for ( V_800 = 0 ; V_800 < V_1277 ; ++ V_800 )
V_10 -> V_5 . V_1274 [ V_3 - 1 ] [ V_800 ] . V_1279 = 1 ;
}
}
return 0 ;
V_398:
for ( V_3 = 0 ; V_3 < V_1272 ; ++ V_3 ) {
F_630 ( V_10 -> V_5 . V_1273 [ V_3 ] ) ;
V_10 -> V_5 . V_1273 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_630 ( V_10 -> V_5 . V_1274 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1274 [ V_3 - 1 ] = NULL ;
}
return - V_397 ;
}
void F_636 ( struct V_99 * V_99 )
{
F_637 ( V_99 ) ;
}
int F_638 ( struct V_99 * V_99 ,
struct V_746 * V_747 ,
struct V_1264 * V_1265 ,
enum V_1281 V_1282 )
{
if ( ( V_747 -> V_1227 >= V_573 ) && ( V_1282 == V_1283 ) ) {
unsigned long V_1280 ;
V_1280 = F_639 ( NULL , 0 , V_747 -> V_1275 * V_105 ,
V_1284 | V_1285 ,
V_1286 | V_1287 , 0 ) ;
if ( F_183 ( ( void * ) V_1280 ) )
return F_184 ( ( void * ) V_1280 ) ;
V_747 -> V_1280 = V_1280 ;
}
return 0 ;
}
void F_640 ( struct V_99 * V_99 ,
struct V_1264 * V_1265 ,
const struct V_746 * V_855 ,
enum V_1281 V_1282 )
{
int V_1288 = 0 ;
if ( ( V_1265 -> V_10 >= V_573 ) && ( V_1282 == V_1289 ) ) {
int V_106 ;
V_106 = F_641 ( V_855 -> V_1280 ,
V_855 -> V_1275 * V_105 ) ;
if ( V_106 < 0 )
F_10 ( V_862
L_32
L_33 ) ;
}
if ( ! V_99 -> V_5 . V_719 )
V_1288 = F_642 ( V_99 ) ;
if ( V_1288 )
F_284 ( V_99 , V_1288 ) ;
if ( ( V_1282 != V_1289 ) && ( V_1265 -> V_291 & V_1290 ) )
F_643 ( V_99 , V_1265 -> V_10 ) ;
}
void F_644 ( struct V_99 * V_99 )
{
F_645 ( V_99 ) ;
}
void F_646 ( struct V_99 * V_99 ,
struct V_746 * V_10 )
{
F_645 ( V_99 ) ;
}
int F_647 ( struct V_1 * V_2 )
{
if ( F_419 ( V_2 ) && V_73 -> V_1076 )
V_73 -> V_1076 ( V_2 , false ) ;
return ( V_2 -> V_5 . V_1028 == V_1120 &&
! V_2 -> V_5 . V_6 . V_1096 )
|| ! F_648 ( & V_2 -> V_1291 . V_1292 )
|| F_649 ( V_2 )
|| V_2 -> V_5 . V_1122 . V_1123
|| F_133 ( & V_2 -> V_5 . V_85 ) ||
( F_499 ( V_2 ) &&
F_498 ( V_2 ) ) ;
}
int F_650 ( struct V_1 * V_2 )
{
return F_651 ( V_2 ) == V_1106 ;
}
int F_499 ( struct V_1 * V_2 )
{
return V_73 -> V_1078 ( V_2 ) ;
}
bool F_652 ( struct V_1 * V_2 , unsigned long V_1293 )
{
unsigned long V_1294 = F_417 ( V_2 ) +
F_372 ( V_2 , V_958 ) ;
return V_1294 == V_1293 ;
}
unsigned long F_416 ( struct V_1 * V_2 )
{
unsigned long V_948 ;
V_948 = V_73 -> V_979 ( V_2 ) ;
if ( V_2 -> V_170 & V_951 )
V_948 &= ~ V_950 ;
return V_948 ;
}
static void F_443 ( struct V_1 * V_2 , unsigned long V_948 )
{
if ( V_2 -> V_170 & V_951 &&
F_652 ( V_2 , V_2 -> V_5 . V_955 ) )
V_948 |= V_950 ;
V_73 -> V_1295 ( V_2 , V_948 ) ;
}
void F_424 ( struct V_1 * V_2 , unsigned long V_948 )
{
F_443 ( V_2 , V_948 ) ;
F_31 ( V_67 , V_2 ) ;
}
void F_653 ( struct V_1 * V_2 , struct V_1296 * V_343 )
{
int V_117 ;
if ( ( V_2 -> V_5 . V_84 . V_941 != V_343 -> V_5 . V_941 ) ||
V_343 -> V_1297 )
return;
V_117 = F_527 ( V_2 ) ;
if ( F_150 ( V_117 ) )
return;
if ( ! V_2 -> V_5 . V_84 . V_941 &&
V_343 -> V_5 . V_102 != V_2 -> V_5 . V_84 . V_1298 ( V_2 ) )
return;
V_2 -> V_5 . V_84 . V_1299 ( V_2 , V_343 -> V_815 , 0 , true ) ;
}
static inline T_1 F_654 ( T_5 V_100 )
{
return F_655 ( V_100 & 0xffffffff , F_656 ( V_4 ) ) ;
}
static inline T_1 F_657 ( T_1 V_1300 )
{
return ( V_1300 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_658 ( struct V_1 * V_2 , T_5 V_100 )
{
T_1 V_1300 = F_654 ( V_100 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1300 ] != ~ 0 )
V_1300 = F_657 ( V_1300 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1300 ] = V_100 ;
}
static T_1 F_659 ( struct V_1 * V_2 , T_5 V_100 )
{
int V_3 ;
T_1 V_1300 = F_654 ( V_100 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1300 ] != V_100 &&
V_2 -> V_5 . V_6 . V_7 [ V_1300 ] != ~ 0 ) ; V_3 ++ )
V_1300 = F_657 ( V_1300 ) ;
return V_1300 ;
}
bool F_660 ( struct V_1 * V_2 , T_5 V_100 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_659 ( V_2 , V_100 ) ] == V_100 ;
}
static void F_661 ( struct V_1 * V_2 , T_5 V_100 )
{
T_1 V_3 , V_800 , V_1301 ;
V_3 = V_800 = F_659 ( V_2 , V_100 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_800 = F_657 ( V_800 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_800 ] == ~ 0 )
return;
V_1301 = F_654 ( V_2 -> V_5 . V_6 . V_7 [ V_800 ] ) ;
} while ( ( V_3 <= V_800 ) ? ( V_3 < V_1301 && V_1301 <= V_800 ) : ( V_3 < V_1301 || V_1301 <= V_800 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_800 ] ;
V_3 = V_800 ;
}
}
static int F_662 ( struct V_1 * V_2 , T_1 V_184 )
{
return F_167 ( V_2 -> V_99 , & V_2 -> V_5 . V_6 . V_38 , & V_184 ,
sizeof( V_184 ) ) ;
}
void F_663 ( struct V_1 * V_2 ,
struct V_1296 * V_343 )
{
struct V_75 V_76 ;
F_664 ( V_343 -> V_5 . V_1302 , V_343 -> V_815 ) ;
F_658 ( V_2 , V_343 -> V_5 . V_100 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_427 & V_428 ) ||
( V_2 -> V_5 . V_6 . V_429 &&
V_73 -> V_88 ( V_2 ) == 0 ) )
F_31 ( V_1095 , V_2 ) ;
else if ( ! F_662 ( V_2 , V_1303 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_914 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_343 -> V_5 . V_1302 ;
F_36 ( V_2 , & V_76 ) ;
}
}
void F_665 ( struct V_1 * V_2 ,
struct V_1296 * V_343 )
{
struct V_75 V_76 ;
F_666 ( V_343 -> V_5 . V_1302 , V_343 -> V_815 ) ;
if ( V_343 -> V_1297 )
V_343 -> V_5 . V_1302 = ~ 0 ;
else
F_661 ( V_2 , V_343 -> V_5 . V_100 ) ;
if ( ( V_2 -> V_5 . V_6 . V_427 & V_428 ) &&
! F_662 ( V_2 , V_1304 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_914 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_343 -> V_5 . V_1302 ;
F_36 ( V_2 , & V_76 ) ;
}
V_2 -> V_5 . V_6 . V_1096 = false ;
V_2 -> V_5 . V_1028 = V_1120 ;
}
bool F_667 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_427 & V_428 ) )
return true ;
else
return ! F_501 ( V_2 ) &&
V_73 -> V_1078 ( V_2 ) ;
}
void F_668 ( struct V_99 * V_99 )
{
F_41 ( & V_99 -> V_5 . V_1258 ) ;
}
void F_669 ( struct V_99 * V_99 )
{
F_670 ( & V_99 -> V_5 . V_1258 ) ;
}
bool F_242 ( struct V_99 * V_99 )
{
return F_133 ( & V_99 -> V_5 . V_1258 ) ;
}
