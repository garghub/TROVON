static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 , unsigned int V_7 ,
T_1 V_8 )
{
F_4 ( V_8 , V_6 -> V_9 + V_7 ) ;
}
static void F_5 ( struct V_5 * V_6 , unsigned int V_7 ,
T_1 V_8 )
{
F_4 ( V_8 , V_6 -> V_9 + V_7 ) ;
F_4 ( V_8 , V_6 -> V_9 + V_7 + 0x1000 ) ;
}
static void F_6 ( struct V_5 * V_6 , unsigned int V_7 ,
T_1 V_8 )
{
F_4 ( V_8 , V_6 -> V_9 + V_7 + 0x2000 ) ;
}
static T_1 F_7 ( struct V_5 * V_6 , unsigned int V_7 )
{
return F_8 ( V_6 -> V_9 + V_7 ) ;
}
static void F_9 ( struct V_5 * V_6 , unsigned int V_7 ,
T_1 V_8 , T_1 V_10 )
{
T_1 V_11 = F_8 ( V_6 -> V_9 + V_7 ) ;
V_8 = ( V_8 & V_10 ) | ( V_11 & ~ V_10 ) ;
F_4 ( V_8 , V_6 -> V_9 + V_7 ) ;
}
static void F_10 ( struct V_5 * V_6 , unsigned int V_7 ,
T_1 V_8 , T_1 V_10 )
{
F_9 ( V_6 , V_7 + 0x1000 , V_8 , V_10 ) ;
}
static void F_11 ( struct V_5 * V_6 , unsigned int V_7 ,
T_1 V_8 , T_1 V_10 )
{
F_9 ( V_6 , V_7 , V_8 , V_10 ) ;
F_10 ( V_6 , V_7 , V_8 , V_10 ) ;
}
static void F_12 ( struct V_5 * V_6 ,
struct V_2 * V_4 )
{
T_2 V_12 , V_13 ;
V_12 = F_13 ( V_4 , 0 ) ;
switch ( V_6 -> V_14 . V_15 ) {
case V_16 :
case V_17 :
V_13 = V_12 + V_6 -> V_14 . V_18 * V_6 -> V_14 . V_19 ;
break;
default:
V_13 = 0 ;
}
F_6 ( V_6 , V_20 , V_12 ) ;
F_6 ( V_6 , V_21 , V_13 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
unsigned int V_22 ;
#ifdef F_15
T_1 V_23 = 7 ;
#else
T_1 V_23 = 0 ;
#endif
switch ( V_6 -> V_14 . V_15 ) {
default:
case V_16 :
case V_17 :
V_22 = 1 ;
break;
case V_24 :
V_23 ^= 1 ;
case V_25 :
V_22 = 2 ;
break;
case V_26 :
V_22 = 3 ;
break;
}
F_3 ( V_6 , V_27 , V_23 ) ;
F_5 ( V_6 , V_28 , V_6 -> V_14 . V_18 * V_22 ) ;
}
static int F_16 ( struct V_29 * V_30 , const struct V_31 * V_32 ,
unsigned int * V_33 , unsigned int * V_34 ,
unsigned int V_35 [] , void * V_36 [] )
{
struct V_5 * V_6 = F_17 ( V_30 ) ;
struct V_37 * V_14 = & V_6 -> V_14 ;
int V_38 = V_39 [ V_6 -> V_40 ] . V_41 * V_14 -> V_18 / 8 ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
if ( V_32 && V_32 -> V_32 . V_14 . V_45 < V_14 -> V_19 * V_38 )
return - V_46 ;
* V_34 = 1 ;
V_35 [ 0 ] = V_32 ? V_32 -> V_32 . V_14 . V_45 : V_14 -> V_19 * V_38 ;
V_36 [ 0 ] = V_6 -> V_47 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_17 ( V_4 -> V_29 ) ;
struct V_37 * V_14 = & V_6 -> V_14 ;
unsigned V_38 = V_39 [ V_6 -> V_40 ] . V_41 * V_14 -> V_18 / 8 ;
unsigned V_48 = V_14 -> V_19 * V_38 ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
if ( F_20 ( V_4 , 0 ) < V_48 ) {
F_21 ( V_6 -> V_42 . V_43 , L_2 ,
F_20 ( V_4 , 0 ) , V_48 ) ;
return - V_46 ;
}
F_22 ( V_4 , 0 , V_48 ) ;
return 0 ;
}
static void F_23 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_17 ( V_4 -> V_29 ) ;
struct V_1 * V_49 = F_1 ( V_4 ) ;
unsigned long V_50 ;
F_24 ( & V_6 -> V_51 , V_50 ) ;
F_25 ( & V_49 -> V_52 , & V_6 -> V_53 ) ;
F_26 ( & V_6 -> V_51 , V_50 ) ;
}
static int F_27 ( struct V_29 * V_30 , unsigned int V_54 )
{
struct V_5 * V_6 = F_17 ( V_30 ) ;
struct V_1 * V_55 , * V_56 ;
int V_57 ;
V_6 -> V_58 = 0 ;
V_57 = F_28 ( & V_6 -> V_42 , 0 ,
V_59 , V_60 , 1 ) ;
if ( V_57 < 0 && V_57 != - V_61 ) {
F_29 (buf, node, &vou_dev->buf_list, list) {
F_30 ( & V_55 -> V_4 , V_62 ) ;
F_31 ( & V_55 -> V_52 ) ;
}
V_6 -> V_63 = NULL ;
return V_57 ;
}
V_55 = F_32 ( V_6 -> V_53 . V_64 , struct V_1 , V_52 ) ;
V_6 -> V_63 = V_55 ;
F_3 ( V_6 , V_65 , 1 ) ;
F_18 ( V_6 -> V_42 . V_43 , L_3 ,
V_44 , F_7 ( V_6 , V_66 ) ) ;
F_12 ( V_6 , & V_55 -> V_4 ) ;
V_55 = F_32 ( V_55 -> V_52 . V_64 , struct V_1 , V_52 ) ;
F_3 ( V_6 , V_65 , 0 ) ;
F_12 ( V_6 , & V_55 -> V_4 ) ;
F_3 ( V_6 , V_67 , 5 ) ;
F_14 ( V_6 ) ;
F_3 ( V_6 , V_68 , 0x10004 ) ;
V_6 -> V_69 = V_70 ;
F_3 ( V_6 , V_71 , 0x107 ) ;
return 0 ;
}
static void F_33 ( struct V_29 * V_30 )
{
struct V_5 * V_6 = F_17 ( V_30 ) ;
struct V_1 * V_55 , * V_56 ;
unsigned long V_50 ;
F_28 ( & V_6 -> V_42 , 0 ,
V_59 , V_60 , 0 ) ;
F_9 ( V_6 , V_71 , 0 , 1 ) ;
F_9 ( V_6 , V_68 , 0 , 0x30000 ) ;
F_34 ( 50 ) ;
F_24 ( & V_6 -> V_51 , V_50 ) ;
F_29 (buf, node, &vou_dev->buf_list, list) {
F_30 ( & V_55 -> V_4 , V_72 ) ;
F_31 ( & V_55 -> V_52 ) ;
}
V_6 -> V_63 = NULL ;
F_26 ( & V_6 -> V_51 , V_50 ) ;
}
static int F_35 ( struct V_73 * V_73 , void * V_74 ,
struct V_75 * V_76 )
{
struct V_5 * V_6 = F_36 ( V_73 ) ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
F_37 ( V_76 -> V_77 , L_4 , sizeof( V_76 -> V_77 ) ) ;
F_37 ( V_76 -> V_78 , L_5 , sizeof( V_76 -> V_78 ) ) ;
F_37 ( V_76 -> V_79 , L_6 , sizeof( V_76 -> V_79 ) ) ;
V_76 -> V_80 = V_81 | V_82 |
V_83 ;
V_76 -> V_84 = V_76 -> V_80 | V_85 ;
return 0 ;
}
static int F_38 ( struct V_73 * V_73 , void * V_74 ,
struct V_86 * V_32 )
{
struct V_5 * V_6 = F_36 ( V_73 ) ;
if ( V_32 -> V_87 >= F_39 ( V_39 ) )
return - V_46 ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
V_32 -> type = V_88 ;
F_37 ( V_32 -> V_89 , V_39 [ V_32 -> V_87 ] . V_90 ,
sizeof( V_32 -> V_89 ) ) ;
V_32 -> V_15 = V_39 [ V_32 -> V_87 ] . V_91 ;
return 0 ;
}
static int F_40 ( struct V_73 * V_73 , void * V_74 ,
struct V_31 * V_32 )
{
struct V_5 * V_6 = F_36 ( V_73 ) ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
V_32 -> type = V_88 ;
V_32 -> V_32 . V_14 = V_6 -> V_14 ;
return 0 ;
}
static void F_41 ( struct V_5 * V_6 ,
int V_40 , int V_92 , int V_93 )
{
struct V_94 * V_32 = V_39 + V_40 ;
unsigned int V_95 , V_96 , V_97 ,
V_98 , V_99 , V_100 ;
struct V_101 * V_102 = & V_6 -> V_102 ;
struct V_37 * V_14 = & V_6 -> V_14 ;
T_1 V_103 = 0 , V_104 , V_105 ;
if ( V_6 -> V_106 & V_107 ) {
V_97 = 858 ;
} else {
V_97 = 864 ;
}
V_98 = V_14 -> V_19 / 2 ;
V_99 = V_102 -> V_19 / 2 ;
V_100 = V_102 -> V_108 / 2 ;
V_95 = V_97 - V_109 ;
V_96 = 20 ;
V_104 = V_102 -> V_18 + V_102 -> V_110 ;
V_105 = V_99 + V_100 ;
F_18 ( V_6 -> V_42 . V_43 ,
L_7 ,
V_14 -> V_18 , V_98 , V_95 , V_96 ,
V_102 -> V_110 , V_100 , V_104 , V_105 ) ;
F_5 ( V_6 , V_111 , ( V_14 -> V_18 << 16 ) | V_98 ) ;
F_5 ( V_6 , V_112 , ( V_95 << 16 ) | V_96 ) ;
F_5 ( V_6 , V_113 , ( V_102 -> V_110 << 16 ) | V_100 ) ;
F_5 ( V_6 , V_114 , ( V_104 << 16 ) | V_105 ) ;
if ( V_92 )
V_103 |= ( 1 << 15 ) | ( V_115 [ V_92 - 1 ] << 4 ) ;
if ( V_93 )
V_103 |= ( 1 << 14 ) | V_116 [ V_93 - 1 ] ;
F_18 ( V_6 -> V_42 . V_43 , L_8 , V_32 -> V_90 , V_103 ) ;
F_5 ( V_6 , V_117 , V_103 ) ;
F_5 ( V_6 , V_118 ,
V_32 -> V_119 | ( V_32 -> V_120 << 8 ) | ( V_32 -> V_121 << 16 ) ) ;
}
static void F_42 ( struct V_122 * V_123 , T_3 V_106 )
{
unsigned int V_124 = V_125 , V_126 = 0 , V_127 ;
int V_128 , V_129 = 0 ;
if ( V_106 & V_107 )
V_127 = 480 ;
else
V_127 = 576 ;
F_43 ( & V_123 -> V_130 ,
V_131 , V_109 , 2 ,
& V_123 -> V_132 ,
V_133 , V_127 , 1 , 0 ) ;
for ( V_128 = F_39 ( V_134 ) - 1 ; V_128 >= 0 ; V_128 -- ) {
unsigned int V_135 ;
unsigned int V_136 = V_123 -> V_137 . V_18 * V_138 [ V_128 ] /
V_134 [ V_128 ] ;
if ( V_136 > V_109 )
break;
V_135 = abs ( V_136 - V_123 -> V_130 ) ;
if ( V_135 < V_124 ) {
V_124 = V_135 ;
V_129 = V_128 ;
V_126 = V_136 ;
}
if ( ! V_135 )
break;
}
V_123 -> V_130 = V_126 ;
V_123 -> V_139 = V_129 ;
V_124 = V_125 ;
for ( V_128 = F_39 ( V_140 ) - 1 ; V_128 >= 0 ; V_128 -- ) {
unsigned int V_135 ;
unsigned int V_136 = V_123 -> V_137 . V_19 * V_141 [ V_128 ] /
V_140 [ V_128 ] ;
if ( V_136 > V_127 )
break;
V_135 = abs ( V_136 - V_123 -> V_132 ) ;
if ( V_135 < V_124 ) {
V_124 = V_135 ;
V_129 = V_128 ;
V_126 = V_136 ;
}
if ( ! V_135 )
break;
}
V_123 -> V_132 = V_126 ;
V_123 -> V_142 = V_129 ;
}
static void F_44 ( struct V_122 * V_123 , T_3 V_106 )
{
unsigned int V_124 = V_125 , V_126 = V_123 -> V_130 ,
V_97 , V_143 , V_127 ;
int V_128 , V_144 = 0 , V_145 = 0 ;
if ( V_106 & V_107 ) {
V_97 = 858 ;
V_143 = 262 * 2 ;
V_127 = 480 ;
} else {
V_97 = 864 ;
V_143 = 312 * 2 ;
V_127 = 576 ;
}
for ( V_128 = 0 ; V_128 < F_39 ( V_134 ) ; V_128 ++ ) {
unsigned int V_135 ;
unsigned int V_136 = V_123 -> V_130 * V_134 [ V_128 ] /
V_138 [ V_128 ] ;
if ( V_136 > V_109 )
break;
V_135 = abs ( V_136 - V_123 -> V_137 . V_18 ) ;
if ( V_135 < V_124 ) {
V_124 = V_135 ;
V_144 = V_128 ;
V_126 = V_136 ;
}
if ( ! V_135 )
break;
}
V_123 -> V_137 . V_18 = V_126 ;
V_123 -> V_139 = V_144 ;
if ( V_123 -> V_137 . V_110 + V_126 > V_97 )
V_123 -> V_137 . V_110 = V_97 - V_126 ;
F_45 ( L_9 , V_44 , V_123 -> V_130 ,
V_134 [ V_144 ] , V_138 [ V_144 ] , V_126 ) ;
V_124 = V_125 ;
for ( V_128 = 0 ; V_128 < F_39 ( V_140 ) ; V_128 ++ ) {
unsigned int V_135 ;
unsigned int V_136 = V_123 -> V_132 * V_140 [ V_128 ] /
V_141 [ V_128 ] ;
if ( V_136 > V_127 )
break;
V_135 = abs ( V_136 - V_123 -> V_137 . V_19 ) ;
if ( V_135 < V_124 ) {
V_124 = V_135 ;
V_145 = V_128 ;
V_126 = V_136 ;
}
if ( ! V_135 )
break;
}
V_123 -> V_137 . V_19 = V_126 ;
V_123 -> V_142 = V_145 ;
if ( V_123 -> V_137 . V_108 + V_126 > V_143 )
V_123 -> V_137 . V_108 = V_143 - V_126 ;
F_45 ( L_10 , V_44 , V_123 -> V_132 ,
V_140 [ V_145 ] , V_141 [ V_145 ] , V_126 ) ;
}
static int F_46 ( struct V_73 * V_73 , void * V_74 ,
struct V_31 * V_32 )
{
struct V_5 * V_6 = F_36 ( V_73 ) ;
struct V_37 * V_14 = & V_32 -> V_32 . V_14 ;
unsigned int V_127 ;
int V_40 ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
V_14 -> V_146 = V_147 ;
V_14 -> V_148 = V_149 ;
V_14 -> V_150 = V_14 -> V_151 = 0 ;
for ( V_40 = 0 ; V_40 < F_39 ( V_39 ) ; V_40 ++ )
if ( V_39 [ V_40 ] . V_91 == V_14 -> V_15 )
break;
if ( V_40 == F_39 ( V_39 ) )
return - V_46 ;
if ( V_6 -> V_106 & V_107 )
V_127 = 480 ;
else
V_127 = 576 ;
F_43 ( & V_14 -> V_18 ,
V_131 , V_109 , 2 ,
& V_14 -> V_19 ,
V_133 , V_127 , 1 , 0 ) ;
V_14 -> V_152 = V_14 -> V_18 * V_39 [ V_40 ] . V_153 ;
V_14 -> V_45 = V_14 -> V_19 * ( ( V_14 -> V_18 * V_39 [ V_40 ] . V_41 ) >> 3 ) ;
return 0 ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_37 * V_14 )
{
unsigned int V_127 ;
struct V_122 V_123 ;
struct V_154 V_155 = {
. V_156 = V_157 ,
. V_155 . V_158 = V_159 ,
. V_155 . V_146 = V_147 ,
. V_155 . V_148 = V_149 ,
} ;
struct V_160 * V_161 = & V_155 . V_155 ;
int V_40 ;
int V_57 ;
if ( F_48 ( & V_6 -> V_162 ) )
return - V_163 ;
for ( V_40 = 0 ; V_40 < F_39 ( V_39 ) ; V_40 ++ )
if ( V_39 [ V_40 ] . V_91 == V_14 -> V_15 )
break;
V_123 . V_130 = V_14 -> V_18 ;
V_123 . V_132 = V_14 -> V_19 ;
V_123 . V_137 = V_6 -> V_102 ;
F_44 ( & V_123 , V_6 -> V_106 ) ;
V_161 -> V_18 = V_123 . V_137 . V_18 ;
V_161 -> V_19 = V_123 . V_137 . V_19 ;
V_57 = F_28 ( & V_6 -> V_42 , 0 , V_164 ,
V_165 , NULL , & V_155 ) ;
if ( V_57 < 0 )
return V_57 ;
F_18 ( V_6 -> V_42 . V_43 , L_11 , V_44 ,
V_123 . V_137 . V_18 , V_123 . V_137 . V_19 , V_161 -> V_18 , V_161 -> V_19 ) ;
if ( V_6 -> V_106 & V_107 )
V_127 = 480 ;
else
V_127 = 576 ;
if ( ( unsigned ) V_161 -> V_18 > V_109 ||
( unsigned ) V_161 -> V_19 > V_127 ||
V_161 -> V_158 != V_159 )
return - V_166 ;
if ( V_161 -> V_18 != V_123 . V_137 . V_18 ||
V_161 -> V_19 != V_123 . V_137 . V_19 ) {
V_123 . V_137 . V_18 = V_161 -> V_18 ;
V_123 . V_137 . V_19 = V_161 -> V_19 ;
F_42 ( & V_123 , V_6 -> V_106 ) ;
}
V_6 -> V_102 = V_123 . V_137 ;
V_14 -> V_18 = V_123 . V_130 ;
V_14 -> V_19 = V_123 . V_132 ;
F_18 ( V_6 -> V_42 . V_43 , L_12 , V_44 ,
V_14 -> V_18 , V_14 -> V_19 ) ;
V_6 -> V_40 = V_40 ;
V_6 -> V_14 = * V_14 ;
F_41 ( V_6 , V_40 ,
V_123 . V_139 , V_123 . V_142 ) ;
return 0 ;
}
static int F_49 ( struct V_73 * V_73 , void * V_74 ,
struct V_31 * V_32 )
{
struct V_5 * V_6 = F_36 ( V_73 ) ;
int V_57 = F_46 ( V_73 , V_74 , V_32 ) ;
if ( V_57 )
return V_57 ;
return F_47 ( V_6 , & V_32 -> V_32 . V_14 ) ;
}
static int F_50 ( struct V_73 * V_73 , void * V_167 ,
struct V_168 * V_169 )
{
struct V_5 * V_6 = F_36 ( V_73 ) ;
if ( V_169 -> V_87 )
return - V_46 ;
F_37 ( V_169 -> V_170 , L_13 , sizeof( V_169 -> V_170 ) ) ;
V_169 -> type = V_171 ;
V_169 -> V_106 = V_6 -> V_172 . V_173 ;
return 0 ;
}
static int F_51 ( struct V_73 * V_73 , void * V_167 , unsigned int * V_128 )
{
* V_128 = 0 ;
return 0 ;
}
static int F_52 ( struct V_73 * V_73 , void * V_167 , unsigned int V_128 )
{
return V_128 ? - V_46 : 0 ;
}
static T_1 F_53 ( enum V_174 V_175 )
{
switch ( V_175 ) {
default:
F_54 ( L_14 ,
V_44 , V_175 ) ;
case V_176 :
return 1 ;
case V_177 :
return 0 ;
case V_178 :
return 3 ;
}
}
static int F_55 ( struct V_73 * V_73 , void * V_74 , T_3 V_179 )
{
struct V_5 * V_6 = F_36 ( V_73 ) ;
int V_57 ;
F_18 ( V_6 -> V_42 . V_43 , L_15 , V_44 , V_179 ) ;
if ( V_179 == V_6 -> V_106 )
return 0 ;
if ( F_48 ( & V_6 -> V_162 ) )
return - V_163 ;
V_57 = F_28 ( & V_6 -> V_42 , 0 , V_59 ,
V_180 , V_179 ) ;
if ( V_57 < 0 && V_57 != - V_61 )
return V_57 ;
V_6 -> V_102 . V_108 = V_6 -> V_102 . V_110 = 0 ;
V_6 -> V_102 . V_18 = V_109 ;
if ( V_179 & V_107 ) {
F_11 ( V_6 , V_181 ,
F_53 ( V_6 -> V_182 -> V_175 ) << 29 , 7 << 29 ) ;
V_6 -> V_102 . V_19 = 480 ;
} else {
F_11 ( V_6 , V_181 , 5 << 29 , 7 << 29 ) ;
V_6 -> V_102 . V_19 = 576 ;
}
V_6 -> V_14 . V_18 = V_6 -> V_102 . V_18 ;
V_6 -> V_14 . V_19 = V_6 -> V_102 . V_19 ;
V_6 -> V_14 . V_152 =
V_6 -> V_14 . V_18 * V_39 [ V_6 -> V_40 ] . V_153 ;
V_6 -> V_14 . V_45 = V_6 -> V_14 . V_19 *
( ( V_6 -> V_14 . V_18 * V_39 [ V_6 -> V_40 ] . V_41 ) >> 3 ) ;
V_6 -> V_106 = V_179 ;
F_47 ( V_6 , & V_6 -> V_14 ) ;
return 0 ;
}
static int F_56 ( struct V_73 * V_73 , void * V_74 , T_3 * V_106 )
{
struct V_5 * V_6 = F_36 ( V_73 ) ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
* V_106 = V_6 -> V_106 ;
return 0 ;
}
static int F_57 ( struct V_73 * V_73 , void * V_74 )
{
struct V_5 * V_6 = F_36 ( V_73 ) ;
F_58 ( L_16 , F_7 ( V_6 , V_71 ) ) ;
F_58 ( L_17 , F_7 ( V_6 , V_181 ) ) ;
F_58 ( L_18 , F_7 ( V_6 , V_66 ) ) ;
F_58 ( L_19 , F_7 ( V_6 , V_117 ) ) ;
F_58 ( L_20 , F_7 ( V_6 , V_111 ) ) ;
F_58 ( L_21 , F_7 ( V_6 , V_183 ) ) ;
F_58 ( L_22 , F_7 ( V_6 , V_113 ) ) ;
F_58 ( L_23 , F_7 ( V_6 , V_114 ) ) ;
F_58 ( L_24 , F_7 ( V_6 , V_112 ) ) ;
F_58 ( L_25 , F_7 ( V_6 , V_68 ) ) ;
F_58 ( L_26 , F_7 ( V_6 , V_184 ) ) ;
F_58 ( L_27 , F_7 ( V_6 , V_185 ) ) ;
F_58 ( L_28 , F_7 ( V_6 , V_186 ) ) ;
F_58 ( L_29 , F_7 ( V_6 , V_118 ) ) ;
F_58 ( L_30 , F_7 ( V_6 , V_20 ) ) ;
F_58 ( L_31 , F_7 ( V_6 , V_21 ) ) ;
F_58 ( L_32 , F_7 ( V_6 , V_28 ) ) ;
F_58 ( L_33 , F_7 ( V_6 , V_27 ) ) ;
F_58 ( L_34 , F_7 ( V_6 , V_67 ) ) ;
F_58 ( L_35 , F_7 ( V_6 , V_65 ) ) ;
return 0 ;
}
static int F_59 ( struct V_73 * V_73 , void * V_167 ,
struct V_187 * V_188 )
{
struct V_5 * V_6 = F_36 ( V_73 ) ;
if ( V_188 -> type != V_88 )
return - V_46 ;
switch ( V_188 -> V_189 ) {
case V_190 :
V_188 -> V_191 = V_6 -> V_102 ;
break;
case V_192 :
case V_193 :
V_188 -> V_191 . V_110 = 0 ;
V_188 -> V_191 . V_108 = 0 ;
V_188 -> V_191 . V_18 = V_109 ;
if ( V_6 -> V_106 & V_107 )
V_188 -> V_191 . V_19 = 480 ;
else
V_188 -> V_191 . V_19 = 576 ;
break;
default:
return - V_46 ;
}
return 0 ;
}
static int F_60 ( struct V_73 * V_73 , void * V_167 ,
struct V_187 * V_188 )
{
struct V_101 * V_102 = & V_188 -> V_191 ;
struct V_5 * V_6 = F_36 ( V_73 ) ;
struct V_194 V_195 = { . type = V_88 } ;
struct V_37 * V_14 = & V_6 -> V_14 ;
struct V_122 V_123 ;
struct V_154 V_155 = {
. V_156 = V_157 ,
. V_155 . V_158 = V_159 ,
. V_155 . V_146 = V_147 ,
. V_155 . V_148 = V_149 ,
} ;
unsigned int V_127 ;
int V_57 ;
if ( V_188 -> type != V_88 ||
V_188 -> V_189 != V_190 )
return - V_46 ;
if ( F_48 ( & V_6 -> V_162 ) )
return - V_163 ;
if ( V_6 -> V_106 & V_107 )
V_127 = 480 ;
else
V_127 = 576 ;
F_43 ( & V_102 -> V_18 ,
V_131 , V_109 , 1 ,
& V_102 -> V_19 ,
V_133 , V_127 , 1 , 0 ) ;
if ( V_102 -> V_18 + V_102 -> V_110 > V_109 )
V_102 -> V_110 = V_109 - V_102 -> V_18 ;
if ( V_102 -> V_19 + V_102 -> V_108 > V_127 )
V_102 -> V_108 = V_127 - V_102 -> V_19 ;
V_123 . V_137 = * V_102 ;
V_123 . V_130 = V_14 -> V_18 ;
V_123 . V_132 = V_14 -> V_19 ;
V_195 . V_196 . V_18 = V_123 . V_137 . V_18 ;
V_195 . V_196 . V_19 = V_123 . V_137 . V_19 ;
F_28 ( & V_6 -> V_42 , 0 , V_59 ,
V_197 , & V_195 ) ;
V_155 . V_155 . V_18 = V_123 . V_137 . V_18 ;
V_155 . V_155 . V_19 = V_123 . V_137 . V_19 ;
V_57 = F_28 ( & V_6 -> V_42 , 0 , V_164 ,
V_165 , NULL , & V_155 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ( unsigned ) V_155 . V_155 . V_18 > V_109 ||
( unsigned ) V_155 . V_155 . V_19 > V_127 ||
V_155 . V_155 . V_158 != V_159 )
return - V_166 ;
V_123 . V_137 . V_18 = V_155 . V_155 . V_18 ;
V_123 . V_137 . V_19 = V_155 . V_155 . V_19 ;
F_42 ( & V_123 , V_6 -> V_106 ) ;
V_6 -> V_102 = V_123 . V_137 ;
V_14 -> V_18 = V_123 . V_130 ;
V_14 -> V_19 = V_123 . V_132 ;
F_41 ( V_6 , V_6 -> V_40 ,
V_123 . V_139 , V_123 . V_142 ) ;
return 0 ;
}
static T_4 F_61 ( int V_198 , void * V_199 )
{
struct V_5 * V_6 = V_199 ;
static unsigned long V_200 ;
struct V_1 * V_4 ;
static int V_201 ;
T_1 V_202 = F_7 ( V_6 , V_68 ) , V_203 ;
T_1 V_204 = F_7 ( V_6 , V_66 ) ;
if ( ! ( V_202 & 0x300 ) ) {
if ( F_62 ( & V_200 , 500 ) )
F_21 ( V_6 -> V_42 . V_43 , L_36 ,
V_202 ) ;
return V_205 ;
}
F_63 ( & V_6 -> V_51 ) ;
if ( ! V_6 -> V_63 || F_64 ( & V_6 -> V_53 ) ) {
if ( F_62 ( & V_200 , 500 ) )
F_21 ( V_6 -> V_42 . V_43 ,
L_37 , V_202 ) ;
F_9 ( V_6 , V_68 , 0 , 0x300 ) ;
F_65 ( & V_6 -> V_51 ) ;
return V_206 ;
}
V_203 = ~ ( 0x300 & V_202 ) & V_202 & 0x30304 ;
F_18 ( V_6 -> V_42 . V_43 ,
L_38 ,
V_202 , V_203 , V_204 , V_201 ) ;
V_201 ++ ;
F_3 ( V_6 , V_68 , V_203 ) ;
V_4 = V_6 -> V_63 ;
if ( F_66 ( & V_4 -> V_52 ) ) {
F_12 ( V_6 , & V_4 -> V_4 ) ;
F_65 ( & V_6 -> V_51 ) ;
return V_206 ;
}
F_31 ( & V_4 -> V_52 ) ;
F_67 ( & V_4 -> V_4 . V_207 . V_208 ) ;
V_4 -> V_4 . V_207 . V_58 = V_6 -> V_58 ++ ;
V_4 -> V_4 . V_207 . V_146 = V_147 ;
F_30 ( & V_4 -> V_4 , V_209 ) ;
V_6 -> V_63 = F_32 ( V_6 -> V_53 . V_64 ,
struct V_1 , V_52 ) ;
if ( F_66 ( & V_6 -> V_53 ) ) {
F_12 ( V_6 , & V_6 -> V_63 -> V_4 ) ;
} else {
struct V_1 * V_210 = F_32 ( V_6 -> V_63 -> V_52 . V_64 ,
struct V_1 , V_52 ) ;
F_12 ( V_6 , & V_210 -> V_4 ) ;
}
F_65 ( & V_6 -> V_51 ) ;
return V_206 ;
}
static int F_68 ( struct V_5 * V_6 )
{
struct V_211 * V_182 = V_6 -> V_182 ;
T_1 V_212 = F_53 ( V_182 -> V_175 ) << 29 ;
int V_128 = 100 ;
F_3 ( V_6 , V_68 , 0 ) ;
F_3 ( V_6 , V_184 , 0x101 ) ;
while ( -- V_128 && ( F_7 ( V_6 , V_184 ) & 0x101 ) )
F_69 ( 1 ) ;
if ( ! V_128 )
return - V_213 ;
F_18 ( V_6 -> V_42 . V_43 , L_39 , 100 - V_128 ) ;
if ( V_182 -> V_50 & V_214 )
V_212 |= 1 << 28 ;
if ( V_182 -> V_50 & V_215 )
V_212 |= 1 << 27 ;
if ( V_182 -> V_50 & V_216 )
V_212 |= 1 << 26 ;
F_11 ( V_6 , V_181 , V_212 , 0xfc000000 ) ;
F_3 ( V_6 , V_67 , 4 ) ;
F_5 ( V_6 , V_185 , 0x800000 ) ;
F_47 ( V_6 , & V_6 -> V_14 ) ;
return 0 ;
}
static int F_70 ( struct V_73 * V_73 )
{
struct V_5 * V_6 = F_36 ( V_73 ) ;
int V_135 ;
if ( F_71 ( & V_6 -> V_217 ) )
return - V_218 ;
V_135 = F_72 ( V_73 ) ;
if ( V_135 )
goto V_219;
if ( F_73 ( V_73 ) &&
V_6 -> V_69 == V_220 ) {
F_74 ( V_6 -> V_42 . V_43 ) ;
V_135 = F_68 ( V_6 ) ;
if ( V_135 < 0 ) {
F_75 ( V_6 -> V_42 . V_43 ) ;
F_76 ( V_73 ) ;
} else {
V_6 -> V_69 = V_221 ;
}
}
V_219:
F_77 ( & V_6 -> V_217 ) ;
return V_135 ;
}
static int F_78 ( struct V_73 * V_73 )
{
struct V_5 * V_6 = F_36 ( V_73 ) ;
bool V_222 ;
F_79 ( & V_6 -> V_217 ) ;
V_222 = F_73 ( V_73 ) ;
F_80 ( V_73 , NULL ) ;
if ( V_222 ) {
V_6 -> V_69 = V_220 ;
F_9 ( V_6 , V_71 , 0 , 0x101 ) ;
F_75 ( V_6 -> V_42 . V_43 ) ;
}
F_77 ( & V_6 -> V_217 ) ;
return 0 ;
}
static int F_81 ( struct V_223 * V_224 )
{
struct V_211 * V_225 = V_224 -> V_43 . V_226 ;
struct V_101 * V_102 ;
struct V_37 * V_14 ;
struct V_227 * V_228 ;
struct V_229 * V_172 ;
struct V_5 * V_6 ;
struct V_230 * V_231 ;
struct V_232 * V_233 ;
struct V_29 * V_234 ;
int V_198 , V_57 ;
V_231 = F_82 ( V_224 , V_235 , 0 ) ;
V_198 = F_83 ( V_224 , 0 ) ;
if ( ! V_225 || ! V_231 || V_198 <= 0 ) {
F_84 ( & V_224 -> V_43 , L_40 ) ;
return - V_236 ;
}
V_6 = F_85 ( & V_224 -> V_43 , sizeof( * V_6 ) , V_237 ) ;
if ( ! V_6 )
return - V_238 ;
F_86 ( & V_6 -> V_53 ) ;
F_87 ( & V_6 -> V_51 ) ;
F_88 ( & V_6 -> V_217 ) ;
V_6 -> V_182 = V_225 ;
V_6 -> V_69 = V_220 ;
V_6 -> V_40 = 1 ;
V_102 = & V_6 -> V_102 ;
V_14 = & V_6 -> V_14 ;
V_6 -> V_106 = V_239 ;
V_102 -> V_110 = 0 ;
V_102 -> V_108 = 0 ;
V_102 -> V_18 = V_109 ;
V_102 -> V_19 = 480 ;
V_14 -> V_18 = V_109 ;
V_14 -> V_19 = 480 ;
V_14 -> V_15 = V_17 ;
V_14 -> V_146 = V_147 ;
V_14 -> V_152 = V_109 ;
V_14 -> V_45 = V_109 * 2 * 480 ;
V_14 -> V_148 = V_149 ;
V_6 -> V_9 = F_89 ( & V_224 -> V_43 , V_231 ) ;
if ( F_90 ( V_6 -> V_9 ) )
return F_91 ( V_6 -> V_9 ) ;
V_57 = F_92 ( & V_224 -> V_43 , V_198 , F_61 , 0 , L_41 , V_6 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_93 ( & V_224 -> V_43 , & V_6 -> V_42 ) ;
if ( V_57 < 0 ) {
F_84 ( & V_224 -> V_43 , L_42 ) ;
return V_57 ;
}
V_172 = & V_6 -> V_172 ;
* V_172 = V_240 ;
if ( V_225 -> V_175 == V_176 )
V_172 -> V_173 |= V_241 ;
V_172 -> V_42 = & V_6 -> V_42 ;
V_172 -> V_242 = V_243 ;
V_172 -> V_51 = & V_6 -> V_217 ;
F_94 ( V_172 , V_6 ) ;
V_234 = & V_6 -> V_162 ;
V_234 -> type = V_88 ;
V_234 -> V_244 = V_245 | V_246 | V_247 ;
V_234 -> V_248 = V_6 ;
V_234 -> V_249 = sizeof( struct V_1 ) ;
V_234 -> V_250 = & V_251 ;
V_234 -> V_252 = & V_253 ;
V_234 -> V_254 = V_255 ;
V_234 -> V_256 = 2 ;
V_234 -> V_51 = & V_6 -> V_217 ;
V_57 = F_95 ( V_234 ) ;
if ( V_57 )
goto V_257;
V_6 -> V_47 = F_96 ( & V_224 -> V_43 ) ;
if ( F_90 ( V_6 -> V_47 ) ) {
F_84 ( & V_224 -> V_43 , L_43 ) ;
V_57 = F_91 ( V_6 -> V_47 ) ;
goto V_257;
}
V_172 -> V_162 = V_234 ;
F_86 ( & V_6 -> V_53 ) ;
F_97 ( & V_224 -> V_43 ) ;
F_98 ( & V_224 -> V_43 ) ;
V_228 = F_99 ( V_225 -> V_228 ) ;
if ( ! V_228 ) {
V_57 = - V_236 ;
goto V_258;
}
V_57 = F_68 ( V_6 ) ;
if ( V_57 < 0 )
goto V_259;
V_233 = F_100 ( & V_6 -> V_42 , V_228 ,
V_225 -> V_260 , NULL ) ;
if ( ! V_233 ) {
V_57 = - V_238 ;
goto V_261;
}
V_57 = F_101 ( V_172 , V_262 , - 1 ) ;
if ( V_57 < 0 )
goto V_263;
return 0 ;
V_263:
V_261:
V_259:
F_102 ( V_228 ) ;
V_258:
F_103 ( V_6 -> V_47 ) ;
V_257:
F_104 ( & V_224 -> V_43 ) ;
F_105 ( & V_6 -> V_42 ) ;
return V_57 ;
}
static int F_106 ( struct V_223 * V_224 )
{
struct V_264 * V_42 = F_107 ( V_224 ) ;
struct V_5 * V_6 = F_2 ( V_42 ,
struct V_5 , V_42 ) ;
struct V_232 * V_265 = F_32 ( V_42 -> V_266 . V_64 ,
struct V_232 , V_52 ) ;
struct V_267 * V_268 = F_108 ( V_265 ) ;
F_104 ( & V_224 -> V_43 ) ;
F_109 ( & V_6 -> V_172 ) ;
F_102 ( V_268 -> V_269 ) ;
F_103 ( V_6 -> V_47 ) ;
F_105 ( & V_6 -> V_42 ) ;
return 0 ;
}
