static inline int F_1 ( T_1 V_1 )
{
if ( F_2 ( V_1 < F_3 ( V_2 ) ) )
return V_2 [ V_1 ] ;
return - V_3 ;
}
static inline int
F_4 ( struct V_4 * V_5 , T_1 V_1 )
{
if ( F_2 ( V_1 < F_3 ( V_2 ) ) )
return V_5 -> V_6 [ V_2 [ V_1 ] ] ;
return - V_3 ;
}
static void F_5 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
T_2 V_17 )
{
T_3 V_18 = V_16 -> V_19 ;
T_4 V_20 = V_12 -> V_20 ;
V_12 -> V_21 . V_22 = V_23 ;
if ( ! ( V_14 -> V_24 & V_25 ) ) {
V_20 |= V_26 ;
if ( F_6 ( V_18 ) )
V_20 |= V_27 ;
if ( F_7 ( V_18 ) &&
! ( F_8 ( V_16 -> V_28 ) & 0xf ) )
V_20 |= V_29 ;
} else {
V_20 &= ( ~ V_26 ) ;
V_20 |= V_27 ;
}
if ( F_9 ( V_18 ) )
V_20 |= V_26 | V_30 ;
V_12 -> V_31 = V_17 ;
if ( F_10 ( V_18 ) )
V_20 |= V_32 ;
if ( F_11 ( V_18 ) ) {
T_2 * V_33 = F_12 ( V_16 ) ;
V_12 -> V_34 = V_33 [ 0 ] & 0xf ;
V_20 &= ~ V_27 ;
} else {
V_20 |= V_27 ;
}
F_13 ( V_8 , V_14 , V_18 , & V_20 ) ;
V_20 &= ~ ( V_35 ) ;
if ( F_6 ( V_18 ) ) {
if ( F_14 ( V_18 ) || F_15 ( V_18 ) )
V_12 -> V_36 . V_37 = F_16 ( 3 ) ;
else
V_12 -> V_36 . V_37 = F_16 ( 2 ) ;
} else {
V_12 -> V_36 . V_37 = 0 ;
}
V_12 -> V_38 = 0 ;
V_12 -> V_20 = V_20 ;
V_12 -> V_39 = 0 ;
}
static void F_17 ( struct V_7 * V_8 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
T_3 V_18 )
{
T_5 V_40 ;
int V_41 ;
T_2 V_42 ;
T_2 V_43 ;
T_2 V_44 ;
if ( F_7 ( V_18 ) )
V_43 = 3 ;
else
V_43 = V_45 ;
V_12 -> V_43 = V_43 ;
V_42 = V_46 ;
if ( V_43 < V_42 )
V_42 = V_43 ;
V_12 -> V_42 = V_42 ;
if ( F_18 ( V_18 ) ) {
V_12 -> V_47 = 0 ;
V_12 -> V_20 |= V_48 ;
return;
}
V_41 = V_14 -> V_49 . V_50 [ 0 ] . V_51 ;
if ( V_14 -> V_49 . V_50 [ 0 ] . V_24 & V_52 ||
( V_41 < 0 ) || ( V_41 > V_53 ) )
V_41 = F_19 ( & V_8 -> V_54 [ V_14 -> V_55 ] ,
V_14 -> V_49 . V_56 ) ;
if ( V_14 -> V_55 == V_57 )
V_41 += V_58 ;
V_44 = V_59 [ V_41 ] . V_60 ;
V_40 = 0 ;
if ( ( V_41 >= V_61 ) && ( V_41 <= V_62 ) )
V_40 |= V_63 ;
V_8 -> V_64 = F_20 ( V_8 , V_8 -> V_64 ,
V_8 -> V_65 . V_66 ) ;
V_40 |= F_21 ( V_8 -> V_64 ) ;
V_12 -> V_67 = F_22 ( V_44 , V_40 ) ;
}
static void F_23 ( struct V_7 * V_8 ,
struct V_13 * V_14 ,
struct V_11 * V_12 ,
struct V_9 * V_68 ,
int V_31 )
{
struct V_69 * V_70 = V_14 -> V_49 . V_71 ;
switch ( V_70 -> V_72 ) {
case V_73 :
V_12 -> V_74 = V_75 ;
memcpy ( V_12 -> V_76 , V_70 -> V_76 , V_70 -> V_77 ) ;
if ( V_14 -> V_24 & V_78 )
V_12 -> V_20 |= V_79 ;
F_24 ( V_8 , L_1 ) ;
break;
case V_80 :
V_12 -> V_74 = V_81 ;
F_25 ( V_70 , V_68 , V_12 -> V_76 ) ;
F_24 ( V_8 , L_2 ) ;
break;
case V_82 :
V_12 -> V_74 |= V_83 ;
case V_84 :
V_12 -> V_74 |= ( V_85 |
( V_70 -> V_86 & V_87 ) << V_88 ) ;
memcpy ( & V_12 -> V_76 [ 3 ] , V_70 -> V_76 , V_70 -> V_77 ) ;
F_24 ( V_8 , L_3
L_4 , V_70 -> V_86 ) ;
break;
default:
F_26 ( V_8 , L_5 , V_70 -> V_72 ) ;
break;
}
}
int F_27 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_15 * V_16 = (struct V_15 * ) V_10 -> V_89 ;
struct V_13 * V_14 = F_28 ( V_10 ) ;
struct V_90 * V_56 = V_14 -> V_49 . V_56 ;
struct V_91 * V_92 = NULL ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
struct V_11 * V_12 ;
struct V_4 * V_5 = & V_8 -> V_101 [ V_102 ] ;
int V_103 ;
T_6 V_104 ;
T_6 V_105 ;
T_6 V_106 ;
T_1 V_107 , V_108 , V_109 ;
T_1 V_110 = 0 ;
T_3 V_18 ;
T_2 V_111 ;
T_2 V_31 ;
T_2 V_112 = 0 ;
T_2 V_1 = 0 ;
T_2 * V_33 = NULL ;
unsigned long V_24 ;
bool V_113 = false ;
if ( V_14 -> V_49 . V_114 )
V_5 = F_29 ( V_14 -> V_49 . V_114 ) ;
F_30 ( & V_8 -> V_115 , V_24 ) ;
if ( F_31 ( V_8 ) ) {
F_32 ( V_8 , L_6 ) ;
goto V_116;
}
V_18 = V_16 -> V_19 ;
#ifdef F_33
if ( F_34 ( V_18 ) )
F_24 ( V_8 , L_7 ) ;
else if ( F_14 ( V_18 ) )
F_24 ( V_8 , L_8 ) ;
else if ( F_15 ( V_18 ) )
F_24 ( V_8 , L_9 ) ;
#endif
V_111 = F_35 ( V_18 ) ;
if ( ! F_18 ( V_18 ) )
V_31 = V_5 -> V_117 ;
else {
V_31 = F_36 ( V_8 , V_5 , V_14 -> V_49 . V_56 ) ;
if ( V_31 == V_118 ) {
F_32 ( V_8 , L_10 ,
V_16 -> V_119 ) ;
goto V_116;
}
}
F_24 ( V_8 , L_11 , V_31 ) ;
if ( V_56 )
V_92 = ( void * ) V_56 -> V_120 ;
if ( V_92 && V_92 -> V_121 &&
( V_14 -> V_24 & V_122 ) ) {
F_37 ( V_8 , V_31 , 1 ) ;
}
if ( V_14 -> V_24 & V_123 ) {
V_103 = V_5 -> V_124 ;
V_16 -> V_19 |=
F_16 ( V_125 ) ;
} else
V_103 = V_5 -> V_126 [ F_38 ( V_10 ) ] ;
F_39 ( & V_8 -> V_127 ) ;
if ( F_11 ( V_18 ) ) {
V_33 = F_12 ( V_16 ) ;
V_1 = V_33 [ 0 ] & V_128 ;
if ( F_40 ( V_1 >= V_129 ) ) {
F_41 ( & V_8 -> V_127 ) ;
goto V_116;
}
V_110 = V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] . V_110 ;
V_110 &= V_131 ;
V_16 -> V_28 = V_16 -> V_28 &
F_16 ( V_132 ) ;
V_16 -> V_28 |= F_16 ( V_110 ) ;
V_110 += 0x10 ;
if ( V_14 -> V_24 & V_78 &&
V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] . V_133 . V_134 == V_135 ) {
V_103 = V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] . V_133 . V_103 ;
V_113 = true ;
}
}
V_94 = & V_8 -> V_94 [ V_103 ] ;
V_96 = & V_94 -> V_96 ;
if ( F_42 ( F_43 ( V_96 ) < V_96 -> V_136 ) ) {
F_41 ( & V_8 -> V_127 ) ;
goto V_116;
}
if ( F_11 ( V_18 ) ) {
V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] . V_137 ++ ;
if ( ! F_10 ( V_18 ) )
V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] . V_110 = V_110 ;
}
F_41 ( & V_8 -> V_127 ) ;
memset ( & ( V_94 -> V_138 [ V_96 -> V_139 ] ) , 0 , sizeof( struct V_140 ) ) ;
V_94 -> V_138 [ V_96 -> V_139 ] . V_10 = V_10 ;
V_94 -> V_138 [ V_96 -> V_139 ] . V_5 = V_5 ;
V_98 = V_94 -> V_141 [ V_96 -> V_139 ] ;
V_100 = & V_94 -> V_142 [ V_96 -> V_139 ] ;
V_12 = & V_98 -> V_141 . V_143 ;
memset ( & V_98 -> V_16 , 0 , sizeof( V_98 -> V_16 ) ) ;
memset ( V_12 , 0 , sizeof( struct V_11 ) ) ;
V_98 -> V_16 . V_141 = V_144 ;
V_98 -> V_16 . V_145 = F_16 ( ( T_1 ) ( F_44 ( V_103 ) |
F_45 ( V_96 -> V_139 ) ) ) ;
memcpy ( V_12 -> V_16 , V_16 , V_111 ) ;
V_107 = ( T_1 ) V_10 -> V_107 ;
V_12 -> V_107 = F_16 ( V_107 ) ;
if ( V_14 -> V_49 . V_71 )
F_23 ( V_8 , V_14 , V_12 , V_10 , V_31 ) ;
F_5 ( V_8 , V_10 , V_12 , V_14 , V_16 , V_31 ) ;
F_46 ( V_8 , V_107 , V_16 ) ;
F_17 ( V_8 , V_12 , V_14 , V_18 ) ;
F_47 ( V_8 , true , V_18 , V_107 ) ;
V_107 = sizeof( struct V_11 ) +
sizeof( struct V_146 ) + V_111 ;
V_108 = ( V_107 + 3 ) & ~ 3 ;
if ( V_108 != V_107 )
V_12 -> V_20 |= V_147 ;
V_105 = F_48 ( V_8 -> V_148 ,
& V_98 -> V_16 , V_108 ,
V_149 ) ;
F_49 ( V_100 , V_150 , V_105 ) ;
F_50 ( V_100 , V_107 , V_108 ) ;
V_8 -> V_151 -> V_152 -> V_153 -> V_154 ( V_8 , V_94 ,
V_105 , V_108 , 1 , 0 ) ;
if ( ! F_10 ( V_16 -> V_19 ) ) {
V_94 -> V_155 = 1 ;
} else {
V_112 = 1 ;
V_94 -> V_155 = 0 ;
}
V_109 = V_10 -> V_107 - V_111 ;
if ( V_109 > 0 ) {
V_104 = F_48 ( V_8 -> V_148 , V_10 -> V_89 + V_111 ,
V_109 , V_156 ) ;
V_8 -> V_151 -> V_152 -> V_153 -> V_154 ( V_8 , V_94 ,
V_104 , V_109 ,
0 , 0 ) ;
}
V_106 = V_105 + sizeof( struct V_146 ) +
F_51 ( struct V_11 , V_157 ) ;
F_52 ( V_8 -> V_148 , V_105 ,
V_108 , V_149 ) ;
V_12 -> V_158 = F_53 ( V_106 ) ;
V_12 -> V_159 = F_54 ( V_106 ) ;
F_24 ( V_8 , L_12 ,
F_8 ( V_98 -> V_16 . V_145 ) ) ;
F_24 ( V_8 , L_13 , F_55 ( V_12 -> V_20 ) ) ;
F_56 ( V_8 , V_160 , ( T_2 * ) V_12 , sizeof( * V_12 ) ) ;
F_56 ( V_8 , V_160 , ( T_2 * ) V_12 -> V_16 , V_111 ) ;
if ( V_14 -> V_24 & V_78 )
V_8 -> V_151 -> V_152 -> V_153 -> V_161 ( V_8 , V_94 ,
F_8 ( V_12 -> V_107 ) ) ;
F_57 ( V_8 -> V_148 , V_105 ,
V_108 , V_149 ) ;
F_58 ( V_8 ,
& ( (struct V_162 * ) V_94 -> V_163 ) [ V_94 -> V_96 . V_139 ] ,
sizeof( struct V_162 ) ,
& V_98 -> V_16 , V_108 ,
V_10 -> V_89 + V_111 , V_109 ) ;
V_96 -> V_139 = F_59 ( V_96 -> V_139 , V_96 -> V_164 ) ;
F_60 ( V_8 , V_94 ) ;
F_61 ( & V_8 -> V_115 , V_24 ) ;
if ( V_92 && V_92 -> V_165 && ! V_113 )
F_62 ( & V_92 -> V_166 ) ;
if ( ( F_43 ( V_96 ) < V_96 -> V_136 ) &&
V_8 -> V_167 ) {
if ( V_112 ) {
F_30 ( & V_8 -> V_115 , V_24 ) ;
V_94 -> V_155 = 1 ;
F_60 ( V_8 , V_94 ) ;
F_61 ( & V_8 -> V_115 , V_24 ) ;
} else {
F_63 ( V_8 , V_94 ) ;
}
}
return 0 ;
V_116:
F_61 ( & V_8 -> V_115 , V_24 ) ;
return - 1 ;
}
static inline int F_64 ( struct V_7 * V_8 ,
struct V_168 * V_169 , T_7 V_170 )
{
V_169 -> V_171 = F_65 ( & V_8 -> V_148 -> V_172 , V_170 , & V_169 -> V_173 ,
V_174 ) ;
if ( ! V_169 -> V_171 )
return - V_175 ;
V_169 -> V_170 = V_170 ;
return 0 ;
}
static inline void F_66 ( struct V_7 * V_8 ,
struct V_168 * V_169 )
{
if ( F_42 ( ! V_169 -> V_171 ) )
return;
F_67 ( & V_8 -> V_148 -> V_172 , V_169 -> V_170 , V_169 -> V_171 , V_169 -> V_173 ) ;
memset ( V_169 , 0 , sizeof( * V_169 ) ) ;
}
void F_68 ( struct V_7 * V_8 )
{
int V_103 ;
if ( V_8 -> V_94 ) {
for ( V_103 = 0 ; V_103 < V_8 -> V_65 . V_176 ; V_103 ++ )
if ( V_103 == V_8 -> V_177 )
F_69 ( V_8 ) ;
else
F_70 ( V_8 , V_103 ) ;
}
F_66 ( V_8 , & V_8 -> V_178 ) ;
F_66 ( V_8 , & V_8 -> V_179 ) ;
F_71 ( V_8 ) ;
}
int F_72 ( struct V_7 * V_8 )
{
int V_180 ;
int V_103 , V_181 ;
unsigned long V_24 ;
F_68 ( V_8 ) ;
V_180 = F_64 ( V_8 , & V_8 -> V_179 ,
V_8 -> V_65 . V_182 ) ;
if ( V_180 ) {
F_26 ( V_8 , L_14 ) ;
goto V_183;
}
V_180 = F_64 ( V_8 , & V_8 -> V_178 , V_184 ) ;
if ( V_180 ) {
F_26 ( V_8 , L_15 ) ;
goto V_185;
}
V_180 = F_73 ( V_8 ) ;
if ( V_180 )
goto error;
F_30 ( & V_8 -> V_115 , V_24 ) ;
F_74 ( V_8 , 0 ) ;
F_75 ( V_8 , V_186 , V_8 -> V_178 . V_173 >> 4 ) ;
F_61 ( & V_8 -> V_115 , V_24 ) ;
for ( V_103 = 0 ; V_103 < V_8 -> V_65 . V_176 ; V_103 ++ ) {
V_181 = ( V_103 == V_8 -> V_177 ) ?
V_187 : V_188 ;
V_180 = F_76 ( V_8 ,
& V_8 -> V_94 [ V_103 ] , V_181 ,
V_103 ) ;
if ( V_180 ) {
F_26 ( V_8 , L_16 , V_103 ) ;
goto error;
}
}
return V_180 ;
error:
F_68 ( V_8 ) ;
F_66 ( V_8 , & V_8 -> V_178 ) ;
V_185:
F_66 ( V_8 , & V_8 -> V_179 ) ;
V_183:
return V_180 ;
}
void F_77 ( struct V_7 * V_8 )
{
int V_103 , V_181 ;
unsigned long V_24 ;
F_30 ( & V_8 -> V_115 , V_24 ) ;
F_74 ( V_8 , 0 ) ;
F_75 ( V_8 , V_186 , V_8 -> V_178 . V_173 >> 4 ) ;
F_61 ( & V_8 -> V_115 , V_24 ) ;
for ( V_103 = 0 ; V_103 < V_8 -> V_65 . V_176 ; V_103 ++ ) {
V_181 = V_103 == V_8 -> V_177 ?
V_187 : V_188 ;
F_78 ( V_8 , & V_8 -> V_94 [ V_103 ] ,
V_181 , V_103 ) ;
}
}
void F_79 ( struct V_7 * V_8 )
{
int V_189 , V_103 ;
unsigned long V_24 ;
F_30 ( & V_8 -> V_115 , V_24 ) ;
F_74 ( V_8 , 0 ) ;
for ( V_189 = 0 ; V_189 < V_8 -> V_65 . V_190 ; V_189 ++ ) {
F_75 ( V_8 ,
F_80 ( V_189 ) , 0x0 ) ;
if ( F_81 ( V_8 , V_191 ,
F_82 ( V_189 ) ,
1000 ) )
F_26 ( V_8 , L_17
L_18 , V_189 ,
F_83 ( V_8 ,
V_191 ) ) ;
}
F_61 ( & V_8 -> V_115 , V_24 ) ;
if ( ! V_8 -> V_94 )
return;
for ( V_103 = 0 ; V_103 < V_8 -> V_65 . V_176 ; V_103 ++ )
if ( V_103 == V_8 -> V_177 )
F_84 ( V_8 ) ;
else
F_85 ( V_8 , V_103 ) ;
}
static int F_86 ( struct V_7 * V_8 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_8 -> V_65 . V_176 ; V_103 ++ )
if ( ! F_87 ( V_103 , & V_8 -> V_192 ) )
return V_103 ;
return - 1 ;
}
static void F_88 ( struct V_7 * V_8 ,
T_1 V_103 )
{
F_89 ( V_8 ,
F_90 ( V_103 ) ,
( 0 << V_193 ) |
( 1 << V_194 ) ) ;
}
static int F_91 ( struct V_7 * V_8 , T_1 V_195 ,
T_1 V_103 )
{
T_5 V_196 ;
T_5 V_197 ;
T_1 V_198 ;
V_198 = V_195 & V_199 ;
V_196 = V_8 -> V_200 +
F_92 ( V_103 ) ;
V_197 = F_93 ( V_8 , V_196 ) ;
if ( V_103 & 0x1 )
V_197 = ( V_198 << 16 ) | ( V_197 & 0x0000FFFF ) ;
else
V_197 = V_198 | ( V_197 & 0xFFFF0000 ) ;
F_94 ( V_8 , V_196 , V_197 ) ;
return 0 ;
}
static int F_95 ( struct V_7 * V_8 , int V_103 ,
int V_201 , int V_31 , int V_1 , T_1 V_202 )
{
unsigned long V_24 ;
T_1 V_195 ;
int V_180 ;
if ( ( V_203 > V_103 ) ||
( V_203 +
V_8 -> V_151 -> V_204 -> V_205 <= V_103 ) ) {
F_96 ( V_8 ,
L_19 ,
V_103 , V_203 ,
V_203 +
V_8 -> V_151 -> V_204 -> V_205 - 1 ) ;
return - V_3 ;
}
V_195 = F_97 ( V_31 , V_1 ) ;
V_180 = F_98 ( V_8 , V_31 , V_1 ) ;
if ( V_180 )
return V_180 ;
F_30 ( & V_8 -> V_115 , V_24 ) ;
F_88 ( V_8 , V_103 ) ;
F_91 ( V_8 , V_195 , V_103 ) ;
F_99 ( V_8 , V_206 , ( 1 << V_103 ) ) ;
V_8 -> V_94 [ V_103 ] . V_96 . V_207 = ( V_202 & 0xff ) ;
V_8 -> V_94 [ V_103 ] . V_96 . V_139 = ( V_202 & 0xff ) ;
F_100 ( V_8 , V_103 , V_202 ) ;
F_94 ( V_8 ,
V_8 -> V_200 + F_101 ( V_103 ) ,
( V_208 << V_209 ) &
V_210 ) ;
F_94 ( V_8 , V_8 -> V_200 +
F_101 ( V_103 ) + sizeof( T_5 ) ,
( V_211 << V_212 )
& V_213 ) ;
F_99 ( V_8 , V_214 , ( 1 << V_103 ) ) ;
F_102 ( V_8 , & V_8 -> V_94 [ V_103 ] , V_201 , 1 ) ;
F_61 ( & V_8 -> V_115 , V_24 ) ;
return 0 ;
}
int F_103 ( struct V_7 * V_8 , struct V_215 * V_114 ,
struct V_90 * V_56 , T_1 V_1 , T_1 * V_216 )
{
int V_31 ;
int V_201 ;
int V_103 ;
int V_180 ;
unsigned long V_24 ;
struct V_217 * V_218 ;
V_201 = F_4 ( F_29 ( V_114 ) , V_1 ) ;
if ( F_42 ( V_201 < 0 ) )
return V_201 ;
F_96 ( V_8 , L_20 ,
V_219 , V_56 -> V_171 , V_1 ) ;
V_31 = F_104 ( V_56 ) ;
if ( V_31 == V_118 ) {
F_26 ( V_8 , L_21 ) ;
return - V_220 ;
}
if ( F_42 ( V_1 >= V_129 ) )
return - V_3 ;
if ( V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] . V_133 . V_134 != V_221 ) {
F_26 ( V_8 , L_22 ) ;
return - V_220 ;
}
V_103 = F_86 ( V_8 ) ;
if ( V_103 == - 1 ) {
F_26 ( V_8 , L_23 ) ;
return - V_220 ;
}
F_30 ( & V_8 -> V_127 , V_24 ) ;
V_218 = & V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] ;
* V_216 = F_105 ( V_218 -> V_110 ) ;
V_218 -> V_133 . V_103 = V_103 ;
F_106 ( & V_8 -> V_94 [ V_103 ] ,
F_1 ( V_1 ) , V_103 ) ;
F_61 ( & V_8 -> V_127 , V_24 ) ;
V_180 = F_95 ( V_8 , V_103 , V_201 ,
V_31 , V_1 , * V_216 ) ;
if ( V_180 )
return V_180 ;
F_30 ( & V_8 -> V_127 , V_24 ) ;
V_218 = & V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] ;
if ( V_218 -> V_137 == 0 ) {
F_107 ( V_8 , L_24 ) ;
V_218 -> V_133 . V_134 = V_135 ;
F_108 ( V_114 , V_56 -> V_171 , V_1 ) ;
} else {
F_107 ( V_8 ,
L_25 ,
V_218 -> V_137 ) ;
V_218 -> V_133 . V_134 = V_222 ;
}
F_61 ( & V_8 -> V_127 , V_24 ) ;
return V_180 ;
}
static int F_109 ( struct V_7 * V_8 , T_1 V_103 ,
T_1 V_202 , T_2 V_201 )
{
if ( ( V_203 > V_103 ) ||
( V_203 +
V_8 -> V_151 -> V_204 -> V_205 <= V_103 ) ) {
F_96 ( V_8 ,
L_19 ,
V_103 , V_203 ,
V_203 +
V_8 -> V_151 -> V_204 -> V_205 - 1 ) ;
return - V_3 ;
}
F_88 ( V_8 , V_103 ) ;
F_110 ( V_8 ,
V_206 , ( 1 << V_103 ) ) ;
V_8 -> V_94 [ V_103 ] . V_96 . V_207 = ( V_202 & 0xff ) ;
V_8 -> V_94 [ V_103 ] . V_96 . V_139 = ( V_202 & 0xff ) ;
F_100 ( V_8 , V_103 , V_202 ) ;
F_110 ( V_8 ,
V_214 , ( 1 << V_103 ) ) ;
F_111 ( V_8 , V_103 ) ;
F_102 ( V_8 , & V_8 -> V_94 [ V_103 ] , V_201 , 0 ) ;
return 0 ;
}
int F_112 ( struct V_7 * V_8 , struct V_215 * V_114 ,
struct V_90 * V_56 , T_1 V_1 )
{
int V_223 , V_103 , V_31 , V_216 ;
struct V_217 * V_218 ;
int V_139 , V_207 ;
unsigned long V_24 ;
V_223 = F_4 ( F_29 ( V_114 ) , V_1 ) ;
if ( F_42 ( V_223 < 0 ) )
return V_223 ;
V_31 = F_104 ( V_56 ) ;
if ( V_31 == V_118 ) {
F_26 ( V_8 , L_26 , V_1 ) ;
return - V_220 ;
}
F_30 ( & V_8 -> V_127 , V_24 ) ;
V_218 = & V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] ;
V_216 = ( V_218 -> V_110 & V_131 ) >> 4 ;
V_103 = V_218 -> V_133 . V_103 ;
switch ( V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] . V_133 . V_134 ) {
case V_222 :
F_107 ( V_8 , L_27 ) ;
goto V_224;
case V_135 :
break;
default:
F_96 ( V_8 , L_28 ) ;
}
V_139 = V_8 -> V_94 [ V_103 ] . V_96 . V_139 ;
V_207 = V_8 -> V_94 [ V_103 ] . V_96 . V_207 ;
if ( V_139 != V_207 ) {
F_107 ( V_8 , L_29 ) ;
V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] . V_133 . V_134 =
V_225 ;
F_61 ( & V_8 -> V_127 , V_24 ) ;
return 0 ;
}
F_107 ( V_8 , L_24 ) ;
V_224:
V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] . V_133 . V_134 = V_221 ;
F_41 ( & V_8 -> V_127 ) ;
F_39 ( & V_8 -> V_115 ) ;
F_109 ( V_8 , V_103 , V_216 , V_223 ) ;
F_61 ( & V_8 -> V_115 , V_24 ) ;
F_113 ( V_114 , V_56 -> V_171 , V_1 ) ;
return 0 ;
}
int F_114 ( struct V_7 * V_8 ,
int V_31 , T_2 V_1 , int V_103 )
{
struct V_95 * V_96 = & V_8 -> V_94 [ V_103 ] . V_96 ;
T_2 * V_171 = V_8 -> V_130 [ V_31 ] . V_56 . V_56 . V_171 ;
struct V_217 * V_218 = & V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] ;
struct V_4 * V_5 ;
V_5 = & V_8 -> V_101 [ V_8 -> V_130 [ V_31 ] . V_226 ] ;
F_115 ( & V_8 -> V_127 ) ;
switch ( V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] . V_133 . V_134 ) {
case V_225 :
if ( ( V_103 == V_218 -> V_133 . V_103 ) &&
( V_96 -> V_207 == V_96 -> V_139 ) ) {
T_1 V_216 = F_105 ( V_218 -> V_110 ) ;
int V_201 = F_4 ( V_5 , V_1 ) ;
F_107 ( V_8 ,
L_30 ) ;
F_109 ( V_8 , V_103 , V_216 , V_201 ) ;
V_218 -> V_133 . V_134 = V_221 ;
F_113 ( V_5 -> V_114 , V_171 , V_1 ) ;
}
break;
case V_222 :
if ( V_218 -> V_137 == 0 ) {
F_107 ( V_8 ,
L_31 ) ;
V_218 -> V_133 . V_134 = V_135 ;
F_108 ( V_5 -> V_114 , V_171 , V_1 ) ;
}
break;
}
return 0 ;
}
static void F_116 ( struct V_7 * V_8 ,
struct V_4 * V_5 ,
const T_2 * V_119 )
{
struct V_90 * V_56 ;
struct V_91 * V_92 ;
F_117 () ;
V_56 = F_118 ( V_5 -> V_114 , V_119 ) ;
if ( V_56 ) {
V_92 = ( void * ) V_56 -> V_120 ;
if ( V_92 -> V_165 &&
F_119 ( & V_92 -> V_166 ) == 0 )
F_120 ( V_8 -> V_227 , V_56 , false ) ;
}
F_121 () ;
}
static void
F_122 ( struct V_7 * V_8 , struct V_140 * V_228 ,
bool V_113 )
{
struct V_15 * V_16 = (struct V_15 * ) V_228 -> V_10 -> V_89 ;
if ( ! V_113 )
F_116 ( V_8 , V_228 -> V_5 , V_16 -> V_119 ) ;
F_123 ( V_8 -> V_227 , V_228 -> V_10 ) ;
}
int F_124 ( struct V_7 * V_8 , int V_103 , int V_229 )
{
struct V_93 * V_94 = & V_8 -> V_94 [ V_103 ] ;
struct V_95 * V_96 = & V_94 -> V_96 ;
struct V_140 * V_228 ;
int V_230 = 0 ;
struct V_15 * V_16 ;
if ( ( V_229 >= V_96 -> V_164 ) || ( F_125 ( V_96 , V_229 ) == 0 ) ) {
F_26 ( V_8 , L_32
L_33 , V_103 ,
V_229 , V_96 -> V_164 , V_96 -> V_139 , V_96 -> V_207 ) ;
return 0 ;
}
for ( V_229 = F_59 ( V_229 , V_96 -> V_164 ) ;
V_96 -> V_207 != V_229 ;
V_96 -> V_207 = F_59 ( V_96 -> V_207 , V_96 -> V_164 ) ) {
V_228 = & V_94 -> V_138 [ V_94 -> V_96 . V_207 ] ;
if ( F_40 ( V_228 -> V_10 == NULL ) )
continue;
V_16 = (struct V_15 * ) V_228 -> V_10 -> V_89 ;
if ( F_11 ( V_16 -> V_19 ) )
V_230 ++ ;
F_122 ( V_8 , V_228 ,
V_103 >= V_231 ) ;
V_228 -> V_10 = NULL ;
V_8 -> V_151 -> V_152 -> V_153 -> V_232 ( V_8 , V_94 ) ;
}
return V_230 ;
}
static int F_126 ( struct V_7 * V_8 ,
struct V_233 * V_133 ,
struct V_234 * V_235 )
{
int V_236 , V_237 , V_238 ;
T_1 V_239 = F_8 ( V_235 -> V_239 ) ;
T_1 V_240 = F_8 ( V_235 -> V_240 ) ;
int V_241 = 0 ;
struct V_13 * V_14 ;
T_8 V_242 , V_243 ;
if ( F_42 ( ! V_133 -> V_244 ) ) {
if ( F_42 ( V_235 -> V_242 ) )
F_26 ( V_8 , L_34 ) ;
return - V_3 ;
}
V_133 -> V_244 = 0 ;
F_127 ( V_8 , L_35 , V_133 -> V_245 ,
V_235 -> V_239 ) ;
V_237 = V_133 -> V_245 - F_128 ( V_239 >> 4 ) ;
if ( V_237 < 0 )
V_237 += 0x100 ;
if ( V_133 -> V_246 > ( 64 - V_237 ) ) {
F_127 ( V_8 , L_36 ) ;
return - 1 ;
}
V_242 = F_129 ( V_235 -> V_242 ) >> V_237 ;
V_243 = V_242 & V_133 -> V_242 ;
V_236 = 0 ;
while ( V_243 ) {
V_238 = V_243 & 1ULL ;
V_241 += V_238 ;
F_127 ( V_8 , L_37 ,
V_238 ? L_38 : L_39 , V_236 ,
( V_133 -> V_245 + V_236 ) & 0xff ,
V_133 -> V_245 + V_236 ) ;
V_243 >>= 1 ;
++ V_236 ;
}
F_127 ( V_8 , L_40 ,
( unsigned long long ) V_242 ) ;
V_14 = F_28 ( V_8 -> V_94 [ V_240 ] . V_138 [ V_133 -> V_245 ] . V_10 ) ;
memset ( & V_14 -> V_247 , 0 , sizeof( V_14 -> V_247 ) ) ;
V_14 -> V_24 |= V_248 ;
V_14 -> V_24 |= V_249 ;
V_14 -> V_247 . V_250 = V_241 ;
V_14 -> V_247 . V_251 = V_133 -> V_246 ;
F_130 ( V_8 , V_133 -> V_67 , V_14 ) ;
return 0 ;
}
void F_130 ( struct V_7 * V_8 , T_5 V_67 ,
struct V_13 * V_14 )
{
struct V_252 * V_253 = & V_14 -> V_49 . V_50 [ 0 ] ;
V_14 -> V_254 =
( ( V_67 & V_255 ) >> V_256 ) ;
if ( V_67 & V_257 )
V_253 -> V_24 |= V_52 ;
if ( V_67 & V_258 )
V_253 -> V_24 |= V_259 ;
if ( V_67 & V_260 )
V_253 -> V_24 |= V_261 ;
if ( V_67 & V_262 )
V_253 -> V_24 |= V_263 ;
if ( V_67 & V_264 )
V_253 -> V_24 |= V_265 ;
V_253 -> V_51 = F_131 ( V_67 , V_14 -> V_55 ) ;
}
void F_132 ( struct V_7 * V_8 ,
struct V_266 * V_267 )
{
struct V_268 * V_269 = F_133 ( V_267 ) ;
struct V_234 * V_235 = & V_269 -> V_270 . V_271 ;
struct V_93 * V_94 = NULL ;
struct V_233 * V_133 ;
int V_229 ;
int V_31 ;
int V_1 ;
unsigned long V_24 ;
T_1 V_240 = F_8 ( V_235 -> V_240 ) ;
T_1 V_272 = F_8 ( V_235 -> V_273 ) ;
if ( V_240 >= V_8 -> V_65 . V_176 ) {
F_26 ( V_8 ,
L_41 ) ;
return;
}
V_94 = & V_8 -> V_94 [ V_240 ] ;
V_31 = V_235 -> V_31 ;
V_1 = V_235 -> V_1 ;
V_133 = & V_8 -> V_130 [ V_31 ] . V_1 [ V_1 ] . V_133 ;
if ( F_42 ( V_133 -> V_103 != V_240 ) ) {
F_127 ( V_8 ,
L_42 ,
V_240 , V_133 -> V_103 ) ;
return;
}
V_229 = F_134 ( V_272 & 0xff , V_94 -> V_96 . V_164 ) ;
F_30 ( & V_8 -> V_127 , V_24 ) ;
F_127 ( V_8 , L_43
L_44 ,
V_133 -> V_244 ,
( T_2 * ) & V_235 -> V_274 ,
V_235 -> V_31 ) ;
F_127 ( V_8 , L_45
L_46
L_47 ,
V_235 -> V_1 ,
V_235 -> V_239 ,
( unsigned long long ) F_129 ( V_235 -> V_242 ) ,
V_235 -> V_240 ,
V_235 -> V_273 ) ;
F_127 ( V_8 , L_48 ,
V_133 -> V_245 ,
( unsigned long long ) V_133 -> V_242 ) ;
F_126 ( V_8 , V_133 , V_235 ) ;
if ( V_94 -> V_96 . V_207 != ( V_272 & 0xff ) ) {
int V_275 = F_124 ( V_8 , V_240 , V_229 ) ;
F_135 ( V_8 , V_31 , V_1 , V_275 ) ;
if ( ( F_43 ( & V_94 -> V_96 ) > V_94 -> V_96 . V_276 ) &&
V_8 -> V_167 &&
( V_133 -> V_134 != V_225 ) )
F_136 ( V_8 , V_94 ) ;
F_114 ( V_8 , V_31 , V_1 , V_240 ) ;
}
F_61 ( & V_8 -> V_127 , V_24 ) ;
}
const char * F_137 ( T_5 V_247 )
{
#define F_138 ( T_9 ) case TX_STATUS_FAIL_ ## x: return #x
#define F_139 ( T_9 ) case TX_STATUS_POSTPONE_ ## x: return #x
switch ( V_247 & V_277 ) {
case V_278 :
return L_49 ;
F_139 ( V_279 ) ;
F_139 ( V_280 ) ;
F_139 ( V_281 ) ;
F_139 ( V_282 ) ;
F_138 ( V_283 ) ;
F_138 ( V_284 ) ;
F_138 ( V_285 ) ;
F_138 ( V_286 ) ;
F_138 ( V_287 ) ;
F_138 ( V_288 ) ;
F_138 ( V_289 ) ;
F_138 ( V_290 ) ;
F_138 ( V_291 ) ;
F_138 ( V_292 ) ;
F_138 ( V_293 ) ;
F_138 ( V_294 ) ;
F_138 ( V_295 ) ;
F_138 ( V_296 ) ;
F_138 ( V_297 ) ;
F_138 ( V_298 ) ;
F_138 ( V_299 ) ;
}
return L_50 ;
#undef F_138
#undef F_139
}
