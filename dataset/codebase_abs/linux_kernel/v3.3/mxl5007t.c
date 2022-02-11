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
V_11 -> V_23 = V_23 ;
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
static int F_23 ( struct V_92 * V_93 )
{
struct V_99 * V_100 = & V_93 -> V_101 ;
T_3 V_102 = V_100 -> V_103 ;
struct V_10 * V_11 = V_93 -> V_95 ;
enum V_62 V_63 ;
enum V_12 V_13 ;
int V_81 ;
T_3 V_104 = V_100 -> V_105 ;
switch ( V_102 ) {
case V_106 :
V_13 = V_15 ;
V_63 = V_64 ;
break;
case V_107 :
V_13 = V_19 ;
V_63 = V_64 ;
break;
case V_108 :
case V_109 :
V_13 = V_17 ;
switch ( V_100 -> V_110 ) {
case 6000000 :
V_63 = V_64 ;
break;
case 7000000 :
V_63 = V_65 ;
break;
case 8000000 :
V_63 = V_66 ;
break;
default:
return - V_21 ;
}
break;
default:
F_12 ( L_6 ) ;
return - V_21 ;
}
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 1 ) ;
F_24 ( & V_11 -> V_111 ) ;
V_81 = F_16 ( V_11 , V_13 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
V_81 = F_18 ( V_11 , V_104 , V_63 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
V_11 -> V_105 = V_104 ;
V_11 -> V_112 = V_100 -> V_110 ;
V_87:
F_25 ( & V_11 -> V_111 ) ;
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
static int F_28 ( struct V_92 * V_93 , T_3 * V_105 )
{
struct V_10 * V_11 = V_93 -> V_95 ;
* V_105 = V_11 -> V_105 ;
return 0 ;
}
static int F_29 ( struct V_92 * V_93 , T_3 * V_112 )
{
struct V_10 * V_11 = V_93 -> V_95 ;
* V_112 = V_11 -> V_112 ;
return 0 ;
}
static int F_30 ( struct V_92 * V_93 , T_3 * V_105 )
{
struct V_10 * V_11 = V_93 -> V_95 ;
* V_105 = 0 ;
switch ( V_11 -> V_23 ) {
case V_25 :
* V_105 = 4000000 ;
break;
case V_26 :
* V_105 = 4500000 ;
break;
case V_27 :
* V_105 = 4570000 ;
break;
case V_28 :
* V_105 = 5000000 ;
break;
case V_29 :
* V_105 = 5380000 ;
break;
case V_30 :
* V_105 = 6000000 ;
break;
case V_31 :
* V_105 = 6280000 ;
break;
case V_32 :
* V_105 = 9191500 ;
break;
case V_33 :
* V_105 = 35250000 ;
break;
case V_34 :
* V_105 = 36150000 ;
break;
case V_35 :
* V_105 = 44000000 ;
break;
}
return 0 ;
}
static int F_31 ( struct V_92 * V_93 )
{
struct V_10 * V_11 = V_93 -> V_95 ;
F_24 ( & V_113 ) ;
if ( V_11 )
F_32 ( V_11 ) ;
F_25 ( & V_113 ) ;
V_93 -> V_95 = NULL ;
return 0 ;
}
static int F_33 ( struct V_10 * V_11 )
{
char * V_114 ;
int V_81 ;
T_1 V_115 ;
V_81 = F_14 ( V_11 , 0xd9 , & V_115 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
switch ( V_115 ) {
case V_116 :
V_114 = L_7 ;
break;
case V_117 :
V_114 = L_8 ;
break;
case V_118 :
V_114 = L_9 ;
break;
case V_119 :
V_114 = L_10 ;
break;
case V_120 :
V_114 = L_11 ;
break;
case V_121 :
V_114 = L_12 ;
break;
case V_122 :
V_114 = L_13 ;
break;
default:
V_114 = L_14 ;
F_34 ( V_123 L_15 , V_124 , V_115 ) ;
V_115 = V_125 ;
}
V_11 -> V_126 = V_115 ;
F_35 ( L_16 , V_114 ,
F_36 ( V_11 -> V_78 . V_82 ) ,
V_11 -> V_78 . V_77 ) ;
return 0 ;
V_87:
F_37 ( L_17 ,
F_36 ( V_11 -> V_78 . V_82 ) ,
V_11 -> V_78 . V_77 ) ;
V_11 -> V_126 = V_125 ;
return V_81 ;
}
struct V_92 * F_38 ( struct V_92 * V_93 ,
struct V_127 * V_128 , T_1 V_77 ,
struct V_52 * V_53 )
{
struct V_10 * V_11 = NULL ;
int V_129 , V_81 ;
F_24 ( & V_113 ) ;
V_129 = F_39 ( struct V_10 , V_11 ,
V_130 ,
V_128 , V_77 , L_18 ) ;
switch ( V_129 ) {
case 0 :
goto V_87;
case 1 :
V_11 -> V_54 = V_53 ;
F_40 ( & V_11 -> V_111 ) ;
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 1 ) ;
V_81 = F_33 ( V_11 ) ;
if ( V_93 -> V_96 . V_97 )
V_93 -> V_96 . V_97 ( V_93 , 0 ) ;
if ( F_4 ( V_81 ) )
goto V_87;
break;
default:
break;
}
V_93 -> V_95 = V_11 ;
F_25 ( & V_113 ) ;
memcpy ( & V_93 -> V_96 . V_131 , & V_132 ,
sizeof( struct V_133 ) ) ;
return V_93 ;
V_87:
F_25 ( & V_113 ) ;
F_31 ( V_93 ) ;
return NULL ;
}
