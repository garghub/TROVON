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
static int F_5 ( struct V_22 * V_23 , T_2 V_24 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_4 ( L_2 , V_20 ) ;
switch( V_24 ) {
case V_26 :
F_3 ( V_2 , 0x3c ,
( F_1 ( V_2 , 0x3c ) & 0xfe ) | 0x02 ) ;
break;
case V_27 :
F_3 ( V_2 , 0x3c , F_1 ( V_2 , 0x3c ) | 0x03 ) ;
break;
case V_28 :
F_3 ( V_2 , 0x3c , F_1 ( V_2 , 0x3c ) & 0xfd ) ;
break;
}
F_4 ( L_3 , V_20 ) ;
return 0 ;
}
static int F_6 ( struct V_22 * V_23 , T_3 V_29 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_4 ( L_2 , V_20 ) ;
switch( V_29 ) {
case V_30 :
F_3 ( V_2 , 0x3b ,
( F_1 ( V_2 , 0x3b ) & 0x74 ) | 0x08 ) ;
break;
case V_31 :
F_3 ( V_2 , 0x3b ,
( F_1 ( V_2 , 0x3b ) & 0x74 ) | 0x01 ) ;
break;
}
F_4 ( L_3 , V_20 ) ;
return 0 ;
}
static int F_7 ( struct V_22 * V_23 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
T_1 V_34 ;
int V_35 ;
unsigned long V_36 ;
int V_37 = 0 ;
F_4 ( L_2 , V_20 ) ;
if ( V_33 -> V_38 > 8 )
return - V_39 ;
V_34 = F_1 ( V_2 , 0x3b ) ;
F_3 ( V_2 , 0x3b , 0x02 ) ;
F_8 ( 15 ) ;
for( V_35 = 0 ; V_35 < V_33 -> V_38 ; V_35 ++ ) {
F_3 ( V_2 , 0x3d + V_35 , V_33 -> V_7 [ V_35 ] ) ;
}
F_3 ( V_2 , 0x3b , F_1 ( V_2 , 0x3b ) |
( ( V_33 -> V_38 - 1 ) << 4 ) | 0x08 ) ;
V_36 = V_40 + ( ( 100 * V_41 ) / 1000 ) ;
while( F_9 ( V_40 , V_36 ) ) {
if ( ! ( F_1 ( V_2 , 0x3b ) & 0x08 ) )
break;
F_8 ( 5 ) ;
}
if ( F_10 ( V_40 , V_36 ) )
V_37 = - V_42 ;
F_3 ( V_2 , 0x3b , V_34 ) ;
F_8 ( 15 ) ;
F_4 ( L_3 , V_20 ) ;
return V_37 ;
}
static int F_11 ( struct V_22 * V_23 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
T_1 V_34 ;
int V_35 ;
int V_45 ;
unsigned long V_36 ;
int V_37 = 0 ;
V_34 = F_1 ( V_2 , 0x3b ) ;
F_3 ( V_2 , 0x3b , 0x82 ) ;
F_8 ( 15 ) ;
V_36 = V_40 + ( ( V_44 -> V_36 * V_41 ) / 1000 ) ;
while( F_9 ( V_40 , V_36 ) ) {
if ( ! ( F_1 ( V_2 , 0x3b ) & 0x80 ) )
break;
F_8 ( 5 ) ;
}
if ( F_10 ( V_40 , V_36 ) ) {
V_37 = - V_42 ;
goto exit;
}
if ( F_1 ( V_2 , 0x49 ) ) {
V_37 = - V_46 ;
goto exit;
}
V_45 = ( F_1 ( V_2 , 0x3b ) & 0x70 ) >> 4 ;
if ( V_45 > sizeof( V_44 -> V_7 ) ) {
V_37 = - V_47 ;
goto exit;
}
V_44 -> V_38 = V_45 ;
for( V_35 = 0 ; V_35 < V_45 ; V_35 ++ ) {
V_44 -> V_7 [ V_35 ] = F_1 ( V_2 , 0x3d + V_35 ) ;
}
exit:
F_3 ( V_2 , 0x3b , V_34 ) ;
F_8 ( 15 ) ;
return V_37 ;
}
static int F_12 ( struct V_22 * V_23 , T_4 V_48 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
T_1 V_34 ;
int V_37 = 0 ;
unsigned long V_36 ;
V_34 = F_1 ( V_2 , 0x3b ) ;
F_3 ( V_2 , 0x3b , ( F_1 ( V_2 , 0x3b ) & 0x70 ) | 0x01 ) ;
if ( V_48 == V_49 ) {
F_3 ( V_2 , 0x3b , F_1 ( V_2 , 0x3b ) | 0x04 ) ;
}
F_8 ( 15 ) ;
F_3 ( V_2 , 0x3b , F_1 ( V_2 , 0x3b ) | 0x08 ) ;
V_36 = V_40 + ( ( 100 * V_41 ) / 1000 ) ;
while( F_9 ( V_40 , V_36 ) ) {
if ( ! ( F_1 ( V_2 , 0x3b ) & 0x08 ) )
break;
F_8 ( 5 ) ;
}
if ( F_10 ( V_40 , V_36 ) )
V_37 = - V_42 ;
F_3 ( V_2 , 0x3b , V_34 ) ;
F_8 ( 15 ) ;
return V_37 ;
}
static T_5 F_13 ( struct V_1 * V_2 )
{
T_1 V_34 ;
T_5 V_50 = 0 ;
V_34 = F_1 ( V_2 , 0x14 ) ;
if ( V_34 & 0x02 )
V_50 |= V_51 ;
if ( V_34 & 0x01 )
V_50 |= V_52 ;
V_34 = F_1 ( V_2 , 0x36 ) ;
if ( V_34 & 0x01 )
V_50 |= V_53 ;
if ( V_34 & 0x20 )
V_50 |= V_54 ;
if ( V_50 == ( V_51 | V_52 | V_53 | V_54 ) )
V_50 |= V_55 ;
return V_50 ;
}
static int F_14 ( struct V_22 * V_23 , T_5 * V_50 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
T_1 V_34 ;
F_4 ( L_2 , V_20 ) ;
if ( V_50 == NULL )
return - V_39 ;
* V_50 = F_13 ( V_2 ) ;
if ( * V_50 == ( V_51 | V_52 | V_53 ) ) {
V_34 = F_1 ( V_2 , V_56 ) ;
if ( ( V_34 & 0x07 ) == 0x03 ) {
if ( V_34 & 0x08 )
F_3 ( V_2 , V_57 , 0x13 ) ;
else
F_3 ( V_2 , V_57 , 0x1b ) ;
F_15 ( 200 ) ;
* V_50 = F_13 ( V_2 ) ;
}
}
if ( ( * V_50 & V_55 ) && ! V_2 -> V_58 ) {
T_6 V_59 = F_16 ( V_2 ) ;
switch ( F_1 ( V_2 , V_56 ) & 0x07 ) {
case 0 : V_59 = ( V_59 * 2 * 1 ) / 2 ; break;
case 1 : V_59 = ( V_59 * 2 * 2 ) / 3 ; break;
case 2 : V_59 = ( V_59 * 2 * 3 ) / 4 ; break;
case 3 : V_59 = ( V_59 * 2 * 5 ) / 6 ; break;
case 4 : V_59 = ( V_59 * 2 * 6 ) / 7 ; break;
case 5 : V_59 = ( V_59 * 2 * 7 ) / 8 ; break;
}
if ( V_59 == 0 ) {
F_17 ( V_60 L_4 ) ;
V_59 = 1 ;
}
V_59 = V_2 -> V_61 / V_59 ;
if ( V_59 < 2 )
V_34 = 0x00 ;
else if ( V_59 < 5 )
V_34 = 0x01 ;
else if ( V_59 < 9 )
V_34 = 0x02 ;
else if ( V_59 < 13 )
V_34 = 0x03 ;
else if ( V_59 < 17 )
V_34 = 0x04 ;
else if ( V_59 < 25 )
V_34 = 0x05 ;
else if ( V_59 < 33 )
V_34 = 0x06 ;
else
V_34 = 0x07 ;
F_4 ( L_5 , V_59 , V_34 ) ;
F_3 ( V_2 , V_62 , 0x18 ) ;
F_3 ( V_2 , V_62 , 0x10 ) ;
F_3 ( V_2 , V_62 , V_34 ) ;
V_34 = F_1 ( V_2 , V_63 ) ;
F_3 ( V_2 , V_63 , V_34 | ( 1 << 6 ) ) ;
V_34 = F_1 ( V_2 , V_64 ) & 0x7f ;
F_3 ( V_2 , V_64 , V_34 ) ;
if ( F_16 ( V_2 ) >= 20000000 ) {
F_3 ( V_2 , V_65 , 0x8a ) ;
F_3 ( V_2 , V_66 , 0x6a ) ;
} else {
F_3 ( V_2 , V_65 , 0x58 ) ;
F_3 ( V_2 , V_66 , 0x27 ) ;
}
V_2 -> V_58 = 1 ;
}
F_4 ( L_3 , V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 , T_6 * V_67 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_3 ( V_2 , 0x46 , 0x1d ) ;
F_15 ( 25 ) ;
* V_67 = ( F_1 ( V_2 , 0x48 ) << 8 ) | F_1 ( V_2 , 0x47 ) ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 , T_7 * V_68 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
T_1 V_34 = F_1 ( V_2 , 0x15 ) ;
* V_68 = ( T_7 ) ( ( V_34 << 8 ) | V_34 ) ;
return 0 ;
}
static int F_20 ( struct V_22 * V_23 , T_6 * V_69 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_3 ( V_2 , 0x46 , 0x1f ) ;
F_15 ( 25 ) ;
* V_69 = ( F_1 ( V_2 , 0x48 ) << 8 ) | F_1 ( V_2 , 0x47 ) ;
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
struct V_70 * V_71 )
{
T_1 V_72 ;
T_8 V_34 ;
F_4 ( L_2 , V_20 ) ;
V_34 = ( ( T_8 ) V_71 -> V_73 . V_74 . V_75 / 1000ULL ) * ( 1ULL << 24 ) ;
if ( V_71 -> V_73 . V_74 . V_75 < 29000000 )
V_34 *= 2 ;
F_24 ( V_34 , ( V_2 -> V_61 / 1000 ) ) ;
F_4 ( L_7 , ( unsigned long long ) V_34 ) ;
V_72 = F_1 ( V_2 , V_76 ) ;
F_3 ( V_2 , V_76 , V_72 & 0x7f ) ;
F_3 ( V_2 , V_77 , V_34 >> 16 ) ;
F_3 ( V_2 , V_78 , V_34 >> 8 ) ;
F_3 ( V_2 , V_79 , V_34 & 0xff ) ;
F_3 ( V_2 , V_76 , V_72 | 0x80 ) ;
F_4 ( L_3 , V_20 ) ;
}
static T_6 F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_75 ;
}
static void F_25 ( struct V_1 * V_2 , int V_80 )
{
int V_34 ;
T_1 V_72 ;
F_4 ( L_2 , V_20 ) ;
V_34 = - ( int ) ( ( V_80 * ( 1 << 24 ) ) / ( V_2 -> V_61 / 1000000 ) ) ;
F_4 ( L_8 , V_80 , V_34 ) ;
V_72 = F_1 ( V_2 , V_76 ) ;
F_3 ( V_2 , V_76 , V_72 & 0xbf ) ;
F_3 ( V_2 , V_81 , V_34 >> 16 ) ;
F_3 ( V_2 , V_82 , V_34 >> 8 ) ;
F_3 ( V_2 , V_83 , V_34 & 0xff ) ;
F_3 ( V_2 , V_76 , V_72 | 0x40 ) ;
F_4 ( L_3 , V_20 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_34 ;
F_3 ( V_2 , 0x06 , F_1 ( V_2 , 0x06 ) | 0x08 ) ;
V_34 = F_1 ( V_2 , 0x0e ) << 16 ;
V_34 |= F_1 ( V_2 , 0x0f ) << 8 ;
V_34 |= F_1 ( V_2 , 0x10 ) ;
F_3 ( V_2 , 0x06 , F_1 ( V_2 , 0x06 ) & 0xf7 ) ;
if ( V_34 & 0x800000 )
V_34 |= 0xff000000 ;
V_34 = ( ( ( - V_34 ) * ( V_2 -> V_61 / 1000000 ) ) / ( 1 << 24 ) ) ;
return V_34 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
T_1 V_84 = 0 ;
T_1 V_85 , V_86 ;
F_4 ( L_2 , V_20 ) ;
if ( V_71 -> V_84 == V_87 )
V_84 = V_2 -> V_9 -> V_88 ? 0x08 : 0 ;
else if ( V_71 -> V_84 == V_89 )
V_84 = V_2 -> V_9 -> V_88 ? 0 : 0x08 ;
if ( ( V_71 -> V_73 . V_74 . V_90 == V_91 ) || ( V_71 -> V_84 == V_92 ) ) {
V_85 = 0x3f ;
V_86 = 0 ;
} else {
switch( V_71 -> V_73 . V_74 . V_90 ) {
case V_93 :
V_85 = 0x01 ; V_86 = 0x10 ;
break;
case V_94 :
V_85 = 0x02 ; V_86 = 0x11 ;
break;
case V_95 :
V_85 = 0x04 ; V_86 = 0x12 ;
break;
case V_96 :
V_85 = 0x08 ; V_86 = 0x13 ;
break;
case V_97 :
V_85 = 0x10 ; V_86 = 0x14 ;
break;
case V_98 :
V_85 = 0x20 ; V_86 = 0x15 ;
break;
default:
return;
}
}
V_86 |= V_84 ;
F_4 ( L_9 , V_85 , V_86 ) ;
F_3 ( V_2 , V_99 , V_85 ) ;
F_3 ( V_2 , V_57 , V_86 ) ;
F_4 ( L_3 , V_20 ) ;
}
static T_9 F_28 ( struct V_1 * V_2 )
{
switch( F_1 ( V_2 , 0x32 ) & 0x07 ) {
case 0 :
return V_93 ;
case 1 :
return V_94 ;
case 2 :
return V_95 ;
case 3 :
return V_96 ;
case 4 :
return V_97 ;
case 5 :
return V_98 ;
}
return V_100 ;
}
static T_10 F_29 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 , 0x32 ) & 0x08 )
return V_89 ;
return V_87 ;
}
static int F_30 ( struct V_22 * V_23 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
int V_101 ;
struct V_102 V_103 ;
T_11 V_104 ;
F_4 ( L_2 , V_20 ) ;
memcpy ( & V_103 . V_105 , V_71 , sizeof( struct V_70 ) ) ;
F_31 ( V_23 , & V_103 ) ;
V_101 = V_71 -> V_106 - V_2 -> V_107 ;
if ( ( V_101 > - V_103 . V_108 ) &&
( V_101 < V_103 . V_108 ) &&
( V_101 != 0 ) &&
( V_2 -> V_90 == V_71 -> V_73 . V_74 . V_90 ) &&
( V_2 -> V_75 == V_71 -> V_73 . V_74 . V_75 ) ) {
if ( V_23 -> V_109 . V_110 . V_111 ) {
V_23 -> V_109 . V_110 . V_111 ( V_23 , V_71 ) ;
if ( V_23 -> V_109 . V_112 ) V_23 -> V_109 . V_112 ( V_23 , 0 ) ;
}
if ( V_23 -> V_109 . V_110 . V_113 ) {
T_6 V_59 ;
V_23 -> V_109 . V_110 . V_113 ( V_23 , & V_59 ) ;
if ( V_23 -> V_109 . V_112 ) V_23 -> V_109 . V_112 ( V_23 , 0 ) ;
F_25 ( V_2 , V_71 -> V_106 - V_59 ) ;
} else {
F_25 ( V_2 , 0 ) ;
}
F_4 ( L_10 ) ;
return 0 ;
}
F_4 ( L_11 ) ;
F_21 ( V_2 ) ;
if ( V_71 -> V_73 . V_74 . V_75 > 33000000 )
V_2 -> V_61 = 80000000 ;
else if ( V_71 -> V_73 . V_74 . V_75 > 28500000 )
V_2 -> V_61 = 59000000 ;
else if ( V_71 -> V_73 . V_74 . V_75 > 25000000 )
V_2 -> V_61 = 86000000 ;
else if ( V_71 -> V_73 . V_74 . V_75 > 1900000 )
V_2 -> V_61 = 88000000 ;
else
V_2 -> V_61 = 44000000 ;
switch ( V_2 -> V_61 ) {
default:
case 88000000 :
V_104 = 80 ;
break;
case 86000000 :
V_104 = 78 ;
break;
case 80000000 :
V_104 = 72 ;
break;
case 59000000 :
V_104 = 51 ;
break;
case 44000000 :
V_104 = 36 ;
break;
}
F_4 ( L_12 , V_2 -> V_61 / 1000000 - 8 , ( V_2 -> V_61 + ( V_114 * 32 ) - 1 ) / ( V_114 * 32 ) ) ;
F_3 ( V_2 , V_115 , V_2 -> V_61 / 1000000 - 8 ) ;
F_3 ( V_2 , V_116 , 0x40 ) ;
F_3 ( V_2 , V_117 , ( V_2 -> V_61 + ( V_114 * 32 ) - 1 ) / ( V_114 * 32 ) ) ;
if ( V_71 -> V_73 . V_74 . V_75 > 29000000 )
F_3 ( V_2 , V_64 , 0xae | 0x10 ) ;
else
F_3 ( V_2 , V_64 , 0xac | 0x10 ) ;
F_3 ( V_2 , V_118 , 0x00 ) ;
F_3 ( V_2 , V_119 , 0x00 ) ;
F_3 ( V_2 , V_120 , 0xb0 ) ;
F_3 ( V_2 , V_76 , 0xF0 ) ;
F_3 ( V_2 , V_121 , 0x2a ) ;
F_3 ( V_2 , V_122 , 0x79 ) ;
if ( V_71 -> V_73 . V_74 . V_75 > 20000000 )
F_3 ( V_2 , V_65 , 0x79 ) ;
else
F_3 ( V_2 , V_65 , 0x58 ) ;
F_3 ( V_2 , V_66 , 0x6b ) ;
if ( V_71 -> V_73 . V_74 . V_75 >= 8000000 )
F_3 ( V_2 , V_123 , ( 0 << 6 ) | 0x10 ) ;
else if ( V_71 -> V_73 . V_74 . V_75 >= 4000000 )
F_3 ( V_2 , V_123 , ( 1 << 6 ) | 0x10 ) ;
else
F_3 ( V_2 , V_123 , ( 3 << 6 ) | 0x10 ) ;
F_3 ( V_2 , V_124 , 0x00 ) ;
F_3 ( V_2 , V_125 , 0x33 ) ;
F_3 ( V_2 , V_126 , V_2 -> V_9 -> V_127 ) ;
F_3 ( V_2 , V_63 , 0x3d ) ;
F_3 ( V_2 , V_128 , 0x03 ) ;
F_3 ( V_2 , V_129 , 0x6e ) ;
F_3 ( V_2 , V_130 , 0x00 ) ;
F_3 ( V_2 , V_131 , 0x61 ) ;
if ( V_23 -> V_109 . V_110 . V_111 ) {
V_23 -> V_109 . V_110 . V_111 ( V_23 , V_71 ) ;
if ( V_23 -> V_109 . V_112 )
V_23 -> V_109 . V_112 ( V_23 , 0 ) ;
F_25 ( V_2 , 0 ) ;
}
F_23 ( V_2 , V_71 ) ;
F_27 ( V_2 , V_71 ) ;
F_3 ( V_2 , V_64 , F_1 ( V_2 , V_64 ) | 1 ) ;
V_2 -> V_90 = V_71 -> V_73 . V_74 . V_90 ;
V_2 -> V_75 = V_71 -> V_73 . V_74 . V_75 ;
V_2 -> V_58 = 0 ;
V_2 -> V_107 = V_71 -> V_106 ;
F_4 ( L_3 , V_20 ) ;
return 0 ;
}
static int F_32 ( struct V_22 * V_23 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
V_71 -> V_106 = V_2 -> V_107 + F_26 ( V_2 ) ;
V_71 -> V_84 = F_29 ( V_2 ) ;
V_71 -> V_73 . V_74 . V_75 = F_16 ( V_2 ) ;
V_71 -> V_73 . V_74 . V_90 = F_28 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_22 * V_23 ,
struct V_102 * V_103 )
{
if ( V_103 -> V_105 . V_73 . V_74 . V_75 > 20000000 ) {
V_103 -> V_132 = 50 ;
V_103 -> V_133 = 2000 ;
V_103 -> V_108 = 8000 ;
} else if ( V_103 -> V_105 . V_73 . V_74 . V_75 > 12000000 ) {
V_103 -> V_132 = 100 ;
V_103 -> V_133 = 1500 ;
V_103 -> V_108 = 9000 ;
} else if ( V_103 -> V_105 . V_73 . V_74 . V_75 > 8000000 ) {
V_103 -> V_132 = 100 ;
V_103 -> V_133 = 1000 ;
V_103 -> V_108 = 8000 ;
} else if ( V_103 -> V_105 . V_73 . V_74 . V_75 > 4000000 ) {
V_103 -> V_132 = 100 ;
V_103 -> V_133 = 500 ;
V_103 -> V_108 = 7000 ;
} else if ( V_103 -> V_105 . V_73 . V_74 . V_75 > 2000000 ) {
V_103 -> V_132 = 200 ;
V_103 -> V_133 = ( V_103 -> V_105 . V_73 . V_74 . V_75 / 8000 ) ;
V_103 -> V_108 = 14 * V_103 -> V_133 ;
} else {
V_103 -> V_132 = 200 ;
V_103 -> V_133 = ( V_103 -> V_105 . V_73 . V_74 . V_75 / 8000 ) ;
V_103 -> V_108 = 18 * V_103 -> V_133 ;
}
return 0 ;
}
static int F_33 ( struct V_22 * V_23 , int V_134 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
if ( V_134 )
return F_3 ( V_2 , 0x02 , V_2 -> V_135 | 1 ) ;
else
return F_3 ( V_2 , 0x02 , V_2 -> V_135 & 0xfe ) ;
}
static int F_34 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
V_2 -> V_135 = V_2 -> V_9 -> V_136 << 4 ;
F_3 ( V_2 , 0x02 , V_2 -> V_135 ) ;
F_8 ( 10 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
V_2 -> V_135 = 0x12 ;
return F_3 ( V_2 , 0x02 , V_2 -> V_135 ) ;
}
static void F_36 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_37 ( & V_2 -> V_137 ) ;
F_38 ( V_2 ) ;
}
static T_6 F_39 ( struct V_138 * V_139 )
{
return V_140 ;
}
static int F_40 ( struct V_138 * V_141 , struct V_6 V_7 [] , int V_142 )
{
struct V_1 * V_2 = F_41 ( V_141 ) ;
struct V_6 V_143 [ 1 + V_142 ] ;
T_1 V_144 [ 2 ] = { V_118 , V_2 -> V_135 | 1 } ;
memset ( V_143 , 0 , sizeof( struct V_6 ) * ( 1 + V_142 ) ) ;
V_143 [ 0 ] . V_8 = V_2 -> V_9 -> V_10 ;
V_143 [ 0 ] . V_12 = V_144 ;
V_143 [ 0 ] . V_13 = 2 ;
memcpy ( & V_143 [ 1 ] , V_7 , sizeof( struct V_6 ) * V_142 ) ;
return F_2 ( V_2 -> V_17 , V_143 , 1 + V_142 ) == 1 + V_142 ? V_142 : - V_46 ;
}
struct V_138 * F_42 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
return & V_2 -> V_137 ;
}
struct V_22 * F_43 ( const struct V_145 * V_9 ,
struct V_138 * V_17 )
{
struct V_1 * V_2 = F_44 ( sizeof( struct V_1 ) , V_146 ) ;
T_1 V_35 ;
if ( V_2 == NULL )
goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_58 = 0 ;
V_2 -> V_61 = 88000000 ;
V_2 -> V_107 = 0 ;
V_2 -> V_90 = V_100 ;
V_2 -> V_75 = 0 ;
V_35 = F_1 ( V_2 , V_147 ) ;
if ( V_35 != 0x03 )
goto error;
memset ( V_2 -> V_15 , 0xff , sizeof( V_2 -> V_15 ) ) ;
for ( V_35 = 0 ; V_35 < 0x50 ; V_35 ++ )
V_2 -> V_15 [ V_35 ] = F_1 ( V_2 , V_35 ) ;
memcpy ( & V_2 -> V_148 . V_109 , & V_149 , sizeof( struct V_150 ) ) ;
V_2 -> V_148 . V_25 = V_2 ;
F_45 ( V_2 -> V_137 . V_151 , L_13 ,
sizeof( V_2 -> V_137 . V_151 ) ) ;
V_2 -> V_137 . V_152 = & V_153 ;
V_2 -> V_137 . V_154 = NULL ;
F_46 ( & V_2 -> V_137 , V_2 ) ;
if ( F_47 ( & V_2 -> V_137 ) < 0 ) {
F_17 ( V_60 L_14 ) ;
goto error;
}
return & V_2 -> V_148 ;
error:
F_38 ( V_2 ) ;
return NULL ;
}
