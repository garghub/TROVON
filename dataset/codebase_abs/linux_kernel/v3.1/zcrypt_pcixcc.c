static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
static struct V_7 V_8 = {
. type = 0x06 ,
. V_9 = 0x00000058 ,
. V_10 = { 'C' , 'A' ,} ,
. V_11 = { 'P' , 'K' } ,
} ;
static struct V_12 V_13 = {
. V_11 = { 'P' , 'K' } ,
. V_14 = 10 ,
. V_15 = { 'M' , 'R' , 'P' , ' ' , ' ' , ' ' , ' ' , ' ' }
} ;
static struct V_12 V_16 = {
. V_11 = { 'P' , 'K' } ,
. V_14 = 10 ,
. V_15 = { 'Z' , 'E' , 'R' , 'O' , '-' , 'P' , 'A' , 'D' }
} ;
struct {
struct V_7 V_17 ;
struct V_18 V_19 ;
struct V_12 V_20 ;
unsigned short V_21 ;
char V_22 [ 0 ] ;
} V_23 ( ( V_24 ) ) * V_25 = V_4 -> V_26 ;
int V_27 ;
V_25 -> V_21 = V_6 -> V_28 + 2 ;
if ( F_2 ( V_25 -> V_22 , V_6 -> V_29 , V_6 -> V_28 ) )
return - V_30 ;
V_27 = F_3 ( V_6 , V_25 -> V_22 + V_6 -> V_28 , 1 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 += sizeof( * V_25 ) + V_6 -> V_28 ;
V_25 -> V_17 = V_8 ;
V_25 -> V_17 . V_31 = V_27 - sizeof( V_25 -> V_17 ) ;
V_25 -> V_17 . V_32 = V_33 - sizeof( V_25 -> V_17 ) ;
V_25 -> V_19 = V_34 ;
V_25 -> V_19 . V_35 = F_4 ( V_2 -> V_36 -> V_37 ) ;
V_25 -> V_19 . V_38 = V_25 -> V_17 . V_32 ;
V_25 -> V_20 = ( V_2 -> V_39 == V_40 ) ?
V_16 : V_13 ;
V_25 -> V_19 . V_41 = V_27 - sizeof( V_25 -> V_17 ) - sizeof( V_25 -> V_19 ) ;
V_4 -> V_21 = V_27 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 )
{
static struct V_7 V_8 = {
. type = 0x06 ,
. V_9 = 0x00000058 ,
. V_10 = { 'C' , 'A' ,} ,
. V_11 = { 'P' , 'D' } ,
} ;
static struct V_12 V_44 = {
. V_11 = { 'P' , 'D' } ,
. V_14 = 10 ,
. V_15 = { 'Z' , 'E' , 'R' , 'O' , '-' , 'P' , 'A' , 'D' }
} ;
static struct V_12 V_45 = {
. V_11 = { 'P' , 'D' } ,
. V_14 = 10 ,
. V_15 = { 'P' , 'K' , 'C' , 'S' , '-' , '1' , '.' , '2' }
} ;
struct {
struct V_7 V_17 ;
struct V_18 V_19 ;
struct V_12 V_20 ;
unsigned short V_21 ;
char V_22 [ 0 ] ;
} V_23 ( ( V_24 ) ) * V_25 = V_4 -> V_26 ;
int V_27 ;
V_25 -> V_21 = V_43 -> V_28 + 2 ;
if ( F_2 ( V_25 -> V_22 , V_43 -> V_29 , V_43 -> V_28 ) )
return - V_30 ;
V_27 = F_6 ( V_43 , V_25 -> V_22 + V_43 -> V_28 , 1 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 += sizeof( * V_25 ) + V_43 -> V_28 ;
V_25 -> V_17 = V_8 ;
V_25 -> V_17 . V_31 = V_27 - sizeof( V_25 -> V_17 ) ;
V_25 -> V_17 . V_32 = V_33 - sizeof( V_25 -> V_17 ) ;
V_25 -> V_19 = V_34 ;
V_25 -> V_19 . V_35 = F_4 ( V_2 -> V_36 -> V_37 ) ;
V_25 -> V_19 . V_41 = V_25 -> V_19 . V_38 =
V_27 - sizeof( V_25 -> V_17 ) - sizeof( V_25 -> V_19 ) ;
V_25 -> V_20 = ( V_2 -> V_39 == V_40 ) ?
V_45 : V_44 ;
V_4 -> V_21 = V_27 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_46 * V_47 )
{
static struct V_7 V_8 = {
. type = 0x06 ,
. V_9 = 0x00000058 ,
} ;
struct {
struct V_7 V_17 ;
struct V_18 V_19 ;
} V_23 ( ( V_24 ) ) * V_25 = V_4 -> V_26 ;
int V_48 = F_8 ( V_47 -> V_49 ) ;
int V_50 ;
char * V_51 = V_4 -> V_26 + sizeof( struct V_7 ) + V_48 ;
char * V_11 ;
V_4 -> V_21 = sizeof( struct V_7 ) +
F_8 ( V_47 -> V_49 ) +
V_47 -> V_52 ;
if ( V_4 -> V_21 > V_53 )
return - V_30 ;
if ( F_8 ( V_47 -> V_54 ) > V_55 )
return - V_30 ;
if ( F_8 ( V_47 -> V_56 ) > V_57 )
return - V_30 ;
V_50 = F_8 ( V_47 -> V_54 ) +
F_8 ( V_47 -> V_56 ) +
sizeof( struct V_58 ) ;
if ( V_50 > V_59 ) {
V_47 -> V_54 = V_59 -
( sizeof( struct V_58 ) +
F_8 ( V_47 -> V_56 ) ) ;
}
V_25 -> V_17 = V_8 ;
memcpy ( V_25 -> V_17 . V_10 , & ( V_47 -> V_60 ) , sizeof( V_47 -> V_60 ) ) ;
V_25 -> V_17 . V_31 = V_47 -> V_49 ;
if ( V_47 -> V_52 ) {
V_25 -> V_17 . V_61 = V_25 -> V_17 . V_9 + V_48 ;
V_25 -> V_17 . V_62 = V_47 -> V_52 ;
}
V_25 -> V_17 . V_32 = V_47 -> V_54 ;
V_25 -> V_17 . V_63 = V_47 -> V_56 ;
if ( F_2 ( & ( V_25 -> V_19 ) , V_47 -> V_64 ,
V_47 -> V_49 ) )
return - V_30 ;
if ( V_25 -> V_19 . V_65 + sizeof( V_25 -> V_17 . V_11 ) >
V_47 -> V_49 )
return - V_30 ;
V_11 = ( ( unsigned char * ) & V_25 -> V_19 ) + V_25 -> V_19 . V_65 ;
memcpy ( V_25 -> V_17 . V_11 , V_11 , sizeof( V_25 -> V_17 . V_11 ) ) ;
if ( memcmp ( V_11 , L_1 , 2 ) == 0 )
V_4 -> V_66 = 1 ;
else
V_4 -> V_66 = 0 ;
if ( V_47 -> V_52 &&
F_2 ( V_51 , V_47 -> V_67 ,
V_47 -> V_52 ) )
return - V_30 ;
return 0 ;
}
static void F_9 ( struct V_68 * V_36 ,
struct V_3 * V_4 ,
unsigned V_69 )
{
struct {
struct V_7 V_17 ;
struct V_18 V_19 ;
char V_11 [ 2 ] ;
short int V_70 ;
char V_71 [ 8 ] ;
short int V_72 ;
short int V_73 ;
} V_23 ( ( V_24 ) ) * V_25 = V_4 -> V_26 ;
static struct V_7 V_8 = {
. type = 0x06 ,
. V_9 = 0x00000058 ,
. V_10 = { 'C' , 'A' } ,
. V_11 = { 'R' , 'L' } ,
. V_31 = sizeof *V_25 - sizeof( V_25 -> V_17 ) ,
. V_32 = sizeof *V_25 - sizeof( V_25 -> V_17 ) ,
} ;
static struct V_18 V_74 = {
. V_65 = 0x00dc ,
. V_75 = 0x02 ,
. V_76 = { 0x54 , 0x32 } ,
. V_41 = sizeof *V_25 - sizeof( V_25 -> V_17 ) -
sizeof( V_25 -> V_19 ) ,
. V_38 = sizeof *V_25 - sizeof( V_25 -> V_17 ) ,
} ;
V_25 -> V_17 = V_8 ;
V_25 -> V_17 . V_63 = V_69 ,
V_25 -> V_19 = V_74 ;
V_25 -> V_19 . V_77 = V_69 ,
V_25 -> V_19 . V_35 = F_4 ( V_36 -> V_37 ) ;
memcpy ( V_25 -> V_11 , V_25 -> V_17 . V_11 , 0x02 ) ;
V_25 -> V_70 = 0x0a ;
memcpy ( V_25 -> V_71 , L_2 , 8 ) ;
V_25 -> V_72 = 0x02 ;
V_25 -> V_73 = 0x02 ;
V_4 -> V_21 = sizeof *V_25 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_78 ,
char T_1 * V_79 ,
unsigned int V_80 )
{
static unsigned char V_81 [] = {
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
struct V_82 * V_25 = V_78 -> V_26 ;
unsigned short V_83 , V_84 ;
unsigned int V_85 , V_86 ;
char * V_87 ;
V_83 = V_25 -> V_19 . V_88 ;
if ( F_11 ( V_83 != 0 ) ) {
V_84 = V_25 -> V_19 . V_89 ;
if ( V_83 == 8 && V_84 == 66 )
return - V_90 ;
if ( V_83 == 8 && V_84 == 65 )
return - V_90 ;
if ( V_83 == 8 && V_84 == 770 )
return - V_90 ;
if ( V_83 == 8 && V_84 == 783 ) {
V_2 -> V_91 = V_92 ;
return - V_93 ;
}
if ( V_83 == 12 && V_84 == 769 )
return - V_90 ;
if ( V_83 == 8 && V_84 == 72 )
return - V_90 ;
V_2 -> V_94 = 0 ;
return - V_93 ;
}
V_87 = V_25 -> V_22 ;
V_85 = V_25 -> V_21 - 2 ;
if ( V_85 > V_80 )
return - V_90 ;
V_86 = V_80 - V_85 ;
if ( V_86 > 0 ) {
if ( V_86 < 10 )
return - V_90 ;
if ( F_12 ( V_79 , V_81 , V_86 - 1 ) )
return - V_30 ;
if ( F_13 ( 0 , V_79 + V_86 - 1 ) )
return - V_30 ;
}
if ( F_12 ( V_79 + V_86 , V_87 , V_85 ) )
return - V_30 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_78 ,
struct V_46 * V_47 )
{
struct V_58 * V_25 = V_78 -> V_26 ;
char * V_87 = V_78 -> V_26 ;
if ( F_12 ( V_47 -> V_95 ,
V_87 + V_25 -> V_96 . V_9 , V_25 -> V_96 . V_97 ) )
return - V_30 ;
V_47 -> V_54 = V_25 -> V_96 . V_97 ;
if ( V_25 -> V_96 . V_98 )
if ( F_12 ( V_47 -> V_99 ,
V_87 + V_25 -> V_96 . V_61 , V_25 -> V_96 . V_98 ) )
return - V_30 ;
V_47 -> V_56 = V_25 -> V_96 . V_98 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_78 ,
char * V_100 )
{
struct {
struct V_101 V_17 ;
struct V_102 V_96 ;
struct V_18 V_19 ;
} V_23 ( ( V_24 ) ) * V_25 = V_78 -> V_26 ;
char * V_87 = V_78 -> V_26 ;
if ( V_25 -> V_19 . V_88 != 0 || V_25 -> V_19 . V_89 != 0 )
return - V_90 ;
memcpy ( V_100 , V_87 + V_25 -> V_96 . V_61 , V_25 -> V_96 . V_98 ) ;
return V_25 -> V_96 . V_98 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_78 ,
char T_1 * V_79 ,
unsigned int V_80 )
{
struct V_82 * V_25 = V_78 -> V_26 ;
switch ( ( ( unsigned char * ) V_78 -> V_26 ) [ 1 ] ) {
case V_103 :
case V_104 :
return F_17 ( V_2 , V_78 ) ;
case V_105 :
if ( V_25 -> V_19 . V_88 &&
( V_25 -> V_19 . V_89 == 0x14f ) &&
( V_80 > 256 ) ) {
if ( V_2 -> V_106 <= 17 ) {
V_2 -> V_106 = 17 ;
return - V_93 ;
} else
return - V_90 ;
}
if ( V_25 -> V_17 . V_107 )
return F_17 ( V_2 , V_78 ) ;
if ( V_25 -> V_19 . V_75 == 0x02 )
return F_10 ( V_2 , V_78 ,
V_79 , V_80 ) ;
default:
V_2 -> V_94 = 0 ;
return - V_93 ;
}
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_78 ,
struct V_46 * V_47 )
{
struct V_82 * V_25 = V_78 -> V_26 ;
switch ( ( ( unsigned char * ) V_78 -> V_26 ) [ 1 ] ) {
case V_103 :
case V_104 :
V_47 -> V_108 = 0x0008044DL ;
return F_17 ( V_2 , V_78 ) ;
case V_105 :
if ( V_25 -> V_17 . V_107 ) {
memcpy ( & ( V_47 -> V_108 ) , V_25 -> V_96 . V_109 , sizeof( V_110 ) ) ;
return F_17 ( V_2 , V_78 ) ;
}
if ( V_25 -> V_19 . V_75 == 0x02 )
return F_14 ( V_2 , V_78 , V_47 ) ;
default:
V_47 -> V_108 = 0x0008044DL ;
V_2 -> V_94 = 0 ;
return - V_93 ;
}
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_78 ,
char * V_87 )
{
struct V_82 * V_25 = V_78 -> V_26 ;
switch ( V_25 -> V_17 . type ) {
case V_103 :
case V_104 :
return - V_90 ;
case V_105 :
if ( V_25 -> V_17 . V_107 )
return - V_90 ;
if ( V_25 -> V_19 . V_75 == 0x02 )
return F_15 ( V_2 , V_78 , V_87 ) ;
default:
V_2 -> V_94 = 0 ;
return - V_93 ;
}
}
static void F_20 ( struct V_68 * V_36 ,
struct V_3 * V_25 ,
struct V_3 * V_78 )
{
static struct V_111 V_112 = {
. type = V_103 ,
. V_107 = V_113 ,
} ;
struct V_114 * V_115 =
(struct V_114 * ) V_25 -> V_116 ;
struct V_82 * V_117 ;
int V_21 ;
if ( F_21 ( V_78 ) ) {
memcpy ( V_25 -> V_26 , & V_112 , sizeof( V_112 ) ) ;
goto V_118;
}
V_117 = V_78 -> V_26 ;
if ( V_117 -> V_17 . type == V_105 &&
V_117 -> V_19 . V_75 == 0x02 ) {
switch ( V_115 -> type ) {
case V_119 :
V_21 = sizeof( struct V_82 )
+ V_117 -> V_21 - 2 ;
V_21 = F_22 ( V_33 , V_21 ) ;
memcpy ( V_25 -> V_26 , V_78 -> V_26 , V_21 ) ;
break;
case V_120 :
V_21 = V_117 -> V_96 . V_61 + V_117 -> V_96 . V_98 ;
V_21 = F_22 ( V_59 , V_21 ) ;
memcpy ( V_25 -> V_26 , V_78 -> V_26 , V_21 ) ;
break;
default:
memcpy ( V_25 -> V_26 , & V_112 , sizeof V_112 ) ;
}
} else
memcpy ( V_25 -> V_26 , V_78 -> V_26 , sizeof V_112 ) ;
V_118:
F_23 ( & ( V_115 -> V_121 ) ) ;
}
static long F_24 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_3 V_4 ;
struct V_114 V_115 = {
. type = V_119 ,
} ;
int V_122 ;
F_25 ( & V_4 ) ;
V_4 . V_26 = ( void * ) F_26 ( V_123 ) ;
if ( ! V_4 . V_26 )
return - V_124 ;
V_4 . V_125 = ( ( ( unsigned long long ) V_126 -> V_127 ) << 32 ) +
F_27 ( & V_128 ) ;
V_4 . V_116 = & V_115 ;
V_122 = F_1 ( V_2 , & V_4 , V_6 ) ;
if ( V_122 )
goto V_129;
F_28 ( & V_115 . V_121 ) ;
F_29 ( V_2 -> V_36 , & V_4 ) ;
V_122 = F_30 ( & V_115 . V_121 ) ;
if ( V_122 == 0 )
V_122 = F_16 ( V_2 , & V_4 , V_6 -> V_79 ,
V_6 -> V_80 ) ;
else
F_31 ( V_2 -> V_36 , & V_4 ) ;
V_129:
F_32 ( ( unsigned long ) V_4 . V_26 ) ;
return V_122 ;
}
static long F_33 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 V_4 ;
struct V_114 V_115 = {
. type = V_119 ,
} ;
int V_122 ;
F_25 ( & V_4 ) ;
V_4 . V_26 = ( void * ) F_26 ( V_123 ) ;
if ( ! V_4 . V_26 )
return - V_124 ;
V_4 . V_125 = ( ( ( unsigned long long ) V_126 -> V_127 ) << 32 ) +
F_27 ( & V_128 ) ;
V_4 . V_116 = & V_115 ;
V_122 = F_5 ( V_2 , & V_4 , V_43 ) ;
if ( V_122 )
goto V_129;
F_28 ( & V_115 . V_121 ) ;
F_29 ( V_2 -> V_36 , & V_4 ) ;
V_122 = F_30 ( & V_115 . V_121 ) ;
if ( V_122 == 0 )
V_122 = F_16 ( V_2 , & V_4 , V_43 -> V_79 ,
V_43 -> V_80 ) ;
else
F_31 ( V_2 -> V_36 , & V_4 ) ;
V_129:
F_32 ( ( unsigned long ) V_4 . V_26 ) ;
return V_122 ;
}
static long F_34 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_3 V_4 ;
struct V_114 V_115 = {
. type = V_120 ,
} ;
int V_122 ;
F_25 ( & V_4 ) ;
V_4 . V_26 = F_35 ( V_53 , V_123 ) ;
if ( ! V_4 . V_26 )
return - V_124 ;
V_4 . V_125 = ( ( ( unsigned long long ) V_126 -> V_127 ) << 32 ) +
F_27 ( & V_128 ) ;
V_4 . V_116 = & V_115 ;
V_122 = F_7 ( V_2 , & V_4 , V_47 ) ;
if ( V_122 )
goto V_129;
F_28 ( & V_115 . V_121 ) ;
F_29 ( V_2 -> V_36 , & V_4 ) ;
V_122 = F_30 ( & V_115 . V_121 ) ;
if ( V_122 == 0 )
V_122 = F_18 ( V_2 , & V_4 , V_47 ) ;
else
F_31 ( V_2 -> V_36 , & V_4 ) ;
V_129:
F_36 ( V_4 . V_26 ) ;
return V_122 ;
}
static long F_37 ( struct V_1 * V_2 ,
char * V_100 )
{
struct V_3 V_4 ;
struct V_114 V_115 = {
. type = V_120 ,
} ;
int V_122 ;
F_25 ( & V_4 ) ;
V_4 . V_26 = F_35 ( V_53 , V_123 ) ;
if ( ! V_4 . V_26 )
return - V_124 ;
V_4 . V_125 = ( ( ( unsigned long long ) V_126 -> V_127 ) << 32 ) +
F_27 ( & V_128 ) ;
V_4 . V_116 = & V_115 ;
F_9 ( V_2 -> V_36 , & V_4 , V_130 ) ;
F_28 ( & V_115 . V_121 ) ;
F_29 ( V_2 -> V_36 , & V_4 ) ;
V_122 = F_30 ( & V_115 . V_121 ) ;
if ( V_122 == 0 )
V_122 = F_19 ( V_2 , & V_4 , V_100 ) ;
else
F_31 ( V_2 -> V_36 , & V_4 ) ;
F_38 ( V_4 . V_26 ) ;
return V_122 ;
}
static int F_39 ( struct V_68 * V_36 )
{
static unsigned char V_25 [] = {
0x00 , 0x06 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x58 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x43 , 0x41 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x50 , 0x4B , 0x00 , 0x00 ,
0x00 , 0x00 , 0x01 , 0xC4 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x07 , 0x24 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0xDC , 0x02 , 0x00 , 0x00 , 0x00 , 0x54 , 0x32 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0xE8 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x07 , 0x24 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x04 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x50 , 0x4B , 0x00 , 0x0A ,
0x4D , 0x52 , 0x50 , 0x20 , 0x20 , 0x20 , 0x20 , 0x20 ,
0x00 , 0x42 , 0x00 , 0x01 , 0x02 , 0x03 , 0x04 , 0x05 ,
0x06 , 0x07 , 0x08 , 0x09 , 0x0A , 0x0B , 0x0C , 0x0D ,
0x0E , 0x0F , 0x00 , 0x11 , 0x22 , 0x33 , 0x44 , 0x55 ,
0x66 , 0x77 , 0x88 , 0x99 , 0xAA , 0xBB , 0xCC , 0xDD ,
0xEE , 0xFF , 0xFF , 0xEE , 0xDD , 0xCC , 0xBB , 0xAA ,
0x99 , 0x88 , 0x77 , 0x66 , 0x55 , 0x44 , 0x33 , 0x22 ,
0x11 , 0x00 , 0x01 , 0x23 , 0x45 , 0x67 , 0x89 , 0xAB ,
0xCD , 0xEF , 0xFE , 0xDC , 0xBA , 0x98 , 0x76 , 0x54 ,
0x32 , 0x10 , 0x00 , 0x9A , 0x00 , 0x98 , 0x00 , 0x00 ,
0x1E , 0x00 , 0x00 , 0x94 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x04 , 0x00 , 0x00 , 0x8C , 0x00 , 0x00 , 0x00 , 0x40 ,
0x02 , 0x00 , 0x00 , 0x40 , 0xBA , 0xE8 , 0x23 , 0x3C ,
0x75 , 0xF3 , 0x91 , 0x61 , 0xD6 , 0x73 , 0x39 , 0xCF ,
0x7B , 0x6D , 0x8E , 0x61 , 0x97 , 0x63 , 0x9E , 0xD9 ,
0x60 , 0x55 , 0xD6 , 0xC7 , 0xEF , 0xF8 , 0x1E , 0x63 ,
0x95 , 0x17 , 0xCC , 0x28 , 0x45 , 0x60 , 0x11 , 0xC5 ,
0xC4 , 0x4E , 0x66 , 0xC6 , 0xE6 , 0xC3 , 0xDE , 0x8A ,
0x19 , 0x30 , 0xCF , 0x0E , 0xD7 , 0xAA , 0xDB , 0x01 ,
0xD8 , 0x00 , 0xBB , 0x8F , 0x39 , 0x9F , 0x64 , 0x28 ,
0xF5 , 0x7A , 0x77 , 0x49 , 0xCC , 0x6B , 0xA3 , 0x91 ,
0x97 , 0x70 , 0xE7 , 0x60 , 0x1E , 0x39 , 0xE1 , 0xE5 ,
0x33 , 0xE1 , 0x15 , 0x63 , 0x69 , 0x08 , 0x80 , 0x4C ,
0x67 , 0xC4 , 0x41 , 0x8F , 0x48 , 0xDF , 0x26 , 0x98 ,
0xF1 , 0xD5 , 0x8D , 0x88 , 0xD9 , 0x6A , 0xA4 , 0x96 ,
0xC5 , 0x84 , 0xD9 , 0x30 , 0x49 , 0x67 , 0x7D , 0x19 ,
0xB1 , 0xB3 , 0x45 , 0x4D , 0xB2 , 0x53 , 0x9A , 0x47 ,
0x3C , 0x7C , 0x55 , 0xBF , 0xCC , 0x85 , 0x00 , 0x36 ,
0xF1 , 0x3D , 0x93 , 0x53
} ;
unsigned long long V_125 ;
struct V_18 * V_19 ;
char * V_78 ;
int V_122 , V_131 ;
V_78 = ( void * ) F_26 ( V_123 ) ;
if ( ! V_78 )
return - V_124 ;
V_122 = F_40 ( V_36 -> V_37 , 0x0102030405060708ULL , V_25 , sizeof( V_25 ) ) ;
if ( V_122 )
goto V_129;
for ( V_131 = 0 ; V_131 < 6 ; V_131 ++ ) {
F_41 ( 300 ) ;
V_122 = F_42 ( V_36 -> V_37 , & V_125 , V_78 , 4096 ) ;
if ( V_122 == 0 && V_125 == 0x0102030405060708ULL )
break;
}
if ( V_131 >= 6 ) {
V_122 = - V_132 ;
goto V_129;
}
V_19 = (struct V_18 * ) ( V_78 + 48 ) ;
if ( V_19 -> V_88 == 8 && V_19 -> V_89 == 33 )
V_122 = V_40 ;
else
V_122 = V_133 ;
V_129:
F_32 ( ( unsigned long ) V_78 ) ;
return V_122 ;
}
static int F_43 ( struct V_68 * V_36 )
{
struct V_3 V_4 ;
unsigned long long V_125 ;
struct {
struct V_101 V_17 ;
struct V_102 V_96 ;
struct V_18 V_19 ;
} V_23 ( ( V_24 ) ) * V_78 ;
int V_122 , V_131 ;
F_25 ( & V_4 ) ;
V_4 . V_26 = ( void * ) F_26 ( V_123 ) ;
if ( ! V_4 . V_26 )
return - V_124 ;
F_9 ( V_36 , & V_4 , 4 ) ;
V_122 = F_40 ( V_36 -> V_37 , 0x0102030405060708ULL , V_4 . V_26 ,
V_4 . V_21 ) ;
if ( V_122 )
goto V_129;
for ( V_131 = 0 ; V_131 < 2 * V_134 ; V_131 ++ ) {
F_44 ( 1000 / V_134 ) ;
V_122 = F_42 ( V_36 -> V_37 , & V_125 , V_4 . V_26 , 4096 ) ;
if ( V_122 == 0 && V_125 == 0x0102030405060708ULL )
break;
}
if ( V_131 >= 2 * V_134 ) {
V_122 = - V_132 ;
goto V_129;
}
V_78 = V_4 . V_26 ;
if ( V_78 -> V_19 . V_88 == 0 && V_78 -> V_19 . V_89 == 0 )
V_122 = 1 ;
else
V_122 = 0 ;
V_129:
F_32 ( ( unsigned long ) V_4 . V_26 ) ;
return V_122 ;
}
static int F_45 ( struct V_68 * V_36 )
{
struct V_1 * V_2 ;
int V_122 = 0 ;
V_2 = F_46 ( V_135 ) ;
if ( ! V_2 )
return - V_124 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_94 = 1 ;
switch ( V_36 -> V_136 ) {
case V_137 :
V_122 = F_39 ( V_36 ) ;
if ( V_122 < 0 ) {
F_47 ( V_2 ) ;
return V_122 ;
}
V_2 -> V_39 = V_122 ;
if ( V_122 == V_40 ) {
V_2 -> V_138 = L_3 ;
V_2 -> V_139 = V_140 ;
V_2 -> V_91 = V_92 ;
V_2 -> V_141 = V_142 ;
V_2 -> V_106 = V_142 ;
} else {
V_2 -> V_138 = L_4 ;
V_2 -> V_139 = V_143 ;
V_2 -> V_91 = V_144 ;
V_2 -> V_141 = V_142 ;
V_2 -> V_106 = V_142 ;
}
break;
case V_145 :
V_2 -> V_39 = V_146 ;
V_2 -> V_138 = L_5 ;
V_2 -> V_139 = V_147 ;
V_2 -> V_91 = V_144 ;
V_2 -> V_141 = V_142 ;
V_2 -> V_106 = V_142 ;
break;
case V_148 :
V_2 -> V_39 = V_149 ;
V_2 -> V_138 = L_6 ;
V_2 -> V_139 = V_150 ;
V_2 -> V_91 = V_151 ;
V_2 -> V_141 = V_152 ;
V_2 -> V_106 = V_152 ;
break;
default:
goto V_129;
}
V_122 = F_43 ( V_36 ) ;
if ( V_122 < 0 ) {
F_47 ( V_2 ) ;
return V_122 ;
}
if ( V_122 )
V_2 -> V_153 = & V_154 ;
else
V_2 -> V_153 = & V_155 ;
V_36 -> V_78 = & V_2 -> V_78 ;
V_36 -> V_116 = V_2 ;
V_122 = F_48 ( V_2 ) ;
if ( V_122 )
goto V_129;
return 0 ;
V_129:
V_36 -> V_116 = NULL ;
F_47 ( V_2 ) ;
return V_122 ;
}
static void F_49 ( struct V_68 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_116 ;
F_50 ( V_2 ) ;
}
int T_2 F_51 ( void )
{
return F_52 ( & V_156 , V_157 , L_7 ) ;
}
void F_53 ( void )
{
F_54 ( & V_156 ) ;
}
