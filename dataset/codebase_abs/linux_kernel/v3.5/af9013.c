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
F_3 ( L_1 , V_7 , V_4 , V_6 ) ;
V_7 = - V_16 ;
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
. V_14 = V_17 ,
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
F_3 ( L_2 , V_7 , V_4 , V_6 ) ;
V_7 = - V_16 ;
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_4 , const T_1 * V_5 ,
int V_6 )
{
int V_7 , V_18 ;
T_1 V_3 = ( 0 << 7 ) | ( 0 << 6 ) | ( 1 << 1 ) | ( 1 << 0 ) ;
if ( ( V_2 -> V_12 . V_19 == V_20 ) &&
( ( V_4 & 0xff00 ) != 0xff00 ) && ( ( V_4 & 0xff00 ) != 0xae00 ) ) {
V_3 |= ( ( V_6 - 1 ) << 2 ) ;
V_7 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
} else {
for ( V_18 = 0 ; V_18 < V_6 ; V_18 ++ ) {
V_7 = F_1 ( V_2 , V_3 , V_4 + V_18 , V_5 + V_18 , 1 ) ;
if ( V_7 )
goto V_21;
}
}
V_21:
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_4 , T_1 * V_5 , int V_6 )
{
int V_7 , V_18 ;
T_1 V_3 = ( 0 << 7 ) | ( 0 << 6 ) | ( 1 << 1 ) | ( 0 << 0 ) ;
if ( ( V_2 -> V_12 . V_19 == V_20 ) &&
( ( V_4 & 0xff00 ) != 0xff00 ) && ( ( V_4 & 0xff00 ) != 0xae00 ) ) {
V_3 |= ( ( V_6 - 1 ) << 2 ) ;
V_7 = F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
} else {
for ( V_18 = 0 ; V_18 < V_6 ; V_18 ++ ) {
V_7 = F_4 ( V_2 , V_3 , V_4 + V_18 , V_5 + V_18 , 1 ) ;
if ( V_7 )
goto V_21;
}
}
V_21:
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
static int F_9 ( struct V_1 * V_22 , T_2 V_4 , T_1 * V_5 ,
T_1 V_6 )
{
T_1 V_3 = ( 1 << 7 ) | ( 1 << 6 ) | ( ( V_6 - 1 ) << 2 ) | ( 1 << 1 ) | ( 1 << 0 ) ;
return F_1 ( V_22 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_10 ( struct V_1 * V_22 , T_2 V_4 , int V_23 ,
int V_6 , T_1 V_5 )
{
int V_7 ;
T_1 V_24 , V_25 ;
if ( V_6 != 8 ) {
V_7 = F_8 ( V_22 , V_4 , & V_24 ) ;
if ( V_7 )
return V_7 ;
V_25 = ( 0xff >> ( 8 - V_6 ) ) << V_23 ;
V_5 <<= V_23 ;
V_24 &= ~ V_25 ;
V_5 |= V_24 ;
}
return F_7 ( V_22 , V_4 , V_5 ) ;
}
static int F_11 ( struct V_1 * V_22 , T_2 V_4 , int V_23 ,
int V_6 , T_1 * V_5 )
{
int V_7 ;
T_1 V_24 ;
V_7 = F_8 ( V_22 , V_4 , & V_24 ) ;
if ( V_7 )
return V_7 ;
* V_5 = ( V_24 >> V_23 ) ;
* V_5 &= ( 0xff >> ( 8 - V_6 ) ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_22 , T_1 V_26 , T_1 V_27 )
{
int V_7 ;
T_1 V_23 ;
T_2 V_11 ;
F_13 ( L_3 , V_28 , V_26 , V_27 ) ;
switch ( V_26 ) {
case 0 :
case 1 :
V_11 = 0xd735 ;
break;
case 2 :
case 3 :
V_11 = 0xd736 ;
break;
default:
V_21 ( L_4 , V_26 ) ;
V_7 = - V_29 ;
goto V_21;
} ;
switch ( V_26 ) {
case 0 :
case 2 :
V_23 = 0 ;
break;
case 1 :
case 3 :
default:
V_23 = 4 ;
break;
} ;
V_7 = F_10 ( V_22 , V_11 , V_23 , 4 , V_27 ) ;
if ( V_7 )
goto V_21;
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static T_3 F_14 ( T_3 V_30 , T_3 V_31 , T_3 V_32 )
{
T_3 V_33 = 0 , V_34 = 0 , V_18 ;
F_13 ( L_6 , V_28 , V_30 , V_31 , V_32 ) ;
if ( V_30 > V_31 ) {
V_34 = V_30 / V_31 ;
V_30 = V_30 - V_34 * V_31 ;
}
for ( V_18 = 0 ; V_18 < V_32 ; V_18 ++ ) {
if ( V_30 >= V_31 ) {
V_33 += 1 ;
V_30 -= V_31 ;
}
V_30 <<= 1 ;
V_33 <<= 1 ;
}
V_33 = ( V_34 << ( T_3 ) V_32 ) + V_33 ;
F_13 ( L_7 , V_28 , V_30 , V_31 , V_32 , V_33 ) ;
return V_33 ;
}
static int F_15 ( struct V_1 * V_22 , T_1 V_35 )
{
int V_7 , V_18 ;
T_1 V_24 ;
F_13 ( L_8 , V_28 , V_35 ) ;
V_7 = F_10 ( V_22 , 0xd417 , 4 , 1 , 1 ) ;
if ( V_7 )
goto V_21;
V_7 = F_7 ( V_22 , 0xaeff , 1 ) ;
if ( V_7 )
goto V_21;
for ( V_18 = 0 ; V_18 < 150 ; V_18 ++ ) {
V_7 = F_11 ( V_22 , 0xd417 , 1 , 1 , & V_24 ) ;
if ( V_7 )
goto V_21;
if ( V_24 )
break;
F_16 ( 5000 , 25000 ) ;
}
if ( ! V_24 )
return - V_36 ;
if ( V_35 ) {
V_7 = F_10 ( V_22 , 0xd417 , 1 , 1 , 0 ) ;
if ( V_7 )
goto V_21;
V_7 = F_10 ( V_22 , 0xd417 , 4 , 1 , 0 ) ;
V_7 = F_10 ( V_22 , 0xd73a , 3 , 1 , 0 ) ;
} else {
V_7 = F_10 ( V_22 , 0xd73a , 3 , 1 , 1 ) ;
}
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static int F_17 ( struct V_37 * V_38 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
int V_7 ;
F_13 ( L_9 , V_28 ) ;
V_7 = F_10 ( V_22 , 0xd391 , 4 , 1 , 1 ) ;
if ( V_7 )
goto V_21;
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static int F_18 ( struct V_37 * V_38 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
int V_7 ;
T_1 V_8 [ 5 ] ;
F_13 ( L_9 , V_28 ) ;
V_7 = F_11 ( V_22 , 0xd391 , 4 , 1 , & V_8 [ 0 ] ) ;
if ( V_7 )
goto V_21;
if ( ! V_8 [ 0 ] ) {
F_13 ( L_10 , V_28 ) ;
return 0 ;
}
V_7 = F_6 ( V_22 , 0xd387 , V_8 , 5 ) ;
if ( V_7 )
goto V_21;
V_22 -> V_40 = ( V_8 [ 2 ] << 16 ) | ( V_8 [ 1 ] << 8 ) | V_8 [ 0 ] ;
V_22 -> V_41 += ( V_8 [ 4 ] << 8 ) | V_8 [ 3 ] ;
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static int F_19 ( struct V_37 * V_38 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
int V_7 ;
F_13 ( L_9 , V_28 ) ;
V_7 = F_10 ( V_22 , 0xd2e1 , 3 , 1 , 1 ) ;
if ( V_7 )
goto V_21;
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static int F_20 ( struct V_37 * V_38 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
int V_7 , V_18 , V_6 ;
T_1 V_8 [ 3 ] , V_24 ;
T_3 V_42 ;
const struct V_43 * V_44 ( V_45 ) ;
F_13 ( L_9 , V_28 ) ;
V_7 = F_11 ( V_22 , 0xd2e1 , 3 , 1 , & V_24 ) ;
if ( V_7 )
goto V_21;
if ( ! V_24 ) {
F_13 ( L_10 , V_28 ) ;
return 0 ;
}
V_7 = F_6 ( V_22 , 0xd2e3 , V_8 , 3 ) ;
if ( V_7 )
goto V_21;
V_42 = ( V_8 [ 2 ] << 16 ) | ( V_8 [ 1 ] << 8 ) | V_8 [ 0 ] ;
V_7 = F_8 ( V_22 , 0xd3c1 , & V_24 ) ;
if ( V_7 )
goto V_21;
switch ( ( V_24 >> 6 ) & 3 ) {
case 0 :
V_6 = F_21 ( V_46 ) ;
V_45 = V_46 ;
break;
case 1 :
V_6 = F_21 ( V_47 ) ;
V_45 = V_47 ;
break;
case 2 :
V_6 = F_21 ( V_48 ) ;
V_45 = V_48 ;
break;
default:
goto V_21;
break;
}
for ( V_18 = 0 ; V_18 < V_6 ; V_18 ++ ) {
V_24 = V_45 [ V_18 ] . V_49 ;
if ( V_42 < V_45 [ V_18 ] . V_5 )
break;
}
V_22 -> V_49 = V_24 * 10 ;
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static int F_22 ( struct V_37 * V_38 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
int V_7 = 0 ;
T_1 V_8 [ 2 ] , V_50 , V_51 ;
int V_52 ;
F_13 ( L_9 , V_28 ) ;
if ( ! V_22 -> V_53 )
return 0 ;
V_7 = F_6 ( V_22 , 0xd07c , V_8 , 2 ) ;
if ( V_7 )
goto V_21;
V_50 = V_8 [ 0 ] ;
V_51 = V_8 [ 1 ] ;
V_52 = ( 0xffff / \
( 9 * ( V_22 -> V_54 + V_22 -> V_55 ) - \
11 * ( V_22 -> V_56 + V_22 -> V_57 ) ) ) * \
( 10 * ( V_50 + V_51 ) - \
11 * ( V_22 -> V_56 + V_22 -> V_57 ) ) ;
if ( V_52 < 0 )
V_52 = 0 ;
else if ( V_52 > 0xffff )
V_52 = 0xffff ;
V_22 -> V_52 = V_52 ;
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static void F_23 ( struct V_58 * V_59 )
{
struct V_1 * V_22 = F_24 ( V_59 ,
struct V_1 , V_60 . V_59 ) ;
unsigned int V_61 ;
if ( ! ( V_22 -> V_62 & V_63 ) ) {
V_22 -> V_64 = 0 ;
V_22 -> V_40 = 0 ;
V_22 -> V_49 = 0 ;
}
switch ( V_22 -> V_64 ) {
default:
V_22 -> V_64 = 0 ;
case 0 :
F_22 ( & V_22 -> V_38 ) ;
V_22 -> V_64 ++ ;
V_61 = 300 ;
break;
case 1 :
F_19 ( & V_22 -> V_38 ) ;
V_22 -> V_64 ++ ;
V_61 = 200 ;
break;
case 2 :
F_17 ( & V_22 -> V_38 ) ;
V_22 -> V_64 ++ ;
V_61 = 1000 ;
break;
case 3 :
F_20 ( & V_22 -> V_38 ) ;
V_22 -> V_64 ++ ;
V_61 = 400 ;
break;
case 4 :
F_18 ( & V_22 -> V_38 ) ;
V_22 -> V_64 ++ ;
V_61 = 100 ;
break;
}
F_25 ( & V_22 -> V_60 ,
F_26 ( V_61 ) ) ;
}
static int F_27 ( struct V_37 * V_38 ,
struct V_65 * V_66 )
{
V_66 -> V_67 = 800 ;
V_66 -> V_68 = 0 ;
V_66 -> V_69 = 0 ;
return 0 ;
}
static int F_28 ( struct V_37 * V_38 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
struct V_70 * V_34 = & V_38 -> V_71 ;
int V_7 , V_18 , V_72 ;
bool V_73 , V_74 ;
T_1 V_8 [ 6 ] ;
T_3 V_75 , V_76 ;
F_13 ( L_11 , V_28 ,
V_34 -> V_77 , V_34 -> V_78 ) ;
if ( V_38 -> V_79 . V_80 . V_81 )
V_38 -> V_79 . V_80 . V_81 ( V_38 ) ;
if ( V_34 -> V_78 != V_22 -> V_78 ) {
for ( V_18 = 0 ; V_18 < F_21 ( V_82 ) ; V_18 ++ ) {
if ( V_82 [ V_18 ] . clock == V_22 -> V_12 . clock &&
V_82 [ V_18 ] . V_78 == V_34 -> V_78 ) {
break;
}
}
V_7 = F_5 ( V_22 , 0xae00 , V_82 [ V_18 ] . V_5 ,
sizeof( V_82 [ V_18 ] . V_5 ) ) ;
}
if ( V_34 -> V_78 != V_22 -> V_78 || V_22 -> V_83 ) {
if ( V_38 -> V_79 . V_80 . V_84 )
V_38 -> V_79 . V_80 . V_84 ( V_38 , & V_75 ) ;
else
V_75 = V_22 -> V_12 . V_75 ;
V_72 = V_75 ;
while ( V_72 > ( V_22 -> V_12 . clock / 2 ) )
V_72 -= V_22 -> V_12 . clock ;
if ( V_72 < 0 ) {
V_72 *= - 1 ;
V_74 = V_22 -> V_12 . V_74 ;
} else {
V_74 = ! V_22 -> V_12 . V_74 ;
}
V_76 = F_14 ( V_72 , V_22 -> V_12 . clock , 23 ) ;
if ( V_74 )
V_76 = 0x800000 - V_76 ;
V_8 [ 0 ] = ( V_76 >> 0 ) & 0xff ;
V_8 [ 1 ] = ( V_76 >> 8 ) & 0xff ;
V_8 [ 2 ] = ( V_76 >> 16 ) & 0x7f ;
V_76 = 0x800000 - V_76 ;
V_8 [ 3 ] = ( V_76 >> 0 ) & 0xff ;
V_8 [ 4 ] = ( V_76 >> 8 ) & 0xff ;
V_8 [ 5 ] = ( V_76 >> 16 ) & 0x7f ;
V_7 = F_5 ( V_22 , 0xd140 , V_8 , 3 ) ;
if ( V_7 )
goto V_21;
V_7 = F_5 ( V_22 , 0x9be7 , V_8 , 6 ) ;
if ( V_7 )
goto V_21;
}
V_7 = F_10 ( V_22 , 0xd330 , 3 , 1 , 1 ) ;
if ( V_7 )
goto V_21;
V_7 = F_10 ( V_22 , 0xd507 , 6 , 1 , 0 ) ;
if ( V_7 )
goto V_21;
V_7 = F_10 ( V_22 , 0x9bfe , 0 , 1 , 0 ) ;
if ( V_7 )
goto V_21;
V_7 = F_10 ( V_22 , 0x9bc2 , 0 , 1 , 0 ) ;
if ( V_7 )
goto V_21;
V_73 = false ;
memset ( V_8 , 0 , 3 ) ;
switch ( V_34 -> V_85 ) {
case V_86 :
V_73 = 1 ;
break;
case V_87 :
break;
case V_88 :
V_8 [ 0 ] |= ( 1 << 0 ) ;
break;
default:
F_13 ( L_12 , V_28 ) ;
V_73 = 1 ;
}
switch ( V_34 -> V_89 ) {
case V_90 :
V_73 = 1 ;
break;
case V_91 :
break;
case V_92 :
V_8 [ 0 ] |= ( 1 << 2 ) ;
break;
case V_93 :
V_8 [ 0 ] |= ( 2 << 2 ) ;
break;
case V_94 :
V_8 [ 0 ] |= ( 3 << 2 ) ;
break;
default:
F_13 ( L_13 , V_28 ) ;
V_73 = 1 ;
}
switch ( V_34 -> V_95 ) {
case V_96 :
V_73 = 1 ;
break;
case V_97 :
break;
case V_98 :
V_8 [ 0 ] |= ( 1 << 4 ) ;
break;
case V_99 :
V_8 [ 0 ] |= ( 2 << 4 ) ;
break;
case V_100 :
V_8 [ 0 ] |= ( 3 << 4 ) ;
break;
default:
F_13 ( L_14 , V_28 ) ;
V_73 = 1 ;
} ;
switch ( V_34 -> V_101 ) {
case V_102 :
V_73 = 1 ;
break;
case V_103 :
break;
case V_104 :
V_8 [ 1 ] |= ( 1 << 6 ) ;
break;
case V_105 :
V_8 [ 1 ] |= ( 2 << 6 ) ;
break;
default:
F_13 ( L_15 , V_28 ) ;
V_73 = 1 ;
}
V_8 [ 1 ] |= ( 1 << 4 ) ;
switch ( V_34 -> V_106 ) {
case V_107 :
V_73 = 1 ;
break;
case V_108 :
break;
case V_109 :
V_8 [ 2 ] |= ( 1 << 0 ) ;
break;
case V_110 :
V_8 [ 2 ] |= ( 2 << 0 ) ;
break;
case V_111 :
V_8 [ 2 ] |= ( 3 << 0 ) ;
break;
case V_112 :
V_8 [ 2 ] |= ( 4 << 0 ) ;
break;
default:
F_13 ( L_16 , V_28 ) ;
V_73 = 1 ;
}
switch ( V_34 -> V_113 ) {
case V_107 :
V_73 = 1 ;
break;
case V_108 :
break;
case V_109 :
V_8 [ 2 ] |= ( 1 << 3 ) ;
break;
case V_110 :
V_8 [ 2 ] |= ( 2 << 3 ) ;
break;
case V_111 :
V_8 [ 2 ] |= ( 3 << 3 ) ;
break;
case V_112 :
V_8 [ 2 ] |= ( 4 << 3 ) ;
break;
case V_114 :
break;
default:
F_13 ( L_17 , V_28 ) ;
V_73 = 1 ;
}
switch ( V_34 -> V_78 ) {
case 6000000 :
break;
case 7000000 :
V_8 [ 1 ] |= ( 1 << 2 ) ;
break;
case 8000000 :
V_8 [ 1 ] |= ( 2 << 2 ) ;
break;
default:
F_13 ( L_18 , V_28 ) ;
V_7 = - V_29 ;
goto V_21;
}
V_7 = F_5 ( V_22 , 0xd3c0 , V_8 , 3 ) ;
if ( V_7 )
goto V_21;
if ( V_73 ) {
V_7 = F_7 ( V_22 , 0xaefd , 0 ) ;
if ( V_7 )
goto V_21;
F_13 ( L_19 , V_28 ) ;
} else {
V_7 = F_7 ( V_22 , 0xaefd , 1 ) ;
if ( V_7 )
goto V_21;
V_7 = F_7 ( V_22 , 0xaefe , 0 ) ;
if ( V_7 )
goto V_21;
F_13 ( L_20 , V_28 ) ;
}
V_7 = F_7 ( V_22 , 0xffff , 0 ) ;
if ( V_7 )
goto V_21;
V_22 -> V_78 = V_34 -> V_78 ;
V_22 -> V_115 = V_116 ;
V_22 -> V_83 = false ;
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static int F_29 ( struct V_37 * V_38 )
{
struct V_70 * V_34 = & V_38 -> V_71 ;
struct V_1 * V_22 = V_38 -> V_39 ;
int V_7 ;
T_1 V_8 [ 3 ] ;
F_13 ( L_9 , V_28 ) ;
V_7 = F_6 ( V_22 , 0xd3c0 , V_8 , 3 ) ;
if ( V_7 )
goto V_21;
switch ( ( V_8 [ 1 ] >> 6 ) & 3 ) {
case 0 :
V_34 -> V_101 = V_103 ;
break;
case 1 :
V_34 -> V_101 = V_104 ;
break;
case 2 :
V_34 -> V_101 = V_105 ;
break;
}
switch ( ( V_8 [ 0 ] >> 0 ) & 3 ) {
case 0 :
V_34 -> V_85 = V_87 ;
break;
case 1 :
V_34 -> V_85 = V_88 ;
}
switch ( ( V_8 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_34 -> V_89 = V_91 ;
break;
case 1 :
V_34 -> V_89 = V_92 ;
break;
case 2 :
V_34 -> V_89 = V_93 ;
break;
case 3 :
V_34 -> V_89 = V_94 ;
break;
}
switch ( ( V_8 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_34 -> V_95 = V_97 ;
break;
case 1 :
V_34 -> V_95 = V_98 ;
break;
case 2 :
V_34 -> V_95 = V_99 ;
break;
case 3 :
V_34 -> V_95 = V_100 ;
break;
}
switch ( ( V_8 [ 2 ] >> 0 ) & 7 ) {
case 0 :
V_34 -> V_106 = V_108 ;
break;
case 1 :
V_34 -> V_106 = V_109 ;
break;
case 2 :
V_34 -> V_106 = V_110 ;
break;
case 3 :
V_34 -> V_106 = V_111 ;
break;
case 4 :
V_34 -> V_106 = V_112 ;
break;
}
switch ( ( V_8 [ 2 ] >> 3 ) & 7 ) {
case 0 :
V_34 -> V_113 = V_108 ;
break;
case 1 :
V_34 -> V_113 = V_109 ;
break;
case 2 :
V_34 -> V_113 = V_110 ;
break;
case 3 :
V_34 -> V_113 = V_111 ;
break;
case 4 :
V_34 -> V_113 = V_112 ;
break;
}
switch ( ( V_8 [ 1 ] >> 2 ) & 3 ) {
case 0 :
V_34 -> V_78 = 6000000 ;
break;
case 1 :
V_34 -> V_78 = 7000000 ;
break;
case 2 :
V_34 -> V_78 = 8000000 ;
break;
}
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static int F_30 ( struct V_37 * V_38 , T_4 * V_117 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
int V_7 ;
T_1 V_24 ;
if ( F_31 (
V_22 -> V_118 + F_26 ( 2000 ) ) &&
F_32 (
V_22 -> V_115 + F_26 ( 4000 ) )
) {
* V_117 = V_22 -> V_62 ;
return 0 ;
} else {
* V_117 = 0 ;
}
V_7 = F_11 ( V_22 , 0xd507 , 6 , 1 , & V_24 ) ;
if ( V_7 )
goto V_21;
if ( V_24 )
* V_117 |= V_119 | V_120 | V_121 |
V_122 | V_63 ;
if ( ! * V_117 ) {
V_7 = F_11 ( V_22 , 0xd330 , 3 , 1 , & V_24 ) ;
if ( V_7 )
goto V_21;
if ( V_24 )
* V_117 |= V_119 | V_120 |
V_121 ;
}
V_22 -> V_62 = * V_117 ;
V_22 -> V_118 = V_116 ;
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static int F_33 ( struct V_37 * V_38 , T_2 * V_49 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
* V_49 = V_22 -> V_49 ;
return 0 ;
}
static int F_34 ( struct V_37 * V_38 , T_2 * V_123 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
* V_123 = V_22 -> V_52 ;
return 0 ;
}
static int F_35 ( struct V_37 * V_38 , T_3 * V_40 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
* V_40 = V_22 -> V_40 ;
return 0 ;
}
static int F_36 ( struct V_37 * V_38 , T_3 * V_41 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
* V_41 = V_22 -> V_41 ;
return 0 ;
}
static int F_37 ( struct V_37 * V_38 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
int V_7 , V_18 , V_6 ;
T_1 V_8 [ 3 ] , V_24 ;
T_3 V_124 ;
const struct V_125 * V_126 ;
F_13 ( L_9 , V_28 ) ;
V_7 = F_15 ( V_22 , 1 ) ;
if ( V_7 )
goto V_21;
V_7 = F_7 ( V_22 , 0xd73a , 0xa4 ) ;
if ( V_7 )
goto V_21;
V_7 = F_5 ( V_22 , 0x9bf2 , V_22 -> V_12 . V_127 , 4 ) ;
if ( V_7 )
goto V_21;
switch ( V_22 -> V_12 . clock ) {
case 28800000 :
V_24 = 0 ;
break;
case 20480000 :
V_24 = 1 ;
break;
case 28000000 :
V_24 = 2 ;
break;
case 25000000 :
V_24 = 3 ;
break;
default:
V_21 ( L_21 ) ;
return - V_29 ;
}
V_124 = F_14 ( V_22 -> V_12 . clock , 1000000ul , 19 ) ;
V_8 [ 0 ] = ( V_124 >> 0 ) & 0xff ;
V_8 [ 1 ] = ( V_124 >> 8 ) & 0xff ;
V_8 [ 2 ] = ( V_124 >> 16 ) & 0xff ;
V_7 = F_5 ( V_22 , 0xd180 , V_8 , 3 ) ;
if ( V_7 )
goto V_21;
V_7 = F_10 ( V_22 , 0x9bd2 , 0 , 4 , V_24 ) ;
if ( V_7 )
goto V_21;
V_7 = F_7 ( V_22 , 0xd416 , 0x14 ) ;
if ( V_7 )
goto V_21;
V_7 = F_10 ( V_22 , 0xd700 , 1 , 1 , 1 ) ;
if ( V_7 )
goto V_21;
V_7 = F_10 ( V_22 , 0xd700 , 2 , 1 , 0 ) ;
if ( V_7 )
goto V_21;
V_7 = F_10 ( V_22 , 0xd371 , 1 , 1 , 1 ) ;
if ( V_7 )
goto V_21;
if ( V_22 -> V_12 . V_19 == V_20 ) {
V_7 = F_10 ( V_22 , 0xd50b , 2 , 1 , 1 ) ;
if ( V_7 )
goto V_21;
} else {
V_7 = F_10 ( V_22 , 0xd500 , 3 , 1 , 1 ) ;
if ( V_7 )
goto V_21;
V_7 = F_10 ( V_22 , 0xd502 , 4 , 1 , 1 ) ;
if ( V_7 )
goto V_21;
}
V_7 = F_10 ( V_22 , 0xd520 , 4 , 1 , 1 ) ;
if ( V_7 )
goto V_21;
F_13 ( L_22 , V_28 ) ;
V_6 = F_21 ( V_128 ) ;
V_126 = V_128 ;
for ( V_18 = 0 ; V_18 < V_6 ; V_18 ++ ) {
V_7 = F_10 ( V_22 , V_126 [ V_18 ] . V_11 , V_126 [ V_18 ] . V_23 ,
V_126 [ V_18 ] . V_6 , V_126 [ V_18 ] . V_5 ) ;
if ( V_7 )
goto V_21;
}
F_13 ( L_23 , V_28 ) ;
switch ( V_22 -> V_12 . V_129 ) {
case V_130 :
V_6 = F_21 ( V_131 ) ;
V_126 = V_131 ;
break;
case V_132 :
case V_133 :
case V_134 :
V_6 = F_21 ( V_135 ) ;
V_126 = V_135 ;
break;
case V_136 :
V_6 = F_21 ( V_137 ) ;
V_126 = V_137 ;
break;
case V_138 :
V_6 = F_21 ( V_139 ) ;
V_126 = V_139 ;
break;
case V_140 :
V_6 = F_21 ( V_141 ) ;
V_126 = V_141 ;
break;
case V_142 :
case V_143 :
V_6 = F_21 ( V_144 ) ;
V_126 = V_144 ;
break;
case V_145 :
V_6 = F_21 ( V_146 ) ;
V_126 = V_146 ;
break;
case V_147 :
case V_148 :
V_6 = F_21 ( V_149 ) ;
V_126 = V_149 ;
break;
case V_150 :
default:
V_6 = F_21 ( V_151 ) ;
V_126 = V_151 ;
break;
}
for ( V_18 = 0 ; V_18 < V_6 ; V_18 ++ ) {
V_7 = F_10 ( V_22 , V_126 [ V_18 ] . V_11 , V_126 [ V_18 ] . V_23 ,
V_126 [ V_18 ] . V_6 , V_126 [ V_18 ] . V_5 ) ;
if ( V_7 )
goto V_21;
}
V_7 = F_10 ( V_22 , 0xd500 , 1 , 2 , V_22 -> V_12 . V_19 ) ;
if ( V_7 )
goto V_21;
V_7 = F_10 ( V_22 , 0xd730 , 0 , 1 , 1 ) ;
if ( V_7 )
goto V_21;
if ( ! V_22 -> V_53 ) {
V_7 = F_11 ( V_22 , 0x9bee , 0 , 1 ,
& V_22 -> V_53 ) ;
if ( V_7 )
goto V_21;
}
if ( V_22 -> V_53 && ! V_22 -> V_54 ) {
V_7 = F_8 ( V_22 , 0x9bbd , & V_22 -> V_54 ) ;
if ( V_7 )
goto V_21;
V_7 = F_8 ( V_22 , 0x9bd0 , & V_22 -> V_56 ) ;
if ( V_7 )
goto V_21;
V_7 = F_8 ( V_22 , 0x9be2 , & V_22 -> V_55 ) ;
if ( V_7 )
goto V_21;
V_7 = F_8 ( V_22 , 0x9be4 , & V_22 -> V_57 ) ;
if ( V_7 )
goto V_21;
}
V_7 = F_7 ( V_22 , 0xd2e2 , 1 ) ;
if ( V_7 )
goto V_21;
V_8 [ 0 ] = ( 10000 >> 0 ) & 0xff ;
V_8 [ 1 ] = ( 10000 >> 8 ) & 0xff ;
V_7 = F_5 ( V_22 , 0xd385 , V_8 , 2 ) ;
if ( V_7 )
goto V_21;
V_7 = F_10 ( V_22 , 0xd392 , 1 , 1 , 1 ) ;
if ( V_7 )
goto V_21;
V_22 -> V_83 = true ;
F_25 ( & V_22 -> V_60 , F_26 ( 400 ) ) ;
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static int F_38 ( struct V_37 * V_38 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
int V_7 ;
F_13 ( L_9 , V_28 ) ;
F_39 ( & V_22 -> V_60 ) ;
V_7 = F_10 ( V_22 , 0xd730 , 0 , 1 , 0 ) ;
if ( V_7 )
goto V_21;
V_7 = F_15 ( V_22 , 0 ) ;
if ( V_7 )
goto V_21;
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static int F_40 ( struct V_37 * V_38 , int V_152 )
{
int V_7 ;
struct V_1 * V_22 = V_38 -> V_39 ;
F_13 ( L_24 , V_28 , V_152 ) ;
if ( V_22 -> V_153 == V_152 )
return 0 ;
if ( V_22 -> V_12 . V_19 == V_20 )
V_7 = F_10 ( V_22 , 0xd417 , 3 , 1 , V_152 ) ;
else
V_7 = F_10 ( V_22 , 0xd607 , 2 , 1 , V_152 ) ;
if ( V_7 )
goto V_21;
V_22 -> V_153 = V_152 ;
return V_7 ;
V_21:
F_13 ( L_5 , V_28 , V_7 ) ;
return V_7 ;
}
static void F_41 ( struct V_37 * V_38 )
{
struct V_1 * V_22 = V_38 -> V_39 ;
F_42 ( V_22 ) ;
}
static int F_43 ( struct V_1 * V_22 )
{
int V_18 , V_6 , V_154 , V_7 ;
const struct V_155 * V_156 ;
T_2 V_157 = 0 ;
T_1 V_5 ;
T_1 V_158 [ 4 ] ;
T_1 * V_159 = V_160 ;
F_44 ( 100 ) ;
V_7 = F_8 ( V_22 , 0x98be , & V_5 ) ;
if ( V_7 )
goto V_21;
else
F_13 ( L_25 , V_28 , V_5 ) ;
if ( V_5 == 0x0c )
goto exit;
F_45 ( L_26 ,
V_161 . F_45 . V_162 ) ;
V_7 = F_46 ( & V_156 , V_159 , V_22 -> V_15 -> V_163 . V_164 ) ;
if ( V_7 ) {
V_21 ( L_27
L_28 \
L_29 ,
V_159 , V_7 ) ;
goto V_21;
}
F_45 ( L_30 , V_159 ) ;
for ( V_18 = 0 ; V_18 < V_156 -> V_165 ; V_18 ++ )
V_157 += V_156 -> V_166 [ V_18 ] ;
V_158 [ 0 ] = V_157 >> 8 ;
V_158 [ 1 ] = V_157 & 0xff ;
V_158 [ 2 ] = V_156 -> V_165 >> 8 ;
V_158 [ 3 ] = V_156 -> V_165 & 0xff ;
V_7 = F_9 ( V_22 , 0x50fc ,
V_158 , sizeof( V_158 ) ) ;
if ( V_7 )
goto V_167;
#define F_47 0x5100
#define F_48 16
for ( V_154 = V_156 -> V_165 ; V_154 > 0 ; V_154 -= F_48 ) {
V_6 = V_154 ;
if ( V_6 > F_48 )
V_6 = F_48 ;
V_7 = F_9 ( V_22 ,
F_47 + V_156 -> V_165 - V_154 ,
( T_1 * ) & V_156 -> V_166 [ V_156 -> V_165 - V_154 ] , V_6 ) ;
if ( V_7 ) {
V_21 ( L_31 , V_7 ) ;
goto V_167;
}
}
V_7 = F_7 ( V_22 , 0xe205 , 1 ) ;
if ( V_7 )
goto V_167;
for ( V_18 = 0 ; V_18 < 15 ; V_18 ++ ) {
F_44 ( 100 ) ;
V_7 = F_8 ( V_22 , 0x98be , & V_5 ) ;
if ( V_7 )
goto V_167;
F_13 ( L_25 , V_28 , V_5 ) ;
if ( V_5 == 0x0c || V_5 == 0x04 )
break;
}
if ( V_5 == 0x04 ) {
V_21 ( L_32 ) ;
V_7 = - V_168 ;
} else if ( V_5 != 0x0c ) {
V_21 ( L_33 ) ;
V_7 = - V_168 ;
}
V_167:
F_49 ( V_156 ) ;
V_21:
exit:
if ( ! V_7 )
F_45 ( L_34 , V_161 . F_45 . V_162 ) ;
return V_7 ;
}
struct V_37 * F_50 ( const struct V_169 * V_12 ,
struct V_170 * V_15 )
{
int V_7 ;
struct V_1 * V_22 = NULL ;
T_1 V_8 [ 4 ] , V_18 ;
V_22 = F_51 ( sizeof( struct V_1 ) , V_171 ) ;
if ( V_22 == NULL )
goto V_21;
V_22 -> V_15 = V_15 ;
memcpy ( & V_22 -> V_12 , V_12 , sizeof( struct V_169 ) ) ;
if ( V_22 -> V_12 . V_19 != V_20 ) {
V_7 = F_43 ( V_22 ) ;
if ( V_7 )
goto V_21;
}
V_7 = F_6 ( V_22 , 0x5103 , V_8 , 4 ) ;
if ( V_7 )
goto V_21;
F_45 ( L_35 , V_8 [ 0 ] , V_8 [ 1 ] , V_8 [ 2 ] , V_8 [ 3 ] ) ;
for ( V_18 = 0 ; V_18 < sizeof( V_22 -> V_12 . V_26 ) ; V_18 ++ ) {
V_7 = F_12 ( V_22 , V_18 , V_22 -> V_12 . V_26 [ V_18 ] ) ;
if ( V_7 )
goto V_21;
}
memcpy ( & V_22 -> V_38 . V_79 , & V_161 ,
sizeof( struct V_172 ) ) ;
V_22 -> V_38 . V_39 = V_22 ;
F_52 ( & V_22 -> V_60 , F_23 ) ;
return & V_22 -> V_38 ;
V_21:
F_42 ( V_22 ) ;
return NULL ;
}
