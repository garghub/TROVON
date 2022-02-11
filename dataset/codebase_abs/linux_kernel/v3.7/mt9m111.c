static const struct V_1 * F_1 ( struct V_2 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ )
if ( V_6 [ V_5 ] . V_4 == V_4 )
return V_6 + V_5 ;
return V_2 -> V_7 ;
}
static struct V_2 * F_3 ( const struct V_8 * V_9 )
{
return F_4 ( F_5 ( V_9 ) , struct V_2 , V_10 ) ;
}
static int F_6 ( struct V_8 * V_9 , const T_1 V_11 )
{
int V_12 ;
T_1 V_13 ;
struct V_2 * V_2 = F_3 ( V_9 ) ;
V_13 = ( V_11 >> 8 ) ;
if ( V_13 == V_2 -> V_14 )
return 0 ;
if ( V_13 > 2 )
return - V_15 ;
V_12 = F_7 ( V_9 , V_16 , V_13 ) ;
if ( ! V_12 )
V_2 -> V_14 = V_13 ;
return V_12 ;
}
static int F_8 ( struct V_8 * V_9 , const T_1 V_11 )
{
int V_12 ;
V_12 = F_6 ( V_9 , V_11 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_9 , V_11 & 0xff ) ;
F_10 ( & V_9 -> V_17 , L_1 , V_11 , V_12 ) ;
return V_12 ;
}
static int F_11 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_1 V_18 )
{
int V_12 ;
V_12 = F_6 ( V_9 , V_11 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_9 , V_11 & 0xff , V_18 ) ;
F_10 ( & V_9 -> V_17 , L_2 , V_11 , V_18 , V_12 ) ;
return V_12 ;
}
static int F_12 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_1 V_18 )
{
int V_12 ;
V_12 = F_8 ( V_9 , V_11 ) ;
if ( V_12 >= 0 )
V_12 = F_11 ( V_9 , V_11 , V_12 | V_18 ) ;
return V_12 ;
}
static int F_13 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_1 V_18 )
{
int V_12 ;
V_12 = F_8 ( V_9 , V_11 ) ;
if ( V_12 >= 0 )
V_12 = F_11 ( V_9 , V_11 , V_12 & ~ V_18 ) ;
return V_12 ;
}
static int F_14 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_1 V_18 , const T_1 V_19 )
{
int V_12 ;
V_12 = F_8 ( V_9 , V_11 ) ;
if ( V_12 >= 0 )
V_12 = F_11 ( V_9 , V_11 , ( V_12 & ~ V_19 ) | V_18 ) ;
return V_12 ;
}
static int F_15 ( struct V_2 * V_2 ,
struct V_20 * V_21 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
return F_17 ( V_22 , V_21 -> V_23 ) ;
}
static int F_18 ( struct V_2 * V_2 ,
struct V_20 * V_21 , struct V_24 * V_25 ,
unsigned int V_26 , unsigned int V_27 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
int V_12 = F_11 ( V_9 , V_21 -> V_28 , V_25 -> V_26 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_9 , V_21 -> V_29 , V_25 -> V_27 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_9 , V_21 -> V_30 , V_26 ) ;
if ( ! V_12 )
V_12 = F_11 ( V_9 , V_21 -> V_31 , V_27 ) ;
return V_12 ;
}
static int F_19 ( struct V_2 * V_2 , struct V_24 * V_25 ,
int V_26 , int V_27 , enum V_3 V_4 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
int V_12 ;
V_12 = F_17 ( V_32 , V_25 -> V_33 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_34 , V_25 -> V_35 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_36 , V_25 -> V_26 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_37 , V_25 -> V_27 ) ;
if ( V_4 != V_38 ) {
if ( ! V_12 )
V_12 = F_18 ( V_2 , & V_39 ,
V_25 , V_26 , V_27 ) ;
if ( ! V_12 )
V_12 = F_18 ( V_2 , & V_40 ,
V_25 , V_26 , V_27 ) ;
}
F_10 ( & V_9 -> V_17 , L_3 ,
V_41 , V_4 , V_25 -> V_26 , V_25 -> V_27 , V_25 -> V_33 , V_25 -> V_35 ,
V_26 , V_27 , V_12 ) ;
return V_12 ;
}
static int F_20 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
return F_17 ( V_42 , V_43 ) ;
}
static int F_21 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
int V_12 ;
V_12 = F_22 ( V_42 , V_44 ) ;
if ( ! V_12 )
V_12 = F_22 ( V_42 , V_45 ) ;
if ( ! V_12 )
V_12 = F_23 ( V_42 , V_44
| V_45 ) ;
return V_12 ;
}
static int F_24 ( struct V_46 * V_47 , const struct V_48 * V_49 )
{
struct V_24 V_25 = V_49 -> V_50 ;
struct V_2 * V_2 = F_4 ( V_47 , struct V_2 , V_10 ) ;
int V_26 , V_27 ;
int V_12 ;
if ( V_49 -> type != V_51 )
return - V_15 ;
if ( V_2 -> V_7 -> V_4 == V_52 ||
V_2 -> V_7 -> V_4 == V_38 ) {
V_25 . V_26 = F_25 ( V_25 . V_26 , 2 ) ;
V_25 . V_27 = F_25 ( V_25 . V_27 , 2 ) ;
}
F_26 ( & V_25 . V_33 , & V_25 . V_26 ,
V_53 , 2 , V_54 ) ;
F_26 ( & V_25 . V_35 , & V_25 . V_27 ,
V_55 , 2 , V_56 ) ;
V_26 = F_27 ( V_2 -> V_26 , V_25 . V_26 ) ;
V_27 = F_27 ( V_2 -> V_27 , V_25 . V_27 ) ;
V_12 = F_19 ( V_2 , & V_25 , V_26 , V_27 , V_2 -> V_7 -> V_4 ) ;
if ( ! V_12 ) {
V_2 -> V_25 = V_25 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_27 = V_27 ;
}
return V_12 ;
}
static int F_28 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
struct V_2 * V_2 = F_4 ( V_47 , struct V_2 , V_10 ) ;
V_49 -> V_50 = V_2 -> V_25 ;
V_49 -> type = V_51 ;
return 0 ;
}
static int F_29 ( struct V_46 * V_47 , struct V_57 * V_49 )
{
if ( V_49 -> type != V_51 )
return - V_15 ;
V_49 -> V_58 . V_33 = V_53 ;
V_49 -> V_58 . V_35 = V_55 ;
V_49 -> V_58 . V_26 = V_54 ;
V_49 -> V_58 . V_27 = V_56 ;
V_49 -> V_59 = V_49 -> V_58 ;
V_49 -> V_60 . V_61 = 1 ;
V_49 -> V_60 . V_62 = 1 ;
return 0 ;
}
static int F_30 ( struct V_46 * V_47 ,
struct V_63 * V_64 )
{
struct V_2 * V_2 = F_4 ( V_47 , struct V_2 , V_10 ) ;
V_64 -> V_26 = V_2 -> V_26 ;
V_64 -> V_27 = V_2 -> V_27 ;
V_64 -> V_4 = V_2 -> V_7 -> V_4 ;
V_64 -> V_65 = V_2 -> V_7 -> V_65 ;
V_64 -> V_66 = V_67 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_2 ,
enum V_3 V_4 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
T_1 V_68 , V_69 = V_70 |
V_71 | V_72 |
V_73 | V_74 |
V_75 | V_76 |
V_77 |
V_78 ;
int V_12 ;
switch ( V_4 ) {
case V_52 :
V_68 = V_70 |
V_72 ;
break;
case V_38 :
V_68 = V_71 | V_72 ;
break;
case V_79 :
V_68 = V_72 | V_74 |
V_77 ;
break;
case V_80 :
V_68 = V_72 | V_74 ;
break;
case V_81 :
V_68 = V_72 | V_73 |
V_77 ;
break;
case V_82 :
V_68 = V_72 | V_73 ;
break;
case V_83 :
V_68 = V_72 | V_73 |
V_78 ;
break;
case V_84 :
V_68 = V_72 | V_73 |
V_77 |
V_78 ;
break;
case V_85 :
V_68 = 0 ;
break;
case V_86 :
V_68 = V_78 ;
break;
case V_87 :
V_68 = V_77 ;
break;
case V_88 :
V_68 = V_77 |
V_78 ;
break;
default:
F_32 ( & V_9 -> V_17 , L_4 , V_4 ) ;
return - V_15 ;
}
V_12 = F_14 ( V_9 , V_40 . V_89 ,
V_68 , V_69 ) ;
if ( ! V_12 )
V_12 = F_14 ( V_9 , V_39 . V_89 ,
V_68 , V_69 ) ;
return V_12 ;
}
static int F_33 ( struct V_46 * V_47 ,
struct V_63 * V_64 )
{
struct V_8 * V_9 = F_16 ( V_47 ) ;
struct V_2 * V_2 = F_4 ( V_47 , struct V_2 , V_10 ) ;
const struct V_1 * V_7 ;
struct V_24 * V_25 = & V_2 -> V_25 ;
bool V_90 ;
V_7 = F_1 ( V_2 , V_64 -> V_4 ) ;
V_90 = V_7 -> V_4 == V_52 ||
V_7 -> V_4 == V_38 ;
if ( V_90 ) {
V_25 -> V_26 = F_25 ( V_25 -> V_26 , 2 ) ;
V_25 -> V_27 = F_25 ( V_25 -> V_27 , 2 ) ;
}
if ( V_7 -> V_4 == V_38 ) {
V_64 -> V_26 = V_25 -> V_26 ;
V_64 -> V_27 = V_25 -> V_27 ;
} else {
if ( V_64 -> V_26 > V_25 -> V_26 )
V_64 -> V_26 = V_25 -> V_26 ;
if ( V_64 -> V_27 > V_25 -> V_27 )
V_64 -> V_27 = V_25 -> V_27 ;
}
F_10 ( & V_9 -> V_17 , L_5 , V_41 ,
V_64 -> V_26 , V_64 -> V_27 , V_7 -> V_4 ) ;
V_64 -> V_4 = V_7 -> V_4 ;
V_64 -> V_65 = V_7 -> V_65 ;
return 0 ;
}
static int F_34 ( struct V_46 * V_47 ,
struct V_63 * V_64 )
{
const struct V_1 * V_7 ;
struct V_2 * V_2 = F_4 ( V_47 , struct V_2 , V_10 ) ;
struct V_24 * V_25 = & V_2 -> V_25 ;
int V_12 ;
F_33 ( V_47 , V_64 ) ;
V_7 = F_1 ( V_2 , V_64 -> V_4 ) ;
V_12 = F_19 ( V_2 , V_25 , V_64 -> V_26 , V_64 -> V_27 , V_64 -> V_4 ) ;
if ( ! V_12 )
V_12 = F_31 ( V_2 , V_64 -> V_4 ) ;
if ( ! V_12 ) {
V_2 -> V_26 = V_64 -> V_26 ;
V_2 -> V_27 = V_64 -> V_27 ;
V_2 -> V_7 = V_7 ;
}
return V_12 ;
}
static int F_35 ( struct V_46 * V_47 ,
struct V_91 * V_92 )
{
struct V_8 * V_9 = F_16 ( V_47 ) ;
struct V_2 * V_2 = F_4 ( V_47 , struct V_2 , V_10 ) ;
if ( V_92 -> V_93 . type != V_94 )
return - V_15 ;
if ( V_92 -> V_93 . V_95 != V_9 -> V_95 )
return - V_96 ;
V_92 -> V_97 = V_2 -> V_98 ;
V_92 -> V_99 = 0 ;
return 0 ;
}
static int F_36 ( struct V_46 * V_47 ,
struct V_100 * V_11 )
{
struct V_8 * V_9 = F_16 ( V_47 ) ;
int V_101 ;
if ( V_11 -> V_93 . type != V_94 || V_11 -> V_11 > 0x2ff )
return - V_15 ;
if ( V_11 -> V_93 . V_95 != V_9 -> V_95 )
return - V_96 ;
V_101 = F_8 ( V_9 , V_11 -> V_11 ) ;
V_11 -> V_102 = 2 ;
V_11 -> V_101 = ( V_103 ) V_101 ;
if ( V_11 -> V_101 > 0xffff )
return - V_104 ;
return 0 ;
}
static int F_37 ( struct V_46 * V_47 ,
struct V_100 * V_11 )
{
struct V_8 * V_9 = F_16 ( V_47 ) ;
if ( V_11 -> V_93 . type != V_94 || V_11 -> V_11 > 0x2ff )
return - V_15 ;
if ( V_11 -> V_93 . V_95 != V_9 -> V_95 )
return - V_96 ;
if ( F_11 ( V_9 , V_11 -> V_11 , V_11 -> V_101 ) < 0 )
return - V_104 ;
return 0 ;
}
static int F_38 ( struct V_2 * V_2 , int V_105 , int V_19 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
int V_12 ;
if ( V_105 )
V_12 = F_12 ( V_9 , V_2 -> V_21 -> V_106 , V_19 ) ;
else
V_12 = F_13 ( V_9 , V_2 -> V_21 -> V_106 , V_19 ) ;
return V_12 ;
}
static int F_39 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
int V_18 ;
V_18 = F_40 ( V_107 ) ;
if ( V_18 >= 0 )
return ( V_18 & 0x2f ) * ( 1 << ( ( V_18 >> 10 ) & 1 ) ) *
( 1 << ( ( V_18 >> 9 ) & 1 ) ) ;
return V_18 ;
}
static int F_41 ( struct V_2 * V_2 , int V_108 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
T_1 V_101 ;
if ( V_108 > 63 * 2 * 2 )
return - V_15 ;
if ( ( V_108 >= 64 * 2 ) && ( V_108 < 63 * 2 * 2 ) )
V_101 = ( 1 << 10 ) | ( 1 << 9 ) | ( V_108 / 4 ) ;
else if ( ( V_108 >= 64 ) && ( V_108 < 64 * 2 ) )
V_101 = ( 1 << 9 ) | ( V_108 / 2 ) ;
else
V_101 = V_108 ;
return F_17 ( V_107 , V_101 ) ;
}
static int F_42 ( struct V_2 * V_2 , int V_109 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
if ( V_109 )
return F_22 ( V_110 , V_111 ) ;
return F_23 ( V_110 , V_111 ) ;
}
static int F_43 ( struct V_2 * V_2 , int V_109 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
if ( V_109 )
return F_22 ( V_110 , V_112 ) ;
return F_23 ( V_110 , V_112 ) ;
}
static int F_44 ( struct V_113 * V_114 )
{
struct V_2 * V_2 = F_4 ( V_114 -> V_115 ,
struct V_2 , V_116 ) ;
switch ( V_114 -> V_92 ) {
case V_117 :
return F_38 ( V_2 , V_114 -> V_101 ,
V_118 ) ;
case V_119 :
return F_38 ( V_2 , V_114 -> V_101 ,
V_120 ) ;
case V_121 :
return F_41 ( V_2 , V_114 -> V_101 ) ;
case V_122 :
return F_42 ( V_2 , V_114 -> V_101 ) ;
case V_123 :
return F_43 ( V_2 , V_114 -> V_101 ) ;
}
return - V_15 ;
}
static int F_45 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
int V_12 ;
F_46 ( V_2 -> V_108 , F_39 ( V_2 ) ) ;
V_12 = F_22 ( V_42 , V_44 ) ;
if ( ! V_12 )
V_12 = F_22 ( V_42 , V_45 |
V_124 |
V_125 ) ;
if ( ! V_12 )
V_12 = F_23 ( V_42 , V_43 ) ;
return V_12 ;
}
static void F_47 ( struct V_2 * V_2 )
{
F_15 ( V_2 , V_2 -> V_21 ) ;
F_31 ( V_2 , V_2 -> V_7 -> V_4 ) ;
F_19 ( V_2 , & V_2 -> V_25 ,
V_2 -> V_26 , V_2 -> V_27 , V_2 -> V_7 -> V_4 ) ;
F_48 ( & V_2 -> V_116 ) ;
}
static int F_49 ( struct V_2 * V_2 )
{
int V_12 = F_20 ( V_2 ) ;
if ( ! V_12 )
V_12 = F_21 ( V_2 ) ;
if ( ! V_12 )
F_47 ( V_2 ) ;
return V_12 ;
}
static int F_50 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
int V_12 ;
V_2 -> V_21 = & V_39 ;
V_12 = F_20 ( V_2 ) ;
if ( ! V_12 )
V_12 = F_21 ( V_2 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_2 , V_2 -> V_21 ) ;
if ( V_12 )
F_32 ( & V_9 -> V_17 , L_6 , V_12 ) ;
return V_12 ;
}
static int F_51 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
struct V_126 * V_127 = F_52 ( V_9 ) ;
int V_12 ;
V_12 = F_53 ( & V_9 -> V_17 , V_127 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_49 ( V_2 ) ;
if ( V_12 < 0 ) {
F_32 ( & V_9 -> V_17 , L_7 , V_12 ) ;
F_54 ( & V_9 -> V_17 , V_127 ) ;
}
return V_12 ;
}
static void F_55 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
struct V_126 * V_127 = F_52 ( V_9 ) ;
F_45 ( V_2 ) ;
F_54 ( & V_9 -> V_17 , V_127 ) ;
}
static int F_56 ( struct V_46 * V_47 , int V_109 )
{
struct V_2 * V_2 = F_4 ( V_47 , struct V_2 , V_10 ) ;
int V_12 = 0 ;
F_57 ( & V_2 -> V_128 ) ;
if ( V_2 -> V_129 == ! V_109 ) {
if ( V_109 )
V_12 = F_51 ( V_2 ) ;
else
F_55 ( V_2 ) ;
}
if ( ! V_12 ) {
V_2 -> V_129 += V_109 ? 1 : - 1 ;
F_58 ( V_2 -> V_129 < 0 ) ;
}
F_59 ( & V_2 -> V_128 ) ;
return V_12 ;
}
static int F_60 ( struct V_46 * V_47 , unsigned int V_130 ,
enum V_3 * V_4 )
{
if ( V_130 >= F_2 ( V_6 ) )
return - V_15 ;
* V_4 = V_6 [ V_130 ] . V_4 ;
return 0 ;
}
static int F_61 ( struct V_46 * V_47 ,
struct V_131 * V_132 )
{
struct V_8 * V_9 = F_16 ( V_47 ) ;
struct V_126 * V_127 = F_52 ( V_9 ) ;
V_132 -> V_133 = V_134 | V_135 |
V_136 | V_137 |
V_138 ;
V_132 -> type = V_139 ;
V_132 -> V_133 = F_62 ( V_127 , V_132 ) ;
return 0 ;
}
static int F_63 ( struct V_8 * V_9 )
{
struct V_2 * V_2 = F_3 ( V_9 ) ;
T_2 V_18 ;
int V_12 ;
V_12 = F_56 ( & V_2 -> V_10 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_18 = F_40 ( V_140 ) ;
switch ( V_18 ) {
case 0x143a :
V_2 -> V_98 = V_141 ;
F_64 ( & V_9 -> V_17 ,
L_8 , V_18 ) ;
break;
case 0x148c :
V_2 -> V_98 = V_142 ;
F_64 ( & V_9 -> V_17 , L_9 , V_18 ) ;
break;
default:
F_32 ( & V_9 -> V_17 ,
L_10 ,
V_18 ) ;
V_12 = - V_96 ;
goto V_143;
}
V_12 = F_50 ( V_2 ) ;
if ( V_12 )
goto V_143;
V_12 = F_48 ( & V_2 -> V_116 ) ;
V_143:
F_56 ( & V_2 -> V_10 , 0 ) ;
return V_12 ;
}
static int F_65 ( struct V_8 * V_9 ,
const struct V_144 * V_145 )
{
struct V_2 * V_2 ;
struct V_146 * V_147 = F_66 ( V_9 -> V_17 . V_148 ) ;
struct V_126 * V_127 = F_52 ( V_9 ) ;
int V_12 ;
if ( ! V_127 ) {
F_32 ( & V_9 -> V_17 , L_11 ) ;
return - V_15 ;
}
if ( ! F_67 ( V_147 , V_149 ) ) {
F_68 ( & V_147 -> V_17 ,
L_12 ) ;
return - V_104 ;
}
V_2 = F_69 ( sizeof( struct V_2 ) , V_150 ) ;
if ( ! V_2 )
return - V_151 ;
F_70 ( & V_2 -> V_10 , V_9 , & V_152 ) ;
F_71 ( & V_2 -> V_116 , 5 ) ;
F_72 ( & V_2 -> V_116 , & V_153 ,
V_117 , 0 , 1 , 1 , 0 ) ;
F_72 ( & V_2 -> V_116 , & V_153 ,
V_119 , 0 , 1 , 1 , 0 ) ;
F_72 ( & V_2 -> V_116 , & V_153 ,
V_123 , 0 , 1 , 1 , 1 ) ;
V_2 -> V_108 = F_72 ( & V_2 -> V_116 , & V_153 ,
V_121 , 0 , 63 * 2 * 2 , 1 , 32 ) ;
F_73 ( & V_2 -> V_116 ,
& V_153 , V_122 , 1 , 0 ,
V_154 ) ;
V_2 -> V_10 . V_155 = & V_2 -> V_116 ;
if ( V_2 -> V_116 . error ) {
int V_156 = V_2 -> V_116 . error ;
F_74 ( V_2 ) ;
return V_156 ;
}
V_2 -> V_25 . V_33 = V_53 ;
V_2 -> V_25 . V_35 = V_55 ;
V_2 -> V_25 . V_26 = V_54 ;
V_2 -> V_25 . V_27 = V_56 ;
V_2 -> V_7 = & V_6 [ 0 ] ;
V_2 -> V_14 = - 1 ;
F_75 ( & V_2 -> V_128 ) ;
V_12 = F_63 ( V_9 ) ;
if ( V_12 ) {
F_76 ( & V_2 -> V_116 ) ;
F_74 ( V_2 ) ;
}
return V_12 ;
}
static int F_77 ( struct V_8 * V_9 )
{
struct V_2 * V_2 = F_3 ( V_9 ) ;
F_78 ( & V_2 -> V_10 ) ;
F_76 ( & V_2 -> V_116 ) ;
F_74 ( V_2 ) ;
return 0 ;
}
