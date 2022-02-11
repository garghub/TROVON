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
int V_7 , V_19 ;
V_7 = F_4 ( V_2 -> V_16 , V_24 ,
V_2 -> V_25 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_3 ) ;
return V_7 ;
}
V_7 = F_8 ( V_2 -> V_16 , V_26 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_4 ) ;
return V_7 ;
}
V_19 = ( V_7 & ~ V_27 ) | V_2 -> V_28 ;
V_7 = F_4 ( V_2 -> V_16 , V_26 ,
V_19 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_5 ) ;
return V_7 ;
}
F_3 ( & V_2 -> V_16 -> V_17 , L_6 , V_29 , V_2 -> V_25 ,
V_2 -> V_28 ) ;
return V_7 ;
}
static int F_9 ( struct V_30 * V_31 ,
bool V_32 )
{
if ( V_32 )
return F_7 ( V_31 -> V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_8 ( V_2 -> V_16 , V_33 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_7 ) ;
return V_7 ;
}
F_3 ( & V_2 -> V_16 -> V_17 , L_8 , V_7 ) ;
if ( V_7 != V_2 -> V_34 -> V_35 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_9 , V_7 ) ;
return - V_36 ;
}
V_7 = F_1 ( V_2 , V_37 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_2 , V_38 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_16 ,
V_39 ,
V_40 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_10 ) ;
return V_7 ;
}
V_2 -> V_41 = V_40 ;
V_2 -> V_25 = V_42 ;
V_2 -> V_28 = V_43 ;
V_7 = F_7 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_16 ,
V_44 ,
V_45 |
V_46 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_11 ) ;
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
return V_47 ;
}
}
return - V_13 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_48 ) ; ++ V_6 ) {
if ( V_48 [ V_6 ] . V_23 == V_2 -> V_23 )
return V_48 [ V_6 ] . V_49 ;
}
return V_50 ;
}
static int F_13 ( struct V_1 * V_2 , bool V_51 )
{
int V_7 ;
if ( V_51 )
V_7 = F_14 ( & V_2 -> V_16 -> V_17 ) ;
else {
F_15 ( & V_2 -> V_16 -> V_17 ) ;
V_7 = F_16 ( & V_2 -> V_16 -> V_17 ) ;
}
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_12 , V_51 ) ;
if ( V_51 )
F_17 ( & V_2 -> V_16 -> V_17 ) ;
return V_7 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , bool V_51 )
{
return 0 ;
}
static void F_18 ( struct V_52 * V_53 ,
struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_54 ; V_6 ++ )
V_2 -> V_55 [ V_6 ] . V_56 = & V_57 [ V_6 ] ;
}
static int F_19 ( struct V_1 * V_2 , int V_6 ,
bool V_32 )
{
struct V_58 * V_59 = & V_2 -> V_55 [ V_6 ] ;
const struct V_60 * V_56 = V_59 -> V_56 ;
int V_7 ;
if ( V_32 ) {
if ( F_20 ( & V_59 -> V_61 ) > 1 )
return 0 ;
} else {
if ( F_21 ( & V_59 -> V_61 ) > 0 )
return 0 ;
}
V_7 = F_13 ( V_2 , V_32 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_8 ( V_2 -> V_16 , V_56 -> V_62 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_13 ) ;
goto V_63;
}
if ( V_32 )
V_7 |= V_56 -> V_64 ;
else
V_7 &= ~ V_56 -> V_64 ;
V_7 = F_4 ( V_2 -> V_16 , V_56 -> V_62 ,
V_7 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_14 ) ;
goto V_63;
}
V_7 = F_8 ( V_2 -> V_16 , V_56 -> V_65 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_15 ) ;
goto V_63;
}
if ( V_32 )
V_7 |= V_56 -> V_66 ;
else
V_7 &= ~ V_56 -> V_66 ;
V_7 = F_4 ( V_2 -> V_16 , V_56 -> V_65 , V_7 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_16 ) ;
goto V_63;
}
if ( V_32 )
F_22 ( & V_2 -> V_67 ) ;
else
F_23 ( & V_2 -> V_67 ) ;
return 0 ;
V_63:
F_13 ( V_2 , false ) ;
return V_7 ;
}
static int F_24 ( struct V_1 * V_2 , int V_19 )
{
int V_7 , V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_2 -> V_34 -> V_68 ) ; ++ V_6 ) {
if ( V_2 -> V_34 -> V_68 [ V_6 ] . V_69 == V_19 ) {
V_7 = F_4 (
V_2 -> V_16 ,
V_39 ,
V_2 -> V_34 -> V_68 [ V_6 ] . V_70 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_17 ) ;
return V_7 ;
}
V_2 -> V_41 = V_2 -> V_34 -> V_68 [ V_6 ] . V_70 ;
return 0 ;
}
}
return - V_13 ;
}
static int F_25 ( struct V_1 * V_2 , int * V_19 )
{
int V_7 ;
F_26 ( & V_2 -> V_71 ) ;
V_7 = F_8 ( V_2 -> V_16 , V_72 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_18 ) ;
F_27 ( & V_2 -> V_71 ) ;
return V_7 ;
}
* V_19 = F_28 ( V_7 , 7 ) ;
F_27 ( & V_2 -> V_71 ) ;
return V_73 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_74 const * V_75 ,
int * V_19 )
{
int V_7 ;
int V_76 = V_75 -> V_77 ;
F_26 ( & V_2 -> V_71 ) ;
V_7 = F_13 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_71 ) ;
return V_7 ;
}
V_7 = F_30 ( V_2 -> V_16 ,
F_31 ( V_76 ) ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_19 , V_76 ) ;
F_13 ( V_2 , false ) ;
F_27 ( & V_2 -> V_71 ) ;
return V_7 ;
}
* V_19 = F_28 ( V_7 >> V_75 -> V_78 . V_79 ,
V_75 -> V_78 . V_80 - 1 ) ;
V_7 = F_13 ( V_2 , false ) ;
F_27 ( & V_2 -> V_71 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_73 ;
}
static int F_32 ( struct V_52 * V_53 ,
struct V_74 const * V_75 ,
int * V_19 , int * V_20 , long V_81 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
int V_7 ;
switch ( V_81 ) {
case V_82 :
switch ( V_75 -> type ) {
case V_83 :
return F_25 ( V_2 , V_19 ) ;
case V_84 :
if ( F_34 ( V_53 ) )
return - V_85 ;
else
return F_29 ( V_2 , V_75 , V_19 ) ;
default:
return - V_13 ;
}
case V_86 :
if ( V_75 -> type == V_83 ) {
* V_19 = V_87 ;
return V_73 ;
} else
return - V_13 ;
case V_88 :
* V_19 = 0 ;
switch ( V_75 -> type ) {
case V_83 :
* V_20 = 500000 ;
return V_47 ;
case V_84 :
{
int V_6 ;
const struct V_89 * V_90 ;
int V_91 = F_2 ( V_2 -> V_34 -> V_68 ) ;
for ( V_6 = 0 ; V_6 < V_91 ; ++ V_6 ) {
V_90 = & V_2 -> V_34 -> V_68 [ V_6 ] ;
if ( V_90 -> V_70 == V_2 -> V_41 ) {
* V_20 = V_90 -> V_69 ;
return V_47 ;
}
}
return - V_13 ;
}
default:
return - V_13 ;
}
case V_92 :
F_26 ( & V_2 -> V_71 ) ;
V_7 = F_11 ( V_2 , V_19 , V_20 ) ;
F_27 ( & V_2 -> V_71 ) ;
return V_7 ;
default:
return - V_13 ;
}
}
static int F_35 ( struct V_52 * V_53 ,
struct V_74 const * V_75 ,
int V_19 , int V_20 , long V_81 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
int V_7 ;
switch ( V_81 ) {
case V_92 :
F_26 ( & V_2 -> V_71 ) ;
V_7 = F_6 ( V_2 , V_19 , V_20 ) ;
F_27 ( & V_2 -> V_71 ) ;
break;
case V_88 :
if ( V_19 )
return - V_13 ;
F_26 ( & V_2 -> V_71 ) ;
V_7 = F_24 ( V_2 , V_20 ) ;
F_27 ( & V_2 -> V_71 ) ;
return V_7 ;
default:
V_7 = - V_13 ;
}
return V_7 ;
}
static int F_36 ( struct V_52 * V_53 ,
const struct V_74 * V_75 ,
enum V_93 type ,
enum V_94 V_95 ,
enum V_96 V_56 ,
int * V_19 , int * V_20 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
* V_20 = 0 ;
switch ( V_56 ) {
case V_97 :
* V_19 = V_2 -> V_25 ;
break;
case V_98 :
* V_19 = V_2 -> V_28 ;
break;
default:
return - V_13 ;
}
return V_73 ;
}
static int F_37 ( struct V_52 * V_53 ,
const struct V_74 * V_75 ,
enum V_93 type ,
enum V_94 V_95 ,
enum V_96 V_56 ,
int V_19 , int V_20 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
if ( V_2 -> V_99 )
return - V_85 ;
switch ( V_56 ) {
case V_97 :
V_2 -> V_25 = V_19 & 0xFF ;
break;
case V_98 :
V_2 -> V_28 = V_19 & V_27 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_38 ( struct V_52 * V_53 ,
const struct V_74 * V_75 ,
enum V_93 type ,
enum V_94 V_95 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
return V_2 -> V_99 ;
}
static int F_39 ( struct V_52 * V_53 ,
const struct V_74 * V_75 ,
enum V_93 type ,
enum V_94 V_95 ,
int V_32 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
int V_7 ;
if ( V_32 == V_2 -> V_99 )
return 0 ;
F_26 ( & V_2 -> V_71 ) ;
V_7 = F_19 ( V_2 , V_100 ,
V_32 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_71 ) ;
return V_7 ;
}
V_2 -> V_99 = V_32 ;
F_27 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int F_40 ( struct V_52 * V_53 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_103 ; V_6 ++ ) {
if ( V_2 -> V_104 [ V_6 ] . V_105 == V_102 )
return 0 ;
}
return - V_13 ;
}
static T_2 F_41 ( struct V_106 * V_17 ,
struct V_107 * V_108 ,
char * V_109 )
{
struct V_52 * V_53 = F_42 ( V_17 ) ;
struct V_1 * V_2 = F_33 ( V_53 ) ;
int V_110 ;
F_26 ( & V_2 -> V_71 ) ;
V_110 = V_2 -> V_111 ;
F_27 ( & V_2 -> V_71 ) ;
return sprintf ( V_109 , L_20 , V_110 ) ;
}
static T_2 F_43 ( struct V_106 * V_17 ,
struct V_107 * V_108 ,
char * V_109 )
{
struct V_52 * V_53 = F_42 ( V_17 ) ;
struct V_1 * V_2 = F_33 ( V_53 ) ;
bool V_32 ;
F_26 ( & V_2 -> V_71 ) ;
V_32 = V_2 -> V_112 ;
F_27 ( & V_2 -> V_71 ) ;
return sprintf ( V_109 , L_20 , V_32 ) ;
}
static int F_44 ( struct V_52 * V_53 , unsigned V_19 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
if ( V_19 > V_113 )
V_19 = V_113 ;
F_26 ( & V_2 -> V_71 ) ;
V_2 -> V_111 = V_19 ;
F_27 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int F_45 ( const struct V_114 * V_16 ,
char * V_115 , int V_116 )
{
int V_117 = 3 * 2 ;
T_1 V_118 = V_119 ;
int V_7 = - V_120 ;
if ( F_46 ( V_16 -> V_121 , V_122 ) ) {
struct V_123 V_124 [ 2 ] = {
{
. V_125 = V_16 -> V_125 ,
. V_126 = 0 ,
. V_109 = & V_118 ,
. V_127 = sizeof( V_118 ) ,
} ,
{
. V_125 = V_16 -> V_125 ,
. V_126 = V_128 ,
. V_109 = ( T_1 * ) V_115 ,
. V_127 = V_116 * V_117 ,
}
} ;
V_7 = F_47 ( V_16 -> V_121 , V_124 , 2 ) ;
if ( V_7 != 2 )
V_7 = - V_120 ;
else
V_7 = 0 ;
} else {
int V_6 , V_129 = V_130 / V_117 ;
for ( V_6 = 0 ; V_6 < V_116 * V_117 ; V_6 += V_129 ) {
V_7 = F_48 ( V_16 ,
V_118 , V_129 ,
& V_115 [ V_6 ] ) ;
if ( V_7 != V_129 ) {
V_7 = - V_120 ;
break;
}
V_7 = 0 ;
}
}
if ( V_7 )
F_5 ( & V_16 -> V_17 , L_21 ) ;
return V_7 ;
}
static int F_49 ( struct V_52 * V_53 ,
unsigned V_116 , bool V_131 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
int V_7 , V_6 ;
T_1 V_132 ;
T_3 V_115 [ V_113 * 3 ] ;
T_4 V_133 ;
T_5 V_134 ;
V_7 = F_8 ( V_2 -> V_16 ,
V_135 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_22 ) ;
return V_7 ;
}
V_132 = V_7 & 0x7F ;
if ( ! V_132 )
return 0 ;
if ( ! V_131 ) {
V_2 -> V_136 = V_2 -> V_137 ;
V_2 -> V_137 = F_50 () ;
}
V_134 = ( V_2 -> V_137 - V_2 -> V_136 ) ;
F_51 ( V_134 , V_132 ) ;
V_133 = V_2 -> V_137 - ( V_132 - 1 ) * V_134 ;
if ( V_116 && V_132 > V_116 )
V_132 = V_116 ;
V_7 = F_45 ( V_2 -> V_16 , ( T_1 * ) V_115 , V_132 ) ;
if ( V_7 )
return V_7 ;
for ( V_6 = 0 ; V_6 < V_132 ; V_6 ++ ) {
T_3 V_138 [ 8 ] ;
int V_139 , V_140 ;
V_139 = 0 ;
F_52 (bit, indio_dev->active_scan_mask,
indio_dev->masklength)
memcpy ( & V_138 [ V_139 ++ ] , & V_115 [ V_6 * 3 + V_140 ] , 2 ) ;
F_53 ( V_53 , V_138 , V_133 ) ;
V_133 += V_134 ;
}
return V_132 ;
}
static int F_54 ( struct V_52 * V_53 , unsigned V_116 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
int V_7 ;
F_26 ( & V_2 -> V_71 ) ;
V_7 = F_49 ( V_53 , V_116 , false ) ;
F_27 ( & V_2 -> V_71 ) ;
return V_7 ;
}
static T_6 F_55 ( int V_131 , void * V_141 )
{
struct V_142 * V_143 = V_141 ;
struct V_52 * V_53 = V_143 -> V_53 ;
struct V_1 * V_2 = F_33 ( V_53 ) ;
int V_140 , V_7 , V_6 = 0 ;
F_26 ( & V_2 -> V_71 ) ;
F_52 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_7 = F_30 ( V_2 -> V_16 ,
F_31 ( V_140 ) ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_71 ) ;
goto V_144;
}
V_2 -> V_115 [ V_6 ++ ] = V_7 ;
}
F_27 ( & V_2 -> V_71 ) ;
F_53 ( V_53 , V_2 -> V_115 ,
V_2 -> V_137 ) ;
V_144:
F_56 ( V_53 -> V_102 ) ;
return V_145 ;
}
static int F_57 ( struct V_101 * V_102 )
{
struct V_30 * V_31 = F_58 ( V_102 ) ;
struct V_1 * V_2 = V_31 -> V_2 ;
int V_7 ;
if ( V_31 == & V_31 -> V_2 -> V_104 [ V_146 ] )
return 0 ;
F_26 ( & V_2 -> V_71 ) ;
V_7 = F_4 ( V_2 -> V_16 ,
V_44 ,
V_45 |
V_46 ) ;
F_27 ( & V_2 -> V_71 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_11 ) ;
return V_7 ;
}
return 0 ;
}
static int F_59 ( struct V_101 * V_102 ,
bool V_32 )
{
struct V_30 * V_31 = F_58 ( V_102 ) ;
struct V_1 * V_2 = V_31 -> V_2 ;
int V_7 ;
F_26 ( & V_2 -> V_71 ) ;
if ( V_31 -> V_147 == V_32 ) {
F_27 ( & V_2 -> V_71 ) ;
return 0 ;
}
if ( V_31 -> V_148 ) {
V_7 = V_31 -> V_148 ( V_31 , V_32 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_71 ) ;
return V_7 ;
}
}
V_7 = F_19 ( V_2 , V_31 -> V_59 , V_32 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_71 ) ;
return V_7 ;
}
V_31 -> V_147 = V_32 ;
F_27 ( & V_2 -> V_71 ) ;
return V_7 ;
}
static int F_60 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
int V_95 ;
int V_7 ;
V_7 = F_8 ( V_2 -> V_16 ,
V_149 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_23 ) ;
return V_7 ;
}
if ( V_7 & V_150 )
V_95 = V_151 ;
else
V_95 = V_152 ;
if ( V_7 & V_153 )
F_61 ( V_53 , F_62 ( V_84 ,
0 ,
V_154 ,
V_155 ,
V_95 ) ,
V_2 -> V_137 ) ;
if ( V_7 & V_156 )
F_61 ( V_53 , F_62 ( V_84 ,
0 ,
V_157 ,
V_155 ,
V_95 ) ,
V_2 -> V_137 ) ;
if ( V_7 & V_158 )
F_61 ( V_53 , F_62 ( V_84 ,
0 ,
V_159 ,
V_155 ,
V_95 ) ,
V_2 -> V_137 ) ;
return V_7 ;
}
static T_6 F_63 ( int V_131 , void * V_160 )
{
struct V_52 * V_53 = V_160 ;
struct V_1 * V_2 = F_33 ( V_53 ) ;
bool V_161 = false ;
int V_7 ;
F_26 ( & V_2 -> V_71 ) ;
if ( V_2 -> V_112 ) {
V_7 = F_49 ( V_53 ,
V_113 , true ) ;
if ( V_7 > 0 )
V_161 = true ;
}
if ( V_2 -> V_99 ) {
V_7 = F_60 ( V_53 ) ;
if ( V_7 > 0 )
V_161 = true ;
}
if ( V_161 ) {
V_7 = F_4 ( V_2 -> V_16 ,
V_44 ,
V_45 |
V_46 ) ;
if ( V_7 )
F_5 ( & V_2 -> V_16 -> V_17 , L_11 ) ;
V_7 = V_145 ;
} else {
V_7 = V_162 ;
}
F_27 ( & V_2 -> V_71 ) ;
return V_7 ;
}
static T_6 F_64 ( int V_131 , void * V_160 )
{
struct V_52 * V_53 = V_160 ;
struct V_1 * V_2 = F_33 ( V_53 ) ;
bool V_161 = false ;
int V_6 ;
V_2 -> V_136 = V_2 -> V_137 ;
V_2 -> V_137 = F_50 () ;
for ( V_6 = 0 ; V_6 < V_103 ; V_6 ++ ) {
if ( V_2 -> V_104 [ V_6 ] . V_147 ) {
F_65 ( V_2 -> V_104 [ V_6 ] . V_105 ) ;
V_161 = true ;
break;
}
}
if ( V_2 -> V_99 || V_2 -> V_112 )
return V_163 ;
if ( V_161 )
return V_145 ;
return V_162 ;
}
static const char * F_66 ( struct V_106 * V_17 , int * V_2 )
{
const struct V_164 * V_165 ;
V_165 = F_67 ( V_17 -> V_166 -> V_167 , V_17 ) ;
if ( ! V_165 )
return NULL ;
* V_2 = ( int ) V_165 -> V_168 ;
return F_68 ( V_17 ) ;
}
static int F_69 ( struct V_114 * V_16 ,
struct V_1 * V_2 )
{
struct V_106 * V_17 ;
struct V_169 * V_170 ;
int V_7 ;
if ( ! V_16 )
return - V_13 ;
V_17 = & V_16 -> V_17 ;
V_170 = F_70 ( V_17 , V_171 , 0 , V_172 ) ;
if ( F_71 ( V_170 ) ) {
F_5 ( V_17 , L_24 ) ;
return F_72 ( V_170 ) ;
}
V_7 = F_73 ( V_170 ) ;
F_3 ( V_17 , L_25 , F_74 ( V_170 ) , V_7 ) ;
return V_7 ;
}
static void F_75 ( struct V_1 * V_2 ,
int V_173 )
{
int V_6 ;
for ( V_6 = V_173 ; V_6 >= 0 ; V_6 ++ ) {
if ( V_2 -> V_104 [ V_6 ] . V_105 ) {
F_76 ( V_2 -> V_104 [ V_6 ] . V_105 ) ;
V_2 -> V_104 [ V_6 ] . V_105 = NULL ;
}
}
}
static int F_77 ( struct V_52 * V_53 ,
struct V_1 * V_2 )
{
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_103 ; V_6 ++ ) {
struct V_30 * V_31 = & V_2 -> V_104 [ V_6 ] ;
V_31 -> V_105 = F_78 ( & V_2 -> V_16 -> V_17 ,
V_174 [ V_6 ] . V_175 ,
V_53 -> V_175 ,
V_53 -> V_165 ) ;
if ( ! V_31 -> V_105 ) {
V_7 = - V_176 ;
break;
}
V_31 -> V_105 -> V_17 . V_177 = & V_2 -> V_16 -> V_17 ;
V_31 -> V_105 -> V_178 = & V_179 ;
V_31 -> V_59 = V_174 [ V_6 ] . V_59 ;
V_31 -> V_2 = V_2 ;
V_31 -> V_148 = V_174 [ V_6 ] . V_148 ;
F_79 ( V_31 -> V_105 , V_31 ) ;
V_7 = F_80 ( V_31 -> V_105 ) ;
if ( V_7 )
break;
}
if ( V_7 )
F_75 ( V_2 , V_6 - 1 ) ;
return V_7 ;
}
static int F_81 ( struct V_1 * V_2 )
{
T_1 V_180 = V_181 ;
int V_7 ;
V_7 = F_4 ( V_2 -> V_16 , V_180 , V_2 -> V_112 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_26 ) ;
return V_7 ;
}
if ( ! V_2 -> V_112 )
return 0 ;
V_7 = F_4 ( V_2 -> V_16 ,
V_182 ,
V_2 -> V_111 ) ;
if ( V_7 < 0 )
F_5 ( & V_2 -> V_16 -> V_17 , L_27 ) ;
return V_7 ;
}
static int F_82 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
int V_7 = 0 ;
if ( V_53 -> V_183 == V_184 )
return F_83 ( V_53 ) ;
F_26 ( & V_2 -> V_71 ) ;
if ( ! V_2 -> V_111 )
goto V_185;
V_7 = F_19 ( V_2 , V_186 ,
true ) ;
if ( V_7 )
goto V_185;
V_2 -> V_112 = V_187 ;
V_7 = F_81 ( V_2 ) ;
if ( V_7 ) {
V_2 -> V_112 = 0 ;
F_19 ( V_2 , V_186 ,
false ) ;
}
V_185:
F_27 ( & V_2 -> V_71 ) ;
return V_7 ;
}
static int F_84 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_33 ( V_53 ) ;
if ( V_53 -> V_183 == V_184 )
return F_85 ( V_53 ) ;
F_26 ( & V_2 -> V_71 ) ;
if ( ! V_2 -> V_112 )
goto V_185;
F_19 ( V_2 , V_186 , false ) ;
F_49 ( V_53 , V_113 , false ) ;
V_2 -> V_112 = 0 ;
F_81 ( V_2 ) ;
V_185:
F_27 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int F_86 ( struct V_114 * V_16 ,
const struct V_188 * V_165 )
{
struct V_1 * V_2 ;
struct V_52 * V_53 ;
int V_7 ;
const char * V_175 = NULL ;
int V_35 = 0 ;
V_53 = F_87 ( & V_16 -> V_17 , sizeof( * V_2 ) ) ;
if ( ! V_53 )
return - V_176 ;
V_2 = F_33 ( V_53 ) ;
F_88 ( V_16 , V_53 ) ;
V_2 -> V_16 = V_16 ;
if ( V_165 ) {
V_175 = V_165 -> V_175 ;
V_35 = V_165 -> V_168 ;
}
if ( F_89 ( & V_16 -> V_17 ) )
V_175 = F_66 ( & V_16 -> V_17 , & V_35 ) ;
V_2 -> V_34 = & V_189 [ V_35 ] ;
V_7 = F_10 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_90 ( & V_2 -> V_71 ) ;
V_53 -> V_17 . V_177 = & V_16 -> V_17 ;
V_53 -> V_190 = V_2 -> V_34 -> V_190 ;
V_53 -> V_191 = V_2 -> V_34 -> V_191 ;
V_53 -> V_175 = V_175 ;
V_53 -> V_192 = V_193 ;
V_53 -> V_56 = & V_194 ;
if ( V_16 -> V_131 < 0 )
V_16 -> V_131 = F_69 ( V_16 , V_2 ) ;
if ( V_16 -> V_131 >= 0 ) {
V_7 = F_91 (
& V_16 -> V_17 , V_16 -> V_131 ,
F_64 ,
F_63 ,
V_195 ,
V_196 ,
V_53 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_16 ,
V_44 ,
V_46 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_11 ) ;
return V_7 ;
}
F_18 ( V_53 , V_2 ) ;
V_7 = F_77 ( V_53 , V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_92 ( V_53 ,
& V_197 ,
F_55 ,
& V_198 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_16 -> V_17 ,
L_28 ) ;
goto V_199;
}
if ( F_46 ( V_16 -> V_121 , V_122 ) ||
F_46 ( V_16 -> V_121 ,
V_200 ) ) {
V_53 -> V_192 |= V_201 ;
V_53 -> V_56 = & V_202 ;
V_53 -> V_115 -> V_203 = V_204 ;
}
}
V_7 = F_93 ( V_53 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_16 -> V_17 , L_29 ) ;
goto V_205;
}
V_7 = F_94 ( & V_16 -> V_17 ) ;
if ( V_7 )
goto V_206;
F_95 ( & V_16 -> V_17 ) ;
F_96 ( & V_16 -> V_17 ,
V_207 ) ;
F_97 ( & V_16 -> V_17 ) ;
return 0 ;
V_206:
F_98 ( V_53 ) ;
V_205:
if ( V_53 -> V_208 )
F_99 ( V_53 ) ;
V_199:
F_75 ( V_2 , V_103 - 1 ) ;
return V_7 ;
}
static int F_100 ( struct V_114 * V_16 )
{
struct V_52 * V_53 = F_101 ( V_16 ) ;
struct V_1 * V_2 = F_33 ( V_53 ) ;
F_102 ( & V_16 -> V_17 ) ;
F_103 ( & V_16 -> V_17 ) ;
F_17 ( & V_16 -> V_17 ) ;
F_98 ( V_53 ) ;
F_75 ( V_2 , V_103 - 1 ) ;
F_26 ( & V_2 -> V_71 ) ;
F_1 ( V_2 , V_209 , 0 ) ;
F_27 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int F_104 ( struct V_106 * V_17 )
{
struct V_52 * V_53 = F_101 ( F_105 ( V_17 ) ) ;
struct V_1 * V_2 = F_33 ( V_53 ) ;
F_26 ( & V_2 -> V_71 ) ;
F_1 ( V_2 , V_210 , 0 ) ;
F_27 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int F_106 ( struct V_106 * V_17 )
{
struct V_52 * V_53 = F_101 ( F_105 ( V_17 ) ) ;
struct V_1 * V_2 = F_33 ( V_53 ) ;
F_26 ( & V_2 -> V_71 ) ;
if ( F_107 ( & V_2 -> V_67 ) )
F_1 ( V_2 , V_37 , 0 ) ;
F_81 ( V_2 ) ;
F_27 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int F_108 ( struct V_106 * V_17 )
{
struct V_52 * V_53 = F_101 ( F_105 ( V_17 ) ) ;
struct V_1 * V_2 = F_33 ( V_53 ) ;
int V_7 ;
F_3 ( & V_2 -> V_16 -> V_17 , V_29 ) ;
V_7 = F_1 ( V_2 , V_210 , 0 ) ;
if ( V_7 < 0 )
return - V_211 ;
return 0 ;
}
static int F_109 ( struct V_106 * V_17 )
{
struct V_52 * V_53 = F_101 ( F_105 ( V_17 ) ) ;
struct V_1 * V_2 = F_33 ( V_53 ) ;
int V_7 ;
int V_212 ;
F_3 ( & V_2 -> V_16 -> V_17 , V_29 ) ;
V_7 = F_1 ( V_2 , V_37 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_81 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_212 = F_12 ( V_2 ) ;
if ( V_212 < 20 )
F_110 ( V_212 * 1000 , 20000 ) ;
else
F_111 ( V_212 ) ;
return 0 ;
}
