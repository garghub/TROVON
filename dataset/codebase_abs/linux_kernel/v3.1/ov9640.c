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
static int F_8 ( struct V_25 * V_26 ,
unsigned long V_10 )
{
return 0 ;
}
static unsigned long F_9 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_10 ( V_26 ) ;
unsigned long V_10 = V_29 | V_30 |
V_31 | V_32 |
V_33 | V_34 ;
return F_11 ( V_28 , V_10 ) ;
}
static int F_12 ( struct V_22 * V_23 , struct V_35 * V_36 )
{
struct V_37 * V_38 = F_13 ( V_23 ) ;
switch ( V_36 -> V_39 ) {
case V_40 :
V_36 -> V_41 = V_38 -> V_42 ;
break;
case V_43 :
V_36 -> V_41 = V_38 -> V_44 ;
break;
}
return 0 ;
}
static int F_14 ( struct V_22 * V_23 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_37 * V_38 = F_13 ( V_23 ) ;
int V_5 = 0 ;
switch ( V_36 -> V_39 ) {
case V_40 :
V_38 -> V_42 = V_36 -> V_41 ;
if ( V_36 -> V_41 )
V_5 = F_5 ( V_2 , V_45 ,
V_46 , 0 ) ;
else
V_5 = F_5 ( V_2 , V_45 ,
0 , V_46 ) ;
break;
case V_43 :
V_38 -> V_44 = V_36 -> V_41 ;
if ( V_36 -> V_41 )
V_5 = F_5 ( V_2 , V_45 ,
V_47 , 0 ) ;
else
V_5 = F_5 ( V_2 , V_45 ,
0 , V_47 ) ;
break;
}
return V_5 ;
}
static int F_16 ( struct V_22 * V_23 ,
struct V_48 * V_39 )
{
struct V_37 * V_38 = F_13 ( V_23 ) ;
V_39 -> V_49 = V_38 -> V_50 ;
V_39 -> V_51 = V_38 -> V_51 ;
return 0 ;
}
static int F_17 ( struct V_22 * V_23 ,
struct V_52 * V_3 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
int V_5 ;
T_1 V_4 ;
if ( V_3 -> V_3 & ~ 0xff )
return - V_53 ;
V_3 -> V_54 = 1 ;
V_5 = F_1 ( V_2 , V_3 -> V_3 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_3 -> V_4 = ( V_55 ) V_4 ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 ,
struct V_52 * V_3 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
if ( V_3 -> V_3 & ~ 0xff || V_3 -> V_4 & ~ 0xff )
return - V_53 ;
return F_4 ( V_2 , V_3 -> V_3 , V_3 -> V_4 ) ;
}
static void F_19 ( T_2 * V_56 , T_2 * V_57 )
{
int V_58 ;
enum { V_59 , V_60 , V_61 , V_62 , V_63 , V_64 , V_65 };
int V_66 [] = { 88 , 160 , 176 , 320 , 352 , 640 , 1280 } ;
int V_67 [] = { 72 , 120 , 144 , 240 , 288 , 480 , 960 } ;
for ( V_58 = 0 ; V_58 < F_20 ( V_66 ) ; V_58 ++ ) {
if ( V_66 [ V_58 ] >= * V_56 && V_67 [ V_58 ] >= * V_57 ) {
* V_56 = V_66 [ V_58 ] ;
* V_57 = V_67 [ V_58 ] ;
return;
}
}
* V_56 = V_66 [ V_65 ] ;
* V_57 = V_67 [ V_65 ] ;
}
static void F_21 ( enum V_68 V_69 ,
struct V_70 * V_71 )
{
switch ( V_69 ) {
default:
case V_72 :
V_71 -> V_73 = V_74 ;
V_71 -> V_75 = V_76 |
F_22 ( 0x01 ) ;
break;
case V_77 :
V_71 -> V_78 = V_79 ;
V_71 -> V_75 = V_80 ;
V_71 -> V_81 = V_82 ;
break;
case V_83 :
V_71 -> V_78 = V_79 ;
V_71 -> V_75 = V_80 ;
V_71 -> V_81 = V_84 ;
break;
} ;
}
static int F_23 ( struct V_1 * V_2 , T_2 V_56 ,
enum V_68 V_69 , struct V_70 * V_85 )
{
const struct V_86 * V_87 , * V_88 ;
int V_89 , V_90 ;
int V_58 , V_5 ;
T_1 V_4 ;
switch ( V_56 ) {
case V_91 :
V_87 = V_92 ;
V_89 = F_20 ( V_92 ) ;
break;
case V_93 :
V_87 = V_94 ;
V_89 = F_20 ( V_94 ) ;
break;
case V_95 :
V_87 = V_96 ;
V_89 = F_20 ( V_96 ) ;
break;
case V_97 :
V_87 = V_98 ;
V_89 = F_20 ( V_98 ) ;
break;
case V_99 :
V_87 = V_100 ;
V_89 = F_20 ( V_100 ) ;
break;
case V_101 :
V_87 = V_102 ;
V_89 = F_20 ( V_102 ) ;
break;
case V_103 :
V_87 = V_104 ;
V_89 = F_20 ( V_104 ) ;
break;
default:
F_3 ( & V_2 -> V_16 , L_7 ) ;
return - V_53 ;
}
if ( V_69 == V_72 ) {
V_88 = V_105 ;
V_90 = F_20 ( V_105 ) ;
} else {
V_88 = V_106 ;
V_90 = F_20 ( V_106 ) ;
}
for ( V_58 = 0 ; V_58 < V_89 ; V_58 ++ ) {
V_4 = V_87 [ V_58 ] . V_4 ;
switch ( V_87 [ V_58 ] . V_3 ) {
case V_20 :
V_4 |= V_85 -> V_78 ;
break;
case V_107 :
V_4 |= V_85 -> V_73 ;
break;
case V_108 :
V_4 |= V_85 -> V_75 ;
break;
case V_109 :
V_4 |= V_85 -> V_81 ;
break;
}
V_5 = F_4 ( V_2 , V_87 [ V_58 ] . V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
}
for ( V_58 = 0 ; V_58 < V_90 ; V_58 ++ ) {
V_5 = F_4 ( V_2 , V_88 [ V_58 ] . V_3 ,
V_88 [ V_58 ] . V_4 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_58 , V_5 ;
for ( V_58 = 0 ; V_58 < F_20 ( V_110 ) ; V_58 ++ ) {
V_5 = F_4 ( V_2 , V_110 [ V_58 ] . V_3 ,
V_110 [ V_58 ] . V_4 ) ;
if ( V_5 )
return V_5 ;
}
F_25 ( 150 ) ;
return 0 ;
}
static int F_26 ( struct V_22 * V_23 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_70 V_85 = { 0 } ;
enum V_113 V_114 ;
enum V_68 V_69 = V_112 -> V_69 ;
int V_5 ;
F_19 ( & V_112 -> V_56 , & V_112 -> V_57 ) ;
F_21 ( V_112 -> V_69 , & V_85 ) ;
F_6 ( V_2 ) ;
V_5 = F_24 ( V_2 ) ;
if ( V_5 )
return V_5 ;
switch ( V_69 ) {
case V_77 :
case V_83 :
V_114 = V_115 ;
break;
default:
V_69 = V_72 ;
case V_72 :
V_114 = V_116 ;
}
V_5 = F_23 ( V_2 , V_112 -> V_56 , V_69 , & V_85 ) ;
if ( ! V_5 ) {
V_112 -> V_69 = V_69 ;
V_112 -> V_117 = V_114 ;
}
return V_5 ;
}
static int F_27 ( struct V_22 * V_23 ,
struct V_111 * V_112 )
{
F_19 ( & V_112 -> V_56 , & V_112 -> V_57 ) ;
V_112 -> V_118 = V_119 ;
switch ( V_112 -> V_69 ) {
case V_77 :
case V_83 :
V_112 -> V_117 = V_115 ;
break;
default:
V_112 -> V_69 = V_72 ;
case V_72 :
V_112 -> V_117 = V_116 ;
}
return 0 ;
}
static int F_28 ( struct V_22 * V_23 , unsigned int V_120 ,
enum V_68 * V_69 )
{
if ( V_120 >= F_20 ( V_121 ) )
return - V_53 ;
* V_69 = V_121 [ V_120 ] ;
return 0 ;
}
static int F_29 ( struct V_22 * V_23 , struct V_122 * V_123 )
{
V_123 -> V_124 . V_125 = 0 ;
V_123 -> V_124 . V_126 = 0 ;
V_123 -> V_124 . V_56 = V_103 ;
V_123 -> V_124 . V_57 = V_127 ;
V_123 -> type = V_128 ;
return 0 ;
}
static int F_30 ( struct V_22 * V_23 , struct V_129 * V_123 )
{
V_123 -> V_130 . V_125 = 0 ;
V_123 -> V_130 . V_126 = 0 ;
V_123 -> V_130 . V_56 = V_103 ;
V_123 -> V_130 . V_57 = V_127 ;
V_123 -> V_131 = V_123 -> V_130 ;
V_123 -> type = V_128 ;
V_123 -> V_132 . V_133 = 1 ;
V_123 -> V_132 . V_134 = 1 ;
return 0 ;
}
static int F_31 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = F_32 ( V_2 ) ;
struct V_37 * V_38 = F_13 ( V_23 ) ;
T_1 V_135 , V_136 , V_137 , V_138 ;
const char * V_139 ;
int V_5 = 0 ;
F_33 ( ! V_26 -> V_140 ||
F_34 ( V_26 -> V_140 ) -> V_141 != V_26 -> V_142 ) ;
V_5 = F_1 ( V_2 , V_143 , & V_135 ) ;
if ( V_5 )
goto V_14;
V_5 = F_1 ( V_2 , V_144 , & V_136 ) ;
if ( V_5 )
goto V_14;
V_5 = F_1 ( V_2 , V_145 , & V_137 ) ;
if ( V_5 )
goto V_14;
V_5 = F_1 ( V_2 , V_146 , & V_138 ) ;
if ( V_5 )
goto V_14;
switch ( F_35 ( V_135 , V_136 ) ) {
case V_147 :
V_139 = L_8 ;
V_38 -> V_50 = V_148 ;
V_38 -> V_51 = 2 ;
case V_149 :
V_139 = L_8 ;
V_38 -> V_50 = V_148 ;
V_38 -> V_51 = 3 ;
break;
default:
F_3 ( & V_2 -> V_16 , L_9 , V_135 , V_136 ) ;
V_5 = - V_150 ;
goto V_14;
}
F_36 ( & V_2 -> V_16 , L_10 ,
V_139 , V_135 , V_136 , V_137 , V_138 ) ;
V_14:
return V_5 ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_151 * V_152 )
{
struct V_37 * V_38 ;
struct V_25 * V_26 = V_2 -> V_16 . V_153 ;
struct V_27 * V_28 ;
int V_5 ;
if ( ! V_26 ) {
F_3 ( & V_2 -> V_16 , L_11 ) ;
return - V_53 ;
}
V_28 = F_10 ( V_26 ) ;
if ( ! V_28 ) {
F_3 ( & V_2 -> V_16 , L_12 ) ;
return - V_53 ;
}
V_38 = F_38 ( sizeof( struct V_37 ) , V_154 ) ;
if ( ! V_38 ) {
F_3 ( & V_2 -> V_16 ,
L_13 ) ;
return - V_155 ;
}
F_39 ( & V_38 -> V_156 , V_2 , & V_157 ) ;
V_26 -> V_158 = & V_159 ;
V_5 = F_31 ( V_26 , V_2 ) ;
if ( V_5 ) {
V_26 -> V_158 = NULL ;
F_40 ( V_38 ) ;
}
return V_5 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_32 ( V_2 ) ;
struct V_37 * V_38 = F_13 ( V_23 ) ;
F_40 ( V_38 ) ;
return 0 ;
}
static int T_3 F_42 ( void )
{
return F_43 ( & V_160 ) ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_160 ) ;
}
