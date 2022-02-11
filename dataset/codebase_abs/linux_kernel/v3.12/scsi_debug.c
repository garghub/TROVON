static unsigned int F_1 ( void )
{
return V_1 | V_2 | V_3 ;
}
static void F_2 ( void )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
F_3 ( & V_8 ) ;
F_4 (sdbg_host, &sdebug_host_list, host_list) {
V_7 = V_5 -> V_9 ;
if ( ( V_7 -> V_10 >= 0 ) &&
( V_11 > V_7 -> V_10 ) )
V_7 -> V_12 = V_11 + 1 ;
else
V_7 -> V_12 = V_11 ;
V_7 -> V_13 = V_14 ;
}
F_5 ( & V_8 ) ;
}
static void F_6 ( struct V_15 * V_16 , int V_17 ,
int V_18 , int V_19 )
{
unsigned char * V_20 ;
V_20 = V_16 -> V_21 ;
memset ( V_20 , 0 , V_22 ) ;
F_7 ( V_23 , V_20 , V_17 , V_18 , V_19 ) ;
if ( V_24 & V_25 )
F_8 ( V_26 L_1
L_2 , V_17 , V_18 , V_19 ) ;
}
static void F_9 ( unsigned char * V_27 ,
unsigned long long * V_28 , unsigned int * V_29 ,
T_1 * V_30 )
{
* V_30 = 0 ;
switch ( * V_27 ) {
case V_31 :
* V_28 = ( V_32 ) V_27 [ 19 ] | ( V_32 ) V_27 [ 18 ] << 8 |
( V_32 ) V_27 [ 17 ] << 16 | ( V_32 ) V_27 [ 16 ] << 24 |
( V_32 ) V_27 [ 15 ] << 32 | ( V_32 ) V_27 [ 14 ] << 40 |
( V_32 ) V_27 [ 13 ] << 48 | ( V_32 ) V_27 [ 12 ] << 56 ;
* V_30 = ( T_1 ) V_27 [ 23 ] | ( T_1 ) V_27 [ 22 ] << 8 |
( T_1 ) V_27 [ 21 ] << 16 | ( T_1 ) V_27 [ 20 ] << 24 ;
* V_29 = ( T_1 ) V_27 [ 31 ] | ( T_1 ) V_27 [ 30 ] << 8 | ( T_1 ) V_27 [ 29 ] << 16 |
( T_1 ) V_27 [ 28 ] << 24 ;
break;
case V_33 :
case V_34 :
case V_35 :
* V_28 = ( V_32 ) V_27 [ 9 ] | ( V_32 ) V_27 [ 8 ] << 8 |
( V_32 ) V_27 [ 7 ] << 16 | ( V_32 ) V_27 [ 6 ] << 24 |
( V_32 ) V_27 [ 5 ] << 32 | ( V_32 ) V_27 [ 4 ] << 40 |
( V_32 ) V_27 [ 3 ] << 48 | ( V_32 ) V_27 [ 2 ] << 56 ;
* V_29 = ( T_1 ) V_27 [ 13 ] | ( T_1 ) V_27 [ 12 ] << 8 | ( T_1 ) V_27 [ 11 ] << 16 |
( T_1 ) V_27 [ 10 ] << 24 ;
break;
case V_36 :
case V_37 :
* V_28 = ( T_1 ) V_27 [ 5 ] | ( T_1 ) V_27 [ 4 ] << 8 | ( T_1 ) V_27 [ 3 ] << 16 |
( T_1 ) V_27 [ 2 ] << 24 ;
* V_29 = ( T_1 ) V_27 [ 9 ] | ( T_1 ) V_27 [ 8 ] << 8 | ( T_1 ) V_27 [ 7 ] << 16 |
( T_1 ) V_27 [ 6 ] << 24 ;
break;
case V_38 :
case V_39 :
case V_40 :
case V_41 :
* V_28 = ( T_1 ) V_27 [ 5 ] | ( T_1 ) V_27 [ 4 ] << 8 | ( T_1 ) V_27 [ 3 ] << 16 |
( T_1 ) V_27 [ 2 ] << 24 ;
* V_29 = ( T_1 ) V_27 [ 8 ] | ( T_1 ) V_27 [ 7 ] << 8 ;
break;
case V_42 :
case V_43 :
* V_28 = ( T_1 ) V_27 [ 3 ] | ( T_1 ) V_27 [ 2 ] << 8 |
( T_1 ) ( V_27 [ 1 ] & 0x1f ) << 16 ;
* V_29 = ( 0 == V_27 [ 4 ] ) ? 256 : V_27 [ 4 ] ;
break;
default:
break;
}
}
static int F_10 ( struct V_44 * V_45 , int V_27 , void T_2 * V_46 )
{
if ( V_24 & V_25 ) {
F_8 ( V_26 L_3 , V_27 ) ;
}
return - V_47 ;
}
static int F_11 ( struct V_48 * V_49 , int V_50 ,
struct V_15 * V_16 )
{
if ( V_16 -> V_51 ) {
if ( V_24 & V_25 )
F_8 ( V_26 L_4
L_5 ) ;
V_16 -> V_51 = 0 ;
F_6 ( V_16 , V_52 , V_53 , 0 ) ;
return V_54 ;
}
if ( ( 0 == V_50 ) && V_16 -> V_55 ) {
if ( V_24 & V_25 )
F_8 ( V_26 L_6
L_7 ) ;
F_6 ( V_16 , V_56 , V_57 ,
0x2 ) ;
return V_54 ;
}
return 0 ;
}
static int F_12 ( struct V_48 * V_58 , unsigned char * V_59 ,
int V_60 )
{
int V_61 ;
struct V_62 * V_63 = F_13 ( V_58 ) ;
if ( ! V_63 -> V_64 )
return 0 ;
if ( ! ( F_14 ( V_58 ) || V_58 -> V_65 == V_66 ) )
return ( V_67 << 16 ) ;
V_61 = F_15 ( V_63 -> V_68 . V_69 , V_63 -> V_68 . V_70 ,
V_59 , V_60 ) ;
V_63 -> V_71 = F_16 ( V_58 ) - V_61 ;
return 0 ;
}
static int F_17 ( struct V_48 * V_58 , unsigned char * V_59 ,
int V_60 )
{
if ( ! F_16 ( V_58 ) )
return 0 ;
if ( ! ( F_14 ( V_58 ) || V_58 -> V_65 == V_72 ) )
return - 1 ;
return F_18 ( V_58 , V_59 , V_60 ) ;
}
static int F_19 ( unsigned char * V_59 , int V_73 ,
int V_74 , int V_75 ,
const char * V_76 ,
int V_77 )
{
int V_29 , V_78 ;
char V_79 [ 32 ] ;
V_78 = V_74 + 1 ;
V_59 [ 0 ] = 0x2 ;
V_59 [ 1 ] = 0x1 ;
V_59 [ 2 ] = 0x0 ;
memcpy ( & V_59 [ 4 ] , V_80 , 8 ) ;
memcpy ( & V_59 [ 12 ] , V_81 , 16 ) ;
memcpy ( & V_59 [ 28 ] , V_76 , V_77 ) ;
V_29 = 8 + 16 + V_77 ;
V_59 [ 3 ] = V_29 ;
V_29 += 4 ;
if ( V_75 >= 0 ) {
V_59 [ V_29 ++ ] = 0x1 ;
V_59 [ V_29 ++ ] = 0x3 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x8 ;
V_59 [ V_29 ++ ] = 0x53 ;
V_59 [ V_29 ++ ] = 0x33 ;
V_59 [ V_29 ++ ] = 0x33 ;
V_59 [ V_29 ++ ] = 0x30 ;
V_59 [ V_29 ++ ] = ( V_75 >> 24 ) ;
V_59 [ V_29 ++ ] = ( V_75 >> 16 ) & 0xff ;
V_59 [ V_29 ++ ] = ( V_75 >> 8 ) & 0xff ;
V_59 [ V_29 ++ ] = V_75 & 0xff ;
V_59 [ V_29 ++ ] = 0x61 ;
V_59 [ V_29 ++ ] = 0x94 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x4 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x1 ;
}
V_59 [ V_29 ++ ] = 0x61 ;
V_59 [ V_29 ++ ] = 0x93 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x8 ;
V_59 [ V_29 ++ ] = 0x52 ;
V_59 [ V_29 ++ ] = 0x22 ;
V_59 [ V_29 ++ ] = 0x22 ;
V_59 [ V_29 ++ ] = 0x20 ;
V_59 [ V_29 ++ ] = ( V_78 >> 24 ) ;
V_59 [ V_29 ++ ] = ( V_78 >> 16 ) & 0xff ;
V_59 [ V_29 ++ ] = ( V_78 >> 8 ) & 0xff ;
V_59 [ V_29 ++ ] = V_78 & 0xff ;
V_59 [ V_29 ++ ] = 0x61 ;
V_59 [ V_29 ++ ] = 0x95 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x4 ;
V_59 [ V_29 ++ ] = 0 ;
V_59 [ V_29 ++ ] = 0 ;
V_59 [ V_29 ++ ] = ( V_73 >> 8 ) & 0xff ;
V_59 [ V_29 ++ ] = V_73 & 0xff ;
V_59 [ V_29 ++ ] = 0x61 ;
V_59 [ V_29 ++ ] = 0xa3 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x8 ;
V_59 [ V_29 ++ ] = 0x52 ;
V_59 [ V_29 ++ ] = 0x22 ;
V_59 [ V_29 ++ ] = 0x22 ;
V_59 [ V_29 ++ ] = 0x20 ;
V_59 [ V_29 ++ ] = ( V_74 >> 24 ) ;
V_59 [ V_29 ++ ] = ( V_74 >> 16 ) & 0xff ;
V_59 [ V_29 ++ ] = ( V_74 >> 8 ) & 0xff ;
V_59 [ V_29 ++ ] = V_74 & 0xff ;
V_59 [ V_29 ++ ] = 0x63 ;
V_59 [ V_29 ++ ] = 0xa8 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 24 ;
memcpy ( V_59 + V_29 , L_8 , 12 ) ;
V_29 += 12 ;
snprintf ( V_79 , sizeof( V_79 ) , L_9 , V_74 ) ;
memcpy ( V_59 + V_29 , V_79 , 8 ) ;
V_29 += 8 ;
memset ( V_59 + V_29 , 0 , 4 ) ;
V_29 += 4 ;
return V_29 ;
}
static int F_20 ( unsigned char * V_59 )
{
memcpy ( V_59 , V_82 , sizeof( V_82 ) ) ;
return sizeof( V_82 ) ;
}
static int F_21 ( unsigned char * V_59 )
{
int V_29 = 0 ;
const char * V_83 = L_10 ;
const char * V_84 = L_11 ;
int V_85 , V_86 ;
V_59 [ V_29 ++ ] = 0x1 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_86 = strlen ( V_83 ) ;
V_85 = V_86 + 1 ;
if ( V_85 % 4 )
V_85 = ( ( V_85 / 4 ) + 1 ) * 4 ;
V_59 [ V_29 ++ ] = V_85 ;
memcpy ( V_59 + V_29 , V_83 , V_86 ) ;
memset ( V_59 + V_29 + V_86 , 0 , V_85 - V_86 ) ;
V_29 += V_85 ;
V_59 [ V_29 ++ ] = 0x4 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_86 = strlen ( V_84 ) ;
V_85 = V_86 + 1 ;
if ( V_85 % 4 )
V_85 = ( ( V_85 / 4 ) + 1 ) * 4 ;
V_59 [ V_29 ++ ] = V_85 ;
memcpy ( V_59 + V_29 , V_84 , V_86 ) ;
memset ( V_59 + V_29 + V_86 , 0 , V_85 - V_86 ) ;
V_29 += V_85 ;
return V_29 ;
}
static int F_22 ( unsigned char * V_59 , int V_74 )
{
int V_29 = 0 ;
int V_78 , V_87 ;
V_78 = V_74 + 1 ;
V_87 = V_78 + 1 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x1 ;
memset ( V_59 + V_29 , 0 , 6 ) ;
V_29 += 6 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 12 ;
V_59 [ V_29 ++ ] = 0x61 ;
V_59 [ V_29 ++ ] = 0x93 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x8 ;
V_59 [ V_29 ++ ] = 0x52 ;
V_59 [ V_29 ++ ] = 0x22 ;
V_59 [ V_29 ++ ] = 0x22 ;
V_59 [ V_29 ++ ] = 0x20 ;
V_59 [ V_29 ++ ] = ( V_78 >> 24 ) ;
V_59 [ V_29 ++ ] = ( V_78 >> 16 ) & 0xff ;
V_59 [ V_29 ++ ] = ( V_78 >> 8 ) & 0xff ;
V_59 [ V_29 ++ ] = V_78 & 0xff ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x2 ;
memset ( V_59 + V_29 , 0 , 6 ) ;
V_29 += 6 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 12 ;
V_59 [ V_29 ++ ] = 0x61 ;
V_59 [ V_29 ++ ] = 0x93 ;
V_59 [ V_29 ++ ] = 0x0 ;
V_59 [ V_29 ++ ] = 0x8 ;
V_59 [ V_29 ++ ] = 0x52 ;
V_59 [ V_29 ++ ] = 0x22 ;
V_59 [ V_29 ++ ] = 0x22 ;
V_59 [ V_29 ++ ] = 0x20 ;
V_59 [ V_29 ++ ] = ( V_87 >> 24 ) ;
V_59 [ V_29 ++ ] = ( V_87 >> 16 ) & 0xff ;
V_59 [ V_29 ++ ] = ( V_87 >> 8 ) & 0xff ;
V_59 [ V_29 ++ ] = V_87 & 0xff ;
return V_29 ;
}
static int F_23 ( unsigned char * V_59 )
{
memcpy ( V_59 , V_88 , sizeof( V_88 ) ) ;
return sizeof( V_88 ) ;
}
static int F_24 ( unsigned char * V_59 )
{
unsigned int V_89 ;
memcpy ( V_59 , V_90 , sizeof( V_90 ) ) ;
V_89 = 1 << V_91 ;
V_59 [ 2 ] = ( V_89 >> 8 ) & 0xff ;
V_59 [ 3 ] = V_89 & 0xff ;
if ( V_92 > 0x400 ) {
V_59 [ 4 ] = ( V_92 >> 24 ) & 0xff ;
V_59 [ 5 ] = ( V_92 >> 16 ) & 0xff ;
V_59 [ 6 ] = ( V_92 >> 8 ) & 0xff ;
V_59 [ 7 ] = V_92 & 0xff ;
}
F_25 ( V_93 , & V_59 [ 8 ] ) ;
if ( V_1 ) {
F_25 ( V_94 , & V_59 [ 16 ] ) ;
F_25 ( V_95 , & V_59 [ 20 ] ) ;
}
if ( V_96 ) {
F_25 ( V_96 , & V_59 [ 28 ] ) ;
V_59 [ 28 ] |= 0x80 ;
}
F_25 ( V_97 , & V_59 [ 24 ] ) ;
F_26 ( V_98 , & V_59 [ 32 ] ) ;
return 0x3c ;
return sizeof( V_90 ) ;
}
static int F_27 ( unsigned char * V_59 )
{
memset ( V_59 , 0 , 0x3c ) ;
V_59 [ 0 ] = 0 ;
V_59 [ 1 ] = 1 ;
V_59 [ 2 ] = 0 ;
V_59 [ 3 ] = 5 ;
return 0x3c ;
}
static int F_28 ( unsigned char * V_59 )
{
memset ( V_59 , 0 , 0x4 ) ;
V_59 [ 0 ] = 0 ;
if ( V_1 )
V_59 [ 1 ] = 1 << 7 ;
if ( V_2 )
V_59 [ 1 ] |= 1 << 6 ;
if ( V_3 )
V_59 [ 1 ] |= 1 << 5 ;
if ( V_99 )
V_59 [ 1 ] |= 1 << 2 ;
return 0x4 ;
}
static int F_29 ( struct V_48 * V_58 , int V_100 ,
struct V_15 * V_16 )
{
unsigned char V_101 ;
unsigned char * V_59 ;
unsigned char * V_27 = ( unsigned char * ) V_58 -> V_102 ;
int V_103 , V_104 , V_105 ;
V_103 = ( V_27 [ 3 ] << 8 ) + V_27 [ 4 ] ;
V_59 = F_30 ( V_106 , V_107 ) ;
if ( ! V_59 )
return V_108 << 16 ;
if ( V_16 -> V_109 )
V_101 = 0x1e ;
else if ( V_110 && ( 0 == V_16 -> V_111 ) )
V_101 = 0x7f ;
else
V_101 = ( V_112 & 0x1f ) ;
V_59 [ 0 ] = V_101 ;
if ( 0x2 & V_27 [ 1 ] ) {
F_6 ( V_16 , V_113 , V_114 ,
0 ) ;
F_31 ( V_59 ) ;
return V_54 ;
} else if ( 0x1 & V_27 [ 1 ] ) {
int V_115 , V_73 , V_74 , V_116 ;
char V_117 [ 6 ] ;
int V_118 = V_16 -> V_5 -> V_9 -> V_118 ;
V_73 = ( ( ( V_118 + 1 ) & 0x7f ) << 8 ) +
( V_16 -> V_119 & 0x7f ) ;
if ( 0 == V_120 )
V_118 = 0 ;
V_115 = V_16 -> V_109 ? - 1 : ( ( ( V_118 + 1 ) * 2000 ) +
( V_16 -> V_100 * 1000 ) + V_16 -> V_111 ) ;
V_74 = ( ( V_118 + 1 ) * 2000 ) +
( V_16 -> V_100 * 1000 ) - 3 ;
V_116 = F_32 ( V_117 , 6 , L_12 , V_115 ) ;
if ( 0 == V_27 [ 2 ] ) {
V_59 [ 1 ] = V_27 [ 2 ] ;
V_104 = 4 ;
V_59 [ V_104 ++ ] = 0x0 ;
V_59 [ V_104 ++ ] = 0x80 ;
V_59 [ V_104 ++ ] = 0x83 ;
V_59 [ V_104 ++ ] = 0x84 ;
V_59 [ V_104 ++ ] = 0x85 ;
V_59 [ V_104 ++ ] = 0x86 ;
V_59 [ V_104 ++ ] = 0x87 ;
V_59 [ V_104 ++ ] = 0x88 ;
V_59 [ V_104 ++ ] = 0x89 ;
V_59 [ V_104 ++ ] = 0xb0 ;
V_59 [ V_104 ++ ] = 0xb1 ;
if ( F_1 () )
V_59 [ V_104 ++ ] = 0xb2 ;
V_59 [ 3 ] = V_104 - 4 ;
} else if ( 0x80 == V_27 [ 2 ] ) {
V_59 [ 1 ] = V_27 [ 2 ] ;
V_59 [ 3 ] = V_116 ;
memcpy ( & V_59 [ 4 ] , V_117 , V_116 ) ;
} else if ( 0x83 == V_27 [ 2 ] ) {
V_59 [ 1 ] = V_27 [ 2 ] ;
V_59 [ 3 ] = F_19 ( & V_59 [ 4 ] , V_73 ,
V_74 , V_115 ,
V_117 , V_116 ) ;
} else if ( 0x84 == V_27 [ 2 ] ) {
V_59 [ 1 ] = V_27 [ 2 ] ;
V_59 [ 3 ] = F_20 ( & V_59 [ 4 ] ) ;
} else if ( 0x85 == V_27 [ 2 ] ) {
V_59 [ 1 ] = V_27 [ 2 ] ;
V_59 [ 3 ] = F_21 ( & V_59 [ 4 ] ) ;
} else if ( 0x86 == V_27 [ 2 ] ) {
V_59 [ 1 ] = V_27 [ 2 ] ;
V_59 [ 3 ] = 0x3c ;
if ( V_121 == V_122 )
V_59 [ 4 ] = 0x4 ;
else if ( V_121 )
V_59 [ 4 ] = 0x5 ;
else
V_59 [ 4 ] = 0x0 ;
V_59 [ 5 ] = 0x7 ;
} else if ( 0x87 == V_27 [ 2 ] ) {
V_59 [ 1 ] = V_27 [ 2 ] ;
V_59 [ 3 ] = 0x8 ;
V_59 [ 4 ] = 0x2 ;
V_59 [ 6 ] = 0x80 ;
V_59 [ 8 ] = 0x18 ;
V_59 [ 10 ] = 0x82 ;
} else if ( 0x88 == V_27 [ 2 ] ) {
V_59 [ 1 ] = V_27 [ 2 ] ;
V_59 [ 3 ] = F_22 ( & V_59 [ 4 ] , V_74 ) ;
} else if ( 0x89 == V_27 [ 2 ] ) {
V_59 [ 1 ] = V_27 [ 2 ] ;
V_104 = F_23 ( & V_59 [ 4 ] ) ;
V_59 [ 2 ] = ( V_104 >> 8 ) ;
V_59 [ 3 ] = ( V_104 & 0xff ) ;
} else if ( 0xb0 == V_27 [ 2 ] ) {
V_59 [ 1 ] = V_27 [ 2 ] ;
V_59 [ 3 ] = F_24 ( & V_59 [ 4 ] ) ;
} else if ( 0xb1 == V_27 [ 2 ] ) {
V_59 [ 1 ] = V_27 [ 2 ] ;
V_59 [ 3 ] = F_27 ( & V_59 [ 4 ] ) ;
} else if ( 0xb2 == V_27 [ 2 ] ) {
V_59 [ 1 ] = V_27 [ 2 ] ;
V_59 [ 3 ] = F_28 ( & V_59 [ 4 ] ) ;
} else {
F_6 ( V_16 , V_113 ,
V_114 , 0 ) ;
F_31 ( V_59 ) ;
return V_54 ;
}
V_116 = F_33 ( ( ( V_59 [ 2 ] << 8 ) + V_59 [ 3 ] ) + 4 , V_103 ) ;
V_105 = F_12 ( V_58 , V_59 ,
F_33 ( V_116 , V_106 ) ) ;
F_31 ( V_59 ) ;
return V_105 ;
}
V_59 [ 1 ] = V_123 ? 0x80 : 0 ;
V_59 [ 2 ] = V_124 ;
V_59 [ 3 ] = 2 ;
V_59 [ 4 ] = V_125 - 5 ;
V_59 [ 5 ] = V_121 ? 1 : 0 ;
if ( 0 == V_120 )
V_59 [ 5 ] = 0x10 ;
V_59 [ 6 ] = 0x10 ;
V_59 [ 7 ] = 0xa ;
memcpy ( & V_59 [ 8 ] , V_80 , 8 ) ;
memcpy ( & V_59 [ 16 ] , V_81 , 16 ) ;
memcpy ( & V_59 [ 32 ] , V_126 , 4 ) ;
V_59 [ 58 ] = 0x0 ; V_59 [ 59 ] = 0x77 ;
V_59 [ 60 ] = 0x3 ; V_59 [ 61 ] = 0x14 ;
V_104 = 62 ;
if ( V_112 == 0 ) {
V_59 [ V_104 ++ ] = 0x3 ; V_59 [ V_104 ++ ] = 0x3d ;
} else if ( V_112 == 1 ) {
V_59 [ V_104 ++ ] = 0x3 ; V_59 [ V_104 ++ ] = 0x60 ;
}
V_59 [ V_104 ++ ] = 0xc ; V_59 [ V_104 ++ ] = 0xf ;
V_105 = F_12 ( V_58 , V_59 ,
F_33 ( V_103 , V_125 ) ) ;
F_31 ( V_59 ) ;
return V_105 ;
}
static int F_34 ( struct V_48 * V_58 ,
struct V_15 * V_16 )
{
unsigned char * V_20 ;
unsigned char * V_27 = ( unsigned char * ) V_58 -> V_102 ;
unsigned char V_59 [ V_22 ] ;
int V_127 ;
int V_116 = 18 ;
memset ( V_59 , 0 , sizeof( V_59 ) ) ;
if ( V_16 -> V_51 == 1 )
F_6 ( V_16 , 0 , V_128 , 0 ) ;
V_127 = ! ! ( V_27 [ 1 ] & 1 ) || V_23 ;
V_20 = V_16 -> V_21 ;
if ( ( V_129 [ 2 ] & 0x4 ) && ( 6 == ( V_129 [ 3 ] & 0xf ) ) ) {
if ( V_127 ) {
V_59 [ 0 ] = 0x72 ;
V_59 [ 1 ] = 0x0 ;
V_59 [ 2 ] = V_130 ;
V_59 [ 3 ] = 0xff ;
} else {
V_59 [ 0 ] = 0x70 ;
V_59 [ 2 ] = 0x0 ;
V_59 [ 7 ] = 0xa ;
V_59 [ 12 ] = V_130 ;
V_59 [ 13 ] = 0xff ;
}
} else {
memcpy ( V_59 , V_20 , V_22 ) ;
if ( ( V_27 [ 1 ] & 1 ) && ( ! V_23 ) ) {
memset ( V_59 , 0 , sizeof( V_59 ) ) ;
V_59 [ 0 ] = 0x72 ;
V_59 [ 1 ] = V_20 [ 2 ] ;
V_59 [ 2 ] = V_20 [ 12 ] ;
V_59 [ 3 ] = V_20 [ 13 ] ;
V_116 = 8 ;
}
}
F_6 ( V_16 , 0 , V_128 , 0 ) ;
return F_12 ( V_58 , V_59 , V_116 ) ;
}
static int F_35 ( struct V_48 * V_58 ,
struct V_15 * V_16 )
{
unsigned char * V_27 = ( unsigned char * ) V_58 -> V_102 ;
int V_131 , V_132 , V_133 ;
if ( ( V_132 = F_11 ( V_58 , 1 , V_16 ) ) )
return V_132 ;
V_131 = ( V_27 [ 4 ] & 0xf0 ) >> 4 ;
if ( V_131 ) {
F_6 ( V_16 , V_113 , V_114 ,
0 ) ;
return V_54 ;
}
V_133 = V_27 [ 4 ] & 1 ;
if ( V_133 == V_16 -> V_55 )
V_16 -> V_55 = ! V_133 ;
return 0 ;
}
static T_3 F_36 ( void )
{
if ( V_134 > 0 )
return ( T_3 ) V_134 *
( 1073741824 / V_135 ) ;
else
return V_92 ;
}
static int F_37 ( struct V_48 * V_58 ,
struct V_15 * V_16 )
{
unsigned char V_59 [ V_136 ] ;
unsigned int V_137 ;
int V_132 ;
if ( ( V_132 = F_11 ( V_58 , 1 , V_16 ) ) )
return V_132 ;
V_138 = F_36 () ;
memset ( V_59 , 0 , V_136 ) ;
if ( V_138 < 0xffffffff ) {
V_137 = ( unsigned int ) V_138 - 1 ;
V_59 [ 0 ] = ( V_137 >> 24 ) ;
V_59 [ 1 ] = ( V_137 >> 16 ) & 0xff ;
V_59 [ 2 ] = ( V_137 >> 8 ) & 0xff ;
V_59 [ 3 ] = V_137 & 0xff ;
} else {
V_59 [ 0 ] = 0xff ;
V_59 [ 1 ] = 0xff ;
V_59 [ 2 ] = 0xff ;
V_59 [ 3 ] = 0xff ;
}
V_59 [ 6 ] = ( V_135 >> 8 ) & 0xff ;
V_59 [ 7 ] = V_135 & 0xff ;
return F_12 ( V_58 , V_59 , V_136 ) ;
}
static int F_38 ( struct V_48 * V_58 ,
struct V_15 * V_16 )
{
unsigned char * V_27 = ( unsigned char * ) V_58 -> V_102 ;
unsigned char V_59 [ V_139 ] ;
unsigned long long V_137 ;
int V_132 , V_140 , V_103 ;
if ( ( V_132 = F_11 ( V_58 , 1 , V_16 ) ) )
return V_132 ;
V_103 = ( ( V_27 [ 10 ] << 24 ) + ( V_27 [ 11 ] << 16 ) + ( V_27 [ 12 ] << 8 )
+ V_27 [ 13 ] ) ;
V_138 = F_36 () ;
memset ( V_59 , 0 , V_139 ) ;
V_137 = V_138 - 1 ;
for ( V_140 = 0 ; V_140 < 8 ; ++ V_140 , V_137 >>= 8 )
V_59 [ 7 - V_140 ] = V_137 & 0xff ;
V_59 [ 8 ] = ( V_135 >> 24 ) & 0xff ;
V_59 [ 9 ] = ( V_135 >> 16 ) & 0xff ;
V_59 [ 10 ] = ( V_135 >> 8 ) & 0xff ;
V_59 [ 11 ] = V_135 & 0xff ;
V_59 [ 13 ] = V_91 & 0xf ;
V_59 [ 14 ] = ( V_141 >> 8 ) & 0x3f ;
if ( F_1 () ) {
V_59 [ 14 ] |= 0x80 ;
if ( V_99 )
V_59 [ 14 ] |= 0x40 ;
}
V_59 [ 15 ] = V_141 & 0xff ;
if ( V_121 ) {
V_59 [ 12 ] = ( V_121 - 1 ) << 1 ;
V_59 [ 12 ] |= 1 ;
}
return F_12 ( V_58 , V_59 ,
F_33 ( V_103 , V_139 ) ) ;
}
static int F_39 ( struct V_48 * V_58 ,
struct V_15 * V_16 )
{
unsigned char * V_27 = ( unsigned char * ) V_58 -> V_102 ;
unsigned char * V_59 ;
int V_118 = V_16 -> V_5 -> V_9 -> V_118 ;
int V_104 , V_105 , V_142 , V_143 ;
int V_144 , V_145 , V_78 , V_87 ;
V_142 = ( ( V_27 [ 6 ] << 24 ) + ( V_27 [ 7 ] << 16 ) + ( V_27 [ 8 ] << 8 )
+ V_27 [ 9 ] ) ;
V_59 = F_30 ( V_146 , V_107 ) ;
if ( ! V_59 )
return V_108 << 16 ;
V_78 = 0x1 ;
V_87 = 0x2 ;
V_144 = ( ( ( V_118 + 1 ) & 0x7f ) << 8 ) +
( V_16 -> V_119 & 0x7f ) ;
V_145 = ( ( ( V_118 + 1 ) & 0x7f ) << 8 ) +
( V_16 -> V_119 & 0x7f ) + 0x80 ;
V_104 = 4 ;
if ( 0 == V_120 ) {
V_59 [ V_104 ++ ] = V_118 % 3 ;
V_59 [ V_104 ++ ] = 0x0F ;
} else {
V_59 [ V_104 ++ ] = 0x0 ;
V_59 [ V_104 ++ ] = 0x01 ;
}
V_59 [ V_104 ++ ] = ( V_144 >> 8 ) & 0xff ;
V_59 [ V_104 ++ ] = V_144 & 0xff ;
V_59 [ V_104 ++ ] = 0 ;
V_59 [ V_104 ++ ] = 0 ;
V_59 [ V_104 ++ ] = 0 ;
V_59 [ V_104 ++ ] = 0x1 ;
V_59 [ V_104 ++ ] = 0 ;
V_59 [ V_104 ++ ] = 0 ;
V_59 [ V_104 ++ ] = ( V_78 >> 8 ) & 0xff ;
V_59 [ V_104 ++ ] = V_78 & 0xff ;
V_59 [ V_104 ++ ] = 3 ;
V_59 [ V_104 ++ ] = 0x08 ;
V_59 [ V_104 ++ ] = ( V_145 >> 8 ) & 0xff ;
V_59 [ V_104 ++ ] = V_145 & 0xff ;
V_59 [ V_104 ++ ] = 0 ;
V_59 [ V_104 ++ ] = 0 ;
V_59 [ V_104 ++ ] = 0 ;
V_59 [ V_104 ++ ] = 0x1 ;
V_59 [ V_104 ++ ] = 0 ;
V_59 [ V_104 ++ ] = 0 ;
V_59 [ V_104 ++ ] = ( V_87 >> 8 ) & 0xff ;
V_59 [ V_104 ++ ] = V_87 & 0xff ;
V_143 = V_104 - 4 ;
V_59 [ 0 ] = ( V_143 >> 24 ) & 0xff ;
V_59 [ 1 ] = ( V_143 >> 16 ) & 0xff ;
V_59 [ 2 ] = ( V_143 >> 8 ) & 0xff ;
V_59 [ 3 ] = V_143 & 0xff ;
V_143 = F_33 ( V_142 , V_104 ) ;
V_105 = F_12 ( V_58 , V_59 ,
F_33 ( V_143 , V_146 ) ) ;
F_31 ( V_59 ) ;
return V_105 ;
}
static int F_40 ( unsigned char * V_147 , int V_148 , int V_100 )
{
unsigned char V_149 [] = { 0x1 , 0xa , 0xc0 , 11 , 240 , 0 , 0 , 0 ,
5 , 0 , 0xff , 0xff } ;
memcpy ( V_147 , V_149 , sizeof( V_149 ) ) ;
if ( 1 == V_148 )
memset ( V_147 + 2 , 0 , sizeof( V_149 ) - 2 ) ;
return sizeof( V_149 ) ;
}
static int F_41 ( unsigned char * V_147 , int V_148 , int V_100 )
{
unsigned char V_150 [] = { 0x2 , 0xe , 128 , 128 , 0 , 10 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_147 , V_150 , sizeof( V_150 ) ) ;
if ( 1 == V_148 )
memset ( V_147 + 2 , 0 , sizeof( V_150 ) - 2 ) ;
return sizeof( V_150 ) ;
}
static int F_42 ( unsigned char * V_147 , int V_148 , int V_100 )
{
unsigned char V_151 [] = { 0x3 , 0x16 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0x40 , 0 , 0 , 0 } ;
memcpy ( V_147 , V_151 , sizeof( V_151 ) ) ;
V_147 [ 10 ] = ( V_152 >> 8 ) & 0xff ;
V_147 [ 11 ] = V_152 & 0xff ;
V_147 [ 12 ] = ( V_135 >> 8 ) & 0xff ;
V_147 [ 13 ] = V_135 & 0xff ;
if ( V_123 )
V_147 [ 20 ] |= 0x20 ;
if ( 1 == V_148 )
memset ( V_147 + 2 , 0 , sizeof( V_151 ) - 2 ) ;
return sizeof( V_151 ) ;
}
static int F_43 ( unsigned char * V_147 , int V_148 , int V_100 )
{
unsigned char V_153 [] = { 0x8 , 18 , 0x14 , 0 , 0xff , 0xff , 0 , 0 ,
0xff , 0xff , 0xff , 0xff , 0x80 , 0x14 , 0 , 0 , 0 , 0 , 0 , 0 } ;
memcpy ( V_147 , V_153 , sizeof( V_153 ) ) ;
if ( 1 == V_148 )
memset ( V_147 + 2 , 0 , sizeof( V_153 ) - 2 ) ;
return sizeof( V_153 ) ;
}
static int F_44 ( unsigned char * V_147 , int V_148 , int V_100 )
{
unsigned char V_154 [] = { 0x6 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ;
unsigned char V_155 [] = { 0xa , 10 , 2 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0x2 , 0x4b } ;
if ( V_23 )
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
static int F_45 ( unsigned char * V_147 , int V_148 , int V_100 )
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
static int F_46 ( unsigned char * V_147 , int V_148 , int V_100 )
{
unsigned char V_160 [] = { 0x19 , 0x6 ,
0x6 , 0x0 , 0x7 , 0xd0 , 0x0 , 0x0 } ;
memcpy ( V_147 , V_160 , sizeof( V_160 ) ) ;
if ( 1 == V_148 )
memset ( V_147 + 2 , 0 , sizeof( V_160 ) - 2 ) ;
return sizeof( V_160 ) ;
}
static int F_47 ( unsigned char * V_147 , int V_148 , int V_100 ,
int V_74 )
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
int V_78 , V_87 ;
V_78 = V_74 + 1 ;
V_87 = V_78 + 1 ;
memcpy ( V_147 , V_161 , sizeof( V_161 ) ) ;
V_147 [ 20 ] = ( V_78 >> 24 ) ;
V_147 [ 21 ] = ( V_78 >> 16 ) & 0xff ;
V_147 [ 22 ] = ( V_78 >> 8 ) & 0xff ;
V_147 [ 23 ] = V_78 & 0xff ;
V_147 [ 48 + 20 ] = ( V_87 >> 24 ) ;
V_147 [ 48 + 21 ] = ( V_87 >> 16 ) & 0xff ;
V_147 [ 48 + 22 ] = ( V_87 >> 8 ) & 0xff ;
V_147 [ 48 + 23 ] = V_87 & 0xff ;
if ( 1 == V_148 )
memset ( V_147 + 4 , 0 , sizeof( V_161 ) - 4 ) ;
return sizeof( V_161 ) ;
}
static int F_48 ( unsigned char * V_147 , int V_148 )
{
unsigned char V_162 [] = { 0x59 , 0x2 , 0 , 0xc , 0 , 0x6 , 0x10 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
} ;
memcpy ( V_147 , V_162 , sizeof( V_162 ) ) ;
if ( 1 == V_148 )
memset ( V_147 + 4 , 0 , sizeof( V_162 ) - 4 ) ;
return sizeof( V_162 ) ;
}
static int F_49 ( struct V_48 * V_58 , int V_100 ,
struct V_15 * V_16 )
{
unsigned char V_163 , V_164 ;
int V_148 , V_165 , V_166 , V_167 ;
unsigned char V_168 ;
int V_140 , V_103 , V_169 , V_170 , V_116 , V_132 , V_74 ;
unsigned char * V_171 ;
unsigned char V_59 [ V_172 ] ;
unsigned char * V_27 = ( unsigned char * ) V_58 -> V_102 ;
if ( ( V_132 = F_11 ( V_58 , 1 , V_16 ) ) )
return V_132 ;
V_163 = ! ! ( V_27 [ 1 ] & 0x8 ) ;
V_148 = ( V_27 [ 2 ] & 0xc0 ) >> 6 ;
V_165 = V_27 [ 2 ] & 0x3f ;
V_166 = V_27 [ 3 ] ;
V_169 = ( V_173 == V_27 [ 0 ] ) ;
V_164 = V_169 ? 0 : ! ! ( V_27 [ 1 ] & 0x10 ) ;
if ( ( 0 == V_112 ) && ( 0 == V_163 ) )
V_167 = V_164 ? 16 : 8 ;
else
V_167 = 0 ;
V_103 = V_169 ? V_27 [ 4 ] : ( ( V_27 [ 7 ] << 8 ) | V_27 [ 8 ] ) ;
memset ( V_59 , 0 , V_172 ) ;
if ( 0x3 == V_148 ) {
F_6 ( V_16 , V_113 , V_174 ,
0 ) ;
return V_54 ;
}
V_74 = ( ( V_16 -> V_5 -> V_9 -> V_118 + 1 ) * 2000 ) +
( V_16 -> V_100 * 1000 ) - 3 ;
if ( 0 == V_112 )
V_168 = ( F_50 ( V_100 ) ? 0x80 : 0x0 ) | 0x10 ;
else
V_168 = 0x0 ;
if ( V_169 ) {
V_59 [ 2 ] = V_168 ;
V_59 [ 3 ] = V_167 ;
V_170 = 4 ;
} else {
V_59 [ 3 ] = V_168 ;
if ( 16 == V_167 )
V_59 [ 4 ] = 0x1 ;
V_59 [ 7 ] = V_167 ;
V_170 = 8 ;
}
V_171 = V_59 + V_170 ;
if ( ( V_167 > 0 ) && ( ! V_138 ) )
V_138 = F_36 () ;
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
V_171 = V_59 + V_170 ;
} else if ( 16 == V_167 ) {
unsigned long long V_137 = V_138 ;
for ( V_140 = 0 ; V_140 < 8 ; ++ V_140 , V_137 >>= 8 )
V_171 [ 7 - V_140 ] = V_137 & 0xff ;
V_171 [ 12 ] = ( V_135 >> 24 ) & 0xff ;
V_171 [ 13 ] = ( V_135 >> 16 ) & 0xff ;
V_171 [ 14 ] = ( V_135 >> 8 ) & 0xff ;
V_171 [ 15 ] = V_135 & 0xff ;
V_170 += V_167 ;
V_171 = V_59 + V_170 ;
}
if ( ( V_166 > 0x0 ) && ( V_166 < 0xff ) && ( 0x19 != V_165 ) ) {
F_6 ( V_16 , V_113 , V_114 ,
0 ) ;
return V_54 ;
}
switch ( V_165 ) {
case 0x1 :
V_116 = F_40 ( V_171 , V_148 , V_100 ) ;
V_170 += V_116 ;
break;
case 0x2 :
V_116 = F_41 ( V_171 , V_148 , V_100 ) ;
V_170 += V_116 ;
break;
case 0x3 :
V_116 = F_42 ( V_171 , V_148 , V_100 ) ;
V_170 += V_116 ;
break;
case 0x8 :
V_116 = F_43 ( V_171 , V_148 , V_100 ) ;
V_170 += V_116 ;
break;
case 0xa :
V_116 = F_44 ( V_171 , V_148 , V_100 ) ;
V_170 += V_116 ;
break;
case 0x19 :
if ( ( V_166 > 0x2 ) && ( V_166 < 0xff ) ) {
F_6 ( V_16 , V_113 ,
V_114 , 0 ) ;
return V_54 ;
}
V_116 = 0 ;
if ( ( 0x0 == V_166 ) || ( 0xff == V_166 ) )
V_116 += F_46 ( V_171 + V_116 , V_148 , V_100 ) ;
if ( ( 0x1 == V_166 ) || ( 0xff == V_166 ) )
V_116 += F_47 ( V_171 + V_116 , V_148 , V_100 ,
V_74 ) ;
if ( ( 0x2 == V_166 ) || ( 0xff == V_166 ) )
V_116 += F_48 ( V_171 + V_116 , V_148 ) ;
V_170 += V_116 ;
break;
case 0x1c :
V_116 = F_45 ( V_171 , V_148 , V_100 ) ;
V_170 += V_116 ;
break;
case 0x3f :
if ( ( 0 == V_166 ) || ( 0xff == V_166 ) ) {
V_116 = F_40 ( V_171 , V_148 , V_100 ) ;
V_116 += F_41 ( V_171 + V_116 , V_148 , V_100 ) ;
V_116 += F_42 ( V_171 + V_116 , V_148 , V_100 ) ;
V_116 += F_43 ( V_171 + V_116 , V_148 , V_100 ) ;
V_116 += F_44 ( V_171 + V_116 , V_148 , V_100 ) ;
V_116 += F_46 ( V_171 + V_116 , V_148 , V_100 ) ;
if ( 0xff == V_166 ) {
V_116 += F_47 ( V_171 + V_116 , V_148 ,
V_100 , V_74 ) ;
V_116 += F_48 ( V_171 + V_116 , V_148 ) ;
}
V_116 += F_45 ( V_171 + V_116 , V_148 , V_100 ) ;
} else {
F_6 ( V_16 , V_113 ,
V_114 , 0 ) ;
return V_54 ;
}
V_170 += V_116 ;
break;
default:
F_6 ( V_16 , V_113 , V_114 ,
0 ) ;
return V_54 ;
}
if ( V_169 )
V_59 [ 0 ] = V_170 - 1 ;
else {
V_59 [ 0 ] = ( ( V_170 - 2 ) >> 8 ) & 0xff ;
V_59 [ 1 ] = ( V_170 - 2 ) & 0xff ;
}
return F_12 ( V_58 , V_59 , F_33 ( V_103 , V_170 ) ) ;
}
static int F_51 ( struct V_48 * V_58 , int V_175 ,
struct V_15 * V_16 )
{
int V_176 , V_177 , V_178 , V_179 , V_167 , V_180 , V_181 , V_182 ;
int V_183 , V_184 , V_132 , V_185 ;
unsigned char V_59 [ V_186 ] ;
unsigned char * V_27 = ( unsigned char * ) V_58 -> V_102 ;
if ( ( V_132 = F_11 ( V_58 , 1 , V_16 ) ) )
return V_132 ;
memset ( V_59 , 0 , sizeof( V_59 ) ) ;
V_176 = V_27 [ 1 ] & 0x10 ;
V_177 = V_27 [ 1 ] & 0x1 ;
V_183 = V_175 ? V_27 [ 4 ] : ( ( V_27 [ 7 ] << 8 ) + V_27 [ 8 ] ) ;
if ( ( 0 == V_176 ) || V_177 || ( V_183 > V_186 ) ) {
F_6 ( V_16 , V_113 ,
V_114 , 0 ) ;
return V_54 ;
}
V_184 = F_17 ( V_58 , V_59 , V_183 ) ;
if ( - 1 == V_184 )
return ( V_67 << 16 ) ;
else if ( ( V_184 < V_183 ) &&
( V_24 & V_25 ) )
F_8 ( V_26 L_13
L_14 , V_183 , V_184 ) ;
V_179 = V_175 ? ( V_59 [ 0 ] + 1 ) : ( ( V_59 [ 0 ] << 8 ) + V_59 [ 1 ] + 2 ) ;
V_167 = V_175 ? V_59 [ 3 ] : ( ( V_59 [ 6 ] << 8 ) + V_59 [ 7 ] ) ;
if ( V_179 > 2 ) {
F_6 ( V_16 , V_113 ,
V_187 , 0 ) ;
return V_54 ;
}
V_180 = V_167 + ( V_175 ? 4 : 8 ) ;
V_185 = V_59 [ V_180 ] & 0x3f ;
V_178 = ! ! ( V_59 [ V_180 ] & 0x80 ) ;
if ( V_178 ) {
F_6 ( V_16 , V_113 ,
V_187 , 0 ) ;
return V_54 ;
}
V_181 = ! ! ( V_59 [ V_180 ] & 0x40 ) ;
V_182 = V_181 ? ( ( V_59 [ V_180 + 2 ] << 8 ) + V_59 [ V_180 + 3 ] + 4 ) :
( V_59 [ V_180 + 1 ] + 2 ) ;
if ( ( V_182 + V_180 ) > V_183 ) {
F_6 ( V_16 , V_113 ,
V_188 , 0 ) ;
return V_54 ;
}
switch ( V_185 ) {
case 0xa :
if ( V_156 [ 1 ] == V_59 [ V_180 + 1 ] ) {
memcpy ( V_156 + 2 , V_59 + V_180 + 2 ,
sizeof( V_156 ) - 2 ) ;
V_23 = ! ! ( V_156 [ 2 ] & 0x4 ) ;
return 0 ;
}
break;
case 0x1c :
if ( V_129 [ 1 ] == V_59 [ V_180 + 1 ] ) {
memcpy ( V_129 + 2 , V_59 + V_180 + 2 ,
sizeof( V_129 ) - 2 ) ;
return 0 ;
}
break;
default:
break;
}
F_6 ( V_16 , V_113 ,
V_187 , 0 ) ;
return V_54 ;
}
static int F_52 ( unsigned char * V_59 )
{
unsigned char V_189 [] = { 0x0 , 0x0 , 0x3 , 0x2 , 0x0 , 38 ,
0x0 , 0x1 , 0x3 , 0x2 , 0x0 , 65 ,
} ;
memcpy ( V_59 , V_189 , sizeof( V_189 ) ) ;
return sizeof( V_189 ) ;
}
static int F_53 ( unsigned char * V_59 )
{
unsigned char V_190 [] = { 0x0 , 0x0 , 0x3 , 0x3 , 0x0 , 0x0 , 38 ,
} ;
memcpy ( V_59 , V_190 , sizeof( V_190 ) ) ;
if ( V_129 [ 2 ] & 0x4 ) {
V_59 [ 4 ] = V_130 ;
V_59 [ 5 ] = 0xff ;
}
return sizeof( V_190 ) ;
}
static int F_54 ( struct V_48 * V_58 ,
struct V_15 * V_16 )
{
int V_191 , V_177 , V_148 , V_165 , V_166 , V_103 , V_132 , V_116 , V_104 ;
unsigned char V_59 [ V_192 ] ;
unsigned char * V_27 = ( unsigned char * ) V_58 -> V_102 ;
if ( ( V_132 = F_11 ( V_58 , 1 , V_16 ) ) )
return V_132 ;
memset ( V_59 , 0 , sizeof( V_59 ) ) ;
V_191 = V_27 [ 1 ] & 0x2 ;
V_177 = V_27 [ 1 ] & 0x1 ;
if ( V_191 || V_177 ) {
F_6 ( V_16 , V_113 ,
V_114 , 0 ) ;
return V_54 ;
}
V_148 = ( V_27 [ 2 ] & 0xc0 ) >> 6 ;
V_165 = V_27 [ 2 ] & 0x3f ;
V_166 = V_27 [ 3 ] & 0xff ;
V_103 = ( V_27 [ 7 ] << 8 ) + V_27 [ 8 ] ;
V_59 [ 0 ] = V_165 ;
if ( 0 == V_166 ) {
switch ( V_165 ) {
case 0x0 :
V_104 = 4 ;
V_59 [ V_104 ++ ] = 0x0 ;
V_59 [ V_104 ++ ] = 0xd ;
V_59 [ V_104 ++ ] = 0x2f ;
V_59 [ 3 ] = V_104 - 4 ;
break;
case 0xd :
V_59 [ 3 ] = F_52 ( V_59 + 4 ) ;
break;
case 0x2f :
V_59 [ 3 ] = F_53 ( V_59 + 4 ) ;
break;
default:
F_6 ( V_16 , V_113 ,
V_114 , 0 ) ;
return V_54 ;
}
} else if ( 0xff == V_166 ) {
V_59 [ 0 ] |= 0x40 ;
V_59 [ 1 ] = V_166 ;
switch ( V_165 ) {
case 0x0 :
V_104 = 4 ;
V_59 [ V_104 ++ ] = 0x0 ;
V_59 [ V_104 ++ ] = 0x0 ;
V_59 [ V_104 ++ ] = 0x0 ;
V_59 [ V_104 ++ ] = 0xff ;
V_59 [ V_104 ++ ] = 0xd ;
V_59 [ V_104 ++ ] = 0x0 ;
V_59 [ V_104 ++ ] = 0x2f ;
V_59 [ V_104 ++ ] = 0x0 ;
V_59 [ 3 ] = V_104 - 4 ;
break;
case 0xd :
V_104 = 4 ;
V_59 [ V_104 ++ ] = 0xd ;
V_59 [ V_104 ++ ] = 0x0 ;
V_59 [ 3 ] = V_104 - 4 ;
break;
case 0x2f :
V_104 = 4 ;
V_59 [ V_104 ++ ] = 0x2f ;
V_59 [ V_104 ++ ] = 0x0 ;
V_59 [ 3 ] = V_104 - 4 ;
break;
default:
F_6 ( V_16 , V_113 ,
V_114 , 0 ) ;
return V_54 ;
}
} else {
F_6 ( V_16 , V_113 ,
V_114 , 0 ) ;
return V_54 ;
}
V_116 = F_33 ( ( ( V_59 [ 2 ] << 8 ) + V_59 [ 3 ] ) + 4 , V_103 ) ;
return F_12 ( V_58 , V_59 ,
F_33 ( V_116 , V_106 ) ) ;
}
static int F_55 ( struct V_15 * V_193 ,
unsigned long long V_28 , unsigned int V_29 )
{
if ( V_28 + V_29 > V_138 ) {
F_6 ( V_193 , V_113 , V_194 , 0 ) ;
return V_54 ;
}
if ( V_29 > V_92 ) {
F_6 ( V_193 , V_113 , V_114 , 0 ) ;
return V_54 ;
}
return 0 ;
}
static int F_56 ( struct V_48 * V_195 ,
struct V_15 * V_193 ,
unsigned long long V_28 , unsigned int V_29 , int V_196 )
{
int V_105 ;
unsigned long long V_197 , V_198 = 0 ;
struct V_62 * V_63 ;
enum V_199 V_200 ;
T_4 (* F_57)( struct V_201 * , unsigned int , void * , T_4 ,
T_5 );
if ( V_196 ) {
V_63 = F_58 ( V_195 ) ;
V_200 = V_72 ;
F_57 = V_202 ;
} else {
V_63 = F_13 ( V_195 ) ;
V_200 = V_66 ;
F_57 = V_203 ;
}
if ( ! V_63 -> V_64 )
return 0 ;
if ( ! ( F_14 ( V_195 ) || V_195 -> V_65 == V_200 ) )
return - 1 ;
V_197 = F_59 ( V_28 , V_92 ) ;
if ( V_197 + V_29 > V_92 )
V_198 = V_197 + V_29 - V_92 ;
V_105 = F_57 ( V_63 -> V_68 . V_69 , V_63 -> V_68 . V_70 ,
V_204 + ( V_197 * V_135 ) ,
( V_29 - V_198 ) * V_135 , 0 ) ;
if ( V_105 != ( V_29 - V_198 ) * V_135 )
return V_105 ;
if ( V_198 ) {
V_105 += F_57 ( V_63 -> V_68 . V_69 , V_63 -> V_68 . V_70 ,
V_204 , V_198 * V_135 ,
( V_29 - V_198 ) * V_135 ) ;
}
return V_105 ;
}
static T_6 F_60 ( const void * V_205 , int V_116 )
{
T_6 V_206 ;
switch ( V_207 ) {
case 1 :
V_206 = F_61 ( V_205 , V_116 ) ;
break;
case 0 :
V_206 = F_62 ( F_63 ( V_205 , V_116 ) ) ;
break;
}
return V_206 ;
}
static int F_64 ( struct V_208 * V_209 , const void * V_210 ,
T_3 V_211 , T_1 V_30 )
{
T_6 V_206 = F_60 ( V_210 , V_135 ) ;
if ( V_209 -> V_212 != V_206 ) {
F_65 ( L_15 ,
V_213 ,
( unsigned long ) V_211 ,
F_66 ( V_209 -> V_212 ) ,
F_66 ( V_206 ) ) ;
return 0x01 ;
}
if ( V_121 == V_214 &&
F_67 ( V_209 -> V_215 ) != ( V_211 & 0xffffffff ) ) {
F_65 ( L_16 ,
V_213 , ( unsigned long ) V_211 ) ;
return 0x03 ;
}
if ( V_121 == V_216 &&
F_67 ( V_209 -> V_215 ) != V_30 ) {
F_65 ( L_16 ,
V_213 , ( unsigned long ) V_211 ) ;
V_217 ++ ;
return 0x03 ;
}
return 0 ;
}
static int F_68 ( struct V_48 * V_49 , T_3 V_218 ,
unsigned int V_219 , T_1 V_30 )
{
unsigned int V_220 , V_71 ;
struct V_201 * V_221 ;
struct V_208 * V_209 ;
T_3 V_211 ;
T_3 V_222 = V_218 ;
void * V_223 ;
V_218 = F_59 ( V_222 , V_92 ) ;
V_209 = V_224 + V_218 ;
for ( V_220 = 0 ; V_220 < V_219 ; V_220 ++ ) {
int V_105 ;
if ( V_209 [ V_220 ] . V_225 == 0xffff )
continue;
V_211 = V_218 + V_220 ;
V_105 = F_64 ( & V_209 [ V_220 ] ,
V_204 + V_211 * V_135 ,
V_211 , V_30 ) ;
if ( V_105 ) {
V_217 ++ ;
return V_105 ;
}
V_30 ++ ;
}
V_71 = V_219 * sizeof( * V_224 ) ;
V_211 = V_218 ;
F_69 (SCpnt, psgl, scsi_prot_sg_count(SCpnt), i) {
int V_116 = F_33 ( V_221 -> V_64 , V_71 ) ;
V_223 = F_70 ( F_71 ( V_221 ) ) + V_221 -> V_170 ;
memcpy ( V_223 , V_224 + V_211 , V_116 ) ;
V_211 += V_116 / sizeof( * V_224 ) ;
if ( V_211 >= V_92 ) {
V_222 = V_211 ;
V_211 = F_59 ( V_222 , V_92 ) ;
}
V_71 -= V_116 ;
F_72 ( V_223 ) ;
}
V_226 ++ ;
return 0 ;
}
static int F_73 ( struct V_48 * V_49 , unsigned long long V_28 ,
unsigned int V_29 , struct V_15 * V_16 ,
T_1 V_30 )
{
unsigned long V_227 ;
int V_105 ;
V_105 = F_55 ( V_16 , V_28 , V_29 ) ;
if ( V_105 )
return V_105 ;
if ( ( V_228 & V_25 ) &&
( V_28 <= ( V_229 + V_230 - 1 ) ) &&
( ( V_28 + V_29 ) > V_229 ) ) {
F_6 ( V_16 , V_231 , V_232 , 0 ) ;
if ( 0x70 == ( V_16 -> V_21 [ 0 ] & 0x7f ) ) {
V_16 -> V_21 [ 0 ] |= 0x80 ;
V_105 = ( V_28 < V_229 )
? V_229 : ( int ) V_28 ;
V_16 -> V_21 [ 3 ] = ( V_105 >> 24 ) & 0xff ;
V_16 -> V_21 [ 4 ] = ( V_105 >> 16 ) & 0xff ;
V_16 -> V_21 [ 5 ] = ( V_105 >> 8 ) & 0xff ;
V_16 -> V_21 [ 6 ] = V_105 & 0xff ;
}
F_74 ( V_49 , F_16 ( V_49 ) ) ;
return V_54 ;
}
if ( V_233 && F_75 ( V_49 ) ) {
int V_234 = F_68 ( V_49 , V_28 , V_29 , V_30 ) ;
if ( V_234 ) {
F_6 ( V_16 , V_235 , 0x10 , V_234 ) ;
return V_236 ;
}
}
F_76 ( & V_237 , V_227 ) ;
V_105 = F_56 ( V_49 , V_16 , V_28 , V_29 , 0 ) ;
F_77 ( & V_237 , V_227 ) ;
if ( V_105 == - 1 )
return V_67 << 16 ;
F_13 ( V_49 ) -> V_71 = F_16 ( V_49 ) - V_105 ;
return 0 ;
}
void F_78 ( unsigned char * V_205 , int V_116 )
{
int V_220 , V_238 ;
F_8 ( V_239 L_17 ) ;
for ( V_220 = 0 ; V_220 < V_116 ; V_220 += 16 ) {
F_8 ( V_239 L_18 , V_220 ) ;
for ( V_238 = 0 ; V_238 < 16 ; V_238 ++ ) {
unsigned char V_240 = V_205 [ V_220 + V_238 ] ;
if ( V_240 >= 0x20 && V_240 < 0x7e )
F_8 ( L_19 , V_205 [ V_220 + V_238 ] ) ;
else
F_8 ( L_20 , V_205 [ V_220 + V_238 ] ) ;
}
F_8 ( L_21 ) ;
}
}
static int F_79 ( struct V_48 * V_49 , T_3 V_218 ,
unsigned int V_219 , T_1 V_30 )
{
int V_220 , V_238 , V_105 ;
struct V_208 * V_209 ;
struct V_201 * V_241 = F_80 ( V_49 ) ;
struct V_201 * V_221 = F_81 ( V_49 ) ;
void * V_242 , * V_223 ;
T_3 V_222 = V_218 ;
T_3 V_211 ;
int V_243 ;
V_211 = F_59 ( V_222 , V_92 ) ;
F_82 ( F_83 ( V_49 ) == 0 ) ;
F_82 ( F_75 ( V_49 ) == 0 ) ;
V_243 = 0 ;
F_84 (SCpnt, dsgl, scsi_sg_count(SCpnt), i) {
V_242 = F_70 ( F_71 ( V_241 ) ) + V_241 -> V_170 ;
V_223 = F_70 ( F_71 ( V_221 ) ) + V_221 -> V_170 ;
for ( V_238 = 0 ; V_238 < V_241 -> V_64 ; V_238 += V_135 ) {
if ( V_243 >= V_221 -> V_64 ) {
F_72 ( V_223 ) ;
V_221 = F_85 ( V_221 ) ;
F_82 ( V_221 == NULL ) ;
V_223 = F_70 ( F_71 ( V_221 ) )
+ V_221 -> V_170 ;
V_243 = 0 ;
}
V_209 = V_223 + V_243 ;
V_105 = F_64 ( V_209 , V_242 + V_238 , V_218 , V_30 ) ;
if ( V_105 ) {
F_78 ( V_242 + V_238 , V_135 ) ;
goto V_244;
}
memcpy ( V_224 + V_211 , V_209 , sizeof( * V_209 ) ) ;
V_211 ++ ;
if ( V_211 == V_92 )
V_211 = 0 ;
V_218 ++ ;
V_30 ++ ;
V_243 += sizeof( struct V_208 ) ;
}
F_72 ( V_223 ) ;
F_72 ( V_242 ) ;
}
V_245 ++ ;
return 0 ;
V_244:
V_217 ++ ;
F_72 ( V_223 ) ;
F_72 ( V_242 ) ;
return V_105 ;
}
static unsigned long F_86 ( T_3 V_28 )
{
if ( V_96 ) {
V_28 += V_97 -
V_96 ;
}
F_59 ( V_28 , V_97 ) ;
return V_28 ;
}
static T_3 F_87 ( unsigned long V_246 )
{
T_3 V_28 = V_246 * V_97 ;
if ( V_96 ) {
V_28 -= V_97 -
V_96 ;
}
return V_28 ;
}
static unsigned int F_88 ( T_3 V_28 , unsigned int * V_29 )
{
T_3 V_247 ;
unsigned int V_248 ;
unsigned long V_246 ;
unsigned long V_249 ;
V_246 = F_86 ( V_28 ) ;
V_248 = F_89 ( V_246 , V_250 ) ;
if ( V_248 )
V_249 = F_90 ( V_250 , V_251 , V_246 ) ;
else
V_249 = F_91 ( V_250 , V_251 , V_246 ) ;
V_247 = F_92 ( T_3 , V_92 , F_87 ( V_249 ) ) ;
* V_29 = V_247 - V_28 ;
return V_248 ;
}
static void F_93 ( T_3 V_28 , unsigned int V_116 )
{
T_3 V_247 = V_28 + V_116 ;
while ( V_28 < V_247 ) {
unsigned long V_246 = F_86 ( V_28 ) ;
if ( V_246 < V_251 )
F_94 ( V_246 , V_250 ) ;
V_28 = F_87 ( V_246 + 1 ) ;
}
}
static void F_95 ( T_3 V_28 , unsigned int V_116 )
{
T_3 V_247 = V_28 + V_116 ;
while ( V_28 < V_247 ) {
unsigned long V_246 = F_86 ( V_28 ) ;
if ( V_28 == F_87 ( V_246 ) &&
V_28 + V_97 <= V_247 &&
V_246 < V_251 ) {
F_96 ( V_246 , V_250 ) ;
if ( V_99 ) {
memset ( V_204 +
V_28 * V_135 , 0 ,
V_135 *
V_97 ) ;
}
if ( V_224 ) {
memset ( V_224 + V_28 , 0xff ,
sizeof( * V_224 ) *
V_97 ) ;
}
}
V_28 = F_87 ( V_246 + 1 ) ;
}
}
static int F_97 ( struct V_48 * V_49 , unsigned long long V_28 ,
unsigned int V_29 , struct V_15 * V_16 ,
T_1 V_30 )
{
unsigned long V_227 ;
int V_105 ;
V_105 = F_55 ( V_16 , V_28 , V_29 ) ;
if ( V_105 )
return V_105 ;
if ( V_233 && F_75 ( V_49 ) ) {
int V_234 = F_79 ( V_49 , V_28 , V_29 , V_30 ) ;
if ( V_234 ) {
F_6 ( V_16 , V_113 , 0x10 , V_234 ) ;
return V_236 ;
}
}
F_98 ( & V_237 , V_227 ) ;
V_105 = F_56 ( V_49 , V_16 , V_28 , V_29 , 1 ) ;
if ( F_1 () )
F_93 ( V_28 , V_29 ) ;
F_99 ( & V_237 , V_227 ) ;
if ( - 1 == V_105 )
return ( V_67 << 16 ) ;
else if ( ( V_105 < ( V_29 * V_135 ) ) &&
( V_24 & V_25 ) )
F_8 ( V_26 L_22
L_14 , V_29 * V_135 , V_105 ) ;
return 0 ;
}
static int F_100 ( struct V_48 * V_195 , unsigned long long V_28 ,
unsigned int V_29 , struct V_15 * V_16 ,
T_1 V_30 , unsigned int V_252 )
{
unsigned long V_227 ;
unsigned long long V_220 ;
int V_105 ;
V_105 = F_55 ( V_16 , V_28 , V_29 ) ;
if ( V_105 )
return V_105 ;
if ( V_29 > V_98 ) {
F_6 ( V_16 , V_113 , V_114 ,
0 ) ;
return V_54 ;
}
F_98 ( & V_237 , V_227 ) ;
if ( V_252 && F_1 () ) {
F_95 ( V_28 , V_29 ) ;
goto V_244;
}
V_105 = F_17 ( V_195 ,
V_204 + ( V_28 * V_135 ) ,
V_135 ) ;
if ( - 1 == V_105 ) {
F_99 ( & V_237 , V_227 ) ;
return ( V_67 << 16 ) ;
} else if ( ( V_105 < ( V_29 * V_135 ) ) &&
( V_24 & V_25 ) )
F_8 ( V_26 L_23
L_14 , V_29 * V_135 , V_105 ) ;
for ( V_220 = 1 ; V_220 < V_29 ; V_220 ++ )
memcpy ( V_204 + ( ( V_28 + V_220 ) * V_135 ) ,
V_204 + ( V_28 * V_135 ) ,
V_135 ) ;
if ( F_1 () )
F_93 ( V_28 , V_29 ) ;
V_244:
F_99 ( & V_237 , V_227 ) ;
return 0 ;
}
static int F_101 ( struct V_48 * V_195 , struct V_15 * V_16 )
{
unsigned char * V_205 ;
struct V_253 * V_254 ;
unsigned int V_220 , V_255 , V_256 ;
int V_105 ;
V_105 = F_11 ( V_195 , 1 , V_16 ) ;
if ( V_105 )
return V_105 ;
V_255 = F_102 ( & V_195 -> V_102 [ 7 ] ) ;
F_82 ( F_16 ( V_195 ) != V_255 ) ;
V_256 = ( V_255 - 8 ) / 16 ;
V_205 = F_103 ( F_16 ( V_195 ) , V_107 ) ;
if ( ! V_205 )
return V_54 ;
F_18 ( V_195 , V_205 , F_16 ( V_195 ) ) ;
F_82 ( F_102 ( & V_205 [ 0 ] ) != V_255 - 2 ) ;
F_82 ( F_102 ( & V_205 [ 2 ] ) != V_256 * 16 ) ;
V_254 = ( void * ) & V_205 [ 8 ] ;
for ( V_220 = 0 ; V_220 < V_256 ; V_220 ++ ) {
unsigned long long V_28 = F_104 ( & V_254 [ V_220 ] . V_28 ) ;
unsigned int V_29 = F_105 ( & V_254 [ V_220 ] . V_257 ) ;
V_105 = F_55 ( V_16 , V_28 , V_29 ) ;
if ( V_105 )
goto V_244;
F_95 ( V_28 , V_29 ) ;
}
V_105 = 0 ;
V_244:
F_31 ( V_205 ) ;
return V_105 ;
}
static int F_106 ( struct V_48 * V_195 ,
struct V_15 * V_16 )
{
unsigned long long V_28 ;
unsigned int V_103 , V_248 , V_29 ;
unsigned char V_59 [ V_258 ] ;
int V_105 ;
V_105 = F_11 ( V_195 , 1 , V_16 ) ;
if ( V_105 )
return V_105 ;
V_28 = F_104 ( & V_195 -> V_102 [ 2 ] ) ;
V_103 = F_105 ( & V_195 -> V_102 [ 10 ] ) ;
if ( V_103 < 24 )
return 0 ;
V_105 = F_55 ( V_16 , V_28 , 1 ) ;
if ( V_105 )
return V_105 ;
V_248 = F_88 ( V_28 , & V_29 ) ;
memset ( V_59 , 0 , V_258 ) ;
F_25 ( 20 , & V_59 [ 0 ] ) ;
F_26 ( V_28 , & V_59 [ 8 ] ) ;
F_25 ( V_29 , & V_59 [ 16 ] ) ;
V_59 [ 20 ] = ! V_248 ;
return F_12 ( V_195 , V_59 , V_258 ) ;
}
static int F_107 ( struct V_48 * V_58 ,
struct V_15 * V_16 )
{
unsigned int V_103 ;
int V_259 , V_220 , V_260 , V_29 , V_104 , V_109 , V_111 ;
unsigned char * V_27 = ( unsigned char * ) V_58 -> V_102 ;
int V_261 = ( int ) V_27 [ 2 ] ;
struct V_262 * V_263 ;
unsigned char V_59 [ V_264 ] ;
unsigned char * V_265 ;
V_103 = V_27 [ 9 ] + ( V_27 [ 8 ] << 8 ) + ( V_27 [ 7 ] << 16 ) + ( V_27 [ 6 ] << 24 ) ;
if ( ( V_103 < 4 ) || ( V_261 > 2 ) ) {
F_6 ( V_16 , V_113 , V_114 ,
0 ) ;
return V_54 ;
}
memset ( V_59 , 0 , V_264 ) ;
V_259 = V_266 ;
if ( 1 == V_261 )
V_259 = 0 ;
else if ( V_110 && ( V_259 > 0 ) )
-- V_259 ;
V_109 = ( V_261 > 0 ) ? 1 : 0 ;
V_29 = V_259 + V_109 ;
V_59 [ 2 ] = ( ( sizeof( struct V_262 ) * V_29 ) >> 8 ) & 0xff ;
V_59 [ 3 ] = ( sizeof( struct V_262 ) * V_29 ) & 0xff ;
V_104 = F_33 ( ( int ) ( ( V_264 - 8 ) /
sizeof( struct V_262 ) ) , V_29 ) ;
if ( V_104 < V_29 ) {
V_109 = 0 ;
V_259 = V_104 ;
}
V_263 = (struct V_262 * ) & V_59 [ 8 ] ;
V_265 = V_59 + V_264 ;
for ( V_220 = 0 , V_111 = ( V_110 ? 1 : 0 ) ;
( ( V_220 < V_259 ) && ( ( unsigned char * ) ( V_263 + V_220 ) < V_265 ) ) ;
V_220 ++ , V_111 ++ ) {
V_260 = ( V_111 >> 8 ) & 0x3f ;
if ( V_260 )
V_263 [ V_220 ] . V_262 [ 0 ] =
( V_260 | ( V_267 << 6 ) ) ;
V_263 [ V_220 ] . V_262 [ 1 ] = V_111 & 0xff ;
}
if ( V_109 ) {
V_263 [ V_220 ] . V_262 [ 0 ] = ( V_14 >> 8 ) & 0xff ;
V_263 [ V_220 ] . V_262 [ 1 ] = V_14 & 0xff ;
V_220 ++ ;
}
V_103 = ( unsigned char * ) ( V_263 + V_220 ) - V_59 ;
return F_12 ( V_58 , V_59 ,
F_33 ( ( int ) V_103 , V_264 ) ) ;
}
static int F_108 ( struct V_48 * V_58 , unsigned long long V_28 ,
unsigned int V_29 , struct V_15 * V_16 )
{
int V_220 , V_238 , V_105 = - 1 ;
unsigned char * V_268 , * V_205 ;
unsigned int V_170 ;
struct V_201 * V_269 ;
struct V_62 * V_63 = F_13 ( V_58 ) ;
V_205 = F_103 ( F_16 ( V_58 ) , V_107 ) ;
if ( ! V_205 )
return V_105 ;
F_18 ( V_58 , V_205 , F_16 ( V_58 ) ) ;
V_170 = 0 ;
F_109 (sdb->table.sgl, sg, sdb->table.nents, i) {
V_268 = ( unsigned char * ) F_70 ( F_71 ( V_269 ) ) ;
if ( ! V_268 )
goto V_244;
for ( V_238 = 0 ; V_238 < V_269 -> V_64 ; V_238 ++ )
* ( V_268 + V_269 -> V_170 + V_238 ) ^= * ( V_205 + V_170 + V_238 ) ;
V_170 += V_269 -> V_64 ;
F_72 ( V_268 ) ;
}
V_105 = 0 ;
V_244:
F_31 ( V_205 ) ;
return V_105 ;
}
static void F_110 ( unsigned long V_270 )
{
struct V_271 * V_272 ;
unsigned long V_227 ;
if ( V_270 >= V_273 ) {
F_8 ( V_239 L_24
L_25 ) ;
return;
}
F_111 ( & V_274 , V_227 ) ;
V_272 = & V_275 [ ( int ) V_270 ] ;
if ( ! V_272 -> V_276 ) {
F_8 ( V_239 L_26
L_27 ) ;
F_112 ( & V_274 , V_227 ) ;
return;
}
V_272 -> V_276 = 0 ;
if ( V_272 -> V_277 ) {
V_272 -> V_278 -> V_279 = V_272 -> V_280 ;
V_272 -> V_277 ( V_272 -> V_278 ) ;
}
V_272 -> V_277 = NULL ;
F_112 ( & V_274 , V_227 ) ;
}
static struct V_15 *
F_113 ( struct V_4 * V_5 , T_7 V_281 )
{
struct V_15 * V_16 ;
V_16 = F_30 ( sizeof( * V_16 ) , V_281 ) ;
if ( V_16 ) {
V_16 -> V_5 = V_5 ;
F_114 ( & V_16 -> V_282 , & V_5 -> V_283 ) ;
}
return V_16 ;
}
static struct V_15 * F_115 ( struct V_44 * V_284 )
{
struct V_4 * V_5 ;
struct V_15 * V_285 = NULL ;
struct V_15 * V_16 =
(struct V_15 * ) V_284 -> V_286 ;
if ( V_16 )
return V_16 ;
V_5 = * (struct V_4 * * ) F_116 ( V_284 -> V_287 ) ;
if ( ! V_5 ) {
F_8 ( V_239 L_28 ) ;
return NULL ;
}
F_4 (devip, &sdbg_host->dev_info_list, dev_list) {
if ( ( V_16 -> V_288 ) && ( V_16 -> V_119 == V_284 -> V_119 ) &&
( V_16 -> V_100 == V_284 -> V_289 ) &&
( V_16 -> V_111 == V_284 -> V_111 ) )
return V_16 ;
else {
if ( ( ! V_16 -> V_288 ) && ( ! V_285 ) )
V_285 = V_16 ;
}
}
if ( ! V_285 ) {
V_285 = F_113 ( V_5 , V_107 ) ;
if ( ! V_285 ) {
F_8 ( V_239 L_29 ,
V_213 , __LINE__ ) ;
return NULL ;
}
}
V_285 -> V_119 = V_284 -> V_119 ;
V_285 -> V_100 = V_284 -> V_289 ;
V_285 -> V_111 = V_284 -> V_111 ;
V_285 -> V_5 = V_5 ;
V_285 -> V_51 = 1 ;
V_285 -> V_288 = 1 ;
memset ( V_285 -> V_21 , 0 , V_22 ) ;
if ( V_23 )
V_285 -> V_21 [ 0 ] = 0x72 ;
else {
V_285 -> V_21 [ 0 ] = 0x70 ;
V_285 -> V_21 [ 7 ] = 0xa ;
}
if ( V_284 -> V_111 == V_14 )
V_285 -> V_109 = V_14 & 0xff ;
return V_285 ;
}
static int F_117 ( struct V_44 * V_290 )
{
if ( V_24 & V_25 )
F_8 ( V_26 L_30 ,
V_290 -> V_287 -> V_118 , V_290 -> V_119 , V_290 -> V_289 , V_290 -> V_111 ) ;
F_118 ( V_291 , V_290 -> V_292 ) ;
return 0 ;
}
static int F_119 ( struct V_44 * V_290 )
{
struct V_15 * V_16 ;
if ( V_24 & V_25 )
F_8 ( V_26 L_31 ,
V_290 -> V_287 -> V_118 , V_290 -> V_119 , V_290 -> V_289 , V_290 -> V_111 ) ;
if ( V_290 -> V_287 -> V_293 != V_294 )
V_290 -> V_287 -> V_293 = V_294 ;
V_16 = F_115 ( V_290 ) ;
if ( NULL == V_16 )
return 1 ;
V_290 -> V_286 = V_16 ;
if ( V_290 -> V_287 -> V_295 )
F_120 ( V_290 , V_296 ,
V_290 -> V_287 -> V_295 ) ;
F_121 ( V_290 -> V_292 , 256 * 1024 ) ;
if ( V_297 )
V_290 -> V_298 = 1 ;
return 0 ;
}
static void F_122 ( struct V_44 * V_290 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_290 -> V_286 ;
if ( V_24 & V_25 )
F_8 ( V_26 L_32 ,
V_290 -> V_287 -> V_118 , V_290 -> V_119 , V_290 -> V_289 , V_290 -> V_111 ) ;
if ( V_16 ) {
V_16 -> V_288 = 0 ;
V_290 -> V_286 = NULL ;
}
}
static int F_123 ( struct V_48 * V_102 )
{
unsigned long V_227 ;
int V_140 ;
struct V_271 * V_272 ;
F_111 ( & V_274 , V_227 ) ;
for ( V_140 = 0 ; V_140 < V_273 ; ++ V_140 ) {
V_272 = & V_275 [ V_140 ] ;
if ( V_272 -> V_276 && ( V_102 == V_272 -> V_278 ) ) {
F_124 ( & V_272 -> V_299 ) ;
V_272 -> V_276 = 0 ;
V_272 -> V_278 = NULL ;
break;
}
}
F_112 ( & V_274 , V_227 ) ;
return ( V_140 < V_273 ) ? 1 : 0 ;
}
static void F_125 ( void )
{
unsigned long V_227 ;
int V_140 ;
struct V_271 * V_272 ;
F_111 ( & V_274 , V_227 ) ;
for ( V_140 = 0 ; V_140 < V_273 ; ++ V_140 ) {
V_272 = & V_275 [ V_140 ] ;
if ( V_272 -> V_276 && V_272 -> V_278 ) {
F_124 ( & V_272 -> V_299 ) ;
V_272 -> V_276 = 0 ;
V_272 -> V_278 = NULL ;
}
}
F_112 ( & V_274 , V_227 ) ;
}
static int F_126 ( struct V_48 * V_49 )
{
if ( V_24 & V_25 )
F_8 ( V_26 L_33 ) ;
++ V_300 ;
F_123 ( V_49 ) ;
return V_301 ;
}
static int F_127 ( struct V_44 * V_284 ,
struct V_302 * V_303 , T_3 V_304 , int * V_305 )
{
int V_184 ;
unsigned char * V_205 ;
if ( V_24 & V_25 )
F_8 ( V_26 L_34 ) ;
V_205 = F_128 ( V_303 ) ;
if ( V_205 ) {
V_184 = F_129 ( V_205 , V_304 ,
& V_305 [ 2 ] , & V_305 [ 0 ] , & V_305 [ 1 ] ) ;
F_31 ( V_205 ) ;
if ( ! V_184 )
return V_184 ;
}
V_305 [ 0 ] = V_306 ;
V_305 [ 1 ] = V_152 ;
V_305 [ 2 ] = V_307 ;
return 0 ;
}
static int F_130 ( struct V_48 * V_49 )
{
struct V_15 * V_16 ;
if ( V_24 & V_25 )
F_8 ( V_26 L_35 ) ;
++ V_308 ;
if ( V_49 ) {
V_16 = F_115 ( V_49 -> V_309 ) ;
if ( V_16 )
V_16 -> V_51 = 1 ;
}
return V_301 ;
}
static int F_131 ( struct V_48 * V_49 )
{
struct V_4 * V_5 ;
struct V_15 * V_310 ;
struct V_44 * V_290 ;
struct V_6 * V_311 ;
if ( V_24 & V_25 )
F_8 ( V_26 L_36 ) ;
++ V_312 ;
if ( V_49 && ( ( V_290 = V_49 -> V_309 ) ) && ( ( V_311 = V_290 -> V_287 ) ) ) {
V_5 = * (struct V_4 * * ) F_116 ( V_311 ) ;
if ( V_5 ) {
F_4 (dev_info,
&sdbg_host->dev_info_list,
dev_list)
V_310 -> V_51 = 1 ;
}
}
return V_301 ;
}
static int F_132 ( struct V_48 * V_49 )
{
struct V_4 * V_5 ;
struct V_15 * V_310 ;
if ( V_24 & V_25 )
F_8 ( V_26 L_37 ) ;
++ V_313 ;
F_3 ( & V_8 ) ;
F_4 (sdbg_host, &sdebug_host_list, host_list) {
F_4 (dev_info, &sdbg_host->dev_info_list,
dev_list)
V_310 -> V_51 = 1 ;
}
F_5 ( & V_8 ) ;
F_125 () ;
return V_301 ;
}
static void T_8 F_133 ( void )
{
unsigned long V_227 ;
int V_140 ;
struct V_271 * V_272 ;
F_111 ( & V_274 , V_227 ) ;
for ( V_140 = 0 ; V_140 < V_273 ; ++ V_140 ) {
V_272 = & V_275 [ V_140 ] ;
F_134 ( & V_272 -> V_299 ) ;
V_272 -> V_276 = 0 ;
V_272 -> V_278 = NULL ;
}
F_112 ( & V_274 , V_227 ) ;
}
static void T_8 F_135 ( unsigned char * V_314 ,
unsigned long V_315 )
{
struct V_316 * V_317 ;
int V_318 [ V_319 + 2 ] ;
int V_320 , V_321 , V_140 ;
int V_322 , V_218 , V_323 ;
if ( ( V_324 < 1 ) || ( V_315 < 1048576 ) )
return;
if ( V_324 > V_319 ) {
V_324 = V_319 ;
F_8 ( V_325 L_38
L_39 , V_319 ) ;
}
V_321 = ( int ) V_92 ;
V_320 = ( V_321 - V_152 )
/ V_324 ;
V_322 = V_306 * V_152 ;
V_318 [ 0 ] = V_152 ;
for ( V_140 = 1 ; V_140 < V_324 ; ++ V_140 )
V_318 [ V_140 ] = ( ( V_140 * V_320 ) / V_322 )
* V_322 ;
V_318 [ V_324 ] = V_321 ;
V_318 [ V_324 + 1 ] = 0 ;
V_314 [ 510 ] = 0x55 ;
V_314 [ 511 ] = 0xAA ;
V_317 = (struct V_316 * ) ( V_314 + 0x1be ) ;
for ( V_140 = 0 ; V_318 [ V_140 + 1 ] ; ++ V_140 , ++ V_317 ) {
V_218 = V_318 [ V_140 ] ;
V_323 = V_318 [ V_140 + 1 ] - 1 ;
V_317 -> V_326 = 0 ;
V_317 -> V_327 = V_218 / V_322 ;
V_317 -> V_328 = ( V_218 - ( V_317 -> V_327 * V_322 ) )
/ V_152 ;
V_317 -> V_211 = ( V_218 % V_152 ) + 1 ;
V_317 -> V_329 = V_323 / V_322 ;
V_317 -> V_330 = ( V_323 - ( V_317 -> V_329 * V_322 ) )
/ V_152 ;
V_317 -> V_331 = ( V_323 % V_152 ) + 1 ;
V_317 -> V_332 = F_136 ( V_218 ) ;
V_317 -> V_333 = F_136 ( V_323 - V_218 + 1 ) ;
V_317 -> V_334 = 0x83 ;
}
}
static int F_137 ( struct V_48 * V_102 ,
struct V_15 * V_16 ,
T_9 V_335 , int V_280 , int V_336 )
{
if ( ( V_24 & V_25 ) && V_102 ) {
if ( V_280 ) {
struct V_44 * V_290 = V_102 -> V_309 ;
F_8 ( V_26 L_40
L_41 , V_290 -> V_287 -> V_118 ,
V_290 -> V_119 , V_290 -> V_289 , V_290 -> V_111 , V_280 ) ;
}
}
if ( V_102 && V_16 ) {
if ( V_337 == ( V_280 & 0xff ) )
memcpy ( V_102 -> V_338 , V_16 -> V_21 ,
( V_339 > V_22 ) ?
V_22 : V_339 ) ;
}
if ( V_336 <= 0 ) {
if ( V_102 )
V_102 -> V_279 = V_280 ;
if ( V_335 )
V_335 ( V_102 ) ;
return 0 ;
} else {
unsigned long V_227 ;
int V_140 ;
struct V_271 * V_272 = NULL ;
F_111 ( & V_274 , V_227 ) ;
for ( V_140 = 0 ; V_140 < V_273 ; ++ V_140 ) {
V_272 = & V_275 [ V_140 ] ;
if ( ! V_272 -> V_276 )
break;
}
if ( V_140 >= V_273 ) {
F_112 ( & V_274 , V_227 ) ;
F_8 ( V_325 L_42 ) ;
return 1 ;
}
V_272 -> V_276 = 1 ;
V_272 -> V_278 = V_102 ;
V_272 -> V_280 = V_280 ;
V_272 -> V_277 = V_335 ;
V_272 -> V_299 . V_340 = F_110 ;
V_272 -> V_299 . V_210 = V_140 ;
V_272 -> V_299 . V_341 = V_342 + V_336 ;
F_138 ( & V_272 -> V_299 ) ;
F_112 ( & V_274 , V_227 ) ;
if ( V_102 )
V_102 -> V_279 = 0 ;
return 0 ;
}
}
static const char * F_139 ( struct V_6 * V_343 )
{
sprintf ( V_344 , L_43
L_44 , V_345 ,
V_346 , V_347 ,
V_25 ) ;
return V_344 ;
}
static int F_140 ( struct V_6 * V_287 , char * V_348 , int V_64 )
{
char V_59 [ 16 ] ;
int V_349 ;
int V_350 = V_64 > 15 ? 15 : V_64 ;
if ( ! F_141 ( V_351 ) || ! F_141 ( V_352 ) )
return - V_353 ;
memcpy ( V_59 , V_348 , V_350 ) ;
V_59 [ V_350 ] = '\0' ;
if ( 1 != sscanf ( V_59 , L_12 , & V_349 ) )
return - V_47 ;
V_25 = V_349 ;
if ( V_354 != 0 )
V_355 = 0 ;
return V_64 ;
}
static int F_142 ( struct V_356 * V_357 , struct V_6 * V_287 )
{
F_143 ( V_357 , L_45
L_46
L_47
L_48
L_49
L_50
L_51
L_52 ,
V_345 , V_346 , V_11 ,
V_347 , V_25 , V_354 ,
V_355 , V_358 ,
V_266 , V_124 ,
V_135 , V_307 , V_306 ,
V_152 , V_300 , V_308 , V_312 ,
V_313 , V_226 , V_245 , V_217 ) ;
return 0 ;
}
static T_10 F_144 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_358 ) ;
}
static T_10 F_145 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_363 ;
char V_364 [ 20 ] ;
if ( 1 == sscanf ( V_205 , L_54 , V_364 ) ) {
if ( ( 1 == sscanf ( V_364 , L_12 , & V_363 ) ) && ( V_363 >= 0 ) ) {
V_358 = V_363 ;
return V_362 ;
}
}
return - V_47 ;
}
static T_10 F_146 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_55 , V_25 ) ;
}
static T_10 F_147 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_349 ;
char V_364 [ 20 ] ;
if ( 1 == sscanf ( V_205 , L_54 , V_364 ) ) {
if ( 0 == F_148 ( V_364 , L_56 , 2 ) ) {
if ( 1 == sscanf ( & V_364 [ 2 ] , L_57 , & V_349 ) )
goto V_365;
} else {
if ( 1 == sscanf ( V_364 , L_12 , & V_349 ) )
goto V_365;
}
}
return - V_47 ;
V_365:
V_25 = V_349 ;
V_355 = 0 ;
return V_362 ;
}
static T_10 F_149 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_112 ) ;
}
static T_10 F_150 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_205 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_112 = V_104 ;
return V_362 ;
}
return - V_47 ;
}
static T_10 F_151 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_23 ) ;
}
static T_10 F_152 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_205 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_23 = V_104 ;
return V_362 ;
}
return - V_47 ;
}
static T_10 F_153 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_366 ) ;
}
static T_10 F_154 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_205 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_366 = V_104 ;
return V_362 ;
}
return - V_47 ;
}
static T_10 F_155 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_110 ) ;
}
static T_10 F_156 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_205 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_110 = V_104 ;
return V_362 ;
}
return - V_47 ;
}
static T_10 F_157 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_11 ) ;
}
static T_10 F_158 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_205 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_11 = V_104 ;
F_2 () ;
return V_362 ;
}
return - V_47 ;
}
static T_10 F_159 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_347 ) ;
}
static T_10 F_160 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_324 ) ;
}
static T_10 F_161 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_354 ) ;
}
static T_10 F_162 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_367 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_205 , L_12 , & V_367 ) ) ) {
V_354 = V_367 ;
V_355 = 0 ;
return V_362 ;
}
return - V_47 ;
}
static T_10 F_163 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_266 ) ;
}
static T_10 F_164 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_205 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_266 = V_104 ;
F_2 () ;
return V_362 ;
}
return - V_47 ;
}
static T_10 F_165 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_273 ) ;
}
static T_10 F_166 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_205 , L_12 , & V_104 ) ) && ( V_104 > 0 ) &&
( V_104 <= V_368 ) ) {
V_273 = V_104 ;
return V_362 ;
}
return - V_47 ;
}
static T_10 F_167 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_297 ) ;
}
static T_10 F_168 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_124 ) ;
}
static T_10 F_169 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_134 ) ;
}
static T_10 F_170 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_205 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_134 = V_104 ;
V_138 = F_36 () ;
return V_362 ;
}
return - V_47 ;
}
static T_10 F_171 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_369 ) ;
}
static T_10 F_172 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_370 ;
if ( sscanf ( V_205 , L_12 , & V_370 ) != 1 )
return - V_47 ;
if ( V_370 > 0 ) {
do {
F_173 () ;
} while ( -- V_370 );
} else if ( V_370 < 0 ) {
do {
F_174 () ;
} while ( ++ V_370 );
}
return V_362 ;
}
static T_10 F_175 ( struct V_359 * V_360 ,
char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_120 ) ;
}
static T_10 F_176 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_205 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_120 = V_104 ;
return V_362 ;
}
return - V_47 ;
}
static T_10 F_177 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_58 , V_135 ) ;
}
static T_10 F_178 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_233 ) ;
}
static T_10 F_179 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_121 ) ;
}
static T_10 F_180 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_207 ) ;
}
static T_10 F_181 ( struct V_359 * V_360 , char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_157 ) ;
}
static T_10 F_182 ( struct V_359 * V_360 , char * V_205 )
{
T_10 V_362 ;
if ( ! F_1 () )
return F_32 ( V_205 , V_361 , L_59 ,
V_92 ) ;
V_362 = F_183 ( V_205 , V_361 , V_250 , V_251 ) ;
V_205 [ V_362 ++ ] = '\n' ;
V_205 [ V_362 ++ ] = 0 ;
return V_362 ;
}
static T_10 F_184 ( struct V_359 * V_360 ,
char * V_205 )
{
return F_32 ( V_205 , V_361 , L_53 , V_123 ? 1 : 0 ) ;
}
static T_10 F_185 ( struct V_359 * V_360 ,
const char * V_205 , T_4 V_362 )
{
int V_104 ;
if ( ( V_362 > 0 ) && ( 1 == sscanf ( V_205 , L_12 , & V_104 ) ) && ( V_104 >= 0 ) ) {
V_123 = ( V_104 > 0 ) ;
return V_362 ;
}
return - V_47 ;
}
static int F_186 ( void )
{
int V_105 ;
V_105 = F_187 ( & V_371 , & V_372 ) ;
V_105 |= F_187 ( & V_371 , & V_373 ) ;
V_105 |= F_187 ( & V_371 , & V_374 ) ;
V_105 |= F_187 ( & V_371 , & V_375 ) ;
V_105 |= F_187 ( & V_371 , & V_376 ) ;
V_105 |= F_187 ( & V_371 , & V_377 ) ;
V_105 |= F_187 ( & V_371 , & V_378 ) ;
V_105 |= F_187 ( & V_371 , & V_379 ) ;
V_105 |= F_187 ( & V_371 , & V_380 ) ;
V_105 |= F_187 ( & V_371 , & V_381 ) ;
V_105 |= F_187 ( & V_371 , & V_382 ) ;
V_105 |= F_187 ( & V_371 , & V_383 ) ;
V_105 |= F_187 ( & V_371 , & V_384 ) ;
V_105 |= F_187 ( & V_371 , & V_385 ) ;
V_105 |= F_187 ( & V_371 , & V_386 ) ;
V_105 |= F_187 ( & V_371 , & V_387 ) ;
V_105 |= F_187 ( & V_371 , & V_388 ) ;
V_105 |= F_187 ( & V_371 , & V_389 ) ;
V_105 |= F_187 ( & V_371 , & V_390 ) ;
V_105 |= F_187 ( & V_371 , & V_391 ) ;
V_105 |= F_187 ( & V_371 , & V_392 ) ;
V_105 |= F_187 ( & V_371 , & V_393 ) ;
V_105 |= F_187 ( & V_371 , & V_394 ) ;
V_105 |= F_187 ( & V_371 , & V_395 ) ;
return V_105 ;
}
static void F_188 ( void )
{
F_189 ( & V_371 , & V_395 ) ;
F_189 ( & V_371 , & V_394 ) ;
F_189 ( & V_371 , & V_393 ) ;
F_189 ( & V_371 , & V_392 ) ;
F_189 ( & V_371 , & V_391 ) ;
F_189 ( & V_371 , & V_390 ) ;
F_189 ( & V_371 , & V_389 ) ;
F_189 ( & V_371 , & V_388 ) ;
F_189 ( & V_371 , & V_387 ) ;
F_189 ( & V_371 , & V_385 ) ;
F_189 ( & V_371 , & V_384 ) ;
F_189 ( & V_371 , & V_386 ) ;
F_189 ( & V_371 , & V_383 ) ;
F_189 ( & V_371 , & V_382 ) ;
F_189 ( & V_371 , & V_381 ) ;
F_189 ( & V_371 , & V_380 ) ;
F_189 ( & V_371 , & V_379 ) ;
F_189 ( & V_371 , & V_378 ) ;
F_189 ( & V_371 , & V_377 ) ;
F_189 ( & V_371 , & V_376 ) ;
F_189 ( & V_371 , & V_375 ) ;
F_189 ( & V_371 , & V_374 ) ;
F_189 ( & V_371 , & V_373 ) ;
F_189 ( & V_371 , & V_372 ) ;
}
static int T_8 F_190 ( void )
{
unsigned long V_396 ;
int V_397 ;
int V_140 ;
int V_105 ;
switch ( V_135 ) {
case 512 :
case 1024 :
case 2048 :
case 4096 :
break;
default:
F_8 ( V_239 L_60 ,
V_135 ) ;
return - V_47 ;
}
switch ( V_121 ) {
case V_398 :
case V_214 :
case V_216 :
case V_122 :
break;
default:
F_8 ( V_239 L_61 ) ;
return - V_47 ;
}
if ( V_207 > 1 ) {
F_8 ( V_239 L_62 ) ;
return - V_47 ;
}
if ( V_157 > 1 ) {
F_8 ( V_239 L_63 ) ;
return - V_47 ;
}
if ( V_91 > 15 ) {
F_8 ( V_239 L_64 ,
V_91 ) ;
return - V_47 ;
}
if ( V_141 > 0x3fff ) {
F_8 ( V_239 L_65 ,
V_141 ) ;
return - V_47 ;
}
if ( V_347 < 1 )
V_347 = 1 ;
V_396 = ( unsigned long ) V_347 * 1048576 ;
V_92 = V_396 / V_135 ;
V_138 = F_36 () ;
V_306 = 8 ;
V_152 = 32 ;
if ( V_347 >= 16 )
V_306 = 32 ;
else if ( V_347 >= 256 )
V_306 = 64 ;
V_307 = ( unsigned long ) V_138 /
( V_152 * V_306 ) ;
if ( V_307 >= 1024 ) {
V_306 = 255 ;
V_152 = 63 ;
V_307 = ( unsigned long ) V_138 /
( V_152 * V_306 ) ;
}
V_204 = F_191 ( V_396 ) ;
if ( NULL == V_204 ) {
F_8 ( V_239 L_66 ) ;
return - V_399 ;
}
memset ( V_204 , 0 , V_396 ) ;
if ( V_324 > 0 )
F_135 ( V_204 , V_396 ) ;
if ( V_233 ) {
int V_400 ;
V_400 = V_92 * sizeof( struct V_208 ) ;
V_224 = F_191 ( V_400 ) ;
F_8 ( V_239 L_67 ,
V_400 , V_224 ) ;
if ( V_224 == NULL ) {
F_8 ( V_239 L_68 ) ;
V_105 = - V_399 ;
goto V_401;
}
memset ( V_224 , 0xff , V_400 ) ;
}
if ( F_1 () ) {
V_94 =
F_192 ( V_94 , 0U , 0xffffffffU ) ;
V_95 =
F_192 ( V_95 , 0U , 256U ) ;
V_97 =
F_192 ( V_97 , 1U , 0xffffffffU ) ;
if ( V_96 &&
V_97 <=
V_96 ) {
F_8 ( V_239
L_69 ,
V_213 ) ;
return - V_47 ;
}
V_251 = F_86 ( V_92 - 1 ) + 1 ;
V_250 = F_191 ( F_193 ( V_251 ) * sizeof( long ) ) ;
F_8 ( V_26 L_70 ,
V_251 ) ;
if ( V_250 == NULL ) {
F_8 ( V_239 L_71 ) ;
V_105 = - V_399 ;
goto V_401;
}
F_194 ( V_250 , V_251 ) ;
if ( V_324 )
F_93 ( 0 , 2 ) ;
}
V_402 = F_195 ( L_72 ) ;
if ( F_196 ( V_402 ) ) {
F_8 ( V_325 L_73 ) ;
V_105 = F_197 ( V_402 ) ;
goto V_401;
}
V_105 = F_198 ( & V_403 ) ;
if ( V_105 < 0 ) {
F_8 ( V_325 L_74 ,
V_105 ) ;
goto V_404;
}
V_105 = F_199 ( & V_371 ) ;
if ( V_105 < 0 ) {
F_8 ( V_325 L_75 ,
V_105 ) ;
goto V_405;
}
V_105 = F_186 () ;
if ( V_105 < 0 ) {
F_8 ( V_325 L_76 ,
V_105 ) ;
goto V_406;
}
F_133 () ;
V_397 = V_369 ;
V_369 = 0 ;
for ( V_140 = 0 ; V_140 < V_397 ; V_140 ++ ) {
if ( F_173 () ) {
F_8 ( V_239 L_77
L_78 , V_140 ) ;
break;
}
}
if ( V_24 & V_25 ) {
F_8 ( V_26 L_79 ,
V_369 ) ;
}
return 0 ;
V_406:
F_188 () ;
F_200 ( & V_371 ) ;
V_405:
F_201 ( & V_403 ) ;
V_404:
F_202 ( V_402 ) ;
V_401:
if ( V_250 )
F_203 ( V_250 ) ;
if ( V_224 )
F_203 ( V_224 ) ;
F_203 ( V_204 ) ;
return V_105 ;
}
static void T_11 F_204 ( void )
{
int V_140 = V_369 ;
F_125 () ;
for (; V_140 ; V_140 -- )
F_174 () ;
F_188 () ;
F_200 ( & V_371 ) ;
F_201 ( & V_403 ) ;
F_202 ( V_402 ) ;
if ( V_224 )
F_203 ( V_224 ) ;
F_203 ( V_204 ) ;
}
static void F_205 ( struct V_309 * V_45 )
{
struct V_4 * V_5 ;
V_5 = F_206 ( V_45 ) ;
F_31 ( V_5 ) ;
}
static int F_173 ( void )
{
int V_140 , V_407 ;
int error = 0 ;
struct V_4 * V_5 ;
struct V_15 * V_408 , * V_409 ;
V_5 = F_30 ( sizeof( * V_5 ) , V_410 ) ;
if ( NULL == V_5 ) {
F_8 ( V_239 L_29 ,
V_213 , __LINE__ ) ;
return - V_399 ;
}
F_207 ( & V_5 -> V_283 ) ;
V_407 = V_11 * V_266 ;
for ( V_140 = 0 ; V_140 < V_407 ; V_140 ++ ) {
V_408 = F_113 ( V_5 , V_410 ) ;
if ( ! V_408 ) {
F_8 ( V_239 L_29 ,
V_213 , __LINE__ ) ;
error = - V_399 ;
goto V_411;
}
}
F_3 ( & V_8 ) ;
F_114 ( & V_5 -> V_412 , & V_413 ) ;
F_5 ( & V_8 ) ;
V_5 -> V_45 . V_414 = & V_403 ;
V_5 -> V_45 . V_415 = V_402 ;
V_5 -> V_45 . V_416 = & F_205 ;
F_208 ( & V_5 -> V_45 , L_80 , V_369 ) ;
error = F_209 ( & V_5 -> V_45 ) ;
if ( error )
goto V_411;
++ V_369 ;
return error ;
V_411:
F_210 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_211 ( & V_408 -> V_282 ) ;
F_31 ( V_408 ) ;
}
F_31 ( V_5 ) ;
return error ;
}
static void F_174 ( void )
{
struct V_4 * V_5 = NULL ;
F_3 ( & V_8 ) ;
if ( ! F_212 ( & V_413 ) ) {
V_5 = F_213 ( V_413 . V_417 ,
struct V_4 , V_412 ) ;
F_211 ( & V_5 -> V_412 ) ;
}
F_5 ( & V_8 ) ;
if ( ! V_5 )
return;
F_214 ( & V_5 -> V_45 ) ;
-- V_369 ;
}
static
int F_215 ( struct V_48 * V_49 , T_9 V_335 )
{
unsigned char * V_27 = ( unsigned char * ) V_49 -> V_102 ;
int V_116 , V_140 ;
unsigned int V_29 ;
unsigned long long V_28 ;
T_1 V_30 ;
int V_132 = 0 ;
int V_100 = V_49 -> V_309 -> V_289 ;
struct V_15 * V_16 = NULL ;
int V_418 = 0 ;
int V_419 = 0 ;
int V_420 = 0 ;
int V_421 = 0 ;
int V_422 = 0 ;
int V_252 = 0 ;
F_74 ( V_49 , 0 ) ;
if ( ( V_24 & V_25 ) && V_27 ) {
F_8 ( V_26 L_81 ) ;
for ( V_140 = 0 , V_116 = V_49 -> V_423 ; V_140 < V_116 ; ++ V_140 )
F_8 ( L_20 , ( int ) V_27 [ V_140 ] ) ;
F_8 ( L_21 ) ;
}
if ( V_100 == V_49 -> V_309 -> V_287 -> V_424 -> V_10 ) {
F_8 ( V_26 L_82
L_83 ) ;
return F_137 ( V_49 , NULL , V_335 ,
V_425 << 16 , 0 ) ;
}
if ( ( V_49 -> V_309 -> V_111 >= V_266 ) &&
( V_49 -> V_309 -> V_111 != V_14 ) )
return F_137 ( V_49 , NULL , V_335 ,
V_425 << 16 , 0 ) ;
V_16 = F_115 ( V_49 -> V_309 ) ;
if ( NULL == V_16 )
return F_137 ( V_49 , NULL , V_335 ,
V_425 << 16 , 0 ) ;
if ( ( V_354 != 0 ) &&
( ++ V_355 >= abs ( V_354 ) ) ) {
V_355 = 0 ;
if ( V_354 < - 1 )
V_354 = - 1 ;
if ( V_426 & V_25 )
return 0 ;
else if ( V_427 & V_25 &&
F_216 ( V_49 ) )
return 0 ;
else if ( V_428 & V_25 )
V_418 = 1 ;
else if ( V_429 & V_25 )
V_419 = 1 ;
else if ( V_430 & V_25 )
V_420 = 1 ;
else if ( V_431 & V_25 )
V_421 = 1 ;
}
if ( V_16 -> V_109 ) {
switch ( * V_27 ) {
case V_432 :
case V_433 :
case V_434 :
case V_435 :
break;
default:
if ( V_24 & V_25 )
F_8 ( V_26 L_84
L_85 , * V_27 ) ;
F_6 ( V_16 , V_113 ,
V_436 , 0 ) ;
V_132 = V_54 ;
return F_137 ( V_49 , V_16 , V_335 , V_132 ,
0 ) ;
}
}
switch ( * V_27 ) {
case V_432 :
V_422 = 1 ;
V_132 = F_29 ( V_49 , V_100 , V_16 ) ;
break;
case V_433 :
V_422 = 1 ;
V_132 = F_34 ( V_49 , V_16 ) ;
break;
case V_437 :
case V_438 :
V_132 = F_35 ( V_49 , V_16 ) ;
break;
case V_439 :
V_132 = F_11 ( V_49 , 1 , V_16 ) ;
if ( V_132 )
break;
if ( V_24 & V_25 )
F_8 ( V_26 L_86 ,
V_27 [ 4 ] ? L_87 : L_88 ) ;
break;
case V_440 :
V_132 = F_11 ( V_49 , 1 , V_16 ) ;
break;
case V_434 :
V_422 = 1 ;
V_132 = F_11 ( V_49 , 0 , V_16 ) ;
break;
case V_441 :
V_132 = F_11 ( V_49 , 1 , V_16 ) ;
break;
case V_442 :
V_132 = F_11 ( V_49 , 1 , V_16 ) ;
break;
case V_443 :
V_132 = F_11 ( V_49 , 1 , V_16 ) ;
break;
case V_444 :
V_132 = F_11 ( V_49 , 1 , V_16 ) ;
break;
case V_445 :
V_132 = F_37 ( V_49 , V_16 ) ;
break;
case V_446 :
if ( V_27 [ 1 ] == V_447 )
V_132 = F_38 ( V_49 , V_16 ) ;
else if ( V_27 [ 1 ] == V_448 ) {
if ( F_1 () == 0 ) {
F_6 ( V_16 , V_113 ,
V_449 , 0 ) ;
V_132 = V_54 ;
} else
V_132 = F_106 ( V_49 , V_16 ) ;
} else {
F_6 ( V_16 , V_113 ,
V_436 , 0 ) ;
V_132 = V_54 ;
}
break;
case V_450 :
if ( V_451 != V_27 [ 1 ] ) {
F_6 ( V_16 , V_113 ,
V_436 , 0 ) ;
V_132 = V_54 ;
break;
}
V_132 = F_39 ( V_49 , V_16 ) ;
break;
case V_35 :
case V_37 :
case V_40 :
if ( V_121 == V_216 &&
V_27 [ 1 ] & 0xe0 ) {
F_6 ( V_16 , V_113 ,
V_449 , 0 ) ;
V_132 = V_54 ;
break;
}
if ( ( V_121 == V_214 ||
V_121 == V_122 ) &&
( V_27 [ 1 ] & 0xe0 ) == 0 )
F_8 ( V_239 L_89 ) ;
case V_43 :
V_452:
V_132 = F_11 ( V_49 , 0 , V_16 ) ;
if ( V_132 )
break;
if ( V_366 )
break;
F_9 ( V_27 , & V_28 , & V_29 , & V_30 ) ;
V_132 = F_73 ( V_49 , V_28 , V_29 , V_16 , V_30 ) ;
if ( V_418 && ( 0 == V_132 ) ) {
F_6 ( V_16 , V_453 ,
V_130 , 0 ) ;
V_132 = V_54 ;
} else if ( V_419 && ( 0 == V_132 ) ) {
F_6 ( V_16 , V_235 ,
V_454 , V_455 ) ;
V_132 = V_54 ;
} else if ( V_420 && ( 0 == V_132 ) ) {
F_6 ( V_16 , V_235 , 0x10 , 1 ) ;
V_132 = V_236 ;
} else if ( V_421 && ( 0 == V_132 ) ) {
F_6 ( V_16 , V_113 , 0x10 , 1 ) ;
V_132 = V_236 ;
}
break;
case V_435 :
V_422 = 1 ;
V_132 = F_107 ( V_49 , V_16 ) ;
break;
case V_456 :
V_132 = F_11 ( V_49 , 0 , V_16 ) ;
break;
case V_34 :
case V_36 :
case V_39 :
if ( V_121 == V_216 &&
V_27 [ 1 ] & 0xe0 ) {
F_6 ( V_16 , V_113 ,
V_449 , 0 ) ;
V_132 = V_54 ;
break;
}
if ( ( V_121 == V_214 ||
V_121 == V_122 ) &&
( V_27 [ 1 ] & 0xe0 ) == 0 )
F_8 ( V_239 L_89 ) ;
case V_42 :
V_196:
V_132 = F_11 ( V_49 , 0 , V_16 ) ;
if ( V_132 )
break;
if ( V_366 )
break;
F_9 ( V_27 , & V_28 , & V_29 , & V_30 ) ;
V_132 = F_97 ( V_49 , V_28 , V_29 , V_16 , V_30 ) ;
if ( V_418 && ( 0 == V_132 ) ) {
F_6 ( V_16 , V_453 ,
V_130 , 0 ) ;
V_132 = V_54 ;
} else if ( V_420 && ( 0 == V_132 ) ) {
F_6 ( V_16 , V_235 , 0x10 , 1 ) ;
V_132 = V_236 ;
} else if ( V_421 && ( 0 == V_132 ) ) {
F_6 ( V_16 , V_113 , 0x10 , 1 ) ;
V_132 = V_236 ;
}
break;
case V_33 :
case V_38 :
if ( V_27 [ 1 ] & 0x8 ) {
if ( ( * V_27 == V_33 && V_2 == 0 ) ||
( * V_27 == V_38 && V_3 == 0 ) ) {
F_6 ( V_16 , V_113 ,
V_114 , 0 ) ;
V_132 = V_54 ;
} else
V_252 = 1 ;
}
if ( V_132 )
break;
V_132 = F_11 ( V_49 , 0 , V_16 ) ;
if ( V_132 )
break;
F_9 ( V_27 , & V_28 , & V_29 , & V_30 ) ;
V_132 = F_100 ( V_49 , V_28 , V_29 , V_16 , V_30 , V_252 ) ;
break;
case V_457 :
V_132 = F_11 ( V_49 , 0 , V_16 ) ;
if ( V_132 )
break;
if ( V_95 == 0 || V_1 == 0 ) {
F_6 ( V_16 , V_113 ,
V_449 , 0 ) ;
V_132 = V_54 ;
} else
V_132 = F_101 ( V_49 , V_16 ) ;
break;
case V_173 :
case V_458 :
V_132 = F_49 ( V_49 , V_100 , V_16 ) ;
break;
case V_459 :
V_132 = F_51 ( V_49 , 1 , V_16 ) ;
break;
case V_460 :
V_132 = F_51 ( V_49 , 0 , V_16 ) ;
break;
case V_461 :
V_132 = F_54 ( V_49 , V_16 ) ;
break;
case V_462 :
V_422 = 1 ;
V_132 = F_11 ( V_49 , 0 , V_16 ) ;
break;
case V_463 :
V_132 = F_11 ( V_49 , 1 , V_16 ) ;
break;
case V_41 :
if ( ! F_14 ( V_49 ) ) {
F_6 ( V_16 , V_113 ,
V_114 , 0 ) ;
V_132 = V_54 ;
break;
}
V_132 = F_11 ( V_49 , 0 , V_16 ) ;
if ( V_132 )
break;
if ( V_366 )
break;
F_9 ( V_27 , & V_28 , & V_29 , & V_30 ) ;
V_132 = F_73 ( V_49 , V_28 , V_29 , V_16 , V_30 ) ;
if ( V_132 )
break;
V_132 = F_97 ( V_49 , V_28 , V_29 , V_16 , V_30 ) ;
if ( V_132 )
break;
V_132 = F_108 ( V_49 , V_28 , V_29 , V_16 ) ;
break;
case V_31 :
if ( V_121 == V_216 ) {
if ( ( V_27 [ 10 ] & 0xe0 ) == 0 )
F_8 ( V_239
L_89 ) ;
if ( V_27 [ 9 ] == V_464 ) {
F_82 ( V_49 -> V_423 < 32 ) ;
goto V_452;
}
if ( V_27 [ 9 ] == V_465 ) {
F_82 ( V_49 -> V_423 < 32 ) ;
goto V_196;
}
}
F_6 ( V_16 , V_113 ,
V_114 , 0 ) ;
V_132 = V_54 ;
break;
default:
if ( V_24 & V_25 )
F_8 ( V_26 L_90
L_91 , * V_27 ) ;
V_132 = F_11 ( V_49 , 1 , V_16 ) ;
if ( V_132 )
break;
F_6 ( V_16 , V_113 , V_436 , 0 ) ;
V_132 = V_54 ;
break;
}
return F_137 ( V_49 , V_16 , V_335 , V_132 ,
( V_422 ? 0 : V_358 ) ) ;
}
static int F_217 ( struct V_309 * V_45 )
{
int error = 0 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_466 ;
V_5 = F_206 ( V_45 ) ;
V_467 . V_468 = V_273 ;
V_7 = F_218 ( & V_467 , sizeof( V_5 ) ) ;
if ( NULL == V_7 ) {
F_8 ( V_239 L_92 , V_213 ) ;
error = - V_469 ;
return error ;
}
V_5 -> V_9 = V_7 ;
* ( (struct V_4 * * ) V_7 -> V_286 ) = V_5 ;
if ( ( V_7 -> V_10 >= 0 ) && ( V_11 > V_7 -> V_10 ) )
V_7 -> V_12 = V_11 + 1 ;
else
V_7 -> V_12 = V_11 ;
V_7 -> V_13 = V_14 ;
V_466 = 0 ;
switch ( V_121 ) {
case V_214 :
V_466 = V_470 ;
if ( V_233 )
V_466 |= V_471 ;
break;
case V_216 :
V_466 = V_472 ;
if ( V_233 )
V_466 |= V_473 ;
break;
case V_122 :
V_466 = V_474 ;
if ( V_233 )
V_466 |= V_475 ;
break;
default:
if ( V_233 )
V_466 |= V_476 ;
break;
}
F_219 ( V_7 , V_466 ) ;
F_8 ( V_26 L_93 ,
( V_466 & V_470 ) ? L_94 : L_95 ,
( V_466 & V_472 ) ? L_96 : L_95 ,
( V_466 & V_474 ) ? L_97 : L_95 ,
( V_466 & V_476 ) ? L_98 : L_95 ,
( V_466 & V_471 ) ? L_99 : L_95 ,
( V_466 & V_473 ) ? L_100 : L_95 ,
( V_466 & V_475 ) ? L_101 : L_95 ) ;
if ( V_207 == 1 )
F_220 ( V_7 , V_477 ) ;
else
F_220 ( V_7 , V_478 ) ;
error = F_221 ( V_7 , & V_5 -> V_45 ) ;
if ( error ) {
F_8 ( V_239 L_102 , V_213 ) ;
error = - V_469 ;
F_222 ( V_7 ) ;
} else
F_223 ( V_7 ) ;
return error ;
}
static int F_224 ( struct V_309 * V_45 )
{
struct V_4 * V_5 ;
struct V_15 * V_408 , * V_409 ;
V_5 = F_206 ( V_45 ) ;
if ( ! V_5 ) {
F_8 ( V_239 L_103 ,
V_213 ) ;
return - V_469 ;
}
F_225 ( V_5 -> V_9 ) ;
F_210 (sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
F_211 ( & V_408 -> V_282 ) ;
F_31 ( V_408 ) ;
}
F_222 ( V_5 -> V_9 ) ;
return 0 ;
}
static int F_226 ( struct V_309 * V_45 ,
struct V_359 * V_479 )
{
return 1 ;
}
