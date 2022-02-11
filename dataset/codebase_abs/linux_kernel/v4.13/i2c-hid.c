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
static void F_28 ( struct V_91 * V_81 , unsigned int type ,
unsigned int * V_92 )
{
struct V_86 * V_87 ;
unsigned int V_61 ;
F_29 (report, &hid->report_enum[type].report_list, list) {
V_61 = F_27 ( V_87 ) ;
if ( * V_92 < V_61 )
* V_92 = V_61 ;
}
}
static void F_30 ( struct V_17 * V_18 )
{
F_31 ( V_18 -> V_79 ) ;
F_31 ( V_18 -> V_93 ) ;
F_31 ( V_18 -> V_54 ) ;
F_31 ( V_18 -> V_20 ) ;
V_18 -> V_79 = NULL ;
V_18 -> V_93 = NULL ;
V_18 -> V_20 = NULL ;
V_18 -> V_54 = NULL ;
V_18 -> V_63 = 0 ;
}
static int F_32 ( struct V_17 * V_18 , T_4 V_94 )
{
int V_14 = sizeof( V_95 ) +
sizeof( V_6 ) +
sizeof( V_6 ) +
V_94 ;
V_18 -> V_79 = F_33 ( V_94 , V_96 ) ;
V_18 -> V_93 = F_33 ( V_94 , V_96 ) ;
V_18 -> V_54 = F_33 ( V_14 , V_96 ) ;
V_18 -> V_20 = F_33 ( sizeof( union V_11 ) + V_14 , V_96 ) ;
if ( ! V_18 -> V_79 || ! V_18 -> V_93 || ! V_18 -> V_54 || ! V_18 -> V_20 ) {
F_30 ( V_18 ) ;
return - V_97 ;
}
V_18 -> V_63 = V_94 ;
return 0 ;
}
static int F_34 ( struct V_91 * V_81 ,
unsigned char V_98 , V_95 * V_41 , T_4 V_99 ,
unsigned char V_100 )
{
struct V_8 * V_9 = V_81 -> V_101 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
T_4 V_102 , V_103 ;
int V_21 ;
if ( V_100 == V_104 )
return - V_64 ;
V_103 = F_35 ( V_99 + 2 , ( T_4 ) V_18 -> V_63 ) ;
V_21 = F_12 ( V_9 ,
V_100 == V_105 ? 0x03 : 0x01 ,
V_98 , V_18 -> V_93 , V_103 ) ;
if ( V_21 < 0 )
return V_21 ;
V_102 = V_18 -> V_93 [ 0 ] | ( V_18 -> V_93 [ 1 ] << 8 ) ;
if ( V_102 <= 2 )
return 0 ;
V_102 = F_35 ( V_102 , V_103 ) ;
V_99 = F_35 ( V_99 , V_102 - 2 ) ;
memcpy ( V_41 , V_18 -> V_93 + 2 , V_99 ) ;
return V_99 ;
}
static int F_36 ( struct V_91 * V_81 , V_95 * V_41 ,
T_4 V_99 , unsigned char V_100 , bool V_53 )
{
struct V_8 * V_9 = V_81 -> V_101 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
int V_106 = V_41 [ 0 ] ;
int V_21 ;
if ( V_100 == V_82 )
return - V_64 ;
F_18 ( & V_18 -> V_73 ) ;
if ( V_106 ) {
V_41 ++ ;
V_99 -- ;
}
V_21 = F_15 ( V_9 ,
V_100 == V_105 ? 0x03 : 0x02 ,
V_106 , V_41 , V_99 , V_53 ) ;
if ( V_106 && V_21 >= 0 )
V_21 ++ ;
F_20 ( & V_18 -> V_73 ) ;
return V_21 ;
}
static int F_37 ( struct V_91 * V_81 , V_95 * V_41 ,
T_4 V_99 )
{
return F_36 ( V_81 , V_41 , V_99 , V_104 ,
false ) ;
}
static int F_38 ( struct V_91 * V_81 , unsigned char V_107 ,
V_95 * V_41 , T_4 V_40 , unsigned char V_108 ,
int V_109 )
{
switch ( V_109 ) {
case V_110 :
return F_34 ( V_81 , V_107 , V_41 , V_40 , V_108 ) ;
case V_111 :
if ( V_41 [ 0 ] != V_107 )
return - V_64 ;
return F_36 ( V_81 , V_41 , V_40 , V_108 , true ) ;
default:
return - V_46 ;
}
}
static int F_39 ( struct V_91 * V_81 )
{
struct V_8 * V_9 = V_81 -> V_101 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
struct V_112 * V_49 = & V_18 -> V_49 ;
unsigned int V_113 ;
char * V_114 ;
int V_21 ;
int V_115 = 3 ;
F_4 ( V_18 , L_13 , V_36 ) ;
V_113 = F_13 ( V_49 -> V_116 ) ;
if ( ! V_113 || V_113 > V_117 ) {
F_40 ( L_14 , V_113 ) ;
return - V_64 ;
}
do {
V_21 = F_17 ( V_9 ) ;
if ( V_21 )
F_41 ( 1000 ) ;
} while ( V_115 -- > 0 && V_21 );
if ( V_21 )
return V_21 ;
V_114 = F_33 ( V_113 , V_96 ) ;
if ( ! V_114 ) {
F_40 ( L_15 ) ;
return - V_97 ;
}
F_4 ( V_18 , L_16 ) ;
V_21 = F_11 ( V_9 , & V_118 , V_114 , V_113 ) ;
if ( V_21 ) {
F_42 ( V_81 , L_17 ) ;
F_31 ( V_114 ) ;
return - V_46 ;
}
F_4 ( V_18 , L_18 , V_113 , V_114 ) ;
V_21 = F_43 ( V_81 , V_114 , V_113 ) ;
F_31 ( V_114 ) ;
if ( V_21 ) {
F_40 ( L_19 ) ;
return V_21 ;
}
return 0 ;
}
static int F_44 ( struct V_91 * V_81 )
{
struct V_8 * V_9 = V_81 -> V_101 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
int V_21 ;
unsigned int V_63 = V_119 ;
F_28 ( V_81 , V_82 , & V_63 ) ;
F_28 ( V_81 , V_104 , & V_63 ) ;
F_28 ( V_81 , V_105 , & V_63 ) ;
if ( V_63 > V_18 -> V_63 ) {
F_45 ( V_9 -> V_83 ) ;
F_30 ( V_18 ) ;
V_21 = F_32 ( V_18 , V_63 ) ;
F_46 ( V_9 -> V_83 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static void F_47 ( struct V_91 * V_81 )
{
V_81 -> V_120 = 0 ;
}
static int F_48 ( struct V_91 * V_81 )
{
struct V_8 * V_9 = V_81 -> V_101 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
int V_21 = 0 ;
V_21 = F_49 ( & V_9 -> V_52 ) ;
if ( V_21 < 0 )
return V_21 ;
F_5 ( V_80 , & V_18 -> V_38 ) ;
return 0 ;
}
static void F_50 ( struct V_91 * V_81 )
{
struct V_8 * V_9 = V_81 -> V_101 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
F_7 ( V_80 , & V_18 -> V_38 ) ;
F_51 ( & V_9 -> V_52 ) ;
}
static int F_52 ( struct V_91 * V_81 , int V_121 )
{
struct V_8 * V_9 = V_81 -> V_101 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
F_4 ( V_18 , L_20 , V_36 , V_121 ) ;
switch ( V_121 ) {
case V_122 :
F_49 ( & V_9 -> V_52 ) ;
break;
case V_123 :
F_51 ( & V_9 -> V_52 ) ;
break;
}
return 0 ;
}
static int F_53 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = F_3 ( V_9 ) ;
unsigned long V_124 = 0 ;
int V_21 ;
F_54 ( & V_9 -> V_52 , L_21 , V_9 -> V_83 ) ;
if ( ! F_55 ( V_9 -> V_83 ) )
V_124 = V_125 ;
V_21 = F_56 ( V_9 -> V_83 , NULL , F_26 ,
V_124 | V_126 , V_9 -> V_127 , V_18 ) ;
if ( V_21 < 0 ) {
F_57 ( & V_9 -> V_52 ,
L_22
L_23 ,
V_9 -> V_127 , V_9 -> V_83 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
static int F_58 ( struct V_17 * V_18 )
{
struct V_8 * V_9 = V_18 -> V_9 ;
struct V_112 * V_49 = & V_18 -> V_49 ;
unsigned int V_128 ;
int V_21 ;
F_4 ( V_18 , L_24 ) ;
V_21 = F_11 ( V_9 , & V_28 , V_18 -> V_33 ,
sizeof( struct V_112 ) ) ;
if ( V_21 ) {
F_14 ( & V_9 -> V_52 , L_25 ) ;
return - V_129 ;
}
if ( F_13 ( V_49 -> V_130 ) != 0x0100 ) {
F_14 ( & V_9 -> V_52 ,
L_26 ,
F_13 ( V_49 -> V_130 ) ) ;
return - V_129 ;
}
V_128 = F_13 ( V_49 -> V_131 ) ;
if ( V_128 != sizeof( struct V_112 ) ) {
F_14 ( & V_9 -> V_52 , L_27 ,
V_128 ) ;
return - V_129 ;
}
F_4 ( V_18 , L_28 , V_128 , V_18 -> V_33 ) ;
return 0 ;
}
static int F_59 ( struct V_8 * V_9 ,
struct V_132 * V_133 )
{
static T_6 V_134 =
F_60 ( 0x3CDFF6F7 , 0x4267 , 0x4555 ,
0xAD , 0x05 , 0xB3 , 0x0A , 0x3D , 0x89 , 0x38 , 0xDE ) ;
union V_135 * V_136 ;
struct V_137 * V_138 ;
T_7 V_139 ;
V_139 = F_61 ( & V_9 -> V_52 ) ;
if ( ! V_139 || F_62 ( V_139 , & V_138 ) )
return - V_129 ;
V_136 = F_63 ( V_139 , & V_134 , 1 , 1 , NULL ,
V_140 ) ;
if ( ! V_136 ) {
F_14 ( & V_9 -> V_52 , L_29 ) ;
return - V_129 ;
}
V_133 -> V_141 = V_136 -> integer . V_142 ;
F_64 ( V_136 ) ;
return 0 ;
}
static void F_65 ( struct V_88 * V_52 )
{
T_7 V_139 = F_61 ( V_52 ) ;
struct V_137 * V_138 ;
if ( V_139 && F_62 ( V_139 , & V_138 ) == 0 )
F_66 ( V_138 ) ;
}
static inline int F_59 ( struct V_8 * V_9 ,
struct V_132 * V_133 )
{
return - V_129 ;
}
static inline void F_65 ( struct V_88 * V_52 ) {}
static int F_67 ( struct V_8 * V_9 ,
struct V_132 * V_133 )
{
struct V_88 * V_52 = & V_9 -> V_52 ;
T_1 V_143 ;
int V_21 ;
V_21 = F_68 ( V_52 -> V_144 , L_30 , & V_143 ) ;
if ( V_21 ) {
F_14 ( & V_9 -> V_52 , L_31 ) ;
return - V_129 ;
}
if ( V_143 >> 16 ) {
F_14 ( & V_9 -> V_52 , L_32 ,
V_143 ) ;
return - V_64 ;
}
V_133 -> V_141 = V_143 ;
V_21 = F_68 ( V_52 -> V_144 , L_33 ,
& V_143 ) ;
if ( ! V_21 )
V_133 -> V_145 = V_143 ;
return 0 ;
}
static inline int F_67 ( struct V_8 * V_9 ,
struct V_132 * V_133 )
{
return - V_129 ;
}
static int F_69 ( struct V_8 * V_9 ,
const struct V_146 * V_84 )
{
int V_21 ;
struct V_17 * V_18 ;
struct V_91 * V_81 ;
V_6 V_147 ;
struct V_132 * V_148 = V_9 -> V_52 . V_148 ;
F_40 ( L_34 , V_9 -> V_37 ) ;
if ( ! V_9 -> V_83 ) {
F_14 ( & V_9 -> V_52 ,
L_35 ) ;
return - V_64 ;
}
if ( V_9 -> V_83 < 0 ) {
if ( V_9 -> V_83 != - V_149 )
F_14 ( & V_9 -> V_52 ,
L_36 ) ;
return V_9 -> V_83 ;
}
V_18 = F_33 ( sizeof( struct V_17 ) , V_96 ) ;
if ( ! V_18 )
return - V_97 ;
if ( V_9 -> V_52 . V_144 ) {
V_21 = F_67 ( V_9 , & V_18 -> V_133 ) ;
if ( V_21 )
goto V_150;
} else if ( ! V_148 ) {
V_21 = F_59 ( V_9 , & V_18 -> V_133 ) ;
if ( V_21 ) {
F_14 ( & V_9 -> V_52 ,
L_31 ) ;
goto V_150;
}
} else {
V_18 -> V_133 = * V_148 ;
}
V_18 -> V_133 . V_151 = F_70 ( & V_9 -> V_52 , L_37 ) ;
if ( F_71 ( V_18 -> V_133 . V_151 ) ) {
V_21 = F_72 ( V_18 -> V_133 . V_151 ) ;
if ( V_21 != - V_149 )
F_14 ( & V_9 -> V_52 , L_38 ,
V_21 ) ;
goto V_150;
}
V_21 = F_73 ( V_18 -> V_133 . V_151 ) ;
if ( V_21 < 0 ) {
F_14 ( & V_9 -> V_52 , L_39 ,
V_21 ) ;
goto V_150;
}
if ( V_18 -> V_133 . V_145 )
F_41 ( V_18 -> V_133 . V_145 ) ;
F_74 ( V_9 , V_18 ) ;
V_18 -> V_9 = V_9 ;
V_147 = V_18 -> V_133 . V_141 ;
V_18 -> V_31 = F_75 ( V_147 ) ;
F_76 ( & V_18 -> V_26 ) ;
F_77 ( & V_18 -> V_73 ) ;
V_21 = F_32 ( V_18 , V_119 ) ;
if ( V_21 < 0 )
goto V_152;
F_65 ( & V_9 -> V_52 ) ;
F_78 ( & V_9 -> V_52 ) ;
F_79 ( & V_9 -> V_52 ) ;
F_80 ( & V_9 -> V_52 ) ;
F_81 ( & V_9 -> V_52 ) ;
V_21 = F_58 ( V_18 ) ;
if ( V_21 < 0 )
goto V_153;
V_21 = F_53 ( V_9 ) ;
if ( V_21 < 0 )
goto V_153;
V_81 = F_82 () ;
if ( F_71 ( V_81 ) ) {
V_21 = F_72 ( V_81 ) ;
goto V_154;
}
V_18 -> V_81 = V_81 ;
V_81 -> V_101 = V_9 ;
V_81 -> V_155 = & V_156 ;
V_81 -> V_52 . V_157 = & V_9 -> V_52 ;
V_81 -> V_158 = V_159 ;
V_81 -> V_160 = F_13 ( V_18 -> V_49 . V_130 ) ;
V_81 -> V_161 = F_13 ( V_18 -> V_49 . V_162 ) ;
V_81 -> V_163 = F_13 ( V_18 -> V_49 . V_164 ) ;
snprintf ( V_81 -> V_127 , sizeof( V_81 -> V_127 ) , L_40 ,
V_9 -> V_127 , V_81 -> V_161 , V_81 -> V_163 ) ;
F_83 ( V_81 -> V_165 , F_84 ( & V_9 -> V_52 ) , sizeof( V_81 -> V_165 ) ) ;
V_18 -> V_3 = F_1 ( V_81 -> V_161 , V_81 -> V_163 ) ;
V_21 = F_85 ( V_81 ) ;
if ( V_21 ) {
if ( V_21 != - V_129 )
F_42 ( V_9 , L_41 , V_21 ) ;
goto V_166;
}
F_51 ( & V_9 -> V_52 ) ;
return 0 ;
V_166:
F_86 ( V_81 ) ;
V_154:
F_87 ( V_9 -> V_83 , V_18 ) ;
V_153:
F_88 ( & V_9 -> V_52 ) ;
F_89 ( & V_9 -> V_52 ) ;
V_152:
F_90 ( V_18 -> V_133 . V_151 ) ;
V_150:
F_30 ( V_18 ) ;
F_31 ( V_18 ) ;
return V_21 ;
}
static int F_91 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = F_3 ( V_9 ) ;
struct V_91 * V_81 ;
F_49 ( & V_9 -> V_52 ) ;
F_89 ( & V_9 -> V_52 ) ;
F_92 ( & V_9 -> V_52 ) ;
F_88 ( & V_9 -> V_52 ) ;
V_81 = V_18 -> V_81 ;
F_86 ( V_81 ) ;
F_87 ( V_9 -> V_83 , V_18 ) ;
if ( V_18 -> V_63 )
F_30 ( V_18 ) ;
F_90 ( V_18 -> V_133 . V_151 ) ;
F_31 ( V_18 ) ;
return 0 ;
}
static void F_93 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = F_3 ( V_9 ) ;
F_16 ( V_9 , V_76 ) ;
F_87 ( V_9 -> V_83 , V_18 ) ;
}
static int F_94 ( struct V_88 * V_52 )
{
struct V_8 * V_9 = F_95 ( V_52 ) ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
struct V_91 * V_81 = V_18 -> V_81 ;
int V_21 ;
int V_167 ;
if ( V_81 -> V_168 && V_81 -> V_168 -> V_169 ) {
V_21 = F_96 ( V_52 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = V_81 -> V_168 -> V_169 ( V_81 , V_170 ) ;
if ( V_21 < 0 )
return V_21 ;
}
if ( ! F_97 ( V_52 ) ) {
F_16 ( V_9 , V_76 ) ;
F_45 ( V_9 -> V_83 ) ;
}
if ( F_98 ( & V_9 -> V_52 ) ) {
V_167 = F_99 ( V_9 -> V_83 ) ;
if ( ! V_167 )
V_18 -> V_171 = true ;
else
F_100 ( V_81 , L_42 ,
V_167 ) ;
} else {
V_21 = F_90 ( V_18 -> V_133 . V_151 ) ;
if ( V_21 < 0 )
F_100 ( V_81 , L_43 , V_21 ) ;
}
return 0 ;
}
static int F_101 ( struct V_88 * V_52 )
{
int V_21 ;
struct V_8 * V_9 = F_95 ( V_52 ) ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
struct V_91 * V_81 = V_18 -> V_81 ;
int V_167 ;
if ( ! F_98 ( & V_9 -> V_52 ) ) {
V_21 = F_73 ( V_18 -> V_133 . V_151 ) ;
if ( V_21 < 0 )
F_100 ( V_81 , L_44 , V_21 ) ;
if ( V_18 -> V_133 . V_145 )
F_41 ( V_18 -> V_133 . V_145 ) ;
} else if ( V_18 -> V_171 ) {
V_167 = F_102 ( V_9 -> V_83 ) ;
if ( ! V_167 )
V_18 -> V_171 = false ;
else
F_100 ( V_81 , L_45 ,
V_167 ) ;
}
F_89 ( V_52 ) ;
F_79 ( V_52 ) ;
F_80 ( V_52 ) ;
F_46 ( V_9 -> V_83 ) ;
V_21 = F_17 ( V_9 ) ;
if ( V_21 )
return V_21 ;
if ( V_81 -> V_168 && V_81 -> V_168 -> V_172 ) {
V_21 = V_81 -> V_168 -> V_172 ( V_81 ) ;
return V_21 ;
}
return 0 ;
}
static int F_103 ( struct V_88 * V_52 )
{
struct V_8 * V_9 = F_95 ( V_52 ) ;
F_16 ( V_9 , V_76 ) ;
F_45 ( V_9 -> V_83 ) ;
return 0 ;
}
static int F_104 ( struct V_88 * V_52 )
{
struct V_8 * V_9 = F_95 ( V_52 ) ;
F_46 ( V_9 -> V_83 ) ;
F_16 ( V_9 , V_69 ) ;
return 0 ;
}
