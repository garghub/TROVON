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
if ( V_33 )
F_22 ( & V_2 -> V_54 ) ;
else
F_23 ( & V_2 -> V_54 ) ;
return 0 ;
V_51:
F_13 ( V_2 , false ) ;
return V_10 ;
}
static int F_24 ( struct V_1 * V_2 , int V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 , V_9 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_2 -> V_55 -> V_56 ) ; ++ V_9 ) {
if ( V_2 -> V_55 -> V_56 [ V_9 ] . V_57 == V_20 ) {
V_10 = F_5 ( V_2 -> V_8 ,
V_58 ,
V_2 -> V_55 -> V_56 [ V_9 ] . V_59 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_9 ) ;
return V_10 ;
}
V_2 -> V_60 = V_2 -> V_55 -> V_56 [ V_9 ] . V_59 ;
return 0 ;
}
}
return - V_16 ;
}
static int F_25 ( struct V_1 * V_2 , int * V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 ;
unsigned int V_61 ;
F_26 ( & V_2 -> V_62 ) ;
V_10 = F_27 ( V_2 -> V_8 , V_63 , & V_61 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_10 ) ;
F_28 ( & V_2 -> V_62 ) ;
return V_10 ;
}
* V_20 = F_29 ( V_61 , 7 ) ;
F_28 ( & V_2 -> V_62 ) ;
return V_64 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_65 const * V_66 ,
int * V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 ;
int V_67 = V_66 -> V_68 ;
T_2 V_69 ;
F_26 ( & V_2 -> V_62 ) ;
V_10 = F_13 ( V_2 , true ) ;
if ( V_10 < 0 ) {
F_28 ( & V_2 -> V_62 ) ;
return V_10 ;
}
V_10 = F_31 ( V_2 -> V_8 , F_32 ( V_67 ) ,
& V_69 , sizeof( V_69 ) ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_11 , V_67 ) ;
F_13 ( V_2 , false ) ;
F_28 ( & V_2 -> V_62 ) ;
return V_10 ;
}
* V_20 = F_29 ( F_33 ( V_69 ) >> V_66 -> V_70 . V_71 ,
V_66 -> V_70 . V_72 - 1 ) ;
V_10 = F_13 ( V_2 , false ) ;
F_28 ( & V_2 -> V_62 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_64 ;
}
static int F_34 ( struct V_39 * V_40 ,
struct V_65 const * V_66 ,
int * V_20 , int * V_21 , long V_73 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
int V_10 ;
switch ( V_73 ) {
case V_74 :
switch ( V_66 -> type ) {
case V_75 :
return F_25 ( V_2 , V_20 ) ;
case V_76 :
if ( F_36 ( V_40 ) )
return - V_77 ;
else
return F_30 ( V_2 , V_66 , V_20 ) ;
default:
return - V_16 ;
}
case V_78 :
if ( V_66 -> type == V_75 ) {
* V_20 = V_79 ;
return V_64 ;
} else {
return - V_16 ;
}
case V_80 :
* V_20 = 0 ;
switch ( V_66 -> type ) {
case V_75 :
* V_21 = 500000 ;
return V_34 ;
case V_76 :
{
int V_9 ;
const struct V_81 * V_82 ;
int V_83 = F_3 ( V_2 -> V_55 -> V_56 ) ;
for ( V_9 = 0 ; V_9 < V_83 ; ++ V_9 ) {
V_82 = & V_2 -> V_55 -> V_56 [ V_9 ] ;
if ( V_82 -> V_59 == V_2 -> V_60 ) {
* V_21 = V_82 -> V_57 ;
return V_34 ;
}
}
return - V_16 ;
}
default:
return - V_16 ;
}
case V_84 :
F_26 ( & V_2 -> V_62 ) ;
V_10 = F_11 ( V_2 , V_20 , V_21 ) ;
F_28 ( & V_2 -> V_62 ) ;
return V_10 ;
default:
return - V_16 ;
}
}
static int F_37 ( struct V_39 * V_40 ,
struct V_65 const * V_66 ,
int V_20 , int V_21 , long V_73 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
int V_10 ;
switch ( V_73 ) {
case V_84 :
F_26 ( & V_2 -> V_62 ) ;
V_10 = F_7 ( V_2 , V_20 , V_21 ) ;
F_28 ( & V_2 -> V_62 ) ;
break;
case V_80 :
if ( V_20 )
return - V_16 ;
F_26 ( & V_2 -> V_62 ) ;
V_10 = F_24 ( V_2 , V_21 ) ;
F_28 ( & V_2 -> V_62 ) ;
return V_10 ;
default:
V_10 = - V_16 ;
}
return V_10 ;
}
static int F_38 ( struct V_39 * V_40 ,
const struct V_65 * V_66 ,
enum V_85 type ,
enum V_86 V_87 ,
enum V_88 V_43 ,
int * V_20 , int * V_21 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
* V_21 = 0 ;
switch ( V_43 ) {
case V_89 :
* V_20 = V_2 -> V_26 ;
break;
case V_90 :
* V_20 = V_2 -> V_29 ;
break;
default:
return - V_16 ;
}
return V_64 ;
}
static int F_39 ( struct V_39 * V_40 ,
const struct V_65 * V_66 ,
enum V_85 type ,
enum V_86 V_87 ,
enum V_88 V_43 ,
int V_20 , int V_21 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
if ( V_2 -> V_91 )
return - V_77 ;
switch ( V_43 ) {
case V_89 :
V_2 -> V_26 = V_20 & V_92 ;
break;
case V_90 :
V_2 -> V_29 = V_20 & V_28 ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_40 ( struct V_39 * V_40 ,
const struct V_65 * V_66 ,
enum V_85 type ,
enum V_86 V_87 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
return V_2 -> V_91 ;
}
static int F_41 ( struct V_39 * V_40 ,
const struct V_65 * V_66 ,
enum V_85 type ,
enum V_86 V_87 ,
int V_33 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
int V_10 ;
if ( V_33 == V_2 -> V_91 )
return 0 ;
F_26 ( & V_2 -> V_62 ) ;
V_10 = F_19 ( V_2 , V_93 ,
V_33 ) ;
if ( V_10 < 0 ) {
F_28 ( & V_2 -> V_62 ) ;
return V_10 ;
}
V_2 -> V_91 = V_33 ;
F_28 ( & V_2 -> V_62 ) ;
return 0 ;
}
static int F_42 ( struct V_39 * V_40 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_96 ; V_9 ++ ) {
if ( V_2 -> V_97 [ V_9 ] . V_98 == V_95 )
return 0 ;
}
return - V_16 ;
}
static T_3 F_43 ( struct V_6 * V_7 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_39 * V_40 = F_44 ( V_7 ) ;
struct V_1 * V_2 = F_35 ( V_40 ) ;
int V_102 ;
F_26 ( & V_2 -> V_62 ) ;
V_102 = V_2 -> V_103 ;
F_28 ( & V_2 -> V_62 ) ;
return sprintf ( V_101 , L_12 , V_102 ) ;
}
static T_3 F_45 ( struct V_6 * V_7 ,
struct V_99 * V_100 ,
char * V_101 )
{
struct V_39 * V_40 = F_44 ( V_7 ) ;
struct V_1 * V_2 = F_35 ( V_40 ) ;
bool V_33 ;
F_26 ( & V_2 -> V_62 ) ;
V_33 = V_2 -> V_104 ;
F_28 ( & V_2 -> V_62 ) ;
return sprintf ( V_101 , L_12 , V_33 ) ;
}
static int F_46 ( struct V_39 * V_40 , unsigned V_20 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
if ( V_20 > V_105 )
V_20 = V_105 ;
F_26 ( & V_2 -> V_62 ) ;
V_2 -> V_103 = V_20 ;
F_28 ( & V_2 -> V_62 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
char * V_106 , int V_107 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_108 = 3 * 2 ;
int V_10 ;
int V_109 = V_107 * V_108 ;
int V_9 ;
T_4 V_110 = F_48 ( V_2 -> V_8 ) ;
if ( ! V_110 || V_110 > V_109 )
V_110 = V_109 ;
else if ( V_110 < V_109 )
V_110 = V_108 ;
for ( V_9 = 0 ; V_9 < V_109 ; V_9 += V_110 ) {
V_10 = F_49 ( V_2 -> V_8 , V_111 ,
& V_106 [ V_9 ] , V_110 ) ;
if ( V_10 )
break;
}
if ( V_10 )
F_6 ( V_7 ,
L_13 ,
V_110 ) ;
return V_10 ;
}
static int F_50 ( struct V_39 * V_40 ,
unsigned V_107 , bool V_112 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 , V_9 ;
T_1 V_113 ;
T_5 V_106 [ V_105 * 3 ] ;
T_6 V_114 ;
T_7 V_115 ;
unsigned int V_20 ;
V_10 = F_27 ( V_2 -> V_8 , V_116 , & V_20 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_14 ) ;
return V_10 ;
}
V_113 = V_20 & 0x7F ;
if ( ! V_113 )
return 0 ;
if ( ! V_112 ) {
V_2 -> V_117 = V_2 -> V_118 ;
V_2 -> V_118 = F_51 () ;
}
V_115 = ( V_2 -> V_118 - V_2 -> V_117 ) ;
F_52 ( V_115 , V_113 ) ;
V_114 = V_2 -> V_118 - ( V_113 - 1 ) * V_115 ;
if ( V_107 && V_113 > V_107 )
V_113 = V_107 ;
V_10 = F_47 ( V_2 , ( T_1 * ) V_106 , V_113 ) ;
if ( V_10 )
return V_10 ;
for ( V_9 = 0 ; V_9 < V_113 ; V_9 ++ ) {
T_5 V_119 [ 8 ] ;
int V_120 , V_121 ;
V_120 = 0 ;
F_53 (bit, indio_dev->active_scan_mask,
indio_dev->masklength)
memcpy ( & V_119 [ V_120 ++ ] , & V_106 [ V_9 * 3 + V_121 ] , 2 ) ;
F_54 ( V_40 , V_119 , V_114 ) ;
V_114 += V_115 ;
}
return V_113 ;
}
static int F_55 ( struct V_39 * V_40 , unsigned V_107 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
int V_10 ;
F_26 ( & V_2 -> V_62 ) ;
V_10 = F_50 ( V_40 , V_107 , false ) ;
F_28 ( & V_2 -> V_62 ) ;
return V_10 ;
}
static T_8 F_56 ( int V_112 , void * V_122 )
{
struct V_123 * V_124 = V_122 ;
struct V_39 * V_40 = V_124 -> V_40 ;
struct V_1 * V_2 = F_35 ( V_40 ) ;
int V_10 ;
F_26 ( & V_2 -> V_62 ) ;
V_10 = F_31 ( V_2 -> V_8 , V_125 ,
V_2 -> V_106 , V_126 * 2 ) ;
F_28 ( & V_2 -> V_62 ) ;
if ( V_10 < 0 )
goto V_127;
F_54 ( V_40 , V_2 -> V_106 ,
V_124 -> V_118 ) ;
V_127:
F_57 ( V_40 -> V_95 ) ;
return V_128 ;
}
static int F_58 ( struct V_94 * V_95 )
{
struct V_31 * V_32 = F_59 ( V_95 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 ;
if ( V_32 == & V_32 -> V_2 -> V_97 [ V_129 ] )
return 0 ;
F_26 ( & V_2 -> V_62 ) ;
V_10 = F_5 ( V_2 -> V_8 , V_130 ,
V_131 |
V_132 ) ;
F_28 ( & V_2 -> V_62 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_15 ) ;
return V_10 ;
}
return 0 ;
}
static int F_60 ( struct V_94 * V_95 ,
bool V_33 )
{
struct V_31 * V_32 = F_59 ( V_95 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
int V_10 ;
F_26 ( & V_2 -> V_62 ) ;
if ( V_32 -> V_133 == V_33 ) {
F_28 ( & V_2 -> V_62 ) ;
return 0 ;
}
if ( V_32 -> V_134 ) {
V_10 = V_32 -> V_134 ( V_32 , V_33 ) ;
if ( V_10 < 0 ) {
F_28 ( & V_2 -> V_62 ) ;
return V_10 ;
}
}
V_10 = F_19 ( V_2 , V_32 -> V_46 , V_33 ) ;
if ( V_10 < 0 ) {
F_28 ( & V_2 -> V_62 ) ;
return V_10 ;
}
V_32 -> V_133 = V_33 ;
F_28 ( & V_2 -> V_62 ) ;
return V_10 ;
}
static int F_61 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_87 ;
int V_10 ;
unsigned int V_20 ;
V_10 = F_27 ( V_2 -> V_8 , V_135 , & V_20 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_16 ) ;
return V_10 ;
}
if ( V_20 & V_136 )
V_87 = V_137 ;
else
V_87 = V_138 ;
if ( V_20 & V_139 )
F_62 ( V_40 ,
F_63 ( V_76 ,
0 ,
V_140 ,
V_141 ,
V_87 ) ,
V_2 -> V_118 ) ;
if ( V_20 & V_142 )
F_62 ( V_40 ,
F_63 ( V_76 ,
0 ,
V_143 ,
V_141 ,
V_87 ) ,
V_2 -> V_118 ) ;
if ( V_20 & V_144 )
F_62 ( V_40 ,
F_63 ( V_76 ,
0 ,
V_145 ,
V_141 ,
V_87 ) ,
V_2 -> V_118 ) ;
return V_10 ;
}
static T_8 F_64 ( int V_112 , void * V_146 )
{
struct V_39 * V_40 = V_146 ;
struct V_1 * V_2 = F_35 ( V_40 ) ;
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
bool V_147 = false ;
int V_10 ;
F_26 ( & V_2 -> V_62 ) ;
if ( V_2 -> V_104 ) {
V_10 = F_50 ( V_40 ,
V_105 , true ) ;
if ( V_10 > 0 )
V_147 = true ;
}
if ( V_2 -> V_91 ) {
V_10 = F_61 ( V_40 ) ;
if ( V_10 > 0 )
V_147 = true ;
}
if ( V_147 ) {
V_10 = F_5 ( V_2 -> V_8 , V_130 ,
V_131 |
V_132 ) ;
if ( V_10 )
F_6 ( V_7 , L_15 ) ;
V_10 = V_128 ;
} else {
V_10 = V_148 ;
}
F_28 ( & V_2 -> V_62 ) ;
return V_10 ;
}
static T_8 F_65 ( int V_112 , void * V_146 )
{
struct V_39 * V_40 = V_146 ;
struct V_1 * V_2 = F_35 ( V_40 ) ;
bool V_147 = false ;
int V_9 ;
V_2 -> V_117 = V_2 -> V_118 ;
V_2 -> V_118 = F_51 () ;
for ( V_9 = 0 ; V_9 < V_96 ; V_9 ++ ) {
if ( V_2 -> V_97 [ V_9 ] . V_133 ) {
F_66 ( V_2 -> V_97 [ V_9 ] . V_98 ) ;
V_147 = true ;
break;
}
}
if ( V_2 -> V_91 || V_2 -> V_104 )
return V_149 ;
if ( V_147 )
return V_128 ;
return V_148 ;
}
static void F_67 ( struct V_1 * V_2 ,
int V_150 )
{
int V_9 ;
for ( V_9 = V_150 ; V_9 >= 0 ; V_9 -- ) {
if ( V_2 -> V_97 [ V_9 ] . V_98 ) {
F_68 ( V_2 -> V_97 [ V_9 ] . V_98 ) ;
V_2 -> V_97 [ V_9 ] . V_98 = NULL ;
}
}
}
static int F_69 ( struct V_39 * V_40 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < V_96 ; V_9 ++ ) {
struct V_31 * V_32 = & V_2 -> V_97 [ V_9 ] ;
V_32 -> V_98 = F_70 ( V_7 ,
V_151 [ V_9 ] . V_152 ,
V_40 -> V_152 ,
V_40 -> V_153 ) ;
if ( ! V_32 -> V_98 ) {
V_10 = - V_154 ;
break;
}
V_32 -> V_98 -> V_7 . V_155 = V_7 ;
V_32 -> V_98 -> V_156 = & V_157 ;
V_32 -> V_46 = V_151 [ V_9 ] . V_46 ;
V_32 -> V_2 = V_2 ;
V_32 -> V_134 = V_151 [ V_9 ] . V_134 ;
F_71 ( V_32 -> V_98 , V_32 ) ;
V_10 = F_72 ( V_32 -> V_98 ) ;
if ( V_10 )
break;
}
if ( V_10 )
F_67 ( V_2 , V_9 - 1 ) ;
return V_10 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
T_1 V_158 = V_159 ;
int V_10 ;
V_10 = F_5 ( V_2 -> V_8 , V_158 , V_2 -> V_104 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_17 ) ;
return V_10 ;
}
if ( ! V_2 -> V_104 )
return 0 ;
V_10 = F_5 ( V_2 -> V_8 , V_160 ,
V_2 -> V_103 ) ;
if ( V_10 < 0 )
F_6 ( V_7 , L_18 ) ;
return V_10 ;
}
static int F_74 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
return F_13 ( V_2 , true ) ;
}
static int F_75 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
int V_10 = 0 ;
if ( V_40 -> V_161 == V_162 )
return F_76 ( V_40 ) ;
F_26 ( & V_2 -> V_62 ) ;
if ( ! V_2 -> V_103 )
goto V_163;
V_10 = F_19 ( V_2 , V_164 ,
true ) ;
if ( V_10 )
goto V_163;
V_2 -> V_104 = V_165 ;
V_10 = F_73 ( V_2 ) ;
if ( V_10 ) {
V_2 -> V_104 = 0 ;
F_19 ( V_2 , V_164 ,
false ) ;
}
V_163:
F_28 ( & V_2 -> V_62 ) ;
return V_10 ;
}
static int F_77 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
if ( V_40 -> V_161 == V_162 )
return F_78 ( V_40 ) ;
F_26 ( & V_2 -> V_62 ) ;
if ( ! V_2 -> V_104 )
goto V_163;
F_19 ( V_2 , V_164 , false ) ;
F_50 ( V_40 , V_105 , false ) ;
V_2 -> V_104 = 0 ;
F_73 ( V_2 ) ;
V_163:
F_28 ( & V_2 -> V_62 ) ;
return 0 ;
}
static int F_79 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_35 ( V_40 ) ;
return F_13 ( V_2 , false ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
int V_10 , V_9 ;
unsigned int V_20 ;
V_10 = F_27 ( V_2 -> V_8 , V_166 , & V_20 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_19 ) ;
return V_10 ;
}
F_4 ( V_7 , L_20 , V_20 ) ;
for ( V_9 = 0 ; V_9 < F_3 ( V_167 ) ; V_9 ++ ) {
if ( V_167 [ V_9 ] . V_168 == V_20 ) {
V_2 -> V_55 = & V_167 [ V_9 ] ;
break;
}
}
if ( ! V_2 -> V_55 ) {
F_6 ( V_7 , L_21 , V_20 ) ;
return - V_169 ;
}
V_10 = F_1 ( V_2 , V_170 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_7 ( V_2 , V_171 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( V_2 -> V_8 , V_58 ,
V_172 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_22 ) ;
return V_10 ;
}
V_2 -> V_60 = V_172 ;
V_2 -> V_26 = V_173 ;
V_2 -> V_29 = V_174 ;
V_10 = F_8 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_5 ( V_2 -> V_8 , V_130 ,
V_131 |
V_132 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_15 ) ;
return V_10 ;
}
return 0 ;
}
int F_81 ( struct V_6 * V_7 , struct V_8 * V_8 , int V_112 ,
const char * V_152 , bool V_175 )
{
struct V_1 * V_2 ;
struct V_39 * V_40 ;
int V_10 ;
V_40 = F_82 ( V_7 , sizeof( * V_2 ) ) ;
if ( ! V_40 )
return - V_154 ;
V_2 = F_35 ( V_40 ) ;
F_83 ( V_7 , V_40 ) ;
V_2 -> V_112 = V_112 ;
V_2 -> V_8 = V_8 ;
V_10 = F_80 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
F_84 ( & V_2 -> V_62 ) ;
V_40 -> V_7 . V_155 = V_7 ;
V_40 -> V_176 = V_2 -> V_55 -> V_176 ;
V_40 -> V_177 = V_2 -> V_55 -> V_177 ;
V_40 -> V_152 = V_152 ? V_152 : V_2 -> V_55 -> V_152 ;
V_40 -> V_178 = V_179 ;
V_40 -> V_180 = V_181 ;
V_40 -> V_43 = & V_182 ;
V_10 = F_85 ( V_40 ,
& V_183 ,
F_56 ,
& V_184 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_23 ) ;
return V_10 ;
}
if ( V_2 -> V_112 > 0 ) {
V_10 = F_86 (
V_7 , V_2 -> V_112 ,
F_65 ,
F_64 ,
V_185 ,
V_186 ,
V_40 ) ;
if ( V_10 )
goto V_187;
V_10 = F_5 ( V_2 -> V_8 , V_130 ,
V_132 ) ;
if ( V_10 < 0 ) {
F_6 ( V_7 , L_15 ) ;
goto V_187;
}
F_18 ( V_40 , V_2 ) ;
V_10 = F_69 ( V_40 , V_2 ) ;
if ( V_10 )
goto V_187;
if ( V_175 ) {
V_40 -> V_180 |= V_188 ;
V_40 -> V_43 = & V_189 ;
V_40 -> V_106 -> V_190 = V_191 ;
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
F_67 ( V_2 , V_96 - 1 ) ;
V_187:
F_92 ( V_40 ) ;
return V_10 ;
}
int F_93 ( struct V_6 * V_7 )
{
struct V_39 * V_40 = F_94 ( V_7 ) ;
struct V_1 * V_2 = F_35 ( V_40 ) ;
F_95 ( V_40 ) ;
F_96 ( V_7 ) ;
F_97 ( V_7 ) ;
F_17 ( V_7 ) ;
F_67 ( V_2 , V_96 - 1 ) ;
F_92 ( V_40 ) ;
F_26 ( & V_2 -> V_62 ) ;
F_1 ( V_2 , V_194 , 0 ) ;
F_28 ( & V_2 -> V_62 ) ;
return 0 ;
}
static int F_98 ( struct V_6 * V_7 )
{
struct V_39 * V_40 = F_94 ( V_7 ) ;
struct V_1 * V_2 = F_35 ( V_40 ) ;
F_26 ( & V_2 -> V_62 ) ;
F_1 ( V_2 , V_195 , 0 ) ;
F_28 ( & V_2 -> V_62 ) ;
return 0 ;
}
static int F_99 ( struct V_6 * V_7 )
{
struct V_39 * V_40 = F_94 ( V_7 ) ;
struct V_1 * V_2 = F_35 ( V_40 ) ;
F_26 ( & V_2 -> V_62 ) ;
if ( F_100 ( & V_2 -> V_54 ) )
F_1 ( V_2 , V_170 , 0 ) ;
F_73 ( V_2 ) ;
F_28 ( & V_2 -> V_62 ) ;
return 0 ;
}
static int F_101 ( struct V_6 * V_7 )
{
struct V_39 * V_40 = F_94 ( V_7 ) ;
struct V_1 * V_2 = F_35 ( V_40 ) ;
int V_10 ;
F_4 ( V_7 , V_30 ) ;
V_10 = F_1 ( V_2 , V_195 , 0 ) ;
if ( V_10 < 0 )
return - V_196 ;
return 0 ;
}
static int F_102 ( struct V_6 * V_7 )
{
struct V_39 * V_40 = F_94 ( V_7 ) ;
struct V_1 * V_2 = F_35 ( V_40 ) ;
int V_10 ;
int V_197 ;
F_4 ( V_7 , V_30 ) ;
V_10 = F_1 ( V_2 , V_170 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_73 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_197 = F_12 ( V_2 ) ;
if ( V_197 < 20 )
F_103 ( V_197 * 1000 , 20000 ) ;
else
F_104 ( V_197 ) ;
return 0 ;
}
