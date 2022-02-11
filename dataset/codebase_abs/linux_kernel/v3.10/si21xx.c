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
V_9 . V_7 [ 0 ] = V_3 ;
memcpy ( V_9 . V_7 + 1 , V_4 , V_5 ) ;
V_6 = F_2 ( V_2 -> V_14 , & V_9 , 1 ) ;
if ( V_6 != 1 )
F_3 ( L_1
L_2 , V_15 , V_3 , V_4 [ 0 ] , V_6 ) ;
return ( V_6 != 1 ) ? - V_16 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_17 , T_1 V_4 )
{
int V_6 ;
T_1 V_7 [] = { V_17 , V_4 } ;
struct V_8 V_9 = {
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_7 = V_7 ,
. V_5 = 2
} ;
V_6 = F_2 ( V_2 -> V_14 , & V_9 , 1 ) ;
if ( V_6 != 1 )
F_3 ( L_3
L_2 , V_15 , V_17 , V_4 , V_6 ) ;
return ( V_6 != 1 ) ? - V_16 : 0 ;
}
static int F_5 ( struct V_18 * V_19 , const T_1 V_7 [] , int V_5 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
if ( V_5 != 2 )
return - V_21 ;
return F_4 ( V_2 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_17 )
{
int V_6 ;
T_1 V_22 [] = { V_17 } ;
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
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 != 2 )
F_3 ( L_4 ,
V_15 , V_17 , V_6 ) ;
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
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 != 2 )
F_3 ( L_5 , V_15 , V_6 ) ;
return V_6 == 2 ? 0 : - 1 ;
}
static int F_8 ( struct V_1 * V_2 , int V_26 )
{
unsigned long V_27 = V_28 ;
F_3 ( L_6 , V_15 ) ;
while ( ( F_6 ( V_2 , V_29 ) & 0x8 ) == 8 ) {
if ( V_28 - V_27 > V_26 ) {
F_3 ( L_7 , V_15 ) ;
return - V_30 ;
}
F_9 ( 10 ) ;
}
return 0 ;
}
static int F_10 ( struct V_18 * V_19 , T_2 V_31 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_2 V_32 , V_33 ;
int V_34 ;
T_1 V_35 [ 3 ] ;
F_3 ( L_8 , V_15 , V_31 ) ;
if ( ( V_31 < 1000000 ) || ( V_31 > 45000000 ) )
return - V_21 ;
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
static int F_11 ( struct V_18 * V_19 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_1 V_40 ;
T_1 V_41 ;
int V_42 ;
F_3 ( L_6 , V_15 ) ;
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
static int F_12 ( struct V_18 * V_19 ,
T_3 V_47 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_1 V_48 ;
F_3 ( L_6 , V_15 ) ;
if ( F_8 ( V_2 , 100 ) < 0 )
return - V_30 ;
V_48 = ( 0x80 | F_6 ( V_2 , 0xc1 ) ) ;
if ( F_4 ( V_2 , V_29 ,
V_47 == V_49 ? ( V_48 & ~ 0x10 ) : ( V_48 | 0x10 ) ) )
return - V_16 ;
if ( F_8 ( V_2 , 100 ) < 0 )
return - V_30 ;
if ( F_4 ( V_2 , V_29 , V_48 ) )
return - V_16 ;
return 0 ;
}
static int F_13 ( struct V_18 * V_19 , T_4 V_50 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_1 V_48 ;
F_3 ( L_6 , V_15 ) ;
V_48 = ( 0x80 | F_6 ( V_2 , V_29 ) ) ;
switch ( V_50 ) {
case V_51 :
return F_4 ( V_2 , V_29 , V_48 | 0x20 ) ;
case V_52 :
return F_4 ( V_2 , V_29 , ( V_48 & ~ 0x20 ) ) ;
default:
return - V_21 ;
}
}
static int F_14 ( struct V_18 * V_19 , T_5 V_53 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_1 V_48 ;
F_3 ( L_9 , V_15 ,
V_53 == V_54 ? L_10 :
V_53 == V_55 ? L_11 : L_12 ) ;
V_48 = ( 0x80 | F_6 ( V_2 , V_29 ) ) ;
switch ( V_53 ) {
case V_55 :
return F_4 ( V_2 , V_29 , V_48 | 0x40 ) ;
break;
case V_54 :
return F_4 ( V_2 , V_29 , ( V_48 & ~ 0x40 ) ) ;
break;
default:
return - V_21 ;
}
}
static int F_15 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
int V_34 ;
int V_42 = 0 ;
T_1 V_3 ;
T_1 V_48 ;
T_1 V_56 [ 2 ] ;
F_3 ( L_6 , V_15 ) ;
for ( V_34 = 0 ; ; V_34 += 2 ) {
V_3 = V_57 [ V_34 ] ;
V_48 = V_57 [ V_34 + 1 ] ;
if ( V_3 == 0xff && V_48 == 0xff )
break;
F_1 ( V_2 , V_3 , & V_48 , 1 ) ;
}
V_3 = 0x08 ;
F_1 ( V_2 , V_58 , & V_3 , 0x01 ) ;
V_56 [ 0 ] =
V_59 + ( V_60 << 1 )
+ ( V_61 << 2 ) + ( V_62 << 3 )
+ ( V_63 << 4 ) + ( V_64 << 5 )
+ ( V_64 << 6 ) + ( V_64 << 7 ) ;
V_56 [ 1 ] = 0 ;
V_42 |= F_1 ( V_2 , V_65 , V_56 , 0x02 ) ;
if ( V_42 != 0 )
F_3 ( L_13 , V_15 ) ;
return 0 ;
}
static int F_16 ( struct V_18 * V_19 , T_6 * V_42 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_1 V_66 [ 2 ] ;
T_1 V_67 ;
T_1 V_34 ;
T_1 V_68 ;
T_1 signal = F_6 ( V_2 , V_69 ) ;
F_7 ( V_2 , V_70 , V_66 , 0x02 ) ;
V_67 = 0 ;
for ( V_34 = 0 ; V_34 < 7 ; ++ V_34 )
V_67 |= ( ( V_66 [ 0 ] >> V_34 ) & 0x01 ) << ( 6 - V_34 ) ;
V_68 = ( ( V_67 & 0x7f ) | ( V_66 [ 1 ] & 0x80 ) ) ;
F_3 ( L_14 , V_15 , V_68 ) ;
* V_42 = 0 ;
if ( signal > 10 )
* V_42 |= V_71 ;
if ( V_68 & 0x2 )
* V_42 |= V_72 ;
if ( V_68 & 0x20 )
* V_42 |= V_73 ;
if ( V_68 & 0x40 )
* V_42 |= V_74 ;
if ( ( V_68 & 0x7b ) == 0x7b )
* V_42 |= V_75 ;
return 0 ;
}
static int F_17 ( struct V_18 * V_19 , T_7 * V_76 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_7 signal = ( 3 * F_6 ( V_2 , 0x27 ) *
F_6 ( V_2 , 0x28 ) ) ;
F_3 ( L_15 , V_15 ,
F_6 ( V_2 , 0x27 ) ,
F_6 ( V_2 , 0x28 ) , ( int ) signal ) ;
signal <<= 4 ;
* V_76 = signal ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 , T_2 * V_77 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_3 ( L_6 , V_15 ) ;
if ( V_2 -> V_78 != V_79 )
return 0 ;
* V_77 = ( F_6 ( V_2 , 0x1d ) << 8 ) |
F_6 ( V_2 , 0x1e ) ;
return 0 ;
}
static int F_19 ( struct V_18 * V_19 , T_7 * V_80 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_8 V_81 = 0xffff - ( ( F_6 ( V_2 , 0x24 ) << 8 ) |
F_6 ( V_2 , 0x25 ) ) ;
V_81 = 3 * ( V_81 - 0xa100 ) ;
* V_80 = ( V_81 > 0xffff ) ? 0xffff : ( V_81 < 0 ) ? 0 : V_81 ;
F_3 ( L_6 , V_15 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 , T_2 * V_82 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_3 ( L_6 , V_15 ) ;
if ( V_2 -> V_78 != V_83 )
* V_82 = 0 ;
else
* V_82 = ( F_6 ( V_2 , 0x1d ) << 8 ) |
F_6 ( V_2 , 0x1e ) ;
return 0 ;
}
static int F_21 ( struct V_18 * V_19 , int V_84 ,
T_9 V_85 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_1 V_86 [] = {
0x0 , 0x01 , 0x02 , 0x04 , 0x00 ,
0x8 , 0x10 , 0x20 , 0x00 , 0x3f
} ;
T_1 V_87 ;
int V_42 ;
T_1 V_88 = 0x80 ;
T_1 V_17 , V_89 [ 3 ] ;
F_3 ( L_6 , V_15 ) ;
V_42 = V_43 ;
V_87 = V_86 [ V_85 ] ;
F_10 ( V_19 , V_84 ) ;
V_42 |= F_1 ( V_2 ,
V_90 ,
& V_87 , 0x01 ) ;
V_42 |= F_7 ( V_2 , V_91 , & V_17 , 0x01 ) ;
V_17 &= ~ V_88 ;
V_42 |= F_1 ( V_2 , V_91 , & V_17 , 0x01 ) ;
V_89 [ 0 ] = 0xCB ;
V_89 [ 1 ] = 0x40 ;
V_89 [ 2 ] = 0xCB ;
V_42 |= F_1 ( V_2 ,
V_92 ,
& V_89 [ 0 ] , 0x03 ) ;
V_17 = 0x56 ;
V_42 |= F_1 ( V_2 ,
V_93 , & V_17 , 1 ) ;
V_17 = 0x05 ;
V_42 |= F_1 ( V_2 ,
V_94 , & V_17 , 1 ) ;
V_42 |= F_1 ( V_2 ,
V_91 , & V_88 , 0x01 ) ;
return V_42 ;
}
static int F_22 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
struct V_95 * V_96 = & V_19 -> V_97 ;
unsigned char V_98 ;
int V_99 ;
unsigned char V_100 = 0 ;
bool V_101 ;
int V_102 ;
int V_103 ;
unsigned int V_104 ;
unsigned int V_105 ;
unsigned int V_106 ;
unsigned int V_107 ;
int V_34 ;
bool V_108 [ V_109 ] ;
bool V_110 [ V_109 ] ;
int V_42 ;
int V_111 [ V_109 ] = { 200 , 192 , 193 , 194 , 195 ,
196 , 204 , 205 , 206 , 207
} ;
int V_112 ;
int V_113 ;
int V_114 ;
int V_115 ;
int V_116 ;
int V_33 ;
unsigned char V_89 [ 4 ] ;
F_3 ( L_16 , V_15 ) ;
if ( V_96 -> V_117 != V_118 ) {
F_3 ( L_17 ,
V_15 , V_96 -> V_117 ) ;
return - V_119 ;
}
for ( V_34 = 0 ; V_34 < V_109 ; ++ V_34 )
V_108 [ V_34 ] = V_110 [ V_34 ] = false ;
V_112 = - 700000 ;
V_113 = - 100000 ;
V_114 = 0 ;
V_115 = 0 ;
V_116 = 10 * V_96 -> V_120 ;
V_33 = V_96 -> V_121 / 100 ;
V_42 = V_43 ;
V_105 = ( V_116 - V_114 ) - ( ( V_115 * 200 )
+ ( V_33 * 135 ) ) / 200 ;
V_104 = ( V_116 - V_114 ) + ( ( V_115 * 200 )
+ ( V_33 * 135 ) ) / 200 ;
V_102 = 100000 *
( ( ( V_116 - V_114 ) -
( V_113 + V_112 ) / 2 )
/ 100000 ) ;
V_103 = ( V_116 - V_114 ) - V_102 ;
for ( V_34 = 0 ; V_34 < V_109 ; ++ V_34 ) {
V_106 = ( ( V_116 - V_114 ) / ( V_111 [ V_34 ] * 2500 ) ) *
( V_111 [ V_34 ] * 2500 ) + V_111 [ V_34 ] * 2500 ;
V_107 = ( ( V_116 - V_114 ) / ( V_111 [ V_34 ] * 2500 ) ) *
( V_111 [ V_34 ] * 2500 ) ;
if ( ( ( V_105 < V_106 ) && ( V_106 < V_104 ) ) ||
( ( V_105 < V_107 ) && ( V_107 < V_104 ) ) )
V_110 [ V_34 ] = true ;
}
for ( V_34 = 0 ; V_34 < V_109 ; ++ V_34 ) {
V_106 = ( ( V_116 - V_114 ) / ( V_111 [ V_34 ] * 5000 ) ) *
( V_111 [ V_34 ] * 5000 ) + V_111 [ V_34 ] * 5000 ;
V_107 = ( ( V_116 - V_114 ) / ( V_111 [ V_34 ] * 5000 ) ) *
( V_111 [ V_34 ] * 5000 ) ;
if ( ( ( V_105 < V_106 ) && ( V_106 < V_104 ) ) ||
( ( V_105 < V_107 ) && ( V_107 < V_104 ) ) )
V_108 [ V_34 ] = true ;
}
V_101 = true ;
for ( V_34 = 0 ; V_34 < V_109 ; ++ V_34 ) {
if ( V_108 [ V_34 ] || V_110 [ V_34 ] ) {
V_101 = false ;
break;
}
}
if ( V_101 ) {
for ( V_34 = 0 ; V_34 < V_109 ; ++ V_34 ) {
if ( ! V_108 [ V_34 ] ) {
V_100 = ( T_1 ) V_111 [ V_34 ] ;
break;
}
}
} else {
for ( V_34 = 0 ; V_34 < V_109 ; ++ V_34 ) {
if ( ( V_108 [ V_34 ] ||
! V_110 [ V_34 ] ) ) {
V_100 = ( T_1 ) V_111 [ V_34 ] ;
break;
}
}
}
if ( V_100 > 207 || V_100 < 192 )
V_100 = 200 ;
V_99 = ( ( 0x4000 * ( V_103 / 10 ) ) /
( ( V_100 ) * 1000 ) ) ;
V_98 = ( T_1 ) ( V_102 / 100000 ) ;
V_89 [ 0 ] = V_100 ;
V_89 [ 1 ] = V_98 ;
V_89 [ 2 ] = V_99 & 0xFF ;
V_89 [ 3 ] = V_99 >> 8 & 0xFF ;
V_42 |= F_1 ( V_2 , V_122 , & V_89 [ 0 ] , 0x04 ) ;
V_2 -> V_36 = V_100 ;
F_21 ( V_19 , V_96 -> V_121 , V_96 -> V_123 ) ;
return 0 ;
}
static int F_23 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_1 V_124 ;
F_3 ( L_6 , V_15 ) ;
F_7 ( V_2 , V_58 , & V_124 , 0x01 ) ;
V_124 |= 1 << 6 ;
F_1 ( V_2 , V_58 , & V_124 , 0x01 ) ;
V_2 -> V_125 = 0 ;
return 0 ;
}
static void F_24 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_3 ( L_6 , V_15 ) ;
F_25 ( V_2 ) ;
}
struct V_18 * F_26 ( const struct V_126 * V_11 ,
struct V_127 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_128 ;
F_3 ( L_6 , V_15 ) ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_129 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_11 = V_11 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_125 = 0 ;
V_2 -> V_78 = V_79 ;
V_128 = F_6 ( V_2 , V_58 ) ;
F_4 ( V_2 , V_58 , V_128 | 0x40 ) ;
F_9 ( 200 ) ;
V_128 = F_6 ( V_2 , 0x00 ) ;
if ( V_128 != 0x04 && V_128 != 0x14 )
goto error;
memcpy ( & V_2 -> V_130 . V_131 , & V_132 ,
sizeof( struct V_133 ) ) ;
V_2 -> V_130 . V_20 = V_2 ;
return & V_2 -> V_130 ;
error:
F_25 ( V_2 ) ;
return NULL ;
}
