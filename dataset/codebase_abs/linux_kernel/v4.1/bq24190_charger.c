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
int V_9 ;
T_1 V_3 ;
V_27 = F_12 ( V_18 -> V_18 . V_20 ) ;
if ( ! V_27 )
return - V_28 ;
V_9 = F_6 ( V_6 , V_27 -> V_7 , V_27 -> V_11 , V_27 -> V_12 , & V_3 ) ;
if ( V_9 )
return V_9 ;
return F_16 ( V_24 , V_29 , L_1 , V_3 ) ;
}
static T_2 F_17 ( struct V_21 * V_22 ,
struct V_23 * V_18 , const char * V_24 , T_3 V_30 )
{
struct V_25 * V_26 = F_14 ( V_22 ) ;
struct V_5 * V_6 = F_15 ( V_26 ) ;
struct V_19 * V_27 ;
int V_9 ;
T_1 V_3 ;
V_27 = F_12 ( V_18 -> V_18 . V_20 ) ;
if ( ! V_27 )
return - V_28 ;
V_9 = F_18 ( V_24 , 0 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_7 ( V_6 , V_27 -> V_7 , V_27 -> V_11 , V_27 -> V_12 , V_3 ) ;
if ( V_9 )
return V_9 ;
return V_30 ;
}
static int F_19 ( struct V_5 * V_6 )
{
F_10 () ;
return F_20 ( & V_6 -> V_31 -> V_22 . V_32 ,
& V_33 ) ;
}
static void F_21 ( struct V_5 * V_6 )
{
F_22 ( & V_6 -> V_31 -> V_22 . V_32 , & V_33 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
return 0 ;
}
static inline void F_21 ( struct V_5 * V_6 ) {}
static int F_23 ( struct V_5 * V_6 )
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
static int F_24 ( struct V_5 * V_6 )
{
int V_9 , V_15 = 100 ;
T_1 V_3 ;
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
if ( ! V_3 )
break;
F_25 ( 10 ) ;
} while ( -- V_15 );
if ( ! V_15 )
return - V_41 ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 ,
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
static int F_27 ( struct V_5 * V_6 ,
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
return - V_28 ;
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
static int F_28 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_3 ;
int V_57 , V_9 ;
F_29 ( & V_6 -> V_58 ) ;
if ( V_6 -> V_59 ) {
V_3 = V_6 -> V_60 ;
V_6 -> V_59 = false ;
F_30 ( & V_6 -> V_58 ) ;
} else {
F_30 ( & V_6 -> V_58 ) ;
V_9 = F_2 ( V_6 , V_61 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
}
if ( V_3 & V_62 ) {
V_57 = V_63 ;
} else {
V_3 &= V_64 ;
V_3 >>= V_65 ;
switch ( V_3 ) {
case 0x0 :
V_57 = V_66 ;
break;
case 0x1 :
V_57 = V_67 ;
break;
case 0x2 :
V_57 = V_68 ;
break;
case 0x3 :
V_57 = V_69 ;
break;
default:
V_57 = V_70 ;
}
}
V_13 -> V_51 = V_57 ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_3 ;
int V_9 ;
V_9 = F_6 ( V_6 , V_71 ,
V_72 ,
V_73 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_51 = V_3 ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_3 ;
int V_74 , V_9 ;
V_9 = F_8 ( V_6 , V_46 ,
V_75 , V_76 ,
V_77 ,
F_11 ( V_77 ) , & V_74 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_6 ( V_6 , V_46 ,
V_47 ,
V_48 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_3 )
V_74 /= 5 ;
V_13 -> V_51 = V_74 ;
return 0 ;
}
static int F_33 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
int V_14 = F_11 ( V_77 ) - 1 ;
V_13 -> V_51 = V_77 [ V_14 ] ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 ,
const union V_42 * V_13 )
{
T_1 V_3 ;
int V_9 , V_74 = V_13 -> V_51 ;
V_9 = F_6 ( V_6 , V_46 ,
V_47 ,
V_48 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_3 )
V_74 *= 5 ;
return F_9 ( V_6 , V_46 ,
V_75 , V_76 ,
V_77 ,
F_11 ( V_77 ) , V_74 ) ;
}
static int F_35 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
int V_78 , V_9 ;
V_9 = F_8 ( V_6 , V_79 ,
V_80 , V_81 ,
V_82 ,
F_11 ( V_82 ) , & V_78 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_51 = V_78 ;
return 0 ;
}
static int F_36 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
int V_14 = F_11 ( V_82 ) - 1 ;
V_13 -> V_51 = V_82 [ V_14 ] ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
const union V_42 * V_13 )
{
return F_9 ( V_6 , V_79 ,
V_80 , V_81 ,
V_82 ,
F_11 ( V_82 ) , V_13 -> V_51 ) ;
}
static int F_38 ( struct V_25 * V_26 ,
enum V_83 V_84 , union V_42 * V_13 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
int V_9 ;
F_39 ( V_6 -> V_22 , L_2 , V_84 ) ;
F_40 ( V_6 -> V_22 ) ;
switch ( V_84 ) {
case V_85 :
V_9 = F_26 ( V_6 , V_13 ) ;
break;
case V_86 :
V_9 = F_28 ( V_6 , V_13 ) ;
break;
case V_87 :
V_9 = F_31 ( V_6 , V_13 ) ;
break;
case V_88 :
V_9 = F_32 ( V_6 , V_13 ) ;
break;
case V_89 :
V_9 = F_33 ( V_6 , V_13 ) ;
break;
case V_90 :
V_9 = F_35 ( V_6 , V_13 ) ;
break;
case V_91 :
V_9 = F_36 ( V_6 , V_13 ) ;
break;
case V_92 :
V_13 -> V_51 = V_93 ;
V_9 = 0 ;
break;
case V_94 :
V_13 -> V_95 = V_6 -> V_96 ;
V_9 = 0 ;
break;
case V_97 :
V_13 -> V_95 = V_98 ;
V_9 = 0 ;
break;
default:
V_9 = - V_99 ;
}
F_41 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_42 ( struct V_25 * V_26 ,
enum V_83 V_84 ,
const union V_42 * V_13 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
int V_9 ;
F_39 ( V_6 -> V_22 , L_2 , V_84 ) ;
F_40 ( V_6 -> V_22 ) ;
switch ( V_84 ) {
case V_85 :
V_9 = F_27 ( V_6 , V_13 ) ;
break;
case V_88 :
V_9 = F_34 ( V_6 , V_13 ) ;
break;
case V_90 :
V_9 = F_37 ( V_6 , V_13 ) ;
break;
default:
V_9 = - V_28 ;
}
F_41 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_43 ( struct V_25 * V_26 ,
enum V_83 V_84 )
{
int V_9 ;
switch ( V_84 ) {
case V_85 :
case V_88 :
case V_90 :
V_9 = 1 ;
break;
default:
V_9 = 0 ;
}
return V_9 ;
}
static int F_44 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_100 , V_101 ;
int V_102 , V_9 ;
F_29 ( & V_6 -> V_58 ) ;
if ( V_6 -> V_103 ) {
V_101 = V_6 -> V_60 ;
V_6 -> V_103 = false ;
F_30 ( & V_6 -> V_58 ) ;
} else {
F_30 ( & V_6 -> V_58 ) ;
V_9 = F_2 ( V_6 , V_61 , & V_101 ) ;
if ( V_9 < 0 )
return V_9 ;
}
V_101 &= V_64 ;
V_101 >>= V_65 ;
V_9 = F_2 ( V_6 , V_71 , & V_100 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! ( V_100 & V_72 ) || V_101 ) {
V_102 = V_104 ;
} else {
V_100 &= V_105 ;
V_100 >>= V_106 ;
switch ( V_100 ) {
case 0x0 :
V_102 = V_107 ;
break;
case 0x1 :
case 0x2 :
V_102 = V_108 ;
break;
case 0x3 :
V_102 = V_109 ;
break;
default:
V_9 = - V_41 ;
}
}
if ( ! V_9 )
V_13 -> V_51 = V_102 ;
return V_9 ;
}
static int F_45 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_3 ;
int V_57 , V_9 ;
F_29 ( & V_6 -> V_58 ) ;
if ( V_6 -> V_110 ) {
V_3 = V_6 -> V_60 ;
V_6 -> V_110 = false ;
F_30 ( & V_6 -> V_58 ) ;
} else {
F_30 ( & V_6 -> V_58 ) ;
V_9 = F_2 ( V_6 , V_61 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
}
if ( V_3 & V_111 ) {
V_57 = V_63 ;
} else {
V_3 &= V_112 ;
V_3 >>= V_113 ;
switch ( V_3 ) {
case 0x0 :
V_57 = V_66 ;
break;
case 0x1 :
case 0x3 :
case 0x5 :
V_57 = V_114 ;
break;
case 0x2 :
case 0x4 :
case 0x6 :
V_57 = V_68 ;
break;
default:
V_57 = V_70 ;
}
}
V_13 -> V_51 = V_57 ;
return 0 ;
}
static int F_46 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
T_1 V_115 ;
int V_9 ;
V_9 = F_6 ( V_6 , V_116 ,
V_117 ,
V_118 , & V_115 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_51 = ! V_115 ;
return 0 ;
}
static int F_47 ( struct V_5 * V_6 ,
const union V_42 * V_13 )
{
return F_7 ( V_6 , V_116 ,
V_117 ,
V_118 , ! V_13 -> V_51 ) ;
}
static int F_48 ( struct V_5 * V_6 ,
union V_42 * V_13 )
{
int V_119 , V_9 ;
V_9 = F_8 ( V_6 , V_120 ,
V_121 ,
V_122 ,
V_123 ,
F_11 ( V_123 ) , & V_119 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_51 = V_119 ;
return 0 ;
}
static int F_49 ( struct V_5 * V_6 ,
const union V_42 * V_13 )
{
return F_9 ( V_6 , V_120 ,
V_121 ,
V_122 ,
V_123 ,
F_11 ( V_123 ) , V_13 -> V_51 ) ;
}
static int F_50 ( struct V_25 * V_26 ,
enum V_83 V_84 , union V_42 * V_13 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
int V_9 ;
F_39 ( V_6 -> V_22 , L_2 , V_84 ) ;
F_40 ( V_6 -> V_22 ) ;
switch ( V_84 ) {
case V_124 :
V_9 = F_44 ( V_6 , V_13 ) ;
break;
case V_86 :
V_9 = F_45 ( V_6 , V_13 ) ;
break;
case V_87 :
V_9 = F_46 ( V_6 , V_13 ) ;
break;
case V_125 :
V_13 -> V_51 = V_126 ;
V_9 = 0 ;
break;
case V_127 :
V_9 = F_48 ( V_6 , V_13 ) ;
break;
case V_92 :
V_13 -> V_51 = V_93 ;
V_9 = 0 ;
break;
default:
V_9 = - V_99 ;
}
F_41 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_51 ( struct V_25 * V_26 ,
enum V_83 V_84 ,
const union V_42 * V_13 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
int V_9 ;
F_39 ( V_6 -> V_22 , L_2 , V_84 ) ;
F_41 ( V_6 -> V_22 ) ;
switch ( V_84 ) {
case V_87 :
V_9 = F_47 ( V_6 , V_13 ) ;
break;
case V_127 :
V_9 = F_49 ( V_6 , V_13 ) ;
break;
default:
V_9 = - V_28 ;
}
F_41 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_52 ( struct V_25 * V_26 ,
enum V_83 V_84 )
{
int V_9 ;
switch ( V_84 ) {
case V_87 :
case V_127 :
V_9 = 1 ;
break;
default:
V_9 = 0 ;
}
return V_9 ;
}
static T_4 F_53 ( int V_128 , void * V_8 )
{
struct V_5 * V_6 = V_8 ;
bool V_129 = false ;
T_1 V_100 = 0 , V_60 = 0 ;
int V_9 ;
F_40 ( V_6 -> V_22 ) ;
V_9 = F_2 ( V_6 , V_71 , & V_100 ) ;
if ( V_9 < 0 ) {
F_54 ( V_6 -> V_22 , L_3 , V_9 ) ;
goto V_130;
}
if ( V_100 != V_6 -> V_100 ) {
if ( ( V_6 -> V_100 & V_72 ) &&
! ( V_100 & V_72 ) ) {
V_9 = F_7 ( V_6 , V_131 ,
V_132 ,
V_133 ,
0 ) ;
if ( V_9 < 0 )
F_54 ( V_6 -> V_22 , L_4 ,
V_9 ) ;
}
V_6 -> V_100 = V_100 ;
V_129 = true ;
}
F_29 ( & V_6 -> V_58 ) ;
V_9 = F_2 ( V_6 , V_61 , & V_60 ) ;
if ( V_9 < 0 ) {
F_30 ( & V_6 -> V_58 ) ;
F_54 ( V_6 -> V_22 , L_5 , V_9 ) ;
goto V_130;
}
if ( V_60 != V_6 -> V_60 ) {
V_6 -> V_60 = V_60 ;
V_6 -> V_59 = true ;
V_6 -> V_110 = true ;
V_6 -> V_103 = true ;
V_129 = true ;
}
F_30 ( & V_6 -> V_58 ) ;
if ( V_129 && ! V_6 -> V_134 ) {
F_55 ( V_6 -> V_31 ) ;
F_55 ( V_6 -> V_135 ) ;
V_6 -> V_134 = false ;
}
V_130:
F_41 ( V_6 -> V_22 ) ;
F_39 ( V_6 -> V_22 , L_6 , V_100 , V_60 ) ;
return V_136 ;
}
static int F_56 ( struct V_5 * V_6 )
{
T_1 V_3 ;
int V_9 ;
F_40 ( V_6 -> V_22 ) ;
V_9 = F_6 ( V_6 , V_137 ,
V_138 ,
V_139 ,
& V_3 ) ;
if ( V_9 < 0 )
goto V_130;
if ( V_3 != V_6 -> V_140 ) {
V_9 = - V_141 ;
goto V_130;
}
V_9 = F_24 ( V_6 ) ;
if ( V_9 < 0 )
goto V_130;
V_9 = F_23 ( V_6 ) ;
V_130:
F_41 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_57 ( struct V_5 * V_6 )
{
V_6 -> V_128 = F_58 ( V_6 -> V_22 -> V_142 , 0 ) ;
if ( V_6 -> V_128 <= 0 )
return - 1 ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 )
{
return - 1 ;
}
static int F_59 ( struct V_5 * V_6 ,
struct V_143 * V_144 )
{
int V_9 ;
if ( ! F_60 ( V_144 -> V_145 ) )
return - 1 ;
V_9 = F_61 ( V_144 -> V_145 , F_62 ( V_6 -> V_22 ) ) ;
if ( V_9 < 0 )
return - 1 ;
V_9 = F_63 ( V_144 -> V_145 ) ;
if ( V_9 < 0 )
goto V_130;
V_6 -> V_128 = F_64 ( V_144 -> V_145 ) ;
if ( ! V_6 -> V_128 )
goto V_130;
V_6 -> V_145 = V_144 -> V_145 ;
return 0 ;
V_130:
F_65 ( V_144 -> V_145 ) ;
return - 1 ;
}
static int F_66 ( struct V_146 * V_10 ,
const struct V_147 * V_148 )
{
struct V_149 * V_150 = F_67 ( V_10 -> V_22 . V_151 ) ;
struct V_21 * V_22 = & V_10 -> V_22 ;
struct V_143 * V_144 = V_10 -> V_22 . V_152 ;
struct V_153 V_154 = {} , V_155 = {} ;
struct V_5 * V_6 ;
int V_9 ;
if ( ! F_68 ( V_150 , V_156 ) ) {
F_54 ( V_22 , L_7 ) ;
return - V_141 ;
}
V_6 = F_69 ( V_22 , sizeof( * V_6 ) , V_157 ) ;
if ( ! V_6 ) {
F_54 ( V_22 , L_8 ) ;
return - V_158 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_140 = V_148 -> V_159 ;
strncpy ( V_6 -> V_96 , V_148 -> V_20 , V_160 ) ;
F_70 ( & V_6 -> V_58 ) ;
V_6 -> V_134 = true ;
V_6 -> V_59 = false ;
V_6 -> V_110 = false ;
V_6 -> V_103 = false ;
F_71 ( V_10 , V_6 ) ;
if ( V_22 -> V_142 )
V_9 = F_57 ( V_6 ) ;
else
V_9 = F_59 ( V_6 , V_144 ) ;
if ( V_9 ) {
F_54 ( V_22 , L_9 ) ;
return - V_28 ;
}
V_9 = F_72 ( V_22 , V_6 -> V_128 , NULL ,
F_53 ,
V_161 | V_162 ,
L_10 , V_6 ) ;
if ( V_9 < 0 ) {
F_54 ( V_22 , L_11 ) ;
goto V_163;
}
F_73 ( V_22 ) ;
F_74 ( V_22 ) ;
V_9 = F_56 ( V_6 ) ;
if ( V_9 < 0 ) {
F_54 ( V_22 , L_12 ) ;
goto V_164;
}
V_154 . V_165 = V_6 ;
V_154 . V_166 = V_167 ;
V_154 . V_168 = F_11 ( V_167 ) ,
V_6 -> V_31 = F_75 ( V_22 , & V_169 ,
& V_154 ) ;
if ( F_76 ( V_6 -> V_31 ) ) {
F_54 ( V_22 , L_13 ) ;
V_9 = F_77 ( V_6 -> V_31 ) ;
goto V_164;
}
V_155 . V_165 = V_6 ;
V_6 -> V_135 = F_75 ( V_22 , & V_170 ,
& V_155 ) ;
if ( F_76 ( V_6 -> V_135 ) ) {
F_54 ( V_22 , L_14 ) ;
V_9 = F_77 ( V_6 -> V_135 ) ;
goto V_171;
}
V_9 = F_19 ( V_6 ) ;
if ( V_9 ) {
F_54 ( V_22 , L_15 ) ;
goto V_172;
}
return 0 ;
V_172:
F_78 ( V_6 -> V_135 ) ;
V_171:
F_78 ( V_6 -> V_31 ) ;
V_164:
F_79 ( V_22 ) ;
V_163:
if ( V_6 -> V_145 )
F_65 ( V_6 -> V_145 ) ;
return V_9 ;
}
static int F_80 ( struct V_146 * V_10 )
{
struct V_5 * V_6 = F_81 ( V_10 ) ;
F_40 ( V_6 -> V_22 ) ;
F_24 ( V_6 ) ;
F_41 ( V_6 -> V_22 ) ;
F_21 ( V_6 ) ;
F_78 ( V_6 -> V_135 ) ;
F_78 ( V_6 -> V_31 ) ;
F_79 ( V_6 -> V_22 ) ;
if ( V_6 -> V_145 )
F_65 ( V_6 -> V_145 ) ;
return 0 ;
}
static int F_82 ( struct V_21 * V_22 )
{
struct V_146 * V_10 = F_83 ( V_22 ) ;
struct V_5 * V_6 = F_81 ( V_10 ) ;
F_40 ( V_6 -> V_22 ) ;
F_24 ( V_6 ) ;
F_41 ( V_6 -> V_22 ) ;
return 0 ;
}
static int F_84 ( struct V_21 * V_22 )
{
struct V_146 * V_10 = F_83 ( V_22 ) ;
struct V_5 * V_6 = F_81 ( V_10 ) ;
V_6 -> V_59 = false ;
V_6 -> V_110 = false ;
V_6 -> V_103 = false ;
F_40 ( V_6 -> V_22 ) ;
F_24 ( V_6 ) ;
F_41 ( V_6 -> V_22 ) ;
F_55 ( V_6 -> V_31 ) ;
F_55 ( V_6 -> V_135 ) ;
return 0 ;
}
