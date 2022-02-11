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
unsigned char V_32 [ 3 ] ;
if ( F_18 ( V_15 -> V_25 ) < 4 )
return 0 ;
if ( F_6 ( V_1 , V_33 , V_31 ) == 0 ) {
if ( V_31 [ 0 ] != 0 && ( V_31 [ 1 ] & 0x80 ) && V_31 [ 2 ] != 0 ) {
V_15 -> V_34 = V_31 [ 0 ] ;
V_15 -> V_35 = V_31 [ 2 ] ;
}
}
if ( F_12 ( V_15 -> V_22 ) >= 5 &&
F_19 ( V_15 -> V_24 ) ) {
if ( F_6 ( V_1 , V_36 , V_32 ) ) {
F_13 ( V_27 L_7
L_6 ) ;
} else {
V_15 -> V_37 = ( V_32 [ 0 ] << 5 ) | ( ( V_32 [ 1 ] & 0x0f ) << 1 ) ;
V_15 -> V_38 = ( V_32 [ 2 ] << 5 ) | ( ( V_32 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
return 0 ;
}
static int F_20 ( struct V_1 * V_1 )
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
static int F_21 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
V_15 -> V_2 = V_39 ;
if ( F_18 ( V_15 -> V_25 ) >= 4 )
V_15 -> V_2 |= V_40 ;
if ( F_11 ( V_15 -> V_22 ) )
V_15 -> V_2 |= V_41 ;
if ( F_1 ( V_1 , V_15 -> V_2 ) )
return - 1 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_1 , unsigned int V_42 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
if ( V_42 >= 80 ) {
V_15 -> V_2 |= V_43 ;
V_1 -> V_42 = 80 ;
} else {
V_15 -> V_2 &= ~ V_43 ;
V_1 -> V_42 = 40 ;
}
F_1 ( V_1 , V_15 -> V_2 ) ;
}
static int F_23 ( struct V_1 * V_1 )
{
static unsigned char V_3 = 0xc8 ;
struct V_14 * V_15 = V_1 -> V_16 ;
if ( ! F_24 ( V_15 -> V_24 ) )
return 0 ;
if ( F_2 ( V_1 , V_18 ) )
return - 1 ;
if ( F_3 ( & V_1 -> V_5 , & V_3 , V_6 ) )
return - 1 ;
V_15 -> V_22 |= F_25 ( 1 ) ;
return 0 ;
}
static int F_26 ( struct V_44 * V_44 , unsigned char V_13 )
{
struct V_1 * V_45 = F_27 ( V_44 -> V_45 ) ;
char V_46 = V_47 ;
if ( F_2 ( V_45 , V_13 ) )
return - 1 ;
if ( F_3 ( & V_45 -> V_5 , & V_46 , V_6 ) )
return - 1 ;
return 0 ;
}
static int F_28 ( struct V_44 * V_44 )
{
struct V_1 * V_45 = F_27 ( V_44 -> V_45 ) ;
struct V_14 * V_15 = V_45 -> V_16 ;
F_29 ( V_45 -> V_5 . V_44 ) ;
V_15 -> V_48 = V_44 ;
F_30 ( V_45 -> V_5 . V_44 ) ;
return 0 ;
}
static void F_31 ( struct V_44 * V_44 )
{
struct V_1 * V_45 = F_27 ( V_44 -> V_45 ) ;
struct V_14 * V_15 = V_45 -> V_16 ;
F_29 ( V_45 -> V_5 . V_44 ) ;
V_15 -> V_48 = NULL ;
F_30 ( V_45 -> V_5 . V_44 ) ;
}
static int F_32 ( unsigned char * V_49 )
{
return ( V_49 [ 0 ] & 0xFC ) == 0x84 && ( V_49 [ 3 ] & 0xCC ) == 0xC4 ;
}
static void F_33 ( struct V_44 * V_50 , unsigned char * V_51 )
{
struct V_1 * V_52 = F_27 ( V_50 ) ;
if ( V_52 && V_52 -> V_53 == V_54 ) {
F_34 ( V_50 , V_51 [ 1 ] , 0 ) ;
F_34 ( V_50 , V_51 [ 4 ] , 0 ) ;
F_34 ( V_50 , V_51 [ 5 ] , 0 ) ;
if ( V_52 -> V_55 == 4 )
F_34 ( V_50 , V_51 [ 2 ] , 0 ) ;
} else
F_34 ( V_50 , V_51 [ 1 ] , 0 ) ;
}
static void F_35 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
struct V_1 * V_52 = F_27 ( V_15 -> V_48 ) ;
if ( V_52 ) {
if ( V_52 -> V_55 == 4 )
V_15 -> V_2 |= V_56 ;
else
V_15 -> V_2 &= ~ V_56 ;
if ( F_1 ( V_1 , V_15 -> V_2 ) )
F_13 ( V_57 L_8 ) ;
}
}
static void F_36 ( struct V_1 * V_1 )
{
struct V_44 * V_44 ;
V_44 = F_37 ( sizeof( struct V_44 ) , V_58 ) ;
if ( ! V_44 ) {
F_13 ( V_27 L_9 ) ;
return;
}
V_44 -> V_29 . type = V_59 ;
F_38 ( V_44 -> V_12 , L_10 , sizeof( V_44 -> V_12 ) ) ;
F_38 ( V_44 -> V_60 , L_11 , sizeof( V_44 -> V_12 ) ) ;
V_44 -> V_61 = F_26 ;
V_44 -> V_62 = F_28 ;
V_44 -> V_63 = F_31 ;
V_44 -> V_45 = V_1 -> V_5 . V_44 ;
V_1 -> V_64 = F_35 ;
F_13 ( V_57 L_12 , V_44 -> V_12 , V_1 -> V_60 ) ;
F_39 ( V_44 ) ;
}
static int F_40 ( const unsigned char V_49 [] ,
struct V_14 * V_15 ,
struct V_65 * V_66 )
{
memset ( V_66 , 0 , sizeof( struct V_65 ) ) ;
if ( F_41 ( V_15 -> V_19 ) ) {
V_66 -> V_67 = ( ( ( V_49 [ 3 ] & 0x10 ) << 8 ) |
( ( V_49 [ 1 ] & 0x0f ) << 8 ) |
V_49 [ 4 ] ) ;
V_66 -> V_68 = ( ( ( V_49 [ 3 ] & 0x20 ) << 7 ) |
( ( V_49 [ 1 ] & 0xf0 ) << 4 ) |
V_49 [ 5 ] ) ;
V_66 -> V_69 = V_49 [ 2 ] ;
V_66 -> V_70 = ( ( ( V_49 [ 0 ] & 0x30 ) >> 2 ) |
( ( V_49 [ 0 ] & 0x04 ) >> 1 ) |
( ( V_49 [ 3 ] & 0x04 ) >> 2 ) ) ;
if ( F_24 ( V_15 -> V_24 ) && V_66 -> V_70 == 2 ) {
V_15 -> V_71 . V_67 = ( ( ( V_49 [ 4 ] & 0x0f ) << 8 ) | V_49 [ 1 ] ) << 1 ;
V_15 -> V_71 . V_68 = ( ( ( V_49 [ 4 ] & 0xf0 ) << 4 ) | V_49 [ 2 ] ) << 1 ;
V_15 -> V_71 . V_69 = ( ( V_49 [ 3 ] & 0x30 ) | ( V_49 [ 5 ] & 0x0f ) ) << 1 ;
return 1 ;
}
V_66 -> V_72 = ( V_49 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_66 -> V_73 = ( V_49 [ 0 ] & 0x02 ) ? 1 : 0 ;
if ( F_42 ( V_15 -> V_24 ) ) {
V_66 -> V_72 = ( ( V_49 [ 0 ] ^ V_49 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
} else if ( F_43 ( V_15 -> V_22 ) ) {
V_66 -> V_74 = ( ( V_49 [ 0 ] ^ V_49 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
if ( V_66 -> V_70 == 2 )
V_66 -> V_75 = ( signed char ) ( V_49 [ 1 ] ) ;
}
if ( F_44 ( V_15 -> V_22 ) ) {
V_66 -> V_76 = ( ( V_49 [ 0 ] ^ V_49 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
V_66 -> V_77 = ( ( V_49 [ 0 ] ^ V_49 [ 3 ] ) & 0x02 ) ? 1 : 0 ;
}
if ( F_14 ( V_15 -> V_23 ) &&
( ( V_49 [ 0 ] ^ V_49 [ 3 ] ) & 0x02 ) ) {
switch ( F_14 ( V_15 -> V_23 ) & ~ 0x01 ) {
default:
break;
case 8 :
V_66 -> V_78 |= ( ( V_49 [ 5 ] & 0x08 ) ) ? 0x80 : 0 ;
V_66 -> V_78 |= ( ( V_49 [ 4 ] & 0x08 ) ) ? 0x40 : 0 ;
case 6 :
V_66 -> V_78 |= ( ( V_49 [ 5 ] & 0x04 ) ) ? 0x20 : 0 ;
V_66 -> V_78 |= ( ( V_49 [ 4 ] & 0x04 ) ) ? 0x10 : 0 ;
case 4 :
V_66 -> V_78 |= ( ( V_49 [ 5 ] & 0x02 ) ) ? 0x08 : 0 ;
V_66 -> V_78 |= ( ( V_49 [ 4 ] & 0x02 ) ) ? 0x04 : 0 ;
case 2 :
V_66 -> V_78 |= ( ( V_49 [ 5 ] & 0x01 ) ) ? 0x02 : 0 ;
V_66 -> V_78 |= ( ( V_49 [ 4 ] & 0x01 ) ) ? 0x01 : 0 ;
}
}
} else {
V_66 -> V_67 = ( ( ( V_49 [ 1 ] & 0x1f ) << 8 ) | V_49 [ 2 ] ) ;
V_66 -> V_68 = ( ( ( V_49 [ 4 ] & 0x1f ) << 8 ) | V_49 [ 5 ] ) ;
V_66 -> V_69 = ( ( ( V_49 [ 0 ] & 0x30 ) << 2 ) | ( V_49 [ 3 ] & 0x3F ) ) ;
V_66 -> V_70 = ( ( ( V_49 [ 1 ] & 0x80 ) >> 4 ) | ( ( V_49 [ 0 ] & 0x04 ) >> 1 ) ) ;
V_66 -> V_72 = ( V_49 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_66 -> V_73 = ( V_49 [ 0 ] & 0x02 ) ? 1 : 0 ;
}
return 0 ;
}
static void F_45 ( struct V_79 * V_80 , int V_81 , bool V_82 , int V_67 , int V_68 )
{
F_46 ( V_80 , V_81 ) ;
F_47 ( V_80 , V_83 , V_82 ) ;
if ( V_82 ) {
F_48 ( V_80 , V_84 , V_67 ) ;
F_48 ( V_80 , V_85 ,
V_86 + V_87 - V_68 ) ;
}
}
static void F_49 ( struct V_79 * V_80 ,
const struct V_65 * V_88 ,
const struct V_65 * V_89 ,
int V_90 )
{
if ( V_90 >= 2 ) {
F_45 ( V_80 , 0 , true , F_50 ( V_88 -> V_67 , V_89 -> V_67 ) , F_50 ( V_88 -> V_68 , V_89 -> V_68 ) ) ;
F_45 ( V_80 , 1 , true , V_32 ( V_88 -> V_67 , V_89 -> V_67 ) , V_32 ( V_88 -> V_68 , V_89 -> V_68 ) ) ;
} else if ( V_90 == 1 ) {
F_45 ( V_80 , 0 , true , V_88 -> V_67 , V_88 -> V_68 ) ;
F_45 ( V_80 , 1 , false , 0 , 0 ) ;
} else {
F_45 ( V_80 , 0 , false , 0 , 0 ) ;
F_45 ( V_80 , 1 , false , 0 , 0 ) ;
}
}
static void F_51 ( struct V_1 * V_1 )
{
struct V_79 * V_80 = V_1 -> V_80 ;
struct V_14 * V_15 = V_1 -> V_16 ;
struct V_65 V_66 ;
int V_90 ;
int V_91 ;
int V_92 ;
if ( F_40 ( V_1 -> V_51 , V_15 , & V_66 ) )
return;
if ( V_66 . V_75 ) {
V_15 -> V_75 += V_66 . V_75 ;
while ( V_15 -> V_75 >= 4 ) {
F_52 ( V_80 , V_93 , ! V_66 . V_77 ) ;
F_53 ( V_80 ) ;
F_52 ( V_80 , V_93 , V_66 . V_77 ) ;
F_53 ( V_80 ) ;
V_15 -> V_75 -= 4 ;
}
while ( V_15 -> V_75 <= - 4 ) {
F_52 ( V_80 , V_94 , ! V_66 . V_76 ) ;
F_53 ( V_80 ) ;
F_52 ( V_80 , V_94 , V_66 . V_76 ) ;
F_53 ( V_80 ) ;
V_15 -> V_75 += 4 ;
}
return;
}
if ( V_66 . V_69 > 0 && V_66 . V_67 > 1 ) {
V_90 = 1 ;
V_91 = 5 ;
if ( F_11 ( V_15 -> V_22 ) ) {
switch ( V_66 . V_70 ) {
case 0 ... 1 :
if ( F_54 ( V_15 -> V_22 ) )
V_90 = V_66 . V_70 + 2 ;
break;
case 2 :
if ( F_55 ( V_15 -> V_19 ) )
;
break;
case 4 ... 15 :
if ( F_56 ( V_15 -> V_22 ) )
V_91 = V_66 . V_70 ;
break;
}
}
} else {
V_90 = 0 ;
V_91 = 0 ;
}
if ( F_24 ( V_15 -> V_24 ) )
F_49 ( V_80 , & V_66 , & V_15 -> V_71 , V_90 ) ;
if ( V_66 . V_69 > 30 ) F_52 ( V_80 , V_95 , 1 ) ;
if ( V_66 . V_69 < 25 ) F_52 ( V_80 , V_95 , 0 ) ;
if ( V_90 > 0 ) {
F_48 ( V_80 , V_96 , V_66 . V_67 ) ;
F_48 ( V_80 , V_97 , V_86 + V_87 - V_66 . V_68 ) ;
}
F_48 ( V_80 , V_98 , V_66 . V_69 ) ;
if ( F_56 ( V_15 -> V_22 ) )
F_48 ( V_80 , V_99 , V_91 ) ;
F_52 ( V_80 , V_100 , V_90 == 1 ) ;
F_52 ( V_80 , V_101 , V_66 . V_72 ) ;
F_52 ( V_80 , V_102 , V_66 . V_73 ) ;
if ( F_54 ( V_15 -> V_22 ) ) {
F_52 ( V_80 , V_103 , V_90 == 2 ) ;
F_52 ( V_80 , V_104 , V_90 == 3 ) ;
}
if ( F_43 ( V_15 -> V_22 ) )
F_52 ( V_80 , V_105 , V_66 . V_74 ) ;
if ( F_44 ( V_15 -> V_22 ) ) {
F_52 ( V_80 , V_94 , V_66 . V_76 ) ;
F_52 ( V_80 , V_93 , V_66 . V_77 ) ;
}
for ( V_92 = 0 ; V_92 < F_14 ( V_15 -> V_23 ) ; V_92 ++ )
F_52 ( V_80 , V_106 + V_92 , V_66 . V_78 & ( 1 << V_92 ) ) ;
F_53 ( V_80 ) ;
}
static int F_57 ( unsigned char V_51 [] , int V_107 , unsigned char V_108 )
{
static const unsigned char V_109 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const unsigned char V_110 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_111 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_112 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const unsigned char V_113 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
if ( V_107 < 0 || V_107 > 4 )
return 0 ;
switch ( V_108 ) {
case V_114 :
case V_115 :
return ( V_51 [ V_107 ] & V_110 [ V_107 ] ) == V_111 [ V_107 ] ;
case V_116 :
return ( V_51 [ V_107 ] & V_109 [ V_107 ] ) == V_111 [ V_107 ] ;
case V_117 :
return ( V_51 [ V_107 ] & V_112 [ V_107 ] ) == V_113 [ V_107 ] ;
default:
F_13 ( V_27 L_13 , V_108 ) ;
return 0 ;
}
}
static unsigned char F_58 ( struct V_1 * V_1 )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < 5 ; V_92 ++ )
if ( ! F_57 ( V_1 -> V_51 , V_92 , V_116 ) ) {
F_13 ( V_57 L_14 ) ;
return V_115 ;
}
return V_116 ;
}
static T_1 F_59 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
if ( V_1 -> V_118 >= 6 ) {
if ( F_60 ( V_15 -> V_108 == V_114 ) )
V_15 -> V_108 = F_58 ( V_1 ) ;
if ( F_61 ( V_15 -> V_22 ) &&
F_32 ( V_1 -> V_51 ) ) {
if ( V_15 -> V_48 )
F_33 ( V_15 -> V_48 , V_1 -> V_51 ) ;
} else
F_51 ( V_1 ) ;
return V_119 ;
}
return F_57 ( V_1 -> V_51 , V_1 -> V_118 - 1 , V_15 -> V_108 ) ?
V_120 : V_121 ;
}
static void F_62 ( struct V_79 * V_80 , struct V_14 * V_15 )
{
int V_92 ;
F_63 ( V_122 , V_80 -> V_123 ) ;
F_63 ( V_124 , V_80 -> V_125 ) ;
F_64 ( V_80 , V_96 ,
V_126 , V_15 -> V_37 ? : V_127 , 0 , 0 ) ;
F_64 ( V_80 , V_97 ,
V_87 , V_15 -> V_38 ? : V_86 , 0 , 0 ) ;
F_64 ( V_80 , V_98 , 0 , 255 , 0 , 0 ) ;
if ( F_24 ( V_15 -> V_24 ) ) {
F_63 ( V_128 , V_80 -> V_123 ) ;
F_65 ( V_80 , 2 ) ;
F_64 ( V_80 , V_84 , V_126 ,
V_15 -> V_37 ? : V_127 , 0 , 0 ) ;
F_64 ( V_80 , V_85 , V_87 ,
V_15 -> V_38 ? : V_86 , 0 , 0 ) ;
}
if ( F_56 ( V_15 -> V_22 ) )
F_64 ( V_80 , V_99 , 0 , 15 , 0 , 0 ) ;
F_63 ( V_129 , V_80 -> V_125 ) ;
F_63 ( V_95 , V_80 -> V_130 ) ;
F_63 ( V_100 , V_80 -> V_130 ) ;
F_63 ( V_101 , V_80 -> V_130 ) ;
F_63 ( V_102 , V_80 -> V_130 ) ;
if ( F_54 ( V_15 -> V_22 ) ) {
F_63 ( V_103 , V_80 -> V_130 ) ;
F_63 ( V_104 , V_80 -> V_130 ) ;
}
if ( F_43 ( V_15 -> V_22 ) )
F_63 ( V_105 , V_80 -> V_130 ) ;
if ( F_44 ( V_15 -> V_22 ) ||
F_43 ( V_15 -> V_22 ) ) {
F_63 ( V_94 , V_80 -> V_130 ) ;
F_63 ( V_93 , V_80 -> V_130 ) ;
}
for ( V_92 = 0 ; V_92 < F_14 ( V_15 -> V_23 ) ; V_92 ++ )
F_63 ( V_106 + V_92 , V_80 -> V_130 ) ;
F_66 ( V_131 , V_80 -> V_125 ) ;
F_66 ( V_132 , V_80 -> V_133 ) ;
F_66 ( V_134 , V_80 -> V_133 ) ;
F_67 ( V_80 , V_96 , V_15 -> V_34 ) ;
F_67 ( V_80 , V_97 , V_15 -> V_35 ) ;
if ( F_42 ( V_15 -> V_24 ) ) {
F_63 ( V_135 , V_80 -> V_123 ) ;
F_66 ( V_102 , V_80 -> V_130 ) ;
F_66 ( V_105 , V_80 -> V_130 ) ;
}
}
static void F_68 ( struct V_1 * V_1 )
{
F_5 ( V_1 ) ;
F_69 ( V_1 -> V_16 ) ;
V_1 -> V_16 = NULL ;
}
static int F_70 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_16 ;
struct V_14 V_136 = * V_15 ;
int V_137 = 0 ;
int error ;
do {
F_71 ( V_1 ) ;
error = F_4 ( V_1 , 0 ) ;
} while ( error && ++ V_137 < 3 );
if ( error )
return - 1 ;
if ( V_137 > 1 )
F_13 ( V_138 L_15 ,
V_137 ) ;
if ( F_20 ( V_1 ) ) {
F_13 ( V_27 L_16 ) ;
return - 1 ;
}
if ( F_21 ( V_1 ) ) {
F_13 ( V_27 L_17 ) ;
return - 1 ;
}
if ( F_23 ( V_1 ) ) {
F_13 ( V_27 L_18 ) ;
return - 1 ;
}
if ( V_136 . V_25 != V_15 -> V_25 ||
V_136 . V_19 != V_15 -> V_19 ||
V_136 . V_22 != V_15 -> V_22 ||
V_136 . V_23 != V_15 -> V_23 ) {
F_13 ( V_27 L_19
L_20 ,
V_136 . V_25 , V_15 -> V_25 ,
V_136 . V_19 , V_15 -> V_19 ,
V_136 . V_22 , V_15 -> V_22 ,
V_136 . V_23 , V_15 -> V_23 ) ;
return - 1 ;
}
return 0 ;
}
void T_2 F_72 ( void )
{
V_139 = F_73 ( V_140 ) ;
V_141 = F_73 ( V_142 ) ;
}
int F_74 ( struct V_1 * V_1 )
{
struct V_14 * V_15 ;
if ( V_141 ) {
F_13 ( V_57 L_21 ) ;
return - V_10 ;
}
V_1 -> V_16 = V_15 = F_37 ( sizeof( struct V_14 ) , V_58 ) ;
if ( ! V_15 )
return - V_143 ;
F_71 ( V_1 ) ;
if ( F_20 ( V_1 ) ) {
F_13 ( V_27 L_16 ) ;
goto V_144;
}
if ( F_21 ( V_1 ) ) {
F_13 ( V_27 L_17 ) ;
goto V_144;
}
if ( F_23 ( V_1 ) ) {
F_13 ( V_27 L_22 ) ;
goto V_144;
}
V_15 -> V_108 = F_41 ( V_15 -> V_19 ) ? V_114 : V_117 ;
F_13 ( V_57 L_23 ,
F_75 ( V_15 -> V_25 ) ,
F_18 ( V_15 -> V_25 ) , F_76 ( V_15 -> V_25 ) ,
V_15 -> V_19 , V_15 -> V_22 , V_15 -> V_23 , V_15 -> V_24 ) ;
F_62 ( V_1 -> V_80 , V_15 ) ;
V_1 -> V_145 = ( ( V_15 -> V_19 & 0x00ff0000 ) >> 8 ) |
( V_15 -> V_19 & 0x000000ff ) ;
V_1 -> V_146 = F_59 ;
V_1 -> V_147 = F_22 ;
V_1 -> V_148 = F_68 ;
V_1 -> V_149 = F_70 ;
V_1 -> V_150 = F_5 ;
V_1 -> V_55 = 6 ;
V_1 -> V_151 = 0 ;
if ( F_61 ( V_15 -> V_22 ) )
F_36 ( V_1 ) ;
if ( V_1 -> V_42 >= 80 && V_139 ) {
F_13 ( V_57 L_24 ,
F_77 ( V_152 ) ) ;
V_1 -> V_42 = 40 ;
}
return 0 ;
V_144:
F_69 ( V_15 ) ;
return - 1 ;
}
bool F_78 ( void )
{
return true ;
}
void T_2 F_72 ( void )
{
}
int F_74 ( struct V_1 * V_1 )
{
return - V_153 ;
}
bool F_78 ( void )
{
return false ;
}
