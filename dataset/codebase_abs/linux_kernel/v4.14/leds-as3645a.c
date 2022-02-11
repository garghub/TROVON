static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_6 , V_3 , V_4 ) ;
F_3 ( & V_6 -> V_8 , L_1 , V_3 , V_4 ,
V_7 < 0 ? L_2 : L_3 ) ;
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
V_7 = F_5 ( V_6 , V_3 ) ;
F_3 ( & V_6 -> V_8 , L_4 , V_3 , V_7 ,
V_7 < 0 ? L_2 : L_3 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = ( V_2 -> V_9 << V_10 )
| ( V_2 -> V_11 << V_12 )
| V_13 ;
return F_1 ( V_2 , V_14 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = V_2 -> V_15 << V_16 ;
V_4 |= ( V_2 -> V_17 . V_18
<< V_19 )
| ( ( V_2 -> V_20 ? V_2 -> V_20 - 1 : 0 )
<< V_21 ) ;
return F_1 ( V_2 , V_22 , V_4 ) ;
}
static int
F_8 ( struct V_1 * V_2 , enum V_23 V_24 , bool V_25 )
{
T_1 V_26 ;
V_26 = ( V_2 -> V_17 . V_27 << V_28 )
| ( V_25 ? V_29 : 0 )
| V_24 ;
if ( V_24 == V_30 &&
V_2 -> V_31 == V_32 )
V_26 |= V_33
| V_34 ;
return F_1 ( V_2 , V_35 , V_26 ) ;
}
static int F_9 ( struct V_36 * V_37 , T_2 * V_38 )
{
struct V_1 * V_2 = F_10 ( V_37 ) ;
int V_7 ;
V_7 = F_4 ( V_2 , V_39 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 & V_40 )
* V_38 |= V_41 ;
if ( V_7 & V_42 )
* V_38 |= V_43 ;
F_3 ( & V_2 -> V_6 -> V_8 , L_5 ,
V_7 & V_44 ? 2 : 1 ) ;
if ( V_7 & V_45 )
* V_38 |= V_46 ;
if ( V_7 & V_47 )
* V_38 |= V_48 ;
if ( V_7 & V_49 )
* V_38 |= V_41 ;
if ( V_7 & V_50 )
* V_38 |= V_51 ;
return V_7 ;
}
static unsigned int F_11 ( unsigned int V_52 , unsigned int V_53 ,
unsigned int V_54 ,
unsigned int V_4 )
{
if ( V_4 < V_52 )
V_4 = V_52 ;
if ( V_4 > V_53 )
V_4 = V_53 ;
return ( V_4 - V_52 ) / V_54 ;
}
static unsigned int F_12 ( struct V_1 * V_2 , bool V_55 ,
unsigned int V_56 )
{
if ( V_55 )
return F_11 ( V_57 ,
V_2 -> V_17 . V_58 ,
V_59 , V_56 ) ;
else
return F_11 ( V_60 ,
V_2 -> V_17 . V_61 ,
V_62 , V_56 ) ;
}
static int F_13 ( struct V_63 * V_64 ,
enum V_65 V_66 )
{
struct V_1 * V_2 = F_14 ( V_64 ) ;
int V_7 ;
V_2 -> V_20 = V_66 ;
V_7 = F_7 ( V_2 ) ;
if ( V_7 )
return V_7 ;
return F_8 ( V_2 , V_67 , V_66 ) ;
}
static int F_15 ( struct V_63 * V_68 ,
enum V_65 V_66 )
{
struct V_36 * V_37 = F_16 ( V_68 ) ;
struct V_1 * V_2 = F_10 ( V_37 ) ;
int V_7 ;
if ( V_66 ) {
V_2 -> V_11 = V_66 - 1 ;
V_7 = F_6 ( V_2 ) ;
if ( V_7 )
return V_7 ;
}
return F_8 ( V_2 , V_69 , V_66 ) ;
}
static int F_17 ( struct V_36 * V_37 ,
T_2 V_70 )
{
struct V_1 * V_2 = F_10 ( V_37 ) ;
V_2 -> V_9 = F_12 ( V_2 , true , V_70 ) ;
return F_6 ( V_2 ) ;
}
static int F_18 ( struct V_36 * V_37 ,
T_2 V_71 )
{
struct V_1 * V_2 = F_10 ( V_37 ) ;
V_2 -> V_15 = F_19 ( V_71 ) ;
return F_7 ( V_2 ) ;
}
static int F_20 ( struct V_36 * V_37 , bool V_72 )
{
struct V_1 * V_2 = F_10 ( V_37 ) ;
return F_8 ( V_2 , V_30 , V_72 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_73 * V_8 = & V_2 -> V_6 -> V_8 ;
T_2 V_38 = 0 ;
int V_7 ;
V_7 = F_4 ( V_2 , V_39 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( V_8 , L_6 , V_7 ) ;
V_7 = F_6 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_8 ( V_2 , V_67 , false ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( & V_2 -> V_37 , & V_38 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( V_8 , L_7 ,
F_4 ( V_2 , V_22 ) ) ;
F_3 ( V_8 , L_8 ,
F_4 ( V_2 , V_14 ) ) ;
F_3 ( V_8 , L_9 ,
F_4 ( V_2 , V_35 ) ) ;
return V_7 & ~ V_44 ? - V_74 : 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_73 * V_8 = & V_2 -> V_6 -> V_8 ;
int V_7 , V_75 , V_76 , V_77 , V_78 ;
const char * V_79 ;
V_7 = F_4 ( V_2 , V_80 ) ;
if ( V_7 < 0 ) {
F_23 ( V_8 , L_10 ) ;
return V_7 ;
}
V_75 = F_24 ( V_7 ) ;
V_76 = F_25 ( V_7 ) ;
V_7 = F_4 ( V_2 , V_81 ) ;
if ( V_7 < 0 ) {
F_23 ( V_8 , L_11 ) ;
return V_7 ;
}
V_77 = F_26 ( V_7 ) ;
V_78 = F_27 ( V_7 ) ;
if ( V_76 != 0x01 || V_77 != 0x00 ) {
F_23 ( V_8 , L_12
L_13 , V_76 , V_77 ) ;
return - V_82 ;
}
switch ( V_75 ) {
case 1 :
V_79 = L_14 ;
break;
case 2 :
V_79 = L_15 ;
break;
case 3 :
V_79 = L_16 ;
break;
case 4 :
V_79 = L_17 ;
break;
case 5 :
V_79 = L_18 ;
break;
default:
V_79 = L_19 ;
}
F_28 ( V_8 , L_20 , V_79 ,
V_75 , V_78 ) ;
V_7 = F_1 ( V_2 , V_83 , V_84 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_1 ( V_2 , V_85 , V_86 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_89 * V_90 )
{
struct V_91 * V_17 = & V_2 -> V_17 ;
struct V_89 * V_92 ;
const char * V_93 ;
int V_7 ;
F_30 (node, child) {
T_2 V_94 = 0 ;
F_31 ( V_92 , L_21 , & V_94 ) ;
switch ( V_94 ) {
case V_95 :
V_2 -> V_96 = F_32 ( V_92 ) ;
break;
case V_97 :
V_2 -> V_98 = F_32 ( V_92 ) ;
break;
default:
F_33 ( & V_2 -> V_6 -> V_8 ,
L_22 , V_94 ) ;
break;
}
}
if ( ! V_2 -> V_96 ) {
F_23 ( & V_2 -> V_6 -> V_8 , L_23 ) ;
return - V_82 ;
}
V_7 = F_34 ( V_2 -> V_96 , L_24 , & V_93 ) ;
if ( ! V_7 )
F_35 ( V_88 -> V_2 , V_93 , sizeof( V_88 -> V_2 ) ) ;
else
snprintf ( V_88 -> V_2 , sizeof( V_88 -> V_2 ) ,
L_25 , V_90 -> V_93 ) ;
V_7 = F_31 ( V_2 -> V_96 , L_26 ,
& V_17 -> V_99 ) ;
if ( V_7 < 0 ) {
F_23 ( & V_2 -> V_6 -> V_8 ,
L_27 ) ;
goto V_100;
}
V_7 = F_31 ( V_2 -> V_96 , L_28 ,
& V_17 -> V_61 ) ;
if ( V_7 < 0 ) {
F_23 ( & V_2 -> V_6 -> V_8 ,
L_29 ) ;
goto V_100;
}
V_7 = F_31 ( V_2 -> V_96 , L_30 ,
& V_17 -> V_58 ) ;
if ( V_7 < 0 ) {
F_23 ( & V_2 -> V_6 -> V_8 ,
L_31 ) ;
goto V_100;
}
F_31 ( V_2 -> V_96 , L_32 ,
& V_17 -> V_18 ) ;
F_31 ( V_2 -> V_96 , L_33 ,
& V_17 -> V_27 ) ;
V_17 -> V_27 = F_36 ( V_17 -> V_27 ) ;
if ( ! V_2 -> V_98 ) {
F_33 ( & V_2 -> V_6 -> V_8 ,
L_34 ) ;
goto V_100;
}
V_7 = F_34 ( V_2 -> V_98 , L_24 , & V_93 ) ;
if ( ! V_7 )
F_35 ( V_88 -> V_101 , V_93 , sizeof( V_88 -> V_101 ) ) ;
else
snprintf ( V_88 -> V_101 , sizeof( V_88 -> V_101 ) ,
L_35 , V_90 -> V_93 ) ;
V_7 = F_31 ( V_2 -> V_98 , L_30 ,
& V_17 -> V_102 ) ;
if ( V_7 < 0 ) {
F_23 ( & V_2 -> V_6 -> V_8 ,
L_36 ) ;
goto V_100;
}
return 0 ;
V_100:
F_37 ( V_2 -> V_96 ) ;
F_37 ( V_2 -> V_98 ) ;
return V_7 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
struct V_63 * V_68 = & V_2 -> V_37 . V_103 ;
struct V_63 * V_64 = & V_2 -> V_64 ;
struct V_104 * V_17 ;
int V_7 ;
V_64 -> V_93 = V_88 -> V_101 ;
V_64 -> V_105 = F_13 ;
V_64 -> V_106 =
V_2 -> V_17 . V_102 / V_107 ;
V_64 -> V_108 = V_109 ;
V_7 = F_39 ( & V_2 -> V_6 -> V_8 , V_64 ) ;
if ( V_7 < 0 )
return V_7 ;
V_17 = & V_2 -> V_37 . V_66 ;
V_17 -> V_52 = V_60 ;
V_17 -> V_53 = V_2 -> V_17 . V_61 ;
V_17 -> V_54 = V_62 ;
V_17 -> V_4 = V_2 -> V_17 . V_61 ;
V_17 = & V_2 -> V_37 . V_15 ;
V_17 -> V_52 = V_110 ;
V_17 -> V_53 = V_2 -> V_17 . V_99 ;
V_17 -> V_54 = V_111 ;
V_17 -> V_4 = V_2 -> V_17 . V_99 ;
V_2 -> V_37 . V_112 = & V_113 ;
V_68 -> V_93 = V_88 -> V_2 ;
V_68 -> V_105 = F_15 ;
V_68 -> V_106 =
F_12 ( V_2 , false ,
V_2 -> V_17 . V_58 ) + 1 ;
V_68 -> V_108 = V_114 | V_109 ;
V_7 = F_40 ( & V_2 -> V_6 -> V_8 , & V_2 -> V_37 ) ;
if ( V_7 ) {
F_41 ( V_64 ) ;
F_23 ( & V_2 -> V_6 -> V_8 ,
L_37 ,
V_7 ) ;
}
return V_7 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = & V_2 -> V_37 ;
struct V_63 * V_115 = & V_37 -> V_103 ;
struct V_116 V_17 = {
. V_117 = {
. V_52 = V_57 ,
. V_53 = V_2 -> V_17 . V_58 ,
. V_54 = V_59 ,
. V_4 = V_2 -> V_17 . V_58 ,
} ,
} ;
struct V_116 V_118 = {
. V_117 = {
. V_52 = V_119 ,
. V_53 = V_2 -> V_17 . V_102 ,
. V_54 = V_107 ,
. V_4 = V_2 -> V_17 . V_102 ,
} ,
} ;
F_35 ( V_17 . V_120 , V_115 -> V_93 , sizeof( V_17 . V_120 ) ) ;
F_35 ( V_118 . V_120 , V_2 -> V_64 . V_93 , sizeof( V_17 . V_120 ) ) ;
V_2 -> V_121 = F_43 (
& V_2 -> V_6 -> V_8 , F_44 ( V_2 -> V_96 ) ,
& V_2 -> V_37 , NULL , & V_17 ) ;
if ( F_45 ( V_2 -> V_121 ) )
return F_46 ( V_2 -> V_121 ) ;
V_2 -> V_122 = F_47 (
& V_2 -> V_6 -> V_8 , F_44 ( V_2 -> V_98 ) ,
& V_2 -> V_64 , & V_118 ) ;
if ( F_45 ( V_2 -> V_122 ) ) {
F_48 ( V_2 -> V_121 ) ;
return F_46 ( V_2 -> V_122 ) ;
}
return 0 ;
}
static int F_49 ( struct V_5 * V_6 )
{
struct V_87 V_88 ;
struct V_1 * V_2 ;
int V_7 ;
if ( V_6 -> V_8 . V_123 == NULL )
return - V_82 ;
V_2 = F_50 ( & V_6 -> V_8 , sizeof( * V_2 ) , V_124 ) ;
if ( V_2 == NULL )
return - V_125 ;
V_2 -> V_6 = V_6 ;
V_7 = F_29 ( V_2 , & V_88 , V_6 -> V_8 . V_123 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_22 ( V_2 ) ;
if ( V_7 < 0 )
goto V_126;
F_51 ( & V_2 -> V_127 ) ;
F_52 ( V_6 , V_2 ) ;
V_7 = F_21 ( V_2 ) ;
if ( V_7 )
goto V_128;
V_7 = F_38 ( V_2 , & V_88 ) ;
if ( V_7 )
goto V_128;
V_7 = F_42 ( V_2 ) ;
if ( V_7 )
goto V_129;
return 0 ;
V_129:
F_53 ( & V_2 -> V_37 ) ;
V_128:
F_54 ( & V_2 -> V_127 ) ;
V_126:
F_37 ( V_2 -> V_96 ) ;
F_37 ( V_2 -> V_98 ) ;
return V_7 ;
}
static int F_55 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_56 ( V_6 ) ;
F_8 ( V_2 , V_130 , false ) ;
F_48 ( V_2 -> V_121 ) ;
F_48 ( V_2 -> V_122 ) ;
F_53 ( & V_2 -> V_37 ) ;
F_41 ( & V_2 -> V_64 ) ;
F_54 ( & V_2 -> V_127 ) ;
F_37 ( V_2 -> V_96 ) ;
F_37 ( V_2 -> V_98 ) ;
return 0 ;
}
