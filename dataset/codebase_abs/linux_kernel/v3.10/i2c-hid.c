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
T_1 V_5 , unsigned char * V_34 , T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_1 * args = V_11 -> V_46 ;
int V_14 ;
T_2 V_47 = F_12 ( V_11 -> V_42 . V_43 ) ;
T_2 V_48 = 2 +
( V_5 ? 1 : 0 ) +
V_9 ;
int V_7 = ( V_5 >= 0x0F ? 1 : 0 ) +
2 +
V_48 ;
int V_49 = 0 ;
F_3 ( V_11 , L_4 , V_29 ) ;
if ( V_5 >= 0x0F ) {
args [ V_49 ++ ] = V_5 ;
V_5 = 0x0F ;
}
args [ V_49 ++ ] = V_47 & 0xFF ;
args [ V_49 ++ ] = V_47 >> 8 ;
args [ V_49 ++ ] = V_48 & 0xFF ;
args [ V_49 ++ ] = V_48 >> 8 ;
if ( V_5 )
args [ V_49 ++ ] = V_5 ;
memcpy ( & args [ V_49 ] , V_34 , V_9 ) ;
V_14 = F_1 ( V_2 , & V_50 , V_5 ,
V_6 , args , V_7 , NULL , 0 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_6 ) ;
return V_14 ;
}
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 , int V_51 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
F_3 ( V_11 , L_4 , V_29 ) ;
V_14 = F_1 ( V_2 , & V_52 , V_51 ,
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
V_14 = F_15 ( V_2 , V_53 ) ;
if ( V_14 )
return V_14 ;
F_3 ( V_11 , L_8 ) ;
V_14 = F_10 ( V_2 , & V_54 , NULL , 0 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_9 ) ;
F_15 ( V_2 , V_55 ) ;
return V_14 ;
}
return 0 ;
}
static void F_17 ( struct V_10 * V_11 )
{
int V_14 , V_56 ;
int V_48 = F_12 ( V_11 -> V_42 . V_57 ) ;
V_14 = F_18 ( V_11 -> V_2 , V_11 -> V_58 , V_48 ) ;
if ( V_14 != V_48 ) {
if ( V_14 < 0 )
return;
F_13 ( & V_11 -> V_2 -> V_45 , L_10 ,
V_29 , V_14 , V_48 ) ;
return;
}
V_56 = V_11 -> V_58 [ 0 ] | V_11 -> V_58 [ 1 ] << 8 ;
if ( ! V_56 ) {
if ( F_19 ( V_37 , & V_11 -> V_31 ) )
F_20 ( & V_11 -> V_19 ) ;
return;
}
if ( V_56 > V_48 ) {
F_13 ( & V_11 -> V_2 -> V_45 , L_11 ,
V_29 , V_48 , V_56 ) ;
return;
}
F_3 ( V_11 , L_12 , V_56 , V_11 -> V_58 ) ;
if ( F_8 ( V_59 , & V_11 -> V_31 ) )
F_21 ( V_11 -> V_60 , V_61 , V_11 -> V_58 + 2 ,
V_56 - 2 , 1 ) ;
return;
}
static T_4 F_22 ( int V_62 , void * V_63 )
{
struct V_10 * V_11 = V_63 ;
if ( F_8 ( V_36 , & V_11 -> V_31 ) )
return V_64 ;
F_17 ( V_11 ) ;
return V_64 ;
}
static int F_23 ( struct V_65 * V_66 )
{
return ( ( V_66 -> V_48 - 1 ) >> 3 ) + 1 +
V_66 -> V_67 -> V_68 [ V_66 -> type ] . V_69 + 2 ;
}
static void F_24 ( struct V_65 * V_66 , T_1 * V_70 ,
T_3 V_71 )
{
struct V_72 * V_60 = V_66 -> V_67 ;
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
unsigned int V_48 , V_56 ;
V_48 = F_23 ( V_66 ) ;
if ( F_11 ( V_2 ,
V_66 -> type == V_74 ? 0x03 : 0x01 ,
V_66 -> V_75 , V_70 , V_48 ) )
return;
F_3 ( V_11 , L_13 , V_48 , V_48 , V_11 -> V_58 ) ;
V_56 = V_70 [ 0 ] | ( V_70 [ 1 ] << 8 ) ;
if ( V_56 != V_48 ) {
F_13 ( & V_2 -> V_45 , L_14 ,
V_29 , V_48 , V_56 ) ;
return;
}
F_25 ( V_60 , V_66 -> type , V_70 + 2 , V_48 - 2 , 1 ) ;
}
static void F_26 ( struct V_72 * V_60 )
{
struct V_65 * V_66 ;
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_1 * V_58 = F_27 ( V_11 -> V_71 , V_76 ) ;
if ( ! V_58 ) {
F_13 ( & V_2 -> V_45 , L_15 ) ;
return;
}
F_28 (report,
&hid->report_enum[HID_INPUT_REPORT].report_list, list)
F_24 ( V_66 , V_58 , V_11 -> V_71 ) ;
F_28 (report,
&hid->report_enum[HID_FEATURE_REPORT].report_list, list)
F_24 ( V_66 , V_58 , V_11 -> V_71 ) ;
F_29 ( V_58 ) ;
}
static void F_30 ( struct V_72 * V_60 , unsigned int type ,
unsigned int * V_77 )
{
struct V_65 * V_66 ;
unsigned int V_48 ;
F_28 (report, &hid->report_enum[type].report_list, list) {
V_48 = F_23 ( V_66 ) ;
if ( * V_77 < V_48 )
* V_77 = V_48 ;
}
}
static void F_31 ( struct V_10 * V_11 )
{
F_29 ( V_11 -> V_58 ) ;
F_29 ( V_11 -> V_46 ) ;
F_29 ( V_11 -> V_13 ) ;
V_11 -> V_58 = NULL ;
V_11 -> V_13 = NULL ;
V_11 -> V_46 = NULL ;
V_11 -> V_71 = 0 ;
}
static int F_32 ( struct V_10 * V_11 , T_3 V_78 )
{
int V_7 = sizeof( V_79 ) +
sizeof( V_80 ) +
sizeof( V_80 ) +
V_78 ;
V_11 -> V_58 = F_27 ( V_78 , V_76 ) ;
V_11 -> V_46 = F_27 ( V_7 , V_76 ) ;
V_11 -> V_13 = F_27 ( sizeof( union V_4 ) + V_7 , V_76 ) ;
if ( ! V_11 -> V_58 || ! V_11 -> V_46 || ! V_11 -> V_13 ) {
F_31 ( V_11 ) ;
return - V_81 ;
}
V_11 -> V_71 = V_78 ;
return 0 ;
}
static int F_33 ( struct V_72 * V_60 ,
unsigned char V_82 , V_79 * V_34 , T_3 V_83 ,
unsigned char V_84 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_3 V_85 , V_86 ;
int V_14 ;
if ( V_84 == V_87 )
return - V_88 ;
V_86 = F_34 ( V_83 + 2 , ( T_3 ) V_11 -> V_71 ) ;
V_14 = F_11 ( V_2 ,
V_84 == V_74 ? 0x03 : 0x01 ,
V_82 , V_11 -> V_58 , V_86 ) ;
if ( V_14 < 0 )
return V_14 ;
V_85 = V_11 -> V_58 [ 0 ] | ( V_11 -> V_58 [ 1 ] << 8 ) ;
if ( V_85 <= 2 )
return 0 ;
V_85 = F_34 ( V_85 , V_86 ) ;
V_83 = F_34 ( V_83 , V_85 - 2 ) ;
memcpy ( V_34 , V_11 -> V_58 + 2 , V_83 ) ;
return V_83 ;
}
static int F_35 ( struct V_72 * V_60 , V_79 * V_34 ,
T_3 V_83 , unsigned char V_84 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
int V_89 = V_34 [ 0 ] ;
int V_14 ;
if ( V_84 == V_61 )
return - V_88 ;
if ( V_89 ) {
V_34 ++ ;
V_83 -- ;
}
V_14 = F_14 ( V_2 ,
V_84 == V_74 ? 0x03 : 0x02 ,
V_89 , V_34 , V_83 ) ;
if ( V_89 && V_14 >= 0 )
V_14 ++ ;
return V_14 ;
}
static void F_36 ( struct V_72 * V_60 , struct V_65 * V_90 ,
int V_91 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
char * V_34 ;
int V_14 ;
int V_33 = F_23 ( V_90 ) - 2 ;
V_34 = F_27 ( V_33 , V_76 ) ;
if ( ! V_34 )
return;
switch ( V_91 ) {
case V_92 :
V_14 = F_33 ( V_60 , V_90 -> V_75 , V_34 , V_33 , V_90 -> type ) ;
if ( V_14 < 0 )
F_13 ( & V_2 -> V_45 , L_16 ,
V_29 , V_14 ) ;
else
F_21 ( V_60 , V_90 -> type , V_34 , V_14 , 0 ) ;
break;
case V_93 :
F_37 ( V_90 , V_34 ) ;
F_35 ( V_60 , V_34 , V_33 , V_90 -> type ) ;
break;
}
F_29 ( V_34 ) ;
}
static int F_38 ( struct V_72 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_94 * V_42 = & V_11 -> V_42 ;
unsigned int V_95 ;
char * V_96 ;
int V_14 ;
int V_97 = 3 ;
F_3 ( V_11 , L_17 , V_29 ) ;
V_95 = F_12 ( V_42 -> V_98 ) ;
if ( ! V_95 || V_95 > V_99 ) {
F_39 ( L_18 , V_95 ) ;
return - V_88 ;
}
do {
V_14 = F_16 ( V_2 ) ;
if ( V_14 )
F_40 ( 1000 ) ;
} while ( V_97 -- > 0 && V_14 );
if ( V_14 )
return V_14 ;
V_96 = F_27 ( V_95 , V_76 ) ;
if ( ! V_96 ) {
F_39 ( L_19 ) ;
return - V_81 ;
}
F_3 ( V_11 , L_20 ) ;
V_14 = F_10 ( V_2 , & V_100 , V_96 , V_95 ) ;
if ( V_14 ) {
F_41 ( V_60 , L_21 ) ;
F_29 ( V_96 ) ;
return - V_39 ;
}
F_3 ( V_11 , L_22 , V_95 , V_96 ) ;
V_14 = F_42 ( V_60 , V_96 , V_95 ) ;
F_29 ( V_96 ) ;
if ( V_14 ) {
F_39 ( L_23 ) ;
return V_14 ;
}
return 0 ;
}
static int F_43 ( struct V_72 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
unsigned int V_71 = V_101 ;
F_30 ( V_60 , V_61 , & V_71 ) ;
F_30 ( V_60 , V_87 , & V_71 ) ;
F_30 ( V_60 , V_74 , & V_71 ) ;
if ( V_71 > V_11 -> V_71 ) {
F_31 ( V_11 ) ;
V_14 = F_32 ( V_11 , V_71 ) ;
if ( V_14 )
return V_14 ;
}
if ( ! ( V_60 -> V_102 & V_103 ) )
F_26 ( V_60 ) ;
return 0 ;
}
static void F_44 ( struct V_72 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
V_60 -> V_104 = 0 ;
F_31 ( V_11 ) ;
}
static int F_45 ( struct V_72 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 = 0 ;
F_46 ( & V_105 ) ;
if ( ! V_60 -> V_106 ++ ) {
V_14 = F_15 ( V_2 , V_53 ) ;
if ( V_14 ) {
V_60 -> V_106 -- ;
goto V_107;
}
F_4 ( V_59 , & V_11 -> V_31 ) ;
}
V_107:
F_47 ( & V_105 ) ;
return V_14 ;
}
static void F_48 ( struct V_72 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_46 ( & V_105 ) ;
if ( ! -- V_60 -> V_106 ) {
F_6 ( V_59 , & V_11 -> V_31 ) ;
F_15 ( V_2 , V_55 ) ;
}
F_47 ( & V_105 ) ;
}
static int F_49 ( struct V_72 * V_60 , int V_108 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 = 0 ;
F_3 ( V_11 , L_24 , V_29 , V_108 ) ;
switch ( V_108 ) {
case V_109 :
V_14 = F_15 ( V_2 , V_53 ) ;
break;
case V_110 :
V_14 = F_15 ( V_2 , V_55 ) ;
break;
}
return V_14 ;
}
static int F_50 ( struct V_111 * V_45 ,
unsigned int type , unsigned int V_112 , int V_113 )
{
struct V_72 * V_60 = F_51 ( V_45 ) ;
struct V_114 * V_115 ;
int V_116 ;
if ( type == V_117 )
return F_52 ( V_45 , type , V_112 , V_113 ) ;
if ( type != V_118 )
return - 1 ;
V_116 = F_53 ( V_60 , type , V_112 , & V_115 ) ;
if ( V_116 == - 1 ) {
F_54 ( V_45 , L_25 ) ;
return - 1 ;
}
return F_55 ( V_115 , V_116 , V_113 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
F_57 ( & V_2 -> V_45 , L_26 , V_2 -> V_62 ) ;
V_14 = F_58 ( V_2 -> V_62 , NULL , F_22 ,
V_119 | V_120 ,
V_2 -> V_121 , V_11 ) ;
if ( V_14 < 0 ) {
F_59 ( & V_2 -> V_45 ,
L_27
L_28 ,
V_2 -> V_121 , V_2 -> V_62 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_60 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_94 * V_42 = & V_11 -> V_42 ;
unsigned int V_122 ;
int V_14 ;
V_14 = F_10 ( V_2 , & V_21 , V_11 -> V_26 , 4 ) ;
F_3 ( V_11 , L_29 ,
V_29 , 4 , V_11 -> V_26 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 ,
L_30 ,
V_14 ) ;
return - V_123 ;
}
V_122 = F_12 ( V_42 -> V_124 ) ;
if ( V_122 < 4 || V_122 > sizeof( struct V_94 ) ) {
F_13 ( & V_2 -> V_45 , L_31 ,
V_122 ) ;
return - V_123 ;
}
if ( F_12 ( V_42 -> V_125 ) != 0x0100 ) {
F_13 ( & V_2 -> V_45 ,
L_32 ,
F_12 ( V_42 -> V_125 ) ) ;
return - V_123 ;
}
F_3 ( V_11 , L_33 ) ;
V_14 = F_10 ( V_2 , & V_21 , V_11 -> V_26 ,
V_122 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_34 ) ;
return - V_123 ;
}
F_3 ( V_11 , L_35 , V_122 , V_11 -> V_26 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
static T_1 V_128 [] = {
0xF7 , 0xF6 , 0xDF , 0x3C , 0x67 , 0x42 , 0x55 , 0x45 ,
0xAD , 0x05 , 0xB3 , 0x0A , 0x3D , 0x89 , 0x38 , 0xDE ,
} ;
struct V_129 V_34 = { V_130 , NULL } ;
union V_131 V_132 [ 4 ] , * V_133 ;
struct V_134 V_135 ;
struct V_136 * V_137 ;
T_5 V_138 ;
V_138 = F_62 ( & V_2 -> V_45 ) ;
if ( ! V_138 || F_63 ( V_138 , & V_137 ) )
return - V_123 ;
V_135 . V_83 = F_64 ( V_132 ) ;
V_135 . V_139 = V_132 ;
V_132 [ 0 ] . type = V_140 ;
V_132 [ 0 ] . V_70 . V_18 = sizeof( V_128 ) ;
V_132 [ 0 ] . V_70 . V_139 = V_128 ;
V_132 [ 1 ] . type = V_141 ;
V_132 [ 1 ] . integer . V_113 = 1 ;
V_132 [ 2 ] . type = V_141 ;
V_132 [ 2 ] . integer . V_113 = 1 ;
V_132 [ 3 ] . type = V_141 ;
V_132 [ 3 ] . integer . V_113 = 0 ;
if ( F_65 ( F_66 ( V_138 , L_36 , & V_135 , & V_34 ) ) ) {
F_13 ( & V_2 -> V_45 , L_37 ) ;
return - V_123 ;
}
V_133 = (union V_131 * ) V_34 . V_139 ;
if ( V_133 -> type != V_141 ) {
F_13 ( & V_2 -> V_45 , L_38 ,
V_133 -> type ) ;
F_29 ( V_34 . V_139 ) ;
return - V_88 ;
}
V_127 -> V_142 = V_133 -> integer . V_113 ;
F_29 ( V_34 . V_139 ) ;
return 0 ;
}
static inline int F_61 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
return - V_123 ;
}
static int F_67 ( struct V_1 * V_2 ,
const struct V_143 * V_63 )
{
int V_14 ;
struct V_10 * V_11 ;
struct V_72 * V_60 ;
V_80 V_144 ;
struct V_126 * V_145 = V_2 -> V_45 . V_145 ;
F_39 ( L_39 , V_2 -> V_30 ) ;
if ( ! V_2 -> V_62 ) {
F_13 ( & V_2 -> V_45 ,
L_40 ) ;
return - V_88 ;
}
V_11 = F_27 ( sizeof( struct V_10 ) , V_76 ) ;
if ( ! V_11 )
return - V_81 ;
if ( ! V_145 ) {
V_14 = F_61 ( V_2 , & V_11 -> V_127 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 ,
L_41 ) ;
goto V_146;
}
} else {
V_11 -> V_127 = * V_145 ;
}
F_68 ( V_2 , V_11 ) ;
V_11 -> V_2 = V_2 ;
V_144 = V_11 -> V_127 . V_142 ;
V_11 -> V_24 = F_69 ( V_144 ) ;
F_70 ( & V_11 -> V_19 ) ;
V_14 = F_32 ( V_11 , V_101 ) ;
if ( V_14 < 0 )
goto V_146;
V_14 = F_60 ( V_11 ) ;
if ( V_14 < 0 )
goto V_146;
V_14 = F_56 ( V_2 ) ;
if ( V_14 < 0 )
goto V_146;
V_60 = F_71 () ;
if ( F_72 ( V_60 ) ) {
V_14 = F_73 ( V_60 ) ;
goto V_147;
}
V_11 -> V_60 = V_60 ;
V_60 -> V_73 = V_2 ;
V_60 -> V_148 = & V_149 ;
V_60 -> V_150 = F_33 ;
V_60 -> V_151 = F_35 ;
V_60 -> V_45 . V_152 = & V_2 -> V_45 ;
F_74 ( & V_60 -> V_45 , F_62 ( & V_2 -> V_45 ) ) ;
V_60 -> V_153 = V_154 ;
V_60 -> V_155 = F_12 ( V_11 -> V_42 . V_125 ) ;
V_60 -> V_156 = F_12 ( V_11 -> V_42 . V_157 ) ;
V_60 -> V_158 = F_12 ( V_11 -> V_42 . V_159 ) ;
snprintf ( V_60 -> V_121 , sizeof( V_60 -> V_121 ) , L_42 ,
V_2 -> V_121 , V_60 -> V_156 , V_60 -> V_158 ) ;
V_14 = F_75 ( V_60 ) ;
if ( V_14 ) {
if ( V_14 != - V_123 )
F_41 ( V_2 , L_43 , V_14 ) ;
goto V_160;
}
return 0 ;
V_160:
F_76 ( V_60 ) ;
V_147:
F_77 ( V_2 -> V_62 , V_11 ) ;
V_146:
F_31 ( V_11 ) ;
F_29 ( V_11 ) ;
return V_14 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_72 * V_60 ;
V_60 = V_11 -> V_60 ;
F_76 ( V_60 ) ;
F_77 ( V_2 -> V_62 , V_11 ) ;
if ( V_11 -> V_71 )
F_31 ( V_11 ) ;
F_29 ( V_11 ) ;
return 0 ;
}
static int F_79 ( struct V_67 * V_45 )
{
struct V_1 * V_2 = F_80 ( V_45 ) ;
if ( F_81 ( & V_2 -> V_45 ) )
F_82 ( V_2 -> V_62 ) ;
F_15 ( V_2 , V_55 ) ;
return 0 ;
}
static int F_83 ( struct V_67 * V_45 )
{
int V_14 ;
struct V_1 * V_2 = F_80 ( V_45 ) ;
V_14 = F_16 ( V_2 ) ;
if ( V_14 )
return V_14 ;
if ( F_81 ( & V_2 -> V_45 ) )
F_84 ( V_2 -> V_62 ) ;
return 0 ;
}
