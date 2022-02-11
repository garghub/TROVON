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
T_1 V_68 , V_74 , V_75 , V_76 , V_77 , V_1 , V_78 = 0 ;
struct V_79 * V_34 = V_6 -> V_34 ;
unsigned long V_62 ;
T_3 V_80 ;
T_2 V_81 ;
int V_30 , V_82 ;
V_80 = ( (struct V_83 * ) V_71 ) -> V_84 ;
if ( ! F_41 ( V_85 , & V_6 -> V_34 -> V_86 . V_87 ) ) {
F_21 ( & V_6 -> V_10 -> V_9 ,
L_6 , V_80 ) ;
F_21 ( & V_6 -> V_10 -> V_9 , L_7 ) ;
return 0 ;
}
F_25 ( & V_34 -> V_88 , V_62 ) ;
V_74 = F_42 ( V_34 , V_89 ) ;
if ( V_74 ) {
F_43 ( V_6 , V_90 , L_6 , V_80 ) ;
F_31 ( & V_34 -> V_88 , V_62 ) ;
return V_91 ;
}
V_1 = V_73 + ( sizeof( struct V_83 ) / sizeof( T_1 ) ) ;
V_77 = 0x31 | ( V_1 << 16 ) | ( V_6 -> V_34 -> V_92 << 29 ) ;
F_44 ( V_77 , F_45 ( V_34 , 0 ) ) ;
V_77 = 0x1 | ( 1 << 4 ) ;
if ( F_19 ( V_6 ) )
V_77 |= ( V_42 << 5 ) ;
F_44 ( V_77 , F_45 ( V_34 , 1 ) ) ;
for ( V_30 = 2 , V_82 = 0 ; V_82 < ( sizeof( struct V_83 ) / sizeof( T_1 ) ) ;
V_30 ++ , V_82 ++ ) {
F_44 ( * ( V_71 ++ ) , F_45 ( V_34 , V_30 ) ) ;
}
for ( V_82 = 0 ; V_82 < V_73 ; V_82 ++ , V_30 ++ )
F_44 ( * ( V_72 ++ ) , F_45 ( V_34 , V_30 ) ) ;
F_46 ( V_34 , V_89 , V_93 ) ;
V_94:
V_68 = F_47 ( V_6 , & V_78 ) ;
if ( V_68 != V_91 ) {
V_75 = F_48 ( F_49 ( V_34 , 0 ) ) ;
if ( V_75 & V_95 ) {
F_50 ( V_6 ) ;
goto V_94;
}
V_81 = F_51 ( V_75 ) ;
V_76 = F_52 ( V_75 ) ;
V_80 = F_53 ( V_75 ) ;
switch ( V_81 ) {
case V_96 :
case V_97 :
V_68 = V_98 ;
break;
default:
if ( V_80 == V_99 ) {
V_68 = F_54 ( V_6 ) ;
if ( ! V_68 )
goto V_100;
}
F_13 ( & V_6 -> V_10 -> V_9 ,
L_8 ,
V_80 , V_81 ) ;
V_68 = V_81 ;
break;
}
goto V_100;
}
F_13 ( & V_6 -> V_10 -> V_9 , L_9 ,
F_53 ( V_77 ) ) ;
V_68 = V_91 ;
V_100:
F_46 ( V_34 , V_101 , V_102 ) ;
F_31 ( & V_6 -> V_34 -> V_88 , V_62 ) ;
return V_68 ;
}
static void F_55 ( struct V_5 * V_6 )
{
V_6 -> V_103 = V_104 ;
V_6 -> V_105 = V_106 ;
V_6 -> V_107 = V_108 ;
V_6 -> V_109 = V_110 ;
V_6 -> V_111 = V_112 ;
V_6 -> V_113 = V_114 ;
}
int F_56 ( struct V_5 * V_6 ,
struct V_115 * V_116 , T_3 V_117 )
{
struct V_118 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_60 V_61 ;
int V_29 ;
T_1 V_87 ;
V_29 = F_57 ( & V_61 , V_6 , V_119 ) ;
if ( V_29 )
return V_29 ;
V_61 . V_65 . V_66 [ 1 ] = V_117 << 16 | 0x1 ;
V_29 = F_58 ( V_6 , & V_61 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_10 , V_29 ) ;
F_29 ( & V_61 ) ;
return V_29 ;
}
V_87 = V_61 . V_68 . V_66 [ 2 ] & 0xffff ;
if ( V_87 & V_120 )
V_116 -> V_121 = F_59 ( V_61 . V_68 . V_66 [ 2 ] ) ;
if ( V_87 & V_122 )
V_116 -> V_52 = F_60 ( V_61 . V_68 . V_66 [ 3 ] ) ;
if ( V_87 & V_123 )
V_116 -> V_124 = F_59 ( V_61 . V_68 . V_66 [ 3 ] ) ;
if ( V_87 & V_125 )
V_116 -> V_126 = F_60 ( V_61 . V_68 . V_66 [ 4 ] ) ;
if ( V_87 & V_127 )
V_116 -> V_128 = F_59 ( V_61 . V_68 . V_66 [ 4 ] ) ;
if ( V_87 & V_129 )
V_116 -> V_130 = F_60 ( V_61 . V_68 . V_66 [ 5 ] ) ;
if ( V_87 & V_131 )
V_116 -> V_132 = F_59 ( V_61 . V_68 . V_66 [ 5 ] ) ;
if ( V_87 & V_133 )
V_116 -> V_134 = F_60 ( V_61 . V_68 . V_66 [ 6 ] ) ;
if ( V_87 & V_135 )
V_116 -> V_136 = F_59 ( V_61 . V_68 . V_66 [ 6 ] ) ;
if ( V_87 & V_137 )
V_116 -> V_138 = F_60 ( V_61 . V_68 . V_66 [ 7 ] ) ;
V_116 -> V_139 = F_59 ( V_61 . V_68 . V_66 [ 7 ] ) ;
V_116 -> V_140 = F_60 ( V_61 . V_68 . V_66 [ 8 ] ) ;
V_116 -> V_141 = F_59 ( V_61 . V_68 . V_66 [ 8 ] ) ;
V_116 -> V_142 = F_60 ( V_61 . V_68 . V_66 [ 9 ] ) ;
F_21 ( V_9 , L_11
L_12
L_13
L_14
L_15
L_16 ,
V_116 -> V_121 , V_116 -> V_52 ,
V_116 -> V_124 , V_116 -> V_126 ,
V_116 -> V_128 ,
V_116 -> V_130 , V_116 -> V_132 ,
V_116 -> V_134 , V_116 -> V_136 ,
V_116 -> V_138 , V_116 -> V_139 ,
V_116 -> V_140 , V_116 -> V_141 ,
V_116 -> V_142 ) ;
F_29 ( & V_61 ) ;
return V_29 ;
}
static int F_61 ( struct V_5 * V_6 ,
struct V_60 * V_61 )
{
V_6 -> V_143 = ( V_61 -> V_68 . V_66 [ 1 ] >> 16 ) & 0xffff ;
V_6 -> V_62 &= ~ V_144 ;
return 0 ;
}
static int F_62 ( struct V_5 * V_6 ,
struct V_60 * V_61 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
int V_30 , V_145 ;
T_3 * V_146 ;
if ( V_20 -> V_147 )
return 0 ;
V_20 -> V_148 = V_61 -> V_68 . V_66 [ 2 ] & 0xf ;
if ( ! V_20 -> V_148 )
return 0 ;
V_20 -> V_149 = V_61 -> V_68 . V_66 [ 2 ] >> 16 ;
V_145 = V_20 -> V_149 ;
V_20 -> V_147 = F_11 ( sizeof( T_3 ) * V_145 , V_32 ) ;
if ( ! V_20 -> V_147 )
return - V_33 ;
V_146 = ( T_3 * ) & V_61 -> V_68 . V_66 [ 3 ] ;
for ( V_30 = 0 ; V_30 < V_145 ; V_30 ++ )
V_20 -> V_147 [ V_30 ] = V_146 [ V_30 ] ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_60 V_61 ;
int V_150 ;
V_150 = F_64 ( & V_61 , V_151 ) ;
if ( V_150 )
return V_150 ;
V_150 = F_58 ( V_6 , & V_61 ) ;
if ( V_150 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_17 ,
V_150 ) ;
} else {
V_20 -> V_152 = V_61 . V_68 . V_66 [ 1 ] & 0x3 ;
switch ( V_20 -> V_152 ) {
case V_153 :
V_150 = F_62 ( V_6 , & V_61 ) ;
break;
case V_154 :
V_150 = F_61 ( V_6 , & V_61 ) ;
break;
}
}
F_29 ( & V_61 ) ;
return V_150 ;
}
static int F_65 ( struct V_5 * V_6 )
{
struct V_115 V_155 ;
struct V_79 * V_34 = V_6 -> V_34 ;
int V_29 ;
V_29 = F_56 ( V_6 , & V_155 , 0 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_66 ( V_6 , & V_155 , V_34 -> V_42 ) ;
if ( V_29 )
return - V_31 ;
V_29 = F_63 ( V_6 ) ;
if ( V_29 )
return V_29 ;
if ( F_67 ( V_6 ) )
return - V_31 ;
F_55 ( V_6 ) ;
V_6 -> V_62 |= V_156 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_18 ,
V_6 -> V_34 -> V_92 ) ;
V_34 -> V_157 = ( T_2 ) V_155 . V_158 ;
V_34 -> V_159 = V_155 . V_159 ;
V_34 -> V_160 = V_155 . V_160 ;
V_34 -> V_161 = V_155 . V_161 ;
V_34 -> V_162 = V_155 . V_162 ;
return 0 ;
}
static int F_68 ( struct V_5 * V_6 ,
int V_163 )
{
int V_29 ;
F_14 ( & V_6 -> V_164 ) ;
if ( ! V_165 && ! ! V_166 )
F_69 ( & V_6 -> V_10 -> V_9 ,
L_19 ) ;
V_29 = F_70 ( V_6 , 1 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_20 ) ;
goto V_167;
}
V_29 = F_71 ( V_6 ) ;
if ( V_29 )
goto V_167;
V_29 = F_9 ( V_6 , 1 ) ;
if ( V_29 )
goto V_168;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
goto V_169;
V_29 = F_36 ( V_6 , V_170 ) ;
if ( V_29 )
goto V_171;
V_29 = F_65 ( V_6 ) ;
if ( V_29 )
goto V_172;
V_29 = F_72 ( V_6 , V_6 -> V_173 , V_163 ) ;
if ( V_29 )
goto V_172;
F_73 ( V_6 -> V_10 , V_6 ) ;
F_21 ( & V_6 -> V_10 -> V_9 , L_21 ,
V_6 -> V_173 -> V_174 ) ;
F_74 ( V_6 , V_175 ,
V_6 -> V_34 -> V_86 . V_176 ) ;
return 0 ;
V_172:
F_36 ( V_6 , V_70 ) ;
V_171:
F_37 ( V_6 , 0 ) ;
V_169:
F_32 ( V_6 ) ;
V_168:
F_75 ( V_6 ) ;
V_167:
F_76 ( V_6 ) ;
return V_29 ;
}
static int F_77 ( struct V_5 * V_6 )
{
T_1 V_177 ;
do {
F_78 ( 20 ) ;
if ( ++ V_6 -> V_178 > V_179 )
return - V_31 ;
V_177 = F_42 ( V_6 -> V_34 , V_180 ) ;
} while ( V_177 != V_181 );
return 0 ;
}
int F_79 ( struct V_5 * V_6 , int V_163 )
{
struct V_79 * V_34 = V_6 -> V_34 ;
int V_29 ;
F_16 ( & V_34 -> V_88 ) ;
F_80 ( V_85 , & V_34 -> V_86 . V_87 ) ;
F_80 ( V_182 , & V_34 -> V_86 . V_87 ) ;
V_34 -> V_86 . V_176 = V_183 ;
V_34 -> V_184 = 0 ;
V_6 -> V_178 = 0 ;
V_34 -> V_185 = 1 ;
V_6 -> V_186 = 0 ;
V_6 -> V_62 |= V_187 ;
V_29 = F_77 ( V_6 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_68 ( V_6 , V_163 ) ;
if ( V_29 )
return V_29 ;
if ( F_81 ( V_6 ) )
F_69 ( & V_6 -> V_10 -> V_9 , L_22 ) ;
F_82 ( & V_6 -> V_188 , V_189 ) ;
F_83 ( V_190 , & V_6 -> V_177 ) ;
return 0 ;
}
void F_84 ( struct V_5 * V_6 )
{
struct V_79 * V_34 = V_6 -> V_34 ;
V_34 -> V_161 = V_191 ;
F_21 ( & V_6 -> V_10 -> V_9 ,
L_23 ,
V_34 -> V_92 ) ;
V_6 -> V_192 = & V_193 ;
F_80 ( V_194 , & V_6 -> V_177 ) ;
return;
}
void F_85 ( struct V_79 * V_34 )
{
V_34 -> V_195 = & V_196 ;
V_34 -> V_197 = ( T_1 * ) V_198 ;
V_34 -> V_199 = ( T_1 * ) V_200 ;
}
static T_1 F_86 ( T_1 V_201 , T_2 V_202 )
{
T_1 V_203 ;
V_203 = V_201 / ( ( V_202 + 1 ) * V_204 ) ;
if ( V_203 )
V_203 = V_204 ;
else
V_203 = V_201 % V_204 ;
return V_203 ;
}
int F_87 ( struct V_5 * V_6 , T_2 V_42 )
{
struct V_27 * V_35 = V_6 -> V_34 -> V_20 -> V_35 ;
T_2 V_30 ;
if ( F_6 ( V_6 ) )
return 0 ;
for ( V_30 = 0 ; V_30 < V_6 -> V_34 -> V_20 -> V_18 ; V_30 ++ ) {
if ( V_35 [ V_30 ] . V_42 == V_42 )
return V_30 ;
}
return - V_205 ;
}
static inline int F_88 ( struct V_58 * * V_59 )
{
* V_59 = F_11 ( sizeof( struct V_58 ) , V_206 ) ;
if ( ! * V_59 )
return - V_33 ;
F_17 ( & ( * V_59 ) -> V_207 ) ;
return 0 ;
}
static inline int F_89 ( struct V_83 * * V_71 ,
T_1 V_73 )
{
* V_71 = F_11 ( sizeof( struct V_83 ) * V_73 , V_206 ) ;
if ( ! * V_71 )
return - V_33 ;
return 0 ;
}
static int F_64 ( struct V_60 * V_208 , T_1 type )
{
const struct V_209 * V_210 ;
int V_30 , V_73 ;
V_210 = V_211 ;
V_73 = F_90 ( V_211 ) ;
for ( V_30 = 0 ; V_30 < V_73 ; V_30 ++ ) {
if ( type == V_210 [ V_30 ] . V_61 ) {
V_208 -> V_212 = V_213 ;
V_208 -> V_65 . V_214 = V_210 [ V_30 ] . V_215 ;
V_208 -> V_68 . V_214 = V_210 [ V_30 ] . V_216 ;
V_208 -> V_65 . V_66 = F_91 ( V_208 -> V_65 . V_214 , sizeof( T_1 ) ,
V_206 ) ;
if ( ! V_208 -> V_65 . V_66 )
return - V_33 ;
V_208 -> V_68 . V_66 = F_91 ( V_208 -> V_68 . V_214 , sizeof( T_1 ) ,
V_206 ) ;
if ( ! V_208 -> V_68 . V_66 ) {
F_23 ( V_208 -> V_65 . V_66 ) ;
V_208 -> V_65 . V_66 = NULL ;
return - V_33 ;
}
memset ( V_208 -> V_65 . V_66 , 0 , sizeof( T_1 ) * V_208 -> V_65 . V_214 ) ;
memset ( V_208 -> V_68 . V_66 , 0 , sizeof( T_1 ) * V_208 -> V_68 . V_214 ) ;
V_208 -> V_65 . V_66 [ 0 ] = ( type | ( V_208 -> V_65 . V_214 << 16 ) |
( 3 << 29 ) ) ;
V_208 -> V_68 . V_66 [ 0 ] = ( type & 0xffff ) | V_208 -> V_68 . V_214 << 16 ;
return 0 ;
}
}
return - V_205 ;
}
static int F_92 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
T_3 V_217 , T_2 V_218 )
{
struct V_83 * V_71 ;
int V_30 ;
T_1 V_219 , V_220 ;
T_3 V_221 ;
T_2 V_84 , V_222 , V_223 ;
V_220 = V_204 ;
if ( V_218 == V_224 ) {
V_59 -> V_67 = (struct V_225 * ) V_61 -> V_65 . V_66 ;
V_59 -> V_69 = (struct V_225 * ) V_61 -> V_68 . V_66 ;
V_219 = V_61 -> V_65 . V_214 ;
V_59 -> V_226 = ( V_219 * 4 ) ;
V_219 = V_61 -> V_68 . V_214 ;
V_59 -> V_227 = ( V_219 * 4 ) ;
V_84 = V_61 -> V_65 . V_66 [ 0 ] & 0xff ;
V_221 = ( V_59 -> V_226 ) % ( V_220 ) ;
V_222 = ( V_59 -> V_226 ) / ( V_220 ) ;
if ( V_221 )
V_222 ++ ;
V_223 = V_222 ;
if ( F_89 ( & V_59 -> V_228 , V_222 ) )
return - V_33 ;
V_221 = ( V_59 -> V_227 ) % ( V_220 ) ;
V_222 = ( V_59 -> V_227 ) / ( V_220 ) ;
if ( V_221 )
V_222 ++ ;
if ( F_89 ( & V_59 -> V_229 , V_222 ) )
return - V_33 ;
V_222 = V_223 ;
V_71 = V_59 -> V_228 ;
} else {
V_61 -> V_65 . V_66 = ( T_1 * ) V_59 -> V_67 ;
V_61 -> V_68 . V_66 = ( T_1 * ) V_59 -> V_69 ;
V_84 = V_61 -> V_65 . V_66 [ 0 ] & 0xff ;
V_221 = ( V_59 -> V_227 ) % ( V_220 ) ;
V_222 = ( V_59 -> V_227 ) / ( V_220 ) ;
if ( V_221 )
V_222 ++ ;
V_61 -> V_65 . V_214 = V_59 -> V_226 / 4 ;
V_61 -> V_68 . V_214 = V_59 -> V_227 / 4 ;
V_71 = V_59 -> V_229 ;
V_61 -> V_212 = V_59 -> V_228 -> V_212 ;
}
V_59 -> V_230 = V_217 ;
V_59 -> V_231 = V_84 ;
for ( V_30 = 0 ; V_30 < V_222 ; V_30 ++ ) {
V_71 [ V_30 ] . V_232 = 2 ;
V_71 [ V_30 ] . V_218 = V_218 ;
V_71 [ V_30 ] . V_212 = V_61 -> V_212 ;
V_71 [ V_30 ] . V_233 = 1 ;
V_71 [ V_30 ] . V_222 = V_222 ;
V_71 [ V_30 ] . V_234 = V_30 + 1 ;
V_71 [ V_30 ] . V_84 = V_84 ;
V_71 [ V_30 ] . V_235 = V_217 ;
}
return 0 ;
}
static void F_30 ( struct V_58 * V_59 )
{
if ( ! V_59 )
return;
F_23 ( V_59 -> V_228 ) ;
F_23 ( V_59 -> V_229 ) ;
F_23 ( V_59 ) ;
}
static int F_93 ( struct V_27 * V_28 ,
struct V_58 * V_59 , T_2 type )
{
struct V_56 * V_57 ;
unsigned long V_62 ;
int V_150 = 0 ;
if ( type == V_236 ) {
V_57 = & V_28 -> V_44 ;
F_25 ( & V_57 -> V_47 , V_62 ) ;
V_57 -> V_64 -- ;
F_28 ( & V_59 -> V_63 ) ;
if ( V_57 -> V_64 > 0 )
V_150 = 1 ;
F_31 ( & V_57 -> V_47 , V_62 ) ;
}
if ( type == V_224 ) {
while ( F_94 ( V_237 , & V_28 -> V_177 ) )
F_78 ( 100 ) ;
V_28 -> V_238 = NULL ;
F_83 ( V_237 , & V_28 -> V_177 ) ;
}
return V_150 ;
}
static void F_95 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
T_4 V_239 )
{
if ( F_41 ( V_240 , & V_28 -> V_177 ) ||
V_28 -> V_6 -> V_186 )
return;
F_96 ( V_20 -> V_22 . V_38 , & V_28 -> V_49 ) ;
}
static inline void F_97 ( struct V_58 * V_59 )
{
struct V_241 * V_242 = & V_59 -> V_207 ;
if ( F_98 ( V_242 , V_243 ) )
V_59 -> V_244 = V_245 ;
else
V_59 -> V_244 = V_246 ;
return;
}
static void F_99 ( struct V_58 * V_59 ,
T_2 type )
{
if ( type == V_236 ) {
V_59 -> V_247 ++ ;
if ( V_59 -> V_247 < V_59 -> V_229 -> V_222 )
V_59 -> V_244 = V_248 ;
else
V_59 -> V_244 = V_245 ;
} else {
V_59 -> V_249 ++ ;
if ( V_59 -> V_249 < V_59 -> V_228 -> V_222 )
V_59 -> V_244 = V_248 ;
else
V_59 -> V_244 = V_250 ;
}
}
static void F_100 ( struct V_58 * V_59 ,
T_2 type )
{
struct V_27 * V_28 = V_59 -> V_28 ;
struct V_241 * V_242 = & V_28 -> V_48 ;
if ( ! F_98 ( V_242 , V_251 ) ) {
V_59 -> V_244 = V_246 ;
return;
}
F_83 ( V_252 , & V_28 -> V_177 ) ;
F_99 ( V_59 , type ) ;
}
static void F_101 ( struct V_5 * V_6 ,
T_1 * V_71 , T_1 * V_72 , T_1 V_73 )
{
struct V_79 * V_34 = V_6 -> V_34 ;
T_1 V_253 ;
T_2 V_30 , V_254 = 2 , V_255 , V_82 ;
V_255 = ( sizeof( struct V_83 ) / sizeof( T_1 ) ) ;
V_254 = ( V_73 / sizeof( T_1 ) ) + V_255 ;
V_253 = F_48 ( F_49 ( V_34 , 0 ) ) ;
for ( V_30 = 2 , V_82 = 0 ; V_82 < V_255 ; V_30 ++ , V_82 ++ )
* ( V_71 ++ ) = F_48 ( F_49 ( V_34 , V_30 ) ) ;
for (; V_82 < V_254 ; V_30 ++ , V_82 ++ )
* ( V_72 ++ ) = F_48 ( F_49 ( V_34 , V_30 ) ) ;
}
static int F_102 ( struct V_27 * V_28 )
{
int V_150 = - V_256 ;
T_1 V_257 = 10000 ;
do {
if ( ! F_94 ( V_252 , & V_28 -> V_177 ) ) {
V_150 = 0 ;
break;
}
F_103 ( 1 ) ;
} while ( -- V_257 );
return V_150 ;
}
static int F_104 ( struct V_58 * V_59 , T_2 type )
{
struct V_27 * V_28 = V_59 -> V_28 ;
T_1 V_203 , V_255 ;
T_1 * V_71 , * V_72 ;
int V_150 ;
T_2 V_42 = V_59 -> V_258 ;
if ( F_102 ( V_28 ) )
return - V_256 ;
if ( type == V_224 ) {
V_71 = ( T_1 * ) ( V_59 -> V_228 + V_59 -> V_249 ) ;
V_72 = ( T_1 * ) ( V_59 -> V_67 + V_59 -> V_249 ) ;
V_255 = ( sizeof( struct V_83 ) / sizeof( T_1 ) ) ;
V_203 = F_86 ( V_59 -> V_226 ,
V_59 -> V_249 ) ;
V_203 = ( V_203 / sizeof( T_1 ) ) ;
} else {
V_71 = ( T_1 * ) ( V_59 -> V_229 + V_59 -> V_247 ) ;
V_72 = ( T_1 * ) ( V_59 -> V_69 + V_59 -> V_247 ) ;
V_255 = ( sizeof( struct V_83 ) / sizeof( T_1 ) ) ;
V_203 = F_86 ( V_59 -> V_227 ,
V_59 -> V_247 ) ;
V_203 = ( V_203 / sizeof( T_1 ) ) ;
}
V_150 = F_40 ( V_28 -> V_6 , V_71 , V_72 ,
V_42 , V_203 ) ;
return V_150 ;
}
static int F_105 ( struct V_58 * V_59 ,
struct V_27 * V_28 , T_2 type )
{
bool V_259 = true ;
int V_29 = - V_31 ;
while ( V_259 ) {
if ( F_41 ( V_240 , & V_28 -> V_177 ) ||
V_28 -> V_6 -> V_186 )
V_59 -> V_244 = V_246 ;
switch ( V_59 -> V_244 ) {
case V_248 :
V_59 -> V_244 = V_260 ;
if ( F_104 ( V_59 , type ) )
V_59 -> V_244 = V_246 ;
break;
case V_260 :
F_100 ( V_59 , type ) ;
break;
case V_250 :
F_97 ( V_59 ) ;
break;
case V_245 :
V_29 = 0 ;
V_259 = false ;
break;
case V_246 :
V_29 = - V_31 ;
V_259 = false ;
F_83 ( V_252 , & V_28 -> V_177 ) ;
break;
default:
V_29 = - V_31 ;
V_259 = false ;
}
}
return V_29 ;
}
static int F_106 ( struct V_5 * V_6 ,
struct V_58 * V_59 , int V_42 )
{
struct V_27 * V_28 ;
int V_29 , V_261 = F_87 ( V_6 , V_42 ) ;
if ( V_261 < 0 )
return - V_31 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ V_261 ] ;
V_59 -> V_28 = V_28 ;
V_59 -> V_258 = V_42 ;
if ( ! F_41 ( V_262 , & V_28 -> V_177 ) ) {
if ( F_19 ( V_6 ) )
return - V_31 ;
if ( F_6 ( V_6 ) &&
V_59 -> V_231 != V_170 )
return - V_31 ;
}
F_107 ( & V_28 -> V_43 ) ;
V_28 -> V_238 = V_59 ;
V_29 = F_105 ( V_59 , V_28 , V_224 ) ;
F_93 ( V_28 , V_59 , V_224 ) ;
F_108 ( & V_28 -> V_43 ) ;
return V_29 ;
}
static void F_109 ( struct V_5 * V_6 ,
struct V_58 * V_59 ,
struct V_60 * V_61 )
{
#ifdef F_110
if ( F_19 ( V_6 ) ) {
F_111 ( V_6 , V_59 , V_61 ) ;
return;
}
#endif
V_61 -> V_68 . V_66 [ 0 ] |= ( 0x9 << 25 ) ;
return;
}
static void V_50 ( struct V_263 * V_264 )
{
struct V_27 * V_28 = F_112 ( V_264 , struct V_27 ,
V_49 ) ;
struct V_58 * V_59 = NULL ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_60 V_61 ;
T_2 V_65 ;
if ( V_6 -> V_186 )
return;
if ( F_41 ( V_240 , & V_28 -> V_177 ) )
return;
V_59 = F_27 ( & V_28 -> V_44 . V_45 ,
struct V_58 , V_63 ) ;
V_6 = V_28 -> V_6 ;
if ( F_92 ( V_59 , & V_61 , V_59 -> V_228 -> V_235 ,
V_236 ) )
goto V_265;
F_109 ( V_6 , V_59 , & V_61 ) ;
V_59 -> V_244 = V_248 ;
F_105 ( V_59 , V_28 , V_236 ) ;
V_265:
F_29 ( & V_61 ) ;
V_65 = F_93 ( V_28 , V_59 , V_236 ) ;
F_30 ( V_59 ) ;
if ( V_65 )
F_95 ( V_6 -> V_34 -> V_20 , V_28 ,
V_50 ) ;
}
static void F_113 ( struct V_83 * V_71 ,
struct V_27 * V_28 )
{
struct V_58 * V_59 ;
T_1 V_203 ;
if ( F_94 ( V_237 , & V_28 -> V_177 ) )
return;
V_59 = V_28 -> V_238 ;
if ( V_59 == NULL )
goto V_266;
if ( V_59 -> V_230 != V_71 -> V_235 )
goto V_266;
V_203 = F_86 ( V_59 -> V_227 ,
V_59 -> V_247 ) ;
F_101 ( V_28 -> V_6 ,
( T_1 * ) ( V_59 -> V_229 + V_59 -> V_247 ) ,
( T_1 * ) ( V_59 -> V_69 + V_59 -> V_247 ) ,
V_203 ) ;
if ( ++ V_59 -> V_247 < V_59 -> V_229 -> V_222 )
goto V_266;
F_114 ( & V_59 -> V_207 ) ;
V_266:
F_83 ( V_237 , & V_28 -> V_177 ) ;
}
int F_115 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_58 * V_59 )
{
struct V_56 * V_57 = & V_28 -> V_44 ;
V_57 -> V_64 ++ ;
F_116 ( & V_59 -> V_63 , & V_57 -> V_45 ) ;
if ( V_57 -> V_64 == 1 )
F_95 ( V_20 , V_28 ,
V_50 ) ;
return 0 ;
}
static int F_117 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_58 * V_59 )
{
struct V_56 * V_57 = & V_28 -> V_44 ;
F_118 ( & V_57 -> V_47 ) ;
F_115 ( V_20 , V_28 , V_59 ) ;
F_119 ( & V_57 -> V_47 ) ;
return 0 ;
}
static void F_120 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_83 * V_71 )
{
struct V_58 * V_59 = NULL ;
struct V_267 * V_268 ;
T_1 V_203 , V_202 ;
T_2 V_269 = 0 , V_270 = 0 ;
F_118 ( & V_28 -> V_46 . V_47 ) ;
if ( V_28 -> V_46 . V_64 > 0 ) {
F_121 (node, &vf->rcv_pend.wait_list) {
V_59 = F_122 ( V_268 , struct V_58 , V_63 ) ;
if ( V_59 -> V_230 == V_71 -> V_235 ) {
V_269 = 1 ;
break;
}
}
}
if ( V_269 ) {
V_202 = V_59 -> V_249 ;
V_203 = F_86 ( V_59 -> V_226 ,
V_202 ) ;
F_101 ( V_28 -> V_6 ,
( T_1 * ) ( V_59 -> V_228 + V_202 ) ,
( T_1 * ) ( V_59 -> V_67 + V_202 ) ,
V_203 ) ;
V_59 -> V_249 ++ ;
if ( V_59 -> V_249 >= V_71 -> V_222 ) {
V_28 -> V_46 . V_64 -- ;
F_28 ( & V_59 -> V_63 ) ;
V_270 = 1 ;
}
}
F_119 ( & V_28 -> V_46 . V_47 ) ;
if ( V_270 )
if ( F_117 ( V_20 , V_28 , V_59 ) )
F_30 ( V_59 ) ;
return;
}
static void F_123 ( struct V_19 * V_20 ,
struct V_83 * V_71 ,
struct V_27 * V_28 )
{
struct V_58 * V_59 ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_60 V_61 ;
T_1 V_203 ;
int V_29 ;
T_2 V_84 ;
if ( V_6 -> V_186 )
return;
if ( ! F_41 ( V_262 , & V_28 -> V_177 ) &&
V_71 -> V_212 != V_213 &&
V_71 -> V_84 != V_170 )
return;
if ( V_71 -> V_234 > 1 ) {
F_120 ( V_20 , V_28 , V_71 ) ;
return;
}
V_84 = V_71 -> V_84 ;
if ( F_88 ( & V_59 ) )
return;
if ( V_71 -> V_212 == V_213 )
V_29 = F_64 ( & V_61 , V_84 ) ;
else
V_29 = F_57 ( & V_61 , V_6 , V_84 ) ;
if ( V_29 ) {
F_30 ( V_59 ) ;
return;
}
V_61 . V_212 = V_71 -> V_212 ;
if ( F_92 ( V_59 , & V_61 , V_71 -> V_235 ,
V_224 ) ) {
F_29 ( & V_61 ) ;
F_30 ( V_59 ) ;
return;
}
V_203 = F_86 ( V_59 -> V_226 ,
V_59 -> V_249 ) ;
F_101 ( V_28 -> V_6 ,
( T_1 * ) ( V_59 -> V_228 + V_59 -> V_249 ) ,
( T_1 * ) ( V_59 -> V_67 + V_59 -> V_249 ) ,
V_203 ) ;
V_59 -> V_258 = V_28 -> V_42 ;
V_59 -> V_28 = V_28 ;
V_59 -> V_230 = V_71 -> V_235 ;
V_59 -> V_249 ++ ;
if ( F_124 ( V_6 , V_59 , V_28 ) )
return;
if ( V_59 -> V_249 == V_59 -> V_228 -> V_222 ) {
if ( F_117 ( V_20 , V_28 , V_59 ) ) {
F_29 ( & V_61 ) ;
F_30 ( V_59 ) ;
}
} else {
F_118 ( & V_28 -> V_46 . V_47 ) ;
F_116 ( & V_59 -> V_63 , & V_28 -> V_46 . V_45 ) ;
V_28 -> V_46 . V_64 ++ ;
F_119 ( & V_28 -> V_46 . V_47 ) ;
}
}
static void F_125 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
struct V_83 V_71 ;
T_1 * V_271 = ( T_1 * ) & V_71 ;
T_2 V_218 , V_30 ;
for ( V_30 = 2 ; V_30 < 6 ; V_30 ++ )
V_271 [ V_30 - 2 ] = F_48 ( F_49 ( V_28 -> V_6 -> V_34 , V_30 ) ) ;
V_218 = V_71 . V_218 ;
switch ( V_218 ) {
case V_224 :
F_123 ( V_20 , & V_71 , V_28 ) ;
break;
case V_236 :
F_113 ( & V_71 , V_28 ) ;
break;
}
}
static void F_126 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_28 -> V_6 ;
if ( F_19 ( V_6 ) )
F_127 ( V_20 , V_28 ) ;
else
F_13 ( & V_6 -> V_10 -> V_9 ,
L_24 ) ;
}
void F_128 ( struct V_5 * V_6 , T_1 V_272 )
{
struct V_27 * V_28 ;
struct V_19 * V_20 ;
int V_261 ;
T_2 V_42 ;
V_20 = V_6 -> V_34 -> V_20 ;
V_42 = F_4 ( V_272 ) ;
V_261 = F_87 ( V_6 , V_42 ) ;
if ( V_261 < 0 )
return;
V_28 = & V_20 -> V_35 [ V_261 ] ;
V_28 -> V_42 = V_42 ;
if ( F_2 ( V_272 ) )
F_114 ( & V_28 -> V_48 ) ;
if ( F_3 ( V_272 ) ) {
F_126 ( V_20 , V_28 ) ;
return;
}
if ( F_1 ( V_272 ) )
F_125 ( V_20 , V_28 ) ;
}
int F_37 ( struct V_5 * V_6 , T_2 V_273 )
{
struct V_60 V_61 ;
int V_29 ;
if ( ! F_41 ( V_194 , & V_6 -> V_177 ) )
return 0 ;
if ( F_57 ( & V_61 , V_6 , V_274 ) )
return - V_33 ;
if ( V_273 )
V_61 . V_65 . V_66 [ 1 ] = ( 1 << 4 ) | ( 1 << 5 ) | ( 1 << 6 ) | ( 1 << 7 ) ;
V_29 = F_129 ( V_6 , & V_61 ) ;
if ( V_29 != V_98 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_25 ,
( V_273 ? L_26 : L_27 ) , V_29 ) ;
}
F_29 ( & V_61 ) ;
return V_29 ;
}
static int F_130 ( struct V_5 * V_6 ,
struct V_58 * V_59 )
{
T_2 V_254 = V_179 ;
T_1 V_177 ;
V_177 = F_42 ( V_6 -> V_34 , V_180 ) ;
if ( V_177 == V_181 ) {
F_78 ( 20 ) ;
F_83 ( V_252 , & V_59 -> V_28 -> V_177 ) ;
V_59 -> V_244 = V_248 ;
if ( ++ V_6 -> V_178 > V_254 )
return - V_31 ;
else
return 0 ;
}
return - V_31 ;
}
static int F_131 ( struct V_5 * V_6 ,
struct V_60 * V_61 )
{
struct V_79 * V_34 = V_6 -> V_34 ;
struct V_118 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_58 * V_59 ;
int V_29 ;
T_1 V_275 , V_80 , V_81 , V_68 ;
T_3 V_217 = ++ V_6 -> V_34 -> V_20 -> V_22 . V_276 ;
T_2 V_239 = V_34 -> V_42 ;
V_68 = F_88 ( & V_59 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_92 ( V_59 , V_61 , V_217 , V_224 ) ;
if ( V_68 )
goto V_277;
V_278:
if ( ! F_41 ( V_85 , & V_6 -> V_34 -> V_86 . V_87 ) ) {
V_68 = - V_31 ;
F_43 ( V_6 , V_90 , L_28 ,
F_53 ( V_61 -> V_65 . V_66 [ 0 ] ) , V_239 ) ;
goto V_279;
}
V_29 = F_106 ( V_6 , V_59 , V_239 ) ;
if ( V_29 ) {
F_13 ( V_9 , L_29 ,
( V_61 -> V_65 . V_66 [ 0 ] & 0xffff ) , V_239 ) ;
V_68 = V_91 ;
if ( ( V_59 -> V_228 -> V_84 == V_170 ) &&
! F_130 ( V_6 , V_59 ) )
goto V_278;
goto V_279;
}
V_275 = V_61 -> V_68 . V_66 [ 0 ] ;
V_81 = F_51 ( V_275 ) ;
V_80 = F_53 ( V_61 -> V_65 . V_66 [ 0 ] ) ;
if ( ( V_81 == V_96 ) ||
( V_81 == V_97 ) ) {
V_68 = V_98 ;
} else {
V_68 = V_81 ;
if ( ! V_68 )
V_68 = 1 ;
F_13 ( V_9 ,
L_30 ,
V_80 , V_81 , V_239 ) ;
}
V_279:
if ( V_68 == V_91 ) {
V_34 -> V_184 = 1 ;
V_6 -> V_186 = 1 ;
F_83 ( V_85 , & V_34 -> V_86 . V_87 ) ;
}
V_277:
F_30 ( V_59 ) ;
return V_68 ;
}
int F_36 ( struct V_5 * V_6 , T_2 V_84 )
{
struct V_60 V_61 ;
struct V_27 * V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
int V_150 ;
if ( F_64 ( & V_61 , V_84 ) )
return - V_33 ;
V_150 = F_58 ( V_6 , & V_61 ) ;
if ( V_150 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_31 , V_84 ? L_32 : L_33 ,
V_150 ) ;
goto V_100;
}
V_84 = ( V_61 . V_68 . V_66 [ 0 ] & 0xff ) ;
if ( V_61 . V_68 . V_66 [ 0 ] >> 25 == 2 )
return 2 ;
if ( V_84 == V_170 )
F_80 ( V_262 , & V_28 -> V_177 ) ;
else
F_83 ( V_262 , & V_28 -> V_177 ) ;
V_100:
F_29 ( & V_61 ) ;
return V_150 ;
}
void F_132 ( struct V_280 * V_173 , T_3 V_281 )
{
struct V_5 * V_6 = F_133 ( V_173 ) ;
struct V_282 * V_283 ;
struct V_267 * V_284 , V_285 ;
F_14 ( & V_285 ) ;
V_284 = & V_6 -> V_164 ;
F_134 ( V_173 ) ;
while ( ! F_26 ( V_284 ) ) {
V_283 = F_122 ( V_284 -> V_286 , struct V_282 , V_63 ) ;
F_135 ( & V_283 -> V_63 , & V_285 ) ;
}
F_136 ( V_173 ) ;
while ( ! F_26 ( & V_285 ) ) {
V_283 = F_122 ( ( & V_285 ) -> V_286 ,
struct V_282 , V_63 ) ;
F_137 ( V_6 , V_283 -> V_287 , V_281 ) ;
F_28 ( & V_283 -> V_63 ) ;
F_23 ( V_283 ) ;
}
}
void F_33 ( struct V_21 * V_22 )
{
struct V_267 * V_284 = & V_22 -> V_41 ;
struct V_288 * V_289 ;
while ( ! F_26 ( V_284 ) ) {
V_289 = F_122 ( V_284 -> V_286 , struct V_288 ,
V_63 ) ;
F_34 ( & V_289 -> V_264 ) ;
F_28 ( & V_289 -> V_63 ) ;
F_23 ( V_289 ) ;
}
}
static void F_138 ( struct V_280 * V_173 )
{
struct V_5 * V_6 = F_133 ( V_173 ) ;
T_3 V_281 ;
if ( ! F_41 ( V_290 , & V_6 -> V_177 ) )
return;
V_281 = V_6 -> V_34 -> V_20 -> V_281 ;
F_139 ( V_173 , V_281 ) ;
}
static void F_140 ( struct V_263 * V_264 )
{
struct V_288 * V_289 ;
struct V_280 * V_173 ;
V_289 = F_112 ( V_264 , struct V_288 , V_264 ) ;
V_173 = (struct V_280 * ) V_289 -> V_271 ;
F_138 ( V_173 ) ;
return;
}
static struct V_288 *
F_141 ( struct V_21 * V_22 )
{
struct V_267 * V_268 ;
struct V_288 * V_289 = NULL ;
T_2 V_291 = 0 ;
F_121 (node, &bc->async_list) {
V_289 = F_122 ( V_268 , struct V_288 , V_63 ) ;
if ( ! F_142 ( & V_289 -> V_264 ) ) {
V_291 = 1 ;
break;
}
}
if ( ! V_291 ) {
V_289 = F_11 ( sizeof( struct V_288 ) ,
V_206 ) ;
if ( V_289 == NULL )
return NULL ;
F_116 ( & V_289 -> V_63 , & V_22 -> V_41 ) ;
}
return V_289 ;
}
static void F_143 ( struct V_21 * V_22 ,
T_4 V_239 , void * V_292 )
{
struct V_288 * V_289 = NULL ;
V_289 = F_141 ( V_22 ) ;
if ( ! V_289 )
return;
V_289 -> V_271 = V_292 ;
F_18 ( & V_289 -> V_264 , V_239 ) ;
F_96 ( V_22 -> V_40 , & V_289 -> V_264 ) ;
}
void F_144 ( struct V_280 * V_173 )
{
struct V_5 * V_6 = F_133 ( V_173 ) ;
struct V_21 * V_22 = & V_6 -> V_34 -> V_20 -> V_22 ;
if ( V_6 -> V_186 )
return;
F_143 ( V_22 , F_140 ,
V_173 ) ;
}
static int F_145 ( struct V_5 * V_6 )
{
int V_29 ;
F_80 ( V_85 , & V_6 -> V_34 -> V_86 . V_87 ) ;
F_146 ( V_6 ) ;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_6 , V_170 ) ;
if ( V_29 )
goto V_293;
V_29 = F_65 ( V_6 ) ;
if ( V_29 )
goto V_294;
return 0 ;
V_294:
F_36 ( V_6 , V_70 ) ;
V_293:
F_37 ( V_6 , 0 ) ;
return V_29 ;
}
static void F_147 ( struct V_5 * V_6 )
{
struct V_280 * V_173 = V_6 -> V_173 ;
if ( F_148 ( V_173 ) ) {
if ( ! F_149 ( V_6 , V_173 ) )
F_150 ( V_173 , V_295 ) ;
}
F_151 ( V_173 ) ;
}
static void F_152 ( struct V_5 * V_6 )
{
struct V_79 * V_34 = V_6 -> V_34 ;
struct V_296 * V_297 = V_34 -> V_297 ;
struct V_280 * V_173 = V_6 -> V_173 ;
T_2 V_30 , V_298 = V_34 -> V_299 - 1 ;
F_153 ( V_6 ) ;
F_154 ( V_173 ) ;
if ( F_148 ( V_173 ) )
F_155 ( V_6 , V_173 ) ;
for ( V_30 = 0 ; V_30 < V_298 ; V_30 ++ ) {
V_297 [ V_30 ] . V_300 = V_30 ;
V_297 [ V_30 ] . V_301 = 0 ;
V_297 [ V_30 ] . V_302 = 0 ;
}
V_34 -> V_184 = 0 ;
}
static int F_156 ( struct V_5 * V_6 )
{
struct V_79 * V_34 = V_6 -> V_34 ;
struct V_118 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_303 * V_86 = & V_34 -> V_86 ;
T_2 V_239 = V_34 -> V_42 ;
T_1 V_177 ;
if ( ( V_86 -> V_304 == V_305 ) ||
( V_86 -> V_304 == V_306 ) ) {
if ( ! F_145 ( V_6 ) ) {
F_147 ( V_6 ) ;
V_6 -> V_178 = 0 ;
F_21 ( V_9 ,
L_34 ,
V_307 , V_239 ) ;
} else {
F_13 ( V_9 ,
L_35 ,
V_307 , V_239 ) ;
V_177 = F_42 ( V_34 , V_180 ) ;
F_21 ( V_9 , L_36 ,
V_177 ) ;
}
}
return 0 ;
}
static int F_157 ( struct V_5 * V_6 )
{
struct V_79 * V_34 = V_6 -> V_34 ;
struct V_118 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_303 * V_86 = & V_34 -> V_86 ;
T_2 V_239 = V_34 -> V_42 ;
T_1 V_177 ;
V_6 -> V_308 ++ ;
if ( V_6 -> V_308 < 3 ) {
V_6 -> V_186 = 1 ;
F_83 ( V_85 , & V_86 -> V_87 ) ;
F_21 ( V_9 ,
L_37 ) ;
return 0 ;
}
if ( V_6 -> V_308 > V_309 ) {
F_83 ( V_182 , & V_86 -> V_87 ) ;
V_6 -> V_310 = 0 ;
V_6 -> V_178 = 0 ;
V_6 -> V_308 = 0 ;
F_152 ( V_6 ) ;
F_13 ( V_9 ,
L_38 ) ;
return - V_31 ;
}
F_21 ( V_9 , L_39 , V_239 ) ;
F_21 ( V_9 , L_40 ,
V_307 , V_6 -> V_308 , V_239 ) ;
F_80 ( V_190 , & V_6 -> V_177 ) ;
V_6 -> V_186 = 1 ;
F_83 ( V_85 , & V_86 -> V_87 ) ;
F_152 ( V_6 ) ;
V_6 -> V_186 = 0 ;
if ( ! F_145 ( V_6 ) ) {
F_147 ( V_6 ) ;
V_6 -> V_310 = 0 ;
V_6 -> V_308 = 0 ;
V_6 -> V_178 = 0 ;
F_21 ( V_9 , L_41 , V_239 ) ;
} else {
F_13 ( V_9 , L_42 ,
V_307 , V_239 ) ;
V_177 = F_42 ( V_34 , V_180 ) ;
F_21 ( V_9 , L_43 , V_307 , V_177 ) ;
}
return 0 ;
}
static int F_158 ( struct V_5 * V_6 )
{
struct V_79 * V_34 = V_6 -> V_34 ;
int V_150 = 0 ;
if ( V_34 -> V_86 . V_304 != V_181 )
V_150 = F_156 ( V_6 ) ;
else if ( V_34 -> V_184 )
V_150 = F_157 ( V_6 ) ;
F_83 ( V_190 , & V_6 -> V_177 ) ;
return V_150 ;
}
static int F_159 ( struct V_5 * V_6 )
{
struct V_303 * V_86 = & V_6 -> V_34 -> V_86 ;
F_13 ( & V_6 -> V_10 -> V_9 , L_44 ) ;
if ( V_86 -> V_304 == V_181 )
F_152 ( V_6 ) ;
F_83 ( V_182 , & V_86 -> V_87 ) ;
F_83 ( V_190 , & V_6 -> V_177 ) ;
return - V_31 ;
}
static int
F_160 ( struct V_5 * V_6 )
{
struct V_303 * V_86 = & V_6 -> V_34 -> V_86 ;
F_21 ( & V_6 -> V_10 -> V_9 , L_45 ) ;
if ( V_86 -> V_304 == V_181 ) {
F_80 ( V_190 , & V_6 -> V_177 ) ;
V_6 -> V_310 = 0 ;
V_6 -> V_308 = 0 ;
F_83 ( V_85 , & V_86 -> V_87 ) ;
F_152 ( V_6 ) ;
}
return 0 ;
}
static int F_161 ( struct V_5 * V_6 )
{
struct V_303 * V_86 = & V_6 -> V_34 -> V_86 ;
T_2 V_239 = V_6 -> V_34 -> V_42 ;
if ( V_86 -> V_304 == V_181 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_46 , V_239 ) ;
F_80 ( V_190 , & V_6 -> V_177 ) ;
V_6 -> V_310 = 0 ;
V_6 -> V_308 = 0 ;
F_83 ( V_85 , & V_86 -> V_87 ) ;
F_152 ( V_6 ) ;
}
return 0 ;
}
static int F_162 ( struct V_5 * V_6 )
{
F_13 ( & V_6 -> V_10 -> V_9 , L_47 , V_307 ) ;
return 0 ;
}
static void V_175 ( struct V_263 * V_264 )
{
struct V_5 * V_6 ;
struct V_303 * V_86 ;
int V_150 = 0 ;
V_6 = F_112 ( V_264 , struct V_5 , V_311 . V_264 ) ;
V_86 = & V_6 -> V_34 -> V_86 ;
V_86 -> V_312 = F_42 ( V_6 -> V_34 , V_180 ) ;
switch ( V_86 -> V_312 ) {
case V_181 :
V_150 = F_158 ( V_6 ) ;
break;
case V_305 :
case V_306 :
V_150 = F_161 ( V_6 ) ;
break;
case V_313 :
V_150 = F_160 ( V_6 ) ;
break;
case V_314 :
V_150 = F_159 ( V_6 ) ;
break;
case V_315 :
break;
default:
V_150 = F_162 ( V_6 ) ;
}
V_86 -> V_304 = V_86 -> V_312 ;
if ( ! V_150 && F_41 ( V_182 , & V_86 -> V_87 ) )
F_74 ( V_6 , V_175 ,
V_86 -> V_176 ) ;
}
static void F_163 ( struct V_5 * V_6 )
{
while ( F_94 ( V_190 , & V_6 -> V_177 ) )
F_78 ( 20 ) ;
F_83 ( V_182 , & V_6 -> V_34 -> V_86 . V_87 ) ;
F_83 ( V_190 , & V_6 -> V_177 ) ;
F_164 ( & V_6 -> V_311 ) ;
}
static int F_165 ( struct V_19 * V_20 ,
T_3 V_316 , T_2 V_273 )
{
T_3 V_281 = V_20 -> V_281 ;
T_2 V_317 = 0 ;
int V_30 ;
if ( V_20 -> V_152 != V_153 )
return - V_205 ;
if ( V_273 ) {
if ( V_281 )
return - V_205 ;
if ( V_20 -> V_148 ) {
for ( V_30 = 0 ; V_30 < V_20 -> V_149 ; V_30 ++ ) {
if ( V_20 -> V_147 [ V_30 ] == V_316 )
V_317 = 1 ;
}
if ( ! V_317 )
return - V_205 ;
}
} else {
if ( ! V_281 || V_281 != V_316 )
return - V_205 ;
}
return 0 ;
}
int F_166 ( struct V_5 * V_6 ,
T_3 V_316 , T_2 V_273 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_60 V_61 ;
int V_150 ;
if ( V_316 == 0 )
return 0 ;
V_150 = F_165 ( V_20 , V_316 , V_273 ) ;
if ( V_150 )
return V_150 ;
V_150 = F_64 ( & V_61 ,
V_318 ) ;
if ( V_150 )
return V_150 ;
V_61 . V_65 . V_66 [ 1 ] = ( V_273 & 1 ) | V_316 << 16 ;
F_33 ( & V_20 -> V_22 ) ;
V_150 = F_58 ( V_6 , & V_61 ) ;
if ( V_150 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_48 , V_150 ) ;
} else {
F_167 ( V_6 ) ;
if ( V_273 )
V_20 -> V_281 = V_316 ;
else
V_20 -> V_281 = 0 ;
F_138 ( V_6 -> V_173 ) ;
}
F_29 ( & V_61 ) ;
return V_150 ;
}
static void F_168 ( struct V_5 * V_6 )
{
struct V_267 * V_284 = & V_6 -> V_319 ;
struct V_282 * V_283 ;
T_3 V_281 ;
V_281 = V_6 -> V_34 -> V_20 -> V_281 ;
while ( ! F_26 ( V_284 ) ) {
V_283 = F_122 ( V_284 -> V_286 , struct V_282 , V_63 ) ;
F_169 ( V_6 , V_283 -> V_287 ,
V_281 , V_320 ) ;
F_28 ( & V_283 -> V_63 ) ;
F_23 ( V_283 ) ;
}
}
int F_170 ( struct V_8 * V_10 )
{
struct V_5 * V_6 = F_171 ( V_10 ) ;
struct V_280 * V_173 = V_6 -> V_173 ;
int V_321 ;
F_154 ( V_173 ) ;
F_172 ( V_6 ) ;
if ( F_148 ( V_173 ) )
F_155 ( V_6 , V_173 ) ;
F_36 ( V_6 , V_70 ) ;
F_37 ( V_6 , 0 ) ;
F_153 ( V_6 ) ;
F_164 ( & V_6 -> V_188 ) ;
V_321 = F_173 ( V_10 ) ;
if ( V_321 )
return V_321 ;
return 0 ;
}
int F_174 ( struct V_5 * V_6 )
{
struct V_303 * V_86 = & V_6 -> V_34 -> V_86 ;
struct V_280 * V_173 = V_6 -> V_173 ;
int V_29 ;
F_80 ( V_182 , & V_86 -> V_87 ) ;
F_146 ( V_6 ) ;
V_29 = F_37 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_6 , V_170 ) ;
if ( ! V_29 ) {
if ( F_148 ( V_173 ) ) {
V_29 = F_149 ( V_6 , V_173 ) ;
if ( ! V_29 )
F_150 ( V_173 , V_295 ) ;
}
}
F_151 ( V_173 ) ;
F_74 ( V_6 , V_175 ,
V_86 -> V_176 ) ;
return V_29 ;
}
