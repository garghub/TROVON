static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
const T_1 * V_5 , int V_6 )
{
int V_7 ;
T_1 V_8 [ 3 + V_6 ] ;
struct V_9 V_10 [ 1 ] = {
{
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_6 = sizeof( V_8 ) ,
. V_8 = V_8 ,
}
} ;
V_8 [ 0 ] = ( V_4 >> 8 ) & 0xff ;
V_8 [ 1 ] = ( V_4 >> 0 ) & 0xff ;
V_8 [ 2 ] = V_3 ;
memcpy ( & V_8 [ 3 ] , V_5 , V_6 ) ;
V_7 = F_2 ( V_2 -> V_15 , V_10 , 1 ) ;
if ( V_7 == 1 ) {
V_7 = 0 ;
} else {
F_3 ( & V_2 -> V_15 -> V_16 , L_1 \
L_2 , V_17 , V_7 , V_4 , V_6 ) ;
V_7 = - V_18 ;
}
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 * V_5 , int V_6 )
{
int V_7 ;
T_1 V_8 [ 3 ] ;
struct V_9 V_10 [ 2 ] = {
{
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_6 = 3 ,
. V_8 = V_8 ,
} , {
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = V_19 ,
. V_6 = V_6 ,
. V_8 = V_5 ,
}
} ;
V_8 [ 0 ] = ( V_4 >> 8 ) & 0xff ;
V_8 [ 1 ] = ( V_4 >> 0 ) & 0xff ;
V_8 [ 2 ] = V_3 ;
V_7 = F_2 ( V_2 -> V_15 , V_10 , 2 ) ;
if ( V_7 == 2 ) {
V_7 = 0 ;
} else {
F_3 ( & V_2 -> V_15 -> V_16 , L_3 \
L_2 , V_17 , V_7 , V_4 , V_6 ) ;
V_7 = - V_18 ;
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_4 , const T_1 * V_5 ,
int V_6 )
{
int V_7 , V_20 ;
T_1 V_3 = ( 0 << 7 ) | ( 0 << 6 ) | ( 1 << 1 ) | ( 1 << 0 ) ;
if ( ( V_2 -> V_12 . V_21 == V_22 ) &&
( ( V_4 & 0xff00 ) != 0xff00 ) && ( ( V_4 & 0xff00 ) != 0xae00 ) ) {
V_3 |= ( ( V_6 - 1 ) << 2 ) ;
V_7 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
} else {
for ( V_20 = 0 ; V_20 < V_6 ; V_20 ++ ) {
V_7 = F_1 ( V_2 , V_3 , V_4 + V_20 , V_5 + V_20 , 1 ) ;
if ( V_7 )
goto V_23;
}
}
V_23:
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_4 , T_1 * V_5 , int V_6 )
{
int V_7 , V_20 ;
T_1 V_3 = ( 0 << 7 ) | ( 0 << 6 ) | ( 1 << 1 ) | ( 0 << 0 ) ;
if ( ( V_2 -> V_12 . V_21 == V_22 ) &&
( ( V_4 & 0xff00 ) != 0xff00 ) && ( ( V_4 & 0xff00 ) != 0xae00 ) ) {
V_3 |= ( ( V_6 - 1 ) << 2 ) ;
V_7 = F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
} else {
for ( V_20 = 0 ; V_20 < V_6 ; V_20 ++ ) {
V_7 = F_4 ( V_2 , V_3 , V_4 + V_20 , V_5 + V_20 , 1 ) ;
if ( V_7 )
goto V_23;
}
}
V_23:
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
static int F_9 ( struct V_1 * V_24 , T_2 V_4 , T_1 * V_5 ,
T_1 V_6 )
{
T_1 V_3 = ( 1 << 7 ) | ( 1 << 6 ) | ( ( V_6 - 1 ) << 2 ) | ( 1 << 1 ) | ( 1 << 0 ) ;
return F_1 ( V_24 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_10 ( struct V_1 * V_24 , T_2 V_4 , int V_25 ,
int V_6 , T_1 V_5 )
{
int V_7 ;
T_1 V_26 , V_27 ;
if ( V_6 != 8 ) {
V_7 = F_8 ( V_24 , V_4 , & V_26 ) ;
if ( V_7 )
return V_7 ;
V_27 = ( 0xff >> ( 8 - V_6 ) ) << V_25 ;
V_5 <<= V_25 ;
V_26 &= ~ V_27 ;
V_5 |= V_26 ;
}
return F_7 ( V_24 , V_4 , V_5 ) ;
}
static int F_11 ( struct V_1 * V_24 , T_2 V_4 , int V_25 ,
int V_6 , T_1 * V_5 )
{
int V_7 ;
T_1 V_26 ;
V_7 = F_8 ( V_24 , V_4 , & V_26 ) ;
if ( V_7 )
return V_7 ;
* V_5 = ( V_26 >> V_25 ) ;
* V_5 &= ( 0xff >> ( 8 - V_6 ) ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_24 , T_1 V_28 , T_1 V_29 )
{
int V_7 ;
T_1 V_25 ;
T_2 V_11 ;
F_13 ( & V_24 -> V_15 -> V_16 , L_4 ,
V_30 , V_28 , V_29 ) ;
switch ( V_28 ) {
case 0 :
case 1 :
V_11 = 0xd735 ;
break;
case 2 :
case 3 :
V_11 = 0xd736 ;
break;
default:
F_14 ( & V_24 -> V_15 -> V_16 , L_5 ,
V_17 , V_28 ) ;
V_7 = - V_31 ;
goto V_23;
}
switch ( V_28 ) {
case 0 :
case 2 :
V_25 = 0 ;
break;
case 1 :
case 3 :
default:
V_25 = 4 ;
break;
}
V_7 = F_10 ( V_24 , V_11 , V_25 , 4 , V_29 ) ;
if ( V_7 )
goto V_23;
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static T_3 F_15 ( struct V_1 * V_24 , T_3 V_32 , T_3 V_33 , T_3 V_34 )
{
T_3 V_35 = 0 , V_36 = 0 , V_20 ;
F_13 ( & V_24 -> V_15 -> V_16 , L_7 , V_30 , V_32 , V_33 , V_34 ) ;
if ( V_32 > V_33 ) {
V_36 = V_32 / V_33 ;
V_32 = V_32 - V_36 * V_33 ;
}
for ( V_20 = 0 ; V_20 < V_34 ; V_20 ++ ) {
if ( V_32 >= V_33 ) {
V_35 += 1 ;
V_32 -= V_33 ;
}
V_32 <<= 1 ;
V_35 <<= 1 ;
}
V_35 = ( V_36 << ( T_3 ) V_34 ) + V_35 ;
F_13 ( & V_24 -> V_15 -> V_16 , L_8 ,
V_30 , V_32 , V_33 , V_34 , V_35 , V_35 ) ;
return V_35 ;
}
static int F_16 ( struct V_1 * V_24 , T_1 V_37 )
{
int V_7 , V_20 ;
T_1 V_26 ;
F_13 ( & V_24 -> V_15 -> V_16 , L_9 , V_30 , V_37 ) ;
V_7 = F_10 ( V_24 , 0xd417 , 4 , 1 , 1 ) ;
if ( V_7 )
goto V_23;
V_7 = F_7 ( V_24 , 0xaeff , 1 ) ;
if ( V_7 )
goto V_23;
for ( V_20 = 0 ; V_20 < 150 ; V_20 ++ ) {
V_7 = F_11 ( V_24 , 0xd417 , 1 , 1 , & V_26 ) ;
if ( V_7 )
goto V_23;
if ( V_26 )
break;
F_17 ( 5000 , 25000 ) ;
}
if ( ! V_26 )
return - V_38 ;
if ( V_37 ) {
V_7 = F_10 ( V_24 , 0xd417 , 1 , 1 , 0 ) ;
if ( V_7 )
goto V_23;
V_7 = F_10 ( V_24 , 0xd417 , 4 , 1 , 0 ) ;
V_7 = F_10 ( V_24 , 0xd73a , 3 , 1 , 0 ) ;
} else {
V_7 = F_10 ( V_24 , 0xd73a , 3 , 1 , 1 ) ;
}
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static int F_18 ( struct V_39 * V_40 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
int V_7 ;
F_13 ( & V_24 -> V_15 -> V_16 , L_10 , V_30 ) ;
V_7 = F_10 ( V_24 , 0xd391 , 4 , 1 , 1 ) ;
if ( V_7 )
goto V_23;
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static int F_19 ( struct V_39 * V_40 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
int V_7 ;
T_1 V_8 [ 5 ] ;
F_13 ( & V_24 -> V_15 -> V_16 , L_10 , V_30 ) ;
V_7 = F_11 ( V_24 , 0xd391 , 4 , 1 , & V_8 [ 0 ] ) ;
if ( V_7 )
goto V_23;
if ( ! V_8 [ 0 ] ) {
F_13 ( & V_24 -> V_15 -> V_16 , L_11 , V_30 ) ;
return 0 ;
}
V_7 = F_6 ( V_24 , 0xd387 , V_8 , 5 ) ;
if ( V_7 )
goto V_23;
V_24 -> V_42 = ( V_8 [ 2 ] << 16 ) | ( V_8 [ 1 ] << 8 ) | V_8 [ 0 ] ;
V_24 -> V_43 += ( V_8 [ 4 ] << 8 ) | V_8 [ 3 ] ;
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static int F_20 ( struct V_39 * V_40 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
int V_7 ;
F_13 ( & V_24 -> V_15 -> V_16 , L_10 , V_30 ) ;
V_7 = F_10 ( V_24 , 0xd2e1 , 3 , 1 , 1 ) ;
if ( V_7 )
goto V_23;
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static int F_21 ( struct V_39 * V_40 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
int V_7 , V_20 , V_6 ;
T_1 V_8 [ 3 ] , V_26 ;
T_3 V_44 ;
const struct V_45 * V_46 ( V_47 ) ;
F_13 ( & V_24 -> V_15 -> V_16 , L_10 , V_30 ) ;
V_7 = F_11 ( V_24 , 0xd2e1 , 3 , 1 , & V_26 ) ;
if ( V_7 )
goto V_23;
if ( ! V_26 ) {
F_13 ( & V_24 -> V_15 -> V_16 , L_11 , V_30 ) ;
return 0 ;
}
V_7 = F_6 ( V_24 , 0xd2e3 , V_8 , 3 ) ;
if ( V_7 )
goto V_23;
V_44 = ( V_8 [ 2 ] << 16 ) | ( V_8 [ 1 ] << 8 ) | V_8 [ 0 ] ;
V_7 = F_8 ( V_24 , 0xd3c1 , & V_26 ) ;
if ( V_7 )
goto V_23;
switch ( ( V_26 >> 6 ) & 3 ) {
case 0 :
V_6 = F_22 ( V_48 ) ;
V_47 = V_48 ;
break;
case 1 :
V_6 = F_22 ( V_49 ) ;
V_47 = V_49 ;
break;
case 2 :
V_6 = F_22 ( V_50 ) ;
V_47 = V_50 ;
break;
default:
goto V_23;
break;
}
for ( V_20 = 0 ; V_20 < V_6 ; V_20 ++ ) {
V_26 = V_47 [ V_20 ] . V_51 ;
if ( V_44 < V_47 [ V_20 ] . V_5 )
break;
}
V_24 -> V_51 = V_26 * 10 ;
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static int F_23 ( struct V_39 * V_40 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
int V_7 = 0 ;
T_1 V_8 [ 2 ] , V_52 , V_53 ;
int V_54 ;
F_13 ( & V_24 -> V_15 -> V_16 , L_10 , V_30 ) ;
if ( ! V_24 -> V_55 )
return 0 ;
V_7 = F_6 ( V_24 , 0xd07c , V_8 , 2 ) ;
if ( V_7 )
goto V_23;
V_52 = V_8 [ 0 ] ;
V_53 = V_8 [ 1 ] ;
V_54 = ( 0xffff / \
( 9 * ( V_24 -> V_56 + V_24 -> V_57 ) - \
11 * ( V_24 -> V_58 + V_24 -> V_59 ) ) ) * \
( 10 * ( V_52 + V_53 ) - \
11 * ( V_24 -> V_58 + V_24 -> V_59 ) ) ;
if ( V_54 < 0 )
V_54 = 0 ;
else if ( V_54 > 0xffff )
V_54 = 0xffff ;
V_24 -> V_54 = V_54 ;
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static void F_24 ( struct V_60 * V_61 )
{
struct V_1 * V_24 = F_25 ( V_61 ,
struct V_1 , V_62 . V_61 ) ;
unsigned int V_63 ;
if ( ! ( V_24 -> V_64 & V_65 ) ) {
V_24 -> V_66 = 0 ;
V_24 -> V_42 = 0 ;
V_24 -> V_51 = 0 ;
}
switch ( V_24 -> V_66 ) {
default:
V_24 -> V_66 = 0 ;
case 0 :
F_23 ( & V_24 -> V_40 ) ;
V_24 -> V_66 ++ ;
V_63 = 300 ;
break;
case 1 :
F_20 ( & V_24 -> V_40 ) ;
V_24 -> V_66 ++ ;
V_63 = 200 ;
break;
case 2 :
F_18 ( & V_24 -> V_40 ) ;
V_24 -> V_66 ++ ;
V_63 = 1000 ;
break;
case 3 :
F_21 ( & V_24 -> V_40 ) ;
V_24 -> V_66 ++ ;
V_63 = 400 ;
break;
case 4 :
F_19 ( & V_24 -> V_40 ) ;
V_24 -> V_66 ++ ;
V_63 = 100 ;
break;
}
F_26 ( & V_24 -> V_62 ,
F_27 ( V_63 ) ) ;
}
static int F_28 ( struct V_39 * V_40 ,
struct V_67 * V_68 )
{
V_68 -> V_69 = 800 ;
V_68 -> V_70 = 0 ;
V_68 -> V_71 = 0 ;
return 0 ;
}
static int F_29 ( struct V_39 * V_40 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
struct V_72 * V_36 = & V_40 -> V_73 ;
int V_7 , V_20 , V_74 ;
bool V_75 , V_76 ;
T_1 V_8 [ 6 ] ;
T_3 V_77 , V_78 ;
F_13 ( & V_24 -> V_15 -> V_16 , L_12 ,
V_30 , V_36 -> V_79 , V_36 -> V_80 ) ;
if ( V_40 -> V_81 . V_82 . V_83 )
V_40 -> V_81 . V_82 . V_83 ( V_40 ) ;
if ( V_36 -> V_80 != V_24 -> V_80 ) {
for ( V_20 = 0 ; V_20 < F_22 ( V_84 ) ; V_20 ++ ) {
if ( V_84 [ V_20 ] . clock == V_24 -> V_12 . clock &&
V_84 [ V_20 ] . V_80 == V_36 -> V_80 ) {
break;
}
}
V_7 = F_5 ( V_24 , 0xae00 , V_84 [ V_20 ] . V_5 ,
sizeof( V_84 [ V_20 ] . V_5 ) ) ;
}
if ( V_36 -> V_80 != V_24 -> V_80 || V_24 -> V_85 ) {
if ( V_40 -> V_81 . V_82 . V_86 )
V_40 -> V_81 . V_82 . V_86 ( V_40 , & V_77 ) ;
else
V_77 = V_24 -> V_12 . V_77 ;
F_13 ( & V_24 -> V_15 -> V_16 , L_13 ,
V_30 , V_77 ) ;
V_74 = V_77 ;
while ( V_74 > ( V_24 -> V_12 . clock / 2 ) )
V_74 -= V_24 -> V_12 . clock ;
if ( V_74 < 0 ) {
V_74 *= - 1 ;
V_76 = V_24 -> V_12 . V_76 ;
} else {
V_76 = ! V_24 -> V_12 . V_76 ;
}
V_78 = F_15 ( V_24 , V_74 , V_24 -> V_12 . clock ,
23 ) ;
if ( V_76 )
V_78 = 0x800000 - V_78 ;
V_8 [ 0 ] = ( V_78 >> 0 ) & 0xff ;
V_8 [ 1 ] = ( V_78 >> 8 ) & 0xff ;
V_8 [ 2 ] = ( V_78 >> 16 ) & 0x7f ;
V_78 = 0x800000 - V_78 ;
V_8 [ 3 ] = ( V_78 >> 0 ) & 0xff ;
V_8 [ 4 ] = ( V_78 >> 8 ) & 0xff ;
V_8 [ 5 ] = ( V_78 >> 16 ) & 0x7f ;
V_7 = F_5 ( V_24 , 0xd140 , V_8 , 3 ) ;
if ( V_7 )
goto V_23;
V_7 = F_5 ( V_24 , 0x9be7 , V_8 , 6 ) ;
if ( V_7 )
goto V_23;
}
V_7 = F_10 ( V_24 , 0xd330 , 3 , 1 , 1 ) ;
if ( V_7 )
goto V_23;
V_7 = F_10 ( V_24 , 0xd507 , 6 , 1 , 0 ) ;
if ( V_7 )
goto V_23;
V_7 = F_10 ( V_24 , 0x9bfe , 0 , 1 , 0 ) ;
if ( V_7 )
goto V_23;
V_7 = F_10 ( V_24 , 0x9bc2 , 0 , 1 , 0 ) ;
if ( V_7 )
goto V_23;
V_75 = false ;
memset ( V_8 , 0 , 3 ) ;
switch ( V_36 -> V_87 ) {
case V_88 :
V_75 = 1 ;
break;
case V_89 :
break;
case V_90 :
V_8 [ 0 ] |= ( 1 << 0 ) ;
break;
default:
F_13 ( & V_24 -> V_15 -> V_16 , L_14 ,
V_30 ) ;
V_75 = 1 ;
}
switch ( V_36 -> V_91 ) {
case V_92 :
V_75 = 1 ;
break;
case V_93 :
break;
case V_94 :
V_8 [ 0 ] |= ( 1 << 2 ) ;
break;
case V_95 :
V_8 [ 0 ] |= ( 2 << 2 ) ;
break;
case V_96 :
V_8 [ 0 ] |= ( 3 << 2 ) ;
break;
default:
F_13 ( & V_24 -> V_15 -> V_16 , L_15 ,
V_30 ) ;
V_75 = 1 ;
}
switch ( V_36 -> V_97 ) {
case V_98 :
V_75 = 1 ;
break;
case V_99 :
break;
case V_100 :
V_8 [ 0 ] |= ( 1 << 4 ) ;
break;
case V_101 :
V_8 [ 0 ] |= ( 2 << 4 ) ;
break;
case V_102 :
V_8 [ 0 ] |= ( 3 << 4 ) ;
break;
default:
F_13 ( & V_24 -> V_15 -> V_16 , L_16 , V_30 ) ;
V_75 = 1 ;
}
switch ( V_36 -> V_103 ) {
case V_104 :
V_75 = 1 ;
break;
case V_105 :
break;
case V_106 :
V_8 [ 1 ] |= ( 1 << 6 ) ;
break;
case V_107 :
V_8 [ 1 ] |= ( 2 << 6 ) ;
break;
default:
F_13 ( & V_24 -> V_15 -> V_16 , L_17 , V_30 ) ;
V_75 = 1 ;
}
V_8 [ 1 ] |= ( 1 << 4 ) ;
switch ( V_36 -> V_108 ) {
case V_109 :
V_75 = 1 ;
break;
case V_110 :
break;
case V_111 :
V_8 [ 2 ] |= ( 1 << 0 ) ;
break;
case V_112 :
V_8 [ 2 ] |= ( 2 << 0 ) ;
break;
case V_113 :
V_8 [ 2 ] |= ( 3 << 0 ) ;
break;
case V_114 :
V_8 [ 2 ] |= ( 4 << 0 ) ;
break;
default:
F_13 ( & V_24 -> V_15 -> V_16 , L_18 ,
V_30 ) ;
V_75 = 1 ;
}
switch ( V_36 -> V_115 ) {
case V_109 :
V_75 = 1 ;
break;
case V_110 :
break;
case V_111 :
V_8 [ 2 ] |= ( 1 << 3 ) ;
break;
case V_112 :
V_8 [ 2 ] |= ( 2 << 3 ) ;
break;
case V_113 :
V_8 [ 2 ] |= ( 3 << 3 ) ;
break;
case V_114 :
V_8 [ 2 ] |= ( 4 << 3 ) ;
break;
case V_116 :
break;
default:
F_13 ( & V_24 -> V_15 -> V_16 , L_19 ,
V_30 ) ;
V_75 = 1 ;
}
switch ( V_36 -> V_80 ) {
case 6000000 :
break;
case 7000000 :
V_8 [ 1 ] |= ( 1 << 2 ) ;
break;
case 8000000 :
V_8 [ 1 ] |= ( 2 << 2 ) ;
break;
default:
F_13 ( & V_24 -> V_15 -> V_16 , L_20 ,
V_30 ) ;
V_7 = - V_31 ;
goto V_23;
}
V_7 = F_5 ( V_24 , 0xd3c0 , V_8 , 3 ) ;
if ( V_7 )
goto V_23;
if ( V_75 ) {
V_7 = F_7 ( V_24 , 0xaefd , 0 ) ;
if ( V_7 )
goto V_23;
F_13 ( & V_24 -> V_15 -> V_16 , L_21 , V_30 ) ;
} else {
V_7 = F_7 ( V_24 , 0xaefd , 1 ) ;
if ( V_7 )
goto V_23;
V_7 = F_7 ( V_24 , 0xaefe , 0 ) ;
if ( V_7 )
goto V_23;
F_13 ( & V_24 -> V_15 -> V_16 , L_22 , V_30 ) ;
}
V_7 = F_7 ( V_24 , 0xffff , 0 ) ;
if ( V_7 )
goto V_23;
V_24 -> V_80 = V_36 -> V_80 ;
V_24 -> V_117 = V_118 ;
V_24 -> V_85 = false ;
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static int F_30 ( struct V_39 * V_40 )
{
struct V_72 * V_36 = & V_40 -> V_73 ;
struct V_1 * V_24 = V_40 -> V_41 ;
int V_7 ;
T_1 V_8 [ 3 ] ;
F_13 ( & V_24 -> V_15 -> V_16 , L_10 , V_30 ) ;
V_7 = F_6 ( V_24 , 0xd3c0 , V_8 , 3 ) ;
if ( V_7 )
goto V_23;
switch ( ( V_8 [ 1 ] >> 6 ) & 3 ) {
case 0 :
V_36 -> V_103 = V_105 ;
break;
case 1 :
V_36 -> V_103 = V_106 ;
break;
case 2 :
V_36 -> V_103 = V_107 ;
break;
}
switch ( ( V_8 [ 0 ] >> 0 ) & 3 ) {
case 0 :
V_36 -> V_87 = V_89 ;
break;
case 1 :
V_36 -> V_87 = V_90 ;
}
switch ( ( V_8 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_36 -> V_91 = V_93 ;
break;
case 1 :
V_36 -> V_91 = V_94 ;
break;
case 2 :
V_36 -> V_91 = V_95 ;
break;
case 3 :
V_36 -> V_91 = V_96 ;
break;
}
switch ( ( V_8 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_36 -> V_97 = V_99 ;
break;
case 1 :
V_36 -> V_97 = V_100 ;
break;
case 2 :
V_36 -> V_97 = V_101 ;
break;
case 3 :
V_36 -> V_97 = V_102 ;
break;
}
switch ( ( V_8 [ 2 ] >> 0 ) & 7 ) {
case 0 :
V_36 -> V_108 = V_110 ;
break;
case 1 :
V_36 -> V_108 = V_111 ;
break;
case 2 :
V_36 -> V_108 = V_112 ;
break;
case 3 :
V_36 -> V_108 = V_113 ;
break;
case 4 :
V_36 -> V_108 = V_114 ;
break;
}
switch ( ( V_8 [ 2 ] >> 3 ) & 7 ) {
case 0 :
V_36 -> V_115 = V_110 ;
break;
case 1 :
V_36 -> V_115 = V_111 ;
break;
case 2 :
V_36 -> V_115 = V_112 ;
break;
case 3 :
V_36 -> V_115 = V_113 ;
break;
case 4 :
V_36 -> V_115 = V_114 ;
break;
}
switch ( ( V_8 [ 1 ] >> 2 ) & 3 ) {
case 0 :
V_36 -> V_80 = 6000000 ;
break;
case 1 :
V_36 -> V_80 = 7000000 ;
break;
case 2 :
V_36 -> V_80 = 8000000 ;
break;
}
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static int F_31 ( struct V_39 * V_40 , T_4 * V_119 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
int V_7 ;
T_1 V_26 ;
if ( F_32 (
V_24 -> V_120 + F_27 ( 2000 ) ) &&
F_33 (
V_24 -> V_117 + F_27 ( 4000 ) )
) {
* V_119 = V_24 -> V_64 ;
return 0 ;
} else {
* V_119 = 0 ;
}
V_7 = F_11 ( V_24 , 0xd507 , 6 , 1 , & V_26 ) ;
if ( V_7 )
goto V_23;
if ( V_26 )
* V_119 |= V_121 | V_122 | V_123 |
V_124 | V_65 ;
if ( ! * V_119 ) {
V_7 = F_11 ( V_24 , 0xd330 , 3 , 1 , & V_26 ) ;
if ( V_7 )
goto V_23;
if ( V_26 )
* V_119 |= V_121 | V_122 |
V_123 ;
}
V_24 -> V_64 = * V_119 ;
V_24 -> V_120 = V_118 ;
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static int F_34 ( struct V_39 * V_40 , T_2 * V_51 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
* V_51 = V_24 -> V_51 ;
return 0 ;
}
static int F_35 ( struct V_39 * V_40 , T_2 * V_125 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
* V_125 = V_24 -> V_54 ;
return 0 ;
}
static int F_36 ( struct V_39 * V_40 , T_3 * V_42 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
* V_42 = V_24 -> V_42 ;
return 0 ;
}
static int F_37 ( struct V_39 * V_40 , T_3 * V_43 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
* V_43 = V_24 -> V_43 ;
return 0 ;
}
static int F_38 ( struct V_39 * V_40 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
int V_7 , V_20 , V_6 ;
T_1 V_8 [ 3 ] , V_26 ;
T_3 V_126 ;
const struct V_127 * V_128 ;
F_13 ( & V_24 -> V_15 -> V_16 , L_10 , V_30 ) ;
V_7 = F_16 ( V_24 , 1 ) ;
if ( V_7 )
goto V_23;
V_7 = F_7 ( V_24 , 0xd73a , 0xa4 ) ;
if ( V_7 )
goto V_23;
V_7 = F_5 ( V_24 , 0x9bf2 , V_24 -> V_12 . V_129 , 4 ) ;
if ( V_7 )
goto V_23;
switch ( V_24 -> V_12 . clock ) {
case 28800000 :
V_26 = 0 ;
break;
case 20480000 :
V_26 = 1 ;
break;
case 28000000 :
V_26 = 2 ;
break;
case 25000000 :
V_26 = 3 ;
break;
default:
F_14 ( & V_24 -> V_15 -> V_16 , L_23 ,
V_17 ) ;
return - V_31 ;
}
V_126 = F_15 ( V_24 , V_24 -> V_12 . clock , 1000000ul , 19 ) ;
V_8 [ 0 ] = ( V_126 >> 0 ) & 0xff ;
V_8 [ 1 ] = ( V_126 >> 8 ) & 0xff ;
V_8 [ 2 ] = ( V_126 >> 16 ) & 0xff ;
V_7 = F_5 ( V_24 , 0xd180 , V_8 , 3 ) ;
if ( V_7 )
goto V_23;
V_7 = F_10 ( V_24 , 0x9bd2 , 0 , 4 , V_26 ) ;
if ( V_7 )
goto V_23;
V_7 = F_7 ( V_24 , 0xd416 , 0x14 ) ;
if ( V_7 )
goto V_23;
V_7 = F_10 ( V_24 , 0xd700 , 1 , 1 , 1 ) ;
if ( V_7 )
goto V_23;
V_7 = F_10 ( V_24 , 0xd700 , 2 , 1 , 0 ) ;
if ( V_7 )
goto V_23;
V_7 = F_10 ( V_24 , 0xd371 , 1 , 1 , 1 ) ;
if ( V_7 )
goto V_23;
if ( V_24 -> V_12 . V_21 == V_22 ) {
V_7 = F_10 ( V_24 , 0xd50b , 2 , 1 , 1 ) ;
if ( V_7 )
goto V_23;
} else {
V_7 = F_10 ( V_24 , 0xd500 , 3 , 1 , 1 ) ;
if ( V_7 )
goto V_23;
V_7 = F_10 ( V_24 , 0xd502 , 4 , 1 , 1 ) ;
if ( V_7 )
goto V_23;
}
V_7 = F_10 ( V_24 , 0xd520 , 4 , 1 , 1 ) ;
if ( V_7 )
goto V_23;
F_13 ( & V_24 -> V_15 -> V_16 , L_24 , V_30 ) ;
V_6 = F_22 ( V_130 ) ;
V_128 = V_130 ;
for ( V_20 = 0 ; V_20 < V_6 ; V_20 ++ ) {
V_7 = F_10 ( V_24 , V_128 [ V_20 ] . V_11 , V_128 [ V_20 ] . V_25 ,
V_128 [ V_20 ] . V_6 , V_128 [ V_20 ] . V_5 ) ;
if ( V_7 )
goto V_23;
}
F_13 ( & V_24 -> V_15 -> V_16 , L_25 ,
V_30 ) ;
switch ( V_24 -> V_12 . V_131 ) {
case V_132 :
V_6 = F_22 ( V_133 ) ;
V_128 = V_133 ;
break;
case V_134 :
case V_135 :
case V_136 :
V_6 = F_22 ( V_137 ) ;
V_128 = V_137 ;
break;
case V_138 :
V_6 = F_22 ( V_139 ) ;
V_128 = V_139 ;
break;
case V_140 :
V_6 = F_22 ( V_141 ) ;
V_128 = V_141 ;
break;
case V_142 :
V_6 = F_22 ( V_143 ) ;
V_128 = V_143 ;
break;
case V_144 :
case V_145 :
V_6 = F_22 ( V_146 ) ;
V_128 = V_146 ;
break;
case V_147 :
V_6 = F_22 ( V_148 ) ;
V_128 = V_148 ;
break;
case V_149 :
case V_150 :
V_6 = F_22 ( V_151 ) ;
V_128 = V_151 ;
break;
case V_152 :
default:
V_6 = F_22 ( V_153 ) ;
V_128 = V_153 ;
break;
}
for ( V_20 = 0 ; V_20 < V_6 ; V_20 ++ ) {
V_7 = F_10 ( V_24 , V_128 [ V_20 ] . V_11 , V_128 [ V_20 ] . V_25 ,
V_128 [ V_20 ] . V_6 , V_128 [ V_20 ] . V_5 ) ;
if ( V_7 )
goto V_23;
}
V_7 = F_10 ( V_24 , 0xd500 , 1 , 2 , V_24 -> V_12 . V_21 ) ;
if ( V_7 )
goto V_23;
V_7 = F_10 ( V_24 , 0xd730 , 0 , 1 , 1 ) ;
if ( V_7 )
goto V_23;
if ( ! V_24 -> V_55 ) {
V_7 = F_11 ( V_24 , 0x9bee , 0 , 1 ,
& V_24 -> V_55 ) ;
if ( V_7 )
goto V_23;
}
if ( V_24 -> V_55 && ! V_24 -> V_56 ) {
V_7 = F_8 ( V_24 , 0x9bbd , & V_24 -> V_56 ) ;
if ( V_7 )
goto V_23;
V_7 = F_8 ( V_24 , 0x9bd0 , & V_24 -> V_58 ) ;
if ( V_7 )
goto V_23;
V_7 = F_8 ( V_24 , 0x9be2 , & V_24 -> V_57 ) ;
if ( V_7 )
goto V_23;
V_7 = F_8 ( V_24 , 0x9be4 , & V_24 -> V_59 ) ;
if ( V_7 )
goto V_23;
}
V_7 = F_7 ( V_24 , 0xd2e2 , 1 ) ;
if ( V_7 )
goto V_23;
V_8 [ 0 ] = ( 10000 >> 0 ) & 0xff ;
V_8 [ 1 ] = ( 10000 >> 8 ) & 0xff ;
V_7 = F_5 ( V_24 , 0xd385 , V_8 , 2 ) ;
if ( V_7 )
goto V_23;
V_7 = F_10 ( V_24 , 0xd392 , 1 , 1 , 1 ) ;
if ( V_7 )
goto V_23;
V_24 -> V_85 = true ;
F_26 ( & V_24 -> V_62 , F_27 ( 400 ) ) ;
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static int F_39 ( struct V_39 * V_40 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
int V_7 ;
F_13 ( & V_24 -> V_15 -> V_16 , L_10 , V_30 ) ;
F_40 ( & V_24 -> V_62 ) ;
V_7 = F_10 ( V_24 , 0xd730 , 0 , 1 , 0 ) ;
if ( V_7 )
goto V_23;
V_7 = F_16 ( V_24 , 0 ) ;
if ( V_7 )
goto V_23;
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static int F_41 ( struct V_39 * V_40 , int V_154 )
{
int V_7 ;
struct V_1 * V_24 = V_40 -> V_41 ;
F_13 ( & V_24 -> V_15 -> V_16 , L_26 , V_30 , V_154 ) ;
if ( V_24 -> V_155 == V_154 )
return 0 ;
if ( V_24 -> V_12 . V_21 == V_22 )
V_7 = F_10 ( V_24 , 0xd417 , 3 , 1 , V_154 ) ;
else
V_7 = F_10 ( V_24 , 0xd607 , 2 , 1 , V_154 ) ;
if ( V_7 )
goto V_23;
V_24 -> V_155 = V_154 ;
return V_7 ;
V_23:
F_13 ( & V_24 -> V_15 -> V_16 , L_6 , V_30 , V_7 ) ;
return V_7 ;
}
static void F_42 ( struct V_39 * V_40 )
{
struct V_1 * V_24 = V_40 -> V_41 ;
F_43 ( V_24 ) ;
}
static int F_44 ( struct V_1 * V_24 )
{
int V_20 , V_6 , V_156 , V_7 ;
const struct V_157 * V_158 ;
T_2 V_159 = 0 ;
T_1 V_5 ;
T_1 V_160 [ 4 ] ;
T_1 * V_161 = V_162 ;
F_45 ( 100 ) ;
V_7 = F_8 ( V_24 , 0x98be , & V_5 ) ;
if ( V_7 )
goto V_23;
else
F_13 ( & V_24 -> V_15 -> V_16 , L_27 ,
V_30 , V_5 ) ;
if ( V_5 == 0x0c )
goto exit;
F_46 ( & V_24 -> V_15 -> V_16 , L_28 \
L_29 ,
V_17 , V_163 . V_164 . V_165 ) ;
V_7 = F_47 ( & V_158 , V_161 , V_24 -> V_15 -> V_16 . V_166 ) ;
if ( V_7 ) {
F_46 ( & V_24 -> V_15 -> V_16 , L_30 \
L_31 \
L_32 ,
V_17 , V_161 , V_7 ) ;
goto V_23;
}
F_46 ( & V_24 -> V_15 -> V_16 , L_33 ,
V_17 , V_161 ) ;
for ( V_20 = 0 ; V_20 < V_158 -> V_167 ; V_20 ++ )
V_159 += V_158 -> V_168 [ V_20 ] ;
V_160 [ 0 ] = V_159 >> 8 ;
V_160 [ 1 ] = V_159 & 0xff ;
V_160 [ 2 ] = V_158 -> V_167 >> 8 ;
V_160 [ 3 ] = V_158 -> V_167 & 0xff ;
V_7 = F_9 ( V_24 , 0x50fc ,
V_160 , sizeof( V_160 ) ) ;
if ( V_7 )
goto V_169;
#define F_48 0x5100
#define F_49 16
for ( V_156 = V_158 -> V_167 ; V_156 > 0 ; V_156 -= F_49 ) {
V_6 = V_156 ;
if ( V_6 > F_49 )
V_6 = F_49 ;
V_7 = F_9 ( V_24 ,
F_48 + V_158 -> V_167 - V_156 ,
( T_1 * ) & V_158 -> V_168 [ V_158 -> V_167 - V_156 ] , V_6 ) ;
if ( V_7 ) {
F_14 ( & V_24 -> V_15 -> V_16 ,
L_34 ,
V_17 , V_7 ) ;
goto V_169;
}
}
V_7 = F_7 ( V_24 , 0xe205 , 1 ) ;
if ( V_7 )
goto V_169;
for ( V_20 = 0 ; V_20 < 15 ; V_20 ++ ) {
F_45 ( 100 ) ;
V_7 = F_8 ( V_24 , 0x98be , & V_5 ) ;
if ( V_7 )
goto V_169;
F_13 ( & V_24 -> V_15 -> V_16 , L_27 ,
V_30 , V_5 ) ;
if ( V_5 == 0x0c || V_5 == 0x04 )
break;
}
if ( V_5 == 0x04 ) {
F_14 ( & V_24 -> V_15 -> V_16 , L_35 ,
V_17 ) ;
V_7 = - V_170 ;
} else if ( V_5 != 0x0c ) {
F_14 ( & V_24 -> V_15 -> V_16 , L_36 ,
V_17 ) ;
V_7 = - V_170 ;
}
V_169:
F_50 ( V_158 ) ;
V_23:
exit:
if ( ! V_7 )
F_46 ( & V_24 -> V_15 -> V_16 , L_37 ,
V_17 , V_163 . V_164 . V_165 ) ;
return V_7 ;
}
struct V_39 * F_51 ( const struct V_171 * V_12 ,
struct V_172 * V_15 )
{
int V_7 ;
struct V_1 * V_24 = NULL ;
T_1 V_8 [ 4 ] , V_20 ;
V_24 = F_52 ( sizeof( struct V_1 ) , V_173 ) ;
if ( V_24 == NULL )
goto V_23;
V_24 -> V_15 = V_15 ;
memcpy ( & V_24 -> V_12 , V_12 , sizeof( struct V_171 ) ) ;
if ( V_24 -> V_12 . V_21 != V_22 ) {
V_7 = F_44 ( V_24 ) ;
if ( V_7 )
goto V_23;
}
V_7 = F_6 ( V_24 , 0x5103 , V_8 , 4 ) ;
if ( V_7 )
goto V_23;
F_46 ( & V_24 -> V_15 -> V_16 , L_38 ,
V_17 , V_8 [ 0 ] , V_8 [ 1 ] , V_8 [ 2 ] , V_8 [ 3 ] ) ;
for ( V_20 = 0 ; V_20 < sizeof( V_24 -> V_12 . V_28 ) ; V_20 ++ ) {
V_7 = F_12 ( V_24 , V_20 , V_24 -> V_12 . V_28 [ V_20 ] ) ;
if ( V_7 )
goto V_23;
}
memcpy ( & V_24 -> V_40 . V_81 , & V_163 ,
sizeof( struct V_174 ) ) ;
V_24 -> V_40 . V_41 = V_24 ;
F_53 ( & V_24 -> V_62 , F_24 ) ;
return & V_24 -> V_40 ;
V_23:
F_43 ( V_24 ) ;
return NULL ;
}
