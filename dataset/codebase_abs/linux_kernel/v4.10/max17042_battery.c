static int F_1 ( struct V_1 * V_2 , int * V_3 )
{
int V_4 ;
T_1 V_5 ;
struct V_6 * V_7 = V_2 -> V_6 ;
V_4 = F_2 ( V_7 , V_8 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_3 = V_5 ;
if ( * V_3 & 0x8000 ) {
* V_3 = ( 0x7fff & ~ * V_3 ) + 1 ;
* V_3 *= - 1 ;
}
* V_3 = * V_3 * 10 / 256 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int * V_9 )
{
int V_3 , V_10 , V_11 , V_4 ;
T_1 V_12 ;
V_4 = F_2 ( V_2 -> V_6 , V_13 , & V_12 ) ;
if ( V_4 < 0 )
goto V_14;
V_10 = V_12 * 625 / 8 ;
V_10 /= 1000 ;
V_4 = F_2 ( V_2 -> V_6 , V_15 , & V_12 ) ;
if ( V_4 < 0 )
goto V_14;
V_11 = V_12 * 625 / 8 ;
V_11 /= 1000 ;
if ( V_10 < V_2 -> V_16 -> V_17 ) {
* V_9 = V_18 ;
goto V_19;
}
if ( V_11 > V_2 -> V_16 -> V_20 + V_21 ) {
* V_9 = V_22 ;
goto V_19;
}
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( V_4 < 0 )
goto V_14;
if ( V_3 <= V_2 -> V_16 -> V_23 ) {
* V_9 = V_24 ;
goto V_19;
}
if ( V_3 >= V_2 -> V_16 -> V_25 ) {
* V_9 = V_26 ;
goto V_19;
}
* V_9 = V_27 ;
V_19:
return 0 ;
V_14:
return V_4 ;
}
static int F_4 ( struct V_28 * V_29 ,
enum V_30 V_31 ,
union V_32 * V_12 )
{
struct V_1 * V_2 = F_5 ( V_29 ) ;
struct V_6 * V_7 = V_2 -> V_6 ;
int V_4 ;
T_1 V_5 ;
if ( ! V_2 -> V_33 )
return - V_34 ;
switch ( V_31 ) {
case V_35 :
V_4 = F_2 ( V_7 , V_36 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_5 & V_37 )
V_12 -> V_38 = 0 ;
else
V_12 -> V_38 = 1 ;
break;
case V_39 :
V_4 = F_2 ( V_7 , V_40 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = V_5 ;
break;
case V_41 :
V_4 = F_2 ( V_7 , V_42 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = V_5 >> 8 ;
V_12 -> V_38 *= 20000 ;
break;
case V_43 :
if ( V_2 -> V_44 == V_45 )
V_4 = F_2 ( V_7 , V_46 , & V_5 ) ;
else
V_4 = F_2 ( V_7 , V_47 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = V_5 >> 7 ;
V_12 -> V_38 *= 10000 ;
break;
case V_48 :
V_4 = F_2 ( V_7 , V_15 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = V_5 * 625 / 8 ;
break;
case V_49 :
V_4 = F_2 ( V_7 , V_13 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = V_5 * 625 / 8 ;
break;
case V_50 :
V_4 = F_2 ( V_7 , V_51 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = V_5 * 625 / 8 ;
break;
case V_52 :
V_4 = F_2 ( V_7 , V_53 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = V_5 >> 8 ;
break;
case V_54 :
V_4 = F_2 ( V_7 , V_55 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = V_5 * 1000 / 2 ;
break;
case V_56 :
V_4 = F_2 ( V_7 , V_57 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = V_5 * 1000 / 2 ;
break;
case V_58 :
V_4 = F_1 ( V_2 , & V_12 -> V_38 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_59 :
V_4 = F_2 ( V_7 , V_60 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = ( V_5 & 0xff ) * 10 ;
break;
case V_61 :
V_4 = F_2 ( V_7 , V_60 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = ( V_5 >> 8 ) * 10 ;
break;
case V_62 :
V_12 -> V_38 = V_2 -> V_16 -> V_23 ;
break;
case V_63 :
V_12 -> V_38 = V_2 -> V_16 -> V_25 ;
break;
case V_64 :
V_4 = F_3 ( V_2 , & V_12 -> V_38 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_65 :
if ( V_2 -> V_16 -> V_66 ) {
V_4 = F_2 ( V_7 , V_67 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = V_5 ;
if ( V_12 -> V_38 & 0x8000 ) {
V_12 -> V_38 = ~ V_12 -> V_38 & 0x7fff ;
V_12 -> V_38 ++ ;
V_12 -> V_38 *= - 1 ;
}
V_12 -> V_38 *= 1562500 / V_2 -> V_16 -> V_68 ;
} else {
return - V_69 ;
}
break;
case V_70 :
if ( V_2 -> V_16 -> V_66 ) {
V_4 = F_2 ( V_7 , V_71 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 -> V_38 = V_5 ;
if ( V_12 -> V_38 & 0x8000 ) {
V_12 -> V_38 = ~ V_12 -> V_38 & 0x7fff ;
V_12 -> V_38 ++ ;
V_12 -> V_38 *= - 1 ;
}
V_12 -> V_38 *= 1562500 / V_2 -> V_16 -> V_68 ;
} else {
return - V_69 ;
}
break;
default:
return - V_69 ;
}
return 0 ;
}
static int F_6 ( struct V_28 * V_29 ,
enum V_30 V_31 ,
const union V_32 * V_12 )
{
struct V_1 * V_2 = F_5 ( V_29 ) ;
struct V_6 * V_7 = V_2 -> V_6 ;
int V_4 = 0 ;
T_1 V_5 ;
T_2 V_3 ;
switch ( V_31 ) {
case V_59 :
V_4 = F_2 ( V_7 , V_60 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_3 = V_12 -> V_38 / 10 ;
if ( V_3 >= ( T_2 ) ( V_5 >> 8 ) )
V_3 = ( T_2 ) ( V_5 >> 8 ) - 1 ;
V_5 = ( V_5 & 0xff00 ) + V_3 ;
V_4 = F_7 ( V_7 , V_60 , V_5 ) ;
break;
case V_61 :
V_4 = F_2 ( V_7 , V_60 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_3 = V_12 -> V_38 / 10 ;
if ( V_3 <= ( T_2 ) ( V_5 & 0xff ) )
V_3 = ( T_2 ) ( V_5 & 0xff ) + 1 ;
V_5 = ( V_5 & 0xff ) + ( V_3 << 8 ) ;
V_4 = F_7 ( V_7 , V_60 , V_5 ) ;
break;
default:
V_4 = - V_69 ;
}
return V_4 ;
}
static int F_8 ( struct V_28 * V_29 ,
enum V_30 V_31 )
{
int V_4 ;
switch ( V_31 ) {
case V_59 :
case V_61 :
V_4 = 1 ;
break;
default:
V_4 = 0 ;
}
return V_4 ;
}
static int F_9 ( struct V_6 * V_7 , T_3 V_72 , T_1 V_73 )
{
int V_74 = 8 ;
int V_4 ;
T_1 V_75 ;
do {
V_4 = F_7 ( V_7 , V_72 , V_73 ) ;
F_2 ( V_7 , V_72 , & V_75 ) ;
if ( V_75 != V_73 ) {
V_4 = - V_76 ;
V_74 -- ;
}
} while ( V_74 && V_75 != V_73 );
if ( V_4 < 0 )
F_10 ( L_1 , V_77 , V_4 ) ;
return V_4 ;
}
static inline void F_11 ( struct V_6 * V_7 ,
T_3 V_72 , T_4 V_73 )
{
if ( V_73 )
F_7 ( V_7 , V_72 , V_73 ) ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
F_7 ( V_7 , V_78 , V_79 ) ;
F_7 ( V_7 , V_80 , V_81 ) ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
F_7 ( V_7 , V_78 , V_82 ) ;
F_7 ( V_7 , V_80 , V_83 ) ;
}
static inline void F_14 ( struct V_1 * V_2 ,
T_3 V_84 , int V_85 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_85 ; V_86 ++ )
F_7 ( V_7 , V_84 + V_86 ,
V_2 -> V_16 -> V_87 -> V_88 [ V_86 ] ) ;
}
static inline void F_15 ( struct V_1 * V_2 ,
T_3 V_84 , T_4 * V_5 , int V_85 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
int V_86 ;
T_1 V_89 ;
for ( V_86 = 0 ; V_86 < V_85 ; V_86 ++ ) {
F_2 ( V_7 , V_84 + V_86 , & V_89 ) ;
V_5 [ V_86 ] = ( T_4 ) V_89 ;
}
}
static inline int F_16 ( struct V_1 * V_2 ,
T_4 * V_90 , T_4 * V_91 , int V_85 )
{
int V_86 ;
if ( memcmp ( V_90 , V_91 , V_85 ) ) {
F_17 ( & V_2 -> V_92 -> V_93 , L_2 , V_77 ) ;
for ( V_86 = 0 ; V_86 < V_85 ; V_86 ++ )
F_18 ( & V_2 -> V_92 -> V_93 , L_3 ,
V_90 [ V_86 ] , V_91 [ V_86 ] ) ;
F_18 ( & V_2 -> V_92 -> V_93 , L_4 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_4 ;
int V_94 = F_20 ( V_2 -> V_16 -> V_87 -> V_88 ) ;
T_4 * V_95 ;
V_95 = F_21 ( V_94 , sizeof( * V_95 ) , V_96 ) ;
if ( ! V_95 )
return - V_97 ;
F_12 ( V_2 ) ;
F_14 ( V_2 , V_98 ,
V_94 ) ;
F_15 ( V_2 , V_98 , V_95 ,
V_94 ) ;
V_4 = F_16 (
V_2 ,
V_2 -> V_16 -> V_87 -> V_88 ,
V_95 ,
V_94 ) ;
F_13 ( V_2 ) ;
F_22 ( V_95 ) ;
return V_4 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_86 ;
int V_94 = F_20 ( V_2 -> V_16 -> V_87 -> V_88 ) ;
T_4 * V_95 ;
int V_4 = 0 ;
V_95 = F_21 ( V_94 , sizeof( * V_95 ) , V_96 ) ;
if ( ! V_95 )
return - V_97 ;
F_15 ( V_2 , V_98 , V_95 ,
V_94 ) ;
for ( V_86 = 0 ; V_86 < V_94 ; V_86 ++ )
if ( V_95 [ V_86 ] )
V_4 = - V_69 ;
F_22 ( V_95 ) ;
return V_4 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_99 * V_100 = V_2 -> V_16 -> V_87 ;
struct V_6 * V_7 = V_2 -> V_6 ;
F_7 ( V_7 , V_101 , V_100 -> V_100 ) ;
F_7 ( V_7 , V_102 , V_100 -> V_103 ) ;
F_7 ( V_7 , V_104 ,
V_100 -> V_105 ) ;
F_7 ( V_7 , V_106 , V_100 -> V_107 ) ;
if ( V_2 -> V_44 == V_108 ||
V_2 -> V_44 == V_109 )
F_7 ( V_7 , V_110 ,
V_100 -> V_111 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_99 * V_100 = V_2 -> V_16 -> V_87 ;
struct V_6 * V_7 = V_2 -> V_6 ;
F_9 ( V_7 , V_112 , V_100 -> V_113 ) ;
F_9 ( V_7 , V_114 , V_100 -> V_115 ) ;
F_9 ( V_7 , V_116 , V_100 -> V_117 ) ;
if ( V_2 -> V_44 == V_45 ) {
F_7 ( V_7 , V_118 , V_100 -> V_119 ) ;
F_9 ( V_7 , V_120 ,
V_100 -> V_121 ) ;
} else {
F_9 ( V_7 , V_122 ,
V_100 -> V_123 ) ;
F_9 ( V_7 , V_124 ,
V_100 -> V_125 ) ;
F_9 ( V_7 , V_126 ,
V_100 -> V_127 ) ;
F_9 ( V_7 , V_128 ,
V_100 -> V_129 ) ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_99 * V_100 = V_2 -> V_16 -> V_87 ;
struct V_6 * V_7 = V_2 -> V_6 ;
F_9 ( V_7 , V_55 ,
V_100 -> V_130 ) ;
F_7 ( V_7 , V_131 , V_100 -> V_132 ) ;
F_9 ( V_7 , V_133 ,
V_100 -> V_134 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
unsigned int V_135 ;
struct V_6 * V_7 = V_2 -> V_6 ;
F_2 ( V_7 , V_136 , & V_135 ) ;
F_7 ( V_7 , V_137 , V_138 ) ;
F_9 ( V_7 , V_139 , V_135 ) ;
F_7 ( V_7 , V_137 , V_140 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_141 , V_142 , V_143 , V_135 ;
T_1 V_144 ;
struct V_99 * V_100 = V_2 -> V_16 -> V_87 ;
struct V_6 * V_7 = V_2 -> V_6 ;
F_2 ( V_7 , V_145 , & V_141 ) ;
F_2 ( V_7 , V_136 , & V_135 ) ;
V_144 = ( ( V_135 >> 8 ) * V_141 ) / 100 ;
F_9 ( V_7 , V_146 , V_144 ) ;
V_142 = V_144 ;
F_9 ( V_7 , V_147 , V_142 ) ;
V_143 = V_100 -> V_130 / V_148 ;
F_9 ( V_7 , V_149 , V_143 ) ;
F_9 ( V_7 , V_150 , V_151 ) ;
F_9 ( V_7 , V_55 ,
V_100 -> V_130 ) ;
F_7 ( V_7 , V_131 ,
V_100 -> V_132 ) ;
F_9 ( V_7 , V_133 ,
V_100 -> V_134 ) ;
F_7 ( V_7 , V_53 , V_135 ) ;
}
static inline void F_29 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_99 * V_100 = V_2 -> V_16 -> V_87 ;
F_11 ( V_7 , V_152 , V_100 -> V_153 ) ;
F_11 ( V_7 , V_154 , V_100 -> V_155 ) ;
F_11 ( V_7 , V_156 , V_100 -> V_157 ) ;
F_11 ( V_7 , V_158 , V_100 -> V_159 ) ;
F_11 ( V_7 , V_160 , V_100 -> V_161 ) ;
F_11 ( V_7 , V_60 , V_100 -> V_162 ) ;
F_11 ( V_7 , V_163 ,
V_100 -> V_164 ) ;
F_11 ( V_7 , V_101 , V_100 -> V_100 ) ;
F_11 ( V_7 , V_165 , V_100 -> V_166 ) ;
F_11 ( V_7 , V_131 , V_100 -> V_132 ) ;
F_11 ( V_7 , V_116 , V_100 -> V_117 ) ;
F_11 ( V_7 , V_167 , V_100 -> V_168 ) ;
F_11 ( V_7 , V_102 , V_100 -> V_103 ) ;
F_11 ( V_7 , V_104 , V_100 -> V_105 ) ;
F_11 ( V_7 , V_106 , V_100 -> V_107 ) ;
F_11 ( V_7 , V_169 , V_100 -> V_170 ) ;
F_11 ( V_7 , V_171 , V_100 -> V_172 ) ;
F_11 ( V_7 , V_55 , V_100 -> V_130 ) ;
F_11 ( V_7 , V_133 , V_100 -> V_134 ) ;
if ( V_2 -> V_44 == V_45 )
F_11 ( V_7 , V_173 ,
V_100 -> V_174 ) ;
F_11 ( V_7 , V_175 , V_100 -> V_176 ) ;
F_11 ( V_7 , V_149 , V_100 -> V_177 ) ;
F_11 ( V_7 , V_150 , V_100 -> V_178 ) ;
if ( V_2 -> V_44 == V_45 )
F_11 ( V_7 , V_46 , V_100 -> V_179 ) ;
else
F_11 ( V_7 , V_47 , V_100 -> V_179 ) ;
F_11 ( V_7 , V_180 , V_100 -> V_181 ) ;
F_11 ( V_7 , V_182 , V_100 -> V_183 ) ;
F_11 ( V_7 , V_184 , V_100 -> V_185 ) ;
F_11 ( V_7 , V_112 , V_100 -> V_113 ) ;
F_11 ( V_7 , V_114 , V_100 -> V_115 ) ;
if ( V_2 -> V_44 ) {
F_11 ( V_7 , V_118 ,
V_100 -> V_119 ) ;
F_11 ( V_7 , V_120 ,
V_100 -> V_121 ) ;
}
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
int V_4 ;
F_29 ( V_2 ) ;
F_31 ( 500 ) ;
F_24 ( V_2 ) ;
V_4 = F_19 ( V_2 ) ;
if ( V_4 ) {
F_17 ( & V_2 -> V_92 -> V_93 , L_5 ,
V_77 ) ;
return - V_76 ;
}
V_4 = F_23 ( V_2 ) ;
if ( V_4 ) {
F_17 ( & V_2 -> V_92 -> V_93 , L_6 ,
V_77 ) ;
return - V_76 ;
}
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_31 ( 350 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_32 ( V_7 , V_36 , V_186 , 0x0 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , T_4 V_187 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
T_1 V_188 , V_189 ;
F_2 ( V_7 , V_53 , & V_188 ) ;
V_188 >>= 8 ;
V_189 = ( V_188 + V_187 ) << 8 ;
V_189 |= ( V_188 - V_187 ) ;
F_7 ( V_7 , V_163 , V_189 ) ;
}
static T_5 F_34 ( int V_190 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
T_1 V_12 ;
F_2 ( V_2 -> V_6 , V_36 , & V_12 ) ;
if ( ( V_12 & V_191 ) ||
( V_12 & V_192 ) ) {
F_18 ( & V_2 -> V_92 -> V_93 , L_7 ) ;
F_33 ( V_2 , 1 ) ;
}
F_35 ( V_2 -> V_193 ) ;
return V_194 ;
}
static void F_36 ( struct V_195 * V_196 )
{
struct V_1 * V_2 = F_37 ( V_196 ,
struct V_1 , V_196 ) ;
int V_4 ;
if ( V_2 -> V_16 -> V_197 && V_2 -> V_16 -> V_87 ) {
V_4 = F_30 ( V_2 ) ;
if ( V_4 )
return;
}
V_2 -> V_33 = 1 ;
}
static struct V_198 *
F_38 ( struct V_199 * V_93 )
{
struct V_200 * V_201 = V_93 -> V_202 ;
T_1 V_203 ;
struct V_198 * V_16 ;
if ( ! V_201 )
return V_93 -> V_204 ;
V_16 = F_39 ( V_93 , sizeof( * V_16 ) , V_96 ) ;
if ( ! V_16 )
return NULL ;
if ( F_40 ( V_201 , L_8 , & V_203 ) == 0 ) {
V_16 -> V_68 = V_203 ;
V_16 -> V_66 = true ;
}
if ( F_41 ( V_201 , L_9 , & V_16 -> V_23 ) )
V_16 -> V_23 = V_205 ;
if ( F_41 ( V_201 , L_10 , & V_16 -> V_25 ) )
V_16 -> V_25 = V_206 ;
if ( F_41 ( V_201 , L_11 , & V_16 -> V_17 ) )
V_16 -> V_17 = V_205 ;
if ( F_41 ( V_201 , L_12 , & V_16 -> V_20 ) )
V_16 -> V_20 = V_206 ;
return V_16 ;
}
static struct V_198 *
F_38 ( struct V_199 * V_93 )
{
return V_93 -> V_204 ;
}
static int F_42 ( struct V_207 * V_92 ,
const struct V_208 * V_190 )
{
struct V_209 * V_210 = F_43 ( V_92 -> V_93 . V_211 ) ;
const struct V_212 * V_213 = & V_214 ;
struct V_215 V_216 = {} ;
struct V_1 * V_2 ;
int V_4 ;
int V_86 ;
T_1 V_12 ;
if ( ! F_44 ( V_210 , V_217 ) )
return - V_76 ;
V_2 = F_39 ( & V_92 -> V_93 , sizeof( * V_2 ) , V_96 ) ;
if ( ! V_2 )
return - V_97 ;
V_2 -> V_92 = V_92 ;
V_2 -> V_6 = F_45 ( V_92 , & V_218 ) ;
if ( F_46 ( V_2 -> V_6 ) ) {
F_17 ( & V_92 -> V_93 , L_13 ) ;
return - V_69 ;
}
V_2 -> V_16 = F_38 ( & V_92 -> V_93 ) ;
if ( ! V_2 -> V_16 ) {
F_17 ( & V_92 -> V_93 , L_14 ) ;
return - V_69 ;
}
F_47 ( V_92 , V_2 ) ;
V_2 -> V_44 = V_190 -> V_219 ;
V_216 . V_220 = V_2 ;
if ( ! V_2 -> V_16 -> V_66 )
V_213 = & V_221 ;
if ( V_2 -> V_16 -> V_68 == 0 )
V_2 -> V_16 -> V_68 = V_222 ;
if ( V_2 -> V_16 -> V_223 )
for ( V_86 = 0 ; V_86 < V_2 -> V_16 -> V_224 ; V_86 ++ )
F_7 ( V_2 -> V_6 ,
V_2 -> V_16 -> V_223 [ V_86 ] . V_84 ,
V_2 -> V_16 -> V_223 [ V_86 ] . V_5 ) ;
if ( ! V_2 -> V_16 -> V_66 ) {
F_7 ( V_2 -> V_6 , V_156 , 0x0000 ) ;
F_7 ( V_2 -> V_6 , V_169 , 0x0003 ) ;
F_7 ( V_2 -> V_6 , V_102 , 0x0007 ) ;
}
V_2 -> V_193 = F_48 ( & V_92 -> V_93 , V_213 ,
& V_216 ) ;
if ( F_46 ( V_2 -> V_193 ) ) {
F_17 ( & V_92 -> V_93 , L_15 ) ;
return F_49 ( V_2 -> V_193 ) ;
}
if ( V_92 -> V_225 ) {
V_4 = F_50 ( & V_92 -> V_93 , V_92 -> V_225 ,
NULL ,
F_34 ,
V_226 |
V_227 ,
V_2 -> V_193 -> V_228 -> V_229 ,
V_2 ) ;
if ( ! V_4 ) {
F_32 ( V_2 -> V_6 , V_101 ,
V_230 ,
V_230 ) ;
F_33 ( V_2 , 1 ) ;
} else {
V_92 -> V_225 = 0 ;
F_17 ( & V_92 -> V_93 , L_16 ,
V_77 ) ;
}
}
F_2 ( V_2 -> V_6 , V_36 , & V_12 ) ;
if ( V_12 & V_186 ) {
F_51 ( & V_2 -> V_196 , F_36 ) ;
F_52 ( & V_2 -> V_196 ) ;
} else {
V_2 -> V_33 = 1 ;
}
return 0 ;
}
static int F_53 ( struct V_199 * V_93 )
{
struct V_1 * V_2 = F_54 ( V_93 ) ;
if ( V_2 -> V_92 -> V_225 ) {
F_55 ( V_2 -> V_92 -> V_225 ) ;
F_56 ( V_2 -> V_92 -> V_225 ) ;
}
return 0 ;
}
static int F_57 ( struct V_199 * V_93 )
{
struct V_1 * V_2 = F_54 ( V_93 ) ;
if ( V_2 -> V_92 -> V_225 ) {
F_58 ( V_2 -> V_92 -> V_225 ) ;
F_59 ( V_2 -> V_92 -> V_225 ) ;
F_33 ( V_2 , 1 ) ;
}
return 0 ;
}
