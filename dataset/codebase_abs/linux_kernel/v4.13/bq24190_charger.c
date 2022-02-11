static T_1 F_1 ( const int V_1 [] , int V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 1 ; V_4 < V_2 ; V_4 ++ )
if ( V_3 < V_1 [ V_4 ] )
break;
return V_4 - 1 ;
}
static int F_2 ( struct V_5 * V_6 , T_1 V_7 , T_1 * V_8 )
{
int V_9 ;
V_9 = F_3 ( V_6 -> V_10 , V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_8 = V_9 ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 , T_1 V_7 , T_1 V_8 )
{
return F_5 ( V_6 -> V_10 , V_7 , V_8 ) ;
}
static int F_6 ( struct V_5 * V_6 , T_1 V_7 ,
T_1 V_11 , T_1 V_12 , T_1 * V_8 )
{
T_1 V_3 ;
int V_9 ;
V_9 = F_2 ( V_6 , V_7 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_3 &= V_11 ;
V_3 >>= V_12 ;
* V_8 = V_3 ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 , T_1 V_7 ,
T_1 V_11 , T_1 V_12 , T_1 V_8 )
{
T_1 V_3 ;
int V_9 ;
V_9 = F_2 ( V_6 , V_7 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_3 &= ~ V_11 ;
V_3 |= ( ( V_8 << V_12 ) & V_11 ) ;
return F_4 ( V_6 , V_7 , V_3 ) ;
}
static int F_8 ( struct V_5 * V_6 ,
T_1 V_7 , T_1 V_11 , T_1 V_12 ,
const int V_1 [] , int V_2 ,
int * V_13 )
{
T_1 V_3 ;
int V_9 ;
V_9 = F_6 ( V_6 , V_7 , V_11 , V_12 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_3 = ( V_3 >= V_2 ) ? ( V_2 - 1 ) : V_3 ;
* V_13 = V_1 [ V_3 ] ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 ,
T_1 V_7 , T_1 V_11 , T_1 V_12 ,
const int V_1 [] , int V_2 ,
int V_13 )
{
T_1 V_14 ;
V_14 = F_1 ( V_1 , V_2 , V_13 ) ;
return F_7 ( V_6 , V_7 , V_11 , V_12 , V_14 ) ;
}
static void F_10 ( void )
{
int V_4 , V_15 = F_11 ( V_16 ) ;
for ( V_4 = 0 ; V_4 < V_15 ; V_4 ++ )
V_17 [ V_4 ] = & V_16 [ V_4 ] . V_18 . V_18 ;
V_17 [ V_15 ] = NULL ;
}
static struct V_19 * F_12 (
const char * V_20 )
{
int V_4 , V_15 = F_11 ( V_16 ) ;
for ( V_4 = 0 ; V_4 < V_15 ; V_4 ++ )
if ( ! strcmp ( V_20 , V_16 [ V_4 ] . V_18 . V_18 . V_20 ) )
break;
if ( V_4 >= V_15 )
return NULL ;
return & V_16 [ V_4 ] ;
}
static T_2 F_13 ( struct V_21 * V_22 ,
struct V_23 * V_18 , char * V_24 )
{
struct V_25 * V_26 = F_14 ( V_22 ) ;
struct V_5 * V_6 = F_15 ( V_26 ) ;
struct V_19 * V_27 ;
T_2 V_28 ;
int V_9 ;
T_1 V_3 ;
V_27 = F_12 ( V_18 -> V_18 . V_20 ) ;
if ( ! V_27 )
return - V_29 ;
V_9 = F_16 ( V_6 -> V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_6 ( V_6 , V_27 -> V_7 , V_27 -> V_11 , V_27 -> V_12 , & V_3 ) ;
if ( V_9 )
V_28 = V_9 ;
else
V_28 = F_17 ( V_24 , V_30 , L_1 , V_3 ) ;
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
return V_28 ;
}
static T_2 F_20 ( struct V_21 * V_22 ,
struct V_23 * V_18 , const char * V_24 , T_3 V_28 )
{
struct V_25 * V_26 = F_14 ( V_22 ) ;
struct V_5 * V_6 = F_15 ( V_26 ) ;
struct V_19 * V_27 ;
int V_9 ;
T_1 V_3 ;
V_27 = F_12 ( V_18 -> V_18 . V_20 ) ;
if ( ! V_27 )
return - V_29 ;
V_9 = F_21 ( V_24 , 0 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_16 ( V_6 -> V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_7 ( V_6 , V_27 -> V_7 , V_27 -> V_11 , V_27 -> V_12 , V_3 ) ;
if ( V_9 )
V_28 = V_9 ;
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
return V_28 ;
}
static int F_22 ( struct V_5 * V_6 )
{
F_10 () ;
return F_23 ( & V_6 -> V_31 -> V_22 . V_32 ,
& V_33 ) ;
}
static void F_24 ( struct V_5 * V_6 )
{
F_25 ( & V_6 -> V_31 -> V_22 . V_32 , & V_33 ) ;
}
static int F_22 ( struct V_5 * V_6 )
{
return 0 ;
}
static inline void F_24 ( struct V_5 * V_6 ) {}
static int F_26 ( struct V_5 * V_6 )
{
int V_9 ;
T_1 V_3 ;
V_9 = F_2 ( V_6 , V_34 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_6 -> V_35 = ( ( V_3 & V_36 ) >>
V_37 ) ;
V_3 &= ~ V_36 ;
return F_4 ( V_6 , V_34 , V_3 ) ;
}
static int F_27 ( struct V_5 * V_6 )
{
int V_9 , V_15 = 100 ;
T_1 V_3 ;
if ( F_28 ( V_6 -> V_22 , L_2 ) )
return 0 ;
V_9 = F_7 ( V_6 , V_38 ,
V_39 ,
V_40 ,
0x1 ) ;
if ( V_9 < 0 )
return V_9 ;
do {
V_9 = F_6 ( V_6 , V_38 ,
V_39 ,
V_40 ,
& V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_3 == 0 )
return 0 ;
F_29 ( 100 , 200 ) ;
} while ( -- V_15 );
return - V_41 ;
}
static int F_30 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_3 ;
int type , V_9 ;
V_9 = F_6 ( V_6 , V_38 ,
V_43 ,
V_44 ,
& V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_3 ) {
type = V_45 ;
} else {
V_9 = F_6 ( V_6 , V_46 ,
V_47 ,
V_48 ,
& V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
type = ( V_3 ) ? V_49 :
V_50 ;
}
V_13 -> V_51 = type ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 ,
const union V_42 * V_13 )
{
T_1 V_52 , V_53 , V_54 ;
int V_9 ;
switch ( V_13 -> V_51 ) {
case V_45 :
V_52 = 0x0 ;
break;
case V_49 :
V_52 = 0x1 ;
V_53 = 0x1 ;
V_54 = 0x0 ;
break;
case V_50 :
V_52 = 0x1 ;
V_53 = 0x0 ;
V_54 = 0x1 ;
break;
default:
return - V_29 ;
}
if ( V_52 ) {
V_9 = F_7 ( V_6 , V_46 ,
V_47 ,
V_48 ,
V_53 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_7 ( V_6 , V_34 ,
V_55 ,
V_56 ,
V_54 ) ;
if ( V_9 < 0 )
return V_9 ;
}
return F_7 ( V_6 , V_38 ,
V_43 ,
V_44 , V_52 ) ;
}
static int F_32 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_3 ;
int V_57 ;
F_33 ( & V_6 -> V_58 ) ;
V_3 = V_6 -> V_59 ;
F_34 ( & V_6 -> V_58 ) ;
if ( V_3 & V_60 ) {
switch ( V_3 >> V_61 & 0x7 ) {
case 0x1 :
case 0x3 :
case 0x5 :
V_57 = V_62 ;
break;
case 0x2 :
case 0x4 :
case 0x6 :
V_57 = V_63 ;
break;
default:
V_57 = V_64 ;
}
} else if ( V_3 & V_65 ) {
V_57 = V_66 ;
} else if ( V_3 & V_67 ) {
switch ( V_3 >> V_68 & 0x3 ) {
case 0x1 :
V_57 = V_69 ;
break;
case 0x2 :
V_57 = V_63 ;
break;
case 0x3 :
V_57 = V_70 ;
break;
default:
V_57 = - 1 ;
}
} else if ( V_3 & V_71 ) {
V_57 = V_66 ;
} else {
V_57 = V_72 ;
}
V_13 -> V_51 = V_57 ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_73 , V_74 ;
int V_9 ;
V_9 = F_6 ( V_6 , V_75 ,
V_76 ,
V_77 , & V_73 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_6 ( V_6 , V_78 ,
V_79 ,
V_80 , & V_74 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_51 = V_73 && ! V_74 ;
return 0 ;
}
static int F_36 ( struct V_5 * V_6 ,
const union V_42 * V_13 )
{
return F_37 ( V_6 , V_13 ) ;
}
static int F_38 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
return F_39 ( V_6 , V_13 ) ;
}
static int F_40 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
return F_41 ( V_6 , V_13 ) ;
}
static int F_42 ( struct V_5 * V_6 ,
const union V_42 * V_13 )
{
return F_43 ( V_6 , V_13 ) ;
}
static int F_44 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_3 ;
int V_81 , V_9 ;
V_9 = F_8 ( V_6 , V_46 ,
V_82 , V_83 ,
V_84 ,
F_11 ( V_84 ) , & V_81 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_6 ( V_6 , V_46 ,
V_47 ,
V_48 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_3 )
V_81 /= 5 ;
V_13 -> V_51 = V_81 ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
int V_14 = F_11 ( V_84 ) - 1 ;
V_13 -> V_51 = V_84 [ V_14 ] ;
return 0 ;
}
static int F_46 ( struct V_5 * V_6 ,
const union V_42 * V_13 )
{
T_1 V_3 ;
int V_9 , V_81 = V_13 -> V_51 ;
V_9 = F_6 ( V_6 , V_46 ,
V_47 ,
V_48 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_3 )
V_81 *= 5 ;
return F_9 ( V_6 , V_46 ,
V_82 , V_83 ,
V_84 ,
F_11 ( V_84 ) , V_81 ) ;
}
static int F_47 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
int V_85 , V_9 ;
V_9 = F_8 ( V_6 , V_86 ,
V_87 , V_88 ,
V_89 ,
F_11 ( V_89 ) , & V_85 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_51 = V_85 ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
int V_14 = F_11 ( V_89 ) - 1 ;
V_13 -> V_51 = V_89 [ V_14 ] ;
return 0 ;
}
static int F_49 ( struct V_5 * V_6 ,
const union V_42 * V_13 )
{
return F_9 ( V_6 , V_86 ,
V_87 , V_88 ,
V_89 ,
F_11 ( V_89 ) , V_13 -> V_51 ) ;
}
static int F_50 ( struct V_25 * V_26 ,
enum V_90 V_91 , union V_42 * V_13 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
int V_9 ;
F_51 ( V_6 -> V_22 , L_3 , V_91 ) ;
V_9 = F_16 ( V_6 -> V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
switch ( V_91 ) {
case V_92 :
V_9 = F_30 ( V_6 , V_13 ) ;
break;
case V_93 :
V_9 = F_32 ( V_6 , V_13 ) ;
break;
case V_94 :
V_9 = F_35 ( V_6 , V_13 ) ;
break;
case V_95 :
V_9 = F_38 ( V_6 , V_13 ) ;
break;
case V_96 :
V_9 = F_40 ( V_6 , V_13 ) ;
break;
case V_97 :
V_9 = F_44 ( V_6 , V_13 ) ;
break;
case V_98 :
V_9 = F_45 ( V_6 , V_13 ) ;
break;
case V_99 :
V_9 = F_47 ( V_6 , V_13 ) ;
break;
case V_100 :
V_9 = F_48 ( V_6 , V_13 ) ;
break;
case V_101 :
V_13 -> V_51 = V_102 ;
V_9 = 0 ;
break;
case V_103 :
V_13 -> V_104 = V_6 -> V_105 ;
V_9 = 0 ;
break;
case V_106 :
V_13 -> V_104 = V_107 ;
V_9 = 0 ;
break;
default:
V_9 = - V_108 ;
}
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_52 ( struct V_25 * V_26 ,
enum V_90 V_91 ,
const union V_42 * V_13 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
int V_9 ;
F_51 ( V_6 -> V_22 , L_3 , V_91 ) ;
V_9 = F_16 ( V_6 -> V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
switch ( V_91 ) {
case V_94 :
V_9 = F_36 ( V_6 , V_13 ) ;
break;
case V_96 :
V_9 = F_42 ( V_6 , V_13 ) ;
break;
case V_92 :
V_9 = F_31 ( V_6 , V_13 ) ;
break;
case V_97 :
V_9 = F_46 ( V_6 , V_13 ) ;
break;
case V_99 :
V_9 = F_49 ( V_6 , V_13 ) ;
break;
default:
V_9 = - V_29 ;
}
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_53 ( struct V_25 * V_26 ,
enum V_90 V_91 )
{
int V_9 ;
switch ( V_91 ) {
case V_94 :
case V_96 :
case V_92 :
case V_97 :
case V_99 :
V_9 = 1 ;
break;
default:
V_9 = 0 ;
}
return V_9 ;
}
static int F_39 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_109 , V_110 ;
int V_111 , V_9 ;
F_33 ( & V_6 -> V_58 ) ;
V_110 = V_6 -> V_59 ;
F_34 ( & V_6 -> V_58 ) ;
V_110 &= V_67 ;
V_110 >>= V_68 ;
V_9 = F_2 ( V_6 , V_75 , & V_109 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! ( V_109 & V_76 ) || V_110 ) {
V_111 = V_112 ;
} else {
V_109 &= V_113 ;
V_109 >>= V_114 ;
switch ( V_109 ) {
case 0x0 :
V_111 = V_115 ;
break;
case 0x1 :
case 0x2 :
V_111 = V_116 ;
break;
case 0x3 :
V_111 = V_117 ;
break;
default:
V_9 = - V_41 ;
}
}
if ( ! V_9 )
V_13 -> V_51 = V_111 ;
return V_9 ;
}
static int F_54 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_3 ;
int V_57 ;
F_33 ( & V_6 -> V_58 ) ;
V_3 = V_6 -> V_59 ;
F_34 ( & V_6 -> V_58 ) ;
if ( V_3 & V_65 ) {
V_57 = V_66 ;
} else {
V_3 &= V_60 ;
V_3 >>= V_61 ;
switch ( V_3 ) {
case 0x0 :
V_57 = V_72 ;
break;
case 0x1 :
case 0x3 :
case 0x5 :
V_57 = V_62 ;
break;
case 0x2 :
case 0x4 :
case 0x6 :
V_57 = V_63 ;
break;
default:
V_57 = V_64 ;
}
}
V_13 -> V_51 = V_57 ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_74 ;
int V_9 ;
V_9 = F_6 ( V_6 , V_78 ,
V_79 ,
V_80 , & V_74 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_51 = ! V_74 ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
const union V_42 * V_13 )
{
return F_7 ( V_6 , V_78 ,
V_79 ,
V_80 , ! V_13 -> V_51 ) ;
}
static int F_41 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
int V_118 , V_9 ;
V_9 = F_8 ( V_6 , V_119 ,
V_120 ,
V_121 ,
V_122 ,
F_11 ( V_122 ) , & V_118 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_51 = V_118 ;
return 0 ;
}
static int F_43 ( struct V_5 * V_6 ,
const union V_42 * V_13 )
{
return F_9 ( V_6 , V_119 ,
V_120 ,
V_121 ,
V_122 ,
F_11 ( V_122 ) , V_13 -> V_51 ) ;
}
static int F_56 ( struct V_25 * V_26 ,
enum V_90 V_91 , union V_42 * V_13 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
int V_9 ;
F_57 ( V_6 -> V_22 , L_4 ) ;
F_51 ( V_6 -> V_22 , L_3 , V_91 ) ;
V_9 = F_16 ( V_6 -> V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
switch ( V_91 ) {
case V_95 :
V_9 = F_39 ( V_6 , V_13 ) ;
break;
case V_93 :
V_9 = F_54 ( V_6 , V_13 ) ;
break;
case V_94 :
V_9 = F_55 ( V_6 , V_13 ) ;
break;
case V_123 :
V_13 -> V_51 = V_124 ;
V_9 = 0 ;
break;
case V_96 :
V_9 = F_41 ( V_6 , V_13 ) ;
break;
case V_101 :
V_13 -> V_51 = V_102 ;
V_9 = 0 ;
break;
default:
V_9 = - V_108 ;
}
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_58 ( struct V_25 * V_26 ,
enum V_90 V_91 ,
const union V_42 * V_13 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
int V_9 ;
F_57 ( V_6 -> V_22 , L_4 ) ;
F_51 ( V_6 -> V_22 , L_3 , V_91 ) ;
V_9 = F_16 ( V_6 -> V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
switch ( V_91 ) {
case V_94 :
V_9 = F_37 ( V_6 , V_13 ) ;
break;
case V_96 :
V_9 = F_43 ( V_6 , V_13 ) ;
break;
default:
V_9 = - V_29 ;
}
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_59 ( struct V_25 * V_26 ,
enum V_90 V_91 )
{
int V_9 ;
switch ( V_91 ) {
case V_94 :
case V_96 :
V_9 = 1 ;
break;
default:
V_9 = 0 ;
}
return V_9 ;
}
static void F_60 ( struct V_5 * V_6 )
{
const T_1 V_125 = V_113 ;
const T_1 V_126 = V_65
| V_60 ;
bool V_127 = false , V_128 = false ;
T_1 V_109 = 0 , V_59 = 0 ;
int V_4 , V_9 ;
V_9 = F_2 ( V_6 , V_75 , & V_109 ) ;
if ( V_9 < 0 ) {
F_61 ( V_6 -> V_22 , L_5 , V_9 ) ;
return;
}
V_4 = 0 ;
do {
V_9 = F_2 ( V_6 , V_129 , & V_59 ) ;
if ( V_9 < 0 ) {
F_61 ( V_6 -> V_22 , L_6 , V_9 ) ;
return;
}
} while ( V_59 && ++ V_4 < 2 );
if ( V_59 == ( 1 << V_68 ) &&
! ( V_109 & V_76 ) )
V_59 = 0 ;
if ( V_59 != V_6 -> V_59 ) {
F_57 ( V_6 -> V_22 ,
L_7 ,
! ! ( V_59 & V_71 ) ,
! ! ( V_59 & V_67 ) ,
! ! ( V_59 & V_65 ) ,
! ! ( V_59 & V_60 ) ) ;
F_33 ( & V_6 -> V_58 ) ;
if ( ( V_6 -> V_59 & V_126 ) != ( V_59 & V_126 ) )
V_128 = true ;
if ( ( V_6 -> V_59 & ~ V_126 ) != ( V_59 & ~ V_126 ) )
V_127 = true ;
V_6 -> V_59 = V_59 ;
F_34 ( & V_6 -> V_58 ) ;
}
if ( V_109 != V_6 -> V_109 ) {
if ( ( V_6 -> V_109 & V_76 ) &&
! ( V_109 & V_76 ) ) {
V_9 = F_7 ( V_6 , V_130 ,
V_131 ,
V_132 ,
0 ) ;
if ( V_9 < 0 )
F_61 ( V_6 -> V_22 , L_8 ,
V_9 ) ;
}
if ( ( V_6 -> V_109 & V_125 ) != ( V_109 & V_125 ) )
V_128 = true ;
if ( ( V_6 -> V_109 & ~ V_125 ) != ( V_109 & ~ V_125 ) )
V_127 = true ;
V_6 -> V_109 = V_109 ;
}
if ( V_127 || V_128 )
F_62 ( V_6 -> V_31 ) ;
if ( V_128 && V_6 -> V_133 )
F_62 ( V_6 -> V_133 ) ;
F_51 ( V_6 -> V_22 , L_9 , V_109 , V_59 ) ;
}
static T_4 F_63 ( int V_134 , void * V_8 )
{
struct V_5 * V_6 = V_8 ;
int error ;
V_6 -> V_135 = true ;
error = F_16 ( V_6 -> V_22 ) ;
if ( error < 0 ) {
F_57 ( V_6 -> V_22 , L_10 , error ) ;
F_64 ( V_6 -> V_22 ) ;
return V_136 ;
}
F_60 ( V_6 ) ;
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
V_6 -> V_135 = false ;
return V_137 ;
}
static void F_65 ( struct V_138 * V_139 )
{
struct V_5 * V_6 =
F_66 ( V_139 , struct V_5 , V_140 . V_139 ) ;
int error , V_141 = 0 ;
T_1 V_3 ;
error = F_16 ( V_6 -> V_22 ) ;
if ( error < 0 ) {
F_57 ( V_6 -> V_22 , L_10 , error ) ;
F_64 ( V_6 -> V_22 ) ;
return;
}
if ( F_67 ( V_6 -> V_142 , V_143 ) == 1 )
V_141 = 500000 ;
else if ( F_67 ( V_6 -> V_142 , V_144 ) == 1 ||
F_67 ( V_6 -> V_142 , V_145 ) == 1 )
V_141 = 1500000 ;
else if ( F_67 ( V_6 -> V_142 , V_146 ) == 1 )
V_141 = 2000000 ;
if ( V_141 ) {
error = F_9 ( V_6 , V_130 ,
V_147 ,
V_148 ,
V_149 ,
F_11 ( V_149 ) ,
V_141 ) ;
if ( error < 0 )
F_61 ( V_6 -> V_22 , L_11 , error ) ;
}
if ( ! V_141 && F_67 ( V_6 -> V_142 , V_150 ) == 1 )
V_3 = V_151 ;
else
V_3 = V_152 ;
error = F_7 ( V_6 , V_38 ,
V_43 ,
V_44 ,
V_3 ) ;
if ( error < 0 )
F_61 ( V_6 -> V_22 , L_12 , error ) ;
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
}
static int F_68 ( struct V_153 * V_154 , unsigned long V_155 ,
void * V_156 )
{
struct V_5 * V_6 =
F_66 ( V_154 , struct V_5 , V_157 ) ;
F_69 ( V_158 , & V_6 -> V_140 , F_70 ( 300 ) ) ;
return V_159 ;
}
static int F_71 ( struct V_5 * V_6 )
{
T_1 V_3 ;
int V_9 ;
V_9 = F_6 ( V_6 , V_160 ,
V_161 ,
V_162 ,
& V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_3 != V_163 &&
V_3 != V_164 ) {
F_61 ( V_6 -> V_22 , L_13 , V_3 ) ;
return - V_165 ;
}
V_9 = F_27 ( V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_26 ( V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_2 ( V_6 , V_75 , & V_6 -> V_109 ) ;
}
static int F_72 ( struct V_166 * V_10 ,
const struct V_167 * V_168 )
{
struct V_169 * V_170 = F_73 ( V_10 -> V_22 . V_171 ) ;
struct V_21 * V_22 = & V_10 -> V_22 ;
struct V_172 V_173 = {} , V_174 = {} ;
struct V_5 * V_6 ;
const char * V_20 ;
int V_9 ;
if ( ! F_74 ( V_170 , V_175 ) ) {
F_61 ( V_22 , L_14 ) ;
return - V_165 ;
}
V_6 = F_75 ( V_22 , sizeof( * V_6 ) , V_176 ) ;
if ( ! V_6 ) {
F_61 ( V_22 , L_15 ) ;
return - V_177 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_22 = V_22 ;
strncpy ( V_6 -> V_105 , V_168 -> V_20 , V_178 ) ;
F_76 ( & V_6 -> V_58 ) ;
V_6 -> V_59 = 0 ;
V_6 -> V_109 = V_179 ;
F_77 ( V_10 , V_6 ) ;
if ( ! V_10 -> V_134 ) {
F_61 ( V_22 , L_16 ) ;
return - V_29 ;
}
if ( F_78 ( V_22 , L_17 , & V_20 ) == 0 ) {
V_6 -> V_142 = F_79 ( V_20 ) ;
if ( ! V_6 -> V_142 )
return - V_180 ;
F_80 ( V_6 -> V_22 , L_18 , V_20 ) ;
}
F_81 ( V_22 ) ;
F_82 ( V_22 ) ;
F_83 ( V_22 , 600 ) ;
V_9 = F_16 ( V_22 ) ;
if ( V_9 < 0 ) {
F_61 ( V_22 , L_10 , V_9 ) ;
goto V_181;
}
V_9 = F_71 ( V_6 ) ;
if ( V_9 < 0 ) {
F_61 ( V_22 , L_19 ) ;
goto V_181;
}
V_173 . V_182 = V_6 ;
V_173 . V_183 = V_184 ;
V_173 . V_185 = F_11 ( V_184 ) ,
V_6 -> V_31 = F_84 ( V_22 , & V_186 ,
& V_173 ) ;
if ( F_85 ( V_6 -> V_31 ) ) {
F_61 ( V_22 , L_20 ) ;
V_9 = F_86 ( V_6 -> V_31 ) ;
goto V_181;
}
if ( ! F_28 ( V_22 , L_21 ) ) {
V_174 . V_182 = V_6 ;
V_6 -> V_133 = F_84 ( V_22 , & V_187 ,
& V_174 ) ;
if ( F_85 ( V_6 -> V_133 ) ) {
F_61 ( V_22 , L_22 ) ;
V_9 = F_86 ( V_6 -> V_133 ) ;
goto V_188;
}
}
V_9 = F_22 ( V_6 ) ;
if ( V_9 ) {
F_61 ( V_22 , L_23 ) ;
goto V_188;
}
V_6 -> V_189 = true ;
V_9 = F_87 ( V_22 , V_10 -> V_134 , NULL ,
F_63 ,
V_190 | V_191 ,
L_24 , V_6 ) ;
if ( V_9 < 0 ) {
F_61 ( V_22 , L_25 ) ;
goto V_192;
}
if ( V_6 -> V_142 ) {
F_88 ( & V_6 -> V_140 , F_65 ) ;
V_6 -> V_157 . V_193 = F_68 ;
V_9 = F_89 ( V_22 , V_6 -> V_142 ,
& V_6 -> V_157 ) ;
if ( V_9 ) {
F_61 ( V_22 , L_26 ) ;
goto V_192;
}
F_69 ( V_158 , & V_6 -> V_140 , 0 ) ;
}
F_90 ( V_10 -> V_134 ) ;
F_18 ( V_22 ) ;
F_19 ( V_22 ) ;
return 0 ;
V_192:
F_24 ( V_6 ) ;
V_188:
if ( ! F_91 ( V_6 -> V_133 ) )
F_92 ( V_6 -> V_133 ) ;
F_92 ( V_6 -> V_31 ) ;
V_181:
F_93 ( V_22 ) ;
F_94 ( V_22 ) ;
F_95 ( V_22 ) ;
return V_9 ;
}
static int F_96 ( struct V_166 * V_10 )
{
struct V_5 * V_6 = F_97 ( V_10 ) ;
int error ;
error = F_16 ( V_6 -> V_22 ) ;
if ( error < 0 ) {
F_57 ( V_6 -> V_22 , L_10 , error ) ;
F_64 ( V_6 -> V_22 ) ;
}
F_27 ( V_6 ) ;
F_24 ( V_6 ) ;
if ( V_6 -> V_133 )
F_92 ( V_6 -> V_133 ) ;
F_92 ( V_6 -> V_31 ) ;
if ( error >= 0 )
F_93 ( V_6 -> V_22 ) ;
F_94 ( V_6 -> V_22 ) ;
F_95 ( V_6 -> V_22 ) ;
return 0 ;
}
static T_5 int F_98 ( struct V_21 * V_22 )
{
struct V_166 * V_10 = F_99 ( V_22 ) ;
struct V_5 * V_6 = F_97 ( V_10 ) ;
if ( ! V_6 -> V_189 )
return 0 ;
F_51 ( V_6 -> V_22 , L_27 , V_194 ) ;
return 0 ;
}
static T_5 int F_100 ( struct V_21 * V_22 )
{
struct V_166 * V_10 = F_99 ( V_22 ) ;
struct V_5 * V_6 = F_97 ( V_10 ) ;
if ( ! V_6 -> V_189 )
return 0 ;
if ( ! V_6 -> V_135 ) {
F_51 ( V_6 -> V_22 , L_28 ) ;
F_60 ( V_6 ) ;
}
return 0 ;
}
static T_5 int F_101 ( struct V_21 * V_22 )
{
struct V_166 * V_10 = F_99 ( V_22 ) ;
struct V_5 * V_6 = F_97 ( V_10 ) ;
int error ;
error = F_16 ( V_6 -> V_22 ) ;
if ( error < 0 ) {
F_57 ( V_6 -> V_22 , L_10 , error ) ;
F_64 ( V_6 -> V_22 ) ;
}
F_27 ( V_6 ) ;
if ( error >= 0 ) {
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
}
return 0 ;
}
static T_5 int F_102 ( struct V_21 * V_22 )
{
struct V_166 * V_10 = F_99 ( V_22 ) ;
struct V_5 * V_6 = F_97 ( V_10 ) ;
int error ;
V_6 -> V_59 = 0 ;
V_6 -> V_109 = V_179 ;
error = F_16 ( V_6 -> V_22 ) ;
if ( error < 0 ) {
F_57 ( V_6 -> V_22 , L_10 , error ) ;
F_64 ( V_6 -> V_22 ) ;
}
F_27 ( V_6 ) ;
F_26 ( V_6 ) ;
F_2 ( V_6 , V_75 , & V_6 -> V_109 ) ;
if ( error >= 0 ) {
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
}
F_62 ( V_6 -> V_31 ) ;
if ( V_6 -> V_133 )
F_62 ( V_6 -> V_133 ) ;
return 0 ;
}
