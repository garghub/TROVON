void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_6 )
{
switch ( V_6 -> type ) {
case V_7 :
if ( ! ( V_6 -> V_8 . V_9 . V_10 & V_11 ) )
V_4 -> V_12 &= ~ 0x0a ;
V_4 -> V_13 = V_6 -> V_8 . V_9 . V_14 & 0x0f ;
if ( V_6 -> V_8 . V_9 . V_10 & V_15 )
V_4 -> V_16 += 1 ;
if ( V_6 -> V_8 . V_9 . V_17 & V_18 )
V_2 -> V_19 = 1 ;
if ( V_6 -> V_8 . V_9 . V_20 & V_21 )
V_4 -> V_22 |= V_23 ;
break;
case V_24 :
V_4 -> V_13 = V_6 -> V_8 . V_25 . V_14 & 0x0f ;
break;
#ifdef F_2
case V_26 :
if ( V_6 -> V_8 . V_27 . V_14 != - 1 )
V_4 -> V_13 = V_6 -> V_8 . V_27 . V_14 ;
if ( V_6 -> V_8 . V_27 . V_28 != - 1 )
V_4 -> V_29 = V_6 -> V_8 . V_27 . V_28 ;
if ( V_6 -> V_8 . V_27 . V_30 != - 1 )
V_4 -> V_31 = V_6 -> V_8 . V_27 . V_30 ;
switch ( V_6 -> V_8 . V_27 . V_32 ) {
case 0 : V_4 -> V_33 = V_34 ; break;
case 1 : V_4 -> V_33 = V_35 ; break;
case 2 : V_4 -> V_33 = V_36 ; break;
default: break;
}
#endif
default:
break;
}
}
static void
F_3 ( struct V_37 * V_38 , int V_39 , T_1 * V_6 )
{
T_2 * V_40 = & V_6 -> V_39 [ V_39 ] ;
if ( ! ( V_40 -> V_10 & V_41 ) )
V_38 -> V_42 = 0 ;
if ( ! ( V_40 -> V_10 & V_43 ) )
V_38 -> V_22 &= ~ V_44 ;
if ( ! ( V_40 -> V_10 & V_45 ) )
V_38 -> V_22 |= V_46 ;
if ( ! ( V_40 -> V_10 & V_47 ) )
V_38 -> V_22 |= V_48 ;
V_38 -> V_49 = ( V_40 -> V_50 + 3 ) / 4 ;
V_38 -> V_51 = ( V_40 -> V_52 == 0x8 ) ? 0 : 1 ;
}
static void
F_4 ( struct V_37 * V_38 , int V_39 , T_3 * V_6 )
{
struct V_53 * V_40 = & V_6 -> V_39 [ V_39 ] ;
if ( V_40 -> V_10 & V_54 ) {
V_38 -> V_42 = 2 << V_6 -> V_55 ;
}
if ( V_40 -> V_10 & V_56 )
V_38 -> V_22 |= V_44 ;
if ( V_40 -> V_10 & V_57 )
V_38 -> V_49 = V_58 [ V_40 -> V_59 & 0xf ] ;
V_38 -> V_51 = ( V_40 -> V_10 & V_60 ) ? 1 : 0 ;
}
void F_5 ( struct V_37 * V_38 , int V_39 , struct V_5 * V_61 )
{
switch ( V_61 -> type ) {
case V_7 :
F_3 ( V_38 , V_39 , & V_61 -> V_8 . V_9 ) ;
break;
case V_24 :
F_4 ( V_38 , V_39 , & V_61 -> V_8 . V_25 ) ;
break;
default:
break;
}
}
static void F_6 ( struct V_62 * V_4 , T_1 * V_6 )
{
int V_63 ;
printf ( L_1 ,
F_7 ( V_4 ) , V_6 -> V_14 & 0x0f ,
( V_6 -> V_10 & V_64 ) ? L_2 : L_3 ,
( V_6 -> V_10 & V_11 ) ? L_4 : L_3 ,
( V_6 -> V_10 & V_15 ) ? L_5 : L_3 ,
( V_6 -> V_10 & V_65 ) ? L_6 : L_3 ,
( V_6 -> V_20 & V_21 ) ? L_7 : L_3 ,
( V_6 -> V_17 & V_18 ) ? L_8 : L_3 ) ;
for ( V_63 = 0 ; V_63 < 15 ; V_63 ++ ) {
struct T_2 * V_40 = & V_6 -> V_39 [ V_63 ] ;
printf ( L_9 ,
F_7 ( V_4 ) , V_63 ,
( V_40 -> V_10 & V_43 ) ? L_10 : L_3 ,
( V_40 -> V_10 & V_45 ) ? L_11 : L_3 ,
( V_40 -> V_10 & V_47 ) ? L_12 : L_3 ,
( V_40 -> V_10 & V_41 ) ? L_13 : L_3 ,
V_40 -> V_52 ,
V_40 -> V_50 / 4 ,
V_40 -> V_66 ) ;
}
}
static void F_8 ( struct V_62 * V_4 , T_3 * V_6 )
{
int V_63 , V_67 , V_68 ;
char * V_69 ;
V_67 = 2 << V_6 -> V_55 ;
V_68 = 0 ;
if ( V_6 -> V_70 < 6 )
V_68 = V_71 [ V_6 -> V_70 ] ;
switch ( ( V_6 -> V_10 & V_72 ) >> 6 ) {
default:
case 0 : V_69 = L_3 ; break;
case 1 : V_69 = L_14 ; break;
case 2 : V_69 = L_15 ; break;
}
printf ( L_16 ,
F_7 ( V_4 ) , V_6 -> V_14 & 0x0f ,
( V_6 -> V_17 & V_64 ) ? L_2 : L_3 ,
( V_6 -> V_10 & V_73 ) ? L_17 : L_3 ,
( V_6 -> V_10 & V_74 ) ? L_18 : L_3 ,
( V_6 -> V_10 & V_75 ) ? L_19 : L_3 ,
( V_6 -> V_10 & V_76 ) ? L_20 : L_3 ,
( V_6 -> V_10 & V_77 ) ? L_21 : L_3 ,
( V_6 -> V_10 & V_78 ) ? L_12 : L_3 ,
( V_6 -> V_17 & V_79 ) ? L_22 : L_3 ,
V_69 , V_68 , V_67 ) ;
for ( V_63 = 0 ; V_63 <= 15 ; V_63 ++ ) {
int V_80 , V_81 ;
struct V_53 * V_40 = & V_6 -> V_39 [ V_63 ] ;
V_81 = V_40 -> V_59 & 0xf ;
V_80 = V_58 [ V_81 ] ;
printf ( L_23 ,
F_7 ( V_4 ) , V_63 ,
( V_40 -> V_10 & V_82 ) ? L_4 : L_3 ,
( V_40 -> V_10 & V_57 ) ? L_24 : L_3 ,
( V_40 -> V_10 & V_56 ) ? L_10 : L_3 ,
( V_40 -> V_10 & V_83 ) ? L_25 : L_3 ,
( V_40 -> V_10 & V_54 ) ? L_13 : L_3 ,
( V_40 -> V_10 & V_60 ) ? L_26 : L_3 ,
V_80 ) ;
}
}
static void F_6 ( struct V_62 * V_4 , T_1 * V_6 ) { ( void ) V_4 ; ( void ) V_6 ; }
static void F_8 ( struct V_62 * V_4 , T_3 * V_6 ) { ( void ) V_4 ; ( void ) V_6 ; }
static void F_9 ( struct V_62 * V_4 , T_4 V_84 , T_4 * V_85 ,
int V_86 )
{
F_10 ( 5 ) ;
switch ( V_86 ) {
case V_87 :
* V_85 |= V_84 ;
break;
case V_88 :
* V_85 &= 0xfe ;
break;
case V_89 :
* V_85 |= 0x02 ;
break;
case V_90 :
* V_85 &= 0xfd ;
break;
}
F_11 ( V_4 , V_91 , * V_85 ) ;
F_12 ( V_4 , V_92 ) ;
F_10 ( 5 ) ;
}
static void F_13 ( struct V_62 * V_4 , T_4 * V_85 )
{
F_9 ( V_4 , 1 , V_85 , V_87 ) ;
F_9 ( V_4 , 0 , V_85 , V_89 ) ;
F_9 ( V_4 , 0 , V_85 , V_88 ) ;
F_9 ( V_4 , 0 , V_85 , V_90 ) ;
}
static void F_14 ( struct V_62 * V_4 , T_4 * V_85 )
{
F_9 ( V_4 , 0 , V_85 , V_89 ) ;
F_9 ( V_4 , 1 , V_85 , V_87 ) ;
}
static void F_15 ( struct V_62 * V_4 , T_4 * V_93 , T_4 V_84 ,
T_4 * V_85 )
{
F_9 ( V_4 , V_84 , V_85 , V_87 ) ;
F_9 ( V_4 , 0 , V_85 , V_89 ) ;
if ( V_93 )
* V_93 = F_12 ( V_4 , V_91 ) ;
F_9 ( V_4 , 0 , V_85 , V_90 ) ;
F_9 ( V_4 , 0 , V_85 , V_88 ) ;
}
static void F_16 ( struct V_62 * V_4 , T_4 V_84 , T_4 * V_85 ,
T_4 * V_94 )
{
F_11 ( V_4 , V_95 , * V_94 & 0xfe ) ;
F_15 ( V_4 , NULL , V_84 , V_85 ) ;
F_11 ( V_4 , V_95 , * V_94 ) ;
}
static void F_17 ( struct V_62 * V_4 , T_4 * V_93 , T_4 * V_85 ,
T_4 * V_94 )
{
F_11 ( V_4 , V_95 , * V_94 | 0x01 ) ;
F_15 ( V_4 , V_93 , 1 , V_85 ) ;
F_11 ( V_4 , V_95 , * V_94 ) ;
}
static void F_18 ( struct V_62 * V_4 , T_4 * V_96 , T_4 V_97 ,
T_4 * V_85 , T_4 * V_94 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < 8 ; V_98 ++ )
F_15 ( V_4 , NULL , ( V_97 >> ( 7 - V_98 ) ) & 0x01 , V_85 ) ;
F_17 ( V_4 , V_96 , V_85 , V_94 ) ;
}
static void F_19 ( struct V_62 * V_4 , T_4 * V_99 , T_4 V_96 ,
T_4 * V_85 , T_4 * V_94 )
{
int V_98 ;
T_4 V_93 ;
* V_99 = 0 ;
for ( V_98 = 0 ; V_98 < 8 ; V_98 ++ ) {
F_15 ( V_4 , & V_93 , 1 , V_85 ) ;
* V_99 |= ( ( V_93 & 0x01 ) << ( 7 - V_98 ) ) ;
}
F_16 ( V_4 , V_96 , V_85 , V_94 ) ;
}
static int F_20 ( struct V_62 * V_4 , int V_100 ,
T_4 * V_8 , int V_101 )
{
T_4 V_94 , V_85 ;
T_4 V_102 , V_103 ;
T_4 V_96 ;
int V_98 ;
V_103 = F_12 ( V_4 , V_91 ) ;
V_102 = F_12 ( V_4 , V_95 ) ;
V_94 = V_102 & 0x1c ;
F_11 ( V_4 , V_91 , V_103 ) ;
F_11 ( V_4 , V_95 , V_94 ) ;
V_85 = V_103 ;
F_9 ( V_4 , 0 , & V_85 , V_90 ) ;
F_9 ( V_4 , 0 , & V_85 , V_88 ) ;
F_14 ( V_4 , & V_85 ) ;
for ( V_98 = 0 ; V_98 < V_101 ; V_98 += 16 ) {
do {
F_13 ( V_4 , & V_85 ) ;
F_18 ( V_4 , & V_96 ,
0xa0 | ( ( ( V_100 + V_98 ) >> 7 ) & 0x0e ) ,
& V_85 , & V_94 ) ;
} while ( V_96 & 0x01 );
F_18 ( V_4 , & V_96 , ( V_100 + V_98 ) & 0xff ,
& V_85 , & V_94 ) ;
for ( V_104 = 0 ; V_104 < 16 ; V_104 ++ )
F_18 ( V_4 , & V_96 , V_8 [ V_98 + V_104 ] ,
& V_85 , & V_94 ) ;
F_14 ( V_4 , & V_85 ) ;
}
F_11 ( V_4 , V_95 , V_102 ) ;
F_11 ( V_4 , V_91 , V_103 ) ;
return 0 ;
}
static int F_21 ( struct V_62 * V_4 , int V_100 , T_4 * V_8 , int V_101 )
{
T_4 V_94 , V_85 ;
T_4 V_102 , V_103 ;
T_4 V_96 ;
int V_105 = 1 ;
int V_98 ;
V_103 = F_12 ( V_4 , V_91 ) ;
V_102 = F_12 ( V_4 , V_95 ) ;
V_94 = V_102 & 0x1c ;
F_11 ( V_4 , V_91 , V_103 ) ;
F_11 ( V_4 , V_95 , V_94 ) ;
V_85 = V_103 ;
F_9 ( V_4 , 0 , & V_85 , V_90 ) ;
F_9 ( V_4 , 0 , & V_85 , V_88 ) ;
F_14 ( V_4 , & V_85 ) ;
F_13 ( V_4 , & V_85 ) ;
F_18 ( V_4 , & V_96 ,
0xa0 | ( ( V_100 >> 7 ) & 0x0e ) , & V_85 , & V_94 ) ;
if ( V_96 & 0x01 )
goto V_106;
F_18 ( V_4 , & V_96 ,
V_100 & 0xff , & V_85 , & V_94 ) ;
if ( V_96 & 0x01 )
goto V_106;
F_13 ( V_4 , & V_85 ) ;
F_18 ( V_4 , & V_96 ,
0xa1 | ( ( V_100 >> 7 ) & 0x0e ) , & V_85 , & V_94 ) ;
if ( V_96 & 0x01 )
goto V_106;
V_94 |= 0x01 ;
F_11 ( V_4 , V_95 , V_94 ) ;
for ( V_98 = 0 ; V_98 < V_101 ; V_98 ++ )
F_19 ( V_4 , & V_8 [ V_98 ] , ( V_98 == ( V_101 - 1 ) ) , & V_85 , & V_94 ) ;
V_94 &= 0xfe ;
F_11 ( V_4 , V_95 , V_94 ) ;
F_14 ( V_4 , & V_85 ) ;
V_105 = 0 ;
V_106:
F_11 ( V_4 , V_95 , V_102 ) ;
F_11 ( V_4 , V_91 , V_103 ) ;
return V_105 ;
}
static int F_22 ( struct V_62 * V_4 , T_1 * V_6 )
{
static T_4 V_107 [ 6 ] = { 0xfe , 0xfe , 0 , 0 , 0 , 0 } ;
T_4 * V_8 = ( T_4 * ) V_6 ;
int V_101 = sizeof( * V_6 ) ;
T_5 V_108 ;
int V_98 ;
if ( F_21 ( V_4 , V_109 , V_8 , V_101 ) )
return 1 ;
if ( V_6 -> type != 0 ||
memcmp ( V_6 -> V_110 , V_107 , 6 ) ||
V_6 -> V_111 != V_101 - 12 )
return 1 ;
for ( V_98 = 6 , V_108 = 0 ; V_98 < V_101 - 6 ; V_98 ++ )
V_108 += V_8 [ V_98 ] ;
if ( V_108 != V_6 -> V_112 )
return 1 ;
return 0 ;
}
static void F_23 ( struct V_62 * V_4 , T_4 * V_85 )
{
F_11 ( V_4 , V_91 , * V_85 | 0x04 ) ;
F_12 ( V_4 , V_92 ) ;
F_10 ( 2 ) ;
F_11 ( V_4 , V_91 , * V_85 ) ;
}
static void F_24 ( struct V_62 * V_4 , T_4 * V_93 , T_4 * V_85 )
{
F_10 ( 2 ) ;
F_23 ( V_4 , V_85 ) ;
* V_93 = F_12 ( V_4 , V_91 ) ;
}
static void F_25 ( struct V_62 * V_4 , T_4 V_84 , T_4 * V_85 )
{
if ( V_84 & 0x01 )
* V_85 |= 0x02 ;
else
* V_85 &= 0xfd ;
* V_85 |= 0x10 ;
F_11 ( V_4 , V_91 , * V_85 ) ;
F_12 ( V_4 , V_92 ) ;
F_10 ( 2 ) ;
F_23 ( V_4 , V_85 ) ;
}
static void F_26 ( struct V_62 * V_4 , T_4 * V_85 )
{
* V_85 &= 0xef ;
F_11 ( V_4 , V_91 , * V_85 ) ;
F_12 ( V_4 , V_92 ) ;
F_10 ( 2 ) ;
F_23 ( V_4 , V_85 ) ;
}
static void F_27 ( struct V_62 * V_4 , T_5 V_97 ,
T_4 * V_93 , T_4 * V_85 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < 9 ; V_98 ++ )
F_25 ( V_4 , ( T_4 ) ( V_97 >> ( 8 - V_98 ) ) , V_85 ) ;
* V_93 = F_12 ( V_4 , V_91 ) ;
}
static void F_28 ( struct V_62 * V_4 ,
unsigned short * V_113 , unsigned char * V_85 )
{
int V_98 ;
T_4 V_93 ;
* V_113 = 0 ;
for ( V_98 = 0 ; V_98 < 16 ; V_98 ++ ) {
F_24 ( V_4 , & V_93 , V_85 ) ;
if ( V_93 & 0x01 )
* V_113 |= ( 0x01 << ( 15 - V_98 ) ) ;
else
* V_113 &= ~ ( 0x01 << ( 15 - V_98 ) ) ;
}
}
static int F_29 ( struct V_62 * V_4 , unsigned short * V_8 ,
int V_101 , unsigned char * V_85 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_101 ; V_98 ++ ) {
unsigned char V_93 ;
F_27 ( V_4 , 0x180 | V_98 , & V_93 , V_85 ) ;
if ( V_93 & 0x01 )
return 1 ;
F_28 ( V_4 , & V_8 [ V_98 ] , V_85 ) ;
F_26 ( V_4 , V_85 ) ;
}
return 0 ;
}
static int F_30 ( struct V_62 * V_4 , T_3 * V_6 )
{
T_4 V_94 , V_85 ;
T_4 V_102 , V_103 ;
int V_105 = 1 ;
V_103 = F_12 ( V_4 , V_91 ) ;
V_102 = F_12 ( V_4 , V_95 ) ;
V_85 = V_103 & 0xe9 ;
F_11 ( V_4 , V_91 , V_85 ) ;
V_94 = ( V_102 & 0xe9 ) | 0x09 ;
F_11 ( V_4 , V_95 , V_94 ) ;
V_105 = F_29 ( V_4 , ( T_5 * ) V_6 ,
sizeof( * V_6 ) / sizeof( short ) , & V_85 ) ;
F_11 ( V_4 , V_95 , V_102 ) ;
F_11 ( V_4 , V_91 , V_103 ) ;
return V_105 ;
}
static int F_31 ( struct V_62 * V_4 , T_3 * V_6 )
{
T_4 * V_8 = ( T_4 * ) V_6 ;
int V_101 = sizeof( * V_6 ) ;
T_5 V_108 ;
int V_98 ;
switch ( V_4 -> V_114 -> V_115 ) {
case V_116 :
case V_117 :
case V_118 :
V_98 = F_21 ( V_4 , V_119 ,
V_8 , V_101 ) ;
break;
case V_120 :
V_98 = F_21 ( V_4 , V_119 ,
V_8 , V_101 ) ;
if ( ! V_98 )
break;
default:
V_98 = F_30 ( V_4 , V_6 ) ;
break;
}
if ( V_98 )
return 1 ;
for ( V_98 = 0 , V_108 = 0 ; V_98 < V_101 - 1 ; V_98 += 2 )
V_108 += V_8 [ V_98 ] + ( V_8 [ V_98 + 1 ] << 8 ) ;
if ( V_108 != 0x1234 )
return 1 ;
return 0 ;
}
static int F_32 ( struct V_62 * V_4 , struct V_121 * V_122 )
{
struct V_123 V_124 ;
F_33 ( V_4 -> V_114 , & V_124 ) ;
if ( ! F_34 ( & V_124 , V_122 ) )
return 0 ;
return V_26 ;
}
static inline int F_32 ( struct V_62 * V_4 ,
struct V_121 * V_98 )
{
return 0 ;
}
int F_35 ( struct V_62 * V_4 , struct V_5 * V_61 )
{
if ( ! F_22 ( V_4 , & V_61 -> V_8 . V_9 ) ) {
V_61 -> type = V_7 ;
F_6 ( V_4 , & V_61 -> V_8 . V_9 ) ;
} else if ( ! F_31 ( V_4 , & V_61 -> V_8 . V_25 ) ) {
V_61 -> type = V_24 ;
F_8 ( V_4 , & V_61 -> V_8 . V_25 ) ;
} else {
V_61 -> type = F_32 ( V_4 , & V_61 -> V_8 . V_27 ) ;
}
return V_61 -> type ;
}
char * F_36 ( struct V_5 * V_61 )
{
switch ( V_61 -> type ) {
case V_7 :
return L_27 ;
case V_24 :
return L_28 ;
case V_26 :
return L_29 ;
default:
return L_30 ;
}
}
