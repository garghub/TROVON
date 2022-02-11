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
const struct V_3 * V_47 = & V_48 ;
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
if ( V_5 >= 0x0F ) {
args [ V_55 ++ ] = V_5 ;
V_5 = 0x0F ;
}
if ( V_6 == 0x03 || V_52 == 0 ) {
args [ V_55 ++ ] = V_49 & 0xFF ;
args [ V_55 ++ ] = V_49 >> 8 ;
} else {
args [ V_55 ++ ] = V_50 & 0xFF ;
args [ V_55 ++ ] = V_50 >> 8 ;
V_47 = & V_56 ;
}
args [ V_55 ++ ] = V_54 & 0xFF ;
args [ V_55 ++ ] = V_54 >> 8 ;
if ( V_5 )
args [ V_55 ++ ] = V_5 ;
memcpy ( & args [ V_55 ] , V_34 , V_9 ) ;
V_14 = F_1 ( V_2 , V_47 , V_5 ,
V_6 , args , V_7 , NULL , 0 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_6 ) ;
return V_14 ;
}
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 , int V_57 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
F_3 ( V_11 , L_4 , V_29 ) ;
V_14 = F_1 ( V_2 , & V_58 , V_57 ,
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
V_14 = F_15 ( V_2 , V_59 ) ;
if ( V_14 )
return V_14 ;
F_3 ( V_11 , L_8 ) ;
V_14 = F_10 ( V_2 , & V_60 , NULL , 0 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_9 ) ;
F_15 ( V_2 , V_61 ) ;
return V_14 ;
}
return 0 ;
}
static void F_17 ( struct V_10 * V_11 )
{
int V_14 , V_62 ;
int V_54 = F_12 ( V_11 -> V_42 . V_63 ) ;
V_14 = F_18 ( V_11 -> V_2 , V_11 -> V_64 , V_54 ) ;
if ( V_14 != V_54 ) {
if ( V_14 < 0 )
return;
F_13 ( & V_11 -> V_2 -> V_45 , L_10 ,
V_29 , V_14 , V_54 ) ;
return;
}
V_62 = V_11 -> V_64 [ 0 ] | V_11 -> V_64 [ 1 ] << 8 ;
if ( ! V_62 ) {
if ( F_19 ( V_37 , & V_11 -> V_31 ) )
F_20 ( & V_11 -> V_19 ) ;
return;
}
if ( V_62 > V_54 ) {
F_13 ( & V_11 -> V_2 -> V_45 , L_11 ,
V_29 , V_54 , V_62 ) ;
return;
}
F_3 ( V_11 , L_12 , V_62 , V_11 -> V_64 ) ;
if ( F_8 ( V_65 , & V_11 -> V_31 ) )
F_21 ( V_11 -> V_66 , V_67 , V_11 -> V_64 + 2 ,
V_62 - 2 , 1 ) ;
return;
}
static T_4 F_22 ( int V_68 , void * V_69 )
{
struct V_10 * V_11 = V_69 ;
if ( F_8 ( V_36 , & V_11 -> V_31 ) )
return V_70 ;
F_17 ( V_11 ) ;
return V_70 ;
}
static int F_23 ( struct V_71 * V_72 )
{
return ( ( V_72 -> V_54 - 1 ) >> 3 ) + 1 +
V_72 -> V_73 -> V_74 [ V_72 -> type ] . V_75 + 2 ;
}
static void F_24 ( struct V_71 * V_72 , T_1 * V_76 ,
T_3 V_77 )
{
struct V_78 * V_66 = V_72 -> V_73 ;
struct V_1 * V_2 = V_66 -> V_79 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
unsigned int V_54 , V_62 ;
V_54 = F_23 ( V_72 ) ;
if ( F_11 ( V_2 ,
V_72 -> type == V_80 ? 0x03 : 0x01 ,
V_72 -> V_81 , V_76 , V_54 ) )
return;
F_3 ( V_11 , L_13 , V_54 , V_54 , V_11 -> V_64 ) ;
V_62 = V_76 [ 0 ] | ( V_76 [ 1 ] << 8 ) ;
if ( V_62 != V_54 ) {
F_13 ( & V_2 -> V_45 , L_14 ,
V_29 , V_54 , V_62 ) ;
return;
}
F_25 ( V_66 , V_72 -> type , V_76 + 2 , V_54 - 2 , 1 ) ;
}
static void F_26 ( struct V_78 * V_66 )
{
struct V_71 * V_72 ;
struct V_1 * V_2 = V_66 -> V_79 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_1 * V_64 = F_27 ( V_11 -> V_77 , V_82 ) ;
if ( ! V_64 ) {
F_13 ( & V_2 -> V_45 , L_15 ) ;
return;
}
F_28 (report,
&hid->report_enum[HID_FEATURE_REPORT].report_list, list)
F_24 ( V_72 , V_64 , V_11 -> V_77 ) ;
F_29 ( V_64 ) ;
}
static void F_30 ( struct V_78 * V_66 , unsigned int type ,
unsigned int * V_83 )
{
struct V_71 * V_72 ;
unsigned int V_54 ;
F_28 (report, &hid->report_enum[type].report_list, list) {
V_54 = F_23 ( V_72 ) ;
if ( * V_83 < V_54 )
* V_83 = V_54 ;
}
}
static void F_31 ( struct V_10 * V_11 )
{
F_29 ( V_11 -> V_64 ) ;
F_29 ( V_11 -> V_46 ) ;
F_29 ( V_11 -> V_13 ) ;
V_11 -> V_64 = NULL ;
V_11 -> V_13 = NULL ;
V_11 -> V_46 = NULL ;
V_11 -> V_77 = 0 ;
}
static int F_32 ( struct V_10 * V_11 , T_3 V_84 )
{
int V_7 = sizeof( V_85 ) +
sizeof( V_86 ) +
sizeof( V_86 ) +
V_84 ;
V_11 -> V_64 = F_27 ( V_84 , V_82 ) ;
V_11 -> V_46 = F_27 ( V_7 , V_82 ) ;
V_11 -> V_13 = F_27 ( sizeof( union V_4 ) + V_7 , V_82 ) ;
if ( ! V_11 -> V_64 || ! V_11 -> V_46 || ! V_11 -> V_13 ) {
F_31 ( V_11 ) ;
return - V_87 ;
}
V_11 -> V_77 = V_84 ;
return 0 ;
}
static int F_33 ( struct V_78 * V_66 ,
unsigned char V_88 , V_85 * V_34 , T_3 V_89 ,
unsigned char V_90 )
{
struct V_1 * V_2 = V_66 -> V_79 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_3 V_91 , V_92 ;
int V_14 ;
if ( V_90 == V_93 )
return - V_94 ;
V_92 = F_34 ( V_89 + 2 , ( T_3 ) V_11 -> V_77 ) ;
V_14 = F_11 ( V_2 ,
V_90 == V_80 ? 0x03 : 0x01 ,
V_88 , V_11 -> V_64 , V_92 ) ;
if ( V_14 < 0 )
return V_14 ;
V_91 = V_11 -> V_64 [ 0 ] | ( V_11 -> V_64 [ 1 ] << 8 ) ;
if ( V_91 <= 2 )
return 0 ;
V_91 = F_34 ( V_91 , V_92 ) ;
V_89 = F_34 ( V_89 , V_91 - 2 ) ;
memcpy ( V_34 , V_11 -> V_64 + 2 , V_89 ) ;
return V_89 ;
}
static int F_35 ( struct V_78 * V_66 , V_85 * V_34 ,
T_3 V_89 , unsigned char V_90 )
{
struct V_1 * V_2 = V_66 -> V_79 ;
int V_95 = V_34 [ 0 ] ;
int V_14 ;
if ( V_90 == V_67 )
return - V_94 ;
if ( V_95 ) {
V_34 ++ ;
V_89 -- ;
}
V_14 = F_14 ( V_2 ,
V_90 == V_80 ? 0x03 : 0x02 ,
V_95 , V_34 , V_89 ) ;
if ( V_95 && V_14 >= 0 )
V_14 ++ ;
return V_14 ;
}
static void F_36 ( struct V_78 * V_66 , struct V_71 * V_96 ,
int V_97 )
{
struct V_1 * V_2 = V_66 -> V_79 ;
char * V_34 ;
int V_14 ;
int V_33 = F_23 ( V_96 ) - 2 ;
V_34 = F_27 ( V_33 , V_82 ) ;
if ( ! V_34 )
return;
switch ( V_97 ) {
case V_98 :
V_14 = F_33 ( V_66 , V_96 -> V_81 , V_34 , V_33 , V_96 -> type ) ;
if ( V_14 < 0 )
F_13 ( & V_2 -> V_45 , L_16 ,
V_29 , V_14 ) ;
else
F_21 ( V_66 , V_96 -> type , V_34 , V_14 , 0 ) ;
break;
case V_99 :
F_37 ( V_96 , V_34 ) ;
F_35 ( V_66 , V_34 , V_33 , V_96 -> type ) ;
break;
}
F_29 ( V_34 ) ;
}
static int F_38 ( struct V_78 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_79 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_100 * V_42 = & V_11 -> V_42 ;
unsigned int V_101 ;
char * V_102 ;
int V_14 ;
int V_103 = 3 ;
F_3 ( V_11 , L_17 , V_29 ) ;
V_101 = F_12 ( V_42 -> V_104 ) ;
if ( ! V_101 || V_101 > V_105 ) {
F_39 ( L_18 , V_101 ) ;
return - V_94 ;
}
do {
V_14 = F_16 ( V_2 ) ;
if ( V_14 )
F_40 ( 1000 ) ;
} while ( V_103 -- > 0 && V_14 );
if ( V_14 )
return V_14 ;
V_102 = F_27 ( V_101 , V_82 ) ;
if ( ! V_102 ) {
F_39 ( L_19 ) ;
return - V_87 ;
}
F_3 ( V_11 , L_20 ) ;
V_14 = F_10 ( V_2 , & V_106 , V_102 , V_101 ) ;
if ( V_14 ) {
F_41 ( V_66 , L_21 ) ;
F_29 ( V_102 ) ;
return - V_39 ;
}
F_3 ( V_11 , L_22 , V_101 , V_102 ) ;
V_14 = F_42 ( V_66 , V_102 , V_101 ) ;
F_29 ( V_102 ) ;
if ( V_14 ) {
F_39 ( L_23 ) ;
return V_14 ;
}
return 0 ;
}
static int F_43 ( struct V_78 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_79 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
unsigned int V_77 = V_107 ;
F_30 ( V_66 , V_67 , & V_77 ) ;
F_30 ( V_66 , V_93 , & V_77 ) ;
F_30 ( V_66 , V_80 , & V_77 ) ;
if ( V_77 > V_11 -> V_77 ) {
F_31 ( V_11 ) ;
V_14 = F_32 ( V_11 , V_77 ) ;
if ( V_14 )
return V_14 ;
}
if ( ! ( V_66 -> V_108 & V_109 ) )
F_26 ( V_66 ) ;
return 0 ;
}
static void F_44 ( struct V_78 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_79 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
V_66 -> V_110 = 0 ;
F_31 ( V_11 ) ;
}
static int F_45 ( struct V_78 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_79 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 = 0 ;
F_46 ( & V_111 ) ;
if ( ! V_66 -> V_112 ++ ) {
V_14 = F_15 ( V_2 , V_59 ) ;
if ( V_14 ) {
V_66 -> V_112 -- ;
goto V_113;
}
F_4 ( V_65 , & V_11 -> V_31 ) ;
}
V_113:
F_47 ( & V_111 ) ;
return V_14 ;
}
static void F_48 ( struct V_78 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_79 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_46 ( & V_111 ) ;
if ( ! -- V_66 -> V_112 ) {
F_6 ( V_65 , & V_11 -> V_31 ) ;
F_15 ( V_2 , V_61 ) ;
}
F_47 ( & V_111 ) ;
}
static int F_49 ( struct V_78 * V_66 , int V_114 )
{
struct V_1 * V_2 = V_66 -> V_79 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 = 0 ;
F_3 ( V_11 , L_24 , V_29 , V_114 ) ;
switch ( V_114 ) {
case V_115 :
V_14 = F_15 ( V_2 , V_59 ) ;
break;
case V_116 :
V_14 = F_15 ( V_2 , V_61 ) ;
break;
}
return V_14 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_14 ;
F_51 ( & V_2 -> V_45 , L_25 , V_2 -> V_68 ) ;
V_14 = F_52 ( V_2 -> V_68 , NULL , F_22 ,
V_117 | V_118 ,
V_2 -> V_119 , V_11 ) ;
if ( V_14 < 0 ) {
F_53 ( & V_2 -> V_45 ,
L_26
L_27 ,
V_2 -> V_119 , V_2 -> V_68 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_54 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_100 * V_42 = & V_11 -> V_42 ;
unsigned int V_120 ;
int V_14 ;
V_14 = F_10 ( V_2 , & V_21 , V_11 -> V_26 , 4 ) ;
F_3 ( V_11 , L_28 , V_29 ,
V_11 -> V_26 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 ,
L_29 ,
V_14 ) ;
return - V_121 ;
}
V_120 = F_12 ( V_42 -> V_122 ) ;
if ( V_120 < 4 || V_120 > sizeof( struct V_100 ) ) {
F_13 ( & V_2 -> V_45 , L_30 ,
V_120 ) ;
return - V_121 ;
}
if ( F_12 ( V_42 -> V_123 ) != 0x0100 ) {
F_13 ( & V_2 -> V_45 ,
L_31 ,
F_12 ( V_42 -> V_123 ) ) ;
return - V_121 ;
}
F_3 ( V_11 , L_32 ) ;
V_14 = F_10 ( V_2 , & V_21 , V_11 -> V_26 ,
V_120 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_33 ) ;
return - V_121 ;
}
F_3 ( V_11 , L_34 , V_120 , V_11 -> V_26 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
static T_1 V_126 [] = {
0xF7 , 0xF6 , 0xDF , 0x3C , 0x67 , 0x42 , 0x55 , 0x45 ,
0xAD , 0x05 , 0xB3 , 0x0A , 0x3D , 0x89 , 0x38 , 0xDE ,
} ;
union V_127 V_128 [ 4 ] ;
struct V_129 V_130 ;
struct V_131 * V_132 ;
unsigned long long V_133 ;
T_5 V_134 ;
V_134 = F_56 ( & V_2 -> V_45 ) ;
if ( ! V_134 || F_57 ( V_134 , & V_132 ) )
return - V_121 ;
V_130 . V_89 = F_58 ( V_128 ) ;
V_130 . V_135 = V_128 ;
V_128 [ 0 ] . type = V_136 ;
V_128 [ 0 ] . V_76 . V_18 = sizeof( V_126 ) ;
V_128 [ 0 ] . V_76 . V_135 = V_126 ;
V_128 [ 1 ] . type = V_137 ;
V_128 [ 1 ] . integer . V_133 = 1 ;
V_128 [ 2 ] . type = V_137 ;
V_128 [ 2 ] . integer . V_133 = 1 ;
V_128 [ 3 ] . type = V_138 ;
V_128 [ 3 ] . V_139 . V_89 = 0 ;
V_128 [ 3 ] . V_139 . V_140 = NULL ;
if ( F_59 ( F_60 ( V_134 , L_35 , & V_130 ,
& V_133 ) ) ) {
F_13 ( & V_2 -> V_45 , L_36 ) ;
return - V_121 ;
}
V_125 -> V_141 = V_133 ;
return 0 ;
}
static inline int F_55 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
return - V_121 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
struct V_73 * V_45 = & V_2 -> V_45 ;
T_6 V_142 ;
int V_14 ;
V_14 = F_62 ( V_45 -> V_143 , L_37 , & V_142 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 , L_38 ) ;
return - V_121 ;
}
if ( V_142 >> 16 ) {
F_13 ( & V_2 -> V_45 , L_39 ,
V_142 ) ;
return - V_94 ;
}
V_125 -> V_141 = V_142 ;
return 0 ;
}
static inline int F_61 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
return - V_121 ;
}
static int F_63 ( struct V_1 * V_2 ,
const struct V_144 * V_69 )
{
int V_14 ;
struct V_10 * V_11 ;
struct V_78 * V_66 ;
V_86 V_145 ;
struct V_124 * V_146 = V_2 -> V_45 . V_146 ;
F_39 ( L_40 , V_2 -> V_30 ) ;
if ( ! V_2 -> V_68 ) {
F_13 ( & V_2 -> V_45 ,
L_41 ) ;
return - V_94 ;
}
V_11 = F_27 ( sizeof( struct V_10 ) , V_82 ) ;
if ( ! V_11 )
return - V_87 ;
if ( V_2 -> V_45 . V_143 ) {
V_14 = F_61 ( V_2 , & V_11 -> V_125 ) ;
if ( V_14 )
goto V_147;
} else if ( ! V_146 ) {
V_14 = F_55 ( V_2 , & V_11 -> V_125 ) ;
if ( V_14 ) {
F_13 ( & V_2 -> V_45 ,
L_38 ) ;
goto V_147;
}
} else {
V_11 -> V_125 = * V_146 ;
}
F_64 ( V_2 , V_11 ) ;
V_11 -> V_2 = V_2 ;
V_145 = V_11 -> V_125 . V_141 ;
V_11 -> V_24 = F_65 ( V_145 ) ;
F_66 ( & V_11 -> V_19 ) ;
V_14 = F_32 ( V_11 , V_107 ) ;
if ( V_14 < 0 )
goto V_147;
V_14 = F_54 ( V_11 ) ;
if ( V_14 < 0 )
goto V_147;
V_14 = F_50 ( V_2 ) ;
if ( V_14 < 0 )
goto V_147;
V_66 = F_67 () ;
if ( F_68 ( V_66 ) ) {
V_14 = F_69 ( V_66 ) ;
goto V_148;
}
V_11 -> V_66 = V_66 ;
V_66 -> V_79 = V_2 ;
V_66 -> V_149 = & V_150 ;
V_66 -> V_151 = F_33 ;
V_66 -> V_152 = F_35 ;
V_66 -> V_45 . V_153 = & V_2 -> V_45 ;
F_70 ( & V_66 -> V_45 , F_71 ( & V_2 -> V_45 ) ) ;
V_66 -> V_154 = V_155 ;
V_66 -> V_156 = F_12 ( V_11 -> V_42 . V_123 ) ;
V_66 -> V_157 = F_12 ( V_11 -> V_42 . V_158 ) ;
V_66 -> V_159 = F_12 ( V_11 -> V_42 . V_160 ) ;
snprintf ( V_66 -> V_119 , sizeof( V_66 -> V_119 ) , L_42 ,
V_2 -> V_119 , V_66 -> V_157 , V_66 -> V_159 ) ;
V_14 = F_72 ( V_66 ) ;
if ( V_14 ) {
if ( V_14 != - V_121 )
F_41 ( V_2 , L_43 , V_14 ) ;
goto V_161;
}
return 0 ;
V_161:
F_73 ( V_66 ) ;
V_148:
F_74 ( V_2 -> V_68 , V_11 ) ;
V_147:
F_31 ( V_11 ) ;
F_29 ( V_11 ) ;
return V_14 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_78 * V_66 ;
V_66 = V_11 -> V_66 ;
F_73 ( V_66 ) ;
F_74 ( V_2 -> V_68 , V_11 ) ;
if ( V_11 -> V_77 )
F_31 ( V_11 ) ;
F_29 ( V_11 ) ;
return 0 ;
}
static int F_76 ( struct V_73 * V_45 )
{
struct V_1 * V_2 = F_77 ( V_45 ) ;
if ( F_78 ( & V_2 -> V_45 ) )
F_79 ( V_2 -> V_68 ) ;
F_15 ( V_2 , V_61 ) ;
return 0 ;
}
static int F_80 ( struct V_73 * V_45 )
{
int V_14 ;
struct V_1 * V_2 = F_77 ( V_45 ) ;
V_14 = F_16 ( V_2 ) ;
if ( V_14 )
return V_14 ;
if ( F_78 ( & V_2 -> V_45 ) )
F_81 ( V_2 -> V_68 ) ;
return 0 ;
}
