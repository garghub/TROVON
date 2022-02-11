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
for ( V_30 = 0 ; V_30 < V_18 ; V_30 ++ ) {
V_28 = & V_20 -> V_35 [ V_30 ] ;
V_28 -> V_6 = V_6 ;
V_28 -> V_42 = F_5 ( V_6 , V_30 ) ;
F_15 ( & V_28 -> V_43 ) ;
F_16 ( & V_28 -> V_44 ) ;
F_14 ( & V_28 -> V_45 . V_46 ) ;
F_14 ( & V_28 -> V_47 . V_46 ) ;
F_16 ( & V_28 -> V_45 . V_48 ) ;
F_16 ( & V_28 -> V_47 . V_48 ) ;
F_17 ( & V_28 -> V_49 ) ;
F_18 ( & V_28 -> V_50 , V_51 ) ;
if ( F_19 ( V_6 ) ) {
V_26 = F_11 ( sizeof( struct V_25 ) , V_32 ) ;
if ( ! V_26 ) {
V_29 = - V_33 ;
goto V_52;
}
V_20 -> V_35 [ V_30 ] . V_26 = V_26 ;
V_26 -> V_53 = V_54 ;
V_26 -> V_55 = V_56 ;
V_26 -> V_57 = V_58 ;
V_26 -> V_59 = false ;
F_20 ( V_26 -> V_60 ) ;
F_21 ( & V_6 -> V_10 -> V_9 ,
L_5 ,
V_26 -> V_60 , V_30 ) ;
}
}
return 0 ;
V_52:
F_22 ( V_22 -> V_40 ) ;
V_39:
F_22 ( V_22 -> V_38 ) ;
V_37:
F_23 ( V_20 -> V_35 ) ;
V_36:
F_23 ( V_6 -> V_34 -> V_20 ) ;
return V_29 ;
}
void F_24 ( struct V_61 * V_62 )
{
struct V_63 * V_64 ;
struct V_65 V_66 ;
unsigned long V_67 ;
F_25 ( & V_62 -> V_48 , V_67 ) ;
while ( ! F_26 ( & V_62 -> V_46 ) ) {
V_64 = F_27 ( & V_62 -> V_46 ,
struct V_63 , V_68 ) ;
F_28 ( & V_64 -> V_68 ) ;
V_62 -> V_69 -- ;
V_66 . V_70 . V_71 = ( T_1 * ) V_64 -> V_72 ;
V_66 . V_73 . V_71 = ( T_1 * ) V_64 -> V_74 ;
F_29 ( & V_66 ) ;
F_30 ( V_64 ) ;
}
F_31 ( & V_62 -> V_48 , V_67 ) ;
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
F_24 ( & V_28 -> V_47 ) ;
F_34 ( & V_28 -> V_50 ) ;
F_24 ( & V_28 -> V_45 ) ;
}
F_22 ( V_22 -> V_38 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_18 ; V_30 ++ )
F_23 ( V_20 -> V_35 [ V_30 ] . V_26 ) ;
F_23 ( V_20 -> V_35 ) ;
F_23 ( V_6 -> V_34 -> V_20 ) ;
}
static void F_35 ( struct V_5 * V_6 )
{
F_36 ( V_6 , V_75 ) ;
F_37 ( V_6 , 0 ) ;
F_32 ( V_6 ) ;
}
void F_38 ( struct V_5 * V_6 )
{
if ( ! F_39 ( V_76 , & V_6 -> V_77 ) )
return;
F_40 ( V_6 ) ;
if ( F_19 ( V_6 ) )
F_41 ( V_6 ) ;
if ( F_6 ( V_6 ) )
F_35 ( V_6 ) ;
}
static int F_42 ( struct V_5 * V_6 , T_1 * V_78 ,
T_1 * V_79 , T_2 V_42 , T_2 V_80 )
{
struct V_81 * V_34 = V_6 -> V_34 ;
struct V_82 * V_83 = V_34 -> V_84 ;
struct V_65 V_66 ;
unsigned long V_85 ;
int V_29 ;
memset ( & V_66 , 0 , sizeof( struct V_65 ) ) ;
V_66 . V_78 = V_78 ;
V_66 . V_79 = V_79 ;
V_66 . V_86 = V_80 ;
V_66 . V_87 = V_42 ;
V_66 . V_88 = V_89 ;
V_66 . V_90 = ( (struct V_91 * ) V_78 ) -> V_90 ;
V_29 = V_83 -> V_92 -> V_93 ( V_6 , & V_66 , & V_85 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_6 ,
V_94 , V_66 . V_90 , V_66 . type , V_34 -> V_42 ,
V_34 -> V_95 ) ;
return V_29 ;
}
if ( ! F_43 ( & V_66 . V_96 , V_85 ) ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_7 ,
V_94 , V_66 . V_90 , V_66 . type , V_34 -> V_42 ,
V_34 -> V_95 ) ;
F_44 ( V_83 -> V_97 ) ;
}
return V_66 . V_98 ;
}
static void F_45 ( struct V_5 * V_6 )
{
V_6 -> V_99 = V_100 ;
V_6 -> V_101 = V_102 ;
V_6 -> V_103 = V_104 ;
V_6 -> V_105 = V_106 ;
V_6 -> V_107 = V_108 ;
V_6 -> V_109 = V_110 ;
}
int F_46 ( struct V_5 * V_6 ,
struct V_111 * V_112 , T_3 V_113 )
{
struct V_114 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_65 V_66 ;
int V_29 ;
T_1 V_115 ;
V_29 = F_47 ( & V_66 , V_6 , V_116 ) ;
if ( V_29 )
return V_29 ;
V_66 . V_70 . V_71 [ 1 ] = V_113 << 16 | 0x1 ;
V_29 = F_48 ( V_6 , & V_66 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_8 , V_29 ) ;
F_29 ( & V_66 ) ;
return V_29 ;
}
V_115 = V_66 . V_73 . V_71 [ 2 ] & 0xffff ;
if ( V_115 & V_117 )
V_112 -> V_57 = F_49 ( V_66 . V_73 . V_71 [ 2 ] ) ;
if ( V_115 & V_118 )
V_112 -> V_55 = F_50 ( V_66 . V_73 . V_71 [ 3 ] ) ;
if ( V_115 & V_119 )
V_112 -> V_120 = F_49 ( V_66 . V_73 . V_71 [ 3 ] ) ;
if ( V_115 & V_121 )
V_112 -> V_122 = F_50 ( V_66 . V_73 . V_71 [ 4 ] ) ;
if ( V_115 & V_123 )
V_112 -> V_124 = F_49 ( V_66 . V_73 . V_71 [ 4 ] ) ;
if ( V_115 & V_125 )
V_112 -> V_126 = F_50 ( V_66 . V_73 . V_71 [ 5 ] ) ;
if ( V_115 & V_127 )
V_112 -> V_128 = F_49 ( V_66 . V_73 . V_71 [ 5 ] ) ;
if ( V_115 & V_129 )
V_112 -> V_130 = F_50 ( V_66 . V_73 . V_71 [ 6 ] ) ;
if ( V_115 & V_131 )
V_112 -> V_132 = F_49 ( V_66 . V_73 . V_71 [ 6 ] ) ;
if ( V_115 & V_133 )
V_112 -> V_134 = F_50 ( V_66 . V_73 . V_71 [ 7 ] ) ;
V_112 -> V_135 = F_49 ( V_66 . V_73 . V_71 [ 7 ] ) ;
V_112 -> V_136 = F_50 ( V_66 . V_73 . V_71 [ 8 ] ) ;
V_112 -> V_137 = F_49 ( V_66 . V_73 . V_71 [ 8 ] ) ;
V_112 -> V_138 = F_50 ( V_66 . V_73 . V_71 [ 9 ] ) ;
F_21 ( V_9 , L_9
L_10
L_11
L_12
L_13
L_14 ,
V_112 -> V_57 , V_112 -> V_55 ,
V_112 -> V_120 , V_112 -> V_122 ,
V_112 -> V_124 ,
V_112 -> V_126 , V_112 -> V_128 ,
V_112 -> V_130 , V_112 -> V_132 ,
V_112 -> V_134 , V_112 -> V_135 ,
V_112 -> V_136 , V_112 -> V_137 ,
V_112 -> V_138 ) ;
F_29 ( & V_66 ) ;
return V_29 ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_65 * V_66 )
{
V_6 -> V_139 = F_49 ( V_66 -> V_73 . V_71 [ 1 ] ) & 0xffff ;
V_6 -> V_67 &= ~ V_140 ;
return 0 ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_65 * V_66 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
int V_30 , V_141 ;
T_3 * V_142 ;
if ( V_20 -> V_143 )
return 0 ;
V_20 -> V_144 = V_66 -> V_73 . V_71 [ 2 ] & 0xf ;
V_20 -> V_145 = V_66 -> V_73 . V_71 [ 2 ] >> 16 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_15 ,
V_20 -> V_145 ) ;
F_53 ( V_6 ) ;
if ( ! V_20 -> V_144 )
return 0 ;
V_141 = V_20 -> V_145 ;
V_20 -> V_143 = F_11 ( sizeof( T_3 ) * V_141 , V_32 ) ;
if ( ! V_20 -> V_143 )
return - V_33 ;
V_142 = ( T_3 * ) & V_66 -> V_73 . V_71 [ 3 ] ;
for ( V_30 = 0 ; V_30 < V_141 ; V_30 ++ )
V_20 -> V_143 [ V_30 ] = V_142 [ V_30 ] ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_65 V_66 ;
int V_146 = 0 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_146 = F_55 ( & V_66 , V_147 ) ;
if ( V_146 )
return V_146 ;
V_146 = F_48 ( V_6 , & V_66 ) ;
if ( V_146 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_16 ,
V_146 ) ;
} else {
V_20 -> V_53 = V_66 . V_73 . V_71 [ 1 ] & 0x3 ;
switch ( V_20 -> V_53 ) {
case V_54 :
V_146 = F_52 ( V_6 , & V_66 ) ;
break;
case V_148 :
V_146 = F_51 ( V_6 , & V_66 ) ;
break;
}
}
F_29 ( & V_66 ) ;
return V_146 ;
}
static int F_56 ( struct V_5 * V_6 )
{
struct V_81 * V_34 = V_6 -> V_34 ;
struct V_111 V_149 ;
int V_29 ;
V_29 = F_46 ( V_6 , & V_149 , 0 ) ;
if ( V_29 )
return V_29 ;
V_34 -> V_150 = V_149 . V_124 ;
V_29 = F_57 ( V_6 , & V_149 , V_34 -> V_42 ) ;
if ( V_29 )
return - V_31 ;
if ( F_58 ( V_6 ) )
return - V_31 ;
F_45 ( V_6 ) ;
V_6 -> V_67 |= V_151 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_17 ,
V_6 -> V_34 -> V_152 ) ;
V_34 -> V_153 = ( T_2 ) V_149 . V_154 ;
V_34 -> V_155 = V_149 . V_155 ;
V_34 -> V_156 = V_149 . V_156 ;
V_34 -> V_95 = V_149 . V_95 ;
V_34 -> V_157 = V_149 . V_157 ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 ,
int V_158 )
{
int V_29 ;
V_6 -> V_67 |= V_159 ;
V_6 -> V_34 -> V_160 = 1 ;
F_14 ( & V_6 -> V_161 ) ;
if ( ! V_162 && ! ! V_163 )
F_60 ( & V_6 -> V_10 -> V_9 ,
L_18 ) ;
F_61 ( V_6 , V_164 ) ;
F_62 ( V_6 , V_164 ) ;
V_29 = F_63 ( V_6 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_19 ) ;
goto V_165;
}
V_29 = F_64 ( V_6 ) ;
if ( V_29 )
goto V_165;
V_29 = F_9 ( V_6 , 1 ) ;
if ( V_29 )
goto V_166;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
goto V_167;
V_29 = F_36 ( V_6 , V_168 ) ;
if ( V_29 )
goto V_169;
V_29 = F_56 ( V_6 ) ;
if ( V_29 )
goto V_170;
V_29 = F_54 ( V_6 ) ;
if ( V_29 )
goto V_170;
V_29 = F_65 ( V_6 , V_6 -> V_171 , V_158 ) ;
if ( V_29 )
goto V_170;
F_66 ( V_6 -> V_10 , V_6 ) ;
F_21 ( & V_6 -> V_10 -> V_9 , L_20 ,
V_6 -> V_171 -> V_172 ) ;
F_67 ( V_6 , V_173 ,
V_6 -> V_34 -> V_174 . V_175 ) ;
return 0 ;
V_170:
F_36 ( V_6 , V_75 ) ;
V_169:
F_37 ( V_6 , 0 ) ;
V_167:
F_32 ( V_6 ) ;
V_166:
F_68 ( V_6 ) ;
V_165:
F_69 ( V_6 ) ;
return V_29 ;
}
static int F_70 ( struct V_5 * V_6 )
{
T_1 V_77 ;
do {
F_71 ( 20 ) ;
if ( ++ V_6 -> V_176 > V_177 )
return - V_31 ;
V_77 = F_72 ( V_6 -> V_34 , V_178 ) ;
} while ( V_77 != V_179 );
return 0 ;
}
int F_73 ( struct V_5 * V_6 , int V_158 )
{
struct V_81 * V_34 = V_6 -> V_34 ;
int V_29 ;
F_74 ( V_180 , & V_34 -> V_174 . V_115 ) ;
V_34 -> V_174 . V_175 = V_181 ;
V_34 -> V_182 = 0 ;
V_6 -> V_176 = 0 ;
V_34 -> V_183 = 1 ;
V_6 -> V_184 = 0 ;
V_6 -> V_67 |= V_185 ;
V_29 = F_70 ( V_6 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_59 ( V_6 , V_158 ) ;
if ( V_29 )
return V_29 ;
if ( F_75 ( V_6 ) )
F_60 ( & V_6 -> V_10 -> V_9 , L_21 ) ;
F_76 ( & V_6 -> V_186 , V_187 ) ;
F_77 ( V_188 , & V_6 -> V_77 ) ;
return 0 ;
}
void F_78 ( struct V_5 * V_6 )
{
struct V_81 * V_34 = V_6 -> V_34 ;
V_34 -> V_95 = V_189 ;
F_21 ( & V_6 -> V_10 -> V_9 ,
L_22 ,
V_34 -> V_152 ) ;
V_6 -> V_190 = & V_191 ;
F_74 ( V_76 , & V_6 -> V_77 ) ;
return;
}
void F_79 ( struct V_81 * V_34 )
{
V_34 -> V_192 = & V_193 ;
V_34 -> V_194 = ( T_1 * ) V_195 ;
V_34 -> V_196 = ( T_1 * ) V_197 ;
}
static T_1 F_80 ( T_1 V_198 , T_2 V_199 )
{
T_1 V_86 ;
V_86 = V_198 / ( ( V_199 + 1 ) * V_200 ) ;
if ( V_86 )
V_86 = V_200 ;
else
V_86 = V_198 % V_200 ;
return V_86 ;
}
int F_81 ( struct V_5 * V_6 , T_2 V_42 )
{
struct V_27 * V_35 = V_6 -> V_34 -> V_20 -> V_35 ;
T_2 V_30 ;
if ( F_6 ( V_6 ) )
return 0 ;
for ( V_30 = 0 ; V_30 < V_6 -> V_34 -> V_20 -> V_18 ; V_30 ++ ) {
if ( V_35 [ V_30 ] . V_42 == V_42 )
return V_30 ;
}
return - V_201 ;
}
static inline int F_82 ( struct V_63 * * V_64 )
{
* V_64 = F_11 ( sizeof( struct V_63 ) , V_202 ) ;
if ( ! * V_64 )
return - V_33 ;
F_17 ( & ( * V_64 ) -> V_203 ) ;
return 0 ;
}
static inline int F_83 ( struct V_91 * * V_78 ,
T_1 V_80 )
{
* V_78 = F_11 ( sizeof( struct V_91 ) * V_80 , V_202 ) ;
if ( ! * V_78 )
return - V_33 ;
return 0 ;
}
static int F_55 ( struct V_65 * V_83 , T_1 type )
{
const struct V_204 * V_205 ;
int V_30 , V_80 ;
V_205 = V_206 ;
V_80 = F_84 ( V_206 ) ;
for ( V_30 = 0 ; V_30 < V_80 ; V_30 ++ ) {
if ( type == V_205 [ V_30 ] . V_66 ) {
V_83 -> V_88 = V_207 ;
V_83 -> V_70 . V_208 = V_205 [ V_30 ] . V_209 ;
V_83 -> V_73 . V_208 = V_205 [ V_30 ] . V_210 ;
V_83 -> V_70 . V_71 = F_85 ( V_83 -> V_70 . V_208 , sizeof( T_1 ) ,
V_202 ) ;
if ( ! V_83 -> V_70 . V_71 )
return - V_33 ;
V_83 -> V_73 . V_71 = F_85 ( V_83 -> V_73 . V_208 , sizeof( T_1 ) ,
V_202 ) ;
if ( ! V_83 -> V_73 . V_71 ) {
F_23 ( V_83 -> V_70 . V_71 ) ;
V_83 -> V_70 . V_71 = NULL ;
return - V_33 ;
}
memset ( V_83 -> V_70 . V_71 , 0 , sizeof( T_1 ) * V_83 -> V_70 . V_208 ) ;
memset ( V_83 -> V_73 . V_71 , 0 , sizeof( T_1 ) * V_83 -> V_73 . V_208 ) ;
V_83 -> V_70 . V_71 [ 0 ] = ( type | ( V_83 -> V_70 . V_208 << 16 ) |
( 3 << 29 ) ) ;
V_83 -> V_73 . V_71 [ 0 ] = ( type & 0xffff ) | V_83 -> V_73 . V_208 << 16 ;
return 0 ;
}
}
return - V_201 ;
}
static int F_86 ( struct V_63 * V_64 ,
struct V_65 * V_66 ,
T_3 V_211 , T_2 V_212 )
{
struct V_91 * V_78 ;
int V_30 ;
T_1 V_213 , V_214 ;
T_3 V_215 ;
T_2 V_90 , V_216 , V_217 ;
V_214 = V_200 ;
if ( V_212 == V_218 ) {
V_64 -> V_72 = (struct V_219 * ) V_66 -> V_70 . V_71 ;
V_64 -> V_74 = (struct V_219 * ) V_66 -> V_73 . V_71 ;
V_213 = V_66 -> V_70 . V_208 ;
V_64 -> V_220 = ( V_213 * 4 ) ;
V_213 = V_66 -> V_73 . V_208 ;
V_64 -> V_221 = ( V_213 * 4 ) ;
V_90 = V_66 -> V_70 . V_71 [ 0 ] & 0xff ;
V_215 = ( V_64 -> V_220 ) % ( V_214 ) ;
V_216 = ( V_64 -> V_220 ) / ( V_214 ) ;
if ( V_215 )
V_216 ++ ;
V_217 = V_216 ;
if ( F_83 ( & V_64 -> V_222 , V_216 ) )
return - V_33 ;
V_215 = ( V_64 -> V_221 ) % ( V_214 ) ;
V_216 = ( V_64 -> V_221 ) / ( V_214 ) ;
if ( V_215 )
V_216 ++ ;
if ( F_83 ( & V_64 -> V_223 , V_216 ) )
return - V_33 ;
V_216 = V_217 ;
V_78 = V_64 -> V_222 ;
} else {
V_66 -> V_70 . V_71 = ( T_1 * ) V_64 -> V_72 ;
V_66 -> V_73 . V_71 = ( T_1 * ) V_64 -> V_74 ;
V_90 = V_66 -> V_70 . V_71 [ 0 ] & 0xff ;
V_66 -> V_90 = V_90 ;
V_215 = ( V_64 -> V_221 ) % ( V_214 ) ;
V_216 = ( V_64 -> V_221 ) / ( V_214 ) ;
if ( V_215 )
V_216 ++ ;
V_66 -> V_70 . V_208 = V_64 -> V_220 / 4 ;
V_66 -> V_73 . V_208 = V_64 -> V_221 / 4 ;
V_78 = V_64 -> V_223 ;
V_66 -> V_88 = V_64 -> V_222 -> V_88 ;
}
V_64 -> V_224 = V_211 ;
V_64 -> V_225 = V_90 ;
for ( V_30 = 0 ; V_30 < V_216 ; V_30 ++ ) {
V_78 [ V_30 ] . V_226 = 2 ;
V_78 [ V_30 ] . V_212 = V_212 ;
V_78 [ V_30 ] . V_88 = V_66 -> V_88 ;
V_78 [ V_30 ] . V_227 = 1 ;
V_78 [ V_30 ] . V_216 = V_216 ;
V_78 [ V_30 ] . V_228 = V_30 + 1 ;
V_78 [ V_30 ] . V_90 = V_90 ;
V_78 [ V_30 ] . V_229 = V_211 ;
}
return 0 ;
}
static void F_30 ( struct V_63 * V_64 )
{
if ( ! V_64 )
return;
F_23 ( V_64 -> V_222 ) ;
F_23 ( V_64 -> V_223 ) ;
F_23 ( V_64 ) ;
}
static int F_87 ( struct V_27 * V_28 ,
struct V_63 * V_64 , T_2 type )
{
struct V_61 * V_62 ;
unsigned long V_67 ;
int V_146 = 0 ;
if ( type == V_230 ) {
V_62 = & V_28 -> V_45 ;
F_25 ( & V_62 -> V_48 , V_67 ) ;
V_62 -> V_69 -- ;
F_28 ( & V_64 -> V_68 ) ;
if ( V_62 -> V_69 > 0 )
V_146 = 1 ;
F_31 ( & V_62 -> V_48 , V_67 ) ;
}
if ( type == V_218 ) {
while ( F_88 ( V_231 , & V_28 -> V_77 ) )
F_71 ( 100 ) ;
V_28 -> V_232 = NULL ;
F_77 ( V_231 , & V_28 -> V_77 ) ;
}
return V_146 ;
}
static void F_89 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
T_4 V_233 )
{
if ( F_39 ( V_234 , & V_28 -> V_77 ) ||
V_28 -> V_6 -> V_184 )
return;
F_90 ( V_20 -> V_22 . V_38 , & V_28 -> V_50 ) ;
}
static inline void F_91 ( struct V_63 * V_64 )
{
struct V_96 * V_235 = & V_64 -> V_203 ;
if ( F_43 ( V_235 , V_236 ) )
V_64 -> V_237 = V_238 ;
else
V_64 -> V_237 = V_239 ;
return;
}
static void F_92 ( struct V_63 * V_64 ,
T_2 type )
{
if ( type == V_230 ) {
V_64 -> V_240 ++ ;
if ( V_64 -> V_240 < V_64 -> V_223 -> V_216 )
V_64 -> V_237 = V_241 ;
else
V_64 -> V_237 = V_238 ;
} else {
V_64 -> V_242 ++ ;
if ( V_64 -> V_242 < V_64 -> V_222 -> V_216 )
V_64 -> V_237 = V_241 ;
else
V_64 -> V_237 = V_243 ;
}
}
static void F_93 ( struct V_63 * V_64 ,
T_2 type )
{
struct V_27 * V_28 = V_64 -> V_28 ;
struct V_96 * V_235 = & V_28 -> V_49 ;
if ( ! F_43 ( V_235 , V_244 ) ) {
V_64 -> V_237 = V_239 ;
return;
}
F_77 ( V_245 , & V_28 -> V_77 ) ;
F_92 ( V_64 , type ) ;
}
static void F_94 ( struct V_5 * V_6 ,
T_1 * V_78 , T_1 * V_79 , T_1 V_80 )
{
struct V_81 * V_34 = V_6 -> V_34 ;
T_1 V_246 ;
T_2 V_30 , V_247 = 2 , V_248 , V_249 ;
V_248 = ( sizeof( struct V_91 ) / sizeof( T_1 ) ) ;
V_247 = ( V_80 / sizeof( T_1 ) ) + V_248 ;
V_246 = F_95 ( F_96 ( V_34 , 0 ) ) ;
for ( V_30 = 2 , V_249 = 0 ; V_249 < V_248 ; V_30 ++ , V_249 ++ )
* ( V_78 ++ ) = F_95 ( F_96 ( V_34 , V_30 ) ) ;
for (; V_249 < V_247 ; V_30 ++ , V_249 ++ )
* ( V_79 ++ ) = F_95 ( F_96 ( V_34 , V_30 ) ) ;
}
static int F_97 ( struct V_27 * V_28 )
{
int V_146 = - V_250 ;
T_1 V_85 = 10000 ;
do {
if ( ! F_88 ( V_245 , & V_28 -> V_77 ) ) {
V_146 = 0 ;
break;
}
F_98 ( 1 ) ;
} while ( -- V_85 );
return V_146 ;
}
static int F_99 ( struct V_63 * V_64 , T_2 type )
{
struct V_27 * V_28 = V_64 -> V_28 ;
T_1 V_86 , V_248 ;
T_1 * V_78 , * V_79 ;
int V_146 ;
T_2 V_42 = V_64 -> V_251 ;
if ( F_97 ( V_28 ) )
return - V_250 ;
if ( type == V_218 ) {
V_78 = ( T_1 * ) ( V_64 -> V_222 + V_64 -> V_242 ) ;
V_79 = ( T_1 * ) ( V_64 -> V_72 + V_64 -> V_242 ) ;
V_248 = ( sizeof( struct V_91 ) / sizeof( T_1 ) ) ;
V_86 = F_80 ( V_64 -> V_220 ,
V_64 -> V_242 ) ;
V_86 = ( V_86 / sizeof( T_1 ) ) ;
} else {
V_78 = ( T_1 * ) ( V_64 -> V_223 + V_64 -> V_240 ) ;
V_79 = ( T_1 * ) ( V_64 -> V_74 + V_64 -> V_240 ) ;
V_248 = ( sizeof( struct V_91 ) / sizeof( T_1 ) ) ;
V_86 = F_80 ( V_64 -> V_221 ,
V_64 -> V_240 ) ;
V_86 = ( V_86 / sizeof( T_1 ) ) ;
}
V_146 = F_42 ( V_28 -> V_6 , V_78 , V_79 ,
V_42 , V_86 ) ;
return V_146 ;
}
static int F_100 ( struct V_63 * V_64 ,
struct V_27 * V_28 , T_2 type )
{
bool V_252 = true ;
int V_29 = - V_31 ;
while ( V_252 ) {
if ( F_39 ( V_234 , & V_28 -> V_77 ) ||
V_28 -> V_6 -> V_184 )
V_64 -> V_237 = V_239 ;
switch ( V_64 -> V_237 ) {
case V_241 :
V_64 -> V_237 = V_253 ;
if ( F_99 ( V_64 , type ) )
V_64 -> V_237 = V_239 ;
break;
case V_253 :
F_93 ( V_64 , type ) ;
break;
case V_243 :
F_91 ( V_64 ) ;
break;
case V_238 :
V_29 = 0 ;
V_252 = false ;
break;
case V_239 :
V_29 = - V_31 ;
V_252 = false ;
F_77 ( V_245 , & V_28 -> V_77 ) ;
break;
default:
V_29 = - V_31 ;
V_252 = false ;
}
}
return V_29 ;
}
static int F_101 ( struct V_5 * V_6 ,
struct V_63 * V_64 , int V_42 )
{
struct V_27 * V_28 ;
int V_29 , V_254 = F_81 ( V_6 , V_42 ) ;
if ( V_254 < 0 )
return - V_31 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ V_254 ] ;
V_64 -> V_28 = V_28 ;
V_64 -> V_251 = V_42 ;
if ( ! F_39 ( V_255 , & V_28 -> V_77 ) ) {
if ( F_19 ( V_6 ) )
return - V_31 ;
if ( F_6 ( V_6 ) &&
V_64 -> V_225 != V_168 )
return - V_31 ;
}
F_102 ( & V_28 -> V_43 ) ;
V_28 -> V_232 = V_64 ;
V_29 = F_100 ( V_64 , V_28 , V_218 ) ;
F_87 ( V_28 , V_64 , V_218 ) ;
F_103 ( & V_28 -> V_43 ) ;
return V_29 ;
}
static void F_104 ( struct V_5 * V_6 ,
struct V_63 * V_64 ,
struct V_65 * V_66 )
{
#ifdef F_105
if ( F_19 ( V_6 ) ) {
F_106 ( V_6 , V_64 , V_66 ) ;
return;
}
#endif
V_66 -> V_73 . V_71 [ 0 ] |= ( 0x9 << 25 ) ;
return;
}
static void V_51 ( struct V_256 * V_257 )
{
struct V_27 * V_28 = F_107 ( V_257 , struct V_27 ,
V_50 ) ;
struct V_63 * V_64 = NULL ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_65 V_66 ;
T_2 V_70 ;
if ( V_6 -> V_184 )
return;
if ( F_39 ( V_234 , & V_28 -> V_77 ) )
return;
memset ( & V_66 , 0 , sizeof( struct V_65 ) ) ;
V_64 = F_27 ( & V_28 -> V_45 . V_46 ,
struct V_63 , V_68 ) ;
V_6 = V_28 -> V_6 ;
if ( F_86 ( V_64 , & V_66 , V_64 -> V_222 -> V_229 ,
V_230 ) )
goto V_258;
F_104 ( V_6 , V_64 , & V_66 ) ;
V_64 -> V_237 = V_241 ;
F_100 ( V_64 , V_28 , V_230 ) ;
V_258:
F_29 ( & V_66 ) ;
V_70 = F_87 ( V_28 , V_64 , V_230 ) ;
F_30 ( V_64 ) ;
if ( V_70 )
F_89 ( V_6 -> V_34 -> V_20 , V_28 ,
V_51 ) ;
}
static void F_108 ( struct V_91 * V_78 ,
struct V_27 * V_28 )
{
struct V_63 * V_64 ;
T_1 V_86 ;
if ( F_88 ( V_231 , & V_28 -> V_77 ) )
return;
V_64 = V_28 -> V_232 ;
if ( V_64 == NULL )
goto V_259;
if ( V_64 -> V_224 != V_78 -> V_229 )
goto V_259;
V_86 = F_80 ( V_64 -> V_221 ,
V_64 -> V_240 ) ;
F_94 ( V_28 -> V_6 ,
( T_1 * ) ( V_64 -> V_223 + V_64 -> V_240 ) ,
( T_1 * ) ( V_64 -> V_74 + V_64 -> V_240 ) ,
V_86 ) ;
if ( ++ V_64 -> V_240 < V_64 -> V_223 -> V_216 )
goto V_259;
F_109 ( & V_64 -> V_203 ) ;
V_259:
F_77 ( V_231 , & V_28 -> V_77 ) ;
}
int F_110 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_63 * V_64 )
{
struct V_61 * V_62 = & V_28 -> V_45 ;
V_62 -> V_69 ++ ;
F_111 ( & V_64 -> V_68 , & V_62 -> V_46 ) ;
if ( V_62 -> V_69 == 1 )
F_89 ( V_20 , V_28 ,
V_51 ) ;
return 0 ;
}
static int F_112 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_63 * V_64 )
{
struct V_61 * V_62 = & V_28 -> V_45 ;
F_113 ( & V_62 -> V_48 ) ;
F_110 ( V_20 , V_28 , V_64 ) ;
F_114 ( & V_62 -> V_48 ) ;
return 0 ;
}
static void F_115 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_91 * V_78 )
{
struct V_63 * V_64 = NULL ;
struct V_260 * V_261 ;
T_1 V_86 , V_199 ;
T_2 V_262 = 0 , V_263 = 0 ;
F_113 ( & V_28 -> V_47 . V_48 ) ;
if ( V_28 -> V_47 . V_69 > 0 ) {
F_116 (node, &vf->rcv_pend.wait_list) {
V_64 = F_117 ( V_261 , struct V_63 , V_68 ) ;
if ( V_64 -> V_224 == V_78 -> V_229 ) {
V_262 = 1 ;
break;
}
}
}
if ( V_262 ) {
V_199 = V_64 -> V_242 ;
V_86 = F_80 ( V_64 -> V_220 ,
V_199 ) ;
F_94 ( V_28 -> V_6 ,
( T_1 * ) ( V_64 -> V_222 + V_199 ) ,
( T_1 * ) ( V_64 -> V_72 + V_199 ) ,
V_86 ) ;
V_64 -> V_242 ++ ;
if ( V_64 -> V_242 >= V_78 -> V_216 ) {
V_28 -> V_47 . V_69 -- ;
F_28 ( & V_64 -> V_68 ) ;
V_263 = 1 ;
}
}
F_114 ( & V_28 -> V_47 . V_48 ) ;
if ( V_263 )
if ( F_112 ( V_20 , V_28 , V_64 ) )
F_30 ( V_64 ) ;
return;
}
static void F_118 ( struct V_19 * V_20 ,
struct V_91 * V_78 ,
struct V_27 * V_28 )
{
struct V_63 * V_64 ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_65 V_66 ;
T_1 V_86 ;
int V_29 ;
T_2 V_90 ;
if ( V_6 -> V_184 )
return;
if ( ! F_39 ( V_255 , & V_28 -> V_77 ) &&
V_78 -> V_88 != V_207 &&
V_78 -> V_90 != V_168 )
return;
if ( V_78 -> V_228 > 1 ) {
F_115 ( V_20 , V_28 , V_78 ) ;
return;
}
memset ( & V_66 , 0 , sizeof( struct V_65 ) ) ;
V_90 = V_78 -> V_90 ;
if ( F_82 ( & V_64 ) )
return;
if ( V_78 -> V_88 == V_207 )
V_29 = F_55 ( & V_66 , V_90 ) ;
else
V_29 = F_47 ( & V_66 , V_6 , V_90 ) ;
if ( V_29 ) {
F_30 ( V_64 ) ;
return;
}
V_66 . V_88 = V_78 -> V_88 ;
if ( F_86 ( V_64 , & V_66 , V_78 -> V_229 ,
V_218 ) ) {
F_29 ( & V_66 ) ;
F_30 ( V_64 ) ;
return;
}
V_86 = F_80 ( V_64 -> V_220 ,
V_64 -> V_242 ) ;
F_94 ( V_28 -> V_6 ,
( T_1 * ) ( V_64 -> V_222 + V_64 -> V_242 ) ,
( T_1 * ) ( V_64 -> V_72 + V_64 -> V_242 ) ,
V_86 ) ;
V_64 -> V_251 = V_28 -> V_42 ;
V_64 -> V_28 = V_28 ;
V_64 -> V_224 = V_78 -> V_229 ;
V_64 -> V_242 ++ ;
if ( F_119 ( V_6 , V_64 , V_28 ) )
return;
if ( V_64 -> V_242 == V_64 -> V_222 -> V_216 ) {
if ( F_112 ( V_20 , V_28 , V_64 ) ) {
F_29 ( & V_66 ) ;
F_30 ( V_64 ) ;
}
} else {
F_113 ( & V_28 -> V_47 . V_48 ) ;
F_111 ( & V_64 -> V_68 , & V_28 -> V_47 . V_46 ) ;
V_28 -> V_47 . V_69 ++ ;
F_114 ( & V_28 -> V_47 . V_48 ) ;
}
}
static void F_120 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
struct V_91 V_78 ;
T_1 * V_264 = ( T_1 * ) & V_78 ;
T_2 V_212 , V_30 ;
for ( V_30 = 2 ; V_30 < 6 ; V_30 ++ )
V_264 [ V_30 - 2 ] = F_95 ( F_96 ( V_28 -> V_6 -> V_34 , V_30 ) ) ;
V_212 = V_78 . V_212 ;
switch ( V_212 ) {
case V_218 :
F_118 ( V_20 , & V_78 , V_28 ) ;
break;
case V_230 :
F_108 ( & V_78 , V_28 ) ;
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
void F_123 ( struct V_5 * V_6 , T_1 V_265 )
{
struct V_27 * V_28 ;
struct V_19 * V_20 ;
int V_254 ;
T_2 V_42 ;
V_20 = V_6 -> V_34 -> V_20 ;
V_42 = F_4 ( V_265 ) ;
V_254 = F_81 ( V_6 , V_42 ) ;
if ( V_254 < 0 )
return;
V_28 = & V_20 -> V_35 [ V_254 ] ;
V_28 -> V_42 = V_42 ;
if ( F_2 ( V_265 ) )
F_109 ( & V_28 -> V_49 ) ;
if ( F_3 ( V_265 ) ) {
F_121 ( V_20 , V_28 ) ;
return;
}
if ( F_1 ( V_265 ) )
F_120 ( V_20 , V_28 ) ;
}
int F_37 ( struct V_5 * V_6 , T_2 V_266 )
{
struct V_65 V_66 ;
int V_29 ;
if ( ! F_39 ( V_76 , & V_6 -> V_77 ) )
return 0 ;
if ( F_47 ( & V_66 , V_6 , V_267 ) )
return - V_33 ;
if ( V_266 )
V_66 . V_70 . V_71 [ 1 ] = ( 1 << 4 ) | ( 1 << 5 ) | ( 1 << 6 ) | ( 1 << 7 ) ;
V_29 = F_124 ( V_6 , & V_66 ) ;
if ( V_29 != V_268 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_24 ,
( V_266 ? L_25 : L_26 ) , V_29 ) ;
}
F_29 ( & V_66 ) ;
return V_29 ;
}
static int F_125 ( struct V_5 * V_6 ,
struct V_63 * V_64 )
{
T_2 V_247 = V_177 ;
T_1 V_77 ;
V_77 = F_72 ( V_6 -> V_34 , V_178 ) ;
if ( V_77 == V_179 ) {
F_71 ( 20 ) ;
F_77 ( V_245 , & V_64 -> V_28 -> V_77 ) ;
V_64 -> V_237 = V_241 ;
if ( ++ V_6 -> V_176 > V_247 )
return - V_31 ;
else
return 0 ;
}
return - V_31 ;
}
static int F_126 ( struct V_5 * V_6 ,
struct V_65 * V_66 )
{
struct V_81 * V_34 = V_6 -> V_34 ;
struct V_82 * V_83 = V_34 -> V_84 ;
struct V_114 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_63 * V_64 ;
int V_29 ;
T_1 V_269 , V_270 , V_271 , V_73 ;
T_3 V_211 = ++ V_6 -> V_34 -> V_20 -> V_22 . V_272 ;
T_2 V_233 = V_34 -> V_42 ;
V_73 = F_82 ( & V_64 ) ;
if ( V_73 )
goto V_273;
V_73 = F_86 ( V_64 , V_66 , V_211 , V_218 ) ;
if ( V_73 )
goto V_274;
V_275:
if ( ! F_39 ( V_276 , & V_83 -> V_115 ) ) {
V_73 = - V_31 ;
F_127 ( V_6 , V_277 , L_27 ,
F_128 ( V_66 -> V_70 . V_71 [ 0 ] ) , V_233 ) ;
goto V_278;
}
V_29 = F_101 ( V_6 , V_64 , V_233 ) ;
if ( V_29 ) {
F_13 ( V_9 , L_28 ,
( V_66 -> V_70 . V_71 [ 0 ] & 0xffff ) , V_233 ) ;
V_73 = V_279 ;
if ( ( V_64 -> V_222 -> V_90 == V_168 ) &&
! F_125 ( V_6 , V_64 ) )
goto V_275;
goto V_278;
}
V_269 = V_66 -> V_73 . V_71 [ 0 ] ;
V_271 = F_129 ( V_269 ) ;
V_270 = F_128 ( V_66 -> V_70 . V_71 [ 0 ] ) ;
if ( ( V_271 == V_280 ) ||
( V_271 == V_281 ) ) {
V_73 = V_268 ;
} else {
if ( V_66 -> type == V_282 ) {
V_73 = V_268 ;
} else {
V_73 = V_271 ;
if ( ! V_73 )
V_73 = 1 ;
F_13 ( V_9 ,
L_29 ,
V_270 , V_271 , V_233 ) ;
}
}
V_278:
if ( V_73 == V_279 ) {
V_34 -> V_182 = 1 ;
V_6 -> V_184 = 1 ;
F_77 ( V_276 , & V_83 -> V_115 ) ;
}
V_274:
F_30 ( V_64 ) ;
V_273:
if ( V_66 -> type == V_282 ) {
F_29 ( V_66 ) ;
F_23 ( V_66 ) ;
}
return V_73 ;
}
static int F_130 ( struct V_5 * V_6 ,
struct V_65 * V_66 )
{
if ( V_66 -> type == V_282 )
return F_131 ( V_6 , V_66 ) ;
else
return F_126 ( V_6 , V_66 ) ;
}
static int F_36 ( struct V_5 * V_6 , T_2 V_90 )
{
struct V_65 V_66 ;
struct V_27 * V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
int V_146 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
if ( F_55 ( & V_66 , V_90 ) )
return - V_33 ;
V_146 = F_48 ( V_6 , & V_66 ) ;
if ( V_146 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_30 , V_90 ? L_31 : L_32 ,
V_146 ) ;
goto V_283;
}
V_90 = ( V_66 . V_73 . V_71 [ 0 ] & 0xff ) ;
if ( V_66 . V_73 . V_71 [ 0 ] >> 25 == 2 )
return 2 ;
if ( V_90 == V_168 )
F_74 ( V_255 , & V_28 -> V_77 ) ;
else
F_77 ( V_255 , & V_28 -> V_77 ) ;
V_283:
F_29 ( & V_66 ) ;
return V_146 ;
}
static void F_132 ( struct V_284 * V_171 , const T_2 * V_60 ,
enum V_285 V_286 )
{
struct V_5 * V_6 = F_133 ( V_171 ) ;
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
T_3 V_287 ;
int V_30 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
if ( ! F_134 ( V_28 ) ) {
F_135 ( V_6 , V_60 , 0 , V_286 ) ;
} else {
F_113 ( & V_28 -> V_44 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_145 ; V_30 ++ ) {
V_287 = V_28 -> V_288 [ V_30 ] ;
if ( V_287 )
F_135 ( V_6 , V_60 , V_287 ,
V_286 ) ;
}
F_114 ( & V_28 -> V_44 ) ;
if ( F_136 ( V_6 ) )
F_135 ( V_6 , V_60 , 0 , V_286 ) ;
}
}
void F_33 ( struct V_21 * V_22 )
{
struct V_260 * V_289 = & V_22 -> V_41 ;
struct V_290 * V_291 ;
F_44 ( V_22 -> V_40 ) ;
while ( ! F_26 ( V_289 ) ) {
V_291 = F_117 ( V_289 -> V_292 , struct V_290 ,
V_68 ) ;
F_34 ( & V_291 -> V_257 ) ;
F_28 ( & V_291 -> V_68 ) ;
F_23 ( V_291 ) ;
}
}
void F_137 ( struct V_284 * V_171 )
{
struct V_5 * V_6 = F_133 ( V_171 ) ;
struct V_81 * V_34 = V_6 -> V_34 ;
static const T_2 V_293 [ V_294 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
struct V_295 * V_296 ;
T_1 V_297 = V_298 ;
if ( ! F_39 ( V_299 , & V_6 -> V_77 ) )
return;
if ( V_171 -> V_67 & V_300 ) {
if ( ! ( V_6 -> V_67 & V_301 ) )
V_297 = V_302 ;
} else if ( ( V_171 -> V_67 & V_303 ) ||
( F_138 ( V_171 ) > V_34 -> V_150 ) ) {
V_297 = V_304 ;
} else {
F_132 ( V_171 , V_293 , V_305 ) ;
if ( ! F_139 ( V_171 ) ) {
F_140 ( V_6 ) ;
F_141 (ha, netdev)
F_132 ( V_171 , V_296 -> V_306 ,
V_307 ) ;
}
}
if ( F_142 ( V_171 ) > V_34 -> V_308 ) {
V_297 = V_302 ;
} else if ( ! F_143 ( V_171 ) ) {
F_144 (ha, netdev)
F_132 ( V_171 , V_296 -> V_306 ,
V_309 ) ;
}
if ( V_6 -> V_10 -> V_310 ) {
if ( V_297 == V_302 &&
! V_6 -> V_311 ) {
F_145 ( V_6 ) ;
V_6 -> V_312 = 1 ;
V_6 -> V_313 = true ;
} else {
V_6 -> V_312 = 0 ;
V_6 -> V_313 = false ;
}
}
F_146 ( V_6 , V_297 ) ;
}
static void F_147 ( struct V_256 * V_257 )
{
struct V_290 * V_291 ;
struct V_5 * V_6 ;
struct V_65 * V_66 ;
V_291 = F_107 ( V_257 , struct V_290 , V_257 ) ;
V_6 = V_291 -> V_264 ;
V_66 = V_291 -> V_66 ;
F_126 ( V_6 , V_66 ) ;
return;
}
static struct V_290 *
F_148 ( struct V_21 * V_22 )
{
struct V_260 * V_261 ;
struct V_290 * V_291 = NULL ;
T_2 V_314 = 0 ;
F_116 (node, &bc->async_list) {
V_291 = F_117 ( V_261 , struct V_290 , V_68 ) ;
if ( ! F_149 ( & V_291 -> V_257 ) ) {
V_314 = 1 ;
break;
}
}
if ( ! V_314 ) {
V_291 = F_11 ( sizeof( struct V_290 ) ,
V_202 ) ;
if ( V_291 == NULL )
return NULL ;
F_111 ( & V_291 -> V_68 , & V_22 -> V_41 ) ;
}
return V_291 ;
}
static void F_150 ( struct V_21 * V_22 ,
T_4 V_233 , void * V_315 ,
struct V_65 * V_66 )
{
struct V_290 * V_291 = NULL ;
V_291 = F_148 ( V_22 ) ;
if ( ! V_291 )
return;
V_291 -> V_264 = V_315 ;
V_291 -> V_66 = V_66 ;
F_18 ( & V_291 -> V_257 , V_233 ) ;
F_90 ( V_22 -> V_40 , & V_291 -> V_257 ) ;
}
static int F_131 ( struct V_5 * V_6 ,
struct V_65 * V_66 )
{
struct V_21 * V_22 = & V_6 -> V_34 -> V_20 -> V_22 ;
if ( V_6 -> V_184 )
return - V_31 ;
F_150 ( V_22 , F_147 ,
V_6 , V_66 ) ;
return 0 ;
}
static int F_151 ( struct V_5 * V_6 )
{
int V_29 ;
V_6 -> V_184 = 0 ;
F_152 ( V_6 -> V_34 -> V_84 ) ;
F_153 ( V_6 ) ;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_6 , V_168 ) ;
if ( V_29 )
goto V_316;
V_29 = F_56 ( V_6 ) ;
if ( V_29 )
goto V_317;
return 0 ;
V_317:
F_36 ( V_6 , V_75 ) ;
V_316:
F_37 ( V_6 , 0 ) ;
return V_29 ;
}
static void F_154 ( struct V_5 * V_6 )
{
struct V_284 * V_171 = V_6 -> V_171 ;
if ( F_155 ( V_171 ) ) {
if ( ! F_156 ( V_6 , V_171 ) )
F_157 ( V_171 , V_318 ) ;
}
F_158 ( V_171 ) ;
}
static void F_159 ( struct V_5 * V_6 )
{
struct V_81 * V_34 = V_6 -> V_34 ;
struct V_319 * V_320 = V_34 -> V_320 ;
struct V_284 * V_171 = V_6 -> V_171 ;
T_2 V_30 , V_321 = V_34 -> V_322 - 1 ;
F_160 ( V_171 ) ;
F_161 ( V_6 ) ;
F_162 ( V_6 ) ;
if ( F_155 ( V_171 ) )
F_163 ( V_6 , V_171 ) ;
for ( V_30 = 0 ; V_30 < V_321 ; V_30 ++ ) {
V_320 [ V_30 ] . V_323 = V_30 ;
V_320 [ V_30 ] . V_324 = 0 ;
V_320 [ V_30 ] . V_325 = 0 ;
}
V_34 -> V_182 = 0 ;
}
static int F_164 ( struct V_5 * V_6 )
{
struct V_81 * V_34 = V_6 -> V_34 ;
struct V_114 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_326 * V_174 = & V_34 -> V_174 ;
T_2 V_233 = V_34 -> V_42 ;
T_1 V_77 ;
if ( ( V_174 -> V_327 == V_328 ) ||
( V_174 -> V_327 == V_329 ) ) {
if ( ! F_151 ( V_6 ) ) {
F_154 ( V_6 ) ;
V_6 -> V_176 = 0 ;
F_21 ( V_9 ,
L_33 ,
V_94 , V_233 ) ;
} else {
F_13 ( V_9 ,
L_34 ,
V_94 , V_233 ) ;
V_77 = F_72 ( V_34 , V_178 ) ;
F_21 ( V_9 , L_35 ,
V_77 ) ;
}
}
return 0 ;
}
static int F_165 ( struct V_5 * V_6 )
{
struct V_81 * V_34 = V_6 -> V_34 ;
struct V_82 * V_83 = V_34 -> V_84 ;
struct V_114 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_326 * V_174 = & V_34 -> V_174 ;
T_2 V_233 = V_34 -> V_42 ;
T_1 V_77 ;
V_6 -> V_330 ++ ;
if ( V_6 -> V_330 < 3 ) {
V_6 -> V_184 = 1 ;
F_77 ( V_276 , & V_83 -> V_115 ) ;
F_21 ( V_9 ,
L_36 ) ;
return 0 ;
}
if ( V_6 -> V_330 > V_331 ) {
F_77 ( V_180 , & V_174 -> V_115 ) ;
V_6 -> V_332 = 0 ;
V_6 -> V_176 = 0 ;
V_6 -> V_330 = 0 ;
F_159 ( V_6 ) ;
F_13 ( V_9 ,
L_37 ) ;
return - V_31 ;
}
F_21 ( V_9 , L_38 , V_233 ) ;
F_21 ( V_9 , L_39 ,
V_94 , V_6 -> V_330 , V_233 ) ;
F_74 ( V_188 , & V_6 -> V_77 ) ;
V_6 -> V_184 = 1 ;
F_77 ( V_276 , & V_83 -> V_115 ) ;
F_159 ( V_6 ) ;
V_6 -> V_184 = 0 ;
if ( ! F_151 ( V_6 ) ) {
F_154 ( V_6 ) ;
V_6 -> V_332 = 0 ;
V_6 -> V_330 = 0 ;
V_6 -> V_176 = 0 ;
F_21 ( V_9 , L_40 , V_233 ) ;
} else {
F_13 ( V_9 , L_41 ,
V_94 , V_233 ) ;
V_77 = F_72 ( V_34 , V_178 ) ;
F_21 ( V_9 , L_42 , V_94 , V_77 ) ;
}
return 0 ;
}
static int F_166 ( struct V_5 * V_6 )
{
struct V_81 * V_34 = V_6 -> V_34 ;
int V_146 = 0 ;
if ( V_34 -> V_174 . V_327 != V_179 )
V_146 = F_164 ( V_6 ) ;
else if ( V_34 -> V_182 )
V_146 = F_165 ( V_6 ) ;
F_77 ( V_188 , & V_6 -> V_77 ) ;
return V_146 ;
}
static int F_167 ( struct V_5 * V_6 )
{
struct V_326 * V_174 = & V_6 -> V_34 -> V_174 ;
F_13 ( & V_6 -> V_10 -> V_9 , L_43 ) ;
if ( V_174 -> V_327 == V_179 )
F_159 ( V_6 ) ;
F_77 ( V_180 , & V_174 -> V_115 ) ;
F_77 ( V_188 , & V_6 -> V_77 ) ;
return - V_31 ;
}
static int
F_168 ( struct V_5 * V_6 )
{
struct V_82 * V_83 = V_6 -> V_34 -> V_84 ;
struct V_326 * V_174 = & V_6 -> V_34 -> V_174 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_44 ) ;
if ( V_174 -> V_327 == V_179 ) {
F_74 ( V_188 , & V_6 -> V_77 ) ;
V_6 -> V_332 = 0 ;
V_6 -> V_330 = 0 ;
F_77 ( V_276 , & V_83 -> V_115 ) ;
F_159 ( V_6 ) ;
}
return 0 ;
}
static int F_169 ( struct V_5 * V_6 )
{
struct V_82 * V_83 = V_6 -> V_34 -> V_84 ;
struct V_326 * V_174 = & V_6 -> V_34 -> V_174 ;
T_2 V_233 = V_6 -> V_34 -> V_42 ;
if ( V_174 -> V_327 == V_179 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_45 , V_233 ) ;
F_74 ( V_188 , & V_6 -> V_77 ) ;
V_6 -> V_332 = 0 ;
V_6 -> V_330 = 0 ;
F_77 ( V_276 , & V_83 -> V_115 ) ;
F_159 ( V_6 ) ;
}
return 0 ;
}
static int F_170 ( struct V_5 * V_6 )
{
F_13 ( & V_6 -> V_10 -> V_9 , L_46 , V_94 ) ;
return 0 ;
}
static void F_171 ( struct V_5 * V_6 )
{
if ( V_6 -> V_333 . V_334 )
F_172 ( V_6 ) ;
}
static void V_173 ( struct V_256 * V_257 )
{
struct V_5 * V_6 ;
struct V_326 * V_174 ;
int V_146 = 0 ;
V_6 = F_107 ( V_257 , struct V_5 , V_335 . V_257 ) ;
V_174 = & V_6 -> V_34 -> V_174 ;
V_174 -> V_336 = F_72 ( V_6 -> V_34 , V_178 ) ;
switch ( V_174 -> V_336 ) {
case V_179 :
V_146 = F_166 ( V_6 ) ;
break;
case V_328 :
case V_329 :
V_146 = F_169 ( V_6 ) ;
break;
case V_337 :
V_146 = F_168 ( V_6 ) ;
break;
case V_338 :
V_146 = F_167 ( V_6 ) ;
break;
case V_339 :
break;
default:
V_146 = F_170 ( V_6 ) ;
}
V_174 -> V_327 = V_174 -> V_336 ;
F_171 ( V_6 ) ;
if ( ! V_146 && F_39 ( V_180 , & V_174 -> V_115 ) )
F_67 ( V_6 , V_173 ,
V_174 -> V_175 ) ;
}
static void F_173 ( struct V_5 * V_6 )
{
while ( F_88 ( V_188 , & V_6 -> V_77 ) )
F_71 ( 20 ) ;
F_77 ( V_180 , & V_6 -> V_34 -> V_174 . V_115 ) ;
F_77 ( V_188 , & V_6 -> V_77 ) ;
F_174 ( & V_6 -> V_335 ) ;
}
static int F_175 ( struct V_19 * V_20 ,
struct V_27 * V_28 , T_3 V_287 )
{
int V_30 , V_29 = - V_201 ;
if ( ! V_28 -> V_288 )
return V_29 ;
F_176 ( & V_28 -> V_44 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_145 ; V_30 ++ ) {
if ( V_28 -> V_288 [ V_30 ] == V_287 ) {
V_29 = 0 ;
break;
}
}
F_177 ( & V_28 -> V_44 ) ;
return V_29 ;
}
static int F_178 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
int V_29 = 0 ;
F_176 ( & V_28 -> V_44 ) ;
if ( V_28 -> V_340 >= V_20 -> V_145 )
V_29 = - V_201 ;
F_177 ( & V_28 -> V_44 ) ;
return V_29 ;
}
static int F_179 ( struct V_5 * V_6 ,
T_3 V_341 , T_2 V_266 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
bool V_342 ;
T_2 V_343 = 0 ;
int V_30 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
V_342 = F_134 ( V_28 ) ;
if ( V_20 -> V_53 != V_54 )
return - V_201 ;
if ( V_266 ) {
if ( F_180 ( V_6 ) && V_342 )
return - V_201 ;
if ( F_178 ( V_20 , V_28 ) )
return - V_201 ;
if ( V_20 -> V_144 ) {
for ( V_30 = 0 ; V_30 < V_20 -> V_145 ; V_30 ++ ) {
if ( V_20 -> V_143 [ V_30 ] == V_341 )
V_343 = 1 ;
}
if ( ! V_343 )
return - V_201 ;
}
} else {
if ( ! V_342 || F_175 ( V_20 , V_28 , V_341 ) )
return - V_201 ;
}
return 0 ;
}
static void F_181 ( struct V_27 * V_28 , T_3 V_287 ,
enum V_344 V_270 )
{
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_19 * V_20 ;
V_20 = V_6 -> V_34 -> V_20 ;
if ( ! V_28 -> V_288 )
return;
F_176 ( & V_28 -> V_44 ) ;
switch ( V_270 ) {
case V_345 :
F_182 ( V_20 , V_28 , V_287 ) ;
break;
case V_346 :
F_183 ( V_20 , V_28 , V_287 ) ;
break;
default:
F_184 ( V_6 -> V_171 , L_47 ) ;
}
F_177 ( & V_28 -> V_44 ) ;
return;
}
int F_185 ( struct V_5 * V_6 ,
T_3 V_341 , T_2 V_266 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_284 * V_171 = V_6 -> V_171 ;
struct V_27 * V_28 ;
struct V_65 V_66 ;
int V_146 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
if ( V_341 == 0 )
return 0 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
V_146 = F_179 ( V_6 , V_341 , V_266 ) ;
if ( V_146 )
return V_146 ;
V_146 = F_55 ( & V_66 ,
V_347 ) ;
if ( V_146 )
return V_146 ;
V_66 . V_70 . V_71 [ 1 ] = ( V_266 & 1 ) | V_341 << 16 ;
F_33 ( & V_20 -> V_22 ) ;
V_146 = F_48 ( V_6 , & V_66 ) ;
if ( V_146 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_48 , V_146 ) ;
} else {
F_186 ( V_171 ) ;
F_187 ( V_6 ) ;
F_188 ( V_171 ) ;
if ( V_266 )
F_181 ( V_28 , V_341 , V_345 ) ;
else
F_181 ( V_28 , V_341 , V_346 ) ;
F_186 ( V_171 ) ;
F_189 ( V_171 ) ;
F_188 ( V_171 ) ;
}
F_29 ( & V_66 ) ;
return V_146 ;
}
static void F_190 ( struct V_5 * V_6 )
{
struct V_260 * V_289 = & V_6 -> V_348 ;
struct V_349 * V_350 ;
while ( ! F_26 ( V_289 ) ) {
V_350 = F_117 ( V_289 -> V_292 , struct V_349 , V_68 ) ;
F_191 ( V_6 , V_350 -> V_351 , V_350 -> V_287 ,
V_352 ) ;
F_28 ( & V_350 -> V_68 ) ;
F_23 ( V_350 ) ;
}
}
static int F_192 ( struct V_8 * V_10 )
{
struct V_5 * V_6 = F_193 ( V_10 ) ;
struct V_284 * V_171 = V_6 -> V_171 ;
int V_353 ;
F_160 ( V_171 ) ;
F_194 ( V_6 ) ;
if ( F_155 ( V_171 ) )
F_163 ( V_6 , V_171 ) ;
F_36 ( V_6 , V_75 ) ;
F_37 ( V_6 , 0 ) ;
F_162 ( V_6 ) ;
F_174 ( & V_6 -> V_186 ) ;
V_353 = F_195 ( V_10 ) ;
if ( V_353 )
return V_353 ;
return 0 ;
}
static int F_196 ( struct V_5 * V_6 )
{
struct V_326 * V_174 = & V_6 -> V_34 -> V_174 ;
struct V_284 * V_171 = V_6 -> V_171 ;
int V_29 ;
F_74 ( V_180 , & V_174 -> V_115 ) ;
F_153 ( V_6 ) ;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_6 , V_168 ) ;
if ( ! V_29 ) {
if ( F_155 ( V_171 ) ) {
V_29 = F_156 ( V_6 , V_171 ) ;
if ( ! V_29 )
F_157 ( V_171 , V_318 ) ;
}
}
F_158 ( V_171 ) ;
F_67 ( V_6 , V_173 ,
V_174 -> V_175 ) ;
return V_29 ;
}
void F_53 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_18 ; V_30 ++ ) {
V_28 = & V_20 -> V_35 [ V_30 ] ;
V_28 -> V_288 = F_85 ( V_20 -> V_145 ,
sizeof( * V_28 -> V_288 ) , V_32 ) ;
}
}
void F_40 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_18 ; V_30 ++ ) {
V_28 = & V_20 -> V_35 [ V_30 ] ;
F_23 ( V_28 -> V_288 ) ;
V_28 -> V_288 = NULL ;
}
}
void F_182 ( struct V_19 * V_20 ,
struct V_27 * V_28 , T_3 V_287 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_145 ; V_30 ++ ) {
if ( ! V_28 -> V_288 [ V_30 ] ) {
V_28 -> V_288 [ V_30 ] = V_287 ;
V_28 -> V_340 ++ ;
return;
}
}
}
void F_183 ( struct V_19 * V_20 ,
struct V_27 * V_28 , T_3 V_287 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_145 ; V_30 ++ ) {
if ( V_28 -> V_288 [ V_30 ] == V_287 ) {
V_28 -> V_288 [ V_30 ] = 0 ;
V_28 -> V_340 -- ;
return;
}
}
}
bool F_134 ( struct V_27 * V_28 )
{
bool V_29 = false ;
F_176 ( & V_28 -> V_44 ) ;
if ( V_28 -> V_340 )
V_29 = true ;
F_177 ( & V_28 -> V_44 ) ;
return V_29 ;
}
