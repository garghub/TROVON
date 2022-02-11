static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 [ 60 ] ;
struct V_8 V_9 = {
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_7 = V_7 ,
. V_5 = V_5 + 1
} ;
if ( V_5 > sizeof( V_7 ) - 1 )
return - V_14 ;
V_9 . V_7 [ 0 ] = V_3 ;
memcpy ( V_9 . V_7 + 1 , V_4 , V_5 ) ;
V_6 = F_2 ( V_2 -> V_15 , & V_9 , 1 ) ;
if ( V_6 != 1 )
F_3 ( L_1 ,
V_16 , V_3 , V_4 [ 0 ] , V_6 ) ;
return ( V_6 != 1 ) ? - V_17 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_18 , T_1 V_4 )
{
int V_6 ;
T_1 V_7 [] = { V_18 , V_4 } ;
struct V_8 V_9 = {
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_7 = V_7 ,
. V_5 = 2
} ;
V_6 = F_2 ( V_2 -> V_15 , & V_9 , 1 ) ;
if ( V_6 != 1 )
F_3 ( L_2 ,
V_16 , V_18 , V_4 , V_6 ) ;
return ( V_6 != 1 ) ? - V_17 : 0 ;
}
static int F_5 ( struct V_19 * V_20 , const T_1 V_7 [] , int V_5 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
if ( V_5 != 2 )
return - V_14 ;
return F_4 ( V_2 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_18 )
{
int V_6 ;
T_1 V_22 [] = { V_18 } ;
T_1 V_23 [] = { 0 } ;
struct V_8 V_9 [] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_7 = V_22 ,
. V_5 = 1
} , {
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = V_24 ,
. V_7 = V_23 ,
. V_5 = 1
}
} ;
V_6 = F_2 ( V_2 -> V_15 , V_9 , 2 ) ;
if ( V_6 != 2 )
F_3 ( L_3 ,
V_16 , V_18 , V_6 ) ;
return V_23 [ 0 ] ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_25 , T_1 V_5 )
{
int V_6 ;
struct V_8 V_9 [] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_7 = & V_3 ,
. V_5 = 1
} , {
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = V_24 ,
. V_7 = V_25 ,
. V_5 = V_5
}
} ;
V_6 = F_2 ( V_2 -> V_15 , V_9 , 2 ) ;
if ( V_6 != 2 )
F_3 ( L_4 , V_16 , V_6 ) ;
return V_6 == 2 ? 0 : - 1 ;
}
static int F_8 ( struct V_1 * V_2 , int V_26 )
{
unsigned long V_27 = V_28 ;
F_3 ( L_5 , V_16 ) ;
while ( ( F_6 ( V_2 , V_29 ) & 0x8 ) == 8 ) {
if ( V_28 - V_27 > V_26 ) {
F_3 ( L_6 , V_16 ) ;
return - V_30 ;
}
F_9 ( 10 ) ;
}
return 0 ;
}
static int F_10 ( struct V_19 * V_20 , T_2 V_31 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_2 V_32 , V_33 ;
int V_34 ;
T_1 V_35 [ 3 ] ;
F_3 ( L_7 , V_16 , V_31 ) ;
if ( ( V_31 < 1000000 ) || ( V_31 > 45000000 ) )
return - V_14 ;
V_33 = V_31 ;
V_32 = 0 ;
for ( V_34 = 0 ; V_34 < 4 ; ++ V_34 ) {
V_32 /= 100 ;
V_32 = V_32 + ( ( V_33 % 100 ) * 0x800000 ) /
V_2 -> V_36 ;
V_33 /= 100 ;
}
for ( V_34 = 0 ; V_34 < 3 ; ++ V_34 )
V_35 [ V_34 ] = ( T_1 ) ( ( V_32 >> ( V_34 * 8 ) ) & 0xff ) ;
F_1 ( V_2 , V_37 , V_35 , 0x03 ) ;
return 0 ;
}
static int F_11 ( struct V_19 * V_20 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_40 ;
T_1 V_41 ;
int V_42 ;
F_3 ( L_5 , V_16 ) ;
V_42 = V_43 ;
V_41 = 0 ;
V_42 |= F_7 ( V_2 , V_44 , & V_40 , 0x01 ) ;
V_42 |= F_7 ( V_2 , V_29 , & V_40 , 0x01 ) ;
V_42 |= F_1 ( V_2 , V_45 , V_39 -> V_9 , V_39 -> V_46 ) ;
V_41 = ( V_40 & 0x70 ) ;
V_41 |= V_39 -> V_46 ;
V_41 |= 0x80 ;
V_42 |= F_1 ( V_2 , V_29 , & V_41 , 0x01 ) ;
return V_42 ;
}
static int F_12 ( struct V_19 * V_20 ,
enum V_47 V_48 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_49 ;
F_3 ( L_5 , V_16 ) ;
if ( F_8 ( V_2 , 100 ) < 0 )
return - V_30 ;
V_49 = ( 0x80 | F_6 ( V_2 , 0xc1 ) ) ;
if ( F_4 ( V_2 , V_29 ,
V_48 == V_50 ? ( V_49 & ~ 0x10 ) : ( V_49 | 0x10 ) ) )
return - V_17 ;
if ( F_8 ( V_2 , 100 ) < 0 )
return - V_30 ;
if ( F_4 ( V_2 , V_29 , V_49 ) )
return - V_17 ;
return 0 ;
}
static int F_13 ( struct V_19 * V_20 , enum V_51 V_52 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_49 ;
F_3 ( L_5 , V_16 ) ;
V_49 = ( 0x80 | F_6 ( V_2 , V_29 ) ) ;
switch ( V_52 ) {
case V_53 :
return F_4 ( V_2 , V_29 , V_49 | 0x20 ) ;
case V_54 :
return F_4 ( V_2 , V_29 , ( V_49 & ~ 0x20 ) ) ;
default:
return - V_14 ;
}
}
static int F_14 ( struct V_19 * V_20 , enum V_55 V_56 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_49 ;
F_3 ( L_8 , V_16 ,
V_56 == V_57 ? L_9 :
V_56 == V_58 ? L_10 : L_11 ) ;
V_49 = ( 0x80 | F_6 ( V_2 , V_29 ) ) ;
switch ( V_56 ) {
case V_58 :
return F_4 ( V_2 , V_29 , V_49 | 0x40 ) ;
break;
case V_57 :
return F_4 ( V_2 , V_29 , ( V_49 & ~ 0x40 ) ) ;
break;
default:
return - V_14 ;
}
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
int V_34 ;
int V_42 = 0 ;
T_1 V_3 ;
T_1 V_49 ;
T_1 V_59 [ 2 ] ;
F_3 ( L_5 , V_16 ) ;
for ( V_34 = 0 ; ; V_34 += 2 ) {
V_3 = V_60 [ V_34 ] ;
V_49 = V_60 [ V_34 + 1 ] ;
if ( V_3 == 0xff && V_49 == 0xff )
break;
F_1 ( V_2 , V_3 , & V_49 , 1 ) ;
}
V_3 = 0x08 ;
F_1 ( V_2 , V_61 , & V_3 , 0x01 ) ;
V_59 [ 0 ] =
V_62 + ( V_63 << 1 )
+ ( V_64 << 2 ) + ( V_65 << 3 )
+ ( V_66 << 4 ) + ( V_67 << 5 )
+ ( V_67 << 6 ) + ( V_67 << 7 ) ;
V_59 [ 1 ] = 0 ;
V_42 |= F_1 ( V_2 , V_68 , V_59 , 0x02 ) ;
if ( V_42 != 0 )
F_3 ( L_12 , V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_19 * V_20 , enum V_69 * V_42 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_70 [ 2 ] ;
T_1 V_71 ;
T_1 V_34 ;
T_1 V_72 ;
T_1 signal = F_6 ( V_2 , V_73 ) ;
F_7 ( V_2 , V_74 , V_70 , 0x02 ) ;
V_71 = 0 ;
for ( V_34 = 0 ; V_34 < 7 ; ++ V_34 )
V_71 |= ( ( V_70 [ 0 ] >> V_34 ) & 0x01 ) << ( 6 - V_34 ) ;
V_72 = ( ( V_71 & 0x7f ) | ( V_70 [ 1 ] & 0x80 ) ) ;
F_3 ( L_13 , V_16 , V_72 ) ;
* V_42 = 0 ;
if ( signal > 10 )
* V_42 |= V_75 ;
if ( V_72 & 0x2 )
* V_42 |= V_76 ;
if ( V_72 & 0x20 )
* V_42 |= V_77 ;
if ( V_72 & 0x40 )
* V_42 |= V_78 ;
if ( ( V_72 & 0x7b ) == 0x7b )
* V_42 |= V_79 ;
return 0 ;
}
static int F_17 ( struct V_19 * V_20 , T_3 * V_80 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_3 signal = ( 3 * F_6 ( V_2 , 0x27 ) *
F_6 ( V_2 , 0x28 ) ) ;
F_3 ( L_14 , V_16 ,
F_6 ( V_2 , 0x27 ) ,
F_6 ( V_2 , 0x28 ) , ( int ) signal ) ;
signal <<= 4 ;
* V_80 = signal ;
return 0 ;
}
static int F_18 ( struct V_19 * V_20 , T_2 * V_81 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
F_3 ( L_5 , V_16 ) ;
if ( V_2 -> V_82 != V_83 )
return 0 ;
* V_81 = ( F_6 ( V_2 , 0x1d ) << 8 ) |
F_6 ( V_2 , 0x1e ) ;
return 0 ;
}
static int F_19 ( struct V_19 * V_20 , T_3 * V_84 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_4 V_85 = 0xffff - ( ( F_6 ( V_2 , 0x24 ) << 8 ) |
F_6 ( V_2 , 0x25 ) ) ;
V_85 = 3 * ( V_85 - 0xa100 ) ;
* V_84 = ( V_85 > 0xffff ) ? 0xffff : ( V_85 < 0 ) ? 0 : V_85 ;
F_3 ( L_5 , V_16 ) ;
return 0 ;
}
static int F_20 ( struct V_19 * V_20 , T_2 * V_86 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
F_3 ( L_5 , V_16 ) ;
if ( V_2 -> V_82 != V_87 )
* V_86 = 0 ;
else
* V_86 = ( F_6 ( V_2 , 0x1d ) << 8 ) |
F_6 ( V_2 , 0x1e ) ;
return 0 ;
}
static int F_21 ( struct V_19 * V_20 , int V_88 ,
enum V_89 V_90 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_91 [] = {
0x0 , 0x01 , 0x02 , 0x04 , 0x00 ,
0x8 , 0x10 , 0x20 , 0x00 , 0x3f
} ;
T_1 V_92 ;
int V_42 ;
T_1 V_93 = 0x80 ;
T_1 V_18 , V_94 [ 3 ] ;
F_3 ( L_5 , V_16 ) ;
V_42 = V_43 ;
V_92 = V_91 [ V_90 ] ;
F_10 ( V_20 , V_88 ) ;
V_42 |= F_1 ( V_2 ,
V_95 ,
& V_92 , 0x01 ) ;
V_42 |= F_7 ( V_2 , V_96 , & V_18 , 0x01 ) ;
V_18 &= ~ V_93 ;
V_42 |= F_1 ( V_2 , V_96 , & V_18 , 0x01 ) ;
V_94 [ 0 ] = 0xCB ;
V_94 [ 1 ] = 0x40 ;
V_94 [ 2 ] = 0xCB ;
V_42 |= F_1 ( V_2 ,
V_97 ,
& V_94 [ 0 ] , 0x03 ) ;
V_18 = 0x56 ;
V_42 |= F_1 ( V_2 ,
V_98 , & V_18 , 1 ) ;
V_18 = 0x05 ;
V_42 |= F_1 ( V_2 ,
V_99 , & V_18 , 1 ) ;
V_42 |= F_1 ( V_2 ,
V_96 , & V_93 , 0x01 ) ;
return V_42 ;
}
static int F_22 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
struct V_100 * V_101 = & V_20 -> V_102 ;
unsigned char V_103 ;
int V_104 ;
unsigned char V_105 = 0 ;
bool V_106 ;
int V_107 ;
int V_108 ;
unsigned int V_109 ;
unsigned int V_110 ;
unsigned int V_111 ;
unsigned int V_112 ;
int V_34 ;
bool V_113 [ V_114 ] ;
bool V_115 [ V_114 ] ;
int V_42 ;
int V_116 [ V_114 ] = { 200 , 192 , 193 , 194 , 195 ,
196 , 204 , 205 , 206 , 207
} ;
int V_117 ;
int V_118 ;
int V_119 ;
int V_120 ;
int V_121 ;
int V_33 ;
unsigned char V_94 [ 4 ] ;
F_3 ( L_15 , V_16 ) ;
if ( V_101 -> V_122 != V_123 ) {
F_3 ( L_16 ,
V_16 , V_101 -> V_122 ) ;
return - V_124 ;
}
for ( V_34 = 0 ; V_34 < V_114 ; ++ V_34 )
V_113 [ V_34 ] = V_115 [ V_34 ] = false ;
V_117 = - 700000 ;
V_118 = - 100000 ;
V_119 = 0 ;
V_120 = 0 ;
V_121 = 10 * V_101 -> V_125 ;
V_33 = V_101 -> V_126 / 100 ;
V_42 = V_43 ;
V_110 = ( V_121 - V_119 ) - ( ( V_120 * 200 )
+ ( V_33 * 135 ) ) / 200 ;
V_109 = ( V_121 - V_119 ) + ( ( V_120 * 200 )
+ ( V_33 * 135 ) ) / 200 ;
V_107 = 100000 *
( ( ( V_121 - V_119 ) -
( V_118 + V_117 ) / 2 )
/ 100000 ) ;
V_108 = ( V_121 - V_119 ) - V_107 ;
for ( V_34 = 0 ; V_34 < V_114 ; ++ V_34 ) {
V_111 = ( ( V_121 - V_119 ) / ( V_116 [ V_34 ] * 2500 ) ) *
( V_116 [ V_34 ] * 2500 ) + V_116 [ V_34 ] * 2500 ;
V_112 = ( ( V_121 - V_119 ) / ( V_116 [ V_34 ] * 2500 ) ) *
( V_116 [ V_34 ] * 2500 ) ;
if ( ( ( V_110 < V_111 ) && ( V_111 < V_109 ) ) ||
( ( V_110 < V_112 ) && ( V_112 < V_109 ) ) )
V_115 [ V_34 ] = true ;
}
for ( V_34 = 0 ; V_34 < V_114 ; ++ V_34 ) {
V_111 = ( ( V_121 - V_119 ) / ( V_116 [ V_34 ] * 5000 ) ) *
( V_116 [ V_34 ] * 5000 ) + V_116 [ V_34 ] * 5000 ;
V_112 = ( ( V_121 - V_119 ) / ( V_116 [ V_34 ] * 5000 ) ) *
( V_116 [ V_34 ] * 5000 ) ;
if ( ( ( V_110 < V_111 ) && ( V_111 < V_109 ) ) ||
( ( V_110 < V_112 ) && ( V_112 < V_109 ) ) )
V_113 [ V_34 ] = true ;
}
V_106 = true ;
for ( V_34 = 0 ; V_34 < V_114 ; ++ V_34 ) {
if ( V_113 [ V_34 ] || V_115 [ V_34 ] ) {
V_106 = false ;
break;
}
}
if ( V_106 ) {
for ( V_34 = 0 ; V_34 < V_114 ; ++ V_34 ) {
if ( ! V_113 [ V_34 ] ) {
V_105 = ( T_1 ) V_116 [ V_34 ] ;
break;
}
}
} else {
for ( V_34 = 0 ; V_34 < V_114 ; ++ V_34 ) {
if ( ( V_113 [ V_34 ] ||
! V_115 [ V_34 ] ) ) {
V_105 = ( T_1 ) V_116 [ V_34 ] ;
break;
}
}
}
if ( V_105 > 207 || V_105 < 192 )
V_105 = 200 ;
V_104 = ( ( 0x4000 * ( V_108 / 10 ) ) /
( ( V_105 ) * 1000 ) ) ;
V_103 = ( T_1 ) ( V_107 / 100000 ) ;
V_94 [ 0 ] = V_105 ;
V_94 [ 1 ] = V_103 ;
V_94 [ 2 ] = V_104 & 0xFF ;
V_94 [ 3 ] = V_104 >> 8 & 0xFF ;
V_42 |= F_1 ( V_2 , V_127 , & V_94 [ 0 ] , 0x04 ) ;
V_2 -> V_36 = V_105 ;
F_21 ( V_20 , V_101 -> V_126 , V_101 -> V_128 ) ;
return 0 ;
}
static int F_23 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_129 ;
F_3 ( L_5 , V_16 ) ;
F_7 ( V_2 , V_61 , & V_129 , 0x01 ) ;
V_129 |= 1 << 6 ;
F_1 ( V_2 , V_61 , & V_129 , 0x01 ) ;
V_2 -> V_130 = 0 ;
return 0 ;
}
static void F_24 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
F_3 ( L_5 , V_16 ) ;
F_25 ( V_2 ) ;
}
struct V_19 * F_26 ( const struct V_131 * V_11 ,
struct V_132 * V_15 )
{
struct V_1 * V_2 = NULL ;
int V_133 ;
F_3 ( L_5 , V_16 ) ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_134 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_11 = V_11 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_130 = 0 ;
V_2 -> V_82 = V_83 ;
V_133 = F_6 ( V_2 , V_61 ) ;
F_4 ( V_2 , V_61 , V_133 | 0x40 ) ;
F_9 ( 200 ) ;
V_133 = F_6 ( V_2 , 0x00 ) ;
if ( V_133 != 0x04 && V_133 != 0x14 )
goto error;
memcpy ( & V_2 -> V_135 . V_136 , & V_137 ,
sizeof( struct V_138 ) ) ;
V_2 -> V_135 . V_21 = V_2 ;
return & V_2 -> V_135 ;
error:
F_25 ( V_2 ) ;
return NULL ;
}
