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
struct V_39 * V_32 )
{
struct V_27 * V_28 = F_12 ( V_23 ) ;
V_32 -> V_40 = V_28 -> V_41 ;
V_32 -> V_42 = V_28 -> V_42 ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 ,
struct V_43 * V_3 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
int V_5 ;
T_1 V_4 ;
if ( V_3 -> V_3 & ~ 0xff )
return - V_38 ;
V_3 -> V_44 = 1 ;
V_5 = F_1 ( V_2 , V_3 -> V_3 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_3 -> V_4 = ( V_45 ) V_4 ;
return 0 ;
}
static int F_14 ( struct V_22 * V_23 ,
const struct V_43 * V_3 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
if ( V_3 -> V_3 & ~ 0xff || V_3 -> V_4 & ~ 0xff )
return - V_38 ;
return F_4 ( V_2 , V_3 -> V_3 , V_3 -> V_4 ) ;
}
static int F_15 ( struct V_22 * V_23 , int V_46 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
struct V_47 * V_48 = F_16 ( V_2 ) ;
return F_17 ( & V_2 -> V_16 , V_48 , V_46 ) ;
}
static void F_18 ( T_2 * V_49 , T_2 * V_50 )
{
int V_51 ;
enum { V_52 , V_53 , V_54 , V_55 , V_56 , V_57 , V_58 };
int V_59 [] = { 88 , 160 , 176 , 320 , 352 , 640 , 1280 } ;
int V_60 [] = { 72 , 120 , 144 , 240 , 288 , 480 , 960 } ;
for ( V_51 = 0 ; V_51 < F_19 ( V_59 ) ; V_51 ++ ) {
if ( V_59 [ V_51 ] >= * V_49 && V_60 [ V_51 ] >= * V_50 ) {
* V_49 = V_59 [ V_51 ] ;
* V_50 = V_60 [ V_51 ] ;
return;
}
}
* V_49 = V_59 [ V_58 ] ;
* V_50 = V_60 [ V_58 ] ;
}
static void F_20 ( enum V_61 V_62 ,
struct V_63 * V_64 )
{
switch ( V_62 ) {
default:
case V_65 :
V_64 -> V_66 = V_67 ;
V_64 -> V_68 = V_69 |
F_21 ( 0x01 ) ;
break;
case V_70 :
V_64 -> V_71 = V_72 ;
V_64 -> V_68 = V_73 ;
V_64 -> V_74 = V_75 ;
break;
case V_76 :
V_64 -> V_71 = V_72 ;
V_64 -> V_68 = V_73 ;
V_64 -> V_74 = V_77 ;
break;
} ;
}
static int F_22 ( struct V_1 * V_2 , T_2 V_49 ,
enum V_61 V_62 , struct V_63 * V_78 )
{
const struct V_79 * V_80 , * V_81 ;
int V_82 , V_83 ;
int V_51 , V_5 ;
T_1 V_4 ;
switch ( V_49 ) {
case V_84 :
V_80 = V_85 ;
V_82 = F_19 ( V_85 ) ;
break;
case V_86 :
V_80 = V_87 ;
V_82 = F_19 ( V_87 ) ;
break;
case V_88 :
V_80 = V_89 ;
V_82 = F_19 ( V_89 ) ;
break;
case V_90 :
V_80 = V_91 ;
V_82 = F_19 ( V_91 ) ;
break;
case V_92 :
V_80 = V_93 ;
V_82 = F_19 ( V_93 ) ;
break;
case V_94 :
V_80 = V_95 ;
V_82 = F_19 ( V_95 ) ;
break;
case V_96 :
V_80 = V_97 ;
V_82 = F_19 ( V_97 ) ;
break;
default:
F_3 ( & V_2 -> V_16 , L_7 ) ;
return - V_38 ;
}
if ( V_62 == V_65 ) {
V_81 = V_98 ;
V_83 = F_19 ( V_98 ) ;
} else {
V_81 = V_99 ;
V_83 = F_19 ( V_99 ) ;
}
for ( V_51 = 0 ; V_51 < V_82 ; V_51 ++ ) {
V_4 = V_80 [ V_51 ] . V_4 ;
switch ( V_80 [ V_51 ] . V_3 ) {
case V_20 :
V_4 |= V_78 -> V_71 ;
break;
case V_100 :
V_4 |= V_78 -> V_66 ;
break;
case V_101 :
V_4 |= V_78 -> V_68 ;
break;
case V_102 :
V_4 |= V_78 -> V_74 ;
break;
}
V_5 = F_4 ( V_2 , V_80 [ V_51 ] . V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
}
for ( V_51 = 0 ; V_51 < V_83 ; V_51 ++ ) {
V_5 = F_4 ( V_2 , V_81 [ V_51 ] . V_3 ,
V_81 [ V_51 ] . V_4 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_51 , V_5 ;
for ( V_51 = 0 ; V_51 < F_19 ( V_103 ) ; V_51 ++ ) {
V_5 = F_4 ( V_2 , V_103 [ V_51 ] . V_3 ,
V_103 [ V_51 ] . V_4 ) ;
if ( V_5 )
return V_5 ;
}
F_24 ( 150 ) ;
return 0 ;
}
static int F_25 ( struct V_22 * V_23 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
struct V_63 V_78 = { 0 } ;
enum V_106 V_107 ;
enum V_61 V_62 = V_105 -> V_62 ;
int V_5 ;
F_18 ( & V_105 -> V_49 , & V_105 -> V_50 ) ;
F_20 ( V_105 -> V_62 , & V_78 ) ;
F_6 ( V_2 ) ;
V_5 = F_23 ( V_2 ) ;
if ( V_5 )
return V_5 ;
switch ( V_62 ) {
case V_70 :
case V_76 :
V_107 = V_108 ;
break;
default:
V_62 = V_65 ;
case V_65 :
V_107 = V_109 ;
}
V_5 = F_22 ( V_2 , V_105 -> V_49 , V_62 , & V_78 ) ;
if ( ! V_5 ) {
V_105 -> V_62 = V_62 ;
V_105 -> V_110 = V_107 ;
}
return V_5 ;
}
static int F_26 ( struct V_22 * V_23 ,
struct V_104 * V_105 )
{
F_18 ( & V_105 -> V_49 , & V_105 -> V_50 ) ;
V_105 -> V_111 = V_112 ;
switch ( V_105 -> V_62 ) {
case V_70 :
case V_76 :
V_105 -> V_110 = V_108 ;
break;
default:
V_105 -> V_62 = V_65 ;
case V_65 :
V_105 -> V_110 = V_109 ;
}
return 0 ;
}
static int F_27 ( struct V_22 * V_23 , unsigned int V_113 ,
enum V_61 * V_62 )
{
if ( V_113 >= F_19 ( V_114 ) )
return - V_38 ;
* V_62 = V_114 [ V_113 ] ;
return 0 ;
}
static int F_28 ( struct V_22 * V_23 , struct V_115 * V_116 )
{
V_116 -> V_117 . V_118 = 0 ;
V_116 -> V_117 . V_119 = 0 ;
V_116 -> V_117 . V_49 = V_96 ;
V_116 -> V_117 . V_50 = V_120 ;
V_116 -> type = V_121 ;
return 0 ;
}
static int F_29 ( struct V_22 * V_23 , struct V_122 * V_116 )
{
V_116 -> V_123 . V_118 = 0 ;
V_116 -> V_123 . V_119 = 0 ;
V_116 -> V_123 . V_49 = V_96 ;
V_116 -> V_123 . V_50 = V_120 ;
V_116 -> V_124 = V_116 -> V_123 ;
V_116 -> type = V_121 ;
V_116 -> V_125 . V_126 = 1 ;
V_116 -> V_125 . V_127 = 1 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_31 ( V_2 ) ;
struct V_27 * V_28 = F_12 ( V_23 ) ;
T_1 V_128 , V_129 , V_130 , V_131 ;
const char * V_132 ;
int V_5 ;
V_5 = F_15 ( & V_28 -> V_31 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_133 , & V_128 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_134 , & V_129 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_135 , & V_130 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_136 , & V_131 ) ;
if ( V_5 )
goto V_137;
switch ( F_32 ( V_128 , V_129 ) ) {
case V_138 :
V_132 = L_8 ;
V_28 -> V_41 = V_139 ;
V_28 -> V_42 = 2 ;
break;
case V_140 :
V_132 = L_8 ;
V_28 -> V_41 = V_139 ;
V_28 -> V_42 = 3 ;
break;
default:
F_3 ( & V_2 -> V_16 , L_9 , V_128 , V_129 ) ;
V_5 = - V_141 ;
goto V_137;
}
F_33 ( & V_2 -> V_16 , L_10 ,
V_132 , V_128 , V_129 , V_130 , V_131 ) ;
V_5 = F_34 ( & V_28 -> V_30 ) ;
V_137:
F_15 ( & V_28 -> V_31 , 0 ) ;
return V_5 ;
}
static int F_35 ( struct V_22 * V_23 ,
struct V_142 * V_143 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
struct V_47 * V_48 = F_16 ( V_2 ) ;
V_143 -> V_10 = V_144 | V_145 |
V_146 | V_147 |
V_148 ;
V_143 -> type = V_149 ;
V_143 -> V_10 = F_36 ( V_48 , V_143 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_150 * V_151 )
{
struct V_27 * V_28 ;
struct V_47 * V_48 = F_16 ( V_2 ) ;
int V_5 ;
if ( ! V_48 ) {
F_3 ( & V_2 -> V_16 , L_11 ) ;
return - V_38 ;
}
V_28 = F_38 ( & V_2 -> V_16 , sizeof( struct V_27 ) , V_152 ) ;
if ( ! V_28 ) {
F_3 ( & V_2 -> V_16 ,
L_12 ) ;
return - V_153 ;
}
F_39 ( & V_28 -> V_31 , V_2 , & V_154 ) ;
F_40 ( & V_28 -> V_30 , 2 ) ;
F_41 ( & V_28 -> V_30 , & V_155 ,
V_33 , 0 , 1 , 1 , 0 ) ;
F_41 ( & V_28 -> V_30 , & V_155 ,
V_36 , 0 , 1 , 1 , 0 ) ;
V_28 -> V_31 . V_156 = & V_28 -> V_30 ;
if ( V_28 -> V_30 . error )
return V_28 -> V_30 . error ;
V_5 = F_30 ( V_2 ) ;
if ( V_5 )
F_42 ( & V_28 -> V_30 ) ;
return V_5 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_31 ( V_2 ) ;
struct V_27 * V_28 = F_12 ( V_23 ) ;
F_44 ( & V_28 -> V_31 ) ;
F_42 ( & V_28 -> V_30 ) ;
return 0 ;
}
