static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 150 ;
while ( V_3 -- > 0 ) {
int V_4 = F_2 ( V_2 -> V_5 ,
V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( V_4 & V_7 ) == V_7 )
return 0 ;
F_3 ( 20 ) ;
}
F_4 ( & V_2 -> V_5 -> V_8 , L_1 ) ;
return - V_9 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_10 [ 3 ] )
{
int V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_6 ( V_2 -> V_5 , V_11 ,
3 * sizeof( T_1 ) , ( V_12 * ) V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return ( V_2 -> V_13 & V_14 ) >>
V_15 ;
}
static T_2 F_8 ( struct V_16 * V_8 ,
struct V_17 * V_18 ,
char * V_10 )
{
return F_9 ( V_10 , V_19 ,
F_10 ( V_19 ) ) ;
}
static T_2 F_11 ( struct V_16 * V_8 ,
struct V_17 * V_18 ,
char * V_10 )
{
struct V_1 * V_2 = F_12 ( F_13 (
F_14 ( V_8 ) ) ) ;
return F_9 ( V_10 , V_2 -> V_20 -> V_21 ,
F_10 ( V_2 -> V_20 -> V_21 ) ) ;
}
static T_2 F_15 ( struct V_16 * V_8 ,
struct V_17 * V_18 ,
char * V_10 )
{
struct V_22 * V_23 = F_16 ( V_8 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
int V_24 = F_7 ( V_2 ) ;
return F_9 ( V_10 , V_25 [ V_24 ] ,
F_10 ( V_25 [ 0 ] ) ) ;
}
static int F_17 ( struct V_1 * V_2 ,
int V_26 , int V_27 )
{
return F_18 ( V_19 ,
F_10 ( V_19 ) ,
V_26 , V_27 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_26 , int V_27 )
{
return F_18 ( V_2 -> V_20 -> V_21 ,
F_10 ( V_2 -> V_20 -> V_21 ) , V_26 , V_27 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
int V_26 , int V_27 )
{
int V_24 = F_7 ( V_2 ) ;
return F_18 ( V_25 [ V_24 ] ,
F_10 ( V_25 [ 0 ] ) , V_26 , V_27 ) ;
}
static int F_21 ( struct V_1 * V_2 , int * V_28 , int * V_29 )
{
int V_24 , V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_30 ) ;
if ( V_4 < 0 )
return V_4 ;
V_24 = F_7 ( V_2 ) ;
V_4 &= V_31 ;
* V_28 = V_25 [ V_24 ] [ V_4 ] [ 0 ] ;
* V_29 = V_25 [ V_24 ] [ V_4 ] [ 1 ] ;
return 0 ;
}
static int F_22 ( struct V_22 * V_23 ,
struct V_32 const * V_33 ,
int * V_26 , int * V_27 , long V_34 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
T_1 V_35 [ 3 ] ;
int V_24 , V_4 ;
switch ( V_34 ) {
case V_36 :
if ( F_23 ( V_23 ) )
return - V_37 ;
F_24 ( & V_2 -> V_38 ) ;
V_4 = F_5 ( V_2 , V_35 ) ;
F_25 ( & V_2 -> V_38 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_26 = F_26 ( F_27 (
V_35 [ V_33 -> V_39 ] ) >> V_33 -> V_40 . V_41 ,
V_33 -> V_40 . V_42 - 1 ) ;
return V_43 ;
case V_44 :
V_24 = V_2 -> V_45 & V_46 ;
* V_26 = V_2 -> V_20 -> V_21 [ V_24 ] [ 0 ] ;
* V_27 = V_2 -> V_20 -> V_21 [ V_24 ] [ 1 ] ;
return V_47 ;
case V_48 :
V_24 = F_7 ( V_2 ) ;
* V_26 = V_19 [ V_24 ] [ 0 ] ;
* V_27 = V_19 [ V_24 ] [ 1 ] ;
return V_47 ;
case V_49 :
V_4 = F_2 ( V_2 -> V_5 ,
V_50 + V_33 -> V_39 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_26 = F_26 ( V_4 , 7 ) ;
return V_43 ;
case V_51 :
if ( V_2 -> V_45 & V_52 ) {
V_4 = F_21 ( V_2 , V_26 , V_27 ) ;
if ( V_4 < 0 )
return V_4 ;
} else {
* V_26 = 0 ;
* V_27 = 0 ;
}
return V_47 ;
}
return - V_53 ;
}
static int F_28 ( struct V_1 * V_2 )
{
return F_29 ( V_2 -> V_5 , V_54 ,
V_2 -> V_13 & ~ V_55 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
return F_29 ( V_2 -> V_5 , V_54 ,
V_2 -> V_13 ) ;
}
static int F_31 ( struct V_1 * V_2 , V_12 V_56 , V_12 V_26 )
{
int V_4 ;
F_24 ( & V_2 -> V_38 ) ;
V_4 = F_28 ( V_2 ) ;
if ( V_4 < 0 )
goto V_57;
V_4 = F_29 ( V_2 -> V_5 , V_56 , V_26 ) ;
if ( V_4 < 0 )
goto V_57;
V_4 = F_30 ( V_2 ) ;
if ( V_4 < 0 )
goto V_57;
V_4 = 0 ;
V_57:
F_25 ( & V_2 -> V_38 ) ;
return V_4 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_26 ;
const struct V_58 * V_59 = V_2 -> V_20 ;
V_26 = F_2 ( V_2 -> V_5 , V_59 -> V_60 ) ;
if ( V_26 < 0 )
return V_26 ;
return ! ( V_26 & V_61 ) ;
}
static int F_33 ( struct V_1 * V_2 , bool V_62 )
{
int V_26 ;
const struct V_58 * V_59 = V_2 -> V_20 ;
if ( ( V_62 && F_32 ( V_2 ) ) ||
( ! V_62 && ! ( F_32 ( V_2 ) ) ) )
return 0 ;
V_26 = F_2 ( V_2 -> V_5 , V_59 -> V_60 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_62 ) {
V_26 |= F_34 ( V_63 + V_59 -> V_64 ) ;
V_26 |= F_34 ( V_65 + V_59 -> V_64 ) ;
V_26 |= F_34 ( V_66 + V_59 -> V_64 ) ;
V_26 &= ~ V_61 ;
} else {
V_26 &= ~ F_34 ( V_63 + V_59 -> V_64 ) ;
V_26 &= ~ F_34 ( V_65 + V_59 -> V_64 ) ;
V_26 &= ~ F_34 ( V_66 + V_59 -> V_64 ) ;
V_26 |= V_61 ;
}
V_26 = F_31 ( V_2 , V_59 -> V_60 , V_26 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
int V_26 , int V_27 )
{
int V_24 , V_56 ;
V_24 = F_20 ( V_2 , V_26 , V_27 ) ;
if ( V_24 < 0 )
return V_24 ;
V_56 = F_2 ( V_2 -> V_5 ,
V_30 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 &= ~ V_31 ;
V_56 |= V_24 ;
return F_31 ( V_2 , V_30 , V_56 ) ;
}
static int F_36 ( struct V_22 * V_23 ,
struct V_32 const * V_33 ,
int V_26 , int V_27 , long V_34 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
int V_24 , V_4 ;
if ( F_23 ( V_23 ) )
return - V_37 ;
switch ( V_34 ) {
case V_48 :
V_24 = F_17 ( V_2 , V_26 , V_27 ) ;
if ( V_24 < 0 )
return V_24 ;
V_2 -> V_13 &= ~ V_14 ;
V_2 -> V_13 |= V_24 << V_15 ;
return F_31 ( V_2 , V_54 ,
V_2 -> V_13 ) ;
case V_44 :
V_24 = F_19 ( V_2 , V_26 , V_27 ) ;
if ( V_24 < 0 )
return V_24 ;
V_2 -> V_45 &= ~ V_46 ;
V_2 -> V_45 |= V_24 ;
return F_31 ( V_2 , V_67 ,
V_2 -> V_45 ) ;
case V_49 :
if ( V_26 < - 128 || V_26 > 127 )
return - V_53 ;
return F_31 ( V_2 ,
V_50 + V_33 -> V_39 ,
V_26 ) ;
case V_51 :
if ( V_26 == 0 && V_27 == 0 ) {
V_2 -> V_45 &= ~ V_52 ;
} else {
V_2 -> V_45 |= V_52 ;
V_4 = F_35 ( V_2 , V_26 , V_27 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_31 ( V_2 , V_67 ,
V_2 -> V_45 ) ;
default:
return - V_53 ;
}
}
static int F_37 ( struct V_22 * V_23 ,
const struct V_32 * V_33 ,
enum V_68 type ,
enum V_69 V_70 ,
enum V_71 V_72 ,
int * V_26 , int * V_27 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
int V_4 , V_73 ;
switch ( V_72 ) {
case V_74 :
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_20 -> V_75 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_26 = V_4 & V_2 -> V_20 -> V_76 ;
return V_43 ;
case V_77 :
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_20 -> V_78 ) ;
if ( V_4 < 0 )
return V_4 ;
V_73 = V_4 * V_79 [
F_7 ( V_2 ) ] ;
* V_26 = V_73 / V_80 ;
* V_27 = V_73 % V_80 ;
return V_47 ;
case V_81 :
V_4 = F_2 ( V_2 -> V_5 ,
V_82 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_83 ) {
* V_26 = 0 ;
* V_27 = 0 ;
} else {
V_4 = F_21 ( V_2 , V_26 , V_27 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return V_47 ;
default:
return - V_53 ;
}
}
static int F_38 ( struct V_22 * V_23 ,
const struct V_32 * V_33 ,
enum V_68 type ,
enum V_69 V_70 ,
enum V_71 V_72 ,
int V_26 , int V_27 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
int V_4 , V_56 , V_84 ;
switch ( V_72 ) {
case V_74 :
if ( V_26 < 0 || V_26 > V_85 )
return - V_53 ;
return F_31 ( V_2 , V_2 -> V_20 -> V_75 ,
V_26 ) ;
case V_77 :
V_84 = ( V_26 * V_80 + V_27 ) /
V_79 [
F_7 ( V_2 ) ] ;
if ( V_84 < 0 || V_84 > 0xff )
return - V_53 ;
return F_31 ( V_2 , V_2 -> V_20 -> V_78 ,
V_84 ) ;
case V_81 :
V_56 = F_2 ( V_2 -> V_5 ,
V_82 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_26 == 0 && V_27 == 0 ) {
V_56 |= V_83 ;
} else {
V_56 &= ~ V_83 ;
V_4 = F_35 ( V_2 , V_26 , V_27 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_31 ( V_2 , V_82 , V_56 ) ;
default:
return - V_53 ;
}
}
static int F_39 ( struct V_22 * V_23 ,
const struct V_32 * V_33 ,
enum V_68 type ,
enum V_69 V_70 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
const struct V_58 * V_59 = V_2 -> V_20 ;
int V_4 ;
switch ( V_70 ) {
case V_86 :
return F_32 ( V_2 ) ;
case V_87 :
if ( F_32 ( V_2 ) )
return 0 ;
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_20 -> V_60 ) ;
if ( V_4 < 0 )
return V_4 ;
return ! ! ( V_4 & F_34 ( V_33 -> V_39 + V_59 -> V_64 ) ) ;
default:
return - V_53 ;
}
}
static int F_40 ( struct V_22 * V_23 ,
const struct V_32 * V_33 ,
enum V_68 type ,
enum V_69 V_70 ,
int V_62 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
const struct V_58 * V_59 = V_2 -> V_20 ;
int V_26 ;
switch ( V_70 ) {
case V_86 :
return F_33 ( V_2 , V_62 ) ;
case V_87 :
V_26 = F_2 ( V_2 -> V_5 , V_59 -> V_60 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_62 ) {
if ( F_32 ( V_2 ) ) {
V_26 &= ~ F_34 ( V_63 + V_59 -> V_64 ) ;
V_26 &= ~ F_34 ( V_65 + V_59 -> V_64 ) ;
V_26 &= ~ F_34 ( V_66 + V_59 -> V_64 ) ;
V_26 |= V_61 ;
}
V_26 |= F_34 ( V_33 -> V_39 + V_59 -> V_64 ) ;
} else {
if ( F_32 ( V_2 ) )
return 0 ;
V_26 &= ~ F_34 ( V_33 -> V_39 + V_59 -> V_64 ) ;
}
V_26 |= V_59 -> V_88 ;
return F_31 ( V_2 , V_59 -> V_60 , V_26 ) ;
default:
return - V_53 ;
}
}
static void F_41 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
T_3 V_89 = F_42 () ;
int V_90 ;
V_90 = F_2 ( V_2 -> V_5 , V_2 -> V_20 -> V_91 ) ;
if ( V_90 < 0 )
return;
if ( F_32 ( V_2 ) ) {
F_43 ( V_23 ,
F_44 ( V_92 , 0 ,
V_93 ,
V_94 ,
V_86 ) ,
V_89 ) ;
return;
}
if ( V_90 & V_2 -> V_20 -> V_95 )
F_43 ( V_23 ,
F_44 ( V_92 , 0 , V_96 ,
V_94 ,
V_87 ) ,
V_89 ) ;
if ( V_90 & V_2 -> V_20 -> V_97 )
F_43 ( V_23 ,
F_44 ( V_92 , 0 , V_98 ,
V_94 ,
V_87 ) ,
V_89 ) ;
if ( V_90 & V_2 -> V_20 -> V_99 )
F_43 ( V_23 ,
F_44 ( V_92 , 0 , V_100 ,
V_94 ,
V_87 ) ,
V_89 ) ;
}
static T_4 F_45 ( int V_101 , void * V_102 )
{
struct V_22 * V_23 = V_102 ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
const struct V_58 * V_59 = V_2 -> V_20 ;
int V_4 = V_103 ;
int V_90 ;
V_90 = F_2 ( V_2 -> V_5 , V_104 ) ;
if ( V_90 < 0 )
return V_103 ;
if ( V_90 & V_105 ) {
F_46 ( V_23 -> V_106 ) ;
V_4 = V_107 ;
}
if ( ( V_90 & V_108 &&
V_59 -> V_91 == V_109 ) ||
( V_90 & V_110 &&
V_59 -> V_91 == V_111 ) ) {
F_41 ( V_23 ) ;
V_4 = V_107 ;
}
return V_4 ;
}
static T_4 F_47 ( int V_101 , void * V_102 )
{
struct V_112 * V_113 = V_102 ;
struct V_22 * V_23 = V_113 -> V_23 ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
V_12 V_35 [ 16 ] ;
int V_4 ;
V_4 = F_5 ( V_2 , ( T_1 * ) V_35 ) ;
if ( V_4 < 0 )
goto V_114;
F_48 ( V_23 , V_35 ,
F_42 () ) ;
V_114:
F_49 ( V_23 -> V_106 ) ;
return V_107 ;
}
static int F_50 ( struct V_22 * V_23 ,
unsigned V_56 , unsigned V_115 ,
unsigned * V_116 )
{
int V_4 ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
if ( V_56 > V_117 )
return - V_53 ;
if ( ! V_116 )
return F_31 ( V_2 , V_56 , V_115 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_56 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_116 = V_4 ;
return 0 ;
}
static int F_51 ( struct V_118 * V_106 ,
bool V_62 )
{
struct V_22 * V_23 = F_52 ( V_106 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
int V_56 ;
V_56 = F_2 ( V_2 -> V_5 , V_119 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_62 )
V_56 |= V_105 ;
else
V_56 &= ~ V_105 ;
return F_31 ( V_2 , V_119 , V_56 ) ;
}
static int F_53 ( struct V_118 * V_106 ,
struct V_22 * V_23 )
{
struct V_22 * V_120 = F_52 ( V_106 ) ;
if ( V_120 != V_23 )
return - V_53 ;
return 0 ;
}
static int F_54 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
struct V_118 * V_106 ;
int V_4 ;
V_106 = F_55 ( & V_2 -> V_5 -> V_8 , L_2 ,
V_23 -> V_121 ,
V_23 -> V_122 ) ;
if ( ! V_106 )
return - V_123 ;
V_106 -> V_8 . V_124 = & V_2 -> V_5 -> V_8 ;
V_106 -> V_125 = & V_126 ;
F_56 ( V_106 , V_23 ) ;
V_4 = F_57 ( V_106 ) ;
if ( V_4 )
return V_4 ;
V_23 -> V_106 = V_106 ;
return 0 ;
}
static void F_58 ( struct V_22 * V_23 )
{
if ( V_23 -> V_106 )
F_59 ( V_23 -> V_106 ) ;
}
static int F_60 ( struct V_127 * V_5 )
{
int V_24 ;
int V_4 ;
V_4 = F_29 ( V_5 , V_128 ,
V_129 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_24 = 0 ; V_24 < 10 ; V_24 ++ ) {
F_61 ( 100 , 200 ) ;
V_4 = F_2 ( V_5 , V_128 ) ;
if ( V_4 == - V_9 )
continue;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_4 & V_129 ) )
return 0 ;
}
return - V_130 ;
}
static int F_62 ( struct V_127 * V_5 ,
const struct V_131 * V_122 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 ;
int V_4 ;
const struct V_132 * V_133 ;
V_133 = F_63 ( V_134 , & V_5 -> V_8 ) ;
if ( ! V_133 ) {
F_4 ( & V_5 -> V_8 , L_3 ) ;
return - V_135 ;
}
V_23 = F_64 ( & V_5 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_23 )
return - V_123 ;
V_2 = F_12 ( V_23 ) ;
V_2 -> V_5 = V_5 ;
F_65 ( & V_2 -> V_38 ) ;
V_2 -> V_20 = V_133 -> V_2 ;
V_4 = F_2 ( V_5 , V_136 ) ;
if ( V_4 < 0 )
return V_4 ;
switch ( V_4 ) {
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
if ( V_4 == V_2 -> V_20 -> V_142 )
break;
default:
return - V_135 ;
}
F_66 ( & V_5 -> V_8 , L_4 ,
V_133 -> V_143 , V_2 -> V_20 -> V_142 ) ;
F_67 ( V_5 , V_23 ) ;
V_23 -> V_72 = & V_144 ;
V_23 -> V_121 = V_122 -> V_121 ;
V_23 -> V_8 . V_124 = & V_5 -> V_8 ;
V_23 -> V_145 = V_146 ;
V_23 -> V_147 = V_2 -> V_20 -> V_147 ;
V_23 -> V_148 = V_2 -> V_20 -> V_148 ;
V_23 -> V_149 = V_150 ;
V_4 = F_60 ( V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_45 = V_151 ;
V_4 = F_29 ( V_5 , V_67 ,
V_2 -> V_45 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_29 ( V_5 , V_152 ,
V_85 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_5 -> V_101 ) {
int V_153 = V_105 |
V_108 |
V_110 ;
int V_154 = V_108 |
V_110 ;
int V_155 ;
V_155 = F_68 ( V_5 -> V_8 . V_156 , L_5 ) ;
if ( V_155 == V_5 -> V_101 ) {
F_69 ( & V_5 -> V_8 , L_6 ) ;
} else {
V_4 = F_29 ( V_5 ,
V_157 ,
V_153 ) ;
if ( V_4 < 0 )
return V_4 ;
F_69 ( & V_5 -> V_8 , L_7 ) ;
}
V_4 = F_29 ( V_5 ,
V_119 ,
V_154 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_54 ( V_23 ) ;
if ( V_4 < 0 )
return V_4 ;
}
V_2 -> V_13 = V_55 |
( V_158 << V_15 ) ;
V_4 = F_29 ( V_5 , V_54 ,
V_2 -> V_13 ) ;
if ( V_4 < 0 )
goto V_159;
V_4 = F_70 ( V_23 , NULL ,
F_47 , NULL ) ;
if ( V_4 < 0 )
goto V_159;
if ( V_5 -> V_101 ) {
V_4 = F_71 ( & V_5 -> V_8 ,
V_5 -> V_101 ,
NULL , F_45 ,
V_160 | V_161 ,
V_5 -> V_121 , V_23 ) ;
if ( V_4 )
goto V_162;
}
V_4 = F_72 ( V_23 ) ;
if ( V_4 < 0 )
goto V_162;
V_4 = F_33 ( V_2 , false ) ;
if ( V_4 )
return V_4 ;
return 0 ;
V_162:
F_73 ( V_23 ) ;
V_159:
F_58 ( V_23 ) ;
return V_4 ;
}
static int F_74 ( struct V_127 * V_5 )
{
struct V_22 * V_23 = F_13 ( V_5 ) ;
F_75 ( V_23 ) ;
F_73 ( V_23 ) ;
F_58 ( V_23 ) ;
F_28 ( F_12 ( V_23 ) ) ;
return 0 ;
}
static int F_76 ( struct V_16 * V_8 )
{
return F_28 ( F_12 ( F_13 (
F_14 ( V_8 ) ) ) ) ;
}
static int F_77 ( struct V_16 * V_8 )
{
return F_30 ( F_12 ( F_13 (
F_14 ( V_8 ) ) ) ) ;
}
