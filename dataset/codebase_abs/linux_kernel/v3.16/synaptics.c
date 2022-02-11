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
V_85 -> V_92 = ( V_65 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_85 -> V_93 = ( V_65 [ 0 ] & 0x02 ) ? 1 : 0 ;
if ( F_52 ( V_22 -> V_36 ) ) {
V_85 -> V_92 = ( ( V_65 [ 0 ] ^ V_65 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
} else if ( F_53 ( V_22 -> V_34 ) ) {
V_85 -> V_94 = ( ( V_65 [ 0 ] ^ V_65 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
if ( V_85 -> V_87 == 2 )
V_85 -> V_95 = ( signed char ) ( V_65 [ 1 ] ) ;
}
if ( F_54 ( V_22 -> V_34 ) ) {
V_85 -> V_96 = ( ( V_65 [ 0 ] ^ V_65 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
V_85 -> V_97 = ( ( V_65 [ 0 ] ^ V_65 [ 3 ] ) & 0x02 ) ? 1 : 0 ;
}
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
if ( F_18 ( V_22 -> V_35 ) &&
( ( V_65 [ 0 ] ^ V_65 [ 3 ] ) & 0x02 ) ) {
switch ( F_18 ( V_22 -> V_35 ) & ~ 0x01 ) {
default:
break;
case 8 :
V_85 -> V_98 |= ( ( V_65 [ 5 ] & 0x08 ) ) ? 0x80 : 0 ;
V_85 -> V_98 |= ( ( V_65 [ 4 ] & 0x08 ) ) ? 0x40 : 0 ;
case 6 :
V_85 -> V_98 |= ( ( V_65 [ 5 ] & 0x04 ) ) ? 0x20 : 0 ;
V_85 -> V_98 |= ( ( V_65 [ 4 ] & 0x04 ) ) ? 0x10 : 0 ;
case 4 :
V_85 -> V_98 |= ( ( V_65 [ 5 ] & 0x02 ) ) ? 0x08 : 0 ;
V_85 -> V_98 |= ( ( V_65 [ 4 ] & 0x02 ) ) ? 0x04 : 0 ;
case 2 :
V_85 -> V_98 |= ( ( V_65 [ 5 ] & 0x01 ) ) ? 0x02 : 0 ;
V_85 -> V_98 |= ( ( V_65 [ 4 ] & 0x01 ) ) ? 0x01 : 0 ;
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
if ( V_85 -> V_88 > V_99 )
V_85 -> V_88 -= 1 << V_100 ;
else if ( V_85 -> V_88 == V_99 )
V_85 -> V_88 = V_101 ;
if ( V_85 -> V_17 > V_102 )
V_85 -> V_17 -= 1 << V_100 ;
else if ( V_85 -> V_17 == V_102 )
V_85 -> V_17 = V_103 ;
return 0 ;
}
static void F_55 ( struct V_104 * V_105 , int V_106 ,
bool V_107 , int V_88 , int V_17 )
{
F_56 ( V_105 , V_106 ) ;
F_57 ( V_105 , V_108 , V_107 ) ;
if ( V_107 ) {
F_58 ( V_105 , V_109 , V_88 ) ;
F_58 ( V_105 , V_110 , F_7 ( V_17 ) ) ;
}
}
static void F_59 ( struct V_104 * V_105 ,
const struct V_84 * V_111 ,
const struct V_84 * V_112 ,
int V_113 )
{
if ( V_113 >= 2 ) {
F_55 ( V_105 , 0 , true , F_60 ( V_111 -> V_88 , V_112 -> V_88 ) ,
F_60 ( V_111 -> V_17 , V_112 -> V_17 ) ) ;
F_55 ( V_105 , 1 , true , F_61 ( V_111 -> V_88 , V_112 -> V_88 ) ,
F_61 ( V_111 -> V_17 , V_112 -> V_17 ) ) ;
} else if ( V_113 == 1 ) {
F_55 ( V_105 , 0 , true , V_111 -> V_88 , V_111 -> V_17 ) ;
F_55 ( V_105 , 1 , false , 0 , 0 ) ;
} else {
F_55 ( V_105 , 0 , false , 0 , 0 ) ;
F_55 ( V_105 , 1 , false , 0 , 0 ) ;
}
}
static void F_62 ( struct V_1 * V_1 ,
const struct V_84 * V_85 )
{
struct V_104 * V_105 = V_1 -> V_105 ;
struct V_21 * V_22 = V_1 -> V_23 ;
int V_14 ;
F_63 ( V_105 , V_114 , V_85 -> V_92 ) ;
F_63 ( V_105 , V_115 , V_85 -> V_93 ) ;
if ( F_53 ( V_22 -> V_34 ) )
F_63 ( V_105 , V_116 , V_85 -> V_94 ) ;
if ( F_54 ( V_22 -> V_34 ) ) {
F_63 ( V_105 , V_117 , V_85 -> V_96 ) ;
F_63 ( V_105 , V_118 , V_85 -> V_97 ) ;
}
for ( V_14 = 0 ; V_14 < F_18 ( V_22 -> V_35 ) ; V_14 ++ )
F_63 ( V_105 , V_119 + V_14 , V_85 -> V_98 & ( 1 << V_14 ) ) ;
}
static void F_64 ( struct V_104 * V_105 , int V_106 ,
const struct V_84 * V_85 )
{
F_56 ( V_105 , V_106 ) ;
F_57 ( V_105 , V_108 , ( V_85 != NULL ) ) ;
if ( ! V_85 )
return;
F_58 ( V_105 , V_109 , V_85 -> V_88 ) ;
F_58 ( V_105 , V_110 , F_7 ( V_85 -> V_17 ) ) ;
F_58 ( V_105 , V_120 , V_85 -> V_89 ) ;
}
static void F_65 ( struct V_1 * V_1 ,
struct V_80 * V_90 ,
const struct V_84 * V_82 )
{
struct V_104 * V_105 = V_1 -> V_105 ;
struct V_21 * V_22 = V_1 -> V_23 ;
struct V_84 * V_83 = & V_22 -> V_83 ;
struct V_80 * V_121 = & V_22 -> V_90 ;
switch ( V_90 -> V_81 ) {
case 0 :
F_64 ( V_105 , 0 , NULL ) ;
F_64 ( V_105 , 1 , NULL ) ;
break;
case 1 :
if ( V_90 -> V_82 == - 1 ) {
F_64 ( V_105 , 0 , NULL ) ;
F_64 ( V_105 , 1 , NULL ) ;
} else if ( V_90 -> V_82 == 0 ) {
F_64 ( V_105 , 0 , V_82 ) ;
F_64 ( V_105 , 1 , NULL ) ;
} else {
F_64 ( V_105 , 0 , NULL ) ;
F_64 ( V_105 , 1 , V_82 ) ;
}
break;
default:
if ( V_90 -> V_82 != - 1 &&
( V_90 -> V_82 == V_121 -> V_82 ||
V_121 -> V_82 == - 1 || V_90 -> V_83 == V_121 -> V_82 ) )
F_64 ( V_105 , 0 , V_82 ) ;
else
F_64 ( V_105 , 0 , NULL ) ;
if ( V_90 -> V_83 != - 1 &&
( V_90 -> V_83 == V_121 -> V_83 ||
( V_121 -> V_83 == - 1 &&
( V_121 -> V_82 == - 1 || V_90 -> V_83 == V_121 -> V_82 ) ) ) )
F_64 ( V_105 , 1 , V_83 ) ;
else
F_64 ( V_105 , 1 , NULL ) ;
break;
}
F_66 ( V_105 , false ) ;
F_67 ( V_105 , V_90 -> V_81 ) ;
F_62 ( V_1 , V_82 ) ;
F_68 ( V_105 ) ;
}
static void F_69 ( struct V_21 * V_22 ,
struct V_80 * V_90 )
{
F_48 ( V_90 , 0 , - 1 , - 1 ) ;
V_22 -> V_122 = false ;
}
static void F_70 ( struct V_21 * V_22 ,
struct V_80 * V_90 )
{
struct V_84 * V_83 = & V_22 -> V_83 ;
struct V_80 * V_121 = & V_22 -> V_90 ;
if ( V_22 -> V_91 && V_83 -> V_89 == 0 ) {
F_48 ( V_90 , 1 , 0 , - 1 ) ;
V_22 -> V_122 = false ;
return;
}
switch ( V_121 -> V_81 ) {
case 0 :
F_48 ( V_90 , 1 , 0 , - 1 ) ;
break;
case 1 :
if ( V_22 -> V_122 ||
( V_22 -> V_91 && V_121 -> V_82 <= 0 ) )
F_48 ( V_90 , 1 , 1 , - 1 ) ;
else if ( V_121 -> V_82 == - 1 )
F_48 ( V_90 , 1 , 0 , - 1 ) ;
break;
case 2 :
if ( V_22 -> V_122 ) {
F_48 ( V_90 , 1 , - 1 , - 1 ) ;
break;
}
F_48 ( V_90 , 1 , V_121 -> V_83 , - 1 ) ;
break;
case 3 :
F_48 ( V_90 , 1 , - 1 , - 1 ) ;
V_22 -> V_122 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_71 ( struct V_21 * V_22 ,
struct V_80 * V_90 )
{
struct V_80 * V_121 = & V_22 -> V_90 ;
switch ( V_121 -> V_81 ) {
case 0 :
F_48 ( V_90 , 2 , 0 , 1 ) ;
break;
case 1 :
if ( V_121 -> V_82 >= 1 )
F_48 ( V_90 , 2 , 0 , V_121 -> V_82 ) ;
else
F_48 ( V_90 , 2 , 0 , 1 ) ;
break;
case 2 :
if ( V_22 -> V_122 )
F_48 ( V_90 , 2 , 0 , 1 ) ;
break;
case 3 :
F_48 ( V_90 , 2 , - 1 , - 1 ) ;
V_22 -> V_122 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_72 ( struct V_21 * V_22 ,
struct V_80 * V_90 )
{
struct V_80 * V_121 = & V_22 -> V_90 ;
switch ( V_121 -> V_81 ) {
case 0 :
F_48 ( V_90 , 3 , 0 , 2 ) ;
break;
case 1 :
if ( V_121 -> V_82 >= 2 )
F_48 ( V_90 , 3 , 0 , V_121 -> V_82 ) ;
else
F_48 ( V_90 , 3 , 0 , 2 ) ;
break;
case 2 :
if ( V_121 -> V_83 >= 3 ) {
F_48 ( V_90 , 3 , 0 , V_121 -> V_83 ) ;
break;
}
if ( V_22 -> V_122 ) {
F_48 ( V_90 , 3 , - 1 , - 1 ) ;
break;
}
F_48 ( V_90 , 3 , 0 , - 1 ) ;
break;
case 3 :
if ( V_121 -> V_83 <= 2 )
F_48 ( V_90 , 3 , 0 , 2 ) ;
break;
case 4 :
case 5 :
break;
}
}
static void F_73 ( struct V_21 * V_22 ,
struct V_80 * V_90 )
{
V_22 -> V_122 = false ;
}
static void F_74 ( struct V_1 * V_1 ,
struct V_84 * V_82 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
struct V_84 * V_83 = & V_22 -> V_83 ;
struct V_80 V_90 ;
V_90 = V_83 -> V_90 ;
if ( V_82 -> V_89 == 0 )
F_69 ( V_22 , & V_90 ) ;
else if ( V_82 -> V_87 >= 4 )
F_70 ( V_22 , & V_90 ) ;
else if ( V_82 -> V_87 == 0 )
F_71 ( V_22 , & V_90 ) ;
else if ( V_82 -> V_87 == 1 && V_90 . V_81 <= 3 )
F_72 ( V_22 , & V_90 ) ;
else
F_73 ( V_22 , & V_90 ) ;
F_65 ( V_1 , & V_90 , V_82 ) ;
V_22 -> V_90 = V_83 -> V_90 = V_90 ;
V_22 -> V_91 = false ;
}
static void F_75 ( struct V_1 * V_1 )
{
struct V_104 * V_105 = V_1 -> V_105 ;
struct V_21 * V_22 = V_1 -> V_23 ;
struct V_84 V_85 ;
int V_113 ;
int V_123 ;
if ( F_50 ( V_1 -> V_67 , V_22 , & V_85 ) )
return;
if ( F_28 ( V_22 -> V_36 ) ) {
F_74 ( V_1 , & V_85 ) ;
return;
}
if ( V_85 . V_95 ) {
V_22 -> V_95 += V_85 . V_95 ;
while ( V_22 -> V_95 >= 4 ) {
F_63 ( V_105 , V_118 , ! V_85 . V_97 ) ;
F_68 ( V_105 ) ;
F_63 ( V_105 , V_118 , V_85 . V_97 ) ;
F_68 ( V_105 ) ;
V_22 -> V_95 -= 4 ;
}
while ( V_22 -> V_95 <= - 4 ) {
F_63 ( V_105 , V_117 , ! V_85 . V_96 ) ;
F_68 ( V_105 ) ;
F_63 ( V_105 , V_117 , V_85 . V_96 ) ;
F_68 ( V_105 ) ;
V_22 -> V_95 += 4 ;
}
return;
}
if ( V_85 . V_89 > 0 && V_85 . V_88 > 1 ) {
V_113 = 1 ;
V_123 = 5 ;
if ( F_15 ( V_22 -> V_34 ) ) {
switch ( V_85 . V_87 ) {
case 0 ... 1 :
if ( F_76 ( V_22 -> V_34 ) )
V_113 = V_85 . V_87 + 2 ;
break;
case 2 :
if ( F_77 ( V_22 -> V_26 ) )
;
break;
case 4 ... 15 :
if ( F_78 ( V_22 -> V_34 ) )
V_123 = V_85 . V_87 ;
break;
}
}
} else {
V_113 = 0 ;
V_123 = 0 ;
}
if ( F_27 ( V_22 -> V_36 ) )
F_59 ( V_105 , & V_85 , & V_22 -> V_83 ,
V_113 ) ;
if ( V_85 . V_89 > 30 ) F_63 ( V_105 , V_124 , 1 ) ;
if ( V_85 . V_89 < 25 ) F_63 ( V_105 , V_124 , 0 ) ;
if ( V_113 > 0 ) {
F_58 ( V_105 , V_125 , V_85 . V_88 ) ;
F_58 ( V_105 , V_126 , F_7 ( V_85 . V_17 ) ) ;
}
F_58 ( V_105 , V_127 , V_85 . V_89 ) ;
if ( F_78 ( V_22 -> V_34 ) )
F_58 ( V_105 , V_128 , V_123 ) ;
F_63 ( V_105 , V_129 , V_113 == 1 ) ;
if ( F_76 ( V_22 -> V_34 ) ) {
F_63 ( V_105 , V_130 , V_113 == 2 ) ;
F_63 ( V_105 , V_131 , V_113 == 3 ) ;
}
F_62 ( V_1 , & V_85 ) ;
F_68 ( V_105 ) ;
}
static int F_79 ( struct V_1 * V_1 ,
int V_132 , unsigned char V_133 )
{
static const unsigned char V_134 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const unsigned char V_135 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_136 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_137 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const unsigned char V_138 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
const char * V_67 = V_1 -> V_67 ;
if ( V_132 < 0 || V_132 > 4 )
return 0 ;
switch ( V_133 ) {
case V_139 :
case V_140 :
return ( V_67 [ V_132 ] & V_135 [ V_132 ] ) == V_136 [ V_132 ] ;
case V_141 :
return ( V_67 [ V_132 ] & V_134 [ V_132 ] ) == V_136 [ V_132 ] ;
case V_142 :
return ( V_67 [ V_132 ] & V_137 [ V_132 ] ) == V_138 [ V_132 ] ;
default:
F_31 ( V_1 , L_14 , V_133 ) ;
return 0 ;
}
}
static unsigned char F_80 ( struct V_1 * V_1 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < 5 ; V_14 ++ )
if ( ! F_79 ( V_1 , V_14 , V_141 ) ) {
F_46 ( V_1 , L_15 ) ;
return V_140 ;
}
return V_141 ;
}
static T_1 F_81 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
if ( V_1 -> V_143 >= 6 ) {
if ( F_82 ( V_22 -> V_133 == V_139 ) )
V_22 -> V_133 = F_80 ( V_1 ) ;
if ( F_83 ( V_22 -> V_34 ) &&
F_39 ( V_1 -> V_67 ) ) {
if ( V_22 -> V_64 )
F_40 ( V_22 -> V_64 , V_1 -> V_67 ) ;
} else
F_75 ( V_1 ) ;
return V_144 ;
}
return F_79 ( V_1 , V_1 -> V_143 - 1 , V_22 -> V_133 ) ?
V_145 : V_146 ;
}
static void F_84 ( struct V_104 * V_105 ,
struct V_21 * V_22 , int V_147 ,
int V_148 )
{
int V_48 = V_22 -> V_48 ? : V_149 ;
int V_49 = V_22 -> V_49 ? : V_150 ;
int V_50 = V_22 -> V_50 ? : V_19 ;
int V_51 = V_22 -> V_51 ? : V_18 ;
int V_151 = F_85 ( V_22 -> V_36 ) ?
V_152 : 0 ;
F_86 ( V_105 , V_147 , V_48 , V_49 , V_151 , 0 ) ;
F_86 ( V_105 , V_148 , V_50 , V_51 , V_151 , 0 ) ;
F_87 ( V_105 , V_147 , V_22 -> V_44 ) ;
F_87 ( V_105 , V_148 , V_22 -> V_45 ) ;
}
static void F_88 ( struct V_1 * V_1 ,
struct V_21 * V_22 )
{
struct V_104 * V_105 = V_1 -> V_105 ;
int V_14 ;
F_89 ( V_153 , V_105 -> V_154 ) ;
F_89 ( V_155 , V_105 -> V_156 ) ;
F_89 ( V_114 , V_105 -> V_157 ) ;
F_89 ( V_115 , V_105 -> V_157 ) ;
if ( F_53 ( V_22 -> V_34 ) )
F_89 ( V_116 , V_105 -> V_157 ) ;
if ( ! V_22 -> V_54 ) {
F_89 ( V_158 , V_105 -> V_156 ) ;
F_89 ( V_159 , V_105 -> V_160 ) ;
F_89 ( V_161 , V_105 -> V_160 ) ;
return;
}
F_89 ( V_162 , V_105 -> V_156 ) ;
F_84 ( V_105 , V_22 , V_125 , V_126 ) ;
F_86 ( V_105 , V_127 , 0 , 255 , 0 , 0 ) ;
if ( F_28 ( V_22 -> V_36 ) ) {
F_84 ( V_105 , V_22 , V_109 ,
V_110 ) ;
F_86 ( V_105 , V_120 , 0 , 255 , 0 , 0 ) ;
F_90 ( V_105 , 2 , V_163 ) ;
F_89 ( V_164 , V_105 -> V_157 ) ;
F_89 ( V_165 , V_105 -> V_157 ) ;
} else if ( F_27 ( V_22 -> V_36 ) ) {
F_89 ( V_166 , V_105 -> V_154 ) ;
F_90 ( V_105 , 2 , 0 ) ;
F_84 ( V_105 , V_22 , V_109 ,
V_110 ) ;
}
if ( F_78 ( V_22 -> V_34 ) )
F_86 ( V_105 , V_128 , 0 , 15 , 0 , 0 ) ;
F_89 ( V_124 , V_105 -> V_157 ) ;
F_89 ( V_129 , V_105 -> V_157 ) ;
if ( F_76 ( V_22 -> V_34 ) ) {
F_89 ( V_130 , V_105 -> V_157 ) ;
F_89 ( V_131 , V_105 -> V_157 ) ;
}
if ( F_54 ( V_22 -> V_34 ) ||
F_53 ( V_22 -> V_34 ) ) {
F_89 ( V_117 , V_105 -> V_157 ) ;
F_89 ( V_118 , V_105 -> V_157 ) ;
}
for ( V_14 = 0 ; V_14 < F_18 ( V_22 -> V_35 ) ; V_14 ++ )
F_89 ( V_119 + V_14 , V_105 -> V_157 ) ;
F_91 ( V_158 , V_105 -> V_156 ) ;
F_91 ( V_159 , V_105 -> V_160 ) ;
F_91 ( V_161 , V_105 -> V_160 ) ;
if ( F_52 ( V_22 -> V_36 ) ) {
F_89 ( V_167 , V_105 -> V_154 ) ;
if ( F_6 ( V_1 , V_168 ) )
F_89 ( V_169 , V_105 -> V_154 ) ;
F_91 ( V_115 , V_105 -> V_157 ) ;
F_91 ( V_116 , V_105 -> V_157 ) ;
}
}
static T_2 F_92 ( struct V_1 * V_1 ,
void * V_170 , char * V_65 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
return sprintf ( V_65 , L_16 , V_22 -> V_56 ? '1' : '0' ) ;
}
static T_2 F_93 ( struct V_1 * V_1 ,
void * V_170 , const char * V_65 ,
T_3 V_171 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
unsigned int V_172 ;
int V_173 ;
V_173 = F_94 ( V_65 , 10 , & V_172 ) ;
if ( V_173 )
return V_173 ;
if ( V_172 > 1 )
return - V_174 ;
if ( V_172 == V_22 -> V_56 )
return V_171 ;
V_22 -> V_56 = V_172 ;
if ( V_172 )
V_22 -> V_2 |= V_57 ;
else
V_22 -> V_2 &= ~ V_57 ;
if ( F_1 ( V_1 , V_22 -> V_2 ) )
return - V_175 ;
return V_171 ;
}
static void F_95 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
if ( ! V_22 -> V_54 && F_96 ( V_22 -> V_37 ) )
F_97 ( & V_1 -> V_5 . V_15 -> V_105 ,
& V_176 . V_177 ) ;
F_5 ( V_1 ) ;
F_98 ( V_22 ) ;
V_1 -> V_23 = NULL ;
}
static int F_99 ( struct V_1 * V_1 )
{
struct V_21 * V_22 = V_1 -> V_23 ;
struct V_21 V_178 = * V_22 ;
unsigned char V_3 [ 2 ] ;
int V_179 = 0 ;
int error ;
do {
F_100 ( V_1 ) ;
if ( V_179 ) {
F_101 ( 1 ) ;
}
F_3 ( & V_1 -> V_5 , V_3 , V_180 ) ;
error = F_4 ( V_1 , 0 ) ;
} while ( error && ++ V_179 < 3 );
if ( error )
return - 1 ;
if ( V_179 > 1 )
F_102 ( V_1 , L_17 , V_179 ) ;
if ( F_25 ( V_1 ) ) {
F_31 ( V_1 , L_18 ) ;
return - 1 ;
}
if ( F_30 ( V_1 ) ) {
F_31 ( V_1 , L_19 ) ;
return - 1 ;
}
if ( V_178 . V_37 != V_22 -> V_37 ||
V_178 . V_26 != V_22 -> V_26 ||
V_178 . V_34 != V_22 -> V_34 ||
V_178 . V_35 != V_22 -> V_35 ) {
F_31 ( V_1 ,
L_20 ,
V_178 . V_37 , V_22 -> V_37 ,
V_178 . V_26 , V_22 -> V_26 ,
V_178 . V_34 , V_22 -> V_34 ,
V_178 . V_35 , V_22 -> V_35 ) ;
return - 1 ;
}
return 0 ;
}
void T_4 F_103 ( void )
{
V_181 = F_104 ( V_182 ) ;
V_183 = F_104 ( V_184 ) ;
}
static int F_105 ( struct V_1 * V_1 , bool V_54 )
{
struct V_21 * V_22 ;
int V_173 = - 1 ;
if ( V_54 && V_183 ) {
F_46 ( V_1 ,
L_21 ) ;
return - V_10 ;
}
V_1 -> V_23 = V_22 = F_44 ( sizeof( struct V_21 ) , V_73 ) ;
if ( ! V_22 )
return - V_185 ;
F_100 ( V_1 ) ;
if ( F_25 ( V_1 ) ) {
F_31 ( V_1 , L_18 ) ;
goto V_186;
}
V_22 -> V_54 = V_54 ;
if ( F_96 ( V_22 -> V_37 ) )
V_22 -> V_56 = true ;
if ( F_30 ( V_1 ) ) {
F_31 ( V_1 , L_19 ) ;
goto V_186;
}
V_22 -> V_133 = F_51 ( V_22 -> V_26 ) ? V_139 : V_142 ;
F_46 ( V_1 ,
L_22 ,
F_106 ( V_22 -> V_37 ) ,
F_22 ( V_22 -> V_37 ) , F_107 ( V_22 -> V_37 ) ,
V_22 -> V_26 ,
V_22 -> V_34 , V_22 -> V_35 , V_22 -> V_36 ,
V_22 -> V_29 , V_22 -> V_16 ) ;
F_88 ( V_1 , V_22 ) ;
V_1 -> V_187 = ( ( V_22 -> V_26 & 0x00ff0000 ) >> 8 ) |
( V_22 -> V_26 & 0x000000ff ) ;
if ( V_54 ) {
V_1 -> V_188 = F_81 ;
V_1 -> V_71 = 6 ;
} else {
V_1 -> V_188 = V_189 ;
V_1 -> V_71 = 3 ;
}
V_1 -> V_190 = F_32 ;
V_1 -> V_191 = F_95 ;
V_1 -> V_192 = F_99 ;
V_1 -> V_193 = F_5 ;
V_1 -> V_194 = 0 ;
if ( F_83 ( V_22 -> V_34 ) )
F_43 ( V_1 ) ;
if ( V_1 -> V_58 >= 80 && V_181 ) {
F_46 ( V_1 ,
L_23 ,
F_108 ( V_195 ) ) ;
V_1 -> V_58 = 40 ;
}
if ( ! V_22 -> V_54 && F_96 ( V_22 -> V_37 ) ) {
V_173 = F_109 ( & V_1 -> V_5 . V_15 -> V_105 ,
& V_176 . V_177 ) ;
if ( V_173 ) {
F_31 ( V_1 ,
L_24 ,
V_173 ) ;
goto V_186;
}
}
return 0 ;
V_186:
F_98 ( V_22 ) ;
return V_173 ;
}
int F_110 ( struct V_1 * V_1 )
{
return F_105 ( V_1 , true ) ;
}
int F_111 ( struct V_1 * V_1 )
{
return F_105 ( V_1 , false ) ;
}
bool F_112 ( void )
{
return true ;
}
void T_4 F_103 ( void )
{
}
int F_110 ( struct V_1 * V_1 )
{
return - V_196 ;
}
bool F_112 ( void )
{
return false ;
}
