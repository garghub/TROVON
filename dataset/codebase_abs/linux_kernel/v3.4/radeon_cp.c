T_1 F_1 ( T_2 * V_1 , T_1 V_2 )
{
T_1 V_3 ;
if ( V_1 -> V_4 & V_5 ) {
V_3 = F_2 ( V_1 -> V_6 , V_2 ) ;
} else {
V_3 = * ( ( ( volatile T_1 * )
V_1 -> V_6 -> V_7 ) +
( V_2 / sizeof( T_1 ) ) ) ;
V_3 = F_3 ( V_3 ) ;
}
return V_3 ;
}
T_1 F_4 ( T_2 * V_1 )
{
if ( V_1 -> V_8 )
return F_1 ( V_1 , 0 ) ;
else {
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
return F_5 ( V_11 ) ;
else
return F_5 ( V_12 ) ;
}
}
void F_6 ( T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
if ( V_1 -> V_4 & V_5 )
F_7 ( V_1 -> V_6 , V_2 , V_3 ) ;
else
* ( ( ( volatile T_1 * ) V_1 -> V_6 -> V_7 ) +
( V_2 / sizeof( T_1 ) ) ) = F_8 ( V_3 ) ;
}
void F_9 ( T_2 * V_1 , T_1 V_3 )
{
F_6 ( V_1 , 0 , V_3 ) ;
}
T_1 F_10 ( T_2 * V_1 , int V_13 )
{
if ( V_1 -> V_8 ) {
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
return F_1 ( V_1 ,
F_11 ( V_13 ) ) ;
else
return F_1 ( V_1 ,
F_12 ( V_13 ) ) ;
} else {
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
return F_5 ( V_14 + 4 * V_13 ) ;
else
return F_5 ( V_15 + 4 * V_13 ) ;
}
}
T_1 F_13 ( T_2 * V_1 , int V_16 )
{
T_1 V_17 ;
if ( V_16 < 0x10000 )
V_17 = F_2 ( V_1 -> V_18 , V_16 ) ;
else {
F_7 ( V_1 -> V_18 , V_19 , V_16 ) ;
V_17 = F_2 ( V_1 -> V_18 , V_20 ) ;
}
return V_17 ;
}
static T_1 F_14 ( T_2 * V_1 , int V_16 )
{
T_1 V_17 ;
F_15 ( V_21 , 0x7f0000 | ( V_16 & 0xff ) ) ;
V_17 = F_5 ( V_22 ) ;
F_15 ( V_21 , 0 ) ;
return V_17 ;
}
static T_1 F_16 ( T_2 * V_1 , int V_16 )
{
T_1 V_17 ;
F_15 ( V_23 , V_16 & 0xff ) ;
V_17 = F_5 ( V_24 ) ;
F_15 ( V_23 , 0xff ) ;
return V_17 ;
}
static T_1 F_17 ( T_2 * V_1 , int V_16 )
{
T_1 V_17 ;
F_15 ( V_25 , ( V_16 & V_26 ) ) ;
V_17 = F_5 ( V_27 ) ;
F_15 ( V_25 , V_26 ) ;
return V_17 ;
}
static T_1 F_18 ( T_2 * V_1 , int V_16 )
{
T_1 V_17 ;
F_15 ( V_28 , ( ( V_16 & V_29 ) |
V_30 ) ) ;
V_17 = F_5 ( V_31 ) ;
return V_17 ;
}
static T_1 F_19 ( T_2 * V_1 , int V_16 )
{
if ( ( ( V_1 -> V_4 & V_9 ) == V_32 ) ||
( ( V_1 -> V_4 & V_9 ) == V_33 ) )
return F_17 ( V_1 , V_16 ) ;
else if ( ( V_1 -> V_4 & V_9 ) == V_34 )
return F_18 ( V_1 , V_16 ) ;
else
return F_16 ( V_1 , V_16 ) ;
}
T_1 F_20 ( T_2 * V_1 )
{
if ( ( V_1 -> V_4 & V_9 ) >= V_35 )
return F_5 ( V_36 ) ;
else if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
return F_5 ( V_37 ) ;
else if ( ( V_1 -> V_4 & V_9 ) == V_38 )
return F_14 ( V_1 , V_39 ) ;
else if ( ( ( V_1 -> V_4 & V_9 ) == V_32 ) ||
( ( V_1 -> V_4 & V_9 ) == V_33 ) )
return F_17 ( V_1 , V_40 ) ;
else if ( ( V_1 -> V_4 & V_9 ) == V_34 )
return F_18 ( V_1 , V_41 ) ;
else if ( ( V_1 -> V_4 & V_9 ) > V_38 )
return F_14 ( V_1 , V_42 ) ;
else
return F_5 ( V_43 ) ;
}
static void F_21 ( T_2 * V_1 , T_1 V_44 )
{
if ( ( V_1 -> V_4 & V_9 ) >= V_35 )
F_15 ( V_36 , V_44 ) ;
else if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
F_15 ( V_37 , V_44 ) ;
else if ( ( V_1 -> V_4 & V_9 ) == V_38 )
F_22 ( V_39 , V_44 ) ;
else if ( ( ( V_1 -> V_4 & V_9 ) == V_32 ) ||
( ( V_1 -> V_4 & V_9 ) == V_33 ) )
F_23 ( V_40 , V_44 ) ;
else if ( ( V_1 -> V_4 & V_9 ) == V_34 )
F_24 ( V_41 , V_44 ) ;
else if ( ( V_1 -> V_4 & V_9 ) > V_38 )
F_22 ( V_42 , V_44 ) ;
else
F_15 ( V_43 , V_44 ) ;
}
void F_25 ( T_2 * V_1 , T_1 V_45 )
{
if ( ( V_1 -> V_4 & V_9 ) >= V_35 ) {
F_15 ( V_46 , V_45 & 0xffff ) ;
F_15 ( V_47 , ( V_45 >> 16 ) & 0xffff ) ;
} else if ( ( V_1 -> V_4 & V_9 ) >= V_10 ) {
F_15 ( V_48 , V_45 & 0xffff ) ;
F_15 ( V_49 , ( V_45 >> 16 ) & 0xffff ) ;
} else if ( ( V_1 -> V_4 & V_9 ) == V_38 )
F_22 ( V_50 , V_45 ) ;
else if ( ( ( V_1 -> V_4 & V_9 ) == V_32 ) ||
( ( V_1 -> V_4 & V_9 ) == V_33 ) )
F_23 ( V_51 , V_45 ) ;
else if ( ( V_1 -> V_4 & V_9 ) == V_34 )
F_24 ( V_52 , V_45 ) ;
else if ( ( V_1 -> V_4 & V_9 ) > V_38 )
F_22 ( V_53 , V_45 ) ;
else
F_15 ( V_54 , V_45 ) ;
}
void F_26 ( T_2 * V_1 , T_3 V_55 )
{
T_1 V_56 = F_27 ( V_55 ) ;
T_1 V_57 = V_55 & 0xffffffff ;
T_1 V_58 = ( V_55 >> 22 ) & 0x3ffff ;
if ( ( V_1 -> V_4 & V_9 ) >= V_35 )
F_15 ( V_59 , V_58 ) ;
else if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
F_15 ( V_60 , V_58 ) ;
else if ( ( V_1 -> V_4 & V_9 ) == V_38 ) {
F_22 ( V_61 , V_57 ) ;
F_22 ( V_62 , V_56 ) ;
} else if ( ( ( V_1 -> V_4 & V_9 ) == V_32 ) ||
( ( V_1 -> V_4 & V_9 ) == V_33 ) ) {
F_23 ( V_63 , V_57 ) ;
F_23 ( V_64 , V_56 ) ;
} else if ( ( V_1 -> V_4 & V_9 ) == V_34 ) {
F_24 ( V_65 , V_57 ) ;
F_24 ( V_66 , V_56 ) ;
} else if ( ( V_1 -> V_4 & V_9 ) > V_38 ) {
F_22 ( V_67 , V_57 ) ;
F_22 ( V_68 , V_56 ) ;
} else if ( ( ( V_1 -> V_4 & V_9 ) == V_69 ) ||
( ( V_1 -> V_4 & V_9 ) == V_70 ) ) {
F_15 ( V_71 , V_57 ) ;
F_15 ( V_72 , V_56 ) ;
} else {
F_15 ( V_71 , V_57 ) ;
if ( ( V_1 -> V_4 & V_9 ) >= V_73 )
F_15 ( V_74 , V_56 ) ;
}
}
void F_28 ( struct V_75 * V_1 )
{
T_1 V_76 ;
if ( ( ( V_1 -> V_4 & V_9 ) == V_32 ) ||
( ( V_1 -> V_4 & V_9 ) == V_33 ) ) {
V_76 = F_5 ( V_77 ) & ~ V_78 ;
F_15 ( V_77 , V_76 ) ;
} else if ( ( ( V_1 -> V_4 & V_9 ) <= V_79 ) ||
( ( V_1 -> V_4 & V_9 ) == V_80 ) ||
( ( V_1 -> V_4 & V_9 ) == V_69 ) ||
( ( V_1 -> V_4 & V_9 ) == V_70 ) ) {
V_76 = F_5 ( V_77 ) & ~ V_81 ;
F_15 ( V_77 , V_76 ) ;
}
}
static int F_29 ( struct V_82 * V_83 , int V_16 )
{
T_2 * V_1 = V_83 -> V_84 ;
F_30 ( V_85 , V_16 & 0x1f ) ;
return F_5 ( V_86 ) ;
}
static T_1 F_31 ( T_2 * V_1 , int V_16 )
{
F_30 ( V_87 , V_16 & 0xff ) ;
return F_5 ( V_88 ) ;
}
static void F_32 ( T_2 * V_1 )
{
F_33 ( L_1 , V_89 ) ;
F_33 ( L_2 ,
( unsigned int ) F_5 ( V_90 ) ) ;
F_33 ( L_3 ,
( unsigned int ) F_5 ( V_12 ) ) ;
F_33 ( L_4 ,
( unsigned int ) F_5 ( V_91 ) ) ;
F_33 ( L_5 ,
( unsigned int ) F_5 ( V_92 ) ) ;
F_33 ( L_6 ,
( unsigned int ) F_5 ( V_93 ) ) ;
F_33 ( L_7 ,
( unsigned int ) F_5 ( V_94 ) ) ;
F_33 ( L_8 ,
( unsigned int ) F_5 ( V_95 ) ) ;
F_33 ( L_9 ,
( unsigned int ) F_5 ( V_96 ) ) ;
}
static int F_34 ( T_2 * V_1 )
{
T_1 V_76 ;
int V_97 ;
V_1 -> V_98 . V_99 |= V_100 ;
if ( ( V_1 -> V_4 & V_9 ) <= V_101 ) {
V_76 = F_5 ( V_102 ) ;
V_76 |= V_103 ;
F_15 ( V_102 , V_76 ) ;
for ( V_97 = 0 ; V_97 < V_1 -> V_104 ; V_97 ++ ) {
if ( ! ( F_5 ( V_102 )
& V_105 ) ) {
return 0 ;
}
F_35 ( 1 ) ;
}
} else {
return 0 ;
}
#if V_106
F_36 ( L_10 ) ;
F_32 ( V_1 ) ;
#endif
return - V_107 ;
}
static int F_37 ( T_2 * V_1 , int V_108 )
{
int V_97 ;
V_1 -> V_98 . V_99 |= V_100 ;
for ( V_97 = 0 ; V_97 < V_1 -> V_104 ; V_97 ++ ) {
int V_109 = ( F_5 ( V_90 )
& V_110 ) ;
if ( V_109 >= V_108 )
return 0 ;
F_35 ( 1 ) ;
}
F_38 ( L_11 ,
F_5 ( V_90 ) ,
F_5 ( V_111 ) ) ;
#if V_106
F_36 ( L_10 ) ;
F_32 ( V_1 ) ;
#endif
return - V_107 ;
}
static int F_39 ( T_2 * V_1 )
{
int V_97 , V_17 ;
V_1 -> V_98 . V_99 |= V_100 ;
V_17 = F_37 ( V_1 , 64 ) ;
if ( V_17 )
return V_17 ;
for ( V_97 = 0 ; V_97 < V_1 -> V_104 ; V_97 ++ ) {
if ( ! ( F_5 ( V_90 )
& V_112 ) ) {
F_34 ( V_1 ) ;
return 0 ;
}
F_35 ( 1 ) ;
}
F_38 ( L_12 ,
F_5 ( V_90 ) ,
F_5 ( V_111 ) ) ;
#if V_106
F_36 ( L_10 ) ;
F_32 ( V_1 ) ;
#endif
return - V_107 ;
}
static void F_40 ( struct V_82 * V_83 )
{
T_2 * V_1 = V_83 -> V_84 ;
T_4 V_113 , V_114 = 0 ;
if ( ( V_1 -> V_4 & V_9 ) == V_115 ) {
T_4 V_116 = F_5 ( V_117 ) ;
if ( ( V_116 & 3 ) == 3 )
V_1 -> V_118 = 2 ;
else
V_1 -> V_118 = 1 ;
} else
V_1 -> V_118 = 1 ;
if ( ( V_1 -> V_4 & V_9 ) >= V_80 ) {
V_114 = F_5 ( V_119 ) ;
V_1 -> V_120 = ( ( V_114 >> 12 ) & 0x3 ) + 1 ;
if ( ( V_83 -> V_121 -> V_122 == 0x5e4c ) ||
( V_83 -> V_121 -> V_122 == 0x5e4f ) )
V_1 -> V_120 = 1 ;
} else {
if ( ( ( V_1 -> V_4 & V_9 ) == V_123 &&
V_83 -> V_121 -> V_122 != 0x4144 ) ||
( ( V_1 -> V_4 & V_9 ) == V_124 &&
V_83 -> V_121 -> V_122 != 0x4148 ) ) {
V_1 -> V_120 = 2 ;
} else {
V_1 -> V_120 = 1 ;
}
}
F_41 ( L_13 , V_1 -> V_120 ) ;
V_113 = ( V_125 | V_126 ) ;
switch ( V_1 -> V_120 ) {
case 2 : V_113 |= V_127 ; break;
case 3 : V_113 |= V_128 ; break;
case 4 : V_113 |= V_129 ; break;
default:
case 1 : V_113 |= V_130 ; break;
}
if ( ( V_1 -> V_4 & V_9 ) >= V_38 ) {
F_42 ( V_131 , ( 1 | ( ( V_114 >> 8 ) & 0xf ) << 4 ) ) ;
F_15 ( V_132 , ( ( 1 << V_1 -> V_120 ) - 1 ) ) ;
}
F_15 ( V_133 , V_113 ) ;
F_39 ( V_1 ) ;
F_15 ( V_134 , F_5 ( V_134 ) | V_135 ) ;
F_15 ( V_136 , ( F_5 ( V_136 ) |
V_137 |
V_138 ) ) ;
}
static int F_43 ( T_2 * V_1 )
{
struct V_139 * V_121 ;
const char * V_140 = NULL ;
int V_141 ;
F_38 ( L_14 ) ;
V_121 = F_44 ( L_15 , 0 , NULL , 0 ) ;
V_141 = F_45 ( V_121 ) ;
if ( V_141 ) {
F_33 ( V_142 L_16 ) ;
return - V_143 ;
}
if ( ( ( V_1 -> V_4 & V_9 ) == V_144 ) ||
( ( V_1 -> V_4 & V_9 ) == V_145 ) ||
( ( V_1 -> V_4 & V_9 ) == V_146 ) ||
( ( V_1 -> V_4 & V_9 ) == V_147 ) ||
( ( V_1 -> V_4 & V_9 ) == V_148 ) ) {
F_41 ( L_17 ) ;
V_140 = V_149 ;
} else if ( ( ( V_1 -> V_4 & V_9 ) == V_73 ) ||
( ( V_1 -> V_4 & V_9 ) == V_150 ) ||
( ( V_1 -> V_4 & V_9 ) == V_101 ) ||
( ( V_1 -> V_4 & V_9 ) == V_151 ) ) {
F_41 ( L_18 ) ;
V_140 = V_152 ;
} else if ( ( ( V_1 -> V_4 & V_9 ) == V_123 ) ||
( ( V_1 -> V_4 & V_9 ) == V_124 ) ||
( ( V_1 -> V_4 & V_9 ) == V_79 ) ||
( ( V_1 -> V_4 & V_9 ) == V_153 ) ||
( ( V_1 -> V_4 & V_9 ) == V_69 ) ||
( ( V_1 -> V_4 & V_9 ) == V_70 ) ) {
F_41 ( L_19 ) ;
V_140 = V_154 ;
} else if ( ( ( V_1 -> V_4 & V_9 ) == V_80 ) ||
( ( V_1 -> V_4 & V_9 ) == V_155 ) ||
( ( V_1 -> V_4 & V_9 ) == V_156 ) ) {
F_41 ( L_20 ) ;
V_140 = V_157 ;
} else if ( ( ( V_1 -> V_4 & V_9 ) == V_32 ) ||
( ( V_1 -> V_4 & V_9 ) == V_33 ) ) {
F_41 ( L_21 ) ;
V_140 = V_158 ;
} else if ( ( V_1 -> V_4 & V_9 ) == V_34 ) {
F_41 ( L_22 ) ;
V_140 = V_159 ;
} else if ( ( ( V_1 -> V_4 & V_9 ) == V_38 ) ||
( ( V_1 -> V_4 & V_9 ) == V_160 ) ||
( ( V_1 -> V_4 & V_9 ) == V_115 ) ||
( ( V_1 -> V_4 & V_9 ) == V_161 ) ||
( ( V_1 -> V_4 & V_9 ) == V_162 ) ||
( ( V_1 -> V_4 & V_9 ) == V_163 ) ) {
F_41 ( L_23 ) ;
V_140 = V_164 ;
}
V_141 = F_46 ( & V_1 -> V_165 , V_140 , & V_121 -> V_83 ) ;
F_47 ( V_121 ) ;
if ( V_141 ) {
F_33 ( V_142 L_24 ,
V_140 ) ;
} else if ( V_1 -> V_165 -> V_166 % 8 ) {
F_33 ( V_142
L_25 ,
V_1 -> V_165 -> V_166 , V_140 ) ;
V_141 = - V_143 ;
F_48 ( V_1 -> V_165 ) ;
V_1 -> V_165 = NULL ;
}
return V_141 ;
}
static void F_49 ( T_2 * V_1 )
{
const T_5 * V_167 ;
int V_97 , V_166 ;
F_39 ( V_1 ) ;
if ( V_1 -> V_165 ) {
V_166 = V_1 -> V_165 -> V_166 / 4 ;
V_167 = ( const T_5 * ) & V_1 -> V_165 -> V_168 [ 0 ] ;
F_15 ( V_169 , 0 ) ;
for ( V_97 = 0 ; V_97 < V_166 ; V_97 += 2 ) {
F_15 ( V_170 ,
F_50 ( & V_167 [ V_97 ] ) ) ;
F_15 ( V_171 ,
F_50 ( & V_167 [ V_97 + 1 ] ) ) ;
}
}
}
static void F_51 ( T_2 * V_1 )
{
F_38 ( L_14 ) ;
#if 0
u32 tmp;
tmp = RADEON_READ(RADEON_CP_RB_WPTR) | (1 << 31);
RADEON_WRITE(RADEON_CP_RB_WPTR, tmp);
#endif
}
int F_52 ( T_2 * V_1 )
{
V_172 ;
F_38 ( L_14 ) ;
F_53 ( 6 ) ;
F_54 () ;
F_55 () ;
F_56 () ;
F_57 () ;
F_58 () ;
return F_39 ( V_1 ) ;
}
static void F_59 ( T_2 * V_1 )
{
V_172 ;
F_38 ( L_14 ) ;
F_39 ( V_1 ) ;
F_15 ( V_173 , V_1 -> V_174 ) ;
V_1 -> V_175 = 1 ;
if ( ( V_1 -> V_4 & V_9 ) == V_80 ) {
F_53 ( 3 ) ;
F_60 ( F_61 ( V_176 , 1 ) ) ;
F_60 ( 5 ) ;
F_60 ( 0xdeadbeef ) ;
F_57 () ;
F_58 () ;
}
F_53 ( 8 ) ;
F_60 ( F_61 ( V_177 , 0 ) ) ;
F_60 ( V_178 |
V_179 |
V_180 |
V_181 ) ;
F_54 () ;
F_55 () ;
F_56 () ;
F_57 () ;
F_58 () ;
V_1 -> V_182 |= V_183 | V_184 ;
}
static void F_62 ( T_2 * V_1 )
{
T_1 V_185 ;
F_38 ( L_14 ) ;
V_185 = F_5 ( V_12 ) ;
F_15 ( V_91 , V_185 ) ;
F_63 ( V_1 , V_185 ) ;
V_1 -> V_186 . V_187 = V_185 ;
}
static void F_64 ( T_2 * V_1 )
{
V_172 ;
F_38 ( L_14 ) ;
if ( ( V_1 -> V_4 & V_9 ) == V_80 ) {
F_53 ( 2 ) ;
F_60 ( F_61 ( V_188 , 0 ) ) ;
F_60 ( V_189 ) ;
F_57 () ;
F_58 () ;
F_39 ( V_1 ) ;
}
F_15 ( V_173 , V_190 ) ;
V_1 -> V_175 = 0 ;
}
static int F_65 ( struct V_82 * V_83 )
{
T_2 * V_1 = V_83 -> V_84 ;
T_1 V_191 = 0 , V_192 = 0 , V_193 ;
F_38 ( L_14 ) ;
F_34 ( V_1 ) ;
if ( ( V_1 -> V_4 & V_9 ) <= V_156 ) {
V_191 = F_5 ( V_85 ) ;
V_192 = F_29 ( V_83 , V_194 ) ;
F_42 ( V_194 , ( V_192 |
V_195 |
V_196 |
V_197 |
V_198 |
V_199 |
V_200 ) ) ;
}
V_193 = F_5 ( V_201 ) ;
F_15 ( V_201 , ( V_193 |
V_202 |
V_203 |
V_204 |
V_205 |
V_206 |
V_207 |
V_208 ) ) ;
F_5 ( V_201 ) ;
F_15 ( V_201 , ( V_193 &
~ ( V_202 |
V_203 |
V_204 |
V_205 |
V_206 |
V_207 |
V_208 ) ) ) ;
F_5 ( V_201 ) ;
if ( ( V_1 -> V_4 & V_9 ) <= V_156 ) {
F_42 ( V_194 , V_192 ) ;
F_15 ( V_85 , V_191 ) ;
F_15 ( V_201 , V_193 ) ;
}
if ( ( V_1 -> V_4 & V_9 ) >= V_123 )
F_40 ( V_83 ) ;
F_62 ( V_1 ) ;
V_1 -> V_175 = 0 ;
F_66 ( V_83 ) ;
return 0 ;
}
static void F_67 ( struct V_82 * V_83 ,
T_2 * V_1 ,
struct V_209 * V_210 )
{
struct V_211 * V_212 ;
T_1 V_213 , V_185 ;
if ( ! V_1 -> V_214 )
F_21 ( V_1 ,
( ( V_1 -> V_215 - 1 ) & 0xffff0000 )
| ( V_1 -> V_216 >> 16 ) ) ;
#if V_217
if ( V_1 -> V_4 & V_5 ) {
F_26 ( V_1 , V_83 -> V_218 -> V_219 ) ;
F_25 ( V_1 ,
( ( ( V_1 -> V_215 - 1 +
V_1 -> V_220 ) & 0xffff0000 ) |
( V_1 -> V_215 >> 16 ) ) ) ;
V_213 = ( V_1 -> V_221 -> V_222
- V_83 -> V_218 -> V_219
+ V_1 -> V_215 ) ;
} else
#endif
V_213 = ( V_1 -> V_221 -> V_222
- ( unsigned long ) V_83 -> V_223 -> V_224
+ V_1 -> V_215 ) ;
F_15 ( V_225 , V_213 ) ;
F_15 ( V_226 , 0 ) ;
V_185 = F_5 ( V_12 ) ;
F_15 ( V_91 , V_185 ) ;
F_63 ( V_1 , V_185 ) ;
V_1 -> V_186 . V_187 = V_185 ;
#if V_217
if ( V_1 -> V_4 & V_5 ) {
F_15 ( V_227 ,
V_1 -> V_6 -> V_222
- V_83 -> V_218 -> V_219 + V_1 -> V_215 ) ;
} else
#endif
{
F_15 ( V_227 ,
V_1 -> V_6 -> V_222
- ( ( unsigned long ) V_83 -> V_223 -> V_224 )
+ V_1 -> V_215 ) ;
}
#ifdef F_68
F_15 ( V_228 ,
V_229 |
( V_1 -> V_186 . V_230 << 18 ) |
( V_1 -> V_186 . V_231 << 8 ) |
V_1 -> V_186 . V_232 ) ;
#else
F_15 ( V_228 ,
( V_1 -> V_186 . V_230 << 18 ) |
( V_1 -> V_186 . V_231 << 8 ) |
V_1 -> V_186 . V_232 ) ;
#endif
F_15 ( V_233 , F_5 ( V_227 )
+ V_234 ) ;
F_15 ( V_235 , 0x7 ) ;
F_28 ( V_1 ) ;
F_6 ( V_1 , F_12 ( 0 ) , 0 ) ;
F_15 ( V_236 , 0 ) ;
F_6 ( V_1 , F_12 ( 1 ) , 0 ) ;
F_15 ( V_237 , 0 ) ;
F_6 ( V_1 , F_12 ( 2 ) , 0 ) ;
F_15 ( V_238 , 0 ) ;
V_212 = V_210 -> V_239 -> V_240 ;
if ( V_212 -> V_241 ) {
V_212 -> V_241 -> V_242 = 0 ;
V_212 -> V_241 -> V_243 = 0 ;
V_212 -> V_241 -> V_244 = 0 ;
}
F_39 ( V_1 ) ;
F_15 ( V_177 ,
( V_178 |
V_179 |
V_180 |
V_181 ) ) ;
}
static void F_69 ( T_2 * V_1 )
{
T_1 V_76 ;
V_1 -> V_8 = 0 ;
F_6 ( V_1 , F_12 ( 1 ) , 0 ) ;
F_15 ( V_245 , 0xdeadbeef ) ;
for ( V_76 = 0 ; V_76 < V_1 -> V_104 ; V_76 ++ ) {
T_1 V_3 ;
V_3 = F_1 ( V_1 , F_12 ( 1 ) ) ;
if ( V_3 == 0xdeadbeef )
break;
F_35 ( 1 ) ;
}
if ( V_76 < V_1 -> V_104 ) {
V_1 -> V_8 = 1 ;
F_41 ( L_26 , V_76 ) ;
} else {
V_1 -> V_8 = 0 ;
F_41 ( L_27 ) ;
}
if ( V_246 == 1 ) {
V_1 -> V_8 = 0 ;
F_41 ( L_28 ) ;
}
if ( ! V_1 -> V_8 ) {
F_15 ( V_228 , F_5 ( V_228 ) |
V_247 ) ;
F_15 ( V_235 , 0 ) ;
}
}
static void F_70 ( T_2 * V_1 , int V_248 )
{
T_1 V_249 ;
if ( V_248 ) {
F_38 ( L_29 ,
V_1 -> V_215 ,
( long ) V_1 -> V_250 . V_251 ,
V_1 -> V_220 ) ;
V_249 = F_19 ( V_1 , V_252 ) ;
if ( ( ( V_1 -> V_4 & V_9 ) == V_32 ) ||
( ( V_1 -> V_4 & V_9 ) == V_33 ) )
F_71 ( V_252 , ( V_253 |
V_254 ) ) ;
else
F_71 ( V_252 , V_253 ) ;
F_71 ( V_255 , ( V_256 |
V_257 ) ) ;
V_249 = F_19 ( V_1 , V_258 ) ;
F_71 ( V_258 , ( V_259 |
V_260 |
V_261 |
V_262 ) ) ;
V_249 = V_1 -> V_250 . V_251 & 0xfffff000 ;
V_249 |= ( F_27 ( V_1 -> V_250 . V_251 ) & 0xff ) << 4 ;
F_71 ( V_263 , V_249 ) ;
V_249 = F_19 ( V_1 , V_264 ) ;
F_71 ( V_264 , ( ( 1 << V_265 ) |
V_266 ) ) ;
F_26 ( V_1 , V_1 -> V_215 ) ;
V_1 -> V_220 = 32 * 1024 * 1024 ;
V_249 = ( ( ( V_1 -> V_215 - 1 + V_1 -> V_220 ) &
0xffff0000 ) | ( V_1 -> V_215 >> 16 ) ) ;
F_25 ( V_1 , V_249 ) ;
V_249 = F_19 ( V_1 , V_255 ) ;
F_71 ( V_255 , ( V_256 |
V_257 ) ) ;
do {
V_249 = F_19 ( V_1 , V_267 ) ;
if ( ( V_249 & V_268 ) == 0 )
break;
F_35 ( 1 ) ;
} while ( 1 );
F_71 ( V_267 ,
V_268 ) ;
do {
V_249 = F_19 ( V_1 , V_267 ) ;
if ( ( V_249 & V_268 ) == 0 )
break;
F_35 ( 1 ) ;
} while ( 1 );
F_71 ( V_267 , 0 ) ;
} else {
F_71 ( V_255 , 0 ) ;
}
}
static void F_72 ( T_2 * V_1 , int V_248 )
{
T_1 V_249 ;
int V_97 ;
if ( V_248 ) {
F_38 ( L_29 ,
V_1 -> V_215 ,
( long ) V_1 -> V_250 . V_251 ,
V_1 -> V_220 ) ;
F_71 ( V_269 , ( F_73 ( 6 ) |
F_74 ( 6 ) ) ) ;
for ( V_97 = 0 ; V_97 < 19 ; V_97 ++ )
F_71 ( V_270 + V_97 ,
( V_271 |
V_272 |
V_273 |
F_75 ( 3 ) |
V_274 |
F_76 ( 3 ) ) ) ;
F_71 ( V_275 , ( V_276 |
V_277 ) ) ;
for ( V_97 = 1 ; V_97 < 8 ; V_97 ++ )
F_71 ( V_275 + V_97 , 0 ) ;
F_71 ( V_278 ,
V_1 -> V_250 . V_251 ) ;
F_71 ( V_279 ,
V_1 -> V_215 ) ;
F_71 ( V_280 ,
( V_1 -> V_215 + V_1 -> V_220 - 1 ) ) ;
F_71 ( V_281 , 0 ) ;
F_71 ( V_282 ,
V_1 -> V_215 ) ;
F_71 ( V_283 ,
( V_1 -> V_215 + V_1 -> V_220 - 1 ) ) ;
V_249 = F_19 ( V_1 , V_269 ) ;
F_71 ( V_269 , ( V_249 | V_284 ) ) ;
V_249 = F_19 ( V_1 , V_285 ) ;
F_71 ( V_285 , ( V_249 | V_286 ) ) ;
V_249 = F_19 ( V_1 , V_269 ) ;
V_249 &= ~ ( V_287 | V_288 ) ;
F_71 ( V_269 , V_249 ) ;
V_249 = F_19 ( V_1 , V_269 ) ;
V_249 |= V_287 | V_288 ;
F_71 ( V_269 , V_249 ) ;
V_249 = F_19 ( V_1 , V_269 ) ;
V_249 &= ~ ( V_287 | V_288 ) ;
F_71 ( V_269 , V_249 ) ;
V_249 = F_19 ( V_1 , V_269 ) ;
} else {
F_71 ( V_269 , 0 ) ;
V_249 = F_19 ( V_1 , V_285 ) ;
V_249 &= ~ V_286 ;
F_71 ( V_285 , V_249 ) ;
}
}
static void F_77 ( T_2 * V_1 , int V_248 )
{
T_1 V_76 = F_31 ( V_1 , V_289 ) ;
if ( V_248 ) {
F_38 ( L_30 ,
V_1 -> V_215 ,
( long ) V_1 -> V_250 . V_251 ,
V_1 -> V_220 ) ;
F_78 ( V_290 ,
V_1 -> V_215 ) ;
F_78 ( V_291 ,
V_1 -> V_250 . V_251 ) ;
F_78 ( V_292 ,
V_1 -> V_215 ) ;
F_78 ( V_293 ,
V_1 -> V_215 +
V_1 -> V_220 - 1 ) ;
F_25 ( V_1 , 0xffffffc0 ) ;
F_78 ( V_289 ,
V_294 ) ;
} else {
F_78 ( V_289 ,
V_76 & ~ V_294 ) ;
}
}
static void F_79 ( T_2 * V_1 , int V_248 )
{
T_1 V_76 ;
if ( ( ( V_1 -> V_4 & V_9 ) == V_32 ) ||
( ( V_1 -> V_4 & V_9 ) == V_33 ) ||
( V_1 -> V_4 & V_295 ) ) {
F_70 ( V_1 , V_248 ) ;
return;
}
if ( ( V_1 -> V_4 & V_9 ) == V_34 ) {
F_72 ( V_1 , V_248 ) ;
return;
}
if ( V_1 -> V_4 & V_296 ) {
F_77 ( V_1 , V_248 ) ;
return;
}
V_76 = F_5 ( V_92 ) ;
if ( V_248 ) {
F_15 ( V_92 ,
V_76 | V_297 ) ;
F_15 ( V_94 , V_1 -> V_250 . V_251 ) ;
F_15 ( V_298 , V_1 -> V_215 ) ;
F_15 ( V_299 , V_1 -> V_215
+ V_1 -> V_220 - 1 ) ;
F_25 ( V_1 , 0xffffffc0 ) ;
F_15 ( V_300 , 0 ) ;
} else {
F_15 ( V_92 ,
V_76 & ~ V_297 ) ;
}
}
static int F_80 ( T_2 * V_1 )
{
struct V_301 * V_250 = & V_1 -> V_250 ;
struct V_302 * V_303 ;
int V_97 ;
for ( V_97 = 0 ; V_97 < V_304 * 2 ; V_97 ++ ) {
if ( ! V_1 -> V_305 [ V_97 ] . V_210 ||
V_1 -> V_305 [ V_97 ] . V_210 == V_306 )
break;
}
if ( V_97 >= 2 * V_304 )
return - V_307 ;
V_303 = & V_1 -> V_305 [ V_97 ] ;
for ( V_97 = 0 ; V_97 < V_304 ; V_97 ++ ) {
struct V_308 * V_309 = & V_1 -> V_310 [ V_97 ] ;
if ( V_309 -> V_311 )
continue;
V_303 -> V_312 = V_97 ;
V_303 -> V_313 = V_250 -> V_251 ;
V_303 -> V_314 = V_303 -> V_313 + V_250 -> V_315 ;
V_303 -> V_4 = 0 ;
V_303 -> V_210 = V_306 ;
V_309 -> V_311 = 1 ;
V_309 -> V_313 = V_303 -> V_313 ;
V_309 -> V_314 = V_303 -> V_314 ;
V_309 -> V_4 = 0 ;
F_15 ( V_316 + 16 * V_97 , V_309 -> V_4 ) ;
F_15 ( V_317 + 16 * V_97 , V_309 -> V_313 ) ;
F_15 ( V_318 + 16 * V_97 , V_309 -> V_314 ) ;
return 0 ;
}
return - V_307 ;
}
static int F_81 ( struct V_82 * V_83 , T_6 * V_319 ,
struct V_209 * V_210 )
{
T_2 * V_1 = V_83 -> V_84 ;
struct V_211 * V_212 = V_210 -> V_239 -> V_240 ;
F_38 ( L_14 ) ;
if ( ( V_1 -> V_4 & V_320 ) && ! V_1 -> V_214 ) {
F_36 ( L_31 ) ;
F_82 ( V_83 ) ;
return - V_143 ;
}
if ( V_319 -> V_321 && ( V_1 -> V_4 & V_5 ) ) {
F_38 ( L_32 ) ;
V_1 -> V_4 &= ~ V_5 ;
} else if ( ! ( V_1 -> V_4 & ( V_5 | V_322 | V_296 ) )
&& ! V_319 -> V_321 ) {
F_38 ( L_33 ) ;
V_1 -> V_4 |= V_5 ;
}
if ( ( ! ( V_1 -> V_4 & V_5 ) ) && ! V_83 -> V_223 ) {
F_36 ( L_34 ) ;
F_82 ( V_83 ) ;
return - V_143 ;
}
V_1 -> V_104 = V_319 -> V_104 ;
if ( V_1 -> V_104 < 1 ||
V_1 -> V_104 > V_323 ) {
F_38 ( L_35 ) ;
F_82 ( V_83 ) ;
return - V_143 ;
}
V_1 -> V_324 = V_325 ;
switch( V_319 -> V_326 ) {
case V_327 :
V_1 -> V_328 = V_329 ;
break;
case V_330 :
V_1 -> V_328 = V_331 ;
break;
default:
V_1 -> V_328 = V_332 ;
}
V_1 -> V_333 = 0 ;
V_1 -> V_174 = V_319 -> V_174 ;
if ( ( V_319 -> V_174 != V_334 ) &&
( V_319 -> V_174 != V_335 ) ) {
F_38 ( L_36 , V_319 -> V_174 ) ;
F_82 ( V_83 ) ;
return - V_143 ;
}
switch ( V_319 -> V_336 ) {
case 16 :
V_1 -> V_337 = V_338 ;
break;
case 32 :
default:
V_1 -> V_337 = V_339 ;
break;
}
V_1 -> V_340 = V_319 -> V_340 ;
V_1 -> V_341 = V_319 -> V_341 ;
V_1 -> V_342 = V_319 -> V_342 ;
V_1 -> V_343 = V_319 -> V_343 ;
switch ( V_319 -> V_344 ) {
case 16 :
V_1 -> V_345 = V_346 ;
break;
case 32 :
default:
V_1 -> V_345 = V_347 ;
break;
}
V_1 -> V_348 = V_319 -> V_348 ;
V_1 -> V_349 = V_319 -> V_349 ;
V_1 -> V_350 . V_351 = ( V_352 |
( V_1 -> V_337 << 10 ) |
( V_1 -> V_328 ==
V_332 ? V_353 : 0 ) ) ;
V_1 -> V_350 . V_354 =
( V_1 -> V_345 |
V_355 |
V_356 |
V_357 |
V_358 |
V_359 | V_360 ) ;
V_1 -> V_350 . V_361 = ( V_362 |
V_363 |
V_364 |
V_365 |
V_366 |
V_367 |
V_368 |
V_369 |
V_370 |
V_371 |
V_372 ) ;
V_1 -> V_373 = V_319 -> V_373 ;
V_1 -> V_374 = V_319 -> V_374 ;
V_1 -> V_375 = V_319 -> V_375 ;
V_1 -> V_376 = V_319 -> V_376 ;
V_212 -> V_377 = F_83 ( V_83 ) ;
if ( ! V_212 -> V_377 ) {
F_36 ( L_37 ) ;
F_82 ( V_83 ) ;
return - V_143 ;
}
V_1 -> V_221 = F_84 ( V_83 , V_319 -> V_373 ) ;
if ( ! V_1 -> V_221 ) {
F_36 ( L_38 ) ;
F_82 ( V_83 ) ;
return - V_143 ;
}
V_1 -> V_6 = F_84 ( V_83 , V_319 -> V_374 ) ;
if ( ! V_1 -> V_6 ) {
F_36 ( L_39 ) ;
F_82 ( V_83 ) ;
return - V_143 ;
}
V_83 -> V_378 = V_319 -> V_375 ;
V_83 -> V_379 = F_84 ( V_83 , V_319 -> V_375 ) ;
if ( ! V_83 -> V_379 ) {
F_36 ( L_40 ) ;
F_82 ( V_83 ) ;
return - V_143 ;
}
if ( V_319 -> V_376 ) {
V_1 -> V_380 =
F_84 ( V_83 , V_319 -> V_376 ) ;
if ( ! V_1 -> V_380 ) {
F_36 ( L_41 ) ;
F_82 ( V_83 ) ;
return - V_143 ;
}
}
#if V_217
if ( V_1 -> V_4 & V_5 ) {
F_85 ( V_1 -> V_221 , V_83 ) ;
F_85 ( V_1 -> V_6 , V_83 ) ;
F_85 ( V_83 -> V_379 , V_83 ) ;
if ( ! V_1 -> V_221 -> V_7 ||
! V_1 -> V_6 -> V_7 ||
! V_83 -> V_379 -> V_7 ) {
F_36 ( L_42 ) ;
F_82 ( V_83 ) ;
return - V_143 ;
}
} else
#endif
{
V_1 -> V_221 -> V_7 =
( void * ) ( unsigned long ) V_1 -> V_221 -> V_222 ;
V_1 -> V_6 -> V_7 =
( void * ) ( unsigned long ) V_1 -> V_6 -> V_222 ;
V_83 -> V_379 -> V_7 =
( void * ) ( unsigned long ) V_83 -> V_379 -> V_222 ;
F_38 ( L_43 ,
V_1 -> V_221 -> V_7 ) ;
F_38 ( L_44 ,
V_1 -> V_6 -> V_7 ) ;
F_38 ( L_45 ,
V_83 -> V_379 -> V_7 ) ;
}
V_1 -> V_216 = ( F_20 ( V_1 ) & 0xffff ) << 16 ;
V_1 -> V_381 =
( ( F_20 ( V_1 ) & 0xffff0000u ) + 0x10000 )
- V_1 -> V_216 ;
V_1 -> V_382 = ( ( ( V_1 -> V_341 / 64 ) << 22 ) |
( ( V_1 -> V_340
+ V_1 -> V_216 ) >> 10 ) ) ;
V_1 -> V_383 = ( ( ( V_1 -> V_343 / 64 ) << 22 ) |
( ( V_1 -> V_342
+ V_1 -> V_216 ) >> 10 ) ) ;
V_1 -> V_384 = ( ( ( V_1 -> V_349 / 64 ) << 22 ) |
( ( V_1 -> V_348
+ V_1 -> V_216 ) >> 10 ) ) ;
V_1 -> V_220 = V_319 -> V_220 ;
if ( V_1 -> V_214 ) {
T_1 V_219 = 0 ;
F_41 ( L_46 ) ;
#if V_217
if ( V_1 -> V_4 & V_5 ) {
V_219 = V_83 -> V_218 -> V_219 ;
if ( ( V_219 + V_1 -> V_220 - 1 ) >= V_1 -> V_216 &&
V_219 < ( V_1 -> V_216 + V_1 -> V_381 - 1 ) ) {
F_41 ( L_47 ,
V_83 -> V_218 -> V_219 ) ;
V_219 = 0 ;
}
}
#endif
if ( V_219 == 0 ) {
V_219 = V_1 -> V_216 + V_1 -> V_381 ;
if ( V_219 < V_1 -> V_216 ||
( ( V_219 + V_1 -> V_220 ) & 0xfffffffful ) < V_219 )
V_219 = V_1 -> V_216
- V_1 -> V_220 ;
}
V_1 -> V_215 = V_219 & 0xffc00000u ;
if ( V_1 -> V_215 != V_219 )
F_41 ( L_48 ,
V_219 , V_1 -> V_215 ) ;
} else {
F_41 ( L_49 ) ;
V_1 -> V_215 = V_1 -> V_216 +
F_5 ( V_385 ) ;
}
#if V_217
if ( V_1 -> V_4 & V_5 )
V_1 -> V_386 = ( V_83 -> V_379 -> V_222
- V_83 -> V_218 -> V_219
+ V_1 -> V_215 ) ;
else
#endif
V_1 -> V_386 = ( V_83 -> V_379 -> V_222
- ( unsigned long ) V_83 -> V_223 -> V_224
+ V_1 -> V_215 ) ;
F_38 ( L_50 , V_1 -> V_220 ) ;
F_38 ( L_51 , V_1 -> V_215 ) ;
F_38 ( L_52 ,
V_1 -> V_386 ) ;
V_1 -> V_186 . V_387 = ( T_1 * ) V_1 -> V_221 -> V_7 ;
V_1 -> V_186 . V_388 = ( ( T_1 * ) V_1 -> V_221 -> V_7
+ V_319 -> V_389 / sizeof( T_1 ) ) ;
V_1 -> V_186 . V_166 = V_319 -> V_389 ;
V_1 -> V_186 . V_232 = F_86 ( V_319 -> V_389 / 8 ) ;
V_1 -> V_186 . V_390 = 4096 ;
V_1 -> V_186 . V_231 = F_86 ( 4096 / 8 ) ;
V_1 -> V_186 . V_391 = 32 ;
V_1 -> V_186 . V_230 = F_86 ( 32 / 16 ) ;
V_1 -> V_186 . V_392 = ( V_1 -> V_186 . V_166 / sizeof( T_1 ) ) - 1 ;
V_1 -> V_186 . V_393 = V_394 ;
#if V_217
if ( V_1 -> V_4 & V_5 ) {
F_79 ( V_1 , 0 ) ;
} else
#endif
{
T_1 V_395 ;
int V_17 ;
V_1 -> V_250 . V_396 = F_87 ( 32 ) ;
if ( V_1 -> V_397 ) {
V_1 -> V_250 . V_251 =
( V_398 ) V_1 -> V_399 + V_1 -> V_216 ;
V_1 -> V_250 . V_400 . V_222 =
V_1 -> V_399 + V_1 -> V_401 ;
V_1 -> V_250 . V_400 . V_166 =
V_1 -> V_250 . V_315 ;
F_85 ( & V_1 -> V_250 . V_400 , V_83 ) ;
V_1 -> V_250 . V_16 =
V_1 -> V_250 . V_400 . V_7 ;
if ( V_1 -> V_4 & V_296 )
V_1 -> V_250 . V_402 = V_403 ;
else
V_1 -> V_250 . V_402 = V_404 ;
V_1 -> V_250 . V_405 =
V_406 ;
F_38 ( L_53 ,
V_1 -> V_250 . V_16 ,
V_1 -> V_399 ) ;
} else {
if ( V_1 -> V_4 & V_295 )
V_1 -> V_250 . V_402 = V_407 ;
else
V_1 -> V_250 . V_402 = V_404 ;
V_1 -> V_250 . V_405 =
V_408 ;
V_1 -> V_250 . V_16 = NULL ;
V_1 -> V_250 . V_251 = 0 ;
if ( V_1 -> V_4 & V_296 ) {
F_36
( L_54 ) ;
F_82 ( V_83 ) ;
return - V_143 ;
}
}
V_395 = F_5 ( V_409 ) ;
F_15 ( V_409 , 0 ) ;
if ( ( V_1 -> V_4 & V_9 ) == V_34 )
V_17 = F_88 ( V_83 ) ;
else
V_17 = F_89 ( V_83 , & V_1 -> V_250 ) ;
F_15 ( V_409 , V_395 ) ;
if ( ! V_17 ) {
F_36 ( L_55 ) ;
F_82 ( V_83 ) ;
return - V_307 ;
}
V_17 = F_80 ( V_1 ) ;
if ( V_17 ) {
F_36 ( L_56 ) ;
if ( ( V_1 -> V_4 & V_9 ) == V_34 )
F_90 ( V_83 , & V_1 -> V_250 ) ;
else
F_91 ( V_83 , & V_1 -> V_250 ) ;
F_82 ( V_83 ) ;
return V_17 ;
}
F_79 ( V_1 , 1 ) ;
}
if ( ! V_1 -> V_165 ) {
int V_141 = F_43 ( V_1 ) ;
if ( V_141 ) {
F_36 ( L_57 ) ;
F_82 ( V_83 ) ;
return V_141 ;
}
}
F_49 ( V_1 ) ;
F_67 ( V_83 , V_1 , V_210 ) ;
V_1 -> V_410 = 0 ;
F_65 ( V_83 ) ;
F_69 ( V_1 ) ;
return 0 ;
}
static int F_82 ( struct V_82 * V_83 )
{
T_2 * V_1 = V_83 -> V_84 ;
F_38 ( L_14 ) ;
if ( V_83 -> V_411 )
F_92 ( V_83 ) ;
#if V_217
if ( V_1 -> V_4 & V_5 ) {
if ( V_1 -> V_221 != NULL ) {
F_93 ( V_1 -> V_221 , V_83 ) ;
V_1 -> V_221 = NULL ;
}
if ( V_1 -> V_6 != NULL ) {
F_93 ( V_1 -> V_6 , V_83 ) ;
V_1 -> V_6 = NULL ;
}
if ( V_83 -> V_379 != NULL ) {
F_93 ( V_83 -> V_379 , V_83 ) ;
V_83 -> V_379 = NULL ;
}
} else
#endif
{
if ( V_1 -> V_250 . V_251 ) {
F_79 ( V_1 , 0 ) ;
if ( ( V_1 -> V_4 & V_9 ) == V_34 )
F_90 ( V_83 , & V_1 -> V_250 ) ;
else {
if ( ! F_91 ( V_83 , & V_1 -> V_250 ) )
F_36 ( L_58 ) ;
}
}
if ( V_1 -> V_250 . V_405 == V_406 )
{
F_93 ( & V_1 -> V_250 . V_400 , V_83 ) ;
V_1 -> V_250 . V_16 = NULL ;
}
}
memset ( V_1 , 0 , F_94 ( T_2 , V_4 ) ) ;
return 0 ;
}
static int F_95 ( struct V_82 * V_83 , struct V_209 * V_210 )
{
T_2 * V_1 = V_83 -> V_84 ;
if ( ! V_1 ) {
F_36 ( L_59 ) ;
return - V_143 ;
}
F_38 ( L_60 ) ;
#if V_217
if ( V_1 -> V_4 & V_5 ) {
F_79 ( V_1 , 0 ) ;
} else
#endif
{
F_79 ( V_1 , 1 ) ;
}
F_49 ( V_1 ) ;
F_67 ( V_83 , V_1 , V_210 ) ;
V_1 -> V_412 = 0 ;
F_65 ( V_83 ) ;
F_96 ( V_83 , V_413 , 1 ) ;
F_38 ( L_61 ) ;
return 0 ;
}
int F_97 ( struct V_82 * V_83 , void * V_168 , struct V_209 * V_210 )
{
T_2 * V_1 = V_83 -> V_84 ;
T_6 * V_319 = V_168 ;
F_98 ( V_83 , V_210 ) ;
if ( V_319 -> V_326 == V_330 )
F_99 ( V_83 ) ;
switch ( V_319 -> V_326 ) {
case V_414 :
case V_327 :
case V_330 :
return F_81 ( V_83 , V_319 , V_210 ) ;
case V_415 :
return F_100 ( V_83 , V_319 , V_210 ) ;
case V_416 :
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
return F_101 ( V_83 ) ;
else
return F_82 ( V_83 ) ;
}
return - V_143 ;
}
int F_102 ( struct V_82 * V_83 , void * V_168 , struct V_209 * V_210 )
{
T_2 * V_1 = V_83 -> V_84 ;
F_38 ( L_14 ) ;
F_98 ( V_83 , V_210 ) ;
if ( V_1 -> V_175 ) {
F_38 ( L_62 ) ;
return 0 ;
}
if ( V_1 -> V_174 == V_190 ) {
F_38 ( L_63 ,
V_1 -> V_174 ) ;
return 0 ;
}
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
F_103 ( V_1 ) ;
else
F_59 ( V_1 ) ;
return 0 ;
}
int F_104 ( struct V_82 * V_83 , void * V_168 , struct V_209 * V_210 )
{
T_2 * V_1 = V_83 -> V_84 ;
T_7 * V_417 = V_168 ;
int V_17 ;
F_38 ( L_14 ) ;
F_98 ( V_83 , V_210 ) ;
if ( ! V_1 -> V_175 )
return 0 ;
if ( V_417 -> V_418 ) {
F_51 ( V_1 ) ;
}
if ( V_417 -> V_419 ) {
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
V_17 = F_105 ( V_1 ) ;
else
V_17 = F_52 ( V_1 ) ;
if ( V_17 )
return V_17 ;
}
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
F_106 ( V_1 ) ;
else
F_64 ( V_1 ) ;
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
F_107 ( V_83 ) ;
else
F_65 ( V_83 ) ;
return 0 ;
}
void F_108 ( struct V_82 * V_83 )
{
T_2 * V_1 = V_83 -> V_84 ;
int V_97 , V_17 ;
if ( V_1 ) {
if ( V_1 -> V_175 ) {
if ( ( V_1 -> V_4 & V_9 ) >= V_10 ) {
while ( ( V_17 = F_105 ( V_1 ) ) != 0 ) {
F_38 ( L_64 , V_17 ) ;
#ifdef F_109
F_110 () ;
#else
F_111 ( & V_17 , V_420 , L_65 , 1 ) ;
#endif
}
} else {
while ( ( V_17 = F_52 ( V_1 ) ) != 0 ) {
F_38 ( L_64 , V_17 ) ;
#ifdef F_109
F_110 () ;
#else
F_111 ( & V_17 , V_420 , L_65 , 1 ) ;
#endif
}
}
if ( ( V_1 -> V_4 & V_9 ) >= V_10 ) {
F_106 ( V_1 ) ;
F_107 ( V_83 ) ;
} else {
F_64 ( V_1 ) ;
F_65 ( V_83 ) ;
}
}
if ( ( V_1 -> V_4 & V_9 ) < V_10 ) {
if ( V_1 -> V_18 )
F_15 ( V_421 , 0 ) ;
if ( V_1 -> V_18 ) {
for ( V_97 = 0 ; V_97 < V_304 ; V_97 ++ ) {
F_15 ( V_316 + 16 * V_97 , 0 ) ;
F_15 ( V_317 +
16 * V_97 , 0 ) ;
F_15 ( V_318 +
16 * V_97 , 0 ) ;
}
}
}
F_112 ( & ( V_1 -> V_422 ) ) ;
F_112 ( & ( V_1 -> V_423 ) ) ;
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
F_101 ( V_83 ) ;
else
F_82 ( V_83 ) ;
if ( V_1 -> V_165 ) {
F_48 ( V_1 -> V_165 ) ;
V_1 -> V_165 = NULL ;
}
if ( V_1 -> V_424 ) {
F_48 ( V_1 -> V_424 ) ;
V_1 -> V_424 = NULL ;
}
}
}
int F_113 ( struct V_82 * V_83 , void * V_168 , struct V_209 * V_210 )
{
T_2 * V_1 = V_83 -> V_84 ;
F_38 ( L_14 ) ;
F_98 ( V_83 , V_210 ) ;
if ( ! V_1 ) {
F_38 ( L_66 ) ;
return - V_143 ;
}
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
F_114 ( V_1 ) ;
else
F_62 ( V_1 ) ;
V_1 -> V_175 = 0 ;
return 0 ;
}
int F_115 ( struct V_82 * V_83 , void * V_168 , struct V_209 * V_210 )
{
T_2 * V_1 = V_83 -> V_84 ;
F_38 ( L_14 ) ;
F_98 ( V_83 , V_210 ) ;
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
return F_105 ( V_1 ) ;
else
return F_52 ( V_1 ) ;
}
int F_116 ( struct V_82 * V_83 , void * V_168 , struct V_209 * V_210 )
{
T_2 * V_1 = V_83 -> V_84 ;
F_38 ( L_14 ) ;
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
return F_117 ( V_83 , V_210 ) ;
else
return F_95 ( V_83 , V_210 ) ;
}
int F_118 ( struct V_82 * V_83 , void * V_168 , struct V_209 * V_210 )
{
T_2 * V_1 = V_83 -> V_84 ;
F_38 ( L_14 ) ;
F_98 ( V_83 , V_210 ) ;
if ( ( V_1 -> V_4 & V_9 ) >= V_10 )
return F_107 ( V_83 ) ;
else
return F_65 ( V_83 ) ;
}
int F_119 ( struct V_82 * V_83 , void * V_168 , struct V_209 * V_210 )
{
return 0 ;
}
struct V_425 * F_120 ( struct V_82 * V_83 )
{
struct V_426 * V_427 = V_83 -> V_427 ;
T_2 * V_1 = V_83 -> V_84 ;
T_8 * V_428 ;
struct V_425 * V_429 ;
int V_97 , V_430 ;
int V_387 ;
if ( ++ V_1 -> V_410 >= V_427 -> V_431 )
V_1 -> V_410 = 0 ;
V_387 = V_1 -> V_410 ;
for ( V_430 = 0 ; V_430 < V_1 -> V_104 ; V_430 ++ ) {
T_1 V_432 = F_121 ( V_1 , 1 ) ;
F_38 ( L_67 , V_432 ) ;
for ( V_97 = 0 ; V_97 < V_427 -> V_431 ; V_97 ++ ) {
V_429 = V_427 -> V_433 [ V_387 ] ;
V_428 = V_429 -> V_84 ;
if ( V_429 -> V_210 == NULL || ( V_429 -> V_434 &&
V_428 -> V_435 <=
V_432 ) ) {
V_1 -> V_98 . V_436 ++ ;
V_429 -> V_434 = 0 ;
return V_429 ;
}
if ( ++ V_387 >= V_427 -> V_431 )
V_387 = 0 ;
}
if ( V_430 ) {
F_35 ( 1 ) ;
V_1 -> V_98 . V_437 ++ ;
}
}
return NULL ;
}
void F_66 ( struct V_82 * V_83 )
{
struct V_426 * V_427 = V_83 -> V_427 ;
T_2 * V_1 = V_83 -> V_84 ;
int V_97 ;
V_1 -> V_410 = 0 ;
for ( V_97 = 0 ; V_97 < V_427 -> V_431 ; V_97 ++ ) {
struct V_425 * V_429 = V_427 -> V_433 [ V_97 ] ;
T_8 * V_428 = V_429 -> V_84 ;
V_428 -> V_435 = 0 ;
}
}
int F_122 ( T_2 * V_1 , int V_438 )
{
T_9 * V_186 = & V_1 -> V_186 ;
int V_97 ;
T_1 V_439 = F_123 ( V_1 ) ;
for ( V_97 = 0 ; V_97 < V_1 -> V_104 ; V_97 ++ ) {
T_1 V_440 = F_123 ( V_1 ) ;
V_186 -> V_441 = ( V_440 - V_186 -> V_187 ) * sizeof( T_1 ) ;
if ( V_186 -> V_441 <= 0 )
V_186 -> V_441 += V_186 -> V_166 ;
if ( V_186 -> V_441 > V_438 )
return 0 ;
V_1 -> V_98 . V_99 |= V_100 ;
if ( V_440 != V_439 )
V_97 = 0 ;
V_439 = V_440 ;
F_35 ( 1 ) ;
}
#if V_106
F_32 ( V_1 ) ;
F_36 ( L_10 ) ;
#endif
return - V_107 ;
}
static int F_124 ( struct V_82 * V_83 ,
struct V_209 * V_210 ,
struct V_442 * V_443 )
{
int V_97 ;
struct V_425 * V_429 ;
for ( V_97 = V_443 -> V_444 ; V_97 < V_443 -> V_445 ; V_97 ++ ) {
V_429 = F_120 ( V_83 ) ;
if ( ! V_429 )
return - V_107 ;
V_429 -> V_210 = V_210 ;
if ( F_125 ( & V_443 -> V_446 [ V_97 ] , & V_429 -> V_447 ,
sizeof( V_429 -> V_447 ) ) )
return - V_448 ;
if ( F_125 ( & V_443 -> V_449 [ V_97 ] , & V_429 -> V_450 ,
sizeof( V_429 -> V_450 ) ) )
return - V_448 ;
V_443 -> V_444 ++ ;
}
return 0 ;
}
int F_126 ( struct V_82 * V_83 , void * V_168 , struct V_209 * V_210 )
{
struct V_426 * V_427 = V_83 -> V_427 ;
int V_17 = 0 ;
struct V_442 * V_443 = V_168 ;
F_98 ( V_83 , V_210 ) ;
if ( V_443 -> V_451 != 0 ) {
F_36 ( L_68 ,
V_452 , V_443 -> V_451 ) ;
return - V_143 ;
}
if ( V_443 -> V_445 < 0 || V_443 -> V_445 > V_427 -> V_431 ) {
F_36 ( L_69 ,
V_452 , V_443 -> V_445 , V_427 -> V_431 ) ;
return - V_143 ;
}
V_443 -> V_444 = 0 ;
if ( V_443 -> V_445 ) {
V_17 = F_124 ( V_83 , V_210 , V_443 ) ;
}
return V_17 ;
}
int F_127 ( struct V_82 * V_83 , unsigned long V_4 )
{
T_2 * V_1 ;
int V_17 = 0 ;
V_1 = F_128 ( sizeof( T_2 ) , V_453 ) ;
if ( V_1 == NULL )
return - V_307 ;
V_83 -> V_84 = ( void * ) V_1 ;
V_1 -> V_4 = V_4 ;
switch ( V_4 & V_9 ) {
case V_144 :
case V_146 :
case V_73 :
case V_123 :
case V_124 :
case V_80 :
case V_155 :
case V_156 :
case V_38 :
case V_160 :
case V_163 :
case V_161 :
V_1 -> V_4 |= V_454 ;
break;
default:
break;
}
F_129 ( V_83 -> V_121 ) ;
if ( F_130 ( V_83 ) )
V_1 -> V_4 |= V_5 ;
else if ( F_131 ( V_83 -> V_121 ) )
V_1 -> V_4 |= V_296 ;
else
V_1 -> V_4 |= V_322 ;
V_17 = F_132 ( V_83 , F_133 ( V_83 -> V_121 , 2 ) ,
F_134 ( V_83 -> V_121 , 2 ) , V_455 ,
V_456 | V_457 , & V_1 -> V_18 ) ;
if ( V_17 != 0 )
return V_17 ;
V_17 = F_135 ( V_83 , 2 ) ;
if ( V_17 ) {
F_136 ( V_83 ) ;
return V_17 ;
}
F_38 ( L_70 ,
( ( V_1 -> V_4 & V_5 ) ? L_71 : ( ( ( V_1 -> V_4 & V_296 ) ? L_72 : L_73 ) ) ) ) ;
return V_17 ;
}
int F_137 ( struct V_82 * V_83 , struct V_458 * V_239 )
{
struct V_211 * V_212 ;
unsigned long V_459 ;
int V_17 ;
V_212 = F_128 ( sizeof( * V_212 ) , V_453 ) ;
if ( ! V_212 )
return - V_307 ;
V_459 = F_138 (unsigned long, SAREA_MAX, PAGE_SIZE) ;
V_17 = F_132 ( V_83 , 0 , V_459 , V_460 , V_461 ,
& V_212 -> V_377 ) ;
if ( V_17 ) {
F_36 ( L_74 ) ;
F_139 ( V_212 ) ;
return V_17 ;
}
V_212 -> V_241 = V_212 -> V_377 -> V_7 + sizeof( struct V_462 ) ;
V_212 -> V_241 -> V_463 = 0 ;
V_239 -> V_240 = V_212 ;
return 0 ;
}
void F_140 ( struct V_82 * V_83 , struct V_458 * V_239 )
{
struct V_211 * V_212 = V_239 -> V_240 ;
if ( ! V_212 )
return;
if ( V_212 -> V_241 &&
V_212 -> V_241 -> V_463 != 0 )
F_141 ( V_83 , V_239 ) ;
V_212 -> V_241 = NULL ;
if ( V_212 -> V_377 )
F_142 ( V_83 , V_212 -> V_377 ) ;
F_139 ( V_212 ) ;
V_239 -> V_240 = NULL ;
}
int F_143 ( struct V_82 * V_83 )
{
int V_17 ;
T_10 * V_464 ;
T_2 * V_1 = V_83 -> V_84 ;
V_1 -> V_250 . V_315 = V_465 ;
V_1 -> V_401 = F_133 ( V_83 -> V_121 , 0 ) ;
V_17 = F_132 ( V_83 , V_1 -> V_401 ,
F_134 ( V_83 -> V_121 , 0 ) , V_466 ,
V_467 , & V_464 ) ;
if ( V_17 != 0 )
return V_17 ;
return 0 ;
}
int F_136 ( struct V_82 * V_83 )
{
T_2 * V_1 = V_83 -> V_84 ;
F_38 ( L_14 ) ;
F_144 ( V_83 , V_1 -> V_18 ) ;
F_139 ( V_1 ) ;
V_83 -> V_84 = NULL ;
return 0 ;
}
void F_145 ( T_2 * V_1 )
{
int V_97 ;
T_1 * V_186 ;
int V_468 ;
V_468 = V_1 -> V_186 . V_187 & ( V_469 - 1 ) ;
if ( V_468 ) {
int V_470 = V_469 - V_468 ;
V_186 = V_1 -> V_186 . V_387 ;
for ( V_97 = 0 ; V_97 < V_470 ; V_97 ++ )
V_186 [ V_1 -> V_186 . V_187 + V_97 ] = F_146 () ;
V_1 -> V_186 . V_187 += V_97 ;
V_1 -> V_186 . V_441 -= V_470 * sizeof( T_1 ) ;
}
V_1 -> V_186 . V_187 &= V_1 -> V_186 . V_392 ;
F_147 () ;
F_123 ( V_1 ) ;
if ( ( V_1 -> V_4 & V_9 ) >= V_10 ) {
F_15 ( V_471 , V_1 -> V_186 . V_187 ) ;
F_5 ( V_11 ) ;
} else {
F_15 ( V_91 , V_1 -> V_186 . V_187 ) ;
F_5 ( V_12 ) ;
}
}
