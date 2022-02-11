static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 ,
V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 )
{
T_2 V_8 = F_5 ( V_3 , V_5 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 &= ~ V_6 ;
V_8 |= V_7 & V_6 ;
return F_6 ( V_3 , V_5 , V_8 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
const struct V_9 * V_10 )
{
int V_11 ;
V_11 = F_6 ( V_3 , V_12 ,
( V_10 -> V_13 & 0x0F00 ) >> 4 |
( V_10 -> V_14 & 0x0F00 ) >> 8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_3 , V_15 ,
V_10 -> V_14 & 0x00FF ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_3 , V_16 ,
V_10 -> V_13 & 0x00FF ) ;
return V_11 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_11 ;
V_11 = F_6 ( V_3 , V_18 ,
( V_19 & 0x07F8 ) >> 3 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_3 , V_20 ,
( V_21 & 0x07F8 ) >> 3 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( 1 == V_17 -> V_22 )
V_11 = F_4 ( V_3 , V_23 , 0x77 ,
( V_19 & 0x0007 ) << 4 |
( V_21 & 0x0007 ) ) ;
return V_11 ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_4 ( V_3 , V_24 , V_25 , V_25 ) ;
F_10 ( 1 ) ;
}
static int F_11 ( struct V_2 * V_3 , int V_26 )
{
int V_11 ;
T_1 V_27 ;
T_1 V_28 ;
if ( V_26 ) {
V_27 = 0 ;
V_28 = 0 ;
} else {
V_27 = V_29 | V_30 | V_31 ;
V_28 = V_32 ;
}
V_11 = F_4 ( V_3 , V_24 , V_33 , V_27 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_4 ( V_3 , V_34 , V_35 , V_28 ) ;
}
static const struct V_9 * F_12 ( T_3 V_36 ,
T_4 V_37 , T_4 V_38 )
{
const struct V_9 * V_10 ;
const struct V_9 * V_11 = NULL ;
T_5 V_39 = 0xffffffff , V_40 ;
int V_41 , V_42 ;
if ( V_36 & V_43 ) {
V_10 = V_44 ;
V_41 = F_13 ( V_44 ) ;
} else if ( V_36 & V_45 ) {
V_10 = V_46 ;
V_41 = F_13 ( V_46 ) ;
} else {
return NULL ;
}
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ ) {
V_40 = abs ( V_37 - V_10 [ V_42 ] . V_37 ) +
abs ( V_38 - V_10 [ V_42 ] . V_38 ) ;
if ( V_40 < V_39 ) {
V_39 = V_40 ;
V_11 = V_10 + V_42 ;
}
}
return V_11 ;
}
static int F_14 ( struct V_47 * V_48 , int V_26 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
T_1 V_8 ;
int V_11 ;
if ( ! V_26 ) {
switch ( V_17 -> V_22 ) {
case 0 :
V_8 = V_49 ;
break;
case 1 :
V_8 = V_50 ;
break;
default:
F_16 ( & V_3 -> V_51 , L_1 ) ;
return - V_52 ;
}
} else {
V_8 = V_53 ;
if ( ! V_17 -> V_10 ) {
F_16 ( & V_3 -> V_51 , L_2 ) ;
return - V_54 ;
}
F_17 ( & V_3 -> V_51 , L_3 ,
V_17 -> V_10 -> V_55 ,
V_17 -> V_10 -> V_37 ,
V_17 -> V_10 -> V_38 ) ;
}
V_11 = F_4 ( V_3 , V_56 , V_57 , V_8 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_11 ( V_3 , V_26 ) ;
}
static int F_18 ( struct V_47 * V_48 , T_3 * V_36 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
* V_36 = V_17 -> V_36 ;
return 0 ;
}
static int F_19 ( struct V_47 * V_48 , T_3 V_36 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
const unsigned V_58 = 720 ;
const unsigned V_59 = 15 ;
unsigned V_60 ;
unsigned V_61 ;
int V_11 ;
if ( ! ( V_36 & ( V_43 | V_45 ) ) )
return - V_52 ;
V_17 -> V_36 = V_36 ;
if ( V_36 & V_62 ) {
V_60 = 240 ;
V_61 = 18 ;
V_11 = F_4 ( V_3 , V_63 , 0x10 , 0x10 ) ;
} else {
V_60 = 288 ;
V_61 = 24 ;
V_11 = F_4 ( V_3 , V_63 , 0x10 , 0x00 ) ;
}
if ( ! V_11 )
V_11 = F_6 ( V_3 , V_64 ,
( ( V_61 >> 2 ) & 0xc0 ) |
( ( V_60 >> 4 ) & 0x30 ) |
( ( V_59 >> 6 ) & 0x0c ) |
( ( V_58 >> 8 ) & 0x03 ) ) ;
if ( ! V_11 )
V_11 = F_6 ( V_3 , V_65 ,
V_61 & 0xff ) ;
if ( ! V_11 )
V_11 = F_6 ( V_3 , V_66 ,
V_60 & 0xff ) ;
return V_11 ;
}
static int F_20 ( struct V_47 * V_48 ,
struct V_67 * V_68 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
int V_11 ;
if ( V_68 -> V_68 > 0xff )
return - V_52 ;
V_68 -> V_41 = 1 ;
V_11 = F_5 ( V_3 , V_68 -> V_68 ) ;
if ( V_11 < 0 )
return V_11 ;
V_68 -> V_8 = ( V_69 ) V_11 ;
return 0 ;
}
static int F_21 ( struct V_47 * V_48 ,
const struct V_67 * V_68 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
if ( V_68 -> V_68 > 0xff ||
V_68 -> V_8 > 0xff )
return - V_52 ;
return F_6 ( V_3 , V_68 -> V_68 , V_68 -> V_8 ) ;
}
static int F_22 ( struct V_47 * V_48 , int V_70 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_71 * V_72 = F_23 ( V_3 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
return F_24 ( & V_3 -> V_51 , V_72 , V_17 -> V_73 , V_70 ) ;
}
static int F_25 ( struct V_47 * V_48 , T_4 * V_37 , T_4 * V_38 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_11 = - V_52 ;
T_1 V_8 ;
V_17 -> V_10 = F_12 ( V_17 -> V_36 , * V_37 , * V_38 ) ;
if ( ! V_17 -> V_10 )
goto V_74;
F_9 ( V_3 ) ;
V_8 = 0x00 ;
if ( V_75 == V_17 -> V_76 -> V_77 )
V_8 = V_78 ;
V_11 = F_4 ( V_3 , V_56 , V_78 , V_8 ) ;
if ( V_11 < 0 )
goto V_74;
switch ( V_17 -> V_76 -> V_79 ) {
case V_80 :
V_8 = V_81 ; break;
case V_82 :
V_8 = V_83 ; break;
case V_84 :
V_8 = V_85 ; break;
case V_86 :
V_8 = V_87 ; break;
case V_88 :
V_8 = V_89 ; break;
case V_90 :
V_8 = V_91 ; break;
case V_92 :
V_8 = V_93 ; break;
case V_94 :
V_8 = V_95 ; break;
default:
V_8 = 0 ;
}
V_11 = F_4 ( V_3 , V_96 , V_97 , V_8 ) ;
if ( V_11 < 0 )
goto V_74;
V_11 = F_7 ( V_3 , V_17 -> V_10 ) ;
if ( V_11 < 0 )
goto V_74;
V_11 = F_8 ( V_3 ) ;
if ( V_11 < 0 )
goto V_74;
* V_37 = V_17 -> V_10 -> V_37 ;
* V_38 = V_17 -> V_10 -> V_38 ;
return V_11 ;
V_74:
F_9 ( V_3 ) ;
V_17 -> V_10 = NULL ;
return V_11 ;
}
static int F_26 ( struct V_47 * V_48 ,
struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( V_101 -> V_102 != V_103 )
return - V_52 ;
if ( V_101 -> V_104 > V_105 )
return - V_52 ;
V_101 -> V_106 . V_107 = 0 ;
V_101 -> V_106 . V_108 = 0 ;
if ( V_17 -> V_36 & V_43 ) {
V_101 -> V_106 . V_37 = 640 ;
V_101 -> V_106 . V_38 = 480 ;
} else {
V_101 -> V_106 . V_37 = 768 ;
V_101 -> V_106 . V_38 = 576 ;
}
return 0 ;
}
static int F_27 ( struct V_47 * V_48 ,
struct V_98 * V_99 ,
struct V_109 * V_110 )
{
struct V_111 * V_112 = & V_110 -> V_110 ;
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( V_110 -> V_113 )
return - V_52 ;
if ( ! V_17 -> V_10 ) {
V_17 -> V_10 = F_12 ( V_17 -> V_36 , 640 , 480 ) ;
if ( ! V_17 -> V_10 )
return - V_52 ;
}
V_112 -> V_37 = V_17 -> V_10 -> V_37 ;
V_112 -> V_38 = V_17 -> V_10 -> V_38 ;
V_112 -> V_114 = V_115 ;
V_112 -> V_116 = V_117 ;
V_112 -> V_118 = V_119 ;
return 0 ;
}
static int F_28 ( struct V_47 * V_48 ,
struct V_111 * V_112 )
{
T_4 V_37 = V_112 -> V_37 , V_38 = V_112 -> V_38 ;
int V_11 ;
F_29 ( V_112 -> V_118 != V_120 &&
V_112 -> V_118 != V_119 ) ;
if ( V_112 -> V_114 != V_115 )
return - V_52 ;
V_112 -> V_116 = V_117 ;
V_11 = F_25 ( V_48 , & V_37 , & V_38 ) ;
if ( ! V_11 ) {
V_112 -> V_37 = V_37 ;
V_112 -> V_38 = V_38 ;
}
return V_11 ;
}
static int F_30 ( struct V_47 * V_48 ,
struct V_98 * V_99 ,
struct V_109 * V_110 )
{
struct V_111 * V_112 = & V_110 -> V_110 ;
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
const struct V_9 * V_10 ;
if ( V_110 -> V_113 )
return - V_52 ;
if ( V_120 == V_112 -> V_118 ) {
V_112 -> V_118 = V_119 ;
} else if ( V_119 != V_112 -> V_118 ) {
F_16 ( & V_3 -> V_51 , L_4 , V_112 -> V_118 ) ;
return - V_52 ;
}
V_112 -> V_114 = V_115 ;
V_112 -> V_116 = V_117 ;
V_10 = F_12 ( V_17 -> V_36 , V_112 -> V_37 , V_112 -> V_38 ) ;
if ( ! V_10 )
return - V_52 ;
V_112 -> V_37 = V_10 -> V_37 ;
V_112 -> V_38 = V_10 -> V_38 ;
if ( V_110 -> V_102 == V_103 )
return F_28 ( V_48 , V_112 ) ;
V_99 -> V_121 = * V_112 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
T_2 V_122 ;
int V_11 ;
if ( V_75 != V_17 -> V_76 -> V_77 &&
V_123 != V_17 -> V_76 -> V_77 ) {
F_16 ( & V_3 -> V_51 , L_5 ) ;
return - V_124 ;
}
V_11 = F_22 ( & V_17 -> V_4 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_122 = F_5 ( V_3 , V_125 ) ;
V_17 -> V_22 = F_32 ( V_122 ) ;
V_122 = F_33 ( V_122 ) ;
if ( 0x0B != V_122 ||
0x01 < V_17 -> V_22 ) {
F_16 ( & V_3 -> V_51 ,
L_6 ,
V_122 , V_17 -> V_22 ) ;
V_11 = - V_124 ;
goto V_126;
}
F_34 ( & V_3 -> V_51 ,
L_7 , V_122 , V_17 -> V_22 ) ;
V_17 -> V_36 = V_43 ;
V_17 -> V_10 = & V_44 [ 0 ] ;
V_126:
F_22 ( & V_17 -> V_4 , 0 ) ;
return V_11 ;
}
static int F_35 ( struct V_47 * V_48 ,
struct V_98 * V_99 ,
struct V_127 * V_114 )
{
if ( V_114 -> V_113 || V_114 -> V_128 )
return - V_52 ;
V_114 -> V_114 = V_115 ;
return 0 ;
}
static int F_36 ( struct V_47 * V_48 ,
struct V_129 * V_99 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_71 * V_72 = F_23 ( V_3 ) ;
V_99 -> V_130 = V_131 | V_132 |
V_133 | V_134 |
V_135 | V_136 |
V_137 ;
V_99 -> type = V_138 ;
V_99 -> V_130 = F_37 ( V_72 , V_99 ) ;
return 0 ;
}
static int F_38 ( struct V_47 * V_48 ,
const struct V_129 * V_99 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_71 * V_72 = F_23 ( V_3 ) ;
T_1 V_8 = V_139 | V_140 ;
unsigned long V_130 = F_37 ( V_72 , V_99 ) ;
if ( V_130 & V_136 )
V_8 |= V_141 ;
if ( V_130 & V_134 )
V_8 |= V_142 ;
return F_6 ( V_3 , V_143 , V_8 ) ;
}
static int F_39 ( struct V_47 * V_48 , T_3 * V_36 )
{
* V_36 = V_43 | V_45 ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 ,
const struct V_144 * V_145 )
{
struct V_1 * V_17 ;
struct V_146 * V_76 ;
struct V_147 * V_148 =
F_41 ( V_3 -> V_51 . V_149 ) ;
struct V_71 * V_72 = F_23 ( V_3 ) ;
int V_11 ;
if ( ! V_72 || ! V_72 -> V_150 ) {
F_16 ( & V_3 -> V_51 , L_8 ) ;
return - V_52 ;
}
V_76 = V_72 -> V_150 ;
if ( ! F_42 ( V_148 , V_151 ) ) {
F_16 ( & V_3 -> V_51 ,
L_9
L_10 ) ;
return - V_152 ;
}
V_17 = F_43 ( & V_3 -> V_51 , sizeof( * V_17 ) , V_153 ) ;
if ( ! V_17 )
return - V_154 ;
V_17 -> V_76 = V_76 ;
F_44 ( & V_17 -> V_4 , V_3 , & V_155 ) ;
V_17 -> V_73 = F_45 ( & V_3 -> V_51 , L_11 ) ;
if ( F_46 ( V_17 -> V_73 ) )
return F_47 ( V_17 -> V_73 ) ;
V_11 = F_31 ( V_3 ) ;
if ( V_11 < 0 )
F_48 ( V_17 -> V_73 ) ;
return V_11 ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
F_48 ( V_17 -> V_73 ) ;
return 0 ;
}
