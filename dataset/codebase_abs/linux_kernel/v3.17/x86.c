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
void F_16 ( unsigned V_10 , T_2 V_22 , T_2 V_28 )
{
unsigned int V_23 = F_8 () ;
struct V_11 * V_24 = F_9 ( V_25 , V_23 ) ;
if ( ( ( V_22 ^ V_24 -> V_14 [ V_10 ] . V_18 ) & V_28 ) == 0 )
return;
V_24 -> V_14 [ V_10 ] . V_18 = V_22 ;
F_5 ( V_15 . V_19 [ V_10 ] , V_22 ) ;
if ( ! V_24 -> V_20 ) {
V_24 -> V_9 . V_29 = F_3 ;
F_17 ( & V_24 -> V_9 ) ;
V_24 -> V_20 = true ;
}
}
static void F_18 ( void * V_30 )
{
unsigned int V_23 = F_8 () ;
struct V_11 * V_24 = F_9 ( V_25 , V_23 ) ;
if ( V_24 -> V_20 )
F_3 ( & V_24 -> V_9 ) ;
}
T_2 F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_5 . V_31 ;
}
int F_20 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
T_2 V_34 = V_2 -> V_5 . V_31 &
( V_35 | V_36 ) ;
T_2 V_37 = V_33 -> V_38 &
( V_35 | V_36 ) ;
T_2 V_39 = ( ( ~ 0ULL ) << F_21 ( V_2 ) ) |
0x2ff | ( F_22 ( V_2 ) ? 0 : V_36 ) ;
if ( ! V_33 -> V_40 &&
( ( V_33 -> V_38 & V_39 ) != 0 ||
V_37 == V_36 ||
( V_37 == V_35 &&
V_34 == ( V_35 | V_36 ) ) ||
( V_37 == ( V_35 | V_36 ) &&
V_34 == 0 ) ) )
return 1 ;
F_23 ( V_2 , V_33 -> V_38 ) ;
return 0 ;
}
T_3 T_4 void F_24 ( void )
{
F_25 () ;
}
static int F_26 ( int V_41 )
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
static int F_27 ( int V_41 )
{
unsigned int V_28 ;
if ( F_28 ( V_41 > 31 || V_41 == V_51 ) )
return V_52 ;
V_28 = 1 << V_41 ;
if ( V_28 & ( ( 1 << V_53 ) | ( 1 << V_54 ) | ( 1 << V_55 ) ) )
return V_56 ;
if ( V_28 & ( ( 1 << V_57 ) | ( 1 << V_58 ) ) )
return V_59 ;
return V_60 ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned V_16 , bool V_61 , T_1 V_62 ,
bool V_63 )
{
T_1 V_64 ;
int V_65 , V_66 ;
F_30 ( V_67 , V_2 ) ;
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
F_30 ( V_72 , V_2 ) ;
return;
}
V_65 = F_26 ( V_64 ) ;
V_66 = F_26 ( V_16 ) ;
if ( ( V_65 == V_49 && V_66 == V_49 )
|| ( V_65 == V_43 && V_66 != V_50 ) ) {
V_2 -> V_5 . V_68 . V_69 = true ;
V_2 -> V_5 . V_68 . V_71 = true ;
V_2 -> V_5 . V_68 . V_16 = V_57 ;
V_2 -> V_5 . V_68 . V_62 = 0 ;
} else
goto V_70;
}
void F_31 ( struct V_1 * V_2 , unsigned V_16 )
{
F_29 ( V_2 , V_16 , false , 0 , false ) ;
}
void F_32 ( struct V_1 * V_2 , unsigned V_16 )
{
F_29 ( V_2 , V_16 , false , 0 , true ) ;
}
void F_33 ( struct V_1 * V_2 , int V_73 )
{
if ( V_73 )
F_34 ( V_2 , 0 ) ;
else
V_74 -> V_75 ( V_2 ) ;
}
void F_35 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
++ V_2 -> V_78 . V_79 ;
V_2 -> V_5 . V_80 = V_77 -> V_81 ;
F_36 ( V_2 , V_42 , V_77 -> V_62 ) ;
}
void F_37 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
if ( F_38 ( V_2 ) && ! V_77 -> V_82 )
V_2 -> V_5 . V_83 . V_84 ( V_2 , V_77 ) ;
else
V_2 -> V_5 . V_85 . V_84 ( V_2 , V_77 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_5 . V_86 ) ;
F_30 ( V_87 , V_2 ) ;
}
void F_36 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_62 )
{
F_29 ( V_2 , V_16 , true , V_62 , false ) ;
}
void F_41 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_62 )
{
F_29 ( V_2 , V_16 , true , V_62 , true ) ;
}
bool F_42 ( struct V_1 * V_2 , int V_88 )
{
if ( V_74 -> V_89 ( V_2 ) <= V_88 )
return true ;
F_36 ( V_2 , V_48 , 0 ) ;
return false ;
}
int F_43 ( struct V_1 * V_2 , struct V_90 * V_85 ,
T_5 V_91 , void * V_38 , int V_92 , int V_93 ,
T_1 V_94 )
{
T_5 V_95 ;
T_6 V_96 ;
V_96 = F_44 ( V_91 ) ;
V_95 = V_85 -> V_97 ( V_2 , V_96 , V_94 ) ;
if ( V_95 == V_98 )
return - V_99 ;
V_95 = F_45 ( V_95 ) ;
return F_46 ( V_2 -> V_100 , V_95 , V_38 , V_92 , V_93 ) ;
}
int F_47 ( struct V_1 * V_2 , T_5 V_101 ,
void * V_38 , int V_92 , int V_93 , T_1 V_94 )
{
return F_43 ( V_2 , V_2 -> V_5 . V_102 , V_101 ,
V_38 , V_92 , V_93 , V_94 ) ;
}
int F_48 ( struct V_1 * V_2 , struct V_90 * V_85 , unsigned long V_103 )
{
T_5 V_104 = V_103 >> V_105 ;
unsigned V_92 = ( ( V_103 & ( V_106 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_107 ;
T_2 V_108 [ F_49 ( V_85 -> V_109 ) ] ;
V_107 = F_43 ( V_2 , V_85 , V_104 , V_108 ,
V_92 * sizeof( T_2 ) , sizeof( V_108 ) ,
V_110 | V_111 ) ;
if ( V_107 < 0 ) {
V_107 = 0 ;
goto V_112;
}
for ( V_3 = 0 ; V_3 < F_49 ( V_108 ) ; ++ V_3 ) {
if ( F_50 ( V_108 [ V_3 ] ) &&
( V_108 [ V_3 ] & V_2 -> V_5 . V_85 . V_113 [ 0 ] [ 2 ] ) ) {
V_107 = 0 ;
goto V_112;
}
}
V_107 = 1 ;
memcpy ( V_85 -> V_109 , V_108 , sizeof( V_85 -> V_109 ) ) ;
F_51 ( V_114 ,
( unsigned long * ) & V_2 -> V_5 . V_115 ) ;
F_51 ( V_114 ,
( unsigned long * ) & V_2 -> V_5 . V_116 ) ;
V_112:
return V_107 ;
}
static bool F_52 ( struct V_1 * V_2 )
{
T_2 V_108 [ F_49 ( V_2 -> V_5 . V_102 -> V_109 ) ] ;
bool V_117 = true ;
int V_92 ;
T_5 V_101 ;
int V_118 ;
if ( F_53 ( V_2 ) || ! F_54 ( V_2 ) )
return false ;
if ( ! F_55 ( V_114 ,
( unsigned long * ) & V_2 -> V_5 . V_115 ) )
return true ;
V_101 = ( F_56 ( V_2 ) & ~ 31u ) >> V_105 ;
V_92 = ( F_56 ( V_2 ) & ~ 31u ) & ( V_106 - 1 ) ;
V_118 = F_47 ( V_2 , V_101 , V_108 , V_92 , sizeof( V_108 ) ,
V_110 | V_111 ) ;
if ( V_118 < 0 )
goto V_112;
V_117 = memcmp ( V_108 , V_2 -> V_5 . V_102 -> V_109 , sizeof( V_108 ) ) != 0 ;
V_112:
return V_117 ;
}
int F_57 ( struct V_1 * V_2 , unsigned long V_119 )
{
unsigned long V_120 = F_58 ( V_2 ) ;
unsigned long V_121 = V_122 | V_123 |
V_124 | V_125 ;
V_119 |= V_126 ;
#ifdef F_59
if ( V_119 & 0xffffffff00000000UL )
return 1 ;
#endif
V_119 &= ~ V_127 ;
if ( ( V_119 & V_125 ) && ! ( V_119 & V_124 ) )
return 1 ;
if ( ( V_119 & V_122 ) && ! ( V_119 & V_128 ) )
return 1 ;
if ( ! F_60 ( V_2 ) && ( V_119 & V_122 ) ) {
#ifdef F_59
if ( ( V_2 -> V_5 . V_129 & V_130 ) ) {
int V_131 , V_132 ;
if ( ! F_54 ( V_2 ) )
return 1 ;
V_74 -> V_133 ( V_2 , & V_131 , & V_132 ) ;
if ( V_132 )
return 1 ;
} else
#endif
if ( F_54 ( V_2 ) && ! F_48 ( V_2 , V_2 -> V_5 . V_102 ,
F_56 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_119 & V_122 ) && F_61 ( V_2 , V_134 ) )
return 1 ;
V_74 -> V_135 ( V_2 , V_119 ) ;
if ( ( V_119 ^ V_120 ) & V_122 ) {
F_62 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_119 ^ V_120 ) & V_121 )
F_63 ( V_2 ) ;
return 0 ;
}
void F_64 ( struct V_1 * V_2 , unsigned long V_136 )
{
( void ) F_57 ( V_2 , F_65 ( V_2 , ~ 0x0eul ) | ( V_136 & 0x0f ) ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
if ( F_61 ( V_2 , V_137 ) &&
! V_2 -> V_138 ) {
F_67 ( V_139 , V_2 -> V_5 . V_140 ) ;
V_2 -> V_138 = 1 ;
}
}
static void F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_138 ) {
if ( V_2 -> V_5 . V_140 != V_141 )
F_67 ( V_139 , V_141 ) ;
V_2 -> V_138 = 0 ;
}
}
int F_69 ( struct V_1 * V_2 , T_1 V_142 , T_2 V_143 )
{
T_2 V_140 = V_143 ;
T_2 V_144 = V_2 -> V_5 . V_140 ;
T_2 V_145 ;
if ( V_142 != V_139 )
return 1 ;
if ( ! ( V_140 & V_146 ) )
return 1 ;
if ( ( V_140 & V_147 ) && ! ( V_140 & V_148 ) )
return 1 ;
V_145 = V_2 -> V_5 . V_149 | V_146 ;
if ( V_140 & ~ V_145 )
return 1 ;
if ( ( ! ( V_140 & V_150 ) ) != ( ! ( V_140 & V_151 ) ) )
return 1 ;
F_68 ( V_2 ) ;
V_2 -> V_5 . V_140 = V_140 ;
if ( ( V_140 ^ V_144 ) & V_152 )
F_70 ( V_2 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 , T_1 V_142 , T_2 V_143 )
{
if ( V_74 -> V_89 ( V_2 ) != 0 ||
F_69 ( V_2 , V_142 , V_143 ) ) {
F_34 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_72 ( struct V_1 * V_2 , unsigned long V_153 )
{
unsigned long V_154 = F_73 ( V_2 ) ;
unsigned long V_155 = V_156 | V_157 |
V_158 | V_159 ;
if ( V_153 & V_160 )
return 1 ;
if ( ! F_74 ( V_2 ) && ( V_153 & V_137 ) )
return 1 ;
if ( ! F_75 ( V_2 ) && ( V_153 & V_159 ) )
return 1 ;
if ( ! F_76 ( V_2 ) && ( V_153 & V_161 ) )
return 1 ;
if ( ! F_77 ( V_2 ) && ( V_153 & V_162 ) )
return 1 ;
if ( F_53 ( V_2 ) ) {
if ( ! ( V_153 & V_158 ) )
return 1 ;
} else if ( F_60 ( V_2 ) && ( V_153 & V_158 )
&& ( ( V_153 ^ V_154 ) & V_155 )
&& ! F_48 ( V_2 , V_2 -> V_5 . V_102 ,
F_56 ( V_2 ) ) )
return 1 ;
if ( ( V_153 & V_134 ) && ! ( V_154 & V_134 ) ) {
if ( ! F_78 ( V_2 ) )
return 1 ;
if ( ( F_56 ( V_2 ) & V_163 ) || ! F_53 ( V_2 ) )
return 1 ;
}
if ( V_74 -> V_164 ( V_2 , V_153 ) )
return 1 ;
if ( ( ( V_153 ^ V_154 ) & V_155 ) ||
( ! ( V_153 & V_134 ) && ( V_154 & V_134 ) ) )
F_63 ( V_2 ) ;
if ( ( V_153 ^ V_154 ) & V_161 )
F_79 ( V_2 , V_2 -> V_5 . V_102 , false ) ;
if ( ( V_153 ^ V_154 ) & V_137 )
F_70 ( V_2 ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , unsigned long V_103 )
{
if ( V_103 == F_56 ( V_2 ) && ! F_52 ( V_2 ) ) {
F_81 ( V_2 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
if ( F_53 ( V_2 ) ) {
if ( V_103 & V_165 )
return 1 ;
} else if ( F_54 ( V_2 ) && F_60 ( V_2 ) &&
! F_48 ( V_2 , V_2 -> V_5 . V_102 , V_103 ) )
return 1 ;
V_2 -> V_5 . V_103 = V_103 ;
F_51 ( V_166 , ( V_167 * ) & V_2 -> V_5 . V_115 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 , unsigned long V_168 )
{
if ( V_168 & V_169 )
return 1 ;
if ( F_85 ( V_2 -> V_100 ) )
F_86 ( V_2 , V_168 ) ;
else
V_2 -> V_5 . V_168 = V_168 ;
return 0 ;
}
unsigned long F_87 ( struct V_1 * V_2 )
{
if ( F_85 ( V_2 -> V_100 ) )
return F_88 ( V_2 ) ;
else
return V_2 -> V_5 . V_168 ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_170 & V_171 ) )
V_74 -> V_172 ( V_2 , V_2 -> V_5 . V_173 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
unsigned long V_174 ;
if ( V_2 -> V_170 & V_171 )
V_174 = V_2 -> V_5 . V_175 ;
else
V_174 = V_2 -> V_5 . V_174 ;
V_74 -> V_176 ( V_2 , V_174 ) ;
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
if ( F_61 ( V_2 , V_187 ) )
return 1 ;
case 6 :
if ( V_184 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_173 = ( V_184 & V_188 ) | F_91 ( V_2 ) ;
F_89 ( V_2 ) ;
break;
case 5 :
if ( F_61 ( V_2 , V_187 ) )
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
F_31 ( V_2 , V_192 ) ;
else if ( V_191 < 0 )
F_34 ( V_2 , 0 ) ;
return V_191 ;
}
static int F_95 ( struct V_1 * V_2 , int V_183 , unsigned long * V_184 )
{
switch ( V_183 ) {
case 0 ... 3 :
* V_184 = V_2 -> V_5 . V_185 [ V_183 ] ;
break;
case 4 :
if ( F_61 ( V_2 , V_187 ) )
return 1 ;
case 6 :
if ( V_2 -> V_170 & V_171 )
* V_184 = V_2 -> V_5 . V_173 ;
else
* V_184 = V_74 -> V_193 ( V_2 ) ;
break;
case 5 :
if ( F_61 ( V_2 , V_187 ) )
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
F_31 ( V_2 , V_192 ) ;
return 1 ;
}
return 0 ;
}
bool F_97 ( struct V_1 * V_2 )
{
T_1 V_194 = F_98 ( V_2 , V_195 ) ;
T_2 V_38 ;
int V_73 ;
V_73 = F_99 ( V_2 , V_194 , & V_38 ) ;
if ( V_73 )
return V_73 ;
F_100 ( V_2 , V_196 , ( T_1 ) V_38 ) ;
F_100 ( V_2 , V_197 , V_38 >> 32 ) ;
return V_73 ;
}
bool F_101 ( struct V_1 * V_2 , T_2 V_129 )
{
if ( V_129 & V_198 )
return false ;
if ( V_129 & V_199 ) {
struct V_200 * V_201 ;
V_201 = F_102 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_201 || ! ( V_201 -> V_202 & F_103 ( V_203 ) ) )
return false ;
}
if ( V_129 & V_204 ) {
struct V_200 * V_201 ;
V_201 = F_102 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_201 || ! ( V_201 -> V_194 & F_103 ( V_205 ) ) )
return false ;
}
return true ;
}
static int F_104 ( struct V_1 * V_2 , T_2 V_129 )
{
T_2 V_206 = V_2 -> V_5 . V_129 ;
if ( ! F_101 ( V_2 , V_129 ) )
return 1 ;
if ( F_60 ( V_2 )
&& ( V_2 -> V_5 . V_129 & V_130 ) != ( V_129 & V_130 ) )
return 1 ;
V_129 &= ~ V_207 ;
V_129 |= V_2 -> V_5 . V_129 & V_207 ;
V_74 -> F_104 ( V_2 , V_129 ) ;
if ( ( V_129 ^ V_206 ) & V_208 )
F_63 ( V_2 ) ;
return 0 ;
}
void F_105 ( T_2 V_28 )
{
V_198 &= ~ V_28 ;
}
int F_106 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
return V_74 -> V_209 ( V_2 , V_21 ) ;
}
static int F_107 ( struct V_1 * V_2 , unsigned V_142 , T_2 * V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = * V_38 ;
V_21 . V_142 = V_142 ;
V_21 . V_40 = true ;
return F_106 ( V_2 , & V_21 ) ;
}
static void F_108 ( struct V_210 * V_211 )
{
struct V_212 * V_213 = & V_212 ;
T_2 V_214 ;
V_214 = F_109 ( F_110 ( V_211 -> V_215 . V_216 , V_211 -> V_217 ) ) ;
F_111 ( & V_213 -> V_218 ) ;
V_213 -> clock . V_219 = V_211 -> V_215 . clock -> V_220 . V_219 ;
V_213 -> clock . V_221 = V_211 -> V_215 . V_221 ;
V_213 -> clock . V_28 = V_211 -> V_215 . V_28 ;
V_213 -> clock . V_222 = V_211 -> V_215 . V_222 ;
V_213 -> clock . V_223 = V_211 -> V_215 . V_223 ;
V_213 -> V_214 = V_214 ;
V_213 -> V_224 = V_211 -> V_215 . V_225 ;
F_112 ( & V_213 -> V_218 ) ;
}
static void F_113 ( struct V_100 * V_100 , T_6 V_226 )
{
int V_227 ;
int V_118 ;
struct V_228 V_229 ;
struct V_230 V_231 ;
if ( ! V_226 )
return;
V_118 = F_114 ( V_100 , V_226 , & V_227 , sizeof( V_227 ) ) ;
if ( V_118 )
return;
if ( V_227 & 1 )
++ V_227 ;
++ V_227 ;
F_115 ( V_100 , V_226 , & V_227 , sizeof( V_227 ) ) ;
F_116 ( & V_231 ) ;
if ( V_100 -> V_5 . V_232 ) {
struct V_230 V_233 = F_117 ( V_100 -> V_5 . V_232 ) ;
V_231 = F_118 ( V_231 , V_233 ) ;
}
V_229 . V_234 = V_231 . V_235 ;
V_229 . V_236 = V_231 . V_237 ;
V_229 . V_227 = V_227 ;
F_115 ( V_100 , V_226 , & V_229 , sizeof( V_229 ) ) ;
V_227 ++ ;
F_115 ( V_100 , V_226 , & V_227 , sizeof( V_227 ) ) ;
}
static T_7 F_119 ( T_7 V_238 , T_7 V_239 )
{
T_7 V_240 , V_241 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_240 ;
}
static void F_120 ( T_7 V_242 , T_7 V_243 ,
T_8 * V_244 , T_1 * V_245 )
{
T_9 V_246 ;
T_10 V_223 = 0 ;
T_9 V_247 ;
T_7 V_248 ;
V_247 = V_243 * 1000LL ;
V_246 = V_242 * 1000LL ;
while ( V_247 > V_246 * 2 || V_247 & 0xffffffff00000000ULL ) {
V_247 >>= 1 ;
V_223 -- ;
}
V_248 = ( T_7 ) V_247 ;
while ( V_248 <= V_246 || V_246 & 0xffffffff00000000ULL ) {
if ( V_246 & 0xffffffff00000000ULL || V_248 & 0x80000000 )
V_246 >>= 1 ;
else
V_248 <<= 1 ;
V_223 ++ ;
}
* V_244 = V_223 ;
* V_245 = F_119 ( V_246 , V_248 ) ;
F_121 ( L_2 ,
V_249 , V_243 , V_242 , V_223 , * V_245 ) ;
}
static inline T_2 F_122 ( void )
{
return F_123 () ;
}
static inline T_2 F_124 ( struct V_1 * V_2 , T_2 V_236 )
{
return F_125 ( V_236 , V_2 -> V_5 . V_250 ,
V_2 -> V_5 . V_251 ) ;
}
static T_1 F_126 ( T_1 V_252 , T_11 V_253 )
{
T_2 V_254 = ( T_2 ) V_252 * ( 1000000 + V_253 ) ;
F_127 ( V_254 , 1000000 ) ;
return V_254 ;
}
static void F_128 ( struct V_1 * V_2 , T_1 V_255 )
{
T_1 V_256 , V_257 ;
int V_258 = 0 ;
if ( V_255 == 0 )
return;
F_120 ( V_255 , V_259 / 1000 ,
& V_2 -> V_5 . V_251 ,
& V_2 -> V_5 . V_250 ) ;
V_2 -> V_5 . V_260 = V_255 ;
V_256 = F_126 ( V_261 , - V_262 ) ;
V_257 = F_126 ( V_261 , V_262 ) ;
if ( V_255 < V_256 || V_255 > V_257 ) {
F_121 ( L_3 , V_255 , V_256 , V_257 ) ;
V_258 = 1 ;
}
V_74 -> V_263 ( V_2 , V_255 , V_258 ) ;
}
static T_2 F_129 ( struct V_1 * V_2 , T_12 V_264 )
{
T_2 V_265 = F_125 ( V_264 - V_2 -> V_5 . V_266 ,
V_2 -> V_5 . V_250 ,
V_2 -> V_5 . V_251 ) ;
V_265 += V_2 -> V_5 . V_267 ;
return V_265 ;
}
void F_130 ( struct V_1 * V_2 )
{
#ifdef F_59
bool V_268 ;
bool V_269 = false ;
struct V_270 * V_271 = & V_2 -> V_100 -> V_5 ;
struct V_212 * V_272 = & V_212 ;
V_268 = ( V_271 -> V_273 + 1 ==
F_131 ( & V_2 -> V_100 -> V_274 ) ) ;
if ( V_268 && V_272 -> clock . V_219 == V_275 )
if ( ! V_271 -> V_276 )
V_269 = 1 ;
if ( ! V_268 && V_271 -> V_276 )
V_269 = 1 ;
if ( V_269 )
F_30 ( V_277 , V_2 ) ;
F_132 ( V_2 -> V_278 , V_271 -> V_273 ,
F_131 ( & V_2 -> V_100 -> V_274 ) ,
V_271 -> V_276 , V_272 -> clock . V_219 ) ;
#endif
}
static void F_133 ( struct V_1 * V_2 , T_12 V_92 )
{
T_2 V_279 = V_74 -> V_280 ( V_2 ) ;
V_2 -> V_5 . V_281 += V_92 - V_279 ;
}
void F_134 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
struct V_100 * V_100 = V_2 -> V_100 ;
T_2 V_92 , V_282 , V_283 ;
unsigned long V_284 ;
T_12 V_285 ;
bool V_286 ;
bool V_287 ;
T_2 V_38 = V_21 -> V_38 ;
F_135 ( & V_100 -> V_5 . V_288 , V_284 ) ;
V_92 = V_74 -> V_289 ( V_2 , V_38 ) ;
V_282 = F_122 () ;
V_283 = V_282 - V_100 -> V_5 . V_290 ;
if ( V_2 -> V_5 . V_260 ) {
int V_291 = 0 ;
V_285 = V_38 - V_100 -> V_5 . V_292 ;
#ifdef F_59
V_285 = ( V_285 * 1000 ) / V_2 -> V_5 . V_260 ;
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
F_127 ( V_283 , 1000 ) ;
V_285 -= V_283 ;
if ( V_285 < 0 )
V_285 = - V_285 ;
if ( V_291 )
V_285 = V_293 ;
} else
V_285 = V_293 ;
if ( V_285 < V_293 &&
V_2 -> V_5 . V_260 == V_100 -> V_5 . V_294 ) {
if ( ! F_136 () ) {
V_92 = V_100 -> V_5 . V_295 ;
F_121 ( L_4 , V_38 ) ;
} else {
T_2 V_296 = F_124 ( V_2 , V_283 ) ;
V_38 += V_296 ;
V_92 = V_74 -> V_289 ( V_2 , V_38 ) ;
F_121 ( L_5 , V_296 ) ;
}
V_286 = true ;
V_287 = ( V_2 -> V_5 . V_297 == V_100 -> V_5 . V_298 ) ;
} else {
V_100 -> V_5 . V_298 ++ ;
V_100 -> V_5 . V_299 = V_282 ;
V_100 -> V_5 . V_300 = V_38 ;
V_100 -> V_5 . V_295 = V_92 ;
V_286 = false ;
F_121 ( L_6 ,
V_100 -> V_5 . V_298 , V_38 ) ;
}
V_100 -> V_5 . V_290 = V_282 ;
V_100 -> V_5 . V_292 = V_38 ;
V_100 -> V_5 . V_294 = V_2 -> V_5 . V_260 ;
V_2 -> V_5 . V_301 = V_38 ;
V_2 -> V_5 . V_297 = V_100 -> V_5 . V_298 ;
V_2 -> V_5 . V_266 = V_100 -> V_5 . V_299 ;
V_2 -> V_5 . V_267 = V_100 -> V_5 . V_300 ;
if ( F_137 ( V_2 ) && ! V_21 -> V_40 )
F_133 ( V_2 , V_92 ) ;
V_74 -> V_302 ( V_2 , V_92 ) ;
F_138 ( & V_100 -> V_5 . V_288 , V_284 ) ;
F_139 ( & V_100 -> V_5 . V_303 ) ;
if ( ! V_286 ) {
V_100 -> V_5 . V_273 = 0 ;
} else if ( ! V_287 ) {
V_100 -> V_5 . V_273 ++ ;
}
F_130 ( V_2 ) ;
F_140 ( & V_100 -> V_5 . V_303 ) ;
}
static T_13 F_141 ( void )
{
T_13 V_107 ;
T_2 V_304 ;
F_142 () ;
V_107 = ( T_13 ) F_143 () ;
V_304 = V_212 . clock . V_221 ;
if ( F_144 ( V_107 >= V_304 ) )
return V_107 ;
asm volatile ("");
return V_304 ;
}
static inline T_2 F_145 ( T_13 * V_305 )
{
long V_254 ;
struct V_212 * V_272 = & V_212 ;
* V_305 = F_141 () ;
V_254 = ( * V_305 - V_272 -> clock . V_221 ) & V_272 -> clock . V_28 ;
return V_254 * V_272 -> clock . V_222 ;
}
static int F_146 ( T_12 * V_306 , T_13 * V_305 )
{
struct V_212 * V_272 = & V_212 ;
unsigned long V_218 ;
int V_307 ;
T_2 V_282 ;
do {
V_218 = F_147 ( & V_272 -> V_218 ) ;
V_307 = V_272 -> clock . V_219 ;
V_282 = V_272 -> V_224 ;
V_282 += F_145 ( V_305 ) ;
V_282 >>= V_272 -> clock . V_223 ;
V_282 += V_272 -> V_214 ;
} while ( F_148 ( F_149 ( & V_272 -> V_218 , V_218 ) ) );
* V_306 = V_282 ;
return V_307 ;
}
static bool F_150 ( T_12 * V_264 , T_13 * V_305 )
{
if ( V_212 . clock . V_219 != V_275 )
return false ;
return F_146 ( V_264 , V_305 ) == V_275 ;
}
static void F_151 ( struct V_100 * V_100 )
{
#ifdef F_59
struct V_270 * V_271 = & V_100 -> V_5 ;
int V_219 ;
bool V_308 , V_268 ;
V_268 = ( V_271 -> V_273 + 1 ==
F_131 ( & V_100 -> V_274 ) ) ;
V_308 = F_150 (
& V_271 -> V_309 ,
& V_271 -> V_310 ) ;
V_271 -> V_276 = V_308 && V_268
&& ! V_311 ;
if ( V_271 -> V_276 )
F_152 ( & V_312 , 1 ) ;
V_219 = V_212 . clock . V_219 ;
F_153 ( V_271 -> V_276 , V_219 ,
V_268 ) ;
#endif
}
static void F_154 ( struct V_100 * V_100 )
{
#ifdef F_59
int V_3 ;
struct V_1 * V_2 ;
struct V_270 * V_271 = & V_100 -> V_5 ;
F_139 ( & V_271 -> V_303 ) ;
F_155 ( V_100 ) ;
F_151 ( V_100 ) ;
F_156 (i, vcpu, kvm)
F_157 ( V_313 , & V_2 -> V_314 ) ;
F_156 (i, vcpu, kvm)
F_158 ( V_315 , & V_2 -> V_314 ) ;
F_140 ( & V_271 -> V_303 ) ;
#endif
}
static int F_159 ( struct V_1 * V_254 )
{
unsigned long V_284 , V_255 ;
struct V_316 * V_2 = & V_254 -> V_5 ;
struct V_270 * V_271 = & V_254 -> V_100 -> V_5 ;
T_12 V_264 ;
T_2 V_317 , V_318 ;
struct V_319 V_320 ;
T_14 V_321 ;
bool V_276 ;
V_264 = 0 ;
V_318 = 0 ;
F_139 ( & V_271 -> V_303 ) ;
V_276 = V_271 -> V_276 ;
if ( V_276 ) {
V_318 = V_271 -> V_310 ;
V_264 = V_271 -> V_309 ;
}
F_140 ( & V_271 -> V_303 ) ;
F_160 ( V_284 ) ;
V_255 = F_161 ( V_322 ) ;
if ( F_148 ( V_255 == 0 ) ) {
F_162 ( V_284 ) ;
F_30 ( V_313 , V_254 ) ;
return 1 ;
}
if ( ! V_276 ) {
V_318 = F_163 () ;
V_264 = F_122 () ;
}
V_317 = V_74 -> V_323 ( V_254 , V_318 ) ;
if ( V_2 -> V_324 ) {
T_2 V_265 = F_129 ( V_254 , V_264 ) ;
if ( V_265 > V_317 ) {
F_164 ( V_254 , V_265 - V_317 ) ;
V_317 = V_265 ;
}
}
F_162 ( V_284 ) ;
if ( ! V_2 -> V_325 )
return 0 ;
if ( F_148 ( V_2 -> V_326 != V_255 ) ) {
F_120 ( V_259 / 1000 , V_255 ,
& V_2 -> V_327 . V_328 ,
& V_2 -> V_327 . V_329 ) ;
V_2 -> V_326 = V_255 ;
}
V_2 -> V_327 . V_317 = V_317 ;
V_2 -> V_327 . V_330 = V_264 + V_254 -> V_100 -> V_5 . V_232 ;
V_2 -> V_301 = V_317 ;
V_2 -> V_327 . V_227 += 2 ;
if ( F_148 ( F_165 ( V_254 -> V_100 , & V_2 -> V_331 ,
& V_320 , sizeof( V_320 ) ) ) )
return 0 ;
V_321 = ( V_320 . V_284 & V_332 ) ;
if ( V_2 -> V_333 ) {
V_321 |= V_332 ;
V_2 -> V_333 = false ;
}
if ( V_276 )
V_321 |= V_334 ;
V_2 -> V_327 . V_284 = V_321 ;
F_166 ( V_254 -> V_100 , & V_2 -> V_331 ,
& V_2 -> V_327 ,
sizeof( V_2 -> V_327 ) ) ;
return 0 ;
}
static void F_167 ( struct V_335 * V_336 )
{
int V_3 ;
struct V_337 * V_338 = F_168 ( V_336 ) ;
struct V_270 * V_271 = F_4 ( V_338 , struct V_270 ,
V_339 ) ;
struct V_100 * V_100 = F_4 ( V_271 , struct V_100 , V_5 ) ;
struct V_1 * V_2 ;
F_156 (i, vcpu, kvm) {
F_157 ( V_313 , & V_2 -> V_314 ) ;
F_169 ( V_2 ) ;
}
}
static void F_170 ( struct V_1 * V_254 )
{
struct V_100 * V_100 = V_254 -> V_100 ;
F_157 ( V_313 , & V_254 -> V_314 ) ;
F_171 ( & V_100 -> V_5 . V_339 ,
V_340 ) ;
}
static void F_172 ( struct V_335 * V_336 )
{
struct V_337 * V_338 = F_168 ( V_336 ) ;
struct V_270 * V_271 = F_4 ( V_338 , struct V_270 ,
V_341 ) ;
struct V_100 * V_100 = F_4 ( V_271 , struct V_100 , V_5 ) ;
F_171 ( & V_100 -> V_5 . V_339 , 0 ) ;
F_171 ( & V_100 -> V_5 . V_341 ,
V_342 ) ;
}
static bool F_173 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_343 - 1 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_174 ( unsigned V_306 )
{
return V_306 < 8 && ( 1 << V_306 ) & 0xf3 ;
}
static bool F_175 ( unsigned V_306 )
{
return V_306 < 8 && ( 1 << V_306 ) & 0x73 ;
}
static bool F_176 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
int V_3 ;
if ( ! F_173 ( V_21 ) )
return false ;
if ( V_21 == V_356 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_174 ( ( V_38 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_355 ) {
if ( V_38 & ~ 0xcff )
return false ;
return F_175 ( V_38 & 0xff ) ;
} else if ( V_21 >= V_344 && V_21 <= V_354 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_175 ( ( V_38 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_175 ( V_38 & 0xff ) ;
}
static int F_177 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 * V_357 = ( T_2 * ) & V_2 -> V_5 . V_358 . V_359 ;
if ( ! F_176 ( V_2 , V_21 , V_38 ) )
return 1 ;
if ( V_21 == V_355 ) {
V_2 -> V_5 . V_358 . V_360 = V_38 ;
V_2 -> V_5 . V_358 . V_361 = ( V_38 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_344 )
V_357 [ 0 ] = V_38 ;
else if ( V_21 == V_345 || V_21 == V_346 )
V_357 [ 1 + V_21 - V_345 ] = V_38 ;
else if ( V_21 >= V_347 && V_21 <= V_354 )
V_357 [ 3 + V_21 - V_347 ] = V_38 ;
else if ( V_21 == V_356 )
V_2 -> V_5 . V_362 = V_38 ;
else {
int V_363 , V_364 ;
T_2 * V_365 ;
V_363 = ( V_21 - 0x200 ) / 2 ;
V_364 = V_21 - 0x200 - 2 * V_363 ;
if ( ! V_364 )
V_365 =
( T_2 * ) & V_2 -> V_5 . V_358 . V_366 [ V_363 ] . V_367 ;
else
V_365 =
( T_2 * ) & V_2 -> V_5 . V_358 . V_366 [ V_363 ] . V_368 ;
* V_365 = V_38 ;
}
F_63 ( V_2 ) ;
return 0 ;
}
static int F_178 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 V_369 = V_2 -> V_5 . V_369 ;
unsigned V_370 = V_369 & 0xff ;
switch ( V_21 ) {
case V_371 :
V_2 -> V_5 . V_372 = V_38 ;
break;
case V_373 :
if ( ! ( V_369 & V_374 ) )
return 1 ;
if ( V_38 != 0 && V_38 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_375 = V_38 ;
break;
default:
if ( V_21 >= V_376 &&
V_21 < V_376 + 4 * V_370 ) {
T_1 V_92 = V_21 - V_376 ;
if ( ( V_92 & 0x3 ) == 0 &&
V_38 != 0 && ( V_38 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_377 [ V_92 ] = V_38 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_179 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_100 * V_100 = V_2 -> V_100 ;
int V_378 = F_53 ( V_2 ) ;
T_14 * V_379 = V_378 ? ( T_14 * ) ( long ) V_100 -> V_5 . F_179 . V_380
: ( T_14 * ) ( long ) V_100 -> V_5 . F_179 . V_381 ;
T_14 V_382 = V_378 ? V_100 -> V_5 . F_179 . V_383
: V_100 -> V_5 . F_179 . V_384 ;
T_1 V_385 = V_38 & ~ V_386 ;
T_2 V_387 = V_38 & V_386 ;
T_14 * V_388 ;
int V_118 ;
V_118 = - V_389 ;
if ( V_385 >= V_382 )
goto V_112;
V_118 = - V_390 ;
V_388 = F_180 ( V_379 + ( V_385 * V_106 ) , V_106 ) ;
if ( F_181 ( V_388 ) ) {
V_118 = F_182 ( V_388 ) ;
goto V_112;
}
if ( F_115 ( V_100 , V_387 , V_388 , V_106 ) )
goto V_391;
V_118 = 0 ;
V_391:
F_183 ( V_388 ) ;
V_112:
return V_118 ;
}
static bool F_184 ( struct V_100 * V_100 )
{
return V_100 -> V_5 . V_392 & V_393 ;
}
static bool F_185 ( T_1 V_21 )
{
bool V_118 = false ;
switch ( V_21 ) {
case V_394 :
case V_395 :
case V_396 :
case V_397 :
V_118 = true ;
break;
}
return V_118 ;
}
static int F_186 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
struct V_100 * V_100 = V_2 -> V_100 ;
switch ( V_21 ) {
case V_394 :
V_100 -> V_5 . V_398 = V_38 ;
if ( ! V_100 -> V_5 . V_398 )
V_100 -> V_5 . V_392 &= ~ V_393 ;
break;
case V_395 : {
T_2 V_101 ;
unsigned long V_399 ;
T_14 V_400 [ 4 ] ;
if ( ! V_100 -> V_5 . V_398 )
break;
if ( ! ( V_38 & V_393 ) ) {
V_100 -> V_5 . V_392 = V_38 ;
break;
}
V_101 = V_38 >> V_401 ;
V_399 = F_187 ( V_100 , V_101 ) ;
if ( F_188 ( V_399 ) )
return 1 ;
V_74 -> V_402 ( V_2 , V_400 ) ;
( ( unsigned char * ) V_400 ) [ 3 ] = 0xc3 ;
if ( F_189 ( ( void V_403 * ) V_399 , V_400 , 4 ) )
return 1 ;
V_100 -> V_5 . V_392 = V_38 ;
F_190 ( V_100 , V_101 ) ;
break;
}
case V_396 : {
T_2 V_101 ;
T_15 V_404 ;
memset ( & V_404 , 0 , sizeof( V_404 ) ) ;
V_100 -> V_5 . V_405 = V_38 ;
if ( ! ( V_38 & V_406 ) )
break;
V_101 = V_38 >> V_407 ;
if ( F_115 ( V_100 , V_101 << V_407 ,
& V_404 , sizeof( V_404 ) ) )
return 1 ;
F_190 ( V_100 , V_101 ) ;
break;
}
default:
F_191 ( V_2 , L_7
L_8 , V_21 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_192 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
switch ( V_21 ) {
case V_408 : {
T_2 V_101 ;
unsigned long V_399 ;
if ( ! ( V_38 & V_409 ) ) {
V_2 -> V_5 . V_410 = V_38 ;
if ( F_193 ( V_2 , 0 ) )
return 1 ;
break;
}
V_101 = V_38 >> V_411 ;
V_399 = F_187 ( V_2 -> V_100 , V_101 ) ;
if ( F_188 ( V_399 ) )
return 1 ;
if ( F_194 ( ( void V_403 * ) V_399 , V_106 ) )
return 1 ;
V_2 -> V_5 . V_410 = V_38 ;
F_190 ( V_2 -> V_100 , V_101 ) ;
if ( F_193 ( V_2 , F_44 ( V_101 ) | V_412 ) )
return 1 ;
break;
}
case V_413 :
return F_195 ( V_2 , V_414 , V_38 ) ;
case V_415 :
return F_195 ( V_2 , V_416 , V_38 ) ;
case V_417 :
return F_195 ( V_2 , V_418 , V_38 ) ;
default:
F_191 ( V_2 , L_7
L_8 , V_21 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_196 ( struct V_1 * V_2 , T_2 V_38 )
{
T_6 V_419 = V_38 & ~ 0x3f ;
if ( V_38 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_420 = V_38 ;
if ( ! ( V_38 & V_421 ) ) {
F_62 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_197 ( V_2 -> V_100 , & V_2 -> V_5 . V_6 . V_38 , V_419 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_422 = ! ( V_38 & V_423 ) ;
F_198 ( V_2 ) ;
return 0 ;
}
static void F_199 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_325 = false ;
}
static void F_200 ( struct V_1 * V_2 )
{
T_2 V_296 ;
if ( ! ( V_2 -> V_5 . V_424 . V_420 & V_412 ) )
return;
V_296 = V_425 -> V_426 . V_427 - V_2 -> V_5 . V_424 . V_428 ;
V_2 -> V_5 . V_424 . V_428 = V_425 -> V_426 . V_427 ;
V_2 -> V_5 . V_424 . V_429 = V_296 ;
}
static void F_201 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_424 . V_420 & V_412 ) )
return;
if ( F_148 ( F_165 ( V_2 -> V_100 , & V_2 -> V_5 . V_424 . V_430 ,
& V_2 -> V_5 . V_424 . V_431 , sizeof( struct V_432 ) ) ) )
return;
V_2 -> V_5 . V_424 . V_431 . V_431 += V_2 -> V_5 . V_424 . V_429 ;
V_2 -> V_5 . V_424 . V_431 . V_227 += 2 ;
V_2 -> V_5 . V_424 . V_429 = 0 ;
F_166 ( V_2 -> V_100 , & V_2 -> V_5 . V_424 . V_430 ,
& V_2 -> V_5 . V_424 . V_431 , sizeof( struct V_432 ) ) ;
}
int F_202 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
bool V_433 = false ;
T_1 V_21 = V_33 -> V_142 ;
T_2 V_38 = V_33 -> V_38 ;
switch ( V_21 ) {
case V_434 :
case V_435 :
case V_436 :
case V_437 :
case V_438 :
case V_439 :
break;
case V_440 :
return F_104 ( V_2 , V_38 ) ;
case V_441 :
V_38 &= ~ ( T_2 ) 0x40 ;
V_38 &= ~ ( T_2 ) 0x100 ;
V_38 &= ~ ( T_2 ) 0x8 ;
V_38 &= ~ ( T_2 ) 0x40000 ;
if ( V_38 != 0 ) {
F_191 ( V_2 , L_9 ,
V_38 ) ;
return 1 ;
}
break;
case V_442 :
if ( V_38 != 0 ) {
F_191 ( V_2 , L_10
L_11 , V_38 ) ;
return 1 ;
}
break;
case V_443 :
if ( ! V_38 ) {
break;
} else if ( V_38 & ~ ( V_444 | V_445 ) ) {
return 1 ;
}
F_191 ( V_2 , L_12 ,
V_249 , V_38 ) ;
break;
case 0x200 ... 0x2ff :
return F_177 ( V_2 , V_21 , V_38 ) ;
case V_446 :
return F_20 ( V_2 , V_33 ) ;
case V_447 ... V_447 + 0x3ff :
return F_203 ( V_2 , V_21 , V_38 ) ;
case V_448 :
F_204 ( V_2 , V_38 ) ;
break;
case V_449 :
if ( F_137 ( V_2 ) ) {
if ( ! V_33 -> V_40 ) {
T_2 V_450 = V_38 - V_2 -> V_5 . V_281 ;
V_74 -> V_451 ( V_2 , V_450 , true ) ;
}
V_2 -> V_5 . V_281 = V_38 ;
}
break;
case V_452 :
V_2 -> V_5 . V_453 = V_38 ;
break;
case V_454 :
case V_455 :
V_2 -> V_100 -> V_5 . V_226 = V_38 ;
F_113 ( V_2 -> V_100 , V_38 ) ;
break;
case V_456 :
case V_457 : {
T_2 V_458 ;
F_199 ( V_2 ) ;
V_2 -> V_5 . time = V_38 ;
F_30 ( V_459 , V_2 ) ;
if ( ! ( V_38 & 1 ) )
break;
V_458 = V_38 & ~ ( V_386 | 1 ) ;
if ( F_197 ( V_2 -> V_100 ,
& V_2 -> V_5 . V_331 , V_38 & ~ 1ULL ,
sizeof( struct V_319 ) ) )
V_2 -> V_5 . V_325 = false ;
else
V_2 -> V_5 . V_325 = true ;
break;
}
case V_460 :
if ( F_196 ( V_2 , V_38 ) )
return 1 ;
break;
case V_461 :
if ( F_148 ( ! F_205 () ) )
return 1 ;
if ( V_38 & V_462 )
return 1 ;
if ( F_197 ( V_2 -> V_100 , & V_2 -> V_5 . V_424 . V_430 ,
V_38 & V_463 ,
sizeof( struct V_432 ) ) )
return 1 ;
V_2 -> V_5 . V_424 . V_420 = V_38 ;
if ( ! ( V_38 & V_412 ) )
break;
V_2 -> V_5 . V_424 . V_428 = V_425 -> V_426 . V_427 ;
F_206 () ;
F_200 ( V_2 ) ;
F_207 () ;
F_30 ( V_464 , V_2 ) ;
break;
case V_465 :
if ( F_193 ( V_2 , V_38 ) )
return 1 ;
break;
case V_373 :
case V_371 :
case V_376 ... V_376 + 4 * V_466 - 1 :
return F_178 ( V_2 , V_21 , V_38 ) ;
case V_467 :
case V_468 :
case V_469 :
case V_470 :
if ( V_38 != 0 )
F_191 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_471 :
case V_472 :
case V_473 :
case V_474 :
F_191 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_475 :
case V_476 :
V_433 = true ;
case V_477 :
case V_478 :
if ( F_208 ( V_2 , V_21 ) )
return F_209 ( V_2 , V_33 ) ;
if ( V_433 || V_38 != 0 )
F_191 ( V_2 , L_15
L_14 , V_21 , V_38 ) ;
break;
case V_479 :
break;
case V_394 ... V_480 :
if ( F_185 ( V_21 ) ) {
int V_118 ;
F_210 ( & V_2 -> V_100 -> V_481 ) ;
V_118 = F_186 ( V_2 , V_21 , V_38 ) ;
F_211 ( & V_2 -> V_100 -> V_481 ) ;
return V_118 ;
} else
return F_192 ( V_2 , V_21 , V_38 ) ;
break;
case V_482 :
F_191 ( V_2 , L_16 , V_21 , V_38 ) ;
break;
case V_483 :
if ( ! F_212 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_484 . V_485 = V_38 ;
break;
case V_486 :
if ( ! F_212 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_484 . V_487 = V_38 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_100 -> V_5 . F_179 . V_21 ) )
return F_179 ( V_2 , V_38 ) ;
if ( F_208 ( V_2 , V_21 ) )
return F_209 ( V_2 , V_33 ) ;
if ( ! V_488 ) {
F_191 ( V_2 , L_17 ,
V_21 , V_38 ) ;
return 1 ;
} else {
F_191 ( V_2 , L_16 ,
V_21 , V_38 ) ;
break;
}
}
return 0 ;
}
int F_213 ( struct V_1 * V_2 , T_1 V_489 , T_2 * V_490 )
{
return V_74 -> V_491 ( V_2 , V_489 , V_490 ) ;
}
static int F_214 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_490 )
{
T_2 * V_357 = ( T_2 * ) & V_2 -> V_5 . V_358 . V_359 ;
if ( ! F_173 ( V_21 ) )
return 1 ;
if ( V_21 == V_355 )
* V_490 = V_2 -> V_5 . V_358 . V_360 +
( V_2 -> V_5 . V_358 . V_361 << 10 ) ;
else if ( V_21 == V_344 )
* V_490 = V_357 [ 0 ] ;
else if ( V_21 == V_345 || V_21 == V_346 )
* V_490 = V_357 [ 1 + V_21 - V_345 ] ;
else if ( V_21 >= V_347 && V_21 <= V_354 )
* V_490 = V_357 [ 3 + V_21 - V_347 ] ;
else if ( V_21 == V_356 )
* V_490 = V_2 -> V_5 . V_362 ;
else {
int V_363 , V_364 ;
T_2 * V_365 ;
V_363 = ( V_21 - 0x200 ) / 2 ;
V_364 = V_21 - 0x200 - 2 * V_363 ;
if ( ! V_364 )
V_365 =
( T_2 * ) & V_2 -> V_5 . V_358 . V_366 [ V_363 ] . V_367 ;
else
V_365 =
( T_2 * ) & V_2 -> V_5 . V_358 . V_366 [ V_363 ] . V_368 ;
* V_490 = * V_365 ;
}
return 0 ;
}
static int F_215 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_490 )
{
T_2 V_38 ;
T_2 V_369 = V_2 -> V_5 . V_369 ;
unsigned V_370 = V_369 & 0xff ;
switch ( V_21 ) {
case V_492 :
case V_493 :
V_38 = 0 ;
break;
case V_494 :
V_38 = V_2 -> V_5 . V_369 ;
break;
case V_373 :
if ( ! ( V_369 & V_374 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_375 ;
break;
case V_371 :
V_38 = V_2 -> V_5 . V_372 ;
break;
default:
if ( V_21 >= V_376 &&
V_21 < V_376 + 4 * V_370 ) {
T_1 V_92 = V_21 - V_376 ;
V_38 = V_2 -> V_5 . V_377 [ V_92 ] ;
break;
}
return 1 ;
}
* V_490 = V_38 ;
return 0 ;
}
static int F_216 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_490 )
{
T_2 V_38 = 0 ;
struct V_100 * V_100 = V_2 -> V_100 ;
switch ( V_21 ) {
case V_394 :
V_38 = V_100 -> V_5 . V_398 ;
break;
case V_395 :
V_38 = V_100 -> V_5 . V_392 ;
break;
case V_397 : {
V_38 =
F_217 ( F_122 () + V_100 -> V_5 . V_232 , 100 ) ;
break;
}
case V_396 :
V_38 = V_100 -> V_5 . V_405 ;
break;
default:
F_191 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_490 = V_38 ;
return 0 ;
}
static int F_218 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_490 )
{
T_2 V_38 = 0 ;
switch ( V_21 ) {
case V_495 : {
int V_118 ;
struct V_1 * V_254 ;
F_156 (r, v, vcpu->kvm) {
if ( V_254 == V_2 ) {
V_38 = V_118 ;
break;
}
}
break;
}
case V_413 :
return F_219 ( V_2 , V_414 , V_490 ) ;
case V_415 :
return F_219 ( V_2 , V_416 , V_490 ) ;
case V_417 :
return F_219 ( V_2 , V_418 , V_490 ) ;
case V_408 :
V_38 = V_2 -> V_5 . V_410 ;
break;
default:
F_191 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_490 = V_38 ;
return 0 ;
}
int F_220 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_490 )
{
T_2 V_38 ;
switch ( V_21 ) {
case V_496 :
case V_497 :
case V_443 :
case V_498 :
case V_499 :
case V_500 :
case V_501 :
case V_502 :
case V_441 :
case V_437 :
case V_467 :
case V_471 :
case V_503 :
case V_434 :
case V_442 :
case V_439 :
V_38 = 0 ;
break;
case V_475 :
case V_476 :
case V_477 :
case V_478 :
if ( F_208 ( V_2 , V_21 ) )
return F_221 ( V_2 , V_21 , V_490 ) ;
V_38 = 0 ;
break;
case V_435 :
V_38 = 0x100000000ULL ;
break;
case V_504 :
V_38 = 0x500 | V_343 ;
break;
case 0x200 ... 0x2ff :
return F_214 ( V_2 , V_21 , V_490 ) ;
case 0xcd :
V_38 = 3 ;
break;
case V_505 :
V_38 = 1 << 24 ;
break;
case V_446 :
V_38 = F_19 ( V_2 ) ;
break;
case V_447 ... V_447 + 0x3ff :
return F_222 ( V_2 , V_21 , V_490 ) ;
break;
case V_448 :
V_38 = F_223 ( V_2 ) ;
break;
case V_449 :
V_38 = ( T_2 ) V_2 -> V_5 . V_281 ;
break;
case V_452 :
V_38 = V_2 -> V_5 . V_453 ;
break;
case V_506 :
V_38 = 1000ULL ;
V_38 |= ( ( ( T_9 ) 4ULL ) << 40 ) ;
break;
case V_440 :
V_38 = V_2 -> V_5 . V_129 ;
break;
case V_455 :
case V_454 :
V_38 = V_2 -> V_100 -> V_5 . V_226 ;
break;
case V_457 :
case V_456 :
V_38 = V_2 -> V_5 . time ;
break;
case V_460 :
V_38 = V_2 -> V_5 . V_6 . V_420 ;
break;
case V_461 :
V_38 = V_2 -> V_5 . V_424 . V_420 ;
break;
case V_465 :
V_38 = V_2 -> V_5 . V_507 . V_420 ;
break;
case V_492 :
case V_493 :
case V_494 :
case V_373 :
case V_371 :
case V_376 ... V_376 + 4 * V_466 - 1 :
return F_215 ( V_2 , V_21 , V_490 ) ;
case V_479 :
V_38 = 0x20000000 ;
break;
case V_394 ... V_480 :
if ( F_185 ( V_21 ) ) {
int V_118 ;
F_210 ( & V_2 -> V_100 -> V_481 ) ;
V_118 = F_216 ( V_2 , V_21 , V_490 ) ;
F_211 ( & V_2 -> V_100 -> V_481 ) ;
return V_118 ;
} else
return F_218 ( V_2 , V_21 , V_490 ) ;
break;
case V_482 :
V_38 = 0xbe702111 ;
break;
case V_483 :
if ( ! F_212 ( V_2 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_484 . V_485 ;
break;
case V_486 :
if ( ! F_212 ( V_2 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_484 . V_487 ;
break;
default:
if ( F_208 ( V_2 , V_21 ) )
return F_221 ( V_2 , V_21 , V_490 ) ;
if ( ! V_488 ) {
F_191 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_191 ( V_2 , L_20 , V_21 ) ;
V_38 = 0 ;
}
break;
}
* V_490 = V_38 ;
return 0 ;
}
static int F_224 ( struct V_1 * V_2 , struct V_508 * V_19 ,
struct V_509 * V_510 ,
int (* F_225)( struct V_1 * V_2 ,
unsigned V_142 , T_2 * V_38 ) )
{
int V_3 , V_363 ;
V_363 = F_226 ( & V_2 -> V_100 -> V_511 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_512 ; ++ V_3 )
if ( F_225 ( V_2 , V_510 [ V_3 ] . V_142 , & V_510 [ V_3 ] . V_38 ) )
break;
F_227 ( & V_2 -> V_100 -> V_511 , V_363 ) ;
return V_3 ;
}
static int F_228 ( struct V_1 * V_2 , struct V_508 V_403 * V_513 ,
int (* F_225)( struct V_1 * V_2 ,
unsigned V_142 , T_2 * V_38 ) ,
int V_514 )
{
struct V_508 V_19 ;
struct V_509 * V_510 ;
int V_118 , V_515 ;
unsigned V_516 ;
V_118 = - V_99 ;
if ( F_229 ( & V_19 , V_513 , sizeof V_19 ) )
goto V_112;
V_118 = - V_389 ;
if ( V_19 . V_512 >= V_517 )
goto V_112;
V_516 = sizeof( struct V_509 ) * V_19 . V_512 ;
V_510 = F_180 ( V_513 -> V_510 , V_516 ) ;
if ( F_181 ( V_510 ) ) {
V_118 = F_182 ( V_510 ) ;
goto V_112;
}
V_118 = V_515 = F_224 ( V_2 , & V_19 , V_510 , F_225 ) ;
if ( V_118 < 0 )
goto V_391;
V_118 = - V_99 ;
if ( V_514 && F_230 ( V_513 -> V_510 , V_510 , V_516 ) )
goto V_391;
V_118 = V_515 ;
V_391:
F_183 ( V_510 ) ;
V_112:
return V_118 ;
}
int F_231 ( struct V_100 * V_100 , long V_518 )
{
int V_118 ;
switch ( V_518 ) {
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
#ifdef F_232
case V_555 :
case V_556 :
#endif
V_118 = 1 ;
break;
case V_557 :
V_118 = V_558 ;
break;
case V_559 :
V_118 = ! V_74 -> V_560 () ;
break;
case V_561 :
V_118 = V_562 ;
break;
case V_563 :
V_118 = V_564 ;
break;
case V_565 :
V_118 = V_566 ;
break;
case V_567 :
V_118 = 0 ;
break;
#ifdef F_232
case V_568 :
V_118 = F_233 ( & V_569 ) ;
break;
#endif
case V_570 :
V_118 = V_466 ;
break;
case V_571 :
V_118 = V_572 ;
break;
case V_573 :
V_118 = V_574 ;
break;
case V_575 :
V_118 = F_234 ( V_576 ) ;
break;
default:
V_118 = 0 ;
break;
}
return V_118 ;
}
long F_235 ( struct V_577 * V_578 ,
unsigned int V_579 , unsigned long V_580 )
{
void V_403 * V_581 = ( void V_403 * ) V_580 ;
long V_118 ;
switch ( V_579 ) {
case V_582 : {
struct V_583 V_403 * V_584 = V_581 ;
struct V_583 V_585 ;
unsigned V_515 ;
V_118 = - V_99 ;
if ( F_229 ( & V_585 , V_584 , sizeof V_585 ) )
goto V_112;
V_515 = V_585 . V_512 ;
V_585 . V_512 = V_586 + F_49 ( V_587 ) ;
if ( F_230 ( V_584 , & V_585 , sizeof V_585 ) )
goto V_112;
V_118 = - V_389 ;
if ( V_515 < V_585 . V_512 )
goto V_112;
V_118 = - V_99 ;
if ( F_230 ( V_584 -> V_588 , & V_589 ,
V_586 * sizeof( T_1 ) ) )
goto V_112;
if ( F_230 ( V_584 -> V_588 + V_586 ,
& V_587 ,
F_49 ( V_587 ) * sizeof( T_1 ) ) )
goto V_112;
V_118 = 0 ;
break;
}
case V_590 :
case V_591 : {
struct V_592 V_403 * V_593 = V_581 ;
struct V_592 V_594 ;
V_118 = - V_99 ;
if ( F_229 ( & V_594 , V_593 , sizeof V_594 ) )
goto V_112;
V_118 = F_236 ( & V_594 , V_593 -> V_510 ,
V_579 ) ;
if ( V_118 )
goto V_112;
V_118 = - V_99 ;
if ( F_230 ( V_593 , & V_594 , sizeof V_594 ) )
goto V_112;
V_118 = 0 ;
break;
}
case V_595 : {
T_2 V_596 ;
V_596 = V_597 ;
V_118 = - V_99 ;
if ( F_230 ( V_581 , & V_596 , sizeof V_596 ) )
goto V_112;
V_118 = 0 ;
break;
}
default:
V_118 = - V_598 ;
}
V_112:
return V_118 ;
}
static void F_237 ( void * V_599 )
{
F_238 () ;
}
static bool F_239 ( struct V_1 * V_2 )
{
return F_240 ( V_2 -> V_100 ) ;
}
void F_241 ( struct V_1 * V_2 , int V_23 )
{
if ( F_239 ( V_2 ) ) {
if ( V_74 -> V_600 () )
F_242 ( V_23 , V_2 -> V_5 . V_601 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_243 ( V_2 -> V_23 ,
F_237 , NULL , 1 ) ;
}
V_74 -> V_602 ( V_2 , V_23 ) ;
if ( F_148 ( V_2 -> V_5 . V_603 ) ) {
F_244 ( V_2 , V_2 -> V_5 . V_603 ) ;
V_2 -> V_5 . V_603 = 0 ;
F_157 ( V_313 , & V_2 -> V_314 ) ;
}
if ( F_148 ( V_2 -> V_23 != V_23 ) || F_136 () ) {
T_12 V_604 = ! V_2 -> V_5 . V_605 ? 0 :
F_163 () - V_2 -> V_5 . V_605 ;
if ( V_604 < 0 )
F_245 ( L_21 ) ;
if ( F_136 () ) {
T_2 V_92 = V_74 -> V_289 ( V_2 ,
V_2 -> V_5 . V_301 ) ;
V_74 -> V_302 ( V_2 , V_92 ) ;
V_2 -> V_5 . V_324 = 1 ;
}
if ( ! V_2 -> V_100 -> V_5 . V_276 || V_2 -> V_23 == - 1 )
F_30 ( V_459 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_246 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_200 ( V_2 ) ;
F_30 ( V_464 , V_2 ) ;
}
void F_247 ( struct V_1 * V_2 )
{
V_74 -> V_606 ( V_2 ) ;
F_248 ( V_2 ) ;
V_2 -> V_5 . V_605 = F_163 () ;
}
static int F_249 ( struct V_1 * V_2 ,
struct V_607 * V_608 )
{
V_74 -> V_609 ( V_2 ) ;
memcpy ( V_608 -> V_610 , V_2 -> V_5 . V_611 -> V_610 , sizeof *V_608 ) ;
return 0 ;
}
static int F_250 ( struct V_1 * V_2 ,
struct V_607 * V_608 )
{
F_251 ( V_2 , V_608 ) ;
F_252 ( V_2 ) ;
return 0 ;
}
static int F_253 ( struct V_1 * V_2 ,
struct V_612 * V_613 )
{
if ( V_613 -> V_613 >= V_614 )
return - V_598 ;
if ( F_85 ( V_2 -> V_100 ) )
return - V_615 ;
F_254 ( V_2 , V_613 -> V_613 , false ) ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
static int F_255 ( struct V_1 * V_2 )
{
F_39 ( V_2 ) ;
return 0 ;
}
static int F_256 ( struct V_1 * V_2 ,
struct V_616 * V_617 )
{
if ( V_617 -> V_284 )
return - V_598 ;
V_2 -> V_5 . V_618 = ! ! V_617 -> V_361 ;
return 0 ;
}
static int F_257 ( struct V_1 * V_2 ,
T_2 V_369 )
{
int V_118 ;
unsigned V_370 = V_369 & 0xff , V_619 ;
V_118 = - V_598 ;
if ( ! V_370 || V_370 >= V_466 )
goto V_112;
if ( V_369 & ~ ( V_597 | 0xff | 0xff0000 ) )
goto V_112;
V_118 = 0 ;
V_2 -> V_5 . V_369 = V_369 ;
if ( V_369 & V_374 )
V_2 -> V_5 . V_375 = ~ ( T_2 ) 0 ;
for ( V_619 = 0 ; V_619 < V_370 ; V_619 ++ )
V_2 -> V_5 . V_377 [ V_619 * 4 ] = ~ ( T_2 ) 0 ;
V_112:
return V_118 ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_620 * V_621 )
{
T_2 V_369 = V_2 -> V_5 . V_369 ;
unsigned V_370 = V_369 & 0xff ;
T_2 * V_622 = V_2 -> V_5 . V_377 ;
if ( V_621 -> V_619 >= V_370 || ! ( V_621 -> V_487 & V_623 ) )
return - V_598 ;
if ( ( V_621 -> V_487 & V_624 ) && ( V_369 & V_374 ) &&
V_2 -> V_5 . V_375 != ~ ( T_2 ) 0 )
return 0 ;
V_622 += 4 * V_621 -> V_619 ;
if ( ( V_621 -> V_487 & V_624 ) && V_622 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_621 -> V_487 & V_624 ) {
if ( ( V_2 -> V_5 . V_372 & V_625 ) ||
! F_61 ( V_2 , V_626 ) ) {
F_30 ( V_72 , V_2 ) ;
return 0 ;
}
if ( V_622 [ 1 ] & V_623 )
V_621 -> V_487 |= V_627 ;
V_622 [ 2 ] = V_621 -> V_399 ;
V_622 [ 3 ] = V_621 -> V_628 ;
V_2 -> V_5 . V_372 = V_621 -> V_372 ;
V_622 [ 1 ] = V_621 -> V_487 ;
F_31 ( V_2 , V_58 ) ;
} else if ( ! ( V_622 [ 1 ] & V_623 )
|| ! ( V_622 [ 1 ] & V_624 ) ) {
if ( V_622 [ 1 ] & V_623 )
V_621 -> V_487 |= V_627 ;
V_622 [ 2 ] = V_621 -> V_399 ;
V_622 [ 3 ] = V_621 -> V_628 ;
V_622 [ 1 ] = V_621 -> V_487 ;
} else
V_622 [ 1 ] |= V_627 ;
return 0 ;
}
static void F_259 ( struct V_1 * V_2 ,
struct V_629 * V_630 )
{
F_260 ( V_2 ) ;
V_630 -> V_68 . V_631 =
V_2 -> V_5 . V_68 . V_69 &&
! F_261 ( V_2 -> V_5 . V_68 . V_16 ) ;
V_630 -> V_68 . V_16 = V_2 -> V_5 . V_68 . V_16 ;
V_630 -> V_68 . V_71 = V_2 -> V_5 . V_68 . V_71 ;
V_630 -> V_68 . V_632 = 0 ;
V_630 -> V_68 . V_62 = V_2 -> V_5 . V_68 . V_62 ;
V_630 -> V_633 . V_631 =
V_2 -> V_5 . V_633 . V_69 && ! V_2 -> V_5 . V_633 . V_634 ;
V_630 -> V_633 . V_16 = V_2 -> V_5 . V_633 . V_16 ;
V_630 -> V_633 . V_634 = 0 ;
V_630 -> V_633 . V_635 = V_74 -> V_636 ( V_2 ) ;
V_630 -> V_637 . V_631 = V_2 -> V_5 . V_638 ;
V_630 -> V_637 . V_69 = V_2 -> V_5 . V_639 != 0 ;
V_630 -> V_637 . V_640 = V_74 -> V_641 ( V_2 ) ;
V_630 -> V_637 . V_632 = 0 ;
V_630 -> V_642 = 0 ;
V_630 -> V_284 = ( V_643
| V_644 ) ;
memset ( & V_630 -> V_645 , 0 , sizeof( V_630 -> V_645 ) ) ;
}
static int F_262 ( struct V_1 * V_2 ,
struct V_629 * V_630 )
{
if ( V_630 -> V_284 & ~ ( V_643
| V_646
| V_644 ) )
return - V_598 ;
F_260 ( V_2 ) ;
V_2 -> V_5 . V_68 . V_69 = V_630 -> V_68 . V_631 ;
V_2 -> V_5 . V_68 . V_16 = V_630 -> V_68 . V_16 ;
V_2 -> V_5 . V_68 . V_71 = V_630 -> V_68 . V_71 ;
V_2 -> V_5 . V_68 . V_62 = V_630 -> V_68 . V_62 ;
V_2 -> V_5 . V_633 . V_69 = V_630 -> V_633 . V_631 ;
V_2 -> V_5 . V_633 . V_16 = V_630 -> V_633 . V_16 ;
V_2 -> V_5 . V_633 . V_634 = V_630 -> V_633 . V_634 ;
if ( V_630 -> V_284 & V_644 )
V_74 -> V_647 ( V_2 ,
V_630 -> V_633 . V_635 ) ;
V_2 -> V_5 . V_638 = V_630 -> V_637 . V_631 ;
if ( V_630 -> V_284 & V_643 )
V_2 -> V_5 . V_639 = V_630 -> V_637 . V_69 ;
V_74 -> V_648 ( V_2 , V_630 -> V_637 . V_640 ) ;
if ( V_630 -> V_284 & V_646 &&
F_263 ( V_2 ) )
V_2 -> V_5 . V_611 -> V_642 = V_630 -> V_642 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
static void F_264 ( struct V_1 * V_2 ,
struct V_649 * V_650 )
{
unsigned long V_184 ;
memcpy ( V_650 -> V_185 , V_2 -> V_5 . V_185 , sizeof( V_2 -> V_5 . V_185 ) ) ;
F_95 ( V_2 , 6 , & V_184 ) ;
V_650 -> V_173 = V_184 ;
V_650 -> V_174 = V_2 -> V_5 . V_174 ;
V_650 -> V_284 = 0 ;
memset ( & V_650 -> V_645 , 0 , sizeof( V_650 -> V_645 ) ) ;
}
static int F_265 ( struct V_1 * V_2 ,
struct V_649 * V_650 )
{
if ( V_650 -> V_284 )
return - V_598 ;
memcpy ( V_2 -> V_5 . V_185 , V_650 -> V_185 , sizeof( V_2 -> V_5 . V_185 ) ) ;
V_2 -> V_5 . V_173 = V_650 -> V_173 ;
F_89 ( V_2 ) ;
V_2 -> V_5 . V_174 = V_650 -> V_174 ;
F_90 ( V_2 ) ;
return 0 ;
}
static void F_266 ( struct V_1 * V_2 ,
struct V_651 * V_652 )
{
if ( V_572 ) {
memcpy ( V_652 -> V_653 ,
& V_2 -> V_5 . V_654 . V_655 -> V_656 ,
V_2 -> V_5 . V_657 ) ;
* ( T_2 * ) & V_652 -> V_653 [ V_658 / sizeof( T_1 ) ] &=
V_2 -> V_5 . V_149 | V_659 ;
} else {
memcpy ( V_652 -> V_653 ,
& V_2 -> V_5 . V_654 . V_655 -> V_660 ,
sizeof( struct V_661 ) ) ;
* ( T_2 * ) & V_652 -> V_653 [ V_658 / sizeof( T_1 ) ] =
V_659 ;
}
}
static int F_267 ( struct V_1 * V_2 ,
struct V_651 * V_652 )
{
T_2 V_662 =
* ( T_2 * ) & V_652 -> V_653 [ V_658 / sizeof( T_1 ) ] ;
if ( V_572 ) {
if ( V_662 & ~ F_268 () )
return - V_598 ;
memcpy ( & V_2 -> V_5 . V_654 . V_655 -> V_656 ,
V_652 -> V_653 , V_2 -> V_5 . V_657 ) ;
} else {
if ( V_662 & ~ V_659 )
return - V_598 ;
memcpy ( & V_2 -> V_5 . V_654 . V_655 -> V_660 ,
V_652 -> V_653 , sizeof( struct V_661 ) ) ;
}
return 0 ;
}
static void F_269 ( struct V_1 * V_2 ,
struct V_663 * V_664 )
{
if ( ! V_572 ) {
V_664 -> V_665 = 0 ;
return;
}
V_664 -> V_665 = 1 ;
V_664 -> V_284 = 0 ;
V_664 -> V_666 [ 0 ] . V_143 = V_139 ;
V_664 -> V_666 [ 0 ] . V_22 = V_2 -> V_5 . V_140 ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_663 * V_664 )
{
int V_3 , V_118 = 0 ;
if ( ! V_572 )
return - V_598 ;
if ( V_664 -> V_665 > V_667 || V_664 -> V_284 )
return - V_598 ;
for ( V_3 = 0 ; V_3 < V_664 -> V_665 ; V_3 ++ )
if ( V_664 -> V_666 [ V_3 ] . V_143 == V_139 ) {
V_118 = F_69 ( V_2 , V_139 ,
V_664 -> V_666 [ V_3 ] . V_22 ) ;
break;
}
if ( V_118 )
V_118 = - V_598 ;
return V_118 ;
}
static int F_271 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_325 )
return - V_598 ;
V_2 -> V_5 . V_333 = true ;
F_30 ( V_313 , V_2 ) ;
return 0 ;
}
long F_272 ( struct V_577 * V_578 ,
unsigned int V_579 , unsigned long V_580 )
{
struct V_1 * V_2 = V_578 -> V_668 ;
void V_403 * V_581 = ( void V_403 * ) V_580 ;
int V_118 ;
union {
struct V_607 * V_669 ;
struct V_651 * V_656 ;
struct V_663 * V_666 ;
void * V_670 ;
} V_671 ;
V_671 . V_670 = NULL ;
switch ( V_579 ) {
case V_672 : {
V_118 = - V_598 ;
if ( ! V_2 -> V_5 . V_611 )
goto V_112;
V_671 . V_669 = F_273 ( sizeof( struct V_607 ) , V_673 ) ;
V_118 = - V_390 ;
if ( ! V_671 . V_669 )
goto V_112;
V_118 = F_249 ( V_2 , V_671 . V_669 ) ;
if ( V_118 )
goto V_112;
V_118 = - V_99 ;
if ( F_230 ( V_581 , V_671 . V_669 , sizeof( struct V_607 ) ) )
goto V_112;
V_118 = 0 ;
break;
}
case V_674 : {
V_118 = - V_598 ;
if ( ! V_2 -> V_5 . V_611 )
goto V_112;
V_671 . V_669 = F_180 ( V_581 , sizeof( * V_671 . V_669 ) ) ;
if ( F_181 ( V_671 . V_669 ) )
return F_182 ( V_671 . V_669 ) ;
V_118 = F_250 ( V_2 , V_671 . V_669 ) ;
break;
}
case V_675 : {
struct V_612 V_613 ;
V_118 = - V_99 ;
if ( F_229 ( & V_613 , V_581 , sizeof V_613 ) )
goto V_112;
V_118 = F_253 ( V_2 , & V_613 ) ;
break;
}
case V_676 : {
V_118 = F_255 ( V_2 ) ;
break;
}
case V_677 : {
struct V_678 V_403 * V_593 = V_581 ;
struct V_678 V_594 ;
V_118 = - V_99 ;
if ( F_229 ( & V_594 , V_593 , sizeof V_594 ) )
goto V_112;
V_118 = F_274 ( V_2 , & V_594 , V_593 -> V_510 ) ;
break;
}
case V_679 : {
struct V_592 V_403 * V_593 = V_581 ;
struct V_592 V_594 ;
V_118 = - V_99 ;
if ( F_229 ( & V_594 , V_593 , sizeof V_594 ) )
goto V_112;
V_118 = F_275 ( V_2 , & V_594 ,
V_593 -> V_510 ) ;
break;
}
case V_680 : {
struct V_592 V_403 * V_593 = V_581 ;
struct V_592 V_594 ;
V_118 = - V_99 ;
if ( F_229 ( & V_594 , V_593 , sizeof V_594 ) )
goto V_112;
V_118 = F_276 ( V_2 , & V_594 ,
V_593 -> V_510 ) ;
if ( V_118 )
goto V_112;
V_118 = - V_99 ;
if ( F_230 ( V_593 , & V_594 , sizeof V_594 ) )
goto V_112;
V_118 = 0 ;
break;
}
case V_681 :
V_118 = F_228 ( V_2 , V_581 , F_213 , 1 ) ;
break;
case V_682 :
V_118 = F_228 ( V_2 , V_581 , F_107 , 0 ) ;
break;
case V_683 : {
struct V_616 V_617 ;
V_118 = - V_99 ;
if ( F_229 ( & V_617 , V_581 , sizeof V_617 ) )
goto V_112;
V_118 = F_256 ( V_2 , & V_617 ) ;
if ( V_118 )
goto V_112;
V_118 = - V_99 ;
if ( F_230 ( V_581 , & V_617 , sizeof V_617 ) )
goto V_112;
V_118 = 0 ;
break;
} ;
case V_684 : {
struct V_685 V_686 ;
V_118 = - V_598 ;
if ( ! F_85 ( V_2 -> V_100 ) )
goto V_112;
V_118 = - V_99 ;
if ( F_229 ( & V_686 , V_581 , sizeof V_686 ) )
goto V_112;
V_118 = F_277 ( V_2 , V_686 . V_687 ) ;
break;
}
case V_688 : {
T_2 V_369 ;
V_118 = - V_99 ;
if ( F_229 ( & V_369 , V_581 , sizeof V_369 ) )
goto V_112;
V_118 = F_257 ( V_2 , V_369 ) ;
break;
}
case V_689 : {
struct V_620 V_621 ;
V_118 = - V_99 ;
if ( F_229 ( & V_621 , V_581 , sizeof V_621 ) )
goto V_112;
V_118 = F_258 ( V_2 , & V_621 ) ;
break;
}
case V_690 : {
struct V_629 V_630 ;
F_259 ( V_2 , & V_630 ) ;
V_118 = - V_99 ;
if ( F_230 ( V_581 , & V_630 , sizeof( struct V_629 ) ) )
break;
V_118 = 0 ;
break;
}
case V_691 : {
struct V_629 V_630 ;
V_118 = - V_99 ;
if ( F_229 ( & V_630 , V_581 , sizeof( struct V_629 ) ) )
break;
V_118 = F_262 ( V_2 , & V_630 ) ;
break;
}
case V_692 : {
struct V_649 V_650 ;
F_264 ( V_2 , & V_650 ) ;
V_118 = - V_99 ;
if ( F_230 ( V_581 , & V_650 ,
sizeof( struct V_649 ) ) )
break;
V_118 = 0 ;
break;
}
case V_693 : {
struct V_649 V_650 ;
V_118 = - V_99 ;
if ( F_229 ( & V_650 , V_581 ,
sizeof( struct V_649 ) ) )
break;
V_118 = F_265 ( V_2 , & V_650 ) ;
break;
}
case V_694 : {
V_671 . V_656 = F_273 ( sizeof( struct V_651 ) , V_673 ) ;
V_118 = - V_390 ;
if ( ! V_671 . V_656 )
break;
F_266 ( V_2 , V_671 . V_656 ) ;
V_118 = - V_99 ;
if ( F_230 ( V_581 , V_671 . V_656 , sizeof( struct V_651 ) ) )
break;
V_118 = 0 ;
break;
}
case V_695 : {
V_671 . V_656 = F_180 ( V_581 , sizeof( * V_671 . V_656 ) ) ;
if ( F_181 ( V_671 . V_656 ) )
return F_182 ( V_671 . V_656 ) ;
V_118 = F_267 ( V_2 , V_671 . V_656 ) ;
break;
}
case V_696 : {
V_671 . V_666 = F_273 ( sizeof( struct V_663 ) , V_673 ) ;
V_118 = - V_390 ;
if ( ! V_671 . V_666 )
break;
F_269 ( V_2 , V_671 . V_666 ) ;
V_118 = - V_99 ;
if ( F_230 ( V_581 , V_671 . V_666 ,
sizeof( struct V_663 ) ) )
break;
V_118 = 0 ;
break;
}
case V_697 : {
V_671 . V_666 = F_180 ( V_581 , sizeof( * V_671 . V_666 ) ) ;
if ( F_181 ( V_671 . V_666 ) )
return F_182 ( V_671 . V_666 ) ;
V_118 = F_270 ( V_2 , V_671 . V_666 ) ;
break;
}
case V_698 : {
T_1 V_699 ;
V_118 = - V_598 ;
V_699 = ( T_1 ) V_580 ;
if ( V_699 >= V_700 )
goto V_112;
if ( V_699 == 0 )
V_699 = V_261 ;
F_128 ( V_2 , V_699 ) ;
V_118 = 0 ;
goto V_112;
}
case V_701 : {
V_118 = V_2 -> V_5 . V_260 ;
goto V_112;
}
case V_702 : {
V_118 = F_271 ( V_2 ) ;
goto V_112;
}
default:
V_118 = - V_598 ;
}
V_112:
F_183 ( V_671 . V_670 ) ;
return V_118 ;
}
int F_278 ( struct V_1 * V_2 , struct V_703 * V_704 )
{
return V_705 ;
}
static int F_279 ( struct V_100 * V_100 , unsigned long V_399 )
{
int V_107 ;
if ( V_399 > ( unsigned int ) ( - 3 * V_106 ) )
return - V_598 ;
V_107 = V_74 -> V_706 ( V_100 , V_399 ) ;
return V_107 ;
}
static int F_280 ( struct V_100 * V_100 ,
T_2 V_707 )
{
V_100 -> V_5 . V_708 = V_707 ;
return 0 ;
}
static int F_281 ( struct V_100 * V_100 ,
T_1 V_709 )
{
if ( V_709 < V_710 )
return - V_598 ;
F_210 ( & V_100 -> V_711 ) ;
F_282 ( V_100 , V_709 ) ;
V_100 -> V_5 . V_712 = V_709 ;
F_211 ( & V_100 -> V_711 ) ;
return 0 ;
}
static int F_283 ( struct V_100 * V_100 )
{
return V_100 -> V_5 . V_713 ;
}
static int F_284 ( struct V_100 * V_100 , struct V_714 * V_715 )
{
int V_118 ;
V_118 = 0 ;
switch ( V_715 -> V_716 ) {
case V_717 :
memcpy ( & V_715 -> V_715 . V_718 ,
& F_285 ( V_100 ) -> V_719 [ 0 ] ,
sizeof( struct V_720 ) ) ;
break;
case V_721 :
memcpy ( & V_715 -> V_715 . V_718 ,
& F_285 ( V_100 ) -> V_719 [ 1 ] ,
sizeof( struct V_720 ) ) ;
break;
case V_722 :
V_118 = F_286 ( V_100 , & V_715 -> V_715 . V_723 ) ;
break;
default:
V_118 = - V_598 ;
break;
}
return V_118 ;
}
static int F_287 ( struct V_100 * V_100 , struct V_714 * V_715 )
{
int V_118 ;
V_118 = 0 ;
switch ( V_715 -> V_716 ) {
case V_717 :
F_139 ( & F_285 ( V_100 ) -> V_481 ) ;
memcpy ( & F_285 ( V_100 ) -> V_719 [ 0 ] ,
& V_715 -> V_715 . V_718 ,
sizeof( struct V_720 ) ) ;
F_140 ( & F_285 ( V_100 ) -> V_481 ) ;
break;
case V_721 :
F_139 ( & F_285 ( V_100 ) -> V_481 ) ;
memcpy ( & F_285 ( V_100 ) -> V_719 [ 1 ] ,
& V_715 -> V_715 . V_718 ,
sizeof( struct V_720 ) ) ;
F_140 ( & F_285 ( V_100 ) -> V_481 ) ;
break;
case V_722 :
V_118 = F_288 ( V_100 , & V_715 -> V_715 . V_723 ) ;
break;
default:
V_118 = - V_598 ;
break;
}
F_289 ( F_285 ( V_100 ) ) ;
return V_118 ;
}
static int F_290 ( struct V_100 * V_100 , struct V_724 * V_725 )
{
int V_118 = 0 ;
F_210 ( & V_100 -> V_5 . V_726 -> V_727 . V_481 ) ;
memcpy ( V_725 , & V_100 -> V_5 . V_726 -> V_727 , sizeof( struct V_724 ) ) ;
F_211 ( & V_100 -> V_5 . V_726 -> V_727 . V_481 ) ;
return V_118 ;
}
static int F_291 ( struct V_100 * V_100 , struct V_724 * V_725 )
{
int V_118 = 0 ;
F_210 ( & V_100 -> V_5 . V_726 -> V_727 . V_481 ) ;
memcpy ( & V_100 -> V_5 . V_726 -> V_727 , V_725 , sizeof( struct V_724 ) ) ;
F_292 ( V_100 , 0 , V_725 -> V_728 [ 0 ] . V_729 , 0 ) ;
F_211 ( & V_100 -> V_5 . V_726 -> V_727 . V_481 ) ;
return V_118 ;
}
static int F_293 ( struct V_100 * V_100 , struct V_730 * V_725 )
{
int V_118 = 0 ;
F_210 ( & V_100 -> V_5 . V_726 -> V_727 . V_481 ) ;
memcpy ( V_725 -> V_728 , & V_100 -> V_5 . V_726 -> V_727 . V_728 ,
sizeof( V_725 -> V_728 ) ) ;
V_725 -> V_284 = V_100 -> V_5 . V_726 -> V_727 . V_284 ;
F_211 ( & V_100 -> V_5 . V_726 -> V_727 . V_481 ) ;
memset ( & V_725 -> V_645 , 0 , sizeof( V_725 -> V_645 ) ) ;
return V_118 ;
}
static int F_294 ( struct V_100 * V_100 , struct V_730 * V_725 )
{
int V_118 = 0 , V_731 = 0 ;
T_1 V_732 , V_733 ;
F_210 ( & V_100 -> V_5 . V_726 -> V_727 . V_481 ) ;
V_732 = V_100 -> V_5 . V_726 -> V_727 . V_284 & V_734 ;
V_733 = V_725 -> V_284 & V_734 ;
if ( ! V_732 && V_733 )
V_731 = 1 ;
memcpy ( & V_100 -> V_5 . V_726 -> V_727 . V_728 , & V_725 -> V_728 ,
sizeof( V_100 -> V_5 . V_726 -> V_727 . V_728 ) ) ;
V_100 -> V_5 . V_726 -> V_727 . V_284 = V_725 -> V_284 ;
F_292 ( V_100 , 0 , V_100 -> V_5 . V_726 -> V_727 . V_728 [ 0 ] . V_729 , V_731 ) ;
F_211 ( & V_100 -> V_5 . V_726 -> V_727 . V_481 ) ;
return V_118 ;
}
static int F_295 ( struct V_100 * V_100 ,
struct V_735 * V_736 )
{
if ( ! V_100 -> V_5 . V_726 )
return - V_615 ;
F_210 ( & V_100 -> V_5 . V_726 -> V_727 . V_481 ) ;
V_100 -> V_5 . V_726 -> V_727 . V_63 = V_736 -> V_737 ;
F_211 ( & V_100 -> V_5 . V_726 -> V_727 . V_481 ) ;
return 0 ;
}
int F_296 ( struct V_100 * V_100 , struct V_738 * log )
{
int V_118 ;
struct V_739 * V_740 ;
unsigned long V_515 , V_3 ;
unsigned long * V_741 ;
unsigned long * V_742 ;
bool V_743 = false ;
F_210 ( & V_100 -> V_711 ) ;
V_118 = - V_598 ;
if ( log -> V_10 >= V_566 )
goto V_112;
V_740 = F_297 ( V_100 -> V_744 , log -> V_10 ) ;
V_741 = V_740 -> V_741 ;
V_118 = - V_745 ;
if ( ! V_741 )
goto V_112;
V_515 = F_298 ( V_740 ) ;
V_742 = V_741 + V_515 / sizeof( long ) ;
memset ( V_742 , 0 , V_515 ) ;
F_139 ( & V_100 -> V_746 ) ;
for ( V_3 = 0 ; V_3 < V_515 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_28 ;
T_5 V_92 ;
if ( ! V_741 [ V_3 ] )
continue;
V_743 = true ;
V_28 = F_299 ( & V_741 [ V_3 ] , 0 ) ;
V_742 [ V_3 ] = V_28 ;
V_92 = V_3 * V_747 ;
F_300 ( V_100 , V_740 , V_92 , V_28 ) ;
}
F_140 ( & V_100 -> V_746 ) ;
F_301 ( & V_100 -> V_711 ) ;
if ( V_743 )
F_302 ( V_100 ) ;
V_118 = - V_99 ;
if ( F_230 ( log -> V_741 , V_742 , V_515 ) )
goto V_112;
V_118 = 0 ;
V_112:
F_211 ( & V_100 -> V_711 ) ;
return V_118 ;
}
int F_303 ( struct V_100 * V_100 , struct V_748 * V_749 ,
bool V_750 )
{
if ( ! F_85 ( V_100 ) )
return - V_615 ;
V_749 -> V_487 = F_304 ( V_100 , V_751 ,
V_749 -> V_613 , V_749 -> V_752 ,
V_750 ) ;
return 0 ;
}
long F_305 ( struct V_577 * V_578 ,
unsigned int V_579 , unsigned long V_580 )
{
struct V_100 * V_100 = V_578 -> V_668 ;
void V_403 * V_581 = ( void V_403 * ) V_580 ;
int V_118 = - V_753 ;
union {
struct V_724 V_725 ;
struct V_730 V_754 ;
struct V_755 V_756 ;
} V_671 ;
switch ( V_579 ) {
case V_757 :
V_118 = F_279 ( V_100 , V_580 ) ;
break;
case V_758 : {
T_2 V_707 ;
V_118 = - V_99 ;
if ( F_229 ( & V_707 , V_581 , sizeof V_707 ) )
goto V_112;
V_118 = F_280 ( V_100 , V_707 ) ;
break;
}
case V_759 :
V_118 = F_281 ( V_100 , V_580 ) ;
break;
case V_760 :
V_118 = F_283 ( V_100 ) ;
break;
case V_761 : {
struct V_762 * V_763 ;
F_210 ( & V_100 -> V_481 ) ;
V_118 = - V_764 ;
if ( V_100 -> V_5 . V_763 )
goto V_765;
V_118 = - V_598 ;
if ( F_131 ( & V_100 -> V_274 ) )
goto V_765;
V_118 = - V_390 ;
V_763 = F_306 ( V_100 ) ;
if ( V_763 ) {
V_118 = F_307 ( V_100 ) ;
if ( V_118 ) {
F_210 ( & V_100 -> V_711 ) ;
F_308 ( V_100 , V_766 ,
& V_763 -> V_767 ) ;
F_308 ( V_100 , V_766 ,
& V_763 -> V_768 ) ;
F_308 ( V_100 , V_766 ,
& V_763 -> V_769 ) ;
F_211 ( & V_100 -> V_711 ) ;
F_183 ( V_763 ) ;
goto V_765;
}
} else
goto V_765;
F_14 () ;
V_100 -> V_5 . V_763 = V_763 ;
F_14 () ;
V_118 = F_309 ( V_100 ) ;
if ( V_118 ) {
F_210 ( & V_100 -> V_711 ) ;
F_210 ( & V_100 -> V_770 ) ;
F_310 ( V_100 ) ;
F_311 ( V_100 ) ;
F_211 ( & V_100 -> V_770 ) ;
F_211 ( & V_100 -> V_711 ) ;
}
V_765:
F_211 ( & V_100 -> V_481 ) ;
break;
}
case V_771 :
V_671 . V_756 . V_284 = V_772 ;
goto V_773;
case V_774 :
V_118 = - V_99 ;
if ( F_229 ( & V_671 . V_756 , V_581 ,
sizeof( struct V_755 ) ) )
goto V_112;
V_773:
F_210 ( & V_100 -> V_711 ) ;
V_118 = - V_764 ;
if ( V_100 -> V_5 . V_726 )
goto V_775;
V_118 = - V_390 ;
V_100 -> V_5 . V_726 = F_312 ( V_100 , V_671 . V_756 . V_284 ) ;
if ( V_100 -> V_5 . V_726 )
V_118 = 0 ;
V_775:
F_211 ( & V_100 -> V_711 ) ;
break;
case V_776 : {
struct V_714 * V_715 ;
V_715 = F_180 ( V_581 , sizeof( * V_715 ) ) ;
if ( F_181 ( V_715 ) ) {
V_118 = F_182 ( V_715 ) ;
goto V_112;
}
V_118 = - V_615 ;
if ( ! F_85 ( V_100 ) )
goto V_777;
V_118 = F_284 ( V_100 , V_715 ) ;
if ( V_118 )
goto V_777;
V_118 = - V_99 ;
if ( F_230 ( V_581 , V_715 , sizeof *V_715 ) )
goto V_777;
V_118 = 0 ;
V_777:
F_183 ( V_715 ) ;
break;
}
case V_778 : {
struct V_714 * V_715 ;
V_715 = F_180 ( V_581 , sizeof( * V_715 ) ) ;
if ( F_181 ( V_715 ) ) {
V_118 = F_182 ( V_715 ) ;
goto V_112;
}
V_118 = - V_615 ;
if ( ! F_85 ( V_100 ) )
goto V_779;
V_118 = F_287 ( V_100 , V_715 ) ;
if ( V_118 )
goto V_779;
V_118 = 0 ;
V_779:
F_183 ( V_715 ) ;
break;
}
case V_780 : {
V_118 = - V_99 ;
if ( F_229 ( & V_671 . V_725 , V_581 , sizeof( struct V_724 ) ) )
goto V_112;
V_118 = - V_615 ;
if ( ! V_100 -> V_5 . V_726 )
goto V_112;
V_118 = F_290 ( V_100 , & V_671 . V_725 ) ;
if ( V_118 )
goto V_112;
V_118 = - V_99 ;
if ( F_230 ( V_581 , & V_671 . V_725 , sizeof( struct V_724 ) ) )
goto V_112;
V_118 = 0 ;
break;
}
case V_781 : {
V_118 = - V_99 ;
if ( F_229 ( & V_671 . V_725 , V_581 , sizeof V_671 . V_725 ) )
goto V_112;
V_118 = - V_615 ;
if ( ! V_100 -> V_5 . V_726 )
goto V_112;
V_118 = F_291 ( V_100 , & V_671 . V_725 ) ;
break;
}
case V_782 : {
V_118 = - V_615 ;
if ( ! V_100 -> V_5 . V_726 )
goto V_112;
V_118 = F_293 ( V_100 , & V_671 . V_754 ) ;
if ( V_118 )
goto V_112;
V_118 = - V_99 ;
if ( F_230 ( V_581 , & V_671 . V_754 , sizeof( V_671 . V_754 ) ) )
goto V_112;
V_118 = 0 ;
break;
}
case V_783 : {
V_118 = - V_99 ;
if ( F_229 ( & V_671 . V_754 , V_581 , sizeof( V_671 . V_754 ) ) )
goto V_112;
V_118 = - V_615 ;
if ( ! V_100 -> V_5 . V_726 )
goto V_112;
V_118 = F_294 ( V_100 , & V_671 . V_754 ) ;
break;
}
case V_784 : {
struct V_735 V_736 ;
V_118 = - V_99 ;
if ( F_229 ( & V_736 , V_581 , sizeof( V_736 ) ) )
goto V_112;
V_118 = F_295 ( V_100 , & V_736 ) ;
break;
}
case V_785 : {
V_118 = - V_99 ;
if ( F_229 ( & V_100 -> V_5 . F_179 , V_581 ,
sizeof( struct V_786 ) ) )
goto V_112;
V_118 = - V_598 ;
if ( V_100 -> V_5 . F_179 . V_284 )
goto V_112;
V_118 = 0 ;
break;
}
case V_787 : {
struct V_788 V_789 ;
T_2 V_790 ;
T_12 V_296 ;
V_118 = - V_99 ;
if ( F_229 ( & V_789 , V_581 , sizeof( V_789 ) ) )
goto V_112;
V_118 = - V_598 ;
if ( V_789 . V_284 )
goto V_112;
V_118 = 0 ;
F_313 () ;
V_790 = F_122 () ;
V_296 = V_789 . clock - V_790 ;
F_314 () ;
V_100 -> V_5 . V_232 = V_296 ;
F_154 ( V_100 ) ;
break;
}
case V_791 : {
struct V_788 V_789 ;
T_2 V_790 ;
F_313 () ;
V_790 = F_122 () ;
V_789 . clock = V_100 -> V_5 . V_232 + V_790 ;
F_314 () ;
V_789 . V_284 = 0 ;
memset ( & V_789 . V_632 , 0 , sizeof( V_789 . V_632 ) ) ;
V_118 = - V_99 ;
if ( F_230 ( V_581 , & V_789 , sizeof( V_789 ) ) )
goto V_112;
V_118 = 0 ;
break;
}
default:
;
}
V_112:
return V_118 ;
}
static void F_315 ( void )
{
T_1 V_792 [ 2 ] ;
unsigned V_3 , V_793 ;
for ( V_3 = V_793 = V_794 ; V_3 < F_49 ( V_589 ) ; V_3 ++ ) {
if ( F_316 ( V_589 [ V_3 ] , & V_792 [ 0 ] , & V_792 [ 1 ] ) < 0 )
continue;
switch ( V_589 [ V_3 ] ) {
case V_795 :
if ( ! V_74 -> V_796 () )
continue;
break;
default:
break;
}
if ( V_793 < V_3 )
V_589 [ V_793 ] = V_589 [ V_3 ] ;
V_793 ++ ;
}
V_586 = V_793 ;
}
static int F_317 ( struct V_1 * V_2 , T_6 V_399 , int V_93 ,
const void * V_254 )
{
int V_797 = 0 ;
int V_515 ;
do {
V_515 = F_318 ( V_93 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_611 &&
! F_319 ( & V_2 -> V_5 . V_611 -> V_798 , V_399 , V_515 , V_254 ) )
&& F_320 ( V_2 -> V_100 , V_799 , V_399 , V_515 , V_254 ) )
break;
V_797 += V_515 ;
V_399 += V_515 ;
V_93 -= V_515 ;
V_254 += V_515 ;
} while ( V_93 );
return V_797 ;
}
static int F_321 ( struct V_1 * V_2 , T_6 V_399 , int V_93 , void * V_254 )
{
int V_797 = 0 ;
int V_515 ;
do {
V_515 = F_318 ( V_93 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_611 &&
! F_322 ( & V_2 -> V_5 . V_611 -> V_798 , V_399 , V_515 , V_254 ) )
&& F_323 ( V_2 -> V_100 , V_799 , V_399 , V_515 , V_254 ) )
break;
F_324 ( V_800 , V_515 , V_399 , * ( T_2 * ) V_254 ) ;
V_797 += V_515 ;
V_399 += V_515 ;
V_93 -= V_515 ;
V_254 += V_515 ;
} while ( V_93 );
return V_797 ;
}
static void F_325 ( struct V_1 * V_2 ,
struct V_801 * V_802 , int V_803 )
{
V_74 -> V_804 ( V_2 , V_802 , V_803 ) ;
}
void F_326 ( struct V_1 * V_2 ,
struct V_801 * V_802 , int V_803 )
{
V_74 -> V_805 ( V_2 , V_802 , V_803 ) ;
}
T_6 F_327 ( struct V_1 * V_2 , T_6 V_419 , T_1 V_94 )
{
T_6 V_806 ;
struct V_76 V_68 ;
F_13 ( ! F_38 ( V_2 ) ) ;
V_94 |= V_110 ;
V_806 = V_2 -> V_5 . V_85 . V_807 ( V_2 , V_419 , V_94 , & V_68 ) ;
return V_806 ;
}
T_6 F_328 ( struct V_1 * V_2 , T_16 V_808 ,
struct V_76 * V_68 )
{
T_1 V_94 = ( V_74 -> V_89 ( V_2 ) == 3 ) ? V_110 : 0 ;
return V_2 -> V_5 . V_102 -> V_807 ( V_2 , V_808 , V_94 , V_68 ) ;
}
T_6 F_329 ( struct V_1 * V_2 , T_16 V_808 ,
struct V_76 * V_68 )
{
T_1 V_94 = ( V_74 -> V_89 ( V_2 ) == 3 ) ? V_110 : 0 ;
V_94 |= V_809 ;
return V_2 -> V_5 . V_102 -> V_807 ( V_2 , V_808 , V_94 , V_68 ) ;
}
T_6 F_330 ( struct V_1 * V_2 , T_16 V_808 ,
struct V_76 * V_68 )
{
T_1 V_94 = ( V_74 -> V_89 ( V_2 ) == 3 ) ? V_110 : 0 ;
V_94 |= V_111 ;
return V_2 -> V_5 . V_102 -> V_807 ( V_2 , V_808 , V_94 , V_68 ) ;
}
T_6 F_331 ( struct V_1 * V_2 , T_16 V_808 ,
struct V_76 * V_68 )
{
return V_2 -> V_5 . V_102 -> V_807 ( V_2 , V_808 , 0 , V_68 ) ;
}
static int F_332 ( T_16 V_399 , void * V_184 , unsigned int V_810 ,
struct V_1 * V_2 , T_1 V_94 ,
struct V_76 * V_68 )
{
void * V_38 = V_184 ;
int V_118 = V_811 ;
while ( V_810 ) {
T_6 V_419 = V_2 -> V_5 . V_102 -> V_807 ( V_2 , V_399 , V_94 ,
V_68 ) ;
unsigned V_92 = V_399 & ( V_106 - 1 ) ;
unsigned V_812 = F_318 ( V_810 , ( unsigned ) V_106 - V_92 ) ;
int V_107 ;
if ( V_419 == V_98 )
return V_813 ;
V_107 = F_46 ( V_2 -> V_100 , V_419 >> V_105 , V_38 ,
V_92 , V_812 ) ;
if ( V_107 < 0 ) {
V_118 = V_814 ;
goto V_112;
}
V_810 -= V_812 ;
V_38 += V_812 ;
V_399 += V_812 ;
}
V_112:
return V_118 ;
}
static int F_333 ( struct V_815 * V_816 ,
T_16 V_399 , void * V_184 , unsigned int V_810 ,
struct V_76 * V_68 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
T_1 V_94 = ( V_74 -> V_89 ( V_2 ) == 3 ) ? V_110 : 0 ;
unsigned V_92 ;
int V_107 ;
T_6 V_419 = V_2 -> V_5 . V_102 -> V_807 ( V_2 , V_399 , V_94 | V_809 ,
V_68 ) ;
if ( F_148 ( V_419 == V_98 ) )
return V_813 ;
V_92 = V_399 & ( V_106 - 1 ) ;
if ( F_28 ( V_92 + V_810 > V_106 ) )
V_810 = ( unsigned ) V_106 - V_92 ;
V_107 = F_46 ( V_2 -> V_100 , V_419 >> V_105 , V_184 ,
V_92 , V_810 ) ;
if ( F_148 ( V_107 < 0 ) )
return V_814 ;
return V_811 ;
}
int F_335 ( struct V_815 * V_816 ,
T_16 V_399 , void * V_184 , unsigned int V_810 ,
struct V_76 * V_68 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
T_1 V_94 = ( V_74 -> V_89 ( V_2 ) == 3 ) ? V_110 : 0 ;
return F_332 ( V_399 , V_184 , V_810 , V_2 , V_94 ,
V_68 ) ;
}
static int F_336 ( struct V_815 * V_816 ,
T_16 V_399 , void * V_184 , unsigned int V_810 ,
struct V_76 * V_68 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
return F_332 ( V_399 , V_184 , V_810 , V_2 , 0 , V_68 ) ;
}
int F_337 ( struct V_815 * V_816 ,
T_16 V_399 , void * V_184 ,
unsigned int V_810 ,
struct V_76 * V_68 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
void * V_38 = V_184 ;
int V_118 = V_811 ;
while ( V_810 ) {
T_6 V_419 = V_2 -> V_5 . V_102 -> V_807 ( V_2 , V_399 ,
V_111 ,
V_68 ) ;
unsigned V_92 = V_399 & ( V_106 - 1 ) ;
unsigned V_817 = F_318 ( V_810 , ( unsigned ) V_106 - V_92 ) ;
int V_107 ;
if ( V_419 == V_98 )
return V_813 ;
V_107 = F_115 ( V_2 -> V_100 , V_419 , V_38 , V_817 ) ;
if ( V_107 < 0 ) {
V_118 = V_814 ;
goto V_112;
}
V_810 -= V_817 ;
V_38 += V_817 ;
V_399 += V_817 ;
}
V_112:
return V_118 ;
}
static int F_338 ( struct V_1 * V_2 , unsigned long V_808 ,
T_6 * V_419 , struct V_76 * V_68 ,
bool V_818 )
{
T_1 V_94 = ( ( V_74 -> V_89 ( V_2 ) == 3 ) ? V_110 : 0 )
| ( V_818 ? V_111 : 0 ) ;
if ( F_339 ( V_2 , V_808 )
&& ! F_340 ( V_2 , V_2 -> V_5 . V_102 ,
V_2 -> V_5 . V_94 , V_94 ) ) {
* V_419 = V_2 -> V_5 . V_819 << V_105 |
( V_808 & ( V_106 - 1 ) ) ;
F_341 ( V_808 , * V_419 , V_818 , false ) ;
return 1 ;
}
* V_419 = V_2 -> V_5 . V_102 -> V_807 ( V_2 , V_808 , V_94 , V_68 ) ;
if ( * V_419 == V_98 )
return - 1 ;
if ( ( * V_419 & V_386 ) == V_820 )
return 1 ;
if ( F_342 ( V_2 , * V_419 ) ) {
F_341 ( V_808 , * V_419 , V_818 , true ) ;
return 1 ;
}
return 0 ;
}
int F_343 ( struct V_1 * V_2 , T_6 V_419 ,
const void * V_184 , int V_810 )
{
int V_107 ;
V_107 = F_115 ( V_2 -> V_100 , V_419 , V_184 , V_810 ) ;
if ( V_107 < 0 )
return 0 ;
F_344 ( V_2 , V_419 , V_184 , V_810 ) ;
return 1 ;
}
static int F_345 ( struct V_1 * V_2 , void * V_184 , int V_810 )
{
if ( V_2 -> V_821 ) {
F_324 ( V_800 , V_810 ,
V_2 -> V_822 [ 0 ] . V_419 , * ( T_2 * ) V_184 ) ;
V_2 -> V_821 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_346 ( struct V_1 * V_2 , T_6 V_419 ,
void * V_184 , int V_810 )
{
return ! F_114 ( V_2 -> V_100 , V_419 , V_184 , V_810 ) ;
}
static int F_347 ( struct V_1 * V_2 , T_6 V_419 ,
void * V_184 , int V_810 )
{
return F_343 ( V_2 , V_419 , V_184 , V_810 ) ;
}
static int F_348 ( struct V_1 * V_2 , T_6 V_419 , int V_810 , void * V_184 )
{
F_324 ( V_823 , V_810 , V_419 , * ( T_2 * ) V_184 ) ;
return F_317 ( V_2 , V_419 , V_810 , V_184 ) ;
}
static int F_349 ( struct V_1 * V_2 , T_6 V_419 ,
void * V_184 , int V_810 )
{
F_324 ( V_824 , V_810 , V_419 , 0 ) ;
return V_814 ;
}
static int F_350 ( struct V_1 * V_2 , T_6 V_419 ,
void * V_184 , int V_810 )
{
struct V_825 * V_826 = & V_2 -> V_822 [ 0 ] ;
memcpy ( V_2 -> V_827 -> V_828 . V_38 , V_826 -> V_38 , F_318 ( 8u , V_826 -> V_93 ) ) ;
return V_811 ;
}
static int F_351 ( unsigned long V_399 , void * V_184 ,
unsigned int V_810 ,
struct V_76 * V_68 ,
struct V_1 * V_2 ,
const struct V_829 * V_830 )
{
T_6 V_419 ;
int V_797 , V_107 ;
bool V_818 = V_830 -> V_818 ;
struct V_825 * V_826 ;
V_107 = F_338 ( V_2 , V_399 , & V_419 , V_68 , V_818 ) ;
if ( V_107 < 0 )
return V_813 ;
if ( V_107 )
goto V_828;
if ( V_830 -> V_831 ( V_2 , V_419 , V_184 , V_810 ) )
return V_811 ;
V_828:
V_797 = V_830 -> V_832 ( V_2 , V_419 , V_810 , V_184 ) ;
if ( V_797 == V_810 )
return V_811 ;
V_419 += V_797 ;
V_810 -= V_797 ;
V_184 += V_797 ;
F_28 ( V_2 -> V_833 >= V_834 ) ;
V_826 = & V_2 -> V_822 [ V_2 -> V_833 ++ ] ;
V_826 -> V_419 = V_419 ;
V_826 -> V_38 = V_184 ;
V_826 -> V_93 = V_810 ;
return V_811 ;
}
int F_352 ( struct V_815 * V_816 , unsigned long V_399 ,
void * V_184 , unsigned int V_810 ,
struct V_76 * V_68 ,
const struct V_829 * V_830 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
T_6 V_419 ;
int V_835 ;
if ( V_830 -> V_836 &&
V_830 -> V_836 ( V_2 , V_184 , V_810 ) )
return V_811 ;
V_2 -> V_833 = 0 ;
if ( ( ( V_399 + V_810 - 1 ) ^ V_399 ) & V_386 ) {
int V_837 ;
V_837 = - V_399 & ~ V_386 ;
V_835 = F_351 ( V_399 , V_184 , V_837 , V_68 ,
V_2 , V_830 ) ;
if ( V_835 != V_811 )
return V_835 ;
V_399 += V_837 ;
V_184 += V_837 ;
V_810 -= V_837 ;
}
V_835 = F_351 ( V_399 , V_184 , V_810 , V_68 ,
V_2 , V_830 ) ;
if ( V_835 != V_811 )
return V_835 ;
if ( ! V_2 -> V_833 )
return V_835 ;
V_419 = V_2 -> V_822 [ 0 ] . V_419 ;
V_2 -> V_838 = 1 ;
V_2 -> V_839 = 0 ;
V_2 -> V_827 -> V_828 . V_93 = F_318 ( 8u , V_2 -> V_822 [ 0 ] . V_93 ) ;
V_2 -> V_827 -> V_828 . V_840 = V_2 -> V_841 = V_830 -> V_818 ;
V_2 -> V_827 -> V_842 = V_843 ;
V_2 -> V_827 -> V_828 . V_844 = V_419 ;
return V_830 -> V_845 ( V_2 , V_419 , V_184 , V_810 ) ;
}
static int F_353 ( struct V_815 * V_816 ,
unsigned long V_399 ,
void * V_184 ,
unsigned int V_810 ,
struct V_76 * V_68 )
{
return F_352 ( V_816 , V_399 , V_184 , V_810 ,
V_68 , & V_846 ) ;
}
int F_354 ( struct V_815 * V_816 ,
unsigned long V_399 ,
const void * V_184 ,
unsigned int V_810 ,
struct V_76 * V_68 )
{
return F_352 ( V_816 , V_399 , ( void * ) V_184 , V_810 ,
V_68 , & V_847 ) ;
}
static int F_355 ( struct V_815 * V_816 ,
unsigned long V_399 ,
const void * V_848 ,
const void * V_849 ,
unsigned int V_810 ,
struct V_76 * V_68 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
T_6 V_419 ;
struct V_388 * V_388 ;
char * V_850 ;
bool V_851 ;
if ( V_810 > 8 || ( V_810 & ( V_810 - 1 ) ) )
goto V_852;
V_419 = F_330 ( V_2 , V_399 , NULL ) ;
if ( V_419 == V_98 ||
( V_419 & V_386 ) == V_820 )
goto V_852;
if ( ( ( V_419 + V_810 - 1 ) & V_386 ) != ( V_419 & V_386 ) )
goto V_852;
V_388 = F_356 ( V_2 -> V_100 , V_419 >> V_105 ) ;
if ( F_357 ( V_388 ) )
goto V_852;
V_850 = F_358 ( V_388 ) ;
V_850 += F_359 ( V_419 ) ;
switch ( V_810 ) {
case 1 :
V_851 = F_360 ( T_14 , V_850 , V_848 , V_849 ) ;
break;
case 2 :
V_851 = F_360 ( V_853 , V_850 , V_848 , V_849 ) ;
break;
case 4 :
V_851 = F_360 ( T_1 , V_850 , V_848 , V_849 ) ;
break;
case 8 :
V_851 = F_361 ( V_850 , V_848 , V_849 ) ;
break;
default:
F_25 () ;
}
F_362 ( V_850 ) ;
F_363 ( V_388 ) ;
if ( ! V_851 )
return V_854 ;
F_190 ( V_2 -> V_100 , V_419 >> V_105 ) ;
F_344 ( V_2 , V_419 , V_849 , V_810 ) ;
return V_811 ;
V_852:
F_364 ( V_855 L_22 ) ;
return F_354 ( V_816 , V_399 , V_849 , V_810 , V_68 ) ;
}
static int F_365 ( struct V_1 * V_2 , void * V_856 )
{
int V_118 ;
if ( V_2 -> V_5 . V_857 . V_858 )
V_118 = F_323 ( V_2 -> V_100 , V_766 , V_2 -> V_5 . V_857 . V_859 ,
V_2 -> V_5 . V_857 . V_516 , V_856 ) ;
else
V_118 = F_320 ( V_2 -> V_100 , V_766 ,
V_2 -> V_5 . V_857 . V_859 , V_2 -> V_5 . V_857 . V_516 ,
V_856 ) ;
return V_118 ;
}
static int F_366 ( struct V_1 * V_2 , int V_516 ,
unsigned short V_859 , void * V_184 ,
unsigned int V_729 , bool V_858 )
{
V_2 -> V_5 . V_857 . V_859 = V_859 ;
V_2 -> V_5 . V_857 . V_858 = V_858 ;
V_2 -> V_5 . V_857 . V_729 = V_729 ;
V_2 -> V_5 . V_857 . V_516 = V_516 ;
if ( ! F_365 ( V_2 , V_2 -> V_5 . V_860 ) ) {
V_2 -> V_5 . V_857 . V_729 = 0 ;
return 1 ;
}
V_2 -> V_827 -> V_842 = V_861 ;
V_2 -> V_827 -> V_862 . V_863 = V_858 ? V_864 : V_865 ;
V_2 -> V_827 -> V_862 . V_516 = V_516 ;
V_2 -> V_827 -> V_862 . V_866 = V_867 * V_106 ;
V_2 -> V_827 -> V_862 . V_729 = V_729 ;
V_2 -> V_827 -> V_862 . V_859 = V_859 ;
return 0 ;
}
static int F_367 ( struct V_815 * V_816 ,
int V_516 , unsigned short V_859 , void * V_184 ,
unsigned int V_729 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
int V_107 ;
if ( V_2 -> V_5 . V_857 . V_729 )
goto V_868;
V_107 = F_366 ( V_2 , V_516 , V_859 , V_184 , V_729 , true ) ;
if ( V_107 ) {
V_868:
memcpy ( V_184 , V_2 -> V_5 . V_860 , V_516 * V_729 ) ;
F_368 ( V_869 , V_859 , V_516 , V_729 , V_2 -> V_5 . V_860 ) ;
V_2 -> V_5 . V_857 . V_729 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_369 ( struct V_815 * V_816 ,
int V_516 , unsigned short V_859 ,
const void * V_184 , unsigned int V_729 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
memcpy ( V_2 -> V_5 . V_860 , V_184 , V_516 * V_729 ) ;
F_368 ( V_870 , V_859 , V_516 , V_729 , V_2 -> V_5 . V_860 ) ;
return F_366 ( V_2 , V_516 , V_859 , ( void * ) V_184 , V_729 , false ) ;
}
static unsigned long F_370 ( struct V_1 * V_2 , int V_803 )
{
return V_74 -> F_370 ( V_2 , V_803 ) ;
}
static void F_371 ( struct V_815 * V_816 , V_167 V_81 )
{
F_372 ( F_334 ( V_816 ) , V_81 ) ;
}
int F_373 ( struct V_1 * V_2 )
{
if ( ! F_239 ( V_2 ) )
return V_811 ;
if ( V_74 -> V_600 () ) {
int V_23 = F_374 () ;
F_242 ( V_23 , V_2 -> V_5 . V_601 ) ;
F_375 ( V_2 -> V_5 . V_601 ,
F_237 , NULL , 1 ) ;
F_376 () ;
F_377 ( V_2 -> V_5 . V_601 ) ;
} else
F_238 () ;
return V_811 ;
}
static void F_378 ( struct V_815 * V_816 )
{
F_373 ( F_334 ( V_816 ) ) ;
}
int F_379 ( struct V_815 * V_816 , int V_183 , unsigned long * V_871 )
{
return F_95 ( F_334 ( V_816 ) , V_183 , V_871 ) ;
}
int F_380 ( struct V_815 * V_816 , int V_183 , unsigned long V_22 )
{
return F_93 ( F_334 ( V_816 ) , V_183 , V_22 ) ;
}
static T_2 F_381 ( T_2 V_872 , T_1 V_873 )
{
return ( V_872 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_873 ;
}
static unsigned long F_382 ( struct V_815 * V_816 , int V_874 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
unsigned long V_22 ;
switch ( V_874 ) {
case 0 :
V_22 = F_58 ( V_2 ) ;
break;
case 2 :
V_22 = V_2 -> V_5 . V_80 ;
break;
case 3 :
V_22 = F_56 ( V_2 ) ;
break;
case 4 :
V_22 = F_73 ( V_2 ) ;
break;
case 8 :
V_22 = F_87 ( V_2 ) ;
break;
default:
F_383 ( L_23 , V_249 , V_874 ) ;
return 0 ;
}
return V_22 ;
}
static int F_384 ( struct V_815 * V_816 , int V_874 , V_167 V_184 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
int V_191 = 0 ;
switch ( V_874 ) {
case 0 :
V_191 = F_57 ( V_2 , F_381 ( F_58 ( V_2 ) , V_184 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_80 = V_184 ;
break;
case 3 :
V_191 = F_80 ( V_2 , V_184 ) ;
break;
case 4 :
V_191 = F_72 ( V_2 , F_381 ( F_73 ( V_2 ) , V_184 ) ) ;
break;
case 8 :
V_191 = F_84 ( V_2 , V_184 ) ;
break;
default:
F_383 ( L_23 , V_249 , V_874 ) ;
V_191 = - 1 ;
}
return V_191 ;
}
static int F_385 ( struct V_815 * V_816 )
{
return V_74 -> V_89 ( F_334 ( V_816 ) ) ;
}
static void F_386 ( struct V_815 * V_816 , struct V_875 * V_876 )
{
V_74 -> V_877 ( F_334 ( V_816 ) , V_876 ) ;
}
static void F_387 ( struct V_815 * V_816 , struct V_875 * V_876 )
{
V_74 -> V_878 ( F_334 ( V_816 ) , V_876 ) ;
}
static void F_388 ( struct V_815 * V_816 , struct V_875 * V_876 )
{
V_74 -> V_879 ( F_334 ( V_816 ) , V_876 ) ;
}
static void F_389 ( struct V_815 * V_816 , struct V_875 * V_876 )
{
V_74 -> V_880 ( F_334 ( V_816 ) , V_876 ) ;
}
static unsigned long F_390 (
struct V_815 * V_816 , int V_803 )
{
return F_370 ( F_334 ( V_816 ) , V_803 ) ;
}
static bool F_391 ( struct V_815 * V_816 , V_853 * V_881 ,
struct V_882 * V_883 , T_1 * V_884 ,
int V_803 )
{
struct V_801 V_802 ;
F_326 ( F_334 ( V_816 ) , & V_802 , V_803 ) ;
* V_881 = V_802 . V_881 ;
if ( V_802 . V_885 ) {
memset ( V_883 , 0 , sizeof( * V_883 ) ) ;
return false ;
}
if ( V_802 . V_886 )
V_802 . V_887 >>= 12 ;
F_392 ( V_883 , V_802 . V_887 ) ;
F_393 ( V_883 , ( unsigned long ) V_802 . V_888 ) ;
#ifdef F_59
if ( V_884 )
* V_884 = V_802 . V_888 >> 32 ;
#endif
V_883 -> type = V_802 . type ;
V_883 -> V_608 = V_802 . V_608 ;
V_883 -> V_889 = V_802 . V_889 ;
V_883 -> V_357 = V_802 . V_890 ;
V_883 -> V_891 = V_802 . V_891 ;
V_883 -> V_892 = V_802 . V_892 ;
V_883 -> V_893 = V_802 . V_185 ;
V_883 -> V_886 = V_802 . V_886 ;
return true ;
}
static void F_394 ( struct V_815 * V_816 , V_853 V_881 ,
struct V_882 * V_883 , T_1 V_884 ,
int V_803 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
struct V_801 V_802 ;
V_802 . V_881 = V_881 ;
V_802 . V_888 = F_395 ( V_883 ) ;
#ifdef F_59
V_802 . V_888 |= ( ( T_2 ) V_884 ) << 32 ;
#endif
V_802 . V_887 = F_396 ( V_883 ) ;
if ( V_883 -> V_886 )
V_802 . V_887 = ( V_802 . V_887 << 12 ) | 0xfff ;
V_802 . type = V_883 -> type ;
V_802 . V_889 = V_883 -> V_889 ;
V_802 . V_185 = V_883 -> V_893 ;
V_802 . V_608 = V_883 -> V_608 ;
V_802 . V_892 = V_883 -> V_892 ;
V_802 . V_886 = V_883 -> V_886 ;
V_802 . V_891 = V_883 -> V_891 ;
V_802 . V_890 = V_883 -> V_357 ;
V_802 . V_885 = ! V_802 . V_890 ;
V_802 . V_894 = 0 ;
F_325 ( V_2 , & V_802 , V_803 ) ;
return;
}
static int F_397 ( struct V_815 * V_816 ,
T_1 V_489 , T_2 * V_490 )
{
return F_213 ( F_334 ( V_816 ) , V_489 , V_490 ) ;
}
static int F_398 ( struct V_815 * V_816 ,
T_1 V_489 , T_2 V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = V_38 ;
V_21 . V_142 = V_489 ;
V_21 . V_40 = false ;
return F_106 ( F_334 ( V_816 ) , & V_21 ) ;
}
static int F_399 ( struct V_815 * V_816 ,
T_1 V_895 )
{
return F_400 ( F_334 ( V_816 ) , V_895 ) ;
}
static int F_401 ( struct V_815 * V_816 ,
T_1 V_895 , T_2 * V_490 )
{
return F_99 ( F_334 ( V_816 ) , V_895 , V_490 ) ;
}
static void F_402 ( struct V_815 * V_816 )
{
F_334 ( V_816 ) -> V_5 . V_896 = 1 ;
}
static void F_403 ( struct V_815 * V_816 )
{
F_206 () ;
F_404 ( F_334 ( V_816 ) ) ;
F_405 () ;
}
static void F_406 ( struct V_815 * V_816 )
{
F_207 () ;
}
static int F_407 ( struct V_815 * V_816 ,
struct V_897 * V_898 ,
enum V_899 V_900 )
{
return V_74 -> V_901 ( F_334 ( V_816 ) , V_898 , V_900 ) ;
}
static void F_408 ( struct V_815 * V_816 ,
T_1 * V_902 , T_1 * V_903 , T_1 * V_194 , T_1 * V_202 )
{
V_678 ( F_334 ( V_816 ) , V_902 , V_903 , V_194 , V_202 ) ;
}
static V_167 F_409 ( struct V_815 * V_816 , unsigned V_904 )
{
return F_98 ( F_334 ( V_816 ) , V_904 ) ;
}
static void F_410 ( struct V_815 * V_816 , unsigned V_904 , V_167 V_184 )
{
F_100 ( F_334 ( V_816 ) , V_904 , V_184 ) ;
}
static void F_411 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_905 = V_74 -> V_636 ( V_2 ) ;
if ( V_905 & V_28 )
V_28 = 0 ;
if ( F_148 ( V_905 || V_28 ) ) {
V_74 -> V_647 ( V_2 , V_28 ) ;
if ( ! V_28 )
F_30 ( V_67 , V_2 ) ;
}
}
static void F_412 ( struct V_1 * V_2 )
{
struct V_815 * V_816 = & V_2 -> V_5 . V_906 ;
if ( V_816 -> V_68 . V_41 == V_42 )
F_37 ( V_2 , & V_816 -> V_68 ) ;
else if ( V_816 -> V_68 . V_907 )
F_36 ( V_2 , V_816 -> V_68 . V_41 ,
V_816 -> V_68 . V_62 ) ;
else
F_31 ( V_2 , V_816 -> V_68 . V_41 ) ;
}
static void F_413 ( struct V_1 * V_2 )
{
struct V_815 * V_816 = & V_2 -> V_5 . V_906 ;
int V_131 , V_132 ;
V_74 -> V_133 ( V_2 , & V_131 , & V_132 ) ;
V_816 -> V_908 = F_414 ( V_2 ) ;
V_816 -> V_909 = F_415 ( V_2 ) ;
V_816 -> V_307 = ( ! F_416 ( V_2 ) ) ? V_910 :
( V_816 -> V_908 & V_911 ) ? V_912 :
( V_132 && F_53 ( V_2 ) ) ? V_913 :
V_131 ? V_914 :
V_915 ;
V_816 -> V_916 = F_417 ( V_2 ) ;
F_418 ( V_816 ) ;
V_2 -> V_5 . V_917 = false ;
}
int F_419 ( struct V_1 * V_2 , int V_613 , int V_918 )
{
struct V_815 * V_816 = & V_2 -> V_5 . V_906 ;
int V_107 ;
F_413 ( V_2 ) ;
V_816 -> V_919 = 2 ;
V_816 -> V_920 = 2 ;
V_816 -> V_921 = V_816 -> V_909 + V_918 ;
V_107 = F_420 ( V_816 , V_613 ) ;
if ( V_107 != V_811 )
return V_922 ;
V_816 -> V_909 = V_816 -> V_921 ;
F_421 ( V_2 , V_816 -> V_909 ) ;
F_422 ( V_2 , V_816 -> V_908 ) ;
if ( V_613 == V_51 )
V_2 -> V_5 . V_639 = 0 ;
else
V_2 -> V_5 . V_633 . V_69 = false ;
return V_923 ;
}
static int F_423 ( struct V_1 * V_2 )
{
int V_118 = V_923 ;
++ V_2 -> V_78 . V_924 ;
F_424 ( V_2 ) ;
if ( ! F_417 ( V_2 ) ) {
V_2 -> V_827 -> V_842 = V_925 ;
V_2 -> V_827 -> V_926 . V_927 = V_928 ;
V_2 -> V_827 -> V_926 . V_929 = 0 ;
V_118 = V_922 ;
}
F_31 ( V_2 , V_192 ) ;
return V_118 ;
}
static bool F_425 ( struct V_1 * V_2 , T_16 V_80 ,
bool V_930 ,
int V_931 )
{
T_6 V_419 = V_80 ;
T_17 V_932 ;
if ( V_931 & V_933 )
return false ;
if ( ! V_2 -> V_5 . V_85 . V_934 ) {
V_419 = F_330 ( V_2 , V_80 , NULL ) ;
if ( V_419 == V_98 )
return true ;
}
V_932 = F_426 ( V_2 -> V_100 , F_45 ( V_419 ) ) ;
if ( F_427 ( V_932 ) )
return false ;
F_428 ( V_932 ) ;
if ( V_2 -> V_5 . V_85 . V_934 ) {
unsigned int V_935 ;
F_139 ( & V_2 -> V_100 -> V_746 ) ;
V_935 = V_2 -> V_100 -> V_5 . V_935 ;
F_140 ( & V_2 -> V_100 -> V_746 ) ;
if ( V_935 )
F_429 ( V_2 -> V_100 , F_45 ( V_419 ) ) ;
return true ;
}
F_429 ( V_2 -> V_100 , F_45 ( V_419 ) ) ;
return ! V_930 ;
}
static bool F_430 ( struct V_815 * V_816 ,
unsigned long V_80 , int V_931 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
unsigned long V_936 , V_937 , V_419 = V_80 ;
V_936 = V_2 -> V_5 . V_936 ;
V_937 = V_2 -> V_5 . V_937 ;
V_2 -> V_5 . V_936 = V_2 -> V_5 . V_937 = 0 ;
if ( ! ( V_931 & V_938 ) )
return false ;
if ( F_431 ( V_816 ) )
return false ;
if ( V_816 -> V_909 == V_936 && V_937 == V_80 )
return false ;
V_2 -> V_5 . V_936 = V_816 -> V_909 ;
V_2 -> V_5 . V_937 = V_80 ;
if ( ! V_2 -> V_5 . V_85 . V_934 )
V_419 = F_330 ( V_2 , V_80 , NULL ) ;
F_429 ( V_2 -> V_100 , F_45 ( V_419 ) ) ;
return true ;
}
static int F_432 ( unsigned long V_399 , T_1 type , T_1 V_174 ,
unsigned long * V_185 )
{
T_1 V_173 = 0 ;
int V_3 ;
T_1 V_939 , V_940 ;
V_939 = V_174 ;
V_940 = V_174 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_939 >>= 2 , V_940 >>= 4 )
if ( ( V_939 & 3 ) && ( V_940 & 15 ) == type && V_185 [ V_3 ] == V_399 )
V_173 |= ( 1 << V_3 ) ;
return V_173 ;
}
static void F_433 ( struct V_1 * V_2 , unsigned long V_941 , int * V_118 )
{
struct V_942 * V_942 = V_2 -> V_827 ;
if ( F_148 ( V_941 & V_943 ) ) {
if ( V_2 -> V_170 & V_944 ) {
V_942 -> V_945 . V_5 . V_173 = V_946 | V_181 |
V_182 ;
V_942 -> V_945 . V_5 . V_947 = V_2 -> V_5 . V_948 ;
V_942 -> V_945 . V_5 . V_68 = V_53 ;
V_942 -> V_842 = V_949 ;
* V_118 = V_950 ;
} else {
V_2 -> V_5 . V_906 . V_908 &= ~ V_943 ;
V_2 -> V_5 . V_173 &= ~ 15 ;
V_2 -> V_5 . V_173 |= V_946 | V_182 ;
F_31 ( V_2 , V_53 ) ;
}
}
}
static bool F_434 ( struct V_1 * V_2 , int * V_118 )
{
struct V_942 * V_942 = V_2 -> V_827 ;
unsigned long V_909 = V_2 -> V_5 . V_906 . V_909 ;
T_1 V_173 = 0 ;
if ( F_148 ( V_2 -> V_170 & V_171 ) &&
( V_2 -> V_5 . V_175 & V_179 ) ) {
V_173 = F_432 ( V_909 , 0 ,
V_2 -> V_5 . V_175 ,
V_2 -> V_5 . V_186 ) ;
if ( V_173 != 0 ) {
V_942 -> V_945 . V_5 . V_173 = V_173 | V_181 | V_182 ;
V_942 -> V_945 . V_5 . V_947 = F_415 ( V_2 ) +
F_370 ( V_2 , V_951 ) ;
V_942 -> V_945 . V_5 . V_68 = V_53 ;
V_942 -> V_842 = V_949 ;
* V_118 = V_950 ;
return true ;
}
}
if ( F_148 ( V_2 -> V_5 . V_174 & V_179 ) &&
! ( F_414 ( V_2 ) & V_952 ) ) {
V_173 = F_432 ( V_909 , 0 ,
V_2 -> V_5 . V_174 ,
V_2 -> V_5 . V_185 ) ;
if ( V_173 != 0 ) {
V_2 -> V_5 . V_173 &= ~ 15 ;
V_2 -> V_5 . V_173 |= V_173 | V_182 ;
F_31 ( V_2 , V_53 ) ;
* V_118 = V_923 ;
return true ;
}
}
return false ;
}
int F_435 ( struct V_1 * V_2 ,
unsigned long V_80 ,
int V_931 ,
void * V_953 ,
int V_954 )
{
int V_118 ;
struct V_815 * V_816 = & V_2 -> V_5 . V_906 ;
bool V_514 = true ;
bool V_955 = V_2 -> V_5 . V_930 ;
V_2 -> V_5 . V_930 = false ;
F_436 ( V_2 ) ;
if ( ! ( V_931 & V_956 ) ) {
F_413 ( V_2 ) ;
if ( F_434 ( V_2 , & V_118 ) )
return V_118 ;
V_816 -> V_957 = 0 ;
V_816 -> V_958 = false ;
V_816 -> V_959 = false ;
V_816 -> V_960 = V_931 & V_961 ;
V_118 = F_437 ( V_816 , V_953 , V_954 ) ;
F_438 ( V_2 ) ;
++ V_2 -> V_78 . V_962 ;
if ( V_118 != V_963 ) {
if ( V_931 & V_961 )
return V_922 ;
if ( F_425 ( V_2 , V_80 , V_955 ,
V_931 ) )
return V_923 ;
if ( V_931 & V_964 )
return V_922 ;
return F_423 ( V_2 ) ;
}
}
if ( V_931 & V_964 ) {
F_421 ( V_2 , V_816 -> V_921 ) ;
if ( V_816 -> V_908 & V_952 )
F_422 ( V_2 , V_816 -> V_908 & ~ V_952 ) ;
return V_923 ;
}
if ( F_430 ( V_816 , V_80 , V_931 ) )
return V_923 ;
if ( V_2 -> V_5 . V_917 ) {
V_2 -> V_5 . V_917 = false ;
F_439 ( V_816 ) ;
}
V_965:
V_118 = F_440 ( V_816 ) ;
if ( V_118 == V_966 )
return V_923 ;
if ( V_118 == V_967 ) {
if ( F_425 ( V_2 , V_80 , V_955 ,
V_931 ) )
return V_923 ;
return F_423 ( V_2 ) ;
}
if ( V_816 -> V_958 ) {
F_412 ( V_2 ) ;
V_118 = V_923 ;
} else if ( V_2 -> V_5 . V_857 . V_729 ) {
if ( ! V_2 -> V_5 . V_857 . V_858 ) {
V_2 -> V_5 . V_857 . V_729 = 0 ;
} else {
V_514 = false ;
V_2 -> V_5 . V_968 = V_969 ;
}
V_118 = V_950 ;
} else if ( V_2 -> V_838 ) {
if ( ! V_2 -> V_841 )
V_514 = false ;
V_118 = V_950 ;
V_2 -> V_5 . V_968 = V_970 ;
} else if ( V_118 == V_971 )
goto V_965;
else
V_118 = V_923 ;
if ( V_514 ) {
unsigned long V_941 = V_74 -> V_972 ( V_2 ) ;
F_411 ( V_2 , V_816 -> V_957 ) ;
V_2 -> V_5 . V_973 = false ;
F_421 ( V_2 , V_816 -> V_909 ) ;
if ( V_118 == V_923 )
F_433 ( V_2 , V_941 , & V_118 ) ;
F_441 ( V_2 , V_816 -> V_908 ) ;
if ( F_148 ( ( V_816 -> V_908 & ~ V_941 ) & V_974 ) )
F_30 ( V_67 , V_2 ) ;
} else
V_2 -> V_5 . V_973 = true ;
return V_118 ;
}
int F_442 ( struct V_1 * V_2 , int V_516 , unsigned short V_859 )
{
unsigned long V_184 = F_98 ( V_2 , V_196 ) ;
int V_107 = F_369 ( & V_2 -> V_5 . V_906 ,
V_516 , V_859 , & V_184 , 1 ) ;
V_2 -> V_5 . V_857 . V_729 = 0 ;
return V_107 ;
}
static void F_443 ( void * V_898 )
{
F_444 ( V_322 , 0 ) ;
}
static void F_445 ( void * V_38 )
{
struct V_975 * V_976 = V_38 ;
unsigned long V_252 = 0 ;
if ( V_38 )
V_252 = V_976 -> V_849 ;
else if ( ! F_234 ( V_977 ) )
V_252 = F_446 ( F_447 () ) ;
if ( ! V_252 )
V_252 = V_261 ;
F_444 ( V_322 , V_252 ) ;
}
static int F_448 ( struct V_978 * V_979 , unsigned long V_184 ,
void * V_38 )
{
struct V_975 * V_976 = V_38 ;
struct V_100 * V_100 ;
struct V_1 * V_2 ;
int V_3 , V_980 = 0 ;
if ( V_184 == V_981 && V_976 -> V_848 > V_976 -> V_849 )
return 0 ;
if ( V_184 == V_982 && V_976 -> V_848 < V_976 -> V_849 )
return 0 ;
F_243 ( V_976 -> V_23 , F_445 , V_976 , 1 ) ;
F_139 ( & V_983 ) ;
F_449 (kvm, &vm_list, vm_list) {
F_156 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_976 -> V_23 )
continue;
F_30 ( V_313 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_980 = 1 ;
}
}
F_140 ( & V_983 ) ;
if ( V_976 -> V_848 < V_976 -> V_849 && V_980 ) {
F_243 ( V_976 -> V_23 , F_445 , V_976 , 1 ) ;
}
return 0 ;
}
static int F_450 ( struct V_978 * V_984 ,
unsigned long V_985 , void * V_986 )
{
unsigned int V_23 = ( unsigned long ) V_986 ;
switch ( V_985 ) {
case V_987 :
case V_988 :
F_243 ( V_23 , F_445 , NULL , 1 ) ;
break;
case V_989 :
F_243 ( V_23 , F_443 , NULL , 1 ) ;
break;
}
return V_990 ;
}
static void F_451 ( void )
{
int V_23 ;
V_991 = V_261 ;
F_452 () ;
if ( ! F_234 ( V_977 ) ) {
#ifdef F_453
struct V_992 V_993 ;
memset ( & V_993 , 0 , sizeof( V_993 ) ) ;
V_23 = F_374 () ;
F_454 ( & V_993 , V_23 ) ;
if ( V_993 . V_994 . V_995 )
V_991 = V_993 . V_994 . V_995 ;
F_376 () ;
#endif
F_455 ( & V_996 ,
V_997 ) ;
}
F_121 ( L_24 , V_991 ) ;
F_456 (cpu)
F_243 ( V_23 , F_445 , NULL , 1 ) ;
F_457 ( & V_998 ) ;
F_458 () ;
}
int F_459 ( void )
{
return F_460 ( V_999 ) != NULL ;
}
static int F_461 ( void )
{
int V_1000 = 3 ;
if ( F_460 ( V_999 ) )
V_1000 = V_74 -> V_89 ( F_460 ( V_999 ) ) ;
return V_1000 != 0 ;
}
static unsigned long F_462 ( void )
{
unsigned long V_1001 = 0 ;
if ( F_460 ( V_999 ) )
V_1001 = F_415 ( F_460 ( V_999 ) ) ;
return V_1001 ;
}
void F_463 ( struct V_1 * V_2 )
{
F_444 ( V_999 , V_2 ) ;
}
void F_464 ( struct V_1 * V_2 )
{
F_444 ( V_999 , NULL ) ;
}
static void F_465 ( void )
{
T_2 V_28 ;
int V_1002 = V_1003 . V_1004 ;
V_28 = ( ( 1ull << ( 51 - V_1002 + 1 ) ) - 1 ) << V_1002 ;
V_28 |= 0x3ull << 62 ;
V_28 |= 1ull ;
#ifdef F_59
if ( V_1002 == 52 )
V_28 &= ~ 1ull ;
#endif
F_466 ( V_28 ) ;
}
static void F_467 ( struct V_335 * V_336 )
{
struct V_100 * V_100 ;
struct V_1 * V_2 ;
int V_3 ;
F_139 ( & V_983 ) ;
F_449 (kvm, &vm_list, vm_list)
F_156 (i, vcpu, kvm)
F_157 ( V_277 , & V_2 -> V_314 ) ;
F_152 ( & V_312 , 0 ) ;
F_140 ( & V_983 ) ;
}
static int F_468 ( struct V_978 * V_979 , unsigned long V_1005 ,
void * V_1006 )
{
struct V_212 * V_272 = & V_212 ;
struct V_210 * V_211 = V_1006 ;
F_108 ( V_211 ) ;
if ( V_272 -> clock . V_219 != V_275 &&
F_131 ( & V_312 ) != 0 )
F_469 ( V_1007 , & V_1008 ) ;
return 0 ;
}
int F_470 ( void * V_1009 )
{
int V_118 ;
struct V_74 * V_830 = V_1009 ;
if ( V_74 ) {
F_10 ( V_26 L_25 ) ;
V_118 = - V_764 ;
goto V_112;
}
if ( ! V_830 -> V_1010 () ) {
F_10 ( V_26 L_26 ) ;
V_118 = - V_1011 ;
goto V_112;
}
if ( V_830 -> V_1012 () ) {
F_10 ( V_26 L_27 ) ;
V_118 = - V_1011 ;
goto V_112;
}
V_118 = - V_390 ;
V_25 = F_471 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_112;
}
V_118 = F_472 () ;
if ( V_118 )
goto V_1013;
F_465 () ;
V_74 = V_830 ;
F_315 () ;
F_473 ( V_1014 , V_1015 ,
V_1016 , V_1017 , 0 ) ;
F_451 () ;
F_474 ( & V_1018 ) ;
if ( V_572 )
V_141 = F_475 ( V_139 ) ;
F_476 () ;
#ifdef F_59
F_477 ( & V_1019 ) ;
#endif
return 0 ;
V_1013:
F_478 ( V_25 ) ;
V_112:
return V_118 ;
}
void F_479 ( void )
{
F_480 ( & V_1018 ) ;
if ( ! F_234 ( V_977 ) )
F_481 ( & V_996 ,
V_997 ) ;
F_482 ( & V_998 ) ;
#ifdef F_59
F_483 ( & V_1019 ) ;
#endif
V_74 = NULL ;
F_484 () ;
F_478 ( V_25 ) ;
}
int F_485 ( struct V_1 * V_2 )
{
++ V_2 -> V_78 . V_1020 ;
if ( F_85 ( V_2 -> V_100 ) ) {
V_2 -> V_5 . V_1021 = V_1022 ;
return 1 ;
} else {
V_2 -> V_827 -> V_842 = V_1023 ;
return 0 ;
}
}
int F_486 ( struct V_1 * V_2 )
{
T_2 V_1024 , V_1025 , V_1026 , V_107 ;
T_18 V_1027 , V_1028 , V_1029 , V_191 = V_1030 , V_1031 = 0 ;
bool V_1032 , V_1033 ;
if ( V_74 -> V_89 ( V_2 ) != 0 || ! F_416 ( V_2 ) ) {
F_31 ( V_2 , V_192 ) ;
return 0 ;
}
V_1033 = F_487 ( V_2 ) ;
if ( ! V_1033 ) {
V_1024 = ( ( T_2 ) F_98 ( V_2 , V_197 ) << 32 ) |
( F_98 ( V_2 , V_196 ) & 0xffffffff ) ;
V_1025 = ( ( T_2 ) F_98 ( V_2 , V_1034 ) << 32 ) |
( F_98 ( V_2 , V_195 ) & 0xffffffff ) ;
V_1026 = ( ( T_2 ) F_98 ( V_2 , V_1035 ) << 32 ) |
( F_98 ( V_2 , V_1036 ) & 0xffffffff ) ;
}
#ifdef F_59
else {
V_1024 = F_98 ( V_2 , V_195 ) ;
V_1025 = F_98 ( V_2 , V_197 ) ;
V_1026 = F_98 ( V_2 , V_1037 ) ;
}
#endif
V_1027 = V_1024 & 0xffff ;
V_1032 = ( V_1024 >> 16 ) & 0x1 ;
V_1029 = ( V_1024 >> 32 ) & 0xfff ;
V_1028 = ( V_1024 >> 48 ) & 0xfff ;
F_488 ( V_1027 , V_1032 , V_1029 , V_1028 , V_1025 , V_1026 ) ;
switch ( V_1027 ) {
case V_1038 :
F_489 ( V_2 ) ;
break;
default:
V_191 = V_1039 ;
break;
}
V_107 = V_191 | ( ( ( T_2 ) V_1031 & 0xfff ) << 32 ) ;
if ( V_1033 ) {
F_100 ( V_2 , V_196 , V_107 ) ;
} else {
F_100 ( V_2 , V_197 , V_107 >> 32 ) ;
F_100 ( V_2 , V_196 , V_107 & 0xffffffff ) ;
}
return 1 ;
}
static void F_490 ( struct V_100 * V_100 , unsigned long V_284 , int V_1040 )
{
struct V_1041 V_1042 ;
V_1042 . V_1043 = 0 ;
V_1042 . V_1044 = 0 ;
V_1042 . V_1045 = V_1040 ;
V_1042 . V_1046 = V_1047 ;
F_491 ( V_100 , 0 , & V_1042 , NULL ) ;
}
int F_492 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1048 , V_1049 , V_1050 , V_1051 , V_107 ;
int V_1052 , V_118 = 1 ;
if ( F_184 ( V_2 -> V_100 ) )
return F_486 ( V_2 ) ;
V_16 = F_98 ( V_2 , V_196 ) ;
V_1048 = F_98 ( V_2 , V_1034 ) ;
V_1049 = F_98 ( V_2 , V_195 ) ;
V_1050 = F_98 ( V_2 , V_197 ) ;
V_1051 = F_98 ( V_2 , V_1036 ) ;
F_493 ( V_16 , V_1048 , V_1049 , V_1050 , V_1051 ) ;
V_1052 = F_487 ( V_2 ) ;
if ( ! V_1052 ) {
V_16 &= 0xFFFFFFFF ;
V_1048 &= 0xFFFFFFFF ;
V_1049 &= 0xFFFFFFFF ;
V_1050 &= 0xFFFFFFFF ;
V_1051 &= 0xFFFFFFFF ;
}
if ( V_74 -> V_89 ( V_2 ) != 0 ) {
V_107 = - V_1053 ;
goto V_112;
}
switch ( V_16 ) {
case V_1054 :
V_107 = 0 ;
break;
case V_1055 :
F_490 ( V_2 -> V_100 , V_1048 , V_1049 ) ;
V_107 = 0 ;
break;
default:
V_107 = - V_1056 ;
break;
}
V_112:
if ( ! V_1052 )
V_107 = ( T_1 ) V_107 ;
F_100 ( V_2 , V_196 , V_107 ) ;
++ V_2 -> V_78 . V_1057 ;
return V_118 ;
}
static int F_494 ( struct V_815 * V_816 )
{
struct V_1 * V_2 = F_334 ( V_816 ) ;
char V_1058 [ 3 ] ;
unsigned long V_1059 = F_415 ( V_2 ) ;
V_74 -> V_402 ( V_2 , V_1058 ) ;
return F_354 ( V_816 , V_1059 , V_1058 , 3 , NULL ) ;
}
static int F_495 ( struct V_1 * V_2 )
{
return ( ! F_85 ( V_2 -> V_100 ) && ! F_496 ( V_2 ) &&
V_2 -> V_827 -> V_1060 &&
F_497 ( V_2 ) ) ;
}
static void F_498 ( struct V_1 * V_2 )
{
struct V_942 * V_942 = V_2 -> V_827 ;
V_942 -> V_1061 = ( F_414 ( V_2 ) & V_974 ) != 0 ;
V_942 -> V_168 = F_87 ( V_2 ) ;
V_942 -> V_31 = F_19 ( V_2 ) ;
if ( F_85 ( V_2 -> V_100 ) )
V_942 -> V_1062 = 1 ;
else
V_942 -> V_1062 =
F_497 ( V_2 ) &&
! F_496 ( V_2 ) &&
! F_499 ( V_2 ) ;
}
static void F_252 ( struct V_1 * V_2 )
{
int V_1063 , V_1064 ;
if ( ! V_74 -> F_252 )
return;
if ( ! V_2 -> V_5 . V_611 )
return;
if ( ! V_2 -> V_5 . V_611 -> V_687 )
V_1063 = F_500 ( V_2 ) ;
else
V_1063 = - 1 ;
if ( V_1063 != - 1 )
V_1063 >>= 4 ;
V_1064 = F_88 ( V_2 ) ;
V_74 -> F_252 ( V_2 , V_1064 , V_1063 ) ;
}
static int F_501 ( struct V_1 * V_2 , bool V_1065 )
{
int V_118 ;
if ( V_2 -> V_5 . V_68 . V_69 ) {
F_502 ( V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ) ;
if ( F_27 ( V_2 -> V_5 . V_68 . V_16 ) == V_60 )
F_441 ( V_2 , F_414 ( V_2 ) |
V_952 ) ;
V_74 -> V_1066 ( V_2 , V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ,
V_2 -> V_5 . V_68 . V_63 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_638 ) {
V_74 -> V_1067 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_633 . V_69 ) {
V_74 -> V_1068 ( V_2 ) ;
return 0 ;
}
if ( F_417 ( V_2 ) && V_74 -> V_1069 ) {
V_118 = V_74 -> V_1069 ( V_2 , V_1065 ) ;
if ( V_118 != 0 )
return V_118 ;
}
if ( V_2 -> V_5 . V_639 ) {
if ( V_74 -> V_1070 ( V_2 ) ) {
-- V_2 -> V_5 . V_639 ;
V_2 -> V_5 . V_638 = true ;
V_74 -> V_1067 ( V_2 ) ;
}
} else if ( F_503 ( V_2 ) ) {
if ( F_417 ( V_2 ) && V_74 -> V_1069 ) {
V_118 = V_74 -> V_1069 ( V_2 , V_1065 ) ;
if ( V_118 != 0 )
return V_118 ;
}
if ( V_74 -> V_1071 ( V_2 ) ) {
F_254 ( V_2 , F_504 ( V_2 ) ,
false ) ;
V_74 -> V_1068 ( V_2 ) ;
}
}
return 0 ;
}
static void F_260 ( struct V_1 * V_2 )
{
unsigned V_887 = 2 ;
if ( V_74 -> V_641 ( V_2 ) || V_2 -> V_5 . V_638 )
V_887 = 1 ;
V_2 -> V_5 . V_639 += F_505 ( & V_2 -> V_5 . V_86 , 0 ) ;
V_2 -> V_5 . V_639 = F_318 ( V_2 -> V_5 . V_639 , V_887 ) ;
F_30 ( V_67 , V_2 ) ;
}
static void F_506 ( struct V_1 * V_2 )
{
T_2 V_1072 [ 4 ] ;
T_1 V_1073 [ 8 ] ;
if ( ! F_507 ( V_2 -> V_5 . V_611 ) )
return;
memset ( V_1072 , 0 , 32 ) ;
memset ( V_1073 , 0 , 32 ) ;
F_508 ( V_2 , V_1072 , V_1073 ) ;
V_74 -> V_1074 ( V_2 , V_1072 ) ;
F_509 ( V_2 , V_1073 ) ;
}
static int F_510 ( struct V_1 * V_2 )
{
int V_118 ;
bool V_1065 = ! F_85 ( V_2 -> V_100 ) &&
V_2 -> V_827 -> V_1060 ;
bool V_1075 = false ;
if ( V_2 -> V_314 ) {
if ( F_511 ( V_1076 , V_2 ) )
F_512 ( V_2 ) ;
if ( F_511 ( V_1077 , V_2 ) )
F_513 ( V_2 ) ;
if ( F_511 ( V_277 , V_2 ) )
F_154 ( V_2 -> V_100 ) ;
if ( F_511 ( V_459 , V_2 ) )
F_170 ( V_2 ) ;
if ( F_511 ( V_313 , V_2 ) ) {
V_118 = F_159 ( V_2 ) ;
if ( F_148 ( V_118 ) )
goto V_112;
}
if ( F_511 ( V_1078 , V_2 ) )
F_81 ( V_2 ) ;
if ( F_511 ( V_1079 , V_2 ) )
V_74 -> V_1080 ( V_2 ) ;
if ( F_511 ( V_1081 , V_2 ) ) {
V_2 -> V_827 -> V_842 = V_1082 ;
V_118 = 0 ;
goto V_112;
}
if ( F_511 ( V_72 , V_2 ) ) {
V_2 -> V_827 -> V_842 = V_1083 ;
V_118 = 0 ;
goto V_112;
}
if ( F_511 ( V_1084 , V_2 ) ) {
V_2 -> V_1085 = 0 ;
V_74 -> V_1086 ( V_2 ) ;
}
if ( F_511 ( V_1087 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1088 = true ;
V_118 = 1 ;
goto V_112;
}
if ( F_511 ( V_464 , V_2 ) )
F_201 ( V_2 ) ;
if ( F_511 ( V_87 , V_2 ) )
F_260 ( V_2 ) ;
if ( F_511 ( V_1089 , V_2 ) )
F_514 ( V_2 ) ;
if ( F_511 ( V_1090 , V_2 ) )
F_515 ( V_2 ) ;
if ( F_511 ( V_1091 , V_2 ) )
F_506 ( V_2 ) ;
}
if ( F_511 ( V_67 , V_2 ) || V_1065 ) {
F_516 ( V_2 ) ;
if ( V_2 -> V_5 . V_1021 == V_1092 ) {
V_118 = 1 ;
goto V_112;
}
if ( F_501 ( V_2 , V_1065 ) != 0 )
V_1075 = true ;
else if ( V_2 -> V_5 . V_639 )
V_74 -> V_1093 ( V_2 ) ;
else if ( F_503 ( V_2 ) || V_1065 )
V_74 -> V_1094 ( V_2 ) ;
if ( F_517 ( V_2 ) ) {
if ( V_74 -> V_1095 )
V_74 -> V_1095 ( V_2 ,
F_500 ( V_2 ) ) ;
F_252 ( V_2 ) ;
F_518 ( V_2 ) ;
}
}
V_118 = F_519 ( V_2 ) ;
if ( F_148 ( V_118 ) ) {
goto V_1096;
}
F_206 () ;
V_74 -> V_1097 ( V_2 ) ;
if ( V_2 -> V_1085 )
F_404 ( V_2 ) ;
F_66 ( V_2 ) ;
V_2 -> V_307 = V_1098 ;
F_227 ( & V_2 -> V_100 -> V_511 , V_2 -> V_1099 ) ;
F_520 () ;
F_313 () ;
if ( V_2 -> V_307 == V_1100 || V_2 -> V_314
|| F_521 () || F_522 ( V_425 ) ) {
V_2 -> V_307 = V_1101 ;
F_14 () ;
F_314 () ;
F_207 () ;
V_2 -> V_1099 = F_226 ( & V_2 -> V_100 -> V_511 ) ;
V_118 = 1 ;
goto V_1096;
}
if ( V_1075 )
F_523 ( V_2 -> V_23 ) ;
F_524 () ;
if ( F_148 ( V_2 -> V_5 . V_177 ) ) {
F_525 ( 0 , 7 ) ;
F_525 ( V_2 -> V_5 . V_186 [ 0 ] , 0 ) ;
F_525 ( V_2 -> V_5 . V_186 [ 1 ] , 1 ) ;
F_525 ( V_2 -> V_5 . V_186 [ 2 ] , 2 ) ;
F_525 ( V_2 -> V_5 . V_186 [ 3 ] , 3 ) ;
F_525 ( V_2 -> V_5 . V_173 , 6 ) ;
}
F_526 ( V_2 -> V_278 ) ;
V_74 -> V_827 ( V_2 ) ;
if ( F_148 ( V_2 -> V_5 . V_177 & V_1102 ) ) {
int V_3 ;
F_28 ( V_2 -> V_170 & V_171 ) ;
V_74 -> V_1103 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_1104 ; V_3 ++ )
V_2 -> V_5 . V_186 [ V_3 ] = V_2 -> V_5 . V_185 [ V_3 ] ;
}
if ( F_527 () )
F_528 () ;
V_2 -> V_5 . V_301 = V_74 -> V_323 ( V_2 ,
F_163 () ) ;
V_2 -> V_307 = V_1101 ;
F_14 () ;
V_74 -> V_1105 ( V_2 ) ;
++ V_2 -> V_78 . V_1106 ;
F_529 () ;
F_530 () ;
F_207 () ;
V_2 -> V_1099 = F_226 ( & V_2 -> V_100 -> V_511 ) ;
if ( F_148 ( V_1107 == V_1108 ) ) {
unsigned long V_1059 = F_415 ( V_2 ) ;
F_531 ( V_1108 , ( void * ) V_1059 ) ;
}
if ( F_148 ( V_2 -> V_5 . V_1109 ) )
F_30 ( V_313 , V_2 ) ;
if ( V_2 -> V_5 . V_1110 )
F_532 ( V_2 ) ;
V_118 = V_74 -> V_1111 ( V_2 ) ;
return V_118 ;
V_1096:
V_74 -> V_1096 ( V_2 ) ;
if ( F_148 ( V_2 -> V_5 . V_1110 ) )
F_532 ( V_2 ) ;
V_112:
return V_118 ;
}
static int F_533 ( struct V_1 * V_2 )
{
int V_118 ;
struct V_100 * V_100 = V_2 -> V_100 ;
V_2 -> V_1099 = F_226 ( & V_100 -> V_511 ) ;
V_118 = 1 ;
while ( V_118 > 0 ) {
if ( V_2 -> V_5 . V_1021 == V_1112 &&
! V_2 -> V_5 . V_6 . V_1088 )
V_118 = F_510 ( V_2 ) ;
else {
F_227 ( & V_100 -> V_511 , V_2 -> V_1099 ) ;
F_534 ( V_2 ) ;
V_2 -> V_1099 = F_226 ( & V_100 -> V_511 ) ;
if ( F_511 ( V_1113 , V_2 ) ) {
F_516 ( V_2 ) ;
switch( V_2 -> V_5 . V_1021 ) {
case V_1022 :
V_2 -> V_5 . V_1114 . V_1115 = false ;
V_2 -> V_5 . V_1021 =
V_1112 ;
case V_1112 :
V_2 -> V_5 . V_6 . V_1088 = false ;
break;
case V_1092 :
break;
default:
V_118 = - V_1116 ;
break;
}
}
}
if ( V_118 <= 0 )
break;
F_158 ( V_1117 , & V_2 -> V_314 ) ;
if ( F_535 ( V_2 ) )
F_536 ( V_2 ) ;
if ( F_495 ( V_2 ) ) {
V_118 = - V_1116 ;
V_2 -> V_827 -> V_842 = V_1118 ;
++ V_2 -> V_78 . V_1119 ;
}
F_537 ( V_2 ) ;
if ( F_522 ( V_425 ) ) {
V_118 = - V_1116 ;
V_2 -> V_827 -> V_842 = V_1118 ;
++ V_2 -> V_78 . V_1120 ;
}
if ( F_521 () ) {
F_227 ( & V_100 -> V_511 , V_2 -> V_1099 ) ;
F_538 () ;
V_2 -> V_1099 = F_226 ( & V_100 -> V_511 ) ;
}
}
F_227 ( & V_100 -> V_511 , V_2 -> V_1099 ) ;
return V_118 ;
}
static inline int F_539 ( struct V_1 * V_2 )
{
int V_118 ;
V_2 -> V_1099 = F_226 ( & V_2 -> V_100 -> V_511 ) ;
V_118 = F_540 ( V_2 , V_956 ) ;
F_227 ( & V_2 -> V_100 -> V_511 , V_2 -> V_1099 ) ;
if ( V_118 != V_923 )
return 0 ;
return 1 ;
}
static int V_969 ( struct V_1 * V_2 )
{
F_13 ( ! V_2 -> V_5 . V_857 . V_729 ) ;
return F_539 ( V_2 ) ;
}
static int V_970 ( struct V_1 * V_2 )
{
struct V_942 * V_827 = V_2 -> V_827 ;
struct V_825 * V_826 ;
unsigned V_93 ;
F_13 ( ! V_2 -> V_838 ) ;
V_826 = & V_2 -> V_822 [ V_2 -> V_839 ] ;
V_93 = F_318 ( 8u , V_826 -> V_93 ) ;
if ( ! V_2 -> V_841 )
memcpy ( V_826 -> V_38 , V_827 -> V_828 . V_38 , V_93 ) ;
if ( V_826 -> V_93 <= 8 ) {
V_826 ++ ;
V_2 -> V_839 ++ ;
} else {
V_826 -> V_38 += V_93 ;
V_826 -> V_419 += V_93 ;
V_826 -> V_93 -= V_93 ;
}
if ( V_2 -> V_839 >= V_2 -> V_833 ) {
V_2 -> V_838 = 0 ;
if ( V_2 -> V_841 )
return 1 ;
V_2 -> V_821 = 1 ;
return F_539 ( V_2 ) ;
}
V_827 -> V_842 = V_843 ;
V_827 -> V_828 . V_844 = V_826 -> V_419 ;
if ( V_2 -> V_841 )
memcpy ( V_827 -> V_828 . V_38 , V_826 -> V_38 , F_318 ( 8u , V_826 -> V_93 ) ) ;
V_827 -> V_828 . V_93 = F_318 ( 8u , V_826 -> V_93 ) ;
V_827 -> V_828 . V_840 = V_2 -> V_841 ;
V_2 -> V_5 . V_968 = V_970 ;
return 0 ;
}
int F_541 ( struct V_1 * V_2 , struct V_942 * V_942 )
{
int V_118 ;
T_19 V_1121 ;
if ( ! F_542 ( V_425 ) && F_543 ( V_425 ) )
return - V_390 ;
if ( V_2 -> V_1122 )
F_544 ( V_1123 , & V_2 -> V_1124 , & V_1121 ) ;
if ( F_148 ( V_2 -> V_5 . V_1021 == V_1125 ) ) {
F_534 ( V_2 ) ;
F_516 ( V_2 ) ;
F_158 ( V_1113 , & V_2 -> V_314 ) ;
V_118 = - V_1126 ;
goto V_112;
}
if ( ! F_85 ( V_2 -> V_100 ) ) {
if ( F_84 ( V_2 , V_942 -> V_168 ) != 0 ) {
V_118 = - V_598 ;
goto V_112;
}
}
if ( F_148 ( V_2 -> V_5 . V_968 ) ) {
int (* F_545)( struct V_1 * ) = V_2 -> V_5 . V_968 ;
V_2 -> V_5 . V_968 = NULL ;
V_118 = F_545 ( V_2 ) ;
if ( V_118 <= 0 )
goto V_112;
} else
F_28 ( V_2 -> V_5 . V_857 . V_729 || V_2 -> V_838 ) ;
V_118 = F_533 ( V_2 ) ;
V_112:
F_498 ( V_2 ) ;
if ( V_2 -> V_1122 )
F_544 ( V_1123 , & V_1121 , NULL ) ;
return V_118 ;
}
int F_546 ( struct V_1 * V_2 , struct V_1127 * V_610 )
{
if ( V_2 -> V_5 . V_973 ) {
F_547 ( & V_2 -> V_5 . V_906 ) ;
V_2 -> V_5 . V_973 = false ;
}
V_610 -> V_1128 = F_98 ( V_2 , V_196 ) ;
V_610 -> V_1129 = F_98 ( V_2 , V_1034 ) ;
V_610 -> V_1130 = F_98 ( V_2 , V_195 ) ;
V_610 -> V_1131 = F_98 ( V_2 , V_197 ) ;
V_610 -> V_1132 = F_98 ( V_2 , V_1036 ) ;
V_610 -> V_1133 = F_98 ( V_2 , V_1035 ) ;
V_610 -> V_1134 = F_98 ( V_2 , V_1135 ) ;
V_610 -> V_1136 = F_98 ( V_2 , V_1137 ) ;
#ifdef F_59
V_610 -> V_1138 = F_98 ( V_2 , V_1037 ) ;
V_610 -> V_1139 = F_98 ( V_2 , V_1140 ) ;
V_610 -> V_1141 = F_98 ( V_2 , V_1142 ) ;
V_610 -> V_1143 = F_98 ( V_2 , V_1144 ) ;
V_610 -> V_1145 = F_98 ( V_2 , V_1146 ) ;
V_610 -> V_1147 = F_98 ( V_2 , V_1148 ) ;
V_610 -> V_1149 = F_98 ( V_2 , V_1150 ) ;
V_610 -> V_1151 = F_98 ( V_2 , V_1152 ) ;
#endif
V_610 -> V_1059 = F_415 ( V_2 ) ;
V_610 -> V_941 = F_414 ( V_2 ) ;
return 0 ;
}
int F_548 ( struct V_1 * V_2 , struct V_1127 * V_610 )
{
V_2 -> V_5 . V_917 = true ;
V_2 -> V_5 . V_973 = false ;
F_100 ( V_2 , V_196 , V_610 -> V_1128 ) ;
F_100 ( V_2 , V_1034 , V_610 -> V_1129 ) ;
F_100 ( V_2 , V_195 , V_610 -> V_1130 ) ;
F_100 ( V_2 , V_197 , V_610 -> V_1131 ) ;
F_100 ( V_2 , V_1036 , V_610 -> V_1132 ) ;
F_100 ( V_2 , V_1035 , V_610 -> V_1133 ) ;
F_100 ( V_2 , V_1135 , V_610 -> V_1134 ) ;
F_100 ( V_2 , V_1137 , V_610 -> V_1136 ) ;
#ifdef F_59
F_100 ( V_2 , V_1037 , V_610 -> V_1138 ) ;
F_100 ( V_2 , V_1140 , V_610 -> V_1139 ) ;
F_100 ( V_2 , V_1142 , V_610 -> V_1141 ) ;
F_100 ( V_2 , V_1144 , V_610 -> V_1143 ) ;
F_100 ( V_2 , V_1146 , V_610 -> V_1145 ) ;
F_100 ( V_2 , V_1148 , V_610 -> V_1147 ) ;
F_100 ( V_2 , V_1150 , V_610 -> V_1149 ) ;
F_100 ( V_2 , V_1152 , V_610 -> V_1151 ) ;
#endif
F_421 ( V_2 , V_610 -> V_1059 ) ;
F_422 ( V_2 , V_610 -> V_941 ) ;
V_2 -> V_5 . V_68 . V_69 = false ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
void F_549 ( struct V_1 * V_2 , int * V_185 , int * V_892 )
{
struct V_801 V_1153 ;
F_326 ( V_2 , & V_1153 , V_951 ) ;
* V_185 = V_1153 . V_185 ;
* V_892 = V_1153 . V_892 ;
}
int F_550 ( struct V_1 * V_2 ,
struct V_1154 * V_1155 )
{
struct V_875 V_876 ;
F_326 ( V_2 , & V_1155 -> V_1153 , V_951 ) ;
F_326 ( V_2 , & V_1155 -> V_1156 , V_1157 ) ;
F_326 ( V_2 , & V_1155 -> V_1158 , V_1159 ) ;
F_326 ( V_2 , & V_1155 -> V_1160 , V_1161 ) ;
F_326 ( V_2 , & V_1155 -> V_1162 , V_1163 ) ;
F_326 ( V_2 , & V_1155 -> V_1164 , V_1165 ) ;
F_326 ( V_2 , & V_1155 -> V_1166 , V_1167 ) ;
F_326 ( V_2 , & V_1155 -> V_1168 , V_1169 ) ;
V_74 -> V_878 ( V_2 , & V_876 ) ;
V_1155 -> V_1170 . V_887 = V_876 . V_516 ;
V_1155 -> V_1170 . V_888 = V_876 . V_81 ;
V_74 -> V_877 ( V_2 , & V_876 ) ;
V_1155 -> V_1171 . V_887 = V_876 . V_516 ;
V_1155 -> V_1171 . V_888 = V_876 . V_81 ;
V_1155 -> V_119 = F_58 ( V_2 ) ;
V_1155 -> V_80 = V_2 -> V_5 . V_80 ;
V_1155 -> V_103 = F_56 ( V_2 ) ;
V_1155 -> V_153 = F_73 ( V_2 ) ;
V_1155 -> V_168 = F_87 ( V_2 ) ;
V_1155 -> V_129 = V_2 -> V_5 . V_129 ;
V_1155 -> V_31 = F_19 ( V_2 ) ;
memset ( V_1155 -> V_1172 , 0 , sizeof V_1155 -> V_1172 ) ;
if ( V_2 -> V_5 . V_633 . V_69 && ! V_2 -> V_5 . V_633 . V_634 )
F_157 ( V_2 -> V_5 . V_633 . V_16 ,
( unsigned long * ) V_1155 -> V_1172 ) ;
return 0 ;
}
int F_551 ( struct V_1 * V_2 ,
struct V_1173 * V_1021 )
{
F_516 ( V_2 ) ;
if ( V_2 -> V_5 . V_1021 == V_1022 &&
V_2 -> V_5 . V_1114 . V_1115 )
V_1021 -> V_1021 = V_1112 ;
else
V_1021 -> V_1021 = V_2 -> V_5 . V_1021 ;
return 0 ;
}
int F_552 ( struct V_1 * V_2 ,
struct V_1173 * V_1021 )
{
if ( ! F_263 ( V_2 ) &&
V_1021 -> V_1021 != V_1112 )
return - V_598 ;
if ( V_1021 -> V_1021 == V_1174 ) {
V_2 -> V_5 . V_1021 = V_1092 ;
F_157 ( V_1175 , & V_2 -> V_5 . V_611 -> V_1176 ) ;
} else
V_2 -> V_5 . V_1021 = V_1021 -> V_1021 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
int F_553 ( struct V_1 * V_2 , V_853 V_1177 , int V_1178 ,
int V_1179 , bool V_71 , T_1 V_62 )
{
struct V_815 * V_816 = & V_2 -> V_5 . V_906 ;
int V_107 ;
F_413 ( V_2 ) ;
V_107 = F_554 ( V_816 , V_1177 , V_1178 , V_1179 ,
V_71 , V_62 ) ;
if ( V_107 )
return V_922 ;
F_421 ( V_2 , V_816 -> V_909 ) ;
F_422 ( V_2 , V_816 -> V_908 ) ;
F_30 ( V_67 , V_2 ) ;
return V_923 ;
}
int F_555 ( struct V_1 * V_2 ,
struct V_1154 * V_1155 )
{
struct V_32 V_1180 ;
int V_1181 = 0 ;
int V_1182 , V_1183 , V_363 ;
struct V_875 V_876 ;
if ( ! F_74 ( V_2 ) && ( V_1155 -> V_153 & V_137 ) )
return - V_598 ;
V_876 . V_516 = V_1155 -> V_1170 . V_887 ;
V_876 . V_81 = V_1155 -> V_1170 . V_888 ;
V_74 -> V_880 ( V_2 , & V_876 ) ;
V_876 . V_516 = V_1155 -> V_1171 . V_887 ;
V_876 . V_81 = V_1155 -> V_1171 . V_888 ;
V_74 -> V_879 ( V_2 , & V_876 ) ;
V_2 -> V_5 . V_80 = V_1155 -> V_80 ;
V_1181 |= F_56 ( V_2 ) != V_1155 -> V_103 ;
V_2 -> V_5 . V_103 = V_1155 -> V_103 ;
F_51 ( V_166 , ( V_167 * ) & V_2 -> V_5 . V_115 ) ;
F_84 ( V_2 , V_1155 -> V_168 ) ;
V_1181 |= V_2 -> V_5 . V_129 != V_1155 -> V_129 ;
V_74 -> F_104 ( V_2 , V_1155 -> V_129 ) ;
V_1180 . V_38 = V_1155 -> V_31 ;
V_1180 . V_40 = true ;
F_20 ( V_2 , & V_1180 ) ;
V_1181 |= F_58 ( V_2 ) != V_1155 -> V_119 ;
V_74 -> V_135 ( V_2 , V_1155 -> V_119 ) ;
V_2 -> V_5 . V_119 = V_1155 -> V_119 ;
V_1181 |= F_73 ( V_2 ) != V_1155 -> V_153 ;
V_74 -> V_164 ( V_2 , V_1155 -> V_153 ) ;
if ( V_1155 -> V_153 & V_137 )
F_70 ( V_2 ) ;
V_363 = F_226 ( & V_2 -> V_100 -> V_511 ) ;
if ( ! F_53 ( V_2 ) && F_54 ( V_2 ) ) {
F_48 ( V_2 , V_2 -> V_5 . V_102 , F_56 ( V_2 ) ) ;
V_1181 = 1 ;
}
F_227 ( & V_2 -> V_100 -> V_511 , V_363 ) ;
if ( V_1181 )
F_63 ( V_2 ) ;
V_1183 = V_614 ;
V_1182 = F_556 (
( const unsigned long * ) V_1155 -> V_1172 , V_1183 ) ;
if ( V_1182 < V_1183 ) {
F_254 ( V_2 , V_1182 , false ) ;
F_121 ( L_29 , V_1182 ) ;
}
F_325 ( V_2 , & V_1155 -> V_1153 , V_951 ) ;
F_325 ( V_2 , & V_1155 -> V_1156 , V_1157 ) ;
F_325 ( V_2 , & V_1155 -> V_1158 , V_1159 ) ;
F_325 ( V_2 , & V_1155 -> V_1160 , V_1161 ) ;
F_325 ( V_2 , & V_1155 -> V_1162 , V_1163 ) ;
F_325 ( V_2 , & V_1155 -> V_1164 , V_1165 ) ;
F_325 ( V_2 , & V_1155 -> V_1166 , V_1167 ) ;
F_325 ( V_2 , & V_1155 -> V_1168 , V_1169 ) ;
F_252 ( V_2 ) ;
if ( F_557 ( V_2 ) && F_415 ( V_2 ) == 0xfff0 &&
V_1155 -> V_1153 . V_881 == 0xf000 && V_1155 -> V_1153 . V_888 == 0xffff0000 &&
! F_416 ( V_2 ) )
V_2 -> V_5 . V_1021 = V_1112 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
int F_558 ( struct V_1 * V_2 ,
struct V_1184 * V_1185 )
{
unsigned long V_941 ;
int V_3 , V_118 ;
if ( V_1185 -> V_736 & ( V_1186 | V_1187 ) ) {
V_118 = - V_1188 ;
if ( V_2 -> V_5 . V_68 . V_69 )
goto V_112;
if ( V_1185 -> V_736 & V_1186 )
F_31 ( V_2 , V_53 ) ;
else
F_31 ( V_2 , V_54 ) ;
}
V_941 = F_414 ( V_2 ) ;
V_2 -> V_170 = V_1185 -> V_736 ;
if ( ! ( V_2 -> V_170 & V_1189 ) )
V_2 -> V_170 = 0 ;
if ( V_2 -> V_170 & V_171 ) {
for ( V_3 = 0 ; V_3 < V_1104 ; ++ V_3 )
V_2 -> V_5 . V_186 [ V_3 ] = V_1185 -> V_5 . V_1190 [ V_3 ] ;
V_2 -> V_5 . V_175 = V_1185 -> V_5 . V_1190 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1104 ; V_3 ++ )
V_2 -> V_5 . V_186 [ V_3 ] = V_2 -> V_5 . V_185 [ V_3 ] ;
}
F_90 ( V_2 ) ;
if ( V_2 -> V_170 & V_944 )
V_2 -> V_5 . V_948 = F_415 ( V_2 ) +
F_370 ( V_2 , V_951 ) ;
F_422 ( V_2 , V_941 ) ;
V_74 -> V_1191 ( V_2 ) ;
V_118 = 0 ;
V_112:
return V_118 ;
}
int F_559 ( struct V_1 * V_2 ,
struct V_1192 * V_1166 )
{
unsigned long V_1193 = V_1166 -> V_1194 ;
T_6 V_419 ;
int V_363 ;
V_363 = F_226 ( & V_2 -> V_100 -> V_511 ) ;
V_419 = F_331 ( V_2 , V_1193 , NULL ) ;
F_227 ( & V_2 -> V_100 -> V_511 , V_363 ) ;
V_1166 -> V_1195 = V_419 ;
V_1166 -> V_1196 = V_419 != V_98 ;
V_1166 -> V_1197 = 1 ;
V_1166 -> V_1198 = 0 ;
return 0 ;
}
int F_560 ( struct V_1 * V_2 , struct V_1199 * V_1200 )
{
struct V_661 * V_660 =
& V_2 -> V_5 . V_654 . V_655 -> V_660 ;
memcpy ( V_1200 -> V_1201 , V_660 -> V_1202 , 128 ) ;
V_1200 -> V_1203 = V_660 -> V_1204 ;
V_1200 -> V_1205 = V_660 -> V_1206 ;
V_1200 -> V_1207 = V_660 -> V_1208 ;
V_1200 -> V_1209 = V_660 -> V_1210 ;
V_1200 -> V_1211 = V_660 -> V_1059 ;
V_1200 -> V_1212 = V_660 -> V_1213 ;
memcpy ( V_1200 -> V_1214 , V_660 -> V_1215 , sizeof V_660 -> V_1215 ) ;
return 0 ;
}
int F_561 ( struct V_1 * V_2 , struct V_1199 * V_1200 )
{
struct V_661 * V_660 =
& V_2 -> V_5 . V_654 . V_655 -> V_660 ;
memcpy ( V_660 -> V_1202 , V_1200 -> V_1201 , 128 ) ;
V_660 -> V_1204 = V_1200 -> V_1203 ;
V_660 -> V_1206 = V_1200 -> V_1205 ;
V_660 -> V_1208 = V_1200 -> V_1207 ;
V_660 -> V_1210 = V_1200 -> V_1209 ;
V_660 -> V_1059 = V_1200 -> V_1211 ;
V_660 -> V_1213 = V_1200 -> V_1212 ;
memcpy ( V_660 -> V_1215 , V_1200 -> V_1214 , sizeof V_660 -> V_1215 ) ;
return 0 ;
}
int F_562 ( struct V_1 * V_2 )
{
int V_73 ;
V_73 = F_563 ( & V_2 -> V_5 . V_654 ) ;
if ( V_73 )
return V_73 ;
F_564 ( & V_2 -> V_5 . V_654 ) ;
V_2 -> V_5 . V_140 = V_146 ;
V_2 -> V_5 . V_119 |= V_126 ;
return 0 ;
}
static void F_565 ( struct V_1 * V_2 )
{
F_566 ( & V_2 -> V_5 . V_654 ) ;
}
void F_404 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1216 )
return;
F_68 ( V_2 ) ;
V_2 -> V_1216 = 1 ;
F_567 () ;
F_568 ( & V_2 -> V_5 . V_654 ) ;
F_569 ( 1 ) ;
}
void F_248 ( struct V_1 * V_2 )
{
F_68 ( V_2 ) ;
if ( ! V_2 -> V_1216 )
return;
V_2 -> V_1216 = 0 ;
F_570 ( & V_2 -> V_5 . V_654 ) ;
F_571 () ;
++ V_2 -> V_78 . V_1217 ;
F_30 ( V_1084 , V_2 ) ;
F_569 ( 0 ) ;
}
void F_572 ( struct V_1 * V_2 )
{
F_199 ( V_2 ) ;
F_573 ( V_2 -> V_5 . V_601 ) ;
F_565 ( V_2 ) ;
V_74 -> V_1218 ( V_2 ) ;
}
struct V_1 * F_574 ( struct V_100 * V_100 ,
unsigned int V_1219 )
{
if ( F_136 () && F_131 ( & V_100 -> V_274 ) != 0 )
F_364 ( V_855
L_30
L_31 ) ;
return V_74 -> V_1220 ( V_100 , V_1219 ) ;
}
int F_575 ( struct V_1 * V_2 )
{
int V_118 ;
V_2 -> V_5 . V_358 . V_1221 = 1 ;
V_118 = V_602 ( V_2 ) ;
if ( V_118 )
return V_118 ;
F_576 ( V_2 ) ;
F_577 ( V_2 ) ;
V_606 ( V_2 ) ;
return V_118 ;
}
int F_578 ( struct V_1 * V_2 )
{
int V_118 ;
struct V_32 V_21 ;
struct V_100 * V_100 = V_2 -> V_100 ;
V_118 = V_602 ( V_2 ) ;
if ( V_118 )
return V_118 ;
V_21 . V_38 = 0x0 ;
V_21 . V_142 = V_1222 ;
V_21 . V_40 = true ;
F_134 ( V_2 , & V_21 ) ;
V_606 ( V_2 ) ;
F_171 ( & V_100 -> V_5 . V_341 ,
V_342 ) ;
return V_118 ;
}
void F_579 ( struct V_1 * V_2 )
{
int V_118 ;
V_2 -> V_5 . V_6 . V_420 = 0 ;
V_118 = V_602 ( V_2 ) ;
F_13 ( V_118 ) ;
F_512 ( V_2 ) ;
V_606 ( V_2 ) ;
F_565 ( V_2 ) ;
V_74 -> V_1218 ( V_2 ) ;
}
void F_576 ( struct V_1 * V_2 )
{
F_152 ( & V_2 -> V_5 . V_86 , 0 ) ;
V_2 -> V_5 . V_639 = 0 ;
V_2 -> V_5 . V_638 = false ;
F_580 ( V_2 ) ;
F_436 ( V_2 ) ;
memset ( V_2 -> V_5 . V_185 , 0 , sizeof( V_2 -> V_5 . V_185 ) ) ;
V_2 -> V_5 . V_173 = V_1223 ;
F_89 ( V_2 ) ;
V_2 -> V_5 . V_174 = V_190 ;
F_90 ( V_2 ) ;
F_30 ( V_67 , V_2 ) ;
V_2 -> V_5 . V_6 . V_420 = 0 ;
V_2 -> V_5 . V_424 . V_420 = 0 ;
F_199 ( V_2 ) ;
F_62 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1088 = false ;
F_581 ( V_2 ) ;
memset ( V_2 -> V_5 . V_610 , 0 , sizeof( V_2 -> V_5 . V_610 ) ) ;
V_2 -> V_5 . V_115 = ~ 0 ;
V_2 -> V_5 . V_116 = ~ 0 ;
V_74 -> V_1224 ( V_2 ) ;
}
void F_582 ( struct V_1 * V_2 , unsigned int V_41 )
{
struct V_801 V_1153 ;
F_326 ( V_2 , & V_1153 , V_951 ) ;
V_1153 . V_881 = V_41 << 8 ;
V_1153 . V_888 = V_41 << 12 ;
F_325 ( V_2 , & V_1153 , V_951 ) ;
F_421 ( V_2 , 0 ) ;
}
int F_583 ( void * V_599 )
{
struct V_100 * V_100 ;
struct V_1 * V_2 ;
int V_3 ;
int V_107 ;
T_2 V_1225 ;
T_2 V_1226 = 0 ;
bool V_1227 , V_1228 = false ;
F_15 () ;
V_107 = V_74 -> V_1229 ( V_599 ) ;
if ( V_107 != 0 )
return V_107 ;
V_1225 = F_163 () ;
V_1227 = ! F_136 () ;
F_449 (kvm, &vm_list, vm_list) {
F_156 (i, vcpu, kvm) {
if ( ! V_1227 && V_2 -> V_23 == F_8 () )
F_157 ( V_313 , & V_2 -> V_314 ) ;
if ( V_1227 && V_2 -> V_5 . V_605 > V_1225 ) {
V_1228 = true ;
if ( V_2 -> V_5 . V_605 > V_1226 )
V_1226 = V_2 -> V_5 . V_605 ;
}
}
}
if ( V_1228 ) {
T_2 V_1230 = V_1226 - V_1225 ;
V_311 = true ;
F_449 (kvm, &vm_list, vm_list) {
F_156 (i, vcpu, kvm) {
V_2 -> V_5 . V_603 += V_1230 ;
V_2 -> V_5 . V_605 = V_1225 ;
F_157 ( V_277 ,
& V_2 -> V_314 ) ;
}
V_100 -> V_5 . V_290 = 0 ;
V_100 -> V_5 . V_292 = 0 ;
}
}
return 0 ;
}
void F_584 ( void * V_599 )
{
V_74 -> V_1231 ( V_599 ) ;
F_18 ( V_599 ) ;
}
int F_585 ( void )
{
return V_74 -> V_1232 () ;
}
void F_586 ( void )
{
V_74 -> V_1233 () ;
}
void F_587 ( void * V_1234 )
{
V_74 -> V_1235 ( V_1234 ) ;
}
bool F_588 ( struct V_1 * V_2 )
{
return F_85 ( V_2 -> V_100 ) == ( V_2 -> V_5 . V_611 != NULL ) ;
}
int F_589 ( struct V_1 * V_2 )
{
struct V_388 * V_388 ;
struct V_100 * V_100 ;
int V_118 ;
F_13 ( V_2 -> V_100 == NULL ) ;
V_100 = V_2 -> V_100 ;
V_2 -> V_5 . V_1114 . V_1115 = false ;
V_2 -> V_5 . V_906 . V_830 = & V_1236 ;
if ( ! F_85 ( V_100 ) || F_557 ( V_2 ) )
V_2 -> V_5 . V_1021 = V_1112 ;
else
V_2 -> V_5 . V_1021 = V_1125 ;
V_388 = F_590 ( V_673 | V_1237 ) ;
if ( ! V_388 ) {
V_118 = - V_390 ;
goto V_1238;
}
V_2 -> V_5 . V_860 = F_591 ( V_388 ) ;
F_128 ( V_2 , V_991 ) ;
V_118 = F_592 ( V_2 ) ;
if ( V_118 < 0 )
goto V_1239;
if ( F_85 ( V_100 ) ) {
V_118 = F_593 ( V_2 ) ;
if ( V_118 < 0 )
goto V_1240;
} else
F_594 ( & V_1241 ) ;
V_2 -> V_5 . V_377 = F_273 ( V_466 * sizeof( T_2 ) * 4 ,
V_673 ) ;
if ( ! V_2 -> V_5 . V_377 ) {
V_118 = - V_390 ;
goto V_1242;
}
V_2 -> V_5 . V_369 = V_466 ;
if ( ! F_595 ( & V_2 -> V_5 . V_601 , V_673 ) ) {
V_118 = - V_390 ;
goto V_1243;
}
V_118 = F_562 ( V_2 ) ;
if ( V_118 )
goto V_1244;
V_2 -> V_5 . V_281 = 0x0 ;
V_2 -> V_5 . V_325 = false ;
V_2 -> V_5 . V_149 = 0 ;
V_2 -> V_5 . V_657 = V_1245 + V_658 ;
F_1 ( V_2 ) ;
F_596 ( V_2 ) ;
return 0 ;
V_1244:
F_573 ( V_2 -> V_5 . V_601 ) ;
V_1243:
F_183 ( V_2 -> V_5 . V_377 ) ;
V_1242:
F_597 ( V_2 ) ;
V_1240:
F_598 ( V_2 ) ;
V_1239:
F_599 ( ( unsigned long ) V_2 -> V_5 . V_860 ) ;
V_1238:
return V_118 ;
}
void F_600 ( struct V_1 * V_2 )
{
int V_363 ;
F_601 ( V_2 ) ;
F_183 ( V_2 -> V_5 . V_377 ) ;
F_597 ( V_2 ) ;
V_363 = F_226 ( & V_2 -> V_100 -> V_511 ) ;
F_598 ( V_2 ) ;
F_227 ( & V_2 -> V_100 -> V_511 , V_363 ) ;
F_599 ( ( unsigned long ) V_2 -> V_5 . V_860 ) ;
if ( ! F_85 ( V_2 -> V_100 ) )
F_602 ( & V_1241 ) ;
}
int F_603 ( struct V_100 * V_100 , unsigned long type )
{
if ( type )
return - V_598 ;
F_604 ( & V_100 -> V_5 . V_1246 ) ;
F_604 ( & V_100 -> V_5 . V_1247 ) ;
F_604 ( & V_100 -> V_5 . V_1248 ) ;
F_152 ( & V_100 -> V_5 . V_1249 , 0 ) ;
F_157 ( V_751 , & V_100 -> V_5 . V_1250 ) ;
F_157 ( V_1251 ,
& V_100 -> V_5 . V_1250 ) ;
F_605 ( & V_100 -> V_5 . V_288 ) ;
F_606 ( & V_100 -> V_5 . V_1252 ) ;
F_607 ( & V_100 -> V_5 . V_303 ) ;
F_151 ( V_100 ) ;
F_608 ( & V_100 -> V_5 . V_339 , F_167 ) ;
F_608 ( & V_100 -> V_5 . V_341 , F_172 ) ;
return 0 ;
}
static void F_609 ( struct V_1 * V_2 )
{
int V_118 ;
V_118 = V_602 ( V_2 ) ;
F_13 ( V_118 ) ;
F_512 ( V_2 ) ;
V_606 ( V_2 ) ;
}
static void F_610 ( struct V_100 * V_100 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_156 (i, vcpu, kvm) {
F_62 ( V_2 ) ;
F_609 ( V_2 ) ;
}
F_156 (i, vcpu, kvm)
F_572 ( V_2 ) ;
F_210 ( & V_100 -> V_481 ) ;
for ( V_3 = 0 ; V_3 < F_131 ( & V_100 -> V_274 ) ; V_3 ++ )
V_100 -> V_1253 [ V_3 ] = NULL ;
F_152 ( & V_100 -> V_274 , 0 ) ;
F_211 ( & V_100 -> V_481 ) ;
}
void F_611 ( struct V_100 * V_100 )
{
F_612 ( & V_100 -> V_5 . V_341 ) ;
F_612 ( & V_100 -> V_5 . V_339 ) ;
F_613 ( V_100 ) ;
F_614 ( V_100 ) ;
}
void F_615 ( struct V_100 * V_100 )
{
if ( V_425 -> V_1254 == V_100 -> V_1254 ) {
struct V_1255 V_1256 ;
memset ( & V_1256 , 0 , sizeof( V_1256 ) ) ;
V_1256 . V_10 = V_1257 ;
F_616 ( V_100 , & V_1256 ) ;
V_1256 . V_10 = V_1258 ;
F_616 ( V_100 , & V_1256 ) ;
V_1256 . V_10 = V_1259 ;
F_616 ( V_100 , & V_1256 ) ;
}
F_617 ( V_100 ) ;
F_183 ( V_100 -> V_5 . V_763 ) ;
F_183 ( V_100 -> V_5 . V_1260 ) ;
F_610 ( V_100 ) ;
if ( V_100 -> V_5 . V_1261 )
F_618 ( V_100 -> V_5 . V_1261 ) ;
if ( V_100 -> V_5 . V_1262 )
F_618 ( V_100 -> V_5 . V_1262 ) ;
F_183 ( F_619 ( V_100 -> V_5 . V_1263 , 1 ) ) ;
}
void F_620 ( struct V_100 * V_100 , struct V_739 * free ,
struct V_739 * V_1264 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1265 ; ++ V_3 ) {
if ( ! V_1264 || free -> V_5 . V_1266 [ V_3 ] != V_1264 -> V_5 . V_1266 [ V_3 ] ) {
F_621 ( free -> V_5 . V_1266 [ V_3 ] ) ;
free -> V_5 . V_1266 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1264 || free -> V_5 . V_1267 [ V_3 - 1 ] !=
V_1264 -> V_5 . V_1267 [ V_3 - 1 ] ) {
F_621 ( free -> V_5 . V_1267 [ V_3 - 1 ] ) ;
free -> V_5 . V_1267 [ V_3 - 1 ] = NULL ;
}
}
}
int F_622 ( struct V_100 * V_100 , struct V_739 * V_10 ,
unsigned long V_1268 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1265 ; ++ V_3 ) {
unsigned long V_1269 ;
int V_1270 ;
int V_752 = V_3 + 1 ;
V_1270 = F_623 ( V_10 -> V_1271 + V_1268 - 1 ,
V_10 -> V_1271 , V_752 ) + 1 ;
V_10 -> V_5 . V_1266 [ V_3 ] =
F_624 ( V_1270 * sizeof( * V_10 -> V_5 . V_1266 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1266 [ V_3 ] )
goto V_391;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1267 [ V_3 - 1 ] = F_624 ( V_1270 *
sizeof( * V_10 -> V_5 . V_1267 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1267 [ V_3 - 1 ] )
goto V_391;
if ( V_10 -> V_1271 & ( F_625 ( V_752 ) - 1 ) )
V_10 -> V_5 . V_1267 [ V_3 - 1 ] [ 0 ] . V_1272 = 1 ;
if ( ( V_10 -> V_1271 + V_1268 ) & ( F_625 ( V_752 ) - 1 ) )
V_10 -> V_5 . V_1267 [ V_3 - 1 ] [ V_1270 - 1 ] . V_1272 = 1 ;
V_1269 = V_10 -> V_1273 >> V_105 ;
if ( ( V_10 -> V_1271 ^ V_1269 ) & ( F_625 ( V_752 ) - 1 ) ||
! F_626 () ) {
unsigned long V_793 ;
for ( V_793 = 0 ; V_793 < V_1270 ; ++ V_793 )
V_10 -> V_5 . V_1267 [ V_3 - 1 ] [ V_793 ] . V_1272 = 1 ;
}
}
return 0 ;
V_391:
for ( V_3 = 0 ; V_3 < V_1265 ; ++ V_3 ) {
F_621 ( V_10 -> V_5 . V_1266 [ V_3 ] ) ;
V_10 -> V_5 . V_1266 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_621 ( V_10 -> V_5 . V_1267 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1267 [ V_3 - 1 ] = NULL ;
}
return - V_390 ;
}
void F_627 ( struct V_100 * V_100 )
{
F_628 ( V_100 ) ;
}
int F_629 ( struct V_100 * V_100 ,
struct V_739 * V_740 ,
struct V_1255 * V_1256 ,
enum V_1274 V_1275 )
{
if ( ( V_740 -> V_1219 >= V_566 ) && ( V_1275 == V_1276 ) ) {
unsigned long V_1273 ;
V_1273 = F_630 ( NULL , 0 , V_740 -> V_1268 * V_106 ,
V_1277 | V_1278 ,
V_1279 | V_1280 , 0 ) ;
if ( F_181 ( ( void * ) V_1273 ) )
return F_182 ( ( void * ) V_1273 ) ;
V_740 -> V_1273 = V_1273 ;
}
return 0 ;
}
void F_631 ( struct V_100 * V_100 ,
struct V_1255 * V_1256 ,
const struct V_739 * V_848 ,
enum V_1274 V_1275 )
{
int V_1281 = 0 ;
if ( ( V_1256 -> V_10 >= V_566 ) && ( V_1275 == V_1282 ) ) {
int V_107 ;
V_107 = F_632 ( V_848 -> V_1273 ,
V_848 -> V_1268 * V_106 ) ;
if ( V_107 < 0 )
F_10 ( V_855
L_32
L_33 ) ;
}
if ( ! V_100 -> V_5 . V_712 )
V_1281 = F_633 ( V_100 ) ;
if ( V_1281 )
F_282 ( V_100 , V_1281 ) ;
if ( ( V_1275 != V_1282 ) && ( V_1256 -> V_284 & V_1283 ) )
F_634 ( V_100 , V_1256 -> V_10 ) ;
}
void F_635 ( struct V_100 * V_100 )
{
F_636 ( V_100 ) ;
}
void F_637 ( struct V_100 * V_100 ,
struct V_739 * V_10 )
{
F_636 ( V_100 ) ;
}
int F_638 ( struct V_1 * V_2 )
{
if ( F_417 ( V_2 ) && V_74 -> V_1069 )
V_74 -> V_1069 ( V_2 , false ) ;
return ( V_2 -> V_5 . V_1021 == V_1112 &&
! V_2 -> V_5 . V_6 . V_1088 )
|| ! F_639 ( & V_2 -> V_1284 . V_1285 )
|| F_640 ( V_2 )
|| V_2 -> V_5 . V_1114 . V_1115
|| F_131 ( & V_2 -> V_5 . V_86 ) ||
( F_497 ( V_2 ) &&
F_496 ( V_2 ) ) ;
}
int F_641 ( struct V_1 * V_2 )
{
return F_642 ( V_2 ) == V_1098 ;
}
int F_497 ( struct V_1 * V_2 )
{
return V_74 -> V_1071 ( V_2 ) ;
}
bool F_643 ( struct V_1 * V_2 , unsigned long V_1286 )
{
unsigned long V_1287 = F_415 ( V_2 ) +
F_370 ( V_2 , V_951 ) ;
return V_1287 == V_1286 ;
}
unsigned long F_414 ( struct V_1 * V_2 )
{
unsigned long V_941 ;
V_941 = V_74 -> V_972 ( V_2 ) ;
if ( V_2 -> V_170 & V_944 )
V_941 &= ~ V_943 ;
return V_941 ;
}
static void F_441 ( struct V_1 * V_2 , unsigned long V_941 )
{
if ( V_2 -> V_170 & V_944 &&
F_643 ( V_2 , V_2 -> V_5 . V_948 ) )
V_941 |= V_943 ;
V_74 -> V_1288 ( V_2 , V_941 ) ;
}
void F_422 ( struct V_1 * V_2 , unsigned long V_941 )
{
F_441 ( V_2 , V_941 ) ;
F_30 ( V_67 , V_2 ) ;
}
void F_644 ( struct V_1 * V_2 , struct V_1289 * V_336 )
{
int V_118 ;
if ( ( V_2 -> V_5 . V_85 . V_934 != V_336 -> V_5 . V_934 ) ||
V_336 -> V_1290 )
return;
V_118 = F_519 ( V_2 ) ;
if ( F_148 ( V_118 ) )
return;
if ( ! V_2 -> V_5 . V_85 . V_934 &&
V_336 -> V_5 . V_103 != V_2 -> V_5 . V_85 . V_1291 ( V_2 ) )
return;
V_2 -> V_5 . V_85 . V_1292 ( V_2 , V_336 -> V_808 , 0 , true ) ;
}
static inline T_1 F_645 ( T_5 V_101 )
{
return F_646 ( V_101 & 0xffffffff , F_647 ( V_4 ) ) ;
}
static inline T_1 F_648 ( T_1 V_1293 )
{
return ( V_1293 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_649 ( struct V_1 * V_2 , T_5 V_101 )
{
T_1 V_1293 = F_645 ( V_101 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1293 ] != ~ 0 )
V_1293 = F_648 ( V_1293 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1293 ] = V_101 ;
}
static T_1 F_650 ( struct V_1 * V_2 , T_5 V_101 )
{
int V_3 ;
T_1 V_1293 = F_645 ( V_101 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1293 ] != V_101 &&
V_2 -> V_5 . V_6 . V_7 [ V_1293 ] != ~ 0 ) ; V_3 ++ )
V_1293 = F_648 ( V_1293 ) ;
return V_1293 ;
}
bool F_651 ( struct V_1 * V_2 , T_5 V_101 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_650 ( V_2 , V_101 ) ] == V_101 ;
}
static void F_652 ( struct V_1 * V_2 , T_5 V_101 )
{
T_1 V_3 , V_793 , V_1294 ;
V_3 = V_793 = F_650 ( V_2 , V_101 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_793 = F_648 ( V_793 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_793 ] == ~ 0 )
return;
V_1294 = F_645 ( V_2 -> V_5 . V_6 . V_7 [ V_793 ] ) ;
} while ( ( V_3 <= V_793 ) ? ( V_3 < V_1294 && V_1294 <= V_793 ) : ( V_3 < V_1294 || V_1294 <= V_793 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_793 ] ;
V_3 = V_793 ;
}
}
static int F_653 ( struct V_1 * V_2 , T_1 V_184 )
{
return F_166 ( V_2 -> V_100 , & V_2 -> V_5 . V_6 . V_38 , & V_184 ,
sizeof( V_184 ) ) ;
}
void F_654 ( struct V_1 * V_2 ,
struct V_1289 * V_336 )
{
struct V_76 V_77 ;
F_655 ( V_336 -> V_5 . V_1295 , V_336 -> V_808 ) ;
F_649 ( V_2 , V_336 -> V_5 . V_101 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_420 & V_421 ) ||
( V_2 -> V_5 . V_6 . V_422 &&
V_74 -> V_89 ( V_2 ) == 0 ) )
F_30 ( V_1087 , V_2 ) ;
else if ( ! F_653 ( V_2 , V_1296 ) ) {
V_77 . V_41 = V_42 ;
V_77 . V_907 = true ;
V_77 . V_62 = 0 ;
V_77 . V_82 = false ;
V_77 . V_81 = V_336 -> V_5 . V_1295 ;
F_35 ( V_2 , & V_77 ) ;
}
}
void F_656 ( struct V_1 * V_2 ,
struct V_1289 * V_336 )
{
struct V_76 V_77 ;
F_657 ( V_336 -> V_5 . V_1295 , V_336 -> V_808 ) ;
if ( V_336 -> V_1290 )
V_336 -> V_5 . V_1295 = ~ 0 ;
else
F_652 ( V_2 , V_336 -> V_5 . V_101 ) ;
if ( ( V_2 -> V_5 . V_6 . V_420 & V_421 ) &&
! F_653 ( V_2 , V_1297 ) ) {
V_77 . V_41 = V_42 ;
V_77 . V_907 = true ;
V_77 . V_62 = 0 ;
V_77 . V_82 = false ;
V_77 . V_81 = V_336 -> V_5 . V_1295 ;
F_35 ( V_2 , & V_77 ) ;
}
V_2 -> V_5 . V_6 . V_1088 = false ;
V_2 -> V_5 . V_1021 = V_1112 ;
}
bool F_658 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_420 & V_421 ) )
return true ;
else
return ! F_499 ( V_2 ) &&
V_74 -> V_1071 ( V_2 ) ;
}
void F_659 ( struct V_100 * V_100 )
{
F_40 ( & V_100 -> V_5 . V_1249 ) ;
}
void F_660 ( struct V_100 * V_100 )
{
F_661 ( & V_100 -> V_5 . V_1249 ) ;
}
bool F_240 ( struct V_100 * V_100 )
{
return F_131 ( & V_100 -> V_5 . V_1249 ) ;
}
