static inline bool F_1 ( T_1 V_1 )
{
return ( V_1 & ( 1 << V_2 ) ) ? true : false ;
}
static inline bool F_2 ( T_1 V_1 )
{
return ( V_1 & ( 1 << V_3 ) ) ? true : false ;
}
static inline bool F_3 ( T_1 V_1 )
{
return ( V_1 & ( 1 << V_4 ) ) ? true : false ;
}
static inline T_2 F_4 ( T_1 V_1 )
{
return ( V_1 >> 4 ) & 0xff ;
}
static int F_5 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_11 ;
T_3 V_12 , V_13 ;
if ( F_6 ( V_6 ) )
return 0 ;
V_11 = F_7 ( V_9 , V_14 ) ;
if ( ! V_11 )
return 0 ;
F_8 ( V_9 , V_11 + V_15 , & V_13 ) ;
F_8 ( V_9 , V_11 + V_16 , & V_12 ) ;
return ( V_9 -> V_17 + V_13 + V_12 * V_7 ) & 0xff ;
}
int F_9 ( struct V_5 * V_6 , int V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_29 , V_30 ;
if ( ! F_10 ( V_6 ) )
return - V_31 ;
V_20 = F_11 ( sizeof( struct V_19 ) , V_32 ) ;
if ( ! V_20 )
return - V_33 ;
V_6 -> V_34 -> V_20 = V_20 ;
V_20 -> V_18 = V_18 ;
V_22 = & V_20 -> V_22 ;
V_20 -> V_35 = F_11 ( sizeof( struct V_27 ) *
V_18 , V_32 ) ;
if ( ! V_20 -> V_35 ) {
V_29 = - V_33 ;
goto V_36;
}
V_24 = F_12 ( L_1 ) ;
if ( V_24 == NULL ) {
V_29 = - V_33 ;
F_13 ( & V_6 -> V_10 -> V_9 ,
L_2 ) ;
goto V_37;
}
V_22 -> V_38 = V_24 ;
V_24 = F_12 ( L_3 ) ;
if ( V_24 == NULL ) {
V_29 = - V_33 ;
F_13 ( & V_6 -> V_10 -> V_9 , L_4 ) ;
goto V_39;
}
V_22 -> V_40 = V_24 ;
F_14 ( & V_22 -> V_41 ) ;
F_15 ( & V_22 -> V_42 , V_43 ) ;
F_16 ( & V_22 -> V_44 ) ;
V_22 -> V_6 = V_6 ;
for ( V_30 = 0 ; V_30 < V_18 ; V_30 ++ ) {
V_28 = & V_20 -> V_35 [ V_30 ] ;
V_28 -> V_6 = V_6 ;
V_28 -> V_45 = F_5 ( V_6 , V_30 ) ;
F_17 ( & V_28 -> V_46 ) ;
F_16 ( & V_28 -> V_47 ) ;
F_14 ( & V_28 -> V_48 . V_49 ) ;
F_14 ( & V_28 -> V_50 . V_49 ) ;
F_16 ( & V_28 -> V_48 . V_51 ) ;
F_16 ( & V_28 -> V_50 . V_51 ) ;
F_18 ( & V_28 -> V_52 ) ;
F_15 ( & V_28 -> V_53 , V_54 ) ;
if ( F_19 ( V_6 ) ) {
V_26 = F_11 ( sizeof( struct V_25 ) , V_32 ) ;
if ( ! V_26 ) {
V_29 = - V_33 ;
goto V_55;
}
V_20 -> V_35 [ V_30 ] . V_26 = V_26 ;
V_26 -> V_56 = V_57 ;
V_26 -> V_58 = V_59 ;
V_26 -> V_60 = V_61 ;
V_26 -> V_62 = false ;
F_20 ( V_26 -> V_63 ) ;
F_21 ( & V_6 -> V_10 -> V_9 ,
L_5 ,
V_26 -> V_63 , V_30 ) ;
}
}
return 0 ;
V_55:
F_22 ( V_22 -> V_40 ) ;
V_39:
F_22 ( V_22 -> V_38 ) ;
V_37:
F_23 ( V_20 -> V_35 ) ;
V_36:
F_23 ( V_6 -> V_34 -> V_20 ) ;
return V_29 ;
}
void F_24 ( struct V_64 * V_65 )
{
struct V_66 * V_67 ;
struct V_68 V_69 ;
unsigned long V_70 ;
F_25 ( & V_65 -> V_51 , V_70 ) ;
while ( ! F_26 ( & V_65 -> V_49 ) ) {
V_67 = F_27 ( & V_65 -> V_49 ,
struct V_66 , V_71 ) ;
F_28 ( & V_67 -> V_71 ) ;
V_65 -> V_72 -- ;
V_69 . V_73 . V_74 = ( T_1 * ) V_67 -> V_75 ;
V_69 . V_76 . V_74 = ( T_1 * ) V_67 -> V_77 ;
F_29 ( & V_69 ) ;
F_30 ( V_67 ) ;
}
F_31 ( & V_65 -> V_51 , V_70 ) ;
}
void F_32 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_21 * V_22 = & V_20 -> V_22 ;
struct V_27 * V_28 ;
int V_30 ;
if ( ! F_10 ( V_6 ) )
return;
F_33 ( V_22 ) ;
F_22 ( V_22 -> V_40 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_18 ; V_30 ++ ) {
V_28 = & V_20 -> V_35 [ V_30 ] ;
F_24 ( & V_28 -> V_50 ) ;
F_34 ( & V_28 -> V_53 ) ;
F_24 ( & V_28 -> V_48 ) ;
}
F_22 ( V_22 -> V_38 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_18 ; V_30 ++ )
F_23 ( V_20 -> V_35 [ V_30 ] . V_26 ) ;
F_23 ( V_20 -> V_35 ) ;
F_23 ( V_6 -> V_34 -> V_20 ) ;
}
static void F_35 ( struct V_5 * V_6 )
{
F_36 ( V_6 , V_78 ) ;
F_37 ( V_6 , 0 ) ;
F_32 ( V_6 ) ;
}
void F_38 ( struct V_5 * V_6 )
{
if ( ! F_39 ( V_79 , & V_6 -> V_80 ) )
return;
F_40 ( V_6 ) ;
if ( F_19 ( V_6 ) )
F_41 ( V_6 ) ;
if ( F_6 ( V_6 ) )
F_35 ( V_6 ) ;
}
static int F_42 ( struct V_5 * V_6 , T_1 * V_81 ,
T_1 * V_82 , T_2 V_45 , T_2 V_83 )
{
struct V_84 * V_34 = V_6 -> V_34 ;
struct V_85 * V_86 = V_34 -> V_87 ;
struct V_68 V_69 ;
unsigned long V_88 ;
int V_29 ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
V_69 . V_81 = V_81 ;
V_69 . V_82 = V_82 ;
V_69 . V_89 = V_83 ;
V_69 . V_90 = V_45 ;
V_69 . V_91 = V_92 ;
V_69 . V_93 = ( (struct V_94 * ) V_81 ) -> V_93 ;
V_29 = V_86 -> V_95 -> V_96 ( V_6 , & V_69 , & V_88 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_6 ,
V_97 , V_69 . V_93 , V_69 . type , V_34 -> V_45 ,
V_34 -> V_98 ) ;
return V_29 ;
}
if ( ! F_43 ( & V_69 . V_99 , V_88 ) ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_7 ,
V_97 , V_69 . V_93 , V_69 . type , V_34 -> V_45 ,
V_34 -> V_98 ) ;
F_44 ( V_86 -> V_100 ) ;
}
return V_69 . V_101 ;
}
static void F_45 ( struct V_5 * V_6 )
{
V_6 -> V_102 = V_103 ;
V_6 -> V_104 = V_105 ;
V_6 -> V_106 = V_107 ;
V_6 -> V_108 = V_109 ;
V_6 -> V_110 = V_111 ;
V_6 -> V_112 = V_113 ;
}
int F_46 ( struct V_5 * V_6 ,
struct V_114 * V_115 , T_3 V_116 )
{
struct V_117 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_68 V_69 ;
int V_29 ;
T_1 V_118 ;
V_29 = F_47 ( & V_69 , V_6 , V_119 ) ;
if ( V_29 )
return V_29 ;
V_69 . V_73 . V_74 [ 1 ] = V_116 << 16 | 0x1 ;
V_29 = F_48 ( V_6 , & V_69 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_8 , V_29 ) ;
F_29 ( & V_69 ) ;
return V_29 ;
}
V_118 = V_69 . V_76 . V_74 [ 2 ] & 0xffff ;
if ( V_118 & V_120 )
V_115 -> V_60 = F_49 ( V_69 . V_76 . V_74 [ 2 ] ) ;
if ( V_118 & V_121 )
V_115 -> V_58 = F_50 ( V_69 . V_76 . V_74 [ 3 ] ) ;
if ( V_118 & V_122 )
V_115 -> V_123 = F_49 ( V_69 . V_76 . V_74 [ 3 ] ) ;
if ( V_118 & V_124 )
V_115 -> V_125 = F_50 ( V_69 . V_76 . V_74 [ 4 ] ) ;
if ( V_118 & V_126 )
V_115 -> V_127 = F_49 ( V_69 . V_76 . V_74 [ 4 ] ) ;
if ( V_118 & V_128 )
V_115 -> V_129 = F_50 ( V_69 . V_76 . V_74 [ 5 ] ) ;
if ( V_118 & V_130 )
V_115 -> V_131 = F_49 ( V_69 . V_76 . V_74 [ 5 ] ) ;
if ( V_118 & V_132 )
V_115 -> V_133 = F_50 ( V_69 . V_76 . V_74 [ 6 ] ) ;
if ( V_118 & V_134 )
V_115 -> V_135 = F_49 ( V_69 . V_76 . V_74 [ 6 ] ) ;
if ( V_118 & V_136 )
V_115 -> V_137 = F_50 ( V_69 . V_76 . V_74 [ 7 ] ) ;
V_115 -> V_138 = F_49 ( V_69 . V_76 . V_74 [ 7 ] ) ;
V_115 -> V_139 = F_50 ( V_69 . V_76 . V_74 [ 8 ] ) ;
V_115 -> V_140 = F_49 ( V_69 . V_76 . V_74 [ 8 ] ) ;
V_115 -> V_141 = F_50 ( V_69 . V_76 . V_74 [ 9 ] ) ;
F_21 ( V_9 , L_9
L_10
L_11
L_12
L_13
L_14 ,
V_115 -> V_60 , V_115 -> V_58 ,
V_115 -> V_123 , V_115 -> V_125 ,
V_115 -> V_127 ,
V_115 -> V_129 , V_115 -> V_131 ,
V_115 -> V_133 , V_115 -> V_135 ,
V_115 -> V_137 , V_115 -> V_138 ,
V_115 -> V_139 , V_115 -> V_140 ,
V_115 -> V_141 ) ;
F_29 ( & V_69 ) ;
return V_29 ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_68 * V_69 )
{
V_6 -> V_142 = F_49 ( V_69 -> V_76 . V_74 [ 1 ] ) & 0xffff ;
V_6 -> V_70 &= ~ V_143 ;
return 0 ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_68 * V_69 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
int V_30 , V_144 ;
T_3 * V_145 ;
if ( V_20 -> V_146 )
return 0 ;
V_20 -> V_147 = V_69 -> V_76 . V_74 [ 2 ] & 0xf ;
V_20 -> V_148 = V_69 -> V_76 . V_74 [ 2 ] >> 16 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_15 ,
V_20 -> V_148 ) ;
F_53 ( V_6 ) ;
if ( ! V_20 -> V_147 )
return 0 ;
V_144 = V_20 -> V_148 ;
V_20 -> V_146 = F_11 ( sizeof( T_3 ) * V_144 , V_32 ) ;
if ( ! V_20 -> V_146 )
return - V_33 ;
V_145 = ( T_3 * ) & V_69 -> V_76 . V_74 [ 3 ] ;
for ( V_30 = 0 ; V_30 < V_144 ; V_30 ++ )
V_20 -> V_146 [ V_30 ] = V_145 [ V_30 ] ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_68 V_69 ;
int V_149 = 0 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_149 = F_55 ( & V_69 , V_150 ) ;
if ( V_149 )
return V_149 ;
V_149 = F_48 ( V_6 , & V_69 ) ;
if ( V_149 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_16 ,
V_149 ) ;
} else {
V_20 -> V_56 = V_69 . V_76 . V_74 [ 1 ] & 0x3 ;
switch ( V_20 -> V_56 ) {
case V_57 :
V_149 = F_52 ( V_6 , & V_69 ) ;
break;
case V_151 :
V_149 = F_51 ( V_6 , & V_69 ) ;
break;
}
}
F_29 ( & V_69 ) ;
return V_149 ;
}
static int F_56 ( struct V_5 * V_6 )
{
struct V_84 * V_34 = V_6 -> V_34 ;
struct V_114 V_152 ;
int V_29 ;
V_29 = F_46 ( V_6 , & V_152 , 0 ) ;
if ( V_29 )
return V_29 ;
V_34 -> V_153 = V_152 . V_127 ;
V_29 = F_57 ( V_6 , & V_152 , V_34 -> V_45 ) ;
if ( V_29 )
return - V_31 ;
if ( F_58 ( V_6 ) )
return - V_31 ;
F_45 ( V_6 ) ;
V_6 -> V_70 |= V_154 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_17 ,
V_6 -> V_34 -> V_155 ) ;
V_34 -> V_156 = ( T_2 ) V_152 . V_157 ;
V_34 -> V_158 = V_152 . V_158 ;
V_34 -> V_159 = V_152 . V_159 ;
V_34 -> V_98 = V_152 . V_98 ;
V_34 -> V_160 = V_152 . V_160 ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 ,
int V_161 )
{
int V_29 ;
V_6 -> V_70 |= V_162 ;
V_6 -> V_34 -> V_163 = 1 ;
F_14 ( & V_6 -> V_164 ) ;
if ( ! V_165 && ! ! V_166 )
F_60 ( & V_6 -> V_10 -> V_9 ,
L_18 ) ;
F_61 ( V_6 , V_167 ) ;
F_62 ( V_6 , V_167 ) ;
V_29 = F_63 ( V_6 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_19 ) ;
goto V_168;
}
V_29 = F_64 ( V_6 ) ;
if ( V_29 )
goto V_168;
V_29 = F_9 ( V_6 , 1 ) ;
if ( V_29 )
goto V_169;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
goto V_170;
V_29 = F_36 ( V_6 , V_171 ) ;
if ( V_29 )
goto V_172;
V_29 = F_56 ( V_6 ) ;
if ( V_29 )
goto V_173;
V_29 = F_54 ( V_6 ) ;
if ( V_29 )
goto V_173;
V_29 = F_65 ( V_6 , V_6 -> V_174 , V_161 ) ;
if ( V_29 )
goto V_173;
F_66 ( V_6 -> V_10 , V_6 ) ;
F_21 ( & V_6 -> V_10 -> V_9 , L_20 ,
V_6 -> V_174 -> V_175 ) ;
F_67 ( V_6 , V_176 ,
V_6 -> V_34 -> V_177 . V_178 ) ;
return 0 ;
V_173:
F_36 ( V_6 , V_78 ) ;
V_172:
F_37 ( V_6 , 0 ) ;
V_170:
F_32 ( V_6 ) ;
V_169:
F_68 ( V_6 ) ;
V_168:
F_69 ( V_6 ) ;
return V_29 ;
}
static int F_70 ( struct V_5 * V_6 )
{
T_1 V_80 ;
do {
F_71 ( 20 ) ;
if ( ++ V_6 -> V_179 > V_180 )
return - V_31 ;
V_80 = F_72 ( V_6 -> V_34 , V_181 ) ;
} while ( V_80 != V_182 );
return 0 ;
}
int F_73 ( struct V_5 * V_6 , int V_161 )
{
struct V_84 * V_34 = V_6 -> V_34 ;
int V_29 ;
F_74 ( V_183 , & V_34 -> V_177 . V_118 ) ;
V_34 -> V_177 . V_178 = V_184 ;
V_34 -> V_185 = 0 ;
V_6 -> V_179 = 0 ;
V_34 -> V_186 = 1 ;
V_6 -> V_187 = 0 ;
V_6 -> V_70 |= V_188 ;
V_29 = F_70 ( V_6 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_59 ( V_6 , V_161 ) ;
if ( V_29 )
return V_29 ;
if ( F_75 ( V_6 ) )
F_60 ( & V_6 -> V_10 -> V_9 , L_21 ) ;
F_76 ( & V_6 -> V_189 , V_190 ) ;
F_77 ( V_191 , & V_6 -> V_80 ) ;
return 0 ;
}
void F_78 ( struct V_5 * V_6 )
{
struct V_84 * V_34 = V_6 -> V_34 ;
V_34 -> V_98 = V_192 ;
F_21 ( & V_6 -> V_10 -> V_9 ,
L_22 ,
V_34 -> V_155 ) ;
V_6 -> V_193 = & V_194 ;
F_74 ( V_79 , & V_6 -> V_80 ) ;
return;
}
void F_79 ( struct V_84 * V_34 )
{
V_34 -> V_195 = & V_196 ;
V_34 -> V_197 = ( T_1 * ) V_198 ;
V_34 -> V_199 = ( T_1 * ) V_200 ;
}
static T_1 F_80 ( T_1 V_201 , T_2 V_202 )
{
T_1 V_89 ;
V_89 = V_201 / ( ( V_202 + 1 ) * V_203 ) ;
if ( V_89 )
V_89 = V_203 ;
else
V_89 = V_201 % V_203 ;
return V_89 ;
}
int F_81 ( struct V_5 * V_6 , T_2 V_45 )
{
struct V_27 * V_35 = V_6 -> V_34 -> V_20 -> V_35 ;
T_2 V_30 ;
if ( F_6 ( V_6 ) )
return 0 ;
for ( V_30 = 0 ; V_30 < V_6 -> V_34 -> V_20 -> V_18 ; V_30 ++ ) {
if ( V_35 [ V_30 ] . V_45 == V_45 )
return V_30 ;
}
return - V_204 ;
}
static inline int F_82 ( struct V_66 * * V_67 )
{
* V_67 = F_11 ( sizeof( struct V_66 ) , V_205 ) ;
if ( ! * V_67 )
return - V_33 ;
F_18 ( & ( * V_67 ) -> V_206 ) ;
return 0 ;
}
static inline int F_83 ( struct V_94 * * V_81 ,
T_1 V_83 )
{
* V_81 = F_11 ( sizeof( struct V_94 ) * V_83 , V_205 ) ;
if ( ! * V_81 )
return - V_33 ;
return 0 ;
}
static int F_55 ( struct V_68 * V_86 , T_1 type )
{
const struct V_207 * V_208 ;
int V_30 , V_83 ;
V_208 = V_209 ;
V_83 = F_84 ( V_209 ) ;
for ( V_30 = 0 ; V_30 < V_83 ; V_30 ++ ) {
if ( type == V_208 [ V_30 ] . V_69 ) {
V_86 -> V_91 = V_210 ;
V_86 -> V_73 . V_211 = V_208 [ V_30 ] . V_212 ;
V_86 -> V_76 . V_211 = V_208 [ V_30 ] . V_213 ;
V_86 -> V_73 . V_74 = F_85 ( V_86 -> V_73 . V_211 , sizeof( T_1 ) ,
V_205 ) ;
if ( ! V_86 -> V_73 . V_74 )
return - V_33 ;
V_86 -> V_76 . V_74 = F_85 ( V_86 -> V_76 . V_211 , sizeof( T_1 ) ,
V_205 ) ;
if ( ! V_86 -> V_76 . V_74 ) {
F_23 ( V_86 -> V_73 . V_74 ) ;
V_86 -> V_73 . V_74 = NULL ;
return - V_33 ;
}
V_86 -> V_73 . V_74 [ 0 ] = ( type | ( V_86 -> V_73 . V_211 << 16 ) |
( 3 << 29 ) ) ;
V_86 -> V_76 . V_74 [ 0 ] = ( type & 0xffff ) | V_86 -> V_76 . V_211 << 16 ;
return 0 ;
}
}
return - V_204 ;
}
static int F_86 ( struct V_66 * V_67 ,
struct V_68 * V_69 ,
T_3 V_214 , T_2 V_215 )
{
struct V_94 * V_81 ;
int V_30 ;
T_1 V_216 , V_217 ;
T_3 V_218 ;
T_2 V_93 , V_219 , V_220 ;
V_217 = V_203 ;
if ( V_215 == V_221 ) {
V_67 -> V_75 = (struct V_222 * ) V_69 -> V_73 . V_74 ;
V_67 -> V_77 = (struct V_222 * ) V_69 -> V_76 . V_74 ;
V_216 = V_69 -> V_73 . V_211 ;
V_67 -> V_223 = ( V_216 * 4 ) ;
V_216 = V_69 -> V_76 . V_211 ;
V_67 -> V_224 = ( V_216 * 4 ) ;
V_93 = V_69 -> V_73 . V_74 [ 0 ] & 0xff ;
V_218 = ( V_67 -> V_223 ) % ( V_217 ) ;
V_219 = ( V_67 -> V_223 ) / ( V_217 ) ;
if ( V_218 )
V_219 ++ ;
V_220 = V_219 ;
if ( F_83 ( & V_67 -> V_225 , V_219 ) )
return - V_33 ;
V_218 = ( V_67 -> V_224 ) % ( V_217 ) ;
V_219 = ( V_67 -> V_224 ) / ( V_217 ) ;
if ( V_218 )
V_219 ++ ;
if ( F_83 ( & V_67 -> V_226 , V_219 ) )
return - V_33 ;
V_219 = V_220 ;
V_81 = V_67 -> V_225 ;
} else {
V_69 -> V_73 . V_74 = ( T_1 * ) V_67 -> V_75 ;
V_69 -> V_76 . V_74 = ( T_1 * ) V_67 -> V_77 ;
V_93 = V_69 -> V_73 . V_74 [ 0 ] & 0xff ;
V_69 -> V_93 = V_93 ;
V_218 = ( V_67 -> V_224 ) % ( V_217 ) ;
V_219 = ( V_67 -> V_224 ) / ( V_217 ) ;
if ( V_218 )
V_219 ++ ;
V_69 -> V_73 . V_211 = V_67 -> V_223 / 4 ;
V_69 -> V_76 . V_211 = V_67 -> V_224 / 4 ;
V_81 = V_67 -> V_226 ;
V_69 -> V_91 = V_67 -> V_225 -> V_91 ;
}
V_67 -> V_227 = V_214 ;
V_67 -> V_228 = V_93 ;
for ( V_30 = 0 ; V_30 < V_219 ; V_30 ++ ) {
V_81 [ V_30 ] . V_229 = 2 ;
V_81 [ V_30 ] . V_215 = V_215 ;
V_81 [ V_30 ] . V_91 = V_69 -> V_91 ;
V_81 [ V_30 ] . V_230 = 1 ;
V_81 [ V_30 ] . V_219 = V_219 ;
V_81 [ V_30 ] . V_231 = V_30 + 1 ;
V_81 [ V_30 ] . V_93 = V_93 ;
V_81 [ V_30 ] . V_232 = V_214 ;
}
return 0 ;
}
static void F_30 ( struct V_66 * V_67 )
{
if ( ! V_67 )
return;
F_23 ( V_67 -> V_225 ) ;
F_23 ( V_67 -> V_226 ) ;
F_23 ( V_67 ) ;
}
static int F_87 ( struct V_27 * V_28 ,
struct V_66 * V_67 , T_2 type )
{
struct V_64 * V_65 ;
unsigned long V_70 ;
int V_149 = 0 ;
if ( type == V_233 ) {
V_65 = & V_28 -> V_48 ;
F_25 ( & V_65 -> V_51 , V_70 ) ;
V_65 -> V_72 -- ;
F_28 ( & V_67 -> V_71 ) ;
if ( V_65 -> V_72 > 0 )
V_149 = 1 ;
F_31 ( & V_65 -> V_51 , V_70 ) ;
}
if ( type == V_221 ) {
while ( F_88 ( V_234 , & V_28 -> V_80 ) )
F_71 ( 100 ) ;
V_28 -> V_235 = NULL ;
F_77 ( V_234 , & V_28 -> V_80 ) ;
}
return V_149 ;
}
static void F_89 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
T_4 V_236 )
{
if ( F_39 ( V_237 , & V_28 -> V_80 ) ||
V_28 -> V_6 -> V_187 )
return;
F_90 ( V_20 -> V_22 . V_38 , & V_28 -> V_53 ) ;
}
static inline void F_91 ( struct V_66 * V_67 )
{
struct V_99 * V_238 = & V_67 -> V_206 ;
if ( F_43 ( V_238 , V_239 ) )
V_67 -> V_240 = V_241 ;
else
V_67 -> V_240 = V_242 ;
return;
}
static void F_92 ( struct V_66 * V_67 ,
T_2 type )
{
if ( type == V_233 ) {
V_67 -> V_243 ++ ;
if ( V_67 -> V_243 < V_67 -> V_226 -> V_219 )
V_67 -> V_240 = V_244 ;
else
V_67 -> V_240 = V_241 ;
} else {
V_67 -> V_245 ++ ;
if ( V_67 -> V_245 < V_67 -> V_225 -> V_219 )
V_67 -> V_240 = V_244 ;
else
V_67 -> V_240 = V_246 ;
}
}
static void F_93 ( struct V_66 * V_67 ,
T_2 type )
{
struct V_27 * V_28 = V_67 -> V_28 ;
struct V_99 * V_238 = & V_28 -> V_52 ;
if ( ! F_43 ( V_238 , V_247 ) ) {
V_67 -> V_240 = V_242 ;
return;
}
F_77 ( V_248 , & V_28 -> V_80 ) ;
F_92 ( V_67 , type ) ;
}
static void F_94 ( struct V_5 * V_6 ,
T_1 * V_81 , T_1 * V_82 , T_1 V_83 )
{
struct V_84 * V_34 = V_6 -> V_34 ;
T_1 V_249 ;
T_2 V_30 , V_250 = 2 , V_251 , V_252 ;
V_251 = ( sizeof( struct V_94 ) / sizeof( T_1 ) ) ;
V_250 = ( V_83 / sizeof( T_1 ) ) + V_251 ;
V_249 = F_95 ( F_96 ( V_34 , 0 ) ) ;
for ( V_30 = 2 , V_252 = 0 ; V_252 < V_251 ; V_30 ++ , V_252 ++ )
* ( V_81 ++ ) = F_95 ( F_96 ( V_34 , V_30 ) ) ;
for (; V_252 < V_250 ; V_30 ++ , V_252 ++ )
* ( V_82 ++ ) = F_95 ( F_96 ( V_34 , V_30 ) ) ;
}
static int F_97 ( struct V_27 * V_28 )
{
int V_149 = - V_253 ;
T_1 V_88 = 10000 ;
do {
if ( ! F_88 ( V_248 , & V_28 -> V_80 ) ) {
V_149 = 0 ;
break;
}
F_98 ( 1 ) ;
} while ( -- V_88 );
return V_149 ;
}
static int F_99 ( struct V_66 * V_67 , T_2 type )
{
struct V_27 * V_28 = V_67 -> V_28 ;
T_1 V_89 , V_251 ;
T_1 * V_81 , * V_82 ;
int V_149 ;
T_2 V_45 = V_67 -> V_254 ;
if ( F_97 ( V_28 ) )
return - V_253 ;
if ( type == V_221 ) {
V_81 = ( T_1 * ) ( V_67 -> V_225 + V_67 -> V_245 ) ;
V_82 = ( T_1 * ) ( V_67 -> V_75 + V_67 -> V_245 ) ;
V_251 = ( sizeof( struct V_94 ) / sizeof( T_1 ) ) ;
V_89 = F_80 ( V_67 -> V_223 ,
V_67 -> V_245 ) ;
V_89 = ( V_89 / sizeof( T_1 ) ) ;
} else {
V_81 = ( T_1 * ) ( V_67 -> V_226 + V_67 -> V_243 ) ;
V_82 = ( T_1 * ) ( V_67 -> V_77 + V_67 -> V_243 ) ;
V_251 = ( sizeof( struct V_94 ) / sizeof( T_1 ) ) ;
V_89 = F_80 ( V_67 -> V_224 ,
V_67 -> V_243 ) ;
V_89 = ( V_89 / sizeof( T_1 ) ) ;
}
V_149 = F_42 ( V_28 -> V_6 , V_81 , V_82 ,
V_45 , V_89 ) ;
return V_149 ;
}
static int F_100 ( struct V_66 * V_67 ,
struct V_27 * V_28 , T_2 type )
{
bool V_255 = true ;
int V_29 = - V_31 ;
while ( V_255 ) {
if ( F_39 ( V_237 , & V_28 -> V_80 ) ||
V_28 -> V_6 -> V_187 )
V_67 -> V_240 = V_242 ;
switch ( V_67 -> V_240 ) {
case V_244 :
V_67 -> V_240 = V_256 ;
if ( F_99 ( V_67 , type ) )
V_67 -> V_240 = V_242 ;
break;
case V_256 :
F_93 ( V_67 , type ) ;
break;
case V_246 :
F_91 ( V_67 ) ;
break;
case V_241 :
V_29 = 0 ;
V_255 = false ;
break;
case V_242 :
V_29 = - V_31 ;
V_255 = false ;
F_77 ( V_248 , & V_28 -> V_80 ) ;
break;
default:
V_29 = - V_31 ;
V_255 = false ;
}
}
return V_29 ;
}
static int F_101 ( struct V_5 * V_6 ,
struct V_66 * V_67 , int V_45 )
{
struct V_27 * V_28 ;
int V_29 , V_257 = F_81 ( V_6 , V_45 ) ;
if ( V_257 < 0 )
return - V_31 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ V_257 ] ;
V_67 -> V_28 = V_28 ;
V_67 -> V_254 = V_45 ;
if ( ! F_39 ( V_258 , & V_28 -> V_80 ) ) {
if ( F_19 ( V_6 ) )
return - V_31 ;
if ( F_6 ( V_6 ) &&
V_67 -> V_228 != V_171 )
return - V_31 ;
}
F_102 ( & V_28 -> V_46 ) ;
V_28 -> V_235 = V_67 ;
V_29 = F_100 ( V_67 , V_28 , V_221 ) ;
F_87 ( V_28 , V_67 , V_221 ) ;
F_103 ( & V_28 -> V_46 ) ;
return V_29 ;
}
static void F_104 ( struct V_5 * V_6 ,
struct V_66 * V_67 ,
struct V_68 * V_69 )
{
#ifdef F_105
if ( F_19 ( V_6 ) ) {
F_106 ( V_6 , V_67 , V_69 ) ;
return;
}
#endif
V_69 -> V_76 . V_74 [ 0 ] |= ( 0x9 << 25 ) ;
return;
}
static void V_54 ( struct V_259 * V_260 )
{
struct V_27 * V_28 = F_107 ( V_260 , struct V_27 ,
V_53 ) ;
struct V_66 * V_67 = NULL ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_68 V_69 ;
T_2 V_73 ;
if ( V_6 -> V_187 )
return;
if ( F_39 ( V_237 , & V_28 -> V_80 ) )
return;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
V_67 = F_27 ( & V_28 -> V_48 . V_49 ,
struct V_66 , V_71 ) ;
V_6 = V_28 -> V_6 ;
if ( F_86 ( V_67 , & V_69 , V_67 -> V_225 -> V_232 ,
V_233 ) )
goto V_261;
F_104 ( V_6 , V_67 , & V_69 ) ;
V_67 -> V_240 = V_244 ;
F_100 ( V_67 , V_28 , V_233 ) ;
V_261:
F_29 ( & V_69 ) ;
V_73 = F_87 ( V_28 , V_67 , V_233 ) ;
F_30 ( V_67 ) ;
if ( V_73 )
F_89 ( V_6 -> V_34 -> V_20 , V_28 ,
V_54 ) ;
}
static void F_108 ( struct V_94 * V_81 ,
struct V_27 * V_28 )
{
struct V_66 * V_67 ;
T_1 V_89 ;
if ( F_88 ( V_234 , & V_28 -> V_80 ) )
return;
V_67 = V_28 -> V_235 ;
if ( V_67 == NULL )
goto V_262;
if ( V_67 -> V_227 != V_81 -> V_232 )
goto V_262;
V_89 = F_80 ( V_67 -> V_224 ,
V_67 -> V_243 ) ;
F_94 ( V_28 -> V_6 ,
( T_1 * ) ( V_67 -> V_226 + V_67 -> V_243 ) ,
( T_1 * ) ( V_67 -> V_77 + V_67 -> V_243 ) ,
V_89 ) ;
if ( ++ V_67 -> V_243 < V_67 -> V_226 -> V_219 )
goto V_262;
F_109 ( & V_67 -> V_206 ) ;
V_262:
F_77 ( V_234 , & V_28 -> V_80 ) ;
}
int F_110 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_66 * V_67 )
{
struct V_64 * V_65 = & V_28 -> V_48 ;
V_65 -> V_72 ++ ;
F_111 ( & V_67 -> V_71 , & V_65 -> V_49 ) ;
if ( V_65 -> V_72 == 1 )
F_89 ( V_20 , V_28 ,
V_54 ) ;
return 0 ;
}
static int F_112 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_66 * V_67 )
{
struct V_64 * V_65 = & V_28 -> V_48 ;
F_113 ( & V_65 -> V_51 ) ;
F_110 ( V_20 , V_28 , V_67 ) ;
F_114 ( & V_65 -> V_51 ) ;
return 0 ;
}
static void F_115 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_94 * V_81 )
{
struct V_66 * V_67 = NULL ;
struct V_263 * V_264 ;
T_1 V_89 , V_202 ;
T_2 V_265 = 0 , V_266 = 0 ;
F_113 ( & V_28 -> V_50 . V_51 ) ;
if ( V_28 -> V_50 . V_72 > 0 ) {
F_116 (node, &vf->rcv_pend.wait_list) {
V_67 = F_117 ( V_264 , struct V_66 , V_71 ) ;
if ( V_67 -> V_227 == V_81 -> V_232 ) {
V_265 = 1 ;
break;
}
}
}
if ( V_265 ) {
V_202 = V_67 -> V_245 ;
V_89 = F_80 ( V_67 -> V_223 ,
V_202 ) ;
F_94 ( V_28 -> V_6 ,
( T_1 * ) ( V_67 -> V_225 + V_202 ) ,
( T_1 * ) ( V_67 -> V_75 + V_202 ) ,
V_89 ) ;
V_67 -> V_245 ++ ;
if ( V_67 -> V_245 >= V_81 -> V_219 ) {
V_28 -> V_50 . V_72 -- ;
F_28 ( & V_67 -> V_71 ) ;
V_266 = 1 ;
}
}
F_114 ( & V_28 -> V_50 . V_51 ) ;
if ( V_266 )
if ( F_112 ( V_20 , V_28 , V_67 ) )
F_30 ( V_67 ) ;
return;
}
static void F_118 ( struct V_19 * V_20 ,
struct V_94 * V_81 ,
struct V_27 * V_28 )
{
struct V_66 * V_67 ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_68 V_69 ;
T_1 V_89 ;
int V_29 ;
T_2 V_93 ;
if ( V_6 -> V_187 )
return;
if ( ! F_39 ( V_258 , & V_28 -> V_80 ) &&
V_81 -> V_91 != V_210 &&
V_81 -> V_93 != V_171 )
return;
if ( V_81 -> V_231 > 1 ) {
F_115 ( V_20 , V_28 , V_81 ) ;
return;
}
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
V_93 = V_81 -> V_93 ;
if ( F_82 ( & V_67 ) )
return;
if ( V_81 -> V_91 == V_210 )
V_29 = F_55 ( & V_69 , V_93 ) ;
else
V_29 = F_47 ( & V_69 , V_6 , V_93 ) ;
if ( V_29 ) {
F_30 ( V_67 ) ;
return;
}
V_69 . V_91 = V_81 -> V_91 ;
if ( F_86 ( V_67 , & V_69 , V_81 -> V_232 ,
V_221 ) ) {
F_29 ( & V_69 ) ;
F_30 ( V_67 ) ;
return;
}
V_89 = F_80 ( V_67 -> V_223 ,
V_67 -> V_245 ) ;
F_94 ( V_28 -> V_6 ,
( T_1 * ) ( V_67 -> V_225 + V_67 -> V_245 ) ,
( T_1 * ) ( V_67 -> V_75 + V_67 -> V_245 ) ,
V_89 ) ;
V_67 -> V_254 = V_28 -> V_45 ;
V_67 -> V_28 = V_28 ;
V_67 -> V_227 = V_81 -> V_232 ;
V_67 -> V_245 ++ ;
if ( F_119 ( V_6 , V_67 , V_28 ) )
return;
if ( V_67 -> V_245 == V_67 -> V_225 -> V_219 ) {
if ( F_112 ( V_20 , V_28 , V_67 ) ) {
F_29 ( & V_69 ) ;
F_30 ( V_67 ) ;
}
} else {
F_113 ( & V_28 -> V_50 . V_51 ) ;
F_111 ( & V_67 -> V_71 , & V_28 -> V_50 . V_49 ) ;
V_28 -> V_50 . V_72 ++ ;
F_114 ( & V_28 -> V_50 . V_51 ) ;
}
}
static void F_120 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
struct V_94 V_81 ;
T_1 * V_267 = ( T_1 * ) & V_81 ;
T_2 V_215 , V_30 ;
for ( V_30 = 2 ; V_30 < 6 ; V_30 ++ )
V_267 [ V_30 - 2 ] = F_95 ( F_96 ( V_28 -> V_6 -> V_34 , V_30 ) ) ;
V_215 = V_81 . V_215 ;
switch ( V_215 ) {
case V_221 :
F_118 ( V_20 , & V_81 , V_28 ) ;
break;
case V_233 :
F_108 ( & V_81 , V_28 ) ;
break;
}
}
static void F_121 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_28 -> V_6 ;
if ( F_19 ( V_6 ) )
F_122 ( V_20 , V_28 ) ;
else
F_13 ( & V_6 -> V_10 -> V_9 ,
L_23 ) ;
}
void F_123 ( struct V_5 * V_6 , T_1 V_268 )
{
struct V_27 * V_28 ;
struct V_19 * V_20 ;
int V_257 ;
T_2 V_45 ;
V_20 = V_6 -> V_34 -> V_20 ;
V_45 = F_4 ( V_268 ) ;
V_257 = F_81 ( V_6 , V_45 ) ;
if ( V_257 < 0 )
return;
V_28 = & V_20 -> V_35 [ V_257 ] ;
V_28 -> V_45 = V_45 ;
if ( F_2 ( V_268 ) )
F_109 ( & V_28 -> V_52 ) ;
if ( F_3 ( V_268 ) ) {
F_121 ( V_20 , V_28 ) ;
return;
}
if ( F_1 ( V_268 ) )
F_120 ( V_20 , V_28 ) ;
}
int F_37 ( struct V_5 * V_6 , T_2 V_269 )
{
struct V_68 V_69 ;
int V_29 ;
if ( ! F_39 ( V_79 , & V_6 -> V_80 ) )
return 0 ;
if ( F_47 ( & V_69 , V_6 , V_270 ) )
return - V_33 ;
if ( V_269 )
V_69 . V_73 . V_74 [ 1 ] = ( 1 << 4 ) | ( 1 << 5 ) | ( 1 << 6 ) | ( 1 << 7 ) ;
V_29 = F_124 ( V_6 , & V_69 ) ;
if ( V_29 != V_271 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_24 ,
( V_269 ? L_25 : L_26 ) , V_29 ) ;
}
F_29 ( & V_69 ) ;
return V_29 ;
}
static int F_125 ( struct V_5 * V_6 ,
struct V_66 * V_67 )
{
T_2 V_250 = V_180 ;
T_1 V_80 ;
V_80 = F_72 ( V_6 -> V_34 , V_181 ) ;
if ( V_80 == V_182 ) {
F_71 ( 20 ) ;
F_77 ( V_248 , & V_67 -> V_28 -> V_80 ) ;
V_67 -> V_240 = V_244 ;
if ( ++ V_6 -> V_179 > V_250 )
return - V_31 ;
else
return 0 ;
}
return - V_31 ;
}
static int F_126 ( struct V_5 * V_6 ,
struct V_68 * V_69 )
{
struct V_84 * V_34 = V_6 -> V_34 ;
struct V_85 * V_86 = V_34 -> V_87 ;
struct V_117 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_66 * V_67 ;
int V_29 ;
T_1 V_272 , V_273 , V_274 , V_76 ;
T_3 V_214 = ++ V_6 -> V_34 -> V_20 -> V_22 . V_275 ;
T_2 V_236 = V_34 -> V_45 ;
V_76 = F_82 ( & V_67 ) ;
if ( V_76 )
goto V_276;
V_76 = F_86 ( V_67 , V_69 , V_214 , V_221 ) ;
if ( V_76 )
goto V_277;
V_278:
if ( ! F_39 ( V_279 , & V_86 -> V_118 ) ) {
V_76 = - V_31 ;
F_127 ( V_6 , V_280 , L_27 ,
F_128 ( V_69 -> V_73 . V_74 [ 0 ] ) , V_236 ) ;
goto V_281;
}
V_29 = F_101 ( V_6 , V_67 , V_236 ) ;
if ( V_29 ) {
F_13 ( V_9 , L_28 ,
( V_69 -> V_73 . V_74 [ 0 ] & 0xffff ) , V_236 ) ;
V_76 = V_282 ;
if ( ( V_67 -> V_225 -> V_93 == V_171 ) &&
! F_125 ( V_6 , V_67 ) )
goto V_278;
goto V_281;
}
V_272 = V_69 -> V_76 . V_74 [ 0 ] ;
V_274 = F_129 ( V_272 ) ;
V_273 = F_128 ( V_69 -> V_73 . V_74 [ 0 ] ) ;
if ( ( V_274 == V_283 ) ||
( V_274 == V_284 ) ) {
V_76 = V_271 ;
} else {
if ( V_69 -> type == V_285 ) {
V_76 = V_271 ;
} else {
V_76 = V_274 ;
if ( ! V_76 )
V_76 = 1 ;
F_13 ( V_9 ,
L_29 ,
V_273 , V_274 , V_236 ) ;
}
}
V_281:
if ( V_76 == V_282 ) {
V_34 -> V_185 = 1 ;
V_6 -> V_187 = 1 ;
F_77 ( V_279 , & V_86 -> V_118 ) ;
}
V_277:
F_30 ( V_67 ) ;
V_276:
if ( V_69 -> type == V_285 ) {
F_29 ( V_69 ) ;
F_23 ( V_69 ) ;
}
return V_76 ;
}
static int F_130 ( struct V_5 * V_6 ,
struct V_68 * V_69 )
{
if ( V_69 -> type == V_285 )
return F_131 ( V_6 , V_69 ) ;
else
return F_126 ( V_6 , V_69 ) ;
}
static int F_36 ( struct V_5 * V_6 , T_2 V_93 )
{
struct V_68 V_69 ;
struct V_27 * V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
int V_149 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( F_55 ( & V_69 , V_93 ) )
return - V_33 ;
V_149 = F_48 ( V_6 , & V_69 ) ;
if ( V_149 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_30 , V_93 ? L_31 : L_32 ,
V_149 ) ;
goto V_286;
}
V_93 = ( V_69 . V_76 . V_74 [ 0 ] & 0xff ) ;
if ( V_69 . V_76 . V_74 [ 0 ] >> 25 == 2 )
return 2 ;
if ( V_93 == V_171 )
F_74 ( V_258 , & V_28 -> V_80 ) ;
else
F_77 ( V_258 , & V_28 -> V_80 ) ;
V_286:
F_29 ( & V_69 ) ;
return V_149 ;
}
static void F_132 ( struct V_287 * V_174 , const T_2 * V_63 ,
enum V_288 V_289 )
{
struct V_5 * V_6 = F_133 ( V_174 ) ;
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
T_3 V_290 ;
int V_30 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
if ( ! F_134 ( V_28 ) ) {
F_135 ( V_6 , V_63 , 0 , V_289 ) ;
} else {
F_113 ( & V_28 -> V_47 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_148 ; V_30 ++ ) {
V_290 = V_28 -> V_291 [ V_30 ] ;
if ( V_290 )
F_135 ( V_6 , V_63 , V_290 ,
V_289 ) ;
}
F_114 ( & V_28 -> V_47 ) ;
if ( F_136 ( V_6 ) )
F_135 ( V_6 , V_63 , 0 , V_289 ) ;
}
}
void F_33 ( struct V_21 * V_22 )
{
struct V_263 * V_292 = & V_22 -> V_41 ;
struct V_293 * V_294 ;
F_44 ( V_22 -> V_40 ) ;
F_34 ( & V_22 -> V_42 ) ;
F_113 ( & V_22 -> V_44 ) ;
while ( ! F_26 ( V_292 ) ) {
V_294 = F_117 ( V_292 -> V_295 , struct V_293 ,
V_71 ) ;
F_28 ( & V_294 -> V_71 ) ;
F_23 ( V_294 -> V_69 ) ;
F_23 ( V_294 ) ;
}
F_114 ( & V_22 -> V_44 ) ;
}
void F_137 ( struct V_287 * V_174 )
{
struct V_5 * V_6 = F_133 ( V_174 ) ;
struct V_84 * V_34 = V_6 -> V_34 ;
static const T_2 V_296 [ V_297 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
struct V_298 * V_299 ;
T_1 V_300 = V_301 ;
if ( ! F_39 ( V_302 , & V_6 -> V_80 ) )
return;
if ( V_174 -> V_70 & V_303 ) {
if ( ! ( V_6 -> V_70 & V_304 ) )
V_300 = V_305 ;
} else if ( ( V_174 -> V_70 & V_306 ) ||
( F_138 ( V_174 ) > V_34 -> V_153 ) ) {
V_300 = V_307 ;
} else {
F_132 ( V_174 , V_296 , V_308 ) ;
if ( ! F_139 ( V_174 ) ) {
F_140 ( V_6 ) ;
F_141 (ha, netdev)
F_132 ( V_174 , V_299 -> V_309 ,
V_310 ) ;
}
}
if ( F_142 ( V_174 ) > V_34 -> V_311 ) {
V_300 = V_305 ;
} else if ( ! F_143 ( V_174 ) ) {
F_144 (ha, netdev)
F_132 ( V_174 , V_299 -> V_309 ,
V_312 ) ;
}
if ( V_6 -> V_10 -> V_313 ) {
if ( V_300 == V_305 &&
! V_6 -> V_314 ) {
F_145 ( V_6 ) ;
V_6 -> V_315 = 1 ;
V_6 -> V_316 = true ;
} else {
V_6 -> V_315 = 0 ;
V_6 -> V_316 = false ;
}
}
F_146 ( V_6 , V_300 ) ;
}
static void V_43 ( struct V_259 * V_260 )
{
struct V_293 * V_294 , * V_317 ;
struct V_21 * V_22 ;
struct V_68 * V_69 ;
struct V_263 * V_292 ;
F_147 ( V_318 ) ;
V_22 = F_107 ( V_260 , struct V_21 , V_42 ) ;
V_292 = & V_22 -> V_41 ;
F_113 ( & V_22 -> V_44 ) ;
F_148 ( V_292 , & V_318 ) ;
F_114 ( & V_22 -> V_44 ) ;
F_149 (entry, tmp, &del_list, list) {
F_28 ( & V_294 -> V_71 ) ;
V_69 = V_294 -> V_69 ;
F_126 ( V_22 -> V_6 , V_69 ) ;
F_23 ( V_294 ) ;
}
if ( ! F_26 ( V_292 ) )
F_90 ( V_22 -> V_40 , & V_22 -> V_42 ) ;
return;
}
static struct V_293 *
F_150 ( struct V_21 * V_22 ,
struct V_68 * V_69 )
{
struct V_293 * V_294 = NULL ;
V_294 = F_11 ( sizeof( * V_294 ) , V_205 ) ;
if ( ! V_294 )
return NULL ;
V_294 -> V_69 = V_69 ;
F_113 ( & V_22 -> V_44 ) ;
F_111 ( & V_294 -> V_71 , & V_22 -> V_41 ) ;
F_114 ( & V_22 -> V_44 ) ;
return V_294 ;
}
static void F_151 ( struct V_21 * V_22 ,
struct V_68 * V_69 )
{
struct V_293 * V_294 = NULL ;
V_294 = F_150 ( V_22 , V_69 ) ;
if ( ! V_294 ) {
F_29 ( V_69 ) ;
F_23 ( V_69 ) ;
return;
}
F_90 ( V_22 -> V_40 , & V_22 -> V_42 ) ;
}
static int F_131 ( struct V_5 * V_6 ,
struct V_68 * V_69 )
{
struct V_21 * V_22 = & V_6 -> V_34 -> V_20 -> V_22 ;
if ( V_6 -> V_187 )
return - V_31 ;
F_151 ( V_22 , V_69 ) ;
return 0 ;
}
static int F_152 ( struct V_5 * V_6 )
{
int V_29 ;
V_6 -> V_187 = 0 ;
F_153 ( V_6 -> V_34 -> V_87 ) ;
F_154 ( V_6 ) ;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_6 , V_171 ) ;
if ( V_29 )
goto V_319;
V_29 = F_56 ( V_6 ) ;
if ( V_29 )
goto V_320;
return 0 ;
V_320:
F_36 ( V_6 , V_78 ) ;
V_319:
F_37 ( V_6 , 0 ) ;
return V_29 ;
}
static void F_155 ( struct V_5 * V_6 )
{
struct V_287 * V_174 = V_6 -> V_174 ;
if ( F_156 ( V_174 ) ) {
if ( ! F_157 ( V_6 , V_174 ) )
F_158 ( V_174 , V_321 ) ;
}
F_159 ( V_174 ) ;
}
static void F_160 ( struct V_5 * V_6 )
{
struct V_84 * V_34 = V_6 -> V_34 ;
struct V_322 * V_323 = V_34 -> V_323 ;
struct V_287 * V_174 = V_6 -> V_174 ;
T_2 V_30 , V_324 = V_34 -> V_325 - 1 ;
F_161 ( V_174 ) ;
F_162 ( V_6 ) ;
F_163 ( V_6 ) ;
if ( F_156 ( V_174 ) )
F_164 ( V_6 , V_174 ) ;
for ( V_30 = 0 ; V_30 < V_324 ; V_30 ++ ) {
V_323 [ V_30 ] . V_326 = V_30 ;
V_323 [ V_30 ] . V_327 = 0 ;
V_323 [ V_30 ] . V_328 = 0 ;
}
V_34 -> V_185 = 0 ;
}
static int F_165 ( struct V_5 * V_6 )
{
struct V_84 * V_34 = V_6 -> V_34 ;
struct V_117 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_329 * V_177 = & V_34 -> V_177 ;
T_2 V_236 = V_34 -> V_45 ;
T_1 V_80 ;
if ( ( V_177 -> V_330 == V_331 ) ||
( V_177 -> V_330 == V_332 ) ) {
if ( ! F_152 ( V_6 ) ) {
F_155 ( V_6 ) ;
V_6 -> V_179 = 0 ;
F_21 ( V_9 ,
L_33 ,
V_97 , V_236 ) ;
} else {
F_13 ( V_9 ,
L_34 ,
V_97 , V_236 ) ;
V_80 = F_72 ( V_34 , V_181 ) ;
F_21 ( V_9 , L_35 ,
V_80 ) ;
}
}
return 0 ;
}
static int F_166 ( struct V_5 * V_6 )
{
struct V_84 * V_34 = V_6 -> V_34 ;
struct V_85 * V_86 = V_34 -> V_87 ;
struct V_117 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_329 * V_177 = & V_34 -> V_177 ;
T_2 V_236 = V_34 -> V_45 ;
T_1 V_80 ;
V_6 -> V_333 ++ ;
if ( V_6 -> V_333 < 3 ) {
V_6 -> V_187 = 1 ;
F_77 ( V_279 , & V_86 -> V_118 ) ;
F_21 ( V_9 ,
L_36 ) ;
return 0 ;
}
if ( V_6 -> V_333 > V_334 ) {
F_77 ( V_183 , & V_177 -> V_118 ) ;
V_6 -> V_335 = 0 ;
V_6 -> V_179 = 0 ;
V_6 -> V_333 = 0 ;
F_160 ( V_6 ) ;
F_13 ( V_9 ,
L_37 ) ;
return - V_31 ;
}
F_21 ( V_9 , L_38 , V_236 ) ;
F_21 ( V_9 , L_39 ,
V_97 , V_6 -> V_333 , V_236 ) ;
F_74 ( V_191 , & V_6 -> V_80 ) ;
V_6 -> V_187 = 1 ;
F_77 ( V_279 , & V_86 -> V_118 ) ;
F_160 ( V_6 ) ;
V_6 -> V_187 = 0 ;
if ( ! F_152 ( V_6 ) ) {
F_155 ( V_6 ) ;
V_6 -> V_335 = 0 ;
V_6 -> V_333 = 0 ;
V_6 -> V_179 = 0 ;
F_21 ( V_9 , L_40 , V_236 ) ;
} else {
F_13 ( V_9 , L_41 ,
V_97 , V_236 ) ;
V_80 = F_72 ( V_34 , V_181 ) ;
F_21 ( V_9 , L_42 , V_97 , V_80 ) ;
}
return 0 ;
}
static int F_167 ( struct V_5 * V_6 )
{
struct V_84 * V_34 = V_6 -> V_34 ;
int V_149 = 0 ;
if ( V_34 -> V_177 . V_330 != V_182 )
V_149 = F_165 ( V_6 ) ;
else if ( V_34 -> V_185 )
V_149 = F_166 ( V_6 ) ;
F_77 ( V_191 , & V_6 -> V_80 ) ;
return V_149 ;
}
static int F_168 ( struct V_5 * V_6 )
{
struct V_329 * V_177 = & V_6 -> V_34 -> V_177 ;
F_13 ( & V_6 -> V_10 -> V_9 , L_43 ) ;
if ( V_177 -> V_330 == V_182 )
F_160 ( V_6 ) ;
F_77 ( V_183 , & V_177 -> V_118 ) ;
F_77 ( V_191 , & V_6 -> V_80 ) ;
return - V_31 ;
}
static int
F_169 ( struct V_5 * V_6 )
{
struct V_85 * V_86 = V_6 -> V_34 -> V_87 ;
struct V_329 * V_177 = & V_6 -> V_34 -> V_177 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_44 ) ;
if ( V_177 -> V_330 == V_182 ) {
F_74 ( V_191 , & V_6 -> V_80 ) ;
V_6 -> V_335 = 0 ;
V_6 -> V_333 = 0 ;
F_77 ( V_279 , & V_86 -> V_118 ) ;
F_160 ( V_6 ) ;
}
return 0 ;
}
static int F_170 ( struct V_5 * V_6 )
{
struct V_85 * V_86 = V_6 -> V_34 -> V_87 ;
struct V_329 * V_177 = & V_6 -> V_34 -> V_177 ;
T_2 V_236 = V_6 -> V_34 -> V_45 ;
if ( V_177 -> V_330 == V_182 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_45 , V_236 ) ;
F_74 ( V_191 , & V_6 -> V_80 ) ;
V_6 -> V_335 = 0 ;
V_6 -> V_333 = 0 ;
F_77 ( V_279 , & V_86 -> V_118 ) ;
F_160 ( V_6 ) ;
}
return 0 ;
}
static int F_171 ( struct V_5 * V_6 )
{
F_13 ( & V_6 -> V_10 -> V_9 , L_46 , V_97 ) ;
return 0 ;
}
static void F_172 ( struct V_5 * V_6 )
{
if ( V_6 -> V_336 . V_337 )
F_173 ( V_6 ) ;
}
static void V_176 ( struct V_259 * V_260 )
{
struct V_5 * V_6 ;
struct V_329 * V_177 ;
int V_149 = 0 ;
V_6 = F_107 ( V_260 , struct V_5 , V_338 . V_260 ) ;
V_177 = & V_6 -> V_34 -> V_177 ;
V_177 -> V_339 = F_72 ( V_6 -> V_34 , V_181 ) ;
switch ( V_177 -> V_339 ) {
case V_182 :
V_149 = F_167 ( V_6 ) ;
break;
case V_331 :
case V_332 :
V_149 = F_170 ( V_6 ) ;
break;
case V_340 :
V_149 = F_169 ( V_6 ) ;
break;
case V_341 :
V_149 = F_168 ( V_6 ) ;
break;
case V_342 :
break;
default:
V_149 = F_171 ( V_6 ) ;
}
V_177 -> V_330 = V_177 -> V_339 ;
F_172 ( V_6 ) ;
if ( ! V_149 && F_39 ( V_183 , & V_177 -> V_118 ) )
F_67 ( V_6 , V_176 ,
V_177 -> V_178 ) ;
}
static void F_174 ( struct V_5 * V_6 )
{
while ( F_88 ( V_191 , & V_6 -> V_80 ) )
F_71 ( 20 ) ;
F_77 ( V_183 , & V_6 -> V_34 -> V_177 . V_118 ) ;
F_77 ( V_191 , & V_6 -> V_80 ) ;
F_175 ( & V_6 -> V_338 ) ;
}
static int F_176 ( struct V_19 * V_20 ,
struct V_27 * V_28 , T_3 V_290 )
{
int V_30 , V_29 = - V_204 ;
if ( ! V_28 -> V_291 )
return V_29 ;
F_177 ( & V_28 -> V_47 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_148 ; V_30 ++ ) {
if ( V_28 -> V_291 [ V_30 ] == V_290 ) {
V_29 = 0 ;
break;
}
}
F_178 ( & V_28 -> V_47 ) ;
return V_29 ;
}
static int F_179 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
int V_29 = 0 ;
F_177 ( & V_28 -> V_47 ) ;
if ( V_28 -> V_343 >= V_20 -> V_148 )
V_29 = - V_204 ;
F_178 ( & V_28 -> V_47 ) ;
return V_29 ;
}
static int F_180 ( struct V_5 * V_6 ,
T_3 V_344 , T_2 V_269 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
bool V_345 ;
T_2 V_346 = 0 ;
int V_30 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
V_345 = F_134 ( V_28 ) ;
if ( V_20 -> V_56 != V_57 )
return - V_204 ;
if ( V_269 ) {
if ( F_181 ( V_6 ) && V_345 )
return - V_204 ;
if ( F_179 ( V_20 , V_28 ) )
return - V_204 ;
if ( V_20 -> V_147 ) {
for ( V_30 = 0 ; V_30 < V_20 -> V_148 ; V_30 ++ ) {
if ( V_20 -> V_146 [ V_30 ] == V_344 )
V_346 = 1 ;
}
if ( ! V_346 )
return - V_204 ;
}
} else {
if ( ! V_345 || F_176 ( V_20 , V_28 , V_344 ) )
return - V_204 ;
}
return 0 ;
}
static void F_182 ( struct V_27 * V_28 , T_3 V_290 ,
enum V_347 V_273 )
{
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_19 * V_20 ;
V_20 = V_6 -> V_34 -> V_20 ;
if ( ! V_28 -> V_291 )
return;
F_177 ( & V_28 -> V_47 ) ;
switch ( V_273 ) {
case V_348 :
F_183 ( V_20 , V_28 , V_290 ) ;
break;
case V_349 :
F_184 ( V_20 , V_28 , V_290 ) ;
break;
default:
F_185 ( V_6 -> V_174 , L_47 ) ;
}
F_178 ( & V_28 -> V_47 ) ;
return;
}
int F_186 ( struct V_5 * V_6 ,
T_3 V_344 , T_2 V_269 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_287 * V_174 = V_6 -> V_174 ;
struct V_27 * V_28 ;
struct V_68 V_69 ;
int V_149 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_344 == 0 )
return 0 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
V_149 = F_180 ( V_6 , V_344 , V_269 ) ;
if ( V_149 )
return V_149 ;
V_149 = F_55 ( & V_69 ,
V_350 ) ;
if ( V_149 )
return V_149 ;
V_69 . V_73 . V_74 [ 1 ] = ( V_269 & 1 ) | V_344 << 16 ;
F_33 ( & V_20 -> V_22 ) ;
V_149 = F_48 ( V_6 , & V_69 ) ;
if ( V_149 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_48 , V_149 ) ;
} else {
F_187 ( V_174 ) ;
F_188 ( V_6 ) ;
F_189 ( V_174 ) ;
if ( V_269 )
F_182 ( V_28 , V_344 , V_348 ) ;
else
F_182 ( V_28 , V_344 , V_349 ) ;
F_187 ( V_174 ) ;
F_190 ( V_174 ) ;
F_189 ( V_174 ) ;
}
F_29 ( & V_69 ) ;
return V_149 ;
}
static void F_191 ( struct V_5 * V_6 )
{
struct V_263 * V_292 = & V_6 -> V_351 ;
struct V_352 * V_353 ;
while ( ! F_26 ( V_292 ) ) {
V_353 = F_117 ( V_292 -> V_295 , struct V_352 , V_71 ) ;
F_192 ( V_6 , V_353 -> V_354 , V_353 -> V_290 ,
V_355 ) ;
F_28 ( & V_353 -> V_71 ) ;
F_23 ( V_353 ) ;
}
}
static int F_193 ( struct V_8 * V_10 )
{
struct V_5 * V_6 = F_194 ( V_10 ) ;
struct V_287 * V_174 = V_6 -> V_174 ;
int V_356 ;
F_161 ( V_174 ) ;
F_195 ( V_6 ) ;
if ( F_156 ( V_174 ) )
F_164 ( V_6 , V_174 ) ;
F_36 ( V_6 , V_78 ) ;
F_37 ( V_6 , 0 ) ;
F_163 ( V_6 ) ;
F_175 ( & V_6 -> V_189 ) ;
V_356 = F_196 ( V_10 ) ;
if ( V_356 )
return V_356 ;
return 0 ;
}
static int F_197 ( struct V_5 * V_6 )
{
struct V_329 * V_177 = & V_6 -> V_34 -> V_177 ;
struct V_287 * V_174 = V_6 -> V_174 ;
int V_29 ;
F_74 ( V_183 , & V_177 -> V_118 ) ;
F_154 ( V_6 ) ;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_6 , V_171 ) ;
if ( ! V_29 ) {
if ( F_156 ( V_174 ) ) {
V_29 = F_157 ( V_6 , V_174 ) ;
if ( ! V_29 )
F_158 ( V_174 , V_321 ) ;
}
}
F_159 ( V_174 ) ;
F_67 ( V_6 , V_176 ,
V_177 -> V_178 ) ;
return V_29 ;
}
void F_53 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_18 ; V_30 ++ ) {
V_28 = & V_20 -> V_35 [ V_30 ] ;
V_28 -> V_291 = F_85 ( V_20 -> V_148 ,
sizeof( * V_28 -> V_291 ) , V_32 ) ;
}
}
void F_40 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_18 ; V_30 ++ ) {
V_28 = & V_20 -> V_35 [ V_30 ] ;
F_23 ( V_28 -> V_291 ) ;
V_28 -> V_291 = NULL ;
}
}
void F_183 ( struct V_19 * V_20 ,
struct V_27 * V_28 , T_3 V_290 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_148 ; V_30 ++ ) {
if ( ! V_28 -> V_291 [ V_30 ] ) {
V_28 -> V_291 [ V_30 ] = V_290 ;
V_28 -> V_343 ++ ;
return;
}
}
}
void F_184 ( struct V_19 * V_20 ,
struct V_27 * V_28 , T_3 V_290 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_148 ; V_30 ++ ) {
if ( V_28 -> V_291 [ V_30 ] == V_290 ) {
V_28 -> V_291 [ V_30 ] = 0 ;
V_28 -> V_343 -- ;
return;
}
}
}
bool F_134 ( struct V_27 * V_28 )
{
bool V_29 = false ;
F_177 ( & V_28 -> V_47 ) ;
if ( V_28 -> V_343 )
V_29 = true ;
F_178 ( & V_28 -> V_47 ) ;
return V_29 ;
}
