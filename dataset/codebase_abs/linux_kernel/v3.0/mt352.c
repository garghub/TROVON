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
enum V_28 V_29 ,
unsigned char * V_8 )
{
T_2 V_30 = 20480 ;
T_2 V_31 , V_32 ;
switch ( V_29 ) {
case V_33 :
V_31 = 6 ;
break;
case V_34 :
V_31 = 7 ;
break;
case V_35 :
default:
V_31 = 8 ;
break;
}
if ( V_6 -> V_12 . V_30 )
V_30 = V_6 -> V_12 . V_30 ;
V_32 = 64 * V_31 * ( 1 << 16 ) / ( 7 * 8 ) ;
V_32 = V_32 * 1000 / V_30 ;
F_8 ( L_3 ,
V_25 , V_31 , V_30 , V_32 ) ;
V_8 [ 0 ] = F_9 ( V_32 ) ;
V_8 [ 1 ] = F_10 ( V_32 ) ;
}
static void F_11 ( struct V_5 * V_6 ,
unsigned char * V_8 )
{
int V_30 = 20480 ;
int V_36 = 36167 ;
int V_37 , V_32 ;
if ( V_6 -> V_12 . V_30 )
V_30 = V_6 -> V_12 . V_30 ;
if ( V_6 -> V_12 . V_36 )
V_36 = V_6 -> V_12 . V_36 ;
if ( V_30 >= V_36 * 2 )
V_37 = V_36 ;
else {
V_37 = V_30 - ( V_36 % V_30 ) ;
if ( V_37 > V_30 / 2 )
V_37 = V_30 - V_37 ;
}
V_32 = - 16374 * V_37 / V_30 ;
F_8 ( L_4 ,
V_25 , V_36 , V_37 , V_30 , V_32 , V_32 & 0x3fff ) ;
V_8 [ 0 ] = F_9 ( V_32 ) ;
V_8 [ 1 ] = F_10 ( V_32 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned char V_8 [ 13 ] ;
static unsigned char V_40 [] = { 0x5d , 0x01 } ;
static unsigned char V_41 [] = { 0x5e , 0x01 } ;
unsigned int V_42 = 0 ;
struct V_43 * V_44 = & V_39 -> V_45 . V_46 ;
switch ( V_44 -> V_47 ) {
case V_48 :
V_42 |= ( 1 << 7 ) ;
break;
case V_49 :
V_42 |= ( 2 << 7 ) ;
break;
case V_50 :
V_42 |= ( 3 << 7 ) ;
break;
case V_51 :
V_42 |= ( 4 << 7 ) ;
break;
case V_52 :
case V_53 :
break;
default:
return - V_54 ;
}
switch ( V_44 -> V_55 ) {
case V_48 :
V_42 |= ( 1 << 4 ) ;
break;
case V_49 :
V_42 |= ( 2 << 4 ) ;
break;
case V_50 :
V_42 |= ( 3 << 4 ) ;
break;
case V_51 :
V_42 |= ( 4 << 4 ) ;
break;
case V_52 :
case V_53 :
break;
case V_56 :
if ( V_44 -> V_57 == V_58 ||
V_44 -> V_57 == V_59 )
break;
default:
return - V_54 ;
}
switch ( V_44 -> V_60 ) {
case V_61 :
break;
case V_62 :
case V_63 :
V_42 |= ( 1 << 13 ) ;
break;
case V_64 :
V_42 |= ( 2 << 13 ) ;
break;
default:
return - V_54 ;
}
switch ( V_44 -> V_65 ) {
case V_66 :
case V_67 :
break;
case V_68 :
V_42 |= ( 1 << 0 ) ;
break;
default:
return - V_54 ;
}
switch ( V_44 -> V_69 ) {
case V_70 :
case V_71 :
break;
case V_72 :
V_42 |= ( 1 << 2 ) ;
break;
case V_73 :
V_42 |= ( 2 << 2 ) ;
break;
case V_74 :
V_42 |= ( 3 << 2 ) ;
break;
default:
return - V_54 ;
}
switch ( V_44 -> V_57 ) {
case V_58 :
case V_59 :
break;
case V_75 :
V_42 |= ( 1 << 10 ) ;
break;
case V_76 :
V_42 |= ( 2 << 10 ) ;
break;
case V_77 :
V_42 |= ( 3 << 10 ) ;
break;
default:
return - V_54 ;
}
V_8 [ 0 ] = V_78 ;
V_8 [ 1 ] = F_9 ( V_42 ) ;
V_8 [ 2 ] = F_10 ( V_42 ) ;
V_8 [ 3 ] = 0x50 ;
F_7 ( V_6 , V_44 -> V_29 , V_8 + 4 ) ;
F_11 ( V_6 , V_8 + 6 ) ;
if ( V_6 -> V_12 . V_79 ) {
if ( V_2 -> V_80 . V_81 . V_82 ) {
V_2 -> V_80 . V_81 . V_82 ( V_2 , V_39 ) ;
if ( V_2 -> V_80 . V_83 )
V_2 -> V_80 . V_83 ( V_2 , 0 ) ;
}
F_4 ( V_2 , V_8 , 8 ) ;
F_4 ( V_2 , V_41 , 2 ) ;
} else {
if ( V_2 -> V_80 . V_81 . V_84 ) {
V_2 -> V_80 . V_81 . V_84 ( V_2 , V_39 , V_8 + 8 , 5 ) ;
V_8 [ 8 ] <<= 1 ;
F_4 ( V_2 , V_8 , sizeof( V_8 ) ) ;
F_4 ( V_2 , V_40 , 2 ) ;
}
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_42 ;
T_3 div ;
T_1 V_85 ;
struct V_43 * V_44 = & V_39 -> V_45 . V_46 ;
static const T_1 V_86 [ 8 ] =
{
V_52 ,
V_48 ,
V_49 ,
V_50 ,
V_51 ,
V_53 ,
V_53 ,
V_53
} ;
if ( ( F_5 ( V_6 , 0x00 ) & 0xC0 ) != 0xC0 )
return - V_54 ;
V_42 = ( F_5 ( V_6 , V_87 ) << 8 ) | F_5 ( V_6 , V_88 ) ;
div = ( F_5 ( V_6 , V_89 ) << 8 ) | F_5 ( V_6 , V_90 ) ;
V_85 = F_5 ( V_6 , V_91 ) ;
V_44 -> V_47 = V_86 [ ( V_42 >> 7 ) & 7 ] ;
V_44 -> V_55 = V_86 [ ( V_42 >> 4 ) & 7 ] ;
switch ( ( V_42 >> 13 ) & 3 )
{
case 0 :
V_44 -> V_60 = V_61 ;
break;
case 1 :
V_44 -> V_60 = V_63 ;
break;
case 2 :
V_44 -> V_60 = V_64 ;
break;
default:
V_44 -> V_60 = V_62 ;
break;
}
V_44 -> V_65 = ( V_42 & 0x01 ) ? V_68 : V_66 ;
switch ( ( V_42 >> 2 ) & 3 )
{
case 0 :
V_44 -> V_69 = V_70 ;
break;
case 1 :
V_44 -> V_69 = V_72 ;
break;
case 2 :
V_44 -> V_69 = V_73 ;
break;
case 3 :
V_44 -> V_69 = V_74 ;
break;
default:
V_44 -> V_69 = V_71 ;
break;
}
switch ( ( V_42 >> 10 ) & 7 )
{
case 0 :
V_44 -> V_57 = V_59 ;
break;
case 1 :
V_44 -> V_57 = V_75 ;
break;
case 2 :
V_44 -> V_57 = V_76 ;
break;
case 3 :
V_44 -> V_57 = V_77 ;
break;
default:
V_44 -> V_57 = V_58 ;
break;
}
V_39 -> V_92 = ( 500 * ( div - V_93 ) ) / 3 * 1000 ;
if ( V_85 == 0x72 )
V_44 -> V_29 = V_35 ;
else if ( V_85 == 0x64 )
V_44 -> V_29 = V_34 ;
else
V_44 -> V_29 = V_33 ;
if ( F_5 ( V_6 , V_94 ) & 0x02 )
V_39 -> V_95 = V_96 ;
else
V_39 -> V_95 = V_97 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_4 * V_98 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_99 , V_100 , V_101 ;
if ( ( V_99 = F_5 ( V_6 , V_102 ) ) < 0 )
return - V_103 ;
if ( ( V_100 = F_5 ( V_6 , V_104 ) ) < 0 )
return - V_103 ;
if ( ( V_101 = F_5 ( V_6 , V_105 ) ) < 0 )
return - V_103 ;
* V_98 = 0 ;
if ( V_99 & ( 1 << 4 ) )
* V_98 |= V_106 ;
if ( V_99 & ( 1 << 1 ) )
* V_98 |= V_107 ;
if ( V_99 & ( 1 << 5 ) )
* V_98 |= V_108 ;
if ( V_100 & ( 1 << 1 ) )
* V_98 |= V_109 ;
if ( V_101 & ( 1 << 6 ) )
* V_98 |= V_110 ;
if ( ( * V_98 & ( V_106 | V_107 | V_109 ) ) !=
( V_106 | V_107 | V_109 ) )
* V_98 &= ~ V_108 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 * V_111 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_111 = ( F_5 ( V_6 , V_112 ) << 16 ) |
( F_5 ( V_6 , V_113 ) << 8 ) |
( F_5 ( V_6 , V_114 ) ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_3 * V_115 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 signal = ( ( F_5 ( V_6 , V_116 ) & 0x0f ) << 12 ) |
( F_5 ( V_6 , V_117 ) << 4 ) ;
* V_115 = ~ signal ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 * V_118 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_119 = F_5 ( V_6 , V_120 ) ;
* V_118 = ( V_119 << 8 ) | V_119 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 * V_121 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_121 = ( F_5 ( V_6 , V_122 ) << 8 ) |
( F_5 ( V_6 , V_123 ) ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
V_125 -> V_126 = 800 ;
V_125 -> V_127 = 0 ;
V_125 -> V_128 = 0 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
static T_1 V_129 [] = { V_130 , 0xC0 } ;
F_8 ( L_5 , V_25 ) ;
if ( ( F_5 ( V_6 , V_27 ) & 0x10 ) == 0 ||
( F_5 ( V_6 , V_131 ) & 0x20 ) == 0 ) {
F_4 ( V_2 , V_129 , sizeof( V_129 ) ) ;
return V_6 -> V_12 . V_132 ( V_2 ) ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_22 ( V_6 ) ;
}
struct V_1 * F_23 ( const struct V_133 * V_12 ,
struct V_134 * V_17 )
{
struct V_5 * V_6 = NULL ;
V_6 = F_24 ( sizeof( struct V_5 ) , V_135 ) ;
if ( V_6 == NULL ) goto error;
V_6 -> V_17 = V_17 ;
memcpy ( & V_6 -> V_12 , V_12 , sizeof( struct V_133 ) ) ;
if ( F_5 ( V_6 , V_136 ) != V_137 ) goto error;
memcpy ( & V_6 -> V_138 . V_80 , & V_139 , sizeof( struct V_140 ) ) ;
V_6 -> V_138 . V_7 = V_6 ;
return & V_6 -> V_138 ;
error:
F_22 ( V_6 ) ;
return NULL ;
}
