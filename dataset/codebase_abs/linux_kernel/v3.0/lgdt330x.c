static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 ,
int V_4 )
{
struct V_5 V_6 =
{ . V_7 = V_2 -> V_8 -> V_9 ,
. V_10 = 0 ,
. V_3 = V_3 ,
. V_4 = 2 } ;
int V_11 ;
int V_12 ;
for ( V_11 = 0 ; V_11 < V_4 - 1 ; V_11 += 2 ) {
if ( ( V_12 = F_2 ( V_2 -> V_13 , & V_6 , 1 ) ) != 1 ) {
F_3 ( V_14 L_1 , V_15 , V_6 . V_3 [ 0 ] , V_6 . V_3 [ 1 ] , V_12 ) ;
if ( V_12 < 0 )
return V_12 ;
else
return - V_16 ;
}
V_6 . V_3 += 2 ;
}
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
enum V_17 V_18 , T_1 * V_3 , int V_4 )
{
T_1 V_19 [] = { V_18 } ;
struct V_5 V_6 [] = {
{ . V_7 = V_2 -> V_8 -> V_9 ,
. V_10 = 0 , . V_3 = V_19 , . V_4 = 1 } ,
{ . V_7 = V_2 -> V_8 -> V_9 ,
. V_10 = V_20 , . V_3 = V_3 , . V_4 = V_4 } ,
} ;
int V_21 ;
V_21 = F_2 ( V_2 -> V_13 , V_6 , 2 ) ;
if ( V_21 != 2 ) {
F_3 ( V_14 L_2 , V_15 , V_2 -> V_8 -> V_9 , V_18 , V_21 ) ;
} else {
V_21 = 0 ;
}
return V_21 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_21 ;
T_1 V_22 [] = {
V_23 ,
0x00
} ;
V_21 = F_1 ( V_2 ,
V_22 , sizeof( V_22 ) ) ;
if ( V_21 == 0 ) {
V_22 [ 1 ] = 0x7f ;
V_21 = F_1 ( V_2 ,
V_22 , sizeof( V_22 ) ) ;
}
return V_21 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_21 ;
T_1 V_22 [] = {
0x02 ,
0x00
} ;
V_21 = F_1 ( V_2 ,
V_22 , sizeof( V_22 ) ) ;
if ( V_21 == 0 ) {
V_22 [ 1 ] = 0x01 ;
V_21 = F_1 ( V_2 ,
V_22 , sizeof( V_22 ) ) ;
}
return V_21 ;
}
static int F_7 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 -> V_24 ) {
case V_25 :
return F_5 ( V_2 ) ;
case V_26 :
return F_6 ( V_2 ) ;
default:
return - V_27 ;
}
}
static int F_8 ( struct V_28 * V_29 )
{
static T_1 V_30 [] = {
V_31 , 0x00 ,
V_32 , 0x87 ,
V_33 , 0x8e ,
V_34 , 0x01 ,
V_35 , 0xfb ,
V_36 , 0x40 ,
V_37 , 0x93 ,
V_38 , 0x00 ,
V_39 , 0xc6 ,
V_40 , 0x40 ,
V_41 , 0x07 ,
V_42 , 0xfe ,
V_43 , 0x08 ,
V_44 , 0x9a
} ;
static T_1 V_45 [] = {
0x4c , 0x14
} ;
static T_1 V_46 [] = {
0x4c , 0x14 ,
0x87 , 0xf3
} ;
static T_1 V_47 [] = {
0x4c , 0x14 ,
0x87 , 0xda
} ;
struct V_1 * V_2 = V_29 -> V_48 ;
char * V_49 ;
int V_12 ;
switch ( V_2 -> V_8 -> V_24 ) {
case V_25 :
V_49 = L_3 ;
V_12 = F_1 ( V_2 , V_30 ,
sizeof( V_30 ) ) ;
break;
case V_26 :
V_49 = L_4 ;
switch ( V_2 -> V_8 -> V_50 ) {
case 2 :
V_12 = F_1 ( V_2 ,
V_47 ,
sizeof( V_47 ) ) ;
break;
case 1 :
V_12 = F_1 ( V_2 ,
V_46 ,
sizeof( V_46 ) ) ;
break;
case 0 :
default:
V_12 = F_1 ( V_2 , V_45 ,
sizeof( V_45 ) ) ;
}
break;
default:
V_49 = L_5 ;
F_3 ( V_14 L_6 ) ;
V_12 = - V_27 ;
}
F_9 ( L_7 , V_15 , V_49 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_7 ( V_2 ) ;
}
static int F_10 ( struct V_28 * V_29 , T_2 * V_51 )
{
* V_51 = 0 ;
return 0 ;
}
static int F_11 ( struct V_28 * V_29 , T_2 * V_52 )
{
struct V_1 * V_2 = V_29 -> V_48 ;
int V_12 ;
T_1 V_3 [ 2 ] ;
switch ( V_2 -> V_8 -> V_24 ) {
case V_25 :
V_12 = F_4 ( V_2 , V_53 ,
V_3 , sizeof( V_3 ) ) ;
break;
case V_26 :
V_12 = F_4 ( V_2 , V_54 ,
V_3 , sizeof( V_3 ) ) ;
break;
default:
F_3 ( V_14
L_6 ) ;
V_12 = - V_27 ;
}
* V_52 = ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ;
return 0 ;
}
static int F_12 ( struct V_28 * V_29 ,
struct V_55 * V_56 )
{
static T_1 V_57 [] = {
0x04 , 0x00 ,
0x0d , 0x40 ,
0x0e , 0x87 ,
0x0f , 0x8e ,
0x10 , 0x01 ,
0x47 , 0x8b } ;
static T_1 V_58 [] = {
0x04 , 0x00 ,
0x0d , 0x00 ,
0x0e , 0x00 ,
0x0f , 0x00 ,
0x10 , 0x00 ,
0x51 , 0x63 ,
0x47 , 0x66 ,
0x48 , 0x66 ,
0x4d , 0x1a ,
0x49 , 0x08 ,
0x4a , 0x9b } ;
struct V_1 * V_2 = V_29 -> V_48 ;
static T_1 V_59 [] = { V_60 , 0x03 } ;
int V_12 ;
if ( V_2 -> V_61 != V_56 -> V_62 . V_63 . V_64 ) {
switch( V_56 -> V_62 . V_63 . V_64 ) {
case V_65 :
F_9 ( L_8 , V_15 ) ;
V_59 [ 1 ] = 0x03 ;
if ( V_2 -> V_8 -> V_66 )
V_2 -> V_8 -> V_66 ( V_29 , 1 ) ;
if ( V_2 -> V_8 -> V_24 == V_26 ) {
V_12 = F_1 ( V_2 , V_57 ,
sizeof( V_57 ) ) ;
}
break;
case V_67 :
F_9 ( L_9 , V_15 ) ;
V_59 [ 1 ] = 0x00 ;
if ( V_2 -> V_8 -> V_66 )
V_2 -> V_8 -> V_66 ( V_29 , 0 ) ;
if ( V_2 -> V_8 -> V_24 == V_26 ) {
V_12 = F_1 ( V_2 , V_58 ,
sizeof( V_58 ) ) ;
}
break;
case V_68 :
F_9 ( L_10 , V_15 ) ;
V_59 [ 1 ] = 0x01 ;
if ( V_2 -> V_8 -> V_66 )
V_2 -> V_8 -> V_66 ( V_29 , 0 ) ;
if ( V_2 -> V_8 -> V_24 == V_26 ) {
V_12 = F_1 ( V_2 , V_58 ,
sizeof( V_58 ) ) ;
}
break;
default:
F_3 ( V_14 L_11 , V_15 , V_56 -> V_62 . V_63 . V_64 ) ;
return - 1 ;
}
V_59 [ 1 ] |= V_2 -> V_8 -> V_69 ;
F_1 ( V_2 , V_59 ,
sizeof( V_59 ) ) ;
if ( V_2 -> V_8 -> V_70 )
V_2 -> V_8 -> V_70 ( V_29 , 0 ) ;
V_2 -> V_61 = V_56 -> V_62 . V_63 . V_64 ;
}
if ( V_29 -> V_71 . V_72 . V_73 ) {
V_29 -> V_71 . V_72 . V_73 ( V_29 , V_56 ) ;
if ( V_29 -> V_71 . V_74 ) V_29 -> V_71 . V_74 ( V_29 , 0 ) ;
}
V_2 -> V_75 = V_56 -> V_76 ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_28 * V_29 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = V_29 -> V_48 ;
V_56 -> V_76 = V_2 -> V_75 ;
return 0 ;
}
static int F_14 ( struct V_28 * V_29 , T_3 * V_77 )
{
struct V_1 * V_2 = V_29 -> V_48 ;
T_1 V_3 [ 3 ] ;
* V_77 = 0 ;
F_4 ( V_2 , V_78 , V_3 , 1 ) ;
F_9 ( L_12 , V_15 , V_3 [ 0 ] ) ;
if ( ( V_3 [ 0 ] & 0x0c ) == 0x8 ) {
* V_77 |= V_79 ;
}
F_4 ( V_2 , V_60 , V_3 , sizeof( V_3 ) ) ;
F_9 ( L_13 , V_15 , V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
if ( ( V_3 [ 2 ] & 0x03 ) == 0x01 ) {
* V_77 |= V_80 ;
}
if ( ( V_3 [ 2 ] & 0x0c ) == 0x08 ) {
* V_77 |= V_81 ;
* V_77 |= V_82 ;
}
F_4 ( V_2 , V_83 , V_3 , 1 ) ;
F_9 ( L_14 , V_15 , V_3 [ 0 ] ) ;
switch ( V_2 -> V_61 ) {
case V_68 :
case V_67 :
if ( ( V_3 [ 0 ] & 0x07 ) == 0x07 )
* V_77 |= V_84 ;
break;
case V_65 :
if ( ( V_3 [ 0 ] & 0x80 ) == 0x80 )
* V_77 |= V_84 ;
break;
default:
F_3 ( V_14 L_15 , V_15 ) ;
}
return 0 ;
}
static int F_15 ( struct V_28 * V_29 , T_3 * V_77 )
{
struct V_1 * V_2 = V_29 -> V_48 ;
int V_12 ;
T_1 V_3 [ 3 ] ;
* V_77 = 0 ;
V_12 = F_4 ( V_2 , 0x58 , V_3 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
F_9 ( L_12 , V_15 , V_3 [ 0 ] ) ;
if ( ( V_3 [ 0 ] & 0x21 ) == 0x01 ) {
* V_77 |= V_79 ;
}
F_4 ( V_2 , V_83 , V_3 , 1 ) ;
F_9 ( L_14 , V_15 , V_3 [ 0 ] ) ;
switch ( V_2 -> V_61 ) {
case V_68 :
case V_67 :
if ( ( V_3 [ 0 ] & 0x07 ) == 0x07 )
* V_77 |= V_84 ;
else
break;
F_4 ( V_2 , 0x8a , V_3 , 1 ) ;
if ( ( V_3 [ 0 ] & 0x04 ) == 0x04 )
* V_77 |= V_80 ;
if ( ( V_3 [ 0 ] & 0x01 ) == 0x01 )
* V_77 |= V_81 ;
if ( ( V_3 [ 0 ] & 0x08 ) == 0x08 )
* V_77 |= V_82 ;
break;
case V_65 :
if ( ( V_3 [ 0 ] & 0x80 ) == 0x80 )
* V_77 |= V_84 ;
else
break;
F_4 ( V_2 , 0x38 , V_3 , 1 ) ;
if ( ( V_3 [ 0 ] & 0x02 ) == 0x00 )
* V_77 |= V_80 ;
if ( ( V_3 [ 0 ] & 0x01 ) == 0x01 ) {
* V_77 |= V_81 ;
* V_77 |= V_82 ;
}
break;
default:
F_3 ( V_14 L_15 , V_15 ) ;
}
return 0 ;
}
static T_2 F_16 ( T_2 V_85 , T_2 V_86 )
{
if ( V_85 == 0 )
return 0 ;
V_85 = F_17 ( V_85 ) ;
if ( V_85 > V_86 ) {
return 0 ;
}
return 10 * ( V_86 - V_85 ) ;
}
static int F_18 ( struct V_28 * V_29 , T_4 * V_87 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 -> V_48 ;
T_1 V_3 [ 5 ] ;
T_2 V_88 ;
T_2 V_86 ;
switch( V_2 -> V_61 ) {
case V_65 :
F_4 ( V_2 , V_89 , V_3 , 5 ) ;
#ifdef F_19
V_88 = ( ( V_3 [ 0 ] & 7 ) << 16 ) | ( V_3 [ 1 ] << 8 ) | V_3 [ 2 ] ;
V_86 = 69765745 ;
#else
V_88 = ( ( V_3 [ 0 ] & 7 << 3 ) << 13 ) | ( V_3 [ 3 ] << 8 ) | V_3 [ 4 ] ;
V_86 = 73957994 ;
#endif
break;
case V_67 :
case V_68 :
F_4 ( V_2 , V_90 , V_3 , 2 ) ;
V_88 = ( ( V_3 [ 0 ] & 3 ) << 8 ) | V_3 [ 1 ] ;
V_86 = V_2 -> V_61 == V_67 ? 97939837 : 98026066 ;
break;
default:
F_3 ( V_91 L_15 ,
V_15 ) ;
return - V_16 ;
}
V_2 -> V_87 = F_16 ( V_88 , V_86 ) ;
* V_87 = ( V_2 -> V_87 ) >> 16 ;
F_9 ( L_16 , V_15 , V_88 ,
V_2 -> V_87 >> 24 , ( ( ( V_2 -> V_87 >> 8 ) & 0xffff ) * 100 ) >> 16 ) ;
return 0 ;
}
static int F_20 ( struct V_28 * V_29 , T_4 * V_87 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 -> V_48 ;
T_1 V_3 [ 5 ] ;
T_2 V_88 ;
T_2 V_86 ;
switch( V_2 -> V_61 ) {
case V_65 :
F_4 ( V_2 , V_92 , V_3 , 5 ) ;
#ifdef F_19
V_88 = ( ( V_3 [ 0 ] & 0x78 ) << 13 ) | ( V_3 [ 1 ] << 8 ) | V_3 [ 2 ] ;
V_86 = 73957994 ;
#else
V_88 = ( ( V_3 [ 0 ] & 7 ) << 16 ) | ( V_3 [ 3 ] << 8 ) | V_3 [ 4 ] ;
V_86 = 73957994 ;
#endif
break;
case V_67 :
case V_68 :
F_4 ( V_2 , V_90 , V_3 , 2 ) ;
V_88 = ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ;
V_86 = V_2 -> V_61 == V_67 ? 97939837 : 98026066 ;
break;
default:
F_3 ( V_91 L_15 ,
V_15 ) ;
return - V_16 ;
}
V_2 -> V_87 = F_16 ( V_88 , V_86 ) ;
* V_87 = ( V_2 -> V_87 ) >> 16 ;
F_9 ( L_16 , V_15 , V_88 ,
V_2 -> V_87 >> 24 , ( ( ( V_2 -> V_87 >> 8 ) & 0xffff ) * 100 ) >> 16 ) ;
return 0 ;
}
static int F_21 ( struct V_28 * V_29 , T_4 * V_93 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 -> V_48 ;
T_4 V_87 ;
int V_21 ;
V_21 = V_29 -> V_71 . V_94 ( V_29 , & V_87 ) ;
if ( V_21 != 0 )
return V_21 ;
if ( V_2 -> V_87 >= 8960 * 0x10000 )
* V_93 = 0xffff ;
else
* V_93 = V_2 -> V_87 / 8960 ;
return 0 ;
}
static int F_22 ( struct V_28 * V_29 , struct V_95 * V_96 )
{
V_96 -> V_97 = 500 ;
V_96 -> V_98 = 0 ;
V_96 -> V_99 = 0 ;
return 0 ;
}
static void F_23 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 -> V_48 ;
F_24 ( V_2 ) ;
}
struct V_28 * F_25 ( const struct V_100 * V_8 ,
struct V_101 * V_13 )
{
struct V_1 * V_2 = NULL ;
T_1 V_3 [ 1 ] ;
V_2 = F_26 ( sizeof( struct V_1 ) , V_102 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_8 = V_8 ;
V_2 -> V_13 = V_13 ;
switch ( V_8 -> V_24 ) {
case V_25 :
memcpy ( & V_2 -> V_103 . V_71 , & V_104 , sizeof( struct V_105 ) ) ;
break;
case V_26 :
memcpy ( & V_2 -> V_103 . V_71 , & V_106 , sizeof( struct V_105 ) ) ;
break;
default:
goto error;
}
V_2 -> V_103 . V_48 = V_2 ;
if ( F_4 ( V_2 , 2 , V_3 , 1 ) )
goto error;
V_2 -> V_75 = - 1 ;
V_2 -> V_61 = - 1 ;
return & V_2 -> V_103 ;
error:
F_24 ( V_2 ) ;
F_9 ( L_17 , V_15 ) ;
return NULL ;
}
