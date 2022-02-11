static int F_1 ( struct V_1 * V_2 , int * V_3 )
{
int V_4 ;
T_1 V_5 ;
struct V_6 * V_7 = V_2 -> V_6 ;
V_4 = F_2 ( V_7 , V_8 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_3 = F_3 ( V_5 , 15 ) ;
* V_3 = * V_3 * 10 / 256 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int * V_9 )
{
int V_4 , V_10 , V_11 ;
V_4 = F_5 ( V_2 -> V_12 ) ;
if ( V_4 < 0 ) {
* V_9 = V_13 ;
return 0 ;
}
if ( V_4 == 0 ) {
* V_9 = V_14 ;
return 0 ;
}
V_4 = F_2 ( V_2 -> V_6 , V_15 , & V_10 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_2 -> V_6 , V_16 , & V_11 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( V_10 - V_11 ) <= V_17 )
* V_9 = V_18 ;
else
* V_9 = V_19 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int * V_20 )
{
int V_3 , V_21 , V_22 , V_4 ;
T_1 V_23 ;
V_4 = F_2 ( V_2 -> V_6 , V_24 , & V_23 ) ;
if ( V_4 < 0 )
goto V_25;
V_21 = V_23 * 625 / 8 ;
V_21 /= 1000 ;
V_4 = F_2 ( V_2 -> V_6 , V_26 , & V_23 ) ;
if ( V_4 < 0 )
goto V_25;
V_22 = V_23 * 625 / 8 ;
V_22 /= 1000 ;
if ( V_21 < V_2 -> V_27 -> V_28 ) {
* V_20 = V_29 ;
goto V_30;
}
if ( V_22 > V_2 -> V_27 -> V_31 + V_32 ) {
* V_20 = V_33 ;
goto V_30;
}
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( V_4 < 0 )
goto V_25;
if ( V_3 < V_2 -> V_27 -> V_34 ) {
* V_20 = V_35 ;
goto V_30;
}
if ( V_3 > V_2 -> V_27 -> V_36 ) {
* V_20 = V_37 ;
goto V_30;
}
* V_20 = V_38 ;
V_30:
return 0 ;
V_25:
return V_4 ;
}
static int F_7 ( struct V_39 * V_40 ,
enum V_41 V_42 ,
union V_43 * V_23 )
{
struct V_1 * V_2 = F_8 ( V_40 ) ;
struct V_6 * V_7 = V_2 -> V_6 ;
int V_4 ;
T_1 V_5 ;
T_2 V_44 ;
if ( ! V_2 -> V_45 )
return - V_46 ;
switch ( V_42 ) {
case V_47 :
V_4 = F_4 ( V_2 , & V_23 -> V_48 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_49 :
V_4 = F_2 ( V_7 , V_50 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_5 & V_51 )
V_23 -> V_48 = 0 ;
else
V_23 -> V_48 = 1 ;
break;
case V_52 :
V_23 -> V_48 = V_53 ;
break;
case V_54 :
V_4 = F_2 ( V_7 , V_55 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = V_5 ;
break;
case V_56 :
V_4 = F_2 ( V_7 , V_57 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = V_5 >> 8 ;
V_23 -> V_48 *= 20000 ;
break;
case V_58 :
V_4 = F_2 ( V_7 , V_57 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = ( V_5 & 0xff ) * 20000 ;
break;
case V_59 :
if ( V_2 -> V_60 == V_61 )
V_4 = F_2 ( V_7 , V_62 , & V_5 ) ;
else
V_4 = F_2 ( V_7 , V_63 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = V_5 >> 7 ;
V_23 -> V_48 *= 10000 ;
break;
case V_64 :
V_4 = F_2 ( V_7 , V_26 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = V_5 * 625 / 8 ;
break;
case V_65 :
V_4 = F_2 ( V_7 , V_24 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = V_5 * 625 / 8 ;
break;
case V_66 :
V_4 = F_2 ( V_7 , V_67 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = V_5 * 625 / 8 ;
break;
case V_68 :
V_4 = F_2 ( V_7 , V_69 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = V_5 >> 8 ;
break;
case V_70 :
V_4 = F_2 ( V_7 , V_71 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_44 = V_5 * 5000000ll ;
F_9 ( V_44 , V_2 -> V_27 -> V_72 ) ;
V_23 -> V_48 = V_44 ;
break;
case V_73 :
V_4 = F_2 ( V_7 , V_15 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_44 = V_5 * 5000000ll ;
F_9 ( V_44 , V_2 -> V_27 -> V_72 ) ;
V_23 -> V_48 = V_44 ;
break;
case V_74 :
V_4 = F_2 ( V_7 , V_16 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_44 = V_5 * 5000000ll ;
F_9 ( V_44 , V_2 -> V_27 -> V_72 ) ;
V_23 -> V_48 = V_44 ;
break;
case V_75 :
V_4 = F_2 ( V_7 , V_76 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = V_5 * 1000 / 2 ;
break;
case V_77 :
V_4 = F_1 ( V_2 , & V_23 -> V_48 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_78 :
V_4 = F_2 ( V_7 , V_79 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = F_3 ( V_5 & 0xff , 7 ) * 10 ;
break;
case V_80 :
V_4 = F_2 ( V_7 , V_79 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = F_3 ( V_5 >> 8 , 7 ) * 10 ;
break;
case V_81 :
V_23 -> V_48 = V_2 -> V_27 -> V_34 ;
break;
case V_82 :
V_23 -> V_48 = V_2 -> V_27 -> V_36 ;
break;
case V_83 :
V_4 = F_6 ( V_2 , & V_23 -> V_48 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_84 :
V_23 -> V_48 = V_85 ;
break;
case V_86 :
if ( V_2 -> V_27 -> V_87 ) {
V_4 = F_2 ( V_7 , V_88 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = F_3 ( V_5 , 15 ) ;
V_23 -> V_48 *= 1562500 / V_2 -> V_27 -> V_72 ;
} else {
return - V_89 ;
}
break;
case V_90 :
if ( V_2 -> V_27 -> V_87 ) {
V_4 = F_2 ( V_7 , V_91 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 -> V_48 = F_3 ( V_5 , 15 ) ;
V_23 -> V_48 *= 1562500 / V_2 -> V_27 -> V_72 ;
} else {
return - V_89 ;
}
break;
default:
return - V_89 ;
}
return 0 ;
}
static int F_10 ( struct V_39 * V_40 ,
enum V_41 V_42 ,
const union V_43 * V_23 )
{
struct V_1 * V_2 = F_8 ( V_40 ) ;
struct V_6 * V_7 = V_2 -> V_6 ;
int V_4 = 0 ;
T_1 V_5 ;
T_3 V_3 ;
switch ( V_42 ) {
case V_78 :
V_4 = F_2 ( V_7 , V_79 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_3 = V_23 -> V_48 / 10 ;
if ( V_3 >= ( T_3 ) ( V_5 >> 8 ) )
V_3 = ( T_3 ) ( V_5 >> 8 ) - 1 ;
V_5 = ( V_5 & 0xff00 ) + V_3 ;
V_4 = F_11 ( V_7 , V_79 , V_5 ) ;
break;
case V_80 :
V_4 = F_2 ( V_7 , V_79 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_3 = V_23 -> V_48 / 10 ;
if ( V_3 <= ( T_3 ) ( V_5 & 0xff ) )
V_3 = ( T_3 ) ( V_5 & 0xff ) + 1 ;
V_5 = ( V_5 & 0xff ) + ( V_3 << 8 ) ;
V_4 = F_11 ( V_7 , V_79 , V_5 ) ;
break;
default:
V_4 = - V_89 ;
}
return V_4 ;
}
static int F_12 ( struct V_39 * V_40 ,
enum V_41 V_42 )
{
int V_4 ;
switch ( V_42 ) {
case V_78 :
case V_80 :
V_4 = 1 ;
break;
default:
V_4 = 0 ;
}
return V_4 ;
}
static void F_13 ( struct V_39 * V_40 )
{
F_14 ( V_40 ) ;
}
static int F_15 ( struct V_6 * V_7 , T_4 V_92 , T_1 V_93 )
{
int V_94 = 8 ;
int V_4 ;
T_1 V_95 ;
do {
V_4 = F_11 ( V_7 , V_92 , V_93 ) ;
F_2 ( V_7 , V_92 , & V_95 ) ;
if ( V_95 != V_93 ) {
V_4 = - V_96 ;
V_94 -- ;
}
} while ( V_94 && V_95 != V_93 );
if ( V_4 < 0 )
F_16 ( L_1 , V_97 , V_4 ) ;
return V_4 ;
}
static inline void F_17 ( struct V_6 * V_7 ,
T_4 V_92 , T_5 V_93 )
{
if ( V_93 )
F_11 ( V_7 , V_92 , V_93 ) ;
}
static inline void F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
F_11 ( V_7 , V_98 , V_99 ) ;
F_11 ( V_7 , V_100 , V_101 ) ;
}
static inline void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
F_11 ( V_7 , V_98 , V_102 ) ;
F_11 ( V_7 , V_100 , V_103 ) ;
}
static inline void F_20 ( struct V_1 * V_2 ,
T_4 V_104 , int V_105 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ )
F_11 ( V_7 , V_104 + V_106 ,
V_2 -> V_27 -> V_107 -> V_108 [ V_106 ] ) ;
}
static inline void F_21 ( struct V_1 * V_2 ,
T_4 V_104 , T_5 * V_5 , int V_105 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
int V_106 ;
T_1 V_109 ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
F_2 ( V_7 , V_104 + V_106 , & V_109 ) ;
V_5 [ V_106 ] = ( T_5 ) V_109 ;
}
}
static inline int F_22 ( struct V_1 * V_2 ,
T_5 * V_110 , T_5 * V_111 , int V_105 )
{
int V_106 ;
if ( memcmp ( V_110 , V_111 , V_105 ) ) {
F_23 ( & V_2 -> V_112 -> V_113 , L_2 , V_97 ) ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ )
F_24 ( & V_2 -> V_112 -> V_113 , L_3 ,
V_110 [ V_106 ] , V_111 [ V_106 ] ) ;
F_24 ( & V_2 -> V_112 -> V_113 , L_4 ) ;
return - V_89 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_4 ;
int V_114 = F_26 ( V_2 -> V_27 -> V_107 -> V_108 ) ;
T_5 * V_115 ;
V_115 = F_27 ( V_114 , sizeof( * V_115 ) , V_116 ) ;
if ( ! V_115 )
return - V_117 ;
F_18 ( V_2 ) ;
F_20 ( V_2 , V_118 ,
V_114 ) ;
F_21 ( V_2 , V_118 , V_115 ,
V_114 ) ;
V_4 = F_22 (
V_2 ,
V_2 -> V_27 -> V_107 -> V_108 ,
V_115 ,
V_114 ) ;
F_19 ( V_2 ) ;
F_28 ( V_115 ) ;
return V_4 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_106 ;
int V_114 = F_26 ( V_2 -> V_27 -> V_107 -> V_108 ) ;
T_5 * V_115 ;
int V_4 = 0 ;
V_115 = F_27 ( V_114 , sizeof( * V_115 ) , V_116 ) ;
if ( ! V_115 )
return - V_117 ;
F_21 ( V_2 , V_118 , V_115 ,
V_114 ) ;
for ( V_106 = 0 ; V_106 < V_114 ; V_106 ++ )
if ( V_115 [ V_106 ] )
V_4 = - V_89 ;
F_28 ( V_115 ) ;
return V_4 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_119 * V_120 = V_2 -> V_27 -> V_107 ;
struct V_6 * V_7 = V_2 -> V_6 ;
F_11 ( V_7 , V_121 , V_120 -> V_120 ) ;
F_11 ( V_7 , V_122 , V_120 -> V_123 ) ;
F_11 ( V_7 , V_124 ,
V_120 -> V_125 ) ;
F_11 ( V_7 , V_126 , V_120 -> V_127 ) ;
if ( V_2 -> V_60 == V_128 ||
V_2 -> V_60 == V_129 )
F_11 ( V_7 , V_130 ,
V_120 -> V_131 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_119 * V_120 = V_2 -> V_27 -> V_107 ;
struct V_6 * V_7 = V_2 -> V_6 ;
F_15 ( V_7 , V_132 , V_120 -> V_133 ) ;
F_15 ( V_7 , V_134 , V_120 -> V_135 ) ;
F_15 ( V_7 , V_136 , V_120 -> V_137 ) ;
if ( V_2 -> V_60 == V_61 ) {
F_11 ( V_7 , V_138 , V_120 -> V_139 ) ;
F_15 ( V_7 , V_140 ,
V_120 -> V_141 ) ;
} else {
F_15 ( V_7 , V_142 ,
V_120 -> V_143 ) ;
F_15 ( V_7 , V_144 ,
V_120 -> V_145 ) ;
F_15 ( V_7 , V_146 ,
V_120 -> V_147 ) ;
F_15 ( V_7 , V_148 ,
V_120 -> V_149 ) ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_119 * V_120 = V_2 -> V_27 -> V_107 ;
struct V_6 * V_7 = V_2 -> V_6 ;
F_15 ( V_7 , V_15 ,
V_120 -> V_150 ) ;
F_11 ( V_7 , V_71 , V_120 -> V_151 ) ;
F_15 ( V_7 , V_152 ,
V_120 -> V_153 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
unsigned int V_154 ;
struct V_6 * V_7 = V_2 -> V_6 ;
F_2 ( V_7 , V_155 , & V_154 ) ;
F_11 ( V_7 , V_156 , V_157 ) ;
F_15 ( V_7 , V_158 , V_154 ) ;
F_11 ( V_7 , V_156 , V_159 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_160 , V_161 , V_162 , V_154 ;
T_1 V_163 ;
struct V_119 * V_120 = V_2 -> V_27 -> V_107 ;
struct V_6 * V_7 = V_2 -> V_6 ;
F_2 ( V_7 , V_164 , & V_160 ) ;
F_2 ( V_7 , V_155 , & V_154 ) ;
V_163 = ( ( V_154 >> 8 ) * V_160 ) / 100 ;
F_15 ( V_7 , V_165 , V_163 ) ;
V_161 = V_163 ;
F_15 ( V_7 , V_16 , V_161 ) ;
V_162 = V_120 -> V_150 / V_166 ;
F_15 ( V_7 , V_167 , V_162 ) ;
F_15 ( V_7 , V_168 , V_169 ) ;
F_15 ( V_7 , V_15 ,
V_120 -> V_150 ) ;
F_11 ( V_7 , V_71 ,
V_120 -> V_151 ) ;
F_15 ( V_7 , V_152 ,
V_120 -> V_153 ) ;
F_11 ( V_7 , V_69 , V_154 ) ;
}
static inline void F_35 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_119 * V_120 = V_2 -> V_27 -> V_107 ;
F_17 ( V_7 , V_170 , V_120 -> V_171 ) ;
F_17 ( V_7 , V_172 , V_120 -> V_173 ) ;
F_17 ( V_7 , V_174 , V_120 -> V_175 ) ;
F_17 ( V_7 , V_176 , V_120 -> V_177 ) ;
F_17 ( V_7 , V_178 , V_120 -> V_179 ) ;
F_17 ( V_7 , V_79 , V_120 -> V_180 ) ;
F_17 ( V_7 , V_181 ,
V_120 -> V_182 ) ;
F_17 ( V_7 , V_121 , V_120 -> V_120 ) ;
F_17 ( V_7 , V_183 , V_120 -> V_184 ) ;
F_17 ( V_7 , V_71 , V_120 -> V_151 ) ;
F_17 ( V_7 , V_136 , V_120 -> V_137 ) ;
F_17 ( V_7 , V_185 , V_120 -> V_186 ) ;
F_17 ( V_7 , V_122 , V_120 -> V_123 ) ;
F_17 ( V_7 , V_124 , V_120 -> V_125 ) ;
F_17 ( V_7 , V_126 , V_120 -> V_127 ) ;
F_17 ( V_7 , V_187 , V_120 -> V_188 ) ;
F_17 ( V_7 , V_189 , V_120 -> V_190 ) ;
F_17 ( V_7 , V_15 , V_120 -> V_150 ) ;
F_17 ( V_7 , V_152 , V_120 -> V_153 ) ;
if ( V_2 -> V_60 == V_61 )
F_17 ( V_7 , V_191 ,
V_120 -> V_192 ) ;
F_17 ( V_7 , V_193 , V_120 -> V_194 ) ;
F_17 ( V_7 , V_167 , V_120 -> V_195 ) ;
F_17 ( V_7 , V_168 , V_120 -> V_196 ) ;
if ( V_2 -> V_60 == V_61 )
F_17 ( V_7 , V_62 , V_120 -> V_197 ) ;
else
F_17 ( V_7 , V_63 , V_120 -> V_197 ) ;
F_17 ( V_7 , V_198 , V_120 -> V_199 ) ;
F_17 ( V_7 , V_200 , V_120 -> V_201 ) ;
F_17 ( V_7 , V_202 , V_120 -> V_203 ) ;
F_17 ( V_7 , V_132 , V_120 -> V_133 ) ;
F_17 ( V_7 , V_134 , V_120 -> V_135 ) ;
if ( V_2 -> V_60 ) {
F_17 ( V_7 , V_138 ,
V_120 -> V_139 ) ;
F_17 ( V_7 , V_140 ,
V_120 -> V_141 ) ;
}
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
int V_4 ;
F_35 ( V_2 ) ;
F_37 ( 500 ) ;
F_30 ( V_2 ) ;
V_4 = F_25 ( V_2 ) ;
if ( V_4 ) {
F_23 ( & V_2 -> V_112 -> V_113 , L_5 ,
V_97 ) ;
return - V_96 ;
}
V_4 = F_29 ( V_2 ) ;
if ( V_4 ) {
F_23 ( & V_2 -> V_112 -> V_113 , L_6 ,
V_97 ) ;
return - V_96 ;
}
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
F_37 ( 350 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_38 ( V_7 , V_50 , V_204 , 0x0 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , T_5 V_205 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
T_1 V_206 , V_207 ;
F_2 ( V_7 , V_69 , & V_206 ) ;
V_206 >>= 8 ;
V_207 = ( V_206 + V_205 ) << 8 ;
V_207 |= ( V_206 - V_205 ) ;
F_11 ( V_7 , V_181 , V_207 ) ;
}
static T_6 F_40 ( int V_208 , void * V_113 )
{
struct V_1 * V_2 = V_113 ;
T_1 V_23 ;
F_2 ( V_2 -> V_6 , V_50 , & V_23 ) ;
if ( ( V_23 & V_209 ) ||
( V_23 & V_210 ) ) {
F_24 ( & V_2 -> V_112 -> V_113 , L_7 ) ;
F_39 ( V_2 , 1 ) ;
}
F_14 ( V_2 -> V_12 ) ;
return V_211 ;
}
static void F_41 ( struct V_212 * V_213 )
{
struct V_1 * V_2 = F_42 ( V_213 ,
struct V_1 , V_213 ) ;
int V_4 ;
if ( V_2 -> V_27 -> V_214 && V_2 -> V_27 -> V_107 ) {
V_4 = F_36 ( V_2 ) ;
if ( V_4 )
return;
}
V_2 -> V_45 = 1 ;
}
static struct V_215 *
F_43 ( struct V_1 * V_2 )
{
struct V_216 * V_113 = & V_2 -> V_112 -> V_113 ;
struct V_217 * V_218 = V_113 -> V_219 ;
T_1 V_220 ;
struct V_215 * V_27 ;
if ( ! V_218 )
return V_113 -> V_221 ;
V_27 = F_44 ( V_113 , sizeof( * V_27 ) , V_116 ) ;
if ( ! V_27 )
return NULL ;
if ( F_45 ( V_218 , L_8 , & V_220 ) == 0 ) {
V_27 -> V_72 = V_220 ;
V_27 -> V_87 = true ;
}
if ( F_46 ( V_218 , L_9 , & V_27 -> V_34 ) )
V_27 -> V_34 = V_222 ;
if ( F_46 ( V_218 , L_10 , & V_27 -> V_36 ) )
V_27 -> V_36 = V_223 ;
if ( F_46 ( V_218 , L_11 , & V_27 -> V_28 ) )
V_27 -> V_28 = V_222 ;
if ( F_46 ( V_218 , L_12 , & V_27 -> V_31 ) )
V_27 -> V_31 = V_223 ;
return V_27 ;
}
static struct V_215 *
F_43 ( struct V_1 * V_2 )
{
struct V_216 * V_113 = & V_2 -> V_112 -> V_113 ;
struct V_215 * V_27 ;
int V_4 , V_188 ;
if ( V_113 -> V_221 )
return V_113 -> V_221 ;
V_27 = F_44 ( V_113 , sizeof( * V_27 ) , V_116 ) ;
if ( ! V_27 )
return V_27 ;
if ( V_2 -> V_60 != V_61 ) {
V_27 -> V_224 = V_225 ;
V_27 -> V_226 =
F_26 ( V_225 ) ;
}
V_4 = F_2 ( V_2 -> V_6 , V_187 , & V_188 ) ;
if ( V_4 < 0 )
return NULL ;
if ( ( V_188 & 0x3 ) == 0x3 )
V_27 -> V_87 = false ;
else
V_27 -> V_87 = true ;
V_27 -> V_28 = V_227 ;
V_27 -> V_31 = V_228 ;
V_27 -> V_34 = V_229 ;
V_27 -> V_36 = V_230 ;
return V_27 ;
}
static int F_47 ( struct V_231 * V_112 ,
const struct V_232 * V_208 )
{
struct V_233 * V_234 = F_48 ( V_112 -> V_113 . V_235 ) ;
const struct V_236 * V_237 = & V_238 ;
struct V_239 V_240 = {} ;
struct V_1 * V_2 ;
int V_4 ;
int V_106 ;
T_1 V_23 ;
if ( ! F_49 ( V_234 , V_241 ) )
return - V_96 ;
V_2 = F_44 ( & V_112 -> V_113 , sizeof( * V_2 ) , V_116 ) ;
if ( ! V_2 )
return - V_117 ;
V_2 -> V_112 = V_112 ;
V_2 -> V_60 = V_208 -> V_242 ;
V_2 -> V_6 = F_50 ( V_112 , & V_243 ) ;
if ( F_51 ( V_2 -> V_6 ) ) {
F_23 ( & V_112 -> V_113 , L_13 ) ;
return - V_89 ;
}
V_2 -> V_27 = F_43 ( V_2 ) ;
if ( ! V_2 -> V_27 ) {
F_23 ( & V_112 -> V_113 , L_14 ) ;
return - V_89 ;
}
F_52 ( V_112 , V_2 ) ;
V_240 . V_244 = V_2 ;
if ( ! V_2 -> V_27 -> V_87 )
V_237 = & V_245 ;
if ( V_2 -> V_27 -> V_72 == 0 )
V_2 -> V_27 -> V_72 = V_246 ;
if ( V_2 -> V_27 -> V_224 )
for ( V_106 = 0 ; V_106 < V_2 -> V_27 -> V_226 ; V_106 ++ )
F_11 ( V_2 -> V_6 ,
V_2 -> V_27 -> V_224 [ V_106 ] . V_104 ,
V_2 -> V_27 -> V_224 [ V_106 ] . V_5 ) ;
if ( ! V_2 -> V_27 -> V_87 ) {
F_11 ( V_2 -> V_6 , V_174 , 0x0000 ) ;
F_11 ( V_2 -> V_6 , V_187 , 0x0003 ) ;
F_11 ( V_2 -> V_6 , V_122 , 0x0007 ) ;
}
V_2 -> V_12 = F_53 ( & V_112 -> V_113 , V_237 ,
& V_240 ) ;
if ( F_51 ( V_2 -> V_12 ) ) {
F_23 ( & V_112 -> V_113 , L_15 ) ;
return F_54 ( V_2 -> V_12 ) ;
}
if ( V_112 -> V_247 ) {
V_4 = F_55 ( & V_112 -> V_113 , V_112 -> V_247 ,
NULL ,
F_40 ,
V_248 |
V_249 ,
V_2 -> V_12 -> V_250 -> V_251 ,
V_2 ) ;
if ( ! V_4 ) {
F_38 ( V_2 -> V_6 , V_121 ,
V_252 ,
V_252 ) ;
F_39 ( V_2 , 1 ) ;
} else {
V_112 -> V_247 = 0 ;
F_23 ( & V_112 -> V_113 , L_16 ,
V_97 ) ;
}
}
F_2 ( V_2 -> V_6 , V_50 , & V_23 ) ;
if ( V_23 & V_204 ) {
F_56 ( & V_2 -> V_213 , F_41 ) ;
F_57 ( & V_2 -> V_213 ) ;
} else {
V_2 -> V_45 = 1 ;
}
return 0 ;
}
static int F_58 ( struct V_216 * V_113 )
{
struct V_1 * V_2 = F_59 ( V_113 ) ;
if ( V_2 -> V_112 -> V_247 ) {
F_60 ( V_2 -> V_112 -> V_247 ) ;
F_61 ( V_2 -> V_112 -> V_247 ) ;
}
return 0 ;
}
static int F_62 ( struct V_216 * V_113 )
{
struct V_1 * V_2 = F_59 ( V_113 ) ;
if ( V_2 -> V_112 -> V_247 ) {
F_63 ( V_2 -> V_112 -> V_247 ) ;
F_64 ( V_2 -> V_112 -> V_247 ) ;
F_39 ( V_2 , 1 ) ;
}
return 0 ;
}
