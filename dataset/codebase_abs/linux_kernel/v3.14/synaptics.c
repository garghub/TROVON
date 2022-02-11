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
if ( V_40 ) {
V_18 -> V_41 = V_40 [ 0 ] ;
V_18 -> V_42 = V_40 [ 1 ] ;
V_18 -> V_43 = V_40 [ 2 ] ;
V_18 -> V_44 = V_40 [ 3 ] ;
return 0 ;
}
if ( F_21 ( V_18 -> V_34 ) < 4 )
return 0 ;
if ( F_7 ( V_1 , V_45 , V_39 ) == 0 ) {
if ( V_39 [ 0 ] != 0 && ( V_39 [ 1 ] & 0x80 ) && V_39 [ 2 ] != 0 ) {
V_18 -> V_46 = V_39 [ 0 ] ;
V_18 -> V_47 = V_39 [ 2 ] ;
}
}
if ( F_15 ( V_18 -> V_31 ) >= 5 &&
F_22 ( V_18 -> V_33 ) ) {
if ( F_7 ( V_1 , V_48 , V_39 ) ) {
F_16 ( V_1 ,
L_5 ) ;
} else {
V_18 -> V_42 = ( V_39 [ 0 ] << 5 ) | ( ( V_39 [ 1 ] & 0x0f ) << 1 ) ;
V_18 -> V_44 = ( V_39 [ 2 ] << 5 ) | ( ( V_39 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
if ( F_15 ( V_18 -> V_31 ) >= 7 &&
F_23 ( V_18 -> V_33 ) ) {
if ( F_7 ( V_1 , V_49 , V_39 ) ) {
F_16 ( V_1 ,
L_6 ) ;
} else {
V_18 -> V_41 = ( V_39 [ 0 ] << 5 ) | ( ( V_39 [ 1 ] & 0x0f ) << 1 ) ;
V_18 -> V_43 = ( V_39 [ 2 ] << 5 ) | ( ( V_39 [ 1 ] & 0xf0 ) >> 3 ) ;
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
if ( V_18 -> V_50 )
V_18 -> V_2 |= V_51 ;
if ( V_18 -> V_52 )
V_18 -> V_2 |= V_53 ;
if ( V_1 -> V_54 >= 80 )
V_18 -> V_2 |= V_55 ;
if ( F_14 ( V_18 -> V_31 ) )
V_18 -> V_2 |= V_56 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
return - 1 ;
if ( V_18 -> V_50 &&
F_25 ( V_1 ) ) {
F_30 ( V_1 , L_7 ) ;
return - 1 ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_1 , unsigned int V_54 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( V_54 >= 80 ) {
V_18 -> V_2 |= V_55 ;
V_1 -> V_54 = 80 ;
} else {
V_18 -> V_2 &= ~ V_55 ;
V_1 -> V_54 = 40 ;
}
F_1 ( V_1 , V_18 -> V_2 ) ;
}
static int F_32 ( struct V_57 * V_57 , unsigned char V_16 )
{
struct V_1 * V_58 = F_33 ( V_57 -> V_58 ) ;
char V_59 = V_60 ;
if ( F_2 ( V_58 , V_16 ) )
return - 1 ;
if ( F_3 ( & V_58 -> V_5 , & V_59 , V_6 ) )
return - 1 ;
return 0 ;
}
static int F_34 ( struct V_57 * V_57 )
{
struct V_1 * V_58 = F_33 ( V_57 -> V_58 ) ;
struct V_17 * V_18 = V_58 -> V_19 ;
F_35 ( V_58 -> V_5 . V_57 ) ;
V_18 -> V_61 = V_57 ;
F_36 ( V_58 -> V_5 . V_57 ) ;
return 0 ;
}
static void F_37 ( struct V_57 * V_57 )
{
struct V_1 * V_58 = F_33 ( V_57 -> V_58 ) ;
struct V_17 * V_18 = V_58 -> V_19 ;
F_35 ( V_58 -> V_5 . V_57 ) ;
V_18 -> V_61 = NULL ;
F_36 ( V_58 -> V_5 . V_57 ) ;
}
static int F_38 ( unsigned char * V_62 )
{
return ( V_62 [ 0 ] & 0xFC ) == 0x84 && ( V_62 [ 3 ] & 0xCC ) == 0xC4 ;
}
static void F_39 ( struct V_57 * V_63 , unsigned char * V_64 )
{
struct V_1 * V_65 = F_33 ( V_63 ) ;
if ( V_65 && V_65 -> V_66 == V_67 ) {
F_40 ( V_63 , V_64 [ 1 ] , 0 ) ;
F_40 ( V_63 , V_64 [ 4 ] , 0 ) ;
F_40 ( V_63 , V_64 [ 5 ] , 0 ) ;
if ( V_65 -> V_68 == 4 )
F_40 ( V_63 , V_64 [ 2 ] , 0 ) ;
} else
F_40 ( V_63 , V_64 [ 1 ] , 0 ) ;
}
static void F_41 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_1 * V_65 = F_33 ( V_18 -> V_61 ) ;
if ( V_65 ) {
if ( V_65 -> V_68 == 4 )
V_18 -> V_2 |= V_69 ;
else
V_18 -> V_2 &= ~ V_69 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
F_16 ( V_1 ,
L_8 ) ;
}
}
static void F_42 ( struct V_1 * V_1 )
{
struct V_57 * V_57 ;
V_57 = F_43 ( sizeof( struct V_57 ) , V_70 ) ;
if ( ! V_57 ) {
F_30 ( V_1 ,
L_9 ) ;
return;
}
V_57 -> V_37 . type = V_71 ;
F_44 ( V_57 -> V_12 , L_10 , sizeof( V_57 -> V_12 ) ) ;
F_44 ( V_57 -> V_72 , L_11 , sizeof( V_57 -> V_12 ) ) ;
V_57 -> V_73 = F_32 ;
V_57 -> V_74 = F_34 ;
V_57 -> V_75 = F_37 ;
V_57 -> V_58 = V_1 -> V_5 . V_57 ;
V_1 -> V_76 = F_41 ;
F_45 ( V_1 , L_12 ,
V_57 -> V_12 , V_1 -> V_72 ) ;
F_46 ( V_57 ) ;
}
static void F_47 ( struct V_77 * V_66 , int V_78 ,
int V_79 , int V_80 )
{
V_66 -> V_78 = V_78 ;
V_66 -> V_79 = V_79 ;
V_66 -> V_80 = V_80 ;
}
static void F_48 ( const unsigned char V_62 [] ,
struct V_17 * V_18 ,
struct V_81 * V_82 )
{
struct V_81 * V_80 = & V_18 -> V_80 ;
int V_83 ;
V_83 = ( V_62 [ 5 ] & 0x30 ) >> 4 ;
switch ( V_83 ) {
case 1 :
V_80 -> V_84 = V_82 -> V_84 ;
V_80 -> V_85 = ( ( ( V_62 [ 4 ] & 0x0f ) << 8 ) | V_62 [ 1 ] ) << 1 ;
V_80 -> V_13 = ( ( ( V_62 [ 4 ] & 0xf0 ) << 4 ) | V_62 [ 2 ] ) << 1 ;
V_80 -> V_86 = ( ( V_62 [ 3 ] & 0x30 ) | ( V_62 [ 5 ] & 0x0f ) ) << 1 ;
break;
case 2 :
F_47 ( & V_80 -> V_87 , V_62 [ 1 ] , V_62 [ 2 ] , V_62 [ 4 ] ) ;
break;
default:
break;
}
V_18 -> V_88 = true ;
}
static int F_49 ( const unsigned char V_62 [] ,
struct V_17 * V_18 ,
struct V_81 * V_82 )
{
memset ( V_82 , 0 , sizeof( struct V_81 ) ) ;
if ( F_50 ( V_18 -> V_22 ) ) {
V_82 -> V_84 = ( ( ( V_62 [ 0 ] & 0x30 ) >> 2 ) |
( ( V_62 [ 0 ] & 0x04 ) >> 1 ) |
( ( V_62 [ 3 ] & 0x04 ) >> 2 ) ) ;
V_82 -> V_89 = ( V_62 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_82 -> V_90 = ( V_62 [ 0 ] & 0x02 ) ? 1 : 0 ;
if ( F_51 ( V_18 -> V_33 ) ) {
V_82 -> V_89 = ( ( V_62 [ 0 ] ^ V_62 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
} else if ( F_52 ( V_18 -> V_31 ) ) {
V_82 -> V_91 = ( ( V_62 [ 0 ] ^ V_62 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
if ( V_82 -> V_84 == 2 )
V_82 -> V_92 = ( signed char ) ( V_62 [ 1 ] ) ;
}
if ( F_53 ( V_18 -> V_31 ) ) {
V_82 -> V_93 = ( ( V_62 [ 0 ] ^ V_62 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
V_82 -> V_94 = ( ( V_62 [ 0 ] ^ V_62 [ 3 ] ) & 0x02 ) ? 1 : 0 ;
}
if ( ( F_26 ( V_18 -> V_33 ) ||
F_27 ( V_18 -> V_33 ) ) &&
V_82 -> V_84 == 2 ) {
F_48 ( V_62 , V_18 , V_82 ) ;
return 1 ;
}
V_82 -> V_85 = ( ( ( V_62 [ 3 ] & 0x10 ) << 8 ) |
( ( V_62 [ 1 ] & 0x0f ) << 8 ) |
V_62 [ 4 ] ) ;
V_82 -> V_13 = ( ( ( V_62 [ 3 ] & 0x20 ) << 7 ) |
( ( V_62 [ 1 ] & 0xf0 ) << 4 ) |
V_62 [ 5 ] ) ;
V_82 -> V_86 = V_62 [ 2 ] ;
if ( F_17 ( V_18 -> V_32 ) &&
( ( V_62 [ 0 ] ^ V_62 [ 3 ] ) & 0x02 ) ) {
switch ( F_17 ( V_18 -> V_32 ) & ~ 0x01 ) {
default:
break;
case 8 :
V_82 -> V_95 |= ( ( V_62 [ 5 ] & 0x08 ) ) ? 0x80 : 0 ;
V_82 -> V_95 |= ( ( V_62 [ 4 ] & 0x08 ) ) ? 0x40 : 0 ;
case 6 :
V_82 -> V_95 |= ( ( V_62 [ 5 ] & 0x04 ) ) ? 0x20 : 0 ;
V_82 -> V_95 |= ( ( V_62 [ 4 ] & 0x04 ) ) ? 0x10 : 0 ;
case 4 :
V_82 -> V_95 |= ( ( V_62 [ 5 ] & 0x02 ) ) ? 0x08 : 0 ;
V_82 -> V_95 |= ( ( V_62 [ 4 ] & 0x02 ) ) ? 0x04 : 0 ;
case 2 :
V_82 -> V_95 |= ( ( V_62 [ 5 ] & 0x01 ) ) ? 0x02 : 0 ;
V_82 -> V_95 |= ( ( V_62 [ 4 ] & 0x01 ) ) ? 0x01 : 0 ;
}
}
} else {
V_82 -> V_85 = ( ( ( V_62 [ 1 ] & 0x1f ) << 8 ) | V_62 [ 2 ] ) ;
V_82 -> V_13 = ( ( ( V_62 [ 4 ] & 0x1f ) << 8 ) | V_62 [ 5 ] ) ;
V_82 -> V_86 = ( ( ( V_62 [ 0 ] & 0x30 ) << 2 ) | ( V_62 [ 3 ] & 0x3F ) ) ;
V_82 -> V_84 = ( ( ( V_62 [ 1 ] & 0x80 ) >> 4 ) | ( ( V_62 [ 0 ] & 0x04 ) >> 1 ) ) ;
V_82 -> V_89 = ( V_62 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_82 -> V_90 = ( V_62 [ 0 ] & 0x02 ) ? 1 : 0 ;
}
if ( V_82 -> V_85 > V_96 )
V_82 -> V_85 -= 1 << V_97 ;
else if ( V_82 -> V_85 == V_96 )
V_82 -> V_85 = V_98 ;
if ( V_82 -> V_13 > V_99 )
V_82 -> V_13 -= 1 << V_97 ;
else if ( V_82 -> V_13 == V_99 )
V_82 -> V_13 = V_100 ;
return 0 ;
}
static void F_54 ( struct V_101 * V_102 , int V_103 ,
bool V_104 , int V_85 , int V_13 )
{
F_55 ( V_102 , V_103 ) ;
F_56 ( V_102 , V_105 , V_104 ) ;
if ( V_104 ) {
F_57 ( V_102 , V_106 , V_85 ) ;
F_57 ( V_102 , V_107 , F_6 ( V_13 ) ) ;
}
}
static void F_58 ( struct V_101 * V_102 ,
const struct V_81 * V_108 ,
const struct V_81 * V_109 ,
int V_110 )
{
if ( V_110 >= 2 ) {
F_54 ( V_102 , 0 , true , F_59 ( V_108 -> V_85 , V_109 -> V_85 ) ,
F_59 ( V_108 -> V_13 , V_109 -> V_13 ) ) ;
F_54 ( V_102 , 1 , true , F_60 ( V_108 -> V_85 , V_109 -> V_85 ) ,
F_60 ( V_108 -> V_13 , V_109 -> V_13 ) ) ;
} else if ( V_110 == 1 ) {
F_54 ( V_102 , 0 , true , V_108 -> V_85 , V_108 -> V_13 ) ;
F_54 ( V_102 , 1 , false , 0 , 0 ) ;
} else {
F_54 ( V_102 , 0 , false , 0 , 0 ) ;
F_54 ( V_102 , 1 , false , 0 , 0 ) ;
}
}
static void F_61 ( struct V_1 * V_1 ,
const struct V_81 * V_82 )
{
struct V_101 * V_102 = V_1 -> V_102 ;
struct V_17 * V_18 = V_1 -> V_19 ;
int V_111 ;
F_62 ( V_102 , V_112 , V_82 -> V_89 ) ;
F_62 ( V_102 , V_113 , V_82 -> V_90 ) ;
if ( F_52 ( V_18 -> V_31 ) )
F_62 ( V_102 , V_114 , V_82 -> V_91 ) ;
if ( F_53 ( V_18 -> V_31 ) ) {
F_62 ( V_102 , V_115 , V_82 -> V_93 ) ;
F_62 ( V_102 , V_116 , V_82 -> V_94 ) ;
}
for ( V_111 = 0 ; V_111 < F_17 ( V_18 -> V_32 ) ; V_111 ++ )
F_62 ( V_102 , V_117 + V_111 , V_82 -> V_95 & ( 1 << V_111 ) ) ;
}
static void F_63 ( struct V_101 * V_102 , int V_103 ,
const struct V_81 * V_82 )
{
F_55 ( V_102 , V_103 ) ;
F_56 ( V_102 , V_105 , ( V_82 != NULL ) ) ;
if ( ! V_82 )
return;
F_57 ( V_102 , V_106 , V_82 -> V_85 ) ;
F_57 ( V_102 , V_107 , F_6 ( V_82 -> V_13 ) ) ;
F_57 ( V_102 , V_118 , V_82 -> V_86 ) ;
}
static void F_64 ( struct V_1 * V_1 ,
struct V_77 * V_87 ,
const struct V_81 * V_79 )
{
struct V_101 * V_102 = V_1 -> V_102 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_81 * V_80 = & V_18 -> V_80 ;
struct V_77 * V_119 = & V_18 -> V_87 ;
switch ( V_87 -> V_78 ) {
case 0 :
F_63 ( V_102 , 0 , NULL ) ;
F_63 ( V_102 , 1 , NULL ) ;
break;
case 1 :
if ( V_87 -> V_79 == - 1 ) {
F_63 ( V_102 , 0 , NULL ) ;
F_63 ( V_102 , 1 , NULL ) ;
} else if ( V_87 -> V_79 == 0 ) {
F_63 ( V_102 , 0 , V_79 ) ;
F_63 ( V_102 , 1 , NULL ) ;
} else {
F_63 ( V_102 , 0 , NULL ) ;
F_63 ( V_102 , 1 , V_79 ) ;
}
break;
default:
if ( V_87 -> V_79 != - 1 &&
( V_87 -> V_79 == V_119 -> V_79 ||
V_119 -> V_79 == - 1 || V_87 -> V_80 == V_119 -> V_79 ) )
F_63 ( V_102 , 0 , V_79 ) ;
else
F_63 ( V_102 , 0 , NULL ) ;
if ( V_87 -> V_80 != - 1 &&
( V_87 -> V_80 == V_119 -> V_80 ||
( V_119 -> V_80 == - 1 &&
( V_119 -> V_79 == - 1 || V_87 -> V_80 == V_119 -> V_79 ) ) ) )
F_63 ( V_102 , 1 , V_80 ) ;
else
F_63 ( V_102 , 1 , NULL ) ;
break;
}
F_65 ( V_102 , false ) ;
F_66 ( V_102 , V_87 -> V_78 ) ;
F_61 ( V_1 , V_79 ) ;
F_67 ( V_102 ) ;
}
static void F_68 ( struct V_17 * V_18 ,
struct V_77 * V_87 )
{
F_47 ( V_87 , 0 , - 1 , - 1 ) ;
V_18 -> V_120 = false ;
}
static void F_69 ( struct V_17 * V_18 ,
struct V_77 * V_87 )
{
struct V_81 * V_80 = & V_18 -> V_80 ;
struct V_77 * V_119 = & V_18 -> V_87 ;
if ( V_18 -> V_88 && V_80 -> V_86 == 0 ) {
F_47 ( V_87 , 1 , 0 , - 1 ) ;
V_18 -> V_120 = false ;
return;
}
switch ( V_119 -> V_78 ) {
case 0 :
F_47 ( V_87 , 1 , 0 , - 1 ) ;
break;
case 1 :
if ( V_18 -> V_120 ||
( V_18 -> V_88 && V_119 -> V_79 <= 0 ) )
F_47 ( V_87 , 1 , 1 , - 1 ) ;
else if ( V_119 -> V_79 == - 1 )
F_47 ( V_87 , 1 , 0 , - 1 ) ;
break;
case 2 :
if ( V_18 -> V_120 ) {
F_47 ( V_87 , 1 , - 1 , - 1 ) ;
break;
}
F_47 ( V_87 , 1 , V_119 -> V_80 , - 1 ) ;
break;
case 3 :
F_47 ( V_87 , 1 , - 1 , - 1 ) ;
V_18 -> V_120 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_70 ( struct V_17 * V_18 ,
struct V_77 * V_87 )
{
struct V_77 * V_119 = & V_18 -> V_87 ;
switch ( V_119 -> V_78 ) {
case 0 :
F_47 ( V_87 , 2 , 0 , 1 ) ;
break;
case 1 :
if ( V_119 -> V_79 >= 1 )
F_47 ( V_87 , 2 , 0 , V_119 -> V_79 ) ;
else
F_47 ( V_87 , 2 , 0 , 1 ) ;
break;
case 2 :
if ( V_18 -> V_120 )
F_47 ( V_87 , 2 , 0 , 1 ) ;
break;
case 3 :
F_47 ( V_87 , 2 , - 1 , - 1 ) ;
V_18 -> V_120 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_71 ( struct V_17 * V_18 ,
struct V_77 * V_87 )
{
struct V_77 * V_119 = & V_18 -> V_87 ;
switch ( V_119 -> V_78 ) {
case 0 :
F_47 ( V_87 , 3 , 0 , 2 ) ;
break;
case 1 :
if ( V_119 -> V_79 >= 2 )
F_47 ( V_87 , 3 , 0 , V_119 -> V_79 ) ;
else
F_47 ( V_87 , 3 , 0 , 2 ) ;
break;
case 2 :
if ( V_119 -> V_80 >= 3 ) {
F_47 ( V_87 , 3 , 0 , V_119 -> V_80 ) ;
break;
}
if ( V_18 -> V_120 ) {
F_47 ( V_87 , 3 , - 1 , - 1 ) ;
break;
}
F_47 ( V_87 , 3 , 0 , - 1 ) ;
break;
case 3 :
if ( V_119 -> V_80 <= 2 )
F_47 ( V_87 , 3 , 0 , 2 ) ;
break;
case 4 :
case 5 :
break;
}
}
static void F_72 ( struct V_17 * V_18 ,
struct V_77 * V_87 )
{
V_18 -> V_120 = false ;
}
static void F_73 ( struct V_1 * V_1 ,
struct V_81 * V_79 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_81 * V_80 = & V_18 -> V_80 ;
struct V_77 V_87 ;
V_87 = V_80 -> V_87 ;
if ( V_79 -> V_86 == 0 )
F_68 ( V_18 , & V_87 ) ;
else if ( V_79 -> V_84 >= 4 )
F_69 ( V_18 , & V_87 ) ;
else if ( V_79 -> V_84 == 0 )
F_70 ( V_18 , & V_87 ) ;
else if ( V_79 -> V_84 == 1 && V_87 . V_78 <= 3 )
F_71 ( V_18 , & V_87 ) ;
else
F_72 ( V_18 , & V_87 ) ;
F_64 ( V_1 , & V_87 , V_79 ) ;
V_18 -> V_87 = V_80 -> V_87 = V_87 ;
V_18 -> V_88 = false ;
}
static void F_74 ( struct V_1 * V_1 )
{
struct V_101 * V_102 = V_1 -> V_102 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_81 V_82 ;
int V_110 ;
int V_121 ;
if ( F_49 ( V_1 -> V_64 , V_18 , & V_82 ) )
return;
if ( F_27 ( V_18 -> V_33 ) ) {
F_73 ( V_1 , & V_82 ) ;
return;
}
if ( V_82 . V_92 ) {
V_18 -> V_92 += V_82 . V_92 ;
while ( V_18 -> V_92 >= 4 ) {
F_62 ( V_102 , V_116 , ! V_82 . V_94 ) ;
F_67 ( V_102 ) ;
F_62 ( V_102 , V_116 , V_82 . V_94 ) ;
F_67 ( V_102 ) ;
V_18 -> V_92 -= 4 ;
}
while ( V_18 -> V_92 <= - 4 ) {
F_62 ( V_102 , V_115 , ! V_82 . V_93 ) ;
F_67 ( V_102 ) ;
F_62 ( V_102 , V_115 , V_82 . V_93 ) ;
F_67 ( V_102 ) ;
V_18 -> V_92 += 4 ;
}
return;
}
if ( V_82 . V_86 > 0 && V_82 . V_85 > 1 ) {
V_110 = 1 ;
V_121 = 5 ;
if ( F_14 ( V_18 -> V_31 ) ) {
switch ( V_82 . V_84 ) {
case 0 ... 1 :
if ( F_75 ( V_18 -> V_31 ) )
V_110 = V_82 . V_84 + 2 ;
break;
case 2 :
if ( F_76 ( V_18 -> V_22 ) )
;
break;
case 4 ... 15 :
if ( F_77 ( V_18 -> V_31 ) )
V_121 = V_82 . V_84 ;
break;
}
}
} else {
V_110 = 0 ;
V_121 = 0 ;
}
if ( F_26 ( V_18 -> V_33 ) )
F_58 ( V_102 , & V_82 , & V_18 -> V_80 ,
V_110 ) ;
if ( V_82 . V_86 > 30 ) F_62 ( V_102 , V_122 , 1 ) ;
if ( V_82 . V_86 < 25 ) F_62 ( V_102 , V_122 , 0 ) ;
if ( V_110 > 0 ) {
F_57 ( V_102 , V_123 , V_82 . V_85 ) ;
F_57 ( V_102 , V_124 , F_6 ( V_82 . V_13 ) ) ;
}
F_57 ( V_102 , V_125 , V_82 . V_86 ) ;
if ( F_77 ( V_18 -> V_31 ) )
F_57 ( V_102 , V_126 , V_121 ) ;
F_62 ( V_102 , V_127 , V_110 == 1 ) ;
if ( F_75 ( V_18 -> V_31 ) ) {
F_62 ( V_102 , V_128 , V_110 == 2 ) ;
F_62 ( V_102 , V_129 , V_110 == 3 ) ;
}
F_61 ( V_1 , & V_82 ) ;
F_67 ( V_102 ) ;
}
static int F_78 ( struct V_1 * V_1 ,
int V_130 , unsigned char V_131 )
{
static const unsigned char V_132 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const unsigned char V_133 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_134 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_135 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const unsigned char V_136 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
const char * V_64 = V_1 -> V_64 ;
if ( V_130 < 0 || V_130 > 4 )
return 0 ;
switch ( V_131 ) {
case V_137 :
case V_138 :
return ( V_64 [ V_130 ] & V_133 [ V_130 ] ) == V_134 [ V_130 ] ;
case V_139 :
return ( V_64 [ V_130 ] & V_132 [ V_130 ] ) == V_134 [ V_130 ] ;
case V_140 :
return ( V_64 [ V_130 ] & V_135 [ V_130 ] ) == V_136 [ V_130 ] ;
default:
F_30 ( V_1 , L_13 , V_131 ) ;
return 0 ;
}
}
static unsigned char F_79 ( struct V_1 * V_1 )
{
int V_111 ;
for ( V_111 = 0 ; V_111 < 5 ; V_111 ++ )
if ( ! F_78 ( V_1 , V_111 , V_139 ) ) {
F_45 ( V_1 , L_14 ) ;
return V_138 ;
}
return V_139 ;
}
static T_1 F_80 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( V_1 -> V_141 >= 6 ) {
if ( F_81 ( V_18 -> V_131 == V_137 ) )
V_18 -> V_131 = F_79 ( V_1 ) ;
if ( F_82 ( V_18 -> V_31 ) &&
F_38 ( V_1 -> V_64 ) ) {
if ( V_18 -> V_61 )
F_39 ( V_18 -> V_61 , V_1 -> V_64 ) ;
} else
F_74 ( V_1 ) ;
return V_142 ;
}
return F_78 ( V_1 , V_1 -> V_141 - 1 , V_18 -> V_131 ) ?
V_143 : V_144 ;
}
static void F_83 ( struct V_101 * V_102 ,
struct V_17 * V_18 , int V_145 ,
int V_146 )
{
int V_41 = V_18 -> V_41 ? : V_147 ;
int V_42 = V_18 -> V_42 ? : V_148 ;
int V_43 = V_18 -> V_43 ? : V_15 ;
int V_44 = V_18 -> V_44 ? : V_14 ;
int V_149 = F_84 ( V_18 -> V_33 ) ?
V_150 : 0 ;
F_85 ( V_102 , V_145 , V_41 , V_42 , V_149 , 0 ) ;
F_85 ( V_102 , V_146 , V_43 , V_44 , V_149 , 0 ) ;
F_86 ( V_102 , V_145 , V_18 -> V_46 ) ;
F_86 ( V_102 , V_146 , V_18 -> V_47 ) ;
}
static void F_87 ( struct V_101 * V_102 , struct V_17 * V_18 )
{
int V_111 ;
F_88 ( V_151 , V_102 -> V_152 ) ;
F_88 ( V_153 , V_102 -> V_154 ) ;
F_88 ( V_112 , V_102 -> V_155 ) ;
F_88 ( V_113 , V_102 -> V_155 ) ;
if ( F_52 ( V_18 -> V_31 ) )
F_88 ( V_114 , V_102 -> V_155 ) ;
if ( ! V_18 -> V_50 ) {
F_88 ( V_156 , V_102 -> V_154 ) ;
F_88 ( V_157 , V_102 -> V_158 ) ;
F_88 ( V_159 , V_102 -> V_158 ) ;
return;
}
F_88 ( V_160 , V_102 -> V_154 ) ;
F_83 ( V_102 , V_18 , V_123 , V_124 ) ;
F_85 ( V_102 , V_125 , 0 , 255 , 0 , 0 ) ;
if ( F_27 ( V_18 -> V_33 ) ) {
F_83 ( V_102 , V_18 , V_106 ,
V_107 ) ;
F_85 ( V_102 , V_118 , 0 , 255 , 0 , 0 ) ;
F_89 ( V_102 , 2 , V_161 ) ;
F_88 ( V_162 , V_102 -> V_155 ) ;
F_88 ( V_163 , V_102 -> V_155 ) ;
} else if ( F_26 ( V_18 -> V_33 ) ) {
F_88 ( V_164 , V_102 -> V_152 ) ;
F_89 ( V_102 , 2 , 0 ) ;
F_83 ( V_102 , V_18 , V_106 ,
V_107 ) ;
}
if ( F_77 ( V_18 -> V_31 ) )
F_85 ( V_102 , V_126 , 0 , 15 , 0 , 0 ) ;
F_88 ( V_122 , V_102 -> V_155 ) ;
F_88 ( V_127 , V_102 -> V_155 ) ;
if ( F_75 ( V_18 -> V_31 ) ) {
F_88 ( V_128 , V_102 -> V_155 ) ;
F_88 ( V_129 , V_102 -> V_155 ) ;
}
if ( F_53 ( V_18 -> V_31 ) ||
F_52 ( V_18 -> V_31 ) ) {
F_88 ( V_115 , V_102 -> V_155 ) ;
F_88 ( V_116 , V_102 -> V_155 ) ;
}
for ( V_111 = 0 ; V_111 < F_17 ( V_18 -> V_32 ) ; V_111 ++ )
F_88 ( V_117 + V_111 , V_102 -> V_155 ) ;
F_90 ( V_156 , V_102 -> V_154 ) ;
F_90 ( V_157 , V_102 -> V_158 ) ;
F_90 ( V_159 , V_102 -> V_158 ) ;
if ( F_51 ( V_18 -> V_33 ) ) {
F_88 ( V_165 , V_102 -> V_152 ) ;
F_90 ( V_113 , V_102 -> V_155 ) ;
F_90 ( V_114 , V_102 -> V_155 ) ;
}
}
static T_2 F_91 ( struct V_1 * V_1 ,
void * V_166 , char * V_62 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
return sprintf ( V_62 , L_15 , V_18 -> V_52 ? '1' : '0' ) ;
}
static T_2 F_92 ( struct V_1 * V_1 ,
void * V_166 , const char * V_62 ,
T_3 V_167 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned int V_168 ;
int V_169 ;
V_169 = F_93 ( V_62 , 10 , & V_168 ) ;
if ( V_169 )
return V_169 ;
if ( V_168 > 1 )
return - V_170 ;
if ( V_168 == V_18 -> V_52 )
return V_167 ;
V_18 -> V_52 = V_168 ;
if ( V_168 )
V_18 -> V_2 |= V_53 ;
else
V_18 -> V_2 &= ~ V_53 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
return - V_171 ;
return V_167 ;
}
static void F_94 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( ! V_18 -> V_50 && F_95 ( V_18 -> V_34 ) )
F_96 ( & V_1 -> V_5 . V_57 -> V_102 ,
& V_172 . V_173 ) ;
F_5 ( V_1 ) ;
F_97 ( V_18 ) ;
V_1 -> V_19 = NULL ;
}
static int F_98 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_17 V_174 = * V_18 ;
unsigned char V_3 [ 2 ] ;
int V_175 = 0 ;
int error ;
do {
F_99 ( V_1 ) ;
if ( V_175 ) {
F_100 ( 1 ) ;
}
F_3 ( & V_1 -> V_5 , V_3 , V_176 ) ;
error = F_4 ( V_1 , 0 ) ;
} while ( error && ++ V_175 < 3 );
if ( error )
return - 1 ;
if ( V_175 > 1 )
F_101 ( V_1 , L_16 , V_175 ) ;
if ( F_24 ( V_1 ) ) {
F_30 ( V_1 , L_17 ) ;
return - 1 ;
}
if ( F_29 ( V_1 ) ) {
F_30 ( V_1 , L_18 ) ;
return - 1 ;
}
if ( V_174 . V_34 != V_18 -> V_34 ||
V_174 . V_22 != V_18 -> V_22 ||
V_174 . V_31 != V_18 -> V_31 ||
V_174 . V_32 != V_18 -> V_32 ) {
F_30 ( V_1 ,
L_19 ,
V_174 . V_34 , V_18 -> V_34 ,
V_174 . V_22 , V_18 -> V_22 ,
V_174 . V_31 , V_18 -> V_31 ,
V_174 . V_32 , V_18 -> V_32 ) ;
return - 1 ;
}
return 0 ;
}
void T_4 F_102 ( void )
{
const struct V_177 * V_178 ;
V_179 = F_103 ( V_180 ) ;
V_181 = F_103 ( V_182 ) ;
V_178 = F_104 ( V_183 ) ;
if ( V_178 )
V_40 = V_178 -> V_184 ;
}
static int F_105 ( struct V_1 * V_1 , bool V_50 )
{
struct V_17 * V_18 ;
int V_169 = - 1 ;
if ( V_50 && V_181 ) {
F_45 ( V_1 ,
L_20 ) ;
return - V_10 ;
}
V_1 -> V_19 = V_18 = F_43 ( sizeof( struct V_17 ) , V_70 ) ;
if ( ! V_18 )
return - V_185 ;
F_99 ( V_1 ) ;
if ( F_24 ( V_1 ) ) {
F_30 ( V_1 , L_17 ) ;
goto V_186;
}
V_18 -> V_50 = V_50 ;
if ( F_95 ( V_18 -> V_34 ) )
V_18 -> V_52 = true ;
if ( F_29 ( V_1 ) ) {
F_30 ( V_1 , L_18 ) ;
goto V_186;
}
V_18 -> V_131 = F_50 ( V_18 -> V_22 ) ? V_137 : V_140 ;
F_45 ( V_1 ,
L_21 ,
F_106 ( V_18 -> V_34 ) ,
F_21 ( V_18 -> V_34 ) , F_107 ( V_18 -> V_34 ) ,
V_18 -> V_22 ,
V_18 -> V_31 , V_18 -> V_32 , V_18 -> V_33 ,
V_18 -> V_25 , V_18 -> V_28 ) ;
F_87 ( V_1 -> V_102 , V_18 ) ;
V_1 -> V_187 = ( ( V_18 -> V_22 & 0x00ff0000 ) >> 8 ) |
( V_18 -> V_22 & 0x000000ff ) ;
if ( V_50 ) {
V_1 -> V_188 = F_80 ;
V_1 -> V_68 = 6 ;
} else {
V_1 -> V_188 = V_189 ;
V_1 -> V_68 = 3 ;
}
V_1 -> V_190 = F_31 ;
V_1 -> V_191 = F_94 ;
V_1 -> V_192 = F_98 ;
V_1 -> V_193 = F_5 ;
V_1 -> V_194 = 0 ;
if ( F_82 ( V_18 -> V_31 ) )
F_42 ( V_1 ) ;
if ( V_1 -> V_54 >= 80 && V_179 ) {
F_45 ( V_1 ,
L_22 ,
F_108 ( V_195 ) ) ;
V_1 -> V_54 = 40 ;
}
if ( ! V_18 -> V_50 && F_95 ( V_18 -> V_34 ) ) {
V_169 = F_109 ( & V_1 -> V_5 . V_57 -> V_102 ,
& V_172 . V_173 ) ;
if ( V_169 ) {
F_30 ( V_1 ,
L_23 ,
V_169 ) ;
goto V_186;
}
}
return 0 ;
V_186:
F_97 ( V_18 ) ;
return V_169 ;
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
void T_4 F_102 ( void )
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
