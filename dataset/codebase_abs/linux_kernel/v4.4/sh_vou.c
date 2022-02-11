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
static int F_16 ( struct V_31 * V_32 , const void * V_33 ,
unsigned int * V_34 , unsigned int * V_35 ,
unsigned int V_36 [] , void * V_37 [] )
{
const struct V_38 * V_39 = V_33 ;
struct V_5 * V_6 = F_17 ( V_32 ) ;
struct V_40 * V_16 = & V_6 -> V_16 ;
int V_41 = V_42 [ V_6 -> V_43 ] . V_44 * V_16 -> V_20 / 8 ;
F_18 ( V_6 -> V_45 . V_46 , L_1 , V_47 ) ;
if ( V_39 && V_39 -> V_39 . V_16 . V_48 < V_16 -> V_21 * V_41 )
return - V_49 ;
* V_35 = 1 ;
V_36 [ 0 ] = V_39 ? V_39 -> V_39 . V_16 . V_48 : V_16 -> V_21 * V_41 ;
V_37 [ 0 ] = V_6 -> V_50 ;
return 0 ;
}
static int F_19 ( struct V_51 * V_4 )
{
struct V_5 * V_6 = F_17 ( V_4 -> V_31 ) ;
struct V_40 * V_16 = & V_6 -> V_16 ;
unsigned V_41 = V_42 [ V_6 -> V_43 ] . V_44 * V_16 -> V_20 / 8 ;
unsigned V_52 = V_16 -> V_21 * V_41 ;
F_18 ( V_6 -> V_45 . V_46 , L_1 , V_47 ) ;
if ( F_20 ( V_4 , 0 ) < V_52 ) {
F_21 ( V_6 -> V_45 . V_46 , L_2 ,
F_20 ( V_4 , 0 ) , V_52 ) ;
return - V_49 ;
}
F_22 ( V_4 , 0 , V_52 ) ;
return 0 ;
}
static void F_23 ( struct V_51 * V_4 )
{
struct V_2 * V_12 = F_24 ( V_4 ) ;
struct V_5 * V_6 = F_17 ( V_4 -> V_31 ) ;
struct V_1 * V_53 = F_1 ( V_12 ) ;
unsigned long V_54 ;
F_25 ( & V_6 -> V_55 , V_54 ) ;
F_26 ( & V_53 -> V_56 , & V_6 -> V_57 ) ;
F_27 ( & V_6 -> V_55 , V_54 ) ;
}
static int F_28 ( struct V_31 * V_32 , unsigned int V_58 )
{
struct V_5 * V_6 = F_17 ( V_32 ) ;
struct V_1 * V_59 , * V_60 ;
int V_61 ;
V_6 -> V_62 = 0 ;
V_61 = F_29 ( & V_6 -> V_45 , 0 ,
V_63 , V_64 , 1 ) ;
if ( V_61 < 0 && V_61 != - V_65 ) {
F_30 (buf, node, &vou_dev->buf_list, list) {
F_31 ( & V_59 -> V_4 . V_15 ,
V_66 ) ;
F_32 ( & V_59 -> V_56 ) ;
}
V_6 -> V_67 = NULL ;
return V_61 ;
}
V_59 = F_33 ( V_6 -> V_57 . V_68 , struct V_1 , V_56 ) ;
V_6 -> V_67 = V_59 ;
F_3 ( V_6 , V_69 , 1 ) ;
F_18 ( V_6 -> V_45 . V_46 , L_3 ,
V_47 , F_7 ( V_6 , V_70 ) ) ;
F_12 ( V_6 , & V_59 -> V_4 ) ;
V_59 = F_33 ( V_59 -> V_56 . V_68 , struct V_1 , V_56 ) ;
F_3 ( V_6 , V_69 , 0 ) ;
F_12 ( V_6 , & V_59 -> V_4 ) ;
F_3 ( V_6 , V_71 , 5 ) ;
F_14 ( V_6 ) ;
F_3 ( V_6 , V_72 , 0x10004 ) ;
V_6 -> V_73 = V_74 ;
F_3 ( V_6 , V_75 , 0x107 ) ;
return 0 ;
}
static void F_34 ( struct V_31 * V_32 )
{
struct V_5 * V_6 = F_17 ( V_32 ) ;
struct V_1 * V_59 , * V_60 ;
unsigned long V_54 ;
F_29 ( & V_6 -> V_45 , 0 ,
V_63 , V_64 , 0 ) ;
F_9 ( V_6 , V_75 , 0 , 1 ) ;
F_9 ( V_6 , V_72 , 0 , 0x30000 ) ;
F_35 ( 50 ) ;
F_25 ( & V_6 -> V_55 , V_54 ) ;
F_30 (buf, node, &vou_dev->buf_list, list) {
F_31 ( & V_59 -> V_4 . V_15 , V_76 ) ;
F_32 ( & V_59 -> V_56 ) ;
}
V_6 -> V_67 = NULL ;
F_27 ( & V_6 -> V_55 , V_54 ) ;
}
static int F_36 ( struct V_77 * V_77 , void * V_78 ,
struct V_79 * V_80 )
{
struct V_5 * V_6 = F_37 ( V_77 ) ;
F_18 ( V_6 -> V_45 . V_46 , L_1 , V_47 ) ;
F_38 ( V_80 -> V_81 , L_4 , sizeof( V_80 -> V_81 ) ) ;
F_38 ( V_80 -> V_82 , L_5 , sizeof( V_80 -> V_82 ) ) ;
F_38 ( V_80 -> V_83 , L_6 , sizeof( V_80 -> V_83 ) ) ;
V_80 -> V_84 = V_85 | V_86 |
V_87 ;
V_80 -> V_88 = V_80 -> V_84 | V_89 ;
return 0 ;
}
static int F_39 ( struct V_77 * V_77 , void * V_78 ,
struct V_90 * V_39 )
{
struct V_5 * V_6 = F_37 ( V_77 ) ;
if ( V_39 -> V_91 >= F_40 ( V_42 ) )
return - V_49 ;
F_18 ( V_6 -> V_45 . V_46 , L_1 , V_47 ) ;
V_39 -> type = V_92 ;
F_38 ( V_39 -> V_93 , V_42 [ V_39 -> V_91 ] . V_94 ,
sizeof( V_39 -> V_93 ) ) ;
V_39 -> V_17 = V_42 [ V_39 -> V_91 ] . V_95 ;
return 0 ;
}
static int F_41 ( struct V_77 * V_77 , void * V_78 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = F_37 ( V_77 ) ;
F_18 ( V_6 -> V_45 . V_46 , L_1 , V_47 ) ;
V_39 -> type = V_92 ;
V_39 -> V_39 . V_16 = V_6 -> V_16 ;
return 0 ;
}
static void F_42 ( struct V_5 * V_6 ,
int V_43 , int V_96 , int V_97 )
{
struct V_98 * V_39 = V_42 + V_43 ;
unsigned int V_99 , V_100 , V_101 ,
V_102 , V_103 , V_104 ;
struct V_105 * V_106 = & V_6 -> V_106 ;
struct V_40 * V_16 = & V_6 -> V_16 ;
T_1 V_107 = 0 , V_108 , V_109 ;
if ( V_6 -> V_110 & V_111 ) {
V_101 = 858 ;
} else {
V_101 = 864 ;
}
V_102 = V_16 -> V_21 / 2 ;
V_103 = V_106 -> V_21 / 2 ;
V_104 = V_106 -> V_112 / 2 ;
V_99 = V_101 - V_113 ;
V_100 = 20 ;
V_108 = V_106 -> V_20 + V_106 -> V_114 ;
V_109 = V_103 + V_104 ;
F_18 ( V_6 -> V_45 . V_46 ,
L_7 ,
V_16 -> V_20 , V_102 , V_99 , V_100 ,
V_106 -> V_114 , V_104 , V_108 , V_109 ) ;
F_5 ( V_6 , V_115 , ( V_16 -> V_20 << 16 ) | V_102 ) ;
F_5 ( V_6 , V_116 , ( V_99 << 16 ) | V_100 ) ;
F_5 ( V_6 , V_117 , ( V_106 -> V_114 << 16 ) | V_104 ) ;
F_5 ( V_6 , V_118 , ( V_108 << 16 ) | V_109 ) ;
if ( V_96 )
V_107 |= ( 1 << 15 ) | ( V_119 [ V_96 - 1 ] << 4 ) ;
if ( V_97 )
V_107 |= ( 1 << 14 ) | V_120 [ V_97 - 1 ] ;
F_18 ( V_6 -> V_45 . V_46 , L_8 , V_39 -> V_94 , V_107 ) ;
F_5 ( V_6 , V_121 , V_107 ) ;
F_5 ( V_6 , V_122 ,
V_39 -> V_123 | ( V_39 -> V_124 << 8 ) | ( V_39 -> V_125 << 16 ) ) ;
}
static void F_43 ( struct V_126 * V_127 , T_3 V_110 )
{
unsigned int V_128 = V_129 , V_130 = 0 , V_131 ;
int V_132 , V_133 = 0 ;
if ( V_110 & V_111 )
V_131 = 480 ;
else
V_131 = 576 ;
F_44 ( & V_127 -> V_134 ,
V_135 , V_113 , 2 ,
& V_127 -> V_136 ,
V_137 , V_131 , 1 , 0 ) ;
for ( V_132 = F_40 ( V_138 ) - 1 ; V_132 >= 0 ; V_132 -- ) {
unsigned int V_139 ;
unsigned int V_140 = V_127 -> V_141 . V_20 * V_142 [ V_132 ] /
V_138 [ V_132 ] ;
if ( V_140 > V_113 )
break;
V_139 = abs ( V_140 - V_127 -> V_134 ) ;
if ( V_139 < V_128 ) {
V_128 = V_139 ;
V_133 = V_132 ;
V_130 = V_140 ;
}
if ( ! V_139 )
break;
}
V_127 -> V_134 = V_130 ;
V_127 -> V_143 = V_133 ;
V_128 = V_129 ;
for ( V_132 = F_40 ( V_144 ) - 1 ; V_132 >= 0 ; V_132 -- ) {
unsigned int V_139 ;
unsigned int V_140 = V_127 -> V_141 . V_21 * V_145 [ V_132 ] /
V_144 [ V_132 ] ;
if ( V_140 > V_131 )
break;
V_139 = abs ( V_140 - V_127 -> V_136 ) ;
if ( V_139 < V_128 ) {
V_128 = V_139 ;
V_133 = V_132 ;
V_130 = V_140 ;
}
if ( ! V_139 )
break;
}
V_127 -> V_136 = V_130 ;
V_127 -> V_146 = V_133 ;
}
static void F_45 ( struct V_126 * V_127 , T_3 V_110 )
{
unsigned int V_128 = V_129 , V_130 = V_127 -> V_134 ,
V_101 , V_147 , V_131 ;
int V_132 , V_148 = 0 , V_149 = 0 ;
if ( V_110 & V_111 ) {
V_101 = 858 ;
V_147 = 262 * 2 ;
V_131 = 480 ;
} else {
V_101 = 864 ;
V_147 = 312 * 2 ;
V_131 = 576 ;
}
for ( V_132 = 0 ; V_132 < F_40 ( V_138 ) ; V_132 ++ ) {
unsigned int V_139 ;
unsigned int V_140 = V_127 -> V_134 * V_138 [ V_132 ] /
V_142 [ V_132 ] ;
if ( V_140 > V_113 )
break;
V_139 = abs ( V_140 - V_127 -> V_141 . V_20 ) ;
if ( V_139 < V_128 ) {
V_128 = V_139 ;
V_148 = V_132 ;
V_130 = V_140 ;
}
if ( ! V_139 )
break;
}
V_127 -> V_141 . V_20 = V_130 ;
V_127 -> V_143 = V_148 ;
if ( V_127 -> V_141 . V_114 + V_130 > V_101 )
V_127 -> V_141 . V_114 = V_101 - V_130 ;
F_46 ( L_9 , V_47 , V_127 -> V_134 ,
V_138 [ V_148 ] , V_142 [ V_148 ] , V_130 ) ;
V_128 = V_129 ;
for ( V_132 = 0 ; V_132 < F_40 ( V_144 ) ; V_132 ++ ) {
unsigned int V_139 ;
unsigned int V_140 = V_127 -> V_136 * V_144 [ V_132 ] /
V_145 [ V_132 ] ;
if ( V_140 > V_131 )
break;
V_139 = abs ( V_140 - V_127 -> V_141 . V_21 ) ;
if ( V_139 < V_128 ) {
V_128 = V_139 ;
V_149 = V_132 ;
V_130 = V_140 ;
}
if ( ! V_139 )
break;
}
V_127 -> V_141 . V_21 = V_130 ;
V_127 -> V_146 = V_149 ;
if ( V_127 -> V_141 . V_112 + V_130 > V_147 )
V_127 -> V_141 . V_112 = V_147 - V_130 ;
F_46 ( L_10 , V_47 , V_127 -> V_136 ,
V_144 [ V_149 ] , V_145 [ V_149 ] , V_130 ) ;
}
static int F_47 ( struct V_77 * V_77 , void * V_78 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = F_37 ( V_77 ) ;
struct V_40 * V_16 = & V_39 -> V_39 . V_16 ;
unsigned int V_131 ;
int V_43 ;
F_18 ( V_6 -> V_45 . V_46 , L_1 , V_47 ) ;
V_16 -> V_150 = V_151 ;
V_16 -> V_152 = V_153 ;
V_16 -> V_154 = V_16 -> V_155 = 0 ;
for ( V_43 = 0 ; V_43 < F_40 ( V_42 ) ; V_43 ++ )
if ( V_42 [ V_43 ] . V_95 == V_16 -> V_17 )
break;
if ( V_43 == F_40 ( V_42 ) )
return - V_49 ;
if ( V_6 -> V_110 & V_111 )
V_131 = 480 ;
else
V_131 = 576 ;
F_44 ( & V_16 -> V_20 ,
V_135 , V_113 , 2 ,
& V_16 -> V_21 ,
V_137 , V_131 , 1 , 0 ) ;
V_16 -> V_156 = V_16 -> V_20 * V_42 [ V_43 ] . V_157 ;
V_16 -> V_48 = V_16 -> V_21 * ( ( V_16 -> V_20 * V_42 [ V_43 ] . V_44 ) >> 3 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_40 * V_16 )
{
unsigned int V_131 ;
struct V_126 V_127 ;
struct V_158 V_159 = {
. V_160 = V_161 ,
. V_159 . V_162 = V_163 ,
. V_159 . V_150 = V_151 ,
. V_159 . V_152 = V_153 ,
} ;
struct V_164 * V_165 = & V_159 . V_159 ;
int V_43 ;
int V_61 ;
if ( F_49 ( & V_6 -> V_166 ) )
return - V_167 ;
for ( V_43 = 0 ; V_43 < F_40 ( V_42 ) ; V_43 ++ )
if ( V_42 [ V_43 ] . V_95 == V_16 -> V_17 )
break;
V_127 . V_134 = V_16 -> V_20 ;
V_127 . V_136 = V_16 -> V_21 ;
V_127 . V_141 = V_6 -> V_106 ;
F_45 ( & V_127 , V_6 -> V_110 ) ;
V_165 -> V_20 = V_127 . V_141 . V_20 ;
V_165 -> V_21 = V_127 . V_141 . V_21 ;
V_61 = F_29 ( & V_6 -> V_45 , 0 , V_168 ,
V_169 , NULL , & V_159 ) ;
if ( V_61 < 0 )
return V_61 ;
F_18 ( V_6 -> V_45 . V_46 , L_11 , V_47 ,
V_127 . V_141 . V_20 , V_127 . V_141 . V_21 , V_165 -> V_20 , V_165 -> V_21 ) ;
if ( V_6 -> V_110 & V_111 )
V_131 = 480 ;
else
V_131 = 576 ;
if ( ( unsigned ) V_165 -> V_20 > V_113 ||
( unsigned ) V_165 -> V_21 > V_131 ||
V_165 -> V_162 != V_163 )
return - V_170 ;
if ( V_165 -> V_20 != V_127 . V_141 . V_20 ||
V_165 -> V_21 != V_127 . V_141 . V_21 ) {
V_127 . V_141 . V_20 = V_165 -> V_20 ;
V_127 . V_141 . V_21 = V_165 -> V_21 ;
F_43 ( & V_127 , V_6 -> V_110 ) ;
}
V_6 -> V_106 = V_127 . V_141 ;
V_16 -> V_20 = V_127 . V_134 ;
V_16 -> V_21 = V_127 . V_136 ;
F_18 ( V_6 -> V_45 . V_46 , L_12 , V_47 ,
V_16 -> V_20 , V_16 -> V_21 ) ;
V_6 -> V_43 = V_43 ;
V_6 -> V_16 = * V_16 ;
F_42 ( V_6 , V_43 ,
V_127 . V_143 , V_127 . V_146 ) ;
return 0 ;
}
static int F_50 ( struct V_77 * V_77 , void * V_78 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = F_37 ( V_77 ) ;
int V_61 = F_47 ( V_77 , V_78 , V_39 ) ;
if ( V_61 )
return V_61 ;
return F_48 ( V_6 , & V_39 -> V_39 . V_16 ) ;
}
static int F_51 ( struct V_77 * V_77 , void * V_171 ,
struct V_172 * V_173 )
{
struct V_5 * V_6 = F_37 ( V_77 ) ;
if ( V_173 -> V_91 )
return - V_49 ;
F_38 ( V_173 -> V_174 , L_13 , sizeof( V_173 -> V_174 ) ) ;
V_173 -> type = V_175 ;
V_173 -> V_110 = V_6 -> V_176 . V_177 ;
return 0 ;
}
static int F_52 ( struct V_77 * V_77 , void * V_171 , unsigned int * V_132 )
{
* V_132 = 0 ;
return 0 ;
}
static int F_53 ( struct V_77 * V_77 , void * V_171 , unsigned int V_132 )
{
return V_132 ? - V_49 : 0 ;
}
static T_1 F_54 ( enum V_178 V_179 )
{
switch ( V_179 ) {
default:
F_55 ( L_14 ,
V_47 , V_179 ) ;
case V_180 :
return 1 ;
case V_181 :
return 0 ;
case V_182 :
return 3 ;
}
}
static int F_56 ( struct V_77 * V_77 , void * V_78 , T_3 V_183 )
{
struct V_5 * V_6 = F_37 ( V_77 ) ;
int V_61 ;
F_18 ( V_6 -> V_45 . V_46 , L_15 , V_47 , V_183 ) ;
if ( V_183 == V_6 -> V_110 )
return 0 ;
if ( F_49 ( & V_6 -> V_166 ) )
return - V_167 ;
V_61 = F_29 ( & V_6 -> V_45 , 0 , V_63 ,
V_184 , V_183 ) ;
if ( V_61 < 0 && V_61 != - V_65 )
return V_61 ;
V_6 -> V_106 . V_112 = V_6 -> V_106 . V_114 = 0 ;
V_6 -> V_106 . V_20 = V_113 ;
if ( V_183 & V_111 ) {
F_11 ( V_6 , V_185 ,
F_54 ( V_6 -> V_186 -> V_179 ) << 29 , 7 << 29 ) ;
V_6 -> V_106 . V_21 = 480 ;
} else {
F_11 ( V_6 , V_185 , 5 << 29 , 7 << 29 ) ;
V_6 -> V_106 . V_21 = 576 ;
}
V_6 -> V_16 . V_20 = V_6 -> V_106 . V_20 ;
V_6 -> V_16 . V_21 = V_6 -> V_106 . V_21 ;
V_6 -> V_16 . V_156 =
V_6 -> V_16 . V_20 * V_42 [ V_6 -> V_43 ] . V_157 ;
V_6 -> V_16 . V_48 = V_6 -> V_16 . V_21 *
( ( V_6 -> V_16 . V_20 * V_42 [ V_6 -> V_43 ] . V_44 ) >> 3 ) ;
V_6 -> V_110 = V_183 ;
F_48 ( V_6 , & V_6 -> V_16 ) ;
return 0 ;
}
static int F_57 ( struct V_77 * V_77 , void * V_78 , T_3 * V_110 )
{
struct V_5 * V_6 = F_37 ( V_77 ) ;
F_18 ( V_6 -> V_45 . V_46 , L_1 , V_47 ) ;
* V_110 = V_6 -> V_110 ;
return 0 ;
}
static int F_58 ( struct V_77 * V_77 , void * V_78 )
{
struct V_5 * V_6 = F_37 ( V_77 ) ;
F_59 ( L_16 , F_7 ( V_6 , V_75 ) ) ;
F_59 ( L_17 , F_7 ( V_6 , V_185 ) ) ;
F_59 ( L_18 , F_7 ( V_6 , V_70 ) ) ;
F_59 ( L_19 , F_7 ( V_6 , V_121 ) ) ;
F_59 ( L_20 , F_7 ( V_6 , V_115 ) ) ;
F_59 ( L_21 , F_7 ( V_6 , V_187 ) ) ;
F_59 ( L_22 , F_7 ( V_6 , V_117 ) ) ;
F_59 ( L_23 , F_7 ( V_6 , V_118 ) ) ;
F_59 ( L_24 , F_7 ( V_6 , V_116 ) ) ;
F_59 ( L_25 , F_7 ( V_6 , V_72 ) ) ;
F_59 ( L_26 , F_7 ( V_6 , V_188 ) ) ;
F_59 ( L_27 , F_7 ( V_6 , V_189 ) ) ;
F_59 ( L_28 , F_7 ( V_6 , V_190 ) ) ;
F_59 ( L_29 , F_7 ( V_6 , V_122 ) ) ;
F_59 ( L_30 , F_7 ( V_6 , V_22 ) ) ;
F_59 ( L_31 , F_7 ( V_6 , V_23 ) ) ;
F_59 ( L_32 , F_7 ( V_6 , V_30 ) ) ;
F_59 ( L_33 , F_7 ( V_6 , V_29 ) ) ;
F_59 ( L_34 , F_7 ( V_6 , V_71 ) ) ;
F_59 ( L_35 , F_7 ( V_6 , V_69 ) ) ;
return 0 ;
}
static int F_60 ( struct V_77 * V_77 , void * V_171 ,
struct V_191 * V_192 )
{
struct V_5 * V_6 = F_37 ( V_77 ) ;
if ( V_192 -> type != V_92 )
return - V_49 ;
switch ( V_192 -> V_193 ) {
case V_194 :
V_192 -> V_195 = V_6 -> V_106 ;
break;
case V_196 :
case V_197 :
V_192 -> V_195 . V_114 = 0 ;
V_192 -> V_195 . V_112 = 0 ;
V_192 -> V_195 . V_20 = V_113 ;
if ( V_6 -> V_110 & V_111 )
V_192 -> V_195 . V_21 = 480 ;
else
V_192 -> V_195 . V_21 = 576 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static int F_61 ( struct V_77 * V_77 , void * V_171 ,
struct V_191 * V_192 )
{
struct V_105 * V_106 = & V_192 -> V_195 ;
struct V_5 * V_6 = F_37 ( V_77 ) ;
struct V_198 V_199 = { . type = V_92 } ;
struct V_40 * V_16 = & V_6 -> V_16 ;
struct V_126 V_127 ;
struct V_158 V_159 = {
. V_160 = V_161 ,
. V_159 . V_162 = V_163 ,
. V_159 . V_150 = V_151 ,
. V_159 . V_152 = V_153 ,
} ;
unsigned int V_131 ;
int V_61 ;
if ( V_192 -> type != V_92 ||
V_192 -> V_193 != V_194 )
return - V_49 ;
if ( F_49 ( & V_6 -> V_166 ) )
return - V_167 ;
if ( V_6 -> V_110 & V_111 )
V_131 = 480 ;
else
V_131 = 576 ;
F_44 ( & V_106 -> V_20 ,
V_135 , V_113 , 1 ,
& V_106 -> V_21 ,
V_137 , V_131 , 1 , 0 ) ;
if ( V_106 -> V_20 + V_106 -> V_114 > V_113 )
V_106 -> V_114 = V_113 - V_106 -> V_20 ;
if ( V_106 -> V_21 + V_106 -> V_112 > V_131 )
V_106 -> V_112 = V_131 - V_106 -> V_21 ;
V_127 . V_141 = * V_106 ;
V_127 . V_134 = V_16 -> V_20 ;
V_127 . V_136 = V_16 -> V_21 ;
V_199 . V_200 . V_20 = V_127 . V_141 . V_20 ;
V_199 . V_200 . V_21 = V_127 . V_141 . V_21 ;
F_29 ( & V_6 -> V_45 , 0 , V_63 ,
V_201 , & V_199 ) ;
V_159 . V_159 . V_20 = V_127 . V_141 . V_20 ;
V_159 . V_159 . V_21 = V_127 . V_141 . V_21 ;
V_61 = F_29 ( & V_6 -> V_45 , 0 , V_168 ,
V_169 , NULL , & V_159 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( ( unsigned ) V_159 . V_159 . V_20 > V_113 ||
( unsigned ) V_159 . V_159 . V_21 > V_131 ||
V_159 . V_159 . V_162 != V_163 )
return - V_170 ;
V_127 . V_141 . V_20 = V_159 . V_159 . V_20 ;
V_127 . V_141 . V_21 = V_159 . V_159 . V_21 ;
F_43 ( & V_127 , V_6 -> V_110 ) ;
V_6 -> V_106 = V_127 . V_141 ;
V_16 -> V_20 = V_127 . V_134 ;
V_16 -> V_21 = V_127 . V_136 ;
F_42 ( V_6 , V_6 -> V_43 ,
V_127 . V_143 , V_127 . V_146 ) ;
return 0 ;
}
static T_4 F_62 ( int V_202 , void * V_203 )
{
struct V_5 * V_6 = V_203 ;
static unsigned long V_204 ;
struct V_1 * V_4 ;
static int V_205 ;
T_1 V_206 = F_7 ( V_6 , V_72 ) , V_207 ;
T_1 V_208 = F_7 ( V_6 , V_70 ) ;
if ( ! ( V_206 & 0x300 ) ) {
if ( F_63 ( & V_204 , 500 ) )
F_21 ( V_6 -> V_45 . V_46 , L_36 ,
V_206 ) ;
return V_209 ;
}
F_64 ( & V_6 -> V_55 ) ;
if ( ! V_6 -> V_67 || F_65 ( & V_6 -> V_57 ) ) {
if ( F_63 ( & V_204 , 500 ) )
F_21 ( V_6 -> V_45 . V_46 ,
L_37 , V_206 ) ;
F_9 ( V_6 , V_72 , 0 , 0x300 ) ;
F_66 ( & V_6 -> V_55 ) ;
return V_210 ;
}
V_207 = ~ ( 0x300 & V_206 ) & V_206 & 0x30304 ;
F_18 ( V_6 -> V_45 . V_46 ,
L_38 ,
V_206 , V_207 , V_208 , V_205 ) ;
V_205 ++ ;
F_3 ( V_6 , V_72 , V_207 ) ;
V_4 = V_6 -> V_67 ;
if ( F_67 ( & V_4 -> V_56 ) ) {
F_12 ( V_6 , & V_4 -> V_4 ) ;
F_66 ( & V_6 -> V_55 ) ;
return V_210 ;
}
F_32 ( & V_4 -> V_56 ) ;
F_68 ( & V_4 -> V_4 . V_211 ) ;
V_4 -> V_4 . V_62 = V_6 -> V_62 ++ ;
V_4 -> V_4 . V_150 = V_151 ;
F_31 ( & V_4 -> V_4 . V_15 , V_212 ) ;
V_6 -> V_67 = F_33 ( V_6 -> V_57 . V_68 ,
struct V_1 , V_56 ) ;
if ( F_67 ( & V_6 -> V_57 ) ) {
F_12 ( V_6 , & V_6 -> V_67 -> V_4 ) ;
} else {
struct V_1 * V_213 = F_33 ( V_6 -> V_67 -> V_56 . V_68 ,
struct V_1 , V_56 ) ;
F_12 ( V_6 , & V_213 -> V_4 ) ;
}
F_66 ( & V_6 -> V_55 ) ;
return V_210 ;
}
static int F_69 ( struct V_5 * V_6 )
{
struct V_214 * V_186 = V_6 -> V_186 ;
T_1 V_215 = F_54 ( V_186 -> V_179 ) << 29 ;
int V_132 = 100 ;
F_3 ( V_6 , V_72 , 0 ) ;
F_3 ( V_6 , V_188 , 0x101 ) ;
while ( -- V_132 && ( F_7 ( V_6 , V_188 ) & 0x101 ) )
F_70 ( 1 ) ;
if ( ! V_132 )
return - V_216 ;
F_18 ( V_6 -> V_45 . V_46 , L_39 , 100 - V_132 ) ;
if ( V_186 -> V_54 & V_217 )
V_215 |= 1 << 28 ;
if ( V_186 -> V_54 & V_218 )
V_215 |= 1 << 27 ;
if ( V_186 -> V_54 & V_219 )
V_215 |= 1 << 26 ;
F_11 ( V_6 , V_185 , V_215 , 0xfc000000 ) ;
F_3 ( V_6 , V_71 , 4 ) ;
F_5 ( V_6 , V_189 , 0x800000 ) ;
F_48 ( V_6 , & V_6 -> V_16 ) ;
return 0 ;
}
static int F_71 ( struct V_77 * V_77 )
{
struct V_5 * V_6 = F_37 ( V_77 ) ;
int V_139 ;
if ( F_72 ( & V_6 -> V_220 ) )
return - V_221 ;
V_139 = F_73 ( V_77 ) ;
if ( V_139 )
goto V_222;
if ( F_74 ( V_77 ) &&
V_6 -> V_73 == V_223 ) {
F_75 ( V_6 -> V_45 . V_46 ) ;
V_139 = F_69 ( V_6 ) ;
if ( V_139 < 0 ) {
F_76 ( V_6 -> V_45 . V_46 ) ;
F_77 ( V_77 ) ;
} else {
V_6 -> V_73 = V_224 ;
}
}
V_222:
F_78 ( & V_6 -> V_220 ) ;
return V_139 ;
}
static int F_79 ( struct V_77 * V_77 )
{
struct V_5 * V_6 = F_37 ( V_77 ) ;
bool V_225 ;
F_80 ( & V_6 -> V_220 ) ;
V_225 = F_74 ( V_77 ) ;
F_81 ( V_77 , NULL ) ;
if ( V_225 ) {
V_6 -> V_73 = V_223 ;
F_9 ( V_6 , V_75 , 0 , 0x101 ) ;
F_76 ( V_6 -> V_45 . V_46 ) ;
}
F_78 ( & V_6 -> V_220 ) ;
return 0 ;
}
static int F_82 ( struct V_226 * V_227 )
{
struct V_214 * V_228 = V_227 -> V_46 . V_229 ;
struct V_105 * V_106 ;
struct V_40 * V_16 ;
struct V_230 * V_231 ;
struct V_232 * V_176 ;
struct V_5 * V_6 ;
struct V_233 * V_234 ;
struct V_235 * V_236 ;
struct V_31 * V_237 ;
int V_202 , V_61 ;
V_234 = F_83 ( V_227 , V_238 , 0 ) ;
V_202 = F_84 ( V_227 , 0 ) ;
if ( ! V_228 || ! V_234 || V_202 <= 0 ) {
F_85 ( & V_227 -> V_46 , L_40 ) ;
return - V_239 ;
}
V_6 = F_86 ( & V_227 -> V_46 , sizeof( * V_6 ) , V_240 ) ;
if ( ! V_6 )
return - V_241 ;
F_87 ( & V_6 -> V_57 ) ;
F_88 ( & V_6 -> V_55 ) ;
F_89 ( & V_6 -> V_220 ) ;
V_6 -> V_186 = V_228 ;
V_6 -> V_73 = V_223 ;
V_6 -> V_43 = 1 ;
V_106 = & V_6 -> V_106 ;
V_16 = & V_6 -> V_16 ;
V_6 -> V_110 = V_242 ;
V_106 -> V_114 = 0 ;
V_106 -> V_112 = 0 ;
V_106 -> V_20 = V_113 ;
V_106 -> V_21 = 480 ;
V_16 -> V_20 = V_113 ;
V_16 -> V_21 = 480 ;
V_16 -> V_17 = V_19 ;
V_16 -> V_150 = V_151 ;
V_16 -> V_156 = V_113 ;
V_16 -> V_48 = V_113 * 2 * 480 ;
V_16 -> V_152 = V_153 ;
V_6 -> V_9 = F_90 ( & V_227 -> V_46 , V_234 ) ;
if ( F_91 ( V_6 -> V_9 ) )
return F_92 ( V_6 -> V_9 ) ;
V_61 = F_93 ( & V_227 -> V_46 , V_202 , F_62 , 0 , L_41 , V_6 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_94 ( & V_227 -> V_46 , & V_6 -> V_45 ) ;
if ( V_61 < 0 ) {
F_85 ( & V_227 -> V_46 , L_42 ) ;
return V_61 ;
}
V_176 = & V_6 -> V_176 ;
* V_176 = V_243 ;
if ( V_228 -> V_179 == V_180 )
V_176 -> V_177 |= V_244 ;
V_176 -> V_45 = & V_6 -> V_45 ;
V_176 -> V_245 = V_246 ;
V_176 -> V_55 = & V_6 -> V_220 ;
F_95 ( V_176 , V_6 ) ;
V_237 = & V_6 -> V_166 ;
V_237 -> type = V_92 ;
V_237 -> V_247 = V_248 | V_249 | V_250 ;
V_237 -> V_251 = V_6 ;
V_237 -> V_252 = sizeof( struct V_1 ) ;
V_237 -> V_253 = & V_254 ;
V_237 -> V_255 = & V_256 ;
V_237 -> V_257 = V_258 ;
V_237 -> V_259 = 2 ;
V_237 -> V_55 = & V_6 -> V_220 ;
V_61 = F_96 ( V_237 ) ;
if ( V_61 )
goto V_260;
V_6 -> V_50 = F_97 ( & V_227 -> V_46 ) ;
if ( F_91 ( V_6 -> V_50 ) ) {
F_85 ( & V_227 -> V_46 , L_43 ) ;
V_61 = F_92 ( V_6 -> V_50 ) ;
goto V_260;
}
V_176 -> V_166 = V_237 ;
F_87 ( & V_6 -> V_57 ) ;
F_98 ( & V_227 -> V_46 ) ;
F_99 ( & V_227 -> V_46 ) ;
V_231 = F_100 ( V_228 -> V_231 ) ;
if ( ! V_231 ) {
V_61 = - V_239 ;
goto V_261;
}
V_61 = F_69 ( V_6 ) ;
if ( V_61 < 0 )
goto V_262;
V_236 = F_101 ( & V_6 -> V_45 , V_231 ,
V_228 -> V_263 , NULL ) ;
if ( ! V_236 ) {
V_61 = - V_241 ;
goto V_264;
}
V_61 = F_102 ( V_176 , V_265 , - 1 ) ;
if ( V_61 < 0 )
goto V_266;
return 0 ;
V_266:
V_264:
V_262:
F_103 ( V_231 ) ;
V_261:
F_104 ( V_6 -> V_50 ) ;
V_260:
F_105 ( & V_227 -> V_46 ) ;
F_106 ( & V_6 -> V_45 ) ;
return V_61 ;
}
static int F_107 ( struct V_226 * V_227 )
{
struct V_267 * V_45 = F_108 ( V_227 ) ;
struct V_5 * V_6 = F_2 ( V_45 ,
struct V_5 , V_45 ) ;
struct V_235 * V_268 = F_33 ( V_45 -> V_269 . V_68 ,
struct V_235 , V_56 ) ;
struct V_270 * V_271 = F_109 ( V_268 ) ;
F_105 ( & V_227 -> V_46 ) ;
F_110 ( & V_6 -> V_176 ) ;
F_103 ( V_271 -> V_272 ) ;
F_104 ( V_6 -> V_50 ) ;
F_106 ( & V_6 -> V_45 ) ;
return 0 ;
}
