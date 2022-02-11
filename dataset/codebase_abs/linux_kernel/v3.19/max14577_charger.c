static enum V_1 F_1 (
enum V_2 V_3 , T_1 V_4 ) {
switch ( V_4 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return V_4 ;
case V_11 :
case V_12 :
if ( V_3 == V_13 )
V_4 |= 0x8 ;
return V_4 ;
default:
F_2 ( 1 , L_1 , V_4 ) ;
return V_4 ;
}
}
static int F_3 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_16 ;
int V_19 = V_20 ;
T_1 V_21 ;
F_4 ( V_17 , V_22 , & V_21 ) ;
if ( ( V_21 & V_23 ) == 0 )
goto V_24;
F_4 ( V_17 , V_25 , & V_21 ) ;
if ( V_21 & V_26 ) {
if ( V_21 & V_27 )
V_19 = V_28 ;
else
V_19 = V_29 ;
goto V_24;
}
V_24:
V_15 -> V_30 = V_19 ;
return V_19 ;
}
static int F_5 ( struct V_14 * V_15 )
{
if ( F_3 ( V_15 ) == V_29 )
return V_31 ;
return V_32 ;
}
static int F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_16 ;
T_1 V_21 ;
enum V_1 V_33 ;
F_4 ( V_17 , V_34 , & V_21 ) ;
V_21 = ( ( V_21 & V_35 ) >> V_36 ) ;
V_33 = F_1 ( V_15 -> V_18 -> V_3 , V_21 ) ;
switch ( V_33 ) {
case V_6 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_37 :
return 1 ;
case V_5 :
case V_7 :
case V_12 :
case V_38 :
default:
return 0 ;
}
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_16 ;
int V_19 = V_39 ;
T_1 V_21 ;
enum V_1 V_33 ;
F_4 ( V_17 , V_34 , & V_21 ) ;
V_21 = ( ( V_21 & V_35 ) >> V_36 ) ;
V_33 = F_1 ( V_15 -> V_18 -> V_3 , V_21 ) ;
if ( V_33 == V_11 ) {
V_19 = V_40 ;
goto V_24;
}
F_4 ( V_17 , V_25 , & V_21 ) ;
if ( V_21 & V_41 ) {
V_19 = V_42 ;
goto V_24;
}
V_24:
V_15 -> V_43 = V_19 ;
return V_19 ;
}
static int F_8 ( struct V_14 * V_15 )
{
return 1 ;
}
static int F_9 ( struct V_14 * V_15 ,
unsigned long V_44 )
{
T_1 V_21 ;
switch ( V_44 ) {
case 5 ... 7 :
V_21 = V_44 - 3 ;
break;
case 0 :
V_21 = 0x7 ;
break;
default:
F_10 ( V_15 -> V_45 , L_2 ,
V_44 ) ;
return - V_46 ;
}
V_21 <<= V_47 ;
return F_11 ( V_15 -> V_18 -> V_16 ,
V_48 , V_49 , V_21 ) ;
}
static int F_12 ( struct V_14 * V_15 ,
unsigned int V_50 )
{
T_1 V_21 ;
if ( V_50 < V_51 ||
V_50 > V_52 )
return - V_46 ;
if ( V_50 == 4200000 )
V_21 = 0x0 ;
else if ( V_50 == V_52 )
V_21 = 0x1f ;
else if ( V_50 <= 4280000 ) {
unsigned int V_4 = V_50 ;
V_4 -= V_51 ;
V_4 /= V_53 ;
if ( V_50 <= 4180000 )
V_21 = 0x1 + V_4 ;
else
V_21 = V_4 ;
} else
return - V_46 ;
V_21 <<= V_54 ;
return F_13 ( V_15 -> V_18 -> V_16 ,
V_55 , V_21 ) ;
}
static int F_14 ( struct V_14 * V_15 ,
unsigned int V_56 )
{
unsigned int V_57 = 0xf ;
T_1 V_21 ;
switch ( V_15 -> V_18 -> V_3 ) {
case V_13 :
if ( V_56 < 5000 )
return - V_46 ;
if ( V_56 >= 7500 && V_56 < 10000 )
V_57 = 0x0 ;
else if ( V_56 <= 50000 ) {
V_57 = V_56 / 5000 ;
} else {
V_56 = F_15 ( V_56 , 100000U ) - 50000U ;
V_57 = 0xa + V_56 / 10000 ;
}
break;
case V_58 :
default:
if ( V_56 < V_59 )
return - V_46 ;
V_56 = F_15 ( V_56 , V_60 ) ;
V_56 -= V_59 ;
V_57 = V_56 / V_61 ;
break;
}
V_21 = V_57 << V_62 ;
return F_11 ( V_15 -> V_18 -> V_16 ,
V_63 , V_64 ,
V_21 ) ;
}
static int F_16 ( struct V_14 * V_15 ,
unsigned int V_56 )
{
T_1 V_21 ;
int V_65 ;
const struct V_66 * V_67 =
& V_68 [ V_15 -> V_18 -> V_3 ] ;
V_65 = F_17 ( V_67 , V_56 , V_56 , & V_21 ) ;
if ( V_65 ) {
F_10 ( V_15 -> V_45 , L_3 , V_56 ) ;
return V_65 ;
}
return F_11 ( V_15 -> V_18 -> V_16 ,
V_69 ,
V_70 | V_71 ,
V_21 ) ;
}
static int F_18 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_16 ;
T_1 V_21 ;
int V_65 ;
V_21 = 0x1 << V_72 ;
F_11 ( V_17 , V_73 ,
V_74 | V_75 ,
V_21 ) ;
V_21 = 0x1 << V_76 ;
V_21 |= 0x1 << V_77 ;
F_13 ( V_17 , V_78 , V_21 ) ;
V_21 = 0x0 << V_79 ;
F_13 ( V_17 , V_80 , V_21 ) ;
V_65 = F_12 ( V_15 , V_15 -> V_81 -> V_82 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_14 ( V_15 , V_15 -> V_81 -> V_83 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_16 ( V_15 , V_15 -> V_81 -> V_84 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_9 ( V_15 ,
V_85 ) ;
if ( V_65 )
return V_65 ;
switch ( V_15 -> V_81 -> V_86 ) {
case 7500000 :
V_21 = 0x0 ;
break;
case 6000000 :
case 6500000 :
case 7000000 :
V_21 = 0x1 + ( V_15 -> V_81 -> V_86 - 6000000 ) / 500000 ;
break;
default:
F_10 ( V_15 -> V_45 , L_4 ,
V_15 -> V_81 -> V_86 ) ;
return - V_46 ;
}
V_21 <<= V_87 ;
F_13 ( V_17 , V_88 , V_21 ) ;
return 0 ;
}
static int F_19 ( struct V_89 * V_90 ,
enum V_91 V_92 ,
union V_93 * V_4 )
{
struct V_14 * V_15 = F_20 ( V_90 ,
struct V_14 ,
V_94 ) ;
int V_65 = 0 ;
switch ( V_92 ) {
case V_95 :
V_4 -> V_96 = F_3 ( V_15 ) ;
break;
case V_97 :
V_4 -> V_96 = F_5 ( V_15 ) ;
break;
case V_98 :
V_4 -> V_96 = F_7 ( V_15 ) ;
break;
case V_99 :
V_4 -> V_96 = F_8 ( V_15 ) ;
break;
case V_100 :
V_4 -> V_96 = F_6 ( V_15 ) ;
break;
case V_101 :
F_21 ( F_22 ( V_102 ) != V_103 ) ;
V_4 -> V_104 = V_102 [ V_15 -> V_18 -> V_3 ] ;
break;
case V_105 :
V_4 -> V_104 = V_106 ;
break;
default:
return - V_46 ;
}
return V_65 ;
}
static struct V_107 * F_23 (
struct V_108 * V_109 )
{
struct V_107 * V_81 ;
struct V_110 * V_111 = V_109 -> V_45 . V_112 ;
int V_65 ;
if ( ! V_111 ) {
F_10 ( & V_109 -> V_45 , L_5 ) ;
return F_24 ( - V_46 ) ;
}
V_81 = F_25 ( & V_109 -> V_45 , sizeof( * V_81 ) , V_113 ) ;
if ( ! V_81 )
return F_24 ( - V_114 ) ;
V_65 = F_26 ( V_111 , L_6 ,
& V_81 -> V_82 ) ;
if ( V_65 ) {
F_10 ( & V_109 -> V_45 , L_7 ) ;
return F_24 ( V_65 ) ;
}
V_65 = F_26 ( V_111 , L_8 ,
& V_81 -> V_84 ) ;
if ( V_65 ) {
F_10 ( & V_109 -> V_45 , L_9 ) ;
return F_24 ( V_65 ) ;
}
V_65 = F_26 ( V_111 , L_10 , & V_81 -> V_83 ) ;
if ( V_65 ) {
F_10 ( & V_109 -> V_45 , L_11 ) ;
return F_24 ( V_65 ) ;
}
V_65 = F_26 ( V_111 , L_12 , & V_81 -> V_86 ) ;
if ( V_65 ) {
F_10 ( & V_109 -> V_45 , L_13 ) ;
return F_24 ( V_65 ) ;
}
return V_81 ;
}
static struct V_107 * F_23 (
struct V_108 * V_109 )
{
return NULL ;
}
static T_2 F_27 ( struct V_115 * V_45 ,
struct V_116 * V_117 , char * V_118 )
{
struct V_14 * V_15 = F_28 ( V_45 ) ;
T_1 V_21 ;
int V_65 ;
unsigned int V_4 ;
V_65 = F_4 ( V_15 -> V_18 -> V_16 , V_48 ,
& V_21 ) ;
if ( V_65 )
return V_65 ;
V_21 &= V_49 ;
V_21 >>= V_47 ;
switch ( V_21 ) {
case 0x2 ... 0x4 :
V_4 = V_21 + 3 ;
break;
case 0x7 :
V_4 = 0 ;
break;
default:
V_4 = 5 ;
break;
}
return F_29 ( V_118 , V_119 , L_14 , V_4 ) ;
}
static T_2 F_30 ( struct V_115 * V_45 ,
struct V_116 * V_117 , const char * V_118 , T_3 V_120 )
{
struct V_14 * V_15 = F_28 ( V_45 ) ;
unsigned long V_4 ;
int V_65 ;
V_65 = F_31 ( V_118 , 10 , & V_4 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_9 ( V_15 , V_4 ) ;
if ( V_65 )
return V_65 ;
return V_120 ;
}
static int F_32 ( struct V_108 * V_109 )
{
struct V_14 * V_15 ;
struct V_18 * V_18 = F_28 ( V_109 -> V_45 . V_121 ) ;
int V_65 ;
V_15 = F_25 ( & V_109 -> V_45 , sizeof( * V_15 ) , V_113 ) ;
if ( ! V_15 )
return - V_114 ;
F_33 ( V_109 , V_15 ) ;
V_15 -> V_45 = & V_109 -> V_45 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_81 = F_23 ( V_109 ) ;
if ( F_34 ( V_15 -> V_81 ) )
return F_35 ( V_15 -> V_81 ) ;
V_65 = F_18 ( V_15 ) ;
if ( V_65 )
return V_65 ;
V_15 -> V_94 . V_122 = L_15 ,
V_15 -> V_94 . type = V_123 ,
V_15 -> V_94 . V_124 = V_125 ,
V_15 -> V_94 . V_126 = F_22 ( V_125 ) ,
V_15 -> V_94 . V_127 = F_19 ,
V_65 = F_36 ( & V_109 -> V_45 , & V_128 ) ;
if ( V_65 ) {
F_10 ( & V_109 -> V_45 , L_16 ) ;
return V_65 ;
}
V_65 = F_37 ( & V_109 -> V_45 , & V_15 -> V_94 ) ;
if ( V_65 ) {
F_10 ( & V_109 -> V_45 , L_17 ) ;
goto V_129;
}
F_21 ( V_59 +
V_61 * 0xf !=
V_60 ) ;
return 0 ;
V_129:
F_38 ( & V_109 -> V_45 , & V_128 ) ;
return V_65 ;
}
static int F_39 ( struct V_108 * V_109 )
{
struct V_14 * V_15 = F_40 ( V_109 ) ;
F_38 ( & V_109 -> V_45 , & V_128 ) ;
F_41 ( & V_15 -> V_94 ) ;
return 0 ;
}
