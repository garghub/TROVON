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
V_60 [ 1 ] = F_35 ( V_101 ) ? 0x80 : 0 ;
V_60 [ 2 ] = V_124 ;
V_60 [ 3 ] = 2 ;
V_60 [ 4 ] = V_125 - 5 ;
V_60 [ 5 ] = V_122 ? 1 : 0 ;
if ( 0 == V_121 )
V_60 [ 5 ] = 0x10 ;
V_60 [ 6 ] = 0x10 ;
V_60 [ 7 ] = 0xa ;
memcpy ( & V_60 [ 8 ] , V_81 , 8 ) ;
memcpy ( & V_60 [ 16 ] , V_82 , 16 ) ;
memcpy ( & V_60 [ 32 ] , V_126 , 4 ) ;
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
F_34 ( V_104 , V_125 ) ) ;
F_32 ( V_60 ) ;
return V_106 ;
}
static int F_36 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char * V_21 ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
unsigned char V_60 [ V_23 ] ;
int V_127 ;
int V_117 = 18 ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
if ( V_17 -> V_52 == 1 )
F_7 ( V_17 , 0 , V_128 , 0 ) ;
V_127 = ! ! ( V_28 [ 1 ] & 1 ) || V_24 ;
V_21 = V_17 -> V_22 ;
if ( ( V_129 [ 2 ] & 0x4 ) && ( 6 == ( V_129 [ 3 ] & 0xf ) ) ) {
if ( V_127 ) {
V_60 [ 0 ] = 0x72 ;
V_60 [ 1 ] = 0x0 ;
V_60 [ 2 ] = V_130 ;
V_60 [ 3 ] = 0xff ;
} else {
V_60 [ 0 ] = 0x70 ;
V_60 [ 2 ] = 0x0 ;
V_60 [ 7 ] = 0xa ;
V_60 [ 12 ] = V_130 ;
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
F_7 ( V_17 , 0 , V_128 , 0 ) ;
return F_13 ( V_59 , V_60 , V_117 ) ;
}
static int F_37 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
int V_131 , V_132 , V_133 ;
if ( ( V_132 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_132 ;
V_131 = ( V_28 [ 4 ] & 0xf0 ) >> 4 ;
if ( V_131 ) {
F_7 ( V_17 , V_114 , V_115 ,
0 ) ;
return V_55 ;
}
V_133 = V_28 [ 4 ] & 1 ;
if ( V_133 == V_17 -> V_56 )
V_17 -> V_56 = ! V_133 ;
return 0 ;
}
static T_1 F_38 ( void )
{
if ( V_134 > 0 )
return ( T_1 ) V_134 *
( 1073741824 / V_135 ) ;
else
return V_93 ;
}
static int F_39 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char V_60 [ V_136 ] ;
unsigned int V_137 ;
int V_132 ;
if ( ( V_132 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_132 ;
V_138 = F_38 () ;
memset ( V_60 , 0 , V_136 ) ;
if ( V_138 < 0xffffffff ) {
V_137 = ( unsigned int ) V_138 - 1 ;
V_60 [ 0 ] = ( V_137 >> 24 ) ;
V_60 [ 1 ] = ( V_137 >> 16 ) & 0xff ;
V_60 [ 2 ] = ( V_137 >> 8 ) & 0xff ;
V_60 [ 3 ] = V_137 & 0xff ;
} else {
V_60 [ 0 ] = 0xff ;
V_60 [ 1 ] = 0xff ;
V_60 [ 2 ] = 0xff ;
V_60 [ 3 ] = 0xff ;
}
V_60 [ 6 ] = ( V_135 >> 8 ) & 0xff ;
V_60 [ 7 ] = V_135 & 0xff ;
return F_13 ( V_59 , V_60 , V_136 ) ;
}
static int F_40 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
unsigned char V_60 [ V_139 ] ;
unsigned long long V_137 ;
int V_132 , V_140 , V_104 ;
if ( ( V_132 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_132 ;
V_104 = ( ( V_28 [ 10 ] << 24 ) + ( V_28 [ 11 ] << 16 ) + ( V_28 [ 12 ] << 8 )
+ V_28 [ 13 ] ) ;
V_138 = F_38 () ;
memset ( V_60 , 0 , V_139 ) ;
V_137 = V_138 - 1 ;
for ( V_140 = 0 ; V_140 < 8 ; ++ V_140 , V_137 >>= 8 )
V_60 [ 7 - V_140 ] = V_137 & 0xff ;
V_60 [ 8 ] = ( V_135 >> 24 ) & 0xff ;
V_60 [ 9 ] = ( V_135 >> 16 ) & 0xff ;
V_60 [ 10 ] = ( V_135 >> 8 ) & 0xff ;
V_60 [ 11 ] = V_135 & 0xff ;
V_60 [ 13 ] = V_92 & 0xf ;
V_60 [ 14 ] = ( V_141 >> 8 ) & 0x3f ;
if ( F_1 () ) {
V_60 [ 14 ] |= 0x80 ;
if ( V_100 )
V_60 [ 14 ] |= 0x40 ;
}
V_60 [ 15 ] = V_141 & 0xff ;
if ( V_122 ) {
V_60 [ 12 ] = ( V_122 - 1 ) << 1 ;
V_60 [ 12 ] |= 1 ;
}
return F_13 ( V_59 , V_60 ,
F_34 ( V_104 , V_139 ) ) ;
}
static int F_41 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
unsigned char * V_60 ;
int V_119 = V_17 -> V_6 -> V_10 -> V_119 ;
int V_105 , V_106 , V_142 , V_143 ;
int V_144 , V_145 , V_79 , V_88 ;
V_142 = ( ( V_28 [ 6 ] << 24 ) + ( V_28 [ 7 ] << 16 ) + ( V_28 [ 8 ] << 8 )
+ V_28 [ 9 ] ) ;
V_60 = F_31 ( V_146 , V_108 ) ;
if ( ! V_60 )
return V_109 << 16 ;
V_79 = 0x1 ;
V_88 = 0x2 ;
V_144 = ( ( ( V_119 + 1 ) & 0x7f ) << 8 ) +
( V_17 -> V_120 & 0x7f ) ;
V_145 = ( ( ( V_119 + 1 ) & 0x7f ) << 8 ) +
( V_17 -> V_120 & 0x7f ) + 0x80 ;
V_105 = 4 ;
if ( 0 == V_121 ) {
V_60 [ V_105 ++ ] = V_119 % 3 ;
V_60 [ V_105 ++ ] = 0x0F ;
} else {
V_60 [ V_105 ++ ] = 0x0 ;
V_60 [ V_105 ++ ] = 0x01 ;
}
V_60 [ V_105 ++ ] = ( V_144 >> 8 ) & 0xff ;
V_60 [ V_105 ++ ] = V_144 & 0xff ;
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
V_60 [ V_105 ++ ] = ( V_145 >> 8 ) & 0xff ;
V_60 [ V_105 ++ ] = V_145 & 0xff ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = 0x1 ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = 0 ;
V_60 [ V_105 ++ ] = ( V_88 >> 8 ) & 0xff ;
V_60 [ V_105 ++ ] = V_88 & 0xff ;
V_143 = V_105 - 4 ;
V_60 [ 0 ] = ( V_143 >> 24 ) & 0xff ;
V_60 [ 1 ] = ( V_143 >> 16 ) & 0xff ;
V_60 [ 2 ] = ( V_143 >> 8 ) & 0xff ;
V_60 [ 3 ] = V_143 & 0xff ;
V_143 = F_34 ( V_142 , V_105 ) ;
V_106 = F_13 ( V_59 , V_60 ,
F_34 ( V_143 , V_146 ) ) ;
F_32 ( V_60 ) ;
return V_106 ;
}
static int F_42 ( unsigned char * V_147 , int V_148 , int V_101 )
{
unsigned char V_149 [] = { 0x1 , 0xa , 0xc0 , 11 , 240 , 0 , 0 , 0 ,
5 , 0 , 0xff , 0xff } ;
memcpy ( V_147 , V_149 , sizeof( V_149 ) ) ;
if ( 1 == V_148 )
memset ( V_147 + 2 , 0 , sizeof( V_149 ) - 2 ) ;
return sizeof( V_149 ) ;
}
static int F_43 ( unsigned char * V_147 , int V_148 , int V_101 )
{
unsigned char V_150 [] = { 0x2 , 0xe , 128 , 128 , 0 , 10 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_147 , V_150 , sizeof( V_150 ) ) ;
if ( 1 == V_148 )
memset ( V_147 + 2 , 0 , sizeof( V_150 ) - 2 ) ;
return sizeof( V_150 ) ;
}
static int F_44 ( unsigned char * V_147 , int V_148 , int V_101 )
{
unsigned char V_151 [] = { 0x3 , 0x16 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0x40 , 0 , 0 , 0 } ;
memcpy ( V_147 , V_151 , sizeof( V_151 ) ) ;
V_147 [ 10 ] = ( V_152 >> 8 ) & 0xff ;
V_147 [ 11 ] = V_152 & 0xff ;
V_147 [ 12 ] = ( V_135 >> 8 ) & 0xff ;
V_147 [ 13 ] = V_135 & 0xff ;
if ( F_35 ( V_101 ) )
V_147 [ 20 ] |= 0x20 ;
if ( 1 == V_148 )
memset ( V_147 + 2 , 0 , sizeof( V_151 ) - 2 ) ;
return sizeof( V_151 ) ;
}
static int F_45 ( unsigned char * V_147 , int V_148 , int V_101 )
{
unsigned char V_153 [] = { 0x8 , 18 , 0x14 , 0 , 0xff , 0xff , 0 , 0 ,
0xff , 0xff , 0xff , 0xff , 0x80 , 0x14 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_147 , V_153 , sizeof( V_153 ) ) ;
if ( 1 == V_148 )
memset ( V_147 + 2 , 0 , sizeof( V_153 ) - 2 ) ;
return sizeof( V_153 ) ;
}
static int F_46 ( unsigned char * V_147 , int V_148 , int V_101 )
{
unsigned char V_154 [] = { 0x6 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ;
unsigned char V_155 [] = { 0xa , 10 , 2 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x2 , 0x4b } ;
if ( V_24 )
V_156 [ 2 ] |= 0x4 ;
else
V_156 [ 2 ] &= ~ 0x4 ;
if ( V_157 )
V_156 [ 5 ] |= 0x80 ;
memcpy ( V_147 , V_156 , sizeof( V_156 ) ) ;
if ( 1 == V_148 )
memcpy ( V_147 + 2 , V_154 , sizeof( V_154 ) ) ;
else if ( 2 == V_148 )
memcpy ( V_147 , V_155 , sizeof( V_155 ) ) ;
return sizeof( V_156 ) ;
}
static int F_47 ( unsigned char * V_147 , int V_148 , int V_101 )
{
unsigned char V_158 [] = { 0x4 , 0xf , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
unsigned char V_159 [] = { 0x1c , 0xa , 0x08 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x0 , 0x0 } ;
memcpy ( V_147 , V_129 , sizeof( V_129 ) ) ;
if ( 1 == V_148 )
memcpy ( V_147 + 2 , V_158 , sizeof( V_158 ) ) ;
else if ( 2 == V_148 )
memcpy ( V_147 , V_159 , sizeof( V_159 ) ) ;
return sizeof( V_129 ) ;
}
static int F_48 ( unsigned char * V_147 , int V_148 , int V_101 )
{
unsigned char V_160 [] = { 0x19 , 0x6 ,
0x6 , 0x0 , 0x7 , 0xd0 , 0x0 , 0x0 } ;
memcpy ( V_147 , V_160 , sizeof( V_160 ) ) ;
if ( 1 == V_148 )
memset ( V_147 + 2 , 0 , sizeof( V_160 ) - 2 ) ;
return sizeof( V_160 ) ;
}
static int F_49 ( unsigned char * V_147 , int V_148 , int V_101 ,
int V_75 )
{
unsigned char V_161 [] = { 0x59 , 0x1 , 0 , 0x64 , 0 , 0x6 , 0 , 2 ,
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
memcpy ( V_147 , V_161 , sizeof( V_161 ) ) ;
V_147 [ 20 ] = ( V_79 >> 24 ) ;
V_147 [ 21 ] = ( V_79 >> 16 ) & 0xff ;
V_147 [ 22 ] = ( V_79 >> 8 ) & 0xff ;
V_147 [ 23 ] = V_79 & 0xff ;
V_147 [ 48 + 20 ] = ( V_88 >> 24 ) ;
V_147 [ 48 + 21 ] = ( V_88 >> 16 ) & 0xff ;
V_147 [ 48 + 22 ] = ( V_88 >> 8 ) & 0xff ;
V_147 [ 48 + 23 ] = V_88 & 0xff ;
if ( 1 == V_148 )
memset ( V_147 + 4 , 0 , sizeof( V_161 ) - 4 ) ;
return sizeof( V_161 ) ;
}
static int F_50 ( unsigned char * V_147 , int V_148 )
{
unsigned char V_162 [] = { 0x59 , 0x2 , 0 , 0xc , 0 , 0x6 , 0x10 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
memcpy ( V_147 , V_162 , sizeof( V_162 ) ) ;
if ( 1 == V_148 )
memset ( V_147 + 4 , 0 , sizeof( V_162 ) - 4 ) ;
return sizeof( V_162 ) ;
}
static int F_51 ( struct V_49 * V_59 , int V_101 ,
struct V_16 * V_17 )
{
unsigned char V_163 , V_164 ;
int V_148 , V_165 , V_166 , V_167 ;
unsigned char V_168 ;
int V_140 , V_104 , V_169 , V_170 , V_117 , V_132 , V_75 ;
unsigned char * V_171 ;
unsigned char V_60 [ V_172 ] ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
if ( ( V_132 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_132 ;
V_163 = ! ! ( V_28 [ 1 ] & 0x8 ) ;
V_148 = ( V_28 [ 2 ] & 0xc0 ) >> 6 ;
V_165 = V_28 [ 2 ] & 0x3f ;
V_166 = V_28 [ 3 ] ;
V_169 = ( V_173 == V_28 [ 0 ] ) ;
V_164 = V_169 ? 0 : ! ! ( V_28 [ 1 ] & 0x10 ) ;
if ( ( 0 == V_113 ) && ( 0 == V_163 ) )
V_167 = V_164 ? 16 : 8 ;
else
V_167 = 0 ;
V_104 = V_169 ? V_28 [ 4 ] : ( ( V_28 [ 7 ] << 8 ) | V_28 [ 8 ] ) ;
memset ( V_60 , 0 , V_172 ) ;
if ( 0x3 == V_148 ) {
F_7 ( V_17 , V_114 , V_174 ,
0 ) ;
return V_55 ;
}
V_75 = ( ( V_17 -> V_6 -> V_10 -> V_119 + 1 ) * 2000 ) +
( V_17 -> V_101 * 1000 ) - 3 ;
if ( 0 == V_113 )
V_168 = ( F_52 ( V_101 ) ? 0x80 : 0x0 ) | 0x10 ;
else
V_168 = 0x0 ;
if ( V_169 ) {
V_60 [ 2 ] = V_168 ;
V_60 [ 3 ] = V_167 ;
V_170 = 4 ;
} else {
V_60 [ 3 ] = V_168 ;
if ( 16 == V_167 )
V_60 [ 4 ] = 0x1 ;
V_60 [ 7 ] = V_167 ;
V_170 = 8 ;
}
V_171 = V_60 + V_170 ;
if ( ( V_167 > 0 ) && ( ! V_138 ) )
V_138 = F_38 () ;
if ( 8 == V_167 ) {
if ( V_138 > 0xfffffffe ) {
V_171 [ 0 ] = 0xff ;
V_171 [ 1 ] = 0xff ;
V_171 [ 2 ] = 0xff ;
V_171 [ 3 ] = 0xff ;
} else {
V_171 [ 0 ] = ( V_138 >> 24 ) & 0xff ;
V_171 [ 1 ] = ( V_138 >> 16 ) & 0xff ;
V_171 [ 2 ] = ( V_138 >> 8 ) & 0xff ;
V_171 [ 3 ] = V_138 & 0xff ;
}
V_171 [ 6 ] = ( V_135 >> 8 ) & 0xff ;
V_171 [ 7 ] = V_135 & 0xff ;
V_170 += V_167 ;
V_171 = V_60 + V_170 ;
} else if ( 16 == V_167 ) {
unsigned long long V_137 = V_138 ;
for ( V_140 = 0 ; V_140 < 8 ; ++ V_140 , V_137 >>= 8 )
V_171 [ 7 - V_140 ] = V_137 & 0xff ;
V_171 [ 12 ] = ( V_135 >> 24 ) & 0xff ;
V_171 [ 13 ] = ( V_135 >> 16 ) & 0xff ;
V_171 [ 14 ] = ( V_135 >> 8 ) & 0xff ;
V_171 [ 15 ] = V_135 & 0xff ;
V_170 += V_167 ;
V_171 = V_60 + V_170 ;
}
if ( ( V_166 > 0x0 ) && ( V_166 < 0xff ) && ( 0x19 != V_165 ) ) {
F_7 ( V_17 , V_114 , V_115 ,
0 ) ;
return V_55 ;
}
switch ( V_165 ) {
case 0x1 :
V_117 = F_42 ( V_171 , V_148 , V_101 ) ;
V_170 += V_117 ;
break;
case 0x2 :
V_117 = F_43 ( V_171 , V_148 , V_101 ) ;
V_170 += V_117 ;
break;
case 0x3 :
V_117 = F_44 ( V_171 , V_148 , V_101 ) ;
V_170 += V_117 ;
break;
case 0x8 :
V_117 = F_45 ( V_171 , V_148 , V_101 ) ;
V_170 += V_117 ;
break;
case 0xa :
V_117 = F_46 ( V_171 , V_148 , V_101 ) ;
V_170 += V_117 ;
break;
case 0x19 :
if ( ( V_166 > 0x2 ) && ( V_166 < 0xff ) ) {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
return V_55 ;
}
V_117 = 0 ;
if ( ( 0x0 == V_166 ) || ( 0xff == V_166 ) )
V_117 += F_48 ( V_171 + V_117 , V_148 , V_101 ) ;
if ( ( 0x1 == V_166 ) || ( 0xff == V_166 ) )
V_117 += F_49 ( V_171 + V_117 , V_148 , V_101 ,
V_75 ) ;
if ( ( 0x2 == V_166 ) || ( 0xff == V_166 ) )
V_117 += F_50 ( V_171 + V_117 , V_148 ) ;
V_170 += V_117 ;
break;
case 0x1c :
V_117 = F_47 ( V_171 , V_148 , V_101 ) ;
V_170 += V_117 ;
break;
case 0x3f :
if ( ( 0 == V_166 ) || ( 0xff == V_166 ) ) {
V_117 = F_42 ( V_171 , V_148 , V_101 ) ;
V_117 += F_43 ( V_171 + V_117 , V_148 , V_101 ) ;
V_117 += F_44 ( V_171 + V_117 , V_148 , V_101 ) ;
V_117 += F_45 ( V_171 + V_117 , V_148 , V_101 ) ;
V_117 += F_46 ( V_171 + V_117 , V_148 , V_101 ) ;
V_117 += F_48 ( V_171 + V_117 , V_148 , V_101 ) ;
if ( 0xff == V_166 ) {
V_117 += F_49 ( V_171 + V_117 , V_148 ,
V_101 , V_75 ) ;
V_117 += F_50 ( V_171 + V_117 , V_148 ) ;
}
V_117 += F_47 ( V_171 + V_117 , V_148 , V_101 ) ;
} else {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
return V_55 ;
}
V_170 += V_117 ;
break;
default:
F_7 ( V_17 , V_114 , V_115 ,
0 ) ;
return V_55 ;
}
if ( V_169 )
V_60 [ 0 ] = V_170 - 1 ;
else {
V_60 [ 0 ] = ( ( V_170 - 2 ) >> 8 ) & 0xff ;
V_60 [ 1 ] = ( V_170 - 2 ) & 0xff ;
}
return F_13 ( V_59 , V_60 , F_34 ( V_104 , V_170 ) ) ;
}
static int F_53 ( struct V_49 * V_59 , int V_175 ,
struct V_16 * V_17 )
{
int V_176 , V_177 , V_178 , V_179 , V_167 , V_180 , V_181 , V_182 ;
int V_183 , V_184 , V_132 , V_185 ;
unsigned char V_60 [ V_186 ] ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
if ( ( V_132 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_132 ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
V_176 = V_28 [ 1 ] & 0x10 ;
V_177 = V_28 [ 1 ] & 0x1 ;
V_183 = V_175 ? V_28 [ 4 ] : ( ( V_28 [ 7 ] << 8 ) + V_28 [ 8 ] ) ;
if ( ( 0 == V_176 ) || V_177 || ( V_183 > V_186 ) ) {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
return V_55 ;
}
V_184 = F_18 ( V_59 , V_60 , V_183 ) ;
if ( - 1 == V_184 )
return ( V_68 << 16 ) ;
else if ( ( V_184 < V_183 ) &&
( V_25 & V_26 ) )
F_9 ( V_27 L_13
L_14 , V_183 , V_184 ) ;
V_179 = V_175 ? ( V_60 [ 0 ] + 1 ) : ( ( V_60 [ 0 ] << 8 ) + V_60 [ 1 ] + 2 ) ;
V_167 = V_175 ? V_60 [ 3 ] : ( ( V_60 [ 6 ] << 8 ) + V_60 [ 7 ] ) ;
if ( V_179 > 2 ) {
F_7 ( V_17 , V_114 ,
V_187 , 0 ) ;
return V_55 ;
}
V_180 = V_167 + ( V_175 ? 4 : 8 ) ;
V_185 = V_60 [ V_180 ] & 0x3f ;
V_178 = ! ! ( V_60 [ V_180 ] & 0x80 ) ;
if ( V_178 ) {
F_7 ( V_17 , V_114 ,
V_187 , 0 ) ;
return V_55 ;
}
V_181 = ! ! ( V_60 [ V_180 ] & 0x40 ) ;
V_182 = V_181 ? ( ( V_60 [ V_180 + 2 ] << 8 ) + V_60 [ V_180 + 3 ] + 4 ) :
( V_60 [ V_180 + 1 ] + 2 ) ;
if ( ( V_182 + V_180 ) > V_183 ) {
F_7 ( V_17 , V_114 ,
V_188 , 0 ) ;
return V_55 ;
}
switch ( V_185 ) {
case 0xa :
if ( V_156 [ 1 ] == V_60 [ V_180 + 1 ] ) {
memcpy ( V_156 + 2 , V_60 + V_180 + 2 ,
sizeof( V_156 ) - 2 ) ;
V_24 = ! ! ( V_156 [ 2 ] & 0x4 ) ;
return 0 ;
}
break;
case 0x1c :
if ( V_129 [ 1 ] == V_60 [ V_180 + 1 ] ) {
memcpy ( V_129 + 2 , V_60 + V_180 + 2 ,
sizeof( V_129 ) - 2 ) ;
return 0 ;
}
break;
default:
break;
}
F_7 ( V_17 , V_114 ,
V_187 , 0 ) ;
return V_55 ;
}
static int F_54 ( unsigned char * V_60 )
{
unsigned char V_189 [] = { 0x0 , 0x0 , 0x3 , 0x2 , 0x0 , 38 ,
0x0 , 0x1 , 0x3 , 0x2 , 0x0 , 65 ,
} ;
memcpy ( V_60 , V_189 , sizeof( V_189 ) ) ;
return sizeof( V_189 ) ;
}
static int F_55 ( unsigned char * V_60 )
{
unsigned char V_190 [] = { 0x0 , 0x0 , 0x3 , 0x3 , 0x0 , 0x0 , 38 ,
} ;
memcpy ( V_60 , V_190 , sizeof( V_190 ) ) ;
if ( V_129 [ 2 ] & 0x4 ) {
V_60 [ 4 ] = V_130 ;
V_60 [ 5 ] = 0xff ;
}
return sizeof( V_190 ) ;
}
static int F_56 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
int V_191 , V_177 , V_148 , V_165 , V_166 , V_104 , V_132 , V_117 , V_105 ;
unsigned char V_60 [ V_192 ] ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
if ( ( V_132 = F_12 ( V_59 , 1 , V_17 ) ) )
return V_132 ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
V_191 = V_28 [ 1 ] & 0x2 ;
V_177 = V_28 [ 1 ] & 0x1 ;
if ( V_191 || V_177 ) {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
return V_55 ;
}
V_148 = ( V_28 [ 2 ] & 0xc0 ) >> 6 ;
V_165 = V_28 [ 2 ] & 0x3f ;
V_166 = V_28 [ 3 ] & 0xff ;
V_104 = ( V_28 [ 7 ] << 8 ) + V_28 [ 8 ] ;
V_60 [ 0 ] = V_165 ;
if ( 0 == V_166 ) {
switch ( V_165 ) {
case 0x0 :
V_105 = 4 ;
V_60 [ V_105 ++ ] = 0x0 ;
V_60 [ V_105 ++ ] = 0xd ;
V_60 [ V_105 ++ ] = 0x2f ;
V_60 [ 3 ] = V_105 - 4 ;
break;
case 0xd :
V_60 [ 3 ] = F_54 ( V_60 + 4 ) ;
break;
case 0x2f :
V_60 [ 3 ] = F_55 ( V_60 + 4 ) ;
break;
default:
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
return V_55 ;
}
} else if ( 0xff == V_166 ) {
V_60 [ 0 ] |= 0x40 ;
V_60 [ 1 ] = V_166 ;
switch ( V_165 ) {
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
static int F_57 ( struct V_16 * V_193 ,
unsigned long long V_29 , unsigned int V_30 )
{
if ( V_29 + V_30 > V_138 ) {
F_7 ( V_193 , V_114 , V_194 , 0 ) ;
return V_55 ;
}
if ( V_30 > V_93 ) {
F_7 ( V_193 , V_114 , V_115 , 0 ) ;
return V_55 ;
}
return 0 ;
}
static int F_58 ( struct V_49 * V_195 ,
struct V_16 * V_193 ,
unsigned long long V_29 , unsigned int V_30 , int V_196 )
{
int V_106 ;
unsigned long long V_197 , V_198 = 0 ;
int (* F_59)( struct V_49 * , unsigned char * , int );
F_59 = V_196 ? F_18 : F_13 ;
V_197 = F_60 ( V_29 , V_93 ) ;
if ( V_197 + V_30 > V_93 )
V_198 = V_197 + V_30 - V_93 ;
V_106 = F_59 ( V_195 , V_199 + ( V_197 * V_135 ) ,
( V_30 - V_198 ) * V_135 ) ;
if ( ! V_106 && V_198 )
V_106 = F_59 ( V_195 , V_199 , V_198 * V_135 ) ;
return V_106 ;
}
static int F_61 ( struct V_49 * V_50 , T_1 V_200 ,
unsigned int V_201 , T_2 V_31 )
{
unsigned int V_202 , V_72 ;
struct V_203 * V_204 ;
struct V_205 * V_206 ;
T_1 V_4 ;
T_1 V_207 = V_200 ;
void * V_208 ;
V_200 = F_60 ( V_207 , V_93 ) ;
V_206 = (struct V_205 * ) ( V_209 + F_2 ( V_200 ) ) ;
for ( V_202 = 0 ; V_202 < V_201 ; V_202 ++ ) {
T_4 V_210 ;
if ( V_206 [ V_202 ] . V_211 == 0xffff )
continue;
V_4 = V_200 + V_202 ;
switch ( V_212 ) {
case 1 :
V_210 = F_62 ( V_199 +
V_4 * V_135 ,
V_135 ) ;
break;
case 0 :
V_210 = F_63 ( V_199 +
V_4 * V_135 ,
V_135 ) ;
V_210 = F_64 ( V_210 ) ;
break;
default:
F_65 () ;
}
if ( V_206 [ V_202 ] . V_213 != V_210 ) {
F_9 ( V_214 L_15 \
L_16 , V_215 ,
( unsigned long ) V_4 ,
F_66 ( V_206 [ V_202 ] . V_213 ) ,
F_66 ( V_210 ) ) ;
V_216 ++ ;
return 0x01 ;
}
if ( V_122 == V_217 &&
F_67 ( V_206 [ V_202 ] . V_218 ) != ( V_4 & 0xffffffff ) ) {
F_9 ( V_214 L_17 ,
V_215 , ( unsigned long ) V_4 ) ;
V_216 ++ ;
return 0x03 ;
}
if ( V_122 == V_219 &&
F_67 ( V_206 [ V_202 ] . V_218 ) != V_31 ) {
F_9 ( V_214 L_17 ,
V_215 , ( unsigned long ) V_4 ) ;
V_216 ++ ;
return 0x03 ;
}
V_31 ++ ;
}
V_72 = V_201 * 8 ;
V_4 = V_200 ;
F_68 (SCpnt, psgl, scsi_prot_sg_count(SCpnt), i) {
int V_117 = F_34 ( V_204 -> V_65 , V_72 ) ;
V_208 = F_69 ( F_70 ( V_204 ) ) + V_204 -> V_170 ;
memcpy ( V_208 , V_209 + F_2 ( V_4 ) , V_117 ) ;
V_4 += V_117 >> 3 ;
if ( V_4 >= V_93 ) {
V_207 = V_4 ;
V_4 = F_60 ( V_207 , V_93 ) ;
}
V_72 -= V_117 ;
F_71 ( V_208 ) ;
}
V_220 ++ ;
return 0 ;
}
static int F_72 ( struct V_49 * V_50 , unsigned long long V_29 ,
unsigned int V_30 , struct V_16 * V_17 ,
T_2 V_31 )
{
unsigned long V_221 ;
int V_106 ;
V_106 = F_57 ( V_17 , V_29 , V_30 ) ;
if ( V_106 )
return V_106 ;
if ( ( V_222 & V_26 ) &&
( V_29 <= ( V_223 + V_224 - 1 ) ) &&
( ( V_29 + V_30 ) > V_223 ) ) {
F_7 ( V_17 , V_225 , V_226 , 0 ) ;
if ( 0x70 == ( V_17 -> V_22 [ 0 ] & 0x7f ) ) {
V_17 -> V_22 [ 0 ] |= 0x80 ;
V_106 = ( V_29 < V_223 )
? V_223 : ( int ) V_29 ;
V_17 -> V_22 [ 3 ] = ( V_106 >> 24 ) & 0xff ;
V_17 -> V_22 [ 4 ] = ( V_106 >> 16 ) & 0xff ;
V_17 -> V_22 [ 5 ] = ( V_106 >> 8 ) & 0xff ;
V_17 -> V_22 [ 6 ] = V_106 & 0xff ;
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
V_106 = F_58 ( V_50 , V_17 , V_29 , V_30 , 0 ) ;
F_76 ( & V_231 , V_221 ) ;
return V_106 ;
}
void F_77 ( unsigned char * V_232 , int V_117 )
{
int V_202 , V_233 ;
F_9 ( V_214 L_18 ) ;
for ( V_202 = 0 ; V_202 < V_117 ; V_202 += 16 ) {
F_9 ( V_214 L_19 , V_202 ) ;
for ( V_233 = 0 ; V_233 < 16 ; V_233 ++ ) {
unsigned char V_234 = V_232 [ V_202 + V_233 ] ;
if ( V_234 >= 0x20 && V_234 < 0x7e )
F_9 ( L_20 , V_232 [ V_202 + V_233 ] ) ;
else
F_9 ( L_21 , V_232 [ V_202 + V_233 ] ) ;
}
F_9 ( L_22 ) ;
}
}
static int F_78 ( struct V_49 * V_50 , T_1 V_200 ,
unsigned int V_201 , T_2 V_31 )
{
int V_202 , V_233 , V_106 ;
struct V_205 * V_206 ;
struct V_203 * V_235 = F_79 ( V_50 ) ;
struct V_203 * V_204 = F_80 ( V_50 ) ;
void * V_236 , * V_208 ;
T_1 V_207 = V_200 ;
T_1 V_4 ;
int V_237 ;
unsigned short V_210 ;
V_4 = F_60 ( V_207 , V_93 ) ;
F_81 ( F_82 ( V_50 ) == 0 ) ;
F_81 ( F_74 ( V_50 ) == 0 ) ;
V_208 = F_69 ( F_70 ( V_204 ) ) + V_204 -> V_170 ;
V_237 = 0 ;
F_83 (SCpnt, dsgl, scsi_sg_count(SCpnt), i) {
V_236 = F_69 ( F_70 ( V_235 ) ) + V_235 -> V_170 ;
for ( V_233 = 0 ; V_233 < V_235 -> V_65 ; V_233 += V_135 ) {
if ( V_237 >= V_204 -> V_65 ) {
F_71 ( V_208 ) ;
V_204 = F_84 ( V_204 ) ;
F_81 ( V_204 == NULL ) ;
V_208 = F_69 ( F_70 ( V_204 ) )
+ V_204 -> V_170 ;
V_237 = 0 ;
}
V_206 = V_208 + V_237 ;
switch ( V_212 ) {
case 1 :
V_210 = F_62 ( V_236 ,
V_135 ) ;
break;
case 0 :
V_210 = F_64 ( F_63 ( V_236 ,
V_135 ) ) ;
break;
default:
F_65 () ;
V_106 = 0 ;
goto V_238;
}
if ( V_206 -> V_213 != V_210 ) {
F_9 ( V_214
L_23 \
L_24 ,
V_215 , ( unsigned long ) V_4 ,
F_66 ( V_206 -> V_213 ) ,
F_66 ( V_210 ) ) ;
V_106 = 0x01 ;
F_77 ( V_236 , V_135 ) ;
goto V_238;
}
if ( V_122 == V_217 &&
F_67 ( V_206 -> V_218 )
!= ( V_200 & 0xffffffff ) ) {
F_9 ( V_214
L_17 ,
V_215 , ( unsigned long ) V_4 ) ;
V_106 = 0x03 ;
F_77 ( V_236 , V_135 ) ;
goto V_238;
}
if ( V_122 == V_219 &&
F_67 ( V_206 -> V_218 ) != V_31 ) {
F_9 ( V_214
L_17 ,
V_215 , ( unsigned long ) V_4 ) ;
V_106 = 0x03 ;
F_77 ( V_236 , V_135 ) ;
goto V_238;
}
memcpy ( V_209 + F_2 ( V_4 ) , V_206 , 8 ) ;
V_4 ++ ;
if ( V_4 == V_93 )
V_4 = 0 ;
V_200 ++ ;
V_31 ++ ;
V_236 += V_135 ;
V_237 += sizeof( struct V_205 ) ;
}
F_71 ( V_236 ) ;
}
F_71 ( V_208 ) ;
V_239 ++ ;
return 0 ;
V_238:
V_216 ++ ;
F_71 ( V_236 ) ;
F_71 ( V_208 ) ;
return V_106 ;
}
static unsigned int F_85 ( T_1 V_29 , unsigned int * V_30 )
{
unsigned int V_240 , V_241 , V_242 ;
T_1 V_197 , V_243 , V_244 ;
V_240 = V_98 ;
V_241 = V_240 - V_97 ;
V_197 = V_29 + V_241 ;
F_60 ( V_197 , V_240 ) ;
V_242 = F_86 ( V_197 , V_245 ) ;
if ( V_242 )
V_243 = F_87 ( V_245 , V_246 , V_197 ) ;
else
V_243 = F_88 ( V_245 , V_246 , V_197 ) ;
V_244 = V_243 * V_240 - V_97 ;
* V_30 = V_244 - V_29 ;
return V_242 ;
}
static void F_89 ( T_1 V_29 , unsigned int V_117 )
{
unsigned int V_240 , V_241 ;
T_1 V_244 = V_29 + V_117 ;
V_240 = V_98 ;
V_241 = V_240 - V_97 ;
while ( V_29 < V_244 ) {
T_1 V_197 , V_247 ;
V_197 = V_29 + V_241 ;
V_247 = F_60 ( V_197 , V_240 ) ;
if ( V_197 < V_246 )
F_90 ( V_197 , V_245 ) ;
V_29 += V_240 - V_247 ;
}
}
static void F_91 ( T_1 V_29 , unsigned int V_117 )
{
unsigned int V_240 , V_241 ;
T_1 V_244 = V_29 + V_117 ;
V_240 = V_98 ;
V_241 = V_240 - V_97 ;
while ( V_29 < V_244 ) {
T_1 V_197 , V_247 ;
V_197 = V_29 + V_241 ;
V_247 = F_60 ( V_197 , V_240 ) ;
if ( V_247 == 0 && V_29 + V_240 <= V_244 && V_197 < V_246 ) {
F_92 ( V_197 , V_245 ) ;
if ( V_100 )
memset ( V_199 +
V_197 * V_135 , 0 ,
V_135 ) ;
}
V_29 += V_240 - V_247 ;
}
}
static int F_93 ( struct V_49 * V_50 , unsigned long long V_29 ,
unsigned int V_30 , struct V_16 * V_17 ,
T_2 V_31 )
{
unsigned long V_221 ;
int V_106 ;
V_106 = F_57 ( V_17 , V_29 , V_30 ) ;
if ( V_106 )
return V_106 ;
if ( V_227 && F_74 ( V_50 ) ) {
int V_228 = F_78 ( V_50 , V_29 , V_30 , V_31 ) ;
if ( V_228 ) {
F_7 ( V_17 , V_114 , 0x10 , V_228 ) ;
return V_230 ;
}
}
F_94 ( & V_231 , V_221 ) ;
V_106 = F_58 ( V_50 , V_17 , V_29 , V_30 , 1 ) ;
if ( V_98 )
F_89 ( V_29 , V_30 ) ;
F_95 ( & V_231 , V_221 ) ;
if ( - 1 == V_106 )
return ( V_68 << 16 ) ;
else if ( ( V_106 < ( V_30 * V_135 ) ) &&
( V_25 & V_26 ) )
F_9 ( V_27 L_25
L_14 , V_30 * V_135 , V_106 ) ;
return 0 ;
}
static int F_96 ( struct V_49 * V_195 , unsigned long long V_29 ,
unsigned int V_30 , struct V_16 * V_17 ,
T_2 V_31 , unsigned int V_248 )
{
unsigned long V_221 ;
unsigned long long V_202 ;
int V_106 ;
V_106 = F_57 ( V_17 , V_29 , V_30 ) ;
if ( V_106 )
return V_106 ;
if ( V_30 > V_99 ) {
F_7 ( V_17 , V_114 , V_115 ,
0 ) ;
return V_55 ;
}
F_94 ( & V_231 , V_221 ) ;
if ( V_248 && V_98 ) {
F_91 ( V_29 , V_30 ) ;
goto V_238;
}
V_106 = F_18 ( V_195 ,
V_199 + ( V_29 * V_135 ) ,
V_135 ) ;
if ( - 1 == V_106 ) {
F_95 ( & V_231 , V_221 ) ;
return ( V_68 << 16 ) ;
} else if ( ( V_106 < ( V_30 * V_135 ) ) &&
( V_25 & V_26 ) )
F_9 ( V_27 L_26
L_14 , V_30 * V_135 , V_106 ) ;
for ( V_202 = 1 ; V_202 < V_30 ; V_202 ++ )
memcpy ( V_199 + ( ( V_29 + V_202 ) * V_135 ) ,
V_199 + ( V_29 * V_135 ) ,
V_135 ) ;
if ( V_98 )
F_89 ( V_29 , V_30 ) ;
V_238:
F_95 ( & V_231 , V_221 ) ;
return 0 ;
}
static int F_97 ( struct V_49 * V_195 , struct V_16 * V_17 )
{
unsigned char * V_232 ;
struct V_249 * V_250 ;
unsigned int V_202 , V_251 , V_252 ;
int V_106 ;
V_106 = F_12 ( V_195 , 1 , V_17 ) ;
if ( V_106 )
return V_106 ;
V_251 = F_98 ( & V_195 -> V_103 [ 7 ] ) ;
F_81 ( F_17 ( V_195 ) != V_251 ) ;
V_252 = ( V_251 - 8 ) / 16 ;
V_232 = F_99 ( F_17 ( V_195 ) , V_108 ) ;
if ( ! V_232 )
return V_55 ;
F_19 ( V_195 , V_232 , F_17 ( V_195 ) ) ;
F_81 ( F_98 ( & V_232 [ 0 ] ) != V_251 - 2 ) ;
F_81 ( F_98 ( & V_232 [ 2 ] ) != V_252 * 16 ) ;
V_250 = ( void * ) & V_232 [ 8 ] ;
for ( V_202 = 0 ; V_202 < V_252 ; V_202 ++ ) {
unsigned long long V_29 = F_100 ( & V_250 [ V_202 ] . V_29 ) ;
unsigned int V_30 = F_101 ( & V_250 [ V_202 ] . V_253 ) ;
V_106 = F_57 ( V_17 , V_29 , V_30 ) ;
if ( V_106 )
goto V_238;
F_91 ( V_29 , V_30 ) ;
}
V_106 = 0 ;
V_238:
F_32 ( V_232 ) ;
return V_106 ;
}
static int F_102 ( struct V_49 * V_195 ,
struct V_16 * V_17 )
{
unsigned long long V_29 ;
unsigned int V_104 , V_242 , V_30 ;
unsigned char V_60 [ V_254 ] ;
int V_106 ;
V_106 = F_12 ( V_195 , 1 , V_17 ) ;
if ( V_106 )
return V_106 ;
V_29 = F_100 ( & V_195 -> V_103 [ 2 ] ) ;
V_104 = F_101 ( & V_195 -> V_103 [ 10 ] ) ;
if ( V_104 < 24 )
return 0 ;
V_106 = F_57 ( V_17 , V_29 , 1 ) ;
if ( V_106 )
return V_106 ;
V_242 = F_85 ( V_29 , & V_30 ) ;
memset ( V_60 , 0 , V_254 ) ;
F_26 ( 20 , & V_60 [ 0 ] ) ;
F_27 ( V_29 , & V_60 [ 8 ] ) ;
F_26 ( V_30 , & V_60 [ 16 ] ) ;
V_60 [ 20 ] = ! V_242 ;
return F_13 ( V_195 , V_60 , V_254 ) ;
}
static int F_103 ( struct V_49 * V_59 ,
struct V_16 * V_17 )
{
unsigned int V_104 ;
int V_255 , V_202 , V_256 , V_30 , V_105 , V_110 , V_112 ;
unsigned char * V_28 = ( unsigned char * ) V_59 -> V_103 ;
int V_257 = ( int ) V_28 [ 2 ] ;
struct V_258 * V_259 ;
unsigned char V_60 [ V_260 ] ;
unsigned char * V_261 ;
V_104 = V_28 [ 9 ] + ( V_28 [ 8 ] << 8 ) + ( V_28 [ 7 ] << 16 ) + ( V_28 [ 6 ] << 24 ) ;
if ( ( V_104 < 4 ) || ( V_257 > 2 ) ) {
F_7 ( V_17 , V_114 , V_115 ,
0 ) ;
return V_55 ;
}
memset ( V_60 , 0 , V_260 ) ;
V_255 = V_262 ;
if ( 1 == V_257 )
V_255 = 0 ;
else if ( V_111 && ( V_255 > 0 ) )
-- V_255 ;
V_110 = ( V_257 > 0 ) ? 1 : 0 ;
V_30 = V_255 + V_110 ;
V_60 [ 2 ] = ( ( sizeof( struct V_258 ) * V_30 ) >> 8 ) & 0xff ;
V_60 [ 3 ] = ( sizeof( struct V_258 ) * V_30 ) & 0xff ;
V_105 = F_34 ( ( int ) ( ( V_260 - 8 ) /
sizeof( struct V_258 ) ) , V_30 ) ;
if ( V_105 < V_30 ) {
V_110 = 0 ;
V_255 = V_105 ;
}
V_259 = (struct V_258 * ) & V_60 [ 8 ] ;
V_261 = V_60 + V_260 ;
for ( V_202 = 0 , V_112 = ( V_111 ? 1 : 0 ) ;
( ( V_202 < V_255 ) && ( ( unsigned char * ) ( V_259 + V_202 ) < V_261 ) ) ;
V_202 ++ , V_112 ++ ) {
V_256 = ( V_112 >> 8 ) & 0x3f ;
if ( V_256 )
V_259 [ V_202 ] . V_258 [ 0 ] =
( V_256 | ( V_263 << 6 ) ) ;
V_259 [ V_202 ] . V_258 [ 1 ] = V_112 & 0xff ;
}
if ( V_110 ) {
V_259 [ V_202 ] . V_258 [ 0 ] = ( V_15 >> 8 ) & 0xff ;
V_259 [ V_202 ] . V_258 [ 1 ] = V_15 & 0xff ;
V_202 ++ ;
}
V_104 = ( unsigned char * ) ( V_259 + V_202 ) - V_60 ;
return F_13 ( V_59 , V_60 ,
F_34 ( ( int ) V_104 , V_260 ) ) ;
}
static int F_104 ( struct V_49 * V_59 , unsigned long long V_29 ,
unsigned int V_30 , struct V_16 * V_17 )
{
int V_202 , V_233 , V_106 = - 1 ;
unsigned char * V_264 , * V_232 ;
unsigned int V_170 ;
struct V_203 * V_265 ;
struct V_63 * V_64 = F_14 ( V_59 ) ;
V_232 = F_99 ( F_17 ( V_59 ) , V_108 ) ;
if ( ! V_232 )
return V_106 ;
F_19 ( V_59 , V_232 , F_17 ( V_59 ) ) ;
V_170 = 0 ;
F_105 (sdb->table.sgl, sg, sdb->table.nents, i) {
V_264 = ( unsigned char * ) F_69 ( F_70 ( V_265 ) ) ;
if ( ! V_264 )
goto V_238;
for ( V_233 = 0 ; V_233 < V_265 -> V_65 ; V_233 ++ )
* ( V_264 + V_265 -> V_170 + V_233 ) ^= * ( V_232 + V_170 + V_233 ) ;
V_170 += V_265 -> V_65 ;
F_71 ( V_264 ) ;
}
V_106 = 0 ;
V_238:
F_32 ( V_232 ) ;
return V_106 ;
}
static void F_106 ( unsigned long V_266 )
{
struct V_267 * V_268 ;
unsigned long V_221 ;
if ( V_266 >= V_269 ) {
F_9 ( V_214 L_27
L_28 ) ;
return;
}
F_107 ( & V_270 , V_221 ) ;
V_268 = & V_271 [ ( int ) V_266 ] ;
if ( ! V_268 -> V_272 ) {
F_9 ( V_214 L_29
L_30 ) ;
F_108 ( & V_270 , V_221 ) ;
return;
}
V_268 -> V_272 = 0 ;
if ( V_268 -> V_273 ) {
V_268 -> V_274 -> V_275 = V_268 -> V_276 ;
V_268 -> V_273 ( V_268 -> V_274 ) ;
}
V_268 -> V_273 = NULL ;
F_108 ( & V_270 , V_221 ) ;
}
static struct V_16 *
F_109 ( struct V_5 * V_6 , T_5 V_277 )
{
struct V_16 * V_17 ;
V_17 = F_31 ( sizeof( * V_17 ) , V_277 ) ;
if ( V_17 ) {
V_17 -> V_6 = V_6 ;
F_110 ( & V_17 -> V_278 , & V_6 -> V_279 ) ;
}
return V_17 ;
}
static struct V_16 * F_111 ( struct V_45 * V_280 )
{
struct V_5 * V_6 ;
struct V_16 * V_281 = NULL ;
struct V_16 * V_17 =
(struct V_16 * ) V_280 -> V_282 ;
if ( V_17 )
return V_17 ;
V_6 = * (struct V_5 * * ) F_112 ( V_280 -> V_283 ) ;
if ( ! V_6 ) {
F_9 ( V_214 L_31 ) ;
return NULL ;
}
F_5 (devip, &sdbg_host->dev_info_list, dev_list) {
if ( ( V_17 -> V_284 ) && ( V_17 -> V_120 == V_280 -> V_120 ) &&
( V_17 -> V_101 == V_280 -> V_285 ) &&
( V_17 -> V_112 == V_280 -> V_112 ) )
return V_17 ;
else {
if ( ( ! V_17 -> V_284 ) && ( ! V_281 ) )
V_281 = V_17 ;
}
}
if ( ! V_281 ) {
V_281 = F_109 ( V_6 , V_108 ) ;
if ( ! V_281 ) {
F_9 ( V_214 L_32 ,
V_215 , __LINE__ ) ;
return NULL ;
}
}
V_281 -> V_120 = V_280 -> V_120 ;
V_281 -> V_101 = V_280 -> V_285 ;
V_281 -> V_112 = V_280 -> V_112 ;
V_281 -> V_6 = V_6 ;
V_281 -> V_52 = 1 ;
V_281 -> V_284 = 1 ;
memset ( V_281 -> V_22 , 0 , V_23 ) ;
if ( V_24 )
V_281 -> V_22 [ 0 ] = 0x72 ;
else {
V_281 -> V_22 [ 0 ] = 0x70 ;
V_281 -> V_22 [ 7 ] = 0xa ;
}
if ( V_280 -> V_112 == V_15 )
V_281 -> V_110 = V_15 & 0xff ;
return V_281 ;
}
static int F_113 ( struct V_45 * V_286 )
{
if ( V_25 & V_26 )
F_9 ( V_27 L_33 ,
V_286 -> V_283 -> V_119 , V_286 -> V_120 , V_286 -> V_285 , V_286 -> V_112 ) ;
F_114 ( V_287 , V_286 -> V_288 ) ;
return 0 ;
}
static int F_115 ( struct V_45 * V_286 )
{
struct V_16 * V_17 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_34 ,
V_286 -> V_283 -> V_119 , V_286 -> V_120 , V_286 -> V_285 , V_286 -> V_112 ) ;
if ( V_286 -> V_283 -> V_289 != V_290 )
V_286 -> V_283 -> V_289 = V_290 ;
V_17 = F_111 ( V_286 ) ;
if ( NULL == V_17 )
return 1 ;
V_286 -> V_282 = V_17 ;
if ( V_286 -> V_283 -> V_291 )
F_116 ( V_286 , V_292 ,
V_286 -> V_283 -> V_291 ) ;
F_117 ( V_286 -> V_288 , 256 * 1024 ) ;
if ( V_293 )
V_286 -> V_294 = 1 ;
return 0 ;
}
static void F_118 ( struct V_45 * V_286 )
{
struct V_16 * V_17 =
(struct V_16 * ) V_286 -> V_282 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_35 ,
V_286 -> V_283 -> V_119 , V_286 -> V_120 , V_286 -> V_285 , V_286 -> V_112 ) ;
if ( V_17 ) {
V_17 -> V_284 = 0 ;
V_286 -> V_282 = NULL ;
}
}
static int F_119 ( struct V_49 * V_103 )
{
unsigned long V_221 ;
int V_140 ;
struct V_267 * V_268 ;
F_107 ( & V_270 , V_221 ) ;
for ( V_140 = 0 ; V_140 < V_269 ; ++ V_140 ) {
V_268 = & V_271 [ V_140 ] ;
if ( V_268 -> V_272 && ( V_103 == V_268 -> V_274 ) ) {
F_120 ( & V_268 -> V_295 ) ;
V_268 -> V_272 = 0 ;
V_268 -> V_274 = NULL ;
break;
}
}
F_108 ( & V_270 , V_221 ) ;
return ( V_140 < V_269 ) ? 1 : 0 ;
}
static void F_121 ( void )
{
unsigned long V_221 ;
int V_140 ;
struct V_267 * V_268 ;
F_107 ( & V_270 , V_221 ) ;
for ( V_140 = 0 ; V_140 < V_269 ; ++ V_140 ) {
V_268 = & V_271 [ V_140 ] ;
if ( V_268 -> V_272 && V_268 -> V_274 ) {
F_120 ( & V_268 -> V_295 ) ;
V_268 -> V_272 = 0 ;
V_268 -> V_274 = NULL ;
}
}
F_108 ( & V_270 , V_221 ) ;
}
static int F_122 ( struct V_49 * V_50 )
{
if ( V_25 & V_26 )
F_9 ( V_27 L_36 ) ;
++ V_296 ;
F_119 ( V_50 ) ;
return V_297 ;
}
static int F_123 ( struct V_45 * V_280 ,
struct V_298 * V_299 , T_1 V_300 , int * V_301 )
{
int V_184 ;
unsigned char * V_232 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_37 ) ;
V_232 = F_124 ( V_299 ) ;
if ( V_232 ) {
V_184 = F_125 ( V_232 , V_300 ,
& V_301 [ 2 ] , & V_301 [ 0 ] , & V_301 [ 1 ] ) ;
F_32 ( V_232 ) ;
if ( ! V_184 )
return V_184 ;
}
V_301 [ 0 ] = V_302 ;
V_301 [ 1 ] = V_152 ;
V_301 [ 2 ] = V_303 ;
return 0 ;
}
static int F_126 ( struct V_49 * V_50 )
{
struct V_16 * V_17 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_38 ) ;
++ V_304 ;
if ( V_50 ) {
V_17 = F_111 ( V_50 -> V_305 ) ;
if ( V_17 )
V_17 -> V_52 = 1 ;
}
return V_297 ;
}
static int F_127 ( struct V_49 * V_50 )
{
struct V_5 * V_6 ;
struct V_16 * V_306 ;
struct V_45 * V_286 ;
struct V_7 * V_307 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_39 ) ;
++ V_308 ;
if ( V_50 && ( ( V_286 = V_50 -> V_305 ) ) && ( ( V_307 = V_286 -> V_283 ) ) ) {
V_6 = * (struct V_5 * * ) F_112 ( V_307 ) ;
if ( V_6 ) {
F_5 (dev_info,
&sdbg_host->dev_info_list,
dev_list)
V_306 -> V_52 = 1 ;
}
}
return V_297 ;
}
static int F_128 ( struct V_49 * V_50 )
{
struct V_5 * V_6 ;
struct V_16 * V_306 ;
if ( V_25 & V_26 )
F_9 ( V_27 L_40 ) ;
++ V_309 ;
F_4 ( & V_9 ) ;
F_5 (sdbg_host, &sdebug_host_list, host_list) {
F_5 (dev_info, &sdbg_host->dev_info_list,
dev_list)
V_306 -> V_52 = 1 ;
}
F_6 ( & V_9 ) ;
F_121 () ;
return V_297 ;
}
static void T_6 F_129 ( void )
{
unsigned long V_221 ;
int V_140 ;
struct V_267 * V_268 ;
F_107 ( & V_270 , V_221 ) ;
for ( V_140 = 0 ; V_140 < V_269 ; ++ V_140 ) {
V_268 = & V_271 [ V_140 ] ;
F_130 ( & V_268 -> V_295 ) ;
V_268 -> V_272 = 0 ;
V_268 -> V_274 = NULL ;
}
F_108 ( & V_270 , V_221 ) ;
}
static void T_6 F_131 ( unsigned char * V_310 ,
unsigned long V_311 )
{
struct V_312 * V_313 ;
int V_314 [ V_315 + 2 ] ;
int V_316 , V_317 , V_140 ;
int V_318 , V_200 , V_319 ;
if ( ( V_320 < 1 ) || ( V_311 < 1048576 ) )
return;
if ( V_320 > V_315 ) {
V_320 = V_315 ;
F_9 ( V_321 L_41
L_42 , V_315 ) ;
}
V_317 = ( int ) V_93 ;
V_316 = ( V_317 - V_152 )
/ V_320 ;
V_318 = V_302 * V_152 ;
V_314 [ 0 ] = V_152 ;
for ( V_140 = 1 ; V_140 < V_320 ; ++ V_140 )
V_314 [ V_140 ] = ( ( V_140 * V_316 ) / V_318 )
* V_318 ;
V_314 [ V_320 ] = V_317 ;
V_314 [ V_320 + 1 ] = 0 ;
V_310 [ 510 ] = 0x55 ;
V_310 [ 511 ] = 0xAA ;
V_313 = (struct V_312 * ) ( V_310 + 0x1be ) ;
for ( V_140 = 0 ; V_314 [ V_140 + 1 ] ; ++ V_140 , ++ V_313 ) {
V_200 = V_314 [ V_140 ] ;
V_319 = V_314 [ V_140 + 1 ] - 1 ;
V_313 -> V_322 = 0 ;
V_313 -> V_323 = V_200 / V_318 ;
V_313 -> V_324 = ( V_200 - ( V_313 -> V_323 * V_318 ) )
/ V_152 ;
V_313 -> V_4 = ( V_200 % V_152 ) + 1 ;
V_313 -> V_325 = V_319 / V_318 ;
V_313 -> V_326 = ( V_319 - ( V_313 -> V_325 * V_318 ) )
/ V_152 ;
V_313 -> V_327 = ( V_319 % V_152 ) + 1 ;
V_313 -> V_328 = V_200 ;
V_313 -> V_329 = V_319 - V_200 + 1 ;
V_313 -> V_330 = 0x83 ;
}
}
static int F_132 ( struct V_49 * V_103 ,
struct V_16 * V_17 ,
T_7 V_331 , int V_276 , int V_332 )
{
if ( ( V_25 & V_26 ) && V_103 ) {
if ( V_276 ) {
struct V_45 * V_286 = V_103 -> V_305 ;
F_9 ( V_27 L_43
L_44 , V_286 -> V_283 -> V_119 ,
V_286 -> V_120 , V_286 -> V_285 , V_286 -> V_112 , V_276 ) ;
}
}
if ( V_103 && V_17 ) {
if ( V_333 == ( V_276 & 0xff ) )
memcpy ( V_103 -> V_334 , V_17 -> V_22 ,
( V_335 > V_23 ) ?
V_23 : V_335 ) ;
}
if ( V_332 <= 0 ) {
if ( V_103 )
V_103 -> V_275 = V_276 ;
if ( V_331 )
V_331 ( V_103 ) ;
return 0 ;
} else {
unsigned long V_221 ;
int V_140 ;
struct V_267 * V_268 = NULL ;
F_107 ( & V_270 , V_221 ) ;
for ( V_140 = 0 ; V_140 < V_269 ; ++ V_140 ) {
V_268 = & V_271 [ V_140 ] ;
if ( ! V_268 -> V_272 )
break;
}
if ( V_140 >= V_269 ) {
F_108 ( & V_270 , V_221 ) ;
F_9 ( V_321 L_45 ) ;
return 1 ;
}
V_268 -> V_272 = 1 ;
V_268 -> V_274 = V_103 ;
V_268 -> V_276 = V_276 ;
V_268 -> V_273 = V_331 ;
V_268 -> V_295 . V_336 = F_106 ;
V_268 -> V_295 . V_337 = V_140 ;
V_268 -> V_295 . V_338 = V_339 + V_332 ;
F_133 ( & V_268 -> V_295 ) ;
F_108 ( & V_270 , V_221 ) ;
if ( V_103 )
V_103 -> V_275 = 0 ;
return 0 ;
}
}
static const char * F_134 ( struct V_7 * V_340 )
{
sprintf ( V_341 , L_46
L_47 , V_342 ,
V_343 , V_344 ,
V_26 ) ;
return V_341 ;
}
static int F_135 ( struct V_7 * V_283 , char * V_345 , char * * V_133 , T_8 V_170 ,
int V_65 , int V_346 )
{
int V_117 , V_347 , V_348 ;
int V_349 ;
V_349 = V_65 ;
if ( V_346 == 1 ) {
char V_60 [ 16 ] ;
int V_350 = V_65 > 15 ? 15 : V_65 ;
if ( ! F_136 ( V_351 ) || ! F_136 ( V_352 ) )
return - V_353 ;
memcpy ( V_60 , V_345 , V_350 ) ;
V_60 [ V_350 ] = '\0' ;
if ( 1 != sscanf ( V_60 , L_12 , & V_347 ) )
return - V_48 ;
V_26 = V_347 ;
if ( V_354 != 0 )
V_355 = 0 ;
return V_65 ;
}
V_348 = 0 ;
V_347 = V_117 = sprintf ( V_345 , L_48
L_49
L_50
L_51
L_52
L_53
L_54
L_55 ,
V_342 , V_343 , V_12 ,
V_344 , V_26 , V_354 ,
V_355 , V_356 ,
V_262 , V_124 ,
V_135 , V_303 , V_302 ,
V_152 , V_296 , V_304 , V_308 ,
V_309 , V_220 , V_239 , V_216 ) ;
if ( V_347 < V_170 ) {
V_117 = 0 ;
V_348 = V_347 ;
}
* V_133 = V_345 + ( V_170 - V_348 ) ;
V_117 -= ( V_170 - V_348 ) ;
if ( V_117 > V_65 )
V_117 = V_65 ;
return V_117 ;
}
static T_9 F_137 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_356 ) ;
}
static T_9 F_138 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_361 ;
char V_362 [ 20 ] ;
if ( 1 == sscanf ( V_232 , L_57 , V_362 ) ) {
if ( ( 1 == sscanf ( V_362 , L_12 , & V_361 ) ) && ( V_361 >= 0 ) ) {
V_356 = V_361 ;
return V_360 ;
}
}
return - V_48 ;
}
static T_9 F_139 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_58 , V_26 ) ;
}
static T_9 F_140 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_363 ;
char V_362 [ 20 ] ;
if ( 1 == sscanf ( V_232 , L_57 , V_362 ) ) {
if ( 0 == F_141 ( V_362 , L_59 , 2 ) ) {
if ( 1 == sscanf ( & V_362 [ 2 ] , L_60 , & V_363 ) )
goto V_364;
} else {
if ( 1 == sscanf ( V_362 , L_12 , & V_363 ) )
goto V_364;
}
}
return - V_48 ;
V_364:
V_26 = V_363 ;
V_355 = 0 ;
return V_360 ;
}
static T_9 F_142 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_113 ) ;
}
static T_9 F_143 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_105 ;
if ( ( V_360 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_113 = V_105 ;
return V_360 ;
}
return - V_48 ;
}
static T_9 F_144 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_24 ) ;
}
static T_9 F_145 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_105 ;
if ( ( V_360 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_24 = V_105 ;
return V_360 ;
}
return - V_48 ;
}
static T_9 F_146 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_365 ) ;
}
static T_9 F_147 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_105 ;
if ( ( V_360 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_365 = V_105 ;
return V_360 ;
}
return - V_48 ;
}
static T_9 F_148 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_111 ) ;
}
static T_9 F_149 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_105 ;
if ( ( V_360 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_111 = V_105 ;
return V_360 ;
}
return - V_48 ;
}
static T_9 F_150 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_12 ) ;
}
static T_9 F_151 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_105 ;
if ( ( V_360 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_12 = V_105 ;
F_3 () ;
return V_360 ;
}
return - V_48 ;
}
static T_9 F_152 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_344 ) ;
}
static T_9 F_153 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_320 ) ;
}
static T_9 F_154 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_354 ) ;
}
static T_9 F_155 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_366 ;
if ( ( V_360 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_366 ) ) ) {
V_354 = V_366 ;
V_355 = 0 ;
return V_360 ;
}
return - V_48 ;
}
static T_9 F_156 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_262 ) ;
}
static T_9 F_157 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_105 ;
if ( ( V_360 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_262 = V_105 ;
F_3 () ;
return V_360 ;
}
return - V_48 ;
}
static T_9 F_158 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_269 ) ;
}
static T_9 F_159 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_105 ;
if ( ( V_360 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_105 ) ) && ( V_105 > 0 ) &&
( V_105 <= V_367 ) ) {
V_269 = V_105 ;
return V_360 ;
}
return - V_48 ;
}
static T_9 F_160 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_293 ) ;
}
static T_9 F_161 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_124 ) ;
}
static T_9 F_162 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_134 ) ;
}
static T_9 F_163 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_105 ;
if ( ( V_360 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_134 = V_105 ;
V_138 = F_38 () ;
return V_360 ;
}
return - V_48 ;
}
static T_9 F_164 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_368 ) ;
}
static T_9 F_165 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_369 ;
if ( sscanf ( V_232 , L_12 , & V_369 ) != 1 )
return - V_48 ;
if ( V_369 > 0 ) {
do {
F_166 () ;
} while ( -- V_369 );
} else if ( V_369 < 0 ) {
do {
F_167 () ;
} while ( ++ V_369 );
}
return V_360 ;
}
static T_9 F_168 ( struct V_357 * V_358 ,
char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_121 ) ;
}
static T_9 F_169 ( struct V_357 * V_358 ,
const char * V_232 , T_10 V_360 )
{
int V_105 ;
if ( ( V_360 > 0 ) && ( 1 == sscanf ( V_232 , L_12 , & V_105 ) ) && ( V_105 >= 0 ) ) {
V_121 = V_105 ;
return V_360 ;
}
return - V_48 ;
}
static T_9 F_170 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_61 , V_135 ) ;
}
static T_9 F_171 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_227 ) ;
}
static T_9 F_172 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_122 ) ;
}
static T_9 F_173 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_212 ) ;
}
static T_9 F_174 ( struct V_357 * V_358 , char * V_232 )
{
return F_33 ( V_232 , V_359 , L_56 , V_157 ) ;
}
static T_9 F_175 ( struct V_357 * V_358 , char * V_232 )
{
T_9 V_360 ;
if ( ! F_1 () )
return F_33 ( V_232 , V_359 , L_62 ,
V_93 ) ;
V_360 = F_176 ( V_232 , V_359 , V_245 , V_246 ) ;
V_232 [ V_360 ++ ] = '\n' ;
V_232 [ V_360 ++ ] = 0 ;
return V_360 ;
}
static int F_177 ( void )
{
int V_106 ;
V_106 = F_178 ( & V_370 , & V_371 ) ;
V_106 |= F_178 ( & V_370 , & V_372 ) ;
V_106 |= F_178 ( & V_370 , & V_373 ) ;
V_106 |= F_178 ( & V_370 , & V_374 ) ;
V_106 |= F_178 ( & V_370 , & V_375 ) ;
V_106 |= F_178 ( & V_370 , & V_376 ) ;
V_106 |= F_178 ( & V_370 , & V_377 ) ;
V_106 |= F_178 ( & V_370 , & V_378 ) ;
V_106 |= F_178 ( & V_370 , & V_379 ) ;
V_106 |= F_178 ( & V_370 , & V_380 ) ;
V_106 |= F_178 ( & V_370 , & V_381 ) ;
V_106 |= F_178 ( & V_370 , & V_382 ) ;
V_106 |= F_178 ( & V_370 , & V_383 ) ;
V_106 |= F_178 ( & V_370 , & V_384 ) ;
V_106 |= F_178 ( & V_370 , & V_385 ) ;
V_106 |= F_178 ( & V_370 , & V_386 ) ;
V_106 |= F_178 ( & V_370 , & V_387 ) ;
V_106 |= F_178 ( & V_370 , & V_388 ) ;
V_106 |= F_178 ( & V_370 , & V_389 ) ;
V_106 |= F_178 ( & V_370 , & V_390 ) ;
V_106 |= F_178 ( & V_370 , & V_391 ) ;
V_106 |= F_178 ( & V_370 , & V_392 ) ;
V_106 |= F_178 ( & V_370 , & V_393 ) ;
return V_106 ;
}
static void F_179 ( void )
{
F_180 ( & V_370 , & V_393 ) ;
F_180 ( & V_370 , & V_392 ) ;
F_180 ( & V_370 , & V_391 ) ;
F_180 ( & V_370 , & V_390 ) ;
F_180 ( & V_370 , & V_389 ) ;
F_180 ( & V_370 , & V_388 ) ;
F_180 ( & V_370 , & V_387 ) ;
F_180 ( & V_370 , & V_386 ) ;
F_180 ( & V_370 , & V_385 ) ;
F_180 ( & V_370 , & V_384 ) ;
F_180 ( & V_370 , & V_383 ) ;
F_180 ( & V_370 , & V_382 ) ;
F_180 ( & V_370 , & V_381 ) ;
F_180 ( & V_370 , & V_380 ) ;
F_180 ( & V_370 , & V_379 ) ;
F_180 ( & V_370 , & V_378 ) ;
F_180 ( & V_370 , & V_377 ) ;
F_180 ( & V_370 , & V_376 ) ;
F_180 ( & V_370 , & V_375 ) ;
F_180 ( & V_370 , & V_374 ) ;
F_180 ( & V_370 , & V_373 ) ;
F_180 ( & V_370 , & V_372 ) ;
F_180 ( & V_370 , & V_371 ) ;
}
static int T_6 F_181 ( void )
{
unsigned long V_394 ;
int V_395 ;
int V_140 ;
int V_106 ;
switch ( V_135 ) {
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_9 ( V_214 L_63 ,
V_135 ) ;
return - V_48 ;
}
switch ( V_122 ) {
case V_396 :
case V_217 :
case V_219 :
case V_123 :
break;
default:
F_9 ( V_214 L_64 ) ;
return - V_48 ;
}
if ( V_212 > 1 ) {
F_9 ( V_214 L_65 ) ;
return - V_48 ;
}
if ( V_157 > 1 ) {
F_9 ( V_214 L_66 ) ;
return - V_48 ;
}
if ( V_92 > 15 ) {
F_9 ( V_214 L_67 ,
V_92 ) ;
return - V_48 ;
}
if ( V_141 > 0x3fff ) {
F_9 ( V_214 L_68 ,
V_141 ) ;
return - V_48 ;
}
if ( V_344 < 1 )
V_344 = 1 ;
V_394 = ( unsigned long ) V_344 * 1048576 ;
V_93 = V_394 / V_135 ;
V_138 = F_38 () ;
V_302 = 8 ;
V_152 = 32 ;
if ( V_344 >= 16 )
V_302 = 32 ;
else if ( V_344 >= 256 )
V_302 = 64 ;
V_303 = ( unsigned long ) V_138 /
( V_152 * V_302 ) ;
if ( V_303 >= 1024 ) {
V_302 = 255 ;
V_152 = 63 ;
V_303 = ( unsigned long ) V_138 /
( V_152 * V_302 ) ;
}
V_199 = F_182 ( V_394 ) ;
if ( NULL == V_199 ) {
F_9 ( V_214 L_69 ) ;
return - V_397 ;
}
memset ( V_199 , 0 , V_394 ) ;
if ( V_320 > 0 )
F_131 ( V_199 , V_394 ) ;
if ( V_122 ) {
int V_398 ;
V_398 = V_93 * sizeof( struct V_205 ) ;
V_209 = F_182 ( V_398 ) ;
F_9 ( V_214 L_70 ,
V_398 , V_209 ) ;
if ( V_209 == NULL ) {
F_9 ( V_214 L_71 ) ;
V_106 = - V_397 ;
goto V_399;
}
memset ( V_209 , 0xff , V_398 ) ;
}
if ( F_1 () ) {
unsigned int V_400 ;
V_95 =
F_183 ( V_95 , 0U , 0xffffffffU ) ;
V_96 =
F_183 ( V_96 , 0U , 256U ) ;
V_98 =
F_183 ( V_98 , 1U , 0xffffffffU ) ;
if ( V_97 &&
V_98 < V_97 ) {
F_9 ( V_214
L_72 ,
V_215 ) ;
return - V_48 ;
}
V_246 = ( V_93 / V_98 ) ;
V_400 = V_246 >> 3 ;
V_245 = F_182 ( V_400 ) ;
F_9 ( V_27 L_73 ,
V_246 ) ;
if ( V_245 == NULL ) {
F_9 ( V_214 L_74 ) ;
V_106 = - V_397 ;
goto V_399;
}
memset ( V_245 , 0x0 , V_400 ) ;
if ( V_320 )
F_89 ( 0 , 2 ) ;
}
V_401 = F_184 ( L_75 ) ;
if ( F_185 ( V_401 ) ) {
F_9 ( V_321 L_76 ) ;
V_106 = F_186 ( V_401 ) ;
goto V_399;
}
V_106 = F_187 ( & V_402 ) ;
if ( V_106 < 0 ) {
F_9 ( V_321 L_77 ,
V_106 ) ;
goto V_403;
}
V_106 = F_188 ( & V_370 ) ;
if ( V_106 < 0 ) {
F_9 ( V_321 L_78 ,
V_106 ) ;
goto V_404;
}
V_106 = F_177 () ;
if ( V_106 < 0 ) {
F_9 ( V_321 L_79 ,
V_106 ) ;
goto V_405;
}
F_129 () ;
V_395 = V_368 ;
V_368 = 0 ;
for ( V_140 = 0 ; V_140 < V_395 ; V_140 ++ ) {
if ( F_166 () ) {
F_9 ( V_214 L_80
L_81 , V_140 ) ;
break;
}
}
if ( V_25 & V_26 ) {
F_9 ( V_27 L_82 ,
V_368 ) ;
}
return 0 ;
V_405:
F_179 () ;
F_189 ( & V_370 ) ;
V_404:
F_190 ( & V_402 ) ;
V_403:
F_191 ( V_401 ) ;
V_399:
if ( V_245 )
F_192 ( V_245 ) ;
if ( V_209 )
F_192 ( V_209 ) ;
F_192 ( V_199 ) ;
return V_106 ;
}
static void T_11 F_193 ( void )
{
int V_140 = V_368 ;
F_121 () ;
for (; V_140 ; V_140 -- )
F_167 () ;
F_179 () ;
F_189 ( & V_370 ) ;
F_190 ( & V_402 ) ;
F_191 ( V_401 ) ;
if ( V_209 )
F_192 ( V_209 ) ;
F_192 ( V_199 ) ;
}
static void F_194 ( struct V_305 * V_46 )
{
struct V_5 * V_6 ;
V_6 = F_195 ( V_46 ) ;
F_32 ( V_6 ) ;
}
static int F_166 ( void )
{
int V_140 , V_406 ;
int error = 0 ;
struct V_5 * V_6 ;
struct V_16 * V_407 , * V_408 ;
V_6 = F_31 ( sizeof( * V_6 ) , V_409 ) ;
if ( NULL == V_6 ) {
F_9 ( V_214 L_32 ,
V_215 , __LINE__ ) ;
return - V_397 ;
}
F_196 ( & V_6 -> V_279 ) ;
V_406 = V_12 * V_262 ;
for ( V_140 = 0 ; V_140 < V_406 ; V_140 ++ ) {
V_407 = F_109 ( V_6 , V_409 ) ;
if ( ! V_407 ) {
F_9 ( V_214 L_32 ,
V_215 , __LINE__ ) ;
error = - V_397 ;
goto V_410;
}
}
F_4 ( & V_9 ) ;
F_110 ( & V_6 -> V_411 , & V_412 ) ;
F_6 ( & V_9 ) ;
V_6 -> V_46 . V_413 = & V_402 ;
V_6 -> V_46 . V_414 = V_401 ;
V_6 -> V_46 . V_415 = & F_194 ;
F_197 ( & V_6 -> V_46 , L_83 , V_368 ) ;
error = F_198 ( & V_6 -> V_46 ) ;
if ( error )
goto V_410;
++ V_368 ;
return error ;
V_410:
F_199 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_200 ( & V_407 -> V_278 ) ;
F_32 ( V_407 ) ;
}
F_32 ( V_6 ) ;
return error ;
}
static void F_167 ( void )
{
struct V_5 * V_6 = NULL ;
F_4 ( & V_9 ) ;
if ( ! F_201 ( & V_412 ) ) {
V_6 = F_202 ( V_412 . V_416 ,
struct V_5 , V_411 ) ;
F_200 ( & V_6 -> V_411 ) ;
}
F_6 ( & V_9 ) ;
if ( ! V_6 )
return;
F_203 ( & V_6 -> V_46 ) ;
-- V_368 ;
}
static
int F_204 ( struct V_49 * V_50 , T_7 V_331 )
{
unsigned char * V_28 = ( unsigned char * ) V_50 -> V_103 ;
int V_117 , V_140 ;
unsigned int V_30 ;
unsigned long long V_29 ;
T_2 V_31 ;
int V_132 = 0 ;
int V_101 = V_50 -> V_305 -> V_285 ;
struct V_16 * V_17 = NULL ;
int V_417 = 0 ;
int V_418 = 0 ;
int V_419 = 0 ;
int V_420 = 0 ;
int V_421 = 0 ;
int V_248 = 0 ;
F_73 ( V_50 , 0 ) ;
if ( ( V_25 & V_26 ) && V_28 ) {
F_9 ( V_27 L_84 ) ;
for ( V_140 = 0 , V_117 = V_50 -> V_422 ; V_140 < V_117 ; ++ V_140 )
F_9 ( L_21 , ( int ) V_28 [ V_140 ] ) ;
F_9 ( L_22 ) ;
}
if ( V_101 == V_50 -> V_305 -> V_283 -> V_423 -> V_11 ) {
F_9 ( V_27 L_85
L_86 ) ;
return F_132 ( V_50 , NULL , V_331 ,
V_424 << 16 , 0 ) ;
}
if ( ( V_50 -> V_305 -> V_112 >= V_262 ) &&
( V_50 -> V_305 -> V_112 != V_15 ) )
return F_132 ( V_50 , NULL , V_331 ,
V_424 << 16 , 0 ) ;
V_17 = F_111 ( V_50 -> V_305 ) ;
if ( NULL == V_17 )
return F_132 ( V_50 , NULL , V_331 ,
V_424 << 16 , 0 ) ;
if ( ( V_354 != 0 ) &&
( ++ V_355 >= abs ( V_354 ) ) ) {
V_355 = 0 ;
if ( V_354 < - 1 )
V_354 = - 1 ;
if ( V_425 & V_26 )
return 0 ;
else if ( V_426 & V_26 &&
F_205 ( V_50 ) )
return 0 ;
else if ( V_427 & V_26 )
V_417 = 1 ;
else if ( V_428 & V_26 )
V_418 = 1 ;
else if ( V_429 & V_26 )
V_419 = 1 ;
else if ( V_430 & V_26 )
V_420 = 1 ;
}
if ( V_17 -> V_110 ) {
switch ( * V_28 ) {
case V_431 :
case V_432 :
case V_433 :
case V_434 :
break;
default:
if ( V_25 & V_26 )
F_9 ( V_27 L_87
L_88 , * V_28 ) ;
F_7 ( V_17 , V_114 ,
V_435 , 0 ) ;
V_132 = V_55 ;
return F_132 ( V_50 , V_17 , V_331 , V_132 ,
0 ) ;
}
}
switch ( * V_28 ) {
case V_431 :
V_421 = 1 ;
V_132 = F_30 ( V_50 , V_101 , V_17 ) ;
break;
case V_432 :
V_421 = 1 ;
V_132 = F_36 ( V_50 , V_17 ) ;
break;
case V_436 :
case V_437 :
V_132 = F_37 ( V_50 , V_17 ) ;
break;
case V_438 :
V_132 = F_12 ( V_50 , 1 , V_17 ) ;
if ( V_132 )
break;
if ( V_25 & V_26 )
F_9 ( V_27 L_89 ,
V_28 [ 4 ] ? L_90 : L_91 ) ;
break;
case V_439 :
V_132 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_433 :
V_421 = 1 ;
V_132 = F_12 ( V_50 , 0 , V_17 ) ;
break;
case V_440 :
V_132 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_441 :
V_132 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_442 :
V_132 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_443 :
V_132 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_444 :
V_132 = F_39 ( V_50 , V_17 ) ;
break;
case V_445 :
if ( V_28 [ 1 ] == V_446 )
V_132 = F_40 ( V_50 , V_17 ) ;
else if ( V_28 [ 1 ] == V_447 ) {
if ( F_1 () == 0 ) {
F_7 ( V_17 , V_114 ,
V_448 , 0 ) ;
V_132 = V_55 ;
} else
V_132 = F_102 ( V_50 , V_17 ) ;
} else {
F_7 ( V_17 , V_114 ,
V_435 , 0 ) ;
V_132 = V_55 ;
}
break;
case V_449 :
if ( V_450 != V_28 [ 1 ] ) {
F_7 ( V_17 , V_114 ,
V_435 , 0 ) ;
V_132 = V_55 ;
break;
}
V_132 = F_41 ( V_50 , V_17 ) ;
break;
case V_36 :
case V_38 :
case V_41 :
if ( V_122 == V_219 &&
V_28 [ 1 ] & 0xe0 ) {
F_7 ( V_17 , V_114 ,
V_448 , 0 ) ;
V_132 = V_55 ;
break;
}
if ( ( V_122 == V_217 ||
V_122 == V_123 ) &&
( V_28 [ 1 ] & 0xe0 ) == 0 )
F_9 ( V_214 L_92 ) ;
case V_44 :
V_451:
V_132 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_132 )
break;
if ( V_365 )
break;
F_10 ( V_28 , & V_29 , & V_30 , & V_31 ) ;
V_132 = F_72 ( V_50 , V_29 , V_30 , V_17 , V_31 ) ;
if ( V_417 && ( 0 == V_132 ) ) {
F_7 ( V_17 , V_452 ,
V_130 , 0 ) ;
V_132 = V_55 ;
} else if ( V_418 && ( 0 == V_132 ) ) {
F_7 ( V_17 , V_229 ,
V_453 , V_454 ) ;
V_132 = V_55 ;
} else if ( V_419 && ( 0 == V_132 ) ) {
F_7 ( V_17 , V_229 , 0x10 , 1 ) ;
V_132 = V_230 ;
} else if ( V_420 && ( 0 == V_132 ) ) {
F_7 ( V_17 , V_114 , 0x10 , 1 ) ;
V_132 = V_230 ;
}
break;
case V_434 :
V_421 = 1 ;
V_132 = F_103 ( V_50 , V_17 ) ;
break;
case V_455 :
V_132 = F_12 ( V_50 , 0 , V_17 ) ;
break;
case V_35 :
case V_37 :
case V_40 :
if ( V_122 == V_219 &&
V_28 [ 1 ] & 0xe0 ) {
F_7 ( V_17 , V_114 ,
V_448 , 0 ) ;
V_132 = V_55 ;
break;
}
if ( ( V_122 == V_217 ||
V_122 == V_123 ) &&
( V_28 [ 1 ] & 0xe0 ) == 0 )
F_9 ( V_214 L_92 ) ;
case V_43 :
V_196:
V_132 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_132 )
break;
if ( V_365 )
break;
F_10 ( V_28 , & V_29 , & V_30 , & V_31 ) ;
V_132 = F_93 ( V_50 , V_29 , V_30 , V_17 , V_31 ) ;
if ( V_417 && ( 0 == V_132 ) ) {
F_7 ( V_17 , V_452 ,
V_130 , 0 ) ;
V_132 = V_55 ;
} else if ( V_419 && ( 0 == V_132 ) ) {
F_7 ( V_17 , V_229 , 0x10 , 1 ) ;
V_132 = V_230 ;
} else if ( V_420 && ( 0 == V_132 ) ) {
F_7 ( V_17 , V_114 , 0x10 , 1 ) ;
V_132 = V_230 ;
}
break;
case V_34 :
case V_39 :
if ( V_28 [ 1 ] & 0x8 ) {
if ( ( * V_28 == V_34 && V_2 == 0 ) ||
( * V_28 == V_39 && V_3 == 0 ) ) {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
V_132 = V_55 ;
} else
V_248 = 1 ;
}
if ( V_132 )
break;
V_132 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_132 )
break;
F_10 ( V_28 , & V_29 , & V_30 , & V_31 ) ;
V_132 = F_96 ( V_50 , V_29 , V_30 , V_17 , V_31 , V_248 ) ;
break;
case V_456 :
V_132 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_132 )
break;
if ( V_96 == 0 || V_1 == 0 ) {
F_7 ( V_17 , V_114 ,
V_448 , 0 ) ;
V_132 = V_55 ;
} else
V_132 = F_97 ( V_50 , V_17 ) ;
break;
case V_173 :
case V_457 :
V_132 = F_51 ( V_50 , V_101 , V_17 ) ;
break;
case V_458 :
V_132 = F_53 ( V_50 , 1 , V_17 ) ;
break;
case V_459 :
V_132 = F_53 ( V_50 , 0 , V_17 ) ;
break;
case V_460 :
V_132 = F_56 ( V_50 , V_17 ) ;
break;
case V_461 :
V_421 = 1 ;
V_132 = F_12 ( V_50 , 0 , V_17 ) ;
break;
case V_462 :
V_132 = F_12 ( V_50 , 1 , V_17 ) ;
break;
case V_42 :
if ( ! F_15 ( V_50 ) ) {
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
V_132 = V_55 ;
break;
}
V_132 = F_12 ( V_50 , 0 , V_17 ) ;
if ( V_132 )
break;
if ( V_365 )
break;
F_10 ( V_28 , & V_29 , & V_30 , & V_31 ) ;
V_132 = F_72 ( V_50 , V_29 , V_30 , V_17 , V_31 ) ;
if ( V_132 )
break;
V_132 = F_93 ( V_50 , V_29 , V_30 , V_17 , V_31 ) ;
if ( V_132 )
break;
V_132 = F_104 ( V_50 , V_29 , V_30 , V_17 ) ;
break;
case V_32 :
if ( V_122 == V_219 ) {
if ( ( V_28 [ 10 ] & 0xe0 ) == 0 )
F_9 ( V_214
L_92 ) ;
if ( V_28 [ 9 ] == V_463 ) {
F_81 ( V_50 -> V_422 < 32 ) ;
goto V_451;
}
if ( V_28 [ 9 ] == V_464 ) {
F_81 ( V_50 -> V_422 < 32 ) ;
goto V_196;
}
}
F_7 ( V_17 , V_114 ,
V_115 , 0 ) ;
V_132 = V_55 ;
break;
default:
if ( V_25 & V_26 )
F_9 ( V_27 L_93
L_94 , * V_28 ) ;
V_132 = F_12 ( V_50 , 1 , V_17 ) ;
if ( V_132 )
break;
F_7 ( V_17 , V_114 , V_435 , 0 ) ;
V_132 = V_55 ;
break;
}
return F_132 ( V_50 , V_17 , V_331 , V_132 ,
( V_421 ? 0 : V_356 ) ) ;
}
static int F_206 ( struct V_305 * V_46 )
{
int error = 0 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_465 ;
V_6 = F_195 ( V_46 ) ;
V_466 . V_467 = V_269 ;
V_8 = F_207 ( & V_466 , sizeof( V_6 ) ) ;
if ( NULL == V_8 ) {
F_9 ( V_214 L_95 , V_215 ) ;
error = - V_468 ;
return error ;
}
V_6 -> V_10 = V_8 ;
* ( (struct V_5 * * ) V_8 -> V_282 ) = V_6 ;
if ( ( V_8 -> V_11 >= 0 ) && ( V_12 > V_8 -> V_11 ) )
V_8 -> V_13 = V_12 + 1 ;
else
V_8 -> V_13 = V_12 ;
V_8 -> V_14 = V_15 ;
V_465 = 0 ;
switch ( V_122 ) {
case V_217 :
V_465 = V_469 ;
if ( V_227 )
V_465 |= V_470 ;
break;
case V_219 :
V_465 = V_471 ;
if ( V_227 )
V_465 |= V_472 ;
break;
case V_123 :
V_465 = V_473 ;
if ( V_227 )
V_465 |= V_474 ;
break;
default:
if ( V_227 )
V_465 |= V_475 ;
break;
}
F_208 ( V_8 , V_465 ) ;
F_9 ( V_27 L_96 ,
( V_465 & V_469 ) ? L_97 : L_98 ,
( V_465 & V_471 ) ? L_99 : L_98 ,
( V_465 & V_473 ) ? L_100 : L_98 ,
( V_465 & V_475 ) ? L_101 : L_98 ,
( V_465 & V_470 ) ? L_102 : L_98 ,
( V_465 & V_472 ) ? L_103 : L_98 ,
( V_465 & V_474 ) ? L_104 : L_98 ) ;
if ( V_212 == 1 )
F_209 ( V_8 , V_476 ) ;
else
F_209 ( V_8 , V_477 ) ;
error = F_210 ( V_8 , & V_6 -> V_46 ) ;
if ( error ) {
F_9 ( V_214 L_105 , V_215 ) ;
error = - V_468 ;
F_211 ( V_8 ) ;
} else
F_212 ( V_8 ) ;
return error ;
}
static int F_213 ( struct V_305 * V_46 )
{
struct V_5 * V_6 ;
struct V_16 * V_407 , * V_408 ;
V_6 = F_195 ( V_46 ) ;
if ( ! V_6 ) {
F_9 ( V_214 L_106 ,
V_215 ) ;
return - V_468 ;
}
F_214 ( V_6 -> V_10 ) ;
F_199 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_200 ( & V_407 -> V_278 ) ;
F_32 ( V_407 ) ;
}
F_211 ( V_6 -> V_10 ) ;
return 0 ;
}
static int F_215 ( struct V_305 * V_46 ,
struct V_357 * V_478 )
{
return 1 ;
}
