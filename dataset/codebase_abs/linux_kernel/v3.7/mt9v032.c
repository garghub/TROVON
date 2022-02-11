static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , const T_1 V_7 )
{
T_2 V_8 = F_4 ( V_6 , V_7 ) ;
F_5 ( & V_6 -> V_9 , L_1 , V_10 ,
V_8 , V_7 ) ;
return V_8 ;
}
static int F_6 ( struct V_5 * V_6 , const T_1 V_7 ,
const T_3 V_8 )
{
F_5 ( & V_6 -> V_9 , L_2 , V_10 ,
V_8 , V_7 ) ;
return F_7 ( V_6 , V_7 , V_8 ) ;
}
static int F_8 ( struct V_1 * V_1 , T_3 V_11 , T_3 V_12 )
{
struct V_5 * V_6 = F_9 ( & V_1 -> V_4 ) ;
T_3 V_13 = ( V_1 -> V_14 & ~ V_11 ) | V_12 ;
int V_15 ;
V_15 = F_6 ( V_6 , V_16 , V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
V_1 -> V_14 = V_13 ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_1 , T_3 V_17 , int V_18 )
{
struct V_5 * V_6 = F_9 ( & V_1 -> V_4 ) ;
T_3 V_13 = V_1 -> V_19 ;
int V_15 ;
if ( V_18 )
V_13 |= V_17 ;
else
V_13 &= ~ V_17 ;
V_15 = F_6 ( V_6 , V_20 , V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
V_1 -> V_19 = V_13 ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_9 ( & V_1 -> V_4 ) ;
struct V_21 * V_22 = & V_1 -> V_22 ;
return F_6 ( V_6 , V_23 ,
F_12 ( T_2 , V_1 -> V_24 , 660 - V_22 -> V_25 ) ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_9 ( & V_1 -> V_4 ) ;
int V_15 ;
if ( V_1 -> V_26 -> V_27 ) {
V_1 -> V_26 -> V_27 ( & V_1 -> V_4 , V_1 -> V_28 ) ;
F_14 ( 1 ) ;
}
V_15 = F_6 ( V_6 , V_29 , 1 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_6 ( V_6 , V_29 , 0 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_6 ( V_6 , V_16 , 0 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
if ( V_1 -> V_26 -> V_27 )
V_1 -> V_26 -> V_27 ( & V_1 -> V_4 , 0 ) ;
}
static int F_16 ( struct V_1 * V_1 , bool V_30 )
{
struct V_5 * V_6 = F_9 ( & V_1 -> V_4 ) ;
int V_15 ;
if ( ! V_30 ) {
F_15 ( V_1 ) ;
return 0 ;
}
V_15 = F_13 ( V_1 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_1 -> V_26 && V_1 -> V_26 -> V_31 ) {
V_15 = F_6 ( V_6 , V_32 ,
V_33 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_15 = F_6 ( V_6 , V_34 , 0 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_17 ( & V_1 -> V_35 ) ;
}
static struct V_36 *
F_18 ( struct V_1 * V_1 , struct V_37 * V_38 ,
unsigned int V_39 , enum V_40 V_17 )
{
switch ( V_17 ) {
case V_41 :
return F_19 ( V_38 , V_39 ) ;
case V_42 :
return & V_1 -> V_43 ;
default:
return NULL ;
}
}
static struct V_21 *
F_20 ( struct V_1 * V_1 , struct V_37 * V_38 ,
unsigned int V_39 , enum V_40 V_17 )
{
switch ( V_17 ) {
case V_41 :
return F_21 ( V_38 , V_39 ) ;
case V_42 :
return & V_1 -> V_22 ;
default:
return NULL ;
}
}
static int F_22 ( struct V_2 * V_4 , int V_18 )
{
const T_3 V_44 = V_45
| V_46
| V_47 ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_36 * V_43 = & V_1 -> V_43 ;
struct V_21 * V_22 = & V_1 -> V_22 ;
unsigned int V_48 ;
unsigned int V_49 ;
int V_15 ;
if ( ! V_18 )
return F_8 ( V_1 , V_44 , 0 ) ;
V_48 = F_23 ( V_22 -> V_25 , V_43 -> V_25 ) ;
V_49 = F_23 ( V_22 -> V_50 , V_43 -> V_50 ) ;
V_15 = F_6 ( V_6 , V_51 ,
( V_48 - 1 ) << V_52 |
( V_49 - 1 ) << V_53 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_6 ( V_6 , V_54 , V_22 -> V_55 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_6 ( V_6 , V_56 , V_22 -> V_57 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_6 ( V_6 , V_58 , V_22 -> V_25 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_6 ( V_6 , V_59 , V_22 -> V_50 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_11 ( V_1 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_8 ( V_1 , 0 , V_44 ) ;
}
static int F_24 ( struct V_2 * V_4 ,
struct V_37 * V_38 ,
struct V_60 * V_61 )
{
if ( V_61 -> V_62 > 0 )
return - V_63 ;
V_61 -> V_61 = V_64 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_4 ,
struct V_37 * V_38 ,
struct V_65 * V_66 )
{
if ( V_66 -> V_62 >= 8 || V_66 -> V_61 != V_64 )
return - V_63 ;
V_66 -> V_67 = V_68 / V_66 -> V_62 ;
V_66 -> V_69 = V_66 -> V_67 ;
V_66 -> V_70 = V_71 / V_66 -> V_62 ;
V_66 -> V_72 = V_66 -> V_70 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_4 ,
struct V_37 * V_38 ,
struct V_73 * V_43 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_43 -> V_43 = * F_18 ( V_1 , V_38 , V_43 -> V_39 ,
V_43 -> V_17 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_1 ,
unsigned int V_48 )
{
struct V_5 * V_6 = F_9 ( & V_1 -> V_4 ) ;
int V_15 ;
V_15 = F_28 ( V_1 -> V_74 ,
V_1 -> V_28 / V_48 ) ;
if ( V_15 < 0 )
F_29 ( & V_6 -> V_9 , L_3 , V_15 ) ;
}
static int F_30 ( struct V_2 * V_4 ,
struct V_37 * V_38 ,
struct V_73 * V_43 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_36 * V_75 ;
struct V_21 * V_76 ;
unsigned int V_25 ;
unsigned int V_50 ;
unsigned int V_48 ;
unsigned int V_49 ;
V_76 = F_20 ( V_1 , V_38 , V_43 -> V_39 ,
V_43 -> V_17 ) ;
V_25 = F_31 (unsigned int, ALIGN(format->format.width, 2),
max(__crop->width / 8, MT9V032_WINDOW_WIDTH_MIN),
__crop->width) ;
V_50 = F_31 (unsigned int, ALIGN(format->format.height, 2),
max(__crop->height / 8, MT9V032_WINDOW_HEIGHT_MIN),
__crop->height) ;
V_48 = F_23 ( V_76 -> V_25 , V_25 ) ;
V_49 = F_23 ( V_76 -> V_50 , V_50 ) ;
V_75 = F_18 ( V_1 , V_38 , V_43 -> V_39 ,
V_43 -> V_17 ) ;
V_75 -> V_25 = V_76 -> V_25 / V_48 ;
V_75 -> V_50 = V_76 -> V_50 / V_49 ;
if ( V_43 -> V_17 == V_42 )
F_27 ( V_1 , V_48 ) ;
V_43 -> V_43 = * V_75 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_4 ,
struct V_37 * V_38 ,
struct V_77 * V_22 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_22 -> V_78 = * F_20 ( V_1 , V_38 , V_22 -> V_39 ,
V_22 -> V_17 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_4 ,
struct V_37 * V_38 ,
struct V_77 * V_22 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_36 * V_75 ;
struct V_21 * V_76 ;
struct V_21 V_78 ;
V_78 . V_55 = F_34 ( F_35 ( V_22 -> V_78 . V_55 + 1 , 2 ) - 1 ,
V_79 ,
V_80 ) ;
V_78 . V_57 = F_34 ( F_35 ( V_22 -> V_78 . V_57 + 1 , 2 ) - 1 ,
V_81 ,
V_82 ) ;
V_78 . V_25 = F_34 ( F_35 ( V_22 -> V_78 . V_25 , 2 ) ,
V_83 ,
V_84 ) ;
V_78 . V_50 = F_34 ( F_35 ( V_22 -> V_78 . V_50 , 2 ) ,
V_85 ,
V_86 ) ;
V_78 . V_25 = F_36 ( V_78 . V_25 , V_87 - V_78 . V_55 ) ;
V_78 . V_50 = F_36 ( V_78 . V_50 , V_88 - V_78 . V_57 ) ;
V_76 = F_20 ( V_1 , V_38 , V_22 -> V_39 , V_22 -> V_17 ) ;
if ( V_78 . V_25 != V_76 -> V_25 || V_78 . V_50 != V_76 -> V_50 ) {
V_75 = F_18 ( V_1 , V_38 , V_22 -> V_39 ,
V_22 -> V_17 ) ;
V_75 -> V_25 = V_78 . V_25 ;
V_75 -> V_50 = V_78 . V_50 ;
if ( V_22 -> V_17 == V_42 )
F_27 ( V_1 , 1 ) ;
}
* V_76 = V_78 ;
V_22 -> V_78 = V_78 ;
return 0 ;
}
static int F_37 ( struct V_89 * V_90 )
{
struct V_1 * V_1 =
F_2 ( V_90 -> V_91 , struct V_1 , V_35 ) ;
struct V_5 * V_6 = F_9 ( & V_1 -> V_4 ) ;
T_4 V_92 ;
T_3 V_8 ;
switch ( V_90 -> V_93 ) {
case V_94 :
return F_10 ( V_1 , V_95 ,
V_90 -> V_96 ) ;
case V_97 :
return F_6 ( V_6 , V_98 , V_90 -> V_96 ) ;
case V_99 :
return F_10 ( V_1 , V_100 ,
! V_90 -> V_96 ) ;
case V_101 :
return F_6 ( V_6 , V_102 ,
V_90 -> V_96 ) ;
case V_103 :
V_1 -> V_24 = V_90 -> V_96 ;
return F_11 ( V_1 ) ;
case V_104 :
return F_6 ( V_6 , V_105 ,
V_90 -> V_96 ) ;
case V_106 :
case V_107 :
if ( V_1 -> V_108 == NULL )
break;
V_92 = V_1 -> V_26 -> V_109 [ V_1 -> V_108 -> V_96 ] ;
V_1 -> V_74 -> V_110 = V_92 ;
V_1 -> V_28 = V_92 ;
break;
case V_111 :
switch ( V_1 -> V_112 -> V_96 ) {
case 0 :
V_8 = 0 ;
break;
case 1 :
V_8 = V_113
| V_114 ;
break;
case 2 :
V_8 = V_115
| V_114 ;
break;
case 3 :
V_8 = V_116
| V_114 ;
break;
default:
V_8 = ( V_1 -> V_117 -> V_96 <<
V_118 )
| V_119
| V_114
| V_120 ;
break;
}
return F_6 ( V_6 , V_121 , V_8 ) ;
}
return 0 ;
}
static int F_38 ( struct V_2 * V_4 , int V_30 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_15 = 0 ;
F_39 ( & V_1 -> V_122 ) ;
if ( V_1 -> V_123 == ! V_30 ) {
V_15 = F_16 ( V_1 , ! ! V_30 ) ;
if ( V_15 < 0 )
goto V_124;
}
V_1 -> V_123 += V_30 ? 1 : - 1 ;
F_40 ( V_1 -> V_123 < 0 ) ;
V_124:
F_41 ( & V_1 -> V_122 ) ;
return V_15 ;
}
static int F_42 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
T_2 V_8 ;
int V_15 ;
F_43 ( & V_6 -> V_9 , L_4 ,
V_6 -> V_125 ) ;
V_15 = F_13 ( V_1 ) ;
if ( V_15 < 0 ) {
F_44 ( & V_6 -> V_9 , L_5 ) ;
return V_15 ;
}
V_8 = F_3 ( V_6 , V_126 ) ;
if ( V_8 != V_127 && V_8 != V_128 ) {
F_44 ( & V_6 -> V_9 , L_6
L_7 , V_8 ) ;
return - V_129 ;
}
F_15 ( V_1 ) ;
F_43 ( & V_6 -> V_9 , L_8 ,
V_6 -> V_125 ) ;
F_27 ( V_1 , 1 ) ;
return V_15 ;
}
static int F_45 ( struct V_2 * V_4 , struct V_37 * V_38 )
{
struct V_36 * V_43 ;
struct V_21 * V_22 ;
V_22 = F_21 ( V_38 , 0 ) ;
V_22 -> V_55 = V_130 ;
V_22 -> V_57 = V_131 ;
V_22 -> V_25 = V_68 ;
V_22 -> V_50 = V_71 ;
V_43 = F_19 ( V_38 , 0 ) ;
V_43 -> V_61 = V_64 ;
V_43 -> V_25 = V_68 ;
V_43 -> V_50 = V_71 ;
V_43 -> V_132 = V_133 ;
V_43 -> V_134 = V_135 ;
return F_38 ( V_4 , 1 ) ;
}
static int F_46 ( struct V_2 * V_4 , struct V_37 * V_38 )
{
return F_38 ( V_4 , 0 ) ;
}
static int F_47 ( struct V_5 * V_6 ,
const struct V_136 * V_137 )
{
struct V_138 * V_26 = V_6 -> V_9 . V_139 ;
struct V_1 * V_1 ;
unsigned int V_140 ;
int V_15 ;
if ( ! F_48 ( V_6 -> V_141 ,
V_142 ) ) {
F_29 ( & V_6 -> V_141 -> V_9 ,
L_9 ) ;
return - V_143 ;
}
V_1 = F_49 ( sizeof( * V_1 ) , V_144 ) ;
if ( ! V_1 )
return - V_145 ;
F_50 ( & V_1 -> V_122 ) ;
V_1 -> V_26 = V_26 ;
F_51 ( & V_1 -> V_35 , 10 ) ;
F_52 ( & V_1 -> V_35 , & V_146 ,
V_94 , 0 , 1 , 1 , 1 ) ;
F_52 ( & V_1 -> V_35 , & V_146 ,
V_97 , V_147 ,
V_148 , 1 , V_149 ) ;
F_53 ( & V_1 -> V_35 , & V_146 ,
V_99 , V_150 , 0 ,
V_151 ) ;
F_52 ( & V_1 -> V_35 , & V_146 ,
V_101 , V_152 ,
V_153 , 1 ,
V_154 ) ;
F_52 ( & V_1 -> V_35 , & V_146 ,
V_103 , V_155 ,
V_156 , 1 ,
V_157 ) ;
F_52 ( & V_1 -> V_35 , & V_146 ,
V_104 , V_158 ,
V_159 , 1 ,
V_160 ) ;
V_1 -> V_112 = F_54 ( & V_1 -> V_35 ,
& V_146 , V_111 ,
F_55 ( V_161 ) - 1 , 0 , 0 ,
V_161 ) ;
V_1 -> V_117 = F_56 ( & V_1 -> V_35 ,
& V_162 , NULL ) ;
F_57 ( 2 , & V_1 -> V_112 ) ;
V_1 -> V_74 =
F_52 ( & V_1 -> V_35 , & V_146 ,
V_106 , 0 , 0 , 1 , 0 ) ;
if ( V_26 && V_26 -> V_109 ) {
unsigned int V_163 = 0 ;
for ( V_140 = 0 ; V_26 -> V_109 [ V_140 ] ; ++ V_140 ) {
if ( V_26 -> V_109 [ V_140 ] == V_26 -> V_164 )
V_163 = V_140 ;
}
V_1 -> V_108 =
F_58 ( & V_1 -> V_35 ,
& V_146 ,
V_107 , V_140 - 1 , V_163 ,
V_26 -> V_109 ) ;
F_57 ( 2 , & V_1 -> V_108 ) ;
}
V_1 -> V_4 . V_165 = & V_1 -> V_35 ;
if ( V_1 -> V_35 . error )
F_59 ( V_166 L_10 ,
V_10 , V_1 -> V_35 . error ) ;
V_1 -> V_22 . V_55 = V_130 ;
V_1 -> V_22 . V_57 = V_131 ;
V_1 -> V_22 . V_25 = V_68 ;
V_1 -> V_22 . V_50 = V_71 ;
V_1 -> V_43 . V_61 = V_64 ;
V_1 -> V_43 . V_25 = V_68 ;
V_1 -> V_43 . V_50 = V_71 ;
V_1 -> V_43 . V_132 = V_133 ;
V_1 -> V_43 . V_134 = V_135 ;
V_1 -> V_19 = V_100 | V_95 ;
V_1 -> V_24 = V_157 ;
V_1 -> V_28 = V_167 ;
F_60 ( & V_1 -> V_4 , V_6 , & V_168 ) ;
V_1 -> V_4 . V_169 = & V_170 ;
V_1 -> V_4 . V_171 |= V_172 ;
V_1 -> V_39 . V_171 = V_173 ;
V_15 = F_61 ( & V_1 -> V_4 . V_174 , 1 , & V_1 -> V_39 , 0 ) ;
if ( V_15 < 0 )
F_62 ( V_1 ) ;
return V_15 ;
}
static int F_63 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_64 ( V_6 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_65 ( V_4 ) ;
F_66 ( & V_4 -> V_174 ) ;
F_62 ( V_1 ) ;
return 0 ;
}
