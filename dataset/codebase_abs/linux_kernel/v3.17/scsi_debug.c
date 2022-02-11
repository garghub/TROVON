static unsigned int F_1 ( void )
{
return ( ( 0 == V_1 ) &&
( V_2 | V_3 | V_4 ) ) ;
}
static void * F_2 ( unsigned long long V_5 )
{
V_5 = F_3 ( V_5 , V_6 ) ;
return V_7 + V_5 * V_8 ;
}
static struct V_9 * F_4 ( T_1 V_10 )
{
V_10 = F_3 ( V_10 , V_6 ) ;
return V_11 + V_10 ;
}
static void F_5 ( void )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
F_6 ( & V_16 ) ;
F_7 (sdbg_host, &sdebug_host_list, host_list) {
V_15 = V_13 -> V_17 ;
if ( ( V_15 -> V_18 >= 0 ) &&
( V_19 > V_15 -> V_18 ) )
V_15 -> V_20 = V_19 + 1 ;
else
V_15 -> V_20 = V_19 ;
V_15 -> V_21 = V_22 ;
}
F_8 ( & V_16 ) ;
}
static void F_9 ( struct V_23 * V_24 , int V_25 , int V_26 , int V_27 )
{
unsigned char * V_28 ;
V_28 = V_24 -> V_29 ;
if ( ! V_28 ) {
F_10 ( V_30 , V_24 -> V_31 ,
L_1 , V_32 ) ;
return;
}
memset ( V_28 , 0 , V_33 ) ;
F_11 ( V_34 , V_28 , V_25 , V_26 , V_27 ) ;
if ( V_35 & V_36 )
F_10 ( V_37 , V_24 -> V_31 ,
L_2 ,
V_38 , V_25 , V_26 , V_27 ) ;
}
static void F_12 ( unsigned char * V_39 ,
unsigned long long * V_5 , unsigned int * V_40 ,
T_2 * V_41 )
{
* V_41 = 0 ;
switch ( * V_39 ) {
case V_42 :
* V_5 = ( V_43 ) V_39 [ 19 ] | ( V_43 ) V_39 [ 18 ] << 8 |
( V_43 ) V_39 [ 17 ] << 16 | ( V_43 ) V_39 [ 16 ] << 24 |
( V_43 ) V_39 [ 15 ] << 32 | ( V_43 ) V_39 [ 14 ] << 40 |
( V_43 ) V_39 [ 13 ] << 48 | ( V_43 ) V_39 [ 12 ] << 56 ;
* V_41 = ( T_2 ) V_39 [ 23 ] | ( T_2 ) V_39 [ 22 ] << 8 |
( T_2 ) V_39 [ 21 ] << 16 | ( T_2 ) V_39 [ 20 ] << 24 ;
* V_40 = ( T_2 ) V_39 [ 31 ] | ( T_2 ) V_39 [ 30 ] << 8 | ( T_2 ) V_39 [ 29 ] << 16 |
( T_2 ) V_39 [ 28 ] << 24 ;
break;
case V_44 :
case V_45 :
case V_46 :
* V_5 = ( V_43 ) V_39 [ 9 ] | ( V_43 ) V_39 [ 8 ] << 8 |
( V_43 ) V_39 [ 7 ] << 16 | ( V_43 ) V_39 [ 6 ] << 24 |
( V_43 ) V_39 [ 5 ] << 32 | ( V_43 ) V_39 [ 4 ] << 40 |
( V_43 ) V_39 [ 3 ] << 48 | ( V_43 ) V_39 [ 2 ] << 56 ;
* V_40 = ( T_2 ) V_39 [ 13 ] | ( T_2 ) V_39 [ 12 ] << 8 | ( T_2 ) V_39 [ 11 ] << 16 |
( T_2 ) V_39 [ 10 ] << 24 ;
break;
case V_47 :
case V_48 :
* V_5 = ( T_2 ) V_39 [ 5 ] | ( T_2 ) V_39 [ 4 ] << 8 | ( T_2 ) V_39 [ 3 ] << 16 |
( T_2 ) V_39 [ 2 ] << 24 ;
* V_40 = ( T_2 ) V_39 [ 9 ] | ( T_2 ) V_39 [ 8 ] << 8 | ( T_2 ) V_39 [ 7 ] << 16 |
( T_2 ) V_39 [ 6 ] << 24 ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
* V_5 = ( T_2 ) V_39 [ 5 ] | ( T_2 ) V_39 [ 4 ] << 8 | ( T_2 ) V_39 [ 3 ] << 16 |
( T_2 ) V_39 [ 2 ] << 24 ;
* V_40 = ( T_2 ) V_39 [ 8 ] | ( T_2 ) V_39 [ 7 ] << 8 ;
break;
case V_53 :
case V_54 :
* V_5 = ( T_2 ) V_39 [ 3 ] | ( T_2 ) V_39 [ 2 ] << 8 |
( T_2 ) ( V_39 [ 1 ] & 0x1f ) << 16 ;
* V_40 = ( 0 == V_39 [ 4 ] ) ? 256 : V_39 [ 4 ] ;
break;
default:
break;
}
}
static int F_13 ( struct V_55 * V_56 , int V_39 , void T_3 * V_57 )
{
if ( V_35 & V_36 ) {
if ( 0x1261 == V_39 )
F_10 ( V_37 , V_56 ,
L_3 , V_32 ) ;
else if ( 0x5331 == V_39 )
F_10 ( V_37 , V_56 ,
L_4 ,
V_32 ) ;
else
F_10 ( V_37 , V_56 , L_5 ,
V_32 , V_39 ) ;
}
return - V_58 ;
}
static int F_14 ( struct V_23 * V_59 , int V_60 ,
struct V_61 * V_62 )
{
int V_63 ;
bool V_64 = ! ! ( V_35 & V_36 ) ;
V_63 = F_15 ( V_62 -> V_65 , V_66 ) ;
if ( V_63 != V_66 ) {
const char * V_67 = NULL ;
switch ( V_63 ) {
case V_68 :
F_9 ( V_59 , V_69 ,
V_70 , V_71 ) ;
if ( V_64 )
V_67 = L_6 ;
break;
case V_72 :
F_9 ( V_59 , V_69 ,
V_70 , V_73 ) ;
if ( V_64 )
V_67 = L_7 ;
break;
case V_74 :
F_9 ( V_59 , V_69 ,
V_75 , V_76 ) ;
if ( V_64 )
V_67 = L_8 ;
break;
default:
F_16 ( L_9 ,
V_32 , V_63 ) ;
if ( V_64 )
V_67 = L_10 ;
break;
}
F_17 ( V_63 , V_62 -> V_65 ) ;
if ( V_64 )
F_10 ( V_37 , V_59 -> V_31 ,
L_11 ,
V_38 , V_67 ) ;
return V_77 ;
}
if ( ( V_78 == V_60 ) && V_62 -> V_79 ) {
F_9 ( V_59 , V_80 , V_81 ,
0x2 ) ;
if ( V_64 )
F_10 ( V_37 , V_59 -> V_31 ,
L_12 , V_38 ,
L_13 ) ;
return V_77 ;
}
return 0 ;
}
static int F_18 ( struct V_23 * V_24 , unsigned char * V_82 ,
int V_83 )
{
int V_84 ;
struct V_85 * V_86 = F_19 ( V_24 ) ;
if ( ! V_86 -> V_87 )
return 0 ;
if ( ! ( F_20 ( V_24 ) || V_24 -> V_88 == V_89 ) )
return ( V_90 << 16 ) ;
V_84 = F_21 ( V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_82 , V_83 ) ;
V_86 -> V_94 = F_22 ( V_24 ) - V_84 ;
return 0 ;
}
static int F_23 ( struct V_23 * V_24 , unsigned char * V_82 ,
int V_83 )
{
if ( ! F_22 ( V_24 ) )
return 0 ;
if ( ! ( F_20 ( V_24 ) || V_24 -> V_88 == V_95 ) )
return - 1 ;
return F_24 ( V_24 , V_82 , V_83 ) ;
}
static int F_25 ( unsigned char * V_82 , int V_96 ,
int V_97 , int V_98 ,
const char * V_99 ,
int V_100 )
{
int V_40 , V_101 ;
char V_102 [ 32 ] ;
V_101 = V_97 + 1 ;
V_82 [ 0 ] = 0x2 ;
V_82 [ 1 ] = 0x1 ;
V_82 [ 2 ] = 0x0 ;
memcpy ( & V_82 [ 4 ] , V_103 , 8 ) ;
memcpy ( & V_82 [ 12 ] , V_104 , 16 ) ;
memcpy ( & V_82 [ 28 ] , V_99 , V_100 ) ;
V_40 = 8 + 16 + V_100 ;
V_82 [ 3 ] = V_40 ;
V_40 += 4 ;
if ( V_98 >= 0 ) {
V_82 [ V_40 ++ ] = 0x1 ;
V_82 [ V_40 ++ ] = 0x3 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x8 ;
V_82 [ V_40 ++ ] = 0x53 ;
V_82 [ V_40 ++ ] = 0x33 ;
V_82 [ V_40 ++ ] = 0x33 ;
V_82 [ V_40 ++ ] = 0x30 ;
V_82 [ V_40 ++ ] = ( V_98 >> 24 ) ;
V_82 [ V_40 ++ ] = ( V_98 >> 16 ) & 0xff ;
V_82 [ V_40 ++ ] = ( V_98 >> 8 ) & 0xff ;
V_82 [ V_40 ++ ] = V_98 & 0xff ;
V_82 [ V_40 ++ ] = 0x61 ;
V_82 [ V_40 ++ ] = 0x94 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x4 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x1 ;
}
V_82 [ V_40 ++ ] = 0x61 ;
V_82 [ V_40 ++ ] = 0x93 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x8 ;
V_82 [ V_40 ++ ] = 0x52 ;
V_82 [ V_40 ++ ] = 0x22 ;
V_82 [ V_40 ++ ] = 0x22 ;
V_82 [ V_40 ++ ] = 0x20 ;
V_82 [ V_40 ++ ] = ( V_101 >> 24 ) ;
V_82 [ V_40 ++ ] = ( V_101 >> 16 ) & 0xff ;
V_82 [ V_40 ++ ] = ( V_101 >> 8 ) & 0xff ;
V_82 [ V_40 ++ ] = V_101 & 0xff ;
V_82 [ V_40 ++ ] = 0x61 ;
V_82 [ V_40 ++ ] = 0x95 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x4 ;
V_82 [ V_40 ++ ] = 0 ;
V_82 [ V_40 ++ ] = 0 ;
V_82 [ V_40 ++ ] = ( V_96 >> 8 ) & 0xff ;
V_82 [ V_40 ++ ] = V_96 & 0xff ;
V_82 [ V_40 ++ ] = 0x61 ;
V_82 [ V_40 ++ ] = 0xa3 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x8 ;
V_82 [ V_40 ++ ] = 0x52 ;
V_82 [ V_40 ++ ] = 0x22 ;
V_82 [ V_40 ++ ] = 0x22 ;
V_82 [ V_40 ++ ] = 0x20 ;
V_82 [ V_40 ++ ] = ( V_97 >> 24 ) ;
V_82 [ V_40 ++ ] = ( V_97 >> 16 ) & 0xff ;
V_82 [ V_40 ++ ] = ( V_97 >> 8 ) & 0xff ;
V_82 [ V_40 ++ ] = V_97 & 0xff ;
V_82 [ V_40 ++ ] = 0x63 ;
V_82 [ V_40 ++ ] = 0xa8 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 24 ;
memcpy ( V_82 + V_40 , L_14 , 12 ) ;
V_40 += 12 ;
snprintf ( V_102 , sizeof( V_102 ) , L_15 , V_97 ) ;
memcpy ( V_82 + V_40 , V_102 , 8 ) ;
V_40 += 8 ;
memset ( V_82 + V_40 , 0 , 4 ) ;
V_40 += 4 ;
return V_40 ;
}
static int F_26 ( unsigned char * V_82 )
{
memcpy ( V_82 , V_105 , sizeof( V_105 ) ) ;
return sizeof( V_105 ) ;
}
static int F_27 ( unsigned char * V_82 )
{
int V_40 = 0 ;
const char * V_106 = L_16 ;
const char * V_107 = L_17 ;
int V_108 , V_109 ;
V_82 [ V_40 ++ ] = 0x1 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_109 = strlen ( V_106 ) ;
V_108 = V_109 + 1 ;
if ( V_108 % 4 )
V_108 = ( ( V_108 / 4 ) + 1 ) * 4 ;
V_82 [ V_40 ++ ] = V_108 ;
memcpy ( V_82 + V_40 , V_106 , V_109 ) ;
memset ( V_82 + V_40 + V_109 , 0 , V_108 - V_109 ) ;
V_40 += V_108 ;
V_82 [ V_40 ++ ] = 0x4 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_109 = strlen ( V_107 ) ;
V_108 = V_109 + 1 ;
if ( V_108 % 4 )
V_108 = ( ( V_108 / 4 ) + 1 ) * 4 ;
V_82 [ V_40 ++ ] = V_108 ;
memcpy ( V_82 + V_40 , V_107 , V_109 ) ;
memset ( V_82 + V_40 + V_109 , 0 , V_108 - V_109 ) ;
V_40 += V_108 ;
return V_40 ;
}
static int F_28 ( unsigned char * V_82 , int V_97 )
{
int V_40 = 0 ;
int V_101 , V_110 ;
V_101 = V_97 + 1 ;
V_110 = V_101 + 1 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x1 ;
memset ( V_82 + V_40 , 0 , 6 ) ;
V_40 += 6 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 12 ;
V_82 [ V_40 ++ ] = 0x61 ;
V_82 [ V_40 ++ ] = 0x93 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x8 ;
V_82 [ V_40 ++ ] = 0x52 ;
V_82 [ V_40 ++ ] = 0x22 ;
V_82 [ V_40 ++ ] = 0x22 ;
V_82 [ V_40 ++ ] = 0x20 ;
V_82 [ V_40 ++ ] = ( V_101 >> 24 ) ;
V_82 [ V_40 ++ ] = ( V_101 >> 16 ) & 0xff ;
V_82 [ V_40 ++ ] = ( V_101 >> 8 ) & 0xff ;
V_82 [ V_40 ++ ] = V_101 & 0xff ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x2 ;
memset ( V_82 + V_40 , 0 , 6 ) ;
V_40 += 6 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 12 ;
V_82 [ V_40 ++ ] = 0x61 ;
V_82 [ V_40 ++ ] = 0x93 ;
V_82 [ V_40 ++ ] = 0x0 ;
V_82 [ V_40 ++ ] = 0x8 ;
V_82 [ V_40 ++ ] = 0x52 ;
V_82 [ V_40 ++ ] = 0x22 ;
V_82 [ V_40 ++ ] = 0x22 ;
V_82 [ V_40 ++ ] = 0x20 ;
V_82 [ V_40 ++ ] = ( V_110 >> 24 ) ;
V_82 [ V_40 ++ ] = ( V_110 >> 16 ) & 0xff ;
V_82 [ V_40 ++ ] = ( V_110 >> 8 ) & 0xff ;
V_82 [ V_40 ++ ] = V_110 & 0xff ;
return V_40 ;
}
static int F_29 ( unsigned char * V_82 )
{
memcpy ( V_82 , V_111 , sizeof( V_111 ) ) ;
return sizeof( V_111 ) ;
}
static int F_30 ( unsigned char * V_82 )
{
unsigned int V_112 ;
memcpy ( V_82 , V_113 , sizeof( V_113 ) ) ;
V_112 = 1 << V_114 ;
V_82 [ 2 ] = ( V_112 >> 8 ) & 0xff ;
V_82 [ 3 ] = V_112 & 0xff ;
if ( V_6 > 0x400 ) {
V_82 [ 4 ] = ( V_6 >> 24 ) & 0xff ;
V_82 [ 5 ] = ( V_6 >> 16 ) & 0xff ;
V_82 [ 6 ] = ( V_6 >> 8 ) & 0xff ;
V_82 [ 7 ] = V_6 & 0xff ;
}
F_31 ( V_115 , & V_82 [ 8 ] ) ;
if ( V_2 ) {
F_31 ( V_116 , & V_82 [ 16 ] ) ;
F_31 ( V_117 , & V_82 [ 20 ] ) ;
}
if ( V_118 ) {
F_31 ( V_118 , & V_82 [ 28 ] ) ;
V_82 [ 28 ] |= 0x80 ;
}
F_31 ( V_119 , & V_82 [ 24 ] ) ;
F_32 ( V_120 , & V_82 [ 32 ] ) ;
return 0x3c ;
return sizeof( V_113 ) ;
}
static int F_33 ( unsigned char * V_82 )
{
memset ( V_82 , 0 , 0x3c ) ;
V_82 [ 0 ] = 0 ;
V_82 [ 1 ] = 1 ;
V_82 [ 2 ] = 0 ;
V_82 [ 3 ] = 5 ;
return 0x3c ;
}
static int F_34 ( unsigned char * V_82 )
{
memset ( V_82 , 0 , 0x4 ) ;
V_82 [ 0 ] = 0 ;
if ( V_2 )
V_82 [ 1 ] = 1 << 7 ;
if ( V_3 )
V_82 [ 1 ] |= 1 << 6 ;
if ( V_4 )
V_82 [ 1 ] |= 1 << 5 ;
if ( V_121 )
V_82 [ 1 ] |= 1 << 2 ;
return 0x4 ;
}
static int F_35 ( struct V_23 * V_24 , int V_122 ,
struct V_61 * V_62 )
{
unsigned char V_123 ;
unsigned char * V_82 ;
unsigned char * V_39 = ( unsigned char * ) V_24 -> V_124 ;
int V_125 , V_126 , V_127 ;
V_125 = ( V_39 [ 3 ] << 8 ) + V_39 [ 4 ] ;
V_82 = F_36 ( V_128 , V_129 ) ;
if ( ! V_82 )
return V_130 << 16 ;
if ( V_62 -> V_131 )
V_123 = 0x1e ;
else if ( V_132 && ( 0 == V_62 -> V_133 ) )
V_123 = 0x7f ;
else
V_123 = ( V_134 & 0x1f ) ;
V_82 [ 0 ] = V_123 ;
if ( 0x2 & V_39 [ 1 ] ) {
F_9 ( V_24 , V_135 , V_136 ,
0 ) ;
F_37 ( V_82 ) ;
return V_77 ;
} else if ( 0x1 & V_39 [ 1 ] ) {
int V_137 , V_96 , V_97 , V_138 ;
char V_139 [ 6 ] ;
int V_140 = V_62 -> V_13 -> V_17 -> V_140 ;
V_96 = ( ( ( V_140 + 1 ) & 0x7f ) << 8 ) +
( V_62 -> V_141 & 0x7f ) ;
if ( 0 == V_142 )
V_140 = 0 ;
V_137 = V_62 -> V_131 ? - 1 : ( ( ( V_140 + 1 ) * 2000 ) +
( V_62 -> V_122 * 1000 ) + V_62 -> V_133 ) ;
V_97 = ( ( V_140 + 1 ) * 2000 ) +
( V_62 -> V_122 * 1000 ) - 3 ;
V_138 = F_38 ( V_139 , 6 , L_18 , V_137 ) ;
if ( 0 == V_39 [ 2 ] ) {
V_82 [ 1 ] = V_39 [ 2 ] ;
V_126 = 4 ;
V_82 [ V_126 ++ ] = 0x0 ;
V_82 [ V_126 ++ ] = 0x80 ;
V_82 [ V_126 ++ ] = 0x83 ;
V_82 [ V_126 ++ ] = 0x84 ;
V_82 [ V_126 ++ ] = 0x85 ;
V_82 [ V_126 ++ ] = 0x86 ;
V_82 [ V_126 ++ ] = 0x87 ;
V_82 [ V_126 ++ ] = 0x88 ;
V_82 [ V_126 ++ ] = 0x89 ;
V_82 [ V_126 ++ ] = 0xb0 ;
V_82 [ V_126 ++ ] = 0xb1 ;
if ( F_1 () )
V_82 [ V_126 ++ ] = 0xb2 ;
V_82 [ 3 ] = V_126 - 4 ;
} else if ( 0x80 == V_39 [ 2 ] ) {
V_82 [ 1 ] = V_39 [ 2 ] ;
V_82 [ 3 ] = V_138 ;
memcpy ( & V_82 [ 4 ] , V_139 , V_138 ) ;
} else if ( 0x83 == V_39 [ 2 ] ) {
V_82 [ 1 ] = V_39 [ 2 ] ;
V_82 [ 3 ] = F_25 ( & V_82 [ 4 ] , V_96 ,
V_97 , V_137 ,
V_139 , V_138 ) ;
} else if ( 0x84 == V_39 [ 2 ] ) {
V_82 [ 1 ] = V_39 [ 2 ] ;
V_82 [ 3 ] = F_26 ( & V_82 [ 4 ] ) ;
} else if ( 0x85 == V_39 [ 2 ] ) {
V_82 [ 1 ] = V_39 [ 2 ] ;
V_82 [ 3 ] = F_27 ( & V_82 [ 4 ] ) ;
} else if ( 0x86 == V_39 [ 2 ] ) {
V_82 [ 1 ] = V_39 [ 2 ] ;
V_82 [ 3 ] = 0x3c ;
if ( V_143 == V_144 )
V_82 [ 4 ] = 0x4 ;
else if ( V_143 )
V_82 [ 4 ] = 0x5 ;
else
V_82 [ 4 ] = 0x0 ;
V_82 [ 5 ] = 0x7 ;
} else if ( 0x87 == V_39 [ 2 ] ) {
V_82 [ 1 ] = V_39 [ 2 ] ;
V_82 [ 3 ] = 0x8 ;
V_82 [ 4 ] = 0x2 ;
V_82 [ 6 ] = 0x80 ;
V_82 [ 8 ] = 0x18 ;
V_82 [ 10 ] = 0x82 ;
} else if ( 0x88 == V_39 [ 2 ] ) {
V_82 [ 1 ] = V_39 [ 2 ] ;
V_82 [ 3 ] = F_28 ( & V_82 [ 4 ] , V_97 ) ;
} else if ( 0x89 == V_39 [ 2 ] ) {
V_82 [ 1 ] = V_39 [ 2 ] ;
V_126 = F_29 ( & V_82 [ 4 ] ) ;
V_82 [ 2 ] = ( V_126 >> 8 ) ;
V_82 [ 3 ] = ( V_126 & 0xff ) ;
} else if ( 0xb0 == V_39 [ 2 ] ) {
V_82 [ 1 ] = V_39 [ 2 ] ;
V_82 [ 3 ] = F_30 ( & V_82 [ 4 ] ) ;
} else if ( 0xb1 == V_39 [ 2 ] ) {
V_82 [ 1 ] = V_39 [ 2 ] ;
V_82 [ 3 ] = F_33 ( & V_82 [ 4 ] ) ;
} else if ( 0xb2 == V_39 [ 2 ] ) {
V_82 [ 1 ] = V_39 [ 2 ] ;
V_82 [ 3 ] = F_34 ( & V_82 [ 4 ] ) ;
} else {
F_9 ( V_24 , V_135 ,
V_136 , 0 ) ;
F_37 ( V_82 ) ;
return V_77 ;
}
V_138 = F_39 ( ( ( V_82 [ 2 ] << 8 ) + V_82 [ 3 ] ) + 4 , V_125 ) ;
V_127 = F_18 ( V_24 , V_82 ,
F_39 ( V_138 , V_128 ) ) ;
F_37 ( V_82 ) ;
return V_127 ;
}
V_82 [ 1 ] = V_145 ? 0x80 : 0 ;
V_82 [ 2 ] = V_146 ;
V_82 [ 3 ] = 2 ;
V_82 [ 4 ] = V_147 - 5 ;
V_82 [ 5 ] = V_143 ? 1 : 0 ;
if ( 0 == V_142 )
V_82 [ 5 ] = 0x10 ;
V_82 [ 6 ] = 0x10 ;
V_82 [ 7 ] = 0xa ;
memcpy ( & V_82 [ 8 ] , V_103 , 8 ) ;
memcpy ( & V_82 [ 16 ] , V_104 , 16 ) ;
memcpy ( & V_82 [ 32 ] , V_148 , 4 ) ;
V_82 [ 58 ] = 0x0 ; V_82 [ 59 ] = 0x77 ;
V_82 [ 60 ] = 0x3 ; V_82 [ 61 ] = 0x14 ;
V_126 = 62 ;
if ( V_134 == 0 ) {
V_82 [ V_126 ++ ] = 0x3 ; V_82 [ V_126 ++ ] = 0x3d ;
} else if ( V_134 == 1 ) {
V_82 [ V_126 ++ ] = 0x3 ; V_82 [ V_126 ++ ] = 0x60 ;
}
V_82 [ V_126 ++ ] = 0xc ; V_82 [ V_126 ++ ] = 0xf ;
V_127 = F_18 ( V_24 , V_82 ,
F_39 ( V_125 , V_147 ) ) ;
F_37 ( V_82 ) ;
return V_127 ;
}
static int F_40 ( struct V_23 * V_24 ,
struct V_61 * V_62 )
{
unsigned char * V_28 ;
unsigned char * V_39 = ( unsigned char * ) V_24 -> V_124 ;
unsigned char V_82 [ V_33 ] ;
int V_149 ;
int V_138 = 18 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_149 = ! ! ( V_39 [ 1 ] & 1 ) || V_34 ;
V_28 = V_24 -> V_29 ;
if ( ( V_150 [ 2 ] & 0x4 ) && ( 6 == ( V_150 [ 3 ] & 0xf ) ) ) {
if ( V_149 ) {
V_82 [ 0 ] = 0x72 ;
V_82 [ 1 ] = 0x0 ;
V_82 [ 2 ] = V_151 ;
V_82 [ 3 ] = 0xff ;
} else {
V_82 [ 0 ] = 0x70 ;
V_82 [ 2 ] = 0x0 ;
V_82 [ 7 ] = 0xa ;
V_82 [ 12 ] = V_151 ;
V_82 [ 13 ] = 0xff ;
}
} else {
memcpy ( V_82 , V_28 , V_33 ) ;
if ( ( V_39 [ 1 ] & 1 ) && ( ! V_34 ) ) {
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_82 [ 0 ] = 0x72 ;
V_82 [ 1 ] = V_28 [ 2 ] ;
V_82 [ 2 ] = V_28 [ 12 ] ;
V_82 [ 3 ] = V_28 [ 13 ] ;
V_138 = 8 ;
}
}
F_9 ( V_24 , 0 , V_152 , 0 ) ;
return F_18 ( V_24 , V_82 , V_138 ) ;
}
static int F_41 ( struct V_23 * V_24 ,
struct V_61 * V_62 )
{
unsigned char * V_39 = ( unsigned char * ) V_24 -> V_124 ;
int V_153 , V_154 , V_155 ;
V_154 = F_14 ( V_24 , V_156 , V_62 ) ;
if ( V_154 )
return V_154 ;
V_153 = ( V_39 [ 4 ] & 0xf0 ) >> 4 ;
if ( V_153 ) {
F_9 ( V_24 , V_135 , V_136 ,
0 ) ;
return V_77 ;
}
V_155 = V_39 [ 4 ] & 1 ;
if ( V_155 == V_62 -> V_79 )
V_62 -> V_79 = ! V_155 ;
return 0 ;
}
static T_1 F_42 ( void )
{
if ( V_157 > 0 )
return ( T_1 ) V_157 *
( 1073741824 / V_8 ) ;
else
return V_6 ;
}
static int F_43 ( struct V_23 * V_24 ,
struct V_61 * V_62 )
{
unsigned char V_82 [ V_158 ] ;
unsigned int V_159 ;
int V_154 ;
V_154 = F_14 ( V_24 , V_156 , V_62 ) ;
if ( V_154 )
return V_154 ;
V_160 = F_42 () ;
memset ( V_82 , 0 , V_158 ) ;
if ( V_160 < 0xffffffff ) {
V_159 = ( unsigned int ) V_160 - 1 ;
V_82 [ 0 ] = ( V_159 >> 24 ) ;
V_82 [ 1 ] = ( V_159 >> 16 ) & 0xff ;
V_82 [ 2 ] = ( V_159 >> 8 ) & 0xff ;
V_82 [ 3 ] = V_159 & 0xff ;
} else {
V_82 [ 0 ] = 0xff ;
V_82 [ 1 ] = 0xff ;
V_82 [ 2 ] = 0xff ;
V_82 [ 3 ] = 0xff ;
}
V_82 [ 6 ] = ( V_8 >> 8 ) & 0xff ;
V_82 [ 7 ] = V_8 & 0xff ;
return F_18 ( V_24 , V_82 , V_158 ) ;
}
static int F_44 ( struct V_23 * V_24 ,
struct V_61 * V_62 )
{
unsigned char * V_39 = ( unsigned char * ) V_24 -> V_124 ;
unsigned char V_82 [ V_161 ] ;
unsigned long long V_159 ;
int V_154 , V_63 , V_125 ;
V_154 = F_14 ( V_24 , V_156 , V_62 ) ;
if ( V_154 )
return V_154 ;
V_125 = ( ( V_39 [ 10 ] << 24 ) + ( V_39 [ 11 ] << 16 ) + ( V_39 [ 12 ] << 8 )
+ V_39 [ 13 ] ) ;
V_160 = F_42 () ;
memset ( V_82 , 0 , V_161 ) ;
V_159 = V_160 - 1 ;
for ( V_63 = 0 ; V_63 < 8 ; ++ V_63 , V_159 >>= 8 )
V_82 [ 7 - V_63 ] = V_159 & 0xff ;
V_82 [ 8 ] = ( V_8 >> 24 ) & 0xff ;
V_82 [ 9 ] = ( V_8 >> 16 ) & 0xff ;
V_82 [ 10 ] = ( V_8 >> 8 ) & 0xff ;
V_82 [ 11 ] = V_8 & 0xff ;
V_82 [ 13 ] = V_114 & 0xf ;
V_82 [ 14 ] = ( V_162 >> 8 ) & 0x3f ;
if ( F_1 () ) {
V_82 [ 14 ] |= 0x80 ;
if ( V_121 )
V_82 [ 14 ] |= 0x40 ;
}
V_82 [ 15 ] = V_162 & 0xff ;
if ( V_143 ) {
V_82 [ 12 ] = ( V_143 - 1 ) << 1 ;
V_82 [ 12 ] |= 1 ;
}
return F_18 ( V_24 , V_82 ,
F_39 ( V_125 , V_161 ) ) ;
}
static int F_45 ( struct V_23 * V_24 ,
struct V_61 * V_62 )
{
unsigned char * V_39 = ( unsigned char * ) V_24 -> V_124 ;
unsigned char * V_82 ;
int V_140 = V_62 -> V_13 -> V_17 -> V_140 ;
int V_126 , V_127 , V_163 , V_164 ;
int V_165 , V_166 , V_101 , V_110 ;
V_163 = ( ( V_39 [ 6 ] << 24 ) + ( V_39 [ 7 ] << 16 ) + ( V_39 [ 8 ] << 8 )
+ V_39 [ 9 ] ) ;
V_82 = F_36 ( V_167 , V_129 ) ;
if ( ! V_82 )
return V_130 << 16 ;
V_101 = 0x1 ;
V_110 = 0x2 ;
V_165 = ( ( ( V_140 + 1 ) & 0x7f ) << 8 ) +
( V_62 -> V_141 & 0x7f ) ;
V_166 = ( ( ( V_140 + 1 ) & 0x7f ) << 8 ) +
( V_62 -> V_141 & 0x7f ) + 0x80 ;
V_126 = 4 ;
if ( 0 == V_142 ) {
V_82 [ V_126 ++ ] = V_140 % 3 ;
V_82 [ V_126 ++ ] = 0x0F ;
} else {
V_82 [ V_126 ++ ] = 0x0 ;
V_82 [ V_126 ++ ] = 0x01 ;
}
V_82 [ V_126 ++ ] = ( V_165 >> 8 ) & 0xff ;
V_82 [ V_126 ++ ] = V_165 & 0xff ;
V_82 [ V_126 ++ ] = 0 ;
V_82 [ V_126 ++ ] = 0 ;
V_82 [ V_126 ++ ] = 0 ;
V_82 [ V_126 ++ ] = 0x1 ;
V_82 [ V_126 ++ ] = 0 ;
V_82 [ V_126 ++ ] = 0 ;
V_82 [ V_126 ++ ] = ( V_101 >> 8 ) & 0xff ;
V_82 [ V_126 ++ ] = V_101 & 0xff ;
V_82 [ V_126 ++ ] = 3 ;
V_82 [ V_126 ++ ] = 0x08 ;
V_82 [ V_126 ++ ] = ( V_166 >> 8 ) & 0xff ;
V_82 [ V_126 ++ ] = V_166 & 0xff ;
V_82 [ V_126 ++ ] = 0 ;
V_82 [ V_126 ++ ] = 0 ;
V_82 [ V_126 ++ ] = 0 ;
V_82 [ V_126 ++ ] = 0x1 ;
V_82 [ V_126 ++ ] = 0 ;
V_82 [ V_126 ++ ] = 0 ;
V_82 [ V_126 ++ ] = ( V_110 >> 8 ) & 0xff ;
V_82 [ V_126 ++ ] = V_110 & 0xff ;
V_164 = V_126 - 4 ;
V_82 [ 0 ] = ( V_164 >> 24 ) & 0xff ;
V_82 [ 1 ] = ( V_164 >> 16 ) & 0xff ;
V_82 [ 2 ] = ( V_164 >> 8 ) & 0xff ;
V_82 [ 3 ] = V_164 & 0xff ;
V_164 = F_39 ( V_163 , V_126 ) ;
V_127 = F_18 ( V_24 , V_82 ,
F_39 ( V_164 , V_167 ) ) ;
F_37 ( V_82 ) ;
return V_127 ;
}
static int F_46 ( unsigned char * V_168 , int V_169 , int V_122 )
{
unsigned char V_170 [] = { 0x1 , 0xa , 0xc0 , 11 , 240 , 0 , 0 , 0 ,
5 , 0 , 0xff , 0xff } ;
memcpy ( V_168 , V_170 , sizeof( V_170 ) ) ;
if ( 1 == V_169 )
memset ( V_168 + 2 , 0 , sizeof( V_170 ) - 2 ) ;
return sizeof( V_170 ) ;
}
static int F_47 ( unsigned char * V_168 , int V_169 , int V_122 )
{
unsigned char V_171 [] = { 0x2 , 0xe , 128 , 128 , 0 , 10 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_168 , V_171 , sizeof( V_171 ) ) ;
if ( 1 == V_169 )
memset ( V_168 + 2 , 0 , sizeof( V_171 ) - 2 ) ;
return sizeof( V_171 ) ;
}
static int F_48 ( unsigned char * V_168 , int V_169 , int V_122 )
{
unsigned char V_172 [] = { 0x3 , 0x16 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0x40 , 0 , 0 , 0 } ;
memcpy ( V_168 , V_172 , sizeof( V_172 ) ) ;
V_168 [ 10 ] = ( V_173 >> 8 ) & 0xff ;
V_168 [ 11 ] = V_173 & 0xff ;
V_168 [ 12 ] = ( V_8 >> 8 ) & 0xff ;
V_168 [ 13 ] = V_8 & 0xff ;
if ( V_145 )
V_168 [ 20 ] |= 0x20 ;
if ( 1 == V_169 )
memset ( V_168 + 2 , 0 , sizeof( V_172 ) - 2 ) ;
return sizeof( V_172 ) ;
}
static int F_49 ( unsigned char * V_168 , int V_169 , int V_122 )
{
unsigned char V_174 [] = { 0x4 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
unsigned char V_175 [] = { 0x8 , 18 , 0x14 , 0 , 0xff , 0xff , 0 , 0 ,
0xff , 0xff , 0xff , 0xff , 0x80 , 0x14 , 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( V_176 & V_36 )
V_177 [ 2 ] &= ~ 0x4 ;
memcpy ( V_168 , V_177 , sizeof( V_177 ) ) ;
if ( 1 == V_169 )
memcpy ( V_168 + 2 , V_174 , sizeof( V_174 ) ) ;
else if ( 2 == V_169 )
memcpy ( V_168 , V_175 , sizeof( V_175 ) ) ;
return sizeof( V_177 ) ;
}
static int F_50 ( unsigned char * V_168 , int V_169 , int V_122 )
{
unsigned char V_178 [] = { 0x6 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ;
unsigned char V_179 [] = { 0xa , 10 , 2 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x2 , 0x4b } ;
if ( V_34 )
V_180 [ 2 ] |= 0x4 ;
else
V_180 [ 2 ] &= ~ 0x4 ;
if ( V_181 )
V_180 [ 5 ] |= 0x80 ;
memcpy ( V_168 , V_180 , sizeof( V_180 ) ) ;
if ( 1 == V_169 )
memcpy ( V_168 + 2 , V_178 , sizeof( V_178 ) ) ;
else if ( 2 == V_169 )
memcpy ( V_168 , V_179 , sizeof( V_179 ) ) ;
return sizeof( V_180 ) ;
}
static int F_51 ( unsigned char * V_168 , int V_169 , int V_122 )
{
unsigned char V_182 [] = { 0x4 , 0xf , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
unsigned char V_183 [] = { 0x1c , 0xa , 0x08 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
memcpy ( V_168 , V_150 , sizeof( V_150 ) ) ;
if ( 1 == V_169 )
memcpy ( V_168 + 2 , V_182 , sizeof( V_182 ) ) ;
else if ( 2 == V_169 )
memcpy ( V_168 , V_183 , sizeof( V_183 ) ) ;
return sizeof( V_150 ) ;
}
static int F_52 ( unsigned char * V_168 , int V_169 , int V_122 )
{
unsigned char V_184 [] = { 0x19 , 0x6 ,
0x6 , 0x0 , 0x7 , 0xd0 , 0x0 , 0x0 } ;
memcpy ( V_168 , V_184 , sizeof( V_184 ) ) ;
if ( 1 == V_169 )
memset ( V_168 + 2 , 0 , sizeof( V_184 ) - 2 ) ;
return sizeof( V_184 ) ;
}
static int F_53 ( unsigned char * V_168 , int V_169 , int V_122 ,
int V_97 )
{
unsigned char V_185 [] = { 0x59 , 0x1 , 0 , 0x64 , 0 , 0x6 , 0 , 2 ,
0 , 0 , 0 , 0 , 0x10 , 0x9 , 0x8 , 0x0 ,
0x52 , 0x22 , 0x22 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 ,
0x51 , 0x11 , 0x11 , 0x10 , 0x0 , 0x0 , 0x0 , 0x1 ,
0x2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0x88 , 0x99 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 1 , 0 , 0 , 0x10 , 0x9 , 0x8 , 0x0 ,
0x52 , 0x22 , 0x22 , 0x20 , 0x0 , 0x0 , 0x0 , 0x0 ,
0x51 , 0x11 , 0x11 , 0x10 , 0x0 , 0x0 , 0x0 , 0x1 ,
0x3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0x88 , 0x99 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
int V_101 , V_110 ;
V_101 = V_97 + 1 ;
V_110 = V_101 + 1 ;
memcpy ( V_168 , V_185 , sizeof( V_185 ) ) ;
V_168 [ 20 ] = ( V_101 >> 24 ) ;
V_168 [ 21 ] = ( V_101 >> 16 ) & 0xff ;
V_168 [ 22 ] = ( V_101 >> 8 ) & 0xff ;
V_168 [ 23 ] = V_101 & 0xff ;
V_168 [ 48 + 20 ] = ( V_110 >> 24 ) ;
V_168 [ 48 + 21 ] = ( V_110 >> 16 ) & 0xff ;
V_168 [ 48 + 22 ] = ( V_110 >> 8 ) & 0xff ;
V_168 [ 48 + 23 ] = V_110 & 0xff ;
if ( 1 == V_169 )
memset ( V_168 + 4 , 0 , sizeof( V_185 ) - 4 ) ;
return sizeof( V_185 ) ;
}
static int F_54 ( unsigned char * V_168 , int V_169 )
{
unsigned char V_186 [] = { 0x59 , 0x2 , 0 , 0xc , 0 , 0x6 , 0x10 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
memcpy ( V_168 , V_186 , sizeof( V_186 ) ) ;
if ( 1 == V_169 )
memset ( V_168 + 4 , 0 , sizeof( V_186 ) - 4 ) ;
return sizeof( V_186 ) ;
}
static int F_55 ( struct V_23 * V_24 , int V_122 ,
struct V_61 * V_62 )
{
unsigned char V_187 , V_188 ;
int V_169 , V_189 , V_190 , V_191 ;
unsigned char V_192 ;
int V_63 , V_125 , V_193 , V_194 , V_138 , V_154 , V_97 ;
unsigned char * V_195 ;
unsigned char V_82 [ V_196 ] ;
unsigned char * V_39 = ( unsigned char * ) V_24 -> V_124 ;
V_154 = F_14 ( V_24 , V_156 , V_62 ) ;
if ( V_154 )
return V_154 ;
V_187 = ! ! ( V_39 [ 1 ] & 0x8 ) ;
V_169 = ( V_39 [ 2 ] & 0xc0 ) >> 6 ;
V_189 = V_39 [ 2 ] & 0x3f ;
V_190 = V_39 [ 3 ] ;
V_193 = ( V_197 == V_39 [ 0 ] ) ;
V_188 = V_193 ? 0 : ! ! ( V_39 [ 1 ] & 0x10 ) ;
if ( ( 0 == V_134 ) && ( 0 == V_187 ) )
V_191 = V_188 ? 16 : 8 ;
else
V_191 = 0 ;
V_125 = V_193 ? V_39 [ 4 ] : ( ( V_39 [ 7 ] << 8 ) | V_39 [ 8 ] ) ;
memset ( V_82 , 0 , V_196 ) ;
if ( 0x3 == V_169 ) {
F_9 ( V_24 , V_135 , V_198 , 0 ) ;
return V_77 ;
}
V_97 = ( ( V_62 -> V_13 -> V_17 -> V_140 + 1 ) * 2000 ) +
( V_62 -> V_122 * 1000 ) - 3 ;
if ( 0 == V_134 )
V_192 = ( F_56 ( V_122 ) ? 0x80 : 0x0 ) | 0x10 ;
else
V_192 = 0x0 ;
if ( V_193 ) {
V_82 [ 2 ] = V_192 ;
V_82 [ 3 ] = V_191 ;
V_194 = 4 ;
} else {
V_82 [ 3 ] = V_192 ;
if ( 16 == V_191 )
V_82 [ 4 ] = 0x1 ;
V_82 [ 7 ] = V_191 ;
V_194 = 8 ;
}
V_195 = V_82 + V_194 ;
if ( ( V_191 > 0 ) && ( ! V_160 ) )
V_160 = F_42 () ;
if ( 8 == V_191 ) {
if ( V_160 > 0xfffffffe ) {
V_195 [ 0 ] = 0xff ;
V_195 [ 1 ] = 0xff ;
V_195 [ 2 ] = 0xff ;
V_195 [ 3 ] = 0xff ;
} else {
V_195 [ 0 ] = ( V_160 >> 24 ) & 0xff ;
V_195 [ 1 ] = ( V_160 >> 16 ) & 0xff ;
V_195 [ 2 ] = ( V_160 >> 8 ) & 0xff ;
V_195 [ 3 ] = V_160 & 0xff ;
}
V_195 [ 6 ] = ( V_8 >> 8 ) & 0xff ;
V_195 [ 7 ] = V_8 & 0xff ;
V_194 += V_191 ;
V_195 = V_82 + V_194 ;
} else if ( 16 == V_191 ) {
unsigned long long V_159 = V_160 ;
for ( V_63 = 0 ; V_63 < 8 ; ++ V_63 , V_159 >>= 8 )
V_195 [ 7 - V_63 ] = V_159 & 0xff ;
V_195 [ 12 ] = ( V_8 >> 24 ) & 0xff ;
V_195 [ 13 ] = ( V_8 >> 16 ) & 0xff ;
V_195 [ 14 ] = ( V_8 >> 8 ) & 0xff ;
V_195 [ 15 ] = V_8 & 0xff ;
V_194 += V_191 ;
V_195 = V_82 + V_194 ;
}
if ( ( V_190 > 0x0 ) && ( V_190 < 0xff ) && ( 0x19 != V_189 ) ) {
F_9 ( V_24 , V_135 , V_136 ,
0 ) ;
return V_77 ;
}
switch ( V_189 ) {
case 0x1 :
V_138 = F_46 ( V_195 , V_169 , V_122 ) ;
V_194 += V_138 ;
break;
case 0x2 :
V_138 = F_47 ( V_195 , V_169 , V_122 ) ;
V_194 += V_138 ;
break;
case 0x3 :
V_138 = F_48 ( V_195 , V_169 , V_122 ) ;
V_194 += V_138 ;
break;
case 0x8 :
V_138 = F_49 ( V_195 , V_169 , V_122 ) ;
V_194 += V_138 ;
break;
case 0xa :
V_138 = F_50 ( V_195 , V_169 , V_122 ) ;
V_194 += V_138 ;
break;
case 0x19 :
if ( ( V_190 > 0x2 ) && ( V_190 < 0xff ) ) {
F_9 ( V_24 , V_135 ,
V_136 , 0 ) ;
return V_77 ;
}
V_138 = 0 ;
if ( ( 0x0 == V_190 ) || ( 0xff == V_190 ) )
V_138 += F_52 ( V_195 + V_138 , V_169 , V_122 ) ;
if ( ( 0x1 == V_190 ) || ( 0xff == V_190 ) )
V_138 += F_53 ( V_195 + V_138 , V_169 , V_122 ,
V_97 ) ;
if ( ( 0x2 == V_190 ) || ( 0xff == V_190 ) )
V_138 += F_54 ( V_195 + V_138 , V_169 ) ;
V_194 += V_138 ;
break;
case 0x1c :
V_138 = F_51 ( V_195 , V_169 , V_122 ) ;
V_194 += V_138 ;
break;
case 0x3f :
if ( ( 0 == V_190 ) || ( 0xff == V_190 ) ) {
V_138 = F_46 ( V_195 , V_169 , V_122 ) ;
V_138 += F_47 ( V_195 + V_138 , V_169 , V_122 ) ;
V_138 += F_48 ( V_195 + V_138 , V_169 , V_122 ) ;
V_138 += F_49 ( V_195 + V_138 , V_169 , V_122 ) ;
V_138 += F_50 ( V_195 + V_138 , V_169 , V_122 ) ;
V_138 += F_52 ( V_195 + V_138 , V_169 , V_122 ) ;
if ( 0xff == V_190 ) {
V_138 += F_53 ( V_195 + V_138 , V_169 ,
V_122 , V_97 ) ;
V_138 += F_54 ( V_195 + V_138 , V_169 ) ;
}
V_138 += F_51 ( V_195 + V_138 , V_169 , V_122 ) ;
} else {
F_9 ( V_24 , V_135 ,
V_136 , 0 ) ;
return V_77 ;
}
V_194 += V_138 ;
break;
default:
F_9 ( V_24 , V_135 , V_136 ,
0 ) ;
return V_77 ;
}
if ( V_193 )
V_82 [ 0 ] = V_194 - 1 ;
else {
V_82 [ 0 ] = ( ( V_194 - 2 ) >> 8 ) & 0xff ;
V_82 [ 1 ] = ( V_194 - 2 ) & 0xff ;
}
return F_18 ( V_24 , V_82 , F_39 ( V_125 , V_194 ) ) ;
}
static int F_57 ( struct V_23 * V_24 , int V_199 ,
struct V_61 * V_62 )
{
int V_200 , V_201 , V_202 , V_203 , V_191 , V_204 , V_205 , V_206 ;
int V_207 , V_208 , V_154 , V_209 ;
unsigned char V_82 [ V_210 ] ;
unsigned char * V_39 = ( unsigned char * ) V_24 -> V_124 ;
V_154 = F_14 ( V_24 , V_156 , V_62 ) ;
if ( V_154 )
return V_154 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_200 = V_39 [ 1 ] & 0x10 ;
V_201 = V_39 [ 1 ] & 0x1 ;
V_207 = V_199 ? V_39 [ 4 ] : ( ( V_39 [ 7 ] << 8 ) + V_39 [ 8 ] ) ;
if ( ( 0 == V_200 ) || V_201 || ( V_207 > V_210 ) ) {
F_9 ( V_24 , V_135 ,
V_136 , 0 ) ;
return V_77 ;
}
V_208 = F_23 ( V_24 , V_82 , V_207 ) ;
if ( - 1 == V_208 )
return ( V_90 << 16 ) ;
else if ( ( V_208 < V_207 ) &&
( V_35 & V_36 ) )
F_10 ( V_37 , V_24 -> V_31 ,
L_19 ,
V_32 , V_207 , V_208 ) ;
V_203 = V_199 ? ( V_82 [ 0 ] + 1 ) : ( ( V_82 [ 0 ] << 8 ) + V_82 [ 1 ] + 2 ) ;
V_191 = V_199 ? V_82 [ 3 ] : ( ( V_82 [ 6 ] << 8 ) + V_82 [ 7 ] ) ;
if ( V_203 > 2 ) {
F_9 ( V_24 , V_135 ,
V_211 , 0 ) ;
return V_77 ;
}
V_204 = V_191 + ( V_199 ? 4 : 8 ) ;
V_209 = V_82 [ V_204 ] & 0x3f ;
V_202 = ! ! ( V_82 [ V_204 ] & 0x80 ) ;
if ( V_202 ) {
F_9 ( V_24 , V_135 ,
V_211 , 0 ) ;
return V_77 ;
}
V_205 = ! ! ( V_82 [ V_204 ] & 0x40 ) ;
V_206 = V_205 ? ( ( V_82 [ V_204 + 2 ] << 8 ) + V_82 [ V_204 + 3 ] + 4 ) :
( V_82 [ V_204 + 1 ] + 2 ) ;
if ( ( V_206 + V_204 ) > V_207 ) {
F_9 ( V_24 , V_135 ,
V_212 , 0 ) ;
return V_77 ;
}
switch ( V_209 ) {
case 0x8 :
if ( V_177 [ 1 ] == V_82 [ V_204 + 1 ] ) {
memcpy ( V_177 + 2 , V_82 + V_204 + 2 ,
sizeof( V_177 ) - 2 ) ;
goto V_213;
}
break;
case 0xa :
if ( V_180 [ 1 ] == V_82 [ V_204 + 1 ] ) {
memcpy ( V_180 + 2 , V_82 + V_204 + 2 ,
sizeof( V_180 ) - 2 ) ;
V_34 = ! ! ( V_180 [ 2 ] & 0x4 ) ;
goto V_213;
}
break;
case 0x1c :
if ( V_150 [ 1 ] == V_82 [ V_204 + 1 ] ) {
memcpy ( V_150 + 2 , V_82 + V_204 + 2 ,
sizeof( V_150 ) - 2 ) ;
goto V_213;
}
break;
default:
break;
}
F_9 ( V_24 , V_135 ,
V_211 , 0 ) ;
return V_77 ;
V_213:
F_58 ( V_74 , V_62 -> V_65 ) ;
return 0 ;
}
static int F_59 ( unsigned char * V_82 )
{
unsigned char V_214 [] = { 0x0 , 0x0 , 0x3 , 0x2 , 0x0 , 38 ,
0x0 , 0x1 , 0x3 , 0x2 , 0x0 , 65 ,
} ;
memcpy ( V_82 , V_214 , sizeof( V_214 ) ) ;
return sizeof( V_214 ) ;
}
static int F_60 ( unsigned char * V_82 )
{
unsigned char V_215 [] = { 0x0 , 0x0 , 0x3 , 0x3 , 0x0 , 0x0 , 38 ,
} ;
memcpy ( V_82 , V_215 , sizeof( V_215 ) ) ;
if ( V_150 [ 2 ] & 0x4 ) {
V_82 [ 4 ] = V_151 ;
V_82 [ 5 ] = 0xff ;
}
return sizeof( V_215 ) ;
}
static int F_61 ( struct V_23 * V_24 ,
struct V_61 * V_62 )
{
int V_216 , V_201 , V_169 , V_189 , V_190 , V_125 , V_154 , V_138 , V_126 ;
unsigned char V_82 [ V_217 ] ;
unsigned char * V_39 = ( unsigned char * ) V_24 -> V_124 ;
V_154 = F_14 ( V_24 , V_156 , V_62 ) ;
if ( V_154 )
return V_154 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_216 = V_39 [ 1 ] & 0x2 ;
V_201 = V_39 [ 1 ] & 0x1 ;
if ( V_216 || V_201 ) {
F_9 ( V_24 , V_135 ,
V_136 , 0 ) ;
return V_77 ;
}
V_169 = ( V_39 [ 2 ] & 0xc0 ) >> 6 ;
V_189 = V_39 [ 2 ] & 0x3f ;
V_190 = V_39 [ 3 ] & 0xff ;
V_125 = ( V_39 [ 7 ] << 8 ) + V_39 [ 8 ] ;
V_82 [ 0 ] = V_189 ;
if ( 0 == V_190 ) {
switch ( V_189 ) {
case 0x0 :
V_126 = 4 ;
V_82 [ V_126 ++ ] = 0x0 ;
V_82 [ V_126 ++ ] = 0xd ;
V_82 [ V_126 ++ ] = 0x2f ;
V_82 [ 3 ] = V_126 - 4 ;
break;
case 0xd :
V_82 [ 3 ] = F_59 ( V_82 + 4 ) ;
break;
case 0x2f :
V_82 [ 3 ] = F_60 ( V_82 + 4 ) ;
break;
default:
F_9 ( V_24 , V_135 ,
V_136 , 0 ) ;
return V_77 ;
}
} else if ( 0xff == V_190 ) {
V_82 [ 0 ] |= 0x40 ;
V_82 [ 1 ] = V_190 ;
switch ( V_189 ) {
case 0x0 :
V_126 = 4 ;
V_82 [ V_126 ++ ] = 0x0 ;
V_82 [ V_126 ++ ] = 0x0 ;
V_82 [ V_126 ++ ] = 0x0 ;
V_82 [ V_126 ++ ] = 0xff ;
V_82 [ V_126 ++ ] = 0xd ;
V_82 [ V_126 ++ ] = 0x0 ;
V_82 [ V_126 ++ ] = 0x2f ;
V_82 [ V_126 ++ ] = 0x0 ;
V_82 [ 3 ] = V_126 - 4 ;
break;
case 0xd :
V_126 = 4 ;
V_82 [ V_126 ++ ] = 0xd ;
V_82 [ V_126 ++ ] = 0x0 ;
V_82 [ 3 ] = V_126 - 4 ;
break;
case 0x2f :
V_126 = 4 ;
V_82 [ V_126 ++ ] = 0x2f ;
V_82 [ V_126 ++ ] = 0x0 ;
V_82 [ 3 ] = V_126 - 4 ;
break;
default:
F_9 ( V_24 , V_135 ,
V_136 , 0 ) ;
return V_77 ;
}
} else {
F_9 ( V_24 , V_135 ,
V_136 , 0 ) ;
return V_77 ;
}
V_138 = F_39 ( ( ( V_82 [ 2 ] << 8 ) + V_82 [ 3 ] ) + 4 , V_125 ) ;
return F_18 ( V_24 , V_82 ,
F_39 ( V_138 , V_128 ) ) ;
}
static int F_62 ( struct V_23 * V_24 ,
unsigned long long V_5 , unsigned int V_40 )
{
if ( V_5 + V_40 > V_160 ) {
F_9 ( V_24 , V_135 , V_218 , 0 ) ;
return V_77 ;
}
if ( V_40 > V_6 ) {
F_9 ( V_24 , V_135 , V_136 , 0 ) ;
return V_77 ;
}
return 0 ;
}
static int F_63 ( struct V_23 * V_219 ,
unsigned long long V_5 , unsigned int V_40 , int V_220 )
{
int V_127 ;
unsigned long long V_221 , V_222 = 0 ;
struct V_85 * V_86 ;
enum V_223 V_224 ;
T_4 (* F_64)( struct V_225 * , unsigned int , void * , T_4 ,
T_5 );
if ( V_220 ) {
V_86 = F_65 ( V_219 ) ;
V_224 = V_95 ;
F_64 = V_226 ;
} else {
V_86 = F_19 ( V_219 ) ;
V_224 = V_89 ;
F_64 = V_227 ;
}
if ( ! V_86 -> V_87 )
return 0 ;
if ( ! ( F_20 ( V_219 ) || V_219 -> V_88 == V_224 ) )
return - 1 ;
V_221 = F_3 ( V_5 , V_6 ) ;
if ( V_221 + V_40 > V_6 )
V_222 = V_221 + V_40 - V_6 ;
V_127 = F_64 ( V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_7 + ( V_221 * V_8 ) ,
( V_40 - V_222 ) * V_8 , 0 ) ;
if ( V_127 != ( V_40 - V_222 ) * V_8 )
return V_127 ;
if ( V_222 ) {
V_127 += F_64 ( V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_7 , V_222 * V_8 ,
( V_40 - V_222 ) * V_8 ) ;
}
return V_127 ;
}
static T_6 F_66 ( const void * V_228 , int V_138 )
{
T_6 V_229 ;
if ( V_230 )
V_229 = ( V_231 T_6 ) F_67 ( V_228 , V_138 ) ;
else
V_229 = F_68 ( F_69 ( V_228 , V_138 ) ) ;
return V_229 ;
}
static int F_70 ( struct V_9 * V_232 , const void * V_233 ,
T_1 V_10 , T_2 V_41 )
{
T_6 V_229 = F_66 ( V_233 , V_8 ) ;
if ( V_232 -> V_234 != V_229 ) {
F_71 ( L_20 ,
V_32 ,
( unsigned long ) V_10 ,
F_72 ( V_232 -> V_234 ) ,
F_72 ( V_229 ) ) ;
return 0x01 ;
}
if ( V_143 == V_235 &&
F_73 ( V_232 -> V_236 ) != ( V_10 & 0xffffffff ) ) {
F_71 ( L_21 ,
V_32 , ( unsigned long ) V_10 ) ;
return 0x03 ;
}
if ( V_143 == V_237 &&
F_73 ( V_232 -> V_236 ) != V_41 ) {
F_71 ( L_21 ,
V_32 , ( unsigned long ) V_10 ) ;
return 0x03 ;
}
return 0 ;
}
static void F_74 ( struct V_23 * V_59 , T_1 V_10 ,
unsigned int V_238 , bool V_239 )
{
T_4 V_94 ;
void * V_240 ;
const void * V_241 = V_11 + V_6 ;
struct V_242 V_243 ;
V_94 = V_238 * sizeof( * V_11 ) ;
F_75 ( & V_243 , F_76 ( V_59 ) ,
F_77 ( V_59 ) , V_244 |
( V_239 ? V_245 : V_246 ) ) ;
while ( F_78 ( & V_243 ) && V_94 > 0 ) {
T_4 V_138 = F_39 ( V_243 . V_87 , V_94 ) ;
void * V_155 = F_4 ( V_10 ) ;
T_4 V_222 = 0 ;
if ( V_241 < V_155 + V_138 )
V_222 = V_155 + V_138 - V_241 ;
V_240 = V_243 . V_247 ;
if ( V_239 )
memcpy ( V_240 , V_155 , V_138 - V_222 ) ;
else
memcpy ( V_155 , V_240 , V_138 - V_222 ) ;
if ( V_222 ) {
if ( V_239 )
memcpy ( V_240 + V_138 - V_222 , V_11 , V_222 ) ;
else
memcpy ( V_11 , V_240 + V_138 - V_222 , V_222 ) ;
}
V_10 += V_138 / sizeof( * V_11 ) ;
V_94 -= V_138 ;
}
F_79 ( & V_243 ) ;
}
static int F_80 ( struct V_23 * V_59 , T_1 V_248 ,
unsigned int V_238 , T_2 V_41 )
{
unsigned int V_249 ;
struct V_9 * V_232 ;
T_1 V_10 ;
for ( V_249 = 0 ; V_249 < V_238 ; V_249 ++ , V_41 ++ ) {
int V_127 ;
V_10 = V_248 + V_249 ;
V_232 = F_4 ( V_10 ) ;
if ( V_232 -> V_250 == F_68 ( 0xffff ) )
continue;
V_127 = F_70 ( V_232 , F_2 ( V_10 ) , V_10 , V_41 ) ;
if ( V_127 ) {
V_251 ++ ;
return V_127 ;
}
}
F_74 ( V_59 , V_248 , V_238 , true ) ;
V_252 ++ ;
return 0 ;
}
static int F_81 ( struct V_23 * V_59 , unsigned long long V_5 ,
unsigned int V_40 , T_2 V_41 )
{
unsigned long V_253 ;
int V_127 ;
V_127 = F_62 ( V_59 , V_5 , V_40 ) ;
if ( V_127 )
return V_127 ;
if ( ( V_254 & V_36 ) &&
( V_5 <= ( V_255 + V_256 - 1 ) ) &&
( ( V_5 + V_40 ) > V_255 ) ) {
F_9 ( V_59 , V_257 , V_258 , 0 ) ;
if ( 0x70 == ( V_59 -> V_29 [ 0 ] & 0x7f ) ) {
V_59 -> V_29 [ 0 ] |= 0x80 ;
V_127 = ( V_5 < V_255 )
? V_255 : ( int ) V_5 ;
V_59 -> V_29 [ 3 ] = ( V_127 >> 24 ) & 0xff ;
V_59 -> V_29 [ 4 ] = ( V_127 >> 16 ) & 0xff ;
V_59 -> V_29 [ 5 ] = ( V_127 >> 8 ) & 0xff ;
V_59 -> V_29 [ 6 ] = V_127 & 0xff ;
}
F_82 ( V_59 , F_22 ( V_59 ) ) ;
return V_77 ;
}
F_83 ( & V_259 , V_253 ) ;
if ( V_260 && F_77 ( V_59 ) ) {
int V_261 = F_80 ( V_59 , V_5 , V_40 , V_41 ) ;
if ( V_261 ) {
F_84 ( & V_259 , V_253 ) ;
F_9 ( V_59 , V_262 , 0x10 , V_261 ) ;
return V_263 ;
}
}
V_127 = F_63 ( V_59 , V_5 , V_40 , 0 ) ;
F_84 ( & V_259 , V_253 ) ;
if ( V_127 == - 1 )
return V_90 << 16 ;
F_19 ( V_59 ) -> V_94 = F_22 ( V_59 ) - V_127 ;
return 0 ;
}
void F_85 ( unsigned char * V_228 , int V_138 )
{
int V_249 , V_264 , V_126 ;
F_71 ( L_22 ) ;
for ( V_249 = 0 ; V_249 < V_138 ; V_249 += 16 ) {
char V_102 [ 128 ] ;
for ( V_264 = 0 , V_126 = 0 ; V_264 < 16 ; V_264 ++ ) {
unsigned char V_265 = V_228 [ V_249 + V_264 ] ;
if ( V_265 >= 0x20 && V_265 < 0x7e )
V_126 += F_38 ( V_102 + V_126 , sizeof( V_102 ) - V_126 ,
L_23 , V_228 [ V_249 + V_264 ] ) ;
else
V_126 += F_38 ( V_102 + V_126 , sizeof( V_102 ) - V_126 ,
L_24 , V_228 [ V_249 + V_264 ] ) ;
}
F_71 ( L_25 , V_249 , V_102 ) ;
}
}
static int F_86 ( struct V_23 * V_59 , T_1 V_248 ,
unsigned int V_238 , T_2 V_41 )
{
int V_127 ;
struct V_9 * V_232 ;
void * V_266 ;
T_1 V_10 = V_248 ;
int V_267 ;
int V_268 ;
struct V_242 V_269 ;
struct V_242 V_270 ;
F_87 ( F_88 ( V_59 ) == 0 ) ;
F_87 ( F_77 ( V_59 ) == 0 ) ;
F_75 ( & V_270 , F_76 ( V_59 ) ,
F_77 ( V_59 ) ,
V_244 | V_246 ) ;
F_75 ( & V_269 , F_89 ( V_59 ) , F_88 ( V_59 ) ,
V_244 | V_246 ) ;
while ( F_78 ( & V_270 ) ) {
V_268 = 0 ;
if ( F_90 ( ! F_78 ( & V_269 ) ) ) {
V_127 = 0x01 ;
goto V_271;
}
for ( V_267 = 0 ; V_267 < V_270 . V_87 ;
V_267 += sizeof( struct V_9 ) ) {
if ( V_268 >= V_269 . V_87 ) {
if ( F_90 ( ! F_78 ( & V_269 ) ) ) {
V_127 = 0x01 ;
goto V_271;
}
V_268 = 0 ;
}
V_232 = V_270 . V_247 + V_267 ;
V_266 = V_269 . V_247 + V_268 ;
V_127 = F_70 ( V_232 , V_266 , V_10 , V_41 ) ;
if ( V_127 ) {
F_85 ( V_266 , V_8 ) ;
goto V_271;
}
V_10 ++ ;
V_41 ++ ;
V_268 += V_8 ;
}
V_269 . V_272 = V_268 ;
F_79 ( & V_269 ) ;
}
F_79 ( & V_270 ) ;
F_74 ( V_59 , V_248 , V_238 , false ) ;
V_273 ++ ;
return 0 ;
V_271:
V_251 ++ ;
F_79 ( & V_269 ) ;
F_79 ( & V_270 ) ;
return V_127 ;
}
static unsigned long F_91 ( T_1 V_5 )
{
if ( V_118 ) {
V_5 += V_119 -
V_118 ;
}
F_3 ( V_5 , V_119 ) ;
return V_5 ;
}
static T_1 F_92 ( unsigned long V_274 )
{
T_1 V_5 = V_274 * V_119 ;
if ( V_118 ) {
V_5 -= V_119 -
V_118 ;
}
return V_5 ;
}
static unsigned int F_93 ( T_1 V_5 , unsigned int * V_40 )
{
T_1 V_275 ;
unsigned int V_276 ;
unsigned long V_274 ;
unsigned long V_277 ;
V_274 = F_91 ( V_5 ) ;
V_276 = F_94 ( V_274 , V_278 ) ;
if ( V_276 )
V_277 = F_95 ( V_278 , V_279 , V_274 ) ;
else
V_277 = F_96 ( V_278 , V_279 , V_274 ) ;
V_275 = F_97 ( T_1 , V_6 , F_92 ( V_277 ) ) ;
* V_40 = V_275 - V_5 ;
return V_276 ;
}
static void F_98 ( T_1 V_5 , unsigned int V_138 )
{
T_1 V_275 = V_5 + V_138 ;
while ( V_5 < V_275 ) {
unsigned long V_274 = F_91 ( V_5 ) ;
if ( V_274 < V_279 )
F_58 ( V_274 , V_278 ) ;
V_5 = F_92 ( V_274 + 1 ) ;
}
}
static void F_99 ( T_1 V_5 , unsigned int V_138 )
{
T_1 V_275 = V_5 + V_138 ;
while ( V_5 < V_275 ) {
unsigned long V_274 = F_91 ( V_5 ) ;
if ( V_5 == F_92 ( V_274 ) &&
V_5 + V_119 <= V_275 &&
V_274 < V_279 ) {
F_17 ( V_274 , V_278 ) ;
if ( V_121 ) {
memset ( V_7 +
V_5 * V_8 , 0 ,
V_8 *
V_119 ) ;
}
if ( V_11 ) {
memset ( V_11 + V_5 , 0xff ,
sizeof( * V_11 ) *
V_119 ) ;
}
}
V_5 = F_92 ( V_274 + 1 ) ;
}
}
static int F_100 ( struct V_23 * V_59 , unsigned long long V_5 ,
unsigned int V_40 , T_2 V_41 )
{
unsigned long V_253 ;
int V_127 ;
V_127 = F_62 ( V_59 , V_5 , V_40 ) ;
if ( V_127 )
return V_127 ;
F_101 ( & V_259 , V_253 ) ;
if ( V_260 && F_77 ( V_59 ) ) {
int V_261 = F_86 ( V_59 , V_5 , V_40 , V_41 ) ;
if ( V_261 ) {
F_102 ( & V_259 , V_253 ) ;
F_9 ( V_59 , V_135 , 0x10 ,
V_261 ) ;
return V_263 ;
}
}
V_127 = F_63 ( V_59 , V_5 , V_40 , 1 ) ;
if ( F_1 () )
F_98 ( V_5 , V_40 ) ;
F_102 ( & V_259 , V_253 ) ;
if ( - 1 == V_127 )
return ( V_90 << 16 ) ;
else if ( ( V_127 < ( V_40 * V_8 ) ) &&
( V_35 & V_36 ) )
F_10 ( V_37 , V_59 -> V_31 ,
L_26 ,
V_38 , V_40 * V_8 , V_127 ) ;
return 0 ;
}
static int F_103 ( struct V_23 * V_219 , unsigned long long V_5 ,
unsigned int V_40 , T_2 V_41 , unsigned int V_280 )
{
unsigned long V_253 ;
unsigned long long V_249 ;
int V_127 ;
V_127 = F_62 ( V_219 , V_5 , V_40 ) ;
if ( V_127 )
return V_127 ;
if ( V_40 > V_120 ) {
F_9 ( V_219 , V_135 , V_136 ,
0 ) ;
return V_77 ;
}
F_101 ( & V_259 , V_253 ) ;
if ( V_280 && F_1 () ) {
F_99 ( V_5 , V_40 ) ;
goto V_271;
}
V_127 = F_23 ( V_219 ,
V_7 + ( V_5 * V_8 ) ,
V_8 ) ;
if ( - 1 == V_127 ) {
F_102 ( & V_259 , V_253 ) ;
return ( V_90 << 16 ) ;
} else if ( ( V_127 < ( V_40 * V_8 ) ) &&
( V_35 & V_36 ) )
F_10 ( V_37 , V_219 -> V_31 ,
L_27 ,
V_38 , L_28 ,
V_40 * V_8 , V_127 ) ;
for ( V_249 = 1 ; V_249 < V_40 ; V_249 ++ )
memcpy ( V_7 + ( ( V_5 + V_249 ) * V_8 ) ,
V_7 + ( V_5 * V_8 ) ,
V_8 ) ;
if ( F_1 () )
F_98 ( V_5 , V_40 ) ;
V_271:
F_102 ( & V_259 , V_253 ) ;
return 0 ;
}
static int F_104 ( struct V_23 * V_219 , struct V_61 * V_62 )
{
unsigned char * V_228 ;
struct V_281 * V_282 ;
unsigned int V_249 , V_283 , V_284 ;
int V_127 ;
unsigned long V_253 ;
V_127 = F_14 ( V_219 , V_156 , V_62 ) ;
if ( V_127 )
return V_127 ;
V_283 = F_105 ( & V_219 -> V_124 [ 7 ] ) ;
F_87 ( F_22 ( V_219 ) != V_283 ) ;
V_284 = ( V_283 - 8 ) / 16 ;
V_228 = F_106 ( F_22 ( V_219 ) , V_129 ) ;
if ( ! V_228 )
return V_77 ;
F_24 ( V_219 , V_228 , F_22 ( V_219 ) ) ;
F_87 ( F_105 ( & V_228 [ 0 ] ) != V_283 - 2 ) ;
F_87 ( F_105 ( & V_228 [ 2 ] ) != V_284 * 16 ) ;
V_282 = ( void * ) & V_228 [ 8 ] ;
F_101 ( & V_259 , V_253 ) ;
for ( V_249 = 0 ; V_249 < V_284 ; V_249 ++ ) {
unsigned long long V_5 = F_107 ( & V_282 [ V_249 ] . V_5 ) ;
unsigned int V_40 = F_108 ( & V_282 [ V_249 ] . V_285 ) ;
V_127 = F_62 ( V_219 , V_5 , V_40 ) ;
if ( V_127 )
goto V_271;
F_99 ( V_5 , V_40 ) ;
}
V_127 = 0 ;
V_271:
F_102 ( & V_259 , V_253 ) ;
F_37 ( V_228 ) ;
return V_127 ;
}
static int F_109 ( struct V_23 * V_219 ,
struct V_61 * V_62 )
{
unsigned long long V_5 ;
unsigned int V_125 , V_276 , V_40 ;
unsigned char V_82 [ V_286 ] ;
int V_127 ;
V_127 = F_14 ( V_219 , V_156 , V_62 ) ;
if ( V_127 )
return V_127 ;
V_5 = F_107 ( & V_219 -> V_124 [ 2 ] ) ;
V_125 = F_108 ( & V_219 -> V_124 [ 10 ] ) ;
if ( V_125 < 24 )
return 0 ;
V_127 = F_62 ( V_219 , V_5 , 1 ) ;
if ( V_127 )
return V_127 ;
V_276 = F_93 ( V_5 , & V_40 ) ;
memset ( V_82 , 0 , V_286 ) ;
F_31 ( 20 , & V_82 [ 0 ] ) ;
F_32 ( V_5 , & V_82 [ 8 ] ) ;
F_31 ( V_40 , & V_82 [ 16 ] ) ;
V_82 [ 20 ] = ! V_276 ;
return F_18 ( V_219 , V_82 , V_286 ) ;
}
static int F_110 ( struct V_23 * V_24 ,
struct V_61 * V_62 )
{
unsigned int V_125 ;
int V_287 , V_249 , V_288 , V_40 , V_126 ;
V_43 V_131 , V_133 ;
unsigned char * V_39 = ( unsigned char * ) V_24 -> V_124 ;
int V_289 = ( int ) V_39 [ 2 ] ;
struct V_290 * V_291 ;
unsigned char V_82 [ V_292 ] ;
unsigned char * V_293 ;
V_125 = V_39 [ 9 ] + ( V_39 [ 8 ] << 8 ) + ( V_39 [ 7 ] << 16 ) + ( V_39 [ 6 ] << 24 ) ;
if ( ( V_125 < 4 ) || ( V_289 > 2 ) ) {
F_9 ( V_24 , V_135 , V_136 ,
0 ) ;
return V_77 ;
}
memset ( V_82 , 0 , V_292 ) ;
V_287 = V_294 ;
if ( 1 == V_289 )
V_287 = 0 ;
else if ( V_132 && ( V_287 > 0 ) )
-- V_287 ;
V_131 = ( V_289 > 0 ) ? 1 : 0 ;
V_40 = V_287 + V_131 ;
V_82 [ 2 ] = ( ( sizeof( struct V_290 ) * V_40 ) >> 8 ) & 0xff ;
V_82 [ 3 ] = ( sizeof( struct V_290 ) * V_40 ) & 0xff ;
V_126 = F_39 ( ( int ) ( ( V_292 - 8 ) /
sizeof( struct V_290 ) ) , V_40 ) ;
if ( V_126 < V_40 ) {
V_131 = 0 ;
V_287 = V_126 ;
}
V_291 = (struct V_290 * ) & V_82 [ 8 ] ;
V_293 = V_82 + V_292 ;
for ( V_249 = 0 , V_133 = ( V_132 ? 1 : 0 ) ;
( ( V_249 < V_287 ) && ( ( unsigned char * ) ( V_291 + V_249 ) < V_293 ) ) ;
V_249 ++ , V_133 ++ ) {
V_288 = ( V_133 >> 8 ) & 0x3f ;
if ( V_288 )
V_291 [ V_249 ] . V_290 [ 0 ] =
( V_288 | ( V_295 << 6 ) ) ;
V_291 [ V_249 ] . V_290 [ 1 ] = V_133 & 0xff ;
}
if ( V_131 ) {
V_291 [ V_249 ] . V_290 [ 0 ] = ( V_22 >> 8 ) & 0xff ;
V_291 [ V_249 ] . V_290 [ 1 ] = V_22 & 0xff ;
V_249 ++ ;
}
V_125 = ( unsigned char * ) ( V_291 + V_249 ) - V_82 ;
return F_18 ( V_24 , V_82 ,
F_39 ( ( int ) V_125 , V_292 ) ) ;
}
static int F_111 ( struct V_23 * V_24 , unsigned long long V_5 ,
unsigned int V_40 , struct V_61 * V_62 )
{
int V_264 ;
unsigned char * V_296 , * V_228 ;
unsigned int V_194 ;
struct V_85 * V_86 = F_19 ( V_24 ) ;
struct V_242 V_243 ;
V_228 = F_106 ( F_22 ( V_24 ) , V_129 ) ;
if ( ! V_228 ) {
F_9 ( V_24 , V_80 ,
V_297 , 0 ) ;
return V_77 ;
}
F_24 ( V_24 , V_228 , F_22 ( V_24 ) ) ;
V_194 = 0 ;
F_75 ( & V_243 , V_86 -> V_91 . V_92 , V_86 -> V_91 . V_93 ,
V_244 | V_245 ) ;
while ( F_78 ( & V_243 ) ) {
V_296 = V_243 . V_247 ;
for ( V_264 = 0 ; V_264 < V_243 . V_87 ; V_264 ++ )
* ( V_296 + V_264 ) ^= * ( V_228 + V_194 + V_264 ) ;
V_194 += V_243 . V_87 ;
}
F_79 ( & V_243 ) ;
F_37 ( V_228 ) ;
return 0 ;
}
static void F_112 ( unsigned long V_298 )
{
int V_299 ;
int V_300 = 0 ;
unsigned long V_253 ;
struct V_301 * V_302 ;
struct V_23 * V_24 ;
struct V_61 * V_62 ;
F_113 ( & V_303 ) ;
V_299 = V_298 ;
if ( ( V_299 < 0 ) || ( V_299 >= V_304 ) ) {
F_71 ( L_29 , V_32 , V_299 ) ;
return;
}
F_114 ( & V_305 , V_253 ) ;
V_302 = & V_306 [ V_299 ] ;
V_24 = V_302 -> V_307 ;
if ( NULL == V_24 ) {
F_115 ( & V_305 , V_253 ) ;
F_71 ( L_30 , V_32 ) ;
return;
}
V_62 = (struct V_61 * ) V_24 -> V_31 -> V_308 ;
if ( V_62 )
F_116 ( & V_62 -> V_309 ) ;
else
F_71 ( L_31 , V_32 ) ;
if ( F_117 ( & V_310 ) > 0 )
V_300 = 1 ;
V_302 -> V_307 = NULL ;
if ( ! F_118 ( V_299 , V_311 ) ) {
F_115 ( & V_305 , V_253 ) ;
F_71 ( L_32 , V_32 ) ;
return;
}
if ( F_119 ( V_300 ) ) {
int V_63 , V_312 ;
V_312 = F_117 ( & V_310 ) ;
if ( V_299 >= V_312 ) {
F_115 ( & V_305 , V_253 ) ;
F_71 ( L_33 , V_32 , V_312 ) ;
return;
}
V_63 = F_120 ( V_311 , V_312 ) ;
if ( ( V_63 < V_313 ) || ( V_63 == V_312 ) )
F_121 ( & V_310 , 0 ) ;
else
F_121 ( & V_310 , V_63 + 1 ) ;
}
F_115 ( & V_305 , V_253 ) ;
V_24 -> V_314 ( V_24 ) ;
}
static enum V_315
F_122 ( struct V_316 * V_317 )
{
int V_299 ;
int V_300 = 0 ;
unsigned long V_253 ;
struct V_318 * V_319 = (struct V_318 * ) V_317 ;
struct V_301 * V_302 ;
struct V_23 * V_24 ;
struct V_61 * V_62 ;
F_113 ( & V_303 ) ;
V_299 = V_319 -> V_299 ;
if ( ( V_299 < 0 ) || ( V_299 >= V_304 ) ) {
F_71 ( L_29 , V_32 , V_299 ) ;
goto V_320;
}
F_114 ( & V_305 , V_253 ) ;
V_302 = & V_306 [ V_299 ] ;
V_24 = V_302 -> V_307 ;
if ( NULL == V_24 ) {
F_115 ( & V_305 , V_253 ) ;
F_71 ( L_30 , V_32 ) ;
goto V_320;
}
V_62 = (struct V_61 * ) V_24 -> V_31 -> V_308 ;
if ( V_62 )
F_116 ( & V_62 -> V_309 ) ;
else
F_71 ( L_31 , V_32 ) ;
if ( F_117 ( & V_310 ) > 0 )
V_300 = 1 ;
V_302 -> V_307 = NULL ;
if ( ! F_118 ( V_299 , V_311 ) ) {
F_115 ( & V_305 , V_253 ) ;
F_71 ( L_32 , V_32 ) ;
goto V_320;
}
if ( F_119 ( V_300 ) ) {
int V_63 , V_312 ;
V_312 = F_117 ( & V_310 ) ;
if ( V_299 >= V_312 ) {
F_115 ( & V_305 , V_253 ) ;
F_71 ( L_33 , V_32 , V_312 ) ;
goto V_320;
}
V_63 = F_120 ( V_311 , V_312 ) ;
if ( ( V_63 < V_313 ) || ( V_63 == V_312 ) )
F_121 ( & V_310 , 0 ) ;
else
F_121 ( & V_310 , V_63 + 1 ) ;
}
F_115 ( & V_305 , V_253 ) ;
V_24 -> V_314 ( V_24 ) ;
V_320:
return V_321 ;
}
static struct V_61 *
F_123 ( struct V_12 * V_13 , T_7 V_322 )
{
struct V_61 * V_62 ;
V_62 = F_36 ( sizeof( * V_62 ) , V_322 ) ;
if ( V_62 ) {
V_62 -> V_13 = V_13 ;
F_124 ( & V_62 -> V_323 , & V_13 -> V_324 ) ;
}
return V_62 ;
}
static struct V_61 * F_125 ( struct V_55 * V_325 )
{
struct V_12 * V_13 ;
struct V_61 * V_326 = NULL ;
struct V_61 * V_62 =
(struct V_61 * ) V_325 -> V_308 ;
if ( V_62 )
return V_62 ;
V_13 = * (struct V_12 * * ) F_126 ( V_325 -> V_327 ) ;
if ( ! V_13 ) {
F_71 ( L_34 , V_32 ) ;
return NULL ;
}
F_7 (devip, &sdbg_host->dev_info_list, dev_list) {
if ( ( V_62 -> V_328 ) && ( V_62 -> V_141 == V_325 -> V_141 ) &&
( V_62 -> V_122 == V_325 -> V_329 ) &&
( V_62 -> V_133 == V_325 -> V_133 ) )
return V_62 ;
else {
if ( ( ! V_62 -> V_328 ) && ( ! V_326 ) )
V_326 = V_62 ;
}
}
if ( ! V_326 ) {
V_326 = F_123 ( V_13 , V_129 ) ;
if ( ! V_326 ) {
F_127 ( V_30 L_35 ,
V_32 , __LINE__ ) ;
return NULL ;
}
}
V_326 -> V_141 = V_325 -> V_141 ;
V_326 -> V_122 = V_325 -> V_329 ;
V_326 -> V_133 = V_325 -> V_133 ;
V_326 -> V_13 = V_13 ;
F_121 ( & V_326 -> V_309 , 0 ) ;
F_58 ( V_68 , V_326 -> V_65 ) ;
V_326 -> V_328 = 1 ;
if ( V_325 -> V_133 == V_22 )
V_326 -> V_131 = V_22 & 0xff ;
return V_326 ;
}
static int F_128 ( struct V_55 * V_330 )
{
if ( V_35 & V_36 )
F_127 ( V_37 L_36 ,
V_330 -> V_327 -> V_140 , V_330 -> V_141 , V_330 -> V_329 , V_330 -> V_133 ) ;
F_129 ( V_331 , V_330 -> V_332 ) ;
return 0 ;
}
static int F_130 ( struct V_55 * V_330 )
{
struct V_61 * V_62 ;
if ( V_35 & V_36 )
F_127 ( V_37 L_37 ,
V_330 -> V_327 -> V_140 , V_330 -> V_141 , V_330 -> V_329 , V_330 -> V_133 ) ;
if ( V_330 -> V_327 -> V_333 != V_334 )
V_330 -> V_327 -> V_333 = V_334 ;
V_62 = F_125 ( V_330 ) ;
if ( NULL == V_62 )
return 1 ;
V_330 -> V_308 = V_62 ;
V_330 -> V_335 = 1 ;
if ( V_330 -> V_327 -> V_336 )
F_131 ( V_330 , V_337 ,
V_338 ) ;
F_132 ( V_330 -> V_332 , - 1U ) ;
if ( V_339 )
V_330 -> V_340 = 1 ;
return 0 ;
}
static void F_133 ( struct V_55 * V_330 )
{
struct V_61 * V_62 =
(struct V_61 * ) V_330 -> V_308 ;
if ( V_35 & V_36 )
F_127 ( V_37 L_38 ,
V_330 -> V_327 -> V_140 , V_330 -> V_141 , V_330 -> V_329 , V_330 -> V_133 ) ;
if ( V_62 ) {
V_62 -> V_328 = 0 ;
V_330 -> V_308 = NULL ;
}
}
static int F_134 ( struct V_23 * V_124 )
{
unsigned long V_253 ;
int V_63 , V_341 , V_342 ;
struct V_301 * V_302 ;
struct V_61 * V_62 ;
F_114 ( & V_305 , V_253 ) ;
V_341 = V_313 ;
V_342 = F_117 ( & V_310 ) ;
if ( V_342 > V_341 )
V_341 = V_342 ;
for ( V_63 = 0 ; V_63 < V_341 ; ++ V_63 ) {
if ( F_94 ( V_63 , V_311 ) ) {
V_302 = & V_306 [ V_63 ] ;
if ( V_124 == V_302 -> V_307 ) {
if ( V_343 > 0 ) {
if ( V_302 -> V_319 )
F_135 (
& V_302 -> V_319 -> V_344 ) ;
} else if ( V_345 > 0 ) {
if ( V_302 -> V_346 )
F_136 (
V_302 -> V_346 ) ;
} else if ( V_345 < 0 ) {
if ( V_302 -> V_347 )
F_137 ( V_302 -> V_347 ) ;
}
F_138 ( V_63 , V_311 ) ;
V_62 = (struct V_61 * )
V_124 -> V_31 -> V_308 ;
if ( V_62 )
F_116 ( & V_62 -> V_309 ) ;
V_302 -> V_307 = NULL ;
break;
}
}
}
F_115 ( & V_305 , V_253 ) ;
return ( V_63 < V_341 ) ? 1 : 0 ;
}
static void F_139 ( void )
{
unsigned long V_253 ;
int V_63 ;
struct V_301 * V_302 ;
struct V_61 * V_62 ;
F_114 ( & V_305 , V_253 ) ;
for ( V_63 = 0 ; V_63 < V_304 ; ++ V_63 ) {
if ( F_94 ( V_63 , V_311 ) ) {
V_302 = & V_306 [ V_63 ] ;
if ( V_302 -> V_307 ) {
if ( V_343 > 0 ) {
if ( V_302 -> V_319 )
F_135 (
& V_302 -> V_319 -> V_344 ) ;
} else if ( V_345 > 0 ) {
if ( V_302 -> V_346 )
F_136 (
V_302 -> V_346 ) ;
} else if ( V_345 < 0 ) {
if ( V_302 -> V_347 )
F_137 ( V_302 -> V_347 ) ;
}
F_138 ( V_63 , V_311 ) ;
V_62 = (struct V_61 * )
V_302 -> V_307 -> V_31 -> V_308 ;
if ( V_62 )
F_116 ( & V_62 -> V_309 ) ;
V_302 -> V_307 = NULL ;
}
}
}
F_115 ( & V_305 , V_253 ) ;
}
static void F_140 ( void )
{
unsigned long V_253 ;
int V_63 ;
struct V_301 * V_302 ;
F_114 ( & V_305 , V_253 ) ;
for ( V_63 = 0 ; V_63 < V_304 ; ++ V_63 ) {
V_302 = & V_306 [ V_63 ] ;
F_37 ( V_302 -> V_346 ) ;
V_302 -> V_346 = NULL ;
F_37 ( V_302 -> V_347 ) ;
V_302 -> V_347 = NULL ;
F_37 ( V_302 -> V_319 ) ;
V_302 -> V_319 = NULL ;
}
F_115 ( & V_305 , V_253 ) ;
}
static int F_141 ( struct V_23 * V_59 )
{
++ V_348 ;
if ( V_59 ) {
if ( V_59 -> V_31 &&
( V_349 & V_36 ) )
F_10 ( V_37 , V_59 -> V_31 , L_39 ,
V_32 ) ;
F_134 ( V_59 ) ;
}
return V_350 ;
}
static int F_142 ( struct V_23 * V_59 )
{
struct V_61 * V_62 ;
++ V_351 ;
if ( V_59 && V_59 -> V_31 ) {
struct V_55 * V_330 = V_59 -> V_31 ;
if ( V_349 & V_36 )
F_10 ( V_37 , V_330 , L_39 , V_32 ) ;
V_62 = F_125 ( V_330 ) ;
if ( V_62 )
F_58 ( V_68 , V_62 -> V_65 ) ;
}
return V_350 ;
}
static int F_143 ( struct V_23 * V_59 )
{
struct V_12 * V_13 ;
struct V_61 * V_62 ;
struct V_55 * V_330 ;
struct V_14 * V_352 ;
int V_63 = 0 ;
++ V_353 ;
if ( ! V_59 )
goto V_354;
V_330 = V_59 -> V_31 ;
if ( ! V_330 )
goto V_354;
if ( V_349 & V_36 )
F_10 ( V_37 , V_330 , L_39 , V_32 ) ;
V_352 = V_330 -> V_327 ;
if ( ! V_352 )
goto V_354;
V_13 = * (struct V_12 * * ) F_126 ( V_352 ) ;
if ( V_13 ) {
F_7 (devip,
&sdbg_host->dev_info_list,
dev_list)
if ( V_62 -> V_122 == V_330 -> V_329 ) {
F_58 ( V_72 , V_62 -> V_65 ) ;
++ V_63 ;
}
}
if ( V_355 & V_36 )
F_10 ( V_37 , V_330 ,
L_40 , V_32 , V_63 ) ;
V_354:
return V_350 ;
}
static int F_144 ( struct V_23 * V_59 )
{
struct V_12 * V_13 ;
struct V_61 * V_62 ;
struct V_55 * V_330 ;
struct V_14 * V_352 ;
int V_63 = 0 ;
++ V_356 ;
if ( ! ( V_59 && V_59 -> V_31 ) )
goto V_354;
V_330 = V_59 -> V_31 ;
if ( V_349 & V_36 )
F_10 ( V_37 , V_330 , L_39 , V_32 ) ;
V_352 = V_330 -> V_327 ;
if ( V_352 ) {
V_13 = * (struct V_12 * * ) F_126 ( V_352 ) ;
if ( V_13 ) {
F_7 (devip,
&sdbg_host->dev_info_list,
dev_list) {
F_58 ( V_72 , V_62 -> V_65 ) ;
++ V_63 ;
}
}
}
if ( V_355 & V_36 )
F_10 ( V_37 , V_330 ,
L_41 , V_32 , V_63 ) ;
V_354:
return V_350 ;
}
static int F_145 ( struct V_23 * V_59 )
{
struct V_12 * V_13 ;
struct V_61 * V_62 ;
int V_63 = 0 ;
++ V_357 ;
if ( ( V_59 -> V_31 ) && ( V_349 & V_36 ) )
F_10 ( V_37 , V_59 -> V_31 , L_39 , V_32 ) ;
F_6 ( & V_16 ) ;
F_7 (sdbg_host, &sdebug_host_list, host_list) {
F_7 (devip, &sdbg_host->dev_info_list,
dev_list) {
F_58 ( V_72 , V_62 -> V_65 ) ;
++ V_63 ;
}
}
F_8 ( & V_16 ) ;
F_139 () ;
if ( V_355 & V_36 )
F_10 ( V_37 , V_59 -> V_31 ,
L_42 , V_32 , V_63 ) ;
return V_350 ;
}
static void T_8 F_146 ( unsigned char * V_358 ,
unsigned long V_359 )
{
struct V_360 * V_361 ;
int V_362 [ V_363 + 2 ] ;
int V_364 , V_365 , V_63 ;
int V_366 , V_248 , V_367 ;
if ( ( V_368 < 1 ) || ( V_359 < 1048576 ) )
return;
if ( V_368 > V_363 ) {
V_368 = V_363 ;
F_16 ( L_43 , V_32 ,
V_363 ) ;
}
V_365 = ( int ) V_6 ;
V_364 = ( V_365 - V_173 )
/ V_368 ;
V_366 = V_369 * V_173 ;
V_362 [ 0 ] = V_173 ;
for ( V_63 = 1 ; V_63 < V_368 ; ++ V_63 )
V_362 [ V_63 ] = ( ( V_63 * V_364 ) / V_366 )
* V_366 ;
V_362 [ V_368 ] = V_365 ;
V_362 [ V_368 + 1 ] = 0 ;
V_358 [ 510 ] = 0x55 ;
V_358 [ 511 ] = 0xAA ;
V_361 = (struct V_360 * ) ( V_358 + 0x1be ) ;
for ( V_63 = 0 ; V_362 [ V_63 + 1 ] ; ++ V_63 , ++ V_361 ) {
V_248 = V_362 [ V_63 ] ;
V_367 = V_362 [ V_63 + 1 ] - 1 ;
V_361 -> V_370 = 0 ;
V_361 -> V_371 = V_248 / V_366 ;
V_361 -> V_372 = ( V_248 - ( V_361 -> V_371 * V_366 ) )
/ V_173 ;
V_361 -> V_10 = ( V_248 % V_173 ) + 1 ;
V_361 -> V_373 = V_367 / V_366 ;
V_361 -> V_374 = ( V_367 - ( V_361 -> V_373 * V_366 ) )
/ V_173 ;
V_361 -> V_375 = ( V_367 % V_173 ) + 1 ;
V_361 -> V_376 = F_147 ( V_248 ) ;
V_361 -> V_377 = F_147 ( V_367 - V_248 + 1 ) ;
V_361 -> V_378 = 0x83 ;
}
}
static int
F_148 ( struct V_23 * V_124 , struct V_61 * V_62 ,
int V_379 , int V_380 )
{
unsigned long V_253 ;
int V_63 , V_309 , V_381 , V_382 , V_383 ;
struct V_301 * V_302 = NULL ;
struct V_55 * V_330 = V_124 -> V_31 ;
if ( NULL == V_124 || NULL == V_62 ) {
F_16 ( L_44 ,
V_32 ) ;
return V_384 ;
}
if ( ( V_379 ) && ( V_35 & V_36 ) )
F_10 ( V_37 , V_330 , L_45 ,
V_32 , V_379 ) ;
if ( V_380 == 0 ) {
V_124 -> V_385 = V_379 ;
V_124 -> V_314 ( V_124 ) ;
return 0 ;
}
F_114 ( & V_305 , V_253 ) ;
V_309 = F_117 ( & V_62 -> V_309 ) ;
V_382 = V_124 -> V_31 -> V_386 ;
V_63 = F_149 ( V_311 , V_313 ) ;
V_381 = 0 ;
V_383 = 0 ;
if ( ( V_382 > 0 ) && ( V_309 >= V_382 ) )
V_381 = 1 ;
else if ( ( V_387 != 0 ) &&
( V_388 & V_36 ) ) {
if ( ( V_309 == ( V_382 - 1 ) ) &&
( F_150 ( & V_389 ) >=
abs ( V_387 ) ) ) {
F_121 ( & V_389 , 0 ) ;
V_383 = 1 ;
V_381 = 1 ;
}
}
if ( V_381 )
V_379 = V_390 ;
if ( V_63 >= V_313 ) {
if ( V_391 & V_36 )
V_381 = 1 ;
F_115 ( & V_305 , V_253 ) ;
if ( V_392 & V_36 )
F_10 ( V_37 , V_330 ,
L_46 ,
V_32 , V_309 ,
( V_383 ? L_47 : L_48 ) ,
( V_381 ? L_49 :
L_50 ) ) ;
if ( V_381 ) {
V_124 -> V_385 = V_379 ;
V_124 -> V_314 ( V_124 ) ;
return 0 ;
} else
return V_384 ;
}
F_151 ( V_63 , V_311 ) ;
F_113 ( & V_62 -> V_309 ) ;
V_302 = & V_306 [ V_63 ] ;
V_302 -> V_307 = V_124 ;
V_124 -> V_385 = V_379 ;
F_115 ( & V_305 , V_253 ) ;
if ( V_380 > 0 ) {
if ( NULL == V_302 -> V_346 ) {
V_302 -> V_346 = F_106 ( sizeof( struct V_393 ) ,
V_129 ) ;
if ( NULL == V_302 -> V_346 )
return V_384 ;
F_152 ( V_302 -> V_346 ) ;
}
V_302 -> V_346 -> V_394 = F_112 ;
V_302 -> V_346 -> V_233 = V_63 ;
V_302 -> V_346 -> V_395 = F_153 () + V_380 ;
F_154 ( V_302 -> V_346 ) ;
} else if ( V_343 > 0 ) {
T_9 V_396 = F_155 ( 0 , V_343 ) ;
struct V_318 * V_397 = V_302 -> V_319 ;
if ( NULL == V_397 ) {
V_397 = F_106 ( sizeof( * V_397 ) , V_129 ) ;
if ( NULL == V_397 )
return V_384 ;
V_302 -> V_319 = V_397 ;
F_156 ( & V_397 -> V_344 , V_398 ,
V_399 ) ;
V_397 -> V_344 . V_394 = F_122 ;
V_397 -> V_299 = V_63 ;
}
F_157 ( & V_397 -> V_344 , V_396 , V_399 ) ;
} else {
if ( NULL == V_302 -> V_347 ) {
V_302 -> V_347 = F_106 ( sizeof( * V_302 -> V_347 ) ,
V_129 ) ;
if ( NULL == V_302 -> V_347 )
return V_384 ;
F_158 ( V_302 -> V_347 ,
F_112 , V_63 ) ;
}
if ( - 1 == V_380 )
F_159 ( V_302 -> V_347 ) ;
else
F_160 ( V_302 -> V_347 ) ;
}
if ( V_381 && ( V_392 & V_36 ) )
F_10 ( V_37 , V_330 ,
L_51 , V_32 ,
V_309 , ( V_383 ? L_47 : L_48 ) ,
L_49 ) ;
return 0 ;
}
static const char * F_161 ( struct V_14 * V_400 )
{
sprintf ( V_401 , L_52
L_53 , V_402 ,
V_403 , V_404 ,
V_36 ) ;
return V_401 ;
}
static int F_162 ( struct V_14 * V_327 , char * V_405 , int V_87 )
{
char V_82 [ 16 ] ;
int V_406 ;
int V_407 = V_87 > 15 ? 15 : V_87 ;
if ( ! F_163 ( V_408 ) || ! F_163 ( V_409 ) )
return - V_410 ;
memcpy ( V_82 , V_405 , V_407 ) ;
V_82 [ V_407 ] = '\0' ;
if ( 1 != sscanf ( V_82 , L_18 , & V_406 ) )
return - V_58 ;
V_36 = V_406 ;
if ( V_387 != 0 )
F_121 ( & V_411 , 0 ) ;
return V_87 ;
}
static int F_164 ( struct V_412 * V_413 , struct V_14 * V_327 )
{
int V_414 , V_415 ;
char V_102 [ 32 ] ;
if ( V_387 > 0 )
snprintf ( V_102 , sizeof( V_102 ) , L_54 ,
( ( V_388 & V_36 ) ?
F_117 ( & V_389 ) :
F_117 ( & V_411 ) ) ) ;
else
V_102 [ 0 ] = '\0' ;
F_165 ( V_413 , L_55
L_56
L_57
L_58
L_59
L_60
L_61
L_62 ,
V_402 , V_403 ,
V_19 , V_404 , V_36 ,
V_387 , V_102 , V_345 , V_343 ,
V_294 , F_117 ( & V_303 ) ,
V_8 , V_416 , V_369 ,
V_173 , V_348 , V_351 ,
V_353 , V_356 , V_357 ,
V_252 , V_273 , V_251 , V_417 / 1000 ) ;
V_414 = F_15 ( V_311 , V_313 ) ;
if ( V_414 != V_313 ) {
V_415 = F_120 ( V_311 , V_313 ) ;
F_165 ( V_413 , L_63 ,
L_64 , V_414 , V_415 ) ;
}
return 0 ;
}
static T_10 F_166 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_345 ) ;
}
static T_10 F_167 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_422 , V_208 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_422 ) ) ) {
V_208 = V_421 ;
if ( V_345 != V_422 ) {
unsigned long V_253 ;
int V_63 ;
F_114 ( & V_305 , V_253 ) ;
V_63 = F_15 ( V_311 ,
V_313 ) ;
if ( V_63 != V_313 )
V_208 = - V_423 ;
else {
V_345 = V_422 ;
V_343 = 0 ;
}
F_115 ( & V_305 , V_253 ) ;
}
return V_208 ;
}
return - V_58 ;
}
static T_10 F_168 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_343 ) ;
}
static T_10 F_169 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
unsigned long V_253 ;
int V_424 , V_208 , V_63 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_424 ) ) &&
( V_424 >= 0 ) && ( V_424 < 1000000000 ) ) {
V_208 = V_421 ;
if ( V_343 != V_424 ) {
F_114 ( & V_305 , V_253 ) ;
V_63 = F_15 ( V_311 ,
V_313 ) ;
if ( V_63 != V_313 )
V_208 = - V_423 ;
else {
V_343 = V_424 ;
V_345 = V_424 ? V_425
: V_426 ;
}
F_115 ( & V_305 , V_253 ) ;
}
return V_208 ;
}
return - V_58 ;
}
static T_10 F_170 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_66 , V_36 ) ;
}
static T_10 F_171 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_406 ;
char V_427 [ 20 ] ;
if ( 1 == sscanf ( V_228 , L_67 , V_427 ) ) {
if ( 0 == F_172 ( V_427 , L_68 , 2 ) ) {
if ( 1 == sscanf ( & V_427 [ 2 ] , L_69 , & V_406 ) )
goto V_428;
} else {
if ( 1 == sscanf ( V_427 , L_18 , & V_406 ) )
goto V_428;
}
}
return - V_58 ;
V_428:
V_36 = V_406 ;
F_121 ( & V_411 , 0 ) ;
F_121 ( & V_389 , 0 ) ;
return V_421 ;
}
static T_10 F_173 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_134 ) ;
}
static T_10 F_174 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_126 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_126 ) ) && ( V_126 >= 0 ) ) {
V_134 = V_126 ;
return V_421 ;
}
return - V_58 ;
}
static T_10 F_175 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_34 ) ;
}
static T_10 F_176 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_126 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_126 ) ) && ( V_126 >= 0 ) ) {
V_34 = V_126 ;
return V_421 ;
}
return - V_58 ;
}
static T_10 F_177 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_1 ) ;
}
static T_10 F_178 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_126 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_126 ) ) && ( V_126 >= 0 ) ) {
V_126 = ( V_126 > 0 ) ;
V_1 = ( V_1 > 0 ) ;
if ( V_1 != V_126 ) {
if ( ( 0 == V_126 ) && ( NULL == V_7 ) ) {
unsigned long V_429 =
( unsigned long ) V_404 *
1048576 ;
V_7 = F_179 ( V_429 ) ;
if ( NULL == V_7 ) {
F_71 ( L_70 ,
V_32 ) ;
return - V_430 ;
}
memset ( V_7 , 0 , V_429 ) ;
}
V_1 = V_126 ;
}
return V_421 ;
}
return - V_58 ;
}
static T_10 F_180 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_132 ) ;
}
static T_10 F_181 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_126 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_126 ) ) && ( V_126 >= 0 ) ) {
V_132 = V_126 ;
return V_421 ;
}
return - V_58 ;
}
static T_10 F_182 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_19 ) ;
}
static T_10 F_183 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_126 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_126 ) ) && ( V_126 >= 0 ) ) {
V_19 = V_126 ;
F_5 () ;
return V_421 ;
}
return - V_58 ;
}
static T_10 F_184 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_404 ) ;
}
static T_10 F_185 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_368 ) ;
}
static T_10 F_186 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_387 ) ;
}
static T_10 F_187 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_431 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_431 ) ) ) {
V_387 = V_431 ;
F_121 ( & V_411 , 0 ) ;
return V_421 ;
}
return - V_58 ;
}
static T_10 F_188 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_294 ) ;
}
static T_10 F_189 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_126 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_126 ) ) && ( V_126 >= 0 ) ) {
V_294 = V_126 ;
F_5 () ;
return V_421 ;
}
return - V_58 ;
}
static T_10 F_190 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_313 ) ;
}
static T_10 F_191 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
unsigned long V_253 ;
int V_126 , V_63 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_126 ) ) && ( V_126 > 0 ) &&
( V_126 <= V_304 ) ) {
F_114 ( & V_305 , V_253 ) ;
V_63 = F_120 ( V_311 , V_304 ) ;
V_313 = V_126 ;
if ( V_304 == V_63 )
F_121 ( & V_310 , 0 ) ;
else if ( V_63 >= V_126 )
F_121 ( & V_310 , V_63 + 1 ) ;
else
F_121 ( & V_310 , 0 ) ;
F_115 ( & V_305 , V_253 ) ;
return V_421 ;
}
return - V_58 ;
}
static T_10 F_192 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_339 ) ;
}
static T_10 F_193 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_146 ) ;
}
static T_10 F_194 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_157 ) ;
}
static T_10 F_195 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_126 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_126 ) ) && ( V_126 >= 0 ) ) {
V_157 = V_126 ;
V_160 = F_42 () ;
return V_421 ;
}
return - V_58 ;
}
static T_10 F_196 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_432 ) ;
}
static T_10 F_197 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_433 ;
if ( sscanf ( V_228 , L_18 , & V_433 ) != 1 )
return - V_58 ;
if ( V_433 > 0 ) {
do {
F_198 () ;
} while ( -- V_433 );
} else if ( V_433 < 0 ) {
do {
F_199 () ;
} while ( ++ V_433 );
}
return V_421 ;
}
static T_10 F_200 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_142 ) ;
}
static T_10 F_201 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_126 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_126 ) ) && ( V_126 >= 0 ) ) {
V_142 = V_126 ;
return V_421 ;
}
return - V_58 ;
}
static T_10 F_202 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_71 , V_8 ) ;
}
static T_10 F_203 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_260 ) ;
}
static T_10 F_204 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_143 ) ;
}
static T_10 F_205 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_71 , V_230 ) ;
}
static T_10 F_206 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_181 ) ;
}
static T_10 F_207 ( struct V_418 * V_419 , char * V_228 )
{
T_10 V_421 ;
if ( ! F_1 () )
return F_38 ( V_228 , V_420 , L_72 ,
V_6 ) ;
V_421 = F_208 ( V_228 , V_420 , V_278 , V_279 ) ;
V_228 [ V_421 ++ ] = '\n' ;
V_228 [ V_421 ++ ] = 0 ;
return V_421 ;
}
static T_10 F_209 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , V_145 ? 1 : 0 ) ;
}
static T_10 F_210 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_126 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_126 ) ) && ( V_126 >= 0 ) ) {
V_145 = ( V_126 > 0 ) ;
return V_421 ;
}
return - V_58 ;
}
static T_10 F_211 ( struct V_418 * V_419 , char * V_228 )
{
return F_38 ( V_228 , V_420 , L_65 , ! ! V_434 ) ;
}
static T_10 F_212 ( struct V_418 * V_419 , const char * V_228 ,
T_4 V_421 )
{
int V_126 , V_208 ;
if ( ( V_421 > 0 ) && ( 1 == sscanf ( V_228 , L_18 , & V_126 ) ) && ( V_126 >= 0 ) ) {
bool V_435 = ( V_126 > 0 ) ;
V_208 = V_421 ;
if ( V_435 != V_434 ) {
unsigned long V_253 ;
int V_63 ;
F_114 ( & V_305 , V_253 ) ;
V_63 = F_15 ( V_311 ,
V_313 ) ;
if ( V_63 != V_313 )
V_208 = - V_423 ;
else
V_434 = V_435 ;
F_115 ( & V_305 , V_253 ) ;
}
return V_208 ;
}
return - V_58 ;
}
static int T_8 F_213 ( void )
{
unsigned long V_429 ;
int V_436 ;
int V_63 ;
int V_127 ;
F_121 ( & V_411 , 0 ) ;
F_121 ( & V_303 , 0 ) ;
F_121 ( & V_310 , 0 ) ;
if ( V_343 >= 1000000000 ) {
F_16 ( L_73 ,
V_32 ) ;
V_343 = 0 ;
} else if ( V_343 > 0 )
V_345 = V_425 ;
switch ( V_8 ) {
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_71 ( L_74 , V_32 ,
V_8 ) ;
return - V_58 ;
}
switch ( V_143 ) {
case V_437 :
case V_235 :
case V_237 :
case V_144 :
break;
default:
F_71 ( L_75 , V_32 ) ;
return - V_58 ;
}
if ( V_230 > 1 ) {
F_71 ( L_76 , V_32 ) ;
return - V_58 ;
}
if ( V_181 > 1 ) {
F_71 ( L_77 , V_32 ) ;
return - V_58 ;
}
if ( V_114 > 15 ) {
F_71 ( L_78 , V_32 ,
V_114 ) ;
return - V_58 ;
}
if ( V_162 > 0x3fff ) {
F_71 ( L_79 , V_32 ,
V_162 ) ;
return - V_58 ;
}
if ( V_404 < 1 )
V_404 = 1 ;
V_429 = ( unsigned long ) V_404 * 1048576 ;
V_6 = V_429 / V_8 ;
V_160 = F_42 () ;
V_369 = 8 ;
V_173 = 32 ;
if ( V_404 >= 16 )
V_369 = 32 ;
else if ( V_404 >= 256 )
V_369 = 64 ;
V_416 = ( unsigned long ) V_160 /
( V_173 * V_369 ) ;
if ( V_416 >= 1024 ) {
V_369 = 255 ;
V_173 = 63 ;
V_416 = ( unsigned long ) V_160 /
( V_173 * V_369 ) ;
}
if ( 0 == V_1 ) {
V_7 = F_179 ( V_429 ) ;
if ( NULL == V_7 ) {
F_71 ( L_80 , V_32 ) ;
return - V_430 ;
}
memset ( V_7 , 0 , V_429 ) ;
if ( V_368 > 0 )
F_146 ( V_7 , V_429 ) ;
}
if ( V_260 ) {
int V_438 ;
V_438 = V_6 * sizeof( struct V_9 ) ;
V_11 = F_179 ( V_438 ) ;
F_71 ( L_81 , V_32 , V_438 ,
V_11 ) ;
if ( V_11 == NULL ) {
F_71 ( L_82 , V_32 ) ;
V_127 = - V_430 ;
goto V_439;
}
memset ( V_11 , 0xff , V_438 ) ;
}
if ( F_1 () ) {
V_116 =
F_214 ( V_116 , 0U , 0xffffffffU ) ;
V_117 =
F_214 ( V_117 , 0U , 256U ) ;
V_119 =
F_214 ( V_119 , 1U , 0xffffffffU ) ;
if ( V_118 &&
V_119 <=
V_118 ) {
F_71 ( L_83 ,
V_32 ) ;
return - V_58 ;
}
V_279 = F_91 ( V_6 - 1 ) + 1 ;
V_278 = F_179 ( F_215 ( V_279 ) * sizeof( long ) ) ;
F_216 ( L_84 , V_32 , V_279 ) ;
if ( V_278 == NULL ) {
F_71 ( L_85 , V_32 ) ;
V_127 = - V_430 ;
goto V_439;
}
F_217 ( V_278 , V_279 ) ;
if ( V_368 )
F_98 ( 0 , 2 ) ;
}
V_440 = F_218 ( L_86 ) ;
if ( F_219 ( V_440 ) ) {
F_16 ( L_87 , V_32 ) ;
V_127 = F_220 ( V_440 ) ;
goto V_439;
}
V_127 = F_221 ( & V_441 ) ;
if ( V_127 < 0 ) {
F_16 ( L_88 , V_32 , V_127 ) ;
goto V_442;
}
V_127 = F_222 ( & V_443 ) ;
if ( V_127 < 0 ) {
F_16 ( L_89 , V_32 , V_127 ) ;
goto V_444;
}
V_436 = V_432 ;
V_432 = 0 ;
for ( V_63 = 0 ; V_63 < V_436 ; V_63 ++ ) {
if ( F_198 () ) {
F_71 ( L_90 ,
V_32 , V_63 ) ;
break;
}
}
if ( V_35 & V_36 ) {
F_216 ( L_91 , V_32 ,
V_432 ) ;
}
return 0 ;
V_444:
F_223 ( & V_441 ) ;
V_442:
F_224 ( V_440 ) ;
V_439:
if ( V_278 )
F_225 ( V_278 ) ;
if ( V_11 )
F_225 ( V_11 ) ;
F_225 ( V_7 ) ;
return V_127 ;
}
static void T_11 F_226 ( void )
{
int V_63 = V_432 ;
F_139 () ;
F_140 () ;
for (; V_63 ; V_63 -- )
F_199 () ;
F_227 ( & V_443 ) ;
F_223 ( & V_441 ) ;
F_224 ( V_440 ) ;
if ( V_11 )
F_225 ( V_11 ) ;
F_225 ( V_7 ) ;
}
static void F_228 ( struct V_31 * V_56 )
{
struct V_12 * V_13 ;
V_13 = F_229 ( V_56 ) ;
F_37 ( V_13 ) ;
}
static int F_198 ( void )
{
int V_63 , V_445 ;
int error = 0 ;
struct V_12 * V_13 ;
struct V_61 * V_446 , * V_447 ;
V_13 = F_36 ( sizeof( * V_13 ) , V_448 ) ;
if ( NULL == V_13 ) {
F_127 ( V_30 L_35 ,
V_32 , __LINE__ ) ;
return - V_430 ;
}
F_230 ( & V_13 -> V_324 ) ;
V_445 = V_19 * V_294 ;
for ( V_63 = 0 ; V_63 < V_445 ; V_63 ++ ) {
V_446 = F_123 ( V_13 , V_448 ) ;
if ( ! V_446 ) {
F_127 ( V_30 L_35 ,
V_32 , __LINE__ ) ;
error = - V_430 ;
goto V_449;
}
}
F_6 ( & V_16 ) ;
F_124 ( & V_13 -> V_450 , & V_451 ) ;
F_8 ( & V_16 ) ;
V_13 -> V_56 . V_452 = & V_441 ;
V_13 -> V_56 . V_453 = V_440 ;
V_13 -> V_56 . V_454 = & F_228 ;
F_231 ( & V_13 -> V_56 , L_92 , V_432 ) ;
error = F_232 ( & V_13 -> V_56 ) ;
if ( error )
goto V_449;
++ V_432 ;
return error ;
V_449:
F_233 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_234 ( & V_446 -> V_323 ) ;
F_37 ( V_446 ) ;
}
F_37 ( V_13 ) ;
return error ;
}
static void F_199 ( void )
{
struct V_12 * V_13 = NULL ;
F_6 ( & V_16 ) ;
if ( ! F_235 ( & V_451 ) ) {
V_13 = F_236 ( V_451 . V_455 ,
struct V_12 , V_450 ) ;
F_234 ( & V_13 -> V_450 ) ;
}
F_8 ( & V_16 ) ;
if ( ! V_13 )
return;
F_237 ( & V_13 -> V_56 ) ;
-- V_432 ;
}
static int
F_238 ( struct V_23 * V_59 )
{
unsigned char * V_39 = ( unsigned char * ) V_59 -> V_124 ;
int V_138 , V_63 ;
unsigned int V_40 ;
unsigned long long V_5 ;
T_2 V_41 ;
int V_154 = 0 ;
int V_122 = V_59 -> V_31 -> V_329 ;
struct V_61 * V_62 = NULL ;
int V_456 = 0 ;
int V_457 = 0 ;
int V_458 = 0 ;
int V_459 = 0 ;
int V_460 = 0 ;
int V_461 = 0 ;
int V_280 = 0 ;
F_82 ( V_59 , 0 ) ;
if ( ( V_35 & V_36 ) &&
! ( V_462 & V_36 ) && V_39 ) {
char V_102 [ 120 ] ;
int V_126 ;
V_138 = V_59 -> V_463 ;
if ( V_138 > 32 )
strcpy ( V_102 , L_93 ) ;
else {
for ( V_63 = 0 , V_126 = 0 ; V_63 < V_138 ; ++ V_63 )
V_126 += F_38 ( V_102 + V_126 , sizeof( V_102 ) - V_126 , L_24 ,
( unsigned int ) V_39 [ V_63 ] ) ;
}
F_10 ( V_37 , V_59 -> V_31 , L_94 , V_38 ,
V_102 ) ;
}
if ( ( V_59 -> V_31 -> V_133 >= V_294 ) &&
( V_59 -> V_31 -> V_133 != V_22 ) )
return F_148 ( V_59 , NULL , V_464 << 16 , 0 ) ;
V_62 = F_125 ( V_59 -> V_31 ) ;
if ( NULL == V_62 )
return F_148 ( V_59 , NULL , V_464 << 16 , 0 ) ;
if ( ( V_387 != 0 ) &&
( F_150 ( & V_411 ) >=
abs ( V_387 ) ) ) {
F_121 ( & V_411 , 0 ) ;
if ( V_387 < - 1 )
V_387 = - 1 ;
if ( V_465 & V_36 )
return 0 ;
else if ( V_466 & V_36 &&
F_239 ( V_59 ) )
return 0 ;
else if ( V_467 & V_36 )
V_456 = 1 ;
else if ( V_468 & V_36 )
V_457 = 1 ;
else if ( V_469 & V_36 )
V_458 = 1 ;
else if ( V_470 & V_36 )
V_459 = 1 ;
else if ( V_471 & V_36 )
V_460 = 1 ;
}
if ( V_62 -> V_131 ) {
switch ( * V_39 ) {
case V_472 :
case V_473 :
case V_474 :
case V_475 :
break;
default:
if ( V_35 & V_36 )
F_127 ( V_37 L_95
L_96 , * V_39 ) ;
F_9 ( V_59 , V_135 ,
V_476 , 0 ) ;
V_154 = V_77 ;
return F_148 ( V_59 , V_62 , V_154 , 0 ) ;
}
}
switch ( * V_39 ) {
case V_472 :
V_461 = 1 ;
V_154 = F_35 ( V_59 , V_122 , V_62 ) ;
break;
case V_473 :
V_461 = 1 ;
V_154 = F_40 ( V_59 , V_62 ) ;
break;
case V_477 :
case V_478 :
V_154 = F_41 ( V_59 , V_62 ) ;
break;
case V_479 :
V_154 = F_14 ( V_59 , V_156 , V_62 ) ;
if ( V_154 )
break;
if ( V_35 & V_36 )
F_127 ( V_37 L_97 ,
V_39 [ 4 ] ? L_98 : L_99 ) ;
break;
case V_480 :
V_154 = F_14 ( V_59 , V_156 , V_62 ) ;
break;
case V_474 :
V_154 = F_14 ( V_59 , V_78 , V_62 ) ;
break;
case V_481 :
V_154 = F_14 ( V_59 , V_156 , V_62 ) ;
break;
case V_482 :
V_154 = F_14 ( V_59 , V_156 , V_62 ) ;
break;
case V_483 :
V_154 = F_14 ( V_59 , V_156 , V_62 ) ;
break;
case V_484 :
V_154 = F_14 ( V_59 , V_156 , V_62 ) ;
break;
case V_485 :
V_154 = F_43 ( V_59 , V_62 ) ;
break;
case V_486 :
if ( V_39 [ 1 ] == V_487 )
V_154 = F_44 ( V_59 , V_62 ) ;
else if ( V_39 [ 1 ] == V_488 ) {
if ( F_1 () == 0 ) {
F_9 ( V_59 , V_135 ,
V_489 , 0 ) ;
V_154 = V_77 ;
} else
V_154 = F_109 ( V_59 , V_62 ) ;
} else {
F_9 ( V_59 , V_135 ,
V_476 , 0 ) ;
V_154 = V_77 ;
}
break;
case V_490 :
if ( V_491 != V_39 [ 1 ] ) {
F_9 ( V_59 , V_135 ,
V_476 , 0 ) ;
V_154 = V_77 ;
break;
}
V_154 = F_45 ( V_59 , V_62 ) ;
break;
case V_46 :
case V_48 :
case V_51 :
if ( V_143 == V_237 &&
V_39 [ 1 ] & 0xe0 ) {
F_9 ( V_59 , V_135 ,
V_489 , 0 ) ;
V_154 = V_77 ;
break;
}
if ( ( V_143 == V_235 ||
V_143 == V_144 ) &&
( V_39 [ 1 ] & 0xe0 ) == 0 )
F_127 ( V_30 L_100 ) ;
case V_54 :
V_239:
V_154 = F_14 ( V_59 , V_78 , V_62 ) ;
if ( V_154 )
break;
if ( V_1 )
break;
F_12 ( V_39 , & V_5 , & V_40 , & V_41 ) ;
if ( V_460 )
V_40 /= 2 ;
V_154 = F_81 ( V_59 , V_5 , V_40 , V_41 ) ;
if ( V_456 && ( 0 == V_154 ) ) {
F_9 ( V_59 , V_492 ,
V_151 , 0 ) ;
V_154 = V_77 ;
} else if ( V_457 && ( 0 == V_154 ) ) {
F_9 ( V_59 , V_262 ,
V_493 , V_494 ) ;
V_154 = V_77 ;
} else if ( V_458 && ( 0 == V_154 ) ) {
F_9 ( V_59 , V_262 , 0x10 , 1 ) ;
V_154 = V_263 ;
} else if ( V_459 && ( 0 == V_154 ) ) {
F_9 ( V_59 , V_135 , 0x10 , 1 ) ;
V_154 = V_263 ;
}
break;
case V_475 :
V_461 = 1 ;
V_154 = F_110 ( V_59 , V_62 ) ;
break;
case V_495 :
V_154 = F_14 ( V_59 , V_78 , V_62 ) ;
break;
case V_45 :
case V_47 :
case V_50 :
if ( V_143 == V_237 &&
V_39 [ 1 ] & 0xe0 ) {
F_9 ( V_59 , V_135 ,
V_489 , 0 ) ;
V_154 = V_77 ;
break;
}
if ( ( V_143 == V_235 ||
V_143 == V_144 ) &&
( V_39 [ 1 ] & 0xe0 ) == 0 )
F_127 ( V_30 L_100 ) ;
case V_53 :
V_220:
V_154 = F_14 ( V_59 , V_78 , V_62 ) ;
if ( V_154 )
break;
if ( V_1 )
break;
F_12 ( V_39 , & V_5 , & V_40 , & V_41 ) ;
V_154 = F_100 ( V_59 , V_5 , V_40 , V_41 ) ;
if ( V_456 && ( 0 == V_154 ) ) {
F_9 ( V_59 , V_492 ,
V_151 , 0 ) ;
V_154 = V_77 ;
} else if ( V_458 && ( 0 == V_154 ) ) {
F_9 ( V_59 , V_262 , 0x10 , 1 ) ;
V_154 = V_263 ;
} else if ( V_459 && ( 0 == V_154 ) ) {
F_9 ( V_59 , V_135 , 0x10 , 1 ) ;
V_154 = V_263 ;
}
break;
case V_44 :
case V_49 :
if ( V_39 [ 1 ] & 0x8 ) {
if ( ( * V_39 == V_44 && V_3 == 0 ) ||
( * V_39 == V_49 && V_4 == 0 ) ) {
F_9 ( V_59 , V_135 ,
V_136 , 0 ) ;
V_154 = V_77 ;
} else
V_280 = 1 ;
}
if ( V_154 )
break;
V_154 = F_14 ( V_59 , V_78 , V_62 ) ;
if ( V_154 )
break;
if ( V_1 )
break;
F_12 ( V_39 , & V_5 , & V_40 , & V_41 ) ;
V_154 = F_103 ( V_59 , V_5 , V_40 , V_41 , V_280 ) ;
break;
case V_496 :
V_154 = F_14 ( V_59 , V_78 , V_62 ) ;
if ( V_154 )
break;
if ( V_1 )
break;
if ( V_117 == 0 || V_2 == 0 ) {
F_9 ( V_59 , V_135 ,
V_489 , 0 ) ;
V_154 = V_77 ;
} else
V_154 = F_104 ( V_59 , V_62 ) ;
break;
case V_197 :
case V_497 :
V_154 = F_55 ( V_59 , V_122 , V_62 ) ;
break;
case V_498 :
V_154 = F_57 ( V_59 , 1 , V_62 ) ;
break;
case V_499 :
V_154 = F_57 ( V_59 , 0 , V_62 ) ;
break;
case V_500 :
V_154 = F_61 ( V_59 , V_62 ) ;
break;
case V_501 :
V_461 = 1 ;
V_154 = F_14 ( V_59 , V_78 , V_62 ) ;
break;
case V_502 :
V_154 = F_14 ( V_59 , V_156 , V_62 ) ;
break;
case V_52 :
if ( ! F_20 ( V_59 ) ) {
F_9 ( V_59 , V_135 ,
V_136 , 0 ) ;
V_154 = V_77 ;
break;
}
V_154 = F_14 ( V_59 , V_78 , V_62 ) ;
if ( V_154 )
break;
if ( V_1 )
break;
F_12 ( V_39 , & V_5 , & V_40 , & V_41 ) ;
V_154 = F_81 ( V_59 , V_5 , V_40 , V_41 ) ;
if ( V_154 )
break;
V_154 = F_100 ( V_59 , V_5 , V_40 , V_41 ) ;
if ( V_154 )
break;
V_154 = F_111 ( V_59 , V_5 , V_40 , V_62 ) ;
break;
case V_42 :
if ( V_143 == V_237 ) {
if ( ( V_39 [ 10 ] & 0xe0 ) == 0 )
F_127 ( V_30
L_100 ) ;
if ( V_39 [ 9 ] == V_503 ) {
F_87 ( V_59 -> V_463 < 32 ) ;
goto V_239;
}
if ( V_39 [ 9 ] == V_504 ) {
F_87 ( V_59 -> V_463 < 32 ) ;
goto V_220;
}
}
F_9 ( V_59 , V_135 ,
V_136 , 0 ) ;
V_154 = V_77 ;
break;
case 0x85 :
if ( V_35 & V_36 )
F_10 ( V_37 , V_59 -> V_31 ,
L_101 , V_38 ) ;
F_9 ( V_59 , V_135 ,
V_476 , 0 ) ;
V_154 = V_77 ;
break;
default:
if ( V_35 & V_36 )
F_10 ( V_37 , V_59 -> V_31 ,
L_102 ,
V_38 , * V_39 ) ;
V_154 = F_14 ( V_59 , V_156 , V_62 ) ;
if ( V_154 )
break;
F_9 ( V_59 , V_135 , V_476 , 0 ) ;
V_154 = V_77 ;
break;
}
return F_148 ( V_59 , V_62 , V_154 ,
( V_461 ? 0 : V_345 ) ) ;
}
static int
F_240 ( struct V_14 * V_17 , struct V_23 * V_39 )
{
if ( V_434 ) {
unsigned long V_253 ;
int V_505 ;
F_114 ( V_17 -> V_506 , V_253 ) ;
V_505 = F_238 ( V_39 ) ;
F_115 ( V_17 -> V_506 , V_253 ) ;
return V_505 ;
} else
return F_238 ( V_39 ) ;
}
static int
F_241 ( struct V_55 * V_325 , int V_382 , int V_507 )
{
int V_309 = 0 ;
int V_508 = 0 ;
unsigned long V_253 ;
struct V_61 * V_62 ;
F_114 ( & V_305 , V_253 ) ;
V_62 = (struct V_61 * ) V_325 -> V_308 ;
if ( NULL == V_62 ) {
F_115 ( & V_305 , V_253 ) ;
return - V_509 ;
}
V_309 = F_117 ( & V_62 -> V_309 ) ;
F_115 ( & V_305 , V_253 ) ;
if ( V_507 == V_510 || V_507 == V_511 ) {
if ( V_382 < 1 )
V_382 = 1 ;
if ( V_382 > V_304 + 10 )
V_382 = V_304 + 10 ;
F_131 ( V_325 , F_242 ( V_325 ) , V_382 ) ;
} else if ( V_507 == V_512 )
F_243 ( V_325 , V_382 ) ;
else
V_508 = 1 ;
if ( V_508 )
F_10 ( V_513 , V_325 ,
L_103 , V_32 , V_507 ) ;
if ( V_392 & V_36 ) {
if ( V_512 == V_507 )
F_10 ( V_37 , V_325 ,
L_104 ,
V_32 , V_382 , V_309 ) ;
else {
const char * V_67 ;
switch ( V_507 ) {
case V_510 :
V_67 = L_105 ;
break;
case V_511 :
V_67 = L_106 ;
break;
default:
V_67 = L_10 ;
break;
}
F_10 ( V_37 , V_325 ,
L_107 ,
V_32 , V_382 , V_309 , V_67 ) ;
}
}
return V_325 -> V_386 ;
}
static int
F_244 ( struct V_55 * V_325 , int V_514 )
{
if ( V_325 -> V_335 ) {
F_245 ( V_325 , V_514 ) ;
if ( V_514 )
F_246 ( V_325 , V_325 -> V_386 ) ;
else
F_247 ( V_325 , V_325 -> V_386 ) ;
} else
V_514 = 0 ;
if ( V_392 & V_36 ) {
const char * V_67 ;
switch ( V_514 ) {
case 0 :
V_67 = L_108 ;
break;
case V_515 :
V_67 = L_109 ;
break;
case V_516 :
V_67 = L_110 ;
break;
default:
V_67 = L_10 ;
break;
}
F_10 ( V_37 , V_325 , L_111 , V_32 , V_67 ) ;
}
return V_514 ;
}
static int F_248 ( struct V_31 * V_56 )
{
int error = 0 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_517 ;
V_13 = F_229 ( V_56 ) ;
V_518 . V_519 = V_313 ;
if ( V_520 )
V_518 . V_521 = V_522 ;
V_15 = F_249 ( & V_518 , sizeof( V_13 ) ) ;
if ( NULL == V_15 ) {
F_127 ( V_30 L_112 , V_32 ) ;
error = - V_509 ;
return error ;
}
V_13 -> V_17 = V_15 ;
* ( (struct V_12 * * ) V_15 -> V_308 ) = V_13 ;
if ( ( V_15 -> V_18 >= 0 ) && ( V_19 > V_15 -> V_18 ) )
V_15 -> V_20 = V_19 + 1 ;
else
V_15 -> V_20 = V_19 ;
V_15 -> V_21 = V_22 ;
V_517 = 0 ;
switch ( V_143 ) {
case V_235 :
V_517 = V_523 ;
if ( V_260 )
V_517 |= V_524 ;
break;
case V_237 :
V_517 = V_525 ;
if ( V_260 )
V_517 |= V_526 ;
break;
case V_144 :
V_517 = V_527 ;
if ( V_260 )
V_517 |= V_528 ;
break;
default:
if ( V_260 )
V_517 |= V_529 ;
break;
}
F_250 ( V_15 , V_517 ) ;
F_127 ( V_37 L_113 ,
( V_517 & V_523 ) ? L_114 : L_48 ,
( V_517 & V_525 ) ? L_115 : L_48 ,
( V_517 & V_527 ) ? L_116 : L_48 ,
( V_517 & V_529 ) ? L_117 : L_48 ,
( V_517 & V_524 ) ? L_118 : L_48 ,
( V_517 & V_526 ) ? L_119 : L_48 ,
( V_517 & V_528 ) ? L_120 : L_48 ) ;
if ( V_230 == 1 )
F_251 ( V_15 , V_530 ) ;
else
F_251 ( V_15 , V_531 ) ;
error = F_252 ( V_15 , & V_13 -> V_56 ) ;
if ( error ) {
F_127 ( V_30 L_121 , V_32 ) ;
error = - V_509 ;
F_253 ( V_15 ) ;
} else
F_254 ( V_15 ) ;
return error ;
}
static int F_255 ( struct V_31 * V_56 )
{
struct V_12 * V_13 ;
struct V_61 * V_446 , * V_447 ;
V_13 = F_229 ( V_56 ) ;
if ( ! V_13 ) {
F_127 ( V_30 L_122 ,
V_32 ) ;
return - V_509 ;
}
F_256 ( V_13 -> V_17 ) ;
F_233 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_234 ( & V_446 -> V_323 ) ;
F_37 ( V_446 ) ;
}
F_253 ( V_13 -> V_17 ) ;
return 0 ;
}
static int F_257 ( struct V_31 * V_56 ,
struct V_418 * V_532 )
{
return 1 ;
}
