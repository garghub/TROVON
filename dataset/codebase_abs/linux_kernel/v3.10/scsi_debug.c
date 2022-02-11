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
memset ( V_60 , 0 , 0x4 ) ;
V_60 [ 0 ] = 0 ;
if ( V_1 )
V_60 [ 1 ] = 1 << 7 ;
if ( V_2 )
V_60 [ 1 ] |= 1 << 6 ;
if ( V_3 )
V_60 [ 1 ] |= 1 << 5 ;
if ( V_100 )
V_60 [ 1 ] |= 1 << 2 ;
return 0x4 ;
}
static int F_30 ( struct V_49 * V_59 , int V_101 ,
struct V_16 * V_17 )
{
unsigned char V_102 ;
unsigned char * V_60 ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
int V_104 , V_105 , V_106 ;
V_104 = ( V_28 [ 3 ] << 8 ) + V_28 [ 4 ] ;
V_60 = F_31 ( V_107 , V_108 ) ;
if ( ! V_60 )
return V_109 << 16 ;
if ( V_17 -> V_110 )
V_102 = 0x1e ;
else if ( V_111 && ( 0 == V_17 -> V_112 ) )
V_102 = 0x7f ;
else
V_102 = ( V_113 & 0x1f ) ;
V_60 [ 0 ] = V_102 ;
if ( 0x2 & V_28 [ 1 ] ) {
F_7 ( V_17 , V_114 , V_115 ,
0 ) ;
F_32 ( V_60 ) ;
return V_55 ;
} else if ( 0x1 & V_28 [ 1 ] ) {
int V_116 , V_74 , V_75 , V_117 ;
char V_118 [ 6 ] ;
int V_119 = V_17 -> V_6 -> V_10 -> V_119 ;
V_74 = ( ( ( V_119 + 1 ) & 0x7f ) << 8 ) +
( V_17 -> V_120 & 0x7f ) ;
if ( 0 == V_121 )
V_119 = 0 ;
V_116 = V_17 -> V_110 ? - 1 : ( ( ( V_119 + 1 ) * 2000 ) +
( V_17 -> V_101 * 1000 ) + V_17 -> V_112 ) ;
V_75 = ( ( V_119 + 1 ) * 2000 ) +
( V_17 -> V_101 * 1000 ) - 3 ;
V_117 = F_33 ( V_118 , 6 , L_12 , V_116 ) ;
if ( 0 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_105 = 4 ;
V_60 [ V_105 ++ ] = 0x0 ;
V_60 [ V_105 ++ ] = 0x80 ;
V_60 [ V_105 ++ ] = 0x83 ;
V_60 [ V_105 ++ ] = 0x84 ;
V_60 [ V_105 ++ ] = 0x85 ;
V_60 [ V_105 ++ ] = 0x86 ;
V_60 [ V_105 ++ ] = 0x87 ;
V_60 [ V_105 ++ ] = 0x88 ;
V_60 [ V_105 ++ ] = 0x89 ;
V_60 [ V_105 ++ ] = 0xb0 ;
V_60 [ V_105 ++ ] = 0xb1 ;
if ( F_1 () )
V_60 [ V_105 ++ ] = 0xb2 ;
V_60 [ 3 ] = V_105 - 4 ;
} else if ( 0x80 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = V_117 ;
memcpy ( & V_60 [ 4 ] , V_118 , V_117 ) ;
} else if ( 0x83 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = F_20 ( & V_60 [ 4 ] , V_74 ,
V_75 , V_116 ,
V_118 , V_117 ) ;
} else if ( 0x84 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = F_21 ( & V_60 [ 4 ] ) ;
} else if ( 0x85 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = F_22 ( & V_60 [ 4 ] ) ;
} else if ( 0x86 == V_28 [ 2 ] ) {
V_60 [ 1 ] = V_28 [ 2 ] ;
V_60 [ 3 ] = 0x3c ;
if ( V_122 == V_123 )
V_60 [ 4 ] = 0x4 ;
else if ( V_122 )
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
V_105 = F_24 ( & V_60 [ 4 ] ) ;
V_60 [ 2 ] = ( V_105 >> 8 ) ;
V_60 [ 3 ] = ( V_105 & 0xff ) ;
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
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
F_32 ( V_60 ) ;
return V_55 ;
}
V_117 = F_34 ( ( ( V_60 [ 2 ] << 8 ) + V_60 [ 3 ] ) + 4 , V_104 ) ;
V_106 = F_13 ( V_59 , V_60 ,
F_34 ( V_117 , V_107 ) ) ;
F_32 ( V_60 ) ;
return V_106 ;
}
V_60 [ 1 ] = V_124 ? 0x80 : 0 ;
V_60 [ 2 ] = V_125 ;
V_60 [ 3 ] = 2 ;
V_60 [ 4 ] = V_126 - 5 ;
V_60 [ 5 ] = V_122 ? 1 : 0 ;
if ( 0 == V_121 )
V_60 [ 5 ] = 0x10 ;
V_60 [ 6 ] = 0x10 ;
V_60 [ 7 ] = 0xa ;
memcpy ( & V_60 [ 8 ] , V_81 , 8 ) ;
memcpy ( & V_60 [ 16 ] , V_82 , 16 ) ;
memcpy ( & V_60 [ 32 ] , V_127 , 4 ) ;
V_60 [ 58 ] = 0x0 ; V_60 [ 59 ] = 0x77 ;
V_60 [ 60 ] = 0x3 ; V_60 [ 61 ] = 0x14 ;
V_105 = 62 ;
if ( V_113 == 0 ) {
V_60 [ V_105 ++ ] = 0x3 ; V_60 [ V_105 ++ ] = 0x3d ;
} else if ( V_113 == 1 ) {
V_60 [ V_105 ++ ] = 0x3 ; V_60 [ V_105 ++ ] = 0x60 ;
}
V_60 [ V_105 ++ ] = 0xc ; V_60 [ V_105 ++ ] = 0xf ;
V_106 = F_13 ( V_59 , V_60 ,
F_34 ( V_104 , V_126 ) ) ;
F_32 ( V_60 ) ;
return V_106 ;
}
static int F_35 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char * V_21 ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
unsigned char V_60 [ V_23 ] ;
int V_128 ;
int V_117 = 18 ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
if ( V_17 -> V_52 == 1 )
F_7 ( V_17 , 0 , V_129 , 0 ) ;
V_128 = ! ! ( V_28 [ 1 ] & 1 ) || V_24 ;
V_21 = V_17 -> V_22 ;
if ( ( V_130 [ 2 ] & 0x4 ) && ( 6 == ( V_130 [ 3 ] & 0xf ) ) ) {
if ( V_128 ) {
V_60 [ 0 ] = 0x72 ;
V_60 [ 1 ] = 0x0 ;
V_60 [ 2 ] = V_131 ;
V_60 [ 3 ] = 0xff ;
} else {
V_60 [ 0 ] = 0x70 ;
V_60 [ 2 ] = 0x0 ;
V_60 [ 7 ] = 0xa ;
V_60 [ 12 ] = V_131 ;
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
V_117 = 8 ;
}
}
F_7 ( V_17 , 0 , V_129 , 0 ) ;
return F_13 ( V_59 , V_60 , V_117 ) ;
}
static int F_36 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
int V_132 , V_133 , V_134 ;
if ( ( V_133 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_133 ;
V_132 = ( V_28 [ 4 ] & 0xf0 ) >> 4 ;
if ( V_132 ) {
F_7 ( V_17 , V_114 , V_115 ,
0 ) ;
return V_55 ;
}
V_134 = V_28 [ 4 ] & 1 ;
if ( V_134 == V_17 -> V_56 )
V_17 -> V_56 = ! V_134 ;
return 0 ;
}
static T_1 F_37 ( void )
{
if ( V_135 > 0 )
return ( T_1 ) V_135 *
( 1073741824 / V_136 ) ;
else
return V_93 ;
}
static int F_38 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char V_60 [ V_137 ] ;
unsigned int V_138 ;
int V_133 ;
if ( ( V_133 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_133 ;
V_139 = F_37 () ;
memset ( V_60 , 0 , V_137 ) ;
if ( V_139 < 0xffffffff ) {
V_138 = ( unsigned int ) V_139 - 1 ;
V_60 [ 0 ] = ( V_138 >> 24 ) ;
V_60 [ 1 ] = ( V_138 >> 16 ) & 0xff ;
V_60 [ 2 ] = ( V_138 >> 8 ) & 0xff ;
V_60 [ 3 ] = V_138 & 0xff ;
} else {
V_60 [ 0 ] = 0xff ;
V_60 [ 1 ] = 0xff ;
V_60 [ 2 ] = 0xff ;
V_60 [ 3 ] = 0xff ;
}
V_60 [ 6 ] = ( V_136 >> 8 ) & 0xff ;
V_60 [ 7 ] = V_136 & 0xff ;
return F_13 ( V_59 , V_60 , V_137 ) ;
}
static int F_39 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
unsigned char V_60 [ V_140 ] ;
unsigned long long V_138 ;
int V_133 , V_141 , V_104 ;
if ( ( V_133 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_133 ;
V_104 = ( ( V_28 [ 10 ] << 24 ) + ( V_28 [ 11 ] << 16 ) + ( V_28 [ 12 ] << 8 )
+ V_28 [ 13 ] ) ;
V_139 = F_37 () ;
memset ( V_60 , 0 , V_140 ) ;
V_138 = V_139 - 1 ;
for ( V_141 = 0 ; V_141 < 8 ; ++ V_141 , V_138 >>= 8 )
V_60 [ 7 - V_141 ] = V_138 & 0xff ;
V_60 [ 8 ] = ( V_136 >> 24 ) & 0xff ;
V_60 [ 9 ] = ( V_136 >> 16 ) & 0xff ;
V_60 [ 10 ] = ( V_136 >> 8 ) & 0xff ;
V_60 [ 11 ] = V_136 & 0xff ;
V_60 [ 13 ] = V_92 & 0xf ;
V_60 [ 14 ] = ( V_142 >> 8 ) & 0x3f ;
if ( F_1 () ) {
V_60 [ 14 ] |= 0x80 ;
if ( V_100 )
V_60 [ 14 ] |= 0x40 ;
}
V_60 [ 15 ] = V_142 & 0xff ;
if ( V_122 ) {
V_60 [ 12 ] = ( V_122 - 1 ) << 1 ;
V_60 [ 12 ] |= 1 ;
}
return F_13 ( V_59 , V_60 ,
F_34 ( V_104 , V_140 ) ) ;
}
static int F_40 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
unsigned char * V_60 ;
int V_119 = V_17 -> V_6 -> V_10 -> V_119 ;
int V_105 , V_106 , V_143 , V_144 ;
int V_145 , V_146 , V_79 , V_88 ;
V_143 = ( ( V_28 [ 6 ] << 24 ) + ( V_28 [ 7 ] << 16 ) + ( V_28 [ 8 ] << 8 )
+ V_28 [ 9 ] ) ;
V_60 = F_31 ( V_147 , V_108 ) ;
if ( ! V_60 )
return V_109 << 16 ;
V_79 = 0x1 ;
V_88 = 0x2 ;
V_145 = ( ( ( V_119 + 1 ) & 0x7f ) << 8 ) +
( V_17 -> V_120 & 0x7f ) ;
V_146 = ( ( ( V_119 + 1 ) & 0x7f ) << 8 ) +
( V_17 -> V_120 & 0x7f ) + 0x80 ;
V_105 = 4 ;
if ( 0 == V_121 ) {
V_60 [ V_105 ++ ] = V_119 % 3 ;
V_60 [ V_105 ++ ] = 0x0F ;
} else {
V_60 [ V_105 ++ ] = 0x0 ;
V_60 [ V_105 ++ ] = 0x01 ;
}
V_60 [ V_105 ++ ] = ( V_145 >> 8 ) & 0xff ;
V_60 [ V_105 ++ ] = V_145 & 0xff ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = 0x1 ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = ( V_79 >> 8 ) & 0xff ;
V_60 [ V_105 ++ ] = V_79 & 0xff ;
V_60 [ V_105 ++ ] = 3 ;
V_60 [ V_105 ++ ] = 0x08 ;
V_60 [ V_105 ++ ] = ( V_146 >> 8 ) & 0xff ;
V_60 [ V_105 ++ ] = V_146 & 0xff ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = 0x1 ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = ( V_88 >> 8 ) & 0xff ;
V_60 [ V_105 ++ ] = V_88 & 0xff ;
V_144 = V_105 - 4 ;
V_60 [ 0 ] = ( V_144 >> 24 ) & 0xff ;
V_60 [ 1 ] = ( V_144 >> 16 ) & 0xff ;
V_60 [ 2 ] = ( V_144 >> 8 ) & 0xff ;
V_60 [ 3 ] = V_144 & 0xff ;
V_144 = F_34 ( V_143 , V_105 ) ;
V_106 = F_13 ( V_59 , V_60 ,
F_34 ( V_144 , V_147 ) ) ;
F_32 ( V_60 ) ;
return V_106 ;
}
static int F_41 ( unsigned char * V_148 , int V_149 , int V_101 )
{
unsigned char V_150 [] = { 0x1 , 0xa , 0xc0 , 11 , 240 , 0 , 0 , 0 ,
5 , 0 , 0xff , 0xff } ;
memcpy ( V_148 , V_150 , sizeof( V_150 ) ) ;
if ( 1 == V_149 )
memset ( V_148 + 2 , 0 , sizeof( V_150 ) - 2 ) ;
return sizeof( V_150 ) ;
}
static int F_42 ( unsigned char * V_148 , int V_149 , int V_101 )
{
unsigned char V_151 [] = { 0x2 , 0xe , 128 , 128 , 0 , 10 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_148 , V_151 , sizeof( V_151 ) ) ;
if ( 1 == V_149 )
memset ( V_148 + 2 , 0 , sizeof( V_151 ) - 2 ) ;
return sizeof( V_151 ) ;
}
static int F_43 ( unsigned char * V_148 , int V_149 , int V_101 )
{
unsigned char V_152 [] = { 0x3 , 0x16 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0x40 , 0 , 0 , 0 } ;
memcpy ( V_148 , V_152 , sizeof( V_152 ) ) ;
V_148 [ 10 ] = ( V_153 >> 8 ) & 0xff ;
V_148 [ 11 ] = V_153 & 0xff ;
V_148 [ 12 ] = ( V_136 >> 8 ) & 0xff ;
V_148 [ 13 ] = V_136 & 0xff ;
if ( V_124 )
V_148 [ 20 ] |= 0x20 ;
if ( 1 == V_149 )
memset ( V_148 + 2 , 0 , sizeof( V_152 ) - 2 ) ;
return sizeof( V_152 ) ;
}
static int F_44 ( unsigned char * V_148 , int V_149 , int V_101 )
{
unsigned char V_154 [] = { 0x8 , 18 , 0x14 , 0 , 0xff , 0xff , 0 , 0 ,
0xff , 0xff , 0xff , 0xff , 0x80 , 0x14 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_148 , V_154 , sizeof( V_154 ) ) ;
if ( 1 == V_149 )
memset ( V_148 + 2 , 0 , sizeof( V_154 ) - 2 ) ;
return sizeof( V_154 ) ;
}
static int F_45 ( unsigned char * V_148 , int V_149 , int V_101 )
{
unsigned char V_155 [] = { 0x6 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ;
unsigned char V_156 [] = { 0xa , 10 , 2 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x2 , 0x4b } ;
if ( V_24 )
V_157 [ 2 ] |= 0x4 ;
else
V_157 [ 2 ] &= ~ 0x4 ;
if ( V_158 )
V_157 [ 5 ] |= 0x80 ;
memcpy ( V_148 , V_157 , sizeof( V_157 ) ) ;
if ( 1 == V_149 )
memcpy ( V_148 + 2 , V_155 , sizeof( V_155 ) ) ;
else if ( 2 == V_149 )
memcpy ( V_148 , V_156 , sizeof( V_156 ) ) ;
return sizeof( V_157 ) ;
}
static int F_46 ( unsigned char * V_148 , int V_149 , int V_101 )
{
unsigned char V_159 [] = { 0x4 , 0xf , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
unsigned char V_160 [] = { 0x1c , 0xa , 0x08 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
memcpy ( V_148 , V_130 , sizeof( V_130 ) ) ;
if ( 1 == V_149 )
memcpy ( V_148 + 2 , V_159 , sizeof( V_159 ) ) ;
else if ( 2 == V_149 )
memcpy ( V_148 , V_160 , sizeof( V_160 ) ) ;
return sizeof( V_130 ) ;
}
static int F_47 ( unsigned char * V_148 , int V_149 , int V_101 )
{
unsigned char V_161 [] = { 0x19 , 0x6 ,
0x6 , 0x0 , 0x7 , 0xd0 , 0x0 , 0x0 } ;
memcpy ( V_148 , V_161 , sizeof( V_161 ) ) ;
if ( 1 == V_149 )
memset ( V_148 + 2 , 0 , sizeof( V_161 ) - 2 ) ;
return sizeof( V_161 ) ;
}
static int F_48 ( unsigned char * V_148 , int V_149 , int V_101 ,
int V_75 )
{
unsigned char V_162 [] = { 0x59 , 0x1 , 0 , 0x64 , 0 , 0x6 , 0 , 2 ,
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
memcpy ( V_148 , V_162 , sizeof( V_162 ) ) ;
V_148 [ 20 ] = ( V_79 >> 24 ) ;
V_148 [ 21 ] = ( V_79 >> 16 ) & 0xff ;
V_148 [ 22 ] = ( V_79 >> 8 ) & 0xff ;
V_148 [ 23 ] = V_79 & 0xff ;
V_148 [ 48 + 20 ] = ( V_88 >> 24 ) ;
V_148 [ 48 + 21 ] = ( V_88 >> 16 ) & 0xff ;
V_148 [ 48 + 22 ] = ( V_88 >> 8 ) & 0xff ;
V_148 [ 48 + 23 ] = V_88 & 0xff ;
if ( 1 == V_149 )
memset ( V_148 + 4 , 0 , sizeof( V_162 ) - 4 ) ;
return sizeof( V_162 ) ;
}
static int F_49 ( unsigned char * V_148 , int V_149 )
{
unsigned char V_163 [] = { 0x59 , 0x2 , 0 , 0xc , 0 , 0x6 , 0x10 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
memcpy ( V_148 , V_163 , sizeof( V_163 ) ) ;
if ( 1 == V_149 )
memset ( V_148 + 4 , 0 , sizeof( V_163 ) - 4 ) ;
return sizeof( V_163 ) ;
}
static int F_50 ( struct V_49 * V_59 , int V_101 ,
struct V_16 * V_17 )
{
unsigned char V_164 , V_165 ;
int V_149 , V_166 , V_167 , V_168 ;
unsigned char V_169 ;
int V_141 , V_104 , V_170 , V_171 , V_117 , V_133 , V_75 ;
unsigned char * V_172 ;
unsigned char V_60 [ V_173 ] ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
if ( ( V_133 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_133 ;
V_164 = ! ! ( V_28 [ 1 ] & 0x8 ) ;
V_149 = ( V_28 [ 2 ] & 0xc0 ) >> 6 ;
V_166 = V_28 [ 2 ] & 0x3f ;
V_167 = V_28 [ 3 ] ;
V_170 = ( V_174 == V_28 [ 0 ] ) ;
V_165 = V_170 ? 0 : ! ! ( V_28 [ 1 ] & 0x10 ) ;
if ( ( 0 == V_113 ) && ( 0 == V_164 ) )
V_168 = V_165 ? 16 : 8 ;
else
V_168 = 0 ;
V_104 = V_170 ? V_28 [ 4 ] : ( ( V_28 [ 7 ] << 8 ) | V_28 [ 8 ] ) ;
memset ( V_60 , 0 , V_173 ) ;
if ( 0x3 == V_149 ) {
F_7 ( V_17 , V_114 , V_175 ,
0 ) ;
return V_55 ;
}
V_75 = ( ( V_17 -> V_6 -> V_10 -> V_119 + 1 ) * 2000 ) +
( V_17 -> V_101 * 1000 ) - 3 ;
if ( 0 == V_113 )
V_169 = ( F_51 ( V_101 ) ? 0x80 : 0x0 ) | 0x10 ;
else
V_169 = 0x0 ;
if ( V_170 ) {
V_60 [ 2 ] = V_169 ;
V_60 [ 3 ] = V_168 ;
V_171 = 4 ;
} else {
V_60 [ 3 ] = V_169 ;
if ( 16 == V_168 )
V_60 [ 4 ] = 0x1 ;
V_60 [ 7 ] = V_168 ;
V_171 = 8 ;
}
V_172 = V_60 + V_171 ;
if ( ( V_168 > 0 ) && ( ! V_139 ) )
V_139 = F_37 () ;
if ( 8 == V_168 ) {
if ( V_139 > 0xfffffffe ) {
V_172 [ 0 ] = 0xff ;
V_172 [ 1 ] = 0xff ;
V_172 [ 2 ] = 0xff ;
V_172 [ 3 ] = 0xff ;
} else {
V_172 [ 0 ] = ( V_139 >> 24 ) & 0xff ;
V_172 [ 1 ] = ( V_139 >> 16 ) & 0xff ;
V_172 [ 2 ] = ( V_139 >> 8 ) & 0xff ;
V_172 [ 3 ] = V_139 & 0xff ;
}
V_172 [ 6 ] = ( V_136 >> 8 ) & 0xff ;
V_172 [ 7 ] = V_136 & 0xff ;
V_171 += V_168 ;
V_172 = V_60 + V_171 ;
} else if ( 16 == V_168 ) {
unsigned long long V_138 = V_139 ;
for ( V_141 = 0 ; V_141 < 8 ; ++ V_141 , V_138 >>= 8 )
V_172 [ 7 - V_141 ] = V_138 & 0xff ;
V_172 [ 12 ] = ( V_136 >> 24 ) & 0xff ;
V_172 [ 13 ] = ( V_136 >> 16 ) & 0xff ;
V_172 [ 14 ] = ( V_136 >> 8 ) & 0xff ;
V_172 [ 15 ] = V_136 & 0xff ;
V_171 += V_168 ;
V_172 = V_60 + V_171 ;
}
if ( ( V_167 > 0x0 ) && ( V_167 < 0xff ) && ( 0x19 != V_166 ) ) {
F_7 ( V_17 , V_114 , V_115 ,
0 ) ;
return V_55 ;
}
switch ( V_166 ) {
case 0x1 :
V_117 = F_41 ( V_172 , V_149 , V_101 ) ;
V_171 += V_117 ;
break;
case 0x2 :
V_117 = F_42 ( V_172 , V_149 , V_101 ) ;
V_171 += V_117 ;
break;
case 0x3 :
V_117 = F_43 ( V_172 , V_149 , V_101 ) ;
V_171 += V_117 ;
break;
case 0x8 :
V_117 = F_44 ( V_172 , V_149 , V_101 ) ;
V_171 += V_117 ;
break;
case 0xa :
V_117 = F_45 ( V_172 , V_149 , V_101 ) ;
V_171 += V_117 ;
break;
case 0x19 :
if ( ( V_167 > 0x2 ) && ( V_167 < 0xff ) ) {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
return V_55 ;
}
V_117 = 0 ;
if ( ( 0x0 == V_167 ) || ( 0xff == V_167 ) )
V_117 += F_47 ( V_172 + V_117 , V_149 , V_101 ) ;
if ( ( 0x1 == V_167 ) || ( 0xff == V_167 ) )
V_117 += F_48 ( V_172 + V_117 , V_149 , V_101 ,
V_75 ) ;
if ( ( 0x2 == V_167 ) || ( 0xff == V_167 ) )
V_117 += F_49 ( V_172 + V_117 , V_149 ) ;
V_171 += V_117 ;
break;
case 0x1c :
V_117 = F_46 ( V_172 , V_149 , V_101 ) ;
V_171 += V_117 ;
break;
case 0x3f :
if ( ( 0 == V_167 ) || ( 0xff == V_167 ) ) {
V_117 = F_41 ( V_172 , V_149 , V_101 ) ;
V_117 += F_42 ( V_172 + V_117 , V_149 , V_101 ) ;
V_117 += F_43 ( V_172 + V_117 , V_149 , V_101 ) ;
V_117 += F_44 ( V_172 + V_117 , V_149 , V_101 ) ;
V_117 += F_45 ( V_172 + V_117 , V_149 , V_101 ) ;
V_117 += F_47 ( V_172 + V_117 , V_149 , V_101 ) ;
if ( 0xff == V_167 ) {
V_117 += F_48 ( V_172 + V_117 , V_149 ,
V_101 , V_75 ) ;
V_117 += F_49 ( V_172 + V_117 , V_149 ) ;
}
V_117 += F_46 ( V_172 + V_117 , V_149 , V_101 ) ;
} else {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
return V_55 ;
}
V_171 += V_117 ;
break;
default:
F_7 ( V_17 , V_114 , V_115 ,
0 ) ;
return V_55 ;
}
if ( V_170 )
V_60 [ 0 ] = V_171 - 1 ;
else {
V_60 [ 0 ] = ( ( V_171 - 2 ) >> 8 ) & 0xff ;
V_60 [ 1 ] = ( V_171 - 2 ) & 0xff ;
}
return F_13 ( V_59 , V_60 , F_34 ( V_104 , V_171 ) ) ;
}
static int F_52 ( struct V_49 * V_59 , int V_176 ,
struct V_16 * V_17 )
{
int V_177 , V_178 , V_179 , V_180 , V_168 , V_181 , V_182 , V_183 ;
int V_184 , V_185 , V_133 , V_186 ;
unsigned char V_60 [ V_187 ] ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
if ( ( V_133 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_133 ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
V_177 = V_28 [ 1 ] & 0x10 ;
V_178 = V_28 [ 1 ] & 0x1 ;
V_184 = V_176 ? V_28 [ 4 ] : ( ( V_28 [ 7 ] << 8 ) + V_28 [ 8 ] ) ;
if ( ( 0 == V_177 ) || V_178 || ( V_184 > V_187 ) ) {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
return V_55 ;
}
V_185 = F_18 ( V_59 , V_60 , V_184 ) ;
if ( - 1 == V_185 )
return ( V_68 << 16 ) ;
else if ( ( V_185 < V_184 ) &&
( V_25 & V_26 ) )
F_9 ( V_27 L_13
L_14 , V_184 , V_185 ) ;
V_180 = V_176 ? ( V_60 [ 0 ] + 1 ) : ( ( V_60 [ 0 ] << 8 ) + V_60 [ 1 ] + 2 ) ;
V_168 = V_176 ? V_60 [ 3 ] : ( ( V_60 [ 6 ] << 8 ) + V_60 [ 7 ] ) ;
if ( V_180 > 2 ) {
F_7 ( V_17 , V_114 ,
V_188 , 0 ) ;
return V_55 ;
}
V_181 = V_168 + ( V_176 ? 4 : 8 ) ;
V_186 = V_60 [ V_181 ] & 0x3f ;
V_179 = ! ! ( V_60 [ V_181 ] & 0x80 ) ;
if ( V_179 ) {
F_7 ( V_17 , V_114 ,
V_188 , 0 ) ;
return V_55 ;
}
V_182 = ! ! ( V_60 [ V_181 ] & 0x40 ) ;
V_183 = V_182 ? ( ( V_60 [ V_181 + 2 ] << 8 ) + V_60 [ V_181 + 3 ] + 4 ) :
( V_60 [ V_181 + 1 ] + 2 ) ;
if ( ( V_183 + V_181 ) > V_184 ) {
F_7 ( V_17 , V_114 ,
V_189 , 0 ) ;
return V_55 ;
}
switch ( V_186 ) {
case 0xa :
if ( V_157 [ 1 ] == V_60 [ V_181 + 1 ] ) {
memcpy ( V_157 + 2 , V_60 + V_181 + 2 ,
sizeof( V_157 ) - 2 ) ;
V_24 = ! ! ( V_157 [ 2 ] & 0x4 ) ;
return 0 ;
}
break;
case 0x1c :
if ( V_130 [ 1 ] == V_60 [ V_181 + 1 ] ) {
memcpy ( V_130 + 2 , V_60 + V_181 + 2 ,
sizeof( V_130 ) - 2 ) ;
return 0 ;
}
break;
default:
break;
}
F_7 ( V_17 , V_114 ,
V_188 , 0 ) ;
return V_55 ;
}
static int F_53 ( unsigned char * V_60 )
{
unsigned char V_190 [] = { 0x0 , 0x0 , 0x3 , 0x2 , 0x0 , 38 ,
0x0 , 0x1 , 0x3 , 0x2 , 0x0 , 65 ,
} ;
memcpy ( V_60 , V_190 , sizeof( V_190 ) ) ;
return sizeof( V_190 ) ;
}
static int F_54 ( unsigned char * V_60 )
{
unsigned char V_191 [] = { 0x0 , 0x0 , 0x3 , 0x3 , 0x0 , 0x0 , 38 ,
} ;
memcpy ( V_60 , V_191 , sizeof( V_191 ) ) ;
if ( V_130 [ 2 ] & 0x4 ) {
V_60 [ 4 ] = V_131 ;
V_60 [ 5 ] = 0xff ;
}
return sizeof( V_191 ) ;
}
static int F_55 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
int V_192 , V_178 , V_149 , V_166 , V_167 , V_104 , V_133 , V_117 , V_105 ;
unsigned char V_60 [ V_193 ] ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
if ( ( V_133 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_133 ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
V_192 = V_28 [ 1 ] & 0x2 ;
V_178 = V_28 [ 1 ] & 0x1 ;
if ( V_192 || V_178 ) {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
return V_55 ;
}
V_149 = ( V_28 [ 2 ] & 0xc0 ) >> 6 ;
V_166 = V_28 [ 2 ] & 0x3f ;
V_167 = V_28 [ 3 ] & 0xff ;
V_104 = ( V_28 [ 7 ] << 8 ) + V_28 [ 8 ] ;
V_60 [ 0 ] = V_166 ;
if ( 0 == V_167 ) {
switch ( V_166 ) {
case 0x0 :
V_105 = 4 ;
V_60 [ V_105 ++ ] = 0x0 ;
V_60 [ V_105 ++ ] = 0xd ;
V_60 [ V_105 ++ ] = 0x2f ;
V_60 [ 3 ] = V_105 - 4 ;
break;
case 0xd :
V_60 [ 3 ] = F_53 ( V_60 + 4 ) ;
break;
case 0x2f :
V_60 [ 3 ] = F_54 ( V_60 + 4 ) ;
break;
default:
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
return V_55 ;
}
} else if ( 0xff == V_167 ) {
V_60 [ 0 ] |= 0x40 ;
V_60 [ 1 ] = V_167 ;
switch ( V_166 ) {
case 0x0 :
V_105 = 4 ;
V_60 [ V_105 ++ ] = 0x0 ;
V_60 [ V_105 ++ ] = 0x0 ;
V_60 [ V_105 ++ ] = 0x0 ;
V_60 [ V_105 ++ ] = 0xff ;
V_60 [ V_105 ++ ] = 0xd ;
V_60 [ V_105 ++ ] = 0x0 ;
V_60 [ V_105 ++ ] = 0x2f ;
V_60 [ V_105 ++ ] = 0x0 ;
V_60 [ 3 ] = V_105 - 4 ;
break;
case 0xd :
V_105 = 4 ;
V_60 [ V_105 ++ ] = 0xd ;
V_60 [ V_105 ++ ] = 0x0 ;
V_60 [ 3 ] = V_105 - 4 ;
break;
case 0x2f :
V_105 = 4 ;
V_60 [ V_105 ++ ] = 0x2f ;
V_60 [ V_105 ++ ] = 0x0 ;
V_60 [ 3 ] = V_105 - 4 ;
break;
default:
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
return V_55 ;
}
} else {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
return V_55 ;
}
V_117 = F_34 ( ( ( V_60 [ 2 ] << 8 ) + V_60 [ 3 ] ) + 4 , V_104 ) ;
return F_13 ( V_59 , V_60 ,
F_34 ( V_117 , V_107 ) ) ;
}
static int F_56 ( struct V_16 * V_194 ,
unsigned long long V_29 , unsigned int V_30 )
{
if ( V_29 + V_30 > V_139 ) {
F_7 ( V_194 , V_114 , V_195 , 0 ) ;
return V_55 ;
}
if ( V_30 > V_93 ) {
F_7 ( V_194 , V_114 , V_115 , 0 ) ;
return V_55 ;
}
return 0 ;
}
static int F_57 ( struct V_49 * V_196 ,
struct V_16 * V_194 ,
unsigned long long V_29 , unsigned int V_30 , int V_197 )
{
int V_106 ;
unsigned long long V_198 , V_199 = 0 ;
int (* F_58)( struct V_49 * , unsigned char * , int );
F_58 = V_197 ? F_18 : F_13 ;
V_198 = F_59 ( V_29 , V_93 ) ;
if ( V_198 + V_30 > V_93 )
V_199 = V_198 + V_30 - V_93 ;
V_106 = F_58 ( V_196 , V_200 + ( V_198 * V_136 ) ,
( V_30 - V_199 ) * V_136 ) ;
if ( ! V_106 && V_199 )
V_106 = F_58 ( V_196 , V_200 , V_199 * V_136 ) ;
return V_106 ;
}
static int F_60 ( struct V_49 * V_50 , T_1 V_201 ,
unsigned int V_202 , T_2 V_31 )
{
unsigned int V_203 , V_72 ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
T_1 V_4 ;
T_1 V_208 = V_201 ;
void * V_209 ;
V_201 = F_59 ( V_208 , V_93 ) ;
V_207 = (struct V_206 * ) ( V_210 + F_2 ( V_201 ) ) ;
for ( V_203 = 0 ; V_203 < V_202 ; V_203 ++ ) {
T_4 V_211 ;
if ( V_207 [ V_203 ] . V_212 == 0xffff )
continue;
V_4 = V_201 + V_203 ;
switch ( V_213 ) {
case 1 :
V_211 = F_61 ( V_200 +
V_4 * V_136 ,
V_136 ) ;
break;
case 0 :
V_211 = F_62 ( V_200 +
V_4 * V_136 ,
V_136 ) ;
V_211 = F_63 ( V_211 ) ;
break;
default:
F_64 () ;
}
if ( V_207 [ V_203 ] . V_214 != V_211 ) {
F_9 ( V_215 L_15 \
L_16 , V_216 ,
( unsigned long ) V_4 ,
F_65 ( V_207 [ V_203 ] . V_214 ) ,
F_65 ( V_211 ) ) ;
V_217 ++ ;
return 0x01 ;
}
if ( V_122 == V_218 &&
F_66 ( V_207 [ V_203 ] . V_219 ) != ( V_4 & 0xffffffff ) ) {
F_9 ( V_215 L_17 ,
V_216 , ( unsigned long ) V_4 ) ;
V_217 ++ ;
return 0x03 ;
}
if ( V_122 == V_220 &&
F_66 ( V_207 [ V_203 ] . V_219 ) != V_31 ) {
F_9 ( V_215 L_17 ,
V_216 , ( unsigned long ) V_4 ) ;
V_217 ++ ;
return 0x03 ;
}
V_31 ++ ;
}
V_72 = V_202 * 8 ;
V_4 = V_201 ;
F_67 (SCpnt, psgl, scsi_prot_sg_count(SCpnt), i) {
int V_117 = F_34 ( V_205 -> V_65 , V_72 ) ;
V_209 = F_68 ( F_69 ( V_205 ) ) + V_205 -> V_171 ;
memcpy ( V_209 , V_210 + F_2 ( V_4 ) , V_117 ) ;
V_4 += V_117 >> 3 ;
if ( V_4 >= V_93 ) {
V_208 = V_4 ;
V_4 = F_59 ( V_208 , V_93 ) ;
}
V_72 -= V_117 ;
F_70 ( V_209 ) ;
}
V_221 ++ ;
return 0 ;
}
static int F_71 ( struct V_49 * V_50 , unsigned long long V_29 ,
unsigned int V_30 , struct V_16 * V_17 ,
T_2 V_31 )
{
unsigned long V_222 ;
int V_106 ;
V_106 = F_56 ( V_17 , V_29 , V_30 ) ;
if ( V_106 )
return V_106 ;
if ( ( V_223 & V_26 ) &&
( V_29 <= ( V_224 + V_225 - 1 ) ) &&
( ( V_29 + V_30 ) > V_224 ) ) {
F_7 ( V_17 , V_226 , V_227 , 0 ) ;
if ( 0x70 == ( V_17 -> V_22 [ 0 ] & 0x7f ) ) {
V_17 -> V_22 [ 0 ] |= 0x80 ;
V_106 = ( V_29 < V_224 )
? V_224 : ( int ) V_29 ;
V_17 -> V_22 [ 3 ] = ( V_106 >> 24 ) & 0xff ;
V_17 -> V_22 [ 4 ] = ( V_106 >> 16 ) & 0xff ;
V_17 -> V_22 [ 5 ] = ( V_106 >> 8 ) & 0xff ;
V_17 -> V_22 [ 6 ] = V_106 & 0xff ;
}
F_72 ( V_50 , F_17 ( V_50 ) ) ;
return V_55 ;
}
if ( V_228 && F_73 ( V_50 ) ) {
int V_229 = F_60 ( V_50 , V_29 , V_30 , V_31 ) ;
if ( V_229 ) {
F_7 ( V_17 , V_230 , 0x10 , V_229 ) ;
return V_231 ;
}
}
F_74 ( & V_232 , V_222 ) ;
V_106 = F_57 ( V_50 , V_17 , V_29 , V_30 , 0 ) ;
F_75 ( & V_232 , V_222 ) ;
return V_106 ;
}
void F_76 ( unsigned char * V_233 , int V_117 )
{
int V_203 , V_234 ;
F_9 ( V_215 L_18 ) ;
for ( V_203 = 0 ; V_203 < V_117 ; V_203 += 16 ) {
F_9 ( V_215 L_19 , V_203 ) ;
for ( V_234 = 0 ; V_234 < 16 ; V_234 ++ ) {
unsigned char V_235 = V_233 [ V_203 + V_234 ] ;
if ( V_235 >= 0x20 && V_235 < 0x7e )
F_9 ( L_20 , V_233 [ V_203 + V_234 ] ) ;
else
F_9 ( L_21 , V_233 [ V_203 + V_234 ] ) ;
}
F_9 ( L_22 ) ;
}
}
static int F_77 ( struct V_49 * V_50 , T_1 V_201 ,
unsigned int V_202 , T_2 V_31 )
{
int V_203 , V_234 , V_106 ;
struct V_206 * V_207 ;
struct V_204 * V_236 = F_78 ( V_50 ) ;
struct V_204 * V_205 = F_79 ( V_50 ) ;
void * V_237 , * V_209 ;
T_1 V_208 = V_201 ;
T_1 V_4 ;
int V_238 ;
unsigned short V_211 ;
V_4 = F_59 ( V_208 , V_93 ) ;
F_80 ( F_81 ( V_50 ) == 0 ) ;
F_80 ( F_73 ( V_50 ) == 0 ) ;
V_209 = F_68 ( F_69 ( V_205 ) ) + V_205 -> V_171 ;
V_238 = 0 ;
F_82 (SCpnt, dsgl, scsi_sg_count(SCpnt), i) {
V_237 = F_68 ( F_69 ( V_236 ) ) + V_236 -> V_171 ;
for ( V_234 = 0 ; V_234 < V_236 -> V_65 ; V_234 += V_136 ) {
if ( V_238 >= V_205 -> V_65 ) {
F_70 ( V_209 ) ;
V_205 = F_83 ( V_205 ) ;
F_80 ( V_205 == NULL ) ;
V_209 = F_68 ( F_69 ( V_205 ) )
+ V_205 -> V_171 ;
V_238 = 0 ;
}
V_207 = V_209 + V_238 ;
switch ( V_213 ) {
case 1 :
V_211 = F_61 ( V_237 ,
V_136 ) ;
break;
case 0 :
V_211 = F_63 ( F_62 ( V_237 ,
V_136 ) ) ;
break;
default:
F_64 () ;
V_106 = 0 ;
goto V_239;
}
if ( V_207 -> V_214 != V_211 ) {
F_9 ( V_215
L_23 \
L_24 ,
V_216 , ( unsigned long ) V_4 ,
F_65 ( V_207 -> V_214 ) ,
F_65 ( V_211 ) ) ;
V_106 = 0x01 ;
F_76 ( V_237 , V_136 ) ;
goto V_239;
}
if ( V_122 == V_218 &&
F_66 ( V_207 -> V_219 )
!= ( V_201 & 0xffffffff ) ) {
F_9 ( V_215
L_17 ,
V_216 , ( unsigned long ) V_4 ) ;
V_106 = 0x03 ;
F_76 ( V_237 , V_136 ) ;
goto V_239;
}
if ( V_122 == V_220 &&
F_66 ( V_207 -> V_219 ) != V_31 ) {
F_9 ( V_215
L_17 ,
V_216 , ( unsigned long ) V_4 ) ;
V_106 = 0x03 ;
F_76 ( V_237 , V_136 ) ;
goto V_239;
}
memcpy ( V_210 + F_2 ( V_4 ) , V_207 , 8 ) ;
V_4 ++ ;
if ( V_4 == V_93 )
V_4 = 0 ;
V_201 ++ ;
V_31 ++ ;
V_237 += V_136 ;
V_238 += sizeof( struct V_206 ) ;
}
F_70 ( V_237 ) ;
}
F_70 ( V_209 ) ;
V_240 ++ ;
return 0 ;
V_239:
V_217 ++ ;
F_70 ( V_237 ) ;
F_70 ( V_209 ) ;
return V_106 ;
}
static unsigned long F_84 ( T_1 V_29 )
{
if ( V_97 ) {
V_29 += V_98 -
V_97 ;
}
F_59 ( V_29 , V_98 ) ;
return V_29 ;
}
static T_1 F_85 ( unsigned long V_241 )
{
return V_241 * V_98 -
V_97 ;
}
static unsigned int F_86 ( T_1 V_29 , unsigned int * V_30 )
{
T_1 V_242 ;
unsigned int V_243 ;
unsigned long V_241 ;
unsigned long V_244 ;
V_241 = F_84 ( V_29 ) ;
V_243 = F_87 ( V_241 , V_245 ) ;
if ( V_243 )
V_244 = F_88 ( V_245 , V_246 , V_241 ) ;
else
V_244 = F_89 ( V_245 , V_246 , V_241 ) ;
V_242 = F_90 ( T_1 , V_93 , F_85 ( V_244 ) ) ;
* V_30 = V_242 - V_29 ;
return V_243 ;
}
static void F_91 ( T_1 V_29 , unsigned int V_117 )
{
T_1 V_242 = V_29 + V_117 ;
while ( V_29 < V_242 ) {
unsigned long V_241 = F_84 ( V_29 ) ;
if ( V_241 < V_246 )
F_92 ( V_241 , V_245 ) ;
V_29 = F_85 ( V_241 + 1 ) ;
}
}
static void F_93 ( T_1 V_29 , unsigned int V_117 )
{
T_1 V_242 = V_29 + V_117 ;
while ( V_29 < V_242 ) {
unsigned long V_241 = F_84 ( V_29 ) ;
if ( V_29 == F_85 ( V_241 ) &&
V_29 + V_98 <= V_242 &&
V_241 < V_246 ) {
F_94 ( V_241 , V_245 ) ;
if ( V_100 ) {
memset ( V_200 +
V_29 * V_136 , 0 ,
V_136 *
V_98 ) ;
}
}
V_29 = F_85 ( V_241 + 1 ) ;
}
}
static int F_95 ( struct V_49 * V_50 , unsigned long long V_29 ,
unsigned int V_30 , struct V_16 * V_17 ,
T_2 V_31 )
{
unsigned long V_222 ;
int V_106 ;
V_106 = F_56 ( V_17 , V_29 , V_30 ) ;
if ( V_106 )
return V_106 ;
if ( V_228 && F_73 ( V_50 ) ) {
int V_229 = F_77 ( V_50 , V_29 , V_30 , V_31 ) ;
if ( V_229 ) {
F_7 ( V_17 , V_114 , 0x10 , V_229 ) ;
return V_231 ;
}
}
F_96 ( & V_232 , V_222 ) ;
V_106 = F_57 ( V_50 , V_17 , V_29 , V_30 , 1 ) ;
if ( F_1 () )
F_91 ( V_29 , V_30 ) ;
F_97 ( & V_232 , V_222 ) ;
if ( - 1 == V_106 )
return ( V_68 << 16 ) ;
else if ( ( V_106 < ( V_30 * V_136 ) ) &&
( V_25 & V_26 ) )
F_9 ( V_27 L_25
L_14 , V_30 * V_136 , V_106 ) ;
return 0 ;
}
static int F_98 ( struct V_49 * V_196 , unsigned long long V_29 ,
unsigned int V_30 , struct V_16 * V_17 ,
T_2 V_31 , unsigned int V_247 )
{
unsigned long V_222 ;
unsigned long long V_203 ;
int V_106 ;
V_106 = F_56 ( V_17 , V_29 , V_30 ) ;
if ( V_106 )
return V_106 ;
if ( V_30 > V_99 ) {
F_7 ( V_17 , V_114 , V_115 ,
0 ) ;
return V_55 ;
}
F_96 ( & V_232 , V_222 ) ;
if ( V_247 && F_1 () ) {
F_93 ( V_29 , V_30 ) ;
goto V_239;
}
V_106 = F_18 ( V_196 ,
V_200 + ( V_29 * V_136 ) ,
V_136 ) ;
if ( - 1 == V_106 ) {
F_97 ( & V_232 , V_222 ) ;
return ( V_68 << 16 ) ;
} else if ( ( V_106 < ( V_30 * V_136 ) ) &&
( V_25 & V_26 ) )
F_9 ( V_27 L_26
L_14 , V_30 * V_136 , V_106 ) ;
for ( V_203 = 1 ; V_203 < V_30 ; V_203 ++ )
memcpy ( V_200 + ( ( V_29 + V_203 ) * V_136 ) ,
V_200 + ( V_29 * V_136 ) ,
V_136 ) ;
if ( F_1 () )
F_91 ( V_29 , V_30 ) ;
V_239:
F_97 ( & V_232 , V_222 ) ;
return 0 ;
}
static int F_99 ( struct V_49 * V_196 , struct V_16 * V_17 )
{
unsigned char * V_233 ;
struct V_248 * V_249 ;
unsigned int V_203 , V_250 , V_251 ;
int V_106 ;
V_106 = F_12 ( V_196 , 1 , V_17 ) ;
if ( V_106 )
return V_106 ;
V_250 = F_100 ( & V_196 -> V_103 [ 7 ] ) ;
F_80 ( F_17 ( V_196 ) != V_250 ) ;
V_251 = ( V_250 - 8 ) / 16 ;
V_233 = F_101 ( F_17 ( V_196 ) , V_108 ) ;
if ( ! V_233 )
return V_55 ;
F_19 ( V_196 , V_233 , F_17 ( V_196 ) ) ;
F_80 ( F_100 ( & V_233 [ 0 ] ) != V_250 - 2 ) ;
F_80 ( F_100 ( & V_233 [ 2 ] ) != V_251 * 16 ) ;
V_249 = ( void * ) & V_233 [ 8 ] ;
for ( V_203 = 0 ; V_203 < V_251 ; V_203 ++ ) {
unsigned long long V_29 = F_102 ( & V_249 [ V_203 ] . V_29 ) ;
unsigned int V_30 = F_103 ( & V_249 [ V_203 ] . V_252 ) ;
V_106 = F_56 ( V_17 , V_29 , V_30 ) ;
if ( V_106 )
goto V_239;
F_93 ( V_29 , V_30 ) ;
}
V_106 = 0 ;
V_239:
F_32 ( V_233 ) ;
return V_106 ;
}
static int F_104 ( struct V_49 * V_196 ,
struct V_16 * V_17 )
{
unsigned long long V_29 ;
unsigned int V_104 , V_243 , V_30 ;
unsigned char V_60 [ V_253 ] ;
int V_106 ;
V_106 = F_12 ( V_196 , 1 , V_17 ) ;
if ( V_106 )
return V_106 ;
V_29 = F_102 ( & V_196 -> V_103 [ 2 ] ) ;
V_104 = F_103 ( & V_196 -> V_103 [ 10 ] ) ;
if ( V_104 < 24 )
return 0 ;
V_106 = F_56 ( V_17 , V_29 , 1 ) ;
if ( V_106 )
return V_106 ;
V_243 = F_86 ( V_29 , & V_30 ) ;
memset ( V_60 , 0 , V_253 ) ;
F_26 ( 20 , & V_60 [ 0 ] ) ;
F_27 ( V_29 , & V_60 [ 8 ] ) ;
F_26 ( V_30 , & V_60 [ 16 ] ) ;
V_60 [ 20 ] = ! V_243 ;
return F_13 ( V_196 , V_60 , V_253 ) ;
}
static int F_105 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned int V_104 ;
int V_254 , V_203 , V_255 , V_30 , V_105 , V_110 , V_112 ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
int V_256 = ( int ) V_28 [ 2 ] ;
struct V_257 * V_258 ;
unsigned char V_60 [ V_259 ] ;
unsigned char * V_260 ;
V_104 = V_28 [ 9 ] + ( V_28 [ 8 ] << 8 ) + ( V_28 [ 7 ] << 16 ) + ( V_28 [ 6 ] << 24 ) ;
if ( ( V_104 < 4 ) || ( V_256 > 2 ) ) {
F_7 ( V_17 , V_114 , V_115 ,
0 ) ;
return V_55 ;
}
memset ( V_60 , 0 , V_259 ) ;
V_254 = V_261 ;
if ( 1 == V_256 )
V_254 = 0 ;
else if ( V_111 && ( V_254 > 0 ) )
-- V_254 ;
V_110 = ( V_256 > 0 ) ? 1 : 0 ;
V_30 = V_254 + V_110 ;
V_60 [ 2 ] = ( ( sizeof( struct V_257 ) * V_30 ) >> 8 ) & 0xff ;
V_60 [ 3 ] = ( sizeof( struct V_257 ) * V_30 ) & 0xff ;
V_105 = F_34 ( ( int ) ( ( V_259 - 8 ) /
sizeof( struct V_257 ) ) , V_30 ) ;
if ( V_105 < V_30 ) {
V_110 = 0 ;
V_254 = V_105 ;
}
V_258 = (struct V_257 * ) & V_60 [ 8 ] ;
V_260 = V_60 + V_259 ;
for ( V_203 = 0 , V_112 = ( V_111 ? 1 : 0 ) ;
( ( V_203 < V_254 ) && ( ( unsigned char * ) ( V_258 + V_203 ) < V_260 ) ) ;
V_203 ++ , V_112 ++ ) {
V_255 = ( V_112 >> 8 ) & 0x3f ;
if ( V_255 )
V_258 [ V_203 ] . V_257 [ 0 ] =
( V_255 | ( V_262 << 6 ) ) ;
V_258 [ V_203 ] . V_257 [ 1 ] = V_112 & 0xff ;
}
if ( V_110 ) {
V_258 [ V_203 ] . V_257 [ 0 ] = ( V_15 >> 8 ) & 0xff ;
V_258 [ V_203 ] . V_257 [ 1 ] = V_15 & 0xff ;
V_203 ++ ;
}
V_104 = ( unsigned char * ) ( V_258 + V_203 ) - V_60 ;
return F_13 ( V_59 , V_60 ,
F_34 ( ( int ) V_104 , V_259 ) ) ;
}
static int F_106 ( struct V_49 * V_59 , unsigned long long V_29 ,
unsigned int V_30 , struct V_16 * V_17 )
{
int V_203 , V_234 , V_106 = - 1 ;
unsigned char * V_263 , * V_233 ;
unsigned int V_171 ;
struct V_204 * V_264 ;
struct V_63 * V_64 = F_14 ( V_59 ) ;
V_233 = F_101 ( F_17 ( V_59 ) , V_108 ) ;
if ( ! V_233 )
return V_106 ;
F_19 ( V_59 , V_233 , F_17 ( V_59 ) ) ;
V_171 = 0 ;
F_107 (sdb->table.sgl, sg, sdb->table.nents, i) {
V_263 = ( unsigned char * ) F_68 ( F_69 ( V_264 ) ) ;
if ( ! V_263 )
goto V_239;
for ( V_234 = 0 ; V_234 < V_264 -> V_65 ; V_234 ++ )
* ( V_263 + V_264 -> V_171 + V_234 ) ^= * ( V_233 + V_171 + V_234 ) ;
V_171 += V_264 -> V_65 ;
F_70 ( V_263 ) ;
}
V_106 = 0 ;
V_239:
F_32 ( V_233 ) ;
return V_106 ;
}
static void F_108 ( unsigned long V_265 )
{
struct V_266 * V_267 ;
unsigned long V_222 ;
if ( V_265 >= V_268 ) {
F_9 ( V_215 L_27
L_28 ) ;
return;
}
F_109 ( & V_269 , V_222 ) ;
V_267 = & V_270 [ ( int ) V_265 ] ;
if ( ! V_267 -> V_271 ) {
F_9 ( V_215 L_29
L_30 ) ;
F_110 ( & V_269 , V_222 ) ;
return;
}
V_267 -> V_271 = 0 ;
if ( V_267 -> V_272 ) {
V_267 -> V_273 -> V_274 = V_267 -> V_275 ;
V_267 -> V_272 ( V_267 -> V_273 ) ;
}
V_267 -> V_272 = NULL ;
F_110 ( & V_269 , V_222 ) ;
}
static struct V_16 *
F_111 ( struct V_5 * V_6 , T_5 V_276 )
{
struct V_16 * V_17 ;
V_17 = F_31 ( sizeof( * V_17 ) , V_276 ) ;
if ( V_17 ) {
V_17 -> V_6 = V_6 ;
F_112 ( & V_17 -> V_277 , & V_6 -> V_278 ) ;
}
return V_17 ;
}
static struct V_16 * F_113 ( struct V_45 * V_279 )
{
struct V_5 * V_6 ;
struct V_16 * V_280 = NULL ;
struct V_16 * V_17 =
(struct V_16 * ) V_279 -> V_281 ;
if ( V_17 )
return V_17 ;
V_6 = * (struct V_5 * * ) F_114 ( V_279 -> V_282 ) ;
if ( ! V_6 ) {
F_9 ( V_215 L_31 ) ;
return NULL ;
}
F_5 (devip, &sdbg_host->dev_info_list, dev_list) {
if ( ( V_17 -> V_283 ) && ( V_17 -> V_120 == V_279 -> V_120 ) &&
( V_17 -> V_101 == V_279 -> V_284 ) &&
( V_17 -> V_112 == V_279 -> V_112 ) )
return V_17 ;
else {
if ( ( ! V_17 -> V_283 ) && ( ! V_280 ) )
V_280 = V_17 ;
}
}
if ( ! V_280 ) {
V_280 = F_111 ( V_6 , V_108 ) ;
if ( ! V_280 ) {
F_9 ( V_215 L_32 ,
V_216 , __LINE__ ) ;
return NULL ;
}
}
V_280 -> V_120 = V_279 -> V_120 ;
V_280 -> V_101 = V_279 -> V_284 ;
V_280 -> V_112 = V_279 -> V_112 ;
V_280 -> V_6 = V_6 ;
V_280 -> V_52 = 1 ;
V_280 -> V_283 = 1 ;
memset ( V_280 -> V_22 , 0 , V_23 ) ;
if ( V_24 )
V_280 -> V_22 [ 0 ] = 0x72 ;
else {
V_280 -> V_22 [ 0 ] = 0x70 ;
V_280 -> V_22 [ 7 ] = 0xa ;
}
if ( V_279 -> V_112 == V_15 )
V_280 -> V_110 = V_15 & 0xff ;
return V_280 ;
}
static int F_115 ( struct V_45 * V_285 )
{
if ( V_25 & V_26 )
F_9 ( V_27 L_33 ,
V_285 -> V_282 -> V_119 , V_285 -> V_120 , V_285 -> V_284 , V_285 -> V_112 ) ;
F_116 ( V_286 , V_285 -> V_287 ) ;
return 0 ;
}
static int F_117 ( struct V_45 * V_285 )
{
struct V_16 * V_17 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_34 ,
V_285 -> V_282 -> V_119 , V_285 -> V_120 , V_285 -> V_284 , V_285 -> V_112 ) ;
if ( V_285 -> V_282 -> V_288 != V_289 )
V_285 -> V_282 -> V_288 = V_289 ;
V_17 = F_113 ( V_285 ) ;
if ( NULL == V_17 )
return 1 ;
V_285 -> V_281 = V_17 ;
if ( V_285 -> V_282 -> V_290 )
F_118 ( V_285 , V_291 ,
V_285 -> V_282 -> V_290 ) ;
F_119 ( V_285 -> V_287 , 256 * 1024 ) ;
if ( V_292 )
V_285 -> V_293 = 1 ;
return 0 ;
}
static void F_120 ( struct V_45 * V_285 )
{
struct V_16 * V_17 =
(struct V_16 * ) V_285 -> V_281 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_35 ,
V_285 -> V_282 -> V_119 , V_285 -> V_120 , V_285 -> V_284 , V_285 -> V_112 ) ;
if ( V_17 ) {
V_17 -> V_283 = 0 ;
V_285 -> V_281 = NULL ;
}
}
static int F_121 ( struct V_49 * V_103 )
{
unsigned long V_222 ;
int V_141 ;
struct V_266 * V_267 ;
F_109 ( & V_269 , V_222 ) ;
for ( V_141 = 0 ; V_141 < V_268 ; ++ V_141 ) {
V_267 = & V_270 [ V_141 ] ;
if ( V_267 -> V_271 && ( V_103 == V_267 -> V_273 ) ) {
F_122 ( & V_267 -> V_294 ) ;
V_267 -> V_271 = 0 ;
V_267 -> V_273 = NULL ;
break;
}
}
F_110 ( & V_269 , V_222 ) ;
return ( V_141 < V_268 ) ? 1 : 0 ;
}
static void F_123 ( void )
{
unsigned long V_222 ;
int V_141 ;
struct V_266 * V_267 ;
F_109 ( & V_269 , V_222 ) ;
for ( V_141 = 0 ; V_141 < V_268 ; ++ V_141 ) {
V_267 = & V_270 [ V_141 ] ;
if ( V_267 -> V_271 && V_267 -> V_273 ) {
F_122 ( & V_267 -> V_294 ) ;
V_267 -> V_271 = 0 ;
V_267 -> V_273 = NULL ;
}
}
F_110 ( & V_269 , V_222 ) ;
}
static int F_124 ( struct V_49 * V_50 )
{
if ( V_25 & V_26 )
F_9 ( V_27 L_36 ) ;
++ V_295 ;
F_121 ( V_50 ) ;
return V_296 ;
}
static int F_125 ( struct V_45 * V_279 ,
struct V_297 * V_298 , T_1 V_299 , int * V_300 )
{
int V_185 ;
unsigned char * V_233 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_37 ) ;
V_233 = F_126 ( V_298 ) ;
if ( V_233 ) {
V_185 = F_127 ( V_233 , V_299 ,
& V_300 [ 2 ] , & V_300 [ 0 ] , & V_300 [ 1 ] ) ;
F_32 ( V_233 ) ;
if ( ! V_185 )
return V_185 ;
}
V_300 [ 0 ] = V_301 ;
V_300 [ 1 ] = V_153 ;
V_300 [ 2 ] = V_302 ;
return 0 ;
}
static int F_128 ( struct V_49 * V_50 )
{
struct V_16 * V_17 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_38 ) ;
++ V_303 ;
if ( V_50 ) {
V_17 = F_113 ( V_50 -> V_304 ) ;
if ( V_17 )
V_17 -> V_52 = 1 ;
}
return V_296 ;
}
static int F_129 ( struct V_49 * V_50 )
{
struct V_5 * V_6 ;
struct V_16 * V_305 ;
struct V_45 * V_285 ;
struct V_7 * V_306 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_39 ) ;
++ V_307 ;
if ( V_50 && ( ( V_285 = V_50 -> V_304 ) ) && ( ( V_306 = V_285 -> V_282 ) ) ) {
V_6 = * (struct V_5 * * ) F_114 ( V_306 ) ;
if ( V_6 ) {
F_5 (dev_info,
&sdbg_host->dev_info_list,
dev_list)
V_305 -> V_52 = 1 ;
}
}
return V_296 ;
}
static int F_130 ( struct V_49 * V_50 )
{
struct V_5 * V_6 ;
struct V_16 * V_305 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_40 ) ;
++ V_308 ;
F_4 ( & V_9 ) ;
F_5 (sdbg_host, &sdebug_host_list, host_list) {
F_5 (dev_info, &sdbg_host->dev_info_list,
dev_list)
V_305 -> V_52 = 1 ;
}
F_6 ( & V_9 ) ;
F_123 () ;
return V_296 ;
}
static void T_6 F_131 ( void )
{
unsigned long V_222 ;
int V_141 ;
struct V_266 * V_267 ;
F_109 ( & V_269 , V_222 ) ;
for ( V_141 = 0 ; V_141 < V_268 ; ++ V_141 ) {
V_267 = & V_270 [ V_141 ] ;
F_132 ( & V_267 -> V_294 ) ;
V_267 -> V_271 = 0 ;
V_267 -> V_273 = NULL ;
}
F_110 ( & V_269 , V_222 ) ;
}
static void T_6 F_133 ( unsigned char * V_309 ,
unsigned long V_310 )
{
struct V_311 * V_312 ;
int V_313 [ V_314 + 2 ] ;
int V_315 , V_316 , V_141 ;
int V_317 , V_201 , V_318 ;
if ( ( V_319 < 1 ) || ( V_310 < 1048576 ) )
return;
if ( V_319 > V_314 ) {
V_319 = V_314 ;
F_9 ( V_320 L_41
L_42 , V_314 ) ;
}
V_316 = ( int ) V_93 ;
V_315 = ( V_316 - V_153 )
/ V_319 ;
V_317 = V_301 * V_153 ;
V_313 [ 0 ] = V_153 ;
for ( V_141 = 1 ; V_141 < V_319 ; ++ V_141 )
V_313 [ V_141 ] = ( ( V_141 * V_315 ) / V_317 )
* V_317 ;
V_313 [ V_319 ] = V_316 ;
V_313 [ V_319 + 1 ] = 0 ;
V_309 [ 510 ] = 0x55 ;
V_309 [ 511 ] = 0xAA ;
V_312 = (struct V_311 * ) ( V_309 + 0x1be ) ;
for ( V_141 = 0 ; V_313 [ V_141 + 1 ] ; ++ V_141 , ++ V_312 ) {
V_201 = V_313 [ V_141 ] ;
V_318 = V_313 [ V_141 + 1 ] - 1 ;
V_312 -> V_321 = 0 ;
V_312 -> V_322 = V_201 / V_317 ;
V_312 -> V_323 = ( V_201 - ( V_312 -> V_322 * V_317 ) )
/ V_153 ;
V_312 -> V_4 = ( V_201 % V_153 ) + 1 ;
V_312 -> V_324 = V_318 / V_317 ;
V_312 -> V_325 = ( V_318 - ( V_312 -> V_324 * V_317 ) )
/ V_153 ;
V_312 -> V_326 = ( V_318 % V_153 ) + 1 ;
V_312 -> V_327 = V_201 ;
V_312 -> V_328 = V_318 - V_201 + 1 ;
V_312 -> V_329 = 0x83 ;
}
}
static int F_134 ( struct V_49 * V_103 ,
struct V_16 * V_17 ,
T_7 V_330 , int V_275 , int V_331 )
{
if ( ( V_25 & V_26 ) && V_103 ) {
if ( V_275 ) {
struct V_45 * V_285 = V_103 -> V_304 ;
F_9 ( V_27 L_43
L_44 , V_285 -> V_282 -> V_119 ,
V_285 -> V_120 , V_285 -> V_284 , V_285 -> V_112 , V_275 ) ;
}
}
if ( V_103 && V_17 ) {
if ( V_332 == ( V_275 & 0xff ) )
memcpy ( V_103 -> V_333 , V_17 -> V_22 ,
( V_334 > V_23 ) ?
V_23 : V_334 ) ;
}
if ( V_331 <= 0 ) {
if ( V_103 )
V_103 -> V_274 = V_275 ;
if ( V_330 )
V_330 ( V_103 ) ;
return 0 ;
} else {
unsigned long V_222 ;
int V_141 ;
struct V_266 * V_267 = NULL ;
F_109 ( & V_269 , V_222 ) ;
for ( V_141 = 0 ; V_141 < V_268 ; ++ V_141 ) {
V_267 = & V_270 [ V_141 ] ;
if ( ! V_267 -> V_271 )
break;
}
if ( V_141 >= V_268 ) {
F_110 ( & V_269 , V_222 ) ;
F_9 ( V_320 L_45 ) ;
return 1 ;
}
V_267 -> V_271 = 1 ;
V_267 -> V_273 = V_103 ;
V_267 -> V_275 = V_275 ;
V_267 -> V_272 = V_330 ;
V_267 -> V_294 . V_335 = F_108 ;
V_267 -> V_294 . V_336 = V_141 ;
V_267 -> V_294 . V_337 = V_338 + V_331 ;
F_135 ( & V_267 -> V_294 ) ;
F_110 ( & V_269 , V_222 ) ;
if ( V_103 )
V_103 -> V_274 = 0 ;
return 0 ;
}
}
static const char * F_136 ( struct V_7 * V_339 )
{
sprintf ( V_340 , L_46
L_47 , V_341 ,
V_342 , V_343 ,
V_26 ) ;
return V_340 ;
}
static int F_137 ( struct V_7 * V_282 , char * V_344 , int V_65 )
{
char V_60 [ 16 ] ;
int V_345 ;
int V_346 = V_65 > 15 ? 15 : V_65 ;
if ( ! F_138 ( V_347 ) || ! F_138 ( V_348 ) )
return - V_349 ;
memcpy ( V_60 , V_344 , V_346 ) ;
V_60 [ V_346 ] = '\0' ;
if ( 1 != sscanf ( V_60 , L_12 , & V_345 ) )
return - V_48 ;
V_26 = V_345 ;
if ( V_350 != 0 )
V_351 = 0 ;
return V_65 ;
}
static int F_139 ( struct V_352 * V_353 , struct V_7 * V_282 )
{
F_140 ( V_353 , L_48
L_49
L_50
L_51
L_52
L_53
L_54
L_55 ,
V_341 , V_342 , V_12 ,
V_343 , V_26 , V_350 ,
V_351 , V_354 ,
V_261 , V_125 ,
V_136 , V_302 , V_301 ,
V_153 , V_295 , V_303 , V_307 ,
V_308 , V_221 , V_240 , V_217 ) ;
return 0 ;
}
static T_8 F_141 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_354 ) ;
}
static T_8 F_142 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_359 ;
char V_360 [ 20 ] ;
if ( 1 == sscanf ( V_233 , L_57 , V_360 ) ) {
if ( ( 1 == sscanf ( V_360 , L_12 , & V_359 ) ) && ( V_359 >= 0 ) ) {
V_354 = V_359 ;
return V_358 ;
}
}
return - V_48 ;
}
static T_8 F_143 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_58 , V_26 ) ;
}
static T_8 F_144 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_345 ;
char V_360 [ 20 ] ;
if ( 1 == sscanf ( V_233 , L_57 , V_360 ) ) {
if ( 0 == F_145 ( V_360 , L_59 , 2 ) ) {
if ( 1 == sscanf ( & V_360 [ 2 ] , L_60 , & V_345 ) )
goto V_361;
} else {
if ( 1 == sscanf ( V_360 , L_12 , & V_345 ) )
goto V_361;
}
}
return - V_48 ;
V_361:
V_26 = V_345 ;
V_351 = 0 ;
return V_358 ;
}
static T_8 F_146 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_113 ) ;
}
static T_8 F_147 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_105 ;
if ( ( V_358 > 0 ) && ( 1 == sscanf ( V_233 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_113 = V_105 ;
return V_358 ;
}
return - V_48 ;
}
static T_8 F_148 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_24 ) ;
}
static T_8 F_149 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_105 ;
if ( ( V_358 > 0 ) && ( 1 == sscanf ( V_233 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_24 = V_105 ;
return V_358 ;
}
return - V_48 ;
}
static T_8 F_150 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_362 ) ;
}
static T_8 F_151 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_105 ;
if ( ( V_358 > 0 ) && ( 1 == sscanf ( V_233 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_362 = V_105 ;
return V_358 ;
}
return - V_48 ;
}
static T_8 F_152 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_111 ) ;
}
static T_8 F_153 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_105 ;
if ( ( V_358 > 0 ) && ( 1 == sscanf ( V_233 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_111 = V_105 ;
return V_358 ;
}
return - V_48 ;
}
static T_8 F_154 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_12 ) ;
}
static T_8 F_155 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_105 ;
if ( ( V_358 > 0 ) && ( 1 == sscanf ( V_233 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_12 = V_105 ;
F_3 () ;
return V_358 ;
}
return - V_48 ;
}
static T_8 F_156 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_343 ) ;
}
static T_8 F_157 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_319 ) ;
}
static T_8 F_158 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_350 ) ;
}
static T_8 F_159 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_363 ;
if ( ( V_358 > 0 ) && ( 1 == sscanf ( V_233 , L_12 , & V_363 ) ) ) {
V_350 = V_363 ;
V_351 = 0 ;
return V_358 ;
}
return - V_48 ;
}
static T_8 F_160 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_261 ) ;
}
static T_8 F_161 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_105 ;
if ( ( V_358 > 0 ) && ( 1 == sscanf ( V_233 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_261 = V_105 ;
F_3 () ;
return V_358 ;
}
return - V_48 ;
}
static T_8 F_162 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_268 ) ;
}
static T_8 F_163 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_105 ;
if ( ( V_358 > 0 ) && ( 1 == sscanf ( V_233 , L_12 , & V_105 ) ) && ( V_105 > 0 ) &&
( V_105 <= V_364 ) ) {
V_268 = V_105 ;
return V_358 ;
}
return - V_48 ;
}
static T_8 F_164 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_292 ) ;
}
static T_8 F_165 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_125 ) ;
}
static T_8 F_166 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_135 ) ;
}
static T_8 F_167 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_105 ;
if ( ( V_358 > 0 ) && ( 1 == sscanf ( V_233 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_135 = V_105 ;
V_139 = F_37 () ;
return V_358 ;
}
return - V_48 ;
}
static T_8 F_168 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_365 ) ;
}
static T_8 F_169 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_366 ;
if ( sscanf ( V_233 , L_12 , & V_366 ) != 1 )
return - V_48 ;
if ( V_366 > 0 ) {
do {
F_170 () ;
} while ( -- V_366 );
} else if ( V_366 < 0 ) {
do {
F_171 () ;
} while ( ++ V_366 );
}
return V_358 ;
}
static T_8 F_172 ( struct V_355 * V_356 ,
char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_121 ) ;
}
static T_8 F_173 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_105 ;
if ( ( V_358 > 0 ) && ( 1 == sscanf ( V_233 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_121 = V_105 ;
return V_358 ;
}
return - V_48 ;
}
static T_8 F_174 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_61 , V_136 ) ;
}
static T_8 F_175 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_228 ) ;
}
static T_8 F_176 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_122 ) ;
}
static T_8 F_177 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_213 ) ;
}
static T_8 F_178 ( struct V_355 * V_356 , char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_158 ) ;
}
static T_8 F_179 ( struct V_355 * V_356 , char * V_233 )
{
T_8 V_358 ;
if ( ! F_1 () )
return F_33 ( V_233 , V_357 , L_62 ,
V_93 ) ;
V_358 = F_180 ( V_233 , V_357 , V_245 , V_246 ) ;
V_233 [ V_358 ++ ] = '\n' ;
V_233 [ V_358 ++ ] = 0 ;
return V_358 ;
}
static T_8 F_181 ( struct V_355 * V_356 ,
char * V_233 )
{
return F_33 ( V_233 , V_357 , L_56 , V_124 ? 1 : 0 ) ;
}
static T_8 F_182 ( struct V_355 * V_356 ,
const char * V_233 , T_9 V_358 )
{
int V_105 ;
if ( ( V_358 > 0 ) && ( 1 == sscanf ( V_233 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_124 = ( V_105 > 0 ) ;
return V_358 ;
}
return - V_48 ;
}
static int F_183 ( void )
{
int V_106 ;
V_106 = F_184 ( & V_367 , & V_368 ) ;
V_106 |= F_184 ( & V_367 , & V_369 ) ;
V_106 |= F_184 ( & V_367 , & V_370 ) ;
V_106 |= F_184 ( & V_367 , & V_371 ) ;
V_106 |= F_184 ( & V_367 , & V_372 ) ;
V_106 |= F_184 ( & V_367 , & V_373 ) ;
V_106 |= F_184 ( & V_367 , & V_374 ) ;
V_106 |= F_184 ( & V_367 , & V_375 ) ;
V_106 |= F_184 ( & V_367 , & V_376 ) ;
V_106 |= F_184 ( & V_367 , & V_377 ) ;
V_106 |= F_184 ( & V_367 , & V_378 ) ;
V_106 |= F_184 ( & V_367 , & V_379 ) ;
V_106 |= F_184 ( & V_367 , & V_380 ) ;
V_106 |= F_184 ( & V_367 , & V_381 ) ;
V_106 |= F_184 ( & V_367 , & V_382 ) ;
V_106 |= F_184 ( & V_367 , & V_383 ) ;
V_106 |= F_184 ( & V_367 , & V_384 ) ;
V_106 |= F_184 ( & V_367 , & V_385 ) ;
V_106 |= F_184 ( & V_367 , & V_386 ) ;
V_106 |= F_184 ( & V_367 , & V_387 ) ;
V_106 |= F_184 ( & V_367 , & V_388 ) ;
V_106 |= F_184 ( & V_367 , & V_389 ) ;
V_106 |= F_184 ( & V_367 , & V_390 ) ;
V_106 |= F_184 ( & V_367 , & V_391 ) ;
return V_106 ;
}
static void F_185 ( void )
{
F_186 ( & V_367 , & V_391 ) ;
F_186 ( & V_367 , & V_390 ) ;
F_186 ( & V_367 , & V_389 ) ;
F_186 ( & V_367 , & V_388 ) ;
F_186 ( & V_367 , & V_387 ) ;
F_186 ( & V_367 , & V_386 ) ;
F_186 ( & V_367 , & V_385 ) ;
F_186 ( & V_367 , & V_384 ) ;
F_186 ( & V_367 , & V_383 ) ;
F_186 ( & V_367 , & V_381 ) ;
F_186 ( & V_367 , & V_380 ) ;
F_186 ( & V_367 , & V_382 ) ;
F_186 ( & V_367 , & V_379 ) ;
F_186 ( & V_367 , & V_378 ) ;
F_186 ( & V_367 , & V_377 ) ;
F_186 ( & V_367 , & V_376 ) ;
F_186 ( & V_367 , & V_375 ) ;
F_186 ( & V_367 , & V_374 ) ;
F_186 ( & V_367 , & V_373 ) ;
F_186 ( & V_367 , & V_372 ) ;
F_186 ( & V_367 , & V_371 ) ;
F_186 ( & V_367 , & V_370 ) ;
F_186 ( & V_367 , & V_369 ) ;
F_186 ( & V_367 , & V_368 ) ;
}
static int T_6 F_187 ( void )
{
unsigned long V_392 ;
int V_393 ;
int V_141 ;
int V_106 ;
switch ( V_136 ) {
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_9 ( V_215 L_63 ,
V_136 ) ;
return - V_48 ;
}
switch ( V_122 ) {
case V_394 :
case V_218 :
case V_220 :
case V_123 :
break;
default:
F_9 ( V_215 L_64 ) ;
return - V_48 ;
}
if ( V_213 > 1 ) {
F_9 ( V_215 L_65 ) ;
return - V_48 ;
}
if ( V_158 > 1 ) {
F_9 ( V_215 L_66 ) ;
return - V_48 ;
}
if ( V_92 > 15 ) {
F_9 ( V_215 L_67 ,
V_92 ) ;
return - V_48 ;
}
if ( V_142 > 0x3fff ) {
F_9 ( V_215 L_68 ,
V_142 ) ;
return - V_48 ;
}
if ( V_343 < 1 )
V_343 = 1 ;
V_392 = ( unsigned long ) V_343 * 1048576 ;
V_93 = V_392 / V_136 ;
V_139 = F_37 () ;
V_301 = 8 ;
V_153 = 32 ;
if ( V_343 >= 16 )
V_301 = 32 ;
else if ( V_343 >= 256 )
V_301 = 64 ;
V_302 = ( unsigned long ) V_139 /
( V_153 * V_301 ) ;
if ( V_302 >= 1024 ) {
V_301 = 255 ;
V_153 = 63 ;
V_302 = ( unsigned long ) V_139 /
( V_153 * V_301 ) ;
}
V_200 = F_188 ( V_392 ) ;
if ( NULL == V_200 ) {
F_9 ( V_215 L_69 ) ;
return - V_395 ;
}
memset ( V_200 , 0 , V_392 ) ;
if ( V_319 > 0 )
F_133 ( V_200 , V_392 ) ;
if ( V_122 ) {
int V_396 ;
V_396 = V_93 * sizeof( struct V_206 ) ;
V_210 = F_188 ( V_396 ) ;
F_9 ( V_215 L_70 ,
V_396 , V_210 ) ;
if ( V_210 == NULL ) {
F_9 ( V_215 L_71 ) ;
V_106 = - V_395 ;
goto V_397;
}
memset ( V_210 , 0xff , V_396 ) ;
}
if ( F_1 () ) {
V_95 =
F_189 ( V_95 , 0U , 0xffffffffU ) ;
V_96 =
F_189 ( V_96 , 0U , 256U ) ;
V_98 =
F_189 ( V_98 , 1U , 0xffffffffU ) ;
if ( V_97 &&
V_98 <=
V_97 ) {
F_9 ( V_215
L_72 ,
V_216 ) ;
return - V_48 ;
}
V_246 = F_84 ( V_93 - 1 ) + 1 ;
V_245 = F_188 ( F_190 ( V_246 ) * sizeof( long ) ) ;
F_9 ( V_27 L_73 ,
V_246 ) ;
if ( V_245 == NULL ) {
F_9 ( V_215 L_74 ) ;
V_106 = - V_395 ;
goto V_397;
}
F_191 ( V_245 , V_246 ) ;
if ( V_319 )
F_91 ( 0 , 2 ) ;
}
V_398 = F_192 ( L_75 ) ;
if ( F_193 ( V_398 ) ) {
F_9 ( V_320 L_76 ) ;
V_106 = F_194 ( V_398 ) ;
goto V_397;
}
V_106 = F_195 ( & V_399 ) ;
if ( V_106 < 0 ) {
F_9 ( V_320 L_77 ,
V_106 ) ;
goto V_400;
}
V_106 = F_196 ( & V_367 ) ;
if ( V_106 < 0 ) {
F_9 ( V_320 L_78 ,
V_106 ) ;
goto V_401;
}
V_106 = F_183 () ;
if ( V_106 < 0 ) {
F_9 ( V_320 L_79 ,
V_106 ) ;
goto V_402;
}
F_131 () ;
V_393 = V_365 ;
V_365 = 0 ;
for ( V_141 = 0 ; V_141 < V_393 ; V_141 ++ ) {
if ( F_170 () ) {
F_9 ( V_215 L_80
L_81 , V_141 ) ;
break;
}
}
if ( V_25 & V_26 ) {
F_9 ( V_27 L_82 ,
V_365 ) ;
}
return 0 ;
V_402:
F_185 () ;
F_197 ( & V_367 ) ;
V_401:
F_198 ( & V_399 ) ;
V_400:
F_199 ( V_398 ) ;
V_397:
if ( V_245 )
F_200 ( V_245 ) ;
if ( V_210 )
F_200 ( V_210 ) ;
F_200 ( V_200 ) ;
return V_106 ;
}
static void T_10 F_201 ( void )
{
int V_141 = V_365 ;
F_123 () ;
for (; V_141 ; V_141 -- )
F_171 () ;
F_185 () ;
F_197 ( & V_367 ) ;
F_198 ( & V_399 ) ;
F_199 ( V_398 ) ;
if ( V_210 )
F_200 ( V_210 ) ;
F_200 ( V_200 ) ;
}
static void F_202 ( struct V_304 * V_46 )
{
struct V_5 * V_6 ;
V_6 = F_203 ( V_46 ) ;
F_32 ( V_6 ) ;
}
static int F_170 ( void )
{
int V_141 , V_403 ;
int error = 0 ;
struct V_5 * V_6 ;
struct V_16 * V_404 , * V_405 ;
V_6 = F_31 ( sizeof( * V_6 ) , V_406 ) ;
if ( NULL == V_6 ) {
F_9 ( V_215 L_32 ,
V_216 , __LINE__ ) ;
return - V_395 ;
}
F_204 ( & V_6 -> V_278 ) ;
V_403 = V_12 * V_261 ;
for ( V_141 = 0 ; V_141 < V_403 ; V_141 ++ ) {
V_404 = F_111 ( V_6 , V_406 ) ;
if ( ! V_404 ) {
F_9 ( V_215 L_32 ,
V_216 , __LINE__ ) ;
error = - V_395 ;
goto V_407;
}
}
F_4 ( & V_9 ) ;
F_112 ( & V_6 -> V_408 , & V_409 ) ;
F_6 ( & V_9 ) ;
V_6 -> V_46 . V_410 = & V_399 ;
V_6 -> V_46 . V_411 = V_398 ;
V_6 -> V_46 . V_412 = & F_202 ;
F_205 ( & V_6 -> V_46 , L_83 , V_365 ) ;
error = F_206 ( & V_6 -> V_46 ) ;
if ( error )
goto V_407;
++ V_365 ;
return error ;
V_407:
F_207 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_208 ( & V_404 -> V_277 ) ;
F_32 ( V_404 ) ;
}
F_32 ( V_6 ) ;
return error ;
}
static void F_171 ( void )
{
struct V_5 * V_6 = NULL ;
F_4 ( & V_9 ) ;
if ( ! F_209 ( & V_409 ) ) {
V_6 = F_210 ( V_409 . V_413 ,
struct V_5 , V_408 ) ;
F_208 ( & V_6 -> V_408 ) ;
}
F_6 ( & V_9 ) ;
if ( ! V_6 )
return;
F_211 ( & V_6 -> V_46 ) ;
-- V_365 ;
}
static
int F_212 ( struct V_49 * V_50 , T_7 V_330 )
{
unsigned char * V_28 = ( unsigned char * ) V_50 -> V_103 ;
int V_117 , V_141 ;
unsigned int V_30 ;
unsigned long long V_29 ;
T_2 V_31 ;
int V_133 = 0 ;
int V_101 = V_50 -> V_304 -> V_284 ;
struct V_16 * V_17 = NULL ;
int V_414 = 0 ;
int V_415 = 0 ;
int V_416 = 0 ;
int V_417 = 0 ;
int V_418 = 0 ;
int V_247 = 0 ;
F_72 ( V_50 , 0 ) ;
if ( ( V_25 & V_26 ) && V_28 ) {
F_9 ( V_27 L_84 ) ;
for ( V_141 = 0 , V_117 = V_50 -> V_419 ; V_141 < V_117 ; ++ V_141 )
F_9 ( L_21 , ( int ) V_28 [ V_141 ] ) ;
F_9 ( L_22 ) ;
}
if ( V_101 == V_50 -> V_304 -> V_282 -> V_420 -> V_11 ) {
F_9 ( V_27 L_85
L_86 ) ;
return F_134 ( V_50 , NULL , V_330 ,
V_421 << 16 , 0 ) ;
}
if ( ( V_50 -> V_304 -> V_112 >= V_261 ) &&
( V_50 -> V_304 -> V_112 != V_15 ) )
return F_134 ( V_50 , NULL , V_330 ,
V_421 << 16 , 0 ) ;
V_17 = F_113 ( V_50 -> V_304 ) ;
if ( NULL == V_17 )
return F_134 ( V_50 , NULL , V_330 ,
V_421 << 16 , 0 ) ;
if ( ( V_350 != 0 ) &&
( ++ V_351 >= abs ( V_350 ) ) ) {
V_351 = 0 ;
if ( V_350 < - 1 )
V_350 = - 1 ;
if ( V_422 & V_26 )
return 0 ;
else if ( V_423 & V_26 &&
F_213 ( V_50 ) )
return 0 ;
else if ( V_424 & V_26 )
V_414 = 1 ;
else if ( V_425 & V_26 )
V_415 = 1 ;
else if ( V_426 & V_26 )
V_416 = 1 ;
else if ( V_427 & V_26 )
V_417 = 1 ;
}
if ( V_17 -> V_110 ) {
switch ( * V_28 ) {
case V_428 :
case V_429 :
case V_430 :
case V_431 :
break;
default:
if ( V_25 & V_26 )
F_9 ( V_27 L_87
L_88 , * V_28 ) ;
F_7 ( V_17 , V_114 ,
V_432 , 0 ) ;
V_133 = V_55 ;
return F_134 ( V_50 , V_17 , V_330 , V_133 ,
0 ) ;
}
}
switch ( * V_28 ) {
case V_428 :
V_418 = 1 ;
V_133 = F_30 ( V_50 , V_101 , V_17 ) ;
break;
case V_429 :
V_418 = 1 ;
V_133 = F_35 ( V_50 , V_17 ) ;
break;
case V_433 :
case V_434 :
V_133 = F_36 ( V_50 , V_17 ) ;
break;
case V_435 :
V_133 = F_12 ( V_50 , 1 , V_17 ) ;
if ( V_133 )
break;
if ( V_25 & V_26 )
F_9 ( V_27 L_89 ,
V_28 [ 4 ] ? L_90 : L_91 ) ;
break;
case V_436 :
V_133 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_430 :
V_418 = 1 ;
V_133 = F_12 ( V_50 , 0 , V_17 ) ;
break;
case V_437 :
V_133 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_438 :
V_133 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_439 :
V_133 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_440 :
V_133 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_441 :
V_133 = F_38 ( V_50 , V_17 ) ;
break;
case V_442 :
if ( V_28 [ 1 ] == V_443 )
V_133 = F_39 ( V_50 , V_17 ) ;
else if ( V_28 [ 1 ] == V_444 ) {
if ( F_1 () == 0 ) {
F_7 ( V_17 , V_114 ,
V_445 , 0 ) ;
V_133 = V_55 ;
} else
V_133 = F_104 ( V_50 , V_17 ) ;
} else {
F_7 ( V_17 , V_114 ,
V_432 , 0 ) ;
V_133 = V_55 ;
}
break;
case V_446 :
if ( V_447 != V_28 [ 1 ] ) {
F_7 ( V_17 , V_114 ,
V_432 , 0 ) ;
V_133 = V_55 ;
break;
}
V_133 = F_40 ( V_50 , V_17 ) ;
break;
case V_36 :
case V_38 :
case V_41 :
if ( V_122 == V_220 &&
V_28 [ 1 ] & 0xe0 ) {
F_7 ( V_17 , V_114 ,
V_445 , 0 ) ;
V_133 = V_55 ;
break;
}
if ( ( V_122 == V_218 ||
V_122 == V_123 ) &&
( V_28 [ 1 ] & 0xe0 ) == 0 )
F_9 ( V_215 L_92 ) ;
case V_44 :
V_448:
V_133 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_133 )
break;
if ( V_362 )
break;
F_10 ( V_28 , & V_29 , & V_30 , & V_31 ) ;
V_133 = F_71 ( V_50 , V_29 , V_30 , V_17 , V_31 ) ;
if ( V_414 && ( 0 == V_133 ) ) {
F_7 ( V_17 , V_449 ,
V_131 , 0 ) ;
V_133 = V_55 ;
} else if ( V_415 && ( 0 == V_133 ) ) {
F_7 ( V_17 , V_230 ,
V_450 , V_451 ) ;
V_133 = V_55 ;
} else if ( V_416 && ( 0 == V_133 ) ) {
F_7 ( V_17 , V_230 , 0x10 , 1 ) ;
V_133 = V_231 ;
} else if ( V_417 && ( 0 == V_133 ) ) {
F_7 ( V_17 , V_114 , 0x10 , 1 ) ;
V_133 = V_231 ;
}
break;
case V_431 :
V_418 = 1 ;
V_133 = F_105 ( V_50 , V_17 ) ;
break;
case V_452 :
V_133 = F_12 ( V_50 , 0 , V_17 ) ;
break;
case V_35 :
case V_37 :
case V_40 :
if ( V_122 == V_220 &&
V_28 [ 1 ] & 0xe0 ) {
F_7 ( V_17 , V_114 ,
V_445 , 0 ) ;
V_133 = V_55 ;
break;
}
if ( ( V_122 == V_218 ||
V_122 == V_123 ) &&
( V_28 [ 1 ] & 0xe0 ) == 0 )
F_9 ( V_215 L_92 ) ;
case V_43 :
V_197:
V_133 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_133 )
break;
if ( V_362 )
break;
F_10 ( V_28 , & V_29 , & V_30 , & V_31 ) ;
V_133 = F_95 ( V_50 , V_29 , V_30 , V_17 , V_31 ) ;
if ( V_414 && ( 0 == V_133 ) ) {
F_7 ( V_17 , V_449 ,
V_131 , 0 ) ;
V_133 = V_55 ;
} else if ( V_416 && ( 0 == V_133 ) ) {
F_7 ( V_17 , V_230 , 0x10 , 1 ) ;
V_133 = V_231 ;
} else if ( V_417 && ( 0 == V_133 ) ) {
F_7 ( V_17 , V_114 , 0x10 , 1 ) ;
V_133 = V_231 ;
}
break;
case V_34 :
case V_39 :
if ( V_28 [ 1 ] & 0x8 ) {
if ( ( * V_28 == V_34 && V_2 == 0 ) ||
( * V_28 == V_39 && V_3 == 0 ) ) {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
V_133 = V_55 ;
} else
V_247 = 1 ;
}
if ( V_133 )
break;
V_133 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_133 )
break;
F_10 ( V_28 , & V_29 , & V_30 , & V_31 ) ;
V_133 = F_98 ( V_50 , V_29 , V_30 , V_17 , V_31 , V_247 ) ;
break;
case V_453 :
V_133 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_133 )
break;
if ( V_96 == 0 || V_1 == 0 ) {
F_7 ( V_17 , V_114 ,
V_445 , 0 ) ;
V_133 = V_55 ;
} else
V_133 = F_99 ( V_50 , V_17 ) ;
break;
case V_174 :
case V_454 :
V_133 = F_50 ( V_50 , V_101 , V_17 ) ;
break;
case V_455 :
V_133 = F_52 ( V_50 , 1 , V_17 ) ;
break;
case V_456 :
V_133 = F_52 ( V_50 , 0 , V_17 ) ;
break;
case V_457 :
V_133 = F_55 ( V_50 , V_17 ) ;
break;
case V_458 :
V_418 = 1 ;
V_133 = F_12 ( V_50 , 0 , V_17 ) ;
break;
case V_459 :
V_133 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_42 :
if ( ! F_15 ( V_50 ) ) {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
V_133 = V_55 ;
break;
}
V_133 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_133 )
break;
if ( V_362 )
break;
F_10 ( V_28 , & V_29 , & V_30 , & V_31 ) ;
V_133 = F_71 ( V_50 , V_29 , V_30 , V_17 , V_31 ) ;
if ( V_133 )
break;
V_133 = F_95 ( V_50 , V_29 , V_30 , V_17 , V_31 ) ;
if ( V_133 )
break;
V_133 = F_106 ( V_50 , V_29 , V_30 , V_17 ) ;
break;
case V_32 :
if ( V_122 == V_220 ) {
if ( ( V_28 [ 10 ] & 0xe0 ) == 0 )
F_9 ( V_215
L_92 ) ;
if ( V_28 [ 9 ] == V_460 ) {
F_80 ( V_50 -> V_419 < 32 ) ;
goto V_448;
}
if ( V_28 [ 9 ] == V_461 ) {
F_80 ( V_50 -> V_419 < 32 ) ;
goto V_197;
}
}
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
V_133 = V_55 ;
break;
default:
if ( V_25 & V_26 )
F_9 ( V_27 L_93
L_94 , * V_28 ) ;
V_133 = F_12 ( V_50 , 1 , V_17 ) ;
if ( V_133 )
break;
F_7 ( V_17 , V_114 , V_432 , 0 ) ;
V_133 = V_55 ;
break;
}
return F_134 ( V_50 , V_17 , V_330 , V_133 ,
( V_418 ? 0 : V_354 ) ) ;
}
static int F_214 ( struct V_304 * V_46 )
{
int error = 0 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_462 ;
V_6 = F_203 ( V_46 ) ;
V_463 . V_464 = V_268 ;
V_8 = F_215 ( & V_463 , sizeof( V_6 ) ) ;
if ( NULL == V_8 ) {
F_9 ( V_215 L_95 , V_216 ) ;
error = - V_465 ;
return error ;
}
V_6 -> V_10 = V_8 ;
* ( (struct V_5 * * ) V_8 -> V_281 ) = V_6 ;
if ( ( V_8 -> V_11 >= 0 ) && ( V_12 > V_8 -> V_11 ) )
V_8 -> V_13 = V_12 + 1 ;
else
V_8 -> V_13 = V_12 ;
V_8 -> V_14 = V_15 ;
V_462 = 0 ;
switch ( V_122 ) {
case V_218 :
V_462 = V_466 ;
if ( V_228 )
V_462 |= V_467 ;
break;
case V_220 :
V_462 = V_468 ;
if ( V_228 )
V_462 |= V_469 ;
break;
case V_123 :
V_462 = V_470 ;
if ( V_228 )
V_462 |= V_471 ;
break;
default:
if ( V_228 )
V_462 |= V_472 ;
break;
}
F_216 ( V_8 , V_462 ) ;
F_9 ( V_27 L_96 ,
( V_462 & V_466 ) ? L_97 : L_98 ,
( V_462 & V_468 ) ? L_99 : L_98 ,
( V_462 & V_470 ) ? L_100 : L_98 ,
( V_462 & V_472 ) ? L_101 : L_98 ,
( V_462 & V_467 ) ? L_102 : L_98 ,
( V_462 & V_469 ) ? L_103 : L_98 ,
( V_462 & V_471 ) ? L_104 : L_98 ) ;
if ( V_213 == 1 )
F_217 ( V_8 , V_473 ) ;
else
F_217 ( V_8 , V_474 ) ;
error = F_218 ( V_8 , & V_6 -> V_46 ) ;
if ( error ) {
F_9 ( V_215 L_105 , V_216 ) ;
error = - V_465 ;
F_219 ( V_8 ) ;
} else
F_220 ( V_8 ) ;
return error ;
}
static int F_221 ( struct V_304 * V_46 )
{
struct V_5 * V_6 ;
struct V_16 * V_404 , * V_405 ;
V_6 = F_203 ( V_46 ) ;
if ( ! V_6 ) {
F_9 ( V_215 L_106 ,
V_216 ) ;
return - V_465 ;
}
F_222 ( V_6 -> V_10 ) ;
F_207 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_208 ( & V_404 -> V_277 ) ;
F_32 ( V_404 ) ;
}
F_219 ( V_6 -> V_10 ) ;
return 0 ;
}
static int F_223 ( struct V_304 * V_46 ,
struct V_355 * V_475 )
{
return 1 ;
}
