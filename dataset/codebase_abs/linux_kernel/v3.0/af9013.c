static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 * V_5 , T_1 V_6 )
{
T_1 V_7 [ 3 + V_6 ] ;
struct V_8 V_9 = {
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = 0 ,
. V_6 = sizeof( V_7 ) ,
. V_7 = V_7 } ;
V_7 [ 0 ] = V_4 >> 8 ;
V_7 [ 1 ] = V_4 & 0xff ;
V_7 [ 2 ] = V_3 ;
memcpy ( & V_7 [ 3 ] , V_5 , V_6 ) ;
if ( F_2 ( V_2 -> V_14 , & V_9 , 1 ) != 1 ) {
F_3 ( L_1 , V_4 , V_6 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 V_4 , T_1 * V_5 ,
T_1 V_6 )
{
T_1 V_3 = ( 1 << 0 ) | ( 1 << 1 ) | ( ( V_6 - 1 ) << 2 ) | ( 0 << 6 ) | ( 0 << 7 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_4 , T_1 * V_5 ,
T_1 V_6 )
{
T_1 V_3 = ( 1 << 0 ) | ( 1 << 1 ) | ( ( V_6 - 1 ) << 2 ) | ( 1 << 6 ) | ( 1 << 7 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_5 )
{
return F_4 ( V_2 , V_4 , & V_5 , 1 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_4 , T_1 * V_5 )
{
T_1 V_16 [ 3 ] = { V_4 >> 8 , V_4 & 0xff , 0 } ;
T_1 V_17 [ 1 ] ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = 0 ,
. V_6 = sizeof( V_16 ) ,
. V_7 = V_16
} , {
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = V_18 ,
. V_6 = sizeof( V_17 ) ,
. V_7 = V_17
}
} ;
if ( F_2 ( V_2 -> V_14 , V_9 , 2 ) != 2 ) {
F_3 ( L_2 , V_4 ) ;
return - V_15 ;
}
* V_5 = V_17 [ 0 ] ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_19 ,
T_1 V_6 , T_1 V_5 )
{
int V_20 ;
T_1 V_21 , V_22 ;
V_20 = F_7 ( V_2 , V_4 , & V_21 ) ;
if ( V_20 )
return V_20 ;
V_22 = V_23 [ V_6 - 1 ] << V_19 ;
V_21 = ( V_21 & ~ V_22 ) | ( ( V_5 << V_19 ) & V_22 ) ;
return F_6 ( V_2 , V_4 , V_21 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_19 ,
T_1 V_6 , T_1 * V_5 )
{
int V_20 ;
T_1 V_21 ;
V_20 = F_7 ( V_2 , V_4 , & V_21 ) ;
if ( V_20 )
return V_20 ;
* V_5 = ( V_21 >> V_19 ) & V_23 [ V_6 - 1 ] ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_24 , T_1 V_25 )
{
int V_20 ;
T_1 V_19 ;
T_2 V_10 ;
F_11 ( L_3 , V_26 , V_24 , V_25 ) ;
switch ( V_24 ) {
case 0 :
case 1 :
V_10 = 0xd735 ;
break;
case 2 :
case 3 :
V_10 = 0xd736 ;
break;
default:
F_12 ( L_4 , V_24 ) ;
V_20 = - V_27 ;
goto error;
} ;
switch ( V_24 ) {
case 0 :
case 2 :
V_19 = 0 ;
break;
case 1 :
case 3 :
default:
V_19 = 4 ;
break;
} ;
V_20 = F_8 ( V_2 , V_10 , V_19 , 4 , V_25 ) ;
error:
return V_20 ;
}
static T_3 F_13 ( T_3 V_28 , T_3 V_29 , T_3 V_30 )
{
T_3 V_31 = 0 , V_32 = 0 , V_33 ;
F_11 ( L_5 , V_26 , V_28 , V_29 , V_30 ) ;
if ( V_28 > V_29 ) {
V_32 = V_28 / V_29 ;
V_28 = V_28 - V_32 * V_29 ;
}
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ ) {
if ( V_28 >= V_29 ) {
V_31 += 1 ;
V_28 -= V_29 ;
}
V_28 <<= 1 ;
V_31 <<= 1 ;
}
V_31 = ( V_32 << ( T_3 ) V_30 ) + V_31 ;
F_11 ( L_6 , V_26 , V_28 , V_29 , V_30 , V_31 , V_31 ) ;
return V_31 ;
}
static int F_14 ( struct V_1 * V_2 , T_4 V_34 )
{
int V_20 , V_33 , V_35 , V_36 ;
F_11 ( L_7 , V_26 ,
V_2 -> V_11 . V_37 , V_34 ) ;
for ( V_33 = 0 , V_36 = 0 ; V_33 < F_15 ( V_38 ) ; V_33 ++ ) {
if ( V_38 [ V_33 ] . V_37 == V_2 -> V_11 . V_37 &&
V_38 [ V_33 ] . V_34 == V_34 ) {
V_36 = 1 ;
break;
}
}
if ( ! V_36 ) {
F_12 ( L_8 ) ;
V_20 = - V_27 ;
goto error;
}
F_11 ( L_9 , V_26 ) ;
F_16 ( V_38 [ V_33 ] . V_5 , sizeof( V_38 [ V_33 ] . V_5 ) , F_11 ) ;
for ( V_35 = 0 ; V_35 < sizeof( V_38 [ V_33 ] . V_5 ) ; V_35 ++ ) {
V_20 = F_6 ( V_2 , 0xae00 + V_35 ,
V_38 [ V_33 ] . V_5 [ V_35 ] ) ;
if ( V_20 )
break;
}
error:
return V_20 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_20 ;
T_1 V_7 [ 3 ] , V_21 , V_33 ;
T_3 V_39 ;
F_11 ( L_10 , V_26 , V_2 -> V_11 . V_37 ) ;
switch ( V_2 -> V_11 . V_37 ) {
case 28800 :
V_21 = 0 ;
break;
case 20480 :
V_21 = 1 ;
break;
case 28000 :
V_21 = 2 ;
break;
case 25000 :
V_21 = 3 ;
break;
default:
F_12 ( L_11 ) ;
return - V_27 ;
}
V_39 = F_13 ( V_2 -> V_11 . V_37 * 1000 , 1000000ul , 19ul ) ;
V_7 [ 0 ] = ( T_1 ) ( ( V_39 & 0x000000ff ) ) ;
V_7 [ 1 ] = ( T_1 ) ( ( V_39 & 0x0000ff00 ) >> 8 ) ;
V_7 [ 2 ] = ( T_1 ) ( ( V_39 & 0x00ff0000 ) >> 16 ) ;
F_11 ( L_12 , V_26 ) ;
F_16 ( V_7 , sizeof( V_7 ) , F_11 ) ;
for ( V_33 = 0 ; V_33 < sizeof( V_7 ) ; V_33 ++ ) {
V_20 = F_6 ( V_2 , 0xd180 + V_33 , V_7 [ V_33 ] ) ;
if ( V_20 )
goto error;
}
V_20 = F_8 ( V_2 , 0x9bd2 , 0 , 4 , V_21 ) ;
error:
return V_20 ;
}
static int F_18 ( struct V_1 * V_2 , T_4 V_34 )
{
int V_20 ;
T_2 V_10 ;
T_1 V_7 [ 3 ] , V_33 , V_35 ;
T_3 V_40 , V_41 ;
T_5 V_42 ;
int V_43 ;
for ( V_35 = 0 ; V_35 < 3 ; V_35 ++ ) {
if ( V_35 == 0 ) {
V_10 = 0xd140 ;
V_42 = V_2 -> V_11 . V_44 ? - 1 : 1 ;
} else if ( V_35 == 1 ) {
V_10 = 0x9be7 ;
V_42 = V_2 -> V_11 . V_44 ? - 1 : 1 ;
} else {
V_10 = 0x9bea ;
V_42 = V_2 -> V_11 . V_44 ? 1 : - 1 ;
}
V_40 = V_2 -> V_11 . V_37 * 1000 ;
V_43 = V_2 -> V_11 . V_45 * 1000 ;
if ( V_2 -> V_11 . V_46 == V_47 ) {
switch ( V_34 ) {
case V_48 :
V_43 = 3300000 ;
break;
case V_49 :
V_43 = 3500000 ;
break;
case V_50 :
default:
V_43 = 4000000 ;
break;
}
} else if ( V_2 -> V_11 . V_46 == V_51 ) {
switch ( V_34 ) {
case V_48 :
V_43 = 3000000 ;
break;
case V_49 :
V_43 = 3500000 ;
break;
case V_50 :
default:
V_43 = 4000000 ;
break;
}
}
while ( V_43 > ( V_40 / 2 ) )
V_43 = V_43 - V_40 ;
if ( V_43 >= 0 )
V_42 = V_42 * ( - 1 ) ;
else
V_43 = V_43 * ( - 1 ) ;
V_41 = F_13 ( V_43 , V_40 , 23ul ) ;
if ( V_42 == - 1 )
V_41 = 0x00800000 - V_41 ;
V_7 [ 0 ] = ( T_1 ) ( ( V_41 & 0x000000ff ) ) ;
V_7 [ 1 ] = ( T_1 ) ( ( V_41 & 0x0000ff00 ) >> 8 ) ;
V_7 [ 2 ] = ( T_1 ) ( ( V_41 & 0x007f0000 ) >> 16 ) ;
F_11 ( L_13 , V_26 ) ;
F_16 ( V_7 , sizeof( V_7 ) , F_11 ) ;
for ( V_33 = 0 ; V_33 < sizeof( V_7 ) ; V_33 ++ ) {
V_20 = F_6 ( V_2 , V_10 ++ , V_7 [ V_33 ] ) ;
if ( V_20 )
goto error;
}
}
error:
return V_20 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_52 * V_53 , T_1 * V_54 )
{
int V_20 ;
T_1 V_33 , V_7 [ 3 ] = { 0 , 0 , 0 } ;
* V_54 = 0 ;
switch ( V_53 -> V_55 ) {
case V_56 :
* V_54 = 1 ;
case V_57 :
break;
case V_58 :
V_7 [ 0 ] |= ( 1 << 0 ) ;
break;
default:
F_11 ( L_14 , V_26 ) ;
* V_54 = 1 ;
}
switch ( V_53 -> V_59 ) {
case V_60 :
* V_54 = 1 ;
case V_61 :
break;
case V_62 :
V_7 [ 0 ] |= ( 1 << 2 ) ;
break;
case V_63 :
V_7 [ 0 ] |= ( 2 << 2 ) ;
break;
case V_64 :
V_7 [ 0 ] |= ( 3 << 2 ) ;
break;
default:
F_11 ( L_15 , V_26 ) ;
* V_54 = 1 ;
}
switch ( V_53 -> V_65 ) {
case V_66 :
* V_54 = 1 ;
case V_67 :
break;
case V_68 :
V_7 [ 0 ] |= ( 1 << 4 ) ;
break;
case V_69 :
V_7 [ 0 ] |= ( 2 << 4 ) ;
break;
case V_70 :
V_7 [ 0 ] |= ( 3 << 4 ) ;
break;
default:
F_11 ( L_16 , V_26 ) ;
* V_54 = 1 ;
} ;
switch ( V_53 -> V_71 ) {
case V_72 :
* V_54 = 1 ;
case V_73 :
break;
case V_74 :
V_7 [ 1 ] |= ( 1 << 6 ) ;
break;
case V_75 :
V_7 [ 1 ] |= ( 2 << 6 ) ;
break;
default:
F_11 ( L_17 , V_26 ) ;
* V_54 = 1 ;
}
V_7 [ 1 ] |= ( 1 << 4 ) ;
switch ( V_53 -> V_76 ) {
case V_77 :
* V_54 = 1 ;
case V_78 :
break;
case V_79 :
V_7 [ 2 ] |= ( 1 << 0 ) ;
break;
case V_80 :
V_7 [ 2 ] |= ( 2 << 0 ) ;
break;
case V_81 :
V_7 [ 2 ] |= ( 3 << 0 ) ;
break;
case V_82 :
V_7 [ 2 ] |= ( 4 << 0 ) ;
break;
default:
F_11 ( L_18 , V_26 ) ;
* V_54 = 1 ;
}
switch ( V_53 -> V_83 ) {
case V_77 :
if ( V_53 -> V_65 != V_67 )
* V_54 = 1 ;
case V_78 :
break;
case V_79 :
V_7 [ 2 ] |= ( 1 << 3 ) ;
break;
case V_80 :
V_7 [ 2 ] |= ( 2 << 3 ) ;
break;
case V_81 :
V_7 [ 2 ] |= ( 3 << 3 ) ;
break;
case V_82 :
V_7 [ 2 ] |= ( 4 << 3 ) ;
break;
case V_84 :
if ( V_53 -> V_65 == V_66 )
break;
default:
F_11 ( L_19 , V_26 ) ;
* V_54 = 1 ;
}
switch ( V_53 -> V_85 ) {
case V_48 :
break;
case V_49 :
V_7 [ 1 ] |= ( 1 << 2 ) ;
break;
case V_50 :
V_7 [ 1 ] |= ( 2 << 2 ) ;
break;
default:
F_11 ( L_20 , V_26 ) ;
V_7 [ 1 ] |= ( 2 << 2 ) ;
}
for ( V_33 = 0 ; V_33 < sizeof( V_7 ) ; V_33 ++ ) {
V_20 = F_6 ( V_2 , 0xd3c0 + V_33 , V_7 [ V_33 ] ) ;
if ( V_20 )
break;
}
return V_20 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_86 )
{
int V_20 ;
T_1 V_21 , V_33 ;
F_11 ( L_21 , V_26 ) ;
V_20 = F_8 ( V_2 , 0xd417 , 4 , 1 , 1 ) ;
if ( V_20 )
goto error;
V_20 = F_6 ( V_2 , 0xaeff , 1 ) ;
if ( V_20 )
goto error;
for ( V_33 = 0 ; V_33 < 150 ; V_33 ++ ) {
V_20 = F_9 ( V_2 , 0xd417 , 1 , 1 , & V_21 ) ;
if ( V_20 )
goto error;
if ( V_21 )
break;
F_21 ( 10 ) ;
}
if ( ! V_21 )
return - V_87 ;
if ( ! V_86 ) {
V_20 = F_8 ( V_2 , 0xd417 , 1 , 1 , 0 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd417 , 4 , 1 , 0 ) ;
}
error:
return V_20 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_88 )
{
int V_20 ;
F_11 ( L_22 , V_26 , V_88 ) ;
if ( V_88 ) {
V_20 = F_8 ( V_2 , 0xd73a , 3 , 1 , 0 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd417 , 1 , 1 , 0 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd417 , 4 , 1 , 0 ) ;
} else {
V_20 = F_20 ( V_2 , 1 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd73a , 3 , 1 , 1 ) ;
}
error:
return V_20 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_88 )
{
F_11 ( L_22 , V_26 , V_88 ) ;
return F_8 ( V_2 , 0xd730 , 0 , 1 , V_88 ) ;
}
static int F_24 ( struct V_89 * V_90 ,
struct V_91 * V_53 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 ;
T_1 V_54 ;
F_11 ( L_23 , V_26 , V_53 -> V_93 ,
V_53 -> V_94 . V_95 . V_85 ) ;
V_2 -> V_93 = V_53 -> V_93 ;
if ( V_90 -> V_96 . V_97 . V_98 )
V_90 -> V_96 . V_97 . V_98 ( V_90 , V_53 ) ;
V_20 = F_14 ( V_2 , V_53 -> V_94 . V_95 . V_85 ) ;
if ( V_20 )
goto error;
V_20 = F_18 ( V_2 , V_53 -> V_94 . V_95 . V_85 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd330 , 3 , 1 , 1 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd507 , 6 , 1 , 0 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0x9bfe , 0 , 1 , 0 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0x9bc2 , 0 , 1 , 0 ) ;
if ( V_20 )
goto error;
V_20 = F_19 ( V_2 , & V_53 -> V_94 . V_95 , & V_54 ) ;
if ( V_20 )
goto error;
if ( V_54 ) {
V_20 = F_6 ( V_2 , 0xaefd , 0 ) ;
F_11 ( L_24 , V_26 ) ;
} else {
V_20 = F_6 ( V_2 , 0xaefd , 1 ) ;
if ( V_20 )
goto error;
V_20 = F_6 ( V_2 , 0xaefe , 0 ) ;
F_11 ( L_25 , V_26 ) ;
}
if ( V_20 )
goto error;
V_20 = F_6 ( V_2 , 0xffff , 0 ) ;
if ( V_20 )
goto error;
error:
return V_20 ;
}
static int F_25 ( struct V_89 * V_90 ,
struct V_91 * V_99 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 ;
T_1 V_33 , V_7 [ 3 ] ;
F_11 ( L_21 , V_26 ) ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
V_20 = F_7 ( V_2 , 0xd3c0 + V_33 , & V_7 [ V_33 ] ) ;
if ( V_20 )
goto error;
}
switch ( ( V_7 [ 1 ] >> 6 ) & 3 ) {
case 0 :
V_99 -> V_94 . V_95 . V_71 = V_73 ;
break;
case 1 :
V_99 -> V_94 . V_95 . V_71 = V_74 ;
break;
case 2 :
V_99 -> V_94 . V_95 . V_71 = V_75 ;
break;
}
switch ( ( V_7 [ 0 ] >> 0 ) & 3 ) {
case 0 :
V_99 -> V_94 . V_95 . V_55 = V_57 ;
break;
case 1 :
V_99 -> V_94 . V_95 . V_55 = V_58 ;
}
switch ( ( V_7 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_99 -> V_94 . V_95 . V_59 = V_61 ;
break;
case 1 :
V_99 -> V_94 . V_95 . V_59 = V_62 ;
break;
case 2 :
V_99 -> V_94 . V_95 . V_59 = V_63 ;
break;
case 3 :
V_99 -> V_94 . V_95 . V_59 = V_64 ;
break;
}
switch ( ( V_7 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_99 -> V_94 . V_95 . V_65 = V_67 ;
break;
case 1 :
V_99 -> V_94 . V_95 . V_65 = V_68 ;
break;
case 2 :
V_99 -> V_94 . V_95 . V_65 = V_69 ;
break;
case 3 :
V_99 -> V_94 . V_95 . V_65 = V_70 ;
break;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 7 ) {
case 0 :
V_99 -> V_94 . V_95 . V_76 = V_78 ;
break;
case 1 :
V_99 -> V_94 . V_95 . V_76 = V_79 ;
break;
case 2 :
V_99 -> V_94 . V_95 . V_76 = V_80 ;
break;
case 3 :
V_99 -> V_94 . V_95 . V_76 = V_81 ;
break;
case 4 :
V_99 -> V_94 . V_95 . V_76 = V_82 ;
break;
}
switch ( ( V_7 [ 2 ] >> 3 ) & 7 ) {
case 0 :
V_99 -> V_94 . V_95 . V_83 = V_78 ;
break;
case 1 :
V_99 -> V_94 . V_95 . V_83 = V_79 ;
break;
case 2 :
V_99 -> V_94 . V_95 . V_83 = V_80 ;
break;
case 3 :
V_99 -> V_94 . V_95 . V_83 = V_81 ;
break;
case 4 :
V_99 -> V_94 . V_95 . V_83 = V_82 ;
break;
}
switch ( ( V_7 [ 1 ] >> 2 ) & 3 ) {
case 0 :
V_99 -> V_94 . V_95 . V_85 = V_48 ;
break;
case 1 :
V_99 -> V_94 . V_95 . V_85 = V_49 ;
break;
case 2 :
V_99 -> V_94 . V_95 . V_85 = V_50 ;
break;
}
V_99 -> V_100 = V_101 ;
V_99 -> V_93 = V_2 -> V_93 ;
error:
return V_20 ;
}
static int F_26 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 ;
T_1 V_7 [ 3 ] , V_33 ;
T_3 V_102 = 0 ;
T_3 V_103 = 0 ;
T_3 V_104 = 0 ;
V_2 -> V_105 = 0 ;
V_20 = F_9 ( V_2 , 0xd391 , 4 , 1 , & V_7 [ 0 ] ) ;
if ( V_20 )
goto error;
if ( ! V_7 [ 0 ] )
goto exit;
for ( V_33 = 0 ; V_33 < 2 ; V_33 ++ ) {
V_20 = F_7 ( V_2 , 0xd38a + V_33 , & V_7 [ V_33 ] ) ;
if ( V_20 )
goto error;
}
V_104 = ( V_7 [ 1 ] << 8 ) + V_7 [ 0 ] ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
V_20 = F_7 ( V_2 , 0xd387 + V_33 , & V_7 [ V_33 ] ) ;
if ( V_20 )
goto error;
}
V_102 = ( V_7 [ 2 ] << 16 ) + ( V_7 [ 1 ] << 8 ) + V_7 [ 0 ] ;
V_102 = V_102 - V_104 * 8 * 8 ;
for ( V_33 = 0 ; V_33 < 2 ; V_33 ++ ) {
V_20 = F_7 ( V_2 , 0xd385 + V_33 , & V_7 [ V_33 ] ) ;
if ( V_20 )
goto error;
}
V_103 = ( V_7 [ 1 ] << 8 ) + V_7 [ 0 ] ;
V_103 = V_103 - V_104 ;
V_103 = V_103 * 204 * 8 ;
if ( V_103 )
V_2 -> V_105 = V_102 * 1000000000 / V_103 ;
V_2 -> V_106 += V_104 ;
F_11 ( L_26 , V_26 ,
V_102 , V_103 , V_104 ) ;
V_20 = F_6 ( V_2 , 0xd385 , 10000 & 0xff ) ;
if ( V_20 )
goto error;
V_20 = F_6 ( V_2 , 0xd386 , 10000 >> 8 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd391 , 4 , 1 , 1 ) ;
if ( V_20 )
goto error;
exit:
error:
return V_20 ;
}
static int F_27 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 ;
T_1 V_7 [ 3 ] , V_33 , V_6 ;
T_3 V_107 = 0 ;
struct V_108 * V_109 ( V_108 ) ;
V_20 = F_9 ( V_2 , 0xd2e1 , 3 , 1 , & V_7 [ 0 ] ) ;
if ( V_20 )
goto error;
if ( V_7 [ 0 ] ) {
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
V_20 = F_7 ( V_2 , 0xd2e3 + V_33 , & V_7 [ V_33 ] ) ;
if ( V_20 )
goto error;
}
V_107 = ( V_7 [ 2 ] << 16 ) + ( V_7 [ 1 ] << 8 ) + V_7 [ 0 ] ;
V_20 = F_7 ( V_2 , 0xd3c1 , & V_7 [ 0 ] ) ;
if ( V_20 )
goto error;
switch ( ( V_7 [ 0 ] >> 6 ) & 3 ) {
case 0 :
V_6 = F_15 ( V_110 ) ;
V_108 = V_110 ;
break;
case 1 :
V_6 = F_15 ( V_111 ) ;
V_108 = V_111 ;
break;
case 2 :
V_6 = F_15 ( V_112 ) ;
V_108 = V_112 ;
break;
default:
V_6 = 0 ;
break;
}
if ( V_6 ) {
for ( V_33 = 0 ; V_33 < V_6 ; V_33 ++ ) {
if ( V_107 < V_108 [ V_33 ] . V_5 ) {
V_2 -> V_113 = V_108 [ V_33 ] . V_113 * 10 ;
break;
}
}
}
V_20 = F_6 ( V_2 , 0xd2e2 , 1 ) ;
if ( V_20 )
goto error;
for ( V_33 = 0 ; V_33 < 10 ; V_33 ++ ) {
F_21 ( 10 ) ;
V_20 = F_9 ( V_2 , 0xd2e6 , 0 , 1 ,
& V_7 [ 0 ] ) ;
if ( V_20 )
goto error;
if ( ! V_7 [ 0 ] )
break;
}
V_20 = F_8 ( V_2 , 0xd2e1 , 3 , 1 , 1 ) ;
if ( V_20 )
goto error;
}
error:
return V_20 ;
}
static int F_28 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 = 0 ;
T_1 V_114 , V_115 ;
int V_116 ;
F_11 ( L_21 , V_26 ) ;
if ( V_2 -> V_117 ) {
V_20 = F_7 ( V_2 , 0xd07c , & V_114 ) ;
if ( V_20 )
goto error;
V_20 = F_7 ( V_2 , 0xd07d , & V_115 ) ;
if ( V_20 )
goto error;
V_116 = ( 0xffff / \
( 9 * ( V_2 -> V_118 + V_2 -> V_119 ) - \
11 * ( V_2 -> V_120 + V_2 -> V_121 ) ) ) * \
( 10 * ( V_114 + V_115 ) - \
11 * ( V_2 -> V_120 + V_2 -> V_121 ) ) ;
if ( V_116 < 0 )
V_116 = 0 ;
else if ( V_116 > 0xffff )
V_116 = 0xffff ;
V_2 -> V_116 = V_116 ;
} else {
V_2 -> V_116 = 0 ;
}
error:
return V_20 ;
}
static int F_29 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 ;
if ( F_30 ( V_122 , V_2 -> V_123 ) )
return 0 ;
V_2 -> V_123 = V_122 + F_31 ( 1200 ) ;
V_20 = F_28 ( V_90 ) ;
if ( V_20 )
goto error;
V_20 = F_27 ( V_90 ) ;
if ( V_20 )
goto error;
V_20 = F_26 ( V_90 ) ;
if ( V_20 )
goto error;
error:
return V_20 ;
}
static int F_32 ( struct V_89 * V_90 ,
struct V_124 * V_125 )
{
V_125 -> V_126 = 800 ;
V_125 -> V_127 = 0 ;
V_125 -> V_128 = 0 ;
return 0 ;
}
static int F_33 ( struct V_89 * V_90 , T_6 * V_129 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 = 0 ;
T_1 V_21 ;
* V_129 = 0 ;
V_20 = F_9 ( V_2 , 0xd507 , 6 , 1 , & V_21 ) ;
if ( V_20 )
goto error;
if ( V_21 )
* V_129 |= V_130 | V_131 | V_132 |
V_133 | V_134 ;
if ( ! * V_129 ) {
V_20 = F_9 ( V_2 , 0xd330 , 3 , 1 , & V_21 ) ;
if ( V_20 )
goto error;
if ( V_21 )
* V_129 |= V_130 | V_131 |
V_132 ;
}
if ( ! * V_129 ) {
V_20 = F_9 ( V_2 , 0xd333 , 7 , 1 , & V_21 ) ;
if ( V_20 )
goto error;
if ( V_21 )
* V_129 |= V_130 | V_131 ;
}
if ( ! * V_129 ) {
V_20 = F_9 ( V_2 , 0xd334 , 6 , 1 , & V_21 ) ;
if ( V_20 )
goto error;
if ( V_21 )
* V_129 |= V_130 | V_131 ;
}
if ( ! * V_129 ) {
V_20 = F_9 ( V_2 , 0xd1a0 , 6 , 1 , & V_21 ) ;
if ( V_20 )
goto error;
if ( V_21 )
* V_129 |= V_130 ;
}
V_20 = F_29 ( V_90 ) ;
error:
return V_20 ;
}
static int F_34 ( struct V_89 * V_90 , T_3 * V_105 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 ;
V_20 = F_29 ( V_90 ) ;
* V_105 = V_2 -> V_105 ;
return V_20 ;
}
static int F_35 ( struct V_89 * V_90 , T_2 * V_135 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 ;
V_20 = F_29 ( V_90 ) ;
* V_135 = V_2 -> V_116 ;
return V_20 ;
}
static int F_36 ( struct V_89 * V_90 , T_2 * V_113 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 ;
V_20 = F_29 ( V_90 ) ;
* V_113 = V_2 -> V_113 ;
return V_20 ;
}
static int F_37 ( struct V_89 * V_90 , T_3 * V_106 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 ;
V_20 = F_29 ( V_90 ) ;
* V_106 = V_2 -> V_106 ;
return V_20 ;
}
static int F_38 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 ;
F_11 ( L_21 , V_26 ) ;
V_20 = F_23 ( V_2 , 0 ) ;
if ( V_20 )
goto error;
V_20 = F_22 ( V_2 , 0 ) ;
error:
return V_20 ;
}
static int F_39 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
int V_20 , V_33 , V_6 ;
T_1 V_136 , V_137 ;
struct V_138 * V_139 ;
F_11 ( L_21 , V_26 ) ;
V_20 = F_20 ( V_2 , 0 ) ;
if ( V_20 )
goto error;
V_20 = F_22 ( V_2 , 1 ) ;
if ( V_20 )
goto error;
V_20 = F_6 ( V_2 , 0xd73a , 0xa4 ) ;
if ( V_20 )
goto error;
for ( V_33 = 0 ; V_33 < sizeof( V_2 -> V_11 . V_140 ) ; V_33 ++ ) {
V_20 = F_6 ( V_2 , 0x9bf2 + V_33 ,
V_2 -> V_11 . V_140 [ V_33 ] ) ;
if ( V_20 )
goto error;
}
V_20 = F_17 ( V_2 ) ;
if ( V_20 )
goto error;
V_20 = F_6 ( V_2 , 0xd416 , 0x14 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd700 , 1 , 1 , 1 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd700 , 2 , 1 , 0 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd371 , 1 , 1 , 1 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd392 , 1 , 1 , 1 ) ;
if ( V_20 )
goto error;
F_11 ( L_27 , V_26 ) ;
V_6 = F_15 ( V_141 ) ;
V_139 = V_141 ;
for ( V_33 = 0 ; V_33 < V_6 ; V_33 ++ ) {
V_20 = F_8 ( V_2 , V_139 [ V_33 ] . V_10 , V_139 [ V_33 ] . V_19 ,
V_139 [ V_33 ] . V_6 , V_139 [ V_33 ] . V_5 ) ;
if ( V_20 )
goto error;
}
F_11 ( L_28 , V_26 ) ;
switch ( V_2 -> V_11 . V_46 ) {
case V_142 :
V_6 = F_15 ( V_143 ) ;
V_139 = V_143 ;
break;
case V_144 :
case V_145 :
case V_146 :
V_6 = F_15 ( V_147 ) ;
V_139 = V_147 ;
break;
case V_148 :
V_6 = F_15 ( V_149 ) ;
V_139 = V_149 ;
break;
case V_150 :
V_6 = F_15 ( V_151 ) ;
V_139 = V_151 ;
break;
case V_152 :
V_6 = F_15 ( V_153 ) ;
V_139 = V_153 ;
break;
case V_154 :
case V_155 :
V_6 = F_15 ( V_156 ) ;
V_139 = V_156 ;
break;
case V_157 :
V_6 = F_15 ( V_158 ) ;
V_139 = V_158 ;
break;
case V_47 :
case V_51 :
V_6 = F_15 ( V_159 ) ;
V_139 = V_159 ;
break;
case V_160 :
default:
V_6 = F_15 ( V_161 ) ;
V_139 = V_161 ;
break;
}
for ( V_33 = 0 ; V_33 < V_6 ; V_33 ++ ) {
V_20 = F_8 ( V_2 , V_139 [ V_33 ] . V_10 , V_139 [ V_33 ] . V_19 ,
V_139 [ V_33 ] . V_6 , V_139 [ V_33 ] . V_5 ) ;
if ( V_20 )
goto error;
}
F_11 ( L_29 , V_26 ) ;
V_136 = 0 ;
V_137 = 0 ;
switch ( V_2 -> V_11 . V_162 ) {
case V_163 :
V_136 = 1 ;
break;
case V_164 :
V_137 = 1 ;
break;
case V_165 :
default:
break;
}
V_20 = F_8 ( V_2 , 0xd500 , 1 , 1 , V_136 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd500 , 2 , 1 , V_137 ) ;
if ( V_20 )
goto error;
V_20 = F_23 ( V_2 , 1 ) ;
if ( V_20 )
goto error;
V_20 = F_9 ( V_2 , 0x9bee , 0 , 1 ,
& V_2 -> V_117 ) ;
if ( V_20 )
goto error;
if ( V_2 -> V_117 ) {
V_20 = F_7 ( V_2 , 0x9bbd , & V_2 -> V_118 ) ;
if ( V_20 )
goto error;
V_20 = F_7 ( V_2 , 0x9bd0 , & V_2 -> V_120 ) ;
if ( V_20 )
goto error;
V_20 = F_7 ( V_2 , 0x9be2 , & V_2 -> V_119 ) ;
if ( V_20 )
goto error;
V_20 = F_7 ( V_2 , 0x9be4 , & V_2 -> V_121 ) ;
if ( V_20 )
goto error;
}
error:
return V_20 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_33 , V_6 , V_166 , V_20 ;
const struct V_167 * V_168 ;
T_2 V_169 = 0 ;
T_1 V_5 ;
T_1 V_170 [ 4 ] ;
T_1 * V_171 = V_172 ;
F_21 ( 100 ) ;
V_20 = F_7 ( V_2 , 0x98be , & V_5 ) ;
if ( V_20 )
goto error;
else
F_11 ( L_30 , V_26 , V_5 ) ;
if ( V_5 == 0x0c )
goto exit;
F_41 ( L_31 ,
V_173 . F_41 . V_174 ) ;
V_20 = F_42 ( & V_168 , V_171 , V_2 -> V_14 -> V_175 . V_176 ) ;
if ( V_20 ) {
F_12 ( L_32
L_33 \
L_34 ,
V_171 , V_20 ) ;
goto error;
}
F_41 ( L_35 , V_171 ) ;
for ( V_33 = 0 ; V_33 < V_168 -> V_177 ; V_33 ++ )
V_169 += V_168 -> V_178 [ V_33 ] ;
V_170 [ 0 ] = V_169 >> 8 ;
V_170 [ 1 ] = V_169 & 0xff ;
V_170 [ 2 ] = V_168 -> V_177 >> 8 ;
V_170 [ 3 ] = V_168 -> V_177 & 0xff ;
V_20 = F_5 ( V_2 , 0x50fc ,
V_170 , sizeof( V_170 ) ) ;
if ( V_20 )
goto V_179;
#define F_43 0x5100
#define F_44 16
for ( V_166 = V_168 -> V_177 ; V_166 > 0 ; V_166 -= F_44 ) {
V_6 = V_166 ;
if ( V_6 > F_44 )
V_6 = F_44 ;
V_20 = F_5 ( V_2 ,
F_43 + V_168 -> V_177 - V_166 ,
( T_1 * ) & V_168 -> V_178 [ V_168 -> V_177 - V_166 ] , V_6 ) ;
if ( V_20 ) {
F_12 ( L_36 , V_20 ) ;
goto V_179;
}
}
V_20 = F_6 ( V_2 , 0xe205 , 1 ) ;
if ( V_20 )
goto V_179;
for ( V_33 = 0 ; V_33 < 15 ; V_33 ++ ) {
F_21 ( 100 ) ;
V_20 = F_7 ( V_2 , 0x98be , & V_5 ) ;
if ( V_20 )
goto V_179;
F_11 ( L_30 , V_26 , V_5 ) ;
if ( V_5 == 0x0c || V_5 == 0x04 )
break;
}
if ( V_5 == 0x04 ) {
F_12 ( L_37 ) ;
V_20 = - 1 ;
} else if ( V_5 != 0x0c ) {
F_12 ( L_38 ) ;
V_20 = - 1 ;
}
V_179:
F_45 ( V_168 ) ;
error:
exit:
if ( ! V_20 )
F_41 ( L_39 , V_173 . F_41 . V_174 ) ;
return V_20 ;
}
static int F_46 ( struct V_89 * V_90 , int V_180 )
{
int V_20 ;
struct V_1 * V_2 = V_90 -> V_92 ;
F_11 ( L_40 , V_26 , V_180 ) ;
if ( V_2 -> V_11 . V_162 == V_165 )
V_20 = F_8 ( V_2 , 0xd417 , 3 , 1 , V_180 ) ;
else
V_20 = F_8 ( V_2 , 0xd607 , 2 , 1 , V_180 ) ;
return V_20 ;
}
static void F_47 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_92 ;
F_48 ( V_2 ) ;
}
struct V_89 * F_49 ( const struct V_181 * V_11 ,
struct V_182 * V_14 )
{
int V_20 ;
struct V_1 * V_2 = NULL ;
T_1 V_7 [ 4 ] , V_33 ;
V_2 = F_50 ( sizeof( struct V_1 ) , V_183 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_11 , V_11 , sizeof( struct V_181 ) ) ;
if ( V_2 -> V_11 . V_162 != V_165 ) {
V_20 = F_40 ( V_2 ) ;
if ( V_20 )
goto error;
}
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ ) {
V_20 = F_7 ( V_2 , 0x5103 + V_33 , & V_7 [ V_33 ] ) ;
if ( V_20 )
goto error;
}
F_41 ( L_41 , V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] ) ;
V_20 = F_9 ( V_2 , 0xd733 , 4 , 4 , & V_7 [ 2 ] ) ;
if ( V_20 )
goto error;
for ( V_33 = 0 ; V_33 < 2 ; V_33 ++ ) {
V_20 = F_7 ( V_2 , 0x116b + V_33 , & V_7 [ V_33 ] ) ;
if ( V_20 )
goto error;
}
F_11 ( L_42 , V_26 ,
V_7 [ 2 ] , V_7 [ 0 ] , V_7 [ 1 ] ) ;
if ( V_2 -> V_11 . V_162 == V_165 ) {
V_20 = F_8 ( V_2 , 0xd50b , 2 , 1 , 1 ) ;
} else {
V_20 = F_8 ( V_2 , 0xd500 , 3 , 1 , 1 ) ;
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd502 , 4 , 1 , 1 ) ;
}
if ( V_20 )
goto error;
V_20 = F_8 ( V_2 , 0xd520 , 4 , 1 , 1 ) ;
if ( V_20 )
goto error;
for ( V_33 = 0 ; V_33 < sizeof( V_2 -> V_11 . V_24 ) ; V_33 ++ ) {
V_20 = F_10 ( V_2 , V_33 , V_2 -> V_11 . V_24 [ V_33 ] ) ;
if ( V_20 )
goto error;
}
memcpy ( & V_2 -> V_184 . V_96 , & V_173 ,
sizeof( struct V_185 ) ) ;
V_2 -> V_184 . V_92 = V_2 ;
return & V_2 -> V_184 ;
error:
F_48 ( V_2 ) ;
return NULL ;
}
