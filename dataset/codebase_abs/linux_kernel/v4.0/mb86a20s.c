static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_6 [] = { V_4 , V_5 } ;
struct V_7 V_8 = {
. V_9 = V_3 , . V_10 = 0 , . V_6 = V_6 , . V_11 = 2
} ;
int V_12 ;
V_12 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ;
if ( V_12 != 1 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_1 ,
V_15 , V_12 , V_4 , V_5 ) ;
return V_12 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , struct V_16 * V_17 , int V_18 )
{
int V_19 , V_12 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
V_12 = F_1 ( V_2 , V_3 , V_17 [ V_19 ] . V_4 ,
V_17 [ V_19 ] . V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
T_1 V_20 ;
int V_12 ;
struct V_7 V_8 [] = {
{ . V_9 = V_3 , . V_10 = 0 , . V_6 = & V_4 , . V_11 = 1 } ,
{ . V_9 = V_3 , . V_10 = V_21 , . V_6 = & V_20 , . V_11 = 1 }
} ;
V_12 = F_2 ( V_2 -> V_13 , V_8 , 2 ) ;
if ( V_12 != 2 ) {
F_3 ( & V_2 -> V_13 -> V_14 , L_2 ,
V_15 , V_4 , V_12 ) ;
return ( V_12 < 0 ) ? V_12 : - V_22 ;
}
return V_20 ;
}
static int F_6 ( struct V_23 * V_24 , T_2 * V_25 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
int V_20 ;
* V_25 = 0 ;
V_20 = F_7 ( V_2 , 0x0a ) & 0xf ;
if ( V_20 < 0 )
return V_20 ;
if ( V_20 >= 2 )
* V_25 |= V_27 ;
if ( V_20 >= 4 )
* V_25 |= V_28 ;
if ( V_20 >= 5 )
* V_25 |= V_29 ;
if ( V_20 >= 7 )
* V_25 |= V_30 ;
if ( V_20 >= 8 )
* V_25 |= V_31 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_3 ,
V_15 , * V_25 , V_20 ) ;
return V_20 ;
}
static int F_9 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_32 * V_33 = & V_24 -> V_34 ;
int V_12 ;
unsigned V_35 , V_36 , V_37 ;
if ( V_2 -> V_38 &&
( ! F_10 ( V_39 , V_2 -> V_38 ) ) )
return V_33 -> V_40 . V_41 [ 0 ] . V_42 ;
V_33 -> V_40 . V_41 [ 0 ] . V_42 = 0 ;
V_35 = 0xfff ;
V_36 = 0 ;
do {
V_37 = ( V_35 + V_36 ) / 2 ;
V_12 = F_11 ( V_2 , 0x04 , 0x1f ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x05 , V_37 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x04 , 0x20 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x05 , V_37 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x02 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_12 & 0x08 )
V_36 = ( V_35 + V_36 ) / 2 ;
else
V_35 = ( V_35 + V_36 ) / 2 ;
if ( V_35 - V_36 < 4 ) {
V_37 = ( V_35 + V_36 ) / 2 ;
V_37 = V_37 << ( 16 - 12 ) ;
if ( V_37 )
V_37 |= ( 1 << 12 ) - 1 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_4 ,
V_15 , V_37 , V_36 , V_37 >> 4 , V_35 ) ;
V_33 -> V_40 . V_41 [ 0 ] . V_42 = V_37 ;
V_2 -> V_38 = V_39 +
F_12 ( 1000 ) ;
return 0 ;
}
} while ( 1 );
}
static int F_13 ( struct V_1 * V_2 ,
unsigned V_43 )
{
int V_12 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x86 ,
[ 1 ] = 0x8a ,
[ 2 ] = 0x8e ,
} ;
if ( V_43 >= F_14 ( V_4 ) )
return - V_44 ;
V_12 = F_11 ( V_2 , 0x6d , V_4 [ V_43 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( ( V_12 >> 4 ) & 0x07 ) {
case 0 :
return V_45 ;
case 1 :
return V_46 ;
case 2 :
return V_47 ;
case 3 :
return V_48 ;
default:
return V_49 ;
}
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_43 )
{
int V_12 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x87 ,
[ 1 ] = 0x8b ,
[ 2 ] = 0x8f ,
} ;
if ( V_43 >= F_14 ( V_4 ) )
return - V_44 ;
V_12 = F_11 ( V_2 , 0x6d , V_4 [ V_43 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( ( V_12 >> 4 ) & 0x07 ) {
case 0 :
return V_50 ;
case 1 :
return V_51 ;
case 2 :
return V_52 ;
case 3 :
return V_53 ;
case 4 :
return V_54 ;
default:
return V_55 ;
}
}
static int F_16 ( struct V_1 * V_2 ,
unsigned V_43 )
{
int V_12 ;
int V_56 [] = {
0 , 1 , 2 , 4 , 8
} ;
static unsigned char V_4 [] = {
[ 0 ] = 0x88 ,
[ 1 ] = 0x8c ,
[ 2 ] = 0x90 ,
} ;
if ( V_43 >= F_14 ( V_4 ) )
return - V_44 ;
V_12 = F_11 ( V_2 , 0x6d , V_4 [ V_43 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
return V_56 [ ( V_12 >> 4 ) & 0x07 ] ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned V_43 )
{
int V_12 , V_57 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x89 ,
[ 1 ] = 0x8d ,
[ 2 ] = 0x91 ,
} ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_43 >= F_14 ( V_4 ) )
return - V_44 ;
V_12 = F_11 ( V_2 , 0x6d , V_4 [ V_43 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
V_57 = ( V_12 >> 4 ) & 0x0f ;
F_8 ( & V_2 -> V_13 -> V_14 , L_6 , V_15 , V_57 ) ;
return V_57 ;
}
static void F_18 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_32 * V_33 = & V_24 -> V_34 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
V_33 -> V_58 = V_59 ;
V_33 -> V_60 = 6000000 ;
V_33 -> V_61 = 0 ;
V_33 -> V_62 = V_63 ;
V_33 -> V_64 = V_65 ;
V_33 -> V_66 = 0 ;
V_33 -> V_67 = 0 ;
}
static void F_19 ( struct V_23 * V_24 , T_3 V_43 ,
T_3 V_68 , T_3 V_69 ,
T_3 V_64 ,
T_3 V_70 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
T_3 V_71 ;
int V_72 , V_73 , V_74 ;
switch ( V_68 ) {
case V_45 :
case V_46 :
default:
V_72 = 0 ;
break;
case V_47 :
V_72 = 1 ;
break;
case V_48 :
V_72 = 2 ;
break;
}
switch ( V_69 ) {
default:
case V_50 :
case V_55 :
V_73 = 0 ;
break;
case V_51 :
V_73 = 1 ;
break;
case V_52 :
V_73 = 2 ;
break;
case V_53 :
V_73 = 3 ;
break;
case V_54 :
V_73 = 4 ;
break;
}
switch ( V_64 ) {
default:
case V_75 :
V_74 = 0 ;
break;
case V_76 :
V_74 = 1 ;
break;
case V_77 :
V_74 = 2 ;
break;
case V_78 :
V_74 = 3 ;
break;
}
V_71 = V_79 [ V_72 ] [ V_73 ] [ V_74 ] * V_70 * V_80 ;
if ( V_71 < 256 )
V_71 = 256 ;
else if ( V_71 > ( 1 << 24 ) - 1 )
V_71 = ( 1 << 24 ) - 1 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_7 ,
V_15 , 'A' + V_43 ,
V_70 * V_79 [ V_72 ] [ V_73 ] [ V_74 ] / 1000 ,
V_71 , V_71 ) ;
V_2 -> V_81 [ V_43 ] = V_71 ;
}
static int F_20 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_32 * V_33 = & V_24 -> V_34 ;
int V_43 , V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
F_18 ( V_24 ) ;
V_12 = F_11 ( V_2 , 0x6d , 0x85 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
V_33 -> V_82 = ( V_12 & 0x10 ) ? 1 : 0 ;
for ( V_43 = 0 ; V_43 < V_83 ; V_43 ++ ) {
F_8 ( & V_2 -> V_13 -> V_14 , L_8 ,
V_15 , 'A' + V_43 ) ;
V_12 = F_17 ( V_2 , V_43 ) ;
if ( V_12 < 0 )
goto V_84;
if ( V_12 >= 0 && V_12 < 14 ) {
V_33 -> V_43 [ V_43 ] . V_85 = V_12 ;
} else {
V_33 -> V_43 [ V_43 ] . V_85 = 0 ;
V_2 -> V_81 [ V_43 ] = 0 ;
continue;
}
V_33 -> V_61 |= 1 << V_43 ;
V_12 = F_13 ( V_2 , V_43 ) ;
if ( V_12 < 0 )
goto V_84;
F_8 ( & V_2 -> V_13 -> V_14 , L_9 ,
V_15 , V_12 ) ;
V_33 -> V_43 [ V_43 ] . V_68 = V_12 ;
V_12 = F_15 ( V_2 , V_43 ) ;
if ( V_12 < 0 )
goto V_84;
F_8 ( & V_2 -> V_13 -> V_14 , L_10 ,
V_15 , V_12 ) ;
V_33 -> V_43 [ V_43 ] . V_73 = V_12 ;
V_12 = F_16 ( V_2 , V_43 ) ;
if ( V_12 < 0 )
goto V_84;
F_8 ( & V_2 -> V_13 -> V_14 , L_11 ,
V_15 , V_12 ) ;
V_33 -> V_43 [ V_43 ] . V_56 = V_12 ;
F_19 ( V_24 , V_43 , V_33 -> V_43 [ V_43 ] . V_68 ,
V_33 -> V_43 [ V_43 ] . V_73 ,
V_33 -> V_64 ,
V_33 -> V_43 [ V_43 ] . V_85 ) ;
}
V_12 = F_11 ( V_2 , 0x6d , 0x84 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ( V_12 & 0x60 ) == 0x20 ) {
V_33 -> V_66 = 1 ;
if ( ! V_33 -> V_67 )
V_33 -> V_67 = 1 ;
}
V_12 = F_7 ( V_2 , 0x07 ) ;
if ( V_12 < 0 )
return V_12 ;
V_33 -> V_62 = V_63 ;
if ( ( V_12 & 0x60 ) == 0x20 ) {
switch ( ( V_12 >> 2 ) & 0x03 ) {
case 1 :
V_33 -> V_62 = V_86 ;
break;
case 2 :
V_33 -> V_62 = V_87 ;
break;
}
}
V_33 -> V_64 = V_65 ;
if ( ! ( V_12 & 0x10 ) ) {
switch ( V_12 & 0x3 ) {
case 0 :
V_33 -> V_64 = V_75 ;
break;
case 1 :
V_33 -> V_64 = V_76 ;
break;
case 2 :
V_33 -> V_64 = V_77 ;
break;
}
}
return 0 ;
V_84:
V_33 -> V_61 = 0 ;
return V_12 ;
}
static int F_21 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_32 * V_33 = & V_24 -> V_34 ;
int V_12 , V_20 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_2 -> V_88 != V_33 -> V_89 ) {
memset ( & V_33 -> V_90 , 0 , sizeof( V_33 -> V_90 ) ) ;
memset ( & V_33 -> V_91 , 0 , sizeof( V_33 -> V_91 ) ) ;
memset ( & V_33 -> V_92 , 0 , sizeof( V_33 -> V_92 ) ) ;
memset ( & V_33 -> V_93 , 0 , sizeof( V_33 -> V_93 ) ) ;
memset ( & V_33 -> V_94 , 0 , sizeof( V_33 -> V_94 ) ) ;
memset ( & V_33 -> V_95 , 0 , sizeof( V_33 -> V_95 ) ) ;
memset ( & V_33 -> V_96 , 0 , sizeof( V_33 -> V_96 ) ) ;
V_2 -> V_88 = V_33 -> V_89 ;
}
V_12 = F_22 ( V_2 , V_97 ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_7 ( V_2 , 0x45 ) ;
if ( V_12 < 0 )
goto V_98;
V_20 = V_12 ;
V_12 = F_11 ( V_2 , 0x45 , V_20 | 0x10 ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_11 ( V_2 , 0x45 , V_20 & 0x6f ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_11 ( V_2 , 0x50 , 0x50 ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
goto V_98;
V_20 = V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_20 | 0x01 ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_11 ( V_2 , 0x51 , V_20 & 0x06 ) ;
if ( V_12 < 0 )
goto V_98;
goto V_99;
V_98:
F_3 ( & V_2 -> V_13 -> V_14 ,
L_12 ,
V_15 , V_12 ) ;
V_99:
return V_12 ;
}
static int F_23 ( struct V_23 * V_24 ,
unsigned V_43 ,
T_3 * error , T_3 * V_57 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
int V_12 , V_20 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_43 >= V_83 )
return - V_44 ;
V_12 = F_7 ( V_2 , 0x54 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & ( 1 << V_43 ) ) ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_13 ,
V_15 , 'A' + V_43 ) ;
return - V_100 ;
}
V_12 = F_7 ( V_2 , 0x55 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error = V_12 << 16 ;
V_12 = F_7 ( V_2 , 0x56 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 << 8 ;
V_12 = F_7 ( V_2 , 0x57 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_14 ,
V_15 , 'A' + V_43 , * error ) ;
V_12 = F_11 ( V_2 , 0x50 , 0xa7 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_57 = V_12 << 16 ;
V_12 = F_11 ( V_2 , 0x50 , 0xa8 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_57 |= V_12 << 8 ;
V_12 = F_11 ( V_2 , 0x50 , 0xa9 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_57 |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_15 ,
V_15 , 'A' + V_43 , * V_57 ) ;
if ( V_2 -> V_81 [ V_43 ]
&& V_2 -> V_81 [ V_43 ] != * V_57 ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_16 ,
V_15 , 'A' + V_43 , V_2 -> V_81 [ V_43 ] ) ;
V_12 = F_11 ( V_2 , 0x52 , 0x00 ) ;
V_12 = F_11 ( V_2 , 0x50 , 0xa7 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 ,
V_2 -> V_81 [ V_43 ] >> 16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x50 , 0xa8 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 ,
V_2 -> V_81 [ V_43 ] >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x50 , 0xa9 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 ,
V_2 -> V_81 [ V_43 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x52 , 0x01 ) ;
V_12 = F_11 ( V_2 , 0x53 , 0x00 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x53 , 0x07 ) ;
} else {
V_12 = F_7 ( V_2 , 0x53 ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = V_12 ;
V_12 = F_11 ( V_2 , 0x53 , V_20 & ~ ( 1 << V_43 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x53 , V_20 | ( 1 << V_43 ) ) ;
}
return V_12 ;
}
static int F_24 ( struct V_23 * V_24 ,
unsigned V_43 ,
T_3 * error , T_3 * V_57 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
T_3 V_101 , V_102 ;
int V_12 , V_20 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_43 >= V_83 )
return - V_44 ;
V_12 = F_7 ( V_2 , 0x60 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & ( 1 << V_43 ) ) ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_17 ,
V_15 , 'A' + V_43 ) ;
return - V_100 ;
}
V_12 = F_7 ( V_2 , 0x64 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error = V_12 << 16 ;
V_12 = F_7 ( V_2 , 0x65 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 << 8 ;
V_12 = F_7 ( V_2 , 0x66 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_18 ,
V_15 , 'A' + V_43 , * error ) ;
V_12 = F_11 ( V_2 , 0x50 , 0xdc + V_43 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_101 = V_12 << 8 ;
V_12 = F_11 ( V_2 , 0x50 , 0xdd + V_43 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_101 |= V_12 ;
* V_57 = V_101 * 204 * 8 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_19 ,
V_15 , 'A' + V_43 , * V_57 ) ;
if ( ! V_2 -> V_81 [ V_43 ] )
goto V_103;
V_102 = V_2 -> V_81 [ V_43 ] / 204 / 8 ;
if ( V_102 < 32 )
V_102 = 32 ;
if ( V_102 > 65535 )
V_102 = 65535 ;
if ( V_102 != V_101 ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_20 ,
V_15 , 'A' + V_43 , V_102 ) ;
V_12 = F_11 ( V_2 , 0x5e , 0x00 ) ;
V_12 = F_11 ( V_2 , 0x50 , 0xdc + V_43 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_102 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x50 , 0xdd + V_43 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_102 & 0xff ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x5e , 0x07 ) ;
V_12 = F_11 ( V_2 , 0x5f , 0x00 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x5f , 0x07 ) ;
return V_12 ;
}
V_103:
V_12 = F_7 ( V_2 , 0x5f ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = V_12 ;
V_12 = F_11 ( V_2 , 0x5f , V_20 & ~ ( 1 << V_43 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x5f , V_20 | ( 1 << V_43 ) ) ;
return V_12 ;
}
static int F_25 ( struct V_23 * V_24 ,
unsigned V_43 ,
T_3 * error , T_3 * V_57 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
int V_12 , V_20 ;
T_3 V_102 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_43 >= V_83 )
return - V_44 ;
V_12 = F_11 ( V_2 , 0x50 , 0xb8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & ( 1 << V_43 ) ) ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_21 ,
V_15 , 'A' + V_43 ) ;
return - V_100 ;
}
V_12 = F_11 ( V_2 , 0x50 , 0xb9 + V_43 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* error = V_12 << 8 ;
V_12 = F_11 ( V_2 , 0x50 , 0xba + V_43 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_22 ,
V_15 , 'A' + V_43 , * error ) ;
V_12 = F_11 ( V_2 , 0x50 , 0xb2 + V_43 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_57 = V_12 << 8 ;
V_12 = F_11 ( V_2 , 0x50 , 0xb3 + V_43 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_57 |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_23 ,
V_15 , 'A' + V_43 , * V_57 ) ;
if ( ! V_2 -> V_81 [ V_43 ] )
goto V_103;
V_102 = V_2 -> V_81 [ V_43 ] / 204 / 8 ;
if ( V_102 < 32 )
V_102 = 32 ;
if ( V_102 > 65535 )
V_102 = 65535 ;
if ( V_102 != * V_57 ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_24 ,
V_15 , 'A' + V_43 , V_102 ) ;
V_12 = F_11 ( V_2 , 0x50 , 0xb0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , 0x00 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x50 , 0xb2 + V_43 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_102 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x50 , 0xb3 + V_43 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_102 & 0xff ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x50 , 0xb0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , 0x07 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x50 , 0xb1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , 0x07 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , 0x00 ) ;
return V_12 ;
}
V_103:
V_12 = F_11 ( V_2 , 0x50 , 0xb1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_20 | ( 1 << V_43 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_20 & ~ ( 1 << V_43 ) ) ;
return V_12 ;
}
static T_3 F_26 ( T_3 V_104 , const struct V_105 * V_106 ,
unsigned V_11 )
{
T_4 V_107 ;
T_3 V_108 , V_109 ;
int V_19 , V_110 ;
if ( V_104 >= V_106 [ 0 ] . V_111 )
return V_106 [ 0 ] . V_112 ;
if ( V_104 < V_106 [ V_11 - 1 ] . V_111 )
return V_106 [ V_11 - 1 ] . V_112 ;
for ( V_19 = 1 ; V_19 < V_11 - 1 ; V_19 ++ ) {
if ( V_104 == V_106 [ V_19 ] . V_111 )
return V_106 [ V_19 ] . V_112 ;
if ( V_104 > V_106 [ V_19 ] . V_111 )
break;
}
V_109 = V_106 [ V_19 ] . V_112 - V_106 [ V_19 - 1 ] . V_112 ;
V_108 = V_106 [ V_19 - 1 ] . V_111 - V_106 [ V_19 ] . V_111 ;
V_107 = V_104 - V_106 [ V_19 ] . V_111 ;
V_107 *= V_109 ;
F_27 ( V_107 , V_108 ) ;
V_110 = V_106 [ V_19 ] . V_112 - V_107 ;
return V_110 ;
}
static int F_28 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_32 * V_33 = & V_24 -> V_34 ;
T_3 V_113 , V_90 ;
int V_12 , V_20 ;
V_12 = F_7 ( V_2 , 0x45 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & 0x40 ) ) {
F_8 ( & V_2 -> V_13 -> V_14 , L_25 ,
V_15 ) ;
return - V_100 ;
}
V_20 = V_12 ;
V_12 = F_7 ( V_2 , 0x46 ) ;
if ( V_12 < 0 )
return V_12 ;
V_113 = V_12 << 8 ;
V_12 = F_7 ( V_2 , 0x46 ) ;
if ( V_12 < 0 )
return V_12 ;
V_113 |= V_12 ;
V_90 = F_26 ( V_113 ,
V_114 , F_14 ( V_114 ) ) ;
V_33 -> V_90 . V_41 [ 0 ] . V_115 = V_116 ;
V_33 -> V_90 . V_41 [ 0 ] . V_117 = V_90 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_26 ,
V_15 , V_90 / 1000 , V_90 % 1000 , V_113 ) ;
V_12 = F_11 ( V_2 , 0x45 , V_20 | 0x10 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x45 , V_20 & 0x6f ) ;
return V_12 ;
}
static int F_29 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_32 * V_33 = & V_24 -> V_34 ;
T_3 V_118 , V_90 ;
int V_12 , V_20 , V_43 ;
const struct V_105 * V_119 ;
unsigned V_120 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
V_12 = F_11 ( V_2 , 0x50 , 0x5b ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & 0x01 ) ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_27 , V_15 ) ;
return - V_100 ;
}
for ( V_43 = 0 ; V_43 < V_83 ; V_43 ++ ) {
if ( ! ( V_33 -> V_61 & ( 1 << V_43 ) ) ) {
V_33 -> V_90 . V_41 [ 1 + V_43 ] . V_115 = V_121 ;
continue;
}
V_12 = F_11 ( V_2 , 0x50 , 0x52 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_118 = V_12 << 16 ;
V_12 = F_11 ( V_2 , 0x50 , 0x53 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_118 |= V_12 << 8 ;
V_12 = F_11 ( V_2 , 0x50 , 0x54 + V_43 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_118 |= V_12 ;
switch ( V_33 -> V_43 [ V_43 ] . V_68 ) {
case V_45 :
case V_46 :
V_119 = V_122 ;
V_120 = F_14 ( V_122 ) ;
break;
case V_47 :
V_119 = V_123 ;
V_120 = F_14 ( V_123 ) ;
break;
default:
case V_48 :
V_119 = V_124 ;
V_120 = F_14 ( V_124 ) ;
break;
}
V_90 = F_26 ( V_118 , V_119 , V_120 ) ;
V_33 -> V_90 . V_41 [ 1 + V_43 ] . V_115 = V_116 ;
V_33 -> V_90 . V_41 [ 1 + V_43 ] . V_117 = V_90 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_28 ,
V_15 , 'A' + V_43 , V_90 / 1000 , V_90 % 1000 , V_118 ) ;
}
V_12 = F_11 ( V_2 , 0x50 , 0x50 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_20 | 0x01 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_20 & 0x06 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static void F_30 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_32 * V_33 = & V_24 -> V_34 ;
int V_43 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
V_33 -> V_40 . V_11 = 1 ;
V_33 -> V_90 . V_11 = V_83 + 1 ;
V_33 -> V_91 . V_11 = V_83 + 1 ;
V_33 -> V_92 . V_11 = V_83 + 1 ;
V_33 -> V_93 . V_11 = V_83 + 1 ;
V_33 -> V_94 . V_11 = V_83 + 1 ;
V_33 -> V_95 . V_11 = V_83 + 1 ;
V_33 -> V_96 . V_11 = V_83 + 1 ;
V_33 -> V_40 . V_41 [ 0 ] . V_115 = V_125 ;
V_33 -> V_40 . V_41 [ 0 ] . V_42 = 0 ;
for ( V_43 = 0 ; V_43 < V_83 + 1 ; V_43 ++ ) {
V_33 -> V_90 . V_41 [ V_43 ] . V_115 = V_121 ;
V_33 -> V_91 . V_41 [ V_43 ] . V_115 = V_121 ;
V_33 -> V_92 . V_41 [ V_43 ] . V_115 = V_121 ;
V_33 -> V_93 . V_41 [ V_43 ] . V_115 = V_121 ;
V_33 -> V_94 . V_41 [ V_43 ] . V_115 = V_121 ;
V_33 -> V_95 . V_41 [ V_43 ] . V_115 = V_121 ;
V_33 -> V_96 . V_41 [ V_43 ] . V_115 = V_121 ;
}
}
static int F_31 ( struct V_23 * V_24 , int V_126 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_32 * V_33 = & V_24 -> V_34 ;
int V_12 = 0 , V_43 ;
T_3 V_127 = 0 , V_128 = 0 ;
T_3 V_129 = 0 , V_130 = 0 ;
T_3 V_131 = 0 , V_132 = 0 ;
T_3 V_95 = 0 , V_96 = 0 ;
T_3 V_133 = 0 , V_134 = 0 ;
int V_135 = 0 , V_136 = 0 , V_137 = 0 ;
int V_138 = 0 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
F_28 ( V_24 ) ;
F_29 ( V_24 ) ;
if ( V_126 < 9 )
return 0 ;
for ( V_43 = 0 ; V_43 < V_83 ; V_43 ++ ) {
if ( V_33 -> V_61 & ( 1 << V_43 ) ) {
V_135 ++ ;
V_12 = F_23 ( V_24 , V_43 ,
& V_127 , & V_128 ) ;
if ( V_12 >= 0 ) {
V_33 -> V_91 . V_41 [ 1 + V_43 ] . V_115 = V_139 ;
V_33 -> V_91 . V_41 [ 1 + V_43 ] . V_42 += V_127 ;
V_33 -> V_92 . V_41 [ 1 + V_43 ] . V_115 = V_139 ;
V_33 -> V_92 . V_41 [ 1 + V_43 ] . V_42 += V_128 ;
} else if ( V_12 != - V_100 ) {
V_33 -> V_91 . V_41 [ 1 + V_43 ] . V_115 = V_121 ;
V_33 -> V_92 . V_41 [ 1 + V_43 ] . V_115 = V_121 ;
F_3 ( & V_2 -> V_13 -> V_14 ,
L_29 ,
V_15 , 'A' + V_43 , V_12 ) ;
}
if ( V_33 -> V_95 . V_41 [ 1 + V_43 ] . V_115 != V_121 )
V_136 ++ ;
V_12 = F_24 ( V_24 , V_43 ,
& V_127 , & V_128 ) ;
if ( V_12 >= 0 ) {
V_33 -> V_93 . V_41 [ 1 + V_43 ] . V_115 = V_139 ;
V_33 -> V_93 . V_41 [ 1 + V_43 ] . V_42 += V_127 ;
V_33 -> V_94 . V_41 [ 1 + V_43 ] . V_115 = V_139 ;
V_33 -> V_94 . V_41 [ 1 + V_43 ] . V_42 += V_128 ;
} else if ( V_12 != - V_100 ) {
V_33 -> V_93 . V_41 [ 1 + V_43 ] . V_115 = V_121 ;
V_33 -> V_94 . V_41 [ 1 + V_43 ] . V_115 = V_121 ;
F_3 ( & V_2 -> V_13 -> V_14 ,
L_29 ,
V_15 , 'A' + V_43 , V_12 ) ;
}
if ( V_33 -> V_95 . V_41 [ 1 + V_43 ] . V_115 != V_121 )
V_137 ++ ;
V_12 = F_25 ( V_24 , V_43 ,
& V_95 ,
& V_96 ) ;
if ( V_12 >= 0 ) {
V_33 -> V_95 . V_41 [ 1 + V_43 ] . V_115 = V_139 ;
V_33 -> V_95 . V_41 [ 1 + V_43 ] . V_42 += V_95 ;
V_33 -> V_96 . V_41 [ 1 + V_43 ] . V_115 = V_139 ;
V_33 -> V_96 . V_41 [ 1 + V_43 ] . V_42 += V_96 ;
} else if ( V_12 != - V_100 ) {
V_33 -> V_95 . V_41 [ 1 + V_43 ] . V_115 = V_121 ;
V_33 -> V_96 . V_41 [ 1 + V_43 ] . V_115 = V_121 ;
F_3 ( & V_2 -> V_13 -> V_14 ,
L_30 ,
V_15 , 'A' + V_43 , V_12 ) ;
}
if ( V_33 -> V_95 . V_41 [ 1 + V_43 ] . V_115 != V_121 )
V_138 ++ ;
V_129 += V_33 -> V_91 . V_41 [ 1 + V_43 ] . V_42 ;
V_130 += V_33 -> V_92 . V_41 [ 1 + V_43 ] . V_42 ;
V_131 += V_33 -> V_93 . V_41 [ 1 + V_43 ] . V_42 ;
V_132 += V_33 -> V_94 . V_41 [ 1 + V_43 ] . V_42 ;
V_133 += V_33 -> V_95 . V_41 [ 1 + V_43 ] . V_42 ;
V_134 += V_33 -> V_96 . V_41 [ 1 + V_43 ] . V_42 ;
}
}
if ( V_136 ) {
V_33 -> V_91 . V_41 [ 0 ] . V_115 = V_139 ;
V_33 -> V_91 . V_41 [ 0 ] . V_42 = V_129 ;
V_33 -> V_92 . V_41 [ 0 ] . V_115 = V_139 ;
V_33 -> V_92 . V_41 [ 0 ] . V_42 = V_130 ;
} else {
V_33 -> V_91 . V_41 [ 0 ] . V_115 = V_121 ;
V_33 -> V_92 . V_41 [ 0 ] . V_115 = V_139 ;
}
if ( V_137 ) {
V_33 -> V_93 . V_41 [ 0 ] . V_115 = V_139 ;
V_33 -> V_93 . V_41 [ 0 ] . V_42 = V_131 ;
V_33 -> V_94 . V_41 [ 0 ] . V_115 = V_139 ;
V_33 -> V_94 . V_41 [ 0 ] . V_42 = V_132 ;
} else {
V_33 -> V_93 . V_41 [ 0 ] . V_115 = V_121 ;
V_33 -> V_94 . V_41 [ 0 ] . V_115 = V_139 ;
}
if ( V_138 ) {
V_33 -> V_95 . V_41 [ 0 ] . V_115 = V_139 ;
V_33 -> V_95 . V_41 [ 0 ] . V_42 = V_133 ;
V_33 -> V_96 . V_41 [ 0 ] . V_115 = V_139 ;
V_33 -> V_96 . V_41 [ 0 ] . V_42 = V_134 ;
} else {
V_33 -> V_95 . V_41 [ 0 ] . V_115 = V_121 ;
V_33 -> V_96 . V_41 [ 0 ] . V_115 = V_139 ;
}
return V_12 ;
}
static int F_32 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
T_4 V_140 ;
T_3 V_141 ;
int V_12 ;
T_1 V_142 = 1 , V_143 , V_144 = 0x3a ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_24 -> V_145 . V_146 )
V_24 -> V_145 . V_146 ( V_24 , 0 ) ;
V_12 = F_22 ( V_2 , V_147 ) ;
if ( V_12 < 0 )
goto V_98;
if ( ! V_2 -> V_148 )
V_144 |= 0x04 ;
V_12 = F_11 ( V_2 , 0x09 , V_144 ) ;
if ( V_12 < 0 )
goto V_98;
if ( ! V_2 -> V_149 )
V_143 = 1 ;
else
V_143 = 0 ;
V_12 = F_11 ( V_2 , 0x39 , V_143 ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_11 ( V_2 , 0x71 , V_2 -> V_149 ) ;
if ( V_12 < 0 )
goto V_98;
if ( V_2 -> V_150 ) {
V_12 = F_11 ( V_2 , 0x44 , V_2 -> V_150 ) ;
if ( V_12 < 0 )
goto V_98;
}
V_141 = V_2 -> V_151 -> V_141 ;
if ( ! V_141 )
V_141 = 32571428 ;
if ( V_24 -> V_145 . V_152 . V_153 )
V_24 -> V_145 . V_152 . V_153 ( V_24 , & V_2 -> V_154 ) ;
if ( ! V_2 -> V_154 )
V_2 -> V_154 = 3300000 ;
V_140 = ( ( ( T_4 ) 1 ) << 34 ) * V_2 -> V_154 ;
F_27 ( V_140 , 63 * V_141 ) ;
V_140 = ( 1 << 25 ) - V_140 ;
V_12 = F_11 ( V_2 , 0x28 , 0x2a ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_11 ( V_2 , 0x29 , ( V_140 >> 16 ) & 0xff ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_11 ( V_2 , 0x2a , ( V_140 >> 8 ) & 0xff ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_11 ( V_2 , 0x2b , V_140 & 0xff ) ;
if ( V_12 < 0 )
goto V_98;
F_8 ( & V_2 -> V_13 -> V_14 , L_31 ,
V_15 , V_141 , V_2 -> V_154 , ( long long ) V_140 ) ;
V_140 = V_2 -> V_154 * 1677721600L ;
F_27 ( V_140 , 1628571429L ) ;
V_12 = F_11 ( V_2 , 0x28 , 0x20 ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_11 ( V_2 , 0x29 , ( V_140 >> 16 ) & 0xff ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_11 ( V_2 , 0x2a , ( V_140 >> 8 ) & 0xff ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_11 ( V_2 , 0x2b , V_140 & 0xff ) ;
if ( V_12 < 0 )
goto V_98;
F_8 ( & V_2 -> V_13 -> V_14 , L_32 ,
V_15 , V_2 -> V_154 , ( long long ) V_140 ) ;
if ( ! V_2 -> V_151 -> V_155 )
V_142 &= ~ 1 ;
V_12 = F_11 ( V_2 , 0x50 , 0xd5 ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_11 ( V_2 , 0x51 , V_142 ) ;
if ( V_12 < 0 )
goto V_98;
V_12 = F_22 ( V_2 , V_156 ) ;
if ( V_12 < 0 )
goto V_98;
V_98:
if ( V_24 -> V_145 . V_146 )
V_24 -> V_145 . V_146 ( V_24 , 1 ) ;
if ( V_12 < 0 ) {
V_2 -> V_157 = true ;
F_33 ( & V_2 -> V_13 -> V_14 ,
L_33 ) ;
} else {
V_2 -> V_157 = false ;
F_8 ( & V_2 -> V_13 -> V_14 , L_34 ) ;
}
return V_12 ;
}
static int F_34 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_32 * V_33 = & V_24 -> V_34 ;
int V_12 , V_154 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( ! V_33 -> V_61 )
V_33 -> V_61 = 7 ;
if ( V_33 -> V_61 == 1 )
V_2 -> V_149 = V_158 ;
else if ( V_33 -> V_82 )
V_2 -> V_149 = V_159 ;
else
V_2 -> V_149 = V_160 ;
if ( V_33 -> V_148 == V_161 )
V_2 -> V_148 = true ;
else
V_2 -> V_148 = false ;
if ( ! V_33 -> V_66 ) {
V_2 -> V_150 = 0 ;
} else {
if ( V_33 -> V_162 >= F_14 ( V_163 ) )
V_33 -> V_162 = 0 ;
V_2 -> V_150 = V_163 [ V_33 -> V_162 ] ;
}
if ( V_24 -> V_145 . V_146 )
V_24 -> V_145 . V_146 ( V_24 , 1 ) ;
V_24 -> V_145 . V_152 . V_164 ( V_24 ) ;
if ( V_24 -> V_145 . V_152 . V_153 )
V_24 -> V_145 . V_152 . V_153 ( V_24 , & V_154 ) ;
F_32 ( V_24 ) ;
if ( V_24 -> V_145 . V_146 )
V_24 -> V_145 . V_146 ( V_24 , 0 ) ;
V_12 = F_22 ( V_2 , V_165 ) ;
F_21 ( V_24 ) ;
F_30 ( V_24 ) ;
if ( V_24 -> V_145 . V_146 )
V_24 -> V_145 . V_146 ( V_24 , 1 ) ;
return V_12 ;
}
static int F_35 ( struct V_23 * V_24 ,
T_2 * V_25 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
int V_12 , V_126 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_24 -> V_145 . V_146 )
V_24 -> V_145 . V_146 ( V_24 , 0 ) ;
V_126 = F_6 ( V_24 , V_25 ) ;
if ( V_126 < 7 ) {
F_30 ( V_24 ) ;
F_18 ( V_24 ) ;
}
if ( V_126 < 0 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_35 , V_15 ) ;
goto error;
}
V_12 = F_9 ( V_24 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_36 , V_15 ) ;
F_30 ( V_24 ) ;
F_18 ( V_24 ) ;
V_12 = 0 ;
goto error;
}
if ( V_126 >= 7 ) {
V_12 = F_20 ( V_24 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_37 , V_15 ) ;
V_12 = 0 ;
goto error;
}
V_12 = F_31 ( V_24 , V_126 ) ;
if ( V_12 < 0 && V_12 != - V_100 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_38 , V_15 ) ;
V_12 = 0 ;
goto error;
}
V_12 = 0 ;
}
goto V_99;
error:
F_30 ( V_24 ) ;
V_99:
if ( V_24 -> V_145 . V_146 )
V_24 -> V_145 . V_146 ( V_24 , 1 ) ;
return V_12 ;
}
static int F_36 ( struct V_23 * V_24 ,
T_5 * V_40 )
{
struct V_32 * V_33 = & V_24 -> V_34 ;
* V_40 = V_33 -> V_40 . V_41 [ 0 ] . V_42 ;
return 0 ;
}
static int F_37 ( struct V_23 * V_24 )
{
return 0 ;
}
static int F_38 ( struct V_23 * V_24 ,
bool V_166 ,
unsigned int V_167 ,
unsigned int * V_168 ,
T_2 * V_25 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
int V_12 = 0 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_166 )
V_12 = F_34 ( V_24 ) ;
if ( ! ( V_167 & V_169 ) )
F_35 ( V_24 , V_25 ) ;
return V_12 ;
}
static void F_39 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
F_40 ( V_2 ) ;
}
struct V_23 * F_41 ( const struct V_170 * V_151 ,
struct V_171 * V_13 )
{
struct V_1 * V_2 ;
T_1 V_172 ;
F_8 ( & V_13 -> V_14 , L_5 , V_15 ) ;
V_2 = F_42 ( sizeof( struct V_1 ) , V_173 ) ;
if ( V_2 == NULL ) {
F_3 ( & V_13 -> V_14 ,
L_39 , V_15 ) ;
goto error;
}
V_2 -> V_151 = V_151 ;
V_2 -> V_13 = V_13 ;
memcpy ( & V_2 -> V_174 . V_145 , & V_175 ,
sizeof( struct V_176 ) ) ;
V_2 -> V_174 . V_26 = V_2 ;
V_172 = F_7 ( V_2 , 0 ) ;
if ( V_172 == 0x13 ) {
F_33 ( & V_13 -> V_14 ,
L_40 ) ;
} else {
F_8 ( & V_13 -> V_14 ,
L_41 ,
V_172 ) ;
goto error;
}
return & V_2 -> V_174 ;
error:
F_40 ( V_2 ) ;
return NULL ;
}
