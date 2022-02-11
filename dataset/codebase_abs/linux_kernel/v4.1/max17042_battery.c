static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_9 ;
int V_11 ;
T_1 V_12 ;
if ( ! V_8 -> V_13 )
return - V_14 ;
switch ( V_4 ) {
case V_15 :
V_11 = F_3 ( V_10 , V_16 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_12 & V_17 )
V_6 -> V_18 = 0 ;
else
V_6 -> V_18 = 1 ;
break;
case V_19 :
V_11 = F_3 ( V_10 , V_20 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_18 = V_12 ;
break;
case V_21 :
V_11 = F_3 ( V_10 , V_22 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_18 = V_12 >> 8 ;
V_6 -> V_18 *= 20000 ;
break;
case V_23 :
if ( V_8 -> V_24 == V_25 )
V_11 = F_3 ( V_10 , V_26 , & V_12 ) ;
else
V_11 = F_3 ( V_10 , V_27 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_18 = V_12 >> 7 ;
V_6 -> V_18 *= 10000 ;
break;
case V_28 :
V_11 = F_3 ( V_10 , V_29 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_18 = V_12 * 625 / 8 ;
break;
case V_30 :
V_11 = F_3 ( V_10 , V_31 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_18 = V_12 * 625 / 8 ;
break;
case V_32 :
V_11 = F_3 ( V_10 , V_33 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_18 = V_12 * 625 / 8 ;
break;
case V_34 :
V_11 = F_3 ( V_10 , V_35 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_18 = V_12 >> 8 ;
break;
case V_36 :
V_11 = F_3 ( V_10 , V_37 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_18 = V_12 * 1000 / 2 ;
break;
case V_38 :
V_11 = F_3 ( V_10 , V_39 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_18 = V_12 * 1000 / 2 ;
break;
case V_40 :
V_11 = F_3 ( V_10 , V_41 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_18 = V_12 ;
if ( V_6 -> V_18 & 0x8000 ) {
V_6 -> V_18 = ( 0x7fff & ~ V_6 -> V_18 ) + 1 ;
V_6 -> V_18 *= - 1 ;
}
V_6 -> V_18 = V_6 -> V_18 * 10 / 256 ;
break;
case V_42 :
if ( V_8 -> V_43 -> V_44 ) {
V_11 = F_3 ( V_10 , V_45 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_18 = V_12 ;
if ( V_6 -> V_18 & 0x8000 ) {
V_6 -> V_18 = ~ V_6 -> V_18 & 0x7fff ;
V_6 -> V_18 ++ ;
V_6 -> V_18 *= - 1 ;
}
V_6 -> V_18 *= 1562500 / V_8 -> V_43 -> V_46 ;
} else {
return - V_47 ;
}
break;
case V_48 :
if ( V_8 -> V_43 -> V_44 ) {
V_11 = F_3 ( V_10 , V_49 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 -> V_18 = V_12 ;
if ( V_6 -> V_18 & 0x8000 ) {
V_6 -> V_18 = ~ V_6 -> V_18 & 0x7fff ;
V_6 -> V_18 ++ ;
V_6 -> V_18 *= - 1 ;
}
V_6 -> V_18 *= 1562500 / V_8 -> V_43 -> V_46 ;
} else {
return - V_47 ;
}
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_4 ( struct V_9 * V_10 , T_2 V_50 , T_1 V_51 )
{
int V_52 = 8 ;
int V_11 ;
T_1 V_53 ;
do {
V_11 = F_5 ( V_10 , V_50 , V_51 ) ;
F_3 ( V_10 , V_50 , & V_53 ) ;
if ( V_53 != V_51 ) {
V_11 = - V_54 ;
V_52 -- ;
}
} while ( V_52 && V_53 != V_51 );
if ( V_11 < 0 )
F_6 ( L_1 , V_55 , V_11 ) ;
return V_11 ;
}
static inline void F_7 ( struct V_9 * V_10 ,
T_2 V_50 , T_3 V_51 )
{
if ( V_51 )
F_5 ( V_10 , V_50 , V_51 ) ;
}
static inline void F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
F_5 ( V_10 , V_56 , V_57 ) ;
F_5 ( V_10 , V_58 , V_59 ) ;
}
static inline void F_9 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
F_5 ( V_10 , V_56 , V_60 ) ;
F_5 ( V_10 , V_58 , V_61 ) ;
}
static inline void F_10 ( struct V_7 * V_8 ,
T_2 V_62 , int V_63 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ )
F_5 ( V_10 , V_62 + V_64 ,
V_8 -> V_43 -> V_65 -> V_66 [ V_64 ] ) ;
}
static inline void F_11 ( struct V_7 * V_8 ,
T_2 V_62 , T_1 * V_12 , int V_63 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ )
F_3 ( V_10 , V_62 + V_64 , & V_12 [ V_64 ] ) ;
}
static inline int F_12 ( struct V_7 * V_8 ,
T_3 * V_67 , T_3 * V_68 , int V_63 )
{
int V_64 ;
if ( memcmp ( V_67 , V_68 , V_63 ) ) {
F_13 ( & V_8 -> V_69 -> V_70 , L_2 , V_55 ) ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ )
F_14 ( & V_8 -> V_69 -> V_70 , L_3 ,
V_67 [ V_64 ] , V_68 [ V_64 ] ) ;
F_14 ( & V_8 -> V_69 -> V_70 , L_4 ) ;
return - V_47 ;
}
return 0 ;
}
static int F_15 ( struct V_7 * V_8 )
{
int V_11 ;
int V_71 = F_16 ( V_8 -> V_43 -> V_65 -> V_66 ) ;
T_1 * V_72 ;
V_72 = F_17 ( V_71 , sizeof( * V_72 ) , V_73 ) ;
if ( ! V_72 )
return - V_74 ;
F_8 ( V_8 ) ;
F_10 ( V_8 , V_75 ,
V_71 ) ;
F_11 ( V_8 , V_75 , V_72 ,
V_71 ) ;
V_11 = F_12 (
V_8 ,
V_8 -> V_43 -> V_65 -> V_66 ,
( T_3 * ) V_72 ,
V_71 ) ;
F_9 ( V_8 ) ;
F_18 ( V_72 ) ;
return V_11 ;
}
static int F_19 ( struct V_7 * V_8 )
{
int V_64 ;
int V_71 = F_16 ( V_8 -> V_43 -> V_65 -> V_66 ) ;
T_1 * V_72 ;
int V_11 = 0 ;
V_72 = F_17 ( V_71 , sizeof( * V_72 ) , V_73 ) ;
if ( ! V_72 )
return - V_74 ;
F_11 ( V_8 , V_75 , V_72 ,
V_71 ) ;
for ( V_64 = 0 ; V_64 < V_71 ; V_64 ++ )
if ( V_72 [ V_64 ] )
V_11 = - V_47 ;
F_18 ( V_72 ) ;
return V_11 ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_76 * V_77 = V_8 -> V_43 -> V_65 ;
struct V_9 * V_10 = V_8 -> V_9 ;
F_5 ( V_10 , V_78 , V_77 -> V_77 ) ;
F_5 ( V_10 , V_79 , V_77 -> V_80 ) ;
F_5 ( V_10 , V_81 ,
V_77 -> V_82 ) ;
F_5 ( V_10 , V_83 , V_77 -> V_84 ) ;
if ( V_8 -> V_24 == V_85 ||
V_8 -> V_24 == V_86 )
F_5 ( V_10 , V_87 ,
V_77 -> V_88 ) ;
}
static void F_21 ( struct V_7 * V_8 )
{
struct V_76 * V_77 = V_8 -> V_43 -> V_65 ;
struct V_9 * V_10 = V_8 -> V_9 ;
F_4 ( V_10 , V_89 , V_77 -> V_90 ) ;
F_4 ( V_10 , V_91 , V_77 -> V_92 ) ;
F_4 ( V_10 , V_93 , V_77 -> V_94 ) ;
if ( V_8 -> V_24 == V_25 ) {
F_5 ( V_10 , V_95 , V_77 -> V_96 ) ;
F_4 ( V_10 , V_97 ,
V_77 -> V_98 ) ;
} else {
F_4 ( V_10 , V_99 ,
V_77 -> V_100 ) ;
F_4 ( V_10 , V_101 ,
V_77 -> V_102 ) ;
F_4 ( V_10 , V_103 ,
V_77 -> V_104 ) ;
F_4 ( V_10 , V_105 ,
V_77 -> V_106 ) ;
}
}
static void F_22 ( struct V_7 * V_8 )
{
struct V_76 * V_77 = V_8 -> V_43 -> V_65 ;
struct V_9 * V_10 = V_8 -> V_9 ;
F_4 ( V_10 , V_37 ,
V_77 -> V_107 ) ;
F_5 ( V_10 , V_108 , V_77 -> V_109 ) ;
F_4 ( V_10 , V_110 ,
V_77 -> V_111 ) ;
}
static void F_23 ( struct V_7 * V_8 )
{
unsigned int V_112 ;
struct V_9 * V_10 = V_8 -> V_9 ;
F_3 ( V_10 , V_113 , & V_112 ) ;
F_5 ( V_10 , V_114 , V_115 ) ;
F_4 ( V_10 , V_116 , V_112 ) ;
F_5 ( V_10 , V_114 , V_117 ) ;
}
static void F_24 ( struct V_7 * V_8 )
{
T_1 V_118 , V_119 , V_120 , V_112 ;
T_1 V_121 ;
struct V_76 * V_77 = V_8 -> V_43 -> V_65 ;
struct V_9 * V_10 = V_8 -> V_9 ;
F_3 ( V_10 , V_122 , & V_118 ) ;
F_3 ( V_10 , V_113 , & V_112 ) ;
V_121 = ( ( V_112 >> 8 ) * V_118 ) / 100 ;
F_4 ( V_10 , V_123 , V_121 ) ;
V_119 = V_121 ;
F_4 ( V_10 , V_124 , V_119 ) ;
V_120 = V_77 -> V_107 / V_125 ;
F_4 ( V_10 , V_126 , V_120 ) ;
F_4 ( V_10 , V_127 , V_128 ) ;
F_4 ( V_10 , V_37 ,
V_77 -> V_107 ) ;
F_5 ( V_10 , V_108 ,
V_77 -> V_109 ) ;
F_4 ( V_10 , V_110 ,
V_77 -> V_111 ) ;
F_5 ( V_10 , V_35 , V_112 ) ;
}
static inline void F_25 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
struct V_76 * V_77 = V_8 -> V_43 -> V_65 ;
F_7 ( V_10 , V_129 , V_77 -> V_130 ) ;
F_7 ( V_10 , V_131 , V_77 -> V_132 ) ;
F_7 ( V_10 , V_133 , V_77 -> V_134 ) ;
F_7 ( V_10 , V_135 , V_77 -> V_136 ) ;
F_7 ( V_10 , V_137 , V_77 -> V_138 ) ;
F_7 ( V_10 , V_139 , V_77 -> V_140 ) ;
F_7 ( V_10 , V_141 ,
V_77 -> V_142 ) ;
F_7 ( V_10 , V_78 , V_77 -> V_77 ) ;
F_7 ( V_10 , V_143 , V_77 -> V_144 ) ;
F_7 ( V_10 , V_108 , V_77 -> V_109 ) ;
F_7 ( V_10 , V_93 , V_77 -> V_94 ) ;
F_7 ( V_10 , V_145 , V_77 -> V_146 ) ;
F_7 ( V_10 , V_79 , V_77 -> V_80 ) ;
F_7 ( V_10 , V_81 , V_77 -> V_82 ) ;
F_7 ( V_10 , V_83 , V_77 -> V_84 ) ;
F_7 ( V_10 , V_147 , V_77 -> V_148 ) ;
F_7 ( V_10 , V_149 , V_77 -> V_150 ) ;
F_7 ( V_10 , V_37 , V_77 -> V_107 ) ;
F_7 ( V_10 , V_110 , V_77 -> V_111 ) ;
if ( V_8 -> V_24 == V_25 )
F_7 ( V_10 , V_151 ,
V_77 -> V_152 ) ;
F_7 ( V_10 , V_153 , V_77 -> V_154 ) ;
F_7 ( V_10 , V_126 , V_77 -> V_155 ) ;
F_7 ( V_10 , V_127 , V_77 -> V_156 ) ;
if ( V_8 -> V_24 == V_25 )
F_7 ( V_10 , V_26 , V_77 -> V_157 ) ;
else
F_7 ( V_10 , V_27 , V_77 -> V_157 ) ;
F_7 ( V_10 , V_158 , V_77 -> V_159 ) ;
F_7 ( V_10 , V_160 , V_77 -> V_161 ) ;
F_7 ( V_10 , V_162 , V_77 -> V_163 ) ;
F_7 ( V_10 , V_89 , V_77 -> V_90 ) ;
F_7 ( V_10 , V_91 , V_77 -> V_92 ) ;
if ( V_8 -> V_24 ) {
F_7 ( V_10 , V_95 ,
V_77 -> V_96 ) ;
F_7 ( V_10 , V_97 ,
V_77 -> V_98 ) ;
}
}
static int F_26 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
int V_11 ;
F_25 ( V_8 ) ;
F_27 ( 500 ) ;
F_20 ( V_8 ) ;
V_11 = F_15 ( V_8 ) ;
if ( V_11 ) {
F_13 ( & V_8 -> V_69 -> V_70 , L_5 ,
V_55 ) ;
return - V_54 ;
}
V_11 = F_19 ( V_8 ) ;
if ( V_11 ) {
F_13 ( & V_8 -> V_69 -> V_70 , L_6 ,
V_55 ) ;
return - V_54 ;
}
F_21 ( V_8 ) ;
F_22 ( V_8 ) ;
F_27 ( 350 ) ;
F_23 ( V_8 ) ;
F_24 ( V_8 ) ;
F_28 ( V_10 , V_16 , V_164 , 0x0 ) ;
return 0 ;
}
static void F_29 ( struct V_7 * V_8 , T_3 V_165 )
{
struct V_9 * V_10 = V_8 -> V_9 ;
T_1 V_166 , V_167 ;
F_3 ( V_10 , V_35 , & V_166 ) ;
V_166 >>= 8 ;
V_167 = ( V_166 + V_165 ) << 8 ;
V_167 |= ( V_166 - V_165 ) ;
F_5 ( V_10 , V_141 , V_167 ) ;
}
static T_4 F_30 ( int V_168 , void * V_70 )
{
struct V_7 * V_8 = V_70 ;
T_1 V_6 ;
F_3 ( V_8 -> V_9 , V_16 , & V_6 ) ;
if ( ( V_6 & V_169 ) ||
( V_6 & V_170 ) ) {
F_14 ( & V_8 -> V_69 -> V_70 , L_7 ) ;
F_29 ( V_8 , 1 ) ;
}
F_31 ( V_8 -> V_171 ) ;
return V_172 ;
}
static void F_32 ( struct V_173 * V_174 )
{
struct V_7 * V_8 = F_33 ( V_174 ,
struct V_7 , V_174 ) ;
int V_11 ;
if ( V_8 -> V_43 -> V_175 && V_8 -> V_43 -> V_65 ) {
V_11 = F_26 ( V_8 ) ;
if ( V_11 )
return;
}
V_8 -> V_13 = 1 ;
}
static struct V_176 *
F_34 ( struct V_177 * V_70 )
{
struct V_178 * V_179 = V_70 -> V_180 ;
T_1 V_181 ;
struct V_176 * V_43 ;
if ( ! V_179 )
return V_70 -> V_182 ;
V_43 = F_35 ( V_70 , sizeof( * V_43 ) , V_73 ) ;
if ( ! V_43 )
return NULL ;
if ( F_36 ( V_179 , L_8 , & V_181 ) == 0 ) {
V_43 -> V_46 = V_181 ;
V_43 -> V_44 = true ;
}
return V_43 ;
}
static struct V_176 *
F_34 ( struct V_177 * V_70 )
{
return V_70 -> V_182 ;
}
static int F_37 ( struct V_183 * V_69 ,
const struct V_184 * V_168 )
{
struct V_185 * V_186 = F_38 ( V_69 -> V_70 . V_187 ) ;
const struct V_188 * V_189 = & V_190 ;
struct V_191 V_192 = {} ;
struct V_7 * V_8 ;
int V_11 ;
int V_64 ;
T_1 V_6 ;
if ( ! F_39 ( V_186 , V_193 ) )
return - V_54 ;
V_8 = F_35 ( & V_69 -> V_70 , sizeof( * V_8 ) , V_73 ) ;
if ( ! V_8 )
return - V_74 ;
V_8 -> V_69 = V_69 ;
V_8 -> V_9 = F_40 ( V_69 , & V_194 ) ;
if ( F_41 ( V_8 -> V_9 ) ) {
F_13 ( & V_69 -> V_70 , L_9 ) ;
return - V_47 ;
}
V_8 -> V_43 = F_34 ( & V_69 -> V_70 ) ;
if ( ! V_8 -> V_43 ) {
F_13 ( & V_69 -> V_70 , L_10 ) ;
return - V_47 ;
}
F_42 ( V_69 , V_8 ) ;
V_8 -> V_24 = V_168 -> V_195 ;
V_192 . V_196 = V_8 ;
if ( ! V_8 -> V_43 -> V_44 )
V_189 = & V_197 ;
if ( V_8 -> V_43 -> V_46 == 0 )
V_8 -> V_43 -> V_46 = V_198 ;
if ( V_8 -> V_43 -> V_199 )
for ( V_64 = 0 ; V_64 < V_8 -> V_43 -> V_200 ; V_64 ++ )
F_5 ( V_8 -> V_9 ,
V_8 -> V_43 -> V_199 [ V_64 ] . V_62 ,
V_8 -> V_43 -> V_199 [ V_64 ] . V_12 ) ;
if ( ! V_8 -> V_43 -> V_44 ) {
F_5 ( V_8 -> V_9 , V_133 , 0x0000 ) ;
F_5 ( V_8 -> V_9 , V_147 , 0x0003 ) ;
F_5 ( V_8 -> V_9 , V_79 , 0x0007 ) ;
}
V_8 -> V_171 = F_43 ( & V_69 -> V_70 , V_189 ,
& V_192 ) ;
if ( F_41 ( V_8 -> V_171 ) ) {
F_13 ( & V_69 -> V_70 , L_11 ) ;
return F_44 ( V_8 -> V_171 ) ;
}
if ( V_69 -> V_201 ) {
V_11 = F_45 ( V_69 -> V_201 , NULL ,
F_30 ,
V_202 | V_203 ,
V_8 -> V_171 -> V_204 -> V_205 , V_8 ) ;
if ( ! V_11 ) {
F_28 ( V_8 -> V_9 , V_78 ,
V_206 ,
V_206 ) ;
F_29 ( V_8 , 1 ) ;
} else {
V_69 -> V_201 = 0 ;
F_13 ( & V_69 -> V_70 , L_12 ,
V_55 ) ;
}
}
F_3 ( V_8 -> V_9 , V_16 , & V_6 ) ;
if ( V_6 & V_164 ) {
F_46 ( & V_8 -> V_174 , F_32 ) ;
F_47 ( & V_8 -> V_174 ) ;
} else {
V_8 -> V_13 = 1 ;
}
return 0 ;
}
static int F_48 ( struct V_183 * V_69 )
{
struct V_7 * V_8 = F_49 ( V_69 ) ;
if ( V_69 -> V_201 )
F_50 ( V_69 -> V_201 , V_8 ) ;
F_51 ( V_8 -> V_171 ) ;
return 0 ;
}
static int F_52 ( struct V_177 * V_70 )
{
struct V_7 * V_8 = F_53 ( V_70 ) ;
if ( V_8 -> V_69 -> V_201 ) {
F_54 ( V_8 -> V_69 -> V_201 ) ;
F_55 ( V_8 -> V_69 -> V_201 ) ;
}
return 0 ;
}
static int F_56 ( struct V_177 * V_70 )
{
struct V_7 * V_8 = F_53 ( V_70 ) ;
if ( V_8 -> V_69 -> V_201 ) {
F_57 ( V_8 -> V_69 -> V_201 ) ;
F_58 ( V_8 -> V_69 -> V_201 ) ;
F_29 ( V_8 , 1 ) ;
}
return 0 ;
}
