static int F_1 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
unsigned int V_4 ;
V_3 = F_2 ( V_1 , V_5 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 &= V_6 ;
V_4 >>= V_7 ;
switch ( V_4 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
* V_2 = V_13 ;
break;
case V_14 :
* V_2 = V_15 ;
break;
case V_16 :
case V_17 :
* V_2 = V_18 ;
break;
case V_19 :
case V_20 :
case V_21 :
* V_2 = V_22 ;
break;
case V_23 :
default:
* V_2 = V_24 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
unsigned int V_4 ;
V_3 = F_2 ( V_1 , V_5 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 &= V_6 ;
V_4 >>= V_7 ;
switch ( V_4 ) {
case V_8 :
case V_11 :
* V_2 = V_25 ;
break;
case V_9 :
case V_10 :
case V_12 :
* V_2 = V_26 ;
break;
case V_14 :
case V_16 :
case V_17 :
case V_19 :
case V_20 :
case V_21 :
* V_2 = V_27 ;
break;
case V_23 :
default:
* V_2 = V_28 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
unsigned int V_4 ;
V_3 = F_2 ( V_1 , V_5 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 &= V_29 ;
V_4 >>= V_30 ;
switch ( V_4 ) {
case V_31 :
* V_2 = V_32 ;
break;
case V_33 :
case V_34 :
case V_35 :
* V_2 = V_36 ;
break;
case V_37 :
* V_2 = V_38 ;
break;
case V_39 :
* V_2 = V_40 ;
break;
case V_41 :
* V_2 = V_42 ;
break;
case V_43 :
default:
* V_2 = V_44 ;
break;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , int * V_2 )
{
unsigned int V_4 ;
int V_3 ;
V_3 = F_2 ( V_1 , V_45 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_2 = ( V_4 & V_46 ) ? 0 : 1 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , int * V_2 )
{
unsigned int V_4 ;
int V_3 ;
V_3 = F_2 ( V_1 , V_45 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_2 = ( V_4 & V_47 ) ? 1 : 0 ;
return 0 ;
}
static int F_7 ( struct V_48 * V_49 ,
enum V_50 V_51 ,
union V_52 * V_2 )
{
struct V_53 * V_54 = F_8 ( V_49 ) ;
struct V_1 * V_1 = V_54 -> V_55 -> V_1 ;
int V_3 = 0 ;
switch ( V_51 ) {
case V_56 :
V_3 = F_1 ( V_1 , & V_2 -> V_57 ) ;
break;
case V_58 :
V_3 = F_3 ( V_1 , & V_2 -> V_57 ) ;
break;
case V_59 :
V_3 = F_4 ( V_1 , & V_2 -> V_57 ) ;
break;
case V_60 :
V_3 = F_5 ( V_1 , & V_2 -> V_57 ) ;
break;
case V_61 :
V_3 = F_6 ( V_1 , & V_2 -> V_57 ) ;
break;
case V_62 :
V_2 -> V_63 = V_64 ;
break;
case V_65 :
V_2 -> V_63 = V_66 ;
break;
default:
return - V_67 ;
}
return V_3 ;
}
static T_1 F_9 ( struct V_68 * V_69 ,
struct V_70 * V_71 , const char * V_72 , T_2 V_73 ,
int (* F_10)( struct V_53 * , unsigned long ) )
{
struct V_53 * V_54 = F_11 ( V_69 ) ;
unsigned long V_2 ;
int V_3 ;
V_3 = F_12 ( V_72 , 10 , & V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_10 ( V_54 , V_2 ) ;
if ( V_3 )
return V_3 ;
return V_73 ;
}
static T_1 F_13 ( struct V_68 * V_69 ,
struct V_70 * V_71 , char * V_72 )
{
struct V_53 * V_54 = F_11 ( V_69 ) ;
unsigned int V_4 , V_2 ;
int V_3 ;
V_3 = F_2 ( V_54 -> V_55 -> V_1 , V_74 ,
& V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 &= V_75 ;
V_4 >>= V_76 ;
switch ( V_4 ) {
case 0x1 ... 0x7 :
V_2 = 4 + ( V_4 - 1 ) * 2 ;
break;
case 0x0 :
default:
V_2 = 0 ;
break;
}
return F_14 ( V_72 , V_77 , L_1 , V_2 ) ;
}
static int F_15 ( struct V_53 * V_54 ,
unsigned long V_78 )
{
unsigned int V_4 ;
switch ( V_78 ) {
case 4 ... 16 :
V_4 = ( V_78 - 4 ) / 2 + 1 ;
break;
case 0 :
V_4 = 0 ;
break;
default:
return - V_67 ;
}
V_4 <<= V_76 ;
return F_16 ( V_54 -> V_55 -> V_1 ,
V_74 ,
V_75 , V_4 ) ;
}
static T_1 F_17 ( struct V_68 * V_69 ,
struct V_70 * V_71 , const char * V_72 , T_2 V_73 )
{
return F_9 ( V_69 , V_71 , V_72 , V_73 ,
F_15 ) ;
}
static T_1 F_18 ( struct V_68 * V_69 ,
struct V_70 * V_71 , char * V_72 )
{
struct V_53 * V_54 = F_11 ( V_69 ) ;
unsigned int V_4 , V_2 ;
int V_3 ;
V_3 = F_2 ( V_54 -> V_55 -> V_1 , V_79 ,
& V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 &= V_80 ;
V_4 >>= V_81 ;
if ( V_4 <= 0x04 )
V_2 = 100000 + V_4 * 25000 ;
else
V_2 = V_4 * 50000 ;
return F_14 ( V_72 , V_77 , L_1 , V_2 ) ;
}
static int F_19 ( struct V_53 * V_54 ,
unsigned long V_82 )
{
unsigned int V_4 ;
if ( V_82 < 100000 || V_82 > 350000 )
return - V_67 ;
if ( V_82 <= 200000 )
V_4 = ( V_82 - 100000 ) / 25000 ;
else
V_4 = V_82 / 50000 ;
V_4 <<= V_81 ;
return F_16 ( V_54 -> V_55 -> V_1 ,
V_79 ,
V_80 , V_4 ) ;
}
static T_1 F_20 ( struct V_68 * V_69 ,
struct V_70 * V_71 , const char * V_72 , T_2 V_73 )
{
return F_9 ( V_69 , V_71 , V_72 , V_73 ,
F_19 ) ;
}
static T_1 F_21 ( struct V_68 * V_69 ,
struct V_70 * V_71 , char * V_72 )
{
struct V_53 * V_54 = F_11 ( V_69 ) ;
unsigned int V_4 , V_2 ;
int V_3 ;
V_3 = F_2 ( V_54 -> V_55 -> V_1 , V_79 ,
& V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 &= V_83 ;
V_4 >>= V_84 ;
V_2 = V_4 * 10 ;
return F_14 ( V_72 , V_77 , L_1 , V_2 ) ;
}
static int F_22 ( struct V_53 * V_54 ,
unsigned long V_85 )
{
unsigned int V_4 ;
if ( V_85 > 70 )
return - V_67 ;
V_4 = V_85 / 10 ;
V_4 <<= V_84 ;
return F_16 ( V_54 -> V_55 -> V_1 ,
V_79 ,
V_83 , V_4 ) ;
}
static T_1 F_23 ( struct V_68 * V_69 ,
struct V_70 * V_71 , const char * V_72 , T_2 V_73 )
{
return F_9 ( V_69 , V_71 , V_72 , V_73 ,
F_22 ) ;
}
static int F_24 ( struct V_53 * V_54 ,
unsigned int V_86 )
{
unsigned int V_4 ;
if ( V_86 >= 3650000 && V_86 < 4340000 )
V_4 = ( V_86 - 3650000 ) / 25000 ;
else if ( V_86 >= 4340000 && V_86 < 4350000 )
V_4 = 0x1c ;
else if ( V_86 >= 4350000 && V_86 <= 4400000 )
V_4 = 0x1d + ( V_86 - 4350000 ) / 25000 ;
else {
F_25 ( V_54 -> V_69 , L_2 ) ;
return - V_67 ;
}
V_4 <<= V_87 ;
F_26 ( V_54 -> V_69 , L_3 , V_86 ,
V_4 ) ;
return F_16 ( V_54 -> V_55 -> V_1 ,
V_88 ,
V_89 , V_4 ) ;
}
static int F_27 ( struct V_53 * V_54 ,
unsigned int V_86 )
{
unsigned int V_4 ;
if ( V_86 < 3000000 || V_86 > 3700000 ) {
F_25 ( V_54 -> V_69 , L_4 ) ;
return - V_67 ;
}
V_4 = ( V_86 - 3000000 ) / 100000 ;
V_4 <<= V_90 ;
F_26 ( V_54 -> V_69 , L_5 ,
V_86 , V_4 ) ;
return F_16 ( V_54 -> V_55 -> V_1 ,
V_88 ,
V_91 , V_4 ) ;
}
static int F_28 ( struct V_53 * V_54 ,
unsigned int V_92 )
{
unsigned int V_4 ;
switch ( V_92 ) {
case 70 :
case 85 :
case 100 :
case 115 :
V_4 = ( V_92 - 70 ) / 15 ;
break;
default:
F_25 ( V_54 -> V_69 , L_6 ) ;
return - V_67 ;
}
V_4 <<= V_93 ;
F_26 ( V_54 -> V_69 , L_7 ,
V_92 , V_4 ) ;
return F_16 ( V_54 -> V_55 -> V_1 ,
V_94 ,
V_95 , V_4 ) ;
}
static int F_29 ( struct V_53 * V_54 ,
unsigned int V_82 )
{
unsigned int V_4 ;
if ( V_82 && ( V_82 < 2000000 || V_82 > 3500000 ) ) {
F_25 ( V_54 -> V_69 , L_8 ) ;
return - V_67 ;
}
if ( V_82 )
V_4 = ( ( V_82 - 2000000 ) / 250000 ) + 1 ;
else
V_4 = 0 ;
V_4 <<= V_96 ;
F_26 ( V_54 -> V_69 , L_9 , V_82 , V_4 ) ;
return F_16 ( V_54 -> V_55 -> V_1 ,
V_97 ,
V_98 , V_4 ) ;
}
static int F_30 ( struct V_53 * V_54 ,
unsigned int V_86 )
{
unsigned int V_4 ;
switch ( V_86 ) {
case 4300000 :
V_4 = 0x0 ;
break;
case 4700000 :
case 4800000 :
case 4900000 :
V_4 = ( V_86 - 4700000 ) / 100000 ;
default:
F_25 ( V_54 -> V_69 , L_10 ) ;
return - V_67 ;
}
V_4 <<= V_99 ;
F_26 ( V_54 -> V_69 , L_11 ,
V_86 , V_4 ) ;
return F_16 ( V_54 -> V_55 -> V_1 ,
V_97 ,
V_100 , V_4 ) ;
}
static int F_31 ( struct V_53 * V_54 )
{
int V_3 ;
unsigned int V_4 ;
V_4 = ( 0x3 << V_101 ) ;
V_3 = F_16 ( V_54 -> V_55 -> V_1 ,
V_102 ,
V_103 , V_4 ) ;
if ( V_3 ) {
F_25 ( V_54 -> V_69 , L_12 , V_3 ) ;
return V_3 ;
}
V_3 = F_15 ( V_54 , V_104 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_19 ( V_54 ,
V_105 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_22 ( V_54 , V_106 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_24 ( V_54 , V_54 -> V_107 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_27 ( V_54 , V_54 -> V_108 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_28 ( V_54 ,
V_54 -> V_109 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_29 ( V_54 , V_54 -> V_110 ) ;
if ( V_3 )
return V_3 ;
return F_30 ( V_54 ,
V_54 -> V_111 ) ;
}
static int F_32 ( struct V_68 * V_69 , struct V_53 * V_54 )
{
struct V_112 * V_113 = V_69 -> V_114 ;
if ( ! V_113 ) {
F_25 ( V_69 , L_13 ) ;
return - V_67 ;
}
if ( F_33 ( V_113 , L_14 ,
& V_54 -> V_107 ) )
V_54 -> V_107 = V_115 ;
if ( F_33 ( V_113 , L_15 ,
& V_54 -> V_108 ) )
V_54 -> V_108 = V_116 ;
if ( F_33 ( V_113 , L_16 ,
& V_54 -> V_109 ) )
V_54 -> V_109 = V_117 ;
if ( F_33 ( V_113 , L_17 ,
& V_54 -> V_110 ) )
V_54 -> V_110 = V_118 ;
if ( F_33 ( V_113 , L_18 ,
& V_54 -> V_111 ) )
V_54 -> V_111 =
V_119 ;
return 0 ;
}
static int F_32 ( struct V_68 * V_69 , struct V_53 * V_54 )
{
return 0 ;
}
static int F_34 ( struct V_120 * V_121 )
{
struct V_53 * V_54 ;
struct V_122 V_123 = {} ;
struct V_124 * V_55 = F_11 ( V_121 -> V_69 . V_125 ) ;
int V_3 ;
V_54 = F_35 ( & V_121 -> V_69 , sizeof( * V_54 ) , V_126 ) ;
if ( ! V_54 )
return - V_127 ;
F_36 ( V_121 , V_54 ) ;
V_54 -> V_69 = & V_121 -> V_69 ;
V_54 -> V_55 = V_55 ;
V_3 = F_32 ( & V_121 -> V_69 , V_54 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_31 ( V_54 ) ;
if ( V_3 )
return V_3 ;
V_123 . V_128 = V_54 ;
V_3 = F_37 ( & V_121 -> V_69 , & V_129 ) ;
if ( V_3 ) {
F_25 ( & V_121 -> V_69 , L_19 ) ;
goto V_130;
}
V_3 = F_37 ( & V_121 -> V_69 ,
& V_131 ) ;
if ( V_3 ) {
F_25 ( & V_121 -> V_69 , L_20 ) ;
goto V_130;
}
V_3 = F_37 ( & V_121 -> V_69 , & V_132 ) ;
if ( V_3 ) {
F_25 ( & V_121 -> V_69 , L_21 ) ;
goto V_130;
}
V_54 -> V_133 = F_38 ( & V_121 -> V_69 ,
& V_134 ,
& V_123 ) ;
if ( F_39 ( V_54 -> V_133 ) ) {
F_25 ( & V_121 -> V_69 , L_22 ) ;
V_3 = F_40 ( V_54 -> V_133 ) ;
goto V_130;
}
return 0 ;
V_130:
F_41 ( & V_121 -> V_69 , & V_132 ) ;
F_41 ( & V_121 -> V_69 , & V_131 ) ;
F_41 ( & V_121 -> V_69 , & V_129 ) ;
return V_3 ;
}
static int F_42 ( struct V_120 * V_121 )
{
struct V_53 * V_54 = F_43 ( V_121 ) ;
F_41 ( & V_121 -> V_69 , & V_132 ) ;
F_41 ( & V_121 -> V_69 , & V_131 ) ;
F_41 ( & V_121 -> V_69 , & V_129 ) ;
F_44 ( V_54 -> V_133 ) ;
return 0 ;
}
