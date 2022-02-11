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
static int F_23 ( struct V_47 * V_48 , int V_65 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_66 * V_67 = F_24 ( V_3 ) ;
return F_25 ( & V_3 -> V_51 , V_67 , V_65 ) ;
}
static int F_26 ( struct V_47 * V_48 , T_4 * V_37 , T_4 * V_38 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_11 = - V_52 ;
T_1 V_8 ;
V_17 -> V_10 = F_12 ( V_17 -> V_36 , * V_37 , * V_38 ) ;
if ( ! V_17 -> V_10 )
goto V_68;
F_9 ( V_3 ) ;
V_8 = 0x00 ;
if ( V_69 == V_17 -> V_70 -> V_71 )
V_8 = V_72 ;
V_11 = F_4 ( V_3 , V_56 , V_72 , V_8 ) ;
if ( V_11 < 0 )
goto V_68;
switch ( V_17 -> V_70 -> V_73 ) {
case V_74 :
V_8 = V_75 ; break;
case V_76 :
V_8 = V_77 ; break;
case V_78 :
V_8 = V_79 ; break;
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
default:
V_8 = 0 ;
}
V_11 = F_4 ( V_3 , V_90 , V_91 , V_8 ) ;
if ( V_11 < 0 )
goto V_68;
V_11 = F_7 ( V_3 , V_17 -> V_10 ) ;
if ( V_11 < 0 )
goto V_68;
V_11 = F_8 ( V_3 ) ;
if ( V_11 < 0 )
goto V_68;
* V_37 = V_17 -> V_10 -> V_37 ;
* V_38 = V_17 -> V_10 -> V_38 ;
return V_11 ;
V_68:
F_9 ( V_3 ) ;
V_17 -> V_10 = NULL ;
return V_11 ;
}
static int F_27 ( struct V_47 * V_48 , struct V_92 * V_93 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
V_93 -> V_94 . V_95 = 0 ;
V_93 -> V_94 . V_96 = 0 ;
if ( V_17 -> V_36 & V_43 ) {
V_93 -> V_94 . V_37 = 640 ;
V_93 -> V_94 . V_38 = 480 ;
} else {
V_93 -> V_94 . V_37 = 768 ;
V_93 -> V_94 . V_38 = 576 ;
}
V_93 -> type = V_97 ;
return 0 ;
}
static int F_28 ( struct V_47 * V_48 , struct V_98 * V_93 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
V_93 -> V_99 . V_95 = 0 ;
V_93 -> V_99 . V_96 = 0 ;
if ( V_17 -> V_36 & V_43 ) {
V_93 -> V_99 . V_37 = 640 ;
V_93 -> V_99 . V_38 = 480 ;
} else {
V_93 -> V_99 . V_37 = 768 ;
V_93 -> V_99 . V_38 = 576 ;
}
V_93 -> V_100 = V_93 -> V_99 ;
V_93 -> type = V_97 ;
V_93 -> V_101 . V_102 = 1 ;
V_93 -> V_101 . V_103 = 1 ;
return 0 ;
}
static int F_29 ( struct V_47 * V_48 ,
struct V_104 * V_105 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
if ( ! V_17 -> V_10 ) {
V_17 -> V_10 = F_12 ( V_17 -> V_36 , 640 , 480 ) ;
if ( ! V_17 -> V_10 )
return - V_52 ;
}
V_105 -> V_37 = V_17 -> V_10 -> V_37 ;
V_105 -> V_38 = V_17 -> V_10 -> V_38 ;
V_105 -> V_106 = V_107 ;
V_105 -> V_108 = V_109 ;
V_105 -> V_110 = V_111 ;
return 0 ;
}
static int F_30 ( struct V_47 * V_48 ,
struct V_104 * V_105 )
{
T_4 V_37 = V_105 -> V_37 , V_38 = V_105 -> V_38 ;
int V_11 ;
F_31 ( V_105 -> V_110 != V_112 &&
V_105 -> V_110 != V_111 ) ;
if ( V_105 -> V_106 != V_107 )
return - V_52 ;
V_105 -> V_108 = V_109 ;
V_11 = F_26 ( V_48 , & V_37 , & V_38 ) ;
if ( ! V_11 ) {
V_105 -> V_37 = V_37 ;
V_105 -> V_38 = V_38 ;
}
return V_11 ;
}
static int F_32 ( struct V_47 * V_48 ,
struct V_104 * V_105 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
const struct V_9 * V_10 ;
if ( V_112 == V_105 -> V_110 ) {
V_105 -> V_110 = V_111 ;
} else if ( V_111 != V_105 -> V_110 ) {
F_16 ( & V_3 -> V_51 , L_4 , V_105 -> V_110 ) ;
return - V_52 ;
}
V_105 -> V_106 = V_107 ;
V_105 -> V_108 = V_109 ;
V_10 = F_12 ( V_17 -> V_36 , V_105 -> V_37 , V_105 -> V_38 ) ;
if ( ! V_10 )
return - V_52 ;
V_105 -> V_37 = V_10 -> V_37 ;
V_105 -> V_38 = V_10 -> V_38 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
T_2 V_59 ;
int V_11 ;
if ( V_69 != V_17 -> V_70 -> V_71 &&
V_113 != V_17 -> V_70 -> V_71 ) {
F_16 ( & V_3 -> V_51 , L_5 ) ;
return - V_114 ;
}
V_11 = F_23 ( & V_17 -> V_4 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_59 = F_5 ( V_3 , V_115 ) ;
V_17 -> V_22 = F_34 ( V_59 ) ;
V_59 = F_35 ( V_59 ) ;
if ( 0x0B != V_59 ||
0x01 < V_17 -> V_22 ) {
F_16 ( & V_3 -> V_51 ,
L_6 ,
V_59 , V_17 -> V_22 ) ;
V_11 = - V_114 ;
goto V_116;
}
F_36 ( & V_3 -> V_51 ,
L_7 , V_59 , V_17 -> V_22 ) ;
V_17 -> V_36 = V_43 ;
V_116:
F_23 ( & V_17 -> V_4 , 0 ) ;
return V_11 ;
}
static int F_37 ( struct V_47 * V_48 , unsigned int V_117 ,
enum V_118 * V_106 )
{
if ( V_117 )
return - V_52 ;
* V_106 = V_107 ;
return 0 ;
}
static int F_38 ( struct V_47 * V_48 ,
struct V_119 * V_120 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_66 * V_67 = F_24 ( V_3 ) ;
V_120 -> V_121 = V_122 | V_123 |
V_124 | V_125 |
V_126 | V_127 |
V_128 ;
V_120 -> type = V_129 ;
V_120 -> V_121 = F_39 ( V_67 , V_120 ) ;
return 0 ;
}
static int F_40 ( struct V_47 * V_48 ,
const struct V_119 * V_120 )
{
struct V_2 * V_3 = F_15 ( V_48 ) ;
struct V_66 * V_67 = F_24 ( V_3 ) ;
T_1 V_8 = V_130 | V_131 ;
unsigned long V_121 = F_39 ( V_67 , V_120 ) ;
if ( V_121 & V_127 )
V_8 |= V_132 ;
if ( V_121 & V_125 )
V_8 |= V_133 ;
return F_6 ( V_3 , V_134 , V_8 ) ;
}
static int F_41 ( struct V_2 * V_3 ,
const struct V_135 * V_136 )
{
struct V_1 * V_17 ;
struct V_137 * V_70 ;
struct V_138 * V_139 =
F_42 ( V_3 -> V_51 . V_140 ) ;
struct V_66 * V_67 = F_24 ( V_3 ) ;
if ( ! V_67 || ! V_67 -> V_141 ) {
F_16 ( & V_3 -> V_51 , L_8 ) ;
return - V_52 ;
}
V_70 = V_67 -> V_141 ;
if ( ! F_43 ( V_139 , V_142 ) ) {
F_16 ( & V_3 -> V_51 ,
L_9
L_10 ) ;
return - V_143 ;
}
V_17 = F_44 ( & V_3 -> V_51 , sizeof( * V_17 ) , V_144 ) ;
if ( ! V_17 )
return - V_145 ;
V_17 -> V_70 = V_70 ;
F_45 ( & V_17 -> V_4 , V_3 , & V_146 ) ;
return F_33 ( V_3 ) ;
}
static int F_46 ( struct V_2 * V_3 )
{
return 0 ;
}
