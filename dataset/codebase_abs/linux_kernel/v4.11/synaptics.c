static int F_1 ( struct V_1 * V_1 , unsigned char V_2 )
{
unsigned char V_3 [ 1 ] ;
if ( F_2 ( V_1 , V_2 ) )
return - 1 ;
V_3 [ 0 ] = V_4 ;
if ( F_3 ( & V_1 -> V_5 , V_3 , V_6 ) )
return - 1 ;
return 0 ;
}
int F_4 ( struct V_1 * V_1 , bool V_7 )
{
struct V_5 * V_5 = & V_1 -> V_5 ;
unsigned char V_3 [ 4 ] ;
V_3 [ 0 ] = 0 ;
F_3 ( V_5 , V_3 , V_8 ) ;
F_3 ( V_5 , V_3 , V_8 ) ;
F_3 ( V_5 , V_3 , V_8 ) ;
F_3 ( V_5 , V_3 , V_8 ) ;
F_3 ( V_5 , V_3 , V_9 ) ;
if ( V_3 [ 1 ] != 0x47 )
return - V_10 ;
if ( V_7 ) {
V_1 -> V_11 = L_1 ;
V_1 -> V_12 = L_2 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0 ) ;
}
static int F_6 ( int V_13 )
{
return V_14 + V_15 - V_13 ;
}
static int F_7 ( struct V_1 * V_1 , unsigned char V_16 , unsigned char * V_3 )
{
if ( F_2 ( V_1 , V_16 ) )
return - 1 ;
if ( F_3 ( & V_1 -> V_5 , V_3 , V_9 ) )
return - 1 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_20 [ 3 ] ;
if ( F_7 ( V_1 , V_21 , V_20 ) )
return - 1 ;
V_18 -> V_22 = ( V_20 [ 0 ] << 16 ) | ( V_20 [ 1 ] << 8 ) | V_20 [ 2 ] ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_23 [ 3 ] ;
if ( F_7 ( V_1 , V_24 , V_23 ) )
return - 1 ;
V_18 -> V_25 = ( V_23 [ 0 ] << 16 ) | ( V_23 [ 1 ] << 8 ) | V_23 [ 2 ] ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_26 [ 3 ] ;
if ( F_11 ( V_18 -> V_27 ) < 0x705 )
return 0 ;
if ( F_7 ( V_1 , V_28 , V_26 ) )
return - 1 ;
V_18 -> V_29 = ( ( V_26 [ 0 ] & 0xfc ) << 6 ) | V_26 [ 1 ] ;
if ( F_12 ( V_26 [ 0 ] ) )
return F_9 ( V_1 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_30 [ 3 ] ;
if ( F_7 ( V_1 , V_31 , V_30 ) )
return - 1 ;
V_18 -> V_32 = ( V_30 [ 0 ] << 16 ) | ( V_30 [ 1 ] << 8 ) | V_30 [ 2 ] ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_33 [ 3 ] ;
if ( F_7 ( V_1 , V_34 , V_33 ) )
return - 1 ;
V_18 -> V_35 = ( V_33 [ 0 ] << 16 ) | ( V_33 [ 1 ] << 8 ) | V_33 [ 2 ] ;
V_18 -> V_36 = V_18 -> V_37 = 0 ;
if ( F_11 ( V_18 -> V_27 ) < 0x705 &&
F_15 ( V_18 -> V_35 ) != 0x47 ) {
return - 1 ;
}
if ( ! F_16 ( V_18 -> V_35 ) )
V_18 -> V_35 = 0 ;
if ( F_17 ( V_18 -> V_35 ) >= 1 ) {
if ( F_7 ( V_1 , V_38 , V_33 ) ) {
F_18 ( V_1 ,
L_3 ) ;
} else {
V_18 -> V_36 = ( V_33 [ 0 ] << 16 ) | ( V_33 [ 1 ] << 8 ) | V_33 [ 2 ] ;
if ( F_19 ( V_18 -> V_36 ) > 8 )
V_18 -> V_36 &= 0xff0fff ;
}
}
if ( F_17 ( V_18 -> V_35 ) >= 4 ) {
if ( F_7 ( V_1 , V_39 , V_33 ) ) {
F_18 ( V_1 ,
L_4 ) ;
} else {
V_18 -> V_37 = ( V_33 [ 0 ] << 16 ) | ( V_33 [ 1 ] << 8 ) | V_33 [ 2 ] ;
}
}
return 0 ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_40 [ 3 ] ;
if ( F_7 ( V_1 , V_41 , V_40 ) )
return - 1 ;
V_18 -> V_27 = ( V_40 [ 0 ] << 16 ) | ( V_40 [ 1 ] << 8 ) | V_40 [ 2 ] ;
if ( F_21 ( V_18 -> V_27 ) )
return 0 ;
return - 1 ;
}
static int F_22 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_42 [ 3 ] ;
if ( F_23 ( V_18 -> V_27 ) < 4 )
return 0 ;
if ( F_7 ( V_1 , V_43 , V_42 ) == 0 ) {
if ( V_42 [ 0 ] != 0 && ( V_42 [ 1 ] & 0x80 ) && V_42 [ 2 ] != 0 ) {
V_18 -> V_44 = V_42 [ 0 ] ;
V_18 -> V_45 = V_42 [ 2 ] ;
}
}
if ( F_17 ( V_18 -> V_35 ) >= 5 &&
F_24 ( V_18 -> V_37 ) ) {
if ( F_7 ( V_1 , V_46 , V_42 ) ) {
F_18 ( V_1 ,
L_5 ) ;
} else {
V_18 -> V_47 = ( V_42 [ 0 ] << 5 ) | ( ( V_42 [ 1 ] & 0x0f ) << 1 ) ;
V_18 -> V_48 = ( V_42 [ 2 ] << 5 ) | ( ( V_42 [ 1 ] & 0xf0 ) >> 3 ) ;
F_25 ( V_1 ,
L_6 ,
V_18 -> V_47 , V_18 -> V_48 ) ;
}
}
if ( F_26 ( V_18 -> V_37 ) &&
( F_17 ( V_18 -> V_35 ) >= 7 ||
F_11 ( V_18 -> V_27 ) == 0x801 ) ) {
if ( F_7 ( V_1 , V_49 , V_42 ) ) {
F_18 ( V_1 ,
L_7 ) ;
} else {
V_18 -> V_50 = ( V_42 [ 0 ] << 5 ) | ( ( V_42 [ 1 ] & 0x0f ) << 1 ) ;
V_18 -> V_51 = ( V_42 [ 2 ] << 5 ) | ( ( V_42 [ 1 ] & 0xf0 ) >> 3 ) ;
F_25 ( V_1 ,
L_8 ,
V_18 -> V_50 , V_18 -> V_51 ) ;
}
}
return 0 ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
int V_52 ;
for ( V_52 = 0 ; V_53 [ V_52 ] . V_54 ; V_52 ++ ) {
if ( ! F_28 ( V_1 ,
V_53 [ V_52 ] . V_54 ) )
continue;
if ( V_53 [ V_52 ] . V_29 . V_55 != V_56 &&
V_18 -> V_29 < V_53 [ V_52 ] . V_29 . V_55 )
continue;
if ( V_53 [ V_52 ] . V_29 . V_57 != V_56 &&
V_18 -> V_29 > V_53 [ V_52 ] . V_29 . V_57 )
continue;
V_18 -> V_50 = V_53 [ V_52 ] . V_50 ;
V_18 -> V_47 = V_53 [ V_52 ] . V_47 ;
V_18 -> V_51 = V_53 [ V_52 ] . V_51 ;
V_18 -> V_48 = V_53 [ V_52 ] . V_48 ;
F_25 ( V_1 ,
L_9 ,
V_18 -> V_50 , V_18 -> V_47 ,
V_18 -> V_51 , V_18 -> V_48 ) ;
break;
}
}
static int F_29 ( struct V_1 * V_1 )
{
if ( F_20 ( V_1 ) )
return - 1 ;
if ( F_8 ( V_1 ) )
return - 1 ;
if ( F_13 ( V_1 ) )
return - 1 ;
if ( F_10 ( V_1 ) )
return - 1 ;
if ( F_14 ( V_1 ) )
return - 1 ;
if ( F_22 ( V_1 ) )
return - 1 ;
F_27 ( V_1 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 )
{
static unsigned char V_3 = 0xc8 ;
struct V_17 * V_18 = V_1 -> V_19 ;
if ( ! ( F_31 ( V_18 -> V_37 ) ||
F_32 ( V_18 -> V_37 ) ) )
return 0 ;
if ( F_2 ( V_1 , V_21 ) )
return - 1 ;
if ( F_3 ( & V_1 -> V_5 , & V_3 , V_6 ) )
return - 1 ;
V_18 -> V_35 |= F_33 ( 1 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
V_18 -> V_2 = 0 ;
if ( V_18 -> V_58 )
V_18 -> V_2 |= V_59 ;
if ( V_18 -> V_60 )
V_18 -> V_2 |= V_61 ;
if ( V_1 -> V_62 >= 80 )
V_18 -> V_2 |= V_63 ;
if ( F_16 ( V_18 -> V_35 ) )
V_18 -> V_2 |= V_64 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
return - 1 ;
if ( V_18 -> V_58 &&
F_30 ( V_1 ) ) {
F_35 ( V_1 , L_10 ) ;
return - 1 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_1 , unsigned int V_62 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( V_62 >= 80 ) {
V_18 -> V_2 |= V_63 ;
V_1 -> V_62 = 80 ;
} else {
V_18 -> V_2 &= ~ V_63 ;
V_1 -> V_62 = 40 ;
}
F_1 ( V_1 , V_18 -> V_2 ) ;
}
static int F_37 ( struct V_65 * V_65 , unsigned char V_16 )
{
struct V_1 * V_66 = F_38 ( V_65 -> V_66 ) ;
char V_67 = V_68 ;
if ( F_2 ( V_66 , V_16 ) )
return - 1 ;
if ( F_3 ( & V_66 -> V_5 , & V_67 , V_6 ) )
return - 1 ;
return 0 ;
}
static int F_39 ( struct V_65 * V_65 )
{
struct V_1 * V_66 = F_38 ( V_65 -> V_66 ) ;
struct V_17 * V_18 = V_66 -> V_19 ;
F_40 ( V_66 -> V_5 . V_65 ) ;
V_18 -> V_69 = V_65 ;
F_41 ( V_66 -> V_5 . V_65 ) ;
return 0 ;
}
static void F_42 ( struct V_65 * V_65 )
{
struct V_1 * V_66 = F_38 ( V_65 -> V_66 ) ;
struct V_17 * V_18 = V_66 -> V_19 ;
F_40 ( V_66 -> V_5 . V_65 ) ;
V_18 -> V_69 = NULL ;
F_41 ( V_66 -> V_5 . V_65 ) ;
}
static int F_43 ( unsigned char * V_23 )
{
return ( V_23 [ 0 ] & 0xFC ) == 0x84 && ( V_23 [ 3 ] & 0xCC ) == 0xC4 ;
}
static void F_44 ( struct V_65 * V_70 ,
unsigned char * V_71 )
{
struct V_1 * V_72 = F_38 ( V_70 ) ;
if ( V_72 && V_72 -> V_73 == V_74 ) {
F_45 ( V_70 , V_71 [ 1 ] , 0 ) ;
F_45 ( V_70 , V_71 [ 4 ] , 0 ) ;
F_45 ( V_70 , V_71 [ 5 ] , 0 ) ;
if ( V_72 -> V_75 == 4 )
F_45 ( V_70 , V_71 [ 2 ] , 0 ) ;
} else {
F_45 ( V_70 , V_71 [ 1 ] , 0 ) ;
}
}
static void F_46 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_1 * V_72 = F_38 ( V_18 -> V_69 ) ;
if ( V_72 ) {
if ( V_72 -> V_75 == 4 )
V_18 -> V_2 |= V_76 ;
else
V_18 -> V_2 &= ~ V_76 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
F_18 ( V_1 ,
L_11 ) ;
}
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_65 * V_65 ;
V_65 = F_48 ( sizeof( struct V_65 ) , V_77 ) ;
if ( ! V_65 ) {
F_35 ( V_1 ,
L_12 ) ;
return;
}
V_65 -> V_40 . type = V_78 ;
F_49 ( V_65 -> V_12 , L_13 , sizeof( V_65 -> V_12 ) ) ;
F_49 ( V_65 -> V_79 , L_14 , sizeof( V_65 -> V_12 ) ) ;
V_65 -> V_80 = F_37 ;
V_65 -> V_81 = F_39 ;
V_65 -> V_82 = F_42 ;
V_65 -> V_66 = V_1 -> V_5 . V_65 ;
V_1 -> V_83 = F_46 ;
F_25 ( V_1 , L_15 ,
V_65 -> V_12 , V_1 -> V_79 ) ;
F_50 ( V_65 ) ;
}
static void F_51 ( const unsigned char V_23 [] ,
struct V_17 * V_18 ,
struct V_84 * V_85 )
{
struct V_84 * V_86 = & V_18 -> V_86 ;
int V_87 ;
V_87 = ( V_23 [ 5 ] & 0x30 ) >> 4 ;
switch ( V_87 ) {
case 1 :
V_86 -> V_88 = V_85 -> V_88 ;
V_86 -> V_89 = ( ( ( V_23 [ 4 ] & 0x0f ) << 8 ) | V_23 [ 1 ] ) << 1 ;
V_86 -> V_13 = ( ( ( V_23 [ 4 ] & 0xf0 ) << 4 ) | V_23 [ 2 ] ) << 1 ;
V_86 -> V_90 = ( ( V_23 [ 3 ] & 0x30 ) | ( V_23 [ 5 ] & 0x0f ) ) << 1 ;
break;
case 2 :
V_18 -> V_91 = V_23 [ 1 ] ;
break;
default:
break;
}
}
static void F_52 ( const unsigned char V_23 [] ,
struct V_17 * V_18 ,
struct V_84 * V_85 )
{
unsigned int V_92 =
( F_19 ( V_18 -> V_36 ) + 1 ) >> 1 ;
unsigned int V_93 = F_53 ( V_92 - 1 , 0 ) ;
V_85 -> V_94 = V_23 [ 4 ] & V_93 ;
V_85 -> V_94 |= ( V_23 [ 5 ] & V_93 ) << V_92 ;
}
static int F_54 ( const unsigned char V_23 [] ,
struct V_17 * V_18 ,
struct V_84 * V_85 )
{
memset ( V_85 , 0 , sizeof( struct V_84 ) ) ;
if ( F_55 ( V_18 -> V_22 ) ) {
V_85 -> V_88 = ( ( ( V_23 [ 0 ] & 0x30 ) >> 2 ) |
( ( V_23 [ 0 ] & 0x04 ) >> 1 ) |
( ( V_23 [ 3 ] & 0x04 ) >> 2 ) ) ;
if ( ( F_31 ( V_18 -> V_37 ) ||
F_32 ( V_18 -> V_37 ) ) &&
V_85 -> V_88 == 2 ) {
F_51 ( V_23 , V_18 , V_85 ) ;
return 1 ;
}
V_85 -> V_89 = ( ( ( V_23 [ 3 ] & 0x10 ) << 8 ) |
( ( V_23 [ 1 ] & 0x0f ) << 8 ) |
V_23 [ 4 ] ) ;
V_85 -> V_13 = ( ( ( V_23 [ 3 ] & 0x20 ) << 7 ) |
( ( V_23 [ 1 ] & 0xf0 ) << 4 ) |
V_23 [ 5 ] ) ;
V_85 -> V_90 = V_23 [ 2 ] ;
V_85 -> V_95 = ( V_23 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_85 -> V_96 = ( V_23 [ 0 ] & 0x02 ) ? 1 : 0 ;
if ( V_18 -> V_97 ) {
if ( V_85 -> V_90 == 0 ) {
V_18 -> V_98 = V_18 -> V_99 = false ;
} else if ( V_85 -> V_88 >= 4 && ( ( V_23 [ 0 ] ^ V_23 [ 3 ] ) & 0x01 ) ) {
if ( ! V_18 -> V_98 ) {
V_18 -> V_100 = V_101 ;
V_18 -> V_98 = true ;
} else if ( F_56 ( V_101 ,
V_18 -> V_100 +
F_57 ( 50 ) ) ) {
V_18 -> V_99 = true ;
}
} else {
V_18 -> V_98 = false ;
}
V_85 -> V_95 = V_18 -> V_99 ;
} else if ( F_58 ( V_18 -> V_37 ) ) {
V_85 -> V_95 = ( ( V_23 [ 0 ] ^ V_23 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
} else if ( F_59 ( V_18 -> V_35 ) ) {
V_85 -> V_102 = ( ( V_23 [ 0 ] ^ V_23 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
if ( V_85 -> V_88 == 2 )
V_85 -> V_103 = ( signed char ) ( V_23 [ 1 ] ) ;
}
if ( F_60 ( V_18 -> V_35 ) ) {
V_85 -> V_104 = ( ( V_23 [ 0 ] ^ V_23 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
V_85 -> V_105 = ( ( V_23 [ 0 ] ^ V_23 [ 3 ] ) & 0x02 ) ? 1 : 0 ;
}
if ( F_19 ( V_18 -> V_36 ) > 0 &&
( ( V_23 [ 0 ] ^ V_23 [ 3 ] ) & 0x02 ) ) {
F_52 ( V_23 , V_18 , V_85 ) ;
}
} else {
V_85 -> V_89 = ( ( ( V_23 [ 1 ] & 0x1f ) << 8 ) | V_23 [ 2 ] ) ;
V_85 -> V_13 = ( ( ( V_23 [ 4 ] & 0x1f ) << 8 ) | V_23 [ 5 ] ) ;
V_85 -> V_90 = ( ( ( V_23 [ 0 ] & 0x30 ) << 2 ) | ( V_23 [ 3 ] & 0x3F ) ) ;
V_85 -> V_88 = ( ( ( V_23 [ 1 ] & 0x80 ) >> 4 ) | ( ( V_23 [ 0 ] & 0x04 ) >> 1 ) ) ;
V_85 -> V_95 = ( V_23 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_85 -> V_96 = ( V_23 [ 0 ] & 0x02 ) ? 1 : 0 ;
}
if ( V_85 -> V_89 > V_106 )
V_85 -> V_89 -= 1 << V_107 ;
else if ( V_85 -> V_89 == V_106 )
V_85 -> V_89 = V_108 ;
if ( V_85 -> V_13 > V_109 )
V_85 -> V_13 -= 1 << V_107 ;
else if ( V_85 -> V_13 == V_109 )
V_85 -> V_13 = V_110 ;
return 0 ;
}
static void F_61 ( struct V_111 * V_112 , int V_113 ,
bool V_114 , int V_89 , int V_13 )
{
F_62 ( V_112 , V_113 ) ;
F_63 ( V_112 , V_115 , V_114 ) ;
if ( V_114 ) {
F_64 ( V_112 , V_116 , V_89 ) ;
F_64 ( V_112 , V_117 , F_6 ( V_13 ) ) ;
}
}
static void F_65 ( struct V_111 * V_112 ,
const struct V_84 * V_118 ,
const struct V_84 * V_119 ,
int V_120 )
{
if ( V_120 >= 2 ) {
F_61 ( V_112 , 0 , true , V_55 ( V_118 -> V_89 , V_119 -> V_89 ) ,
V_55 ( V_118 -> V_13 , V_119 -> V_13 ) ) ;
F_61 ( V_112 , 1 , true , V_57 ( V_118 -> V_89 , V_119 -> V_89 ) ,
V_57 ( V_118 -> V_13 , V_119 -> V_13 ) ) ;
} else if ( V_120 == 1 ) {
F_61 ( V_112 , 0 , true , V_118 -> V_89 , V_118 -> V_13 ) ;
F_61 ( V_112 , 1 , false , 0 , 0 ) ;
} else {
F_61 ( V_112 , 0 , false , 0 , 0 ) ;
F_61 ( V_112 , 1 , false , 0 , 0 ) ;
}
}
static void F_66 ( struct V_1 * V_1 ,
const struct V_84 * V_85 )
{
struct V_111 * V_112 = V_1 -> V_112 ;
struct V_17 * V_18 = V_1 -> V_19 ;
int V_92 = ( F_19 ( V_18 -> V_36 ) + 1 ) >> 1 ;
int V_52 ;
if ( ! F_19 ( V_18 -> V_36 ) )
return;
if ( ( F_11 ( V_18 -> V_27 ) == 0x801 ||
F_11 ( V_18 -> V_27 ) == 0x802 ) &&
! ( ( V_1 -> V_71 [ 0 ] ^ V_1 -> V_71 [ 3 ] ) & 0x02 ) )
return;
if ( ! F_67 ( V_18 -> V_25 ) ) {
for ( V_52 = 0 ; V_52 < V_92 ; V_52 ++ ) {
F_68 ( V_112 , V_121 + 2 * V_52 ,
V_85 -> V_94 & ( 1 << V_52 ) ) ;
F_68 ( V_112 , V_122 + 2 * V_52 ,
V_85 -> V_94 & ( 1 << ( V_52 + V_92 ) ) ) ;
}
return;
}
if ( V_18 -> V_69 ) {
T_1 V_123 ;
V_123 = F_69 ( V_85 -> V_94 ) |
F_70 ( V_85 -> V_94 ) << 1 |
F_71 ( V_85 -> V_94 ) << 2 ;
F_45 ( V_18 -> V_69 ,
V_124 , V_125 ) ;
F_45 ( V_18 -> V_69 , V_123 , V_125 ) ;
}
}
static void F_72 ( struct V_1 * V_1 ,
const struct V_84 * V_85 )
{
struct V_111 * V_112 = V_1 -> V_112 ;
struct V_17 * V_18 = V_1 -> V_19 ;
F_68 ( V_112 , V_126 , V_85 -> V_95 ) ;
F_68 ( V_112 , V_127 , V_85 -> V_96 ) ;
if ( F_59 ( V_18 -> V_35 ) )
F_68 ( V_112 , V_128 , V_85 -> V_102 ) ;
if ( F_60 ( V_18 -> V_35 ) ) {
F_68 ( V_112 , V_129 , V_85 -> V_104 ) ;
F_68 ( V_112 , V_130 , V_85 -> V_105 ) ;
}
F_66 ( V_1 , V_85 ) ;
}
static void F_73 ( struct V_1 * V_1 ,
const struct V_84 * V_131 ,
int V_120 )
{
struct V_111 * V_112 = V_1 -> V_112 ;
struct V_17 * V_18 = V_1 -> V_19 ;
const struct V_84 * V_85 [ 2 ] = { V_131 , & V_18 -> V_86 } ;
struct V_132 V_133 [ 2 ] ;
int V_113 [ 2 ] , V_134 , V_52 ;
V_134 = F_74 ( V_120 , 0 , 2 ) ;
for ( V_52 = 0 ; V_52 < V_134 ; V_52 ++ ) {
V_133 [ V_52 ] . V_89 = V_85 [ V_52 ] -> V_89 ;
V_133 [ V_52 ] . V_13 = F_6 ( V_85 [ V_52 ] -> V_13 ) ;
}
F_75 ( V_112 , V_113 , V_133 , V_134 , V_135 * V_18 -> V_44 ) ;
for ( V_52 = 0 ; V_52 < V_134 ; V_52 ++ ) {
F_62 ( V_112 , V_113 [ V_52 ] ) ;
F_63 ( V_112 , V_115 , true ) ;
F_64 ( V_112 , V_116 , V_133 [ V_52 ] . V_89 ) ;
F_64 ( V_112 , V_117 , V_133 [ V_52 ] . V_13 ) ;
F_64 ( V_112 , V_136 , V_85 [ V_52 ] -> V_90 ) ;
}
F_76 ( V_112 ) ;
F_77 ( V_112 , false ) ;
F_78 ( V_112 , V_120 ) ;
F_72 ( V_1 , V_131 ) ;
F_79 ( V_112 ) ;
}
static void F_80 ( struct V_1 * V_1 ,
struct V_84 * V_131 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
int V_120 ;
if ( V_131 -> V_90 == 0 )
V_120 = 0 ;
else if ( V_131 -> V_88 >= 4 )
V_120 = 1 ;
else if ( V_131 -> V_88 == 0 )
V_120 = 2 ;
else if ( V_131 -> V_88 == 1 )
V_120 = V_18 -> V_91 ? V_18 -> V_91 : 3 ;
else
V_120 = 4 ;
F_73 ( V_1 , V_131 , V_120 ) ;
}
static void F_81 ( struct V_1 * V_1 )
{
struct V_111 * V_112 = V_1 -> V_112 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_84 V_85 ;
int V_120 ;
int V_137 ;
if ( F_54 ( V_1 -> V_71 , V_18 , & V_85 ) )
return;
if ( F_32 ( V_18 -> V_37 ) ) {
F_80 ( V_1 , & V_85 ) ;
return;
}
if ( V_85 . V_103 ) {
V_18 -> V_103 += V_85 . V_103 ;
while ( V_18 -> V_103 >= 4 ) {
F_68 ( V_112 , V_130 , ! V_85 . V_105 ) ;
F_79 ( V_112 ) ;
F_68 ( V_112 , V_130 , V_85 . V_105 ) ;
F_79 ( V_112 ) ;
V_18 -> V_103 -= 4 ;
}
while ( V_18 -> V_103 <= - 4 ) {
F_68 ( V_112 , V_129 , ! V_85 . V_104 ) ;
F_79 ( V_112 ) ;
F_68 ( V_112 , V_129 , V_85 . V_104 ) ;
F_79 ( V_112 ) ;
V_18 -> V_103 += 4 ;
}
return;
}
if ( V_85 . V_90 > 0 && V_85 . V_89 > 1 ) {
V_120 = 1 ;
V_137 = 5 ;
if ( F_16 ( V_18 -> V_35 ) ) {
switch ( V_85 . V_88 ) {
case 0 ... 1 :
if ( F_82 ( V_18 -> V_35 ) )
V_120 = V_85 . V_88 + 2 ;
break;
case 2 :
if ( F_83 ( V_18 -> V_22 ) )
;
break;
case 4 ... 15 :
if ( F_84 ( V_18 -> V_35 ) )
V_137 = V_85 . V_88 ;
break;
}
}
} else {
V_120 = 0 ;
V_137 = 0 ;
}
if ( V_138 ) {
F_73 ( V_1 , & V_85 , V_120 ) ;
return;
}
if ( F_31 ( V_18 -> V_37 ) )
F_65 ( V_112 , & V_85 , & V_18 -> V_86 ,
V_120 ) ;
if ( V_85 . V_90 > 30 ) F_68 ( V_112 , V_139 , 1 ) ;
if ( V_85 . V_90 < 25 ) F_68 ( V_112 , V_139 , 0 ) ;
if ( V_120 > 0 ) {
F_64 ( V_112 , V_140 , V_85 . V_89 ) ;
F_64 ( V_112 , V_141 , F_6 ( V_85 . V_13 ) ) ;
}
F_64 ( V_112 , V_142 , V_85 . V_90 ) ;
if ( F_84 ( V_18 -> V_35 ) )
F_64 ( V_112 , V_143 , V_137 ) ;
F_68 ( V_112 , V_144 , V_120 == 1 ) ;
if ( F_82 ( V_18 -> V_35 ) ) {
F_68 ( V_112 , V_145 , V_120 == 2 ) ;
F_68 ( V_112 , V_146 , V_120 == 3 ) ;
}
F_72 ( V_1 , & V_85 ) ;
F_79 ( V_112 ) ;
}
static int F_85 ( struct V_1 * V_1 ,
int V_147 , unsigned char V_148 )
{
static const unsigned char V_149 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const unsigned char V_150 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_151 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_152 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const unsigned char V_153 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
const char * V_71 = V_1 -> V_71 ;
if ( V_147 < 0 || V_147 > 4 )
return 0 ;
switch ( V_148 ) {
case V_154 :
case V_155 :
return ( V_71 [ V_147 ] & V_150 [ V_147 ] ) == V_151 [ V_147 ] ;
case V_156 :
return ( V_71 [ V_147 ] & V_149 [ V_147 ] ) == V_151 [ V_147 ] ;
case V_157 :
return ( V_71 [ V_147 ] & V_152 [ V_147 ] ) == V_153 [ V_147 ] ;
default:
F_35 ( V_1 , L_16 , V_148 ) ;
return 0 ;
}
}
static unsigned char F_86 ( struct V_1 * V_1 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < 5 ; V_52 ++ )
if ( ! F_85 ( V_1 , V_52 , V_156 ) ) {
F_25 ( V_1 , L_17 ) ;
return V_155 ;
}
return V_156 ;
}
static T_2 F_87 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( V_1 -> V_158 >= 6 ) {
if ( F_88 ( V_18 -> V_148 == V_154 ) )
V_18 -> V_148 = F_86 ( V_1 ) ;
if ( F_89 ( V_18 -> V_35 ) &&
F_43 ( V_1 -> V_71 ) ) {
if ( V_18 -> V_69 )
F_44 ( V_18 -> V_69 ,
V_1 -> V_71 ) ;
} else
F_81 ( V_1 ) ;
return V_159 ;
}
return F_85 ( V_1 , V_1 -> V_158 - 1 , V_18 -> V_148 ) ?
V_160 : V_161 ;
}
static void F_90 ( struct V_111 * V_112 ,
struct V_17 * V_18 , int V_162 ,
int V_163 )
{
int V_50 = V_18 -> V_50 ? : V_164 ;
int V_47 = V_18 -> V_47 ? : V_165 ;
int V_51 = V_18 -> V_51 ? : V_15 ;
int V_48 = V_18 -> V_48 ? : V_14 ;
int V_166 = F_91 ( V_18 -> V_37 ) ?
V_167 : 0 ;
F_92 ( V_112 , V_162 , V_50 , V_47 , V_166 , 0 ) ;
F_92 ( V_112 , V_163 , V_51 , V_48 , V_166 , 0 ) ;
F_93 ( V_112 , V_162 , V_18 -> V_44 ) ;
F_93 ( V_112 , V_163 , V_18 -> V_45 ) ;
}
static void F_94 ( struct V_1 * V_1 ,
struct V_17 * V_18 )
{
struct V_111 * V_112 = V_1 -> V_112 ;
int V_52 ;
F_95 ( V_168 , V_112 -> V_169 ) ;
F_95 ( V_170 , V_112 -> V_171 ) ;
F_95 ( V_126 , V_112 -> V_172 ) ;
F_95 ( V_127 , V_112 -> V_172 ) ;
if ( F_59 ( V_18 -> V_35 ) )
F_95 ( V_128 , V_112 -> V_172 ) ;
if ( ! V_18 -> V_58 ) {
F_95 ( V_173 , V_112 -> V_171 ) ;
F_95 ( V_174 , V_112 -> V_175 ) ;
F_95 ( V_176 , V_112 -> V_175 ) ;
return;
}
F_95 ( V_177 , V_112 -> V_171 ) ;
F_90 ( V_112 , V_18 , V_140 , V_141 ) ;
F_92 ( V_112 , V_142 , 0 , 255 , 0 , 0 ) ;
if ( V_138 )
F_92 ( V_112 , V_136 , 0 , 255 , 0 , 0 ) ;
if ( F_32 ( V_18 -> V_37 ) ) {
F_90 ( V_112 , V_18 , V_116 ,
V_117 ) ;
F_92 ( V_112 , V_136 , 0 , 255 , 0 , 0 ) ;
F_96 ( V_112 , 2 , V_178 | V_179 ) ;
F_95 ( V_180 , V_112 -> V_172 ) ;
F_95 ( V_181 , V_112 -> V_172 ) ;
} else if ( F_31 ( V_18 -> V_37 ) ) {
F_90 ( V_112 , V_18 , V_116 ,
V_117 ) ;
F_96 ( V_112 , 2 ,
V_178 |
( V_138 ?
V_179 : V_182 ) ) ;
}
if ( F_84 ( V_18 -> V_35 ) )
F_92 ( V_112 , V_143 , 0 , 15 , 0 , 0 ) ;
F_95 ( V_139 , V_112 -> V_172 ) ;
F_95 ( V_144 , V_112 -> V_172 ) ;
if ( F_82 ( V_18 -> V_35 ) ) {
F_95 ( V_145 , V_112 -> V_172 ) ;
F_95 ( V_146 , V_112 -> V_172 ) ;
}
if ( F_60 ( V_18 -> V_35 ) ||
F_59 ( V_18 -> V_35 ) ) {
F_95 ( V_129 , V_112 -> V_172 ) ;
F_95 ( V_130 , V_112 -> V_172 ) ;
}
if ( ! F_67 ( V_18 -> V_25 ) )
for ( V_52 = 0 ; V_52 < F_19 ( V_18 -> V_36 ) ; V_52 ++ )
F_95 ( V_121 + V_52 , V_112 -> V_172 ) ;
F_97 ( V_173 , V_112 -> V_171 ) ;
F_97 ( V_174 , V_112 -> V_175 ) ;
F_97 ( V_176 , V_112 -> V_175 ) ;
if ( F_58 ( V_18 -> V_37 ) ) {
F_95 ( V_183 , V_112 -> V_169 ) ;
if ( F_28 ( V_1 , V_184 ) &&
! F_67 ( V_18 -> V_25 ) )
F_95 ( V_185 , V_112 -> V_169 ) ;
F_97 ( V_127 , V_112 -> V_172 ) ;
F_97 ( V_128 , V_112 -> V_172 ) ;
}
}
static T_3 F_98 ( struct V_1 * V_1 ,
void * V_186 , char * V_23 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
return sprintf ( V_23 , L_18 , V_18 -> V_60 ? '1' : '0' ) ;
}
static T_3 F_99 ( struct V_1 * V_1 ,
void * V_186 , const char * V_23 ,
T_4 V_187 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned int V_188 ;
int V_189 ;
V_189 = F_100 ( V_23 , 10 , & V_188 ) ;
if ( V_189 )
return V_189 ;
if ( V_188 > 1 )
return - V_190 ;
if ( V_188 == V_18 -> V_60 )
return V_187 ;
V_18 -> V_60 = V_188 ;
if ( V_188 )
V_18 -> V_2 |= V_61 ;
else
V_18 -> V_2 &= ~ V_61 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
return - V_191 ;
return V_187 ;
}
static void F_101 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( ! V_18 -> V_58 && F_102 ( V_18 -> V_27 ) )
F_103 ( & V_1 -> V_5 . V_65 -> V_112 ,
& V_192 . V_193 ) ;
F_5 ( V_1 ) ;
F_104 ( V_18 ) ;
V_1 -> V_19 = NULL ;
}
static int F_105 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_17 V_194 = * V_18 ;
unsigned char V_3 [ 2 ] ;
int V_195 = 0 ;
int error ;
do {
F_106 ( V_1 ) ;
if ( V_195 ) {
F_107 ( 1 ) ;
}
F_3 ( & V_1 -> V_5 , V_3 , V_196 ) ;
error = F_4 ( V_1 , 0 ) ;
} while ( error && ++ V_195 < 3 );
if ( error )
return - 1 ;
if ( V_195 > 1 )
F_108 ( V_1 , L_19 , V_195 ) ;
if ( F_29 ( V_1 ) ) {
F_35 ( V_1 , L_20 ) ;
return - 1 ;
}
if ( F_34 ( V_1 ) ) {
F_35 ( V_1 , L_21 ) ;
return - 1 ;
}
if ( V_194 . V_27 != V_18 -> V_27 ||
V_194 . V_22 != V_18 -> V_22 ||
V_194 . V_35 != V_18 -> V_35 ||
V_194 . V_36 != V_18 -> V_36 ) {
F_35 ( V_1 ,
L_22 ,
V_194 . V_27 , V_18 -> V_27 ,
V_194 . V_22 , V_18 -> V_22 ,
V_194 . V_35 , V_18 -> V_35 ,
V_194 . V_36 , V_18 -> V_36 ) ;
return - 1 ;
}
return 0 ;
}
void T_5 F_109 ( void )
{
V_197 = F_110 ( V_198 ) ;
V_199 = F_110 ( V_200 ) ;
V_138 = F_110 ( V_201 ) ;
}
static int F_111 ( struct V_1 * V_1 , bool V_58 )
{
struct V_17 * V_18 ;
int V_189 = - 1 ;
if ( V_58 && V_199 ) {
F_25 ( V_1 ,
L_23 ) ;
return - V_10 ;
}
V_1 -> V_19 = V_18 = F_48 ( sizeof( struct V_17 ) , V_77 ) ;
if ( ! V_18 )
return - V_202 ;
F_106 ( V_1 ) ;
if ( F_29 ( V_1 ) ) {
F_35 ( V_1 , L_20 ) ;
goto V_203;
}
V_18 -> V_58 = V_58 ;
if ( F_102 ( V_18 -> V_27 ) )
V_18 -> V_60 = true ;
V_18 -> V_97 = F_28 ( V_1 , V_204 ) ;
if ( F_34 ( V_1 ) ) {
F_35 ( V_1 , L_21 ) ;
goto V_203;
}
V_18 -> V_148 = F_55 ( V_18 -> V_22 ) ? V_154 : V_157 ;
F_25 ( V_1 ,
L_24 ,
F_112 ( V_18 -> V_27 ) ,
F_23 ( V_18 -> V_27 ) , F_113 ( V_18 -> V_27 ) ,
V_18 -> V_22 ,
V_18 -> V_35 , V_18 -> V_36 , V_18 -> V_37 ,
V_18 -> V_25 , V_18 -> V_29 , V_18 -> V_32 ) ;
F_94 ( V_1 , V_18 ) ;
V_1 -> V_205 = ( ( V_18 -> V_22 & 0x00ff0000 ) >> 8 ) |
( V_18 -> V_22 & 0x000000ff ) ;
if ( V_58 ) {
V_1 -> V_206 = F_87 ;
V_1 -> V_75 = 6 ;
} else {
V_1 -> V_206 = V_207 ;
V_1 -> V_75 = 3 ;
}
V_1 -> V_208 = F_36 ;
V_1 -> V_209 = F_101 ;
V_1 -> V_210 = F_105 ;
V_1 -> V_211 = F_5 ;
V_1 -> V_212 = 0 ;
if ( F_89 ( V_18 -> V_35 ) )
F_47 ( V_1 ) ;
if ( V_1 -> V_62 >= 80 && V_197 ) {
F_25 ( V_1 ,
L_25 ,
F_114 ( V_213 ) ) ;
V_1 -> V_62 = 40 ;
}
if ( ! V_18 -> V_58 && F_102 ( V_18 -> V_27 ) ) {
V_189 = F_115 ( & V_1 -> V_5 . V_65 -> V_112 ,
& V_192 . V_193 ) ;
if ( V_189 ) {
F_35 ( V_1 ,
L_26 ,
V_189 ) ;
goto V_203;
}
}
return 0 ;
V_203:
F_104 ( V_18 ) ;
return V_189 ;
}
int F_116 ( struct V_1 * V_1 )
{
return F_111 ( V_1 , true ) ;
}
int F_117 ( struct V_1 * V_1 )
{
return F_111 ( V_1 , false ) ;
}
void T_5 F_109 ( void )
{
}
int F_116 ( struct V_1 * V_1 )
{
return - V_214 ;
}
