static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_3 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_5 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_7 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 == true )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_10 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 == true )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_13 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_15 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 == true ) {
F_17 ( V_16 , L_1
L_2 , V_17 ) ;
return 0 ;
}
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_18 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_20 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_9 -> V_14 == true )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_22 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_17 ( V_18 , L_3 ,
V_17 , * V_12 ) ;
V_9 -> V_19 = * V_12 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
F_9 ( & V_9 -> V_15 ) ;
F_17 ( V_18 , L_4 , V_17 ) ;
V_21 -> V_22 = true ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
struct V_23 * V_6 , char * V_12 )
{
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_24 * V_25 = (struct V_24 * )
( & ( V_9 -> V_10 -> V_26 ) ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
F_9 ( & V_9 -> V_15 ) ;
F_17 ( V_27 , L_5 , V_17 , ( * V_12 == 6 ) ?
L_6 : L_7 ) ;
if ( * V_12 || V_9 -> V_28 ) {
V_9 -> V_29 = false ;
V_25 -> V_30 = true ;
} else {
if ( V_9 -> V_10 -> V_31 == V_32 )
F_28 ( V_2 ) ;
V_9 -> V_29 = true ;
V_25 -> V_30 = false ;
V_21 -> V_33 = * V_12 ;
}
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_30 ( V_34 L_8 , V_17 , * V_12 ) ;
if ( ( * V_12 != 0 ) && ( * V_12 != 1 ) ) {
F_17 ( V_16 , L_9
L_10 , V_17 ) ;
F_11 ( & V_9 -> V_15 ) ;
return - 1 ;
}
V_9 -> V_35 = * V_12 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_24 * V_25 = (struct V_24 * )
( & ( V_9 -> V_10 -> V_26 ) ) ;
F_9 ( & V_9 -> V_15 ) ;
F_30 ( V_34 L_11 ,
V_17 , * V_12 ) ;
V_25 -> V_36 = * V_12 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_30 ( V_34 L_12
L_13 , V_17 , * V_12 ) ;
V_9 -> V_28 = * V_12 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_37 = * V_12 ;
if ( V_9 -> V_14 == true )
return 0 ;
F_30 ( V_34 L_14 , V_17 ,
* V_12 , V_38 ) ;
if ( V_37 > 0 )
V_38 |= ( 1 << V_37 ) ;
else
V_38 &= V_39 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = F_35 ( V_2 ) ;
enum V_40 V_41 ;
int V_13 ;
if ( V_9 -> V_14 == true )
return 0 ;
V_41 = V_9 -> V_10 -> V_42 ;
F_9 ( & V_9 -> V_15 ) ;
if ( V_6 -> V_43 == V_44 || V_6 -> V_43 == V_45 ||
V_21 -> V_46 ) {
if ( V_9 -> V_10 -> V_26 . V_47 ) {
if ( V_41 == V_48 ) {
if ( V_9 -> V_10 -> V_49 >
V_50 ) {
F_17 ( V_16 , L_15 ,
V_17 ) ;
F_11 ( & V_9 -> V_15 ) ;
return - 1 ;
} else {
F_30 ( V_34 L_16
L_17 , V_17 ) ;
F_9 ( & V_9 -> V_10 -> V_51 ) ;
F_36 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_51 ) ;
}
}
}
}
V_13 = F_37 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_52 * V_53 = (struct V_52 * ) V_12 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_2 V_54 ;
int V_55 ;
V_6 -> V_56 . V_57 = sizeof( * V_53 ) ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_58 = 130 * 1000 * 1000 ;
if ( V_9 -> V_59 != NULL ) {
V_53 -> V_60 = V_9 -> V_61 ;
}
V_53 -> V_62 . V_63 = 100 ;
V_53 -> V_62 . V_64 = 0 ;
V_53 -> V_62 . V_65 = 0 ;
V_53 -> V_62 . V_66 = 7 ;
V_53 -> V_67 . V_63 = 70 ;
V_53 -> V_67 . V_64 = 0 ;
V_53 -> V_67 . V_65 = 0 ;
V_53 -> V_67 . V_66 = 7 ;
V_53 -> V_68 = F_39 ( V_69 , V_70 ) ;
for ( V_55 = 0 ; V_55 < V_53 -> V_68 ; V_55 ++ )
V_53 -> V_71 [ V_55 ] = V_72 [ V_55 ] ;
V_53 -> V_73 = V_74 ;
V_53 -> V_75 = V_76 ;
V_53 -> V_77 = V_78 ;
V_53 -> V_79 = 0 ;
V_53 -> V_80 = 5000000 ;
V_53 -> V_81 = 0 ;
V_53 -> V_82 = 65535 * 1000 ;
V_53 -> V_83 = V_84 ;
V_53 -> V_85 = V_86 ;
V_53 -> V_87 = V_84 | V_86 | V_88 ;
V_53 -> V_89 = V_90 ;
V_53 -> V_91 = 18 ;
for ( V_55 = 0 , V_54 = 0 ; V_55 < 14 ; V_55 ++ ) {
if ( ( V_9 -> V_10 -> V_92 ) [ V_55 + 1 ] ) {
V_53 -> V_93 [ V_54 ] . V_55 = V_55 + 1 ;
V_53 -> V_93 [ V_54 ] . V_94 = V_95 [ V_55 ] *
100000 ;
V_53 -> V_93 [ V_54 ] . V_96 = 1 ;
V_54 ++ ;
}
if ( V_54 == V_97 )
break;
}
V_53 -> V_98 = V_54 ;
V_53 -> V_99 = V_54 ;
V_53 -> V_100 = V_101 | V_102 |
V_103 | V_104 ;
V_53 -> V_105 = V_106 | V_107 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
enum V_40 V_41 ;
int V_13 ;
if ( ! ( V_21 -> V_108 & V_109 ) ) {
if ( ( V_21 -> V_31 >= V_110 ) &&
( V_21 -> V_31 <= V_111 ) )
return 0 ;
if ( ( V_9 -> V_10 -> V_31 == V_32 ) &&
( V_9 -> V_10 -> V_112 < 2 ) )
return 0 ;
}
if ( V_9 -> V_14 == true ) {
F_30 ( V_34 L_18 ,
V_17 ) ;
return 0 ;
}
V_41 = V_9 -> V_10 -> V_42 ;
if ( ! V_9 -> F_11 )
return - V_113 ;
if ( V_9 -> V_10 -> V_114 . V_115 == true )
return - V_116 ;
if ( V_6 -> V_56 . V_117 & V_118 ) {
struct V_119 * V_120 = (struct V_119 * ) V_7 ;
if ( V_120 -> V_121 ) {
V_21 -> V_122 . V_123 = V_120 -> V_121 ;
memcpy ( V_21 -> V_122 . V_124 , V_120 -> V_125 ,
V_120 -> V_121 ) ;
}
}
F_9 ( & V_9 -> V_15 ) ;
V_9 -> V_10 -> V_126 = true ;
if ( V_9 -> V_10 -> V_31 != V_32 ) {
if ( V_9 -> V_10 -> V_26 . V_47 ) {
if ( V_41 == V_48 ) {
if ( V_9 -> V_10 -> V_49 >
V_50 ) {
F_17 ( V_16 , L_19
L_20 , V_17 ) ;
F_11 ( & V_9 -> V_15 ) ;
return - 1 ;
} else {
F_17 ( V_127 , L_16
L_17 , V_17 ) ;
F_9 ( & V_9 -> V_10 -> V_51 ) ;
F_36 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_51 ) ;
}
}
}
F_41 ( V_9 -> V_10 ) ;
if ( V_9 -> V_10 -> V_128 )
V_9 -> V_10 -> V_128 ( V_2 ,
V_129 ) ;
if ( V_9 -> V_10 -> V_42 != V_48 ) {
V_9 -> V_10 -> V_130 = true ;
if ( V_21 -> V_131 )
V_21 -> V_131 ( V_21 -> V_2 ,
V_132 ) ;
F_42 ( V_9 -> V_10 , 0 ) ;
if ( V_21 -> V_131 )
V_21 -> V_131 ( V_21 -> V_2 ,
V_133 ) ;
}
V_13 = 0 ;
} else {
V_9 -> V_10 -> V_130 = true ;
V_13 = F_43 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> F_11 )
return - V_113 ;
if ( V_9 -> V_14 == true )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_45 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( ( F_47 ( V_9 -> V_10 , false ) ) &&
! ( V_9 -> V_10 -> V_108 & V_109 ) ) {
;
}
if ( V_9 -> V_14 == true ) {
F_30 ( V_34 L_21
L_22 , V_17 ) ;
return 0 ;
}
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_48 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_50 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_6 -> V_56 . V_57 > V_134 )
return - V_135 ;
F_9 ( & V_9 -> V_15 ) ;
V_6 -> V_56 . V_57 = F_39 ( ( V_136 ) V_6 -> V_56 . V_57 , sizeof( V_9 -> V_137 ) ) ;
memset ( V_9 -> V_137 , 0 , sizeof( V_9 -> V_137 ) ) ;
memcpy ( V_9 -> V_137 , V_12 , V_6 -> V_56 . V_57 ) ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
V_6 -> V_56 . V_57 = strlen ( V_9 -> V_137 ) ;
memcpy ( V_12 , V_9 -> V_137 , V_6 -> V_56 . V_57 ) ;
V_6 -> V_56 . V_117 = 1 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 == true )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_54 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_56 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 == true )
return 0 ;
if ( V_6 -> V_138 . V_139 )
V_9 -> V_10 -> V_140 = V_141 ;
else {
if ( V_6 -> V_138 . V_142 < V_76 ||
V_6 -> V_138 . V_142 > V_78 )
return - V_143 ;
V_9 -> V_10 -> V_140 = V_6 -> V_138 . V_142 & ~ 0x1 ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_138 . V_142 = V_9 -> V_10 -> V_140 ;
V_6 -> V_138 . V_144 = 0 ;
V_6 -> V_138 . V_139 = ( V_6 -> V_138 . V_142 == V_141 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_145 ,
char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ( F_47 ( V_9 -> V_10 , false ) ) &&
! ( V_9 -> V_10 -> V_108 & V_109 ) ) {
;
}
if ( V_9 -> V_14 == true )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_60 ( V_9 -> V_10 , V_11 , V_145 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_62 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_146 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_64 ( V_9 -> V_10 , V_11 , V_6 , V_146 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_146 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
struct V_20 * V_21 = V_9 -> V_10 ;
T_3 V_147 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_148 = 0xff ;
T_3 V_149 = 0 ;
T_1 V_150 [ 4 ] [ 6 ] = { { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } } ;
int V_55 ;
if ( ( F_47 ( V_9 -> V_10 , false ) ) &&
! ( V_9 -> V_10 -> V_108 & V_109 ) )
;
if ( V_9 -> V_14 == true )
return 0 ;
if ( ! V_9 -> F_11 )
return - V_113 ;
V_9 -> V_10 -> V_151 = 1 ;
F_9 ( & V_9 -> V_10 -> V_51 ) ;
F_36 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_51 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_17 ( V_152 , L_23 ) ;
V_13 = F_66 ( V_9 -> V_10 , V_11 , V_6 , V_146 ) ;
F_11 ( & V_9 -> V_15 ) ;
if ( V_6 -> V_153 . V_117 & V_154 ) {
V_21 -> V_155 = V_21 -> V_156 = V_157 ;
F_67 ( V_2 ) ;
memset ( V_9 -> V_10 -> V_158 , 0 ,
sizeof( struct V_159 ) * 32 ) ;
goto V_160;
}
if ( V_6 -> V_153 . V_57 != 0 ) {
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
V_147 [ V_55 ] |= V_146 [ 4 * V_55 + 0 ] & V_148 ;
if ( V_55 == 1 && ( 4 * V_55 + 1 ) == V_6 -> V_153 . V_57 )
V_148 = 0x00 ;
if ( V_55 == 3 && ( 4 * V_55 + 1 ) == V_6 -> V_153 . V_57 )
V_148 = 0x00 ;
V_147 [ V_55 ] |= ( V_146 [ 4 * V_55 + 1 ] & V_148 ) << 8 ;
V_147 [ V_55 ] |= ( V_146 [ 4 * V_55 + 2 ] & V_148 ) << 16 ;
V_147 [ V_55 ] |= ( V_146 [ 4 * V_55 + 3 ] & V_148 ) << 24 ;
}
#define F_68 0x4
#define F_69 0x14
switch ( V_6 -> V_153 . V_117 & V_161 ) {
case 0 :
V_149 = V_21 -> V_162 ;
break;
case 1 :
V_149 = 0 ;
break;
case 2 :
V_149 = 1 ;
break;
case 3 :
V_149 = 2 ;
break;
case 4 :
V_149 = 3 ;
break;
default:
break;
}
if ( V_6 -> V_153 . V_57 == 0x5 ) {
V_21 -> V_155 = V_163 ;
F_70 ( V_2 ) ;
}
else if ( V_6 -> V_153 . V_57 == 0xd ) {
V_21 -> V_155 = V_164 ;
F_70 ( V_2 ) ;
F_71 ( V_2 , V_149 , V_149 , V_164 ,
V_150 [ V_149 ] , 0 , V_147 ) ;
F_72 ( V_2 , V_149 , V_149 , V_164 ,
V_150 [ V_149 ] , 0 , V_147 , 0 ) ;
} else {
F_30 ( V_34 L_24 ) ;
}
}
V_160:
V_9 -> V_10 -> V_151 = 0 ;
return V_13 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_3 * V_165 ,
union V_5 * V_6 , char * V_166 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int * V_167 = ( int * ) V_166 ;
int V_43 = V_167 [ 0 ] ;
if ( V_9 -> V_14 == true )
return 0 ;
V_9 -> V_10 -> V_168 = V_43 ;
return 1 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_169 = 0 ;
if ( V_9 -> V_14 == true )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
if ( V_6 -> V_170 . V_117 & V_171 ||
V_6 -> V_170 . V_139 ) {
V_169 = - V_143 ;
goto exit;
}
if ( ! ( V_6 -> V_170 . V_117 & V_172 ) ) {
V_169 = - V_143 ;
goto exit;
}
if ( V_6 -> V_170 . V_142 > V_173 ) {
V_169 = - V_143 ;
goto exit;
}
if ( V_6 -> V_170 . V_117 & V_174 ) {
V_9 -> V_175 = V_6 -> V_170 . V_142 ;
F_75 ( L_25 ,
V_6 -> V_170 . V_142 ) ;
} else {
V_9 -> V_176 = V_6 -> V_170 . V_142 ;
F_75 ( L_26 ,
V_6 -> V_170 . V_142 ) ;
}
F_76 ( V_2 ) ;
exit:
F_11 ( & V_9 -> V_15 ) ;
return V_169 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_170 . V_139 = 0 ;
if ( ( V_6 -> V_170 . V_117 & V_177 ) ==
V_171 )
return - V_143 ;
if ( V_6 -> V_170 . V_117 & V_174 ) {
V_6 -> V_170 . V_117 = V_172 & V_174 ;
V_6 -> V_170 . V_142 = V_9 -> V_175 ;
} else {
V_6 -> V_170 . V_117 = V_172 & V_178 ;
V_6 -> V_170 . V_142 = V_9 -> V_176 ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_59 == NULL )
return - 1 ;
V_6 -> V_179 . V_142 = V_9 -> V_179 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
short V_169 = 0 ;
if ( V_9 -> V_14 == true )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
if ( V_9 -> V_59 == NULL ) {
V_169 = - 1 ;
goto exit;
}
if ( V_9 -> V_59 ( V_2 , V_6 -> V_179 . V_142 ) == 0 )
V_9 -> V_179 = V_6 -> V_179 . V_142 ;
else
V_169 = - V_143 ;
exit:
F_11 ( & V_9 -> V_15 ) ;
return V_169 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
if ( V_9 -> V_14 == true )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_9 -> V_10 -> V_151 = 1 ;
F_9 ( & V_9 -> V_10 -> V_51 ) ;
F_36 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_51 ) ;
V_13 = F_81 ( V_21 , V_11 , V_6 , V_12 ) ;
{
T_1 V_180 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_1 V_181 [ 6 ] = { 0 } ;
T_3 V_146 [ 4 ] = { 0 } ;
struct V_182 * V_183 = (struct V_182 * ) V_12 ;
struct V_184 * V_153 = & V_6 -> V_153 ;
T_1 V_185 = 0 , V_186 = 0 , V_187 = 0 ;
if ( ( V_153 -> V_117 & V_154 ) ||
V_183 -> V_186 == V_188 ) {
V_21 -> V_155 = V_21 -> V_156
= V_157 ;
F_67 ( V_2 ) ;
memset ( V_9 -> V_10 -> V_158 , 0 ,
sizeof( struct V_159 ) * 32 ) ;
goto V_160;
}
V_186 = ( V_183 -> V_186 == V_189 ) ? V_190 :
V_183 -> V_186 ;
V_185 = V_153 -> V_117 & V_161 ;
if ( V_185 )
V_185 -- ;
V_187 = V_183 -> V_191 & V_192 ;
if ( ( ! V_187 ) || ( V_44 == V_21 -> V_193 ) ||
( V_186 == V_163 ) ) {
if ( ( V_183 -> V_194 == 13 ) && ( V_186 == V_163 ) )
V_186 = V_164 ;
V_21 -> V_155 = V_186 ;
F_70 ( V_2 ) ;
}
memcpy ( ( T_1 * ) V_146 , V_183 -> V_146 , 16 ) ;
if ( ( V_186 & V_163 ) && ( V_21 -> V_195 != 2 ) ) {
if ( V_183 -> V_194 == 13 )
V_21 -> V_155 = V_186 = V_164 ;
F_71 ( V_2 , V_185 , V_185 , V_186 , V_181 , 0 , V_146 ) ;
F_72 ( V_2 , V_185 , V_185 , V_186 , V_181 , 0 , V_146 , 0 ) ;
} else if ( V_187 ) {
V_21 -> V_156 = V_186 ;
F_71 ( V_2 , V_185 , V_185 , V_186 , V_180 , 0 , V_146 ) ;
F_72 ( V_2 , V_185 , V_185 , V_186 , V_180 , 0 ,
V_146 , 0 ) ;
} else {
if ( ( V_21 -> V_155 == V_190 ) &&
V_21 -> V_196 -> V_197 )
F_82 ( V_2 , 0x173 , 1 ) ;
F_71 ( V_2 , 4 , V_185 , V_186 , ( T_1 * ) V_21 -> V_198 ,
0 , V_146 ) ;
F_72 ( V_2 , 4 , V_185 , V_186 , ( T_1 * ) V_21 -> V_198 ,
0 , V_146 , 0 ) ;
}
}
V_160:
V_9 -> V_10 -> V_151 = 0 ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_56 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 == true )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_84 ( V_9 -> V_10 , V_11 , & ( V_56 -> V_199 ) , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 == true )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_86 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_56 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 == true )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_88 ( V_9 -> V_10 , V_12 , V_56 -> V_56 . V_57 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_56 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
if ( V_21 -> V_200 == 0 || V_21 -> V_201 == NULL ) {
V_56 -> V_56 . V_57 = 0 ;
return 0 ;
}
if ( V_56 -> V_56 . V_57 < V_21 -> V_200 )
return - V_135 ;
V_56 -> V_56 . V_57 = V_21 -> V_200 ;
memcpy ( V_12 , V_21 -> V_201 , V_21 -> V_200 ) ;
return V_13 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
T_3 * V_202 = ( T_3 * ) ( V_6 -> V_56 . V_203 ) ;
T_3 V_204 = V_202 [ 0 ] ;
T_3 V_205 = V_202 [ 1 ] ;
T_3 V_206 = V_202 [ 2 ] ;
if ( V_207 == V_204 ) {
V_21 -> V_208 . V_205 =
( V_205 ) ? ( true ) : ( false ) ;
V_21 -> V_208 . V_206 =
( V_206 ) ? ( true ) : ( false ) ;
( V_205 ) ?
( F_91 ( V_2 , false ) ) :
( F_92 ( V_2 , false ) ) ;
F_30 ( V_34 L_27 ,
V_17 , V_205 , V_206 ) ;
} else {
return - 1 ;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
F_9 ( & V_9 -> V_15 ) ;
snprintf ( V_12 , 45 , L_28 ,
V_21 -> V_208 . V_205 ,
V_21 -> V_208 . V_206 ) ;
V_6 -> V_56 . V_57 = strlen ( V_12 ) + 1 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static struct V_209 * F_94 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
struct V_209 * V_210 = & V_9 -> V_210 ;
int V_211 = 0 ;
int V_212 = 0 ;
int V_213 = 0 ;
if ( V_21 -> V_31 < V_32 ) {
V_210 -> V_63 . V_63 = 10 ;
V_210 -> V_63 . V_64 = 0 ;
V_210 -> V_63 . V_65 = - 100 ;
V_210 -> V_63 . V_66 = V_214 | V_215 ;
return V_210 ;
}
V_211 = ( & V_21 -> V_122 ) -> V_216 . V_217 ;
V_212 = ( & V_21 -> V_122 ) -> V_216 . signal ;
V_213 = ( & V_21 -> V_122 ) -> V_216 . V_65 ;
V_210 -> V_63 . V_64 = V_211 ;
V_210 -> V_63 . V_63 = V_212 ;
V_210 -> V_63 . V_65 = V_213 ;
V_210 -> V_63 . V_66 = V_214 | V_215 ;
return V_210 ;
}
