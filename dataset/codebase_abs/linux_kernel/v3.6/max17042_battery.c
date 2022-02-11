static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_1 , V_7 , V_5 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 = F_5 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_1 , V_7 , V_5 ) ;
return V_5 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_8 * V_9 , int V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
F_1 ( V_2 , V_9 [ V_11 ] . V_12 , V_9 [ V_11 ] . V_9 ) ;
}
static int F_7 ( struct V_13 * V_14 ,
enum V_15 V_16 ,
union V_17 * V_18 )
{
struct V_19 * V_20 = F_8 ( V_14 ,
struct V_19 , V_21 ) ;
int V_5 ;
if ( ! V_20 -> V_22 )
return - V_23 ;
switch ( V_16 ) {
case V_24 :
V_5 = F_4 ( V_20 -> V_2 , V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 & V_26 )
V_18 -> V_27 = 0 ;
else
V_18 -> V_27 = 1 ;
break;
case V_28 :
V_5 = F_4 ( V_20 -> V_2 , V_29 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 ;
break;
case V_30 :
V_5 = F_4 ( V_20 -> V_2 , V_31 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 >> 8 ;
V_18 -> V_27 *= 20000 ;
break;
case V_32 :
if ( V_20 -> V_33 == V_34 )
V_5 = F_4 ( V_20 -> V_2 , V_35 ) ;
else
V_5 = F_4 ( V_20 -> V_2 , V_36 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 >> 7 ;
V_18 -> V_27 *= 10000 ;
break;
case V_37 :
V_5 = F_4 ( V_20 -> V_2 , V_38 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 * 625 / 8 ;
break;
case V_39 :
V_5 = F_4 ( V_20 -> V_2 , V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 * 625 / 8 ;
break;
case V_41 :
V_5 = F_4 ( V_20 -> V_2 , V_42 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 * 625 / 8 ;
break;
case V_43 :
V_5 = F_4 ( V_20 -> V_2 , V_44 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 >> 8 ;
break;
case V_45 :
V_5 = F_4 ( V_20 -> V_2 , V_46 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 * 1000 / 2 ;
break;
case V_47 :
V_5 = F_4 ( V_20 -> V_2 , V_48 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 * 1000 / 2 ;
break;
case V_49 :
V_5 = F_4 ( V_20 -> V_2 , V_50 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 ;
if ( V_18 -> V_27 & 0x8000 ) {
V_18 -> V_27 = ( 0x7fff & ~ V_18 -> V_27 ) + 1 ;
V_18 -> V_27 *= - 1 ;
}
V_18 -> V_27 = V_18 -> V_27 * 10 / 256 ;
break;
case V_51 :
if ( V_20 -> V_52 -> V_53 ) {
V_5 = F_4 ( V_20 -> V_2 , V_54 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 ;
if ( V_18 -> V_27 & 0x8000 ) {
V_18 -> V_27 = ~ V_18 -> V_27 & 0x7fff ;
V_18 -> V_27 ++ ;
V_18 -> V_27 *= - 1 ;
}
V_18 -> V_27 *= 1562500 / V_20 -> V_52 -> V_55 ;
} else {
return - V_56 ;
}
break;
case V_57 :
if ( V_20 -> V_52 -> V_53 ) {
V_5 = F_4 ( V_20 -> V_2 ,
V_58 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 ;
if ( V_18 -> V_27 & 0x8000 ) {
V_18 -> V_27 = ~ V_18 -> V_27 & 0x7fff ;
V_18 -> V_27 ++ ;
V_18 -> V_27 *= - 1 ;
}
V_18 -> V_27 *= 1562500 / V_20 -> V_52 -> V_55 ;
} else {
return - V_56 ;
}
break;
default:
return - V_56 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
int V_59 = 8 ;
int V_5 ;
T_2 V_60 ;
do {
V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
V_60 = F_4 ( V_2 , V_3 ) ;
if ( V_60 != V_4 ) {
V_5 = - V_61 ;
V_59 -- ;
}
} while ( V_59 && V_60 != V_4 );
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_1 , V_7 , V_5 ) ;
return V_5 ;
}
static inline void F_10 (
struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
if ( V_4 )
F_1 ( V_2 , V_3 , V_4 ) ;
}
static inline void F_11 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
F_1 ( V_2 , V_62 , V_63 ) ;
F_1 ( V_2 , V_64 , V_65 ) ;
}
static inline void F_12 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
F_1 ( V_2 , V_62 , V_66 ) ;
F_1 ( V_2 , V_64 , V_67 ) ;
}
static inline void F_13 ( struct V_19 * V_20 ,
T_1 V_12 , int V_10 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
F_1 ( V_2 , V_12 + V_11 ,
V_20 -> V_52 -> V_68 -> V_69 [ V_11 ] ) ;
}
static inline void F_14 ( struct V_19 * V_20 ,
T_1 V_12 , T_2 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
V_9 [ V_11 ] = F_4 ( V_2 , V_12 + V_11 ) ;
}
static inline int F_15 ( struct V_19 * V_20 ,
T_2 * V_70 , T_2 * V_71 , int V_10 )
{
int V_11 ;
if ( memcmp ( V_70 , V_71 , V_10 ) ) {
F_3 ( & V_20 -> V_2 -> V_6 , L_2 , V_7 ) ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
F_16 ( & V_20 -> V_2 -> V_6 , L_3 ,
V_70 [ V_11 ] , V_71 [ V_11 ] ) ;
F_16 ( & V_20 -> V_2 -> V_6 , L_4 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_17 ( struct V_19 * V_20 )
{
int V_5 ;
int V_72 = F_18 ( V_20 -> V_52 -> V_68 -> V_69 ) ;
T_2 * V_73 ;
V_73 = F_19 ( V_72 , sizeof( * V_73 ) , V_74 ) ;
if ( ! V_73 )
return - V_75 ;
F_11 ( V_20 ) ;
F_13 ( V_20 , V_76 ,
V_72 ) ;
F_14 ( V_20 , V_76 , V_73 ,
V_72 ) ;
V_5 = F_15 (
V_20 ,
V_20 -> V_52 -> V_68 -> V_69 ,
V_73 ,
V_72 ) ;
F_12 ( V_20 ) ;
F_20 ( V_73 ) ;
return V_5 ;
}
static int F_21 ( struct V_19 * V_20 )
{
int V_11 ;
int V_72 = F_18 ( V_20 -> V_52 -> V_68 -> V_69 ) ;
T_2 * V_73 ;
int V_5 = 0 ;
V_73 = F_19 ( V_72 , sizeof( * V_73 ) , V_74 ) ;
if ( ! V_73 )
return - V_75 ;
F_14 ( V_20 , V_76 , V_73 ,
V_72 ) ;
for ( V_11 = 0 ; V_11 < V_72 ; V_11 ++ )
if ( V_73 [ V_11 ] )
V_5 = - V_56 ;
F_20 ( V_73 ) ;
return V_5 ;
}
static void F_22 ( struct V_19 * V_20 )
{
struct V_77 * V_78 = V_20 -> V_52 -> V_68 ;
F_1 ( V_20 -> V_2 , V_79 , V_78 -> V_78 ) ;
F_1 ( V_20 -> V_2 , V_80 , V_78 -> V_81 ) ;
F_1 ( V_20 -> V_2 , V_82 ,
V_78 -> V_83 ) ;
F_1 ( V_20 -> V_2 , V_84 , V_78 -> V_85 ) ;
if ( V_20 -> V_33 == V_86 )
F_1 ( V_20 -> V_2 , V_87 ,
V_78 -> V_88 ) ;
}
static void F_23 ( struct V_19 * V_20 )
{
struct V_77 * V_78 = V_20 -> V_52 -> V_68 ;
F_9 ( V_20 -> V_2 , V_89 ,
V_78 -> V_90 ) ;
F_9 ( V_20 -> V_2 , V_91 ,
V_78 -> V_92 ) ;
F_9 ( V_20 -> V_2 , V_93 ,
V_78 -> V_94 ) ;
if ( V_20 -> V_33 == V_34 ) {
F_1 ( V_20 -> V_2 , V_95 ,
V_78 -> V_96 ) ;
F_9 ( V_20 -> V_2 , V_97 ,
V_78 -> V_98 ) ;
} else {
F_9 ( V_20 -> V_2 , V_99 ,
V_78 -> V_100 ) ;
F_9 ( V_20 -> V_2 , V_101 ,
V_78 -> V_102 ) ;
F_9 ( V_20 -> V_2 , V_103 ,
V_78 -> V_104 ) ;
F_9 ( V_20 -> V_2 , V_105 ,
V_78 -> V_106 ) ;
}
}
static void F_24 ( struct V_19 * V_20 )
{
struct V_77 * V_78 = V_20 -> V_52 -> V_68 ;
F_9 ( V_20 -> V_2 , V_46 ,
V_78 -> V_107 ) ;
F_1 ( V_20 -> V_2 , V_108 ,
V_78 -> V_109 ) ;
F_9 ( V_20 -> V_2 , V_110 ,
V_78 -> V_111 ) ;
}
static void F_25 ( struct V_19 * V_20 )
{
T_2 V_112 ;
V_112 = F_4 ( V_20 -> V_2 , V_113 ) ;
F_1 ( V_20 -> V_2 , V_114 , V_115 ) ;
F_9 ( V_20 -> V_2 , V_116 , V_112 ) ;
F_1 ( V_20 -> V_2 , V_114 , V_117 ) ;
}
static void F_26 ( struct V_19 * V_20 )
{
T_2 V_118 , V_119 , V_120 , V_112 ;
T_3 V_121 ;
struct V_77 * V_78 = V_20 -> V_52 -> V_68 ;
V_118 = F_4 ( V_20 -> V_2 , V_122 ) ;
V_112 = F_4 ( V_20 -> V_2 , V_113 ) ;
V_121 = ( ( V_112 >> 8 ) * V_118 ) / 100 ;
F_9 ( V_20 -> V_2 , V_123 , ( T_2 ) V_121 ) ;
V_119 = ( T_2 ) V_121 ;
F_9 ( V_20 -> V_2 , V_124 , V_119 ) ;
V_120 = V_78 -> V_107 / V_125 ;
F_9 ( V_20 -> V_2 , V_126 , V_120 ) ;
F_9 ( V_20 -> V_2 , V_127 , V_128 ) ;
F_9 ( V_20 -> V_2 , V_46 ,
V_78 -> V_107 ) ;
F_1 ( V_20 -> V_2 , V_108 ,
V_78 -> V_109 ) ;
F_9 ( V_20 -> V_2 , V_110 ,
V_78 -> V_111 ) ;
F_1 ( V_20 -> V_2 , V_44 , V_112 ) ;
}
static inline void F_27 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_77 * V_78 = V_20 -> V_52 -> V_68 ;
F_10 ( V_2 , V_129 , V_78 -> V_130 ) ;
F_10 ( V_2 , V_131 , V_78 -> V_132 ) ;
F_10 ( V_2 , V_133 , V_78 -> V_134 ) ;
F_10 ( V_2 , V_135 , V_78 -> V_136 ) ;
F_10 ( V_2 , V_137 , V_78 -> V_138 ) ;
F_10 ( V_2 , V_139 , V_78 -> V_140 ) ;
F_10 ( V_2 , V_141 ,
V_78 -> V_142 ) ;
F_10 ( V_2 , V_79 , V_78 -> V_78 ) ;
F_10 ( V_2 , V_143 , V_78 -> V_144 ) ;
F_10 ( V_2 , V_108 , V_78 -> V_109 ) ;
F_10 ( V_2 , V_93 , V_78 -> V_94 ) ;
F_10 ( V_2 , V_145 , V_78 -> V_146 ) ;
F_10 ( V_2 , V_80 , V_78 -> V_81 ) ;
F_10 ( V_2 , V_82 , V_78 -> V_83 ) ;
F_10 ( V_2 , V_84 , V_78 -> V_85 ) ;
F_10 ( V_2 , V_147 , V_78 -> V_148 ) ;
F_10 ( V_2 , V_149 , V_78 -> V_150 ) ;
F_10 ( V_2 , V_46 , V_78 -> V_107 ) ;
F_10 ( V_2 , V_110 , V_78 -> V_111 ) ;
if ( V_20 -> V_33 == V_34 )
F_10 ( V_2 , V_151 ,
V_78 -> V_152 ) ;
F_10 ( V_2 , V_153 , V_78 -> V_154 ) ;
F_10 ( V_2 , V_126 , V_78 -> V_155 ) ;
F_10 ( V_2 , V_127 , V_78 -> V_156 ) ;
if ( V_20 -> V_33 == V_34 )
F_10 ( V_2 , V_35 , V_78 -> V_157 ) ;
else
F_10 ( V_2 , V_36 , V_78 -> V_157 ) ;
F_10 ( V_2 , V_158 , V_78 -> V_159 ) ;
F_10 ( V_2 , V_160 , V_78 -> V_161 ) ;
F_10 ( V_2 , V_162 , V_78 -> V_163 ) ;
F_10 ( V_2 , V_89 , V_78 -> V_90 ) ;
F_10 ( V_2 , V_91 , V_78 -> V_92 ) ;
if ( V_20 -> V_33 ) {
F_10 ( V_2 , V_95 ,
V_78 -> V_96 ) ;
F_10 ( V_2 , V_97 ,
V_78 -> V_98 ) ;
}
}
static int F_28 ( struct V_19 * V_20 )
{
int V_5 ;
int V_18 ;
F_27 ( V_20 ) ;
F_29 ( 500 ) ;
F_22 ( V_20 ) ;
V_5 = F_17 ( V_20 ) ;
if ( V_5 ) {
F_3 ( & V_20 -> V_2 -> V_6 , L_5 ,
V_7 ) ;
return - V_61 ;
}
F_21 ( V_20 ) ;
if ( V_5 ) {
F_3 ( & V_20 -> V_2 -> V_6 , L_6 ,
V_7 ) ;
return - V_61 ;
}
F_23 ( V_20 ) ;
F_24 ( V_20 ) ;
F_29 ( 350 ) ;
F_25 ( V_20 ) ;
F_26 ( V_20 ) ;
V_18 = F_4 ( V_20 -> V_2 , V_25 ) ;
F_1 ( V_20 -> V_2 , V_25 ,
V_18 & ( ~ V_164 ) ) ;
return 0 ;
}
static void F_30 ( struct V_19 * V_20 , T_2 V_165 )
{
T_2 V_166 , V_167 ;
V_166 = F_4 ( V_20 -> V_2 , V_44 ) >> 8 ;
V_167 = ( V_166 + V_165 ) << 8 ;
V_167 |= ( V_166 - V_165 ) ;
F_1 ( V_20 -> V_2 , V_141 , V_167 ) ;
}
static T_4 F_31 ( int V_168 , void * V_6 )
{
struct V_19 * V_20 = V_6 ;
T_2 V_18 ;
V_18 = F_4 ( V_20 -> V_2 , V_25 ) ;
if ( ( V_18 & V_169 ) ||
( V_18 & V_170 ) ) {
F_16 ( & V_20 -> V_2 -> V_6 , L_7 ) ;
F_30 ( V_20 , 1 ) ;
}
F_32 ( & V_20 -> V_21 ) ;
return V_171 ;
}
static void F_33 ( struct V_172 * V_173 )
{
struct V_19 * V_20 = F_8 ( V_173 ,
struct V_19 , V_173 ) ;
int V_5 ;
if ( V_20 -> V_52 -> V_174 && V_20 -> V_52 -> V_68 ) {
V_5 = F_28 ( V_20 ) ;
if ( V_5 )
return;
}
V_20 -> V_22 = 1 ;
}
static struct V_175 *
F_34 ( struct V_176 * V_6 )
{
struct V_177 * V_178 = V_6 -> V_179 ;
T_3 V_180 ;
struct V_175 * V_52 ;
if ( ! V_178 )
return V_6 -> V_181 ;
V_52 = F_35 ( V_6 , sizeof( * V_52 ) , V_74 ) ;
if ( ! V_52 )
return NULL ;
if ( F_36 ( V_178 , L_8 , & V_180 ) == 0 ) {
V_52 -> V_55 = V_180 ;
V_52 -> V_53 = true ;
}
return V_52 ;
}
static struct V_175 *
F_34 ( struct V_176 * V_6 )
{
return V_6 -> V_181 ;
}
static int T_5 F_37 ( struct V_1 * V_2 ,
const struct V_182 * V_168 )
{
struct V_183 * V_184 = F_38 ( V_2 -> V_6 . V_185 ) ;
struct V_19 * V_20 ;
int V_5 ;
int V_3 ;
if ( ! F_39 ( V_184 , V_186 ) )
return - V_61 ;
V_20 = F_35 ( & V_2 -> V_6 , sizeof( * V_20 ) , V_74 ) ;
if ( ! V_20 )
return - V_75 ;
V_20 -> V_2 = V_2 ;
V_20 -> V_52 = F_34 ( & V_2 -> V_6 ) ;
if ( ! V_20 -> V_52 ) {
F_3 ( & V_2 -> V_6 , L_9 ) ;
return - V_56 ;
}
F_40 ( V_2 , V_20 ) ;
V_5 = F_4 ( V_20 -> V_2 , V_187 ) ;
if ( V_5 == V_188 ) {
F_41 ( & V_2 -> V_6 , L_10 ) ;
V_20 -> V_33 = V_34 ;
} else if ( V_5 == V_189 ) {
F_41 ( & V_2 -> V_6 , L_11 ) ;
V_20 -> V_33 = V_86 ;
} else {
F_3 ( & V_2 -> V_6 , L_12 , V_5 ) ;
return - V_61 ;
}
V_20 -> V_21 . V_190 = L_13 ;
V_20 -> V_21 . type = V_191 ;
V_20 -> V_21 . V_192 = F_7 ;
V_20 -> V_21 . V_193 = V_194 ;
V_20 -> V_21 . V_195 = F_18 ( V_194 ) ;
if ( ! V_20 -> V_52 -> V_53 )
V_20 -> V_21 . V_195 -= 2 ;
if ( V_20 -> V_52 -> V_55 == 0 )
V_20 -> V_52 -> V_55 = V_196 ;
if ( V_20 -> V_52 -> V_197 )
F_6 ( V_2 , V_20 -> V_52 -> V_197 ,
V_20 -> V_52 -> V_198 ) ;
if ( ! V_20 -> V_52 -> V_53 ) {
F_1 ( V_2 , V_133 , 0x0000 ) ;
F_1 ( V_2 , V_147 , 0x0003 ) ;
F_1 ( V_2 , V_80 , 0x0007 ) ;
}
V_5 = F_42 ( & V_2 -> V_6 , & V_20 -> V_21 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_14 ) ;
return V_5 ;
}
if ( V_2 -> V_199 ) {
V_5 = F_43 ( V_2 -> V_199 , NULL ,
F_31 ,
V_200 ,
V_20 -> V_21 . V_190 , V_20 ) ;
if ( ! V_5 ) {
V_3 = F_4 ( V_2 , V_79 ) ;
V_3 |= V_201 ;
F_1 ( V_2 , V_79 , V_3 ) ;
F_30 ( V_20 , 1 ) ;
} else {
V_2 -> V_199 = 0 ;
F_3 ( & V_2 -> V_6 , L_15 ,
V_7 ) ;
}
}
V_3 = F_4 ( V_20 -> V_2 , V_25 ) ;
if ( V_3 & V_164 ) {
F_44 ( & V_20 -> V_173 , F_33 ) ;
F_45 ( & V_20 -> V_173 ) ;
} else {
V_20 -> V_22 = 1 ;
}
return 0 ;
}
static int T_6 F_46 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_47 ( V_2 ) ;
if ( V_2 -> V_199 )
F_48 ( V_2 -> V_199 , V_20 ) ;
F_49 ( & V_20 -> V_21 ) ;
return 0 ;
}
static int F_50 ( struct V_176 * V_6 )
{
struct V_19 * V_20 = F_51 ( V_6 ) ;
if ( V_20 -> V_2 -> V_199 ) {
F_52 ( V_20 -> V_2 -> V_199 ) ;
F_53 ( V_20 -> V_2 -> V_199 ) ;
}
return 0 ;
}
static int F_54 ( struct V_176 * V_6 )
{
struct V_19 * V_20 = F_51 ( V_6 ) ;
if ( V_20 -> V_2 -> V_199 ) {
F_55 ( V_20 -> V_2 -> V_199 ) ;
F_56 ( V_20 -> V_2 -> V_199 ) ;
F_30 ( V_20 , 1 ) ;
}
return 0 ;
}
