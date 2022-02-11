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
static int F_6 ( struct V_23 * V_24 , enum V_25 * V_26 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
int V_20 ;
* V_26 = 0 ;
V_20 = F_7 ( V_2 , 0x0a ) & 0xf ;
if ( V_20 < 0 )
return V_20 ;
if ( V_20 >= 2 )
* V_26 |= V_28 ;
if ( V_20 >= 4 )
* V_26 |= V_29 ;
if ( V_20 >= 5 )
* V_26 |= V_30 ;
if ( V_20 >= 7 )
* V_26 |= V_31 ;
if ( V_20 >= 8 )
* V_26 |= V_32 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_3 ,
V_15 , * V_26 , V_20 ) ;
return V_20 ;
}
static int F_9 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_33 * V_34 = & V_24 -> V_35 ;
int V_12 ;
unsigned V_36 , V_37 , V_38 ;
if ( V_2 -> V_39 &&
( ! F_10 ( V_40 , V_2 -> V_39 ) ) )
return V_34 -> V_41 . V_42 [ 0 ] . V_43 ;
V_34 -> V_41 . V_42 [ 0 ] . V_43 = 0 ;
V_36 = 0xfff ;
V_37 = 0 ;
do {
V_38 = ( V_36 + V_37 ) / 2 ;
V_12 = F_11 ( V_2 , 0x04 , 0x1f ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x05 , V_38 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x04 , 0x20 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x05 , V_38 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x02 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_12 & 0x08 )
V_37 = ( V_36 + V_37 ) / 2 ;
else
V_36 = ( V_36 + V_37 ) / 2 ;
if ( V_36 - V_37 < 4 ) {
V_38 = ( V_36 + V_37 ) / 2 ;
V_38 = V_38 << ( 16 - 12 ) ;
if ( V_38 )
V_38 |= ( 1 << 12 ) - 1 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_4 ,
V_15 , V_38 , V_37 , V_38 >> 4 , V_36 ) ;
V_34 -> V_41 . V_42 [ 0 ] . V_43 = V_38 ;
V_2 -> V_39 = V_40 +
F_12 ( 1000 ) ;
return 0 ;
}
} while ( 1 );
}
static int F_13 ( struct V_1 * V_2 ,
unsigned V_44 )
{
int V_12 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x86 ,
[ 1 ] = 0x8a ,
[ 2 ] = 0x8e ,
} ;
if ( V_44 >= F_14 ( V_4 ) )
return - V_45 ;
V_12 = F_11 ( V_2 , 0x6d , V_4 [ V_44 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( ( V_12 >> 4 ) & 0x07 ) {
case 0 :
return V_46 ;
case 1 :
return V_47 ;
case 2 :
return V_48 ;
case 3 :
return V_49 ;
default:
return V_50 ;
}
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_44 )
{
int V_12 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x87 ,
[ 1 ] = 0x8b ,
[ 2 ] = 0x8f ,
} ;
if ( V_44 >= F_14 ( V_4 ) )
return - V_45 ;
V_12 = F_11 ( V_2 , 0x6d , V_4 [ V_44 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( ( V_12 >> 4 ) & 0x07 ) {
case 0 :
return V_51 ;
case 1 :
return V_52 ;
case 2 :
return V_53 ;
case 3 :
return V_54 ;
case 4 :
return V_55 ;
default:
return V_56 ;
}
}
static int F_16 ( struct V_1 * V_2 ,
unsigned V_44 )
{
int V_12 ;
int V_57 [] = {
0 , 1 , 2 , 4 , 8
} ;
static unsigned char V_4 [] = {
[ 0 ] = 0x88 ,
[ 1 ] = 0x8c ,
[ 2 ] = 0x90 ,
} ;
if ( V_44 >= F_14 ( V_4 ) )
return - V_45 ;
V_12 = F_11 ( V_2 , 0x6d , V_4 [ V_44 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
return V_57 [ ( V_12 >> 4 ) & 0x07 ] ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned V_44 )
{
int V_12 , V_58 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x89 ,
[ 1 ] = 0x8d ,
[ 2 ] = 0x91 ,
} ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_44 >= F_14 ( V_4 ) )
return - V_45 ;
V_12 = F_11 ( V_2 , 0x6d , V_4 [ V_44 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
V_58 = ( V_12 >> 4 ) & 0x0f ;
F_8 ( & V_2 -> V_13 -> V_14 , L_6 , V_15 , V_58 ) ;
return V_58 ;
}
static void F_18 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_33 * V_34 = & V_24 -> V_35 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
V_34 -> V_59 = V_60 ;
V_34 -> V_61 = 6000000 ;
V_34 -> V_62 = 0 ;
V_34 -> V_63 = V_64 ;
V_34 -> V_65 = V_66 ;
V_34 -> V_67 = 0 ;
V_34 -> V_68 = 0 ;
}
static void F_19 ( struct V_23 * V_24 , T_2 V_44 ,
T_2 V_69 , T_2 V_70 ,
T_2 V_65 ,
T_2 V_71 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
T_2 V_72 ;
int V_73 , V_74 , V_75 ;
switch ( V_69 ) {
case V_46 :
case V_47 :
default:
V_73 = 0 ;
break;
case V_48 :
V_73 = 1 ;
break;
case V_49 :
V_73 = 2 ;
break;
}
switch ( V_70 ) {
default:
case V_51 :
case V_56 :
V_74 = 0 ;
break;
case V_52 :
V_74 = 1 ;
break;
case V_53 :
V_74 = 2 ;
break;
case V_54 :
V_74 = 3 ;
break;
case V_55 :
V_74 = 4 ;
break;
}
switch ( V_65 ) {
default:
case V_76 :
V_75 = 0 ;
break;
case V_77 :
V_75 = 1 ;
break;
case V_78 :
V_75 = 2 ;
break;
case V_79 :
V_75 = 3 ;
break;
}
V_72 = V_80 [ V_73 ] [ V_74 ] [ V_75 ] * V_71 * V_81 ;
if ( V_72 < 256 )
V_72 = 256 ;
else if ( V_72 > ( 1 << 24 ) - 1 )
V_72 = ( 1 << 24 ) - 1 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_7 ,
V_15 , 'A' + V_44 ,
V_71 * V_80 [ V_73 ] [ V_74 ] [ V_75 ] / 1000 ,
V_72 , V_72 ) ;
V_2 -> V_82 [ V_44 ] = V_72 ;
}
static int F_20 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_33 * V_34 = & V_24 -> V_35 ;
int V_44 , V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
F_18 ( V_24 ) ;
V_12 = F_11 ( V_2 , 0x6d , 0x85 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
V_34 -> V_83 = ( V_12 & 0x10 ) ? 1 : 0 ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
F_8 ( & V_2 -> V_13 -> V_14 , L_8 ,
V_15 , 'A' + V_44 ) ;
V_12 = F_17 ( V_2 , V_44 ) ;
if ( V_12 < 0 )
goto V_85;
if ( V_12 >= 0 && V_12 < 14 ) {
V_34 -> V_44 [ V_44 ] . V_86 = V_12 ;
} else {
V_34 -> V_44 [ V_44 ] . V_86 = 0 ;
V_2 -> V_82 [ V_44 ] = 0 ;
continue;
}
V_34 -> V_62 |= 1 << V_44 ;
V_12 = F_13 ( V_2 , V_44 ) ;
if ( V_12 < 0 )
goto V_85;
F_8 ( & V_2 -> V_13 -> V_14 , L_9 ,
V_15 , V_12 ) ;
V_34 -> V_44 [ V_44 ] . V_69 = V_12 ;
V_12 = F_15 ( V_2 , V_44 ) ;
if ( V_12 < 0 )
goto V_85;
F_8 ( & V_2 -> V_13 -> V_14 , L_10 ,
V_15 , V_12 ) ;
V_34 -> V_44 [ V_44 ] . V_74 = V_12 ;
V_12 = F_16 ( V_2 , V_44 ) ;
if ( V_12 < 0 )
goto V_85;
F_8 ( & V_2 -> V_13 -> V_14 , L_11 ,
V_15 , V_12 ) ;
V_34 -> V_44 [ V_44 ] . V_57 = V_12 ;
F_19 ( V_24 , V_44 , V_34 -> V_44 [ V_44 ] . V_69 ,
V_34 -> V_44 [ V_44 ] . V_74 ,
V_34 -> V_65 ,
V_34 -> V_44 [ V_44 ] . V_86 ) ;
}
V_12 = F_11 ( V_2 , 0x6d , 0x84 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ( V_12 & 0x60 ) == 0x20 ) {
V_34 -> V_67 = 1 ;
if ( ! V_34 -> V_68 )
V_34 -> V_68 = 1 ;
}
V_12 = F_7 ( V_2 , 0x07 ) ;
if ( V_12 < 0 )
return V_12 ;
V_34 -> V_63 = V_64 ;
if ( ( V_12 & 0x60 ) == 0x20 ) {
switch ( ( V_12 >> 2 ) & 0x03 ) {
case 1 :
V_34 -> V_63 = V_87 ;
break;
case 2 :
V_34 -> V_63 = V_88 ;
break;
}
}
V_34 -> V_65 = V_66 ;
if ( ! ( V_12 & 0x10 ) ) {
switch ( V_12 & 0x3 ) {
case 0 :
V_34 -> V_65 = V_76 ;
break;
case 1 :
V_34 -> V_65 = V_77 ;
break;
case 2 :
V_34 -> V_65 = V_78 ;
break;
}
}
return 0 ;
V_85:
V_34 -> V_62 = 0 ;
return V_12 ;
}
static int F_21 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_33 * V_34 = & V_24 -> V_35 ;
int V_12 , V_20 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_2 -> V_89 != V_34 -> V_90 ) {
memset ( & V_34 -> V_91 , 0 , sizeof( V_34 -> V_91 ) ) ;
memset ( & V_34 -> V_92 , 0 , sizeof( V_34 -> V_92 ) ) ;
memset ( & V_34 -> V_93 , 0 , sizeof( V_34 -> V_93 ) ) ;
memset ( & V_34 -> V_94 , 0 , sizeof( V_34 -> V_94 ) ) ;
memset ( & V_34 -> V_95 , 0 , sizeof( V_34 -> V_95 ) ) ;
memset ( & V_34 -> V_96 , 0 , sizeof( V_34 -> V_96 ) ) ;
memset ( & V_34 -> V_97 , 0 , sizeof( V_34 -> V_97 ) ) ;
V_2 -> V_89 = V_34 -> V_90 ;
}
V_12 = F_22 ( V_2 , V_98 ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_7 ( V_2 , 0x45 ) ;
if ( V_12 < 0 )
goto V_99;
V_20 = V_12 ;
V_12 = F_11 ( V_2 , 0x45 , V_20 | 0x10 ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_11 ( V_2 , 0x45 , V_20 & 0x6f ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_11 ( V_2 , 0x50 , 0x50 ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
goto V_99;
V_20 = V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_20 | 0x01 ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_11 ( V_2 , 0x51 , V_20 & 0x06 ) ;
if ( V_12 < 0 )
goto V_99;
goto V_100;
V_99:
F_3 ( & V_2 -> V_13 -> V_14 ,
L_12 ,
V_15 , V_12 ) ;
V_100:
return V_12 ;
}
static int F_23 ( struct V_23 * V_24 ,
unsigned V_44 ,
T_2 * error , T_2 * V_58 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
int V_12 , V_20 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_44 >= V_84 )
return - V_45 ;
V_12 = F_7 ( V_2 , 0x54 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & ( 1 << V_44 ) ) ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_13 ,
V_15 , 'A' + V_44 ) ;
return - V_101 ;
}
V_12 = F_7 ( V_2 , 0x55 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error = V_12 << 16 ;
V_12 = F_7 ( V_2 , 0x56 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 << 8 ;
V_12 = F_7 ( V_2 , 0x57 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_14 ,
V_15 , 'A' + V_44 , * error ) ;
V_12 = F_11 ( V_2 , 0x50 , 0xa7 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_58 = V_12 << 16 ;
V_12 = F_11 ( V_2 , 0x50 , 0xa8 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_58 |= V_12 << 8 ;
V_12 = F_11 ( V_2 , 0x50 , 0xa9 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_58 |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_15 ,
V_15 , 'A' + V_44 , * V_58 ) ;
if ( V_2 -> V_82 [ V_44 ]
&& V_2 -> V_82 [ V_44 ] != * V_58 ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_16 ,
V_15 , 'A' + V_44 , V_2 -> V_82 [ V_44 ] ) ;
V_12 = F_11 ( V_2 , 0x52 , 0x00 ) ;
V_12 = F_11 ( V_2 , 0x50 , 0xa7 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 ,
V_2 -> V_82 [ V_44 ] >> 16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x50 , 0xa8 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 ,
V_2 -> V_82 [ V_44 ] >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x50 , 0xa9 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 ,
V_2 -> V_82 [ V_44 ] ) ;
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
V_12 = F_11 ( V_2 , 0x53 , V_20 & ~ ( 1 << V_44 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x53 , V_20 | ( 1 << V_44 ) ) ;
}
return V_12 ;
}
static int F_24 ( struct V_23 * V_24 ,
unsigned V_44 ,
T_2 * error , T_2 * V_58 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
T_2 V_102 , V_103 ;
int V_12 , V_20 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_44 >= V_84 )
return - V_45 ;
V_12 = F_7 ( V_2 , 0x60 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & ( 1 << V_44 ) ) ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_17 ,
V_15 , 'A' + V_44 ) ;
return - V_101 ;
}
V_12 = F_7 ( V_2 , 0x64 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error = V_12 << 16 ;
V_12 = F_7 ( V_2 , 0x65 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 << 8 ;
V_12 = F_7 ( V_2 , 0x66 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_18 ,
V_15 , 'A' + V_44 , * error ) ;
V_12 = F_11 ( V_2 , 0x50 , 0xdc + V_44 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_102 = V_12 << 8 ;
V_12 = F_11 ( V_2 , 0x50 , 0xdd + V_44 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_102 |= V_12 ;
* V_58 = V_102 * 204 * 8 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_19 ,
V_15 , 'A' + V_44 , * V_58 ) ;
if ( ! V_2 -> V_82 [ V_44 ] )
goto V_104;
V_103 = V_2 -> V_82 [ V_44 ] / 204 / 8 ;
if ( V_103 < 32 )
V_103 = 32 ;
if ( V_103 > 65535 )
V_103 = 65535 ;
if ( V_103 != V_102 ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_20 ,
V_15 , 'A' + V_44 , V_103 ) ;
V_12 = F_11 ( V_2 , 0x5e , 0x00 ) ;
V_12 = F_11 ( V_2 , 0x50 , 0xdc + V_44 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_103 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x50 , 0xdd + V_44 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_103 & 0xff ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x5e , 0x07 ) ;
V_12 = F_11 ( V_2 , 0x5f , 0x00 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x5f , 0x07 ) ;
return V_12 ;
}
V_104:
V_12 = F_7 ( V_2 , 0x5f ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = V_12 ;
V_12 = F_11 ( V_2 , 0x5f , V_20 & ~ ( 1 << V_44 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x5f , V_20 | ( 1 << V_44 ) ) ;
return V_12 ;
}
static int F_25 ( struct V_23 * V_24 ,
unsigned V_44 ,
T_2 * error , T_2 * V_58 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
int V_12 , V_20 ;
T_2 V_103 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_44 >= V_84 )
return - V_45 ;
V_12 = F_11 ( V_2 , 0x50 , 0xb8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & ( 1 << V_44 ) ) ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_21 ,
V_15 , 'A' + V_44 ) ;
return - V_101 ;
}
V_12 = F_11 ( V_2 , 0x50 , 0xb9 + V_44 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* error = V_12 << 8 ;
V_12 = F_11 ( V_2 , 0x50 , 0xba + V_44 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_22 ,
V_15 , 'A' + V_44 , * error ) ;
V_12 = F_11 ( V_2 , 0x50 , 0xb2 + V_44 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_58 = V_12 << 8 ;
V_12 = F_11 ( V_2 , 0x50 , 0xb3 + V_44 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_58 |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_23 ,
V_15 , 'A' + V_44 , * V_58 ) ;
if ( ! V_2 -> V_82 [ V_44 ] )
goto V_104;
V_103 = V_2 -> V_82 [ V_44 ] / 204 / 8 ;
if ( V_103 < 32 )
V_103 = 32 ;
if ( V_103 > 65535 )
V_103 = 65535 ;
if ( V_103 != * V_58 ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_24 ,
V_15 , 'A' + V_44 , V_103 ) ;
V_12 = F_11 ( V_2 , 0x50 , 0xb0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , 0x00 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x50 , 0xb2 + V_44 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_103 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x50 , 0xb3 + V_44 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_103 & 0xff ) ;
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
V_104:
V_12 = F_11 ( V_2 , 0x50 , 0xb1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_20 | ( 1 << V_44 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x51 , V_20 & ~ ( 1 << V_44 ) ) ;
return V_12 ;
}
static T_2 F_26 ( T_2 V_105 , const struct V_106 * V_107 ,
unsigned V_11 )
{
T_3 V_108 ;
T_2 V_109 , V_110 ;
int V_19 , V_111 ;
if ( V_105 >= V_107 [ 0 ] . V_112 )
return V_107 [ 0 ] . V_113 ;
if ( V_105 < V_107 [ V_11 - 1 ] . V_112 )
return V_107 [ V_11 - 1 ] . V_113 ;
for ( V_19 = 1 ; V_19 < V_11 - 1 ; V_19 ++ ) {
if ( V_105 == V_107 [ V_19 ] . V_112 )
return V_107 [ V_19 ] . V_113 ;
if ( V_105 > V_107 [ V_19 ] . V_112 )
break;
}
V_110 = V_107 [ V_19 ] . V_113 - V_107 [ V_19 - 1 ] . V_113 ;
V_109 = V_107 [ V_19 - 1 ] . V_112 - V_107 [ V_19 ] . V_112 ;
V_108 = V_105 - V_107 [ V_19 ] . V_112 ;
V_108 *= V_110 ;
F_27 ( V_108 , V_109 ) ;
V_111 = V_107 [ V_19 ] . V_113 - V_108 ;
return V_111 ;
}
static int F_28 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_33 * V_34 = & V_24 -> V_35 ;
T_2 V_114 , V_91 ;
int V_12 , V_20 ;
V_12 = F_7 ( V_2 , 0x45 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & 0x40 ) ) {
F_8 ( & V_2 -> V_13 -> V_14 , L_25 ,
V_15 ) ;
return - V_101 ;
}
V_20 = V_12 ;
V_12 = F_7 ( V_2 , 0x46 ) ;
if ( V_12 < 0 )
return V_12 ;
V_114 = V_12 << 8 ;
V_12 = F_7 ( V_2 , 0x46 ) ;
if ( V_12 < 0 )
return V_12 ;
V_114 |= V_12 ;
V_91 = F_26 ( V_114 ,
V_115 , F_14 ( V_115 ) ) ;
V_34 -> V_91 . V_42 [ 0 ] . V_116 = V_117 ;
V_34 -> V_91 . V_42 [ 0 ] . V_118 = V_91 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_26 ,
V_15 , V_91 / 1000 , V_91 % 1000 , V_114 ) ;
V_12 = F_11 ( V_2 , 0x45 , V_20 | 0x10 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_2 , 0x45 , V_20 & 0x6f ) ;
return V_12 ;
}
static int F_29 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_33 * V_34 = & V_24 -> V_35 ;
T_2 V_119 , V_91 ;
int V_12 , V_20 , V_44 ;
const struct V_106 * V_120 ;
unsigned V_121 ;
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
return - V_101 ;
}
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
if ( ! ( V_34 -> V_62 & ( 1 << V_44 ) ) ) {
V_34 -> V_91 . V_42 [ 1 + V_44 ] . V_116 = V_122 ;
continue;
}
V_12 = F_11 ( V_2 , 0x50 , 0x52 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_119 = V_12 << 16 ;
V_12 = F_11 ( V_2 , 0x50 , 0x53 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_119 |= V_12 << 8 ;
V_12 = F_11 ( V_2 , 0x50 , 0x54 + V_44 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_119 |= V_12 ;
switch ( V_34 -> V_44 [ V_44 ] . V_69 ) {
case V_46 :
case V_47 :
V_120 = V_123 ;
V_121 = F_14 ( V_123 ) ;
break;
case V_48 :
V_120 = V_124 ;
V_121 = F_14 ( V_124 ) ;
break;
default:
case V_49 :
V_120 = V_125 ;
V_121 = F_14 ( V_125 ) ;
break;
}
V_91 = F_26 ( V_119 , V_120 , V_121 ) ;
V_34 -> V_91 . V_42 [ 1 + V_44 ] . V_116 = V_117 ;
V_34 -> V_91 . V_42 [ 1 + V_44 ] . V_118 = V_91 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_28 ,
V_15 , 'A' + V_44 , V_91 / 1000 , V_91 % 1000 , V_119 ) ;
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
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_33 * V_34 = & V_24 -> V_35 ;
int V_44 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
V_34 -> V_41 . V_11 = 1 ;
V_34 -> V_91 . V_11 = V_84 + 1 ;
V_34 -> V_92 . V_11 = V_84 + 1 ;
V_34 -> V_93 . V_11 = V_84 + 1 ;
V_34 -> V_94 . V_11 = V_84 + 1 ;
V_34 -> V_95 . V_11 = V_84 + 1 ;
V_34 -> V_96 . V_11 = V_84 + 1 ;
V_34 -> V_97 . V_11 = V_84 + 1 ;
V_34 -> V_41 . V_42 [ 0 ] . V_116 = V_126 ;
V_34 -> V_41 . V_42 [ 0 ] . V_43 = 0 ;
for ( V_44 = 0 ; V_44 < V_84 + 1 ; V_44 ++ ) {
V_34 -> V_91 . V_42 [ V_44 ] . V_116 = V_122 ;
V_34 -> V_92 . V_42 [ V_44 ] . V_116 = V_122 ;
V_34 -> V_93 . V_42 [ V_44 ] . V_116 = V_122 ;
V_34 -> V_94 . V_42 [ V_44 ] . V_116 = V_122 ;
V_34 -> V_95 . V_42 [ V_44 ] . V_116 = V_122 ;
V_34 -> V_96 . V_42 [ V_44 ] . V_116 = V_122 ;
V_34 -> V_97 . V_42 [ V_44 ] . V_116 = V_122 ;
}
}
static int F_31 ( struct V_23 * V_24 , int V_127 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_33 * V_34 = & V_24 -> V_35 ;
int V_12 = 0 , V_44 ;
T_2 V_128 = 0 , V_129 = 0 ;
T_2 V_130 = 0 , V_131 = 0 ;
T_2 V_132 = 0 , V_133 = 0 ;
T_2 V_96 = 0 , V_97 = 0 ;
T_2 V_134 = 0 , V_135 = 0 ;
int V_136 = 0 , V_137 = 0 , V_138 = 0 ;
int V_139 = 0 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
F_28 ( V_24 ) ;
F_29 ( V_24 ) ;
if ( V_127 < 9 )
return 0 ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
if ( V_34 -> V_62 & ( 1 << V_44 ) ) {
V_136 ++ ;
V_12 = F_23 ( V_24 , V_44 ,
& V_128 , & V_129 ) ;
if ( V_12 >= 0 ) {
V_34 -> V_92 . V_42 [ 1 + V_44 ] . V_116 = V_140 ;
V_34 -> V_92 . V_42 [ 1 + V_44 ] . V_43 += V_128 ;
V_34 -> V_93 . V_42 [ 1 + V_44 ] . V_116 = V_140 ;
V_34 -> V_93 . V_42 [ 1 + V_44 ] . V_43 += V_129 ;
} else if ( V_12 != - V_101 ) {
V_34 -> V_92 . V_42 [ 1 + V_44 ] . V_116 = V_122 ;
V_34 -> V_93 . V_42 [ 1 + V_44 ] . V_116 = V_122 ;
F_3 ( & V_2 -> V_13 -> V_14 ,
L_29 ,
V_15 , 'A' + V_44 , V_12 ) ;
}
if ( V_34 -> V_96 . V_42 [ 1 + V_44 ] . V_116 != V_122 )
V_137 ++ ;
V_12 = F_24 ( V_24 , V_44 ,
& V_128 , & V_129 ) ;
if ( V_12 >= 0 ) {
V_34 -> V_94 . V_42 [ 1 + V_44 ] . V_116 = V_140 ;
V_34 -> V_94 . V_42 [ 1 + V_44 ] . V_43 += V_128 ;
V_34 -> V_95 . V_42 [ 1 + V_44 ] . V_116 = V_140 ;
V_34 -> V_95 . V_42 [ 1 + V_44 ] . V_43 += V_129 ;
} else if ( V_12 != - V_101 ) {
V_34 -> V_94 . V_42 [ 1 + V_44 ] . V_116 = V_122 ;
V_34 -> V_95 . V_42 [ 1 + V_44 ] . V_116 = V_122 ;
F_3 ( & V_2 -> V_13 -> V_14 ,
L_29 ,
V_15 , 'A' + V_44 , V_12 ) ;
}
if ( V_34 -> V_96 . V_42 [ 1 + V_44 ] . V_116 != V_122 )
V_138 ++ ;
V_12 = F_25 ( V_24 , V_44 ,
& V_96 ,
& V_97 ) ;
if ( V_12 >= 0 ) {
V_34 -> V_96 . V_42 [ 1 + V_44 ] . V_116 = V_140 ;
V_34 -> V_96 . V_42 [ 1 + V_44 ] . V_43 += V_96 ;
V_34 -> V_97 . V_42 [ 1 + V_44 ] . V_116 = V_140 ;
V_34 -> V_97 . V_42 [ 1 + V_44 ] . V_43 += V_97 ;
} else if ( V_12 != - V_101 ) {
V_34 -> V_96 . V_42 [ 1 + V_44 ] . V_116 = V_122 ;
V_34 -> V_97 . V_42 [ 1 + V_44 ] . V_116 = V_122 ;
F_3 ( & V_2 -> V_13 -> V_14 ,
L_30 ,
V_15 , 'A' + V_44 , V_12 ) ;
}
if ( V_34 -> V_96 . V_42 [ 1 + V_44 ] . V_116 != V_122 )
V_139 ++ ;
V_130 += V_34 -> V_92 . V_42 [ 1 + V_44 ] . V_43 ;
V_131 += V_34 -> V_93 . V_42 [ 1 + V_44 ] . V_43 ;
V_132 += V_34 -> V_94 . V_42 [ 1 + V_44 ] . V_43 ;
V_133 += V_34 -> V_95 . V_42 [ 1 + V_44 ] . V_43 ;
V_134 += V_34 -> V_96 . V_42 [ 1 + V_44 ] . V_43 ;
V_135 += V_34 -> V_97 . V_42 [ 1 + V_44 ] . V_43 ;
}
}
if ( V_137 ) {
V_34 -> V_92 . V_42 [ 0 ] . V_116 = V_140 ;
V_34 -> V_92 . V_42 [ 0 ] . V_43 = V_130 ;
V_34 -> V_93 . V_42 [ 0 ] . V_116 = V_140 ;
V_34 -> V_93 . V_42 [ 0 ] . V_43 = V_131 ;
} else {
V_34 -> V_92 . V_42 [ 0 ] . V_116 = V_122 ;
V_34 -> V_93 . V_42 [ 0 ] . V_116 = V_140 ;
}
if ( V_138 ) {
V_34 -> V_94 . V_42 [ 0 ] . V_116 = V_140 ;
V_34 -> V_94 . V_42 [ 0 ] . V_43 = V_132 ;
V_34 -> V_95 . V_42 [ 0 ] . V_116 = V_140 ;
V_34 -> V_95 . V_42 [ 0 ] . V_43 = V_133 ;
} else {
V_34 -> V_94 . V_42 [ 0 ] . V_116 = V_122 ;
V_34 -> V_95 . V_42 [ 0 ] . V_116 = V_140 ;
}
if ( V_139 ) {
V_34 -> V_96 . V_42 [ 0 ] . V_116 = V_140 ;
V_34 -> V_96 . V_42 [ 0 ] . V_43 = V_134 ;
V_34 -> V_97 . V_42 [ 0 ] . V_116 = V_140 ;
V_34 -> V_97 . V_42 [ 0 ] . V_43 = V_135 ;
} else {
V_34 -> V_96 . V_42 [ 0 ] . V_116 = V_122 ;
V_34 -> V_97 . V_42 [ 0 ] . V_116 = V_140 ;
}
return V_12 ;
}
static int F_32 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
T_3 V_141 ;
T_2 V_142 ;
int V_12 ;
T_1 V_143 = 1 , V_144 , V_145 = 0x3a ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_24 -> V_146 . V_147 )
V_24 -> V_146 . V_147 ( V_24 , 0 ) ;
V_12 = F_22 ( V_2 , V_148 ) ;
if ( V_12 < 0 )
goto V_99;
if ( ! V_2 -> V_149 )
V_145 |= 0x04 ;
V_12 = F_11 ( V_2 , 0x09 , V_145 ) ;
if ( V_12 < 0 )
goto V_99;
if ( ! V_2 -> V_150 )
V_144 = 1 ;
else
V_144 = 0 ;
V_12 = F_11 ( V_2 , 0x39 , V_144 ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_11 ( V_2 , 0x71 , V_2 -> V_150 ) ;
if ( V_12 < 0 )
goto V_99;
if ( V_2 -> V_151 ) {
V_12 = F_11 ( V_2 , 0x44 , V_2 -> V_151 ) ;
if ( V_12 < 0 )
goto V_99;
}
V_142 = V_2 -> V_152 -> V_142 ;
if ( ! V_142 )
V_142 = 32571428 ;
if ( V_24 -> V_146 . V_153 . V_154 )
V_24 -> V_146 . V_153 . V_154 ( V_24 , & V_2 -> V_155 ) ;
if ( ! V_2 -> V_155 )
V_2 -> V_155 = 3300000 ;
V_141 = ( ( ( T_3 ) 1 ) << 34 ) * V_2 -> V_155 ;
F_27 ( V_141 , 63 * V_142 ) ;
V_141 = ( 1 << 25 ) - V_141 ;
V_12 = F_11 ( V_2 , 0x28 , 0x2a ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_11 ( V_2 , 0x29 , ( V_141 >> 16 ) & 0xff ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_11 ( V_2 , 0x2a , ( V_141 >> 8 ) & 0xff ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_11 ( V_2 , 0x2b , V_141 & 0xff ) ;
if ( V_12 < 0 )
goto V_99;
F_8 ( & V_2 -> V_13 -> V_14 , L_31 ,
V_15 , V_142 , V_2 -> V_155 , ( long long ) V_141 ) ;
V_141 = V_2 -> V_155 * 1677721600L ;
F_27 ( V_141 , 1628571429L ) ;
V_12 = F_11 ( V_2 , 0x28 , 0x20 ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_11 ( V_2 , 0x29 , ( V_141 >> 16 ) & 0xff ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_11 ( V_2 , 0x2a , ( V_141 >> 8 ) & 0xff ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_11 ( V_2 , 0x2b , V_141 & 0xff ) ;
if ( V_12 < 0 )
goto V_99;
F_8 ( & V_2 -> V_13 -> V_14 , L_32 ,
V_15 , V_2 -> V_155 , ( long long ) V_141 ) ;
if ( ! V_2 -> V_152 -> V_156 )
V_143 &= ~ 1 ;
V_12 = F_11 ( V_2 , 0x50 , 0xd5 ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_11 ( V_2 , 0x51 , V_143 ) ;
if ( V_12 < 0 )
goto V_99;
V_12 = F_22 ( V_2 , V_157 ) ;
if ( V_12 < 0 )
goto V_99;
V_99:
if ( V_24 -> V_146 . V_147 )
V_24 -> V_146 . V_147 ( V_24 , 1 ) ;
if ( V_12 < 0 ) {
V_2 -> V_158 = true ;
F_33 ( & V_2 -> V_13 -> V_14 ,
L_33 ) ;
} else {
V_2 -> V_158 = false ;
F_8 ( & V_2 -> V_13 -> V_14 , L_34 ) ;
}
return V_12 ;
}
static int F_34 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_33 * V_34 = & V_24 -> V_35 ;
int V_12 , V_155 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( ! V_34 -> V_62 )
V_34 -> V_62 = 7 ;
if ( V_34 -> V_62 == 1 )
V_2 -> V_150 = V_159 ;
else if ( V_34 -> V_83 )
V_2 -> V_150 = V_160 ;
else
V_2 -> V_150 = V_161 ;
if ( V_34 -> V_149 == V_162 )
V_2 -> V_149 = true ;
else
V_2 -> V_149 = false ;
if ( ! V_34 -> V_67 ) {
V_2 -> V_151 = 0 ;
} else {
if ( V_34 -> V_163 >= F_14 ( V_164 ) )
V_34 -> V_163 = 0 ;
V_2 -> V_151 = V_164 [ V_34 -> V_163 ] ;
}
if ( V_24 -> V_146 . V_147 )
V_24 -> V_146 . V_147 ( V_24 , 1 ) ;
V_24 -> V_146 . V_153 . V_165 ( V_24 ) ;
if ( V_24 -> V_146 . V_153 . V_154 )
V_24 -> V_146 . V_153 . V_154 ( V_24 , & V_155 ) ;
F_32 ( V_24 ) ;
if ( V_24 -> V_146 . V_147 )
V_24 -> V_146 . V_147 ( V_24 , 0 ) ;
V_12 = F_22 ( V_2 , V_166 ) ;
F_21 ( V_24 ) ;
F_30 ( V_24 ) ;
if ( V_24 -> V_146 . V_147 )
V_24 -> V_146 . V_147 ( V_24 , 1 ) ;
return V_12 ;
}
static int F_35 ( struct V_23 * V_24 ,
enum V_25 * V_26 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
int V_12 , V_127 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_24 -> V_146 . V_147 )
V_24 -> V_146 . V_147 ( V_24 , 0 ) ;
V_127 = F_6 ( V_24 , V_26 ) ;
if ( V_127 < 7 ) {
F_30 ( V_24 ) ;
F_18 ( V_24 ) ;
}
if ( V_127 < 0 ) {
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
if ( V_127 >= 7 ) {
V_12 = F_20 ( V_24 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_37 , V_15 ) ;
V_12 = 0 ;
goto error;
}
V_12 = F_31 ( V_24 , V_127 ) ;
if ( V_12 < 0 && V_12 != - V_101 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_38 , V_15 ) ;
V_12 = 0 ;
goto error;
}
V_12 = 0 ;
}
goto V_100;
error:
F_30 ( V_24 ) ;
V_100:
if ( V_24 -> V_146 . V_147 )
V_24 -> V_146 . V_147 ( V_24 , 1 ) ;
return V_12 ;
}
static int F_36 ( struct V_23 * V_24 ,
T_4 * V_41 )
{
struct V_33 * V_34 = & V_24 -> V_35 ;
* V_41 = V_34 -> V_41 . V_42 [ 0 ] . V_43 ;
return 0 ;
}
static int F_37 ( struct V_23 * V_24 )
{
return 0 ;
}
static int F_38 ( struct V_23 * V_24 ,
bool V_167 ,
unsigned int V_168 ,
unsigned int * V_169 ,
enum V_25 * V_26 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
int V_12 = 0 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_167 )
V_12 = F_34 ( V_24 ) ;
if ( ! ( V_168 & V_170 ) )
F_35 ( V_24 , V_26 ) ;
return V_12 ;
}
static void F_39 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
F_40 ( V_2 ) ;
}
struct V_23 * F_41 ( const struct V_171 * V_152 ,
struct V_172 * V_13 )
{
struct V_1 * V_2 ;
T_1 V_173 ;
F_8 ( & V_13 -> V_14 , L_5 , V_15 ) ;
V_2 = F_42 ( sizeof( struct V_1 ) , V_174 ) ;
if ( V_2 == NULL ) {
F_3 ( & V_13 -> V_14 ,
L_39 , V_15 ) ;
goto error;
}
V_2 -> V_152 = V_152 ;
V_2 -> V_13 = V_13 ;
memcpy ( & V_2 -> V_175 . V_146 , & V_176 ,
sizeof( struct V_177 ) ) ;
V_2 -> V_175 . V_27 = V_2 ;
V_173 = F_7 ( V_2 , 0 ) ;
if ( V_173 == 0x13 ) {
F_33 ( & V_13 -> V_14 ,
L_40 ) ;
} else {
F_8 ( & V_13 -> V_14 ,
L_41 ,
V_173 ) ;
goto error;
}
return & V_2 -> V_175 ;
error:
F_40 ( V_2 ) ;
return NULL ;
}
