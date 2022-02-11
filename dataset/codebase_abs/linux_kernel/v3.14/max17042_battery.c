static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_9 ) ;
struct V_10 * V_11 = V_8 -> V_10 ;
int V_12 ;
T_1 V_13 ;
if ( ! V_8 -> V_14 )
return - V_15 ;
switch ( V_4 ) {
case V_16 :
V_12 = F_3 ( V_11 , V_17 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_13 & V_18 )
V_6 -> V_19 = 0 ;
else
V_6 -> V_19 = 1 ;
break;
case V_20 :
V_12 = F_3 ( V_11 , V_21 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 -> V_19 = V_13 ;
break;
case V_22 :
V_12 = F_3 ( V_11 , V_23 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 -> V_19 = V_13 >> 8 ;
V_6 -> V_19 *= 20000 ;
break;
case V_24 :
if ( V_8 -> V_25 == V_26 )
V_12 = F_3 ( V_11 , V_27 , & V_13 ) ;
else
V_12 = F_3 ( V_11 , V_28 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 -> V_19 = V_13 >> 7 ;
V_6 -> V_19 *= 10000 ;
break;
case V_29 :
V_12 = F_3 ( V_11 , V_30 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 -> V_19 = V_13 * 625 / 8 ;
break;
case V_31 :
V_12 = F_3 ( V_11 , V_32 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 -> V_19 = V_13 * 625 / 8 ;
break;
case V_33 :
V_12 = F_3 ( V_11 , V_34 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 -> V_19 = V_13 * 625 / 8 ;
break;
case V_35 :
V_12 = F_3 ( V_11 , V_36 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 -> V_19 = V_13 >> 8 ;
break;
case V_37 :
V_12 = F_3 ( V_11 , V_38 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 -> V_19 = V_13 * 1000 / 2 ;
break;
case V_39 :
V_12 = F_3 ( V_11 , V_40 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 -> V_19 = V_13 * 1000 / 2 ;
break;
case V_41 :
V_12 = F_3 ( V_11 , V_42 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 -> V_19 = V_13 ;
if ( V_6 -> V_19 & 0x8000 ) {
V_6 -> V_19 = ( 0x7fff & ~ V_6 -> V_19 ) + 1 ;
V_6 -> V_19 *= - 1 ;
}
V_6 -> V_19 = V_6 -> V_19 * 10 / 256 ;
break;
case V_43 :
if ( V_8 -> V_44 -> V_45 ) {
V_12 = F_3 ( V_11 , V_46 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 -> V_19 = V_13 ;
if ( V_6 -> V_19 & 0x8000 ) {
V_6 -> V_19 = ~ V_6 -> V_19 & 0x7fff ;
V_6 -> V_19 ++ ;
V_6 -> V_19 *= - 1 ;
}
V_6 -> V_19 *= 1562500 / V_8 -> V_44 -> V_47 ;
} else {
return - V_48 ;
}
break;
case V_49 :
if ( V_8 -> V_44 -> V_45 ) {
V_12 = F_3 ( V_11 , V_50 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 -> V_19 = V_13 ;
if ( V_6 -> V_19 & 0x8000 ) {
V_6 -> V_19 = ~ V_6 -> V_19 & 0x7fff ;
V_6 -> V_19 ++ ;
V_6 -> V_19 *= - 1 ;
}
V_6 -> V_19 *= 1562500 / V_8 -> V_44 -> V_47 ;
} else {
return - V_48 ;
}
break;
default:
return - V_48 ;
}
return 0 ;
}
static int F_4 ( struct V_10 * V_11 , T_2 V_51 , T_1 V_52 )
{
int V_53 = 8 ;
int V_12 ;
T_1 V_54 ;
do {
V_12 = F_5 ( V_11 , V_51 , V_52 ) ;
F_3 ( V_11 , V_51 , & V_54 ) ;
if ( V_54 != V_52 ) {
V_12 = - V_55 ;
V_53 -- ;
}
} while ( V_53 && V_54 != V_52 );
if ( V_12 < 0 )
F_6 ( L_1 , V_56 , V_12 ) ;
return V_12 ;
}
static inline void F_7 ( struct V_10 * V_11 ,
T_2 V_51 , T_3 V_52 )
{
if ( V_52 )
F_5 ( V_11 , V_51 , V_52 ) ;
}
static inline void F_8 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_10 ;
F_5 ( V_11 , V_57 , V_58 ) ;
F_5 ( V_11 , V_59 , V_60 ) ;
}
static inline void F_9 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_10 ;
F_5 ( V_11 , V_57 , V_61 ) ;
F_5 ( V_11 , V_59 , V_62 ) ;
}
static inline void F_10 ( struct V_7 * V_8 ,
T_2 V_63 , int V_64 )
{
struct V_10 * V_11 = V_8 -> V_10 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ )
F_5 ( V_11 , V_63 + V_65 ,
V_8 -> V_44 -> V_66 -> V_67 [ V_65 ] ) ;
}
static inline void F_11 ( struct V_7 * V_8 ,
T_2 V_63 , T_1 * V_13 , int V_64 )
{
struct V_10 * V_11 = V_8 -> V_10 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ )
F_3 ( V_11 , V_63 + V_65 , & V_13 [ V_65 ] ) ;
}
static inline int F_12 ( struct V_7 * V_8 ,
T_3 * V_68 , T_3 * V_69 , int V_64 )
{
int V_65 ;
if ( memcmp ( V_68 , V_69 , V_64 ) ) {
F_13 ( & V_8 -> V_70 -> V_71 , L_2 , V_56 ) ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ )
F_14 ( & V_8 -> V_70 -> V_71 , L_3 ,
V_68 [ V_65 ] , V_69 [ V_65 ] ) ;
F_14 ( & V_8 -> V_70 -> V_71 , L_4 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_15 ( struct V_7 * V_8 )
{
int V_12 ;
int V_72 = F_16 ( V_8 -> V_44 -> V_66 -> V_67 ) ;
T_1 * V_73 ;
V_73 = F_17 ( V_72 , sizeof( * V_73 ) , V_74 ) ;
if ( ! V_73 )
return - V_75 ;
F_8 ( V_8 ) ;
F_10 ( V_8 , V_76 ,
V_72 ) ;
F_11 ( V_8 , V_76 , V_73 ,
V_72 ) ;
V_12 = F_12 (
V_8 ,
V_8 -> V_44 -> V_66 -> V_67 ,
( T_3 * ) V_73 ,
V_72 ) ;
F_9 ( V_8 ) ;
F_18 ( V_73 ) ;
return V_12 ;
}
static int F_19 ( struct V_7 * V_8 )
{
int V_65 ;
int V_72 = F_16 ( V_8 -> V_44 -> V_66 -> V_67 ) ;
T_1 * V_73 ;
int V_12 = 0 ;
V_73 = F_17 ( V_72 , sizeof( * V_73 ) , V_74 ) ;
if ( ! V_73 )
return - V_75 ;
F_11 ( V_8 , V_76 , V_73 ,
V_72 ) ;
for ( V_65 = 0 ; V_65 < V_72 ; V_65 ++ )
if ( V_73 [ V_65 ] )
V_12 = - V_48 ;
F_18 ( V_73 ) ;
return V_12 ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_77 * V_78 = V_8 -> V_44 -> V_66 ;
struct V_10 * V_11 = V_8 -> V_10 ;
F_5 ( V_11 , V_79 , V_78 -> V_78 ) ;
F_5 ( V_11 , V_80 , V_78 -> V_81 ) ;
F_5 ( V_11 , V_82 ,
V_78 -> V_83 ) ;
F_5 ( V_11 , V_84 , V_78 -> V_85 ) ;
if ( V_8 -> V_25 == V_86 )
F_5 ( V_11 , V_87 ,
V_78 -> V_88 ) ;
}
static void F_21 ( struct V_7 * V_8 )
{
struct V_77 * V_78 = V_8 -> V_44 -> V_66 ;
struct V_10 * V_11 = V_8 -> V_10 ;
F_4 ( V_11 , V_89 , V_78 -> V_90 ) ;
F_4 ( V_11 , V_91 , V_78 -> V_92 ) ;
F_4 ( V_11 , V_93 , V_78 -> V_94 ) ;
if ( V_8 -> V_25 == V_26 ) {
F_5 ( V_11 , V_95 , V_78 -> V_96 ) ;
F_4 ( V_11 , V_97 ,
V_78 -> V_98 ) ;
} else {
F_4 ( V_11 , V_99 ,
V_78 -> V_100 ) ;
F_4 ( V_11 , V_101 ,
V_78 -> V_102 ) ;
F_4 ( V_11 , V_103 ,
V_78 -> V_104 ) ;
F_4 ( V_11 , V_105 ,
V_78 -> V_106 ) ;
}
}
static void F_22 ( struct V_7 * V_8 )
{
struct V_77 * V_78 = V_8 -> V_44 -> V_66 ;
struct V_10 * V_11 = V_8 -> V_10 ;
F_4 ( V_11 , V_38 ,
V_78 -> V_107 ) ;
F_5 ( V_11 , V_108 , V_78 -> V_109 ) ;
F_4 ( V_11 , V_110 ,
V_78 -> V_111 ) ;
}
static void F_23 ( struct V_7 * V_8 )
{
unsigned int V_112 ;
struct V_10 * V_11 = V_8 -> V_10 ;
F_3 ( V_11 , V_113 , & V_112 ) ;
F_5 ( V_11 , V_114 , V_115 ) ;
F_4 ( V_11 , V_116 , V_112 ) ;
F_5 ( V_11 , V_114 , V_117 ) ;
}
static void F_24 ( struct V_7 * V_8 )
{
T_1 V_118 , V_119 , V_120 , V_112 ;
T_1 V_121 ;
struct V_77 * V_78 = V_8 -> V_44 -> V_66 ;
struct V_10 * V_11 = V_8 -> V_10 ;
F_3 ( V_11 , V_122 , & V_118 ) ;
F_3 ( V_11 , V_113 , & V_112 ) ;
V_121 = ( ( V_112 >> 8 ) * V_118 ) / 100 ;
F_4 ( V_11 , V_123 , V_121 ) ;
V_119 = V_121 ;
F_4 ( V_11 , V_124 , V_119 ) ;
V_120 = V_78 -> V_107 / V_125 ;
F_4 ( V_11 , V_126 , V_120 ) ;
F_4 ( V_11 , V_127 , V_128 ) ;
F_4 ( V_11 , V_38 ,
V_78 -> V_107 ) ;
F_5 ( V_11 , V_108 ,
V_78 -> V_109 ) ;
F_4 ( V_11 , V_110 ,
V_78 -> V_111 ) ;
F_5 ( V_11 , V_36 , V_112 ) ;
}
static inline void F_25 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_10 ;
struct V_77 * V_78 = V_8 -> V_44 -> V_66 ;
F_7 ( V_11 , V_129 , V_78 -> V_130 ) ;
F_7 ( V_11 , V_131 , V_78 -> V_132 ) ;
F_7 ( V_11 , V_133 , V_78 -> V_134 ) ;
F_7 ( V_11 , V_135 , V_78 -> V_136 ) ;
F_7 ( V_11 , V_137 , V_78 -> V_138 ) ;
F_7 ( V_11 , V_139 , V_78 -> V_140 ) ;
F_7 ( V_11 , V_141 ,
V_78 -> V_142 ) ;
F_7 ( V_11 , V_79 , V_78 -> V_78 ) ;
F_7 ( V_11 , V_143 , V_78 -> V_144 ) ;
F_7 ( V_11 , V_108 , V_78 -> V_109 ) ;
F_7 ( V_11 , V_93 , V_78 -> V_94 ) ;
F_7 ( V_11 , V_145 , V_78 -> V_146 ) ;
F_7 ( V_11 , V_80 , V_78 -> V_81 ) ;
F_7 ( V_11 , V_82 , V_78 -> V_83 ) ;
F_7 ( V_11 , V_84 , V_78 -> V_85 ) ;
F_7 ( V_11 , V_147 , V_78 -> V_148 ) ;
F_7 ( V_11 , V_149 , V_78 -> V_150 ) ;
F_7 ( V_11 , V_38 , V_78 -> V_107 ) ;
F_7 ( V_11 , V_110 , V_78 -> V_111 ) ;
if ( V_8 -> V_25 == V_26 )
F_7 ( V_11 , V_151 ,
V_78 -> V_152 ) ;
F_7 ( V_11 , V_153 , V_78 -> V_154 ) ;
F_7 ( V_11 , V_126 , V_78 -> V_155 ) ;
F_7 ( V_11 , V_127 , V_78 -> V_156 ) ;
if ( V_8 -> V_25 == V_26 )
F_7 ( V_11 , V_27 , V_78 -> V_157 ) ;
else
F_7 ( V_11 , V_28 , V_78 -> V_157 ) ;
F_7 ( V_11 , V_158 , V_78 -> V_159 ) ;
F_7 ( V_11 , V_160 , V_78 -> V_161 ) ;
F_7 ( V_11 , V_162 , V_78 -> V_163 ) ;
F_7 ( V_11 , V_89 , V_78 -> V_90 ) ;
F_7 ( V_11 , V_91 , V_78 -> V_92 ) ;
if ( V_8 -> V_25 ) {
F_7 ( V_11 , V_95 ,
V_78 -> V_96 ) ;
F_7 ( V_11 , V_97 ,
V_78 -> V_98 ) ;
}
}
static int F_26 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_10 ;
int V_12 ;
int V_6 ;
F_25 ( V_8 ) ;
F_27 ( 500 ) ;
F_20 ( V_8 ) ;
V_12 = F_15 ( V_8 ) ;
if ( V_12 ) {
F_13 ( & V_8 -> V_70 -> V_71 , L_5 ,
V_56 ) ;
return - V_55 ;
}
V_12 = F_19 ( V_8 ) ;
if ( V_12 ) {
F_13 ( & V_8 -> V_70 -> V_71 , L_6 ,
V_56 ) ;
return - V_55 ;
}
F_21 ( V_8 ) ;
F_22 ( V_8 ) ;
F_27 ( 350 ) ;
F_23 ( V_8 ) ;
F_24 ( V_8 ) ;
F_3 ( V_11 , V_17 , & V_6 ) ;
F_5 ( V_11 , V_17 , V_6 & ( ~ V_164 ) ) ;
return 0 ;
}
static void F_28 ( struct V_7 * V_8 , T_3 V_165 )
{
struct V_10 * V_11 = V_8 -> V_10 ;
T_1 V_166 , V_167 ;
F_3 ( V_11 , V_36 , & V_166 ) ;
V_166 >>= 8 ;
V_167 = ( V_166 + V_165 ) << 8 ;
V_167 |= ( V_166 - V_165 ) ;
F_5 ( V_11 , V_141 , V_167 ) ;
}
static T_4 F_29 ( int V_168 , void * V_71 )
{
struct V_7 * V_8 = V_71 ;
T_1 V_6 ;
F_3 ( V_8 -> V_10 , V_17 , & V_6 ) ;
if ( ( V_6 & V_169 ) ||
( V_6 & V_170 ) ) {
F_14 ( & V_8 -> V_70 -> V_71 , L_7 ) ;
F_28 ( V_8 , 1 ) ;
}
F_30 ( & V_8 -> V_9 ) ;
return V_171 ;
}
static void F_31 ( struct V_172 * V_173 )
{
struct V_7 * V_8 = F_2 ( V_173 ,
struct V_7 , V_173 ) ;
int V_12 ;
if ( V_8 -> V_44 -> V_174 && V_8 -> V_44 -> V_66 ) {
V_12 = F_26 ( V_8 ) ;
if ( V_12 )
return;
}
V_8 -> V_14 = 1 ;
}
static struct V_175 *
F_32 ( struct V_176 * V_71 )
{
struct V_177 * V_178 = V_71 -> V_179 ;
T_1 V_180 ;
struct V_175 * V_44 ;
if ( ! V_178 )
return V_71 -> V_181 ;
V_44 = F_33 ( V_71 , sizeof( * V_44 ) , V_74 ) ;
if ( ! V_44 )
return NULL ;
if ( F_34 ( V_178 , L_8 , & V_180 ) == 0 ) {
V_44 -> V_47 = V_180 ;
V_44 -> V_45 = true ;
}
return V_44 ;
}
static struct V_175 *
F_32 ( struct V_176 * V_71 )
{
return V_71 -> V_181 ;
}
static int F_35 ( struct V_182 * V_70 ,
const struct V_183 * V_168 )
{
struct V_184 * V_185 = F_36 ( V_70 -> V_71 . V_186 ) ;
struct V_7 * V_8 ;
int V_12 ;
int V_65 ;
T_1 V_6 ;
if ( ! F_37 ( V_185 , V_187 ) )
return - V_55 ;
V_8 = F_33 ( & V_70 -> V_71 , sizeof( * V_8 ) , V_74 ) ;
if ( ! V_8 )
return - V_75 ;
V_8 -> V_70 = V_70 ;
V_8 -> V_10 = F_38 ( V_70 , & V_188 ) ;
if ( F_39 ( V_8 -> V_10 ) ) {
F_13 ( & V_70 -> V_71 , L_9 ) ;
return - V_48 ;
}
V_8 -> V_44 = F_32 ( & V_70 -> V_71 ) ;
if ( ! V_8 -> V_44 ) {
F_13 ( & V_70 -> V_71 , L_10 ) ;
return - V_48 ;
}
F_40 ( V_70 , V_8 ) ;
F_3 ( V_8 -> V_10 , V_189 , & V_6 ) ;
if ( V_6 == V_190 ) {
F_41 ( & V_70 -> V_71 , L_11 ) ;
V_8 -> V_25 = V_26 ;
} else if ( V_6 == V_191 ) {
F_41 ( & V_70 -> V_71 , L_12 ) ;
V_8 -> V_25 = V_86 ;
} else {
F_13 ( & V_70 -> V_71 , L_13 , V_6 ) ;
return - V_55 ;
}
V_8 -> V_9 . V_192 = L_14 ;
V_8 -> V_9 . type = V_193 ;
V_8 -> V_9 . V_194 = F_1 ;
V_8 -> V_9 . V_195 = V_196 ;
V_8 -> V_9 . V_197 = F_16 ( V_196 ) ;
if ( ! V_8 -> V_44 -> V_45 )
V_8 -> V_9 . V_197 -= 2 ;
if ( V_8 -> V_44 -> V_47 == 0 )
V_8 -> V_44 -> V_47 = V_198 ;
if ( V_8 -> V_44 -> V_199 )
for ( V_65 = 0 ; V_65 < V_8 -> V_44 -> V_200 ; V_65 ++ )
F_5 ( V_8 -> V_10 ,
V_8 -> V_44 -> V_199 [ V_65 ] . V_63 ,
V_8 -> V_44 -> V_199 [ V_65 ] . V_13 ) ;
if ( ! V_8 -> V_44 -> V_45 ) {
F_5 ( V_8 -> V_10 , V_133 , 0x0000 ) ;
F_5 ( V_8 -> V_10 , V_147 , 0x0003 ) ;
F_5 ( V_8 -> V_10 , V_80 , 0x0007 ) ;
}
V_12 = F_42 ( & V_70 -> V_71 , & V_8 -> V_9 ) ;
if ( V_12 ) {
F_13 ( & V_70 -> V_71 , L_15 ) ;
return V_12 ;
}
if ( V_70 -> V_201 ) {
V_12 = F_43 ( V_70 -> V_201 , NULL ,
F_29 ,
V_202 | V_203 ,
V_8 -> V_9 . V_192 , V_8 ) ;
if ( ! V_12 ) {
F_3 ( V_8 -> V_10 , V_79 , & V_6 ) ;
V_6 |= V_204 ;
F_5 ( V_8 -> V_10 , V_79 , V_6 ) ;
F_28 ( V_8 , 1 ) ;
} else {
V_70 -> V_201 = 0 ;
F_13 ( & V_70 -> V_71 , L_16 ,
V_56 ) ;
}
}
F_3 ( V_8 -> V_10 , V_17 , & V_6 ) ;
if ( V_6 & V_164 ) {
F_44 ( & V_8 -> V_173 , F_31 ) ;
F_45 ( & V_8 -> V_173 ) ;
} else {
V_8 -> V_14 = 1 ;
}
return 0 ;
}
static int F_46 ( struct V_182 * V_70 )
{
struct V_7 * V_8 = F_47 ( V_70 ) ;
if ( V_70 -> V_201 )
F_48 ( V_70 -> V_201 , V_8 ) ;
F_49 ( & V_8 -> V_9 ) ;
return 0 ;
}
static int F_50 ( struct V_176 * V_71 )
{
struct V_7 * V_8 = F_51 ( V_71 ) ;
if ( V_8 -> V_70 -> V_201 ) {
F_52 ( V_8 -> V_70 -> V_201 ) ;
F_53 ( V_8 -> V_70 -> V_201 ) ;
}
return 0 ;
}
static int F_54 ( struct V_176 * V_71 )
{
struct V_7 * V_8 = F_51 ( V_71 ) ;
if ( V_8 -> V_70 -> V_201 ) {
F_55 ( V_8 -> V_70 -> V_201 ) ;
F_56 ( V_8 -> V_70 -> V_201 ) ;
F_28 ( V_8 , 1 ) ;
}
return 0 ;
}
