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
if ( F_5 ( F_6 ( & V_8 ) ) )
return - 1 ;
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
static int F_7 ( struct V_5 * V_6 )
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
static T_3 F_8 ( T_1 V_29 , int V_30 )
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
if ( F_5 ( F_6 ( & V_37 ) ) )
return - 1 ;
if ( F_4 ( & V_9 ) ) return - 1 ;
if ( F_5 ( F_6 ( & V_37 ) ) )
return - 1 ;
F_9 ( & V_37 ) ;
return ( V_10 [ 5 ] |
( ( V_38 ) ( V_10 [ 10 ] ) << 8 ) | ( ( V_38 ) ( V_10 [ 15 ] ) << 16 ) |
( ( V_38 ) ( V_10 [ 20 ] ) << 24 ) | ( ( V_38 ) ( V_10 [ 25 ] ) << 32 ) ) ;
}
static inline int F_10 ( struct V_39 * V_40 ) {
T_3 V_41 ;
T_4 V_42 ;
unsigned int V_43 ;
V_41 = F_8 ( V_44 , 5 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( T_4 ) V_41 & 0xffffff ;
V_43 = ( unsigned int ) ( V_41 >> 24 ) & 0xffff ;
V_40 -> V_45 = ( V_46 ) ( V_42 % 100 ) * 10000 ;
V_40 -> V_47 = ( V_48 ) ( V_42 / 100 ) + V_43 * 86400 ;
return 0 ;
}
static inline int F_11 ( struct V_39 * V_40 ) {
T_3 V_41 ;
unsigned int V_42 ;
V_41 = F_8 ( V_49 , 2 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( unsigned int ) V_41 & 0xffff ;
V_40 -> V_45 = ( V_46 ) ( V_42 % 100 ) * 10000 ;
V_40 -> V_47 = ( V_48 ) ( V_42 / 100 ) ;
return 0 ;
}
static inline int F_12 ( struct V_39 * V_40 ) {
T_3 V_41 ;
T_4 V_42 ;
V_41 = F_8 ( V_50 , 3 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( T_4 ) V_41 & 0xffffff ;
V_40 -> V_45 = ( V_46 ) ( V_42 % 100 ) * 10000 ;
V_40 -> V_47 = ( V_48 ) ( V_42 / 100 ) ;
return 0 ;
}
static inline int F_13 ( struct V_39 * V_40 ) {
T_3 V_41 ;
T_4 V_42 ;
V_41 = F_8 ( V_51 , 3 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( T_4 ) V_41 & 0xffffff ;
V_40 -> V_45 = ( V_46 ) ( V_42 % 100 ) * 10000 ;
V_40 -> V_47 = ( V_48 ) ( V_42 / 100 ) ;
return 0 ;
}
static inline int F_14 ( struct V_39 * V_40 ) {
T_3 V_41 ;
T_4 V_42 ;
V_41 = F_8 ( V_52 , 3 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( T_4 ) V_41 & 0xffffff ;
V_40 -> V_45 = ( V_46 ) ( V_42 % 100 ) * 10000 ;
V_40 -> V_47 = ( V_48 ) ( V_42 / 100 ) ;
return 0 ;
}
static T_5 F_15 ( struct V_53 * V_53 , char T_6 * V_54 ,
T_7 V_55 , T_8 * V_56 ) {
T_5 V_57 ;
if ( V_55 < sizeof( unsigned long ) )
return - V_58 ;
V_57 = F_16 ( 68 , ( unsigned long T_6 * ) V_54 ) ;
return V_57 ;
}
static unsigned int F_17 ( struct V_53 * V_53 , T_9 * V_59 )
{
unsigned long V_60 ;
V_60 = 0 ;
if ( V_60 != 0 )
return V_61 | V_62 ;
return 0 ;
}
static int F_18 ( struct V_63 * V_63 , struct V_53 * V_53 )
{
return 0 ;
}
static int F_19 ( int V_64 , struct V_53 * V_65 , int V_66 )
{
return F_20 ( V_64 , V_65 , V_66 , & V_67 ) ;
}
static int F_21 ( char * V_54 )
{
#define YN ( T_10 ) ("no")
#define F_22 ( T_10 ) ("yes")
char * V_68 ;
struct V_5 V_27 ;
struct V_39 V_69 ;
memset ( & V_27 , 0 , sizeof( struct V_5 ) ) ;
V_68 = V_54 ;
if ( F_7 ( & V_27 ) ) {
V_68 += sprintf ( V_68 , L_1 ) ;
} else {
V_68 += sprintf ( V_68 ,
L_2
L_3
L_4 ,
V_27 . V_24 , V_27 . V_25 , V_27 . V_26 ,
V_27 . V_20 + 1900 , V_27 . V_21 + 1 ,
V_27 . V_22 , V_70 ) ;
}
if ( F_10 ( & V_69 ) ) {
V_68 += sprintf ( V_68 , L_5 ) ;
} else {
V_68 += sprintf ( V_68 , L_6 ,
V_69 . V_47 , ( int ) V_69 . V_45 / 1000 ) ;
}
if ( F_11 ( & V_69 ) ) {
V_68 += sprintf ( V_68 , L_7 ) ;
} else {
V_68 += sprintf ( V_68 , L_8 ,
V_69 . V_47 , ( int ) V_69 . V_45 / 1000 ) ;
}
if ( F_12 ( & V_69 ) ) {
V_68 += sprintf ( V_68 , L_9 ) ;
} else {
V_68 += sprintf ( V_68 , L_10 ,
V_69 . V_47 , ( int ) V_69 . V_45 / 1000 ) ;
}
if ( F_13 ( & V_69 ) ) {
V_68 += sprintf ( V_68 , L_11 ) ;
} else {
V_68 += sprintf ( V_68 , L_12 ,
V_69 . V_47 , ( int ) V_69 . V_45 / 1000 ) ;
}
if ( F_14 ( & V_69 ) ) {
V_68 += sprintf ( V_68 , L_13 ) ;
} else {
V_68 += sprintf ( V_68 , L_14 ,
V_69 . V_47 , ( int ) V_69 . V_45 / 1000 ) ;
}
V_68 += sprintf ( V_68 ,
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23 ,
YN ( V_71 ) ,
F_22 ( V_72 ) ,
YN ( V_73 ) ,
YN ( V_74 ) ,
YN ( V_75 ) ,
YN ( V_76 ) ,
YN ( V_77 ) ,
1UL ,
1 ? L_24 : L_25 ) ;
return V_68 - V_54 ;
#undef YN
#undef F_22
}
static int F_23 ( char * V_78 , char * * V_79 , T_11 V_80 ,
int V_55 , int * V_81 , void * V_4 )
{
int V_82 = F_21 ( V_78 ) ;
if ( V_82 <= V_80 + V_55 ) * V_81 = 1 ;
* V_79 = V_78 + V_80 ;
V_82 -= V_80 ;
if ( V_82 > V_55 ) V_82 = V_55 ;
if ( V_82 < 0 ) V_82 = 0 ;
return V_82 ;
}
static int F_24 ( struct V_53 * V_53 ,
unsigned int V_83 , unsigned long V_84 )
{
#if 1
return - V_58 ;
#else
struct V_5 V_85 ;
struct V_39 V_86 ;
int V_87 = 0 ;
switch ( V_83 ) {
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
{
return - V_58 ;
}
case V_94 :
{
if ( F_12 ( & V_86 ) ) return - V_95 ;
if ( F_7 ( & V_85 ) ) return - V_95 ;
V_85 . V_24 = V_86 . V_47 / 3600 ; V_86 . V_47 %= 3600 ;
V_85 . V_25 = V_86 . V_47 / 60 ; V_86 . V_47 %= 60 ;
V_85 . V_26 = V_86 . V_47 ;
break;
}
case V_96 :
{
return F_16 ( V_97 , ( unsigned long * ) V_84 ) ;
}
case V_98 :
{
if ( ( V_84 < 1 ) || ( V_84 > 100 ) ) return - V_58 ;
V_86 . V_47 = 0 ;
V_86 . V_45 = 1000000 / V_84 ;
if ( F_25 ( & V_86 ) ) return - V_95 ;
V_97 = V_84 ;
return 0 ;
}
case V_99 :
{
struct V_100 V_101 ;
if ( F_26 ( & V_101 , (struct V_100 * ) V_84 ,
sizeof( struct V_100 ) ) )
return - V_95 ;
if ( V_101 . V_24 > 23 ) return - V_58 ;
if ( V_101 . V_25 > 59 ) return - V_58 ;
if ( V_101 . V_26 > 59 ) return - V_58 ;
V_86 . V_102 = V_101 . V_24 * 3600 +
V_101 . V_25 * 60 + V_101 . V_26 ;
V_86 . V_103 = 0 ;
if ( F_27 ( & V_86 ) ) return - V_95 ;
return 0 ;
}
case V_104 :
{
if ( F_7 ( & V_85 ) ) return - V_95 ;
break;
}
case V_105 :
{
struct V_5 V_106 ;
unsigned char V_107 , V_108 , V_109 , V_110 , V_102 , V_111 ;
unsigned int V_112 ;
if ( ! F_28 ( V_113 ) )
return - V_114 ;
if ( F_26 ( & V_106 , (struct V_5 * ) V_84 ,
sizeof( struct V_5 ) ) )
return - V_95 ;
V_112 = V_106 . V_20 + 1900 ;
V_107 = V_106 . V_21 + 1 ;
V_108 = V_106 . V_22 ;
V_109 = V_106 . V_24 ;
V_110 = V_106 . V_25 ;
V_102 = V_106 . V_26 ;
if ( V_112 < 1970 )
return - V_58 ;
V_111 = ( ( ! ( V_112 % 4 ) && ( V_112 % 100 ) ) || ! ( V_112 % 400 ) ) ;
if ( ( V_107 > 12 ) || ( V_108 == 0 ) )
return - V_58 ;
if ( V_108 > ( V_115 [ V_107 ] + ( ( V_107 == 2 ) && V_111 ) ) )
return - V_58 ;
if ( ( V_109 >= 24 ) || ( V_110 >= 60 ) || ( V_102 >= 60 ) )
return - V_58 ;
if ( ( V_112 -= V_116 ) > 255 )
return - V_58 ;
return 0 ;
}
case V_117 :
{
return F_16 ( V_70 , ( unsigned long * ) V_84 ) ;
}
case V_118 :
{
if ( V_84 < 1900 )
return - V_58 ;
if ( ! F_28 ( V_113 ) )
return - V_114 ;
V_70 = V_84 ;
return 0 ;
}
default:
return - V_58 ;
}
return F_29 ( ( void * ) V_84 , & V_85 , sizeof V_85 ) ? - V_95 : 0 ;
#endif
}
static long F_30 ( struct V_53 * V_53 ,
unsigned int V_83 , unsigned long V_84 )
{
int V_119 ;
F_31 ( & V_120 ) ;
V_119 = F_24 ( V_53 , V_83 , V_84 ) ;
F_32 ( & V_120 ) ;
return V_119 ;
}
static int T_12 F_33 ( void )
{
int V_119 ;
#ifdef F_34
if ( ! V_121 )
return - V_122 ;
#endif
F_3 ( & V_37 , 1 ) ;
if ( ( V_119 = F_35 ( & F_1 ) ) )
return V_119 ;
if ( F_36 ( & V_123 ) != 0 )
F_37 ( V_124 L_26 ) ;
F_38 ( L_27 , 0 , NULL ,
F_23 , NULL ) ;
F_37 ( V_124 L_28
L_29 V_125 L_30 ) ;
return 0 ;
}
static void T_13 F_39 ( void )
{
F_40 ( L_27 , NULL ) ;
F_41 ( & V_123 ) ;
F_42 ( F_1 ) ;
F_37 ( V_124 L_31 ) ;
}
