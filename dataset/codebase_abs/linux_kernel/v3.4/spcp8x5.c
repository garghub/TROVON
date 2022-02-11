static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
enum V_6 type = V_7 ;
T_1 V_8 = F_2 ( V_2 -> V_9 -> V_10 . V_11 ) ;
if ( V_8 == 0x0201 )
type = V_7 ;
else if ( V_8 == 0x0231 )
type = V_12 ;
else if ( V_8 == 0x0235 )
type = V_13 ;
else if ( V_8 == 0x0204 )
type = V_14 ;
else if ( V_8 == 0x0471 &&
V_2 -> V_9 -> V_10 . V_15 == F_3 ( 0x081e ) )
type = V_16 ;
F_4 ( & V_2 -> V_9 -> V_9 , L_1 , ( int ) type ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_17 ; ++ V_5 ) {
V_4 = F_5 ( sizeof( struct V_3 ) , V_18 ) ;
if ( ! V_4 )
goto V_19;
F_6 ( & V_4 -> V_20 ) ;
F_7 ( & V_4 -> V_21 ) ;
V_4 -> type = type ;
F_8 ( V_2 -> V_22 [ V_5 ] , V_4 ) ;
}
return 0 ;
V_19:
for ( -- V_5 ; V_5 >= 0 ; -- V_5 ) {
V_4 = F_9 ( V_2 -> V_22 [ V_5 ] ) ;
F_10 ( V_4 ) ;
F_8 ( V_2 -> V_22 [ V_5 ] , NULL ) ;
}
return - V_23 ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_17 ; V_5 ++ )
F_10 ( F_9 ( V_2 -> V_22 [ V_5 ] ) ) ;
}
static int F_12 ( struct V_24 * V_9 , T_2 V_25 ,
enum V_6 type )
{
int V_26 ;
T_2 V_27 = 0 ;
if ( type == V_7 )
return - V_28 ;
V_27 = ( unsigned short ) V_25 ;
V_26 = F_13 ( V_9 , F_14 ( V_9 , 0 ) ,
V_29 , V_30 ,
V_27 , 0x04 , NULL , 0 , 100 ) ;
if ( V_26 != 0 )
F_4 ( & V_9 -> V_9 , L_2 , V_26 ) ;
return V_26 ;
}
static int F_15 ( struct V_24 * V_9 , T_2 * V_31 ,
enum V_6 type )
{
T_2 * V_32 ;
int V_33 ;
if ( type == V_7 )
return - V_28 ;
if ( V_31 == NULL )
return - V_34 ;
V_32 = F_16 ( 1 , V_18 ) ;
if ( ! V_32 )
return - V_23 ;
V_32 [ 0 ] = V_31 [ 0 ] ;
V_33 = F_13 ( V_9 , F_17 ( V_9 , 0 ) ,
V_35 , V_36 ,
0 , V_37 , V_32 , 1 , 100 ) ;
if ( V_33 < 0 )
F_4 ( & V_9 -> V_9 , L_3 ,
V_32 , V_33 ) ;
F_4 ( & V_9 -> V_9 , L_4 , V_33 , V_32 ) ;
V_31 [ 0 ] = V_32 [ 0 ] ;
F_10 ( V_32 ) ;
return V_33 ;
}
static void F_18 ( struct V_24 * V_9 , T_1 V_25 ,
T_1 V_38 , enum V_6 type )
{
int V_33 ;
if ( type == V_7 )
return;
V_33 = F_13 ( V_9 , F_14 ( V_9 , 0 ) ,
V_39 , V_40 ,
V_25 , V_38 , NULL , 0 , 100 ) ;
F_4 ( & V_9 -> V_9 , L_5 , V_25 , V_38 ) ;
if ( V_33 < 0 )
F_4 ( & V_9 -> V_9 ,
L_6 , V_33 ) ;
}
static int F_19 ( struct V_41 * V_22 )
{
struct V_3 * V_4 = F_9 ( V_22 ) ;
if ( V_4 -> V_42 & V_43 )
return 1 ;
return 0 ;
}
static void F_20 ( struct V_41 * V_22 , int V_44 )
{
struct V_3 * V_4 = F_9 ( V_22 ) ;
unsigned long V_45 ;
T_2 V_46 ;
F_21 ( & V_4 -> V_20 , V_45 ) ;
if ( V_44 )
V_4 -> V_47 = V_48
| V_49 ;
else
V_4 -> V_47 &= ~ ( V_48
| V_49 ) ;
V_46 = V_4 -> V_47 ;
F_22 ( & V_4 -> V_20 , V_45 ) ;
F_12 ( V_22 -> V_2 -> V_9 , V_46 , V_4 -> type ) ;
}
static void F_23 ( struct V_50 * V_51 )
{
* ( V_51 -> V_52 ) = V_53 ;
V_51 -> V_52 -> V_54 = V_55 | V_56 | V_57 | V_58 | V_59 ;
V_51 -> V_52 -> V_60 = 115200 ;
V_51 -> V_52 -> V_61 = 115200 ;
}
static void F_24 ( struct V_50 * V_51 ,
struct V_41 * V_22 , struct V_62 * V_63 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_3 * V_4 = F_9 ( V_22 ) ;
unsigned long V_45 ;
unsigned int V_64 = V_51 -> V_52 -> V_54 ;
unsigned int V_65 = V_63 -> V_54 ;
unsigned short V_66 ;
unsigned char V_67 [ 2 ] = { 0 , 0 } ;
int V_68 ;
int V_5 ;
T_2 V_46 ;
if ( ! F_25 ( V_51 -> V_52 , V_63 ) )
return;
F_21 ( & V_4 -> V_20 , V_45 ) ;
V_46 = V_4 -> V_47 ;
if ( ( V_65 & V_69 ) == V_70 ) {
V_4 -> V_47 |= V_71 ;
if ( ! ( V_65 & V_72 ) )
V_4 -> V_47 |= V_73 ;
}
if ( V_46 != V_4 -> V_47 ) {
V_46 = V_4 -> V_47 ;
F_22 ( & V_4 -> V_20 , V_45 ) ;
F_12 ( V_2 -> V_9 , V_46 , V_4 -> type ) ;
} else {
F_22 ( & V_4 -> V_20 , V_45 ) ;
}
V_68 = F_26 ( V_51 ) ;
switch ( V_68 ) {
case 300 : V_67 [ 0 ] = 0x00 ; break;
case 600 : V_67 [ 0 ] = 0x01 ; break;
case 1200 : V_67 [ 0 ] = 0x02 ; break;
case 2400 : V_67 [ 0 ] = 0x03 ; break;
case 4800 : V_67 [ 0 ] = 0x04 ; break;
case 9600 : V_67 [ 0 ] = 0x05 ; break;
case 19200 : V_67 [ 0 ] = 0x07 ; break;
case 38400 : V_67 [ 0 ] = 0x09 ; break;
case 57600 : V_67 [ 0 ] = 0x0a ; break;
case 115200 : V_67 [ 0 ] = 0x0b ; break;
case 230400 : V_67 [ 0 ] = 0x0c ; break;
case 460800 : V_67 [ 0 ] = 0x0d ; break;
case 921600 : V_67 [ 0 ] = 0x0e ; break;
case 3000000 : V_67 [ 0 ] = 0x11 ; break;
case 0 :
case 1000000 :
V_67 [ 0 ] = 0x0b ; break;
default:
F_27 ( & V_22 -> V_9 , L_7
L_8 ) ;
}
if ( V_64 & V_74 ) {
switch ( V_64 & V_74 ) {
case V_75 :
V_67 [ 1 ] |= V_76 ;
break;
case V_77 :
V_67 [ 1 ] |= V_78 ;
break;
case V_79 :
V_67 [ 1 ] |= V_80 ;
break;
default:
case V_56 :
V_67 [ 1 ] |= V_81 ;
break;
}
}
V_67 [ 1 ] |= ( V_64 & V_82 ) ? V_83 :
V_84 ;
if ( V_64 & V_85 ) {
V_67 [ 1 ] |= ( V_64 & V_86 ) ?
V_87 : V_88 ;
} else
V_67 [ 1 ] |= V_89 ;
V_66 = V_67 [ 0 ] | V_67 [ 1 ] << 8 ;
V_5 = F_13 ( V_2 -> V_9 , F_14 ( V_2 -> V_9 , 0 ) ,
V_90 , V_91 ,
V_66 , 0 , NULL , 0 , 100 ) ;
if ( V_5 < 0 )
F_27 ( & V_22 -> V_9 , L_9 ,
V_66 , V_5 ) ;
F_28 ( L_10 , V_5 ) ;
if ( V_64 & V_72 ) {
F_18 ( V_2 -> V_9 , 0x000a ,
V_92 , V_4 -> type ) ;
}
}
static int F_29 ( struct V_50 * V_51 , struct V_41 * V_22 )
{
struct V_62 V_93 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_3 * V_4 = F_9 ( V_22 ) ;
int V_33 ;
unsigned long V_45 ;
T_2 V_31 = 0x30 ;
F_28 ( L_11 , V_94 , V_22 -> V_95 ) ;
F_30 ( V_2 -> V_9 , V_22 -> V_96 -> V_97 ) ;
F_30 ( V_2 -> V_9 , V_22 -> V_98 -> V_97 ) ;
V_33 = F_13 ( V_2 -> V_9 , F_14 ( V_2 -> V_9 , 0 ) ,
0x09 , 0x00 ,
0x01 , 0x00 , NULL , 0x00 , 100 ) ;
if ( V_33 )
return V_33 ;
F_12 ( V_2 -> V_9 , V_4 -> V_47 , V_4 -> type ) ;
if ( V_51 )
F_24 ( V_51 , V_22 , & V_93 ) ;
F_15 ( V_2 -> V_9 , & V_31 , V_4 -> type ) ;
F_21 ( & V_4 -> V_20 , V_45 ) ;
V_4 -> V_42 = V_31 & 0xf0 ;
F_22 ( & V_4 -> V_20 , V_45 ) ;
V_22 -> V_22 . V_99 = 256 ;
return F_31 ( V_51 , V_22 ) ;
}
static void F_32 ( struct V_100 * V_100 )
{
struct V_41 * V_22 = V_100 -> V_101 ;
struct V_3 * V_4 = F_9 ( V_22 ) ;
struct V_50 * V_51 ;
unsigned char * V_102 = V_100 -> V_103 ;
unsigned long V_45 ;
T_2 V_31 ;
char V_104 ;
V_104 = V_105 ;
F_21 ( & V_4 -> V_20 , V_45 ) ;
V_31 = V_4 -> V_42 ;
V_4 -> V_42 &= ~ V_106 ;
F_22 ( & V_4 -> V_20 , V_45 ) ;
F_33 ( & V_4 -> V_21 ) ;
if ( ! V_100 -> V_107 )
return;
V_51 = F_34 ( & V_22 -> V_22 ) ;
if ( ! V_51 )
return;
if ( V_31 & V_106 ) {
if ( V_31 & V_108 )
V_104 = V_109 ;
else if ( V_31 & V_110 )
V_104 = V_111 ;
else if ( V_31 & V_112 )
V_104 = V_113 ;
F_4 ( & V_22 -> V_9 , L_12 , V_104 ) ;
if ( V_31 & V_114 )
F_35 ( V_51 , 0 , V_115 ) ;
if ( V_31 & V_116 )
F_36 ( V_22 , V_51 ,
V_4 -> V_42 & V_43 ) ;
}
F_37 ( V_51 , V_102 , V_104 ,
V_100 -> V_107 ) ;
F_38 ( V_51 ) ;
F_39 ( V_51 ) ;
}
static int F_40 ( struct V_41 * V_22 ,
unsigned int V_117 )
{
struct V_3 * V_4 = F_9 ( V_22 ) ;
unsigned long V_45 ;
unsigned int V_118 ;
unsigned int V_31 ;
unsigned int V_119 ;
F_21 ( & V_4 -> V_20 , V_45 ) ;
V_118 = V_4 -> V_42 ;
F_22 ( & V_4 -> V_20 , V_45 ) ;
while ( 1 ) {
F_41 ( & V_4 -> V_21 ) ;
if ( F_42 ( V_120 ) )
return - V_121 ;
F_21 ( & V_4 -> V_20 , V_45 ) ;
V_31 = V_4 -> V_42 ;
F_22 ( & V_4 -> V_20 , V_45 ) ;
V_119 = V_118 ^ V_31 ;
if ( ( ( V_117 & V_122 ) && ( V_119 & V_123 ) ) ||
( ( V_117 & V_124 ) && ( V_119 & V_125 ) ) ||
( ( V_117 & V_126 ) && ( V_119 & V_43 ) ) ||
( ( V_117 & V_127 ) && ( V_119 & V_128 ) ) )
return 0 ;
V_118 = V_31 ;
}
return 0 ;
}
static int F_43 ( struct V_50 * V_51 ,
unsigned int V_129 , unsigned long V_117 )
{
struct V_41 * V_22 = V_51 -> V_130 ;
F_28 ( L_13 , V_94 , V_22 -> V_95 , V_129 ) ;
switch ( V_129 ) {
case V_131 :
F_28 ( L_14 , V_94 , V_22 -> V_95 ) ;
return F_40 ( V_22 , V_117 ) ;
default:
F_28 ( L_15 , V_94 , V_129 ) ;
break;
}
return - V_132 ;
}
static int F_44 ( struct V_50 * V_51 ,
unsigned int V_133 , unsigned int V_134 )
{
struct V_41 * V_22 = V_51 -> V_130 ;
struct V_3 * V_4 = F_9 ( V_22 ) ;
unsigned long V_45 ;
T_2 V_46 ;
F_21 ( & V_4 -> V_20 , V_45 ) ;
if ( V_133 & V_135 )
V_4 -> V_47 |= V_73 ;
if ( V_133 & V_136 )
V_4 -> V_47 |= V_71 ;
if ( V_134 & V_135 )
V_4 -> V_47 &= ~ V_73 ;
if ( V_134 & V_136 )
V_4 -> V_47 &= ~ V_71 ;
V_46 = V_4 -> V_47 ;
F_22 ( & V_4 -> V_20 , V_45 ) ;
return F_12 ( V_22 -> V_2 -> V_9 , V_46 , V_4 -> type ) ;
}
static int F_45 ( struct V_50 * V_51 )
{
struct V_41 * V_22 = V_51 -> V_130 ;
struct V_3 * V_4 = F_9 ( V_22 ) ;
unsigned long V_45 ;
unsigned int V_27 ;
unsigned int V_31 ;
unsigned int V_137 ;
F_21 ( & V_4 -> V_20 , V_45 ) ;
V_27 = V_4 -> V_47 ;
V_31 = V_4 -> V_42 ;
F_22 ( & V_4 -> V_20 , V_45 ) ;
V_137 = ( ( V_27 & V_71 ) ? V_136 : 0 )
| ( ( V_27 & V_73 ) ? V_135 : 0 )
| ( ( V_31 & V_128 ) ? V_127 : 0 )
| ( ( V_31 & V_125 ) ? V_124 : 0 )
| ( ( V_31 & V_123 ) ? V_138 : 0 )
| ( ( V_31 & V_43 ) ? V_126 : 0 ) ;
return V_137 ;
}
