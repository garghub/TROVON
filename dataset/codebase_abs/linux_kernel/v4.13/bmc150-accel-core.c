static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_9 ;
int V_10 ;
T_1 V_11 ;
int V_12 = - 1 ;
if ( V_5 > 0 ) {
for ( V_9 = 0 ; V_9 < F_3 ( V_13 ) ;
++ V_9 ) {
if ( V_13 [ V_9 ] . V_14 ==
V_5 )
V_12 =
V_13 [ V_9 ] . V_15 ;
}
} else {
V_12 = 0 ;
}
if ( V_12 < 0 )
return - V_16 ;
V_11 = V_4 << V_17 ;
V_11 |= ( V_12 << V_18 ) ;
F_4 ( V_7 , L_1 , V_11 ) ;
V_10 = F_5 ( V_2 -> V_8 , V_19 , V_11 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_2 ) ;
return V_10 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_20 ,
int V_21 )
{
int V_9 ;
int V_10 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_22 ) ; ++ V_9 ) {
if ( V_22 [ V_9 ] . V_20 == V_20 &&
V_22 [ V_9 ] . V_21 == V_21 ) {
V_10 = F_5 ( V_2 -> V_8 ,
V_23 ,
V_22 [ V_9 ] . V_24 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_24 =
V_22 [ V_9 ] . V_24 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 ;
V_10 = F_5 ( V_2 -> V_8 , V_25 ,
V_2 -> V_26 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_3 ) ;
return V_10 ;
}
V_10 = F_9 ( V_2 -> V_8 , V_27 ,
V_28 , V_2 -> V_29 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_4 ) ;
return V_10 ;
}
F_4 ( V_7 , L_5 , V_30 , V_2 -> V_26 ,
V_2 -> V_29 ) ;
return V_10 ;
}
static int F_10 ( struct V_31 * V_32 ,
bool V_33 )
{
if ( V_33 )
return F_8 ( V_32 -> V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int * V_20 ,
int * V_21 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_22 ) ; ++ V_9 ) {
if ( V_22 [ V_9 ] . V_24 == V_2 -> V_24 ) {
* V_20 = V_22 [ V_9 ] . V_20 ;
* V_21 = V_22 [ V_9 ] . V_21 ;
return V_34 ;
}
}
return - V_16 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_35 ) ; ++ V_9 ) {
if ( V_35 [ V_9 ] . V_24 == V_2 -> V_24 )
return V_35 [ V_9 ] . V_36 ;
}
return V_37 ;
}
static int F_13 ( struct V_1 * V_2 , bool V_38 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 ;
if ( V_38 ) {
V_10 = F_14 ( V_7 ) ;
} else {
F_15 ( V_7 ) ;
V_10 = F_16 ( V_7 ) ;
}
if ( V_10 < 0 ) {
F_6 ( V_7 ,
L_6 , V_38 ) ;
if ( V_38 )
F_17 ( V_7 ) ;
return V_10 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , bool V_38 )
{
return 0 ;
}
static void F_18 ( struct V_39 * V_40 ,
struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_41 ; V_9 ++ )
V_2 -> V_42 [ V_9 ] . V_43 = & V_44 [ V_9 ] ;
}
static int F_19 ( struct V_1 * V_2 , int V_9 ,
bool V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_45 * V_46 = & V_2 -> V_42 [ V_9 ] ;
const struct V_47 * V_43 = V_46 -> V_43 ;
int V_10 ;
if ( V_33 ) {
if ( F_20 ( & V_46 -> V_48 ) > 1 )
return 0 ;
} else {
if ( F_21 ( & V_46 -> V_48 ) > 0 )
return 0 ;
}
V_10 = F_13 ( V_2 , V_33 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_9 ( V_2 -> V_8 , V_43 -> V_49 , V_43 -> V_50 ,
( V_33 ? V_43 -> V_50 : 0 ) ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_7 ) ;
goto V_51;
}
V_10 = F_9 ( V_2 -> V_8 , V_43 -> V_52 , V_43 -> V_53 ,
( V_33 ? V_43 -> V_53 : 0 ) ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_8 ) ;
goto V_51;
}
return 0 ;
V_51:
F_13 ( V_2 , false ) ;
return V_10 ;
}
static int F_22 ( struct V_1 * V_2 , int V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 , V_9 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_2 -> V_54 -> V_55 ) ; ++ V_9 ) {
if ( V_2 -> V_54 -> V_55 [ V_9 ] . V_56 == V_20 ) {
V_10 = F_5 ( V_2 -> V_8 ,
V_57 ,
V_2 -> V_54 -> V_55 [ V_9 ] . V_58 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_9 ) ;
return V_10 ;
}
V_2 -> V_59 = V_2 -> V_54 -> V_55 [ V_9 ] . V_58 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_23 ( struct V_1 * V_2 , int * V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 ;
unsigned int V_60 ;
F_24 ( & V_2 -> V_61 ) ;
V_10 = F_25 ( V_2 -> V_8 , V_62 , & V_60 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_10 ) ;
F_26 ( & V_2 -> V_61 ) ;
return V_10 ;
}
* V_20 = F_27 ( V_60 , 7 ) ;
F_26 ( & V_2 -> V_61 ) ;
return V_63 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_64 const * V_65 ,
int * V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 ;
int V_66 = V_65 -> V_67 ;
T_2 V_68 ;
F_24 ( & V_2 -> V_61 ) ;
V_10 = F_13 ( V_2 , true ) ;
if ( V_10 < 0 ) {
F_26 ( & V_2 -> V_61 ) ;
return V_10 ;
}
V_10 = F_29 ( V_2 -> V_8 , F_30 ( V_66 ) ,
& V_68 , sizeof( V_68 ) ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_11 , V_66 ) ;
F_13 ( V_2 , false ) ;
F_26 ( & V_2 -> V_61 ) ;
return V_10 ;
}
* V_20 = F_27 ( F_31 ( V_68 ) >> V_65 -> V_69 . V_70 ,
V_65 -> V_69 . V_71 - 1 ) ;
V_10 = F_13 ( V_2 , false ) ;
F_26 ( & V_2 -> V_61 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_63 ;
}
static int F_32 ( struct V_39 * V_40 ,
struct V_64 const * V_65 ,
int * V_20 , int * V_21 , long V_72 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_10 ;
switch ( V_72 ) {
case V_73 :
switch ( V_65 -> type ) {
case V_74 :
return F_23 ( V_2 , V_20 ) ;
case V_75 :
if ( F_34 ( V_40 ) )
return - V_76 ;
else
return F_28 ( V_2 , V_65 , V_20 ) ;
default:
return - V_16 ;
}
case V_77 :
if ( V_65 -> type == V_74 ) {
* V_20 = V_78 ;
return V_63 ;
} else {
return - V_16 ;
}
case V_79 :
* V_20 = 0 ;
switch ( V_65 -> type ) {
case V_74 :
* V_21 = 500000 ;
return V_34 ;
case V_75 :
{
int V_9 ;
const struct V_80 * V_81 ;
int V_82 = F_3 ( V_2 -> V_54 -> V_55 ) ;
for ( V_9 = 0 ; V_9 < V_82 ; ++ V_9 ) {
V_81 = & V_2 -> V_54 -> V_55 [ V_9 ] ;
if ( V_81 -> V_58 == V_2 -> V_59 ) {
* V_21 = V_81 -> V_56 ;
return V_34 ;
}
}
return - V_16 ;
}
default:
return - V_16 ;
}
case V_83 :
F_24 ( & V_2 -> V_61 ) ;
V_10 = F_11 ( V_2 , V_20 , V_21 ) ;
F_26 ( & V_2 -> V_61 ) ;
return V_10 ;
default:
return - V_16 ;
}
}
static int F_35 ( struct V_39 * V_40 ,
struct V_64 const * V_65 ,
int V_20 , int V_21 , long V_72 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_10 ;
switch ( V_72 ) {
case V_83 :
F_24 ( & V_2 -> V_61 ) ;
V_10 = F_7 ( V_2 , V_20 , V_21 ) ;
F_26 ( & V_2 -> V_61 ) ;
break;
case V_79 :
if ( V_20 )
return - V_16 ;
F_24 ( & V_2 -> V_61 ) ;
V_10 = F_22 ( V_2 , V_21 ) ;
F_26 ( & V_2 -> V_61 ) ;
return V_10 ;
default:
V_10 = - V_16 ;
}
return V_10 ;
}
static int F_36 ( struct V_39 * V_40 ,
const struct V_64 * V_65 ,
enum V_84 type ,
enum V_85 V_86 ,
enum V_87 V_43 ,
int * V_20 , int * V_21 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
* V_21 = 0 ;
switch ( V_43 ) {
case V_88 :
* V_20 = V_2 -> V_26 ;
break;
case V_89 :
* V_20 = V_2 -> V_29 ;
break;
default:
return - V_16 ;
}
return V_63 ;
}
static int F_37 ( struct V_39 * V_40 ,
const struct V_64 * V_65 ,
enum V_84 type ,
enum V_85 V_86 ,
enum V_87 V_43 ,
int V_20 , int V_21 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
if ( V_2 -> V_90 )
return - V_76 ;
switch ( V_43 ) {
case V_88 :
V_2 -> V_26 = V_20 & V_91 ;
break;
case V_89 :
V_2 -> V_29 = V_20 & V_28 ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_38 ( struct V_39 * V_40 ,
const struct V_64 * V_65 ,
enum V_84 type ,
enum V_85 V_86 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
return V_2 -> V_90 ;
}
static int F_39 ( struct V_39 * V_40 ,
const struct V_64 * V_65 ,
enum V_84 type ,
enum V_85 V_86 ,
int V_33 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_10 ;
if ( V_33 == V_2 -> V_90 )
return 0 ;
F_24 ( & V_2 -> V_61 ) ;
V_10 = F_19 ( V_2 , V_92 ,
V_33 ) ;
if ( V_10 < 0 ) {
F_26 ( & V_2 -> V_61 ) ;
return V_10 ;
}
V_2 -> V_90 = V_33 ;
F_26 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_40 ( struct V_39 * V_40 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_95 ; V_9 ++ ) {
if ( V_2 -> V_96 [ V_9 ] . V_97 == V_94 )
return 0 ;
}
return - V_16 ;
}
static T_3 F_41 ( struct V_6 * V_7 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_39 * V_40 = F_42 ( V_7 ) ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_101 ;
F_24 ( & V_2 -> V_61 ) ;
V_101 = V_2 -> V_102 ;
F_26 ( & V_2 -> V_61 ) ;
return sprintf ( V_100 , L_12 , V_101 ) ;
}
static T_3 F_43 ( struct V_6 * V_7 ,
struct V_98 * V_99 ,
char * V_100 )
{
struct V_39 * V_40 = F_42 ( V_7 ) ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
bool V_33 ;
F_24 ( & V_2 -> V_61 ) ;
V_33 = V_2 -> V_103 ;
F_26 ( & V_2 -> V_61 ) ;
return sprintf ( V_100 , L_12 , V_33 ) ;
}
static int F_44 ( struct V_39 * V_40 , unsigned V_20 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
if ( V_20 > V_104 )
V_20 = V_104 ;
F_24 ( & V_2 -> V_61 ) ;
V_2 -> V_102 = V_20 ;
F_26 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
char * V_105 , int V_106 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_107 = 3 * 2 ;
int V_10 ;
int V_108 = V_106 * V_107 ;
int V_9 ;
T_4 V_109 = F_46 ( V_2 -> V_8 ) ;
if ( ! V_109 || V_109 > V_108 )
V_109 = V_108 ;
else if ( V_109 < V_108 )
V_109 = V_107 ;
for ( V_9 = 0 ; V_9 < V_108 ; V_9 += V_109 ) {
V_10 = F_47 ( V_2 -> V_8 , V_110 ,
& V_105 [ V_9 ] , V_109 ) ;
if ( V_10 )
break;
}
if ( V_10 )
F_6 ( V_7 ,
L_13 ,
V_109 ) ;
return V_10 ;
}
static int F_48 ( struct V_39 * V_40 ,
unsigned V_106 , bool V_111 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 , V_9 ;
T_1 V_112 ;
T_5 V_105 [ V_104 * 3 ] ;
T_6 V_113 ;
T_7 V_114 ;
unsigned int V_20 ;
V_10 = F_25 ( V_2 -> V_8 , V_115 , & V_20 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_14 ) ;
return V_10 ;
}
V_112 = V_20 & 0x7F ;
if ( ! V_112 )
return 0 ;
if ( ! V_111 ) {
V_2 -> V_116 = V_2 -> V_117 ;
V_2 -> V_117 = F_49 ( V_40 ) ;
}
V_114 = ( V_2 -> V_117 - V_2 -> V_116 ) ;
F_50 ( V_114 , V_112 ) ;
V_113 = V_2 -> V_117 - ( V_112 - 1 ) * V_114 ;
if ( V_106 && V_112 > V_106 )
V_112 = V_106 ;
V_10 = F_45 ( V_2 , ( T_1 * ) V_105 , V_112 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_112 ; V_9 ++ ) {
T_5 V_118 [ 8 ] ;
int V_119 , V_120 ;
V_119 = 0 ;
F_51 (bit, indio_dev->active_scan_mask,
indio_dev->masklength)
memcpy ( & V_118 [ V_119 ++ ] , & V_105 [ V_9 * 3 + V_120 ] , 2 ) ;
F_52 ( V_40 , V_118 , V_113 ) ;
V_113 += V_114 ;
}
return V_112 ;
}
static int F_53 ( struct V_39 * V_40 , unsigned V_106 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_10 ;
F_24 ( & V_2 -> V_61 ) ;
V_10 = F_48 ( V_40 , V_106 , false ) ;
F_26 ( & V_2 -> V_61 ) ;
return V_10 ;
}
static T_8 F_54 ( int V_111 , void * V_121 )
{
struct V_122 * V_123 = V_121 ;
struct V_39 * V_40 = V_123 -> V_40 ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_10 ;
F_24 ( & V_2 -> V_61 ) ;
V_10 = F_29 ( V_2 -> V_8 , V_124 ,
V_2 -> V_105 , V_125 * 2 ) ;
F_26 ( & V_2 -> V_61 ) ;
if ( V_10 < 0 )
goto V_126;
F_52 ( V_40 , V_2 -> V_105 ,
V_123 -> V_117 ) ;
V_126:
F_55 ( V_40 -> V_94 ) ;
return V_127 ;
}
static int F_56 ( struct V_93 * V_94 )
{
struct V_31 * V_32 = F_57 ( V_94 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 ;
if ( V_32 == & V_32 -> V_2 -> V_96 [ V_128 ] )
return 0 ;
F_24 ( & V_2 -> V_61 ) ;
V_10 = F_5 ( V_2 -> V_8 , V_129 ,
V_130 |
V_131 ) ;
F_26 ( & V_2 -> V_61 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_15 ) ;
return V_10 ;
}
return 0 ;
}
static int F_58 ( struct V_93 * V_94 ,
bool V_33 )
{
struct V_31 * V_32 = F_57 ( V_94 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
int V_10 ;
F_24 ( & V_2 -> V_61 ) ;
if ( V_32 -> V_132 == V_33 ) {
F_26 ( & V_2 -> V_61 ) ;
return 0 ;
}
if ( V_32 -> V_133 ) {
V_10 = V_32 -> V_133 ( V_32 , V_33 ) ;
if ( V_10 < 0 ) {
F_26 ( & V_2 -> V_61 ) ;
return V_10 ;
}
}
V_10 = F_19 ( V_2 , V_32 -> V_46 , V_33 ) ;
if ( V_10 < 0 ) {
F_26 ( & V_2 -> V_61 ) ;
return V_10 ;
}
V_32 -> V_132 = V_33 ;
F_26 ( & V_2 -> V_61 ) ;
return V_10 ;
}
static int F_59 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_86 ;
int V_10 ;
unsigned int V_20 ;
V_10 = F_25 ( V_2 -> V_8 , V_134 , & V_20 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_16 ) ;
return V_10 ;
}
if ( V_20 & V_135 )
V_86 = V_136 ;
else
V_86 = V_137 ;
if ( V_20 & V_138 )
F_60 ( V_40 ,
F_61 ( V_75 ,
0 ,
V_139 ,
V_140 ,
V_86 ) ,
V_2 -> V_117 ) ;
if ( V_20 & V_141 )
F_60 ( V_40 ,
F_61 ( V_75 ,
0 ,
V_142 ,
V_140 ,
V_86 ) ,
V_2 -> V_117 ) ;
if ( V_20 & V_143 )
F_60 ( V_40 ,
F_61 ( V_75 ,
0 ,
V_144 ,
V_140 ,
V_86 ) ,
V_2 -> V_117 ) ;
return V_10 ;
}
static T_8 F_62 ( int V_111 , void * V_145 )
{
struct V_39 * V_40 = V_145 ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
bool V_146 = false ;
int V_10 ;
F_24 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_103 ) {
V_10 = F_48 ( V_40 ,
V_104 , true ) ;
if ( V_10 > 0 )
V_146 = true ;
}
if ( V_2 -> V_90 ) {
V_10 = F_59 ( V_40 ) ;
if ( V_10 > 0 )
V_146 = true ;
}
if ( V_146 ) {
V_10 = F_5 ( V_2 -> V_8 , V_129 ,
V_130 |
V_131 ) ;
if ( V_10 )
F_6 ( V_7 , L_15 ) ;
V_10 = V_127 ;
} else {
V_10 = V_147 ;
}
F_26 ( & V_2 -> V_61 ) ;
return V_10 ;
}
static T_8 F_63 ( int V_111 , void * V_145 )
{
struct V_39 * V_40 = V_145 ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
bool V_146 = false ;
int V_9 ;
V_2 -> V_116 = V_2 -> V_117 ;
V_2 -> V_117 = F_49 ( V_40 ) ;
for ( V_9 = 0 ; V_9 < V_95 ; V_9 ++ ) {
if ( V_2 -> V_96 [ V_9 ] . V_132 ) {
F_64 ( V_2 -> V_96 [ V_9 ] . V_97 ) ;
V_146 = true ;
break;
}
}
if ( V_2 -> V_90 || V_2 -> V_103 )
return V_148 ;
if ( V_146 )
return V_127 ;
return V_147 ;
}
static void F_65 ( struct V_1 * V_2 ,
int V_149 )
{
int V_9 ;
for ( V_9 = V_149 ; V_9 >= 0 ; V_9 -- ) {
if ( V_2 -> V_96 [ V_9 ] . V_97 ) {
F_66 ( V_2 -> V_96 [ V_9 ] . V_97 ) ;
V_2 -> V_96 [ V_9 ] . V_97 = NULL ;
}
}
}
static int F_67 ( struct V_39 * V_40 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < V_95 ; V_9 ++ ) {
struct V_31 * V_32 = & V_2 -> V_96 [ V_9 ] ;
V_32 -> V_97 = F_68 ( V_7 ,
V_150 [ V_9 ] . V_151 ,
V_40 -> V_151 ,
V_40 -> V_152 ) ;
if ( ! V_32 -> V_97 ) {
V_10 = - V_153 ;
break;
}
V_32 -> V_97 -> V_7 . V_154 = V_7 ;
V_32 -> V_97 -> V_155 = & V_156 ;
V_32 -> V_46 = V_150 [ V_9 ] . V_46 ;
V_32 -> V_2 = V_2 ;
V_32 -> V_133 = V_150 [ V_9 ] . V_133 ;
F_69 ( V_32 -> V_97 , V_32 ) ;
V_10 = F_70 ( V_32 -> V_97 ) ;
if ( V_10 )
break;
}
if ( V_10 )
F_65 ( V_2 , V_9 - 1 ) ;
return V_10 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
T_1 V_157 = V_158 ;
int V_10 ;
V_10 = F_5 ( V_2 -> V_8 , V_157 , V_2 -> V_103 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_17 ) ;
return V_10 ;
}
if ( ! V_2 -> V_103 )
return 0 ;
V_10 = F_5 ( V_2 -> V_8 , V_159 ,
V_2 -> V_102 ) ;
if ( V_10 < 0 )
F_6 ( V_7 , L_18 ) ;
return V_10 ;
}
static int F_72 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
return F_13 ( V_2 , true ) ;
}
static int F_73 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_10 = 0 ;
if ( V_40 -> V_160 == V_161 )
return F_74 ( V_40 ) ;
F_24 ( & V_2 -> V_61 ) ;
if ( ! V_2 -> V_102 )
goto V_162;
V_10 = F_19 ( V_2 , V_163 ,
true ) ;
if ( V_10 )
goto V_162;
V_2 -> V_103 = V_164 ;
V_10 = F_71 ( V_2 ) ;
if ( V_10 ) {
V_2 -> V_103 = 0 ;
F_19 ( V_2 , V_163 ,
false ) ;
}
V_162:
F_26 ( & V_2 -> V_61 ) ;
return V_10 ;
}
static int F_75 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
if ( V_40 -> V_160 == V_161 )
return F_76 ( V_40 ) ;
F_24 ( & V_2 -> V_61 ) ;
if ( ! V_2 -> V_103 )
goto V_162;
F_19 ( V_2 , V_163 , false ) ;
F_48 ( V_40 , V_104 , false ) ;
V_2 -> V_103 = 0 ;
F_71 ( V_2 ) ;
V_162:
F_26 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_77 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
return F_13 ( V_2 , false ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 , V_9 ;
unsigned int V_20 ;
F_5 ( V_2 -> V_8 , V_165 ,
V_166 ) ;
F_79 ( 1800 , 2500 ) ;
V_10 = F_25 ( V_2 -> V_8 , V_167 , & V_20 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_19 ) ;
return V_10 ;
}
F_4 ( V_7 , L_20 , V_20 ) ;
for ( V_9 = 0 ; V_9 < F_3 ( V_168 ) ; V_9 ++ ) {
if ( V_168 [ V_9 ] . V_169 == V_20 ) {
V_2 -> V_54 = & V_168 [ V_9 ] ;
break;
}
}
if ( ! V_2 -> V_54 ) {
F_6 ( V_7 , L_21 , V_20 ) ;
return - V_170 ;
}
V_10 = F_1 ( V_2 , V_171 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_7 ( V_2 , V_172 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( V_2 -> V_8 , V_57 ,
V_173 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_22 ) ;
return V_10 ;
}
V_2 -> V_59 = V_173 ;
V_2 -> V_26 = V_174 ;
V_2 -> V_29 = V_175 ;
V_10 = F_8 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( V_2 -> V_8 , V_129 ,
V_130 |
V_131 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_15 ) ;
return V_10 ;
}
return 0 ;
}
int F_80 ( struct V_6 * V_7 , struct V_8 * V_8 , int V_111 ,
const char * V_151 , bool V_176 )
{
struct V_1 * V_2 ;
struct V_39 * V_40 ;
int V_10 ;
V_40 = F_81 ( V_7 , sizeof( * V_2 ) ) ;
if ( ! V_40 )
return - V_153 ;
V_2 = F_33 ( V_40 ) ;
F_82 ( V_7 , V_40 ) ;
V_2 -> V_111 = V_111 ;
V_2 -> V_8 = V_8 ;
V_10 = F_78 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
F_83 ( & V_2 -> V_61 ) ;
V_40 -> V_7 . V_154 = V_7 ;
V_40 -> V_177 = V_2 -> V_54 -> V_177 ;
V_40 -> V_178 = V_2 -> V_54 -> V_178 ;
V_40 -> V_151 = V_151 ? V_151 : V_2 -> V_54 -> V_151 ;
V_40 -> V_179 = V_180 ;
V_40 -> V_181 = V_182 ;
V_40 -> V_43 = & V_183 ;
V_10 = F_84 ( V_40 ,
& V_184 ,
F_54 ,
& V_185 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_23 ) ;
return V_10 ;
}
if ( V_2 -> V_111 > 0 ) {
V_10 = F_85 (
V_7 , V_2 -> V_111 ,
F_63 ,
F_62 ,
V_186 ,
V_187 ,
V_40 ) ;
if ( V_10 )
goto V_188;
V_10 = F_5 ( V_2 -> V_8 , V_129 ,
V_131 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_15 ) ;
goto V_188;
}
F_18 ( V_40 , V_2 ) ;
V_10 = F_67 ( V_40 , V_2 ) ;
if ( V_10 )
goto V_188;
if ( V_176 ) {
V_40 -> V_181 |= V_189 ;
V_40 -> V_43 = & V_190 ;
F_86 ( V_40 -> V_105 ,
V_191 ) ;
}
}
V_10 = F_87 ( V_7 ) ;
if ( V_10 )
goto V_192;
F_88 ( V_7 ) ;
F_89 ( V_7 , V_193 ) ;
F_90 ( V_7 ) ;
V_10 = F_91 ( V_40 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_24 ) ;
goto V_192;
}
return 0 ;
V_192:
F_65 ( V_2 , V_95 - 1 ) ;
V_188:
F_92 ( V_40 ) ;
return V_10 ;
}
int F_93 ( struct V_6 * V_7 )
{
struct V_39 * V_40 = F_94 ( V_7 ) ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
F_95 ( V_40 ) ;
F_96 ( V_7 ) ;
F_97 ( V_7 ) ;
F_17 ( V_7 ) ;
F_65 ( V_2 , V_95 - 1 ) ;
F_92 ( V_40 ) ;
F_24 ( & V_2 -> V_61 ) ;
F_1 ( V_2 , V_194 , 0 ) ;
F_26 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_98 ( struct V_6 * V_7 )
{
struct V_39 * V_40 = F_94 ( V_7 ) ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
F_24 ( & V_2 -> V_61 ) ;
F_1 ( V_2 , V_195 , 0 ) ;
F_26 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_99 ( struct V_6 * V_7 )
{
struct V_39 * V_40 = F_94 ( V_7 ) ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
F_24 ( & V_2 -> V_61 ) ;
F_1 ( V_2 , V_171 , 0 ) ;
F_71 ( V_2 ) ;
F_26 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_100 ( struct V_6 * V_7 )
{
struct V_39 * V_40 = F_94 ( V_7 ) ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_10 ;
F_4 ( V_7 , V_30 ) ;
V_10 = F_1 ( V_2 , V_195 , 0 ) ;
if ( V_10 < 0 )
return - V_196 ;
return 0 ;
}
static int F_101 ( struct V_6 * V_7 )
{
struct V_39 * V_40 = F_94 ( V_7 ) ;
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_10 ;
int V_197 ;
F_4 ( V_7 , V_30 ) ;
V_10 = F_1 ( V_2 , V_171 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_71 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_197 = F_12 ( V_2 ) ;
if ( V_197 < 20 )
F_79 ( V_197 * 1000 , 20000 ) ;
else
F_102 ( V_197 ) ;
return 0 ;
}
