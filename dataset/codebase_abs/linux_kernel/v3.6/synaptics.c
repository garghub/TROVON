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
if ( V_81 -> V_13 > V_97 )
V_81 -> V_13 -= 1 << V_96 ;
return 0 ;
}
static void F_54 ( struct V_98 * V_99 , int V_100 ,
bool V_101 , int V_84 , int V_13 )
{
F_55 ( V_99 , V_100 ) ;
F_56 ( V_99 , V_102 , V_101 ) ;
if ( V_101 ) {
F_57 ( V_99 , V_103 , V_84 ) ;
F_57 ( V_99 , V_104 , F_6 ( V_13 ) ) ;
}
}
static void F_58 ( struct V_98 * V_99 ,
const struct V_80 * V_105 ,
const struct V_80 * V_106 ,
int V_107 )
{
if ( V_107 >= 2 ) {
F_54 ( V_99 , 0 , true , F_59 ( V_105 -> V_84 , V_106 -> V_84 ) ,
F_59 ( V_105 -> V_13 , V_106 -> V_13 ) ) ;
F_54 ( V_99 , 1 , true , F_60 ( V_105 -> V_84 , V_106 -> V_84 ) ,
F_60 ( V_105 -> V_13 , V_106 -> V_13 ) ) ;
} else if ( V_107 == 1 ) {
F_54 ( V_99 , 0 , true , V_105 -> V_84 , V_105 -> V_13 ) ;
F_54 ( V_99 , 1 , false , 0 , 0 ) ;
} else {
F_54 ( V_99 , 0 , false , 0 , 0 ) ;
F_54 ( V_99 , 1 , false , 0 , 0 ) ;
}
}
static void F_61 ( struct V_1 * V_1 ,
const struct V_80 * V_81 )
{
struct V_98 * V_99 = V_1 -> V_99 ;
struct V_17 * V_18 = V_1 -> V_19 ;
int V_108 ;
F_62 ( V_99 , V_109 , V_81 -> V_88 ) ;
F_62 ( V_99 , V_110 , V_81 -> V_89 ) ;
if ( F_52 ( V_18 -> V_31 ) )
F_62 ( V_99 , V_111 , V_81 -> V_90 ) ;
if ( F_53 ( V_18 -> V_31 ) ) {
F_62 ( V_99 , V_112 , V_81 -> V_92 ) ;
F_62 ( V_99 , V_113 , V_81 -> V_93 ) ;
}
for ( V_108 = 0 ; V_108 < F_17 ( V_18 -> V_32 ) ; V_108 ++ )
F_62 ( V_99 , V_114 + V_108 , V_81 -> V_94 & ( 1 << V_108 ) ) ;
}
static void F_63 ( struct V_98 * V_99 , int V_100 ,
const struct V_80 * V_81 )
{
F_55 ( V_99 , V_100 ) ;
F_56 ( V_99 , V_102 , ( V_81 != NULL ) ) ;
if ( ! V_81 )
return;
F_57 ( V_99 , V_103 , V_81 -> V_84 ) ;
F_57 ( V_99 , V_104 , F_6 ( V_81 -> V_13 ) ) ;
F_57 ( V_99 , V_115 , V_81 -> V_85 ) ;
}
static void F_64 ( struct V_1 * V_1 ,
struct V_76 * V_86 ,
const struct V_80 * V_78 )
{
struct V_98 * V_99 = V_1 -> V_99 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_80 * V_79 = & V_18 -> V_79 ;
struct V_76 * V_116 = & V_18 -> V_86 ;
switch ( V_86 -> V_77 ) {
case 0 :
F_63 ( V_99 , 0 , NULL ) ;
F_63 ( V_99 , 1 , NULL ) ;
break;
case 1 :
if ( V_86 -> V_78 == - 1 ) {
F_63 ( V_99 , 0 , NULL ) ;
F_63 ( V_99 , 1 , NULL ) ;
} else if ( V_86 -> V_78 == 0 ) {
F_63 ( V_99 , 0 , V_78 ) ;
F_63 ( V_99 , 1 , NULL ) ;
} else {
F_63 ( V_99 , 0 , NULL ) ;
F_63 ( V_99 , 1 , V_78 ) ;
}
break;
default:
if ( V_86 -> V_78 != - 1 &&
( V_86 -> V_78 == V_116 -> V_78 || V_116 -> V_78 == - 1 ) )
F_63 ( V_99 , 0 , V_78 ) ;
else
F_63 ( V_99 , 0 , NULL ) ;
if ( V_86 -> V_79 != - 1 &&
( V_86 -> V_79 == V_116 -> V_79 || V_116 -> V_79 == - 1 ) )
F_63 ( V_99 , 1 , V_79 ) ;
else
F_63 ( V_99 , 1 , NULL ) ;
break;
}
F_65 ( V_99 , false ) ;
F_66 ( V_99 , V_86 -> V_77 ) ;
F_61 ( V_1 , V_78 ) ;
F_67 ( V_99 ) ;
}
static void F_68 ( struct V_17 * V_18 ,
struct V_76 * V_86 )
{
F_47 ( V_86 , 0 , - 1 , - 1 ) ;
V_18 -> V_117 = false ;
}
static void F_69 ( struct V_17 * V_18 ,
struct V_76 * V_86 )
{
struct V_80 * V_79 = & V_18 -> V_79 ;
struct V_76 * V_116 = & V_18 -> V_86 ;
if ( V_18 -> V_87 && V_79 -> V_85 == 0 ) {
F_47 ( V_86 , 1 , 0 , - 1 ) ;
V_18 -> V_117 = false ;
return;
}
switch ( V_116 -> V_77 ) {
case 0 :
F_47 ( V_86 , 1 , 0 , - 1 ) ;
break;
case 1 :
if ( V_18 -> V_117 ||
( V_18 -> V_87 && V_116 -> V_78 <= 0 ) )
F_47 ( V_86 , 1 , 1 , - 1 ) ;
else if ( V_116 -> V_78 == - 1 )
F_47 ( V_86 , 1 , 0 , - 1 ) ;
break;
case 2 :
if ( V_18 -> V_117 ) {
F_47 ( V_86 , 1 , - 1 , - 1 ) ;
break;
}
F_47 ( V_86 , 1 , V_116 -> V_79 , - 1 ) ;
break;
case 3 :
F_47 ( V_86 , 1 , - 1 , - 1 ) ;
V_18 -> V_117 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_70 ( struct V_17 * V_18 ,
struct V_76 * V_86 )
{
struct V_76 * V_116 = & V_18 -> V_86 ;
switch ( V_116 -> V_77 ) {
case 0 :
F_47 ( V_86 , 2 , 0 , 1 ) ;
break;
case 1 :
if ( V_116 -> V_78 >= 1 )
F_47 ( V_86 , 2 , 0 , V_116 -> V_78 ) ;
else
F_47 ( V_86 , 2 , 0 , 1 ) ;
break;
case 2 :
if ( V_18 -> V_117 )
F_47 ( V_86 , 2 , 0 , 1 ) ;
break;
case 3 :
F_47 ( V_86 , 2 , - 1 , - 1 ) ;
V_18 -> V_117 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_71 ( struct V_17 * V_18 ,
struct V_76 * V_86 )
{
struct V_76 * V_116 = & V_18 -> V_86 ;
switch ( V_116 -> V_77 ) {
case 0 :
F_47 ( V_86 , 3 , 0 , 2 ) ;
break;
case 1 :
if ( V_116 -> V_78 >= 2 )
F_47 ( V_86 , 3 , 0 , V_116 -> V_78 ) ;
else
F_47 ( V_86 , 3 , 0 , 2 ) ;
break;
case 2 :
if ( V_116 -> V_79 >= 3 ) {
F_47 ( V_86 , 3 , 0 , V_116 -> V_79 ) ;
break;
}
if ( V_18 -> V_117 ) {
F_47 ( V_86 , 3 , - 1 , - 1 ) ;
break;
}
F_47 ( V_86 , 3 , 0 , - 1 ) ;
break;
case 3 :
if ( V_116 -> V_79 <= 2 )
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
V_18 -> V_117 = false ;
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
struct V_98 * V_99 = V_1 -> V_99 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_80 V_81 ;
int V_107 ;
int V_118 ;
if ( F_49 ( V_1 -> V_63 , V_18 , & V_81 ) )
return;
if ( F_27 ( V_18 -> V_33 ) ) {
F_73 ( V_1 , & V_81 ) ;
return;
}
if ( V_81 . V_91 ) {
V_18 -> V_91 += V_81 . V_91 ;
while ( V_18 -> V_91 >= 4 ) {
F_62 ( V_99 , V_113 , ! V_81 . V_93 ) ;
F_67 ( V_99 ) ;
F_62 ( V_99 , V_113 , V_81 . V_93 ) ;
F_67 ( V_99 ) ;
V_18 -> V_91 -= 4 ;
}
while ( V_18 -> V_91 <= - 4 ) {
F_62 ( V_99 , V_112 , ! V_81 . V_92 ) ;
F_67 ( V_99 ) ;
F_62 ( V_99 , V_112 , V_81 . V_92 ) ;
F_67 ( V_99 ) ;
V_18 -> V_91 += 4 ;
}
return;
}
if ( V_81 . V_85 > 0 && V_81 . V_84 > 1 ) {
V_107 = 1 ;
V_118 = 5 ;
if ( F_14 ( V_18 -> V_31 ) ) {
switch ( V_81 . V_83 ) {
case 0 ... 1 :
if ( F_75 ( V_18 -> V_31 ) )
V_107 = V_81 . V_83 + 2 ;
break;
case 2 :
if ( F_76 ( V_18 -> V_22 ) )
;
break;
case 4 ... 15 :
if ( F_77 ( V_18 -> V_31 ) )
V_118 = V_81 . V_83 ;
break;
}
}
} else {
V_107 = 0 ;
V_118 = 0 ;
}
if ( F_26 ( V_18 -> V_33 ) )
F_58 ( V_99 , & V_81 , & V_18 -> V_79 ,
V_107 ) ;
if ( V_81 . V_85 > 30 ) F_62 ( V_99 , V_119 , 1 ) ;
if ( V_81 . V_85 < 25 ) F_62 ( V_99 , V_119 , 0 ) ;
if ( V_107 > 0 ) {
F_57 ( V_99 , V_120 , V_81 . V_84 ) ;
F_57 ( V_99 , V_121 , F_6 ( V_81 . V_13 ) ) ;
}
F_57 ( V_99 , V_122 , V_81 . V_85 ) ;
if ( F_77 ( V_18 -> V_31 ) )
F_57 ( V_99 , V_123 , V_118 ) ;
F_62 ( V_99 , V_124 , V_107 == 1 ) ;
if ( F_75 ( V_18 -> V_31 ) ) {
F_62 ( V_99 , V_125 , V_107 == 2 ) ;
F_62 ( V_99 , V_126 , V_107 == 3 ) ;
}
F_61 ( V_1 , & V_81 ) ;
F_67 ( V_99 ) ;
}
static int F_78 ( struct V_1 * V_1 ,
int V_127 , unsigned char V_128 )
{
static const unsigned char V_129 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const unsigned char V_130 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_131 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_132 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const unsigned char V_133 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
const char * V_63 = V_1 -> V_63 ;
if ( V_127 < 0 || V_127 > 4 )
return 0 ;
switch ( V_128 ) {
case V_134 :
case V_135 :
return ( V_63 [ V_127 ] & V_130 [ V_127 ] ) == V_131 [ V_127 ] ;
case V_136 :
return ( V_63 [ V_127 ] & V_129 [ V_127 ] ) == V_131 [ V_127 ] ;
case V_137 :
return ( V_63 [ V_127 ] & V_132 [ V_127 ] ) == V_133 [ V_127 ] ;
default:
F_30 ( V_1 , L_13 , V_128 ) ;
return 0 ;
}
}
static unsigned char F_79 ( struct V_1 * V_1 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < 5 ; V_108 ++ )
if ( ! F_78 ( V_1 , V_108 , V_136 ) ) {
F_45 ( V_1 , L_14 ) ;
return V_135 ;
}
return V_136 ;
}
static T_1 F_80 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( V_1 -> V_138 >= 6 ) {
if ( F_81 ( V_18 -> V_128 == V_134 ) )
V_18 -> V_128 = F_79 ( V_1 ) ;
if ( F_82 ( V_18 -> V_31 ) &&
F_38 ( V_1 -> V_63 ) ) {
if ( V_18 -> V_60 )
F_39 ( V_18 -> V_60 , V_1 -> V_63 ) ;
} else
F_74 ( V_1 ) ;
return V_139 ;
}
return F_78 ( V_1 , V_1 -> V_138 - 1 , V_18 -> V_128 ) ?
V_140 : V_141 ;
}
static void F_83 ( struct V_98 * V_99 ,
struct V_17 * V_18 , int V_142 ,
int V_143 )
{
int V_47 = V_18 -> V_47 ? : V_144 ;
int V_44 = V_18 -> V_44 ? : V_145 ;
int V_48 = V_18 -> V_48 ? : V_15 ;
int V_45 = V_18 -> V_45 ? : V_14 ;
int V_146 = F_84 ( V_18 -> V_33 ) ?
V_147 : 0 ;
F_85 ( V_99 , V_142 , V_47 , V_44 , V_146 , 0 ) ;
F_85 ( V_99 , V_143 , V_48 , V_45 , V_146 , 0 ) ;
F_86 ( V_99 , V_142 , V_18 -> V_41 ) ;
F_86 ( V_99 , V_143 , V_18 -> V_42 ) ;
}
static void F_87 ( struct V_98 * V_99 , struct V_17 * V_18 )
{
int V_108 ;
F_88 ( V_148 , V_99 -> V_149 ) ;
F_88 ( V_150 , V_99 -> V_151 ) ;
F_88 ( V_109 , V_99 -> V_152 ) ;
F_88 ( V_110 , V_99 -> V_152 ) ;
if ( F_52 ( V_18 -> V_31 ) )
F_88 ( V_111 , V_99 -> V_152 ) ;
if ( ! V_18 -> V_49 ) {
F_88 ( V_153 , V_99 -> V_151 ) ;
F_88 ( V_154 , V_99 -> V_155 ) ;
F_88 ( V_156 , V_99 -> V_155 ) ;
return;
}
F_88 ( V_157 , V_99 -> V_151 ) ;
F_83 ( V_99 , V_18 , V_120 , V_121 ) ;
F_85 ( V_99 , V_122 , 0 , 255 , 0 , 0 ) ;
if ( F_27 ( V_18 -> V_33 ) ) {
F_89 ( V_99 , 2 ) ;
F_83 ( V_99 , V_18 , V_103 ,
V_104 ) ;
F_85 ( V_99 , V_115 , 0 , 255 , 0 , 0 ) ;
F_88 ( V_158 , V_99 -> V_152 ) ;
F_88 ( V_159 , V_99 -> V_152 ) ;
} else if ( F_26 ( V_18 -> V_33 ) ) {
F_88 ( V_160 , V_99 -> V_149 ) ;
F_89 ( V_99 , 2 ) ;
F_83 ( V_99 , V_18 , V_103 ,
V_104 ) ;
}
if ( F_77 ( V_18 -> V_31 ) )
F_85 ( V_99 , V_123 , 0 , 15 , 0 , 0 ) ;
F_88 ( V_119 , V_99 -> V_152 ) ;
F_88 ( V_124 , V_99 -> V_152 ) ;
if ( F_75 ( V_18 -> V_31 ) ) {
F_88 ( V_125 , V_99 -> V_152 ) ;
F_88 ( V_126 , V_99 -> V_152 ) ;
}
if ( F_53 ( V_18 -> V_31 ) ||
F_52 ( V_18 -> V_31 ) ) {
F_88 ( V_112 , V_99 -> V_152 ) ;
F_88 ( V_113 , V_99 -> V_152 ) ;
}
for ( V_108 = 0 ; V_108 < F_17 ( V_18 -> V_32 ) ; V_108 ++ )
F_88 ( V_114 + V_108 , V_99 -> V_152 ) ;
F_90 ( V_153 , V_99 -> V_151 ) ;
F_90 ( V_154 , V_99 -> V_155 ) ;
F_90 ( V_156 , V_99 -> V_155 ) ;
if ( F_51 ( V_18 -> V_33 ) ) {
F_88 ( V_161 , V_99 -> V_149 ) ;
F_90 ( V_110 , V_99 -> V_152 ) ;
F_90 ( V_111 , V_99 -> V_152 ) ;
}
}
static T_2 F_91 ( struct V_1 * V_1 ,
void * V_162 , char * V_61 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
return sprintf ( V_61 , L_15 , V_18 -> V_51 ? '1' : '0' ) ;
}
static T_2 F_92 ( struct V_1 * V_1 ,
void * V_162 , const char * V_61 ,
T_3 V_163 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned int V_164 ;
int V_165 ;
V_165 = F_93 ( V_61 , 10 , & V_164 ) ;
if ( V_165 )
return V_165 ;
if ( V_164 > 1 )
return - V_166 ;
if ( V_164 == V_18 -> V_51 )
return V_163 ;
V_18 -> V_51 = V_164 ;
if ( V_164 )
V_18 -> V_2 |= V_52 ;
else
V_18 -> V_2 &= ~ V_52 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
return - V_167 ;
return V_163 ;
}
static void F_94 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( ! V_18 -> V_49 && F_95 ( V_18 -> V_34 ) )
F_96 ( & V_1 -> V_5 . V_56 -> V_99 ,
& V_168 . V_169 ) ;
F_5 ( V_1 ) ;
F_97 ( V_18 ) ;
V_1 -> V_19 = NULL ;
}
static int F_98 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_17 V_170 = * V_18 ;
int V_171 = 0 ;
int error ;
do {
F_99 ( V_1 ) ;
if ( V_171 ) {
F_100 ( 1 ) ;
}
error = F_4 ( V_1 , 0 ) ;
} while ( error && ++ V_171 < 3 );
if ( error )
return - 1 ;
if ( V_171 > 1 )
F_101 ( V_1 , L_16 , V_171 ) ;
if ( F_24 ( V_1 ) ) {
F_30 ( V_1 , L_17 ) ;
return - 1 ;
}
if ( F_29 ( V_1 ) ) {
F_30 ( V_1 , L_18 ) ;
return - 1 ;
}
if ( V_170 . V_34 != V_18 -> V_34 ||
V_170 . V_22 != V_18 -> V_22 ||
V_170 . V_31 != V_18 -> V_31 ||
V_170 . V_32 != V_18 -> V_32 ) {
F_30 ( V_1 ,
L_19 ,
V_170 . V_34 , V_18 -> V_34 ,
V_170 . V_22 , V_18 -> V_22 ,
V_170 . V_31 , V_18 -> V_31 ,
V_170 . V_32 , V_18 -> V_32 ) ;
return - 1 ;
}
return 0 ;
}
void T_4 F_102 ( void )
{
V_172 = F_103 ( V_173 ) ;
V_174 = F_103 ( V_175 ) ;
}
static int F_104 ( struct V_1 * V_1 , bool V_49 )
{
struct V_17 * V_18 ;
int V_165 = - 1 ;
if ( V_49 && V_174 ) {
F_45 ( V_1 ,
L_20 ) ;
return - V_10 ;
}
V_1 -> V_19 = V_18 = F_43 ( sizeof( struct V_17 ) , V_69 ) ;
if ( ! V_18 )
return - V_176 ;
F_99 ( V_1 ) ;
if ( F_24 ( V_1 ) ) {
F_30 ( V_1 , L_17 ) ;
goto V_177;
}
V_18 -> V_49 = V_49 ;
if ( F_95 ( V_18 -> V_34 ) )
V_18 -> V_51 = true ;
if ( F_29 ( V_1 ) ) {
F_30 ( V_1 , L_18 ) ;
goto V_177;
}
V_18 -> V_128 = F_50 ( V_18 -> V_22 ) ? V_134 : V_137 ;
F_45 ( V_1 ,
L_21 ,
F_105 ( V_18 -> V_34 ) ,
F_21 ( V_18 -> V_34 ) , F_106 ( V_18 -> V_34 ) ,
V_18 -> V_22 ,
V_18 -> V_31 , V_18 -> V_32 , V_18 -> V_33 ,
V_18 -> V_25 , V_18 -> V_28 ) ;
F_87 ( V_1 -> V_99 , V_18 ) ;
V_1 -> V_178 = ( ( V_18 -> V_22 & 0x00ff0000 ) >> 8 ) |
( V_18 -> V_22 & 0x000000ff ) ;
if ( V_49 ) {
V_1 -> V_179 = F_80 ;
V_1 -> V_67 = 6 ;
} else {
V_1 -> V_179 = V_180 ;
V_1 -> V_67 = 3 ;
}
V_1 -> V_181 = F_31 ;
V_1 -> V_182 = F_94 ;
V_1 -> V_183 = F_98 ;
V_1 -> V_184 = F_5 ;
V_1 -> V_185 = 0 ;
if ( F_82 ( V_18 -> V_31 ) )
F_42 ( V_1 ) ;
if ( V_1 -> V_53 >= 80 && V_172 ) {
F_45 ( V_1 ,
L_22 ,
F_107 ( V_186 ) ) ;
V_1 -> V_53 = 40 ;
}
if ( ! V_18 -> V_49 && F_95 ( V_18 -> V_34 ) ) {
V_165 = F_108 ( & V_1 -> V_5 . V_56 -> V_99 ,
& V_168 . V_169 ) ;
if ( V_165 ) {
F_30 ( V_1 ,
L_23 ,
V_165 ) ;
goto V_177;
}
}
return 0 ;
V_177:
F_97 ( V_18 ) ;
return V_165 ;
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
return - V_187 ;
}
bool F_111 ( void )
{
return false ;
}
