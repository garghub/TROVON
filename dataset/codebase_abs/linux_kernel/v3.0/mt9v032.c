static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , const T_1 V_7 )
{
T_2 V_8 = F_4 ( V_6 , V_7 ) ;
F_5 ( & V_6 -> V_9 , L_1 , V_10 ,
F_6 ( V_8 ) , V_7 ) ;
return V_8 < 0 ? V_8 : F_6 ( V_8 ) ;
}
static int F_7 ( struct V_5 * V_6 , const T_1 V_7 ,
const T_3 V_8 )
{
F_5 ( & V_6 -> V_9 , L_2 , V_10 ,
V_8 , V_7 ) ;
return F_8 ( V_6 , V_7 , F_6 ( V_8 ) ) ;
}
static int F_9 ( struct V_1 * V_1 , T_3 V_11 , T_3 V_12 )
{
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
T_3 V_13 = ( V_1 -> V_14 & ~ V_11 ) | V_12 ;
int V_15 ;
V_15 = F_7 ( V_6 , V_16 , V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
V_1 -> V_14 = V_13 ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_1 , T_3 V_17 , int V_18 )
{
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
T_3 V_13 = V_1 -> V_19 ;
int V_15 ;
if ( V_18 )
V_13 |= V_17 ;
else
V_13 &= ~ V_17 ;
V_15 = F_7 ( V_6 , V_20 , V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
V_1 -> V_19 = V_13 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
int V_15 ;
if ( V_1 -> V_21 -> V_22 ) {
V_1 -> V_21 -> V_22 ( & V_1 -> V_4 , 25000000 ) ;
F_13 ( 1 ) ;
}
V_15 = F_7 ( V_6 , V_23 , 1 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_6 , V_23 , 0 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_7 ( V_6 , V_16 , 0 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
if ( V_1 -> V_21 -> V_22 )
V_1 -> V_21 -> V_22 ( & V_1 -> V_4 , 0 ) ;
}
static int F_15 ( struct V_1 * V_1 , bool V_24 )
{
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
int V_15 ;
if ( ! V_24 ) {
F_14 ( V_1 ) ;
return 0 ;
}
V_15 = F_12 ( V_1 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_1 -> V_21 && V_1 -> V_21 -> V_25 ) {
V_15 = F_7 ( V_6 , V_26 ,
V_27 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_15 = F_7 ( V_6 , V_28 , 0 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_16 ( & V_1 -> V_29 ) ;
}
static struct V_30 *
F_17 ( struct V_1 * V_1 , struct V_31 * V_32 ,
unsigned int V_33 , enum V_34 V_17 )
{
switch ( V_17 ) {
case V_35 :
return F_18 ( V_32 , V_33 ) ;
case V_36 :
return & V_1 -> V_37 ;
default:
return NULL ;
}
}
static struct V_38 *
F_19 ( struct V_1 * V_1 , struct V_31 * V_32 ,
unsigned int V_33 , enum V_34 V_17 )
{
switch ( V_17 ) {
case V_35 :
return F_20 ( V_32 , V_33 ) ;
case V_36 :
return & V_1 -> V_39 ;
default:
return NULL ;
}
}
static int F_21 ( struct V_2 * V_4 , int V_18 )
{
const T_3 V_40 = V_41
| V_42
| V_43 ;
struct V_5 * V_6 = F_10 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_30 * V_37 = & V_1 -> V_37 ;
struct V_38 * V_39 = & V_1 -> V_39 ;
unsigned int V_44 ;
unsigned int V_45 ;
int V_15 ;
if ( ! V_18 )
return F_9 ( V_1 , V_40 , 0 ) ;
V_44 = F_22 ( V_39 -> V_46 , V_37 -> V_46 ) ;
V_45 = F_22 ( V_39 -> V_47 , V_37 -> V_47 ) ;
V_15 = F_7 ( V_6 , V_48 ,
( V_44 - 1 ) << V_49 |
( V_45 - 1 ) << V_50 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_6 , V_51 , V_39 -> V_52 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_6 , V_53 , V_39 -> V_54 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_6 , V_55 , V_39 -> V_46 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_6 , V_56 , V_39 -> V_47 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_6 , V_57 ,
F_23 ( 43 , 660 - V_39 -> V_46 ) ) ;
if ( V_15 < 0 )
return V_15 ;
return F_9 ( V_1 , 0 , V_40 ) ;
}
static int F_24 ( struct V_2 * V_4 ,
struct V_31 * V_32 ,
struct V_58 * V_59 )
{
if ( V_59 -> V_60 > 0 )
return - V_61 ;
V_59 -> V_59 = V_62 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_4 ,
struct V_31 * V_32 ,
struct V_63 * V_64 )
{
if ( V_64 -> V_60 >= 8 || V_64 -> V_59 != V_62 )
return - V_61 ;
V_64 -> V_65 = V_66 / V_64 -> V_60 ;
V_64 -> V_67 = V_64 -> V_65 ;
V_64 -> V_68 = V_69 / V_64 -> V_60 ;
V_64 -> V_70 = V_64 -> V_68 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_4 ,
struct V_31 * V_32 ,
struct V_71 * V_37 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_37 -> V_37 = * F_17 ( V_1 , V_32 , V_37 -> V_33 ,
V_37 -> V_17 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_4 ,
struct V_31 * V_32 ,
struct V_71 * V_37 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_30 * V_72 ;
struct V_38 * V_73 ;
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_44 ;
unsigned int V_45 ;
V_73 = F_19 ( V_1 , V_32 , V_37 -> V_33 ,
V_37 -> V_17 ) ;
V_46 = F_28 (unsigned int, ALIGN(format->format.width, 2),
max(__crop->width / 8, MT9V032_WINDOW_WIDTH_MIN),
__crop->width) ;
V_47 = F_28 (unsigned int, ALIGN(format->format.height, 2),
max(__crop->height / 8, MT9V032_WINDOW_HEIGHT_MIN),
__crop->height) ;
V_44 = F_22 ( V_73 -> V_46 , V_46 ) ;
V_45 = F_22 ( V_73 -> V_47 , V_47 ) ;
V_72 = F_17 ( V_1 , V_32 , V_37 -> V_33 ,
V_37 -> V_17 ) ;
V_72 -> V_46 = V_73 -> V_46 / V_44 ;
V_72 -> V_47 = V_73 -> V_47 / V_45 ;
V_37 -> V_37 = * V_72 ;
return 0 ;
}
static int F_29 ( struct V_2 * V_4 ,
struct V_31 * V_32 ,
struct V_74 * V_39 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
V_39 -> V_75 = * F_19 ( V_1 , V_32 , V_39 -> V_33 ,
V_39 -> V_17 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_4 ,
struct V_31 * V_32 ,
struct V_74 * V_39 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_30 * V_72 ;
struct V_38 * V_73 ;
struct V_38 V_75 ;
V_75 . V_52 = F_31 ( F_32 ( V_39 -> V_75 . V_52 , 2 ) ,
V_76 ,
V_77 ) ;
V_75 . V_54 = F_31 ( F_32 ( V_39 -> V_75 . V_54 , 2 ) ,
V_78 ,
V_79 ) ;
V_75 . V_46 = F_31 ( F_32 ( V_39 -> V_75 . V_46 , 2 ) ,
V_80 ,
V_81 ) ;
V_75 . V_47 = F_31 ( F_32 ( V_39 -> V_75 . V_47 , 2 ) ,
V_82 ,
V_83 ) ;
V_75 . V_46 = F_33 ( V_75 . V_46 , V_84 - V_75 . V_52 ) ;
V_75 . V_47 = F_33 ( V_75 . V_47 , V_85 - V_75 . V_54 ) ;
V_73 = F_19 ( V_1 , V_32 , V_39 -> V_33 , V_39 -> V_17 ) ;
if ( V_75 . V_46 != V_73 -> V_46 || V_75 . V_47 != V_73 -> V_47 ) {
V_72 = F_17 ( V_1 , V_32 , V_39 -> V_33 ,
V_39 -> V_17 ) ;
V_72 -> V_46 = V_75 . V_46 ;
V_72 -> V_47 = V_75 . V_47 ;
}
* V_73 = V_75 ;
V_39 -> V_75 = V_75 ;
return 0 ;
}
static int F_34 ( struct V_86 * V_87 )
{
struct V_1 * V_1 =
F_2 ( V_87 -> V_88 , struct V_1 , V_29 ) ;
struct V_5 * V_6 = F_10 ( & V_1 -> V_4 ) ;
T_3 V_8 ;
switch ( V_87 -> V_89 ) {
case V_90 :
return F_11 ( V_1 , V_91 ,
V_87 -> V_92 ) ;
case V_93 :
return F_7 ( V_6 , V_94 , V_87 -> V_92 ) ;
case V_95 :
return F_11 ( V_1 , V_96 ,
V_87 -> V_92 ) ;
case V_97 :
return F_7 ( V_6 , V_98 ,
V_87 -> V_92 ) ;
case V_99 :
switch ( V_87 -> V_92 ) {
case 0 :
V_8 = 0 ;
break;
case 1 :
V_8 = V_100
| V_101 ;
break;
case 2 :
V_8 = V_102
| V_101 ;
break;
case 3 :
V_8 = V_103
| V_101 ;
break;
default:
V_8 = ( V_87 -> V_92 << V_104 )
| V_105
| V_101
| V_106 ;
break;
}
return F_7 ( V_6 , V_107 , V_8 ) ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_4 , int V_24 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_15 = 0 ;
F_36 ( & V_1 -> V_108 ) ;
if ( V_1 -> V_109 == ! V_24 ) {
V_15 = F_15 ( V_1 , ! ! V_24 ) ;
if ( V_15 < 0 )
goto V_110;
}
V_1 -> V_109 += V_24 ? 1 : - 1 ;
F_37 ( V_1 -> V_109 < 0 ) ;
V_110:
F_38 ( & V_1 -> V_108 ) ;
return V_15 ;
}
static int F_39 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_10 ( V_4 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
T_2 V_8 ;
int V_15 ;
F_40 ( & V_6 -> V_9 , L_3 ,
V_6 -> V_111 ) ;
V_15 = F_12 ( V_1 ) ;
if ( V_15 < 0 ) {
F_41 ( & V_6 -> V_9 , L_4 ) ;
return V_15 ;
}
V_8 = F_3 ( V_6 , V_112 ) ;
if ( V_8 != V_113 && V_8 != V_114 ) {
F_41 ( & V_6 -> V_9 , L_5
L_6 , V_8 ) ;
return - V_115 ;
}
F_14 ( V_1 ) ;
F_40 ( & V_6 -> V_9 , L_7 ,
V_6 -> V_111 ) ;
return V_15 ;
}
static int F_42 ( struct V_2 * V_4 , struct V_31 * V_32 )
{
struct V_30 * V_37 ;
struct V_38 * V_39 ;
V_39 = F_20 ( V_32 , 0 ) ;
V_39 -> V_52 = V_116 ;
V_39 -> V_54 = V_117 ;
V_39 -> V_46 = V_66 ;
V_39 -> V_47 = V_69 ;
V_37 = F_18 ( V_32 , 0 ) ;
V_37 -> V_59 = V_62 ;
V_37 -> V_46 = V_66 ;
V_37 -> V_47 = V_69 ;
V_37 -> V_118 = V_119 ;
V_37 -> V_120 = V_121 ;
return F_35 ( V_4 , 1 ) ;
}
static int F_43 ( struct V_2 * V_4 , struct V_31 * V_32 )
{
return F_35 ( V_4 , 0 ) ;
}
static int F_44 ( struct V_5 * V_6 ,
const struct V_122 * V_123 )
{
struct V_1 * V_1 ;
unsigned int V_124 ;
int V_15 ;
if ( ! F_45 ( V_6 -> V_125 ,
V_126 ) ) {
F_46 ( & V_6 -> V_125 -> V_9 ,
L_8 ) ;
return - V_127 ;
}
V_1 = F_47 ( sizeof( * V_1 ) , V_128 ) ;
if ( ! V_1 )
return - V_129 ;
F_48 ( & V_1 -> V_108 ) ;
V_1 -> V_21 = V_6 -> V_9 . V_130 ;
F_49 ( & V_1 -> V_29 , F_50 ( V_131 ) + 4 ) ;
F_51 ( & V_1 -> V_29 , & V_132 ,
V_90 , 0 , 1 , 1 , 1 ) ;
F_51 ( & V_1 -> V_29 , & V_132 ,
V_93 , V_133 ,
V_134 , 1 , V_135 ) ;
F_52 ( & V_1 -> V_29 , & V_132 ,
V_95 , V_136 , 0 ,
V_137 ) ;
F_51 ( & V_1 -> V_29 , & V_132 ,
V_97 , V_138 ,
V_139 , 1 ,
V_140 ) ;
for ( V_124 = 0 ; V_124 < F_50 ( V_131 ) ; ++ V_124 )
F_53 ( & V_1 -> V_29 , & V_131 [ V_124 ] , NULL ) ;
V_1 -> V_4 . V_141 = & V_1 -> V_29 ;
if ( V_1 -> V_29 . error )
F_54 ( V_142 L_9 ,
V_10 , V_1 -> V_29 . error ) ;
V_1 -> V_39 . V_52 = V_116 ;
V_1 -> V_39 . V_54 = V_117 ;
V_1 -> V_39 . V_46 = V_66 ;
V_1 -> V_39 . V_47 = V_69 ;
V_1 -> V_37 . V_59 = V_62 ;
V_1 -> V_37 . V_46 = V_66 ;
V_1 -> V_37 . V_47 = V_69 ;
V_1 -> V_37 . V_118 = V_119 ;
V_1 -> V_37 . V_120 = V_121 ;
V_1 -> V_19 = V_96 | V_91 ;
F_55 ( & V_1 -> V_4 , V_6 , & V_143 ) ;
V_1 -> V_4 . V_144 = & V_145 ;
V_1 -> V_4 . V_146 |= V_147 ;
V_1 -> V_33 . V_146 = V_148 ;
V_15 = F_56 ( & V_1 -> V_4 . V_149 , 1 , & V_1 -> V_33 , 0 ) ;
if ( V_15 < 0 )
F_57 ( V_1 ) ;
return V_15 ;
}
static int F_58 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_59 ( V_6 ) ;
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_60 ( V_4 ) ;
F_61 ( & V_4 -> V_149 ) ;
F_57 ( V_1 ) ;
return 0 ;
}
static int T_4 F_62 ( void )
{
return F_63 ( & V_150 ) ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_150 ) ;
}
