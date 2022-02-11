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
V_18 -> V_25 = ( ( V_23 [ 0 ] & 0xfc ) << 6 ) | V_23 [ 1 ] ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_26 [ 3 ] ;
if ( F_7 ( V_1 , V_27 , V_26 ) )
return - 1 ;
V_18 -> V_28 = ( V_26 [ 0 ] << 16 ) | ( V_26 [ 1 ] << 8 ) | V_26 [ 2 ] ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_29 [ 3 ] ;
if ( F_7 ( V_1 , V_30 , V_29 ) )
return - 1 ;
V_18 -> V_31 = ( V_29 [ 0 ] << 16 ) | ( V_29 [ 1 ] << 8 ) | V_29 [ 2 ] ;
V_18 -> V_32 = V_18 -> V_33 = 0 ;
if ( F_12 ( V_18 -> V_34 ) < 0x705 &&
F_13 ( V_18 -> V_31 ) != 0x47 ) {
return - 1 ;
}
if ( ! F_14 ( V_18 -> V_31 ) )
V_18 -> V_31 = 0 ;
if ( F_15 ( V_18 -> V_31 ) >= 1 ) {
if ( F_7 ( V_1 , V_35 , V_29 ) ) {
F_16 ( V_1 ,
L_3 ) ;
} else {
V_18 -> V_32 = ( V_29 [ 0 ] << 16 ) | ( V_29 [ 1 ] << 8 ) | V_29 [ 2 ] ;
if ( F_17 ( V_18 -> V_32 ) > 8 )
V_18 -> V_32 &= 0xff0fff ;
}
}
if ( F_15 ( V_18 -> V_31 ) >= 4 ) {
if ( F_7 ( V_1 , V_36 , V_29 ) ) {
F_16 ( V_1 ,
L_4 ) ;
} else {
V_18 -> V_33 = ( V_29 [ 0 ] << 16 ) | ( V_29 [ 1 ] << 8 ) | V_29 [ 2 ] ;
}
}
return 0 ;
}
static int F_18 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_37 [ 3 ] ;
if ( F_7 ( V_1 , V_38 , V_37 ) )
return - 1 ;
V_18 -> V_34 = ( V_37 [ 0 ] << 16 ) | ( V_37 [ 1 ] << 8 ) | V_37 [ 2 ] ;
if ( F_19 ( V_18 -> V_34 ) )
return 0 ;
return - 1 ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_39 [ 3 ] ;
if ( F_21 ( V_18 -> V_34 ) < 4 )
return 0 ;
if ( F_7 ( V_1 , V_40 , V_39 ) == 0 ) {
if ( V_39 [ 0 ] != 0 && ( V_39 [ 1 ] & 0x80 ) && V_39 [ 2 ] != 0 ) {
V_18 -> V_41 = V_39 [ 0 ] ;
V_18 -> V_42 = V_39 [ 2 ] ;
}
}
if ( F_15 ( V_18 -> V_31 ) >= 5 &&
F_22 ( V_18 -> V_33 ) ) {
if ( F_7 ( V_1 , V_43 , V_39 ) ) {
F_16 ( V_1 ,
L_5 ) ;
} else {
V_18 -> V_44 = ( V_39 [ 0 ] << 5 ) | ( ( V_39 [ 1 ] & 0x0f ) << 1 ) ;
V_18 -> V_45 = ( V_39 [ 2 ] << 5 ) | ( ( V_39 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
if ( F_15 ( V_18 -> V_31 ) >= 7 &&
F_23 ( V_18 -> V_33 ) ) {
if ( F_7 ( V_1 , V_46 , V_39 ) ) {
F_16 ( V_1 ,
L_6 ) ;
} else {
V_18 -> V_47 = ( V_39 [ 0 ] << 5 ) | ( ( V_39 [ 1 ] & 0x0f ) << 1 ) ;
V_18 -> V_48 = ( V_39 [ 2 ] << 5 ) | ( ( V_39 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
return 0 ;
}
static int F_24 ( struct V_1 * V_1 )
{
if ( F_18 ( V_1 ) )
return - 1 ;
if ( F_8 ( V_1 ) )
return - 1 ;
if ( F_10 ( V_1 ) )
return - 1 ;
if ( F_9 ( V_1 ) )
return - 1 ;
if ( F_11 ( V_1 ) )
return - 1 ;
if ( F_20 ( V_1 ) )
return - 1 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
static unsigned char V_3 = 0xc8 ;
struct V_17 * V_18 = V_1 -> V_19 ;
if ( ! ( F_26 ( V_18 -> V_33 ) ||
F_27 ( V_18 -> V_33 ) ) )
return 0 ;
if ( F_2 ( V_1 , V_21 ) )
return - 1 ;
if ( F_3 ( & V_1 -> V_5 , & V_3 , V_6 ) )
return - 1 ;
V_18 -> V_31 |= F_28 ( 1 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
V_18 -> V_2 = 0 ;
if ( V_18 -> V_49 )
V_18 -> V_2 |= V_50 ;
if ( V_18 -> V_51 )
V_18 -> V_2 |= V_52 ;
if ( V_1 -> V_53 >= 80 )
V_18 -> V_2 |= V_54 ;
if ( F_14 ( V_18 -> V_31 ) )
V_18 -> V_2 |= V_55 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
return - 1 ;
if ( V_18 -> V_49 &&
F_25 ( V_1 ) ) {
F_30 ( V_1 , L_7 ) ;
return - 1 ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_1 , unsigned int V_53 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( V_53 >= 80 ) {
V_18 -> V_2 |= V_54 ;
V_1 -> V_53 = 80 ;
} else {
V_18 -> V_2 &= ~ V_54 ;
V_1 -> V_53 = 40 ;
}
F_1 ( V_1 , V_18 -> V_2 ) ;
}
static int F_32 ( struct V_56 * V_56 , unsigned char V_16 )
{
struct V_1 * V_57 = F_33 ( V_56 -> V_57 ) ;
char V_58 = V_59 ;
if ( F_2 ( V_57 , V_16 ) )
return - 1 ;
if ( F_3 ( & V_57 -> V_5 , & V_58 , V_6 ) )
return - 1 ;
return 0 ;
}
static int F_34 ( struct V_56 * V_56 )
{
struct V_1 * V_57 = F_33 ( V_56 -> V_57 ) ;
struct V_17 * V_18 = V_57 -> V_19 ;
F_35 ( V_57 -> V_5 . V_56 ) ;
V_18 -> V_60 = V_56 ;
F_36 ( V_57 -> V_5 . V_56 ) ;
return 0 ;
}
static void F_37 ( struct V_56 * V_56 )
{
struct V_1 * V_57 = F_33 ( V_56 -> V_57 ) ;
struct V_17 * V_18 = V_57 -> V_19 ;
F_35 ( V_57 -> V_5 . V_56 ) ;
V_18 -> V_60 = NULL ;
F_36 ( V_57 -> V_5 . V_56 ) ;
}
static int F_38 ( unsigned char * V_61 )
{
return ( V_61 [ 0 ] & 0xFC ) == 0x84 && ( V_61 [ 3 ] & 0xCC ) == 0xC4 ;
}
static void F_39 ( struct V_56 * V_62 , unsigned char * V_63 )
{
struct V_1 * V_64 = F_33 ( V_62 ) ;
if ( V_64 && V_64 -> V_65 == V_66 ) {
F_40 ( V_62 , V_63 [ 1 ] , 0 ) ;
F_40 ( V_62 , V_63 [ 4 ] , 0 ) ;
F_40 ( V_62 , V_63 [ 5 ] , 0 ) ;
if ( V_64 -> V_67 == 4 )
F_40 ( V_62 , V_63 [ 2 ] , 0 ) ;
} else
F_40 ( V_62 , V_63 [ 1 ] , 0 ) ;
}
static void F_41 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_1 * V_64 = F_33 ( V_18 -> V_60 ) ;
if ( V_64 ) {
if ( V_64 -> V_67 == 4 )
V_18 -> V_2 |= V_68 ;
else
V_18 -> V_2 &= ~ V_68 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
F_16 ( V_1 ,
L_8 ) ;
}
}
static void F_42 ( struct V_1 * V_1 )
{
struct V_56 * V_56 ;
V_56 = F_43 ( sizeof( struct V_56 ) , V_69 ) ;
if ( ! V_56 ) {
F_30 ( V_1 ,
L_9 ) ;
return;
}
V_56 -> V_37 . type = V_70 ;
F_44 ( V_56 -> V_12 , L_10 , sizeof( V_56 -> V_12 ) ) ;
F_44 ( V_56 -> V_71 , L_11 , sizeof( V_56 -> V_12 ) ) ;
V_56 -> V_72 = F_32 ;
V_56 -> V_73 = F_34 ;
V_56 -> V_74 = F_37 ;
V_56 -> V_57 = V_1 -> V_5 . V_56 ;
V_1 -> V_75 = F_41 ;
F_45 ( V_1 , L_12 ,
V_56 -> V_12 , V_1 -> V_71 ) ;
F_46 ( V_56 ) ;
}
static void F_47 ( struct V_76 * V_65 , int V_77 ,
int V_78 , int V_79 )
{
V_65 -> V_77 = V_77 ;
V_65 -> V_78 = V_78 ;
V_65 -> V_79 = V_79 ;
}
static void F_48 ( const unsigned char V_61 [] ,
struct V_17 * V_18 ,
struct V_80 * V_81 )
{
struct V_80 * V_79 = & V_18 -> V_79 ;
int V_82 ;
V_82 = ( V_61 [ 5 ] & 0x30 ) >> 4 ;
switch ( V_82 ) {
case 1 :
V_79 -> V_83 = V_81 -> V_83 ;
V_79 -> V_84 = ( ( ( V_61 [ 4 ] & 0x0f ) << 8 ) | V_61 [ 1 ] ) << 1 ;
V_79 -> V_13 = ( ( ( V_61 [ 4 ] & 0xf0 ) << 4 ) | V_61 [ 2 ] ) << 1 ;
V_79 -> V_85 = ( ( V_61 [ 3 ] & 0x30 ) | ( V_61 [ 5 ] & 0x0f ) ) << 1 ;
break;
case 2 :
F_47 ( & V_79 -> V_86 , V_61 [ 1 ] , V_61 [ 2 ] , V_61 [ 4 ] ) ;
break;
default:
break;
}
V_18 -> V_87 = true ;
}
static int F_49 ( const unsigned char V_61 [] ,
struct V_17 * V_18 ,
struct V_80 * V_81 )
{
memset ( V_81 , 0 , sizeof( struct V_80 ) ) ;
if ( F_50 ( V_18 -> V_22 ) ) {
V_81 -> V_83 = ( ( ( V_61 [ 0 ] & 0x30 ) >> 2 ) |
( ( V_61 [ 0 ] & 0x04 ) >> 1 ) |
( ( V_61 [ 3 ] & 0x04 ) >> 2 ) ) ;
V_81 -> V_88 = ( V_61 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_81 -> V_89 = ( V_61 [ 0 ] & 0x02 ) ? 1 : 0 ;
if ( F_51 ( V_18 -> V_33 ) ) {
V_81 -> V_88 = ( ( V_61 [ 0 ] ^ V_61 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
} else if ( F_52 ( V_18 -> V_31 ) ) {
V_81 -> V_90 = ( ( V_61 [ 0 ] ^ V_61 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
if ( V_81 -> V_83 == 2 )
V_81 -> V_91 = ( signed char ) ( V_61 [ 1 ] ) ;
}
if ( F_53 ( V_18 -> V_31 ) ) {
V_81 -> V_92 = ( ( V_61 [ 0 ] ^ V_61 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
V_81 -> V_93 = ( ( V_61 [ 0 ] ^ V_61 [ 3 ] ) & 0x02 ) ? 1 : 0 ;
}
if ( ( F_26 ( V_18 -> V_33 ) ||
F_27 ( V_18 -> V_33 ) ) &&
V_81 -> V_83 == 2 ) {
F_48 ( V_61 , V_18 , V_81 ) ;
return 1 ;
}
V_81 -> V_84 = ( ( ( V_61 [ 3 ] & 0x10 ) << 8 ) |
( ( V_61 [ 1 ] & 0x0f ) << 8 ) |
V_61 [ 4 ] ) ;
V_81 -> V_13 = ( ( ( V_61 [ 3 ] & 0x20 ) << 7 ) |
( ( V_61 [ 1 ] & 0xf0 ) << 4 ) |
V_61 [ 5 ] ) ;
V_81 -> V_85 = V_61 [ 2 ] ;
if ( F_17 ( V_18 -> V_32 ) &&
( ( V_61 [ 0 ] ^ V_61 [ 3 ] ) & 0x02 ) ) {
switch ( F_17 ( V_18 -> V_32 ) & ~ 0x01 ) {
default:
break;
case 8 :
V_81 -> V_94 |= ( ( V_61 [ 5 ] & 0x08 ) ) ? 0x80 : 0 ;
V_81 -> V_94 |= ( ( V_61 [ 4 ] & 0x08 ) ) ? 0x40 : 0 ;
case 6 :
V_81 -> V_94 |= ( ( V_61 [ 5 ] & 0x04 ) ) ? 0x20 : 0 ;
V_81 -> V_94 |= ( ( V_61 [ 4 ] & 0x04 ) ) ? 0x10 : 0 ;
case 4 :
V_81 -> V_94 |= ( ( V_61 [ 5 ] & 0x02 ) ) ? 0x08 : 0 ;
V_81 -> V_94 |= ( ( V_61 [ 4 ] & 0x02 ) ) ? 0x04 : 0 ;
case 2 :
V_81 -> V_94 |= ( ( V_61 [ 5 ] & 0x01 ) ) ? 0x02 : 0 ;
V_81 -> V_94 |= ( ( V_61 [ 4 ] & 0x01 ) ) ? 0x01 : 0 ;
}
}
} else {
V_81 -> V_84 = ( ( ( V_61 [ 1 ] & 0x1f ) << 8 ) | V_61 [ 2 ] ) ;
V_81 -> V_13 = ( ( ( V_61 [ 4 ] & 0x1f ) << 8 ) | V_61 [ 5 ] ) ;
V_81 -> V_85 = ( ( ( V_61 [ 0 ] & 0x30 ) << 2 ) | ( V_61 [ 3 ] & 0x3F ) ) ;
V_81 -> V_83 = ( ( ( V_61 [ 1 ] & 0x80 ) >> 4 ) | ( ( V_61 [ 0 ] & 0x04 ) >> 1 ) ) ;
V_81 -> V_88 = ( V_61 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_81 -> V_89 = ( V_61 [ 0 ] & 0x02 ) ? 1 : 0 ;
}
if ( V_81 -> V_84 > V_95 )
V_81 -> V_84 -= 1 << V_96 ;
else if ( V_81 -> V_84 == V_95 )
V_81 -> V_84 = V_97 ;
if ( V_81 -> V_13 > V_98 )
V_81 -> V_13 -= 1 << V_96 ;
else if ( V_81 -> V_13 == V_98 )
V_81 -> V_13 = V_99 ;
return 0 ;
}
static void F_54 ( struct V_100 * V_101 , int V_102 ,
bool V_103 , int V_84 , int V_13 )
{
F_55 ( V_101 , V_102 ) ;
F_56 ( V_101 , V_104 , V_103 ) ;
if ( V_103 ) {
F_57 ( V_101 , V_105 , V_84 ) ;
F_57 ( V_101 , V_106 , F_6 ( V_13 ) ) ;
}
}
static void F_58 ( struct V_100 * V_101 ,
const struct V_80 * V_107 ,
const struct V_80 * V_108 ,
int V_109 )
{
if ( V_109 >= 2 ) {
F_54 ( V_101 , 0 , true , F_59 ( V_107 -> V_84 , V_108 -> V_84 ) ,
F_59 ( V_107 -> V_13 , V_108 -> V_13 ) ) ;
F_54 ( V_101 , 1 , true , F_60 ( V_107 -> V_84 , V_108 -> V_84 ) ,
F_60 ( V_107 -> V_13 , V_108 -> V_13 ) ) ;
} else if ( V_109 == 1 ) {
F_54 ( V_101 , 0 , true , V_107 -> V_84 , V_107 -> V_13 ) ;
F_54 ( V_101 , 1 , false , 0 , 0 ) ;
} else {
F_54 ( V_101 , 0 , false , 0 , 0 ) ;
F_54 ( V_101 , 1 , false , 0 , 0 ) ;
}
}
static void F_61 ( struct V_1 * V_1 ,
const struct V_80 * V_81 )
{
struct V_100 * V_101 = V_1 -> V_101 ;
struct V_17 * V_18 = V_1 -> V_19 ;
int V_110 ;
F_62 ( V_101 , V_111 , V_81 -> V_88 ) ;
F_62 ( V_101 , V_112 , V_81 -> V_89 ) ;
if ( F_52 ( V_18 -> V_31 ) )
F_62 ( V_101 , V_113 , V_81 -> V_90 ) ;
if ( F_53 ( V_18 -> V_31 ) ) {
F_62 ( V_101 , V_114 , V_81 -> V_92 ) ;
F_62 ( V_101 , V_115 , V_81 -> V_93 ) ;
}
for ( V_110 = 0 ; V_110 < F_17 ( V_18 -> V_32 ) ; V_110 ++ )
F_62 ( V_101 , V_116 + V_110 , V_81 -> V_94 & ( 1 << V_110 ) ) ;
}
static void F_63 ( struct V_100 * V_101 , int V_102 ,
const struct V_80 * V_81 )
{
F_55 ( V_101 , V_102 ) ;
F_56 ( V_101 , V_104 , ( V_81 != NULL ) ) ;
if ( ! V_81 )
return;
F_57 ( V_101 , V_105 , V_81 -> V_84 ) ;
F_57 ( V_101 , V_106 , F_6 ( V_81 -> V_13 ) ) ;
F_57 ( V_101 , V_117 , V_81 -> V_85 ) ;
}
static void F_64 ( struct V_1 * V_1 ,
struct V_76 * V_86 ,
const struct V_80 * V_78 )
{
struct V_100 * V_101 = V_1 -> V_101 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_80 * V_79 = & V_18 -> V_79 ;
struct V_76 * V_118 = & V_18 -> V_86 ;
switch ( V_86 -> V_77 ) {
case 0 :
F_63 ( V_101 , 0 , NULL ) ;
F_63 ( V_101 , 1 , NULL ) ;
break;
case 1 :
if ( V_86 -> V_78 == - 1 ) {
F_63 ( V_101 , 0 , NULL ) ;
F_63 ( V_101 , 1 , NULL ) ;
} else if ( V_86 -> V_78 == 0 ) {
F_63 ( V_101 , 0 , V_78 ) ;
F_63 ( V_101 , 1 , NULL ) ;
} else {
F_63 ( V_101 , 0 , NULL ) ;
F_63 ( V_101 , 1 , V_78 ) ;
}
break;
default:
if ( V_86 -> V_78 != - 1 &&
( V_86 -> V_78 == V_118 -> V_78 ||
V_118 -> V_78 == - 1 || V_86 -> V_79 == V_118 -> V_78 ) )
F_63 ( V_101 , 0 , V_78 ) ;
else
F_63 ( V_101 , 0 , NULL ) ;
if ( V_86 -> V_79 != - 1 &&
( V_86 -> V_79 == V_118 -> V_79 ||
( V_118 -> V_79 == - 1 &&
( V_118 -> V_78 == - 1 || V_86 -> V_79 == V_118 -> V_78 ) ) ) )
F_63 ( V_101 , 1 , V_79 ) ;
else
F_63 ( V_101 , 1 , NULL ) ;
break;
}
F_65 ( V_101 , false ) ;
F_66 ( V_101 , V_86 -> V_77 ) ;
F_61 ( V_1 , V_78 ) ;
F_67 ( V_101 ) ;
}
static void F_68 ( struct V_17 * V_18 ,
struct V_76 * V_86 )
{
F_47 ( V_86 , 0 , - 1 , - 1 ) ;
V_18 -> V_119 = false ;
}
static void F_69 ( struct V_17 * V_18 ,
struct V_76 * V_86 )
{
struct V_80 * V_79 = & V_18 -> V_79 ;
struct V_76 * V_118 = & V_18 -> V_86 ;
if ( V_18 -> V_87 && V_79 -> V_85 == 0 ) {
F_47 ( V_86 , 1 , 0 , - 1 ) ;
V_18 -> V_119 = false ;
return;
}
switch ( V_118 -> V_77 ) {
case 0 :
F_47 ( V_86 , 1 , 0 , - 1 ) ;
break;
case 1 :
if ( V_18 -> V_119 ||
( V_18 -> V_87 && V_118 -> V_78 <= 0 ) )
F_47 ( V_86 , 1 , 1 , - 1 ) ;
else if ( V_118 -> V_78 == - 1 )
F_47 ( V_86 , 1 , 0 , - 1 ) ;
break;
case 2 :
if ( V_18 -> V_119 ) {
F_47 ( V_86 , 1 , - 1 , - 1 ) ;
break;
}
F_47 ( V_86 , 1 , V_118 -> V_79 , - 1 ) ;
break;
case 3 :
F_47 ( V_86 , 1 , - 1 , - 1 ) ;
V_18 -> V_119 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_70 ( struct V_17 * V_18 ,
struct V_76 * V_86 )
{
struct V_76 * V_118 = & V_18 -> V_86 ;
switch ( V_118 -> V_77 ) {
case 0 :
F_47 ( V_86 , 2 , 0 , 1 ) ;
break;
case 1 :
if ( V_118 -> V_78 >= 1 )
F_47 ( V_86 , 2 , 0 , V_118 -> V_78 ) ;
else
F_47 ( V_86 , 2 , 0 , 1 ) ;
break;
case 2 :
if ( V_18 -> V_119 )
F_47 ( V_86 , 2 , 0 , 1 ) ;
break;
case 3 :
F_47 ( V_86 , 2 , - 1 , - 1 ) ;
V_18 -> V_119 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_71 ( struct V_17 * V_18 ,
struct V_76 * V_86 )
{
struct V_76 * V_118 = & V_18 -> V_86 ;
switch ( V_118 -> V_77 ) {
case 0 :
F_47 ( V_86 , 3 , 0 , 2 ) ;
break;
case 1 :
if ( V_118 -> V_78 >= 2 )
F_47 ( V_86 , 3 , 0 , V_118 -> V_78 ) ;
else
F_47 ( V_86 , 3 , 0 , 2 ) ;
break;
case 2 :
if ( V_118 -> V_79 >= 3 ) {
F_47 ( V_86 , 3 , 0 , V_118 -> V_79 ) ;
break;
}
if ( V_18 -> V_119 ) {
F_47 ( V_86 , 3 , - 1 , - 1 ) ;
break;
}
F_47 ( V_86 , 3 , 0 , - 1 ) ;
break;
case 3 :
if ( V_118 -> V_79 <= 2 )
F_47 ( V_86 , 3 , 0 , 2 ) ;
break;
case 4 :
case 5 :
break;
}
}
static void F_72 ( struct V_17 * V_18 ,
struct V_76 * V_86 )
{
V_18 -> V_119 = false ;
}
static void F_73 ( struct V_1 * V_1 ,
struct V_80 * V_78 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_80 * V_79 = & V_18 -> V_79 ;
struct V_76 V_86 ;
V_86 = V_79 -> V_86 ;
if ( V_78 -> V_85 == 0 )
F_68 ( V_18 , & V_86 ) ;
else if ( V_78 -> V_83 >= 4 )
F_69 ( V_18 , & V_86 ) ;
else if ( V_78 -> V_83 == 0 )
F_70 ( V_18 , & V_86 ) ;
else if ( V_78 -> V_83 == 1 && V_86 . V_77 <= 3 )
F_71 ( V_18 , & V_86 ) ;
else
F_72 ( V_18 , & V_86 ) ;
F_64 ( V_1 , & V_86 , V_78 ) ;
V_18 -> V_86 = V_79 -> V_86 = V_86 ;
V_18 -> V_87 = false ;
}
static void F_74 ( struct V_1 * V_1 )
{
struct V_100 * V_101 = V_1 -> V_101 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_80 V_81 ;
int V_109 ;
int V_120 ;
if ( F_49 ( V_1 -> V_63 , V_18 , & V_81 ) )
return;
if ( F_27 ( V_18 -> V_33 ) ) {
F_73 ( V_1 , & V_81 ) ;
return;
}
if ( V_81 . V_91 ) {
V_18 -> V_91 += V_81 . V_91 ;
while ( V_18 -> V_91 >= 4 ) {
F_62 ( V_101 , V_115 , ! V_81 . V_93 ) ;
F_67 ( V_101 ) ;
F_62 ( V_101 , V_115 , V_81 . V_93 ) ;
F_67 ( V_101 ) ;
V_18 -> V_91 -= 4 ;
}
while ( V_18 -> V_91 <= - 4 ) {
F_62 ( V_101 , V_114 , ! V_81 . V_92 ) ;
F_67 ( V_101 ) ;
F_62 ( V_101 , V_114 , V_81 . V_92 ) ;
F_67 ( V_101 ) ;
V_18 -> V_91 += 4 ;
}
return;
}
if ( V_81 . V_85 > 0 && V_81 . V_84 > 1 ) {
V_109 = 1 ;
V_120 = 5 ;
if ( F_14 ( V_18 -> V_31 ) ) {
switch ( V_81 . V_83 ) {
case 0 ... 1 :
if ( F_75 ( V_18 -> V_31 ) )
V_109 = V_81 . V_83 + 2 ;
break;
case 2 :
if ( F_76 ( V_18 -> V_22 ) )
;
break;
case 4 ... 15 :
if ( F_77 ( V_18 -> V_31 ) )
V_120 = V_81 . V_83 ;
break;
}
}
} else {
V_109 = 0 ;
V_120 = 0 ;
}
if ( F_26 ( V_18 -> V_33 ) )
F_58 ( V_101 , & V_81 , & V_18 -> V_79 ,
V_109 ) ;
if ( V_81 . V_85 > 30 ) F_62 ( V_101 , V_121 , 1 ) ;
if ( V_81 . V_85 < 25 ) F_62 ( V_101 , V_121 , 0 ) ;
if ( V_109 > 0 ) {
F_57 ( V_101 , V_122 , V_81 . V_84 ) ;
F_57 ( V_101 , V_123 , F_6 ( V_81 . V_13 ) ) ;
}
F_57 ( V_101 , V_124 , V_81 . V_85 ) ;
if ( F_77 ( V_18 -> V_31 ) )
F_57 ( V_101 , V_125 , V_120 ) ;
F_62 ( V_101 , V_126 , V_109 == 1 ) ;
if ( F_75 ( V_18 -> V_31 ) ) {
F_62 ( V_101 , V_127 , V_109 == 2 ) ;
F_62 ( V_101 , V_128 , V_109 == 3 ) ;
}
F_61 ( V_1 , & V_81 ) ;
F_67 ( V_101 ) ;
}
static int F_78 ( struct V_1 * V_1 ,
int V_129 , unsigned char V_130 )
{
static const unsigned char V_131 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const unsigned char V_132 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_133 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_134 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const unsigned char V_135 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
const char * V_63 = V_1 -> V_63 ;
if ( V_129 < 0 || V_129 > 4 )
return 0 ;
switch ( V_130 ) {
case V_136 :
case V_137 :
return ( V_63 [ V_129 ] & V_132 [ V_129 ] ) == V_133 [ V_129 ] ;
case V_138 :
return ( V_63 [ V_129 ] & V_131 [ V_129 ] ) == V_133 [ V_129 ] ;
case V_139 :
return ( V_63 [ V_129 ] & V_134 [ V_129 ] ) == V_135 [ V_129 ] ;
default:
F_30 ( V_1 , L_13 , V_130 ) ;
return 0 ;
}
}
static unsigned char F_79 ( struct V_1 * V_1 )
{
int V_110 ;
for ( V_110 = 0 ; V_110 < 5 ; V_110 ++ )
if ( ! F_78 ( V_1 , V_110 , V_138 ) ) {
F_45 ( V_1 , L_14 ) ;
return V_137 ;
}
return V_138 ;
}
static T_1 F_80 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( V_1 -> V_140 >= 6 ) {
if ( F_81 ( V_18 -> V_130 == V_136 ) )
V_18 -> V_130 = F_79 ( V_1 ) ;
if ( F_82 ( V_18 -> V_31 ) &&
F_38 ( V_1 -> V_63 ) ) {
if ( V_18 -> V_60 )
F_39 ( V_18 -> V_60 , V_1 -> V_63 ) ;
} else
F_74 ( V_1 ) ;
return V_141 ;
}
return F_78 ( V_1 , V_1 -> V_140 - 1 , V_18 -> V_130 ) ?
V_142 : V_143 ;
}
static void F_83 ( struct V_100 * V_101 ,
struct V_17 * V_18 , int V_144 ,
int V_145 )
{
int V_47 = V_18 -> V_47 ? : V_146 ;
int V_44 = V_18 -> V_44 ? : V_147 ;
int V_48 = V_18 -> V_48 ? : V_15 ;
int V_45 = V_18 -> V_45 ? : V_14 ;
int V_148 = F_84 ( V_18 -> V_33 ) ?
V_149 : 0 ;
F_85 ( V_101 , V_144 , V_47 , V_44 , V_148 , 0 ) ;
F_85 ( V_101 , V_145 , V_48 , V_45 , V_148 , 0 ) ;
F_86 ( V_101 , V_144 , V_18 -> V_41 ) ;
F_86 ( V_101 , V_145 , V_18 -> V_42 ) ;
}
static void F_87 ( struct V_100 * V_101 , struct V_17 * V_18 )
{
int V_110 ;
F_88 ( V_150 , V_101 -> V_151 ) ;
F_88 ( V_152 , V_101 -> V_153 ) ;
F_88 ( V_111 , V_101 -> V_154 ) ;
F_88 ( V_112 , V_101 -> V_154 ) ;
if ( F_52 ( V_18 -> V_31 ) )
F_88 ( V_113 , V_101 -> V_154 ) ;
if ( ! V_18 -> V_49 ) {
F_88 ( V_155 , V_101 -> V_153 ) ;
F_88 ( V_156 , V_101 -> V_157 ) ;
F_88 ( V_158 , V_101 -> V_157 ) ;
return;
}
F_88 ( V_159 , V_101 -> V_153 ) ;
F_83 ( V_101 , V_18 , V_122 , V_123 ) ;
F_85 ( V_101 , V_124 , 0 , 255 , 0 , 0 ) ;
if ( F_27 ( V_18 -> V_33 ) ) {
F_83 ( V_101 , V_18 , V_105 ,
V_106 ) ;
F_85 ( V_101 , V_117 , 0 , 255 , 0 , 0 ) ;
F_89 ( V_101 , 2 , V_160 ) ;
F_88 ( V_161 , V_101 -> V_154 ) ;
F_88 ( V_162 , V_101 -> V_154 ) ;
} else if ( F_26 ( V_18 -> V_33 ) ) {
F_88 ( V_163 , V_101 -> V_151 ) ;
F_89 ( V_101 , 2 , 0 ) ;
F_83 ( V_101 , V_18 , V_105 ,
V_106 ) ;
}
if ( F_77 ( V_18 -> V_31 ) )
F_85 ( V_101 , V_125 , 0 , 15 , 0 , 0 ) ;
F_88 ( V_121 , V_101 -> V_154 ) ;
F_88 ( V_126 , V_101 -> V_154 ) ;
if ( F_75 ( V_18 -> V_31 ) ) {
F_88 ( V_127 , V_101 -> V_154 ) ;
F_88 ( V_128 , V_101 -> V_154 ) ;
}
if ( F_53 ( V_18 -> V_31 ) ||
F_52 ( V_18 -> V_31 ) ) {
F_88 ( V_114 , V_101 -> V_154 ) ;
F_88 ( V_115 , V_101 -> V_154 ) ;
}
for ( V_110 = 0 ; V_110 < F_17 ( V_18 -> V_32 ) ; V_110 ++ )
F_88 ( V_116 + V_110 , V_101 -> V_154 ) ;
F_90 ( V_155 , V_101 -> V_153 ) ;
F_90 ( V_156 , V_101 -> V_157 ) ;
F_90 ( V_158 , V_101 -> V_157 ) ;
if ( F_51 ( V_18 -> V_33 ) ) {
F_88 ( V_164 , V_101 -> V_151 ) ;
F_90 ( V_112 , V_101 -> V_154 ) ;
F_90 ( V_113 , V_101 -> V_154 ) ;
}
}
static T_2 F_91 ( struct V_1 * V_1 ,
void * V_165 , char * V_61 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
return sprintf ( V_61 , L_15 , V_18 -> V_51 ? '1' : '0' ) ;
}
static T_2 F_92 ( struct V_1 * V_1 ,
void * V_165 , const char * V_61 ,
T_3 V_166 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned int V_167 ;
int V_168 ;
V_168 = F_93 ( V_61 , 10 , & V_167 ) ;
if ( V_168 )
return V_168 ;
if ( V_167 > 1 )
return - V_169 ;
if ( V_167 == V_18 -> V_51 )
return V_166 ;
V_18 -> V_51 = V_167 ;
if ( V_167 )
V_18 -> V_2 |= V_52 ;
else
V_18 -> V_2 &= ~ V_52 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
return - V_170 ;
return V_166 ;
}
static void F_94 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( ! V_18 -> V_49 && F_95 ( V_18 -> V_34 ) )
F_96 ( & V_1 -> V_5 . V_56 -> V_101 ,
& V_171 . V_172 ) ;
F_5 ( V_1 ) ;
F_97 ( V_18 ) ;
V_1 -> V_19 = NULL ;
}
static int F_98 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_17 V_173 = * V_18 ;
unsigned char V_3 [ 2 ] ;
int V_174 = 0 ;
int error ;
do {
F_99 ( V_1 ) ;
if ( V_174 ) {
F_100 ( 1 ) ;
}
F_3 ( & V_1 -> V_5 , V_3 , V_175 ) ;
error = F_4 ( V_1 , 0 ) ;
} while ( error && ++ V_174 < 3 );
if ( error )
return - 1 ;
if ( V_174 > 1 )
F_101 ( V_1 , L_16 , V_174 ) ;
if ( F_24 ( V_1 ) ) {
F_30 ( V_1 , L_17 ) ;
return - 1 ;
}
if ( F_29 ( V_1 ) ) {
F_30 ( V_1 , L_18 ) ;
return - 1 ;
}
if ( V_173 . V_34 != V_18 -> V_34 ||
V_173 . V_22 != V_18 -> V_22 ||
V_173 . V_31 != V_18 -> V_31 ||
V_173 . V_32 != V_18 -> V_32 ) {
F_30 ( V_1 ,
L_19 ,
V_173 . V_34 , V_18 -> V_34 ,
V_173 . V_22 , V_18 -> V_22 ,
V_173 . V_31 , V_18 -> V_31 ,
V_173 . V_32 , V_18 -> V_32 ) ;
return - 1 ;
}
return 0 ;
}
void T_4 F_102 ( void )
{
V_176 = F_103 ( V_177 ) ;
V_178 = F_103 ( V_179 ) ;
}
static int F_104 ( struct V_1 * V_1 , bool V_49 )
{
struct V_17 * V_18 ;
int V_168 = - 1 ;
if ( V_49 && V_178 ) {
F_45 ( V_1 ,
L_20 ) ;
return - V_10 ;
}
V_1 -> V_19 = V_18 = F_43 ( sizeof( struct V_17 ) , V_69 ) ;
if ( ! V_18 )
return - V_180 ;
F_99 ( V_1 ) ;
if ( F_24 ( V_1 ) ) {
F_30 ( V_1 , L_17 ) ;
goto V_181;
}
V_18 -> V_49 = V_49 ;
if ( F_95 ( V_18 -> V_34 ) )
V_18 -> V_51 = true ;
if ( F_29 ( V_1 ) ) {
F_30 ( V_1 , L_18 ) ;
goto V_181;
}
V_18 -> V_130 = F_50 ( V_18 -> V_22 ) ? V_136 : V_139 ;
F_45 ( V_1 ,
L_21 ,
F_105 ( V_18 -> V_34 ) ,
F_21 ( V_18 -> V_34 ) , F_106 ( V_18 -> V_34 ) ,
V_18 -> V_22 ,
V_18 -> V_31 , V_18 -> V_32 , V_18 -> V_33 ,
V_18 -> V_25 , V_18 -> V_28 ) ;
F_87 ( V_1 -> V_101 , V_18 ) ;
V_1 -> V_182 = ( ( V_18 -> V_22 & 0x00ff0000 ) >> 8 ) |
( V_18 -> V_22 & 0x000000ff ) ;
if ( V_49 ) {
V_1 -> V_183 = F_80 ;
V_1 -> V_67 = 6 ;
} else {
V_1 -> V_183 = V_184 ;
V_1 -> V_67 = 3 ;
}
V_1 -> V_185 = F_31 ;
V_1 -> V_186 = F_94 ;
V_1 -> V_187 = F_98 ;
V_1 -> V_188 = F_5 ;
V_1 -> V_189 = 0 ;
if ( F_82 ( V_18 -> V_31 ) )
F_42 ( V_1 ) ;
if ( V_1 -> V_53 >= 80 && V_176 ) {
F_45 ( V_1 ,
L_22 ,
F_107 ( V_190 ) ) ;
V_1 -> V_53 = 40 ;
}
if ( ! V_18 -> V_49 && F_95 ( V_18 -> V_34 ) ) {
V_168 = F_108 ( & V_1 -> V_5 . V_56 -> V_101 ,
& V_171 . V_172 ) ;
if ( V_168 ) {
F_30 ( V_1 ,
L_23 ,
V_168 ) ;
goto V_181;
}
}
return 0 ;
V_181:
F_97 ( V_18 ) ;
return V_168 ;
}
int F_109 ( struct V_1 * V_1 )
{
return F_104 ( V_1 , true ) ;
}
int F_110 ( struct V_1 * V_1 )
{
return F_104 ( V_1 , false ) ;
}
bool F_111 ( void )
{
return true ;
}
void T_4 F_102 ( void )
{
}
int F_109 ( struct V_1 * V_1 )
{
return - V_191 ;
}
bool F_111 ( void )
{
return false ;
}
