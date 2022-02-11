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
static int F_36 ( struct V_72 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_90 * V_42 = & V_11 -> V_42 ;
unsigned int V_91 ;
char * V_92 ;
int V_14 ;
int V_93 = 3 ;
F_3 ( V_11 , L_16 , V_29 ) ;
V_91 = F_12 ( V_42 -> V_94 ) ;
if ( ! V_91 || V_91 > V_95 ) {
F_37 ( L_17 , V_91 ) ;
return - V_88 ;
}
do {
V_14 = F_16 ( V_2 ) ;
if ( V_14 )
F_38 ( 1000 ) ;
} while ( V_93 -- > 0 && V_14 );
if ( V_14 )
return V_14 ;
V_92 = F_27 ( V_91 , V_76 ) ;
if ( ! V_92 ) {
F_37 ( L_18 ) ;
return - V_81 ;
}
F_3 ( V_11 , L_19 ) ;
V_14 = F_10 ( V_2 , & V_96 , V_92 , V_91 ) ;
if ( V_14 ) {
F_39 ( V_60 , L_20 ) ;
F_29 ( V_92 ) ;
return - V_39 ;
}
F_3 ( V_11 , L_21 , V_91 , V_92 ) ;
V_14 = F_40 ( V_60 , V_92 , V_91 ) ;
F_29 ( V_92 ) ;
if ( V_14 ) {
F_37 ( L_22 ) ;
return V_14 ;
}
return 0 ;
}
static int F_41 ( struct V_72 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
unsigned int V_71 = V_97 ;
F_30 ( V_60 , V_61 , & V_71 ) ;
F_30 ( V_60 , V_87 , & V_71 ) ;
F_30 ( V_60 , V_74 , & V_71 ) ;
if ( V_71 > V_11 -> V_71 ) {
F_31 ( V_11 ) ;
V_14 = F_32 ( V_11 , V_71 ) ;
if ( V_14 )
return V_14 ;
}
if ( ! ( V_60 -> V_98 & V_99 ) )
F_26 ( V_60 ) ;
return 0 ;
}
static void F_42 ( struct V_72 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
V_60 -> V_100 = 0 ;
F_31 ( V_11 ) ;
}
static int F_43 ( struct V_72 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 = 0 ;
F_44 ( & V_101 ) ;
if ( ! V_60 -> V_102 ++ ) {
V_14 = F_15 ( V_2 , V_53 ) ;
if ( V_14 ) {
V_60 -> V_102 -- ;
goto V_103;
}
F_4 ( V_59 , & V_11 -> V_31 ) ;
}
V_103:
F_45 ( & V_101 ) ;
return V_14 ;
}
static void F_46 ( struct V_72 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_44 ( & V_101 ) ;
if ( ! -- V_60 -> V_102 ) {
F_6 ( V_59 , & V_11 -> V_31 ) ;
F_15 ( V_2 , V_55 ) ;
}
F_45 ( & V_101 ) ;
}
static int F_47 ( struct V_72 * V_60 , int V_104 )
{
struct V_1 * V_2 = V_60 -> V_73 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 = 0 ;
F_3 ( V_11 , L_23 , V_29 , V_104 ) ;
switch ( V_104 ) {
case V_105 :
V_14 = F_15 ( V_2 , V_53 ) ;
break;
case V_106 :
V_14 = F_15 ( V_2 , V_55 ) ;
break;
}
return V_14 ;
}
static int F_48 ( struct V_107 * V_45 ,
unsigned int type , unsigned int V_108 , int V_109 )
{
struct V_72 * V_60 = F_49 ( V_45 ) ;
struct V_110 * V_111 ;
int V_112 ;
if ( type == V_113 )
return F_50 ( V_45 , type , V_108 , V_109 ) ;
if ( type != V_114 )
return - 1 ;
V_112 = F_51 ( V_60 , type , V_108 , & V_111 ) ;
if ( V_112 == - 1 ) {
F_52 ( V_45 , L_24 ) ;
return - 1 ;
}
return F_53 ( V_111 , V_112 , V_109 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
F_55 ( & V_2 -> V_45 , L_25 , V_2 -> V_62 ) ;
V_14 = F_56 ( V_2 -> V_62 , NULL , F_22 ,
V_115 | V_116 ,
V_2 -> V_117 , V_11 ) ;
if ( V_14 < 0 ) {
F_57 ( & V_2 -> V_45 ,
L_26
L_27 ,
V_2 -> V_117 , V_2 -> V_62 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_58 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_90 * V_42 = & V_11 -> V_42 ;
unsigned int V_118 ;
int V_14 ;
V_14 = F_10 ( V_2 , & V_21 , V_11 -> V_26 , 4 ) ;
F_3 ( V_11 , L_28 ,
V_29 , 4 , V_11 -> V_26 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 ,
L_29 ,
V_14 ) ;
return - V_119 ;
}
V_118 = F_12 ( V_42 -> V_120 ) ;
if ( V_118 < 4 || V_118 > sizeof( struct V_90 ) ) {
F_13 ( & V_2 -> V_45 , L_30 ,
V_118 ) ;
return - V_119 ;
}
if ( F_12 ( V_42 -> V_121 ) != 0x0100 ) {
F_13 ( & V_2 -> V_45 ,
L_31 ,
F_12 ( V_42 -> V_121 ) ) ;
return - V_119 ;
}
F_3 ( V_11 , L_32 ) ;
V_14 = F_10 ( V_2 , & V_21 , V_11 -> V_26 ,
V_118 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_33 ) ;
return - V_119 ;
}
F_3 ( V_11 , L_34 , V_118 , V_11 -> V_26 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
const struct V_122 * V_63 )
{
int V_14 ;
struct V_10 * V_11 ;
struct V_72 * V_60 ;
V_80 V_123 ;
struct V_124 * V_125 = V_2 -> V_45 . V_125 ;
F_37 ( L_35 , V_2 -> V_30 ) ;
if ( ! V_125 ) {
F_13 ( & V_2 -> V_45 , L_36 ) ;
return - V_88 ;
}
if ( ! V_2 -> V_62 ) {
F_13 ( & V_2 -> V_45 ,
L_37 ) ;
return - V_88 ;
}
V_11 = F_27 ( sizeof( struct V_10 ) , V_76 ) ;
if ( ! V_11 )
return - V_81 ;
F_60 ( V_2 , V_11 ) ;
V_11 -> V_2 = V_2 ;
V_123 = V_125 -> V_126 ;
V_11 -> V_24 = F_61 ( V_123 ) ;
F_62 ( & V_11 -> V_19 ) ;
V_14 = F_32 ( V_11 , V_97 ) ;
if ( V_14 < 0 )
goto V_127;
V_14 = F_58 ( V_11 ) ;
if ( V_14 < 0 )
goto V_127;
V_14 = F_54 ( V_2 ) ;
if ( V_14 < 0 )
goto V_127;
V_60 = F_63 () ;
if ( F_64 ( V_60 ) ) {
V_14 = F_65 ( V_60 ) ;
goto V_128;
}
V_11 -> V_60 = V_60 ;
V_60 -> V_73 = V_2 ;
V_60 -> V_129 = & V_130 ;
V_60 -> V_131 = F_33 ;
V_60 -> V_132 = F_35 ;
V_60 -> V_45 . V_133 = & V_2 -> V_45 ;
V_60 -> V_134 = V_135 ;
V_60 -> V_136 = F_12 ( V_11 -> V_42 . V_121 ) ;
V_60 -> V_137 = F_12 ( V_11 -> V_42 . V_138 ) ;
V_60 -> V_139 = F_12 ( V_11 -> V_42 . V_140 ) ;
snprintf ( V_60 -> V_117 , sizeof( V_60 -> V_117 ) , L_38 ,
V_2 -> V_117 , V_60 -> V_137 , V_60 -> V_139 ) ;
V_14 = F_66 ( V_60 ) ;
if ( V_14 ) {
if ( V_14 != - V_119 )
F_39 ( V_2 , L_39 , V_14 ) ;
goto V_141;
}
return 0 ;
V_141:
F_67 ( V_60 ) ;
V_128:
F_68 ( V_2 -> V_62 , V_11 ) ;
V_127:
F_31 ( V_11 ) ;
F_29 ( V_11 ) ;
return V_14 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_72 * V_60 ;
V_60 = V_11 -> V_60 ;
F_67 ( V_60 ) ;
F_68 ( V_2 -> V_62 , V_11 ) ;
if ( V_11 -> V_71 )
F_31 ( V_11 ) ;
F_29 ( V_11 ) ;
return 0 ;
}
static int F_70 ( struct V_67 * V_45 )
{
struct V_1 * V_2 = F_71 ( V_45 ) ;
if ( F_72 ( & V_2 -> V_45 ) )
F_73 ( V_2 -> V_62 ) ;
F_15 ( V_2 , V_55 ) ;
return 0 ;
}
static int F_74 ( struct V_67 * V_45 )
{
int V_14 ;
struct V_1 * V_2 = F_71 ( V_45 ) ;
V_14 = F_16 ( V_2 ) ;
if ( V_14 )
return V_14 ;
if ( F_72 ( & V_2 -> V_45 ) )
F_75 ( V_2 -> V_62 ) ;
return 0 ;
}
