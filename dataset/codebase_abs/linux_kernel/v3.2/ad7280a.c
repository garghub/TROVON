static void F_1 ( unsigned char * V_1 )
{
unsigned char V_2 , V_3 ;
int V_4 , V_5 ;
for ( V_4 = 0 ; V_4 < 256 ; V_4 ++ ) {
V_3 = V_4 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
V_2 = V_3 & V_6 ;
V_3 <<= 1 ;
if ( V_2 )
V_3 ^= V_7 ;
}
V_1 [ V_4 ] = V_3 ;
}
}
static unsigned char F_2 ( unsigned char * V_1 , unsigned V_8 )
{
unsigned char V_3 ;
V_3 = V_1 [ V_8 >> 16 & 0xFF ] ;
V_3 = V_1 [ V_3 ^ ( V_8 >> 8 & 0xFF ) ] ;
return V_3 ^ ( V_8 & 0xFF ) ;
}
static int F_3 ( struct V_9 * V_10 , unsigned V_8 )
{
unsigned char V_3 = F_2 ( V_10 -> V_1 , V_8 >> 10 ) ;
if ( V_3 != ( ( V_8 >> 2 ) & 0xFF ) )
return - V_11 ;
return 0 ;
}
static void F_4 ( struct V_9 * V_10 )
{
if ( V_10 -> V_12 < 50 )
F_5 ( V_10 -> V_12 ) ;
else
F_6 ( 1 ) ;
}
static int F_7 ( struct V_13 * V_14 , unsigned * V_8 )
{
unsigned V_15 , V_16 = F_8 ( V_17 ) ;
int V_18 ;
struct V_19 V_20 = {
. V_16 = & V_16 ,
. V_15 = & V_15 ,
. V_21 = 4 ,
} ;
struct V_22 V_23 ;
F_9 ( & V_23 ) ;
F_10 ( & V_20 , & V_23 ) ;
V_18 = F_11 ( V_14 , & V_23 ) ;
if ( V_18 )
return V_18 ;
* V_8 = F_12 ( V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 , unsigned V_24 ,
unsigned V_25 , bool V_26 , unsigned V_8 )
{
unsigned V_27 = ( V_24 << 27 | V_25 << 21 |
( V_8 & 0xFF ) << 13 | V_26 << 12 ) ;
V_27 |= F_2 ( V_10 -> V_1 , V_27 >> 11 ) << 3 | 0x2 ;
V_27 = F_8 ( V_27 ) ;
return F_14 ( V_10 -> V_14 , & V_27 , 4 ) ;
}
static int F_15 ( struct V_9 * V_10 , unsigned V_24 ,
unsigned V_25 )
{
int V_18 ;
unsigned V_28 ;
V_18 = F_13 ( V_10 , V_29 , V_30 , 1 ,
V_31 |
V_32 |
V_10 -> V_33 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_13 ( V_10 , V_24 , V_30 , 0 ,
V_31 |
V_34 |
V_10 -> V_33 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_13 ( V_10 , V_24 , V_35 , 0 , V_25 << 2 ) ;
if ( V_18 )
return V_18 ;
F_7 ( V_10 -> V_14 , & V_28 ) ;
if ( F_3 ( V_10 , V_28 ) )
return - V_11 ;
if ( ( ( V_28 >> 27 ) != V_24 ) || ( ( ( V_28 >> 21 ) & 0x3F ) != V_25 ) )
return - V_36 ;
return ( V_28 >> 13 ) & 0xFF ;
}
static int F_16 ( struct V_9 * V_10 , unsigned V_24 ,
unsigned V_25 )
{
int V_18 ;
unsigned V_28 ;
V_18 = F_13 ( V_10 , V_24 , V_35 , 0 , V_25 << 2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_13 ( V_10 , V_29 , V_30 , 1 ,
V_31 |
V_32 |
V_10 -> V_33 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_13 ( V_10 , V_24 , V_30 , 0 ,
V_31 |
V_34 |
V_37 |
V_10 -> V_33 ) ;
if ( V_18 )
return V_18 ;
F_4 ( V_10 ) ;
F_7 ( V_10 -> V_14 , & V_28 ) ;
if ( F_3 ( V_10 , V_28 ) )
return - V_11 ;
if ( ( ( V_28 >> 27 ) != V_24 ) || ( ( ( V_28 >> 23 ) & 0xF ) != V_25 ) )
return - V_36 ;
return ( V_28 >> 11 ) & 0xFFF ;
}
static int F_17 ( struct V_9 * V_10 , unsigned V_4 ,
unsigned * V_38 )
{
int V_5 , V_18 ;
unsigned V_28 , V_39 = 0 ;
V_18 = F_13 ( V_10 , V_29 , V_35 , 1 ,
V_40 << 2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_13 ( V_10 , V_29 , V_30 , 1 ,
V_31 |
V_34 |
V_37 |
V_10 -> V_33 ) ;
if ( V_18 )
return V_18 ;
F_4 ( V_10 ) ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
F_7 ( V_10 -> V_14 , & V_28 ) ;
if ( F_3 ( V_10 , V_28 ) )
return - V_11 ;
if ( V_38 )
V_38 [ V_5 ] = V_28 ;
if ( ( ( V_28 >> 23 ) & 0xF ) <= V_41 )
V_39 += ( ( V_28 >> 11 ) & 0xFFF ) ;
}
return V_39 ;
}
static int F_18 ( struct V_9 * V_10 )
{
unsigned V_8 , V_42 ;
int V_18 ;
V_18 = F_13 ( V_10 , V_29 , V_43 , 1 ,
V_44 |
V_45 |
V_46 |
V_47 |
V_10 -> V_48 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_13 ( V_10 , V_29 , V_43 , 1 ,
V_44 |
V_45 |
V_46 |
V_10 -> V_48 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_13 ( V_10 , V_29 , V_35 , 1 ,
V_43 << 2 ) ;
if ( V_18 )
return V_18 ;
for ( V_42 = 0 ; V_42 <= V_49 ; V_42 ++ ) {
F_7 ( V_10 -> V_14 , & V_8 ) ;
if ( V_8 == 0 )
return V_42 - 1 ;
if ( F_3 ( V_10 , V_8 ) )
return - V_11 ;
if ( V_42 != F_19 ( V_8 >> 27 ) )
return - V_11 ;
}
return - V_36 ;
}
static T_1 F_20 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_54 )
{
struct V_55 * V_56 = F_21 ( V_51 ) ;
struct V_9 * V_10 = F_22 ( V_56 ) ;
struct V_57 * V_58 = F_23 ( V_53 ) ;
return sprintf ( V_54 , L_1 ,
! ! ( V_10 -> V_59 [ V_58 -> V_60 >> 8 ] &
( 1 << ( ( V_58 -> V_60 & 0xFF ) + 2 ) ) ) ) ;
}
static T_1 F_24 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_54 ,
T_2 V_21 )
{
struct V_55 * V_56 = F_21 ( V_51 ) ;
struct V_9 * V_10 = F_22 ( V_56 ) ;
struct V_57 * V_58 = F_23 ( V_53 ) ;
bool V_61 ;
int V_18 ;
unsigned V_24 , V_62 ;
V_18 = F_25 ( V_54 , & V_61 ) ;
if ( V_18 )
return V_18 ;
V_24 = V_58 -> V_60 >> 8 ;
V_62 = V_58 -> V_60 & 0xFF ;
F_26 ( & V_56 -> V_63 ) ;
if ( V_61 )
V_10 -> V_59 [ V_24 ] |= 1 << ( V_62 + 2 ) ;
else
V_10 -> V_59 [ V_24 ] &= ~ ( 1 << ( V_62 + 2 ) ) ;
V_18 = F_13 ( V_10 , V_24 , V_64 ,
0 , V_10 -> V_59 [ V_24 ] ) ;
F_27 ( & V_56 -> V_63 ) ;
return V_18 ? V_18 : V_21 ;
}
static T_1 F_28 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_54 )
{
struct V_55 * V_56 = F_21 ( V_51 ) ;
struct V_9 * V_10 = F_22 ( V_56 ) ;
struct V_57 * V_58 = F_23 ( V_53 ) ;
int V_18 ;
unsigned V_65 ;
F_26 ( & V_56 -> V_63 ) ;
V_18 = F_15 ( V_10 , V_58 -> V_60 >> 8 ,
V_58 -> V_60 & 0xFF ) ;
F_27 ( & V_56 -> V_63 ) ;
if ( V_18 < 0 )
return V_18 ;
V_65 = ( V_18 >> 3 ) * 71500 ;
return sprintf ( V_54 , L_1 , V_65 ) ;
}
static T_1 F_29 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_54 ,
T_2 V_21 )
{
struct V_55 * V_56 = F_21 ( V_51 ) ;
struct V_9 * V_10 = F_22 ( V_56 ) ;
struct V_57 * V_58 = F_23 ( V_53 ) ;
long V_8 ;
int V_18 ;
V_18 = F_30 ( V_54 , 10 , & V_8 ) ;
if ( V_18 )
return V_18 ;
V_8 /= 71500 ;
if ( V_8 > 31 )
return - V_66 ;
F_26 ( & V_56 -> V_63 ) ;
V_18 = F_13 ( V_10 , V_58 -> V_60 >> 8 ,
V_58 -> V_60 & 0xFF ,
0 , ( V_8 & 0x1F ) << 3 ) ;
F_27 ( & V_56 -> V_63 ) ;
return V_18 ? V_18 : V_21 ;
}
static int F_31 ( struct V_9 * V_10 )
{
int V_51 , V_62 , V_4 ;
V_10 -> V_67 = F_32 ( sizeof( * V_10 -> V_67 ) *
( ( V_10 -> V_68 + 1 ) * 12 + 2 ) , V_69 ) ;
if ( V_10 -> V_67 == NULL )
return - V_70 ;
for ( V_51 = 0 , V_4 = 0 ; V_51 <= V_10 -> V_68 ; V_51 ++ )
for ( V_62 = V_40 ; V_62 <= V_71 ; V_62 ++ ,
V_4 ++ ) {
if ( V_62 < V_72 ) {
V_10 -> V_67 [ V_4 ] . type = V_73 ;
V_10 -> V_67 [ V_4 ] . V_74 = 1 ;
V_10 -> V_67 [ V_4 ] . V_75 = ( V_51 * 6 ) + V_62 ;
V_10 -> V_67 [ V_4 ] . V_76 =
V_10 -> V_67 [ V_4 ] . V_75 + 1 ;
} else {
V_10 -> V_67 [ V_4 ] . type = V_77 ;
V_10 -> V_67 [ V_4 ] . V_75 = ( V_51 * 6 ) + V_62 - 6 ;
}
V_10 -> V_67 [ V_4 ] . V_78 = 1 ;
V_10 -> V_67 [ V_4 ] . V_79 =
( 1 << V_80 ) ;
V_10 -> V_67 [ V_4 ] . V_60 =
F_19 ( V_51 ) << 8 | V_62 ;
V_10 -> V_67 [ V_4 ] . V_81 = V_4 ;
V_10 -> V_67 [ V_4 ] . V_82 . V_83 = 'u' ;
V_10 -> V_67 [ V_4 ] . V_82 . V_84 = 12 ;
V_10 -> V_67 [ V_4 ] . V_82 . V_85 = 32 ;
V_10 -> V_67 [ V_4 ] . V_82 . V_86 = 0 ;
}
V_10 -> V_67 [ V_4 ] . type = V_73 ;
V_10 -> V_67 [ V_4 ] . V_74 = 1 ;
V_10 -> V_67 [ V_4 ] . V_75 = 0 ;
V_10 -> V_67 [ V_4 ] . V_76 = V_51 * 6 ;
V_10 -> V_67 [ V_4 ] . V_60 = V_87 ;
V_10 -> V_67 [ V_4 ] . V_78 = 1 ;
V_10 -> V_67 [ V_4 ] . V_79 = ( 1 << V_80 ) ;
V_10 -> V_67 [ V_4 ] . V_81 = V_4 ;
V_10 -> V_67 [ V_4 ] . V_82 . V_83 = 'u' ;
V_10 -> V_67 [ V_4 ] . V_82 . V_84 = 32 ;
V_10 -> V_67 [ V_4 ] . V_82 . V_85 = 32 ;
V_10 -> V_67 [ V_4 ] . V_82 . V_86 = 0 ;
V_4 ++ ;
V_10 -> V_67 [ V_4 ] . type = V_88 ;
V_10 -> V_67 [ V_4 ] . V_75 = - 1 ;
V_10 -> V_67 [ V_4 ] . V_81 = V_4 ;
V_10 -> V_67 [ V_4 ] . V_82 . V_83 = 's' ;
V_10 -> V_67 [ V_4 ] . V_82 . V_84 = 64 ;
V_10 -> V_67 [ V_4 ] . V_82 . V_85 = 64 ;
V_10 -> V_67 [ V_4 ] . V_82 . V_86 = 0 ;
return V_4 + 1 ;
}
static int F_33 ( struct V_9 * V_10 )
{
int V_51 , V_62 , V_4 ;
V_10 -> V_89 = F_32 ( sizeof( * V_10 -> V_89 ) * ( V_10 -> V_68 + 1 ) *
V_90 * 2 , V_69 ) ;
if ( V_10 -> V_89 == NULL )
return - V_70 ;
for ( V_51 = 0 , V_4 = 0 ; V_51 <= V_10 -> V_68 ; V_51 ++ )
for ( V_62 = V_40 ; V_62 <= V_41 ;
V_62 ++ , V_4 ++ ) {
V_10 -> V_89 [ V_4 ] . V_60 =
F_19 ( V_51 ) << 8 | V_62 ;
V_10 -> V_89 [ V_4 ] . V_91 . V_53 . V_92 =
V_93 | V_94 ;
V_10 -> V_89 [ V_4 ] . V_91 . V_95 =
F_20 ;
V_10 -> V_89 [ V_4 ] . V_91 . V_96 =
F_24 ;
V_10 -> V_89 [ V_4 ] . V_91 . V_53 . V_97 =
F_34 ( V_69 ,
L_2 ,
( V_51 * V_90 ) + V_62 ,
( V_51 * V_90 ) + V_62 + 1 ) ;
V_98 [ V_4 ] =
& V_10 -> V_89 [ V_4 ] . V_91 . V_53 ;
V_4 ++ ;
V_10 -> V_89 [ V_4 ] . V_60 =
F_19 ( V_51 ) << 8 |
( V_99 + V_62 ) ;
V_10 -> V_89 [ V_4 ] . V_91 . V_53 . V_92 =
V_93 | V_94 ;
V_10 -> V_89 [ V_4 ] . V_91 . V_95 =
F_28 ;
V_10 -> V_89 [ V_4 ] . V_91 . V_96 =
F_29 ;
V_10 -> V_89 [ V_4 ] . V_91 . V_53 . V_97 =
F_34 ( V_69 , L_3 ,
( V_51 * V_90 ) + V_62 ,
( V_51 * V_90 ) + V_62 + 1 ) ;
V_98 [ V_4 ] =
& V_10 -> V_89 [ V_4 ] . V_91 . V_53 ;
}
V_98 [ V_4 ] = NULL ;
return 0 ;
}
static T_1 F_35 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_54 )
{
struct V_55 * V_56 = F_21 ( V_51 ) ;
struct V_9 * V_10 = F_22 ( V_56 ) ;
struct V_57 * V_58 = F_23 ( V_53 ) ;
unsigned V_8 ;
switch ( V_58 -> V_60 ) {
case V_100 :
V_8 = 1000 + ( V_10 -> V_101 * 1568 ) / 100 ;
break;
case V_102 :
V_8 = 1000 + ( V_10 -> V_103 * 1568 ) / 100 ;
break;
case V_104 :
V_8 = ( V_10 -> V_105 * 196 ) / 10 ;
break;
case V_106 :
V_8 = ( V_10 -> V_107 * 196 ) / 10 ;
break;
default:
return - V_66 ;
}
return sprintf ( V_54 , L_1 , V_8 ) ;
}
static T_1 F_36 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_54 ,
T_2 V_21 )
{
struct V_55 * V_56 = F_21 ( V_51 ) ;
struct V_9 * V_10 = F_22 ( V_56 ) ;
struct V_57 * V_58 = F_23 ( V_53 ) ;
long V_8 ;
int V_18 ;
V_18 = F_37 ( V_54 , 10 , & V_8 ) ;
if ( V_18 )
return V_18 ;
switch ( V_58 -> V_60 ) {
case V_100 :
case V_102 :
V_8 = ( ( V_8 - 1000 ) * 100 ) / 1568 ;
break;
case V_104 :
case V_106 :
V_8 = ( V_8 * 10 ) / 196 ;
break;
default:
return - V_36 ;
}
V_8 = F_38 ( V_8 , 0L , 0xFFL ) ;
F_26 ( & V_56 -> V_63 ) ;
switch ( V_58 -> V_60 ) {
case V_100 :
V_10 -> V_101 = V_8 ;
break;
case V_102 :
V_10 -> V_103 = V_8 ;
break;
case V_104 :
V_10 -> V_105 = V_8 ;
break;
case V_106 :
V_10 -> V_107 = V_8 ;
break;
}
V_18 = F_13 ( V_10 , V_29 ,
V_58 -> V_60 , 1 , V_8 ) ;
F_27 ( & V_56 -> V_63 ) ;
return V_18 ? V_18 : V_21 ;
}
static T_3 F_39 ( int V_108 , void * V_109 )
{
struct V_55 * V_56 = V_109 ;
struct V_9 * V_10 = F_22 ( V_56 ) ;
unsigned * V_67 ;
int V_5 , V_18 ;
V_67 = F_32 ( sizeof( * V_67 ) * V_10 -> V_110 , V_69 ) ;
if ( V_67 == NULL )
return V_111 ;
V_18 = F_17 ( V_10 , V_10 -> V_110 , V_67 ) ;
if ( V_18 < 0 )
return V_111 ;
for ( V_5 = 0 ; V_5 < V_10 -> V_110 ; V_5 ++ ) {
if ( ( ( V_67 [ V_5 ] >> 23 ) & 0xF ) <= V_41 ) {
if ( ( ( V_67 [ V_5 ] >> 11 ) & 0xFFF ) >=
V_10 -> V_101 )
F_40 ( V_56 ,
F_41 ( V_73 ,
1 ,
0 ,
V_112 ,
V_113 ,
0 , 0 , 0 ) ,
F_42 () ) ;
else if ( ( ( V_67 [ V_5 ] >> 11 ) & 0xFFF ) <=
V_10 -> V_103 )
F_40 ( V_56 ,
F_41 ( V_73 ,
1 ,
0 ,
V_114 ,
V_113 ,
0 , 0 , 0 ) ,
F_42 () ) ;
} else {
if ( ( ( V_67 [ V_5 ] >> 11 ) & 0xFFF ) >= V_10 -> V_105 )
F_40 ( V_56 ,
F_43 ( V_77 ,
0 ,
V_113 ,
V_112 ) ,
F_42 () ) ;
else if ( ( ( V_67 [ V_5 ] >> 11 ) & 0xFFF ) <=
V_10 -> V_107 )
F_40 ( V_56 ,
F_43 ( V_77 ,
0 ,
V_113 ,
V_114 ) ,
F_42 () ) ;
}
}
F_44 ( V_67 ) ;
return V_111 ;
}
static int F_45 ( struct V_55 * V_56 ,
struct V_115 const * V_116 ,
int * V_8 ,
int * V_117 ,
long V_23 )
{
struct V_9 * V_10 = F_22 ( V_56 ) ;
unsigned int V_118 ;
int V_18 ;
switch ( V_23 ) {
case 0 :
F_26 ( & V_56 -> V_63 ) ;
if ( V_116 -> V_60 == V_87 )
V_18 = F_17 ( V_10 , V_10 -> V_110 , NULL ) ;
else
V_18 = F_16 ( V_10 , V_116 -> V_60 >> 8 ,
V_116 -> V_60 & 0xFF ) ;
F_27 ( & V_56 -> V_63 ) ;
if ( V_18 < 0 )
return V_18 ;
* V_8 = V_18 ;
return V_119 ;
case ( 1 << V_80 ) :
if ( ( V_116 -> V_60 & 0xFF ) <= V_41 )
V_118 = ( 4000 * 1000 ) >> V_120 ;
else
V_118 = ( 5000 * 1000 ) >> V_120 ;
* V_8 = V_118 / 1000 ;
* V_117 = ( V_118 % 1000 ) * 1000 ;
return V_121 ;
}
return - V_66 ;
}
static int T_4 F_46 ( struct V_13 * V_14 )
{
const struct V_122 * V_123 = V_14 -> V_51 . V_124 ;
struct V_9 * V_10 ;
int V_18 ;
const unsigned short V_125 [ 4 ] = { 465 , 1010 , 1460 , 1890 } ;
const unsigned short V_126 [ 4 ] = { 1 , 2 , 4 , 8 } ;
struct V_55 * V_56 = F_47 ( sizeof( * V_10 ) ) ;
if ( V_56 == NULL )
return - V_70 ;
V_10 = F_22 ( V_56 ) ;
F_48 ( V_14 , V_56 ) ;
V_10 -> V_14 = V_14 ;
if ( ! V_123 )
V_123 = & V_127 ;
F_1 ( V_10 -> V_1 ) ;
V_10 -> V_14 -> V_128 = V_129 ;
V_10 -> V_14 -> V_92 = V_130 ;
F_49 ( V_10 -> V_14 ) ;
V_10 -> V_48 = F_50 ( V_123 -> V_131 & 0x3 ) ;
V_10 -> V_33 = F_51 ( V_123 -> V_132
& 0x3 ) | ( V_123 -> V_133 ?
V_134 : 0 ) ;
V_18 = F_18 ( V_10 ) ;
if ( V_18 < 0 )
goto V_135;
V_10 -> V_68 = V_18 ;
V_10 -> V_110 = ( V_10 -> V_68 + 1 ) * V_136 ;
V_10 -> V_101 = 0xFF ;
V_10 -> V_105 = 0xFF ;
V_10 -> V_12 =
( ( V_125 [ V_123 -> V_131 & 0x3 ] + 695 ) *
( V_136 * V_126 [ V_123 -> V_132 & 0x3 ] ) )
- V_125 [ V_123 -> V_131 & 0x3 ] +
V_10 -> V_68 * 250 ;
V_10 -> V_12 = F_52 ( V_10 -> V_12 , 1000 ) ;
V_10 -> V_12 += 5 ;
V_56 -> V_97 = F_53 ( V_14 ) -> V_97 ;
V_56 -> V_51 . V_137 = & V_14 -> V_51 ;
V_56 -> V_138 = V_139 ;
V_18 = F_31 ( V_10 ) ;
if ( V_18 < 0 )
goto V_135;
V_56 -> V_140 = V_18 ;
V_56 -> V_67 = V_10 -> V_67 ;
V_56 -> V_141 = & V_142 ;
V_18 = F_33 ( V_10 ) ;
if ( V_18 < 0 )
goto V_143;
V_18 = F_54 ( V_56 ) ;
if ( V_18 )
goto V_144;
if ( V_14 -> V_108 > 0 ) {
V_18 = F_13 ( V_10 , V_29 ,
V_145 , 1 ,
V_146 ) ;
if ( V_18 )
goto V_147;
V_18 = F_13 ( V_10 , F_19 ( V_10 -> V_68 ) ,
V_145 , 0 ,
V_148 |
( V_123 -> V_149 & 0xF ) ) ;
if ( V_18 )
goto V_147;
V_18 = F_55 ( V_14 -> V_108 ,
NULL ,
F_39 ,
V_150 |
V_151 ,
V_56 -> V_97 ,
V_56 ) ;
if ( V_18 )
goto V_147;
}
return 0 ;
V_147:
F_56 ( V_56 ) ;
V_144:
F_44 ( V_10 -> V_89 ) ;
V_143:
F_44 ( V_10 -> V_67 ) ;
V_135:
F_57 ( V_56 ) ;
return V_18 ;
}
static int T_5 F_58 ( struct V_13 * V_14 )
{
struct V_55 * V_56 = F_59 ( V_14 ) ;
struct V_9 * V_10 = F_22 ( V_56 ) ;
if ( V_14 -> V_108 > 0 )
F_60 ( V_14 -> V_108 , V_56 ) ;
F_56 ( V_56 ) ;
F_13 ( V_10 , V_29 , V_30 , 1 ,
V_152 | V_10 -> V_33 ) ;
F_44 ( V_10 -> V_67 ) ;
F_44 ( V_10 -> V_89 ) ;
F_57 ( V_56 ) ;
return 0 ;
}
static int T_6 F_61 ( void )
{
return F_62 ( & V_153 ) ;
}
static void T_7 F_63 ( void )
{
F_64 ( & V_153 ) ;
}
