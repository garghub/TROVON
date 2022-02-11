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
static int F_26 ( struct V_34 * V_22 , T_1 V_13 )
{
struct V_5 * V_6 = F_27 ( V_22 ) ;
int V_9 ;
V_9 = F_16 ( V_6 -> V_22 ) ;
if ( V_9 < 0 ) {
F_28 ( V_6 -> V_22 , L_2 , V_9 ) ;
F_29 ( V_6 -> V_22 ) ;
return V_9 ;
}
V_9 = F_7 ( V_6 , V_35 ,
V_36 ,
V_37 , V_13 ) ;
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_30 ( struct V_34 * V_22 )
{
return F_26 ( V_22 , V_38 ) ;
}
static int F_31 ( struct V_34 * V_22 )
{
return F_26 ( V_22 , V_39 ) ;
}
static int F_32 ( struct V_34 * V_22 )
{
struct V_5 * V_6 = F_27 ( V_22 ) ;
int V_9 ;
T_1 V_13 ;
V_9 = F_16 ( V_6 -> V_22 ) ;
if ( V_9 < 0 ) {
F_28 ( V_6 -> V_22 , L_2 , V_9 ) ;
F_29 ( V_6 -> V_22 ) ;
return V_9 ;
}
V_9 = F_6 ( V_6 , V_35 ,
V_36 ,
V_37 , & V_13 ) ;
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
return V_9 ? V_9 : V_13 == V_38 ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_40 * V_41 = V_6 -> V_22 -> V_42 ;
struct V_43 V_44 = { } ;
struct V_34 * V_7 ;
int V_9 = 0 ;
V_44 . V_22 = V_6 -> V_22 ;
if ( V_41 && V_41 -> V_45 )
V_44 . V_46 = V_41 -> V_45 ;
else
V_44 . V_46 = & V_47 ;
V_44 . V_48 = V_6 ;
V_7 = F_34 ( V_6 -> V_22 , & V_49 , & V_44 ) ;
if ( F_35 ( V_7 ) ) {
V_9 = F_36 ( V_7 ) ;
F_37 ( V_6 -> V_22 , L_3 , V_9 ) ;
}
return V_9 ;
}
static int F_33 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_38 ( struct V_5 * V_6 )
{
int V_9 ;
T_1 V_3 ;
V_9 = F_2 ( V_6 , V_50 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_6 -> V_51 = ( ( V_3 & V_52 ) >>
V_53 ) ;
V_3 &= ~ V_52 ;
V_9 = F_4 ( V_6 , V_50 , V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_6 -> V_54 ) {
V_3 = V_6 -> V_54 / 100 - 30 ;
V_9 = F_7 ( V_6 , V_35 ,
V_55 ,
V_56 ,
V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
}
if ( V_6 -> V_57 ) {
V_3 = V_6 -> V_57 / 128 - 1 ;
V_9 = F_7 ( V_6 , V_58 ,
V_59 ,
V_60 ,
V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
}
if ( V_6 -> V_61 ) {
V_3 = V_6 -> V_61 / 128 - 1 ;
V_9 = F_7 ( V_6 , V_58 ,
V_62 ,
V_63 ,
V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
}
return 0 ;
}
static int F_39 ( struct V_5 * V_6 )
{
int V_9 , V_15 = 100 ;
T_1 V_3 ;
if ( F_40 ( V_6 -> V_22 , L_4 ) )
return 0 ;
V_9 = F_7 ( V_6 , V_35 ,
V_64 ,
V_65 ,
0x1 ) ;
if ( V_9 < 0 )
return V_9 ;
do {
V_9 = F_6 ( V_6 , V_35 ,
V_64 ,
V_65 ,
& V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_3 == 0 )
return 0 ;
F_41 ( 100 , 200 ) ;
} while ( -- V_15 );
return - V_66 ;
}
static int F_42 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
T_1 V_3 ;
int type , V_9 ;
V_9 = F_6 ( V_6 , V_35 ,
V_36 ,
V_37 ,
& V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_3 ) {
type = V_68 ;
} else {
V_9 = F_6 ( V_6 , V_69 ,
V_70 ,
V_71 ,
& V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
type = ( V_3 ) ? V_72 :
V_73 ;
}
V_13 -> V_74 = type ;
return 0 ;
}
static int F_43 ( struct V_5 * V_6 ,
const union V_67 * V_13 )
{
T_1 V_75 , V_76 , V_77 ;
int V_9 ;
switch ( V_13 -> V_74 ) {
case V_68 :
V_75 = 0x0 ;
break;
case V_72 :
V_75 = 0x1 ;
V_76 = 0x1 ;
V_77 = 0x0 ;
break;
case V_73 :
V_75 = 0x1 ;
V_76 = 0x0 ;
V_77 = 0x1 ;
break;
default:
return - V_29 ;
}
if ( V_75 ) {
V_9 = F_7 ( V_6 , V_69 ,
V_70 ,
V_71 ,
V_76 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_7 ( V_6 , V_50 ,
V_78 ,
V_79 ,
V_77 ) ;
if ( V_9 < 0 )
return V_9 ;
}
return F_7 ( V_6 , V_35 ,
V_36 ,
V_37 , V_75 ) ;
}
static int F_44 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
T_1 V_3 ;
int V_80 ;
F_45 ( & V_6 -> V_81 ) ;
V_3 = V_6 -> V_82 ;
F_46 ( & V_6 -> V_81 ) ;
if ( V_3 & V_83 ) {
switch ( V_3 >> V_84 & 0x7 ) {
case 0x1 :
case 0x3 :
case 0x5 :
V_80 = V_85 ;
break;
case 0x2 :
case 0x4 :
case 0x6 :
V_80 = V_86 ;
break;
default:
V_80 = V_87 ;
}
} else if ( V_3 & V_88 ) {
V_80 = V_89 ;
} else if ( V_3 & V_90 ) {
switch ( V_3 >> V_91 & 0x3 ) {
case 0x1 :
V_80 = V_92 ;
break;
case 0x2 :
V_80 = V_86 ;
break;
case 0x3 :
V_80 = V_93 ;
break;
default:
V_80 = - 1 ;
}
} else if ( V_3 & V_94 ) {
V_80 = V_89 ;
} else {
V_80 = V_95 ;
}
V_13 -> V_74 = V_80 ;
return 0 ;
}
static int F_47 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
T_1 V_96 , V_97 ;
int V_9 ;
V_9 = F_6 ( V_6 , V_98 ,
V_99 ,
V_100 , & V_96 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_6 ( V_6 , V_101 ,
V_102 ,
V_103 , & V_97 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_74 = V_96 && ! V_97 ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 ,
const union V_67 * V_13 )
{
return F_49 ( V_6 , V_13 ) ;
}
static int F_50 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
return F_51 ( V_6 , V_13 ) ;
}
static int F_52 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
return F_53 ( V_6 , V_13 ) ;
}
static int F_54 ( struct V_5 * V_6 ,
const union V_67 * V_13 )
{
return F_55 ( V_6 , V_13 ) ;
}
static int F_56 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
T_1 V_3 ;
int V_9 ;
V_9 = F_6 ( V_6 , V_58 ,
V_59 ,
V_60 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_74 = ++ V_3 * 128 * 1000 ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
T_1 V_3 ;
int V_9 ;
V_9 = F_6 ( V_6 , V_58 ,
V_62 ,
V_63 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_74 = ++ V_3 * 128 * 1000 ;
return 0 ;
}
static int F_58 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
T_1 V_3 ;
int V_104 , V_9 ;
V_9 = F_8 ( V_6 , V_69 ,
V_105 , V_106 ,
V_107 ,
F_11 ( V_107 ) , & V_104 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_6 ( V_6 , V_69 ,
V_70 ,
V_71 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_3 )
V_104 /= 5 ;
V_13 -> V_74 = V_104 ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
int V_14 = F_11 ( V_107 ) - 1 ;
V_13 -> V_74 = V_107 [ V_14 ] ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 ,
const union V_67 * V_13 )
{
T_1 V_3 ;
int V_9 , V_104 = V_13 -> V_74 ;
V_9 = F_6 ( V_6 , V_69 ,
V_70 ,
V_71 , & V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_3 )
V_104 *= 5 ;
return F_9 ( V_6 , V_69 ,
V_105 , V_106 ,
V_107 ,
F_11 ( V_107 ) , V_104 ) ;
}
static int F_61 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
int V_108 , V_9 ;
V_9 = F_8 ( V_6 , V_109 ,
V_110 , V_111 ,
V_112 ,
F_11 ( V_112 ) , & V_108 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_74 = V_108 ;
return 0 ;
}
static int F_62 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
int V_14 = F_11 ( V_112 ) - 1 ;
V_13 -> V_74 = V_112 [ V_14 ] ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 ,
const union V_67 * V_13 )
{
return F_9 ( V_6 , V_109 ,
V_110 , V_111 ,
V_112 ,
F_11 ( V_112 ) , V_13 -> V_74 ) ;
}
static int F_64 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
int V_113 , V_9 ;
V_9 = F_8 ( V_6 , V_114 ,
V_115 ,
V_116 ,
V_117 ,
F_11 ( V_117 ) , & V_113 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_74 = V_113 ;
return 0 ;
}
static int F_65 ( struct V_5 * V_6 ,
const union V_67 * V_13 )
{
return F_9 ( V_6 , V_114 ,
V_115 ,
V_116 ,
V_117 ,
F_11 ( V_117 ) , V_13 -> V_74 ) ;
}
static int F_66 ( struct V_25 * V_26 ,
enum V_118 V_119 , union V_67 * V_13 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
int V_9 ;
F_67 ( V_6 -> V_22 , L_5 , V_119 ) ;
V_9 = F_16 ( V_6 -> V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
switch ( V_119 ) {
case V_120 :
V_9 = F_42 ( V_6 , V_13 ) ;
break;
case V_121 :
V_9 = F_44 ( V_6 , V_13 ) ;
break;
case V_122 :
V_9 = F_47 ( V_6 , V_13 ) ;
break;
case V_123 :
V_9 = F_50 ( V_6 , V_13 ) ;
break;
case V_124 :
V_9 = F_52 ( V_6 , V_13 ) ;
break;
case V_125 :
V_9 = F_56 ( V_6 , V_13 ) ;
break;
case V_126 :
V_9 = F_57 ( V_6 , V_13 ) ;
break;
case V_127 :
V_9 = F_58 ( V_6 , V_13 ) ;
break;
case V_128 :
V_9 = F_59 ( V_6 , V_13 ) ;
break;
case V_129 :
V_9 = F_61 ( V_6 , V_13 ) ;
break;
case V_130 :
V_9 = F_62 ( V_6 , V_13 ) ;
break;
case V_131 :
V_9 = F_64 ( V_6 , V_13 ) ;
break;
case V_132 :
V_13 -> V_74 = V_133 ;
V_9 = 0 ;
break;
case V_134 :
V_13 -> V_135 = V_6 -> V_136 ;
V_9 = 0 ;
break;
case V_137 :
V_13 -> V_135 = V_138 ;
V_9 = 0 ;
break;
default:
V_9 = - V_139 ;
}
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_68 ( struct V_25 * V_26 ,
enum V_118 V_119 ,
const union V_67 * V_13 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
int V_9 ;
F_67 ( V_6 -> V_22 , L_5 , V_119 ) ;
V_9 = F_16 ( V_6 -> V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
switch ( V_119 ) {
case V_122 :
V_9 = F_48 ( V_6 , V_13 ) ;
break;
case V_124 :
V_9 = F_54 ( V_6 , V_13 ) ;
break;
case V_120 :
V_9 = F_43 ( V_6 , V_13 ) ;
break;
case V_127 :
V_9 = F_60 ( V_6 , V_13 ) ;
break;
case V_129 :
V_9 = F_63 ( V_6 , V_13 ) ;
break;
case V_131 :
V_9 = F_65 ( V_6 , V_13 ) ;
break;
default:
V_9 = - V_29 ;
}
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_69 ( struct V_25 * V_26 ,
enum V_118 V_119 )
{
int V_9 ;
switch ( V_119 ) {
case V_122 :
case V_124 :
case V_120 :
case V_127 :
case V_129 :
case V_131 :
V_9 = 1 ;
break;
default:
V_9 = 0 ;
}
return V_9 ;
}
static void F_70 ( struct V_140 * V_141 )
{
struct V_5 * V_6 =
F_71 ( V_141 , struct V_5 ,
V_142 . V_141 ) ;
F_72 ( V_6 -> V_31 ) ;
}
static void F_73 ( struct V_25 * V_26 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
F_74 ( V_143 , & V_6 -> V_142 ,
F_75 ( 300 ) ) ;
}
static int F_51 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
T_1 V_144 , V_145 ;
int V_146 , V_9 ;
F_45 ( & V_6 -> V_81 ) ;
V_145 = V_6 -> V_82 ;
F_46 ( & V_6 -> V_81 ) ;
V_145 &= V_90 ;
V_145 >>= V_91 ;
V_9 = F_2 ( V_6 , V_98 , & V_144 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! ( V_144 & V_99 ) || V_145 ) {
V_146 = V_147 ;
} else {
V_144 &= V_148 ;
V_144 >>= V_149 ;
switch ( V_144 ) {
case 0x0 :
V_146 = V_150 ;
break;
case 0x1 :
case 0x2 :
V_146 = V_151 ;
break;
case 0x3 :
V_146 = V_152 ;
break;
default:
V_9 = - V_66 ;
}
}
if ( ! V_9 )
V_13 -> V_74 = V_146 ;
return V_9 ;
}
static int F_76 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
T_1 V_3 ;
int V_80 ;
F_45 ( & V_6 -> V_81 ) ;
V_3 = V_6 -> V_82 ;
F_46 ( & V_6 -> V_81 ) ;
if ( V_3 & V_88 ) {
V_80 = V_89 ;
} else {
V_3 &= V_83 ;
V_3 >>= V_84 ;
switch ( V_3 ) {
case 0x0 :
V_80 = V_95 ;
break;
case 0x1 :
case 0x3 :
case 0x5 :
V_80 = V_85 ;
break;
case 0x2 :
case 0x4 :
case 0x6 :
V_80 = V_86 ;
break;
default:
V_80 = V_87 ;
}
}
V_13 -> V_74 = V_80 ;
return 0 ;
}
static int F_77 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
T_1 V_97 ;
int V_9 ;
V_9 = F_6 ( V_6 , V_101 ,
V_102 ,
V_103 , & V_97 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_74 = ! V_97 ;
return 0 ;
}
static int F_49 ( struct V_5 * V_6 ,
const union V_67 * V_13 )
{
return F_7 ( V_6 , V_101 ,
V_102 ,
V_103 , ! V_13 -> V_74 ) ;
}
static int F_53 ( struct V_5 * V_6 ,
union V_67 * V_13 )
{
int V_153 , V_9 ;
V_9 = F_8 ( V_6 , V_154 ,
V_155 ,
V_156 ,
V_157 ,
F_11 ( V_157 ) , & V_153 ) ;
if ( V_9 < 0 )
return V_9 ;
V_13 -> V_74 = V_153 ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 ,
const union V_67 * V_13 )
{
return F_9 ( V_6 , V_154 ,
V_155 ,
V_156 ,
V_157 ,
F_11 ( V_157 ) , V_13 -> V_74 ) ;
}
static int F_78 ( struct V_25 * V_26 ,
enum V_118 V_119 , union V_67 * V_13 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
int V_9 ;
F_28 ( V_6 -> V_22 , L_6 ) ;
F_67 ( V_6 -> V_22 , L_5 , V_119 ) ;
V_9 = F_16 ( V_6 -> V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
switch ( V_119 ) {
case V_123 :
V_9 = F_51 ( V_6 , V_13 ) ;
break;
case V_121 :
V_9 = F_76 ( V_6 , V_13 ) ;
break;
case V_122 :
V_9 = F_77 ( V_6 , V_13 ) ;
break;
case V_158 :
V_13 -> V_74 = V_159 ;
V_9 = 0 ;
break;
case V_124 :
V_9 = F_53 ( V_6 , V_13 ) ;
break;
case V_132 :
V_13 -> V_74 = V_133 ;
V_9 = 0 ;
break;
default:
V_9 = - V_139 ;
}
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_79 ( struct V_25 * V_26 ,
enum V_118 V_119 ,
const union V_67 * V_13 )
{
struct V_5 * V_6 = F_15 ( V_26 ) ;
int V_9 ;
F_28 ( V_6 -> V_22 , L_6 ) ;
F_67 ( V_6 -> V_22 , L_5 , V_119 ) ;
V_9 = F_16 ( V_6 -> V_22 ) ;
if ( V_9 < 0 )
return V_9 ;
switch ( V_119 ) {
case V_122 :
V_9 = F_49 ( V_6 , V_13 ) ;
break;
case V_124 :
V_9 = F_55 ( V_6 , V_13 ) ;
break;
default:
V_9 = - V_29 ;
}
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
return V_9 ;
}
static int F_80 ( struct V_25 * V_26 ,
enum V_118 V_119 )
{
int V_9 ;
switch ( V_119 ) {
case V_122 :
case V_124 :
V_9 = 1 ;
break;
default:
V_9 = 0 ;
}
return V_9 ;
}
static void F_81 ( struct V_5 * V_6 )
{
const T_1 V_160 = V_148 ;
const T_1 V_161 = V_88
| V_83 ;
bool V_162 = false , V_163 = false ;
T_1 V_144 = 0 , V_82 = 0 ;
int V_4 , V_9 ;
V_9 = F_2 ( V_6 , V_98 , & V_144 ) ;
if ( V_9 < 0 ) {
F_37 ( V_6 -> V_22 , L_7 , V_9 ) ;
return;
}
V_4 = 0 ;
do {
V_9 = F_2 ( V_6 , V_164 , & V_82 ) ;
if ( V_9 < 0 ) {
F_37 ( V_6 -> V_22 , L_8 , V_9 ) ;
return;
}
} while ( V_82 && ++ V_4 < 2 );
if ( V_82 == ( 1 << V_91 ) &&
! ( V_144 & V_99 ) )
V_82 = 0 ;
if ( V_82 != V_6 -> V_82 ) {
F_28 ( V_6 -> V_22 ,
L_9 ,
! ! ( V_82 & V_94 ) ,
! ! ( V_82 & V_90 ) ,
! ! ( V_82 & V_88 ) ,
! ! ( V_82 & V_83 ) ) ;
F_45 ( & V_6 -> V_81 ) ;
if ( ( V_6 -> V_82 & V_161 ) != ( V_82 & V_161 ) )
V_163 = true ;
if ( ( V_6 -> V_82 & ~ V_161 ) != ( V_82 & ~ V_161 ) )
V_162 = true ;
V_6 -> V_82 = V_82 ;
F_46 ( & V_6 -> V_81 ) ;
}
if ( V_144 != V_6 -> V_144 ) {
if ( ( V_6 -> V_144 & V_99 ) &&
! ( V_144 & V_99 ) ) {
V_9 = F_7 ( V_6 , V_114 ,
V_165 ,
V_166 ,
0 ) ;
if ( V_9 < 0 )
F_37 ( V_6 -> V_22 , L_10 ,
V_9 ) ;
}
if ( ( V_6 -> V_144 & V_160 ) != ( V_144 & V_160 ) )
V_163 = true ;
if ( ( V_6 -> V_144 & ~ V_160 ) != ( V_144 & ~ V_160 ) )
V_162 = true ;
V_6 -> V_144 = V_144 ;
}
if ( V_162 || V_163 )
F_82 ( V_6 -> V_31 ) ;
if ( V_163 && V_6 -> V_167 )
F_82 ( V_6 -> V_167 ) ;
F_67 ( V_6 -> V_22 , L_11 , V_144 , V_82 ) ;
}
static T_4 F_83 ( int V_168 , void * V_8 )
{
struct V_5 * V_6 = V_8 ;
int error ;
V_6 -> V_169 = true ;
error = F_16 ( V_6 -> V_22 ) ;
if ( error < 0 ) {
F_28 ( V_6 -> V_22 , L_2 , error ) ;
F_29 ( V_6 -> V_22 ) ;
return V_170 ;
}
F_81 ( V_6 ) ;
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
V_6 -> V_169 = false ;
return V_171 ;
}
static void F_84 ( struct V_140 * V_141 )
{
struct V_5 * V_6 =
F_71 ( V_141 , struct V_5 , V_172 . V_141 ) ;
int error , V_173 = 0 ;
T_1 V_3 ;
error = F_16 ( V_6 -> V_22 ) ;
if ( error < 0 ) {
F_28 ( V_6 -> V_22 , L_2 , error ) ;
F_29 ( V_6 -> V_22 ) ;
return;
}
if ( F_85 ( V_6 -> V_174 , V_175 ) == 1 )
V_173 = 500000 ;
else if ( F_85 ( V_6 -> V_174 , V_176 ) == 1 ||
F_85 ( V_6 -> V_174 , V_177 ) == 1 )
V_173 = 1500000 ;
else if ( F_85 ( V_6 -> V_174 , V_178 ) == 1 )
V_173 = 2000000 ;
if ( V_173 ) {
error = F_9 ( V_6 , V_114 ,
V_115 ,
V_116 ,
V_117 ,
F_11 ( V_117 ) ,
V_173 ) ;
if ( error < 0 )
F_37 ( V_6 -> V_22 , L_12 , error ) ;
}
if ( ! V_173 && F_85 ( V_6 -> V_174 , V_179 ) == 1 )
V_3 = V_38 ;
else
V_3 = V_39 ;
error = F_7 ( V_6 , V_35 ,
V_36 ,
V_37 ,
V_3 ) ;
if ( error < 0 )
F_37 ( V_6 -> V_22 , L_13 , error ) ;
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
}
static int F_86 ( struct V_180 * V_181 , unsigned long V_182 ,
void * V_183 )
{
struct V_5 * V_6 =
F_71 ( V_181 , struct V_5 , V_184 ) ;
F_74 ( V_143 , & V_6 -> V_172 , F_75 ( 300 ) ) ;
return V_185 ;
}
static int F_87 ( struct V_5 * V_6 )
{
T_1 V_3 ;
int V_9 ;
V_9 = F_6 ( V_6 , V_186 ,
V_187 ,
V_188 ,
& V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_3 != V_189 &&
V_3 != V_190 ) {
F_37 ( V_6 -> V_22 , L_14 , V_3 ) ;
return - V_191 ;
}
V_9 = F_39 ( V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_38 ( V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_2 ( V_6 , V_98 , & V_6 -> V_144 ) ;
}
static int F_88 ( struct V_5 * V_6 )
{
const char * const V_192 = L_15 ;
struct V_193 V_27 = {} ;
int V_3 ;
if ( F_89 ( V_6 -> V_22 , V_192 , & V_3 ) == 0 ) {
V_3 /= 1000 ;
if ( V_3 >= V_194
&& V_3 <= V_195 )
V_6 -> V_54 = V_3 ;
else
F_28 ( V_6 -> V_22 , L_16 , V_192 , V_3 ) ;
}
if ( V_6 -> V_22 -> V_196 &&
! F_90 ( V_6 -> V_31 , & V_27 ) ) {
V_3 = V_27 . V_197 / 1000 ;
if ( V_3 >= V_198
&& V_3 <= V_199 )
V_6 -> V_57 = V_3 ;
else
F_28 ( V_6 -> V_22 , L_17 ,
V_3 ) ;
V_3 = V_27 . V_200 / 1000 ;
if ( V_3 >= V_201
&& V_3 <= V_202 )
V_6 -> V_61 = V_3 ;
else
F_28 ( V_6 -> V_22 , L_18 ,
V_3 ) ;
}
return 0 ;
}
static int F_91 ( struct V_203 * V_10 ,
const struct V_204 * V_205 )
{
struct V_206 * V_207 = F_92 ( V_10 -> V_22 . V_208 ) ;
struct V_21 * V_22 = & V_10 -> V_22 ;
struct V_209 V_210 = {} , V_211 = {} ;
struct V_5 * V_6 ;
const char * V_20 ;
int V_9 ;
if ( ! F_93 ( V_207 , V_212 ) ) {
F_37 ( V_22 , L_19 ) ;
return - V_191 ;
}
V_6 = F_94 ( V_22 , sizeof( * V_6 ) , V_213 ) ;
if ( ! V_6 ) {
F_37 ( V_22 , L_20 ) ;
return - V_214 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_22 = V_22 ;
strncpy ( V_6 -> V_136 , V_205 -> V_20 , V_215 ) ;
F_95 ( & V_6 -> V_81 ) ;
V_6 -> V_82 = 0 ;
V_6 -> V_144 = V_216 ;
F_96 ( & V_6 -> V_142 ,
F_70 ) ;
F_97 ( V_10 , V_6 ) ;
if ( V_10 -> V_168 <= 0 ) {
F_37 ( V_22 , L_21 ) ;
return - V_29 ;
}
if ( F_98 ( V_22 , L_22 , & V_20 ) == 0 ) {
V_6 -> V_174 = F_99 ( V_20 ) ;
if ( ! V_6 -> V_174 )
return - V_217 ;
F_100 ( V_6 -> V_22 , L_23 , V_20 ) ;
}
F_101 ( V_22 ) ;
F_102 ( V_22 ) ;
F_103 ( V_22 , 600 ) ;
V_9 = F_16 ( V_22 ) ;
if ( V_9 < 0 ) {
F_37 ( V_22 , L_2 , V_9 ) ;
goto V_218;
}
V_210 . V_219 = V_6 ;
V_210 . V_196 = V_22 -> V_196 ;
V_210 . V_220 = V_221 ;
V_210 . V_222 = F_11 ( V_221 ) ,
V_6 -> V_31 = F_104 ( V_22 , & V_223 ,
& V_210 ) ;
if ( F_35 ( V_6 -> V_31 ) ) {
F_37 ( V_22 , L_24 ) ;
V_9 = F_36 ( V_6 -> V_31 ) ;
goto V_218;
}
if ( ! F_40 ( V_22 , L_25 ) ) {
V_211 . V_219 = V_6 ;
V_6 -> V_167 = F_104 ( V_22 , & V_224 ,
& V_211 ) ;
if ( F_35 ( V_6 -> V_167 ) ) {
F_37 ( V_22 , L_26 ) ;
V_9 = F_36 ( V_6 -> V_167 ) ;
goto V_225;
}
}
V_9 = F_88 ( V_6 ) ;
if ( V_9 < 0 ) {
F_37 ( V_22 , L_27 ) ;
goto V_225;
}
V_9 = F_87 ( V_6 ) ;
if ( V_9 < 0 ) {
F_37 ( V_22 , L_28 ) ;
goto V_225;
}
V_9 = F_22 ( V_6 ) ;
if ( V_9 < 0 ) {
F_37 ( V_22 , L_29 ) ;
goto V_225;
}
V_6 -> V_226 = true ;
V_9 = F_105 ( V_22 , V_10 -> V_168 , NULL ,
F_83 ,
V_227 | V_228 ,
L_30 , V_6 ) ;
if ( V_9 < 0 ) {
F_37 ( V_22 , L_31 ) ;
goto V_229;
}
V_9 = F_33 ( V_6 ) ;
if ( V_9 < 0 )
goto V_229;
if ( V_6 -> V_174 ) {
F_96 ( & V_6 -> V_172 , F_84 ) ;
V_6 -> V_184 . V_230 = F_86 ;
V_9 = F_106 ( V_22 , V_6 -> V_174 ,
& V_6 -> V_184 ) ;
if ( V_9 ) {
F_37 ( V_22 , L_32 ) ;
goto V_229;
}
F_74 ( V_143 , & V_6 -> V_172 , 0 ) ;
}
F_107 ( V_10 -> V_168 ) ;
F_18 ( V_22 ) ;
F_19 ( V_22 ) ;
return 0 ;
V_229:
F_24 ( V_6 ) ;
V_225:
if ( ! F_108 ( V_6 -> V_167 ) )
F_109 ( V_6 -> V_167 ) ;
F_109 ( V_6 -> V_31 ) ;
V_218:
F_110 ( V_22 ) ;
F_111 ( V_22 ) ;
F_112 ( V_22 ) ;
return V_9 ;
}
static int F_113 ( struct V_203 * V_10 )
{
struct V_5 * V_6 = F_114 ( V_10 ) ;
int error ;
error = F_16 ( V_6 -> V_22 ) ;
if ( error < 0 ) {
F_28 ( V_6 -> V_22 , L_2 , error ) ;
F_29 ( V_6 -> V_22 ) ;
}
F_39 ( V_6 ) ;
F_24 ( V_6 ) ;
if ( V_6 -> V_167 )
F_109 ( V_6 -> V_167 ) ;
F_109 ( V_6 -> V_31 ) ;
if ( error >= 0 )
F_110 ( V_6 -> V_22 ) ;
F_111 ( V_6 -> V_22 ) ;
F_112 ( V_6 -> V_22 ) ;
return 0 ;
}
static T_5 int F_115 ( struct V_21 * V_22 )
{
struct V_203 * V_10 = F_116 ( V_22 ) ;
struct V_5 * V_6 = F_114 ( V_10 ) ;
if ( ! V_6 -> V_226 )
return 0 ;
F_67 ( V_6 -> V_22 , L_33 , V_231 ) ;
return 0 ;
}
static T_5 int F_117 ( struct V_21 * V_22 )
{
struct V_203 * V_10 = F_116 ( V_22 ) ;
struct V_5 * V_6 = F_114 ( V_10 ) ;
if ( ! V_6 -> V_226 )
return 0 ;
if ( ! V_6 -> V_169 ) {
F_67 ( V_6 -> V_22 , L_34 ) ;
F_81 ( V_6 ) ;
}
return 0 ;
}
static T_5 int F_118 ( struct V_21 * V_22 )
{
struct V_203 * V_10 = F_116 ( V_22 ) ;
struct V_5 * V_6 = F_114 ( V_10 ) ;
int error ;
error = F_16 ( V_6 -> V_22 ) ;
if ( error < 0 ) {
F_28 ( V_6 -> V_22 , L_2 , error ) ;
F_29 ( V_6 -> V_22 ) ;
}
F_39 ( V_6 ) ;
if ( error >= 0 ) {
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
}
return 0 ;
}
static T_5 int F_119 ( struct V_21 * V_22 )
{
struct V_203 * V_10 = F_116 ( V_22 ) ;
struct V_5 * V_6 = F_114 ( V_10 ) ;
int error ;
V_6 -> V_82 = 0 ;
V_6 -> V_144 = V_216 ;
error = F_16 ( V_6 -> V_22 ) ;
if ( error < 0 ) {
F_28 ( V_6 -> V_22 , L_2 , error ) ;
F_29 ( V_6 -> V_22 ) ;
}
F_39 ( V_6 ) ;
F_38 ( V_6 ) ;
F_2 ( V_6 , V_98 , & V_6 -> V_144 ) ;
if ( error >= 0 ) {
F_18 ( V_6 -> V_22 ) ;
F_19 ( V_6 -> V_22 ) ;
}
F_82 ( V_6 -> V_31 ) ;
if ( V_6 -> V_167 )
F_82 ( V_6 -> V_167 ) ;
return 0 ;
}
