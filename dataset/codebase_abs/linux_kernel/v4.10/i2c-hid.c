static T_1 F_1 ( const T_2 V_1 , const T_2 V_2 )
{
T_1 V_3 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_5 [ V_4 ] . V_1 ; V_4 ++ )
if ( V_5 [ V_4 ] . V_1 == V_1 &&
( V_5 [ V_4 ] . V_2 == ( V_6 ) V_7 ||
V_5 [ V_4 ] . V_2 == V_2 ) )
V_3 = V_5 [ V_4 ] . V_3 ;
return V_3 ;
}
static int F_2 ( struct V_8 * V_9 ,
const struct V_10 * V_11 , T_3 V_12 ,
T_3 V_13 , T_3 * args , int V_14 ,
unsigned char * V_15 , int V_16 )
{
struct V_17 * V_18 = F_3 ( V_9 ) ;
union V_11 * V_19 = (union V_11 * ) V_18 -> V_20 ;
int V_21 ;
struct V_22 V_23 [ 2 ] ;
int V_24 = 1 ;
int V_25 = V_11 -> V_25 ;
bool V_26 = V_11 -> V_26 ;
unsigned int V_27 = V_11 -> V_27 ;
if ( V_11 == & V_28 ) {
V_19 -> V_29 . V_30 = V_18 -> V_31 ;
} else {
V_19 -> V_32 [ 0 ] = V_18 -> V_33 [ V_27 ] ;
V_19 -> V_32 [ 1 ] = V_18 -> V_33 [ V_27 + 1 ] ;
}
if ( V_25 > 2 ) {
V_19 -> V_29 . V_34 = V_11 -> V_34 ;
V_19 -> V_29 . V_35 = V_12 | V_13 << 4 ;
}
memcpy ( V_19 -> V_32 + V_25 , args , V_14 ) ;
V_25 += V_14 ;
F_4 ( V_18 , L_1 , V_36 , V_25 , V_19 -> V_32 ) ;
V_23 [ 0 ] . V_37 = V_9 -> V_37 ;
V_23 [ 0 ] . V_38 = V_9 -> V_38 & V_39 ;
V_23 [ 0 ] . V_40 = V_25 ;
V_23 [ 0 ] . V_41 = V_19 -> V_32 ;
if ( V_16 > 0 ) {
V_23 [ 1 ] . V_37 = V_9 -> V_37 ;
V_23 [ 1 ] . V_38 = V_9 -> V_38 & V_39 ;
V_23 [ 1 ] . V_38 |= V_42 ;
V_23 [ 1 ] . V_40 = V_16 ;
V_23 [ 1 ] . V_41 = V_15 ;
V_24 = 2 ;
F_5 ( V_43 , & V_18 -> V_38 ) ;
}
if ( V_26 )
F_5 ( V_44 , & V_18 -> V_38 ) ;
V_21 = F_6 ( V_9 -> V_45 , V_23 , V_24 ) ;
if ( V_16 > 0 )
F_7 ( V_43 , & V_18 -> V_38 ) ;
if ( V_21 != V_24 )
return V_21 < 0 ? V_21 : - V_46 ;
V_21 = 0 ;
if ( V_26 ) {
F_4 ( V_18 , L_2 , V_36 ) ;
if ( ! F_8 ( V_18 -> V_26 ,
! F_9 ( V_44 , & V_18 -> V_38 ) ,
F_10 ( 5000 ) ) )
V_21 = - V_47 ;
F_4 ( V_18 , L_3 , V_36 ) ;
}
return V_21 ;
}
static int F_11 ( struct V_8 * V_9 ,
const struct V_10 * V_11 ,
unsigned char * V_15 , int V_16 )
{
return F_2 ( V_9 , V_11 , 0 , 0 , NULL , 0 ,
V_15 , V_16 ) ;
}
static int F_12 ( struct V_8 * V_9 , T_3 V_13 ,
T_3 V_12 , unsigned char * V_15 , int V_16 )
{
struct V_17 * V_18 = F_3 ( V_9 ) ;
T_3 args [ 3 ] ;
int V_21 ;
int V_14 = 0 ;
T_2 V_48 = F_13 ( V_18 -> V_49 . V_50 ) ;
F_4 ( V_18 , L_4 , V_36 ) ;
if ( V_12 >= 0x0F ) {
args [ V_14 ++ ] = V_12 ;
V_12 = 0x0F ;
}
args [ V_14 ++ ] = V_48 & 0xFF ;
args [ V_14 ++ ] = V_48 >> 8 ;
V_21 = F_2 ( V_9 , & V_51 , V_12 ,
V_13 , args , V_14 , V_15 , V_16 ) ;
if ( V_21 ) {
F_14 ( & V_9 -> V_52 ,
L_5 ) ;
return V_21 ;
}
return 0 ;
}
static int F_15 ( struct V_8 * V_9 , T_3 V_13 ,
T_3 V_12 , unsigned char * V_41 , T_4 V_16 , bool V_53 )
{
struct V_17 * V_18 = F_3 ( V_9 ) ;
T_3 * args = V_18 -> V_54 ;
const struct V_10 * V_55 ;
int V_21 ;
T_2 V_56 = F_13 ( V_18 -> V_49 . V_50 ) ;
T_2 V_57 = F_13 ( V_18 -> V_49 . V_58 ) ;
T_2 V_59 = F_13 ( V_18 -> V_49 . V_60 ) ;
T_2 V_61 ;
int V_14 ;
int V_62 = 0 ;
F_4 ( V_18 , L_4 , V_36 ) ;
if ( V_16 > V_18 -> V_63 )
return - V_64 ;
V_61 = 2 +
( V_12 ? 1 : 0 ) +
V_16 ;
V_14 = ( V_12 >= 0x0F ? 1 : 0 ) +
2 +
V_61 ;
if ( ! V_53 && V_59 == 0 )
return - V_65 ;
if ( V_12 >= 0x0F ) {
args [ V_62 ++ ] = V_12 ;
V_12 = 0x0F ;
}
if ( V_53 ) {
args [ V_62 ++ ] = V_56 & 0xFF ;
args [ V_62 ++ ] = V_56 >> 8 ;
V_55 = & V_66 ;
} else {
args [ V_62 ++ ] = V_57 & 0xFF ;
args [ V_62 ++ ] = V_57 >> 8 ;
V_55 = & V_67 ;
}
args [ V_62 ++ ] = V_61 & 0xFF ;
args [ V_62 ++ ] = V_61 >> 8 ;
if ( V_12 )
args [ V_62 ++ ] = V_12 ;
memcpy ( & args [ V_62 ] , V_41 , V_16 ) ;
V_21 = F_2 ( V_9 , V_55 , V_12 ,
V_13 , args , V_14 , NULL , 0 ) ;
if ( V_21 ) {
F_14 ( & V_9 -> V_52 , L_6 ) ;
return V_21 ;
}
return V_16 ;
}
static int F_16 ( struct V_8 * V_9 , int V_68 )
{
struct V_17 * V_18 = F_3 ( V_9 ) ;
int V_21 ;
F_4 ( V_18 , L_4 , V_36 ) ;
if ( V_68 == V_69 &&
V_18 -> V_3 & V_70 ) {
V_21 = F_11 ( V_9 , & V_71 , NULL , 0 ) ;
if ( ! V_21 )
goto V_72;
}
V_21 = F_2 ( V_9 , & V_71 , V_68 ,
0 , NULL , 0 , NULL , 0 ) ;
if ( V_21 )
F_14 ( & V_9 -> V_52 , L_7 ) ;
V_72:
return V_21 ;
}
static int F_17 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = F_3 ( V_9 ) ;
int V_21 ;
F_4 ( V_18 , L_4 , V_36 ) ;
F_18 ( & V_18 -> V_73 ) ;
V_21 = F_16 ( V_9 , V_69 ) ;
if ( V_21 )
goto V_74;
F_19 ( 1000 , 5000 ) ;
F_4 ( V_18 , L_8 ) ;
V_21 = F_11 ( V_9 , & V_75 , NULL , 0 ) ;
if ( V_21 ) {
F_14 ( & V_9 -> V_52 , L_9 ) ;
F_16 ( V_9 , V_76 ) ;
}
V_74:
F_20 ( & V_18 -> V_73 ) ;
return V_21 ;
}
static void F_21 ( struct V_17 * V_18 )
{
int V_21 , V_77 ;
int V_61 = F_13 ( V_18 -> V_49 . V_78 ) ;
if ( V_61 > V_18 -> V_63 )
V_61 = V_18 -> V_63 ;
V_21 = F_22 ( V_18 -> V_9 , V_18 -> V_79 , V_61 ) ;
if ( V_21 != V_61 ) {
if ( V_21 < 0 )
return;
F_14 ( & V_18 -> V_9 -> V_52 , L_10 ,
V_36 , V_21 , V_61 ) ;
return;
}
V_77 = V_18 -> V_79 [ 0 ] | V_18 -> V_79 [ 1 ] << 8 ;
if ( ! V_77 ) {
if ( F_23 ( V_44 , & V_18 -> V_38 ) )
F_24 ( & V_18 -> V_26 ) ;
return;
}
if ( V_77 > V_61 ) {
F_14 ( & V_18 -> V_9 -> V_52 , L_11 ,
V_36 , V_61 , V_77 ) ;
return;
}
F_4 ( V_18 , L_12 , V_77 , V_18 -> V_79 ) ;
if ( F_9 ( V_80 , & V_18 -> V_38 ) )
F_25 ( V_18 -> V_81 , V_82 , V_18 -> V_79 + 2 ,
V_77 - 2 , 1 ) ;
return;
}
static T_5 F_26 ( int V_83 , void * V_84 )
{
struct V_17 * V_18 = V_84 ;
if ( F_9 ( V_43 , & V_18 -> V_38 ) )
return V_85 ;
F_21 ( V_18 ) ;
return V_85 ;
}
static int F_27 ( struct V_86 * V_87 )
{
return ( ( V_87 -> V_61 - 1 ) >> 3 ) + 1 +
V_87 -> V_88 -> V_89 [ V_87 -> type ] . V_90 + 2 ;
}
static void F_28 ( struct V_86 * V_87 , T_3 * V_91 ,
T_4 V_63 )
{
struct V_92 * V_81 = V_87 -> V_88 ;
struct V_8 * V_9 = V_81 -> V_93 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
unsigned int V_61 , V_77 ;
V_61 = F_27 ( V_87 ) ;
if ( F_12 ( V_9 ,
V_87 -> type == V_94 ? 0x03 : 0x01 ,
V_87 -> V_95 , V_91 , V_61 ) )
return;
F_4 ( V_18 , L_13 , V_61 , V_61 , V_91 ) ;
V_77 = V_91 [ 0 ] | ( V_91 [ 1 ] << 8 ) ;
if ( V_77 != V_61 ) {
F_14 ( & V_9 -> V_52 , L_14 ,
V_36 , V_61 , V_77 ) ;
return;
}
F_29 ( V_81 , V_87 -> type , V_91 + 2 , V_61 - 2 , 1 ) ;
}
static void F_30 ( struct V_92 * V_81 )
{
struct V_86 * V_87 ;
struct V_8 * V_9 = V_81 -> V_93 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
T_3 * V_79 = F_31 ( V_18 -> V_63 , V_96 ) ;
if ( ! V_79 ) {
F_14 ( & V_9 -> V_52 , L_15 ) ;
return;
}
F_32 ( & V_9 -> V_52 ) ;
F_33 (report,
&hid->report_enum[HID_FEATURE_REPORT].report_list, list)
F_28 ( V_87 , V_79 , V_18 -> V_63 ) ;
F_34 ( & V_9 -> V_52 ) ;
F_35 ( V_79 ) ;
}
static void F_36 ( struct V_92 * V_81 , unsigned int type ,
unsigned int * V_97 )
{
struct V_86 * V_87 ;
unsigned int V_61 ;
F_33 (report, &hid->report_enum[type].report_list, list) {
V_61 = F_27 ( V_87 ) ;
if ( * V_97 < V_61 )
* V_97 = V_61 ;
}
}
static void F_37 ( struct V_17 * V_18 )
{
F_35 ( V_18 -> V_79 ) ;
F_35 ( V_18 -> V_98 ) ;
F_35 ( V_18 -> V_54 ) ;
F_35 ( V_18 -> V_20 ) ;
V_18 -> V_79 = NULL ;
V_18 -> V_98 = NULL ;
V_18 -> V_20 = NULL ;
V_18 -> V_54 = NULL ;
V_18 -> V_63 = 0 ;
}
static int F_38 ( struct V_17 * V_18 , T_4 V_99 )
{
int V_14 = sizeof( V_100 ) +
sizeof( V_6 ) +
sizeof( V_6 ) +
V_99 ;
V_18 -> V_79 = F_31 ( V_99 , V_96 ) ;
V_18 -> V_98 = F_31 ( V_99 , V_96 ) ;
V_18 -> V_54 = F_31 ( V_14 , V_96 ) ;
V_18 -> V_20 = F_31 ( sizeof( union V_11 ) + V_14 , V_96 ) ;
if ( ! V_18 -> V_79 || ! V_18 -> V_98 || ! V_18 -> V_54 || ! V_18 -> V_20 ) {
F_37 ( V_18 ) ;
return - V_101 ;
}
V_18 -> V_63 = V_99 ;
return 0 ;
}
static int F_39 ( struct V_92 * V_81 ,
unsigned char V_102 , V_100 * V_41 , T_4 V_103 ,
unsigned char V_104 )
{
struct V_8 * V_9 = V_81 -> V_93 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
T_4 V_105 , V_106 ;
int V_21 ;
if ( V_104 == V_107 )
return - V_64 ;
V_106 = F_40 ( V_103 + 2 , ( T_4 ) V_18 -> V_63 ) ;
V_21 = F_12 ( V_9 ,
V_104 == V_94 ? 0x03 : 0x01 ,
V_102 , V_18 -> V_98 , V_106 ) ;
if ( V_21 < 0 )
return V_21 ;
V_105 = V_18 -> V_98 [ 0 ] | ( V_18 -> V_98 [ 1 ] << 8 ) ;
if ( V_105 <= 2 )
return 0 ;
V_105 = F_40 ( V_105 , V_106 ) ;
V_103 = F_40 ( V_103 , V_105 - 2 ) ;
memcpy ( V_41 , V_18 -> V_98 + 2 , V_103 ) ;
return V_103 ;
}
static int F_41 ( struct V_92 * V_81 , V_100 * V_41 ,
T_4 V_103 , unsigned char V_104 , bool V_53 )
{
struct V_8 * V_9 = V_81 -> V_93 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
int V_108 = V_41 [ 0 ] ;
int V_21 ;
if ( V_104 == V_82 )
return - V_64 ;
F_18 ( & V_18 -> V_73 ) ;
if ( V_108 ) {
V_41 ++ ;
V_103 -- ;
}
V_21 = F_15 ( V_9 ,
V_104 == V_94 ? 0x03 : 0x02 ,
V_108 , V_41 , V_103 , V_53 ) ;
if ( V_108 && V_21 >= 0 )
V_21 ++ ;
F_20 ( & V_18 -> V_73 ) ;
return V_21 ;
}
static int F_42 ( struct V_92 * V_81 , V_100 * V_41 ,
T_4 V_103 )
{
return F_41 ( V_81 , V_41 , V_103 , V_107 ,
false ) ;
}
static int F_43 ( struct V_92 * V_81 , unsigned char V_109 ,
V_100 * V_41 , T_4 V_40 , unsigned char V_110 ,
int V_111 )
{
switch ( V_111 ) {
case V_112 :
return F_39 ( V_81 , V_109 , V_41 , V_40 , V_110 ) ;
case V_113 :
if ( V_41 [ 0 ] != V_109 )
return - V_64 ;
return F_41 ( V_81 , V_41 , V_40 , V_110 , true ) ;
default:
return - V_46 ;
}
}
static int F_44 ( struct V_92 * V_81 )
{
struct V_8 * V_9 = V_81 -> V_93 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
struct V_114 * V_49 = & V_18 -> V_49 ;
unsigned int V_115 ;
char * V_116 ;
int V_21 ;
int V_117 = 3 ;
F_4 ( V_18 , L_16 , V_36 ) ;
V_115 = F_13 ( V_49 -> V_118 ) ;
if ( ! V_115 || V_115 > V_119 ) {
F_45 ( L_17 , V_115 ) ;
return - V_64 ;
}
do {
V_21 = F_17 ( V_9 ) ;
if ( V_21 )
F_46 ( 1000 ) ;
} while ( V_117 -- > 0 && V_21 );
if ( V_21 )
return V_21 ;
V_116 = F_31 ( V_115 , V_96 ) ;
if ( ! V_116 ) {
F_45 ( L_18 ) ;
return - V_101 ;
}
F_4 ( V_18 , L_19 ) ;
V_21 = F_11 ( V_9 , & V_120 , V_116 , V_115 ) ;
if ( V_21 ) {
F_47 ( V_81 , L_20 ) ;
F_35 ( V_116 ) ;
return - V_46 ;
}
F_4 ( V_18 , L_21 , V_115 , V_116 ) ;
V_21 = F_48 ( V_81 , V_116 , V_115 ) ;
F_35 ( V_116 ) ;
if ( V_21 ) {
F_45 ( L_22 ) ;
return V_21 ;
}
return 0 ;
}
static int F_49 ( struct V_92 * V_81 )
{
struct V_8 * V_9 = V_81 -> V_93 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
int V_21 ;
unsigned int V_63 = V_121 ;
F_36 ( V_81 , V_82 , & V_63 ) ;
F_36 ( V_81 , V_107 , & V_63 ) ;
F_36 ( V_81 , V_94 , & V_63 ) ;
if ( V_63 > V_18 -> V_63 ) {
F_50 ( V_9 -> V_83 ) ;
F_37 ( V_18 ) ;
V_21 = F_38 ( V_18 , V_63 ) ;
F_51 ( V_9 -> V_83 ) ;
if ( V_21 )
return V_21 ;
}
if ( ! ( V_81 -> V_3 & V_122 ) )
F_30 ( V_81 ) ;
return 0 ;
}
static void F_52 ( struct V_92 * V_81 )
{
V_81 -> V_123 = 0 ;
}
static int F_53 ( struct V_92 * V_81 )
{
struct V_8 * V_9 = V_81 -> V_93 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
int V_21 = 0 ;
F_18 ( & V_124 ) ;
if ( ! V_81 -> V_125 ++ ) {
V_21 = F_32 ( & V_9 -> V_52 ) ;
if ( V_21 < 0 ) {
V_81 -> V_125 -- ;
goto V_126;
}
F_5 ( V_80 , & V_18 -> V_38 ) ;
}
V_126:
F_20 ( & V_124 ) ;
return V_21 < 0 ? V_21 : 0 ;
}
static void F_54 ( struct V_92 * V_81 )
{
struct V_8 * V_9 = V_81 -> V_93 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
F_18 ( & V_124 ) ;
if ( ! -- V_81 -> V_125 ) {
F_7 ( V_80 , & V_18 -> V_38 ) ;
F_34 ( & V_9 -> V_52 ) ;
}
F_20 ( & V_124 ) ;
}
static int F_55 ( struct V_92 * V_81 , int V_127 )
{
struct V_8 * V_9 = V_81 -> V_93 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
F_4 ( V_18 , L_23 , V_36 , V_127 ) ;
switch ( V_127 ) {
case V_128 :
F_32 ( & V_9 -> V_52 ) ;
break;
case V_129 :
F_34 ( & V_9 -> V_52 ) ;
break;
}
return 0 ;
}
static int F_56 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = F_3 ( V_9 ) ;
unsigned long V_130 = 0 ;
int V_21 ;
F_57 ( & V_9 -> V_52 , L_24 , V_9 -> V_83 ) ;
if ( ! F_58 ( V_9 -> V_83 ) )
V_130 = V_131 ;
V_21 = F_59 ( V_9 -> V_83 , NULL , F_26 ,
V_130 | V_132 , V_9 -> V_133 , V_18 ) ;
if ( V_21 < 0 ) {
F_60 ( & V_9 -> V_52 ,
L_25
L_26 ,
V_9 -> V_133 , V_9 -> V_83 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
static int F_61 ( struct V_17 * V_18 )
{
struct V_8 * V_9 = V_18 -> V_9 ;
struct V_114 * V_49 = & V_18 -> V_49 ;
unsigned int V_134 ;
int V_21 ;
F_4 ( V_18 , L_27 ) ;
V_21 = F_11 ( V_9 , & V_28 , V_18 -> V_33 ,
sizeof( struct V_114 ) ) ;
if ( V_21 ) {
F_14 ( & V_9 -> V_52 , L_28 ) ;
return - V_135 ;
}
if ( F_13 ( V_49 -> V_136 ) != 0x0100 ) {
F_14 ( & V_9 -> V_52 ,
L_29 ,
F_13 ( V_49 -> V_136 ) ) ;
return - V_135 ;
}
V_134 = F_13 ( V_49 -> V_137 ) ;
if ( V_134 != sizeof( struct V_114 ) ) {
F_14 ( & V_9 -> V_52 , L_30 ,
V_134 ) ;
return - V_135 ;
}
F_4 ( V_18 , L_31 , V_134 , V_18 -> V_33 ) ;
return 0 ;
}
static int F_62 ( struct V_8 * V_9 ,
struct V_138 * V_139 )
{
static T_3 V_140 [] = {
0xF7 , 0xF6 , 0xDF , 0x3C , 0x67 , 0x42 , 0x55 , 0x45 ,
0xAD , 0x05 , 0xB3 , 0x0A , 0x3D , 0x89 , 0x38 , 0xDE ,
} ;
union V_141 * V_142 ;
struct V_143 * V_144 ;
T_6 V_145 ;
V_145 = F_63 ( & V_9 -> V_52 ) ;
if ( ! V_145 || F_64 ( V_145 , & V_144 ) )
return - V_135 ;
V_142 = F_65 ( V_145 , V_140 , 1 , 1 , NULL ,
V_146 ) ;
if ( ! V_142 ) {
F_14 ( & V_9 -> V_52 , L_32 ) ;
return - V_135 ;
}
V_139 -> V_147 = V_142 -> integer . V_148 ;
F_66 ( V_142 ) ;
return 0 ;
}
static inline int F_62 ( struct V_8 * V_9 ,
struct V_138 * V_139 )
{
return - V_135 ;
}
static int F_67 ( struct V_8 * V_9 ,
struct V_138 * V_139 )
{
struct V_88 * V_52 = & V_9 -> V_52 ;
T_1 V_149 ;
int V_21 ;
V_21 = F_68 ( V_52 -> V_150 , L_33 , & V_149 ) ;
if ( V_21 ) {
F_14 ( & V_9 -> V_52 , L_34 ) ;
return - V_135 ;
}
if ( V_149 >> 16 ) {
F_14 ( & V_9 -> V_52 , L_35 ,
V_149 ) ;
return - V_64 ;
}
V_139 -> V_147 = V_149 ;
return 0 ;
}
static inline int F_67 ( struct V_8 * V_9 ,
struct V_138 * V_139 )
{
return - V_135 ;
}
static int F_69 ( struct V_8 * V_9 ,
const struct V_151 * V_84 )
{
int V_21 ;
struct V_17 * V_18 ;
struct V_92 * V_81 ;
V_6 V_152 ;
struct V_138 * V_153 = V_9 -> V_52 . V_153 ;
F_45 ( L_36 , V_9 -> V_37 ) ;
if ( ! V_9 -> V_83 ) {
F_14 ( & V_9 -> V_52 ,
L_37 ) ;
return - V_64 ;
}
if ( V_9 -> V_83 < 0 ) {
if ( V_9 -> V_83 != - V_154 )
F_14 ( & V_9 -> V_52 ,
L_38 ) ;
return V_9 -> V_83 ;
}
V_18 = F_31 ( sizeof( struct V_17 ) , V_96 ) ;
if ( ! V_18 )
return - V_101 ;
if ( V_9 -> V_52 . V_150 ) {
V_21 = F_67 ( V_9 , & V_18 -> V_139 ) ;
if ( V_21 )
goto V_155;
} else if ( ! V_153 ) {
V_21 = F_62 ( V_9 , & V_18 -> V_139 ) ;
if ( V_21 ) {
F_14 ( & V_9 -> V_52 ,
L_34 ) ;
goto V_155;
}
} else {
V_18 -> V_139 = * V_153 ;
}
F_70 ( V_9 , V_18 ) ;
V_18 -> V_9 = V_9 ;
V_152 = V_18 -> V_139 . V_147 ;
V_18 -> V_31 = F_71 ( V_152 ) ;
F_72 ( & V_18 -> V_26 ) ;
F_73 ( & V_18 -> V_73 ) ;
V_21 = F_38 ( V_18 , V_121 ) ;
if ( V_21 < 0 )
goto V_155;
F_74 ( & V_9 -> V_52 ) ;
F_75 ( & V_9 -> V_52 ) ;
F_76 ( & V_9 -> V_52 ) ;
F_77 ( & V_9 -> V_52 ) ;
V_21 = F_61 ( V_18 ) ;
if ( V_21 < 0 )
goto V_156;
V_21 = F_56 ( V_9 ) ;
if ( V_21 < 0 )
goto V_156;
V_81 = F_78 () ;
if ( F_79 ( V_81 ) ) {
V_21 = F_80 ( V_81 ) ;
goto V_157;
}
V_18 -> V_81 = V_81 ;
V_81 -> V_93 = V_9 ;
V_81 -> V_158 = & V_159 ;
V_81 -> V_52 . V_160 = & V_9 -> V_52 ;
V_81 -> V_161 = V_162 ;
V_81 -> V_163 = F_13 ( V_18 -> V_49 . V_136 ) ;
V_81 -> V_164 = F_13 ( V_18 -> V_49 . V_165 ) ;
V_81 -> V_166 = F_13 ( V_18 -> V_49 . V_167 ) ;
snprintf ( V_81 -> V_133 , sizeof( V_81 -> V_133 ) , L_39 ,
V_9 -> V_133 , V_81 -> V_164 , V_81 -> V_166 ) ;
F_81 ( V_81 -> V_168 , F_82 ( & V_9 -> V_52 ) , sizeof( V_81 -> V_168 ) ) ;
V_18 -> V_3 = F_1 ( V_81 -> V_164 , V_81 -> V_166 ) ;
V_21 = F_83 ( V_81 ) ;
if ( V_21 ) {
if ( V_21 != - V_135 )
F_47 ( V_9 , L_40 , V_21 ) ;
goto V_169;
}
F_34 ( & V_9 -> V_52 ) ;
return 0 ;
V_169:
F_84 ( V_81 ) ;
V_157:
F_85 ( V_9 -> V_83 , V_18 ) ;
V_156:
F_86 ( & V_9 -> V_52 ) ;
F_87 ( & V_9 -> V_52 ) ;
V_155:
F_37 ( V_18 ) ;
F_35 ( V_18 ) ;
return V_21 ;
}
static int F_88 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = F_3 ( V_9 ) ;
struct V_92 * V_81 ;
F_32 ( & V_9 -> V_52 ) ;
F_87 ( & V_9 -> V_52 ) ;
F_89 ( & V_9 -> V_52 ) ;
F_86 ( & V_9 -> V_52 ) ;
V_81 = V_18 -> V_81 ;
F_84 ( V_81 ) ;
F_85 ( V_9 -> V_83 , V_18 ) ;
if ( V_18 -> V_63 )
F_37 ( V_18 ) ;
F_35 ( V_18 ) ;
return 0 ;
}
static void F_90 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = F_3 ( V_9 ) ;
F_16 ( V_9 , V_76 ) ;
F_85 ( V_9 -> V_83 , V_18 ) ;
}
static int F_91 ( struct V_88 * V_52 )
{
struct V_8 * V_9 = F_92 ( V_52 ) ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
struct V_92 * V_81 = V_18 -> V_81 ;
int V_21 ;
int V_170 ;
if ( V_81 -> V_171 && V_81 -> V_171 -> V_172 ) {
V_21 = F_93 ( V_52 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = V_81 -> V_171 -> V_172 ( V_81 , V_173 ) ;
if ( V_21 < 0 )
return V_21 ;
}
if ( ! F_94 ( V_52 ) ) {
F_16 ( V_9 , V_76 ) ;
F_50 ( V_9 -> V_83 ) ;
}
if ( F_95 ( & V_9 -> V_52 ) ) {
V_170 = F_96 ( V_9 -> V_83 ) ;
if ( ! V_170 )
V_18 -> V_174 = true ;
else
F_97 ( V_81 , L_41 ,
V_170 ) ;
}
return 0 ;
}
static int F_98 ( struct V_88 * V_52 )
{
int V_21 ;
struct V_8 * V_9 = F_92 ( V_52 ) ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
struct V_92 * V_81 = V_18 -> V_81 ;
int V_170 ;
if ( F_95 ( & V_9 -> V_52 ) && V_18 -> V_174 ) {
V_170 = F_99 ( V_9 -> V_83 ) ;
if ( ! V_170 )
V_18 -> V_174 = false ;
else
F_97 ( V_81 , L_42 ,
V_170 ) ;
}
F_87 ( V_52 ) ;
F_75 ( V_52 ) ;
F_76 ( V_52 ) ;
F_51 ( V_9 -> V_83 ) ;
V_21 = F_17 ( V_9 ) ;
if ( V_21 )
return V_21 ;
if ( V_81 -> V_171 && V_81 -> V_171 -> V_175 ) {
V_21 = V_81 -> V_171 -> V_175 ( V_81 ) ;
return V_21 ;
}
return 0 ;
}
static int F_100 ( struct V_88 * V_52 )
{
struct V_8 * V_9 = F_92 ( V_52 ) ;
F_16 ( V_9 , V_76 ) ;
F_50 ( V_9 -> V_83 ) ;
return 0 ;
}
static int F_101 ( struct V_88 * V_52 )
{
struct V_8 * V_9 = F_92 ( V_52 ) ;
F_51 ( V_9 -> V_83 ) ;
F_16 ( V_9 , V_69 ) ;
return 0 ;
}
