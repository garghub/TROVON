static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , T_1 V_7 )
{
return F_4 ( V_6 , V_7 ) ;
}
static int F_5 ( struct V_5 * V_6 , T_1 V_7 , T_2 V_8 )
{
return F_6 ( V_6 , V_7 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_1 , T_2 V_9 ,
T_2 V_10 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
T_2 V_11 = ( V_1 -> V_12 & ~ V_9 ) | V_10 ;
int V_13 ;
if ( V_11 == V_1 -> V_12 )
return 0 ;
V_13 = F_5 ( V_6 , V_14 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
V_1 -> V_12 = V_11 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
int V_13 ;
V_13 = F_5 ( V_6 , V_15 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_15 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_1 -> V_12 = V_16 ;
return F_7 ( V_1 ,
V_17 ,
0 ) ;
}
static int F_10 ( struct V_1 * V_1 )
{
int V_13 ;
V_13 = F_11 ( F_12 ( V_1 -> V_18 ) ,
V_1 -> V_18 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_13 ( V_1 -> V_19 ) ;
if ( V_13 < 0 )
F_14 ( F_12 ( V_1 -> V_18 ) ,
V_1 -> V_18 ) ;
return V_13 ;
}
static void F_15 ( struct V_1 * V_1 )
{
F_14 ( F_12 ( V_1 -> V_18 ) ,
V_1 -> V_18 ) ;
F_16 ( V_1 -> V_19 ) ;
}
static int F_17 ( struct V_1 * V_1 , bool V_20 )
{
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
int V_13 ;
if ( ! V_20 ) {
F_15 ( V_1 ) ;
return 0 ;
}
V_13 = F_10 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_1 ) ;
if ( V_13 < 0 ) {
F_18 ( & V_6 -> V_21 , L_1 ) ;
goto V_22;
}
V_13 = F_19 ( & V_1 -> V_23 ) ;
if ( V_13 < 0 ) {
F_18 ( & V_6 -> V_21 , L_2 ) ;
goto V_22;
}
return 0 ;
V_22:
F_15 ( V_1 ) ;
return V_13 ;
}
static struct V_24 *
F_20 ( struct V_1 * V_1 , struct V_25 * V_26 ,
unsigned int V_27 , enum V_28 V_29 )
{
switch ( V_29 ) {
case V_30 :
return F_21 ( & V_1 -> V_4 , V_26 , V_27 ) ;
case V_31 :
return & V_1 -> V_32 ;
default:
return NULL ;
}
}
static struct V_33 *
F_22 ( struct V_1 * V_1 , struct V_25 * V_26 ,
unsigned int V_27 , enum V_28 V_29 )
{
switch ( V_29 ) {
case V_30 :
return F_23 ( & V_1 -> V_4 , V_26 , V_27 ) ;
case V_31 :
return & V_1 -> V_34 ;
default:
return NULL ;
}
}
static int F_24 ( struct V_2 * V_4 , int V_35 )
{
const T_2 V_36 = V_17 ;
struct V_5 * V_6 = F_8 ( V_4 ) ;
struct V_37 * V_38 = V_6 -> V_21 . V_39 ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_24 * V_32 = & V_1 -> V_32 ;
struct V_33 * V_34 = & V_1 -> V_34 ;
unsigned int V_40 ;
unsigned int V_41 ;
int V_13 ;
if ( ! V_35 )
return F_7 ( V_1 , V_36 , 0 ) ;
if ( V_38 -> V_42 ) {
V_13 = F_5 ( V_6 , V_43 ,
V_44 ) ;
if ( V_13 < 0 )
return V_13 ;
}
V_40 = F_25 ( V_34 -> V_45 , V_32 -> V_45 ) ;
V_41 = F_25 ( V_34 -> V_46 , V_32 -> V_46 ) ;
V_13 = F_5 ( V_6 , V_47 , V_40 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_48 , V_41 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_49 , V_34 -> V_50 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_51 , V_34 -> V_52 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_53 , V_34 -> V_45 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_54 , V_34 -> V_46 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_7 ( V_1 , 0 , V_36 ) ;
}
static int F_26 ( struct V_2 * V_4 ,
struct V_25 * V_26 ,
struct V_55 * V_56 )
{
if ( V_56 -> V_57 > 0 )
return - V_58 ;
V_56 -> V_56 = V_59 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_4 ,
struct V_25 * V_26 ,
struct V_60 * V_61 )
{
if ( V_61 -> V_57 >= 8 || V_61 -> V_56 != V_59 )
return - V_58 ;
V_61 -> V_62 = ( V_63 + 1 ) / V_61 -> V_57 ;
V_61 -> V_64 = V_61 -> V_62 ;
V_61 -> V_65 = ( V_66 + 1 ) / V_61 -> V_57 ;
V_61 -> V_67 = V_61 -> V_65 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_4 ,
struct V_25 * V_26 ,
struct V_68 * V_32 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_32 -> V_32 = * F_20 ( V_1 , V_26 , V_32 -> V_27 ,
V_32 -> V_29 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_4 ,
struct V_25 * V_26 ,
struct V_68 * V_32 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_24 * V_69 ;
struct V_33 * V_70 ;
unsigned int V_45 ;
unsigned int V_46 ;
unsigned int V_40 ;
unsigned int V_41 ;
V_70 = F_22 ( V_1 , V_26 , V_32 -> V_27 ,
V_32 -> V_29 ) ;
V_45 = F_30 (unsigned int, ALIGN(format->format.width, 2),
max_t(unsigned int, __crop->width / 8,
MT9T001_WINDOW_HEIGHT_MIN + 1),
__crop->width) ;
V_46 = F_30 (unsigned int, ALIGN(format->format.height, 2),
max_t(unsigned int, __crop->height / 8,
MT9T001_WINDOW_HEIGHT_MIN + 1),
__crop->height) ;
V_40 = F_25 ( V_70 -> V_45 , V_45 ) ;
V_41 = F_25 ( V_70 -> V_46 , V_46 ) ;
V_69 = F_20 ( V_1 , V_26 , V_32 -> V_27 ,
V_32 -> V_29 ) ;
V_69 -> V_45 = V_70 -> V_45 / V_40 ;
V_69 -> V_46 = V_70 -> V_46 / V_41 ;
V_32 -> V_32 = * V_69 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_4 ,
struct V_25 * V_26 ,
struct V_71 * V_72 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_72 -> V_73 != V_74 )
return - V_58 ;
V_72 -> V_75 = * F_22 ( V_1 , V_26 , V_72 -> V_27 , V_72 -> V_29 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_4 ,
struct V_25 * V_26 ,
struct V_71 * V_72 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_24 * V_69 ;
struct V_33 * V_70 ;
struct V_33 V_76 ;
if ( V_72 -> V_73 != V_74 )
return - V_58 ;
V_76 . V_50 = F_33 ( F_34 ( V_72 -> V_75 . V_50 , 2 ) ,
V_77 ,
V_78 ) ;
V_76 . V_52 = F_33 ( F_34 ( V_72 -> V_75 . V_52 , 2 ) ,
V_79 ,
V_80 ) ;
V_76 . V_45 = F_30 (unsigned int, ALIGN(sel->r.width, 2),
MT9T001_WINDOW_WIDTH_MIN + 1 ,
MT9T001_WINDOW_WIDTH_MAX + 1 ) ;
V_76 . V_46 = F_30 (unsigned int, ALIGN(sel->r.height, 2),
MT9T001_WINDOW_HEIGHT_MIN + 1 ,
MT9T001_WINDOW_HEIGHT_MAX + 1 ) ;
V_76 . V_45 = F_35 (unsigned int, rect.width,
MT9T001_PIXEL_ARRAY_WIDTH - rect.left) ;
V_76 . V_46 = F_35 (unsigned int, rect.height,
MT9T001_PIXEL_ARRAY_HEIGHT - rect.top) ;
V_70 = F_22 ( V_1 , V_26 , V_72 -> V_27 , V_72 -> V_29 ) ;
if ( V_76 . V_45 != V_70 -> V_45 || V_76 . V_46 != V_70 -> V_46 ) {
V_69 = F_20 ( V_1 , V_26 , V_72 -> V_27 ,
V_72 -> V_29 ) ;
V_69 -> V_45 = V_76 . V_45 ;
V_69 -> V_46 = V_76 . V_46 ;
}
* V_70 = V_76 ;
V_72 -> V_75 = V_76 ;
return 0 ;
}
static T_2 F_36 ( T_3 * V_81 )
{
if ( * V_81 <= 32 )
return * V_81 ;
if ( * V_81 <= 64 ) {
* V_81 &= ~ 1 ;
return ( 1 << 6 ) | ( * V_81 >> 1 ) ;
}
* V_81 &= ~ 7 ;
return ( ( * V_81 - 64 ) << 5 ) | ( 1 << 6 ) | 32 ;
}
static int F_37 ( struct V_1 * V_1 , bool V_82 )
{
return F_7 ( V_1 ,
V_82 ? 0 : V_83 ,
V_82 ? V_83 : 0 ) ;
}
static int F_38 ( struct V_84 * V_85 )
{
static const T_1 V_86 [ 4 ] = {
V_87 , V_88 ,
V_89 , V_90
} ;
struct V_1 * V_1 =
F_2 ( V_85 -> V_91 , struct V_1 , V_23 ) ;
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
unsigned int V_92 ;
unsigned int V_93 ;
T_2 V_11 ;
int V_13 ;
switch ( V_85 -> V_94 ) {
case V_95 :
case V_96 :
case V_97 :
case V_98 :
for ( V_93 = 0 , V_92 = 0 ; V_93 < 4 ; ++ V_93 ) {
struct V_84 * V_81 = V_1 -> V_86 [ V_93 ] ;
if ( V_81 -> V_99 != V_81 -> V_100 . V_99 )
V_92 ++ ;
}
if ( V_92 > 1 ) {
V_13 = F_37 ( V_1 , true ) ;
if ( V_13 < 0 )
return V_13 ;
}
for ( V_93 = 0 ; V_93 < 4 ; ++ V_93 ) {
struct V_84 * V_81 = V_1 -> V_86 [ V_93 ] ;
if ( V_81 -> V_99 == V_81 -> V_100 . V_99 )
continue;
V_11 = F_36 ( & V_81 -> V_99 ) ;
V_13 = F_5 ( V_6 , V_86 [ V_93 ] , V_11 ) ;
if ( V_13 < 0 ) {
F_37 ( V_1 , false ) ;
return V_13 ;
}
}
if ( V_92 > 1 ) {
V_13 = F_37 ( V_1 , false ) ;
if ( V_13 < 0 )
return V_13 ;
}
break;
case V_101 :
V_13 = F_5 ( V_6 , V_102 ,
V_85 -> V_99 & 0xffff ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_103 ,
V_85 -> V_99 >> 16 ) ;
case V_104 :
return F_7 ( V_1 ,
V_85 -> V_99 ? 0 : V_105 ,
V_85 -> V_99 ? V_105 : 0 ) ;
case V_106 :
return F_5 ( V_6 , V_107 , V_85 -> V_99 << 2 ) ;
case V_108 :
V_11 = V_85 -> V_99 ? 0 : V_109 ;
V_13 = F_5 ( V_6 , V_110 ,
V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
V_1 -> V_111 = V_11 ;
break;
case V_112 :
V_13 = F_5 ( V_6 , V_113 , V_85 -> V_99 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_114 , V_85 -> V_99 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_115 , V_85 -> V_99 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_116 , V_85 -> V_99 ) ;
case V_117 :
return F_5 ( V_6 , V_110 ,
V_118 |
V_1 -> V_111 ) ;
}
return 0 ;
}
static int F_39 ( struct V_2 * V_4 , int V_20 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_13 = 0 ;
F_40 ( & V_1 -> V_119 ) ;
if ( V_1 -> V_120 == ! V_20 ) {
V_13 = F_17 ( V_1 , ! ! V_20 ) ;
if ( V_13 < 0 )
goto V_121;
}
V_1 -> V_120 += V_20 ? 1 : - 1 ;
F_41 ( V_1 -> V_120 < 0 ) ;
V_121:
F_42 ( & V_1 -> V_119 ) ;
return V_13 ;
}
static int F_43 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_8 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
T_3 V_8 ;
int V_13 ;
V_13 = F_10 ( V_1 ) ;
if ( V_13 < 0 ) {
F_18 ( & V_6 -> V_21 , L_3 ) ;
return V_13 ;
}
V_8 = F_3 ( V_6 , V_122 ) ;
F_15 ( V_1 ) ;
if ( V_8 != V_123 ) {
F_18 ( & V_6 -> V_21 ,
L_4 , V_8 ) ;
return - V_124 ;
}
F_44 ( & V_6 -> V_21 , L_5 ,
V_6 -> V_125 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_4 , struct V_126 * V_127 )
{
struct V_24 * V_32 ;
struct V_33 * V_34 ;
V_34 = F_23 ( V_4 , V_127 -> V_27 , 0 ) ;
V_34 -> V_50 = V_128 ;
V_34 -> V_52 = V_129 ;
V_34 -> V_45 = V_63 + 1 ;
V_34 -> V_46 = V_66 + 1 ;
V_32 = F_21 ( V_4 , V_127 -> V_27 , 0 ) ;
V_32 -> V_56 = V_59 ;
V_32 -> V_45 = V_63 + 1 ;
V_32 -> V_46 = V_66 + 1 ;
V_32 -> V_130 = V_131 ;
V_32 -> V_132 = V_133 ;
return F_39 ( V_4 , 1 ) ;
}
static int F_46 ( struct V_2 * V_4 , struct V_126 * V_127 )
{
return F_39 ( V_4 , 0 ) ;
}
static int F_47 ( struct V_5 * V_6 ,
const struct V_134 * V_135 )
{
struct V_37 * V_38 = V_6 -> V_21 . V_39 ;
struct V_1 * V_1 ;
unsigned int V_93 ;
int V_13 ;
if ( V_38 == NULL ) {
F_18 ( & V_6 -> V_21 , L_6 ) ;
return - V_58 ;
}
if ( ! F_48 ( V_6 -> V_136 ,
V_137 ) ) {
F_49 ( & V_6 -> V_136 -> V_21 ,
L_7 ) ;
return - V_138 ;
}
V_1 = F_50 ( & V_6 -> V_21 , sizeof( * V_1 ) , V_139 ) ;
if ( ! V_1 )
return - V_140 ;
F_51 ( & V_1 -> V_119 ) ;
V_1 -> V_12 = V_16 ;
V_1 -> V_18 [ 0 ] . V_141 = L_8 ;
V_1 -> V_18 [ 1 ] . V_141 = L_9 ;
V_13 = F_52 ( & V_6 -> V_21 , 2 , V_1 -> V_18 ) ;
if ( V_13 < 0 ) {
F_18 ( & V_6 -> V_21 , L_10 ) ;
return V_13 ;
}
V_1 -> V_19 = F_53 ( & V_6 -> V_21 , NULL ) ;
if ( F_54 ( V_1 -> V_19 ) ) {
F_18 ( & V_6 -> V_21 , L_11 ) ;
return F_55 ( V_1 -> V_19 ) ;
}
F_56 ( & V_1 -> V_23 , F_12 ( V_142 ) +
F_12 ( V_143 ) + 4 ) ;
F_57 ( & V_1 -> V_23 , & V_144 ,
V_101 , V_145 ,
V_146 , 1 ,
V_147 ) ;
F_57 ( & V_1 -> V_23 , & V_144 ,
V_148 , 1 , 1 , 1 , 1 ) ;
F_57 ( & V_1 -> V_23 , & V_144 ,
V_149 , V_38 -> V_150 , V_38 -> V_150 ,
1 , V_38 -> V_150 ) ;
F_58 ( & V_1 -> V_23 , & V_144 ,
V_104 ,
F_12 ( V_151 ) - 1 , 0 ,
0 , V_151 ) ;
for ( V_93 = 0 ; V_93 < F_12 ( V_142 ) ; ++ V_93 )
F_59 ( & V_1 -> V_23 , & V_142 [ V_93 ] , NULL ) ;
for ( V_93 = 0 ; V_93 < F_12 ( V_143 ) ; ++ V_93 )
V_1 -> V_86 [ V_93 ] = F_59 ( & V_1 -> V_23 ,
& V_143 [ V_93 ] , NULL ) ;
F_60 ( F_12 ( V_143 ) , V_1 -> V_86 ) ;
V_1 -> V_4 . V_152 = & V_1 -> V_23 ;
if ( V_1 -> V_23 . error ) {
F_61 ( V_153 L_12 ,
V_154 , V_1 -> V_23 . error ) ;
V_13 = - V_58 ;
goto V_155;
}
V_1 -> V_34 . V_50 = V_128 ;
V_1 -> V_34 . V_52 = V_129 ;
V_1 -> V_34 . V_45 = V_63 + 1 ;
V_1 -> V_34 . V_46 = V_66 + 1 ;
V_1 -> V_32 . V_56 = V_59 ;
V_1 -> V_32 . V_45 = V_63 + 1 ;
V_1 -> V_32 . V_46 = V_66 + 1 ;
V_1 -> V_32 . V_130 = V_131 ;
V_1 -> V_32 . V_132 = V_133 ;
F_62 ( & V_1 -> V_4 , V_6 , & V_156 ) ;
V_1 -> V_4 . V_157 = & V_158 ;
V_1 -> V_4 . V_159 |= V_160 ;
V_1 -> V_27 . V_159 = V_161 ;
V_13 = F_63 ( & V_1 -> V_4 . V_162 , 1 , & V_1 -> V_27 ) ;
V_155:
if ( V_13 < 0 ) {
F_64 ( & V_1 -> V_23 ) ;
F_65 ( & V_1 -> V_4 . V_162 ) ;
}
return V_13 ;
}
static int F_66 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_67 ( V_6 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_64 ( & V_1 -> V_23 ) ;
F_68 ( V_4 ) ;
F_65 ( & V_4 -> V_162 ) ;
return 0 ;
}
