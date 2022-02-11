static unsigned int F_1 ( void )
{
return V_1 | V_2 | V_3 ;
}
static void * F_2 ( unsigned long long V_4 )
{
V_4 = F_3 ( V_4 , V_5 ) ;
return V_6 + V_4 * V_7 ;
}
static struct V_8 * F_4 ( T_1 V_9 )
{
V_9 = F_3 ( V_9 , V_5 ) ;
return V_10 + V_9 ;
}
static void F_5 ( void )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
F_6 ( & V_15 ) ;
F_7 (sdbg_host, &sdebug_host_list, host_list) {
V_14 = V_12 -> V_16 ;
if ( ( V_14 -> V_17 >= 0 ) &&
( V_18 > V_14 -> V_17 ) )
V_14 -> V_19 = V_18 + 1 ;
else
V_14 -> V_19 = V_18 ;
V_14 -> V_20 = V_21 ;
}
F_8 ( & V_15 ) ;
}
static void F_9 ( struct V_22 * V_23 , int V_24 ,
int V_25 , int V_26 )
{
unsigned char * V_27 ;
V_27 = V_23 -> V_28 ;
memset ( V_27 , 0 , V_29 ) ;
F_10 ( V_30 , V_27 , V_24 , V_25 , V_26 ) ;
if ( V_31 & V_32 )
F_11 ( V_33 L_1
L_2 , V_24 , V_25 , V_26 ) ;
}
static void F_12 ( unsigned char * V_34 ,
unsigned long long * V_4 , unsigned int * V_35 ,
T_2 * V_36 )
{
* V_36 = 0 ;
switch ( * V_34 ) {
case V_37 :
* V_4 = ( V_38 ) V_34 [ 19 ] | ( V_38 ) V_34 [ 18 ] << 8 |
( V_38 ) V_34 [ 17 ] << 16 | ( V_38 ) V_34 [ 16 ] << 24 |
( V_38 ) V_34 [ 15 ] << 32 | ( V_38 ) V_34 [ 14 ] << 40 |
( V_38 ) V_34 [ 13 ] << 48 | ( V_38 ) V_34 [ 12 ] << 56 ;
* V_36 = ( T_2 ) V_34 [ 23 ] | ( T_2 ) V_34 [ 22 ] << 8 |
( T_2 ) V_34 [ 21 ] << 16 | ( T_2 ) V_34 [ 20 ] << 24 ;
* V_35 = ( T_2 ) V_34 [ 31 ] | ( T_2 ) V_34 [ 30 ] << 8 | ( T_2 ) V_34 [ 29 ] << 16 |
( T_2 ) V_34 [ 28 ] << 24 ;
break;
case V_39 :
case V_40 :
case V_41 :
* V_4 = ( V_38 ) V_34 [ 9 ] | ( V_38 ) V_34 [ 8 ] << 8 |
( V_38 ) V_34 [ 7 ] << 16 | ( V_38 ) V_34 [ 6 ] << 24 |
( V_38 ) V_34 [ 5 ] << 32 | ( V_38 ) V_34 [ 4 ] << 40 |
( V_38 ) V_34 [ 3 ] << 48 | ( V_38 ) V_34 [ 2 ] << 56 ;
* V_35 = ( T_2 ) V_34 [ 13 ] | ( T_2 ) V_34 [ 12 ] << 8 | ( T_2 ) V_34 [ 11 ] << 16 |
( T_2 ) V_34 [ 10 ] << 24 ;
break;
case V_42 :
case V_43 :
* V_4 = ( T_2 ) V_34 [ 5 ] | ( T_2 ) V_34 [ 4 ] << 8 | ( T_2 ) V_34 [ 3 ] << 16 |
( T_2 ) V_34 [ 2 ] << 24 ;
* V_35 = ( T_2 ) V_34 [ 9 ] | ( T_2 ) V_34 [ 8 ] << 8 | ( T_2 ) V_34 [ 7 ] << 16 |
( T_2 ) V_34 [ 6 ] << 24 ;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
* V_4 = ( T_2 ) V_34 [ 5 ] | ( T_2 ) V_34 [ 4 ] << 8 | ( T_2 ) V_34 [ 3 ] << 16 |
( T_2 ) V_34 [ 2 ] << 24 ;
* V_35 = ( T_2 ) V_34 [ 8 ] | ( T_2 ) V_34 [ 7 ] << 8 ;
break;
case V_48 :
case V_49 :
* V_4 = ( T_2 ) V_34 [ 3 ] | ( T_2 ) V_34 [ 2 ] << 8 |
( T_2 ) ( V_34 [ 1 ] & 0x1f ) << 16 ;
* V_35 = ( 0 == V_34 [ 4 ] ) ? 256 : V_34 [ 4 ] ;
break;
default:
break;
}
}
static int F_13 ( struct V_50 * V_51 , int V_34 , void T_3 * V_52 )
{
if ( V_31 & V_32 ) {
F_11 ( V_33 L_3 , V_34 ) ;
}
return - V_53 ;
}
static int F_14 ( struct V_54 * V_55 , int V_56 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_57 ) {
if ( V_31 & V_32 )
F_11 ( V_33 L_4
L_5 ) ;
V_23 -> V_57 = 0 ;
F_9 ( V_23 , V_58 , V_59 , 0 ) ;
return V_60 ;
}
if ( ( 0 == V_56 ) && V_23 -> V_61 ) {
if ( V_31 & V_32 )
F_11 ( V_33 L_6
L_7 ) ;
F_9 ( V_23 , V_62 , V_63 ,
0x2 ) ;
return V_60 ;
}
return 0 ;
}
static int F_15 ( struct V_54 * V_64 , unsigned char * V_65 ,
int V_66 )
{
int V_67 ;
struct V_68 * V_69 = F_16 ( V_64 ) ;
if ( ! V_69 -> V_70 )
return 0 ;
if ( ! ( F_17 ( V_64 ) || V_64 -> V_71 == V_72 ) )
return ( V_73 << 16 ) ;
V_67 = F_18 ( V_69 -> V_74 . V_75 , V_69 -> V_74 . V_76 ,
V_65 , V_66 ) ;
V_69 -> V_77 = F_19 ( V_64 ) - V_67 ;
return 0 ;
}
static int F_20 ( struct V_54 * V_64 , unsigned char * V_65 ,
int V_66 )
{
if ( ! F_19 ( V_64 ) )
return 0 ;
if ( ! ( F_17 ( V_64 ) || V_64 -> V_71 == V_78 ) )
return - 1 ;
return F_21 ( V_64 , V_65 , V_66 ) ;
}
static int F_22 ( unsigned char * V_65 , int V_79 ,
int V_80 , int V_81 ,
const char * V_82 ,
int V_83 )
{
int V_35 , V_84 ;
char V_85 [ 32 ] ;
V_84 = V_80 + 1 ;
V_65 [ 0 ] = 0x2 ;
V_65 [ 1 ] = 0x1 ;
V_65 [ 2 ] = 0x0 ;
memcpy ( & V_65 [ 4 ] , V_86 , 8 ) ;
memcpy ( & V_65 [ 12 ] , V_87 , 16 ) ;
memcpy ( & V_65 [ 28 ] , V_82 , V_83 ) ;
V_35 = 8 + 16 + V_83 ;
V_65 [ 3 ] = V_35 ;
V_35 += 4 ;
if ( V_81 >= 0 ) {
V_65 [ V_35 ++ ] = 0x1 ;
V_65 [ V_35 ++ ] = 0x3 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x8 ;
V_65 [ V_35 ++ ] = 0x53 ;
V_65 [ V_35 ++ ] = 0x33 ;
V_65 [ V_35 ++ ] = 0x33 ;
V_65 [ V_35 ++ ] = 0x30 ;
V_65 [ V_35 ++ ] = ( V_81 >> 24 ) ;
V_65 [ V_35 ++ ] = ( V_81 >> 16 ) & 0xff ;
V_65 [ V_35 ++ ] = ( V_81 >> 8 ) & 0xff ;
V_65 [ V_35 ++ ] = V_81 & 0xff ;
V_65 [ V_35 ++ ] = 0x61 ;
V_65 [ V_35 ++ ] = 0x94 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x4 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x1 ;
}
V_65 [ V_35 ++ ] = 0x61 ;
V_65 [ V_35 ++ ] = 0x93 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x8 ;
V_65 [ V_35 ++ ] = 0x52 ;
V_65 [ V_35 ++ ] = 0x22 ;
V_65 [ V_35 ++ ] = 0x22 ;
V_65 [ V_35 ++ ] = 0x20 ;
V_65 [ V_35 ++ ] = ( V_84 >> 24 ) ;
V_65 [ V_35 ++ ] = ( V_84 >> 16 ) & 0xff ;
V_65 [ V_35 ++ ] = ( V_84 >> 8 ) & 0xff ;
V_65 [ V_35 ++ ] = V_84 & 0xff ;
V_65 [ V_35 ++ ] = 0x61 ;
V_65 [ V_35 ++ ] = 0x95 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x4 ;
V_65 [ V_35 ++ ] = 0 ;
V_65 [ V_35 ++ ] = 0 ;
V_65 [ V_35 ++ ] = ( V_79 >> 8 ) & 0xff ;
V_65 [ V_35 ++ ] = V_79 & 0xff ;
V_65 [ V_35 ++ ] = 0x61 ;
V_65 [ V_35 ++ ] = 0xa3 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x8 ;
V_65 [ V_35 ++ ] = 0x52 ;
V_65 [ V_35 ++ ] = 0x22 ;
V_65 [ V_35 ++ ] = 0x22 ;
V_65 [ V_35 ++ ] = 0x20 ;
V_65 [ V_35 ++ ] = ( V_80 >> 24 ) ;
V_65 [ V_35 ++ ] = ( V_80 >> 16 ) & 0xff ;
V_65 [ V_35 ++ ] = ( V_80 >> 8 ) & 0xff ;
V_65 [ V_35 ++ ] = V_80 & 0xff ;
V_65 [ V_35 ++ ] = 0x63 ;
V_65 [ V_35 ++ ] = 0xa8 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 24 ;
memcpy ( V_65 + V_35 , L_8 , 12 ) ;
V_35 += 12 ;
snprintf ( V_85 , sizeof( V_85 ) , L_9 , V_80 ) ;
memcpy ( V_65 + V_35 , V_85 , 8 ) ;
V_35 += 8 ;
memset ( V_65 + V_35 , 0 , 4 ) ;
V_35 += 4 ;
return V_35 ;
}
static int F_23 ( unsigned char * V_65 )
{
memcpy ( V_65 , V_88 , sizeof( V_88 ) ) ;
return sizeof( V_88 ) ;
}
static int F_24 ( unsigned char * V_65 )
{
int V_35 = 0 ;
const char * V_89 = L_10 ;
const char * V_90 = L_11 ;
int V_91 , V_92 ;
V_65 [ V_35 ++ ] = 0x1 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_92 = strlen ( V_89 ) ;
V_91 = V_92 + 1 ;
if ( V_91 % 4 )
V_91 = ( ( V_91 / 4 ) + 1 ) * 4 ;
V_65 [ V_35 ++ ] = V_91 ;
memcpy ( V_65 + V_35 , V_89 , V_92 ) ;
memset ( V_65 + V_35 + V_92 , 0 , V_91 - V_92 ) ;
V_35 += V_91 ;
V_65 [ V_35 ++ ] = 0x4 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_92 = strlen ( V_90 ) ;
V_91 = V_92 + 1 ;
if ( V_91 % 4 )
V_91 = ( ( V_91 / 4 ) + 1 ) * 4 ;
V_65 [ V_35 ++ ] = V_91 ;
memcpy ( V_65 + V_35 , V_90 , V_92 ) ;
memset ( V_65 + V_35 + V_92 , 0 , V_91 - V_92 ) ;
V_35 += V_91 ;
return V_35 ;
}
static int F_25 ( unsigned char * V_65 , int V_80 )
{
int V_35 = 0 ;
int V_84 , V_93 ;
V_84 = V_80 + 1 ;
V_93 = V_84 + 1 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x1 ;
memset ( V_65 + V_35 , 0 , 6 ) ;
V_35 += 6 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 12 ;
V_65 [ V_35 ++ ] = 0x61 ;
V_65 [ V_35 ++ ] = 0x93 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x8 ;
V_65 [ V_35 ++ ] = 0x52 ;
V_65 [ V_35 ++ ] = 0x22 ;
V_65 [ V_35 ++ ] = 0x22 ;
V_65 [ V_35 ++ ] = 0x20 ;
V_65 [ V_35 ++ ] = ( V_84 >> 24 ) ;
V_65 [ V_35 ++ ] = ( V_84 >> 16 ) & 0xff ;
V_65 [ V_35 ++ ] = ( V_84 >> 8 ) & 0xff ;
V_65 [ V_35 ++ ] = V_84 & 0xff ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x2 ;
memset ( V_65 + V_35 , 0 , 6 ) ;
V_35 += 6 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 12 ;
V_65 [ V_35 ++ ] = 0x61 ;
V_65 [ V_35 ++ ] = 0x93 ;
V_65 [ V_35 ++ ] = 0x0 ;
V_65 [ V_35 ++ ] = 0x8 ;
V_65 [ V_35 ++ ] = 0x52 ;
V_65 [ V_35 ++ ] = 0x22 ;
V_65 [ V_35 ++ ] = 0x22 ;
V_65 [ V_35 ++ ] = 0x20 ;
V_65 [ V_35 ++ ] = ( V_93 >> 24 ) ;
V_65 [ V_35 ++ ] = ( V_93 >> 16 ) & 0xff ;
V_65 [ V_35 ++ ] = ( V_93 >> 8 ) & 0xff ;
V_65 [ V_35 ++ ] = V_93 & 0xff ;
return V_35 ;
}
static int F_26 ( unsigned char * V_65 )
{
memcpy ( V_65 , V_94 , sizeof( V_94 ) ) ;
return sizeof( V_94 ) ;
}
static int F_27 ( unsigned char * V_65 )
{
unsigned int V_95 ;
memcpy ( V_65 , V_96 , sizeof( V_96 ) ) ;
V_95 = 1 << V_97 ;
V_65 [ 2 ] = ( V_95 >> 8 ) & 0xff ;
V_65 [ 3 ] = V_95 & 0xff ;
if ( V_5 > 0x400 ) {
V_65 [ 4 ] = ( V_5 >> 24 ) & 0xff ;
V_65 [ 5 ] = ( V_5 >> 16 ) & 0xff ;
V_65 [ 6 ] = ( V_5 >> 8 ) & 0xff ;
V_65 [ 7 ] = V_5 & 0xff ;
}
F_28 ( V_98 , & V_65 [ 8 ] ) ;
if ( V_1 ) {
F_28 ( V_99 , & V_65 [ 16 ] ) ;
F_28 ( V_100 , & V_65 [ 20 ] ) ;
}
if ( V_101 ) {
F_28 ( V_101 , & V_65 [ 28 ] ) ;
V_65 [ 28 ] |= 0x80 ;
}
F_28 ( V_102 , & V_65 [ 24 ] ) ;
F_29 ( V_103 , & V_65 [ 32 ] ) ;
return 0x3c ;
return sizeof( V_96 ) ;
}
static int F_30 ( unsigned char * V_65 )
{
memset ( V_65 , 0 , 0x3c ) ;
V_65 [ 0 ] = 0 ;
V_65 [ 1 ] = 1 ;
V_65 [ 2 ] = 0 ;
V_65 [ 3 ] = 5 ;
return 0x3c ;
}
static int F_31 ( unsigned char * V_65 )
{
memset ( V_65 , 0 , 0x4 ) ;
V_65 [ 0 ] = 0 ;
if ( V_1 )
V_65 [ 1 ] = 1 << 7 ;
if ( V_2 )
V_65 [ 1 ] |= 1 << 6 ;
if ( V_3 )
V_65 [ 1 ] |= 1 << 5 ;
if ( V_104 )
V_65 [ 1 ] |= 1 << 2 ;
return 0x4 ;
}
static int F_32 ( struct V_54 * V_64 , int V_105 ,
struct V_22 * V_23 )
{
unsigned char V_106 ;
unsigned char * V_65 ;
unsigned char * V_34 = ( unsigned char * ) V_64 -> V_107 ;
int V_108 , V_109 , V_110 ;
V_108 = ( V_34 [ 3 ] << 8 ) + V_34 [ 4 ] ;
V_65 = F_33 ( V_111 , V_112 ) ;
if ( ! V_65 )
return V_113 << 16 ;
if ( V_23 -> V_114 )
V_106 = 0x1e ;
else if ( V_115 && ( 0 == V_23 -> V_116 ) )
V_106 = 0x7f ;
else
V_106 = ( V_117 & 0x1f ) ;
V_65 [ 0 ] = V_106 ;
if ( 0x2 & V_34 [ 1 ] ) {
F_9 ( V_23 , V_118 , V_119 ,
0 ) ;
F_34 ( V_65 ) ;
return V_60 ;
} else if ( 0x1 & V_34 [ 1 ] ) {
int V_120 , V_79 , V_80 , V_121 ;
char V_122 [ 6 ] ;
int V_123 = V_23 -> V_12 -> V_16 -> V_123 ;
V_79 = ( ( ( V_123 + 1 ) & 0x7f ) << 8 ) +
( V_23 -> V_124 & 0x7f ) ;
if ( 0 == V_125 )
V_123 = 0 ;
V_120 = V_23 -> V_114 ? - 1 : ( ( ( V_123 + 1 ) * 2000 ) +
( V_23 -> V_105 * 1000 ) + V_23 -> V_116 ) ;
V_80 = ( ( V_123 + 1 ) * 2000 ) +
( V_23 -> V_105 * 1000 ) - 3 ;
V_121 = F_35 ( V_122 , 6 , L_12 , V_120 ) ;
if ( 0 == V_34 [ 2 ] ) {
V_65 [ 1 ] = V_34 [ 2 ] ;
V_109 = 4 ;
V_65 [ V_109 ++ ] = 0x0 ;
V_65 [ V_109 ++ ] = 0x80 ;
V_65 [ V_109 ++ ] = 0x83 ;
V_65 [ V_109 ++ ] = 0x84 ;
V_65 [ V_109 ++ ] = 0x85 ;
V_65 [ V_109 ++ ] = 0x86 ;
V_65 [ V_109 ++ ] = 0x87 ;
V_65 [ V_109 ++ ] = 0x88 ;
V_65 [ V_109 ++ ] = 0x89 ;
V_65 [ V_109 ++ ] = 0xb0 ;
V_65 [ V_109 ++ ] = 0xb1 ;
if ( F_1 () )
V_65 [ V_109 ++ ] = 0xb2 ;
V_65 [ 3 ] = V_109 - 4 ;
} else if ( 0x80 == V_34 [ 2 ] ) {
V_65 [ 1 ] = V_34 [ 2 ] ;
V_65 [ 3 ] = V_121 ;
memcpy ( & V_65 [ 4 ] , V_122 , V_121 ) ;
} else if ( 0x83 == V_34 [ 2 ] ) {
V_65 [ 1 ] = V_34 [ 2 ] ;
V_65 [ 3 ] = F_22 ( & V_65 [ 4 ] , V_79 ,
V_80 , V_120 ,
V_122 , V_121 ) ;
} else if ( 0x84 == V_34 [ 2 ] ) {
V_65 [ 1 ] = V_34 [ 2 ] ;
V_65 [ 3 ] = F_23 ( & V_65 [ 4 ] ) ;
} else if ( 0x85 == V_34 [ 2 ] ) {
V_65 [ 1 ] = V_34 [ 2 ] ;
V_65 [ 3 ] = F_24 ( & V_65 [ 4 ] ) ;
} else if ( 0x86 == V_34 [ 2 ] ) {
V_65 [ 1 ] = V_34 [ 2 ] ;
V_65 [ 3 ] = 0x3c ;
if ( V_126 == V_127 )
V_65 [ 4 ] = 0x4 ;
else if ( V_126 )
V_65 [ 4 ] = 0x5 ;
else
V_65 [ 4 ] = 0x0 ;
V_65 [ 5 ] = 0x7 ;
} else if ( 0x87 == V_34 [ 2 ] ) {
V_65 [ 1 ] = V_34 [ 2 ] ;
V_65 [ 3 ] = 0x8 ;
V_65 [ 4 ] = 0x2 ;
V_65 [ 6 ] = 0x80 ;
V_65 [ 8 ] = 0x18 ;
V_65 [ 10 ] = 0x82 ;
} else if ( 0x88 == V_34 [ 2 ] ) {
V_65 [ 1 ] = V_34 [ 2 ] ;
V_65 [ 3 ] = F_25 ( & V_65 [ 4 ] , V_80 ) ;
} else if ( 0x89 == V_34 [ 2 ] ) {
V_65 [ 1 ] = V_34 [ 2 ] ;
V_109 = F_26 ( & V_65 [ 4 ] ) ;
V_65 [ 2 ] = ( V_109 >> 8 ) ;
V_65 [ 3 ] = ( V_109 & 0xff ) ;
} else if ( 0xb0 == V_34 [ 2 ] ) {
V_65 [ 1 ] = V_34 [ 2 ] ;
V_65 [ 3 ] = F_27 ( & V_65 [ 4 ] ) ;
} else if ( 0xb1 == V_34 [ 2 ] ) {
V_65 [ 1 ] = V_34 [ 2 ] ;
V_65 [ 3 ] = F_30 ( & V_65 [ 4 ] ) ;
} else if ( 0xb2 == V_34 [ 2 ] ) {
V_65 [ 1 ] = V_34 [ 2 ] ;
V_65 [ 3 ] = F_31 ( & V_65 [ 4 ] ) ;
} else {
F_9 ( V_23 , V_118 ,
V_119 , 0 ) ;
F_34 ( V_65 ) ;
return V_60 ;
}
V_121 = F_36 ( ( ( V_65 [ 2 ] << 8 ) + V_65 [ 3 ] ) + 4 , V_108 ) ;
V_110 = F_15 ( V_64 , V_65 ,
F_36 ( V_121 , V_111 ) ) ;
F_34 ( V_65 ) ;
return V_110 ;
}
V_65 [ 1 ] = V_128 ? 0x80 : 0 ;
V_65 [ 2 ] = V_129 ;
V_65 [ 3 ] = 2 ;
V_65 [ 4 ] = V_130 - 5 ;
V_65 [ 5 ] = V_126 ? 1 : 0 ;
if ( 0 == V_125 )
V_65 [ 5 ] = 0x10 ;
V_65 [ 6 ] = 0x10 ;
V_65 [ 7 ] = 0xa ;
memcpy ( & V_65 [ 8 ] , V_86 , 8 ) ;
memcpy ( & V_65 [ 16 ] , V_87 , 16 ) ;
memcpy ( & V_65 [ 32 ] , V_131 , 4 ) ;
V_65 [ 58 ] = 0x0 ; V_65 [ 59 ] = 0x77 ;
V_65 [ 60 ] = 0x3 ; V_65 [ 61 ] = 0x14 ;
V_109 = 62 ;
if ( V_117 == 0 ) {
V_65 [ V_109 ++ ] = 0x3 ; V_65 [ V_109 ++ ] = 0x3d ;
} else if ( V_117 == 1 ) {
V_65 [ V_109 ++ ] = 0x3 ; V_65 [ V_109 ++ ] = 0x60 ;
}
V_65 [ V_109 ++ ] = 0xc ; V_65 [ V_109 ++ ] = 0xf ;
V_110 = F_15 ( V_64 , V_65 ,
F_36 ( V_108 , V_130 ) ) ;
F_34 ( V_65 ) ;
return V_110 ;
}
static int F_37 ( struct V_54 * V_64 ,
struct V_22 * V_23 )
{
unsigned char * V_27 ;
unsigned char * V_34 = ( unsigned char * ) V_64 -> V_107 ;
unsigned char V_65 [ V_29 ] ;
int V_132 ;
int V_121 = 18 ;
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
if ( V_23 -> V_57 == 1 )
F_9 ( V_23 , 0 , V_133 , 0 ) ;
V_132 = ! ! ( V_34 [ 1 ] & 1 ) || V_30 ;
V_27 = V_23 -> V_28 ;
if ( ( V_134 [ 2 ] & 0x4 ) && ( 6 == ( V_134 [ 3 ] & 0xf ) ) ) {
if ( V_132 ) {
V_65 [ 0 ] = 0x72 ;
V_65 [ 1 ] = 0x0 ;
V_65 [ 2 ] = V_135 ;
V_65 [ 3 ] = 0xff ;
} else {
V_65 [ 0 ] = 0x70 ;
V_65 [ 2 ] = 0x0 ;
V_65 [ 7 ] = 0xa ;
V_65 [ 12 ] = V_135 ;
V_65 [ 13 ] = 0xff ;
}
} else {
memcpy ( V_65 , V_27 , V_29 ) ;
if ( ( V_34 [ 1 ] & 1 ) && ( ! V_30 ) ) {
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
V_65 [ 0 ] = 0x72 ;
V_65 [ 1 ] = V_27 [ 2 ] ;
V_65 [ 2 ] = V_27 [ 12 ] ;
V_65 [ 3 ] = V_27 [ 13 ] ;
V_121 = 8 ;
}
}
F_9 ( V_23 , 0 , V_133 , 0 ) ;
return F_15 ( V_64 , V_65 , V_121 ) ;
}
static int F_38 ( struct V_54 * V_64 ,
struct V_22 * V_23 )
{
unsigned char * V_34 = ( unsigned char * ) V_64 -> V_107 ;
int V_136 , V_137 , V_138 ;
if ( ( V_137 = F_14 ( V_64 , 1 , V_23 ) ) )
return V_137 ;
V_136 = ( V_34 [ 4 ] & 0xf0 ) >> 4 ;
if ( V_136 ) {
F_9 ( V_23 , V_118 , V_119 ,
0 ) ;
return V_60 ;
}
V_138 = V_34 [ 4 ] & 1 ;
if ( V_138 == V_23 -> V_61 )
V_23 -> V_61 = ! V_138 ;
return 0 ;
}
static T_1 F_39 ( void )
{
if ( V_139 > 0 )
return ( T_1 ) V_139 *
( 1073741824 / V_7 ) ;
else
return V_5 ;
}
static int F_40 ( struct V_54 * V_64 ,
struct V_22 * V_23 )
{
unsigned char V_65 [ V_140 ] ;
unsigned int V_141 ;
int V_137 ;
if ( ( V_137 = F_14 ( V_64 , 1 , V_23 ) ) )
return V_137 ;
V_142 = F_39 () ;
memset ( V_65 , 0 , V_140 ) ;
if ( V_142 < 0xffffffff ) {
V_141 = ( unsigned int ) V_142 - 1 ;
V_65 [ 0 ] = ( V_141 >> 24 ) ;
V_65 [ 1 ] = ( V_141 >> 16 ) & 0xff ;
V_65 [ 2 ] = ( V_141 >> 8 ) & 0xff ;
V_65 [ 3 ] = V_141 & 0xff ;
} else {
V_65 [ 0 ] = 0xff ;
V_65 [ 1 ] = 0xff ;
V_65 [ 2 ] = 0xff ;
V_65 [ 3 ] = 0xff ;
}
V_65 [ 6 ] = ( V_7 >> 8 ) & 0xff ;
V_65 [ 7 ] = V_7 & 0xff ;
return F_15 ( V_64 , V_65 , V_140 ) ;
}
static int F_41 ( struct V_54 * V_64 ,
struct V_22 * V_23 )
{
unsigned char * V_34 = ( unsigned char * ) V_64 -> V_107 ;
unsigned char V_65 [ V_143 ] ;
unsigned long long V_141 ;
int V_137 , V_144 , V_108 ;
if ( ( V_137 = F_14 ( V_64 , 1 , V_23 ) ) )
return V_137 ;
V_108 = ( ( V_34 [ 10 ] << 24 ) + ( V_34 [ 11 ] << 16 ) + ( V_34 [ 12 ] << 8 )
+ V_34 [ 13 ] ) ;
V_142 = F_39 () ;
memset ( V_65 , 0 , V_143 ) ;
V_141 = V_142 - 1 ;
for ( V_144 = 0 ; V_144 < 8 ; ++ V_144 , V_141 >>= 8 )
V_65 [ 7 - V_144 ] = V_141 & 0xff ;
V_65 [ 8 ] = ( V_7 >> 24 ) & 0xff ;
V_65 [ 9 ] = ( V_7 >> 16 ) & 0xff ;
V_65 [ 10 ] = ( V_7 >> 8 ) & 0xff ;
V_65 [ 11 ] = V_7 & 0xff ;
V_65 [ 13 ] = V_97 & 0xf ;
V_65 [ 14 ] = ( V_145 >> 8 ) & 0x3f ;
if ( F_1 () ) {
V_65 [ 14 ] |= 0x80 ;
if ( V_104 )
V_65 [ 14 ] |= 0x40 ;
}
V_65 [ 15 ] = V_145 & 0xff ;
if ( V_126 ) {
V_65 [ 12 ] = ( V_126 - 1 ) << 1 ;
V_65 [ 12 ] |= 1 ;
}
return F_15 ( V_64 , V_65 ,
F_36 ( V_108 , V_143 ) ) ;
}
static int F_42 ( struct V_54 * V_64 ,
struct V_22 * V_23 )
{
unsigned char * V_34 = ( unsigned char * ) V_64 -> V_107 ;
unsigned char * V_65 ;
int V_123 = V_23 -> V_12 -> V_16 -> V_123 ;
int V_109 , V_110 , V_146 , V_147 ;
int V_148 , V_149 , V_84 , V_93 ;
V_146 = ( ( V_34 [ 6 ] << 24 ) + ( V_34 [ 7 ] << 16 ) + ( V_34 [ 8 ] << 8 )
+ V_34 [ 9 ] ) ;
V_65 = F_33 ( V_150 , V_112 ) ;
if ( ! V_65 )
return V_113 << 16 ;
V_84 = 0x1 ;
V_93 = 0x2 ;
V_148 = ( ( ( V_123 + 1 ) & 0x7f ) << 8 ) +
( V_23 -> V_124 & 0x7f ) ;
V_149 = ( ( ( V_123 + 1 ) & 0x7f ) << 8 ) +
( V_23 -> V_124 & 0x7f ) + 0x80 ;
V_109 = 4 ;
if ( 0 == V_125 ) {
V_65 [ V_109 ++ ] = V_123 % 3 ;
V_65 [ V_109 ++ ] = 0x0F ;
} else {
V_65 [ V_109 ++ ] = 0x0 ;
V_65 [ V_109 ++ ] = 0x01 ;
}
V_65 [ V_109 ++ ] = ( V_148 >> 8 ) & 0xff ;
V_65 [ V_109 ++ ] = V_148 & 0xff ;
V_65 [ V_109 ++ ] = 0 ;
V_65 [ V_109 ++ ] = 0 ;
V_65 [ V_109 ++ ] = 0 ;
V_65 [ V_109 ++ ] = 0x1 ;
V_65 [ V_109 ++ ] = 0 ;
V_65 [ V_109 ++ ] = 0 ;
V_65 [ V_109 ++ ] = ( V_84 >> 8 ) & 0xff ;
V_65 [ V_109 ++ ] = V_84 & 0xff ;
V_65 [ V_109 ++ ] = 3 ;
V_65 [ V_109 ++ ] = 0x08 ;
V_65 [ V_109 ++ ] = ( V_149 >> 8 ) & 0xff ;
V_65 [ V_109 ++ ] = V_149 & 0xff ;
V_65 [ V_109 ++ ] = 0 ;
V_65 [ V_109 ++ ] = 0 ;
V_65 [ V_109 ++ ] = 0 ;
V_65 [ V_109 ++ ] = 0x1 ;
V_65 [ V_109 ++ ] = 0 ;
V_65 [ V_109 ++ ] = 0 ;
V_65 [ V_109 ++ ] = ( V_93 >> 8 ) & 0xff ;
V_65 [ V_109 ++ ] = V_93 & 0xff ;
V_147 = V_109 - 4 ;
V_65 [ 0 ] = ( V_147 >> 24 ) & 0xff ;
V_65 [ 1 ] = ( V_147 >> 16 ) & 0xff ;
V_65 [ 2 ] = ( V_147 >> 8 ) & 0xff ;
V_65 [ 3 ] = V_147 & 0xff ;
V_147 = F_36 ( V_146 , V_109 ) ;
V_110 = F_15 ( V_64 , V_65 ,
F_36 ( V_147 , V_150 ) ) ;
F_34 ( V_65 ) ;
return V_110 ;
}
static int F_43 ( unsigned char * V_151 , int V_152 , int V_105 )
{
unsigned char V_153 [] = { 0x1 , 0xa , 0xc0 , 11 , 240 , 0 , 0 , 0 ,
5 , 0 , 0xff , 0xff } ;
memcpy ( V_151 , V_153 , sizeof( V_153 ) ) ;
if ( 1 == V_152 )
memset ( V_151 + 2 , 0 , sizeof( V_153 ) - 2 ) ;
return sizeof( V_153 ) ;
}
static int F_44 ( unsigned char * V_151 , int V_152 , int V_105 )
{
unsigned char V_154 [] = { 0x2 , 0xe , 128 , 128 , 0 , 10 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_151 , V_154 , sizeof( V_154 ) ) ;
if ( 1 == V_152 )
memset ( V_151 + 2 , 0 , sizeof( V_154 ) - 2 ) ;
return sizeof( V_154 ) ;
}
static int F_45 ( unsigned char * V_151 , int V_152 , int V_105 )
{
unsigned char V_155 [] = { 0x3 , 0x16 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0x40 , 0 , 0 , 0 } ;
memcpy ( V_151 , V_155 , sizeof( V_155 ) ) ;
V_151 [ 10 ] = ( V_156 >> 8 ) & 0xff ;
V_151 [ 11 ] = V_156 & 0xff ;
V_151 [ 12 ] = ( V_7 >> 8 ) & 0xff ;
V_151 [ 13 ] = V_7 & 0xff ;
if ( V_128 )
V_151 [ 20 ] |= 0x20 ;
if ( 1 == V_152 )
memset ( V_151 + 2 , 0 , sizeof( V_155 ) - 2 ) ;
return sizeof( V_155 ) ;
}
static int F_46 ( unsigned char * V_151 , int V_152 , int V_105 )
{
unsigned char V_157 [] = { 0x8 , 18 , 0x14 , 0 , 0xff , 0xff , 0 , 0 ,
0xff , 0xff , 0xff , 0xff , 0x80 , 0x14 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_151 , V_157 , sizeof( V_157 ) ) ;
if ( 1 == V_152 )
memset ( V_151 + 2 , 0 , sizeof( V_157 ) - 2 ) ;
return sizeof( V_157 ) ;
}
static int F_47 ( unsigned char * V_151 , int V_152 , int V_105 )
{
unsigned char V_158 [] = { 0x6 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ;
unsigned char V_159 [] = { 0xa , 10 , 2 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x2 , 0x4b } ;
if ( V_30 )
V_160 [ 2 ] |= 0x4 ;
else
V_160 [ 2 ] &= ~ 0x4 ;
if ( V_161 )
V_160 [ 5 ] |= 0x80 ;
memcpy ( V_151 , V_160 , sizeof( V_160 ) ) ;
if ( 1 == V_152 )
memcpy ( V_151 + 2 , V_158 , sizeof( V_158 ) ) ;
else if ( 2 == V_152 )
memcpy ( V_151 , V_159 , sizeof( V_159 ) ) ;
return sizeof( V_160 ) ;
}
static int F_48 ( unsigned char * V_151 , int V_152 , int V_105 )
{
unsigned char V_162 [] = { 0x4 , 0xf , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
unsigned char V_163 [] = { 0x1c , 0xa , 0x08 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
memcpy ( V_151 , V_134 , sizeof( V_134 ) ) ;
if ( 1 == V_152 )
memcpy ( V_151 + 2 , V_162 , sizeof( V_162 ) ) ;
else if ( 2 == V_152 )
memcpy ( V_151 , V_163 , sizeof( V_163 ) ) ;
return sizeof( V_134 ) ;
}
static int F_49 ( unsigned char * V_151 , int V_152 , int V_105 )
{
unsigned char V_164 [] = { 0x19 , 0x6 ,
0x6 , 0x0 , 0x7 , 0xd0 , 0x0 , 0x0 } ;
memcpy ( V_151 , V_164 , sizeof( V_164 ) ) ;
if ( 1 == V_152 )
memset ( V_151 + 2 , 0 , sizeof( V_164 ) - 2 ) ;
return sizeof( V_164 ) ;
}
static int F_50 ( unsigned char * V_151 , int V_152 , int V_105 ,
int V_80 )
{
unsigned char V_165 [] = { 0x59 , 0x1 , 0 , 0x64 , 0 , 0x6 , 0 , 2 ,
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
int V_84 , V_93 ;
V_84 = V_80 + 1 ;
V_93 = V_84 + 1 ;
memcpy ( V_151 , V_165 , sizeof( V_165 ) ) ;
V_151 [ 20 ] = ( V_84 >> 24 ) ;
V_151 [ 21 ] = ( V_84 >> 16 ) & 0xff ;
V_151 [ 22 ] = ( V_84 >> 8 ) & 0xff ;
V_151 [ 23 ] = V_84 & 0xff ;
V_151 [ 48 + 20 ] = ( V_93 >> 24 ) ;
V_151 [ 48 + 21 ] = ( V_93 >> 16 ) & 0xff ;
V_151 [ 48 + 22 ] = ( V_93 >> 8 ) & 0xff ;
V_151 [ 48 + 23 ] = V_93 & 0xff ;
if ( 1 == V_152 )
memset ( V_151 + 4 , 0 , sizeof( V_165 ) - 4 ) ;
return sizeof( V_165 ) ;
}
static int F_51 ( unsigned char * V_151 , int V_152 )
{
unsigned char V_166 [] = { 0x59 , 0x2 , 0 , 0xc , 0 , 0x6 , 0x10 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
memcpy ( V_151 , V_166 , sizeof( V_166 ) ) ;
if ( 1 == V_152 )
memset ( V_151 + 4 , 0 , sizeof( V_166 ) - 4 ) ;
return sizeof( V_166 ) ;
}
static int F_52 ( struct V_54 * V_64 , int V_105 ,
struct V_22 * V_23 )
{
unsigned char V_167 , V_168 ;
int V_152 , V_169 , V_170 , V_171 ;
unsigned char V_172 ;
int V_144 , V_108 , V_173 , V_174 , V_121 , V_137 , V_80 ;
unsigned char * V_175 ;
unsigned char V_65 [ V_176 ] ;
unsigned char * V_34 = ( unsigned char * ) V_64 -> V_107 ;
if ( ( V_137 = F_14 ( V_64 , 1 , V_23 ) ) )
return V_137 ;
V_167 = ! ! ( V_34 [ 1 ] & 0x8 ) ;
V_152 = ( V_34 [ 2 ] & 0xc0 ) >> 6 ;
V_169 = V_34 [ 2 ] & 0x3f ;
V_170 = V_34 [ 3 ] ;
V_173 = ( V_177 == V_34 [ 0 ] ) ;
V_168 = V_173 ? 0 : ! ! ( V_34 [ 1 ] & 0x10 ) ;
if ( ( 0 == V_117 ) && ( 0 == V_167 ) )
V_171 = V_168 ? 16 : 8 ;
else
V_171 = 0 ;
V_108 = V_173 ? V_34 [ 4 ] : ( ( V_34 [ 7 ] << 8 ) | V_34 [ 8 ] ) ;
memset ( V_65 , 0 , V_176 ) ;
if ( 0x3 == V_152 ) {
F_9 ( V_23 , V_118 , V_178 ,
0 ) ;
return V_60 ;
}
V_80 = ( ( V_23 -> V_12 -> V_16 -> V_123 + 1 ) * 2000 ) +
( V_23 -> V_105 * 1000 ) - 3 ;
if ( 0 == V_117 )
V_172 = ( F_53 ( V_105 ) ? 0x80 : 0x0 ) | 0x10 ;
else
V_172 = 0x0 ;
if ( V_173 ) {
V_65 [ 2 ] = V_172 ;
V_65 [ 3 ] = V_171 ;
V_174 = 4 ;
} else {
V_65 [ 3 ] = V_172 ;
if ( 16 == V_171 )
V_65 [ 4 ] = 0x1 ;
V_65 [ 7 ] = V_171 ;
V_174 = 8 ;
}
V_175 = V_65 + V_174 ;
if ( ( V_171 > 0 ) && ( ! V_142 ) )
V_142 = F_39 () ;
if ( 8 == V_171 ) {
if ( V_142 > 0xfffffffe ) {
V_175 [ 0 ] = 0xff ;
V_175 [ 1 ] = 0xff ;
V_175 [ 2 ] = 0xff ;
V_175 [ 3 ] = 0xff ;
} else {
V_175 [ 0 ] = ( V_142 >> 24 ) & 0xff ;
V_175 [ 1 ] = ( V_142 >> 16 ) & 0xff ;
V_175 [ 2 ] = ( V_142 >> 8 ) & 0xff ;
V_175 [ 3 ] = V_142 & 0xff ;
}
V_175 [ 6 ] = ( V_7 >> 8 ) & 0xff ;
V_175 [ 7 ] = V_7 & 0xff ;
V_174 += V_171 ;
V_175 = V_65 + V_174 ;
} else if ( 16 == V_171 ) {
unsigned long long V_141 = V_142 ;
for ( V_144 = 0 ; V_144 < 8 ; ++ V_144 , V_141 >>= 8 )
V_175 [ 7 - V_144 ] = V_141 & 0xff ;
V_175 [ 12 ] = ( V_7 >> 24 ) & 0xff ;
V_175 [ 13 ] = ( V_7 >> 16 ) & 0xff ;
V_175 [ 14 ] = ( V_7 >> 8 ) & 0xff ;
V_175 [ 15 ] = V_7 & 0xff ;
V_174 += V_171 ;
V_175 = V_65 + V_174 ;
}
if ( ( V_170 > 0x0 ) && ( V_170 < 0xff ) && ( 0x19 != V_169 ) ) {
F_9 ( V_23 , V_118 , V_119 ,
0 ) ;
return V_60 ;
}
switch ( V_169 ) {
case 0x1 :
V_121 = F_43 ( V_175 , V_152 , V_105 ) ;
V_174 += V_121 ;
break;
case 0x2 :
V_121 = F_44 ( V_175 , V_152 , V_105 ) ;
V_174 += V_121 ;
break;
case 0x3 :
V_121 = F_45 ( V_175 , V_152 , V_105 ) ;
V_174 += V_121 ;
break;
case 0x8 :
V_121 = F_46 ( V_175 , V_152 , V_105 ) ;
V_174 += V_121 ;
break;
case 0xa :
V_121 = F_47 ( V_175 , V_152 , V_105 ) ;
V_174 += V_121 ;
break;
case 0x19 :
if ( ( V_170 > 0x2 ) && ( V_170 < 0xff ) ) {
F_9 ( V_23 , V_118 ,
V_119 , 0 ) ;
return V_60 ;
}
V_121 = 0 ;
if ( ( 0x0 == V_170 ) || ( 0xff == V_170 ) )
V_121 += F_49 ( V_175 + V_121 , V_152 , V_105 ) ;
if ( ( 0x1 == V_170 ) || ( 0xff == V_170 ) )
V_121 += F_50 ( V_175 + V_121 , V_152 , V_105 ,
V_80 ) ;
if ( ( 0x2 == V_170 ) || ( 0xff == V_170 ) )
V_121 += F_51 ( V_175 + V_121 , V_152 ) ;
V_174 += V_121 ;
break;
case 0x1c :
V_121 = F_48 ( V_175 , V_152 , V_105 ) ;
V_174 += V_121 ;
break;
case 0x3f :
if ( ( 0 == V_170 ) || ( 0xff == V_170 ) ) {
V_121 = F_43 ( V_175 , V_152 , V_105 ) ;
V_121 += F_44 ( V_175 + V_121 , V_152 , V_105 ) ;
V_121 += F_45 ( V_175 + V_121 , V_152 , V_105 ) ;
V_121 += F_46 ( V_175 + V_121 , V_152 , V_105 ) ;
V_121 += F_47 ( V_175 + V_121 , V_152 , V_105 ) ;
V_121 += F_49 ( V_175 + V_121 , V_152 , V_105 ) ;
if ( 0xff == V_170 ) {
V_121 += F_50 ( V_175 + V_121 , V_152 ,
V_105 , V_80 ) ;
V_121 += F_51 ( V_175 + V_121 , V_152 ) ;
}
V_121 += F_48 ( V_175 + V_121 , V_152 , V_105 ) ;
} else {
F_9 ( V_23 , V_118 ,
V_119 , 0 ) ;
return V_60 ;
}
V_174 += V_121 ;
break;
default:
F_9 ( V_23 , V_118 , V_119 ,
0 ) ;
return V_60 ;
}
if ( V_173 )
V_65 [ 0 ] = V_174 - 1 ;
else {
V_65 [ 0 ] = ( ( V_174 - 2 ) >> 8 ) & 0xff ;
V_65 [ 1 ] = ( V_174 - 2 ) & 0xff ;
}
return F_15 ( V_64 , V_65 , F_36 ( V_108 , V_174 ) ) ;
}
static int F_54 ( struct V_54 * V_64 , int V_179 ,
struct V_22 * V_23 )
{
int V_180 , V_181 , V_182 , V_183 , V_171 , V_184 , V_185 , V_186 ;
int V_187 , V_188 , V_137 , V_189 ;
unsigned char V_65 [ V_190 ] ;
unsigned char * V_34 = ( unsigned char * ) V_64 -> V_107 ;
if ( ( V_137 = F_14 ( V_64 , 1 , V_23 ) ) )
return V_137 ;
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
V_180 = V_34 [ 1 ] & 0x10 ;
V_181 = V_34 [ 1 ] & 0x1 ;
V_187 = V_179 ? V_34 [ 4 ] : ( ( V_34 [ 7 ] << 8 ) + V_34 [ 8 ] ) ;
if ( ( 0 == V_180 ) || V_181 || ( V_187 > V_190 ) ) {
F_9 ( V_23 , V_118 ,
V_119 , 0 ) ;
return V_60 ;
}
V_188 = F_20 ( V_64 , V_65 , V_187 ) ;
if ( - 1 == V_188 )
return ( V_73 << 16 ) ;
else if ( ( V_188 < V_187 ) &&
( V_31 & V_32 ) )
F_11 ( V_33 L_13
L_14 , V_187 , V_188 ) ;
V_183 = V_179 ? ( V_65 [ 0 ] + 1 ) : ( ( V_65 [ 0 ] << 8 ) + V_65 [ 1 ] + 2 ) ;
V_171 = V_179 ? V_65 [ 3 ] : ( ( V_65 [ 6 ] << 8 ) + V_65 [ 7 ] ) ;
if ( V_183 > 2 ) {
F_9 ( V_23 , V_118 ,
V_191 , 0 ) ;
return V_60 ;
}
V_184 = V_171 + ( V_179 ? 4 : 8 ) ;
V_189 = V_65 [ V_184 ] & 0x3f ;
V_182 = ! ! ( V_65 [ V_184 ] & 0x80 ) ;
if ( V_182 ) {
F_9 ( V_23 , V_118 ,
V_191 , 0 ) ;
return V_60 ;
}
V_185 = ! ! ( V_65 [ V_184 ] & 0x40 ) ;
V_186 = V_185 ? ( ( V_65 [ V_184 + 2 ] << 8 ) + V_65 [ V_184 + 3 ] + 4 ) :
( V_65 [ V_184 + 1 ] + 2 ) ;
if ( ( V_186 + V_184 ) > V_187 ) {
F_9 ( V_23 , V_118 ,
V_192 , 0 ) ;
return V_60 ;
}
switch ( V_189 ) {
case 0xa :
if ( V_160 [ 1 ] == V_65 [ V_184 + 1 ] ) {
memcpy ( V_160 + 2 , V_65 + V_184 + 2 ,
sizeof( V_160 ) - 2 ) ;
V_30 = ! ! ( V_160 [ 2 ] & 0x4 ) ;
return 0 ;
}
break;
case 0x1c :
if ( V_134 [ 1 ] == V_65 [ V_184 + 1 ] ) {
memcpy ( V_134 + 2 , V_65 + V_184 + 2 ,
sizeof( V_134 ) - 2 ) ;
return 0 ;
}
break;
default:
break;
}
F_9 ( V_23 , V_118 ,
V_191 , 0 ) ;
return V_60 ;
}
static int F_55 ( unsigned char * V_65 )
{
unsigned char V_193 [] = { 0x0 , 0x0 , 0x3 , 0x2 , 0x0 , 38 ,
0x0 , 0x1 , 0x3 , 0x2 , 0x0 , 65 ,
} ;
memcpy ( V_65 , V_193 , sizeof( V_193 ) ) ;
return sizeof( V_193 ) ;
}
static int F_56 ( unsigned char * V_65 )
{
unsigned char V_194 [] = { 0x0 , 0x0 , 0x3 , 0x3 , 0x0 , 0x0 , 38 ,
} ;
memcpy ( V_65 , V_194 , sizeof( V_194 ) ) ;
if ( V_134 [ 2 ] & 0x4 ) {
V_65 [ 4 ] = V_135 ;
V_65 [ 5 ] = 0xff ;
}
return sizeof( V_194 ) ;
}
static int F_57 ( struct V_54 * V_64 ,
struct V_22 * V_23 )
{
int V_195 , V_181 , V_152 , V_169 , V_170 , V_108 , V_137 , V_121 , V_109 ;
unsigned char V_65 [ V_196 ] ;
unsigned char * V_34 = ( unsigned char * ) V_64 -> V_107 ;
if ( ( V_137 = F_14 ( V_64 , 1 , V_23 ) ) )
return V_137 ;
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
V_195 = V_34 [ 1 ] & 0x2 ;
V_181 = V_34 [ 1 ] & 0x1 ;
if ( V_195 || V_181 ) {
F_9 ( V_23 , V_118 ,
V_119 , 0 ) ;
return V_60 ;
}
V_152 = ( V_34 [ 2 ] & 0xc0 ) >> 6 ;
V_169 = V_34 [ 2 ] & 0x3f ;
V_170 = V_34 [ 3 ] & 0xff ;
V_108 = ( V_34 [ 7 ] << 8 ) + V_34 [ 8 ] ;
V_65 [ 0 ] = V_169 ;
if ( 0 == V_170 ) {
switch ( V_169 ) {
case 0x0 :
V_109 = 4 ;
V_65 [ V_109 ++ ] = 0x0 ;
V_65 [ V_109 ++ ] = 0xd ;
V_65 [ V_109 ++ ] = 0x2f ;
V_65 [ 3 ] = V_109 - 4 ;
break;
case 0xd :
V_65 [ 3 ] = F_55 ( V_65 + 4 ) ;
break;
case 0x2f :
V_65 [ 3 ] = F_56 ( V_65 + 4 ) ;
break;
default:
F_9 ( V_23 , V_118 ,
V_119 , 0 ) ;
return V_60 ;
}
} else if ( 0xff == V_170 ) {
V_65 [ 0 ] |= 0x40 ;
V_65 [ 1 ] = V_170 ;
switch ( V_169 ) {
case 0x0 :
V_109 = 4 ;
V_65 [ V_109 ++ ] = 0x0 ;
V_65 [ V_109 ++ ] = 0x0 ;
V_65 [ V_109 ++ ] = 0x0 ;
V_65 [ V_109 ++ ] = 0xff ;
V_65 [ V_109 ++ ] = 0xd ;
V_65 [ V_109 ++ ] = 0x0 ;
V_65 [ V_109 ++ ] = 0x2f ;
V_65 [ V_109 ++ ] = 0x0 ;
V_65 [ 3 ] = V_109 - 4 ;
break;
case 0xd :
V_109 = 4 ;
V_65 [ V_109 ++ ] = 0xd ;
V_65 [ V_109 ++ ] = 0x0 ;
V_65 [ 3 ] = V_109 - 4 ;
break;
case 0x2f :
V_109 = 4 ;
V_65 [ V_109 ++ ] = 0x2f ;
V_65 [ V_109 ++ ] = 0x0 ;
V_65 [ 3 ] = V_109 - 4 ;
break;
default:
F_9 ( V_23 , V_118 ,
V_119 , 0 ) ;
return V_60 ;
}
} else {
F_9 ( V_23 , V_118 ,
V_119 , 0 ) ;
return V_60 ;
}
V_121 = F_36 ( ( ( V_65 [ 2 ] << 8 ) + V_65 [ 3 ] ) + 4 , V_108 ) ;
return F_15 ( V_64 , V_65 ,
F_36 ( V_121 , V_111 ) ) ;
}
static int F_58 ( struct V_22 * V_197 ,
unsigned long long V_4 , unsigned int V_35 )
{
if ( V_4 + V_35 > V_142 ) {
F_9 ( V_197 , V_118 , V_198 , 0 ) ;
return V_60 ;
}
if ( V_35 > V_5 ) {
F_9 ( V_197 , V_118 , V_119 , 0 ) ;
return V_60 ;
}
return 0 ;
}
static int F_59 ( struct V_54 * V_199 ,
struct V_22 * V_197 ,
unsigned long long V_4 , unsigned int V_35 , int V_200 )
{
int V_110 ;
unsigned long long V_201 , V_202 = 0 ;
struct V_68 * V_69 ;
enum V_203 V_204 ;
T_4 (* F_60)( struct V_205 * , unsigned int , void * , T_4 ,
T_5 );
if ( V_200 ) {
V_69 = F_61 ( V_199 ) ;
V_204 = V_78 ;
F_60 = V_206 ;
} else {
V_69 = F_16 ( V_199 ) ;
V_204 = V_72 ;
F_60 = V_207 ;
}
if ( ! V_69 -> V_70 )
return 0 ;
if ( ! ( F_17 ( V_199 ) || V_199 -> V_71 == V_204 ) )
return - 1 ;
V_201 = F_3 ( V_4 , V_5 ) ;
if ( V_201 + V_35 > V_5 )
V_202 = V_201 + V_35 - V_5 ;
V_110 = F_60 ( V_69 -> V_74 . V_75 , V_69 -> V_74 . V_76 ,
V_6 + ( V_201 * V_7 ) ,
( V_35 - V_202 ) * V_7 , 0 ) ;
if ( V_110 != ( V_35 - V_202 ) * V_7 )
return V_110 ;
if ( V_202 ) {
V_110 += F_60 ( V_69 -> V_74 . V_75 , V_69 -> V_74 . V_76 ,
V_6 , V_202 * V_7 ,
( V_35 - V_202 ) * V_7 ) ;
}
return V_110 ;
}
static T_6 F_62 ( const void * V_208 , int V_121 )
{
T_6 V_209 ;
if ( V_210 )
V_209 = ( V_211 T_6 ) F_63 ( V_208 , V_121 ) ;
else
V_209 = F_64 ( F_65 ( V_208 , V_121 ) ) ;
return V_209 ;
}
static int F_66 ( struct V_8 * V_212 , const void * V_213 ,
T_1 V_9 , T_2 V_36 )
{
T_6 V_209 = F_62 ( V_213 , V_7 ) ;
if ( V_212 -> V_214 != V_209 ) {
F_67 ( L_15 ,
V_215 ,
( unsigned long ) V_9 ,
F_68 ( V_212 -> V_214 ) ,
F_68 ( V_209 ) ) ;
return 0x01 ;
}
if ( V_126 == V_216 &&
F_69 ( V_212 -> V_217 ) != ( V_9 & 0xffffffff ) ) {
F_67 ( L_16 ,
V_215 , ( unsigned long ) V_9 ) ;
return 0x03 ;
}
if ( V_126 == V_218 &&
F_69 ( V_212 -> V_217 ) != V_36 ) {
F_67 ( L_16 ,
V_215 , ( unsigned long ) V_9 ) ;
V_219 ++ ;
return 0x03 ;
}
return 0 ;
}
static void F_70 ( struct V_54 * V_55 , T_1 V_9 ,
unsigned int V_220 , bool V_221 )
{
unsigned int V_222 , V_77 ;
struct V_205 * V_223 ;
void * V_224 ;
const void * V_225 = V_10 + V_5 ;
V_77 = V_220 * sizeof( * V_10 ) ;
F_71 (SCpnt, psgl, scsi_prot_sg_count(SCpnt), i) {
int V_121 = F_36 ( V_223 -> V_70 , V_77 ) ;
void * V_138 = F_4 ( V_9 ) ;
int V_202 = 0 ;
if ( V_225 < V_138 + V_121 )
V_202 = V_138 + V_121 - V_225 ;
V_224 = F_72 ( F_73 ( V_223 ) ) + V_223 -> V_174 ;
if ( V_221 )
memcpy ( V_224 , V_138 , V_121 - V_202 ) ;
else
memcpy ( V_138 , V_224 , V_121 - V_202 ) ;
if ( V_202 ) {
if ( V_221 )
memcpy ( V_224 + V_121 - V_202 , V_10 , V_202 ) ;
else
memcpy ( V_10 , V_224 + V_121 - V_202 , V_202 ) ;
}
V_9 += V_121 / sizeof( * V_10 ) ;
V_77 -= V_121 ;
F_74 ( V_224 ) ;
}
}
static int F_75 ( struct V_54 * V_55 , T_1 V_226 ,
unsigned int V_220 , T_2 V_36 )
{
unsigned int V_222 ;
struct V_8 * V_212 ;
T_1 V_9 ;
for ( V_222 = 0 ; V_222 < V_220 ; V_222 ++ ) {
int V_110 ;
V_9 = V_226 + V_222 ;
V_212 = F_4 ( V_9 ) ;
if ( V_212 -> V_227 == F_64 ( 0xffff ) )
continue;
V_110 = F_66 ( V_212 , F_2 ( V_9 ) , V_9 , V_36 ) ;
if ( V_110 ) {
V_219 ++ ;
return V_110 ;
}
V_36 ++ ;
}
F_70 ( V_55 , V_226 , V_220 , true ) ;
V_228 ++ ;
return 0 ;
}
static int F_76 ( struct V_54 * V_55 , unsigned long long V_4 ,
unsigned int V_35 , struct V_22 * V_23 ,
T_2 V_36 )
{
unsigned long V_229 ;
int V_110 ;
V_110 = F_58 ( V_23 , V_4 , V_35 ) ;
if ( V_110 )
return V_110 ;
if ( ( V_230 & V_32 ) &&
( V_4 <= ( V_231 + V_232 - 1 ) ) &&
( ( V_4 + V_35 ) > V_231 ) ) {
F_9 ( V_23 , V_233 , V_234 , 0 ) ;
if ( 0x70 == ( V_23 -> V_28 [ 0 ] & 0x7f ) ) {
V_23 -> V_28 [ 0 ] |= 0x80 ;
V_110 = ( V_4 < V_231 )
? V_231 : ( int ) V_4 ;
V_23 -> V_28 [ 3 ] = ( V_110 >> 24 ) & 0xff ;
V_23 -> V_28 [ 4 ] = ( V_110 >> 16 ) & 0xff ;
V_23 -> V_28 [ 5 ] = ( V_110 >> 8 ) & 0xff ;
V_23 -> V_28 [ 6 ] = V_110 & 0xff ;
}
F_77 ( V_55 , F_19 ( V_55 ) ) ;
return V_60 ;
}
if ( V_235 && F_78 ( V_55 ) ) {
int V_236 = F_75 ( V_55 , V_4 , V_35 , V_36 ) ;
if ( V_236 ) {
F_9 ( V_23 , V_237 , 0x10 , V_236 ) ;
return V_238 ;
}
}
F_79 ( & V_239 , V_229 ) ;
V_110 = F_59 ( V_55 , V_23 , V_4 , V_35 , 0 ) ;
F_80 ( & V_239 , V_229 ) ;
if ( V_110 == - 1 )
return V_73 << 16 ;
F_16 ( V_55 ) -> V_77 = F_19 ( V_55 ) - V_110 ;
return 0 ;
}
void F_81 ( unsigned char * V_208 , int V_121 )
{
int V_222 , V_240 ;
F_11 ( V_241 L_17 ) ;
for ( V_222 = 0 ; V_222 < V_121 ; V_222 += 16 ) {
F_11 ( V_241 L_18 , V_222 ) ;
for ( V_240 = 0 ; V_240 < 16 ; V_240 ++ ) {
unsigned char V_242 = V_208 [ V_222 + V_240 ] ;
if ( V_242 >= 0x20 && V_242 < 0x7e )
F_11 ( L_19 , V_208 [ V_222 + V_240 ] ) ;
else
F_11 ( L_20 , V_208 [ V_222 + V_240 ] ) ;
}
F_11 ( L_21 ) ;
}
}
static int F_82 ( struct V_54 * V_55 , T_1 V_226 ,
unsigned int V_220 , T_2 V_36 )
{
int V_222 , V_240 , V_110 ;
struct V_8 * V_212 ;
struct V_205 * V_243 ;
struct V_205 * V_223 = F_83 ( V_55 ) ;
void * V_244 , * V_224 ;
T_1 V_9 = V_226 ;
int V_245 ;
F_84 ( F_85 ( V_55 ) == 0 ) ;
F_84 ( F_78 ( V_55 ) == 0 ) ;
V_245 = 0 ;
F_86 (SCpnt, dsgl, scsi_sg_count(SCpnt), i) {
V_244 = F_72 ( F_73 ( V_243 ) ) + V_243 -> V_174 ;
V_224 = F_72 ( F_73 ( V_223 ) ) + V_223 -> V_174 ;
for ( V_240 = 0 ; V_240 < V_243 -> V_70 ; V_240 += V_7 ) {
if ( V_245 >= V_223 -> V_70 ) {
F_74 ( V_224 ) ;
V_223 = F_87 ( V_223 ) ;
F_84 ( V_223 == NULL ) ;
V_224 = F_72 ( F_73 ( V_223 ) )
+ V_223 -> V_174 ;
V_245 = 0 ;
}
V_212 = V_224 + V_245 ;
V_110 = F_66 ( V_212 , V_244 + V_240 , V_9 , V_36 ) ;
if ( V_110 ) {
F_81 ( V_244 + V_240 , V_7 ) ;
goto V_246;
}
V_9 ++ ;
V_36 ++ ;
V_245 += sizeof( struct V_8 ) ;
}
F_74 ( V_224 ) ;
F_74 ( V_244 ) ;
}
F_70 ( V_55 , V_226 , V_220 , false ) ;
V_247 ++ ;
return 0 ;
V_246:
V_219 ++ ;
F_74 ( V_224 ) ;
F_74 ( V_244 ) ;
return V_110 ;
}
static unsigned long F_88 ( T_1 V_4 )
{
if ( V_101 ) {
V_4 += V_102 -
V_101 ;
}
F_3 ( V_4 , V_102 ) ;
return V_4 ;
}
static T_1 F_89 ( unsigned long V_248 )
{
T_1 V_4 = V_248 * V_102 ;
if ( V_101 ) {
V_4 -= V_102 -
V_101 ;
}
return V_4 ;
}
static unsigned int F_90 ( T_1 V_4 , unsigned int * V_35 )
{
T_1 V_249 ;
unsigned int V_250 ;
unsigned long V_248 ;
unsigned long V_251 ;
V_248 = F_88 ( V_4 ) ;
V_250 = F_91 ( V_248 , V_252 ) ;
if ( V_250 )
V_251 = F_92 ( V_252 , V_253 , V_248 ) ;
else
V_251 = F_93 ( V_252 , V_253 , V_248 ) ;
V_249 = F_94 ( T_1 , V_5 , F_89 ( V_251 ) ) ;
* V_35 = V_249 - V_4 ;
return V_250 ;
}
static void F_95 ( T_1 V_4 , unsigned int V_121 )
{
T_1 V_249 = V_4 + V_121 ;
while ( V_4 < V_249 ) {
unsigned long V_248 = F_88 ( V_4 ) ;
if ( V_248 < V_253 )
F_96 ( V_248 , V_252 ) ;
V_4 = F_89 ( V_248 + 1 ) ;
}
}
static void F_97 ( T_1 V_4 , unsigned int V_121 )
{
T_1 V_249 = V_4 + V_121 ;
while ( V_4 < V_249 ) {
unsigned long V_248 = F_88 ( V_4 ) ;
if ( V_4 == F_89 ( V_248 ) &&
V_4 + V_102 <= V_249 &&
V_248 < V_253 ) {
F_98 ( V_248 , V_252 ) ;
if ( V_104 ) {
memset ( V_6 +
V_4 * V_7 , 0 ,
V_7 *
V_102 ) ;
}
if ( V_10 ) {
memset ( V_10 + V_4 , 0xff ,
sizeof( * V_10 ) *
V_102 ) ;
}
}
V_4 = F_89 ( V_248 + 1 ) ;
}
}
static int F_99 ( struct V_54 * V_55 , unsigned long long V_4 ,
unsigned int V_35 , struct V_22 * V_23 ,
T_2 V_36 )
{
unsigned long V_229 ;
int V_110 ;
V_110 = F_58 ( V_23 , V_4 , V_35 ) ;
if ( V_110 )
return V_110 ;
if ( V_235 && F_78 ( V_55 ) ) {
int V_236 = F_82 ( V_55 , V_4 , V_35 , V_36 ) ;
if ( V_236 ) {
F_9 ( V_23 , V_118 , 0x10 , V_236 ) ;
return V_238 ;
}
}
F_100 ( & V_239 , V_229 ) ;
V_110 = F_59 ( V_55 , V_23 , V_4 , V_35 , 1 ) ;
if ( F_1 () )
F_95 ( V_4 , V_35 ) ;
F_101 ( & V_239 , V_229 ) ;
if ( - 1 == V_110 )
return ( V_73 << 16 ) ;
else if ( ( V_110 < ( V_35 * V_7 ) ) &&
( V_31 & V_32 ) )
F_11 ( V_33 L_22
L_14 , V_35 * V_7 , V_110 ) ;
return 0 ;
}
static int F_102 ( struct V_54 * V_199 , unsigned long long V_4 ,
unsigned int V_35 , struct V_22 * V_23 ,
T_2 V_36 , unsigned int V_254 )
{
unsigned long V_229 ;
unsigned long long V_222 ;
int V_110 ;
V_110 = F_58 ( V_23 , V_4 , V_35 ) ;
if ( V_110 )
return V_110 ;
if ( V_35 > V_103 ) {
F_9 ( V_23 , V_118 , V_119 ,
0 ) ;
return V_60 ;
}
F_100 ( & V_239 , V_229 ) ;
if ( V_254 && F_1 () ) {
F_97 ( V_4 , V_35 ) ;
goto V_246;
}
V_110 = F_20 ( V_199 ,
V_6 + ( V_4 * V_7 ) ,
V_7 ) ;
if ( - 1 == V_110 ) {
F_101 ( & V_239 , V_229 ) ;
return ( V_73 << 16 ) ;
} else if ( ( V_110 < ( V_35 * V_7 ) ) &&
( V_31 & V_32 ) )
F_11 ( V_33 L_23
L_14 , V_35 * V_7 , V_110 ) ;
for ( V_222 = 1 ; V_222 < V_35 ; V_222 ++ )
memcpy ( V_6 + ( ( V_4 + V_222 ) * V_7 ) ,
V_6 + ( V_4 * V_7 ) ,
V_7 ) ;
if ( F_1 () )
F_95 ( V_4 , V_35 ) ;
V_246:
F_101 ( & V_239 , V_229 ) ;
return 0 ;
}
static int F_103 ( struct V_54 * V_199 , struct V_22 * V_23 )
{
unsigned char * V_208 ;
struct V_255 * V_256 ;
unsigned int V_222 , V_257 , V_258 ;
int V_110 ;
V_110 = F_14 ( V_199 , 1 , V_23 ) ;
if ( V_110 )
return V_110 ;
V_257 = F_104 ( & V_199 -> V_107 [ 7 ] ) ;
F_84 ( F_19 ( V_199 ) != V_257 ) ;
V_258 = ( V_257 - 8 ) / 16 ;
V_208 = F_105 ( F_19 ( V_199 ) , V_112 ) ;
if ( ! V_208 )
return V_60 ;
F_21 ( V_199 , V_208 , F_19 ( V_199 ) ) ;
F_84 ( F_104 ( & V_208 [ 0 ] ) != V_257 - 2 ) ;
F_84 ( F_104 ( & V_208 [ 2 ] ) != V_258 * 16 ) ;
V_256 = ( void * ) & V_208 [ 8 ] ;
for ( V_222 = 0 ; V_222 < V_258 ; V_222 ++ ) {
unsigned long long V_4 = F_106 ( & V_256 [ V_222 ] . V_4 ) ;
unsigned int V_35 = F_107 ( & V_256 [ V_222 ] . V_259 ) ;
V_110 = F_58 ( V_23 , V_4 , V_35 ) ;
if ( V_110 )
goto V_246;
F_97 ( V_4 , V_35 ) ;
}
V_110 = 0 ;
V_246:
F_34 ( V_208 ) ;
return V_110 ;
}
static int F_108 ( struct V_54 * V_199 ,
struct V_22 * V_23 )
{
unsigned long long V_4 ;
unsigned int V_108 , V_250 , V_35 ;
unsigned char V_65 [ V_260 ] ;
int V_110 ;
V_110 = F_14 ( V_199 , 1 , V_23 ) ;
if ( V_110 )
return V_110 ;
V_4 = F_106 ( & V_199 -> V_107 [ 2 ] ) ;
V_108 = F_107 ( & V_199 -> V_107 [ 10 ] ) ;
if ( V_108 < 24 )
return 0 ;
V_110 = F_58 ( V_23 , V_4 , 1 ) ;
if ( V_110 )
return V_110 ;
V_250 = F_90 ( V_4 , & V_35 ) ;
memset ( V_65 , 0 , V_260 ) ;
F_28 ( 20 , & V_65 [ 0 ] ) ;
F_29 ( V_4 , & V_65 [ 8 ] ) ;
F_28 ( V_35 , & V_65 [ 16 ] ) ;
V_65 [ 20 ] = ! V_250 ;
return F_15 ( V_199 , V_65 , V_260 ) ;
}
static int F_109 ( struct V_54 * V_64 ,
struct V_22 * V_23 )
{
unsigned int V_108 ;
int V_261 , V_222 , V_262 , V_35 , V_109 , V_114 , V_116 ;
unsigned char * V_34 = ( unsigned char * ) V_64 -> V_107 ;
int V_263 = ( int ) V_34 [ 2 ] ;
struct V_264 * V_265 ;
unsigned char V_65 [ V_266 ] ;
unsigned char * V_267 ;
V_108 = V_34 [ 9 ] + ( V_34 [ 8 ] << 8 ) + ( V_34 [ 7 ] << 16 ) + ( V_34 [ 6 ] << 24 ) ;
if ( ( V_108 < 4 ) || ( V_263 > 2 ) ) {
F_9 ( V_23 , V_118 , V_119 ,
0 ) ;
return V_60 ;
}
memset ( V_65 , 0 , V_266 ) ;
V_261 = V_268 ;
if ( 1 == V_263 )
V_261 = 0 ;
else if ( V_115 && ( V_261 > 0 ) )
-- V_261 ;
V_114 = ( V_263 > 0 ) ? 1 : 0 ;
V_35 = V_261 + V_114 ;
V_65 [ 2 ] = ( ( sizeof( struct V_264 ) * V_35 ) >> 8 ) & 0xff ;
V_65 [ 3 ] = ( sizeof( struct V_264 ) * V_35 ) & 0xff ;
V_109 = F_36 ( ( int ) ( ( V_266 - 8 ) /
sizeof( struct V_264 ) ) , V_35 ) ;
if ( V_109 < V_35 ) {
V_114 = 0 ;
V_261 = V_109 ;
}
V_265 = (struct V_264 * ) & V_65 [ 8 ] ;
V_267 = V_65 + V_266 ;
for ( V_222 = 0 , V_116 = ( V_115 ? 1 : 0 ) ;
( ( V_222 < V_261 ) && ( ( unsigned char * ) ( V_265 + V_222 ) < V_267 ) ) ;
V_222 ++ , V_116 ++ ) {
V_262 = ( V_116 >> 8 ) & 0x3f ;
if ( V_262 )
V_265 [ V_222 ] . V_264 [ 0 ] =
( V_262 | ( V_269 << 6 ) ) ;
V_265 [ V_222 ] . V_264 [ 1 ] = V_116 & 0xff ;
}
if ( V_114 ) {
V_265 [ V_222 ] . V_264 [ 0 ] = ( V_21 >> 8 ) & 0xff ;
V_265 [ V_222 ] . V_264 [ 1 ] = V_21 & 0xff ;
V_222 ++ ;
}
V_108 = ( unsigned char * ) ( V_265 + V_222 ) - V_65 ;
return F_15 ( V_64 , V_65 ,
F_36 ( ( int ) V_108 , V_266 ) ) ;
}
static int F_110 ( struct V_54 * V_64 , unsigned long long V_4 ,
unsigned int V_35 , struct V_22 * V_23 )
{
int V_222 , V_240 , V_110 = - 1 ;
unsigned char * V_270 , * V_208 ;
unsigned int V_174 ;
struct V_205 * V_271 ;
struct V_68 * V_69 = F_16 ( V_64 ) ;
V_208 = F_105 ( F_19 ( V_64 ) , V_112 ) ;
if ( ! V_208 )
return V_110 ;
F_21 ( V_64 , V_208 , F_19 ( V_64 ) ) ;
V_174 = 0 ;
F_111 (sdb->table.sgl, sg, sdb->table.nents, i) {
V_270 = ( unsigned char * ) F_72 ( F_73 ( V_271 ) ) ;
if ( ! V_270 )
goto V_246;
for ( V_240 = 0 ; V_240 < V_271 -> V_70 ; V_240 ++ )
* ( V_270 + V_271 -> V_174 + V_240 ) ^= * ( V_208 + V_174 + V_240 ) ;
V_174 += V_271 -> V_70 ;
F_74 ( V_270 ) ;
}
V_110 = 0 ;
V_246:
F_34 ( V_208 ) ;
return V_110 ;
}
static void F_112 ( unsigned long V_272 )
{
struct V_273 * V_274 ;
unsigned long V_229 ;
if ( V_272 >= V_275 ) {
F_11 ( V_241 L_24
L_25 ) ;
return;
}
F_113 ( & V_276 , V_229 ) ;
V_274 = & V_277 [ ( int ) V_272 ] ;
if ( ! V_274 -> V_278 ) {
F_11 ( V_241 L_26
L_27 ) ;
F_114 ( & V_276 , V_229 ) ;
return;
}
V_274 -> V_278 = 0 ;
if ( V_274 -> V_279 ) {
V_274 -> V_280 -> V_281 = V_274 -> V_282 ;
V_274 -> V_279 ( V_274 -> V_280 ) ;
}
V_274 -> V_279 = NULL ;
F_114 ( & V_276 , V_229 ) ;
}
static struct V_22 *
F_115 ( struct V_11 * V_12 , T_7 V_283 )
{
struct V_22 * V_23 ;
V_23 = F_33 ( sizeof( * V_23 ) , V_283 ) ;
if ( V_23 ) {
V_23 -> V_12 = V_12 ;
F_116 ( & V_23 -> V_284 , & V_12 -> V_285 ) ;
}
return V_23 ;
}
static struct V_22 * F_117 ( struct V_50 * V_286 )
{
struct V_11 * V_12 ;
struct V_22 * V_287 = NULL ;
struct V_22 * V_23 =
(struct V_22 * ) V_286 -> V_288 ;
if ( V_23 )
return V_23 ;
V_12 = * (struct V_11 * * ) F_118 ( V_286 -> V_289 ) ;
if ( ! V_12 ) {
F_11 ( V_241 L_28 ) ;
return NULL ;
}
F_7 (devip, &sdbg_host->dev_info_list, dev_list) {
if ( ( V_23 -> V_290 ) && ( V_23 -> V_124 == V_286 -> V_124 ) &&
( V_23 -> V_105 == V_286 -> V_291 ) &&
( V_23 -> V_116 == V_286 -> V_116 ) )
return V_23 ;
else {
if ( ( ! V_23 -> V_290 ) && ( ! V_287 ) )
V_287 = V_23 ;
}
}
if ( ! V_287 ) {
V_287 = F_115 ( V_12 , V_112 ) ;
if ( ! V_287 ) {
F_11 ( V_241 L_29 ,
V_215 , __LINE__ ) ;
return NULL ;
}
}
V_287 -> V_124 = V_286 -> V_124 ;
V_287 -> V_105 = V_286 -> V_291 ;
V_287 -> V_116 = V_286 -> V_116 ;
V_287 -> V_12 = V_12 ;
V_287 -> V_57 = 1 ;
V_287 -> V_290 = 1 ;
memset ( V_287 -> V_28 , 0 , V_29 ) ;
if ( V_30 )
V_287 -> V_28 [ 0 ] = 0x72 ;
else {
V_287 -> V_28 [ 0 ] = 0x70 ;
V_287 -> V_28 [ 7 ] = 0xa ;
}
if ( V_286 -> V_116 == V_21 )
V_287 -> V_114 = V_21 & 0xff ;
return V_287 ;
}
static int F_119 ( struct V_50 * V_292 )
{
if ( V_31 & V_32 )
F_11 ( V_33 L_30 ,
V_292 -> V_289 -> V_123 , V_292 -> V_124 , V_292 -> V_291 , V_292 -> V_116 ) ;
F_120 ( V_293 , V_292 -> V_294 ) ;
return 0 ;
}
static int F_121 ( struct V_50 * V_292 )
{
struct V_22 * V_23 ;
if ( V_31 & V_32 )
F_11 ( V_33 L_31 ,
V_292 -> V_289 -> V_123 , V_292 -> V_124 , V_292 -> V_291 , V_292 -> V_116 ) ;
if ( V_292 -> V_289 -> V_295 != V_296 )
V_292 -> V_289 -> V_295 = V_296 ;
V_23 = F_117 ( V_292 ) ;
if ( NULL == V_23 )
return 1 ;
V_292 -> V_288 = V_23 ;
if ( V_292 -> V_289 -> V_297 )
F_122 ( V_292 , V_298 ,
V_292 -> V_289 -> V_297 ) ;
F_123 ( V_292 -> V_294 , 256 * 1024 ) ;
if ( V_299 )
V_292 -> V_300 = 1 ;
return 0 ;
}
static void F_124 ( struct V_50 * V_292 )
{
struct V_22 * V_23 =
(struct V_22 * ) V_292 -> V_288 ;
if ( V_31 & V_32 )
F_11 ( V_33 L_32 ,
V_292 -> V_289 -> V_123 , V_292 -> V_124 , V_292 -> V_291 , V_292 -> V_116 ) ;
if ( V_23 ) {
V_23 -> V_290 = 0 ;
V_292 -> V_288 = NULL ;
}
}
static int F_125 ( struct V_54 * V_107 )
{
unsigned long V_229 ;
int V_144 ;
struct V_273 * V_274 ;
F_113 ( & V_276 , V_229 ) ;
for ( V_144 = 0 ; V_144 < V_275 ; ++ V_144 ) {
V_274 = & V_277 [ V_144 ] ;
if ( V_274 -> V_278 && ( V_107 == V_274 -> V_280 ) ) {
F_126 ( & V_274 -> V_301 ) ;
V_274 -> V_278 = 0 ;
V_274 -> V_280 = NULL ;
break;
}
}
F_114 ( & V_276 , V_229 ) ;
return ( V_144 < V_275 ) ? 1 : 0 ;
}
static void F_127 ( void )
{
unsigned long V_229 ;
int V_144 ;
struct V_273 * V_274 ;
F_113 ( & V_276 , V_229 ) ;
for ( V_144 = 0 ; V_144 < V_275 ; ++ V_144 ) {
V_274 = & V_277 [ V_144 ] ;
if ( V_274 -> V_278 && V_274 -> V_280 ) {
F_126 ( & V_274 -> V_301 ) ;
V_274 -> V_278 = 0 ;
V_274 -> V_280 = NULL ;
}
}
F_114 ( & V_276 , V_229 ) ;
}
static int F_128 ( struct V_54 * V_55 )
{
if ( V_31 & V_32 )
F_11 ( V_33 L_33 ) ;
++ V_302 ;
F_125 ( V_55 ) ;
return V_303 ;
}
static int F_129 ( struct V_50 * V_286 ,
struct V_304 * V_305 , T_1 V_306 , int * V_307 )
{
int V_188 ;
unsigned char * V_208 ;
if ( V_31 & V_32 )
F_11 ( V_33 L_34 ) ;
V_208 = F_130 ( V_305 ) ;
if ( V_208 ) {
V_188 = F_131 ( V_208 , V_306 ,
& V_307 [ 2 ] , & V_307 [ 0 ] , & V_307 [ 1 ] ) ;
F_34 ( V_208 ) ;
if ( ! V_188 )
return V_188 ;
}
V_307 [ 0 ] = V_308 ;
V_307 [ 1 ] = V_156 ;
V_307 [ 2 ] = V_309 ;
return 0 ;
}
static int F_132 ( struct V_54 * V_55 )
{
struct V_22 * V_23 ;
if ( V_31 & V_32 )
F_11 ( V_33 L_35 ) ;
++ V_310 ;
if ( V_55 ) {
V_23 = F_117 ( V_55 -> V_311 ) ;
if ( V_23 )
V_23 -> V_57 = 1 ;
}
return V_303 ;
}
static int F_133 ( struct V_54 * V_55 )
{
struct V_11 * V_12 ;
struct V_22 * V_312 ;
struct V_50 * V_292 ;
struct V_13 * V_313 ;
if ( V_31 & V_32 )
F_11 ( V_33 L_36 ) ;
++ V_314 ;
if ( V_55 && ( ( V_292 = V_55 -> V_311 ) ) && ( ( V_313 = V_292 -> V_289 ) ) ) {
V_12 = * (struct V_11 * * ) F_118 ( V_313 ) ;
if ( V_12 ) {
F_7 (dev_info,
&sdbg_host->dev_info_list,
dev_list)
V_312 -> V_57 = 1 ;
}
}
return V_303 ;
}
static int F_134 ( struct V_54 * V_55 )
{
struct V_11 * V_12 ;
struct V_22 * V_312 ;
if ( V_31 & V_32 )
F_11 ( V_33 L_37 ) ;
++ V_315 ;
F_6 ( & V_15 ) ;
F_7 (sdbg_host, &sdebug_host_list, host_list) {
F_7 (dev_info, &sdbg_host->dev_info_list,
dev_list)
V_312 -> V_57 = 1 ;
}
F_8 ( & V_15 ) ;
F_127 () ;
return V_303 ;
}
static void T_8 F_135 ( void )
{
unsigned long V_229 ;
int V_144 ;
struct V_273 * V_274 ;
F_113 ( & V_276 , V_229 ) ;
for ( V_144 = 0 ; V_144 < V_275 ; ++ V_144 ) {
V_274 = & V_277 [ V_144 ] ;
F_136 ( & V_274 -> V_301 ) ;
V_274 -> V_278 = 0 ;
V_274 -> V_280 = NULL ;
}
F_114 ( & V_276 , V_229 ) ;
}
static void T_8 F_137 ( unsigned char * V_316 ,
unsigned long V_317 )
{
struct V_318 * V_319 ;
int V_320 [ V_321 + 2 ] ;
int V_322 , V_323 , V_144 ;
int V_324 , V_226 , V_325 ;
if ( ( V_326 < 1 ) || ( V_317 < 1048576 ) )
return;
if ( V_326 > V_321 ) {
V_326 = V_321 ;
F_11 ( V_327 L_38
L_39 , V_321 ) ;
}
V_323 = ( int ) V_5 ;
V_322 = ( V_323 - V_156 )
/ V_326 ;
V_324 = V_308 * V_156 ;
V_320 [ 0 ] = V_156 ;
for ( V_144 = 1 ; V_144 < V_326 ; ++ V_144 )
V_320 [ V_144 ] = ( ( V_144 * V_322 ) / V_324 )
* V_324 ;
V_320 [ V_326 ] = V_323 ;
V_320 [ V_326 + 1 ] = 0 ;
V_316 [ 510 ] = 0x55 ;
V_316 [ 511 ] = 0xAA ;
V_319 = (struct V_318 * ) ( V_316 + 0x1be ) ;
for ( V_144 = 0 ; V_320 [ V_144 + 1 ] ; ++ V_144 , ++ V_319 ) {
V_226 = V_320 [ V_144 ] ;
V_325 = V_320 [ V_144 + 1 ] - 1 ;
V_319 -> V_328 = 0 ;
V_319 -> V_329 = V_226 / V_324 ;
V_319 -> V_330 = ( V_226 - ( V_319 -> V_329 * V_324 ) )
/ V_156 ;
V_319 -> V_9 = ( V_226 % V_156 ) + 1 ;
V_319 -> V_331 = V_325 / V_324 ;
V_319 -> V_332 = ( V_325 - ( V_319 -> V_331 * V_324 ) )
/ V_156 ;
V_319 -> V_333 = ( V_325 % V_156 ) + 1 ;
V_319 -> V_334 = F_138 ( V_226 ) ;
V_319 -> V_335 = F_138 ( V_325 - V_226 + 1 ) ;
V_319 -> V_336 = 0x83 ;
}
}
static int F_139 ( struct V_54 * V_107 ,
struct V_22 * V_23 ,
T_9 V_337 , int V_282 , int V_338 )
{
if ( ( V_31 & V_32 ) && V_107 ) {
if ( V_282 ) {
struct V_50 * V_292 = V_107 -> V_311 ;
F_11 ( V_33 L_40
L_41 , V_292 -> V_289 -> V_123 ,
V_292 -> V_124 , V_292 -> V_291 , V_292 -> V_116 , V_282 ) ;
}
}
if ( V_107 && V_23 ) {
if ( V_339 == ( V_282 & 0xff ) )
memcpy ( V_107 -> V_340 , V_23 -> V_28 ,
( V_341 > V_29 ) ?
V_29 : V_341 ) ;
}
if ( V_338 <= 0 ) {
if ( V_107 )
V_107 -> V_281 = V_282 ;
if ( V_337 )
V_337 ( V_107 ) ;
return 0 ;
} else {
unsigned long V_229 ;
int V_144 ;
struct V_273 * V_274 = NULL ;
F_113 ( & V_276 , V_229 ) ;
for ( V_144 = 0 ; V_144 < V_275 ; ++ V_144 ) {
V_274 = & V_277 [ V_144 ] ;
if ( ! V_274 -> V_278 )
break;
}
if ( V_144 >= V_275 ) {
F_114 ( & V_276 , V_229 ) ;
F_11 ( V_327 L_42 ) ;
return 1 ;
}
V_274 -> V_278 = 1 ;
V_274 -> V_280 = V_107 ;
V_274 -> V_282 = V_282 ;
V_274 -> V_279 = V_337 ;
V_274 -> V_301 . V_342 = F_112 ;
V_274 -> V_301 . V_213 = V_144 ;
V_274 -> V_301 . V_343 = V_344 + V_338 ;
F_140 ( & V_274 -> V_301 ) ;
F_114 ( & V_276 , V_229 ) ;
if ( V_107 )
V_107 -> V_281 = 0 ;
return 0 ;
}
}
static const char * F_141 ( struct V_13 * V_345 )
{
sprintf ( V_346 , L_43
L_44 , V_347 ,
V_348 , V_349 ,
V_32 ) ;
return V_346 ;
}
static int F_142 ( struct V_13 * V_289 , char * V_350 , int V_70 )
{
char V_65 [ 16 ] ;
int V_351 ;
int V_352 = V_70 > 15 ? 15 : V_70 ;
if ( ! F_143 ( V_353 ) || ! F_143 ( V_354 ) )
return - V_355 ;
memcpy ( V_65 , V_350 , V_352 ) ;
V_65 [ V_352 ] = '\0' ;
if ( 1 != sscanf ( V_65 , L_12 , & V_351 ) )
return - V_53 ;
V_32 = V_351 ;
if ( V_356 != 0 )
V_357 = 0 ;
return V_70 ;
}
static int F_144 ( struct V_358 * V_359 , struct V_13 * V_289 )
{
F_145 ( V_359 , L_45
L_46
L_47
L_48
L_49
L_50
L_51
L_52 ,
V_347 , V_348 , V_18 ,
V_349 , V_32 , V_356 ,
V_357 , V_360 ,
V_268 , V_129 ,
V_7 , V_309 , V_308 ,
V_156 , V_302 , V_310 , V_314 ,
V_315 , V_228 , V_247 , V_219 ) ;
return 0 ;
}
static T_10 F_146 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_360 ) ;
}
static T_10 F_147 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_365 ;
char V_366 [ 20 ] ;
if ( 1 == sscanf ( V_208 , L_54 , V_366 ) ) {
if ( ( 1 == sscanf ( V_366 , L_12 , & V_365 ) ) && ( V_365 >= 0 ) ) {
V_360 = V_365 ;
return V_364 ;
}
}
return - V_53 ;
}
static T_10 F_148 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_55 , V_32 ) ;
}
static T_10 F_149 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_351 ;
char V_366 [ 20 ] ;
if ( 1 == sscanf ( V_208 , L_54 , V_366 ) ) {
if ( 0 == F_150 ( V_366 , L_56 , 2 ) ) {
if ( 1 == sscanf ( & V_366 [ 2 ] , L_57 , & V_351 ) )
goto V_367;
} else {
if ( 1 == sscanf ( V_366 , L_12 , & V_351 ) )
goto V_367;
}
}
return - V_53 ;
V_367:
V_32 = V_351 ;
V_357 = 0 ;
return V_364 ;
}
static T_10 F_151 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_117 ) ;
}
static T_10 F_152 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_109 ;
if ( ( V_364 > 0 ) && ( 1 == sscanf ( V_208 , L_12 , & V_109 ) ) && ( V_109 >= 0 ) ) {
V_117 = V_109 ;
return V_364 ;
}
return - V_53 ;
}
static T_10 F_153 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_30 ) ;
}
static T_10 F_154 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_109 ;
if ( ( V_364 > 0 ) && ( 1 == sscanf ( V_208 , L_12 , & V_109 ) ) && ( V_109 >= 0 ) ) {
V_30 = V_109 ;
return V_364 ;
}
return - V_53 ;
}
static T_10 F_155 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_368 ) ;
}
static T_10 F_156 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_109 ;
if ( ( V_364 > 0 ) && ( 1 == sscanf ( V_208 , L_12 , & V_109 ) ) && ( V_109 >= 0 ) ) {
V_368 = V_109 ;
return V_364 ;
}
return - V_53 ;
}
static T_10 F_157 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_115 ) ;
}
static T_10 F_158 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_109 ;
if ( ( V_364 > 0 ) && ( 1 == sscanf ( V_208 , L_12 , & V_109 ) ) && ( V_109 >= 0 ) ) {
V_115 = V_109 ;
return V_364 ;
}
return - V_53 ;
}
static T_10 F_159 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_18 ) ;
}
static T_10 F_160 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_109 ;
if ( ( V_364 > 0 ) && ( 1 == sscanf ( V_208 , L_12 , & V_109 ) ) && ( V_109 >= 0 ) ) {
V_18 = V_109 ;
F_5 () ;
return V_364 ;
}
return - V_53 ;
}
static T_10 F_161 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_349 ) ;
}
static T_10 F_162 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_326 ) ;
}
static T_10 F_163 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_356 ) ;
}
static T_10 F_164 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_369 ;
if ( ( V_364 > 0 ) && ( 1 == sscanf ( V_208 , L_12 , & V_369 ) ) ) {
V_356 = V_369 ;
V_357 = 0 ;
return V_364 ;
}
return - V_53 ;
}
static T_10 F_165 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_268 ) ;
}
static T_10 F_166 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_109 ;
if ( ( V_364 > 0 ) && ( 1 == sscanf ( V_208 , L_12 , & V_109 ) ) && ( V_109 >= 0 ) ) {
V_268 = V_109 ;
F_5 () ;
return V_364 ;
}
return - V_53 ;
}
static T_10 F_167 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_275 ) ;
}
static T_10 F_168 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_109 ;
if ( ( V_364 > 0 ) && ( 1 == sscanf ( V_208 , L_12 , & V_109 ) ) && ( V_109 > 0 ) &&
( V_109 <= V_370 ) ) {
V_275 = V_109 ;
return V_364 ;
}
return - V_53 ;
}
static T_10 F_169 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_299 ) ;
}
static T_10 F_170 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_129 ) ;
}
static T_10 F_171 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_139 ) ;
}
static T_10 F_172 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_109 ;
if ( ( V_364 > 0 ) && ( 1 == sscanf ( V_208 , L_12 , & V_109 ) ) && ( V_109 >= 0 ) ) {
V_139 = V_109 ;
V_142 = F_39 () ;
return V_364 ;
}
return - V_53 ;
}
static T_10 F_173 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_371 ) ;
}
static T_10 F_174 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_372 ;
if ( sscanf ( V_208 , L_12 , & V_372 ) != 1 )
return - V_53 ;
if ( V_372 > 0 ) {
do {
F_175 () ;
} while ( -- V_372 );
} else if ( V_372 < 0 ) {
do {
F_176 () ;
} while ( ++ V_372 );
}
return V_364 ;
}
static T_10 F_177 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_125 ) ;
}
static T_10 F_178 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_109 ;
if ( ( V_364 > 0 ) && ( 1 == sscanf ( V_208 , L_12 , & V_109 ) ) && ( V_109 >= 0 ) ) {
V_125 = V_109 ;
return V_364 ;
}
return - V_53 ;
}
static T_10 F_179 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_58 , V_7 ) ;
}
static T_10 F_180 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_235 ) ;
}
static T_10 F_181 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_126 ) ;
}
static T_10 F_182 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_58 , V_210 ) ;
}
static T_10 F_183 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_161 ) ;
}
static T_10 F_184 ( struct V_361 * V_362 , char * V_208 )
{
T_10 V_364 ;
if ( ! F_1 () )
return F_35 ( V_208 , V_363 , L_59 ,
V_5 ) ;
V_364 = F_185 ( V_208 , V_363 , V_252 , V_253 ) ;
V_208 [ V_364 ++ ] = '\n' ;
V_208 [ V_364 ++ ] = 0 ;
return V_364 ;
}
static T_10 F_186 ( struct V_361 * V_362 , char * V_208 )
{
return F_35 ( V_208 , V_363 , L_53 , V_128 ? 1 : 0 ) ;
}
static T_10 F_187 ( struct V_361 * V_362 , const char * V_208 ,
T_4 V_364 )
{
int V_109 ;
if ( ( V_364 > 0 ) && ( 1 == sscanf ( V_208 , L_12 , & V_109 ) ) && ( V_109 >= 0 ) ) {
V_128 = ( V_109 > 0 ) ;
return V_364 ;
}
return - V_53 ;
}
static int T_8 F_188 ( void )
{
unsigned long V_373 ;
int V_374 ;
int V_144 ;
int V_110 ;
switch ( V_7 ) {
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_11 ( V_241 L_60 ,
V_7 ) ;
return - V_53 ;
}
switch ( V_126 ) {
case V_375 :
case V_216 :
case V_218 :
case V_127 :
break;
default:
F_11 ( V_241 L_61 ) ;
return - V_53 ;
}
if ( V_210 > 1 ) {
F_11 ( V_241 L_62 ) ;
return - V_53 ;
}
if ( V_161 > 1 ) {
F_11 ( V_241 L_63 ) ;
return - V_53 ;
}
if ( V_97 > 15 ) {
F_11 ( V_241 L_64 ,
V_97 ) ;
return - V_53 ;
}
if ( V_145 > 0x3fff ) {
F_11 ( V_241 L_65 ,
V_145 ) ;
return - V_53 ;
}
if ( V_349 < 1 )
V_349 = 1 ;
V_373 = ( unsigned long ) V_349 * 1048576 ;
V_5 = V_373 / V_7 ;
V_142 = F_39 () ;
V_308 = 8 ;
V_156 = 32 ;
if ( V_349 >= 16 )
V_308 = 32 ;
else if ( V_349 >= 256 )
V_308 = 64 ;
V_309 = ( unsigned long ) V_142 /
( V_156 * V_308 ) ;
if ( V_309 >= 1024 ) {
V_308 = 255 ;
V_156 = 63 ;
V_309 = ( unsigned long ) V_142 /
( V_156 * V_308 ) ;
}
V_6 = F_189 ( V_373 ) ;
if ( NULL == V_6 ) {
F_11 ( V_241 L_66 ) ;
return - V_376 ;
}
memset ( V_6 , 0 , V_373 ) ;
if ( V_326 > 0 )
F_137 ( V_6 , V_373 ) ;
if ( V_235 ) {
int V_377 ;
V_377 = V_5 * sizeof( struct V_8 ) ;
V_10 = F_189 ( V_377 ) ;
F_11 ( V_241 L_67 ,
V_377 , V_10 ) ;
if ( V_10 == NULL ) {
F_11 ( V_241 L_68 ) ;
V_110 = - V_376 ;
goto V_378;
}
memset ( V_10 , 0xff , V_377 ) ;
}
if ( F_1 () ) {
V_99 =
F_190 ( V_99 , 0U , 0xffffffffU ) ;
V_100 =
F_190 ( V_100 , 0U , 256U ) ;
V_102 =
F_190 ( V_102 , 1U , 0xffffffffU ) ;
if ( V_101 &&
V_102 <=
V_101 ) {
F_11 ( V_241
L_69 ,
V_215 ) ;
return - V_53 ;
}
V_253 = F_88 ( V_5 - 1 ) + 1 ;
V_252 = F_189 ( F_191 ( V_253 ) * sizeof( long ) ) ;
F_11 ( V_33 L_70 ,
V_253 ) ;
if ( V_252 == NULL ) {
F_11 ( V_241 L_71 ) ;
V_110 = - V_376 ;
goto V_378;
}
F_192 ( V_252 , V_253 ) ;
if ( V_326 )
F_95 ( 0 , 2 ) ;
}
V_379 = F_193 ( L_72 ) ;
if ( F_194 ( V_379 ) ) {
F_11 ( V_327 L_73 ) ;
V_110 = F_195 ( V_379 ) ;
goto V_378;
}
V_110 = F_196 ( & V_380 ) ;
if ( V_110 < 0 ) {
F_11 ( V_327 L_74 ,
V_110 ) ;
goto V_381;
}
V_110 = F_197 ( & V_382 ) ;
if ( V_110 < 0 ) {
F_11 ( V_327 L_75 ,
V_110 ) ;
goto V_383;
}
F_135 () ;
V_374 = V_371 ;
V_371 = 0 ;
for ( V_144 = 0 ; V_144 < V_374 ; V_144 ++ ) {
if ( F_175 () ) {
F_11 ( V_241 L_76
L_77 , V_144 ) ;
break;
}
}
if ( V_31 & V_32 ) {
F_11 ( V_33 L_78 ,
V_371 ) ;
}
return 0 ;
V_383:
F_198 ( & V_380 ) ;
V_381:
F_199 ( V_379 ) ;
V_378:
if ( V_252 )
F_200 ( V_252 ) ;
if ( V_10 )
F_200 ( V_10 ) ;
F_200 ( V_6 ) ;
return V_110 ;
}
static void T_11 F_201 ( void )
{
int V_144 = V_371 ;
F_127 () ;
for (; V_144 ; V_144 -- )
F_176 () ;
F_202 ( & V_382 ) ;
F_198 ( & V_380 ) ;
F_199 ( V_379 ) ;
if ( V_10 )
F_200 ( V_10 ) ;
F_200 ( V_6 ) ;
}
static void F_203 ( struct V_311 * V_51 )
{
struct V_11 * V_12 ;
V_12 = F_204 ( V_51 ) ;
F_34 ( V_12 ) ;
}
static int F_175 ( void )
{
int V_144 , V_384 ;
int error = 0 ;
struct V_11 * V_12 ;
struct V_22 * V_385 , * V_386 ;
V_12 = F_33 ( sizeof( * V_12 ) , V_387 ) ;
if ( NULL == V_12 ) {
F_11 ( V_241 L_29 ,
V_215 , __LINE__ ) ;
return - V_376 ;
}
F_205 ( & V_12 -> V_285 ) ;
V_384 = V_18 * V_268 ;
for ( V_144 = 0 ; V_144 < V_384 ; V_144 ++ ) {
V_385 = F_115 ( V_12 , V_387 ) ;
if ( ! V_385 ) {
F_11 ( V_241 L_29 ,
V_215 , __LINE__ ) ;
error = - V_376 ;
goto V_388;
}
}
F_6 ( & V_15 ) ;
F_116 ( & V_12 -> V_389 , & V_390 ) ;
F_8 ( & V_15 ) ;
V_12 -> V_51 . V_391 = & V_380 ;
V_12 -> V_51 . V_392 = V_379 ;
V_12 -> V_51 . V_393 = & F_203 ;
F_206 ( & V_12 -> V_51 , L_79 , V_371 ) ;
error = F_207 ( & V_12 -> V_51 ) ;
if ( error )
goto V_388;
++ V_371 ;
return error ;
V_388:
F_208 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_209 ( & V_385 -> V_284 ) ;
F_34 ( V_385 ) ;
}
F_34 ( V_12 ) ;
return error ;
}
static void F_176 ( void )
{
struct V_11 * V_12 = NULL ;
F_6 ( & V_15 ) ;
if ( ! F_210 ( & V_390 ) ) {
V_12 = F_211 ( V_390 . V_394 ,
struct V_11 , V_389 ) ;
F_209 ( & V_12 -> V_389 ) ;
}
F_8 ( & V_15 ) ;
if ( ! V_12 )
return;
F_212 ( & V_12 -> V_51 ) ;
-- V_371 ;
}
static
int F_213 ( struct V_54 * V_55 , T_9 V_337 )
{
unsigned char * V_34 = ( unsigned char * ) V_55 -> V_107 ;
int V_121 , V_144 ;
unsigned int V_35 ;
unsigned long long V_4 ;
T_2 V_36 ;
int V_137 = 0 ;
int V_105 = V_55 -> V_311 -> V_291 ;
struct V_22 * V_23 = NULL ;
int V_395 = 0 ;
int V_396 = 0 ;
int V_397 = 0 ;
int V_398 = 0 ;
int V_399 = 0 ;
int V_254 = 0 ;
F_77 ( V_55 , 0 ) ;
if ( ( V_31 & V_32 ) && V_34 ) {
F_11 ( V_33 L_80 ) ;
for ( V_144 = 0 , V_121 = V_55 -> V_400 ; V_144 < V_121 ; ++ V_144 )
F_11 ( L_20 , ( int ) V_34 [ V_144 ] ) ;
F_11 ( L_21 ) ;
}
if ( V_105 == V_55 -> V_311 -> V_289 -> V_401 -> V_17 ) {
F_11 ( V_33 L_81
L_82 ) ;
return F_139 ( V_55 , NULL , V_337 ,
V_402 << 16 , 0 ) ;
}
if ( ( V_55 -> V_311 -> V_116 >= V_268 ) &&
( V_55 -> V_311 -> V_116 != V_21 ) )
return F_139 ( V_55 , NULL , V_337 ,
V_402 << 16 , 0 ) ;
V_23 = F_117 ( V_55 -> V_311 ) ;
if ( NULL == V_23 )
return F_139 ( V_55 , NULL , V_337 ,
V_402 << 16 , 0 ) ;
if ( ( V_356 != 0 ) &&
( ++ V_357 >= abs ( V_356 ) ) ) {
V_357 = 0 ;
if ( V_356 < - 1 )
V_356 = - 1 ;
if ( V_403 & V_32 )
return 0 ;
else if ( V_404 & V_32 &&
F_214 ( V_55 ) )
return 0 ;
else if ( V_405 & V_32 )
V_395 = 1 ;
else if ( V_406 & V_32 )
V_396 = 1 ;
else if ( V_407 & V_32 )
V_397 = 1 ;
else if ( V_408 & V_32 )
V_398 = 1 ;
}
if ( V_23 -> V_114 ) {
switch ( * V_34 ) {
case V_409 :
case V_410 :
case V_411 :
case V_412 :
break;
default:
if ( V_31 & V_32 )
F_11 ( V_33 L_83
L_84 , * V_34 ) ;
F_9 ( V_23 , V_118 ,
V_413 , 0 ) ;
V_137 = V_60 ;
return F_139 ( V_55 , V_23 , V_337 , V_137 ,
0 ) ;
}
}
switch ( * V_34 ) {
case V_409 :
V_399 = 1 ;
V_137 = F_32 ( V_55 , V_105 , V_23 ) ;
break;
case V_410 :
V_399 = 1 ;
V_137 = F_37 ( V_55 , V_23 ) ;
break;
case V_414 :
case V_415 :
V_137 = F_38 ( V_55 , V_23 ) ;
break;
case V_416 :
V_137 = F_14 ( V_55 , 1 , V_23 ) ;
if ( V_137 )
break;
if ( V_31 & V_32 )
F_11 ( V_33 L_85 ,
V_34 [ 4 ] ? L_86 : L_87 ) ;
break;
case V_417 :
V_137 = F_14 ( V_55 , 1 , V_23 ) ;
break;
case V_411 :
V_399 = 1 ;
V_137 = F_14 ( V_55 , 0 , V_23 ) ;
break;
case V_418 :
V_137 = F_14 ( V_55 , 1 , V_23 ) ;
break;
case V_419 :
V_137 = F_14 ( V_55 , 1 , V_23 ) ;
break;
case V_420 :
V_137 = F_14 ( V_55 , 1 , V_23 ) ;
break;
case V_421 :
V_137 = F_14 ( V_55 , 1 , V_23 ) ;
break;
case V_422 :
V_137 = F_40 ( V_55 , V_23 ) ;
break;
case V_423 :
if ( V_34 [ 1 ] == V_424 )
V_137 = F_41 ( V_55 , V_23 ) ;
else if ( V_34 [ 1 ] == V_425 ) {
if ( F_1 () == 0 ) {
F_9 ( V_23 , V_118 ,
V_426 , 0 ) ;
V_137 = V_60 ;
} else
V_137 = F_108 ( V_55 , V_23 ) ;
} else {
F_9 ( V_23 , V_118 ,
V_413 , 0 ) ;
V_137 = V_60 ;
}
break;
case V_427 :
if ( V_428 != V_34 [ 1 ] ) {
F_9 ( V_23 , V_118 ,
V_413 , 0 ) ;
V_137 = V_60 ;
break;
}
V_137 = F_42 ( V_55 , V_23 ) ;
break;
case V_41 :
case V_43 :
case V_46 :
if ( V_126 == V_218 &&
V_34 [ 1 ] & 0xe0 ) {
F_9 ( V_23 , V_118 ,
V_426 , 0 ) ;
V_137 = V_60 ;
break;
}
if ( ( V_126 == V_216 ||
V_126 == V_127 ) &&
( V_34 [ 1 ] & 0xe0 ) == 0 )
F_11 ( V_241 L_88 ) ;
case V_49 :
V_221:
V_137 = F_14 ( V_55 , 0 , V_23 ) ;
if ( V_137 )
break;
if ( V_368 )
break;
F_12 ( V_34 , & V_4 , & V_35 , & V_36 ) ;
V_137 = F_76 ( V_55 , V_4 , V_35 , V_23 , V_36 ) ;
if ( V_395 && ( 0 == V_137 ) ) {
F_9 ( V_23 , V_429 ,
V_135 , 0 ) ;
V_137 = V_60 ;
} else if ( V_396 && ( 0 == V_137 ) ) {
F_9 ( V_23 , V_237 ,
V_430 , V_431 ) ;
V_137 = V_60 ;
} else if ( V_397 && ( 0 == V_137 ) ) {
F_9 ( V_23 , V_237 , 0x10 , 1 ) ;
V_137 = V_238 ;
} else if ( V_398 && ( 0 == V_137 ) ) {
F_9 ( V_23 , V_118 , 0x10 , 1 ) ;
V_137 = V_238 ;
}
break;
case V_412 :
V_399 = 1 ;
V_137 = F_109 ( V_55 , V_23 ) ;
break;
case V_432 :
V_137 = F_14 ( V_55 , 0 , V_23 ) ;
break;
case V_40 :
case V_42 :
case V_45 :
if ( V_126 == V_218 &&
V_34 [ 1 ] & 0xe0 ) {
F_9 ( V_23 , V_118 ,
V_426 , 0 ) ;
V_137 = V_60 ;
break;
}
if ( ( V_126 == V_216 ||
V_126 == V_127 ) &&
( V_34 [ 1 ] & 0xe0 ) == 0 )
F_11 ( V_241 L_88 ) ;
case V_48 :
V_200:
V_137 = F_14 ( V_55 , 0 , V_23 ) ;
if ( V_137 )
break;
if ( V_368 )
break;
F_12 ( V_34 , & V_4 , & V_35 , & V_36 ) ;
V_137 = F_99 ( V_55 , V_4 , V_35 , V_23 , V_36 ) ;
if ( V_395 && ( 0 == V_137 ) ) {
F_9 ( V_23 , V_429 ,
V_135 , 0 ) ;
V_137 = V_60 ;
} else if ( V_397 && ( 0 == V_137 ) ) {
F_9 ( V_23 , V_237 , 0x10 , 1 ) ;
V_137 = V_238 ;
} else if ( V_398 && ( 0 == V_137 ) ) {
F_9 ( V_23 , V_118 , 0x10 , 1 ) ;
V_137 = V_238 ;
}
break;
case V_39 :
case V_44 :
if ( V_34 [ 1 ] & 0x8 ) {
if ( ( * V_34 == V_39 && V_2 == 0 ) ||
( * V_34 == V_44 && V_3 == 0 ) ) {
F_9 ( V_23 , V_118 ,
V_119 , 0 ) ;
V_137 = V_60 ;
} else
V_254 = 1 ;
}
if ( V_137 )
break;
V_137 = F_14 ( V_55 , 0 , V_23 ) ;
if ( V_137 )
break;
F_12 ( V_34 , & V_4 , & V_35 , & V_36 ) ;
V_137 = F_102 ( V_55 , V_4 , V_35 , V_23 , V_36 , V_254 ) ;
break;
case V_433 :
V_137 = F_14 ( V_55 , 0 , V_23 ) ;
if ( V_137 )
break;
if ( V_100 == 0 || V_1 == 0 ) {
F_9 ( V_23 , V_118 ,
V_426 , 0 ) ;
V_137 = V_60 ;
} else
V_137 = F_103 ( V_55 , V_23 ) ;
break;
case V_177 :
case V_434 :
V_137 = F_52 ( V_55 , V_105 , V_23 ) ;
break;
case V_435 :
V_137 = F_54 ( V_55 , 1 , V_23 ) ;
break;
case V_436 :
V_137 = F_54 ( V_55 , 0 , V_23 ) ;
break;
case V_437 :
V_137 = F_57 ( V_55 , V_23 ) ;
break;
case V_438 :
V_399 = 1 ;
V_137 = F_14 ( V_55 , 0 , V_23 ) ;
break;
case V_439 :
V_137 = F_14 ( V_55 , 1 , V_23 ) ;
break;
case V_47 :
if ( ! F_17 ( V_55 ) ) {
F_9 ( V_23 , V_118 ,
V_119 , 0 ) ;
V_137 = V_60 ;
break;
}
V_137 = F_14 ( V_55 , 0 , V_23 ) ;
if ( V_137 )
break;
if ( V_368 )
break;
F_12 ( V_34 , & V_4 , & V_35 , & V_36 ) ;
V_137 = F_76 ( V_55 , V_4 , V_35 , V_23 , V_36 ) ;
if ( V_137 )
break;
V_137 = F_99 ( V_55 , V_4 , V_35 , V_23 , V_36 ) ;
if ( V_137 )
break;
V_137 = F_110 ( V_55 , V_4 , V_35 , V_23 ) ;
break;
case V_37 :
if ( V_126 == V_218 ) {
if ( ( V_34 [ 10 ] & 0xe0 ) == 0 )
F_11 ( V_241
L_88 ) ;
if ( V_34 [ 9 ] == V_440 ) {
F_84 ( V_55 -> V_400 < 32 ) ;
goto V_221;
}
if ( V_34 [ 9 ] == V_441 ) {
F_84 ( V_55 -> V_400 < 32 ) ;
goto V_200;
}
}
F_9 ( V_23 , V_118 ,
V_119 , 0 ) ;
V_137 = V_60 ;
break;
default:
if ( V_31 & V_32 )
F_11 ( V_33 L_89
L_90 , * V_34 ) ;
V_137 = F_14 ( V_55 , 1 , V_23 ) ;
if ( V_137 )
break;
F_9 ( V_23 , V_118 , V_413 , 0 ) ;
V_137 = V_60 ;
break;
}
return F_139 ( V_55 , V_23 , V_337 , V_137 ,
( V_399 ? 0 : V_360 ) ) ;
}
static int F_215 ( struct V_311 * V_51 )
{
int error = 0 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_442 ;
V_12 = F_204 ( V_51 ) ;
V_443 . V_444 = V_275 ;
V_14 = F_216 ( & V_443 , sizeof( V_12 ) ) ;
if ( NULL == V_14 ) {
F_11 ( V_241 L_91 , V_215 ) ;
error = - V_445 ;
return error ;
}
V_12 -> V_16 = V_14 ;
* ( (struct V_11 * * ) V_14 -> V_288 ) = V_12 ;
if ( ( V_14 -> V_17 >= 0 ) && ( V_18 > V_14 -> V_17 ) )
V_14 -> V_19 = V_18 + 1 ;
else
V_14 -> V_19 = V_18 ;
V_14 -> V_20 = V_21 ;
V_442 = 0 ;
switch ( V_126 ) {
case V_216 :
V_442 = V_446 ;
if ( V_235 )
V_442 |= V_447 ;
break;
case V_218 :
V_442 = V_448 ;
if ( V_235 )
V_442 |= V_449 ;
break;
case V_127 :
V_442 = V_450 ;
if ( V_235 )
V_442 |= V_451 ;
break;
default:
if ( V_235 )
V_442 |= V_452 ;
break;
}
F_217 ( V_14 , V_442 ) ;
F_11 ( V_33 L_92 ,
( V_442 & V_446 ) ? L_93 : L_94 ,
( V_442 & V_448 ) ? L_95 : L_94 ,
( V_442 & V_450 ) ? L_96 : L_94 ,
( V_442 & V_452 ) ? L_97 : L_94 ,
( V_442 & V_447 ) ? L_98 : L_94 ,
( V_442 & V_449 ) ? L_99 : L_94 ,
( V_442 & V_451 ) ? L_100 : L_94 ) ;
if ( V_210 == 1 )
F_218 ( V_14 , V_453 ) ;
else
F_218 ( V_14 , V_454 ) ;
error = F_219 ( V_14 , & V_12 -> V_51 ) ;
if ( error ) {
F_11 ( V_241 L_101 , V_215 ) ;
error = - V_445 ;
F_220 ( V_14 ) ;
} else
F_221 ( V_14 ) ;
return error ;
}
static int F_222 ( struct V_311 * V_51 )
{
struct V_11 * V_12 ;
struct V_22 * V_385 , * V_386 ;
V_12 = F_204 ( V_51 ) ;
if ( ! V_12 ) {
F_11 ( V_241 L_102 ,
V_215 ) ;
return - V_445 ;
}
F_223 ( V_12 -> V_16 ) ;
F_208 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_209 ( & V_385 -> V_284 ) ;
F_34 ( V_385 ) ;
}
F_220 ( V_12 -> V_16 ) ;
return 0 ;
}
static int F_224 ( struct V_311 * V_51 ,
struct V_361 * V_455 )
{
return 1 ;
}
