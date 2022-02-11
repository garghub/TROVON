static unsigned int F_1 ( const int V_1 [] , int V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 - 1 ; V_4 ++ )
if ( V_3 <= V_1 [ V_4 ] )
return V_4 ;
return ( V_2 - 1 ) ;
}
static int F_2 ( struct V_5 * V_6 ,
enum V_7 V_8 ,
const int V_1 [] , int V_2 , int * V_9 )
{
unsigned int V_3 ;
int V_10 ;
V_10 = F_3 ( V_6 -> V_11 [ V_8 ] , & V_3 ) ;
if ( V_10 )
return V_10 ;
V_3 = ( V_3 >= V_2 ) ? ( V_2 - 1 ) : V_3 ;
* V_9 = V_1 [ V_3 ] ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
enum V_7 V_8 ,
const int V_1 [] , int V_2 , int V_9 )
{
unsigned int V_12 = F_1 ( V_1 , V_2 , V_9 ) ;
return F_5 ( V_6 -> V_11 [ V_8 ] , V_12 ) ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
unsigned int V_3 ;
int V_10 , V_16 = 100 ;
V_10 = F_5 ( V_6 -> V_11 [ V_17 ] , 0x01 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_1 ) ;
return V_10 ;
}
do {
V_10 = F_3 ( V_6 -> V_11 [ V_17 ] , & V_3 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_2 ) ;
return V_10 ;
}
if ( ! V_3 )
break;
F_8 ( 10 , 100 ) ;
} while ( -- V_16 );
if ( ! V_16 )
return - V_18 ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 ,
union V_19 * V_9 )
{
unsigned int V_3 , V_20 ;
int V_10 ;
V_10 = F_3 ( V_6 -> V_11 [ V_21 ] ,
& V_20 ) ;
if ( V_10 ) {
F_7 ( & V_6 -> V_15 -> V_14 , L_3 ) ;
return V_10 ;
}
if ( ! V_20 ) {
V_9 -> V_22 = V_23 ;
return 0 ;
}
V_10 = F_3 ( V_6 -> V_11 [ V_24 ] , & V_3 ) ;
if ( V_10 ) {
F_7 ( & V_6 -> V_15 -> V_14 , L_4 ) ;
return V_10 ;
}
switch ( V_3 ) {
case 0 :
V_9 -> V_22 = V_25 ;
return 0 ;
case 1 :
V_9 -> V_22 = V_26 ;
return 0 ;
case 2 :
V_9 -> V_22 = V_27 ;
return 0 ;
default:
V_9 -> V_22 = V_28 ;
return 0 ;
}
}
static int F_10 ( struct V_5 * V_6 ,
union V_19 * V_9 )
{
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
unsigned int V_3 ;
int V_10 ;
V_9 -> V_22 = V_29 ;
V_10 = F_11 ( V_6 -> V_30 , V_31 , & V_3 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_5 ) ;
return V_10 ;
}
if ( V_3 & F_12 ( V_32 ) ) {
V_9 -> V_22 = V_33 ;
return 0 ;
}
if ( V_3 & F_12 ( V_34 ) ) {
V_9 -> V_22 = V_35 ;
return 0 ;
}
if ( V_3 & F_12 ( V_36 ) ) {
V_9 -> V_22 = V_37 ;
return 0 ;
}
V_10 = F_11 ( V_6 -> V_30 , V_38 , & V_3 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_6 ) ;
return V_10 ;
}
if ( V_3 & F_12 ( V_39 ) ) {
V_9 -> V_22 = V_37 ;
return 0 ;
}
if ( V_3 & F_12 ( V_40 ) ) {
V_9 -> V_22 = V_41 ;
return 0 ;
}
V_10 = F_11 ( V_6 -> V_30 , V_42 , & V_3 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_7 ) ;
return V_10 ;
}
if ( V_3 & F_12 ( V_43 ) ) {
V_9 -> V_22 = V_37 ;
return 0 ;
}
if ( V_3 & F_12 ( V_44 ) ) {
V_9 -> V_22 = V_35 ;
return 0 ;
}
if ( V_3 & F_12 ( V_45 ) ) {
V_9 -> V_22 = V_37 ;
return 0 ;
}
if ( V_3 & F_12 ( V_46 ) ) {
V_9 -> V_22 = V_41 ;
return 0 ;
}
V_10 = F_3 ( V_6 -> V_11 [ V_24 ] , & V_3 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_4 ) ;
return V_10 ;
}
if ( V_3 == V_47 ) {
V_9 -> V_22 = V_37 ;
return 0 ;
}
return 0 ;
}
static int F_13 ( struct V_5 * V_6 ,
union V_19 * V_9 )
{
unsigned int V_3 ;
int V_10 ;
V_10 = F_3 ( V_6 -> V_11 [ V_36 ] , & V_3 ) ;
if ( V_10 ) {
F_7 ( & V_6 -> V_15 -> V_14 , L_8 ) ;
return V_10 ;
}
V_9 -> V_22 = ! V_3 ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 ,
union V_19 * V_9 )
{
unsigned int V_3 ;
int V_10 ;
V_10 = F_3 ( V_6 -> V_11 [ V_21 ] , & V_3 ) ;
if ( V_10 ) {
F_7 ( & V_6 -> V_15 -> V_14 , L_3 ) ;
return V_10 ;
}
V_9 -> V_22 = ( int ) V_3 ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
union V_19 * V_9 )
{
int V_48 ;
int V_10 ;
V_10 = F_2 ( V_6 , V_49 ,
V_50 ,
F_16 ( V_50 ) ,
& V_48 ) ;
if ( V_10 ) {
F_7 ( & V_6 -> V_15 -> V_14 , L_9 ) ;
return V_10 ;
}
V_9 -> V_22 = V_48 ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
union V_19 * V_9 )
{
int V_12 = F_16 ( V_50 ) - 1 ;
V_9 -> V_22 = V_50 [ V_12 ] ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 ,
union V_19 * V_9 )
{
int V_51 ;
int V_10 ;
V_10 = F_2 ( V_6 , V_52 ,
V_53 ,
F_16 ( V_53 ) ,
& V_51 ) ;
if ( V_10 ) {
F_7 ( & V_6 -> V_15 -> V_14 , L_10 ) ;
return V_10 ;
}
V_9 -> V_22 = V_51 ;
return 0 ;
}
static int F_19 ( struct V_5 * V_6 ,
union V_19 * V_9 )
{
int V_12 = F_16 ( V_54 ) - 1 ;
V_9 -> V_22 = V_54 [ V_12 ] ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
union V_19 * V_9 )
{
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
int V_55 , V_56 , V_10 ;
V_10 = F_2 ( V_6 , V_49 ,
V_50 ,
F_16 ( V_50 ) ,
& V_55 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_9 ) ;
return V_10 ;
}
V_10 = F_2 ( V_6 , V_57 ,
V_58 ,
F_16 ( V_58 ) ,
& V_56 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_11 ) ;
return V_10 ;
}
V_9 -> V_22 = V_55 * V_56 / 100 ;
return 0 ;
}
static int F_21 ( struct V_59 * V_60 ,
enum V_61 V_62 ,
union V_19 * V_9 )
{
struct V_5 * V_6 = F_22 ( V_60 ) ;
switch ( V_62 ) {
case V_63 :
return F_9 ( V_6 , V_9 ) ;
case V_64 :
return F_10 ( V_6 , V_9 ) ;
case V_65 :
return F_13 ( V_6 , V_9 ) ;
case V_66 :
return F_14 ( V_6 , V_9 ) ;
case V_67 :
return F_15 ( V_6 , V_9 ) ;
case V_68 :
return F_17 ( V_6 , V_9 ) ;
case V_69 :
return F_18 ( V_6 , V_9 ) ;
case V_70 :
return F_19 ( V_6 , V_9 ) ;
case V_71 :
V_9 -> V_22 = V_72 ;
return 0 ;
case V_73 :
return F_20 ( V_6 , V_9 ) ;
case V_74 :
V_9 -> V_75 = V_76 ;
return 0 ;
case V_77 :
V_9 -> V_75 = V_78 ;
return 0 ;
default:
return - V_79 ;
}
}
static int F_23 ( struct V_5 * V_6 , T_1 V_55 ,
T_1 V_56 ,
T_1 V_80 , T_1 V_81 )
{
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
int V_12 , V_10 ;
V_10 = F_6 ( V_6 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_12 ) ;
return V_10 ;
}
V_10 = F_5 ( V_6 -> V_11 [ V_82 ] , 1 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_13 ) ;
return V_10 ;
}
V_10 = F_5 ( V_6 -> V_11 [ V_83 ] , 1 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_14 ) ;
return V_10 ;
}
V_10 = F_5 ( V_6 -> V_11 [ V_84 ] , 1 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_15 ) ;
return V_10 ;
}
V_10 = F_5 ( V_6 -> V_11 [ V_85 ] , 0x00 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_16 ) ;
return V_10 ;
}
V_10 = F_4 ( V_6 , V_49 ,
V_50 ,
F_16 ( V_50 ) , V_55 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_17 ) ;
return V_10 ;
}
V_10 = F_4 ( V_6 , V_57 ,
V_58 ,
F_16 ( V_58 ) ,
V_56 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_18 ) ;
return V_10 ;
}
V_10 = F_4 ( V_6 , V_52 ,
V_53 ,
F_16 ( V_53 ) ,
V_6 -> V_86 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_19 ) ;
return V_10 ;
}
V_12 = F_16 ( V_54 ) - 1 ;
V_10 = F_4 ( V_6 , V_87 ,
V_54 ,
F_16 ( V_54 ) ,
V_54 [ V_12 ] ) ;
if ( V_10 ) {
F_7 ( V_14 , L_20 ) ;
return V_10 ;
}
if ( V_80 == - 1 )
V_80 = 4500000 ;
V_10 = F_4 ( V_6 , V_88 ,
V_89 ,
F_16 ( V_89 ) , V_80 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_21 ) ;
return V_10 ;
}
if ( V_81 == - 1 )
V_81 = 500000 ;
V_10 = F_4 ( V_6 , V_90 ,
V_91 ,
F_16 ( V_91 ) , V_81 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_22 ) ;
return V_10 ;
}
V_10 = F_5 ( V_6 -> V_11 [ V_92 ] , 0x01 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_23 ) ;
return V_10 ;
}
V_10 = F_5 ( V_6 -> V_11 [ V_93 ] , 0x01 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_24 ) ;
return V_10 ;
}
return 0 ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
int V_10 ;
V_10 = F_4 ( V_6 , V_52 ,
V_94 ,
F_16 ( V_94 ) ,
V_6 -> V_95 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_25 ) ;
return V_10 ;
}
return 0 ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
int V_10 ;
V_10 = F_4 ( V_6 , V_52 ,
V_53 ,
F_16 ( V_53 ) ,
V_6 -> V_86 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_19 ) ;
return V_10 ;
}
return 0 ;
}
static int F_26 ( struct V_5 * V_6 ,
bool * V_96 ,
bool * V_97 )
{
unsigned int V_98 , V_99 , V_100 ;
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
bool V_101 = false ;
bool V_102 = false ;
int V_10 ;
V_10 = F_11 ( V_6 -> V_30 , V_31 , & V_98 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_5 ) ;
return V_10 ;
}
V_10 = F_11 ( V_6 -> V_30 , V_103 , & V_99 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_26 ) ;
return V_10 ;
}
if ( V_98 & F_12 ( V_32 ) ) {
F_7 ( V_14 , L_27 ) ;
V_102 = true ;
}
if ( V_98 & F_12 ( V_34 ) ) {
F_7 ( V_14 , L_28 ) ;
V_102 = true ;
}
if ( V_98 & F_12 ( V_36 ) ) {
F_7 ( V_14 , L_29 ) ;
V_101 = true ;
V_102 = true ;
if ( ( V_99 & F_12 ( V_104 ) ) == 0 ) {
V_10 = F_5 ( V_6 -> V_11 [ V_104 ] ,
0x01 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_30 ) ;
return V_10 ;
}
}
V_10 = F_11 ( V_6 -> V_30 , V_105 , & V_100 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_31 ) ;
return V_10 ;
}
if ( V_100 & F_12 ( V_106 ) ) {
V_10 = F_5 (
V_6 -> V_11 [ V_106 ] , 0x00 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_32 ) ;
return V_10 ;
}
}
if ( V_100 & F_12 ( V_107 ) ) {
V_10 = F_5 (
V_6 -> V_11 [ V_107 ] , 0x00 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_33 ) ;
return V_10 ;
}
}
F_27 ( & V_6 -> V_108 ) ;
F_28 ( V_109 ,
& V_6 -> V_110 ,
V_111 * V_112 ) ;
}
* V_96 = V_101 ;
if ( V_102 )
* V_97 = V_102 ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 ,
bool V_101 ,
bool * V_97 )
{
unsigned int V_113 , V_100 ;
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
bool V_102 = false ;
int V_10 ;
V_10 = F_11 ( V_6 -> V_30 , V_38 , & V_113 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_6 ) ;
return V_10 ;
}
V_10 = F_11 ( V_6 -> V_30 , V_105 , & V_100 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_31 ) ;
return V_10 ;
}
if ( V_113 & F_12 ( V_114 ) ) {
F_30 ( V_14 , L_34 ) ;
F_28 ( V_109 ,
& V_6 -> V_115 ,
V_116 * V_112 ) ;
}
if ( V_113 & F_12 ( V_39 ) ) {
F_7 ( V_14 , L_35 ) ;
V_102 = true ;
}
if ( V_113 & F_12 ( V_117 ) ) {
F_30 ( V_14 , L_36 ) ;
if ( ! V_101 ) {
if ( ( V_100 & F_12 ( V_106 ) ) == 0 ) {
V_10 = F_5 (
V_6 -> V_11 [ V_106 ] , 0x01 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_37 ) ;
return V_10 ;
}
V_100 = V_100 | F_12 ( V_106 ) ;
}
F_27 ( & V_6 -> V_108 ) ;
V_102 = true ;
}
}
if ( V_113 & F_12 ( V_118 ) ) {
F_30 ( V_14 , L_38 ) ;
V_10 = F_5 ( V_6 -> V_11 [ V_119 ] ,
V_120 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_39 ) ;
return V_10 ;
}
if ( V_100 & F_12 ( V_106 ) ) {
V_10 = F_5 (
V_6 -> V_11 [ V_106 ] , 0x00 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_32 ) ;
return V_10 ;
}
V_100 = V_100 & ~ F_12 ( V_106 ) ;
}
if ( ! V_101 ) {
F_28 ( V_109 ,
& V_6 -> V_108 ,
V_121 * V_112 ) ;
V_102 = true ;
}
}
if ( V_113 & F_12 ( V_40 ) ) {
F_7 ( V_14 , L_40 ) ;
V_102 = true ;
}
if ( V_113 & F_12 ( V_122 ) ) {
F_31 ( V_14 ,
L_41 ) ;
V_102 = true ;
}
if ( V_113 & F_12 ( V_123 ) ) {
F_30 ( V_14 ,
L_42 ) ;
}
if ( V_102 )
* V_97 = V_102 ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
bool * V_97 )
{
unsigned int V_124 , V_125 ;
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
bool V_102 = false ;
int V_10 ;
V_10 = F_11 ( V_6 -> V_30 , V_42 , & V_124 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_7 ) ;
return V_10 ;
}
V_10 = F_11 ( V_6 -> V_30 , V_126 , & V_125 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_43 ) ;
return V_10 ;
}
if ( V_124 & F_12 ( V_43 ) ) {
F_7 ( V_14 , L_44 ) ;
V_102 = true ;
}
if ( V_124 & F_12 ( V_44 ) ) {
F_7 ( V_14 , L_45 ) ;
V_102 = true ;
}
if ( V_124 & F_12 ( V_45 ) ) {
F_7 ( V_14 , L_46 ) ;
V_102 = true ;
}
if ( V_124 & F_12 ( V_46 ) ) {
F_7 ( V_14 , L_47 ) ;
V_102 = true ;
}
if ( V_102 ) {
F_33 ( V_14 , L_48 ) ;
V_10 = F_25 ( V_6 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_49 ) ;
return V_10 ;
}
V_10 = F_5 ( V_6 -> V_11 [ V_127 ] ,
V_128 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_50 ) ;
return V_10 ;
}
* V_97 = V_102 ;
}
return 0 ;
}
static T_2 F_34 ( int V_129 , void * V_130 )
{
struct V_5 * V_6 = V_130 ;
struct V_13 * V_14 ;
bool V_102 = false ;
bool V_101 = false ;
unsigned int V_131 ;
int V_10 ;
if ( ! V_6 )
return V_132 ;
V_14 = & V_6 -> V_15 -> V_14 ;
if ( V_129 != V_6 -> V_15 -> V_129 ) {
F_7 ( V_14 , L_51 ) ;
return V_132 ;
}
V_10 = F_3 ( V_6 -> V_11 [ V_24 ] , & V_131 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_4 ) ;
return V_133 ;
}
F_30 ( V_14 , L_52 , V_131 ) ;
V_10 = F_26 ( V_6 , & V_101 ,
& V_102 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_53 ) ;
return V_133 ;
}
V_10 = F_29 ( V_6 , V_101 ,
& V_102 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_54 ) ;
return V_133 ;
}
V_10 = F_32 ( V_6 , & V_102 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_55 ) ;
return V_133 ;
}
if ( V_102 ) {
if ( V_6 -> V_134 )
F_35 ( V_6 -> V_134 ) ;
}
return V_133 ;
}
static int F_36 ( struct V_5 * V_6 , T_1 * V_55 ,
T_1 * V_56 ,
T_1 * V_80 , T_1 * V_81 )
{
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
int V_10 ;
if ( ! V_14 -> V_135 && ! F_37 ( V_14 ) ) {
F_7 ( V_14 , L_56 ) ;
return - V_136 ;
}
V_10 = F_38 ( V_14 , L_57 ,
V_55 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_58 ) ;
return V_10 ;
}
V_10 = F_38 ( V_14 , L_59 ,
V_56 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_60 ) ;
return V_10 ;
}
V_10 = F_38 ( V_14 ,
L_61 ,
& V_6 -> V_86 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_62 ) ;
return V_10 ;
}
V_10 = F_38 ( V_14 , L_63 ,
& V_6 -> V_95 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_64 ) ;
return V_10 ;
}
F_38 ( V_14 , L_65 ,
V_80 ) ;
F_38 ( V_14 , L_66 ,
V_81 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 ,
T_3 V_137 , T_3 V_81 )
{
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
int V_10 ;
if ( V_137 == V_138 ) {
V_10 = F_25 ( V_6 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_49 ) ;
return V_10 ;
}
F_30 ( V_14 , L_67 ) ;
V_10 = F_5 ( V_6 -> V_11 [ V_127 ] ,
V_128 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_50 ) ;
return V_139 ;
}
}
F_30 ( V_14 , L_68 ) ;
if ( V_81 != V_140 ) {
V_10 = F_5 ( V_6 -> V_11 [ V_90 ] ,
V_140 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_22 ) ;
return V_139 ;
}
}
return V_141 ;
}
static int F_40 ( struct V_5 * V_6 ,
T_3 V_137 , T_3 V_81 )
{
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
int V_10 ;
if ( V_137 == V_138 ) {
V_10 = F_25 ( V_6 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_49 ) ;
return V_10 ;
}
F_30 ( V_14 , L_69 ) ;
V_10 = F_5 ( V_6 -> V_11 [ V_127 ] ,
V_128 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_50 ) ;
return V_139 ;
}
}
F_30 ( V_14 , L_70 ) ;
if ( V_81 != V_142 ) {
V_10 = F_5 ( V_6 -> V_11 [ V_90 ] ,
V_142 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_22 ) ;
return V_139 ;
}
}
return V_141 ;
}
static int F_41 ( struct V_5 * V_6 ,
T_3 V_137 , T_3 V_81 )
{
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
int V_10 ;
if ( V_137 == V_128 ) {
V_10 = F_24 ( V_6 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_71 ) ;
return V_10 ;
}
F_30 ( V_14 , L_72 ) ;
V_10 = F_5 ( V_6 -> V_11 [ V_127 ] ,
V_138 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_73 ) ;
return V_139 ;
}
}
F_30 ( V_14 , L_74 ) ;
if ( V_81 != V_140 ) {
V_10 = F_5 ( V_6 -> V_11 [ V_90 ] ,
V_140 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_22 ) ;
return V_139 ;
}
}
return V_141 ;
}
static int F_42 ( struct V_5 * V_6 ,
T_3 V_137 , T_3 V_81 )
{
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
int V_10 ;
if ( V_137 == V_138 ) {
V_10 = F_25 ( V_6 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_49 ) ;
return V_10 ;
}
F_30 ( V_14 , L_75 ) ;
V_10 = F_5 ( V_6 -> V_11 [ V_127 ] ,
V_128 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_50 ) ;
return V_139 ;
}
}
F_30 ( V_14 , L_76 ) ;
if ( V_81 != V_143 ) {
V_10 = F_5 ( V_6 -> V_11 [ V_90 ] ,
V_143 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_22 ) ;
return V_139 ;
}
}
return V_141 ;
}
static int F_43 ( struct V_144 * V_145 ,
unsigned long V_146 , void * V_147 )
{
struct V_5 * V_6 = F_44 ( V_145 , struct V_5 , V_145 ) ;
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
unsigned int V_137 , V_81 ;
int V_10 ;
V_10 = F_3 ( V_6 -> V_11 [ V_127 ] ,
& V_137 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_77 ) ;
return V_139 ;
}
V_10 = F_3 ( V_6 -> V_11 [ V_90 ] ,
& V_81 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_78 ) ;
return V_139 ;
}
F_30 ( V_14 , L_79 , V_146 ) ;
switch ( V_146 ) {
case V_148 :
return F_39 ( V_6 , V_137 , V_81 ) ;
case V_149 :
return F_40 ( V_6 , V_137 , V_81 ) ;
case V_150 :
return F_41 ( V_6 , V_137 , V_81 ) ;
case V_151 :
return F_42 ( V_6 , V_137 , V_81 ) ;
default:
F_7 ( V_14 , L_80 ) ;
}
return V_139 ;
}
static void F_45 ( struct V_152 * V_153 )
{
struct V_5 * V_6 = F_44 ( V_153 , struct V_5 ,
V_115 . V_153 ) ;
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
unsigned int V_20 ;
int V_10 ;
V_10 = F_3 ( V_6 -> V_11 [ V_21 ] , & V_20 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_3 ) ;
return;
}
switch ( V_20 ) {
case V_154 :
F_30 ( V_14 , L_81 ) ;
F_27 ( & V_6 -> V_108 ) ;
break;
case V_155 :
F_30 ( V_14 , L_82 ) ;
V_10 = F_5 ( V_6 -> V_11 [ V_119 ] ,
V_120 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_39 ) ;
return;
}
F_28 ( V_109 ,
& V_6 -> V_108 ,
V_121 * V_112 ) ;
break;
}
F_35 ( V_6 -> V_134 ) ;
}
static void F_46 ( struct V_152 * V_153 )
{
struct V_5 * V_6 = F_44 ( V_153 , struct V_5 ,
V_108 . V_153 ) ;
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
int V_10 ;
F_7 ( V_14 , L_83 ) ;
V_10 = F_5 ( V_6 -> V_11 [ V_119 ] ,
V_156 ) ;
if ( V_10 )
F_7 ( V_14 , L_84 ) ;
}
static void F_47 ( struct V_152 * V_153 )
{
struct V_5 * V_6 = F_44 ( V_153 , struct V_5 ,
V_110 . V_153 ) ;
struct V_13 * V_14 = & V_6 -> V_15 -> V_14 ;
unsigned int V_98 , V_99 ;
int V_10 ;
V_10 = F_11 ( V_6 -> V_30 , V_31 , & V_98 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_5 ) ;
return;
}
if ( V_98 & F_12 ( V_36 ) ) {
F_28 ( V_109 ,
& V_6 -> V_110 ,
V_111 * V_112 ) ;
} else {
F_28 ( V_109 ,
& V_6 -> V_108 ,
V_121 * V_112 ) ;
V_10 = F_11 ( V_6 -> V_30 , V_103 , & V_99 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_26 ) ;
return;
}
if ( V_99 & F_12 ( V_104 ) ) {
V_10 = F_5 ( V_6 -> V_11 [ V_104 ] ,
0x00 ) ;
if ( V_10 )
F_7 ( V_14 , L_85 ) ;
}
F_35 ( V_6 -> V_134 ) ;
}
}
static bool F_48 ( struct V_13 * V_14 , unsigned int V_157 )
{
switch ( V_157 ) {
case V_158 :
case V_31 :
case V_38 :
case V_42 :
return false ;
default:
return true ;
}
}
static bool F_49 ( struct V_13 * V_14 , unsigned int V_157 )
{
switch ( V_157 ) {
case V_158 :
case V_159 :
case V_160 :
return false ;
default:
return true ;
}
}
static int F_50 ( struct V_161 * V_15 ,
const struct V_162 * V_163 )
{
struct V_164 * V_165 = F_51 ( V_15 -> V_14 . V_166 ) ;
struct V_13 * V_14 = & V_15 -> V_14 ;
struct V_5 * V_6 ;
struct V_167 V_168 = {} ;
T_1 V_55 , V_56 ;
T_1 V_80 = - 1 , V_81 = - 1 ;
int V_4 , V_10 ;
if ( ! F_52 ( V_165 , V_169 ) ) {
F_7 ( V_14 , L_86 ) ;
return - V_170 ;
}
V_6 = F_53 ( V_14 , sizeof( * V_6 ) , V_171 ) ;
if ( ! V_6 )
return - V_172 ;
V_6 -> V_15 = V_15 ;
F_54 ( V_15 , V_6 ) ;
V_6 -> V_30 = F_55 ( V_15 ,
& V_173 ) ;
if ( F_56 ( V_6 -> V_30 ) ) {
F_7 ( V_14 , L_87 ) ;
return - V_136 ;
}
for ( V_4 = 0 ; V_4 < V_174 ; V_4 ++ ) {
V_6 -> V_11 [ V_4 ] =
F_57 ( V_14 , V_6 -> V_30 ,
V_175 [ V_4 ] ) ;
if ( F_56 ( V_6 -> V_11 [ V_4 ] ) ) {
F_7 ( V_14 ,
L_88 , V_4 ) ;
return F_58 ( V_6 -> V_11 [ V_4 ] ) ;
}
}
V_10 = F_36 ( V_6 , & V_55 , & V_56 ,
& V_80 , & V_81 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_89 ) ;
return V_10 ;
}
#if F_59 ( V_176 )
V_6 -> V_177 = F_60 ( V_14 , V_178 ) ;
if ( F_56 ( V_6 -> V_177 ) ) {
F_7 ( V_14 , L_90 ) ;
} else {
V_6 -> V_145 . V_179 = F_43 ;
V_10 = F_61 ( V_6 -> V_177 , & V_6 -> V_145 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_91 ) ;
V_6 -> V_145 . V_179 = NULL ;
}
}
#endif
F_62 ( & V_6 -> V_115 , F_45 ) ;
F_62 ( & V_6 -> V_108 ,
F_46 ) ;
F_62 ( & V_6 -> V_110 ,
F_47 ) ;
V_168 . V_135 = V_14 -> V_135 ;
V_168 . V_180 = V_6 ;
V_168 . V_181 = V_182 ;
V_168 . V_183 =
F_16 ( V_182 ) ;
V_10 = F_63 ( V_14 , V_15 -> V_129 , NULL ,
F_34 ,
V_184 | V_185 ,
V_186 , V_6 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_92 ) ;
goto V_187;
}
V_10 = F_23 ( V_6 , V_55 , V_56 , V_80 , V_81 ) ;
if ( V_10 ) {
F_7 ( V_14 , L_93 ) ;
goto V_187;
}
V_6 -> V_134 = F_64 ( V_14 , & V_188 ,
& V_168 ) ;
if ( F_56 ( V_6 -> V_134 ) ) {
F_7 ( V_14 , L_94 ) ;
V_10 = F_58 ( V_6 -> V_134 ) ;
goto V_187;
}
return 0 ;
V_187:
#if F_59 ( V_176 )
if ( V_6 -> V_145 . V_179 ) {
F_65 ( V_6 -> V_177 , & V_6 -> V_145 ) ;
V_6 -> V_145 . V_179 = NULL ;
}
#endif
return V_10 ;
}
static int F_66 ( struct V_161 * V_15 )
{
int V_10 ;
struct V_5 * V_6 = F_67 ( V_15 ) ;
V_10 = F_6 ( V_6 ) ;
if ( V_10 )
F_7 ( & V_6 -> V_15 -> V_14 , L_93 ) ;
#if F_59 ( V_176 )
if ( V_6 -> V_145 . V_179 )
F_65 ( V_6 -> V_177 , & V_6 -> V_145 ) ;
#endif
F_27 ( & V_6 -> V_115 ) ;
F_27 ( & V_6 -> V_108 ) ;
F_27 ( & V_6 -> V_110 ) ;
return V_10 ;
}
