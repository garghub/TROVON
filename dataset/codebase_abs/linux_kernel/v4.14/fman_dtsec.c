static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = true ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_13 = true ;
V_2 -> V_14 = V_15 ;
V_2 -> V_16 = V_17 ;
V_2 -> V_18 = V_19 ;
V_2 -> V_20 = V_21 ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = V_27 ;
}
static int F_2 ( struct V_28 T_1 * V_29 , struct V_1 * V_2 ,
T_2 V_30 , T_3 V_31 , T_4 * V_32 ,
T_5 V_33 , T_4 V_34 )
{
bool V_35 , V_36 , V_37 ;
int V_38 ;
T_5 V_39 ;
F_3 ( V_40 , & V_29 -> V_41 ) ;
F_3 ( 0 , & V_29 -> V_41 ) ;
V_39 = F_4 ( & V_29 -> V_42 ) ;
if ( V_30 == V_43 ||
V_30 == V_44 ||
V_30 == V_45 ||
V_30 == V_46 ||
V_30 == V_47 )
if ( V_39 & V_48 )
return - V_49 ;
if ( V_30 == V_50 ||
V_30 == V_51 )
if ( V_39 & V_48 )
return - V_49 ;
V_35 = V_30 == V_43 ||
V_30 == V_44 ||
V_30 == V_45 ||
V_30 == V_46 ;
V_36 = V_30 == V_50 ;
V_37 = V_30 == V_52 ;
V_39 = 0 ;
if ( V_35 || V_30 == V_53 )
V_39 |= V_54 ;
if ( V_36 )
V_39 |= ( V_55 | V_56 ) ;
if ( V_37 )
V_39 |= ( V_55 | V_56 |
V_57 ) ;
if ( V_35 )
V_39 |= V_58 ;
if ( V_31 == V_59 )
V_39 |= V_60 ;
F_3 ( V_39 , & V_29 -> V_61 ) ;
V_39 = 0 ;
if ( V_2 -> V_8 )
V_39 |= V_2 -> V_8 ;
if ( V_2 -> V_16 )
V_39 |= V_2 -> V_16 << V_62 ;
F_3 ( V_39 , & V_29 -> V_63 ) ;
V_39 = 0 ;
V_39 |= ( V_2 -> V_10 << V_64 ) & V_65 ;
V_39 |= V_66 ;
F_3 ( V_39 , & V_29 -> V_67 ) ;
F_3 ( V_34 , & V_29 -> V_68 ) ;
F_3 ( 0 , & V_29 -> V_69 ) ;
if ( V_2 -> V_12 ) {
V_39 = 0 ;
V_39 |= V_70 ;
F_3 ( V_39 , & V_29 -> V_71 ) ;
if ( V_2 -> V_13 ) {
V_39 = 0 ;
V_39 |= V_72 ;
F_3 ( V_39 , & V_29 -> V_73 ) ;
}
}
V_39 = 0 ;
V_39 |= V_74 ;
V_39 |= V_75 ;
F_3 ( V_39 , & V_29 -> V_41 ) ;
V_39 = 0 ;
if ( V_31 < V_76 )
V_39 |= V_77 ;
else if ( V_31 == V_76 )
V_39 |= V_78 ;
V_39 |= ( V_2 -> V_14 << V_79 ) &
V_80 ;
if ( V_2 -> V_7 )
V_39 |= V_81 ;
V_39 |= V_82 ;
F_3 ( V_39 , & V_29 -> V_83 ) ;
V_39 = ( ( ( V_2 -> V_18 <<
V_84 )
& V_85 )
| ( ( V_2 -> V_20 <<
V_86 )
& V_87 )
| ( ( V_2 -> V_22 << V_88 )
& V_89 )
| ( V_2 -> V_24 & V_90 ) ) ;
F_3 ( V_39 , & V_29 -> V_91 ) ;
V_39 = 0 ;
V_39 |= V_92 ;
V_39 |= ( ( V_2 -> V_3 << V_93 )
& V_94 ) ;
V_39 |= ( V_2 -> V_5 & V_95 ) ;
F_3 ( V_39 , & V_29 -> V_96 ) ;
F_3 ( V_2 -> V_26 , & V_29 -> V_97 ) ;
F_3 ( 0xffffffff , & V_29 -> V_98 ) ;
F_3 ( 0xffffffff , & V_29 -> V_99 ) ;
F_3 ( V_33 , & V_29 -> V_100 ) ;
F_3 ( 0xffffffff , & V_29 -> V_101 ) ;
V_39 = ( T_5 ) ( ( V_32 [ 5 ] << 24 ) |
( V_32 [ 4 ] << 16 ) | ( V_32 [ 3 ] << 8 ) | V_32 [ 2 ] ) ;
F_3 ( V_39 , & V_29 -> V_102 ) ;
V_39 = ( T_5 ) ( ( V_32 [ 1 ] << 24 ) | ( V_32 [ 0 ] << 16 ) ) ;
F_3 ( V_39 , & V_29 -> V_103 ) ;
for ( V_38 = 0 ; V_38 < V_104 ; V_38 ++ ) {
F_3 ( 0 , & V_29 -> V_105 [ V_38 ] ) ;
F_3 ( 0 , & V_29 -> V_106 [ V_38 ] ) ;
}
return 0 ;
}
static void F_5 ( struct V_28 T_1 * V_29 , T_4 * V_107 )
{
T_5 V_39 ;
V_39 = ( T_5 ) ( ( V_107 [ 5 ] << 24 ) |
( V_107 [ 4 ] << 16 ) | ( V_107 [ 3 ] << 8 ) | V_107 [ 2 ] ) ;
F_3 ( V_39 , & V_29 -> V_102 ) ;
V_39 = ( T_5 ) ( ( V_107 [ 1 ] << 24 ) | ( V_107 [ 0 ] << 16 ) ) ;
F_3 ( V_39 , & V_29 -> V_103 ) ;
}
static void F_6 ( struct V_28 T_1 * V_29 , int V_108 ,
bool V_109 )
{
int V_110 = ( V_108 >> 5 ) & 0xf ;
int V_111 = V_108 & 0x1f ;
T_5 V_112 = 0x80000000 >> V_111 ;
T_5 T_1 * V_113 ;
if ( V_110 > 7 )
V_113 = & V_29 -> V_106 [ V_110 - 8 ] ;
else
V_113 = & V_29 -> V_105 [ V_110 ] ;
if ( V_109 )
F_3 ( F_4 ( V_113 ) | V_112 , V_113 ) ;
else
F_3 ( F_4 ( V_113 ) & ( ~ V_112 ) , V_113 ) ;
}
static int F_7 ( struct V_114 * V_115 )
{
if ( V_115 -> V_116 >= V_117 ) {
F_8 ( L_1 ) ;
return - V_49 ;
}
if ( V_115 -> V_118 == 0 ) {
F_8 ( L_2 ) ;
return - V_49 ;
}
if ( ( V_115 -> V_119 ) -> V_10 >
V_120 ) {
F_8 ( L_3 ,
V_120 ) ;
return - V_49 ;
}
if ( ( ( V_115 -> V_119 ) -> V_18 >
V_121 ) ||
( ( V_115 -> V_119 ) -> V_20 >
V_121 ) ||
( ( V_115 -> V_119 ) -> V_24 >
V_121 ) ) {
F_8 ( L_4 ,
V_121 ) ;
return - V_49 ;
}
if ( ( V_115 -> V_119 ) -> V_3 >
V_122 ) {
F_8 ( L_5 ,
V_122 ) ;
return - V_49 ;
}
if ( ( V_115 -> V_119 ) -> V_5 >
V_123 ) {
F_8 ( L_6 ,
V_123 ) ;
return - V_49 ;
}
if ( ! V_115 -> V_124 ) {
F_8 ( L_7 ) ;
return - V_49 ;
}
if ( ! V_115 -> V_125 ) {
F_8 ( L_8 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_9 ( enum V_126 V_127 )
{
T_5 V_112 ;
switch ( V_127 ) {
case V_128 :
V_112 = V_129 ;
break;
case V_130 :
V_112 = V_131 ;
break;
case V_132 :
V_112 = V_133 ;
break;
case V_134 :
V_112 = V_135 ;
break;
case V_136 :
V_112 = V_137 ;
break;
case V_138 :
V_112 = V_139 ;
break;
case V_140 :
V_112 = V_141 ;
break;
case V_142 :
V_112 = V_143 ;
break;
case V_144 :
V_112 = V_145 ;
break;
case V_146 :
V_112 = V_147 ;
break;
case V_148 :
V_112 = V_149 ;
break;
case V_150 :
V_112 = V_151 ;
break;
case V_152 :
V_112 = V_153 ;
break;
case V_154 :
V_112 = V_155 ;
break;
case V_156 :
V_112 = V_157 ;
break;
default:
V_112 = 0 ;
break;
}
return V_112 ;
}
static bool F_10 ( struct V_1 * V_158 )
{
if ( ! V_158 )
return true ;
return false ;
}
static T_3 F_11 ( struct V_114 * V_115 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
if ( F_10 ( V_115 -> V_119 ) )
return 0 ;
return ( T_3 ) F_4 ( & V_29 -> V_97 ) ;
}
static void F_12 ( void * V_159 )
{
struct V_114 * V_115 = (struct V_114 * ) V_159 ;
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
T_5 V_160 ;
V_160 = F_4 ( & V_29 -> V_101 ) &
( T_5 ) ( ~ ( V_149 | V_151 ) ) ;
V_160 &= F_4 ( & V_29 -> V_100 ) ;
F_3 ( V_160 , & V_29 -> V_101 ) ;
if ( V_160 & V_129 )
V_115 -> V_124 ( V_115 -> V_161 , V_128 ) ;
if ( V_160 & V_131 )
V_115 -> V_124 ( V_115 -> V_161 , V_130 ) ;
if ( V_160 & V_133 )
V_115 -> V_124 ( V_115 -> V_161 ,
V_132 ) ;
if ( V_160 & V_135 )
V_115 -> V_124 ( V_115 -> V_161 , V_134 ) ;
if ( V_160 & V_137 )
V_115 -> V_124 ( V_115 -> V_161 , V_136 ) ;
if ( V_160 & V_139 )
V_115 -> V_124 ( V_115 -> V_161 , V_138 ) ;
if ( V_160 & V_141 )
V_115 -> V_124 ( V_115 -> V_161 , V_140 ) ;
if ( V_160 & V_143 )
V_115 -> V_124 ( V_115 -> V_161 , V_142 ) ;
if ( V_160 & V_145 ) {
if ( V_115 -> V_162 . V_163 == 2 ) {
T_5 V_164 , V_165 , V_166 , V_167 , V_38 ;
V_164 = F_4 ( & V_29 -> V_168 ) ;
V_165 = F_4 ( & V_29 -> V_169 [ 27 ] ) ;
if ( ( V_165 & 0x007F0000 ) !=
( V_165 & 0x0000007F ) ) {
F_13 ( ( T_5 ) ( F_14
( F_11 ( V_115 ) *
16 / 1000 , 1 ) ) , ( T_5 )
( F_14 ( F_11
( V_115 ) * 16 / 1000 , 1 ) + 1 ) ) ;
}
V_166 = F_4 ( & V_29 -> V_168 ) ;
V_167 = F_4 ( & V_29 -> V_169 [ 27 ] ) ;
if ( ( V_164 == V_166 ) && ( ( V_165 & 0x007F0000 ) ==
( V_167 & 0x007F0000 ) ) ) {
F_3 ( F_4 ( & V_29 -> V_67 ) |
V_170 , & V_29 -> V_67 ) ;
for ( V_38 = 0 ; V_38 < 100 ; V_38 ++ ) {
if ( F_4 ( & V_29 -> V_101 ) &
V_153 )
break;
F_15 ( 1 ) ;
}
if ( F_4 ( & V_29 -> V_101 ) &
V_153 )
F_3 ( V_153 ,
& V_29 -> V_101 ) ;
else
F_16 ( L_9 ) ;
F_17 ( V_115 -> V_171 , V_115 -> V_172 ) ;
F_15 ( 1 ) ;
}
}
V_115 -> V_124 ( V_115 -> V_161 , V_144 ) ;
}
if ( V_160 & V_147 )
V_115 -> V_124 ( V_115 -> V_161 , V_146 ) ;
if ( V_160 & V_153 )
V_115 -> V_124 ( V_115 -> V_161 ,
V_152 ) ;
if ( V_160 & V_155 )
V_115 -> V_124 ( V_115 -> V_161 , V_154 ) ;
if ( V_160 & V_173 )
V_115 -> V_124 ( V_115 -> V_161 , V_174 ) ;
F_18 ( V_160 & V_175 ) ;
F_18 ( V_160 & V_176 ) ;
}
static void F_19 ( void * V_159 )
{
struct V_114 * V_115 = (struct V_114 * ) V_159 ;
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
T_5 V_160 ;
if ( V_115 -> V_177 ) {
V_160 = F_4 ( & V_29 -> V_71 ) ;
V_160 &= F_4 ( & V_29 -> V_73 ) ;
if ( V_160 ) {
F_3 ( V_160 , & V_29 -> V_71 ) ;
F_18 ( V_160 & V_70 ) ;
V_115 -> V_124 ( V_115 -> V_161 ,
V_178 ) ;
}
}
}
static void F_20 ( struct V_114 * V_115 )
{
F_21 ( V_115 -> V_171 , V_179 , V_115 -> V_172 ,
V_180 ) ;
F_21 ( V_115 -> V_171 , V_179 , V_115 -> V_172 ,
V_181 ) ;
F_22 ( V_115 -> V_182 ) ;
V_115 -> V_182 = NULL ;
F_22 ( V_115 -> V_183 ) ;
V_115 -> V_183 = NULL ;
}
int F_23 ( struct V_114 * V_115 , T_3 V_184 )
{
if ( F_10 ( V_115 -> V_119 ) )
return - V_49 ;
V_115 -> V_119 -> V_26 = V_184 ;
return 0 ;
}
int F_24 ( struct V_114 * V_115 , bool V_184 )
{
if ( F_10 ( V_115 -> V_119 ) )
return - V_49 ;
V_115 -> V_119 -> V_7 = V_184 ;
return 0 ;
}
static void F_25 ( struct V_114 * V_115 , enum V_185 V_186 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
if ( V_186 & V_187 )
F_3 ( F_4 ( & V_29 -> V_188 ) &
~ V_189 , & V_29 -> V_188 ) ;
if ( V_186 & V_190 )
F_3 ( F_4 ( & V_29 -> V_67 ) &
~ V_170 , & V_29 -> V_67 ) ;
}
static void F_26 ( struct V_114 * V_115 , enum V_185 V_186 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
T_5 V_39 ;
if ( V_186 & V_190 ) {
V_39 = F_4 ( & V_29 -> V_67 ) | V_170 ;
F_3 ( V_39 , & V_29 -> V_67 ) ;
if ( V_115 -> V_162 . V_163 == 2 ) {
F_13 ( 100 , 200 ) ;
} else {
F_13 ( 10 , 50 ) ;
}
}
if ( V_186 & V_187 ) {
if ( V_115 -> V_162 . V_163 == 2 ) {
F_16 ( L_10 ) ;
} else {
V_39 = F_4 ( & V_29 -> V_188 ) | V_189 ;
F_3 ( V_39 , & V_29 -> V_188 ) ;
F_13 ( 10 , 50 ) ;
}
}
}
int F_27 ( struct V_114 * V_115 , enum V_185 V_186 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
T_5 V_39 ;
if ( ! F_10 ( V_115 -> V_119 ) )
return - V_49 ;
V_39 = F_4 ( & V_29 -> V_41 ) ;
if ( V_186 & V_190 )
V_39 |= V_191 ;
if ( V_186 & V_187 )
V_39 |= V_192 ;
F_3 ( V_39 , & V_29 -> V_41 ) ;
F_25 ( V_115 , V_186 ) ;
return 0 ;
}
int F_28 ( struct V_114 * V_115 , enum V_185 V_186 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
T_5 V_39 ;
if ( ! F_10 ( V_115 -> V_119 ) )
return - V_49 ;
F_26 ( V_115 , V_186 ) ;
V_39 = F_4 ( & V_29 -> V_41 ) ;
if ( V_186 & V_190 )
V_39 &= ~ V_191 ;
if ( V_186 & V_187 )
V_39 &= ~ V_192 ;
F_3 ( V_39 , & V_29 -> V_41 ) ;
return 0 ;
}
int F_29 ( struct V_114 * V_115 ,
T_4 T_6 V_193 ,
T_3 V_194 , T_3 T_6 V_195 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
enum V_185 V_186 = V_196 ;
T_5 V_63 = 0 ;
if ( ! F_10 ( V_115 -> V_119 ) )
return - V_49 ;
if ( ( F_4 ( & V_29 -> V_67 ) & V_170 ) == 0 )
V_186 |= V_190 ;
if ( ( F_4 ( & V_29 -> V_188 ) & V_189 ) == 0 )
V_186 |= V_187 ;
F_26 ( V_115 , V_186 ) ;
if ( V_194 ) {
if ( V_115 -> V_162 . V_163 == 2 && V_194 <= 320 ) {
F_30 ( L_11 ,
V_194 ) ;
return - V_49 ;
}
V_63 = F_4 ( & V_29 -> V_63 ) ;
V_63 &= V_197 ;
V_63 |= V_194 & V_198 ;
F_3 ( V_63 , & V_29 -> V_63 ) ;
F_3 ( F_4 ( & V_29 -> V_41 ) | V_75 ,
& V_29 -> V_41 ) ;
} else
F_3 ( F_4 ( & V_29 -> V_41 ) & ~ V_75 ,
& V_29 -> V_41 ) ;
F_25 ( V_115 , V_186 ) ;
return 0 ;
}
int F_31 ( struct V_114 * V_115 , bool V_199 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
enum V_185 V_186 = V_196 ;
T_5 V_39 ;
if ( ! F_10 ( V_115 -> V_119 ) )
return - V_49 ;
if ( ( F_4 ( & V_29 -> V_67 ) & V_170 ) == 0 )
V_186 |= V_190 ;
if ( ( F_4 ( & V_29 -> V_188 ) & V_189 ) == 0 )
V_186 |= V_187 ;
F_26 ( V_115 , V_186 ) ;
V_39 = F_4 ( & V_29 -> V_41 ) ;
if ( V_199 )
V_39 |= V_74 ;
else
V_39 &= ~ V_74 ;
F_3 ( V_39 , & V_29 -> V_41 ) ;
F_25 ( V_115 , V_186 ) ;
return 0 ;
}
int F_32 ( struct V_114 * V_115 , T_7 * V_200 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
enum V_185 V_186 = V_196 ;
if ( ! F_10 ( V_115 -> V_119 ) )
return - V_49 ;
if ( ( F_4 ( & V_29 -> V_67 ) & V_170 ) == 0 )
V_186 |= V_190 ;
if ( ( F_4 ( & V_29 -> V_188 ) & V_189 ) == 0 )
V_186 |= V_187 ;
F_26 ( V_115 , V_186 ) ;
V_115 -> V_118 = F_33 ( * V_200 ) ;
F_5 ( V_115 -> V_29 , ( T_4 * ) ( * V_200 ) ) ;
F_25 ( V_115 , V_186 ) ;
return 0 ;
}
int F_34 ( struct V_114 * V_115 , T_7 * V_201 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
struct V_202 * V_203 ;
T_8 V_118 ;
T_9 V_108 ;
T_5 V_204 = 0xFFFFFFFF ;
bool V_205 , V_206 ;
if ( ! F_10 ( V_115 -> V_119 ) )
return - V_49 ;
V_118 = F_33 ( * V_201 ) ;
V_206 = ( bool ) ( ( F_4 ( & V_29 -> V_67 ) & V_207 ) ? true : false ) ;
V_205 = ( bool ) ( ( V_118 & V_208 ) ? true : false ) ;
if ( V_206 && ! V_205 ) {
F_8 ( L_12 ) ;
return - V_49 ;
}
V_204 = F_35 ( V_204 , ( T_4 * ) V_201 , V_209 ) ;
V_204 = F_36 ( V_204 ) ;
if ( V_206 ) {
V_108 = ( T_9 ) ( ( V_204 >> 23 ) & 0x1ff ) ;
} else {
V_108 = ( T_9 ) ( ( V_204 >> 24 ) & 0xff ) ;
if ( V_205 )
V_108 += 0x100 ;
}
F_6 ( V_115 -> V_29 , V_108 , true ) ;
V_203 = F_37 ( sizeof( * V_203 ) , V_210 ) ;
if ( ! V_203 )
return - V_211 ;
V_203 -> V_118 = V_118 ;
F_38 ( & V_203 -> V_212 ) ;
if ( V_118 & V_208 )
F_39 ( & V_203 -> V_212 ,
& V_115 -> V_182 -> V_213 [ V_108 ] ) ;
else
F_39 ( & V_203 -> V_212 ,
& V_115 -> V_183 -> V_213 [ V_108 ] ) ;
return 0 ;
}
int F_40 ( struct V_114 * V_115 , T_7 * V_201 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
struct V_214 * V_215 ;
struct V_202 * V_203 = NULL ;
T_8 V_118 ;
T_9 V_108 ;
T_5 V_204 = 0xFFFFFFFF ;
bool V_205 , V_206 ;
if ( ! F_10 ( V_115 -> V_119 ) )
return - V_49 ;
V_118 = F_33 ( * V_201 ) ;
V_206 = ( bool ) ( ( F_4 ( & V_29 -> V_67 ) & V_207 ) ? true : false ) ;
V_205 = ( bool ) ( ( V_118 & V_208 ) ? true : false ) ;
if ( V_206 && ! V_205 ) {
F_8 ( L_12 ) ;
return - V_49 ;
}
V_204 = F_35 ( V_204 , ( T_4 * ) V_201 , V_209 ) ;
V_204 = F_36 ( V_204 ) ;
if ( V_206 ) {
V_108 = ( T_9 ) ( ( V_204 >> 23 ) & 0x1ff ) ;
} else {
V_108 = ( T_9 ) ( ( V_204 >> 24 ) & 0xff ) ;
if ( V_205 )
V_108 += 0x100 ;
}
if ( V_118 & V_208 ) {
F_41 (pos,
&dtsec->multicast_addr_hash->lsts[bucket]) {
V_203 = F_42 ( V_215 ) ;
if ( V_203 -> V_118 == V_118 ) {
F_43 ( & V_203 -> V_212 ) ;
F_44 ( V_203 ) ;
break;
}
}
if ( F_45 ( & V_115 -> V_182 -> V_213 [ V_108 ] ) )
F_6 ( V_115 -> V_29 , V_108 , false ) ;
} else {
F_41 (pos,
&dtsec->unicast_addr_hash->lsts[bucket]) {
V_203 = F_42 ( V_215 ) ;
if ( V_203 -> V_118 == V_118 ) {
F_43 ( & V_203 -> V_212 ) ;
F_44 ( V_203 ) ;
break;
}
}
if ( F_45 ( & V_115 -> V_183 -> V_213 [ V_108 ] ) )
F_6 ( V_115 -> V_29 , V_108 , false ) ;
}
F_18 ( ! V_203 ) ;
return 0 ;
}
int F_46 ( struct V_114 * V_115 , bool V_184 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
T_5 V_39 ;
if ( ! F_10 ( V_115 -> V_119 ) )
return - V_49 ;
V_39 = F_4 ( & V_29 -> V_67 ) ;
if ( V_184 )
V_39 |= V_216 ;
else
V_39 &= ~ V_216 ;
F_3 ( V_39 , & V_29 -> V_67 ) ;
V_39 = F_4 ( & V_29 -> V_67 ) ;
if ( V_184 )
V_39 |= V_217 ;
else
V_39 &= ~ V_217 ;
F_3 ( V_39 , & V_29 -> V_67 ) ;
return 0 ;
}
int F_47 ( struct V_114 * V_115 , T_3 V_218 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
enum V_185 V_186 = V_196 ;
T_5 V_39 ;
if ( ! F_10 ( V_115 -> V_119 ) )
return - V_49 ;
if ( ( F_4 ( & V_29 -> V_67 ) & V_170 ) == 0 )
V_186 |= V_190 ;
if ( ( F_4 ( & V_29 -> V_188 ) & V_189 ) == 0 )
V_186 |= V_187 ;
F_26 ( V_115 , V_186 ) ;
V_39 = F_4 ( & V_29 -> V_83 ) ;
V_39 |= V_82 ;
V_39 &= ~ ( V_77 | V_78 ) ;
if ( V_218 < V_76 )
V_39 |= V_77 ;
else if ( V_218 == V_76 )
V_39 |= V_78 ;
F_3 ( V_39 , & V_29 -> V_83 ) ;
V_39 = F_4 ( & V_29 -> V_61 ) ;
if ( V_218 == V_59 )
V_39 |= V_60 ;
else
V_39 &= ~ V_60 ;
F_3 ( V_39 , & V_29 -> V_61 ) ;
F_25 ( V_115 , V_186 ) ;
return 0 ;
}
int F_48 ( struct V_114 * V_115 )
{
T_3 V_219 ;
if ( ! F_10 ( V_115 -> V_119 ) )
return - V_49 ;
V_219 = F_49 ( V_115 -> V_220 , V_221 ) ;
V_219 &= ~ ( V_222 | V_223 ) ;
V_219 |= ( V_224 | V_225 |
V_226 | V_223 ) ;
F_50 ( V_115 -> V_220 , V_221 , V_219 ) ;
return 0 ;
}
int F_51 ( struct V_114 * V_115 , T_5 * V_227 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
if ( ! F_10 ( V_115 -> V_119 ) )
return - V_49 ;
* V_227 = F_4 ( & V_29 -> V_228 ) ;
return 0 ;
}
int F_52 ( struct V_114 * V_115 ,
enum V_126 V_127 , bool V_109 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
T_5 V_112 = 0 ;
if ( ! F_10 ( V_115 -> V_119 ) )
return - V_49 ;
if ( V_127 != V_178 ) {
V_112 = F_9 ( V_127 ) ;
if ( V_112 ) {
if ( V_109 )
V_115 -> V_229 |= V_112 ;
else
V_115 -> V_229 &= ~ V_112 ;
} else {
F_8 ( L_13 ) ;
return - V_49 ;
}
if ( V_109 )
F_3 ( F_4 ( & V_29 -> V_100 ) | V_112 ,
& V_29 -> V_100 ) ;
else
F_3 ( F_4 ( & V_29 -> V_100 ) & ~ V_112 ,
& V_29 -> V_100 ) ;
} else {
if ( ! V_115 -> V_177 ) {
F_8 ( L_14 ) ;
return - V_49 ;
}
switch ( V_127 ) {
case V_178 :
if ( V_109 ) {
V_115 -> V_230 = true ;
F_3 ( F_4 ( & V_29 -> V_73 ) |
V_72 ,
& V_29 -> V_73 ) ;
} else {
V_115 -> V_230 = false ;
F_3 ( F_4 ( & V_29 -> V_73 ) &
~ V_72 ,
& V_29 -> V_73 ) ;
}
break;
default:
F_8 ( L_13 ) ;
return - V_49 ;
}
}
return 0 ;
}
int F_53 ( struct V_114 * V_115 )
{
struct V_28 T_1 * V_29 = V_115 -> V_29 ;
struct V_1 * V_119 ;
int V_231 ;
T_3 V_232 ;
T_7 V_201 ;
if ( F_10 ( V_115 -> V_119 ) )
return - V_49 ;
if ( V_233 &&
( F_17 ( V_115 -> V_171 , V_115 -> V_172 ) != 0 ) ) {
F_8 ( L_15 ) ;
return - V_49 ;
}
V_231 = F_7 ( V_115 ) ;
if ( V_231 )
return V_231 ;
V_119 = V_115 -> V_119 ;
F_54 ( V_115 -> V_118 , V_201 ) ;
V_231 = F_2 ( V_115 -> V_29 , V_119 , V_115 -> V_234 ,
V_115 -> V_116 , ( T_4 * ) V_201 , V_115 -> V_229 ,
V_115 -> V_220 -> V_235 . V_118 ) ;
if ( V_231 ) {
F_20 ( V_115 ) ;
F_8 ( L_16 ) ;
return V_231 ;
}
if ( V_115 -> V_234 == V_50 ) {
T_3 V_219 ;
V_219 = V_236 | V_237 ;
F_50 ( V_115 -> V_220 , V_238 , V_219 ) ;
V_219 = V_236 ;
F_50 ( V_115 -> V_220 , V_238 , V_219 ) ;
V_219 = ( V_239 | V_224 |
V_226 | V_223 ) ;
F_50 ( V_115 -> V_220 , V_221 , V_219 ) ;
if ( V_115 -> V_240 )
V_219 = V_241 ;
else
V_219 = V_242 ;
F_50 ( V_115 -> V_220 , V_243 , V_219 ) ;
V_219 = ( V_224 | V_225 |
V_226 | V_223 ) ;
F_50 ( V_115 -> V_220 , V_221 , V_219 ) ;
}
V_232 = ( T_3 ) F_4 ( & V_29 -> V_97 ) ;
V_231 = F_55 ( V_115 -> V_171 , V_115 -> V_172 , V_232 ) ;
if ( V_231 ) {
F_8 ( L_17 ) ;
F_20 ( V_115 ) ;
return - V_49 ;
}
V_115 -> V_182 =
F_56 ( V_244 ) ;
if ( ! V_115 -> V_182 ) {
F_20 ( V_115 ) ;
F_8 ( L_18 ) ;
return - V_211 ;
}
V_115 -> V_183 = F_56 ( V_245 ) ;
if ( ! V_115 -> V_183 ) {
F_20 ( V_115 ) ;
F_8 ( L_19 ) ;
return - V_211 ;
}
F_57 ( V_115 -> V_171 , V_179 , V_115 -> V_172 ,
V_180 , F_12 , V_115 ) ;
F_57 ( V_115 -> V_171 , V_179 , V_115 -> V_172 ,
V_181 , F_19 , V_115 ) ;
F_44 ( V_119 ) ;
V_115 -> V_119 = NULL ;
return 0 ;
}
int F_58 ( struct V_114 * V_115 )
{
F_20 ( V_115 ) ;
F_44 ( V_115 -> V_119 ) ;
V_115 -> V_119 = NULL ;
F_44 ( V_115 ) ;
return 0 ;
}
struct V_114 * F_59 ( struct V_246 * V_247 )
{
struct V_114 * V_115 ;
struct V_1 * V_119 ;
void T_1 * V_248 ;
V_248 = V_247 -> V_248 ;
V_115 = F_60 ( sizeof( * V_115 ) , V_210 ) ;
if ( ! V_115 )
return NULL ;
V_119 = F_60 ( sizeof( * V_119 ) , V_210 ) ;
if ( ! V_119 )
goto V_249;
V_115 -> V_119 = V_119 ;
F_1 ( V_119 ) ;
V_115 -> V_29 = V_248 ;
V_115 -> V_118 = F_33 ( V_247 -> V_118 ) ;
V_115 -> V_116 = V_247 -> V_116 ;
V_115 -> V_234 = V_247 -> V_234 ;
V_115 -> V_172 = V_247 -> V_172 ;
V_115 -> V_229 = ( V_129 |
V_131 |
V_135 |
V_137 |
V_139 |
V_175 |
V_141 |
V_143 |
V_145 |
V_176 |
V_147 |
V_155 |
V_173 ) ;
V_115 -> V_124 = V_247 -> V_124 ;
V_115 -> V_125 = V_247 -> V_125 ;
V_115 -> V_161 = V_247 -> V_161 ;
V_115 -> V_177 = V_115 -> V_119 -> V_12 ;
V_115 -> V_230 = V_115 -> V_119 -> V_13 ;
V_115 -> V_171 = V_247 -> V_171 ;
V_115 -> V_240 = V_247 -> V_240 ;
if ( ! V_247 -> V_250 ) {
F_8 ( L_20 ) ;
goto V_251;
}
V_115 -> V_220 = F_61 ( V_247 -> V_250 ) ;
if ( ! V_115 -> V_220 ) {
F_8 ( L_21 ) ;
goto V_251;
}
F_62 ( & V_115 -> V_220 -> V_235 . V_252 ) ;
F_63 ( V_115 -> V_171 , & V_115 -> V_162 ) ;
return V_115 ;
V_251:
F_44 ( V_119 ) ;
V_249:
F_44 ( V_115 ) ;
return NULL ;
}
