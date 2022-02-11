static void F_1 ( int V_1 , void * V_2 ,
T_1 V_3 , T_1 V_4 )
{
return;
}
static int F_2 ( struct V_5 * V_6 )
{
struct V_7 V_8 ;
T_2 V_9 ;
T_1 V_10 [ 91 ] ;
int V_11 ;
V_11 = 0 ;
while ( V_11 < 91 ) {
V_10 [ V_11 ++ ] = V_12 |
V_13 | V_14 ;
V_10 [ V_11 ++ ] = 0x01 ;
V_10 [ V_11 ] = V_11 / 7 ;
V_11 ++ ;
V_10 [ V_11 ++ ] = V_15 ;
V_10 [ V_11 ++ ] = 2 ;
V_11 ++ ; V_11 ++ ;
}
V_10 [ 84 ] |= V_16 ;
V_9 . V_17 = 91 ;
V_9 . V_18 = V_10 ;
V_9 . V_19 . V_7 = & V_8 ;
F_3 ( & V_8 , 0 ) ;
if ( F_4 ( & V_9 ) ) return - 1 ;
F_5 ( & V_8 ) ;
if ( ! ( ( V_10 [ 83 ] | V_10 [ 90 ] | V_10 [ 69 ] | V_10 [ 76 ] |
V_10 [ 55 ] | V_10 [ 62 ] | V_10 [ 34 ] | V_10 [ 41 ] |
V_10 [ 20 ] | V_10 [ 27 ] | V_10 [ 6 ] | V_10 [ 13 ] ) & 0x0f ) )
return - 1 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 -> V_20 = ( V_10 [ 83 ] & 0x0f ) + ( V_10 [ 90 ] & 0x0f ) * 10 ;
V_6 -> V_21 = ( V_10 [ 69 ] & 0x0f ) + ( V_10 [ 76 ] & 0x0f ) * 10 ;
V_6 -> V_22 = ( V_10 [ 55 ] & 0x0f ) + ( V_10 [ 62 ] & 0x0f ) * 10 ;
V_6 -> V_23 = ( V_10 [ 48 ] & 0x0f ) ;
V_6 -> V_24 = ( V_10 [ 34 ] & 0x0f ) + ( V_10 [ 41 ] & 0x0f ) * 10 ;
V_6 -> V_25 = ( V_10 [ 20 ] & 0x0f ) + ( V_10 [ 27 ] & 0x0f ) * 10 ;
V_6 -> V_26 = ( V_10 [ 6 ] & 0x0f ) + ( V_10 [ 13 ] & 0x0f ) * 10 ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_5 V_27 , V_28 ;
int V_11 = 0 ;
if ( F_2 ( & V_28 ) ) return - 1 ;
if ( F_2 ( & V_27 ) ) return - 1 ;
while ( memcmp ( & V_27 , & V_28 , sizeof( struct V_5 ) ) ) {
if ( V_11 ++ > 4 ) return - 1 ;
memcpy ( & V_28 , & V_27 , sizeof( struct V_5 ) ) ;
if ( F_2 ( & V_27 ) ) return - 1 ;
}
memcpy ( V_6 , & V_27 , sizeof( struct V_5 ) ) ;
return 0 ;
}
static T_3 F_7 ( T_1 V_29 , int V_30 )
{
T_2 V_9 ;
T_1 V_10 [ 26 ] = {
V_31 | V_13 | V_14 ,
0 ,
V_32 , 2 , 0 , 0 ,
V_13 | V_14 ,
V_33 , 2 , 0 , 0 ,
V_13 | V_14 ,
V_34 , 2 , 0 , 0 ,
V_13 | V_14 ,
V_35 , 2 , 0 , 0 ,
V_13 | V_14 ,
V_36 , 2 , 0 , 0
} ;
V_9 . V_17 = V_30 * 5 ;
V_10 [ 1 ] = V_29 ;
V_10 [ V_9 . V_17 - 4 ] |= V_16 ;
V_9 . V_18 = V_10 ;
V_9 . V_19 . V_7 = & V_37 ;
F_5 ( & V_37 ) ;
if ( F_4 ( & V_9 ) ) return - 1 ;
F_5 ( & V_37 ) ;
F_8 ( & V_37 ) ;
return ( V_10 [ 5 ] |
( ( V_38 ) ( V_10 [ 10 ] ) << 8 ) | ( ( V_38 ) ( V_10 [ 15 ] ) << 16 ) |
( ( V_38 ) ( V_10 [ 20 ] ) << 24 ) | ( ( V_38 ) ( V_10 [ 25 ] ) << 32 ) ) ;
}
static inline int F_9 ( struct V_39 * V_40 ) {
T_3 V_41 ;
T_4 V_42 ;
unsigned int V_43 ;
V_41 = F_7 ( V_44 , 5 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( T_4 ) V_41 & 0xffffff ;
V_43 = ( unsigned int ) ( V_41 >> 24 ) & 0xffff ;
V_40 -> V_45 = ( V_46 ) ( V_42 % 100 ) * 10000 ;
V_40 -> V_47 = ( V_48 ) ( V_42 / 100 ) + V_43 * 86400 ;
return 0 ;
}
static inline int F_10 ( struct V_39 * V_40 ) {
T_3 V_41 ;
unsigned int V_42 ;
V_41 = F_7 ( V_49 , 2 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( unsigned int ) V_41 & 0xffff ;
V_40 -> V_45 = ( V_46 ) ( V_42 % 100 ) * 10000 ;
V_40 -> V_47 = ( V_48 ) ( V_42 / 100 ) ;
return 0 ;
}
static inline int F_11 ( struct V_39 * V_40 ) {
T_3 V_41 ;
T_4 V_42 ;
V_41 = F_7 ( V_50 , 3 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( T_4 ) V_41 & 0xffffff ;
V_40 -> V_45 = ( V_46 ) ( V_42 % 100 ) * 10000 ;
V_40 -> V_47 = ( V_48 ) ( V_42 / 100 ) ;
return 0 ;
}
static inline int F_12 ( struct V_39 * V_40 ) {
T_3 V_41 ;
T_4 V_42 ;
V_41 = F_7 ( V_51 , 3 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( T_4 ) V_41 & 0xffffff ;
V_40 -> V_45 = ( V_46 ) ( V_42 % 100 ) * 10000 ;
V_40 -> V_47 = ( V_48 ) ( V_42 / 100 ) ;
return 0 ;
}
static inline int F_13 ( struct V_39 * V_40 ) {
T_3 V_41 ;
T_4 V_42 ;
V_41 = F_7 ( V_52 , 3 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( T_4 ) V_41 & 0xffffff ;
V_40 -> V_45 = ( V_46 ) ( V_42 % 100 ) * 10000 ;
V_40 -> V_47 = ( V_48 ) ( V_42 / 100 ) ;
return 0 ;
}
static int F_14 ( struct V_39 * V_53 )
{
T_4 V_42 ;
unsigned int V_43 ;
T_2 V_9 ;
T_1 V_10 [ 11 ] = {
V_31 | V_54 ,
V_55 , 3 , 0 , 0 , 0 ,
V_31 | V_54 ,
V_56 , 2 , 0 , 0
} ;
V_9 . V_17 = 10 ;
if ( 0xffff < V_53 -> V_47 / 86400 ) return - 1 ;
V_43 = V_53 -> V_47 / 86400 ;
if ( 0xffff < V_53 -> V_45 / 1000000 / 86400 ) return - 1 ;
V_43 += ( ( V_53 -> V_47 % 86400 ) + V_53 -> V_45 / 1000000 ) / 86400 ;
if ( V_43 > 0xffff ) return - 1 ;
if ( 0xffffff < V_53 -> V_47 ) return - 1 ;
V_42 = V_53 -> V_47 * 100 ;
if ( 0xffffff < V_53 -> V_45 / 10000 ) return - 1 ;
V_42 += V_53 -> V_45 / 10000 ;
if ( V_42 > 0xffffff ) return - 1 ;
V_10 [ 3 ] = ( T_1 ) ( V_42 & 0xff ) ;
V_10 [ 4 ] = ( T_1 ) ( ( V_42 >> 8 ) & 0xff ) ;
V_10 [ 5 ] = ( T_1 ) ( ( V_42 >> 16 ) & 0xff ) ;
V_10 [ 9 ] = ( T_1 ) ( V_43 & 0xff ) ;
V_10 [ 10 ] = ( T_1 ) ( ( V_43 >> 8 ) & 0xff ) ;
V_9 . V_18 = V_10 ;
if ( F_4 ( & V_9 ) ) return - 1 ;
return 0 ;
}
static int F_15 ( struct V_39 * V_53 )
{
T_4 V_42 ;
T_2 V_9 ;
T_1 V_10 [ 5 ] = {
V_31 | V_54 ,
V_57 , 2 , 0 , 0
} ;
V_9 . V_17 = 4 ;
if ( 0xffff < V_53 -> V_47 ) return - 1 ;
V_42 = V_53 -> V_47 * 100 ;
if ( 0xffff < V_53 -> V_45 / 10000 ) return - 1 ;
V_42 += V_53 -> V_45 / 10000 ;
if ( V_42 > 0xffff ) return - 1 ;
V_10 [ 3 ] = ( T_1 ) ( V_42 & 0xff ) ;
V_10 [ 4 ] = ( T_1 ) ( ( V_42 >> 8 ) & 0xff ) ;
V_9 . V_18 = V_10 ;
if ( F_4 ( & V_9 ) ) return - 1 ;
return 0 ;
}
static int F_16 ( struct V_39 * V_53 , T_1 V_58 )
{
T_4 V_42 ;
T_2 V_9 ;
T_1 V_10 [ 6 ] = {
V_31 | V_54 ,
0 , 3 , 0 , 0 , 0
} ;
V_9 . V_17 = 6 ;
if ( 0xffffff < V_53 -> V_47 ) return - 1 ;
V_42 = V_53 -> V_47 * 100 ;
if ( 0xffffff < V_53 -> V_45 / 10000 ) return - 1 ;
V_42 += V_53 -> V_45 / 10000 ;
if ( V_42 > 0xffffff ) return - 1 ;
V_10 [ 1 ] = V_58 ;
V_10 [ 3 ] = ( T_1 ) ( V_42 & 0xff ) ;
V_10 [ 4 ] = ( T_1 ) ( ( V_42 >> 8 ) & 0xff ) ;
V_10 [ 5 ] = ( T_1 ) ( ( V_42 >> 16 ) & 0xff ) ;
V_9 . V_18 = V_10 ;
if ( F_4 ( & V_9 ) ) {
return - 1 ;
}
return 0 ;
}
static T_5 F_17 ( struct V_59 * V_59 , char T_6 * V_60 ,
T_7 V_61 , T_8 * V_62 ) {
T_5 V_63 ;
if ( V_61 < sizeof( unsigned long ) )
return - V_64 ;
V_63 = F_18 ( 68 , ( unsigned long T_6 * ) V_60 ) ;
return V_63 ;
}
static unsigned int F_19 ( struct V_59 * V_59 , T_9 * V_65 )
{
unsigned long V_66 ;
V_66 = 0 ;
if ( V_66 != 0 )
return V_67 | V_68 ;
return 0 ;
}
static int F_20 ( struct V_69 * V_69 , struct V_59 * V_59 )
{
return 0 ;
}
static int F_21 ( int V_70 , struct V_59 * V_71 , int V_72 )
{
return F_22 ( V_70 , V_71 , V_72 , & V_73 ) ;
}
static int F_23 ( char * V_60 )
{
#define YN ( T_10 ) ("no")
#define F_24 ( T_10 ) ("yes")
char * V_74 ;
struct V_5 V_27 ;
struct V_39 V_75 ;
memset ( & V_27 , 0 , sizeof( struct V_5 ) ) ;
V_74 = V_60 ;
if ( F_6 ( & V_27 ) ) {
V_74 += sprintf ( V_74 , L_1 ) ;
} else {
V_74 += sprintf ( V_74 ,
L_2
L_3
L_4 ,
V_27 . V_24 , V_27 . V_25 , V_27 . V_26 ,
V_27 . V_20 + 1900 , V_27 . V_21 + 1 ,
V_27 . V_22 , V_76 ) ;
}
if ( F_9 ( & V_75 ) ) {
V_74 += sprintf ( V_74 , L_5 ) ;
} else {
V_74 += sprintf ( V_74 , L_6 ,
V_75 . V_47 , ( int ) V_75 . V_45 / 1000 ) ;
}
if ( F_10 ( & V_75 ) ) {
V_74 += sprintf ( V_74 , L_7 ) ;
} else {
V_74 += sprintf ( V_74 , L_8 ,
V_75 . V_47 , ( int ) V_75 . V_45 / 1000 ) ;
}
if ( F_11 ( & V_75 ) ) {
V_74 += sprintf ( V_74 , L_9 ) ;
} else {
V_74 += sprintf ( V_74 , L_10 ,
V_75 . V_47 , ( int ) V_75 . V_45 / 1000 ) ;
}
if ( F_12 ( & V_75 ) ) {
V_74 += sprintf ( V_74 , L_11 ) ;
} else {
V_74 += sprintf ( V_74 , L_12 ,
V_75 . V_47 , ( int ) V_75 . V_45 / 1000 ) ;
}
if ( F_13 ( & V_75 ) ) {
V_74 += sprintf ( V_74 , L_13 ) ;
} else {
V_74 += sprintf ( V_74 , L_14 ,
V_75 . V_47 , ( int ) V_75 . V_45 / 1000 ) ;
}
V_74 += sprintf ( V_74 ,
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23 ,
YN ( V_77 ) ,
F_24 ( V_78 ) ,
YN ( V_79 ) ,
YN ( V_80 ) ,
YN ( V_81 ) ,
YN ( V_82 ) ,
YN ( V_83 ) ,
1UL ,
1 ? L_24 : L_25 ) ;
return V_74 - V_60 ;
#undef YN
#undef F_24
}
static int F_25 ( char * V_84 , char * * V_85 , T_11 V_86 ,
int V_61 , int * V_87 , void * V_4 )
{
int V_88 = F_23 ( V_84 ) ;
if ( V_88 <= V_86 + V_61 ) * V_87 = 1 ;
* V_85 = V_84 + V_86 ;
V_88 -= V_86 ;
if ( V_88 > V_61 ) V_88 = V_61 ;
if ( V_88 < 0 ) V_88 = 0 ;
return V_88 ;
}
static int F_26 ( struct V_59 * V_59 ,
unsigned int V_89 , unsigned long V_90 )
{
#if 1
return - V_64 ;
#else
struct V_5 V_91 ;
struct V_39 V_92 ;
int V_93 = 0 ;
switch ( V_89 ) {
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
{
return - V_64 ;
}
case V_100 :
{
if ( F_11 ( & V_92 ) ) return - V_101 ;
if ( F_6 ( & V_91 ) ) return - V_101 ;
V_91 . V_24 = V_92 . V_47 / 3600 ; V_92 . V_47 %= 3600 ;
V_91 . V_25 = V_92 . V_47 / 60 ; V_92 . V_47 %= 60 ;
V_91 . V_26 = V_92 . V_47 ;
break;
}
case V_102 :
{
return F_18 ( V_103 , ( unsigned long * ) V_90 ) ;
}
case V_104 :
{
if ( ( V_90 < 1 ) || ( V_90 > 100 ) ) return - V_64 ;
V_92 . V_47 = 0 ;
V_92 . V_45 = 1000000 / V_90 ;
if ( F_27 ( & V_92 ) ) return - V_101 ;
V_103 = V_90 ;
return 0 ;
}
case V_105 :
{
struct V_106 V_107 ;
if ( F_28 ( & V_107 , (struct V_106 * ) V_90 ,
sizeof( struct V_106 ) ) )
return - V_101 ;
if ( V_107 . V_24 > 23 ) return - V_64 ;
if ( V_107 . V_25 > 59 ) return - V_64 ;
if ( V_107 . V_26 > 59 ) return - V_64 ;
V_92 . V_108 = V_107 . V_24 * 3600 +
V_107 . V_25 * 60 + V_107 . V_26 ;
V_92 . V_109 = 0 ;
if ( F_29 ( & V_92 ) ) return - V_101 ;
return 0 ;
}
case V_110 :
{
if ( F_6 ( & V_91 ) ) return - V_101 ;
break;
}
case V_111 :
{
struct V_5 V_112 ;
unsigned char V_113 , V_114 , V_115 , V_116 , V_108 , V_117 ;
unsigned int V_118 ;
if ( ! F_30 ( V_119 ) )
return - V_120 ;
if ( F_28 ( & V_112 , (struct V_5 * ) V_90 ,
sizeof( struct V_5 ) ) )
return - V_101 ;
V_118 = V_112 . V_20 + 1900 ;
V_113 = V_112 . V_21 + 1 ;
V_114 = V_112 . V_22 ;
V_115 = V_112 . V_24 ;
V_116 = V_112 . V_25 ;
V_108 = V_112 . V_26 ;
if ( V_118 < 1970 )
return - V_64 ;
V_117 = ( ( ! ( V_118 % 4 ) && ( V_118 % 100 ) ) || ! ( V_118 % 400 ) ) ;
if ( ( V_113 > 12 ) || ( V_114 == 0 ) )
return - V_64 ;
if ( V_114 > ( V_121 [ V_113 ] + ( ( V_113 == 2 ) && V_117 ) ) )
return - V_64 ;
if ( ( V_115 >= 24 ) || ( V_116 >= 60 ) || ( V_108 >= 60 ) )
return - V_64 ;
if ( ( V_118 -= V_122 ) > 255 )
return - V_64 ;
return 0 ;
}
case V_123 :
{
return F_18 ( V_76 , ( unsigned long * ) V_90 ) ;
}
case V_124 :
{
if ( V_90 < 1900 )
return - V_64 ;
if ( ! F_30 ( V_119 ) )
return - V_120 ;
V_76 = V_90 ;
return 0 ;
}
default:
return - V_64 ;
}
return F_31 ( ( void * ) V_90 , & V_91 , sizeof V_91 ) ? - V_101 : 0 ;
#endif
}
static long F_32 ( struct V_59 * V_59 ,
unsigned int V_89 , unsigned long V_90 )
{
int V_125 ;
F_33 ( & V_126 ) ;
V_125 = F_26 ( V_59 , V_89 , V_90 ) ;
F_34 ( & V_126 ) ;
return V_125 ;
}
static int T_12 F_35 ( void )
{
int V_125 ;
#ifdef F_36
if ( ! V_127 )
return - V_128 ;
#endif
F_3 ( & V_37 , 1 ) ;
if ( ( V_125 = F_37 ( & F_1 ) ) )
return V_125 ;
if ( F_38 ( & V_129 ) != 0 )
F_39 ( V_130 L_26 ) ;
F_40 ( L_27 , 0 , NULL ,
F_25 , NULL ) ;
F_39 ( V_130 L_28
L_29 V_131 L_30 ) ;
return 0 ;
}
static void T_13 F_41 ( void )
{
F_42 ( L_27 , NULL ) ;
F_43 ( & V_129 ) ;
F_44 ( F_1 ) ;
F_39 ( V_130 L_31 ) ;
}
