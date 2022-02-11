static inline struct
V_1 * F_1 ( struct V_2 * V_3 )
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
struct V_2 * V_12 )
{
T_2 V_13 , V_14 ;
V_13 = F_13 ( & V_12 -> V_15 , 0 ) ;
switch ( V_6 -> V_16 . V_17 ) {
case V_18 :
case V_19 :
V_14 = V_13 + V_6 -> V_16 . V_20 * V_6 -> V_16 . V_21 ;
break;
default:
V_14 = 0 ;
}
F_6 ( V_6 , V_22 , V_13 ) ;
F_6 ( V_6 , V_23 , V_14 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
unsigned int V_24 ;
#ifdef F_15
T_1 V_25 = 7 ;
#else
T_1 V_25 = 0 ;
#endif
switch ( V_6 -> V_16 . V_17 ) {
default:
case V_18 :
case V_19 :
V_24 = 1 ;
break;
case V_26 :
V_25 ^= 1 ;
case V_27 :
V_24 = 2 ;
break;
case V_28 :
V_24 = 3 ;
break;
}
F_3 ( V_6 , V_29 , V_25 ) ;
F_5 ( V_6 , V_30 , V_6 -> V_16 . V_20 * V_24 ) ;
}
static int F_16 ( struct V_31 * V_32 ,
unsigned int * V_33 , unsigned int * V_34 ,
unsigned int V_35 [] , void * V_36 [] )
{
struct V_5 * V_6 = F_17 ( V_32 ) ;
struct V_37 * V_16 = & V_6 -> V_16 ;
int V_38 = V_39 [ V_6 -> V_40 ] . V_41 * V_16 -> V_20 / 8 ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
V_36 [ 0 ] = V_6 -> V_45 ;
if ( * V_34 )
return V_35 [ 0 ] < V_16 -> V_21 * V_38 ? - V_46 : 0 ;
* V_34 = 1 ;
V_35 [ 0 ] = V_16 -> V_21 * V_38 ;
return 0 ;
}
static int F_19 ( struct V_47 * V_4 )
{
struct V_5 * V_6 = F_17 ( V_4 -> V_31 ) ;
struct V_37 * V_16 = & V_6 -> V_16 ;
unsigned V_38 = V_39 [ V_6 -> V_40 ] . V_41 * V_16 -> V_20 / 8 ;
unsigned V_48 = V_16 -> V_21 * V_38 ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
if ( F_20 ( V_4 , 0 ) < V_48 ) {
F_21 ( V_6 -> V_42 . V_43 , L_2 ,
F_20 ( V_4 , 0 ) , V_48 ) ;
return - V_46 ;
}
F_22 ( V_4 , 0 , V_48 ) ;
return 0 ;
}
static void F_23 ( struct V_47 * V_4 )
{
struct V_2 * V_12 = F_24 ( V_4 ) ;
struct V_5 * V_6 = F_17 ( V_4 -> V_31 ) ;
struct V_1 * V_49 = F_1 ( V_12 ) ;
unsigned long V_50 ;
F_25 ( & V_6 -> V_51 , V_50 ) ;
F_26 ( & V_49 -> V_52 , & V_6 -> V_53 ) ;
F_27 ( & V_6 -> V_51 , V_50 ) ;
}
static int F_28 ( struct V_31 * V_32 , unsigned int V_54 )
{
struct V_5 * V_6 = F_17 ( V_32 ) ;
struct V_1 * V_55 , * V_56 ;
int V_57 ;
V_6 -> V_58 = 0 ;
V_57 = F_29 ( & V_6 -> V_42 , 0 ,
V_59 , V_60 , 1 ) ;
if ( V_57 < 0 && V_57 != - V_61 ) {
F_30 (buf, node, &vou_dev->buf_list, list) {
F_31 ( & V_55 -> V_4 . V_15 ,
V_62 ) ;
F_32 ( & V_55 -> V_52 ) ;
}
V_6 -> V_63 = NULL ;
return V_57 ;
}
V_55 = F_33 ( V_6 -> V_53 . V_64 , struct V_1 , V_52 ) ;
V_6 -> V_63 = V_55 ;
F_3 ( V_6 , V_65 , 1 ) ;
F_18 ( V_6 -> V_42 . V_43 , L_3 ,
V_44 , F_7 ( V_6 , V_66 ) ) ;
F_12 ( V_6 , & V_55 -> V_4 ) ;
V_55 = F_33 ( V_55 -> V_52 . V_64 , struct V_1 , V_52 ) ;
F_3 ( V_6 , V_65 , 0 ) ;
F_12 ( V_6 , & V_55 -> V_4 ) ;
F_3 ( V_6 , V_67 , 5 ) ;
F_14 ( V_6 ) ;
F_3 ( V_6 , V_68 , 0x10004 ) ;
V_6 -> V_69 = V_70 ;
F_3 ( V_6 , V_71 , 0x107 ) ;
return 0 ;
}
static void F_34 ( struct V_31 * V_32 )
{
struct V_5 * V_6 = F_17 ( V_32 ) ;
struct V_1 * V_55 , * V_56 ;
unsigned long V_50 ;
F_29 ( & V_6 -> V_42 , 0 ,
V_59 , V_60 , 0 ) ;
F_9 ( V_6 , V_71 , 0 , 1 ) ;
F_9 ( V_6 , V_68 , 0 , 0x30000 ) ;
F_35 ( 50 ) ;
F_25 ( & V_6 -> V_51 , V_50 ) ;
F_30 (buf, node, &vou_dev->buf_list, list) {
F_31 ( & V_55 -> V_4 . V_15 , V_72 ) ;
F_32 ( & V_55 -> V_52 ) ;
}
V_6 -> V_63 = NULL ;
F_27 ( & V_6 -> V_51 , V_50 ) ;
}
static int F_36 ( struct V_73 * V_73 , void * V_74 ,
struct V_75 * V_76 )
{
struct V_5 * V_6 = F_37 ( V_73 ) ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
F_38 ( V_76 -> V_77 , L_4 , sizeof( V_76 -> V_77 ) ) ;
F_38 ( V_76 -> V_78 , L_5 , sizeof( V_76 -> V_78 ) ) ;
F_38 ( V_76 -> V_79 , L_6 , sizeof( V_76 -> V_79 ) ) ;
V_76 -> V_80 = V_81 | V_82 |
V_83 ;
V_76 -> V_84 = V_76 -> V_80 | V_85 ;
return 0 ;
}
static int F_39 ( struct V_73 * V_73 , void * V_74 ,
struct V_86 * V_87 )
{
struct V_5 * V_6 = F_37 ( V_73 ) ;
if ( V_87 -> V_88 >= F_40 ( V_39 ) )
return - V_46 ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
V_87 -> type = V_89 ;
F_38 ( V_87 -> V_90 , V_39 [ V_87 -> V_88 ] . V_91 ,
sizeof( V_87 -> V_90 ) ) ;
V_87 -> V_17 = V_39 [ V_87 -> V_88 ] . V_92 ;
return 0 ;
}
static int F_41 ( struct V_73 * V_73 , void * V_74 ,
struct V_93 * V_87 )
{
struct V_5 * V_6 = F_37 ( V_73 ) ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
V_87 -> type = V_89 ;
V_87 -> V_87 . V_16 = V_6 -> V_16 ;
return 0 ;
}
static void F_42 ( struct V_5 * V_6 ,
int V_40 , int V_94 , int V_95 )
{
struct V_96 * V_87 = V_39 + V_40 ;
unsigned int V_97 , V_98 , V_99 ,
V_100 , V_101 , V_102 ;
struct V_103 * V_104 = & V_6 -> V_104 ;
struct V_37 * V_16 = & V_6 -> V_16 ;
T_1 V_105 = 0 , V_106 , V_107 ;
if ( V_6 -> V_108 & V_109 ) {
V_99 = 858 ;
} else {
V_99 = 864 ;
}
V_100 = V_16 -> V_21 / 2 ;
V_101 = V_104 -> V_21 / 2 ;
V_102 = V_104 -> V_110 / 2 ;
V_97 = V_99 - V_111 ;
V_98 = 20 ;
V_106 = V_104 -> V_20 + V_104 -> V_112 ;
V_107 = V_101 + V_102 ;
F_18 ( V_6 -> V_42 . V_43 ,
L_7 ,
V_16 -> V_20 , V_100 , V_97 , V_98 ,
V_104 -> V_112 , V_102 , V_106 , V_107 ) ;
F_5 ( V_6 , V_113 , ( V_16 -> V_20 << 16 ) | V_100 ) ;
F_5 ( V_6 , V_114 , ( V_97 << 16 ) | V_98 ) ;
F_5 ( V_6 , V_115 , ( V_104 -> V_112 << 16 ) | V_102 ) ;
F_5 ( V_6 , V_116 , ( V_106 << 16 ) | V_107 ) ;
if ( V_94 )
V_105 |= ( 1 << 15 ) | ( V_117 [ V_94 - 1 ] << 4 ) ;
if ( V_95 )
V_105 |= ( 1 << 14 ) | V_118 [ V_95 - 1 ] ;
F_18 ( V_6 -> V_42 . V_43 , L_8 , V_87 -> V_91 , V_105 ) ;
F_5 ( V_6 , V_119 , V_105 ) ;
F_5 ( V_6 , V_120 ,
V_87 -> V_121 | ( V_87 -> V_122 << 8 ) | ( V_87 -> V_123 << 16 ) ) ;
}
static void F_43 ( struct V_124 * V_125 , T_3 V_108 )
{
unsigned int V_126 = V_127 , V_128 = 0 , V_129 ;
int V_130 , V_131 = 0 ;
if ( V_108 & V_109 )
V_129 = 480 ;
else
V_129 = 576 ;
F_44 ( & V_125 -> V_132 ,
V_133 , V_111 , 2 ,
& V_125 -> V_134 ,
V_135 , V_129 , 1 , 0 ) ;
for ( V_130 = F_40 ( V_136 ) - 1 ; V_130 >= 0 ; V_130 -- ) {
unsigned int V_137 ;
unsigned int V_138 = V_125 -> V_139 . V_20 * V_140 [ V_130 ] /
V_136 [ V_130 ] ;
if ( V_138 > V_111 )
break;
V_137 = abs ( V_138 - V_125 -> V_132 ) ;
if ( V_137 < V_126 ) {
V_126 = V_137 ;
V_131 = V_130 ;
V_128 = V_138 ;
}
if ( ! V_137 )
break;
}
V_125 -> V_132 = V_128 ;
V_125 -> V_141 = V_131 ;
V_126 = V_127 ;
for ( V_130 = F_40 ( V_142 ) - 1 ; V_130 >= 0 ; V_130 -- ) {
unsigned int V_137 ;
unsigned int V_138 = V_125 -> V_139 . V_21 * V_143 [ V_130 ] /
V_142 [ V_130 ] ;
if ( V_138 > V_129 )
break;
V_137 = abs ( V_138 - V_125 -> V_134 ) ;
if ( V_137 < V_126 ) {
V_126 = V_137 ;
V_131 = V_130 ;
V_128 = V_138 ;
}
if ( ! V_137 )
break;
}
V_125 -> V_134 = V_128 ;
V_125 -> V_144 = V_131 ;
}
static void F_45 ( struct V_124 * V_125 , T_3 V_108 )
{
unsigned int V_126 = V_127 , V_128 = V_125 -> V_132 ,
V_99 , V_145 , V_129 ;
int V_130 , V_146 = 0 , V_147 = 0 ;
if ( V_108 & V_109 ) {
V_99 = 858 ;
V_145 = 262 * 2 ;
V_129 = 480 ;
} else {
V_99 = 864 ;
V_145 = 312 * 2 ;
V_129 = 576 ;
}
for ( V_130 = 0 ; V_130 < F_40 ( V_136 ) ; V_130 ++ ) {
unsigned int V_137 ;
unsigned int V_138 = V_125 -> V_132 * V_136 [ V_130 ] /
V_140 [ V_130 ] ;
if ( V_138 > V_111 )
break;
V_137 = abs ( V_138 - V_125 -> V_139 . V_20 ) ;
if ( V_137 < V_126 ) {
V_126 = V_137 ;
V_146 = V_130 ;
V_128 = V_138 ;
}
if ( ! V_137 )
break;
}
V_125 -> V_139 . V_20 = V_128 ;
V_125 -> V_141 = V_146 ;
if ( V_125 -> V_139 . V_112 + V_128 > V_99 )
V_125 -> V_139 . V_112 = V_99 - V_128 ;
F_46 ( L_9 , V_44 , V_125 -> V_132 ,
V_136 [ V_146 ] , V_140 [ V_146 ] , V_128 ) ;
V_126 = V_127 ;
for ( V_130 = 0 ; V_130 < F_40 ( V_142 ) ; V_130 ++ ) {
unsigned int V_137 ;
unsigned int V_138 = V_125 -> V_134 * V_142 [ V_130 ] /
V_143 [ V_130 ] ;
if ( V_138 > V_129 )
break;
V_137 = abs ( V_138 - V_125 -> V_139 . V_21 ) ;
if ( V_137 < V_126 ) {
V_126 = V_137 ;
V_147 = V_130 ;
V_128 = V_138 ;
}
if ( ! V_137 )
break;
}
V_125 -> V_139 . V_21 = V_128 ;
V_125 -> V_144 = V_147 ;
if ( V_125 -> V_139 . V_110 + V_128 > V_145 )
V_125 -> V_139 . V_110 = V_145 - V_128 ;
F_46 ( L_10 , V_44 , V_125 -> V_134 ,
V_142 [ V_147 ] , V_143 [ V_147 ] , V_128 ) ;
}
static int F_47 ( struct V_73 * V_73 , void * V_74 ,
struct V_93 * V_87 )
{
struct V_5 * V_6 = F_37 ( V_73 ) ;
struct V_37 * V_16 = & V_87 -> V_87 . V_16 ;
unsigned int V_129 ;
int V_40 ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
V_16 -> V_148 = V_149 ;
V_16 -> V_150 = V_151 ;
V_16 -> V_152 = V_16 -> V_153 = 0 ;
for ( V_40 = 0 ; V_40 < F_40 ( V_39 ) ; V_40 ++ )
if ( V_39 [ V_40 ] . V_92 == V_16 -> V_17 )
break;
if ( V_40 == F_40 ( V_39 ) )
return - V_46 ;
if ( V_6 -> V_108 & V_109 )
V_129 = 480 ;
else
V_129 = 576 ;
F_44 ( & V_16 -> V_20 ,
V_133 , V_111 , 2 ,
& V_16 -> V_21 ,
V_135 , V_129 , 1 , 0 ) ;
V_16 -> V_154 = V_16 -> V_20 * V_39 [ V_40 ] . V_155 ;
V_16 -> V_156 = V_16 -> V_21 * ( ( V_16 -> V_20 * V_39 [ V_40 ] . V_41 ) >> 3 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_37 * V_16 )
{
unsigned int V_129 ;
struct V_124 V_125 ;
struct V_157 V_158 = {
. V_159 = V_160 ,
. V_158 . V_161 = V_162 ,
. V_158 . V_148 = V_149 ,
. V_158 . V_150 = V_151 ,
} ;
struct V_163 * V_164 = & V_158 . V_158 ;
int V_40 ;
int V_57 ;
if ( F_49 ( & V_6 -> V_165 ) )
return - V_166 ;
for ( V_40 = 0 ; V_40 < F_40 ( V_39 ) ; V_40 ++ )
if ( V_39 [ V_40 ] . V_92 == V_16 -> V_17 )
break;
V_125 . V_132 = V_16 -> V_20 ;
V_125 . V_134 = V_16 -> V_21 ;
V_125 . V_139 = V_6 -> V_104 ;
F_45 ( & V_125 , V_6 -> V_108 ) ;
V_164 -> V_20 = V_125 . V_139 . V_20 ;
V_164 -> V_21 = V_125 . V_139 . V_21 ;
V_57 = F_29 ( & V_6 -> V_42 , 0 , V_167 ,
V_168 , NULL , & V_158 ) ;
if ( V_57 < 0 )
return V_57 ;
F_18 ( V_6 -> V_42 . V_43 , L_11 , V_44 ,
V_125 . V_139 . V_20 , V_125 . V_139 . V_21 , V_164 -> V_20 , V_164 -> V_21 ) ;
if ( V_6 -> V_108 & V_109 )
V_129 = 480 ;
else
V_129 = 576 ;
if ( ( unsigned ) V_164 -> V_20 > V_111 ||
( unsigned ) V_164 -> V_21 > V_129 ||
V_164 -> V_161 != V_162 )
return - V_169 ;
if ( V_164 -> V_20 != V_125 . V_139 . V_20 ||
V_164 -> V_21 != V_125 . V_139 . V_21 ) {
V_125 . V_139 . V_20 = V_164 -> V_20 ;
V_125 . V_139 . V_21 = V_164 -> V_21 ;
F_43 ( & V_125 , V_6 -> V_108 ) ;
}
V_6 -> V_104 = V_125 . V_139 ;
V_16 -> V_20 = V_125 . V_132 ;
V_16 -> V_21 = V_125 . V_134 ;
F_18 ( V_6 -> V_42 . V_43 , L_12 , V_44 ,
V_16 -> V_20 , V_16 -> V_21 ) ;
V_6 -> V_40 = V_40 ;
V_6 -> V_16 = * V_16 ;
F_42 ( V_6 , V_40 ,
V_125 . V_141 , V_125 . V_144 ) ;
return 0 ;
}
static int F_50 ( struct V_73 * V_73 , void * V_74 ,
struct V_93 * V_87 )
{
struct V_5 * V_6 = F_37 ( V_73 ) ;
int V_57 = F_47 ( V_73 , V_74 , V_87 ) ;
if ( V_57 )
return V_57 ;
return F_48 ( V_6 , & V_87 -> V_87 . V_16 ) ;
}
static int F_51 ( struct V_73 * V_73 , void * V_170 ,
struct V_171 * V_172 )
{
struct V_5 * V_6 = F_37 ( V_73 ) ;
if ( V_172 -> V_88 )
return - V_46 ;
F_38 ( V_172 -> V_173 , L_13 , sizeof( V_172 -> V_173 ) ) ;
V_172 -> type = V_174 ;
V_172 -> V_108 = V_6 -> V_175 . V_176 ;
return 0 ;
}
static int F_52 ( struct V_73 * V_73 , void * V_170 , unsigned int * V_130 )
{
* V_130 = 0 ;
return 0 ;
}
static int F_53 ( struct V_73 * V_73 , void * V_170 , unsigned int V_130 )
{
return V_130 ? - V_46 : 0 ;
}
static T_1 F_54 ( enum V_177 V_178 )
{
switch ( V_178 ) {
default:
F_55 ( L_14 ,
V_44 , V_178 ) ;
case V_179 :
return 1 ;
case V_180 :
return 0 ;
case V_181 :
return 3 ;
}
}
static int F_56 ( struct V_73 * V_73 , void * V_74 , T_3 V_182 )
{
struct V_5 * V_6 = F_37 ( V_73 ) ;
int V_57 ;
F_18 ( V_6 -> V_42 . V_43 , L_15 , V_44 , V_182 ) ;
if ( V_182 == V_6 -> V_108 )
return 0 ;
if ( F_49 ( & V_6 -> V_165 ) )
return - V_166 ;
V_57 = F_29 ( & V_6 -> V_42 , 0 , V_59 ,
V_183 , V_182 ) ;
if ( V_57 < 0 && V_57 != - V_61 )
return V_57 ;
V_6 -> V_104 . V_110 = V_6 -> V_104 . V_112 = 0 ;
V_6 -> V_104 . V_20 = V_111 ;
if ( V_182 & V_109 ) {
F_11 ( V_6 , V_184 ,
F_54 ( V_6 -> V_185 -> V_178 ) << 29 , 7 << 29 ) ;
V_6 -> V_104 . V_21 = 480 ;
} else {
F_11 ( V_6 , V_184 , 5 << 29 , 7 << 29 ) ;
V_6 -> V_104 . V_21 = 576 ;
}
V_6 -> V_16 . V_20 = V_6 -> V_104 . V_20 ;
V_6 -> V_16 . V_21 = V_6 -> V_104 . V_21 ;
V_6 -> V_16 . V_154 =
V_6 -> V_16 . V_20 * V_39 [ V_6 -> V_40 ] . V_155 ;
V_6 -> V_16 . V_156 = V_6 -> V_16 . V_21 *
( ( V_6 -> V_16 . V_20 * V_39 [ V_6 -> V_40 ] . V_41 ) >> 3 ) ;
V_6 -> V_108 = V_182 ;
F_48 ( V_6 , & V_6 -> V_16 ) ;
return 0 ;
}
static int F_57 ( struct V_73 * V_73 , void * V_74 , T_3 * V_108 )
{
struct V_5 * V_6 = F_37 ( V_73 ) ;
F_18 ( V_6 -> V_42 . V_43 , L_1 , V_44 ) ;
* V_108 = V_6 -> V_108 ;
return 0 ;
}
static int F_58 ( struct V_73 * V_73 , void * V_74 )
{
struct V_5 * V_6 = F_37 ( V_73 ) ;
F_59 ( L_16 , F_7 ( V_6 , V_71 ) ) ;
F_59 ( L_17 , F_7 ( V_6 , V_184 ) ) ;
F_59 ( L_18 , F_7 ( V_6 , V_66 ) ) ;
F_59 ( L_19 , F_7 ( V_6 , V_119 ) ) ;
F_59 ( L_20 , F_7 ( V_6 , V_113 ) ) ;
F_59 ( L_21 , F_7 ( V_6 , V_186 ) ) ;
F_59 ( L_22 , F_7 ( V_6 , V_115 ) ) ;
F_59 ( L_23 , F_7 ( V_6 , V_116 ) ) ;
F_59 ( L_24 , F_7 ( V_6 , V_114 ) ) ;
F_59 ( L_25 , F_7 ( V_6 , V_68 ) ) ;
F_59 ( L_26 , F_7 ( V_6 , V_187 ) ) ;
F_59 ( L_27 , F_7 ( V_6 , V_188 ) ) ;
F_59 ( L_28 , F_7 ( V_6 , V_189 ) ) ;
F_59 ( L_29 , F_7 ( V_6 , V_120 ) ) ;
F_59 ( L_30 , F_7 ( V_6 , V_22 ) ) ;
F_59 ( L_31 , F_7 ( V_6 , V_23 ) ) ;
F_59 ( L_32 , F_7 ( V_6 , V_30 ) ) ;
F_59 ( L_33 , F_7 ( V_6 , V_29 ) ) ;
F_59 ( L_34 , F_7 ( V_6 , V_67 ) ) ;
F_59 ( L_35 , F_7 ( V_6 , V_65 ) ) ;
return 0 ;
}
static int F_60 ( struct V_73 * V_73 , void * V_170 ,
struct V_190 * V_191 )
{
struct V_5 * V_6 = F_37 ( V_73 ) ;
if ( V_191 -> type != V_89 )
return - V_46 ;
switch ( V_191 -> V_192 ) {
case V_193 :
V_191 -> V_194 = V_6 -> V_104 ;
break;
case V_195 :
case V_196 :
V_191 -> V_194 . V_112 = 0 ;
V_191 -> V_194 . V_110 = 0 ;
V_191 -> V_194 . V_20 = V_111 ;
if ( V_6 -> V_108 & V_109 )
V_191 -> V_194 . V_21 = 480 ;
else
V_191 -> V_194 . V_21 = 576 ;
break;
default:
return - V_46 ;
}
return 0 ;
}
static int F_61 ( struct V_73 * V_73 , void * V_170 ,
struct V_190 * V_191 )
{
struct V_103 * V_104 = & V_191 -> V_194 ;
struct V_5 * V_6 = F_37 ( V_73 ) ;
struct V_197 V_198 = { . type = V_89 } ;
struct V_37 * V_16 = & V_6 -> V_16 ;
struct V_124 V_125 ;
struct V_157 V_158 = {
. V_159 = V_160 ,
. V_158 . V_161 = V_162 ,
. V_158 . V_148 = V_149 ,
. V_158 . V_150 = V_151 ,
} ;
unsigned int V_129 ;
int V_57 ;
if ( V_191 -> type != V_89 ||
V_191 -> V_192 != V_193 )
return - V_46 ;
if ( F_49 ( & V_6 -> V_165 ) )
return - V_166 ;
if ( V_6 -> V_108 & V_109 )
V_129 = 480 ;
else
V_129 = 576 ;
F_44 ( & V_104 -> V_20 ,
V_133 , V_111 , 1 ,
& V_104 -> V_21 ,
V_135 , V_129 , 1 , 0 ) ;
if ( V_104 -> V_20 + V_104 -> V_112 > V_111 )
V_104 -> V_112 = V_111 - V_104 -> V_20 ;
if ( V_104 -> V_21 + V_104 -> V_110 > V_129 )
V_104 -> V_110 = V_129 - V_104 -> V_21 ;
V_125 . V_139 = * V_104 ;
V_125 . V_132 = V_16 -> V_20 ;
V_125 . V_134 = V_16 -> V_21 ;
V_198 . V_199 . V_20 = V_125 . V_139 . V_20 ;
V_198 . V_199 . V_21 = V_125 . V_139 . V_21 ;
F_29 ( & V_6 -> V_42 , 0 , V_59 ,
V_200 , & V_198 ) ;
V_158 . V_158 . V_20 = V_125 . V_139 . V_20 ;
V_158 . V_158 . V_21 = V_125 . V_139 . V_21 ;
V_57 = F_29 ( & V_6 -> V_42 , 0 , V_167 ,
V_168 , NULL , & V_158 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ( unsigned ) V_158 . V_158 . V_20 > V_111 ||
( unsigned ) V_158 . V_158 . V_21 > V_129 ||
V_158 . V_158 . V_161 != V_162 )
return - V_169 ;
V_125 . V_139 . V_20 = V_158 . V_158 . V_20 ;
V_125 . V_139 . V_21 = V_158 . V_158 . V_21 ;
F_43 ( & V_125 , V_6 -> V_108 ) ;
V_6 -> V_104 = V_125 . V_139 ;
V_16 -> V_20 = V_125 . V_132 ;
V_16 -> V_21 = V_125 . V_134 ;
F_42 ( V_6 , V_6 -> V_40 ,
V_125 . V_141 , V_125 . V_144 ) ;
return 0 ;
}
static T_4 F_62 ( int V_201 , void * V_202 )
{
struct V_5 * V_6 = V_202 ;
static unsigned long V_203 ;
struct V_1 * V_4 ;
static int V_204 ;
T_1 V_205 = F_7 ( V_6 , V_68 ) , V_206 ;
T_1 V_207 = F_7 ( V_6 , V_66 ) ;
if ( ! ( V_205 & 0x300 ) ) {
if ( F_63 ( & V_203 , 500 ) )
F_21 ( V_6 -> V_42 . V_43 , L_36 ,
V_205 ) ;
return V_208 ;
}
F_64 ( & V_6 -> V_51 ) ;
if ( ! V_6 -> V_63 || F_65 ( & V_6 -> V_53 ) ) {
if ( F_63 ( & V_203 , 500 ) )
F_21 ( V_6 -> V_42 . V_43 ,
L_37 , V_205 ) ;
F_9 ( V_6 , V_68 , 0 , 0x300 ) ;
F_66 ( & V_6 -> V_51 ) ;
return V_209 ;
}
V_206 = ~ ( 0x300 & V_205 ) & V_205 & 0x30304 ;
F_18 ( V_6 -> V_42 . V_43 ,
L_38 ,
V_205 , V_206 , V_207 , V_204 ) ;
V_204 ++ ;
F_3 ( V_6 , V_68 , V_206 ) ;
V_4 = V_6 -> V_63 ;
if ( F_67 ( & V_4 -> V_52 ) ) {
F_12 ( V_6 , & V_4 -> V_4 ) ;
F_66 ( & V_6 -> V_51 ) ;
return V_209 ;
}
F_32 ( & V_4 -> V_52 ) ;
V_4 -> V_4 . V_15 . V_210 = F_68 () ;
V_4 -> V_4 . V_58 = V_6 -> V_58 ++ ;
V_4 -> V_4 . V_148 = V_149 ;
F_31 ( & V_4 -> V_4 . V_15 , V_211 ) ;
V_6 -> V_63 = F_33 ( V_6 -> V_53 . V_64 ,
struct V_1 , V_52 ) ;
if ( F_67 ( & V_6 -> V_53 ) ) {
F_12 ( V_6 , & V_6 -> V_63 -> V_4 ) ;
} else {
struct V_1 * V_212 = F_33 ( V_6 -> V_63 -> V_52 . V_64 ,
struct V_1 , V_52 ) ;
F_12 ( V_6 , & V_212 -> V_4 ) ;
}
F_66 ( & V_6 -> V_51 ) ;
return V_209 ;
}
static int F_69 ( struct V_5 * V_6 )
{
struct V_213 * V_185 = V_6 -> V_185 ;
T_1 V_214 = F_54 ( V_185 -> V_178 ) << 29 ;
int V_130 = 100 ;
F_3 ( V_6 , V_68 , 0 ) ;
F_3 ( V_6 , V_187 , 0x101 ) ;
while ( -- V_130 && ( F_7 ( V_6 , V_187 ) & 0x101 ) )
F_70 ( 1 ) ;
if ( ! V_130 )
return - V_215 ;
F_18 ( V_6 -> V_42 . V_43 , L_39 , 100 - V_130 ) ;
if ( V_185 -> V_50 & V_216 )
V_214 |= 1 << 28 ;
if ( V_185 -> V_50 & V_217 )
V_214 |= 1 << 27 ;
if ( V_185 -> V_50 & V_218 )
V_214 |= 1 << 26 ;
F_11 ( V_6 , V_184 , V_214 , 0xfc000000 ) ;
F_3 ( V_6 , V_67 , 4 ) ;
F_5 ( V_6 , V_188 , 0x800000 ) ;
F_48 ( V_6 , & V_6 -> V_16 ) ;
return 0 ;
}
static int F_71 ( struct V_73 * V_73 )
{
struct V_5 * V_6 = F_37 ( V_73 ) ;
int V_137 ;
if ( F_72 ( & V_6 -> V_219 ) )
return - V_220 ;
V_137 = F_73 ( V_73 ) ;
if ( V_137 )
goto V_221;
if ( F_74 ( V_73 ) &&
V_6 -> V_69 == V_222 ) {
F_75 ( V_6 -> V_42 . V_43 ) ;
V_137 = F_69 ( V_6 ) ;
if ( V_137 < 0 ) {
F_76 ( V_6 -> V_42 . V_43 ) ;
F_77 ( V_73 ) ;
} else {
V_6 -> V_69 = V_223 ;
}
}
V_221:
F_78 ( & V_6 -> V_219 ) ;
return V_137 ;
}
static int F_79 ( struct V_73 * V_73 )
{
struct V_5 * V_6 = F_37 ( V_73 ) ;
bool V_224 ;
F_80 ( & V_6 -> V_219 ) ;
V_224 = F_74 ( V_73 ) ;
F_81 ( V_73 , NULL ) ;
if ( V_224 ) {
V_6 -> V_69 = V_222 ;
F_9 ( V_6 , V_71 , 0 , 0x101 ) ;
F_76 ( V_6 -> V_42 . V_43 ) ;
}
F_78 ( & V_6 -> V_219 ) ;
return 0 ;
}
static int F_82 ( struct V_225 * V_226 )
{
struct V_213 * V_227 = V_226 -> V_43 . V_228 ;
struct V_103 * V_104 ;
struct V_37 * V_16 ;
struct V_229 * V_230 ;
struct V_231 * V_175 ;
struct V_5 * V_6 ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
struct V_31 * V_236 ;
int V_201 , V_57 ;
V_233 = F_83 ( V_226 , V_237 , 0 ) ;
V_201 = F_84 ( V_226 , 0 ) ;
if ( ! V_227 || ! V_233 || V_201 <= 0 ) {
F_85 ( & V_226 -> V_43 , L_40 ) ;
return - V_238 ;
}
V_6 = F_86 ( & V_226 -> V_43 , sizeof( * V_6 ) , V_239 ) ;
if ( ! V_6 )
return - V_240 ;
F_87 ( & V_6 -> V_53 ) ;
F_88 ( & V_6 -> V_51 ) ;
F_89 ( & V_6 -> V_219 ) ;
V_6 -> V_185 = V_227 ;
V_6 -> V_69 = V_222 ;
V_6 -> V_40 = 1 ;
V_104 = & V_6 -> V_104 ;
V_16 = & V_6 -> V_16 ;
V_6 -> V_108 = V_241 ;
V_104 -> V_112 = 0 ;
V_104 -> V_110 = 0 ;
V_104 -> V_20 = V_111 ;
V_104 -> V_21 = 480 ;
V_16 -> V_20 = V_111 ;
V_16 -> V_21 = 480 ;
V_16 -> V_17 = V_19 ;
V_16 -> V_148 = V_149 ;
V_16 -> V_154 = V_111 ;
V_16 -> V_156 = V_111 * 2 * 480 ;
V_16 -> V_150 = V_151 ;
V_6 -> V_9 = F_90 ( & V_226 -> V_43 , V_233 ) ;
if ( F_91 ( V_6 -> V_9 ) )
return F_92 ( V_6 -> V_9 ) ;
V_57 = F_93 ( & V_226 -> V_43 , V_201 , F_62 , 0 , L_41 , V_6 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_94 ( & V_226 -> V_43 , & V_6 -> V_42 ) ;
if ( V_57 < 0 ) {
F_85 ( & V_226 -> V_43 , L_42 ) ;
return V_57 ;
}
V_175 = & V_6 -> V_175 ;
* V_175 = V_242 ;
if ( V_227 -> V_178 == V_179 )
V_175 -> V_176 |= V_243 ;
V_175 -> V_42 = & V_6 -> V_42 ;
V_175 -> V_244 = V_245 ;
V_175 -> V_51 = & V_6 -> V_219 ;
F_95 ( V_175 , V_6 ) ;
V_236 = & V_6 -> V_165 ;
V_236 -> type = V_89 ;
V_236 -> V_246 = V_247 | V_248 | V_249 ;
V_236 -> V_250 = V_6 ;
V_236 -> V_251 = sizeof( struct V_1 ) ;
V_236 -> V_252 = & V_253 ;
V_236 -> V_254 = & V_255 ;
V_236 -> V_256 = V_257 ;
V_236 -> V_258 = 2 ;
V_236 -> V_51 = & V_6 -> V_219 ;
V_57 = F_96 ( V_236 ) ;
if ( V_57 )
goto V_259;
V_6 -> V_45 = F_97 ( & V_226 -> V_43 ) ;
if ( F_91 ( V_6 -> V_45 ) ) {
F_85 ( & V_226 -> V_43 , L_43 ) ;
V_57 = F_92 ( V_6 -> V_45 ) ;
goto V_259;
}
V_175 -> V_165 = V_236 ;
F_87 ( & V_6 -> V_53 ) ;
F_98 ( & V_226 -> V_43 ) ;
F_99 ( & V_226 -> V_43 ) ;
V_230 = F_100 ( V_227 -> V_230 ) ;
if ( ! V_230 ) {
V_57 = - V_238 ;
goto V_260;
}
V_57 = F_69 ( V_6 ) ;
if ( V_57 < 0 )
goto V_261;
V_235 = F_101 ( & V_6 -> V_42 , V_230 ,
V_227 -> V_262 , NULL ) ;
if ( ! V_235 ) {
V_57 = - V_240 ;
goto V_263;
}
V_57 = F_102 ( V_175 , V_264 , - 1 ) ;
if ( V_57 < 0 )
goto V_265;
return 0 ;
V_265:
V_263:
V_261:
F_103 ( V_230 ) ;
V_260:
F_104 ( V_6 -> V_45 ) ;
V_259:
F_105 ( & V_226 -> V_43 ) ;
F_106 ( & V_6 -> V_42 ) ;
return V_57 ;
}
static int F_107 ( struct V_225 * V_226 )
{
struct V_266 * V_42 = F_108 ( V_226 ) ;
struct V_5 * V_6 = F_2 ( V_42 ,
struct V_5 , V_42 ) ;
struct V_234 * V_267 = F_33 ( V_42 -> V_268 . V_64 ,
struct V_234 , V_52 ) ;
struct V_269 * V_270 = F_109 ( V_267 ) ;
F_105 ( & V_226 -> V_43 ) ;
F_110 ( & V_6 -> V_175 ) ;
F_103 ( V_270 -> V_271 ) ;
F_104 ( V_6 -> V_45 ) ;
F_106 ( & V_6 -> V_42 ) ;
return 0 ;
}
