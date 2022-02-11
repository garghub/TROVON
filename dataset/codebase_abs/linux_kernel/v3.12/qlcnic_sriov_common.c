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
int V_29 ;
F_14 ( & V_6 -> V_155 ) ;
if ( ! V_156 && ! ! V_157 )
F_57 ( & V_6 -> V_10 -> V_9 ,
L_17 ) ;
V_29 = F_58 ( V_6 , 1 , 0 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_18 ) ;
goto V_158;
}
V_29 = F_59 ( V_6 ) ;
if ( V_29 )
goto V_158;
V_29 = F_9 ( V_6 , 1 ) ;
if ( V_29 )
goto V_159;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
goto V_160;
V_29 = F_36 ( V_6 , V_161 ) ;
if ( V_29 )
goto V_162;
V_29 = F_53 ( V_6 ) ;
if ( V_29 )
goto V_163;
if ( V_6 -> V_164 && F_60 ( V_6 ) )
F_61 ( V_6 ) ;
V_29 = F_62 ( V_6 , V_6 -> V_165 , V_154 ) ;
if ( V_29 )
goto V_163;
F_63 ( V_6 -> V_10 , V_6 ) ;
F_21 ( & V_6 -> V_10 -> V_9 , L_19 ,
V_6 -> V_165 -> V_166 ) ;
F_64 ( V_6 , V_167 ,
V_6 -> V_34 -> V_168 . V_169 ) ;
return 0 ;
V_163:
F_36 ( V_6 , V_70 ) ;
V_162:
F_37 ( V_6 , 0 ) ;
V_160:
F_32 ( V_6 ) ;
V_159:
F_65 ( V_6 ) ;
V_158:
F_66 ( V_6 ) ;
return V_29 ;
}
static int F_67 ( struct V_5 * V_6 )
{
T_1 V_170 ;
do {
F_68 ( 20 ) ;
if ( ++ V_6 -> V_171 > V_172 )
return - V_31 ;
V_170 = F_69 ( V_6 -> V_34 , V_173 ) ;
} while ( V_170 != V_174 );
return 0 ;
}
int F_70 ( struct V_5 * V_6 , int V_154 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
int V_29 ;
F_71 ( V_175 , & V_34 -> V_168 . V_108 ) ;
V_34 -> V_168 . V_169 = V_176 ;
V_34 -> V_177 = 0 ;
V_6 -> V_171 = 0 ;
V_34 -> V_178 = 1 ;
V_6 -> V_179 = 0 ;
V_6 -> V_62 |= V_180 ;
V_29 = F_67 ( V_6 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_56 ( V_6 , V_154 ) ;
if ( V_29 )
return V_29 ;
if ( F_72 ( V_6 ) )
F_57 ( & V_6 -> V_10 -> V_9 , L_20 ) ;
F_73 ( & V_6 -> V_181 , V_182 ) ;
F_74 ( V_183 , & V_6 -> V_170 ) ;
return 0 ;
}
void F_75 ( struct V_5 * V_6 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
V_34 -> V_88 = V_184 ;
F_21 ( & V_6 -> V_10 -> V_9 ,
L_21 ,
V_34 -> V_148 ) ;
V_6 -> V_185 = & V_186 ;
F_71 ( V_187 , & V_6 -> V_170 ) ;
return;
}
void F_76 ( struct V_74 * V_34 )
{
V_34 -> V_188 = & V_189 ;
V_34 -> V_190 = ( T_1 * ) V_191 ;
V_34 -> V_192 = ( T_1 * ) V_193 ;
}
static T_1 F_77 ( T_1 V_194 , T_2 V_195 )
{
T_1 V_79 ;
V_79 = V_194 / ( ( V_195 + 1 ) * V_196 ) ;
if ( V_79 )
V_79 = V_196 ;
else
V_79 = V_194 % V_196 ;
return V_79 ;
}
int F_78 ( struct V_5 * V_6 , T_2 V_42 )
{
struct V_27 * V_35 = V_6 -> V_34 -> V_20 -> V_35 ;
T_2 V_30 ;
if ( F_6 ( V_6 ) )
return 0 ;
for ( V_30 = 0 ; V_30 < V_6 -> V_34 -> V_20 -> V_18 ; V_30 ++ ) {
if ( V_35 [ V_30 ] . V_42 == V_42 )
return V_30 ;
}
return - V_197 ;
}
static inline int F_79 ( struct V_58 * * V_59 )
{
* V_59 = F_11 ( sizeof( struct V_58 ) , V_198 ) ;
if ( ! * V_59 )
return - V_33 ;
F_17 ( & ( * V_59 ) -> V_199 ) ;
return 0 ;
}
static inline int F_80 ( struct V_84 * * V_71 ,
T_1 V_73 )
{
* V_71 = F_11 ( sizeof( struct V_84 ) * V_73 , V_198 ) ;
if ( ! * V_71 )
return - V_33 ;
return 0 ;
}
static int F_52 ( struct V_60 * V_76 , T_1 type )
{
const struct V_200 * V_201 ;
int V_30 , V_73 ;
V_201 = V_202 ;
V_73 = F_81 ( V_202 ) ;
for ( V_30 = 0 ; V_30 < V_73 ; V_30 ++ ) {
if ( type == V_201 [ V_30 ] . V_61 ) {
V_76 -> V_81 = V_203 ;
V_76 -> V_65 . V_204 = V_201 [ V_30 ] . V_205 ;
V_76 -> V_68 . V_204 = V_201 [ V_30 ] . V_206 ;
V_76 -> V_65 . V_66 = F_82 ( V_76 -> V_65 . V_204 , sizeof( T_1 ) ,
V_198 ) ;
if ( ! V_76 -> V_65 . V_66 )
return - V_33 ;
V_76 -> V_68 . V_66 = F_82 ( V_76 -> V_68 . V_204 , sizeof( T_1 ) ,
V_198 ) ;
if ( ! V_76 -> V_68 . V_66 ) {
F_23 ( V_76 -> V_65 . V_66 ) ;
V_76 -> V_65 . V_66 = NULL ;
return - V_33 ;
}
memset ( V_76 -> V_65 . V_66 , 0 , sizeof( T_1 ) * V_76 -> V_65 . V_204 ) ;
memset ( V_76 -> V_68 . V_66 , 0 , sizeof( T_1 ) * V_76 -> V_68 . V_204 ) ;
V_76 -> V_65 . V_66 [ 0 ] = ( type | ( V_76 -> V_65 . V_204 << 16 ) |
( 3 << 29 ) ) ;
V_76 -> V_68 . V_66 [ 0 ] = ( type & 0xffff ) | V_76 -> V_68 . V_204 << 16 ;
return 0 ;
}
}
return - V_197 ;
}
static int F_83 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
T_3 V_207 , T_2 V_208 )
{
struct V_84 * V_71 ;
int V_30 ;
T_1 V_209 , V_210 ;
T_3 V_211 ;
T_2 V_83 , V_212 , V_213 ;
V_210 = V_196 ;
if ( V_208 == V_214 ) {
V_59 -> V_67 = (struct V_215 * ) V_61 -> V_65 . V_66 ;
V_59 -> V_69 = (struct V_215 * ) V_61 -> V_68 . V_66 ;
V_209 = V_61 -> V_65 . V_204 ;
V_59 -> V_216 = ( V_209 * 4 ) ;
V_209 = V_61 -> V_68 . V_204 ;
V_59 -> V_217 = ( V_209 * 4 ) ;
V_83 = V_61 -> V_65 . V_66 [ 0 ] & 0xff ;
V_211 = ( V_59 -> V_216 ) % ( V_210 ) ;
V_212 = ( V_59 -> V_216 ) / ( V_210 ) ;
if ( V_211 )
V_212 ++ ;
V_213 = V_212 ;
if ( F_80 ( & V_59 -> V_218 , V_212 ) )
return - V_33 ;
V_211 = ( V_59 -> V_217 ) % ( V_210 ) ;
V_212 = ( V_59 -> V_217 ) / ( V_210 ) ;
if ( V_211 )
V_212 ++ ;
if ( F_80 ( & V_59 -> V_219 , V_212 ) )
return - V_33 ;
V_212 = V_213 ;
V_71 = V_59 -> V_218 ;
} else {
V_61 -> V_65 . V_66 = ( T_1 * ) V_59 -> V_67 ;
V_61 -> V_68 . V_66 = ( T_1 * ) V_59 -> V_69 ;
V_83 = V_61 -> V_65 . V_66 [ 0 ] & 0xff ;
V_211 = ( V_59 -> V_217 ) % ( V_210 ) ;
V_212 = ( V_59 -> V_217 ) / ( V_210 ) ;
if ( V_211 )
V_212 ++ ;
V_61 -> V_65 . V_204 = V_59 -> V_216 / 4 ;
V_61 -> V_68 . V_204 = V_59 -> V_217 / 4 ;
V_71 = V_59 -> V_219 ;
V_61 -> V_81 = V_59 -> V_218 -> V_81 ;
}
V_59 -> V_220 = V_207 ;
V_59 -> V_221 = V_83 ;
for ( V_30 = 0 ; V_30 < V_212 ; V_30 ++ ) {
V_71 [ V_30 ] . V_222 = 2 ;
V_71 [ V_30 ] . V_208 = V_208 ;
V_71 [ V_30 ] . V_81 = V_61 -> V_81 ;
V_71 [ V_30 ] . V_223 = 1 ;
V_71 [ V_30 ] . V_212 = V_212 ;
V_71 [ V_30 ] . V_224 = V_30 + 1 ;
V_71 [ V_30 ] . V_83 = V_83 ;
V_71 [ V_30 ] . V_225 = V_207 ;
}
return 0 ;
}
static void F_30 ( struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_23 ( V_59 -> V_218 ) ;
F_23 ( V_59 -> V_219 ) ;
F_23 ( V_59 ) ;
}
static int F_84 ( struct V_27 * V_28 ,
struct V_58 * V_59 , T_2 type )
{
struct V_56 * V_57 ;
unsigned long V_62 ;
int V_141 = 0 ;
if ( type == V_226 ) {
V_57 = & V_28 -> V_44 ;
F_25 ( & V_57 -> V_47 , V_62 ) ;
V_57 -> V_64 -- ;
F_28 ( & V_59 -> V_63 ) ;
if ( V_57 -> V_64 > 0 )
V_141 = 1 ;
F_31 ( & V_57 -> V_47 , V_62 ) ;
}
if ( type == V_214 ) {
while ( F_85 ( V_227 , & V_28 -> V_170 ) )
F_68 ( 100 ) ;
V_28 -> V_228 = NULL ;
F_74 ( V_227 , & V_28 -> V_170 ) ;
}
return V_141 ;
}
static void F_86 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
T_4 V_229 )
{
if ( F_87 ( V_230 , & V_28 -> V_170 ) ||
V_28 -> V_6 -> V_179 )
return;
F_88 ( V_20 -> V_22 . V_38 , & V_28 -> V_49 ) ;
}
static inline void F_89 ( struct V_58 * V_59 )
{
struct V_89 * V_231 = & V_59 -> V_199 ;
if ( F_41 ( V_231 , V_232 ) )
V_59 -> V_233 = V_234 ;
else
V_59 -> V_233 = V_235 ;
return;
}
static void F_90 ( struct V_58 * V_59 ,
T_2 type )
{
if ( type == V_226 ) {
V_59 -> V_236 ++ ;
if ( V_59 -> V_236 < V_59 -> V_219 -> V_212 )
V_59 -> V_233 = V_237 ;
else
V_59 -> V_233 = V_234 ;
} else {
V_59 -> V_238 ++ ;
if ( V_59 -> V_238 < V_59 -> V_218 -> V_212 )
V_59 -> V_233 = V_237 ;
else
V_59 -> V_233 = V_239 ;
}
}
static void F_91 ( struct V_58 * V_59 ,
T_2 type )
{
struct V_27 * V_28 = V_59 -> V_28 ;
struct V_89 * V_231 = & V_28 -> V_48 ;
if ( ! F_41 ( V_231 , V_240 ) ) {
V_59 -> V_233 = V_235 ;
return;
}
F_74 ( V_241 , & V_28 -> V_170 ) ;
F_90 ( V_59 , type ) ;
}
static void F_92 ( struct V_5 * V_6 ,
T_1 * V_71 , T_1 * V_72 , T_1 V_73 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
T_1 V_242 ;
T_2 V_30 , V_243 = 2 , V_244 , V_245 ;
V_244 = ( sizeof( struct V_84 ) / sizeof( T_1 ) ) ;
V_243 = ( V_73 / sizeof( T_1 ) ) + V_244 ;
V_242 = F_93 ( F_94 ( V_34 , 0 ) ) ;
for ( V_30 = 2 , V_245 = 0 ; V_245 < V_244 ; V_30 ++ , V_245 ++ )
* ( V_71 ++ ) = F_93 ( F_94 ( V_34 , V_30 ) ) ;
for (; V_245 < V_243 ; V_30 ++ , V_245 ++ )
* ( V_72 ++ ) = F_93 ( F_94 ( V_34 , V_30 ) ) ;
}
static int F_95 ( struct V_27 * V_28 )
{
int V_141 = - V_246 ;
T_1 V_78 = 10000 ;
do {
if ( ! F_85 ( V_241 , & V_28 -> V_170 ) ) {
V_141 = 0 ;
break;
}
F_96 ( 1 ) ;
} while ( -- V_78 );
return V_141 ;
}
static int F_97 ( struct V_58 * V_59 , T_2 type )
{
struct V_27 * V_28 = V_59 -> V_28 ;
T_1 V_79 , V_244 ;
T_1 * V_71 , * V_72 ;
int V_141 ;
T_2 V_42 = V_59 -> V_247 ;
if ( F_95 ( V_28 ) )
return - V_246 ;
if ( type == V_214 ) {
V_71 = ( T_1 * ) ( V_59 -> V_218 + V_59 -> V_238 ) ;
V_72 = ( T_1 * ) ( V_59 -> V_67 + V_59 -> V_238 ) ;
V_244 = ( sizeof( struct V_84 ) / sizeof( T_1 ) ) ;
V_79 = F_77 ( V_59 -> V_216 ,
V_59 -> V_238 ) ;
V_79 = ( V_79 / sizeof( T_1 ) ) ;
} else {
V_71 = ( T_1 * ) ( V_59 -> V_219 + V_59 -> V_236 ) ;
V_72 = ( T_1 * ) ( V_59 -> V_69 + V_59 -> V_236 ) ;
V_244 = ( sizeof( struct V_84 ) / sizeof( T_1 ) ) ;
V_79 = F_77 ( V_59 -> V_217 ,
V_59 -> V_236 ) ;
V_79 = ( V_79 / sizeof( T_1 ) ) ;
}
V_141 = F_40 ( V_28 -> V_6 , V_71 , V_72 ,
V_42 , V_79 ) ;
return V_141 ;
}
static int F_98 ( struct V_58 * V_59 ,
struct V_27 * V_28 , T_2 type )
{
bool V_248 = true ;
int V_29 = - V_31 ;
while ( V_248 ) {
if ( F_87 ( V_230 , & V_28 -> V_170 ) ||
V_28 -> V_6 -> V_179 )
V_59 -> V_233 = V_235 ;
switch ( V_59 -> V_233 ) {
case V_237 :
V_59 -> V_233 = V_249 ;
if ( F_97 ( V_59 , type ) )
V_59 -> V_233 = V_235 ;
break;
case V_249 :
F_91 ( V_59 , type ) ;
break;
case V_239 :
F_89 ( V_59 ) ;
break;
case V_234 :
V_29 = 0 ;
V_248 = false ;
break;
case V_235 :
V_29 = - V_31 ;
V_248 = false ;
F_74 ( V_241 , & V_28 -> V_170 ) ;
break;
default:
V_29 = - V_31 ;
V_248 = false ;
}
}
return V_29 ;
}
static int F_99 ( struct V_5 * V_6 ,
struct V_58 * V_59 , int V_42 )
{
struct V_27 * V_28 ;
int V_29 , V_250 = F_78 ( V_6 , V_42 ) ;
if ( V_250 < 0 )
return - V_31 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ V_250 ] ;
V_59 -> V_28 = V_28 ;
V_59 -> V_247 = V_42 ;
if ( ! F_87 ( V_251 , & V_28 -> V_170 ) ) {
if ( F_19 ( V_6 ) )
return - V_31 ;
if ( F_6 ( V_6 ) &&
V_59 -> V_221 != V_161 )
return - V_31 ;
}
F_100 ( & V_28 -> V_43 ) ;
V_28 -> V_228 = V_59 ;
V_29 = F_98 ( V_59 , V_28 , V_214 ) ;
F_84 ( V_28 , V_59 , V_214 ) ;
F_101 ( & V_28 -> V_43 ) ;
return V_29 ;
}
static void F_102 ( struct V_5 * V_6 ,
struct V_58 * V_59 ,
struct V_60 * V_61 )
{
#ifdef F_103
if ( F_19 ( V_6 ) ) {
F_104 ( V_6 , V_59 , V_61 ) ;
return;
}
#endif
V_61 -> V_68 . V_66 [ 0 ] |= ( 0x9 << 25 ) ;
return;
}
static void V_50 ( struct V_252 * V_253 )
{
struct V_27 * V_28 = F_105 ( V_253 , struct V_27 ,
V_49 ) ;
struct V_58 * V_59 = NULL ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_60 V_61 ;
T_2 V_65 ;
if ( V_6 -> V_179 )
return;
if ( F_87 ( V_230 , & V_28 -> V_170 ) )
return;
memset ( & V_61 , 0 , sizeof( struct V_60 ) ) ;
V_59 = F_27 ( & V_28 -> V_44 . V_45 ,
struct V_58 , V_63 ) ;
V_6 = V_28 -> V_6 ;
if ( F_83 ( V_59 , & V_61 , V_59 -> V_218 -> V_225 ,
V_226 ) )
goto V_254;
F_102 ( V_6 , V_59 , & V_61 ) ;
V_59 -> V_233 = V_237 ;
F_98 ( V_59 , V_28 , V_226 ) ;
V_254:
F_29 ( & V_61 ) ;
V_65 = F_84 ( V_28 , V_59 , V_226 ) ;
F_30 ( V_59 ) ;
if ( V_65 )
F_86 ( V_6 -> V_34 -> V_20 , V_28 ,
V_50 ) ;
}
static void F_106 ( struct V_84 * V_71 ,
struct V_27 * V_28 )
{
struct V_58 * V_59 ;
T_1 V_79 ;
if ( F_85 ( V_227 , & V_28 -> V_170 ) )
return;
V_59 = V_28 -> V_228 ;
if ( V_59 == NULL )
goto V_255;
if ( V_59 -> V_220 != V_71 -> V_225 )
goto V_255;
V_79 = F_77 ( V_59 -> V_217 ,
V_59 -> V_236 ) ;
F_92 ( V_28 -> V_6 ,
( T_1 * ) ( V_59 -> V_219 + V_59 -> V_236 ) ,
( T_1 * ) ( V_59 -> V_69 + V_59 -> V_236 ) ,
V_79 ) ;
if ( ++ V_59 -> V_236 < V_59 -> V_219 -> V_212 )
goto V_255;
F_107 ( & V_59 -> V_199 ) ;
V_255:
F_74 ( V_227 , & V_28 -> V_170 ) ;
}
int F_108 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_58 * V_59 )
{
struct V_56 * V_57 = & V_28 -> V_44 ;
V_57 -> V_64 ++ ;
F_109 ( & V_59 -> V_63 , & V_57 -> V_45 ) ;
if ( V_57 -> V_64 == 1 )
F_86 ( V_20 , V_28 ,
V_50 ) ;
return 0 ;
}
static int F_110 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_58 * V_59 )
{
struct V_56 * V_57 = & V_28 -> V_44 ;
F_111 ( & V_57 -> V_47 ) ;
F_108 ( V_20 , V_28 , V_59 ) ;
F_112 ( & V_57 -> V_47 ) ;
return 0 ;
}
static void F_113 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_84 * V_71 )
{
struct V_58 * V_59 = NULL ;
struct V_256 * V_257 ;
T_1 V_79 , V_195 ;
T_2 V_258 = 0 , V_259 = 0 ;
F_111 ( & V_28 -> V_46 . V_47 ) ;
if ( V_28 -> V_46 . V_64 > 0 ) {
F_114 (node, &vf->rcv_pend.wait_list) {
V_59 = F_115 ( V_257 , struct V_58 , V_63 ) ;
if ( V_59 -> V_220 == V_71 -> V_225 ) {
V_258 = 1 ;
break;
}
}
}
if ( V_258 ) {
V_195 = V_59 -> V_238 ;
V_79 = F_77 ( V_59 -> V_216 ,
V_195 ) ;
F_92 ( V_28 -> V_6 ,
( T_1 * ) ( V_59 -> V_218 + V_195 ) ,
( T_1 * ) ( V_59 -> V_67 + V_195 ) ,
V_79 ) ;
V_59 -> V_238 ++ ;
if ( V_59 -> V_238 >= V_71 -> V_212 ) {
V_28 -> V_46 . V_64 -- ;
F_28 ( & V_59 -> V_63 ) ;
V_259 = 1 ;
}
}
F_112 ( & V_28 -> V_46 . V_47 ) ;
if ( V_259 )
if ( F_110 ( V_20 , V_28 , V_59 ) )
F_30 ( V_59 ) ;
return;
}
static void F_116 ( struct V_19 * V_20 ,
struct V_84 * V_71 ,
struct V_27 * V_28 )
{
struct V_58 * V_59 ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_60 V_61 ;
T_1 V_79 ;
int V_29 ;
T_2 V_83 ;
if ( V_6 -> V_179 )
return;
if ( ! F_87 ( V_251 , & V_28 -> V_170 ) &&
V_71 -> V_81 != V_203 &&
V_71 -> V_83 != V_161 )
return;
if ( V_71 -> V_224 > 1 ) {
F_113 ( V_20 , V_28 , V_71 ) ;
return;
}
memset ( & V_61 , 0 , sizeof( struct V_60 ) ) ;
V_83 = V_71 -> V_83 ;
if ( F_79 ( & V_59 ) )
return;
if ( V_71 -> V_81 == V_203 )
V_29 = F_52 ( & V_61 , V_83 ) ;
else
V_29 = F_45 ( & V_61 , V_6 , V_83 ) ;
if ( V_29 ) {
F_30 ( V_59 ) ;
return;
}
V_61 . V_81 = V_71 -> V_81 ;
if ( F_83 ( V_59 , & V_61 , V_71 -> V_225 ,
V_214 ) ) {
F_29 ( & V_61 ) ;
F_30 ( V_59 ) ;
return;
}
V_79 = F_77 ( V_59 -> V_216 ,
V_59 -> V_238 ) ;
F_92 ( V_28 -> V_6 ,
( T_1 * ) ( V_59 -> V_218 + V_59 -> V_238 ) ,
( T_1 * ) ( V_59 -> V_67 + V_59 -> V_238 ) ,
V_79 ) ;
V_59 -> V_247 = V_28 -> V_42 ;
V_59 -> V_28 = V_28 ;
V_59 -> V_220 = V_71 -> V_225 ;
V_59 -> V_238 ++ ;
if ( F_117 ( V_6 , V_59 , V_28 ) )
return;
if ( V_59 -> V_238 == V_59 -> V_218 -> V_212 ) {
if ( F_110 ( V_20 , V_28 , V_59 ) ) {
F_29 ( & V_61 ) ;
F_30 ( V_59 ) ;
}
} else {
F_111 ( & V_28 -> V_46 . V_47 ) ;
F_109 ( & V_59 -> V_63 , & V_28 -> V_46 . V_45 ) ;
V_28 -> V_46 . V_64 ++ ;
F_112 ( & V_28 -> V_46 . V_47 ) ;
}
}
static void F_118 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
struct V_84 V_71 ;
T_1 * V_260 = ( T_1 * ) & V_71 ;
T_2 V_208 , V_30 ;
for ( V_30 = 2 ; V_30 < 6 ; V_30 ++ )
V_260 [ V_30 - 2 ] = F_93 ( F_94 ( V_28 -> V_6 -> V_34 , V_30 ) ) ;
V_208 = V_71 . V_208 ;
switch ( V_208 ) {
case V_214 :
F_116 ( V_20 , & V_71 , V_28 ) ;
break;
case V_226 :
F_106 ( & V_71 , V_28 ) ;
break;
}
}
static void F_119 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_28 -> V_6 ;
if ( F_19 ( V_6 ) )
F_120 ( V_20 , V_28 ) ;
else
F_13 ( & V_6 -> V_10 -> V_9 ,
L_22 ) ;
}
void F_121 ( struct V_5 * V_6 , T_1 V_261 )
{
struct V_27 * V_28 ;
struct V_19 * V_20 ;
int V_250 ;
T_2 V_42 ;
V_20 = V_6 -> V_34 -> V_20 ;
V_42 = F_4 ( V_261 ) ;
V_250 = F_78 ( V_6 , V_42 ) ;
if ( V_250 < 0 )
return;
V_28 = & V_20 -> V_35 [ V_250 ] ;
V_28 -> V_42 = V_42 ;
if ( F_2 ( V_261 ) )
F_107 ( & V_28 -> V_48 ) ;
if ( F_3 ( V_261 ) ) {
F_119 ( V_20 , V_28 ) ;
return;
}
if ( F_1 ( V_261 ) )
F_118 ( V_20 , V_28 ) ;
}
int F_37 ( struct V_5 * V_6 , T_2 V_262 )
{
struct V_60 V_61 ;
int V_29 ;
if ( ! F_87 ( V_187 , & V_6 -> V_170 ) )
return 0 ;
if ( F_45 ( & V_61 , V_6 , V_263 ) )
return - V_33 ;
if ( V_262 )
V_61 . V_65 . V_66 [ 1 ] = ( 1 << 4 ) | ( 1 << 5 ) | ( 1 << 6 ) | ( 1 << 7 ) ;
V_29 = F_122 ( V_6 , & V_61 ) ;
if ( V_29 != V_264 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_23 ,
( V_262 ? L_24 : L_25 ) , V_29 ) ;
}
F_29 ( & V_61 ) ;
return V_29 ;
}
static int F_123 ( struct V_5 * V_6 ,
struct V_58 * V_59 )
{
T_2 V_243 = V_172 ;
T_1 V_170 ;
V_170 = F_69 ( V_6 -> V_34 , V_173 ) ;
if ( V_170 == V_174 ) {
F_68 ( 20 ) ;
F_74 ( V_241 , & V_59 -> V_28 -> V_170 ) ;
V_59 -> V_233 = V_237 ;
if ( ++ V_6 -> V_171 > V_243 )
return - V_31 ;
else
return 0 ;
}
return - V_31 ;
}
static int F_124 ( struct V_5 * V_6 ,
struct V_60 * V_61 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
struct V_75 * V_76 = V_34 -> V_77 ;
struct V_107 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_58 * V_59 ;
int V_29 ;
T_1 V_265 , V_266 , V_267 , V_68 ;
T_3 V_207 = ++ V_6 -> V_34 -> V_20 -> V_22 . V_268 ;
T_2 V_229 = V_34 -> V_42 ;
V_68 = F_79 ( & V_59 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_83 ( V_59 , V_61 , V_207 , V_214 ) ;
if ( V_68 )
goto V_269;
V_270:
if ( ! F_87 ( V_271 , & V_76 -> V_108 ) ) {
V_68 = - V_31 ;
F_125 ( V_6 , V_272 , L_26 ,
F_126 ( V_61 -> V_65 . V_66 [ 0 ] ) , V_229 ) ;
goto V_273;
}
V_29 = F_99 ( V_6 , V_59 , V_229 ) ;
if ( V_29 ) {
F_13 ( V_9 , L_27 ,
( V_61 -> V_65 . V_66 [ 0 ] & 0xffff ) , V_229 ) ;
V_68 = V_274 ;
if ( ( V_59 -> V_218 -> V_83 == V_161 ) &&
! F_123 ( V_6 , V_59 ) )
goto V_270;
goto V_273;
}
V_265 = V_61 -> V_68 . V_66 [ 0 ] ;
V_267 = F_127 ( V_265 ) ;
V_266 = F_126 ( V_61 -> V_65 . V_66 [ 0 ] ) ;
if ( ( V_267 == V_275 ) ||
( V_267 == V_276 ) ) {
V_68 = V_264 ;
} else {
V_68 = V_267 ;
if ( ! V_68 )
V_68 = 1 ;
F_13 ( V_9 ,
L_28 ,
V_266 , V_267 , V_229 ) ;
}
V_273:
if ( V_68 == V_274 ) {
V_34 -> V_177 = 1 ;
V_6 -> V_179 = 1 ;
F_74 ( V_271 , & V_76 -> V_108 ) ;
}
V_269:
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
goto V_277;
}
V_83 = ( V_61 . V_68 . V_66 [ 0 ] & 0xff ) ;
if ( V_61 . V_68 . V_66 [ 0 ] >> 25 == 2 )
return 2 ;
if ( V_83 == V_161 )
F_71 ( V_251 , & V_28 -> V_170 ) ;
else
F_74 ( V_251 , & V_28 -> V_170 ) ;
V_277:
F_29 ( & V_61 ) ;
return V_141 ;
}
void F_128 ( struct V_278 * V_165 , T_3 V_279 )
{
struct V_5 * V_6 = F_129 ( V_165 ) ;
struct V_280 * V_281 ;
struct V_256 * V_282 , V_283 ;
F_14 ( & V_283 ) ;
V_282 = & V_6 -> V_155 ;
F_130 ( V_165 ) ;
while ( ! F_26 ( V_282 ) ) {
V_281 = F_115 ( V_282 -> V_284 , struct V_280 , V_63 ) ;
F_131 ( & V_281 -> V_63 , & V_283 ) ;
}
F_132 ( V_165 ) ;
while ( ! F_26 ( & V_283 ) ) {
V_281 = F_115 ( ( & V_283 ) -> V_284 ,
struct V_280 , V_63 ) ;
F_133 ( V_6 , V_281 -> V_285 , V_279 ) ;
F_28 ( & V_281 -> V_63 ) ;
F_23 ( V_281 ) ;
}
}
void F_33 ( struct V_21 * V_22 )
{
struct V_256 * V_282 = & V_22 -> V_41 ;
struct V_286 * V_287 ;
while ( ! F_26 ( V_282 ) ) {
V_287 = F_115 ( V_282 -> V_284 , struct V_286 ,
V_63 ) ;
F_34 ( & V_287 -> V_253 ) ;
F_28 ( & V_287 -> V_63 ) ;
F_23 ( V_287 ) ;
}
}
static void F_134 ( struct V_278 * V_165 )
{
struct V_5 * V_6 = F_129 ( V_165 ) ;
T_3 V_279 ;
if ( ! F_87 ( V_288 , & V_6 -> V_170 ) )
return;
V_279 = V_6 -> V_34 -> V_20 -> V_279 ;
F_135 ( V_165 , V_279 ) ;
}
static void F_136 ( struct V_252 * V_253 )
{
struct V_286 * V_287 ;
struct V_278 * V_165 ;
V_287 = F_105 ( V_253 , struct V_286 , V_253 ) ;
V_165 = (struct V_278 * ) V_287 -> V_260 ;
F_134 ( V_165 ) ;
return;
}
static struct V_286 *
F_137 ( struct V_21 * V_22 )
{
struct V_256 * V_257 ;
struct V_286 * V_287 = NULL ;
T_2 V_289 = 0 ;
F_114 (node, &bc->async_list) {
V_287 = F_115 ( V_257 , struct V_286 , V_63 ) ;
if ( ! F_138 ( & V_287 -> V_253 ) ) {
V_289 = 1 ;
break;
}
}
if ( ! V_289 ) {
V_287 = F_11 ( sizeof( struct V_286 ) ,
V_198 ) ;
if ( V_287 == NULL )
return NULL ;
F_109 ( & V_287 -> V_63 , & V_22 -> V_41 ) ;
}
return V_287 ;
}
static void F_139 ( struct V_21 * V_22 ,
T_4 V_229 , void * V_290 )
{
struct V_286 * V_287 = NULL ;
V_287 = F_137 ( V_22 ) ;
if ( ! V_287 )
return;
V_287 -> V_260 = V_290 ;
F_18 ( & V_287 -> V_253 , V_229 ) ;
F_88 ( V_22 -> V_40 , & V_287 -> V_253 ) ;
}
void F_140 ( struct V_278 * V_165 )
{
struct V_5 * V_6 = F_129 ( V_165 ) ;
struct V_21 * V_22 = & V_6 -> V_34 -> V_20 -> V_22 ;
if ( V_6 -> V_179 )
return;
F_139 ( V_22 , F_136 ,
V_165 ) ;
}
static int F_141 ( struct V_5 * V_6 )
{
int V_29 ;
V_6 -> V_179 = 0 ;
F_142 ( V_6 -> V_34 -> V_77 ) ;
F_143 ( V_6 ) ;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_6 , V_161 ) ;
if ( V_29 )
goto V_291;
V_29 = F_53 ( V_6 ) ;
if ( V_29 )
goto V_292;
F_144 ( V_6 ) ;
return 0 ;
V_292:
F_36 ( V_6 , V_70 ) ;
V_291:
F_37 ( V_6 , 0 ) ;
return V_29 ;
}
static void F_145 ( struct V_5 * V_6 )
{
struct V_278 * V_165 = V_6 -> V_165 ;
if ( F_146 ( V_165 ) ) {
if ( ! F_147 ( V_6 , V_165 ) )
F_148 ( V_165 , V_293 ) ;
}
F_149 ( V_165 ) ;
}
static void F_150 ( struct V_5 * V_6 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
struct V_294 * V_295 = V_34 -> V_295 ;
struct V_278 * V_165 = V_6 -> V_165 ;
T_2 V_30 , V_296 = V_34 -> V_297 - 1 ;
F_151 ( V_165 ) ;
F_152 ( V_6 ) ;
F_153 ( V_6 ) ;
if ( F_146 ( V_165 ) )
F_154 ( V_6 , V_165 ) ;
for ( V_30 = 0 ; V_30 < V_296 ; V_30 ++ ) {
V_295 [ V_30 ] . V_298 = V_30 ;
V_295 [ V_30 ] . V_299 = 0 ;
V_295 [ V_30 ] . V_300 = 0 ;
}
V_34 -> V_177 = 0 ;
}
static int F_155 ( struct V_5 * V_6 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
struct V_107 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_301 * V_168 = & V_34 -> V_168 ;
T_2 V_229 = V_34 -> V_42 ;
T_1 V_170 ;
if ( ( V_168 -> V_302 == V_303 ) ||
( V_168 -> V_302 == V_304 ) ) {
if ( ! F_141 ( V_6 ) ) {
F_145 ( V_6 ) ;
V_6 -> V_171 = 0 ;
F_21 ( V_9 ,
L_32 ,
V_87 , V_229 ) ;
} else {
F_13 ( V_9 ,
L_33 ,
V_87 , V_229 ) ;
V_170 = F_69 ( V_34 , V_173 ) ;
F_21 ( V_9 , L_34 ,
V_170 ) ;
}
}
return 0 ;
}
static int F_156 ( struct V_5 * V_6 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
struct V_75 * V_76 = V_34 -> V_77 ;
struct V_107 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_301 * V_168 = & V_34 -> V_168 ;
T_2 V_229 = V_34 -> V_42 ;
T_1 V_170 ;
V_6 -> V_305 ++ ;
if ( V_6 -> V_305 < 3 ) {
V_6 -> V_179 = 1 ;
F_74 ( V_271 , & V_76 -> V_108 ) ;
F_21 ( V_9 ,
L_35 ) ;
return 0 ;
}
if ( V_6 -> V_305 > V_306 ) {
F_74 ( V_175 , & V_168 -> V_108 ) ;
V_6 -> V_307 = 0 ;
V_6 -> V_171 = 0 ;
V_6 -> V_305 = 0 ;
F_150 ( V_6 ) ;
F_13 ( V_9 ,
L_36 ) ;
return - V_31 ;
}
F_21 ( V_9 , L_37 , V_229 ) ;
F_21 ( V_9 , L_38 ,
V_87 , V_6 -> V_305 , V_229 ) ;
F_71 ( V_183 , & V_6 -> V_170 ) ;
V_6 -> V_179 = 1 ;
F_74 ( V_271 , & V_76 -> V_108 ) ;
F_150 ( V_6 ) ;
V_6 -> V_179 = 0 ;
if ( ! F_141 ( V_6 ) ) {
F_145 ( V_6 ) ;
V_6 -> V_307 = 0 ;
V_6 -> V_305 = 0 ;
V_6 -> V_171 = 0 ;
F_21 ( V_9 , L_39 , V_229 ) ;
} else {
F_13 ( V_9 , L_40 ,
V_87 , V_229 ) ;
V_170 = F_69 ( V_34 , V_173 ) ;
F_21 ( V_9 , L_41 , V_87 , V_170 ) ;
}
return 0 ;
}
static int F_157 ( struct V_5 * V_6 )
{
struct V_74 * V_34 = V_6 -> V_34 ;
int V_141 = 0 ;
if ( V_34 -> V_168 . V_302 != V_174 )
V_141 = F_155 ( V_6 ) ;
else if ( V_34 -> V_177 )
V_141 = F_156 ( V_6 ) ;
F_74 ( V_183 , & V_6 -> V_170 ) ;
return V_141 ;
}
static int F_158 ( struct V_5 * V_6 )
{
struct V_301 * V_168 = & V_6 -> V_34 -> V_168 ;
F_13 ( & V_6 -> V_10 -> V_9 , L_42 ) ;
if ( V_168 -> V_302 == V_174 )
F_150 ( V_6 ) ;
F_74 ( V_175 , & V_168 -> V_108 ) ;
F_74 ( V_183 , & V_6 -> V_170 ) ;
return - V_31 ;
}
static int
F_159 ( struct V_5 * V_6 )
{
struct V_75 * V_76 = V_6 -> V_34 -> V_77 ;
struct V_301 * V_168 = & V_6 -> V_34 -> V_168 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_43 ) ;
if ( V_168 -> V_302 == V_174 ) {
F_71 ( V_183 , & V_6 -> V_170 ) ;
V_6 -> V_307 = 0 ;
V_6 -> V_305 = 0 ;
F_74 ( V_271 , & V_76 -> V_108 ) ;
F_150 ( V_6 ) ;
}
return 0 ;
}
static int F_160 ( struct V_5 * V_6 )
{
struct V_75 * V_76 = V_6 -> V_34 -> V_77 ;
struct V_301 * V_168 = & V_6 -> V_34 -> V_168 ;
T_2 V_229 = V_6 -> V_34 -> V_42 ;
if ( V_168 -> V_302 == V_174 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_44 , V_229 ) ;
F_71 ( V_183 , & V_6 -> V_170 ) ;
V_6 -> V_307 = 0 ;
V_6 -> V_305 = 0 ;
F_74 ( V_271 , & V_76 -> V_108 ) ;
F_150 ( V_6 ) ;
}
return 0 ;
}
static int F_161 ( struct V_5 * V_6 )
{
F_13 ( & V_6 -> V_10 -> V_9 , L_45 , V_87 ) ;
return 0 ;
}
static void V_167 ( struct V_252 * V_253 )
{
struct V_5 * V_6 ;
struct V_301 * V_168 ;
int V_141 = 0 ;
V_6 = F_105 ( V_253 , struct V_5 , V_308 . V_253 ) ;
V_168 = & V_6 -> V_34 -> V_168 ;
V_168 -> V_309 = F_69 ( V_6 -> V_34 , V_173 ) ;
switch ( V_168 -> V_309 ) {
case V_174 :
V_141 = F_157 ( V_6 ) ;
break;
case V_303 :
case V_304 :
V_141 = F_160 ( V_6 ) ;
break;
case V_310 :
V_141 = F_159 ( V_6 ) ;
break;
case V_311 :
V_141 = F_158 ( V_6 ) ;
break;
case V_312 :
break;
default:
V_141 = F_161 ( V_6 ) ;
}
V_168 -> V_302 = V_168 -> V_309 ;
if ( ! V_141 && F_87 ( V_175 , & V_168 -> V_108 ) )
F_64 ( V_6 , V_167 ,
V_168 -> V_169 ) ;
}
static void F_162 ( struct V_5 * V_6 )
{
while ( F_85 ( V_183 , & V_6 -> V_170 ) )
F_68 ( 20 ) ;
F_74 ( V_175 , & V_6 -> V_34 -> V_168 . V_108 ) ;
F_74 ( V_183 , & V_6 -> V_170 ) ;
F_163 ( & V_6 -> V_308 ) ;
}
static int F_164 ( struct V_19 * V_20 ,
T_3 V_313 , T_2 V_262 )
{
T_3 V_279 = V_20 -> V_279 ;
T_2 V_314 = 0 ;
int V_30 ;
if ( V_20 -> V_143 != V_144 )
return - V_197 ;
if ( V_262 ) {
if ( V_279 )
return - V_197 ;
if ( V_20 -> V_138 ) {
for ( V_30 = 0 ; V_30 < V_20 -> V_139 ; V_30 ++ ) {
if ( V_20 -> V_137 [ V_30 ] == V_313 )
V_314 = 1 ;
}
if ( ! V_314 )
return - V_197 ;
}
} else {
if ( ! V_279 || V_279 != V_313 )
return - V_197 ;
}
return 0 ;
}
int F_165 ( struct V_5 * V_6 ,
T_3 V_313 , T_2 V_262 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_60 V_61 ;
int V_141 ;
if ( V_313 == 0 )
return 0 ;
V_141 = F_164 ( V_20 , V_313 , V_262 ) ;
if ( V_141 )
return V_141 ;
V_141 = F_52 ( & V_61 ,
V_315 ) ;
if ( V_141 )
return V_141 ;
V_61 . V_65 . V_66 [ 1 ] = ( V_262 & 1 ) | V_313 << 16 ;
F_33 ( & V_20 -> V_22 ) ;
V_141 = F_46 ( V_6 , & V_61 ) ;
if ( V_141 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_46 , V_141 ) ;
} else {
F_166 ( V_6 ) ;
if ( V_262 )
V_20 -> V_279 = V_313 ;
else
V_20 -> V_279 = 0 ;
F_134 ( V_6 -> V_165 ) ;
}
F_29 ( & V_61 ) ;
return V_141 ;
}
static void F_167 ( struct V_5 * V_6 )
{
struct V_256 * V_282 = & V_6 -> V_316 ;
struct V_280 * V_281 ;
T_3 V_279 ;
V_279 = V_6 -> V_34 -> V_20 -> V_279 ;
while ( ! F_26 ( V_282 ) ) {
V_281 = F_115 ( V_282 -> V_284 , struct V_280 , V_63 ) ;
F_168 ( V_6 , V_281 -> V_285 ,
V_279 , V_317 ) ;
F_28 ( & V_281 -> V_63 ) ;
F_23 ( V_281 ) ;
}
}
int F_169 ( struct V_8 * V_10 )
{
struct V_5 * V_6 = F_170 ( V_10 ) ;
struct V_278 * V_165 = V_6 -> V_165 ;
int V_318 ;
F_151 ( V_165 ) ;
F_171 ( V_6 ) ;
if ( F_146 ( V_165 ) )
F_154 ( V_6 , V_165 ) ;
F_36 ( V_6 , V_70 ) ;
F_37 ( V_6 , 0 ) ;
F_153 ( V_6 ) ;
F_163 ( & V_6 -> V_181 ) ;
V_318 = F_172 ( V_10 ) ;
if ( V_318 )
return V_318 ;
return 0 ;
}
int F_173 ( struct V_5 * V_6 )
{
struct V_301 * V_168 = & V_6 -> V_34 -> V_168 ;
struct V_278 * V_165 = V_6 -> V_165 ;
int V_29 ;
F_71 ( V_175 , & V_168 -> V_108 ) ;
F_143 ( V_6 ) ;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_6 , V_161 ) ;
if ( ! V_29 ) {
if ( F_146 ( V_165 ) ) {
V_29 = F_147 ( V_6 , V_165 ) ;
if ( ! V_29 )
F_148 ( V_165 , V_293 ) ;
}
}
F_149 ( V_165 ) ;
F_64 ( V_6 , V_167 ,
V_168 -> V_169 ) ;
return V_29 ;
}
