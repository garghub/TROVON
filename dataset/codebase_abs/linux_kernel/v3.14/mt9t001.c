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
static struct V_15 *
F_9 ( struct V_1 * V_1 , struct V_16 * V_17 ,
unsigned int V_18 , enum V_19 V_20 )
{
switch ( V_20 ) {
case V_21 :
return F_10 ( V_17 , V_18 ) ;
case V_22 :
return & V_1 -> V_23 ;
default:
return NULL ;
}
}
static struct V_24 *
F_11 ( struct V_1 * V_1 , struct V_16 * V_17 ,
unsigned int V_18 , enum V_19 V_20 )
{
switch ( V_20 ) {
case V_21 :
return F_12 ( V_17 , V_18 ) ;
case V_22 :
return & V_1 -> V_25 ;
default:
return NULL ;
}
}
static int F_13 ( struct V_2 * V_4 , int V_26 )
{
const T_2 V_27 = V_28 ;
struct V_5 * V_6 = F_8 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_15 * V_23 = & V_1 -> V_23 ;
struct V_24 * V_25 = & V_1 -> V_25 ;
unsigned int V_29 ;
unsigned int V_30 ;
int V_13 ;
if ( ! V_26 )
return F_7 ( V_1 , V_27 , 0 ) ;
V_29 = F_14 ( V_25 -> V_31 , V_23 -> V_31 ) ;
V_30 = F_14 ( V_25 -> V_32 , V_23 -> V_32 ) ;
V_13 = F_5 ( V_6 , V_33 , V_29 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_34 , V_30 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_35 , V_25 -> V_36 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_37 , V_25 -> V_38 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_39 , V_25 -> V_31 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_40 , V_25 -> V_32 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_7 ( V_1 , 0 , V_27 ) ;
}
static int F_15 ( struct V_2 * V_4 ,
struct V_16 * V_17 ,
struct V_41 * V_42 )
{
if ( V_42 -> V_43 > 0 )
return - V_44 ;
V_42 -> V_42 = V_45 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_4 ,
struct V_16 * V_17 ,
struct V_46 * V_47 )
{
if ( V_47 -> V_43 >= 8 || V_47 -> V_42 != V_45 )
return - V_44 ;
V_47 -> V_48 = ( V_49 + 1 ) / V_47 -> V_43 ;
V_47 -> V_50 = V_47 -> V_48 ;
V_47 -> V_51 = ( V_52 + 1 ) / V_47 -> V_43 ;
V_47 -> V_53 = V_47 -> V_51 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_4 ,
struct V_16 * V_17 ,
struct V_54 * V_23 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_23 -> V_23 = * F_9 ( V_1 , V_17 , V_23 -> V_18 ,
V_23 -> V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_4 ,
struct V_16 * V_17 ,
struct V_54 * V_23 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_15 * V_55 ;
struct V_24 * V_56 ;
unsigned int V_31 ;
unsigned int V_32 ;
unsigned int V_29 ;
unsigned int V_30 ;
V_56 = F_11 ( V_1 , V_17 , V_23 -> V_18 ,
V_23 -> V_20 ) ;
V_31 = F_19 (unsigned int, ALIGN(format->format.width, 2),
max_t(unsigned int, __crop->width / 8,
MT9T001_WINDOW_HEIGHT_MIN + 1),
__crop->width) ;
V_32 = F_19 (unsigned int, ALIGN(format->format.height, 2),
max_t(unsigned int, __crop->height / 8,
MT9T001_WINDOW_HEIGHT_MIN + 1),
__crop->height) ;
V_29 = F_14 ( V_56 -> V_31 , V_31 ) ;
V_30 = F_14 ( V_56 -> V_32 , V_32 ) ;
V_55 = F_9 ( V_1 , V_17 , V_23 -> V_18 ,
V_23 -> V_20 ) ;
V_55 -> V_31 = V_56 -> V_31 / V_29 ;
V_55 -> V_32 = V_56 -> V_32 / V_30 ;
V_23 -> V_23 = * V_55 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_4 ,
struct V_16 * V_17 ,
struct V_57 * V_25 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_25 -> V_58 = * F_11 ( V_1 , V_17 , V_25 -> V_18 ,
V_25 -> V_20 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_4 ,
struct V_16 * V_17 ,
struct V_57 * V_25 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_15 * V_55 ;
struct V_24 * V_56 ;
struct V_24 V_58 ;
V_58 . V_36 = F_22 ( F_23 ( V_25 -> V_58 . V_36 , 2 ) ,
V_59 ,
V_60 ) ;
V_58 . V_38 = F_22 ( F_23 ( V_25 -> V_58 . V_38 , 2 ) ,
V_61 ,
V_62 ) ;
V_58 . V_31 = F_19 (unsigned int, ALIGN(crop->rect.width, 2),
MT9T001_WINDOW_WIDTH_MIN + 1 ,
MT9T001_WINDOW_WIDTH_MAX + 1 ) ;
V_58 . V_32 = F_19 (unsigned int, ALIGN(crop->rect.height, 2),
MT9T001_WINDOW_HEIGHT_MIN + 1 ,
MT9T001_WINDOW_HEIGHT_MAX + 1 ) ;
V_58 . V_31 = F_24 (unsigned int, rect.width,
MT9T001_PIXEL_ARRAY_WIDTH - rect.left) ;
V_58 . V_32 = F_24 (unsigned int, rect.height,
MT9T001_PIXEL_ARRAY_HEIGHT - rect.top) ;
V_56 = F_11 ( V_1 , V_17 , V_25 -> V_18 , V_25 -> V_20 ) ;
if ( V_58 . V_31 != V_56 -> V_31 || V_58 . V_32 != V_56 -> V_32 ) {
V_55 = F_9 ( V_1 , V_17 , V_25 -> V_18 ,
V_25 -> V_20 ) ;
V_55 -> V_31 = V_58 . V_31 ;
V_55 -> V_32 = V_58 . V_32 ;
}
* V_56 = V_58 ;
V_25 -> V_58 = V_58 ;
return 0 ;
}
static T_2 F_25 ( T_3 * V_63 )
{
if ( * V_63 <= 32 )
return * V_63 ;
if ( * V_63 <= 64 ) {
* V_63 &= ~ 1 ;
return ( 1 << 6 ) | ( * V_63 >> 1 ) ;
}
* V_63 &= ~ 7 ;
return ( ( * V_63 - 64 ) << 5 ) | ( 1 << 6 ) | 32 ;
}
static int F_26 ( struct V_1 * V_1 , bool V_64 )
{
return F_7 ( V_1 ,
V_64 ? 0 : V_65 ,
V_64 ? V_65 : 0 ) ;
}
static int F_27 ( struct V_66 * V_67 )
{
static const T_1 V_68 [ 4 ] = {
V_69 , V_70 ,
V_71 , V_72
} ;
struct V_1 * V_1 =
F_2 ( V_67 -> V_73 , struct V_1 , V_74 ) ;
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
unsigned int V_75 ;
unsigned int V_76 ;
T_2 V_11 ;
int V_13 ;
switch ( V_67 -> V_77 ) {
case V_78 :
case V_79 :
case V_80 :
case V_81 :
for ( V_76 = 0 , V_75 = 0 ; V_76 < 4 ; ++ V_76 ) {
struct V_66 * V_63 = V_1 -> V_68 [ V_76 ] ;
if ( V_63 -> V_82 != V_63 -> V_83 . V_82 )
V_75 ++ ;
}
if ( V_75 > 1 ) {
V_13 = F_26 ( V_1 , true ) ;
if ( V_13 < 0 )
return V_13 ;
}
for ( V_76 = 0 ; V_76 < 4 ; ++ V_76 ) {
struct V_66 * V_63 = V_1 -> V_68 [ V_76 ] ;
if ( V_63 -> V_82 == V_63 -> V_83 . V_82 )
continue;
V_11 = F_25 ( & V_63 -> V_82 ) ;
V_13 = F_5 ( V_6 , V_68 [ V_76 ] , V_11 ) ;
if ( V_13 < 0 ) {
F_26 ( V_1 , false ) ;
return V_13 ;
}
}
if ( V_75 > 1 ) {
V_13 = F_26 ( V_1 , false ) ;
if ( V_13 < 0 )
return V_13 ;
}
break;
case V_84 :
V_13 = F_5 ( V_6 , V_85 ,
V_67 -> V_82 & 0xffff ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_86 ,
V_67 -> V_82 >> 16 ) ;
case V_87 :
return F_7 ( V_1 ,
V_67 -> V_82 ? 0 : V_88 ,
V_67 -> V_82 ? V_88 : 0 ) ;
case V_89 :
return F_5 ( V_6 , V_90 , V_67 -> V_82 << 2 ) ;
case V_91 :
V_11 = V_67 -> V_82 ? 0 : V_92 ;
V_13 = F_5 ( V_6 , V_93 ,
V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
V_1 -> V_94 = V_11 ;
break;
case V_95 :
V_13 = F_5 ( V_6 , V_96 , V_67 -> V_82 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_97 , V_67 -> V_82 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_98 , V_67 -> V_82 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_99 , V_67 -> V_82 ) ;
case V_100 :
return F_5 ( V_6 , V_93 ,
V_101 |
V_1 -> V_94 ) ;
}
return 0 ;
}
static int F_28 ( struct V_2 * V_4 , struct V_16 * V_17 )
{
struct V_15 * V_23 ;
struct V_24 * V_25 ;
V_25 = F_12 ( V_17 , 0 ) ;
V_25 -> V_36 = V_102 ;
V_25 -> V_38 = V_103 ;
V_25 -> V_31 = V_49 + 1 ;
V_25 -> V_32 = V_52 + 1 ;
V_23 = F_10 ( V_17 , 0 ) ;
V_23 -> V_42 = V_45 ;
V_23 -> V_31 = V_49 + 1 ;
V_23 -> V_32 = V_52 + 1 ;
V_23 -> V_104 = V_105 ;
V_23 -> V_106 = V_107 ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_108 * V_109 = V_6 -> V_110 . V_111 ;
T_3 V_8 ;
int V_13 ;
F_30 ( & V_6 -> V_110 , L_1 ,
V_6 -> V_112 ) ;
V_13 = F_5 ( V_6 , V_113 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_113 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_14 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_109 -> V_114 ) {
V_13 = F_5 ( V_6 , V_115 ,
V_116 ) ;
if ( V_13 < 0 )
return V_13 ;
}
V_8 = F_3 ( V_6 , V_117 ) ;
if ( V_8 != V_118 ) {
F_31 ( & V_6 -> V_110 , L_2
L_3 , V_8 ) ;
return - V_119 ;
}
F_30 ( & V_6 -> V_110 , L_4 ,
V_6 -> V_112 ) ;
return V_13 ;
}
static int F_32 ( struct V_5 * V_6 ,
const struct V_120 * V_121 )
{
struct V_108 * V_109 = V_6 -> V_110 . V_111 ;
struct V_1 * V_1 ;
unsigned int V_76 ;
int V_13 ;
if ( V_109 == NULL ) {
F_31 ( & V_6 -> V_110 , L_5 ) ;
return - V_44 ;
}
if ( ! F_33 ( V_6 -> V_122 ,
V_123 ) ) {
F_34 ( & V_6 -> V_122 -> V_110 ,
L_6 ) ;
return - V_124 ;
}
V_13 = F_29 ( V_6 ) ;
if ( V_13 < 0 )
return V_13 ;
V_1 = F_35 ( & V_6 -> V_110 , sizeof( * V_1 ) , V_125 ) ;
if ( ! V_1 )
return - V_126 ;
F_36 ( & V_1 -> V_74 , F_37 ( V_127 ) +
F_37 ( V_128 ) + 4 ) ;
F_38 ( & V_1 -> V_74 , & V_129 ,
V_84 , V_130 ,
V_131 , 1 ,
V_132 ) ;
F_38 ( & V_1 -> V_74 , & V_129 ,
V_133 , 1 , 1 , 1 , 1 ) ;
F_38 ( & V_1 -> V_74 , & V_129 ,
V_134 , V_109 -> V_135 , V_109 -> V_135 ,
1 , V_109 -> V_135 ) ;
F_39 ( & V_1 -> V_74 , & V_129 ,
V_87 ,
F_37 ( V_136 ) - 1 , 0 ,
0 , V_136 ) ;
for ( V_76 = 0 ; V_76 < F_37 ( V_127 ) ; ++ V_76 )
F_40 ( & V_1 -> V_74 , & V_127 [ V_76 ] , NULL ) ;
for ( V_76 = 0 ; V_76 < F_37 ( V_128 ) ; ++ V_76 )
V_1 -> V_68 [ V_76 ] = F_40 ( & V_1 -> V_74 ,
& V_128 [ V_76 ] , NULL ) ;
F_41 ( F_37 ( V_128 ) , V_1 -> V_68 ) ;
V_1 -> V_4 . V_137 = & V_1 -> V_74 ;
if ( V_1 -> V_74 . error ) {
F_42 ( V_138 L_7 ,
V_139 , V_1 -> V_74 . error ) ;
V_13 = - V_44 ;
goto V_140;
}
V_1 -> V_25 . V_36 = V_102 ;
V_1 -> V_25 . V_38 = V_103 ;
V_1 -> V_25 . V_31 = V_49 + 1 ;
V_1 -> V_25 . V_32 = V_52 + 1 ;
V_1 -> V_23 . V_42 = V_45 ;
V_1 -> V_23 . V_31 = V_49 + 1 ;
V_1 -> V_23 . V_32 = V_52 + 1 ;
V_1 -> V_23 . V_104 = V_105 ;
V_1 -> V_23 . V_106 = V_107 ;
F_43 ( & V_1 -> V_4 , V_6 , & V_141 ) ;
V_1 -> V_4 . V_142 = & V_143 ;
V_1 -> V_4 . V_144 |= V_145 ;
V_1 -> V_18 . V_144 = V_146 ;
V_13 = F_44 ( & V_1 -> V_4 . V_147 , 1 , & V_1 -> V_18 , 0 ) ;
V_140:
if ( V_13 < 0 ) {
F_45 ( & V_1 -> V_74 ) ;
F_46 ( & V_1 -> V_4 . V_147 ) ;
}
return V_13 ;
}
static int F_47 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_48 ( V_6 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_45 ( & V_1 -> V_74 ) ;
F_49 ( V_4 ) ;
F_46 ( & V_4 -> V_147 ) ;
return 0 ;
}
