int F_1 ( int V_1 )
{
switch ( V_1 ) {
case 0x4142 :
case 0x4149 :
case 0x414D :
case 0x4341 :
case 0x4344 :
case 0x4354 :
case 0x4358 :
case 0x444B :
case 0x4558 :
case 0x4643 :
case 0x4651 :
case 0x4C47 :
case 0x4C4B :
case 0x4C51 :
case 0x4F48 :
case 0x504F :
case 0x5053 :
case 0x5058 :
case 0x5343 :
case 0x5344 :
case 0x5345 :
case 0x5350 :
return V_2 ;
case 0x414B :
case 0x4345 :
case 0x4349 :
case 0x434D :
case 0x4847 :
case 0x4849 :
case 0x484D :
case 0x4850 :
case 0x4851 :
case 0x4954 :
case 0x4958 :
case 0x4B43 :
case 0x4B44 :
case 0x4B45 :
case 0x4B47 :
case 0x4B48 :
case 0x4B49 :
case 0x4B4E :
case 0x4B50 :
case 0x4B52 :
case 0x4B54 :
case 0x4B58 :
case 0x4D50 :
case 0x4D53 :
case 0x4D56 :
case 0x4D58 :
case 0x5044 :
case 0x5045 :
case 0x5046 :
case 0x5047 :
case 0x5049 :
case 0x504B :
case 0x504D :
case 0x5254 :
case 0x5347 :
case 0x5349 :
case 0x534B :
case 0x534D :
case 0x5356 :
case 0x5358 :
case 0x5443 :
case 0x544B :
case 0x5647 :
return V_3 ;
default:
return V_4 ;
}
}
int F_2 ( int V_1 )
{
switch ( V_1 ) {
case 1 :
case 2 :
case 36 :
case 37 :
case 38 :
case 39 :
case 40 :
return V_2 ;
case 17 :
case 18 :
case 19 :
case 20 :
case 21 :
case 22 :
case 26 :
case 30 :
case 31 :
case 32 :
case 33 :
case 34 :
case 35 :
return V_3 ;
default:
return V_4 ;
}
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
static struct V_11 V_12 = {
. type = 0x06 ,
. V_13 = 0x00000058 ,
. V_14 = { 'C' , 'A' ,} ,
. V_15 = { 'P' , 'K' } ,
} ;
static struct V_16 V_17 = {
. V_15 = { 'P' , 'K' } ,
. V_18 = 10 ,
. V_19 = { 'M' , 'R' , 'P' , ' ' , ' ' , ' ' , ' ' , ' ' }
} ;
struct {
struct V_11 V_20 ;
struct V_21 V_22 ;
struct V_16 V_23 ;
unsigned short V_24 ;
char V_25 [ 0 ] ;
} V_26 * V_27 = V_8 -> V_28 ;
int V_29 ;
V_27 -> V_24 = V_10 -> V_30 + 2 ;
if ( F_4 ( V_27 -> V_25 , V_10 -> V_31 , V_10 -> V_30 ) )
return - V_32 ;
V_29 = F_5 ( V_10 , V_27 -> V_25 + V_10 -> V_30 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 += sizeof( * V_27 ) + V_10 -> V_30 ;
V_27 -> V_20 = V_12 ;
V_27 -> V_20 . V_33 = V_29 - sizeof( V_27 -> V_20 ) ;
V_27 -> V_20 . V_34 = V_35 - sizeof( V_27 -> V_20 ) ;
V_27 -> V_22 = V_36 ;
V_27 -> V_22 . V_37 = F_6 ( V_6 -> V_38 -> V_39 ) ;
V_27 -> V_22 . V_40 = V_27 -> V_20 . V_34 ;
V_27 -> V_23 = V_17 ;
V_27 -> V_22 . V_41 = V_29 - sizeof( V_27 -> V_20 ) - sizeof( V_27 -> V_22 ) ;
V_8 -> V_24 = V_29 ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_42 * V_43 )
{
static struct V_11 V_12 = {
. type = 0x06 ,
. V_13 = 0x00000058 ,
. V_14 = { 'C' , 'A' ,} ,
. V_15 = { 'P' , 'D' } ,
} ;
static struct V_16 V_44 = {
. V_15 = { 'P' , 'D' } ,
. V_18 = 10 ,
. V_19 = { 'Z' , 'E' , 'R' , 'O' , '-' , 'P' , 'A' , 'D' }
} ;
struct {
struct V_11 V_20 ;
struct V_21 V_22 ;
struct V_16 V_23 ;
unsigned short V_24 ;
char V_25 [ 0 ] ;
} V_26 * V_27 = V_8 -> V_28 ;
int V_29 ;
V_27 -> V_24 = V_43 -> V_30 + 2 ;
if ( F_4 ( V_27 -> V_25 , V_43 -> V_31 , V_43 -> V_30 ) )
return - V_32 ;
V_29 = F_8 ( V_43 , V_27 -> V_25 + V_43 -> V_30 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 += sizeof( * V_27 ) + V_43 -> V_30 ;
V_27 -> V_20 = V_12 ;
V_27 -> V_20 . V_33 = V_29 - sizeof( V_27 -> V_20 ) ;
V_27 -> V_20 . V_34 = V_35 - sizeof( V_27 -> V_20 ) ;
V_27 -> V_22 = V_36 ;
V_27 -> V_22 . V_37 = F_6 ( V_6 -> V_38 -> V_39 ) ;
V_27 -> V_22 . V_41 = V_27 -> V_22 . V_40 =
V_29 - sizeof( V_27 -> V_20 ) - sizeof( V_27 -> V_22 ) ;
V_27 -> V_23 = V_44 ;
V_8 -> V_24 = V_29 ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 ,
struct V_45 * V_46 ,
unsigned int * V_47 ,
unsigned short * * V_48 )
{
static struct V_11 V_12 = {
. type = 0x06 ,
. V_13 = 0x00000058 ,
} ;
struct {
struct V_11 V_20 ;
struct V_21 V_22 ;
} V_26 * V_27 = V_8 -> V_28 ;
int V_49 = F_10 ( V_46 -> V_50 ) ;
int V_51 , V_52 , V_53 ;
char * V_54 = V_8 -> V_28 + sizeof( struct V_11 ) + V_49 ;
char * V_15 ;
if ( F_10 ( V_46 -> V_50 ) <
V_46 -> V_50 )
return - V_55 ;
V_8 -> V_24 = sizeof( struct V_11 ) +
F_10 ( V_46 -> V_50 ) +
V_46 -> V_56 ;
if ( V_8 -> V_24 > V_57 )
return - V_55 ;
V_52 = F_10 ( V_46 -> V_50 ) +
V_46 -> V_56 ;
if ( ( F_10 ( V_46 -> V_50 ) <=
V_46 -> V_56 ) ?
( V_52 < V_46 -> V_56 ) :
( V_52 < F_10 ( V_46 -> V_50 ) ) ) {
return - V_55 ;
}
if ( F_10 ( V_46 -> V_58 ) <
V_46 -> V_58 )
return - V_55 ;
V_51 = sizeof( struct V_59 ) +
F_10 ( V_46 -> V_58 ) +
V_46 -> V_60 ;
if ( V_51 > V_57 )
return - V_55 ;
V_53 = F_10 ( V_46 -> V_58 ) +
V_46 -> V_60 ;
if ( ( F_10 ( V_46 -> V_58 ) <= V_46 -> V_60 ) ?
( V_53 < V_46 -> V_60 ) :
( V_53 < F_10 ( V_46 -> V_58 ) ) ) {
return - V_55 ;
}
V_27 -> V_20 = V_12 ;
memcpy ( V_27 -> V_20 . V_14 , & ( V_46 -> V_61 ) , sizeof( V_46 -> V_61 ) ) ;
V_27 -> V_20 . V_33 = V_46 -> V_50 ;
if ( V_46 -> V_56 ) {
V_27 -> V_20 . V_62 = V_27 -> V_20 . V_13 + V_49 ;
V_27 -> V_20 . V_63 = V_46 -> V_56 ;
}
V_27 -> V_20 . V_34 = V_46 -> V_58 ;
V_27 -> V_20 . V_64 = V_46 -> V_60 ;
if ( F_4 ( & ( V_27 -> V_22 ) , V_46 -> V_65 ,
V_46 -> V_50 ) )
return - V_32 ;
if ( V_27 -> V_22 . V_66 + sizeof( V_27 -> V_20 . V_15 ) >
V_46 -> V_50 )
return - V_55 ;
V_15 = ( ( unsigned char * ) & V_27 -> V_22 ) + V_27 -> V_22 . V_66 ;
memcpy ( V_27 -> V_20 . V_15 , V_15 ,
sizeof( V_27 -> V_20 . V_15 ) ) ;
* V_47 = ( V_27 -> V_20 . V_15 [ 0 ] << 8 ) | V_27 -> V_20 . V_15 [ 1 ] ;
* V_48 = ( unsigned short * ) & V_27 -> V_22 . V_37 ;
if ( memcmp ( V_15 , L_1 , 2 ) == 0 )
V_8 -> V_67 = 1 ;
else
V_8 -> V_67 = 0 ;
if ( V_46 -> V_56 &&
F_4 ( V_54 , V_46 -> V_68 ,
V_46 -> V_56 ) )
return - V_32 ;
return 0 ;
}
static int F_11 ( struct V_7 * V_8 ,
struct V_69 * V_46 ,
unsigned int * V_47 )
{
unsigned int V_70 ;
static struct V_11 V_71 = {
. type = 0x06 ,
. V_72 = { 0x00 , 0x01 } ,
. V_15 = { 0x00 , 0x00 } ,
. V_14 [ 0 ] = 0x58 ,
. V_14 [ 1 ] = 0x43 ,
. V_13 = 0x00000058 ,
} ;
struct {
struct V_11 V_20 ;
struct V_73 V_22 ;
unsigned char V_74 ;
unsigned char V_75 ;
} V_26 * V_27 = V_8 -> V_28 ;
struct V_76 {
unsigned char V_77 ;
unsigned char V_78 ;
unsigned int V_79 ;
unsigned char V_80 ;
unsigned char V_81 ;
unsigned int V_82 ;
} V_26 * V_83 = NULL ;
if ( F_10 ( V_46 -> V_84 ) < V_46 -> V_84 )
return - V_55 ;
V_8 -> V_24 = sizeof( struct V_11 ) + V_46 -> V_84 ;
if ( F_10 ( V_46 -> V_84 ) > V_57 -
( sizeof( struct V_11 ) ) )
return - V_55 ;
if ( F_10 ( V_46 -> V_85 ) < V_46 -> V_85 )
return - V_55 ;
if ( F_10 ( V_46 -> V_85 ) > V_57 -
( sizeof( struct V_59 ) ) )
return - V_55 ;
V_27 -> V_20 = V_71 ;
V_27 -> V_20 . V_33 = V_46 -> V_84 ;
V_27 -> V_20 . V_34 = V_46 -> V_85 ;
if ( F_4 ( & ( V_27 -> V_22 . V_66 ) ,
( char V_86 V_87 * ) V_46 -> V_88 , V_46 -> V_84 ) ) {
return - V_32 ;
}
if ( ( V_27 -> V_75 & 0x80 ) == 0x80 ) {
switch ( V_27 -> V_75 & 0x03 ) {
case 1 :
V_70 = 2 ;
break;
case 2 :
V_70 = 3 ;
break;
default:
return - V_55 ;
}
} else {
V_70 = 1 ;
}
V_83 = (struct V_76 * ) ( ( & ( V_27 -> V_75 ) ) + V_70 ) ;
* V_47 = V_83 -> V_79 & 0xFFFF ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 ,
struct V_7 * V_89 ,
char V_87 * V_90 ,
unsigned int V_91 )
{
static unsigned char V_92 [] = {
0x00 , 0x02 ,
0x1B , 0x7B , 0x5D , 0xB5 , 0x75 , 0x01 , 0x3D , 0xFD ,
0x8D , 0xD1 , 0xC7 , 0x03 , 0x2D , 0x09 , 0x23 , 0x57 ,
0x89 , 0x49 , 0xB9 , 0x3F , 0xBB , 0x99 , 0x41 , 0x5B ,
0x75 , 0x21 , 0x7B , 0x9D , 0x3B , 0x6B , 0x51 , 0x39 ,
0xBB , 0x0D , 0x35 , 0xB9 , 0x89 , 0x0F , 0x93 , 0xA5 ,
0x0B , 0x47 , 0xF1 , 0xD3 , 0xBB , 0xCB , 0xF1 , 0x9D ,
0x23 , 0x73 , 0x71 , 0xFF , 0xF3 , 0xF5 , 0x45 , 0xFB ,
0x61 , 0x29 , 0x23 , 0xFD , 0xF1 , 0x29 , 0x3F , 0x7F ,
0x17 , 0xB7 , 0x1B , 0xA9 , 0x19 , 0xBD , 0x57 , 0xA9 ,
0xD7 , 0x95 , 0xA3 , 0xCB , 0xED , 0x1D , 0xDB , 0x45 ,
0x7D , 0x11 , 0xD1 , 0x51 , 0x1B , 0xED , 0x71 , 0xE9 ,
0xB1 , 0xD1 , 0xAB , 0xAB , 0x21 , 0x2B , 0x1B , 0x9F ,
0x3B , 0x9F , 0xF7 , 0xF7 , 0xBD , 0x63 , 0xEB , 0xAD ,
0xDF , 0xB3 , 0x6F , 0x5B , 0xDB , 0x8D , 0xA9 , 0x5D ,
0xE3 , 0x7D , 0x77 , 0x49 , 0x47 , 0xF5 , 0xA7 , 0xFD ,
0xAB , 0x2F , 0x27 , 0x35 , 0x77 , 0xD3 , 0x49 , 0xC9 ,
0x09 , 0xEB , 0xB1 , 0xF9 , 0xBF , 0x4B , 0xCB , 0x2B ,
0xEB , 0xEB , 0x05 , 0xFF , 0x7D , 0xC7 , 0x91 , 0x8B ,
0x09 , 0x83 , 0xB9 , 0xB9 , 0x69 , 0x33 , 0x39 , 0x6B ,
0x79 , 0x75 , 0x19 , 0xBF , 0xBB , 0x07 , 0x1D , 0xBD ,
0x29 , 0xBF , 0x39 , 0x95 , 0x93 , 0x1D , 0x35 , 0xC7 ,
0xC9 , 0x4D , 0xE5 , 0x97 , 0x0B , 0x43 , 0x9B , 0xF1 ,
0x16 , 0x93 , 0x03 , 0x1F , 0xA5 , 0xFB , 0xDB , 0xF3 ,
0x27 , 0x4F , 0x27 , 0x61 , 0x05 , 0x1F , 0xB9 , 0x23 ,
0x2F , 0xC3 , 0x81 , 0xA9 , 0x23 , 0x71 , 0x55 , 0x55 ,
0xEB , 0xED , 0x41 , 0xE5 , 0xF3 , 0x11 , 0xF1 , 0x43 ,
0x69 , 0x03 , 0xBD , 0x0B , 0x37 , 0x0F , 0x51 , 0x8F ,
0x0B , 0xB5 , 0x89 , 0x5B , 0x67 , 0xA9 , 0xD9 , 0x4F ,
0x01 , 0xF9 , 0x21 , 0x77 , 0x37 , 0x73 , 0x79 , 0xC5 ,
0x7F , 0x51 , 0xC1 , 0xCF , 0x97 , 0xA1 , 0x75 , 0xAD ,
0x35 , 0x9D , 0xD3 , 0xD3 , 0xA7 , 0x9D , 0x5D , 0x41 ,
0x6F , 0x65 , 0x1B , 0xCF , 0xA9 , 0x87 , 0x91 , 0x09
} ;
struct V_93 * V_27 = V_89 -> V_28 ;
unsigned short V_94 , V_95 ;
unsigned int V_96 , V_97 ;
char * V_98 ;
V_94 = V_27 -> V_22 . V_99 ;
if ( F_13 ( V_94 != 0 ) ) {
V_95 = V_27 -> V_22 . V_100 ;
if ( ( V_94 == 8 && V_95 == 66 ) ||
( V_94 == 8 && V_95 == 65 ) ||
( V_94 == 8 && V_95 == 72 ) ||
( V_94 == 8 && V_95 == 770 ) ||
( V_94 == 12 && V_95 == 769 ) ) {
F_14 ( V_101 ,
L_2 ,
F_15 ( V_6 -> V_38 -> V_39 ) ,
F_6 ( V_6 -> V_38 -> V_39 ) ,
( int ) V_94 , ( int ) V_95 ) ;
return - V_55 ;
}
if ( V_94 == 8 && V_95 == 783 ) {
V_6 -> V_102 -> V_103 =
V_104 ;
F_14 ( V_101 ,
L_3 ,
F_15 ( V_6 -> V_38 -> V_39 ) ,
F_6 ( V_6 -> V_38 -> V_39 ) ,
( int ) V_94 , ( int ) V_95 ) ;
return - V_105 ;
}
V_6 -> V_106 = 0 ;
F_16 ( L_4 ,
F_15 ( V_6 -> V_38 -> V_39 ) ,
F_6 ( V_6 -> V_38 -> V_39 ) ) ;
F_14 ( V_107 ,
L_5 ,
F_15 ( V_6 -> V_38 -> V_39 ) ,
F_6 ( V_6 -> V_38 -> V_39 ) ,
( int ) V_94 , ( int ) V_95 ) ;
return - V_105 ;
}
V_98 = V_27 -> V_25 ;
V_96 = V_27 -> V_24 - 2 ;
if ( V_96 > V_91 )
return - V_55 ;
V_97 = V_91 - V_96 ;
if ( V_97 > 0 ) {
if ( V_97 < 10 )
return - V_55 ;
if ( F_17 ( V_90 , V_92 , V_97 - 1 ) )
return - V_32 ;
if ( F_18 ( 0 , V_90 + V_97 - 1 ) )
return - V_32 ;
}
if ( F_17 ( V_90 + V_97 , V_98 , V_96 ) )
return - V_32 ;
return 0 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_7 * V_89 ,
struct V_45 * V_46 )
{
struct V_59 * V_27 = V_89 -> V_28 ;
char * V_98 = V_89 -> V_28 ;
if ( F_17 ( V_46 -> V_108 ,
V_98 + V_27 -> V_109 . V_13 , V_27 -> V_109 . V_110 ) )
return - V_32 ;
V_46 -> V_58 = V_27 -> V_109 . V_110 ;
if ( V_27 -> V_109 . V_111 )
if ( F_17 ( V_46 -> V_112 ,
V_98 + V_27 -> V_109 . V_62 , V_27 -> V_109 . V_111 ) )
return - V_32 ;
V_46 -> V_60 = V_27 -> V_109 . V_111 ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_7 * V_89 ,
struct V_69 * V_46 )
{
struct V_59 * V_27 = V_89 -> V_28 ;
char * V_98 = V_89 -> V_28 ;
if ( V_46 -> V_85 < V_27 -> V_109 . V_110 )
return - V_55 ;
if ( F_17 ( ( char V_86 V_87 * ) V_46 -> V_113 ,
V_98 + V_27 -> V_109 . V_13 , V_27 -> V_109 . V_110 ) )
return - V_32 ;
V_46 -> V_85 = V_27 -> V_109 . V_110 ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_7 * V_89 ,
char * V_114 )
{
struct {
struct V_115 V_20 ;
struct V_116 V_109 ;
struct V_21 V_22 ;
} V_26 * V_27 = V_89 -> V_28 ;
char * V_98 = V_89 -> V_28 ;
if ( V_27 -> V_22 . V_99 != 0 || V_27 -> V_22 . V_100 != 0 )
return - V_55 ;
memcpy ( V_114 , V_98 + V_27 -> V_109 . V_62 , V_27 -> V_109 . V_111 ) ;
return V_27 -> V_109 . V_111 ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_7 * V_89 ,
char V_87 * V_90 ,
unsigned int V_91 )
{
struct V_93 * V_27 = V_89 -> V_28 ;
switch ( V_27 -> V_20 . type ) {
case V_117 :
case V_118 :
return F_23 ( V_6 , V_89 ) ;
case V_119 :
if ( V_27 -> V_22 . V_99 &&
( V_27 -> V_22 . V_100 == 0x14f ) &&
( V_91 > 256 ) ) {
if ( V_6 -> V_102 -> V_120 <= 17 ) {
V_6 -> V_102 -> V_120 = 17 ;
return - V_105 ;
} else
return - V_55 ;
}
if ( V_27 -> V_20 . V_121 )
return F_23 ( V_6 , V_89 ) ;
if ( V_27 -> V_22 . V_122 == 0x02 )
return F_12 ( V_6 , V_89 ,
V_90 , V_91 ) ;
default:
V_6 -> V_106 = 0 ;
F_16 ( L_4 ,
F_15 ( V_6 -> V_38 -> V_39 ) ,
F_6 ( V_6 -> V_38 -> V_39 ) ) ;
F_14 ( V_107 ,
L_6 ,
F_15 ( V_6 -> V_38 -> V_39 ) ,
F_6 ( V_6 -> V_38 -> V_39 ) ,
( int ) V_27 -> V_20 . type ) ;
return - V_105 ;
}
}
static int F_24 ( struct V_5 * V_6 ,
struct V_7 * V_89 ,
struct V_45 * V_46 )
{
struct V_93 * V_27 = V_89 -> V_28 ;
switch ( V_27 -> V_20 . type ) {
case V_117 :
case V_118 :
V_46 -> V_123 = 0x0008044DL ;
return F_23 ( V_6 , V_89 ) ;
case V_119 :
if ( V_27 -> V_20 . V_121 ) {
memcpy ( & ( V_46 -> V_123 ) , V_27 -> V_109 . V_124 , sizeof( V_125 ) ) ;
return F_23 ( V_6 , V_89 ) ;
}
if ( V_27 -> V_22 . V_122 == 0x02 )
return F_19 ( V_6 , V_89 , V_46 ) ;
default:
V_46 -> V_123 = 0x0008044DL ;
V_6 -> V_106 = 0 ;
F_16 ( L_4 ,
F_15 ( V_6 -> V_38 -> V_39 ) ,
F_6 ( V_6 -> V_38 -> V_39 ) ) ;
F_14 ( V_107 ,
L_6 ,
F_15 ( V_6 -> V_38 -> V_39 ) ,
F_6 ( V_6 -> V_38 -> V_39 ) ,
( int ) V_27 -> V_20 . type ) ;
return - V_105 ;
}
}
static int F_25 ( struct V_5 * V_6 ,
struct V_7 * V_89 , struct V_69 * V_46 )
{
struct V_126 * V_27 = V_89 -> V_28 ;
switch ( V_27 -> V_20 . type ) {
case V_117 :
case V_127 :
return F_23 ( V_6 , V_89 ) ;
case V_119 :
if ( V_27 -> V_20 . V_121 )
return F_23 ( V_6 , V_89 ) ;
if ( V_27 -> V_22 . V_122 == 0x04 )
return F_20 ( V_6 , V_89 , V_46 ) ;
default:
V_6 -> V_106 = 0 ;
F_16 ( L_4 ,
F_15 ( V_6 -> V_38 -> V_39 ) ,
F_6 ( V_6 -> V_38 -> V_39 ) ) ;
F_14 ( V_107 ,
L_6 ,
F_15 ( V_6 -> V_38 -> V_39 ) ,
F_6 ( V_6 -> V_38 -> V_39 ) ,
( int ) V_27 -> V_20 . type ) ;
return - V_105 ;
}
}
static int F_26 ( struct V_5 * V_6 ,
struct V_7 * V_89 ,
char * V_98 )
{
struct V_93 * V_27 = V_89 -> V_28 ;
switch ( V_27 -> V_20 . type ) {
case V_117 :
case V_118 :
return - V_55 ;
case V_119 :
if ( V_27 -> V_20 . V_121 )
return - V_55 ;
if ( V_27 -> V_22 . V_122 == 0x02 )
return F_21 ( V_6 , V_89 , V_98 ) ;
default:
V_6 -> V_106 = 0 ;
F_16 ( L_4 ,
F_15 ( V_6 -> V_38 -> V_39 ) ,
F_6 ( V_6 -> V_38 -> V_39 ) ) ;
F_14 ( V_107 ,
L_6 ,
F_15 ( V_6 -> V_38 -> V_39 ) ,
F_6 ( V_6 -> V_38 -> V_39 ) ,
( int ) V_27 -> V_20 . type ) ;
return - V_105 ;
}
}
static void F_27 ( struct V_128 * V_129 ,
struct V_7 * V_27 ,
struct V_7 * V_89 )
{
static struct V_130 V_131 = {
. type = V_117 ,
. V_121 = V_132 ,
} ;
struct V_133 * V_134 =
(struct V_133 * ) V_27 -> V_135 ;
struct V_93 * V_136 ;
int V_24 ;
if ( ! V_89 )
goto V_137;
V_136 = V_89 -> V_28 ;
if ( V_136 -> V_20 . type == V_119 &&
V_136 -> V_22 . V_122 == 0x02 ) {
switch ( V_134 -> type ) {
case V_138 :
V_24 = sizeof( struct V_93 )
+ V_136 -> V_24 - 2 ;
V_24 = F_28 ( V_35 , V_24 ) ;
memcpy ( V_27 -> V_28 , V_89 -> V_28 , V_24 ) ;
break;
case V_139 :
V_24 = V_136 -> V_109 . V_62 + V_136 -> V_109 . V_111 ;
V_24 = F_28 ( V_57 , V_24 ) ;
memcpy ( V_27 -> V_28 , V_89 -> V_28 , V_24 ) ;
break;
default:
memcpy ( V_27 -> V_28 , & V_131 ,
sizeof( V_131 ) ) ;
}
} else
memcpy ( V_27 -> V_28 , V_89 -> V_28 , sizeof( V_131 ) ) ;
V_137:
F_29 ( & ( V_134 -> V_140 ) ) ;
}
static void F_30 ( struct V_128 * V_129 ,
struct V_7 * V_27 ,
struct V_7 * V_89 )
{
static struct V_130 V_131 = {
. type = V_117 ,
. V_121 = V_132 ,
} ;
struct V_133 * V_134 =
(struct V_133 * ) V_27 -> V_135 ;
struct V_126 * V_136 ;
int V_24 ;
if ( ! V_89 )
goto V_137;
V_136 = V_89 -> V_28 ;
if ( V_136 -> V_20 . type == V_119 &&
V_136 -> V_22 . V_122 == 0x04 ) {
switch ( V_134 -> type ) {
case V_141 :
V_24 = V_136 -> V_109 . V_13 + V_136 -> V_109 . V_110 ;
V_24 = F_28 ( V_57 , V_24 ) ;
memcpy ( V_27 -> V_28 , V_89 -> V_28 , V_24 ) ;
break;
default:
memcpy ( V_27 -> V_28 , & V_131 , sizeof( V_131 ) ) ;
}
} else {
memcpy ( V_27 -> V_28 , V_89 -> V_28 , sizeof( V_131 ) ) ;
}
V_137:
F_29 ( & ( V_134 -> V_140 ) ) ;
}
static long F_31 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
struct V_7 V_8 ;
struct V_133 V_134 = {
. type = V_138 ,
} ;
int V_142 ;
F_32 ( & V_8 ) ;
V_8 . V_28 = ( void * ) F_33 ( V_143 ) ;
if ( ! V_8 . V_28 )
return - V_144 ;
V_8 . V_145 = F_27 ;
V_8 . V_146 = ( ( ( unsigned long long ) V_147 -> V_148 ) << 32 ) +
F_34 ( & V_149 ) ;
V_8 . V_135 = & V_134 ;
V_142 = F_3 ( V_6 , & V_8 , V_10 ) ;
if ( V_142 )
goto V_150;
F_35 ( & V_134 . V_140 ) ;
F_36 ( V_6 -> V_38 , & V_8 ) ;
V_142 = F_37 ( & V_134 . V_140 ) ;
if ( V_142 == 0 ) {
V_142 = V_8 . V_142 ;
if ( V_142 == 0 )
V_142 = F_22 ( V_6 , & V_8 ,
V_10 -> V_90 ,
V_10 -> V_91 ) ;
} else
F_38 ( V_6 -> V_38 , & V_8 ) ;
V_150:
F_39 ( ( unsigned long ) V_8 . V_28 ) ;
return V_142 ;
}
static long F_40 ( struct V_5 * V_6 ,
struct V_42 * V_43 )
{
struct V_7 V_8 ;
struct V_133 V_134 = {
. type = V_138 ,
} ;
int V_142 ;
F_32 ( & V_8 ) ;
V_8 . V_28 = ( void * ) F_33 ( V_143 ) ;
if ( ! V_8 . V_28 )
return - V_144 ;
V_8 . V_145 = F_27 ;
V_8 . V_146 = ( ( ( unsigned long long ) V_147 -> V_148 ) << 32 ) +
F_34 ( & V_149 ) ;
V_8 . V_135 = & V_134 ;
V_142 = F_7 ( V_6 , & V_8 , V_43 ) ;
if ( V_142 )
goto V_150;
F_35 ( & V_134 . V_140 ) ;
F_36 ( V_6 -> V_38 , & V_8 ) ;
V_142 = F_37 ( & V_134 . V_140 ) ;
if ( V_142 == 0 ) {
V_142 = V_8 . V_142 ;
if ( V_142 == 0 )
V_142 = F_22 ( V_6 , & V_8 ,
V_43 -> V_90 ,
V_43 -> V_91 ) ;
} else {
F_38 ( V_6 -> V_38 , & V_8 ) ;
}
V_150:
F_39 ( ( unsigned long ) V_8 . V_28 ) ;
return V_142 ;
}
unsigned int F_41 ( struct V_45 * V_46 ,
struct V_7 * V_8 ,
unsigned int * V_151 , unsigned short * * V_48 )
{
struct V_133 V_134 = {
. type = V_139 ,
} ;
int V_142 ;
F_32 ( V_8 ) ;
V_8 -> V_28 = F_42 ( V_57 , V_143 ) ;
if ( ! V_8 -> V_28 )
return - V_144 ;
V_8 -> V_145 = F_27 ;
V_8 -> V_146 = ( ( ( unsigned long long ) V_147 -> V_148 ) << 32 ) +
F_34 ( & V_149 ) ;
V_8 -> V_135 = F_42 ( sizeof( V_134 ) , V_143 ) ;
if ( ! V_8 -> V_135 ) {
F_43 ( V_8 -> V_28 ) ;
return - V_144 ;
}
memcpy ( V_8 -> V_135 , & V_134 , sizeof( V_134 ) ) ;
V_142 = F_9 ( V_8 , V_46 , V_151 , V_48 ) ;
if ( V_142 ) {
F_43 ( V_8 -> V_28 ) ;
F_43 ( V_8 -> V_135 ) ;
}
return V_142 ;
}
static long F_44 ( struct V_5 * V_6 ,
struct V_45 * V_46 ,
struct V_7 * V_8 )
{
int V_142 ;
struct V_133 * V_152 = (struct V_133 * ) ( V_8 -> V_135 ) ;
F_35 ( & V_152 -> V_140 ) ;
F_36 ( V_6 -> V_38 , V_8 ) ;
V_142 = F_37 ( & V_152 -> V_140 ) ;
if ( V_142 == 0 ) {
V_142 = V_8 -> V_142 ;
if ( V_142 == 0 )
V_142 = F_24 ( V_6 , V_8 , V_46 ) ;
} else
F_38 ( V_6 -> V_38 , V_8 ) ;
F_43 ( V_8 -> V_28 ) ;
F_43 ( V_8 -> V_135 ) ;
return V_142 ;
}
unsigned int F_45 ( struct V_69 * V_153 ,
struct V_7 * V_8 ,
unsigned int * V_151 )
{
struct V_133 V_134 = {
. type = V_141 ,
} ;
int V_142 ;
F_32 ( V_8 ) ;
V_8 -> V_28 = F_42 ( V_57 , V_143 ) ;
if ( ! V_8 -> V_28 )
return - V_144 ;
V_8 -> V_145 = F_30 ;
V_8 -> V_146 = ( ( ( unsigned long long ) V_147 -> V_148 ) << 32 ) +
F_34 ( & V_149 ) ;
V_8 -> V_135 = F_42 ( sizeof( V_134 ) , V_143 ) ;
if ( ! V_8 -> V_135 ) {
F_43 ( V_8 -> V_28 ) ;
return - V_144 ;
}
memcpy ( V_8 -> V_135 , & V_134 , sizeof( V_134 ) ) ;
V_142 = F_11 ( V_8 , V_153 , V_151 ) ;
if ( V_142 ) {
F_43 ( V_8 -> V_28 ) ;
F_43 ( V_8 -> V_135 ) ;
}
return V_142 ;
}
static long F_46 ( struct V_5 * V_6 ,
struct V_69 * V_153 ,
struct V_7 * V_8 )
{
int V_142 ;
unsigned int V_70 ;
struct V_133 * V_152 = (struct V_133 * ) ( V_8 -> V_135 ) ;
struct {
struct V_11 V_20 ;
struct V_73 V_22 ;
unsigned char V_74 ;
unsigned char V_75 ;
} V_26 * V_27 = V_8 -> V_28 ;
struct V_76 {
unsigned char V_77 ;
unsigned char V_78 ;
unsigned int V_79 ;
unsigned char V_80 ;
unsigned char V_81 ;
unsigned int V_82 ;
} V_26 * V_83 = NULL ;
if ( ! ( ( V_27 -> V_22 . V_154 & 0x80 ) == 0x80 ) ) {
V_27 -> V_22 . V_155 = ( unsigned int )
F_6 ( V_6 -> V_38 -> V_39 ) ;
if ( ( V_27 -> V_75 & 0x80 ) == 0x80 ) {
switch ( V_27 -> V_75 & 0x03 ) {
case 1 :
V_70 = 2 ;
break;
case 2 :
V_70 = 3 ;
break;
default:
return - V_55 ;
}
} else {
V_70 = 1 ;
}
V_83 = (struct V_76 * ) ( ( & ( V_27 -> V_75 ) ) + V_70 ) ;
V_83 -> V_82 = ( unsigned int )
F_6 ( V_6 -> V_38 -> V_39 ) ;
}
F_35 ( & V_152 -> V_140 ) ;
F_36 ( V_6 -> V_38 , V_8 ) ;
V_142 = F_37 ( & V_152 -> V_140 ) ;
if ( V_142 == 0 ) {
V_142 = V_8 -> V_142 ;
if ( V_142 == 0 )
V_142 = F_25 ( V_6 , V_8 , V_153 ) ;
} else
F_38 ( V_6 -> V_38 , V_8 ) ;
F_43 ( V_8 -> V_28 ) ;
F_43 ( V_8 -> V_135 ) ;
return V_142 ;
}
unsigned int F_47 ( struct V_7 * V_8 , int * V_151 ,
unsigned int * V_37 )
{
struct V_133 V_134 = {
. type = V_139 ,
} ;
F_32 ( V_8 ) ;
V_8 -> V_28 = F_42 ( V_57 , V_143 ) ;
if ( ! V_8 -> V_28 )
return - V_144 ;
V_8 -> V_145 = F_27 ;
V_8 -> V_146 = ( ( ( unsigned long long ) V_147 -> V_148 ) << 32 ) +
F_34 ( & V_149 ) ;
V_8 -> V_135 = F_42 ( sizeof( V_134 ) , V_143 ) ;
if ( ! V_8 -> V_135 ) {
F_43 ( V_8 -> V_28 ) ;
return - V_144 ;
}
memcpy ( V_8 -> V_135 , & V_134 , sizeof( V_134 ) ) ;
F_48 ( V_8 , V_156 , V_37 ) ;
* V_151 = V_157 ;
return 0 ;
}
static long F_49 ( struct V_5 * V_6 ,
char * V_114 , struct V_7 * V_8 )
{
struct {
struct V_11 V_20 ;
struct V_21 V_22 ;
char V_15 [ 2 ] ;
short int V_158 ;
char V_159 [ 8 ] ;
short int V_160 ;
short int V_161 ;
} V_26 * V_27 = V_8 -> V_28 ;
struct V_133 * V_152 = (struct V_133 * ) ( V_8 -> V_135 ) ;
int V_142 ;
V_27 -> V_22 . V_37 = F_6 ( V_6 -> V_38 -> V_39 ) ;
F_35 ( & V_152 -> V_140 ) ;
F_36 ( V_6 -> V_38 , V_8 ) ;
V_142 = F_37 ( & V_152 -> V_140 ) ;
if ( V_142 == 0 ) {
V_142 = V_8 -> V_142 ;
if ( V_142 == 0 )
V_142 = F_26 ( V_6 , V_8 , V_114 ) ;
} else
F_38 ( V_6 -> V_38 , V_8 ) ;
F_43 ( V_8 -> V_28 ) ;
F_43 ( V_8 -> V_135 ) ;
return V_142 ;
}
void T_1 F_50 ( void )
{
F_51 ( & V_162 ) ;
F_51 ( & V_163 ) ;
F_51 ( & V_164 ) ;
}
void T_2 F_52 ( void )
{
F_53 ( & V_162 ) ;
F_53 ( & V_163 ) ;
F_53 ( & V_164 ) ;
}
