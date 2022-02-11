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
if ( ! ( V_36 & ( V_43 | V_45 ) ) )
return - V_52 ;
V_17 -> V_36 = V_36 ;
return 0 ;
}
static int F_20 ( struct V_47 * V_48 ,
struct V_58 * V_59 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
V_59 -> V_60 = V_61 ;
V_59 -> V_22 = V_17 -> V_22 ;
return 0 ;
}
static int F_21 ( struct V_47 * V_48 ,
struct V_62 * V_63 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
int V_11 ;
if ( V_63 -> V_63 > 0xff )
return - V_52 ;
V_11 = F_5 ( V_3 , V_63 -> V_63 ) ;
if ( V_11 < 0 )
return V_11 ;
V_63 -> V_8 = ( V_64 ) V_11 ;
return 0 ;
}
static int F_22 ( struct V_47 * V_48 ,
struct V_62 * V_63 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
if ( V_63 -> V_63 > 0xff ||
V_63 -> V_8 > 0xff )
return - V_52 ;
return F_6 ( V_3 , V_63 -> V_63 , V_63 -> V_8 ) ;
}
static int F_23 ( struct V_47 * V_48 , T_4 * V_37 , T_4 * V_38 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_11 = - V_52 ;
T_1 V_8 ;
V_17 -> V_10 = F_12 ( V_17 -> V_36 , * V_37 , * V_38 ) ;
if ( ! V_17 -> V_10 )
goto V_65;
F_9 ( V_3 ) ;
V_8 = 0x00 ;
if ( V_66 == V_17 -> V_67 -> V_68 )
V_8 = V_69 ;
V_11 = F_4 ( V_3 , V_56 , V_69 , V_8 ) ;
if ( V_11 < 0 )
goto V_65;
switch ( V_17 -> V_67 -> V_70 ) {
case V_71 :
V_8 = V_72 ; break;
case V_73 :
V_8 = V_74 ; break;
case V_75 :
V_8 = V_76 ; break;
case V_77 :
V_8 = V_78 ; break;
case V_79 :
V_8 = V_80 ; break;
case V_81 :
V_8 = V_82 ; break;
case V_83 :
V_8 = V_84 ; break;
case V_85 :
V_8 = V_86 ; break;
default:
V_8 = 0 ;
}
V_11 = F_4 ( V_3 , V_87 , V_88 , V_8 ) ;
if ( V_11 < 0 )
goto V_65;
V_11 = F_7 ( V_3 , V_17 -> V_10 ) ;
if ( V_11 < 0 )
goto V_65;
V_11 = F_8 ( V_3 ) ;
if ( V_11 < 0 )
goto V_65;
* V_37 = V_17 -> V_10 -> V_37 ;
* V_38 = V_17 -> V_10 -> V_38 ;
return V_11 ;
V_65:
F_9 ( V_3 ) ;
V_17 -> V_10 = NULL ;
return V_11 ;
}
static int F_24 ( struct V_47 * V_48 , struct V_89 * V_90 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
V_90 -> V_91 . V_92 = 0 ;
V_90 -> V_91 . V_93 = 0 ;
if ( V_17 -> V_36 & V_43 ) {
V_90 -> V_91 . V_37 = 640 ;
V_90 -> V_91 . V_38 = 480 ;
} else {
V_90 -> V_91 . V_37 = 768 ;
V_90 -> V_91 . V_38 = 576 ;
}
V_90 -> type = V_94 ;
return 0 ;
}
static int F_25 ( struct V_47 * V_48 , struct V_95 * V_90 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
V_90 -> V_96 . V_92 = 0 ;
V_90 -> V_96 . V_93 = 0 ;
if ( V_17 -> V_36 & V_43 ) {
V_90 -> V_96 . V_37 = 640 ;
V_90 -> V_96 . V_38 = 480 ;
} else {
V_90 -> V_96 . V_37 = 768 ;
V_90 -> V_96 . V_38 = 576 ;
}
V_90 -> V_97 = V_90 -> V_96 ;
V_90 -> type = V_94 ;
V_90 -> V_98 . V_99 = 1 ;
V_90 -> V_98 . V_100 = 1 ;
return 0 ;
}
static int F_26 ( struct V_47 * V_48 ,
struct V_101 * V_102 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( ! V_17 -> V_10 ) {
V_17 -> V_10 = F_12 ( V_17 -> V_36 , 640 , 480 ) ;
if ( ! V_17 -> V_10 )
return - V_52 ;
}
V_102 -> V_37 = V_17 -> V_10 -> V_37 ;
V_102 -> V_38 = V_17 -> V_10 -> V_38 ;
V_102 -> V_103 = V_104 ;
V_102 -> V_105 = V_106 ;
V_102 -> V_107 = V_108 ;
return 0 ;
}
static int F_27 ( struct V_47 * V_48 ,
struct V_101 * V_102 )
{
T_4 V_37 = V_102 -> V_37 , V_38 = V_102 -> V_38 ;
int V_11 ;
F_28 ( V_102 -> V_107 != V_109 &&
V_102 -> V_107 != V_108 ) ;
if ( V_102 -> V_103 != V_104 )
return - V_52 ;
V_102 -> V_105 = V_106 ;
V_11 = F_23 ( V_48 , & V_37 , & V_38 ) ;
if ( ! V_11 ) {
V_102 -> V_37 = V_37 ;
V_102 -> V_38 = V_38 ;
}
return V_11 ;
}
static int F_29 ( struct V_47 * V_48 ,
struct V_101 * V_102 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
const struct V_9 * V_10 ;
if ( V_109 == V_102 -> V_107 ) {
V_102 -> V_107 = V_108 ;
} else if ( V_108 != V_102 -> V_107 ) {
F_16 ( & V_3 -> V_51 , L_4 , V_102 -> V_107 ) ;
return - V_52 ;
}
V_102 -> V_103 = V_104 ;
V_102 -> V_105 = V_106 ;
V_10 = F_12 ( V_17 -> V_36 , V_102 -> V_37 , V_102 -> V_38 ) ;
if ( ! V_10 )
return - V_52 ;
V_102 -> V_37 = V_10 -> V_37 ;
V_102 -> V_38 = V_10 -> V_38 ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
T_2 V_59 ;
if ( V_66 != V_17 -> V_67 -> V_68 &&
V_110 != V_17 -> V_67 -> V_68 ) {
F_16 ( & V_3 -> V_51 , L_5 ) ;
return - V_111 ;
}
V_59 = F_5 ( V_3 , V_112 ) ;
V_17 -> V_22 = F_31 ( V_59 ) ;
V_59 = F_32 ( V_59 ) ;
if ( 0x0B != V_59 ||
0x01 < V_17 -> V_22 ) {
F_16 ( & V_3 -> V_51 ,
L_6 ,
V_59 , V_17 -> V_22 ) ;
return - V_111 ;
}
F_33 ( & V_3 -> V_51 ,
L_7 , V_59 , V_17 -> V_22 ) ;
V_17 -> V_36 = V_43 ;
return 0 ;
}
static int F_34 ( struct V_47 * V_48 , unsigned int V_113 ,
enum V_114 * V_103 )
{
if ( V_113 )
return - V_52 ;
* V_103 = V_104 ;
return 0 ;
}
static int F_35 ( struct V_47 * V_48 ,
struct V_115 * V_116 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_117 * V_118 = F_36 ( V_3 ) ;
V_116 -> V_119 = V_120 | V_121 |
V_122 | V_123 |
V_124 | V_125 |
V_126 ;
V_116 -> type = V_127 ;
V_116 -> V_119 = F_37 ( V_118 , V_116 ) ;
return 0 ;
}
static int F_38 ( struct V_47 * V_48 ,
const struct V_115 * V_116 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_117 * V_118 = F_36 ( V_3 ) ;
T_1 V_8 = V_128 | V_129 ;
unsigned long V_119 = F_37 ( V_118 , V_116 ) ;
if ( V_119 & V_125 )
V_8 |= V_130 ;
if ( V_119 & V_123 )
V_8 |= V_131 ;
return F_6 ( V_3 , V_132 , V_8 ) ;
}
static int F_39 ( struct V_2 * V_3 ,
const struct V_133 * V_134 )
{
struct V_1 * V_17 ;
struct V_135 * V_67 ;
struct V_136 * V_137 =
F_40 ( V_3 -> V_51 . V_138 ) ;
struct V_117 * V_118 = F_36 ( V_3 ) ;
int V_11 ;
if ( ! V_118 || ! V_118 -> V_17 ) {
F_16 ( & V_3 -> V_51 , L_8 ) ;
return - V_52 ;
}
V_67 = V_118 -> V_17 ;
if ( ! F_41 ( V_137 , V_139 ) ) {
F_16 ( & V_3 -> V_51 ,
L_9
L_10 ) ;
return - V_140 ;
}
V_17 = F_42 ( sizeof( * V_17 ) , V_141 ) ;
if ( ! V_17 )
return - V_142 ;
V_17 -> V_67 = V_67 ;
F_43 ( & V_17 -> V_4 , V_3 , & V_143 ) ;
V_11 = F_30 ( V_3 ) ;
if ( V_11 )
F_44 ( V_17 ) ;
return V_11 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
F_44 ( V_17 ) ;
return 0 ;
}
