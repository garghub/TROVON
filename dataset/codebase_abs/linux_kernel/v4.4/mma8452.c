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
static int F_32 ( struct V_1 * V_2 ,
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
static int F_33 ( struct V_22 * V_23 ,
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
return F_31 ( V_2 , V_58 ,
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
V_4 = F_32 ( V_2 , V_26 , V_27 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_31 ( V_2 , V_58 ,
V_2 -> V_45 ) ;
default:
return - V_53 ;
}
}
static int F_34 ( struct V_22 * V_23 ,
const struct V_32 * V_33 ,
enum V_59 type ,
enum V_60 V_61 ,
enum V_62 V_63 ,
int * V_26 , int * V_27 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
int V_4 , V_64 ;
switch ( V_63 ) {
case V_65 :
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_20 -> V_66 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_26 = V_4 & V_2 -> V_20 -> V_67 ;
return V_43 ;
case V_68 :
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_20 -> V_69 ) ;
if ( V_4 < 0 )
return V_4 ;
V_64 = V_4 * V_70 [
F_7 ( V_2 ) ] ;
* V_26 = V_64 / V_71 ;
* V_27 = V_64 % V_71 ;
return V_47 ;
case V_72 :
V_4 = F_2 ( V_2 -> V_5 ,
V_73 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_74 ) {
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
static int F_35 ( struct V_22 * V_23 ,
const struct V_32 * V_33 ,
enum V_59 type ,
enum V_60 V_61 ,
enum V_62 V_63 ,
int V_26 , int V_27 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
int V_4 , V_56 , V_75 ;
switch ( V_63 ) {
case V_65 :
if ( V_26 < 0 || V_26 > V_76 )
return - V_53 ;
return F_31 ( V_2 , V_2 -> V_20 -> V_66 ,
V_26 ) ;
case V_68 :
V_75 = ( V_26 * V_71 + V_27 ) /
V_70 [
F_7 ( V_2 ) ] ;
if ( V_75 < 0 || V_75 > 0xff )
return - V_53 ;
return F_31 ( V_2 , V_2 -> V_20 -> V_69 ,
V_75 ) ;
case V_72 :
V_56 = F_2 ( V_2 -> V_5 ,
V_73 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_26 == 0 && V_27 == 0 ) {
V_56 |= V_74 ;
} else {
V_56 &= ~ V_74 ;
V_4 = F_32 ( V_2 , V_26 , V_27 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_31 ( V_2 , V_73 , V_56 ) ;
default:
return - V_53 ;
}
}
static int F_36 ( struct V_22 * V_23 ,
const struct V_32 * V_33 ,
enum V_59 type ,
enum V_60 V_61 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
const struct V_77 * V_78 = V_2 -> V_20 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_20 -> V_79 ) ;
if ( V_4 < 0 )
return V_4 ;
return ! ! ( V_4 & F_37 ( V_33 -> V_39 + V_78 -> V_80 ) ) ;
}
static int F_38 ( struct V_22 * V_23 ,
const struct V_32 * V_33 ,
enum V_59 type ,
enum V_60 V_61 ,
int V_81 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
const struct V_77 * V_78 = V_2 -> V_20 ;
int V_26 ;
V_26 = F_2 ( V_2 -> V_5 , V_78 -> V_79 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_81 )
V_26 |= F_37 ( V_33 -> V_39 + V_78 -> V_80 ) ;
else
V_26 &= ~ F_37 ( V_33 -> V_39 + V_78 -> V_80 ) ;
V_26 |= V_78 -> V_82 ;
V_26 |= V_83 ;
return F_31 ( V_2 , V_78 -> V_79 , V_26 ) ;
}
static void F_39 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
T_3 V_84 = F_40 () ;
int V_85 ;
V_85 = F_2 ( V_2 -> V_5 , V_2 -> V_20 -> V_86 ) ;
if ( V_85 < 0 )
return;
if ( V_85 & V_2 -> V_20 -> V_87 )
F_41 ( V_23 ,
F_42 ( V_88 , 0 , V_89 ,
V_90 ,
V_91 ) ,
V_84 ) ;
if ( V_85 & V_2 -> V_20 -> V_92 )
F_41 ( V_23 ,
F_42 ( V_88 , 0 , V_93 ,
V_90 ,
V_91 ) ,
V_84 ) ;
if ( V_85 & V_2 -> V_20 -> V_94 )
F_41 ( V_23 ,
F_42 ( V_88 , 0 , V_95 ,
V_90 ,
V_91 ) ,
V_84 ) ;
}
static T_4 F_43 ( int V_96 , void * V_97 )
{
struct V_22 * V_23 = V_97 ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
const struct V_77 * V_78 = V_2 -> V_20 ;
int V_4 = V_98 ;
int V_85 ;
V_85 = F_2 ( V_2 -> V_5 , V_99 ) ;
if ( V_85 < 0 )
return V_98 ;
if ( V_85 & V_100 ) {
F_44 ( V_23 -> V_101 ) ;
V_4 = V_102 ;
}
if ( ( V_85 & V_103 &&
V_78 -> V_86 == V_104 ) ||
( V_85 & V_105 &&
V_78 -> V_86 == V_106 ) ) {
F_39 ( V_23 ) ;
V_4 = V_102 ;
}
return V_4 ;
}
static T_4 F_45 ( int V_96 , void * V_97 )
{
struct V_107 * V_108 = V_97 ;
struct V_22 * V_23 = V_108 -> V_23 ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
V_12 V_35 [ 16 ] ;
int V_4 ;
V_4 = F_5 ( V_2 , ( T_1 * ) V_35 ) ;
if ( V_4 < 0 )
goto V_109;
F_46 ( V_23 , V_35 ,
F_40 () ) ;
V_109:
F_47 ( V_23 -> V_101 ) ;
return V_102 ;
}
static int F_48 ( struct V_22 * V_23 ,
unsigned V_56 , unsigned V_110 ,
unsigned * V_111 )
{
int V_4 ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
if ( V_56 > V_112 )
return - V_53 ;
if ( ! V_111 )
return F_31 ( V_2 , V_56 , V_110 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_56 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_111 = V_4 ;
return 0 ;
}
static int F_49 ( struct V_113 * V_101 ,
bool V_81 )
{
struct V_22 * V_23 = F_50 ( V_101 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
int V_56 ;
V_56 = F_2 ( V_2 -> V_5 , V_114 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_81 )
V_56 |= V_100 ;
else
V_56 &= ~ V_100 ;
return F_31 ( V_2 , V_114 , V_56 ) ;
}
static int F_51 ( struct V_113 * V_101 ,
struct V_22 * V_23 )
{
struct V_22 * V_115 = F_50 ( V_101 ) ;
if ( V_115 != V_23 )
return - V_53 ;
return 0 ;
}
static int F_52 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
struct V_113 * V_101 ;
int V_4 ;
V_101 = F_53 ( & V_2 -> V_5 -> V_8 , L_2 ,
V_23 -> V_116 ,
V_23 -> V_117 ) ;
if ( ! V_101 )
return - V_118 ;
V_101 -> V_8 . V_119 = & V_2 -> V_5 -> V_8 ;
V_101 -> V_120 = & V_121 ;
F_54 ( V_101 , V_23 ) ;
V_4 = F_55 ( V_101 ) ;
if ( V_4 )
return V_4 ;
V_23 -> V_101 = V_101 ;
return 0 ;
}
static void F_56 ( struct V_22 * V_23 )
{
if ( V_23 -> V_101 )
F_57 ( V_23 -> V_101 ) ;
}
static int F_58 ( struct V_122 * V_5 )
{
int V_24 ;
int V_4 ;
V_4 = F_29 ( V_5 , V_123 ,
V_124 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_24 = 0 ; V_24 < 10 ; V_24 ++ ) {
F_59 ( 100 , 200 ) ;
V_4 = F_2 ( V_5 , V_123 ) ;
if ( V_4 == - V_9 )
continue;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_4 & V_124 ) )
return 0 ;
}
return - V_125 ;
}
static int F_60 ( struct V_122 * V_5 ,
const struct V_126 * V_117 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 ;
int V_4 ;
const struct V_127 * V_128 ;
V_128 = F_61 ( V_129 , & V_5 -> V_8 ) ;
if ( ! V_128 ) {
F_4 ( & V_5 -> V_8 , L_3 ) ;
return - V_130 ;
}
V_23 = F_62 ( & V_5 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_23 )
return - V_118 ;
V_2 = F_12 ( V_23 ) ;
V_2 -> V_5 = V_5 ;
F_63 ( & V_2 -> V_38 ) ;
V_2 -> V_20 = V_128 -> V_2 ;
V_4 = F_2 ( V_5 , V_131 ) ;
if ( V_4 < 0 )
return V_4 ;
switch ( V_4 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
if ( V_4 == V_2 -> V_20 -> V_136 )
break;
default:
return - V_130 ;
}
F_64 ( & V_5 -> V_8 , L_4 ,
V_128 -> V_137 , V_2 -> V_20 -> V_136 ) ;
F_65 ( V_5 , V_23 ) ;
V_23 -> V_63 = & V_138 ;
V_23 -> V_116 = V_117 -> V_116 ;
V_23 -> V_8 . V_119 = & V_5 -> V_8 ;
V_23 -> V_139 = V_140 ;
V_23 -> V_141 = V_2 -> V_20 -> V_141 ;
V_23 -> V_142 = V_2 -> V_20 -> V_142 ;
V_23 -> V_143 = V_144 ;
V_4 = F_58 ( V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_45 = V_145 ;
V_4 = F_29 ( V_5 , V_58 ,
V_2 -> V_45 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_29 ( V_5 , V_146 ,
V_76 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_5 -> V_96 ) {
int V_147 = V_100 |
V_103 |
V_105 ;
int V_148 = V_103 |
V_105 ;
V_4 = F_29 ( V_5 ,
V_149 ,
V_147 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_29 ( V_5 ,
V_114 ,
V_148 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_52 ( V_23 ) ;
if ( V_4 < 0 )
return V_4 ;
}
V_2 -> V_13 = V_55 |
( V_150 << V_15 ) ;
V_4 = F_29 ( V_5 , V_54 ,
V_2 -> V_13 ) ;
if ( V_4 < 0 )
goto V_151;
V_4 = F_66 ( V_23 , NULL ,
F_45 , NULL ) ;
if ( V_4 < 0 )
goto V_151;
if ( V_5 -> V_96 ) {
V_4 = F_67 ( & V_5 -> V_8 ,
V_5 -> V_96 ,
NULL , F_43 ,
V_152 | V_153 ,
V_5 -> V_116 , V_23 ) ;
if ( V_4 )
goto V_154;
}
V_4 = F_68 ( V_23 ) ;
if ( V_4 < 0 )
goto V_154;
return 0 ;
V_154:
F_69 ( V_23 ) ;
V_151:
F_56 ( V_23 ) ;
return V_4 ;
}
static int F_70 ( struct V_122 * V_5 )
{
struct V_22 * V_23 = F_13 ( V_5 ) ;
F_71 ( V_23 ) ;
F_69 ( V_23 ) ;
F_56 ( V_23 ) ;
F_28 ( F_12 ( V_23 ) ) ;
return 0 ;
}
static int F_72 ( struct V_16 * V_8 )
{
return F_28 ( F_12 ( F_13 (
F_14 ( V_8 ) ) ) ) ;
}
static int F_73 ( struct V_16 * V_8 )
{
return F_30 ( F_12 ( F_13 (
F_14 ( V_8 ) ) ) ) ;
}
