static int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
unsigned int V_3 ;
if ( F_2 ( V_1 , V_4 , & V_3 ) < 0 )
return V_5 ;
V_3 &= V_6 ;
V_3 >>= V_7 ;
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_2 = V_13 ;
break;
case V_14 :
V_2 = V_15 ;
break;
case V_16 :
case V_17 :
V_2 = V_18 ;
break;
case V_19 :
case V_20 :
case V_21 :
V_2 = V_22 ;
break;
case V_23 :
default:
V_2 = V_5 ;
}
return V_2 ;
}
static int F_3 ( struct V_1 * V_1 )
{
int V_2 ;
unsigned int V_3 ;
if ( F_2 ( V_1 , V_4 , & V_3 ) < 0 )
return V_24 ;
V_3 &= V_6 ;
V_3 >>= V_7 ;
switch ( V_3 ) {
case V_8 :
case V_11 :
V_2 = V_25 ;
break;
case V_9 :
case V_10 :
case V_12 :
V_2 = V_26 ;
break;
case V_14 :
case V_16 :
case V_17 :
case V_19 :
case V_20 :
case V_21 :
V_2 = V_27 ;
break;
case V_23 :
default:
V_2 = V_24 ;
}
return V_2 ;
}
static int F_4 ( struct V_1 * V_1 )
{
int V_2 ;
unsigned int V_3 ;
if ( F_2 ( V_1 , V_4 , & V_3 ) < 0 )
return V_28 ;
V_3 &= V_29 ;
V_3 >>= V_30 ;
switch ( V_3 ) {
case V_31 :
V_2 = V_32 ;
break;
case V_33 :
case V_34 :
case V_35 :
V_2 = V_36 ;
break;
case V_37 :
V_2 = V_38 ;
break;
case V_39 :
V_2 = V_40 ;
break;
case V_41 :
V_2 = V_42 ;
break;
case V_43 :
default:
V_2 = V_28 ;
break;
}
return V_2 ;
}
static int F_5 ( struct V_1 * V_1 )
{
unsigned int V_3 ;
F_2 ( V_1 , V_44 , & V_3 ) ;
if ( V_3 & V_45 )
return 0 ;
return 1 ;
}
static int F_6 ( struct V_1 * V_1 )
{
unsigned int V_3 ;
F_2 ( V_1 , V_44 , & V_3 ) ;
if ( V_3 & V_46 )
return 1 ;
return 0 ;
}
static int F_7 ( struct V_47 * V_48 ,
enum V_49 V_50 ,
union V_51 * V_52 )
{
struct V_53 * V_54 = F_8 ( V_48 ,
struct V_53 ,
V_55 ) ;
struct V_1 * V_1 = V_54 -> V_56 -> V_1 ;
int V_57 = 0 ;
switch ( V_50 ) {
case V_58 :
V_52 -> V_59 = F_1 ( V_1 ) ;
break;
case V_60 :
V_52 -> V_59 = F_3 ( V_1 ) ;
break;
case V_61 :
V_52 -> V_59 = F_4 ( V_1 ) ;
break;
case V_62 :
V_52 -> V_59 = F_5 ( V_1 ) ;
break;
case V_63 :
V_52 -> V_59 = F_6 ( V_1 ) ;
break;
case V_64 :
V_52 -> V_65 = V_66 ;
break;
case V_67 :
V_52 -> V_65 = V_68 ;
break;
default:
return - V_69 ;
}
return V_57 ;
}
static T_1 F_9 ( struct V_70 * V_71 ,
struct V_72 * V_73 , const char * V_74 , T_2 V_75 ,
int (* F_10)( struct V_53 * , unsigned long ) )
{
struct V_53 * V_54 = F_11 ( V_71 ) ;
unsigned long V_52 ;
int V_57 ;
V_57 = F_12 ( V_74 , 10 , & V_52 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_10 ( V_54 , V_52 ) ;
if ( V_57 )
return V_57 ;
return V_75 ;
}
static T_1 F_13 ( struct V_70 * V_71 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_53 * V_54 = F_11 ( V_71 ) ;
unsigned int V_3 , V_52 ;
int V_57 ;
V_57 = F_2 ( V_54 -> V_56 -> V_1 , V_76 ,
& V_3 ) ;
if ( V_57 < 0 )
return V_57 ;
V_3 &= V_77 ;
V_3 >>= V_78 ;
switch ( V_3 ) {
case 0x1 ... 0x7 :
V_52 = 4 + ( V_3 - 1 ) * 2 ;
break;
case 0x0 :
default:
V_52 = 0 ;
break;
}
return F_14 ( V_74 , V_79 , L_1 , V_52 ) ;
}
static int F_15 ( struct V_53 * V_54 ,
unsigned long V_80 )
{
unsigned int V_3 ;
switch ( V_80 ) {
case 4 ... 16 :
V_3 = ( V_80 - 4 ) / 2 + 1 ;
break;
case 0 :
V_3 = 0 ;
break;
default:
return - V_69 ;
}
V_3 <<= V_78 ;
return F_16 ( V_54 -> V_56 -> V_1 ,
V_76 ,
V_77 , V_3 ) ;
}
static T_1 F_17 ( struct V_70 * V_71 ,
struct V_72 * V_73 , const char * V_74 , T_2 V_75 )
{
return F_9 ( V_71 , V_73 , V_74 , V_75 ,
F_15 ) ;
}
static T_1 F_18 ( struct V_70 * V_71 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_53 * V_54 = F_11 ( V_71 ) ;
unsigned int V_3 , V_52 ;
int V_57 ;
V_57 = F_2 ( V_54 -> V_56 -> V_1 , V_81 ,
& V_3 ) ;
if ( V_57 < 0 )
return V_57 ;
V_3 &= V_82 ;
V_3 >>= V_83 ;
if ( V_3 <= 0x04 )
V_52 = 100000 + V_3 * 25000 ;
else
V_52 = V_3 * 50000 ;
return F_14 ( V_74 , V_79 , L_1 , V_52 ) ;
}
static int F_19 ( struct V_53 * V_54 ,
unsigned long V_84 )
{
unsigned int V_3 ;
if ( V_84 < 100000 || V_84 > 350000 )
return - V_69 ;
if ( V_84 <= 200000 )
V_3 = ( V_84 - 100000 ) / 25000 ;
else
V_3 = V_84 / 50000 ;
V_3 <<= V_83 ;
return F_16 ( V_54 -> V_56 -> V_1 ,
V_81 ,
V_82 , V_3 ) ;
}
static T_1 F_20 ( struct V_70 * V_71 ,
struct V_72 * V_73 , const char * V_74 , T_2 V_75 )
{
return F_9 ( V_71 , V_73 , V_74 , V_75 ,
F_19 ) ;
}
static T_1 F_21 ( struct V_70 * V_71 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_53 * V_54 = F_11 ( V_71 ) ;
unsigned int V_3 , V_52 ;
int V_57 ;
V_57 = F_2 ( V_54 -> V_56 -> V_1 , V_81 ,
& V_3 ) ;
if ( V_57 < 0 )
return V_57 ;
V_3 &= V_85 ;
V_3 >>= V_86 ;
V_52 = V_3 * 10 ;
return F_14 ( V_74 , V_79 , L_1 , V_52 ) ;
}
static int F_22 ( struct V_53 * V_54 ,
unsigned long V_87 )
{
unsigned int V_3 ;
if ( V_87 > 70 )
return - V_69 ;
V_3 = V_87 / 10 ;
V_3 <<= V_86 ;
return F_16 ( V_54 -> V_56 -> V_1 ,
V_81 ,
V_85 , V_3 ) ;
}
static T_1 F_23 ( struct V_70 * V_71 ,
struct V_72 * V_73 , const char * V_74 , T_2 V_75 )
{
return F_9 ( V_71 , V_73 , V_74 , V_75 ,
F_22 ) ;
}
static int F_24 ( struct V_53 * V_54 ,
unsigned int V_88 )
{
unsigned int V_3 ;
if ( V_88 >= 3650000 && V_88 < 4340000 )
V_3 = ( V_88 - 3650000 ) / 25000 ;
else if ( V_88 >= 4340000 && V_88 < 4350000 )
V_3 = 0x1c ;
else if ( V_88 >= 4350000 && V_88 <= 4400000 )
V_3 = 0x1d + ( V_88 - 4350000 ) / 25000 ;
else {
F_25 ( V_54 -> V_71 , L_2 ) ;
return - V_69 ;
}
V_3 <<= V_89 ;
F_26 ( V_54 -> V_71 , L_3 , V_88 ,
V_3 ) ;
return F_16 ( V_54 -> V_56 -> V_1 ,
V_90 ,
V_91 , V_3 ) ;
}
static int F_27 ( struct V_53 * V_54 ,
unsigned int V_88 )
{
unsigned int V_3 ;
if ( V_88 < 3000000 || V_88 > 3700000 ) {
F_25 ( V_54 -> V_71 , L_4 ) ;
return - V_69 ;
}
V_3 = ( V_88 - 3000000 ) / 100000 ;
V_3 <<= V_92 ;
F_26 ( V_54 -> V_71 , L_5 ,
V_88 , V_3 ) ;
return F_16 ( V_54 -> V_56 -> V_1 ,
V_90 ,
V_93 , V_3 ) ;
}
static int F_28 ( struct V_53 * V_54 ,
unsigned int V_94 )
{
unsigned int V_3 ;
switch ( V_94 ) {
case 70 :
case 85 :
case 100 :
case 115 :
V_3 = ( V_94 - 70 ) / 15 ;
break;
default:
F_25 ( V_54 -> V_71 , L_6 ) ;
return - V_69 ;
}
V_3 <<= V_95 ;
F_26 ( V_54 -> V_71 , L_7 ,
V_94 , V_3 ) ;
return F_16 ( V_54 -> V_56 -> V_1 ,
V_96 ,
V_97 , V_3 ) ;
}
static int F_29 ( struct V_53 * V_54 ,
unsigned int V_84 )
{
unsigned int V_3 ;
if ( V_84 && ( V_84 < 2000000 || V_84 > 3500000 ) ) {
F_25 ( V_54 -> V_71 , L_8 ) ;
return - V_69 ;
}
if ( V_84 )
V_3 = ( ( V_84 - 2000000 ) / 250000 ) + 1 ;
else
V_3 = 0 ;
V_3 <<= V_98 ;
F_26 ( V_54 -> V_71 , L_9 , V_84 , V_3 ) ;
return F_16 ( V_54 -> V_56 -> V_1 ,
V_99 ,
V_100 , V_3 ) ;
}
static int F_30 ( struct V_53 * V_54 ,
unsigned int V_88 )
{
unsigned int V_3 ;
switch ( V_88 ) {
case 4300000 :
V_3 = 0x0 ;
break;
case 4700000 :
case 4800000 :
case 4900000 :
V_3 = ( V_88 - 4700000 ) / 100000 ;
default:
F_25 ( V_54 -> V_71 , L_10 ) ;
return - V_69 ;
}
V_3 <<= V_101 ;
F_26 ( V_54 -> V_71 , L_11 ,
V_88 , V_3 ) ;
return F_16 ( V_54 -> V_56 -> V_1 ,
V_99 ,
V_102 , V_3 ) ;
}
static int F_31 ( struct V_53 * V_54 )
{
int V_57 ;
unsigned int V_3 ;
V_3 = ( 0x3 << V_103 ) ;
V_57 = F_16 ( V_54 -> V_56 -> V_1 ,
V_104 ,
V_105 , V_3 ) ;
if ( V_57 ) {
F_25 ( V_54 -> V_71 , L_12 , V_57 ) ;
return V_57 ;
}
V_57 = F_15 ( V_54 , V_106 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_19 ( V_54 ,
V_107 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_22 ( V_54 , V_108 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_24 ( V_54 , V_54 -> V_109 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_27 ( V_54 , V_54 -> V_110 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_28 ( V_54 ,
V_54 -> V_111 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_29 ( V_54 , V_54 -> V_112 ) ;
if ( V_57 )
return V_57 ;
return F_30 ( V_54 ,
V_54 -> V_113 ) ;
}
static int F_32 ( struct V_70 * V_71 , struct V_53 * V_54 )
{
struct V_114 * V_115 = V_71 -> V_116 ;
if ( ! V_115 ) {
F_25 ( V_71 , L_13 ) ;
return - V_69 ;
}
if ( F_33 ( V_115 , L_14 ,
& V_54 -> V_109 ) )
V_54 -> V_109 = V_117 ;
if ( F_33 ( V_115 , L_15 ,
& V_54 -> V_110 ) )
V_54 -> V_110 = V_118 ;
if ( F_33 ( V_115 , L_16 ,
& V_54 -> V_111 ) )
V_54 -> V_111 = V_119 ;
if ( F_33 ( V_115 , L_17 ,
& V_54 -> V_112 ) )
V_54 -> V_112 = V_120 ;
if ( F_33 ( V_115 , L_18 ,
& V_54 -> V_113 ) )
V_54 -> V_113 =
V_121 ;
return 0 ;
}
static int F_32 ( struct V_70 * V_71 , struct V_53 * V_54 )
{
return 0 ;
}
static int F_34 ( struct V_122 * V_123 )
{
struct V_53 * V_54 ;
struct V_124 * V_56 = F_11 ( V_123 -> V_71 . V_125 ) ;
int V_57 ;
V_54 = F_35 ( & V_123 -> V_71 , sizeof( * V_54 ) , V_126 ) ;
if ( ! V_54 )
return - V_127 ;
F_36 ( V_123 , V_54 ) ;
V_54 -> V_71 = & V_123 -> V_71 ;
V_54 -> V_56 = V_56 ;
V_57 = F_32 ( & V_123 -> V_71 , V_54 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_31 ( V_54 ) ;
if ( V_57 )
return V_57 ;
V_54 -> V_55 . V_128 = V_129 ;
V_54 -> V_55 . type = V_130 ;
V_54 -> V_55 . V_131 = V_132 ;
V_54 -> V_55 . V_133 = F_37 ( V_132 ) ;
V_54 -> V_55 . V_134 = F_7 ;
V_57 = F_38 ( & V_123 -> V_71 , & V_135 ) ;
if ( V_57 ) {
F_25 ( & V_123 -> V_71 , L_19 ) ;
goto V_136;
}
V_57 = F_38 ( & V_123 -> V_71 ,
& V_137 ) ;
if ( V_57 ) {
F_25 ( & V_123 -> V_71 , L_20 ) ;
goto V_136;
}
V_57 = F_38 ( & V_123 -> V_71 , & V_138 ) ;
if ( V_57 ) {
F_25 ( & V_123 -> V_71 , L_21 ) ;
goto V_136;
}
V_57 = F_39 ( & V_123 -> V_71 , & V_54 -> V_55 ) ;
if ( V_57 ) {
F_25 ( & V_123 -> V_71 , L_22 ) ;
goto V_136;
}
return 0 ;
V_136:
F_40 ( & V_123 -> V_71 , & V_138 ) ;
F_40 ( & V_123 -> V_71 , & V_137 ) ;
F_40 ( & V_123 -> V_71 , & V_135 ) ;
return V_57 ;
}
static int F_41 ( struct V_122 * V_123 )
{
struct V_53 * V_54 = F_42 ( V_123 ) ;
F_40 ( & V_123 -> V_71 , & V_138 ) ;
F_40 ( & V_123 -> V_71 , & V_137 ) ;
F_40 ( & V_123 -> V_71 , & V_135 ) ;
F_43 ( & V_54 -> V_55 ) ;
return 0 ;
}
