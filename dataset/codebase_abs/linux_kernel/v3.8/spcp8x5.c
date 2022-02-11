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
F_7 ( & V_6 -> V_21 ) ;
V_6 -> type = type ;
F_8 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_10 ( V_2 ) ;
F_11 ( V_6 ) ;
return 0 ;
}
static int F_12 ( struct V_22 * V_10 , T_2 V_23 ,
enum V_7 type )
{
int V_24 ;
T_2 V_25 = 0 ;
if ( type == V_8 )
return - V_26 ;
V_25 = ( unsigned short ) V_23 ;
V_24 = F_13 ( V_10 , F_14 ( V_10 , 0 ) ,
V_27 , V_28 ,
V_25 , 0x04 , NULL , 0 , 100 ) ;
if ( V_24 != 0 )
F_4 ( & V_10 -> V_10 , L_2 , V_24 ) ;
return V_24 ;
}
static int F_15 ( struct V_22 * V_10 , T_2 * V_29 ,
enum V_7 type )
{
T_2 * V_30 ;
int V_31 ;
if ( type == V_8 )
return - V_26 ;
if ( V_29 == NULL )
return - V_32 ;
V_30 = F_16 ( 1 , V_18 ) ;
if ( ! V_30 )
return - V_19 ;
V_30 [ 0 ] = V_29 [ 0 ] ;
V_31 = F_13 ( V_10 , F_17 ( V_10 , 0 ) ,
V_33 , V_34 ,
0 , V_35 , V_30 , 1 , 100 ) ;
if ( V_31 < 0 )
F_4 ( & V_10 -> V_10 , L_3 ,
V_30 , V_31 ) ;
F_4 ( & V_10 -> V_10 , L_4 , V_31 , V_30 ) ;
V_29 [ 0 ] = V_30 [ 0 ] ;
F_11 ( V_30 ) ;
return V_31 ;
}
static void F_18 ( struct V_22 * V_10 , T_1 V_23 ,
T_1 V_36 , enum V_7 type )
{
int V_31 ;
if ( type == V_8 )
return;
V_31 = F_13 ( V_10 , F_14 ( V_10 , 0 ) ,
V_37 , V_38 ,
V_23 , V_36 , NULL , 0 , 100 ) ;
F_4 ( & V_10 -> V_10 , L_5 , V_23 , V_36 ) ;
if ( V_31 < 0 )
F_4 ( & V_10 -> V_10 ,
L_6 , V_31 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_10 ( V_2 ) ;
if ( V_6 -> V_39 & V_40 )
return 1 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , int V_41 )
{
struct V_5 * V_6 = F_10 ( V_2 ) ;
unsigned long V_42 ;
T_2 V_43 ;
F_21 ( & V_6 -> V_20 , V_42 ) ;
if ( V_41 )
V_6 -> V_44 = V_45
| V_46 ;
else
V_6 -> V_44 &= ~ ( V_45
| V_46 ) ;
V_43 = V_6 -> V_44 ;
F_22 ( & V_6 -> V_20 , V_42 ) ;
F_12 ( V_2 -> V_4 -> V_10 , V_43 , V_6 -> type ) ;
}
static void F_23 ( struct V_47 * V_48 )
{
V_48 -> V_49 = V_50 ;
V_48 -> V_49 . V_51 = V_52 | V_53 | V_54 | V_55 | V_56 ;
V_48 -> V_49 . V_57 = 115200 ;
V_48 -> V_49 . V_58 = 115200 ;
}
static void F_24 ( struct V_47 * V_48 ,
struct V_1 * V_2 , struct V_59 * V_60 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_10 ( V_2 ) ;
unsigned long V_42 ;
unsigned int V_61 = V_48 -> V_49 . V_51 ;
unsigned int V_62 = V_60 -> V_51 ;
unsigned short V_63 ;
unsigned char V_64 [ 2 ] = { 0 , 0 } ;
int V_65 ;
int V_66 ;
T_2 V_43 ;
if ( ! F_25 ( & V_48 -> V_49 , V_60 ) )
return;
F_21 ( & V_6 -> V_20 , V_42 ) ;
V_43 = V_6 -> V_44 ;
if ( ( V_62 & V_67 ) == V_68 ) {
V_6 -> V_44 |= V_69 ;
if ( ! ( V_62 & V_70 ) )
V_6 -> V_44 |= V_71 ;
}
if ( V_43 != V_6 -> V_44 ) {
V_43 = V_6 -> V_44 ;
F_22 ( & V_6 -> V_20 , V_42 ) ;
F_12 ( V_4 -> V_10 , V_43 , V_6 -> type ) ;
} else {
F_22 ( & V_6 -> V_20 , V_42 ) ;
}
V_65 = F_26 ( V_48 ) ;
switch ( V_65 ) {
case 300 : V_64 [ 0 ] = 0x00 ; break;
case 600 : V_64 [ 0 ] = 0x01 ; break;
case 1200 : V_64 [ 0 ] = 0x02 ; break;
case 2400 : V_64 [ 0 ] = 0x03 ; break;
case 4800 : V_64 [ 0 ] = 0x04 ; break;
case 9600 : V_64 [ 0 ] = 0x05 ; break;
case 19200 : V_64 [ 0 ] = 0x07 ; break;
case 38400 : V_64 [ 0 ] = 0x09 ; break;
case 57600 : V_64 [ 0 ] = 0x0a ; break;
case 115200 : V_64 [ 0 ] = 0x0b ; break;
case 230400 : V_64 [ 0 ] = 0x0c ; break;
case 460800 : V_64 [ 0 ] = 0x0d ; break;
case 921600 : V_64 [ 0 ] = 0x0e ; break;
case 3000000 : V_64 [ 0 ] = 0x11 ; break;
case 0 :
case 1000000 :
V_64 [ 0 ] = 0x0b ; break;
default:
F_27 ( & V_2 -> V_10 , L_7
L_8 ) ;
}
if ( V_61 & V_72 ) {
switch ( V_61 & V_72 ) {
case V_73 :
V_64 [ 1 ] |= V_74 ;
break;
case V_75 :
V_64 [ 1 ] |= V_76 ;
break;
case V_77 :
V_64 [ 1 ] |= V_78 ;
break;
default:
case V_53 :
V_64 [ 1 ] |= V_79 ;
break;
}
}
V_64 [ 1 ] |= ( V_61 & V_80 ) ? V_81 :
V_82 ;
if ( V_61 & V_83 ) {
V_64 [ 1 ] |= ( V_61 & V_84 ) ?
V_85 : V_86 ;
} else
V_64 [ 1 ] |= V_87 ;
V_63 = V_64 [ 0 ] | V_64 [ 1 ] << 8 ;
V_66 = F_13 ( V_4 -> V_10 , F_14 ( V_4 -> V_10 , 0 ) ,
V_88 , V_89 ,
V_63 , 0 , NULL , 0 , 100 ) ;
if ( V_66 < 0 )
F_27 ( & V_2 -> V_10 , L_9 ,
V_63 , V_66 ) ;
F_4 ( & V_2 -> V_10 , L_10 , V_66 ) ;
if ( V_61 & V_70 ) {
F_18 ( V_4 -> V_10 , 0x000a ,
V_90 , V_6 -> type ) ;
}
}
static int F_28 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_59 V_91 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_10 ( V_2 ) ;
int V_31 ;
unsigned long V_42 ;
T_2 V_29 = 0x30 ;
F_29 ( V_4 -> V_10 , V_2 -> V_92 -> V_93 ) ;
F_29 ( V_4 -> V_10 , V_2 -> V_94 -> V_93 ) ;
V_31 = F_13 ( V_4 -> V_10 , F_14 ( V_4 -> V_10 , 0 ) ,
0x09 , 0x00 ,
0x01 , 0x00 , NULL , 0x00 , 100 ) ;
if ( V_31 )
return V_31 ;
F_12 ( V_4 -> V_10 , V_6 -> V_44 , V_6 -> type ) ;
if ( V_48 )
F_24 ( V_48 , V_2 , & V_91 ) ;
F_15 ( V_4 -> V_10 , & V_29 , V_6 -> type ) ;
F_21 ( & V_6 -> V_20 , V_42 ) ;
V_6 -> V_39 = V_29 & 0xf0 ;
F_22 ( & V_6 -> V_20 , V_42 ) ;
V_2 -> V_2 . V_95 = 256 ;
return F_30 ( V_48 , V_2 ) ;
}
static void F_31 ( struct V_96 * V_96 )
{
struct V_1 * V_2 = V_96 -> V_97 ;
struct V_5 * V_6 = F_10 ( V_2 ) ;
struct V_47 * V_48 ;
unsigned char * V_98 = V_96 -> V_99 ;
unsigned long V_42 ;
T_2 V_29 ;
char V_100 ;
V_100 = V_101 ;
F_21 ( & V_6 -> V_20 , V_42 ) ;
V_29 = V_6 -> V_39 ;
V_6 -> V_39 &= ~ V_102 ;
F_22 ( & V_6 -> V_20 , V_42 ) ;
F_32 ( & V_6 -> V_21 ) ;
if ( ! V_96 -> V_103 )
return;
V_48 = F_33 ( & V_2 -> V_2 ) ;
if ( ! V_48 )
return;
if ( V_29 & V_102 ) {
if ( V_29 & V_104 )
V_100 = V_105 ;
else if ( V_29 & V_106 )
V_100 = V_107 ;
else if ( V_29 & V_108 )
V_100 = V_109 ;
F_4 ( & V_2 -> V_10 , L_11 , V_100 ) ;
if ( V_29 & V_110 )
F_34 ( V_48 , 0 , V_111 ) ;
if ( V_29 & V_112 )
F_35 ( V_2 , V_48 ,
V_6 -> V_39 & V_40 ) ;
}
F_36 ( V_48 , V_98 , V_100 ,
V_96 -> V_103 ) ;
F_37 ( V_48 ) ;
F_38 ( V_48 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned int V_113 )
{
struct V_5 * V_6 = F_10 ( V_2 ) ;
unsigned long V_42 ;
unsigned int V_114 ;
unsigned int V_29 ;
unsigned int V_115 ;
F_21 ( & V_6 -> V_20 , V_42 ) ;
V_114 = V_6 -> V_39 ;
F_22 ( & V_6 -> V_20 , V_42 ) ;
while ( 1 ) {
F_40 ( & V_6 -> V_21 ) ;
if ( F_41 ( V_116 ) )
return - V_117 ;
F_21 ( & V_6 -> V_20 , V_42 ) ;
V_29 = V_6 -> V_39 ;
F_22 ( & V_6 -> V_20 , V_42 ) ;
V_115 = V_114 ^ V_29 ;
if ( ( ( V_113 & V_118 ) && ( V_115 & V_119 ) ) ||
( ( V_113 & V_120 ) && ( V_115 & V_121 ) ) ||
( ( V_113 & V_122 ) && ( V_115 & V_40 ) ) ||
( ( V_113 & V_123 ) && ( V_115 & V_124 ) ) )
return 0 ;
V_114 = V_29 ;
}
return 0 ;
}
static int F_42 ( struct V_47 * V_48 ,
unsigned int V_125 , unsigned long V_113 )
{
struct V_1 * V_2 = V_48 -> V_126 ;
F_4 ( & V_2 -> V_10 , L_12 , V_127 ,
V_2 -> V_128 , V_125 ) ;
switch ( V_125 ) {
case V_129 :
F_4 ( & V_2 -> V_10 , L_13 , V_127 ,
V_2 -> V_128 ) ;
return F_39 ( V_2 , V_113 ) ;
default:
F_4 ( & V_2 -> V_10 , L_14 , V_127 ,
V_125 ) ;
break;
}
return - V_130 ;
}
static int F_43 ( struct V_47 * V_48 ,
unsigned int V_131 , unsigned int V_132 )
{
struct V_1 * V_2 = V_48 -> V_126 ;
struct V_5 * V_6 = F_10 ( V_2 ) ;
unsigned long V_42 ;
T_2 V_43 ;
F_21 ( & V_6 -> V_20 , V_42 ) ;
if ( V_131 & V_133 )
V_6 -> V_44 |= V_71 ;
if ( V_131 & V_134 )
V_6 -> V_44 |= V_69 ;
if ( V_132 & V_133 )
V_6 -> V_44 &= ~ V_71 ;
if ( V_132 & V_134 )
V_6 -> V_44 &= ~ V_69 ;
V_43 = V_6 -> V_44 ;
F_22 ( & V_6 -> V_20 , V_42 ) ;
return F_12 ( V_2 -> V_4 -> V_10 , V_43 , V_6 -> type ) ;
}
static int F_44 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_126 ;
struct V_5 * V_6 = F_10 ( V_2 ) ;
unsigned long V_42 ;
unsigned int V_25 ;
unsigned int V_29 ;
unsigned int V_135 ;
F_21 ( & V_6 -> V_20 , V_42 ) ;
V_25 = V_6 -> V_44 ;
V_29 = V_6 -> V_39 ;
F_22 ( & V_6 -> V_20 , V_42 ) ;
V_135 = ( ( V_25 & V_69 ) ? V_134 : 0 )
| ( ( V_25 & V_71 ) ? V_133 : 0 )
| ( ( V_29 & V_124 ) ? V_123 : 0 )
| ( ( V_29 & V_121 ) ? V_120 : 0 )
| ( ( V_29 & V_119 ) ? V_136 : 0 )
| ( ( V_29 & V_40 ) ? V_122 : 0 ) ;
return V_135 ;
}
