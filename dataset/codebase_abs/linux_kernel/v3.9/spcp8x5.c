static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
enum V_7 type = V_8 ;
T_1 V_9 = F_2 ( V_4 -> V_10 -> V_11 . V_12 ) ;
if ( V_9 == 0x0201 )
type = V_8 ;
else if ( V_9 == 0x0231 )
type = V_13 ;
else if ( V_9 == 0x0235 )
type = V_14 ;
else if ( V_9 == 0x0204 )
type = V_15 ;
else if ( V_9 == 0x0471 &&
V_4 -> V_10 -> V_11 . V_16 == F_3 ( 0x081e ) )
type = V_17 ;
F_4 ( & V_4 -> V_10 -> V_10 , L_1 , ( int ) type ) ;
V_6 = F_5 ( sizeof( * V_6 ) , V_18 ) ;
if ( ! V_6 )
return - V_19 ;
F_6 ( & V_6 -> V_20 ) ;
V_6 -> type = type ;
F_7 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_9 ( V_2 ) ;
F_10 ( V_6 ) ;
return 0 ;
}
static int F_11 ( struct V_21 * V_10 , T_2 V_22 ,
enum V_7 type )
{
int V_23 ;
T_2 V_24 = 0 ;
if ( type == V_8 )
return - V_25 ;
V_24 = ( unsigned short ) V_22 ;
V_23 = F_12 ( V_10 , F_13 ( V_10 , 0 ) ,
V_26 , V_27 ,
V_24 , 0x04 , NULL , 0 , 100 ) ;
if ( V_23 != 0 )
F_4 ( & V_10 -> V_10 , L_2 , V_23 ) ;
return V_23 ;
}
static int F_14 ( struct V_21 * V_10 , T_2 * V_28 ,
enum V_7 type )
{
T_2 * V_29 ;
int V_30 ;
if ( type == V_8 )
return - V_25 ;
if ( V_28 == NULL )
return - V_31 ;
V_29 = F_15 ( 1 , V_18 ) ;
if ( ! V_29 )
return - V_19 ;
V_29 [ 0 ] = V_28 [ 0 ] ;
V_30 = F_12 ( V_10 , F_16 ( V_10 , 0 ) ,
V_32 , V_33 ,
0 , V_34 , V_29 , 1 , 100 ) ;
if ( V_30 < 0 )
F_4 ( & V_10 -> V_10 , L_3 ,
V_29 , V_30 ) ;
F_4 ( & V_10 -> V_10 , L_4 , V_30 , V_29 ) ;
V_28 [ 0 ] = V_29 [ 0 ] ;
F_10 ( V_29 ) ;
return V_30 ;
}
static void F_17 ( struct V_21 * V_10 , T_1 V_22 ,
T_1 V_35 , enum V_7 type )
{
int V_30 ;
if ( type == V_8 )
return;
V_30 = F_12 ( V_10 , F_13 ( V_10 , 0 ) ,
V_36 , V_37 ,
V_22 , V_35 , NULL , 0 , 100 ) ;
F_4 ( & V_10 -> V_10 , L_5 , V_22 , V_35 ) ;
if ( V_30 < 0 )
F_4 ( & V_10 -> V_10 ,
L_6 , V_30 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_9 ( V_2 ) ;
if ( V_6 -> V_38 & V_39 )
return 1 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , int V_40 )
{
struct V_5 * V_6 = F_9 ( V_2 ) ;
unsigned long V_41 ;
T_2 V_42 ;
F_20 ( & V_6 -> V_20 , V_41 ) ;
if ( V_40 )
V_6 -> V_43 = V_44
| V_45 ;
else
V_6 -> V_43 &= ~ ( V_44
| V_45 ) ;
V_42 = V_6 -> V_43 ;
F_21 ( & V_6 -> V_20 , V_41 ) ;
F_11 ( V_2 -> V_4 -> V_10 , V_42 , V_6 -> type ) ;
}
static void F_22 ( struct V_46 * V_47 )
{
V_47 -> V_48 = V_49 ;
V_47 -> V_48 . V_50 = V_51 | V_52 | V_53 | V_54 | V_55 ;
V_47 -> V_48 . V_56 = 115200 ;
V_47 -> V_48 . V_57 = 115200 ;
}
static void F_23 ( struct V_46 * V_47 ,
struct V_1 * V_2 , struct V_58 * V_59 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_9 ( V_2 ) ;
unsigned long V_41 ;
unsigned int V_60 = V_47 -> V_48 . V_50 ;
unsigned int V_61 = V_59 -> V_50 ;
unsigned short V_62 ;
unsigned char V_63 [ 2 ] = { 0 , 0 } ;
int V_64 ;
int V_65 ;
T_2 V_42 ;
if ( ! F_24 ( & V_47 -> V_48 , V_59 ) )
return;
F_20 ( & V_6 -> V_20 , V_41 ) ;
V_42 = V_6 -> V_43 ;
if ( ( V_61 & V_66 ) == V_67 ) {
V_6 -> V_43 |= V_68 ;
if ( ! ( V_61 & V_69 ) )
V_6 -> V_43 |= V_70 ;
}
if ( V_42 != V_6 -> V_43 ) {
V_42 = V_6 -> V_43 ;
F_21 ( & V_6 -> V_20 , V_41 ) ;
F_11 ( V_4 -> V_10 , V_42 , V_6 -> type ) ;
} else {
F_21 ( & V_6 -> V_20 , V_41 ) ;
}
V_64 = F_25 ( V_47 ) ;
switch ( V_64 ) {
case 300 : V_63 [ 0 ] = 0x00 ; break;
case 600 : V_63 [ 0 ] = 0x01 ; break;
case 1200 : V_63 [ 0 ] = 0x02 ; break;
case 2400 : V_63 [ 0 ] = 0x03 ; break;
case 4800 : V_63 [ 0 ] = 0x04 ; break;
case 9600 : V_63 [ 0 ] = 0x05 ; break;
case 19200 : V_63 [ 0 ] = 0x07 ; break;
case 38400 : V_63 [ 0 ] = 0x09 ; break;
case 57600 : V_63 [ 0 ] = 0x0a ; break;
case 115200 : V_63 [ 0 ] = 0x0b ; break;
case 230400 : V_63 [ 0 ] = 0x0c ; break;
case 460800 : V_63 [ 0 ] = 0x0d ; break;
case 921600 : V_63 [ 0 ] = 0x0e ; break;
case 3000000 : V_63 [ 0 ] = 0x11 ; break;
case 0 :
case 1000000 :
V_63 [ 0 ] = 0x0b ; break;
default:
F_26 ( & V_2 -> V_10 , L_7
L_8 ) ;
}
if ( V_60 & V_71 ) {
switch ( V_60 & V_71 ) {
case V_72 :
V_63 [ 1 ] |= V_73 ;
break;
case V_74 :
V_63 [ 1 ] |= V_75 ;
break;
case V_76 :
V_63 [ 1 ] |= V_77 ;
break;
default:
case V_52 :
V_63 [ 1 ] |= V_78 ;
break;
}
}
V_63 [ 1 ] |= ( V_60 & V_79 ) ? V_80 :
V_81 ;
if ( V_60 & V_82 ) {
V_63 [ 1 ] |= ( V_60 & V_83 ) ?
V_84 : V_85 ;
} else
V_63 [ 1 ] |= V_86 ;
V_62 = V_63 [ 0 ] | V_63 [ 1 ] << 8 ;
V_65 = F_12 ( V_4 -> V_10 , F_13 ( V_4 -> V_10 , 0 ) ,
V_87 , V_88 ,
V_62 , 0 , NULL , 0 , 100 ) ;
if ( V_65 < 0 )
F_26 ( & V_2 -> V_10 , L_9 ,
V_62 , V_65 ) ;
F_4 ( & V_2 -> V_10 , L_10 , V_65 ) ;
if ( V_60 & V_69 ) {
F_17 ( V_4 -> V_10 , 0x000a ,
V_89 , V_6 -> type ) ;
}
}
static int F_27 ( struct V_46 * V_47 , struct V_1 * V_2 )
{
struct V_58 V_90 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_9 ( V_2 ) ;
int V_30 ;
unsigned long V_41 ;
T_2 V_28 = 0x30 ;
F_28 ( V_4 -> V_10 , V_2 -> V_91 -> V_92 ) ;
F_28 ( V_4 -> V_10 , V_2 -> V_93 -> V_92 ) ;
V_30 = F_12 ( V_4 -> V_10 , F_13 ( V_4 -> V_10 , 0 ) ,
0x09 , 0x00 ,
0x01 , 0x00 , NULL , 0x00 , 100 ) ;
if ( V_30 )
return V_30 ;
F_11 ( V_4 -> V_10 , V_6 -> V_43 , V_6 -> type ) ;
if ( V_47 )
F_23 ( V_47 , V_2 , & V_90 ) ;
F_14 ( V_4 -> V_10 , & V_28 , V_6 -> type ) ;
F_20 ( & V_6 -> V_20 , V_41 ) ;
V_6 -> V_38 = V_28 & 0xf0 ;
F_21 ( & V_6 -> V_20 , V_41 ) ;
V_2 -> V_2 . V_94 = 256 ;
return F_29 ( V_47 , V_2 ) ;
}
static void F_30 ( struct V_95 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_96 ;
struct V_5 * V_6 = F_9 ( V_2 ) ;
unsigned char * V_97 = V_95 -> V_98 ;
unsigned long V_41 ;
T_2 V_28 ;
char V_99 ;
V_99 = V_100 ;
F_20 ( & V_6 -> V_20 , V_41 ) ;
V_28 = V_6 -> V_38 ;
V_6 -> V_38 &= ~ V_101 ;
F_21 ( & V_6 -> V_20 , V_41 ) ;
F_31 ( & V_2 -> V_102 ) ;
if ( ! V_95 -> V_103 )
return;
if ( V_28 & V_101 ) {
if ( V_28 & V_104 )
V_99 = V_105 ;
else if ( V_28 & V_106 )
V_99 = V_107 ;
else if ( V_28 & V_108 )
V_99 = V_109 ;
F_4 ( & V_2 -> V_10 , L_11 , V_99 ) ;
if ( V_28 & V_110 )
F_32 ( & V_2 -> V_2 , 0 , V_111 ) ;
if ( V_28 & V_112 ) {
struct V_46 * V_47 = F_33 ( & V_2 -> V_2 ) ;
if ( V_47 ) {
F_34 ( V_2 , V_47 ,
V_6 -> V_38 & V_39 ) ;
F_35 ( V_47 ) ;
}
}
}
F_36 ( & V_2 -> V_2 , V_97 , V_99 ,
V_95 -> V_103 ) ;
F_37 ( & V_2 -> V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned int V_113 )
{
struct V_5 * V_6 = F_9 ( V_2 ) ;
unsigned long V_41 ;
unsigned int V_114 ;
unsigned int V_28 ;
unsigned int V_115 ;
F_20 ( & V_6 -> V_20 , V_41 ) ;
V_114 = V_6 -> V_38 ;
F_21 ( & V_6 -> V_20 , V_41 ) ;
while ( 1 ) {
F_39 ( & V_2 -> V_102 ) ;
if ( F_40 ( V_116 ) )
return - V_117 ;
if ( V_2 -> V_4 -> V_118 )
return - V_119 ;
F_20 ( & V_6 -> V_20 , V_41 ) ;
V_28 = V_6 -> V_38 ;
F_21 ( & V_6 -> V_20 , V_41 ) ;
V_115 = V_114 ^ V_28 ;
if ( ( ( V_113 & V_120 ) && ( V_115 & V_121 ) ) ||
( ( V_113 & V_122 ) && ( V_115 & V_123 ) ) ||
( ( V_113 & V_124 ) && ( V_115 & V_39 ) ) ||
( ( V_113 & V_125 ) && ( V_115 & V_126 ) ) )
return 0 ;
V_114 = V_28 ;
}
return 0 ;
}
static int F_41 ( struct V_46 * V_47 ,
unsigned int V_127 , unsigned long V_113 )
{
struct V_1 * V_2 = V_47 -> V_128 ;
F_4 ( & V_2 -> V_10 , L_12 , V_129 ,
V_2 -> V_130 , V_127 ) ;
switch ( V_127 ) {
case V_131 :
F_4 ( & V_2 -> V_10 , L_13 , V_129 ,
V_2 -> V_130 ) ;
return F_38 ( V_2 , V_113 ) ;
default:
F_4 ( & V_2 -> V_10 , L_14 , V_129 ,
V_127 ) ;
break;
}
return - V_132 ;
}
static int F_42 ( struct V_46 * V_47 ,
unsigned int V_133 , unsigned int V_134 )
{
struct V_1 * V_2 = V_47 -> V_128 ;
struct V_5 * V_6 = F_9 ( V_2 ) ;
unsigned long V_41 ;
T_2 V_42 ;
F_20 ( & V_6 -> V_20 , V_41 ) ;
if ( V_133 & V_135 )
V_6 -> V_43 |= V_70 ;
if ( V_133 & V_136 )
V_6 -> V_43 |= V_68 ;
if ( V_134 & V_135 )
V_6 -> V_43 &= ~ V_70 ;
if ( V_134 & V_136 )
V_6 -> V_43 &= ~ V_68 ;
V_42 = V_6 -> V_43 ;
F_21 ( & V_6 -> V_20 , V_41 ) ;
return F_11 ( V_2 -> V_4 -> V_10 , V_42 , V_6 -> type ) ;
}
static int F_43 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_128 ;
struct V_5 * V_6 = F_9 ( V_2 ) ;
unsigned long V_41 ;
unsigned int V_24 ;
unsigned int V_28 ;
unsigned int V_137 ;
F_20 ( & V_6 -> V_20 , V_41 ) ;
V_24 = V_6 -> V_43 ;
V_28 = V_6 -> V_38 ;
F_21 ( & V_6 -> V_20 , V_41 ) ;
V_137 = ( ( V_24 & V_68 ) ? V_136 : 0 )
| ( ( V_24 & V_70 ) ? V_135 : 0 )
| ( ( V_28 & V_126 ) ? V_125 : 0 )
| ( ( V_28 & V_123 ) ? V_122 : 0 )
| ( ( V_28 & V_121 ) ? V_138 : 0 )
| ( ( V_28 & V_39 ) ? V_124 : 0 ) ;
return V_137 ;
}
