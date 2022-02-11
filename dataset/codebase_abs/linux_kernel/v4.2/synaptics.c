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
static void F_44 ( struct V_1 * V_1 ,
struct V_65 * V_70 ,
unsigned char * V_71 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_1 * V_72 = F_38 ( V_70 ) ;
if ( V_72 && V_72 -> V_73 == V_74 ) {
F_45 ( V_70 , V_71 [ 1 ] | V_18 -> V_75 , 0 ) ;
F_45 ( V_70 , V_71 [ 4 ] , 0 ) ;
F_45 ( V_70 , V_71 [ 5 ] , 0 ) ;
if ( V_72 -> V_76 == 4 )
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
if ( V_72 -> V_76 == 4 )
V_18 -> V_2 |= V_77 ;
else
V_18 -> V_2 &= ~ V_77 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
F_18 ( V_1 ,
L_11 ) ;
}
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_65 * V_65 ;
V_65 = F_48 ( sizeof( struct V_65 ) , V_78 ) ;
if ( ! V_65 ) {
F_35 ( V_1 ,
L_12 ) ;
return;
}
V_65 -> V_40 . type = V_79 ;
F_49 ( V_65 -> V_12 , L_13 , sizeof( V_65 -> V_12 ) ) ;
F_49 ( V_65 -> V_80 , L_14 , sizeof( V_65 -> V_12 ) ) ;
V_65 -> V_81 = F_37 ;
V_65 -> V_82 = F_39 ;
V_65 -> V_83 = F_42 ;
V_65 -> V_66 = V_1 -> V_5 . V_65 ;
V_1 -> V_84 = F_46 ;
F_25 ( V_1 , L_15 ,
V_65 -> V_12 , V_1 -> V_80 ) ;
F_50 ( V_65 ) ;
}
static void F_51 ( const unsigned char V_23 [] ,
struct V_17 * V_18 ,
struct V_85 * V_86 )
{
struct V_85 * V_87 = & V_18 -> V_87 ;
int V_88 ;
V_88 = ( V_23 [ 5 ] & 0x30 ) >> 4 ;
switch ( V_88 ) {
case 1 :
V_87 -> V_89 = V_86 -> V_89 ;
V_87 -> V_90 = ( ( ( V_23 [ 4 ] & 0x0f ) << 8 ) | V_23 [ 1 ] ) << 1 ;
V_87 -> V_13 = ( ( ( V_23 [ 4 ] & 0xf0 ) << 4 ) | V_23 [ 2 ] ) << 1 ;
V_87 -> V_91 = ( ( V_23 [ 3 ] & 0x30 ) | ( V_23 [ 5 ] & 0x0f ) ) << 1 ;
break;
case 2 :
V_18 -> V_92 = V_23 [ 1 ] ;
break;
default:
break;
}
}
static void F_52 ( const unsigned char V_23 [] ,
struct V_17 * V_18 ,
struct V_85 * V_86 )
{
unsigned int V_93 =
( F_19 ( V_18 -> V_36 ) + 1 ) >> 1 ;
unsigned int V_94 = F_53 ( V_93 - 1 , 0 ) ;
V_86 -> V_95 = V_23 [ 4 ] & V_94 ;
V_86 -> V_95 |= ( V_23 [ 5 ] & V_94 ) << V_93 ;
}
static int F_54 ( const unsigned char V_23 [] ,
struct V_17 * V_18 ,
struct V_85 * V_86 )
{
memset ( V_86 , 0 , sizeof( struct V_85 ) ) ;
if ( F_55 ( V_18 -> V_22 ) ) {
V_86 -> V_89 = ( ( ( V_23 [ 0 ] & 0x30 ) >> 2 ) |
( ( V_23 [ 0 ] & 0x04 ) >> 1 ) |
( ( V_23 [ 3 ] & 0x04 ) >> 2 ) ) ;
if ( ( F_31 ( V_18 -> V_37 ) ||
F_32 ( V_18 -> V_37 ) ) &&
V_86 -> V_89 == 2 ) {
F_51 ( V_23 , V_18 , V_86 ) ;
return 1 ;
}
V_86 -> V_90 = ( ( ( V_23 [ 3 ] & 0x10 ) << 8 ) |
( ( V_23 [ 1 ] & 0x0f ) << 8 ) |
V_23 [ 4 ] ) ;
V_86 -> V_13 = ( ( ( V_23 [ 3 ] & 0x20 ) << 7 ) |
( ( V_23 [ 1 ] & 0xf0 ) << 4 ) |
V_23 [ 5 ] ) ;
V_86 -> V_91 = V_23 [ 2 ] ;
V_86 -> V_96 = ( V_23 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_86 -> V_97 = ( V_23 [ 0 ] & 0x02 ) ? 1 : 0 ;
if ( V_18 -> V_98 ) {
if ( V_86 -> V_91 == 0 ) {
V_18 -> V_99 = V_18 -> V_100 = false ;
} else if ( V_86 -> V_89 >= 4 && ( ( V_23 [ 0 ] ^ V_23 [ 3 ] ) & 0x01 ) ) {
if ( ! V_18 -> V_99 ) {
V_18 -> V_101 = V_102 ;
V_18 -> V_99 = true ;
} else if ( F_56 ( V_102 ,
V_18 -> V_101 +
F_57 ( 50 ) ) ) {
V_18 -> V_100 = true ;
}
} else {
V_18 -> V_99 = false ;
}
V_86 -> V_96 = V_18 -> V_100 ;
} else if ( F_58 ( V_18 -> V_37 ) ) {
V_86 -> V_96 = ( ( V_23 [ 0 ] ^ V_23 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
} else if ( F_59 ( V_18 -> V_35 ) ) {
V_86 -> V_103 = ( ( V_23 [ 0 ] ^ V_23 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
if ( V_86 -> V_89 == 2 )
V_86 -> V_104 = ( signed char ) ( V_23 [ 1 ] ) ;
}
if ( F_60 ( V_18 -> V_35 ) ) {
V_86 -> V_105 = ( ( V_23 [ 0 ] ^ V_23 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
V_86 -> V_106 = ( ( V_23 [ 0 ] ^ V_23 [ 3 ] ) & 0x02 ) ? 1 : 0 ;
}
if ( F_19 ( V_18 -> V_36 ) > 0 &&
( ( V_23 [ 0 ] ^ V_23 [ 3 ] ) & 0x02 ) ) {
F_52 ( V_23 , V_18 , V_86 ) ;
}
} else {
V_86 -> V_90 = ( ( ( V_23 [ 1 ] & 0x1f ) << 8 ) | V_23 [ 2 ] ) ;
V_86 -> V_13 = ( ( ( V_23 [ 4 ] & 0x1f ) << 8 ) | V_23 [ 5 ] ) ;
V_86 -> V_91 = ( ( ( V_23 [ 0 ] & 0x30 ) << 2 ) | ( V_23 [ 3 ] & 0x3F ) ) ;
V_86 -> V_89 = ( ( ( V_23 [ 1 ] & 0x80 ) >> 4 ) | ( ( V_23 [ 0 ] & 0x04 ) >> 1 ) ) ;
V_86 -> V_96 = ( V_23 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_86 -> V_97 = ( V_23 [ 0 ] & 0x02 ) ? 1 : 0 ;
}
if ( V_86 -> V_90 > V_107 )
V_86 -> V_90 -= 1 << V_108 ;
else if ( V_86 -> V_90 == V_107 )
V_86 -> V_90 = V_109 ;
if ( V_86 -> V_13 > V_110 )
V_86 -> V_13 -= 1 << V_108 ;
else if ( V_86 -> V_13 == V_110 )
V_86 -> V_13 = V_111 ;
return 0 ;
}
static void F_61 ( struct V_112 * V_113 , int V_114 ,
bool V_115 , int V_90 , int V_13 )
{
F_62 ( V_113 , V_114 ) ;
F_63 ( V_113 , V_116 , V_115 ) ;
if ( V_115 ) {
F_64 ( V_113 , V_117 , V_90 ) ;
F_64 ( V_113 , V_118 , F_6 ( V_13 ) ) ;
}
}
static void F_65 ( struct V_112 * V_113 ,
const struct V_85 * V_119 ,
const struct V_85 * V_120 ,
int V_121 )
{
if ( V_121 >= 2 ) {
F_61 ( V_113 , 0 , true , V_55 ( V_119 -> V_90 , V_120 -> V_90 ) ,
V_55 ( V_119 -> V_13 , V_120 -> V_13 ) ) ;
F_61 ( V_113 , 1 , true , V_57 ( V_119 -> V_90 , V_120 -> V_90 ) ,
V_57 ( V_119 -> V_13 , V_120 -> V_13 ) ) ;
} else if ( V_121 == 1 ) {
F_61 ( V_113 , 0 , true , V_119 -> V_90 , V_119 -> V_13 ) ;
F_61 ( V_113 , 1 , false , 0 , 0 ) ;
} else {
F_61 ( V_113 , 0 , false , 0 , 0 ) ;
F_61 ( V_113 , 1 , false , 0 , 0 ) ;
}
}
static void F_66 ( struct V_1 * V_1 ,
const struct V_85 * V_86 )
{
struct V_112 * V_113 = V_1 -> V_113 ;
struct V_17 * V_18 = V_1 -> V_19 ;
int V_93 = ( F_19 ( V_18 -> V_36 ) + 1 ) >> 1 ;
char V_23 [ 6 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
int V_52 ;
if ( ! F_19 ( V_18 -> V_36 ) )
return;
if ( F_11 ( V_18 -> V_27 ) == 0x801 &&
! ( ( V_1 -> V_71 [ 0 ] ^ V_1 -> V_71 [ 3 ] ) & 0x02 ) )
return;
if ( ! F_67 ( V_18 -> V_25 ) ) {
for ( V_52 = 0 ; V_52 < V_93 ; V_52 ++ ) {
F_68 ( V_113 , V_122 + 2 * V_52 ,
V_86 -> V_95 & ( 1 << V_52 ) ) ;
F_68 ( V_113 , V_123 + 2 * V_52 ,
V_86 -> V_95 & ( 1 << ( V_52 + V_93 ) ) ) ;
}
return;
}
if ( ! V_18 -> V_69 )
return;
V_18 -> V_75 = F_69 ( V_86 -> V_95 ) |
F_70 ( V_86 -> V_95 ) << 1 |
F_71 ( V_86 -> V_95 ) << 2 ;
F_44 ( V_1 , V_18 -> V_69 , V_23 ) ;
}
static void F_72 ( struct V_1 * V_1 ,
const struct V_85 * V_86 )
{
struct V_112 * V_113 = V_1 -> V_113 ;
struct V_17 * V_18 = V_1 -> V_19 ;
F_68 ( V_113 , V_124 , V_86 -> V_96 ) ;
F_68 ( V_113 , V_125 , V_86 -> V_97 ) ;
if ( F_59 ( V_18 -> V_35 ) )
F_68 ( V_113 , V_126 , V_86 -> V_103 ) ;
if ( F_60 ( V_18 -> V_35 ) ) {
F_68 ( V_113 , V_127 , V_86 -> V_105 ) ;
F_68 ( V_113 , V_128 , V_86 -> V_106 ) ;
}
F_66 ( V_1 , V_86 ) ;
}
static void F_73 ( struct V_1 * V_1 ,
const struct V_85 * V_129 ,
int V_121 )
{
struct V_112 * V_113 = V_1 -> V_113 ;
struct V_17 * V_18 = V_1 -> V_19 ;
const struct V_85 * V_86 [ 2 ] = { V_129 , & V_18 -> V_87 } ;
struct V_130 V_131 [ 2 ] ;
int V_114 [ 2 ] , V_132 , V_52 ;
V_132 = F_74 ( V_121 , 0 , 2 ) ;
for ( V_52 = 0 ; V_52 < V_132 ; V_52 ++ ) {
V_131 [ V_52 ] . V_90 = V_86 [ V_52 ] -> V_90 ;
V_131 [ V_52 ] . V_13 = F_6 ( V_86 [ V_52 ] -> V_13 ) ;
}
F_75 ( V_113 , V_114 , V_131 , V_132 , V_133 * V_18 -> V_44 ) ;
for ( V_52 = 0 ; V_52 < V_132 ; V_52 ++ ) {
F_62 ( V_113 , V_114 [ V_52 ] ) ;
F_63 ( V_113 , V_116 , true ) ;
F_64 ( V_113 , V_117 , V_131 [ V_52 ] . V_90 ) ;
F_64 ( V_113 , V_118 , V_131 [ V_52 ] . V_13 ) ;
F_64 ( V_113 , V_134 , V_86 [ V_52 ] -> V_91 ) ;
}
F_76 ( V_113 ) ;
F_77 ( V_113 , false ) ;
F_78 ( V_113 , V_121 ) ;
F_72 ( V_1 , V_129 ) ;
F_79 ( V_113 ) ;
}
static void F_80 ( struct V_1 * V_1 ,
struct V_85 * V_129 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
int V_121 ;
if ( V_129 -> V_91 == 0 )
V_121 = 0 ;
else if ( V_129 -> V_89 >= 4 )
V_121 = 1 ;
else if ( V_129 -> V_89 == 0 )
V_121 = 2 ;
else if ( V_129 -> V_89 == 1 )
V_121 = V_18 -> V_92 ? V_18 -> V_92 : 3 ;
else
V_121 = 4 ;
F_73 ( V_1 , V_129 , V_121 ) ;
}
static void F_81 ( struct V_1 * V_1 )
{
struct V_112 * V_113 = V_1 -> V_113 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_85 V_86 ;
int V_121 ;
int V_135 ;
if ( F_54 ( V_1 -> V_71 , V_18 , & V_86 ) )
return;
if ( F_32 ( V_18 -> V_37 ) ) {
F_80 ( V_1 , & V_86 ) ;
return;
}
if ( V_86 . V_104 ) {
V_18 -> V_104 += V_86 . V_104 ;
while ( V_18 -> V_104 >= 4 ) {
F_68 ( V_113 , V_128 , ! V_86 . V_106 ) ;
F_79 ( V_113 ) ;
F_68 ( V_113 , V_128 , V_86 . V_106 ) ;
F_79 ( V_113 ) ;
V_18 -> V_104 -= 4 ;
}
while ( V_18 -> V_104 <= - 4 ) {
F_68 ( V_113 , V_127 , ! V_86 . V_105 ) ;
F_79 ( V_113 ) ;
F_68 ( V_113 , V_127 , V_86 . V_105 ) ;
F_79 ( V_113 ) ;
V_18 -> V_104 += 4 ;
}
return;
}
if ( V_86 . V_91 > 0 && V_86 . V_90 > 1 ) {
V_121 = 1 ;
V_135 = 5 ;
if ( F_16 ( V_18 -> V_35 ) ) {
switch ( V_86 . V_89 ) {
case 0 ... 1 :
if ( F_82 ( V_18 -> V_35 ) )
V_121 = V_86 . V_89 + 2 ;
break;
case 2 :
if ( F_83 ( V_18 -> V_22 ) )
;
break;
case 4 ... 15 :
if ( F_84 ( V_18 -> V_35 ) )
V_135 = V_86 . V_89 ;
break;
}
}
} else {
V_121 = 0 ;
V_135 = 0 ;
}
if ( V_136 ) {
F_73 ( V_1 , & V_86 , V_121 ) ;
return;
}
if ( F_31 ( V_18 -> V_37 ) )
F_65 ( V_113 , & V_86 , & V_18 -> V_87 ,
V_121 ) ;
if ( V_86 . V_91 > 30 ) F_68 ( V_113 , V_137 , 1 ) ;
if ( V_86 . V_91 < 25 ) F_68 ( V_113 , V_137 , 0 ) ;
if ( V_121 > 0 ) {
F_64 ( V_113 , V_138 , V_86 . V_90 ) ;
F_64 ( V_113 , V_139 , F_6 ( V_86 . V_13 ) ) ;
}
F_64 ( V_113 , V_140 , V_86 . V_91 ) ;
if ( F_84 ( V_18 -> V_35 ) )
F_64 ( V_113 , V_141 , V_135 ) ;
F_68 ( V_113 , V_142 , V_121 == 1 ) ;
if ( F_82 ( V_18 -> V_35 ) ) {
F_68 ( V_113 , V_143 , V_121 == 2 ) ;
F_68 ( V_113 , V_144 , V_121 == 3 ) ;
}
F_72 ( V_1 , & V_86 ) ;
F_79 ( V_113 ) ;
}
static int F_85 ( struct V_1 * V_1 ,
int V_145 , unsigned char V_146 )
{
static const unsigned char V_147 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const unsigned char V_148 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_149 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_150 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const unsigned char V_151 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
const char * V_71 = V_1 -> V_71 ;
if ( V_145 < 0 || V_145 > 4 )
return 0 ;
switch ( V_146 ) {
case V_152 :
case V_153 :
return ( V_71 [ V_145 ] & V_148 [ V_145 ] ) == V_149 [ V_145 ] ;
case V_154 :
return ( V_71 [ V_145 ] & V_147 [ V_145 ] ) == V_149 [ V_145 ] ;
case V_155 :
return ( V_71 [ V_145 ] & V_150 [ V_145 ] ) == V_151 [ V_145 ] ;
default:
F_35 ( V_1 , L_16 , V_146 ) ;
return 0 ;
}
}
static unsigned char F_86 ( struct V_1 * V_1 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < 5 ; V_52 ++ )
if ( ! F_85 ( V_1 , V_52 , V_154 ) ) {
F_25 ( V_1 , L_17 ) ;
return V_153 ;
}
return V_154 ;
}
static T_1 F_87 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( V_1 -> V_156 >= 6 ) {
if ( F_88 ( V_18 -> V_146 == V_152 ) )
V_18 -> V_146 = F_86 ( V_1 ) ;
if ( F_89 ( V_18 -> V_35 ) &&
F_43 ( V_1 -> V_71 ) ) {
if ( V_18 -> V_69 )
F_44 ( V_1 , V_18 -> V_69 ,
V_1 -> V_71 ) ;
} else
F_81 ( V_1 ) ;
return V_157 ;
}
return F_85 ( V_1 , V_1 -> V_156 - 1 , V_18 -> V_146 ) ?
V_158 : V_159 ;
}
static void F_90 ( struct V_112 * V_113 ,
struct V_17 * V_18 , int V_160 ,
int V_161 )
{
int V_50 = V_18 -> V_50 ? : V_162 ;
int V_47 = V_18 -> V_47 ? : V_163 ;
int V_51 = V_18 -> V_51 ? : V_15 ;
int V_48 = V_18 -> V_48 ? : V_14 ;
int V_164 = F_91 ( V_18 -> V_37 ) ?
V_165 : 0 ;
F_92 ( V_113 , V_160 , V_50 , V_47 , V_164 , 0 ) ;
F_92 ( V_113 , V_161 , V_51 , V_48 , V_164 , 0 ) ;
F_93 ( V_113 , V_160 , V_18 -> V_44 ) ;
F_93 ( V_113 , V_161 , V_18 -> V_45 ) ;
}
static void F_94 ( struct V_1 * V_1 ,
struct V_17 * V_18 )
{
struct V_112 * V_113 = V_1 -> V_113 ;
int V_52 ;
F_95 ( V_166 , V_113 -> V_167 ) ;
F_95 ( V_168 , V_113 -> V_169 ) ;
F_95 ( V_124 , V_113 -> V_170 ) ;
F_95 ( V_125 , V_113 -> V_170 ) ;
if ( F_59 ( V_18 -> V_35 ) )
F_95 ( V_126 , V_113 -> V_170 ) ;
if ( ! V_18 -> V_58 ) {
F_95 ( V_171 , V_113 -> V_169 ) ;
F_95 ( V_172 , V_113 -> V_173 ) ;
F_95 ( V_174 , V_113 -> V_173 ) ;
return;
}
F_95 ( V_175 , V_113 -> V_169 ) ;
F_90 ( V_113 , V_18 , V_138 , V_139 ) ;
F_92 ( V_113 , V_140 , 0 , 255 , 0 , 0 ) ;
if ( V_136 )
F_92 ( V_113 , V_134 , 0 , 255 , 0 , 0 ) ;
if ( F_32 ( V_18 -> V_37 ) ) {
F_90 ( V_113 , V_18 , V_117 ,
V_118 ) ;
F_92 ( V_113 , V_134 , 0 , 255 , 0 , 0 ) ;
F_96 ( V_113 , 2 , V_176 | V_177 ) ;
F_95 ( V_178 , V_113 -> V_170 ) ;
F_95 ( V_179 , V_113 -> V_170 ) ;
} else if ( F_31 ( V_18 -> V_37 ) ) {
F_90 ( V_113 , V_18 , V_117 ,
V_118 ) ;
F_96 ( V_113 , 2 ,
V_176 |
( V_136 ?
V_177 : V_180 ) ) ;
}
if ( F_84 ( V_18 -> V_35 ) )
F_92 ( V_113 , V_141 , 0 , 15 , 0 , 0 ) ;
F_95 ( V_137 , V_113 -> V_170 ) ;
F_95 ( V_142 , V_113 -> V_170 ) ;
if ( F_82 ( V_18 -> V_35 ) ) {
F_95 ( V_143 , V_113 -> V_170 ) ;
F_95 ( V_144 , V_113 -> V_170 ) ;
}
if ( F_60 ( V_18 -> V_35 ) ||
F_59 ( V_18 -> V_35 ) ) {
F_95 ( V_127 , V_113 -> V_170 ) ;
F_95 ( V_128 , V_113 -> V_170 ) ;
}
if ( ! F_67 ( V_18 -> V_25 ) )
for ( V_52 = 0 ; V_52 < F_19 ( V_18 -> V_36 ) ; V_52 ++ )
F_95 ( V_122 + V_52 , V_113 -> V_170 ) ;
F_97 ( V_171 , V_113 -> V_169 ) ;
F_97 ( V_172 , V_113 -> V_173 ) ;
F_97 ( V_174 , V_113 -> V_173 ) ;
if ( F_58 ( V_18 -> V_37 ) ) {
F_95 ( V_181 , V_113 -> V_167 ) ;
if ( F_28 ( V_1 , V_182 ) &&
! F_67 ( V_18 -> V_25 ) )
F_95 ( V_183 , V_113 -> V_167 ) ;
F_97 ( V_125 , V_113 -> V_170 ) ;
F_97 ( V_126 , V_113 -> V_170 ) ;
}
}
static T_2 F_98 ( struct V_1 * V_1 ,
void * V_184 , char * V_23 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
return sprintf ( V_23 , L_18 , V_18 -> V_60 ? '1' : '0' ) ;
}
static T_2 F_99 ( struct V_1 * V_1 ,
void * V_184 , const char * V_23 ,
T_3 V_185 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned int V_186 ;
int V_187 ;
V_187 = F_100 ( V_23 , 10 , & V_186 ) ;
if ( V_187 )
return V_187 ;
if ( V_186 > 1 )
return - V_188 ;
if ( V_186 == V_18 -> V_60 )
return V_185 ;
V_18 -> V_60 = V_186 ;
if ( V_186 )
V_18 -> V_2 |= V_61 ;
else
V_18 -> V_2 &= ~ V_61 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
return - V_189 ;
return V_185 ;
}
static void F_101 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( ! V_18 -> V_58 && F_102 ( V_18 -> V_27 ) )
F_103 ( & V_1 -> V_5 . V_65 -> V_113 ,
& V_190 . V_191 ) ;
F_5 ( V_1 ) ;
F_104 ( V_18 ) ;
V_1 -> V_19 = NULL ;
}
static int F_105 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_17 V_192 = * V_18 ;
unsigned char V_3 [ 2 ] ;
int V_193 = 0 ;
int error ;
do {
F_106 ( V_1 ) ;
if ( V_193 ) {
F_107 ( 1 ) ;
}
F_3 ( & V_1 -> V_5 , V_3 , V_194 ) ;
error = F_4 ( V_1 , 0 ) ;
} while ( error && ++ V_193 < 3 );
if ( error )
return - 1 ;
if ( V_193 > 1 )
F_108 ( V_1 , L_19 , V_193 ) ;
if ( F_29 ( V_1 ) ) {
F_35 ( V_1 , L_20 ) ;
return - 1 ;
}
if ( F_34 ( V_1 ) ) {
F_35 ( V_1 , L_21 ) ;
return - 1 ;
}
if ( V_192 . V_27 != V_18 -> V_27 ||
V_192 . V_22 != V_18 -> V_22 ||
V_192 . V_35 != V_18 -> V_35 ||
V_192 . V_36 != V_18 -> V_36 ) {
F_35 ( V_1 ,
L_22 ,
V_192 . V_27 , V_18 -> V_27 ,
V_192 . V_22 , V_18 -> V_22 ,
V_192 . V_35 , V_18 -> V_35 ,
V_192 . V_36 , V_18 -> V_36 ) ;
return - 1 ;
}
return 0 ;
}
void T_4 F_109 ( void )
{
V_195 = F_110 ( V_196 ) ;
V_197 = F_110 ( V_198 ) ;
V_136 = F_110 ( V_199 ) ;
}
static int F_111 ( struct V_1 * V_1 , bool V_58 )
{
struct V_17 * V_18 ;
int V_187 = - 1 ;
if ( V_58 && V_197 ) {
F_25 ( V_1 ,
L_23 ) ;
return - V_10 ;
}
V_1 -> V_19 = V_18 = F_48 ( sizeof( struct V_17 ) , V_78 ) ;
if ( ! V_18 )
return - V_200 ;
F_106 ( V_1 ) ;
if ( F_29 ( V_1 ) ) {
F_35 ( V_1 , L_20 ) ;
goto V_201;
}
V_18 -> V_58 = V_58 ;
if ( F_102 ( V_18 -> V_27 ) )
V_18 -> V_60 = true ;
V_18 -> V_98 = F_28 ( V_1 , V_202 ) ;
if ( F_34 ( V_1 ) ) {
F_35 ( V_1 , L_21 ) ;
goto V_201;
}
V_18 -> V_146 = F_55 ( V_18 -> V_22 ) ? V_152 : V_155 ;
F_25 ( V_1 ,
L_24 ,
F_112 ( V_18 -> V_27 ) ,
F_23 ( V_18 -> V_27 ) , F_113 ( V_18 -> V_27 ) ,
V_18 -> V_22 ,
V_18 -> V_35 , V_18 -> V_36 , V_18 -> V_37 ,
V_18 -> V_25 , V_18 -> V_29 , V_18 -> V_32 ) ;
F_94 ( V_1 , V_18 ) ;
V_1 -> V_203 = ( ( V_18 -> V_22 & 0x00ff0000 ) >> 8 ) |
( V_18 -> V_22 & 0x000000ff ) ;
if ( V_58 ) {
V_1 -> V_204 = F_87 ;
V_1 -> V_76 = 6 ;
} else {
V_1 -> V_204 = V_205 ;
V_1 -> V_76 = 3 ;
}
V_1 -> V_206 = F_36 ;
V_1 -> V_207 = F_101 ;
V_1 -> V_208 = F_105 ;
V_1 -> V_209 = F_5 ;
V_1 -> V_210 = 0 ;
if ( F_89 ( V_18 -> V_35 ) )
F_47 ( V_1 ) ;
if ( V_1 -> V_62 >= 80 && V_195 ) {
F_25 ( V_1 ,
L_25 ,
F_114 ( V_211 ) ) ;
V_1 -> V_62 = 40 ;
}
if ( ! V_18 -> V_58 && F_102 ( V_18 -> V_27 ) ) {
V_187 = F_115 ( & V_1 -> V_5 . V_65 -> V_113 ,
& V_190 . V_191 ) ;
if ( V_187 ) {
F_35 ( V_1 ,
L_26 ,
V_187 ) ;
goto V_201;
}
}
return 0 ;
V_201:
F_104 ( V_18 ) ;
return V_187 ;
}
int F_116 ( struct V_1 * V_1 )
{
return F_111 ( V_1 , true ) ;
}
int F_117 ( struct V_1 * V_1 )
{
return F_111 ( V_1 , false ) ;
}
void T_4 F_109 ( void )
{
}
int F_116 ( struct V_1 * V_1 )
{
return - V_212 ;
}
