static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 [ 2 ] = { V_3 , V_4 } ;
struct V_9 V_10 = { . V_11 = V_6 -> V_12 . V_13 , . V_14 = 0 ,
. V_8 = V_8 , . V_15 = 2 } ;
int V_16 = F_2 ( V_6 -> V_17 , & V_10 , 1 ) ;
if ( V_16 != 1 ) {
F_3 ( L_1 , V_3 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , const T_1 V_18 [] , int V_19 )
{
int V_16 , V_20 ;
for ( V_20 = 0 ; V_20 < V_19 - 1 ; V_20 ++ )
if ( ( V_16 = F_1 ( V_2 , V_18 [ 0 ] + V_20 , V_18 [ V_20 + 1 ] ) ) )
return V_16 ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 , T_1 V_3 )
{
int V_21 ;
T_1 V_22 [] = { V_3 } ;
T_1 V_23 [] = { 0 } ;
struct V_9 V_10 [] = { { . V_11 = V_6 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_8 = V_22 , . V_15 = 1 } ,
{ . V_11 = V_6 -> V_12 . V_13 ,
. V_14 = V_24 ,
. V_8 = V_23 , . V_15 = 1 } } ;
V_21 = F_2 ( V_6 -> V_17 , V_10 , 2 ) ;
if ( V_21 != 2 ) {
F_3 ( L_2 ,
V_25 , V_3 , V_21 ) ;
return V_21 ;
}
return V_23 [ 0 ] ;
}
static int F_6 ( struct V_1 * V_2 )
{
static T_1 V_26 [] = { V_27 , 0x20 , 0x08 } ;
F_4 ( V_2 , V_26 , sizeof( V_26 ) ) ;
return 0 ;
}
static void F_7 ( struct V_5 * V_6 ,
T_2 V_28 ,
unsigned char * V_8 )
{
T_2 V_29 = 20480 ;
T_2 V_30 , V_31 ;
switch ( V_28 ) {
case 6000000 :
V_30 = 6 ;
break;
case 7000000 :
V_30 = 7 ;
break;
case 8000000 :
default:
V_30 = 8 ;
break;
}
if ( V_6 -> V_12 . V_29 )
V_29 = V_6 -> V_12 . V_29 ;
V_31 = 64 * V_30 * ( 1 << 16 ) / ( 7 * 8 ) ;
V_31 = V_31 * 1000 / V_29 ;
F_8 ( L_3 ,
V_25 , V_30 , V_29 , V_31 ) ;
V_8 [ 0 ] = F_9 ( V_31 ) ;
V_8 [ 1 ] = F_10 ( V_31 ) ;
}
static void F_11 ( struct V_5 * V_6 ,
unsigned char * V_8 )
{
int V_29 = 20480 ;
int V_32 = 36167 ;
int V_33 , V_31 ;
if ( V_6 -> V_12 . V_29 )
V_29 = V_6 -> V_12 . V_29 ;
if ( V_6 -> V_12 . V_32 )
V_32 = V_6 -> V_12 . V_32 ;
if ( V_29 >= V_32 * 2 )
V_33 = V_32 ;
else {
V_33 = V_29 - ( V_32 % V_29 ) ;
if ( V_33 > V_29 / 2 )
V_33 = V_29 - V_33 ;
}
V_31 = - 16374 * V_33 / V_29 ;
F_8 ( L_4 ,
V_25 , V_32 , V_33 , V_29 , V_31 , V_31 & 0x3fff ) ;
V_8 [ 0 ] = F_9 ( V_31 ) ;
V_8 [ 1 ] = F_10 ( V_31 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = & V_2 -> V_36 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned char V_8 [ 13 ] ;
static unsigned char V_37 [] = { 0x5d , 0x01 } ;
static unsigned char V_38 [] = { 0x5e , 0x01 } ;
unsigned int V_39 = 0 ;
switch ( V_35 -> V_40 ) {
case V_41 :
V_39 |= ( 1 << 7 ) ;
break;
case V_42 :
V_39 |= ( 2 << 7 ) ;
break;
case V_43 :
V_39 |= ( 3 << 7 ) ;
break;
case V_44 :
V_39 |= ( 4 << 7 ) ;
break;
case V_45 :
case V_46 :
break;
default:
return - V_47 ;
}
switch ( V_35 -> V_48 ) {
case V_41 :
V_39 |= ( 1 << 4 ) ;
break;
case V_42 :
V_39 |= ( 2 << 4 ) ;
break;
case V_43 :
V_39 |= ( 3 << 4 ) ;
break;
case V_44 :
V_39 |= ( 4 << 4 ) ;
break;
case V_45 :
case V_46 :
break;
case V_49 :
if ( V_35 -> V_50 == V_51 ||
V_35 -> V_50 == V_52 )
break;
default:
return - V_47 ;
}
switch ( V_35 -> V_53 ) {
case V_54 :
break;
case V_55 :
case V_56 :
V_39 |= ( 1 << 13 ) ;
break;
case V_57 :
V_39 |= ( 2 << 13 ) ;
break;
default:
return - V_47 ;
}
switch ( V_35 -> V_58 ) {
case V_59 :
case V_60 :
break;
case V_61 :
V_39 |= ( 1 << 0 ) ;
break;
default:
return - V_47 ;
}
switch ( V_35 -> V_62 ) {
case V_63 :
case V_64 :
break;
case V_65 :
V_39 |= ( 1 << 2 ) ;
break;
case V_66 :
V_39 |= ( 2 << 2 ) ;
break;
case V_67 :
V_39 |= ( 3 << 2 ) ;
break;
default:
return - V_47 ;
}
switch ( V_35 -> V_50 ) {
case V_51 :
case V_52 :
break;
case V_68 :
V_39 |= ( 1 << 10 ) ;
break;
case V_69 :
V_39 |= ( 2 << 10 ) ;
break;
case V_70 :
V_39 |= ( 3 << 10 ) ;
break;
default:
return - V_47 ;
}
V_8 [ 0 ] = V_71 ;
V_8 [ 1 ] = F_9 ( V_39 ) ;
V_8 [ 2 ] = F_10 ( V_39 ) ;
V_8 [ 3 ] = 0x50 ;
F_7 ( V_6 , V_35 -> V_72 , V_8 + 4 ) ;
F_11 ( V_6 , V_8 + 6 ) ;
if ( V_6 -> V_12 . V_73 ) {
if ( V_2 -> V_74 . V_75 . V_76 ) {
V_2 -> V_74 . V_75 . V_76 ( V_2 ) ;
if ( V_2 -> V_74 . V_77 )
V_2 -> V_74 . V_77 ( V_2 , 0 ) ;
}
F_4 ( V_2 , V_8 , 8 ) ;
F_4 ( V_2 , V_38 , 2 ) ;
} else {
if ( V_2 -> V_74 . V_75 . V_78 ) {
V_2 -> V_74 . V_75 . V_78 ( V_2 , V_8 + 8 , 5 ) ;
V_8 [ 8 ] <<= 1 ;
F_4 ( V_2 , V_8 , sizeof( V_8 ) ) ;
F_4 ( V_2 , V_37 , 2 ) ;
}
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_39 ;
T_3 div ;
T_1 V_79 ;
static const T_1 V_80 [ 8 ] =
{
V_45 ,
V_41 ,
V_42 ,
V_43 ,
V_44 ,
V_46 ,
V_46 ,
V_46
} ;
if ( ( F_5 ( V_6 , 0x00 ) & 0xC0 ) != 0xC0 )
return - V_47 ;
V_39 = ( F_5 ( V_6 , V_81 ) << 8 ) | F_5 ( V_6 , V_82 ) ;
div = ( F_5 ( V_6 , V_83 ) << 8 ) | F_5 ( V_6 , V_84 ) ;
V_79 = F_5 ( V_6 , V_85 ) ;
V_35 -> V_40 = V_80 [ ( V_39 >> 7 ) & 7 ] ;
V_35 -> V_48 = V_80 [ ( V_39 >> 4 ) & 7 ] ;
switch ( ( V_39 >> 13 ) & 3 )
{
case 0 :
V_35 -> V_53 = V_54 ;
break;
case 1 :
V_35 -> V_53 = V_56 ;
break;
case 2 :
V_35 -> V_53 = V_57 ;
break;
default:
V_35 -> V_53 = V_55 ;
break;
}
V_35 -> V_58 = ( V_39 & 0x01 ) ? V_61 : V_59 ;
switch ( ( V_39 >> 2 ) & 3 )
{
case 0 :
V_35 -> V_62 = V_63 ;
break;
case 1 :
V_35 -> V_62 = V_65 ;
break;
case 2 :
V_35 -> V_62 = V_66 ;
break;
case 3 :
V_35 -> V_62 = V_67 ;
break;
default:
V_35 -> V_62 = V_64 ;
break;
}
switch ( ( V_39 >> 10 ) & 7 )
{
case 0 :
V_35 -> V_50 = V_52 ;
break;
case 1 :
V_35 -> V_50 = V_68 ;
break;
case 2 :
V_35 -> V_50 = V_69 ;
break;
case 3 :
V_35 -> V_50 = V_70 ;
break;
default:
V_35 -> V_50 = V_51 ;
break;
}
V_35 -> V_86 = ( 500 * ( div - V_87 ) ) / 3 * 1000 ;
if ( V_79 == 0x72 )
V_35 -> V_72 = 8000000 ;
else if ( V_79 == 0x64 )
V_35 -> V_72 = 7000000 ;
else
V_35 -> V_72 = 6000000 ;
if ( F_5 ( V_6 , V_88 ) & 0x02 )
V_35 -> V_89 = V_90 ;
else
V_35 -> V_89 = V_91 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , enum V_92 * V_93 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_94 , V_95 , V_96 ;
if ( ( V_94 = F_5 ( V_6 , V_97 ) ) < 0 )
return - V_98 ;
if ( ( V_95 = F_5 ( V_6 , V_99 ) ) < 0 )
return - V_98 ;
if ( ( V_96 = F_5 ( V_6 , V_100 ) ) < 0 )
return - V_98 ;
* V_93 = 0 ;
if ( V_94 & ( 1 << 4 ) )
* V_93 |= V_101 ;
if ( V_94 & ( 1 << 1 ) )
* V_93 |= V_102 ;
if ( V_94 & ( 1 << 5 ) )
* V_93 |= V_103 ;
if ( V_95 & ( 1 << 1 ) )
* V_93 |= V_104 ;
if ( V_96 & ( 1 << 6 ) )
* V_93 |= V_105 ;
if ( ( * V_93 & ( V_101 | V_102 | V_104 ) ) !=
( V_101 | V_102 | V_104 ) )
* V_93 &= ~ V_103 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 * V_106 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_106 = ( F_5 ( V_6 , V_107 ) << 16 ) |
( F_5 ( V_6 , V_108 ) << 8 ) |
( F_5 ( V_6 , V_109 ) ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_3 * V_110 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 signal = ( ( F_5 ( V_6 , V_111 ) & 0x0f ) << 12 ) |
( F_5 ( V_6 , V_112 ) << 4 ) ;
* V_110 = ~ signal ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 * V_113 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_114 = F_5 ( V_6 , V_115 ) ;
* V_113 = ( V_114 << 8 ) | V_114 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 * V_116 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_116 = ( F_5 ( V_6 , V_117 ) << 8 ) |
( F_5 ( V_6 , V_118 ) ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_119 * V_120 )
{
V_120 -> V_121 = 800 ;
V_120 -> V_122 = 0 ;
V_120 -> V_123 = 0 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
static T_1 V_124 [] = { V_125 , 0xC0 } ;
F_8 ( L_5 , V_25 ) ;
if ( ( F_5 ( V_6 , V_27 ) & 0x10 ) == 0 ||
( F_5 ( V_6 , V_126 ) & 0x20 ) == 0 ) {
F_4 ( V_2 , V_124 , sizeof( V_124 ) ) ;
return V_6 -> V_12 . V_127 ( V_2 ) ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_22 ( V_6 ) ;
}
struct V_1 * F_23 ( const struct V_128 * V_12 ,
struct V_129 * V_17 )
{
struct V_5 * V_6 = NULL ;
V_6 = F_24 ( sizeof( struct V_5 ) , V_130 ) ;
if ( V_6 == NULL ) goto error;
V_6 -> V_17 = V_17 ;
memcpy ( & V_6 -> V_12 , V_12 , sizeof( struct V_128 ) ) ;
if ( F_5 ( V_6 , V_131 ) != V_132 ) goto error;
memcpy ( & V_6 -> V_133 . V_74 , & V_134 , sizeof( struct V_135 ) ) ;
V_6 -> V_133 . V_7 = V_6 ;
return & V_6 -> V_133 ;
error:
F_22 ( V_6 ) ;
return NULL ;
}
