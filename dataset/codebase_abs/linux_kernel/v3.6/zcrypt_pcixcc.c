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
return - V_54 ;
V_50 = sizeof( struct V_55 ) +
F_8 ( V_47 -> V_56 ) +
V_47 -> V_57 ;
if ( V_50 > V_53 )
return - V_54 ;
V_25 -> V_17 = V_8 ;
memcpy ( V_25 -> V_17 . V_10 , & ( V_47 -> V_58 ) , sizeof( V_47 -> V_58 ) ) ;
V_25 -> V_17 . V_31 = V_47 -> V_49 ;
if ( V_47 -> V_52 ) {
V_25 -> V_17 . V_59 = V_25 -> V_17 . V_9 + V_48 ;
V_25 -> V_17 . V_60 = V_47 -> V_52 ;
}
V_25 -> V_17 . V_32 = V_47 -> V_56 ;
V_25 -> V_17 . V_61 = V_47 -> V_57 ;
if ( F_2 ( & ( V_25 -> V_19 ) , V_47 -> V_62 ,
V_47 -> V_49 ) )
return - V_30 ;
if ( V_25 -> V_19 . V_63 + sizeof( V_25 -> V_17 . V_11 ) >
V_47 -> V_49 )
return - V_54 ;
V_11 = ( ( unsigned char * ) & V_25 -> V_19 ) + V_25 -> V_19 . V_63 ;
memcpy ( V_25 -> V_17 . V_11 , V_11 , sizeof( V_25 -> V_17 . V_11 ) ) ;
if ( memcmp ( V_11 , L_1 , 2 ) == 0 )
V_4 -> V_64 = 1 ;
else
V_4 -> V_64 = 0 ;
if ( V_47 -> V_52 &&
F_2 ( V_51 , V_47 -> V_65 ,
V_47 -> V_52 ) )
return - V_30 ;
return 0 ;
}
static void F_9 ( struct V_66 * V_36 ,
struct V_3 * V_4 ,
unsigned V_67 )
{
struct {
struct V_7 V_17 ;
struct V_18 V_19 ;
char V_11 [ 2 ] ;
short int V_68 ;
char V_69 [ 8 ] ;
short int V_70 ;
short int V_71 ;
} V_23 ( ( V_24 ) ) * V_25 = V_4 -> V_26 ;
static struct V_7 V_8 = {
. type = 0x06 ,
. V_9 = 0x00000058 ,
. V_10 = { 'C' , 'A' } ,
. V_11 = { 'R' , 'L' } ,
. V_31 = sizeof *V_25 - sizeof( V_25 -> V_17 ) ,
. V_32 = sizeof *V_25 - sizeof( V_25 -> V_17 ) ,
} ;
static struct V_18 V_72 = {
. V_63 = 0x00dc ,
. V_73 = 0x02 ,
. V_74 = { 0x54 , 0x32 } ,
. V_41 = sizeof *V_25 - sizeof( V_25 -> V_17 ) -
sizeof( V_25 -> V_19 ) ,
. V_38 = sizeof *V_25 - sizeof( V_25 -> V_17 ) ,
} ;
V_25 -> V_17 = V_8 ;
V_25 -> V_17 . V_61 = V_67 ,
V_25 -> V_19 = V_72 ;
V_25 -> V_19 . V_75 = V_67 ,
V_25 -> V_19 . V_35 = F_4 ( V_36 -> V_37 ) ;
memcpy ( V_25 -> V_11 , V_25 -> V_17 . V_11 , 0x02 ) ;
V_25 -> V_68 = 0x0a ;
memcpy ( V_25 -> V_69 , L_2 , 8 ) ;
V_25 -> V_70 = 0x02 ;
V_25 -> V_71 = 0x02 ;
V_4 -> V_21 = sizeof *V_25 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_76 ,
char T_1 * V_77 ,
unsigned int V_78 )
{
static unsigned char V_79 [] = {
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
struct V_80 * V_25 = V_76 -> V_26 ;
unsigned short V_81 , V_82 ;
unsigned int V_83 , V_84 ;
char * V_85 ;
V_81 = V_25 -> V_19 . V_86 ;
if ( F_11 ( V_81 != 0 ) ) {
V_82 = V_25 -> V_19 . V_87 ;
if ( V_81 == 8 && V_82 == 66 )
return - V_54 ;
if ( V_81 == 8 && V_82 == 65 )
return - V_54 ;
if ( V_81 == 8 && V_82 == 770 )
return - V_54 ;
if ( V_81 == 8 && V_82 == 783 ) {
V_2 -> V_88 = V_89 ;
return - V_90 ;
}
if ( V_81 == 12 && V_82 == 769 )
return - V_54 ;
if ( V_81 == 8 && V_82 == 72 )
return - V_54 ;
V_2 -> V_91 = 0 ;
return - V_90 ;
}
V_85 = V_25 -> V_22 ;
V_83 = V_25 -> V_21 - 2 ;
if ( V_83 > V_78 )
return - V_54 ;
V_84 = V_78 - V_83 ;
if ( V_84 > 0 ) {
if ( V_84 < 10 )
return - V_54 ;
if ( F_12 ( V_77 , V_79 , V_84 - 1 ) )
return - V_30 ;
if ( F_13 ( 0 , V_77 + V_84 - 1 ) )
return - V_30 ;
}
if ( F_12 ( V_77 + V_84 , V_85 , V_83 ) )
return - V_30 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_76 ,
struct V_46 * V_47 )
{
struct V_55 * V_25 = V_76 -> V_26 ;
char * V_85 = V_76 -> V_26 ;
if ( F_12 ( V_47 -> V_92 ,
V_85 + V_25 -> V_93 . V_9 , V_25 -> V_93 . V_94 ) )
return - V_30 ;
V_47 -> V_56 = V_25 -> V_93 . V_94 ;
if ( V_25 -> V_93 . V_95 )
if ( F_12 ( V_47 -> V_96 ,
V_85 + V_25 -> V_93 . V_59 , V_25 -> V_93 . V_95 ) )
return - V_30 ;
V_47 -> V_57 = V_25 -> V_93 . V_95 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_76 ,
char * V_97 )
{
struct {
struct V_98 V_17 ;
struct V_99 V_93 ;
struct V_18 V_19 ;
} V_23 ( ( V_24 ) ) * V_25 = V_76 -> V_26 ;
char * V_85 = V_76 -> V_26 ;
if ( V_25 -> V_19 . V_86 != 0 || V_25 -> V_19 . V_87 != 0 )
return - V_54 ;
memcpy ( V_97 , V_85 + V_25 -> V_93 . V_59 , V_25 -> V_93 . V_95 ) ;
return V_25 -> V_93 . V_95 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_76 ,
char T_1 * V_77 ,
unsigned int V_78 )
{
struct V_80 * V_25 = V_76 -> V_26 ;
switch ( ( ( unsigned char * ) V_76 -> V_26 ) [ 1 ] ) {
case V_100 :
case V_101 :
return F_17 ( V_2 , V_76 ) ;
case V_102 :
if ( V_25 -> V_19 . V_86 &&
( V_25 -> V_19 . V_87 == 0x14f ) &&
( V_78 > 256 ) ) {
if ( V_2 -> V_103 <= 17 ) {
V_2 -> V_103 = 17 ;
return - V_90 ;
} else
return - V_54 ;
}
if ( V_25 -> V_17 . V_104 )
return F_17 ( V_2 , V_76 ) ;
if ( V_25 -> V_19 . V_73 == 0x02 )
return F_10 ( V_2 , V_76 ,
V_77 , V_78 ) ;
default:
V_2 -> V_91 = 0 ;
return - V_90 ;
}
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_76 ,
struct V_46 * V_47 )
{
struct V_80 * V_25 = V_76 -> V_26 ;
switch ( ( ( unsigned char * ) V_76 -> V_26 ) [ 1 ] ) {
case V_100 :
case V_101 :
V_47 -> V_105 = 0x0008044DL ;
return F_17 ( V_2 , V_76 ) ;
case V_102 :
if ( V_25 -> V_17 . V_104 ) {
memcpy ( & ( V_47 -> V_105 ) , V_25 -> V_93 . V_106 , sizeof( V_107 ) ) ;
return F_17 ( V_2 , V_76 ) ;
}
if ( V_25 -> V_19 . V_73 == 0x02 )
return F_14 ( V_2 , V_76 , V_47 ) ;
default:
V_47 -> V_105 = 0x0008044DL ;
V_2 -> V_91 = 0 ;
return - V_90 ;
}
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_76 ,
char * V_85 )
{
struct V_80 * V_25 = V_76 -> V_26 ;
switch ( V_25 -> V_17 . type ) {
case V_100 :
case V_101 :
return - V_54 ;
case V_102 :
if ( V_25 -> V_17 . V_104 )
return - V_54 ;
if ( V_25 -> V_19 . V_73 == 0x02 )
return F_15 ( V_2 , V_76 , V_85 ) ;
default:
V_2 -> V_91 = 0 ;
return - V_90 ;
}
}
static void F_20 ( struct V_66 * V_36 ,
struct V_3 * V_25 ,
struct V_3 * V_76 )
{
static struct V_108 V_109 = {
. type = V_100 ,
. V_104 = V_110 ,
} ;
struct V_111 * V_112 =
(struct V_111 * ) V_25 -> V_113 ;
struct V_80 * V_114 ;
int V_21 ;
if ( F_21 ( V_76 ) ) {
memcpy ( V_25 -> V_26 , & V_109 , sizeof( V_109 ) ) ;
goto V_115;
}
V_114 = V_76 -> V_26 ;
if ( V_114 -> V_17 . type == V_102 &&
V_114 -> V_19 . V_73 == 0x02 ) {
switch ( V_112 -> type ) {
case V_116 :
V_21 = sizeof( struct V_80 )
+ V_114 -> V_21 - 2 ;
V_21 = F_22 ( V_33 , V_21 ) ;
memcpy ( V_25 -> V_26 , V_76 -> V_26 , V_21 ) ;
break;
case V_117 :
V_21 = V_114 -> V_93 . V_59 + V_114 -> V_93 . V_95 ;
V_21 = F_22 ( V_53 , V_21 ) ;
memcpy ( V_25 -> V_26 , V_76 -> V_26 , V_21 ) ;
break;
default:
memcpy ( V_25 -> V_26 , & V_109 , sizeof V_109 ) ;
}
} else
memcpy ( V_25 -> V_26 , V_76 -> V_26 , sizeof V_109 ) ;
V_115:
F_23 ( & ( V_112 -> V_118 ) ) ;
}
static long F_24 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_3 V_4 ;
struct V_111 V_112 = {
. type = V_116 ,
} ;
int V_119 ;
F_25 ( & V_4 ) ;
V_4 . V_26 = ( void * ) F_26 ( V_120 ) ;
if ( ! V_4 . V_26 )
return - V_121 ;
V_4 . V_122 = F_20 ;
V_4 . V_123 = ( ( ( unsigned long long ) V_124 -> V_125 ) << 32 ) +
F_27 ( & V_126 ) ;
V_4 . V_113 = & V_112 ;
V_119 = F_1 ( V_2 , & V_4 , V_6 ) ;
if ( V_119 )
goto V_127;
F_28 ( & V_112 . V_118 ) ;
F_29 ( V_2 -> V_36 , & V_4 ) ;
V_119 = F_30 ( & V_112 . V_118 ) ;
if ( V_119 == 0 )
V_119 = F_16 ( V_2 , & V_4 , V_6 -> V_77 ,
V_6 -> V_78 ) ;
else
F_31 ( V_2 -> V_36 , & V_4 ) ;
V_127:
F_32 ( ( unsigned long ) V_4 . V_26 ) ;
return V_119 ;
}
static long F_33 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 V_4 ;
struct V_111 V_112 = {
. type = V_116 ,
} ;
int V_119 ;
F_25 ( & V_4 ) ;
V_4 . V_26 = ( void * ) F_26 ( V_120 ) ;
if ( ! V_4 . V_26 )
return - V_121 ;
V_4 . V_122 = F_20 ;
V_4 . V_123 = ( ( ( unsigned long long ) V_124 -> V_125 ) << 32 ) +
F_27 ( & V_126 ) ;
V_4 . V_113 = & V_112 ;
V_119 = F_5 ( V_2 , & V_4 , V_43 ) ;
if ( V_119 )
goto V_127;
F_28 ( & V_112 . V_118 ) ;
F_29 ( V_2 -> V_36 , & V_4 ) ;
V_119 = F_30 ( & V_112 . V_118 ) ;
if ( V_119 == 0 )
V_119 = F_16 ( V_2 , & V_4 , V_43 -> V_77 ,
V_43 -> V_78 ) ;
else
F_31 ( V_2 -> V_36 , & V_4 ) ;
V_127:
F_32 ( ( unsigned long ) V_4 . V_26 ) ;
return V_119 ;
}
static long F_34 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_3 V_4 ;
struct V_111 V_112 = {
. type = V_117 ,
} ;
int V_119 ;
F_25 ( & V_4 ) ;
V_4 . V_26 = F_35 ( V_53 , V_120 ) ;
if ( ! V_4 . V_26 )
return - V_121 ;
V_4 . V_122 = F_20 ;
V_4 . V_123 = ( ( ( unsigned long long ) V_124 -> V_125 ) << 32 ) +
F_27 ( & V_126 ) ;
V_4 . V_113 = & V_112 ;
V_119 = F_7 ( V_2 , & V_4 , V_47 ) ;
if ( V_119 )
goto V_127;
F_28 ( & V_112 . V_118 ) ;
F_29 ( V_2 -> V_36 , & V_4 ) ;
V_119 = F_30 ( & V_112 . V_118 ) ;
if ( V_119 == 0 )
V_119 = F_18 ( V_2 , & V_4 , V_47 ) ;
else
F_31 ( V_2 -> V_36 , & V_4 ) ;
V_127:
F_36 ( V_4 . V_26 ) ;
return V_119 ;
}
static long F_37 ( struct V_1 * V_2 ,
char * V_97 )
{
struct V_3 V_4 ;
struct V_111 V_112 = {
. type = V_117 ,
} ;
int V_119 ;
F_25 ( & V_4 ) ;
V_4 . V_26 = F_35 ( V_53 , V_120 ) ;
if ( ! V_4 . V_26 )
return - V_121 ;
V_4 . V_122 = F_20 ;
V_4 . V_123 = ( ( ( unsigned long long ) V_124 -> V_125 ) << 32 ) +
F_27 ( & V_126 ) ;
V_4 . V_113 = & V_112 ;
F_9 ( V_2 -> V_36 , & V_4 , V_128 ) ;
F_28 ( & V_112 . V_118 ) ;
F_29 ( V_2 -> V_36 , & V_4 ) ;
V_119 = F_30 ( & V_112 . V_118 ) ;
if ( V_119 == 0 )
V_119 = F_19 ( V_2 , & V_4 , V_97 ) ;
else
F_31 ( V_2 -> V_36 , & V_4 ) ;
F_38 ( V_4 . V_26 ) ;
return V_119 ;
}
static int F_39 ( struct V_66 * V_36 )
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
unsigned long long V_123 ;
struct V_18 * V_19 ;
char * V_76 ;
int V_119 , V_129 ;
V_76 = ( void * ) F_26 ( V_120 ) ;
if ( ! V_76 )
return - V_121 ;
V_119 = F_40 ( V_36 -> V_37 , 0x0102030405060708ULL , V_25 , sizeof( V_25 ) ) ;
if ( V_119 )
goto V_127;
for ( V_129 = 0 ; V_129 < 6 ; V_129 ++ ) {
F_41 ( 300 ) ;
V_119 = F_42 ( V_36 -> V_37 , & V_123 , V_76 , 4096 ) ;
if ( V_119 == 0 && V_123 == 0x0102030405060708ULL )
break;
}
if ( V_129 >= 6 ) {
V_119 = - V_130 ;
goto V_127;
}
V_19 = (struct V_18 * ) ( V_76 + 48 ) ;
if ( V_19 -> V_86 == 8 && V_19 -> V_87 == 33 )
V_119 = V_40 ;
else
V_119 = V_131 ;
V_127:
F_32 ( ( unsigned long ) V_76 ) ;
return V_119 ;
}
static int F_43 ( struct V_66 * V_36 )
{
struct V_3 V_4 ;
unsigned long long V_123 ;
struct {
struct V_98 V_17 ;
struct V_99 V_93 ;
struct V_18 V_19 ;
} V_23 ( ( V_24 ) ) * V_76 ;
int V_119 , V_129 ;
F_25 ( & V_4 ) ;
V_4 . V_26 = ( void * ) F_26 ( V_120 ) ;
if ( ! V_4 . V_26 )
return - V_121 ;
F_9 ( V_36 , & V_4 , 4 ) ;
V_119 = F_40 ( V_36 -> V_37 , 0x0102030405060708ULL , V_4 . V_26 ,
V_4 . V_21 ) ;
if ( V_119 )
goto V_127;
for ( V_129 = 0 ; V_129 < 2 * V_132 ; V_129 ++ ) {
F_44 ( 1000 / V_132 ) ;
V_119 = F_42 ( V_36 -> V_37 , & V_123 , V_4 . V_26 , 4096 ) ;
if ( V_119 == 0 && V_123 == 0x0102030405060708ULL )
break;
}
if ( V_129 >= 2 * V_132 ) {
V_119 = - V_130 ;
goto V_127;
}
V_76 = V_4 . V_26 ;
if ( V_76 -> V_19 . V_86 == 0 && V_76 -> V_19 . V_87 == 0 )
V_119 = 1 ;
else
V_119 = 0 ;
V_127:
F_32 ( ( unsigned long ) V_4 . V_26 ) ;
return V_119 ;
}
static int F_45 ( struct V_66 * V_36 )
{
struct V_1 * V_2 ;
int V_119 = 0 ;
V_2 = F_46 ( V_53 ) ;
if ( ! V_2 )
return - V_121 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_91 = 1 ;
switch ( V_36 -> V_133 ) {
case V_134 :
V_119 = F_39 ( V_36 ) ;
if ( V_119 < 0 ) {
F_47 ( V_2 ) ;
return V_119 ;
}
V_2 -> V_39 = V_119 ;
if ( V_119 == V_40 ) {
V_2 -> V_135 = L_3 ;
V_2 -> V_136 = V_137 ;
V_2 -> V_88 = V_89 ;
V_2 -> V_138 = V_139 ;
V_2 -> V_103 = V_139 ;
} else {
V_2 -> V_135 = L_4 ;
V_2 -> V_136 = V_140 ;
V_2 -> V_88 = V_141 ;
V_2 -> V_138 = V_139 ;
V_2 -> V_103 = V_139 ;
}
break;
case V_142 :
V_2 -> V_39 = V_143 ;
V_2 -> V_135 = L_5 ;
V_2 -> V_136 = V_144 ;
V_2 -> V_88 = V_141 ;
V_2 -> V_138 = V_139 ;
V_2 -> V_103 = V_139 ;
break;
case V_145 :
V_2 -> V_39 = V_146 ;
V_2 -> V_135 = L_6 ;
V_2 -> V_136 = V_147 ;
V_2 -> V_88 = V_148 ;
V_2 -> V_138 = V_149 ;
V_2 -> V_103 = V_149 ;
break;
default:
goto V_127;
}
V_119 = F_43 ( V_36 ) ;
if ( V_119 < 0 ) {
F_47 ( V_2 ) ;
return V_119 ;
}
if ( V_119 )
V_2 -> V_150 = & V_151 ;
else
V_2 -> V_150 = & V_152 ;
V_36 -> V_76 = & V_2 -> V_76 ;
V_36 -> V_113 = V_2 ;
V_119 = F_48 ( V_2 ) ;
if ( V_119 )
goto V_127;
return 0 ;
V_127:
V_36 -> V_113 = NULL ;
F_47 ( V_2 ) ;
return V_119 ;
}
static void F_49 ( struct V_66 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_113 ;
F_50 ( V_2 ) ;
}
int T_2 F_51 ( void )
{
return F_52 ( & V_153 , V_154 , L_7 ) ;
}
void F_53 ( void )
{
F_54 ( & V_153 ) ;
}
