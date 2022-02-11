static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_4 )
F_2 ( V_3 ,
V_5 ,
V_6 ,
V_7 ,
V_2 -> V_4 - 1 ) ;
else
F_2 ( V_3 ,
V_5 ,
V_8 ,
V_7 , 0 ) ;
F_3 ( V_2 -> V_9 , & V_3 , V_10 ,
V_2 -> V_2 ) ;
}
void F_4 ( struct V_11 * V_9 )
{
if ( V_9 -> V_12 ++ == 0 )
F_5 ( V_9 ) ;
}
void F_6 ( struct V_11 * V_9 )
{
if ( -- V_9 -> V_12 == 0 )
F_5 ( V_9 ) ;
}
static int F_7 ( struct V_11 * V_9 , struct V_13 * V_14 )
{
enum V_15 V_16 = V_17 ;
int V_18 , V_19 ;
F_8 ( V_9 , V_16 ) ;
V_18 = F_9 ( V_9 , V_16 ) ;
if ( V_18 )
goto V_20;
V_14 -> V_21 =
F_10 ( V_9 , V_22 ,
F_11 ( V_22 ) )
? - 1 : 1 ;
V_18 = F_9 ( V_9 , V_16 ) ;
V_20:
V_19 = F_12 ( V_9 , V_16 , V_18 == 0 ) ;
return V_18 ? V_18 : V_19 ;
}
static int F_13 ( T_2 * V_23 )
{
enum {
V_24 = ( V_25 | V_26 |
V_27 | V_28 |
V_29 ) ,
V_30 = ( V_24 |
V_31 << V_32 ) ,
};
if ( ( * V_23 & V_30 ) == V_30 ) {
* V_23 &= ~ V_30 ;
return V_33 ;
}
if ( ( * V_23 & V_24 ) == V_24 ) {
* V_23 &= ~ V_24 ;
return V_17 ;
}
return - V_34 ;
}
static void F_14 ( struct V_11 * V_9 )
{
struct V_35 * V_36 =
F_15 ( F_16 ( V_9 -> V_37 ) ) ;
F_17 ( V_36 ) ;
}
static int F_18 ( struct V_11 * V_9 )
{
T_2 V_38 = 0 ;
int V_18 ;
V_18 = F_19 ( V_9 , V_9 -> V_39 -> V_40 , NULL , & V_38 ) ;
V_9 -> V_41 =
( V_38 & ( 1 << V_42 ) ) ?
3072 : 6144 ;
return V_18 ;
}
static int F_20 ( struct V_11 * V_9 )
{
F_21 ( V_9 , V_43 / 2 ) ;
return 0 ;
}
static unsigned int F_22 ( struct V_11 * V_9 )
{
return V_44 +
V_45 * V_46 ;
}
static int F_23 ( struct V_11 * V_9 )
{
struct V_47 * V_48 ;
T_3 V_49 ;
int V_18 ;
V_48 = F_24 ( sizeof( struct V_47 ) , V_50 ) ;
if ( ! V_48 )
return - V_51 ;
V_9 -> V_48 = V_48 ;
if ( F_25 ( V_9 ) != 0 ) {
F_26 ( V_9 , V_52 , V_9 -> V_39 ,
L_1 ) ;
V_18 = - V_53 ;
goto V_54;
}
V_9 -> V_55 = V_56 ;
F_27 ( V_9 , & V_49 , V_57 ) ;
V_9 -> V_58 = F_28 ( V_49 , V_59 ) - 1 ;
V_18 = F_29 ( V_9 ) ;
if ( V_18 )
goto V_54;
V_18 = F_9 ( V_9 , V_17 ) ;
if ( V_18 ) {
F_26 ( V_9 , V_52 , V_9 -> V_39 , L_2 ) ;
goto V_60;
}
F_30 ( V_9 ) ;
V_18 = F_31 ( V_9 , & V_9 -> V_61 , sizeof( T_3 ) ,
V_50 ) ;
if ( V_18 )
goto V_62;
F_32 ( V_9 -> V_61 . V_63 & 0x0f ) ;
F_33 ( V_9 , V_52 , V_9 -> V_39 ,
L_3 ,
( unsigned long long ) V_9 -> V_61 . V_63 ,
V_9 -> V_61 . V_64 ,
( unsigned long long ) F_34 ( V_9 -> V_61 . V_64 ) ) ;
V_18 = F_18 ( V_9 ) ;
if ( V_18 == - V_34 ) {
F_26 ( V_9 , V_52 , V_9 -> V_39 ,
L_4 ) ;
V_9 -> V_65 = V_66 ;
V_9 -> V_67 . V_68 = V_69 ;
} else if ( V_18 ) {
goto V_70;
}
V_18 = F_35 ( V_9 ) ;
if ( V_18 )
goto V_70;
F_36 ( V_9 ) ;
F_37 ( V_9 ) ;
return 0 ;
V_70:
F_38 ( V_9 , & V_9 -> V_61 ) ;
V_62:
V_60:
F_39 ( V_9 ) ;
V_54:
F_40 ( V_9 -> V_48 ) ;
return V_18 ;
}
static int F_41 ( struct V_11 * V_9 )
{
T_3 V_71 ;
int V_18 ;
V_18 = F_42 ( V_9 ) ;
if ( V_18 )
return V_18 ;
F_27 ( V_9 , & V_71 , V_72 ) ;
F_43 ( V_71 , V_73 , 1 ) ;
F_44 ( V_9 , & V_71 , V_72 ) ;
F_27 ( V_9 , & V_71 , V_74 ) ;
F_43 ( V_71 , V_75 , 0 ) ;
F_43 ( V_71 , V_76 , 1 ) ;
F_44 ( V_9 , & V_71 , V_74 ) ;
F_27 ( V_9 , & V_71 , V_77 ) ;
F_43 ( V_71 , V_78 , 0 ) ;
F_43 ( V_71 , V_79 , 1 ) ;
F_43 ( V_71 , V_80 , 1 ) ;
F_43 ( V_71 , V_81 , 1 ) ;
F_43 ( V_71 , V_82 , 1 ) ;
F_43 ( V_71 , V_83 ,
V_84 >> 5 ) ;
F_44 ( V_9 , & V_71 , V_77 ) ;
memcpy ( & V_71 , V_9 -> V_85 , sizeof( V_71 ) ) ;
F_44 ( V_9 , & V_71 , V_86 ) ;
F_45 ( sizeof( V_9 -> V_85 ) <
2 * sizeof( V_71 ) + V_87 / 8 ||
V_88 != 0 ) ;
memcpy ( & V_71 , V_9 -> V_85 , sizeof( V_71 ) ) ;
F_44 ( V_9 , & V_71 , V_89 ) ;
memcpy ( & V_71 , V_9 -> V_85 + sizeof( V_71 ) , sizeof( V_71 ) ) ;
F_44 ( V_9 , & V_71 , V_90 ) ;
F_46 ( V_71 , V_91 , 1 ,
V_92 , 1 ) ;
memcpy ( & V_71 , V_9 -> V_85 + 2 * sizeof( V_71 ) ,
V_87 / 8 ) ;
F_44 ( V_9 , & V_71 , V_93 ) ;
V_18 = F_47 ( V_9 , true , false , 0 ) ;
if ( V_18 )
return V_18 ;
F_48 ( V_71 , V_94 , 0 ) ;
F_44 ( V_9 , & V_71 , V_95 ) ;
F_48 ( V_71 , V_96 , 1 ) ;
F_44 ( V_9 , & V_71 , V_97 ) ;
F_49 ( V_9 ) ;
return 0 ;
}
static void F_50 ( struct V_11 * V_9 )
{
F_51 ( V_9 ) ;
F_38 ( V_9 , & V_9 -> V_61 ) ;
F_9 ( V_9 , V_17 ) ;
F_39 ( V_9 ) ;
F_40 ( V_9 -> V_48 ) ;
V_9 -> V_48 = NULL ;
}
static T_4 F_52 ( struct V_11 * V_9 , T_5 * V_98 )
{
return F_53 ( V_99 , V_100 ,
V_101 , V_98 ) ;
}
static int F_54 ( struct V_11 * V_9 )
{
struct V_47 * V_48 = V_9 -> V_48 ;
T_6 * V_102 = V_48 -> V_102 ;
T_7 * V_103 ;
T_7 V_104 , V_105 ;
V_103 = V_9 -> V_106 . V_64 ;
V_105 = V_103 [ V_107 ] ;
if ( V_105 == V_108 )
return 0 ;
F_55 () ;
F_56 ( V_99 , V_100 , V_101 ,
V_102 , V_9 -> V_106 . V_64 , false ) ;
F_55 () ;
V_104 = V_103 [ V_109 ] ;
if ( V_105 != V_104 )
return - V_110 ;
F_57 ( & V_102 [ V_111 ] ,
V_102 [ V_112 ] -
V_102 [ V_113 ] ) ;
V_102 [ V_114 ] =
V_102 [ V_115 ] +
V_102 [ V_116 ] +
V_102 [ V_117 ] +
V_102 [ V_118 ] ;
F_57 ( & V_102 [ V_119 ] ,
V_102 [ V_120 ] -
V_102 [ V_121 ] ) ;
return 0 ;
}
static T_4 F_58 ( struct V_11 * V_9 , T_6 * V_122 ,
struct V_123 * V_124 )
{
struct V_47 * V_48 = V_9 -> V_48 ;
T_6 * V_102 = V_48 -> V_102 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < 100 ; ++ V_125 ) {
if ( F_54 ( V_9 ) == 0 )
break;
F_59 ( 100 ) ;
}
if ( V_122 )
memcpy ( V_122 , V_102 , sizeof( T_6 ) * V_100 ) ;
if ( V_124 ) {
V_124 -> V_126 = V_102 [ V_127 ] ;
V_124 -> V_128 = V_102 [ V_129 ] ;
V_124 -> V_130 = V_102 [ V_120 ] ;
V_124 -> V_131 = V_102 [ V_112 ] ;
V_124 -> V_132 = V_102 [ V_133 ] ;
V_124 -> V_134 = V_102 [ V_135 ] ;
V_124 -> V_136 = V_102 [ V_114 ] ;
V_124 -> V_137 =
V_102 [ V_138 ] +
V_102 [ V_139 ] ;
V_124 -> V_140 = V_102 [ V_141 ] ;
V_124 -> V_142 = V_102 [ V_143 ] ;
V_124 -> V_144 = V_102 [ V_145 ] ;
V_124 -> V_146 =
V_102 [ V_118 ] ;
V_124 -> V_147 = ( V_124 -> V_137 +
V_124 -> V_140 +
V_124 -> V_142 +
V_102 [ V_148 ] ) ;
V_124 -> V_149 = ( V_124 -> V_146 +
V_102 [ V_150 ] ) ;
}
return V_100 ;
}
static int F_60 ( struct V_11 * V_9 )
{
F_61 ( V_151 , V_152 ) ;
int V_18 ;
F_45 ( V_152 !=
V_153 +
sizeof( V_9 -> V_154 ) ) ;
F_62 ( V_9 ) ;
F_63 ( ! F_64 ( & V_9 -> V_155 ) ) ;
V_18 = F_5 ( V_9 ) ;
if ( V_18 != 0 )
return V_18 ;
memcpy ( F_65 ( V_151 , V_156 ) ,
V_9 -> V_154 . V_157 , sizeof( V_9 -> V_154 ) ) ;
return F_66 ( V_9 , V_158 ,
V_151 , sizeof( V_151 ) , NULL , 0 , NULL ) ;
}
static void F_67 ( struct V_11 * V_9 , struct V_159 * V_160 )
{
struct V_47 * V_48 = V_9 -> V_48 ;
V_160 -> V_161 = V_162 ;
if ( V_48 -> V_163 != - 1 )
V_160 -> V_164 = V_162 ;
else
V_160 -> V_164 = 0 ;
memset ( & V_160 -> V_165 , 0 , sizeof( V_160 -> V_165 ) ) ;
}
static int F_68 ( struct V_11 * V_9 , T_2 type )
{
struct V_47 * V_48 = V_9 -> V_48 ;
int V_18 ;
if ( type & ~ V_162 )
return - V_34 ;
if ( type & V_162 ) {
if ( V_48 -> V_163 != - 1 )
F_69 ( V_9 ,
V_48 -> V_163 ) ;
V_18 = F_70 ( V_9 , V_9 -> V_39 -> V_166 ,
& V_48 -> V_163 ) ;
if ( V_18 )
goto V_167;
F_71 ( V_9 -> V_37 , true ) ;
} else {
V_18 = F_72 ( V_9 ) ;
V_48 -> V_163 = - 1 ;
F_71 ( V_9 -> V_37 , false ) ;
if ( V_18 )
goto V_167;
}
return 0 ;
V_167:
F_26 ( V_9 , V_168 , V_9 -> V_39 , L_5 ,
V_169 , type , V_18 ) ;
return V_18 ;
}
static void F_30 ( struct V_11 * V_9 )
{
struct V_47 * V_48 = V_9 -> V_48 ;
int V_18 ;
V_18 = F_73 ( V_9 , & V_48 -> V_163 ) ;
if ( V_18 != 0 ) {
F_72 ( V_9 ) ;
V_48 -> V_163 = - 1 ;
} else if ( V_48 -> V_163 != - 1 ) {
F_71 ( V_9 -> V_37 , true ) ;
}
}
static void F_74 ( struct V_11 * V_9 ,
const T_1 * V_170 , T_4 V_171 ,
const T_1 * V_172 , T_4 V_173 )
{
unsigned V_174 = V_44 + F_75 ( V_9 ) ;
unsigned V_175 = V_44 + F_76 ( V_9 ) ;
unsigned int V_176 ;
unsigned int V_177 = F_77 ( V_173 , 4 ) ;
F_78 ( V_171 != 4 ) ;
F_79 ( V_9 , V_170 , V_174 ) ;
for ( V_176 = 0 ; V_176 < V_177 ; V_176 ++ )
F_79 ( V_9 , & V_172 [ V_176 ] , V_174 + V_171 + 4 * V_176 ) ;
F_80 () ;
F_81 ( V_9 , ( V_178 V_179 ) 0x45789abc , V_175 ) ;
}
static bool F_82 ( struct V_11 * V_9 )
{
unsigned int V_174 = V_44 + F_75 ( V_9 ) ;
T_1 V_170 ;
F_83 ( V_9 , & V_170 , V_174 ) ;
return F_84 ( V_170 , V_180 ) != 0xffffffff &&
F_84 ( V_170 , V_181 ) ;
}
static void F_85 ( struct V_11 * V_9 , T_1 * V_182 ,
T_4 V_183 , T_4 V_184 )
{
unsigned int V_174 = V_44 + F_75 ( V_9 ) ;
unsigned int V_185 = F_77 ( V_184 , 4 ) ;
int V_176 ;
for ( V_176 = 0 ; V_176 < V_185 ; V_176 ++ )
F_83 ( V_9 , & V_182 [ V_176 ] , V_174 + V_183 + 4 * V_176 ) ;
}
static int F_86 ( struct V_11 * V_9 )
{
struct V_47 * V_48 = V_9 -> V_48 ;
unsigned int V_64 = V_44 + F_87 ( V_9 ) ;
T_1 V_49 ;
T_2 V_186 ;
F_83 ( V_9 , & V_49 , V_64 ) ;
V_186 = F_84 ( V_49 , V_180 ) ;
if ( V_186 == 0 )
return 0 ;
F_88 ( V_49 ) ;
F_79 ( V_9 , & V_49 , V_64 ) ;
V_48 -> V_102 [ V_111 ] = 0 ;
V_48 -> V_102 [ V_119 ] = 0 ;
if ( V_186 == V_187 )
return - V_188 ;
else
return - V_189 ;
}
static int F_89 ( struct V_11 * V_9 ,
struct V_190 * V_191 ,
unsigned int type )
{
const struct V_192 * V_193 ;
T_4 V_194 , V_195 ;
bool V_196 ;
int V_18 ;
if ( type >= F_11 ( V_197 ) ||
V_197 [ type ] . V_198 == NULL )
return - V_53 ;
V_193 = & V_197 [ type ] ;
if ( V_193 -> V_199 != F_90 ( V_9 ) )
return - V_53 ;
V_18 = F_91 ( V_9 , type , & V_194 , & V_195 , & V_196 ) ;
if ( V_18 )
return V_18 ;
if ( V_196 )
return - V_53 ;
V_191 -> V_200 = type ;
V_191 -> V_201 . V_202 = L_6 ;
V_191 -> V_201 . V_203 = V_193 -> V_198 ;
V_191 -> V_201 . V_204 . type = V_205 ;
V_191 -> V_201 . V_204 . V_23 = V_206 ;
V_191 -> V_201 . V_204 . V_194 = V_194 ;
V_191 -> V_201 . V_204 . V_207 = V_195 ;
return 0 ;
}
static int F_92 ( struct V_11 * V_9 ,
struct V_190 * V_208 ,
T_4 V_209 )
{
T_8 V_210 [
V_211 ] ;
T_4 V_176 ;
int V_18 ;
V_18 = F_19 ( V_9 , NULL , V_210 , NULL ) ;
if ( V_18 )
return V_18 ;
for ( V_176 = 0 ; V_176 < V_209 ; V_176 ++ )
V_208 [ V_176 ] . V_212 = V_210 [ V_208 [ V_176 ] . V_200 ] ;
return 0 ;
}
static int F_93 ( struct V_11 * V_9 )
{
struct V_190 * V_208 ;
T_2 V_213 ;
unsigned int type ;
T_4 V_209 ;
int V_18 ;
F_94 () ;
V_18 = F_95 ( V_9 , & V_213 ) ;
if ( V_18 )
return V_18 ;
V_208 = F_96 ( F_97 ( V_213 ) , sizeof( * V_208 ) , V_50 ) ;
if ( ! V_208 )
return - V_51 ;
type = 0 ;
V_209 = 0 ;
while ( V_213 != 0 ) {
if ( V_213 & 1 ) {
V_18 = F_89 ( V_9 , & V_208 [ V_209 ] ,
type ) ;
if ( V_18 == 0 )
V_209 ++ ;
else if ( V_18 != - V_53 )
goto V_167;
}
type ++ ;
V_213 >>= 1 ;
}
V_18 = F_92 ( V_9 , V_208 , V_209 ) ;
if ( V_18 )
goto V_167;
V_18 = F_98 ( V_9 , & V_208 [ 0 ] . V_201 , V_209 , sizeof( * V_208 ) ) ;
V_167:
if ( V_18 )
F_40 ( V_208 ) ;
return V_18 ;
}
static void F_99 ( struct V_11 * V_9 , T_2 V_214 )
{
F_81 ( V_9 , F_100 ( V_214 ) ,
V_44 + V_215 ) ;
}
