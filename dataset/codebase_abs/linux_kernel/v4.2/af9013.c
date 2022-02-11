static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
const T_1 * V_5 , int V_6 )
{
int V_7 ;
T_1 V_8 [ V_9 ] ;
struct V_10 V_11 [ 1 ] = {
{
. V_12 = V_2 -> V_13 . V_14 ,
. V_15 = 0 ,
. V_6 = 3 + V_6 ,
. V_8 = V_8 ,
}
} ;
if ( 3 + V_6 > sizeof( V_8 ) ) {
F_2 ( & V_2 -> V_16 -> V_17 ,
L_1 ,
V_18 , V_4 , V_6 ) ;
return - V_19 ;
}
V_8 [ 0 ] = ( V_4 >> 8 ) & 0xff ;
V_8 [ 1 ] = ( V_4 >> 0 ) & 0xff ;
V_8 [ 2 ] = V_3 ;
memcpy ( & V_8 [ 3 ] , V_5 , V_6 ) ;
V_7 = F_3 ( V_2 -> V_16 , V_11 , 1 ) ;
if ( V_7 == 1 ) {
V_7 = 0 ;
} else {
F_2 ( & V_2 -> V_16 -> V_17 , L_2 \
L_3 , V_18 , V_7 , V_4 , V_6 ) ;
V_7 = - V_20 ;
}
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 * V_5 , int V_6 )
{
int V_7 ;
T_1 V_8 [ 3 ] ;
struct V_10 V_11 [ 2 ] = {
{
. V_12 = V_2 -> V_13 . V_14 ,
. V_15 = 0 ,
. V_6 = 3 ,
. V_8 = V_8 ,
} , {
. V_12 = V_2 -> V_13 . V_14 ,
. V_15 = V_21 ,
. V_6 = V_6 ,
. V_8 = V_5 ,
}
} ;
V_8 [ 0 ] = ( V_4 >> 8 ) & 0xff ;
V_8 [ 1 ] = ( V_4 >> 0 ) & 0xff ;
V_8 [ 2 ] = V_3 ;
V_7 = F_3 ( V_2 -> V_16 , V_11 , 2 ) ;
if ( V_7 == 2 ) {
V_7 = 0 ;
} else {
F_2 ( & V_2 -> V_16 -> V_17 , L_4 \
L_3 , V_18 , V_7 , V_4 , V_6 ) ;
V_7 = - V_20 ;
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_4 , const T_1 * V_5 ,
int V_6 )
{
int V_7 , V_22 ;
T_1 V_3 = ( 0 << 7 ) | ( 0 << 6 ) | ( 1 << 1 ) | ( 1 << 0 ) ;
if ( ( V_2 -> V_13 . V_23 == V_24 ) &&
( ( V_4 & 0xff00 ) != 0xff00 ) && ( ( V_4 & 0xff00 ) != 0xae00 ) ) {
V_3 |= ( ( V_6 - 1 ) << 2 ) ;
V_7 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
} else {
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ ) {
V_7 = F_1 ( V_2 , V_3 , V_4 + V_22 , V_5 + V_22 , 1 ) ;
if ( V_7 )
goto V_25;
}
}
V_25:
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_4 , T_1 * V_5 , int V_6 )
{
int V_7 , V_22 ;
T_1 V_3 = ( 0 << 7 ) | ( 0 << 6 ) | ( 1 << 1 ) | ( 0 << 0 ) ;
if ( ( V_2 -> V_13 . V_23 == V_24 ) &&
( ( V_4 & 0xff00 ) != 0xff00 ) && ( ( V_4 & 0xff00 ) != 0xae00 ) ) {
V_3 |= ( ( V_6 - 1 ) << 2 ) ;
V_7 = F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
} else {
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ ) {
V_7 = F_4 ( V_2 , V_3 , V_4 + V_22 , V_5 + V_22 , 1 ) ;
if ( V_7 )
goto V_25;
}
}
V_25:
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_5 )
{
return F_5 ( V_2 , V_4 , & V_5 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_4 , T_1 * V_5 )
{
return F_6 ( V_2 , V_4 , V_5 , 1 ) ;
}
static int F_9 ( struct V_1 * V_26 , T_2 V_4 , T_1 * V_5 ,
T_1 V_6 )
{
T_1 V_3 = ( 1 << 7 ) | ( 1 << 6 ) | ( ( V_6 - 1 ) << 2 ) | ( 1 << 1 ) | ( 1 << 0 ) ;
return F_1 ( V_26 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_10 ( struct V_1 * V_26 , T_2 V_4 , int V_27 ,
int V_6 , T_1 V_5 )
{
int V_7 ;
T_1 V_28 , V_29 ;
if ( V_6 != 8 ) {
V_7 = F_8 ( V_26 , V_4 , & V_28 ) ;
if ( V_7 )
return V_7 ;
V_29 = ( 0xff >> ( 8 - V_6 ) ) << V_27 ;
V_5 <<= V_27 ;
V_28 &= ~ V_29 ;
V_5 |= V_28 ;
}
return F_7 ( V_26 , V_4 , V_5 ) ;
}
static int F_11 ( struct V_1 * V_26 , T_2 V_4 , int V_27 ,
int V_6 , T_1 * V_5 )
{
int V_7 ;
T_1 V_28 ;
V_7 = F_8 ( V_26 , V_4 , & V_28 ) ;
if ( V_7 )
return V_7 ;
* V_5 = ( V_28 >> V_27 ) ;
* V_5 &= ( 0xff >> ( 8 - V_6 ) ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_26 , T_1 V_30 , T_1 V_31 )
{
int V_7 ;
T_1 V_27 ;
T_2 V_12 ;
F_13 ( & V_26 -> V_16 -> V_17 , L_5 ,
V_32 , V_30 , V_31 ) ;
switch ( V_30 ) {
case 0 :
case 1 :
V_12 = 0xd735 ;
break;
case 2 :
case 3 :
V_12 = 0xd736 ;
break;
default:
F_14 ( & V_26 -> V_16 -> V_17 , L_6 ,
V_18 , V_30 ) ;
V_7 = - V_19 ;
goto V_25;
}
switch ( V_30 ) {
case 0 :
case 2 :
V_27 = 0 ;
break;
case 1 :
case 3 :
default:
V_27 = 4 ;
break;
}
V_7 = F_10 ( V_26 , V_12 , V_27 , 4 , V_31 ) ;
if ( V_7 )
goto V_25;
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static T_3 F_15 ( struct V_1 * V_26 , T_3 V_33 , T_3 V_34 , T_3 V_35 )
{
T_3 V_36 = 0 , V_37 = 0 , V_22 ;
F_13 ( & V_26 -> V_16 -> V_17 , L_8 , V_32 , V_33 , V_34 , V_35 ) ;
if ( V_33 > V_34 ) {
V_37 = V_33 / V_34 ;
V_33 = V_33 - V_37 * V_34 ;
}
for ( V_22 = 0 ; V_22 < V_35 ; V_22 ++ ) {
if ( V_33 >= V_34 ) {
V_36 += 1 ;
V_33 -= V_34 ;
}
V_33 <<= 1 ;
V_36 <<= 1 ;
}
V_36 = ( V_37 << ( T_3 ) V_35 ) + V_36 ;
F_13 ( & V_26 -> V_16 -> V_17 , L_9 ,
V_32 , V_33 , V_34 , V_35 , V_36 , V_36 ) ;
return V_36 ;
}
static int F_16 ( struct V_1 * V_26 , T_1 V_38 )
{
int V_7 , V_22 ;
T_1 V_28 ;
F_13 ( & V_26 -> V_16 -> V_17 , L_10 , V_32 , V_38 ) ;
V_7 = F_10 ( V_26 , 0xd417 , 4 , 1 , 1 ) ;
if ( V_7 )
goto V_25;
V_7 = F_7 ( V_26 , 0xaeff , 1 ) ;
if ( V_7 )
goto V_25;
for ( V_22 = 0 ; V_22 < 150 ; V_22 ++ ) {
V_7 = F_11 ( V_26 , 0xd417 , 1 , 1 , & V_28 ) ;
if ( V_7 )
goto V_25;
if ( V_28 )
break;
F_17 ( 5000 , 25000 ) ;
}
if ( ! V_28 )
return - V_39 ;
if ( V_38 ) {
V_7 = F_10 ( V_26 , 0xd417 , 1 , 1 , 0 ) ;
if ( V_7 )
goto V_25;
V_7 = F_10 ( V_26 , 0xd417 , 4 , 1 , 0 ) ;
V_7 = F_10 ( V_26 , 0xd73a , 3 , 1 , 0 ) ;
} else {
V_7 = F_10 ( V_26 , 0xd73a , 3 , 1 , 1 ) ;
}
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static int F_18 ( struct V_40 * V_41 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
int V_7 ;
F_13 ( & V_26 -> V_16 -> V_17 , L_11 , V_32 ) ;
V_7 = F_10 ( V_26 , 0xd391 , 4 , 1 , 1 ) ;
if ( V_7 )
goto V_25;
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static int F_19 ( struct V_40 * V_41 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
int V_7 ;
T_1 V_8 [ 5 ] ;
F_13 ( & V_26 -> V_16 -> V_17 , L_11 , V_32 ) ;
V_7 = F_11 ( V_26 , 0xd391 , 4 , 1 , & V_8 [ 0 ] ) ;
if ( V_7 )
goto V_25;
if ( ! V_8 [ 0 ] ) {
F_13 ( & V_26 -> V_16 -> V_17 , L_12 , V_32 ) ;
return 0 ;
}
V_7 = F_6 ( V_26 , 0xd387 , V_8 , 5 ) ;
if ( V_7 )
goto V_25;
V_26 -> V_43 = ( V_8 [ 2 ] << 16 ) | ( V_8 [ 1 ] << 8 ) | V_8 [ 0 ] ;
V_26 -> V_44 += ( V_8 [ 4 ] << 8 ) | V_8 [ 3 ] ;
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static int F_20 ( struct V_40 * V_41 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
int V_7 ;
F_13 ( & V_26 -> V_16 -> V_17 , L_11 , V_32 ) ;
V_7 = F_10 ( V_26 , 0xd2e1 , 3 , 1 , 1 ) ;
if ( V_7 )
goto V_25;
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static int F_21 ( struct V_40 * V_41 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
int V_7 , V_22 , V_6 ;
T_1 V_8 [ 3 ] , V_28 ;
T_3 V_45 ;
const struct V_46 * V_47 ( V_48 ) ;
F_13 ( & V_26 -> V_16 -> V_17 , L_11 , V_32 ) ;
V_7 = F_11 ( V_26 , 0xd2e1 , 3 , 1 , & V_28 ) ;
if ( V_7 )
goto V_25;
if ( ! V_28 ) {
F_13 ( & V_26 -> V_16 -> V_17 , L_12 , V_32 ) ;
return 0 ;
}
V_7 = F_6 ( V_26 , 0xd2e3 , V_8 , 3 ) ;
if ( V_7 )
goto V_25;
V_45 = ( V_8 [ 2 ] << 16 ) | ( V_8 [ 1 ] << 8 ) | V_8 [ 0 ] ;
V_7 = F_8 ( V_26 , 0xd3c1 , & V_28 ) ;
if ( V_7 )
goto V_25;
switch ( ( V_28 >> 6 ) & 3 ) {
case 0 :
V_6 = F_22 ( V_49 ) ;
V_48 = V_49 ;
break;
case 1 :
V_6 = F_22 ( V_50 ) ;
V_48 = V_50 ;
break;
case 2 :
V_6 = F_22 ( V_51 ) ;
V_48 = V_51 ;
break;
default:
goto V_25;
}
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ ) {
V_28 = V_48 [ V_22 ] . V_52 ;
if ( V_45 < V_48 [ V_22 ] . V_5 )
break;
}
V_26 -> V_52 = V_28 * 10 ;
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static int F_23 ( struct V_40 * V_41 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
int V_7 = 0 ;
T_1 V_8 [ 2 ] , V_53 , V_54 ;
int V_55 ;
F_13 ( & V_26 -> V_16 -> V_17 , L_11 , V_32 ) ;
if ( ! V_26 -> V_56 )
return 0 ;
V_7 = F_6 ( V_26 , 0xd07c , V_8 , 2 ) ;
if ( V_7 )
goto V_25;
V_53 = V_8 [ 0 ] ;
V_54 = V_8 [ 1 ] ;
V_55 = ( 0xffff / \
( 9 * ( V_26 -> V_57 + V_26 -> V_58 ) - \
11 * ( V_26 -> V_59 + V_26 -> V_60 ) ) ) * \
( 10 * ( V_53 + V_54 ) - \
11 * ( V_26 -> V_59 + V_26 -> V_60 ) ) ;
if ( V_55 < 0 )
V_55 = 0 ;
else if ( V_55 > 0xffff )
V_55 = 0xffff ;
V_26 -> V_55 = V_55 ;
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static void F_24 ( struct V_61 * V_62 )
{
struct V_1 * V_26 = F_25 ( V_62 ,
struct V_1 , V_63 . V_62 ) ;
unsigned int V_64 ;
if ( ! ( V_26 -> V_65 & V_66 ) ) {
V_26 -> V_67 = 0 ;
V_26 -> V_43 = 0 ;
V_26 -> V_52 = 0 ;
}
switch ( V_26 -> V_67 ) {
default:
V_26 -> V_67 = 0 ;
case 0 :
F_23 ( & V_26 -> V_41 ) ;
V_26 -> V_67 ++ ;
V_64 = 300 ;
break;
case 1 :
F_20 ( & V_26 -> V_41 ) ;
V_26 -> V_67 ++ ;
V_64 = 200 ;
break;
case 2 :
F_18 ( & V_26 -> V_41 ) ;
V_26 -> V_67 ++ ;
V_64 = 1000 ;
break;
case 3 :
F_21 ( & V_26 -> V_41 ) ;
V_26 -> V_67 ++ ;
V_64 = 400 ;
break;
case 4 :
F_19 ( & V_26 -> V_41 ) ;
V_26 -> V_67 ++ ;
V_64 = 100 ;
break;
}
F_26 ( & V_26 -> V_63 ,
F_27 ( V_64 ) ) ;
}
static int F_28 ( struct V_40 * V_41 ,
struct V_68 * V_69 )
{
V_69 -> V_70 = 800 ;
V_69 -> V_71 = 0 ;
V_69 -> V_72 = 0 ;
return 0 ;
}
static int F_29 ( struct V_40 * V_41 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
struct V_73 * V_37 = & V_41 -> V_74 ;
int V_7 , V_22 , V_75 ;
bool V_76 , V_77 ;
T_1 V_8 [ 6 ] ;
T_3 V_78 , V_79 ;
F_13 ( & V_26 -> V_16 -> V_17 , L_13 ,
V_32 , V_37 -> V_80 , V_37 -> V_81 ) ;
if ( V_41 -> V_82 . V_83 . V_84 )
V_41 -> V_82 . V_83 . V_84 ( V_41 ) ;
if ( V_37 -> V_81 != V_26 -> V_81 ) {
for ( V_22 = 0 ; V_22 < F_22 ( V_85 ) ; V_22 ++ ) {
if ( V_85 [ V_22 ] . clock == V_26 -> V_13 . clock &&
V_85 [ V_22 ] . V_81 == V_37 -> V_81 ) {
break;
}
}
if ( V_22 == F_22 ( V_85 ) )
return - V_19 ;
V_7 = F_5 ( V_26 , 0xae00 , V_85 [ V_22 ] . V_5 ,
sizeof( V_85 [ V_22 ] . V_5 ) ) ;
}
if ( V_37 -> V_81 != V_26 -> V_81 || V_26 -> V_86 ) {
if ( V_41 -> V_82 . V_83 . V_87 )
V_41 -> V_82 . V_83 . V_87 ( V_41 , & V_78 ) ;
else
V_78 = V_26 -> V_13 . V_78 ;
F_13 ( & V_26 -> V_16 -> V_17 , L_14 ,
V_32 , V_78 ) ;
V_75 = V_78 ;
while ( V_75 > ( V_26 -> V_13 . clock / 2 ) )
V_75 -= V_26 -> V_13 . clock ;
if ( V_75 < 0 ) {
V_75 *= - 1 ;
V_77 = V_26 -> V_13 . V_77 ;
} else {
V_77 = ! V_26 -> V_13 . V_77 ;
}
V_79 = F_15 ( V_26 , V_75 , V_26 -> V_13 . clock ,
23 ) ;
if ( V_77 )
V_79 = 0x800000 - V_79 ;
V_8 [ 0 ] = ( V_79 >> 0 ) & 0xff ;
V_8 [ 1 ] = ( V_79 >> 8 ) & 0xff ;
V_8 [ 2 ] = ( V_79 >> 16 ) & 0x7f ;
V_79 = 0x800000 - V_79 ;
V_8 [ 3 ] = ( V_79 >> 0 ) & 0xff ;
V_8 [ 4 ] = ( V_79 >> 8 ) & 0xff ;
V_8 [ 5 ] = ( V_79 >> 16 ) & 0x7f ;
V_7 = F_5 ( V_26 , 0xd140 , V_8 , 3 ) ;
if ( V_7 )
goto V_25;
V_7 = F_5 ( V_26 , 0x9be7 , V_8 , 6 ) ;
if ( V_7 )
goto V_25;
}
V_7 = F_10 ( V_26 , 0xd330 , 3 , 1 , 1 ) ;
if ( V_7 )
goto V_25;
V_7 = F_10 ( V_26 , 0xd507 , 6 , 1 , 0 ) ;
if ( V_7 )
goto V_25;
V_7 = F_10 ( V_26 , 0x9bfe , 0 , 1 , 0 ) ;
if ( V_7 )
goto V_25;
V_7 = F_10 ( V_26 , 0x9bc2 , 0 , 1 , 0 ) ;
if ( V_7 )
goto V_25;
V_76 = false ;
memset ( V_8 , 0 , 3 ) ;
switch ( V_37 -> V_88 ) {
case V_89 :
V_76 = true ;
break;
case V_90 :
break;
case V_91 :
V_8 [ 0 ] |= ( 1 << 0 ) ;
break;
default:
F_13 ( & V_26 -> V_16 -> V_17 , L_15 ,
V_32 ) ;
V_76 = true ;
}
switch ( V_37 -> V_92 ) {
case V_93 :
V_76 = true ;
break;
case V_94 :
break;
case V_95 :
V_8 [ 0 ] |= ( 1 << 2 ) ;
break;
case V_96 :
V_8 [ 0 ] |= ( 2 << 2 ) ;
break;
case V_97 :
V_8 [ 0 ] |= ( 3 << 2 ) ;
break;
default:
F_13 ( & V_26 -> V_16 -> V_17 , L_16 ,
V_32 ) ;
V_76 = true ;
}
switch ( V_37 -> V_98 ) {
case V_99 :
V_76 = true ;
break;
case V_100 :
break;
case V_101 :
V_8 [ 0 ] |= ( 1 << 4 ) ;
break;
case V_102 :
V_8 [ 0 ] |= ( 2 << 4 ) ;
break;
case V_103 :
V_8 [ 0 ] |= ( 3 << 4 ) ;
break;
default:
F_13 ( & V_26 -> V_16 -> V_17 , L_17 , V_32 ) ;
V_76 = true ;
}
switch ( V_37 -> V_104 ) {
case V_105 :
V_76 = true ;
break;
case V_106 :
break;
case V_107 :
V_8 [ 1 ] |= ( 1 << 6 ) ;
break;
case V_108 :
V_8 [ 1 ] |= ( 2 << 6 ) ;
break;
default:
F_13 ( & V_26 -> V_16 -> V_17 , L_18 , V_32 ) ;
V_76 = true ;
}
V_8 [ 1 ] |= ( 1 << 4 ) ;
switch ( V_37 -> V_109 ) {
case V_110 :
V_76 = true ;
break;
case V_111 :
break;
case V_112 :
V_8 [ 2 ] |= ( 1 << 0 ) ;
break;
case V_113 :
V_8 [ 2 ] |= ( 2 << 0 ) ;
break;
case V_114 :
V_8 [ 2 ] |= ( 3 << 0 ) ;
break;
case V_115 :
V_8 [ 2 ] |= ( 4 << 0 ) ;
break;
default:
F_13 ( & V_26 -> V_16 -> V_17 , L_19 ,
V_32 ) ;
V_76 = true ;
}
switch ( V_37 -> V_116 ) {
case V_110 :
V_76 = true ;
break;
case V_111 :
break;
case V_112 :
V_8 [ 2 ] |= ( 1 << 3 ) ;
break;
case V_113 :
V_8 [ 2 ] |= ( 2 << 3 ) ;
break;
case V_114 :
V_8 [ 2 ] |= ( 3 << 3 ) ;
break;
case V_115 :
V_8 [ 2 ] |= ( 4 << 3 ) ;
break;
case V_117 :
break;
default:
F_13 ( & V_26 -> V_16 -> V_17 , L_20 ,
V_32 ) ;
V_76 = true ;
}
switch ( V_37 -> V_81 ) {
case 6000000 :
break;
case 7000000 :
V_8 [ 1 ] |= ( 1 << 2 ) ;
break;
case 8000000 :
V_8 [ 1 ] |= ( 2 << 2 ) ;
break;
default:
F_13 ( & V_26 -> V_16 -> V_17 , L_21 ,
V_32 ) ;
V_7 = - V_19 ;
goto V_25;
}
V_7 = F_5 ( V_26 , 0xd3c0 , V_8 , 3 ) ;
if ( V_7 )
goto V_25;
if ( V_76 ) {
V_7 = F_7 ( V_26 , 0xaefd , 0 ) ;
if ( V_7 )
goto V_25;
F_13 ( & V_26 -> V_16 -> V_17 , L_22 , V_32 ) ;
} else {
V_7 = F_7 ( V_26 , 0xaefd , 1 ) ;
if ( V_7 )
goto V_25;
V_7 = F_7 ( V_26 , 0xaefe , 0 ) ;
if ( V_7 )
goto V_25;
F_13 ( & V_26 -> V_16 -> V_17 , L_23 , V_32 ) ;
}
V_7 = F_7 ( V_26 , 0xffff , 0 ) ;
if ( V_7 )
goto V_25;
V_26 -> V_81 = V_37 -> V_81 ;
V_26 -> V_118 = V_119 ;
V_26 -> V_86 = false ;
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static int F_30 ( struct V_40 * V_41 )
{
struct V_73 * V_37 = & V_41 -> V_74 ;
struct V_1 * V_26 = V_41 -> V_42 ;
int V_7 ;
T_1 V_8 [ 3 ] ;
F_13 ( & V_26 -> V_16 -> V_17 , L_11 , V_32 ) ;
V_7 = F_6 ( V_26 , 0xd3c0 , V_8 , 3 ) ;
if ( V_7 )
goto V_25;
switch ( ( V_8 [ 1 ] >> 6 ) & 3 ) {
case 0 :
V_37 -> V_104 = V_106 ;
break;
case 1 :
V_37 -> V_104 = V_107 ;
break;
case 2 :
V_37 -> V_104 = V_108 ;
break;
}
switch ( ( V_8 [ 0 ] >> 0 ) & 3 ) {
case 0 :
V_37 -> V_88 = V_90 ;
break;
case 1 :
V_37 -> V_88 = V_91 ;
}
switch ( ( V_8 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_37 -> V_92 = V_94 ;
break;
case 1 :
V_37 -> V_92 = V_95 ;
break;
case 2 :
V_37 -> V_92 = V_96 ;
break;
case 3 :
V_37 -> V_92 = V_97 ;
break;
}
switch ( ( V_8 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_37 -> V_98 = V_100 ;
break;
case 1 :
V_37 -> V_98 = V_101 ;
break;
case 2 :
V_37 -> V_98 = V_102 ;
break;
case 3 :
V_37 -> V_98 = V_103 ;
break;
}
switch ( ( V_8 [ 2 ] >> 0 ) & 7 ) {
case 0 :
V_37 -> V_109 = V_111 ;
break;
case 1 :
V_37 -> V_109 = V_112 ;
break;
case 2 :
V_37 -> V_109 = V_113 ;
break;
case 3 :
V_37 -> V_109 = V_114 ;
break;
case 4 :
V_37 -> V_109 = V_115 ;
break;
}
switch ( ( V_8 [ 2 ] >> 3 ) & 7 ) {
case 0 :
V_37 -> V_116 = V_111 ;
break;
case 1 :
V_37 -> V_116 = V_112 ;
break;
case 2 :
V_37 -> V_116 = V_113 ;
break;
case 3 :
V_37 -> V_116 = V_114 ;
break;
case 4 :
V_37 -> V_116 = V_115 ;
break;
}
switch ( ( V_8 [ 1 ] >> 2 ) & 3 ) {
case 0 :
V_37 -> V_81 = 6000000 ;
break;
case 1 :
V_37 -> V_81 = 7000000 ;
break;
case 2 :
V_37 -> V_81 = 8000000 ;
break;
}
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static int F_31 ( struct V_40 * V_41 , enum V_65 * V_120 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
int V_7 ;
T_1 V_28 ;
if ( F_32 (
V_26 -> V_121 + F_27 ( 2000 ) ) &&
F_33 (
V_26 -> V_118 + F_27 ( 4000 ) )
) {
* V_120 = V_26 -> V_65 ;
return 0 ;
} else {
* V_120 = 0 ;
}
V_7 = F_11 ( V_26 , 0xd507 , 6 , 1 , & V_28 ) ;
if ( V_7 )
goto V_25;
if ( V_28 )
* V_120 |= V_122 | V_123 | V_124 |
V_125 | V_66 ;
if ( ! * V_120 ) {
V_7 = F_11 ( V_26 , 0xd330 , 3 , 1 , & V_28 ) ;
if ( V_7 )
goto V_25;
if ( V_28 )
* V_120 |= V_122 | V_123 |
V_124 ;
}
V_26 -> V_65 = * V_120 ;
V_26 -> V_121 = V_119 ;
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static int F_34 ( struct V_40 * V_41 , T_2 * V_52 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
* V_52 = V_26 -> V_52 ;
return 0 ;
}
static int F_35 ( struct V_40 * V_41 , T_2 * V_126 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
* V_126 = V_26 -> V_55 ;
return 0 ;
}
static int F_36 ( struct V_40 * V_41 , T_3 * V_43 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
* V_43 = V_26 -> V_43 ;
return 0 ;
}
static int F_37 ( struct V_40 * V_41 , T_3 * V_44 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
* V_44 = V_26 -> V_44 ;
return 0 ;
}
static int F_38 ( struct V_40 * V_41 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
int V_7 , V_22 , V_6 ;
T_1 V_8 [ 3 ] , V_28 ;
T_3 V_127 ;
const struct V_128 * V_129 ;
F_13 ( & V_26 -> V_16 -> V_17 , L_11 , V_32 ) ;
V_7 = F_16 ( V_26 , 1 ) ;
if ( V_7 )
goto V_25;
V_7 = F_7 ( V_26 , 0xd73a , 0xa4 ) ;
if ( V_7 )
goto V_25;
V_7 = F_5 ( V_26 , 0x9bf2 , V_26 -> V_13 . V_130 , 4 ) ;
if ( V_7 )
goto V_25;
switch ( V_26 -> V_13 . clock ) {
case 28800000 :
V_28 = 0 ;
break;
case 20480000 :
V_28 = 1 ;
break;
case 28000000 :
V_28 = 2 ;
break;
case 25000000 :
V_28 = 3 ;
break;
default:
F_14 ( & V_26 -> V_16 -> V_17 , L_24 ,
V_18 ) ;
return - V_19 ;
}
V_127 = F_15 ( V_26 , V_26 -> V_13 . clock , 1000000ul , 19 ) ;
V_8 [ 0 ] = ( V_127 >> 0 ) & 0xff ;
V_8 [ 1 ] = ( V_127 >> 8 ) & 0xff ;
V_8 [ 2 ] = ( V_127 >> 16 ) & 0xff ;
V_7 = F_5 ( V_26 , 0xd180 , V_8 , 3 ) ;
if ( V_7 )
goto V_25;
V_7 = F_10 ( V_26 , 0x9bd2 , 0 , 4 , V_28 ) ;
if ( V_7 )
goto V_25;
V_7 = F_7 ( V_26 , 0xd416 , 0x14 ) ;
if ( V_7 )
goto V_25;
V_7 = F_10 ( V_26 , 0xd700 , 1 , 1 , 1 ) ;
if ( V_7 )
goto V_25;
V_7 = F_10 ( V_26 , 0xd700 , 2 , 1 , 0 ) ;
if ( V_7 )
goto V_25;
V_7 = F_10 ( V_26 , 0xd371 , 1 , 1 , 1 ) ;
if ( V_7 )
goto V_25;
if ( V_26 -> V_13 . V_23 == V_24 ) {
V_7 = F_10 ( V_26 , 0xd50b , 2 , 1 , 1 ) ;
if ( V_7 )
goto V_25;
} else {
V_7 = F_10 ( V_26 , 0xd500 , 3 , 1 , 1 ) ;
if ( V_7 )
goto V_25;
V_7 = F_10 ( V_26 , 0xd502 , 4 , 1 , 1 ) ;
if ( V_7 )
goto V_25;
}
V_7 = F_10 ( V_26 , 0xd520 , 4 , 1 , 1 ) ;
if ( V_7 )
goto V_25;
F_13 ( & V_26 -> V_16 -> V_17 , L_25 , V_32 ) ;
V_6 = F_22 ( V_131 ) ;
V_129 = V_131 ;
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ ) {
V_7 = F_10 ( V_26 , V_129 [ V_22 ] . V_12 , V_129 [ V_22 ] . V_27 ,
V_129 [ V_22 ] . V_6 , V_129 [ V_22 ] . V_5 ) ;
if ( V_7 )
goto V_25;
}
F_13 ( & V_26 -> V_16 -> V_17 , L_26 ,
V_32 ) ;
switch ( V_26 -> V_13 . V_132 ) {
case V_133 :
V_6 = F_22 ( V_134 ) ;
V_129 = V_134 ;
break;
case V_135 :
case V_136 :
case V_137 :
V_6 = F_22 ( V_138 ) ;
V_129 = V_138 ;
break;
case V_139 :
V_6 = F_22 ( V_140 ) ;
V_129 = V_140 ;
break;
case V_141 :
V_6 = F_22 ( V_142 ) ;
V_129 = V_142 ;
break;
case V_143 :
V_6 = F_22 ( V_144 ) ;
V_129 = V_144 ;
break;
case V_145 :
case V_146 :
V_6 = F_22 ( V_147 ) ;
V_129 = V_147 ;
break;
case V_148 :
V_6 = F_22 ( V_149 ) ;
V_129 = V_149 ;
break;
case V_150 :
case V_151 :
V_6 = F_22 ( V_152 ) ;
V_129 = V_152 ;
break;
case V_153 :
default:
V_6 = F_22 ( V_154 ) ;
V_129 = V_154 ;
break;
}
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ ) {
V_7 = F_10 ( V_26 , V_129 [ V_22 ] . V_12 , V_129 [ V_22 ] . V_27 ,
V_129 [ V_22 ] . V_6 , V_129 [ V_22 ] . V_5 ) ;
if ( V_7 )
goto V_25;
}
V_7 = F_10 ( V_26 , 0xd500 , 1 , 2 , V_26 -> V_13 . V_23 ) ;
if ( V_7 )
goto V_25;
V_7 = F_10 ( V_26 , 0xd730 , 0 , 1 , 1 ) ;
if ( V_7 )
goto V_25;
if ( ! V_26 -> V_56 ) {
V_7 = F_11 ( V_26 , 0x9bee , 0 , 1 ,
& V_26 -> V_56 ) ;
if ( V_7 )
goto V_25;
}
if ( V_26 -> V_56 && ! V_26 -> V_57 ) {
V_7 = F_8 ( V_26 , 0x9bbd , & V_26 -> V_57 ) ;
if ( V_7 )
goto V_25;
V_7 = F_8 ( V_26 , 0x9bd0 , & V_26 -> V_59 ) ;
if ( V_7 )
goto V_25;
V_7 = F_8 ( V_26 , 0x9be2 , & V_26 -> V_58 ) ;
if ( V_7 )
goto V_25;
V_7 = F_8 ( V_26 , 0x9be4 , & V_26 -> V_60 ) ;
if ( V_7 )
goto V_25;
}
V_7 = F_7 ( V_26 , 0xd2e2 , 1 ) ;
if ( V_7 )
goto V_25;
V_8 [ 0 ] = ( 10000 >> 0 ) & 0xff ;
V_8 [ 1 ] = ( 10000 >> 8 ) & 0xff ;
V_7 = F_5 ( V_26 , 0xd385 , V_8 , 2 ) ;
if ( V_7 )
goto V_25;
V_7 = F_10 ( V_26 , 0xd392 , 1 , 1 , 1 ) ;
if ( V_7 )
goto V_25;
V_26 -> V_86 = true ;
F_26 ( & V_26 -> V_63 , F_27 ( 400 ) ) ;
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static int F_39 ( struct V_40 * V_41 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
int V_7 ;
F_13 ( & V_26 -> V_16 -> V_17 , L_11 , V_32 ) ;
F_40 ( & V_26 -> V_63 ) ;
V_7 = F_10 ( V_26 , 0xd730 , 0 , 1 , 0 ) ;
if ( V_7 )
goto V_25;
V_7 = F_16 ( V_26 , 0 ) ;
if ( V_7 )
goto V_25;
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static int F_41 ( struct V_40 * V_41 , int V_155 )
{
int V_7 ;
struct V_1 * V_26 = V_41 -> V_42 ;
F_13 ( & V_26 -> V_16 -> V_17 , L_27 , V_32 , V_155 ) ;
if ( V_26 -> V_156 == V_155 )
return 0 ;
if ( V_26 -> V_13 . V_23 == V_24 )
V_7 = F_10 ( V_26 , 0xd417 , 3 , 1 , V_155 ) ;
else
V_7 = F_10 ( V_26 , 0xd607 , 2 , 1 , V_155 ) ;
if ( V_7 )
goto V_25;
V_26 -> V_156 = V_155 ;
return V_7 ;
V_25:
F_13 ( & V_26 -> V_16 -> V_17 , L_7 , V_32 , V_7 ) ;
return V_7 ;
}
static void F_42 ( struct V_40 * V_41 )
{
struct V_1 * V_26 = V_41 -> V_42 ;
F_43 ( V_26 ) ;
}
static int F_44 ( struct V_1 * V_26 )
{
int V_22 , V_6 , V_157 , V_7 ;
const struct V_158 * V_159 ;
T_2 V_160 = 0 ;
T_1 V_5 ;
T_1 V_161 [ 4 ] ;
T_1 * V_162 = V_163 ;
F_45 ( 100 ) ;
V_7 = F_8 ( V_26 , 0x98be , & V_5 ) ;
if ( V_7 )
goto V_25;
else
F_13 ( & V_26 -> V_16 -> V_17 , L_28 ,
V_32 , V_5 ) ;
if ( V_5 == 0x0c )
goto exit;
F_46 ( & V_26 -> V_16 -> V_17 , L_29 \
L_30 ,
V_18 , V_164 . V_165 . V_166 ) ;
V_7 = F_47 ( & V_159 , V_162 , V_26 -> V_16 -> V_17 . V_167 ) ;
if ( V_7 ) {
F_46 ( & V_26 -> V_16 -> V_17 , L_31 \
L_32 \
L_33 ,
V_18 , V_162 , V_7 ) ;
goto V_25;
}
F_46 ( & V_26 -> V_16 -> V_17 , L_34 ,
V_18 , V_162 ) ;
for ( V_22 = 0 ; V_22 < V_159 -> V_168 ; V_22 ++ )
V_160 += V_159 -> V_169 [ V_22 ] ;
V_161 [ 0 ] = V_160 >> 8 ;
V_161 [ 1 ] = V_160 & 0xff ;
V_161 [ 2 ] = V_159 -> V_168 >> 8 ;
V_161 [ 3 ] = V_159 -> V_168 & 0xff ;
V_7 = F_9 ( V_26 , 0x50fc ,
V_161 , sizeof( V_161 ) ) ;
if ( V_7 )
goto V_170;
#define F_48 0x5100
#define F_49 16
for ( V_157 = V_159 -> V_168 ; V_157 > 0 ; V_157 -= F_49 ) {
V_6 = V_157 ;
if ( V_6 > F_49 )
V_6 = F_49 ;
V_7 = F_9 ( V_26 ,
F_48 + V_159 -> V_168 - V_157 ,
( T_1 * ) & V_159 -> V_169 [ V_159 -> V_168 - V_157 ] , V_6 ) ;
if ( V_7 ) {
F_14 ( & V_26 -> V_16 -> V_17 ,
L_35 ,
V_18 , V_7 ) ;
goto V_170;
}
}
V_7 = F_7 ( V_26 , 0xe205 , 1 ) ;
if ( V_7 )
goto V_170;
for ( V_22 = 0 ; V_22 < 15 ; V_22 ++ ) {
F_45 ( 100 ) ;
V_7 = F_8 ( V_26 , 0x98be , & V_5 ) ;
if ( V_7 )
goto V_170;
F_13 ( & V_26 -> V_16 -> V_17 , L_28 ,
V_32 , V_5 ) ;
if ( V_5 == 0x0c || V_5 == 0x04 )
break;
}
if ( V_5 == 0x04 ) {
F_14 ( & V_26 -> V_16 -> V_17 , L_36 ,
V_18 ) ;
V_7 = - V_171 ;
} else if ( V_5 != 0x0c ) {
F_14 ( & V_26 -> V_16 -> V_17 , L_37 ,
V_18 ) ;
V_7 = - V_171 ;
}
V_170:
F_50 ( V_159 ) ;
V_25:
exit:
if ( ! V_7 )
F_46 ( & V_26 -> V_16 -> V_17 , L_38 ,
V_18 , V_164 . V_165 . V_166 ) ;
return V_7 ;
}
struct V_40 * F_51 ( const struct V_172 * V_13 ,
struct V_173 * V_16 )
{
int V_7 ;
struct V_1 * V_26 = NULL ;
T_1 V_8 [ 4 ] , V_22 ;
V_26 = F_52 ( sizeof( struct V_1 ) , V_174 ) ;
if ( V_26 == NULL )
goto V_25;
V_26 -> V_16 = V_16 ;
memcpy ( & V_26 -> V_13 , V_13 , sizeof( struct V_172 ) ) ;
if ( V_26 -> V_13 . V_23 != V_24 ) {
V_7 = F_44 ( V_26 ) ;
if ( V_7 )
goto V_25;
}
V_7 = F_6 ( V_26 , 0x5103 , V_8 , 4 ) ;
if ( V_7 )
goto V_25;
F_46 ( & V_26 -> V_16 -> V_17 , L_39 ,
V_18 , V_8 [ 0 ] , V_8 [ 1 ] , V_8 [ 2 ] , V_8 [ 3 ] ) ;
for ( V_22 = 0 ; V_22 < sizeof( V_26 -> V_13 . V_30 ) ; V_22 ++ ) {
V_7 = F_12 ( V_26 , V_22 , V_26 -> V_13 . V_30 [ V_22 ] ) ;
if ( V_7 )
goto V_25;
}
memcpy ( & V_26 -> V_41 . V_82 , & V_164 ,
sizeof( struct V_175 ) ) ;
V_26 -> V_41 . V_42 = V_26 ;
F_53 ( & V_26 -> V_63 , F_24 ) ;
return & V_26 -> V_41 ;
V_25:
F_43 ( V_26 ) ;
return NULL ;
}
