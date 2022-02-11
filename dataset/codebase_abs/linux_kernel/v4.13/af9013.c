static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
T_1 V_8 ;
T_2 V_9 ;
F_2 ( & V_6 -> V_10 , L_1 , V_3 , V_4 ) ;
switch ( V_3 ) {
case 0 :
case 1 :
V_9 = 0xd735 ;
break;
case 2 :
case 3 :
V_9 = 0xd736 ;
break;
default:
V_7 = - V_11 ;
goto V_12;
}
switch ( V_3 ) {
case 0 :
case 2 :
V_8 = 0 ;
break;
case 1 :
case 3 :
default:
V_8 = 4 ;
break;
}
V_7 = F_3 ( V_2 -> V_13 , V_9 , 0x0f << V_8 ,
V_4 << V_8 ) ;
if ( V_7 )
goto V_12;
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_4 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
F_2 ( & V_6 -> V_10 , L_3 ) ;
V_7 = F_3 ( V_2 -> V_13 , 0xd391 , 0x10 , 0x10 ) ;
if ( V_7 )
goto V_12;
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_5 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
unsigned int V_17 ;
T_1 V_18 [ 5 ] ;
F_2 ( & V_6 -> V_10 , L_3 ) ;
V_7 = F_6 ( V_2 -> V_13 , 0xd391 , & V_17 ) ;
if ( V_7 )
goto V_12;
if ( ! ( ( V_17 >> 4 ) & 0x01 ) ) {
F_2 ( & V_6 -> V_10 , L_4 ) ;
return 0 ;
}
V_7 = F_7 ( V_2 -> V_13 , 0xd387 , V_18 , 5 ) ;
if ( V_7 )
goto V_12;
V_2 -> V_19 = ( V_18 [ 2 ] << 16 ) | ( V_18 [ 1 ] << 8 ) | V_18 [ 0 ] ;
V_2 -> V_20 += ( V_18 [ 4 ] << 8 ) | V_18 [ 3 ] ;
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_8 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
F_2 ( & V_6 -> V_10 , L_3 ) ;
V_7 = F_3 ( V_2 -> V_13 , 0xd2e1 , 0x08 , 0x08 ) ;
if ( V_7 )
goto V_12;
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_21 * V_22 = & V_15 -> V_23 ;
int V_7 , V_24 , V_25 ;
unsigned int V_17 ;
T_1 V_18 [ 3 ] ;
T_3 V_26 ;
const struct V_27 * V_28 ( V_29 ) ;
F_2 ( & V_6 -> V_10 , L_3 ) ;
V_7 = F_6 ( V_2 -> V_13 , 0xd2e1 , & V_17 ) ;
if ( V_7 )
goto V_12;
if ( ! ( ( V_17 >> 3 ) & 0x01 ) ) {
F_2 ( & V_6 -> V_10 , L_4 ) ;
return 0 ;
}
V_7 = F_7 ( V_2 -> V_13 , 0xd2e3 , V_18 , 3 ) ;
if ( V_7 )
goto V_12;
V_26 = ( V_18 [ 2 ] << 16 ) | ( V_18 [ 1 ] << 8 ) | V_18 [ 0 ] ;
V_7 = F_6 ( V_2 -> V_13 , 0xd3c1 , & V_17 ) ;
if ( V_7 )
goto V_12;
switch ( ( V_17 >> 6 ) & 3 ) {
case 0 :
V_25 = F_10 ( V_30 ) ;
V_29 = V_30 ;
break;
case 1 :
V_25 = F_10 ( V_31 ) ;
V_29 = V_31 ;
break;
case 2 :
V_25 = F_10 ( V_32 ) ;
V_29 = V_32 ;
break;
default:
goto V_12;
}
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_17 = V_29 [ V_24 ] . V_33 ;
if ( V_26 < V_29 [ V_24 ] . V_34 )
break;
}
V_2 -> V_33 = V_17 * 10 ;
V_22 -> V_35 . V_36 [ 0 ] . V_37 = 1000 * V_17 ;
V_22 -> V_35 . V_36 [ 0 ] . V_38 = V_39 ;
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_11 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
T_1 V_18 [ 2 ] , V_40 , V_41 ;
int V_42 ;
F_2 ( & V_6 -> V_10 , L_3 ) ;
if ( ! V_2 -> V_43 )
return 0 ;
V_7 = F_7 ( V_2 -> V_13 , 0xd07c , V_18 , 2 ) ;
if ( V_7 )
goto V_12;
V_40 = V_18 [ 0 ] ;
V_41 = V_18 [ 1 ] ;
V_42 = ( 0xffff / \
( 9 * ( V_2 -> V_44 + V_2 -> V_45 ) - \
11 * ( V_2 -> V_46 + V_2 -> V_47 ) ) ) * \
( 10 * ( V_40 + V_41 ) - \
11 * ( V_2 -> V_46 + V_2 -> V_47 ) ) ;
if ( V_42 < 0 )
V_42 = 0 ;
else if ( V_42 > 0xffff )
V_42 = 0xffff ;
V_2 -> V_42 = V_42 ;
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static void F_12 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_13 ( V_49 ,
struct V_1 , V_50 . V_49 ) ;
unsigned int V_51 ;
if ( ! ( V_2 -> V_52 & V_53 ) ) {
V_2 -> V_54 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_33 = 0 ;
}
switch ( V_2 -> V_54 ) {
default:
V_2 -> V_54 = 0 ;
case 0 :
F_11 ( & V_2 -> V_15 ) ;
V_2 -> V_54 ++ ;
V_51 = 300 ;
break;
case 1 :
F_8 ( & V_2 -> V_15 ) ;
V_2 -> V_54 ++ ;
V_51 = 200 ;
break;
case 2 :
F_4 ( & V_2 -> V_15 ) ;
V_2 -> V_54 ++ ;
V_51 = 1000 ;
break;
case 3 :
F_9 ( & V_2 -> V_15 ) ;
V_2 -> V_54 ++ ;
V_51 = 400 ;
break;
case 4 :
F_5 ( & V_2 -> V_15 ) ;
V_2 -> V_54 ++ ;
V_51 = 100 ;
break;
}
F_14 ( & V_2 -> V_50 ,
F_15 ( V_51 ) ) ;
}
static int F_16 ( struct V_14 * V_15 ,
struct V_55 * V_56 )
{
V_56 -> V_57 = 800 ;
V_56 -> V_58 = 0 ;
V_56 -> V_59 = 0 ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_21 * V_22 = & V_15 -> V_23 ;
int V_7 , V_24 , V_60 ;
bool V_61 , V_62 ;
T_1 V_18 [ 6 ] ;
T_3 V_63 , V_64 ;
F_2 ( & V_6 -> V_10 , L_5 ,
V_22 -> V_65 , V_22 -> V_66 ) ;
if ( V_15 -> V_67 . V_68 . V_69 ) {
V_7 = V_15 -> V_67 . V_68 . V_69 ( V_15 ) ;
if ( V_7 )
goto V_12;
}
if ( V_22 -> V_66 != V_2 -> V_66 ) {
for ( V_24 = 0 ; V_24 < F_10 ( V_70 ) ; V_24 ++ ) {
if ( V_70 [ V_24 ] . clock == V_2 -> V_71 &&
V_70 [ V_24 ] . V_66 == V_22 -> V_66 ) {
break;
}
}
if ( V_24 == F_10 ( V_70 ) ) {
V_7 = - V_11 ;
goto V_12;
}
V_7 = F_18 ( V_2 -> V_13 , 0xae00 , V_70 [ V_24 ] . V_34 ,
sizeof( V_70 [ V_24 ] . V_34 ) ) ;
if ( V_7 )
goto V_12;
}
if ( V_22 -> V_66 != V_2 -> V_66 || V_2 -> V_72 ) {
if ( V_15 -> V_67 . V_68 . V_73 ) {
V_7 = V_15 -> V_67 . V_68 . V_73 ( V_15 ,
& V_63 ) ;
if ( V_7 )
goto V_12;
} else {
V_63 = V_2 -> V_63 ;
}
F_2 ( & V_6 -> V_10 , L_6 , V_63 ) ;
V_60 = V_63 ;
while ( V_60 > ( V_2 -> V_71 / 2 ) )
V_60 -= V_2 -> V_71 ;
if ( V_60 < 0 ) {
V_60 *= - 1 ;
V_62 = V_2 -> V_62 ;
} else {
V_62 = ! V_2 -> V_62 ;
}
V_64 = F_19 ( ( V_74 ) V_60 * 0x800000 ,
V_2 -> V_71 ) ;
if ( V_62 )
V_64 = 0x800000 - V_64 ;
V_18 [ 0 ] = ( V_64 >> 0 ) & 0xff ;
V_18 [ 1 ] = ( V_64 >> 8 ) & 0xff ;
V_18 [ 2 ] = ( V_64 >> 16 ) & 0x7f ;
V_64 = 0x800000 - V_64 ;
V_18 [ 3 ] = ( V_64 >> 0 ) & 0xff ;
V_18 [ 4 ] = ( V_64 >> 8 ) & 0xff ;
V_18 [ 5 ] = ( V_64 >> 16 ) & 0x7f ;
V_7 = F_18 ( V_2 -> V_13 , 0xd140 , V_18 , 3 ) ;
if ( V_7 )
goto V_12;
V_7 = F_18 ( V_2 -> V_13 , 0x9be7 , V_18 , 6 ) ;
if ( V_7 )
goto V_12;
}
V_7 = F_3 ( V_2 -> V_13 , 0xd330 , 0x08 , 0x08 ) ;
if ( V_7 )
goto V_12;
V_7 = F_3 ( V_2 -> V_13 , 0xd507 , 0x40 , 0x00 ) ;
if ( V_7 )
goto V_12;
V_7 = F_3 ( V_2 -> V_13 , 0x9bfe , 0x01 , 0x00 ) ;
if ( V_7 )
goto V_12;
V_7 = F_3 ( V_2 -> V_13 , 0x9bc2 , 0x01 , 0x00 ) ;
if ( V_7 )
goto V_12;
V_61 = false ;
memset ( V_18 , 0 , 3 ) ;
switch ( V_22 -> V_75 ) {
case V_76 :
V_61 = true ;
break;
case V_77 :
break;
case V_78 :
V_18 [ 0 ] |= ( 1 << 0 ) ;
break;
default:
F_2 ( & V_6 -> V_10 , L_7 ) ;
V_61 = true ;
}
switch ( V_22 -> V_79 ) {
case V_80 :
V_61 = true ;
break;
case V_81 :
break;
case V_82 :
V_18 [ 0 ] |= ( 1 << 2 ) ;
break;
case V_83 :
V_18 [ 0 ] |= ( 2 << 2 ) ;
break;
case V_84 :
V_18 [ 0 ] |= ( 3 << 2 ) ;
break;
default:
F_2 ( & V_6 -> V_10 , L_8 ) ;
V_61 = true ;
}
switch ( V_22 -> V_85 ) {
case V_86 :
V_61 = true ;
break;
case V_87 :
break;
case V_88 :
V_18 [ 0 ] |= ( 1 << 4 ) ;
break;
case V_89 :
V_18 [ 0 ] |= ( 2 << 4 ) ;
break;
case V_90 :
V_18 [ 0 ] |= ( 3 << 4 ) ;
break;
default:
F_2 ( & V_6 -> V_10 , L_9 ) ;
V_61 = true ;
}
switch ( V_22 -> V_91 ) {
case V_92 :
V_61 = true ;
break;
case V_93 :
break;
case V_94 :
V_18 [ 1 ] |= ( 1 << 6 ) ;
break;
case V_95 :
V_18 [ 1 ] |= ( 2 << 6 ) ;
break;
default:
F_2 ( & V_6 -> V_10 , L_10 ) ;
V_61 = true ;
}
V_18 [ 1 ] |= ( 1 << 4 ) ;
switch ( V_22 -> V_96 ) {
case V_97 :
V_61 = true ;
break;
case V_98 :
break;
case V_99 :
V_18 [ 2 ] |= ( 1 << 0 ) ;
break;
case V_100 :
V_18 [ 2 ] |= ( 2 << 0 ) ;
break;
case V_101 :
V_18 [ 2 ] |= ( 3 << 0 ) ;
break;
case V_102 :
V_18 [ 2 ] |= ( 4 << 0 ) ;
break;
default:
F_2 ( & V_6 -> V_10 , L_11 ) ;
V_61 = true ;
}
switch ( V_22 -> V_103 ) {
case V_97 :
V_61 = true ;
break;
case V_98 :
break;
case V_99 :
V_18 [ 2 ] |= ( 1 << 3 ) ;
break;
case V_100 :
V_18 [ 2 ] |= ( 2 << 3 ) ;
break;
case V_101 :
V_18 [ 2 ] |= ( 3 << 3 ) ;
break;
case V_102 :
V_18 [ 2 ] |= ( 4 << 3 ) ;
break;
case V_104 :
break;
default:
F_2 ( & V_6 -> V_10 , L_12 ) ;
V_61 = true ;
}
switch ( V_22 -> V_66 ) {
case 6000000 :
break;
case 7000000 :
V_18 [ 1 ] |= ( 1 << 2 ) ;
break;
case 8000000 :
V_18 [ 1 ] |= ( 2 << 2 ) ;
break;
default:
F_2 ( & V_6 -> V_10 , L_13 ) ;
V_7 = - V_11 ;
goto V_12;
}
V_7 = F_18 ( V_2 -> V_13 , 0xd3c0 , V_18 , 3 ) ;
if ( V_7 )
goto V_12;
if ( V_61 ) {
V_7 = F_20 ( V_2 -> V_13 , 0xaefd , 0x00 ) ;
if ( V_7 )
goto V_12;
F_2 ( & V_6 -> V_10 , L_14 ) ;
} else {
V_7 = F_20 ( V_2 -> V_13 , 0xaefd , 0x01 ) ;
if ( V_7 )
goto V_12;
V_7 = F_20 ( V_2 -> V_13 , 0xaefe , 0x00 ) ;
if ( V_7 )
goto V_12;
F_2 ( & V_6 -> V_10 , L_15 ) ;
}
V_7 = F_20 ( V_2 -> V_13 , 0xffff , 0x00 ) ;
if ( V_7 )
goto V_12;
V_2 -> V_66 = V_22 -> V_66 ;
V_2 -> V_105 = V_106 ;
V_2 -> V_72 = false ;
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_21 ( struct V_14 * V_15 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
T_1 V_18 [ 3 ] ;
F_2 ( & V_6 -> V_10 , L_3 ) ;
V_7 = F_7 ( V_2 -> V_13 , 0xd3c0 , V_18 , 3 ) ;
if ( V_7 )
goto V_12;
switch ( ( V_18 [ 1 ] >> 6 ) & 3 ) {
case 0 :
V_22 -> V_91 = V_93 ;
break;
case 1 :
V_22 -> V_91 = V_94 ;
break;
case 2 :
V_22 -> V_91 = V_95 ;
break;
}
switch ( ( V_18 [ 0 ] >> 0 ) & 3 ) {
case 0 :
V_22 -> V_75 = V_77 ;
break;
case 1 :
V_22 -> V_75 = V_78 ;
}
switch ( ( V_18 [ 0 ] >> 2 ) & 3 ) {
case 0 :
V_22 -> V_79 = V_81 ;
break;
case 1 :
V_22 -> V_79 = V_82 ;
break;
case 2 :
V_22 -> V_79 = V_83 ;
break;
case 3 :
V_22 -> V_79 = V_84 ;
break;
}
switch ( ( V_18 [ 0 ] >> 4 ) & 7 ) {
case 0 :
V_22 -> V_85 = V_87 ;
break;
case 1 :
V_22 -> V_85 = V_88 ;
break;
case 2 :
V_22 -> V_85 = V_89 ;
break;
case 3 :
V_22 -> V_85 = V_90 ;
break;
}
switch ( ( V_18 [ 2 ] >> 0 ) & 7 ) {
case 0 :
V_22 -> V_96 = V_98 ;
break;
case 1 :
V_22 -> V_96 = V_99 ;
break;
case 2 :
V_22 -> V_96 = V_100 ;
break;
case 3 :
V_22 -> V_96 = V_101 ;
break;
case 4 :
V_22 -> V_96 = V_102 ;
break;
}
switch ( ( V_18 [ 2 ] >> 3 ) & 7 ) {
case 0 :
V_22 -> V_103 = V_98 ;
break;
case 1 :
V_22 -> V_103 = V_99 ;
break;
case 2 :
V_22 -> V_103 = V_100 ;
break;
case 3 :
V_22 -> V_103 = V_101 ;
break;
case 4 :
V_22 -> V_103 = V_102 ;
break;
}
switch ( ( V_18 [ 1 ] >> 2 ) & 3 ) {
case 0 :
V_22 -> V_66 = 6000000 ;
break;
case 1 :
V_22 -> V_66 = 7000000 ;
break;
case 2 :
V_22 -> V_66 = 8000000 ;
break;
}
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_22 ( struct V_14 * V_15 , enum V_52 * V_107 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
unsigned int V_17 ;
if ( F_23 (
V_2 -> V_108 + F_15 ( 2000 ) ) &&
F_24 (
V_2 -> V_105 + F_15 ( 4000 ) )
) {
* V_107 = V_2 -> V_52 ;
return 0 ;
} else {
* V_107 = 0 ;
}
V_7 = F_6 ( V_2 -> V_13 , 0xd507 , & V_17 ) ;
if ( V_7 )
goto V_12;
if ( ( V_17 >> 6 ) & 0x01 )
* V_107 |= V_109 | V_110 | V_111 |
V_112 | V_53 ;
if ( ! * V_107 ) {
V_7 = F_6 ( V_2 -> V_13 , 0xd330 , & V_17 ) ;
if ( V_7 )
goto V_12;
if ( ( V_17 >> 3 ) & 0x01 )
* V_107 |= V_109 | V_110 |
V_111 ;
}
V_2 -> V_52 = * V_107 ;
V_2 -> V_108 = V_106 ;
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_25 ( struct V_14 * V_15 , T_2 * V_33 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
* V_33 = V_2 -> V_33 ;
return 0 ;
}
static int F_26 ( struct V_14 * V_15 , T_2 * V_113 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
* V_113 = V_2 -> V_42 ;
return 0 ;
}
static int F_27 ( struct V_14 * V_15 , T_3 * V_19 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
* V_19 = V_2 -> V_19 ;
return 0 ;
}
static int F_28 ( struct V_14 * V_15 , T_3 * V_20 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
* V_20 = V_2 -> V_20 ;
return 0 ;
}
static int F_29 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 , V_24 , V_25 ;
unsigned int V_17 ;
T_1 V_18 [ 3 ] ;
const struct V_114 * V_115 ;
F_2 ( & V_6 -> V_10 , L_3 ) ;
V_7 = F_3 ( V_2 -> V_13 , 0xd73a , 0x08 , 0x00 ) ;
if ( V_7 )
goto V_12;
V_7 = F_3 ( V_2 -> V_13 , 0xd417 , 0x02 , 0x00 ) ;
if ( V_7 )
goto V_12;
V_7 = F_3 ( V_2 -> V_13 , 0xd417 , 0x10 , 0x00 ) ;
if ( V_7 )
goto V_12;
V_7 = F_18 ( V_2 -> V_13 , 0x9bf2 , V_2 -> V_116 , 4 ) ;
if ( V_7 )
goto V_12;
switch ( V_2 -> V_71 ) {
case 28800000 :
V_17 = 0 ;
break;
case 20480000 :
V_17 = 1 ;
break;
case 28000000 :
V_17 = 2 ;
break;
case 25000000 :
V_17 = 3 ;
break;
default:
V_7 = - V_11 ;
goto V_12;
}
V_7 = F_3 ( V_2 -> V_13 , 0x9bd2 , 0x0f , V_17 ) ;
if ( V_7 )
goto V_12;
V_17 = F_30 ( ( V_74 ) V_2 -> V_71 * 0x80000 , 1000000 ) ;
V_18 [ 0 ] = ( V_17 >> 0 ) & 0xff ;
V_18 [ 1 ] = ( V_17 >> 8 ) & 0xff ;
V_18 [ 2 ] = ( V_17 >> 16 ) & 0xff ;
V_7 = F_18 ( V_2 -> V_13 , 0xd180 , V_18 , 3 ) ;
if ( V_7 )
goto V_12;
F_2 ( & V_6 -> V_10 , L_16 ) ;
V_25 = F_10 ( V_117 ) ;
V_115 = V_117 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
T_2 V_118 = V_115 [ V_24 ] . V_9 ;
T_1 V_119 = F_31 ( V_115 [ V_24 ] . V_8 + V_115 [ V_24 ] . V_25 - 1 , V_115 [ V_24 ] . V_8 ) ;
T_1 V_34 = V_115 [ V_24 ] . V_34 << V_115 [ V_24 ] . V_8 ;
V_7 = F_3 ( V_2 -> V_13 , V_118 , V_119 , V_34 ) ;
if ( V_7 )
goto V_12;
}
F_2 ( & V_6 -> V_10 , L_17 ) ;
switch ( V_2 -> V_120 ) {
case V_121 :
V_25 = F_10 ( V_122 ) ;
V_115 = V_122 ;
break;
case V_123 :
case V_124 :
case V_125 :
V_25 = F_10 ( V_126 ) ;
V_115 = V_126 ;
break;
case V_127 :
V_25 = F_10 ( V_128 ) ;
V_115 = V_128 ;
break;
case V_129 :
V_25 = F_10 ( V_130 ) ;
V_115 = V_130 ;
break;
case V_131 :
V_25 = F_10 ( V_132 ) ;
V_115 = V_132 ;
break;
case V_133 :
case V_134 :
V_25 = F_10 ( V_135 ) ;
V_115 = V_135 ;
break;
case V_136 :
V_25 = F_10 ( V_137 ) ;
V_115 = V_137 ;
break;
case V_138 :
case V_139 :
V_25 = F_10 ( V_140 ) ;
V_115 = V_140 ;
break;
case V_141 :
default:
V_25 = F_10 ( V_142 ) ;
V_115 = V_142 ;
break;
}
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
T_2 V_118 = V_115 [ V_24 ] . V_9 ;
T_1 V_119 = F_31 ( V_115 [ V_24 ] . V_8 + V_115 [ V_24 ] . V_25 - 1 , V_115 [ V_24 ] . V_8 ) ;
T_1 V_34 = V_115 [ V_24 ] . V_34 << V_115 [ V_24 ] . V_8 ;
V_7 = F_3 ( V_2 -> V_13 , V_118 , V_119 , V_34 ) ;
if ( V_7 )
goto V_12;
}
if ( V_2 -> V_143 == 7 )
V_17 = 1 << 3 | V_2 -> V_144 << 1 ;
else
V_17 = 0 << 3 | V_2 -> V_144 << 1 ;
V_7 = F_3 ( V_2 -> V_13 , 0xd500 , 0x0e , V_17 ) ;
if ( V_7 )
goto V_12;
V_7 = F_3 ( V_2 -> V_13 , 0xd730 , 0x01 , 0x01 ) ;
if ( V_7 )
goto V_12;
if ( ! V_2 -> V_43 ) {
V_7 = F_6 ( V_2 -> V_13 , 0x9bee , & V_17 ) ;
if ( V_7 )
goto V_12;
V_2 -> V_43 = ( V_17 >> 0 ) & 0x01 ;
}
if ( V_2 -> V_43 && ! V_2 -> V_44 ) {
V_7 = F_7 ( V_2 -> V_13 , 0x9bbd , & V_2 -> V_44 , 1 ) ;
if ( V_7 )
goto V_12;
V_7 = F_7 ( V_2 -> V_13 , 0x9bd0 , & V_2 -> V_46 , 1 ) ;
if ( V_7 )
goto V_12;
V_7 = F_7 ( V_2 -> V_13 , 0x9be2 , & V_2 -> V_45 , 1 ) ;
if ( V_7 )
goto V_12;
V_7 = F_7 ( V_2 -> V_13 , 0x9be4 , & V_2 -> V_47 , 1 ) ;
if ( V_7 )
goto V_12;
}
V_7 = F_20 ( V_2 -> V_13 , 0xd2e2 , 0x01 ) ;
if ( V_7 )
goto V_12;
V_18 [ 0 ] = ( 10000 >> 0 ) & 0xff ;
V_18 [ 1 ] = ( 10000 >> 8 ) & 0xff ;
V_7 = F_18 ( V_2 -> V_13 , 0xd385 , V_18 , 2 ) ;
if ( V_7 )
goto V_12;
V_7 = F_3 ( V_2 -> V_13 , 0xd392 , 0x02 , 0x02 ) ;
if ( V_7 )
goto V_12;
V_2 -> V_72 = true ;
F_14 ( & V_2 -> V_50 , F_15 ( 400 ) ) ;
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_32 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
unsigned int V_17 ;
F_2 ( & V_6 -> V_10 , L_3 ) ;
F_33 ( & V_2 -> V_50 ) ;
V_7 = F_3 ( V_2 -> V_13 , 0xd730 , 0x01 , 0x00 ) ;
if ( V_7 )
goto V_12;
V_7 = F_3 ( V_2 -> V_13 , 0xd417 , 0x10 , 0x10 ) ;
if ( V_7 )
goto V_12;
V_7 = F_20 ( V_2 -> V_13 , 0xaeff , 0x01 ) ;
if ( V_7 )
goto V_12;
V_7 = F_34 ( V_2 -> V_13 , 0xd417 , V_17 ,
( V_17 >> 1 ) & 0x01 , 5000 , 1000000 ) ;
if ( V_7 )
goto V_12;
if ( ! ( ( V_17 >> 1 ) & 0x01 ) ) {
V_7 = - V_145 ;
goto V_12;
}
V_7 = F_3 ( V_2 -> V_13 , 0xd73a , 0x08 , 0x08 ) ;
if ( V_7 )
goto V_12;
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_35 ( struct V_14 * V_15 , int V_146 )
{
int V_7 ;
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_2 ( & V_6 -> V_10 , L_18 , V_146 ) ;
if ( V_2 -> V_147 == V_146 )
return 0 ;
if ( V_2 -> V_144 == V_148 )
V_7 = F_3 ( V_2 -> V_13 , 0xd417 , 0x08 ,
V_146 << 3 ) ;
else
V_7 = F_3 ( V_2 -> V_13 , 0xd607 , 0x04 ,
V_146 << 2 ) ;
if ( V_7 )
goto V_12;
V_2 -> V_147 = V_146 ;
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static void F_36 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_2 ( & V_6 -> V_10 , L_3 ) ;
F_37 ( V_6 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 , V_24 , V_25 , V_149 ;
unsigned int V_17 ;
T_1 V_18 [ 4 ] ;
T_2 V_150 = 0 ;
const struct V_151 * V_151 ;
const char * V_152 = V_153 ;
F_2 ( & V_6 -> V_10 , L_3 ) ;
V_7 = F_6 ( V_2 -> V_13 , 0x98be , & V_17 ) ;
if ( V_7 )
goto V_12;
F_2 ( & V_6 -> V_10 , L_19 , V_17 ) ;
if ( V_17 == 0x0c )
return 0 ;
F_39 ( & V_6 -> V_10 , L_20 ,
V_154 . V_155 . V_152 ) ;
V_7 = F_40 ( & V_151 , V_152 , & V_6 -> V_10 ) ;
if ( V_7 ) {
F_39 ( & V_6 -> V_10 , L_21 ,
V_152 , V_7 ) ;
goto V_12;
}
F_39 ( & V_6 -> V_10 , L_22 ,
V_152 ) ;
for ( V_24 = 0 ; V_24 < V_151 -> V_156 ; V_24 ++ )
V_150 += V_151 -> V_157 [ V_24 ] ;
V_18 [ 0 ] = ( V_150 >> 8 ) & 0xff ;
V_18 [ 1 ] = ( V_150 >> 0 ) & 0xff ;
V_18 [ 2 ] = ( V_151 -> V_156 >> 8 ) & 0xff ;
V_18 [ 3 ] = ( V_151 -> V_156 >> 0 ) & 0xff ;
V_7 = F_18 ( V_2 -> V_13 , 0x50fc , V_18 , 4 ) ;
if ( V_7 )
goto V_158;
#define F_41 16
for ( V_149 = V_151 -> V_156 ; V_149 > 0 ; V_149 -= F_41 ) {
V_25 = F_42 ( F_41 , V_149 ) ;
V_7 = F_18 ( V_2 -> V_13 ,
0x5100 + V_151 -> V_156 - V_149 ,
& V_151 -> V_157 [ V_151 -> V_156 - V_149 ] ,
V_25 ) ;
if ( V_7 ) {
F_43 ( & V_6 -> V_10 , L_23 ,
V_7 ) ;
goto V_158;
}
}
F_44 ( V_151 ) ;
V_7 = F_20 ( V_2 -> V_13 , 0xe205 , 0x01 ) ;
if ( V_7 )
goto V_12;
V_7 = F_34 ( V_2 -> V_13 , 0x98be , V_17 ,
( V_17 == 0x0c || V_17 == 0x04 ) ,
5000 , 1000000 ) ;
if ( V_7 )
goto V_12;
F_2 ( & V_6 -> V_10 , L_19 , V_17 ) ;
if ( V_17 == 0x04 ) {
V_7 = - V_159 ;
F_43 ( & V_6 -> V_10 , L_24 ) ;
goto V_12;
} else if ( V_17 != 0x0c ) {
V_7 = - V_159 ;
F_43 ( & V_6 -> V_10 , L_25 ) ;
goto V_12;
}
F_39 ( & V_6 -> V_10 , L_26 ,
V_154 . V_155 . V_152 ) ;
return 0 ;
V_158:
F_44 ( V_151 ) ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
struct V_14 * F_45 ( const struct V_160 * V_161 ,
struct V_162 * V_163 )
{
struct V_5 * V_6 ;
struct V_164 V_165 ;
struct V_166 V_167 ;
V_167 . V_71 = V_161 -> clock ;
V_167 . V_120 = V_161 -> V_120 ;
V_167 . V_63 = V_161 -> V_63 ;
V_167 . V_144 = V_161 -> V_144 ;
V_167 . V_143 = 7 ;
V_167 . V_62 = V_161 -> V_62 ;
memcpy ( & V_167 . V_116 , V_161 -> V_116 , sizeof( V_167 . V_116 ) ) ;
memcpy ( & V_167 . V_3 , V_161 -> V_3 , sizeof( V_167 . V_3 ) ) ;
V_167 . V_168 = true ;
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
F_46 ( V_165 . type , L_27 , sizeof( V_165 . type ) ) ;
V_165 . V_9 = V_161 -> V_169 ;
V_165 . V_170 = & V_167 ;
V_6 = F_47 ( V_163 , & V_165 ) ;
if ( ! V_6 || ! V_6 -> V_10 . V_171 )
return NULL ;
return V_167 . V_172 ( V_6 ) ;
}
static struct V_14 * F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_49 ( V_6 ) ;
F_2 ( & V_6 -> V_10 , L_3 ) ;
return & V_2 -> V_15 ;
}
static int F_50 ( struct V_5 * V_6 , T_1 V_173 , T_2 V_118 ,
const T_1 * V_34 , int V_25 )
{
int V_7 ;
T_1 V_18 [ 21 ] ;
struct V_174 V_175 [ 1 ] = {
{
. V_9 = V_6 -> V_9 ,
. V_176 = 0 ,
. V_25 = 3 + V_25 ,
. V_18 = V_18 ,
}
} ;
if ( 3 + V_25 > sizeof( V_18 ) ) {
V_7 = - V_11 ;
goto V_12;
}
V_18 [ 0 ] = ( V_118 >> 8 ) & 0xff ;
V_18 [ 1 ] = ( V_118 >> 0 ) & 0xff ;
V_18 [ 2 ] = V_173 ;
memcpy ( & V_18 [ 3 ] , V_34 , V_25 ) ;
V_7 = F_51 ( V_6 -> V_177 , V_175 , 1 ) ;
if ( V_7 < 0 ) {
goto V_12;
} else if ( V_7 != 1 ) {
V_7 = - V_178 ;
goto V_12;
}
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_52 ( struct V_5 * V_6 , T_1 V_173 , T_2 V_118 ,
T_1 * V_34 , int V_25 )
{
int V_7 ;
T_1 V_18 [ 3 ] ;
struct V_174 V_175 [ 2 ] = {
{
. V_9 = V_6 -> V_9 ,
. V_176 = 0 ,
. V_25 = 3 ,
. V_18 = V_18 ,
} , {
. V_9 = V_6 -> V_9 ,
. V_176 = V_179 ,
. V_25 = V_25 ,
. V_18 = V_34 ,
}
} ;
V_18 [ 0 ] = ( V_118 >> 8 ) & 0xff ;
V_18 [ 1 ] = ( V_118 >> 0 ) & 0xff ;
V_18 [ 2 ] = V_173 ;
V_7 = F_51 ( V_6 -> V_177 , V_175 , 2 ) ;
if ( V_7 < 0 ) {
goto V_12;
} else if ( V_7 != 2 ) {
V_7 = - V_178 ;
goto V_12;
}
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_53 ( void * V_180 , const void * V_157 , T_4 V_181 )
{
struct V_5 * V_6 = V_180 ;
struct V_1 * V_2 = F_49 ( V_6 ) ;
int V_7 , V_24 ;
T_1 V_173 ;
T_2 V_118 = ( ( T_1 * ) V_157 ) [ 0 ] << 8 | ( ( T_1 * ) V_157 ) [ 1 ] << 0 ;
T_1 * V_34 = & ( ( T_1 * ) V_157 ) [ 2 ] ;
const unsigned int V_25 = V_181 - 2 ;
if ( V_2 -> V_144 == V_148 && ( V_118 & 0xff00 ) != 0xae00 ) {
V_173 = 0 << 7 | 0 << 6 | ( V_25 - 1 ) << 2 | 1 << 1 | 1 << 0 ;
V_7 = F_50 ( V_6 , V_173 , V_118 , V_34 , V_25 ) ;
if ( V_7 )
goto V_12;
} else if ( V_118 >= 0x5100 && V_118 < 0x8fff ) {
V_173 = 1 << 7 | 1 << 6 | ( V_25 - 1 ) << 2 | 1 << 1 | 1 << 0 ;
V_7 = F_50 ( V_6 , V_173 , V_118 , V_34 , V_25 ) ;
if ( V_7 )
goto V_12;
} else {
V_173 = 0 << 7 | 0 << 6 | ( 1 - 1 ) << 2 | 1 << 1 | 1 << 0 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_7 = F_50 ( V_6 , V_173 , V_118 + V_24 , V_34 + V_24 , 1 ) ;
if ( V_7 )
goto V_12;
}
}
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_54 ( void * V_180 , const void * V_182 ,
T_4 V_183 , void * V_184 , T_4 V_185 )
{
struct V_5 * V_6 = V_180 ;
struct V_1 * V_2 = F_49 ( V_6 ) ;
int V_7 , V_24 ;
T_1 V_173 ;
T_2 V_118 = ( ( T_1 * ) V_182 ) [ 0 ] << 8 | ( ( T_1 * ) V_182 ) [ 1 ] << 0 ;
T_1 * V_34 = & ( ( T_1 * ) V_184 ) [ 0 ] ;
const unsigned int V_25 = V_185 ;
if ( V_2 -> V_144 == V_148 && ( V_118 & 0xff00 ) != 0xae00 ) {
V_173 = 0 << 7 | 0 << 6 | ( V_25 - 1 ) << 2 | 1 << 1 | 0 << 0 ;
V_7 = F_52 ( V_6 , V_173 , V_118 , V_184 , V_25 ) ;
if ( V_7 )
goto V_12;
} else {
V_173 = 0 << 7 | 0 << 6 | ( 1 - 1 ) << 2 | 1 << 1 | 0 << 0 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_7 = F_52 ( V_6 , V_173 , V_118 + V_24 , V_34 + V_24 , 1 ) ;
if ( V_7 )
goto V_12;
}
}
return 0 ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_55 ( struct V_5 * V_6 ,
const struct V_186 * V_187 )
{
struct V_1 * V_2 ;
struct V_166 * V_167 = V_6 -> V_10 . V_170 ;
struct V_21 * V_22 ;
int V_7 , V_24 ;
T_1 V_188 [ 4 ] ;
static const struct V_189 V_189 = {
. V_190 = F_54 ,
. V_191 = F_53 ,
} ;
static const struct V_192 V_192 = {
. V_193 = 16 ,
. V_194 = 8 ,
} ;
V_2 = F_56 ( sizeof( * V_2 ) , V_195 ) ;
if ( ! V_2 ) {
V_7 = - V_196 ;
goto V_12;
}
V_2 -> V_6 = V_6 ;
F_57 ( V_6 , V_2 ) ;
V_2 -> V_71 = V_167 -> V_71 ;
V_2 -> V_120 = V_167 -> V_120 ;
V_2 -> V_63 = V_167 -> V_63 ;
V_2 -> V_144 = V_167 -> V_144 ;
V_2 -> V_143 = V_167 -> V_143 ;
V_2 -> V_62 = V_167 -> V_62 ;
memcpy ( & V_2 -> V_116 , V_167 -> V_116 , sizeof( V_2 -> V_116 ) ) ;
memcpy ( & V_2 -> V_3 , V_167 -> V_3 , sizeof( V_2 -> V_3 ) ) ;
F_58 ( & V_2 -> V_50 , F_12 ) ;
V_2 -> V_13 = F_59 ( & V_6 -> V_10 , & V_189 , V_6 ,
& V_192 ) ;
if ( F_60 ( V_2 -> V_13 ) ) {
V_7 = F_61 ( V_2 -> V_13 ) ;
goto V_197;
}
if ( V_2 -> V_144 != V_148 ) {
V_7 = F_38 ( V_2 ) ;
if ( V_7 )
goto V_198;
}
V_7 = F_7 ( V_2 -> V_13 , 0x5103 , V_188 ,
sizeof( V_188 ) ) ;
if ( V_7 )
goto V_198;
for ( V_24 = 0 ; V_24 < sizeof( V_2 -> V_3 ) ; V_24 ++ ) {
V_7 = F_1 ( V_2 , V_24 , V_2 -> V_3 [ V_24 ] ) ;
if ( V_7 )
goto V_198;
}
memcpy ( & V_2 -> V_15 . V_67 , & V_154 , sizeof( V_2 -> V_15 . V_67 ) ) ;
if ( ! V_167 -> V_168 )
V_2 -> V_15 . V_67 . V_199 = NULL ;
V_2 -> V_15 . V_16 = V_2 ;
V_167 -> V_172 = F_48 ;
V_22 = & V_2 -> V_15 . V_23 ;
V_22 -> V_35 . V_25 = 1 ;
F_39 ( & V_6 -> V_10 , L_28 ) ;
F_39 ( & V_6 -> V_10 , L_29 ,
V_188 [ 0 ] , V_188 [ 1 ] ,
V_188 [ 2 ] , V_188 [ 3 ] ) ;
return 0 ;
V_198:
F_62 ( V_2 -> V_13 ) ;
V_197:
F_63 ( V_2 ) ;
V_12:
F_2 ( & V_6 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
static int F_64 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_49 ( V_6 ) ;
F_2 ( & V_6 -> V_10 , L_3 ) ;
F_33 ( & V_2 -> V_50 ) ;
F_62 ( V_2 -> V_13 ) ;
F_63 ( V_2 ) ;
return 0 ;
}
