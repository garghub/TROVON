static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 , T_1 * args , int V_7 ,
unsigned char * V_8 , int V_9 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
union V_4 * V_12 = (union V_4 * ) V_11 -> V_13 ;
int V_14 ;
struct V_15 V_16 [ 2 ] ;
int V_17 = 1 ;
int V_18 = V_4 -> V_18 ;
bool V_19 = V_4 -> V_19 ;
unsigned int V_20 = V_4 -> V_20 ;
if ( V_4 == & V_21 ) {
V_12 -> V_22 . V_23 = V_11 -> V_24 ;
} else {
V_12 -> V_25 [ 0 ] = V_11 -> V_26 [ V_20 ] ;
V_12 -> V_25 [ 1 ] = V_11 -> V_26 [ V_20 + 1 ] ;
}
if ( V_18 > 2 ) {
V_12 -> V_22 . V_27 = V_4 -> V_27 ;
V_12 -> V_22 . V_28 = V_5 | V_6 << 4 ;
}
memcpy ( V_12 -> V_25 + V_18 , args , V_7 ) ;
V_18 += V_7 ;
F_3 ( V_11 , L_1 , V_29 , V_18 , V_12 -> V_25 ) ;
V_16 [ 0 ] . V_30 = V_2 -> V_30 ;
V_16 [ 0 ] . V_31 = V_2 -> V_31 & V_32 ;
V_16 [ 0 ] . V_33 = V_18 ;
V_16 [ 0 ] . V_34 = V_12 -> V_25 ;
if ( V_9 > 0 ) {
V_16 [ 1 ] . V_30 = V_2 -> V_30 ;
V_16 [ 1 ] . V_31 = V_2 -> V_31 & V_32 ;
V_16 [ 1 ] . V_31 |= V_35 ;
V_16 [ 1 ] . V_33 = V_9 ;
V_16 [ 1 ] . V_34 = V_8 ;
V_17 = 2 ;
F_4 ( V_36 , & V_11 -> V_31 ) ;
}
if ( V_19 )
F_4 ( V_37 , & V_11 -> V_31 ) ;
V_14 = F_5 ( V_2 -> V_38 , V_16 , V_17 ) ;
if ( V_9 > 0 )
F_6 ( V_36 , & V_11 -> V_31 ) ;
if ( V_14 != V_17 )
return V_14 < 0 ? V_14 : - V_39 ;
V_14 = 0 ;
if ( V_19 ) {
F_3 ( V_11 , L_2 , V_29 ) ;
if ( ! F_7 ( V_11 -> V_19 ,
! F_8 ( V_37 , & V_11 -> V_31 ) ,
F_9 ( 5000 ) ) )
V_14 = - V_40 ;
F_3 ( V_11 , L_3 , V_29 ) ;
}
return V_14 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned char * V_8 , int V_9 )
{
return F_1 ( V_2 , V_4 , 0 , 0 , NULL , 0 ,
V_8 , V_9 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_5 , unsigned char * V_8 , int V_9 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_1 args [ 3 ] ;
int V_14 ;
int V_7 = 0 ;
T_2 V_41 = F_12 ( V_11 -> V_42 . V_43 ) ;
F_3 ( V_11 , L_4 , V_29 ) ;
if ( V_5 >= 0x0F ) {
args [ V_7 ++ ] = V_5 ;
V_5 = 0x0F ;
}
args [ V_7 ++ ] = V_41 & 0xFF ;
args [ V_7 ++ ] = V_41 >> 8 ;
V_14 = F_1 ( V_2 , & V_44 , V_5 ,
V_6 , args , V_7 , V_8 , V_9 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 ,
L_5 ) ;
return V_14 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_5 , unsigned char * V_34 , T_3 V_9 , bool V_46 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_1 * args = V_11 -> V_47 ;
const struct V_3 * V_48 ;
int V_14 ;
T_2 V_49 = F_12 ( V_11 -> V_42 . V_43 ) ;
T_2 V_50 = F_12 ( V_11 -> V_42 . V_51 ) ;
T_2 V_52 = F_12 ( V_11 -> V_42 . V_53 ) ;
T_2 V_54 = 2 +
( V_5 ? 1 : 0 ) +
V_9 ;
int V_7 = ( V_5 >= 0x0F ? 1 : 0 ) +
2 +
V_54 ;
int V_55 = 0 ;
F_3 ( V_11 , L_4 , V_29 ) ;
if ( ! V_46 && V_52 == 0 )
return - V_56 ;
if ( V_5 >= 0x0F ) {
args [ V_55 ++ ] = V_5 ;
V_5 = 0x0F ;
}
if ( V_46 ) {
args [ V_55 ++ ] = V_49 & 0xFF ;
args [ V_55 ++ ] = V_49 >> 8 ;
V_48 = & V_57 ;
} else {
args [ V_55 ++ ] = V_50 & 0xFF ;
args [ V_55 ++ ] = V_50 >> 8 ;
V_48 = & V_58 ;
}
args [ V_55 ++ ] = V_54 & 0xFF ;
args [ V_55 ++ ] = V_54 >> 8 ;
if ( V_5 )
args [ V_55 ++ ] = V_5 ;
memcpy ( & args [ V_55 ] , V_34 , V_9 ) ;
V_14 = F_1 ( V_2 , V_48 , V_5 ,
V_6 , args , V_7 , NULL , 0 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_6 ) ;
return V_14 ;
}
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 , int V_59 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
F_3 ( V_11 , L_4 , V_29 ) ;
V_14 = F_1 ( V_2 , & V_60 , V_59 ,
0 , NULL , 0 , NULL , 0 ) ;
if ( V_14 )
F_13 ( & V_2 -> V_45 , L_7 ) ;
return V_14 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
F_3 ( V_11 , L_4 , V_29 ) ;
F_17 ( & V_11 -> V_61 ) ;
V_14 = F_15 ( V_2 , V_62 ) ;
if ( V_14 )
goto V_63;
F_3 ( V_11 , L_8 ) ;
V_14 = F_10 ( V_2 , & V_64 , NULL , 0 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_9 ) ;
F_15 ( V_2 , V_65 ) ;
}
V_63:
F_18 ( & V_11 -> V_61 ) ;
return V_14 ;
}
static void F_19 ( struct V_10 * V_11 )
{
int V_14 , V_66 ;
int V_54 = F_12 ( V_11 -> V_42 . V_67 ) ;
if ( V_54 > V_11 -> V_68 )
V_54 = V_11 -> V_68 ;
V_14 = F_20 ( V_11 -> V_2 , V_11 -> V_69 , V_54 ) ;
if ( V_14 != V_54 ) {
if ( V_14 < 0 )
return;
F_13 ( & V_11 -> V_2 -> V_45 , L_10 ,
V_29 , V_14 , V_54 ) ;
return;
}
V_66 = V_11 -> V_69 [ 0 ] | V_11 -> V_69 [ 1 ] << 8 ;
if ( ! V_66 ) {
if ( F_21 ( V_37 , & V_11 -> V_31 ) )
F_22 ( & V_11 -> V_19 ) ;
return;
}
if ( V_66 > V_54 ) {
F_13 ( & V_11 -> V_2 -> V_45 , L_11 ,
V_29 , V_54 , V_66 ) ;
return;
}
F_3 ( V_11 , L_12 , V_66 , V_11 -> V_69 ) ;
if ( F_8 ( V_70 , & V_11 -> V_31 ) )
F_23 ( V_11 -> V_71 , V_72 , V_11 -> V_69 + 2 ,
V_66 - 2 , 1 ) ;
return;
}
static T_4 F_24 ( int V_73 , void * V_74 )
{
struct V_10 * V_11 = V_74 ;
if ( F_8 ( V_36 , & V_11 -> V_31 ) )
return V_75 ;
F_19 ( V_11 ) ;
return V_75 ;
}
static int F_25 ( struct V_76 * V_77 )
{
return ( ( V_77 -> V_54 - 1 ) >> 3 ) + 1 +
V_77 -> V_78 -> V_79 [ V_77 -> type ] . V_80 + 2 ;
}
static void F_26 ( struct V_76 * V_77 , T_1 * V_81 ,
T_3 V_68 )
{
struct V_82 * V_71 = V_77 -> V_78 ;
struct V_1 * V_2 = V_71 -> V_83 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
unsigned int V_54 , V_66 ;
V_54 = F_25 ( V_77 ) ;
if ( F_11 ( V_2 ,
V_77 -> type == V_84 ? 0x03 : 0x01 ,
V_77 -> V_85 , V_81 , V_54 ) )
return;
F_3 ( V_11 , L_13 , V_54 , V_54 , V_81 ) ;
V_66 = V_81 [ 0 ] | ( V_81 [ 1 ] << 8 ) ;
if ( V_66 != V_54 ) {
F_13 ( & V_2 -> V_45 , L_14 ,
V_29 , V_54 , V_66 ) ;
return;
}
F_27 ( V_71 , V_77 -> type , V_81 + 2 , V_54 - 2 , 1 ) ;
}
static void F_28 ( struct V_82 * V_71 )
{
struct V_76 * V_77 ;
struct V_1 * V_2 = V_71 -> V_83 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_1 * V_69 = F_29 ( V_11 -> V_68 , V_86 ) ;
if ( ! V_69 ) {
F_13 ( & V_2 -> V_45 , L_15 ) ;
return;
}
F_30 ( & V_2 -> V_45 ) ;
F_31 (report,
&hid->report_enum[HID_FEATURE_REPORT].report_list, list)
F_26 ( V_77 , V_69 , V_11 -> V_68 ) ;
F_32 ( & V_2 -> V_45 ) ;
F_33 ( V_69 ) ;
}
static void F_34 ( struct V_82 * V_71 , unsigned int type ,
unsigned int * V_87 )
{
struct V_76 * V_77 ;
unsigned int V_54 ;
F_31 (report, &hid->report_enum[type].report_list, list) {
V_54 = F_25 ( V_77 ) ;
if ( * V_87 < V_54 )
* V_87 = V_54 ;
}
}
static void F_35 ( struct V_10 * V_11 )
{
F_33 ( V_11 -> V_69 ) ;
F_33 ( V_11 -> V_88 ) ;
F_33 ( V_11 -> V_47 ) ;
F_33 ( V_11 -> V_13 ) ;
V_11 -> V_69 = NULL ;
V_11 -> V_88 = NULL ;
V_11 -> V_13 = NULL ;
V_11 -> V_47 = NULL ;
V_11 -> V_68 = 0 ;
}
static int F_36 ( struct V_10 * V_11 , T_3 V_89 )
{
int V_7 = sizeof( V_90 ) +
sizeof( V_91 ) +
sizeof( V_91 ) +
V_89 ;
V_11 -> V_69 = F_29 ( V_89 , V_86 ) ;
V_11 -> V_88 = F_29 ( V_89 , V_86 ) ;
V_11 -> V_47 = F_29 ( V_7 , V_86 ) ;
V_11 -> V_13 = F_29 ( sizeof( union V_4 ) + V_7 , V_86 ) ;
if ( ! V_11 -> V_69 || ! V_11 -> V_88 || ! V_11 -> V_47 || ! V_11 -> V_13 ) {
F_35 ( V_11 ) ;
return - V_92 ;
}
V_11 -> V_68 = V_89 ;
return 0 ;
}
static int F_37 ( struct V_82 * V_71 ,
unsigned char V_93 , V_90 * V_34 , T_3 V_94 ,
unsigned char V_95 )
{
struct V_1 * V_2 = V_71 -> V_83 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_3 V_96 , V_97 ;
int V_14 ;
if ( V_95 == V_98 )
return - V_99 ;
V_97 = F_38 ( V_94 + 2 , ( T_3 ) V_11 -> V_68 ) ;
V_14 = F_11 ( V_2 ,
V_95 == V_84 ? 0x03 : 0x01 ,
V_93 , V_11 -> V_88 , V_97 ) ;
if ( V_14 < 0 )
return V_14 ;
V_96 = V_11 -> V_88 [ 0 ] | ( V_11 -> V_88 [ 1 ] << 8 ) ;
if ( V_96 <= 2 )
return 0 ;
V_96 = F_38 ( V_96 , V_97 ) ;
V_94 = F_38 ( V_94 , V_96 - 2 ) ;
memcpy ( V_34 , V_11 -> V_88 + 2 , V_94 ) ;
return V_94 ;
}
static int F_39 ( struct V_82 * V_71 , V_90 * V_34 ,
T_3 V_94 , unsigned char V_95 , bool V_46 )
{
struct V_1 * V_2 = V_71 -> V_83 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_100 = V_34 [ 0 ] ;
int V_14 ;
if ( V_95 == V_72 )
return - V_99 ;
F_17 ( & V_11 -> V_61 ) ;
if ( V_100 ) {
V_34 ++ ;
V_94 -- ;
}
V_14 = F_14 ( V_2 ,
V_95 == V_84 ? 0x03 : 0x02 ,
V_100 , V_34 , V_94 , V_46 ) ;
if ( V_100 && V_14 >= 0 )
V_14 ++ ;
F_18 ( & V_11 -> V_61 ) ;
return V_14 ;
}
static int F_40 ( struct V_82 * V_71 , V_90 * V_34 ,
T_3 V_94 )
{
return F_39 ( V_71 , V_34 , V_94 , V_98 ,
false ) ;
}
static int F_41 ( struct V_82 * V_71 , unsigned char V_101 ,
V_90 * V_34 , T_3 V_33 , unsigned char V_102 ,
int V_103 )
{
switch ( V_103 ) {
case V_104 :
return F_37 ( V_71 , V_101 , V_34 , V_33 , V_102 ) ;
case V_105 :
if ( V_34 [ 0 ] != V_101 )
return - V_99 ;
return F_39 ( V_71 , V_34 , V_33 , V_102 , true ) ;
default:
return - V_39 ;
}
}
static int F_42 ( struct V_82 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_83 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_106 * V_42 = & V_11 -> V_42 ;
unsigned int V_107 ;
char * V_108 ;
int V_14 ;
int V_109 = 3 ;
F_3 ( V_11 , L_16 , V_29 ) ;
V_107 = F_12 ( V_42 -> V_110 ) ;
if ( ! V_107 || V_107 > V_111 ) {
F_43 ( L_17 , V_107 ) ;
return - V_99 ;
}
do {
V_14 = F_16 ( V_2 ) ;
if ( V_14 )
F_44 ( 1000 ) ;
} while ( V_109 -- > 0 && V_14 );
if ( V_14 )
return V_14 ;
V_108 = F_29 ( V_107 , V_86 ) ;
if ( ! V_108 ) {
F_43 ( L_18 ) ;
return - V_92 ;
}
F_3 ( V_11 , L_19 ) ;
V_14 = F_10 ( V_2 , & V_112 , V_108 , V_107 ) ;
if ( V_14 ) {
F_45 ( V_71 , L_20 ) ;
F_33 ( V_108 ) ;
return - V_39 ;
}
F_3 ( V_11 , L_21 , V_107 , V_108 ) ;
V_14 = F_46 ( V_71 , V_108 , V_107 ) ;
F_33 ( V_108 ) ;
if ( V_14 ) {
F_43 ( L_22 ) ;
return V_14 ;
}
return 0 ;
}
static int F_47 ( struct V_82 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_83 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
unsigned int V_68 = V_113 ;
F_34 ( V_71 , V_72 , & V_68 ) ;
F_34 ( V_71 , V_98 , & V_68 ) ;
F_34 ( V_71 , V_84 , & V_68 ) ;
if ( V_68 > V_11 -> V_68 ) {
F_35 ( V_11 ) ;
V_14 = F_36 ( V_11 , V_68 ) ;
if ( V_14 )
return V_14 ;
}
if ( ! ( V_71 -> V_114 & V_115 ) )
F_28 ( V_71 ) ;
return 0 ;
}
static void F_48 ( struct V_82 * V_71 )
{
V_71 -> V_116 = 0 ;
}
static int F_49 ( struct V_82 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_83 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 = 0 ;
F_17 ( & V_117 ) ;
if ( ! V_71 -> V_118 ++ ) {
V_14 = F_30 ( & V_2 -> V_45 ) ;
if ( V_14 < 0 ) {
V_71 -> V_118 -- ;
goto V_119;
}
F_4 ( V_70 , & V_11 -> V_31 ) ;
}
V_119:
F_18 ( & V_117 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static void F_50 ( struct V_82 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_83 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_17 ( & V_117 ) ;
if ( ! -- V_71 -> V_118 ) {
F_6 ( V_70 , & V_11 -> V_31 ) ;
F_32 ( & V_2 -> V_45 ) ;
}
F_18 ( & V_117 ) ;
}
static int F_51 ( struct V_82 * V_71 , int V_120 )
{
struct V_1 * V_2 = V_71 -> V_83 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_3 ( V_11 , L_23 , V_29 , V_120 ) ;
switch ( V_120 ) {
case V_121 :
F_30 ( & V_2 -> V_45 ) ;
break;
case V_122 :
F_32 ( & V_2 -> V_45 ) ;
break;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
F_53 ( & V_2 -> V_45 , L_24 , V_11 -> V_73 ) ;
V_14 = F_54 ( V_11 -> V_73 , NULL , F_24 ,
V_123 | V_124 ,
V_2 -> V_125 , V_11 ) ;
if ( V_14 < 0 ) {
F_55 ( & V_2 -> V_45 ,
L_25
L_26 ,
V_2 -> V_125 , V_11 -> V_73 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_56 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_106 * V_42 = & V_11 -> V_42 ;
unsigned int V_126 ;
int V_14 ;
F_3 ( V_11 , L_27 ) ;
V_14 = F_10 ( V_2 , & V_21 , V_11 -> V_26 ,
sizeof( struct V_106 ) ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_28 ) ;
return - V_127 ;
}
if ( F_12 ( V_42 -> V_128 ) != 0x0100 ) {
F_13 ( & V_2 -> V_45 ,
L_29 ,
F_12 ( V_42 -> V_128 ) ) ;
return - V_127 ;
}
V_126 = F_12 ( V_42 -> V_129 ) ;
if ( V_126 != sizeof( struct V_106 ) ) {
F_13 ( & V_2 -> V_45 , L_30 ,
V_126 ) ;
return - V_127 ;
}
F_3 ( V_11 , L_31 , V_126 , V_11 -> V_26 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
static T_1 V_132 [] = {
0xF7 , 0xF6 , 0xDF , 0x3C , 0x67 , 0x42 , 0x55 , 0x45 ,
0xAD , 0x05 , 0xB3 , 0x0A , 0x3D , 0x89 , 0x38 , 0xDE ,
} ;
union V_133 * V_134 ;
struct V_135 * V_136 ;
T_5 V_137 ;
int V_14 ;
V_137 = F_58 ( & V_2 -> V_45 ) ;
if ( ! V_137 || F_59 ( V_137 , & V_136 ) )
return - V_127 ;
V_134 = F_60 ( V_137 , V_132 , 1 , 1 , NULL ,
V_138 ) ;
if ( ! V_134 ) {
F_13 ( & V_2 -> V_45 , L_32 ) ;
return - V_127 ;
}
V_131 -> V_139 = V_134 -> integer . V_140 ;
F_61 ( V_134 ) ;
V_14 = F_62 ( V_136 , V_141 ) ;
return V_14 < 0 && V_14 != - V_142 ? V_14 : 0 ;
}
static inline int F_57 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
return - V_127 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
struct V_78 * V_45 = & V_2 -> V_45 ;
T_6 V_143 ;
int V_14 ;
V_14 = F_64 ( V_45 -> V_144 , L_33 , & V_143 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_34 ) ;
return - V_127 ;
}
if ( V_143 >> 16 ) {
F_13 ( & V_2 -> V_45 , L_35 ,
V_143 ) ;
return - V_99 ;
}
V_131 -> V_139 = V_143 ;
return 0 ;
}
static inline int F_63 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
return - V_127 ;
}
static int F_65 ( struct V_1 * V_2 ,
const struct V_145 * V_74 )
{
int V_14 ;
struct V_10 * V_11 ;
struct V_82 * V_71 ;
V_91 V_146 ;
struct V_130 * V_147 = V_2 -> V_45 . V_147 ;
F_43 ( L_36 , V_2 -> V_30 ) ;
V_11 = F_29 ( sizeof( struct V_10 ) , V_86 ) ;
if ( ! V_11 )
return - V_92 ;
if ( V_2 -> V_45 . V_144 ) {
V_14 = F_63 ( V_2 , & V_11 -> V_131 ) ;
if ( V_14 )
goto V_148;
} else if ( ! V_147 ) {
V_14 = F_57 ( V_2 , & V_11 -> V_131 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 ,
L_34 ) ;
goto V_148;
}
} else {
V_11 -> V_131 = * V_147 ;
}
if ( V_2 -> V_73 > 0 ) {
V_11 -> V_73 = V_2 -> V_73 ;
} else if ( F_66 ( & V_2 -> V_45 ) ) {
V_11 -> V_149 = F_67 ( & V_2 -> V_45 , NULL , V_150 ) ;
if ( F_68 ( V_11 -> V_149 ) ) {
F_13 ( & V_2 -> V_45 , L_37 ) ;
return F_69 ( V_11 -> V_149 ) ;
}
V_11 -> V_73 = F_70 ( V_11 -> V_149 ) ;
if ( V_11 -> V_73 < 0 ) {
F_71 ( V_11 -> V_149 ) ;
F_13 ( & V_2 -> V_45 , L_38 ) ;
return V_11 -> V_73 ;
}
}
F_72 ( V_2 , V_11 ) ;
V_11 -> V_2 = V_2 ;
V_146 = V_11 -> V_131 . V_139 ;
V_11 -> V_24 = F_73 ( V_146 ) ;
F_74 ( & V_11 -> V_19 ) ;
F_75 ( & V_11 -> V_61 ) ;
V_14 = F_36 ( V_11 , V_113 ) ;
if ( V_14 < 0 )
goto V_148;
F_76 ( & V_2 -> V_45 ) ;
F_77 ( & V_2 -> V_45 ) ;
F_78 ( & V_2 -> V_45 ) ;
V_14 = F_56 ( V_11 ) ;
if ( V_14 < 0 )
goto V_151;
V_14 = F_52 ( V_2 ) ;
if ( V_14 < 0 )
goto V_151;
V_71 = F_79 () ;
if ( F_68 ( V_71 ) ) {
V_14 = F_69 ( V_71 ) ;
goto V_152;
}
V_11 -> V_71 = V_71 ;
V_71 -> V_83 = V_2 ;
V_71 -> V_153 = & V_154 ;
V_71 -> V_45 . V_155 = & V_2 -> V_45 ;
V_71 -> V_156 = V_157 ;
V_71 -> V_158 = F_12 ( V_11 -> V_42 . V_128 ) ;
V_71 -> V_159 = F_12 ( V_11 -> V_42 . V_160 ) ;
V_71 -> V_161 = F_12 ( V_11 -> V_42 . V_162 ) ;
snprintf ( V_71 -> V_125 , sizeof( V_71 -> V_125 ) , L_39 ,
V_2 -> V_125 , V_71 -> V_159 , V_71 -> V_161 ) ;
F_80 ( V_71 -> V_163 , F_81 ( & V_2 -> V_45 ) , sizeof( V_71 -> V_163 ) ) ;
V_14 = F_82 ( V_71 ) ;
if ( V_14 ) {
if ( V_14 != - V_127 )
F_45 ( V_2 , L_40 , V_14 ) ;
goto V_164;
}
F_32 ( & V_2 -> V_45 ) ;
return 0 ;
V_164:
F_83 ( V_71 ) ;
V_152:
F_84 ( V_11 -> V_73 , V_11 ) ;
V_151:
F_85 ( & V_2 -> V_45 ) ;
F_86 ( & V_2 -> V_45 ) ;
V_148:
if ( V_11 -> V_149 )
F_71 ( V_11 -> V_149 ) ;
F_35 ( V_11 ) ;
F_33 ( V_11 ) ;
return V_14 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_82 * V_71 ;
F_30 ( & V_2 -> V_45 ) ;
F_86 ( & V_2 -> V_45 ) ;
F_88 ( & V_2 -> V_45 ) ;
F_85 ( & V_2 -> V_45 ) ;
V_71 = V_11 -> V_71 ;
F_83 ( V_71 ) ;
F_84 ( V_11 -> V_73 , V_11 ) ;
if ( V_11 -> V_68 )
F_35 ( V_11 ) ;
if ( V_11 -> V_149 )
F_71 ( V_11 -> V_149 ) ;
F_33 ( V_11 ) ;
F_89 ( F_66 ( & V_2 -> V_45 ) ) ;
return 0 ;
}
static int F_90 ( struct V_78 * V_45 )
{
struct V_1 * V_2 = F_91 ( V_45 ) ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_82 * V_71 = V_11 -> V_71 ;
int V_14 = 0 ;
int V_165 ;
if ( V_71 -> V_166 && V_71 -> V_166 -> V_167 )
V_14 = V_71 -> V_166 -> V_167 ( V_71 , V_168 ) ;
F_92 ( V_11 -> V_73 ) ;
if ( F_93 ( & V_2 -> V_45 ) ) {
V_165 = F_94 ( V_11 -> V_73 ) ;
if ( ! V_165 )
V_11 -> V_169 = true ;
else
F_95 ( V_71 , L_41 ,
V_165 ) ;
}
F_15 ( V_2 , V_65 ) ;
return V_14 ;
}
static int F_96 ( struct V_78 * V_45 )
{
int V_14 ;
struct V_1 * V_2 = F_91 ( V_45 ) ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_82 * V_71 = V_11 -> V_71 ;
int V_165 ;
F_97 ( V_11 -> V_73 ) ;
V_14 = F_16 ( V_2 ) ;
if ( V_14 )
return V_14 ;
if ( F_93 ( & V_2 -> V_45 ) && V_11 -> V_169 ) {
V_165 = F_98 ( V_11 -> V_73 ) ;
if ( ! V_165 )
V_11 -> V_169 = false ;
else
F_95 ( V_71 , L_42 ,
V_165 ) ;
}
if ( V_71 -> V_166 && V_71 -> V_166 -> V_170 ) {
V_14 = V_71 -> V_166 -> V_170 ( V_71 ) ;
return V_14 ;
}
return 0 ;
}
static int F_99 ( struct V_78 * V_45 )
{
struct V_1 * V_2 = F_91 ( V_45 ) ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_15 ( V_2 , V_65 ) ;
F_92 ( V_11 -> V_73 ) ;
return 0 ;
}
static int F_100 ( struct V_78 * V_45 )
{
struct V_1 * V_2 = F_91 ( V_45 ) ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_97 ( V_11 -> V_73 ) ;
F_15 ( V_2 , V_62 ) ;
return 0 ;
}
