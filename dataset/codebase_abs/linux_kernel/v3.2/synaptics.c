static int F_1 ( int V_1 )
{
return V_2 + V_3 - V_1 ;
}
static int F_2 ( struct V_4 * V_4 , unsigned char V_5 )
{
unsigned char V_6 [ 1 ] ;
if ( F_3 ( V_4 , V_5 ) )
return - 1 ;
V_6 [ 0 ] = V_7 ;
if ( F_4 ( & V_4 -> V_8 , V_6 , V_9 ) )
return - 1 ;
return 0 ;
}
int F_5 ( struct V_4 * V_4 , bool V_10 )
{
struct V_8 * V_8 = & V_4 -> V_8 ;
unsigned char V_6 [ 4 ] ;
V_6 [ 0 ] = 0 ;
F_4 ( V_8 , V_6 , V_11 ) ;
F_4 ( V_8 , V_6 , V_11 ) ;
F_4 ( V_8 , V_6 , V_11 ) ;
F_4 ( V_8 , V_6 , V_11 ) ;
F_4 ( V_8 , V_6 , V_12 ) ;
if ( V_6 [ 1 ] != 0x47 )
return - V_13 ;
if ( V_10 ) {
V_4 -> V_14 = L_1 ;
V_4 -> V_15 = L_2 ;
}
return 0 ;
}
void F_6 ( struct V_4 * V_4 )
{
F_2 ( V_4 , 0 ) ;
}
static int F_7 ( struct V_4 * V_4 , unsigned char V_16 , unsigned char * V_6 )
{
if ( F_3 ( V_4 , V_16 ) )
return - 1 ;
if ( F_4 ( & V_4 -> V_8 , V_6 , V_12 ) )
return - 1 ;
return 0 ;
}
static int F_8 ( struct V_4 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_19 ;
unsigned char V_20 [ 3 ] ;
if ( F_7 ( V_4 , V_21 , V_20 ) )
return - 1 ;
V_18 -> V_22 = ( V_20 [ 0 ] << 16 ) | ( V_20 [ 1 ] << 8 ) | V_20 [ 2 ] ;
return 0 ;
}
static int F_9 ( struct V_4 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_19 ;
unsigned char V_23 [ 3 ] ;
if ( F_7 ( V_4 , V_24 , V_23 ) )
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
if ( F_7 ( V_4 , V_29 , V_23 ) ) {
F_14 ( V_4 ,
L_3 ) ;
} else {
V_18 -> V_26 = ( V_23 [ 0 ] << 16 ) | ( V_23 [ 1 ] << 8 ) | V_23 [ 2 ] ;
if ( F_15 ( V_18 -> V_26 ) > 8 )
V_18 -> V_26 &= 0xff0fff ;
}
}
if ( F_13 ( V_18 -> V_25 ) >= 4 ) {
if ( F_7 ( V_4 , V_30 , V_23 ) ) {
F_14 ( V_4 ,
L_4 ) ;
} else {
V_18 -> V_27 = ( V_23 [ 0 ] << 16 ) | ( V_23 [ 1 ] << 8 ) | V_23 [ 2 ] ;
}
}
return 0 ;
}
static int F_16 ( struct V_4 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_19 ;
unsigned char V_31 [ 3 ] ;
if ( F_7 ( V_4 , V_32 , V_31 ) )
return - 1 ;
V_18 -> V_28 = ( V_31 [ 0 ] << 16 ) | ( V_31 [ 1 ] << 8 ) | V_31 [ 2 ] ;
if ( F_17 ( V_18 -> V_28 ) )
return 0 ;
return - 1 ;
}
static int F_18 ( struct V_4 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_19 ;
unsigned char V_33 [ 3 ] ;
if ( F_19 ( V_18 -> V_28 ) < 4 )
return 0 ;
if ( F_7 ( V_4 , V_34 , V_33 ) == 0 ) {
if ( V_33 [ 0 ] != 0 && ( V_33 [ 1 ] & 0x80 ) && V_33 [ 2 ] != 0 ) {
V_18 -> V_35 = V_33 [ 0 ] ;
V_18 -> V_36 = V_33 [ 2 ] ;
}
}
if ( F_13 ( V_18 -> V_25 ) >= 5 &&
F_20 ( V_18 -> V_27 ) ) {
if ( F_7 ( V_4 , V_37 , V_33 ) ) {
F_14 ( V_4 ,
L_5 ) ;
} else {
V_18 -> V_38 = ( V_33 [ 0 ] << 5 ) | ( ( V_33 [ 1 ] & 0x0f ) << 1 ) ;
V_18 -> V_39 = ( V_33 [ 2 ] << 5 ) | ( ( V_33 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
if ( F_13 ( V_18 -> V_25 ) >= 7 &&
F_21 ( V_18 -> V_27 ) ) {
if ( F_7 ( V_4 , V_40 , V_33 ) ) {
F_14 ( V_4 ,
L_6 ) ;
} else {
V_18 -> V_41 = ( V_33 [ 0 ] << 5 ) | ( ( V_33 [ 1 ] & 0x0f ) << 1 ) ;
V_18 -> V_42 = ( V_33 [ 2 ] << 5 ) | ( ( V_33 [ 1 ] & 0xf0 ) >> 3 ) ;
}
}
return 0 ;
}
static int F_22 ( struct V_4 * V_4 )
{
if ( F_16 ( V_4 ) )
return - 1 ;
if ( F_8 ( V_4 ) )
return - 1 ;
if ( F_9 ( V_4 ) )
return - 1 ;
if ( F_18 ( V_4 ) )
return - 1 ;
return 0 ;
}
static int F_23 ( struct V_4 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_19 ;
V_18 -> V_5 = V_43 ;
if ( F_19 ( V_18 -> V_28 ) >= 4 )
V_18 -> V_5 |= V_44 ;
if ( F_12 ( V_18 -> V_25 ) )
V_18 -> V_5 |= V_45 ;
if ( F_2 ( V_4 , V_18 -> V_5 ) )
return - 1 ;
return 0 ;
}
static void F_24 ( struct V_4 * V_4 , unsigned int V_46 )
{
struct V_17 * V_18 = V_4 -> V_19 ;
if ( V_46 >= 80 ) {
V_18 -> V_5 |= V_47 ;
V_4 -> V_46 = 80 ;
} else {
V_18 -> V_5 &= ~ V_47 ;
V_4 -> V_46 = 40 ;
}
F_2 ( V_4 , V_18 -> V_5 ) ;
}
static int F_25 ( struct V_4 * V_4 )
{
static unsigned char V_6 = 0xc8 ;
struct V_17 * V_18 = V_4 -> V_19 ;
if ( ! ( F_26 ( V_18 -> V_27 ) ||
F_27 ( V_18 -> V_27 ) ) )
return 0 ;
if ( F_3 ( V_4 , V_21 ) )
return - 1 ;
if ( F_4 ( & V_4 -> V_8 , & V_6 , V_9 ) )
return - 1 ;
V_18 -> V_25 |= F_28 ( 1 ) ;
return 0 ;
}
static int F_29 ( struct V_48 * V_48 , unsigned char V_16 )
{
struct V_4 * V_49 = F_30 ( V_48 -> V_49 ) ;
char V_50 = V_51 ;
if ( F_3 ( V_49 , V_16 ) )
return - 1 ;
if ( F_4 ( & V_49 -> V_8 , & V_50 , V_9 ) )
return - 1 ;
return 0 ;
}
static int F_31 ( struct V_48 * V_48 )
{
struct V_4 * V_49 = F_30 ( V_48 -> V_49 ) ;
struct V_17 * V_18 = V_49 -> V_19 ;
F_32 ( V_49 -> V_8 . V_48 ) ;
V_18 -> V_52 = V_48 ;
F_33 ( V_49 -> V_8 . V_48 ) ;
return 0 ;
}
static void F_34 ( struct V_48 * V_48 )
{
struct V_4 * V_49 = F_30 ( V_48 -> V_49 ) ;
struct V_17 * V_18 = V_49 -> V_19 ;
F_32 ( V_49 -> V_8 . V_48 ) ;
V_18 -> V_52 = NULL ;
F_33 ( V_49 -> V_8 . V_48 ) ;
}
static int F_35 ( unsigned char * V_53 )
{
return ( V_53 [ 0 ] & 0xFC ) == 0x84 && ( V_53 [ 3 ] & 0xCC ) == 0xC4 ;
}
static void F_36 ( struct V_48 * V_54 , unsigned char * V_55 )
{
struct V_4 * V_56 = F_30 ( V_54 ) ;
if ( V_56 && V_56 -> V_57 == V_58 ) {
F_37 ( V_54 , V_55 [ 1 ] , 0 ) ;
F_37 ( V_54 , V_55 [ 4 ] , 0 ) ;
F_37 ( V_54 , V_55 [ 5 ] , 0 ) ;
if ( V_56 -> V_59 == 4 )
F_37 ( V_54 , V_55 [ 2 ] , 0 ) ;
} else
F_37 ( V_54 , V_55 [ 1 ] , 0 ) ;
}
static void F_38 ( struct V_4 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_19 ;
struct V_4 * V_56 = F_30 ( V_18 -> V_52 ) ;
if ( V_56 ) {
if ( V_56 -> V_59 == 4 )
V_18 -> V_5 |= V_60 ;
else
V_18 -> V_5 &= ~ V_60 ;
if ( F_2 ( V_4 , V_18 -> V_5 ) )
F_14 ( V_4 ,
L_7 ) ;
}
}
static void F_39 ( struct V_4 * V_4 )
{
struct V_48 * V_48 ;
V_48 = F_40 ( sizeof( struct V_48 ) , V_61 ) ;
if ( ! V_48 ) {
F_41 ( V_4 ,
L_8 ) ;
return;
}
V_48 -> V_31 . type = V_62 ;
F_42 ( V_48 -> V_15 , L_9 , sizeof( V_48 -> V_15 ) ) ;
F_42 ( V_48 -> V_63 , L_10 , sizeof( V_48 -> V_15 ) ) ;
V_48 -> V_64 = F_29 ;
V_48 -> V_65 = F_31 ;
V_48 -> V_66 = F_34 ;
V_48 -> V_49 = V_4 -> V_8 . V_48 ;
V_4 -> V_67 = F_38 ;
F_43 ( V_4 , L_11 ,
V_48 -> V_15 , V_4 -> V_63 ) ;
F_44 ( V_48 ) ;
}
static void F_45 ( struct V_68 * V_57 , int V_69 ,
int V_70 , int V_71 )
{
V_57 -> V_69 = V_69 ;
V_57 -> V_70 = V_70 ;
V_57 -> V_71 = V_71 ;
}
static void F_46 ( const unsigned char V_53 [] ,
struct V_17 * V_18 ,
struct V_72 * V_73 )
{
struct V_72 * V_71 = & V_18 -> V_71 ;
int V_74 ;
V_74 = ( V_53 [ 5 ] & 0x30 ) >> 4 ;
switch ( V_74 ) {
case 1 :
V_71 -> V_75 = V_73 -> V_75 ;
V_71 -> V_76 = ( ( ( V_53 [ 4 ] & 0x0f ) << 8 ) | V_53 [ 1 ] ) << 1 ;
V_71 -> V_1 = ( ( ( V_53 [ 4 ] & 0xf0 ) << 4 ) | V_53 [ 2 ] ) << 1 ;
V_71 -> V_77 = ( ( V_53 [ 3 ] & 0x30 ) | ( V_53 [ 5 ] & 0x0f ) ) << 1 ;
break;
case 2 :
F_45 ( & V_71 -> V_78 , V_53 [ 1 ] , V_53 [ 2 ] , V_53 [ 4 ] ) ;
break;
default:
break;
}
V_18 -> V_79 = true ;
}
static int F_47 ( const unsigned char V_53 [] ,
struct V_17 * V_18 ,
struct V_72 * V_73 )
{
memset ( V_73 , 0 , sizeof( struct V_72 ) ) ;
if ( F_48 ( V_18 -> V_22 ) ) {
V_73 -> V_75 = ( ( ( V_53 [ 0 ] & 0x30 ) >> 2 ) |
( ( V_53 [ 0 ] & 0x04 ) >> 1 ) |
( ( V_53 [ 3 ] & 0x04 ) >> 2 ) ) ;
V_73 -> V_80 = ( V_53 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_73 -> V_81 = ( V_53 [ 0 ] & 0x02 ) ? 1 : 0 ;
if ( F_49 ( V_18 -> V_27 ) ) {
V_73 -> V_80 = ( ( V_53 [ 0 ] ^ V_53 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
} else if ( F_50 ( V_18 -> V_25 ) ) {
V_73 -> V_82 = ( ( V_53 [ 0 ] ^ V_53 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
if ( V_73 -> V_75 == 2 )
V_73 -> V_83 = ( signed char ) ( V_53 [ 1 ] ) ;
}
if ( F_51 ( V_18 -> V_25 ) ) {
V_73 -> V_84 = ( ( V_53 [ 0 ] ^ V_53 [ 3 ] ) & 0x01 ) ? 1 : 0 ;
V_73 -> V_85 = ( ( V_53 [ 0 ] ^ V_53 [ 3 ] ) & 0x02 ) ? 1 : 0 ;
}
if ( ( F_26 ( V_18 -> V_27 ) ||
F_27 ( V_18 -> V_27 ) ) &&
V_73 -> V_75 == 2 ) {
F_46 ( V_53 , V_18 , V_73 ) ;
return 1 ;
}
V_73 -> V_76 = ( ( ( V_53 [ 3 ] & 0x10 ) << 8 ) |
( ( V_53 [ 1 ] & 0x0f ) << 8 ) |
V_53 [ 4 ] ) ;
V_73 -> V_1 = ( ( ( V_53 [ 3 ] & 0x20 ) << 7 ) |
( ( V_53 [ 1 ] & 0xf0 ) << 4 ) |
V_53 [ 5 ] ) ;
V_73 -> V_77 = V_53 [ 2 ] ;
if ( F_15 ( V_18 -> V_26 ) &&
( ( V_53 [ 0 ] ^ V_53 [ 3 ] ) & 0x02 ) ) {
switch ( F_15 ( V_18 -> V_26 ) & ~ 0x01 ) {
default:
break;
case 8 :
V_73 -> V_86 |= ( ( V_53 [ 5 ] & 0x08 ) ) ? 0x80 : 0 ;
V_73 -> V_86 |= ( ( V_53 [ 4 ] & 0x08 ) ) ? 0x40 : 0 ;
case 6 :
V_73 -> V_86 |= ( ( V_53 [ 5 ] & 0x04 ) ) ? 0x20 : 0 ;
V_73 -> V_86 |= ( ( V_53 [ 4 ] & 0x04 ) ) ? 0x10 : 0 ;
case 4 :
V_73 -> V_86 |= ( ( V_53 [ 5 ] & 0x02 ) ) ? 0x08 : 0 ;
V_73 -> V_86 |= ( ( V_53 [ 4 ] & 0x02 ) ) ? 0x04 : 0 ;
case 2 :
V_73 -> V_86 |= ( ( V_53 [ 5 ] & 0x01 ) ) ? 0x02 : 0 ;
V_73 -> V_86 |= ( ( V_53 [ 4 ] & 0x01 ) ) ? 0x01 : 0 ;
}
}
} else {
V_73 -> V_76 = ( ( ( V_53 [ 1 ] & 0x1f ) << 8 ) | V_53 [ 2 ] ) ;
V_73 -> V_1 = ( ( ( V_53 [ 4 ] & 0x1f ) << 8 ) | V_53 [ 5 ] ) ;
V_73 -> V_77 = ( ( ( V_53 [ 0 ] & 0x30 ) << 2 ) | ( V_53 [ 3 ] & 0x3F ) ) ;
V_73 -> V_75 = ( ( ( V_53 [ 1 ] & 0x80 ) >> 4 ) | ( ( V_53 [ 0 ] & 0x04 ) >> 1 ) ) ;
V_73 -> V_80 = ( V_53 [ 0 ] & 0x01 ) ? 1 : 0 ;
V_73 -> V_81 = ( V_53 [ 0 ] & 0x02 ) ? 1 : 0 ;
}
return 0 ;
}
static void F_52 ( struct V_87 * V_88 , int V_89 ,
bool V_90 , int V_76 , int V_1 )
{
F_53 ( V_88 , V_89 ) ;
F_54 ( V_88 , V_91 , V_90 ) ;
if ( V_90 ) {
F_55 ( V_88 , V_92 , V_76 ) ;
F_55 ( V_88 , V_93 , F_1 ( V_1 ) ) ;
}
}
static void F_56 ( struct V_87 * V_88 ,
const struct V_72 * V_94 ,
const struct V_72 * V_95 ,
int V_96 )
{
if ( V_96 >= 2 ) {
F_52 ( V_88 , 0 , true , F_57 ( V_94 -> V_76 , V_95 -> V_76 ) ,
F_57 ( V_94 -> V_1 , V_95 -> V_1 ) ) ;
F_52 ( V_88 , 1 , true , F_58 ( V_94 -> V_76 , V_95 -> V_76 ) ,
F_58 ( V_94 -> V_1 , V_95 -> V_1 ) ) ;
} else if ( V_96 == 1 ) {
F_52 ( V_88 , 0 , true , V_94 -> V_76 , V_94 -> V_1 ) ;
F_52 ( V_88 , 1 , false , 0 , 0 ) ;
} else {
F_52 ( V_88 , 0 , false , 0 , 0 ) ;
F_52 ( V_88 , 1 , false , 0 , 0 ) ;
}
}
static void F_59 ( struct V_4 * V_4 ,
const struct V_72 * V_73 )
{
struct V_87 * V_88 = V_4 -> V_88 ;
struct V_17 * V_18 = V_4 -> V_19 ;
int V_97 ;
F_60 ( V_88 , V_98 , V_73 -> V_80 ) ;
F_60 ( V_88 , V_99 , V_73 -> V_81 ) ;
if ( F_50 ( V_18 -> V_25 ) )
F_60 ( V_88 , V_100 , V_73 -> V_82 ) ;
if ( F_51 ( V_18 -> V_25 ) ) {
F_60 ( V_88 , V_101 , V_73 -> V_84 ) ;
F_60 ( V_88 , V_102 , V_73 -> V_85 ) ;
}
for ( V_97 = 0 ; V_97 < F_15 ( V_18 -> V_26 ) ; V_97 ++ )
F_60 ( V_88 , V_103 + V_97 , V_73 -> V_86 & ( 1 << V_97 ) ) ;
}
static void F_61 ( struct V_87 * V_88 , int V_89 ,
const struct V_72 * V_73 )
{
F_53 ( V_88 , V_89 ) ;
F_54 ( V_88 , V_91 , ( V_73 != NULL ) ) ;
if ( ! V_73 )
return;
F_55 ( V_88 , V_92 , V_73 -> V_76 ) ;
F_55 ( V_88 , V_93 , F_1 ( V_73 -> V_1 ) ) ;
F_55 ( V_88 , V_104 , V_73 -> V_77 ) ;
}
static void F_62 ( struct V_4 * V_4 ,
struct V_68 * V_78 ,
const struct V_72 * V_70 )
{
struct V_87 * V_88 = V_4 -> V_88 ;
struct V_17 * V_18 = V_4 -> V_19 ;
struct V_72 * V_71 = & V_18 -> V_71 ;
struct V_68 * V_105 = & V_18 -> V_78 ;
switch ( V_78 -> V_69 ) {
case 0 :
F_61 ( V_88 , 0 , NULL ) ;
F_61 ( V_88 , 1 , NULL ) ;
break;
case 1 :
if ( V_78 -> V_70 == - 1 ) {
F_61 ( V_88 , 0 , NULL ) ;
F_61 ( V_88 , 1 , NULL ) ;
} else if ( V_78 -> V_70 == 0 ) {
F_61 ( V_88 , 0 , V_70 ) ;
F_61 ( V_88 , 1 , NULL ) ;
} else {
F_61 ( V_88 , 0 , NULL ) ;
F_61 ( V_88 , 1 , V_70 ) ;
}
break;
default:
if ( V_78 -> V_70 != - 1 &&
( V_78 -> V_70 == V_105 -> V_70 || V_105 -> V_70 == - 1 ) )
F_61 ( V_88 , 0 , V_70 ) ;
else
F_61 ( V_88 , 0 , NULL ) ;
if ( V_78 -> V_71 != - 1 &&
( V_78 -> V_71 == V_105 -> V_71 || V_105 -> V_71 == - 1 ) )
F_61 ( V_88 , 1 , V_71 ) ;
else
F_61 ( V_88 , 1 , NULL ) ;
break;
}
F_63 ( V_88 , false ) ;
F_64 ( V_88 , V_78 -> V_69 ) ;
F_59 ( V_4 , V_70 ) ;
F_65 ( V_88 ) ;
}
static void F_66 ( struct V_17 * V_18 ,
struct V_68 * V_78 )
{
F_45 ( V_78 , 0 , - 1 , - 1 ) ;
V_18 -> V_106 = false ;
}
static void F_67 ( struct V_17 * V_18 ,
struct V_68 * V_78 )
{
struct V_72 * V_71 = & V_18 -> V_71 ;
struct V_68 * V_105 = & V_18 -> V_78 ;
if ( V_18 -> V_79 && V_71 -> V_77 == 0 ) {
F_45 ( V_78 , 1 , 0 , - 1 ) ;
V_18 -> V_106 = false ;
return;
}
switch ( V_105 -> V_69 ) {
case 0 :
F_45 ( V_78 , 1 , 0 , - 1 ) ;
break;
case 1 :
if ( V_18 -> V_106 ||
( V_18 -> V_79 && V_105 -> V_70 <= 0 ) )
F_45 ( V_78 , 1 , 1 , - 1 ) ;
else if ( V_105 -> V_70 == - 1 )
F_45 ( V_78 , 1 , 0 , - 1 ) ;
break;
case 2 :
if ( V_18 -> V_106 ) {
F_45 ( V_78 , 1 , - 1 , - 1 ) ;
break;
}
F_45 ( V_78 , 1 , V_105 -> V_71 , - 1 ) ;
break;
case 3 :
F_45 ( V_78 , 1 , - 1 , - 1 ) ;
V_18 -> V_106 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_68 ( struct V_17 * V_18 ,
struct V_68 * V_78 )
{
struct V_68 * V_105 = & V_18 -> V_78 ;
switch ( V_105 -> V_69 ) {
case 0 :
F_45 ( V_78 , 2 , 0 , 1 ) ;
break;
case 1 :
if ( V_105 -> V_70 >= 1 )
F_45 ( V_78 , 2 , 0 , V_105 -> V_70 ) ;
else
F_45 ( V_78 , 2 , 0 , 1 ) ;
break;
case 2 :
if ( V_18 -> V_106 )
F_45 ( V_78 , 2 , 0 , 1 ) ;
break;
case 3 :
F_45 ( V_78 , 2 , - 1 , - 1 ) ;
V_18 -> V_106 = true ;
break;
case 4 :
case 5 :
break;
}
}
static void F_69 ( struct V_17 * V_18 ,
struct V_68 * V_78 )
{
struct V_68 * V_105 = & V_18 -> V_78 ;
switch ( V_105 -> V_69 ) {
case 0 :
F_45 ( V_78 , 3 , 0 , 2 ) ;
break;
case 1 :
if ( V_105 -> V_70 >= 2 )
F_45 ( V_78 , 3 , 0 , V_105 -> V_70 ) ;
else
F_45 ( V_78 , 3 , 0 , 2 ) ;
break;
case 2 :
if ( V_105 -> V_71 >= 3 ) {
F_45 ( V_78 , 3 , 0 , V_105 -> V_71 ) ;
break;
}
if ( V_18 -> V_106 ) {
F_45 ( V_78 , 3 , - 1 , - 1 ) ;
break;
}
F_45 ( V_78 , 3 , 0 , - 1 ) ;
break;
case 3 :
if ( V_105 -> V_71 <= 2 )
F_45 ( V_78 , 3 , 0 , 2 ) ;
break;
case 4 :
case 5 :
break;
}
}
static void F_70 ( struct V_17 * V_18 ,
struct V_68 * V_78 )
{
V_18 -> V_106 = false ;
}
static void F_71 ( struct V_4 * V_4 ,
struct V_72 * V_70 )
{
struct V_17 * V_18 = V_4 -> V_19 ;
struct V_72 * V_71 = & V_18 -> V_71 ;
struct V_68 V_78 ;
V_78 = V_71 -> V_78 ;
if ( V_70 -> V_77 == 0 )
F_66 ( V_18 , & V_78 ) ;
else if ( V_70 -> V_75 >= 4 )
F_67 ( V_18 , & V_78 ) ;
else if ( V_70 -> V_75 == 0 )
F_68 ( V_18 , & V_78 ) ;
else if ( V_70 -> V_75 == 1 && V_78 . V_69 <= 3 )
F_69 ( V_18 , & V_78 ) ;
else
F_70 ( V_18 , & V_78 ) ;
F_62 ( V_4 , & V_78 , V_70 ) ;
V_18 -> V_78 = V_71 -> V_78 = V_78 ;
V_18 -> V_79 = false ;
}
static void F_72 ( struct V_4 * V_4 )
{
struct V_87 * V_88 = V_4 -> V_88 ;
struct V_17 * V_18 = V_4 -> V_19 ;
struct V_72 V_73 ;
int V_96 ;
int V_107 ;
if ( F_47 ( V_4 -> V_55 , V_18 , & V_73 ) )
return;
if ( F_27 ( V_18 -> V_27 ) ) {
F_71 ( V_4 , & V_73 ) ;
return;
}
if ( V_73 . V_83 ) {
V_18 -> V_83 += V_73 . V_83 ;
while ( V_18 -> V_83 >= 4 ) {
F_60 ( V_88 , V_102 , ! V_73 . V_85 ) ;
F_65 ( V_88 ) ;
F_60 ( V_88 , V_102 , V_73 . V_85 ) ;
F_65 ( V_88 ) ;
V_18 -> V_83 -= 4 ;
}
while ( V_18 -> V_83 <= - 4 ) {
F_60 ( V_88 , V_101 , ! V_73 . V_84 ) ;
F_65 ( V_88 ) ;
F_60 ( V_88 , V_101 , V_73 . V_84 ) ;
F_65 ( V_88 ) ;
V_18 -> V_83 += 4 ;
}
return;
}
if ( V_73 . V_77 > 0 && V_73 . V_76 > 1 ) {
V_96 = 1 ;
V_107 = 5 ;
if ( F_12 ( V_18 -> V_25 ) ) {
switch ( V_73 . V_75 ) {
case 0 ... 1 :
if ( F_73 ( V_18 -> V_25 ) )
V_96 = V_73 . V_75 + 2 ;
break;
case 2 :
if ( F_74 ( V_18 -> V_22 ) )
;
break;
case 4 ... 15 :
if ( F_75 ( V_18 -> V_25 ) )
V_107 = V_73 . V_75 ;
break;
}
}
} else {
V_96 = 0 ;
V_107 = 0 ;
}
if ( F_26 ( V_18 -> V_27 ) )
F_56 ( V_88 , & V_73 , & V_18 -> V_71 ,
V_96 ) ;
if ( V_73 . V_77 > 30 ) F_60 ( V_88 , V_108 , 1 ) ;
if ( V_73 . V_77 < 25 ) F_60 ( V_88 , V_108 , 0 ) ;
if ( V_96 > 0 ) {
F_55 ( V_88 , V_109 , V_73 . V_76 ) ;
F_55 ( V_88 , V_110 , F_1 ( V_73 . V_1 ) ) ;
}
F_55 ( V_88 , V_111 , V_73 . V_77 ) ;
if ( F_75 ( V_18 -> V_25 ) )
F_55 ( V_88 , V_112 , V_107 ) ;
F_60 ( V_88 , V_113 , V_96 == 1 ) ;
if ( F_73 ( V_18 -> V_25 ) ) {
F_60 ( V_88 , V_114 , V_96 == 2 ) ;
F_60 ( V_88 , V_115 , V_96 == 3 ) ;
}
F_59 ( V_4 , & V_73 ) ;
F_65 ( V_88 ) ;
}
static int F_76 ( struct V_4 * V_4 ,
int V_116 , unsigned char V_117 )
{
static const unsigned char V_118 [] = { 0xC8 , 0x00 , 0x00 , 0xC8 , 0x00 } ;
static const unsigned char V_119 [] = { 0xC0 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_120 [] = { 0x80 , 0x00 , 0x00 , 0xC0 , 0x00 } ;
static const unsigned char V_121 [] = { 0xC0 , 0x60 , 0x00 , 0xC0 , 0x60 } ;
static const unsigned char V_122 [] = { 0xC0 , 0x00 , 0x00 , 0x80 , 0x00 } ;
const char * V_55 = V_4 -> V_55 ;
if ( V_116 < 0 || V_116 > 4 )
return 0 ;
switch ( V_117 ) {
case V_123 :
case V_124 :
return ( V_55 [ V_116 ] & V_119 [ V_116 ] ) == V_120 [ V_116 ] ;
case V_125 :
return ( V_55 [ V_116 ] & V_118 [ V_116 ] ) == V_120 [ V_116 ] ;
case V_126 :
return ( V_55 [ V_116 ] & V_121 [ V_116 ] ) == V_122 [ V_116 ] ;
default:
F_41 ( V_4 , L_12 , V_117 ) ;
return 0 ;
}
}
static unsigned char F_77 ( struct V_4 * V_4 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < 5 ; V_97 ++ )
if ( ! F_76 ( V_4 , V_97 , V_125 ) ) {
F_43 ( V_4 , L_13 ) ;
return V_124 ;
}
return V_125 ;
}
static T_1 F_78 ( struct V_4 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_19 ;
if ( V_4 -> V_127 >= 6 ) {
if ( F_79 ( V_18 -> V_117 == V_123 ) )
V_18 -> V_117 = F_77 ( V_4 ) ;
if ( F_80 ( V_18 -> V_25 ) &&
F_35 ( V_4 -> V_55 ) ) {
if ( V_18 -> V_52 )
F_36 ( V_18 -> V_52 , V_4 -> V_55 ) ;
} else
F_72 ( V_4 ) ;
return V_128 ;
}
return F_76 ( V_4 , V_4 -> V_127 - 1 , V_18 -> V_117 ) ?
V_129 : V_130 ;
}
static void F_81 ( struct V_87 * V_88 ,
struct V_17 * V_18 , int V_131 ,
int V_132 )
{
int V_41 = V_18 -> V_41 ? : V_133 ;
int V_38 = V_18 -> V_38 ? : V_134 ;
int V_42 = V_18 -> V_42 ? : V_3 ;
int V_39 = V_18 -> V_39 ? : V_2 ;
int V_135 = F_82 ( V_18 -> V_27 ) ?
V_136 : 0 ;
F_83 ( V_88 , V_131 , V_41 , V_38 , V_135 , 0 ) ;
F_83 ( V_88 , V_132 , V_42 , V_39 , V_135 , 0 ) ;
F_84 ( V_88 , V_131 , V_18 -> V_35 ) ;
F_84 ( V_88 , V_132 , V_18 -> V_36 ) ;
}
static void F_85 ( struct V_87 * V_88 , struct V_17 * V_18 )
{
int V_97 ;
F_86 ( V_137 , V_88 -> V_138 ) ;
F_86 ( V_139 , V_88 -> V_140 ) ;
F_81 ( V_88 , V_18 , V_109 , V_110 ) ;
F_83 ( V_88 , V_111 , 0 , 255 , 0 , 0 ) ;
if ( F_27 ( V_18 -> V_27 ) ) {
F_87 ( V_88 , 2 ) ;
F_81 ( V_88 , V_18 , V_92 ,
V_93 ) ;
F_83 ( V_88 , V_104 , 0 , 255 , 0 , 0 ) ;
F_86 ( V_141 , V_88 -> V_142 ) ;
F_86 ( V_143 , V_88 -> V_142 ) ;
} else if ( F_26 ( V_18 -> V_27 ) ) {
F_86 ( V_144 , V_88 -> V_138 ) ;
F_87 ( V_88 , 2 ) ;
F_81 ( V_88 , V_18 , V_92 ,
V_93 ) ;
}
if ( F_75 ( V_18 -> V_25 ) )
F_83 ( V_88 , V_112 , 0 , 15 , 0 , 0 ) ;
F_86 ( V_145 , V_88 -> V_140 ) ;
F_86 ( V_108 , V_88 -> V_142 ) ;
F_86 ( V_113 , V_88 -> V_142 ) ;
F_86 ( V_98 , V_88 -> V_142 ) ;
F_86 ( V_99 , V_88 -> V_142 ) ;
if ( F_73 ( V_18 -> V_25 ) ) {
F_86 ( V_114 , V_88 -> V_142 ) ;
F_86 ( V_115 , V_88 -> V_142 ) ;
}
if ( F_50 ( V_18 -> V_25 ) )
F_86 ( V_100 , V_88 -> V_142 ) ;
if ( F_51 ( V_18 -> V_25 ) ||
F_50 ( V_18 -> V_25 ) ) {
F_86 ( V_101 , V_88 -> V_142 ) ;
F_86 ( V_102 , V_88 -> V_142 ) ;
}
for ( V_97 = 0 ; V_97 < F_15 ( V_18 -> V_26 ) ; V_97 ++ )
F_86 ( V_103 + V_97 , V_88 -> V_142 ) ;
F_88 ( V_146 , V_88 -> V_140 ) ;
F_88 ( V_147 , V_88 -> V_148 ) ;
F_88 ( V_149 , V_88 -> V_148 ) ;
if ( F_49 ( V_18 -> V_27 ) ) {
F_86 ( V_150 , V_88 -> V_138 ) ;
F_88 ( V_99 , V_88 -> V_142 ) ;
F_88 ( V_100 , V_88 -> V_142 ) ;
}
}
static void F_89 ( struct V_4 * V_4 )
{
F_6 ( V_4 ) ;
F_90 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
}
static int F_91 ( struct V_4 * V_4 )
{
struct V_17 * V_18 = V_4 -> V_19 ;
struct V_17 V_151 = * V_18 ;
int V_152 = 0 ;
int error ;
do {
F_92 ( V_4 ) ;
if ( V_152 ) {
F_93 ( 1 ) ;
}
error = F_5 ( V_4 , 0 ) ;
} while ( error && ++ V_152 < 3 );
if ( error )
return - 1 ;
if ( V_152 > 1 )
F_94 ( V_4 , L_14 , V_152 ) ;
if ( F_22 ( V_4 ) ) {
F_41 ( V_4 , L_15 ) ;
return - 1 ;
}
if ( F_23 ( V_4 ) ) {
F_41 ( V_4 , L_16 ) ;
return - 1 ;
}
if ( F_25 ( V_4 ) ) {
F_41 ( V_4 ,
L_17 ) ;
return - 1 ;
}
if ( V_151 . V_28 != V_18 -> V_28 ||
V_151 . V_22 != V_18 -> V_22 ||
V_151 . V_25 != V_18 -> V_25 ||
V_151 . V_26 != V_18 -> V_26 ) {
F_41 ( V_4 ,
L_18 ,
V_151 . V_28 , V_18 -> V_28 ,
V_151 . V_22 , V_18 -> V_22 ,
V_151 . V_25 , V_18 -> V_25 ,
V_151 . V_26 , V_18 -> V_26 ) ;
return - 1 ;
}
return 0 ;
}
void T_2 F_95 ( void )
{
V_153 = F_96 ( V_154 ) ;
V_155 = F_96 ( V_156 ) ;
}
int F_97 ( struct V_4 * V_4 )
{
struct V_17 * V_18 ;
if ( V_155 ) {
F_43 ( V_4 ,
L_19 ) ;
return - V_13 ;
}
V_4 -> V_19 = V_18 = F_40 ( sizeof( struct V_17 ) , V_61 ) ;
if ( ! V_18 )
return - V_157 ;
F_92 ( V_4 ) ;
if ( F_22 ( V_4 ) ) {
F_41 ( V_4 , L_15 ) ;
goto V_158;
}
if ( F_23 ( V_4 ) ) {
F_41 ( V_4 , L_16 ) ;
goto V_158;
}
if ( F_25 ( V_4 ) ) {
F_41 ( V_4 , L_20 ) ;
goto V_158;
}
V_18 -> V_117 = F_48 ( V_18 -> V_22 ) ? V_123 : V_126 ;
F_43 ( V_4 ,
L_21 ,
F_98 ( V_18 -> V_28 ) ,
F_19 ( V_18 -> V_28 ) , F_99 ( V_18 -> V_28 ) ,
V_18 -> V_22 ,
V_18 -> V_25 , V_18 -> V_26 , V_18 -> V_27 ) ;
F_85 ( V_4 -> V_88 , V_18 ) ;
V_4 -> V_159 = ( ( V_18 -> V_22 & 0x00ff0000 ) >> 8 ) |
( V_18 -> V_22 & 0x000000ff ) ;
V_4 -> V_160 = F_78 ;
V_4 -> V_161 = F_24 ;
V_4 -> V_162 = F_89 ;
V_4 -> V_163 = F_91 ;
V_4 -> V_164 = F_6 ;
V_4 -> V_59 = 6 ;
V_4 -> V_165 = 0 ;
if ( F_80 ( V_18 -> V_25 ) )
F_39 ( V_4 ) ;
if ( V_4 -> V_46 >= 80 && V_153 ) {
F_43 ( V_4 ,
L_22 ,
F_100 ( V_166 ) ) ;
V_4 -> V_46 = 40 ;
}
return 0 ;
V_158:
F_90 ( V_18 ) ;
return - 1 ;
}
bool F_101 ( void )
{
return true ;
}
void T_2 F_95 ( void )
{
}
int F_97 ( struct V_4 * V_4 )
{
return - V_167 ;
}
bool F_101 ( void )
{
return false ;
}
