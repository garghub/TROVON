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
F_3 ( V_2 -> V_16 , L_1 , V_8 ) ;
V_7 = F_4 ( V_2 -> V_17 , V_18 , V_8 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 , L_2 ) ;
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
V_7 = F_4 ( V_2 -> V_17 ,
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
V_7 = F_4 ( V_2 -> V_17 , V_24 ,
V_2 -> V_25 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 , L_3 ) ;
return V_7 ;
}
V_7 = F_8 ( V_2 -> V_17 , V_26 ,
V_27 , V_2 -> V_28 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 , L_4 ) ;
return V_7 ;
}
F_3 ( V_2 -> V_16 , L_5 , V_29 , V_2 -> V_25 ,
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
V_7 = F_13 ( V_2 -> V_16 ) ;
} else {
F_14 ( V_2 -> V_16 ) ;
V_7 = F_15 ( V_2 -> V_16 ) ;
}
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 ,
L_6 , V_37 ) ;
if ( V_37 )
F_16 ( V_2 -> V_16 ) ;
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
V_7 = F_8 ( V_2 -> V_17 , V_42 -> V_48 , V_42 -> V_49 ,
( V_32 ? V_42 -> V_49 : 0 ) ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 , L_7 ) ;
goto V_50;
}
V_7 = F_8 ( V_2 -> V_17 , V_42 -> V_51 , V_42 -> V_52 ,
( V_32 ? V_42 -> V_52 : 0 ) ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 , L_8 ) ;
goto V_50;
}
if ( V_32 )
F_21 ( & V_2 -> V_53 ) ;
else
F_22 ( & V_2 -> V_53 ) ;
return 0 ;
V_50:
F_12 ( V_2 , false ) ;
return V_7 ;
}
static int F_23 ( struct V_1 * V_2 , int V_19 )
{
int V_7 , V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_2 -> V_54 -> V_55 ) ; ++ V_6 ) {
if ( V_2 -> V_54 -> V_55 [ V_6 ] . V_56 == V_19 ) {
V_7 = F_4 ( V_2 -> V_17 ,
V_57 ,
V_2 -> V_54 -> V_55 [ V_6 ] . V_58 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 ,
L_9 ) ;
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
unsigned int V_60 ;
F_25 ( & V_2 -> V_61 ) ;
V_7 = F_26 ( V_2 -> V_17 , V_62 , & V_60 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 , L_10 ) ;
F_27 ( & V_2 -> V_61 ) ;
return V_7 ;
}
* V_19 = F_28 ( V_60 , 7 ) ;
F_27 ( & V_2 -> V_61 ) ;
return V_63 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_64 const * V_65 ,
int * V_19 )
{
int V_7 ;
int V_66 = V_65 -> V_67 ;
T_2 V_68 ;
F_25 ( & V_2 -> V_61 ) ;
V_7 = F_12 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_61 ) ;
return V_7 ;
}
V_7 = F_30 ( V_2 -> V_17 , F_31 ( V_66 ) ,
& V_68 , sizeof( V_68 ) ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 , L_11 , V_66 ) ;
F_12 ( V_2 , false ) ;
F_27 ( & V_2 -> V_61 ) ;
return V_7 ;
}
* V_19 = F_28 ( F_32 ( V_68 ) >> V_65 -> V_69 . V_70 ,
V_65 -> V_69 . V_71 - 1 ) ;
V_7 = F_12 ( V_2 , false ) ;
F_27 ( & V_2 -> V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_63 ;
}
static int F_33 ( struct V_38 * V_39 ,
struct V_64 const * V_65 ,
int * V_19 , int * V_20 , long V_72 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
int V_7 ;
switch ( V_72 ) {
case V_73 :
switch ( V_65 -> type ) {
case V_74 :
return F_24 ( V_2 , V_19 ) ;
case V_75 :
if ( F_35 ( V_39 ) )
return - V_76 ;
else
return F_29 ( V_2 , V_65 , V_19 ) ;
default:
return - V_13 ;
}
case V_77 :
if ( V_65 -> type == V_74 ) {
* V_19 = V_78 ;
return V_63 ;
} else {
return - V_13 ;
}
case V_79 :
* V_19 = 0 ;
switch ( V_65 -> type ) {
case V_74 :
* V_20 = 500000 ;
return V_33 ;
case V_75 :
{
int V_6 ;
const struct V_80 * V_81 ;
int V_82 = F_2 ( V_2 -> V_54 -> V_55 ) ;
for ( V_6 = 0 ; V_6 < V_82 ; ++ V_6 ) {
V_81 = & V_2 -> V_54 -> V_55 [ V_6 ] ;
if ( V_81 -> V_58 == V_2 -> V_59 ) {
* V_20 = V_81 -> V_56 ;
return V_33 ;
}
}
return - V_13 ;
}
default:
return - V_13 ;
}
case V_83 :
F_25 ( & V_2 -> V_61 ) ;
V_7 = F_10 ( V_2 , V_19 , V_20 ) ;
F_27 ( & V_2 -> V_61 ) ;
return V_7 ;
default:
return - V_13 ;
}
}
static int F_36 ( struct V_38 * V_39 ,
struct V_64 const * V_65 ,
int V_19 , int V_20 , long V_72 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
int V_7 ;
switch ( V_72 ) {
case V_83 :
F_25 ( & V_2 -> V_61 ) ;
V_7 = F_6 ( V_2 , V_19 , V_20 ) ;
F_27 ( & V_2 -> V_61 ) ;
break;
case V_79 :
if ( V_19 )
return - V_13 ;
F_25 ( & V_2 -> V_61 ) ;
V_7 = F_23 ( V_2 , V_20 ) ;
F_27 ( & V_2 -> V_61 ) ;
return V_7 ;
default:
V_7 = - V_13 ;
}
return V_7 ;
}
static int F_37 ( struct V_38 * V_39 ,
const struct V_64 * V_65 ,
enum V_84 type ,
enum V_85 V_86 ,
enum V_87 V_42 ,
int * V_19 , int * V_20 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
* V_20 = 0 ;
switch ( V_42 ) {
case V_88 :
* V_19 = V_2 -> V_25 ;
break;
case V_89 :
* V_19 = V_2 -> V_28 ;
break;
default:
return - V_13 ;
}
return V_63 ;
}
static int F_38 ( struct V_38 * V_39 ,
const struct V_64 * V_65 ,
enum V_84 type ,
enum V_85 V_86 ,
enum V_87 V_42 ,
int V_19 , int V_20 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
if ( V_2 -> V_90 )
return - V_76 ;
switch ( V_42 ) {
case V_88 :
V_2 -> V_25 = V_19 & V_91 ;
break;
case V_89 :
V_2 -> V_28 = V_19 & V_27 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_39 ( struct V_38 * V_39 ,
const struct V_64 * V_65 ,
enum V_84 type ,
enum V_85 V_86 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
return V_2 -> V_90 ;
}
static int F_40 ( struct V_38 * V_39 ,
const struct V_64 * V_65 ,
enum V_84 type ,
enum V_85 V_86 ,
int V_32 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
int V_7 ;
if ( V_32 == V_2 -> V_90 )
return 0 ;
F_25 ( & V_2 -> V_61 ) ;
V_7 = F_18 ( V_2 , V_92 ,
V_32 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_61 ) ;
return V_7 ;
}
V_2 -> V_90 = V_32 ;
F_27 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_41 ( struct V_38 * V_39 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_95 ; V_6 ++ ) {
if ( V_2 -> V_96 [ V_6 ] . V_97 == V_94 )
return 0 ;
}
return - V_13 ;
}
static T_3 F_42 ( struct V_98 * V_16 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_38 * V_39 = F_43 ( V_16 ) ;
struct V_1 * V_2 = F_34 ( V_39 ) ;
int V_102 ;
F_25 ( & V_2 -> V_61 ) ;
V_102 = V_2 -> V_103 ;
F_27 ( & V_2 -> V_61 ) ;
return sprintf ( V_101 , L_12 , V_102 ) ;
}
static T_3 F_44 ( struct V_98 * V_16 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_38 * V_39 = F_43 ( V_16 ) ;
struct V_1 * V_2 = F_34 ( V_39 ) ;
bool V_32 ;
F_25 ( & V_2 -> V_61 ) ;
V_32 = V_2 -> V_104 ;
F_27 ( & V_2 -> V_61 ) ;
return sprintf ( V_101 , L_12 , V_32 ) ;
}
static int F_45 ( struct V_38 * V_39 , unsigned V_19 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
if ( V_19 > V_105 )
V_19 = V_105 ;
F_25 ( & V_2 -> V_61 ) ;
V_2 -> V_103 = V_19 ;
F_27 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
char * V_106 , int V_107 )
{
int V_108 = 3 * 2 ;
int V_7 ;
int V_109 = V_107 * V_108 ;
int V_6 ;
T_4 V_110 = F_47 ( V_2 -> V_17 ) ;
if ( ! V_110 || V_110 > V_109 )
V_110 = V_109 ;
else if ( V_110 < V_109 )
V_110 = V_108 ;
for ( V_6 = 0 ; V_6 < V_109 ; V_6 += V_110 ) {
V_7 = F_48 ( V_2 -> V_17 , V_111 ,
& V_106 [ V_6 ] , V_110 ) ;
if ( V_7 )
break;
}
if ( V_7 )
F_5 ( V_2 -> V_16 , L_13 ,
V_110 ) ;
return V_7 ;
}
static int F_49 ( struct V_38 * V_39 ,
unsigned V_107 , bool V_112 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
int V_7 , V_6 ;
T_1 V_113 ;
T_5 V_106 [ V_105 * 3 ] ;
T_6 V_114 ;
T_7 V_115 ;
unsigned int V_19 ;
V_7 = F_26 ( V_2 -> V_17 , V_116 , & V_19 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 , L_14 ) ;
return V_7 ;
}
V_113 = V_19 & 0x7F ;
if ( ! V_113 )
return 0 ;
if ( ! V_112 ) {
V_2 -> V_117 = V_2 -> V_118 ;
V_2 -> V_118 = F_50 () ;
}
V_115 = ( V_2 -> V_118 - V_2 -> V_117 ) ;
F_51 ( V_115 , V_113 ) ;
V_114 = V_2 -> V_118 - ( V_113 - 1 ) * V_115 ;
if ( V_107 && V_113 > V_107 )
V_113 = V_107 ;
V_7 = F_46 ( V_2 , ( T_1 * ) V_106 , V_113 ) ;
if ( V_7 )
return V_7 ;
for ( V_6 = 0 ; V_6 < V_113 ; V_6 ++ ) {
T_5 V_119 [ 8 ] ;
int V_120 , V_121 ;
V_120 = 0 ;
F_52 (bit, indio_dev->active_scan_mask,
indio_dev->masklength)
memcpy ( & V_119 [ V_120 ++ ] , & V_106 [ V_6 * 3 + V_121 ] , 2 ) ;
F_53 ( V_39 , V_119 , V_114 ) ;
V_114 += V_115 ;
}
return V_113 ;
}
static int F_54 ( struct V_38 * V_39 , unsigned V_107 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
int V_7 ;
F_25 ( & V_2 -> V_61 ) ;
V_7 = F_49 ( V_39 , V_107 , false ) ;
F_27 ( & V_2 -> V_61 ) ;
return V_7 ;
}
static T_8 F_55 ( int V_112 , void * V_122 )
{
struct V_123 * V_124 = V_122 ;
struct V_38 * V_39 = V_124 -> V_39 ;
struct V_1 * V_2 = F_34 ( V_39 ) ;
int V_121 , V_7 , V_6 = 0 ;
unsigned int V_68 ;
F_25 ( & V_2 -> V_61 ) ;
F_52 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_7 = F_30 ( V_2 -> V_17 ,
F_31 ( V_121 ) , & V_68 ,
2 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_61 ) ;
goto V_125;
}
V_2 -> V_106 [ V_6 ++ ] = V_68 ;
}
F_27 ( & V_2 -> V_61 ) ;
F_53 ( V_39 , V_2 -> V_106 ,
V_124 -> V_118 ) ;
V_125:
F_56 ( V_39 -> V_94 ) ;
return V_126 ;
}
static int F_57 ( struct V_93 * V_94 )
{
struct V_30 * V_31 = F_58 ( V_94 ) ;
struct V_1 * V_2 = V_31 -> V_2 ;
int V_7 ;
if ( V_31 == & V_31 -> V_2 -> V_96 [ V_127 ] )
return 0 ;
F_25 ( & V_2 -> V_61 ) ;
V_7 = F_4 ( V_2 -> V_17 , V_128 ,
V_129 |
V_130 ) ;
F_27 ( & V_2 -> V_61 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 ,
L_15 ) ;
return V_7 ;
}
return 0 ;
}
static int F_59 ( struct V_93 * V_94 ,
bool V_32 )
{
struct V_30 * V_31 = F_58 ( V_94 ) ;
struct V_1 * V_2 = V_31 -> V_2 ;
int V_7 ;
F_25 ( & V_2 -> V_61 ) ;
if ( V_31 -> V_131 == V_32 ) {
F_27 ( & V_2 -> V_61 ) ;
return 0 ;
}
if ( V_31 -> V_132 ) {
V_7 = V_31 -> V_132 ( V_31 , V_32 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_61 ) ;
return V_7 ;
}
}
V_7 = F_18 ( V_2 , V_31 -> V_45 , V_32 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_61 ) ;
return V_7 ;
}
V_31 -> V_131 = V_32 ;
F_27 ( & V_2 -> V_61 ) ;
return V_7 ;
}
static int F_60 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
int V_86 ;
int V_7 ;
unsigned int V_19 ;
V_7 = F_26 ( V_2 -> V_17 , V_133 , & V_19 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 , L_16 ) ;
return V_7 ;
}
if ( V_19 & V_134 )
V_86 = V_135 ;
else
V_86 = V_136 ;
if ( V_19 & V_137 )
F_61 ( V_39 ,
F_62 ( V_75 ,
0 ,
V_138 ,
V_139 ,
V_86 ) ,
V_2 -> V_118 ) ;
if ( V_19 & V_140 )
F_61 ( V_39 ,
F_62 ( V_75 ,
0 ,
V_141 ,
V_139 ,
V_86 ) ,
V_2 -> V_118 ) ;
if ( V_19 & V_142 )
F_61 ( V_39 ,
F_62 ( V_75 ,
0 ,
V_143 ,
V_139 ,
V_86 ) ,
V_2 -> V_118 ) ;
return V_7 ;
}
static T_8 F_63 ( int V_112 , void * V_144 )
{
struct V_38 * V_39 = V_144 ;
struct V_1 * V_2 = F_34 ( V_39 ) ;
bool V_145 = false ;
int V_7 ;
F_25 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_104 ) {
V_7 = F_49 ( V_39 ,
V_105 , true ) ;
if ( V_7 > 0 )
V_145 = true ;
}
if ( V_2 -> V_90 ) {
V_7 = F_60 ( V_39 ) ;
if ( V_7 > 0 )
V_145 = true ;
}
if ( V_145 ) {
V_7 = F_4 ( V_2 -> V_17 , V_128 ,
V_129 |
V_130 ) ;
if ( V_7 )
F_5 ( V_2 -> V_16 , L_15 ) ;
V_7 = V_126 ;
} else {
V_7 = V_146 ;
}
F_27 ( & V_2 -> V_61 ) ;
return V_7 ;
}
static T_8 F_64 ( int V_112 , void * V_144 )
{
struct V_38 * V_39 = V_144 ;
struct V_1 * V_2 = F_34 ( V_39 ) ;
bool V_145 = false ;
int V_6 ;
V_2 -> V_117 = V_2 -> V_118 ;
V_2 -> V_118 = F_50 () ;
for ( V_6 = 0 ; V_6 < V_95 ; V_6 ++ ) {
if ( V_2 -> V_96 [ V_6 ] . V_131 ) {
F_65 ( V_2 -> V_96 [ V_6 ] . V_97 ) ;
V_145 = true ;
break;
}
}
if ( V_2 -> V_90 || V_2 -> V_104 )
return V_147 ;
if ( V_145 )
return V_126 ;
return V_146 ;
}
static void F_66 ( struct V_1 * V_2 ,
int V_148 )
{
int V_6 ;
for ( V_6 = V_148 ; V_6 >= 0 ; V_6 -- ) {
if ( V_2 -> V_96 [ V_6 ] . V_97 ) {
F_67 ( V_2 -> V_96 [ V_6 ] . V_97 ) ;
V_2 -> V_96 [ V_6 ] . V_97 = NULL ;
}
}
}
static int F_68 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_95 ; V_6 ++ ) {
struct V_30 * V_31 = & V_2 -> V_96 [ V_6 ] ;
V_31 -> V_97 = F_69 ( V_2 -> V_16 ,
V_149 [ V_6 ] . V_150 ,
V_39 -> V_150 ,
V_39 -> V_151 ) ;
if ( ! V_31 -> V_97 ) {
V_7 = - V_152 ;
break;
}
V_31 -> V_97 -> V_16 . V_153 = V_2 -> V_16 ;
V_31 -> V_97 -> V_154 = & V_155 ;
V_31 -> V_45 = V_149 [ V_6 ] . V_45 ;
V_31 -> V_2 = V_2 ;
V_31 -> V_132 = V_149 [ V_6 ] . V_132 ;
F_70 ( V_31 -> V_97 , V_31 ) ;
V_7 = F_71 ( V_31 -> V_97 ) ;
if ( V_7 )
break;
}
if ( V_7 )
F_66 ( V_2 , V_6 - 1 ) ;
return V_7 ;
}
static int F_72 ( struct V_1 * V_2 )
{
T_1 V_156 = V_157 ;
int V_7 ;
V_7 = F_4 ( V_2 -> V_17 , V_156 , V_2 -> V_104 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 , L_17 ) ;
return V_7 ;
}
if ( ! V_2 -> V_104 )
return 0 ;
V_7 = F_4 ( V_2 -> V_17 , V_158 ,
V_2 -> V_103 ) ;
if ( V_7 < 0 )
F_5 ( V_2 -> V_16 , L_18 ) ;
return V_7 ;
}
static int F_73 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
return F_12 ( V_2 , true ) ;
}
static int F_74 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
int V_7 = 0 ;
if ( V_39 -> V_159 == V_160 )
return F_75 ( V_39 ) ;
F_25 ( & V_2 -> V_61 ) ;
if ( ! V_2 -> V_103 )
goto V_161;
V_7 = F_18 ( V_2 , V_162 ,
true ) ;
if ( V_7 )
goto V_161;
V_2 -> V_104 = V_163 ;
V_7 = F_72 ( V_2 ) ;
if ( V_7 ) {
V_2 -> V_104 = 0 ;
F_18 ( V_2 , V_162 ,
false ) ;
}
V_161:
F_27 ( & V_2 -> V_61 ) ;
return V_7 ;
}
static int F_76 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
if ( V_39 -> V_159 == V_160 )
return F_77 ( V_39 ) ;
F_25 ( & V_2 -> V_61 ) ;
if ( ! V_2 -> V_104 )
goto V_161;
F_18 ( V_2 , V_162 , false ) ;
F_49 ( V_39 , V_105 , false ) ;
V_2 -> V_104 = 0 ;
F_72 ( V_2 ) ;
V_161:
F_27 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_78 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_34 ( V_39 ) ;
return F_12 ( V_2 , false ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_7 , V_6 ;
unsigned int V_19 ;
V_7 = F_26 ( V_2 -> V_17 , V_164 , & V_19 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 ,
L_19 ) ;
return V_7 ;
}
F_3 ( V_2 -> V_16 , L_20 , V_19 ) ;
for ( V_6 = 0 ; V_6 < F_2 ( V_165 ) ; V_6 ++ ) {
if ( V_165 [ V_6 ] . V_166 == V_19 ) {
V_2 -> V_54 = & V_165 [ V_6 ] ;
break;
}
}
if ( ! V_2 -> V_54 ) {
F_5 ( V_2 -> V_16 , L_21 , V_19 ) ;
return - V_167 ;
}
V_7 = F_1 ( V_2 , V_168 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_2 , V_169 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_17 , V_57 ,
V_170 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 ,
L_22 ) ;
return V_7 ;
}
V_2 -> V_59 = V_170 ;
V_2 -> V_25 = V_171 ;
V_2 -> V_28 = V_172 ;
V_7 = F_7 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_2 -> V_17 , V_128 ,
V_129 |
V_130 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 ,
L_15 ) ;
return V_7 ;
}
return 0 ;
}
int F_80 ( struct V_98 * V_16 , struct V_17 * V_17 , int V_112 ,
const char * V_150 , bool V_173 )
{
struct V_1 * V_2 ;
struct V_38 * V_39 ;
int V_7 ;
V_39 = F_81 ( V_16 , sizeof( * V_2 ) ) ;
if ( ! V_39 )
return - V_152 ;
V_2 = F_34 ( V_39 ) ;
F_82 ( V_16 , V_39 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_112 = V_112 ;
V_2 -> V_17 = V_17 ;
V_7 = F_79 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_83 ( & V_2 -> V_61 ) ;
V_39 -> V_16 . V_153 = V_16 ;
V_39 -> V_174 = V_2 -> V_54 -> V_174 ;
V_39 -> V_175 = V_2 -> V_54 -> V_175 ;
V_39 -> V_150 = V_150 ? V_150 : V_2 -> V_54 -> V_150 ;
V_39 -> V_176 = V_177 ;
V_39 -> V_42 = & V_178 ;
V_7 = F_84 ( V_39 ,
& V_179 ,
F_55 ,
& V_180 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 , L_23 ) ;
return V_7 ;
}
if ( V_2 -> V_112 > 0 ) {
V_7 = F_85 (
V_2 -> V_16 , V_2 -> V_112 ,
F_64 ,
F_63 ,
V_181 ,
V_182 ,
V_39 ) ;
if ( V_7 )
goto V_183;
V_7 = F_4 ( V_2 -> V_17 , V_128 ,
V_130 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_16 , L_15 ) ;
goto V_183;
}
F_17 ( V_39 , V_2 ) ;
V_7 = F_68 ( V_39 , V_2 ) ;
if ( V_7 )
goto V_183;
if ( V_173 ) {
V_39 -> V_176 |= V_184 ;
V_39 -> V_42 = & V_185 ;
V_39 -> V_106 -> V_186 = V_187 ;
}
}
V_7 = F_86 ( V_16 ) ;
if ( V_7 )
goto V_188;
F_87 ( V_16 ) ;
F_88 ( V_16 , V_189 ) ;
F_89 ( V_16 ) ;
V_7 = F_90 ( V_39 ) ;
if ( V_7 < 0 ) {
F_5 ( V_16 , L_24 ) ;
goto V_188;
}
return 0 ;
V_188:
F_66 ( V_2 , V_95 - 1 ) ;
V_183:
F_91 ( V_39 ) ;
return V_7 ;
}
int F_92 ( struct V_98 * V_16 )
{
struct V_38 * V_39 = F_93 ( V_16 ) ;
struct V_1 * V_2 = F_34 ( V_39 ) ;
F_94 ( V_39 ) ;
F_95 ( V_2 -> V_16 ) ;
F_96 ( V_2 -> V_16 ) ;
F_16 ( V_2 -> V_16 ) ;
F_66 ( V_2 , V_95 - 1 ) ;
F_91 ( V_39 ) ;
F_25 ( & V_2 -> V_61 ) ;
F_1 ( V_2 , V_190 , 0 ) ;
F_27 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_97 ( struct V_98 * V_16 )
{
struct V_38 * V_39 = F_93 ( V_16 ) ;
struct V_1 * V_2 = F_34 ( V_39 ) ;
F_25 ( & V_2 -> V_61 ) ;
F_1 ( V_2 , V_191 , 0 ) ;
F_27 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_98 ( struct V_98 * V_16 )
{
struct V_38 * V_39 = F_93 ( V_16 ) ;
struct V_1 * V_2 = F_34 ( V_39 ) ;
F_25 ( & V_2 -> V_61 ) ;
if ( F_99 ( & V_2 -> V_53 ) )
F_1 ( V_2 , V_168 , 0 ) ;
F_72 ( V_2 ) ;
F_27 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_100 ( struct V_98 * V_16 )
{
struct V_38 * V_39 = F_93 ( V_16 ) ;
struct V_1 * V_2 = F_34 ( V_39 ) ;
int V_7 ;
F_3 ( V_2 -> V_16 , V_29 ) ;
V_7 = F_1 ( V_2 , V_191 , 0 ) ;
if ( V_7 < 0 )
return - V_192 ;
return 0 ;
}
static int F_101 ( struct V_98 * V_16 )
{
struct V_38 * V_39 = F_93 ( V_16 ) ;
struct V_1 * V_2 = F_34 ( V_39 ) ;
int V_7 ;
int V_193 ;
F_3 ( V_2 -> V_16 , V_29 ) ;
V_7 = F_1 ( V_2 , V_168 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_72 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_193 = F_11 ( V_2 ) ;
if ( V_193 < 20 )
F_102 ( V_193 * 1000 , 20000 ) ;
else
F_103 ( V_193 ) ;
return 0 ;
}
