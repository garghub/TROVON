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
return 0 ;
}
static int F_9 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
int V_12 ;
unsigned V_32 , V_33 , V_34 ;
V_32 = 0xfff ;
V_33 = 0 ;
do {
V_34 = ( V_32 + V_33 ) / 2 ;
V_12 = F_10 ( V_2 , 0x04 , 0x1f ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x05 , V_34 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x04 , 0x20 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x04 , V_34 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x02 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_12 & 0x08 )
V_33 = ( V_32 + V_33 ) / 2 ;
else
V_32 = ( V_32 + V_33 ) / 2 ;
if ( V_32 - V_33 < 4 ) {
V_34 = ( V_32 + V_33 ) / 2 ;
V_34 <<= ( 16 - 12 ) ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_4 ,
V_15 , V_34 , V_33 , V_34 >> 4 , V_32 ) ;
return V_34 ;
}
} while ( 1 );
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned V_35 )
{
int V_12 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x86 ,
[ 1 ] = 0x8a ,
[ 2 ] = 0x8e ,
} ;
if ( V_35 >= F_12 ( V_4 ) )
return - V_36 ;
V_12 = F_10 ( V_2 , 0x6d , V_4 [ V_35 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( ( V_12 >> 4 ) & 0x07 ) {
case 0 :
return V_37 ;
case 1 :
return V_38 ;
case 2 :
return V_39 ;
case 3 :
return V_40 ;
default:
return V_41 ;
}
}
static int F_13 ( struct V_1 * V_2 ,
unsigned V_35 )
{
int V_12 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x87 ,
[ 1 ] = 0x8b ,
[ 2 ] = 0x8f ,
} ;
if ( V_35 >= F_12 ( V_4 ) )
return - V_36 ;
V_12 = F_10 ( V_2 , 0x6d , V_4 [ V_35 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( ( V_12 >> 4 ) & 0x07 ) {
case 0 :
return V_42 ;
case 1 :
return V_43 ;
case 2 :
return V_44 ;
case 3 :
return V_45 ;
case 4 :
return V_46 ;
default:
return V_47 ;
}
}
static int F_14 ( struct V_1 * V_2 ,
unsigned V_35 )
{
int V_12 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x88 ,
[ 1 ] = 0x8c ,
[ 2 ] = 0x90 ,
} ;
if ( V_35 >= F_12 ( V_4 ) )
return - V_36 ;
V_12 = F_10 ( V_2 , 0x6d , V_4 [ V_35 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( ( V_12 >> 4 ) & 0x07 ) {
case 1 :
return V_48 ;
case 2 :
return V_49 ;
case 3 :
return V_50 ;
case 4 :
return V_51 ;
default:
case 0 :
return V_52 ;
}
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_35 )
{
int V_12 , V_53 ;
static unsigned char V_4 [] = {
[ 0 ] = 0x89 ,
[ 1 ] = 0x8d ,
[ 2 ] = 0x91 ,
} ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_35 >= F_12 ( V_4 ) )
return - V_36 ;
V_12 = F_10 ( V_2 , 0x6d , V_4 [ V_35 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
V_53 = ( V_12 >> 4 ) & 0x0f ;
F_8 ( & V_2 -> V_13 -> V_14 , L_6 , V_15 , V_53 ) ;
return V_53 ;
}
static void F_16 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_54 * V_55 = & V_24 -> V_56 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
V_55 -> V_57 = V_58 ;
V_55 -> V_59 = 6000000 ;
V_55 -> V_60 = 0 ;
V_55 -> V_61 = V_62 ;
V_55 -> V_63 = V_52 ;
V_55 -> V_64 = 0 ;
V_55 -> V_65 = 0 ;
}
static void F_17 ( struct V_23 * V_24 , T_3 V_35 ,
T_3 V_66 , T_3 V_67 , T_3 V_68 ,
T_3 V_69 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
T_3 V_70 ;
int V_71 , V_72 , V_19 ;
switch ( V_66 ) {
case V_37 :
case V_38 :
default:
V_71 = 0 ;
break;
case V_39 :
V_71 = 1 ;
break;
case V_40 :
V_71 = 2 ;
break;
}
switch ( V_67 ) {
default:
case V_42 :
case V_47 :
V_72 = 0 ;
break;
case V_43 :
V_72 = 1 ;
break;
case V_44 :
V_72 = 2 ;
break;
case V_45 :
V_72 = 3 ;
break;
case V_46 :
V_72 = 4 ;
break;
}
switch ( V_68 ) {
default:
case V_48 :
V_19 = 0 ;
break;
case V_49 :
V_19 = 1 ;
break;
case V_50 :
V_19 = 2 ;
break;
case V_51 :
V_19 = 3 ;
break;
}
V_70 = V_73 [ V_71 ] [ V_72 ] [ V_19 ] * V_69 * V_74 ;
if ( V_70 < 256 )
V_70 = 256 ;
else if ( V_70 > ( 1 << 24 ) - 1 )
V_70 = ( 1 << 24 ) - 1 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_7 ,
V_15 , 'A' + V_35 , V_69 * V_73 [ V_71 ] [ V_72 ] [ V_19 ] / 1000 ,
V_70 , V_70 ) ;
V_2 -> V_75 [ V_35 ] = V_70 ;
}
static int F_18 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_54 * V_55 = & V_24 -> V_56 ;
int V_19 , V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
F_16 ( V_24 ) ;
V_12 = F_10 ( V_2 , 0x6d , 0x85 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x6e ) ;
if ( V_12 < 0 )
return V_12 ;
V_55 -> V_76 = ( V_12 & 0x10 ) ? 1 : 0 ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ ) {
F_8 ( & V_2 -> V_13 -> V_14 , L_8 ,
V_15 , 'A' + V_19 ) ;
V_12 = F_15 ( V_2 , V_19 ) ;
if ( V_12 < 0 )
goto V_77;
if ( V_12 >= 0 && V_12 < 14 ) {
V_55 -> V_35 [ V_19 ] . V_78 = V_12 ;
} else {
V_55 -> V_35 [ V_19 ] . V_78 = 0 ;
V_2 -> V_75 [ V_19 ] = 0 ;
continue;
}
V_55 -> V_60 |= 1 << V_19 ;
V_12 = F_11 ( V_2 , V_19 ) ;
if ( V_12 < 0 )
goto V_77;
F_8 ( & V_2 -> V_13 -> V_14 , L_9 ,
V_15 , V_12 ) ;
V_55 -> V_35 [ V_19 ] . V_66 = V_12 ;
V_12 = F_13 ( V_2 , V_19 ) ;
if ( V_12 < 0 )
goto V_77;
F_8 ( & V_2 -> V_13 -> V_14 , L_10 ,
V_15 , V_12 ) ;
V_55 -> V_35 [ V_19 ] . V_67 = V_12 ;
V_12 = F_14 ( V_2 , V_19 ) ;
if ( V_12 < 0 )
goto V_77;
F_8 ( & V_2 -> V_13 -> V_14 , L_11 ,
V_15 , V_12 ) ;
V_55 -> V_35 [ V_19 ] . V_68 = V_12 ;
F_17 ( V_24 , V_19 , V_55 -> V_35 [ V_19 ] . V_66 ,
V_55 -> V_35 [ V_19 ] . V_67 ,
V_55 -> V_35 [ V_19 ] . V_68 ,
V_55 -> V_35 [ V_19 ] . V_78 ) ;
}
V_12 = F_10 ( V_2 , 0x6d , 0x84 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ( V_12 & 0x60 ) == 0x20 ) {
V_55 -> V_64 = 1 ;
if ( ! V_55 -> V_65 )
V_55 -> V_65 = 1 ;
}
V_12 = F_7 ( V_2 , 0x07 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ( V_12 & 0x60 ) == 0x20 ) {
switch ( V_12 & 0x0c >> 2 ) {
case 0 :
V_55 -> V_61 = V_79 ;
break;
case 1 :
V_55 -> V_61 = V_80 ;
break;
case 2 :
V_55 -> V_61 = V_81 ;
break;
}
}
if ( ! ( V_12 & 0x10 ) ) {
switch ( V_12 & 0x3 ) {
case 0 :
V_55 -> V_63 = V_48 ;
break;
case 1 :
V_55 -> V_63 = V_49 ;
break;
case 2 :
V_55 -> V_63 = V_50 ;
break;
}
}
return 0 ;
V_77:
V_55 -> V_60 = 0 ;
return V_12 ;
}
static int F_19 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_54 * V_55 = & V_24 -> V_56 ;
int V_12 , V_20 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_2 -> V_82 != V_55 -> V_83 ) {
memset ( & V_55 -> V_84 , 0 , sizeof( V_55 -> V_84 ) ) ;
memset ( & V_55 -> V_85 , 0 , sizeof( V_55 -> V_85 ) ) ;
memset ( & V_55 -> V_86 , 0 , sizeof( V_55 -> V_86 ) ) ;
memset ( & V_55 -> V_87 , 0 , sizeof( V_55 -> V_87 ) ) ;
memset ( & V_55 -> V_88 , 0 , sizeof( V_55 -> V_88 ) ) ;
memset ( & V_55 -> V_89 , 0 , sizeof( V_55 -> V_89 ) ) ;
memset ( & V_55 -> V_90 , 0 , sizeof( V_55 -> V_90 ) ) ;
memset ( & V_55 -> V_91 , 0 , sizeof( V_55 -> V_91 ) ) ;
V_2 -> V_82 = V_55 -> V_83 ;
}
V_12 = F_20 ( V_2 , V_92 ) ;
if ( V_12 < 0 )
goto V_93;
V_12 = F_7 ( V_2 , 0x45 ) ;
if ( V_12 < 0 )
goto V_93;
V_20 = V_12 ;
V_12 = F_10 ( V_2 , 0x45 , V_20 | 0x10 ) ;
if ( V_12 < 0 )
goto V_93;
V_12 = F_10 ( V_2 , 0x45 , V_20 & 0x6f ) ;
if ( V_12 < 0 )
goto V_93;
V_12 = F_10 ( V_2 , 0x50 , 0x50 ) ;
if ( V_12 < 0 )
goto V_93;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
goto V_93;
V_20 = V_12 ;
V_12 = F_10 ( V_2 , 0x51 , V_20 | 0x01 ) ;
if ( V_12 < 0 )
goto V_93;
V_12 = F_10 ( V_2 , 0x51 , V_20 & 0x06 ) ;
if ( V_12 < 0 )
goto V_93;
goto V_94;
V_93:
F_3 ( & V_2 -> V_13 -> V_14 ,
L_12 ,
V_15 , V_12 ) ;
V_94:
return V_12 ;
}
static int F_21 ( struct V_23 * V_24 ,
unsigned V_35 ,
T_3 * error , T_3 * V_53 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
int V_12 , V_20 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_35 >= 3 )
return - V_36 ;
V_12 = F_7 ( V_2 , 0x54 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & ( 1 << V_35 ) ) ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_13 ,
V_15 , 'A' + V_35 ) ;
return - V_95 ;
}
V_12 = F_7 ( V_2 , 0x55 + V_35 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error = V_12 << 16 ;
V_12 = F_7 ( V_2 , 0x56 + V_35 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 << 8 ;
V_12 = F_7 ( V_2 , 0x57 + V_35 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_14 ,
V_15 , 'A' + V_35 , * error ) ;
V_12 = F_10 ( V_2 , 0x50 , 0xa7 + V_35 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_53 = V_12 << 16 ;
V_12 = F_10 ( V_2 , 0x50 , 0xa8 + V_35 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_53 |= V_12 << 8 ;
V_12 = F_10 ( V_2 , 0x50 , 0xa9 + V_35 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_53 |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_15 ,
V_15 , 'A' + V_35 , * V_53 ) ;
if ( V_2 -> V_75 [ V_35 ]
&& V_2 -> V_75 [ V_35 ] != * V_53 ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_16 ,
V_15 , 'A' + V_35 , V_2 -> V_75 [ V_35 ] ) ;
V_12 = F_10 ( V_2 , 0x52 , 0x00 ) ;
V_12 = F_10 ( V_2 , 0x50 , 0xa7 + V_35 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 ,
V_2 -> V_75 [ V_35 ] >> 16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x50 , 0xa8 + V_35 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 ,
V_2 -> V_75 [ V_35 ] >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x50 , 0xa9 + V_35 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 ,
V_2 -> V_75 [ V_35 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x52 , 0x01 ) ;
V_12 = F_10 ( V_2 , 0x53 , 0x00 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x53 , 0x07 ) ;
} else {
V_12 = F_7 ( V_2 , 0x53 ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = V_12 ;
V_12 = F_10 ( V_2 , 0x53 , V_20 & ~ ( 1 << V_35 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x53 , V_20 | ( 1 << V_35 ) ) ;
}
return V_12 ;
}
static int F_22 ( struct V_23 * V_24 ,
unsigned V_35 ,
T_3 * error , T_3 * V_53 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
T_3 V_96 , V_97 ;
int V_12 , V_20 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_35 >= 3 )
return - V_36 ;
V_12 = F_7 ( V_2 , 0x60 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & ( 1 << V_35 ) ) ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_17 ,
V_15 , 'A' + V_35 ) ;
return - V_95 ;
}
V_12 = F_7 ( V_2 , 0x64 + V_35 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error = V_12 << 16 ;
V_12 = F_7 ( V_2 , 0x65 + V_35 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 << 8 ;
V_12 = F_7 ( V_2 , 0x66 + V_35 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_18 ,
V_15 , 'A' + V_35 , * error ) ;
V_12 = F_10 ( V_2 , 0x50 , 0xdc + V_35 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_96 = V_12 << 8 ;
V_12 = F_10 ( V_2 , 0x50 , 0xdd + V_35 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_96 |= V_12 ;
* V_53 = V_96 * 204 * 8 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_19 ,
V_15 , 'A' + V_35 , * V_53 ) ;
if ( ! V_2 -> V_75 [ V_35 ] )
goto V_98;
V_97 = V_2 -> V_75 [ V_35 ] / 204 / 8 ;
if ( V_97 < 32 )
V_97 = 32 ;
if ( V_97 > 65535 )
V_97 = 65535 ;
if ( V_97 != V_96 ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_20 ,
V_15 , 'A' + V_35 , V_97 ) ;
V_12 = F_10 ( V_2 , 0x5e , 0x00 ) ;
V_12 = F_10 ( V_2 , 0x50 , 0xdc + V_35 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 , V_97 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x50 , 0xdd + V_35 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 , V_97 & 0xff ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x5e , 0x07 ) ;
V_12 = F_10 ( V_2 , 0x5f , 0x00 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x5f , 0x07 ) ;
return V_12 ;
}
V_98:
V_12 = F_7 ( V_2 , 0x5f ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = V_12 ;
V_12 = F_10 ( V_2 , 0x5f , V_20 & ~ ( 1 << V_35 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x5f , V_20 | ( 1 << V_35 ) ) ;
return V_12 ;
}
static int F_23 ( struct V_23 * V_24 ,
unsigned V_35 ,
T_3 * error , T_3 * V_53 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
int V_12 , V_20 ;
T_3 V_97 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_35 >= 3 )
return - V_36 ;
V_12 = F_10 ( V_2 , 0x50 , 0xb8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & ( 1 << V_35 ) ) ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_21 ,
V_15 , 'A' + V_35 ) ;
return - V_95 ;
}
V_12 = F_10 ( V_2 , 0x50 , 0xb9 + V_35 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* error = V_12 << 8 ;
V_12 = F_10 ( V_2 , 0x50 , 0xba + V_35 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* error |= V_12 ;
F_3 ( & V_2 -> V_13 -> V_14 , L_22 ,
V_15 , 'A' + V_35 , * error ) ;
V_12 = F_10 ( V_2 , 0x50 , 0xb2 + V_35 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_53 = V_12 << 8 ;
V_12 = F_10 ( V_2 , 0x50 , 0xb3 + V_35 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_53 |= V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_23 ,
V_15 , 'A' + V_35 , * V_53 ) ;
if ( ! V_2 -> V_75 [ V_35 ] )
goto V_98;
V_97 = V_2 -> V_75 [ V_35 ] / 204 / 8 ;
if ( V_97 < 32 )
V_97 = 32 ;
if ( V_97 > 65535 )
V_97 = 65535 ;
if ( V_97 != * V_53 ) {
F_8 ( & V_2 -> V_13 -> V_14 ,
L_24 ,
V_15 , 'A' + V_35 , V_97 ) ;
V_12 = F_10 ( V_2 , 0x50 , 0xb0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 , 0x00 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x50 , 0xb2 + V_35 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 , V_97 >> 8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x50 , 0xb3 + V_35 * 2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 , V_97 & 0xff ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x50 , 0xb0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 , 0x07 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x50 , 0xb1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 , 0x07 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 , 0x00 ) ;
return V_12 ;
}
V_98:
V_12 = F_10 ( V_2 , 0x50 , 0xb1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = V_12 ;
V_12 = F_10 ( V_2 , 0x51 , V_20 | ( 1 << V_35 ) ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 , V_20 & ~ ( 1 << V_35 ) ) ;
return V_12 ;
}
static T_3 F_24 ( T_3 V_99 , struct V_100 * V_101 ,
unsigned V_11 )
{
T_4 V_102 ;
T_3 V_103 , V_104 ;
int V_19 , V_105 ;
if ( V_99 >= V_101 [ 0 ] . V_106 )
return V_101 [ 0 ] . V_107 ;
if ( V_99 < V_101 [ V_11 - 1 ] . V_106 )
return V_101 [ V_11 - 1 ] . V_107 ;
for ( V_19 = 1 ; V_19 < V_11 - 1 ; V_19 ++ ) {
if ( V_99 == V_101 [ V_19 ] . V_106 )
return V_101 [ V_19 ] . V_107 ;
if ( V_99 > V_101 [ V_19 ] . V_106 )
break;
}
V_104 = V_101 [ V_19 ] . V_107 - V_101 [ V_19 - 1 ] . V_107 ;
V_103 = V_101 [ V_19 - 1 ] . V_106 - V_101 [ V_19 ] . V_106 ;
V_102 = V_99 - V_101 [ V_19 ] . V_106 ;
V_102 *= V_104 ;
F_25 ( V_102 , V_103 ) ;
V_105 = V_101 [ V_19 ] . V_107 - V_102 ;
return V_105 ;
}
static int F_26 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_54 * V_55 = & V_24 -> V_56 ;
T_3 V_108 , V_85 ;
int V_12 , V_20 ;
V_12 = F_7 ( V_2 , 0x45 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & 0x40 ) ) {
F_27 ( & V_2 -> V_13 -> V_14 , L_25 ,
V_15 ) ;
return - V_95 ;
}
V_20 = V_12 ;
V_12 = F_7 ( V_2 , 0x46 ) ;
if ( V_12 < 0 )
return V_12 ;
V_108 = V_12 << 8 ;
V_12 = F_7 ( V_2 , 0x46 ) ;
if ( V_12 < 0 )
return V_12 ;
V_108 |= V_12 ;
V_85 = F_24 ( V_108 ,
V_109 , F_12 ( V_109 ) ) ;
V_55 -> V_85 . V_110 [ 0 ] . V_111 = V_112 ;
V_55 -> V_85 . V_110 [ 0 ] . V_113 = V_85 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_26 ,
V_15 , V_85 / 1000 , V_85 % 1000 , V_108 ) ;
V_12 = F_10 ( V_2 , 0x45 , V_20 | 0x10 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x45 , V_20 & 0x6f ) ;
return V_12 ;
}
static int F_28 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_54 * V_55 = & V_24 -> V_56 ;
T_3 V_114 , V_85 ;
int V_12 , V_20 , V_19 ;
struct V_100 * V_115 ;
unsigned V_116 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
V_12 = F_10 ( V_2 , 0x50 , 0x5b ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_12 & 0x01 ) ) {
F_27 ( & V_2 -> V_13 -> V_14 ,
L_27 , V_15 ) ;
return - V_95 ;
}
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ ) {
if ( ! ( V_55 -> V_60 & ( 1 << V_19 ) ) ) {
V_55 -> V_85 . V_110 [ 1 + V_19 ] . V_111 = V_117 ;
continue;
}
V_12 = F_10 ( V_2 , 0x50 , 0x52 + V_19 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_114 = V_12 << 16 ;
V_12 = F_10 ( V_2 , 0x50 , 0x53 + V_19 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_114 |= V_12 << 8 ;
V_12 = F_10 ( V_2 , 0x50 , 0x54 + V_19 * 3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_114 |= V_12 ;
switch ( V_55 -> V_35 [ V_19 ] . V_66 ) {
case V_37 :
case V_38 :
V_115 = V_118 ;
V_116 = F_12 ( V_118 ) ;
break;
case V_39 :
V_115 = V_119 ;
V_116 = F_12 ( V_119 ) ;
break;
default:
case V_40 :
V_115 = V_120 ;
V_116 = F_12 ( V_120 ) ;
break;
}
V_85 = F_24 ( V_114 , V_115 , V_116 ) ;
V_55 -> V_85 . V_110 [ 1 + V_19 ] . V_111 = V_112 ;
V_55 -> V_85 . V_110 [ 1 + V_19 ] . V_113 = V_85 ;
F_8 ( & V_2 -> V_13 -> V_14 ,
L_28 ,
V_15 , 'A' + V_19 , V_85 / 1000 , V_85 % 1000 , V_114 ) ;
}
V_12 = F_10 ( V_2 , 0x50 , 0x50 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_7 ( V_2 , 0x51 ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = V_12 ;
V_12 = F_10 ( V_2 , 0x51 , V_20 | 0x01 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_2 , 0x51 , V_20 & 0x06 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static void F_29 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_54 * V_55 = & V_24 -> V_56 ;
int V_19 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
V_55 -> V_84 . V_11 = 1 ;
V_55 -> V_85 . V_11 = 4 ;
V_55 -> V_86 . V_11 = 4 ;
V_55 -> V_87 . V_11 = 4 ;
V_55 -> V_88 . V_11 = 4 ;
V_55 -> V_89 . V_11 = 4 ;
V_55 -> V_90 . V_11 = 4 ;
V_55 -> V_91 . V_11 = 4 ;
V_55 -> V_84 . V_110 [ 0 ] . V_111 = V_121 ;
V_55 -> V_84 . V_110 [ 0 ] . V_122 = 0 ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_55 -> V_85 . V_110 [ V_19 ] . V_111 = V_117 ;
V_55 -> V_86 . V_110 [ V_19 ] . V_111 = V_117 ;
V_55 -> V_87 . V_110 [ V_19 ] . V_111 = V_117 ;
V_55 -> V_88 . V_110 [ V_19 ] . V_111 = V_117 ;
V_55 -> V_89 . V_110 [ V_19 ] . V_111 = V_117 ;
V_55 -> V_90 . V_110 [ V_19 ] . V_111 = V_117 ;
V_55 -> V_91 . V_110 [ V_19 ] . V_111 = V_117 ;
}
}
static int F_30 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_54 * V_55 = & V_24 -> V_56 ;
int V_12 = 0 , V_19 ;
T_3 V_123 = 0 , V_124 = 0 ;
T_3 V_125 = 0 , V_126 = 0 ;
T_3 V_127 = 0 , V_128 = 0 ;
T_3 V_90 = 0 , V_91 = 0 ;
T_3 V_129 = 0 , V_130 = 0 ;
int V_131 = 0 , V_132 = 0 , V_133 = 0 ;
int V_134 = 0 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
F_26 ( V_24 ) ;
F_28 ( V_24 ) ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ ) {
if ( V_55 -> V_60 & ( 1 << V_19 ) ) {
V_131 ++ ;
V_12 = F_21 ( V_24 , V_19 ,
& V_123 , & V_124 ) ;
if ( V_12 >= 0 ) {
V_55 -> V_86 . V_110 [ 1 + V_19 ] . V_111 = V_135 ;
V_55 -> V_86 . V_110 [ 1 + V_19 ] . V_122 += V_123 ;
V_55 -> V_87 . V_110 [ 1 + V_19 ] . V_111 = V_135 ;
V_55 -> V_87 . V_110 [ 1 + V_19 ] . V_122 += V_124 ;
} else if ( V_12 != - V_95 ) {
V_55 -> V_86 . V_110 [ 1 + V_19 ] . V_111 = V_117 ;
V_55 -> V_87 . V_110 [ 1 + V_19 ] . V_111 = V_117 ;
F_3 ( & V_2 -> V_13 -> V_14 ,
L_29 ,
V_15 , 'A' + V_19 , V_12 ) ;
}
if ( V_55 -> V_90 . V_110 [ 1 + V_19 ] . V_111 != V_117 )
V_132 ++ ;
V_12 = F_22 ( V_24 , V_19 ,
& V_123 , & V_124 ) ;
if ( V_12 >= 0 ) {
V_55 -> V_88 . V_110 [ 1 + V_19 ] . V_111 = V_135 ;
V_55 -> V_88 . V_110 [ 1 + V_19 ] . V_122 += V_123 ;
V_55 -> V_89 . V_110 [ 1 + V_19 ] . V_111 = V_135 ;
V_55 -> V_89 . V_110 [ 1 + V_19 ] . V_122 += V_124 ;
} else if ( V_12 != - V_95 ) {
V_55 -> V_88 . V_110 [ 1 + V_19 ] . V_111 = V_117 ;
V_55 -> V_89 . V_110 [ 1 + V_19 ] . V_111 = V_117 ;
F_3 ( & V_2 -> V_13 -> V_14 ,
L_29 ,
V_15 , 'A' + V_19 , V_12 ) ;
}
if ( V_55 -> V_90 . V_110 [ 1 + V_19 ] . V_111 != V_117 )
V_133 ++ ;
V_12 = F_23 ( V_24 , V_19 ,
& V_90 ,
& V_91 ) ;
if ( V_12 >= 0 ) {
V_55 -> V_90 . V_110 [ 1 + V_19 ] . V_111 = V_135 ;
V_55 -> V_90 . V_110 [ 1 + V_19 ] . V_122 += V_90 ;
V_55 -> V_91 . V_110 [ 1 + V_19 ] . V_111 = V_135 ;
V_55 -> V_91 . V_110 [ 1 + V_19 ] . V_122 += V_91 ;
} else if ( V_12 != - V_95 ) {
V_55 -> V_90 . V_110 [ 1 + V_19 ] . V_111 = V_117 ;
V_55 -> V_91 . V_110 [ 1 + V_19 ] . V_111 = V_117 ;
F_3 ( & V_2 -> V_13 -> V_14 ,
L_30 ,
V_15 , 'A' + V_19 , V_12 ) ;
}
if ( V_55 -> V_90 . V_110 [ 1 + V_19 ] . V_111 != V_117 )
V_134 ++ ;
V_125 += V_55 -> V_86 . V_110 [ 1 + V_19 ] . V_122 ;
V_126 += V_55 -> V_87 . V_110 [ 1 + V_19 ] . V_122 ;
V_127 += V_55 -> V_88 . V_110 [ 1 + V_19 ] . V_122 ;
V_128 += V_55 -> V_89 . V_110 [ 1 + V_19 ] . V_122 ;
V_129 += V_55 -> V_90 . V_110 [ 1 + V_19 ] . V_122 ;
V_130 += V_55 -> V_91 . V_110 [ 1 + V_19 ] . V_122 ;
}
}
if ( V_132 ) {
V_55 -> V_86 . V_110 [ 0 ] . V_111 = V_135 ;
V_55 -> V_86 . V_110 [ 0 ] . V_122 = V_125 ;
V_55 -> V_87 . V_110 [ 0 ] . V_111 = V_135 ;
V_55 -> V_87 . V_110 [ 0 ] . V_122 = V_126 ;
} else {
V_55 -> V_86 . V_110 [ 0 ] . V_111 = V_117 ;
V_55 -> V_87 . V_110 [ 0 ] . V_111 = V_135 ;
}
if ( V_133 ) {
V_55 -> V_88 . V_110 [ 0 ] . V_111 = V_135 ;
V_55 -> V_88 . V_110 [ 0 ] . V_122 = V_127 ;
V_55 -> V_89 . V_110 [ 0 ] . V_111 = V_135 ;
V_55 -> V_89 . V_110 [ 0 ] . V_122 = V_128 ;
} else {
V_55 -> V_88 . V_110 [ 0 ] . V_111 = V_117 ;
V_55 -> V_89 . V_110 [ 0 ] . V_111 = V_135 ;
}
if ( V_134 ) {
V_55 -> V_90 . V_110 [ 0 ] . V_111 = V_135 ;
V_55 -> V_90 . V_110 [ 0 ] . V_122 = V_129 ;
V_55 -> V_91 . V_110 [ 0 ] . V_111 = V_135 ;
V_55 -> V_91 . V_110 [ 0 ] . V_122 = V_130 ;
} else {
V_55 -> V_90 . V_110 [ 0 ] . V_111 = V_117 ;
V_55 -> V_91 . V_110 [ 0 ] . V_111 = V_135 ;
}
return V_12 ;
}
static int F_31 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
int V_12 ;
T_1 V_136 = 1 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_24 -> V_137 . V_138 )
V_24 -> V_137 . V_138 ( V_24 , 0 ) ;
V_12 = F_20 ( V_2 , V_139 ) ;
if ( V_12 < 0 )
goto V_93;
if ( ! V_2 -> V_140 -> V_141 ) {
V_136 &= ~ 1 ;
V_12 = F_10 ( V_2 , 0x50 , 0xd5 ) ;
if ( V_12 < 0 )
goto V_93;
V_12 = F_10 ( V_2 , 0x51 , V_136 ) ;
if ( V_12 < 0 )
goto V_93;
}
V_93:
if ( V_24 -> V_137 . V_138 )
V_24 -> V_137 . V_138 ( V_24 , 1 ) ;
if ( V_12 < 0 ) {
V_2 -> V_142 = true ;
F_27 ( & V_2 -> V_13 -> V_14 ,
L_31 ) ;
} else {
V_2 -> V_142 = false ;
F_8 ( & V_2 -> V_13 -> V_14 , L_32 ) ;
}
return V_12 ;
}
static int F_32 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
int V_12 ;
#if 0
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
#endif
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_24 -> V_137 . V_138 )
V_24 -> V_137 . V_138 ( V_24 , 1 ) ;
V_24 -> V_137 . V_143 . V_144 ( V_24 ) ;
if ( V_2 -> V_142 )
F_31 ( V_24 ) ;
if ( V_24 -> V_137 . V_138 )
V_24 -> V_137 . V_138 ( V_24 , 0 ) ;
V_12 = F_20 ( V_2 , V_145 ) ;
F_19 ( V_24 ) ;
if ( V_24 -> V_137 . V_138 )
V_24 -> V_137 . V_138 ( V_24 , 1 ) ;
return V_12 ;
}
static int F_33 ( struct V_23 * V_24 ,
T_2 * V_25 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
struct V_54 * V_55 = & V_24 -> V_56 ;
int V_12 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_24 -> V_137 . V_138 )
V_24 -> V_137 . V_138 ( V_24 , 0 ) ;
V_12 = F_6 ( V_24 , V_25 ) ;
if ( ! ( * V_25 & V_31 ) ) {
F_29 ( V_24 ) ;
F_16 ( V_24 ) ;
}
if ( V_12 < 0 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_33 , V_15 ) ;
goto error;
}
V_12 = F_9 ( V_24 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_34 , V_15 ) ;
F_29 ( V_24 ) ;
F_16 ( V_24 ) ;
V_12 = 0 ;
goto error;
}
V_55 -> V_84 . V_110 [ 0 ] . V_122 = V_12 ;
if ( * V_25 & V_31 ) {
V_12 = F_18 ( V_24 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_35 , V_15 ) ;
V_12 = 0 ;
goto error;
}
V_12 = F_30 ( V_24 ) ;
if ( V_12 < 0 && V_12 != - V_95 ) {
F_3 ( & V_2 -> V_13 -> V_14 ,
L_36 , V_15 ) ;
V_12 = 0 ;
goto error;
}
V_12 = 0 ;
}
goto V_94;
error:
F_29 ( V_24 ) ;
V_94:
if ( V_24 -> V_137 . V_138 )
V_24 -> V_137 . V_138 ( V_24 , 1 ) ;
return V_12 ;
}
static int F_34 ( struct V_23 * V_24 ,
T_5 * V_84 )
{
struct V_54 * V_55 = & V_24 -> V_56 ;
* V_84 = V_55 -> V_84 . V_110 [ 0 ] . V_122 ;
return 0 ;
}
static int F_35 ( struct V_23 * V_24 )
{
return 0 ;
}
static int F_36 ( struct V_23 * V_24 ,
bool V_146 ,
unsigned int V_147 ,
unsigned int * V_148 ,
T_2 * V_25 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
int V_12 = 0 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
if ( V_146 )
V_12 = F_32 ( V_24 ) ;
if ( ! ( V_147 & V_149 ) )
F_33 ( V_24 , V_25 ) ;
return V_12 ;
}
static void F_37 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_26 ;
F_8 ( & V_2 -> V_13 -> V_14 , L_5 , V_15 ) ;
F_38 ( V_2 ) ;
}
struct V_23 * F_39 ( const struct V_150 * V_140 ,
struct V_151 * V_13 )
{
struct V_1 * V_2 ;
T_1 V_152 ;
F_8 ( & V_13 -> V_14 , L_5 , V_15 ) ;
V_2 = F_40 ( sizeof( struct V_1 ) , V_153 ) ;
if ( V_2 == NULL ) {
F_3 ( & V_13 -> V_14 ,
L_37 , V_15 ) ;
goto error;
}
V_2 -> V_140 = V_140 ;
V_2 -> V_13 = V_13 ;
memcpy ( & V_2 -> V_154 . V_137 , & V_155 ,
sizeof( struct V_156 ) ) ;
V_2 -> V_154 . V_26 = V_2 ;
V_152 = F_7 ( V_2 , 0 ) ;
if ( V_152 == 0x13 ) {
F_27 ( & V_13 -> V_14 ,
L_38 ) ;
} else {
F_8 ( & V_13 -> V_14 ,
L_39 ,
V_152 ) ;
goto error;
}
return & V_2 -> V_154 ;
error:
F_38 ( V_2 ) ;
return NULL ;
}
