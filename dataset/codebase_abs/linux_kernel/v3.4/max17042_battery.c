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
V_5 = F_4 ( V_20 -> V_2 , V_33 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 >> 7 ;
V_18 -> V_27 *= 10000 ;
break;
case V_34 :
V_5 = F_4 ( V_20 -> V_2 , V_35 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 * 625 / 8 ;
break;
case V_36 :
V_5 = F_4 ( V_20 -> V_2 , V_37 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 * 625 / 8 ;
break;
case V_38 :
V_5 = F_4 ( V_20 -> V_2 , V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 >> 8 ;
break;
case V_40 :
V_5 = F_4 ( V_20 -> V_2 , V_41 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 * 1000 / 2 ;
break;
case V_42 :
V_5 = F_4 ( V_20 -> V_2 , V_43 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 ;
if ( V_18 -> V_27 & 0x8000 ) {
V_18 -> V_27 = ( 0x7fff & ~ V_18 -> V_27 ) + 1 ;
V_18 -> V_27 *= - 1 ;
}
V_18 -> V_27 = V_18 -> V_27 * 10 / 256 ;
break;
case V_44 :
if ( V_20 -> V_45 -> V_46 ) {
V_5 = F_4 ( V_20 -> V_2 , V_47 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 ;
if ( V_18 -> V_27 & 0x8000 ) {
V_18 -> V_27 = ~ V_18 -> V_27 & 0x7fff ;
V_18 -> V_27 ++ ;
V_18 -> V_27 *= - 1 ;
}
V_18 -> V_27 *= 1562500 / V_20 -> V_45 -> V_48 ;
} else {
return - V_49 ;
}
break;
case V_50 :
if ( V_20 -> V_45 -> V_46 ) {
V_5 = F_4 ( V_20 -> V_2 ,
V_51 ) ;
if ( V_5 < 0 )
return V_5 ;
V_18 -> V_27 = V_5 ;
if ( V_18 -> V_27 & 0x8000 ) {
V_18 -> V_27 = ~ V_18 -> V_27 & 0x7fff ;
V_18 -> V_27 ++ ;
V_18 -> V_27 *= - 1 ;
}
V_18 -> V_27 *= 1562500 / V_20 -> V_45 -> V_48 ;
} else {
return - V_49 ;
}
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
int V_52 = 8 ;
int V_5 ;
T_2 V_53 ;
do {
V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
V_53 = F_4 ( V_2 , V_3 ) ;
if ( V_53 != V_4 ) {
V_5 = - V_54 ;
V_52 -- ;
}
} while ( V_52 && V_53 != V_4 );
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
F_1 ( V_2 , V_55 , V_56 ) ;
F_1 ( V_2 , V_57 , V_58 ) ;
}
static inline void F_12 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
F_1 ( V_2 , V_55 , V_59 ) ;
F_1 ( V_2 , V_57 , V_60 ) ;
}
static inline void F_13 ( struct V_19 * V_20 ,
T_1 V_12 , int V_10 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
F_1 ( V_2 , V_12 + V_11 ,
V_20 -> V_45 -> V_61 -> V_62 [ V_11 ] ) ;
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
T_2 * V_63 , T_2 * V_64 , int V_10 )
{
int V_11 ;
if ( memcmp ( V_63 , V_64 , V_10 ) ) {
F_3 ( & V_20 -> V_2 -> V_6 , L_2 , V_7 ) ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
F_16 ( & V_20 -> V_2 -> V_6 , L_3 ,
V_63 [ V_11 ] , V_64 [ V_11 ] ) ;
F_16 ( & V_20 -> V_2 -> V_6 , L_4 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_17 ( struct V_19 * V_20 )
{
int V_5 ;
int V_65 =
sizeof( V_20 -> V_45 -> V_61 -> V_62 ) / sizeof( T_2 ) ;
T_2 * V_66 ;
V_66 = F_18 ( V_65 , V_67 ) ;
if ( ! V_66 )
return - V_68 ;
F_11 ( V_20 ) ;
F_13 ( V_20 , V_69 ,
V_65 ) ;
F_14 ( V_20 , V_69 , V_66 ,
V_65 ) ;
V_5 = F_15 (
V_20 ,
V_20 -> V_45 -> V_61 -> V_62 ,
V_66 ,
V_65 ) ;
F_12 ( V_20 ) ;
F_19 ( V_66 ) ;
return V_5 ;
}
static int F_20 ( struct V_19 * V_20 )
{
int V_11 ;
int V_65 =
sizeof( V_20 -> V_45 -> V_61 -> V_62 ) ;
T_2 * V_66 ;
int V_5 = 0 ;
V_66 = F_18 ( V_65 , V_67 ) ;
if ( ! V_66 )
return - V_68 ;
F_14 ( V_20 , V_69 , V_66 ,
V_65 ) ;
for ( V_11 = 0 ; V_11 < V_65 ; V_11 ++ )
if ( V_66 [ V_11 ] )
V_5 = - V_49 ;
F_19 ( V_66 ) ;
return V_5 ;
}
static void F_21 ( struct V_19 * V_20 )
{
struct V_70 * V_71 = V_20 -> V_45 -> V_61 ;
F_1 ( V_20 -> V_2 , V_72 , V_71 -> V_71 ) ;
F_1 ( V_20 -> V_2 , V_73 , V_71 -> V_74 ) ;
F_1 ( V_20 -> V_2 , V_75 ,
V_71 -> V_76 ) ;
F_1 ( V_20 -> V_2 , V_77 , V_71 -> V_78 ) ;
}
static void F_22 ( struct V_19 * V_20 )
{
struct V_70 * V_71 = V_20 -> V_45 -> V_61 ;
F_9 ( V_20 -> V_2 , V_79 ,
V_71 -> V_80 ) ;
F_9 ( V_20 -> V_2 , V_81 ,
V_71 -> V_82 ) ;
F_1 ( V_20 -> V_2 , V_83 ,
V_71 -> V_84 ) ;
F_9 ( V_20 -> V_2 , V_85 ,
V_71 -> V_86 ) ;
F_9 ( V_20 -> V_2 , V_87 ,
V_71 -> V_88 ) ;
}
static void F_23 ( struct V_19 * V_20 )
{
struct V_70 * V_71 = V_20 -> V_45 -> V_61 ;
F_9 ( V_20 -> V_2 , V_41 ,
V_71 -> V_89 ) ;
F_1 ( V_20 -> V_2 , V_90 ,
V_71 -> V_91 ) ;
F_9 ( V_20 -> V_2 , V_92 ,
V_71 -> V_93 ) ;
}
static void F_24 ( struct V_19 * V_20 )
{
T_2 V_94 ;
V_94 = F_4 ( V_20 -> V_2 , V_95 ) ;
F_1 ( V_20 -> V_2 , V_96 , V_97 ) ;
F_9 ( V_20 -> V_2 , V_98 , V_94 ) ;
F_1 ( V_20 -> V_2 , V_96 , V_99 ) ;
}
static void F_25 ( struct V_19 * V_20 )
{
T_2 V_100 , V_101 , V_102 , V_94 ;
T_3 V_103 ;
struct V_70 * V_71 = V_20 -> V_45 -> V_61 ;
V_100 = F_4 ( V_20 -> V_2 , V_104 ) ;
V_94 = F_4 ( V_20 -> V_2 , V_95 ) ;
V_103 = ( ( V_94 >> 8 ) * V_100 ) / 100 ;
F_9 ( V_20 -> V_2 , V_105 , ( T_2 ) V_103 ) ;
V_101 = ( T_2 ) V_103 ;
F_9 ( V_20 -> V_2 , V_106 , V_101 ) ;
V_102 = V_71 -> V_89 / V_107 ;
F_9 ( V_20 -> V_2 , V_108 , V_102 ) ;
F_9 ( V_20 -> V_2 , V_109 , V_110 ) ;
F_9 ( V_20 -> V_2 , V_41 ,
V_71 -> V_89 ) ;
F_1 ( V_20 -> V_2 , V_90 ,
V_71 -> V_91 ) ;
F_9 ( V_20 -> V_2 , V_92 ,
V_71 -> V_93 ) ;
}
static inline void F_26 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_70 * V_71 = V_20 -> V_45 -> V_61 ;
F_10 ( V_2 , V_111 , V_71 -> V_112 ) ;
F_10 ( V_2 , V_113 , V_71 -> V_114 ) ;
F_10 ( V_2 , V_115 , V_71 -> V_116 ) ;
F_10 ( V_2 , V_117 , V_71 -> V_118 ) ;
F_10 ( V_2 , V_119 , V_71 -> V_120 ) ;
F_10 ( V_2 , V_121 , V_71 -> V_122 ) ;
F_10 ( V_2 , V_123 ,
V_71 -> V_124 ) ;
F_10 ( V_2 , V_72 , V_71 -> V_71 ) ;
F_10 ( V_2 , V_125 , V_71 -> V_126 ) ;
F_10 ( V_2 , V_90 , V_71 -> V_91 ) ;
F_10 ( V_2 , V_87 , V_71 -> V_88 ) ;
F_10 ( V_2 , V_127 , V_71 -> V_128 ) ;
F_10 ( V_2 , V_73 , V_71 -> V_74 ) ;
F_10 ( V_2 , V_75 , V_71 -> V_76 ) ;
F_10 ( V_2 , V_77 , V_71 -> V_78 ) ;
F_10 ( V_2 , V_129 , V_71 -> V_130 ) ;
F_10 ( V_2 , V_131 , V_71 -> V_132 ) ;
F_10 ( V_2 , V_41 , V_71 -> V_89 ) ;
F_10 ( V_2 , V_92 , V_71 -> V_93 ) ;
F_10 ( V_2 , V_133 , V_71 -> V_134 ) ;
F_10 ( V_2 , V_135 , V_71 -> V_136 ) ;
F_10 ( V_2 , V_108 , V_71 -> V_137 ) ;
F_10 ( V_2 , V_109 , V_71 -> V_138 ) ;
F_10 ( V_2 , V_33 , V_71 -> V_139 ) ;
F_10 ( V_2 , V_140 , V_71 -> V_141 ) ;
F_10 ( V_2 , V_142 , V_71 -> V_143 ) ;
F_10 ( V_2 , V_144 , V_71 -> V_145 ) ;
F_10 ( V_2 , V_79 , V_71 -> V_80 ) ;
F_10 ( V_2 , V_81 , V_71 -> V_82 ) ;
F_10 ( V_2 , V_83 ,
V_71 -> V_84 ) ;
F_10 ( V_2 , V_85 , V_71 -> V_86 ) ;
}
static int F_27 ( struct V_19 * V_20 )
{
int V_5 ;
int V_18 ;
F_26 ( V_20 ) ;
F_28 ( 500 ) ;
F_21 ( V_20 ) ;
V_5 = F_17 ( V_20 ) ;
if ( V_5 ) {
F_3 ( & V_20 -> V_2 -> V_6 , L_5 ,
V_7 ) ;
return - V_54 ;
}
F_20 ( V_20 ) ;
if ( V_5 ) {
F_3 ( & V_20 -> V_2 -> V_6 , L_6 ,
V_7 ) ;
return - V_54 ;
}
F_22 ( V_20 ) ;
F_23 ( V_20 ) ;
F_28 ( 350 ) ;
F_24 ( V_20 ) ;
F_25 ( V_20 ) ;
V_18 = F_4 ( V_20 -> V_2 , V_25 ) ;
F_1 ( V_20 -> V_2 , V_25 ,
V_18 & ( ~ V_146 ) ) ;
return 0 ;
}
static void F_29 ( struct V_19 * V_20 , T_2 V_147 )
{
T_2 V_148 , V_149 ;
V_148 = F_4 ( V_20 -> V_2 , V_39 ) >> 8 ;
V_149 = ( V_148 + V_147 ) << 8 ;
V_149 |= ( V_148 - V_147 ) ;
F_1 ( V_20 -> V_2 , V_123 , V_149 ) ;
}
static T_4 F_30 ( int V_150 , void * V_6 )
{
struct V_19 * V_20 = V_6 ;
T_2 V_18 ;
V_18 = F_4 ( V_20 -> V_2 , V_25 ) ;
if ( ( V_18 & V_151 ) ||
( V_18 & V_152 ) ) {
F_16 ( & V_20 -> V_2 -> V_6 , L_7 ) ;
F_29 ( V_20 , 1 ) ;
}
F_31 ( & V_20 -> V_21 ) ;
return V_153 ;
}
static void F_32 ( struct V_154 * V_155 )
{
struct V_19 * V_20 = F_8 ( V_155 ,
struct V_19 , V_155 ) ;
int V_5 ;
if ( V_20 -> V_45 -> V_156 && V_20 -> V_45 -> V_61 ) {
V_5 = F_27 ( V_20 ) ;
if ( V_5 )
return;
}
V_20 -> V_22 = 1 ;
}
static struct V_157 *
F_33 ( struct V_158 * V_6 )
{
struct V_159 * V_160 = V_6 -> V_161 ;
T_3 V_162 ;
struct V_157 * V_45 ;
if ( ! V_160 )
return V_6 -> V_163 ;
V_45 = F_34 ( V_6 , sizeof( * V_45 ) , V_67 ) ;
if ( ! V_45 )
return NULL ;
if ( F_35 ( V_160 , L_8 , & V_162 ) == 0 ) {
V_45 -> V_48 = V_162 ;
V_45 -> V_46 = true ;
}
return V_45 ;
}
static struct V_157 *
F_33 ( struct V_158 * V_6 )
{
return V_6 -> V_163 ;
}
static int T_5 F_36 ( struct V_1 * V_2 ,
const struct V_164 * V_150 )
{
struct V_165 * V_166 = F_37 ( V_2 -> V_6 . V_167 ) ;
struct V_19 * V_20 ;
int V_5 ;
int V_3 ;
if ( ! F_38 ( V_166 , V_168 ) )
return - V_54 ;
V_20 = F_34 ( & V_2 -> V_6 , sizeof( * V_20 ) , V_67 ) ;
if ( ! V_20 )
return - V_68 ;
V_20 -> V_2 = V_2 ;
V_20 -> V_45 = F_33 ( & V_2 -> V_6 ) ;
if ( ! V_20 -> V_45 ) {
F_3 ( & V_2 -> V_6 , L_9 ) ;
return - V_49 ;
}
F_39 ( V_2 , V_20 ) ;
V_20 -> V_21 . V_169 = L_10 ;
V_20 -> V_21 . type = V_170 ;
V_20 -> V_21 . V_171 = F_7 ;
V_20 -> V_21 . V_172 = V_173 ;
V_20 -> V_21 . V_174 = F_40 ( V_173 ) ;
if ( ! V_20 -> V_45 -> V_46 )
V_20 -> V_21 . V_174 -= 2 ;
if ( V_20 -> V_45 -> V_48 == 0 )
V_20 -> V_45 -> V_48 = V_175 ;
if ( V_20 -> V_45 -> V_176 )
F_6 ( V_2 , V_20 -> V_45 -> V_176 ,
V_20 -> V_45 -> V_177 ) ;
if ( ! V_20 -> V_45 -> V_46 ) {
F_1 ( V_2 , V_115 , 0x0000 ) ;
F_1 ( V_2 , V_129 , 0x0003 ) ;
F_1 ( V_2 , V_73 , 0x0007 ) ;
}
if ( V_2 -> V_178 ) {
V_5 = F_41 ( V_2 -> V_178 , NULL ,
F_30 ,
V_179 ,
V_20 -> V_21 . V_169 , V_20 ) ;
if ( ! V_5 ) {
V_3 = F_4 ( V_2 , V_72 ) ;
V_3 |= V_180 ;
F_1 ( V_2 , V_72 , V_3 ) ;
F_29 ( V_20 , 1 ) ;
} else
F_3 ( & V_2 -> V_6 , L_11 ,
V_7 ) ;
}
V_3 = F_4 ( V_20 -> V_2 , V_25 ) ;
if ( V_3 & V_146 ) {
F_42 ( & V_20 -> V_155 , F_32 ) ;
F_43 ( & V_20 -> V_155 ) ;
} else {
V_20 -> V_22 = 1 ;
}
V_5 = F_44 ( & V_2 -> V_6 , & V_20 -> V_21 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_6 , L_12 ) ;
return V_5 ;
}
static int T_6 F_45 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_46 ( V_2 ) ;
F_47 ( & V_20 -> V_21 ) ;
return 0 ;
}
