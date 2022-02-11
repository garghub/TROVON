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
V_18 -> V_26 = V_18 -> V_27 = 0 ;
if ( F_10 ( V_18 -> V_28 ) < 0x705 &&
F_11 ( V_18 -> V_25 ) != 0x47 ) {
return - 1 ;
}
if ( ! F_12 ( V_18 -> V_25 ) )
V_18 -> V_25 = 0 ;
if ( F_13 ( V_18 -> V_25 ) >= 1 ) {
if ( F_7 ( V_1 , V_29 , V_23 ) ) {
F_14 ( V_1 ,
L_3 ) ;
} else {
V_18 -> V_26 = ( V_23 [ 0 ] << 16 ) | ( V_23 [ 1 ] << 8 ) | V_23 [ 2 ] ;
if ( F_15 ( V_18 -> V_26 ) > 8 )
V_18 -> V_26 &= 0xff0fff ;
}
}
if ( F_13 ( V_18 -> V_25 ) >= 4 ) {
if ( F_7 ( V_1 , V_30 , V_23 ) ) {
F_14 ( V_1 ,
L_4 ) ;
} else {
V_18 -> V_27 = ( V_23 [ 0 ] << 16 ) | ( V_23 [ 1 ] << 8 ) | V_23 [ 2 ] ;
}
}
return 0 ;
}
static int F_16 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_31 [ 3 ] ;
if ( F_7 ( V_1 , V_32 , V_31 ) )
return - 1 ;
V_18 -> V_28 = ( V_31 [ 0 ] << 16 ) | ( V_31 [ 1 ] << 8 ) | V_31 [ 2 ] ;
if ( F_17 ( V_18 -> V_28 ) )
return 0 ;
return - 1 ;
}
static int F_18 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned char V_33 [ 3 ] ;
if ( F_19 ( V_18 -> V_28 ) < 4 )
return 0 ;
if ( F_7 ( V_1 , V_34 , V_33 ) == 0 ) {
if ( V_33 [ 0 ] != 0 && ( V_33 [ 1 ] & 0x80 ) && V_33 [ 2 ] != 0 ) {
V_18 -> V_35 = V_33 [ 0 ] ;
V_18 -> V_36 = V_33 [ 2 ] ;
}
}
if ( F_13 ( V_18 -> V_25 ) >= 5 &&
F_20 ( V_18 -> V_27 ) ) {
if ( F_7 ( V_1 , V_37 , V_33 ) ) {
F_14 ( V_1 ,
L_5 ) ;
} else {
V_18 -> V_38 = ( V_33 [ 0 ] << 5 ) | ( ( V_33 [ 1 ] & 0x0f ) << 1 ) ;
V_18 -> V_39 = ( V_33 [ 2 ] << 5 ) | ( ( V_33 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
if ( F_13 ( V_18 -> V_25 ) >= 7 &&
F_21 ( V_18 -> V_27 ) ) {
if ( F_7 ( V_1 , V_40 , V_33 ) ) {
F_14 ( V_1 ,
L_6 ) ;
} else {
V_18 -> V_41 = ( V_33 [ 0 ] << 5 ) | ( ( V_33 [ 1 ] & 0x0f ) << 1 ) ;
V_18 -> V_42 = ( V_33 [ 2 ] << 5 ) | ( ( V_33 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
if ( F_16 ( V_1 ) )
return - 1 ;
if ( F_8 ( V_1 ) )
return - 1 ;
if ( F_9 ( V_1 ) )
return - 1 ;
if ( F_18 ( V_1 ) )
return - 1 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
static unsigned char V_3 = 0xc8 ;
struct V_17 * V_18 = V_1 -> V_19 ;
if ( ! ( F_24 ( V_18 -> V_27 ) ||
F_25 ( V_18 -> V_27 ) ) )
return 0 ;
if ( F_2 ( V_1 , V_21 ) )
return - 1 ;
if ( F_3 ( & V_1 -> V_5 , & V_3 , V_6 ) )
return - 1 ;
V_18 -> V_25 |= F_26 ( 1 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
V_18 -> V_2 = 0 ;
if ( V_18 -> V_43 )
V_18 -> V_2 |= V_44 ;
if ( V_18 -> V_45 )
V_18 -> V_2 |= V_46 ;
if ( V_1 -> V_47 >= 80 )
V_18 -> V_2 |= V_48 ;
if ( F_12 ( V_18 -> V_25 ) )
V_18 -> V_2 |= V_49 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
return - 1 ;
if ( V_18 -> V_43 &&
F_23 ( V_1 ) ) {
F_28 ( V_1 , L_7 ) ;
return - 1 ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_1 , unsigned int V_47 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( V_47 >= 80 ) {
V_18 -> V_2 |= V_48 ;
V_1 -> V_47 = 80 ;
} else {
V_18 -> V_2 &= ~ V_48 ;
V_1 -> V_47 = 40 ;
}
F_1 ( V_1 , V_18 -> V_2 ) ;
}
static int F_30 ( struct V_50 * V_50 , unsigned char V_16 )
{
struct V_1 * V_51 = F_31 ( V_50 -> V_51 ) ;
char V_52 = V_53 ;
if ( F_2 ( V_51 , V_16 ) )
return - 1 ;
if ( F_3 ( & V_51 -> V_5 , & V_52 , V_6 ) )
return - 1 ;
return 0 ;
}
static int F_32 ( struct V_50 * V_50 )
{
struct V_1 * V_51 = F_31 ( V_50 -> V_51 ) ;
struct V_17 * V_18 = V_51 -> V_19 ;
F_33 ( V_51 -> V_5 . V_50 ) ;
V_18 -> V_54 = V_50 ;
F_34 ( V_51 -> V_5 . V_50 ) ;
return 0 ;
}
static void F_35 ( struct V_50 * V_50 )
{
struct V_1 * V_51 = F_31 ( V_50 -> V_51 ) ;
struct V_17 * V_18 = V_51 -> V_19 ;
F_33 ( V_51 -> V_5 . V_50 ) ;
V_18 -> V_54 = NULL ;
F_34 ( V_51 -> V_5 . V_50 ) ;
}
static int F_36 ( unsigned char * V_55 )
{
return ( V_55 [ 0 ] & 0xFC ) == 0x84 && ( V_55 [ 3 ] & 0xCC ) == 0xC4 ;
}
static void F_37 ( struct V_50 * V_56 , unsigned char * V_57 )
{
struct V_1 * V_58 = F_31 ( V_56 ) ;
if ( V_58 && V_58 -> V_59 == V_60 ) {
F_38 ( V_56 , V_57 [ 1 ] , 0 ) ;
F_38 ( V_56 , V_57 [ 4 ] , 0 ) ;
F_38 ( V_56 , V_57 [ 5 ] , 0 ) ;
if ( V_58 -> V_61 == 4 )
F_38 ( V_56 , V_57 [ 2 ] , 0 ) ;
} else
F_38 ( V_56 , V_57 [ 1 ] , 0 ) ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_1 * V_58 = F_31 ( V_18 -> V_54 ) ;
if ( V_58 ) {
if ( V_58 -> V_61 == 4 )
V_18 -> V_2 |= V_62 ;
else
V_18 -> V_2 &= ~ V_62 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
F_14 ( V_1 ,
L_8 ) ;
}
}
static void F_40 ( struct V_1 * V_1 )
{
struct V_50 * V_50 ;
V_50 = F_41 ( sizeof( struct V_50 ) , V_63 ) ;
if ( ! V_50 ) {
F_28 ( V_1 ,
L_9 ) ;
return;
}
V_50 -> V_31 . type = V_64 ;
F_42 ( V_50 -> V_12 , L_10 , sizeof( V_50 -> V_12 ) ) ;
F_42 ( V_50 -> V_65 , L_11 , sizeof( V_50 -> V_12 ) ) ;
V_50 -> V_66 = F_30 ;
V_50 -> V_67 = F_32 ;
V_50 -> V_68 = F_35 ;
V_50 -> V_51 = V_1 -> V_5 . V_50 ;
V_1 -> V_69 = F_39 ;
F_43 ( V_1 , L_12 ,
V_50 -> V_12 , V_1 -> V_65 ) ;
F_44 ( V_50 ) ;
}
static void F_45 ( struct V_70 * V_59 , int V_71 ,
int V_72 , int V_73 )
{
V_59 -> V_71 = V_71 ;
V_59 -> V_72 = V_72 ;
V_59 -> V_73 = V_73 ;
}
static void F_46 ( const unsigned char V_55 [] ,
struct V_17 * V_18 ,
struct V_74 * V_75 )
{
struct V_74 * V_73 = & V_18 -> V_73 ;
int V_76 ;
V_76 = ( V_55 [ 5 ] & 0x30 ) >> 4 ;
switch ( V_76 ) {
case 1 :
V_73 -> V_77 = V_75 -> V_77 ;
V_73 -> V_78 = ( ( ( V_55 [ 4 ] & 0x0f ) << 8 ) | V_55 [ 1 ] ) << 1 ;
V_73 -> V_13 = ( ( ( V_55 [ 4 ] & 0xf0 ) << 4 ) | V_55 [ 2 ] ) << 1 ;
V_73 -> V_79 = ( ( V_55 [ 3 ] & 0x30 ) | ( V_55 [ 5 ] & 0x0f ) ) << 1 ;
break;
case 2 :
F_45 ( & V_73 -> V_80 , V_55 [ 1 ] , V_55 [ 2 ] , V_55 [ 4 ] ) ;
break;
default:
break;
}
V_18 -> V_81 = true ;
}
static int F_47 ( const unsigned char V_55 [] ,
struct V_17 * V_18 ,
struct V_74 * V_75 )
{
memset ( V_75 , 0 , sizeof( struct V_74 ) ) ;
if ( F_48 ( V_18 -> V_22 ) ) {
V_75 -> V_77 = ( ( ( V_55 [ 0 ] & 0x30 ) >> 2 ) |
( ( V_55 [ 0 ] & 0x04 ) >> 1 ) |
( ( V_55 [ 3 ] & 0x04 ) >> 2 ) ) ;
V_75 -> V_82 = ( V_55 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_75 -> V_83 = ( V_55 [ 0 ] & 0x02 ) ? 1 : 0 ;
if ( F_49 ( V_18 -> V_27 ) ) {
V_75 -> V_82 = ( ( V_55 [ 0 ] ^ V_55 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
} else if ( F_50 ( V_18 -> V_25 ) ) {
V_75 -> V_84 = ( ( V_55 [ 0 ] ^ V_55 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
if ( V_75 -> V_77 == 2 )
V_75 -> V_85 = ( signed char ) ( V_55 [ 1 ] ) ;
}
if ( F_51 ( V_18 -> V_25 ) ) {
V_75 -> V_86 = ( ( V_55 [ 0 ] ^ V_55 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
V_75 -> V_87 = ( ( V_55 [ 0 ] ^ V_55 [ 3 ] ) & 0x02 ) ? 1 : 0 ;
}
if ( ( F_24 ( V_18 -> V_27 ) ||
F_25 ( V_18 -> V_27 ) ) &&
V_75 -> V_77 == 2 ) {
F_46 ( V_55 , V_18 , V_75 ) ;
return 1 ;
}
V_75 -> V_78 = ( ( ( V_55 [ 3 ] & 0x10 ) << 8 ) |
( ( V_55 [ 1 ] & 0x0f ) << 8 ) |
V_55 [ 4 ] ) ;
V_75 -> V_13 = ( ( ( V_55 [ 3 ] & 0x20 ) << 7 ) |
( ( V_55 [ 1 ] & 0xf0 ) << 4 ) |
V_55 [ 5 ] ) ;
V_75 -> V_79 = V_55 [ 2 ] ;
if ( F_15 ( V_18 -> V_26 ) &&
( ( V_55 [ 0 ] ^ V_55 [ 3 ] ) & 0x02 ) ) {
switch ( F_15 ( V_18 -> V_26 ) & ~ 0x01 ) {
default:
break;
case 8 :
V_75 -> V_88 |= ( ( V_55 [ 5 ] & 0x08 ) ) ? 0x80 : 0 ;
V_75 -> V_88 |= ( ( V_55 [ 4 ] & 0x08 ) ) ? 0x40 : 0 ;
case 6 :
V_75 -> V_88 |= ( ( V_55 [ 5 ] & 0x04 ) ) ? 0x20 : 0 ;
V_75 -> V_88 |= ( ( V_55 [ 4 ] & 0x04 ) ) ? 0x10 : 0 ;
case 4 :
V_75 -> V_88 |= ( ( V_55 [ 5 ] & 0x02 ) ) ? 0x08 : 0 ;
V_75 -> V_88 |= ( ( V_55 [ 4 ] & 0x02 ) ) ? 0x04 : 0 ;
case 2 :
V_75 -> V_88 |= ( ( V_55 [ 5 ] & 0x01 ) ) ? 0x02 : 0 ;
V_75 -> V_88 |= ( ( V_55 [ 4 ] & 0x01 ) ) ? 0x01 : 0 ;
}
}
} else {
V_75 -> V_78 = ( ( ( V_55 [ 1 ] & 0x1f ) << 8 ) | V_55 [ 2 ] ) ;
V_75 -> V_13 = ( ( ( V_55 [ 4 ] & 0x1f ) << 8 ) | V_55 [ 5 ] ) ;
V_75 -> V_79 = ( ( ( V_55 [ 0 ] & 0x30 ) << 2 ) | ( V_55 [ 3 ] & 0x3F ) ) ;
V_75 -> V_77 = ( ( ( V_55 [ 1 ] & 0x80 ) >> 4 ) | ( ( V_55 [ 0 ] & 0x04 ) >> 1 ) ) ;
V_75 -> V_82 = ( V_55 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_75 -> V_83 = ( V_55 [ 0 ] & 0x02 ) ? 1 : 0 ;
}
return 0 ;
}
static void F_52 ( struct V_89 * V_90 , int V_91 ,
bool V_92 , int V_78 , int V_13 )
{
F_53 ( V_90 , V_91 ) ;
F_54 ( V_90 , V_93 , V_92 ) ;
if ( V_92 ) {
F_55 ( V_90 , V_94 , V_78 ) ;
F_55 ( V_90 , V_95 , F_6 ( V_13 ) ) ;
}
}
static void F_56 ( struct V_89 * V_90 ,
const struct V_74 * V_96 ,
const struct V_74 * V_97 ,
int V_98 )
{
if ( V_98 >= 2 ) {
F_52 ( V_90 , 0 , true , F_57 ( V_96 -> V_78 , V_97 -> V_78 ) ,
F_57 ( V_96 -> V_13 , V_97 -> V_13 ) ) ;
F_52 ( V_90 , 1 , true , F_58 ( V_96 -> V_78 , V_97 -> V_78 ) ,
F_58 ( V_96 -> V_13 , V_97 -> V_13 ) ) ;
} else if ( V_98 == 1 ) {
F_52 ( V_90 , 0 , true , V_96 -> V_78 , V_96 -> V_13 ) ;
F_52 ( V_90 , 1 , false , 0 , 0 ) ;
} else {
F_52 ( V_90 , 0 , false , 0 , 0 ) ;
F_52 ( V_90 , 1 , false , 0 , 0 ) ;
}
}
static void F_59 ( struct V_1 * V_1 ,
const struct V_74 * V_75 )
{
struct V_89 * V_90 = V_1 -> V_90 ;
struct V_17 * V_18 = V_1 -> V_19 ;
int V_99 ;
F_60 ( V_90 , V_100 , V_75 -> V_82 ) ;
F_60 ( V_90 , V_101 , V_75 -> V_83 ) ;
if ( F_50 ( V_18 -> V_25 ) )
F_60 ( V_90 , V_102 , V_75 -> V_84 ) ;
if ( F_51 ( V_18 -> V_25 ) ) {
F_60 ( V_90 , V_103 , V_75 -> V_86 ) ;
F_60 ( V_90 , V_104 , V_75 -> V_87 ) ;
}
for ( V_99 = 0 ; V_99 < F_15 ( V_18 -> V_26 ) ; V_99 ++ )
F_60 ( V_90 , V_105 + V_99 , V_75 -> V_88 & ( 1 << V_99 ) ) ;
}
static void F_61 ( struct V_89 * V_90 , int V_91 ,
const struct V_74 * V_75 )
{
F_53 ( V_90 , V_91 ) ;
F_54 ( V_90 , V_93 , ( V_75 != NULL ) ) ;
if ( ! V_75 )
return;
F_55 ( V_90 , V_94 , V_75 -> V_78 ) ;
F_55 ( V_90 , V_95 , F_6 ( V_75 -> V_13 ) ) ;
F_55 ( V_90 , V_106 , V_75 -> V_79 ) ;
}
static void F_62 ( struct V_1 * V_1 ,
struct V_70 * V_80 ,
const struct V_74 * V_72 )
{
struct V_89 * V_90 = V_1 -> V_90 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_74 * V_73 = & V_18 -> V_73 ;
struct V_70 * V_107 = & V_18 -> V_80 ;
switch ( V_80 -> V_71 ) {
case 0 :
F_61 ( V_90 , 0 , NULL ) ;
F_61 ( V_90 , 1 , NULL ) ;
break;
case 1 :
if ( V_80 -> V_72 == - 1 ) {
F_61 ( V_90 , 0 , NULL ) ;
F_61 ( V_90 , 1 , NULL ) ;
} else if ( V_80 -> V_72 == 0 ) {
F_61 ( V_90 , 0 , V_72 ) ;
F_61 ( V_90 , 1 , NULL ) ;
} else {
F_61 ( V_90 , 0 , NULL ) ;
F_61 ( V_90 , 1 , V_72 ) ;
}
break;
default:
if ( V_80 -> V_72 != - 1 &&
( V_80 -> V_72 == V_107 -> V_72 || V_107 -> V_72 == - 1 ) )
F_61 ( V_90 , 0 , V_72 ) ;
else
F_61 ( V_90 , 0 , NULL ) ;
if ( V_80 -> V_73 != - 1 &&
( V_80 -> V_73 == V_107 -> V_73 || V_107 -> V_73 == - 1 ) )
F_61 ( V_90 , 1 , V_73 ) ;
else
F_61 ( V_90 , 1 , NULL ) ;
break;
}
F_63 ( V_90 , false ) ;
F_64 ( V_90 , V_80 -> V_71 ) ;
F_59 ( V_1 , V_72 ) ;
F_65 ( V_90 ) ;
}
static void F_66 ( struct V_17 * V_18 ,
struct V_70 * V_80 )
{
F_45 ( V_80 , 0 , - 1 , - 1 ) ;
V_18 -> V_108 = false ;
}
static void F_67 ( struct V_17 * V_18 ,
struct V_70 * V_80 )
{
struct V_74 * V_73 = & V_18 -> V_73 ;
struct V_70 * V_107 = & V_18 -> V_80 ;
if ( V_18 -> V_81 && V_73 -> V_79 == 0 ) {
F_45 ( V_80 , 1 , 0 , - 1 ) ;
V_18 -> V_108 = false ;
return;
}
switch ( V_107 -> V_71 ) {
case 0 :
F_45 ( V_80 , 1 , 0 , - 1 ) ;
break;
case 1 :
if ( V_18 -> V_108 ||
( V_18 -> V_81 && V_107 -> V_72 <= 0 ) )
F_45 ( V_80 , 1 , 1 , - 1 ) ;
else if ( V_107 -> V_72 == - 1 )
F_45 ( V_80 , 1 , 0 , - 1 ) ;
break;
case 2 :
if ( V_18 -> V_108 ) {
F_45 ( V_80 , 1 , - 1 , - 1 ) ;
break;
}
F_45 ( V_80 , 1 , V_107 -> V_73 , - 1 ) ;
break;
case 3 :
F_45 ( V_80 , 1 , - 1 , - 1 ) ;
V_18 -> V_108 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_68 ( struct V_17 * V_18 ,
struct V_70 * V_80 )
{
struct V_70 * V_107 = & V_18 -> V_80 ;
switch ( V_107 -> V_71 ) {
case 0 :
F_45 ( V_80 , 2 , 0 , 1 ) ;
break;
case 1 :
if ( V_107 -> V_72 >= 1 )
F_45 ( V_80 , 2 , 0 , V_107 -> V_72 ) ;
else
F_45 ( V_80 , 2 , 0 , 1 ) ;
break;
case 2 :
if ( V_18 -> V_108 )
F_45 ( V_80 , 2 , 0 , 1 ) ;
break;
case 3 :
F_45 ( V_80 , 2 , - 1 , - 1 ) ;
V_18 -> V_108 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_69 ( struct V_17 * V_18 ,
struct V_70 * V_80 )
{
struct V_70 * V_107 = & V_18 -> V_80 ;
switch ( V_107 -> V_71 ) {
case 0 :
F_45 ( V_80 , 3 , 0 , 2 ) ;
break;
case 1 :
if ( V_107 -> V_72 >= 2 )
F_45 ( V_80 , 3 , 0 , V_107 -> V_72 ) ;
else
F_45 ( V_80 , 3 , 0 , 2 ) ;
break;
case 2 :
if ( V_107 -> V_73 >= 3 ) {
F_45 ( V_80 , 3 , 0 , V_107 -> V_73 ) ;
break;
}
if ( V_18 -> V_108 ) {
F_45 ( V_80 , 3 , - 1 , - 1 ) ;
break;
}
F_45 ( V_80 , 3 , 0 , - 1 ) ;
break;
case 3 :
if ( V_107 -> V_73 <= 2 )
F_45 ( V_80 , 3 , 0 , 2 ) ;
break;
case 4 :
case 5 :
break;
}
}
static void F_70 ( struct V_17 * V_18 ,
struct V_70 * V_80 )
{
V_18 -> V_108 = false ;
}
static void F_71 ( struct V_1 * V_1 ,
struct V_74 * V_72 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_74 * V_73 = & V_18 -> V_73 ;
struct V_70 V_80 ;
V_80 = V_73 -> V_80 ;
if ( V_72 -> V_79 == 0 )
F_66 ( V_18 , & V_80 ) ;
else if ( V_72 -> V_77 >= 4 )
F_67 ( V_18 , & V_80 ) ;
else if ( V_72 -> V_77 == 0 )
F_68 ( V_18 , & V_80 ) ;
else if ( V_72 -> V_77 == 1 && V_80 . V_71 <= 3 )
F_69 ( V_18 , & V_80 ) ;
else
F_70 ( V_18 , & V_80 ) ;
F_62 ( V_1 , & V_80 , V_72 ) ;
V_18 -> V_80 = V_73 -> V_80 = V_80 ;
V_18 -> V_81 = false ;
}
static void F_72 ( struct V_1 * V_1 )
{
struct V_89 * V_90 = V_1 -> V_90 ;
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_74 V_75 ;
int V_98 ;
int V_109 ;
if ( F_47 ( V_1 -> V_57 , V_18 , & V_75 ) )
return;
if ( F_25 ( V_18 -> V_27 ) ) {
F_71 ( V_1 , & V_75 ) ;
return;
}
if ( V_75 . V_85 ) {
V_18 -> V_85 += V_75 . V_85 ;
while ( V_18 -> V_85 >= 4 ) {
F_60 ( V_90 , V_104 , ! V_75 . V_87 ) ;
F_65 ( V_90 ) ;
F_60 ( V_90 , V_104 , V_75 . V_87 ) ;
F_65 ( V_90 ) ;
V_18 -> V_85 -= 4 ;
}
while ( V_18 -> V_85 <= - 4 ) {
F_60 ( V_90 , V_103 , ! V_75 . V_86 ) ;
F_65 ( V_90 ) ;
F_60 ( V_90 , V_103 , V_75 . V_86 ) ;
F_65 ( V_90 ) ;
V_18 -> V_85 += 4 ;
}
return;
}
if ( V_75 . V_79 > 0 && V_75 . V_78 > 1 ) {
V_98 = 1 ;
V_109 = 5 ;
if ( F_12 ( V_18 -> V_25 ) ) {
switch ( V_75 . V_77 ) {
case 0 ... 1 :
if ( F_73 ( V_18 -> V_25 ) )
V_98 = V_75 . V_77 + 2 ;
break;
case 2 :
if ( F_74 ( V_18 -> V_22 ) )
;
break;
case 4 ... 15 :
if ( F_75 ( V_18 -> V_25 ) )
V_109 = V_75 . V_77 ;
break;
}
}
} else {
V_98 = 0 ;
V_109 = 0 ;
}
if ( F_24 ( V_18 -> V_27 ) )
F_56 ( V_90 , & V_75 , & V_18 -> V_73 ,
V_98 ) ;
if ( V_75 . V_79 > 30 ) F_60 ( V_90 , V_110 , 1 ) ;
if ( V_75 . V_79 < 25 ) F_60 ( V_90 , V_110 , 0 ) ;
if ( V_98 > 0 ) {
F_55 ( V_90 , V_111 , V_75 . V_78 ) ;
F_55 ( V_90 , V_112 , F_6 ( V_75 . V_13 ) ) ;
}
F_55 ( V_90 , V_113 , V_75 . V_79 ) ;
if ( F_75 ( V_18 -> V_25 ) )
F_55 ( V_90 , V_114 , V_109 ) ;
F_60 ( V_90 , V_115 , V_98 == 1 ) ;
if ( F_73 ( V_18 -> V_25 ) ) {
F_60 ( V_90 , V_116 , V_98 == 2 ) ;
F_60 ( V_90 , V_117 , V_98 == 3 ) ;
}
F_59 ( V_1 , & V_75 ) ;
F_65 ( V_90 ) ;
}
static int F_76 ( struct V_1 * V_1 ,
int V_118 , unsigned char V_119 )
{
static const unsigned char V_120 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const unsigned char V_121 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_122 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_123 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const unsigned char V_124 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
const char * V_57 = V_1 -> V_57 ;
if ( V_118 < 0 || V_118 > 4 )
return 0 ;
switch ( V_119 ) {
case V_125 :
case V_126 :
return ( V_57 [ V_118 ] & V_121 [ V_118 ] ) == V_122 [ V_118 ] ;
case V_127 :
return ( V_57 [ V_118 ] & V_120 [ V_118 ] ) == V_122 [ V_118 ] ;
case V_128 :
return ( V_57 [ V_118 ] & V_123 [ V_118 ] ) == V_124 [ V_118 ] ;
default:
F_28 ( V_1 , L_13 , V_119 ) ;
return 0 ;
}
}
static unsigned char F_77 ( struct V_1 * V_1 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < 5 ; V_99 ++ )
if ( ! F_76 ( V_1 , V_99 , V_127 ) ) {
F_43 ( V_1 , L_14 ) ;
return V_126 ;
}
return V_127 ;
}
static T_1 F_78 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( V_1 -> V_129 >= 6 ) {
if ( F_79 ( V_18 -> V_119 == V_125 ) )
V_18 -> V_119 = F_77 ( V_1 ) ;
if ( F_80 ( V_18 -> V_25 ) &&
F_36 ( V_1 -> V_57 ) ) {
if ( V_18 -> V_54 )
F_37 ( V_18 -> V_54 , V_1 -> V_57 ) ;
} else
F_72 ( V_1 ) ;
return V_130 ;
}
return F_76 ( V_1 , V_1 -> V_129 - 1 , V_18 -> V_119 ) ?
V_131 : V_132 ;
}
static void F_81 ( struct V_89 * V_90 ,
struct V_17 * V_18 , int V_133 ,
int V_134 )
{
int V_41 = V_18 -> V_41 ? : V_135 ;
int V_38 = V_18 -> V_38 ? : V_136 ;
int V_42 = V_18 -> V_42 ? : V_15 ;
int V_39 = V_18 -> V_39 ? : V_14 ;
int V_137 = F_82 ( V_18 -> V_27 ) ?
V_138 : 0 ;
F_83 ( V_90 , V_133 , V_41 , V_38 , V_137 , 0 ) ;
F_83 ( V_90 , V_134 , V_42 , V_39 , V_137 , 0 ) ;
F_84 ( V_90 , V_133 , V_18 -> V_35 ) ;
F_84 ( V_90 , V_134 , V_18 -> V_36 ) ;
}
static void F_85 ( struct V_89 * V_90 , struct V_17 * V_18 )
{
int V_99 ;
F_86 ( V_139 , V_90 -> V_140 ) ;
F_86 ( V_141 , V_90 -> V_142 ) ;
F_86 ( V_100 , V_90 -> V_143 ) ;
F_86 ( V_101 , V_90 -> V_143 ) ;
if ( F_50 ( V_18 -> V_25 ) )
F_86 ( V_102 , V_90 -> V_143 ) ;
if ( ! V_18 -> V_43 ) {
F_86 ( V_144 , V_90 -> V_142 ) ;
F_86 ( V_145 , V_90 -> V_146 ) ;
F_86 ( V_147 , V_90 -> V_146 ) ;
return;
}
F_86 ( V_148 , V_90 -> V_142 ) ;
F_81 ( V_90 , V_18 , V_111 , V_112 ) ;
F_83 ( V_90 , V_113 , 0 , 255 , 0 , 0 ) ;
if ( F_25 ( V_18 -> V_27 ) ) {
F_87 ( V_90 , 2 ) ;
F_81 ( V_90 , V_18 , V_94 ,
V_95 ) ;
F_83 ( V_90 , V_106 , 0 , 255 , 0 , 0 ) ;
F_86 ( V_149 , V_90 -> V_143 ) ;
F_86 ( V_150 , V_90 -> V_143 ) ;
} else if ( F_24 ( V_18 -> V_27 ) ) {
F_86 ( V_151 , V_90 -> V_140 ) ;
F_87 ( V_90 , 2 ) ;
F_81 ( V_90 , V_18 , V_94 ,
V_95 ) ;
}
if ( F_75 ( V_18 -> V_25 ) )
F_83 ( V_90 , V_114 , 0 , 15 , 0 , 0 ) ;
F_86 ( V_110 , V_90 -> V_143 ) ;
F_86 ( V_115 , V_90 -> V_143 ) ;
if ( F_73 ( V_18 -> V_25 ) ) {
F_86 ( V_116 , V_90 -> V_143 ) ;
F_86 ( V_117 , V_90 -> V_143 ) ;
}
if ( F_51 ( V_18 -> V_25 ) ||
F_50 ( V_18 -> V_25 ) ) {
F_86 ( V_103 , V_90 -> V_143 ) ;
F_86 ( V_104 , V_90 -> V_143 ) ;
}
for ( V_99 = 0 ; V_99 < F_15 ( V_18 -> V_26 ) ; V_99 ++ )
F_86 ( V_105 + V_99 , V_90 -> V_143 ) ;
F_88 ( V_144 , V_90 -> V_142 ) ;
F_88 ( V_145 , V_90 -> V_146 ) ;
F_88 ( V_147 , V_90 -> V_146 ) ;
if ( F_49 ( V_18 -> V_27 ) ) {
F_86 ( V_152 , V_90 -> V_140 ) ;
F_88 ( V_101 , V_90 -> V_143 ) ;
F_88 ( V_102 , V_90 -> V_143 ) ;
}
}
static T_2 F_89 ( struct V_1 * V_1 ,
void * V_153 , char * V_55 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
return sprintf ( V_55 , L_15 , V_18 -> V_45 ? '1' : '0' ) ;
}
static T_2 F_90 ( struct V_1 * V_1 ,
void * V_153 , const char * V_55 ,
T_3 V_154 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
unsigned int V_155 ;
int V_156 ;
V_156 = F_91 ( V_55 , 10 , & V_155 ) ;
if ( V_156 )
return V_156 ;
if ( V_155 > 1 )
return - V_157 ;
if ( V_155 == V_18 -> V_45 )
return V_154 ;
V_18 -> V_45 = V_155 ;
if ( V_155 )
V_18 -> V_2 |= V_46 ;
else
V_18 -> V_2 &= ~ V_46 ;
if ( F_1 ( V_1 , V_18 -> V_2 ) )
return - V_158 ;
return V_154 ;
}
static void F_92 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
if ( ! V_18 -> V_43 && F_93 ( V_18 -> V_28 ) )
F_94 ( & V_1 -> V_5 . V_50 -> V_90 ,
& V_159 . V_160 ) ;
F_5 ( V_1 ) ;
F_95 ( V_18 ) ;
V_1 -> V_19 = NULL ;
}
static int F_96 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_17 V_161 = * V_18 ;
int V_162 = 0 ;
int error ;
do {
F_97 ( V_1 ) ;
if ( V_162 ) {
F_98 ( 1 ) ;
}
error = F_4 ( V_1 , 0 ) ;
} while ( error && ++ V_162 < 3 );
if ( error )
return - 1 ;
if ( V_162 > 1 )
F_99 ( V_1 , L_16 , V_162 ) ;
if ( F_22 ( V_1 ) ) {
F_28 ( V_1 , L_17 ) ;
return - 1 ;
}
if ( F_27 ( V_1 ) ) {
F_28 ( V_1 , L_18 ) ;
return - 1 ;
}
if ( V_161 . V_28 != V_18 -> V_28 ||
V_161 . V_22 != V_18 -> V_22 ||
V_161 . V_25 != V_18 -> V_25 ||
V_161 . V_26 != V_18 -> V_26 ) {
F_28 ( V_1 ,
L_19 ,
V_161 . V_28 , V_18 -> V_28 ,
V_161 . V_22 , V_18 -> V_22 ,
V_161 . V_25 , V_18 -> V_25 ,
V_161 . V_26 , V_18 -> V_26 ) ;
return - 1 ;
}
return 0 ;
}
void T_4 F_100 ( void )
{
V_163 = F_101 ( V_164 ) ;
V_165 = F_101 ( V_166 ) ;
}
static int F_102 ( struct V_1 * V_1 , bool V_43 )
{
struct V_17 * V_18 ;
int V_156 = - 1 ;
if ( V_43 && V_165 ) {
F_43 ( V_1 ,
L_20 ) ;
return - V_10 ;
}
V_1 -> V_19 = V_18 = F_41 ( sizeof( struct V_17 ) , V_63 ) ;
if ( ! V_18 )
return - V_167 ;
F_97 ( V_1 ) ;
if ( F_22 ( V_1 ) ) {
F_28 ( V_1 , L_17 ) ;
goto V_168;
}
V_18 -> V_43 = V_43 ;
if ( F_93 ( V_18 -> V_28 ) )
V_18 -> V_45 = true ;
if ( F_27 ( V_1 ) ) {
F_28 ( V_1 , L_18 ) ;
goto V_168;
}
V_18 -> V_119 = F_48 ( V_18 -> V_22 ) ? V_125 : V_128 ;
F_43 ( V_1 ,
L_21 ,
F_103 ( V_18 -> V_28 ) ,
F_19 ( V_18 -> V_28 ) , F_104 ( V_18 -> V_28 ) ,
V_18 -> V_22 ,
V_18 -> V_25 , V_18 -> V_26 , V_18 -> V_27 ) ;
F_85 ( V_1 -> V_90 , V_18 ) ;
V_1 -> V_169 = ( ( V_18 -> V_22 & 0x00ff0000 ) >> 8 ) |
( V_18 -> V_22 & 0x000000ff ) ;
if ( V_43 ) {
V_1 -> V_170 = F_78 ;
V_1 -> V_61 = 6 ;
} else {
V_1 -> V_170 = V_171 ;
V_1 -> V_61 = 3 ;
}
V_1 -> V_172 = F_29 ;
V_1 -> V_173 = F_92 ;
V_1 -> V_174 = F_96 ;
V_1 -> V_175 = F_5 ;
V_1 -> V_176 = 0 ;
if ( F_80 ( V_18 -> V_25 ) )
F_40 ( V_1 ) ;
if ( V_1 -> V_47 >= 80 && V_163 ) {
F_43 ( V_1 ,
L_22 ,
F_105 ( V_177 ) ) ;
V_1 -> V_47 = 40 ;
}
if ( ! V_18 -> V_43 && F_93 ( V_18 -> V_28 ) ) {
V_156 = F_106 ( & V_1 -> V_5 . V_50 -> V_90 ,
& V_159 . V_160 ) ;
if ( V_156 ) {
F_28 ( V_1 ,
L_23 ,
V_156 ) ;
goto V_168;
}
}
return 0 ;
V_168:
F_95 ( V_18 ) ;
return V_156 ;
}
int F_107 ( struct V_1 * V_1 )
{
return F_102 ( V_1 , true ) ;
}
int F_108 ( struct V_1 * V_1 )
{
return F_102 ( V_1 , false ) ;
}
bool F_109 ( void )
{
return true ;
}
void T_4 F_100 ( void )
{
}
int F_107 ( struct V_1 * V_1 )
{
return - V_178 ;
}
bool F_109 ( void )
{
return false ;
}
