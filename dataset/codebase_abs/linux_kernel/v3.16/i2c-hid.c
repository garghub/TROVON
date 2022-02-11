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
V_14 = F_15 ( V_2 , V_61 ) ;
if ( V_14 )
return V_14 ;
F_3 ( V_11 , L_8 ) ;
V_14 = F_10 ( V_2 , & V_62 , NULL , 0 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_9 ) ;
F_15 ( V_2 , V_63 ) ;
return V_14 ;
}
return 0 ;
}
static void F_17 ( struct V_10 * V_11 )
{
int V_14 , V_64 ;
int V_54 = F_12 ( V_11 -> V_42 . V_65 ) ;
V_14 = F_18 ( V_11 -> V_2 , V_11 -> V_66 , V_54 ) ;
if ( V_14 != V_54 ) {
if ( V_14 < 0 )
return;
F_13 ( & V_11 -> V_2 -> V_45 , L_10 ,
V_29 , V_14 , V_54 ) ;
return;
}
V_64 = V_11 -> V_66 [ 0 ] | V_11 -> V_66 [ 1 ] << 8 ;
if ( ! V_64 ) {
if ( F_19 ( V_37 , & V_11 -> V_31 ) )
F_20 ( & V_11 -> V_19 ) ;
return;
}
if ( V_64 > V_54 ) {
F_13 ( & V_11 -> V_2 -> V_45 , L_11 ,
V_29 , V_54 , V_64 ) ;
return;
}
F_3 ( V_11 , L_12 , V_64 , V_11 -> V_66 ) ;
if ( F_8 ( V_67 , & V_11 -> V_31 ) )
F_21 ( V_11 -> V_68 , V_69 , V_11 -> V_66 + 2 ,
V_64 - 2 , 1 ) ;
return;
}
static T_4 F_22 ( int V_70 , void * V_71 )
{
struct V_10 * V_11 = V_71 ;
if ( F_8 ( V_36 , & V_11 -> V_31 ) )
return V_72 ;
F_17 ( V_11 ) ;
return V_72 ;
}
static int F_23 ( struct V_73 * V_74 )
{
return ( ( V_74 -> V_54 - 1 ) >> 3 ) + 1 +
V_74 -> V_75 -> V_76 [ V_74 -> type ] . V_77 + 2 ;
}
static void F_24 ( struct V_73 * V_74 , T_1 * V_78 ,
T_3 V_79 )
{
struct V_80 * V_68 = V_74 -> V_75 ;
struct V_1 * V_2 = V_68 -> V_81 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
unsigned int V_54 , V_64 ;
V_54 = F_23 ( V_74 ) ;
if ( F_11 ( V_2 ,
V_74 -> type == V_82 ? 0x03 : 0x01 ,
V_74 -> V_83 , V_78 , V_54 ) )
return;
F_3 ( V_11 , L_13 , V_54 , V_54 , V_11 -> V_66 ) ;
V_64 = V_78 [ 0 ] | ( V_78 [ 1 ] << 8 ) ;
if ( V_64 != V_54 ) {
F_13 ( & V_2 -> V_45 , L_14 ,
V_29 , V_54 , V_64 ) ;
return;
}
F_25 ( V_68 , V_74 -> type , V_78 + 2 , V_54 - 2 , 1 ) ;
}
static void F_26 ( struct V_80 * V_68 )
{
struct V_73 * V_74 ;
struct V_1 * V_2 = V_68 -> V_81 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_1 * V_66 = F_27 ( V_11 -> V_79 , V_84 ) ;
if ( ! V_66 ) {
F_13 ( & V_2 -> V_45 , L_15 ) ;
return;
}
F_28 ( & V_2 -> V_45 ) ;
F_29 (report,
&hid->report_enum[HID_FEATURE_REPORT].report_list, list)
F_24 ( V_74 , V_66 , V_11 -> V_79 ) ;
F_30 ( & V_2 -> V_45 ) ;
F_31 ( V_66 ) ;
}
static void F_32 ( struct V_80 * V_68 , unsigned int type ,
unsigned int * V_85 )
{
struct V_73 * V_74 ;
unsigned int V_54 ;
F_29 (report, &hid->report_enum[type].report_list, list) {
V_54 = F_23 ( V_74 ) ;
if ( * V_85 < V_54 )
* V_85 = V_54 ;
}
}
static void F_33 ( struct V_10 * V_11 )
{
F_31 ( V_11 -> V_66 ) ;
F_31 ( V_11 -> V_47 ) ;
F_31 ( V_11 -> V_13 ) ;
V_11 -> V_66 = NULL ;
V_11 -> V_13 = NULL ;
V_11 -> V_47 = NULL ;
V_11 -> V_79 = 0 ;
}
static int F_34 ( struct V_10 * V_11 , T_3 V_86 )
{
int V_7 = sizeof( V_87 ) +
sizeof( V_88 ) +
sizeof( V_88 ) +
V_86 ;
V_11 -> V_66 = F_27 ( V_86 , V_84 ) ;
V_11 -> V_47 = F_27 ( V_7 , V_84 ) ;
V_11 -> V_13 = F_27 ( sizeof( union V_4 ) + V_7 , V_84 ) ;
if ( ! V_11 -> V_66 || ! V_11 -> V_47 || ! V_11 -> V_13 ) {
F_33 ( V_11 ) ;
return - V_89 ;
}
V_11 -> V_79 = V_86 ;
return 0 ;
}
static int F_35 ( struct V_80 * V_68 ,
unsigned char V_90 , V_87 * V_34 , T_3 V_91 ,
unsigned char V_92 )
{
struct V_1 * V_2 = V_68 -> V_81 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_3 V_93 , V_94 ;
int V_14 ;
if ( V_92 == V_95 )
return - V_96 ;
V_94 = F_36 ( V_91 + 2 , ( T_3 ) V_11 -> V_79 ) ;
V_14 = F_11 ( V_2 ,
V_92 == V_82 ? 0x03 : 0x01 ,
V_90 , V_11 -> V_66 , V_94 ) ;
if ( V_14 < 0 )
return V_14 ;
V_93 = V_11 -> V_66 [ 0 ] | ( V_11 -> V_66 [ 1 ] << 8 ) ;
if ( V_93 <= 2 )
return 0 ;
V_93 = F_36 ( V_93 , V_94 ) ;
V_91 = F_36 ( V_91 , V_93 - 2 ) ;
memcpy ( V_34 , V_11 -> V_66 + 2 , V_91 ) ;
return V_91 ;
}
static int F_37 ( struct V_80 * V_68 , V_87 * V_34 ,
T_3 V_91 , unsigned char V_92 , bool V_46 )
{
struct V_1 * V_2 = V_68 -> V_81 ;
int V_97 = V_34 [ 0 ] ;
int V_14 ;
if ( V_92 == V_69 )
return - V_96 ;
if ( V_97 ) {
V_34 ++ ;
V_91 -- ;
}
V_14 = F_14 ( V_2 ,
V_92 == V_82 ? 0x03 : 0x02 ,
V_97 , V_34 , V_91 , V_46 ) ;
if ( V_97 && V_14 >= 0 )
V_14 ++ ;
return V_14 ;
}
static int F_38 ( struct V_80 * V_68 , V_87 * V_34 ,
T_3 V_91 )
{
return F_37 ( V_68 , V_34 , V_91 , V_95 ,
false ) ;
}
static int F_39 ( struct V_80 * V_68 , unsigned char V_98 ,
V_87 * V_34 , T_3 V_33 , unsigned char V_99 ,
int V_100 )
{
switch ( V_100 ) {
case V_101 :
return F_35 ( V_68 , V_98 , V_34 , V_33 , V_99 ) ;
case V_102 :
if ( V_34 [ 0 ] != V_98 )
return - V_96 ;
return F_37 ( V_68 , V_34 , V_33 , V_99 , true ) ;
default:
return - V_39 ;
}
}
static int F_40 ( struct V_80 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_81 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_103 * V_42 = & V_11 -> V_42 ;
unsigned int V_104 ;
char * V_105 ;
int V_14 ;
int V_106 = 3 ;
F_3 ( V_11 , L_16 , V_29 ) ;
V_104 = F_12 ( V_42 -> V_107 ) ;
if ( ! V_104 || V_104 > V_108 ) {
F_41 ( L_17 , V_104 ) ;
return - V_96 ;
}
do {
V_14 = F_16 ( V_2 ) ;
if ( V_14 )
F_42 ( 1000 ) ;
} while ( V_106 -- > 0 && V_14 );
if ( V_14 )
return V_14 ;
V_105 = F_27 ( V_104 , V_84 ) ;
if ( ! V_105 ) {
F_41 ( L_18 ) ;
return - V_89 ;
}
F_3 ( V_11 , L_19 ) ;
V_14 = F_10 ( V_2 , & V_109 , V_105 , V_104 ) ;
if ( V_14 ) {
F_43 ( V_68 , L_20 ) ;
F_31 ( V_105 ) ;
return - V_39 ;
}
F_3 ( V_11 , L_21 , V_104 , V_105 ) ;
V_14 = F_44 ( V_68 , V_105 , V_104 ) ;
F_31 ( V_105 ) ;
if ( V_14 ) {
F_41 ( L_22 ) ;
return V_14 ;
}
return 0 ;
}
static int F_45 ( struct V_80 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_81 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
unsigned int V_79 = V_110 ;
F_32 ( V_68 , V_69 , & V_79 ) ;
F_32 ( V_68 , V_95 , & V_79 ) ;
F_32 ( V_68 , V_82 , & V_79 ) ;
if ( V_79 > V_11 -> V_79 ) {
F_33 ( V_11 ) ;
V_14 = F_34 ( V_11 , V_79 ) ;
if ( V_14 )
return V_14 ;
}
if ( ! ( V_68 -> V_111 & V_112 ) )
F_26 ( V_68 ) ;
return 0 ;
}
static void F_46 ( struct V_80 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_81 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
V_68 -> V_113 = 0 ;
F_33 ( V_11 ) ;
}
static int F_47 ( struct V_80 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_81 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 = 0 ;
F_48 ( & V_114 ) ;
if ( ! V_68 -> V_115 ++ ) {
V_14 = F_28 ( & V_2 -> V_45 ) ;
if ( V_14 < 0 ) {
V_68 -> V_115 -- ;
goto V_116;
}
F_4 ( V_67 , & V_11 -> V_31 ) ;
}
V_116:
F_49 ( & V_114 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static void F_50 ( struct V_80 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_81 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_48 ( & V_114 ) ;
if ( ! -- V_68 -> V_115 ) {
F_6 ( V_67 , & V_11 -> V_31 ) ;
F_30 ( & V_2 -> V_45 ) ;
}
F_49 ( & V_114 ) ;
}
static int F_51 ( struct V_80 * V_68 , int V_117 )
{
struct V_1 * V_2 = V_68 -> V_81 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_3 ( V_11 , L_23 , V_29 , V_117 ) ;
switch ( V_117 ) {
case V_118 :
F_28 ( & V_2 -> V_45 ) ;
break;
case V_119 :
F_30 ( & V_2 -> V_45 ) ;
break;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
F_53 ( & V_2 -> V_45 , L_24 , V_2 -> V_70 ) ;
V_14 = F_54 ( V_2 -> V_70 , NULL , F_22 ,
V_120 | V_121 ,
V_2 -> V_122 , V_11 ) ;
if ( V_14 < 0 ) {
F_55 ( & V_2 -> V_45 ,
L_25
L_26 ,
V_2 -> V_122 , V_2 -> V_70 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_56 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_103 * V_42 = & V_11 -> V_42 ;
unsigned int V_123 ;
int V_14 ;
F_3 ( V_11 , L_27 ) ;
V_14 = F_10 ( V_2 , & V_21 , V_11 -> V_26 ,
sizeof( struct V_103 ) ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_28 ) ;
return - V_124 ;
}
if ( F_12 ( V_42 -> V_125 ) != 0x0100 ) {
F_13 ( & V_2 -> V_45 ,
L_29 ,
F_12 ( V_42 -> V_125 ) ) ;
return - V_124 ;
}
V_123 = F_12 ( V_42 -> V_126 ) ;
if ( V_123 != sizeof( struct V_103 ) ) {
F_13 ( & V_2 -> V_45 , L_30 ,
V_123 ) ;
return - V_124 ;
}
F_3 ( V_11 , L_31 , V_123 , V_11 -> V_26 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
static T_1 V_129 [] = {
0xF7 , 0xF6 , 0xDF , 0x3C , 0x67 , 0x42 , 0x55 , 0x45 ,
0xAD , 0x05 , 0xB3 , 0x0A , 0x3D , 0x89 , 0x38 , 0xDE ,
} ;
union V_130 * V_131 ;
struct V_132 * V_133 ;
T_5 V_134 ;
V_134 = F_58 ( & V_2 -> V_45 ) ;
if ( ! V_134 || F_59 ( V_134 , & V_133 ) )
return - V_124 ;
V_131 = F_60 ( V_134 , V_129 , 1 , 1 , NULL ,
V_135 ) ;
if ( ! V_131 ) {
F_13 ( & V_2 -> V_45 , L_32 ) ;
return - V_124 ;
}
V_128 -> V_136 = V_131 -> integer . V_137 ;
F_61 ( V_131 ) ;
return 0 ;
}
static inline int F_57 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
return - V_124 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_75 * V_45 = & V_2 -> V_45 ;
T_6 V_138 ;
int V_14 ;
V_14 = F_63 ( V_45 -> V_139 , L_33 , & V_138 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_34 ) ;
return - V_124 ;
}
if ( V_138 >> 16 ) {
F_13 ( & V_2 -> V_45 , L_35 ,
V_138 ) ;
return - V_96 ;
}
V_128 -> V_136 = V_138 ;
return 0 ;
}
static inline int F_62 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
return - V_124 ;
}
static int F_64 ( struct V_1 * V_2 ,
const struct V_140 * V_71 )
{
int V_14 ;
struct V_10 * V_11 ;
struct V_80 * V_68 ;
V_88 V_141 ;
struct V_127 * V_142 = V_2 -> V_45 . V_142 ;
F_41 ( L_36 , V_2 -> V_30 ) ;
if ( ! V_2 -> V_70 ) {
F_13 ( & V_2 -> V_45 ,
L_37 ) ;
return - V_96 ;
}
V_11 = F_27 ( sizeof( struct V_10 ) , V_84 ) ;
if ( ! V_11 )
return - V_89 ;
if ( V_2 -> V_45 . V_139 ) {
V_14 = F_62 ( V_2 , & V_11 -> V_128 ) ;
if ( V_14 )
goto V_143;
} else if ( ! V_142 ) {
V_14 = F_57 ( V_2 , & V_11 -> V_128 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 ,
L_34 ) ;
goto V_143;
}
} else {
V_11 -> V_128 = * V_142 ;
}
F_65 ( V_2 , V_11 ) ;
V_11 -> V_2 = V_2 ;
V_141 = V_11 -> V_128 . V_136 ;
V_11 -> V_24 = F_66 ( V_141 ) ;
F_67 ( & V_11 -> V_19 ) ;
V_14 = F_34 ( V_11 , V_110 ) ;
if ( V_14 < 0 )
goto V_143;
F_68 ( & V_2 -> V_45 ) ;
F_69 ( & V_2 -> V_45 ) ;
F_70 ( & V_2 -> V_45 ) ;
V_14 = F_56 ( V_11 ) ;
if ( V_14 < 0 )
goto V_144;
V_14 = F_52 ( V_2 ) ;
if ( V_14 < 0 )
goto V_144;
V_68 = F_71 () ;
if ( F_72 ( V_68 ) ) {
V_14 = F_73 ( V_68 ) ;
goto V_145;
}
V_11 -> V_68 = V_68 ;
V_68 -> V_81 = V_2 ;
V_68 -> V_146 = & V_147 ;
V_68 -> V_45 . V_148 = & V_2 -> V_45 ;
F_74 ( & V_68 -> V_45 , F_75 ( & V_2 -> V_45 ) ) ;
V_68 -> V_149 = V_150 ;
V_68 -> V_151 = F_12 ( V_11 -> V_42 . V_125 ) ;
V_68 -> V_152 = F_12 ( V_11 -> V_42 . V_153 ) ;
V_68 -> V_154 = F_12 ( V_11 -> V_42 . V_155 ) ;
snprintf ( V_68 -> V_122 , sizeof( V_68 -> V_122 ) , L_38 ,
V_2 -> V_122 , V_68 -> V_152 , V_68 -> V_154 ) ;
V_14 = F_76 ( V_68 ) ;
if ( V_14 ) {
if ( V_14 != - V_124 )
F_43 ( V_2 , L_39 , V_14 ) ;
goto V_156;
}
F_30 ( & V_2 -> V_45 ) ;
return 0 ;
V_156:
F_77 ( V_68 ) ;
V_145:
F_78 ( V_2 -> V_70 , V_11 ) ;
V_144:
F_79 ( & V_2 -> V_45 ) ;
F_80 ( & V_2 -> V_45 ) ;
V_143:
F_33 ( V_11 ) ;
F_31 ( V_11 ) ;
return V_14 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_80 * V_68 ;
F_28 ( & V_2 -> V_45 ) ;
F_80 ( & V_2 -> V_45 ) ;
F_82 ( & V_2 -> V_45 ) ;
F_79 ( & V_2 -> V_45 ) ;
V_68 = V_11 -> V_68 ;
F_77 ( V_68 ) ;
F_78 ( V_2 -> V_70 , V_11 ) ;
if ( V_11 -> V_79 )
F_33 ( V_11 ) ;
F_31 ( V_11 ) ;
return 0 ;
}
static int F_83 ( struct V_75 * V_45 )
{
struct V_1 * V_2 = F_84 ( V_45 ) ;
F_85 ( V_2 -> V_70 ) ;
if ( F_86 ( & V_2 -> V_45 ) )
F_87 ( V_2 -> V_70 ) ;
F_15 ( V_2 , V_63 ) ;
return 0 ;
}
static int F_88 ( struct V_75 * V_45 )
{
int V_14 ;
struct V_1 * V_2 = F_84 ( V_45 ) ;
F_89 ( V_2 -> V_70 ) ;
V_14 = F_16 ( V_2 ) ;
if ( V_14 )
return V_14 ;
if ( F_86 ( & V_2 -> V_45 ) )
F_90 ( V_2 -> V_70 ) ;
return 0 ;
}
static int F_91 ( struct V_75 * V_45 )
{
struct V_1 * V_2 = F_84 ( V_45 ) ;
F_15 ( V_2 , V_63 ) ;
F_85 ( V_2 -> V_70 ) ;
return 0 ;
}
static int F_92 ( struct V_75 * V_45 )
{
struct V_1 * V_2 = F_84 ( V_45 ) ;
F_89 ( V_2 -> V_70 ) ;
F_15 ( V_2 , V_61 ) ;
return 0 ;
}
