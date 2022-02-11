static void F_1 ( void * V_1 )
{
if ( ! V_1 )
return;
}
static int F_2 ( struct V_2 * V_3 , T_1 V_4 , void * V_5 , int V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
struct V_10 * V_11 = (struct V_10 * ) V_3 -> V_9 ;
int V_12 ;
unsigned int V_13 ;
unsigned int V_14 = 0 , V_15 = 0 ;
unsigned int V_16 = V_8 -> V_17 ;
V_12 = F_3 ( V_3 , V_3 -> V_18 ,
V_8 , V_19 , NULL ) ;
if ( V_12 != V_20 ) {
F_4 ( L_1 ) ;
return V_21 ;
}
if ( V_5 ) {
unsigned int V_22 = V_4 ;
if ( V_4 == V_23 )
V_22 = V_3 -> V_24 ;
else
V_22 = V_3 -> V_18 ;
if ( V_6 ) {
V_12 = F_5 ( V_3 , V_22 , V_3 -> V_25 ) ;
} else {
V_12 = F_6 ( V_3 , V_22 , V_5 ,
V_16 , 0 , & V_15 ) ;
}
if ( V_12 != V_20 ) {
F_4 ( L_2 ) ;
return V_21 ;
}
}
V_12 = F_3 ( V_3 , V_3 -> V_24 , V_11 ,
V_26 , & V_14 ) ;
if ( V_12 == V_27 && V_14 == 0 ) {
F_4 ( L_3 ) ;
V_12 = F_3 ( V_3 , V_3 -> V_24 ,
V_11 , V_26 , & V_14 ) ;
}
if ( V_12 == V_28 ) {
F_4 ( L_4 ) ;
V_12 = F_3 ( V_3 , V_3 -> V_24 ,
V_11 , V_26 , NULL ) ;
}
if ( V_12 != V_20 )
return V_21 ;
V_13 = F_7 ( V_11 -> V_29 ) ;
if ( V_13 && ! ( V_3 -> V_30 & V_31 ) ) {
V_13 = F_8 ( V_13 , V_16 ) ;
if ( V_3 -> V_25 != NULL )
F_9 ( V_3 -> V_25 , F_10 ( F_11 ( V_3 -> V_25 ) ,
( int ) V_13 ) ) ;
}
if ( V_11 -> V_32 != V_33 )
return V_21 ;
return V_34 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_37 -> V_38 . V_39 && V_37 -> V_38 . V_40 )
return V_34 ;
else {
F_13 ( V_3 ) ;
return V_34 ;
}
return V_34 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
unsigned char V_41 [ 36 ] = {
0x00 , 0x80 , 0x02 , 0x00 , 0x1F , 0x00 , 0x00 , 0x00 , 0x55 ,
0x53 , 0x42 , 0x32 , 0x2E , 0x30 , 0x20 , 0x20 , 0x43 , 0x61 ,
0x72 , 0x64 , 0x52 , 0x65 , 0x61 , 0x64 , 0x65 , 0x72 , 0x20 ,
0x20 , 0x20 , 0x20 , 0x20 , 0x20 , 0x30 , 0x31 , 0x30 , 0x30 } ;
F_15 ( V_41 , 36 , V_25 ) ;
return V_34 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
unsigned char V_42 [ 12 ] = {
0x0b , 0x00 , 0x00 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
unsigned char V_43 [ 12 ] = {
0x0b , 0x00 , 0x80 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
if ( V_37 -> V_38 . V_44 )
F_15 ( V_43 , 12 , V_25 ) ;
else
F_15 ( V_42 , 12 , V_25 ) ;
return V_34 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
T_2 V_45 ;
T_3 V_46 ;
unsigned int V_47 = 0 ;
unsigned char V_5 [ 8 ] ;
struct V_48 * V_49 = NULL ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_4 ( L_5 ) ;
if ( V_37 -> V_38 . V_50 ) {
V_46 = 0x200 ;
if ( V_37 -> V_38 . V_51 )
V_45 = V_37 -> V_52 - 1 ;
else
V_45 = ( V_37 -> V_52 + 1 ) * 1024 - 1 ;
} else {
V_46 = 1 << ( V_37 -> V_53 ) ;
V_45 = V_37 -> V_54 * ( V_37 -> V_55 + 1 )
* ( 1 << ( V_37 -> V_56 + 2 ) ) - 1 ;
}
V_37 -> V_45 = V_45 ;
F_4 ( L_6 , V_46 ) ;
F_4 ( L_7 , V_45 ) ;
V_5 [ 0 ] = ( V_45 >> 24 ) & 0xff ;
V_5 [ 1 ] = ( V_45 >> 16 ) & 0xff ;
V_5 [ 2 ] = ( V_45 >> 8 ) & 0xff ;
V_5 [ 3 ] = ( V_45 >> 0 ) & 0xff ;
V_5 [ 4 ] = ( V_46 >> 24 ) & 0xff ;
V_5 [ 5 ] = ( V_46 >> 16 ) & 0xff ;
V_5 [ 6 ] = ( V_46 >> 8 ) & 0xff ;
V_5 [ 7 ] = ( V_46 >> 0 ) & 0xff ;
F_18 ( V_5 , 8 , V_25 , & V_49 , & V_47 , V_57 ) ;
return V_34 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
int V_12 ;
unsigned char * V_58 = V_25 -> V_59 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
T_2 V_60 = ( ( V_58 [ 2 ] << 24 ) & 0xff000000 ) | ( ( V_58 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_58 [ 4 ] << 8 ) & 0x0000ff00 ) | ( ( V_58 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_61 = ( ( V_58 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_58 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_62 = V_60 * 0x200 ;
T_2 V_63 = V_61 * 0x200 ;
if ( V_60 > V_37 -> V_45 )
return V_21 ;
V_12 = F_20 ( V_3 , V_64 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_8 ) ;
return V_21 ;
}
if ( V_37 -> V_38 . V_50 )
V_62 = V_60 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = V_63 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF1 ;
V_8 -> V_68 [ 5 ] = ( unsigned char ) ( V_62 ) ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_62 >> 8 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_62 >> 16 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_62 >> 24 ) ;
V_12 = F_2 ( V_3 , V_23 , F_22 ( V_25 ) , 1 ) ;
return V_12 ;
}
static int F_23 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
int V_12 ;
unsigned char * V_58 = V_25 -> V_59 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
T_2 V_60 = ( ( V_58 [ 2 ] << 24 ) & 0xff000000 ) | ( ( V_58 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_58 [ 4 ] << 8 ) & 0x0000ff00 ) | ( ( V_58 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_61 = ( ( V_58 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_58 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_62 = V_60 * 0x200 ;
T_2 V_63 = V_61 * 0x200 ;
if ( V_60 > V_37 -> V_45 )
return V_21 ;
V_12 = F_20 ( V_3 , V_64 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_8 ) ;
return V_21 ;
}
if ( V_37 -> V_38 . V_50 )
V_62 = V_60 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = V_63 ;
V_8 -> V_67 = 0x00 ;
V_8 -> V_68 [ 0 ] = 0xF0 ;
V_8 -> V_68 [ 5 ] = ( unsigned char ) ( V_62 ) ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_62 >> 8 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_62 >> 16 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_62 >> 24 ) ;
V_12 = F_2 ( V_3 , V_69 , F_22 ( V_25 ) , 1 ) ;
return V_12 ;
}
static int F_24 ( struct V_2 * V_3 , T_3 V_70 , void * V_5 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x01 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xED ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_70 >> 8 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) V_70 ;
V_12 = F_2 ( V_3 , V_23 , V_5 , 0 ) ;
return V_12 ;
}
static int F_25 ( struct V_2 * V_3 , T_1 * V_5 )
{
T_3 V_71 ;
T_2 V_72 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_72 = * ( T_2 * ) & V_5 [ 0x18 ] ;
V_37 -> V_53 = ( T_1 ) ( ( V_72 >> 8 ) & 0x0f ) ;
V_71 = ( T_3 ) V_72 ;
V_72 = * ( T_2 * ) ( & V_5 [ 0x14 ] ) ;
if ( V_37 -> V_38 . V_50 && ! V_37 -> V_38 . V_51 )
V_37 -> V_52 = ( V_72 >> 8 ) & 0x3fffff ;
V_37 -> V_55 = ( ( V_71 & 0x03 ) << 10 ) | ( T_3 ) ( V_72 >> 22 ) ;
V_37 -> V_56 = ( T_1 ) ( V_72 >> 7 ) & 0x07 ;
if ( V_37 -> V_38 . V_50 && V_37 -> V_38 . V_51 )
V_37 -> V_52 = * ( T_2 * ) ( & V_5 [ 0x100 ] ) ;
if ( V_37 -> V_53 > V_73 ) {
V_37 -> V_54 = 1 << ( V_37 -> V_53 - V_73 ) ;
V_37 -> V_53 = V_73 ;
} else {
V_37 -> V_54 = 1 ;
}
return V_34 ;
}
static int F_20 ( struct V_2 * V_3 , unsigned char V_74 )
{
int V_75 ;
char * V_76 = NULL ;
unsigned char * V_5 = NULL ;
const struct V_77 * V_78 = NULL ;
int V_12 = V_21 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_37 -> V_79 == V_74 )
return V_34 ;
switch ( V_74 ) {
case V_80 :
F_4 ( L_9 ) ;
V_76 = L_10 ;
break;
case V_81 :
F_4 ( L_11 ) ;
V_76 = L_12 ;
break;
case V_64 :
F_4 ( L_13 ) ;
V_76 = L_14 ;
break;
default:
F_4 ( L_15 ) ;
goto V_82;
}
V_75 = F_26 ( & V_78 , V_76 , & V_3 -> V_83 -> V_84 ) ;
if ( V_75 ) {
F_4 ( L_16 , V_76 ) ;
goto V_82;
}
V_5 = F_27 ( V_78 -> V_85 , V_86 ) ;
if ( V_5 == NULL ) {
F_4 ( L_17 ) ;
goto V_82;
}
memcpy ( V_5 , V_78 -> V_87 , V_78 -> V_85 ) ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = V_78 -> V_85 ;
V_8 -> V_67 = 0x00 ;
V_8 -> V_68 [ 0 ] = 0xEF ;
V_12 = F_2 ( V_3 , V_69 , V_5 , 0 ) ;
V_37 -> V_79 = V_74 ;
F_28 ( V_5 ) ;
V_82:
if ( V_78 != NULL ) {
F_29 ( V_78 ) ;
V_78 = NULL ;
}
return V_12 ;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_12 ;
T_1 V_5 [ 0x200 ] ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_4 ( L_18 ) ;
V_12 = F_20 ( V_3 , V_80 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_19 ) ;
return V_21 ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF2 ;
V_12 = F_2 ( V_3 , V_23 , NULL , 0 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_20 ) ;
return V_21 ;
}
V_12 = F_20 ( V_3 , V_81 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_21 ) ;
return V_21 ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF1 ;
V_12 = F_2 ( V_3 , V_23 , & V_5 , 0 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_20 ) ;
return V_21 ;
}
V_37 -> V_38 = * (struct V_88 * ) & V_5 [ 0 ] ;
if ( V_37 -> V_38 . V_39 && V_37 -> V_38 . V_40 ) {
F_25 ( V_3 , ( unsigned char * ) & V_5 ) ;
F_4 ( L_22 , V_37 -> V_38 . V_39 ) ;
F_4 ( L_23 , V_37 -> V_38 . V_40 ) ;
F_4 ( L_24 , V_37 -> V_38 . V_51 ) ;
F_4 ( L_25 , V_37 -> V_38 . V_50 ) ;
F_4 ( L_26 , V_37 -> V_38 . V_89 ) ;
F_4 ( L_27 , V_37 -> V_38 . V_44 ) ;
} else {
F_4 ( L_28 , V_5 [ 0 ] ) ;
return V_21 ;
}
return V_34 ;
}
static int F_30 ( struct V_2 * V_3 )
{
int V_12 ;
T_1 V_90 = 0 ;
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
V_12 = F_24 ( V_3 , V_91 , & V_90 ) ;
if ( V_12 != V_20 )
return V_21 ;
if ( V_90 & 0x01 ) {
if ( ! V_37 -> V_38 . V_40 ) {
V_12 = F_13 ( V_3 ) ;
if ( V_12 != V_20 )
return V_21 ;
}
}
return V_12 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
int V_12 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_37 -> V_92 = V_93 ;
switch ( V_25 -> V_59 [ 0 ] ) {
case V_94 :
V_12 = F_12 ( V_3 , V_25 ) ;
break;
case V_95 :
V_12 = F_14 ( V_3 , V_25 ) ;
break;
case V_96 :
V_12 = F_16 ( V_3 , V_25 ) ;
break;
case V_97 :
V_12 = F_17 ( V_3 , V_25 ) ;
break;
case V_98 :
V_12 = F_19 ( V_3 , V_25 ) ;
break;
case V_99 :
V_12 = F_23 ( V_3 , V_25 ) ;
break;
default:
V_37 -> V_92 = V_100 ;
V_12 = V_101 ;
break;
}
return V_12 ;
}
static int F_32 ( struct V_35 * V_25 , struct V_2 * V_3 )
{
int V_12 = 0 ;
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
F_9 ( V_25 , 0 ) ;
if ( F_33 ( ! V_37 -> V_38 . V_40 ) )
V_12 = F_30 ( V_3 ) ;
else
V_12 = F_31 ( V_3 , V_25 ) ;
return 0 ;
}
static int F_34 ( struct V_102 * V_103 ,
const struct V_104 * V_105 )
{
int V_12 ;
T_1 V_90 = 0 ;
struct V_2 * V_3 ;
V_12 = F_35 ( & V_3 , V_103 , V_105 ,
( V_105 - V_106 ) + V_107 ) ;
if ( V_12 )
return V_12 ;
if ( ! V_3 -> V_1 ) {
V_3 -> V_1 = F_36 ( sizeof( struct V_36 ) , V_86 ) ;
if ( ! V_3 -> V_1 )
return - V_108 ;
V_3 -> V_109 = F_1 ;
}
V_3 -> V_110 = L_29 ;
V_3 -> V_111 = F_32 ;
V_3 -> V_112 = 0 ;
V_12 = F_37 ( V_3 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_24 ( V_3 , V_91 , & V_90 ) ;
if ( V_12 != V_20 ) {
F_38 ( V_103 ) ;
return V_21 ;
}
if ( ! ( V_90 & 0x01 ) ) {
V_12 = - V_113 ;
F_39 ( V_114 L_30
L_31 ) ;
F_38 ( V_103 ) ;
}
return V_12 ;
}
static int F_40 ( struct V_102 * V_115 )
{
T_1 V_116 = 0 ;
struct V_2 * V_3 = F_41 ( V_115 ) ;
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
F_42 ( & V_3 -> V_117 ) ;
F_4 ( L_32 , V_118 ) ;
if ( V_3 -> V_119 )
( V_3 -> V_119 ) ( V_3 , V_120 ) ;
F_43 ( & V_3 -> V_117 ) ;
V_37 -> V_121 = true ;
V_37 -> V_38 = * (struct V_88 * ) & V_116 ;
V_37 -> V_122 = * (struct V_123 * ) & V_116 ;
V_37 -> V_124 = * (struct V_125 * ) & V_116 ;
return 0 ;
}
static int F_44 ( struct V_102 * V_115 )
{
T_1 V_116 = 0 ;
struct V_2 * V_3 = F_41 ( V_115 ) ;
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
F_4 ( L_32 , V_118 ) ;
F_45 ( V_115 ) ;
V_37 -> V_121 = true ;
V_37 -> V_38 = * (struct V_88 * ) & V_116 ;
V_37 -> V_122 = * (struct V_123 * ) & V_116 ;
V_37 -> V_124 = * (struct V_125 * ) & V_116 ;
return 0 ;
}
static int T_4 F_46 ( void )
{
return F_47 ( & V_126 ) ;
}
static void T_5 F_48 ( void )
{
F_49 ( & V_126 ) ;
}
