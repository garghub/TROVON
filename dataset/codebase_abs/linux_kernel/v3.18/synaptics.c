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
int V_40 ;
if ( F_21 ( V_18 -> V_34 ) < 4 )
return 0 ;
if ( F_7 ( V_1 , V_41 , V_39 ) == 0 ) {
if ( V_39 [ 0 ] != 0 && ( V_39 [ 1 ] & 0x80 ) && V_39 [ 2 ] != 0 ) {
V_18 -> V_42 = V_39 [ 0 ] ;
V_18 -> V_43 = V_39 [ 2 ] ;
}
}
for ( V_40 = 0 ; V_44 [ V_40 ] . V_45 ; V_40 ++ ) {
if ( F_22 ( V_1 ,
V_44 [ V_40 ] . V_45 ) ) {
V_18 -> V_46 = V_44 [ V_40 ] . V_46 ;
V_18 -> V_47 = V_44 [ V_40 ] . V_47 ;
V_18 -> V_48 = V_44 [ V_40 ] . V_48 ;
V_18 -> V_49 = V_44 [ V_40 ] . V_49 ;
return 0 ;
}
}
if ( F_15 ( V_18 -> V_31 ) >= 5 &&
F_23 ( V_18 -> V_33 ) ) {
if ( F_7 ( V_1 , V_50 , V_39 ) ) {
F_16 ( V_1 ,
L_5 ) ;
} else {
V_18 -> V_47 = ( V_39 [ 0 ] << 5 ) | ( ( V_39 [ 1 ] & 0x0f ) << 1 ) ;
V_18 -> V_49 = ( V_39 [ 2 ] << 5 ) | ( ( V_39 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
if ( F_15 ( V_18 -> V_31 ) >= 7 &&
F_24 ( V_18 -> V_33 ) ) {
if ( F_7 ( V_1 , V_51 , V_39 ) ) {
F_16 ( V_1 ,
L_6 ) ;
} else {
V_18 -> V_46 = ( V_39 [ 0 ] << 5 ) | ( ( V_39 [ 1 ] & 0x0f ) << 1 ) ;
V_18 -> V_48 = ( V_39 [ 2 ] << 5 ) | ( ( V_39 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
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
static int F_26 ( struct V_1 * V_1 )
{
static unsigned char V_3 = 0xc8 ;
struct V_17 * V_18 = V_1 -> V_19 ;
if ( ! ( F_27 ( V_18 -> V_33 ) ||
F_28 ( V_18 -> V_33 ) ) )
return 0 ;
if ( F_2 ( V_1 , V_21 ) )
return - 1 ;
if ( F_3 ( & V_1 -> V_5 , & V_3 , V_6 ) )
return - 1 ;
V_18 -> V_31 |= F_29 ( 1 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
V_18 -> V_2 = 0 ;
if ( V_18 -> V_52 )
V_18 -> V_2 |= V_53 ;
if ( V_18 -> V_54 )
V_18 -> V_2 |= V_55 ;
if ( V_1 -> V_56 >= 80 )
V_18 -> V_2 |= V_57 ;
if ( F_14 ( V_18 -> V_31 ) )
V_18 -> V_2 |= V_58 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
return - 1 ;
if ( V_18 -> V_52 &&
F_26 ( V_1 ) ) {
F_31 ( V_1 , L_7 ) ;
return - 1 ;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_1 , unsigned int V_56 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( V_56 >= 80 ) {
V_18 -> V_2 |= V_57 ;
V_1 -> V_56 = 80 ;
} else {
V_18 -> V_2 &= ~ V_57 ;
V_1 -> V_56 = 40 ;
}
F_1 ( V_1 , V_18 -> V_2 ) ;
}
static int F_33 ( struct V_59 * V_59 , unsigned char V_16 )
{
struct V_1 * V_60 = F_34 ( V_59 -> V_60 ) ;
char V_61 = V_62 ;
if ( F_2 ( V_60 , V_16 ) )
return - 1 ;
if ( F_3 ( & V_60 -> V_5 , & V_61 , V_6 ) )
return - 1 ;
return 0 ;
}
static int F_35 ( struct V_59 * V_59 )
{
struct V_1 * V_60 = F_34 ( V_59 -> V_60 ) ;
struct V_17 * V_18 = V_60 -> V_19 ;
F_36 ( V_60 -> V_5 . V_59 ) ;
V_18 -> V_63 = V_59 ;
F_37 ( V_60 -> V_5 . V_59 ) ;
return 0 ;
}
static void F_38 ( struct V_59 * V_59 )
{
struct V_1 * V_60 = F_34 ( V_59 -> V_60 ) ;
struct V_17 * V_18 = V_60 -> V_19 ;
F_36 ( V_60 -> V_5 . V_59 ) ;
V_18 -> V_63 = NULL ;
F_37 ( V_60 -> V_5 . V_59 ) ;
}
static int F_39 ( unsigned char * V_64 )
{
return ( V_64 [ 0 ] & 0xFC ) == 0x84 && ( V_64 [ 3 ] & 0xCC ) == 0xC4 ;
}
static void F_40 ( struct V_59 * V_65 , unsigned char * V_66 )
{
struct V_1 * V_67 = F_34 ( V_65 ) ;
if ( V_67 && V_67 -> V_68 == V_69 ) {
F_41 ( V_65 , V_66 [ 1 ] , 0 ) ;
F_41 ( V_65 , V_66 [ 4 ] , 0 ) ;
F_41 ( V_65 , V_66 [ 5 ] , 0 ) ;
if ( V_67 -> V_70 == 4 )
F_41 ( V_65 , V_66 [ 2 ] , 0 ) ;
} else
F_41 ( V_65 , V_66 [ 1 ] , 0 ) ;
}
static void F_42 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_1 * V_67 = F_34 ( V_18 -> V_63 ) ;
if ( V_67 ) {
if ( V_67 -> V_70 == 4 )
V_18 -> V_2 |= V_71 ;
else
V_18 -> V_2 &= ~ V_71 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
F_16 ( V_1 ,
L_8 ) ;
}
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_59 * V_59 ;
V_59 = F_44 ( sizeof( struct V_59 ) , V_72 ) ;
if ( ! V_59 ) {
F_31 ( V_1 ,
L_9 ) ;
return;
}
V_59 -> V_37 . type = V_73 ;
F_45 ( V_59 -> V_12 , L_10 , sizeof( V_59 -> V_12 ) ) ;
F_45 ( V_59 -> V_74 , L_11 , sizeof( V_59 -> V_12 ) ) ;
V_59 -> V_75 = F_33 ;
V_59 -> V_76 = F_35 ;
V_59 -> V_77 = F_38 ;
V_59 -> V_60 = V_1 -> V_5 . V_59 ;
V_1 -> V_78 = F_42 ;
F_46 ( V_1 , L_12 ,
V_59 -> V_12 , V_1 -> V_74 ) ;
F_47 ( V_59 ) ;
}
static void F_48 ( struct V_79 * V_68 , int V_80 ,
int V_81 , int V_82 )
{
V_68 -> V_80 = V_80 ;
V_68 -> V_81 = V_81 ;
V_68 -> V_82 = V_82 ;
}
static void F_49 ( const unsigned char V_64 [] ,
struct V_17 * V_18 ,
struct V_83 * V_84 )
{
struct V_83 * V_82 = & V_18 -> V_82 ;
int V_85 ;
V_85 = ( V_64 [ 5 ] & 0x30 ) >> 4 ;
switch ( V_85 ) {
case 1 :
V_82 -> V_86 = V_84 -> V_86 ;
V_82 -> V_87 = ( ( ( V_64 [ 4 ] & 0x0f ) << 8 ) | V_64 [ 1 ] ) << 1 ;
V_82 -> V_13 = ( ( ( V_64 [ 4 ] & 0xf0 ) << 4 ) | V_64 [ 2 ] ) << 1 ;
V_82 -> V_88 = ( ( V_64 [ 3 ] & 0x30 ) | ( V_64 [ 5 ] & 0x0f ) ) << 1 ;
break;
case 2 :
F_48 ( & V_82 -> V_89 , V_64 [ 1 ] , V_64 [ 2 ] , V_64 [ 4 ] ) ;
break;
default:
break;
}
V_18 -> V_90 = true ;
}
static int F_50 ( const unsigned char V_64 [] ,
struct V_17 * V_18 ,
struct V_83 * V_84 )
{
memset ( V_84 , 0 , sizeof( struct V_83 ) ) ;
if ( F_51 ( V_18 -> V_22 ) ) {
V_84 -> V_86 = ( ( ( V_64 [ 0 ] & 0x30 ) >> 2 ) |
( ( V_64 [ 0 ] & 0x04 ) >> 1 ) |
( ( V_64 [ 3 ] & 0x04 ) >> 2 ) ) ;
if ( ( F_27 ( V_18 -> V_33 ) ||
F_28 ( V_18 -> V_33 ) ) &&
V_84 -> V_86 == 2 ) {
F_49 ( V_64 , V_18 , V_84 ) ;
return 1 ;
}
V_84 -> V_87 = ( ( ( V_64 [ 3 ] & 0x10 ) << 8 ) |
( ( V_64 [ 1 ] & 0x0f ) << 8 ) |
V_64 [ 4 ] ) ;
V_84 -> V_13 = ( ( ( V_64 [ 3 ] & 0x20 ) << 7 ) |
( ( V_64 [ 1 ] & 0xf0 ) << 4 ) |
V_64 [ 5 ] ) ;
V_84 -> V_88 = V_64 [ 2 ] ;
V_84 -> V_91 = ( V_64 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_84 -> V_92 = ( V_64 [ 0 ] & 0x02 ) ? 1 : 0 ;
if ( V_93 ) {
if ( V_84 -> V_88 == 0 ) {
V_18 -> V_94 = V_18 -> V_95 = false ;
} else if ( V_84 -> V_86 >= 4 && ( ( V_64 [ 0 ] ^ V_64 [ 3 ] ) & 0x01 ) ) {
if ( ! V_18 -> V_94 ) {
V_18 -> V_96 = V_97 ;
V_18 -> V_94 = true ;
} else if ( F_52 ( V_97 ,
V_18 -> V_96 +
F_53 ( 50 ) ) ) {
V_18 -> V_95 = true ;
}
} else {
V_18 -> V_94 = false ;
}
V_84 -> V_91 = V_18 -> V_95 ;
} else if ( F_54 ( V_18 -> V_33 ) ) {
V_84 -> V_91 = ( ( V_64 [ 0 ] ^ V_64 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
} else if ( F_55 ( V_18 -> V_31 ) ) {
V_84 -> V_98 = ( ( V_64 [ 0 ] ^ V_64 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
if ( V_84 -> V_86 == 2 )
V_84 -> V_99 = ( signed char ) ( V_64 [ 1 ] ) ;
}
if ( F_56 ( V_18 -> V_31 ) ) {
V_84 -> V_100 = ( ( V_64 [ 0 ] ^ V_64 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
V_84 -> V_101 = ( ( V_64 [ 0 ] ^ V_64 [ 3 ] ) & 0x02 ) ? 1 : 0 ;
}
if ( F_17 ( V_18 -> V_32 ) &&
( ( V_64 [ 0 ] ^ V_64 [ 3 ] ) & 0x02 ) ) {
switch ( F_17 ( V_18 -> V_32 ) & ~ 0x01 ) {
default:
break;
case 8 :
V_84 -> V_102 |= ( ( V_64 [ 5 ] & 0x08 ) ) ? 0x80 : 0 ;
V_84 -> V_102 |= ( ( V_64 [ 4 ] & 0x08 ) ) ? 0x40 : 0 ;
case 6 :
V_84 -> V_102 |= ( ( V_64 [ 5 ] & 0x04 ) ) ? 0x20 : 0 ;
V_84 -> V_102 |= ( ( V_64 [ 4 ] & 0x04 ) ) ? 0x10 : 0 ;
case 4 :
V_84 -> V_102 |= ( ( V_64 [ 5 ] & 0x02 ) ) ? 0x08 : 0 ;
V_84 -> V_102 |= ( ( V_64 [ 4 ] & 0x02 ) ) ? 0x04 : 0 ;
case 2 :
V_84 -> V_102 |= ( ( V_64 [ 5 ] & 0x01 ) ) ? 0x02 : 0 ;
V_84 -> V_102 |= ( ( V_64 [ 4 ] & 0x01 ) ) ? 0x01 : 0 ;
}
}
} else {
V_84 -> V_87 = ( ( ( V_64 [ 1 ] & 0x1f ) << 8 ) | V_64 [ 2 ] ) ;
V_84 -> V_13 = ( ( ( V_64 [ 4 ] & 0x1f ) << 8 ) | V_64 [ 5 ] ) ;
V_84 -> V_88 = ( ( ( V_64 [ 0 ] & 0x30 ) << 2 ) | ( V_64 [ 3 ] & 0x3F ) ) ;
V_84 -> V_86 = ( ( ( V_64 [ 1 ] & 0x80 ) >> 4 ) | ( ( V_64 [ 0 ] & 0x04 ) >> 1 ) ) ;
V_84 -> V_91 = ( V_64 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_84 -> V_92 = ( V_64 [ 0 ] & 0x02 ) ? 1 : 0 ;
}
if ( V_84 -> V_87 > V_103 )
V_84 -> V_87 -= 1 << V_104 ;
else if ( V_84 -> V_87 == V_103 )
V_84 -> V_87 = V_105 ;
if ( V_84 -> V_13 > V_106 )
V_84 -> V_13 -= 1 << V_104 ;
else if ( V_84 -> V_13 == V_106 )
V_84 -> V_13 = V_107 ;
return 0 ;
}
static void F_57 ( struct V_108 * V_109 , int V_110 ,
bool V_111 , int V_87 , int V_13 )
{
F_58 ( V_109 , V_110 ) ;
F_59 ( V_109 , V_112 , V_111 ) ;
if ( V_111 ) {
F_60 ( V_109 , V_113 , V_87 ) ;
F_60 ( V_109 , V_114 , F_6 ( V_13 ) ) ;
}
}
static void F_61 ( struct V_108 * V_109 ,
const struct V_83 * V_115 ,
const struct V_83 * V_116 ,
int V_117 )
{
if ( V_117 >= 2 ) {
F_57 ( V_109 , 0 , true , F_62 ( V_115 -> V_87 , V_116 -> V_87 ) ,
F_62 ( V_115 -> V_13 , V_116 -> V_13 ) ) ;
F_57 ( V_109 , 1 , true , F_63 ( V_115 -> V_87 , V_116 -> V_87 ) ,
F_63 ( V_115 -> V_13 , V_116 -> V_13 ) ) ;
} else if ( V_117 == 1 ) {
F_57 ( V_109 , 0 , true , V_115 -> V_87 , V_115 -> V_13 ) ;
F_57 ( V_109 , 1 , false , 0 , 0 ) ;
} else {
F_57 ( V_109 , 0 , false , 0 , 0 ) ;
F_57 ( V_109 , 1 , false , 0 , 0 ) ;
}
}
static void F_64 ( struct V_1 * V_1 ,
const struct V_83 * V_84 )
{
struct V_108 * V_109 = V_1 -> V_109 ;
struct V_17 * V_18 = V_1 -> V_19 ;
int V_40 ;
F_65 ( V_109 , V_118 , V_84 -> V_91 ) ;
F_65 ( V_109 , V_119 , V_84 -> V_92 ) ;
if ( F_55 ( V_18 -> V_31 ) )
F_65 ( V_109 , V_120 , V_84 -> V_98 ) ;
if ( F_56 ( V_18 -> V_31 ) ) {
F_65 ( V_109 , V_121 , V_84 -> V_100 ) ;
F_65 ( V_109 , V_122 , V_84 -> V_101 ) ;
}
for ( V_40 = 0 ; V_40 < F_17 ( V_18 -> V_32 ) ; V_40 ++ )
F_65 ( V_109 , V_123 + V_40 , V_84 -> V_102 & ( 1 << V_40 ) ) ;
}
static void F_66 ( struct V_108 * V_109 , int V_110 ,
const struct V_83 * V_84 )
{
F_58 ( V_109 , V_110 ) ;
F_59 ( V_109 , V_112 , ( V_84 != NULL ) ) ;
if ( ! V_84 )
return;
F_60 ( V_109 , V_113 , V_84 -> V_87 ) ;
F_60 ( V_109 , V_114 , F_6 ( V_84 -> V_13 ) ) ;
F_60 ( V_109 , V_124 , V_84 -> V_88 ) ;
}
static void F_67 ( struct V_1 * V_1 ,
struct V_79 * V_89 ,
const struct V_83 * V_81 )
{
struct V_108 * V_109 = V_1 -> V_109 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_83 * V_82 = & V_18 -> V_82 ;
struct V_79 * V_125 = & V_18 -> V_89 ;
switch ( V_89 -> V_80 ) {
case 0 :
F_66 ( V_109 , 0 , NULL ) ;
F_66 ( V_109 , 1 , NULL ) ;
break;
case 1 :
if ( V_89 -> V_81 == - 1 ) {
F_66 ( V_109 , 0 , NULL ) ;
F_66 ( V_109 , 1 , NULL ) ;
} else if ( V_89 -> V_81 == 0 ) {
F_66 ( V_109 , 0 , V_81 ) ;
F_66 ( V_109 , 1 , NULL ) ;
} else {
F_66 ( V_109 , 0 , NULL ) ;
F_66 ( V_109 , 1 , V_81 ) ;
}
break;
default:
if ( V_89 -> V_81 != - 1 &&
( V_89 -> V_81 == V_125 -> V_81 ||
V_125 -> V_81 == - 1 || V_89 -> V_82 == V_125 -> V_81 ) )
F_66 ( V_109 , 0 , V_81 ) ;
else
F_66 ( V_109 , 0 , NULL ) ;
if ( V_89 -> V_82 != - 1 &&
( V_89 -> V_82 == V_125 -> V_82 ||
( V_125 -> V_82 == - 1 &&
( V_125 -> V_81 == - 1 || V_89 -> V_82 == V_125 -> V_81 ) ) ) )
F_66 ( V_109 , 1 , V_82 ) ;
else
F_66 ( V_109 , 1 , NULL ) ;
break;
}
F_68 ( V_109 , false ) ;
F_69 ( V_109 , V_89 -> V_80 ) ;
F_64 ( V_1 , V_81 ) ;
F_70 ( V_109 ) ;
}
static void F_71 ( struct V_17 * V_18 ,
struct V_79 * V_89 )
{
F_48 ( V_89 , 0 , - 1 , - 1 ) ;
V_18 -> V_126 = false ;
}
static void F_72 ( struct V_17 * V_18 ,
struct V_79 * V_89 )
{
struct V_83 * V_82 = & V_18 -> V_82 ;
struct V_79 * V_125 = & V_18 -> V_89 ;
if ( V_18 -> V_90 && V_82 -> V_88 == 0 ) {
F_48 ( V_89 , 1 , 0 , - 1 ) ;
V_18 -> V_126 = false ;
return;
}
switch ( V_125 -> V_80 ) {
case 0 :
F_48 ( V_89 , 1 , 0 , - 1 ) ;
break;
case 1 :
if ( V_18 -> V_126 ||
( V_18 -> V_90 && V_125 -> V_81 <= 0 ) )
F_48 ( V_89 , 1 , 1 , - 1 ) ;
else if ( V_125 -> V_81 == - 1 )
F_48 ( V_89 , 1 , 0 , - 1 ) ;
break;
case 2 :
if ( V_18 -> V_126 ) {
F_48 ( V_89 , 1 , - 1 , - 1 ) ;
break;
}
F_48 ( V_89 , 1 , V_125 -> V_82 , - 1 ) ;
break;
case 3 :
F_48 ( V_89 , 1 , - 1 , - 1 ) ;
V_18 -> V_126 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_73 ( struct V_17 * V_18 ,
struct V_79 * V_89 )
{
struct V_79 * V_125 = & V_18 -> V_89 ;
switch ( V_125 -> V_80 ) {
case 0 :
F_48 ( V_89 , 2 , 0 , 1 ) ;
break;
case 1 :
if ( V_125 -> V_81 >= 1 )
F_48 ( V_89 , 2 , 0 , V_125 -> V_81 ) ;
else
F_48 ( V_89 , 2 , 0 , 1 ) ;
break;
case 2 :
if ( V_18 -> V_126 )
F_48 ( V_89 , 2 , 0 , 1 ) ;
break;
case 3 :
F_48 ( V_89 , 2 , - 1 , - 1 ) ;
V_18 -> V_126 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_74 ( struct V_17 * V_18 ,
struct V_79 * V_89 )
{
struct V_79 * V_125 = & V_18 -> V_89 ;
switch ( V_125 -> V_80 ) {
case 0 :
F_48 ( V_89 , 3 , 0 , 2 ) ;
break;
case 1 :
if ( V_125 -> V_81 >= 2 )
F_48 ( V_89 , 3 , 0 , V_125 -> V_81 ) ;
else
F_48 ( V_89 , 3 , 0 , 2 ) ;
break;
case 2 :
if ( V_125 -> V_82 >= 3 ) {
F_48 ( V_89 , 3 , 0 , V_125 -> V_82 ) ;
break;
}
if ( V_18 -> V_126 ) {
F_48 ( V_89 , 3 , - 1 , - 1 ) ;
break;
}
F_48 ( V_89 , 3 , 0 , - 1 ) ;
break;
case 3 :
if ( V_125 -> V_82 <= 2 )
F_48 ( V_89 , 3 , 0 , 2 ) ;
break;
case 4 :
case 5 :
break;
}
}
static void F_75 ( struct V_17 * V_18 ,
struct V_79 * V_89 )
{
V_18 -> V_126 = false ;
}
static void F_76 ( struct V_1 * V_1 ,
struct V_83 * V_81 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_83 * V_82 = & V_18 -> V_82 ;
struct V_79 V_89 ;
V_89 = V_82 -> V_89 ;
if ( V_81 -> V_88 == 0 )
F_71 ( V_18 , & V_89 ) ;
else if ( V_81 -> V_86 >= 4 )
F_72 ( V_18 , & V_89 ) ;
else if ( V_81 -> V_86 == 0 )
F_73 ( V_18 , & V_89 ) ;
else if ( V_81 -> V_86 == 1 && V_89 . V_80 <= 3 )
F_74 ( V_18 , & V_89 ) ;
else
F_75 ( V_18 , & V_89 ) ;
F_67 ( V_1 , & V_89 , V_81 ) ;
V_18 -> V_89 = V_82 -> V_89 = V_89 ;
V_18 -> V_90 = false ;
}
static void F_77 ( struct V_1 * V_1 ,
struct V_83 * V_81 ,
int V_117 )
{
struct V_108 * V_109 = V_1 -> V_109 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_83 * V_84 [ 2 ] = { V_81 , & V_18 -> V_82 } ;
struct V_127 V_128 [ 2 ] ;
int V_110 [ 2 ] , V_129 , V_40 ;
V_129 = F_78 ( V_117 , 0 , 2 ) ;
for ( V_40 = 0 ; V_40 < V_129 ; V_40 ++ ) {
V_128 [ V_40 ] . V_87 = V_84 [ V_40 ] -> V_87 ;
V_128 [ V_40 ] . V_13 = F_6 ( V_84 [ V_40 ] -> V_13 ) ;
}
F_79 ( V_109 , V_110 , V_128 , V_129 ) ;
for ( V_40 = 0 ; V_40 < V_129 ; V_40 ++ ) {
F_58 ( V_109 , V_110 [ V_40 ] ) ;
F_59 ( V_109 , V_112 , true ) ;
F_60 ( V_109 , V_113 , V_128 [ V_40 ] . V_87 ) ;
F_60 ( V_109 , V_114 , V_128 [ V_40 ] . V_13 ) ;
F_60 ( V_109 , V_124 , V_84 [ V_40 ] -> V_88 ) ;
}
F_80 ( V_109 ) ;
F_68 ( V_109 , false ) ;
F_69 ( V_109 , V_117 ) ;
F_64 ( V_1 , V_81 ) ;
F_70 ( V_109 ) ;
}
static void F_81 ( struct V_1 * V_1 )
{
struct V_108 * V_109 = V_1 -> V_109 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_83 V_84 ;
int V_117 ;
int V_130 ;
if ( F_50 ( V_1 -> V_66 , V_18 , & V_84 ) )
return;
if ( F_28 ( V_18 -> V_33 ) ) {
F_76 ( V_1 , & V_84 ) ;
return;
}
if ( V_84 . V_99 ) {
V_18 -> V_99 += V_84 . V_99 ;
while ( V_18 -> V_99 >= 4 ) {
F_65 ( V_109 , V_122 , ! V_84 . V_101 ) ;
F_70 ( V_109 ) ;
F_65 ( V_109 , V_122 , V_84 . V_101 ) ;
F_70 ( V_109 ) ;
V_18 -> V_99 -= 4 ;
}
while ( V_18 -> V_99 <= - 4 ) {
F_65 ( V_109 , V_121 , ! V_84 . V_100 ) ;
F_70 ( V_109 ) ;
F_65 ( V_109 , V_121 , V_84 . V_100 ) ;
F_70 ( V_109 ) ;
V_18 -> V_99 += 4 ;
}
return;
}
if ( V_84 . V_88 > 0 && V_84 . V_87 > 1 ) {
V_117 = 1 ;
V_130 = 5 ;
if ( F_14 ( V_18 -> V_31 ) ) {
switch ( V_84 . V_86 ) {
case 0 ... 1 :
if ( F_82 ( V_18 -> V_31 ) )
V_117 = V_84 . V_86 + 2 ;
break;
case 2 :
if ( F_83 ( V_18 -> V_22 ) )
;
break;
case 4 ... 15 :
if ( F_84 ( V_18 -> V_31 ) )
V_130 = V_84 . V_86 ;
break;
}
}
} else {
V_117 = 0 ;
V_130 = 0 ;
}
if ( V_131 ) {
F_77 ( V_1 , & V_84 , V_117 ) ;
return;
}
if ( F_27 ( V_18 -> V_33 ) )
F_61 ( V_109 , & V_84 , & V_18 -> V_82 ,
V_117 ) ;
if ( V_84 . V_88 > 30 ) F_65 ( V_109 , V_132 , 1 ) ;
if ( V_84 . V_88 < 25 ) F_65 ( V_109 , V_132 , 0 ) ;
if ( V_117 > 0 ) {
F_60 ( V_109 , V_133 , V_84 . V_87 ) ;
F_60 ( V_109 , V_134 , F_6 ( V_84 . V_13 ) ) ;
}
F_60 ( V_109 , V_135 , V_84 . V_88 ) ;
if ( F_84 ( V_18 -> V_31 ) )
F_60 ( V_109 , V_136 , V_130 ) ;
F_65 ( V_109 , V_137 , V_117 == 1 ) ;
if ( F_82 ( V_18 -> V_31 ) ) {
F_65 ( V_109 , V_138 , V_117 == 2 ) ;
F_65 ( V_109 , V_139 , V_117 == 3 ) ;
}
F_64 ( V_1 , & V_84 ) ;
F_70 ( V_109 ) ;
}
static int F_85 ( struct V_1 * V_1 ,
int V_140 , unsigned char V_141 )
{
static const unsigned char V_142 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const unsigned char V_143 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_144 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_145 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const unsigned char V_146 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
const char * V_66 = V_1 -> V_66 ;
if ( V_140 < 0 || V_140 > 4 )
return 0 ;
switch ( V_141 ) {
case V_147 :
case V_148 :
return ( V_66 [ V_140 ] & V_143 [ V_140 ] ) == V_144 [ V_140 ] ;
case V_149 :
return ( V_66 [ V_140 ] & V_142 [ V_140 ] ) == V_144 [ V_140 ] ;
case V_150 :
return ( V_66 [ V_140 ] & V_145 [ V_140 ] ) == V_146 [ V_140 ] ;
default:
F_31 ( V_1 , L_13 , V_141 ) ;
return 0 ;
}
}
static unsigned char F_86 ( struct V_1 * V_1 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < 5 ; V_40 ++ )
if ( ! F_85 ( V_1 , V_40 , V_149 ) ) {
F_46 ( V_1 , L_14 ) ;
return V_148 ;
}
return V_149 ;
}
static T_1 F_87 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( V_1 -> V_151 >= 6 ) {
if ( F_88 ( V_18 -> V_141 == V_147 ) )
V_18 -> V_141 = F_86 ( V_1 ) ;
if ( F_89 ( V_18 -> V_31 ) &&
F_39 ( V_1 -> V_66 ) ) {
if ( V_18 -> V_63 )
F_40 ( V_18 -> V_63 , V_1 -> V_66 ) ;
} else
F_81 ( V_1 ) ;
return V_152 ;
}
return F_85 ( V_1 , V_1 -> V_151 - 1 , V_18 -> V_141 ) ?
V_153 : V_154 ;
}
static void F_90 ( struct V_108 * V_109 ,
struct V_17 * V_18 , int V_155 ,
int V_156 )
{
int V_46 = V_18 -> V_46 ? : V_157 ;
int V_47 = V_18 -> V_47 ? : V_158 ;
int V_48 = V_18 -> V_48 ? : V_15 ;
int V_49 = V_18 -> V_49 ? : V_14 ;
int V_159 = F_91 ( V_18 -> V_33 ) ?
V_160 : 0 ;
F_92 ( V_109 , V_155 , V_46 , V_47 , V_159 , 0 ) ;
F_92 ( V_109 , V_156 , V_48 , V_49 , V_159 , 0 ) ;
F_93 ( V_109 , V_155 , V_18 -> V_42 ) ;
F_93 ( V_109 , V_156 , V_18 -> V_43 ) ;
}
static void F_94 ( struct V_1 * V_1 ,
struct V_17 * V_18 )
{
struct V_108 * V_109 = V_1 -> V_109 ;
int V_40 ;
F_95 ( V_161 , V_109 -> V_162 ) ;
F_95 ( V_163 , V_109 -> V_164 ) ;
F_95 ( V_118 , V_109 -> V_165 ) ;
F_95 ( V_119 , V_109 -> V_165 ) ;
if ( F_55 ( V_18 -> V_31 ) )
F_95 ( V_120 , V_109 -> V_165 ) ;
if ( ! V_18 -> V_52 ) {
F_95 ( V_166 , V_109 -> V_164 ) ;
F_95 ( V_167 , V_109 -> V_168 ) ;
F_95 ( V_169 , V_109 -> V_168 ) ;
return;
}
F_95 ( V_170 , V_109 -> V_164 ) ;
F_90 ( V_109 , V_18 , V_133 , V_134 ) ;
F_92 ( V_109 , V_135 , 0 , 255 , 0 , 0 ) ;
if ( V_131 )
F_92 ( V_109 , V_124 , 0 , 255 , 0 , 0 ) ;
if ( F_28 ( V_18 -> V_33 ) ) {
F_90 ( V_109 , V_18 , V_113 ,
V_114 ) ;
F_92 ( V_109 , V_124 , 0 , 255 , 0 , 0 ) ;
F_96 ( V_109 , 2 , V_171 ) ;
F_95 ( V_172 , V_109 -> V_165 ) ;
F_95 ( V_173 , V_109 -> V_165 ) ;
} else if ( F_27 ( V_18 -> V_33 ) ) {
F_90 ( V_109 , V_18 , V_113 ,
V_114 ) ;
F_96 ( V_109 , 2 ,
V_171 |
( V_131 ?
V_174 : V_175 ) ) ;
}
if ( F_84 ( V_18 -> V_31 ) )
F_92 ( V_109 , V_136 , 0 , 15 , 0 , 0 ) ;
F_95 ( V_132 , V_109 -> V_165 ) ;
F_95 ( V_137 , V_109 -> V_165 ) ;
if ( F_82 ( V_18 -> V_31 ) ) {
F_95 ( V_138 , V_109 -> V_165 ) ;
F_95 ( V_139 , V_109 -> V_165 ) ;
}
if ( F_56 ( V_18 -> V_31 ) ||
F_55 ( V_18 -> V_31 ) ) {
F_95 ( V_121 , V_109 -> V_165 ) ;
F_95 ( V_122 , V_109 -> V_165 ) ;
}
for ( V_40 = 0 ; V_40 < F_17 ( V_18 -> V_32 ) ; V_40 ++ )
F_95 ( V_123 + V_40 , V_109 -> V_165 ) ;
F_97 ( V_166 , V_109 -> V_164 ) ;
F_97 ( V_167 , V_109 -> V_168 ) ;
F_97 ( V_169 , V_109 -> V_168 ) ;
if ( F_54 ( V_18 -> V_33 ) ) {
F_95 ( V_176 , V_109 -> V_162 ) ;
if ( F_22 ( V_1 , V_177 ) )
F_95 ( V_178 , V_109 -> V_162 ) ;
F_97 ( V_119 , V_109 -> V_165 ) ;
F_97 ( V_120 , V_109 -> V_165 ) ;
}
}
static T_2 F_98 ( struct V_1 * V_1 ,
void * V_179 , char * V_64 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
return sprintf ( V_64 , L_15 , V_18 -> V_54 ? '1' : '0' ) ;
}
static T_2 F_99 ( struct V_1 * V_1 ,
void * V_179 , const char * V_64 ,
T_3 V_180 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned int V_181 ;
int V_182 ;
V_182 = F_100 ( V_64 , 10 , & V_181 ) ;
if ( V_182 )
return V_182 ;
if ( V_181 > 1 )
return - V_183 ;
if ( V_181 == V_18 -> V_54 )
return V_180 ;
V_18 -> V_54 = V_181 ;
if ( V_181 )
V_18 -> V_2 |= V_55 ;
else
V_18 -> V_2 &= ~ V_55 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
return - V_184 ;
return V_180 ;
}
static void F_101 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( ! V_18 -> V_52 && F_102 ( V_18 -> V_34 ) )
F_103 ( & V_1 -> V_5 . V_59 -> V_109 ,
& V_185 . V_186 ) ;
F_5 ( V_1 ) ;
F_104 ( V_18 ) ;
V_1 -> V_19 = NULL ;
}
static int F_105 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_17 V_187 = * V_18 ;
unsigned char V_3 [ 2 ] ;
int V_188 = 0 ;
int error ;
do {
F_106 ( V_1 ) ;
if ( V_188 ) {
F_107 ( 1 ) ;
}
F_3 ( & V_1 -> V_5 , V_3 , V_189 ) ;
error = F_4 ( V_1 , 0 ) ;
} while ( error && ++ V_188 < 3 );
if ( error )
return - 1 ;
if ( V_188 > 1 )
F_108 ( V_1 , L_16 , V_188 ) ;
if ( F_25 ( V_1 ) ) {
F_31 ( V_1 , L_17 ) ;
return - 1 ;
}
if ( F_30 ( V_1 ) ) {
F_31 ( V_1 , L_18 ) ;
return - 1 ;
}
if ( V_187 . V_34 != V_18 -> V_34 ||
V_187 . V_22 != V_18 -> V_22 ||
V_187 . V_31 != V_18 -> V_31 ||
V_187 . V_32 != V_18 -> V_32 ) {
F_31 ( V_1 ,
L_19 ,
V_187 . V_34 , V_18 -> V_34 ,
V_187 . V_22 , V_18 -> V_22 ,
V_187 . V_31 , V_18 -> V_31 ,
V_187 . V_32 , V_18 -> V_32 ) ;
return - 1 ;
}
return 0 ;
}
void T_4 F_109 ( void )
{
V_190 = F_110 ( V_191 ) ;
V_192 = F_110 ( V_193 ) ;
V_131 = F_110 ( V_194 ) ;
V_93 = F_110 ( V_195 ) ;
}
static int F_111 ( struct V_1 * V_1 , bool V_52 )
{
struct V_17 * V_18 ;
int V_182 = - 1 ;
if ( V_52 && V_192 ) {
F_46 ( V_1 ,
L_20 ) ;
return - V_10 ;
}
V_1 -> V_19 = V_18 = F_44 ( sizeof( struct V_17 ) , V_72 ) ;
if ( ! V_18 )
return - V_196 ;
F_106 ( V_1 ) ;
if ( F_25 ( V_1 ) ) {
F_31 ( V_1 , L_17 ) ;
goto V_197;
}
V_18 -> V_52 = V_52 ;
if ( F_102 ( V_18 -> V_34 ) )
V_18 -> V_54 = true ;
if ( F_30 ( V_1 ) ) {
F_31 ( V_1 , L_18 ) ;
goto V_197;
}
V_18 -> V_141 = F_51 ( V_18 -> V_22 ) ? V_147 : V_150 ;
F_46 ( V_1 ,
L_21 ,
F_112 ( V_18 -> V_34 ) ,
F_21 ( V_18 -> V_34 ) , F_113 ( V_18 -> V_34 ) ,
V_18 -> V_22 ,
V_18 -> V_31 , V_18 -> V_32 , V_18 -> V_33 ,
V_18 -> V_25 , V_18 -> V_28 ) ;
F_94 ( V_1 , V_18 ) ;
V_1 -> V_198 = ( ( V_18 -> V_22 & 0x00ff0000 ) >> 8 ) |
( V_18 -> V_22 & 0x000000ff ) ;
if ( V_52 ) {
V_1 -> V_199 = F_87 ;
V_1 -> V_70 = 6 ;
} else {
V_1 -> V_199 = V_200 ;
V_1 -> V_70 = 3 ;
}
V_1 -> V_201 = F_32 ;
V_1 -> V_202 = F_101 ;
V_1 -> V_203 = F_105 ;
V_1 -> V_204 = F_5 ;
V_1 -> V_205 = 0 ;
if ( F_89 ( V_18 -> V_31 ) )
F_43 ( V_1 ) ;
if ( V_1 -> V_56 >= 80 && V_190 ) {
F_46 ( V_1 ,
L_22 ,
F_114 ( V_206 ) ) ;
V_1 -> V_56 = 40 ;
}
if ( ! V_18 -> V_52 && F_102 ( V_18 -> V_34 ) ) {
V_182 = F_115 ( & V_1 -> V_5 . V_59 -> V_109 ,
& V_185 . V_186 ) ;
if ( V_182 ) {
F_31 ( V_1 ,
L_23 ,
V_182 ) ;
goto V_197;
}
}
return 0 ;
V_197:
F_104 ( V_18 ) ;
return V_182 ;
}
int F_116 ( struct V_1 * V_1 )
{
return F_111 ( V_1 , true ) ;
}
int F_117 ( struct V_1 * V_1 )
{
return F_111 ( V_1 , false ) ;
}
bool F_118 ( void )
{
return true ;
}
void T_4 F_109 ( void )
{
}
int F_116 ( struct V_1 * V_1 )
{
return - V_207 ;
}
bool F_118 ( void )
{
return false ;
}
