static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 ,
V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 ,
const struct V_5 * V_6 )
{
while ( V_6 -> V_7 != 0xff ) {
int V_8 = F_5 ( V_3 ,
V_6 -> V_7 ,
V_6 -> V_9 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 ++ ;
}
return 0 ;
}
static int F_6 ( struct V_2 * V_3 ,
T_1 V_10 ,
T_1 V_11 ,
T_1 V_12 )
{
T_2 V_13 = F_7 ( V_3 , V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 &= ~ V_11 ;
V_13 |= V_12 & V_11 ;
return F_5 ( V_3 , V_10 , V_13 ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
int V_8 = F_5 ( V_3 , V_14 , V_15 ) ;
F_9 ( 1 ) ;
return V_8 ;
}
static int F_10 ( struct V_16 * V_17 , int V_18 )
{
struct V_2 * V_3 = F_11 ( V_17 ) ;
struct V_1 * V_19 = F_2 ( V_17 , struct V_1 , V_4 ) ;
if ( ! V_18 ) {
F_6 ( V_3 , V_20 , V_21 , V_21 ) ;
return 0 ;
}
if ( ! V_19 -> V_22 || ! V_19 -> V_23 ) {
F_12 ( & V_3 -> V_24 , L_1 ) ;
return - V_25 ;
}
F_6 ( V_3 , V_20 , V_21 , 0 ) ;
F_13 ( & V_3 -> V_24 , L_2 ,
V_19 -> V_23 -> V_26 , V_19 -> V_22 -> V_27 ) ;
return 0 ;
}
static int F_14 ( struct V_28 * V_29 )
{
struct V_1 * V_19 = F_2 ( V_29 -> V_30 ,
struct V_1 , V_31 ) ;
struct V_16 * V_17 = & V_19 -> V_4 ;
struct V_2 * V_3 = F_11 ( V_17 ) ;
int V_8 = 0 ;
T_1 V_13 ;
switch ( V_29 -> V_32 ) {
case V_33 :
V_13 = V_29 -> V_13 ? V_34 : 0x00 ;
V_19 -> V_35 = V_29 -> V_13 ;
if ( V_19 -> V_36 -> V_37 & V_38 )
V_13 ^= V_34 ;
return F_6 ( V_3 , V_39 , V_34 , V_13 ) ;
case V_40 :
V_13 = V_29 -> V_13 ? V_41 : 0x00 ;
V_19 -> V_42 = V_29 -> V_13 ;
if ( V_19 -> V_36 -> V_37 & V_43 )
V_13 ^= V_41 ;
return F_6 ( V_3 , V_39 , V_41 , V_13 ) ;
case V_44 :
if ( ! V_29 -> V_13 ) {
V_8 = F_6 ( V_3 , V_45 , 0xff , 0xff ) ;
if ( ! V_8 )
V_8 = F_6 ( V_3 , V_46 ,
V_47 , 0 ) ;
} else {
V_13 = 256 - V_29 -> V_13 ;
V_8 = F_6 ( V_3 , V_46 ,
V_47 , V_47 ) ;
if ( ! V_8 )
V_8 = F_6 ( V_3 , V_45 ,
0xff , V_13 ) ;
}
if ( ! V_8 )
V_19 -> V_48 = V_29 -> V_13 ;
return V_8 ;
}
return - V_49 ;
}
static int F_15 ( struct V_16 * V_17 ,
struct V_50 * V_32 )
{
struct V_1 * V_19 = F_2 ( V_17 , struct V_1 , V_4 ) ;
V_32 -> V_51 = V_19 -> V_52 ;
V_32 -> V_53 = 0 ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 ,
struct V_54 * V_55 )
{
struct V_2 * V_3 = F_11 ( V_17 ) ;
int V_8 ;
V_55 -> V_56 = 1 ;
if ( V_55 -> V_55 > 0xff )
return - V_49 ;
V_8 = F_7 ( V_3 , V_55 -> V_55 ) ;
if ( V_8 < 0 )
return V_8 ;
V_55 -> V_13 = ( V_57 ) V_8 ;
return 0 ;
}
static int F_17 ( struct V_16 * V_17 ,
struct V_54 * V_55 )
{
struct V_2 * V_3 = F_11 ( V_17 ) ;
if ( V_55 -> V_55 > 0xff ||
V_55 -> V_13 > 0xff )
return - V_49 ;
return F_5 ( V_3 , V_55 -> V_55 , V_55 -> V_13 ) ;
}
static const struct V_58 * F_18 ( T_3 V_59 , T_3 V_60 )
{
T_4 V_61 ;
const struct V_58 * V_22 ;
V_61 = abs ( V_59 - V_62 . V_59 ) +
abs ( V_60 - V_62 . V_60 ) ;
V_22 = & V_62 ;
if ( V_61 >
abs ( V_59 - V_63 . V_59 ) +
abs ( V_60 - V_63 . V_60 ) )
V_22 = & V_63 ;
return V_22 ;
}
static int F_19 ( struct V_2 * V_3 , T_3 * V_59 , T_3 * V_60 ,
enum V_64 V_26 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
int V_8 = - V_49 ;
T_1 V_13 ;
int V_65 ;
V_19 -> V_23 = NULL ;
for ( V_65 = 0 ; V_65 < F_20 ( V_66 ) ; V_65 ++ ) {
if ( V_26 == V_66 [ V_65 ] . V_26 ) {
V_19 -> V_23 = V_66 + V_65 ;
break;
}
}
if ( ! V_19 -> V_23 )
goto V_67;
V_19 -> V_22 = F_18 ( * V_59 , * V_60 ) ;
F_8 ( V_3 ) ;
if ( V_19 -> V_36 -> V_68 . V_69 & V_70 ) {
V_8 = F_6 ( V_3 , V_71 , V_72 , 0x00 ) ;
if ( V_8 < 0 )
goto V_67;
V_8 = F_6 ( V_3 ,
V_73 , V_74 ,
V_19 -> V_36 -> V_68 . V_75 ) ;
if ( V_8 < 0 )
goto V_67;
V_8 = F_6 ( V_3 ,
V_76 , V_77 ,
V_19 -> V_36 -> V_68 . V_69 ) ;
if ( V_8 < 0 )
goto V_67;
} else if ( V_19 -> V_36 -> V_68 . V_78 > V_19 -> V_36 -> V_68 . V_79 ) {
V_8 = F_6 ( V_3 ,
V_80 , V_81 ,
V_19 -> V_36 -> V_68 . V_78 ) ;
if ( V_8 < 0 )
goto V_67;
V_8 = F_6 ( V_3 ,
V_82 , V_83 ,
V_19 -> V_36 -> V_68 . V_79 ) ;
if ( V_8 < 0 )
goto V_67;
}
V_8 = F_4 ( V_3 , V_19 -> V_22 -> V_84 ) ;
if ( V_8 < 0 )
goto V_67;
V_13 = V_19 -> V_23 -> V_85 ;
if ( V_13 ) {
V_8 = F_6 ( V_3 ,
V_86 , V_87 , V_13 ) ;
if ( V_8 < 0 )
goto V_67;
}
V_13 = V_19 -> V_23 -> V_88 ;
if ( V_19 -> V_36 -> V_37 & V_38 )
V_13 |= V_34 ;
if ( V_19 -> V_36 -> V_37 & V_43 )
V_13 |= V_41 ;
if ( V_19 -> V_35 )
V_13 ^= V_34 ;
if ( V_19 -> V_42 )
V_13 ^= V_41 ;
V_8 = F_6 ( V_3 ,
V_39 , V_89 | V_90 , V_13 ) ;
if ( V_8 < 0 )
goto V_67;
V_13 = V_19 -> V_22 -> V_91 | V_19 -> V_23 -> V_92 ;
V_8 = F_6 ( V_3 ,
V_14 , V_93 | V_94 | V_95 ,
V_13 ) ;
if ( V_8 < 0 )
goto V_67;
if ( V_19 -> V_48 ) {
V_8 = F_6 ( V_3 , V_46 , V_47 , 1 ) ;
if ( ! V_8 )
V_8 = F_6 ( V_3 , V_45 ,
0xff , 256 - V_19 -> V_48 ) ;
if ( V_8 < 0 )
goto V_67;
}
* V_59 = V_19 -> V_22 -> V_59 ;
* V_60 = V_19 -> V_22 -> V_60 ;
return V_8 ;
V_67:
F_8 ( V_3 ) ;
V_19 -> V_22 = NULL ;
V_19 -> V_23 = NULL ;
return V_8 ;
}
static int F_21 ( struct V_16 * V_17 , struct V_96 * V_97 )
{
V_97 -> V_98 . V_99 = 0 ;
V_97 -> V_98 . V_100 = 0 ;
V_97 -> V_98 . V_59 = V_101 ;
V_97 -> V_98 . V_60 = V_102 ;
V_97 -> type = V_103 ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 , struct V_104 * V_97 )
{
V_97 -> V_105 . V_99 = 0 ;
V_97 -> V_105 . V_100 = 0 ;
V_97 -> V_105 . V_59 = V_101 ;
V_97 -> V_105 . V_60 = V_102 ;
V_97 -> V_106 = V_97 -> V_105 ;
V_97 -> type = V_103 ;
V_97 -> V_107 . V_108 = 1 ;
V_97 -> V_107 . V_109 = 1 ;
return 0 ;
}
static int F_23 ( struct V_16 * V_17 ,
struct V_110 * V_111 )
{
struct V_1 * V_19 = F_2 ( V_17 , struct V_1 , V_4 ) ;
if ( ! V_19 -> V_22 || ! V_19 -> V_23 ) {
V_19 -> V_23 = & V_66 [ 0 ] ;
V_19 -> V_22 = F_18 ( V_101 , V_102 ) ;
}
V_111 -> V_59 = V_19 -> V_22 -> V_59 ;
V_111 -> V_60 = V_19 -> V_22 -> V_60 ;
V_111 -> V_26 = V_19 -> V_23 -> V_26 ;
V_111 -> V_112 = V_19 -> V_23 -> V_112 ;
V_111 -> V_113 = V_114 ;
return 0 ;
}
static int F_24 ( struct V_16 * V_17 ,
struct V_110 * V_111 )
{
struct V_2 * V_3 = F_11 ( V_17 ) ;
struct V_1 * V_19 = F_2 ( V_17 , struct V_1 , V_4 ) ;
int V_8 = F_19 ( V_3 , & V_111 -> V_59 , & V_111 -> V_60 ,
V_111 -> V_26 ) ;
if ( ! V_8 )
V_111 -> V_112 = V_19 -> V_23 -> V_112 ;
return V_8 ;
}
static int F_25 ( struct V_16 * V_17 ,
struct V_110 * V_111 )
{
struct V_1 * V_19 = F_2 ( V_17 , struct V_1 , V_4 ) ;
const struct V_58 * V_22 ;
int V_65 ;
V_22 = F_18 ( V_111 -> V_59 , V_111 -> V_60 ) ;
V_111 -> V_59 = V_22 -> V_59 ;
V_111 -> V_60 = V_22 -> V_60 ;
V_111 -> V_113 = V_114 ;
for ( V_65 = 0 ; V_65 < F_20 ( V_66 ) ; V_65 ++ )
if ( V_111 -> V_26 == V_66 [ V_65 ] . V_26 )
break;
if ( V_65 == F_20 ( V_66 ) ) {
if ( V_19 -> V_23 ) {
V_111 -> V_112 = V_19 -> V_23 -> V_112 ;
V_111 -> V_26 = V_19 -> V_23 -> V_26 ;
} else {
V_111 -> V_112 = V_66 [ 0 ] . V_112 ;
V_111 -> V_26 = V_66 [ 0 ] . V_26 ;
}
} else {
V_111 -> V_112 = V_66 [ V_65 ] . V_112 ;
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_115 , V_116 ;
const char * V_117 ;
V_115 = F_7 ( V_3 , V_118 ) ;
V_116 = F_7 ( V_3 , V_119 ) ;
switch ( F_27 ( V_115 , V_116 ) ) {
case V_120 :
V_117 = L_3 ;
V_19 -> V_52 = V_121 ;
break;
case V_122 :
V_117 = L_4 ;
V_19 -> V_52 = V_123 ;
break;
default:
F_12 ( & V_3 -> V_24 ,
L_5 , V_115 , V_116 ) ;
return - V_124 ;
}
F_28 ( & V_3 -> V_24 ,
L_6 ,
V_117 ,
V_115 ,
V_116 ,
F_7 ( V_3 , V_125 ) ,
F_7 ( V_3 , V_126 ) ) ;
return F_29 ( & V_19 -> V_31 ) ;
}
static int F_30 ( struct V_16 * V_17 , unsigned int V_127 ,
enum V_64 * V_26 )
{
if ( V_127 >= F_20 ( V_66 ) )
return - V_49 ;
* V_26 = V_66 [ V_127 ] . V_26 ;
return 0 ;
}
static int F_31 ( struct V_16 * V_17 ,
struct V_128 * V_129 )
{
struct V_2 * V_3 = F_11 ( V_17 ) ;
struct V_130 * V_131 = F_32 ( V_3 ) ;
V_129 -> V_37 = V_132 | V_133 |
V_134 | V_135 |
V_136 ;
V_129 -> type = V_137 ;
V_129 -> V_37 = F_33 ( V_131 , V_129 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 ,
const struct V_138 * V_139 )
{
struct V_1 * V_19 ;
struct V_130 * V_131 = F_32 ( V_3 ) ;
struct V_140 * V_141 = F_35 ( V_3 -> V_24 . V_142 ) ;
int V_8 ;
if ( ! V_131 || ! V_131 -> V_19 ) {
F_12 ( & V_3 -> V_24 , L_7 ) ;
return - V_49 ;
}
if ( ! F_36 ( V_141 , V_143 ) ) {
F_12 ( & V_141 -> V_24 ,
L_8
L_9 ) ;
return - V_144 ;
}
V_19 = F_37 ( sizeof( * V_19 ) , V_145 ) ;
if ( ! V_19 )
return - V_146 ;
V_19 -> V_36 = V_131 -> V_19 ;
F_38 ( & V_19 -> V_4 , V_3 , & V_147 ) ;
F_39 ( & V_19 -> V_31 , 3 ) ;
F_40 ( & V_19 -> V_31 , & V_148 ,
V_33 , 0 , 1 , 1 , 0 ) ;
F_40 ( & V_19 -> V_31 , & V_148 ,
V_40 , 0 , 1 , 1 , 0 ) ;
F_40 ( & V_19 -> V_31 , & V_148 ,
V_44 , 0 , 256 , 1 , 0 ) ;
V_19 -> V_4 . V_149 = & V_19 -> V_31 ;
if ( V_19 -> V_31 . error ) {
int V_150 = V_19 -> V_31 . error ;
F_41 ( V_19 ) ;
return V_150 ;
}
V_8 = F_26 ( V_3 ) ;
if ( V_8 ) {
F_42 ( & V_19 -> V_31 ) ;
F_41 ( V_19 ) ;
}
return V_8 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
F_44 ( & V_19 -> V_4 ) ;
F_42 ( & V_19 -> V_31 ) ;
F_41 ( V_19 ) ;
return 0 ;
}
