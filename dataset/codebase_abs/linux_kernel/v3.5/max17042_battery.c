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
V_18 -> V_27 = V_5 ;
if ( V_18 -> V_27 & 0x8000 ) {
V_18 -> V_27 = ( 0x7fff & ~ V_18 -> V_27 ) + 1 ;
V_18 -> V_27 *= - 1 ;
}
V_18 -> V_27 = V_18 -> V_27 * 10 / 256 ;
break;
case V_49 :
if ( V_20 -> V_50 -> V_51 ) {
V_5 = F_4 ( V_20 -> V_2 , V_52 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 ;
if ( V_18 -> V_27 & 0x8000 ) {
V_18 -> V_27 = ~ V_18 -> V_27 & 0x7fff ;
V_18 -> V_27 ++ ;
V_18 -> V_27 *= - 1 ;
}
V_18 -> V_27 *= 1562500 / V_20 -> V_50 -> V_53 ;
} else {
return - V_54 ;
}
break;
case V_55 :
if ( V_20 -> V_50 -> V_51 ) {
V_5 = F_4 ( V_20 -> V_2 ,
V_56 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 ;
if ( V_18 -> V_27 & 0x8000 ) {
V_18 -> V_27 = ~ V_18 -> V_27 & 0x7fff ;
V_18 -> V_27 ++ ;
V_18 -> V_27 *= - 1 ;
}
V_18 -> V_27 *= 1562500 / V_20 -> V_50 -> V_53 ;
} else {
return - V_54 ;
}
break;
default:
return - V_54 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
int V_57 = 8 ;
int V_5 ;
T_2 V_58 ;
do {
V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
V_58 = F_4 ( V_2 , V_3 ) ;
if ( V_58 != V_4 ) {
V_5 = - V_59 ;
V_57 -- ;
}
} while ( V_57 && V_58 != V_4 );
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
F_1 ( V_2 , V_60 , V_61 ) ;
F_1 ( V_2 , V_62 , V_63 ) ;
}
static inline void F_12 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
F_1 ( V_2 , V_60 , V_64 ) ;
F_1 ( V_2 , V_62 , V_65 ) ;
}
static inline void F_13 ( struct V_19 * V_20 ,
T_1 V_12 , int V_10 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
F_1 ( V_2 , V_12 + V_11 ,
V_20 -> V_50 -> V_66 -> V_67 [ V_11 ] ) ;
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
T_2 * V_68 , T_2 * V_69 , int V_10 )
{
int V_11 ;
if ( memcmp ( V_68 , V_69 , V_10 ) ) {
F_3 ( & V_20 -> V_2 -> V_6 , L_2 , V_7 ) ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
F_16 ( & V_20 -> V_2 -> V_6 , L_3 ,
V_68 [ V_11 ] , V_69 [ V_11 ] ) ;
F_16 ( & V_20 -> V_2 -> V_6 , L_4 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_17 ( struct V_19 * V_20 )
{
int V_5 ;
int V_70 = F_18 ( V_20 -> V_50 -> V_66 -> V_67 ) ;
T_2 * V_71 ;
V_71 = F_19 ( V_70 , sizeof( * V_71 ) , V_72 ) ;
if ( ! V_71 )
return - V_73 ;
F_11 ( V_20 ) ;
F_13 ( V_20 , V_74 ,
V_70 ) ;
F_14 ( V_20 , V_74 , V_71 ,
V_70 ) ;
V_5 = F_15 (
V_20 ,
V_20 -> V_50 -> V_66 -> V_67 ,
V_71 ,
V_70 ) ;
F_12 ( V_20 ) ;
F_20 ( V_71 ) ;
return V_5 ;
}
static int F_21 ( struct V_19 * V_20 )
{
int V_11 ;
int V_70 = F_18 ( V_20 -> V_50 -> V_66 -> V_67 ) ;
T_2 * V_71 ;
int V_5 = 0 ;
V_71 = F_19 ( V_70 , sizeof( * V_71 ) , V_72 ) ;
if ( ! V_71 )
return - V_73 ;
F_14 ( V_20 , V_74 , V_71 ,
V_70 ) ;
for ( V_11 = 0 ; V_11 < V_70 ; V_11 ++ )
if ( V_71 [ V_11 ] )
V_5 = - V_54 ;
F_20 ( V_71 ) ;
return V_5 ;
}
static void F_22 ( struct V_19 * V_20 )
{
struct V_75 * V_76 = V_20 -> V_50 -> V_66 ;
F_1 ( V_20 -> V_2 , V_77 , V_76 -> V_76 ) ;
F_1 ( V_20 -> V_2 , V_78 , V_76 -> V_79 ) ;
F_1 ( V_20 -> V_2 , V_80 ,
V_76 -> V_81 ) ;
F_1 ( V_20 -> V_2 , V_82 , V_76 -> V_83 ) ;
if ( V_20 -> V_33 == V_84 )
F_1 ( V_20 -> V_2 , V_85 ,
V_76 -> V_86 ) ;
}
static void F_23 ( struct V_19 * V_20 )
{
struct V_75 * V_76 = V_20 -> V_50 -> V_66 ;
F_9 ( V_20 -> V_2 , V_87 ,
V_76 -> V_88 ) ;
F_9 ( V_20 -> V_2 , V_89 ,
V_76 -> V_90 ) ;
F_9 ( V_20 -> V_2 , V_91 ,
V_76 -> V_92 ) ;
if ( V_20 -> V_33 == V_34 ) {
F_1 ( V_20 -> V_2 , V_93 ,
V_76 -> V_94 ) ;
F_9 ( V_20 -> V_2 , V_95 ,
V_76 -> V_96 ) ;
} else {
F_9 ( V_20 -> V_2 , V_97 ,
V_76 -> V_98 ) ;
F_9 ( V_20 -> V_2 , V_99 ,
V_76 -> V_100 ) ;
F_9 ( V_20 -> V_2 , V_101 ,
V_76 -> V_102 ) ;
F_9 ( V_20 -> V_2 , V_103 ,
V_76 -> V_104 ) ;
}
}
static void F_24 ( struct V_19 * V_20 )
{
struct V_75 * V_76 = V_20 -> V_50 -> V_66 ;
F_9 ( V_20 -> V_2 , V_46 ,
V_76 -> V_105 ) ;
F_1 ( V_20 -> V_2 , V_106 ,
V_76 -> V_107 ) ;
F_9 ( V_20 -> V_2 , V_108 ,
V_76 -> V_109 ) ;
}
static void F_25 ( struct V_19 * V_20 )
{
T_2 V_110 ;
V_110 = F_4 ( V_20 -> V_2 , V_111 ) ;
F_1 ( V_20 -> V_2 , V_112 , V_113 ) ;
F_9 ( V_20 -> V_2 , V_114 , V_110 ) ;
F_1 ( V_20 -> V_2 , V_112 , V_115 ) ;
}
static void F_26 ( struct V_19 * V_20 )
{
T_2 V_116 , V_117 , V_118 , V_110 ;
T_3 V_119 ;
struct V_75 * V_76 = V_20 -> V_50 -> V_66 ;
V_116 = F_4 ( V_20 -> V_2 , V_120 ) ;
V_110 = F_4 ( V_20 -> V_2 , V_111 ) ;
V_119 = ( ( V_110 >> 8 ) * V_116 ) / 100 ;
F_9 ( V_20 -> V_2 , V_121 , ( T_2 ) V_119 ) ;
V_117 = ( T_2 ) V_119 ;
F_9 ( V_20 -> V_2 , V_122 , V_117 ) ;
V_118 = V_76 -> V_105 / V_123 ;
F_9 ( V_20 -> V_2 , V_124 , V_118 ) ;
F_9 ( V_20 -> V_2 , V_125 , V_126 ) ;
F_9 ( V_20 -> V_2 , V_46 ,
V_76 -> V_105 ) ;
F_1 ( V_20 -> V_2 , V_106 ,
V_76 -> V_107 ) ;
F_9 ( V_20 -> V_2 , V_108 ,
V_76 -> V_109 ) ;
F_1 ( V_20 -> V_2 , V_44 , V_110 ) ;
}
static inline void F_27 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_75 * V_76 = V_20 -> V_50 -> V_66 ;
F_10 ( V_2 , V_127 , V_76 -> V_128 ) ;
F_10 ( V_2 , V_129 , V_76 -> V_130 ) ;
F_10 ( V_2 , V_131 , V_76 -> V_132 ) ;
F_10 ( V_2 , V_133 , V_76 -> V_134 ) ;
F_10 ( V_2 , V_135 , V_76 -> V_136 ) ;
F_10 ( V_2 , V_137 , V_76 -> V_138 ) ;
F_10 ( V_2 , V_139 ,
V_76 -> V_140 ) ;
F_10 ( V_2 , V_77 , V_76 -> V_76 ) ;
F_10 ( V_2 , V_141 , V_76 -> V_142 ) ;
F_10 ( V_2 , V_106 , V_76 -> V_107 ) ;
F_10 ( V_2 , V_91 , V_76 -> V_92 ) ;
F_10 ( V_2 , V_143 , V_76 -> V_144 ) ;
F_10 ( V_2 , V_78 , V_76 -> V_79 ) ;
F_10 ( V_2 , V_80 , V_76 -> V_81 ) ;
F_10 ( V_2 , V_82 , V_76 -> V_83 ) ;
F_10 ( V_2 , V_145 , V_76 -> V_146 ) ;
F_10 ( V_2 , V_147 , V_76 -> V_148 ) ;
F_10 ( V_2 , V_46 , V_76 -> V_105 ) ;
F_10 ( V_2 , V_108 , V_76 -> V_109 ) ;
if ( V_20 -> V_33 == V_34 )
F_10 ( V_2 , V_149 ,
V_76 -> V_150 ) ;
F_10 ( V_2 , V_151 , V_76 -> V_152 ) ;
F_10 ( V_2 , V_124 , V_76 -> V_153 ) ;
F_10 ( V_2 , V_125 , V_76 -> V_154 ) ;
if ( V_20 -> V_33 == V_34 )
F_10 ( V_2 , V_35 , V_76 -> V_155 ) ;
else
F_10 ( V_2 , V_36 , V_76 -> V_155 ) ;
F_10 ( V_2 , V_156 , V_76 -> V_157 ) ;
F_10 ( V_2 , V_158 , V_76 -> V_159 ) ;
F_10 ( V_2 , V_160 , V_76 -> V_161 ) ;
F_10 ( V_2 , V_87 , V_76 -> V_88 ) ;
F_10 ( V_2 , V_89 , V_76 -> V_90 ) ;
if ( V_20 -> V_33 ) {
F_10 ( V_2 , V_93 ,
V_76 -> V_94 ) ;
F_10 ( V_2 , V_95 ,
V_76 -> V_96 ) ;
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
return - V_59 ;
}
F_21 ( V_20 ) ;
if ( V_5 ) {
F_3 ( & V_20 -> V_2 -> V_6 , L_6 ,
V_7 ) ;
return - V_59 ;
}
F_23 ( V_20 ) ;
F_24 ( V_20 ) ;
F_29 ( 350 ) ;
F_25 ( V_20 ) ;
F_26 ( V_20 ) ;
V_18 = F_4 ( V_20 -> V_2 , V_25 ) ;
F_1 ( V_20 -> V_2 , V_25 ,
V_18 & ( ~ V_162 ) ) ;
return 0 ;
}
static void F_30 ( struct V_19 * V_20 , T_2 V_163 )
{
T_2 V_164 , V_165 ;
V_164 = F_4 ( V_20 -> V_2 , V_44 ) >> 8 ;
V_165 = ( V_164 + V_163 ) << 8 ;
V_165 |= ( V_164 - V_163 ) ;
F_1 ( V_20 -> V_2 , V_139 , V_165 ) ;
}
static T_4 F_31 ( int V_166 , void * V_6 )
{
struct V_19 * V_20 = V_6 ;
T_2 V_18 ;
V_18 = F_4 ( V_20 -> V_2 , V_25 ) ;
if ( ( V_18 & V_167 ) ||
( V_18 & V_168 ) ) {
F_16 ( & V_20 -> V_2 -> V_6 , L_7 ) ;
F_30 ( V_20 , 1 ) ;
}
F_32 ( & V_20 -> V_21 ) ;
return V_169 ;
}
static void F_33 ( struct V_170 * V_171 )
{
struct V_19 * V_20 = F_8 ( V_171 ,
struct V_19 , V_171 ) ;
int V_5 ;
if ( V_20 -> V_50 -> V_172 && V_20 -> V_50 -> V_66 ) {
V_5 = F_28 ( V_20 ) ;
if ( V_5 )
return;
}
V_20 -> V_22 = 1 ;
}
static struct V_173 *
F_34 ( struct V_174 * V_6 )
{
struct V_175 * V_176 = V_6 -> V_177 ;
T_3 V_178 ;
struct V_173 * V_50 ;
if ( ! V_176 )
return V_6 -> V_179 ;
V_50 = F_35 ( V_6 , sizeof( * V_50 ) , V_72 ) ;
if ( ! V_50 )
return NULL ;
if ( F_36 ( V_176 , L_8 , & V_178 ) == 0 ) {
V_50 -> V_53 = V_178 ;
V_50 -> V_51 = true ;
}
return V_50 ;
}
static struct V_173 *
F_34 ( struct V_174 * V_6 )
{
return V_6 -> V_179 ;
}
static int T_5 F_37 ( struct V_1 * V_2 ,
const struct V_180 * V_166 )
{
struct V_181 * V_182 = F_38 ( V_2 -> V_6 . V_183 ) ;
struct V_19 * V_20 ;
int V_5 ;
int V_3 ;
if ( ! F_39 ( V_182 , V_184 ) )
return - V_59 ;
V_20 = F_35 ( & V_2 -> V_6 , sizeof( * V_20 ) , V_72 ) ;
if ( ! V_20 )
return - V_73 ;
V_20 -> V_2 = V_2 ;
V_20 -> V_50 = F_34 ( & V_2 -> V_6 ) ;
if ( ! V_20 -> V_50 ) {
F_3 ( & V_2 -> V_6 , L_9 ) ;
return - V_54 ;
}
F_40 ( V_2 , V_20 ) ;
V_5 = F_4 ( V_20 -> V_2 , V_185 ) ;
if ( V_5 == V_186 ) {
F_41 ( & V_2 -> V_6 , L_10 ) ;
V_20 -> V_33 = V_34 ;
} else if ( V_5 == V_187 ) {
F_41 ( & V_2 -> V_6 , L_11 ) ;
V_20 -> V_33 = V_84 ;
} else {
F_3 ( & V_2 -> V_6 , L_12 , V_5 ) ;
return - V_59 ;
}
V_20 -> V_21 . V_188 = L_13 ;
V_20 -> V_21 . type = V_189 ;
V_20 -> V_21 . V_190 = F_7 ;
V_20 -> V_21 . V_191 = V_192 ;
V_20 -> V_21 . V_193 = F_18 ( V_192 ) ;
if ( ! V_20 -> V_50 -> V_51 )
V_20 -> V_21 . V_193 -= 2 ;
if ( V_20 -> V_50 -> V_53 == 0 )
V_20 -> V_50 -> V_53 = V_194 ;
if ( V_20 -> V_50 -> V_195 )
F_6 ( V_2 , V_20 -> V_50 -> V_195 ,
V_20 -> V_50 -> V_196 ) ;
if ( ! V_20 -> V_50 -> V_51 ) {
F_1 ( V_2 , V_131 , 0x0000 ) ;
F_1 ( V_2 , V_145 , 0x0003 ) ;
F_1 ( V_2 , V_78 , 0x0007 ) ;
}
V_5 = F_42 ( & V_2 -> V_6 , & V_20 -> V_21 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_14 ) ;
return V_5 ;
}
if ( V_2 -> V_197 ) {
V_5 = F_43 ( V_2 -> V_197 , NULL ,
F_31 ,
V_198 ,
V_20 -> V_21 . V_188 , V_20 ) ;
if ( ! V_5 ) {
V_3 = F_4 ( V_2 , V_77 ) ;
V_3 |= V_199 ;
F_1 ( V_2 , V_77 , V_3 ) ;
F_30 ( V_20 , 1 ) ;
} else {
V_2 -> V_197 = 0 ;
F_3 ( & V_2 -> V_6 , L_15 ,
V_7 ) ;
}
}
V_3 = F_4 ( V_20 -> V_2 , V_25 ) ;
if ( V_3 & V_162 ) {
F_44 ( & V_20 -> V_171 , F_33 ) ;
F_45 ( & V_20 -> V_171 ) ;
} else {
V_20 -> V_22 = 1 ;
}
return 0 ;
}
static int T_6 F_46 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_47 ( V_2 ) ;
if ( V_2 -> V_197 )
F_48 ( V_2 -> V_197 , V_20 ) ;
F_49 ( & V_20 -> V_21 ) ;
return 0 ;
}
static int F_50 ( struct V_174 * V_6 )
{
struct V_19 * V_20 = F_51 ( V_6 ) ;
if ( V_20 -> V_2 -> V_197 ) {
F_52 ( V_20 -> V_2 -> V_197 ) ;
F_53 ( V_20 -> V_2 -> V_197 ) ;
}
return 0 ;
}
static int F_54 ( struct V_174 * V_6 )
{
struct V_19 * V_20 = F_51 ( V_6 ) ;
if ( V_20 -> V_2 -> V_197 ) {
F_55 ( V_20 -> V_2 -> V_197 ) ;
F_56 ( V_20 -> V_2 -> V_197 ) ;
F_30 ( V_20 , 1 ) ;
}
return 0 ;
}
