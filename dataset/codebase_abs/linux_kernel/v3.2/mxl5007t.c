static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
unsigned int V_6 = 0 ;
while ( V_2 [ V_6 ] . V_3 || V_2 [ V_6 ] . V_5 ) {
if ( V_2 [ V_6 ] . V_3 == V_3 ) {
V_2 [ V_6 ] . V_5 &= ~ V_4 ;
V_2 [ V_6 ] . V_5 |= V_5 ;
}
V_6 ++ ;
}
return;
}
static void F_2 ( struct V_1 * V_7 ,
struct V_1 * V_8 )
{
unsigned int V_6 , V_9 ;
V_6 = V_9 = 0 ;
while ( V_7 [ V_6 ] . V_3 || V_7 [ V_6 ] . V_5 ) {
while ( V_8 [ V_9 ] . V_3 || V_8 [ V_9 ] . V_5 ) {
if ( V_7 [ V_6 ] . V_3 != V_8 [ V_9 ] . V_3 ) {
V_9 ++ ;
continue;
}
V_8 [ V_9 ] . V_5 = V_7 [ V_6 ] . V_5 ;
break;
}
V_6 ++ ;
}
return;
}
static void F_3 ( struct V_10 * V_11 ,
enum V_12 V_13 ,
T_2 V_14 )
{
switch ( V_13 ) {
case V_15 :
F_1 ( V_11 -> V_16 , 0x06 , 0x1f , 0x12 ) ;
break;
case V_17 :
F_1 ( V_11 -> V_16 , 0x06 , 0x1f , 0x11 ) ;
break;
case V_18 :
F_1 ( V_11 -> V_16 , 0x06 , 0x1f , 0x10 ) ;
break;
case V_19 :
F_1 ( V_11 -> V_20 , 0x09 , 0xff , 0xc1 ) ;
F_1 ( V_11 -> V_20 , 0x0a , 0xff ,
8 - V_14 ) ;
F_1 ( V_11 -> V_20 , 0x0b , 0xff , 0x17 ) ;
break;
default:
F_4 ( - V_21 ) ;
}
return;
}
static void F_5 ( struct V_10 * V_11 ,
enum V_22 V_23 ,
int V_24 )
{
T_1 V_5 ;
switch ( V_23 ) {
case V_25 :
V_5 = 0x00 ;
break;
case V_26 :
V_5 = 0x02 ;
break;
case V_27 :
V_5 = 0x03 ;
break;
case V_28 :
V_5 = 0x04 ;
break;
case V_29 :
V_5 = 0x05 ;
break;
case V_30 :
V_5 = 0x06 ;
break;
case V_31 :
V_5 = 0x07 ;
break;
case V_32 :
V_5 = 0x08 ;
break;
case V_33 :
V_5 = 0x09 ;
break;
case V_34 :
V_5 = 0x0a ;
break;
case V_35 :
V_5 = 0x0b ;
break;
default:
F_4 ( - V_21 ) ;
return;
}
F_1 ( V_11 -> V_16 , 0x02 , 0x0f , V_5 ) ;
F_1 ( V_11 -> V_16 , 0x02 , 0x10 , V_24 ? 0x10 : 0x00 ) ;
return;
}
static void F_6 ( struct V_10 * V_11 ,
enum V_36 V_37 )
{
switch ( V_37 ) {
case V_38 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0x00 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x00 ) ;
break;
case V_39 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0x10 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x01 ) ;
break;
case V_40 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0x20 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x02 ) ;
break;
case V_41 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0x30 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x03 ) ;
break;
case V_42 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0x40 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x04 ) ;
break;
case V_43 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0x50 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x05 ) ;
break;
case V_44 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0x60 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x06 ) ;
break;
case V_45 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0x70 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x07 ) ;
break;
case V_46 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0x80 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x08 ) ;
break;
case V_47 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0x90 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x09 ) ;
break;
case V_48 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0xa0 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x0a ) ;
break;
case V_49 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0xb0 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x0b ) ;
break;
case V_50 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0xc0 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x0c ) ;
break;
case V_51 :
F_1 ( V_11 -> V_16 , 0x03 , 0xf0 , 0xd0 ) ;
F_1 ( V_11 -> V_16 , 0x05 , 0x0f , 0x0d ) ;
break;
default:
F_4 ( - V_21 ) ;
return;
}
return;
}
static struct V_1 * F_7 ( struct V_10 * V_11 ,
enum V_12 V_13 )
{
struct V_52 * V_53 = V_11 -> V_54 ;
memcpy ( & V_11 -> V_16 , & V_55 , sizeof( V_55 ) ) ;
memcpy ( & V_11 -> V_20 , & V_56 , sizeof( V_56 ) ) ;
F_3 ( V_11 , V_13 , V_53 -> V_14 ) ;
F_5 ( V_11 , V_53 -> V_57 , V_53 -> V_24 ) ;
F_6 ( V_11 , V_53 -> V_58 ) ;
F_1 ( V_11 -> V_16 , 0x04 , 0x01 , V_53 -> V_59 ) ;
F_1 ( V_11 -> V_16 , 0x03 , 0x08 , V_53 -> V_60 << 3 ) ;
F_1 ( V_11 -> V_16 , 0x03 , 0x07 , V_53 -> V_61 ) ;
if ( V_13 >= V_19 ) {
F_2 ( V_11 -> V_16 , V_11 -> V_20 ) ;
return V_11 -> V_20 ;
} else
return V_11 -> V_16 ;
}
static void F_8 ( struct V_10 * V_11 ,
enum V_62 V_63 )
{
T_1 V_5 ;
switch ( V_63 ) {
case V_64 :
V_5 = 0x15 ;
break;
case V_65 :
V_5 = 0x2a ;
break;
case V_66 :
V_5 = 0x3f ;
break;
default:
F_4 ( - V_21 ) ;
return;
}
F_1 ( V_11 -> V_67 , 0x0c , 0x3f , V_5 ) ;
return;
}
static struct
V_1 * F_9 ( struct V_10 * V_11 ,
T_3 V_68 , enum V_62 V_63 )
{
T_3 V_69 = 0 ;
T_3 V_70 ;
T_3 V_71 = 1000000 ;
unsigned int V_6 ;
memcpy ( & V_11 -> V_67 , & V_72 , sizeof( V_72 ) ) ;
F_8 ( V_11 , V_63 ) ;
V_69 = V_68 / V_73 ;
V_70 = V_68 % V_73 ;
for ( V_6 = 0 ; V_6 < 6 ; V_6 ++ ) {
V_69 <<= 1 ;
V_71 /= 2 ;
if ( V_70 > V_71 ) {
V_70 -= V_71 ;
V_69 ++ ;
}
}
if ( V_70 > 7812 )
V_69 ++ ;
F_1 ( V_11 -> V_67 , 0x0d , 0xff , ( T_1 ) V_69 ) ;
F_1 ( V_11 -> V_67 , 0x0e , 0xff , ( T_1 ) ( V_69 >> 8 ) ) ;
if ( V_68 >= 333000000 )
F_1 ( V_11 -> V_67 , 0x80 , 0x40 , 0x40 ) ;
return V_11 -> V_67 ;
}
static int F_10 ( struct V_10 * V_11 , T_1 V_3 , T_1 V_5 )
{
T_1 V_74 [] = { V_3 , V_5 } ;
struct V_75 V_76 = { . V_77 = V_11 -> V_78 . V_77 , . V_79 = 0 ,
. V_74 = V_74 , . V_80 = 2 } ;
int V_81 ;
V_81 = F_11 ( V_11 -> V_78 . V_82 , & V_76 , 1 ) ;
if ( V_81 != 1 ) {
F_12 ( L_1 ) ;
return - V_83 ;
}
return 0 ;
}
static int F_13 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
unsigned int V_6 = 0 ;
int V_81 = 0 ;
while ( ( V_81 == 0 ) && ( V_2 [ V_6 ] . V_3 || V_2 [ V_6 ] . V_5 ) ) {
V_81 = F_10 ( V_11 ,
V_2 [ V_6 ] . V_3 , V_2 [ V_6 ] . V_5 ) ;
V_6 ++ ;
}
return V_81 ;
}
static int F_14 ( struct V_10 * V_11 , T_1 V_3 , T_1 * V_5 )
{
T_1 V_74 [ 2 ] = { 0xfb , V_3 } ;
struct V_75 V_76 [] = {
{ . V_77 = V_11 -> V_78 . V_77 , . V_79 = 0 ,
. V_74 = V_74 , . V_80 = 2 } ,
{ . V_77 = V_11 -> V_78 . V_77 , . V_79 = V_84 ,
. V_74 = V_5 , . V_80 = 1 } ,
} ;
int V_81 ;
V_81 = F_11 ( V_11 -> V_78 . V_82 , V_76 , 2 ) ;
if ( V_81 != 2 ) {
F_12 ( L_1 ) ;
return - V_83 ;
}
return 0 ;
}
static int F_15 ( struct V_10 * V_11 )
{
T_1 V_85 = 0xff ;
struct V_75 V_76 = {
. V_77 = V_11 -> V_78 . V_77 , . V_79 = 0 ,
. V_74 = & V_85 , . V_80 = 1
} ;
int V_81 = F_11 ( V_11 -> V_78 . V_82 , & V_76 , 1 ) ;
if ( V_81 != 1 ) {
F_12 ( L_1 ) ;
return - V_83 ;
}
return 0 ;
}
static int F_16 ( struct V_10 * V_11 ,
enum V_12 V_13 )
{
struct V_1 * V_86 ;
int V_81 ;
V_81 = F_15 ( V_11 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
V_86 = F_7 ( V_11 , V_13 ) ;
V_81 = F_13 ( V_11 , V_86 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
F_17 ( 1 ) ;
V_87:
return V_81 ;
}
static int F_18 ( struct V_10 * V_11 , T_3 V_88 ,
enum V_62 V_63 )
{
struct V_1 * V_89 ;
int V_81 ;
V_89 = F_9 ( V_11 , V_88 , V_63 ) ;
V_81 = F_13 ( V_11 , V_89 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
F_19 ( 3 ) ;
V_87:
return V_81 ;
}
static int F_20 ( struct V_10 * V_11 ,
int * V_90 , int * V_91 )
{
T_1 V_85 ;
int V_81 ;
* V_90 = 0 ;
* V_91 = 0 ;
V_81 = F_14 ( V_11 , 0xd8 , & V_85 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
if ( ( V_85 & 0x0c ) == 0x0c )
* V_90 = 1 ;
if ( ( V_85 & 0x03 ) == 0x03 )
* V_91 = 1 ;
V_87:
return V_81 ;
}
static int F_21 ( struct V_92 * V_93 , T_3 * V_94 )
{
struct V_10 * V_11 = V_93 -> V_95 ;
int V_90 , V_91 , V_81 ;
* V_94 = 0 ;
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 1 ) ;
V_81 = F_20 ( V_11 , & V_90 , & V_91 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
F_22 ( L_2 , V_90 ? L_3 : L_4 ,
V_91 ? L_5 : L_4 ) ;
if ( ( V_90 ) || ( V_91 ) )
* V_94 |= V_98 ;
V_87:
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 0 ) ;
return V_81 ;
}
static int F_23 ( struct V_92 * V_93 ,
struct V_99 * V_100 )
{
struct V_10 * V_11 = V_93 -> V_95 ;
enum V_62 V_63 ;
enum V_12 V_13 ;
int V_81 ;
T_3 V_101 = V_100 -> V_102 ;
if ( V_93 -> V_96 . V_103 . type == V_104 ) {
switch ( V_100 -> V_105 . V_106 . V_107 ) {
case V_108 :
case V_109 :
V_13 = V_15 ;
break;
case V_110 :
case V_111 :
V_13 = V_19 ;
break;
default:
F_12 ( L_6 ) ;
return - V_21 ;
}
V_63 = V_64 ;
} else if ( V_93 -> V_96 . V_103 . type == V_112 ) {
switch ( V_100 -> V_105 . V_113 . V_114 ) {
case V_115 :
V_63 = V_64 ;
break;
case V_116 :
V_63 = V_65 ;
break;
case V_117 :
V_63 = V_66 ;
break;
default:
F_12 ( L_7 ) ;
return - V_21 ;
}
V_13 = V_17 ;
} else {
F_12 ( L_8 ) ;
return - V_21 ;
}
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 1 ) ;
F_24 ( & V_11 -> V_118 ) ;
V_81 = F_16 ( V_11 , V_13 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
V_81 = F_18 ( V_11 , V_101 , V_63 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
V_11 -> V_102 = V_101 ;
V_11 -> V_114 = ( V_93 -> V_96 . V_103 . type == V_112 ) ?
V_100 -> V_105 . V_113 . V_114 : 0 ;
V_87:
F_25 ( & V_11 -> V_118 ) ;
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 0 ) ;
return V_81 ;
}
static int F_26 ( struct V_92 * V_93 )
{
struct V_10 * V_11 = V_93 -> V_95 ;
int V_81 ;
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 1 ) ;
V_81 = F_10 ( V_11 , 0x01 , 0x01 ) ;
F_4 ( V_81 ) ;
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 0 ) ;
return V_81 ;
}
static int F_27 ( struct V_92 * V_93 )
{
struct V_10 * V_11 = V_93 -> V_95 ;
int V_81 ;
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 1 ) ;
V_81 = F_10 ( V_11 , 0x01 , 0x00 ) ;
F_4 ( V_81 ) ;
V_81 = F_10 ( V_11 , 0x0f , 0x00 ) ;
F_4 ( V_81 ) ;
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 0 ) ;
return V_81 ;
}
static int F_28 ( struct V_92 * V_93 , T_3 * V_102 )
{
struct V_10 * V_11 = V_93 -> V_95 ;
* V_102 = V_11 -> V_102 ;
return 0 ;
}
static int F_29 ( struct V_92 * V_93 , T_3 * V_114 )
{
struct V_10 * V_11 = V_93 -> V_95 ;
* V_114 = V_11 -> V_114 ;
return 0 ;
}
static int F_30 ( struct V_92 * V_93 )
{
struct V_10 * V_11 = V_93 -> V_95 ;
F_24 ( & V_119 ) ;
if ( V_11 )
F_31 ( V_11 ) ;
F_25 ( & V_119 ) ;
V_93 -> V_95 = NULL ;
return 0 ;
}
static int F_32 ( struct V_10 * V_11 )
{
char * V_120 ;
int V_81 ;
T_1 V_121 ;
V_81 = F_14 ( V_11 , 0xd9 , & V_121 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
switch ( V_121 ) {
case V_122 :
V_120 = L_9 ;
break;
case V_123 :
V_120 = L_10 ;
break;
case V_124 :
V_120 = L_11 ;
break;
case V_125 :
V_120 = L_12 ;
break;
case V_126 :
V_120 = L_13 ;
break;
case V_127 :
V_120 = L_14 ;
break;
case V_128 :
V_120 = L_15 ;
break;
default:
V_120 = L_16 ;
F_33 ( V_129 L_17 , V_130 , V_121 ) ;
V_121 = V_131 ;
}
V_11 -> V_132 = V_121 ;
F_34 ( L_18 , V_120 ,
F_35 ( V_11 -> V_78 . V_82 ) ,
V_11 -> V_78 . V_77 ) ;
return 0 ;
V_87:
F_36 ( L_19 ,
F_35 ( V_11 -> V_78 . V_82 ) ,
V_11 -> V_78 . V_77 ) ;
V_11 -> V_132 = V_131 ;
return V_81 ;
}
struct V_92 * F_37 ( struct V_92 * V_93 ,
struct V_133 * V_134 , T_1 V_77 ,
struct V_52 * V_53 )
{
struct V_10 * V_11 = NULL ;
int V_135 , V_81 ;
F_24 ( & V_119 ) ;
V_135 = F_38 ( struct V_10 , V_11 ,
V_136 ,
V_134 , V_77 , L_20 ) ;
switch ( V_135 ) {
case 0 :
goto V_87;
case 1 :
V_11 -> V_54 = V_53 ;
F_39 ( & V_11 -> V_118 ) ;
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 1 ) ;
V_81 = F_32 ( V_11 ) ;
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 0 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
break;
default:
break;
}
V_93 -> V_95 = V_11 ;
F_25 ( & V_119 ) ;
memcpy ( & V_93 -> V_96 . V_137 , & V_138 ,
sizeof( struct V_139 ) ) ;
return V_93 ;
V_87:
F_25 ( & V_119 ) ;
F_30 ( V_93 ) ;
return NULL ;
}
