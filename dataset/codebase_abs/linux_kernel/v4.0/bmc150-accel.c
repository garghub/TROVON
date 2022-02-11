static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
int V_5 )
{
int V_6 ;
int V_7 ;
T_1 V_8 ;
int V_9 = - 1 ;
if ( V_5 > 0 ) {
for ( V_6 = 0 ; V_6 < F_2 ( V_10 ) ;
++ V_6 ) {
if ( V_10 [ V_6 ] . V_11 ==
V_5 )
V_9 =
V_10 [ V_6 ] . V_12 ;
}
} else
V_9 = 0 ;
if ( V_9 < 0 )
return - V_13 ;
V_8 = V_4 << V_14 ;
V_8 |= ( V_9 << V_15 ) ;
F_3 ( & V_2 -> V_16 -> V_17 , L_1 , V_8 ) ;
V_7 = F_4 ( V_2 -> V_16 ,
V_18 , V_8 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_2 ) ;
return V_7 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_19 ,
int V_20 )
{
int V_6 ;
int V_7 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_21 ) ; ++ V_6 ) {
if ( V_21 [ V_6 ] . V_19 == V_19 &&
V_21 [ V_6 ] . V_20 == V_20 ) {
V_7 = F_4 (
V_2 -> V_16 ,
V_22 ,
V_21 [ V_6 ] . V_23 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_23 =
V_21 [ V_6 ] . V_23 ;
return 0 ;
}
}
return - V_13 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_8 ( V_2 -> V_16 , V_24 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_3 ) ;
return V_7 ;
}
F_3 ( & V_2 -> V_16 -> V_17 , L_4 , V_7 ) ;
if ( V_7 != V_2 -> V_25 -> V_26 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_5 , V_7 ) ;
return - V_27 ;
}
V_7 = F_1 ( V_2 , V_28 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_2 , V_29 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_16 ,
V_30 ,
V_31 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_6 ) ;
return V_7 ;
}
V_2 -> V_32 = V_31 ;
V_7 = F_8 ( V_2 -> V_16 , V_33 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_7 ) ;
return V_7 ;
}
V_2 -> V_34 |= V_35 ;
V_7 = F_4 ( V_2 -> V_16 ,
V_33 ,
V_2 -> V_34 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_8 ) ;
return V_7 ;
}
F_3 ( & V_2 -> V_16 -> V_17 , L_9 , V_2 -> V_34 ) ;
V_7 = F_4 ( V_2 -> V_16 ,
V_36 ,
V_37 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_10 ) ;
return V_7 ;
}
V_2 -> V_38 = V_37 ;
F_3 ( & V_2 -> V_16 -> V_17 , L_11 , V_2 -> V_38 ) ;
V_7 = F_4 ( V_2 -> V_16 ,
V_39 ,
V_40 |
V_41 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_12 ) ;
return V_7 ;
}
return 0 ;
}
static int F_9 (
struct V_1 * V_2 ,
bool V_42 )
{
int V_7 ;
V_7 = F_8 ( V_2 -> V_16 ,
V_43 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_13 ) ;
return V_7 ;
}
if ( V_42 )
V_7 |= V_44 ;
else
V_7 &= ~ V_44 ;
V_7 = F_4 ( V_2 -> V_16 ,
V_43 ,
V_7 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_14 ) ;
return V_7 ;
}
if ( V_42 ) {
V_7 = F_4 ( V_2 -> V_16 ,
V_33 ,
V_2 -> V_34 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_15 ) ;
return V_7 ;
}
V_7 = F_4 ( V_2 -> V_16 ,
V_36 ,
V_2 -> V_38 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_16 ) ;
return V_7 ;
}
if ( ! V_2 -> V_45 ) {
V_7 = F_4 ( V_2 -> V_16 ,
V_39 ,
V_40 |
V_41 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_12 ) ;
return V_7 ;
}
}
V_7 = F_4 ( V_2 -> V_16 ,
V_46 ,
V_47 |
V_48 |
V_49 ) ;
} else
V_7 = F_4 ( V_2 -> V_16 ,
V_46 ,
0 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_17 ) ;
return V_7 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
bool V_42 )
{
int V_7 ;
V_7 = F_8 ( V_2 -> V_16 ,
V_50 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_18 ) ;
return V_7 ;
}
if ( V_42 )
V_7 |= V_51 ;
else
V_7 &= ~ V_51 ;
V_7 = F_4 ( V_2 -> V_16 ,
V_50 ,
V_7 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_19 ) ;
return V_7 ;
}
if ( V_42 ) {
V_7 = F_4 ( V_2 -> V_16 ,
V_39 ,
V_52 |
V_41 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_12 ) ;
return V_7 ;
}
V_7 = F_4 ( V_2 -> V_16 ,
V_53 ,
V_54 ) ;
} else {
V_7 = F_4 ( V_2 -> V_16 ,
V_39 ,
V_40 |
V_41 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_12 ) ;
return V_7 ;
}
V_7 = F_4 ( V_2 -> V_16 ,
V_53 ,
0 ) ;
}
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_20 ) ;
return V_7 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int * V_19 ,
int * V_20 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_21 ) ; ++ V_6 ) {
if ( V_21 [ V_6 ] . V_23 == V_2 -> V_23 ) {
* V_19 = V_21 [ V_6 ] . V_19 ;
* V_20 = V_21 [ V_6 ] . V_20 ;
return V_55 ;
}
}
return - V_13 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_56 ) ; ++ V_6 ) {
if ( V_56 [ V_6 ] . V_23 == V_2 -> V_23 )
return V_56 [ V_6 ] . V_57 ;
}
return V_58 ;
}
static int F_13 ( struct V_1 * V_2 , bool V_59 )
{
int V_7 ;
if ( V_59 )
V_7 = F_14 ( & V_2 -> V_16 -> V_17 ) ;
else {
F_15 ( & V_2 -> V_16 -> V_17 ) ;
V_7 = F_16 ( & V_2 -> V_16 -> V_17 ) ;
}
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_21 , V_59 ) ;
if ( V_59 )
F_17 ( & V_2 -> V_16 -> V_17 ) ;
return V_7 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , bool V_59 )
{
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_19 )
{
int V_7 , V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_2 -> V_25 -> V_60 ) ; ++ V_6 ) {
if ( V_2 -> V_25 -> V_60 [ V_6 ] . V_61 == V_19 ) {
V_7 = F_4 (
V_2 -> V_16 ,
V_30 ,
V_2 -> V_25 -> V_60 [ V_6 ] . V_62 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_22 ) ;
return V_7 ;
}
V_2 -> V_32 = V_2 -> V_25 -> V_60 [ V_6 ] . V_62 ;
return 0 ;
}
}
return - V_13 ;
}
static int F_19 ( struct V_1 * V_2 , int * V_19 )
{
int V_7 ;
F_20 ( & V_2 -> V_63 ) ;
V_7 = F_8 ( V_2 -> V_16 , V_64 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_23 ) ;
F_21 ( & V_2 -> V_63 ) ;
return V_7 ;
}
* V_19 = F_22 ( V_7 , 7 ) ;
F_21 ( & V_2 -> V_63 ) ;
return V_65 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_66 const * V_67 ,
int * V_19 )
{
int V_7 ;
int V_68 = V_67 -> V_69 ;
F_20 ( & V_2 -> V_63 ) ;
V_7 = F_13 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_21 ( & V_2 -> V_63 ) ;
return V_7 ;
}
V_7 = F_24 ( V_2 -> V_16 ,
F_25 ( V_68 ) ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_24 , V_68 ) ;
F_13 ( V_2 , false ) ;
F_21 ( & V_2 -> V_63 ) ;
return V_7 ;
}
* V_19 = F_22 ( V_7 >> V_67 -> V_70 . V_71 ,
V_67 -> V_70 . V_72 - 1 ) ;
V_7 = F_13 ( V_2 , false ) ;
F_21 ( & V_2 -> V_63 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_65 ;
}
static int F_26 ( struct V_73 * V_74 ,
struct V_66 const * V_67 ,
int * V_19 , int * V_20 , long V_75 )
{
struct V_1 * V_2 = F_27 ( V_74 ) ;
int V_7 ;
switch ( V_75 ) {
case V_76 :
switch ( V_67 -> type ) {
case V_77 :
return F_19 ( V_2 , V_19 ) ;
case V_78 :
if ( F_28 ( V_74 ) )
return - V_79 ;
else
return F_23 ( V_2 , V_67 , V_19 ) ;
default:
return - V_13 ;
}
case V_80 :
if ( V_67 -> type == V_77 ) {
* V_19 = V_81 ;
return V_65 ;
} else
return - V_13 ;
case V_82 :
* V_19 = 0 ;
switch ( V_67 -> type ) {
case V_77 :
* V_20 = 500000 ;
return V_55 ;
case V_78 :
{
int V_6 ;
const struct V_83 * V_84 ;
int V_85 = F_2 ( V_2 -> V_25 -> V_60 ) ;
for ( V_6 = 0 ; V_6 < V_85 ; ++ V_6 ) {
V_84 = & V_2 -> V_25 -> V_60 [ V_6 ] ;
if ( V_84 -> V_62 == V_2 -> V_32 ) {
* V_20 = V_84 -> V_61 ;
return V_55 ;
}
}
return - V_13 ;
}
default:
return - V_13 ;
}
case V_86 :
F_20 ( & V_2 -> V_63 ) ;
V_7 = F_11 ( V_2 , V_19 , V_20 ) ;
F_21 ( & V_2 -> V_63 ) ;
return V_7 ;
default:
return - V_13 ;
}
}
static int F_29 ( struct V_73 * V_74 ,
struct V_66 const * V_67 ,
int V_19 , int V_20 , long V_75 )
{
struct V_1 * V_2 = F_27 ( V_74 ) ;
int V_7 ;
switch ( V_75 ) {
case V_86 :
F_20 ( & V_2 -> V_63 ) ;
V_7 = F_6 ( V_2 , V_19 , V_20 ) ;
F_21 ( & V_2 -> V_63 ) ;
break;
case V_82 :
if ( V_19 )
return - V_13 ;
F_20 ( & V_2 -> V_63 ) ;
V_7 = F_18 ( V_2 , V_20 ) ;
F_21 ( & V_2 -> V_63 ) ;
return V_7 ;
default:
V_7 = - V_13 ;
}
return V_7 ;
}
static int F_30 ( struct V_73 * V_74 ,
const struct V_66 * V_67 ,
enum V_87 type ,
enum V_88 V_89 ,
enum V_90 V_91 ,
int * V_19 , int * V_20 )
{
struct V_1 * V_2 = F_27 ( V_74 ) ;
* V_20 = 0 ;
switch ( V_91 ) {
case V_92 :
* V_19 = V_2 -> V_38 ;
break;
case V_93 :
* V_19 = V_2 -> V_34 & V_94 ;
break;
default:
return - V_13 ;
}
return V_65 ;
}
static int F_31 ( struct V_73 * V_74 ,
const struct V_66 * V_67 ,
enum V_87 type ,
enum V_88 V_89 ,
enum V_90 V_91 ,
int V_19 , int V_20 )
{
struct V_1 * V_2 = F_27 ( V_74 ) ;
if ( V_2 -> V_95 )
return - V_79 ;
switch ( V_91 ) {
case V_92 :
V_2 -> V_38 = V_19 ;
break;
case V_93 :
V_2 -> V_34 &= ~ V_94 ;
V_2 -> V_34 |= V_19 & V_94 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_32 ( struct V_73 * V_74 ,
const struct V_66 * V_67 ,
enum V_87 type ,
enum V_88 V_89 )
{
struct V_1 * V_2 = F_27 ( V_74 ) ;
return V_2 -> V_95 ;
}
static int F_33 ( struct V_73 * V_74 ,
const struct V_66 * V_67 ,
enum V_87 type ,
enum V_88 V_89 ,
int V_96 )
{
struct V_1 * V_2 = F_27 ( V_74 ) ;
int V_7 ;
if ( V_96 && V_2 -> V_95 )
return 0 ;
F_20 ( & V_2 -> V_63 ) ;
if ( ! V_96 && V_2 -> V_97 ) {
V_2 -> V_95 = 0 ;
F_21 ( & V_2 -> V_63 ) ;
return 0 ;
}
V_7 = F_13 ( V_2 , V_96 ) ;
if ( V_7 < 0 ) {
F_21 ( & V_2 -> V_63 ) ;
return V_7 ;
}
V_7 = F_9 ( V_2 , V_96 ) ;
if ( V_7 < 0 ) {
F_13 ( V_2 , false ) ;
F_21 ( & V_2 -> V_63 ) ;
return V_7 ;
}
V_2 -> V_95 = V_96 ;
F_21 ( & V_2 -> V_63 ) ;
return 0 ;
}
static int F_34 ( struct V_73 * V_74 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = F_27 ( V_74 ) ;
if ( V_2 -> V_100 != V_99 && V_2 -> V_101 != V_99 )
return - V_13 ;
return 0 ;
}
static T_2 F_35 ( int V_102 , void * V_103 )
{
struct V_104 * V_105 = V_103 ;
struct V_73 * V_74 = V_105 -> V_74 ;
struct V_1 * V_2 = F_27 ( V_74 ) ;
int V_106 , V_7 , V_6 = 0 ;
F_20 ( & V_2 -> V_63 ) ;
F_36 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_7 = F_24 ( V_2 -> V_16 ,
F_25 ( V_106 ) ) ;
if ( V_7 < 0 ) {
F_21 ( & V_2 -> V_63 ) ;
goto V_107;
}
V_2 -> V_108 [ V_6 ++ ] = V_7 ;
}
F_21 ( & V_2 -> V_63 ) ;
F_37 ( V_74 , V_2 -> V_108 ,
V_2 -> V_109 ) ;
V_107:
F_38 ( V_74 -> V_99 ) ;
return V_110 ;
}
static int F_39 ( struct V_98 * V_99 )
{
struct V_73 * V_74 = F_40 ( V_99 ) ;
struct V_1 * V_2 = F_27 ( V_74 ) ;
int V_7 ;
if ( V_2 -> V_45 )
return 0 ;
F_20 ( & V_2 -> V_63 ) ;
V_7 = F_4 ( V_2 -> V_16 ,
V_39 ,
V_40 |
V_41 ) ;
F_21 ( & V_2 -> V_63 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_12 ) ;
return V_7 ;
}
return 0 ;
}
static int F_41 ( struct V_98 * V_99 ,
bool V_96 )
{
struct V_73 * V_74 = F_40 ( V_99 ) ;
struct V_1 * V_2 = F_27 ( V_74 ) ;
int V_7 ;
F_20 ( & V_2 -> V_63 ) ;
if ( ! V_96 && V_2 -> V_95 && V_2 -> V_97 ) {
V_2 -> V_97 = false ;
F_21 ( & V_2 -> V_63 ) ;
return 0 ;
}
V_7 = F_13 ( V_2 , V_96 ) ;
if ( V_7 < 0 ) {
F_21 ( & V_2 -> V_63 ) ;
return V_7 ;
}
if ( V_2 -> V_101 == V_99 )
V_7 = F_9 ( V_2 , V_96 ) ;
else
V_7 = F_10 ( V_2 , V_96 ) ;
if ( V_7 < 0 ) {
F_13 ( V_2 , false ) ;
F_21 ( & V_2 -> V_63 ) ;
return V_7 ;
}
if ( V_2 -> V_101 == V_99 )
V_2 -> V_97 = V_96 ;
else
V_2 -> V_45 = V_96 ;
F_21 ( & V_2 -> V_63 ) ;
return V_7 ;
}
static T_2 F_42 ( int V_102 , void * V_111 )
{
struct V_73 * V_74 = V_111 ;
struct V_1 * V_2 = F_27 ( V_74 ) ;
int V_7 ;
int V_89 ;
V_7 = F_8 ( V_2 -> V_16 ,
V_112 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_25 ) ;
goto V_113;
}
if ( V_7 & V_114 )
V_89 = V_115 ;
else
V_89 = V_116 ;
if ( V_7 & V_117 )
F_43 ( V_74 , F_44 ( V_78 ,
0 ,
V_118 ,
V_119 ,
V_89 ) ,
V_2 -> V_109 ) ;
if ( V_7 & V_120 )
F_43 ( V_74 , F_44 ( V_78 ,
0 ,
V_121 ,
V_119 ,
V_89 ) ,
V_2 -> V_109 ) ;
if ( V_7 & V_122 )
F_43 ( V_74 , F_44 ( V_78 ,
0 ,
V_123 ,
V_119 ,
V_89 ) ,
V_2 -> V_109 ) ;
V_113:
if ( ! V_2 -> V_45 )
V_7 = F_4 ( V_2 -> V_16 ,
V_39 ,
V_40 |
V_41 ) ;
return V_110 ;
}
static T_2 F_45 ( int V_102 , void * V_111 )
{
struct V_73 * V_74 = V_111 ;
struct V_1 * V_2 = F_27 ( V_74 ) ;
V_2 -> V_109 = F_46 () ;
if ( V_2 -> V_45 )
F_47 ( V_2 -> V_100 ) ;
else if ( V_2 -> V_97 )
F_47 ( V_2 -> V_101 ) ;
if ( V_2 -> V_95 )
return V_124 ;
else
return V_110 ;
}
static const char * F_48 ( struct V_125 * V_17 , int * V_2 )
{
const struct V_126 * V_127 ;
V_127 = F_49 ( V_17 -> V_128 -> V_129 , V_17 ) ;
if ( ! V_127 )
return NULL ;
* V_2 = ( int ) V_127 -> V_130 ;
return F_50 ( V_17 ) ;
}
static int F_51 ( struct V_131 * V_16 ,
struct V_1 * V_2 )
{
struct V_125 * V_17 ;
struct V_132 * V_133 ;
int V_7 ;
if ( ! V_16 )
return - V_13 ;
V_17 = & V_16 -> V_17 ;
V_133 = F_52 ( V_17 , V_134 , 0 ) ;
if ( F_53 ( V_133 ) ) {
F_5 ( V_17 , L_26 ) ;
return F_54 ( V_133 ) ;
}
V_7 = F_55 ( V_133 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_56 ( V_133 ) ;
F_3 ( V_17 , L_27 , F_57 ( V_133 ) , V_7 ) ;
return V_7 ;
}
static int F_58 ( struct V_131 * V_16 ,
const struct V_135 * V_127 )
{
struct V_1 * V_2 ;
struct V_73 * V_74 ;
int V_7 ;
const char * V_136 = NULL ;
int V_26 = 0 ;
V_74 = F_59 ( & V_16 -> V_17 , sizeof( * V_2 ) ) ;
if ( ! V_74 )
return - V_137 ;
V_2 = F_27 ( V_74 ) ;
F_60 ( V_16 , V_74 ) ;
V_2 -> V_16 = V_16 ;
if ( V_127 ) {
V_136 = V_127 -> V_136 ;
V_26 = V_127 -> V_130 ;
}
if ( F_61 ( & V_16 -> V_17 ) )
V_136 = F_48 ( & V_16 -> V_17 , & V_26 ) ;
V_2 -> V_25 = & V_138 [ V_26 ] ;
V_7 = F_7 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_62 ( & V_2 -> V_63 ) ;
V_74 -> V_17 . V_139 = & V_16 -> V_17 ;
V_74 -> V_140 = V_2 -> V_25 -> V_140 ;
V_74 -> V_141 = V_2 -> V_25 -> V_141 ;
V_74 -> V_136 = V_136 ;
V_74 -> V_142 = V_143 ;
V_74 -> V_91 = & V_144 ;
if ( V_16 -> V_102 < 0 )
V_16 -> V_102 = F_51 ( V_16 , V_2 ) ;
if ( V_16 -> V_102 >= 0 ) {
V_7 = F_63 (
& V_16 -> V_17 , V_16 -> V_102 ,
F_45 ,
F_42 ,
V_145 ,
V_146 ,
V_74 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_100 = F_64 ( & V_16 -> V_17 ,
L_28 ,
V_74 -> V_136 ,
V_74 -> V_127 ) ;
if ( ! V_2 -> V_100 )
return - V_137 ;
V_2 -> V_101 = F_64 ( & V_16 -> V_17 ,
L_29 ,
V_74 -> V_136 ,
V_74 -> V_127 ) ;
if ( ! V_2 -> V_101 )
return - V_137 ;
V_2 -> V_100 -> V_17 . V_139 = & V_16 -> V_17 ;
V_2 -> V_100 -> V_147 = & V_148 ;
F_65 ( V_2 -> V_100 , V_74 ) ;
V_7 = F_66 ( V_2 -> V_100 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_101 -> V_17 . V_139 = & V_16 -> V_17 ;
V_2 -> V_101 -> V_147 = & V_148 ;
F_65 ( V_2 -> V_101 , V_74 ) ;
V_7 = F_66 ( V_2 -> V_101 ) ;
if ( V_7 ) {
V_2 -> V_101 = NULL ;
goto V_149;
}
V_7 = F_67 ( V_74 ,
& V_150 ,
F_35 ,
NULL ) ;
if ( V_7 < 0 ) {
F_5 ( & V_16 -> V_17 ,
L_30 ) ;
goto V_149;
}
}
V_7 = F_68 ( V_74 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_16 -> V_17 , L_31 ) ;
goto V_151;
}
V_7 = F_69 ( & V_16 -> V_17 ) ;
if ( V_7 )
goto V_152;
F_70 ( & V_16 -> V_17 ) ;
F_71 ( & V_16 -> V_17 ,
V_153 ) ;
F_72 ( & V_16 -> V_17 ) ;
return 0 ;
V_152:
F_73 ( V_74 ) ;
V_151:
if ( V_2 -> V_100 )
F_74 ( V_74 ) ;
V_149:
if ( V_2 -> V_100 )
F_75 ( V_2 -> V_100 ) ;
if ( V_2 -> V_101 )
F_75 ( V_2 -> V_101 ) ;
return V_7 ;
}
static int F_76 ( struct V_131 * V_16 )
{
struct V_73 * V_74 = F_77 ( V_16 ) ;
struct V_1 * V_2 = F_27 ( V_74 ) ;
F_78 ( & V_16 -> V_17 ) ;
F_79 ( & V_16 -> V_17 ) ;
F_17 ( & V_16 -> V_17 ) ;
F_73 ( V_74 ) ;
if ( V_2 -> V_100 ) {
F_74 ( V_74 ) ;
F_75 ( V_2 -> V_100 ) ;
F_75 ( V_2 -> V_101 ) ;
}
F_20 ( & V_2 -> V_63 ) ;
F_1 ( V_2 , V_154 , 0 ) ;
F_21 ( & V_2 -> V_63 ) ;
return 0 ;
}
static int F_80 ( struct V_125 * V_17 )
{
struct V_73 * V_74 = F_77 ( F_81 ( V_17 ) ) ;
struct V_1 * V_2 = F_27 ( V_74 ) ;
F_20 ( & V_2 -> V_63 ) ;
F_1 ( V_2 , V_155 , 0 ) ;
F_21 ( & V_2 -> V_63 ) ;
return 0 ;
}
static int F_82 ( struct V_125 * V_17 )
{
struct V_73 * V_74 = F_77 ( F_81 ( V_17 ) ) ;
struct V_1 * V_2 = F_27 ( V_74 ) ;
F_20 ( & V_2 -> V_63 ) ;
if ( V_2 -> V_45 || V_2 -> V_97 ||
V_2 -> V_95 )
F_1 ( V_2 , V_28 , 0 ) ;
F_21 ( & V_2 -> V_63 ) ;
return 0 ;
}
static int F_83 ( struct V_125 * V_17 )
{
struct V_73 * V_74 = F_77 ( F_81 ( V_17 ) ) ;
struct V_1 * V_2 = F_27 ( V_74 ) ;
int V_7 ;
F_3 ( & V_2 -> V_16 -> V_17 , V_156 ) ;
V_7 = F_1 ( V_2 , V_155 , 0 ) ;
if ( V_7 < 0 )
return - V_157 ;
return 0 ;
}
static int F_84 ( struct V_125 * V_17 )
{
struct V_73 * V_74 = F_77 ( F_81 ( V_17 ) ) ;
struct V_1 * V_2 = F_27 ( V_74 ) ;
int V_7 ;
int V_158 ;
F_3 ( & V_2 -> V_16 -> V_17 , V_156 ) ;
V_7 = F_1 ( V_2 , V_28 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_158 = F_12 ( V_2 ) ;
if ( V_158 < 20 )
F_85 ( V_158 * 1000 , 20000 ) ;
else
F_86 ( V_158 ) ;
return 0 ;
}
