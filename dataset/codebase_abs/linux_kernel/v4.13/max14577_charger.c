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
static int F_3 ( struct V_14 * V_15 , int * V_4 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_16 ;
int V_19 ;
T_1 V_20 ;
V_19 = F_4 ( V_17 , V_21 , & V_20 ) ;
if ( V_19 < 0 )
goto V_22;
if ( ( V_20 & V_23 ) == 0 ) {
* V_4 = V_24 ;
goto V_22;
}
V_19 = F_4 ( V_17 , V_25 , & V_20 ) ;
if ( V_19 < 0 )
goto V_22;
if ( V_20 & V_26 ) {
if ( V_20 & V_27 )
* V_4 = V_28 ;
else
* V_4 = V_29 ;
goto V_22;
}
* V_4 = V_24 ;
V_22:
return V_19 ;
}
static int F_5 ( struct V_14 * V_15 , int * V_4 )
{
int V_19 , V_30 ;
V_19 = F_3 ( V_15 , & V_30 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_30 == V_29 )
* V_4 = V_31 ;
else
* V_4 = V_32 ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 , int * V_4 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_16 ;
T_1 V_20 ;
int V_19 ;
enum V_1 V_33 ;
V_19 = F_4 ( V_17 , V_34 , & V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
V_20 = ( ( V_20 & V_35 ) >> V_36 ) ;
V_33 = F_1 ( V_15 -> V_18 -> V_3 , V_20 ) ;
switch ( V_33 ) {
case V_6 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_37 :
* V_4 = 1 ;
break;
case V_5 :
case V_7 :
case V_12 :
case V_38 :
default:
* V_4 = 0 ;
}
return 0 ;
}
static int F_7 ( struct V_14 * V_15 , int * V_4 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_16 ;
int V_19 ;
T_1 V_20 ;
enum V_1 V_33 ;
V_19 = F_4 ( V_17 , V_34 , & V_20 ) ;
if ( V_19 < 0 )
goto V_22;
V_20 = ( ( V_20 & V_35 ) >> V_36 ) ;
V_33 = F_1 ( V_15 -> V_18 -> V_3 , V_20 ) ;
if ( V_33 == V_11 ) {
* V_4 = V_39 ;
goto V_22;
}
V_19 = F_4 ( V_17 , V_25 , & V_20 ) ;
if ( V_19 < 0 )
goto V_22;
if ( V_20 & V_40 ) {
* V_4 = V_41 ;
goto V_22;
}
* V_4 = V_42 ;
V_22:
return V_19 ;
}
static int F_8 ( struct V_14 * V_15 , int * V_4 )
{
* V_4 = 1 ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 ,
unsigned long V_43 )
{
T_1 V_20 ;
switch ( V_43 ) {
case 5 ... 7 :
V_20 = V_43 - 3 ;
break;
case 0 :
V_20 = 0x7 ;
break;
default:
F_10 ( V_15 -> V_44 , L_2 ,
V_43 ) ;
return - V_45 ;
}
V_20 <<= V_46 ;
return F_11 ( V_15 -> V_18 -> V_16 ,
V_47 , V_48 , V_20 ) ;
}
static int F_12 ( struct V_14 * V_15 ,
unsigned int V_49 )
{
T_1 V_20 ;
if ( V_49 < V_50 ||
V_49 > V_51 )
return - V_45 ;
if ( V_49 == 4200000 )
V_20 = 0x0 ;
else if ( V_49 == V_51 )
V_20 = 0x1f ;
else if ( V_49 <= 4280000 ) {
unsigned int V_4 = V_49 ;
V_4 -= V_50 ;
V_4 /= V_52 ;
if ( V_49 <= 4180000 )
V_20 = 0x1 + V_4 ;
else
V_20 = V_4 ;
} else
return - V_45 ;
V_20 <<= V_53 ;
return F_13 ( V_15 -> V_18 -> V_16 ,
V_54 , V_20 ) ;
}
static int F_14 ( struct V_14 * V_15 ,
unsigned int V_55 )
{
unsigned int V_56 = 0xf ;
T_1 V_20 ;
switch ( V_15 -> V_18 -> V_3 ) {
case V_13 :
if ( V_55 < 5000 )
return - V_45 ;
if ( V_55 >= 7500 && V_55 < 10000 )
V_56 = 0x0 ;
else if ( V_55 <= 50000 ) {
V_56 = V_55 / 5000 ;
} else {
V_55 = F_15 ( V_55 , 100000U ) - 50000U ;
V_56 = 0xa + V_55 / 10000 ;
}
break;
case V_57 :
default:
if ( V_55 < V_58 )
return - V_45 ;
V_55 = F_15 ( V_55 , V_59 ) ;
V_55 -= V_58 ;
V_56 = V_55 / V_60 ;
break;
}
V_20 = V_56 << V_61 ;
return F_11 ( V_15 -> V_18 -> V_16 ,
V_62 , V_63 ,
V_20 ) ;
}
static int F_16 ( struct V_14 * V_15 ,
unsigned int V_55 )
{
T_1 V_20 ;
int V_19 ;
const struct V_64 * V_65 =
& V_66 [ V_15 -> V_18 -> V_3 ] ;
V_19 = F_17 ( V_65 , V_55 , V_55 , & V_20 ) ;
if ( V_19 ) {
F_10 ( V_15 -> V_44 , L_3 , V_55 ) ;
return V_19 ;
}
return F_11 ( V_15 -> V_18 -> V_16 ,
V_67 ,
V_68 | V_69 ,
V_20 ) ;
}
static int F_18 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_16 ;
T_1 V_20 ;
int V_19 ;
V_20 = 0x1 << V_70 ;
F_11 ( V_17 , V_71 ,
V_72 | V_73 ,
V_20 ) ;
V_20 = 0x1 << V_74 ;
V_20 |= 0x1 << V_75 ;
F_13 ( V_17 , V_76 , V_20 ) ;
V_20 = 0x0 << V_77 ;
F_13 ( V_17 , V_78 , V_20 ) ;
V_19 = F_12 ( V_15 , V_15 -> V_79 -> V_80 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_14 ( V_15 , V_15 -> V_79 -> V_81 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_16 ( V_15 , V_15 -> V_79 -> V_82 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_9 ( V_15 ,
V_83 ) ;
if ( V_19 )
return V_19 ;
switch ( V_15 -> V_79 -> V_84 ) {
case 7500000 :
V_20 = 0x0 ;
break;
case 6000000 :
case 6500000 :
case 7000000 :
V_20 = 0x1 + ( V_15 -> V_79 -> V_84 - 6000000 ) / 500000 ;
break;
default:
F_10 ( V_15 -> V_44 , L_4 ,
V_15 -> V_79 -> V_84 ) ;
return - V_45 ;
}
V_20 <<= V_85 ;
F_13 ( V_17 , V_86 , V_20 ) ;
return 0 ;
}
static int F_19 ( struct V_87 * V_88 ,
enum V_89 V_90 ,
union V_91 * V_4 )
{
struct V_14 * V_15 = F_20 ( V_88 ) ;
int V_19 = 0 ;
switch ( V_90 ) {
case V_92 :
V_19 = F_3 ( V_15 , & V_4 -> V_93 ) ;
break;
case V_94 :
V_19 = F_5 ( V_15 , & V_4 -> V_93 ) ;
break;
case V_95 :
V_19 = F_7 ( V_15 , & V_4 -> V_93 ) ;
break;
case V_96 :
V_19 = F_8 ( V_15 , & V_4 -> V_93 ) ;
break;
case V_97 :
V_19 = F_6 ( V_15 , & V_4 -> V_93 ) ;
break;
case V_98 :
F_21 ( F_22 ( V_99 ) != V_100 ) ;
V_4 -> V_101 = V_99 [ V_15 -> V_18 -> V_3 ] ;
break;
case V_102 :
V_4 -> V_101 = V_103 ;
break;
default:
return - V_45 ;
}
return V_19 ;
}
static struct V_104 * F_23 (
struct V_105 * V_106 )
{
struct V_104 * V_79 ;
struct V_107 * V_108 = V_106 -> V_44 . V_109 ;
int V_19 ;
if ( ! V_108 ) {
F_10 ( & V_106 -> V_44 , L_5 ) ;
return F_24 ( - V_45 ) ;
}
V_79 = F_25 ( & V_106 -> V_44 , sizeof( * V_79 ) , V_110 ) ;
if ( ! V_79 )
return F_24 ( - V_111 ) ;
V_19 = F_26 ( V_108 , L_6 ,
& V_79 -> V_80 ) ;
if ( V_19 ) {
F_10 ( & V_106 -> V_44 , L_7 ) ;
return F_24 ( V_19 ) ;
}
V_19 = F_26 ( V_108 , L_8 ,
& V_79 -> V_82 ) ;
if ( V_19 ) {
F_10 ( & V_106 -> V_44 , L_9 ) ;
return F_24 ( V_19 ) ;
}
V_19 = F_26 ( V_108 , L_10 , & V_79 -> V_81 ) ;
if ( V_19 ) {
F_10 ( & V_106 -> V_44 , L_11 ) ;
return F_24 ( V_19 ) ;
}
V_19 = F_26 ( V_108 , L_12 , & V_79 -> V_84 ) ;
if ( V_19 ) {
F_10 ( & V_106 -> V_44 , L_13 ) ;
return F_24 ( V_19 ) ;
}
return V_79 ;
}
static struct V_104 * F_23 (
struct V_105 * V_106 )
{
return NULL ;
}
static T_2 F_27 ( struct V_112 * V_44 ,
struct V_113 * V_114 , char * V_115 )
{
struct V_14 * V_15 = F_28 ( V_44 ) ;
T_1 V_20 ;
int V_19 ;
unsigned int V_4 ;
V_19 = F_4 ( V_15 -> V_18 -> V_16 , V_47 ,
& V_20 ) ;
if ( V_19 )
return V_19 ;
V_20 &= V_48 ;
V_20 >>= V_46 ;
switch ( V_20 ) {
case 0x2 ... 0x4 :
V_4 = V_20 + 3 ;
break;
case 0x7 :
V_4 = 0 ;
break;
default:
V_4 = 5 ;
break;
}
return F_29 ( V_115 , V_116 , L_14 , V_4 ) ;
}
static T_2 F_30 ( struct V_112 * V_44 ,
struct V_113 * V_114 , const char * V_115 , T_3 V_117 )
{
struct V_14 * V_15 = F_28 ( V_44 ) ;
unsigned long V_4 ;
int V_19 ;
V_19 = F_31 ( V_115 , 10 , & V_4 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_9 ( V_15 , V_4 ) ;
if ( V_19 )
return V_19 ;
return V_117 ;
}
static int F_32 ( struct V_105 * V_106 )
{
struct V_14 * V_15 ;
struct V_118 V_119 = {} ;
struct V_18 * V_18 = F_28 ( V_106 -> V_44 . V_120 ) ;
int V_19 ;
V_15 = F_25 ( & V_106 -> V_44 , sizeof( * V_15 ) , V_110 ) ;
if ( ! V_15 )
return - V_111 ;
F_33 ( V_106 , V_15 ) ;
V_15 -> V_44 = & V_106 -> V_44 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_79 = F_23 ( V_106 ) ;
if ( F_34 ( V_15 -> V_79 ) )
return F_35 ( V_15 -> V_79 ) ;
V_19 = F_18 ( V_15 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_36 ( & V_106 -> V_44 , & V_121 ) ;
if ( V_19 ) {
F_10 ( & V_106 -> V_44 , L_15 ) ;
return V_19 ;
}
V_119 . V_122 = V_15 ;
V_15 -> V_123 = F_37 ( & V_106 -> V_44 , & V_124 ,
& V_119 ) ;
if ( F_38 ( V_15 -> V_123 ) ) {
F_10 ( & V_106 -> V_44 , L_16 ) ;
V_19 = F_35 ( V_15 -> V_123 ) ;
goto V_125;
}
F_21 ( V_58 +
V_60 * 0xf !=
V_59 ) ;
return 0 ;
V_125:
F_39 ( & V_106 -> V_44 , & V_121 ) ;
return V_19 ;
}
static int F_40 ( struct V_105 * V_106 )
{
struct V_14 * V_15 = F_41 ( V_106 ) ;
F_39 ( & V_106 -> V_44 , & V_121 ) ;
F_42 ( V_15 -> V_123 ) ;
return 0 ;
}
