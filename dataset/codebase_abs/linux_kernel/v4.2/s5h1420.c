static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
T_1 V_5 [ 2 ] ;
struct V_6 V_7 [] = {
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_12 = V_5 , . V_13 = 2 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_12 = & V_3 , . V_13 = 1 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_14 , . V_12 = V_5 , . V_13 = 1 } ,
} ;
V_5 [ 0 ] = ( V_3 - 1 ) & 0xff ;
V_5 [ 1 ] = V_2 -> V_15 [ ( V_3 - 1 ) & 0xff ] ;
if ( V_2 -> V_9 -> V_16 ) {
V_4 = F_2 ( V_2 -> V_17 , V_7 , 3 ) ;
if ( V_4 != 3 )
return V_4 ;
} else {
V_4 = F_2 ( V_2 -> V_17 , & V_7 [ 1 ] , 1 ) ;
if ( V_4 != 1 )
return V_4 ;
V_4 = F_2 ( V_2 -> V_17 , & V_7 [ 2 ] , 1 ) ;
if ( V_4 != 1 )
return V_4 ;
}
return V_5 [ 0 ] ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_18 )
{
T_1 V_12 [] = { V_3 , V_18 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_12 = V_12 , . V_13 = 2 } ;
int V_19 ;
V_19 = F_2 ( V_2 -> V_17 , & V_7 , 1 ) ;
if ( V_19 != 1 ) {
F_4 ( L_1 , V_20 , V_19 , V_3 , V_18 ) ;
return - V_21 ;
}
V_2 -> V_15 [ V_3 ] = V_18 ;
return 0 ;
}
static int F_5 ( struct V_22 * V_23 ,
enum V_24 V_25 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_4 ( L_2 , V_20 ) ;
switch( V_25 ) {
case V_27 :
F_3 ( V_2 , 0x3c ,
( F_1 ( V_2 , 0x3c ) & 0xfe ) | 0x02 ) ;
break;
case V_28 :
F_3 ( V_2 , 0x3c , F_1 ( V_2 , 0x3c ) | 0x03 ) ;
break;
case V_29 :
F_3 ( V_2 , 0x3c , F_1 ( V_2 , 0x3c ) & 0xfd ) ;
break;
}
F_4 ( L_3 , V_20 ) ;
return 0 ;
}
static int F_6 ( struct V_22 * V_23 ,
enum V_30 V_31 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_4 ( L_2 , V_20 ) ;
switch( V_31 ) {
case V_32 :
F_3 ( V_2 , 0x3b ,
( F_1 ( V_2 , 0x3b ) & 0x74 ) | 0x08 ) ;
break;
case V_33 :
F_3 ( V_2 , 0x3b ,
( F_1 ( V_2 , 0x3b ) & 0x74 ) | 0x01 ) ;
break;
}
F_4 ( L_3 , V_20 ) ;
return 0 ;
}
static int F_7 ( struct V_22 * V_23 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_1 V_36 ;
int V_37 ;
unsigned long V_38 ;
int V_39 = 0 ;
F_4 ( L_2 , V_20 ) ;
if ( V_35 -> V_40 > sizeof( V_35 -> V_7 ) )
return - V_41 ;
V_36 = F_1 ( V_2 , 0x3b ) ;
F_3 ( V_2 , 0x3b , 0x02 ) ;
F_8 ( 15 ) ;
for( V_37 = 0 ; V_37 < V_35 -> V_40 ; V_37 ++ ) {
F_3 ( V_2 , 0x3d + V_37 , V_35 -> V_7 [ V_37 ] ) ;
}
F_3 ( V_2 , 0x3b , F_1 ( V_2 , 0x3b ) |
( ( V_35 -> V_40 - 1 ) << 4 ) | 0x08 ) ;
V_38 = V_42 + ( ( 100 * V_43 ) / 1000 ) ;
while( F_9 ( V_42 , V_38 ) ) {
if ( ! ( F_1 ( V_2 , 0x3b ) & 0x08 ) )
break;
F_8 ( 5 ) ;
}
if ( F_10 ( V_42 , V_38 ) )
V_39 = - V_44 ;
F_3 ( V_2 , 0x3b , V_36 ) ;
F_8 ( 15 ) ;
F_4 ( L_3 , V_20 ) ;
return V_39 ;
}
static int F_11 ( struct V_22 * V_23 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_1 V_36 ;
int V_37 ;
int V_47 ;
unsigned long V_38 ;
int V_39 = 0 ;
V_36 = F_1 ( V_2 , 0x3b ) ;
F_3 ( V_2 , 0x3b , 0x82 ) ;
F_8 ( 15 ) ;
V_38 = V_42 + ( ( V_46 -> V_38 * V_43 ) / 1000 ) ;
while( F_9 ( V_42 , V_38 ) ) {
if ( ! ( F_1 ( V_2 , 0x3b ) & 0x80 ) )
break;
F_8 ( 5 ) ;
}
if ( F_10 ( V_42 , V_38 ) ) {
V_39 = - V_44 ;
goto exit;
}
if ( F_1 ( V_2 , 0x49 ) ) {
V_39 = - V_48 ;
goto exit;
}
V_47 = ( F_1 ( V_2 , 0x3b ) & 0x70 ) >> 4 ;
if ( V_47 > sizeof( V_46 -> V_7 ) ) {
V_39 = - V_49 ;
goto exit;
}
V_46 -> V_40 = V_47 ;
for( V_37 = 0 ; V_37 < V_47 ; V_37 ++ ) {
V_46 -> V_7 [ V_37 ] = F_1 ( V_2 , 0x3d + V_37 ) ;
}
exit:
F_3 ( V_2 , 0x3b , V_36 ) ;
F_8 ( 15 ) ;
return V_39 ;
}
static int F_12 ( struct V_22 * V_23 ,
enum V_50 V_51 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_1 V_36 ;
int V_39 = 0 ;
unsigned long V_38 ;
V_36 = F_1 ( V_2 , 0x3b ) ;
F_3 ( V_2 , 0x3b , ( F_1 ( V_2 , 0x3b ) & 0x70 ) | 0x01 ) ;
if ( V_51 == V_52 ) {
F_3 ( V_2 , 0x3b , F_1 ( V_2 , 0x3b ) | 0x04 ) ;
}
F_8 ( 15 ) ;
F_3 ( V_2 , 0x3b , F_1 ( V_2 , 0x3b ) | 0x08 ) ;
V_38 = V_42 + ( ( 100 * V_43 ) / 1000 ) ;
while( F_9 ( V_42 , V_38 ) ) {
if ( ! ( F_1 ( V_2 , 0x3b ) & 0x08 ) )
break;
F_8 ( 5 ) ;
}
if ( F_10 ( V_42 , V_38 ) )
V_39 = - V_44 ;
F_3 ( V_2 , 0x3b , V_36 ) ;
F_8 ( 15 ) ;
return V_39 ;
}
static enum V_53 F_13 ( struct V_1 * V_2 )
{
T_1 V_36 ;
enum V_53 V_54 = 0 ;
V_36 = F_1 ( V_2 , 0x14 ) ;
if ( V_36 & 0x02 )
V_54 |= V_55 ;
if ( V_36 & 0x01 )
V_54 |= V_56 ;
V_36 = F_1 ( V_2 , 0x36 ) ;
if ( V_36 & 0x01 )
V_54 |= V_57 ;
if ( V_36 & 0x20 )
V_54 |= V_58 ;
if ( V_54 == ( V_55 | V_56 | V_57 | V_58 ) )
V_54 |= V_59 ;
return V_54 ;
}
static int F_14 ( struct V_22 * V_23 ,
enum V_53 * V_54 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_1 V_36 ;
F_4 ( L_2 , V_20 ) ;
if ( V_54 == NULL )
return - V_41 ;
* V_54 = F_13 ( V_2 ) ;
if ( * V_54 == ( V_55 | V_56 | V_57 ) ) {
V_36 = F_1 ( V_2 , V_60 ) ;
if ( ( V_36 & 0x07 ) == 0x03 ) {
if ( V_36 & 0x08 )
F_3 ( V_2 , V_61 , 0x13 ) ;
else
F_3 ( V_2 , V_61 , 0x1b ) ;
F_15 ( 200 ) ;
* V_54 = F_13 ( V_2 ) ;
}
}
if ( ( * V_54 & V_59 ) && ! V_2 -> V_62 ) {
T_2 V_63 = F_16 ( V_2 ) ;
switch ( F_1 ( V_2 , V_60 ) & 0x07 ) {
case 0 : V_63 = ( V_63 * 2 * 1 ) / 2 ; break;
case 1 : V_63 = ( V_63 * 2 * 2 ) / 3 ; break;
case 2 : V_63 = ( V_63 * 2 * 3 ) / 4 ; break;
case 3 : V_63 = ( V_63 * 2 * 5 ) / 6 ; break;
case 4 : V_63 = ( V_63 * 2 * 6 ) / 7 ; break;
case 5 : V_63 = ( V_63 * 2 * 7 ) / 8 ; break;
}
if ( V_63 == 0 ) {
F_17 ( V_64 L_4 ) ;
V_63 = 1 ;
}
V_63 = V_2 -> V_65 / V_63 ;
if ( V_63 < 2 )
V_36 = 0x00 ;
else if ( V_63 < 5 )
V_36 = 0x01 ;
else if ( V_63 < 9 )
V_36 = 0x02 ;
else if ( V_63 < 13 )
V_36 = 0x03 ;
else if ( V_63 < 17 )
V_36 = 0x04 ;
else if ( V_63 < 25 )
V_36 = 0x05 ;
else if ( V_63 < 33 )
V_36 = 0x06 ;
else
V_36 = 0x07 ;
F_4 ( L_5 , V_63 , V_36 ) ;
F_3 ( V_2 , V_66 , 0x18 ) ;
F_3 ( V_2 , V_66 , 0x10 ) ;
F_3 ( V_2 , V_66 , V_36 ) ;
V_36 = F_1 ( V_2 , V_67 ) ;
F_3 ( V_2 , V_67 , V_36 | ( 1 << 6 ) ) ;
V_36 = F_1 ( V_2 , V_68 ) & 0x7f ;
F_3 ( V_2 , V_68 , V_36 ) ;
if ( F_16 ( V_2 ) >= 20000000 ) {
F_3 ( V_2 , V_69 , 0x8a ) ;
F_3 ( V_2 , V_70 , 0x6a ) ;
} else {
F_3 ( V_2 , V_69 , 0x58 ) ;
F_3 ( V_2 , V_70 , 0x27 ) ;
}
V_2 -> V_62 = 1 ;
}
F_4 ( L_3 , V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 , T_2 * V_71 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_3 ( V_2 , 0x46 , 0x1d ) ;
F_15 ( 25 ) ;
* V_71 = ( F_1 ( V_2 , 0x48 ) << 8 ) | F_1 ( V_2 , 0x47 ) ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 , T_3 * V_72 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_1 V_36 = F_1 ( V_2 , 0x15 ) ;
* V_72 = ( T_3 ) ( ( V_36 << 8 ) | V_36 ) ;
return 0 ;
}
static int F_20 ( struct V_22 * V_23 , T_2 * V_73 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_3 ( V_2 , 0x46 , 0x1f ) ;
F_15 ( 25 ) ;
* V_73 = ( F_1 ( V_2 , 0x48 ) << 8 ) | F_1 ( V_2 , 0x47 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_4 ( L_6 , V_20 ) ;
F_3 ( V_2 , 0x01 , 0x08 ) ;
F_3 ( V_2 , 0x01 , 0x00 ) ;
F_22 ( 10 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
T_1 V_76 ;
T_4 V_36 ;
F_4 ( L_2 , V_20 ) ;
V_36 = ( ( T_4 ) V_75 -> V_77 / 1000ULL ) * ( 1ULL << 24 ) ;
if ( V_75 -> V_77 < 29000000 )
V_36 *= 2 ;
F_24 ( V_36 , ( V_2 -> V_65 / 1000 ) ) ;
F_4 ( L_7 , ( unsigned long long ) V_36 ) ;
V_76 = F_1 ( V_2 , V_78 ) ;
F_3 ( V_2 , V_78 , V_76 & 0x7f ) ;
F_3 ( V_2 , V_79 , V_36 >> 16 ) ;
F_3 ( V_2 , V_80 , V_36 >> 8 ) ;
F_3 ( V_2 , V_81 , V_36 & 0xff ) ;
F_3 ( V_2 , V_78 , V_76 | 0x80 ) ;
F_4 ( L_3 , V_20 ) ;
}
static T_2 F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_77 ;
}
static void F_25 ( struct V_1 * V_2 , int V_82 )
{
int V_36 ;
T_1 V_76 ;
F_4 ( L_2 , V_20 ) ;
V_36 = - ( int ) ( ( V_82 * ( 1 << 24 ) ) / ( V_2 -> V_65 / 1000000 ) ) ;
F_4 ( L_8 , V_82 , V_36 ) ;
V_76 = F_1 ( V_2 , V_78 ) ;
F_3 ( V_2 , V_78 , V_76 & 0xbf ) ;
F_3 ( V_2 , V_83 , V_36 >> 16 ) ;
F_3 ( V_2 , V_84 , V_36 >> 8 ) ;
F_3 ( V_2 , V_85 , V_36 & 0xff ) ;
F_3 ( V_2 , V_78 , V_76 | 0x40 ) ;
F_4 ( L_3 , V_20 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_36 ;
F_3 ( V_2 , 0x06 , F_1 ( V_2 , 0x06 ) | 0x08 ) ;
V_36 = F_1 ( V_2 , 0x0e ) << 16 ;
V_36 |= F_1 ( V_2 , 0x0f ) << 8 ;
V_36 |= F_1 ( V_2 , 0x10 ) ;
F_3 ( V_2 , 0x06 , F_1 ( V_2 , 0x06 ) & 0xf7 ) ;
if ( V_36 & 0x800000 )
V_36 |= 0xff000000 ;
V_36 = ( ( ( - V_36 ) * ( V_2 -> V_65 / 1000000 ) ) / ( 1 << 24 ) ) ;
return V_36 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
T_1 V_86 = 0 ;
T_1 V_87 , V_88 ;
F_4 ( L_2 , V_20 ) ;
if ( V_75 -> V_86 == V_89 )
V_86 = V_2 -> V_9 -> V_90 ? 0x08 : 0 ;
else if ( V_75 -> V_86 == V_91 )
V_86 = V_2 -> V_9 -> V_90 ? 0 : 0x08 ;
if ( ( V_75 -> V_92 == V_93 ) || ( V_75 -> V_86 == V_94 ) ) {
V_87 = 0x3f ;
V_88 = 0 ;
} else {
switch ( V_75 -> V_92 ) {
case V_95 :
V_87 = 0x01 ;
V_88 = 0x10 ;
break;
case V_96 :
V_87 = 0x02 ;
V_88 = 0x11 ;
break;
case V_97 :
V_87 = 0x04 ;
V_88 = 0x12 ;
break;
case V_98 :
V_87 = 0x08 ;
V_88 = 0x13 ;
break;
case V_99 :
V_87 = 0x10 ;
V_88 = 0x14 ;
break;
case V_100 :
V_87 = 0x20 ;
V_88 = 0x15 ;
break;
default:
return;
}
}
V_88 |= V_86 ;
F_4 ( L_9 , V_87 , V_88 ) ;
F_3 ( V_2 , V_101 , V_87 ) ;
F_3 ( V_2 , V_61 , V_88 ) ;
F_4 ( L_3 , V_20 ) ;
}
static enum V_102 F_28 ( struct V_1 * V_2 )
{
switch( F_1 ( V_2 , 0x32 ) & 0x07 ) {
case 0 :
return V_95 ;
case 1 :
return V_96 ;
case 2 :
return V_97 ;
case 3 :
return V_98 ;
case 4 :
return V_99 ;
case 5 :
return V_100 ;
}
return V_103 ;
}
static enum V_104
F_29 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 , 0x32 ) & 0x08 )
return V_91 ;
return V_89 ;
}
static int F_30 ( struct V_22 * V_23 )
{
struct V_74 * V_75 = & V_23 -> V_105 ;
struct V_1 * V_2 = V_23 -> V_26 ;
int V_106 ;
struct V_107 V_108 ;
F_4 ( L_2 , V_20 ) ;
F_31 ( V_23 , & V_108 ) ;
V_106 = V_75 -> V_109 - V_2 -> V_110 ;
if ( ( V_106 > - V_108 . V_111 ) &&
( V_106 < V_108 . V_111 ) &&
( V_106 != 0 ) &&
( V_2 -> V_92 == V_75 -> V_92 ) &&
( V_2 -> V_77 == V_75 -> V_77 ) ) {
if ( V_23 -> V_112 . V_113 . V_114 ) {
V_23 -> V_112 . V_113 . V_114 ( V_23 ) ;
if ( V_23 -> V_112 . V_115 ) V_23 -> V_112 . V_115 ( V_23 , 0 ) ;
}
if ( V_23 -> V_112 . V_113 . V_116 ) {
T_2 V_63 ;
V_23 -> V_112 . V_113 . V_116 ( V_23 , & V_63 ) ;
if ( V_23 -> V_112 . V_115 ) V_23 -> V_112 . V_115 ( V_23 , 0 ) ;
F_25 ( V_2 , V_75 -> V_109 - V_63 ) ;
} else {
F_25 ( V_2 , 0 ) ;
}
F_4 ( L_10 ) ;
return 0 ;
}
F_4 ( L_11 ) ;
F_21 ( V_2 ) ;
if ( V_75 -> V_77 > 33000000 )
V_2 -> V_65 = 80000000 ;
else if ( V_75 -> V_77 > 28500000 )
V_2 -> V_65 = 59000000 ;
else if ( V_75 -> V_77 > 25000000 )
V_2 -> V_65 = 86000000 ;
else if ( V_75 -> V_77 > 1900000 )
V_2 -> V_65 = 88000000 ;
else
V_2 -> V_65 = 44000000 ;
F_4 ( L_12 , V_2 -> V_65 / 1000000 - 8 , ( V_2 -> V_65 + ( V_117 * 32 ) - 1 ) / ( V_117 * 32 ) ) ;
F_3 ( V_2 , V_118 , V_2 -> V_65 / 1000000 - 8 ) ;
F_3 ( V_2 , V_119 , 0x40 ) ;
F_3 ( V_2 , V_120 , ( V_2 -> V_65 + ( V_117 * 32 ) - 1 ) / ( V_117 * 32 ) ) ;
if ( V_75 -> V_77 > 29000000 )
F_3 ( V_2 , V_68 , 0xae | 0x10 ) ;
else
F_3 ( V_2 , V_68 , 0xac | 0x10 ) ;
F_3 ( V_2 , V_121 , 0x00 ) ;
F_3 ( V_2 , V_122 , 0x00 ) ;
F_3 ( V_2 , V_123 , 0xb0 ) ;
F_3 ( V_2 , V_78 , 0xF0 ) ;
F_3 ( V_2 , V_124 , 0x2a ) ;
F_3 ( V_2 , V_125 , 0x79 ) ;
if ( V_75 -> V_77 > 20000000 )
F_3 ( V_2 , V_69 , 0x79 ) ;
else
F_3 ( V_2 , V_69 , 0x58 ) ;
F_3 ( V_2 , V_70 , 0x6b ) ;
if ( V_75 -> V_77 >= 8000000 )
F_3 ( V_2 , V_126 , ( 0 << 6 ) | 0x10 ) ;
else if ( V_75 -> V_77 >= 4000000 )
F_3 ( V_2 , V_126 , ( 1 << 6 ) | 0x10 ) ;
else
F_3 ( V_2 , V_126 , ( 3 << 6 ) | 0x10 ) ;
F_3 ( V_2 , V_127 , 0x00 ) ;
F_3 ( V_2 , V_128 , 0x33 ) ;
F_3 ( V_2 , V_129 , V_2 -> V_9 -> V_130 ) ;
F_3 ( V_2 , V_67 , 0x3d ) ;
F_3 ( V_2 , V_131 , 0x03 ) ;
F_3 ( V_2 , V_132 , 0x6e ) ;
F_3 ( V_2 , V_133 , 0x00 ) ;
F_3 ( V_2 , V_134 , 0x61 ) ;
if ( V_23 -> V_112 . V_113 . V_114 ) {
V_23 -> V_112 . V_113 . V_114 ( V_23 ) ;
if ( V_23 -> V_112 . V_115 )
V_23 -> V_112 . V_115 ( V_23 , 0 ) ;
F_25 ( V_2 , 0 ) ;
}
F_23 ( V_2 , V_75 ) ;
F_27 ( V_2 , V_75 ) ;
F_3 ( V_2 , V_68 , F_1 ( V_2 , V_68 ) | 1 ) ;
V_2 -> V_92 = V_75 -> V_92 ;
V_2 -> V_77 = V_75 -> V_77 ;
V_2 -> V_62 = 0 ;
V_2 -> V_110 = V_75 -> V_109 ;
F_4 ( L_3 , V_20 ) ;
return 0 ;
}
static int F_32 ( struct V_22 * V_23 )
{
struct V_74 * V_75 = & V_23 -> V_105 ;
struct V_1 * V_2 = V_23 -> V_26 ;
V_75 -> V_109 = V_2 -> V_110 + F_26 ( V_2 ) ;
V_75 -> V_86 = F_29 ( V_2 ) ;
V_75 -> V_77 = F_16 ( V_2 ) ;
V_75 -> V_92 = F_28 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_22 * V_23 ,
struct V_107 * V_108 )
{
struct V_74 * V_75 = & V_23 -> V_105 ;
if ( V_75 -> V_77 > 20000000 ) {
V_108 -> V_135 = 50 ;
V_108 -> V_136 = 2000 ;
V_108 -> V_111 = 8000 ;
} else if ( V_75 -> V_77 > 12000000 ) {
V_108 -> V_135 = 100 ;
V_108 -> V_136 = 1500 ;
V_108 -> V_111 = 9000 ;
} else if ( V_75 -> V_77 > 8000000 ) {
V_108 -> V_135 = 100 ;
V_108 -> V_136 = 1000 ;
V_108 -> V_111 = 8000 ;
} else if ( V_75 -> V_77 > 4000000 ) {
V_108 -> V_135 = 100 ;
V_108 -> V_136 = 500 ;
V_108 -> V_111 = 7000 ;
} else if ( V_75 -> V_77 > 2000000 ) {
V_108 -> V_135 = 200 ;
V_108 -> V_136 = ( V_75 -> V_77 / 8000 ) ;
V_108 -> V_111 = 14 * V_108 -> V_136 ;
} else {
V_108 -> V_135 = 200 ;
V_108 -> V_136 = ( V_75 -> V_77 / 8000 ) ;
V_108 -> V_111 = 18 * V_108 -> V_136 ;
}
return 0 ;
}
static int F_33 ( struct V_22 * V_23 , int V_137 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
if ( V_137 )
return F_3 ( V_2 , 0x02 , V_2 -> V_138 | 1 ) ;
else
return F_3 ( V_2 , 0x02 , V_2 -> V_138 & 0xfe ) ;
}
static int F_34 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
V_2 -> V_138 = V_2 -> V_9 -> V_139 << 4 ;
F_3 ( V_2 , 0x02 , V_2 -> V_138 ) ;
F_8 ( 10 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
V_2 -> V_138 = 0x12 ;
return F_3 ( V_2 , 0x02 , V_2 -> V_138 ) ;
}
static void F_36 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_37 ( & V_2 -> V_140 ) ;
F_38 ( V_2 ) ;
}
static T_2 F_39 ( struct V_141 * V_142 )
{
return V_143 ;
}
static int F_40 ( struct V_141 * V_144 , struct V_6 V_7 [] , int V_145 )
{
struct V_1 * V_2 = F_41 ( V_144 ) ;
struct V_6 V_146 [ 3 ] ;
T_1 V_147 [ 2 ] = { V_121 , V_2 -> V_138 | 1 } ;
if ( 1 + V_145 > F_42 ( V_146 ) ) {
F_17 ( V_148
L_13 ,
V_149 , V_145 ) ;
return - V_150 ;
}
memset ( V_146 , 0 , sizeof( struct V_6 ) * ( 1 + V_145 ) ) ;
V_146 [ 0 ] . V_8 = V_2 -> V_9 -> V_10 ;
V_146 [ 0 ] . V_12 = V_147 ;
V_146 [ 0 ] . V_13 = 2 ;
memcpy ( & V_146 [ 1 ] , V_7 , sizeof( struct V_6 ) * V_145 ) ;
return F_2 ( V_2 -> V_17 , V_146 , 1 + V_145 ) == 1 + V_145 ? V_145 : - V_48 ;
}
struct V_141 * F_43 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
return & V_2 -> V_140 ;
}
struct V_22 * F_44 ( const struct V_151 * V_9 ,
struct V_141 * V_17 )
{
struct V_1 * V_2 = F_45 ( sizeof( struct V_1 ) , V_152 ) ;
T_1 V_37 ;
if ( V_2 == NULL )
goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_62 = 0 ;
V_2 -> V_65 = 88000000 ;
V_2 -> V_110 = 0 ;
V_2 -> V_92 = V_103 ;
V_2 -> V_77 = 0 ;
V_37 = F_1 ( V_2 , V_153 ) ;
if ( V_37 != 0x03 )
goto error;
memset ( V_2 -> V_15 , 0xff , sizeof( V_2 -> V_15 ) ) ;
for ( V_37 = 0 ; V_37 < 0x50 ; V_37 ++ )
V_2 -> V_15 [ V_37 ] = F_1 ( V_2 , V_37 ) ;
memcpy ( & V_2 -> V_154 . V_112 , & V_155 , sizeof( struct V_156 ) ) ;
V_2 -> V_154 . V_26 = V_2 ;
F_46 ( V_2 -> V_140 . V_157 , L_14 ,
sizeof( V_2 -> V_140 . V_157 ) ) ;
V_2 -> V_140 . V_158 = & V_159 ;
V_2 -> V_140 . V_160 = NULL ;
F_47 ( & V_2 -> V_140 , V_2 ) ;
if ( F_48 ( & V_2 -> V_140 ) < 0 ) {
F_17 ( V_64 L_15 ) ;
goto error;
}
return & V_2 -> V_154 ;
error:
F_38 ( V_2 ) ;
return NULL ;
}
