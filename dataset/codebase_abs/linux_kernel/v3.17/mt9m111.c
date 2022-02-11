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
struct V_91 * V_11 )
{
struct V_8 * V_9 = F_16 ( V_47 ) ;
int V_92 ;
if ( V_11 -> V_11 > 0x2ff )
return - V_15 ;
V_92 = F_8 ( V_9 , V_11 -> V_11 ) ;
V_11 -> V_93 = 2 ;
V_11 -> V_92 = ( V_94 ) V_92 ;
if ( V_11 -> V_92 > 0xffff )
return - V_95 ;
return 0 ;
}
static int F_36 ( struct V_46 * V_47 ,
const struct V_91 * V_11 )
{
struct V_8 * V_9 = F_16 ( V_47 ) ;
if ( V_11 -> V_11 > 0x2ff )
return - V_15 ;
if ( F_11 ( V_9 , V_11 -> V_11 , V_11 -> V_92 ) < 0 )
return - V_95 ;
return 0 ;
}
static int F_37 ( struct V_2 * V_2 , int V_96 , int V_19 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
int V_12 ;
if ( V_96 )
V_12 = F_12 ( V_9 , V_2 -> V_21 -> V_97 , V_19 ) ;
else
V_12 = F_13 ( V_9 , V_2 -> V_21 -> V_97 , V_19 ) ;
return V_12 ;
}
static int F_38 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
int V_18 ;
V_18 = F_39 ( V_98 ) ;
if ( V_18 >= 0 )
return ( V_18 & 0x2f ) * ( 1 << ( ( V_18 >> 10 ) & 1 ) ) *
( 1 << ( ( V_18 >> 9 ) & 1 ) ) ;
return V_18 ;
}
static int F_40 ( struct V_2 * V_2 , int V_99 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
T_1 V_92 ;
if ( V_99 > 63 * 2 * 2 )
return - V_15 ;
if ( ( V_99 >= 64 * 2 ) && ( V_99 < 63 * 2 * 2 ) )
V_92 = ( 1 << 10 ) | ( 1 << 9 ) | ( V_99 / 4 ) ;
else if ( ( V_99 >= 64 ) && ( V_99 < 64 * 2 ) )
V_92 = ( 1 << 9 ) | ( V_99 / 2 ) ;
else
V_92 = V_99 ;
return F_17 ( V_98 , V_92 ) ;
}
static int F_41 ( struct V_2 * V_2 , int V_92 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
if ( V_92 == V_100 )
return F_22 ( V_101 , V_102 ) ;
return F_23 ( V_101 , V_102 ) ;
}
static int F_42 ( struct V_2 * V_2 , int V_103 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
if ( V_103 )
return F_22 ( V_101 , V_104 ) ;
return F_23 ( V_101 , V_104 ) ;
}
static int F_43 ( struct V_105 * V_106 )
{
struct V_2 * V_2 = F_4 ( V_106 -> V_107 ,
struct V_2 , V_108 ) ;
switch ( V_106 -> V_109 ) {
case V_110 :
return F_37 ( V_2 , V_106 -> V_92 ,
V_111 ) ;
case V_112 :
return F_37 ( V_2 , V_106 -> V_92 ,
V_113 ) ;
case V_114 :
return F_40 ( V_2 , V_106 -> V_92 ) ;
case V_115 :
return F_41 ( V_2 , V_106 -> V_92 ) ;
case V_116 :
return F_42 ( V_2 , V_106 -> V_92 ) ;
}
return - V_15 ;
}
static int F_44 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
int V_12 ;
F_45 ( V_2 -> V_99 , F_38 ( V_2 ) ) ;
V_12 = F_22 ( V_42 , V_44 ) ;
if ( ! V_12 )
V_12 = F_22 ( V_42 , V_45 |
V_117 |
V_118 ) ;
if ( ! V_12 )
V_12 = F_23 ( V_42 , V_43 ) ;
return V_12 ;
}
static void F_46 ( struct V_2 * V_2 )
{
F_15 ( V_2 , V_2 -> V_21 ) ;
F_31 ( V_2 , V_2 -> V_7 -> V_4 ) ;
F_19 ( V_2 , & V_2 -> V_25 ,
V_2 -> V_26 , V_2 -> V_27 , V_2 -> V_7 -> V_4 ) ;
F_47 ( & V_2 -> V_108 ) ;
}
static int F_48 ( struct V_2 * V_2 )
{
int V_12 = F_20 ( V_2 ) ;
if ( ! V_12 )
V_12 = F_21 ( V_2 ) ;
if ( ! V_12 )
F_46 ( V_2 ) ;
return V_12 ;
}
static int F_49 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
int V_12 ;
V_12 = F_20 ( V_2 ) ;
if ( ! V_12 )
V_12 = F_21 ( V_2 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_2 , V_2 -> V_21 ) ;
if ( V_12 )
F_32 ( & V_9 -> V_17 , L_6 , V_12 ) ;
return V_12 ;
}
static int F_50 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
struct V_119 * V_120 = F_51 ( V_9 ) ;
int V_12 ;
V_12 = F_52 ( & V_9 -> V_17 , V_120 , V_2 -> V_121 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_48 ( V_2 ) ;
if ( V_12 < 0 ) {
F_32 ( & V_9 -> V_17 , L_7 , V_12 ) ;
F_53 ( & V_9 -> V_17 , V_120 , V_2 -> V_121 ) ;
}
return V_12 ;
}
static void F_54 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_16 ( & V_2 -> V_10 ) ;
struct V_119 * V_120 = F_51 ( V_9 ) ;
F_44 ( V_2 ) ;
F_53 ( & V_9 -> V_17 , V_120 , V_2 -> V_121 ) ;
}
static int F_55 ( struct V_46 * V_47 , int V_103 )
{
struct V_2 * V_2 = F_4 ( V_47 , struct V_2 , V_10 ) ;
int V_12 = 0 ;
F_56 ( & V_2 -> V_122 ) ;
if ( V_2 -> V_123 == ! V_103 ) {
if ( V_103 )
V_12 = F_50 ( V_2 ) ;
else
F_54 ( V_2 ) ;
}
if ( ! V_12 ) {
V_2 -> V_123 += V_103 ? 1 : - 1 ;
F_57 ( V_2 -> V_123 < 0 ) ;
}
F_58 ( & V_2 -> V_122 ) ;
return V_12 ;
}
static int F_59 ( struct V_46 * V_47 , unsigned int V_124 ,
enum V_3 * V_4 )
{
if ( V_124 >= F_2 ( V_6 ) )
return - V_15 ;
* V_4 = V_6 [ V_124 ] . V_4 ;
return 0 ;
}
static int F_60 ( struct V_46 * V_47 ,
struct V_125 * V_126 )
{
struct V_8 * V_9 = F_16 ( V_47 ) ;
struct V_119 * V_120 = F_51 ( V_9 ) ;
V_126 -> V_127 = V_128 | V_129 |
V_130 | V_131 |
V_132 ;
V_126 -> type = V_133 ;
V_126 -> V_127 = F_61 ( V_120 , V_126 ) ;
return 0 ;
}
static int F_62 ( struct V_8 * V_9 )
{
struct V_2 * V_2 = F_3 ( V_9 ) ;
T_2 V_18 ;
int V_12 ;
V_12 = F_55 ( & V_2 -> V_10 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_18 = F_39 ( V_134 ) ;
switch ( V_18 ) {
case 0x143a :
F_63 ( & V_9 -> V_17 ,
L_8 , V_18 ) ;
break;
case 0x148c :
F_63 ( & V_9 -> V_17 , L_9 , V_18 ) ;
break;
default:
F_32 ( & V_9 -> V_17 ,
L_10 ,
V_18 ) ;
V_12 = - V_135 ;
goto V_136;
}
V_12 = F_49 ( V_2 ) ;
if ( V_12 )
goto V_136;
V_12 = F_47 ( & V_2 -> V_108 ) ;
V_136:
F_55 ( & V_2 -> V_10 , 0 ) ;
return V_12 ;
}
static int F_64 ( struct V_8 * V_9 ,
const struct V_137 * V_138 )
{
struct V_2 * V_2 ;
struct V_139 * V_140 = F_65 ( V_9 -> V_17 . V_141 ) ;
struct V_119 * V_120 = F_51 ( V_9 ) ;
int V_12 ;
if ( V_9 -> V_17 . V_142 ) {
V_120 = F_66 ( & V_9 -> V_17 , sizeof( * V_120 ) , V_143 ) ;
if ( ! V_120 )
return - V_144 ;
V_9 -> V_17 . V_145 = V_120 ;
}
if ( ! V_120 ) {
F_32 ( & V_9 -> V_17 , L_11 ) ;
return - V_15 ;
}
if ( ! F_67 ( V_140 , V_146 ) ) {
F_68 ( & V_140 -> V_17 ,
L_12 ) ;
return - V_95 ;
}
V_2 = F_66 ( & V_9 -> V_17 , sizeof( struct V_2 ) , V_143 ) ;
if ( ! V_2 )
return - V_144 ;
V_2 -> V_121 = F_69 ( & V_9 -> V_17 , L_13 ) ;
if ( F_70 ( V_2 -> V_121 ) )
return - V_147 ;
V_2 -> V_21 = & V_39 ;
F_71 ( & V_2 -> V_10 , V_9 , & V_148 ) ;
F_72 ( & V_2 -> V_108 , 5 ) ;
F_73 ( & V_2 -> V_108 , & V_149 ,
V_110 , 0 , 1 , 1 , 0 ) ;
F_73 ( & V_2 -> V_108 , & V_149 ,
V_112 , 0 , 1 , 1 , 0 ) ;
F_73 ( & V_2 -> V_108 , & V_149 ,
V_116 , 0 , 1 , 1 , 1 ) ;
V_2 -> V_99 = F_73 ( & V_2 -> V_108 , & V_149 ,
V_114 , 0 , 63 * 2 * 2 , 1 , 32 ) ;
F_74 ( & V_2 -> V_108 ,
& V_149 , V_115 , 1 , 0 ,
V_100 ) ;
V_2 -> V_10 . V_150 = & V_2 -> V_108 ;
if ( V_2 -> V_108 . error ) {
V_12 = V_2 -> V_108 . error ;
goto V_151;
}
V_2 -> V_25 . V_33 = V_53 ;
V_2 -> V_25 . V_35 = V_55 ;
V_2 -> V_25 . V_26 = V_54 ;
V_2 -> V_25 . V_27 = V_56 ;
V_2 -> V_7 = & V_6 [ 0 ] ;
V_2 -> V_14 = - 1 ;
F_75 ( & V_2 -> V_122 ) ;
V_12 = F_76 ( & V_9 -> V_17 , V_120 ) ;
if ( V_12 < 0 )
goto V_152;
V_12 = F_62 ( V_9 ) ;
if ( V_12 < 0 )
goto V_152;
V_2 -> V_10 . V_17 = & V_9 -> V_17 ;
V_12 = F_77 ( & V_2 -> V_10 ) ;
if ( V_12 < 0 )
goto V_152;
return 0 ;
V_152:
F_78 ( & V_2 -> V_108 ) ;
V_151:
F_79 ( V_2 -> V_121 ) ;
return V_12 ;
}
static int F_80 ( struct V_8 * V_9 )
{
struct V_2 * V_2 = F_3 ( V_9 ) ;
F_81 ( & V_2 -> V_10 ) ;
F_79 ( V_2 -> V_121 ) ;
F_82 ( & V_2 -> V_10 ) ;
F_78 ( & V_2 -> V_108 ) ;
return 0 ;
}
