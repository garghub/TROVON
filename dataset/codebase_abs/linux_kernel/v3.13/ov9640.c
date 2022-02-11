static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
T_1 V_6 = V_3 ;
struct V_7 V_8 = {
. V_9 = V_2 -> V_9 ,
. V_10 = 0 ,
. V_11 = 1 ,
. V_12 = & V_6 ,
} ;
V_5 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ;
if ( V_5 < 0 )
goto V_14;
V_8 . V_10 = V_15 ;
V_5 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ;
if ( V_5 < 0 )
goto V_14;
* V_4 = V_6 ;
return 0 ;
V_14:
F_3 ( & V_2 -> V_16 , L_1 , V_3 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_17 ;
unsigned char V_6 [ 2 ] = { V_3 , V_4 } ;
struct V_7 V_8 = {
. V_9 = V_2 -> V_9 ,
. V_10 = 0 ,
. V_11 = 2 ,
. V_12 = V_6 ,
} ;
V_5 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_16 , L_2 , V_3 ) ;
return V_5 ;
}
V_5 = F_1 ( V_2 , V_3 , & V_17 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_16 ,
L_3 , V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_18 , T_1 V_19 )
{
T_1 V_4 ;
int V_5 ;
V_5 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_16 ,
L_4 , V_3 ) ;
return V_4 ;
}
V_4 |= V_18 ;
V_4 &= ~ V_19 ;
V_5 = F_4 ( V_2 , V_3 , V_4 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_16 ,
L_5 , V_3 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_4 ( V_2 , V_20 , V_21 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_16 ,
L_6 ) ;
return V_5 ;
}
static int F_7 ( struct V_22 * V_23 , int V_24 )
{
return 0 ;
}
static int F_8 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_9 ( V_26 -> V_29 , struct V_27 , V_30 ) ;
struct V_1 * V_2 = F_10 ( & V_28 -> V_31 ) ;
switch ( V_26 -> V_32 ) {
case V_33 :
if ( V_26 -> V_4 )
return F_5 ( V_2 , V_34 ,
V_35 , 0 ) ;
return F_5 ( V_2 , V_34 , 0 , V_35 ) ;
case V_36 :
if ( V_26 -> V_4 )
return F_5 ( V_2 , V_34 ,
V_37 , 0 ) ;
return F_5 ( V_2 , V_34 , 0 , V_37 ) ;
}
return - V_38 ;
}
static int F_11 ( struct V_22 * V_23 ,
struct V_39 * V_3 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
int V_5 ;
T_1 V_4 ;
if ( V_3 -> V_3 & ~ 0xff )
return - V_38 ;
V_3 -> V_40 = 1 ;
V_5 = F_1 ( V_2 , V_3 -> V_3 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_3 -> V_4 = ( V_41 ) V_4 ;
return 0 ;
}
static int F_12 ( struct V_22 * V_23 ,
const struct V_39 * V_3 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
if ( V_3 -> V_3 & ~ 0xff || V_3 -> V_4 & ~ 0xff )
return - V_38 ;
return F_4 ( V_2 , V_3 -> V_3 , V_3 -> V_4 ) ;
}
static int F_13 ( struct V_22 * V_23 , int V_42 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
struct V_43 * V_44 = F_14 ( V_2 ) ;
struct V_27 * V_28 = F_15 ( V_23 ) ;
return F_16 ( & V_2 -> V_16 , V_44 , V_28 -> V_45 , V_42 ) ;
}
static void F_17 ( T_2 * V_46 , T_2 * V_47 )
{
int V_48 ;
enum { V_49 , V_50 , V_51 , V_52 , V_53 , V_54 , V_55 };
int V_56 [] = { 88 , 160 , 176 , 320 , 352 , 640 , 1280 } ;
int V_57 [] = { 72 , 120 , 144 , 240 , 288 , 480 , 960 } ;
for ( V_48 = 0 ; V_48 < F_18 ( V_56 ) ; V_48 ++ ) {
if ( V_56 [ V_48 ] >= * V_46 && V_57 [ V_48 ] >= * V_47 ) {
* V_46 = V_56 [ V_48 ] ;
* V_47 = V_57 [ V_48 ] ;
return;
}
}
* V_46 = V_56 [ V_55 ] ;
* V_47 = V_57 [ V_55 ] ;
}
static void F_19 ( enum V_58 V_59 ,
struct V_60 * V_61 )
{
switch ( V_59 ) {
default:
case V_62 :
V_61 -> V_63 = V_64 ;
V_61 -> V_65 = V_66 |
F_20 ( 0x01 ) ;
break;
case V_67 :
V_61 -> V_68 = V_69 ;
V_61 -> V_65 = V_70 ;
V_61 -> V_71 = V_72 ;
break;
case V_73 :
V_61 -> V_68 = V_69 ;
V_61 -> V_65 = V_70 ;
V_61 -> V_71 = V_74 ;
break;
}
}
static int F_21 ( struct V_1 * V_2 , T_2 V_46 ,
enum V_58 V_59 , struct V_60 * V_75 )
{
const struct V_76 * V_77 , * V_78 ;
int V_79 , V_80 ;
int V_48 , V_5 ;
T_1 V_4 ;
switch ( V_46 ) {
case V_81 :
V_77 = V_82 ;
V_79 = F_18 ( V_82 ) ;
break;
case V_83 :
V_77 = V_84 ;
V_79 = F_18 ( V_84 ) ;
break;
case V_85 :
V_77 = V_86 ;
V_79 = F_18 ( V_86 ) ;
break;
case V_87 :
V_77 = V_88 ;
V_79 = F_18 ( V_88 ) ;
break;
case V_89 :
V_77 = V_90 ;
V_79 = F_18 ( V_90 ) ;
break;
case V_91 :
V_77 = V_92 ;
V_79 = F_18 ( V_92 ) ;
break;
case V_93 :
V_77 = V_94 ;
V_79 = F_18 ( V_94 ) ;
break;
default:
F_3 ( & V_2 -> V_16 , L_7 ) ;
return - V_38 ;
}
if ( V_59 == V_62 ) {
V_78 = V_95 ;
V_80 = F_18 ( V_95 ) ;
} else {
V_78 = V_96 ;
V_80 = F_18 ( V_96 ) ;
}
for ( V_48 = 0 ; V_48 < V_79 ; V_48 ++ ) {
V_4 = V_77 [ V_48 ] . V_4 ;
switch ( V_77 [ V_48 ] . V_3 ) {
case V_20 :
V_4 |= V_75 -> V_68 ;
break;
case V_97 :
V_4 |= V_75 -> V_63 ;
break;
case V_98 :
V_4 |= V_75 -> V_65 ;
break;
case V_99 :
V_4 |= V_75 -> V_71 ;
break;
}
V_5 = F_4 ( V_2 , V_77 [ V_48 ] . V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
}
for ( V_48 = 0 ; V_48 < V_80 ; V_48 ++ ) {
V_5 = F_4 ( V_2 , V_78 [ V_48 ] . V_3 ,
V_78 [ V_48 ] . V_4 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_48 , V_5 ;
for ( V_48 = 0 ; V_48 < F_18 ( V_100 ) ; V_48 ++ ) {
V_5 = F_4 ( V_2 , V_100 [ V_48 ] . V_3 ,
V_100 [ V_48 ] . V_4 ) ;
if ( V_5 )
return V_5 ;
}
F_23 ( 150 ) ;
return 0 ;
}
static int F_24 ( struct V_22 * V_23 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
struct V_60 V_75 = { 0 } ;
enum V_103 V_104 ;
enum V_58 V_59 = V_102 -> V_59 ;
int V_5 ;
F_17 ( & V_102 -> V_46 , & V_102 -> V_47 ) ;
F_19 ( V_102 -> V_59 , & V_75 ) ;
F_6 ( V_2 ) ;
V_5 = F_22 ( V_2 ) ;
if ( V_5 )
return V_5 ;
switch ( V_59 ) {
case V_67 :
case V_73 :
V_104 = V_105 ;
break;
default:
V_59 = V_62 ;
case V_62 :
V_104 = V_106 ;
}
V_5 = F_21 ( V_2 , V_102 -> V_46 , V_59 , & V_75 ) ;
if ( ! V_5 ) {
V_102 -> V_59 = V_59 ;
V_102 -> V_107 = V_104 ;
}
return V_5 ;
}
static int F_25 ( struct V_22 * V_23 ,
struct V_101 * V_102 )
{
F_17 ( & V_102 -> V_46 , & V_102 -> V_47 ) ;
V_102 -> V_108 = V_109 ;
switch ( V_102 -> V_59 ) {
case V_67 :
case V_73 :
V_102 -> V_107 = V_105 ;
break;
default:
V_102 -> V_59 = V_62 ;
case V_62 :
V_102 -> V_107 = V_106 ;
}
return 0 ;
}
static int F_26 ( struct V_22 * V_23 , unsigned int V_110 ,
enum V_58 * V_59 )
{
if ( V_110 >= F_18 ( V_111 ) )
return - V_38 ;
* V_59 = V_111 [ V_110 ] ;
return 0 ;
}
static int F_27 ( struct V_22 * V_23 , struct V_112 * V_113 )
{
V_113 -> V_114 . V_115 = 0 ;
V_113 -> V_114 . V_116 = 0 ;
V_113 -> V_114 . V_46 = V_93 ;
V_113 -> V_114 . V_47 = V_117 ;
V_113 -> type = V_118 ;
return 0 ;
}
static int F_28 ( struct V_22 * V_23 , struct V_119 * V_113 )
{
V_113 -> V_120 . V_115 = 0 ;
V_113 -> V_120 . V_116 = 0 ;
V_113 -> V_120 . V_46 = V_93 ;
V_113 -> V_120 . V_47 = V_117 ;
V_113 -> V_121 = V_113 -> V_120 ;
V_113 -> type = V_118 ;
V_113 -> V_122 . V_123 = 1 ;
V_113 -> V_122 . V_124 = 1 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_30 ( V_2 ) ;
struct V_27 * V_28 = F_15 ( V_23 ) ;
T_1 V_125 , V_126 , V_127 , V_128 ;
const char * V_129 ;
int V_5 ;
V_5 = F_13 ( & V_28 -> V_31 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_130 , & V_125 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_131 , & V_126 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_132 , & V_127 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_133 , & V_128 ) ;
if ( V_5 )
goto V_134;
switch ( F_31 ( V_125 , V_126 ) ) {
case V_135 :
V_129 = L_8 ;
V_28 -> V_136 = 2 ;
break;
case V_137 :
V_129 = L_8 ;
V_28 -> V_136 = 3 ;
break;
default:
F_3 ( & V_2 -> V_16 , L_9 , V_125 , V_126 ) ;
V_5 = - V_138 ;
goto V_134;
}
F_32 ( & V_2 -> V_16 , L_10 ,
V_129 , V_125 , V_126 , V_127 , V_128 ) ;
V_5 = F_33 ( & V_28 -> V_30 ) ;
V_134:
F_13 ( & V_28 -> V_31 , 0 ) ;
return V_5 ;
}
static int F_34 ( struct V_22 * V_23 ,
struct V_139 * V_140 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
struct V_43 * V_44 = F_14 ( V_2 ) ;
V_140 -> V_10 = V_141 | V_142 |
V_143 | V_144 |
V_145 ;
V_140 -> type = V_146 ;
V_140 -> V_10 = F_35 ( V_44 , V_140 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_147 * V_148 )
{
struct V_27 * V_28 ;
struct V_43 * V_44 = F_14 ( V_2 ) ;
int V_5 ;
if ( ! V_44 ) {
F_3 ( & V_2 -> V_16 , L_11 ) ;
return - V_38 ;
}
V_28 = F_37 ( & V_2 -> V_16 , sizeof( struct V_27 ) , V_149 ) ;
if ( ! V_28 ) {
F_3 ( & V_2 -> V_16 ,
L_12 ) ;
return - V_150 ;
}
F_38 ( & V_28 -> V_31 , V_2 , & V_151 ) ;
F_39 ( & V_28 -> V_30 , 2 ) ;
F_40 ( & V_28 -> V_30 , & V_152 ,
V_33 , 0 , 1 , 1 , 0 ) ;
F_40 ( & V_28 -> V_30 , & V_152 ,
V_36 , 0 , 1 , 1 , 0 ) ;
V_28 -> V_31 . V_153 = & V_28 -> V_30 ;
if ( V_28 -> V_30 . error )
return V_28 -> V_30 . error ;
V_28 -> V_45 = F_41 ( & V_2 -> V_16 , L_13 ) ;
if ( F_42 ( V_28 -> V_45 ) ) {
V_5 = F_43 ( V_28 -> V_45 ) ;
goto V_154;
}
V_5 = F_29 ( V_2 ) ;
if ( V_5 ) {
F_44 ( V_28 -> V_45 ) ;
V_154:
F_45 ( & V_28 -> V_30 ) ;
}
return V_5 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_30 ( V_2 ) ;
struct V_27 * V_28 = F_15 ( V_23 ) ;
F_44 ( V_28 -> V_45 ) ;
F_47 ( & V_28 -> V_31 ) ;
F_45 ( & V_28 -> V_30 ) ;
return 0 ;
}
