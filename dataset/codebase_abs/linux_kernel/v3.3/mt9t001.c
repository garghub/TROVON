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
max(__crop->width / 8, MT9T001_WINDOW_HEIGHT_MIN + 1),
__crop->width) ;
V_32 = F_19 (unsigned int, ALIGN(format->format.height, 2),
max(__crop->height / 8, MT9T001_WINDOW_HEIGHT_MIN + 1),
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
V_58 . V_31 = F_22 ( F_23 ( V_25 -> V_58 . V_31 , 2 ) ,
V_63 + 1 ,
V_64 + 1 ) ;
V_58 . V_32 = F_22 ( F_23 ( V_25 -> V_58 . V_32 , 2 ) ,
V_65 + 1 ,
V_66 + 1 ) ;
V_58 . V_31 = F_24 ( V_58 . V_31 , V_67 - V_58 . V_36 ) ;
V_58 . V_32 = F_24 ( V_58 . V_32 , V_68 - V_58 . V_38 ) ;
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
static T_2 F_25 ( T_3 * V_69 )
{
if ( * V_69 <= 32 )
return * V_69 ;
if ( * V_69 <= 64 ) {
* V_69 &= ~ 1 ;
return ( 1 << 6 ) | ( * V_69 >> 1 ) ;
}
* V_69 &= ~ 7 ;
return ( ( * V_69 - 64 ) << 5 ) | ( 1 << 6 ) | 32 ;
}
static int F_26 ( struct V_1 * V_1 , bool V_70 )
{
return F_7 ( V_1 ,
V_70 ? 0 : V_71 ,
V_70 ? V_71 : 0 ) ;
}
static int F_27 ( struct V_72 * V_73 )
{
static const T_1 V_74 [ 4 ] = {
V_75 , V_76 ,
V_77 , V_78
} ;
struct V_1 * V_1 =
F_2 ( V_73 -> V_79 , struct V_1 , V_80 ) ;
struct V_5 * V_6 = F_8 ( & V_1 -> V_4 ) ;
unsigned int V_81 ;
unsigned int V_82 ;
T_2 V_11 ;
int V_13 ;
switch ( V_73 -> V_83 ) {
case V_84 :
case V_85 :
case V_86 :
case V_87 :
for ( V_82 = 0 , V_81 = 0 ; V_82 < 4 ; ++ V_82 ) {
struct V_72 * V_69 = V_1 -> V_74 [ V_82 ] ;
if ( V_69 -> V_88 != V_69 -> V_89 . V_88 )
V_81 ++ ;
}
if ( V_81 > 1 ) {
V_13 = F_26 ( V_1 , true ) ;
if ( V_13 < 0 )
return V_13 ;
}
for ( V_82 = 0 ; V_82 < 4 ; ++ V_82 ) {
struct V_72 * V_69 = V_1 -> V_74 [ V_82 ] ;
if ( V_69 -> V_88 == V_69 -> V_89 . V_88 )
continue;
V_11 = F_25 ( & V_69 -> V_88 ) ;
V_13 = F_5 ( V_6 , V_74 [ V_82 ] , V_11 ) ;
if ( V_13 < 0 ) {
F_26 ( V_1 , false ) ;
return V_13 ;
}
}
if ( V_81 > 1 ) {
V_13 = F_26 ( V_1 , false ) ;
if ( V_13 < 0 )
return V_13 ;
}
break;
case V_90 :
V_13 = F_5 ( V_6 , V_91 ,
V_73 -> V_88 & 0xffff ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_92 ,
V_73 -> V_88 >> 16 ) ;
case V_93 :
V_13 = F_7 ( V_1 ,
V_73 -> V_88 ? 0 : V_94 ,
V_73 -> V_88 ? V_94 : 0 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_95 , V_73 -> V_88 << 2 ) ;
case V_96 :
V_11 = V_73 -> V_88 ? 0 : V_97 ;
V_13 = F_5 ( V_6 , V_98 ,
V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
V_1 -> V_99 = V_11 ;
break;
case V_100 :
V_13 = F_5 ( V_6 , V_101 , V_73 -> V_88 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_102 , V_73 -> V_88 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_103 , V_73 -> V_88 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_5 ( V_6 , V_104 , V_73 -> V_88 ) ;
case V_105 :
return F_5 ( V_6 , V_98 ,
V_106 |
V_1 -> V_99 ) ;
}
return 0 ;
}
static int F_28 ( struct V_2 * V_4 , struct V_16 * V_17 )
{
struct V_15 * V_23 ;
struct V_24 * V_25 ;
V_25 = F_12 ( V_17 , 0 ) ;
V_25 -> V_36 = V_107 ;
V_25 -> V_38 = V_108 ;
V_25 -> V_31 = V_49 + 1 ;
V_25 -> V_32 = V_52 + 1 ;
V_23 = F_10 ( V_17 , 0 ) ;
V_23 -> V_42 = V_45 ;
V_23 -> V_31 = V_49 + 1 ;
V_23 -> V_32 = V_52 + 1 ;
V_23 -> V_109 = V_110 ;
V_23 -> V_111 = V_112 ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_113 * V_114 = V_6 -> V_115 . V_116 ;
T_3 V_8 ;
int V_13 ;
F_30 ( & V_6 -> V_115 , L_1 ,
V_6 -> V_117 ) ;
V_13 = F_5 ( V_6 , V_118 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_118 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_6 , V_14 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_114 && V_114 -> V_119 ) {
V_13 = F_5 ( V_6 , V_120 ,
V_121 ) ;
if ( V_13 < 0 )
return V_13 ;
}
V_8 = F_3 ( V_6 , V_122 ) ;
if ( V_8 != V_123 ) {
F_31 ( & V_6 -> V_115 , L_2
L_3 , V_8 ) ;
return - V_124 ;
}
F_30 ( & V_6 -> V_115 , L_4 ,
V_6 -> V_117 ) ;
return V_13 ;
}
static int F_32 ( struct V_5 * V_6 ,
const struct V_125 * V_126 )
{
struct V_1 * V_1 ;
unsigned int V_82 ;
int V_13 ;
if ( ! F_33 ( V_6 -> V_127 ,
V_128 ) ) {
F_34 ( & V_6 -> V_127 -> V_115 ,
L_5 ) ;
return - V_129 ;
}
V_13 = F_29 ( V_6 ) ;
if ( V_13 < 0 )
return V_13 ;
V_1 = F_35 ( sizeof( * V_1 ) , V_130 ) ;
if ( ! V_1 )
return - V_131 ;
F_36 ( & V_1 -> V_80 , F_37 ( V_132 ) +
F_37 ( V_133 ) + 2 ) ;
F_38 ( & V_1 -> V_80 , & V_134 ,
V_90 , V_135 ,
V_136 , 1 ,
V_137 ) ;
F_38 ( & V_1 -> V_80 , & V_134 ,
V_138 , 1 , 1 , 1 , 1 ) ;
for ( V_82 = 0 ; V_82 < F_37 ( V_132 ) ; ++ V_82 )
F_39 ( & V_1 -> V_80 , & V_132 [ V_82 ] , NULL ) ;
for ( V_82 = 0 ; V_82 < F_37 ( V_133 ) ; ++ V_82 )
V_1 -> V_74 [ V_82 ] = F_39 ( & V_1 -> V_80 ,
& V_133 [ V_82 ] , NULL ) ;
F_40 ( F_37 ( V_133 ) , V_1 -> V_74 ) ;
V_1 -> V_4 . V_139 = & V_1 -> V_80 ;
if ( V_1 -> V_80 . error ) {
F_41 ( V_140 L_6 ,
V_141 , V_1 -> V_80 . error ) ;
V_13 = - V_44 ;
goto V_142;
}
V_1 -> V_25 . V_36 = V_107 ;
V_1 -> V_25 . V_38 = V_108 ;
V_1 -> V_25 . V_31 = V_49 + 1 ;
V_1 -> V_25 . V_32 = V_52 + 1 ;
V_1 -> V_23 . V_42 = V_45 ;
V_1 -> V_23 . V_31 = V_49 + 1 ;
V_1 -> V_23 . V_32 = V_52 + 1 ;
V_1 -> V_23 . V_109 = V_110 ;
V_1 -> V_23 . V_111 = V_112 ;
F_42 ( & V_1 -> V_4 , V_6 , & V_143 ) ;
V_1 -> V_4 . V_144 = & V_145 ;
V_1 -> V_4 . V_146 |= V_147 ;
V_1 -> V_18 . V_146 = V_148 ;
V_13 = F_43 ( & V_1 -> V_4 . V_149 , 1 , & V_1 -> V_18 , 0 ) ;
V_142:
if ( V_13 < 0 ) {
F_44 ( & V_1 -> V_80 ) ;
F_45 ( & V_1 -> V_4 . V_149 ) ;
F_46 ( V_1 ) ;
}
return V_13 ;
}
static int F_47 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_48 ( V_6 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_44 ( & V_1 -> V_80 ) ;
F_49 ( V_4 ) ;
F_45 ( & V_4 -> V_149 ) ;
F_46 ( V_1 ) ;
return 0 ;
}
static int T_4 F_50 ( void )
{
return F_51 ( & V_150 ) ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_150 ) ;
}
