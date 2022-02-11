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
} else {
V_9 = 0 ;
}
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
static int F_10 ( struct V_1 * V_2 , int * V_19 ,
int * V_20 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_21 ) ; ++ V_6 ) {
if ( V_21 [ V_6 ] . V_23 == V_2 -> V_23 ) {
* V_19 = V_21 [ V_6 ] . V_19 ;
* V_20 = V_21 [ V_6 ] . V_20 ;
return V_33 ;
}
}
return - V_13 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_34 ) ; ++ V_6 ) {
if ( V_34 [ V_6 ] . V_23 == V_2 -> V_23 )
return V_34 [ V_6 ] . V_35 ;
}
return V_36 ;
}
static int F_12 ( struct V_1 * V_2 , bool V_37 )
{
int V_7 ;
if ( V_37 ) {
V_7 = F_13 ( & V_2 -> V_16 -> V_17 ) ;
} else {
F_14 ( & V_2 -> V_16 -> V_17 ) ;
V_7 = F_15 ( & V_2 -> V_16 -> V_17 ) ;
}
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_7 , V_37 ) ;
if ( V_37 )
F_16 ( & V_2 -> V_16 -> V_17 ) ;
return V_7 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , bool V_37 )
{
return 0 ;
}
static void F_17 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_40 ; V_6 ++ )
V_2 -> V_41 [ V_6 ] . V_42 = & V_43 [ V_6 ] ;
}
static int F_18 ( struct V_1 * V_2 , int V_6 ,
bool V_32 )
{
struct V_44 * V_45 = & V_2 -> V_41 [ V_6 ] ;
const struct V_46 * V_42 = V_45 -> V_42 ;
int V_7 ;
if ( V_32 ) {
if ( F_19 ( & V_45 -> V_47 ) > 1 )
return 0 ;
} else {
if ( F_20 ( & V_45 -> V_47 ) > 0 )
return 0 ;
}
V_7 = F_12 ( V_2 , V_32 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_8 ( V_2 -> V_16 , V_42 -> V_48 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_8 ) ;
goto V_49;
}
if ( V_32 )
V_7 |= V_42 -> V_50 ;
else
V_7 &= ~ V_42 -> V_50 ;
V_7 = F_4 ( V_2 -> V_16 , V_42 -> V_48 ,
V_7 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_9 ) ;
goto V_49;
}
V_7 = F_8 ( V_2 -> V_16 , V_42 -> V_51 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_10 ) ;
goto V_49;
}
if ( V_32 )
V_7 |= V_42 -> V_52 ;
else
V_7 &= ~ V_42 -> V_52 ;
V_7 = F_4 ( V_2 -> V_16 , V_42 -> V_51 , V_7 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_11 ) ;
goto V_49;
}
if ( V_32 )
F_21 ( & V_2 -> V_53 ) ;
else
F_22 ( & V_2 -> V_53 ) ;
return 0 ;
V_49:
F_12 ( V_2 , false ) ;
return V_7 ;
}
static int F_23 ( struct V_1 * V_2 , int V_19 )
{
int V_7 , V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_2 -> V_54 -> V_55 ) ; ++ V_6 ) {
if ( V_2 -> V_54 -> V_55 [ V_6 ] . V_56 == V_19 ) {
V_7 = F_4 (
V_2 -> V_16 ,
V_57 ,
V_2 -> V_54 -> V_55 [ V_6 ] . V_58 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_12 ) ;
return V_7 ;
}
V_2 -> V_59 = V_2 -> V_54 -> V_55 [ V_6 ] . V_58 ;
return 0 ;
}
}
return - V_13 ;
}
static int F_24 ( struct V_1 * V_2 , int * V_19 )
{
int V_7 ;
F_25 ( & V_2 -> V_60 ) ;
V_7 = F_8 ( V_2 -> V_16 , V_61 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_13 ) ;
F_26 ( & V_2 -> V_60 ) ;
return V_7 ;
}
* V_19 = F_27 ( V_7 , 7 ) ;
F_26 ( & V_2 -> V_60 ) ;
return V_62 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_63 const * V_64 ,
int * V_19 )
{
int V_7 ;
int V_65 = V_64 -> V_66 ;
F_25 ( & V_2 -> V_60 ) ;
V_7 = F_12 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_26 ( & V_2 -> V_60 ) ;
return V_7 ;
}
V_7 = F_29 ( V_2 -> V_16 ,
F_30 ( V_65 ) ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_14 , V_65 ) ;
F_12 ( V_2 , false ) ;
F_26 ( & V_2 -> V_60 ) ;
return V_7 ;
}
* V_19 = F_27 ( V_7 >> V_64 -> V_67 . V_68 ,
V_64 -> V_67 . V_69 - 1 ) ;
V_7 = F_12 ( V_2 , false ) ;
F_26 ( & V_2 -> V_60 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_62 ;
}
static int F_31 ( struct V_38 * V_39 ,
struct V_63 const * V_64 ,
int * V_19 , int * V_20 , long V_70 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
int V_7 ;
switch ( V_70 ) {
case V_71 :
switch ( V_64 -> type ) {
case V_72 :
return F_24 ( V_2 , V_19 ) ;
case V_73 :
if ( F_33 ( V_39 ) )
return - V_74 ;
else
return F_28 ( V_2 , V_64 , V_19 ) ;
default:
return - V_13 ;
}
case V_75 :
if ( V_64 -> type == V_72 ) {
* V_19 = V_76 ;
return V_62 ;
} else {
return - V_13 ;
}
case V_77 :
* V_19 = 0 ;
switch ( V_64 -> type ) {
case V_72 :
* V_20 = 500000 ;
return V_33 ;
case V_73 :
{
int V_6 ;
const struct V_78 * V_79 ;
int V_80 = F_2 ( V_2 -> V_54 -> V_55 ) ;
for ( V_6 = 0 ; V_6 < V_80 ; ++ V_6 ) {
V_79 = & V_2 -> V_54 -> V_55 [ V_6 ] ;
if ( V_79 -> V_58 == V_2 -> V_59 ) {
* V_20 = V_79 -> V_56 ;
return V_33 ;
}
}
return - V_13 ;
}
default:
return - V_13 ;
}
case V_81 :
F_25 ( & V_2 -> V_60 ) ;
V_7 = F_10 ( V_2 , V_19 , V_20 ) ;
F_26 ( & V_2 -> V_60 ) ;
return V_7 ;
default:
return - V_13 ;
}
}
static int F_34 ( struct V_38 * V_39 ,
struct V_63 const * V_64 ,
int V_19 , int V_20 , long V_70 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
int V_7 ;
switch ( V_70 ) {
case V_81 :
F_25 ( & V_2 -> V_60 ) ;
V_7 = F_6 ( V_2 , V_19 , V_20 ) ;
F_26 ( & V_2 -> V_60 ) ;
break;
case V_77 :
if ( V_19 )
return - V_13 ;
F_25 ( & V_2 -> V_60 ) ;
V_7 = F_23 ( V_2 , V_20 ) ;
F_26 ( & V_2 -> V_60 ) ;
return V_7 ;
default:
V_7 = - V_13 ;
}
return V_7 ;
}
static int F_35 ( struct V_38 * V_39 ,
const struct V_63 * V_64 ,
enum V_82 type ,
enum V_83 V_84 ,
enum V_85 V_42 ,
int * V_19 , int * V_20 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
* V_20 = 0 ;
switch ( V_42 ) {
case V_86 :
* V_19 = V_2 -> V_25 ;
break;
case V_87 :
* V_19 = V_2 -> V_28 ;
break;
default:
return - V_13 ;
}
return V_62 ;
}
static int F_36 ( struct V_38 * V_39 ,
const struct V_63 * V_64 ,
enum V_82 type ,
enum V_83 V_84 ,
enum V_85 V_42 ,
int V_19 , int V_20 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
if ( V_2 -> V_88 )
return - V_74 ;
switch ( V_42 ) {
case V_86 :
V_2 -> V_25 = V_19 & V_89 ;
break;
case V_87 :
V_2 -> V_28 = V_19 & V_27 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_37 ( struct V_38 * V_39 ,
const struct V_63 * V_64 ,
enum V_82 type ,
enum V_83 V_84 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
return V_2 -> V_88 ;
}
static int F_38 ( struct V_38 * V_39 ,
const struct V_63 * V_64 ,
enum V_82 type ,
enum V_83 V_84 ,
int V_32 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
int V_7 ;
if ( V_32 == V_2 -> V_88 )
return 0 ;
F_25 ( & V_2 -> V_60 ) ;
V_7 = F_18 ( V_2 , V_90 ,
V_32 ) ;
if ( V_7 < 0 ) {
F_26 ( & V_2 -> V_60 ) ;
return V_7 ;
}
V_2 -> V_88 = V_32 ;
F_26 ( & V_2 -> V_60 ) ;
return 0 ;
}
static int F_39 ( struct V_38 * V_39 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_93 ; V_6 ++ ) {
if ( V_2 -> V_94 [ V_6 ] . V_95 == V_92 )
return 0 ;
}
return - V_13 ;
}
static T_2 F_40 ( struct V_96 * V_17 ,
struct V_97 * V_98 ,
char * V_99 )
{
struct V_38 * V_39 = F_41 ( V_17 ) ;
struct V_1 * V_2 = F_32 ( V_39 ) ;
int V_100 ;
F_25 ( & V_2 -> V_60 ) ;
V_100 = V_2 -> V_101 ;
F_26 ( & V_2 -> V_60 ) ;
return sprintf ( V_99 , L_15 , V_100 ) ;
}
static T_2 F_42 ( struct V_96 * V_17 ,
struct V_97 * V_98 ,
char * V_99 )
{
struct V_38 * V_39 = F_41 ( V_17 ) ;
struct V_1 * V_2 = F_32 ( V_39 ) ;
bool V_32 ;
F_25 ( & V_2 -> V_60 ) ;
V_32 = V_2 -> V_102 ;
F_26 ( & V_2 -> V_60 ) ;
return sprintf ( V_99 , L_15 , V_32 ) ;
}
static int F_43 ( struct V_38 * V_39 , unsigned V_19 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
if ( V_19 > V_103 )
V_19 = V_103 ;
F_25 ( & V_2 -> V_60 ) ;
V_2 -> V_101 = V_19 ;
F_26 ( & V_2 -> V_60 ) ;
return 0 ;
}
static int F_44 ( const struct V_104 * V_16 ,
char * V_105 , int V_106 )
{
int V_107 = 3 * 2 ;
T_1 V_108 = V_109 ;
int V_7 = - V_110 ;
if ( F_45 ( V_16 -> V_111 , V_112 ) ) {
struct V_113 V_114 [ 2 ] = {
{
. V_115 = V_16 -> V_115 ,
. V_116 = 0 ,
. V_99 = & V_108 ,
. V_117 = sizeof( V_108 ) ,
} ,
{
. V_115 = V_16 -> V_115 ,
. V_116 = V_118 ,
. V_99 = ( T_1 * ) V_105 ,
. V_117 = V_106 * V_107 ,
}
} ;
V_7 = F_46 ( V_16 -> V_111 , V_114 , 2 ) ;
if ( V_7 != 2 )
V_7 = - V_110 ;
else
V_7 = 0 ;
} else {
int V_6 , V_119 = V_120 / V_107 ;
for ( V_6 = 0 ; V_6 < V_106 * V_107 ; V_6 += V_119 ) {
V_7 = F_47 ( V_16 ,
V_108 , V_119 ,
& V_105 [ V_6 ] ) ;
if ( V_7 != V_119 ) {
V_7 = - V_110 ;
break;
}
V_7 = 0 ;
}
}
if ( V_7 )
F_5 ( & V_16 -> V_17 , L_16 ) ;
return V_7 ;
}
static int F_48 ( struct V_38 * V_39 ,
unsigned V_106 , bool V_121 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
int V_7 , V_6 ;
T_1 V_122 ;
T_3 V_105 [ V_103 * 3 ] ;
T_4 V_123 ;
T_5 V_124 ;
V_7 = F_8 ( V_2 -> V_16 ,
V_125 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_17 ) ;
return V_7 ;
}
V_122 = V_7 & 0x7F ;
if ( ! V_122 )
return 0 ;
if ( ! V_121 ) {
V_2 -> V_126 = V_2 -> V_127 ;
V_2 -> V_127 = F_49 () ;
}
V_124 = ( V_2 -> V_127 - V_2 -> V_126 ) ;
F_50 ( V_124 , V_122 ) ;
V_123 = V_2 -> V_127 - ( V_122 - 1 ) * V_124 ;
if ( V_106 && V_122 > V_106 )
V_122 = V_106 ;
V_7 = F_44 ( V_2 -> V_16 , ( T_1 * ) V_105 , V_122 ) ;
if ( V_7 )
return V_7 ;
for ( V_6 = 0 ; V_6 < V_122 ; V_6 ++ ) {
T_3 V_128 [ 8 ] ;
int V_129 , V_130 ;
V_129 = 0 ;
F_51 (bit, indio_dev->active_scan_mask,
indio_dev->masklength)
memcpy ( & V_128 [ V_129 ++ ] , & V_105 [ V_6 * 3 + V_130 ] , 2 ) ;
F_52 ( V_39 , V_128 , V_123 ) ;
V_123 += V_124 ;
}
return V_122 ;
}
static int F_53 ( struct V_38 * V_39 , unsigned V_106 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
int V_7 ;
F_25 ( & V_2 -> V_60 ) ;
V_7 = F_48 ( V_39 , V_106 , false ) ;
F_26 ( & V_2 -> V_60 ) ;
return V_7 ;
}
static T_6 F_54 ( int V_121 , void * V_131 )
{
struct V_132 * V_133 = V_131 ;
struct V_38 * V_39 = V_133 -> V_39 ;
struct V_1 * V_2 = F_32 ( V_39 ) ;
int V_130 , V_7 , V_6 = 0 ;
F_25 ( & V_2 -> V_60 ) ;
F_51 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_7 = F_29 ( V_2 -> V_16 ,
F_30 ( V_130 ) ) ;
if ( V_7 < 0 ) {
F_26 ( & V_2 -> V_60 ) ;
goto V_134;
}
V_2 -> V_105 [ V_6 ++ ] = V_7 ;
}
F_26 ( & V_2 -> V_60 ) ;
F_52 ( V_39 , V_2 -> V_105 ,
V_133 -> V_127 ) ;
V_134:
F_55 ( V_39 -> V_92 ) ;
return V_135 ;
}
static int F_56 ( struct V_91 * V_92 )
{
struct V_30 * V_31 = F_57 ( V_92 ) ;
struct V_1 * V_2 = V_31 -> V_2 ;
int V_7 ;
if ( V_31 == & V_31 -> V_2 -> V_94 [ V_136 ] )
return 0 ;
F_25 ( & V_2 -> V_60 ) ;
V_7 = F_4 ( V_2 -> V_16 ,
V_137 ,
V_138 |
V_139 ) ;
F_26 ( & V_2 -> V_60 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_18 ) ;
return V_7 ;
}
return 0 ;
}
static int F_58 ( struct V_91 * V_92 ,
bool V_32 )
{
struct V_30 * V_31 = F_57 ( V_92 ) ;
struct V_1 * V_2 = V_31 -> V_2 ;
int V_7 ;
F_25 ( & V_2 -> V_60 ) ;
if ( V_31 -> V_140 == V_32 ) {
F_26 ( & V_2 -> V_60 ) ;
return 0 ;
}
if ( V_31 -> V_141 ) {
V_7 = V_31 -> V_141 ( V_31 , V_32 ) ;
if ( V_7 < 0 ) {
F_26 ( & V_2 -> V_60 ) ;
return V_7 ;
}
}
V_7 = F_18 ( V_2 , V_31 -> V_45 , V_32 ) ;
if ( V_7 < 0 ) {
F_26 ( & V_2 -> V_60 ) ;
return V_7 ;
}
V_31 -> V_140 = V_32 ;
F_26 ( & V_2 -> V_60 ) ;
return V_7 ;
}
static int F_59 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
int V_84 ;
int V_7 ;
V_7 = F_8 ( V_2 -> V_16 ,
V_142 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_19 ) ;
return V_7 ;
}
if ( V_7 & V_143 )
V_84 = V_144 ;
else
V_84 = V_145 ;
if ( V_7 & V_146 )
F_60 ( V_39 ,
F_61 ( V_73 ,
0 ,
V_147 ,
V_148 ,
V_84 ) ,
V_2 -> V_127 ) ;
if ( V_7 & V_149 )
F_60 ( V_39 ,
F_61 ( V_73 ,
0 ,
V_150 ,
V_148 ,
V_84 ) ,
V_2 -> V_127 ) ;
if ( V_7 & V_151 )
F_60 ( V_39 ,
F_61 ( V_73 ,
0 ,
V_152 ,
V_148 ,
V_84 ) ,
V_2 -> V_127 ) ;
return V_7 ;
}
static T_6 F_62 ( int V_121 , void * V_153 )
{
struct V_38 * V_39 = V_153 ;
struct V_1 * V_2 = F_32 ( V_39 ) ;
bool V_154 = false ;
int V_7 ;
F_25 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_102 ) {
V_7 = F_48 ( V_39 ,
V_103 , true ) ;
if ( V_7 > 0 )
V_154 = true ;
}
if ( V_2 -> V_88 ) {
V_7 = F_59 ( V_39 ) ;
if ( V_7 > 0 )
V_154 = true ;
}
if ( V_154 ) {
V_7 = F_4 ( V_2 -> V_16 ,
V_137 ,
V_138 |
V_139 ) ;
if ( V_7 )
F_5 ( & V_2 -> V_16 -> V_17 ,
L_18 ) ;
V_7 = V_135 ;
} else {
V_7 = V_155 ;
}
F_26 ( & V_2 -> V_60 ) ;
return V_7 ;
}
static T_6 F_63 ( int V_121 , void * V_153 )
{
struct V_38 * V_39 = V_153 ;
struct V_1 * V_2 = F_32 ( V_39 ) ;
bool V_154 = false ;
int V_6 ;
V_2 -> V_126 = V_2 -> V_127 ;
V_2 -> V_127 = F_49 () ;
for ( V_6 = 0 ; V_6 < V_93 ; V_6 ++ ) {
if ( V_2 -> V_94 [ V_6 ] . V_140 ) {
F_64 ( V_2 -> V_94 [ V_6 ] . V_95 ) ;
V_154 = true ;
break;
}
}
if ( V_2 -> V_88 || V_2 -> V_102 )
return V_156 ;
if ( V_154 )
return V_135 ;
return V_155 ;
}
static int F_65 ( struct V_104 * V_16 ,
struct V_1 * V_2 )
{
struct V_96 * V_17 ;
struct V_157 * V_158 ;
int V_7 ;
if ( ! V_16 )
return - V_13 ;
V_17 = & V_16 -> V_17 ;
V_158 = F_66 ( V_17 , V_159 , 0 , V_160 ) ;
if ( F_67 ( V_158 ) ) {
F_5 ( V_17 , L_20 ) ;
return F_68 ( V_158 ) ;
}
V_7 = F_69 ( V_158 ) ;
F_3 ( V_17 , L_21 , F_70 ( V_158 ) , V_7 ) ;
return V_7 ;
}
static void F_71 ( struct V_1 * V_2 ,
int V_161 )
{
int V_6 ;
for ( V_6 = V_161 ; V_6 >= 0 ; V_6 -- ) {
if ( V_2 -> V_94 [ V_6 ] . V_95 ) {
F_72 ( V_2 -> V_94 [ V_6 ] . V_95 ) ;
V_2 -> V_94 [ V_6 ] . V_95 = NULL ;
}
}
}
static int F_73 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_93 ; V_6 ++ ) {
struct V_30 * V_31 = & V_2 -> V_94 [ V_6 ] ;
V_31 -> V_95 = F_74 ( & V_2 -> V_16 -> V_17 ,
V_162 [ V_6 ] . V_163 ,
V_39 -> V_163 ,
V_39 -> V_164 ) ;
if ( ! V_31 -> V_95 ) {
V_7 = - V_165 ;
break;
}
V_31 -> V_95 -> V_17 . V_166 = & V_2 -> V_16 -> V_17 ;
V_31 -> V_95 -> V_167 = & V_168 ;
V_31 -> V_45 = V_162 [ V_6 ] . V_45 ;
V_31 -> V_2 = V_2 ;
V_31 -> V_141 = V_162 [ V_6 ] . V_141 ;
F_75 ( V_31 -> V_95 , V_31 ) ;
V_7 = F_76 ( V_31 -> V_95 ) ;
if ( V_7 )
break;
}
if ( V_7 )
F_71 ( V_2 , V_6 - 1 ) ;
return V_7 ;
}
static int F_77 ( struct V_1 * V_2 )
{
T_1 V_169 = V_170 ;
int V_7 ;
V_7 = F_4 ( V_2 -> V_16 , V_169 , V_2 -> V_102 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_22 ) ;
return V_7 ;
}
if ( ! V_2 -> V_102 )
return 0 ;
V_7 = F_4 ( V_2 -> V_16 ,
V_171 ,
V_2 -> V_101 ) ;
if ( V_7 < 0 )
F_5 ( & V_2 -> V_16 -> V_17 , L_23 ) ;
return V_7 ;
}
static int F_78 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
return F_12 ( V_2 , true ) ;
}
static int F_79 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
int V_7 = 0 ;
if ( V_39 -> V_172 == V_173 )
return F_80 ( V_39 ) ;
F_25 ( & V_2 -> V_60 ) ;
if ( ! V_2 -> V_101 )
goto V_174;
V_7 = F_18 ( V_2 , V_175 ,
true ) ;
if ( V_7 )
goto V_174;
V_2 -> V_102 = V_176 ;
V_7 = F_77 ( V_2 ) ;
if ( V_7 ) {
V_2 -> V_102 = 0 ;
F_18 ( V_2 , V_175 ,
false ) ;
}
V_174:
F_26 ( & V_2 -> V_60 ) ;
return V_7 ;
}
static int F_81 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
if ( V_39 -> V_172 == V_173 )
return F_82 ( V_39 ) ;
F_25 ( & V_2 -> V_60 ) ;
if ( ! V_2 -> V_102 )
goto V_174;
F_18 ( V_2 , V_175 , false ) ;
F_48 ( V_39 , V_103 , false ) ;
V_2 -> V_102 = 0 ;
F_77 ( V_2 ) ;
V_174:
F_26 ( & V_2 -> V_60 ) ;
return 0 ;
}
static int F_83 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_32 ( V_39 ) ;
return F_12 ( V_2 , false ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_7 , V_6 ;
V_7 = F_8 ( V_2 -> V_16 , V_177 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_24 ) ;
return V_7 ;
}
F_3 ( & V_2 -> V_16 -> V_17 , L_25 , V_7 ) ;
for ( V_6 = 0 ; V_6 < F_2 ( V_178 ) ; V_6 ++ ) {
if ( V_178 [ V_6 ] . V_179 == V_7 ) {
V_2 -> V_54 = & V_178 [ V_6 ] ;
break;
}
}
if ( ! V_2 -> V_54 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_26 , V_7 ) ;
return - V_180 ;
}
V_7 = F_1 ( V_2 , V_181 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_2 , V_182 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_16 ,
V_57 ,
V_183 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_27 ) ;
return V_7 ;
}
V_2 -> V_59 = V_183 ;
V_2 -> V_25 = V_184 ;
V_2 -> V_28 = V_185 ;
V_7 = F_7 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_16 ,
V_137 ,
V_138 |
V_139 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 ,
L_18 ) ;
return V_7 ;
}
return 0 ;
}
static int F_85 ( struct V_104 * V_16 ,
const struct V_186 * V_164 )
{
struct V_1 * V_2 ;
struct V_38 * V_39 ;
int V_7 ;
const char * V_163 = NULL ;
V_39 = F_86 ( & V_16 -> V_17 , sizeof( * V_2 ) ) ;
if ( ! V_39 )
return - V_165 ;
V_2 = F_32 ( V_39 ) ;
F_87 ( V_16 , V_39 ) ;
V_2 -> V_16 = V_16 ;
if ( V_164 )
V_163 = V_164 -> V_163 ;
V_7 = F_84 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_88 ( & V_2 -> V_60 ) ;
V_39 -> V_17 . V_166 = & V_16 -> V_17 ;
V_39 -> V_187 = V_2 -> V_54 -> V_187 ;
V_39 -> V_188 = V_2 -> V_54 -> V_188 ;
V_39 -> V_163 = V_163 ? V_163 : V_2 -> V_54 -> V_163 ;
V_39 -> V_189 = V_190 ;
V_39 -> V_42 = & V_191 ;
V_7 = F_89 ( V_39 ,
& V_192 ,
F_54 ,
& V_193 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_16 -> V_17 , L_28 ) ;
return V_7 ;
}
if ( V_16 -> V_121 < 0 )
V_16 -> V_121 = F_65 ( V_16 , V_2 ) ;
if ( V_16 -> V_121 > 0 ) {
V_7 = F_90 (
& V_16 -> V_17 , V_16 -> V_121 ,
F_63 ,
F_62 ,
V_194 ,
V_195 ,
V_39 ) ;
if ( V_7 )
goto V_196;
V_7 = F_4 ( V_2 -> V_16 ,
V_137 ,
V_139 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_2 -> V_16 -> V_17 , L_18 ) ;
goto V_196;
}
F_17 ( V_39 , V_2 ) ;
V_7 = F_73 ( V_39 , V_2 ) ;
if ( V_7 )
goto V_196;
if ( F_45 ( V_16 -> V_111 , V_112 ) ||
F_45 ( V_16 -> V_111 ,
V_197 ) ) {
V_39 -> V_189 |= V_198 ;
V_39 -> V_42 = & V_199 ;
V_39 -> V_105 -> V_200 = V_201 ;
}
}
V_7 = F_91 ( V_39 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_16 -> V_17 , L_29 ) ;
goto V_202;
}
V_7 = F_92 ( & V_16 -> V_17 ) ;
if ( V_7 )
goto V_203;
F_93 ( & V_16 -> V_17 ) ;
F_94 ( & V_16 -> V_17 ,
V_204 ) ;
F_95 ( & V_16 -> V_17 ) ;
return 0 ;
V_203:
F_96 ( V_39 ) ;
V_202:
F_71 ( V_2 , V_93 - 1 ) ;
V_196:
F_97 ( V_39 ) ;
return V_7 ;
}
static int F_98 ( struct V_104 * V_16 )
{
struct V_38 * V_39 = F_99 ( V_16 ) ;
struct V_1 * V_2 = F_32 ( V_39 ) ;
F_100 ( & V_16 -> V_17 ) ;
F_101 ( & V_16 -> V_17 ) ;
F_16 ( & V_16 -> V_17 ) ;
F_96 ( V_39 ) ;
F_71 ( V_2 , V_93 - 1 ) ;
F_97 ( V_39 ) ;
F_25 ( & V_2 -> V_60 ) ;
F_1 ( V_2 , V_205 , 0 ) ;
F_26 ( & V_2 -> V_60 ) ;
return 0 ;
}
static int F_102 ( struct V_96 * V_17 )
{
struct V_38 * V_39 = F_99 ( F_103 ( V_17 ) ) ;
struct V_1 * V_2 = F_32 ( V_39 ) ;
F_25 ( & V_2 -> V_60 ) ;
F_1 ( V_2 , V_206 , 0 ) ;
F_26 ( & V_2 -> V_60 ) ;
return 0 ;
}
static int F_104 ( struct V_96 * V_17 )
{
struct V_38 * V_39 = F_99 ( F_103 ( V_17 ) ) ;
struct V_1 * V_2 = F_32 ( V_39 ) ;
F_25 ( & V_2 -> V_60 ) ;
if ( F_105 ( & V_2 -> V_53 ) )
F_1 ( V_2 , V_181 , 0 ) ;
F_77 ( V_2 ) ;
F_26 ( & V_2 -> V_60 ) ;
return 0 ;
}
static int F_106 ( struct V_96 * V_17 )
{
struct V_38 * V_39 = F_99 ( F_103 ( V_17 ) ) ;
struct V_1 * V_2 = F_32 ( V_39 ) ;
int V_7 ;
F_3 ( & V_2 -> V_16 -> V_17 , V_29 ) ;
V_7 = F_1 ( V_2 , V_206 , 0 ) ;
if ( V_7 < 0 )
return - V_207 ;
return 0 ;
}
static int F_107 ( struct V_96 * V_17 )
{
struct V_38 * V_39 = F_99 ( F_103 ( V_17 ) ) ;
struct V_1 * V_2 = F_32 ( V_39 ) ;
int V_7 ;
int V_208 ;
F_3 ( & V_2 -> V_16 -> V_17 , V_29 ) ;
V_7 = F_1 ( V_2 , V_181 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_77 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_208 = F_11 ( V_2 ) ;
if ( V_208 < 20 )
F_108 ( V_208 * 1000 , 20000 ) ;
else
F_109 ( V_208 ) ;
return 0 ;
}
