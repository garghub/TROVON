static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_2 V_5 , T_2 V_6 , T_1 V_7 )
{
int V_8 ;
if ( ( V_8 = F_2 ( V_2 , V_4 , ( T_2 ) ( V_7 & 0xff ) ) ) )
return V_8 ;
return F_3 ( V_2 , V_3 , V_5 , V_6 ,
( T_2 ) ( ( V_7 & 0x300 ) >> 8 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_2 V_5 , T_2 V_6 , T_1 * V_7 )
{
int V_8 ;
T_2 V_9 , V_10 ;
if ( ( V_8 = F_5 ( V_2 , V_4 , & V_9 ) ) )
return V_8 ;
if ( ( V_8 = F_5 ( V_2 , V_3 , & V_10 ) ) )
return V_8 ;
switch ( V_5 ) {
case 0 :
* V_7 = ( ( T_1 ) ( V_10 & 0x03 ) << 8 ) + ( T_1 ) V_9 ;
break;
case 2 :
* V_7 = ( ( T_1 ) ( V_10 & 0x0C ) << 6 ) + ( T_1 ) V_9 ;
break;
case 4 :
* V_7 = ( ( T_1 ) ( V_10 & 0x30 ) << 4 ) + ( T_1 ) V_9 ;
break;
case 6 :
* V_7 = ( ( T_1 ) ( V_10 & 0xC0 ) << 2 ) + ( T_1 ) V_9 ;
break;
default:
F_6 ( L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_7 ( struct V_12 * V_13 , int * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
int V_8 ;
T_2 V_18 ;
* V_14 = false ;
V_8 = F_8 ( V_16 -> V_2 , V_19 ,
V_20 ,
V_21 , & V_18 ) ;
if ( V_8 )
return V_8 ;
if ( V_18 & 1 ) {
V_8 =
F_8 ( V_16 -> V_2 ,
V_22 ,
V_23 ,
V_24 , & V_18 ) ;
if ( V_8 )
return V_8 ;
if ( ( V_18 & 1 ) == 0 )
* V_14 = true ;
}
return 0 ;
}
static int F_9 ( struct V_12 * V_13 ,
T_3 * V_25 ,
T_3 * V_26 ,
T_1 * V_27 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
int V_8 ;
T_3 V_28 ;
T_3 V_29 ;
T_2 V_18 , V_9 , V_10 , V_30 ;
T_1 V_31 ;
* V_25 = 0 ;
* V_26 = 0 ;
V_8 =
F_8 ( V_16 -> V_2 , V_32 ,
V_33 , V_34 ,
& V_18 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_18 ) {
F_10 ( L_2 ) ;
return 100 ;
}
V_8 =
F_5 ( V_16 -> V_2 ,
V_35 ,
& V_9 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_5 ( V_16 -> V_2 ,
V_36 ,
& V_10 ) ;
if ( V_8 )
return V_8 ;
V_31 = ( ( T_1 ) V_10 << 8 ) + V_9 ;
V_8 =
F_5 ( V_16 -> V_2 , V_37 ,
& V_9 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_5 ( V_16 -> V_2 , V_38 ,
& V_10 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_5 ( V_16 -> V_2 , V_39 ,
& V_30 ) ;
if ( V_8 )
return V_8 ;
V_28 = ( ( T_3 ) V_30 << 16 ) + ( ( T_3 ) V_10 << 8 ) + V_9 ;
* V_25 = V_28 - ( T_3 ) V_31 * 8 * 8 ;
V_8 =
F_5 ( V_16 -> V_2 , V_40 ,
& V_9 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_5 ( V_16 -> V_2 , V_41 ,
& V_10 ) ;
if ( V_8 )
return V_8 ;
V_29 = ( ( T_3 ) V_10 << 8 ) + V_9 ;
if ( V_29 == 0 ) {
F_6 ( L_3 ) ;
return - V_42 ;
}
F_10 ( L_4 ,
V_31 , V_28 , V_29 ) ;
* V_26 = V_29 - ( T_3 ) V_31 ;
* V_27 = V_31 ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 ,
T_3 * V_25 , T_3 * V_26 ,
T_1 * V_27 )
{
T_3 V_43 = 0 , V_44 ;
T_1 V_31 = 0 ;
int V_8 ;
V_8 =
F_9 ( V_13 , & V_44 , & V_43 ,
& V_31 ) ;
if ( V_8 )
return V_8 ;
* V_25 = V_44 ;
* V_26 = V_43 * 204 * 8 ;
* V_27 = V_31 ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 ,
T_3 * V_45 ,
T_3 * V_46 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
T_2 V_18 , V_9 , V_10 , V_30 ;
T_3 V_47 , V_48 , V_49 ;
int V_8 ;
V_8 =
F_8 ( V_16 -> V_2 , V_50 ,
V_51 , V_52 ,
& V_18 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_18 ) {
F_10 ( L_5 ) ;
return 101 ;
}
V_8 =
F_5 ( V_16 -> V_2 , V_53 ,
& V_9 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_5 ( V_16 -> V_2 , V_54 ,
& V_10 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_5 ( V_16 -> V_2 , V_55 ,
& V_30 ) ;
if ( V_8 )
return V_8 ;
* V_45 = ( ( T_3 ) V_30 << 16 ) + ( ( T_3 ) V_10 << 8 ) + V_9 ;
V_8 =
F_5 ( V_16 -> V_2 , V_56 ,
& V_9 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_5 ( V_16 -> V_2 , V_57 ,
& V_10 ) ;
if ( V_8 )
return V_8 ;
V_47 = ( ( T_3 ) V_10 << 8 ) + V_9 ;
if ( V_47 == 0 ) {
F_10 ( L_6 ) ;
return 102 ;
}
V_8 =
F_8 ( V_16 -> V_2 , V_58 ,
V_59 , V_60 ,
& V_18 ) ;
if ( V_8 )
return V_8 ;
if ( V_18 == 0 ) {
V_48 = 1512 ;
} else if ( V_18 == 1 ) {
V_48 = 6048 ;
} else {
F_6 ( L_7 ) ;
return - V_11 ;
}
V_8 =
F_8 ( V_16 -> V_2 , V_61 ,
V_62 , V_63 ,
& V_18 ) ;
if ( V_8 )
return V_8 ;
switch ( V_18 ) {
case 0 :
V_49 = 2 ;
break;
case 1 :
V_49 = 4 ;
break;
case 2 :
V_49 = 6 ;
break;
default:
F_6 ( L_8 ) ;
return - V_11 ;
}
* V_46 = V_47 * 68 * 4 * V_48 * V_49 ;
F_10 ( L_9 ,
* V_45 , V_47 , * V_46 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
int V_8 ;
V_8 =
F_2 ( V_16 -> V_2 , V_56 ,
1 & 0xff ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_16 -> V_2 , V_57 ,
1 >> 8 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_3 ( V_16 -> V_2 , V_64 ,
V_65 , V_66 ,
1 ) ;
return V_8 ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
int V_8 ;
V_8 =
F_2 ( V_16 -> V_2 , V_40 ,
10000 & 0xff ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_2 ( V_16 -> V_2 , V_41 ,
10000 >> 8 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_3 ( V_16 -> V_2 , V_67 ,
V_68 , V_69 ,
1 ) ;
return V_8 ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
int V_8 , V_70 ;
T_4 V_71 , V_72 ;
F_10 ( L_10 ) ;
V_8 = F_7 ( V_13 , & V_70 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_70 ) {
F_10 ( L_11 ) ;
return 0 ;
}
V_8 = F_12 ( V_13 , & V_16 -> V_73 ,
& V_16 -> V_74 ) ;
if ( V_8 == 0 ) {
F_13 ( V_13 ) ;
if ( V_16 -> V_74 > 0 ) {
V_71 =
( T_4 ) V_16 -> V_73 * ( T_4 ) 1000000000 ;
V_72 = ( T_4 ) V_16 -> V_74 ;
V_16 -> V_75 = F_16 ( V_71 , V_72 ) ;
} else {
V_16 -> V_75 = 0xffffffff ;
}
}
V_8 = F_11 ( V_13 , & V_16 -> V_76 ,
& V_16 -> V_77 ,
& V_16 -> V_27 ) ;
if ( V_8 == 0 ) {
V_8 = F_14 ( V_13 ) ;
V_16 -> V_78 += V_16 -> V_27 ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
if ( F_18 ( V_79 , V_16 -> V_80 ) ) {
F_10 ( L_12 ) ;
if ( F_15 ( V_13 ) )
F_6 ( L_13 ) ;
V_16 -> V_80 = V_79 + 250 * V_81 / 1000 ;
}
return 0 ;
}
static int F_19 ( struct V_12 * V_13 ,
enum V_82 * V_83 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
T_2 V_18 ;
int V_8 ;
if ( V_13 -> V_84 . V_85 . V_86 == NULL )
return - V_87 ;
* V_83 = 0 ;
V_8 = F_8 ( V_16 -> V_2 , V_88 ,
V_89 , V_90 , & V_18 ) ;
if ( V_8 )
return V_8 ;
if ( V_18 )
* V_83 |= V_91 ;
V_8 = F_8 ( V_16 -> V_2 , V_92 ,
V_93 , V_94 ,
& V_18 ) ;
if ( V_8 )
return V_8 ;
if ( V_18 )
* V_83 |= V_95 ;
V_8 = F_8 ( V_16 -> V_2 ,
V_96 ,
V_97 ,
V_97 , & V_18 ) ;
if ( V_8 )
return V_8 ;
if ( V_18 )
* V_83 |= V_98 | V_99 | V_100 ;
if ( V_16 -> V_101 )
F_20 ( V_16 -> V_2 , * V_83 & V_100 ) ;
V_8 =
F_8 ( V_16 -> V_2 , V_102 ,
V_103 ,
V_104 , & V_18 ) ;
if ( V_8 )
return V_8 ;
if ( V_18 != V_16 -> V_105 ) {
F_10 ( L_14 , V_18 ) ;
V_16 -> V_105 = V_18 ;
}
return 0 ;
}
static int F_21 ( struct V_12 * V_13 , T_3 * V_75 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
if ( V_13 -> V_84 . V_85 . V_86 == NULL )
return - V_87 ;
F_17 ( V_13 ) ;
* V_75 = V_16 -> V_75 ;
return 0 ;
}
static int F_22 ( struct V_12 * V_13 , T_3 * V_78 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
if ( V_13 -> V_84 . V_85 . V_86 == NULL )
return - V_87 ;
F_17 ( V_13 ) ;
* V_78 = V_16 -> V_78 ;
return 0 ;
}
static int F_23 ( struct V_12 * V_13 ,
T_1 * V_106 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
int V_8 ;
T_2 V_107 , V_108 ;
if ( V_13 -> V_84 . V_85 . V_86 == NULL )
return - V_87 ;
V_8 =
F_5 ( V_16 -> V_2 , V_109 ,
& V_108 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_5 ( V_16 -> V_2 , V_110 ,
& V_107 ) ;
if ( V_8 )
return V_8 ;
* V_106 = ( 512 - V_108 - V_107 ) << 7 ;
return 0 ;
}
static int F_24 ( struct V_12 * V_13 , T_1 * V_111 )
{
return - V_112 ;
}
static int F_25 ( struct V_1 * V_2 , T_3 V_113 )
{
T_2 V_9 , V_10 , V_30 , V_114 , V_115 [ 4 ] ;
int V_8 ;
T_3 V_116 ;
T_3 V_117 ;
T_3 V_118 ;
T_3 V_119 ;
T_3 V_120 ;
T_3 V_121 ;
switch ( V_113 ) {
case 6000000 :
V_116 = 0x2ADB6DC ;
V_117 = 0xAB7313 ;
V_118 = 0xAB6DB7 ;
V_119 = 0xAB685C ;
V_120 = 0x156DB6E ;
V_121 = 0x55B6DC ;
break;
case 7000000 :
V_116 = 0x3200001 ;
V_117 = 0xC80640 ;
V_118 = 0xC80000 ;
V_119 = 0xC7F9C0 ;
V_120 = 0x1900000 ;
V_121 = 0x640000 ;
break;
case 8000000 :
V_116 = 0x3924926 ;
V_117 = 0xE4996E ;
V_118 = 0xE49249 ;
V_119 = 0xE48B25 ;
V_120 = 0x1C92493 ;
V_121 = 0x724925 ;
break;
default:
F_6 ( L_15 , V_113 ) ;
return - V_11 ;
}
V_9 = ( T_2 ) ( V_116 & 0x000000FF ) ;
V_10 = ( T_2 ) ( ( V_116 & 0x0000FF00 ) >> 8 ) ;
V_30 = ( T_2 ) ( ( V_116 & 0x00FF0000 ) >> 16 ) ;
V_114 = ( T_2 ) ( ( V_116 & 0x03000000 ) >> 24 ) ;
V_115 [ 0 ] = V_114 ;
V_115 [ 1 ] = V_30 ;
V_115 [ 2 ] = V_10 ;
V_115 [ 3 ] = V_9 ;
V_8 = F_2 ( V_2 , 0xAE00 , V_115 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE01 , V_115 [ 1 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE02 , V_115 [ 2 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE03 , V_115 [ 3 ] ) ;
if ( V_8 )
return V_8 ;
V_9 = ( T_2 ) ( ( V_120 & 0x0000003F ) ) ;
V_10 = ( T_2 ) ( ( V_120 & 0x00003FC0 ) >> 6 ) ;
V_30 = ( T_2 ) ( ( V_120 & 0x003FC000 ) >> 14 ) ;
V_114 = ( T_2 ) ( ( V_120 & 0x01C00000 ) >> 22 ) ;
V_115 [ 0 ] = V_114 ;
V_115 [ 1 ] = V_30 ;
V_115 [ 2 ] = V_10 ;
V_115 [ 3 ] = V_9 ;
V_8 = F_2 ( V_2 , 0xAE04 , V_115 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE05 , V_115 [ 1 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE06 , V_115 [ 2 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE07 , V_115 [ 3 ] ) ;
if ( V_8 )
return V_8 ;
V_9 = ( T_2 ) ( ( V_117 & 0x000000FF ) ) ;
V_10 = ( T_2 ) ( ( V_117 & 0x0000FF00 ) >> 8 ) ;
V_30 = ( T_2 ) ( ( V_117 & 0x00FFC000 ) >> 16 ) ;
V_114 = ( T_2 ) ( ( V_117 & 0x03000000 ) >> 24 ) ;
V_115 [ 0 ] = V_114 ;
V_115 [ 1 ] = V_30 ;
V_115 [ 2 ] = V_10 ;
V_115 [ 3 ] = V_9 ;
V_8 = F_2 ( V_2 , 0xAE08 , V_115 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE09 , V_115 [ 1 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE0A , V_115 [ 2 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE0B , V_115 [ 3 ] ) ;
if ( V_8 )
return V_8 ;
V_9 = ( T_2 ) ( V_118 & 0x000000FF ) ;
V_10 = ( T_2 ) ( ( V_118 & 0x0000FF00 ) >> 8 ) ;
V_30 = ( T_2 ) ( ( V_118 & 0x00FFC000 ) >> 16 ) ;
V_114 = ( T_2 ) ( ( V_118 & 0x03000000 ) >> 24 ) ;
V_115 [ 0 ] = V_114 ;
V_115 [ 1 ] = V_30 ;
V_115 [ 2 ] = V_10 ;
V_115 [ 3 ] = V_9 ;
V_8 = F_2 ( V_2 , 0xAE0C , V_115 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE0D , V_115 [ 1 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE0E , V_115 [ 2 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE0F , V_115 [ 3 ] ) ;
if ( V_8 )
return V_8 ;
V_9 = ( T_2 ) ( ( V_119 & 0x000000FF ) ) ;
V_10 = ( T_2 ) ( ( V_119 & 0x0000FF00 ) >> 8 ) ;
V_30 = ( T_2 ) ( ( V_119 & 0x00FFC000 ) >> 16 ) ;
V_114 = ( T_2 ) ( ( V_119 & 0x03000000 ) >> 24 ) ;
V_115 [ 0 ] = V_114 ;
V_115 [ 1 ] = V_30 ;
V_115 [ 2 ] = V_10 ;
V_115 [ 3 ] = V_9 ;
V_8 = F_2 ( V_2 , 0xAE10 , V_115 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE11 , V_115 [ 1 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE12 , V_115 [ 2 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE13 , V_115 [ 3 ] ) ;
if ( V_8 )
return V_8 ;
V_9 = ( T_2 ) ( ( V_121 & 0x0000003F ) ) ;
V_10 = ( T_2 ) ( ( V_121 & 0x00003FC0 ) >> 6 ) ;
V_30 = ( T_2 ) ( ( V_121 & 0x003FC000 ) >> 14 ) ;
V_114 = ( T_2 ) ( ( V_121 & 0x01C00000 ) >> 22 ) ;
V_115 [ 0 ] = V_114 ;
V_115 [ 1 ] = V_30 ;
V_115 [ 2 ] = V_10 ;
V_115 [ 3 ] = V_9 ;
V_8 = F_2 ( V_2 , 0xAE14 , V_115 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE15 , V_115 [ 1 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE16 , V_115 [ 2 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_2 , 0xAE17 , V_115 [ 3 ] ) ;
return V_8 ;
}
static int F_26 ( struct V_1 * V_2 , T_3 V_113 )
{
T_2 V_18 ;
switch ( V_113 ) {
case 6000000 :
V_18 = 0 ;
break;
case 7000000 :
V_18 = 1 ;
break;
case 8000000 :
V_18 = 2 ;
break;
default:
F_6 ( L_15 , V_113 ) ;
return - V_11 ;
}
return F_3 ( V_2 , V_122 , V_123 ,
V_124 , V_18 ) ;
}
static int F_27 ( struct V_12 * V_13 , int V_125 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
T_2 V_18 = V_125 ;
int V_8 ;
F_10 ( L_16 , V_125 ? L_17 : L_18 ) ;
V_8 = F_28 ( V_16 -> V_2 , 0x03 , & V_18 , 1 , NULL , 0 ) ;
return V_8 ;
}
static int F_29 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_126 * V_127 = V_13 -> V_128 -> V_129 ;
int V_8 , V_130 , V_131 ;
T_2 V_18 , V_9 = 0 , V_10 = 0 , V_30 = 0 ;
T_2 V_115 [ 2 ] ;
T_1 V_132 ;
F_10 ( L_19 ) ;
F_10 ( L_20 ) ;
if ( ( V_8 =
F_3 ( V_16 -> V_2 , V_133 ,
4 , 1 , 0x01 ) ) )
return V_8 ;
if ( ( V_8 = F_2 ( V_16 -> V_2 , V_134 , 0 ) ) )
return V_8 ;
F_10 ( L_21 ) ;
for ( V_130 = 0 ; V_130 < 150 ; V_130 ++ ) {
if ( ( V_8 =
F_5 ( V_16 -> V_2 ,
V_135 , & V_18 ) ) )
return V_8 ;
if ( V_18 & ( V_136 [ V_137 - 1 ] << V_138 ) )
break;
F_30 ( 10 ) ;
}
if ( V_130 == 150 )
return - V_139 ;
V_8 = F_2 ( V_16 -> V_2 , 0xb200 , 0xa9 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_16 -> V_2 , V_140 , 0x07 ) ;
if ( V_8 )
return V_8 ;
V_18 = 0x01 ;
V_8 = F_28 ( V_16 -> V_2 , 0x03 , & V_18 , 1 , NULL , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_16 -> V_2 , V_140 , 0x00 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_16 -> V_2 , 0xb200 , 0xa1 ) ;
if ( V_8 )
return V_8 ;
V_18 = V_136 [ V_137 - 1 ] << V_138 ;
if ( ( V_8 =
F_3 ( V_16 -> V_2 , V_135 ,
V_138 , V_137 , 1 ) ) )
return V_8 ;
V_8 = F_3 ( V_16 -> V_2 , V_135 ,
V_138 , V_137 , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_16 -> V_2 , 0xaefc , 0 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_22 ) ;
if ( ( V_8 =
F_3 ( V_16 -> V_2 , V_141 ,
V_142 ,
V_143 , 1 ) ) )
return V_8 ;
F_10 ( L_23 ) ;
if ( ( V_8 =
F_3 ( V_16 -> V_2 , V_144 ,
V_145 ,
V_146 , 0 ) ) )
return V_8 ;
if ( ( V_8 =
F_3 ( V_16 -> V_2 , V_147 ,
V_148 ,
V_149 , 0 ) ) )
return V_8 ;
F_10 ( L_24 ) ;
if ( ( V_8 =
F_2 ( V_16 -> V_2 , V_150 , 0x14 ) ) )
return V_8 ;
F_10 ( L_25 ) ;
if ( ( V_8 =
F_3 ( V_16 -> V_2 , V_151 ,
V_152 , V_153 , 0 ) ) )
return V_8 ;
V_8 = F_2 ( V_16 -> V_2 , 0xa16c , 1 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_16 -> V_2 , 0xa3c1 , 0 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_26 ) ;
V_8 = F_25 ( V_16 -> V_2 , 6000000 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_27 ) ;
if ( ( V_8 =
F_3 ( V_16 -> V_2 , V_154 ,
V_155 ,
V_156 , 1 ) ) )
return V_8 ;
F_10 ( L_28 ) ;
if ( ( V_8 =
F_3 ( V_16 -> V_2 , V_157 ,
V_158 ,
V_159 , 1 ) ) )
return V_8 ;
F_10 ( L_29 ) ;
if ( ( V_8 =
F_3 ( V_16 -> V_2 , V_19 ,
V_20 ,
V_21 , 1 ) ) )
return V_8 ;
V_8 = F_2 ( V_16 -> V_2 , 0xa601 , 0 ) ;
F_10 ( L_30 ) ;
if ( ( V_8 = F_2 ( V_16 -> V_2 , 0xaefb , 0x01 ) ) )
return V_8 ;
F_10 ( L_31 ) ;
V_131 = sizeof( V_160 ) / sizeof( V_161 ) ;
for ( V_130 = 0 ; V_130 < V_131 ; V_130 ++ ) {
if ( ( V_8 =
F_3 ( V_16 -> V_2 , V_160 [ V_130 ] . V_162 ,
V_160 [ V_130 ] . V_5 ,
V_160 [ V_130 ] . V_6 , V_160 [ V_130 ] . V_163 ) ) )
return V_8 ;
if ( V_160 [ V_130 ] . V_162 == 0xae18 )
V_30 = V_160 [ V_130 ] . V_163 ;
if ( V_160 [ V_130 ] . V_162 == 0xae19 )
V_10 = V_160 [ V_130 ] . V_163 ;
if ( V_160 [ V_130 ] . V_162 == 0xae1a )
V_9 = V_160 [ V_130 ] . V_163 ;
if ( V_160 [ V_130 ] . V_162 == V_164 )
V_16 -> V_165 = V_160 [ V_130 ] . V_163 ;
if ( V_160 [ V_130 ] . V_162 == V_166 )
V_16 -> V_167 = V_160 [ V_130 ] . V_163 ;
if ( V_160 [ V_130 ] . V_162 == V_168 )
V_16 -> V_169 = V_160 [ V_130 ] . V_163 ;
if ( V_160 [ V_130 ] . V_162 == V_170 )
V_16 -> V_171 = V_160 [ V_130 ] . V_163 ;
}
V_16 -> V_172 =
( ( T_3 ) V_30 << 16 ) + ( ( T_3 ) V_10 << 8 ) + ( T_3 ) V_9 ;
F_10 ( L_32 ) ;
V_8 =
F_4 ( V_16 -> V_2 ,
V_173 ,
V_174 , 0 , 2 ,
& V_16 -> V_175 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_4 ( V_16 -> V_2 ,
V_176 ,
V_177 , 0 , 2 ,
& V_16 -> V_178 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_4 ( V_16 -> V_2 , 0xA60E , 0xA60A , 4 , 2 ,
& V_16 -> V_179 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_4 ( V_16 -> V_2 , 0xA60E , 0xA60B , 6 , 2 ,
& V_16 -> V_180 ) ;
if ( V_8 )
return V_8 ;
if ( V_13 -> V_84 . V_85 . V_86 == NULL ) {
V_8 = F_31 ( V_127 -> V_181 , 0xc6 , V_115 , 2 ) ;
if ( V_8 ) {
F_6 ( L_33 ) ;
return V_8 ;
}
F_10 ( L_34 , V_115 [ 0 ] , V_115 [ 1 ] ) ;
switch ( V_115 [ 0 ] ) {
case 2 :
V_8 = F_31 ( V_127 -> V_181 , 0xc8 , V_115 , 2 ) ;
if ( V_8 ) {
F_6 ( L_33 ) ;
return V_8 ;
}
V_132 = ( T_1 ) ( V_115 [ 0 ] << 8 ) + V_115 [ 1 ] ;
if ( F_32 ( V_182 , V_13 , & V_127 -> V_181 -> V_183 ,
& V_184 , V_132 ) == NULL ) {
F_10 ( L_35 ) ;
return - V_87 ;
}
break;
case 3 :
case 9 :
if ( F_32 ( V_185 , V_13 , & V_127 -> V_181 -> V_183 ,
& V_186 ) == NULL ) {
F_10 ( L_36 ) ;
return - V_87 ;
}
break;
default:
F_6 ( L_37 , V_115 [ 0 ] ) ;
return - V_87 ;
}
V_8 = V_13 -> V_84 . V_85 . V_187 ( V_13 ) ;
if ( V_8 )
return V_8 ;
}
F_10 ( L_38 ) ;
return 0 ;
}
static int F_33 ( struct V_12 * V_13 )
{
return F_27 ( V_13 , 0 ) ;
}
static int F_34 ( struct V_12 * V_13 , int V_188 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
if ( V_188 ) {
V_16 -> V_101 ++ ;
} else {
V_16 -> V_101 -- ;
if ( ! V_16 -> V_101 )
F_20 ( V_16 -> V_2 , 0 ) ;
}
return 0 ;
}
static int F_35 ( struct V_12 * V_13 )
{
struct V_189 * V_190 = & V_13 -> V_191 ;
struct V_15 * V_16 = V_13 -> V_17 ;
int V_8 ;
T_2 V_18 , V_9 , V_10 , V_30 ;
F_10 ( L_39 , V_190 -> V_192 ,
V_190 -> V_193 ) ;
if ( V_13 -> V_84 . V_85 . V_86 == NULL ) {
F_6 ( L_40 ) ;
return - V_87 ;
}
F_10 ( L_41 ) ;
V_8 = F_20 ( V_16 -> V_2 , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_16 -> V_2 , V_194 , 2 , 1 , 0 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_42 ) ;
V_9 = ( T_2 ) ( V_16 -> V_172 & 0x000000ff ) ;
V_10 = ( T_2 ) ( ( V_16 -> V_172 & 0x0000ff00 ) >> 8 ) ;
V_30 = ( T_2 ) ( ( V_16 -> V_172 & 0x00ff0000 ) >> 16 ) ;
V_8 = F_2 ( V_16 -> V_2 , 0xae1a , V_9 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_16 -> V_2 , 0xae19 , V_10 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_2 ( V_16 -> V_2 , 0xae18 , V_30 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_43 ) ;
V_8 =
F_1 ( V_16 -> V_2 ,
V_173 ,
V_174 , 0 , 2 ,
V_16 -> V_175 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_1 ( V_16 -> V_2 ,
V_176 ,
V_177 , 0 , 2 ,
V_16 -> V_178 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_1 ( V_16 -> V_2 , 0xA60E , 0xA60A , 4 , 2 ,
V_16 -> V_179 ) ;
if ( V_8 )
return V_8 ;
V_8 =
F_1 ( V_16 -> V_2 , 0xA60E , 0xA60B , 6 , 2 ,
V_16 -> V_180 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_44 ) ;
V_8 = F_26 ( V_16 -> V_2 , V_190 -> V_193 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_25 ( V_16 -> V_2 , V_190 -> V_193 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_45 ) ;
V_8 = F_2 ( V_16 -> V_2 , 0xaefd , 0 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_46 ) ;
V_8 =
F_2 ( V_16 -> V_2 , V_164 ,
V_16 -> V_165 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_47 ) ;
V_8 = V_13 -> V_84 . V_85 . V_195 ( V_13 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_48 ) ;
V_18 = 0 ;
V_8 = F_36 ( V_16 -> V_2 , 0xffff , & V_18 , 1 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_49 ) ;
V_8 =
F_3 ( V_16 -> V_2 ,
V_196 ,
V_197 , 2 , 0 ) ;
if ( V_8 )
return V_8 ;
F_13 ( V_13 ) ;
F_14 ( V_13 ) ;
V_16 -> V_73 = 0 ;
V_16 -> V_74 = 0 ;
V_16 -> V_75 = 0 ;
V_16 -> V_76 = 0 ;
V_16 -> V_27 = 0 ;
V_16 -> V_80 = V_79 ;
V_16 -> V_105 = - 1 ;
return 0 ;
}
static int F_37 ( struct V_12 * V_13 )
{
struct V_189 * V_190 = & V_13 -> V_191 ;
struct V_15 * V_16 = V_13 -> V_17 ;
int V_8 ;
T_2 V_18 ;
V_8 =
F_8 ( V_16 -> V_2 , V_61 ,
V_62 , V_63 ,
& V_18 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_50 ) ;
F_10 ( L_51 ) ;
switch ( V_18 ) {
case 0 :
V_190 -> V_198 = V_199 ;
F_10 ( L_52 ) ;
break;
case 1 :
V_190 -> V_198 = V_200 ;
F_10 ( L_53 ) ;
break;
case 2 :
V_190 -> V_198 = V_201 ;
F_10 ( L_54 ) ;
break;
}
V_8 =
F_8 ( V_16 -> V_2 , V_202 ,
V_203 , V_204 ,
& V_18 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_55 ) ;
switch ( V_18 ) {
case 0 :
V_190 -> V_205 = V_206 ;
F_10 ( L_56 ) ;
break;
case 1 :
V_190 -> V_205 = V_207 ;
F_10 ( L_57 ) ;
break;
case 2 :
V_190 -> V_205 = V_208 ;
F_10 ( L_58 ) ;
break;
case 3 :
V_190 -> V_205 = V_209 ;
F_10 ( L_59 ) ;
break;
}
V_8 =
F_8 ( V_16 -> V_2 , V_210 ,
V_211 , V_212 , & V_18 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_60 , V_18 ? L_61 : L_62 ) ;
V_8 =
F_8 ( V_16 -> V_2 , V_213 ,
V_214 , V_215 ,
& V_18 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_63 ) ;
switch ( V_18 ) {
case 0 :
V_190 -> V_216 = V_217 ;
F_10 ( L_64 ) ;
break;
case 1 :
V_190 -> V_216 = V_218 ;
F_10 ( L_65 ) ;
break;
case 2 :
V_190 -> V_216 = V_219 ;
F_10 ( L_66 ) ;
break;
case 3 :
V_190 -> V_216 = V_220 ;
F_10 ( L_67 ) ;
break;
case 4 :
V_190 -> V_216 = V_221 ;
F_10 ( L_68 ) ;
break;
}
V_8 =
F_8 ( V_16 -> V_2 , V_222 ,
V_223 , V_224 ,
& V_18 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_69 ) ;
switch ( V_18 ) {
case 0 :
V_190 -> V_225 = V_217 ;
F_10 ( L_64 ) ;
break;
case 1 :
V_190 -> V_225 = V_218 ;
F_10 ( L_65 ) ;
break;
case 2 :
V_190 -> V_225 = V_219 ;
F_10 ( L_66 ) ;
break;
case 3 :
V_190 -> V_225 = V_220 ;
F_10 ( L_67 ) ;
break;
case 4 :
V_190 -> V_225 = V_221 ;
F_10 ( L_68 ) ;
break;
}
V_8 =
F_8 ( V_16 -> V_2 , V_226 ,
V_227 , V_228 , & V_18 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_70 ) ;
switch ( V_18 ) {
case 0 :
V_190 -> V_229 = V_230 ;
F_10 ( L_71 ) ;
break;
case 1 :
V_190 -> V_229 = V_231 ;
F_10 ( L_72 ) ;
break;
case 2 :
V_190 -> V_229 = V_232 ;
F_10 ( L_73 ) ;
break;
case 3 :
V_190 -> V_229 = V_233 ;
F_10 ( L_74 ) ;
break;
}
V_8 =
F_8 ( V_16 -> V_2 , V_58 ,
V_59 , V_60 ,
& V_18 ) ;
if ( V_8 )
return V_8 ;
F_10 ( L_75 ) ;
switch ( V_18 ) {
case 0 :
V_190 -> V_234 = V_235 ;
F_10 ( L_76 ) ;
break;
case 1 :
V_190 -> V_234 = V_236 ;
F_10 ( L_77 ) ;
break;
}
V_8 =
F_8 ( V_16 -> V_2 , V_122 , V_123 ,
V_124 , & V_18 ) ;
F_10 ( L_78 ) ;
switch ( V_18 ) {
case 0 :
V_190 -> V_193 = 6000000 ;
F_10 ( L_79 ) ;
break;
case 1 :
V_190 -> V_193 = 7000000 ;
F_10 ( L_80 ) ;
break;
case 2 :
V_190 -> V_193 = 8000000 ;
F_10 ( L_81 ) ;
break;
}
return 0 ;
}
static void F_38 ( struct V_12 * V_13 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_13 -> V_17 ;
F_39 ( V_16 ) ;
}
struct V_12 * F_40 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = NULL ;
V_16 = F_41 ( sizeof( struct V_15 ) , V_237 ) ;
if ( V_16 == NULL )
goto error;
F_10 ( L_82 ) ;
V_16 -> V_2 = V_2 ;
V_16 -> V_101 = 0 ;
memcpy ( & V_16 -> V_238 . V_84 , & V_239 ,
sizeof( struct V_240 ) ) ;
V_16 -> V_238 . V_17 = V_16 ;
return & V_16 -> V_238 ;
error:
return NULL ;
}
