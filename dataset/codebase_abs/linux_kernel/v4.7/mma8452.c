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
static int F_5 ( struct V_10 * V_5 , bool V_11 )
{
#ifdef F_6
int V_4 ;
if ( V_11 ) {
V_4 = F_7 ( & V_5 -> V_8 ) ;
} else {
F_8 ( & V_5 -> V_8 ) ;
V_4 = F_9 ( & V_5 -> V_8 ) ;
}
if ( V_4 < 0 ) {
F_4 ( & V_5 -> V_8 ,
L_2 , V_11 ) ;
if ( V_11 )
F_10 ( & V_5 -> V_8 ) ;
return V_4 ;
}
#endif
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_12 [ 3 ] )
{
int V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_5 ( V_2 -> V_5 , true ) ;
if ( V_4 )
return V_4 ;
V_4 = F_12 ( V_2 -> V_5 , V_13 ,
3 * sizeof( T_1 ) , ( V_14 * ) V_12 ) ;
V_4 = F_5 ( V_2 -> V_5 , false ) ;
return V_4 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return ( V_2 -> V_15 & V_16 ) >>
V_17 ;
}
static T_2 F_14 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_12 )
{
return F_15 ( V_12 , V_21 ,
F_16 ( V_21 ) ) ;
}
static T_2 F_17 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_12 )
{
struct V_1 * V_2 = F_18 ( F_19 (
F_20 ( V_8 ) ) ) ;
return F_15 ( V_12 , V_2 -> V_22 -> V_23 ,
F_16 ( V_2 -> V_22 -> V_23 ) ) ;
}
static T_2 F_21 ( struct V_18 * V_8 ,
struct V_19 * V_20 ,
char * V_12 )
{
struct V_24 * V_25 = F_22 ( V_8 ) ;
struct V_1 * V_2 = F_18 ( V_25 ) ;
int V_26 = F_13 ( V_2 ) ;
return F_15 ( V_12 , V_27 [ V_26 ] ,
F_16 ( V_27 [ 0 ] ) ) ;
}
static int F_23 ( struct V_1 * V_2 ,
int V_28 , int V_29 )
{
return F_24 ( V_21 ,
F_16 ( V_21 ) ,
V_28 , V_29 ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_28 , int V_29 )
{
return F_24 ( V_2 -> V_22 -> V_23 ,
F_16 ( V_2 -> V_22 -> V_23 ) , V_28 , V_29 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
int V_28 , int V_29 )
{
int V_26 = F_13 ( V_2 ) ;
return F_24 ( V_27 [ V_26 ] ,
F_16 ( V_27 [ 0 ] ) , V_28 , V_29 ) ;
}
static int F_27 ( struct V_1 * V_2 , int * V_30 , int * V_31 )
{
int V_26 , V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_32 ) ;
if ( V_4 < 0 )
return V_4 ;
V_26 = F_13 ( V_2 ) ;
V_4 &= V_33 ;
* V_30 = V_27 [ V_26 ] [ V_4 ] [ 0 ] ;
* V_31 = V_27 [ V_26 ] [ V_4 ] [ 1 ] ;
return 0 ;
}
static int F_28 ( struct V_24 * V_25 ,
struct V_34 const * V_35 ,
int * V_28 , int * V_29 , long V_36 )
{
struct V_1 * V_2 = F_18 ( V_25 ) ;
T_1 V_37 [ 3 ] ;
int V_26 , V_4 ;
switch ( V_36 ) {
case V_38 :
if ( F_29 ( V_25 ) )
return - V_39 ;
F_30 ( & V_2 -> V_40 ) ;
V_4 = F_11 ( V_2 , V_37 ) ;
F_31 ( & V_2 -> V_40 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_28 = F_32 ( F_33 (
V_37 [ V_35 -> V_41 ] ) >> V_35 -> V_42 . V_43 ,
V_35 -> V_42 . V_44 - 1 ) ;
return V_45 ;
case V_46 :
V_26 = V_2 -> V_47 & V_48 ;
* V_28 = V_2 -> V_22 -> V_23 [ V_26 ] [ 0 ] ;
* V_29 = V_2 -> V_22 -> V_23 [ V_26 ] [ 1 ] ;
return V_49 ;
case V_50 :
V_26 = F_13 ( V_2 ) ;
* V_28 = V_21 [ V_26 ] [ 0 ] ;
* V_29 = V_21 [ V_26 ] [ 1 ] ;
return V_49 ;
case V_51 :
V_4 = F_2 ( V_2 -> V_5 ,
V_52 +
V_35 -> V_41 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_28 = F_32 ( V_4 , 7 ) ;
return V_45 ;
case V_53 :
if ( V_2 -> V_47 & V_54 ) {
V_4 = F_27 ( V_2 , V_28 , V_29 ) ;
if ( V_4 < 0 )
return V_4 ;
} else {
* V_28 = 0 ;
* V_29 = 0 ;
}
return V_49 ;
}
return - V_55 ;
}
static int F_34 ( struct V_1 * V_2 )
{
return F_35 ( V_2 -> V_5 , V_56 ,
V_2 -> V_15 & ~ V_57 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
return F_35 ( V_2 -> V_5 , V_56 ,
V_2 -> V_15 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_58 ;
V_58 = F_2 ( V_2 -> V_5 , V_56 ) ;
if ( V_58 < 0 )
return V_58 ;
return V_58 & V_57 ;
}
static int F_38 ( struct V_1 * V_2 , V_14 V_58 , V_14 V_28 )
{
int V_4 ;
int V_59 ;
F_30 ( & V_2 -> V_40 ) ;
V_59 = F_37 ( V_2 ) ;
if ( V_59 < 0 ) {
V_4 = V_59 ;
goto V_60;
}
if ( V_59 > 0 ) {
V_4 = F_34 ( V_2 ) ;
if ( V_4 < 0 )
goto V_60;
}
V_4 = F_35 ( V_2 -> V_5 , V_58 , V_28 ) ;
if ( V_4 < 0 )
goto V_60;
if ( V_59 > 0 ) {
V_4 = F_36 ( V_2 ) ;
if ( V_4 < 0 )
goto V_60;
}
V_4 = 0 ;
V_60:
F_31 ( & V_2 -> V_40 ) ;
return V_4 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_28 ;
const struct V_61 * V_62 = V_2 -> V_22 ;
V_28 = F_2 ( V_2 -> V_5 , V_62 -> V_63 ) ;
if ( V_28 < 0 )
return V_28 ;
return ! ( V_28 & V_64 ) ;
}
static int F_40 ( struct V_1 * V_2 , bool V_65 )
{
int V_28 ;
const struct V_61 * V_62 = V_2 -> V_22 ;
if ( ( V_65 && F_39 ( V_2 ) ) ||
( ! V_65 && ! ( F_39 ( V_2 ) ) ) )
return 0 ;
V_28 = F_2 ( V_2 -> V_5 , V_62 -> V_63 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_65 ) {
V_28 |= F_41 ( V_66 + V_62 -> V_67 ) ;
V_28 |= F_41 ( V_68 + V_62 -> V_67 ) ;
V_28 |= F_41 ( V_69 + V_62 -> V_67 ) ;
V_28 &= ~ V_64 ;
} else {
V_28 &= ~ F_41 ( V_66 + V_62 -> V_67 ) ;
V_28 &= ~ F_41 ( V_68 + V_62 -> V_67 ) ;
V_28 &= ~ F_41 ( V_69 + V_62 -> V_67 ) ;
V_28 |= V_64 ;
}
V_28 = F_38 ( V_2 , V_62 -> V_63 , V_28 ) ;
if ( V_28 )
return V_28 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
int V_28 , int V_29 )
{
int V_26 , V_58 ;
V_26 = F_26 ( V_2 , V_28 , V_29 ) ;
if ( V_26 < 0 )
return V_26 ;
V_58 = F_2 ( V_2 -> V_5 ,
V_32 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 &= ~ V_33 ;
V_58 |= V_26 ;
return F_38 ( V_2 , V_32 , V_58 ) ;
}
static int F_43 ( struct V_24 * V_25 ,
struct V_34 const * V_35 ,
int V_28 , int V_29 , long V_36 )
{
struct V_1 * V_2 = F_18 ( V_25 ) ;
int V_26 , V_4 ;
if ( F_29 ( V_25 ) )
return - V_39 ;
switch ( V_36 ) {
case V_50 :
V_26 = F_23 ( V_2 , V_28 , V_29 ) ;
if ( V_26 < 0 )
return V_26 ;
V_2 -> V_15 &= ~ V_16 ;
V_2 -> V_15 |= V_26 << V_17 ;
return F_38 ( V_2 , V_56 ,
V_2 -> V_15 ) ;
case V_46 :
V_26 = F_25 ( V_2 , V_28 , V_29 ) ;
if ( V_26 < 0 )
return V_26 ;
V_2 -> V_47 &= ~ V_48 ;
V_2 -> V_47 |= V_26 ;
return F_38 ( V_2 , V_70 ,
V_2 -> V_47 ) ;
case V_51 :
if ( V_28 < - 128 || V_28 > 127 )
return - V_55 ;
return F_38 ( V_2 ,
V_52 + V_35 -> V_41 ,
V_28 ) ;
case V_53 :
if ( V_28 == 0 && V_29 == 0 ) {
V_2 -> V_47 &= ~ V_54 ;
} else {
V_2 -> V_47 |= V_54 ;
V_4 = F_42 ( V_2 , V_28 , V_29 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_38 ( V_2 , V_70 ,
V_2 -> V_47 ) ;
default:
return - V_55 ;
}
}
static int F_44 ( struct V_24 * V_25 ,
const struct V_34 * V_35 ,
enum V_71 type ,
enum V_72 V_73 ,
enum V_74 V_75 ,
int * V_28 , int * V_29 )
{
struct V_1 * V_2 = F_18 ( V_25 ) ;
int V_4 , V_76 ;
switch ( V_75 ) {
case V_77 :
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_22 -> V_78 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_28 = V_4 & V_2 -> V_22 -> V_79 ;
return V_45 ;
case V_80 :
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_22 -> V_81 ) ;
if ( V_4 < 0 )
return V_4 ;
V_76 = V_4 * V_82 [
F_13 ( V_2 ) ] ;
* V_28 = V_76 / V_83 ;
* V_29 = V_76 % V_83 ;
return V_49 ;
case V_84 :
V_4 = F_2 ( V_2 -> V_5 ,
V_85 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_86 ) {
* V_28 = 0 ;
* V_29 = 0 ;
} else {
V_4 = F_27 ( V_2 , V_28 , V_29 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return V_49 ;
default:
return - V_55 ;
}
}
static int F_45 ( struct V_24 * V_25 ,
const struct V_34 * V_35 ,
enum V_71 type ,
enum V_72 V_73 ,
enum V_74 V_75 ,
int V_28 , int V_29 )
{
struct V_1 * V_2 = F_18 ( V_25 ) ;
int V_4 , V_58 , V_87 ;
switch ( V_75 ) {
case V_77 :
if ( V_28 < 0 || V_28 > V_88 )
return - V_55 ;
return F_38 ( V_2 , V_2 -> V_22 -> V_78 ,
V_28 ) ;
case V_80 :
V_87 = ( V_28 * V_83 + V_29 ) /
V_82 [
F_13 ( V_2 ) ] ;
if ( V_87 < 0 || V_87 > 0xff )
return - V_55 ;
return F_38 ( V_2 , V_2 -> V_22 -> V_81 ,
V_87 ) ;
case V_84 :
V_58 = F_2 ( V_2 -> V_5 ,
V_85 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_28 == 0 && V_29 == 0 ) {
V_58 |= V_86 ;
} else {
V_58 &= ~ V_86 ;
V_4 = F_42 ( V_2 , V_28 , V_29 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_38 ( V_2 , V_85 , V_58 ) ;
default:
return - V_55 ;
}
}
static int F_46 ( struct V_24 * V_25 ,
const struct V_34 * V_35 ,
enum V_71 type ,
enum V_72 V_73 )
{
struct V_1 * V_2 = F_18 ( V_25 ) ;
const struct V_61 * V_62 = V_2 -> V_22 ;
int V_4 ;
switch ( V_73 ) {
case V_89 :
return F_39 ( V_2 ) ;
case V_90 :
if ( F_39 ( V_2 ) )
return 0 ;
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_22 -> V_63 ) ;
if ( V_4 < 0 )
return V_4 ;
return ! ! ( V_4 & F_41 ( V_35 -> V_41 +
V_62 -> V_67 ) ) ;
default:
return - V_55 ;
}
}
static int F_47 ( struct V_24 * V_25 ,
const struct V_34 * V_35 ,
enum V_71 type ,
enum V_72 V_73 ,
int V_65 )
{
struct V_1 * V_2 = F_18 ( V_25 ) ;
const struct V_61 * V_62 = V_2 -> V_22 ;
int V_28 , V_4 ;
V_4 = F_5 ( V_2 -> V_5 , V_65 ) ;
if ( V_4 )
return V_4 ;
switch ( V_73 ) {
case V_89 :
return F_40 ( V_2 , V_65 ) ;
case V_90 :
V_28 = F_2 ( V_2 -> V_5 , V_62 -> V_63 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_65 ) {
if ( F_39 ( V_2 ) ) {
V_28 &= ~ F_41 ( V_66 + V_62 -> V_67 ) ;
V_28 &= ~ F_41 ( V_68 + V_62 -> V_67 ) ;
V_28 &= ~ F_41 ( V_69 + V_62 -> V_67 ) ;
V_28 |= V_64 ;
}
V_28 |= F_41 ( V_35 -> V_41 + V_62 -> V_67 ) ;
} else {
if ( F_39 ( V_2 ) )
return 0 ;
V_28 &= ~ F_41 ( V_35 -> V_41 + V_62 -> V_67 ) ;
}
V_28 |= V_62 -> V_91 ;
return F_38 ( V_2 , V_62 -> V_63 , V_28 ) ;
default:
return - V_55 ;
}
}
static void F_48 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_18 ( V_25 ) ;
T_3 V_92 = F_49 () ;
int V_93 ;
V_93 = F_2 ( V_2 -> V_5 , V_2 -> V_22 -> V_94 ) ;
if ( V_93 < 0 )
return;
if ( F_39 ( V_2 ) ) {
F_50 ( V_25 ,
F_51 ( V_95 , 0 ,
V_96 ,
V_97 ,
V_89 ) ,
V_92 ) ;
return;
}
if ( V_93 & V_2 -> V_22 -> V_98 )
F_50 ( V_25 ,
F_51 ( V_95 , 0 , V_99 ,
V_97 ,
V_90 ) ,
V_92 ) ;
if ( V_93 & V_2 -> V_22 -> V_100 )
F_50 ( V_25 ,
F_51 ( V_95 , 0 , V_101 ,
V_97 ,
V_90 ) ,
V_92 ) ;
if ( V_93 & V_2 -> V_22 -> V_102 )
F_50 ( V_25 ,
F_51 ( V_95 , 0 , V_103 ,
V_97 ,
V_90 ) ,
V_92 ) ;
}
static T_4 F_52 ( int V_104 , void * V_105 )
{
struct V_24 * V_25 = V_105 ;
struct V_1 * V_2 = F_18 ( V_25 ) ;
const struct V_61 * V_62 = V_2 -> V_22 ;
int V_4 = V_106 ;
int V_93 ;
V_93 = F_2 ( V_2 -> V_5 , V_107 ) ;
if ( V_93 < 0 )
return V_106 ;
if ( V_93 & V_108 ) {
F_53 ( V_25 -> V_109 ) ;
V_4 = V_110 ;
}
if ( ( V_93 & V_111 &&
V_62 -> V_94 == V_112 ) ||
( V_93 & V_113 &&
V_62 -> V_94 == V_114 ) ) {
F_48 ( V_25 ) ;
V_4 = V_110 ;
}
return V_4 ;
}
static T_4 F_54 ( int V_104 , void * V_105 )
{
struct V_115 * V_116 = V_105 ;
struct V_24 * V_25 = V_116 -> V_25 ;
struct V_1 * V_2 = F_18 ( V_25 ) ;
V_14 V_37 [ 16 ] ;
int V_4 ;
V_4 = F_11 ( V_2 , ( T_1 * ) V_37 ) ;
if ( V_4 < 0 )
goto V_117;
F_55 ( V_25 , V_37 ,
F_49 () ) ;
V_117:
F_56 ( V_25 -> V_109 ) ;
return V_110 ;
}
static int F_57 ( struct V_24 * V_25 ,
unsigned V_58 , unsigned V_118 ,
unsigned * V_119 )
{
int V_4 ;
struct V_1 * V_2 = F_18 ( V_25 ) ;
if ( V_58 > V_120 )
return - V_55 ;
if ( ! V_119 )
return F_38 ( V_2 , V_58 , V_118 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_58 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_119 = V_4 ;
return 0 ;
}
static int F_58 ( struct V_121 * V_109 ,
bool V_65 )
{
struct V_24 * V_25 = F_59 ( V_109 ) ;
struct V_1 * V_2 = F_18 ( V_25 ) ;
int V_58 , V_4 ;
V_4 = F_5 ( V_2 -> V_5 , V_65 ) ;
if ( V_4 )
return V_4 ;
V_58 = F_2 ( V_2 -> V_5 , V_122 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_65 )
V_58 |= V_108 ;
else
V_58 &= ~ V_108 ;
return F_38 ( V_2 , V_122 , V_58 ) ;
}
static int F_60 ( struct V_121 * V_109 ,
struct V_24 * V_25 )
{
struct V_24 * V_123 = F_59 ( V_109 ) ;
if ( V_123 != V_25 )
return - V_55 ;
return 0 ;
}
static int F_61 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_18 ( V_25 ) ;
struct V_121 * V_109 ;
int V_4 ;
V_109 = F_62 ( & V_2 -> V_5 -> V_8 , L_3 ,
V_25 -> V_124 ,
V_25 -> V_125 ) ;
if ( ! V_109 )
return - V_126 ;
V_109 -> V_8 . V_127 = & V_2 -> V_5 -> V_8 ;
V_109 -> V_128 = & V_129 ;
F_63 ( V_109 , V_25 ) ;
V_4 = F_64 ( V_109 ) ;
if ( V_4 )
return V_4 ;
V_25 -> V_109 = V_109 ;
return 0 ;
}
static void F_65 ( struct V_24 * V_25 )
{
if ( V_25 -> V_109 )
F_66 ( V_25 -> V_109 ) ;
}
static int F_67 ( struct V_10 * V_5 )
{
int V_26 ;
int V_4 ;
V_4 = F_35 ( V_5 , V_130 ,
V_131 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_26 = 0 ; V_26 < 10 ; V_26 ++ ) {
F_68 ( 100 , 200 ) ;
V_4 = F_2 ( V_5 , V_130 ) ;
if ( V_4 == - V_9 )
continue;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_4 & V_131 ) )
return 0 ;
}
return - V_132 ;
}
static int F_69 ( struct V_10 * V_5 ,
const struct V_133 * V_125 )
{
struct V_1 * V_2 ;
struct V_24 * V_25 ;
int V_4 ;
const struct V_134 * V_135 ;
V_135 = F_70 ( V_136 , & V_5 -> V_8 ) ;
if ( ! V_135 ) {
F_4 ( & V_5 -> V_8 , L_4 ) ;
return - V_137 ;
}
V_25 = F_71 ( & V_5 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_25 )
return - V_126 ;
V_2 = F_18 ( V_25 ) ;
V_2 -> V_5 = V_5 ;
F_72 ( & V_2 -> V_40 ) ;
V_2 -> V_22 = V_135 -> V_2 ;
V_4 = F_2 ( V_5 , V_138 ) ;
if ( V_4 < 0 )
return V_4 ;
switch ( V_4 ) {
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
if ( V_4 == V_2 -> V_22 -> V_145 )
break;
default:
return - V_137 ;
}
F_73 ( & V_5 -> V_8 , L_5 ,
V_135 -> V_146 , V_2 -> V_22 -> V_145 ) ;
F_74 ( V_5 , V_25 ) ;
V_25 -> V_75 = & V_147 ;
V_25 -> V_124 = V_125 -> V_124 ;
V_25 -> V_8 . V_127 = & V_5 -> V_8 ;
V_25 -> V_148 = V_149 ;
V_25 -> V_150 = V_2 -> V_22 -> V_150 ;
V_25 -> V_151 = V_2 -> V_22 -> V_151 ;
V_25 -> V_152 = V_153 ;
V_4 = F_67 ( V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_47 = V_154 ;
V_4 = F_35 ( V_5 , V_70 ,
V_2 -> V_47 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_35 ( V_5 , V_155 ,
V_88 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_5 -> V_104 ) {
int V_156 = V_108 |
V_111 |
V_113 ;
int V_157 = V_111 |
V_113 ;
int V_158 ;
V_158 = F_75 ( V_5 -> V_8 . V_159 , L_6 ) ;
if ( V_158 == V_5 -> V_104 ) {
F_76 ( & V_5 -> V_8 , L_7 ) ;
} else {
V_4 = F_35 ( V_5 ,
V_160 ,
V_156 ) ;
if ( V_4 < 0 )
return V_4 ;
F_76 ( & V_5 -> V_8 , L_8 ) ;
}
V_4 = F_35 ( V_5 ,
V_122 ,
V_157 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_61 ( V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
}
V_2 -> V_15 = V_57 |
( V_161 << V_17 ) ;
V_4 = F_35 ( V_5 , V_56 ,
V_2 -> V_15 ) ;
if ( V_4 < 0 )
goto V_162;
V_4 = F_77 ( V_25 , NULL ,
F_54 , NULL ) ;
if ( V_4 < 0 )
goto V_162;
if ( V_5 -> V_104 ) {
V_4 = F_78 ( & V_5 -> V_8 ,
V_5 -> V_104 ,
NULL , F_52 ,
V_163 | V_164 ,
V_5 -> V_124 , V_25 ) ;
if ( V_4 )
goto V_165;
}
V_4 = F_79 ( & V_5 -> V_8 ) ;
if ( V_4 < 0 )
goto V_165;
F_80 ( & V_5 -> V_8 ) ;
F_81 ( & V_5 -> V_8 ,
V_166 ) ;
F_82 ( & V_5 -> V_8 ) ;
V_4 = F_83 ( V_25 ) ;
if ( V_4 < 0 )
goto V_165;
V_4 = F_40 ( V_2 , false ) ;
if ( V_4 )
return V_4 ;
return 0 ;
V_165:
F_84 ( V_25 ) ;
V_162:
F_65 ( V_25 ) ;
return V_4 ;
}
static int F_85 ( struct V_10 * V_5 )
{
struct V_24 * V_25 = F_19 ( V_5 ) ;
F_86 ( V_25 ) ;
F_87 ( & V_5 -> V_8 ) ;
F_88 ( & V_5 -> V_8 ) ;
F_10 ( & V_5 -> V_8 ) ;
F_84 ( V_25 ) ;
F_65 ( V_25 ) ;
F_34 ( F_18 ( V_25 ) ) ;
return 0 ;
}
static int F_89 ( struct V_18 * V_8 )
{
struct V_24 * V_25 = F_19 ( F_20 ( V_8 ) ) ;
struct V_1 * V_2 = F_18 ( V_25 ) ;
int V_4 ;
F_30 ( & V_2 -> V_40 ) ;
V_4 = F_34 ( V_2 ) ;
F_31 ( & V_2 -> V_40 ) ;
if ( V_4 < 0 ) {
F_4 ( & V_2 -> V_5 -> V_8 , L_9 ) ;
return - V_167 ;
}
return 0 ;
}
static int F_90 ( struct V_18 * V_8 )
{
struct V_24 * V_25 = F_19 ( F_20 ( V_8 ) ) ;
struct V_1 * V_2 = F_18 ( V_25 ) ;
int V_4 , V_168 ;
V_4 = F_36 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_13 ( V_2 ) ;
V_168 = 1000 / V_21 [ V_4 ] [ 0 ] ;
if ( V_168 < 20 )
F_68 ( V_168 * 1000 , 20000 ) ;
else
F_91 ( V_168 ) ;
return 0 ;
}
static int F_92 ( struct V_18 * V_8 )
{
return F_34 ( F_18 ( F_19 (
F_20 ( V_8 ) ) ) ) ;
}
static int F_93 ( struct V_18 * V_8 )
{
return F_36 ( F_18 ( F_19 (
F_20 ( V_8 ) ) ) ) ;
}
