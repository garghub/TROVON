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
static unsigned int F_13 ( struct V_1 * V_2 )
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
V_4 = F_32 ( V_29 ) ;
if ( V_4 )
return V_4 ;
F_33 ( & V_2 -> V_47 ) ;
V_4 = F_11 ( V_2 , V_45 ) ;
F_34 ( & V_2 -> V_47 ) ;
F_35 ( V_29 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_33 = F_36 ( F_37 (
V_45 [ V_43 -> V_48 ] ) >> V_43 -> V_49 . V_50 ,
V_43 -> V_49 . V_51 - 1 ) ;
return V_52 ;
case V_53 :
V_30 = V_2 -> V_54 & V_55 ;
* V_33 = V_2 -> V_26 -> V_27 [ V_30 ] [ 0 ] ;
* V_37 = V_2 -> V_26 -> V_27 [ V_30 ] [ 1 ] ;
return V_56 ;
case V_57 :
V_30 = F_13 ( V_2 ) ;
* V_33 = V_25 [ V_30 ] [ 0 ] ;
* V_37 = V_25 [ V_30 ] [ 1 ] ;
return V_56 ;
case V_58 :
V_4 = F_2 ( V_2 -> V_5 ,
V_59 +
V_43 -> V_48 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_33 = F_36 ( V_4 , 7 ) ;
return V_52 ;
case V_60 :
if ( V_2 -> V_54 & V_61 ) {
V_4 = F_30 ( V_2 , V_33 , V_37 ) ;
if ( V_4 < 0 )
return V_4 ;
} else {
* V_33 = 0 ;
* V_37 = 0 ;
}
return V_56 ;
case V_62 :
V_4 = F_14 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_30 = F_13 ( V_2 ) ;
* V_33 = V_35 [ V_4 ] [ V_30 ] ;
return V_52 ;
}
return - V_63 ;
}
static int F_38 ( struct V_1 * V_2 )
{
return F_39 ( V_2 -> V_5 , V_64 ,
V_2 -> V_15 & ~ V_65 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
return F_39 ( V_2 -> V_5 , V_64 ,
V_2 -> V_15 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_18 ;
V_18 = F_2 ( V_2 -> V_5 , V_64 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_18 & V_65 ;
}
static int F_42 ( struct V_1 * V_2 , V_14 V_18 , V_14 V_33 )
{
int V_4 ;
int V_66 ;
F_33 ( & V_2 -> V_47 ) ;
V_66 = F_41 ( V_2 ) ;
if ( V_66 < 0 ) {
V_4 = V_66 ;
goto V_67;
}
if ( V_66 > 0 ) {
V_4 = F_38 ( V_2 ) ;
if ( V_4 < 0 )
goto V_67;
}
V_4 = F_39 ( V_2 -> V_5 , V_18 , V_33 ) ;
if ( V_4 < 0 )
goto V_67;
if ( V_66 > 0 ) {
V_4 = F_40 ( V_2 ) ;
if ( V_4 < 0 )
goto V_67;
}
V_4 = 0 ;
V_67:
F_34 ( & V_2 -> V_47 ) ;
return V_4 ;
}
static int F_43 ( struct V_1 * V_2 , V_14 V_68 )
{
int V_18 ;
V_18 = F_2 ( V_2 -> V_5 ,
V_19 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 &= ~ V_20 ;
V_18 |= V_68 << V_21 ;
return F_42 ( V_2 , V_19 , V_18 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_33 ;
const struct V_69 * V_70 = V_2 -> V_26 ;
V_33 = F_2 ( V_2 -> V_5 , V_70 -> V_71 ) ;
if ( V_33 < 0 )
return V_33 ;
return ! ( V_33 & V_72 ) ;
}
static int F_45 ( struct V_1 * V_2 , bool V_73 )
{
int V_33 ;
const struct V_69 * V_70 = V_2 -> V_26 ;
if ( ( V_73 && F_44 ( V_2 ) ) ||
( ! V_73 && ! ( F_44 ( V_2 ) ) ) )
return 0 ;
V_33 = F_2 ( V_2 -> V_5 , V_70 -> V_71 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_73 ) {
V_33 |= F_46 ( V_74 + V_70 -> V_75 ) ;
V_33 |= F_46 ( V_76 + V_70 -> V_75 ) ;
V_33 |= F_46 ( V_77 + V_70 -> V_75 ) ;
V_33 &= ~ V_72 ;
} else {
V_33 &= ~ F_46 ( V_74 + V_70 -> V_75 ) ;
V_33 &= ~ F_46 ( V_76 + V_70 -> V_75 ) ;
V_33 &= ~ F_46 ( V_77 + V_70 -> V_75 ) ;
V_33 |= V_72 ;
}
return F_42 ( V_2 , V_70 -> V_71 , V_33 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
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
return F_42 ( V_2 , V_40 , V_18 ) ;
}
static int F_48 ( struct V_28 * V_29 ,
struct V_42 const * V_43 ,
int V_33 , int V_37 , long V_44 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_30 , V_4 ;
V_4 = F_32 ( V_29 ) ;
if ( V_4 )
return V_4 ;
switch ( V_44 ) {
case V_57 :
V_30 = F_26 ( V_2 , V_33 , V_37 ) ;
if ( V_30 < 0 ) {
V_4 = V_30 ;
break;
}
V_2 -> V_15 &= ~ V_16 ;
V_2 -> V_15 |= V_30 << V_17 ;
V_4 = F_42 ( V_2 , V_64 ,
V_2 -> V_15 ) ;
break;
case V_53 :
V_30 = F_28 ( V_2 , V_33 , V_37 ) ;
if ( V_30 < 0 ) {
V_4 = V_30 ;
break;
}
V_2 -> V_54 &= ~ V_55 ;
V_2 -> V_54 |= V_30 ;
V_4 = F_42 ( V_2 , V_78 ,
V_2 -> V_54 ) ;
break;
case V_58 :
if ( V_33 < - 128 || V_33 > 127 ) {
V_4 = - V_63 ;
break;
}
V_4 = F_42 ( V_2 ,
V_59 + V_43 -> V_48 ,
V_33 ) ;
break;
case V_60 :
if ( V_33 == 0 && V_37 == 0 ) {
V_2 -> V_54 &= ~ V_61 ;
} else {
V_2 -> V_54 |= V_61 ;
V_4 = F_47 ( V_2 , V_33 , V_37 ) ;
if ( V_4 < 0 )
break;
}
V_4 = F_42 ( V_2 , V_78 ,
V_2 -> V_54 ) ;
break;
case V_62 :
V_4 = F_13 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < F_17 ( V_35 ) ; V_30 ++ ) {
if ( V_35 [ V_30 ] [ V_4 ] == V_33 ) {
V_4 = F_43 ( V_2 , V_30 ) ;
break;
}
}
break;
default:
V_4 = - V_63 ;
break;
}
F_35 ( V_29 ) ;
return V_4 ;
}
static int F_49 ( struct V_28 * V_29 ,
const struct V_42 * V_43 ,
enum V_79 type ,
enum V_80 V_81 ,
enum V_82 V_83 ,
int * V_33 , int * V_37 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_4 , V_84 , V_85 ;
switch ( V_83 ) {
case V_86 :
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_26 -> V_87 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_33 = V_4 & V_2 -> V_26 -> V_88 ;
return V_52 ;
case V_89 :
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_26 -> V_90 ) ;
if ( V_4 < 0 )
return V_4 ;
V_85 = F_14 ( V_2 ) ;
if ( V_85 < 0 )
return V_85 ;
V_84 = V_4 * V_91 [ V_85 ] [
F_13 ( V_2 ) ] ;
* V_33 = V_84 / V_92 ;
* V_37 = V_84 % V_92 ;
return V_56 ;
case V_93 :
V_4 = F_2 ( V_2 -> V_5 ,
V_94 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_95 ) {
* V_33 = 0 ;
* V_37 = 0 ;
} else {
V_4 = F_30 ( V_2 , V_33 , V_37 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return V_56 ;
default:
return - V_63 ;
}
}
static int F_50 ( struct V_28 * V_29 ,
const struct V_42 * V_43 ,
enum V_79 type ,
enum V_80 V_81 ,
enum V_82 V_83 ,
int V_33 , int V_37 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_4 , V_18 , V_96 ;
switch ( V_83 ) {
case V_86 :
if ( V_33 < 0 || V_33 > V_97 )
return - V_63 ;
return F_42 ( V_2 , V_2 -> V_26 -> V_87 ,
V_33 ) ;
case V_89 :
V_4 = F_14 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_96 = ( V_33 * V_92 + V_37 ) /
V_91 [ V_4 ] [
F_13 ( V_2 ) ] ;
if ( V_96 < 0 || V_96 > 0xff )
return - V_63 ;
return F_42 ( V_2 , V_2 -> V_26 -> V_90 ,
V_96 ) ;
case V_93 :
V_18 = F_2 ( V_2 -> V_5 ,
V_94 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_33 == 0 && V_37 == 0 ) {
V_18 |= V_95 ;
} else {
V_18 &= ~ V_95 ;
V_4 = F_47 ( V_2 , V_33 , V_37 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_42 ( V_2 , V_94 , V_18 ) ;
default:
return - V_63 ;
}
}
static int F_51 ( struct V_28 * V_29 ,
const struct V_42 * V_43 ,
enum V_79 type ,
enum V_80 V_81 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
const struct V_69 * V_70 = V_2 -> V_26 ;
int V_4 ;
switch ( V_81 ) {
case V_98 :
return F_44 ( V_2 ) ;
case V_99 :
if ( F_44 ( V_2 ) )
return 0 ;
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_26 -> V_71 ) ;
if ( V_4 < 0 )
return V_4 ;
return ! ! ( V_4 & F_46 ( V_43 -> V_48 +
V_70 -> V_75 ) ) ;
default:
return - V_63 ;
}
}
static int F_52 ( struct V_28 * V_29 ,
const struct V_42 * V_43 ,
enum V_79 type ,
enum V_80 V_81 ,
int V_73 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
const struct V_69 * V_70 = V_2 -> V_26 ;
int V_33 , V_4 ;
V_4 = F_5 ( V_2 -> V_5 , V_73 ) ;
if ( V_4 )
return V_4 ;
switch ( V_81 ) {
case V_98 :
return F_45 ( V_2 , V_73 ) ;
case V_99 :
V_33 = F_2 ( V_2 -> V_5 , V_70 -> V_71 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_73 ) {
if ( F_44 ( V_2 ) ) {
V_33 &= ~ F_46 ( V_74 + V_70 -> V_75 ) ;
V_33 &= ~ F_46 ( V_76 + V_70 -> V_75 ) ;
V_33 &= ~ F_46 ( V_77 + V_70 -> V_75 ) ;
V_33 |= V_72 ;
}
V_33 |= F_46 ( V_43 -> V_48 + V_70 -> V_75 ) ;
} else {
if ( F_44 ( V_2 ) )
return 0 ;
V_33 &= ~ F_46 ( V_43 -> V_48 + V_70 -> V_75 ) ;
}
V_33 |= V_70 -> V_100 ;
return F_42 ( V_2 , V_70 -> V_71 , V_33 ) ;
default:
return - V_63 ;
}
}
static void F_53 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
T_5 V_101 = F_54 ( V_29 ) ;
int V_102 ;
V_102 = F_2 ( V_2 -> V_5 , V_2 -> V_26 -> V_103 ) ;
if ( V_102 < 0 )
return;
if ( F_44 ( V_2 ) ) {
F_55 ( V_29 ,
F_56 ( V_104 , 0 ,
V_105 ,
V_106 ,
V_98 ) ,
V_101 ) ;
return;
}
if ( V_102 & V_2 -> V_26 -> V_107 )
F_55 ( V_29 ,
F_56 ( V_104 , 0 , V_108 ,
V_106 ,
V_99 ) ,
V_101 ) ;
if ( V_102 & V_2 -> V_26 -> V_109 )
F_55 ( V_29 ,
F_56 ( V_104 , 0 , V_110 ,
V_106 ,
V_99 ) ,
V_101 ) ;
if ( V_102 & V_2 -> V_26 -> V_111 )
F_55 ( V_29 ,
F_56 ( V_104 , 0 , V_112 ,
V_106 ,
V_99 ) ,
V_101 ) ;
}
static T_6 F_57 ( int V_113 , void * V_114 )
{
struct V_28 * V_29 = V_114 ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
const struct V_69 * V_70 = V_2 -> V_26 ;
int V_4 = V_115 ;
int V_102 ;
V_102 = F_2 ( V_2 -> V_5 , V_116 ) ;
if ( V_102 < 0 )
return V_115 ;
if ( V_102 & V_117 ) {
F_58 ( V_29 -> V_118 ) ;
V_4 = V_119 ;
}
if ( ( V_102 & V_120 &&
V_70 -> V_103 == V_121 ) ||
( V_102 & V_122 &&
V_70 -> V_103 == V_123 ) ) {
F_53 ( V_29 ) ;
V_4 = V_119 ;
}
return V_4 ;
}
static T_6 F_59 ( int V_113 , void * V_114 )
{
struct V_124 * V_125 = V_114 ;
struct V_28 * V_29 = V_125 -> V_29 ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
V_14 V_45 [ 16 ] ;
int V_4 ;
V_4 = F_11 ( V_2 , ( T_1 * ) V_45 ) ;
if ( V_4 < 0 )
goto V_126;
F_60 ( V_29 , V_45 ,
F_54 ( V_29 ) ) ;
V_126:
F_61 ( V_29 -> V_118 ) ;
return V_119 ;
}
static int F_62 ( struct V_28 * V_29 ,
unsigned V_18 , unsigned V_127 ,
unsigned * V_128 )
{
int V_4 ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
if ( V_18 > V_129 )
return - V_63 ;
if ( ! V_128 )
return F_42 ( V_2 , V_18 , V_127 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_128 = V_4 ;
return 0 ;
}
static int F_63 ( struct V_130 * V_118 ,
bool V_73 )
{
struct V_28 * V_29 = F_64 ( V_118 ) ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_18 , V_4 ;
V_4 = F_5 ( V_2 -> V_5 , V_73 ) ;
if ( V_4 )
return V_4 ;
V_18 = F_2 ( V_2 -> V_5 , V_131 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_73 )
V_18 |= V_117 ;
else
V_18 &= ~ V_117 ;
return F_42 ( V_2 , V_131 , V_18 ) ;
}
static int F_65 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_29 ) ;
struct V_130 * V_118 ;
int V_4 ;
V_118 = F_66 ( & V_2 -> V_5 -> V_8 , L_4 ,
V_29 -> V_132 ,
V_29 -> V_133 ) ;
if ( ! V_118 )
return - V_134 ;
V_118 -> V_8 . V_135 = & V_2 -> V_5 -> V_8 ;
V_118 -> V_136 = & V_137 ;
F_67 ( V_118 , V_29 ) ;
V_4 = F_68 ( V_118 ) ;
if ( V_4 )
return V_4 ;
V_29 -> V_118 = V_118 ;
return 0 ;
}
static void F_69 ( struct V_28 * V_29 )
{
if ( V_29 -> V_118 )
F_70 ( V_29 -> V_118 ) ;
}
static int F_71 ( struct V_10 * V_5 )
{
int V_30 ;
int V_4 ;
V_4 = F_39 ( V_5 , V_19 ,
V_138 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_30 = 0 ; V_30 < 10 ; V_30 ++ ) {
F_72 ( 100 , 200 ) ;
V_4 = F_2 ( V_5 , V_19 ) ;
if ( V_4 == - V_9 )
continue;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_4 & V_138 ) )
return 0 ;
}
return - V_139 ;
}
static int F_73 ( struct V_10 * V_5 ,
const struct V_140 * V_133 )
{
struct V_1 * V_2 ;
struct V_28 * V_29 ;
int V_4 ;
const struct V_141 * V_142 ;
V_142 = F_74 ( V_143 , & V_5 -> V_8 ) ;
if ( ! V_142 ) {
F_4 ( & V_5 -> V_8 , L_5 ) ;
return - V_144 ;
}
V_29 = F_75 ( & V_5 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_29 )
return - V_134 ;
V_2 = F_19 ( V_29 ) ;
V_2 -> V_5 = V_5 ;
F_76 ( & V_2 -> V_47 ) ;
V_2 -> V_26 = V_142 -> V_2 ;
V_4 = F_2 ( V_5 , V_145 ) ;
if ( V_4 < 0 )
return V_4 ;
switch ( V_4 ) {
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
if ( V_4 == V_2 -> V_26 -> V_152 )
break;
default:
return - V_144 ;
}
F_77 ( & V_5 -> V_8 , L_6 ,
V_142 -> V_153 , V_2 -> V_26 -> V_152 ) ;
F_78 ( V_5 , V_29 ) ;
V_29 -> V_83 = & V_154 ;
V_29 -> V_132 = V_133 -> V_132 ;
V_29 -> V_8 . V_135 = & V_5 -> V_8 ;
V_29 -> V_155 = V_156 ;
V_29 -> V_157 = V_2 -> V_26 -> V_157 ;
V_29 -> V_158 = V_2 -> V_26 -> V_158 ;
V_29 -> V_159 = V_160 ;
V_4 = F_71 ( V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_54 = V_161 ;
V_4 = F_39 ( V_5 , V_78 ,
V_2 -> V_54 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_39 ( V_5 , V_162 ,
V_97 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_5 -> V_113 ) {
int V_163 = V_117 |
V_120 |
V_122 ;
int V_164 = V_120 |
V_122 ;
int V_165 ;
V_165 = F_79 ( V_5 -> V_8 . V_166 , L_7 ) ;
if ( V_165 == V_5 -> V_113 ) {
F_80 ( & V_5 -> V_8 , L_8 ) ;
} else {
V_4 = F_39 ( V_5 ,
V_167 ,
V_163 ) ;
if ( V_4 < 0 )
return V_4 ;
F_80 ( & V_5 -> V_8 , L_9 ) ;
}
V_4 = F_39 ( V_5 ,
V_131 ,
V_164 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_65 ( V_29 ) ;
if ( V_4 < 0 )
return V_4 ;
}
V_2 -> V_15 = V_65 |
( V_168 << V_17 ) ;
V_4 = F_39 ( V_5 , V_64 ,
V_2 -> V_15 ) ;
if ( V_4 < 0 )
goto V_169;
V_4 = F_81 ( V_29 , NULL ,
F_59 , NULL ) ;
if ( V_4 < 0 )
goto V_169;
if ( V_5 -> V_113 ) {
V_4 = F_82 ( & V_5 -> V_8 ,
V_5 -> V_113 ,
NULL , F_57 ,
V_170 | V_171 ,
V_5 -> V_132 , V_29 ) ;
if ( V_4 )
goto V_172;
}
V_4 = F_83 ( & V_5 -> V_8 ) ;
if ( V_4 < 0 )
goto V_172;
F_84 ( & V_5 -> V_8 ) ;
F_85 ( & V_5 -> V_8 ,
V_173 ) ;
F_86 ( & V_5 -> V_8 ) ;
V_4 = F_87 ( V_29 ) ;
if ( V_4 < 0 )
goto V_172;
V_4 = F_45 ( V_2 , false ) ;
if ( V_4 < 0 )
goto V_172;
return 0 ;
V_172:
F_88 ( V_29 ) ;
V_169:
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
F_38 ( F_19 ( V_29 ) ) ;
return 0 ;
}
static int F_93 ( struct V_22 * V_8 )
{
struct V_28 * V_29 = F_20 ( F_21 ( V_8 ) ) ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_4 ;
F_33 ( & V_2 -> V_47 ) ;
V_4 = F_38 ( V_2 ) ;
F_34 ( & V_2 -> V_47 ) ;
if ( V_4 < 0 ) {
F_4 ( & V_2 -> V_5 -> V_8 , L_10 ) ;
return - V_174 ;
}
return 0 ;
}
static int F_94 ( struct V_22 * V_8 )
{
struct V_28 * V_29 = F_20 ( F_21 ( V_8 ) ) ;
struct V_1 * V_2 = F_19 ( V_29 ) ;
int V_4 , V_175 ;
V_4 = F_40 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_13 ( V_2 ) ;
V_175 = 1000 / V_25 [ V_4 ] [ 0 ] ;
if ( V_175 < 20 )
F_72 ( V_175 * 1000 , 20000 ) ;
else
F_95 ( V_175 ) ;
return 0 ;
}
static int F_96 ( struct V_22 * V_8 )
{
return F_38 ( F_19 ( F_20 (
F_21 ( V_8 ) ) ) ) ;
}
static int F_97 ( struct V_22 * V_8 )
{
return F_40 ( F_19 ( F_20 (
F_21 ( V_8 ) ) ) ) ;
}
