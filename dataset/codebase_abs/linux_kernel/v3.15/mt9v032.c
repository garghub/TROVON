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
unsigned int V_23 = V_1 -> V_24 -> V_8 -> V_23 ;
unsigned int V_25 ;
if ( V_1 -> V_26 -> V_26 == V_27 )
V_23 += ( V_1 -> V_28 - 1 ) * 10 ;
V_23 = F_12 (unsigned int, (int)mt9v032->model->data->min_row_time - crop->width,
(int)min_hblank) ;
V_25 = F_12 (unsigned int, mt9v032->hblank, min_hblank) ;
return F_6 ( V_6 , V_29 , V_25 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_9 ( & V_1 -> V_4 ) ;
int V_15 ;
V_15 = F_14 ( V_1 -> V_30 , V_1 -> V_31 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_15 ( V_1 -> V_30 ) ;
if ( V_15 )
return V_15 ;
F_16 ( 1 ) ;
V_15 = F_6 ( V_6 , V_32 , 1 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_6 ( V_6 , V_32 , 0 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_6 ( V_6 , V_16 , 0 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
F_18 ( V_1 -> V_30 ) ;
}
static int F_19 ( struct V_1 * V_1 , bool V_33 )
{
struct V_5 * V_6 = F_9 ( & V_1 -> V_4 ) ;
int V_15 ;
if ( ! V_33 ) {
F_17 ( V_1 ) ;
return 0 ;
}
V_15 = F_13 ( V_1 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_1 -> V_34 && V_1 -> V_34 -> V_35 ) {
V_15 = F_6 ( V_6 , V_1 -> V_24 -> V_8 -> V_36 ,
V_37 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_15 = F_6 ( V_6 , V_38 , 0 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_20 ( & V_1 -> V_39 ) ;
}
static struct V_40 *
F_21 ( struct V_1 * V_1 , struct V_41 * V_42 ,
unsigned int V_43 , enum V_44 V_17 )
{
switch ( V_17 ) {
case V_45 :
return F_22 ( V_42 , V_43 ) ;
case V_46 :
return & V_1 -> V_47 ;
default:
return NULL ;
}
}
static struct V_21 *
F_23 ( struct V_1 * V_1 , struct V_41 * V_42 ,
unsigned int V_43 , enum V_44 V_17 )
{
switch ( V_17 ) {
case V_45 :
return F_24 ( V_42 , V_43 ) ;
case V_46 :
return & V_1 -> V_22 ;
default:
return NULL ;
}
}
static int F_25 ( struct V_2 * V_4 , int V_18 )
{
const T_3 V_48 = V_49
| V_50
| V_51 ;
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_21 * V_22 = & V_1 -> V_22 ;
unsigned int V_52 ;
unsigned int V_53 ;
int V_15 ;
if ( ! V_18 )
return F_8 ( V_1 , V_48 , 0 ) ;
V_52 = F_26 ( V_1 -> V_28 ) - 1 ;
V_53 = F_26 ( V_1 -> V_54 ) - 1 ;
V_15 = F_6 ( V_6 , V_55 ,
V_52 << V_56 |
V_53 << V_57 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_6 ( V_6 , V_58 , V_22 -> V_59 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_6 ( V_6 , V_60 , V_22 -> V_61 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_6 ( V_6 , V_62 , V_22 -> V_63 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_6 ( V_6 , V_64 , V_22 -> V_65 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_11 ( V_1 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_8 ( V_1 , 0 , V_48 ) ;
}
static int F_27 ( struct V_2 * V_4 ,
struct V_41 * V_42 ,
struct V_66 * V_67 )
{
if ( V_67 -> V_68 > 0 )
return - V_69 ;
V_67 -> V_67 = V_70 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_4 ,
struct V_41 * V_42 ,
struct V_71 * V_72 )
{
if ( V_72 -> V_68 >= 3 || V_72 -> V_67 != V_70 )
return - V_69 ;
V_72 -> V_73 = V_74 / ( 1 << V_72 -> V_68 ) ;
V_72 -> V_75 = V_72 -> V_73 ;
V_72 -> V_76 = V_77 / ( 1 << V_72 -> V_68 ) ;
V_72 -> V_78 = V_72 -> V_76 ;
return 0 ;
}
static int F_29 ( struct V_2 * V_4 ,
struct V_41 * V_42 ,
struct V_79 * V_47 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_47 -> V_47 = * F_21 ( V_1 , V_42 , V_47 -> V_43 ,
V_47 -> V_17 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_9 ( & V_1 -> V_4 ) ;
int V_15 ;
V_15 = F_31 ( V_1 -> V_80 ,
V_1 -> V_31 / V_1 -> V_28 ) ;
if ( V_15 < 0 )
F_32 ( & V_6 -> V_9 , L_3 , V_15 ) ;
}
static unsigned int F_33 ( unsigned int V_81 , unsigned int V_82 )
{
if ( V_82 * 3 > V_81 * 2 )
return 1 ;
if ( V_82 * 3 > V_81 )
return 2 ;
return 4 ;
}
static int F_34 ( struct V_2 * V_4 ,
struct V_41 * V_42 ,
struct V_79 * V_47 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_40 * V_83 ;
struct V_21 * V_84 ;
unsigned int V_63 ;
unsigned int V_65 ;
unsigned int V_28 ;
unsigned int V_54 ;
V_84 = F_23 ( V_1 , V_42 , V_47 -> V_43 ,
V_47 -> V_17 ) ;
V_63 = F_35 ( F_36 ( V_47 -> V_47 . V_63 , 2 ) ,
F_12 (unsigned int, __crop->width / 4 ,
MT9V032_WINDOW_WIDTH_MIN) ,
V_84 -> V_63 ) ;
V_65 = F_35 ( F_36 ( V_47 -> V_47 . V_65 , 2 ) ,
F_12 (unsigned int, __crop->height / 4 ,
MT9V032_WINDOW_HEIGHT_MIN) ,
V_84 -> V_65 ) ;
V_28 = F_33 ( V_84 -> V_63 , V_63 ) ;
V_54 = F_33 ( V_84 -> V_65 , V_65 ) ;
V_83 = F_21 ( V_1 , V_42 , V_47 -> V_43 ,
V_47 -> V_17 ) ;
V_83 -> V_63 = V_84 -> V_63 / V_28 ;
V_83 -> V_65 = V_84 -> V_65 / V_54 ;
if ( V_47 -> V_17 == V_46 ) {
V_1 -> V_28 = V_28 ;
V_1 -> V_54 = V_54 ;
F_30 ( V_1 ) ;
}
V_47 -> V_47 = * V_83 ;
return 0 ;
}
static int F_37 ( struct V_2 * V_4 ,
struct V_41 * V_42 ,
struct V_85 * V_22 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_22 -> V_86 = * F_23 ( V_1 , V_42 , V_22 -> V_43 ,
V_22 -> V_17 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_4 ,
struct V_41 * V_42 ,
struct V_85 * V_22 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_40 * V_83 ;
struct V_21 * V_84 ;
struct V_21 V_86 ;
V_86 . V_59 = F_35 ( F_36 ( V_22 -> V_86 . V_59 + 1 , 2 ) - 1 ,
V_87 ,
V_88 ) ;
V_86 . V_61 = F_35 ( F_36 ( V_22 -> V_86 . V_61 + 1 , 2 ) - 1 ,
V_89 ,
V_90 ) ;
V_86 . V_63 = F_39 (unsigned int, ALIGN(crop->rect.width, 2),
MT9V032_WINDOW_WIDTH_MIN,
MT9V032_WINDOW_WIDTH_MAX) ;
V_86 . V_65 = F_39 (unsigned int, ALIGN(crop->rect.height, 2),
MT9V032_WINDOW_HEIGHT_MIN,
MT9V032_WINDOW_HEIGHT_MAX) ;
V_86 . V_63 = F_40 (unsigned int,
rect.width, MT9V032_PIXEL_ARRAY_WIDTH - rect.left) ;
V_86 . V_65 = F_40 (unsigned int,
rect.height, MT9V032_PIXEL_ARRAY_HEIGHT - rect.top) ;
V_84 = F_23 ( V_1 , V_42 , V_22 -> V_43 , V_22 -> V_17 ) ;
if ( V_86 . V_63 != V_84 -> V_63 || V_86 . V_65 != V_84 -> V_65 ) {
V_83 = F_21 ( V_1 , V_42 , V_22 -> V_43 ,
V_22 -> V_17 ) ;
V_83 -> V_63 = V_86 . V_63 ;
V_83 -> V_65 = V_86 . V_65 ;
if ( V_22 -> V_17 == V_46 ) {
V_1 -> V_28 = 1 ;
V_1 -> V_54 = 1 ;
F_30 ( V_1 ) ;
}
}
* V_84 = V_86 ;
V_22 -> V_86 = V_86 ;
return 0 ;
}
static int F_41 ( struct V_91 * V_92 )
{
struct V_1 * V_1 =
F_2 ( V_92 -> V_93 , struct V_1 , V_39 ) ;
struct V_5 * V_6 = F_9 ( & V_1 -> V_4 ) ;
T_4 V_94 ;
T_3 V_8 ;
switch ( V_92 -> V_95 ) {
case V_96 :
return F_10 ( V_1 , V_97 ,
V_92 -> V_98 ) ;
case V_99 :
return F_6 ( V_6 , V_100 , V_92 -> V_98 ) ;
case V_101 :
return F_10 ( V_1 , V_102 ,
! V_92 -> V_98 ) ;
case V_103 :
return F_6 ( V_6 , V_104 ,
V_92 -> V_98 ) ;
case V_105 :
V_1 -> V_25 = V_92 -> V_98 ;
return F_11 ( V_1 ) ;
case V_106 :
return F_6 ( V_6 , V_107 ,
V_92 -> V_98 ) ;
case V_108 :
case V_109 :
if ( V_1 -> V_110 == NULL )
break;
V_94 = V_1 -> V_34 -> V_111 [ V_1 -> V_110 -> V_98 ] ;
V_1 -> V_80 -> V_112 = V_94 ;
V_1 -> V_31 = V_94 ;
break;
case V_113 :
switch ( V_1 -> V_114 -> V_98 ) {
case 0 :
V_8 = 0 ;
break;
case 1 :
V_8 = V_115
| V_116 ;
break;
case 2 :
V_8 = V_117
| V_116 ;
break;
case 3 :
V_8 = V_118
| V_116 ;
break;
default:
V_8 = ( V_1 -> V_119 -> V_98 <<
V_120 )
| V_121
| V_116
| V_122 ;
break;
}
return F_6 ( V_6 , V_123 , V_8 ) ;
}
return 0 ;
}
static int F_42 ( struct V_2 * V_4 , int V_33 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_15 = 0 ;
F_43 ( & V_1 -> V_124 ) ;
if ( V_1 -> V_125 == ! V_33 ) {
V_15 = F_19 ( V_1 , ! ! V_33 ) ;
if ( V_15 < 0 )
goto V_126;
}
V_1 -> V_125 += V_33 ? 1 : - 1 ;
F_44 ( V_1 -> V_125 < 0 ) ;
V_126:
F_45 ( & V_1 -> V_124 ) ;
return V_15 ;
}
static int F_46 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_9 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
unsigned int V_127 ;
T_2 V_26 ;
int V_15 ;
F_47 ( & V_6 -> V_9 , L_4 ,
V_6 -> V_128 ) ;
V_15 = F_13 ( V_1 ) ;
if ( V_15 < 0 ) {
F_48 ( & V_6 -> V_9 , L_5 ) ;
return V_15 ;
}
V_26 = F_3 ( V_6 , V_129 ) ;
if ( V_26 < 0 ) {
F_48 ( & V_6 -> V_9 , L_6 ) ;
return V_26 ;
}
for ( V_127 = 0 ; V_127 < F_49 ( V_130 ) ; ++ V_127 ) {
if ( V_130 [ V_127 ] . V_26 == V_26 ) {
V_1 -> V_26 = & V_130 [ V_127 ] ;
break;
}
}
if ( V_1 -> V_26 == NULL ) {
F_48 ( & V_6 -> V_9 , L_7 ,
V_26 ) ;
return - V_131 ;
}
F_17 ( V_1 ) ;
F_47 ( & V_6 -> V_9 , L_8 ,
V_1 -> V_26 -> V_132 , V_6 -> V_128 ) ;
F_30 ( V_1 ) ;
return V_15 ;
}
static int F_50 ( struct V_2 * V_4 , struct V_41 * V_42 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_40 * V_47 ;
struct V_21 * V_22 ;
V_22 = F_24 ( V_42 , 0 ) ;
V_22 -> V_59 = V_133 ;
V_22 -> V_61 = V_134 ;
V_22 -> V_63 = V_74 ;
V_22 -> V_65 = V_77 ;
V_47 = F_22 ( V_42 , 0 ) ;
if ( V_1 -> V_24 -> V_135 )
V_47 -> V_67 = V_70 ;
else
V_47 -> V_67 = V_136 ;
V_47 -> V_63 = V_74 ;
V_47 -> V_65 = V_77 ;
V_47 -> V_137 = V_138 ;
V_47 -> V_139 = V_140 ;
return F_42 ( V_4 , 1 ) ;
}
static int F_51 ( struct V_2 * V_4 , struct V_41 * V_42 )
{
return F_42 ( V_4 , 0 ) ;
}
static int F_52 ( struct V_5 * V_6 ,
const struct V_141 * V_142 )
{
struct V_143 * V_34 = V_6 -> V_9 . V_144 ;
struct V_1 * V_1 ;
unsigned int V_127 ;
int V_15 ;
if ( ! F_53 ( V_6 -> V_145 ,
V_146 ) ) {
F_32 ( & V_6 -> V_145 -> V_9 ,
L_9 ) ;
return - V_147 ;
}
V_1 = F_54 ( & V_6 -> V_9 , sizeof( * V_1 ) , V_148 ) ;
if ( ! V_1 )
return - V_149 ;
V_1 -> V_30 = F_55 ( & V_6 -> V_9 , NULL ) ;
if ( F_56 ( V_1 -> V_30 ) )
return F_57 ( V_1 -> V_30 ) ;
F_58 ( & V_1 -> V_124 ) ;
V_1 -> V_34 = V_34 ;
V_1 -> V_24 = ( const void * ) V_142 -> V_150 ;
F_59 ( & V_1 -> V_39 , 10 ) ;
F_60 ( & V_1 -> V_39 , & V_151 ,
V_96 , 0 , 1 , 1 , 1 ) ;
F_60 ( & V_1 -> V_39 , & V_151 ,
V_99 , V_152 ,
V_153 , 1 , V_154 ) ;
F_61 ( & V_1 -> V_39 , & V_151 ,
V_101 , V_155 , 0 ,
V_156 ) ;
F_60 ( & V_1 -> V_39 , & V_151 ,
V_103 , V_1 -> V_24 -> V_8 -> V_157 ,
V_1 -> V_24 -> V_8 -> V_158 , 1 ,
V_159 ) ;
F_60 ( & V_1 -> V_39 , & V_151 ,
V_105 , V_1 -> V_24 -> V_8 -> V_23 ,
V_160 , 1 ,
V_161 ) ;
F_60 ( & V_1 -> V_39 , & V_151 ,
V_106 , V_1 -> V_24 -> V_8 -> V_162 ,
V_1 -> V_24 -> V_8 -> V_163 , 1 ,
V_164 ) ;
V_1 -> V_114 = F_62 ( & V_1 -> V_39 ,
& V_151 , V_113 ,
F_49 ( V_165 ) - 1 , 0 , 0 ,
V_165 ) ;
V_1 -> V_119 = F_63 ( & V_1 -> V_39 ,
& V_166 , NULL ) ;
F_64 ( 2 , & V_1 -> V_114 ) ;
V_1 -> V_80 =
F_60 ( & V_1 -> V_39 , & V_151 ,
V_108 , 0 , 0 , 1 , 0 ) ;
if ( V_34 && V_34 -> V_111 ) {
unsigned int V_167 = 0 ;
for ( V_127 = 0 ; V_34 -> V_111 [ V_127 ] ; ++ V_127 ) {
if ( V_34 -> V_111 [ V_127 ] == V_34 -> V_168 )
V_167 = V_127 ;
}
V_1 -> V_110 =
F_65 ( & V_1 -> V_39 ,
& V_151 ,
V_109 , V_127 - 1 , V_167 ,
V_34 -> V_111 ) ;
F_64 ( 2 , & V_1 -> V_110 ) ;
}
V_1 -> V_4 . V_169 = & V_1 -> V_39 ;
if ( V_1 -> V_39 . error )
F_66 ( V_170 L_10 ,
V_10 , V_1 -> V_39 . error ) ;
V_1 -> V_22 . V_59 = V_133 ;
V_1 -> V_22 . V_61 = V_134 ;
V_1 -> V_22 . V_63 = V_74 ;
V_1 -> V_22 . V_65 = V_77 ;
if ( V_1 -> V_24 -> V_135 )
V_1 -> V_47 . V_67 = V_70 ;
else
V_1 -> V_47 . V_67 = V_136 ;
V_1 -> V_47 . V_63 = V_74 ;
V_1 -> V_47 . V_65 = V_77 ;
V_1 -> V_47 . V_137 = V_138 ;
V_1 -> V_47 . V_139 = V_140 ;
V_1 -> V_28 = 1 ;
V_1 -> V_54 = 1 ;
V_1 -> V_19 = V_102 | V_97 ;
V_1 -> V_25 = V_161 ;
V_1 -> V_31 = V_171 ;
F_67 ( & V_1 -> V_4 , V_6 , & V_172 ) ;
V_1 -> V_4 . V_173 = & V_174 ;
V_1 -> V_4 . V_175 |= V_176 ;
V_1 -> V_43 . V_175 = V_177 ;
V_15 = F_68 ( & V_1 -> V_4 . V_178 , 1 , & V_1 -> V_43 , 0 ) ;
if ( V_15 < 0 )
F_69 ( & V_1 -> V_39 ) ;
return V_15 ;
}
static int F_70 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_71 ( V_6 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_69 ( & V_1 -> V_39 ) ;
F_72 ( V_4 ) ;
F_73 ( & V_4 -> V_178 ) ;
return 0 ;
}
