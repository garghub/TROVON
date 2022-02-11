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
F_15 ( & V_28 -> V_44 ) ;
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
V_26 -> V_55 = true ;
F_20 ( V_26 -> V_56 ) ;
F_21 ( & V_6 -> V_10 -> V_9 ,
L_5 ,
V_26 -> V_56 , V_30 ) ;
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
void F_24 ( struct V_57 * V_58 )
{
struct V_59 * V_60 ;
struct V_61 V_62 ;
unsigned long V_63 ;
F_25 ( & V_58 -> V_48 , V_63 ) ;
while ( ! F_26 ( & V_58 -> V_46 ) ) {
V_60 = F_27 ( & V_58 -> V_46 ,
struct V_59 , V_64 ) ;
F_28 ( & V_60 -> V_64 ) ;
V_58 -> V_65 -- ;
V_62 . V_66 . V_67 = ( T_1 * ) V_60 -> V_68 ;
V_62 . V_69 . V_67 = ( T_1 * ) V_60 -> V_70 ;
F_29 ( & V_62 ) ;
F_30 ( V_60 ) ;
}
F_31 ( & V_58 -> V_48 , V_63 ) ;
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
F_36 ( V_6 , V_71 ) ;
F_37 ( V_6 , 0 ) ;
F_32 ( V_6 ) ;
}
void F_38 ( struct V_5 * V_6 )
{
if ( ! F_39 ( V_72 , & V_6 -> V_73 ) )
return;
F_40 ( V_6 ) ;
if ( F_19 ( V_6 ) )
F_41 ( V_6 ) ;
if ( F_6 ( V_6 ) )
F_35 ( V_6 ) ;
}
static int F_42 ( struct V_5 * V_6 , T_1 * V_74 ,
T_1 * V_75 , T_2 V_42 , T_2 V_76 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
struct V_78 * V_79 = V_34 -> V_80 ;
struct V_61 V_62 ;
unsigned long V_81 ;
int V_29 ;
memset ( & V_62 , 0 , sizeof( struct V_61 ) ) ;
V_62 . V_74 = V_74 ;
V_62 . V_75 = V_75 ;
V_62 . V_82 = V_76 ;
V_62 . V_83 = V_42 ;
V_62 . V_84 = V_85 ;
V_62 . V_86 = ( (struct V_87 * ) V_74 ) -> V_86 ;
V_29 = V_79 -> V_88 -> V_89 ( V_6 , & V_62 , & V_81 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_6 ,
V_90 , V_62 . V_86 , V_62 . type , V_34 -> V_42 ,
V_34 -> V_91 ) ;
return V_29 ;
}
if ( ! F_43 ( & V_62 . V_92 , V_81 ) ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_7 ,
V_90 , V_62 . V_86 , V_62 . type , V_34 -> V_42 ,
V_34 -> V_91 ) ;
F_44 ( V_79 -> V_93 ) ;
}
return V_62 . V_94 ;
}
static void F_45 ( struct V_5 * V_6 )
{
V_6 -> V_95 = V_96 ;
V_6 -> V_97 = V_98 ;
V_6 -> V_99 = V_100 ;
V_6 -> V_101 = V_102 ;
V_6 -> V_103 = V_104 ;
V_6 -> V_105 = V_106 ;
}
int F_46 ( struct V_5 * V_6 ,
struct V_107 * V_108 , T_3 V_109 )
{
struct V_110 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_61 V_62 ;
int V_29 ;
T_1 V_111 ;
V_29 = F_47 ( & V_62 , V_6 , V_112 ) ;
if ( V_29 )
return V_29 ;
V_62 . V_66 . V_67 [ 1 ] = V_109 << 16 | 0x1 ;
V_29 = F_48 ( V_6 , & V_62 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_8 , V_29 ) ;
F_29 ( & V_62 ) ;
return V_29 ;
}
V_111 = V_62 . V_69 . V_67 [ 2 ] & 0xffff ;
if ( V_111 & V_113 )
V_108 -> V_114 = F_49 ( V_62 . V_69 . V_67 [ 2 ] ) ;
if ( V_111 & V_115 )
V_108 -> V_53 = F_50 ( V_62 . V_69 . V_67 [ 3 ] ) ;
if ( V_111 & V_116 )
V_108 -> V_117 = F_49 ( V_62 . V_69 . V_67 [ 3 ] ) ;
if ( V_111 & V_118 )
V_108 -> V_119 = F_50 ( V_62 . V_69 . V_67 [ 4 ] ) ;
if ( V_111 & V_120 )
V_108 -> V_121 = F_49 ( V_62 . V_69 . V_67 [ 4 ] ) ;
if ( V_111 & V_122 )
V_108 -> V_123 = F_50 ( V_62 . V_69 . V_67 [ 5 ] ) ;
if ( V_111 & V_124 )
V_108 -> V_125 = F_49 ( V_62 . V_69 . V_67 [ 5 ] ) ;
if ( V_111 & V_126 )
V_108 -> V_127 = F_50 ( V_62 . V_69 . V_67 [ 6 ] ) ;
if ( V_111 & V_128 )
V_108 -> V_129 = F_49 ( V_62 . V_69 . V_67 [ 6 ] ) ;
if ( V_111 & V_130 )
V_108 -> V_131 = F_50 ( V_62 . V_69 . V_67 [ 7 ] ) ;
V_108 -> V_132 = F_49 ( V_62 . V_69 . V_67 [ 7 ] ) ;
V_108 -> V_133 = F_50 ( V_62 . V_69 . V_67 [ 8 ] ) ;
V_108 -> V_134 = F_49 ( V_62 . V_69 . V_67 [ 8 ] ) ;
V_108 -> V_135 = F_50 ( V_62 . V_69 . V_67 [ 9 ] ) ;
F_21 ( V_9 , L_9
L_10
L_11
L_12
L_13
L_14 ,
V_108 -> V_114 , V_108 -> V_53 ,
V_108 -> V_117 , V_108 -> V_119 ,
V_108 -> V_121 ,
V_108 -> V_123 , V_108 -> V_125 ,
V_108 -> V_127 , V_108 -> V_129 ,
V_108 -> V_131 , V_108 -> V_132 ,
V_108 -> V_133 , V_108 -> V_134 ,
V_108 -> V_135 ) ;
F_29 ( & V_62 ) ;
return V_29 ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_61 * V_62 )
{
V_6 -> V_136 = F_49 ( V_62 -> V_69 . V_67 [ 1 ] ) & 0xffff ;
V_6 -> V_63 &= ~ V_137 ;
return 0 ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_61 * V_62 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
int V_30 , V_138 ;
T_3 * V_139 ;
if ( V_20 -> V_140 )
return 0 ;
V_20 -> V_141 = V_62 -> V_69 . V_67 [ 2 ] & 0xf ;
V_20 -> V_142 = V_62 -> V_69 . V_67 [ 2 ] >> 16 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_15 ,
V_20 -> V_142 ) ;
F_53 ( V_6 ) ;
if ( ! V_20 -> V_141 )
return 0 ;
V_138 = V_20 -> V_142 ;
V_20 -> V_140 = F_11 ( sizeof( T_3 ) * V_138 , V_32 ) ;
if ( ! V_20 -> V_140 )
return - V_33 ;
V_139 = ( T_3 * ) & V_62 -> V_69 . V_67 [ 3 ] ;
for ( V_30 = 0 ; V_30 < V_138 ; V_30 ++ )
V_20 -> V_140 [ V_30 ] = V_139 [ V_30 ] ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_61 V_62 ;
int V_143 = 0 ;
V_143 = F_55 ( & V_62 , V_144 ) ;
if ( V_143 )
return V_143 ;
V_143 = F_48 ( V_6 , & V_62 ) ;
if ( V_143 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_16 ,
V_143 ) ;
} else {
V_20 -> V_145 = V_62 . V_69 . V_67 [ 1 ] & 0x3 ;
switch ( V_20 -> V_145 ) {
case V_146 :
V_143 = F_52 ( V_6 , & V_62 ) ;
break;
case V_147 :
V_143 = F_51 ( V_6 , & V_62 ) ;
break;
}
}
F_29 ( & V_62 ) ;
return V_143 ;
}
static int F_56 ( struct V_5 * V_6 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
struct V_107 V_148 ;
int V_29 ;
V_29 = F_46 ( V_6 , & V_148 , 0 ) ;
if ( V_29 )
return V_29 ;
V_34 -> V_149 = V_148 . V_121 ;
V_29 = F_57 ( V_6 , & V_148 , V_34 -> V_42 ) ;
if ( V_29 )
return - V_31 ;
if ( F_58 ( V_6 ) )
return - V_31 ;
F_45 ( V_6 ) ;
V_6 -> V_63 |= V_150 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_17 ,
V_6 -> V_34 -> V_151 ) ;
V_34 -> V_152 = ( T_2 ) V_148 . V_153 ;
V_34 -> V_154 = V_148 . V_154 ;
V_34 -> V_155 = V_148 . V_155 ;
V_34 -> V_91 = V_148 . V_91 ;
V_34 -> V_156 = V_148 . V_156 ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 ,
int V_157 )
{
int V_29 ;
F_14 ( & V_6 -> V_158 ) ;
if ( ! V_159 && ! ! V_160 )
F_60 ( & V_6 -> V_10 -> V_9 ,
L_18 ) ;
F_61 ( V_6 , V_161 ) ;
F_62 ( V_6 , V_161 ) ;
V_29 = F_63 ( V_6 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_19 ) ;
goto V_162;
}
V_29 = F_64 ( V_6 ) ;
if ( V_29 )
goto V_162;
V_29 = F_9 ( V_6 , 1 ) ;
if ( V_29 )
goto V_163;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
goto V_164;
V_29 = F_36 ( V_6 , V_165 ) ;
if ( V_29 )
goto V_166;
V_29 = F_56 ( V_6 ) ;
if ( V_29 )
goto V_167;
V_29 = F_54 ( V_6 ) ;
if ( V_29 )
goto V_167;
V_29 = F_65 ( V_6 , V_6 -> V_168 , V_157 ) ;
if ( V_29 )
goto V_167;
F_66 ( V_6 -> V_10 , V_6 ) ;
F_21 ( & V_6 -> V_10 -> V_9 , L_20 ,
V_6 -> V_168 -> V_169 ) ;
F_67 ( V_6 , V_170 ,
V_6 -> V_34 -> V_171 . V_172 ) ;
return 0 ;
V_167:
F_36 ( V_6 , V_71 ) ;
V_166:
F_37 ( V_6 , 0 ) ;
V_164:
F_32 ( V_6 ) ;
V_163:
F_68 ( V_6 ) ;
V_162:
F_69 ( V_6 ) ;
return V_29 ;
}
static int F_70 ( struct V_5 * V_6 )
{
T_1 V_73 ;
do {
F_71 ( 20 ) ;
if ( ++ V_6 -> V_173 > V_174 )
return - V_31 ;
V_73 = F_72 ( V_6 -> V_34 , V_175 ) ;
} while ( V_73 != V_176 );
return 0 ;
}
int F_73 ( struct V_5 * V_6 , int V_157 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
int V_29 ;
F_74 ( V_177 , & V_34 -> V_171 . V_111 ) ;
V_34 -> V_171 . V_172 = V_178 ;
V_34 -> V_179 = 0 ;
V_6 -> V_173 = 0 ;
V_34 -> V_180 = 1 ;
V_6 -> V_181 = 0 ;
V_6 -> V_63 |= V_182 ;
V_29 = F_70 ( V_6 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_59 ( V_6 , V_157 ) ;
if ( V_29 )
return V_29 ;
if ( F_75 ( V_6 ) )
F_60 ( & V_6 -> V_10 -> V_9 , L_21 ) ;
F_76 ( & V_6 -> V_183 , V_184 ) ;
F_77 ( V_185 , & V_6 -> V_73 ) ;
return 0 ;
}
void F_78 ( struct V_5 * V_6 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
V_34 -> V_91 = V_186 ;
F_21 ( & V_6 -> V_10 -> V_9 ,
L_22 ,
V_34 -> V_151 ) ;
V_6 -> V_187 = & V_188 ;
F_74 ( V_72 , & V_6 -> V_73 ) ;
return;
}
void F_79 ( struct V_77 * V_34 )
{
V_34 -> V_189 = & V_190 ;
V_34 -> V_191 = ( T_1 * ) V_192 ;
V_34 -> V_193 = ( T_1 * ) V_194 ;
}
static T_1 F_80 ( T_1 V_195 , T_2 V_196 )
{
T_1 V_82 ;
V_82 = V_195 / ( ( V_196 + 1 ) * V_197 ) ;
if ( V_82 )
V_82 = V_197 ;
else
V_82 = V_195 % V_197 ;
return V_82 ;
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
return - V_198 ;
}
static inline int F_82 ( struct V_59 * * V_60 )
{
* V_60 = F_11 ( sizeof( struct V_59 ) , V_199 ) ;
if ( ! * V_60 )
return - V_33 ;
F_17 ( & ( * V_60 ) -> V_200 ) ;
return 0 ;
}
static inline int F_83 ( struct V_87 * * V_74 ,
T_1 V_76 )
{
* V_74 = F_11 ( sizeof( struct V_87 ) * V_76 , V_199 ) ;
if ( ! * V_74 )
return - V_33 ;
return 0 ;
}
static int F_55 ( struct V_61 * V_79 , T_1 type )
{
const struct V_201 * V_202 ;
int V_30 , V_76 ;
V_202 = V_203 ;
V_76 = F_84 ( V_203 ) ;
for ( V_30 = 0 ; V_30 < V_76 ; V_30 ++ ) {
if ( type == V_202 [ V_30 ] . V_62 ) {
V_79 -> V_84 = V_204 ;
V_79 -> V_66 . V_205 = V_202 [ V_30 ] . V_206 ;
V_79 -> V_69 . V_205 = V_202 [ V_30 ] . V_207 ;
V_79 -> V_66 . V_67 = F_85 ( V_79 -> V_66 . V_205 , sizeof( T_1 ) ,
V_199 ) ;
if ( ! V_79 -> V_66 . V_67 )
return - V_33 ;
V_79 -> V_69 . V_67 = F_85 ( V_79 -> V_69 . V_205 , sizeof( T_1 ) ,
V_199 ) ;
if ( ! V_79 -> V_69 . V_67 ) {
F_23 ( V_79 -> V_66 . V_67 ) ;
V_79 -> V_66 . V_67 = NULL ;
return - V_33 ;
}
memset ( V_79 -> V_66 . V_67 , 0 , sizeof( T_1 ) * V_79 -> V_66 . V_205 ) ;
memset ( V_79 -> V_69 . V_67 , 0 , sizeof( T_1 ) * V_79 -> V_69 . V_205 ) ;
V_79 -> V_66 . V_67 [ 0 ] = ( type | ( V_79 -> V_66 . V_205 << 16 ) |
( 3 << 29 ) ) ;
V_79 -> V_69 . V_67 [ 0 ] = ( type & 0xffff ) | V_79 -> V_69 . V_205 << 16 ;
return 0 ;
}
}
return - V_198 ;
}
static int F_86 ( struct V_59 * V_60 ,
struct V_61 * V_62 ,
T_3 V_208 , T_2 V_209 )
{
struct V_87 * V_74 ;
int V_30 ;
T_1 V_210 , V_211 ;
T_3 V_212 ;
T_2 V_86 , V_213 , V_214 ;
V_211 = V_197 ;
if ( V_209 == V_215 ) {
V_60 -> V_68 = (struct V_216 * ) V_62 -> V_66 . V_67 ;
V_60 -> V_70 = (struct V_216 * ) V_62 -> V_69 . V_67 ;
V_210 = V_62 -> V_66 . V_205 ;
V_60 -> V_217 = ( V_210 * 4 ) ;
V_210 = V_62 -> V_69 . V_205 ;
V_60 -> V_218 = ( V_210 * 4 ) ;
V_86 = V_62 -> V_66 . V_67 [ 0 ] & 0xff ;
V_212 = ( V_60 -> V_217 ) % ( V_211 ) ;
V_213 = ( V_60 -> V_217 ) / ( V_211 ) ;
if ( V_212 )
V_213 ++ ;
V_214 = V_213 ;
if ( F_83 ( & V_60 -> V_219 , V_213 ) )
return - V_33 ;
V_212 = ( V_60 -> V_218 ) % ( V_211 ) ;
V_213 = ( V_60 -> V_218 ) / ( V_211 ) ;
if ( V_212 )
V_213 ++ ;
if ( F_83 ( & V_60 -> V_220 , V_213 ) )
return - V_33 ;
V_213 = V_214 ;
V_74 = V_60 -> V_219 ;
} else {
V_62 -> V_66 . V_67 = ( T_1 * ) V_60 -> V_68 ;
V_62 -> V_69 . V_67 = ( T_1 * ) V_60 -> V_70 ;
V_86 = V_62 -> V_66 . V_67 [ 0 ] & 0xff ;
V_212 = ( V_60 -> V_218 ) % ( V_211 ) ;
V_213 = ( V_60 -> V_218 ) / ( V_211 ) ;
if ( V_212 )
V_213 ++ ;
V_62 -> V_66 . V_205 = V_60 -> V_217 / 4 ;
V_62 -> V_69 . V_205 = V_60 -> V_218 / 4 ;
V_74 = V_60 -> V_220 ;
V_62 -> V_84 = V_60 -> V_219 -> V_84 ;
}
V_60 -> V_221 = V_208 ;
V_60 -> V_222 = V_86 ;
for ( V_30 = 0 ; V_30 < V_213 ; V_30 ++ ) {
V_74 [ V_30 ] . V_223 = 2 ;
V_74 [ V_30 ] . V_209 = V_209 ;
V_74 [ V_30 ] . V_84 = V_62 -> V_84 ;
V_74 [ V_30 ] . V_224 = 1 ;
V_74 [ V_30 ] . V_213 = V_213 ;
V_74 [ V_30 ] . V_225 = V_30 + 1 ;
V_74 [ V_30 ] . V_86 = V_86 ;
V_74 [ V_30 ] . V_226 = V_208 ;
}
return 0 ;
}
static void F_30 ( struct V_59 * V_60 )
{
if ( ! V_60 )
return;
F_23 ( V_60 -> V_219 ) ;
F_23 ( V_60 -> V_220 ) ;
F_23 ( V_60 ) ;
}
static int F_87 ( struct V_27 * V_28 ,
struct V_59 * V_60 , T_2 type )
{
struct V_57 * V_58 ;
unsigned long V_63 ;
int V_143 = 0 ;
if ( type == V_227 ) {
V_58 = & V_28 -> V_45 ;
F_25 ( & V_58 -> V_48 , V_63 ) ;
V_58 -> V_65 -- ;
F_28 ( & V_60 -> V_64 ) ;
if ( V_58 -> V_65 > 0 )
V_143 = 1 ;
F_31 ( & V_58 -> V_48 , V_63 ) ;
}
if ( type == V_215 ) {
while ( F_88 ( V_228 , & V_28 -> V_73 ) )
F_71 ( 100 ) ;
V_28 -> V_229 = NULL ;
F_77 ( V_228 , & V_28 -> V_73 ) ;
}
return V_143 ;
}
static void F_89 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
T_4 V_230 )
{
if ( F_39 ( V_231 , & V_28 -> V_73 ) ||
V_28 -> V_6 -> V_181 )
return;
F_90 ( V_20 -> V_22 . V_38 , & V_28 -> V_50 ) ;
}
static inline void F_91 ( struct V_59 * V_60 )
{
struct V_92 * V_232 = & V_60 -> V_200 ;
if ( F_43 ( V_232 , V_233 ) )
V_60 -> V_234 = V_235 ;
else
V_60 -> V_234 = V_236 ;
return;
}
static void F_92 ( struct V_59 * V_60 ,
T_2 type )
{
if ( type == V_227 ) {
V_60 -> V_237 ++ ;
if ( V_60 -> V_237 < V_60 -> V_220 -> V_213 )
V_60 -> V_234 = V_238 ;
else
V_60 -> V_234 = V_235 ;
} else {
V_60 -> V_239 ++ ;
if ( V_60 -> V_239 < V_60 -> V_219 -> V_213 )
V_60 -> V_234 = V_238 ;
else
V_60 -> V_234 = V_240 ;
}
}
static void F_93 ( struct V_59 * V_60 ,
T_2 type )
{
struct V_27 * V_28 = V_60 -> V_28 ;
struct V_92 * V_232 = & V_28 -> V_49 ;
if ( ! F_43 ( V_232 , V_241 ) ) {
V_60 -> V_234 = V_236 ;
return;
}
F_77 ( V_242 , & V_28 -> V_73 ) ;
F_92 ( V_60 , type ) ;
}
static void F_94 ( struct V_5 * V_6 ,
T_1 * V_74 , T_1 * V_75 , T_1 V_76 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
T_1 V_243 ;
T_2 V_30 , V_244 = 2 , V_245 , V_246 ;
V_245 = ( sizeof( struct V_87 ) / sizeof( T_1 ) ) ;
V_244 = ( V_76 / sizeof( T_1 ) ) + V_245 ;
V_243 = F_95 ( F_96 ( V_34 , 0 ) ) ;
for ( V_30 = 2 , V_246 = 0 ; V_246 < V_245 ; V_30 ++ , V_246 ++ )
* ( V_74 ++ ) = F_95 ( F_96 ( V_34 , V_30 ) ) ;
for (; V_246 < V_244 ; V_30 ++ , V_246 ++ )
* ( V_75 ++ ) = F_95 ( F_96 ( V_34 , V_30 ) ) ;
}
static int F_97 ( struct V_27 * V_28 )
{
int V_143 = - V_247 ;
T_1 V_81 = 10000 ;
do {
if ( ! F_88 ( V_242 , & V_28 -> V_73 ) ) {
V_143 = 0 ;
break;
}
F_98 ( 1 ) ;
} while ( -- V_81 );
return V_143 ;
}
static int F_99 ( struct V_59 * V_60 , T_2 type )
{
struct V_27 * V_28 = V_60 -> V_28 ;
T_1 V_82 , V_245 ;
T_1 * V_74 , * V_75 ;
int V_143 ;
T_2 V_42 = V_60 -> V_248 ;
if ( F_97 ( V_28 ) )
return - V_247 ;
if ( type == V_215 ) {
V_74 = ( T_1 * ) ( V_60 -> V_219 + V_60 -> V_239 ) ;
V_75 = ( T_1 * ) ( V_60 -> V_68 + V_60 -> V_239 ) ;
V_245 = ( sizeof( struct V_87 ) / sizeof( T_1 ) ) ;
V_82 = F_80 ( V_60 -> V_217 ,
V_60 -> V_239 ) ;
V_82 = ( V_82 / sizeof( T_1 ) ) ;
} else {
V_74 = ( T_1 * ) ( V_60 -> V_220 + V_60 -> V_237 ) ;
V_75 = ( T_1 * ) ( V_60 -> V_70 + V_60 -> V_237 ) ;
V_245 = ( sizeof( struct V_87 ) / sizeof( T_1 ) ) ;
V_82 = F_80 ( V_60 -> V_218 ,
V_60 -> V_237 ) ;
V_82 = ( V_82 / sizeof( T_1 ) ) ;
}
V_143 = F_42 ( V_28 -> V_6 , V_74 , V_75 ,
V_42 , V_82 ) ;
return V_143 ;
}
static int F_100 ( struct V_59 * V_60 ,
struct V_27 * V_28 , T_2 type )
{
bool V_249 = true ;
int V_29 = - V_31 ;
while ( V_249 ) {
if ( F_39 ( V_231 , & V_28 -> V_73 ) ||
V_28 -> V_6 -> V_181 )
V_60 -> V_234 = V_236 ;
switch ( V_60 -> V_234 ) {
case V_238 :
V_60 -> V_234 = V_250 ;
if ( F_99 ( V_60 , type ) )
V_60 -> V_234 = V_236 ;
break;
case V_250 :
F_93 ( V_60 , type ) ;
break;
case V_240 :
F_91 ( V_60 ) ;
break;
case V_235 :
V_29 = 0 ;
V_249 = false ;
break;
case V_236 :
V_29 = - V_31 ;
V_249 = false ;
F_77 ( V_242 , & V_28 -> V_73 ) ;
break;
default:
V_29 = - V_31 ;
V_249 = false ;
}
}
return V_29 ;
}
static int F_101 ( struct V_5 * V_6 ,
struct V_59 * V_60 , int V_42 )
{
struct V_27 * V_28 ;
int V_29 , V_251 = F_81 ( V_6 , V_42 ) ;
if ( V_251 < 0 )
return - V_31 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ V_251 ] ;
V_60 -> V_28 = V_28 ;
V_60 -> V_248 = V_42 ;
if ( ! F_39 ( V_252 , & V_28 -> V_73 ) ) {
if ( F_19 ( V_6 ) )
return - V_31 ;
if ( F_6 ( V_6 ) &&
V_60 -> V_222 != V_165 )
return - V_31 ;
}
F_102 ( & V_28 -> V_43 ) ;
V_28 -> V_229 = V_60 ;
V_29 = F_100 ( V_60 , V_28 , V_215 ) ;
F_87 ( V_28 , V_60 , V_215 ) ;
F_103 ( & V_28 -> V_43 ) ;
return V_29 ;
}
static void F_104 ( struct V_5 * V_6 ,
struct V_59 * V_60 ,
struct V_61 * V_62 )
{
#ifdef F_105
if ( F_19 ( V_6 ) ) {
F_106 ( V_6 , V_60 , V_62 ) ;
return;
}
#endif
V_62 -> V_69 . V_67 [ 0 ] |= ( 0x9 << 25 ) ;
return;
}
static void V_51 ( struct V_253 * V_254 )
{
struct V_27 * V_28 = F_107 ( V_254 , struct V_27 ,
V_50 ) ;
struct V_59 * V_60 = NULL ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_61 V_62 ;
T_2 V_66 ;
if ( V_6 -> V_181 )
return;
if ( F_39 ( V_231 , & V_28 -> V_73 ) )
return;
memset ( & V_62 , 0 , sizeof( struct V_61 ) ) ;
V_60 = F_27 ( & V_28 -> V_45 . V_46 ,
struct V_59 , V_64 ) ;
V_6 = V_28 -> V_6 ;
if ( F_86 ( V_60 , & V_62 , V_60 -> V_219 -> V_226 ,
V_227 ) )
goto V_255;
F_104 ( V_6 , V_60 , & V_62 ) ;
V_60 -> V_234 = V_238 ;
F_100 ( V_60 , V_28 , V_227 ) ;
V_255:
F_29 ( & V_62 ) ;
V_66 = F_87 ( V_28 , V_60 , V_227 ) ;
F_30 ( V_60 ) ;
if ( V_66 )
F_89 ( V_6 -> V_34 -> V_20 , V_28 ,
V_51 ) ;
}
static void F_108 ( struct V_87 * V_74 ,
struct V_27 * V_28 )
{
struct V_59 * V_60 ;
T_1 V_82 ;
if ( F_88 ( V_228 , & V_28 -> V_73 ) )
return;
V_60 = V_28 -> V_229 ;
if ( V_60 == NULL )
goto V_256;
if ( V_60 -> V_221 != V_74 -> V_226 )
goto V_256;
V_82 = F_80 ( V_60 -> V_218 ,
V_60 -> V_237 ) ;
F_94 ( V_28 -> V_6 ,
( T_1 * ) ( V_60 -> V_220 + V_60 -> V_237 ) ,
( T_1 * ) ( V_60 -> V_70 + V_60 -> V_237 ) ,
V_82 ) ;
if ( ++ V_60 -> V_237 < V_60 -> V_220 -> V_213 )
goto V_256;
F_109 ( & V_60 -> V_200 ) ;
V_256:
F_77 ( V_228 , & V_28 -> V_73 ) ;
}
int F_110 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_59 * V_60 )
{
struct V_57 * V_58 = & V_28 -> V_45 ;
V_58 -> V_65 ++ ;
F_111 ( & V_60 -> V_64 , & V_58 -> V_46 ) ;
if ( V_58 -> V_65 == 1 )
F_89 ( V_20 , V_28 ,
V_51 ) ;
return 0 ;
}
static int F_112 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_59 * V_60 )
{
struct V_57 * V_58 = & V_28 -> V_45 ;
F_113 ( & V_58 -> V_48 ) ;
F_110 ( V_20 , V_28 , V_60 ) ;
F_114 ( & V_58 -> V_48 ) ;
return 0 ;
}
static void F_115 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_87 * V_74 )
{
struct V_59 * V_60 = NULL ;
struct V_257 * V_258 ;
T_1 V_82 , V_196 ;
T_2 V_259 = 0 , V_260 = 0 ;
F_113 ( & V_28 -> V_47 . V_48 ) ;
if ( V_28 -> V_47 . V_65 > 0 ) {
F_116 (node, &vf->rcv_pend.wait_list) {
V_60 = F_117 ( V_258 , struct V_59 , V_64 ) ;
if ( V_60 -> V_221 == V_74 -> V_226 ) {
V_259 = 1 ;
break;
}
}
}
if ( V_259 ) {
V_196 = V_60 -> V_239 ;
V_82 = F_80 ( V_60 -> V_217 ,
V_196 ) ;
F_94 ( V_28 -> V_6 ,
( T_1 * ) ( V_60 -> V_219 + V_196 ) ,
( T_1 * ) ( V_60 -> V_68 + V_196 ) ,
V_82 ) ;
V_60 -> V_239 ++ ;
if ( V_60 -> V_239 >= V_74 -> V_213 ) {
V_28 -> V_47 . V_65 -- ;
F_28 ( & V_60 -> V_64 ) ;
V_260 = 1 ;
}
}
F_114 ( & V_28 -> V_47 . V_48 ) ;
if ( V_260 )
if ( F_112 ( V_20 , V_28 , V_60 ) )
F_30 ( V_60 ) ;
return;
}
static void F_118 ( struct V_19 * V_20 ,
struct V_87 * V_74 ,
struct V_27 * V_28 )
{
struct V_59 * V_60 ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_61 V_62 ;
T_1 V_82 ;
int V_29 ;
T_2 V_86 ;
if ( V_6 -> V_181 )
return;
if ( ! F_39 ( V_252 , & V_28 -> V_73 ) &&
V_74 -> V_84 != V_204 &&
V_74 -> V_86 != V_165 )
return;
if ( V_74 -> V_225 > 1 ) {
F_115 ( V_20 , V_28 , V_74 ) ;
return;
}
memset ( & V_62 , 0 , sizeof( struct V_61 ) ) ;
V_86 = V_74 -> V_86 ;
if ( F_82 ( & V_60 ) )
return;
if ( V_74 -> V_84 == V_204 )
V_29 = F_55 ( & V_62 , V_86 ) ;
else
V_29 = F_47 ( & V_62 , V_6 , V_86 ) ;
if ( V_29 ) {
F_30 ( V_60 ) ;
return;
}
V_62 . V_84 = V_74 -> V_84 ;
if ( F_86 ( V_60 , & V_62 , V_74 -> V_226 ,
V_215 ) ) {
F_29 ( & V_62 ) ;
F_30 ( V_60 ) ;
return;
}
V_82 = F_80 ( V_60 -> V_217 ,
V_60 -> V_239 ) ;
F_94 ( V_28 -> V_6 ,
( T_1 * ) ( V_60 -> V_219 + V_60 -> V_239 ) ,
( T_1 * ) ( V_60 -> V_68 + V_60 -> V_239 ) ,
V_82 ) ;
V_60 -> V_248 = V_28 -> V_42 ;
V_60 -> V_28 = V_28 ;
V_60 -> V_221 = V_74 -> V_226 ;
V_60 -> V_239 ++ ;
if ( F_119 ( V_6 , V_60 , V_28 ) )
return;
if ( V_60 -> V_239 == V_60 -> V_219 -> V_213 ) {
if ( F_112 ( V_20 , V_28 , V_60 ) ) {
F_29 ( & V_62 ) ;
F_30 ( V_60 ) ;
}
} else {
F_113 ( & V_28 -> V_47 . V_48 ) ;
F_111 ( & V_60 -> V_64 , & V_28 -> V_47 . V_46 ) ;
V_28 -> V_47 . V_65 ++ ;
F_114 ( & V_28 -> V_47 . V_48 ) ;
}
}
static void F_120 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
struct V_87 V_74 ;
T_1 * V_261 = ( T_1 * ) & V_74 ;
T_2 V_209 , V_30 ;
for ( V_30 = 2 ; V_30 < 6 ; V_30 ++ )
V_261 [ V_30 - 2 ] = F_95 ( F_96 ( V_28 -> V_6 -> V_34 , V_30 ) ) ;
V_209 = V_74 . V_209 ;
switch ( V_209 ) {
case V_215 :
F_118 ( V_20 , & V_74 , V_28 ) ;
break;
case V_227 :
F_108 ( & V_74 , V_28 ) ;
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
void F_123 ( struct V_5 * V_6 , T_1 V_262 )
{
struct V_27 * V_28 ;
struct V_19 * V_20 ;
int V_251 ;
T_2 V_42 ;
V_20 = V_6 -> V_34 -> V_20 ;
V_42 = F_4 ( V_262 ) ;
V_251 = F_81 ( V_6 , V_42 ) ;
if ( V_251 < 0 )
return;
V_28 = & V_20 -> V_35 [ V_251 ] ;
V_28 -> V_42 = V_42 ;
if ( F_2 ( V_262 ) )
F_109 ( & V_28 -> V_49 ) ;
if ( F_3 ( V_262 ) ) {
F_121 ( V_20 , V_28 ) ;
return;
}
if ( F_1 ( V_262 ) )
F_120 ( V_20 , V_28 ) ;
}
int F_37 ( struct V_5 * V_6 , T_2 V_263 )
{
struct V_61 V_62 ;
int V_29 ;
if ( ! F_39 ( V_72 , & V_6 -> V_73 ) )
return 0 ;
if ( F_47 ( & V_62 , V_6 , V_264 ) )
return - V_33 ;
if ( V_263 )
V_62 . V_66 . V_67 [ 1 ] = ( 1 << 4 ) | ( 1 << 5 ) | ( 1 << 6 ) | ( 1 << 7 ) ;
V_29 = F_124 ( V_6 , & V_62 ) ;
if ( V_29 != V_265 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_24 ,
( V_263 ? L_25 : L_26 ) , V_29 ) ;
}
F_29 ( & V_62 ) ;
return V_29 ;
}
static int F_125 ( struct V_5 * V_6 ,
struct V_59 * V_60 )
{
T_2 V_244 = V_174 ;
T_1 V_73 ;
V_73 = F_72 ( V_6 -> V_34 , V_175 ) ;
if ( V_73 == V_176 ) {
F_71 ( 20 ) ;
F_77 ( V_242 , & V_60 -> V_28 -> V_73 ) ;
V_60 -> V_234 = V_238 ;
if ( ++ V_6 -> V_173 > V_244 )
return - V_31 ;
else
return 0 ;
}
return - V_31 ;
}
static int F_126 ( struct V_5 * V_6 ,
struct V_61 * V_62 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
struct V_78 * V_79 = V_34 -> V_80 ;
struct V_110 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_59 * V_60 ;
int V_29 ;
T_1 V_266 , V_267 , V_268 , V_69 ;
T_3 V_208 = ++ V_6 -> V_34 -> V_20 -> V_22 . V_269 ;
T_2 V_230 = V_34 -> V_42 ;
V_69 = F_82 ( & V_60 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_86 ( V_60 , V_62 , V_208 , V_215 ) ;
if ( V_69 )
goto V_270;
V_271:
if ( ! F_39 ( V_272 , & V_79 -> V_111 ) ) {
V_69 = - V_31 ;
F_127 ( V_6 , V_273 , L_27 ,
F_128 ( V_62 -> V_66 . V_67 [ 0 ] ) , V_230 ) ;
goto V_274;
}
V_29 = F_101 ( V_6 , V_60 , V_230 ) ;
if ( V_29 ) {
F_13 ( V_9 , L_28 ,
( V_62 -> V_66 . V_67 [ 0 ] & 0xffff ) , V_230 ) ;
V_69 = V_275 ;
if ( ( V_60 -> V_219 -> V_86 == V_165 ) &&
! F_125 ( V_6 , V_60 ) )
goto V_271;
goto V_274;
}
V_266 = V_62 -> V_69 . V_67 [ 0 ] ;
V_268 = F_129 ( V_266 ) ;
V_267 = F_128 ( V_62 -> V_66 . V_67 [ 0 ] ) ;
if ( ( V_268 == V_276 ) ||
( V_268 == V_277 ) ) {
V_69 = V_265 ;
} else {
V_69 = V_268 ;
if ( ! V_69 )
V_69 = 1 ;
F_13 ( V_9 ,
L_29 ,
V_267 , V_268 , V_230 ) ;
}
V_274:
if ( V_69 == V_275 ) {
V_34 -> V_179 = 1 ;
V_6 -> V_181 = 1 ;
F_77 ( V_272 , & V_79 -> V_111 ) ;
}
V_270:
F_30 ( V_60 ) ;
return V_69 ;
}
static int F_36 ( struct V_5 * V_6 , T_2 V_86 )
{
struct V_61 V_62 ;
struct V_27 * V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
int V_143 ;
if ( F_55 ( & V_62 , V_86 ) )
return - V_33 ;
V_143 = F_48 ( V_6 , & V_62 ) ;
if ( V_143 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_30 , V_86 ? L_31 : L_32 ,
V_143 ) ;
goto V_278;
}
V_86 = ( V_62 . V_69 . V_67 [ 0 ] & 0xff ) ;
if ( V_62 . V_69 . V_67 [ 0 ] >> 25 == 2 )
return 2 ;
if ( V_86 == V_165 )
F_74 ( V_252 , & V_28 -> V_73 ) ;
else
F_77 ( V_252 , & V_28 -> V_73 ) ;
V_278:
F_29 ( & V_62 ) ;
return V_143 ;
}
static void F_130 ( struct V_279 * V_168 )
{
struct V_5 * V_6 = F_131 ( V_168 ) ;
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_280 * V_281 ;
struct V_257 * V_282 , V_283 ;
struct V_27 * V_28 ;
T_3 V_284 ;
int V_30 ;
static const T_2 V_285 [ V_286 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
F_14 ( & V_283 ) ;
V_282 = & V_6 -> V_158 ;
F_132 ( V_168 ) ;
while ( ! F_26 ( V_282 ) ) {
V_281 = F_117 ( V_282 -> V_287 , struct V_280 , V_64 ) ;
F_133 ( & V_281 -> V_64 , & V_283 ) ;
}
F_134 ( V_168 ) ;
while ( ! F_26 ( & V_283 ) ) {
V_281 = F_117 ( ( & V_283 ) -> V_287 ,
struct V_280 , V_64 ) ;
if ( ! F_135 ( V_28 ) ) {
F_136 ( V_6 , V_285 , 0 ) ;
F_136 ( V_6 , V_281 -> V_288 , 0 ) ;
} else {
F_102 ( & V_28 -> V_44 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_142 ; V_30 ++ ) {
V_284 = V_28 -> V_289 [ V_30 ] ;
if ( V_284 ) {
F_136 ( V_6 , V_285 ,
V_284 ) ;
F_136 ( V_6 ,
V_281 -> V_288 ,
V_284 ) ;
}
}
F_103 ( & V_28 -> V_44 ) ;
if ( F_137 ( V_6 ) ) {
F_136 ( V_6 , V_285 , 0 ) ;
F_136 ( V_6 , V_281 -> V_288 , 0 ) ;
}
}
F_28 ( & V_281 -> V_64 ) ;
F_23 ( V_281 ) ;
}
}
void F_33 ( struct V_21 * V_22 )
{
struct V_257 * V_282 = & V_22 -> V_41 ;
struct V_290 * V_291 ;
while ( ! F_26 ( V_282 ) ) {
V_291 = F_117 ( V_282 -> V_287 , struct V_290 ,
V_64 ) ;
F_34 ( & V_291 -> V_254 ) ;
F_28 ( & V_291 -> V_64 ) ;
F_23 ( V_291 ) ;
}
}
static void F_138 ( struct V_279 * V_168 )
{
struct V_5 * V_6 = F_131 ( V_168 ) ;
struct V_77 * V_34 = V_6 -> V_34 ;
T_1 V_292 = V_293 ;
if ( ! F_39 ( V_294 , & V_6 -> V_73 ) )
return;
if ( V_168 -> V_63 & V_295 ) {
if ( ! ( V_6 -> V_63 & V_296 ) )
V_292 = V_297 ;
} else if ( ( V_168 -> V_63 & V_298 ) ||
( F_139 ( V_168 ) > V_34 -> V_149 ) ) {
V_292 = V_299 ;
}
if ( F_6 ( V_6 ) )
F_130 ( V_168 ) ;
F_140 ( V_6 , V_292 ) ;
}
static void F_141 ( struct V_253 * V_254 )
{
struct V_290 * V_291 ;
struct V_279 * V_168 ;
V_291 = F_107 ( V_254 , struct V_290 , V_254 ) ;
V_168 = (struct V_279 * ) V_291 -> V_261 ;
F_138 ( V_168 ) ;
return;
}
static struct V_290 *
F_142 ( struct V_21 * V_22 )
{
struct V_257 * V_258 ;
struct V_290 * V_291 = NULL ;
T_2 V_300 = 0 ;
F_116 (node, &bc->async_list) {
V_291 = F_117 ( V_258 , struct V_290 , V_64 ) ;
if ( ! F_143 ( & V_291 -> V_254 ) ) {
V_300 = 1 ;
break;
}
}
if ( ! V_300 ) {
V_291 = F_11 ( sizeof( struct V_290 ) ,
V_199 ) ;
if ( V_291 == NULL )
return NULL ;
F_111 ( & V_291 -> V_64 , & V_22 -> V_41 ) ;
}
return V_291 ;
}
static void F_144 ( struct V_21 * V_22 ,
T_4 V_230 , void * V_301 )
{
struct V_290 * V_291 = NULL ;
V_291 = F_142 ( V_22 ) ;
if ( ! V_291 )
return;
V_291 -> V_261 = V_301 ;
F_18 ( & V_291 -> V_254 , V_230 ) ;
F_90 ( V_22 -> V_40 , & V_291 -> V_254 ) ;
}
void F_145 ( struct V_279 * V_168 )
{
struct V_5 * V_6 = F_131 ( V_168 ) ;
struct V_21 * V_22 = & V_6 -> V_34 -> V_20 -> V_22 ;
if ( V_6 -> V_181 )
return;
F_144 ( V_22 , F_141 ,
V_168 ) ;
}
static int F_146 ( struct V_5 * V_6 )
{
int V_29 ;
V_6 -> V_181 = 0 ;
F_147 ( V_6 -> V_34 -> V_80 ) ;
F_148 ( V_6 ) ;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_6 , V_165 ) ;
if ( V_29 )
goto V_302;
V_29 = F_56 ( V_6 ) ;
if ( V_29 )
goto V_303;
return 0 ;
V_303:
F_36 ( V_6 , V_71 ) ;
V_302:
F_37 ( V_6 , 0 ) ;
return V_29 ;
}
static void F_149 ( struct V_5 * V_6 )
{
struct V_279 * V_168 = V_6 -> V_168 ;
if ( F_150 ( V_168 ) ) {
if ( ! F_151 ( V_6 , V_168 ) )
F_152 ( V_168 , V_304 ) ;
}
F_153 ( V_168 ) ;
}
static void F_154 ( struct V_5 * V_6 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
struct V_305 * V_306 = V_34 -> V_306 ;
struct V_279 * V_168 = V_6 -> V_168 ;
T_2 V_30 , V_307 = V_34 -> V_308 - 1 ;
F_155 ( V_168 ) ;
F_156 ( V_6 ) ;
F_157 ( V_6 ) ;
if ( F_150 ( V_168 ) )
F_158 ( V_6 , V_168 ) ;
for ( V_30 = 0 ; V_30 < V_307 ; V_30 ++ ) {
V_306 [ V_30 ] . V_309 = V_30 ;
V_306 [ V_30 ] . V_310 = 0 ;
V_306 [ V_30 ] . V_311 = 0 ;
}
V_34 -> V_179 = 0 ;
}
static int F_159 ( struct V_5 * V_6 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
struct V_110 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_312 * V_171 = & V_34 -> V_171 ;
T_2 V_230 = V_34 -> V_42 ;
T_1 V_73 ;
if ( ( V_171 -> V_313 == V_314 ) ||
( V_171 -> V_313 == V_315 ) ) {
if ( ! F_146 ( V_6 ) ) {
F_149 ( V_6 ) ;
V_6 -> V_173 = 0 ;
F_21 ( V_9 ,
L_33 ,
V_90 , V_230 ) ;
} else {
F_13 ( V_9 ,
L_34 ,
V_90 , V_230 ) ;
V_73 = F_72 ( V_34 , V_175 ) ;
F_21 ( V_9 , L_35 ,
V_73 ) ;
}
}
return 0 ;
}
static int F_160 ( struct V_5 * V_6 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
struct V_78 * V_79 = V_34 -> V_80 ;
struct V_110 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_312 * V_171 = & V_34 -> V_171 ;
T_2 V_230 = V_34 -> V_42 ;
T_1 V_73 ;
V_6 -> V_316 ++ ;
if ( V_6 -> V_316 < 3 ) {
V_6 -> V_181 = 1 ;
F_77 ( V_272 , & V_79 -> V_111 ) ;
F_21 ( V_9 ,
L_36 ) ;
return 0 ;
}
if ( V_6 -> V_316 > V_317 ) {
F_77 ( V_177 , & V_171 -> V_111 ) ;
V_6 -> V_318 = 0 ;
V_6 -> V_173 = 0 ;
V_6 -> V_316 = 0 ;
F_154 ( V_6 ) ;
F_13 ( V_9 ,
L_37 ) ;
return - V_31 ;
}
F_21 ( V_9 , L_38 , V_230 ) ;
F_21 ( V_9 , L_39 ,
V_90 , V_6 -> V_316 , V_230 ) ;
F_74 ( V_185 , & V_6 -> V_73 ) ;
V_6 -> V_181 = 1 ;
F_77 ( V_272 , & V_79 -> V_111 ) ;
F_154 ( V_6 ) ;
V_6 -> V_181 = 0 ;
if ( ! F_146 ( V_6 ) ) {
F_149 ( V_6 ) ;
V_6 -> V_318 = 0 ;
V_6 -> V_316 = 0 ;
V_6 -> V_173 = 0 ;
F_21 ( V_9 , L_40 , V_230 ) ;
} else {
F_13 ( V_9 , L_41 ,
V_90 , V_230 ) ;
V_73 = F_72 ( V_34 , V_175 ) ;
F_21 ( V_9 , L_42 , V_90 , V_73 ) ;
}
return 0 ;
}
static int F_161 ( struct V_5 * V_6 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
int V_143 = 0 ;
if ( V_34 -> V_171 . V_313 != V_176 )
V_143 = F_159 ( V_6 ) ;
else if ( V_34 -> V_179 )
V_143 = F_160 ( V_6 ) ;
F_77 ( V_185 , & V_6 -> V_73 ) ;
return V_143 ;
}
static int F_162 ( struct V_5 * V_6 )
{
struct V_312 * V_171 = & V_6 -> V_34 -> V_171 ;
F_13 ( & V_6 -> V_10 -> V_9 , L_43 ) ;
if ( V_171 -> V_313 == V_176 )
F_154 ( V_6 ) ;
F_77 ( V_177 , & V_171 -> V_111 ) ;
F_77 ( V_185 , & V_6 -> V_73 ) ;
return - V_31 ;
}
static int
F_163 ( struct V_5 * V_6 )
{
struct V_78 * V_79 = V_6 -> V_34 -> V_80 ;
struct V_312 * V_171 = & V_6 -> V_34 -> V_171 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_44 ) ;
if ( V_171 -> V_313 == V_176 ) {
F_74 ( V_185 , & V_6 -> V_73 ) ;
V_6 -> V_318 = 0 ;
V_6 -> V_316 = 0 ;
F_77 ( V_272 , & V_79 -> V_111 ) ;
F_154 ( V_6 ) ;
}
return 0 ;
}
static int F_164 ( struct V_5 * V_6 )
{
struct V_78 * V_79 = V_6 -> V_34 -> V_80 ;
struct V_312 * V_171 = & V_6 -> V_34 -> V_171 ;
T_2 V_230 = V_6 -> V_34 -> V_42 ;
if ( V_171 -> V_313 == V_176 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_45 , V_230 ) ;
F_74 ( V_185 , & V_6 -> V_73 ) ;
V_6 -> V_318 = 0 ;
V_6 -> V_316 = 0 ;
F_77 ( V_272 , & V_79 -> V_111 ) ;
F_154 ( V_6 ) ;
}
return 0 ;
}
static int F_165 ( struct V_5 * V_6 )
{
F_13 ( & V_6 -> V_10 -> V_9 , L_46 , V_90 ) ;
return 0 ;
}
static void V_170 ( struct V_253 * V_254 )
{
struct V_5 * V_6 ;
struct V_312 * V_171 ;
int V_143 = 0 ;
V_6 = F_107 ( V_254 , struct V_5 , V_319 . V_254 ) ;
V_171 = & V_6 -> V_34 -> V_171 ;
V_171 -> V_320 = F_72 ( V_6 -> V_34 , V_175 ) ;
switch ( V_171 -> V_320 ) {
case V_176 :
V_143 = F_161 ( V_6 ) ;
break;
case V_314 :
case V_315 :
V_143 = F_164 ( V_6 ) ;
break;
case V_321 :
V_143 = F_163 ( V_6 ) ;
break;
case V_322 :
V_143 = F_162 ( V_6 ) ;
break;
case V_323 :
break;
default:
V_143 = F_165 ( V_6 ) ;
}
V_171 -> V_313 = V_171 -> V_320 ;
if ( ! V_143 && F_39 ( V_177 , & V_171 -> V_111 ) )
F_67 ( V_6 , V_170 ,
V_171 -> V_172 ) ;
}
static void F_166 ( struct V_5 * V_6 )
{
while ( F_88 ( V_185 , & V_6 -> V_73 ) )
F_71 ( 20 ) ;
F_77 ( V_177 , & V_6 -> V_34 -> V_171 . V_111 ) ;
F_77 ( V_185 , & V_6 -> V_73 ) ;
F_167 ( & V_6 -> V_319 ) ;
}
static int F_168 ( struct V_19 * V_20 ,
struct V_27 * V_28 , T_3 V_284 )
{
int V_30 , V_29 = - V_198 ;
if ( ! V_28 -> V_289 )
return V_29 ;
F_102 ( & V_28 -> V_44 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_142 ; V_30 ++ ) {
if ( V_28 -> V_289 [ V_30 ] == V_284 ) {
V_29 = 0 ;
break;
}
}
F_103 ( & V_28 -> V_44 ) ;
return V_29 ;
}
static int F_169 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
int V_29 = 0 ;
F_102 ( & V_28 -> V_44 ) ;
if ( V_28 -> V_324 >= V_20 -> V_142 )
V_29 = - V_198 ;
F_103 ( & V_28 -> V_44 ) ;
return V_29 ;
}
static int F_170 ( struct V_5 * V_6 ,
T_3 V_325 , T_2 V_263 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
bool V_326 ;
T_2 V_327 = 0 ;
int V_30 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
V_326 = F_135 ( V_28 ) ;
if ( V_20 -> V_145 != V_146 )
return - V_198 ;
if ( V_263 ) {
if ( F_171 ( V_6 ) && V_326 )
return - V_198 ;
if ( F_169 ( V_20 , V_28 ) )
return - V_198 ;
if ( V_20 -> V_141 ) {
for ( V_30 = 0 ; V_30 < V_20 -> V_142 ; V_30 ++ ) {
if ( V_20 -> V_140 [ V_30 ] == V_325 )
V_327 = 1 ;
}
if ( ! V_327 )
return - V_198 ;
}
} else {
if ( ! V_326 || F_168 ( V_20 , V_28 , V_325 ) )
return - V_198 ;
}
return 0 ;
}
static void F_172 ( struct V_27 * V_28 , T_3 V_284 ,
enum V_328 V_267 )
{
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_19 * V_20 ;
V_20 = V_6 -> V_34 -> V_20 ;
if ( ! V_28 -> V_289 )
return;
F_102 ( & V_28 -> V_44 ) ;
switch ( V_267 ) {
case V_329 :
F_173 ( V_20 , V_28 , V_284 ) ;
break;
case V_330 :
F_174 ( V_20 , V_28 , V_284 ) ;
break;
default:
F_175 ( V_6 -> V_168 , L_47 ) ;
}
F_103 ( & V_28 -> V_44 ) ;
return;
}
int F_176 ( struct V_5 * V_6 ,
T_3 V_325 , T_2 V_263 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
struct V_61 V_62 ;
int V_143 ;
if ( V_325 == 0 )
return 0 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
V_143 = F_170 ( V_6 , V_325 , V_263 ) ;
if ( V_143 )
return V_143 ;
V_143 = F_55 ( & V_62 ,
V_331 ) ;
if ( V_143 )
return V_143 ;
V_62 . V_66 . V_67 [ 1 ] = ( V_263 & 1 ) | V_325 << 16 ;
F_33 ( & V_20 -> V_22 ) ;
V_143 = F_48 ( V_6 , & V_62 ) ;
if ( V_143 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_48 , V_143 ) ;
} else {
F_177 ( V_6 ) ;
if ( V_263 )
F_172 ( V_28 , V_325 , V_329 ) ;
else
F_172 ( V_28 , V_325 , V_330 ) ;
F_178 ( V_6 -> V_168 ) ;
}
F_29 ( & V_62 ) ;
return V_143 ;
}
static void F_179 ( struct V_5 * V_6 )
{
struct V_257 * V_282 = & V_6 -> V_332 ;
struct V_280 * V_281 ;
while ( ! F_26 ( V_282 ) ) {
V_281 = F_117 ( V_282 -> V_287 , struct V_280 , V_64 ) ;
F_180 ( V_6 , V_281 -> V_288 , V_281 -> V_284 ,
V_333 ) ;
F_28 ( & V_281 -> V_64 ) ;
F_23 ( V_281 ) ;
}
}
static int F_181 ( struct V_8 * V_10 )
{
struct V_5 * V_6 = F_182 ( V_10 ) ;
struct V_279 * V_168 = V_6 -> V_168 ;
int V_334 ;
F_155 ( V_168 ) ;
F_183 ( V_6 ) ;
if ( F_150 ( V_168 ) )
F_158 ( V_6 , V_168 ) ;
F_36 ( V_6 , V_71 ) ;
F_37 ( V_6 , 0 ) ;
F_157 ( V_6 ) ;
F_167 ( & V_6 -> V_183 ) ;
V_334 = F_184 ( V_10 ) ;
if ( V_334 )
return V_334 ;
return 0 ;
}
static int F_185 ( struct V_5 * V_6 )
{
struct V_312 * V_171 = & V_6 -> V_34 -> V_171 ;
struct V_279 * V_168 = V_6 -> V_168 ;
int V_29 ;
F_74 ( V_177 , & V_171 -> V_111 ) ;
F_148 ( V_6 ) ;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_6 , V_165 ) ;
if ( ! V_29 ) {
if ( F_150 ( V_168 ) ) {
V_29 = F_151 ( V_6 , V_168 ) ;
if ( ! V_29 )
F_152 ( V_168 , V_304 ) ;
}
}
F_153 ( V_168 ) ;
F_67 ( V_6 , V_170 ,
V_171 -> V_172 ) ;
return V_29 ;
}
void F_53 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_18 ; V_30 ++ ) {
V_28 = & V_20 -> V_35 [ V_30 ] ;
V_28 -> V_289 = F_85 ( V_20 -> V_142 ,
sizeof( * V_28 -> V_289 ) , V_32 ) ;
}
}
void F_40 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_18 ; V_30 ++ ) {
V_28 = & V_20 -> V_35 [ V_30 ] ;
F_23 ( V_28 -> V_289 ) ;
V_28 -> V_289 = NULL ;
}
}
void F_173 ( struct V_19 * V_20 ,
struct V_27 * V_28 , T_3 V_284 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_142 ; V_30 ++ ) {
if ( ! V_28 -> V_289 [ V_30 ] ) {
V_28 -> V_289 [ V_30 ] = V_284 ;
V_28 -> V_324 ++ ;
return;
}
}
}
void F_174 ( struct V_19 * V_20 ,
struct V_27 * V_28 , T_3 V_284 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_20 -> V_142 ; V_30 ++ ) {
if ( V_28 -> V_289 [ V_30 ] == V_284 ) {
V_28 -> V_289 [ V_30 ] = 0 ;
V_28 -> V_324 -- ;
return;
}
}
}
bool F_135 ( struct V_27 * V_28 )
{
bool V_29 = false ;
F_102 ( & V_28 -> V_44 ) ;
if ( V_28 -> V_324 )
V_29 = true ;
F_103 ( & V_28 -> V_44 ) ;
return V_29 ;
}
