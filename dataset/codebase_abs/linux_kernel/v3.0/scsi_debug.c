static unsigned int F_1 ( void )
{
return V_1 | V_2 | V_3 ;
}
static inline T_1 F_2 ( T_1 V_4 )
{
return V_4 << 3 ;
}
static void F_3 ( void )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_4 ( & V_9 ) ;
F_5 (sdbg_host, &sdebug_host_list, host_list) {
V_8 = V_6 -> V_10 ;
if ( ( V_8 -> V_11 >= 0 ) &&
( V_12 > V_8 -> V_11 ) )
V_8 -> V_13 = V_12 + 1 ;
else
V_8 -> V_13 = V_12 ;
V_8 -> V_14 = V_15 ;
}
F_6 ( & V_9 ) ;
}
static void F_7 ( struct V_16 * V_17 , int V_18 ,
int V_19 , int V_20 )
{
unsigned char * V_21 ;
V_21 = V_17 -> V_22 ;
memset ( V_21 , 0 , V_23 ) ;
F_8 ( V_24 , V_21 , V_18 , V_19 , V_20 ) ;
if ( V_25 & V_26 )
F_9 ( V_27 L_1
L_2 , V_18 , V_19 , V_20 ) ;
}
static void F_10 ( unsigned char * V_28 ,
unsigned long long * V_29 , unsigned int * V_30 ,
T_2 * V_31 )
{
* V_31 = 0 ;
switch ( * V_28 ) {
case V_32 :
* V_29 = ( V_33 ) V_28 [ 19 ] | ( V_33 ) V_28 [ 18 ] << 8 |
( V_33 ) V_28 [ 17 ] << 16 | ( V_33 ) V_28 [ 16 ] << 24 |
( V_33 ) V_28 [ 15 ] << 32 | ( V_33 ) V_28 [ 14 ] << 40 |
( V_33 ) V_28 [ 13 ] << 48 | ( V_33 ) V_28 [ 12 ] << 56 ;
* V_31 = ( T_2 ) V_28 [ 23 ] | ( T_2 ) V_28 [ 22 ] << 8 |
( T_2 ) V_28 [ 21 ] << 16 | ( T_2 ) V_28 [ 20 ] << 24 ;
* V_30 = ( T_2 ) V_28 [ 31 ] | ( T_2 ) V_28 [ 30 ] << 8 | ( T_2 ) V_28 [ 29 ] << 16 |
( T_2 ) V_28 [ 28 ] << 24 ;
break;
case V_34 :
case V_35 :
case V_36 :
* V_29 = ( V_33 ) V_28 [ 9 ] | ( V_33 ) V_28 [ 8 ] << 8 |
( V_33 ) V_28 [ 7 ] << 16 | ( V_33 ) V_28 [ 6 ] << 24 |
( V_33 ) V_28 [ 5 ] << 32 | ( V_33 ) V_28 [ 4 ] << 40 |
( V_33 ) V_28 [ 3 ] << 48 | ( V_33 ) V_28 [ 2 ] << 56 ;
* V_30 = ( T_2 ) V_28 [ 13 ] | ( T_2 ) V_28 [ 12 ] << 8 | ( T_2 ) V_28 [ 11 ] << 16 |
( T_2 ) V_28 [ 10 ] << 24 ;
break;
case V_37 :
case V_38 :
* V_29 = ( T_2 ) V_28 [ 5 ] | ( T_2 ) V_28 [ 4 ] << 8 | ( T_2 ) V_28 [ 3 ] << 16 |
( T_2 ) V_28 [ 2 ] << 24 ;
* V_30 = ( T_2 ) V_28 [ 9 ] | ( T_2 ) V_28 [ 8 ] << 8 | ( T_2 ) V_28 [ 7 ] << 16 |
( T_2 ) V_28 [ 6 ] << 24 ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
* V_29 = ( T_2 ) V_28 [ 5 ] | ( T_2 ) V_28 [ 4 ] << 8 | ( T_2 ) V_28 [ 3 ] << 16 |
( T_2 ) V_28 [ 2 ] << 24 ;
* V_30 = ( T_2 ) V_28 [ 8 ] | ( T_2 ) V_28 [ 7 ] << 8 ;
break;
case V_43 :
case V_44 :
* V_29 = ( T_2 ) V_28 [ 3 ] | ( T_2 ) V_28 [ 2 ] << 8 |
( T_2 ) ( V_28 [ 1 ] & 0x1f ) << 16 ;
* V_30 = ( 0 == V_28 [ 4 ] ) ? 256 : V_28 [ 4 ] ;
break;
default:
break;
}
}
static int F_11 ( struct V_45 * V_46 , int V_28 , void T_3 * V_47 )
{
if ( V_25 & V_26 ) {
F_9 ( V_27 L_3 , V_28 ) ;
}
return - V_48 ;
}
static int F_12 ( struct V_49 * V_50 , int V_51 ,
struct V_16 * V_17 )
{
if ( V_17 -> V_52 ) {
if ( V_25 & V_26 )
F_9 ( V_27 L_4
L_5 ) ;
V_17 -> V_52 = 0 ;
F_7 ( V_17 , V_53 , V_54 , 0 ) ;
return V_55 ;
}
if ( ( 0 == V_51 ) && V_17 -> V_56 ) {
if ( V_25 & V_26 )
F_9 ( V_27 L_6
L_7 ) ;
F_7 ( V_17 , V_57 , V_58 ,
0x2 ) ;
return V_55 ;
}
return 0 ;
}
static int F_13 ( struct V_49 * V_59 , unsigned char * V_60 ,
int V_61 )
{
int V_62 ;
struct V_63 * V_64 = F_14 ( V_59 ) ;
if ( ! V_64 -> V_65 )
return 0 ;
if ( ! ( F_15 ( V_59 ) || V_59 -> V_66 == V_67 ) )
return ( V_68 << 16 ) ;
V_62 = F_16 ( V_64 -> V_69 . V_70 , V_64 -> V_69 . V_71 ,
V_60 , V_61 ) ;
if ( V_64 -> V_72 )
V_64 -> V_72 -= V_62 ;
else
V_64 -> V_72 = F_17 ( V_59 ) - V_62 ;
return 0 ;
}
static int F_18 ( struct V_49 * V_59 , unsigned char * V_60 ,
int V_61 )
{
if ( ! F_17 ( V_59 ) )
return 0 ;
if ( ! ( F_15 ( V_59 ) || V_59 -> V_66 == V_73 ) )
return - 1 ;
return F_19 ( V_59 , V_60 , V_61 ) ;
}
static int F_20 ( unsigned char * V_60 , int V_74 ,
int V_75 , int V_76 ,
const char * V_77 ,
int V_78 )
{
int V_30 , V_79 ;
char V_80 [ 32 ] ;
V_79 = V_75 + 1 ;
V_60 [ 0 ] = 0x2 ;
V_60 [ 1 ] = 0x1 ;
V_60 [ 2 ] = 0x0 ;
memcpy ( & V_60 [ 4 ] , V_81 , 8 ) ;
memcpy ( & V_60 [ 12 ] , V_82 , 16 ) ;
memcpy ( & V_60 [ 28 ] , V_77 , V_78 ) ;
V_30 = 8 + 16 + V_78 ;
V_60 [ 3 ] = V_30 ;
V_30 += 4 ;
if ( V_76 >= 0 ) {
V_60 [ V_30 ++ ] = 0x1 ;
V_60 [ V_30 ++ ] = 0x3 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x8 ;
V_60 [ V_30 ++ ] = 0x53 ;
V_60 [ V_30 ++ ] = 0x33 ;
V_60 [ V_30 ++ ] = 0x33 ;
V_60 [ V_30 ++ ] = 0x30 ;
V_60 [ V_30 ++ ] = ( V_76 >> 24 ) ;
V_60 [ V_30 ++ ] = ( V_76 >> 16 ) & 0xff ;
V_60 [ V_30 ++ ] = ( V_76 >> 8 ) & 0xff ;
V_60 [ V_30 ++ ] = V_76 & 0xff ;
V_60 [ V_30 ++ ] = 0x61 ;
V_60 [ V_30 ++ ] = 0x94 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x4 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x1 ;
}
V_60 [ V_30 ++ ] = 0x61 ;
V_60 [ V_30 ++ ] = 0x93 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x8 ;
V_60 [ V_30 ++ ] = 0x52 ;
V_60 [ V_30 ++ ] = 0x22 ;
V_60 [ V_30 ++ ] = 0x22 ;
V_60 [ V_30 ++ ] = 0x20 ;
V_60 [ V_30 ++ ] = ( V_79 >> 24 ) ;
V_60 [ V_30 ++ ] = ( V_79 >> 16 ) & 0xff ;
V_60 [ V_30 ++ ] = ( V_79 >> 8 ) & 0xff ;
V_60 [ V_30 ++ ] = V_79 & 0xff ;
V_60 [ V_30 ++ ] = 0x61 ;
V_60 [ V_30 ++ ] = 0x95 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x4 ;
V_60 [ V_30 ++ ] = 0 ;
V_60 [ V_30 ++ ] = 0 ;
V_60 [ V_30 ++ ] = ( V_74 >> 8 ) & 0xff ;
V_60 [ V_30 ++ ] = V_74 & 0xff ;
V_60 [ V_30 ++ ] = 0x61 ;
V_60 [ V_30 ++ ] = 0xa3 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x8 ;
V_60 [ V_30 ++ ] = 0x52 ;
V_60 [ V_30 ++ ] = 0x22 ;
V_60 [ V_30 ++ ] = 0x22 ;
V_60 [ V_30 ++ ] = 0x20 ;
V_60 [ V_30 ++ ] = ( V_75 >> 24 ) ;
V_60 [ V_30 ++ ] = ( V_75 >> 16 ) & 0xff ;
V_60 [ V_30 ++ ] = ( V_75 >> 8 ) & 0xff ;
V_60 [ V_30 ++ ] = V_75 & 0xff ;
V_60 [ V_30 ++ ] = 0x63 ;
V_60 [ V_30 ++ ] = 0xa8 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 24 ;
memcpy ( V_60 + V_30 , L_8 , 12 ) ;
V_30 += 12 ;
snprintf ( V_80 , sizeof( V_80 ) , L_9 , V_75 ) ;
memcpy ( V_60 + V_30 , V_80 , 8 ) ;
V_30 += 8 ;
memset ( V_60 + V_30 , 0 , 4 ) ;
V_30 += 4 ;
return V_30 ;
}
static int F_21 ( unsigned char * V_60 )
{
memcpy ( V_60 , V_83 , sizeof( V_83 ) ) ;
return sizeof( V_83 ) ;
}
static int F_22 ( unsigned char * V_60 )
{
int V_30 = 0 ;
const char * V_84 = L_10 ;
const char * V_85 = L_11 ;
int V_86 , V_87 ;
V_60 [ V_30 ++ ] = 0x1 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_87 = strlen ( V_84 ) ;
V_86 = V_87 + 1 ;
if ( V_86 % 4 )
V_86 = ( ( V_86 / 4 ) + 1 ) * 4 ;
V_60 [ V_30 ++ ] = V_86 ;
memcpy ( V_60 + V_30 , V_84 , V_87 ) ;
memset ( V_60 + V_30 + V_87 , 0 , V_86 - V_87 ) ;
V_30 += V_86 ;
V_60 [ V_30 ++ ] = 0x4 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_87 = strlen ( V_85 ) ;
V_86 = V_87 + 1 ;
if ( V_86 % 4 )
V_86 = ( ( V_86 / 4 ) + 1 ) * 4 ;
V_60 [ V_30 ++ ] = V_86 ;
memcpy ( V_60 + V_30 , V_85 , V_87 ) ;
memset ( V_60 + V_30 + V_87 , 0 , V_86 - V_87 ) ;
V_30 += V_86 ;
return V_30 ;
}
static int F_23 ( unsigned char * V_60 , int V_75 )
{
int V_30 = 0 ;
int V_79 , V_88 ;
V_79 = V_75 + 1 ;
V_88 = V_79 + 1 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x1 ;
memset ( V_60 + V_30 , 0 , 6 ) ;
V_30 += 6 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 12 ;
V_60 [ V_30 ++ ] = 0x61 ;
V_60 [ V_30 ++ ] = 0x93 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x8 ;
V_60 [ V_30 ++ ] = 0x52 ;
V_60 [ V_30 ++ ] = 0x22 ;
V_60 [ V_30 ++ ] = 0x22 ;
V_60 [ V_30 ++ ] = 0x20 ;
V_60 [ V_30 ++ ] = ( V_79 >> 24 ) ;
V_60 [ V_30 ++ ] = ( V_79 >> 16 ) & 0xff ;
V_60 [ V_30 ++ ] = ( V_79 >> 8 ) & 0xff ;
V_60 [ V_30 ++ ] = V_79 & 0xff ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x2 ;
memset ( V_60 + V_30 , 0 , 6 ) ;
V_30 += 6 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 12 ;
V_60 [ V_30 ++ ] = 0x61 ;
V_60 [ V_30 ++ ] = 0x93 ;
V_60 [ V_30 ++ ] = 0x0 ;
V_60 [ V_30 ++ ] = 0x8 ;
V_60 [ V_30 ++ ] = 0x52 ;
V_60 [ V_30 ++ ] = 0x22 ;
V_60 [ V_30 ++ ] = 0x22 ;
V_60 [ V_30 ++ ] = 0x20 ;
V_60 [ V_30 ++ ] = ( V_88 >> 24 ) ;
V_60 [ V_30 ++ ] = ( V_88 >> 16 ) & 0xff ;
V_60 [ V_30 ++ ] = ( V_88 >> 8 ) & 0xff ;
V_60 [ V_30 ++ ] = V_88 & 0xff ;
return V_30 ;
}
static int F_24 ( unsigned char * V_60 )
{
memcpy ( V_60 , V_89 , sizeof( V_89 ) ) ;
return sizeof( V_89 ) ;
}
static int F_25 ( unsigned char * V_60 )
{
unsigned int V_90 ;
memcpy ( V_60 , V_91 , sizeof( V_91 ) ) ;
V_90 = 1 << V_92 ;
V_60 [ 2 ] = ( V_90 >> 8 ) & 0xff ;
V_60 [ 3 ] = V_90 & 0xff ;
if ( V_93 > 0x400 ) {
V_60 [ 4 ] = ( V_93 >> 24 ) & 0xff ;
V_60 [ 5 ] = ( V_93 >> 16 ) & 0xff ;
V_60 [ 6 ] = ( V_93 >> 8 ) & 0xff ;
V_60 [ 7 ] = V_93 & 0xff ;
}
F_26 ( V_94 , & V_60 [ 8 ] ) ;
if ( V_1 ) {
F_26 ( V_95 , & V_60 [ 16 ] ) ;
F_26 ( V_96 , & V_60 [ 20 ] ) ;
}
if ( V_97 ) {
F_26 ( V_97 , & V_60 [ 28 ] ) ;
V_60 [ 28 ] |= 0x80 ;
}
F_26 ( V_98 , & V_60 [ 24 ] ) ;
F_27 ( V_99 , & V_60 [ 32 ] ) ;
return 0x3c ;
return sizeof( V_91 ) ;
}
static int F_28 ( unsigned char * V_60 )
{
memset ( V_60 , 0 , 0x3c ) ;
V_60 [ 0 ] = 0 ;
V_60 [ 1 ] = 1 ;
V_60 [ 2 ] = 0 ;
V_60 [ 3 ] = 5 ;
return 0x3c ;
}
static int F_29 ( unsigned char * V_60 )
{
memset ( V_60 , 0 , 0x8 ) ;
V_60 [ 0 ] = 0 ;
if ( V_1 )
V_60 [ 1 ] = 1 << 7 ;
if ( V_2 )
V_60 [ 1 ] |= 1 << 6 ;
if ( V_3 )
V_60 [ 1 ] |= 1 << 5 ;
return 0x8 ;
}
static int F_30 ( struct V_49 * V_59 , int V_100 ,
struct V_16 * V_17 )
{
unsigned char V_101 ;
unsigned char * V_60 ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_102 ;
int V_103 , V_104 , V_105 ;
V_103 = ( V_28 [ 3 ] << 8 ) + V_28 [ 4 ] ;
V_60 = F_31 ( V_106 , V_107 ) ;
if ( ! V_60 )
return V_108 << 16 ;
if ( V_17 -> V_109 )
V_101 = 0x1e ;
else if ( V_110 && ( 0 == V_17 -> V_111 ) )
V_101 = 0x7f ;
else
V_101 = ( V_112 & 0x1f ) ;
V_60 [ 0 ] = V_101 ;
if ( 0x2 & V_28 [ 1 ] ) {
F_7 ( V_17 , V_113 , V_114 ,
0 ) ;
F_32 ( V_60 ) ;
return V_55 ;
} else if ( 0x1 & V_28 [ 1 ] ) {
int V_115 , V_74 , V_75 , V_116 ;
char V_117 [ 6 ] ;
int V_118 = V_17 -> V_6 -> V_10 -> V_118 ;
V_74 = ( ( ( V_118 + 1 ) & 0x7f ) << 8 ) +
( V_17 -> V_119 & 0x7f ) ;
if ( 0 == V_120 )
V_118 = 0 ;
V_115 = V_17 -> V_109 ? - 1 : ( ( ( V_118 + 1 ) * 2000 ) +
( V_17 -> V_100 * 1000 ) + V_17 -> V_111 ) ;
V_75 = ( ( V_118 + 1 ) * 2000 ) +
( V_17 -> V_100 * 1000 ) - 3 ;
V_116 = F_33 ( V_117 , 6 , L_12 , V_115 ) ;
if ( 0 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_104 = 4 ;
V_60 [ V_104 ++ ] = 0x0 ;
V_60 [ V_104 ++ ] = 0x80 ;
V_60 [ V_104 ++ ] = 0x83 ;
V_60 [ V_104 ++ ] = 0x84 ;
V_60 [ V_104 ++ ] = 0x85 ;
V_60 [ V_104 ++ ] = 0x86 ;
V_60 [ V_104 ++ ] = 0x87 ;
V_60 [ V_104 ++ ] = 0x88 ;
V_60 [ V_104 ++ ] = 0x89 ;
V_60 [ V_104 ++ ] = 0xb0 ;
V_60 [ V_104 ++ ] = 0xb1 ;
if ( F_1 () )
V_60 [ V_104 ++ ] = 0xb2 ;
V_60 [ 3 ] = V_104 - 4 ;
} else if ( 0x80 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = V_116 ;
memcpy ( & V_60 [ 4 ] , V_117 , V_116 ) ;
} else if ( 0x83 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = F_20 ( & V_60 [ 4 ] , V_74 ,
V_75 , V_115 ,
V_117 , V_116 ) ;
} else if ( 0x84 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = F_21 ( & V_60 [ 4 ] ) ;
} else if ( 0x85 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = F_22 ( & V_60 [ 4 ] ) ;
} else if ( 0x86 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = 0x3c ;
if ( V_121 == V_122 )
V_60 [ 4 ] = 0x4 ;
else if ( V_121 )
V_60 [ 4 ] = 0x5 ;
else
V_60 [ 4 ] = 0x0 ;
V_60 [ 5 ] = 0x7 ;
} else if ( 0x87 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = 0x8 ;
V_60 [ 4 ] = 0x2 ;
V_60 [ 6 ] = 0x80 ;
V_60 [ 8 ] = 0x18 ;
V_60 [ 10 ] = 0x82 ;
} else if ( 0x88 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = F_23 ( & V_60 [ 4 ] , V_75 ) ;
} else if ( 0x89 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_104 = F_24 ( & V_60 [ 4 ] ) ;
V_60 [ 2 ] = ( V_104 >> 8 ) ;
V_60 [ 3 ] = ( V_104 & 0xff ) ;
} else if ( 0xb0 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = F_25 ( & V_60 [ 4 ] ) ;
} else if ( 0xb1 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = F_28 ( & V_60 [ 4 ] ) ;
} else if ( 0xb2 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = F_29 ( & V_60 [ 4 ] ) ;
} else {
F_7 ( V_17 , V_113 ,
V_114 , 0 ) ;
F_32 ( V_60 ) ;
return V_55 ;
}
V_116 = F_34 ( ( ( V_60 [ 2 ] << 8 ) + V_60 [ 3 ] ) + 4 , V_103 ) ;
V_105 = F_13 ( V_59 , V_60 ,
F_34 ( V_116 , V_106 ) ) ;
F_32 ( V_60 ) ;
return V_105 ;
}
V_60 [ 1 ] = F_35 ( V_100 ) ? 0x80 : 0 ;
V_60 [ 2 ] = V_123 ;
V_60 [ 3 ] = 2 ;
V_60 [ 4 ] = V_124 - 5 ;
V_60 [ 5 ] = V_121 ? 1 : 0 ;
if ( 0 == V_120 )
V_60 [ 5 ] = 0x10 ;
V_60 [ 6 ] = 0x10 ;
V_60 [ 7 ] = 0xa ;
memcpy ( & V_60 [ 8 ] , V_81 , 8 ) ;
memcpy ( & V_60 [ 16 ] , V_82 , 16 ) ;
memcpy ( & V_60 [ 32 ] , V_125 , 4 ) ;
V_60 [ 58 ] = 0x0 ; V_60 [ 59 ] = 0x77 ;
V_60 [ 60 ] = 0x3 ; V_60 [ 61 ] = 0x14 ;
V_104 = 62 ;
if ( V_112 == 0 ) {
V_60 [ V_104 ++ ] = 0x3 ; V_60 [ V_104 ++ ] = 0x3d ;
} else if ( V_112 == 1 ) {
V_60 [ V_104 ++ ] = 0x3 ; V_60 [ V_104 ++ ] = 0x60 ;
}
V_60 [ V_104 ++ ] = 0xc ; V_60 [ V_104 ++ ] = 0xf ;
V_105 = F_13 ( V_59 , V_60 ,
F_34 ( V_103 , V_124 ) ) ;
F_32 ( V_60 ) ;
return V_105 ;
}
static int F_36 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char * V_21 ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_102 ;
unsigned char V_60 [ V_23 ] ;
int V_126 ;
int V_116 = 18 ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
if ( V_17 -> V_52 == 1 )
F_7 ( V_17 , 0 , V_127 , 0 ) ;
V_126 = ! ! ( V_28 [ 1 ] & 1 ) || V_24 ;
V_21 = V_17 -> V_22 ;
if ( ( V_128 [ 2 ] & 0x4 ) && ( 6 == ( V_128 [ 3 ] & 0xf ) ) ) {
if ( V_126 ) {
V_60 [ 0 ] = 0x72 ;
V_60 [ 1 ] = 0x0 ;
V_60 [ 2 ] = V_129 ;
V_60 [ 3 ] = 0xff ;
} else {
V_60 [ 0 ] = 0x70 ;
V_60 [ 2 ] = 0x0 ;
V_60 [ 7 ] = 0xa ;
V_60 [ 12 ] = V_129 ;
V_60 [ 13 ] = 0xff ;
}
} else {
memcpy ( V_60 , V_21 , V_23 ) ;
if ( ( V_28 [ 1 ] & 1 ) && ( ! V_24 ) ) {
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
V_60 [ 0 ] = 0x72 ;
V_60 [ 1 ] = V_21 [ 2 ] ;
V_60 [ 2 ] = V_21 [ 12 ] ;
V_60 [ 3 ] = V_21 [ 13 ] ;
V_116 = 8 ;
}
}
F_7 ( V_17 , 0 , V_127 , 0 ) ;
return F_13 ( V_59 , V_60 , V_116 ) ;
}
static int F_37 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_102 ;
int V_130 , V_131 , V_132 ;
if ( ( V_131 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_131 ;
V_130 = ( V_28 [ 4 ] & 0xf0 ) >> 4 ;
if ( V_130 ) {
F_7 ( V_17 , V_113 , V_114 ,
0 ) ;
return V_55 ;
}
V_132 = V_28 [ 4 ] & 1 ;
if ( V_132 == V_17 -> V_56 )
V_17 -> V_56 = ! V_132 ;
return 0 ;
}
static T_1 F_38 ( void )
{
if ( V_133 > 0 )
return ( T_1 ) V_133 *
( 1073741824 / V_134 ) ;
else
return V_93 ;
}
static int F_39 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char V_60 [ V_135 ] ;
unsigned int V_136 ;
int V_131 ;
if ( ( V_131 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_131 ;
V_137 = F_38 () ;
memset ( V_60 , 0 , V_135 ) ;
if ( V_137 < 0xffffffff ) {
V_136 = ( unsigned int ) V_137 - 1 ;
V_60 [ 0 ] = ( V_136 >> 24 ) ;
V_60 [ 1 ] = ( V_136 >> 16 ) & 0xff ;
V_60 [ 2 ] = ( V_136 >> 8 ) & 0xff ;
V_60 [ 3 ] = V_136 & 0xff ;
} else {
V_60 [ 0 ] = 0xff ;
V_60 [ 1 ] = 0xff ;
V_60 [ 2 ] = 0xff ;
V_60 [ 3 ] = 0xff ;
}
V_60 [ 6 ] = ( V_134 >> 8 ) & 0xff ;
V_60 [ 7 ] = V_134 & 0xff ;
return F_13 ( V_59 , V_60 , V_135 ) ;
}
static int F_40 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_102 ;
unsigned char V_60 [ V_138 ] ;
unsigned long long V_136 ;
int V_131 , V_139 , V_103 ;
if ( ( V_131 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_131 ;
V_103 = ( ( V_28 [ 10 ] << 24 ) + ( V_28 [ 11 ] << 16 ) + ( V_28 [ 12 ] << 8 )
+ V_28 [ 13 ] ) ;
V_137 = F_38 () ;
memset ( V_60 , 0 , V_138 ) ;
V_136 = V_137 - 1 ;
for ( V_139 = 0 ; V_139 < 8 ; ++ V_139 , V_136 >>= 8 )
V_60 [ 7 - V_139 ] = V_136 & 0xff ;
V_60 [ 8 ] = ( V_134 >> 24 ) & 0xff ;
V_60 [ 9 ] = ( V_134 >> 16 ) & 0xff ;
V_60 [ 10 ] = ( V_134 >> 8 ) & 0xff ;
V_60 [ 11 ] = V_134 & 0xff ;
V_60 [ 13 ] = V_92 & 0xf ;
V_60 [ 14 ] = ( V_140 >> 8 ) & 0x3f ;
if ( F_1 () )
V_60 [ 14 ] |= 0x80 ;
V_60 [ 15 ] = V_140 & 0xff ;
if ( V_121 ) {
V_60 [ 12 ] = ( V_121 - 1 ) << 1 ;
V_60 [ 12 ] |= 1 ;
}
return F_13 ( V_59 , V_60 ,
F_34 ( V_103 , V_138 ) ) ;
}
static int F_41 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_102 ;
unsigned char * V_60 ;
int V_118 = V_17 -> V_6 -> V_10 -> V_118 ;
int V_104 , V_105 , V_141 , V_142 ;
int V_143 , V_144 , V_79 , V_88 ;
V_141 = ( ( V_28 [ 6 ] << 24 ) + ( V_28 [ 7 ] << 16 ) + ( V_28 [ 8 ] << 8 )
+ V_28 [ 9 ] ) ;
V_60 = F_31 ( V_145 , V_107 ) ;
if ( ! V_60 )
return V_108 << 16 ;
V_79 = 0x1 ;
V_88 = 0x2 ;
V_143 = ( ( ( V_118 + 1 ) & 0x7f ) << 8 ) +
( V_17 -> V_119 & 0x7f ) ;
V_144 = ( ( ( V_118 + 1 ) & 0x7f ) << 8 ) +
( V_17 -> V_119 & 0x7f ) + 0x80 ;
V_104 = 4 ;
if ( 0 == V_120 ) {
V_60 [ V_104 ++ ] = V_118 % 3 ;
V_60 [ V_104 ++ ] = 0x0F ;
} else {
V_60 [ V_104 ++ ] = 0x0 ;
V_60 [ V_104 ++ ] = 0x01 ;
}
V_60 [ V_104 ++ ] = ( V_143 >> 8 ) & 0xff ;
V_60 [ V_104 ++ ] = V_143 & 0xff ;
V_60 [ V_104 ++ ] = 0 ;
V_60 [ V_104 ++ ] = 0 ;
V_60 [ V_104 ++ ] = 0 ;
V_60 [ V_104 ++ ] = 0x1 ;
V_60 [ V_104 ++ ] = 0 ;
V_60 [ V_104 ++ ] = 0 ;
V_60 [ V_104 ++ ] = ( V_79 >> 8 ) & 0xff ;
V_60 [ V_104 ++ ] = V_79 & 0xff ;
V_60 [ V_104 ++ ] = 3 ;
V_60 [ V_104 ++ ] = 0x08 ;
V_60 [ V_104 ++ ] = ( V_144 >> 8 ) & 0xff ;
V_60 [ V_104 ++ ] = V_144 & 0xff ;
V_60 [ V_104 ++ ] = 0 ;
V_60 [ V_104 ++ ] = 0 ;
V_60 [ V_104 ++ ] = 0 ;
V_60 [ V_104 ++ ] = 0x1 ;
V_60 [ V_104 ++ ] = 0 ;
V_60 [ V_104 ++ ] = 0 ;
V_60 [ V_104 ++ ] = ( V_88 >> 8 ) & 0xff ;
V_60 [ V_104 ++ ] = V_88 & 0xff ;
V_142 = V_104 - 4 ;
V_60 [ 0 ] = ( V_142 >> 24 ) & 0xff ;
V_60 [ 1 ] = ( V_142 >> 16 ) & 0xff ;
V_60 [ 2 ] = ( V_142 >> 8 ) & 0xff ;
V_60 [ 3 ] = V_142 & 0xff ;
V_142 = F_34 ( V_141 , V_104 ) ;
V_105 = F_13 ( V_59 , V_60 ,
F_34 ( V_142 , V_145 ) ) ;
F_32 ( V_60 ) ;
return V_105 ;
}
static int F_42 ( unsigned char * V_146 , int V_147 , int V_100 )
{
unsigned char V_148 [] = { 0x1 , 0xa , 0xc0 , 11 , 240 , 0 , 0 , 0 ,
5 , 0 , 0xff , 0xff } ;
memcpy ( V_146 , V_148 , sizeof( V_148 ) ) ;
if ( 1 == V_147 )
memset ( V_146 + 2 , 0 , sizeof( V_148 ) - 2 ) ;
return sizeof( V_148 ) ;
}
static int F_43 ( unsigned char * V_146 , int V_147 , int V_100 )
{
unsigned char V_149 [] = { 0x2 , 0xe , 128 , 128 , 0 , 10 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_146 , V_149 , sizeof( V_149 ) ) ;
if ( 1 == V_147 )
memset ( V_146 + 2 , 0 , sizeof( V_149 ) - 2 ) ;
return sizeof( V_149 ) ;
}
static int F_44 ( unsigned char * V_146 , int V_147 , int V_100 )
{
unsigned char V_150 [] = { 0x3 , 0x16 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0x40 , 0 , 0 , 0 } ;
memcpy ( V_146 , V_150 , sizeof( V_150 ) ) ;
V_146 [ 10 ] = ( V_151 >> 8 ) & 0xff ;
V_146 [ 11 ] = V_151 & 0xff ;
V_146 [ 12 ] = ( V_134 >> 8 ) & 0xff ;
V_146 [ 13 ] = V_134 & 0xff ;
if ( F_35 ( V_100 ) )
V_146 [ 20 ] |= 0x20 ;
if ( 1 == V_147 )
memset ( V_146 + 2 , 0 , sizeof( V_150 ) - 2 ) ;
return sizeof( V_150 ) ;
}
static int F_45 ( unsigned char * V_146 , int V_147 , int V_100 )
{
unsigned char V_152 [] = { 0x8 , 18 , 0x14 , 0 , 0xff , 0xff , 0 , 0 ,
0xff , 0xff , 0xff , 0xff , 0x80 , 0x14 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_146 , V_152 , sizeof( V_152 ) ) ;
if ( 1 == V_147 )
memset ( V_146 + 2 , 0 , sizeof( V_152 ) - 2 ) ;
return sizeof( V_152 ) ;
}
static int F_46 ( unsigned char * V_146 , int V_147 , int V_100 )
{
unsigned char V_153 [] = { 0x6 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ;
unsigned char V_154 [] = { 0xa , 10 , 2 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x2 , 0x4b } ;
if ( V_24 )
V_155 [ 2 ] |= 0x4 ;
else
V_155 [ 2 ] &= ~ 0x4 ;
if ( V_156 )
V_155 [ 5 ] |= 0x80 ;
memcpy ( V_146 , V_155 , sizeof( V_155 ) ) ;
if ( 1 == V_147 )
memcpy ( V_146 + 2 , V_153 , sizeof( V_153 ) ) ;
else if ( 2 == V_147 )
memcpy ( V_146 , V_154 , sizeof( V_154 ) ) ;
return sizeof( V_155 ) ;
}
static int F_47 ( unsigned char * V_146 , int V_147 , int V_100 )
{
unsigned char V_157 [] = { 0x4 , 0xf , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
unsigned char V_158 [] = { 0x1c , 0xa , 0x08 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
memcpy ( V_146 , V_128 , sizeof( V_128 ) ) ;
if ( 1 == V_147 )
memcpy ( V_146 + 2 , V_157 , sizeof( V_157 ) ) ;
else if ( 2 == V_147 )
memcpy ( V_146 , V_158 , sizeof( V_158 ) ) ;
return sizeof( V_128 ) ;
}
static int F_48 ( unsigned char * V_146 , int V_147 , int V_100 )
{
unsigned char V_159 [] = { 0x19 , 0x6 ,
0x6 , 0x0 , 0x7 , 0xd0 , 0x0 , 0x0 } ;
memcpy ( V_146 , V_159 , sizeof( V_159 ) ) ;
if ( 1 == V_147 )
memset ( V_146 + 2 , 0 , sizeof( V_159 ) - 2 ) ;
return sizeof( V_159 ) ;
}
static int F_49 ( unsigned char * V_146 , int V_147 , int V_100 ,
int V_75 )
{
unsigned char V_160 [] = { 0x59 , 0x1 , 0 , 0x64 , 0 , 0x6 , 0 , 2 ,
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
int V_79 , V_88 ;
V_79 = V_75 + 1 ;
V_88 = V_79 + 1 ;
memcpy ( V_146 , V_160 , sizeof( V_160 ) ) ;
V_146 [ 20 ] = ( V_79 >> 24 ) ;
V_146 [ 21 ] = ( V_79 >> 16 ) & 0xff ;
V_146 [ 22 ] = ( V_79 >> 8 ) & 0xff ;
V_146 [ 23 ] = V_79 & 0xff ;
V_146 [ 48 + 20 ] = ( V_88 >> 24 ) ;
V_146 [ 48 + 21 ] = ( V_88 >> 16 ) & 0xff ;
V_146 [ 48 + 22 ] = ( V_88 >> 8 ) & 0xff ;
V_146 [ 48 + 23 ] = V_88 & 0xff ;
if ( 1 == V_147 )
memset ( V_146 + 4 , 0 , sizeof( V_160 ) - 4 ) ;
return sizeof( V_160 ) ;
}
static int F_50 ( unsigned char * V_146 , int V_147 )
{
unsigned char V_161 [] = { 0x59 , 0x2 , 0 , 0xc , 0 , 0x6 , 0x10 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
memcpy ( V_146 , V_161 , sizeof( V_161 ) ) ;
if ( 1 == V_147 )
memset ( V_146 + 4 , 0 , sizeof( V_161 ) - 4 ) ;
return sizeof( V_161 ) ;
}
static int F_51 ( struct V_49 * V_59 , int V_100 ,
struct V_16 * V_17 )
{
unsigned char V_162 , V_163 ;
int V_147 , V_164 , V_165 , V_166 ;
unsigned char V_167 ;
int V_139 , V_103 , V_168 , V_169 , V_116 , V_131 , V_75 ;
unsigned char * V_170 ;
unsigned char V_60 [ V_171 ] ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_102 ;
if ( ( V_131 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_131 ;
V_162 = ! ! ( V_28 [ 1 ] & 0x8 ) ;
V_147 = ( V_28 [ 2 ] & 0xc0 ) >> 6 ;
V_164 = V_28 [ 2 ] & 0x3f ;
V_165 = V_28 [ 3 ] ;
V_168 = ( V_172 == V_28 [ 0 ] ) ;
V_163 = V_168 ? 0 : ! ! ( V_28 [ 1 ] & 0x10 ) ;
if ( ( 0 == V_112 ) && ( 0 == V_162 ) )
V_166 = V_163 ? 16 : 8 ;
else
V_166 = 0 ;
V_103 = V_168 ? V_28 [ 4 ] : ( ( V_28 [ 7 ] << 8 ) | V_28 [ 8 ] ) ;
memset ( V_60 , 0 , V_171 ) ;
if ( 0x3 == V_147 ) {
F_7 ( V_17 , V_113 , V_173 ,
0 ) ;
return V_55 ;
}
V_75 = ( ( V_17 -> V_6 -> V_10 -> V_118 + 1 ) * 2000 ) +
( V_17 -> V_100 * 1000 ) - 3 ;
if ( 0 == V_112 )
V_167 = ( F_52 ( V_100 ) ? 0x80 : 0x0 ) | 0x10 ;
else
V_167 = 0x0 ;
if ( V_168 ) {
V_60 [ 2 ] = V_167 ;
V_60 [ 3 ] = V_166 ;
V_169 = 4 ;
} else {
V_60 [ 3 ] = V_167 ;
if ( 16 == V_166 )
V_60 [ 4 ] = 0x1 ;
V_60 [ 7 ] = V_166 ;
V_169 = 8 ;
}
V_170 = V_60 + V_169 ;
if ( ( V_166 > 0 ) && ( ! V_137 ) )
V_137 = F_38 () ;
if ( 8 == V_166 ) {
if ( V_137 > 0xfffffffe ) {
V_170 [ 0 ] = 0xff ;
V_170 [ 1 ] = 0xff ;
V_170 [ 2 ] = 0xff ;
V_170 [ 3 ] = 0xff ;
} else {
V_170 [ 0 ] = ( V_137 >> 24 ) & 0xff ;
V_170 [ 1 ] = ( V_137 >> 16 ) & 0xff ;
V_170 [ 2 ] = ( V_137 >> 8 ) & 0xff ;
V_170 [ 3 ] = V_137 & 0xff ;
}
V_170 [ 6 ] = ( V_134 >> 8 ) & 0xff ;
V_170 [ 7 ] = V_134 & 0xff ;
V_169 += V_166 ;
V_170 = V_60 + V_169 ;
} else if ( 16 == V_166 ) {
unsigned long long V_136 = V_137 ;
for ( V_139 = 0 ; V_139 < 8 ; ++ V_139 , V_136 >>= 8 )
V_170 [ 7 - V_139 ] = V_136 & 0xff ;
V_170 [ 12 ] = ( V_134 >> 24 ) & 0xff ;
V_170 [ 13 ] = ( V_134 >> 16 ) & 0xff ;
V_170 [ 14 ] = ( V_134 >> 8 ) & 0xff ;
V_170 [ 15 ] = V_134 & 0xff ;
V_169 += V_166 ;
V_170 = V_60 + V_169 ;
}
if ( ( V_165 > 0x0 ) && ( V_165 < 0xff ) && ( 0x19 != V_164 ) ) {
F_7 ( V_17 , V_113 , V_114 ,
0 ) ;
return V_55 ;
}
switch ( V_164 ) {
case 0x1 :
V_116 = F_42 ( V_170 , V_147 , V_100 ) ;
V_169 += V_116 ;
break;
case 0x2 :
V_116 = F_43 ( V_170 , V_147 , V_100 ) ;
V_169 += V_116 ;
break;
case 0x3 :
V_116 = F_44 ( V_170 , V_147 , V_100 ) ;
V_169 += V_116 ;
break;
case 0x8 :
V_116 = F_45 ( V_170 , V_147 , V_100 ) ;
V_169 += V_116 ;
break;
case 0xa :
V_116 = F_46 ( V_170 , V_147 , V_100 ) ;
V_169 += V_116 ;
break;
case 0x19 :
if ( ( V_165 > 0x2 ) && ( V_165 < 0xff ) ) {
F_7 ( V_17 , V_113 ,
V_114 , 0 ) ;
return V_55 ;
}
V_116 = 0 ;
if ( ( 0x0 == V_165 ) || ( 0xff == V_165 ) )
V_116 += F_48 ( V_170 + V_116 , V_147 , V_100 ) ;
if ( ( 0x1 == V_165 ) || ( 0xff == V_165 ) )
V_116 += F_49 ( V_170 + V_116 , V_147 , V_100 ,
V_75 ) ;
if ( ( 0x2 == V_165 ) || ( 0xff == V_165 ) )
V_116 += F_50 ( V_170 + V_116 , V_147 ) ;
V_169 += V_116 ;
break;
case 0x1c :
V_116 = F_47 ( V_170 , V_147 , V_100 ) ;
V_169 += V_116 ;
break;
case 0x3f :
if ( ( 0 == V_165 ) || ( 0xff == V_165 ) ) {
V_116 = F_42 ( V_170 , V_147 , V_100 ) ;
V_116 += F_43 ( V_170 + V_116 , V_147 , V_100 ) ;
V_116 += F_44 ( V_170 + V_116 , V_147 , V_100 ) ;
V_116 += F_45 ( V_170 + V_116 , V_147 , V_100 ) ;
V_116 += F_46 ( V_170 + V_116 , V_147 , V_100 ) ;
V_116 += F_48 ( V_170 + V_116 , V_147 , V_100 ) ;
if ( 0xff == V_165 ) {
V_116 += F_49 ( V_170 + V_116 , V_147 ,
V_100 , V_75 ) ;
V_116 += F_50 ( V_170 + V_116 , V_147 ) ;
}
V_116 += F_47 ( V_170 + V_116 , V_147 , V_100 ) ;
} else {
F_7 ( V_17 , V_113 ,
V_114 , 0 ) ;
return V_55 ;
}
V_169 += V_116 ;
break;
default:
F_7 ( V_17 , V_113 , V_114 ,
0 ) ;
return V_55 ;
}
if ( V_168 )
V_60 [ 0 ] = V_169 - 1 ;
else {
V_60 [ 0 ] = ( ( V_169 - 2 ) >> 8 ) & 0xff ;
V_60 [ 1 ] = ( V_169 - 2 ) & 0xff ;
}
return F_13 ( V_59 , V_60 , F_34 ( V_103 , V_169 ) ) ;
}
static int F_53 ( struct V_49 * V_59 , int V_174 ,
struct V_16 * V_17 )
{
int V_175 , V_176 , V_177 , V_178 , V_166 , V_179 , V_180 , V_181 ;
int V_182 , V_183 , V_131 , V_184 ;
unsigned char V_60 [ V_185 ] ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_102 ;
if ( ( V_131 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_131 ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
V_175 = V_28 [ 1 ] & 0x10 ;
V_176 = V_28 [ 1 ] & 0x1 ;
V_182 = V_174 ? V_28 [ 4 ] : ( ( V_28 [ 7 ] << 8 ) + V_28 [ 8 ] ) ;
if ( ( 0 == V_175 ) || V_176 || ( V_182 > V_185 ) ) {
F_7 ( V_17 , V_113 ,
V_114 , 0 ) ;
return V_55 ;
}
V_183 = F_18 ( V_59 , V_60 , V_182 ) ;
if ( - 1 == V_183 )
return ( V_68 << 16 ) ;
else if ( ( V_183 < V_182 ) &&
( V_25 & V_26 ) )
F_9 ( V_27 L_13
L_14 , V_182 , V_183 ) ;
V_178 = V_174 ? ( V_60 [ 0 ] + 1 ) : ( ( V_60 [ 0 ] << 8 ) + V_60 [ 1 ] + 2 ) ;
V_166 = V_174 ? V_60 [ 3 ] : ( ( V_60 [ 6 ] << 8 ) + V_60 [ 7 ] ) ;
if ( V_178 > 2 ) {
F_7 ( V_17 , V_113 ,
V_186 , 0 ) ;
return V_55 ;
}
V_179 = V_166 + ( V_174 ? 4 : 8 ) ;
V_184 = V_60 [ V_179 ] & 0x3f ;
V_177 = ! ! ( V_60 [ V_179 ] & 0x80 ) ;
if ( V_177 ) {
F_7 ( V_17 , V_113 ,
V_186 , 0 ) ;
return V_55 ;
}
V_180 = ! ! ( V_60 [ V_179 ] & 0x40 ) ;
V_181 = V_180 ? ( ( V_60 [ V_179 + 2 ] << 8 ) + V_60 [ V_179 + 3 ] + 4 ) :
( V_60 [ V_179 + 1 ] + 2 ) ;
if ( ( V_181 + V_179 ) > V_182 ) {
F_7 ( V_17 , V_113 ,
V_187 , 0 ) ;
return V_55 ;
}
switch ( V_184 ) {
case 0xa :
if ( V_155 [ 1 ] == V_60 [ V_179 + 1 ] ) {
memcpy ( V_155 + 2 , V_60 + V_179 + 2 ,
sizeof( V_155 ) - 2 ) ;
V_24 = ! ! ( V_155 [ 2 ] & 0x4 ) ;
return 0 ;
}
break;
case 0x1c :
if ( V_128 [ 1 ] == V_60 [ V_179 + 1 ] ) {
memcpy ( V_128 + 2 , V_60 + V_179 + 2 ,
sizeof( V_128 ) - 2 ) ;
return 0 ;
}
break;
default:
break;
}
F_7 ( V_17 , V_113 ,
V_186 , 0 ) ;
return V_55 ;
}
static int F_54 ( unsigned char * V_60 )
{
unsigned char V_188 [] = { 0x0 , 0x0 , 0x3 , 0x2 , 0x0 , 38 ,
0x0 , 0x1 , 0x3 , 0x2 , 0x0 , 65 ,
} ;
memcpy ( V_60 , V_188 , sizeof( V_188 ) ) ;
return sizeof( V_188 ) ;
}
static int F_55 ( unsigned char * V_60 )
{
unsigned char V_189 [] = { 0x0 , 0x0 , 0x3 , 0x3 , 0x0 , 0x0 , 38 ,
} ;
memcpy ( V_60 , V_189 , sizeof( V_189 ) ) ;
if ( V_128 [ 2 ] & 0x4 ) {
V_60 [ 4 ] = V_129 ;
V_60 [ 5 ] = 0xff ;
}
return sizeof( V_189 ) ;
}
static int F_56 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
int V_190 , V_176 , V_147 , V_164 , V_165 , V_103 , V_131 , V_116 , V_104 ;
unsigned char V_60 [ V_191 ] ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_102 ;
if ( ( V_131 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_131 ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
V_190 = V_28 [ 1 ] & 0x2 ;
V_176 = V_28 [ 1 ] & 0x1 ;
if ( V_190 || V_176 ) {
F_7 ( V_17 , V_113 ,
V_114 , 0 ) ;
return V_55 ;
}
V_147 = ( V_28 [ 2 ] & 0xc0 ) >> 6 ;
V_164 = V_28 [ 2 ] & 0x3f ;
V_165 = V_28 [ 3 ] & 0xff ;
V_103 = ( V_28 [ 7 ] << 8 ) + V_28 [ 8 ] ;
V_60 [ 0 ] = V_164 ;
if ( 0 == V_165 ) {
switch ( V_164 ) {
case 0x0 :
V_104 = 4 ;
V_60 [ V_104 ++ ] = 0x0 ;
V_60 [ V_104 ++ ] = 0xd ;
V_60 [ V_104 ++ ] = 0x2f ;
V_60 [ 3 ] = V_104 - 4 ;
break;
case 0xd :
V_60 [ 3 ] = F_54 ( V_60 + 4 ) ;
break;
case 0x2f :
V_60 [ 3 ] = F_55 ( V_60 + 4 ) ;
break;
default:
F_7 ( V_17 , V_113 ,
V_114 , 0 ) ;
return V_55 ;
}
} else if ( 0xff == V_165 ) {
V_60 [ 0 ] |= 0x40 ;
V_60 [ 1 ] = V_165 ;
switch ( V_164 ) {
case 0x0 :
V_104 = 4 ;
V_60 [ V_104 ++ ] = 0x0 ;
V_60 [ V_104 ++ ] = 0x0 ;
V_60 [ V_104 ++ ] = 0x0 ;
V_60 [ V_104 ++ ] = 0xff ;
V_60 [ V_104 ++ ] = 0xd ;
V_60 [ V_104 ++ ] = 0x0 ;
V_60 [ V_104 ++ ] = 0x2f ;
V_60 [ V_104 ++ ] = 0x0 ;
V_60 [ 3 ] = V_104 - 4 ;
break;
case 0xd :
V_104 = 4 ;
V_60 [ V_104 ++ ] = 0xd ;
V_60 [ V_104 ++ ] = 0x0 ;
V_60 [ 3 ] = V_104 - 4 ;
break;
case 0x2f :
V_104 = 4 ;
V_60 [ V_104 ++ ] = 0x2f ;
V_60 [ V_104 ++ ] = 0x0 ;
V_60 [ 3 ] = V_104 - 4 ;
break;
default:
F_7 ( V_17 , V_113 ,
V_114 , 0 ) ;
return V_55 ;
}
} else {
F_7 ( V_17 , V_113 ,
V_114 , 0 ) ;
return V_55 ;
}
V_116 = F_34 ( ( ( V_60 [ 2 ] << 8 ) + V_60 [ 3 ] ) + 4 , V_103 ) ;
return F_13 ( V_59 , V_60 ,
F_34 ( V_116 , V_106 ) ) ;
}
static int F_57 ( struct V_16 * V_192 ,
unsigned long long V_29 , unsigned int V_30 )
{
if ( V_29 + V_30 > V_137 ) {
F_7 ( V_192 , V_113 , V_193 , 0 ) ;
return V_55 ;
}
if ( V_30 > V_93 ) {
F_7 ( V_192 , V_113 , V_114 , 0 ) ;
return V_55 ;
}
return 0 ;
}
static int F_58 ( struct V_49 * V_194 ,
struct V_16 * V_192 ,
unsigned long long V_29 , unsigned int V_30 , int V_195 )
{
int V_105 ;
unsigned long long V_196 , V_197 = 0 ;
int (* F_59)( struct V_49 * , unsigned char * , int );
F_59 = V_195 ? F_18 : F_13 ;
V_196 = F_60 ( V_29 , V_93 ) ;
if ( V_196 + V_30 > V_93 )
V_197 = V_196 + V_30 - V_93 ;
V_105 = F_59 ( V_194 , V_198 + ( V_196 * V_134 ) ,
( V_30 - V_197 ) * V_134 ) ;
if ( ! V_105 && V_197 )
V_105 = F_59 ( V_194 , V_198 , V_197 * V_134 ) ;
return V_105 ;
}
static int F_61 ( struct V_49 * V_50 , T_1 V_199 ,
unsigned int V_200 , T_2 V_31 )
{
unsigned int V_201 , V_72 ;
struct V_202 * V_203 ;
struct V_204 * V_205 ;
T_1 V_4 ;
T_1 V_206 = V_199 ;
void * V_207 ;
V_199 = F_60 ( V_206 , V_93 ) ;
V_205 = (struct V_204 * ) ( V_208 + F_2 ( V_199 ) ) ;
for ( V_201 = 0 ; V_201 < V_200 ; V_201 ++ ) {
T_4 V_209 ;
if ( V_205 [ V_201 ] . V_210 == 0xffff )
continue;
V_4 = V_199 + V_201 ;
switch ( V_211 ) {
case 1 :
V_209 = F_62 ( V_198 +
V_4 * V_134 ,
V_134 ) ;
break;
case 0 :
V_209 = F_63 ( V_198 +
V_4 * V_134 ,
V_134 ) ;
V_209 = F_64 ( V_209 ) ;
break;
default:
F_65 () ;
}
if ( V_205 [ V_201 ] . V_212 != V_209 ) {
F_9 ( V_213 L_15 \
L_16 , V_214 ,
( unsigned long ) V_4 ,
F_66 ( V_205 [ V_201 ] . V_212 ) ,
F_66 ( V_209 ) ) ;
V_215 ++ ;
return 0x01 ;
}
if ( V_121 == V_216 &&
F_67 ( V_205 [ V_201 ] . V_217 ) != ( V_4 & 0xffffffff ) ) {
F_9 ( V_213 L_17 ,
V_214 , ( unsigned long ) V_4 ) ;
V_215 ++ ;
return 0x03 ;
}
if ( V_121 == V_218 &&
F_67 ( V_205 [ V_201 ] . V_217 ) != V_31 ) {
F_9 ( V_213 L_17 ,
V_214 , ( unsigned long ) V_4 ) ;
V_215 ++ ;
return 0x03 ;
}
V_31 ++ ;
}
V_72 = V_200 * 8 ;
V_4 = V_199 ;
F_68 (SCpnt, psgl, scsi_prot_sg_count(SCpnt), i) {
int V_116 = F_34 ( V_203 -> V_65 , V_72 ) ;
V_207 = F_69 ( F_70 ( V_203 ) , V_219 ) + V_203 -> V_169 ;
memcpy ( V_207 , V_208 + F_2 ( V_4 ) , V_116 ) ;
V_4 += V_116 >> 3 ;
if ( V_4 >= V_93 ) {
V_206 = V_4 ;
V_4 = F_60 ( V_206 , V_93 ) ;
}
V_72 -= V_116 ;
F_71 ( V_207 , V_219 ) ;
}
V_220 ++ ;
return 0 ;
}
static int F_72 ( struct V_49 * V_50 , unsigned long long V_29 ,
unsigned int V_30 , struct V_16 * V_17 ,
T_2 V_31 )
{
unsigned long V_221 ;
int V_105 ;
V_105 = F_57 ( V_17 , V_29 , V_30 ) ;
if ( V_105 )
return V_105 ;
if ( ( V_222 & V_26 ) &&
( V_29 <= ( V_223 + V_224 - 1 ) ) &&
( ( V_29 + V_30 ) > V_223 ) ) {
F_7 ( V_17 , V_225 , V_226 , 0 ) ;
if ( 0x70 == ( V_17 -> V_22 [ 0 ] & 0x7f ) ) {
V_17 -> V_22 [ 0 ] |= 0x80 ;
V_105 = ( V_29 < V_223 )
? V_223 : ( int ) V_29 ;
V_17 -> V_22 [ 3 ] = ( V_105 >> 24 ) & 0xff ;
V_17 -> V_22 [ 4 ] = ( V_105 >> 16 ) & 0xff ;
V_17 -> V_22 [ 5 ] = ( V_105 >> 8 ) & 0xff ;
V_17 -> V_22 [ 6 ] = V_105 & 0xff ;
}
F_73 ( V_50 , F_17 ( V_50 ) ) ;
return V_55 ;
}
if ( V_227 && F_74 ( V_50 ) ) {
int V_228 = F_61 ( V_50 , V_29 , V_30 , V_31 ) ;
if ( V_228 ) {
F_7 ( V_17 , V_229 , 0x10 , V_228 ) ;
return V_230 ;
}
}
F_75 ( & V_231 , V_221 ) ;
V_105 = F_58 ( V_50 , V_17 , V_29 , V_30 , 0 ) ;
F_76 ( & V_231 , V_221 ) ;
return V_105 ;
}
void F_77 ( unsigned char * V_232 , int V_116 )
{
int V_201 , V_233 ;
F_9 ( V_213 L_18 ) ;
for ( V_201 = 0 ; V_201 < V_116 ; V_201 += 16 ) {
F_9 ( V_213 L_19 , V_201 ) ;
for ( V_233 = 0 ; V_233 < 16 ; V_233 ++ ) {
unsigned char V_234 = V_232 [ V_201 + V_233 ] ;
if ( V_234 >= 0x20 && V_234 < 0x7e )
F_9 ( L_20 , V_232 [ V_201 + V_233 ] ) ;
else
F_9 ( L_21 , V_232 [ V_201 + V_233 ] ) ;
}
F_9 ( L_22 ) ;
}
}
static int F_78 ( struct V_49 * V_50 , T_1 V_199 ,
unsigned int V_200 , T_2 V_31 )
{
int V_201 , V_233 , V_105 ;
struct V_204 * V_205 ;
struct V_202 * V_235 = F_79 ( V_50 ) ;
struct V_202 * V_203 = F_80 ( V_50 ) ;
void * V_236 , * V_207 ;
T_1 V_206 = V_199 ;
T_1 V_4 ;
int V_237 ;
unsigned short V_209 ;
V_4 = F_60 ( V_206 , V_93 ) ;
F_81 ( F_82 ( V_50 ) == 0 ) ;
F_81 ( F_74 ( V_50 ) == 0 ) ;
V_207 = F_69 ( F_70 ( V_203 ) , V_238 ) + V_203 -> V_169 ;
V_237 = 0 ;
F_83 (SCpnt, dsgl, scsi_sg_count(SCpnt), i) {
V_236 = F_69 ( F_70 ( V_235 ) , V_219 ) + V_235 -> V_169 ;
for ( V_233 = 0 ; V_233 < V_235 -> V_65 ; V_233 += V_134 ) {
if ( V_237 >= V_203 -> V_65 ) {
F_71 ( V_207 , V_238 ) ;
V_203 = F_84 ( V_203 ) ;
F_81 ( V_203 == NULL ) ;
V_207 = F_69 ( F_70 ( V_203 ) , V_238 )
+ V_203 -> V_169 ;
V_237 = 0 ;
}
V_205 = V_207 + V_237 ;
switch ( V_211 ) {
case 1 :
V_209 = F_62 ( V_236 ,
V_134 ) ;
break;
case 0 :
V_209 = F_64 ( F_63 ( V_236 ,
V_134 ) ) ;
break;
default:
F_65 () ;
V_105 = 0 ;
goto V_239;
}
if ( V_205 -> V_212 != V_209 ) {
F_9 ( V_213
L_23 \
L_24 ,
V_214 , ( unsigned long ) V_4 ,
F_66 ( V_205 -> V_212 ) ,
F_66 ( V_209 ) ) ;
V_105 = 0x01 ;
F_77 ( V_236 , V_134 ) ;
goto V_239;
}
if ( V_121 == V_216 &&
F_67 ( V_205 -> V_217 )
!= ( V_199 & 0xffffffff ) ) {
F_9 ( V_213
L_17 ,
V_214 , ( unsigned long ) V_4 ) ;
V_105 = 0x03 ;
F_77 ( V_236 , V_134 ) ;
goto V_239;
}
if ( V_121 == V_218 &&
F_67 ( V_205 -> V_217 ) != V_31 ) {
F_9 ( V_213
L_17 ,
V_214 , ( unsigned long ) V_4 ) ;
V_105 = 0x03 ;
F_77 ( V_236 , V_134 ) ;
goto V_239;
}
memcpy ( V_208 + F_2 ( V_4 ) , V_205 , 8 ) ;
V_4 ++ ;
if ( V_4 == V_93 )
V_4 = 0 ;
V_199 ++ ;
V_31 ++ ;
V_236 += V_134 ;
V_237 += sizeof( struct V_204 ) ;
}
F_71 ( V_236 , V_219 ) ;
}
F_71 ( V_207 , V_238 ) ;
V_240 ++ ;
return 0 ;
V_239:
V_215 ++ ;
F_71 ( V_236 , V_219 ) ;
F_71 ( V_207 , V_238 ) ;
return V_105 ;
}
static unsigned int F_85 ( T_1 V_29 , unsigned int * V_30 )
{
unsigned int V_241 , V_242 , V_243 ;
T_1 V_196 , V_244 , V_245 ;
V_241 = V_98 ;
V_242 = V_241 - V_97 ;
V_196 = V_29 + V_242 ;
F_60 ( V_196 , V_241 ) ;
V_243 = F_86 ( V_196 , V_246 ) ;
if ( V_243 )
V_244 = F_87 ( V_246 , V_247 , V_196 ) ;
else
V_244 = F_88 ( V_246 , V_247 , V_196 ) ;
V_245 = V_244 * V_241 - V_97 ;
* V_30 = V_245 - V_29 ;
return V_243 ;
}
static void F_89 ( T_1 V_29 , unsigned int V_116 )
{
unsigned int V_241 , V_242 ;
T_1 V_245 = V_29 + V_116 ;
V_241 = V_98 ;
V_242 = V_241 - V_97 ;
while ( V_29 < V_245 ) {
T_1 V_196 , V_248 ;
V_196 = V_29 + V_242 ;
V_248 = F_60 ( V_196 , V_241 ) ;
if ( V_196 < V_247 )
F_90 ( V_196 , V_246 ) ;
V_29 += V_241 - V_248 ;
}
}
static void F_91 ( T_1 V_29 , unsigned int V_116 )
{
unsigned int V_241 , V_242 ;
T_1 V_245 = V_29 + V_116 ;
V_241 = V_98 ;
V_242 = V_241 - V_97 ;
while ( V_29 < V_245 ) {
T_1 V_196 , V_248 ;
V_196 = V_29 + V_242 ;
V_248 = F_60 ( V_196 , V_241 ) ;
if ( V_248 == 0 && V_29 + V_241 <= V_245 &&
V_196 < V_247 )
F_92 ( V_196 , V_246 ) ;
V_29 += V_241 - V_248 ;
}
}
static int F_93 ( struct V_49 * V_50 , unsigned long long V_29 ,
unsigned int V_30 , struct V_16 * V_17 ,
T_2 V_31 )
{
unsigned long V_221 ;
int V_105 ;
V_105 = F_57 ( V_17 , V_29 , V_30 ) ;
if ( V_105 )
return V_105 ;
if ( V_227 && F_74 ( V_50 ) ) {
int V_228 = F_78 ( V_50 , V_29 , V_30 , V_31 ) ;
if ( V_228 ) {
F_7 ( V_17 , V_113 , 0x10 , V_228 ) ;
return V_230 ;
}
}
F_94 ( & V_231 , V_221 ) ;
V_105 = F_58 ( V_50 , V_17 , V_29 , V_30 , 1 ) ;
if ( V_98 )
F_89 ( V_29 , V_30 ) ;
F_95 ( & V_231 , V_221 ) ;
if ( - 1 == V_105 )
return ( V_68 << 16 ) ;
else if ( ( V_105 < ( V_30 * V_134 ) ) &&
( V_25 & V_26 ) )
F_9 ( V_27 L_25
L_14 , V_30 * V_134 , V_105 ) ;
return 0 ;
}
static int F_96 ( struct V_49 * V_194 , unsigned long long V_29 ,
unsigned int V_30 , struct V_16 * V_17 ,
T_2 V_31 , unsigned int V_249 )
{
unsigned long V_221 ;
unsigned long long V_201 ;
int V_105 ;
V_105 = F_57 ( V_17 , V_29 , V_30 ) ;
if ( V_105 )
return V_105 ;
if ( V_30 > V_99 ) {
F_7 ( V_17 , V_113 , V_114 ,
0 ) ;
return V_55 ;
}
F_94 ( & V_231 , V_221 ) ;
if ( V_249 && V_98 ) {
F_91 ( V_29 , V_30 ) ;
goto V_239;
}
V_105 = F_18 ( V_194 ,
V_198 + ( V_29 * V_134 ) ,
V_134 ) ;
if ( - 1 == V_105 ) {
F_95 ( & V_231 , V_221 ) ;
return ( V_68 << 16 ) ;
} else if ( ( V_105 < ( V_30 * V_134 ) ) &&
( V_25 & V_26 ) )
F_9 ( V_27 L_26
L_14 , V_30 * V_134 , V_105 ) ;
for ( V_201 = 1 ; V_201 < V_30 ; V_201 ++ )
memcpy ( V_198 + ( ( V_29 + V_201 ) * V_134 ) ,
V_198 + ( V_29 * V_134 ) ,
V_134 ) ;
if ( V_98 )
F_89 ( V_29 , V_30 ) ;
V_239:
F_95 ( & V_231 , V_221 ) ;
return 0 ;
}
static int F_97 ( struct V_49 * V_194 , struct V_16 * V_17 )
{
unsigned char * V_232 ;
struct V_250 * V_251 ;
unsigned int V_201 , V_252 , V_253 ;
int V_105 ;
V_105 = F_12 ( V_194 , 1 , V_17 ) ;
if ( V_105 )
return V_105 ;
V_252 = F_98 ( & V_194 -> V_102 [ 7 ] ) ;
F_81 ( F_17 ( V_194 ) != V_252 ) ;
V_253 = ( V_252 - 8 ) / 16 ;
V_232 = F_99 ( F_17 ( V_194 ) , V_107 ) ;
if ( ! V_232 )
return V_55 ;
F_19 ( V_194 , V_232 , F_17 ( V_194 ) ) ;
F_81 ( F_98 ( & V_232 [ 0 ] ) != V_252 - 2 ) ;
F_81 ( F_98 ( & V_232 [ 2 ] ) != V_253 * 16 ) ;
V_251 = ( void * ) & V_232 [ 8 ] ;
for ( V_201 = 0 ; V_201 < V_253 ; V_201 ++ ) {
unsigned long long V_29 = F_100 ( & V_251 [ V_201 ] . V_29 ) ;
unsigned int V_30 = F_101 ( & V_251 [ V_201 ] . V_254 ) ;
V_105 = F_57 ( V_17 , V_29 , V_30 ) ;
if ( V_105 )
goto V_239;
F_91 ( V_29 , V_30 ) ;
}
V_105 = 0 ;
V_239:
F_32 ( V_232 ) ;
return V_105 ;
}
static int F_102 ( struct V_49 * V_194 ,
struct V_16 * V_17 )
{
unsigned long long V_29 ;
unsigned int V_103 , V_243 , V_30 ;
unsigned char V_60 [ V_255 ] ;
int V_105 ;
V_105 = F_12 ( V_194 , 1 , V_17 ) ;
if ( V_105 )
return V_105 ;
V_29 = F_100 ( & V_194 -> V_102 [ 2 ] ) ;
V_103 = F_101 ( & V_194 -> V_102 [ 10 ] ) ;
if ( V_103 < 24 )
return 0 ;
V_105 = F_57 ( V_17 , V_29 , 1 ) ;
if ( V_105 )
return V_105 ;
V_243 = F_85 ( V_29 , & V_30 ) ;
memset ( V_60 , 0 , V_255 ) ;
F_26 ( 16 , & V_60 [ 0 ] ) ;
F_27 ( V_29 , & V_60 [ 8 ] ) ;
F_26 ( V_30 , & V_60 [ 16 ] ) ;
V_60 [ 20 ] = ! V_243 ;
return F_13 ( V_194 , V_60 , V_255 ) ;
}
static int F_103 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned int V_103 ;
int V_256 , V_201 , V_257 , V_30 , V_104 , V_109 , V_111 ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_102 ;
int V_258 = ( int ) V_28 [ 2 ] ;
struct V_259 * V_260 ;
unsigned char V_60 [ V_261 ] ;
unsigned char * V_262 ;
V_103 = V_28 [ 9 ] + ( V_28 [ 8 ] << 8 ) + ( V_28 [ 7 ] << 16 ) + ( V_28 [ 6 ] << 24 ) ;
if ( ( V_103 < 4 ) || ( V_258 > 2 ) ) {
F_7 ( V_17 , V_113 , V_114 ,
0 ) ;
return V_55 ;
}
memset ( V_60 , 0 , V_261 ) ;
V_256 = V_263 ;
if ( 1 == V_258 )
V_256 = 0 ;
else if ( V_110 && ( V_256 > 0 ) )
-- V_256 ;
V_109 = ( V_258 > 0 ) ? 1 : 0 ;
V_30 = V_256 + V_109 ;
V_60 [ 2 ] = ( ( sizeof( struct V_259 ) * V_30 ) >> 8 ) & 0xff ;
V_60 [ 3 ] = ( sizeof( struct V_259 ) * V_30 ) & 0xff ;
V_104 = F_34 ( ( int ) ( ( V_261 - 8 ) /
sizeof( struct V_259 ) ) , V_30 ) ;
if ( V_104 < V_30 ) {
V_109 = 0 ;
V_256 = V_104 ;
}
V_260 = (struct V_259 * ) & V_60 [ 8 ] ;
V_262 = V_60 + V_261 ;
for ( V_201 = 0 , V_111 = ( V_110 ? 1 : 0 ) ;
( ( V_201 < V_256 ) && ( ( unsigned char * ) ( V_260 + V_201 ) < V_262 ) ) ;
V_201 ++ , V_111 ++ ) {
V_257 = ( V_111 >> 8 ) & 0x3f ;
if ( V_257 )
V_260 [ V_201 ] . V_259 [ 0 ] =
( V_257 | ( V_264 << 6 ) ) ;
V_260 [ V_201 ] . V_259 [ 1 ] = V_111 & 0xff ;
}
if ( V_109 ) {
V_260 [ V_201 ] . V_259 [ 0 ] = ( V_15 >> 8 ) & 0xff ;
V_260 [ V_201 ] . V_259 [ 1 ] = V_15 & 0xff ;
V_201 ++ ;
}
V_103 = ( unsigned char * ) ( V_260 + V_201 ) - V_60 ;
return F_13 ( V_59 , V_60 ,
F_34 ( ( int ) V_103 , V_261 ) ) ;
}
static int F_104 ( struct V_49 * V_59 , unsigned long long V_29 ,
unsigned int V_30 , struct V_16 * V_17 )
{
int V_201 , V_233 , V_105 = - 1 ;
unsigned char * V_265 , * V_232 ;
unsigned int V_169 ;
struct V_202 * V_266 ;
struct V_63 * V_64 = F_14 ( V_59 ) ;
V_232 = F_99 ( F_17 ( V_59 ) , V_107 ) ;
if ( ! V_232 )
return V_105 ;
F_19 ( V_59 , V_232 , F_17 ( V_59 ) ) ;
V_169 = 0 ;
F_105 (sdb->table.sgl, sg, sdb->table.nents, i) {
V_265 = ( unsigned char * ) F_69 ( F_70 ( V_266 ) , V_267 ) ;
if ( ! V_265 )
goto V_239;
for ( V_233 = 0 ; V_233 < V_266 -> V_65 ; V_233 ++ )
* ( V_265 + V_266 -> V_169 + V_233 ) ^= * ( V_232 + V_169 + V_233 ) ;
V_169 += V_266 -> V_65 ;
F_71 ( V_265 , V_267 ) ;
}
V_105 = 0 ;
V_239:
F_32 ( V_232 ) ;
return V_105 ;
}
static void F_106 ( unsigned long V_268 )
{
struct V_269 * V_270 ;
unsigned long V_221 ;
if ( V_268 >= V_271 ) {
F_9 ( V_213 L_27
L_28 ) ;
return;
}
F_107 ( & V_272 , V_221 ) ;
V_270 = & V_273 [ ( int ) V_268 ] ;
if ( ! V_270 -> V_274 ) {
F_9 ( V_213 L_29
L_30 ) ;
F_108 ( & V_272 , V_221 ) ;
return;
}
V_270 -> V_274 = 0 ;
if ( V_270 -> V_275 ) {
V_270 -> V_276 -> V_277 = V_270 -> V_278 ;
V_270 -> V_275 ( V_270 -> V_276 ) ;
}
V_270 -> V_275 = NULL ;
F_108 ( & V_272 , V_221 ) ;
}
static struct V_16 *
F_109 ( struct V_5 * V_6 , T_5 V_279 )
{
struct V_16 * V_17 ;
V_17 = F_31 ( sizeof( * V_17 ) , V_279 ) ;
if ( V_17 ) {
V_17 -> V_6 = V_6 ;
F_110 ( & V_17 -> V_280 , & V_6 -> V_281 ) ;
}
return V_17 ;
}
static struct V_16 * F_111 ( struct V_45 * V_282 )
{
struct V_5 * V_6 ;
struct V_16 * V_283 = NULL ;
struct V_16 * V_17 =
(struct V_16 * ) V_282 -> V_284 ;
if ( V_17 )
return V_17 ;
V_6 = * (struct V_5 * * ) F_112 ( V_282 -> V_285 ) ;
if ( ! V_6 ) {
F_9 ( V_213 L_31 ) ;
return NULL ;
}
F_5 (devip, &sdbg_host->dev_info_list, dev_list) {
if ( ( V_17 -> V_286 ) && ( V_17 -> V_119 == V_282 -> V_119 ) &&
( V_17 -> V_100 == V_282 -> V_287 ) &&
( V_17 -> V_111 == V_282 -> V_111 ) )
return V_17 ;
else {
if ( ( ! V_17 -> V_286 ) && ( ! V_283 ) )
V_283 = V_17 ;
}
}
if ( ! V_283 ) {
V_283 = F_109 ( V_6 , V_107 ) ;
if ( ! V_283 ) {
F_9 ( V_213 L_32 ,
V_214 , __LINE__ ) ;
return NULL ;
}
}
V_283 -> V_119 = V_282 -> V_119 ;
V_283 -> V_100 = V_282 -> V_287 ;
V_283 -> V_111 = V_282 -> V_111 ;
V_283 -> V_6 = V_6 ;
V_283 -> V_52 = 1 ;
V_283 -> V_286 = 1 ;
memset ( V_283 -> V_22 , 0 , V_23 ) ;
if ( V_24 )
V_283 -> V_22 [ 0 ] = 0x72 ;
else {
V_283 -> V_22 [ 0 ] = 0x70 ;
V_283 -> V_22 [ 7 ] = 0xa ;
}
if ( V_282 -> V_111 == V_15 )
V_283 -> V_109 = V_15 & 0xff ;
return V_283 ;
}
static int F_113 ( struct V_45 * V_288 )
{
if ( V_25 & V_26 )
F_9 ( V_27 L_33 ,
V_288 -> V_285 -> V_118 , V_288 -> V_119 , V_288 -> V_287 , V_288 -> V_111 ) ;
F_114 ( V_289 , V_288 -> V_290 ) ;
return 0 ;
}
static int F_115 ( struct V_45 * V_288 )
{
struct V_16 * V_17 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_34 ,
V_288 -> V_285 -> V_118 , V_288 -> V_119 , V_288 -> V_287 , V_288 -> V_111 ) ;
if ( V_288 -> V_285 -> V_291 != V_292 )
V_288 -> V_285 -> V_291 = V_292 ;
V_17 = F_111 ( V_288 ) ;
if ( NULL == V_17 )
return 1 ;
V_288 -> V_284 = V_17 ;
if ( V_288 -> V_285 -> V_293 )
F_116 ( V_288 , V_294 ,
V_288 -> V_285 -> V_293 ) ;
F_117 ( V_288 -> V_290 , 256 * 1024 ) ;
if ( V_295 )
V_288 -> V_296 = 1 ;
return 0 ;
}
static void F_118 ( struct V_45 * V_288 )
{
struct V_16 * V_17 =
(struct V_16 * ) V_288 -> V_284 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_35 ,
V_288 -> V_285 -> V_118 , V_288 -> V_119 , V_288 -> V_287 , V_288 -> V_111 ) ;
if ( V_17 ) {
V_17 -> V_286 = 0 ;
V_288 -> V_284 = NULL ;
}
}
static int F_119 ( struct V_49 * V_102 )
{
unsigned long V_221 ;
int V_139 ;
struct V_269 * V_270 ;
F_107 ( & V_272 , V_221 ) ;
for ( V_139 = 0 ; V_139 < V_271 ; ++ V_139 ) {
V_270 = & V_273 [ V_139 ] ;
if ( V_270 -> V_274 && ( V_102 == V_270 -> V_276 ) ) {
F_120 ( & V_270 -> V_297 ) ;
V_270 -> V_274 = 0 ;
V_270 -> V_276 = NULL ;
break;
}
}
F_108 ( & V_272 , V_221 ) ;
return ( V_139 < V_271 ) ? 1 : 0 ;
}
static void F_121 ( void )
{
unsigned long V_221 ;
int V_139 ;
struct V_269 * V_270 ;
F_107 ( & V_272 , V_221 ) ;
for ( V_139 = 0 ; V_139 < V_271 ; ++ V_139 ) {
V_270 = & V_273 [ V_139 ] ;
if ( V_270 -> V_274 && V_270 -> V_276 ) {
F_120 ( & V_270 -> V_297 ) ;
V_270 -> V_274 = 0 ;
V_270 -> V_276 = NULL ;
}
}
F_108 ( & V_272 , V_221 ) ;
}
static int F_122 ( struct V_49 * V_50 )
{
if ( V_25 & V_26 )
F_9 ( V_27 L_36 ) ;
++ V_298 ;
F_119 ( V_50 ) ;
return V_299 ;
}
static int F_123 ( struct V_45 * V_282 ,
struct V_300 * V_301 , T_1 V_302 , int * V_303 )
{
int V_183 ;
unsigned char * V_232 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_37 ) ;
V_232 = F_124 ( V_301 ) ;
if ( V_232 ) {
V_183 = F_125 ( V_232 , V_302 ,
& V_303 [ 2 ] , & V_303 [ 0 ] , & V_303 [ 1 ] ) ;
F_32 ( V_232 ) ;
if ( ! V_183 )
return V_183 ;
}
V_303 [ 0 ] = V_304 ;
V_303 [ 1 ] = V_151 ;
V_303 [ 2 ] = V_305 ;
return 0 ;
}
static int F_126 ( struct V_49 * V_50 )
{
struct V_16 * V_17 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_38 ) ;
++ V_306 ;
if ( V_50 ) {
V_17 = F_111 ( V_50 -> V_307 ) ;
if ( V_17 )
V_17 -> V_52 = 1 ;
}
return V_299 ;
}
static int F_127 ( struct V_49 * V_50 )
{
struct V_5 * V_6 ;
struct V_16 * V_308 ;
struct V_45 * V_288 ;
struct V_7 * V_309 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_39 ) ;
++ V_310 ;
if ( V_50 && ( ( V_288 = V_50 -> V_307 ) ) && ( ( V_309 = V_288 -> V_285 ) ) ) {
V_6 = * (struct V_5 * * ) F_112 ( V_309 ) ;
if ( V_6 ) {
F_5 (dev_info,
&sdbg_host->dev_info_list,
dev_list)
V_308 -> V_52 = 1 ;
}
}
return V_299 ;
}
static int F_128 ( struct V_49 * V_50 )
{
struct V_5 * V_6 ;
struct V_16 * V_308 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_40 ) ;
++ V_311 ;
F_4 ( & V_9 ) ;
F_5 (sdbg_host, &sdebug_host_list, host_list) {
F_5 (dev_info, &sdbg_host->dev_info_list,
dev_list)
V_308 -> V_52 = 1 ;
}
F_6 ( & V_9 ) ;
F_121 () ;
return V_299 ;
}
static void T_6 F_129 ( void )
{
unsigned long V_221 ;
int V_139 ;
struct V_269 * V_270 ;
F_107 ( & V_272 , V_221 ) ;
for ( V_139 = 0 ; V_139 < V_271 ; ++ V_139 ) {
V_270 = & V_273 [ V_139 ] ;
F_130 ( & V_270 -> V_297 ) ;
V_270 -> V_274 = 0 ;
V_270 -> V_276 = NULL ;
}
F_108 ( & V_272 , V_221 ) ;
}
static void T_6 F_131 ( unsigned char * V_312 ,
unsigned long V_313 )
{
struct V_314 * V_315 ;
int V_316 [ V_317 + 2 ] ;
int V_318 , V_319 , V_139 ;
int V_320 , V_199 , V_321 ;
if ( ( V_322 < 1 ) || ( V_313 < 1048576 ) )
return;
if ( V_322 > V_317 ) {
V_322 = V_317 ;
F_9 ( V_323 L_41
L_42 , V_317 ) ;
}
V_319 = ( int ) V_93 ;
V_318 = ( V_319 - V_151 )
/ V_322 ;
V_320 = V_304 * V_151 ;
V_316 [ 0 ] = V_151 ;
for ( V_139 = 1 ; V_139 < V_322 ; ++ V_139 )
V_316 [ V_139 ] = ( ( V_139 * V_318 ) / V_320 )
* V_320 ;
V_316 [ V_322 ] = V_319 ;
V_316 [ V_322 + 1 ] = 0 ;
V_312 [ 510 ] = 0x55 ;
V_312 [ 511 ] = 0xAA ;
V_315 = (struct V_314 * ) ( V_312 + 0x1be ) ;
for ( V_139 = 0 ; V_316 [ V_139 + 1 ] ; ++ V_139 , ++ V_315 ) {
V_199 = V_316 [ V_139 ] ;
V_321 = V_316 [ V_139 + 1 ] - 1 ;
V_315 -> V_324 = 0 ;
V_315 -> V_325 = V_199 / V_320 ;
V_315 -> V_326 = ( V_199 - ( V_315 -> V_325 * V_320 ) )
/ V_151 ;
V_315 -> V_4 = ( V_199 % V_151 ) + 1 ;
V_315 -> V_327 = V_321 / V_320 ;
V_315 -> V_328 = ( V_321 - ( V_315 -> V_327 * V_320 ) )
/ V_151 ;
V_315 -> V_329 = ( V_321 % V_151 ) + 1 ;
V_315 -> V_330 = V_199 ;
V_315 -> V_331 = V_321 - V_199 + 1 ;
V_315 -> V_332 = 0x83 ;
}
}
static int F_132 ( struct V_49 * V_102 ,
struct V_16 * V_17 ,
T_7 V_333 , int V_278 , int V_334 )
{
if ( ( V_25 & V_26 ) && V_102 ) {
if ( V_278 ) {
struct V_45 * V_288 = V_102 -> V_307 ;
F_9 ( V_27 L_43
L_44 , V_288 -> V_285 -> V_118 ,
V_288 -> V_119 , V_288 -> V_287 , V_288 -> V_111 , V_278 ) ;
}
}
if ( V_102 && V_17 ) {
if ( V_335 == ( V_278 & 0xff ) )
memcpy ( V_102 -> V_336 , V_17 -> V_22 ,
( V_337 > V_23 ) ?
V_23 : V_337 ) ;
}
if ( V_334 <= 0 ) {
if ( V_102 )
V_102 -> V_277 = V_278 ;
if ( V_333 )
V_333 ( V_102 ) ;
return 0 ;
} else {
unsigned long V_221 ;
int V_139 ;
struct V_269 * V_270 = NULL ;
F_107 ( & V_272 , V_221 ) ;
for ( V_139 = 0 ; V_139 < V_271 ; ++ V_139 ) {
V_270 = & V_273 [ V_139 ] ;
if ( ! V_270 -> V_274 )
break;
}
if ( V_139 >= V_271 ) {
F_108 ( & V_272 , V_221 ) ;
F_9 ( V_323 L_45 ) ;
return 1 ;
}
V_270 -> V_274 = 1 ;
V_270 -> V_276 = V_102 ;
V_270 -> V_278 = V_278 ;
V_270 -> V_275 = V_333 ;
V_270 -> V_297 . V_338 = F_106 ;
V_270 -> V_297 . V_339 = V_139 ;
V_270 -> V_297 . V_340 = V_341 + V_334 ;
F_133 ( & V_270 -> V_297 ) ;
F_108 ( & V_272 , V_221 ) ;
if ( V_102 )
V_102 -> V_277 = 0 ;
return 0 ;
}
}
static const char * F_134 ( struct V_7 * V_342 )
{
sprintf ( V_343 , L_46
L_47 , V_344 ,
V_345 , V_346 ,
V_26 ) ;
return V_343 ;
}
static int F_135 ( struct V_7 * V_285 , char * V_347 , char * * V_132 , T_8 V_169 ,
int V_65 , int V_348 )
{
int V_116 , V_349 , V_350 ;
int V_351 ;
V_351 = V_65 ;
if ( V_348 == 1 ) {
char V_60 [ 16 ] ;
int V_352 = V_65 > 15 ? 15 : V_65 ;
if ( ! F_136 ( V_353 ) || ! F_136 ( V_354 ) )
return - V_355 ;
memcpy ( V_60 , V_347 , V_352 ) ;
V_60 [ V_352 ] = '\0' ;
if ( 1 != sscanf ( V_60 , L_12 , & V_349 ) )
return - V_48 ;
V_26 = V_349 ;
if ( V_356 != 0 )
V_357 = 0 ;
return V_65 ;
}
V_350 = 0 ;
V_349 = V_116 = sprintf ( V_347 , L_48
L_49
L_50
L_51
L_52
L_53
L_54
L_55 ,
V_344 , V_345 , V_12 ,
V_346 , V_26 , V_356 ,
V_357 , V_358 ,
V_263 , V_123 ,
V_134 , V_305 , V_304 ,
V_151 , V_298 , V_306 , V_310 ,
V_311 , V_220 , V_240 , V_215 ) ;
if ( V_349 < V_169 ) {
V_116 = 0 ;
V_350 = V_349 ;
}
* V_132 = V_347 + ( V_169 - V_350 ) ;
V_116 -= ( V_169 - V_350 ) ;
if ( V_116 > V_65 )
V_116 = V_65 ;
return V_116 ;
}
static T_9 F_137 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_358 ) ;
}
static T_9 F_138 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_363 ;
char V_364 [ 20 ] ;
if ( 1 == sscanf ( V_232 , L_57 , V_364 ) ) {
if ( ( 1 == sscanf ( V_364 , L_12 , & V_363 ) ) && ( V_363 >= 0 ) ) {
V_358 = V_363 ;
return V_362 ;
}
}
return - V_48 ;
}
static T_9 F_139 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_58 , V_26 ) ;
}
static T_9 F_140 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_365 ;
char V_364 [ 20 ] ;
if ( 1 == sscanf ( V_232 , L_57 , V_364 ) ) {
if ( 0 == F_141 ( V_364 , L_59 , 2 ) ) {
if ( 1 == sscanf ( & V_364 [ 2 ] , L_60 , & V_365 ) )
goto V_366;
} else {
if ( 1 == sscanf ( V_364 , L_12 , & V_365 ) )
goto V_366;
}
}
return - V_48 ;
V_366:
V_26 = V_365 ;
V_357 = 0 ;
return V_362 ;
}
static T_9 F_142 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_112 ) ;
}
static T_9 F_143 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_112 = V_104 ;
return V_362 ;
}
return - V_48 ;
}
static T_9 F_144 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_24 ) ;
}
static T_9 F_145 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_24 = V_104 ;
return V_362 ;
}
return - V_48 ;
}
static T_9 F_146 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_367 ) ;
}
static T_9 F_147 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_367 = V_104 ;
return V_362 ;
}
return - V_48 ;
}
static T_9 F_148 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_110 ) ;
}
static T_9 F_149 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_110 = V_104 ;
return V_362 ;
}
return - V_48 ;
}
static T_9 F_150 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_12 ) ;
}
static T_9 F_151 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_12 = V_104 ;
F_3 () ;
return V_362 ;
}
return - V_48 ;
}
static T_9 F_152 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_346 ) ;
}
static T_9 F_153 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_322 ) ;
}
static T_9 F_154 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_356 ) ;
}
static T_9 F_155 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_368 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_368 ) ) ) {
V_356 = V_368 ;
V_357 = 0 ;
return V_362 ;
}
return - V_48 ;
}
static T_9 F_156 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_263 ) ;
}
static T_9 F_157 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_263 = V_104 ;
F_3 () ;
return V_362 ;
}
return - V_48 ;
}
static T_9 F_158 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_271 ) ;
}
static T_9 F_159 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_104 ) ) && ( V_104 > 0 ) &&
( V_104 <= V_369 ) ) {
V_271 = V_104 ;
return V_362 ;
}
return - V_48 ;
}
static T_9 F_160 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_295 ) ;
}
static T_9 F_161 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_123 ) ;
}
static T_9 F_162 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_133 ) ;
}
static T_9 F_163 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_133 = V_104 ;
V_137 = F_38 () ;
return V_362 ;
}
return - V_48 ;
}
static T_9 F_164 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_370 ) ;
}
static T_9 F_165 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_371 ;
if ( sscanf ( V_232 , L_12 , & V_371 ) != 1 )
return - V_48 ;
if ( V_371 > 0 ) {
do {
F_166 () ;
} while ( -- V_371 );
} else if ( V_371 < 0 ) {
do {
F_167 () ;
} while ( ++ V_371 );
}
return V_362 ;
}
static T_9 F_168 ( struct V_359 * V_360 ,
char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_120 ) ;
}
static T_9 F_169 ( struct V_359 * V_360 ,
const char * V_232 , T_10 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_120 = V_104 ;
return V_362 ;
}
return - V_48 ;
}
static T_9 F_170 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_61 , V_134 ) ;
}
static T_9 F_171 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_227 ) ;
}
static T_9 F_172 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_121 ) ;
}
static T_9 F_173 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_211 ) ;
}
static T_9 F_174 ( struct V_359 * V_360 , char * V_232 )
{
return F_33 ( V_232 , V_361 , L_56 , V_156 ) ;
}
static T_9 F_175 ( struct V_359 * V_360 , char * V_232 )
{
T_9 V_362 ;
if ( ! F_1 () )
return F_33 ( V_232 , V_361 , L_62 ,
V_93 ) ;
V_362 = F_176 ( V_232 , V_361 , V_246 , V_247 ) ;
V_232 [ V_362 ++ ] = '\n' ;
V_232 [ V_362 ++ ] = 0 ;
return V_362 ;
}
static int F_177 ( void )
{
int V_105 ;
V_105 = F_178 ( & V_372 , & V_373 ) ;
V_105 |= F_178 ( & V_372 , & V_374 ) ;
V_105 |= F_178 ( & V_372 , & V_375 ) ;
V_105 |= F_178 ( & V_372 , & V_376 ) ;
V_105 |= F_178 ( & V_372 , & V_377 ) ;
V_105 |= F_178 ( & V_372 , & V_378 ) ;
V_105 |= F_178 ( & V_372 , & V_379 ) ;
V_105 |= F_178 ( & V_372 , & V_380 ) ;
V_105 |= F_178 ( & V_372 , & V_381 ) ;
V_105 |= F_178 ( & V_372 , & V_382 ) ;
V_105 |= F_178 ( & V_372 , & V_383 ) ;
V_105 |= F_178 ( & V_372 , & V_384 ) ;
V_105 |= F_178 ( & V_372 , & V_385 ) ;
V_105 |= F_178 ( & V_372 , & V_386 ) ;
V_105 |= F_178 ( & V_372 , & V_387 ) ;
V_105 |= F_178 ( & V_372 , & V_388 ) ;
V_105 |= F_178 ( & V_372 , & V_389 ) ;
V_105 |= F_178 ( & V_372 , & V_390 ) ;
V_105 |= F_178 ( & V_372 , & V_391 ) ;
V_105 |= F_178 ( & V_372 , & V_392 ) ;
V_105 |= F_178 ( & V_372 , & V_393 ) ;
V_105 |= F_178 ( & V_372 , & V_394 ) ;
V_105 |= F_178 ( & V_372 , & V_395 ) ;
return V_105 ;
}
static void F_179 ( void )
{
F_180 ( & V_372 , & V_395 ) ;
F_180 ( & V_372 , & V_394 ) ;
F_180 ( & V_372 , & V_393 ) ;
F_180 ( & V_372 , & V_392 ) ;
F_180 ( & V_372 , & V_391 ) ;
F_180 ( & V_372 , & V_390 ) ;
F_180 ( & V_372 , & V_389 ) ;
F_180 ( & V_372 , & V_388 ) ;
F_180 ( & V_372 , & V_387 ) ;
F_180 ( & V_372 , & V_386 ) ;
F_180 ( & V_372 , & V_385 ) ;
F_180 ( & V_372 , & V_384 ) ;
F_180 ( & V_372 , & V_383 ) ;
F_180 ( & V_372 , & V_382 ) ;
F_180 ( & V_372 , & V_381 ) ;
F_180 ( & V_372 , & V_380 ) ;
F_180 ( & V_372 , & V_379 ) ;
F_180 ( & V_372 , & V_378 ) ;
F_180 ( & V_372 , & V_377 ) ;
F_180 ( & V_372 , & V_376 ) ;
F_180 ( & V_372 , & V_375 ) ;
F_180 ( & V_372 , & V_374 ) ;
F_180 ( & V_372 , & V_373 ) ;
}
static int T_6 F_181 ( void )
{
unsigned long V_396 ;
int V_397 ;
int V_139 ;
int V_105 ;
switch ( V_134 ) {
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_9 ( V_213 L_63 ,
V_134 ) ;
return - V_48 ;
}
switch ( V_121 ) {
case V_398 :
case V_216 :
case V_218 :
case V_122 :
break;
default:
F_9 ( V_213 L_64 ) ;
return - V_48 ;
}
if ( V_211 > 1 ) {
F_9 ( V_213 L_65 ) ;
return - V_48 ;
}
if ( V_156 > 1 ) {
F_9 ( V_213 L_66 ) ;
return - V_48 ;
}
if ( V_92 > 15 ) {
F_9 ( V_213 L_67 ,
V_92 ) ;
return - V_48 ;
}
if ( V_140 > 0x3fff ) {
F_9 ( V_213 L_68 ,
V_140 ) ;
return - V_48 ;
}
if ( V_346 < 1 )
V_346 = 1 ;
V_396 = ( unsigned long ) V_346 * 1048576 ;
V_93 = V_396 / V_134 ;
V_137 = F_38 () ;
V_304 = 8 ;
V_151 = 32 ;
if ( V_346 >= 16 )
V_304 = 32 ;
else if ( V_346 >= 256 )
V_304 = 64 ;
V_305 = ( unsigned long ) V_137 /
( V_151 * V_304 ) ;
if ( V_305 >= 1024 ) {
V_304 = 255 ;
V_151 = 63 ;
V_305 = ( unsigned long ) V_137 /
( V_151 * V_304 ) ;
}
V_198 = F_182 ( V_396 ) ;
if ( NULL == V_198 ) {
F_9 ( V_213 L_69 ) ;
return - V_399 ;
}
memset ( V_198 , 0 , V_396 ) ;
if ( V_322 > 0 )
F_131 ( V_198 , V_396 ) ;
if ( V_121 ) {
int V_400 ;
V_400 = V_93 * sizeof( struct V_204 ) ;
V_208 = F_182 ( V_400 ) ;
F_9 ( V_213 L_70 ,
V_400 , V_208 ) ;
if ( V_208 == NULL ) {
F_9 ( V_213 L_71 ) ;
V_105 = - V_399 ;
goto V_401;
}
memset ( V_208 , 0xff , V_400 ) ;
}
if ( F_1 () ) {
unsigned int V_402 ;
V_95 =
F_183 ( V_95 , 0U , 0xffffffffU ) ;
V_96 =
F_183 ( V_96 , 0U , 256U ) ;
V_98 =
F_183 ( V_98 , 1U , 0xffffffffU ) ;
if ( V_97 &&
V_98 < V_97 ) {
F_9 ( V_213
L_72 ,
V_214 ) ;
return - V_48 ;
}
V_247 = ( V_93 / V_98 ) ;
V_402 = V_247 >> 3 ;
V_246 = F_182 ( V_402 ) ;
F_9 ( V_27 L_73 ,
V_247 ) ;
if ( V_246 == NULL ) {
F_9 ( V_213 L_74 ) ;
V_105 = - V_399 ;
goto V_401;
}
memset ( V_246 , 0x0 , V_402 ) ;
if ( V_322 )
F_89 ( 0 , 2 ) ;
}
V_403 = F_184 ( L_75 ) ;
if ( F_185 ( V_403 ) ) {
F_9 ( V_323 L_76 ) ;
V_105 = F_186 ( V_403 ) ;
goto V_401;
}
V_105 = F_187 ( & V_404 ) ;
if ( V_105 < 0 ) {
F_9 ( V_323 L_77 ,
V_105 ) ;
goto V_405;
}
V_105 = F_188 ( & V_372 ) ;
if ( V_105 < 0 ) {
F_9 ( V_323 L_78 ,
V_105 ) ;
goto V_406;
}
V_105 = F_177 () ;
if ( V_105 < 0 ) {
F_9 ( V_323 L_79 ,
V_105 ) ;
goto V_407;
}
F_129 () ;
V_397 = V_370 ;
V_370 = 0 ;
for ( V_139 = 0 ; V_139 < V_397 ; V_139 ++ ) {
if ( F_166 () ) {
F_9 ( V_213 L_80
L_81 , V_139 ) ;
break;
}
}
if ( V_25 & V_26 ) {
F_9 ( V_27 L_82 ,
V_370 ) ;
}
return 0 ;
V_407:
F_179 () ;
F_189 ( & V_372 ) ;
V_406:
F_190 ( & V_404 ) ;
V_405:
F_191 ( V_403 ) ;
V_401:
if ( V_246 )
F_192 ( V_246 ) ;
if ( V_208 )
F_192 ( V_208 ) ;
F_192 ( V_198 ) ;
return V_105 ;
}
static void T_11 F_193 ( void )
{
int V_139 = V_370 ;
F_121 () ;
for (; V_139 ; V_139 -- )
F_167 () ;
F_179 () ;
F_189 ( & V_372 ) ;
F_190 ( & V_404 ) ;
F_191 ( V_403 ) ;
if ( V_208 )
F_192 ( V_208 ) ;
F_192 ( V_198 ) ;
}
static void F_194 ( struct V_307 * V_46 )
{
struct V_5 * V_6 ;
V_6 = F_195 ( V_46 ) ;
F_32 ( V_6 ) ;
}
static int F_166 ( void )
{
int V_139 , V_408 ;
int error = 0 ;
struct V_5 * V_6 ;
struct V_16 * V_409 , * V_410 ;
V_6 = F_31 ( sizeof( * V_6 ) , V_411 ) ;
if ( NULL == V_6 ) {
F_9 ( V_213 L_32 ,
V_214 , __LINE__ ) ;
return - V_399 ;
}
F_196 ( & V_6 -> V_281 ) ;
V_408 = V_12 * V_263 ;
for ( V_139 = 0 ; V_139 < V_408 ; V_139 ++ ) {
V_409 = F_109 ( V_6 , V_411 ) ;
if ( ! V_409 ) {
F_9 ( V_213 L_32 ,
V_214 , __LINE__ ) ;
error = - V_399 ;
goto V_412;
}
}
F_4 ( & V_9 ) ;
F_110 ( & V_6 -> V_413 , & V_414 ) ;
F_6 ( & V_9 ) ;
V_6 -> V_46 . V_415 = & V_404 ;
V_6 -> V_46 . V_416 = V_403 ;
V_6 -> V_46 . V_417 = & F_194 ;
F_197 ( & V_6 -> V_46 , L_83 , V_370 ) ;
error = F_198 ( & V_6 -> V_46 ) ;
if ( error )
goto V_412;
++ V_370 ;
return error ;
V_412:
F_199 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_200 ( & V_409 -> V_280 ) ;
F_32 ( V_409 ) ;
}
F_32 ( V_6 ) ;
return error ;
}
static void F_167 ( void )
{
struct V_5 * V_6 = NULL ;
F_4 ( & V_9 ) ;
if ( ! F_201 ( & V_414 ) ) {
V_6 = F_202 ( V_414 . V_418 ,
struct V_5 , V_413 ) ;
F_200 ( & V_6 -> V_413 ) ;
}
F_6 ( & V_9 ) ;
if ( ! V_6 )
return;
F_203 ( & V_6 -> V_46 ) ;
-- V_370 ;
}
static
int F_204 ( struct V_49 * V_50 , T_7 V_333 )
{
unsigned char * V_28 = ( unsigned char * ) V_50 -> V_102 ;
int V_116 , V_139 ;
unsigned int V_30 ;
unsigned long long V_29 ;
T_2 V_31 ;
int V_131 = 0 ;
int V_100 = V_50 -> V_307 -> V_287 ;
struct V_16 * V_17 = NULL ;
int V_419 = 0 ;
int V_420 = 0 ;
int V_421 = 0 ;
int V_422 = 0 ;
int V_423 = 0 ;
int V_249 = 0 ;
F_73 ( V_50 , 0 ) ;
if ( ( V_25 & V_26 ) && V_28 ) {
F_9 ( V_27 L_84 ) ;
for ( V_139 = 0 , V_116 = V_50 -> V_424 ; V_139 < V_116 ; ++ V_139 )
F_9 ( L_21 , ( int ) V_28 [ V_139 ] ) ;
F_9 ( L_22 ) ;
}
if ( V_100 == V_50 -> V_307 -> V_285 -> V_425 -> V_11 ) {
F_9 ( V_27 L_85
L_86 ) ;
return F_132 ( V_50 , NULL , V_333 ,
V_426 << 16 , 0 ) ;
}
if ( ( V_50 -> V_307 -> V_111 >= V_263 ) &&
( V_50 -> V_307 -> V_111 != V_15 ) )
return F_132 ( V_50 , NULL , V_333 ,
V_426 << 16 , 0 ) ;
V_17 = F_111 ( V_50 -> V_307 ) ;
if ( NULL == V_17 )
return F_132 ( V_50 , NULL , V_333 ,
V_426 << 16 , 0 ) ;
if ( ( V_356 != 0 ) &&
( ++ V_357 >= abs ( V_356 ) ) ) {
V_357 = 0 ;
if ( V_356 < - 1 )
V_356 = - 1 ;
if ( V_427 & V_26 )
return 0 ;
else if ( V_428 & V_26 )
V_419 = 1 ;
else if ( V_429 & V_26 )
V_420 = 1 ;
else if ( V_430 & V_26 )
V_421 = 1 ;
else if ( V_431 & V_26 )
V_422 = 1 ;
}
if ( V_17 -> V_109 ) {
switch ( * V_28 ) {
case V_432 :
case V_433 :
case V_434 :
case V_435 :
break;
default:
if ( V_25 & V_26 )
F_9 ( V_27 L_87
L_88 , * V_28 ) ;
F_7 ( V_17 , V_113 ,
V_436 , 0 ) ;
V_131 = V_55 ;
return F_132 ( V_50 , V_17 , V_333 , V_131 ,
0 ) ;
}
}
switch ( * V_28 ) {
case V_432 :
V_423 = 1 ;
V_131 = F_30 ( V_50 , V_100 , V_17 ) ;
break;
case V_433 :
V_423 = 1 ;
V_131 = F_36 ( V_50 , V_17 ) ;
break;
case V_437 :
case V_438 :
V_131 = F_37 ( V_50 , V_17 ) ;
break;
case V_439 :
V_131 = F_12 ( V_50 , 1 , V_17 ) ;
if ( V_131 )
break;
if ( V_25 & V_26 )
F_9 ( V_27 L_89 ,
V_28 [ 4 ] ? L_90 : L_91 ) ;
break;
case V_440 :
V_131 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_434 :
V_423 = 1 ;
V_131 = F_12 ( V_50 , 0 , V_17 ) ;
break;
case V_441 :
V_131 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_442 :
V_131 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_443 :
V_131 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_444 :
V_131 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_445 :
V_131 = F_39 ( V_50 , V_17 ) ;
break;
case V_446 :
if ( V_28 [ 1 ] == V_447 )
V_131 = F_40 ( V_50 , V_17 ) ;
else if ( V_28 [ 1 ] == V_448 ) {
if ( F_1 () == 0 ) {
F_7 ( V_17 , V_113 ,
V_449 , 0 ) ;
V_131 = V_55 ;
} else
V_131 = F_102 ( V_50 , V_17 ) ;
} else {
F_7 ( V_17 , V_113 ,
V_436 , 0 ) ;
V_131 = V_55 ;
}
break;
case V_450 :
if ( V_451 != V_28 [ 1 ] ) {
F_7 ( V_17 , V_113 ,
V_436 , 0 ) ;
V_131 = V_55 ;
break;
}
V_131 = F_41 ( V_50 , V_17 ) ;
break;
case V_36 :
case V_38 :
case V_41 :
if ( V_121 == V_218 &&
V_28 [ 1 ] & 0xe0 ) {
F_7 ( V_17 , V_113 ,
V_449 , 0 ) ;
V_131 = V_55 ;
break;
}
if ( ( V_121 == V_216 ||
V_121 == V_122 ) &&
( V_28 [ 1 ] & 0xe0 ) == 0 )
F_9 ( V_213 L_92 ) ;
case V_44 :
V_452:
V_131 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_131 )
break;
if ( V_367 )
break;
F_10 ( V_28 , & V_29 , & V_30 , & V_31 ) ;
V_131 = F_72 ( V_50 , V_29 , V_30 , V_17 , V_31 ) ;
if ( V_419 && ( 0 == V_131 ) ) {
F_7 ( V_17 , V_453 ,
V_129 , 0 ) ;
V_131 = V_55 ;
} else if ( V_420 && ( 0 == V_131 ) ) {
F_7 ( V_17 , V_229 ,
V_454 , V_455 ) ;
V_131 = V_55 ;
} else if ( V_421 && ( 0 == V_131 ) ) {
F_7 ( V_17 , V_229 , 0x10 , 1 ) ;
V_131 = V_230 ;
} else if ( V_422 && ( 0 == V_131 ) ) {
F_7 ( V_17 , V_113 , 0x10 , 1 ) ;
V_131 = V_230 ;
}
break;
case V_435 :
V_423 = 1 ;
V_131 = F_103 ( V_50 , V_17 ) ;
break;
case V_456 :
V_131 = F_12 ( V_50 , 0 , V_17 ) ;
break;
case V_35 :
case V_37 :
case V_40 :
if ( V_121 == V_218 &&
V_28 [ 1 ] & 0xe0 ) {
F_7 ( V_17 , V_113 ,
V_449 , 0 ) ;
V_131 = V_55 ;
break;
}
if ( ( V_121 == V_216 ||
V_121 == V_122 ) &&
( V_28 [ 1 ] & 0xe0 ) == 0 )
F_9 ( V_213 L_92 ) ;
case V_43 :
V_195:
V_131 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_131 )
break;
if ( V_367 )
break;
F_10 ( V_28 , & V_29 , & V_30 , & V_31 ) ;
V_131 = F_93 ( V_50 , V_29 , V_30 , V_17 , V_31 ) ;
if ( V_419 && ( 0 == V_131 ) ) {
F_7 ( V_17 , V_453 ,
V_129 , 0 ) ;
V_131 = V_55 ;
} else if ( V_421 && ( 0 == V_131 ) ) {
F_7 ( V_17 , V_229 , 0x10 , 1 ) ;
V_131 = V_230 ;
} else if ( V_422 && ( 0 == V_131 ) ) {
F_7 ( V_17 , V_113 , 0x10 , 1 ) ;
V_131 = V_230 ;
}
break;
case V_34 :
case V_39 :
if ( V_28 [ 1 ] & 0x8 ) {
if ( ( * V_28 == V_34 && V_2 == 0 ) ||
( * V_28 == V_39 && V_3 == 0 ) ) {
F_7 ( V_17 , V_113 ,
V_114 , 0 ) ;
V_131 = V_55 ;
} else
V_249 = 1 ;
}
if ( V_131 )
break;
V_131 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_131 )
break;
F_10 ( V_28 , & V_29 , & V_30 , & V_31 ) ;
V_131 = F_96 ( V_50 , V_29 , V_30 , V_17 , V_31 , V_249 ) ;
break;
case V_457 :
V_131 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_131 )
break;
if ( V_96 == 0 || V_1 == 0 ) {
F_7 ( V_17 , V_113 ,
V_449 , 0 ) ;
V_131 = V_55 ;
} else
V_131 = F_97 ( V_50 , V_17 ) ;
break;
case V_172 :
case V_458 :
V_131 = F_51 ( V_50 , V_100 , V_17 ) ;
break;
case V_459 :
V_131 = F_53 ( V_50 , 1 , V_17 ) ;
break;
case V_460 :
V_131 = F_53 ( V_50 , 0 , V_17 ) ;
break;
case V_461 :
V_131 = F_56 ( V_50 , V_17 ) ;
break;
case V_462 :
V_423 = 1 ;
V_131 = F_12 ( V_50 , 0 , V_17 ) ;
break;
case V_463 :
V_131 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_42 :
if ( ! F_15 ( V_50 ) ) {
F_7 ( V_17 , V_113 ,
V_114 , 0 ) ;
V_131 = V_55 ;
break;
}
V_131 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_131 )
break;
if ( V_367 )
break;
F_10 ( V_28 , & V_29 , & V_30 , & V_31 ) ;
V_131 = F_72 ( V_50 , V_29 , V_30 , V_17 , V_31 ) ;
if ( V_131 )
break;
V_131 = F_93 ( V_50 , V_29 , V_30 , V_17 , V_31 ) ;
if ( V_131 )
break;
V_131 = F_104 ( V_50 , V_29 , V_30 , V_17 ) ;
break;
case V_32 :
if ( V_121 == V_218 ) {
if ( ( V_28 [ 10 ] & 0xe0 ) == 0 )
F_9 ( V_213
L_92 ) ;
if ( V_28 [ 9 ] == V_464 ) {
F_81 ( V_50 -> V_424 < 32 ) ;
goto V_452;
}
if ( V_28 [ 9 ] == V_465 ) {
F_81 ( V_50 -> V_424 < 32 ) ;
goto V_195;
}
}
F_7 ( V_17 , V_113 ,
V_114 , 0 ) ;
V_131 = V_55 ;
break;
default:
if ( V_25 & V_26 )
F_9 ( V_27 L_93
L_94 , * V_28 ) ;
V_131 = F_12 ( V_50 , 1 , V_17 ) ;
if ( V_131 )
break;
F_7 ( V_17 , V_113 , V_436 , 0 ) ;
V_131 = V_55 ;
break;
}
return F_132 ( V_50 , V_17 , V_333 , V_131 ,
( V_423 ? 0 : V_358 ) ) ;
}
static int F_205 ( struct V_307 * V_46 )
{
int error = 0 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_466 ;
V_6 = F_195 ( V_46 ) ;
V_467 . V_468 = V_271 ;
V_8 = F_206 ( & V_467 , sizeof( V_6 ) ) ;
if ( NULL == V_8 ) {
F_9 ( V_213 L_95 , V_214 ) ;
error = - V_469 ;
return error ;
}
V_6 -> V_10 = V_8 ;
* ( (struct V_5 * * ) V_8 -> V_284 ) = V_6 ;
if ( ( V_8 -> V_11 >= 0 ) && ( V_12 > V_8 -> V_11 ) )
V_8 -> V_13 = V_12 + 1 ;
else
V_8 -> V_13 = V_12 ;
V_8 -> V_14 = V_15 ;
V_466 = 0 ;
switch ( V_121 ) {
case V_216 :
V_466 = V_470 ;
if ( V_227 )
V_466 |= V_471 ;
break;
case V_218 :
V_466 = V_472 ;
if ( V_227 )
V_466 |= V_473 ;
break;
case V_122 :
V_466 = V_474 ;
if ( V_227 )
V_466 |= V_475 ;
break;
default:
if ( V_227 )
V_466 |= V_476 ;
break;
}
F_207 ( V_8 , V_466 ) ;
F_9 ( V_27 L_96 ,
( V_466 & V_470 ) ? L_97 : L_98 ,
( V_466 & V_472 ) ? L_99 : L_98 ,
( V_466 & V_474 ) ? L_100 : L_98 ,
( V_466 & V_476 ) ? L_101 : L_98 ,
( V_466 & V_471 ) ? L_102 : L_98 ,
( V_466 & V_473 ) ? L_103 : L_98 ,
( V_466 & V_475 ) ? L_104 : L_98 ) ;
if ( V_211 == 1 )
F_208 ( V_8 , V_477 ) ;
else
F_208 ( V_8 , V_478 ) ;
error = F_209 ( V_8 , & V_6 -> V_46 ) ;
if ( error ) {
F_9 ( V_213 L_105 , V_214 ) ;
error = - V_469 ;
F_210 ( V_8 ) ;
} else
F_211 ( V_8 ) ;
return error ;
}
static int F_212 ( struct V_307 * V_46 )
{
struct V_5 * V_6 ;
struct V_16 * V_409 , * V_410 ;
V_6 = F_195 ( V_46 ) ;
if ( ! V_6 ) {
F_9 ( V_213 L_106 ,
V_214 ) ;
return - V_469 ;
}
F_213 ( V_6 -> V_10 ) ;
F_199 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_200 ( & V_409 -> V_280 ) ;
F_32 ( V_409 ) ;
}
F_210 ( V_6 -> V_10 ) ;
return 0 ;
}
static int F_214 ( struct V_307 * V_46 ,
struct V_359 * V_479 )
{
return 1 ;
}
