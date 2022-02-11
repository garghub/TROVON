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
static bool F_6 ( struct V_1 * V_1 , const char * const V_13 [] )
{
int V_14 ;
if ( ! strncmp ( V_1 -> V_5 . V_15 -> V_16 , L_3 , 4 ) )
for ( V_14 = 0 ; V_13 [ V_14 ] ; V_14 ++ )
if ( strstr ( V_1 -> V_5 . V_15 -> V_16 , V_13 [ V_14 ] ) )
return true ;
return false ;
}
static int F_7 ( int V_17 )
{
return V_18 + V_19 - V_17 ;
}
static int F_8 ( struct V_1 * V_1 , unsigned char V_20 , unsigned char * V_3 )
{
if ( F_2 ( V_1 , V_20 ) )
return - 1 ;
if ( F_3 ( & V_1 -> V_5 , V_3 , V_9 ) )
return - 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
unsigned char V_24 [ 3 ] ;
if ( F_8 ( V_1 , V_25 , V_24 ) )
return - 1 ;
V_22 -> V_26 = ( V_24 [ 0 ] << 16 ) | ( V_24 [ 1 ] << 8 ) | V_24 [ 2 ] ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
unsigned char V_27 [ 3 ] ;
if ( F_8 ( V_1 , V_28 , V_27 ) )
return - 1 ;
V_22 -> V_29 = ( ( V_27 [ 0 ] & 0xfc ) << 6 ) | V_27 [ 1 ] ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
unsigned char V_30 [ 3 ] ;
if ( F_8 ( V_1 , V_31 , V_30 ) )
return - 1 ;
V_22 -> V_16 = ( V_30 [ 0 ] << 16 ) | ( V_30 [ 1 ] << 8 ) | V_30 [ 2 ] ;
return 0 ;
}
static int F_12 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
unsigned char V_32 [ 3 ] ;
if ( F_8 ( V_1 , V_33 , V_32 ) )
return - 1 ;
V_22 -> V_34 = ( V_32 [ 0 ] << 16 ) | ( V_32 [ 1 ] << 8 ) | V_32 [ 2 ] ;
V_22 -> V_35 = V_22 -> V_36 = 0 ;
if ( F_13 ( V_22 -> V_37 ) < 0x705 &&
F_14 ( V_22 -> V_34 ) != 0x47 ) {
return - 1 ;
}
if ( ! F_15 ( V_22 -> V_34 ) )
V_22 -> V_34 = 0 ;
if ( F_16 ( V_22 -> V_34 ) >= 1 ) {
if ( F_8 ( V_1 , V_38 , V_32 ) ) {
F_17 ( V_1 ,
L_4 ) ;
} else {
V_22 -> V_35 = ( V_32 [ 0 ] << 16 ) | ( V_32 [ 1 ] << 8 ) | V_32 [ 2 ] ;
if ( F_18 ( V_22 -> V_35 ) > 8 )
V_22 -> V_35 &= 0xff0fff ;
}
}
if ( F_16 ( V_22 -> V_34 ) >= 4 ) {
if ( F_8 ( V_1 , V_39 , V_32 ) ) {
F_17 ( V_1 ,
L_5 ) ;
} else {
V_22 -> V_36 = ( V_32 [ 0 ] << 16 ) | ( V_32 [ 1 ] << 8 ) | V_32 [ 2 ] ;
}
}
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
unsigned char V_40 [ 3 ] ;
if ( F_8 ( V_1 , V_41 , V_40 ) )
return - 1 ;
V_22 -> V_37 = ( V_40 [ 0 ] << 16 ) | ( V_40 [ 1 ] << 8 ) | V_40 [ 2 ] ;
if ( F_20 ( V_22 -> V_37 ) )
return 0 ;
return - 1 ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
unsigned char V_42 [ 3 ] ;
int V_14 ;
if ( F_22 ( V_22 -> V_37 ) < 4 )
return 0 ;
if ( F_8 ( V_1 , V_43 , V_42 ) == 0 ) {
if ( V_42 [ 0 ] != 0 && ( V_42 [ 1 ] & 0x80 ) && V_42 [ 2 ] != 0 ) {
V_22 -> V_44 = V_42 [ 0 ] ;
V_22 -> V_45 = V_42 [ 2 ] ;
}
}
for ( V_14 = 0 ; V_46 [ V_14 ] . V_47 ; V_14 ++ ) {
if ( F_6 ( V_1 , V_46 [ V_14 ] . V_47 ) ) {
V_22 -> V_48 = V_46 [ V_14 ] . V_48 ;
V_22 -> V_49 = V_46 [ V_14 ] . V_49 ;
V_22 -> V_50 = V_46 [ V_14 ] . V_50 ;
V_22 -> V_51 = V_46 [ V_14 ] . V_51 ;
return 0 ;
}
}
if ( F_16 ( V_22 -> V_34 ) >= 5 &&
F_23 ( V_22 -> V_36 ) ) {
if ( F_8 ( V_1 , V_52 , V_42 ) ) {
F_17 ( V_1 ,
L_6 ) ;
} else {
V_22 -> V_49 = ( V_42 [ 0 ] << 5 ) | ( ( V_42 [ 1 ] & 0x0f ) << 1 ) ;
V_22 -> V_51 = ( V_42 [ 2 ] << 5 ) | ( ( V_42 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
if ( F_16 ( V_22 -> V_34 ) >= 7 &&
F_24 ( V_22 -> V_36 ) ) {
if ( F_8 ( V_1 , V_53 , V_42 ) ) {
F_17 ( V_1 ,
L_7 ) ;
} else {
V_22 -> V_48 = ( V_42 [ 0 ] << 5 ) | ( ( V_42 [ 1 ] & 0x0f ) << 1 ) ;
V_22 -> V_50 = ( V_42 [ 2 ] << 5 ) | ( ( V_42 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
if ( F_19 ( V_1 ) )
return - 1 ;
if ( F_9 ( V_1 ) )
return - 1 ;
if ( F_11 ( V_1 ) )
return - 1 ;
if ( F_10 ( V_1 ) )
return - 1 ;
if ( F_12 ( V_1 ) )
return - 1 ;
if ( F_21 ( V_1 ) )
return - 1 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 )
{
static unsigned char V_3 = 0xc8 ;
struct V_21 * V_22 = V_1 -> V_23 ;
if ( ! ( F_27 ( V_22 -> V_36 ) ||
F_28 ( V_22 -> V_36 ) ) )
return 0 ;
if ( F_2 ( V_1 , V_25 ) )
return - 1 ;
if ( F_3 ( & V_1 -> V_5 , & V_3 , V_6 ) )
return - 1 ;
V_22 -> V_34 |= F_29 ( 1 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
V_22 -> V_2 = 0 ;
if ( V_22 -> V_54 )
V_22 -> V_2 |= V_55 ;
if ( V_22 -> V_56 )
V_22 -> V_2 |= V_57 ;
if ( V_1 -> V_58 >= 80 )
V_22 -> V_2 |= V_59 ;
if ( F_15 ( V_22 -> V_34 ) )
V_22 -> V_2 |= V_60 ;
if ( F_1 ( V_1 , V_22 -> V_2 ) )
return - 1 ;
if ( V_22 -> V_54 &&
F_26 ( V_1 ) ) {
F_31 ( V_1 , L_8 ) ;
return - 1 ;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_1 , unsigned int V_58 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
if ( V_58 >= 80 ) {
V_22 -> V_2 |= V_59 ;
V_1 -> V_58 = 80 ;
} else {
V_22 -> V_2 &= ~ V_59 ;
V_1 -> V_58 = 40 ;
}
F_1 ( V_1 , V_22 -> V_2 ) ;
}
static int F_33 ( struct V_15 * V_15 , unsigned char V_20 )
{
struct V_1 * V_61 = F_34 ( V_15 -> V_61 ) ;
char V_62 = V_63 ;
if ( F_2 ( V_61 , V_20 ) )
return - 1 ;
if ( F_3 ( & V_61 -> V_5 , & V_62 , V_6 ) )
return - 1 ;
return 0 ;
}
static int F_35 ( struct V_15 * V_15 )
{
struct V_1 * V_61 = F_34 ( V_15 -> V_61 ) ;
struct V_21 * V_22 = V_61 -> V_23 ;
F_36 ( V_61 -> V_5 . V_15 ) ;
V_22 -> V_64 = V_15 ;
F_37 ( V_61 -> V_5 . V_15 ) ;
return 0 ;
}
static void F_38 ( struct V_15 * V_15 )
{
struct V_1 * V_61 = F_34 ( V_15 -> V_61 ) ;
struct V_21 * V_22 = V_61 -> V_23 ;
F_36 ( V_61 -> V_5 . V_15 ) ;
V_22 -> V_64 = NULL ;
F_37 ( V_61 -> V_5 . V_15 ) ;
}
static int F_39 ( unsigned char * V_65 )
{
return ( V_65 [ 0 ] & 0xFC ) == 0x84 && ( V_65 [ 3 ] & 0xCC ) == 0xC4 ;
}
static void F_40 ( struct V_15 * V_66 , unsigned char * V_67 )
{
struct V_1 * V_68 = F_34 ( V_66 ) ;
if ( V_68 && V_68 -> V_69 == V_70 ) {
F_41 ( V_66 , V_67 [ 1 ] , 0 ) ;
F_41 ( V_66 , V_67 [ 4 ] , 0 ) ;
F_41 ( V_66 , V_67 [ 5 ] , 0 ) ;
if ( V_68 -> V_71 == 4 )
F_41 ( V_66 , V_67 [ 2 ] , 0 ) ;
} else
F_41 ( V_66 , V_67 [ 1 ] , 0 ) ;
}
static void F_42 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
struct V_1 * V_68 = F_34 ( V_22 -> V_64 ) ;
if ( V_68 ) {
if ( V_68 -> V_71 == 4 )
V_22 -> V_2 |= V_72 ;
else
V_22 -> V_2 &= ~ V_72 ;
if ( F_1 ( V_1 , V_22 -> V_2 ) )
F_17 ( V_1 ,
L_9 ) ;
}
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_15 * V_15 ;
V_15 = F_44 ( sizeof( struct V_15 ) , V_73 ) ;
if ( ! V_15 ) {
F_31 ( V_1 ,
L_10 ) ;
return;
}
V_15 -> V_40 . type = V_74 ;
F_45 ( V_15 -> V_12 , L_11 , sizeof( V_15 -> V_12 ) ) ;
F_45 ( V_15 -> V_75 , L_12 , sizeof( V_15 -> V_12 ) ) ;
V_15 -> V_76 = F_33 ;
V_15 -> V_77 = F_35 ;
V_15 -> V_78 = F_38 ;
V_15 -> V_61 = V_1 -> V_5 . V_15 ;
V_1 -> V_79 = F_42 ;
F_46 ( V_1 , L_13 ,
V_15 -> V_12 , V_1 -> V_75 ) ;
F_47 ( V_15 ) ;
}
static void F_48 ( struct V_80 * V_69 , int V_81 ,
int V_82 , int V_83 )
{
V_69 -> V_81 = V_81 ;
V_69 -> V_82 = V_82 ;
V_69 -> V_83 = V_83 ;
}
static void F_49 ( const unsigned char V_65 [] ,
struct V_21 * V_22 ,
struct V_84 * V_85 )
{
struct V_84 * V_83 = & V_22 -> V_83 ;
int V_86 ;
V_86 = ( V_65 [ 5 ] & 0x30 ) >> 4 ;
switch ( V_86 ) {
case 1 :
V_83 -> V_87 = V_85 -> V_87 ;
V_83 -> V_88 = ( ( ( V_65 [ 4 ] & 0x0f ) << 8 ) | V_65 [ 1 ] ) << 1 ;
V_83 -> V_17 = ( ( ( V_65 [ 4 ] & 0xf0 ) << 4 ) | V_65 [ 2 ] ) << 1 ;
V_83 -> V_89 = ( ( V_65 [ 3 ] & 0x30 ) | ( V_65 [ 5 ] & 0x0f ) ) << 1 ;
break;
case 2 :
F_48 ( & V_83 -> V_90 , V_65 [ 1 ] , V_65 [ 2 ] , V_65 [ 4 ] ) ;
break;
default:
break;
}
V_22 -> V_91 = true ;
}
static int F_50 ( const unsigned char V_65 [] ,
struct V_21 * V_22 ,
struct V_84 * V_85 )
{
memset ( V_85 , 0 , sizeof( struct V_84 ) ) ;
if ( F_51 ( V_22 -> V_26 ) ) {
V_85 -> V_87 = ( ( ( V_65 [ 0 ] & 0x30 ) >> 2 ) |
( ( V_65 [ 0 ] & 0x04 ) >> 1 ) |
( ( V_65 [ 3 ] & 0x04 ) >> 2 ) ) ;
if ( ( F_27 ( V_22 -> V_36 ) ||
F_28 ( V_22 -> V_36 ) ) &&
V_85 -> V_87 == 2 ) {
F_49 ( V_65 , V_22 , V_85 ) ;
return 1 ;
}
V_85 -> V_88 = ( ( ( V_65 [ 3 ] & 0x10 ) << 8 ) |
( ( V_65 [ 1 ] & 0x0f ) << 8 ) |
V_65 [ 4 ] ) ;
V_85 -> V_17 = ( ( ( V_65 [ 3 ] & 0x20 ) << 7 ) |
( ( V_65 [ 1 ] & 0xf0 ) << 4 ) |
V_65 [ 5 ] ) ;
V_85 -> V_89 = V_65 [ 2 ] ;
V_85 -> V_92 = ( V_65 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_85 -> V_93 = ( V_65 [ 0 ] & 0x02 ) ? 1 : 0 ;
if ( F_52 ( V_22 -> V_36 ) ) {
if ( V_85 -> V_89 == 0 ) {
V_22 -> V_94 = V_22 -> V_95 = false ;
} else if ( V_85 -> V_87 >= 4 && ( ( V_65 [ 0 ] ^ V_65 [ 3 ] ) & 0x01 ) ) {
if ( ! V_22 -> V_94 ) {
V_22 -> V_96 = V_97 ;
V_22 -> V_94 = true ;
} else if ( F_53 ( V_97 ,
V_22 -> V_96 +
F_54 ( 50 ) ) ) {
V_22 -> V_95 = true ;
}
} else {
V_22 -> V_94 = false ;
}
V_85 -> V_92 = V_22 -> V_95 ;
} else if ( F_55 ( V_22 -> V_36 ) ) {
V_85 -> V_92 = ( ( V_65 [ 0 ] ^ V_65 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
} else if ( F_56 ( V_22 -> V_34 ) ) {
V_85 -> V_98 = ( ( V_65 [ 0 ] ^ V_65 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
if ( V_85 -> V_87 == 2 )
V_85 -> V_99 = ( signed char ) ( V_65 [ 1 ] ) ;
}
if ( F_57 ( V_22 -> V_34 ) ) {
V_85 -> V_100 = ( ( V_65 [ 0 ] ^ V_65 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
V_85 -> V_101 = ( ( V_65 [ 0 ] ^ V_65 [ 3 ] ) & 0x02 ) ? 1 : 0 ;
}
if ( F_18 ( V_22 -> V_35 ) &&
( ( V_65 [ 0 ] ^ V_65 [ 3 ] ) & 0x02 ) ) {
switch ( F_18 ( V_22 -> V_35 ) & ~ 0x01 ) {
default:
break;
case 8 :
V_85 -> V_102 |= ( ( V_65 [ 5 ] & 0x08 ) ) ? 0x80 : 0 ;
V_85 -> V_102 |= ( ( V_65 [ 4 ] & 0x08 ) ) ? 0x40 : 0 ;
case 6 :
V_85 -> V_102 |= ( ( V_65 [ 5 ] & 0x04 ) ) ? 0x20 : 0 ;
V_85 -> V_102 |= ( ( V_65 [ 4 ] & 0x04 ) ) ? 0x10 : 0 ;
case 4 :
V_85 -> V_102 |= ( ( V_65 [ 5 ] & 0x02 ) ) ? 0x08 : 0 ;
V_85 -> V_102 |= ( ( V_65 [ 4 ] & 0x02 ) ) ? 0x04 : 0 ;
case 2 :
V_85 -> V_102 |= ( ( V_65 [ 5 ] & 0x01 ) ) ? 0x02 : 0 ;
V_85 -> V_102 |= ( ( V_65 [ 4 ] & 0x01 ) ) ? 0x01 : 0 ;
}
}
} else {
V_85 -> V_88 = ( ( ( V_65 [ 1 ] & 0x1f ) << 8 ) | V_65 [ 2 ] ) ;
V_85 -> V_17 = ( ( ( V_65 [ 4 ] & 0x1f ) << 8 ) | V_65 [ 5 ] ) ;
V_85 -> V_89 = ( ( ( V_65 [ 0 ] & 0x30 ) << 2 ) | ( V_65 [ 3 ] & 0x3F ) ) ;
V_85 -> V_87 = ( ( ( V_65 [ 1 ] & 0x80 ) >> 4 ) | ( ( V_65 [ 0 ] & 0x04 ) >> 1 ) ) ;
V_85 -> V_92 = ( V_65 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_85 -> V_93 = ( V_65 [ 0 ] & 0x02 ) ? 1 : 0 ;
}
if ( V_85 -> V_88 > V_103 )
V_85 -> V_88 -= 1 << V_104 ;
else if ( V_85 -> V_88 == V_103 )
V_85 -> V_88 = V_105 ;
if ( V_85 -> V_17 > V_106 )
V_85 -> V_17 -= 1 << V_104 ;
else if ( V_85 -> V_17 == V_106 )
V_85 -> V_17 = V_107 ;
return 0 ;
}
static void F_58 ( struct V_108 * V_109 , int V_110 ,
bool V_111 , int V_88 , int V_17 )
{
F_59 ( V_109 , V_110 ) ;
F_60 ( V_109 , V_112 , V_111 ) ;
if ( V_111 ) {
F_61 ( V_109 , V_113 , V_88 ) ;
F_61 ( V_109 , V_114 , F_7 ( V_17 ) ) ;
}
}
static void F_62 ( struct V_108 * V_109 ,
const struct V_84 * V_115 ,
const struct V_84 * V_116 ,
int V_117 )
{
if ( V_117 >= 2 ) {
F_58 ( V_109 , 0 , true , F_63 ( V_115 -> V_88 , V_116 -> V_88 ) ,
F_63 ( V_115 -> V_17 , V_116 -> V_17 ) ) ;
F_58 ( V_109 , 1 , true , F_64 ( V_115 -> V_88 , V_116 -> V_88 ) ,
F_64 ( V_115 -> V_17 , V_116 -> V_17 ) ) ;
} else if ( V_117 == 1 ) {
F_58 ( V_109 , 0 , true , V_115 -> V_88 , V_115 -> V_17 ) ;
F_58 ( V_109 , 1 , false , 0 , 0 ) ;
} else {
F_58 ( V_109 , 0 , false , 0 , 0 ) ;
F_58 ( V_109 , 1 , false , 0 , 0 ) ;
}
}
static void F_65 ( struct V_1 * V_1 ,
const struct V_84 * V_85 )
{
struct V_108 * V_109 = V_1 -> V_109 ;
struct V_21 * V_22 = V_1 -> V_23 ;
int V_14 ;
F_66 ( V_109 , V_118 , V_85 -> V_92 ) ;
F_66 ( V_109 , V_119 , V_85 -> V_93 ) ;
if ( F_56 ( V_22 -> V_34 ) )
F_66 ( V_109 , V_120 , V_85 -> V_98 ) ;
if ( F_57 ( V_22 -> V_34 ) ) {
F_66 ( V_109 , V_121 , V_85 -> V_100 ) ;
F_66 ( V_109 , V_122 , V_85 -> V_101 ) ;
}
for ( V_14 = 0 ; V_14 < F_18 ( V_22 -> V_35 ) ; V_14 ++ )
F_66 ( V_109 , V_123 + V_14 , V_85 -> V_102 & ( 1 << V_14 ) ) ;
}
static void F_67 ( struct V_108 * V_109 , int V_110 ,
const struct V_84 * V_85 )
{
F_59 ( V_109 , V_110 ) ;
F_60 ( V_109 , V_112 , ( V_85 != NULL ) ) ;
if ( ! V_85 )
return;
F_61 ( V_109 , V_113 , V_85 -> V_88 ) ;
F_61 ( V_109 , V_114 , F_7 ( V_85 -> V_17 ) ) ;
F_61 ( V_109 , V_124 , V_85 -> V_89 ) ;
}
static void F_68 ( struct V_1 * V_1 ,
struct V_80 * V_90 ,
const struct V_84 * V_82 )
{
struct V_108 * V_109 = V_1 -> V_109 ;
struct V_21 * V_22 = V_1 -> V_23 ;
struct V_84 * V_83 = & V_22 -> V_83 ;
struct V_80 * V_125 = & V_22 -> V_90 ;
switch ( V_90 -> V_81 ) {
case 0 :
F_67 ( V_109 , 0 , NULL ) ;
F_67 ( V_109 , 1 , NULL ) ;
break;
case 1 :
if ( V_90 -> V_82 == - 1 ) {
F_67 ( V_109 , 0 , NULL ) ;
F_67 ( V_109 , 1 , NULL ) ;
} else if ( V_90 -> V_82 == 0 ) {
F_67 ( V_109 , 0 , V_82 ) ;
F_67 ( V_109 , 1 , NULL ) ;
} else {
F_67 ( V_109 , 0 , NULL ) ;
F_67 ( V_109 , 1 , V_82 ) ;
}
break;
default:
if ( V_90 -> V_82 != - 1 &&
( V_90 -> V_82 == V_125 -> V_82 ||
V_125 -> V_82 == - 1 || V_90 -> V_83 == V_125 -> V_82 ) )
F_67 ( V_109 , 0 , V_82 ) ;
else
F_67 ( V_109 , 0 , NULL ) ;
if ( V_90 -> V_83 != - 1 &&
( V_90 -> V_83 == V_125 -> V_83 ||
( V_125 -> V_83 == - 1 &&
( V_125 -> V_82 == - 1 || V_90 -> V_83 == V_125 -> V_82 ) ) ) )
F_67 ( V_109 , 1 , V_83 ) ;
else
F_67 ( V_109 , 1 , NULL ) ;
break;
}
F_69 ( V_109 , false ) ;
F_70 ( V_109 , V_90 -> V_81 ) ;
F_65 ( V_1 , V_82 ) ;
F_71 ( V_109 ) ;
}
static void F_72 ( struct V_21 * V_22 ,
struct V_80 * V_90 )
{
F_48 ( V_90 , 0 , - 1 , - 1 ) ;
V_22 -> V_126 = false ;
}
static void F_73 ( struct V_21 * V_22 ,
struct V_80 * V_90 )
{
struct V_84 * V_83 = & V_22 -> V_83 ;
struct V_80 * V_125 = & V_22 -> V_90 ;
if ( V_22 -> V_91 && V_83 -> V_89 == 0 ) {
F_48 ( V_90 , 1 , 0 , - 1 ) ;
V_22 -> V_126 = false ;
return;
}
switch ( V_125 -> V_81 ) {
case 0 :
F_48 ( V_90 , 1 , 0 , - 1 ) ;
break;
case 1 :
if ( V_22 -> V_126 ||
( V_22 -> V_91 && V_125 -> V_82 <= 0 ) )
F_48 ( V_90 , 1 , 1 , - 1 ) ;
else if ( V_125 -> V_82 == - 1 )
F_48 ( V_90 , 1 , 0 , - 1 ) ;
break;
case 2 :
if ( V_22 -> V_126 ) {
F_48 ( V_90 , 1 , - 1 , - 1 ) ;
break;
}
F_48 ( V_90 , 1 , V_125 -> V_83 , - 1 ) ;
break;
case 3 :
F_48 ( V_90 , 1 , - 1 , - 1 ) ;
V_22 -> V_126 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_74 ( struct V_21 * V_22 ,
struct V_80 * V_90 )
{
struct V_80 * V_125 = & V_22 -> V_90 ;
switch ( V_125 -> V_81 ) {
case 0 :
F_48 ( V_90 , 2 , 0 , 1 ) ;
break;
case 1 :
if ( V_125 -> V_82 >= 1 )
F_48 ( V_90 , 2 , 0 , V_125 -> V_82 ) ;
else
F_48 ( V_90 , 2 , 0 , 1 ) ;
break;
case 2 :
if ( V_22 -> V_126 )
F_48 ( V_90 , 2 , 0 , 1 ) ;
break;
case 3 :
F_48 ( V_90 , 2 , - 1 , - 1 ) ;
V_22 -> V_126 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_75 ( struct V_21 * V_22 ,
struct V_80 * V_90 )
{
struct V_80 * V_125 = & V_22 -> V_90 ;
switch ( V_125 -> V_81 ) {
case 0 :
F_48 ( V_90 , 3 , 0 , 2 ) ;
break;
case 1 :
if ( V_125 -> V_82 >= 2 )
F_48 ( V_90 , 3 , 0 , V_125 -> V_82 ) ;
else
F_48 ( V_90 , 3 , 0 , 2 ) ;
break;
case 2 :
if ( V_125 -> V_83 >= 3 ) {
F_48 ( V_90 , 3 , 0 , V_125 -> V_83 ) ;
break;
}
if ( V_22 -> V_126 ) {
F_48 ( V_90 , 3 , - 1 , - 1 ) ;
break;
}
F_48 ( V_90 , 3 , 0 , - 1 ) ;
break;
case 3 :
if ( V_125 -> V_83 <= 2 )
F_48 ( V_90 , 3 , 0 , 2 ) ;
break;
case 4 :
case 5 :
break;
}
}
static void F_76 ( struct V_21 * V_22 ,
struct V_80 * V_90 )
{
V_22 -> V_126 = false ;
}
static void F_77 ( struct V_1 * V_1 ,
struct V_84 * V_82 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
struct V_84 * V_83 = & V_22 -> V_83 ;
struct V_80 V_90 ;
V_90 = V_83 -> V_90 ;
if ( V_82 -> V_89 == 0 )
F_72 ( V_22 , & V_90 ) ;
else if ( V_82 -> V_87 >= 4 )
F_73 ( V_22 , & V_90 ) ;
else if ( V_82 -> V_87 == 0 )
F_74 ( V_22 , & V_90 ) ;
else if ( V_82 -> V_87 == 1 && V_90 . V_81 <= 3 )
F_75 ( V_22 , & V_90 ) ;
else
F_76 ( V_22 , & V_90 ) ;
F_68 ( V_1 , & V_90 , V_82 ) ;
V_22 -> V_90 = V_83 -> V_90 = V_90 ;
V_22 -> V_91 = false ;
}
static void F_78 ( struct V_1 * V_1 ,
struct V_84 * V_82 ,
int V_117 )
{
struct V_108 * V_109 = V_1 -> V_109 ;
struct V_21 * V_22 = V_1 -> V_23 ;
struct V_84 * V_85 [ 2 ] = { V_82 , & V_22 -> V_83 } ;
struct V_127 V_128 [ 2 ] ;
int V_110 [ 2 ] , V_129 , V_14 ;
V_129 = F_79 ( V_117 , 0 , 2 ) ;
for ( V_14 = 0 ; V_14 < V_129 ; V_14 ++ ) {
V_128 [ V_14 ] . V_88 = V_85 [ V_14 ] -> V_88 ;
V_128 [ V_14 ] . V_17 = F_7 ( V_85 [ V_14 ] -> V_17 ) ;
}
F_80 ( V_109 , V_110 , V_128 , V_129 ) ;
for ( V_14 = 0 ; V_14 < V_129 ; V_14 ++ ) {
F_59 ( V_109 , V_110 [ V_14 ] ) ;
F_60 ( V_109 , V_112 , true ) ;
F_61 ( V_109 , V_113 , V_128 [ V_14 ] . V_88 ) ;
F_61 ( V_109 , V_114 , V_128 [ V_14 ] . V_17 ) ;
F_61 ( V_109 , V_124 , V_85 [ V_14 ] -> V_89 ) ;
}
F_81 ( V_109 ) ;
F_69 ( V_109 , false ) ;
F_70 ( V_109 , V_117 ) ;
F_65 ( V_1 , V_82 ) ;
F_71 ( V_109 ) ;
}
static void F_82 ( struct V_1 * V_1 )
{
struct V_108 * V_109 = V_1 -> V_109 ;
struct V_21 * V_22 = V_1 -> V_23 ;
struct V_84 V_85 ;
int V_117 ;
int V_130 ;
if ( F_50 ( V_1 -> V_67 , V_22 , & V_85 ) )
return;
if ( F_28 ( V_22 -> V_36 ) ) {
F_77 ( V_1 , & V_85 ) ;
return;
}
if ( V_85 . V_99 ) {
V_22 -> V_99 += V_85 . V_99 ;
while ( V_22 -> V_99 >= 4 ) {
F_66 ( V_109 , V_122 , ! V_85 . V_101 ) ;
F_71 ( V_109 ) ;
F_66 ( V_109 , V_122 , V_85 . V_101 ) ;
F_71 ( V_109 ) ;
V_22 -> V_99 -= 4 ;
}
while ( V_22 -> V_99 <= - 4 ) {
F_66 ( V_109 , V_121 , ! V_85 . V_100 ) ;
F_71 ( V_109 ) ;
F_66 ( V_109 , V_121 , V_85 . V_100 ) ;
F_71 ( V_109 ) ;
V_22 -> V_99 += 4 ;
}
return;
}
if ( V_85 . V_89 > 0 && V_85 . V_88 > 1 ) {
V_117 = 1 ;
V_130 = 5 ;
if ( F_15 ( V_22 -> V_34 ) ) {
switch ( V_85 . V_87 ) {
case 0 ... 1 :
if ( F_83 ( V_22 -> V_34 ) )
V_117 = V_85 . V_87 + 2 ;
break;
case 2 :
if ( F_84 ( V_22 -> V_26 ) )
;
break;
case 4 ... 15 :
if ( F_85 ( V_22 -> V_34 ) )
V_130 = V_85 . V_87 ;
break;
}
}
} else {
V_117 = 0 ;
V_130 = 0 ;
}
if ( V_131 ) {
F_78 ( V_1 , & V_85 , V_117 ) ;
return;
}
if ( F_27 ( V_22 -> V_36 ) )
F_62 ( V_109 , & V_85 , & V_22 -> V_83 ,
V_117 ) ;
if ( V_85 . V_89 > 30 ) F_66 ( V_109 , V_132 , 1 ) ;
if ( V_85 . V_89 < 25 ) F_66 ( V_109 , V_132 , 0 ) ;
if ( V_117 > 0 ) {
F_61 ( V_109 , V_133 , V_85 . V_88 ) ;
F_61 ( V_109 , V_134 , F_7 ( V_85 . V_17 ) ) ;
}
F_61 ( V_109 , V_135 , V_85 . V_89 ) ;
if ( F_85 ( V_22 -> V_34 ) )
F_61 ( V_109 , V_136 , V_130 ) ;
F_66 ( V_109 , V_137 , V_117 == 1 ) ;
if ( F_83 ( V_22 -> V_34 ) ) {
F_66 ( V_109 , V_138 , V_117 == 2 ) ;
F_66 ( V_109 , V_139 , V_117 == 3 ) ;
}
F_65 ( V_1 , & V_85 ) ;
F_71 ( V_109 ) ;
}
static int F_86 ( struct V_1 * V_1 ,
int V_140 , unsigned char V_141 )
{
static const unsigned char V_142 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const unsigned char V_143 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_144 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_145 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const unsigned char V_146 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
const char * V_67 = V_1 -> V_67 ;
if ( V_140 < 0 || V_140 > 4 )
return 0 ;
switch ( V_141 ) {
case V_147 :
case V_148 :
return ( V_67 [ V_140 ] & V_143 [ V_140 ] ) == V_144 [ V_140 ] ;
case V_149 :
return ( V_67 [ V_140 ] & V_142 [ V_140 ] ) == V_144 [ V_140 ] ;
case V_150 :
return ( V_67 [ V_140 ] & V_145 [ V_140 ] ) == V_146 [ V_140 ] ;
default:
F_31 ( V_1 , L_14 , V_141 ) ;
return 0 ;
}
}
static unsigned char F_87 ( struct V_1 * V_1 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < 5 ; V_14 ++ )
if ( ! F_86 ( V_1 , V_14 , V_149 ) ) {
F_46 ( V_1 , L_15 ) ;
return V_148 ;
}
return V_149 ;
}
static T_1 F_88 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
if ( V_1 -> V_151 >= 6 ) {
if ( F_89 ( V_22 -> V_141 == V_147 ) )
V_22 -> V_141 = F_87 ( V_1 ) ;
if ( F_90 ( V_22 -> V_34 ) &&
F_39 ( V_1 -> V_67 ) ) {
if ( V_22 -> V_64 )
F_40 ( V_22 -> V_64 , V_1 -> V_67 ) ;
} else
F_82 ( V_1 ) ;
return V_152 ;
}
return F_86 ( V_1 , V_1 -> V_151 - 1 , V_22 -> V_141 ) ?
V_153 : V_154 ;
}
static void F_91 ( struct V_108 * V_109 ,
struct V_21 * V_22 , int V_155 ,
int V_156 )
{
int V_48 = V_22 -> V_48 ? : V_157 ;
int V_49 = V_22 -> V_49 ? : V_158 ;
int V_50 = V_22 -> V_50 ? : V_19 ;
int V_51 = V_22 -> V_51 ? : V_18 ;
int V_159 = F_92 ( V_22 -> V_36 ) ?
V_160 : 0 ;
F_93 ( V_109 , V_155 , V_48 , V_49 , V_159 , 0 ) ;
F_93 ( V_109 , V_156 , V_50 , V_51 , V_159 , 0 ) ;
F_94 ( V_109 , V_155 , V_22 -> V_44 ) ;
F_94 ( V_109 , V_156 , V_22 -> V_45 ) ;
}
static void F_95 ( struct V_1 * V_1 ,
struct V_21 * V_22 )
{
struct V_108 * V_109 = V_1 -> V_109 ;
int V_14 ;
F_96 ( V_161 , V_109 -> V_162 ) ;
F_96 ( V_163 , V_109 -> V_164 ) ;
F_96 ( V_118 , V_109 -> V_165 ) ;
F_96 ( V_119 , V_109 -> V_165 ) ;
if ( F_56 ( V_22 -> V_34 ) )
F_96 ( V_120 , V_109 -> V_165 ) ;
if ( ! V_22 -> V_54 ) {
F_96 ( V_166 , V_109 -> V_164 ) ;
F_96 ( V_167 , V_109 -> V_168 ) ;
F_96 ( V_169 , V_109 -> V_168 ) ;
return;
}
F_96 ( V_170 , V_109 -> V_164 ) ;
F_91 ( V_109 , V_22 , V_133 , V_134 ) ;
F_93 ( V_109 , V_135 , 0 , 255 , 0 , 0 ) ;
if ( V_131 )
F_93 ( V_109 , V_124 , 0 , 255 , 0 , 0 ) ;
if ( F_28 ( V_22 -> V_36 ) ) {
F_91 ( V_109 , V_22 , V_113 ,
V_114 ) ;
F_93 ( V_109 , V_124 , 0 , 255 , 0 , 0 ) ;
F_97 ( V_109 , 2 , V_171 ) ;
F_96 ( V_172 , V_109 -> V_165 ) ;
F_96 ( V_173 , V_109 -> V_165 ) ;
} else if ( F_27 ( V_22 -> V_36 ) ) {
F_91 ( V_109 , V_22 , V_113 ,
V_114 ) ;
F_97 ( V_109 , 2 ,
V_171 |
( V_131 ?
V_174 : V_175 ) ) ;
}
if ( F_85 ( V_22 -> V_34 ) )
F_93 ( V_109 , V_136 , 0 , 15 , 0 , 0 ) ;
F_96 ( V_132 , V_109 -> V_165 ) ;
F_96 ( V_137 , V_109 -> V_165 ) ;
if ( F_83 ( V_22 -> V_34 ) ) {
F_96 ( V_138 , V_109 -> V_165 ) ;
F_96 ( V_139 , V_109 -> V_165 ) ;
}
if ( F_57 ( V_22 -> V_34 ) ||
F_56 ( V_22 -> V_34 ) ) {
F_96 ( V_121 , V_109 -> V_165 ) ;
F_96 ( V_122 , V_109 -> V_165 ) ;
}
for ( V_14 = 0 ; V_14 < F_18 ( V_22 -> V_35 ) ; V_14 ++ )
F_96 ( V_123 + V_14 , V_109 -> V_165 ) ;
F_98 ( V_166 , V_109 -> V_164 ) ;
F_98 ( V_167 , V_109 -> V_168 ) ;
F_98 ( V_169 , V_109 -> V_168 ) ;
if ( F_55 ( V_22 -> V_36 ) ) {
F_96 ( V_176 , V_109 -> V_162 ) ;
if ( F_6 ( V_1 , V_177 ) )
F_96 ( V_178 , V_109 -> V_162 ) ;
F_98 ( V_119 , V_109 -> V_165 ) ;
F_98 ( V_120 , V_109 -> V_165 ) ;
}
}
static T_2 F_99 ( struct V_1 * V_1 ,
void * V_179 , char * V_65 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
return sprintf ( V_65 , L_16 , V_22 -> V_56 ? '1' : '0' ) ;
}
static T_2 F_100 ( struct V_1 * V_1 ,
void * V_179 , const char * V_65 ,
T_3 V_180 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
unsigned int V_181 ;
int V_182 ;
V_182 = F_101 ( V_65 , 10 , & V_181 ) ;
if ( V_182 )
return V_182 ;
if ( V_181 > 1 )
return - V_183 ;
if ( V_181 == V_22 -> V_56 )
return V_180 ;
V_22 -> V_56 = V_181 ;
if ( V_181 )
V_22 -> V_2 |= V_57 ;
else
V_22 -> V_2 &= ~ V_57 ;
if ( F_1 ( V_1 , V_22 -> V_2 ) )
return - V_184 ;
return V_180 ;
}
static void F_102 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
if ( ! V_22 -> V_54 && F_103 ( V_22 -> V_37 ) )
F_104 ( & V_1 -> V_5 . V_15 -> V_109 ,
& V_185 . V_186 ) ;
F_5 ( V_1 ) ;
F_105 ( V_22 ) ;
V_1 -> V_23 = NULL ;
}
static int F_106 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
struct V_21 V_187 = * V_22 ;
unsigned char V_3 [ 2 ] ;
int V_188 = 0 ;
int error ;
do {
F_107 ( V_1 ) ;
if ( V_188 ) {
F_108 ( 1 ) ;
}
F_3 ( & V_1 -> V_5 , V_3 , V_189 ) ;
error = F_4 ( V_1 , 0 ) ;
} while ( error && ++ V_188 < 3 );
if ( error )
return - 1 ;
if ( V_188 > 1 )
F_109 ( V_1 , L_17 , V_188 ) ;
if ( F_25 ( V_1 ) ) {
F_31 ( V_1 , L_18 ) ;
return - 1 ;
}
if ( F_30 ( V_1 ) ) {
F_31 ( V_1 , L_19 ) ;
return - 1 ;
}
if ( V_187 . V_37 != V_22 -> V_37 ||
V_187 . V_26 != V_22 -> V_26 ||
V_187 . V_34 != V_22 -> V_34 ||
V_187 . V_35 != V_22 -> V_35 ) {
F_31 ( V_1 ,
L_20 ,
V_187 . V_37 , V_22 -> V_37 ,
V_187 . V_26 , V_22 -> V_26 ,
V_187 . V_34 , V_22 -> V_34 ,
V_187 . V_35 , V_22 -> V_35 ) ;
return - 1 ;
}
return 0 ;
}
void T_4 F_110 ( void )
{
V_190 = F_111 ( V_191 ) ;
V_192 = F_111 ( V_193 ) ;
V_131 = F_111 ( V_194 ) ;
}
static int F_112 ( struct V_1 * V_1 , bool V_54 )
{
struct V_21 * V_22 ;
int V_182 = - 1 ;
if ( V_54 && V_192 ) {
F_46 ( V_1 ,
L_21 ) ;
return - V_10 ;
}
V_1 -> V_23 = V_22 = F_44 ( sizeof( struct V_21 ) , V_73 ) ;
if ( ! V_22 )
return - V_195 ;
F_107 ( V_1 ) ;
if ( F_25 ( V_1 ) ) {
F_31 ( V_1 , L_18 ) ;
goto V_196;
}
V_22 -> V_54 = V_54 ;
if ( F_103 ( V_22 -> V_37 ) )
V_22 -> V_56 = true ;
if ( F_30 ( V_1 ) ) {
F_31 ( V_1 , L_19 ) ;
goto V_196;
}
V_22 -> V_141 = F_51 ( V_22 -> V_26 ) ? V_147 : V_150 ;
F_46 ( V_1 ,
L_22 ,
F_113 ( V_22 -> V_37 ) ,
F_22 ( V_22 -> V_37 ) , F_114 ( V_22 -> V_37 ) ,
V_22 -> V_26 ,
V_22 -> V_34 , V_22 -> V_35 , V_22 -> V_36 ,
V_22 -> V_29 , V_22 -> V_16 ) ;
F_95 ( V_1 , V_22 ) ;
V_1 -> V_197 = ( ( V_22 -> V_26 & 0x00ff0000 ) >> 8 ) |
( V_22 -> V_26 & 0x000000ff ) ;
if ( V_54 ) {
V_1 -> V_198 = F_88 ;
V_1 -> V_71 = 6 ;
} else {
V_1 -> V_198 = V_199 ;
V_1 -> V_71 = 3 ;
}
V_1 -> V_200 = F_32 ;
V_1 -> V_201 = F_102 ;
V_1 -> V_202 = F_106 ;
V_1 -> V_203 = F_5 ;
V_1 -> V_204 = 0 ;
if ( F_90 ( V_22 -> V_34 ) )
F_43 ( V_1 ) ;
if ( V_1 -> V_58 >= 80 && V_190 ) {
F_46 ( V_1 ,
L_23 ,
F_115 ( V_205 ) ) ;
V_1 -> V_58 = 40 ;
}
if ( ! V_22 -> V_54 && F_103 ( V_22 -> V_37 ) ) {
V_182 = F_116 ( & V_1 -> V_5 . V_15 -> V_109 ,
& V_185 . V_186 ) ;
if ( V_182 ) {
F_31 ( V_1 ,
L_24 ,
V_182 ) ;
goto V_196;
}
}
return 0 ;
V_196:
F_105 ( V_22 ) ;
return V_182 ;
}
int F_117 ( struct V_1 * V_1 )
{
return F_112 ( V_1 , true ) ;
}
int F_118 ( struct V_1 * V_1 )
{
return F_112 ( V_1 , false ) ;
}
bool F_119 ( void )
{
return true ;
}
void T_4 F_110 ( void )
{
}
int F_117 ( struct V_1 * V_1 )
{
return - V_206 ;
}
bool F_119 ( void )
{
return false ;
}
