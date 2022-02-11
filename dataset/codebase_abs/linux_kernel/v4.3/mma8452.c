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
return F_9 ( V_10 , V_20 ,
F_10 ( V_20 ) ) ;
}
static T_2 F_12 ( struct V_16 * V_8 ,
struct V_17 * V_18 ,
char * V_10 )
{
struct V_21 * V_22 = F_13 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_23 = F_7 ( V_2 ) ;
return F_9 ( V_10 , V_24 [ V_23 ] ,
F_10 ( V_24 [ 0 ] ) ) ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_25 , int V_26 )
{
return F_16 ( V_19 ,
F_10 ( V_19 ) ,
V_25 , V_26 ) ;
}
static int F_17 ( struct V_1 * V_2 , int V_25 , int V_26 )
{
return F_16 ( V_20 ,
F_10 ( V_20 ) ,
V_25 , V_26 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
int V_25 , int V_26 )
{
int V_23 = F_7 ( V_2 ) ;
return F_16 ( V_24 [ V_23 ] ,
F_10 ( V_24 [ 0 ] ) , V_25 , V_26 ) ;
}
static int F_19 ( struct V_1 * V_2 , int * V_27 , int * V_28 )
{
int V_23 , V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_29 ) ;
if ( V_4 < 0 )
return V_4 ;
V_23 = F_7 ( V_2 ) ;
V_4 &= V_30 ;
* V_27 = V_24 [ V_23 ] [ V_4 ] [ 0 ] ;
* V_28 = V_24 [ V_23 ] [ V_4 ] [ 1 ] ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 ,
struct V_31 const * V_32 ,
int * V_25 , int * V_26 , long V_33 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
T_1 V_34 [ 3 ] ;
int V_23 , V_4 ;
switch ( V_33 ) {
case V_35 :
if ( F_21 ( V_22 ) )
return - V_36 ;
F_22 ( & V_2 -> V_37 ) ;
V_4 = F_5 ( V_2 , V_34 ) ;
F_23 ( & V_2 -> V_37 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_25 = F_24 ( F_25 ( V_34 [ V_32 -> V_38 ] ) >> 4 ,
11 ) ;
return V_39 ;
case V_40 :
V_23 = V_2 -> V_41 & V_42 ;
* V_25 = V_20 [ V_23 ] [ 0 ] ;
* V_26 = V_20 [ V_23 ] [ 1 ] ;
return V_43 ;
case V_44 :
V_23 = F_7 ( V_2 ) ;
* V_25 = V_19 [ V_23 ] [ 0 ] ;
* V_26 = V_19 [ V_23 ] [ 1 ] ;
return V_43 ;
case V_45 :
V_4 = F_2 ( V_2 -> V_5 ,
V_46 + V_32 -> V_38 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_25 = F_24 ( V_4 , 7 ) ;
return V_39 ;
case V_47 :
if ( V_2 -> V_41 & V_48 ) {
V_4 = F_19 ( V_2 , V_25 , V_26 ) ;
if ( V_4 < 0 )
return V_4 ;
} else {
* V_25 = 0 ;
* V_26 = 0 ;
}
return V_43 ;
}
return - V_49 ;
}
static int F_26 ( struct V_1 * V_2 )
{
return F_27 ( V_2 -> V_5 , V_50 ,
V_2 -> V_13 & ~ V_51 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
return F_27 ( V_2 -> V_5 , V_50 ,
V_2 -> V_13 ) ;
}
static int F_29 ( struct V_1 * V_2 , V_12 V_52 , V_12 V_25 )
{
int V_4 ;
F_22 ( & V_2 -> V_37 ) ;
V_4 = F_26 ( V_2 ) ;
if ( V_4 < 0 )
goto V_53;
V_4 = F_27 ( V_2 -> V_5 , V_52 , V_25 ) ;
if ( V_4 < 0 )
goto V_53;
V_4 = F_28 ( V_2 ) ;
if ( V_4 < 0 )
goto V_53;
V_4 = 0 ;
V_53:
F_23 ( & V_2 -> V_37 ) ;
return V_4 ;
}
static int F_30 ( struct V_1 * V_2 ,
int V_25 , int V_26 )
{
int V_23 , V_52 ;
V_23 = F_18 ( V_2 , V_25 , V_26 ) ;
if ( V_23 < 0 )
return V_23 ;
V_52 = F_2 ( V_2 -> V_5 ,
V_29 ) ;
if ( V_52 < 0 )
return V_52 ;
V_52 &= ~ V_30 ;
V_52 |= V_23 ;
return F_29 ( V_2 , V_29 , V_52 ) ;
}
static int F_31 ( struct V_21 * V_22 ,
struct V_31 const * V_32 ,
int V_25 , int V_26 , long V_33 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_23 , V_4 ;
if ( F_21 ( V_22 ) )
return - V_36 ;
switch ( V_33 ) {
case V_44 :
V_23 = F_15 ( V_2 , V_25 , V_26 ) ;
if ( V_23 < 0 )
return V_23 ;
V_2 -> V_13 &= ~ V_14 ;
V_2 -> V_13 |= V_23 << V_15 ;
return F_29 ( V_2 , V_50 ,
V_2 -> V_13 ) ;
case V_40 :
V_23 = F_17 ( V_2 , V_25 , V_26 ) ;
if ( V_23 < 0 )
return V_23 ;
V_2 -> V_41 &= ~ V_42 ;
V_2 -> V_41 |= V_23 ;
return F_29 ( V_2 , V_54 ,
V_2 -> V_41 ) ;
case V_45 :
if ( V_25 < - 128 || V_25 > 127 )
return - V_49 ;
return F_29 ( V_2 ,
V_46 + V_32 -> V_38 ,
V_25 ) ;
case V_47 :
if ( V_25 == 0 && V_26 == 0 ) {
V_2 -> V_41 &= ~ V_48 ;
} else {
V_2 -> V_41 |= V_48 ;
V_4 = F_30 ( V_2 , V_25 , V_26 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_29 ( V_2 , V_54 ,
V_2 -> V_41 ) ;
default:
return - V_49 ;
}
}
static int F_32 ( struct V_21 * V_22 ,
const struct V_31 * V_32 ,
enum V_55 type ,
enum V_56 V_57 ,
enum V_58 V_59 ,
int * V_25 , int * V_26 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_4 , V_60 ;
switch ( V_59 ) {
case V_61 :
V_4 = F_2 ( V_2 -> V_5 ,
V_62 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_25 = V_4 & V_63 ;
return V_39 ;
case V_64 :
V_4 = F_2 ( V_2 -> V_5 ,
V_65 ) ;
if ( V_4 < 0 )
return V_4 ;
V_60 = V_4 * V_66 [
F_7 ( V_2 ) ] ;
* V_25 = V_60 / V_67 ;
* V_26 = V_60 % V_67 ;
return V_43 ;
case V_68 :
V_4 = F_2 ( V_2 -> V_5 ,
V_69 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_70 ) {
* V_25 = 0 ;
* V_26 = 0 ;
} else {
V_4 = F_19 ( V_2 , V_25 , V_26 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return V_43 ;
default:
return - V_49 ;
}
}
static int F_33 ( struct V_21 * V_22 ,
const struct V_31 * V_32 ,
enum V_55 type ,
enum V_56 V_57 ,
enum V_58 V_59 ,
int V_25 , int V_26 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_4 , V_52 , V_71 ;
switch ( V_59 ) {
case V_61 :
if ( V_25 < 0 || V_25 > V_63 )
return - V_49 ;
return F_29 ( V_2 , V_62 , V_25 ) ;
case V_64 :
V_71 = ( V_25 * V_67 + V_26 ) /
V_66 [
F_7 ( V_2 ) ] ;
if ( V_71 < 0 || V_71 > 0xff )
return - V_49 ;
return F_29 ( V_2 , V_65 ,
V_71 ) ;
case V_68 :
V_52 = F_2 ( V_2 -> V_5 ,
V_69 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( V_25 == 0 && V_26 == 0 ) {
V_52 |= V_70 ;
} else {
V_52 &= ~ V_70 ;
V_4 = F_30 ( V_2 , V_25 , V_26 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return F_29 ( V_2 , V_69 , V_52 ) ;
default:
return - V_49 ;
}
}
static int F_34 ( struct V_21 * V_22 ,
const struct V_31 * V_32 ,
enum V_55 type ,
enum V_56 V_57 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_69 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_4 & F_35 ( V_32 -> V_38 ) ? 1 : 0 ;
}
static int F_36 ( struct V_21 * V_22 ,
const struct V_31 * V_32 ,
enum V_55 type ,
enum V_56 V_57 ,
int V_72 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_25 ;
V_25 = F_2 ( V_2 -> V_5 , V_69 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_72 )
V_25 |= F_35 ( V_32 -> V_38 ) ;
else
V_25 &= ~ F_35 ( V_32 -> V_38 ) ;
V_25 |= V_73 ;
return F_29 ( V_2 , V_69 , V_25 ) ;
}
static void F_37 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
T_3 V_74 = F_38 () ;
int V_75 ;
V_75 = F_2 ( V_2 -> V_5 , V_76 ) ;
if ( V_75 < 0 )
return;
if ( V_75 & V_77 )
F_39 ( V_22 ,
F_40 ( V_78 , 0 , V_79 ,
V_80 ,
V_81 ) ,
V_74 ) ;
if ( V_75 & V_82 )
F_39 ( V_22 ,
F_40 ( V_78 , 0 , V_83 ,
V_80 ,
V_81 ) ,
V_74 ) ;
if ( V_75 & V_84 )
F_39 ( V_22 ,
F_40 ( V_78 , 0 , V_85 ,
V_80 ,
V_81 ) ,
V_74 ) ;
}
static T_4 F_41 ( int V_86 , void * V_87 )
{
struct V_21 * V_22 = V_87 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_4 = V_88 ;
int V_75 ;
V_75 = F_2 ( V_2 -> V_5 , V_89 ) ;
if ( V_75 < 0 )
return V_88 ;
if ( V_75 & V_90 ) {
F_42 ( V_22 -> V_91 ) ;
V_4 = V_92 ;
}
if ( V_75 & V_93 ) {
F_37 ( V_22 ) ;
V_4 = V_92 ;
}
return V_4 ;
}
static T_4 F_43 ( int V_86 , void * V_87 )
{
struct V_94 * V_95 = V_87 ;
struct V_21 * V_22 = V_95 -> V_22 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
V_12 V_34 [ 16 ] ;
int V_4 ;
V_4 = F_5 ( V_2 , ( T_1 * ) V_34 ) ;
if ( V_4 < 0 )
goto V_96;
F_44 ( V_22 , V_34 ,
F_38 () ) ;
V_96:
F_45 ( V_22 -> V_91 ) ;
return V_92 ;
}
static int F_46 ( struct V_21 * V_22 ,
unsigned V_52 , unsigned V_97 ,
unsigned * V_98 )
{
int V_4 ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
if ( V_52 > V_99 )
return - V_49 ;
if ( ! V_98 )
return F_29 ( V_2 , V_52 , V_97 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_52 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_98 = V_4 ;
return 0 ;
}
static int F_47 ( struct V_100 * V_91 ,
bool V_72 )
{
struct V_21 * V_22 = F_48 ( V_91 ) ;
struct V_1 * V_2 = F_14 ( V_22 ) ;
int V_52 ;
V_52 = F_2 ( V_2 -> V_5 , V_101 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( V_72 )
V_52 |= V_90 ;
else
V_52 &= ~ V_90 ;
return F_29 ( V_2 , V_101 , V_52 ) ;
}
static int F_49 ( struct V_100 * V_91 ,
struct V_21 * V_22 )
{
struct V_21 * V_102 = F_48 ( V_91 ) ;
if ( V_102 != V_22 )
return - V_49 ;
return 0 ;
}
static int F_50 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 ) ;
struct V_100 * V_91 ;
int V_4 ;
V_91 = F_51 ( & V_2 -> V_5 -> V_8 , L_2 ,
V_22 -> V_103 ,
V_22 -> V_104 ) ;
if ( ! V_91 )
return - V_105 ;
V_91 -> V_8 . V_106 = & V_2 -> V_5 -> V_8 ;
V_91 -> V_107 = & V_108 ;
F_52 ( V_91 , V_22 ) ;
V_4 = F_53 ( V_91 ) ;
if ( V_4 )
return V_4 ;
V_22 -> V_91 = V_91 ;
return 0 ;
}
static void F_54 ( struct V_21 * V_22 )
{
if ( V_22 -> V_91 )
F_55 ( V_22 -> V_91 ) ;
}
static int F_56 ( struct V_109 * V_5 )
{
int V_23 ;
int V_4 ;
V_4 = F_27 ( V_5 , V_110 ,
V_111 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_23 = 0 ; V_23 < 10 ; V_23 ++ ) {
F_57 ( 100 , 200 ) ;
V_4 = F_2 ( V_5 , V_110 ) ;
if ( V_4 == - V_9 )
continue;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_4 & V_111 ) )
return 0 ;
}
return - V_112 ;
}
static int F_58 ( struct V_109 * V_5 ,
const struct V_113 * V_104 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
int V_4 ;
V_4 = F_2 ( V_5 , V_114 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 != V_115 )
return - V_116 ;
V_22 = F_59 ( & V_5 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_22 )
return - V_105 ;
V_2 = F_14 ( V_22 ) ;
V_2 -> V_5 = V_5 ;
F_60 ( & V_2 -> V_37 ) ;
F_61 ( V_5 , V_22 ) ;
V_22 -> V_59 = & V_117 ;
V_22 -> V_103 = V_104 -> V_103 ;
V_22 -> V_8 . V_106 = & V_5 -> V_8 ;
V_22 -> V_118 = V_119 ;
V_22 -> V_120 = V_121 ;
V_22 -> V_122 = F_10 ( V_121 ) ;
V_22 -> V_123 = V_124 ;
V_4 = F_56 ( V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_41 = V_125 ;
V_4 = F_27 ( V_5 , V_54 ,
V_2 -> V_41 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_27 ( V_5 , V_62 ,
V_63 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_5 -> V_86 ) {
int V_126 = V_90 | V_93 ;
int V_127 = V_93 ;
V_4 = F_27 ( V_5 ,
V_128 ,
V_126 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_27 ( V_5 ,
V_101 ,
V_127 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_50 ( V_22 ) ;
if ( V_4 < 0 )
return V_4 ;
}
V_2 -> V_13 = V_51 |
( V_129 << V_15 ) ;
V_4 = F_27 ( V_5 , V_50 ,
V_2 -> V_13 ) ;
if ( V_4 < 0 )
goto V_130;
V_4 = F_62 ( V_22 , NULL ,
F_43 , NULL ) ;
if ( V_4 < 0 )
goto V_130;
if ( V_5 -> V_86 ) {
V_4 = F_63 ( & V_5 -> V_8 ,
V_5 -> V_86 ,
NULL , F_41 ,
V_131 | V_132 ,
V_5 -> V_103 , V_22 ) ;
if ( V_4 )
goto V_133;
}
V_4 = F_64 ( V_22 ) ;
if ( V_4 < 0 )
goto V_133;
return 0 ;
V_133:
F_65 ( V_22 ) ;
V_130:
F_54 ( V_22 ) ;
return V_4 ;
}
static int F_66 ( struct V_109 * V_5 )
{
struct V_21 * V_22 = F_67 ( V_5 ) ;
F_68 ( V_22 ) ;
F_65 ( V_22 ) ;
F_54 ( V_22 ) ;
F_26 ( F_14 ( V_22 ) ) ;
return 0 ;
}
static int F_69 ( struct V_16 * V_8 )
{
return F_26 ( F_14 ( F_67 (
F_70 ( V_8 ) ) ) ) ;
}
static int F_71 ( struct V_16 * V_8 )
{
return F_28 ( F_14 ( F_67 (
F_70 ( V_8 ) ) ) ) ;
}
