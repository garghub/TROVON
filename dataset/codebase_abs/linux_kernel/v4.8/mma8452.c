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
static int F_14 ( struct V_1 * V_2 )
{
int V_18 ;
V_18 = F_2 ( V_2 -> V_5 ,
V_19 ) ;
if ( V_18 < 0 )
return V_18 ;
return ( ( V_18 & V_20 ) >>
V_21 ) ;
}
static T_2 F_15 ( struct V_22 * V_8 ,
struct V_23 * V_24 ,
char * V_12 )
{
return F_16 ( V_12 , V_25 ,
F_17 ( V_25 ) ) ;
}
static T_2 F_18 ( struct V_22 * V_8 ,
struct V_23 * V_24 ,
char * V_12 )
{
struct V_1 * V_2 = F_19 ( F_20 (
F_21 ( V_8 ) ) ) ;
return F_16 ( V_12 , V_2 -> V_26 -> V_27 ,
F_17 ( V_2 -> V_26 -> V_27 ) ) ;
}
static T_2 F_22 ( struct V_22 * V_8 ,
struct V_23 * V_24 ,
char * V_12 )
{
struct V_28 * V_29 = F_23 ( V_8 ) ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_30 , V_31 ;
V_30 = F_13 ( V_2 ) ;
V_31 = F_14 ( V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
return F_16 ( V_12 , V_32 [ V_31 ] [ V_30 ] ,
F_17 ( V_32 [ 0 ] [ 0 ] ) ) ;
}
static T_2 F_24 ( struct V_22 * V_8 ,
struct V_23 * V_24 ,
char * V_12 )
{
struct V_28 * V_29 = F_23 ( V_8 ) ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_30 = F_13 ( V_2 ) ;
int V_31 ;
T_3 V_33 = 0 ;
T_4 V_34 = 0 ;
for ( V_31 = 0 ; V_31 < F_17 ( V_35 ) ; V_31 ++ ) {
if ( V_33 == V_35 [ V_31 ] [ V_30 ] )
continue;
V_33 = V_35 [ V_31 ] [ V_30 ] ;
V_34 += F_25 ( V_12 + V_34 , V_36 - V_34 , L_3 , V_33 ) ;
}
V_12 [ V_34 - 1 ] = '\n' ;
return V_34 ;
}
static int F_26 ( struct V_1 * V_2 ,
int V_33 , int V_37 )
{
return F_27 ( V_25 ,
F_17 ( V_25 ) ,
V_33 , V_37 ) ;
}
static int F_28 ( struct V_1 * V_2 , int V_33 , int V_37 )
{
return F_27 ( V_2 -> V_26 -> V_27 ,
F_17 ( V_2 -> V_26 -> V_27 ) , V_33 , V_37 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
int V_33 , int V_37 )
{
int V_30 , V_31 ;
V_30 = F_13 ( V_2 ) ;
V_31 = F_14 ( V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
return F_27 ( V_32 [ V_31 ] [ V_30 ] ,
F_17 ( V_32 [ 0 ] [ 0 ] ) , V_33 , V_37 ) ;
}
static int F_30 ( struct V_1 * V_2 , int * V_38 , int * V_39 )
{
int V_31 , V_30 , V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_40 ) ;
if ( V_4 < 0 )
return V_4 ;
V_30 = F_13 ( V_2 ) ;
V_31 = F_14 ( V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
V_4 &= V_41 ;
* V_38 = V_32 [ V_31 ] [ V_30 ] [ V_4 ] [ 0 ] ;
* V_39 = V_32 [ V_31 ] [ V_30 ] [ V_4 ] [ 1 ] ;
return 0 ;
}
static int F_31 ( struct V_28 * V_29 ,
struct V_42 const * V_43 ,
int * V_33 , int * V_37 , long V_44 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
T_1 V_45 [ 3 ] ;
int V_30 , V_4 ;
switch ( V_44 ) {
case V_46 :
if ( F_32 ( V_29 ) )
return - V_47 ;
F_33 ( & V_2 -> V_48 ) ;
V_4 = F_11 ( V_2 , V_45 ) ;
F_34 ( & V_2 -> V_48 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_33 = F_35 ( F_36 (
V_45 [ V_43 -> V_49 ] ) >> V_43 -> V_50 . V_51 ,
V_43 -> V_50 . V_52 - 1 ) ;
return V_53 ;
case V_54 :
V_30 = V_2 -> V_55 & V_56 ;
* V_33 = V_2 -> V_26 -> V_27 [ V_30 ] [ 0 ] ;
* V_37 = V_2 -> V_26 -> V_27 [ V_30 ] [ 1 ] ;
return V_57 ;
case V_58 :
V_30 = F_13 ( V_2 ) ;
* V_33 = V_25 [ V_30 ] [ 0 ] ;
* V_37 = V_25 [ V_30 ] [ 1 ] ;
return V_57 ;
case V_59 :
V_4 = F_2 ( V_2 -> V_5 ,
V_60 +
V_43 -> V_49 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_33 = F_35 ( V_4 , 7 ) ;
return V_53 ;
case V_61 :
if ( V_2 -> V_55 & V_62 ) {
V_4 = F_30 ( V_2 , V_33 , V_37 ) ;
if ( V_4 < 0 )
return V_4 ;
} else {
* V_33 = 0 ;
* V_37 = 0 ;
}
return V_57 ;
case V_63 :
V_4 = F_14 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_30 = F_13 ( V_2 ) ;
* V_33 = V_35 [ V_4 ] [ V_30 ] ;
return V_53 ;
}
return - V_64 ;
}
static int F_37 ( struct V_1 * V_2 )
{
return F_38 ( V_2 -> V_5 , V_65 ,
V_2 -> V_15 & ~ V_66 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
return F_38 ( V_2 -> V_5 , V_65 ,
V_2 -> V_15 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_18 ;
V_18 = F_2 ( V_2 -> V_5 , V_65 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_18 & V_66 ;
}
static int F_41 ( struct V_1 * V_2 , V_14 V_18 , V_14 V_33 )
{
int V_4 ;
int V_67 ;
F_33 ( & V_2 -> V_48 ) ;
V_67 = F_40 ( V_2 ) ;
if ( V_67 < 0 ) {
V_4 = V_67 ;
goto V_68;
}
if ( V_67 > 0 ) {
V_4 = F_37 ( V_2 ) ;
if ( V_4 < 0 )
goto V_68;
}
V_4 = F_38 ( V_2 -> V_5 , V_18 , V_33 ) ;
if ( V_4 < 0 )
goto V_68;
if ( V_67 > 0 ) {
V_4 = F_39 ( V_2 ) ;
if ( V_4 < 0 )
goto V_68;
}
V_4 = 0 ;
V_68:
F_34 ( & V_2 -> V_48 ) ;
return V_4 ;
}
static int F_42 ( struct V_1 * V_2 , V_14 V_69 )
{
int V_18 ;
V_18 = F_2 ( V_2 -> V_5 ,
V_19 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 &= ~ V_20 ;
V_18 |= V_69 << V_21 ;
return F_41 ( V_2 , V_19 , V_18 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_33 ;
const struct V_70 * V_71 = V_2 -> V_26 ;
V_33 = F_2 ( V_2 -> V_5 , V_71 -> V_72 ) ;
if ( V_33 < 0 )
return V_33 ;
return ! ( V_33 & V_73 ) ;
}
static int F_44 ( struct V_1 * V_2 , bool V_74 )
{
int V_33 ;
const struct V_70 * V_71 = V_2 -> V_26 ;
if ( ( V_74 && F_43 ( V_2 ) ) ||
( ! V_74 && ! ( F_43 ( V_2 ) ) ) )
return 0 ;
V_33 = F_2 ( V_2 -> V_5 , V_71 -> V_72 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_74 ) {
V_33 |= F_45 ( V_75 + V_71 -> V_76 ) ;
V_33 |= F_45 ( V_77 + V_71 -> V_76 ) ;
V_33 |= F_45 ( V_78 + V_71 -> V_76 ) ;
V_33 &= ~ V_73 ;
} else {
V_33 &= ~ F_45 ( V_75 + V_71 -> V_76 ) ;
V_33 &= ~ F_45 ( V_77 + V_71 -> V_76 ) ;
V_33 &= ~ F_45 ( V_78 + V_71 -> V_76 ) ;
V_33 |= V_73 ;
}
return F_41 ( V_2 , V_71 -> V_72 , V_33 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
int V_33 , int V_37 )
{
int V_30 , V_18 ;
V_30 = F_29 ( V_2 , V_33 , V_37 ) ;
if ( V_30 < 0 )
return V_30 ;
V_18 = F_2 ( V_2 -> V_5 ,
V_40 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 &= ~ V_41 ;
V_18 |= V_30 ;
return F_41 ( V_2 , V_40 , V_18 ) ;
}
static int F_47 ( struct V_28 * V_29 ,
struct V_42 const * V_43 ,
int V_33 , int V_37 , long V_44 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_30 , V_4 ;
if ( F_32 ( V_29 ) )
return - V_47 ;
switch ( V_44 ) {
case V_58 :
V_30 = F_26 ( V_2 , V_33 , V_37 ) ;
if ( V_30 < 0 )
return V_30 ;
V_2 -> V_15 &= ~ V_16 ;
V_2 -> V_15 |= V_30 << V_17 ;
return F_41 ( V_2 , V_65 ,
V_2 -> V_15 ) ;
case V_54 :
V_30 = F_28 ( V_2 , V_33 , V_37 ) ;
if ( V_30 < 0 )
return V_30 ;
V_2 -> V_55 &= ~ V_56 ;
V_2 -> V_55 |= V_30 ;
return F_41 ( V_2 , V_79 ,
V_2 -> V_55 ) ;
case V_59 :
if ( V_33 < - 128 || V_33 > 127 )
return - V_64 ;
return F_41 ( V_2 ,
V_60 + V_43 -> V_49 ,
V_33 ) ;
case V_61 :
if ( V_33 == 0 && V_37 == 0 ) {
V_2 -> V_55 &= ~ V_62 ;
} else {
V_2 -> V_55 |= V_62 ;
V_4 = F_46 ( V_2 , V_33 , V_37 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_41 ( V_2 , V_79 ,
V_2 -> V_55 ) ;
case V_63 :
V_4 = F_13 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < F_17 ( V_35 ) ; V_30 ++ ) {
if ( V_35 [ V_30 ] [ V_4 ] == V_33 )
return F_42 ( V_2 , V_30 ) ;
}
default:
return - V_64 ;
}
}
static int F_48 ( struct V_28 * V_29 ,
const struct V_42 * V_43 ,
enum V_80 type ,
enum V_81 V_82 ,
enum V_83 V_84 ,
int * V_33 , int * V_37 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_4 , V_85 , V_86 ;
switch ( V_84 ) {
case V_87 :
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_26 -> V_88 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_33 = V_4 & V_2 -> V_26 -> V_89 ;
return V_53 ;
case V_90 :
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_26 -> V_91 ) ;
if ( V_4 < 0 )
return V_4 ;
V_86 = F_14 ( V_2 ) ;
if ( V_86 < 0 )
return V_86 ;
V_85 = V_4 * V_92 [ V_86 ] [
F_13 ( V_2 ) ] ;
* V_33 = V_85 / V_93 ;
* V_37 = V_85 % V_93 ;
return V_57 ;
case V_94 :
V_4 = F_2 ( V_2 -> V_5 ,
V_95 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_96 ) {
* V_33 = 0 ;
* V_37 = 0 ;
} else {
V_4 = F_30 ( V_2 , V_33 , V_37 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return V_57 ;
default:
return - V_64 ;
}
}
static int F_49 ( struct V_28 * V_29 ,
const struct V_42 * V_43 ,
enum V_80 type ,
enum V_81 V_82 ,
enum V_83 V_84 ,
int V_33 , int V_37 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_4 , V_18 , V_97 ;
switch ( V_84 ) {
case V_87 :
if ( V_33 < 0 || V_33 > V_98 )
return - V_64 ;
return F_41 ( V_2 , V_2 -> V_26 -> V_88 ,
V_33 ) ;
case V_90 :
V_4 = F_14 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_97 = ( V_33 * V_93 + V_37 ) /
V_92 [ V_4 ] [
F_13 ( V_2 ) ] ;
if ( V_97 < 0 || V_97 > 0xff )
return - V_64 ;
return F_41 ( V_2 , V_2 -> V_26 -> V_91 ,
V_97 ) ;
case V_94 :
V_18 = F_2 ( V_2 -> V_5 ,
V_95 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_33 == 0 && V_37 == 0 ) {
V_18 |= V_96 ;
} else {
V_18 &= ~ V_96 ;
V_4 = F_46 ( V_2 , V_33 , V_37 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_41 ( V_2 , V_95 , V_18 ) ;
default:
return - V_64 ;
}
}
static int F_50 ( struct V_28 * V_29 ,
const struct V_42 * V_43 ,
enum V_80 type ,
enum V_81 V_82 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
const struct V_70 * V_71 = V_2 -> V_26 ;
int V_4 ;
switch ( V_82 ) {
case V_99 :
return F_43 ( V_2 ) ;
case V_100 :
if ( F_43 ( V_2 ) )
return 0 ;
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_26 -> V_72 ) ;
if ( V_4 < 0 )
return V_4 ;
return ! ! ( V_4 & F_45 ( V_43 -> V_49 +
V_71 -> V_76 ) ) ;
default:
return - V_64 ;
}
}
static int F_51 ( struct V_28 * V_29 ,
const struct V_42 * V_43 ,
enum V_80 type ,
enum V_81 V_82 ,
int V_74 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
const struct V_70 * V_71 = V_2 -> V_26 ;
int V_33 , V_4 ;
V_4 = F_5 ( V_2 -> V_5 , V_74 ) ;
if ( V_4 )
return V_4 ;
switch ( V_82 ) {
case V_99 :
return F_44 ( V_2 , V_74 ) ;
case V_100 :
V_33 = F_2 ( V_2 -> V_5 , V_71 -> V_72 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_74 ) {
if ( F_43 ( V_2 ) ) {
V_33 &= ~ F_45 ( V_75 + V_71 -> V_76 ) ;
V_33 &= ~ F_45 ( V_77 + V_71 -> V_76 ) ;
V_33 &= ~ F_45 ( V_78 + V_71 -> V_76 ) ;
V_33 |= V_73 ;
}
V_33 |= F_45 ( V_43 -> V_49 + V_71 -> V_76 ) ;
} else {
if ( F_43 ( V_2 ) )
return 0 ;
V_33 &= ~ F_45 ( V_43 -> V_49 + V_71 -> V_76 ) ;
}
V_33 |= V_71 -> V_101 ;
return F_41 ( V_2 , V_71 -> V_72 , V_33 ) ;
default:
return - V_64 ;
}
}
static void F_52 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
T_5 V_102 = F_53 ( V_29 ) ;
int V_103 ;
V_103 = F_2 ( V_2 -> V_5 , V_2 -> V_26 -> V_104 ) ;
if ( V_103 < 0 )
return;
if ( F_43 ( V_2 ) ) {
F_54 ( V_29 ,
F_55 ( V_105 , 0 ,
V_106 ,
V_107 ,
V_99 ) ,
V_102 ) ;
return;
}
if ( V_103 & V_2 -> V_26 -> V_108 )
F_54 ( V_29 ,
F_55 ( V_105 , 0 , V_109 ,
V_107 ,
V_100 ) ,
V_102 ) ;
if ( V_103 & V_2 -> V_26 -> V_110 )
F_54 ( V_29 ,
F_55 ( V_105 , 0 , V_111 ,
V_107 ,
V_100 ) ,
V_102 ) ;
if ( V_103 & V_2 -> V_26 -> V_112 )
F_54 ( V_29 ,
F_55 ( V_105 , 0 , V_113 ,
V_107 ,
V_100 ) ,
V_102 ) ;
}
static T_6 F_56 ( int V_114 , void * V_115 )
{
struct V_28 * V_29 = V_115 ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
const struct V_70 * V_71 = V_2 -> V_26 ;
int V_4 = V_116 ;
int V_103 ;
V_103 = F_2 ( V_2 -> V_5 , V_117 ) ;
if ( V_103 < 0 )
return V_116 ;
if ( V_103 & V_118 ) {
F_57 ( V_29 -> V_119 ) ;
V_4 = V_120 ;
}
if ( ( V_103 & V_121 &&
V_71 -> V_104 == V_122 ) ||
( V_103 & V_123 &&
V_71 -> V_104 == V_124 ) ) {
F_52 ( V_29 ) ;
V_4 = V_120 ;
}
return V_4 ;
}
static T_6 F_58 ( int V_114 , void * V_115 )
{
struct V_125 * V_126 = V_115 ;
struct V_28 * V_29 = V_126 -> V_29 ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
V_14 V_45 [ 16 ] ;
int V_4 ;
V_4 = F_11 ( V_2 , ( T_1 * ) V_45 ) ;
if ( V_4 < 0 )
goto V_127;
F_59 ( V_29 , V_45 ,
F_53 ( V_29 ) ) ;
V_127:
F_60 ( V_29 -> V_119 ) ;
return V_120 ;
}
static int F_61 ( struct V_28 * V_29 ,
unsigned V_18 , unsigned V_128 ,
unsigned * V_129 )
{
int V_4 ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
if ( V_18 > V_130 )
return - V_64 ;
if ( ! V_129 )
return F_41 ( V_2 , V_18 , V_128 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_129 = V_4 ;
return 0 ;
}
static int F_62 ( struct V_131 * V_119 ,
bool V_74 )
{
struct V_28 * V_29 = F_63 ( V_119 ) ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_18 , V_4 ;
V_4 = F_5 ( V_2 -> V_5 , V_74 ) ;
if ( V_4 )
return V_4 ;
V_18 = F_2 ( V_2 -> V_5 , V_132 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_74 )
V_18 |= V_118 ;
else
V_18 &= ~ V_118 ;
return F_41 ( V_2 , V_132 , V_18 ) ;
}
static int F_64 ( struct V_131 * V_119 ,
struct V_28 * V_29 )
{
struct V_28 * V_133 = F_63 ( V_119 ) ;
if ( V_133 != V_29 )
return - V_64 ;
return 0 ;
}
static int F_65 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
struct V_131 * V_119 ;
int V_4 ;
V_119 = F_66 ( & V_2 -> V_5 -> V_8 , L_4 ,
V_29 -> V_134 ,
V_29 -> V_135 ) ;
if ( ! V_119 )
return - V_136 ;
V_119 -> V_8 . V_137 = & V_2 -> V_5 -> V_8 ;
V_119 -> V_138 = & V_139 ;
F_67 ( V_119 , V_29 ) ;
V_4 = F_68 ( V_119 ) ;
if ( V_4 )
return V_4 ;
V_29 -> V_119 = V_119 ;
return 0 ;
}
static void F_69 ( struct V_28 * V_29 )
{
if ( V_29 -> V_119 )
F_70 ( V_29 -> V_119 ) ;
}
static int F_71 ( struct V_10 * V_5 )
{
int V_30 ;
int V_4 ;
V_4 = F_38 ( V_5 , V_19 ,
V_140 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_30 = 0 ; V_30 < 10 ; V_30 ++ ) {
F_72 ( 100 , 200 ) ;
V_4 = F_2 ( V_5 , V_19 ) ;
if ( V_4 == - V_9 )
continue;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_4 & V_140 ) )
return 0 ;
}
return - V_141 ;
}
static int F_73 ( struct V_10 * V_5 ,
const struct V_142 * V_135 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
int V_4 ;
const struct V_143 * V_144 ;
V_144 = F_74 ( V_145 , & V_5 -> V_8 ) ;
if ( ! V_144 ) {
F_4 ( & V_5 -> V_8 , L_5 ) ;
return - V_146 ;
}
V_29 = F_75 ( & V_5 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_29 )
return - V_136 ;
V_2 = F_19 ( V_29 ) ;
V_2 -> V_5 = V_5 ;
F_76 ( & V_2 -> V_48 ) ;
V_2 -> V_26 = V_144 -> V_2 ;
V_4 = F_2 ( V_5 , V_147 ) ;
if ( V_4 < 0 )
return V_4 ;
switch ( V_4 ) {
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
if ( V_4 == V_2 -> V_26 -> V_154 )
break;
default:
return - V_146 ;
}
F_77 ( & V_5 -> V_8 , L_6 ,
V_144 -> V_155 , V_2 -> V_26 -> V_154 ) ;
F_78 ( V_5 , V_29 ) ;
V_29 -> V_84 = & V_156 ;
V_29 -> V_134 = V_135 -> V_134 ;
V_29 -> V_8 . V_137 = & V_5 -> V_8 ;
V_29 -> V_157 = V_158 ;
V_29 -> V_159 = V_2 -> V_26 -> V_159 ;
V_29 -> V_160 = V_2 -> V_26 -> V_160 ;
V_29 -> V_161 = V_162 ;
V_4 = F_71 ( V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_55 = V_163 ;
V_4 = F_38 ( V_5 , V_79 ,
V_2 -> V_55 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_38 ( V_5 , V_164 ,
V_98 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_5 -> V_114 ) {
int V_165 = V_118 |
V_121 |
V_123 ;
int V_166 = V_121 |
V_123 ;
int V_167 ;
V_167 = F_79 ( V_5 -> V_8 . V_168 , L_7 ) ;
if ( V_167 == V_5 -> V_114 ) {
F_80 ( & V_5 -> V_8 , L_8 ) ;
} else {
V_4 = F_38 ( V_5 ,
V_169 ,
V_165 ) ;
if ( V_4 < 0 )
return V_4 ;
F_80 ( & V_5 -> V_8 , L_9 ) ;
}
V_4 = F_38 ( V_5 ,
V_132 ,
V_166 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_65 ( V_29 ) ;
if ( V_4 < 0 )
return V_4 ;
}
V_2 -> V_15 = V_66 |
( V_170 << V_17 ) ;
V_4 = F_38 ( V_5 , V_65 ,
V_2 -> V_15 ) ;
if ( V_4 < 0 )
goto V_171;
V_4 = F_81 ( V_29 , NULL ,
F_58 , NULL ) ;
if ( V_4 < 0 )
goto V_171;
if ( V_5 -> V_114 ) {
V_4 = F_82 ( & V_5 -> V_8 ,
V_5 -> V_114 ,
NULL , F_56 ,
V_172 | V_173 ,
V_5 -> V_134 , V_29 ) ;
if ( V_4 )
goto V_174;
}
V_4 = F_83 ( & V_5 -> V_8 ) ;
if ( V_4 < 0 )
goto V_174;
F_84 ( & V_5 -> V_8 ) ;
F_85 ( & V_5 -> V_8 ,
V_175 ) ;
F_86 ( & V_5 -> V_8 ) ;
V_4 = F_87 ( V_29 ) ;
if ( V_4 < 0 )
goto V_174;
V_4 = F_44 ( V_2 , false ) ;
if ( V_4 < 0 )
goto V_174;
return 0 ;
V_174:
F_88 ( V_29 ) ;
V_171:
F_69 ( V_29 ) ;
return V_4 ;
}
static int F_89 ( struct V_10 * V_5 )
{
struct V_28 * V_29 = F_20 ( V_5 ) ;
F_90 ( V_29 ) ;
F_91 ( & V_5 -> V_8 ) ;
F_92 ( & V_5 -> V_8 ) ;
F_10 ( & V_5 -> V_8 ) ;
F_88 ( V_29 ) ;
F_69 ( V_29 ) ;
F_37 ( F_19 ( V_29 ) ) ;
return 0 ;
}
static int F_93 ( struct V_22 * V_8 )
{
struct V_28 * V_29 = F_20 ( F_21 ( V_8 ) ) ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_4 ;
F_33 ( & V_2 -> V_48 ) ;
V_4 = F_37 ( V_2 ) ;
F_34 ( & V_2 -> V_48 ) ;
if ( V_4 < 0 ) {
F_4 ( & V_2 -> V_5 -> V_8 , L_10 ) ;
return - V_176 ;
}
return 0 ;
}
static int F_94 ( struct V_22 * V_8 )
{
struct V_28 * V_29 = F_20 ( F_21 ( V_8 ) ) ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_4 , V_177 ;
V_4 = F_39 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_13 ( V_2 ) ;
V_177 = 1000 / V_25 [ V_4 ] [ 0 ] ;
if ( V_177 < 20 )
F_72 ( V_177 * 1000 , 20000 ) ;
else
F_95 ( V_177 ) ;
return 0 ;
}
static int F_96 ( struct V_22 * V_8 )
{
return F_37 ( F_19 ( F_20 (
F_21 ( V_8 ) ) ) ) ;
}
static int F_97 ( struct V_22 * V_8 )
{
return F_39 ( F_19 ( F_20 (
F_21 ( V_8 ) ) ) ) ;
}
