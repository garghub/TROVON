static T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
T_1 V_4 = 0 ;
if ( V_2 -> V_5 -> V_6 -> V_7 )
V_4 = ( V_2 -> V_5 -> V_6 -> V_7 ( V_2 -> V_5 ,
V_3 ) ) & 0xFF ;
else
F_2 ( 1 ,
V_8 L_1 ,
V_2 -> V_9 ) ;
F_2 ( 4 , L_2 , V_2 -> V_9 , V_3 ,
V_4 ) ;
return V_4 ;
}
static void
F_3 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_1 V_4 )
{
F_2 ( 4 , L_3 , V_2 -> V_9 , V_4 ,
V_3 ) ;
if ( V_2 -> V_5 -> V_6 -> V_10 )
V_2 -> V_5 -> V_6 -> V_10 ( V_2 -> V_5 , V_3 , V_4 ) ;
else
F_2 ( 1 ,
V_8
L_4 ,
V_2 -> V_9 ) ;
}
static T_1
F_4 ( struct V_1 * V_2 )
{
V_2 -> V_11 = F_1 ( V_2 , V_12 ) ;
F_1 ( V_2 , 0 ) ;
return V_2 -> V_11 ;
}
static T_2
F_5 ( struct V_1 * V_2 )
{
V_2 -> V_13 = ( F_1 ( V_2 , V_14 ) << 8 ) |
( F_1 ( V_2 , V_15 ) & 0xFF ) ;
F_1 ( V_2 , 0 ) ;
return V_2 -> V_13 ;
}
static void
F_6 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
while ( ! ( F_4 ( V_2 ) & 0x4 ) ) {
F_7 ( 1 ) ;
if ( V_16 ++ > 200000 ) {
F_2 ( 1 ,
L_5 ,
V_2 -> V_9 , V_2 -> V_11 ) ;
break;
}
}
}
static int
F_8 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_17 , 0x00 ) ;
F_3 ( V_2 , V_17 + 1 , 0x00 ) ;
if ( ( F_1 ( V_2 , V_17 ) |
F_1 ( V_2 , V_17 + 1 ) ) != 0x0000 ) {
F_2 ( 1 ,
V_8
L_6 ,
V_2 -> V_9 ) ;
return - V_18 ;
}
F_3 ( V_2 , V_17 , 0xff ) ;
F_3 ( V_2 , V_17 + 1 , 0xc0 ) ;
if ( ( ( F_1 ( V_2 , V_17 ) << 8 ) |
F_1 ( V_2 , V_17 + 1 ) ) != 0xffc0 ) {
F_2 ( 1 ,
V_8
L_6 ,
V_2 -> V_9 ) ;
return - V_18 ;
}
F_6 ( V_2 ) ;
if ( ( V_2 -> V_11 & 0x4 ) == 0 ) {
F_2 ( 1 ,
V_8
L_7 ,
V_2 -> V_9 ) ;
return - V_19 ;
}
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 ,
T_2 V_20 ,
T_2 V_21 ,
const char * V_22 )
{
int V_16 = 0 ;
F_2 ( 4 , L_8 , V_2 -> V_9 ,
V_20 , V_21 ) ;
while ( V_16 < V_21 ) {
F_3 ( V_2 , V_20 ++ , V_22 [ V_16 ++ ] ) ;
}
return V_16 ;
}
static int
F_10 ( struct V_1 * V_2 )
{
char V_23 [ 34 ] ;
int V_16 ;
F_2 ( 3 , L_9 , V_2 -> V_9 ,
V_2 -> V_24 , V_2 -> V_25 , V_26 ) ;
V_23 [ 0 ] = 0xff ;
V_23 [ 1 ] = 0xc0 ;
V_23 [ 2 ] = 0x00 ;
V_23 [ 3 ] = ( 3 * V_26 ) + 8 ;
V_23 [ 4 ] = V_27 ;
V_23 [ 5 ] = ( V_2 -> V_25 ) >> 8 ;
V_23 [ 6 ] = ( V_2 -> V_25 ) & 0xff ;
V_23 [ 7 ] = ( V_2 -> V_24 ) >> 8 ;
V_23 [ 8 ] = ( V_2 -> V_24 ) & 0xff ;
V_23 [ 9 ] = V_26 ;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
V_23 [ 10 + ( V_16 * 3 ) ] = V_16 ;
V_23 [ 11 + ( V_16 * 3 ) ] = ( V_2 -> V_28 [ V_16 ] << 4 ) | ( V_2 -> V_29 [ V_16 ] ) ;
V_23 [ 12 + ( V_16 * 3 ) ] = V_30 [ V_16 ] ;
}
return F_9 ( V_2 , V_17 ,
( 3 * V_26 ) + 10 , V_23 ) ;
}
static int
F_11 ( struct V_1 * V_2 )
{
char V_31 [ 16 ] ;
int V_16 ;
F_2 ( 3 , L_10 , V_2 -> V_9 ) ;
V_31 [ 0 ] = 0xff ;
V_31 [ 1 ] = 0xda ;
V_31 [ 2 ] = 0x00 ;
V_31 [ 3 ] = 2 + 1 + ( 2 * V_26 ) + 3 ;
V_31 [ 4 ] = V_26 ;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
V_31 [ 5 + ( V_16 * 2 ) ] = V_16 ;
V_31 [ 6 + ( V_16 * 2 ) ] = ( V_32 [ V_16 ] << 4 ) | V_33 [ V_16 ] ;
}
V_31 [ 2 + 1 + ( 2 * V_26 ) + 2 ] = 00 ;
V_31 [ 2 + 1 + ( 2 * V_26 ) + 3 ] = 0x3F ;
V_31 [ 2 + 1 + ( 2 * V_26 ) + 4 ] = 00 ;
return F_9 ( V_2 , V_34 ,
4 + 1 + ( 2 * V_26 ) + 3 ,
V_31 ) ;
}
static int
F_12 ( struct V_1 * V_2 )
{
char V_35 [ 6 ] ;
F_2 ( 3 , L_11 , V_2 -> V_9 ) ;
V_35 [ 0 ] = 0xff ;
V_35 [ 1 ] = 0xdd ;
V_35 [ 2 ] = 0x00 ;
V_35 [ 3 ] = 0x04 ;
V_35 [ 4 ] = V_2 -> V_36 >> 8 ;
V_35 [ 5 ] = V_2 -> V_36 & 0xff ;
return F_9 ( V_2 , V_37 , 6 , V_35 ) ;
}
static void
F_13 ( struct V_1 * V_2 )
{
int V_38 = 0 ;
long V_39 , V_40 ;
if ( V_2 -> V_41 == V_42 ) {
F_2 ( 2 , L_12 , V_2 -> V_9 ) ;
F_3 ( V_2 , V_43 , V_44 ) ;
F_3 ( V_2 , V_45 ,
V_46 | V_47 ) ;
F_3 ( V_2 , V_48 , 0 ) ;
F_3 ( V_2 , V_49 , 0 ) ;
F_3 ( V_2 , V_50 , 3 ) ;
F_3 ( V_2 , V_14 , V_2 -> V_13 >> 8 ) ;
F_3 ( V_2 , V_15 , V_2 -> V_13 & 0xff ) ;
F_3 ( V_2 , V_51 , 0xff ) ;
F_3 ( V_2 , V_52 , 0xff ) ;
F_3 ( V_2 , V_53 , 0xff ) ;
V_38 += F_10 ( V_2 ) ;
V_38 += F_11 ( V_2 ) ;
V_38 += F_12 ( V_2 ) ;
F_2 ( 3 , L_13 , V_2 -> V_9 ) ;
V_38 += F_9 ( V_2 , V_54 ,
sizeof( V_55 ) , V_55 ) ;
V_38 += F_9 ( V_2 , V_56 ,
sizeof( V_57 ) , V_57 ) ;
F_3 ( V_2 , V_58 , 0xff ) ;
F_3 ( V_2 , V_58 + 1 , 0xe0 + V_2 -> V_59 . V_60 ) ;
F_3 ( V_2 , V_58 + 2 , 0x00 ) ;
F_3 ( V_2 , V_58 + 3 , V_2 -> V_59 . V_21 + 2 ) ;
V_38 += F_9 ( V_2 , V_58 + 4 , 60 ,
V_2 -> V_59 . V_22 ) + 4 ;
F_3 ( V_2 , V_61 , 0xff ) ;
F_3 ( V_2 , V_61 + 1 , 0xfe ) ;
F_3 ( V_2 , V_61 + 2 , 0x00 ) ;
F_3 ( V_2 , V_61 + 3 , V_2 -> V_62 . V_21 + 2 ) ;
V_38 += F_9 ( V_2 , V_61 + 4 , 60 ,
V_2 -> V_62 . V_22 ) + 4 ;
F_3 ( V_2 , V_63 , V_64 ) ;
F_3 ( V_2 , V_65 , 1 ) ;
F_6 ( V_2 ) ;
F_2 ( 2 , L_14 ,
V_2 -> V_9 , V_2 -> V_11 ) ;
if ( ( V_2 -> V_11 & 0x4 ) == 0 ) {
F_2 ( 1 , V_8 L_15 ,
V_2 -> V_9 ) ;
return;
}
V_38 = V_2 -> V_66 - V_38 ;
V_39 = V_38 << 3 ;
V_40 = V_39 >> 16 ;
F_2 ( 3 ,
L_16 ,
V_2 -> V_9 , V_38 , V_2 -> V_66 , V_39 , V_40 ) ;
F_3 ( V_2 , V_67 , V_40 >> 8 ) ;
F_3 ( V_2 , V_68 , V_40 & 0xff ) ;
V_40 = V_39 & 0xffff ;
F_3 ( V_2 , V_69 , V_40 >> 8 ) ;
F_3 ( V_2 , V_70 , V_40 & 0xff ) ;
V_39 -= V_39 >> 7 ;
V_39 -= ( ( V_39 * 5 ) >> 6 ) ;
V_40 = V_39 >> 16 ;
F_2 ( 3 , L_17 ,
V_2 -> V_9 , V_39 , V_40 ) ;
F_3 ( V_2 , V_71 , V_40 >> 8 ) ;
F_3 ( V_2 , V_72 , V_40 & 0xff ) ;
V_40 = V_39 & 0xffff ;
F_3 ( V_2 , V_73 , V_40 >> 8 ) ;
F_3 ( V_2 , V_74 , V_40 & 0xff ) ;
F_3 ( V_2 , V_45 ,
V_46 | V_75 |
( V_2 -> V_76 ? V_77 : 0 ) ) ;
F_3 ( V_2 , V_63 ,
V_78 | V_79 |
( ( V_2 -> V_59 . V_21 > 0 ) ? V_80 : 0 ) |
( ( V_2 -> V_62 . V_21 > 0 ) ? V_81 : 0 ) ) ;
} else {
F_2 ( 2 , L_18 , V_2 -> V_9 ) ;
F_3 ( V_2 , V_43 ,
V_44 | V_82 ) ;
F_3 ( V_2 , V_45 , V_47 ) ;
F_3 ( V_2 , V_49 , 0 ) ;
F_3 ( V_2 , V_50 , 3 ) ;
F_2 ( 3 , L_19 , V_2 -> V_9 ) ;
F_9 ( V_2 , V_56 , sizeof( V_57 ) ,
V_57 ) ;
F_3 ( V_2 , V_63 , V_64 ) ;
F_3 ( V_2 , V_65 , 1 ) ;
F_6 ( V_2 ) ;
F_2 ( 2 , L_14 ,
V_2 -> V_9 , V_2 -> V_11 ) ;
if ( ( V_2 -> V_11 & 0x4 ) == 0 ) {
F_2 ( 1 , V_8 L_15 ,
V_2 -> V_9 ) ;
return;
}
F_3 ( V_2 , V_45 , 0 ) ;
F_3 ( V_2 , V_63 , 0 ) ;
}
F_1 ( V_2 , 0 ) ;
}
static int
F_14 ( struct V_83 * V_5 ,
int V_41 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 -> V_22 ;
F_2 ( 2 , L_20 , V_2 -> V_9 , V_41 ) ;
if ( ( V_41 != V_84 ) && ( V_41 != V_42 ) )
return - V_85 ;
V_2 -> V_41 = V_41 ;
F_13 ( V_2 ) ;
return 0 ;
}
static int
F_15 ( struct V_83 * V_5 ,
struct V_86 * V_87 ,
struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 -> V_22 ;
int V_92 ;
F_2 ( 2 , L_21 ,
V_2 -> V_9 , V_87 -> V_93 , V_87 -> V_94 ,
V_89 -> V_95 , V_89 -> V_96 , V_89 -> V_24 , V_89 -> V_25 ,
V_89 -> V_97 , V_89 -> V_98 ) ;
V_2 -> V_24 = V_89 -> V_24 / ( V_89 -> V_97 & 0xff ) ;
V_2 -> V_25 = V_89 -> V_25 / ( ( V_89 -> V_97 >> 8 ) & 0xff ) ;
V_92 = V_2 -> V_24 * V_2 -> V_25 ;
V_92 *= 16 ;
V_92 = V_92 * V_89 -> V_98 / 200 ;
if ( V_92 < 8192 )
V_92 = 8192 ;
if ( V_92 > V_2 -> V_99 * 7 )
V_92 = V_2 -> V_99 * 7 ;
V_2 -> V_66 = V_92 >> 3 ;
F_3 ( V_2 , V_100 , V_2 -> V_101 ) ;
return 0 ;
}
static int
F_16 ( struct V_83 * V_5 ,
int type ,
int V_92 ,
void * V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 -> V_22 ;
int * V_102 = ( int * ) V_22 ;
F_2 ( 2 , L_22 , V_2 -> V_9 , type ,
V_92 ) ;
switch ( type ) {
case V_103 :
if ( V_92 != sizeof( int ) )
return - V_104 ;
F_4 ( V_2 ) ;
* V_102 = V_2 -> V_11 ;
break;
case V_105 :
if ( V_92 != sizeof( int ) )
return - V_104 ;
* V_102 = V_106 ;
break;
case V_107 :
if ( V_92 != sizeof( int ) )
return - V_104 ;
if ( * V_102 != V_106 )
return - V_85 ;
return 0 ;
case V_108 :
case V_109 :
return 0 ;
case V_110 :
return - V_18 ;
case V_111 :
if ( V_92 != sizeof( int ) )
return - V_104 ;
* V_102 = V_2 -> V_99 ;
break;
case V_112 :
if ( V_92 != sizeof( int ) )
return - V_104 ;
V_2 -> V_99 = * V_102 ;
V_2 -> V_66 = ( V_2 -> V_99 * 6 ) >> 3 ;
break;
case V_113 :
if ( V_92 != sizeof( int ) )
return - V_104 ;
* V_102 = F_5 ( V_2 ) ;
break;
case V_114 :
if ( V_92 != sizeof( int ) )
return - V_104 ;
V_2 -> V_13 = * V_102 ;
break;
case V_115 : {
struct V_116 * V_59 = V_22 ;
if ( V_92 != sizeof( struct V_116 ) )
return - V_104 ;
* V_59 = V_2 -> V_59 ;
break;
}
case V_117 : {
struct V_116 * V_59 = V_22 ;
if ( V_92 != sizeof( struct V_116 ) )
return - V_104 ;
V_2 -> V_59 = * V_59 ;
break;
}
case V_118 : {
struct V_119 * V_62 = V_22 ;
if ( V_92 != sizeof( struct V_119 ) )
return - V_104 ;
* V_62 = V_2 -> V_62 ;
break;
}
case V_120 : {
struct V_119 * V_62 = V_22 ;
if ( V_92 != sizeof( struct V_119 ) )
return - V_104 ;
V_2 -> V_62 = * V_62 ;
break;
}
default:
return - V_85 ;
}
return V_92 ;
}
static int
F_17 ( struct V_83 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_22 ;
if ( V_2 ) {
F_2 ( 1 , L_23 , V_2 -> V_9 ,
V_2 -> V_121 ) ;
F_18 ( V_2 ) ;
V_5 -> V_22 = NULL ;
V_122 -- ;
return 0 ;
}
return - V_104 ;
}
static int
F_19 ( struct V_83 * V_5 )
{
struct V_1 * V_2 ;
int V_123 ;
F_2 ( 2 , L_24 ,
V_122 ) ;
if ( V_122 == V_124 ) {
F_2 ( 1 ,
V_8 L_25 ) ;
return - V_125 ;
}
V_5 -> V_22 = V_2 = F_20 ( sizeof( struct V_1 ) , V_126 ) ;
if ( NULL == V_2 ) {
F_2 ( 1 , V_8 L_26 ) ;
return - V_127 ;
}
snprintf ( V_2 -> V_9 , sizeof( V_2 -> V_9 ) , L_27 ,
V_122 ) ;
V_2 -> V_121 = V_122 ++ ;
V_2 -> V_5 = V_5 ;
V_123 = F_8 ( V_2 ) ;
if ( V_123 < 0 ) {
F_17 ( V_5 ) ;
return V_123 ;
}
memcpy ( V_2 -> V_28 , V_128 , 8 ) ;
memcpy ( V_2 -> V_29 , V_129 , 8 ) ;
V_2 -> V_76 = 0 ;
V_2 -> V_41 = V_42 ;
V_2 -> V_24 = 384 ;
V_2 -> V_25 = 288 ;
V_2 -> V_99 = 16000 ;
V_2 -> V_101 = 240 ;
V_2 -> V_13 = 0x100 ;
V_2 -> V_36 = 1 ;
V_2 -> V_59 . V_60 = 0 ;
V_2 -> V_59 . V_21 = 0 ;
V_2 -> V_62 . V_21 = 0 ;
F_13 ( V_2 ) ;
F_2 ( 1 , V_130 L_28 ,
V_2 -> V_9 ) ;
return 0 ;
}
static int T_3
F_21 ( void )
{
V_122 = 0 ;
return F_22 ( & V_131 ) ;
}
static void T_4
F_23 ( void )
{
if ( V_122 ) {
F_2 ( 1 ,
L_29 ,
V_122 ) ;
}
F_24 ( & V_131 ) ;
}
