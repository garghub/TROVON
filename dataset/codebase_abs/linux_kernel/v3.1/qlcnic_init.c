static void F_1 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
F_2 ( V_12 ) ;
F_2 ( V_13 ) ;
F_2 ( V_14 ) ;
F_2 ( V_15 ) ;
F_2 ( V_16 ) ;
F_2 ( V_17 ) ;
F_2 ( V_18 ) ;
F_2 ( V_19 ) ;
F_2 ( V_20 ) ;
F_2 ( V_21 ) ;
F_2 ( V_22 ) ;
F_2 ( V_23 ) ;
F_2 ( V_24 ) ;
F_2 ( V_25 ) ;
F_2 ( V_26 ) ;
F_2 ( V_27 ) ;
F_2 ( V_28 ) ;
F_2 ( V_29 ) ;
F_2 ( V_30 ) ;
F_2 ( V_31 ) ;
F_2 ( V_32 ) ;
F_2 ( V_33 ) ;
F_2 ( V_34 ) ;
F_2 ( V_35 ) ;
F_2 ( V_36 ) ;
F_2 ( V_37 ) ;
F_2 ( V_38 ) ;
F_2 ( V_39 ) ;
F_2 ( V_40 ) ;
F_2 ( V_41 ) ;
F_2 ( V_42 ) ;
F_2 ( V_43 ) ;
F_2 ( V_44 ) ;
F_2 ( V_45 ) ;
F_2 ( V_46 ) ;
F_2 ( V_47 ) ;
F_2 ( V_48 ) ;
F_2 ( V_49 ) ;
F_2 ( V_50 ) ;
F_2 ( V_51 ) ;
}
void F_3 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
int V_60 , V_61 ;
V_55 = V_53 -> V_55 ;
for ( V_61 = 0 ; V_61 < V_53 -> V_62 ; V_61 ++ ) {
V_57 = & V_55 -> V_63 [ V_61 ] ;
for ( V_60 = 0 ; V_60 < V_57 -> V_64 ; ++ V_60 ) {
V_59 = & ( V_57 -> V_65 [ V_60 ] ) ;
if ( V_59 -> V_66 == NULL )
continue;
F_4 ( V_53 -> V_67 ,
V_59 -> V_68 ,
V_57 -> V_69 ,
V_70 ) ;
F_5 ( V_59 -> V_66 ) ;
}
}
}
void F_6 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
int V_60 , V_61 ;
V_55 = V_53 -> V_55 ;
for ( V_61 = 0 ; V_61 < V_53 -> V_62 ; V_61 ++ ) {
V_57 = & V_55 -> V_63 [ V_61 ] ;
F_7 ( & V_57 -> V_71 ) ;
V_59 = V_57 -> V_65 ;
for ( V_60 = 0 ; V_60 < V_57 -> V_64 ; V_60 ++ ) {
F_8 ( & V_59 -> V_72 ,
& V_57 -> V_71 ) ;
V_59 ++ ;
}
}
}
void F_9 ( struct V_52 * V_53 )
{
struct V_73 * V_74 ;
struct V_75 * V_76 ;
int V_60 , V_77 ;
struct V_78 * V_79 = V_53 -> V_79 ;
V_74 = V_79 -> V_80 ;
for ( V_60 = 0 ; V_60 < V_79 -> V_64 ; V_60 ++ ) {
V_76 = V_74 -> V_81 ;
if ( V_76 -> V_68 ) {
F_4 ( V_53 -> V_67 , V_76 -> V_68 ,
V_76 -> V_82 , V_83 ) ;
V_76 -> V_68 = 0ULL ;
}
for ( V_77 = 0 ; V_77 < V_74 -> V_84 ; V_77 ++ ) {
V_76 ++ ;
if ( V_76 -> V_68 ) {
F_10 ( V_53 -> V_67 , V_76 -> V_68 ,
V_76 -> V_82 ,
V_83 ) ;
V_76 -> V_68 = 0ULL ;
}
}
if ( V_74 -> V_66 ) {
F_5 ( V_74 -> V_66 ) ;
V_74 -> V_66 = NULL ;
}
V_74 ++ ;
}
}
void F_11 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_78 * V_79 ;
int V_61 ;
V_55 = V_53 -> V_55 ;
if ( V_55 -> V_63 == NULL )
goto V_85;
for ( V_61 = 0 ; V_61 < V_53 -> V_62 ; V_61 ++ ) {
V_57 = & V_55 -> V_63 [ V_61 ] ;
F_12 ( V_57 -> V_65 ) ;
V_57 -> V_65 = NULL ;
}
F_13 ( V_55 -> V_63 ) ;
V_85:
if ( V_53 -> V_79 == NULL )
return;
V_79 = V_53 -> V_79 ;
F_12 ( V_79 -> V_80 ) ;
V_79 -> V_80 = NULL ;
F_13 ( V_53 -> V_79 ) ;
V_53 -> V_79 = NULL ;
}
int F_14 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_86 * V_87 ;
struct V_78 * V_79 ;
struct V_58 * V_59 ;
int V_61 , V_60 , V_88 ;
struct V_73 * V_80 ;
struct V_89 * V_90 = V_53 -> V_90 ;
V_88 = sizeof( struct V_78 ) ;
V_79 = F_15 ( V_88 , V_91 ) ;
if ( V_79 == NULL ) {
F_16 ( & V_90 -> V_92 , L_1 ) ;
return - V_93 ;
}
V_53 -> V_79 = V_79 ;
V_79 -> V_64 = V_53 -> V_94 ;
V_79 -> V_95 = F_17 ( V_90 , 0 ) ;
V_80 = F_18 ( F_19 ( V_79 ) ) ;
if ( V_80 == NULL ) {
F_16 ( & V_90 -> V_92 , L_2 ) ;
goto V_96;
}
V_79 -> V_80 = V_80 ;
V_55 = V_53 -> V_55 ;
V_88 = V_53 -> V_62 * sizeof( struct V_56 ) ;
V_57 = F_15 ( V_88 , V_91 ) ;
if ( V_57 == NULL ) {
F_16 ( & V_90 -> V_92 , L_3 ) ;
goto V_96;
}
V_55 -> V_63 = V_57 ;
for ( V_61 = 0 ; V_61 < V_53 -> V_62 ; V_61 ++ ) {
V_57 = & V_55 -> V_63 [ V_61 ] ;
switch ( V_61 ) {
case V_97 :
V_57 -> V_64 = V_53 -> V_98 ;
V_57 -> V_69 = V_99 ;
V_57 -> V_100 = V_57 -> V_69 + V_101 ;
break;
case V_102 :
V_57 -> V_64 = V_53 -> V_103 ;
V_57 -> V_69 =
V_104 ;
if ( V_53 -> V_105 & V_106 )
V_57 -> V_69 += V_107 ;
V_57 -> V_100 =
V_57 -> V_69 + V_101 ;
break;
}
V_57 -> V_65 = F_18 ( F_20 ( V_57 ) ) ;
if ( V_57 -> V_65 == NULL ) {
F_16 ( & V_90 -> V_92 , L_4
L_5 , V_61 ) ;
goto V_96;
}
F_7 ( & V_57 -> V_71 ) ;
V_59 = V_57 -> V_65 ;
for ( V_60 = 0 ; V_60 < V_57 -> V_64 ; V_60 ++ ) {
F_8 ( & V_59 -> V_72 ,
& V_57 -> V_71 ) ;
V_59 -> V_108 = V_60 ;
V_59 ++ ;
}
F_21 ( & V_57 -> V_109 ) ;
}
for ( V_61 = 0 ; V_61 < V_53 -> V_110 ; V_61 ++ ) {
V_87 = & V_55 -> V_111 [ V_61 ] ;
V_87 -> V_112 = V_53 -> V_113 [ V_61 ] . V_114 ;
V_87 -> V_53 = V_53 ;
V_87 -> V_64 = V_53 -> V_98 ;
for ( V_60 = 0 ; V_60 < V_115 ; V_60 ++ )
F_7 ( & V_87 -> V_71 [ V_60 ] ) ;
}
return 0 ;
V_96:
F_11 ( V_53 ) ;
return - V_93 ;
}
static T_1 F_22 ( T_1 V_116 )
{
int V_60 ;
T_1 V_117 , V_118 , V_119 ;
F_1 () ;
V_119 = V_120 ;
V_117 = V_116 & 0xfff00000 ;
V_118 = V_116 & 0x000fffff ;
for ( V_60 = 0 ; V_60 < V_121 ; V_60 ++ ) {
if ( V_122 [ V_60 ] == V_117 ) {
V_119 = V_60 << 20 ;
break;
}
}
if ( V_119 == V_120 )
return V_119 ;
else
return V_119 + V_118 ;
}
static int F_23 ( struct V_52 * V_53 )
{
long V_123 = 0 ;
long V_124 = 0 ;
F_24 () ;
while ( V_124 == 0 ) {
V_124 = F_25 ( V_53 , V_125 ) ;
V_124 &= 2 ;
if ( ++ V_123 >= V_126 ) {
F_16 ( & V_53 -> V_67 -> V_92 ,
L_6 ) ;
return - V_127 ;
}
F_26 ( 1 ) ;
}
return 0 ;
}
static int F_27 ( struct V_52 * V_53 ,
T_1 V_116 , T_1 * V_128 )
{
F_28 ( V_53 , V_129 , V_116 ) ;
F_28 ( V_53 , V_130 , 0 ) ;
F_28 ( V_53 , V_131 , 3 ) ;
F_28 ( V_53 , V_132 , 0xb ) ;
if ( F_23 ( V_53 ) ) {
F_16 ( & V_53 -> V_67 -> V_92 , L_7 ) ;
return - V_127 ;
}
F_28 ( V_53 , V_131 , 0 ) ;
F_26 ( 10 ) ;
F_28 ( V_53 , V_130 , 0 ) ;
* V_128 = F_25 ( V_53 , V_133 ) ;
return 0 ;
}
static int F_29 ( struct V_52 * V_53 , int V_116 ,
T_2 * V_134 , T_3 V_88 )
{
int V_135 ;
int V_136 = 0 ;
for ( V_135 = V_116 ; V_135 < ( V_116 + V_88 ) ; V_135 += 4 ) {
int V_137 ;
V_136 = F_27 ( V_53 , V_135 , & V_137 ) ;
if ( V_136 != 0 )
break;
* ( V_138 * ) V_134 = F_30 ( V_137 ) ;
V_134 += 4 ;
}
return V_136 ;
}
int
F_31 ( struct V_52 * V_53 , int V_116 ,
T_2 * V_134 , T_3 V_88 )
{
int V_136 ;
V_136 = F_32 ( V_53 ) ;
if ( V_136 < 0 )
return V_136 ;
V_136 = F_29 ( V_53 , V_116 , V_134 , V_88 ) ;
F_33 ( V_53 ) ;
return V_136 ;
}
int F_34 ( struct V_52 * V_53 , T_1 V_116 , T_1 * V_128 )
{
int V_136 ;
if ( F_32 ( V_53 ) != 0 )
return - V_127 ;
V_136 = F_27 ( V_53 , V_116 , V_128 ) ;
F_33 ( V_53 ) ;
return V_136 ;
}
int F_35 ( struct V_52 * V_53 )
{
int V_116 , V_139 ;
int V_60 , V_140 , V_141 ;
struct V_142 * V_143 ;
unsigned V_118 ;
T_1 V_144 ;
struct V_145 * V_67 = V_53 -> V_67 ;
F_28 ( V_53 , V_146 , 0 ) ;
F_28 ( V_53 , V_147 , 0 ) ;
F_32 ( V_53 ) ;
F_28 ( V_53 , V_148 , 0xfeffffff ) ;
F_33 ( V_53 ) ;
if ( F_34 ( V_53 , 0 , & V_140 ) != 0 || ( V_140 != 0xcafecafe ) ||
F_34 ( V_53 , 4 , & V_140 ) != 0 ) {
F_16 ( & V_67 -> V_92 , L_8 , V_140 ) ;
return - V_127 ;
}
V_118 = V_140 & 0xffffU ;
V_140 = ( V_140 >> 16 ) & 0xffffU ;
if ( V_140 >= 1024 ) {
F_16 ( & V_67 -> V_92 , L_9 ) ;
return - V_127 ;
}
V_143 = F_36 ( V_140 , sizeof( struct V_142 ) , V_91 ) ;
if ( V_143 == NULL ) {
F_16 ( & V_67 -> V_92 , L_10 ) ;
return - V_93 ;
}
for ( V_60 = 0 ; V_60 < V_140 ; V_60 ++ ) {
if ( F_34 ( V_53 , 8 * V_60 + 4 * V_118 , & V_139 ) != 0 ||
F_34 ( V_53 , 8 * V_60 + 4 * V_118 + 4 , & V_116 ) != 0 ) {
F_13 ( V_143 ) ;
return - V_127 ;
}
V_143 [ V_60 ] . V_116 = V_116 ;
V_143 [ V_60 ] . V_149 = V_139 ;
}
for ( V_60 = 0 ; V_60 < V_140 ; V_60 ++ ) {
V_144 = F_22 ( V_143 [ V_60 ] . V_116 ) ;
if ( V_144 == V_120 ) {
F_16 ( & V_67 -> V_92 , L_11 ,
V_143 [ V_60 ] . V_116 ) ;
continue;
}
V_144 += V_150 ;
if ( V_144 & 1 )
continue;
if ( V_144 == F_37 ( 0x1fc ) )
continue;
if ( V_144 == ( V_151 + 0x1c ) )
continue;
if ( V_144 == ( V_152 + 0xbc ) )
continue;
if ( V_144 == ( V_152 + 0xa8 ) )
continue;
if ( V_144 == ( V_152 + 0xc8 ) )
continue;
if ( V_144 == ( V_152 + 0x24 ) )
continue;
if ( V_144 == ( V_152 + 0x1c ) )
continue;
if ( ( V_144 & 0x0ff00000 ) == V_153 )
continue;
if ( V_144 == F_38 ( V_154 ) )
continue;
if ( V_144 == F_38 ( V_155 ) )
continue;
if ( ( V_144 & 0x0ff00000 ) == V_156 )
continue;
V_141 = 1 ;
if ( V_144 == V_148 )
V_141 = 1000 ;
F_28 ( V_53 , V_144 , V_143 [ V_60 ] . V_149 ) ;
F_39 ( V_141 ) ;
}
F_13 ( V_143 ) ;
F_28 ( V_53 , V_157 + 0xec , 0x1e ) ;
F_28 ( V_53 , V_157 + 0x4c , 8 ) ;
F_28 ( V_53 , V_158 + 0x4c , 8 ) ;
F_28 ( V_53 , V_159 + 0x8 , 0 ) ;
F_28 ( V_53 , V_159 + 0xc , 0 ) ;
F_28 ( V_53 , V_160 + 0x8 , 0 ) ;
F_28 ( V_53 , V_160 + 0xc , 0 ) ;
F_28 ( V_53 , V_161 + 0x8 , 0 ) ;
F_28 ( V_53 , V_161 + 0xc , 0 ) ;
F_28 ( V_53 , V_162 + 0x8 , 0 ) ;
F_28 ( V_53 , V_162 + 0xc , 0 ) ;
F_28 ( V_53 , V_163 + 0x8 , 0 ) ;
F_28 ( V_53 , V_163 + 0xc , 0 ) ;
F_39 ( 1 ) ;
F_28 ( V_53 , V_164 , 0 ) ;
F_28 ( V_53 , V_165 , 0 ) ;
return 0 ;
}
static int F_40 ( struct V_52 * V_53 )
{
T_1 V_139 ;
int V_166 = V_167 ;
do {
V_139 = F_25 ( V_53 , V_146 ) ;
switch ( V_139 ) {
case V_168 :
case V_169 :
return 0 ;
case V_170 :
goto V_171;
default:
break;
}
F_39 ( V_172 ) ;
} while ( -- V_166 );
F_28 ( V_53 , V_146 , V_170 ) ;
V_171:
F_16 ( & V_53 -> V_67 -> V_92 , L_12
L_13 , V_139 ) ;
return - V_127 ;
}
static int
F_41 ( struct V_52 * V_53 )
{
T_1 V_139 ;
int V_166 = V_173 ;
do {
V_139 = F_25 ( V_53 , V_147 ) ;
if ( V_139 == V_174 )
return 0 ;
F_39 ( V_175 ) ;
} while ( -- V_166 );
if ( ! V_166 ) {
F_16 ( & V_53 -> V_67 -> V_92 , L_14
L_13 , V_139 ) ;
return - V_127 ;
}
return 0 ;
}
int
F_42 ( struct V_52 * V_53 )
{
int V_176 ;
V_176 = F_40 ( V_53 ) ;
if ( V_176 )
return V_176 ;
V_176 = F_41 ( V_53 ) ;
if ( V_176 )
return V_176 ;
F_28 ( V_53 , V_146 , V_169 ) ;
return V_176 ;
}
int
F_43 ( struct V_52 * V_53 ) {
int V_177 ;
T_1 V_139 ;
V_139 = F_25 ( V_53 , V_178 ) ;
V_139 = F_44 ( V_139 , V_53 -> V_179 ) ;
if ( ( V_139 & 0x3 ) != V_180 ) {
F_16 ( & V_53 -> V_67 -> V_92 ,
L_15 , V_139 ) ;
return - V_127 ;
}
V_53 -> V_181 = ( V_139 >> 2 ) ;
if ( F_34 ( V_53 , V_182 , & V_177 ) )
V_177 = V_183 ;
V_53 -> V_184 = V_177 ;
if ( F_34 ( V_53 , V_185 , & V_177 ) )
V_177 = V_186 ;
V_53 -> V_187 = V_177 ;
return 0 ;
}
static int F_45 ( struct V_52 * V_53 , T_2 V_188 ,
struct V_189 * V_190 )
{
struct V_191 V_192 ;
struct V_189 * V_193 ;
int V_60 = 0 , V_136 ;
T_1 V_194 ;
memset ( V_190 , 0 , sizeof( struct V_189 ) ) ;
V_136 = F_31 ( V_53 , V_195 ,
( T_2 * ) & V_192 ,
sizeof( struct V_191 ) ) ;
if ( V_136 ) {
F_46 ( & V_53 -> V_67 -> V_92 ,
L_16 ) ;
return - V_127 ;
}
V_194 = V_192 . V_196 - sizeof( struct V_191 ) ;
V_193 = (struct V_189 * ) F_18 ( V_194 ) ;
if ( V_193 == NULL ) {
F_46 ( & V_53 -> V_67 -> V_92 , L_17 ) ;
return - V_127 ;
}
V_136 = F_31 ( V_53 , V_195 +
sizeof( struct V_191 ) ,
( T_2 * ) V_193 , V_194 ) ;
if ( V_136 ) {
F_46 ( & V_53 -> V_67 -> V_92 ,
L_18 ) ;
goto V_96;
}
while ( V_60 < ( V_194 / sizeof( struct V_189 ) ) ) {
if ( V_193 [ V_60 ] . V_188 == V_188 )
break;
V_60 ++ ;
}
if ( V_60 >= ( V_194 / sizeof( struct V_189 ) ) ) {
F_46 ( & V_53 -> V_67 -> V_92 ,
L_19 , V_188 , V_60 ) ;
V_136 = - V_127 ;
goto V_96;
}
memcpy ( V_190 , & V_193 [ V_60 ] , sizeof( struct V_189 ) ) ;
V_96:
F_12 ( V_193 ) ;
return V_136 ;
}
int
F_47 ( struct V_52 * V_53 )
{
struct V_189 V_197 ;
T_1 V_198 = - 1 , V_199 ;
int V_136 ;
V_136 = F_45 ( V_53 , V_200 , & V_197 ) ;
if ( ! V_136 )
F_34 ( V_53 , V_197 . V_201 + 4 ,
( int * ) & V_198 ) ;
else
F_34 ( V_53 , V_202 ,
( int * ) & V_198 ) ;
V_198 = F_48 ( V_198 ) ;
V_199 = V_203 ;
if ( V_198 < V_199 ) {
F_16 ( & V_53 -> V_67 -> V_92 ,
L_20
L_21 ,
F_49 ( V_198 ) , F_50 ( V_198 ) , F_51 ( V_198 ) ,
F_49 ( V_199 ) , F_50 ( V_199 ) , F_51 ( V_199 ) ) ;
return - V_204 ;
}
return 0 ;
}
static int
F_52 ( struct V_52 * V_53 )
{
T_1 V_205 ;
V_205 = 0 ;
V_205 = F_25 ( V_53 , V_206 ) ;
if ( V_205 & V_207 )
return 1 ;
return 0 ;
}
static
struct V_208 * F_53 ( const T_2 * V_209 , int V_210 )
{
T_1 V_60 ;
struct V_208 * V_211 = (struct V_208 * ) & V_209 [ 0 ] ;
V_138 V_212 = F_30 ( V_211 -> V_213 ) ;
for ( V_60 = 0 ; V_60 < V_212 ; V_60 ++ ) {
V_138 V_214 = F_30 ( V_211 -> V_215 ) +
( V_60 * F_30 ( V_211 -> V_194 ) ) ;
V_138 V_216 = F_30 ( * ( ( T_1 * ) & V_209 [ V_214 ] + 8 ) ) ;
if ( V_216 == V_210 )
return (struct V_208 * ) & V_209 [ V_214 ] ;
}
return NULL ;
}
static int
F_54 ( struct V_52 * V_53 )
{
const T_2 * V_209 = V_53 -> V_217 -> V_149 ;
struct V_208 * V_211 = (struct V_208 * ) & V_209 [ 0 ] ;
V_138 V_218 = V_53 -> V_217 -> V_88 ;
V_138 V_212 ;
V_138 V_194 ;
V_138 V_219 ;
if ( V_218 < V_220 )
return - V_204 ;
V_212 = F_30 ( V_211 -> V_213 ) ;
V_194 = F_30 ( V_211 -> V_194 ) ;
V_219 = F_30 ( V_211 -> V_215 ) + ( V_212 * V_194 ) ;
if ( V_218 < V_219 )
return - V_204 ;
return 0 ;
}
static int
F_55 ( struct V_52 * V_53 )
{
struct V_208 * V_221 ;
struct V_222 * V_223 ;
const T_2 * V_209 = V_53 -> V_217 -> V_149 ;
int V_224 = F_30 ( * ( ( int * ) & V_209 [ V_53 -> V_225 ] +
V_226 ) ) ;
V_138 V_214 ;
V_138 V_219 ;
V_138 V_227 ;
V_221 = F_53 ( V_209 , V_228 ) ;
if ( ! V_221 )
return - V_204 ;
V_219 = F_30 ( V_221 -> V_215 ) +
( F_30 ( V_221 -> V_194 ) * ( V_224 + 1 ) ) ;
if ( V_53 -> V_217 -> V_88 < V_219 )
return - V_204 ;
V_214 = F_30 ( V_221 -> V_215 ) +
( F_30 ( V_221 -> V_194 ) * ( V_224 ) ) ;
V_223 = (struct V_222 * ) & V_209 [ V_214 ] ;
V_227 = F_30 ( V_223 -> V_215 ) + F_30 ( V_223 -> V_88 ) ;
if ( V_53 -> V_217 -> V_88 < V_227 )
return - V_204 ;
return 0 ;
}
static int
F_56 ( struct V_52 * V_53 )
{
struct V_208 * V_221 ;
struct V_222 * V_223 ;
const T_2 * V_209 = V_53 -> V_217 -> V_149 ;
int V_224 = F_30 ( * ( ( int * ) & V_209 [ V_53 -> V_225 ] +
V_229 ) ) ;
V_138 V_214 ;
V_138 V_219 ;
V_138 V_227 ;
V_221 = F_53 ( V_209 , V_230 ) ;
if ( ! V_221 )
return - V_204 ;
V_219 = F_30 ( V_221 -> V_215 ) +
( F_30 ( V_221 -> V_194 ) * ( V_224 + 1 ) ) ;
if ( V_53 -> V_217 -> V_88 < V_219 )
return - V_204 ;
V_214 = F_30 ( V_221 -> V_215 ) +
( F_30 ( V_221 -> V_194 ) * ( V_224 ) ) ;
V_223 = (struct V_222 * ) & V_209 [ V_214 ] ;
V_227 = F_30 ( V_223 -> V_215 ) + F_30 ( V_223 -> V_88 ) ;
if ( V_53 -> V_217 -> V_88 < V_227 )
return - V_204 ;
return 0 ;
}
static int
F_57 ( struct V_52 * V_53 )
{
struct V_208 * V_231 ;
const T_2 * V_209 = V_53 -> V_217 -> V_149 ;
int V_232 = F_52 ( V_53 ) ;
V_138 V_212 ;
V_138 V_194 ;
V_138 V_219 ;
T_1 V_60 ;
V_231 = F_53 ( V_209 ,
V_233 ) ;
if ( ! V_231 )
return - V_204 ;
V_212 = F_30 ( V_231 -> V_213 ) ;
V_194 = F_30 ( V_231 -> V_194 ) ;
V_219 = F_30 ( V_231 -> V_215 ) + ( V_212 * V_194 ) ;
if ( V_53 -> V_217 -> V_88 < V_219 )
return - V_204 ;
V_234:
for ( V_60 = 0 ; V_60 < V_212 ; V_60 ++ ) {
V_138 V_235 , V_236 , V_214 ;
T_2 V_237 = V_53 -> V_238 -> V_239 ;
T_1 V_240 ;
V_214 = F_30 ( V_231 -> V_215 ) +
( V_60 * F_30 ( V_231 -> V_194 ) ) ;
V_235 = F_30 ( * ( ( int * ) & V_209 [ V_214 ] +
V_241 ) ) ;
V_236 = F_30 ( * ( ( int * ) & V_209 [ V_214 ] +
V_242 ) ) ;
V_240 = V_232 ? 1 : 2 ;
if ( ( V_237 == V_236 ) &&
( ( 1ULL << V_240 ) & V_235 ) ) {
V_53 -> V_225 = V_214 ;
return 0 ;
}
}
if ( V_232 ) {
V_232 = 0 ;
goto V_234;
}
return - V_204 ;
}
static int
F_58 ( struct V_52 * V_53 )
{
if ( F_54 ( V_53 ) ) {
F_16 ( & V_53 -> V_67 -> V_92 ,
L_22 ) ;
return - V_204 ;
}
if ( F_57 ( V_53 ) ) {
F_16 ( & V_53 -> V_67 -> V_92 ,
L_23 ) ;
return - V_204 ;
}
if ( F_55 ( V_53 ) ) {
F_16 ( & V_53 -> V_67 -> V_92 ,
L_24 ) ;
return - V_204 ;
}
if ( F_56 ( V_53 ) ) {
F_16 ( & V_53 -> V_67 -> V_92 ,
L_25 ) ;
return - V_204 ;
}
return 0 ;
}
static
struct V_222 * F_59 ( struct V_52 * V_53 ,
T_1 V_210 , T_1 V_243 )
{
const T_2 * V_209 = V_53 -> V_217 -> V_149 ;
int V_224 = F_30 ( * ( ( int * ) & V_209 [ V_53 -> V_225 ] +
V_243 ) ) ;
struct V_208 * V_221 ;
V_138 V_214 ;
V_221 = F_53 ( V_209 , V_210 ) ;
if ( V_221 == NULL )
return NULL ;
V_214 = F_30 ( V_221 -> V_215 ) +
( F_30 ( V_221 -> V_194 ) * V_224 ) ;
return (struct V_222 * ) & V_209 [ V_214 ] ;
}
static T_2 *
F_60 ( struct V_52 * V_53 )
{
T_1 V_214 = V_244 ;
if ( V_53 -> V_245 == V_246 )
V_214 = F_30 ( ( F_59 ( V_53 ,
V_228 ,
V_226 ) ) -> V_215 ) ;
return ( T_2 * ) & V_53 -> V_217 -> V_149 [ V_214 ] ;
}
static T_2 *
F_61 ( struct V_52 * V_53 )
{
T_1 V_214 = V_247 ;
if ( V_53 -> V_245 == V_246 )
V_214 = F_30 ( ( F_59 ( V_53 ,
V_230 ,
V_229 ) ) -> V_215 ) ;
return ( T_2 * ) & V_53 -> V_217 -> V_149 [ V_214 ] ;
}
static V_138
F_62 ( struct V_52 * V_53 )
{
if ( V_53 -> V_245 == V_246 )
return F_30 ( ( F_59 ( V_53 ,
V_230 ,
V_229 ) ) -> V_88 ) ;
else
return F_30 (
* ( T_1 * ) & V_53 -> V_217 -> V_149 [ V_248 ] ) ;
}
static V_138
F_63 ( struct V_52 * V_53 )
{
struct V_222 * V_249 ;
const struct V_250 * V_217 = V_53 -> V_217 ;
V_138 V_251 , V_252 , V_253 ;
const T_2 * V_254 ;
int V_60 , V_136 ;
if ( V_53 -> V_245 != V_246 )
return F_30 ( * ( T_1 * ) & V_217 -> V_149 [ V_202 ] ) ;
V_249 = F_59 ( V_53 , V_230 ,
V_229 ) ;
V_254 = V_217 -> V_149 + F_30 ( V_249 -> V_215 ) +
F_30 ( V_249 -> V_88 ) - 17 ;
for ( V_60 = 0 ; V_60 < 12 ; V_60 ++ ) {
if ( ! strncmp ( & V_254 [ V_60 ] , L_26 , 4 ) ) {
V_136 = sscanf ( & V_254 [ V_60 + 4 ] , L_27 ,
& V_251 , & V_252 , & V_253 ) ;
if ( V_136 != 3 )
return 0 ;
else
return V_251 + ( V_252 << 8 ) + ( V_253 << 16 ) ;
}
}
return 0 ;
}
static V_138
F_64 ( struct V_52 * V_53 )
{
const struct V_250 * V_217 = V_53 -> V_217 ;
V_138 V_255 , V_256 = V_53 -> V_225 ;
if ( V_53 -> V_245 != V_246 )
return F_30 (
* ( T_1 * ) & V_217 -> V_149 [ V_257 ] ) ;
V_255 = F_30 ( * ( ( T_1 * ) ( & V_217 -> V_149 [ V_256 ] )
+ V_258 ) ) ;
return ( V_255 << 16 ) + ( ( V_255 >> 8 ) & 0xff00 ) + ( V_255 >> 24 ) ;
}
static void F_65 ( struct V_52 * V_53 )
{
if ( F_66 ( V_53 , 2 , V_259 ) )
F_67 ( & V_53 -> V_67 -> V_92 , L_28 ) ;
F_68 ( V_53 , 2 ) ;
}
static int
F_69 ( struct V_52 * V_53 )
{
T_1 V_260 , V_136 = - V_127 ;
int V_166 = V_261 ;
V_53 -> V_260 = F_25 ( V_53 , V_262 ) ;
do {
F_39 ( V_263 ) ;
V_260 = F_25 ( V_53 , V_262 ) ;
if ( V_260 != V_53 -> V_260 ) {
V_136 = V_264 ;
break;
}
} while ( -- V_166 );
return V_136 ;
}
int
F_70 ( struct V_52 * V_53 )
{
if ( F_69 ( V_53 ) ) {
F_65 ( V_53 ) ;
return 1 ;
}
if ( V_53 -> V_265 )
return 1 ;
if ( V_53 -> V_217 )
return 1 ;
return 0 ;
}
int
F_71 ( struct V_52 * V_53 )
{
T_4 * V_266 ;
T_1 V_60 , V_267 , V_88 ;
const struct V_250 * V_217 = V_53 -> V_217 ;
struct V_145 * V_67 = V_53 -> V_67 ;
F_67 ( & V_67 -> V_92 , L_29 ,
V_268 [ V_53 -> V_245 ] ) ;
if ( V_217 ) {
T_5 V_149 ;
V_88 = ( V_247 - V_244 ) / 8 ;
V_266 = ( T_4 * ) F_60 ( V_53 ) ;
V_267 = V_244 ;
for ( V_60 = 0 ; V_60 < V_88 ; V_60 ++ ) {
V_149 = F_72 ( V_266 [ V_60 ] ) ;
if ( F_73 ( V_53 , V_267 , V_149 ) )
return - V_127 ;
V_267 += 8 ;
}
V_88 = ( V_269 T_1 ) F_62 ( V_53 ) / 8 ;
V_266 = ( T_4 * ) F_61 ( V_53 ) ;
V_267 = V_247 ;
for ( V_60 = 0 ; V_60 < V_88 ; V_60 ++ ) {
V_149 = F_72 ( V_266 [ V_60 ] ) ;
if ( F_73 ( V_53 ,
V_267 , V_149 ) )
return - V_127 ;
V_267 += 8 ;
}
V_88 = ( V_269 T_1 ) F_62 ( V_53 ) % 8 ;
if ( V_88 ) {
V_149 = F_72 ( V_266 [ V_60 ] ) ;
if ( F_73 ( V_53 ,
V_267 , V_149 ) )
return - V_127 ;
}
} else {
T_4 V_149 ;
T_1 V_270 , V_271 ;
int V_136 ;
struct V_189 V_272 ;
V_136 = F_45 ( V_53 , V_273 ,
& V_272 ) ;
if ( ! V_136 ) {
V_88 = V_272 . V_88 / 8 ;
V_267 = V_272 . V_201 ;
} else {
V_88 = ( V_247 - V_244 ) / 8 ;
V_267 = V_244 ;
F_67 ( & V_67 -> V_92 ,
L_30 ) ;
}
for ( V_60 = 0 ; V_60 < V_88 ; V_60 ++ ) {
if ( F_34 ( V_53 ,
V_267 , ( int * ) & V_271 ) != 0 )
return - V_127 ;
if ( F_34 ( V_53 ,
V_267 + 4 , ( int * ) & V_270 ) != 0 )
return - V_127 ;
V_149 = ( ( ( T_4 ) V_270 << 32 ) | V_271 ) ;
if ( F_73 ( V_53 ,
V_267 , V_149 ) )
return - V_127 ;
V_267 += 8 ;
}
}
F_39 ( 1 ) ;
F_28 ( V_53 , V_159 + 0x18 , 0x1020 ) ;
F_28 ( V_53 , V_148 , 0x80001e ) ;
return 0 ;
}
static int
F_74 ( struct V_52 * V_53 )
{
V_138 V_139 ;
T_1 V_198 , V_274 , V_275 ;
struct V_145 * V_67 = V_53 -> V_67 ;
const struct V_250 * V_217 = V_53 -> V_217 ;
T_2 V_245 = V_53 -> V_245 ;
if ( V_245 == V_246 ) {
if ( F_58 ( V_53 ) )
return - V_204 ;
V_275 = V_276 ;
} else {
V_139 = F_30 ( * ( T_1 * ) & V_217 -> V_149 [ V_277 ] ) ;
if ( ( V_269 T_1 ) V_139 != V_278 )
return - V_204 ;
V_275 = V_279 ;
}
if ( V_217 -> V_88 < V_275 )
return - V_204 ;
V_139 = F_63 ( V_53 ) ;
V_198 = F_48 ( V_139 ) ;
if ( V_198 < V_203 ) {
F_16 ( & V_67 -> V_92 ,
L_31 ,
V_268 [ V_245 ] , F_49 ( V_198 ) , F_50 ( V_198 ) , F_51 ( V_198 ) ) ;
return - V_204 ;
}
V_139 = F_64 ( V_53 ) ;
F_34 ( V_53 , V_257 , ( int * ) & V_274 ) ;
if ( ( V_269 T_1 ) V_139 != V_274 ) {
F_16 ( & V_67 -> V_92 , L_32 ,
V_268 [ V_245 ] ) ;
return - V_204 ;
}
F_28 ( V_53 , F_37 ( 0x1fc ) , V_278 ) ;
return 0 ;
}
static void
F_75 ( struct V_52 * V_53 )
{
T_2 V_245 ;
switch ( V_53 -> V_245 ) {
case V_280 :
V_245 = V_246 ;
break;
case V_246 :
default:
V_245 = V_281 ;
break;
}
V_53 -> V_245 = V_245 ;
}
void F_76 ( struct V_52 * V_53 )
{
struct V_145 * V_67 = V_53 -> V_67 ;
int V_282 ;
V_53 -> V_245 = V_280 ;
V_283:
F_75 ( V_53 ) ;
if ( V_53 -> V_245 == V_281 ) {
V_53 -> V_217 = NULL ;
} else {
V_282 = F_77 ( & V_53 -> V_217 ,
V_268 [ V_53 -> V_245 ] , & V_67 -> V_92 ) ;
if ( V_282 != 0 )
goto V_283;
V_282 = F_74 ( V_53 ) ;
if ( V_282 != 0 ) {
F_78 ( V_53 -> V_217 ) ;
F_39 ( 1 ) ;
goto V_283;
}
}
}
void
F_79 ( struct V_52 * V_53 )
{
if ( V_53 -> V_217 )
F_78 ( V_53 -> V_217 ) ;
V_53 -> V_217 = NULL ;
}
static void
F_80 ( struct V_52 * V_53 ,
struct V_284 * V_285 )
{
T_1 V_286 ;
T_6 V_287 ;
T_6 V_288 ;
T_2 V_289 , V_290 , V_291 , V_292 ;
T_2 V_293 = 0 ;
struct V_89 * V_90 = V_53 -> V_90 ;
V_53 -> V_294 = 1 ;
V_286 = V_285 -> V_295 [ 1 ] & 0xffffffff ;
V_287 = ( V_285 -> V_295 [ 1 ] >> 32 ) & 0xffff ;
V_288 = ( V_285 -> V_295 [ 1 ] >> 48 ) & 0xffff ;
V_289 = V_285 -> V_295 [ 2 ] & 0xff ;
V_291 = ( V_285 -> V_295 [ 2 ] >> 16 ) & 0xff ;
V_292 = ( V_285 -> V_295 [ 2 ] >> 24 ) & 0xff ;
V_293 = ( V_285 -> V_295 [ 2 ] >> 32 ) & 0x3 ;
V_290 = ( V_285 -> V_295 [ 2 ] >> 8 ) & 0xff ;
if ( V_290 == V_296 )
F_67 ( & V_90 -> V_92 , L_33
L_34 , V_286 , V_287 ) ;
else if ( V_290 == V_297 )
F_67 ( & V_90 -> V_92 , L_35 ,
V_287 ) ;
if ( ! V_289 && ( V_293 == V_298 ||
V_293 == V_299 ) )
V_53 -> V_238 -> V_300 |= V_301 ;
F_81 ( V_53 , V_289 ) ;
if ( V_291 == V_302 )
V_53 -> V_303 = V_304 ;
else
V_53 -> V_303 = V_305 ;
V_53 -> V_306 = V_290 ;
V_53 -> V_307 = V_292 ;
V_53 -> V_288 = V_288 ;
}
static void
F_82 ( int V_308 , int V_309 ,
struct V_86 * V_87 )
{
struct V_284 V_285 ;
struct V_310 * V_311 ;
struct V_52 * V_53 ;
struct V_312 * V_92 ;
int V_60 = 0 , V_313 , V_136 ;
while ( V_308 > 0 && V_60 < 8 ) {
V_311 = & V_87 -> V_314 [ V_309 ] ;
V_285 . V_315 [ V_60 ++ ] = F_83 ( V_311 -> V_316 [ 0 ] ) ;
V_285 . V_315 [ V_60 ++ ] = F_83 ( V_311 -> V_316 [ 1 ] ) ;
V_309 = F_84 ( V_309 , V_87 -> V_64 ) ;
V_308 -- ;
}
V_53 = V_87 -> V_53 ;
V_92 = & V_53 -> V_67 -> V_92 ;
V_313 = F_85 ( V_285 . V_295 [ 0 ] ) ;
switch ( V_313 ) {
case V_317 :
F_80 ( V_53 , & V_285 ) ;
break;
case V_318 :
V_136 = ( T_1 ) ( V_285 . V_295 [ 1 ] ) ;
switch ( V_136 ) {
case 0 :
V_53 -> V_238 -> V_300 |= V_319 ;
break;
case 1 :
F_67 ( V_92 , L_36 ) ;
V_53 -> V_320 = - V_321 ;
break;
case 2 :
F_67 ( V_92 , L_37 ) ;
V_53 -> V_320 = - V_322 ;
break;
default:
F_67 ( V_92 , L_38
L_39 , V_136 ) ;
V_53 -> V_320 = - V_323 ;
break;
}
break;
default:
break;
}
}
static int
F_86 ( struct V_52 * V_53 ,
struct V_56 * V_57 ,
struct V_58 * V_324 )
{
struct V_325 * V_66 ;
T_7 V_68 ;
struct V_145 * V_67 = V_53 -> V_67 ;
V_66 = F_87 ( V_57 -> V_100 ) ;
if ( ! V_66 ) {
V_53 -> V_326 . V_327 ++ ;
return - V_93 ;
}
F_88 ( V_66 , V_101 ) ;
V_68 = F_89 ( V_67 , V_66 -> V_149 ,
V_57 -> V_69 , V_70 ) ;
if ( F_90 ( V_67 , V_68 ) ) {
V_53 -> V_326 . V_328 ++ ;
F_5 ( V_66 ) ;
return - V_93 ;
}
V_324 -> V_66 = V_66 ;
V_324 -> V_68 = V_68 ;
return 0 ;
}
static struct V_325 * F_91 ( struct V_52 * V_53 ,
struct V_56 * V_57 , T_6 V_309 , T_6 V_329 )
{
struct V_58 * V_324 ;
struct V_325 * V_66 ;
V_324 = & V_57 -> V_65 [ V_309 ] ;
if ( F_92 ( V_324 -> V_66 == NULL ) ) {
F_93 ( 1 ) ;
return NULL ;
}
F_4 ( V_53 -> V_67 , V_324 -> V_68 , V_57 -> V_69 ,
V_70 ) ;
V_66 = V_324 -> V_66 ;
if ( F_94 ( ( V_53 -> V_90 -> V_330 & V_331 ) &&
( V_329 == V_332 || V_329 == V_333 ) ) ) {
V_53 -> V_326 . V_334 ++ ;
V_66 -> V_335 = V_336 ;
} else {
F_95 ( V_66 ) ;
}
V_66 -> V_92 = V_53 -> V_90 ;
V_324 -> V_66 = NULL ;
return V_66 ;
}
static inline int
F_96 ( struct V_52 * V_53 , struct V_325 * V_66 ,
T_6 * V_337 )
{
struct V_338 * V_339 ;
if ( ! F_97 ( V_66 , V_337 ) ) {
V_339 = (struct V_338 * ) V_66 -> V_149 ;
memmove ( V_66 -> V_149 + V_340 , V_339 , V_341 * 2 ) ;
F_98 ( V_66 , V_340 ) ;
}
if ( ! V_53 -> V_342 )
return 0 ;
if ( * V_337 == V_53 -> V_342 ) {
* V_337 = 0xffff ;
return 0 ;
}
if ( V_53 -> V_235 & V_343 )
return 0 ;
return - V_204 ;
}
static struct V_58 *
F_99 ( struct V_52 * V_53 ,
struct V_86 * V_87 ,
int V_61 , T_4 V_344 )
{
struct V_89 * V_90 = V_53 -> V_90 ;
struct V_54 * V_55 = V_53 -> V_55 ;
struct V_58 * V_324 ;
struct V_325 * V_66 ;
struct V_56 * V_57 ;
int V_309 , V_82 , V_329 , V_345 ;
T_6 V_346 = 0xffff ;
if ( F_92 ( V_61 >= V_53 -> V_62 ) )
return NULL ;
V_57 = & V_55 -> V_63 [ V_61 ] ;
V_309 = F_100 ( V_344 ) ;
if ( F_92 ( V_309 >= V_57 -> V_64 ) )
return NULL ;
V_324 = & V_57 -> V_65 [ V_309 ] ;
V_82 = F_101 ( V_344 ) ;
V_329 = F_102 ( V_344 ) ;
V_345 = F_103 ( V_344 ) ;
V_66 = F_91 ( V_53 , V_57 , V_309 , V_329 ) ;
if ( ! V_66 )
return V_324 ;
if ( V_82 > V_57 -> V_100 )
F_104 ( V_66 , V_57 -> V_100 ) ;
else
F_104 ( V_66 , V_82 ) ;
if ( V_345 )
F_98 ( V_66 , V_345 ) ;
if ( F_92 ( F_96 ( V_53 , V_66 , & V_346 ) ) ) {
V_53 -> V_326 . V_347 ++ ;
F_105 ( V_66 ) ;
return V_324 ;
}
V_66 -> V_348 = F_106 ( V_66 , V_90 ) ;
if ( V_346 != 0xffff )
F_107 ( V_66 , V_346 ) ;
F_108 ( & V_87 -> V_349 , V_66 ) ;
V_53 -> V_326 . V_350 ++ ;
V_53 -> V_326 . V_351 += V_82 ;
return V_324 ;
}
static struct V_58 *
F_109 ( struct V_52 * V_53 ,
struct V_86 * V_87 ,
int V_61 , T_4 V_344 , T_4 V_352 )
{
struct V_89 * V_90 = V_53 -> V_90 ;
struct V_54 * V_55 = V_53 -> V_55 ;
struct V_58 * V_324 ;
struct V_325 * V_66 ;
struct V_56 * V_57 ;
struct V_353 * V_354 ;
struct V_355 * V_356 ;
bool V_357 , V_358 ;
int V_359 , V_360 ;
int V_309 ;
T_6 V_361 , V_82 , V_362 ;
T_1 V_363 ;
T_6 V_346 = 0xffff ;
if ( F_92 ( V_61 > V_53 -> V_62 ) )
return NULL ;
V_57 = & V_55 -> V_63 [ V_61 ] ;
V_309 = F_110 ( V_344 ) ;
if ( F_92 ( V_309 > V_57 -> V_64 ) )
return NULL ;
V_324 = & V_57 -> V_65 [ V_309 ] ;
V_358 = F_111 ( V_344 ) ;
V_361 = F_112 ( V_344 ) ;
V_359 = F_113 ( V_344 ) ;
V_360 = F_114 ( V_344 ) ;
V_357 = F_115 ( V_344 ) ;
V_363 = F_116 ( V_352 ) ;
V_66 = F_91 ( V_53 , V_57 , V_309 , V_332 ) ;
if ( ! V_66 )
return V_324 ;
if ( V_358 )
V_362 = V_360 + V_364 ;
else
V_362 = V_360 + V_365 ;
F_104 ( V_66 , V_361 + V_362 ) ;
F_98 ( V_66 , V_359 ) ;
if ( F_92 ( F_96 ( V_53 , V_66 , & V_346 ) ) ) {
V_53 -> V_326 . V_347 ++ ;
F_105 ( V_66 ) ;
return V_324 ;
}
V_66 -> V_348 = F_106 ( V_66 , V_90 ) ;
V_354 = (struct V_353 * ) V_66 -> V_149 ;
V_356 = (struct V_355 * ) ( V_66 -> V_149 + ( V_354 -> V_366 << 2 ) ) ;
V_82 = ( V_354 -> V_366 << 2 ) + ( V_356 -> V_367 << 2 ) + V_361 ;
V_354 -> V_368 = F_117 ( V_82 ) ;
V_354 -> V_369 = 0 ;
V_354 -> V_369 = F_118 ( ( unsigned char * ) V_354 , V_354 -> V_366 ) ;
V_356 -> V_370 = V_357 ;
V_356 -> V_371 = F_119 ( V_363 ) ;
V_82 = V_66 -> V_196 ;
if ( V_346 != 0xffff )
F_107 ( V_66 , V_346 ) ;
F_120 ( V_66 ) ;
V_53 -> V_326 . V_372 ++ ;
V_53 -> V_326 . V_373 += V_82 ;
return V_324 ;
}
int
F_121 ( struct V_86 * V_87 , int V_374 )
{
struct V_52 * V_53 = V_87 -> V_53 ;
struct V_375 * V_376 ;
struct V_310 * V_311 ;
struct V_58 * V_377 ;
T_4 V_344 , V_352 ;
int V_378 = 0 ;
int V_313 , V_61 , V_308 ;
T_1 V_379 = V_87 -> V_379 ;
while ( V_378 < V_374 ) {
V_311 = & V_87 -> V_314 [ V_379 ] ;
V_344 = F_83 ( V_311 -> V_316 [ 0 ] ) ;
if ( ! ( V_344 & V_380 ) )
break;
V_308 = F_122 ( V_344 ) ;
V_313 = F_123 ( V_344 ) ;
switch ( V_313 ) {
case V_381 :
case V_382 :
case V_383 :
V_61 = F_124 ( V_344 ) ;
V_377 = F_99 ( V_53 , V_87 ,
V_61 , V_344 ) ;
break;
case V_384 :
V_61 = F_125 ( V_344 ) ;
V_352 = F_83 ( V_311 -> V_316 [ 1 ] ) ;
V_377 = F_109 ( V_53 , V_87 ,
V_61 , V_344 , V_352 ) ;
break;
case V_385 :
F_82 ( V_308 , V_379 , V_87 ) ;
default:
goto V_386;
}
F_93 ( V_308 > 1 ) ;
if ( F_94 ( V_377 ) )
F_8 ( & V_377 -> V_72 , & V_87 -> V_71 [ V_61 ] ) ;
else
V_53 -> V_326 . V_387 ++ ;
V_386:
for (; V_308 > 0 ; V_308 -- ) {
V_311 = & V_87 -> V_314 [ V_379 ] ;
V_311 -> V_316 [ 0 ] =
F_72 ( V_388 ) ;
V_379 = F_84 ( V_379 , V_87 -> V_64 ) ;
}
V_378 ++ ;
}
for ( V_61 = 0 ; V_61 < V_53 -> V_62 ; V_61 ++ ) {
struct V_56 * V_57 =
& V_53 -> V_55 -> V_63 [ V_61 ] ;
if ( ! F_126 ( & V_87 -> V_71 [ V_61 ] ) ) {
F_127 (cur, &sds_ring->free_list[ring]) {
V_377 = F_128 ( V_376 ,
struct V_58 , V_72 ) ;
F_86 ( V_53 , V_57 , V_377 ) ;
}
F_129 ( & V_57 -> V_109 ) ;
F_130 ( & V_87 -> V_71 [ V_61 ] ,
& V_57 -> V_71 ) ;
F_131 ( & V_57 -> V_109 ) ;
}
F_132 ( V_53 , V_57 ) ;
}
if ( V_378 ) {
V_87 -> V_379 = V_379 ;
F_133 ( V_379 , V_87 -> V_389 ) ;
}
return V_378 ;
}
void
F_134 ( struct V_52 * V_53 ,
struct V_56 * V_57 )
{
struct V_390 * V_391 ;
struct V_58 * V_324 ;
int V_378 = 0 ;
T_1 V_392 ;
struct V_375 * V_393 ;
V_392 = V_57 -> V_392 ;
V_393 = & V_57 -> V_71 ;
while ( ! F_126 ( V_393 ) ) {
V_324 = F_128 ( V_393 -> V_283 , struct V_58 , V_72 ) ;
if ( ! V_324 -> V_66 ) {
if ( F_86 ( V_53 , V_57 , V_324 ) )
break;
}
V_378 ++ ;
F_135 ( & V_324 -> V_72 ) ;
V_391 = & V_57 -> V_314 [ V_392 ] ;
V_391 -> V_394 = F_72 ( V_324 -> V_68 ) ;
V_391 -> V_395 = F_136 ( V_324 -> V_108 ) ;
V_391 -> V_396 = F_30 ( V_57 -> V_69 ) ;
V_392 = F_84 ( V_392 , V_57 -> V_64 ) ;
}
if ( V_378 ) {
V_57 -> V_392 = V_392 ;
F_133 ( ( V_392 - 1 ) & ( V_57 -> V_64 - 1 ) ,
V_57 -> V_397 ) ;
}
}
static void
F_132 ( struct V_52 * V_53 ,
struct V_56 * V_57 )
{
struct V_390 * V_391 ;
struct V_58 * V_324 ;
int V_378 = 0 ;
T_8 V_392 ;
struct V_375 * V_393 ;
if ( ! F_137 ( & V_57 -> V_109 ) )
return;
V_392 = V_57 -> V_392 ;
V_393 = & V_57 -> V_71 ;
while ( ! F_126 ( V_393 ) ) {
V_324 = F_128 ( V_393 -> V_283 , struct V_58 , V_72 ) ;
if ( ! V_324 -> V_66 ) {
if ( F_86 ( V_53 , V_57 , V_324 ) )
break;
}
V_378 ++ ;
F_135 ( & V_324 -> V_72 ) ;
V_391 = & V_57 -> V_314 [ V_392 ] ;
V_391 -> V_395 = F_136 ( V_324 -> V_108 ) ;
V_391 -> V_396 = F_30 ( V_57 -> V_69 ) ;
V_391 -> V_394 = F_72 ( V_324 -> V_68 ) ;
V_392 = F_84 ( V_392 , V_57 -> V_64 ) ;
}
if ( V_378 ) {
V_57 -> V_392 = V_392 ;
F_133 ( ( V_392 - 1 ) & ( V_57 -> V_64 - 1 ) ,
V_57 -> V_397 ) ;
}
F_131 ( & V_57 -> V_109 ) ;
}
static void F_138 ( struct V_325 * V_66 )
{
int V_60 ;
unsigned char * V_149 = V_66 -> V_149 ;
F_139 ( V_398 L_40 ) ;
for ( V_60 = 0 ; V_60 < V_66 -> V_196 ; V_60 ++ ) {
F_139 ( V_398 L_41 , V_149 [ V_60 ] ) ;
if ( ( V_60 & 0x0f ) == 8 )
F_139 ( V_398 L_40 ) ;
}
}
void F_140 ( struct V_52 * V_53 ,
struct V_86 * V_87 ,
int V_61 , T_4 V_344 )
{
struct V_54 * V_55 = V_53 -> V_55 ;
struct V_325 * V_66 ;
struct V_56 * V_57 ;
int V_309 , V_82 , V_329 , V_345 ;
if ( F_92 ( V_61 >= V_53 -> V_62 ) )
return;
V_57 = & V_55 -> V_63 [ V_61 ] ;
V_309 = F_100 ( V_344 ) ;
V_82 = F_101 ( V_344 ) ;
if ( F_92 ( V_309 >= V_57 -> V_64 ) )
return;
V_329 = F_102 ( V_344 ) ;
V_345 = F_103 ( V_344 ) ;
V_66 = F_91 ( V_53 , V_57 , V_309 , V_329 ) ;
if ( ! V_66 )
return;
if ( V_82 > V_57 -> V_100 )
F_104 ( V_66 , V_57 -> V_100 ) ;
else
F_104 ( V_66 , V_82 ) ;
if ( V_345 )
F_98 ( V_66 , V_345 ) ;
if ( ! F_141 ( V_66 -> V_149 , V_53 -> V_399 ) )
V_53 -> V_320 ++ ;
else
F_138 ( V_66 ) ;
F_5 ( V_66 ) ;
V_53 -> V_326 . V_350 ++ ;
V_53 -> V_326 . V_351 += V_82 ;
return;
}
void
F_142 ( struct V_86 * V_87 )
{
struct V_52 * V_53 = V_87 -> V_53 ;
struct V_310 * V_311 ;
T_4 V_344 ;
int V_61 , V_313 , V_308 ;
T_1 V_379 = V_87 -> V_379 ;
V_311 = & V_87 -> V_314 [ V_379 ] ;
V_344 = F_83 ( V_311 -> V_316 [ 0 ] ) ;
if ( ! ( V_344 & V_380 ) )
return;
V_308 = F_122 ( V_344 ) ;
V_313 = F_123 ( V_344 ) ;
switch ( V_313 ) {
case V_385 :
F_82 ( V_308 , V_379 , V_87 ) ;
break;
default:
V_61 = F_124 ( V_344 ) ;
F_140 ( V_53 , V_87 , V_61 , V_344 ) ;
break;
}
for (; V_308 > 0 ; V_308 -- ) {
V_311 = & V_87 -> V_314 [ V_379 ] ;
V_311 -> V_316 [ 0 ] = F_72 ( V_388 ) ;
V_379 = F_84 ( V_379 , V_87 -> V_64 ) ;
}
V_87 -> V_379 = V_379 ;
F_133 ( V_379 , V_87 -> V_389 ) ;
}
void
F_143 ( struct V_52 * V_53 , T_1 V_400 , T_1 V_401 ,
T_2 V_402 , T_2 * V_403 )
{
T_1 V_404 , V_405 ;
int V_60 ;
V_404 = F_25 ( V_53 , V_400 ) ;
V_405 = F_25 ( V_53 , V_401 ) ;
if ( V_402 ) {
V_404 |= ( V_404 >> 16 ) | ( V_405 << 16 ) ;
V_405 >>= 16 ;
}
for ( V_60 = 0 ; V_60 < 2 ; V_60 ++ )
V_403 [ V_60 ] = ( T_2 ) ( V_405 >> ( ( 1 - V_60 ) * 8 ) ) ;
for ( V_60 = 2 ; V_60 < 6 ; V_60 ++ )
V_403 [ V_60 ] = ( T_2 ) ( V_404 >> ( ( 5 - V_60 ) * 8 ) ) ;
}
