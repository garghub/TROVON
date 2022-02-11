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
if ( F_18 ( V_6 ) ) {
V_26 = F_11 ( sizeof( struct V_25 ) , V_32 ) ;
if ( ! V_26 ) {
V_29 = - V_33 ;
goto V_49;
}
V_20 -> V_35 [ V_30 ] . V_26 = V_26 ;
V_26 -> V_50 = V_51 ;
F_19 ( V_26 -> V_52 ) ;
F_20 ( & V_6 -> V_10 -> V_9 ,
L_5 ,
V_26 -> V_52 , V_30 ) ;
}
}
return 0 ;
V_49:
F_21 ( V_22 -> V_40 ) ;
V_39:
F_21 ( V_22 -> V_38 ) ;
V_37:
F_22 ( V_20 -> V_35 ) ;
V_36:
F_22 ( V_6 -> V_34 -> V_20 ) ;
return V_29 ;
}
void F_23 ( struct V_53 * V_54 )
{
struct V_55 * V_56 ;
struct V_57 V_58 ;
unsigned long V_59 ;
F_24 ( & V_54 -> V_47 , V_59 ) ;
while ( ! F_25 ( & V_54 -> V_45 ) ) {
V_56 = F_26 ( & V_54 -> V_45 ,
struct V_55 , V_60 ) ;
F_27 ( & V_56 -> V_60 ) ;
V_54 -> V_61 -- ;
V_58 . V_62 . V_63 = ( T_1 * ) V_56 -> V_64 ;
V_58 . V_65 . V_63 = ( T_1 * ) V_56 -> V_66 ;
F_28 ( & V_58 ) ;
F_29 ( V_56 ) ;
}
F_30 ( & V_54 -> V_47 , V_59 ) ;
}
void F_31 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_21 * V_22 = & V_20 -> V_22 ;
struct V_27 * V_28 ;
int V_30 ;
if ( ! F_10 ( V_6 ) )
return;
F_32 ( V_22 ) ;
F_21 ( V_22 -> V_40 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_18 ; V_30 ++ ) {
V_28 = & V_20 -> V_35 [ V_30 ] ;
F_23 ( & V_28 -> V_46 ) ;
F_33 ( & V_28 -> V_67 ) ;
F_23 ( & V_28 -> V_44 ) ;
}
F_21 ( V_22 -> V_38 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_18 ; V_30 ++ )
F_22 ( V_20 -> V_35 [ V_30 ] . V_26 ) ;
F_22 ( V_20 -> V_35 ) ;
F_22 ( V_6 -> V_34 -> V_20 ) ;
}
static void F_34 ( struct V_5 * V_6 )
{
F_35 ( V_6 , V_68 ) ;
F_36 ( V_6 , 0 ) ;
F_31 ( V_6 ) ;
}
void F_37 ( struct V_5 * V_6 )
{
if ( F_18 ( V_6 ) )
F_38 ( V_6 ) ;
if ( F_6 ( V_6 ) )
F_34 ( V_6 ) ;
}
static int F_39 ( struct V_5 * V_6 , T_1 * V_69 ,
T_1 * V_70 , T_2 V_42 , T_2 V_71 )
{
T_1 V_65 , V_72 , V_73 , V_74 , V_75 , V_1 , V_76 = 0 ;
struct V_77 * V_34 = V_6 -> V_34 ;
unsigned long V_59 ;
T_3 V_78 ;
T_2 V_79 ;
int V_30 , V_80 ;
V_78 = ( (struct V_81 * ) V_69 ) -> V_82 ;
if ( ! F_40 ( V_83 , & V_6 -> V_34 -> V_84 . V_85 ) ) {
F_20 ( & V_6 -> V_10 -> V_9 ,
L_6 , V_78 ) ;
F_20 ( & V_6 -> V_10 -> V_9 , L_7 ) ;
return 0 ;
}
F_24 ( & V_34 -> V_86 , V_59 ) ;
V_72 = F_41 ( V_34 , V_87 ) ;
if ( V_72 ) {
F_42 ( V_6 , V_88 , L_6 , V_78 ) ;
F_30 ( & V_34 -> V_86 , V_59 ) ;
return V_89 ;
}
V_1 = V_71 + ( sizeof( struct V_81 ) / sizeof( T_1 ) ) ;
V_75 = 0x31 | ( V_1 << 16 ) | ( V_6 -> V_34 -> V_90 << 29 ) ;
F_43 ( V_75 , F_44 ( V_34 , 0 ) ) ;
V_75 = 0x1 | ( 1 << 4 ) ;
if ( F_18 ( V_6 ) )
V_75 |= ( V_42 << 5 ) ;
F_43 ( V_75 , F_44 ( V_34 , 1 ) ) ;
for ( V_30 = 2 , V_80 = 0 ; V_80 < ( sizeof( struct V_81 ) / sizeof( T_1 ) ) ;
V_30 ++ , V_80 ++ ) {
F_43 ( * ( V_69 ++ ) , F_44 ( V_34 , V_30 ) ) ;
}
for ( V_80 = 0 ; V_80 < V_71 ; V_80 ++ , V_30 ++ )
F_43 ( * ( V_70 ++ ) , F_44 ( V_34 , V_30 ) ) ;
F_45 ( V_34 , V_87 , V_91 ) ;
V_92:
V_65 = F_46 ( V_6 , & V_76 ) ;
if ( V_65 != V_89 ) {
V_73 = F_47 ( F_48 ( V_34 , 0 ) ) ;
if ( V_73 & V_93 ) {
F_49 ( V_6 ) ;
goto V_92;
}
V_79 = F_50 ( V_73 ) ;
V_74 = F_51 ( V_73 ) ;
V_78 = F_52 ( V_73 ) ;
switch ( V_79 ) {
case V_94 :
case V_95 :
V_65 = V_96 ;
break;
default:
if ( V_78 == V_97 ) {
V_65 = F_53 ( V_6 ) ;
if ( ! V_65 )
goto V_98;
}
F_13 ( & V_6 -> V_10 -> V_9 ,
L_8 ,
V_78 , V_79 ) ;
V_65 = V_79 ;
break;
}
goto V_98;
}
F_13 ( & V_6 -> V_10 -> V_9 , L_9 ,
F_52 ( V_75 ) ) ;
V_65 = V_89 ;
V_98:
F_45 ( V_34 , V_99 , V_100 ) ;
F_30 ( & V_6 -> V_34 -> V_86 , V_59 ) ;
return V_65 ;
}
static void F_54 ( struct V_5 * V_6 )
{
V_6 -> V_101 = V_102 ;
V_6 -> V_103 = V_104 ;
V_6 -> V_105 = V_106 ;
V_6 -> V_107 = V_108 ;
V_6 -> V_109 = V_110 ;
V_6 -> V_111 = V_112 ;
}
int F_55 ( struct V_5 * V_6 ,
struct V_113 * V_114 , T_3 V_115 )
{
struct V_116 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_57 V_58 ;
int V_29 ;
T_1 V_85 ;
V_29 = F_56 ( & V_58 , V_6 , V_117 ) ;
if ( V_29 )
return V_29 ;
V_58 . V_62 . V_63 [ 1 ] = V_115 << 16 | 0x1 ;
V_29 = F_57 ( V_6 , & V_58 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_10 , V_29 ) ;
F_28 ( & V_58 ) ;
return V_29 ;
}
V_85 = V_58 . V_65 . V_63 [ 2 ] & 0xffff ;
if ( V_85 & V_118 )
V_114 -> V_119 = F_58 ( V_58 . V_65 . V_63 [ 2 ] ) ;
if ( V_85 & V_120 )
V_114 -> V_50 = F_59 ( V_58 . V_65 . V_63 [ 3 ] ) ;
if ( V_85 & V_121 )
V_114 -> V_122 = F_58 ( V_58 . V_65 . V_63 [ 3 ] ) ;
if ( V_85 & V_123 )
V_114 -> V_124 = F_59 ( V_58 . V_65 . V_63 [ 4 ] ) ;
if ( V_85 & V_125 )
V_114 -> V_126 = F_58 ( V_58 . V_65 . V_63 [ 4 ] ) ;
if ( V_85 & V_127 )
V_114 -> V_128 = F_59 ( V_58 . V_65 . V_63 [ 5 ] ) ;
if ( V_85 & V_129 )
V_114 -> V_130 = F_58 ( V_58 . V_65 . V_63 [ 5 ] ) ;
if ( V_85 & V_131 )
V_114 -> V_132 = F_59 ( V_58 . V_65 . V_63 [ 6 ] ) ;
if ( V_85 & V_133 )
V_114 -> V_134 = F_58 ( V_58 . V_65 . V_63 [ 6 ] ) ;
if ( V_85 & V_135 )
V_114 -> V_136 = F_59 ( V_58 . V_65 . V_63 [ 7 ] ) ;
V_114 -> V_137 = F_58 ( V_58 . V_65 . V_63 [ 7 ] ) ;
V_114 -> V_138 = F_59 ( V_58 . V_65 . V_63 [ 8 ] ) ;
V_114 -> V_139 = F_58 ( V_58 . V_65 . V_63 [ 8 ] ) ;
V_114 -> V_140 = F_59 ( V_58 . V_65 . V_63 [ 9 ] ) ;
F_20 ( V_9 , L_11
L_12
L_13
L_14
L_15
L_16 ,
V_114 -> V_119 , V_114 -> V_50 ,
V_114 -> V_122 , V_114 -> V_124 ,
V_114 -> V_126 ,
V_114 -> V_128 , V_114 -> V_130 ,
V_114 -> V_132 , V_114 -> V_134 ,
V_114 -> V_136 , V_114 -> V_137 ,
V_114 -> V_138 , V_114 -> V_139 ,
V_114 -> V_140 ) ;
F_28 ( & V_58 ) ;
return V_29 ;
}
static int F_60 ( struct V_5 * V_6 ,
struct V_57 * V_58 )
{
V_6 -> V_141 = ( V_58 -> V_65 . V_63 [ 1 ] >> 16 ) & 0xffff ;
V_6 -> V_59 &= ~ V_142 ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 ,
struct V_57 * V_58 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
int V_30 , V_143 ;
T_3 * V_144 ;
if ( V_20 -> V_145 )
return 0 ;
V_20 -> V_146 = V_58 -> V_65 . V_63 [ 2 ] & 0xf ;
if ( ! V_20 -> V_146 )
return 0 ;
V_20 -> V_147 = V_58 -> V_65 . V_63 [ 2 ] >> 16 ;
V_143 = V_20 -> V_147 ;
V_20 -> V_145 = F_11 ( sizeof( T_3 ) * V_143 , V_32 ) ;
if ( ! V_20 -> V_145 )
return - V_33 ;
V_144 = ( T_3 * ) & V_58 -> V_65 . V_63 [ 3 ] ;
for ( V_30 = 0 ; V_30 < V_143 ; V_30 ++ )
V_20 -> V_145 [ V_30 ] = V_144 [ V_30 ] ;
return 0 ;
}
static int F_62 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_57 V_58 ;
int V_148 ;
V_148 = F_63 ( & V_58 , V_149 ) ;
if ( V_148 )
return V_148 ;
V_148 = F_57 ( V_6 , & V_58 ) ;
if ( V_148 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_17 ,
V_148 ) ;
} else {
V_20 -> V_150 = V_58 . V_65 . V_63 [ 1 ] & 0x3 ;
switch ( V_20 -> V_150 ) {
case V_151 :
V_148 = F_61 ( V_6 , & V_58 ) ;
break;
case V_152 :
V_148 = F_60 ( V_6 , & V_58 ) ;
break;
}
}
F_28 ( & V_58 ) ;
return V_148 ;
}
static int F_64 ( struct V_5 * V_6 )
{
struct V_113 V_153 ;
struct V_77 * V_34 = V_6 -> V_34 ;
int V_29 ;
V_29 = F_55 ( V_6 , & V_153 , 0 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_65 ( V_6 , & V_153 , V_34 -> V_42 ) ;
if ( V_29 )
return - V_31 ;
V_29 = F_62 ( V_6 ) ;
if ( V_29 )
return V_29 ;
if ( F_66 ( V_6 ) )
return - V_31 ;
F_54 ( V_6 ) ;
V_6 -> V_59 |= V_154 ;
F_20 ( & V_6 -> V_10 -> V_9 , L_18 ,
V_6 -> V_34 -> V_90 ) ;
V_34 -> V_155 = ( T_2 ) V_153 . V_156 ;
V_34 -> V_157 = V_153 . V_157 ;
V_34 -> V_158 = V_153 . V_158 ;
V_34 -> V_159 = V_153 . V_159 ;
V_34 -> V_160 = V_153 . V_160 ;
return 0 ;
}
static int F_67 ( struct V_5 * V_6 ,
int V_161 )
{
int V_29 ;
F_14 ( & V_6 -> V_162 ) ;
if ( ! V_163 && ! ! V_164 )
F_68 ( & V_6 -> V_10 -> V_9 ,
L_19 ) ;
V_29 = F_69 ( V_6 , 1 ) ;
if ( V_29 ) {
F_13 ( & V_6 -> V_10 -> V_9 , L_20 ) ;
goto V_165;
}
V_29 = F_70 ( V_6 ) ;
if ( V_29 )
goto V_165;
V_29 = F_9 ( V_6 , 1 ) ;
if ( V_29 )
goto V_166;
V_29 = F_36 ( V_6 , 1 ) ;
if ( V_29 )
goto V_167;
V_29 = F_35 ( V_6 , V_168 ) ;
if ( V_29 )
goto V_169;
V_29 = F_64 ( V_6 ) ;
if ( V_29 )
goto V_170;
V_29 = F_71 ( V_6 , V_6 -> V_171 , V_161 ) ;
if ( V_29 )
goto V_170;
F_72 ( V_6 -> V_10 , V_6 ) ;
F_20 ( & V_6 -> V_10 -> V_9 , L_21 ,
V_6 -> V_171 -> V_172 ) ;
F_73 ( V_6 , V_173 ,
V_6 -> V_34 -> V_84 . V_174 ) ;
return 0 ;
V_170:
F_35 ( V_6 , V_68 ) ;
V_169:
F_36 ( V_6 , 0 ) ;
V_167:
F_31 ( V_6 ) ;
V_166:
F_74 ( V_6 ) ;
V_165:
F_75 ( V_6 ) ;
return V_29 ;
}
static int F_76 ( struct V_5 * V_6 )
{
T_1 V_175 ;
do {
F_77 ( 20 ) ;
if ( ++ V_6 -> V_176 > V_177 )
return - V_31 ;
V_175 = F_41 ( V_6 -> V_34 , V_178 ) ;
} while ( V_175 != V_179 );
return 0 ;
}
int F_78 ( struct V_5 * V_6 , int V_161 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
int V_29 ;
F_16 ( & V_34 -> V_86 ) ;
F_79 ( V_83 , & V_34 -> V_84 . V_85 ) ;
F_79 ( V_180 , & V_34 -> V_84 . V_85 ) ;
V_34 -> V_84 . V_174 = V_181 ;
V_34 -> V_182 = 0 ;
V_6 -> V_176 = 0 ;
V_34 -> V_183 = 1 ;
V_6 -> V_184 = 0 ;
V_6 -> V_59 |= V_185 ;
V_29 = F_76 ( V_6 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_67 ( V_6 , V_161 ) ;
if ( V_29 )
return V_29 ;
if ( F_80 ( V_6 ) )
F_68 ( & V_6 -> V_10 -> V_9 , L_22 ) ;
F_81 ( V_186 , & V_6 -> V_175 ) ;
return 0 ;
}
void F_82 ( struct V_5 * V_6 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
V_34 -> V_159 = V_187 ;
F_20 ( & V_6 -> V_10 -> V_9 ,
L_23 ,
V_34 -> V_90 ) ;
V_6 -> V_188 = & V_189 ;
F_79 ( V_190 , & V_6 -> V_175 ) ;
return;
}
void F_83 ( struct V_77 * V_34 )
{
V_34 -> V_191 = & V_192 ;
V_34 -> V_193 = ( T_1 * ) V_194 ;
V_34 -> V_195 = ( T_1 * ) V_196 ;
}
static T_1 F_84 ( T_1 V_197 , T_2 V_198 )
{
T_1 V_199 ;
V_199 = V_197 / ( ( V_198 + 1 ) * V_200 ) ;
if ( V_199 )
V_199 = V_200 ;
else
V_199 = V_197 % V_200 ;
return V_199 ;
}
int F_85 ( struct V_5 * V_6 , T_2 V_42 )
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
static inline int F_86 ( struct V_55 * * V_56 )
{
* V_56 = F_11 ( sizeof( struct V_55 ) , V_202 ) ;
if ( ! * V_56 )
return - V_33 ;
F_17 ( & ( * V_56 ) -> V_203 ) ;
return 0 ;
}
static inline int F_87 ( struct V_81 * * V_69 ,
T_1 V_71 )
{
* V_69 = F_11 ( sizeof( struct V_81 ) * V_71 , V_202 ) ;
if ( ! * V_69 )
return - V_33 ;
return 0 ;
}
static int F_63 ( struct V_57 * V_204 , T_1 type )
{
const struct V_205 * V_206 ;
int V_30 , V_71 ;
V_206 = V_207 ;
V_71 = F_88 ( V_207 ) ;
for ( V_30 = 0 ; V_30 < V_71 ; V_30 ++ ) {
if ( type == V_206 [ V_30 ] . V_58 ) {
V_204 -> V_208 = V_209 ;
V_204 -> V_62 . V_210 = V_206 [ V_30 ] . V_211 ;
V_204 -> V_65 . V_210 = V_206 [ V_30 ] . V_212 ;
V_204 -> V_62 . V_63 = F_89 ( V_204 -> V_62 . V_210 , sizeof( T_1 ) ,
V_202 ) ;
if ( ! V_204 -> V_62 . V_63 )
return - V_33 ;
V_204 -> V_65 . V_63 = F_89 ( V_204 -> V_65 . V_210 , sizeof( T_1 ) ,
V_202 ) ;
if ( ! V_204 -> V_65 . V_63 ) {
F_22 ( V_204 -> V_62 . V_63 ) ;
V_204 -> V_62 . V_63 = NULL ;
return - V_33 ;
}
memset ( V_204 -> V_62 . V_63 , 0 , sizeof( T_1 ) * V_204 -> V_62 . V_210 ) ;
memset ( V_204 -> V_65 . V_63 , 0 , sizeof( T_1 ) * V_204 -> V_65 . V_210 ) ;
V_204 -> V_62 . V_63 [ 0 ] = ( type | ( V_204 -> V_62 . V_210 << 16 ) |
( 3 << 29 ) ) ;
return 0 ;
}
}
return - V_201 ;
}
static int F_90 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
T_3 V_213 , T_2 V_214 )
{
struct V_81 * V_69 ;
int V_30 ;
T_1 V_215 , V_216 ;
T_3 V_217 ;
T_2 V_82 , V_218 , V_219 ;
V_216 = V_200 ;
if ( V_214 == V_220 ) {
V_56 -> V_64 = (struct V_221 * ) V_58 -> V_62 . V_63 ;
V_56 -> V_66 = (struct V_221 * ) V_58 -> V_65 . V_63 ;
V_215 = V_58 -> V_62 . V_210 ;
V_56 -> V_222 = ( V_215 * 4 ) ;
V_215 = V_58 -> V_65 . V_210 ;
V_56 -> V_223 = ( V_215 * 4 ) ;
V_82 = V_58 -> V_62 . V_63 [ 0 ] & 0xff ;
V_217 = ( V_56 -> V_222 ) % ( V_216 ) ;
V_218 = ( V_56 -> V_222 ) / ( V_216 ) ;
if ( V_217 )
V_218 ++ ;
V_219 = V_218 ;
if ( F_87 ( & V_56 -> V_224 , V_218 ) )
return - V_33 ;
V_217 = ( V_56 -> V_223 ) % ( V_216 ) ;
V_218 = ( V_56 -> V_223 ) / ( V_216 ) ;
if ( V_217 )
V_218 ++ ;
if ( F_87 ( & V_56 -> V_225 , V_218 ) )
return - V_33 ;
V_218 = V_219 ;
V_69 = V_56 -> V_224 ;
} else {
V_58 -> V_62 . V_63 = ( T_1 * ) V_56 -> V_64 ;
V_58 -> V_65 . V_63 = ( T_1 * ) V_56 -> V_66 ;
V_82 = V_58 -> V_62 . V_63 [ 0 ] & 0xff ;
V_217 = ( V_56 -> V_223 ) % ( V_216 ) ;
V_218 = ( V_56 -> V_223 ) / ( V_216 ) ;
if ( V_217 )
V_218 ++ ;
V_58 -> V_62 . V_210 = V_56 -> V_222 / 4 ;
V_58 -> V_65 . V_210 = V_56 -> V_223 / 4 ;
V_69 = V_56 -> V_225 ;
}
V_56 -> V_226 = V_213 ;
V_56 -> V_227 = V_82 ;
for ( V_30 = 0 ; V_30 < V_218 ; V_30 ++ ) {
V_69 [ V_30 ] . V_228 = 2 ;
V_69 [ V_30 ] . V_214 = V_214 ;
V_69 [ V_30 ] . V_208 = V_58 -> V_208 ;
V_69 [ V_30 ] . V_229 = 1 ;
V_69 [ V_30 ] . V_218 = V_218 ;
V_69 [ V_30 ] . V_230 = V_30 + 1 ;
V_69 [ V_30 ] . V_82 = V_82 ;
V_69 [ V_30 ] . V_231 = V_213 ;
}
return 0 ;
}
static void F_29 ( struct V_55 * V_56 )
{
if ( ! V_56 )
return;
F_22 ( V_56 -> V_224 ) ;
F_22 ( V_56 -> V_225 ) ;
F_22 ( V_56 ) ;
}
static int F_91 ( struct V_27 * V_28 ,
struct V_55 * V_56 , T_2 type )
{
struct V_53 * V_54 ;
unsigned long V_59 ;
int V_148 = 0 ;
if ( type == V_232 ) {
V_54 = & V_28 -> V_44 ;
F_24 ( & V_54 -> V_47 , V_59 ) ;
V_54 -> V_61 -- ;
F_27 ( & V_56 -> V_60 ) ;
if ( V_54 -> V_61 > 0 )
V_148 = 1 ;
F_30 ( & V_54 -> V_47 , V_59 ) ;
}
if ( type == V_220 ) {
while ( F_92 ( V_233 , & V_28 -> V_175 ) )
F_77 ( 100 ) ;
V_28 -> V_234 = NULL ;
F_81 ( V_233 , & V_28 -> V_175 ) ;
}
return V_148 ;
}
static void F_93 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
T_4 V_235 )
{
if ( F_40 ( V_236 , & V_28 -> V_175 ) ||
V_28 -> V_6 -> V_184 )
return;
F_94 ( & V_28 -> V_67 , V_235 ) ;
F_95 ( V_20 -> V_22 . V_38 , & V_28 -> V_67 ) ;
}
static inline void F_96 ( struct V_55 * V_56 )
{
struct V_237 * V_238 = & V_56 -> V_203 ;
if ( F_97 ( V_238 , V_239 ) )
V_56 -> V_240 = V_241 ;
else
V_56 -> V_240 = V_242 ;
return;
}
static void F_98 ( struct V_55 * V_56 ,
T_2 type )
{
if ( type == V_232 ) {
V_56 -> V_243 ++ ;
if ( V_56 -> V_243 < V_56 -> V_225 -> V_218 )
V_56 -> V_240 = V_244 ;
else
V_56 -> V_240 = V_241 ;
} else {
V_56 -> V_245 ++ ;
if ( V_56 -> V_245 < V_56 -> V_224 -> V_218 )
V_56 -> V_240 = V_244 ;
else
V_56 -> V_240 = V_246 ;
}
}
static void F_99 ( struct V_55 * V_56 ,
T_2 type )
{
struct V_27 * V_28 = V_56 -> V_28 ;
struct V_237 * V_238 = & V_28 -> V_48 ;
if ( ! F_97 ( V_238 , V_247 ) ) {
V_56 -> V_240 = V_242 ;
return;
}
F_81 ( V_248 , & V_28 -> V_175 ) ;
F_98 ( V_56 , type ) ;
}
static void F_100 ( struct V_5 * V_6 ,
T_1 * V_69 , T_1 * V_70 , T_1 V_71 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
T_1 V_249 ;
T_2 V_30 , V_250 = 2 , V_251 , V_80 ;
V_251 = ( sizeof( struct V_81 ) / sizeof( T_1 ) ) ;
V_250 = ( V_71 / sizeof( T_1 ) ) + V_251 ;
V_249 = F_47 ( F_48 ( V_34 , 0 ) ) ;
for ( V_30 = 2 , V_80 = 0 ; V_80 < V_251 ; V_30 ++ , V_80 ++ )
* ( V_69 ++ ) = F_47 ( F_48 ( V_34 , V_30 ) ) ;
for (; V_80 < V_250 ; V_30 ++ , V_80 ++ )
* ( V_70 ++ ) = F_47 ( F_48 ( V_34 , V_30 ) ) ;
}
static int F_101 ( struct V_27 * V_28 )
{
int V_148 = - V_252 ;
T_1 V_253 = 10000 ;
do {
if ( ! F_92 ( V_248 , & V_28 -> V_175 ) ) {
V_148 = 0 ;
break;
}
F_102 ( 1 ) ;
} while ( -- V_253 );
return V_148 ;
}
static int F_103 ( struct V_55 * V_56 , T_2 type )
{
struct V_27 * V_28 = V_56 -> V_28 ;
T_1 V_199 , V_251 ;
T_1 * V_69 , * V_70 ;
int V_148 ;
T_2 V_42 = V_56 -> V_254 ;
if ( F_101 ( V_28 ) )
return - V_252 ;
if ( type == V_220 ) {
V_69 = ( T_1 * ) ( V_56 -> V_224 + V_56 -> V_245 ) ;
V_70 = ( T_1 * ) ( V_56 -> V_64 + V_56 -> V_245 ) ;
V_251 = ( sizeof( struct V_81 ) / sizeof( T_1 ) ) ;
V_199 = F_84 ( V_56 -> V_222 ,
V_56 -> V_245 ) ;
V_199 = ( V_199 / sizeof( T_1 ) ) ;
} else {
V_69 = ( T_1 * ) ( V_56 -> V_225 + V_56 -> V_243 ) ;
V_70 = ( T_1 * ) ( V_56 -> V_66 + V_56 -> V_243 ) ;
V_251 = ( sizeof( struct V_81 ) / sizeof( T_1 ) ) ;
V_199 = F_84 ( V_56 -> V_223 ,
V_56 -> V_243 ) ;
V_199 = ( V_199 / sizeof( T_1 ) ) ;
}
V_148 = F_39 ( V_28 -> V_6 , V_69 , V_70 ,
V_42 , V_199 ) ;
return V_148 ;
}
static int F_104 ( struct V_55 * V_56 ,
struct V_27 * V_28 , T_2 type )
{
bool V_255 = true ;
int V_29 = - V_31 ;
while ( V_255 ) {
if ( F_40 ( V_236 , & V_28 -> V_175 ) ||
V_28 -> V_6 -> V_184 )
V_56 -> V_240 = V_242 ;
switch ( V_56 -> V_240 ) {
case V_244 :
V_56 -> V_240 = V_256 ;
if ( F_103 ( V_56 , type ) )
V_56 -> V_240 = V_242 ;
break;
case V_256 :
F_99 ( V_56 , type ) ;
break;
case V_246 :
F_96 ( V_56 ) ;
break;
case V_241 :
V_29 = 0 ;
V_255 = false ;
break;
case V_242 :
V_29 = - V_31 ;
V_255 = false ;
F_81 ( V_248 , & V_28 -> V_175 ) ;
break;
default:
V_29 = - V_31 ;
V_255 = false ;
}
}
return V_29 ;
}
static int F_105 ( struct V_5 * V_6 ,
struct V_55 * V_56 , int V_42 )
{
struct V_27 * V_28 ;
int V_29 , V_257 = F_85 ( V_6 , V_42 ) ;
if ( V_257 < 0 )
return - V_31 ;
V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ V_257 ] ;
V_56 -> V_28 = V_28 ;
V_56 -> V_254 = V_42 ;
if ( ! F_40 ( V_258 , & V_28 -> V_175 ) ) {
if ( F_18 ( V_6 ) )
return - V_31 ;
if ( F_6 ( V_6 ) &&
V_56 -> V_227 != V_168 )
return - V_31 ;
}
F_106 ( & V_28 -> V_43 ) ;
V_28 -> V_234 = V_56 ;
V_29 = F_104 ( V_56 , V_28 , V_220 ) ;
F_91 ( V_28 , V_56 , V_220 ) ;
F_107 ( & V_28 -> V_43 ) ;
return V_29 ;
}
static void F_108 ( struct V_5 * V_6 ,
struct V_55 * V_56 ,
struct V_57 * V_58 )
{
#ifdef F_109
if ( F_18 ( V_6 ) ) {
F_110 ( V_6 , V_56 , V_58 ) ;
return;
}
#endif
V_58 -> V_65 . V_63 [ 0 ] |= ( 0x9 << 25 ) ;
return;
}
static void F_111 ( struct V_259 * V_260 )
{
struct V_27 * V_28 = F_112 ( V_260 , struct V_27 ,
V_67 ) ;
struct V_55 * V_56 = NULL ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_57 V_58 ;
T_2 V_62 ;
if ( V_6 -> V_184 )
return;
if ( F_40 ( V_236 , & V_28 -> V_175 ) )
return;
V_56 = F_26 ( & V_28 -> V_44 . V_45 ,
struct V_55 , V_60 ) ;
V_6 = V_28 -> V_6 ;
if ( F_90 ( V_56 , & V_58 , V_56 -> V_224 -> V_231 ,
V_232 ) )
goto V_261;
F_108 ( V_6 , V_56 , & V_58 ) ;
V_56 -> V_240 = V_244 ;
F_104 ( V_56 , V_28 , V_232 ) ;
V_261:
F_28 ( & V_58 ) ;
V_62 = F_91 ( V_28 , V_56 , V_232 ) ;
F_29 ( V_56 ) ;
if ( V_62 )
F_93 ( V_6 -> V_34 -> V_20 , V_28 ,
F_111 ) ;
}
static void F_113 ( struct V_81 * V_69 ,
struct V_27 * V_28 )
{
struct V_55 * V_56 ;
T_1 V_199 ;
if ( F_92 ( V_233 , & V_28 -> V_175 ) )
return;
V_56 = V_28 -> V_234 ;
if ( V_56 == NULL )
goto V_262;
if ( V_56 -> V_226 != V_69 -> V_231 )
goto V_262;
V_199 = F_84 ( V_56 -> V_223 ,
V_56 -> V_243 ) ;
F_100 ( V_28 -> V_6 ,
( T_1 * ) ( V_56 -> V_225 + V_56 -> V_243 ) ,
( T_1 * ) ( V_56 -> V_66 + V_56 -> V_243 ) ,
V_199 ) ;
if ( ++ V_56 -> V_243 < V_56 -> V_225 -> V_218 )
goto V_262;
F_114 ( & V_56 -> V_203 ) ;
V_262:
F_81 ( V_233 , & V_28 -> V_175 ) ;
}
int F_115 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_55 * V_56 )
{
struct V_53 * V_54 = & V_28 -> V_44 ;
V_54 -> V_61 ++ ;
F_116 ( & V_56 -> V_60 , & V_54 -> V_45 ) ;
if ( V_54 -> V_61 == 1 )
F_93 ( V_20 , V_28 ,
F_111 ) ;
return 0 ;
}
static int F_117 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_55 * V_56 )
{
struct V_53 * V_54 = & V_28 -> V_44 ;
F_118 ( & V_54 -> V_47 ) ;
F_115 ( V_20 , V_28 , V_56 ) ;
F_119 ( & V_54 -> V_47 ) ;
return 0 ;
}
static void F_120 ( struct V_19 * V_20 ,
struct V_27 * V_28 ,
struct V_81 * V_69 )
{
struct V_55 * V_56 = NULL ;
struct V_263 * V_264 ;
T_1 V_199 , V_198 ;
T_2 V_265 = 0 , V_266 = 0 ;
F_118 ( & V_28 -> V_46 . V_47 ) ;
if ( V_28 -> V_46 . V_61 > 0 ) {
F_121 (node, &vf->rcv_pend.wait_list) {
V_56 = F_122 ( V_264 , struct V_55 , V_60 ) ;
if ( V_56 -> V_226 == V_69 -> V_231 ) {
V_265 = 1 ;
break;
}
}
}
if ( V_265 ) {
V_198 = V_56 -> V_245 ;
V_199 = F_84 ( V_56 -> V_222 ,
V_198 ) ;
F_100 ( V_28 -> V_6 ,
( T_1 * ) ( V_56 -> V_224 + V_198 ) ,
( T_1 * ) ( V_56 -> V_64 + V_198 ) ,
V_199 ) ;
V_56 -> V_245 ++ ;
if ( V_56 -> V_245 >= V_69 -> V_218 ) {
V_28 -> V_46 . V_61 -- ;
F_27 ( & V_56 -> V_60 ) ;
V_266 = 1 ;
}
}
F_119 ( & V_28 -> V_46 . V_47 ) ;
if ( V_266 )
if ( F_117 ( V_20 , V_28 , V_56 ) )
F_29 ( V_56 ) ;
return;
}
static void F_123 ( struct V_19 * V_20 ,
struct V_81 * V_69 ,
struct V_27 * V_28 )
{
struct V_55 * V_56 ;
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_57 V_58 ;
T_1 V_199 ;
int V_29 ;
T_2 V_82 ;
if ( V_6 -> V_184 )
return;
if ( ! F_40 ( V_258 , & V_28 -> V_175 ) &&
V_69 -> V_208 != V_209 &&
V_69 -> V_82 != V_168 )
return;
if ( V_69 -> V_230 > 1 ) {
F_120 ( V_20 , V_28 , V_69 ) ;
return;
}
V_82 = V_69 -> V_82 ;
if ( F_86 ( & V_56 ) )
return;
if ( V_69 -> V_208 == V_209 )
V_29 = F_63 ( & V_58 , V_82 ) ;
else
V_29 = F_56 ( & V_58 , V_6 , V_82 ) ;
if ( V_29 ) {
F_29 ( V_56 ) ;
return;
}
V_58 . V_208 = V_69 -> V_208 ;
if ( F_90 ( V_56 , & V_58 , V_69 -> V_231 ,
V_220 ) ) {
F_28 ( & V_58 ) ;
F_29 ( V_56 ) ;
return;
}
V_199 = F_84 ( V_56 -> V_222 ,
V_56 -> V_245 ) ;
F_100 ( V_28 -> V_6 ,
( T_1 * ) ( V_56 -> V_224 + V_56 -> V_245 ) ,
( T_1 * ) ( V_56 -> V_64 + V_56 -> V_245 ) ,
V_199 ) ;
V_56 -> V_254 = V_28 -> V_42 ;
V_56 -> V_28 = V_28 ;
V_56 -> V_226 = V_69 -> V_231 ;
V_56 -> V_245 ++ ;
if ( F_124 ( V_6 , V_56 , V_28 ) )
return;
if ( V_56 -> V_245 == V_56 -> V_224 -> V_218 ) {
if ( F_117 ( V_20 , V_28 , V_56 ) ) {
F_28 ( & V_58 ) ;
F_29 ( V_56 ) ;
}
} else {
F_118 ( & V_28 -> V_46 . V_47 ) ;
F_116 ( & V_56 -> V_60 , & V_28 -> V_46 . V_45 ) ;
V_28 -> V_46 . V_61 ++ ;
F_119 ( & V_28 -> V_46 . V_47 ) ;
}
}
static void F_125 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
struct V_81 V_69 ;
T_1 * V_267 = ( T_1 * ) & V_69 ;
T_2 V_214 , V_30 ;
for ( V_30 = 2 ; V_30 < 6 ; V_30 ++ )
V_267 [ V_30 - 2 ] = F_47 ( F_48 ( V_28 -> V_6 -> V_34 , V_30 ) ) ;
V_214 = V_69 . V_214 ;
switch ( V_214 ) {
case V_220 :
F_123 ( V_20 , & V_69 , V_28 ) ;
break;
case V_232 :
F_113 ( & V_69 , V_28 ) ;
break;
}
}
static void F_126 ( struct V_19 * V_20 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_28 -> V_6 ;
if ( F_18 ( V_6 ) )
F_127 ( V_20 , V_28 ) ;
else
F_13 ( & V_6 -> V_10 -> V_9 ,
L_24 ) ;
}
void F_128 ( struct V_5 * V_6 , T_1 V_268 )
{
struct V_27 * V_28 ;
struct V_19 * V_20 ;
int V_257 ;
T_2 V_42 ;
V_20 = V_6 -> V_34 -> V_20 ;
V_42 = F_4 ( V_268 ) ;
V_257 = F_85 ( V_6 , V_42 ) ;
if ( V_257 < 0 )
return;
V_28 = & V_20 -> V_35 [ V_257 ] ;
V_28 -> V_42 = V_42 ;
if ( F_2 ( V_268 ) )
F_114 ( & V_28 -> V_48 ) ;
if ( F_3 ( V_268 ) ) {
F_126 ( V_20 , V_28 ) ;
return;
}
if ( F_1 ( V_268 ) )
F_125 ( V_20 , V_28 ) ;
}
int F_36 ( struct V_5 * V_6 , T_2 V_269 )
{
struct V_57 V_58 ;
int V_29 ;
if ( ! F_40 ( V_190 , & V_6 -> V_175 ) )
return 0 ;
if ( F_56 ( & V_58 , V_6 , V_270 ) )
return - V_33 ;
if ( V_269 )
V_58 . V_62 . V_63 [ 1 ] = ( 1 << 4 ) | ( 1 << 5 ) | ( 1 << 6 ) | ( 1 << 7 ) ;
V_29 = F_129 ( V_6 , & V_58 ) ;
if ( V_29 != V_96 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_25 ,
( V_269 ? L_26 : L_27 ) , V_29 ) ;
}
F_28 ( & V_58 ) ;
return V_29 ;
}
static int F_130 ( struct V_5 * V_6 ,
struct V_55 * V_56 )
{
T_2 V_250 = V_177 ;
T_1 V_175 ;
V_175 = F_41 ( V_6 -> V_34 , V_178 ) ;
if ( V_175 == V_179 ) {
F_77 ( 20 ) ;
F_81 ( V_248 , & V_56 -> V_28 -> V_175 ) ;
V_56 -> V_240 = V_244 ;
if ( ++ V_6 -> V_176 > V_250 )
return - V_31 ;
else
return 0 ;
}
return - V_31 ;
}
static int F_131 ( struct V_5 * V_6 ,
struct V_57 * V_58 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
struct V_116 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_55 * V_56 ;
int V_29 ;
T_1 V_271 , V_78 , V_79 , V_65 ;
T_3 V_213 = ++ V_6 -> V_34 -> V_20 -> V_22 . V_272 ;
T_2 V_235 = V_34 -> V_42 ;
V_65 = F_86 ( & V_56 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_90 ( V_56 , V_58 , V_213 , V_220 ) ;
if ( V_65 )
goto V_273;
V_274:
if ( ! F_40 ( V_83 , & V_6 -> V_34 -> V_84 . V_85 ) ) {
V_65 = - V_31 ;
F_42 ( V_6 , V_88 , L_28 ,
F_52 ( V_58 -> V_62 . V_63 [ 0 ] ) , V_235 ) ;
goto V_275;
}
V_29 = F_105 ( V_6 , V_56 , V_235 ) ;
if ( V_29 ) {
F_13 ( V_9 , L_29 ,
( V_58 -> V_62 . V_63 [ 0 ] & 0xffff ) , V_235 ) ;
V_65 = V_89 ;
if ( ( V_56 -> V_224 -> V_82 == V_168 ) &&
! F_130 ( V_6 , V_56 ) )
goto V_274;
goto V_275;
}
V_271 = V_58 -> V_65 . V_63 [ 0 ] ;
V_79 = F_50 ( V_271 ) ;
V_78 = F_52 ( V_58 -> V_62 . V_63 [ 0 ] ) ;
if ( ( V_79 == V_94 ) ||
( V_79 == V_95 ) ) {
V_65 = V_96 ;
} else {
V_65 = V_79 ;
if ( ! V_65 )
V_65 = 1 ;
F_13 ( V_9 ,
L_30 ,
V_78 , V_79 , V_235 ) ;
}
V_275:
if ( V_65 == V_89 ) {
V_34 -> V_182 = 1 ;
V_6 -> V_184 = 1 ;
F_81 ( V_83 , & V_34 -> V_84 . V_85 ) ;
}
V_273:
F_29 ( V_56 ) ;
return V_65 ;
}
int F_35 ( struct V_5 * V_6 , T_2 V_82 )
{
struct V_57 V_58 ;
struct V_27 * V_28 = & V_6 -> V_34 -> V_20 -> V_35 [ 0 ] ;
int V_148 ;
if ( F_63 ( & V_58 , V_82 ) )
return - V_33 ;
V_148 = F_57 ( V_6 , & V_58 ) ;
if ( V_148 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_31 , V_82 ? L_32 : L_33 ,
V_148 ) ;
goto V_98;
}
V_82 = ( V_58 . V_65 . V_63 [ 0 ] & 0xff ) ;
if ( V_58 . V_65 . V_63 [ 0 ] >> 25 == 2 )
return 2 ;
if ( V_82 == V_168 )
F_79 ( V_258 , & V_28 -> V_175 ) ;
else
F_81 ( V_258 , & V_28 -> V_175 ) ;
V_98:
F_28 ( & V_58 ) ;
return V_148 ;
}
void F_132 ( struct V_276 * V_171 , T_3 V_277 )
{
struct V_5 * V_6 = F_133 ( V_171 ) ;
struct V_278 * V_279 ;
struct V_263 * V_280 , V_281 ;
F_14 ( & V_281 ) ;
V_280 = & V_6 -> V_162 ;
F_134 ( V_171 ) ;
while ( ! F_25 ( V_280 ) ) {
V_279 = F_122 ( V_280 -> V_282 , struct V_278 , V_60 ) ;
F_135 ( & V_279 -> V_60 , & V_281 ) ;
}
F_136 ( V_171 ) ;
while ( ! F_25 ( & V_281 ) ) {
V_279 = F_122 ( ( & V_281 ) -> V_282 ,
struct V_278 , V_60 ) ;
F_137 ( V_6 , V_279 -> V_283 , V_277 ) ;
F_27 ( & V_279 -> V_60 ) ;
F_22 ( V_279 ) ;
}
}
void F_32 ( struct V_21 * V_22 )
{
struct V_263 * V_280 = & V_22 -> V_41 ;
struct V_284 * V_285 ;
while ( ! F_25 ( V_280 ) ) {
V_285 = F_122 ( V_280 -> V_282 , struct V_284 ,
V_60 ) ;
F_33 ( & V_285 -> V_260 ) ;
F_27 ( & V_285 -> V_60 ) ;
F_22 ( V_285 ) ;
}
}
static void F_138 ( struct V_276 * V_171 )
{
struct V_5 * V_6 = F_133 ( V_171 ) ;
T_3 V_277 ;
if ( ! F_40 ( V_286 , & V_6 -> V_175 ) )
return;
V_277 = V_6 -> V_34 -> V_20 -> V_277 ;
F_139 ( V_171 , V_277 ) ;
}
static void F_140 ( struct V_259 * V_260 )
{
struct V_284 * V_285 ;
struct V_276 * V_171 ;
V_285 = F_112 ( V_260 , struct V_284 , V_260 ) ;
V_171 = (struct V_276 * ) V_285 -> V_267 ;
F_138 ( V_171 ) ;
return;
}
static struct V_284 *
F_141 ( struct V_21 * V_22 )
{
struct V_263 * V_264 ;
struct V_284 * V_285 = NULL ;
T_2 V_287 = 0 ;
F_121 (node, &bc->async_list) {
V_285 = F_122 ( V_264 , struct V_284 , V_60 ) ;
if ( ! F_142 ( & V_285 -> V_260 ) ) {
V_287 = 1 ;
break;
}
}
if ( ! V_287 ) {
V_285 = F_11 ( sizeof( struct V_284 ) ,
V_202 ) ;
if ( V_285 == NULL )
return NULL ;
F_116 ( & V_285 -> V_60 , & V_22 -> V_41 ) ;
}
return V_285 ;
}
static void F_143 ( struct V_21 * V_22 ,
T_4 V_235 , void * V_288 )
{
struct V_284 * V_285 = NULL ;
V_285 = F_141 ( V_22 ) ;
if ( ! V_285 )
return;
V_285 -> V_267 = V_288 ;
F_94 ( & V_285 -> V_260 , V_235 ) ;
F_95 ( V_22 -> V_40 , & V_285 -> V_260 ) ;
}
void F_144 ( struct V_276 * V_171 )
{
struct V_5 * V_6 = F_133 ( V_171 ) ;
struct V_21 * V_22 = & V_6 -> V_34 -> V_20 -> V_22 ;
if ( V_6 -> V_184 )
return;
F_143 ( V_22 , F_140 ,
V_171 ) ;
}
static int F_145 ( struct V_5 * V_6 )
{
int V_29 ;
F_79 ( V_83 , & V_6 -> V_34 -> V_84 . V_85 ) ;
F_146 ( V_6 ) ;
V_29 = F_36 ( V_6 , 1 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_35 ( V_6 , V_168 ) ;
if ( V_29 )
goto V_289;
V_29 = F_64 ( V_6 ) ;
if ( V_29 )
goto V_290;
return 0 ;
V_290:
F_35 ( V_6 , V_68 ) ;
V_289:
F_36 ( V_6 , 0 ) ;
return V_29 ;
}
static void F_147 ( struct V_5 * V_6 )
{
struct V_276 * V_171 = V_6 -> V_171 ;
if ( F_148 ( V_171 ) ) {
if ( ! F_149 ( V_6 , V_171 ) )
F_150 ( V_171 , V_291 ) ;
}
F_151 ( V_171 ) ;
}
static void F_152 ( struct V_5 * V_6 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
struct V_292 * V_293 = V_34 -> V_293 ;
struct V_276 * V_171 = V_6 -> V_171 ;
T_2 V_30 , V_294 = V_34 -> V_295 - 1 ;
F_153 ( V_6 ) ;
F_154 ( V_171 ) ;
if ( F_148 ( V_171 ) )
F_155 ( V_6 , V_171 ) ;
for ( V_30 = 0 ; V_30 < V_294 ; V_30 ++ ) {
V_293 [ V_30 ] . V_296 = V_30 ;
V_293 [ V_30 ] . V_297 = 0 ;
V_293 [ V_30 ] . V_298 = 0 ;
}
V_34 -> V_182 = 0 ;
}
static int F_156 ( struct V_5 * V_6 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
struct V_116 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_299 * V_84 = & V_34 -> V_84 ;
T_2 V_235 = V_34 -> V_42 ;
T_1 V_175 ;
if ( ( V_84 -> V_300 == V_301 ) ||
( V_84 -> V_300 == V_302 ) ) {
if ( ! F_145 ( V_6 ) ) {
F_147 ( V_6 ) ;
V_6 -> V_176 = 0 ;
F_20 ( V_9 ,
L_34 ,
V_303 , V_235 ) ;
} else {
F_13 ( V_9 ,
L_35 ,
V_303 , V_235 ) ;
V_175 = F_41 ( V_34 , V_178 ) ;
F_20 ( V_9 , L_36 ,
V_175 ) ;
}
}
return 0 ;
}
static int F_157 ( struct V_5 * V_6 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
struct V_116 * V_9 = & V_6 -> V_10 -> V_9 ;
struct V_299 * V_84 = & V_34 -> V_84 ;
T_2 V_235 = V_34 -> V_42 ;
T_1 V_175 ;
V_6 -> V_304 ++ ;
if ( V_6 -> V_304 < 3 ) {
V_6 -> V_184 = 1 ;
F_81 ( V_83 , & V_84 -> V_85 ) ;
F_20 ( V_9 ,
L_37 ) ;
return 0 ;
}
if ( V_6 -> V_304 > V_305 ) {
F_81 ( V_180 , & V_84 -> V_85 ) ;
V_6 -> V_306 = 0 ;
V_6 -> V_176 = 0 ;
V_6 -> V_304 = 0 ;
F_152 ( V_6 ) ;
F_13 ( V_9 ,
L_38 ) ;
return - V_31 ;
}
F_20 ( V_9 , L_39 , V_235 ) ;
F_20 ( V_9 , L_40 ,
V_303 , V_6 -> V_304 , V_235 ) ;
F_79 ( V_186 , & V_6 -> V_175 ) ;
V_6 -> V_184 = 1 ;
F_81 ( V_83 , & V_84 -> V_85 ) ;
F_152 ( V_6 ) ;
V_6 -> V_184 = 0 ;
if ( ! F_145 ( V_6 ) ) {
F_147 ( V_6 ) ;
V_6 -> V_306 = 0 ;
V_6 -> V_304 = 0 ;
V_6 -> V_176 = 0 ;
F_20 ( V_9 , L_41 , V_235 ) ;
} else {
F_13 ( V_9 , L_42 ,
V_303 , V_235 ) ;
V_175 = F_41 ( V_34 , V_178 ) ;
F_20 ( V_9 , L_43 , V_303 , V_175 ) ;
}
return 0 ;
}
static int F_158 ( struct V_5 * V_6 )
{
struct V_77 * V_34 = V_6 -> V_34 ;
int V_148 = 0 ;
if ( V_34 -> V_84 . V_300 != V_179 )
V_148 = F_156 ( V_6 ) ;
else if ( V_34 -> V_182 )
V_148 = F_157 ( V_6 ) ;
F_81 ( V_186 , & V_6 -> V_175 ) ;
return V_148 ;
}
static int F_159 ( struct V_5 * V_6 )
{
struct V_299 * V_84 = & V_6 -> V_34 -> V_84 ;
F_13 ( & V_6 -> V_10 -> V_9 , L_44 ) ;
if ( V_84 -> V_300 == V_179 )
F_152 ( V_6 ) ;
F_81 ( V_180 , & V_84 -> V_85 ) ;
F_81 ( V_186 , & V_6 -> V_175 ) ;
return - V_31 ;
}
static int
F_160 ( struct V_5 * V_6 )
{
struct V_299 * V_84 = & V_6 -> V_34 -> V_84 ;
F_20 ( & V_6 -> V_10 -> V_9 , L_45 ) ;
if ( V_84 -> V_300 == V_179 ) {
F_79 ( V_186 , & V_6 -> V_175 ) ;
V_6 -> V_306 = 0 ;
V_6 -> V_304 = 0 ;
F_81 ( V_83 , & V_84 -> V_85 ) ;
F_152 ( V_6 ) ;
}
return 0 ;
}
static int F_161 ( struct V_5 * V_6 )
{
struct V_299 * V_84 = & V_6 -> V_34 -> V_84 ;
T_2 V_235 = V_6 -> V_34 -> V_42 ;
if ( V_84 -> V_300 == V_179 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_46 , V_235 ) ;
F_79 ( V_186 , & V_6 -> V_175 ) ;
V_6 -> V_306 = 0 ;
V_6 -> V_304 = 0 ;
F_81 ( V_83 , & V_84 -> V_85 ) ;
F_152 ( V_6 ) ;
}
return 0 ;
}
static int F_162 ( struct V_5 * V_6 )
{
F_13 ( & V_6 -> V_10 -> V_9 , L_47 , V_303 ) ;
return 0 ;
}
static void V_173 ( struct V_259 * V_260 )
{
struct V_5 * V_6 ;
struct V_299 * V_84 ;
int V_148 = 0 ;
V_6 = F_112 ( V_260 , struct V_5 , V_307 . V_260 ) ;
V_84 = & V_6 -> V_34 -> V_84 ;
V_84 -> V_308 = F_41 ( V_6 -> V_34 , V_178 ) ;
switch ( V_84 -> V_308 ) {
case V_179 :
V_148 = F_158 ( V_6 ) ;
break;
case V_301 :
case V_302 :
V_148 = F_161 ( V_6 ) ;
break;
case V_309 :
V_148 = F_160 ( V_6 ) ;
break;
case V_310 :
V_148 = F_159 ( V_6 ) ;
break;
case V_311 :
break;
default:
V_148 = F_162 ( V_6 ) ;
}
V_84 -> V_300 = V_84 -> V_308 ;
if ( ! V_148 && F_40 ( V_180 , & V_84 -> V_85 ) )
F_73 ( V_6 , V_173 ,
V_84 -> V_174 ) ;
}
static void F_163 ( struct V_5 * V_6 )
{
while ( F_92 ( V_186 , & V_6 -> V_175 ) )
F_77 ( 20 ) ;
F_81 ( V_180 , & V_6 -> V_34 -> V_84 . V_85 ) ;
F_81 ( V_186 , & V_6 -> V_175 ) ;
F_164 ( & V_6 -> V_307 ) ;
}
static int F_165 ( struct V_19 * V_20 ,
T_3 V_312 , T_2 V_269 )
{
T_3 V_277 = V_20 -> V_277 ;
T_2 V_313 = 0 ;
int V_30 ;
if ( V_20 -> V_150 != V_151 )
return - V_201 ;
if ( V_269 ) {
if ( V_277 )
return - V_201 ;
if ( V_20 -> V_146 ) {
for ( V_30 = 0 ; V_30 < V_20 -> V_147 ; V_30 ++ ) {
if ( V_20 -> V_145 [ V_30 ] == V_312 )
V_313 = 1 ;
}
if ( ! V_313 )
return - V_201 ;
}
} else {
if ( ! V_277 || V_277 != V_312 )
return - V_201 ;
}
return 0 ;
}
int F_166 ( struct V_5 * V_6 ,
T_3 V_312 , T_2 V_269 )
{
struct V_19 * V_20 = V_6 -> V_34 -> V_20 ;
struct V_57 V_58 ;
int V_148 ;
if ( V_312 == 0 )
return 0 ;
V_148 = F_165 ( V_20 , V_312 , V_269 ) ;
if ( V_148 )
return V_148 ;
V_148 = F_63 ( & V_58 ,
V_314 ) ;
if ( V_148 )
return V_148 ;
V_58 . V_62 . V_63 [ 1 ] = ( V_269 & 1 ) | V_312 << 16 ;
F_32 ( & V_20 -> V_22 ) ;
V_148 = F_57 ( V_6 , & V_58 ) ;
if ( V_148 ) {
F_13 ( & V_6 -> V_10 -> V_9 ,
L_48 , V_148 ) ;
} else {
F_167 ( V_6 ) ;
if ( V_269 )
V_20 -> V_277 = V_312 ;
else
V_20 -> V_277 = 0 ;
F_138 ( V_6 -> V_171 ) ;
}
F_28 ( & V_58 ) ;
return V_148 ;
}
static void F_168 ( struct V_5 * V_6 )
{
struct V_263 * V_280 = & V_6 -> V_315 ;
struct V_278 * V_279 ;
T_3 V_277 ;
V_277 = V_6 -> V_34 -> V_20 -> V_277 ;
while ( ! F_25 ( V_280 ) ) {
V_279 = F_122 ( V_280 -> V_282 , struct V_278 , V_60 ) ;
F_169 ( V_6 , V_279 -> V_283 ,
V_277 , V_316 ) ;
F_27 ( & V_279 -> V_60 ) ;
F_22 ( V_279 ) ;
}
}
