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
static int F_6 ( struct V_1 * V_1 , unsigned char V_13 , unsigned char * V_3 )
{
if ( F_2 ( V_1 , V_13 ) )
return - 1 ;
if ( F_3 ( & V_1 -> V_5 , V_3 , V_9 ) )
return - 1 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
unsigned char V_17 [ 3 ] ;
if ( F_6 ( V_1 , V_18 , V_17 ) )
return - 1 ;
V_15 -> V_19 = ( V_17 [ 0 ] << 16 ) | ( V_17 [ 1 ] << 8 ) | V_17 [ 2 ] ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
unsigned char V_20 [ 3 ] ;
if ( F_6 ( V_1 , V_21 , V_20 ) )
return - 1 ;
V_15 -> V_22 = ( V_20 [ 0 ] << 16 ) | ( V_20 [ 1 ] << 8 ) | V_20 [ 2 ] ;
V_15 -> V_23 = V_15 -> V_24 = 0 ;
if ( F_9 ( V_15 -> V_25 ) < 0x705 &&
F_10 ( V_15 -> V_22 ) != 0x47 ) {
return - 1 ;
}
if ( ! F_11 ( V_15 -> V_22 ) )
V_15 -> V_22 = 0 ;
if ( F_12 ( V_15 -> V_22 ) >= 1 ) {
if ( F_6 ( V_1 , V_26 , V_20 ) ) {
F_13 ( V_27 L_3
L_4 ) ;
} else {
V_15 -> V_23 = ( V_20 [ 0 ] << 16 ) | ( V_20 [ 1 ] << 8 ) | V_20 [ 2 ] ;
if ( F_14 ( V_15 -> V_23 ) > 8 )
V_15 -> V_23 &= 0xff0fff ;
}
}
if ( F_12 ( V_15 -> V_22 ) >= 4 ) {
if ( F_6 ( V_1 , V_28 , V_20 ) ) {
F_13 ( V_27 L_5
L_6 ) ;
} else {
V_15 -> V_24 = ( V_20 [ 0 ] << 16 ) | ( V_20 [ 1 ] << 8 ) | V_20 [ 2 ] ;
}
}
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
unsigned char V_29 [ 3 ] ;
if ( F_6 ( V_1 , V_30 , V_29 ) )
return - 1 ;
V_15 -> V_25 = ( V_29 [ 0 ] << 16 ) | ( V_29 [ 1 ] << 8 ) | V_29 [ 2 ] ;
if ( F_16 ( V_15 -> V_25 ) )
return 0 ;
return - 1 ;
}
static int F_17 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
unsigned char V_31 [ 3 ] ;
if ( F_18 ( V_15 -> V_25 ) < 4 )
return 0 ;
if ( F_6 ( V_1 , V_32 , V_31 ) == 0 ) {
if ( V_31 [ 0 ] != 0 && ( V_31 [ 1 ] & 0x80 ) && V_31 [ 2 ] != 0 ) {
V_15 -> V_33 = V_31 [ 0 ] ;
V_15 -> V_34 = V_31 [ 2 ] ;
}
}
if ( F_12 ( V_15 -> V_22 ) >= 5 &&
F_19 ( V_15 -> V_24 ) ) {
if ( F_6 ( V_1 , V_35 , V_31 ) ) {
F_13 ( V_27 L_7
L_8 ) ;
} else {
V_15 -> V_36 = ( V_31 [ 0 ] << 5 ) | ( ( V_31 [ 1 ] & 0x0f ) << 1 ) ;
V_15 -> V_37 = ( V_31 [ 2 ] << 5 ) | ( ( V_31 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
if ( F_12 ( V_15 -> V_22 ) >= 7 &&
F_20 ( V_15 -> V_24 ) ) {
if ( F_6 ( V_1 , V_38 , V_31 ) ) {
F_13 ( V_27 L_9
L_8 ) ;
} else {
V_15 -> V_39 = ( V_31 [ 0 ] << 5 ) | ( ( V_31 [ 1 ] & 0x0f ) << 1 ) ;
V_15 -> V_40 = ( V_31 [ 2 ] << 5 ) | ( ( V_31 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
if ( F_15 ( V_1 ) )
return - 1 ;
if ( F_7 ( V_1 ) )
return - 1 ;
if ( F_8 ( V_1 ) )
return - 1 ;
if ( F_17 ( V_1 ) )
return - 1 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
V_15 -> V_2 = V_41 ;
if ( F_18 ( V_15 -> V_25 ) >= 4 )
V_15 -> V_2 |= V_42 ;
if ( F_11 ( V_15 -> V_22 ) )
V_15 -> V_2 |= V_43 ;
if ( F_1 ( V_1 , V_15 -> V_2 ) )
return - 1 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_1 , unsigned int V_44 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
if ( V_44 >= 80 ) {
V_15 -> V_2 |= V_45 ;
V_1 -> V_44 = 80 ;
} else {
V_15 -> V_2 &= ~ V_45 ;
V_1 -> V_44 = 40 ;
}
F_1 ( V_1 , V_15 -> V_2 ) ;
}
static int F_24 ( struct V_1 * V_1 )
{
static unsigned char V_3 = 0xc8 ;
struct V_14 * V_15 = V_1 -> V_16 ;
if ( ! F_25 ( V_15 -> V_24 ) )
return 0 ;
if ( F_2 ( V_1 , V_18 ) )
return - 1 ;
if ( F_3 ( & V_1 -> V_5 , & V_3 , V_6 ) )
return - 1 ;
V_15 -> V_22 |= F_26 ( 1 ) ;
return 0 ;
}
static int F_27 ( struct V_46 * V_46 , unsigned char V_13 )
{
struct V_1 * V_47 = F_28 ( V_46 -> V_47 ) ;
char V_48 = V_49 ;
if ( F_2 ( V_47 , V_13 ) )
return - 1 ;
if ( F_3 ( & V_47 -> V_5 , & V_48 , V_6 ) )
return - 1 ;
return 0 ;
}
static int F_29 ( struct V_46 * V_46 )
{
struct V_1 * V_47 = F_28 ( V_46 -> V_47 ) ;
struct V_14 * V_15 = V_47 -> V_16 ;
F_30 ( V_47 -> V_5 . V_46 ) ;
V_15 -> V_50 = V_46 ;
F_31 ( V_47 -> V_5 . V_46 ) ;
return 0 ;
}
static void F_32 ( struct V_46 * V_46 )
{
struct V_1 * V_47 = F_28 ( V_46 -> V_47 ) ;
struct V_14 * V_15 = V_47 -> V_16 ;
F_30 ( V_47 -> V_5 . V_46 ) ;
V_15 -> V_50 = NULL ;
F_31 ( V_47 -> V_5 . V_46 ) ;
}
static int F_33 ( unsigned char * V_51 )
{
return ( V_51 [ 0 ] & 0xFC ) == 0x84 && ( V_51 [ 3 ] & 0xCC ) == 0xC4 ;
}
static void F_34 ( struct V_46 * V_52 , unsigned char * V_53 )
{
struct V_1 * V_54 = F_28 ( V_52 ) ;
if ( V_54 && V_54 -> V_55 == V_56 ) {
F_35 ( V_52 , V_53 [ 1 ] , 0 ) ;
F_35 ( V_52 , V_53 [ 4 ] , 0 ) ;
F_35 ( V_52 , V_53 [ 5 ] , 0 ) ;
if ( V_54 -> V_57 == 4 )
F_35 ( V_52 , V_53 [ 2 ] , 0 ) ;
} else
F_35 ( V_52 , V_53 [ 1 ] , 0 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
struct V_1 * V_54 = F_28 ( V_15 -> V_50 ) ;
if ( V_54 ) {
if ( V_54 -> V_57 == 4 )
V_15 -> V_2 |= V_58 ;
else
V_15 -> V_2 &= ~ V_58 ;
if ( F_1 ( V_1 , V_15 -> V_2 ) )
F_13 ( V_59 L_10 ) ;
}
}
static void F_37 ( struct V_1 * V_1 )
{
struct V_46 * V_46 ;
V_46 = F_38 ( sizeof( struct V_46 ) , V_60 ) ;
if ( ! V_46 ) {
F_13 ( V_27 L_11 ) ;
return;
}
V_46 -> V_29 . type = V_61 ;
F_39 ( V_46 -> V_12 , L_12 , sizeof( V_46 -> V_12 ) ) ;
F_39 ( V_46 -> V_62 , L_13 , sizeof( V_46 -> V_12 ) ) ;
V_46 -> V_63 = F_27 ;
V_46 -> V_64 = F_29 ;
V_46 -> V_65 = F_32 ;
V_46 -> V_47 = V_1 -> V_5 . V_46 ;
V_1 -> V_66 = F_36 ;
F_13 ( V_59 L_14 , V_46 -> V_12 , V_1 -> V_62 ) ;
F_40 ( V_46 ) ;
}
static int F_41 ( const unsigned char V_51 [] ,
struct V_14 * V_15 ,
struct V_67 * V_68 )
{
memset ( V_68 , 0 , sizeof( struct V_67 ) ) ;
if ( F_42 ( V_15 -> V_19 ) ) {
V_68 -> V_69 = ( ( ( V_51 [ 0 ] & 0x30 ) >> 2 ) |
( ( V_51 [ 0 ] & 0x04 ) >> 1 ) |
( ( V_51 [ 3 ] & 0x04 ) >> 2 ) ) ;
V_68 -> V_70 = ( V_51 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_68 -> V_71 = ( V_51 [ 0 ] & 0x02 ) ? 1 : 0 ;
if ( F_43 ( V_15 -> V_24 ) ) {
V_68 -> V_70 = ( ( V_51 [ 0 ] ^ V_51 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
} else if ( F_44 ( V_15 -> V_22 ) ) {
V_68 -> V_72 = ( ( V_51 [ 0 ] ^ V_51 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
if ( V_68 -> V_69 == 2 )
V_68 -> V_73 = ( signed char ) ( V_51 [ 1 ] ) ;
}
if ( F_45 ( V_15 -> V_22 ) ) {
V_68 -> V_74 = ( ( V_51 [ 0 ] ^ V_51 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
V_68 -> V_75 = ( ( V_51 [ 0 ] ^ V_51 [ 3 ] ) & 0x02 ) ? 1 : 0 ;
}
if ( F_25 ( V_15 -> V_24 ) && V_68 -> V_69 == 2 ) {
V_15 -> V_76 . V_77 = ( ( ( V_51 [ 4 ] & 0x0f ) << 8 ) | V_51 [ 1 ] ) << 1 ;
V_15 -> V_76 . V_78 = ( ( ( V_51 [ 4 ] & 0xf0 ) << 4 ) | V_51 [ 2 ] ) << 1 ;
V_15 -> V_76 . V_79 = ( ( V_51 [ 3 ] & 0x30 ) | ( V_51 [ 5 ] & 0x0f ) ) << 1 ;
return 1 ;
}
V_68 -> V_77 = ( ( ( V_51 [ 3 ] & 0x10 ) << 8 ) |
( ( V_51 [ 1 ] & 0x0f ) << 8 ) |
V_51 [ 4 ] ) ;
V_68 -> V_78 = ( ( ( V_51 [ 3 ] & 0x20 ) << 7 ) |
( ( V_51 [ 1 ] & 0xf0 ) << 4 ) |
V_51 [ 5 ] ) ;
V_68 -> V_79 = V_51 [ 2 ] ;
if ( F_14 ( V_15 -> V_23 ) &&
( ( V_51 [ 0 ] ^ V_51 [ 3 ] ) & 0x02 ) ) {
switch ( F_14 ( V_15 -> V_23 ) & ~ 0x01 ) {
default:
break;
case 8 :
V_68 -> V_80 |= ( ( V_51 [ 5 ] & 0x08 ) ) ? 0x80 : 0 ;
V_68 -> V_80 |= ( ( V_51 [ 4 ] & 0x08 ) ) ? 0x40 : 0 ;
case 6 :
V_68 -> V_80 |= ( ( V_51 [ 5 ] & 0x04 ) ) ? 0x20 : 0 ;
V_68 -> V_80 |= ( ( V_51 [ 4 ] & 0x04 ) ) ? 0x10 : 0 ;
case 4 :
V_68 -> V_80 |= ( ( V_51 [ 5 ] & 0x02 ) ) ? 0x08 : 0 ;
V_68 -> V_80 |= ( ( V_51 [ 4 ] & 0x02 ) ) ? 0x04 : 0 ;
case 2 :
V_68 -> V_80 |= ( ( V_51 [ 5 ] & 0x01 ) ) ? 0x02 : 0 ;
V_68 -> V_80 |= ( ( V_51 [ 4 ] & 0x01 ) ) ? 0x01 : 0 ;
}
}
} else {
V_68 -> V_77 = ( ( ( V_51 [ 1 ] & 0x1f ) << 8 ) | V_51 [ 2 ] ) ;
V_68 -> V_78 = ( ( ( V_51 [ 4 ] & 0x1f ) << 8 ) | V_51 [ 5 ] ) ;
V_68 -> V_79 = ( ( ( V_51 [ 0 ] & 0x30 ) << 2 ) | ( V_51 [ 3 ] & 0x3F ) ) ;
V_68 -> V_69 = ( ( ( V_51 [ 1 ] & 0x80 ) >> 4 ) | ( ( V_51 [ 0 ] & 0x04 ) >> 1 ) ) ;
V_68 -> V_70 = ( V_51 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_68 -> V_71 = ( V_51 [ 0 ] & 0x02 ) ? 1 : 0 ;
}
return 0 ;
}
static void F_46 ( struct V_81 * V_82 , int V_83 ,
bool V_84 , int V_77 , int V_78 )
{
F_47 ( V_82 , V_83 ) ;
F_48 ( V_82 , V_85 , V_84 ) ;
if ( V_84 ) {
F_49 ( V_82 , V_86 , V_77 ) ;
F_49 ( V_82 , V_87 ,
V_88 + V_89 - V_78 ) ;
}
}
static void F_50 ( struct V_81 * V_82 ,
const struct V_67 * V_90 ,
const struct V_67 * V_91 ,
int V_92 )
{
if ( V_92 >= 2 ) {
F_46 ( V_82 , 0 , true , F_51 ( V_90 -> V_77 , V_91 -> V_77 ) ,
F_51 ( V_90 -> V_78 , V_91 -> V_78 ) ) ;
F_46 ( V_82 , 1 , true , F_52 ( V_90 -> V_77 , V_91 -> V_77 ) ,
F_52 ( V_90 -> V_78 , V_91 -> V_78 ) ) ;
} else if ( V_92 == 1 ) {
F_46 ( V_82 , 0 , true , V_90 -> V_77 , V_90 -> V_78 ) ;
F_46 ( V_82 , 1 , false , 0 , 0 ) ;
} else {
F_46 ( V_82 , 0 , false , 0 , 0 ) ;
F_46 ( V_82 , 1 , false , 0 , 0 ) ;
}
}
static void F_53 ( struct V_1 * V_1 )
{
struct V_81 * V_82 = V_1 -> V_82 ;
struct V_14 * V_15 = V_1 -> V_16 ;
struct V_67 V_68 ;
int V_92 ;
int V_93 ;
int V_94 ;
if ( F_41 ( V_1 -> V_53 , V_15 , & V_68 ) )
return;
if ( V_68 . V_73 ) {
V_15 -> V_73 += V_68 . V_73 ;
while ( V_15 -> V_73 >= 4 ) {
F_54 ( V_82 , V_95 , ! V_68 . V_75 ) ;
F_55 ( V_82 ) ;
F_54 ( V_82 , V_95 , V_68 . V_75 ) ;
F_55 ( V_82 ) ;
V_15 -> V_73 -= 4 ;
}
while ( V_15 -> V_73 <= - 4 ) {
F_54 ( V_82 , V_96 , ! V_68 . V_74 ) ;
F_55 ( V_82 ) ;
F_54 ( V_82 , V_96 , V_68 . V_74 ) ;
F_55 ( V_82 ) ;
V_15 -> V_73 += 4 ;
}
return;
}
if ( V_68 . V_79 > 0 && V_68 . V_77 > 1 ) {
V_92 = 1 ;
V_93 = 5 ;
if ( F_11 ( V_15 -> V_22 ) ) {
switch ( V_68 . V_69 ) {
case 0 ... 1 :
if ( F_56 ( V_15 -> V_22 ) )
V_92 = V_68 . V_69 + 2 ;
break;
case 2 :
if ( F_57 ( V_15 -> V_19 ) )
;
break;
case 4 ... 15 :
if ( F_58 ( V_15 -> V_22 ) )
V_93 = V_68 . V_69 ;
break;
}
}
} else {
V_92 = 0 ;
V_93 = 0 ;
}
if ( F_25 ( V_15 -> V_24 ) )
F_50 ( V_82 , & V_68 , & V_15 -> V_76 , V_92 ) ;
if ( V_68 . V_79 > 30 ) F_54 ( V_82 , V_97 , 1 ) ;
if ( V_68 . V_79 < 25 ) F_54 ( V_82 , V_97 , 0 ) ;
if ( V_92 > 0 ) {
F_49 ( V_82 , V_98 , V_68 . V_77 ) ;
F_49 ( V_82 , V_99 , V_88 + V_89 - V_68 . V_78 ) ;
}
F_49 ( V_82 , V_100 , V_68 . V_79 ) ;
if ( F_58 ( V_15 -> V_22 ) )
F_49 ( V_82 , V_101 , V_93 ) ;
F_54 ( V_82 , V_102 , V_92 == 1 ) ;
F_54 ( V_82 , V_103 , V_68 . V_70 ) ;
F_54 ( V_82 , V_104 , V_68 . V_71 ) ;
if ( F_56 ( V_15 -> V_22 ) ) {
F_54 ( V_82 , V_105 , V_92 == 2 ) ;
F_54 ( V_82 , V_106 , V_92 == 3 ) ;
}
if ( F_44 ( V_15 -> V_22 ) )
F_54 ( V_82 , V_107 , V_68 . V_72 ) ;
if ( F_45 ( V_15 -> V_22 ) ) {
F_54 ( V_82 , V_96 , V_68 . V_74 ) ;
F_54 ( V_82 , V_95 , V_68 . V_75 ) ;
}
for ( V_94 = 0 ; V_94 < F_14 ( V_15 -> V_23 ) ; V_94 ++ )
F_54 ( V_82 , V_108 + V_94 , V_68 . V_80 & ( 1 << V_94 ) ) ;
F_55 ( V_82 ) ;
}
static int F_59 ( unsigned char V_53 [] , int V_109 , unsigned char V_110 )
{
static const unsigned char V_111 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const unsigned char V_112 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_113 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_114 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const unsigned char V_115 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
if ( V_109 < 0 || V_109 > 4 )
return 0 ;
switch ( V_110 ) {
case V_116 :
case V_117 :
return ( V_53 [ V_109 ] & V_112 [ V_109 ] ) == V_113 [ V_109 ] ;
case V_118 :
return ( V_53 [ V_109 ] & V_111 [ V_109 ] ) == V_113 [ V_109 ] ;
case V_119 :
return ( V_53 [ V_109 ] & V_114 [ V_109 ] ) == V_115 [ V_109 ] ;
default:
F_13 ( V_27 L_15 , V_110 ) ;
return 0 ;
}
}
static unsigned char F_60 ( struct V_1 * V_1 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < 5 ; V_94 ++ )
if ( ! F_59 ( V_1 -> V_53 , V_94 , V_118 ) ) {
F_13 ( V_59 L_16 ) ;
return V_117 ;
}
return V_118 ;
}
static T_1 F_61 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
if ( V_1 -> V_120 >= 6 ) {
if ( F_62 ( V_15 -> V_110 == V_116 ) )
V_15 -> V_110 = F_60 ( V_1 ) ;
if ( F_63 ( V_15 -> V_22 ) &&
F_33 ( V_1 -> V_53 ) ) {
if ( V_15 -> V_50 )
F_34 ( V_15 -> V_50 , V_1 -> V_53 ) ;
} else
F_53 ( V_1 ) ;
return V_121 ;
}
return F_59 ( V_1 -> V_53 , V_1 -> V_120 - 1 , V_15 -> V_110 ) ?
V_122 : V_123 ;
}
static void F_64 ( struct V_81 * V_82 , struct V_14 * V_15 )
{
int V_94 ;
int V_124 = F_65 ( V_15 -> V_24 ) ?
V_125 : 0 ;
F_66 ( V_126 , V_82 -> V_127 ) ;
F_66 ( V_128 , V_82 -> V_129 ) ;
F_67 ( V_82 , V_98 ,
V_15 -> V_39 ? : V_130 ,
V_15 -> V_36 ? : V_131 ,
V_124 , 0 ) ;
F_67 ( V_82 , V_99 ,
V_15 -> V_40 ? : V_89 ,
V_15 -> V_37 ? : V_88 ,
V_124 , 0 ) ;
F_67 ( V_82 , V_100 , 0 , 255 , 0 , 0 ) ;
if ( F_25 ( V_15 -> V_24 ) ) {
F_66 ( V_132 , V_82 -> V_127 ) ;
F_68 ( V_82 , 2 ) ;
F_67 ( V_82 , V_86 ,
V_15 -> V_39 ? : V_130 ,
V_15 -> V_36 ? : V_131 ,
V_124 , 0 ) ;
F_67 ( V_82 , V_87 ,
V_15 -> V_40 ? : V_89 ,
V_15 -> V_37 ? : V_88 ,
V_124 , 0 ) ;
F_69 ( V_82 , V_86 , V_15 -> V_33 ) ;
F_69 ( V_82 , V_87 , V_15 -> V_34 ) ;
}
if ( F_58 ( V_15 -> V_22 ) )
F_67 ( V_82 , V_101 , 0 , 15 , 0 , 0 ) ;
F_66 ( V_133 , V_82 -> V_129 ) ;
F_66 ( V_97 , V_82 -> V_134 ) ;
F_66 ( V_102 , V_82 -> V_134 ) ;
F_66 ( V_103 , V_82 -> V_134 ) ;
F_66 ( V_104 , V_82 -> V_134 ) ;
if ( F_56 ( V_15 -> V_22 ) ) {
F_66 ( V_105 , V_82 -> V_134 ) ;
F_66 ( V_106 , V_82 -> V_134 ) ;
}
if ( F_44 ( V_15 -> V_22 ) )
F_66 ( V_107 , V_82 -> V_134 ) ;
if ( F_45 ( V_15 -> V_22 ) ||
F_44 ( V_15 -> V_22 ) ) {
F_66 ( V_96 , V_82 -> V_134 ) ;
F_66 ( V_95 , V_82 -> V_134 ) ;
}
for ( V_94 = 0 ; V_94 < F_14 ( V_15 -> V_23 ) ; V_94 ++ )
F_66 ( V_108 + V_94 , V_82 -> V_134 ) ;
F_70 ( V_135 , V_82 -> V_129 ) ;
F_70 ( V_136 , V_82 -> V_137 ) ;
F_70 ( V_138 , V_82 -> V_137 ) ;
F_69 ( V_82 , V_98 , V_15 -> V_33 ) ;
F_69 ( V_82 , V_99 , V_15 -> V_34 ) ;
if ( F_43 ( V_15 -> V_24 ) ) {
F_66 ( V_139 , V_82 -> V_127 ) ;
F_70 ( V_104 , V_82 -> V_134 ) ;
F_70 ( V_107 , V_82 -> V_134 ) ;
}
}
static void F_71 ( struct V_1 * V_1 )
{
F_5 ( V_1 ) ;
F_72 ( V_1 -> V_16 ) ;
V_1 -> V_16 = NULL ;
}
static int F_73 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
struct V_14 V_140 = * V_15 ;
int V_141 = 0 ;
int error ;
do {
F_74 ( V_1 ) ;
error = F_4 ( V_1 , 0 ) ;
} while ( error && ++ V_141 < 3 );
if ( error )
return - 1 ;
if ( V_141 > 1 )
F_13 ( V_142 L_17 ,
V_141 ) ;
if ( F_21 ( V_1 ) ) {
F_13 ( V_27 L_18 ) ;
return - 1 ;
}
if ( F_22 ( V_1 ) ) {
F_13 ( V_27 L_19 ) ;
return - 1 ;
}
if ( F_24 ( V_1 ) ) {
F_13 ( V_27 L_20 ) ;
return - 1 ;
}
if ( V_140 . V_25 != V_15 -> V_25 ||
V_140 . V_19 != V_15 -> V_19 ||
V_140 . V_22 != V_15 -> V_22 ||
V_140 . V_23 != V_15 -> V_23 ) {
F_13 ( V_27 L_21
L_22 ,
V_140 . V_25 , V_15 -> V_25 ,
V_140 . V_19 , V_15 -> V_19 ,
V_140 . V_22 , V_15 -> V_22 ,
V_140 . V_23 , V_15 -> V_23 ) ;
return - 1 ;
}
return 0 ;
}
void T_2 F_75 ( void )
{
V_143 = F_76 ( V_144 ) ;
V_145 = F_76 ( V_146 ) ;
}
int F_77 ( struct V_1 * V_1 )
{
struct V_14 * V_15 ;
if ( V_145 ) {
F_13 ( V_59 L_23 ) ;
return - V_10 ;
}
V_1 -> V_16 = V_15 = F_38 ( sizeof( struct V_14 ) , V_60 ) ;
if ( ! V_15 )
return - V_147 ;
F_74 ( V_1 ) ;
if ( F_21 ( V_1 ) ) {
F_13 ( V_27 L_18 ) ;
goto V_148;
}
if ( F_22 ( V_1 ) ) {
F_13 ( V_27 L_19 ) ;
goto V_148;
}
if ( F_24 ( V_1 ) ) {
F_13 ( V_27 L_24 ) ;
goto V_148;
}
V_15 -> V_110 = F_42 ( V_15 -> V_19 ) ? V_116 : V_119 ;
F_13 ( V_59 L_25 ,
F_78 ( V_15 -> V_25 ) ,
F_18 ( V_15 -> V_25 ) , F_79 ( V_15 -> V_25 ) ,
V_15 -> V_19 , V_15 -> V_22 , V_15 -> V_23 , V_15 -> V_24 ) ;
F_64 ( V_1 -> V_82 , V_15 ) ;
V_1 -> V_149 = ( ( V_15 -> V_19 & 0x00ff0000 ) >> 8 ) |
( V_15 -> V_19 & 0x000000ff ) ;
V_1 -> V_150 = F_61 ;
V_1 -> V_151 = F_23 ;
V_1 -> V_152 = F_71 ;
V_1 -> V_153 = F_73 ;
V_1 -> V_154 = F_5 ;
V_1 -> V_57 = 6 ;
V_1 -> V_155 = 0 ;
if ( F_63 ( V_15 -> V_22 ) )
F_37 ( V_1 ) ;
if ( V_1 -> V_44 >= 80 && V_143 ) {
F_13 ( V_59 L_26 ,
F_80 ( V_156 ) ) ;
V_1 -> V_44 = 40 ;
}
return 0 ;
V_148:
F_72 ( V_15 ) ;
return - 1 ;
}
bool F_81 ( void )
{
return true ;
}
void T_2 F_75 ( void )
{
}
int F_77 ( struct V_1 * V_1 )
{
return - V_157 ;
}
bool F_81 ( void )
{
return false ;
}
