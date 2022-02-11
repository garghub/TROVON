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
if ( F_4 ( & V_9 ) ) {
F_9 ( & V_37 ) ;
return - 1 ;
}
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
V_40 -> V_45 = ( long ) ( V_42 % 100 ) * 10000 * 1000 ;
V_40 -> V_46 = ( V_42 / 100 ) + ( V_47 ) V_43 * 86400 ;
return 0 ;
}
static inline int F_11 ( struct V_39 * V_40 ) {
T_3 V_41 ;
unsigned int V_42 ;
V_41 = F_8 ( V_48 , 2 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( unsigned int ) V_41 & 0xffff ;
V_40 -> V_45 = ( long ) ( V_42 % 100 ) * 10000 * 1000 ;
V_40 -> V_46 = ( V_47 ) ( V_42 / 100 ) ;
return 0 ;
}
static inline int F_12 ( struct V_39 * V_40 ) {
T_3 V_41 ;
T_4 V_42 ;
V_41 = F_8 ( V_49 , 3 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( T_4 ) V_41 & 0xffffff ;
V_40 -> V_45 = ( long ) ( V_42 % 100 ) * 10000 * 1000 ;
V_40 -> V_46 = ( V_47 ) ( V_42 / 100 ) ;
return 0 ;
}
static inline int F_13 ( struct V_39 * V_40 ) {
T_3 V_41 ;
T_4 V_42 ;
V_41 = F_8 ( V_50 , 3 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( T_4 ) V_41 & 0xffffff ;
V_40 -> V_45 = ( long ) ( V_42 % 100 ) * 10000 * 1000 ;
V_40 -> V_46 = ( V_47 ) ( V_42 / 100 ) ;
return 0 ;
}
static inline int F_14 ( struct V_39 * V_40 ) {
T_3 V_41 ;
T_4 V_42 ;
V_41 = F_8 ( V_51 , 3 ) ;
if ( V_41 < 0 ) return - 1 ;
V_42 = ( T_4 ) V_41 & 0xffffff ;
V_40 -> V_45 = ( long ) ( V_42 % 100 ) * 10000 * 1000 ;
V_40 -> V_46 = ( V_47 ) ( V_42 / 100 ) ;
return 0 ;
}
static T_5 F_15 ( struct V_52 * V_52 , char T_6 * V_53 ,
T_7 V_54 , T_8 * V_55 ) {
T_5 V_56 ;
if ( V_54 < sizeof( unsigned long ) )
return - V_57 ;
V_56 = F_16 ( 68 , ( unsigned long T_6 * ) V_53 ) ;
return V_56 ;
}
static unsigned int F_17 ( struct V_52 * V_52 , T_9 * V_58 )
{
unsigned long V_59 ;
V_59 = 0 ;
if ( V_59 != 0 )
return V_60 | V_61 ;
return 0 ;
}
static int F_18 ( struct V_62 * V_62 , struct V_52 * V_52 )
{
return 0 ;
}
static int F_19 ( int V_63 , struct V_52 * V_64 , int V_65 )
{
return F_20 ( V_63 , V_64 , V_65 , & V_66 ) ;
}
static int F_21 ( struct V_67 * V_68 , void * V_69 )
{
#define YN ( T_10 ) ("no")
#define F_22 ( T_10 ) ("yes")
struct V_5 V_27 ;
struct V_39 V_70 ;
memset ( & V_27 , 0 , sizeof( struct V_5 ) ) ;
if ( F_7 ( & V_27 ) ) {
F_23 ( V_68 , L_1 ) ;
} else {
F_24 ( V_68 ,
L_2
L_3
L_4 ,
V_27 . V_24 , V_27 . V_25 , V_27 . V_26 ,
V_27 . V_20 + 1900 , V_27 . V_21 + 1 ,
V_27 . V_22 , V_71 ) ;
}
if ( F_10 ( & V_70 ) ) {
F_23 ( V_68 , L_5 ) ;
} else {
F_24 ( V_68 , L_6 ,
( V_72 ) V_70 . V_46 , ( long ) V_70 . V_45 / 1000000L ) ;
}
if ( F_11 ( & V_70 ) ) {
F_23 ( V_68 , L_7 ) ;
} else {
F_24 ( V_68 , L_8 ,
( V_72 ) V_70 . V_46 , ( long ) V_70 . V_45 / 1000000L ) ;
}
if ( F_12 ( & V_70 ) ) {
F_23 ( V_68 , L_9 ) ;
} else {
F_24 ( V_68 , L_10 ,
( V_72 ) V_70 . V_46 , ( long ) V_70 . V_45 / 1000000L ) ;
}
if ( F_13 ( & V_70 ) ) {
F_23 ( V_68 , L_11 ) ;
} else {
F_24 ( V_68 , L_12 ,
( V_72 ) V_70 . V_46 , ( long ) V_70 . V_45 / 1000000L ) ;
}
if ( F_14 ( & V_70 ) ) {
F_23 ( V_68 , L_13 ) ;
} else {
F_24 ( V_68 , L_14 ,
( V_72 ) V_70 . V_46 , ( long ) V_70 . V_45 / 1000000L ) ;
}
F_24 ( V_68 ,
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23 ,
YN ( V_73 ) ,
F_22 ( V_74 ) ,
YN ( V_75 ) ,
YN ( V_76 ) ,
YN ( V_77 ) ,
YN ( V_78 ) ,
YN ( V_79 ) ,
1UL ,
1 ? L_24 : L_25 ) ;
return 0 ;
#undef YN
#undef F_22
}
static int F_25 ( struct V_62 * V_62 , struct V_52 * V_52 )
{
return F_26 ( V_52 , F_21 , NULL ) ;
}
static int F_27 ( struct V_52 * V_52 ,
unsigned int V_80 , unsigned long V_81 )
{
#if 1
return - V_57 ;
#else
struct V_5 V_82 ;
struct V_83 V_84 ;
int V_85 = 0 ;
switch ( V_80 ) {
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
{
return - V_57 ;
}
case V_92 :
{
if ( F_12 ( & V_84 ) ) return - V_93 ;
if ( F_7 ( & V_82 ) ) return - V_93 ;
V_82 . V_24 = V_84 . V_46 / 3600 ; V_84 . V_46 %= 3600 ;
V_82 . V_25 = V_84 . V_46 / 60 ; V_84 . V_46 %= 60 ;
V_82 . V_26 = V_84 . V_46 ;
break;
}
case V_94 :
{
return F_16 ( V_95 , ( unsigned long * ) V_81 ) ;
}
case V_96 :
{
if ( ( V_81 < 1 ) || ( V_81 > 100 ) ) return - V_57 ;
V_84 . V_46 = 0 ;
V_84 . V_97 = 1000000 / V_81 ;
if ( F_28 ( & V_84 ) ) return - V_93 ;
V_95 = V_81 ;
return 0 ;
}
case V_98 :
{
struct V_99 V_100 ;
if ( F_29 ( & V_100 , (struct V_99 * ) V_81 ,
sizeof( struct V_99 ) ) )
return - V_93 ;
if ( V_100 . V_24 > 23 ) return - V_57 ;
if ( V_100 . V_25 > 59 ) return - V_57 ;
if ( V_100 . V_26 > 59 ) return - V_57 ;
V_84 . V_101 = V_100 . V_24 * 3600 +
V_100 . V_25 * 60 + V_100 . V_26 ;
V_84 . V_102 = 0 ;
if ( F_30 ( & V_84 ) ) return - V_93 ;
return 0 ;
}
case V_103 :
{
if ( F_7 ( & V_82 ) ) return - V_93 ;
break;
}
case V_104 :
{
struct V_5 V_105 ;
unsigned char V_106 , V_107 , V_108 , V_109 , V_101 , V_110 ;
unsigned int V_111 ;
if ( ! F_31 ( V_112 ) )
return - V_113 ;
if ( F_29 ( & V_105 , (struct V_5 * ) V_81 ,
sizeof( struct V_5 ) ) )
return - V_93 ;
V_111 = V_105 . V_20 + 1900 ;
V_106 = V_105 . V_21 + 1 ;
V_107 = V_105 . V_22 ;
V_108 = V_105 . V_24 ;
V_109 = V_105 . V_25 ;
V_101 = V_105 . V_26 ;
if ( V_111 < 1970 )
return - V_57 ;
V_110 = ( ( ! ( V_111 % 4 ) && ( V_111 % 100 ) ) || ! ( V_111 % 400 ) ) ;
if ( ( V_106 > 12 ) || ( V_107 == 0 ) )
return - V_57 ;
if ( V_107 > ( V_114 [ V_106 ] + ( ( V_106 == 2 ) && V_110 ) ) )
return - V_57 ;
if ( ( V_108 >= 24 ) || ( V_109 >= 60 ) || ( V_101 >= 60 ) )
return - V_57 ;
if ( ( V_111 -= V_115 ) > 255 )
return - V_57 ;
return 0 ;
}
case V_116 :
{
return F_16 ( V_71 , ( unsigned long * ) V_81 ) ;
}
case V_117 :
{
if ( V_81 < 1900 )
return - V_57 ;
if ( ! F_31 ( V_112 ) )
return - V_113 ;
V_71 = V_81 ;
return 0 ;
}
default:
return - V_57 ;
}
return F_32 ( ( void * ) V_81 , & V_82 , sizeof V_82 ) ? - V_93 : 0 ;
#endif
}
static long F_33 ( struct V_52 * V_52 ,
unsigned int V_80 , unsigned long V_81 )
{
int V_118 ;
F_34 ( & V_119 ) ;
V_118 = F_27 ( V_52 , V_80 , V_81 ) ;
F_35 ( & V_119 ) ;
return V_118 ;
}
static int T_11 F_36 ( void )
{
int V_118 ;
#ifdef F_37
if ( ! V_120 )
return - V_121 ;
#endif
F_3 ( & V_37 , 1 ) ;
if ( ( V_118 = F_38 ( & F_1 ) ) )
return V_118 ;
if ( F_39 ( & V_122 ) != 0 )
F_40 ( V_123 L_26 ) ;
F_41 ( L_27 , 0 , NULL , & V_124 ) ;
F_40 ( V_123 L_28
L_29 V_125 L_30 ) ;
return 0 ;
}
static void T_12 F_42 ( void )
{
F_43 ( L_27 , NULL ) ;
F_44 ( & V_122 ) ;
F_45 ( F_1 ) ;
F_40 ( V_123 L_31 ) ;
}
