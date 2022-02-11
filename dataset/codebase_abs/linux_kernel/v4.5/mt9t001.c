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
return V_13 ;
}
return F_19 ( & V_1 -> V_22 ) ;
}
static struct V_23 *
F_20 ( struct V_1 * V_1 , struct V_24 * V_25 ,
unsigned int V_26 , enum V_27 V_28 )
{
switch ( V_28 ) {
case V_29 :
return F_21 ( & V_1 -> V_4 , V_25 , V_26 ) ;
case V_30 :
return & V_1 -> V_31 ;
default:
return NULL ;
}
}
static struct V_32 *
F_22 ( struct V_1 * V_1 , struct V_24 * V_25 ,
unsigned int V_26 , enum V_27 V_28 )
{
switch ( V_28 ) {
case V_29 :
return F_23 ( & V_1 -> V_4 , V_25 , V_26 ) ;
case V_30 :
return & V_1 -> V_33 ;
default:
return NULL ;
}
}
static int F_24 ( struct V_2 * V_4 , int V_34 )
{
const T_2 V_35 = V_17 ;
struct V_5 * V_6 = F_8 ( V_4 ) ;
struct V_36 * V_37 = V_6 -> V_21 . V_38 ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_23 * V_31 = & V_1 -> V_31 ;
struct V_32 * V_33 = & V_1 -> V_33 ;
unsigned int V_39 ;
unsigned int V_40 ;
int V_13 ;
if ( ! V_34 )
return F_7 ( V_1 , V_35 , 0 ) ;
if ( V_37 -> V_41 ) {
V_13 = F_5 ( V_6 , V_42 ,
V_43 ) ;
if ( V_13 < 0 )
return V_13 ;
}
V_39 = F_25 ( V_33 -> V_44 , V_31 -> V_44 ) ;
V_40 = F_25 ( V_33 -> V_45 , V_31 -> V_45 ) ;
V_13 = F_5 ( V_6 , V_46 , V_39 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_47 , V_40 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_48 , V_33 -> V_49 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_50 , V_33 -> V_51 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_52 , V_33 -> V_44 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_53 , V_33 -> V_45 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_7 ( V_1 , 0 , V_35 ) ;
}
static int F_26 ( struct V_2 * V_4 ,
struct V_24 * V_25 ,
struct V_54 * V_55 )
{
if ( V_55 -> V_56 > 0 )
return - V_57 ;
V_55 -> V_55 = V_58 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_4 ,
struct V_24 * V_25 ,
struct V_59 * V_60 )
{
if ( V_60 -> V_56 >= 8 || V_60 -> V_55 != V_58 )
return - V_57 ;
V_60 -> V_61 = ( V_62 + 1 ) / V_60 -> V_56 ;
V_60 -> V_63 = V_60 -> V_61 ;
V_60 -> V_64 = ( V_65 + 1 ) / V_60 -> V_56 ;
V_60 -> V_66 = V_60 -> V_64 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_4 ,
struct V_24 * V_25 ,
struct V_67 * V_31 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_31 -> V_31 = * F_20 ( V_1 , V_25 , V_31 -> V_26 ,
V_31 -> V_28 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_4 ,
struct V_24 * V_25 ,
struct V_67 * V_31 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_23 * V_68 ;
struct V_32 * V_69 ;
unsigned int V_44 ;
unsigned int V_45 ;
unsigned int V_39 ;
unsigned int V_40 ;
V_69 = F_22 ( V_1 , V_25 , V_31 -> V_26 ,
V_31 -> V_28 ) ;
V_44 = F_30 (unsigned int, ALIGN(format->format.width, 2),
max_t(unsigned int, __crop->width / 8,
MT9T001_WINDOW_HEIGHT_MIN + 1),
__crop->width) ;
V_45 = F_30 (unsigned int, ALIGN(format->format.height, 2),
max_t(unsigned int, __crop->height / 8,
MT9T001_WINDOW_HEIGHT_MIN + 1),
__crop->height) ;
V_39 = F_25 ( V_69 -> V_44 , V_44 ) ;
V_40 = F_25 ( V_69 -> V_45 , V_45 ) ;
V_68 = F_20 ( V_1 , V_25 , V_31 -> V_26 ,
V_31 -> V_28 ) ;
V_68 -> V_44 = V_69 -> V_44 / V_39 ;
V_68 -> V_45 = V_69 -> V_45 / V_40 ;
V_31 -> V_31 = * V_68 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_4 ,
struct V_24 * V_25 ,
struct V_70 * V_71 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( V_71 -> V_72 != V_73 )
return - V_57 ;
V_71 -> V_74 = * F_22 ( V_1 , V_25 , V_71 -> V_26 , V_71 -> V_28 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_4 ,
struct V_24 * V_25 ,
struct V_70 * V_71 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_23 * V_68 ;
struct V_32 * V_69 ;
struct V_32 V_75 ;
if ( V_71 -> V_72 != V_73 )
return - V_57 ;
V_75 . V_49 = F_33 ( F_34 ( V_71 -> V_74 . V_49 , 2 ) ,
V_76 ,
V_77 ) ;
V_75 . V_51 = F_33 ( F_34 ( V_71 -> V_74 . V_51 , 2 ) ,
V_78 ,
V_79 ) ;
V_75 . V_44 = F_30 (unsigned int, ALIGN(sel->r.width, 2),
MT9T001_WINDOW_WIDTH_MIN + 1 ,
MT9T001_WINDOW_WIDTH_MAX + 1 ) ;
V_75 . V_45 = F_30 (unsigned int, ALIGN(sel->r.height, 2),
MT9T001_WINDOW_HEIGHT_MIN + 1 ,
MT9T001_WINDOW_HEIGHT_MAX + 1 ) ;
V_75 . V_44 = F_35 (unsigned int, rect.width,
MT9T001_PIXEL_ARRAY_WIDTH - rect.left) ;
V_75 . V_45 = F_35 (unsigned int, rect.height,
MT9T001_PIXEL_ARRAY_HEIGHT - rect.top) ;
V_69 = F_22 ( V_1 , V_25 , V_71 -> V_26 , V_71 -> V_28 ) ;
if ( V_75 . V_44 != V_69 -> V_44 || V_75 . V_45 != V_69 -> V_45 ) {
V_68 = F_20 ( V_1 , V_25 , V_71 -> V_26 ,
V_71 -> V_28 ) ;
V_68 -> V_44 = V_75 . V_44 ;
V_68 -> V_45 = V_75 . V_45 ;
}
* V_69 = V_75 ;
V_71 -> V_74 = V_75 ;
return 0 ;
}
static T_2 F_36 ( T_3 * V_80 )
{
if ( * V_80 <= 32 )
return * V_80 ;
if ( * V_80 <= 64 ) {
* V_80 &= ~ 1 ;
return ( 1 << 6 ) | ( * V_80 >> 1 ) ;
}
* V_80 &= ~ 7 ;
return ( ( * V_80 - 64 ) << 5 ) | ( 1 << 6 ) | 32 ;
}
static int F_37 ( struct V_1 * V_1 , bool V_81 )
{
return F_7 ( V_1 ,
V_81 ? 0 : V_82 ,
V_81 ? V_82 : 0 ) ;
}
static int F_38 ( struct V_83 * V_84 )
{
static const T_1 V_85 [ 4 ] = {
V_86 , V_87 ,
V_88 , V_89
} ;
struct V_1 * V_1 =
F_2 ( V_84 -> V_90 , struct V_1 , V_22 ) ;
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
unsigned int V_91 ;
unsigned int V_92 ;
T_2 V_11 ;
int V_13 ;
switch ( V_84 -> V_93 ) {
case V_94 :
case V_95 :
case V_96 :
case V_97 :
for ( V_92 = 0 , V_91 = 0 ; V_92 < 4 ; ++ V_92 ) {
struct V_83 * V_80 = V_1 -> V_85 [ V_92 ] ;
if ( V_80 -> V_98 != V_80 -> V_99 . V_98 )
V_91 ++ ;
}
if ( V_91 > 1 ) {
V_13 = F_37 ( V_1 , true ) ;
if ( V_13 < 0 )
return V_13 ;
}
for ( V_92 = 0 ; V_92 < 4 ; ++ V_92 ) {
struct V_83 * V_80 = V_1 -> V_85 [ V_92 ] ;
if ( V_80 -> V_98 == V_80 -> V_99 . V_98 )
continue;
V_11 = F_36 ( & V_80 -> V_98 ) ;
V_13 = F_5 ( V_6 , V_85 [ V_92 ] , V_11 ) ;
if ( V_13 < 0 ) {
F_37 ( V_1 , false ) ;
return V_13 ;
}
}
if ( V_91 > 1 ) {
V_13 = F_37 ( V_1 , false ) ;
if ( V_13 < 0 )
return V_13 ;
}
break;
case V_100 :
V_13 = F_5 ( V_6 , V_101 ,
V_84 -> V_98 & 0xffff ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_102 ,
V_84 -> V_98 >> 16 ) ;
case V_103 :
return F_7 ( V_1 ,
V_84 -> V_98 ? 0 : V_104 ,
V_84 -> V_98 ? V_104 : 0 ) ;
case V_105 :
return F_5 ( V_6 , V_106 , V_84 -> V_98 << 2 ) ;
case V_107 :
V_11 = V_84 -> V_98 ? 0 : V_108 ;
V_13 = F_5 ( V_6 , V_109 ,
V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
V_1 -> V_110 = V_11 ;
break;
case V_111 :
V_13 = F_5 ( V_6 , V_112 , V_84 -> V_98 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_113 , V_84 -> V_98 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_114 , V_84 -> V_98 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_115 , V_84 -> V_98 ) ;
case V_116 :
return F_5 ( V_6 , V_109 ,
V_117 |
V_1 -> V_110 ) ;
}
return 0 ;
}
static int F_39 ( struct V_2 * V_4 , int V_20 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_13 = 0 ;
F_40 ( & V_1 -> V_118 ) ;
if ( V_1 -> V_119 == ! V_20 ) {
V_13 = F_17 ( V_1 , ! ! V_20 ) ;
if ( V_13 < 0 )
goto V_120;
}
V_1 -> V_119 += V_20 ? 1 : - 1 ;
F_41 ( V_1 -> V_119 < 0 ) ;
V_120:
F_42 ( & V_1 -> V_118 ) ;
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
F_18 ( & V_6 -> V_21 , L_2 ) ;
return V_13 ;
}
V_8 = F_3 ( V_6 , V_121 ) ;
F_15 ( V_1 ) ;
if ( V_8 != V_122 ) {
F_18 ( & V_6 -> V_21 ,
L_3 , V_8 ) ;
return - V_123 ;
}
F_44 ( & V_6 -> V_21 , L_4 ,
V_6 -> V_124 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_4 , struct V_125 * V_126 )
{
struct V_23 * V_31 ;
struct V_32 * V_33 ;
V_33 = F_23 ( V_4 , V_126 -> V_26 , 0 ) ;
V_33 -> V_49 = V_127 ;
V_33 -> V_51 = V_128 ;
V_33 -> V_44 = V_62 + 1 ;
V_33 -> V_45 = V_65 + 1 ;
V_31 = F_21 ( V_4 , V_126 -> V_26 , 0 ) ;
V_31 -> V_55 = V_58 ;
V_31 -> V_44 = V_62 + 1 ;
V_31 -> V_45 = V_65 + 1 ;
V_31 -> V_129 = V_130 ;
V_31 -> V_131 = V_132 ;
return F_39 ( V_4 , 1 ) ;
}
static int F_46 ( struct V_2 * V_4 , struct V_125 * V_126 )
{
return F_39 ( V_4 , 0 ) ;
}
static int F_47 ( struct V_5 * V_6 ,
const struct V_133 * V_134 )
{
struct V_36 * V_37 = V_6 -> V_21 . V_38 ;
struct V_1 * V_1 ;
unsigned int V_92 ;
int V_13 ;
if ( V_37 == NULL ) {
F_18 ( & V_6 -> V_21 , L_5 ) ;
return - V_57 ;
}
if ( ! F_48 ( V_6 -> V_135 ,
V_136 ) ) {
F_49 ( & V_6 -> V_135 -> V_21 ,
L_6 ) ;
return - V_137 ;
}
V_1 = F_50 ( & V_6 -> V_21 , sizeof( * V_1 ) , V_138 ) ;
if ( ! V_1 )
return - V_139 ;
F_51 ( & V_1 -> V_118 ) ;
V_1 -> V_12 = V_16 ;
V_1 -> V_18 [ 0 ] . V_140 = L_7 ;
V_1 -> V_18 [ 1 ] . V_140 = L_8 ;
V_13 = F_52 ( & V_6 -> V_21 , 2 , V_1 -> V_18 ) ;
if ( V_13 < 0 ) {
F_18 ( & V_6 -> V_21 , L_9 ) ;
return V_13 ;
}
V_1 -> V_19 = F_53 ( & V_6 -> V_21 , NULL ) ;
if ( F_54 ( V_1 -> V_19 ) ) {
F_18 ( & V_6 -> V_21 , L_10 ) ;
return F_55 ( V_1 -> V_19 ) ;
}
F_56 ( & V_1 -> V_22 , F_12 ( V_141 ) +
F_12 ( V_142 ) + 4 ) ;
F_57 ( & V_1 -> V_22 , & V_143 ,
V_100 , V_144 ,
V_145 , 1 ,
V_146 ) ;
F_57 ( & V_1 -> V_22 , & V_143 ,
V_147 , 1 , 1 , 1 , 1 ) ;
F_57 ( & V_1 -> V_22 , & V_143 ,
V_148 , V_37 -> V_149 , V_37 -> V_149 ,
1 , V_37 -> V_149 ) ;
F_58 ( & V_1 -> V_22 , & V_143 ,
V_103 ,
F_12 ( V_150 ) - 1 , 0 ,
0 , V_150 ) ;
for ( V_92 = 0 ; V_92 < F_12 ( V_141 ) ; ++ V_92 )
F_59 ( & V_1 -> V_22 , & V_141 [ V_92 ] , NULL ) ;
for ( V_92 = 0 ; V_92 < F_12 ( V_142 ) ; ++ V_92 )
V_1 -> V_85 [ V_92 ] = F_59 ( & V_1 -> V_22 ,
& V_142 [ V_92 ] , NULL ) ;
F_60 ( F_12 ( V_142 ) , V_1 -> V_85 ) ;
V_1 -> V_4 . V_151 = & V_1 -> V_22 ;
if ( V_1 -> V_22 . error ) {
F_61 ( V_152 L_11 ,
V_153 , V_1 -> V_22 . error ) ;
V_13 = - V_57 ;
goto V_154;
}
V_1 -> V_33 . V_49 = V_127 ;
V_1 -> V_33 . V_51 = V_128 ;
V_1 -> V_33 . V_44 = V_62 + 1 ;
V_1 -> V_33 . V_45 = V_65 + 1 ;
V_1 -> V_31 . V_55 = V_58 ;
V_1 -> V_31 . V_44 = V_62 + 1 ;
V_1 -> V_31 . V_45 = V_65 + 1 ;
V_1 -> V_31 . V_129 = V_130 ;
V_1 -> V_31 . V_131 = V_132 ;
F_62 ( & V_1 -> V_4 , V_6 , & V_155 ) ;
V_1 -> V_4 . V_156 = & V_157 ;
V_1 -> V_4 . V_158 |= V_159 ;
V_1 -> V_26 . V_158 = V_160 ;
V_13 = F_63 ( & V_1 -> V_4 . V_161 , 1 , & V_1 -> V_26 ) ;
V_154:
if ( V_13 < 0 ) {
F_64 ( & V_1 -> V_22 ) ;
F_65 ( & V_1 -> V_4 . V_161 ) ;
}
return V_13 ;
}
static int F_66 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_67 ( V_6 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_64 ( & V_1 -> V_22 ) ;
F_68 ( V_4 ) ;
F_65 ( & V_4 -> V_161 ) ;
return 0 ;
}
