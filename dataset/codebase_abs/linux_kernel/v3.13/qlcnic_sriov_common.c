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
F_14 ( & V_28 -> V_44 . V_45 ) ;
F_14 ( & V_28 -> V_46 . V_45 ) ;
F_16 ( & V_28 -> V_44 . V_47 ) ;
F_16 ( & V_28 -> V_46 . V_47 ) ;
F_17 ( & V_28 -> V_48 ) ;
F_18 ( & V_28 -> V_49 , V_50 ) ;
if ( F_19 ( V_6 ) ) {
V_26 = F_11 ( sizeof( struct V_25 ) , V_32 ) ;
if ( ! V_26 ) {
V_29 = - V_33 ;
goto V_51;
}
V_20 -> V_35 [ V_30 ] . V_26 = V_26 ;
V_26 -> V_52 = V_53 ;
V_26 -> V_54 = true ;
F_20 ( V_26 -> V_55 ) ;
F_21 ( & V_6 -> V_10 -> V_9 ,
L_5 ,
V_26 -> V_55 , V_30 ) ;
}
}
return 0 ;
V_51:
F_22 ( V_22 -> V_40 ) ;
V_39:
F_22 ( V_22 -> V_38 ) ;
V_37:
F_23 ( V_20 -> V_35 ) ;
V_36:
F_23 ( V_6 -> V_34 -> V_20 ) ;
return V_29 ;
}
void F_24 ( struct V_56 * V_57 )
{
struct V_58 * V_59 ;
struct V_60 V_61 ;
unsigned long V_62 ;
F_25 ( & V_57 -> V_47 , V_62 ) ;
while ( ! F_26 ( & V_57 -> V_45 ) ) {
V_59 = F_27 ( & V_57 -> V_45 ,
struct V_58 , V_63 ) ;
F_28 ( & V_59 -> V_63 ) ;
V_57 -> V_64 -- ;
V_61 . V_65 . V_66 = ( T_1 * ) V_59 -> V_67 ;
V_61 . V_68 . V_66 = ( T_1 * ) V_59 -> V_69 ;
F_29 ( & V_61 ) ;
F_30 ( V_59 ) ;
}
F_31 ( & V_57 -> V_47 , V_62 ) ;
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
F_24 ( & V_28 -> V_46 ) ;
F_34 ( & V_28 -> V_49 ) ;
F_24 ( & V_28 -> V_44 ) ;
}
F_22 ( V_22 -> V_38 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_18 ; V_30 ++ )
F_23 ( V_20 -> V_35 [ V_30 ] . V_26 ) ;
F_23 ( V_20 -> V_35 ) ;
F_23 ( V_6 -> V_34 -> V_20 ) ;
}
static void F_35 ( struct V_5 * V_6 )
{
F_36 ( V_6 , V_70 ) ;
F_37 ( V_6 , 0 ) ;
F_32 ( V_6 ) ;
}
void F_38 ( struct V_5 * V_6 )
{
if ( F_19 ( V_6 ) )
F_39 ( V_6 ) ;
if ( F_6 ( V_6 ) )
F_35 ( V_6 ) ;
}
static int F_40 ( struct V_5 * V_6 , T_1 * V_71 ,
T_1 * V_72 , T_2 V_42 , T_2 V_73 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
struct V_75 * V_76 = V_34 -> V_77 ;
struct V_60 V_61 ;
unsigned long V_78 ;
int V_29 ;
memset ( & V_61 , 0 , sizeof( struct V_60 ) ) ;
V_61 . V_71 = V_71 ;
V_61 . V_72 = V_72 ;
V_61 . V_79 = V_73 ;
V_61 . V_80 = V_42 ;
V_61 . V_81 = V_82 ;
V_61 . V_83 = ( (struct V_84 * ) V_71 ) -> V_83 ;
V_29 = V_76 -> V_85 -> V_86 ( V_6 , & V_61 , & V_78 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_6 ,
V_87 , V_61 . V_83 , V_61 . type , V_34 -> V_42 ,
V_34 -> V_88 ) ;
return V_29 ;
}
if ( ! F_41 ( & V_61 . V_89 , V_78 ) ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_7 ,
V_87 , V_61 . V_83 , V_61 . type , V_34 -> V_42 ,
V_34 -> V_88 ) ;
F_42 ( V_76 -> V_90 ) ;
}
return V_61 . V_91 ;
}
static void F_43 ( struct V_5 * V_6 )
{
V_6 -> V_92 = V_93 ;
V_6 -> V_94 = V_95 ;
V_6 -> V_96 = V_97 ;
V_6 -> V_98 = V_99 ;
V_6 -> V_100 = V_101 ;
V_6 -> V_102 = V_103 ;
}
int F_44 ( struct V_5 * V_6 ,
struct V_104 * V_105 , T_3 V_106 )
{
struct V_107 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_60 V_61 ;
int V_29 ;
T_1 V_108 ;
V_29 = F_45 ( & V_61 , V_6 , V_109 ) ;
if ( V_29 )
return V_29 ;
V_61 . V_65 . V_66 [ 1 ] = V_106 << 16 | 0x1 ;
V_29 = F_46 ( V_6 , & V_61 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_8 , V_29 ) ;
F_29 ( & V_61 ) ;
return V_29 ;
}
V_108 = V_61 . V_68 . V_66 [ 2 ] & 0xffff ;
if ( V_108 & V_110 )
V_105 -> V_111 = F_47 ( V_61 . V_68 . V_66 [ 2 ] ) ;
if ( V_108 & V_112 )
V_105 -> V_52 = F_48 ( V_61 . V_68 . V_66 [ 3 ] ) ;
if ( V_108 & V_113 )
V_105 -> V_114 = F_47 ( V_61 . V_68 . V_66 [ 3 ] ) ;
if ( V_108 & V_115 )
V_105 -> V_116 = F_48 ( V_61 . V_68 . V_66 [ 4 ] ) ;
if ( V_108 & V_117 )
V_105 -> V_118 = F_47 ( V_61 . V_68 . V_66 [ 4 ] ) ;
if ( V_108 & V_119 )
V_105 -> V_120 = F_48 ( V_61 . V_68 . V_66 [ 5 ] ) ;
if ( V_108 & V_121 )
V_105 -> V_122 = F_47 ( V_61 . V_68 . V_66 [ 5 ] ) ;
if ( V_108 & V_123 )
V_105 -> V_124 = F_48 ( V_61 . V_68 . V_66 [ 6 ] ) ;
if ( V_108 & V_125 )
V_105 -> V_126 = F_47 ( V_61 . V_68 . V_66 [ 6 ] ) ;
if ( V_108 & V_127 )
V_105 -> V_128 = F_48 ( V_61 . V_68 . V_66 [ 7 ] ) ;
V_105 -> V_129 = F_47 ( V_61 . V_68 . V_66 [ 7 ] ) ;
V_105 -> V_130 = F_48 ( V_61 . V_68 . V_66 [ 8 ] ) ;
V_105 -> V_131 = F_47 ( V_61 . V_68 . V_66 [ 8 ] ) ;
V_105 -> V_132 = F_48 ( V_61 . V_68 . V_66 [ 9 ] ) ;
F_21 ( V_9 , L_9
L_10
L_11
L_12
L_13
L_14 ,
V_105 -> V_111 , V_105 -> V_52 ,
V_105 -> V_114 , V_105 -> V_116 ,
V_105 -> V_118 ,
V_105 -> V_120 , V_105 -> V_122 ,
V_105 -> V_124 , V_105 -> V_126 ,
V_105 -> V_128 , V_105 -> V_129 ,
V_105 -> V_130 , V_105 -> V_131 ,
V_105 -> V_132 ) ;
F_29 ( & V_61 ) ;
return V_29 ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_60 * V_61 )
{
V_6 -> V_133 = F_47 ( V_61 -> V_68 . V_66 [ 1 ] ) & 0xffff ;
V_6 -> V_62 &= ~ V_134 ;
return 0 ;
}
static int F_50 ( struct V_5 * V_6 ,
struct V_60 * V_61 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
int V_30 , V_135 ;
T_3 * V_136 ;
if ( V_20 -> V_137 )
return 0 ;
V_20 -> V_138 = V_61 -> V_68 . V_66 [ 2 ] & 0xf ;
if ( ! V_20 -> V_138 )
return 0 ;
V_20 -> V_139 = V_61 -> V_68 . V_66 [ 2 ] >> 16 ;
V_135 = V_20 -> V_139 ;
V_20 -> V_137 = F_11 ( sizeof( T_3 ) * V_135 , V_32 ) ;
if ( ! V_20 -> V_137 )
return - V_33 ;
V_136 = ( T_3 * ) & V_61 -> V_68 . V_66 [ 3 ] ;
for ( V_30 = 0 ; V_30 < V_135 ; V_30 ++ )
V_20 -> V_137 [ V_30 ] = V_136 [ V_30 ] ;
return 0 ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_104 * V_140 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_60 V_61 ;
int V_141 = 0 ;
V_141 = F_52 ( & V_61 , V_142 ) ;
if ( V_141 )
return V_141 ;
V_141 = F_46 ( V_6 , & V_61 ) ;
if ( V_141 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_15 ,
V_141 ) ;
} else {
V_20 -> V_143 = V_61 . V_68 . V_66 [ 1 ] & 0x3 ;
switch ( V_20 -> V_143 ) {
case V_144 :
V_141 = F_50 ( V_6 , & V_61 ) ;
break;
case V_145 :
V_141 = F_49 ( V_6 , & V_61 ) ;
break;
}
}
F_29 ( & V_61 ) ;
return V_141 ;
}
static int F_53 ( struct V_5 * V_6 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
struct V_104 V_146 ;
int V_29 ;
V_29 = F_44 ( V_6 , & V_146 , 0 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_54 ( V_6 , & V_146 , V_34 -> V_42 ) ;
if ( V_29 )
return - V_31 ;
V_29 = F_51 ( V_6 , & V_146 ) ;
if ( V_29 )
return V_29 ;
if ( F_55 ( V_6 ) )
return - V_31 ;
F_43 ( V_6 ) ;
V_6 -> V_62 |= V_147 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_16 ,
V_6 -> V_34 -> V_148 ) ;
V_34 -> V_149 = ( T_2 ) V_146 . V_150 ;
V_34 -> V_151 = V_146 . V_151 ;
V_34 -> V_152 = V_146 . V_152 ;
V_34 -> V_88 = V_146 . V_88 ;
V_34 -> V_153 = V_146 . V_153 ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 ,
int V_154 )
{
struct V_155 * V_156 ;
int V_29 ;
F_14 ( & V_6 -> V_157 ) ;
if ( ! V_158 && ! ! V_159 )
F_57 ( & V_6 -> V_10 -> V_9 ,
L_17 ) ;
F_58 ( V_6 , V_160 ) ;
F_59 ( V_6 , V_160 ) ;
V_29 = F_60 ( V_6 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_18 ) ;
goto V_161;
}
V_29 = F_61 ( V_6 ) ;
if ( V_29 )
goto V_161;
V_29 = F_9 ( V_6 , 1 ) ;
if ( V_29 )
goto V_162;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
goto V_163;
V_29 = F_36 ( V_6 , V_164 ) ;
if ( V_29 )
goto V_165;
V_29 = F_53 ( V_6 ) ;
if ( V_29 )
goto V_166;
V_156 = V_6 -> V_156 ;
if ( V_156 && F_62 ( V_156 ) )
F_63 ( V_156 ) ;
V_29 = F_64 ( V_6 , V_6 -> V_167 , V_154 ) ;
if ( V_29 )
goto V_166;
F_65 ( V_6 -> V_10 , V_6 ) ;
F_21 ( & V_6 -> V_10 -> V_9 , L_19 ,
V_6 -> V_167 -> V_168 ) ;
F_66 ( V_6 , V_169 ,
V_6 -> V_34 -> V_170 . V_171 ) ;
return 0 ;
V_166:
F_36 ( V_6 , V_70 ) ;
V_165:
F_37 ( V_6 , 0 ) ;
V_163:
F_32 ( V_6 ) ;
V_162:
F_67 ( V_6 ) ;
V_161:
F_68 ( V_6 ) ;
return V_29 ;
}
static int F_69 ( struct V_5 * V_6 )
{
T_1 V_172 ;
do {
F_70 ( 20 ) ;
if ( ++ V_6 -> V_173 > V_174 )
return - V_31 ;
V_172 = F_71 ( V_6 -> V_34 , V_175 ) ;
} while ( V_172 != V_176 );
return 0 ;
}
int F_72 ( struct V_5 * V_6 , int V_154 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
int V_29 ;
F_73 ( V_177 , & V_34 -> V_170 . V_108 ) ;
V_34 -> V_170 . V_171 = V_178 ;
V_34 -> V_179 = 0 ;
V_6 -> V_173 = 0 ;
V_34 -> V_180 = 1 ;
V_6 -> V_181 = 0 ;
V_6 -> V_62 |= V_182 ;
V_29 = F_69 ( V_6 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_56 ( V_6 , V_154 ) ;
if ( V_29 )
return V_29 ;
if ( F_74 ( V_6 ) )
F_57 ( & V_6 -> V_10 -> V_9 , L_20 ) ;
F_75 ( & V_6 -> V_183 , V_184 ) ;
F_76 ( V_185 , & V_6 -> V_172 ) ;
return 0 ;
}
void F_77 ( struct V_5 * V_6 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
V_34 -> V_88 = V_186 ;
F_21 ( & V_6 -> V_10 -> V_9 ,
L_21 ,
V_34 -> V_148 ) ;
V_6 -> V_187 = & V_188 ;
F_73 ( V_189 , & V_6 -> V_172 ) ;
return;
}
void F_78 ( struct V_74 * V_34 )
{
V_34 -> V_190 = & V_191 ;
V_34 -> V_192 = ( T_1 * ) V_193 ;
V_34 -> V_194 = ( T_1 * ) V_195 ;
}
static T_1 F_79 ( T_1 V_196 , T_2 V_197 )
{
T_1 V_79 ;
V_79 = V_196 / ( ( V_197 + 1 ) * V_198 ) ;
if ( V_79 )
V_79 = V_198 ;
else
V_79 = V_196 % V_198 ;
return V_79 ;
}
int F_80 ( struct V_5 * V_6 , T_2 V_42 )
{
struct V_27 * V_35 = V_6 -> V_34 -> V_20 -> V_35 ;
T_2 V_30 ;
if ( F_6 ( V_6 ) )
return 0 ;
for ( V_30 = 0 ; V_30 < V_6 -> V_34 -> V_20 -> V_18 ; V_30 ++ ) {
if ( V_35 [ V_30 ] . V_42 == V_42 )
return V_30 ;
}
return - V_199 ;
}
static inline int F_81 ( struct V_58 * * V_59 )
{
* V_59 = F_11 ( sizeof( struct V_58 ) , V_200 ) ;
if ( ! * V_59 )
return - V_33 ;
F_17 ( & ( * V_59 ) -> V_201 ) ;
return 0 ;
}
static inline int F_82 ( struct V_84 * * V_71 ,
T_1 V_73 )
{
* V_71 = F_11 ( sizeof( struct V_84 ) * V_73 , V_200 ) ;
if ( ! * V_71 )
return - V_33 ;
return 0 ;
}
static int F_52 ( struct V_60 * V_76 , T_1 type )
{
const struct V_202 * V_203 ;
int V_30 , V_73 ;
V_203 = V_204 ;
V_73 = F_83 ( V_204 ) ;
for ( V_30 = 0 ; V_30 < V_73 ; V_30 ++ ) {
if ( type == V_203 [ V_30 ] . V_61 ) {
V_76 -> V_81 = V_205 ;
V_76 -> V_65 . V_206 = V_203 [ V_30 ] . V_207 ;
V_76 -> V_68 . V_206 = V_203 [ V_30 ] . V_208 ;
V_76 -> V_65 . V_66 = F_84 ( V_76 -> V_65 . V_206 , sizeof( T_1 ) ,
V_200 ) ;
if ( ! V_76 -> V_65 . V_66 )
return - V_33 ;
V_76 -> V_68 . V_66 = F_84 ( V_76 -> V_68 . V_206 , sizeof( T_1 ) ,
V_200 ) ;
if ( ! V_76 -> V_68 . V_66 ) {
F_23 ( V_76 -> V_65 . V_66 ) ;
V_76 -> V_65 . V_66 = NULL ;
return - V_33 ;
}
memset ( V_76 -> V_65 . V_66 , 0 , sizeof( T_1 ) * V_76 -> V_65 . V_206 ) ;
memset ( V_76 -> V_68 . V_66 , 0 , sizeof( T_1 ) * V_76 -> V_68 . V_206 ) ;
V_76 -> V_65 . V_66 [ 0 ] = ( type | ( V_76 -> V_65 . V_206 << 16 ) |
( 3 << 29 ) ) ;
V_76 -> V_68 . V_66 [ 0 ] = ( type & 0xffff ) | V_76 -> V_68 . V_206 << 16 ;
return 0 ;
}
}
return - V_199 ;
}
static int F_85 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
T_3 V_209 , T_2 V_210 )
{
struct V_84 * V_71 ;
int V_30 ;
T_1 V_211 , V_212 ;
T_3 V_213 ;
T_2 V_83 , V_214 , V_215 ;
V_212 = V_198 ;
if ( V_210 == V_216 ) {
V_59 -> V_67 = (struct V_217 * ) V_61 -> V_65 . V_66 ;
V_59 -> V_69 = (struct V_217 * ) V_61 -> V_68 . V_66 ;
V_211 = V_61 -> V_65 . V_206 ;
V_59 -> V_218 = ( V_211 * 4 ) ;
V_211 = V_61 -> V_68 . V_206 ;
V_59 -> V_219 = ( V_211 * 4 ) ;
V_83 = V_61 -> V_65 . V_66 [ 0 ] & 0xff ;
V_213 = ( V_59 -> V_218 ) % ( V_212 ) ;
V_214 = ( V_59 -> V_218 ) / ( V_212 ) ;
if ( V_213 )
V_214 ++ ;
V_215 = V_214 ;
if ( F_82 ( & V_59 -> V_220 , V_214 ) )
return - V_33 ;
V_213 = ( V_59 -> V_219 ) % ( V_212 ) ;
V_214 = ( V_59 -> V_219 ) / ( V_212 ) ;
if ( V_213 )
V_214 ++ ;
if ( F_82 ( & V_59 -> V_221 , V_214 ) )
return - V_33 ;
V_214 = V_215 ;
V_71 = V_59 -> V_220 ;
} else {
V_61 -> V_65 . V_66 = ( T_1 * ) V_59 -> V_67 ;
V_61 -> V_68 . V_66 = ( T_1 * ) V_59 -> V_69 ;
V_83 = V_61 -> V_65 . V_66 [ 0 ] & 0xff ;
V_213 = ( V_59 -> V_219 ) % ( V_212 ) ;
V_214 = ( V_59 -> V_219 ) / ( V_212 ) ;
if ( V_213 )
V_214 ++ ;
V_61 -> V_65 . V_206 = V_59 -> V_218 / 4 ;
V_61 -> V_68 . V_206 = V_59 -> V_219 / 4 ;
V_71 = V_59 -> V_221 ;
V_61 -> V_81 = V_59 -> V_220 -> V_81 ;
}
V_59 -> V_222 = V_209 ;
V_59 -> V_223 = V_83 ;
for ( V_30 = 0 ; V_30 < V_214 ; V_30 ++ ) {
V_71 [ V_30 ] . V_224 = 2 ;
V_71 [ V_30 ] . V_210 = V_210 ;
V_71 [ V_30 ] . V_81 = V_61 -> V_81 ;
V_71 [ V_30 ] . V_225 = 1 ;
V_71 [ V_30 ] . V_214 = V_214 ;
V_71 [ V_30 ] . V_226 = V_30 + 1 ;
V_71 [ V_30 ] . V_83 = V_83 ;
V_71 [ V_30 ] . V_227 = V_209 ;
}
return 0 ;
}
static void F_30 ( struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_23 ( V_59 -> V_220 ) ;
F_23 ( V_59 -> V_221 ) ;
F_23 ( V_59 ) ;
}
static int F_86 ( struct V_27 * V_28 ,
struct V_58 * V_59 , T_2 type )
{
struct V_56 * V_57 ;
unsigned long V_62 ;
int V_141 = 0 ;
if ( type == V_228 ) {
V_57 = & V_28 -> V_44 ;
F_25 ( & V_57 -> V_47 , V_62 ) ;
V_57 -> V_64 -- ;
F_28 ( & V_59 -> V_63 ) ;
if ( V_57 -> V_64 > 0 )
V_141 = 1 ;
F_31 ( & V_57 -> V_47 , V_62 ) ;
}
if ( type == V_216 ) {
while ( F_87 ( V_229 , & V_28 -> V_172 ) )
F_70 ( 100 ) ;
V_28 -> V_230 = NULL ;
F_76 ( V_229 , & V_28 -> V_172 ) ;
}
return V_141 ;
}
static void F_88 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
T_4 V_231 )
{
if ( F_89 ( V_232 , & V_28 -> V_172 ) ||
V_28 -> V_6 -> V_181 )
return;
F_90 ( V_20 -> V_22 . V_38 , & V_28 -> V_49 ) ;
}
static inline void F_91 ( struct V_58 * V_59 )
{
struct V_89 * V_233 = & V_59 -> V_201 ;
if ( F_41 ( V_233 , V_234 ) )
V_59 -> V_235 = V_236 ;
else
V_59 -> V_235 = V_237 ;
return;
}
static void F_92 ( struct V_58 * V_59 ,
T_2 type )
{
if ( type == V_228 ) {
V_59 -> V_238 ++ ;
if ( V_59 -> V_238 < V_59 -> V_221 -> V_214 )
V_59 -> V_235 = V_239 ;
else
V_59 -> V_235 = V_236 ;
} else {
V_59 -> V_240 ++ ;
if ( V_59 -> V_240 < V_59 -> V_220 -> V_214 )
V_59 -> V_235 = V_239 ;
else
V_59 -> V_235 = V_241 ;
}
}
static void F_93 ( struct V_58 * V_59 ,
T_2 type )
{
struct V_27 * V_28 = V_59 -> V_28 ;
struct V_89 * V_233 = & V_28 -> V_48 ;
if ( ! F_41 ( V_233 , V_242 ) ) {
V_59 -> V_235 = V_237 ;
return;
}
F_76 ( V_243 , & V_28 -> V_172 ) ;
F_92 ( V_59 , type ) ;
}
static void F_94 ( struct V_5 * V_6 ,
T_1 * V_71 , T_1 * V_72 , T_1 V_73 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
T_1 V_244 ;
T_2 V_30 , V_245 = 2 , V_246 , V_247 ;
V_246 = ( sizeof( struct V_84 ) / sizeof( T_1 ) ) ;
V_245 = ( V_73 / sizeof( T_1 ) ) + V_246 ;
V_244 = F_95 ( F_96 ( V_34 , 0 ) ) ;
for ( V_30 = 2 , V_247 = 0 ; V_247 < V_246 ; V_30 ++ , V_247 ++ )
* ( V_71 ++ ) = F_95 ( F_96 ( V_34 , V_30 ) ) ;
for (; V_247 < V_245 ; V_30 ++ , V_247 ++ )
* ( V_72 ++ ) = F_95 ( F_96 ( V_34 , V_30 ) ) ;
}
static int F_97 ( struct V_27 * V_28 )
{
int V_141 = - V_248 ;
T_1 V_78 = 10000 ;
do {
if ( ! F_87 ( V_243 , & V_28 -> V_172 ) ) {
V_141 = 0 ;
break;
}
F_98 ( 1 ) ;
} while ( -- V_78 );
return V_141 ;
}
static int F_99 ( struct V_58 * V_59 , T_2 type )
{
struct V_27 * V_28 = V_59 -> V_28 ;
T_1 V_79 , V_246 ;
T_1 * V_71 , * V_72 ;
int V_141 ;
T_2 V_42 = V_59 -> V_249 ;
if ( F_97 ( V_28 ) )
return - V_248 ;
if ( type == V_216 ) {
V_71 = ( T_1 * ) ( V_59 -> V_220 + V_59 -> V_240 ) ;
V_72 = ( T_1 * ) ( V_59 -> V_67 + V_59 -> V_240 ) ;
V_246 = ( sizeof( struct V_84 ) / sizeof( T_1 ) ) ;
V_79 = F_79 ( V_59 -> V_218 ,
V_59 -> V_240 ) ;
V_79 = ( V_79 / sizeof( T_1 ) ) ;
} else {
V_71 = ( T_1 * ) ( V_59 -> V_221 + V_59 -> V_238 ) ;
V_72 = ( T_1 * ) ( V_59 -> V_69 + V_59 -> V_238 ) ;
V_246 = ( sizeof( struct V_84 ) / sizeof( T_1 ) ) ;
V_79 = F_79 ( V_59 -> V_219 ,
V_59 -> V_238 ) ;
V_79 = ( V_79 / sizeof( T_1 ) ) ;
}
V_141 = F_40 ( V_28 -> V_6 , V_71 , V_72 ,
V_42 , V_79 ) ;
return V_141 ;
}
static int F_100 ( struct V_58 * V_59 ,
struct V_27 * V_28 , T_2 type )
{
bool V_250 = true ;
int V_29 = - V_31 ;
while ( V_250 ) {
if ( F_89 ( V_232 , & V_28 -> V_172 ) ||
V_28 -> V_6 -> V_181 )
V_59 -> V_235 = V_237 ;
switch ( V_59 -> V_235 ) {
case V_239 :
V_59 -> V_235 = V_251 ;
if ( F_99 ( V_59 , type ) )
V_59 -> V_235 = V_237 ;
break;
case V_251 :
F_93 ( V_59 , type ) ;
break;
case V_241 :
F_91 ( V_59 ) ;
break;
case V_236 :
V_29 = 0 ;
V_250 = false ;
break;
case V_237 :
V_29 = - V_31 ;
V_250 = false ;
F_76 ( V_243 , & V_28 -> V_172 ) ;
break;
default:
V_29 = - V_31 ;
V_250 = false ;
}
}
return V_29 ;
}
static int F_101 ( struct V_5 * V_6 ,
struct V_58 * V_59 , int V_42 )
{
struct V_27 * V_28 ;
int V_29 , V_252 = F_80 ( V_6 , V_42 ) ;
if ( V_252 < 0 )
return - V_31 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ V_252 ] ;
V_59 -> V_28 = V_28 ;
V_59 -> V_249 = V_42 ;
if ( ! F_89 ( V_253 , & V_28 -> V_172 ) ) {
if ( F_19 ( V_6 ) )
return - V_31 ;
if ( F_6 ( V_6 ) &&
V_59 -> V_223 != V_164 )
return - V_31 ;
}
F_102 ( & V_28 -> V_43 ) ;
V_28 -> V_230 = V_59 ;
V_29 = F_100 ( V_59 , V_28 , V_216 ) ;
F_86 ( V_28 , V_59 , V_216 ) ;
F_103 ( & V_28 -> V_43 ) ;
return V_29 ;
}
static void F_104 ( struct V_5 * V_6 ,
struct V_58 * V_59 ,
struct V_60 * V_61 )
{
#ifdef F_105
if ( F_19 ( V_6 ) ) {
F_106 ( V_6 , V_59 , V_61 ) ;
return;
}
#endif
V_61 -> V_68 . V_66 [ 0 ] |= ( 0x9 << 25 ) ;
return;
}
static void V_50 ( struct V_254 * V_255 )
{
struct V_27 * V_28 = F_107 ( V_255 , struct V_27 ,
V_49 ) ;
struct V_58 * V_59 = NULL ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_60 V_61 ;
T_2 V_65 ;
if ( V_6 -> V_181 )
return;
if ( F_89 ( V_232 , & V_28 -> V_172 ) )
return;
memset ( & V_61 , 0 , sizeof( struct V_60 ) ) ;
V_59 = F_27 ( & V_28 -> V_44 . V_45 ,
struct V_58 , V_63 ) ;
V_6 = V_28 -> V_6 ;
if ( F_85 ( V_59 , & V_61 , V_59 -> V_220 -> V_227 ,
V_228 ) )
goto V_256;
F_104 ( V_6 , V_59 , & V_61 ) ;
V_59 -> V_235 = V_239 ;
F_100 ( V_59 , V_28 , V_228 ) ;
V_256:
F_29 ( & V_61 ) ;
V_65 = F_86 ( V_28 , V_59 , V_228 ) ;
F_30 ( V_59 ) ;
if ( V_65 )
F_88 ( V_6 -> V_34 -> V_20 , V_28 ,
V_50 ) ;
}
static void F_108 ( struct V_84 * V_71 ,
struct V_27 * V_28 )
{
struct V_58 * V_59 ;
T_1 V_79 ;
if ( F_87 ( V_229 , & V_28 -> V_172 ) )
return;
V_59 = V_28 -> V_230 ;
if ( V_59 == NULL )
goto V_257;
if ( V_59 -> V_222 != V_71 -> V_227 )
goto V_257;
V_79 = F_79 ( V_59 -> V_219 ,
V_59 -> V_238 ) ;
F_94 ( V_28 -> V_6 ,
( T_1 * ) ( V_59 -> V_221 + V_59 -> V_238 ) ,
( T_1 * ) ( V_59 -> V_69 + V_59 -> V_238 ) ,
V_79 ) ;
if ( ++ V_59 -> V_238 < V_59 -> V_221 -> V_214 )
goto V_257;
F_109 ( & V_59 -> V_201 ) ;
V_257:
F_76 ( V_229 , & V_28 -> V_172 ) ;
}
int F_110 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_58 * V_59 )
{
struct V_56 * V_57 = & V_28 -> V_44 ;
V_57 -> V_64 ++ ;
F_111 ( & V_59 -> V_63 , & V_57 -> V_45 ) ;
if ( V_57 -> V_64 == 1 )
F_88 ( V_20 , V_28 ,
V_50 ) ;
return 0 ;
}
static int F_112 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_58 * V_59 )
{
struct V_56 * V_57 = & V_28 -> V_44 ;
F_113 ( & V_57 -> V_47 ) ;
F_110 ( V_20 , V_28 , V_59 ) ;
F_114 ( & V_57 -> V_47 ) ;
return 0 ;
}
static void F_115 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_84 * V_71 )
{
struct V_58 * V_59 = NULL ;
struct V_258 * V_259 ;
T_1 V_79 , V_197 ;
T_2 V_260 = 0 , V_261 = 0 ;
F_113 ( & V_28 -> V_46 . V_47 ) ;
if ( V_28 -> V_46 . V_64 > 0 ) {
F_116 (node, &vf->rcv_pend.wait_list) {
V_59 = F_117 ( V_259 , struct V_58 , V_63 ) ;
if ( V_59 -> V_222 == V_71 -> V_227 ) {
V_260 = 1 ;
break;
}
}
}
if ( V_260 ) {
V_197 = V_59 -> V_240 ;
V_79 = F_79 ( V_59 -> V_218 ,
V_197 ) ;
F_94 ( V_28 -> V_6 ,
( T_1 * ) ( V_59 -> V_220 + V_197 ) ,
( T_1 * ) ( V_59 -> V_67 + V_197 ) ,
V_79 ) ;
V_59 -> V_240 ++ ;
if ( V_59 -> V_240 >= V_71 -> V_214 ) {
V_28 -> V_46 . V_64 -- ;
F_28 ( & V_59 -> V_63 ) ;
V_261 = 1 ;
}
}
F_114 ( & V_28 -> V_46 . V_47 ) ;
if ( V_261 )
if ( F_112 ( V_20 , V_28 , V_59 ) )
F_30 ( V_59 ) ;
return;
}
static void F_118 ( struct V_19 * V_20 ,
struct V_84 * V_71 ,
struct V_27 * V_28 )
{
struct V_58 * V_59 ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_60 V_61 ;
T_1 V_79 ;
int V_29 ;
T_2 V_83 ;
if ( V_6 -> V_181 )
return;
if ( ! F_89 ( V_253 , & V_28 -> V_172 ) &&
V_71 -> V_81 != V_205 &&
V_71 -> V_83 != V_164 )
return;
if ( V_71 -> V_226 > 1 ) {
F_115 ( V_20 , V_28 , V_71 ) ;
return;
}
memset ( & V_61 , 0 , sizeof( struct V_60 ) ) ;
V_83 = V_71 -> V_83 ;
if ( F_81 ( & V_59 ) )
return;
if ( V_71 -> V_81 == V_205 )
V_29 = F_52 ( & V_61 , V_83 ) ;
else
V_29 = F_45 ( & V_61 , V_6 , V_83 ) ;
if ( V_29 ) {
F_30 ( V_59 ) ;
return;
}
V_61 . V_81 = V_71 -> V_81 ;
if ( F_85 ( V_59 , & V_61 , V_71 -> V_227 ,
V_216 ) ) {
F_29 ( & V_61 ) ;
F_30 ( V_59 ) ;
return;
}
V_79 = F_79 ( V_59 -> V_218 ,
V_59 -> V_240 ) ;
F_94 ( V_28 -> V_6 ,
( T_1 * ) ( V_59 -> V_220 + V_59 -> V_240 ) ,
( T_1 * ) ( V_59 -> V_67 + V_59 -> V_240 ) ,
V_79 ) ;
V_59 -> V_249 = V_28 -> V_42 ;
V_59 -> V_28 = V_28 ;
V_59 -> V_222 = V_71 -> V_227 ;
V_59 -> V_240 ++ ;
if ( F_119 ( V_6 , V_59 , V_28 ) )
return;
if ( V_59 -> V_240 == V_59 -> V_220 -> V_214 ) {
if ( F_112 ( V_20 , V_28 , V_59 ) ) {
F_29 ( & V_61 ) ;
F_30 ( V_59 ) ;
}
} else {
F_113 ( & V_28 -> V_46 . V_47 ) ;
F_111 ( & V_59 -> V_63 , & V_28 -> V_46 . V_45 ) ;
V_28 -> V_46 . V_64 ++ ;
F_114 ( & V_28 -> V_46 . V_47 ) ;
}
}
static void F_120 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
struct V_84 V_71 ;
T_1 * V_262 = ( T_1 * ) & V_71 ;
T_2 V_210 , V_30 ;
for ( V_30 = 2 ; V_30 < 6 ; V_30 ++ )
V_262 [ V_30 - 2 ] = F_95 ( F_96 ( V_28 -> V_6 -> V_34 , V_30 ) ) ;
V_210 = V_71 . V_210 ;
switch ( V_210 ) {
case V_216 :
F_118 ( V_20 , & V_71 , V_28 ) ;
break;
case V_228 :
F_108 ( & V_71 , V_28 ) ;
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
L_22 ) ;
}
void F_123 ( struct V_5 * V_6 , T_1 V_263 )
{
struct V_27 * V_28 ;
struct V_19 * V_20 ;
int V_252 ;
T_2 V_42 ;
V_20 = V_6 -> V_34 -> V_20 ;
V_42 = F_4 ( V_263 ) ;
V_252 = F_80 ( V_6 , V_42 ) ;
if ( V_252 < 0 )
return;
V_28 = & V_20 -> V_35 [ V_252 ] ;
V_28 -> V_42 = V_42 ;
if ( F_2 ( V_263 ) )
F_109 ( & V_28 -> V_48 ) ;
if ( F_3 ( V_263 ) ) {
F_121 ( V_20 , V_28 ) ;
return;
}
if ( F_1 ( V_263 ) )
F_120 ( V_20 , V_28 ) ;
}
int F_37 ( struct V_5 * V_6 , T_2 V_264 )
{
struct V_60 V_61 ;
int V_29 ;
if ( ! F_89 ( V_189 , & V_6 -> V_172 ) )
return 0 ;
if ( F_45 ( & V_61 , V_6 , V_265 ) )
return - V_33 ;
if ( V_264 )
V_61 . V_65 . V_66 [ 1 ] = ( 1 << 4 ) | ( 1 << 5 ) | ( 1 << 6 ) | ( 1 << 7 ) ;
V_29 = F_124 ( V_6 , & V_61 ) ;
if ( V_29 != V_266 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_23 ,
( V_264 ? L_24 : L_25 ) , V_29 ) ;
}
F_29 ( & V_61 ) ;
return V_29 ;
}
static int F_125 ( struct V_5 * V_6 ,
struct V_58 * V_59 )
{
T_2 V_245 = V_174 ;
T_1 V_172 ;
V_172 = F_71 ( V_6 -> V_34 , V_175 ) ;
if ( V_172 == V_176 ) {
F_70 ( 20 ) ;
F_76 ( V_243 , & V_59 -> V_28 -> V_172 ) ;
V_59 -> V_235 = V_239 ;
if ( ++ V_6 -> V_173 > V_245 )
return - V_31 ;
else
return 0 ;
}
return - V_31 ;
}
static int F_126 ( struct V_5 * V_6 ,
struct V_60 * V_61 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
struct V_75 * V_76 = V_34 -> V_77 ;
struct V_107 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_58 * V_59 ;
int V_29 ;
T_1 V_267 , V_268 , V_269 , V_68 ;
T_3 V_209 = ++ V_6 -> V_34 -> V_20 -> V_22 . V_270 ;
T_2 V_231 = V_34 -> V_42 ;
V_68 = F_81 ( & V_59 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_85 ( V_59 , V_61 , V_209 , V_216 ) ;
if ( V_68 )
goto V_271;
V_272:
if ( ! F_89 ( V_273 , & V_76 -> V_108 ) ) {
V_68 = - V_31 ;
F_127 ( V_6 , V_274 , L_26 ,
F_128 ( V_61 -> V_65 . V_66 [ 0 ] ) , V_231 ) ;
goto V_275;
}
V_29 = F_101 ( V_6 , V_59 , V_231 ) ;
if ( V_29 ) {
F_13 ( V_9 , L_27 ,
( V_61 -> V_65 . V_66 [ 0 ] & 0xffff ) , V_231 ) ;
V_68 = V_276 ;
if ( ( V_59 -> V_220 -> V_83 == V_164 ) &&
! F_125 ( V_6 , V_59 ) )
goto V_272;
goto V_275;
}
V_267 = V_61 -> V_68 . V_66 [ 0 ] ;
V_269 = F_129 ( V_267 ) ;
V_268 = F_128 ( V_61 -> V_65 . V_66 [ 0 ] ) ;
if ( ( V_269 == V_277 ) ||
( V_269 == V_278 ) ) {
V_68 = V_266 ;
} else {
V_68 = V_269 ;
if ( ! V_68 )
V_68 = 1 ;
F_13 ( V_9 ,
L_28 ,
V_268 , V_269 , V_231 ) ;
}
V_275:
if ( V_68 == V_276 ) {
V_34 -> V_179 = 1 ;
V_6 -> V_181 = 1 ;
F_76 ( V_273 , & V_76 -> V_108 ) ;
}
V_271:
F_30 ( V_59 ) ;
return V_68 ;
}
int F_36 ( struct V_5 * V_6 , T_2 V_83 )
{
struct V_60 V_61 ;
struct V_27 * V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
int V_141 ;
if ( F_52 ( & V_61 , V_83 ) )
return - V_33 ;
V_141 = F_46 ( V_6 , & V_61 ) ;
if ( V_141 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_29 , V_83 ? L_30 : L_31 ,
V_141 ) ;
goto V_279;
}
V_83 = ( V_61 . V_68 . V_66 [ 0 ] & 0xff ) ;
if ( V_61 . V_68 . V_66 [ 0 ] >> 25 == 2 )
return 2 ;
if ( V_83 == V_164 )
F_73 ( V_253 , & V_28 -> V_172 ) ;
else
F_76 ( V_253 , & V_28 -> V_172 ) ;
V_279:
F_29 ( & V_61 ) ;
return V_141 ;
}
void F_130 ( struct V_280 * V_167 , T_3 V_281 )
{
struct V_5 * V_6 = F_131 ( V_167 ) ;
struct V_282 * V_283 ;
struct V_258 * V_284 , V_285 ;
F_14 ( & V_285 ) ;
V_284 = & V_6 -> V_157 ;
F_132 ( V_167 ) ;
while ( ! F_26 ( V_284 ) ) {
V_283 = F_117 ( V_284 -> V_286 , struct V_282 , V_63 ) ;
F_133 ( & V_283 -> V_63 , & V_285 ) ;
}
F_134 ( V_167 ) ;
while ( ! F_26 ( & V_285 ) ) {
V_283 = F_117 ( ( & V_285 ) -> V_286 ,
struct V_282 , V_63 ) ;
F_135 ( V_6 , V_283 -> V_287 , V_281 ) ;
F_28 ( & V_283 -> V_63 ) ;
F_23 ( V_283 ) ;
}
}
void F_33 ( struct V_21 * V_22 )
{
struct V_258 * V_284 = & V_22 -> V_41 ;
struct V_288 * V_289 ;
while ( ! F_26 ( V_284 ) ) {
V_289 = F_117 ( V_284 -> V_286 , struct V_288 ,
V_63 ) ;
F_34 ( & V_289 -> V_255 ) ;
F_28 ( & V_289 -> V_63 ) ;
F_23 ( V_289 ) ;
}
}
static void F_136 ( struct V_280 * V_167 )
{
struct V_5 * V_6 = F_131 ( V_167 ) ;
T_3 V_281 ;
if ( ! F_89 ( V_290 , & V_6 -> V_172 ) )
return;
V_281 = V_6 -> V_34 -> V_20 -> V_281 ;
F_137 ( V_167 , V_281 ) ;
}
static void F_138 ( struct V_254 * V_255 )
{
struct V_288 * V_289 ;
struct V_280 * V_167 ;
V_289 = F_107 ( V_255 , struct V_288 , V_255 ) ;
V_167 = (struct V_280 * ) V_289 -> V_262 ;
F_136 ( V_167 ) ;
return;
}
static struct V_288 *
F_139 ( struct V_21 * V_22 )
{
struct V_258 * V_259 ;
struct V_288 * V_289 = NULL ;
T_2 V_291 = 0 ;
F_116 (node, &bc->async_list) {
V_289 = F_117 ( V_259 , struct V_288 , V_63 ) ;
if ( ! F_140 ( & V_289 -> V_255 ) ) {
V_291 = 1 ;
break;
}
}
if ( ! V_291 ) {
V_289 = F_11 ( sizeof( struct V_288 ) ,
V_200 ) ;
if ( V_289 == NULL )
return NULL ;
F_111 ( & V_289 -> V_63 , & V_22 -> V_41 ) ;
}
return V_289 ;
}
static void F_141 ( struct V_21 * V_22 ,
T_4 V_231 , void * V_292 )
{
struct V_288 * V_289 = NULL ;
V_289 = F_139 ( V_22 ) ;
if ( ! V_289 )
return;
V_289 -> V_262 = V_292 ;
F_18 ( & V_289 -> V_255 , V_231 ) ;
F_90 ( V_22 -> V_40 , & V_289 -> V_255 ) ;
}
void F_142 ( struct V_280 * V_167 )
{
struct V_5 * V_6 = F_131 ( V_167 ) ;
struct V_21 * V_22 = & V_6 -> V_34 -> V_20 -> V_22 ;
if ( V_6 -> V_181 )
return;
F_141 ( V_22 , F_138 ,
V_167 ) ;
}
static int F_143 ( struct V_5 * V_6 )
{
int V_29 ;
V_6 -> V_181 = 0 ;
F_144 ( V_6 -> V_34 -> V_77 ) ;
F_145 ( V_6 ) ;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_6 , V_164 ) ;
if ( V_29 )
goto V_293;
V_29 = F_53 ( V_6 ) ;
if ( V_29 )
goto V_294;
F_146 ( V_6 -> V_156 ) ;
return 0 ;
V_294:
F_36 ( V_6 , V_70 ) ;
V_293:
F_37 ( V_6 , 0 ) ;
return V_29 ;
}
static void F_147 ( struct V_5 * V_6 )
{
struct V_280 * V_167 = V_6 -> V_167 ;
if ( F_148 ( V_167 ) ) {
if ( ! F_149 ( V_6 , V_167 ) )
F_150 ( V_167 , V_295 ) ;
}
F_151 ( V_167 ) ;
}
static void F_152 ( struct V_5 * V_6 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
struct V_296 * V_297 = V_34 -> V_297 ;
struct V_280 * V_167 = V_6 -> V_167 ;
T_2 V_30 , V_298 = V_34 -> V_299 - 1 ;
F_153 ( V_167 ) ;
F_154 ( V_6 ) ;
F_155 ( V_6 ) ;
if ( F_148 ( V_167 ) )
F_156 ( V_6 , V_167 ) ;
for ( V_30 = 0 ; V_30 < V_298 ; V_30 ++ ) {
V_297 [ V_30 ] . V_300 = V_30 ;
V_297 [ V_30 ] . V_301 = 0 ;
V_297 [ V_30 ] . V_302 = 0 ;
}
V_34 -> V_179 = 0 ;
}
static int F_157 ( struct V_5 * V_6 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
struct V_107 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_303 * V_170 = & V_34 -> V_170 ;
T_2 V_231 = V_34 -> V_42 ;
T_1 V_172 ;
if ( ( V_170 -> V_304 == V_305 ) ||
( V_170 -> V_304 == V_306 ) ) {
if ( ! F_143 ( V_6 ) ) {
F_147 ( V_6 ) ;
V_6 -> V_173 = 0 ;
F_21 ( V_9 ,
L_32 ,
V_87 , V_231 ) ;
} else {
F_13 ( V_9 ,
L_33 ,
V_87 , V_231 ) ;
V_172 = F_71 ( V_34 , V_175 ) ;
F_21 ( V_9 , L_34 ,
V_172 ) ;
}
}
return 0 ;
}
static int F_158 ( struct V_5 * V_6 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
struct V_75 * V_76 = V_34 -> V_77 ;
struct V_107 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_303 * V_170 = & V_34 -> V_170 ;
T_2 V_231 = V_34 -> V_42 ;
T_1 V_172 ;
V_6 -> V_307 ++ ;
if ( V_6 -> V_307 < 3 ) {
V_6 -> V_181 = 1 ;
F_76 ( V_273 , & V_76 -> V_108 ) ;
F_21 ( V_9 ,
L_35 ) ;
return 0 ;
}
if ( V_6 -> V_307 > V_308 ) {
F_76 ( V_177 , & V_170 -> V_108 ) ;
V_6 -> V_309 = 0 ;
V_6 -> V_173 = 0 ;
V_6 -> V_307 = 0 ;
F_152 ( V_6 ) ;
F_13 ( V_9 ,
L_36 ) ;
return - V_31 ;
}
F_21 ( V_9 , L_37 , V_231 ) ;
F_21 ( V_9 , L_38 ,
V_87 , V_6 -> V_307 , V_231 ) ;
F_73 ( V_185 , & V_6 -> V_172 ) ;
V_6 -> V_181 = 1 ;
F_76 ( V_273 , & V_76 -> V_108 ) ;
F_152 ( V_6 ) ;
V_6 -> V_181 = 0 ;
if ( ! F_143 ( V_6 ) ) {
F_147 ( V_6 ) ;
V_6 -> V_309 = 0 ;
V_6 -> V_307 = 0 ;
V_6 -> V_173 = 0 ;
F_21 ( V_9 , L_39 , V_231 ) ;
} else {
F_13 ( V_9 , L_40 ,
V_87 , V_231 ) ;
V_172 = F_71 ( V_34 , V_175 ) ;
F_21 ( V_9 , L_41 , V_87 , V_172 ) ;
}
return 0 ;
}
static int F_159 ( struct V_5 * V_6 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
int V_141 = 0 ;
if ( V_34 -> V_170 . V_304 != V_176 )
V_141 = F_157 ( V_6 ) ;
else if ( V_34 -> V_179 )
V_141 = F_158 ( V_6 ) ;
F_76 ( V_185 , & V_6 -> V_172 ) ;
return V_141 ;
}
static int F_160 ( struct V_5 * V_6 )
{
struct V_303 * V_170 = & V_6 -> V_34 -> V_170 ;
F_13 ( & V_6 -> V_10 -> V_9 , L_42 ) ;
if ( V_170 -> V_304 == V_176 )
F_152 ( V_6 ) ;
F_76 ( V_177 , & V_170 -> V_108 ) ;
F_76 ( V_185 , & V_6 -> V_172 ) ;
return - V_31 ;
}
static int
F_161 ( struct V_5 * V_6 )
{
struct V_75 * V_76 = V_6 -> V_34 -> V_77 ;
struct V_303 * V_170 = & V_6 -> V_34 -> V_170 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_43 ) ;
if ( V_170 -> V_304 == V_176 ) {
F_73 ( V_185 , & V_6 -> V_172 ) ;
V_6 -> V_309 = 0 ;
V_6 -> V_307 = 0 ;
F_76 ( V_273 , & V_76 -> V_108 ) ;
F_152 ( V_6 ) ;
}
return 0 ;
}
static int F_162 ( struct V_5 * V_6 )
{
struct V_75 * V_76 = V_6 -> V_34 -> V_77 ;
struct V_303 * V_170 = & V_6 -> V_34 -> V_170 ;
T_2 V_231 = V_6 -> V_34 -> V_42 ;
if ( V_170 -> V_304 == V_176 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_44 , V_231 ) ;
F_73 ( V_185 , & V_6 -> V_172 ) ;
V_6 -> V_309 = 0 ;
V_6 -> V_307 = 0 ;
F_76 ( V_273 , & V_76 -> V_108 ) ;
F_152 ( V_6 ) ;
}
return 0 ;
}
static int F_163 ( struct V_5 * V_6 )
{
F_13 ( & V_6 -> V_10 -> V_9 , L_45 , V_87 ) ;
return 0 ;
}
static void V_169 ( struct V_254 * V_255 )
{
struct V_5 * V_6 ;
struct V_303 * V_170 ;
int V_141 = 0 ;
V_6 = F_107 ( V_255 , struct V_5 , V_310 . V_255 ) ;
V_170 = & V_6 -> V_34 -> V_170 ;
V_170 -> V_311 = F_71 ( V_6 -> V_34 , V_175 ) ;
switch ( V_170 -> V_311 ) {
case V_176 :
V_141 = F_159 ( V_6 ) ;
break;
case V_305 :
case V_306 :
V_141 = F_162 ( V_6 ) ;
break;
case V_312 :
V_141 = F_161 ( V_6 ) ;
break;
case V_313 :
V_141 = F_160 ( V_6 ) ;
break;
case V_314 :
break;
default:
V_141 = F_163 ( V_6 ) ;
}
V_170 -> V_304 = V_170 -> V_311 ;
if ( ! V_141 && F_89 ( V_177 , & V_170 -> V_108 ) )
F_66 ( V_6 , V_169 ,
V_170 -> V_171 ) ;
}
static void F_164 ( struct V_5 * V_6 )
{
while ( F_87 ( V_185 , & V_6 -> V_172 ) )
F_70 ( 20 ) ;
F_76 ( V_177 , & V_6 -> V_34 -> V_170 . V_108 ) ;
F_76 ( V_185 , & V_6 -> V_172 ) ;
F_165 ( & V_6 -> V_310 ) ;
}
static int F_166 ( struct V_19 * V_20 ,
T_3 V_315 , T_2 V_264 )
{
T_3 V_281 = V_20 -> V_281 ;
T_2 V_316 = 0 ;
int V_30 ;
if ( V_20 -> V_143 != V_144 )
return - V_199 ;
if ( V_264 ) {
if ( V_281 )
return - V_199 ;
if ( V_20 -> V_138 ) {
for ( V_30 = 0 ; V_30 < V_20 -> V_139 ; V_30 ++ ) {
if ( V_20 -> V_137 [ V_30 ] == V_315 )
V_316 = 1 ;
}
if ( ! V_316 )
return - V_199 ;
}
} else {
if ( ! V_281 || V_281 != V_315 )
return - V_199 ;
}
return 0 ;
}
int F_167 ( struct V_5 * V_6 ,
T_3 V_315 , T_2 V_264 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_60 V_61 ;
int V_141 ;
if ( V_315 == 0 )
return 0 ;
V_141 = F_166 ( V_20 , V_315 , V_264 ) ;
if ( V_141 )
return V_141 ;
V_141 = F_52 ( & V_61 ,
V_317 ) ;
if ( V_141 )
return V_141 ;
V_61 . V_65 . V_66 [ 1 ] = ( V_264 & 1 ) | V_315 << 16 ;
F_33 ( & V_20 -> V_22 ) ;
V_141 = F_46 ( V_6 , & V_61 ) ;
if ( V_141 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_46 , V_141 ) ;
} else {
F_168 ( V_6 ) ;
if ( V_264 )
V_20 -> V_281 = V_315 ;
else
V_20 -> V_281 = 0 ;
F_136 ( V_6 -> V_167 ) ;
}
F_29 ( & V_61 ) ;
return V_141 ;
}
static void F_169 ( struct V_5 * V_6 )
{
struct V_258 * V_284 = & V_6 -> V_318 ;
struct V_282 * V_283 ;
T_3 V_281 ;
V_281 = V_6 -> V_34 -> V_20 -> V_281 ;
while ( ! F_26 ( V_284 ) ) {
V_283 = F_117 ( V_284 -> V_286 , struct V_282 , V_63 ) ;
F_170 ( V_6 , V_283 -> V_287 ,
V_281 , V_319 ) ;
F_28 ( & V_283 -> V_63 ) ;
F_23 ( V_283 ) ;
}
}
int F_171 ( struct V_8 * V_10 )
{
struct V_5 * V_6 = F_172 ( V_10 ) ;
struct V_280 * V_167 = V_6 -> V_167 ;
int V_320 ;
F_153 ( V_167 ) ;
F_173 ( V_6 ) ;
if ( F_148 ( V_167 ) )
F_156 ( V_6 , V_167 ) ;
F_36 ( V_6 , V_70 ) ;
F_37 ( V_6 , 0 ) ;
F_155 ( V_6 ) ;
F_165 ( & V_6 -> V_183 ) ;
V_320 = F_174 ( V_10 ) ;
if ( V_320 )
return V_320 ;
return 0 ;
}
int F_175 ( struct V_5 * V_6 )
{
struct V_303 * V_170 = & V_6 -> V_34 -> V_170 ;
struct V_280 * V_167 = V_6 -> V_167 ;
int V_29 ;
F_73 ( V_177 , & V_170 -> V_108 ) ;
F_145 ( V_6 ) ;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_6 , V_164 ) ;
if ( ! V_29 ) {
if ( F_148 ( V_167 ) ) {
V_29 = F_149 ( V_6 , V_167 ) ;
if ( ! V_29 )
F_150 ( V_167 , V_295 ) ;
}
}
F_151 ( V_167 ) ;
F_66 ( V_6 , V_169 ,
V_170 -> V_171 ) ;
return V_29 ;
}
