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
F_1 ( V_11 -> V_16 , 0x03 , 0x08 , V_53 -> V_59 << 3 ) ;
F_1 ( V_11 -> V_16 , 0x03 , 0x07 , V_53 -> V_60 ) ;
if ( V_13 >= V_19 ) {
F_2 ( V_11 -> V_16 , V_11 -> V_20 ) ;
return V_11 -> V_20 ;
} else
return V_11 -> V_16 ;
}
static void F_8 ( struct V_10 * V_11 ,
enum V_61 V_62 )
{
T_1 V_5 ;
switch ( V_62 ) {
case V_63 :
V_5 = 0x15 ;
break;
case V_64 :
V_5 = 0x2a ;
break;
case V_65 :
V_5 = 0x3f ;
break;
default:
F_4 ( - V_21 ) ;
return;
}
F_1 ( V_11 -> V_66 , 0x0c , 0x3f , V_5 ) ;
return;
}
static struct
V_1 * F_9 ( struct V_10 * V_11 ,
T_3 V_67 , enum V_61 V_62 )
{
T_3 V_68 = 0 ;
T_3 V_69 ;
T_3 V_70 = 1000000 ;
unsigned int V_6 ;
memcpy ( & V_11 -> V_66 , & V_71 , sizeof( V_71 ) ) ;
F_8 ( V_11 , V_62 ) ;
V_68 = V_67 / V_72 ;
V_69 = V_67 % V_72 ;
for ( V_6 = 0 ; V_6 < 6 ; V_6 ++ ) {
V_68 <<= 1 ;
V_70 /= 2 ;
if ( V_69 > V_70 ) {
V_69 -= V_70 ;
V_68 ++ ;
}
}
if ( V_69 > 7812 )
V_68 ++ ;
F_1 ( V_11 -> V_66 , 0x0d , 0xff , ( T_1 ) V_68 ) ;
F_1 ( V_11 -> V_66 , 0x0e , 0xff , ( T_1 ) ( V_68 >> 8 ) ) ;
if ( V_67 >= 333000000 )
F_1 ( V_11 -> V_66 , 0x80 , 0x40 , 0x40 ) ;
return V_11 -> V_66 ;
}
static int F_10 ( struct V_10 * V_11 , T_1 V_3 , T_1 V_5 )
{
T_1 V_73 [] = { V_3 , V_5 } ;
struct V_74 V_75 = { . V_76 = V_11 -> V_77 . V_76 , . V_78 = 0 ,
. V_73 = V_73 , . V_79 = 2 } ;
int V_80 ;
V_80 = F_11 ( V_11 -> V_77 . V_81 , & V_75 , 1 ) ;
if ( V_80 != 1 ) {
F_12 ( L_1 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_13 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
unsigned int V_6 = 0 ;
int V_80 = 0 ;
while ( ( V_80 == 0 ) && ( V_2 [ V_6 ] . V_3 || V_2 [ V_6 ] . V_5 ) ) {
V_80 = F_10 ( V_11 ,
V_2 [ V_6 ] . V_3 , V_2 [ V_6 ] . V_5 ) ;
V_6 ++ ;
}
return V_80 ;
}
static int F_14 ( struct V_10 * V_11 , T_1 V_3 , T_1 * V_5 )
{
T_1 V_73 [ 2 ] = { 0xfb , V_3 } ;
struct V_74 V_75 [] = {
{ . V_76 = V_11 -> V_77 . V_76 , . V_78 = 0 ,
. V_73 = V_73 , . V_79 = 2 } ,
{ . V_76 = V_11 -> V_77 . V_76 , . V_78 = V_83 ,
. V_73 = V_5 , . V_79 = 1 } ,
} ;
int V_80 ;
V_80 = F_11 ( V_11 -> V_77 . V_81 , V_75 , 2 ) ;
if ( V_80 != 2 ) {
F_12 ( L_1 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_15 ( struct V_10 * V_11 )
{
T_1 V_84 = 0xff ;
struct V_74 V_75 = {
. V_76 = V_11 -> V_77 . V_76 , . V_78 = 0 ,
. V_73 = & V_84 , . V_79 = 1
} ;
int V_80 = F_11 ( V_11 -> V_77 . V_81 , & V_75 , 1 ) ;
if ( V_80 != 1 ) {
F_12 ( L_1 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_16 ( struct V_10 * V_11 ,
enum V_12 V_13 )
{
struct V_1 * V_85 ;
int V_80 ;
V_85 = F_7 ( V_11 , V_13 ) ;
V_80 = F_13 ( V_11 , V_85 ) ;
if ( F_4 ( V_80 ) )
goto V_86;
F_17 ( 1 ) ;
V_86:
return V_80 ;
}
static int F_18 ( struct V_10 * V_11 , T_3 V_87 ,
enum V_61 V_62 )
{
struct V_1 * V_88 ;
int V_80 ;
V_88 = F_9 ( V_11 , V_87 , V_62 ) ;
V_80 = F_13 ( V_11 , V_88 ) ;
if ( F_4 ( V_80 ) )
goto V_86;
F_19 ( 3 ) ;
V_86:
return V_80 ;
}
static int F_20 ( struct V_10 * V_11 ,
int * V_89 , int * V_90 )
{
T_1 V_84 ;
int V_80 ;
* V_89 = 0 ;
* V_90 = 0 ;
V_80 = F_14 ( V_11 , 0xd8 , & V_84 ) ;
if ( F_4 ( V_80 ) )
goto V_86;
if ( ( V_84 & 0x0c ) == 0x0c )
* V_89 = 1 ;
if ( ( V_84 & 0x03 ) == 0x03 )
* V_90 = 1 ;
V_86:
return V_80 ;
}
static int F_21 ( struct V_91 * V_92 , T_3 * V_93 )
{
struct V_10 * V_11 = V_92 -> V_94 ;
int V_89 , V_90 , V_80 ;
* V_93 = 0 ;
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 1 ) ;
V_80 = F_20 ( V_11 , & V_89 , & V_90 ) ;
if ( F_4 ( V_80 ) )
goto V_86;
F_22 ( L_2 , V_89 ? L_3 : L_4 ,
V_90 ? L_5 : L_4 ) ;
if ( ( V_89 ) || ( V_90 ) )
* V_93 |= V_97 ;
V_86:
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 0 ) ;
return V_80 ;
}
static int F_23 ( struct V_91 * V_92 )
{
struct V_98 * V_99 = & V_92 -> V_100 ;
T_3 V_101 = V_99 -> V_102 ;
struct V_10 * V_11 = V_92 -> V_94 ;
enum V_61 V_62 ;
enum V_12 V_13 ;
int V_80 ;
T_3 V_103 = V_99 -> V_104 ;
switch ( V_101 ) {
case V_105 :
V_13 = V_15 ;
V_62 = V_63 ;
break;
case V_106 :
V_13 = V_19 ;
V_62 = V_63 ;
break;
case V_107 :
case V_108 :
V_13 = V_17 ;
switch ( V_99 -> V_109 ) {
case 6000000 :
V_62 = V_63 ;
break;
case 7000000 :
V_62 = V_64 ;
break;
case 8000000 :
V_62 = V_65 ;
break;
default:
return - V_21 ;
}
break;
default:
F_12 ( L_6 ) ;
return - V_21 ;
}
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 1 ) ;
F_24 ( & V_11 -> V_110 ) ;
V_80 = F_16 ( V_11 , V_13 ) ;
if ( F_4 ( V_80 ) )
goto V_86;
V_80 = F_18 ( V_11 , V_103 , V_62 ) ;
if ( F_4 ( V_80 ) )
goto V_86;
V_11 -> V_104 = V_103 ;
V_11 -> V_111 = V_99 -> V_109 ;
V_86:
F_25 ( & V_11 -> V_110 ) ;
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 0 ) ;
return V_80 ;
}
static int F_26 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = V_92 -> V_94 ;
int V_80 ;
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 1 ) ;
V_80 = F_10 ( V_11 , 0x01 , 0x01 ) ;
F_4 ( V_80 ) ;
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 0 ) ;
return V_80 ;
}
static int F_27 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = V_92 -> V_94 ;
int V_80 ;
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 1 ) ;
V_80 = F_10 ( V_11 , 0x01 , 0x00 ) ;
F_4 ( V_80 ) ;
V_80 = F_10 ( V_11 , 0x0f , 0x00 ) ;
F_4 ( V_80 ) ;
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 0 ) ;
return V_80 ;
}
static int F_28 ( struct V_91 * V_92 , T_3 * V_104 )
{
struct V_10 * V_11 = V_92 -> V_94 ;
* V_104 = V_11 -> V_104 ;
return 0 ;
}
static int F_29 ( struct V_91 * V_92 , T_3 * V_111 )
{
struct V_10 * V_11 = V_92 -> V_94 ;
* V_111 = V_11 -> V_111 ;
return 0 ;
}
static int F_30 ( struct V_91 * V_92 , T_3 * V_104 )
{
struct V_10 * V_11 = V_92 -> V_94 ;
* V_104 = 0 ;
switch ( V_11 -> V_23 ) {
case V_25 :
* V_104 = 4000000 ;
break;
case V_26 :
* V_104 = 4500000 ;
break;
case V_27 :
* V_104 = 4570000 ;
break;
case V_28 :
* V_104 = 5000000 ;
break;
case V_29 :
* V_104 = 5380000 ;
break;
case V_30 :
* V_104 = 6000000 ;
break;
case V_31 :
* V_104 = 6280000 ;
break;
case V_32 :
* V_104 = 9191500 ;
break;
case V_33 :
* V_104 = 35250000 ;
break;
case V_34 :
* V_104 = 36150000 ;
break;
case V_35 :
* V_104 = 44000000 ;
break;
}
return 0 ;
}
static void F_31 ( struct V_91 * V_92 )
{
struct V_10 * V_11 = V_92 -> V_94 ;
F_24 ( & V_112 ) ;
if ( V_11 )
F_32 ( V_11 ) ;
F_25 ( & V_112 ) ;
V_92 -> V_94 = NULL ;
}
static int F_33 ( struct V_10 * V_11 )
{
char * V_113 ;
int V_80 ;
T_1 V_114 ;
V_80 = F_14 ( V_11 , 0xd9 , & V_114 ) ;
if ( F_4 ( V_80 ) )
goto V_86;
switch ( V_114 ) {
case V_115 :
V_113 = L_7 ;
break;
case V_116 :
V_113 = L_8 ;
break;
case V_117 :
V_113 = L_9 ;
break;
case V_118 :
V_113 = L_10 ;
break;
case V_119 :
V_113 = L_11 ;
break;
case V_120 :
V_113 = L_12 ;
break;
case V_121 :
V_113 = L_13 ;
break;
default:
V_113 = L_14 ;
F_34 ( V_122 L_15 , V_123 , V_114 ) ;
V_114 = V_124 ;
}
V_11 -> V_125 = V_114 ;
F_35 ( L_16 , V_113 ,
F_36 ( V_11 -> V_77 . V_81 ) ,
V_11 -> V_77 . V_76 ) ;
return 0 ;
V_86:
F_37 ( L_17 ,
F_36 ( V_11 -> V_77 . V_81 ) ,
V_11 -> V_77 . V_76 ) ;
V_11 -> V_125 = V_124 ;
return V_80 ;
}
struct V_91 * F_38 ( struct V_91 * V_92 ,
struct V_126 * V_127 , T_1 V_76 ,
struct V_52 * V_53 )
{
struct V_10 * V_11 = NULL ;
int V_128 , V_80 ;
F_24 ( & V_112 ) ;
V_128 = F_39 ( struct V_10 , V_11 ,
V_129 ,
V_127 , V_76 , L_18 ) ;
switch ( V_128 ) {
case 0 :
goto V_86;
case 1 :
V_11 -> V_54 = V_53 ;
F_40 ( & V_11 -> V_110 ) ;
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 1 ) ;
V_80 = F_33 ( V_11 ) ;
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 0 ) ;
if ( F_4 ( V_80 ) )
goto V_86;
break;
default:
break;
}
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 1 ) ;
V_80 = F_15 ( V_11 ) ;
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 0 ) ;
if ( F_4 ( V_80 ) )
goto V_86;
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 1 ) ;
V_80 = F_10 ( V_11 , 0x04 ,
V_11 -> V_54 -> V_130 ) ;
if ( V_92 -> V_95 . V_96 )
V_92 -> V_95 . V_96 ( V_92 , 0 ) ;
if ( F_4 ( V_80 ) )
goto V_86;
V_92 -> V_94 = V_11 ;
F_25 ( & V_112 ) ;
memcpy ( & V_92 -> V_95 . V_131 , & V_132 ,
sizeof( struct V_133 ) ) ;
return V_92 ;
V_86:
F_25 ( & V_112 ) ;
F_31 ( V_92 ) ;
return NULL ;
}
