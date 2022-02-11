static int F_1 ( struct V_1 * V_2 , T_1 V_3 , const T_2 * V_4 ,
int V_5 )
{
int V_6 ;
T_2 V_7 [ 3 + V_5 ] ;
struct V_8 V_9 [ 1 ] = {
{
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = 0 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
V_7 [ 0 ] = ( V_3 >> 16 ) & 0xff ;
V_7 [ 1 ] = ( V_3 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_3 >> 0 ) & 0xff ;
memcpy ( & V_7 [ 3 ] , V_4 , V_5 ) ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_3 ( V_15 L_1 ,
V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 , int V_5 )
{
int V_6 ;
T_2 V_7 [ 3 ] = { ( V_3 >> 16 ) & 0xff , ( V_3 >> 8 ) & 0xff ,
( V_3 >> 0 ) & 0xff } ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = 0 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7
} , {
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = V_18 ,
. V_5 = V_5 ,
. V_7 = V_4
}
} ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
V_6 = 0 ;
} else {
F_3 ( V_15 L_2 ,
V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
return F_4 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_19 )
{
int V_6 ;
T_2 V_20 ;
if ( V_19 != 0xff ) {
V_6 = F_4 ( V_2 , V_3 , & V_20 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_19 ;
V_20 &= ~ V_19 ;
V_4 |= V_20 ;
}
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
T_2 V_19 )
{
int V_6 , V_21 ;
T_2 V_20 ;
V_6 = F_4 ( V_2 , V_3 , & V_20 , 1 ) ;
if ( V_6 )
return V_6 ;
V_20 &= V_19 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
if ( ( V_19 >> V_21 ) & 0x01 )
break;
}
* V_4 = V_20 >> V_21 ;
return 0 ;
}
static T_1 F_9 ( T_1 V_22 , T_1 V_23 , T_1 V_24 )
{
T_1 V_25 = 0 , V_26 = 0 , V_21 ;
F_10 ( L_3 , V_16 , V_22 , V_23 , V_24 ) ;
if ( V_22 > V_23 ) {
V_26 = V_22 / V_23 ;
V_22 = V_22 - V_26 * V_23 ;
}
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
if ( V_22 >= V_23 ) {
V_25 += 1 ;
V_22 -= V_23 ;
}
V_22 <<= 1 ;
V_25 <<= 1 ;
}
V_25 = ( V_26 << ( T_1 ) V_24 ) + V_25 ;
F_10 ( L_4 , V_16 , V_22 , V_23 , V_24 , V_25 , V_25 ) ;
return V_25 ;
}
static void F_11 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
F_12 ( V_2 ) ;
}
static int F_13 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
int V_6 , V_21 , V_5 ;
const struct V_30 * V_31 ;
T_2 V_7 [ 4 ] ;
T_1 V_32 , V_33 ;
struct V_34 V_35 [] = {
{ 0x80fb24 , 0x00 , 0x08 } ,
{ 0x80004c , 0x00 , 0xff } ,
{ 0x00f641 , V_2 -> V_11 . V_36 , 0xff } ,
{ 0x80f5ca , 0x01 , 0x01 } ,
{ 0x80f715 , 0x01 , 0x01 } ,
{ 0x00f41f , 0x04 , 0x04 } ,
{ 0x00f41a , 0x01 , 0x01 } ,
{ 0x80f731 , 0x00 , 0x01 } ,
{ 0x00d91e , 0x00 , 0x01 } ,
{ 0x00d919 , 0x00 , 0x01 } ,
{ 0x80f732 , 0x00 , 0x01 } ,
{ 0x00d91f , 0x00 , 0x01 } ,
{ 0x00d91a , 0x00 , 0x01 } ,
{ 0x80f730 , 0x00 , 0x01 } ,
{ 0x80f778 , 0x00 , 0xff } ,
{ 0x80f73c , 0x01 , 0x01 } ,
{ 0x80f776 , 0x00 , 0x01 } ,
{ 0x00d8fd , 0x01 , 0xff } ,
{ 0x00d830 , 0x01 , 0xff } ,
{ 0x00d831 , 0x00 , 0xff } ,
{ 0x00d832 , 0x00 , 0xff } ,
{ 0x80f985 , V_2 -> V_37 , 0x01 } ,
{ 0x80f986 , V_2 -> V_38 , 0x01 } ,
{ 0x00d827 , 0x00 , 0xff } ,
{ 0x00d829 , 0x00 , 0xff } ,
} ;
V_33 = F_9 ( V_2 -> V_11 . clock , 1000000ul , 19ul ) ;
V_7 [ 0 ] = ( V_33 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_33 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_33 >> 16 ) & 0xff ;
V_7 [ 3 ] = ( V_33 >> 24 ) & 0xff ;
F_10 ( L_5 , V_16 , V_2 -> V_11 . clock ,
V_33 ) ;
V_6 = F_1 ( V_2 , 0x800025 , V_7 , 4 ) ;
if ( V_6 < 0 )
goto V_39;
for ( V_21 = 0 ; V_21 < F_14 ( V_40 ) ; V_21 ++ ) {
if ( V_40 [ V_21 ] . clock == V_2 -> V_11 . clock )
break;
}
V_32 = F_9 ( V_40 [ V_21 ] . V_41 , 1000000ul , 19ul ) ;
V_7 [ 0 ] = ( V_32 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_32 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_32 >> 16 ) & 0xff ;
F_10 ( L_6 , V_16 , V_40 [ V_21 ] . V_41 ,
V_32 ) ;
V_6 = F_1 ( V_2 , 0x80f1cd , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_39;
for ( V_21 = 0 ; V_21 < F_14 ( V_35 ) ; V_21 ++ ) {
V_6 = F_7 ( V_2 , V_35 [ V_21 ] . V_3 , V_35 [ V_21 ] . V_4 ,
V_35 [ V_21 ] . V_19 ) ;
if ( V_6 < 0 )
goto V_39;
}
if ( V_2 -> V_11 . V_42 == V_43 ) {
V_6 = F_7 ( V_2 , 0x80f9a5 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_39;
V_6 = F_7 ( V_2 , 0x80f9b5 , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_39;
} else {
V_6 = F_7 ( V_2 , 0x80f990 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_39;
V_6 = F_7 ( V_2 , 0x80f9b5 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_39;
}
F_10 ( L_7 , V_16 ) ;
V_5 = F_14 ( V_44 ) ;
V_31 = V_44 ;
for ( V_21 = 0 ; V_21 < V_5 ; V_21 ++ ) {
V_6 = F_5 ( V_2 , V_31 [ V_21 ] . V_3 , V_31 [ V_21 ] . V_4 ) ;
if ( V_6 < 0 )
goto V_39;
}
F_10 ( L_8 ,
V_16 ) ;
switch ( V_2 -> V_11 . V_36 ) {
case V_45 :
V_5 = F_14 ( V_46 ) ;
V_31 = V_46 ;
break;
case V_47 :
V_5 = F_14 ( V_48 ) ;
V_31 = V_48 ;
break;
case V_49 :
V_5 = F_14 ( V_50 ) ;
V_31 = V_50 ;
break;
case V_51 :
V_5 = F_14 ( V_52 ) ;
V_31 = V_52 ;
break;
default:
F_10 ( L_9 , V_16 ,
V_2 -> V_11 . V_36 ) ;
V_6 = - V_53 ;
goto V_39;
}
for ( V_21 = 0 ; V_21 < V_5 ; V_21 ++ ) {
V_6 = F_5 ( V_2 , V_31 [ V_21 ] . V_3 , V_31 [ V_21 ] . V_4 ) ;
if ( V_6 < 0 )
goto V_39;
}
V_2 -> V_54 = 0 ;
return 0 ;
V_39:
F_10 ( L_10 , V_16 , V_6 ) ;
return V_6 ;
}
static int F_15 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
int V_6 , V_21 ;
T_2 V_20 ;
V_6 = F_5 ( V_2 , 0x80004c , 1 ) ;
if ( V_6 < 0 )
goto V_39;
V_6 = F_5 ( V_2 , 0x800000 , 0 ) ;
if ( V_6 < 0 )
goto V_39;
for ( V_21 = 100 , V_20 = 1 ; V_21 && V_20 ; V_21 -- ) {
V_6 = F_6 ( V_2 , 0x80004c , & V_20 ) ;
if ( V_6 < 0 )
goto V_39;
F_16 ( 200 , 10000 ) ;
}
F_10 ( L_11 , V_16 , V_21 ) ;
if ( V_21 == 0 ) {
V_6 = - V_55 ;
goto V_39;
}
V_6 = F_7 ( V_2 , 0x80fb24 , 0x08 , 0x08 ) ;
if ( V_6 < 0 )
goto V_39;
if ( V_2 -> V_11 . V_42 == V_56 ) {
V_6 = F_7 ( V_2 , 0x00d917 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_39;
V_6 = F_7 ( V_2 , 0x00d916 , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_39;
}
return 0 ;
V_39:
F_10 ( L_10 , V_16 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_27 * V_28 ,
struct V_57 * V_58 )
{
V_58 -> V_59 = 800 ;
V_58 -> V_60 = 0 ;
V_58 -> V_61 = 0 ;
return 0 ;
}
static int F_18 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
struct V_62 * V_26 = & V_28 -> V_63 ;
int V_6 , V_21 , V_64 ;
T_2 V_20 , V_7 [ 3 ] , V_65 ;
T_1 V_66 , V_67 , V_68 ;
F_10 ( L_12 , V_16 , V_26 -> V_69 ,
V_26 -> V_54 ) ;
switch ( V_26 -> V_54 ) {
case 6000000 :
V_65 = 0x00 ;
break;
case 7000000 :
V_65 = 0x01 ;
break;
case 8000000 :
V_65 = 0x02 ;
break;
default:
F_10 ( L_13 , V_16 ) ;
V_6 = - V_70 ;
goto V_39;
}
if ( V_28 -> V_71 . V_72 . V_73 )
V_28 -> V_71 . V_72 . V_73 ( V_28 ) ;
if ( V_26 -> V_54 != V_2 -> V_54 ) {
for ( V_21 = 0 ; V_21 < F_14 ( V_74 ) ; V_21 ++ ) {
if ( V_74 [ V_21 ] . clock == V_2 -> V_11 . clock &&
V_74 [ V_21 ] . V_54 == V_26 -> V_54 ) {
break;
}
}
V_6 = F_1 ( V_2 , 0x800001 ,
V_74 [ V_21 ] . V_4 , sizeof( V_74 [ V_21 ] . V_4 ) ) ;
}
if ( V_26 -> V_54 != V_2 -> V_54 ) {
V_64 = V_2 -> V_11 . V_64 ? - 1 : 1 ;
for ( V_21 = 0 ; V_21 < F_14 ( V_40 ) ; V_21 ++ ) {
if ( V_40 [ V_21 ] . clock == V_2 -> V_11 . clock )
break;
}
V_68 = V_40 [ V_21 ] . V_41 ;
if ( V_28 -> V_71 . V_72 . V_75 )
V_28 -> V_71 . V_72 . V_75 ( V_28 , & V_66 ) ;
else
V_66 = 0 ;
while ( V_66 > ( V_68 / 2 ) )
V_66 -= V_68 ;
if ( V_66 >= 0 )
V_64 *= - 1 ;
else
V_66 *= - 1 ;
V_67 = F_9 ( V_66 , V_68 , 23ul ) ;
if ( V_64 == - 1 )
V_67 *= - 1 ;
V_6 = F_6 ( V_2 , 0x800045 , & V_20 ) ;
if ( V_6 < 0 )
goto V_39;
if ( V_20 == 1 )
V_67 /= 2 ;
V_7 [ 0 ] = ( V_67 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_67 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_67 >> 16 ) & 0x7f ;
V_6 = F_1 ( V_2 , 0x800029 , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_39;
V_2 -> V_54 = V_26 -> V_54 ;
}
V_6 = F_7 ( V_2 , 0x80f904 , V_65 , 0x03 ) ;
if ( V_6 < 0 )
goto V_39;
V_6 = F_5 ( V_2 , 0x800040 , 0x00 ) ;
if ( V_6 < 0 )
goto V_39;
V_6 = F_5 ( V_2 , 0x800047 , 0x00 ) ;
if ( V_6 < 0 )
goto V_39;
V_6 = F_7 ( V_2 , 0x80f999 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_39;
if ( V_26 -> V_69 <= 230000000 )
V_20 = 0x00 ;
else
V_20 = 0x01 ;
V_6 = F_5 ( V_2 , 0x80004b , V_20 ) ;
if ( V_6 < 0 )
goto V_39;
V_6 = F_5 ( V_2 , 0x800000 , 0x00 ) ;
if ( V_6 < 0 )
goto V_39;
return 0 ;
V_39:
F_10 ( L_10 , V_16 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
struct V_62 * V_26 = & V_28 -> V_63 ;
int V_6 ;
T_2 V_7 [ 8 ] ;
F_10 ( L_14 , V_16 ) ;
V_6 = F_4 ( V_2 , 0x80f900 , V_7 , sizeof( V_7 ) ) ;
if ( V_6 < 0 )
goto V_39;
switch ( ( V_7 [ 0 ] >> 0 ) & 3 ) {
case 0 :
V_26 -> V_76 = V_77 ;
break;
case 1 :
V_26 -> V_76 = V_78 ;
break;
}
switch ( ( V_7 [ 1 ] >> 0 ) & 3 ) {
case 0 :
V_26 -> V_79 = V_80 ;
break;
case 1 :
V_26 -> V_79 = V_81 ;
break;
case 2 :
V_26 -> V_79 = V_82 ;
break;
case 3 :
V_26 -> V_79 = V_83 ;
break;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 7 ) {
case 0 :
V_26 -> V_84 = V_85 ;
break;
case 1 :
V_26 -> V_84 = V_86 ;
break;
case 2 :
V_26 -> V_84 = V_87 ;
break;
case 3 :
V_26 -> V_84 = V_88 ;
break;
}
switch ( ( V_7 [ 3 ] >> 0 ) & 3 ) {
case 0 :
V_26 -> V_89 = V_90 ;
break;
case 1 :
V_26 -> V_89 = V_91 ;
break;
case 2 :
V_26 -> V_89 = V_92 ;
break;
}
switch ( ( V_7 [ 4 ] >> 0 ) & 3 ) {
case 0 :
V_26 -> V_54 = 6000000 ;
break;
case 1 :
V_26 -> V_54 = 7000000 ;
break;
case 2 :
V_26 -> V_54 = 8000000 ;
break;
}
switch ( ( V_7 [ 6 ] >> 0 ) & 7 ) {
case 0 :
V_26 -> V_93 = V_94 ;
break;
case 1 :
V_26 -> V_93 = V_95 ;
break;
case 2 :
V_26 -> V_93 = V_96 ;
break;
case 3 :
V_26 -> V_93 = V_97 ;
break;
case 4 :
V_26 -> V_93 = V_98 ;
break;
case 5 :
V_26 -> V_93 = V_99 ;
break;
}
switch ( ( V_7 [ 7 ] >> 0 ) & 7 ) {
case 0 :
V_26 -> V_100 = V_94 ;
break;
case 1 :
V_26 -> V_100 = V_95 ;
break;
case 2 :
V_26 -> V_100 = V_96 ;
break;
case 3 :
V_26 -> V_100 = V_97 ;
break;
case 4 :
V_26 -> V_100 = V_98 ;
break;
case 5 :
V_26 -> V_100 = V_99 ;
break;
}
return 0 ;
V_39:
F_10 ( L_10 , V_16 , V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_27 * V_28 , T_3 * V_101 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
int V_6 ;
T_2 V_20 ;
* V_101 = 0 ;
V_6 = F_6 ( V_2 , 0x800047 , & V_20 ) ;
if ( V_6 < 0 )
goto V_39;
if ( V_20 == 0x01 )
* V_101 |= V_102 ;
if ( V_20 != 0x02 ) {
V_6 = F_8 ( V_2 , 0x80f5a9 , & V_20 , 0x01 ) ;
if ( V_6 < 0 )
goto V_39;
if ( V_20 )
* V_101 |= V_102 | V_103 |
V_104 ;
V_6 = F_8 ( V_2 , 0x80f999 , & V_20 , 0x01 ) ;
if ( V_6 < 0 )
goto V_39;
if ( V_20 )
* V_101 |= V_102 | V_103 |
V_104 | V_105 |
V_106 ;
}
return 0 ;
V_39:
F_10 ( L_10 , V_16 , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_27 * V_28 , T_4 * V_107 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
int V_6 , V_21 , V_5 ;
T_2 V_7 [ 3 ] , V_20 ;
T_1 V_108 ;
const struct V_109 * V_110 ( V_111 ) ;
V_6 = F_4 ( V_2 , 0x80002c , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_39;
V_108 = ( V_7 [ 2 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | V_7 [ 0 ] ;
V_6 = F_6 ( V_2 , 0x80f903 , & V_20 ) ;
if ( V_6 < 0 )
goto V_39;
switch ( ( V_20 >> 0 ) & 3 ) {
case 0 :
V_5 = F_14 ( V_112 ) ;
V_111 = V_112 ;
break;
case 1 :
V_5 = F_14 ( V_113 ) ;
V_111 = V_113 ;
break;
case 2 :
V_5 = F_14 ( V_114 ) ;
V_111 = V_114 ;
break;
default:
goto V_39;
}
for ( V_21 = 0 ; V_21 < V_5 ; V_21 ++ ) {
V_20 = V_111 [ V_21 ] . V_107 ;
if ( V_108 < V_111 [ V_21 ] . V_4 )
break;
}
* V_107 = V_20 * 10 ;
return 0 ;
V_39:
F_10 ( L_10 , V_16 , V_6 ) ;
return V_6 ;
}
static int F_22 ( struct V_27 * V_28 , T_4 * V_115 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
int V_6 ;
T_2 V_116 ;
V_6 = F_6 ( V_2 , 0x800048 , & V_116 ) ;
if ( V_6 < 0 )
goto V_39;
* V_115 = V_116 * 0xffff / 100 ;
return 0 ;
V_39:
F_10 ( L_10 , V_16 , V_6 ) ;
return V_6 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
T_1 V_117 , V_118 ;
T_4 V_119 ;
T_2 V_7 [ 7 ] ;
if ( F_24 ( V_120 , V_2 -> V_121 + F_25 ( 500 ) ) ) {
V_6 = F_4 ( V_2 , 0x800032 , V_7 , sizeof( V_7 ) ) ;
if ( V_6 < 0 )
goto V_39;
V_119 = ( V_7 [ 1 ] << 8 ) + V_7 [ 0 ] ;
V_117 = ( V_7 [ 4 ] << 16 ) + ( V_7 [ 3 ] << 8 ) + V_7 [ 2 ] ;
V_118 = ( V_7 [ 6 ] << 8 ) + V_7 [ 5 ] ;
if ( V_118 < V_119 ) {
V_119 = 1000 ;
V_2 -> V_122 = 0xffffffff ;
} else {
V_118 -= ( T_1 ) V_119 ;
if ( V_118 == 0 ) {
V_2 -> V_122 = 0xffffffff ;
} else {
V_117 -= ( T_1 ) V_119 * 8 * 8 ;
V_118 *= 8 * 8 ;
V_2 -> V_122 = V_117 * ( 0xffffffff / V_118 ) ;
}
}
V_2 -> V_123 += V_119 ;
V_2 -> V_121 = V_120 ;
}
return 0 ;
V_39:
F_10 ( L_10 , V_16 , V_6 ) ;
return V_6 ;
}
static int F_26 ( struct V_27 * V_28 , T_1 * V_122 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
int V_6 ;
V_6 = F_23 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_122 = V_2 -> V_122 ;
return 0 ;
}
static int F_27 ( struct V_27 * V_28 , T_1 * V_124 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
int V_6 ;
V_6 = F_23 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_124 = V_2 -> V_123 ;
return 0 ;
}
static int F_28 ( struct V_27 * V_28 , int V_125 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
int V_6 ;
F_10 ( L_15 , V_16 , V_125 ) ;
V_6 = F_7 ( V_2 , 0x00fa04 , V_125 , 0x01 ) ;
if ( V_6 < 0 )
goto V_39;
return 0 ;
V_39:
F_10 ( L_10 , V_16 , V_6 ) ;
return V_6 ;
}
struct V_27 * F_29 ( const struct V_126 * V_127 ,
struct V_128 * V_14 )
{
int V_6 ;
struct V_1 * V_2 ;
T_2 V_7 [ 8 ] ;
F_10 ( L_16 , V_16 ) ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_129 ) ;
if ( V_2 == NULL )
goto V_39;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_11 , V_127 , sizeof( struct V_126 ) ) ;
if ( V_2 -> V_11 . clock != 12000000 ) {
F_3 ( V_130 L_17 \
L_18 ,
V_2 -> V_11 . clock ) ;
goto V_39;
}
V_6 = F_4 ( V_2 , 0x0083e9 , & V_7 [ 0 ] , 4 ) ;
if ( V_6 < 0 )
goto V_39;
V_6 = F_4 ( V_2 , 0x804191 , & V_7 [ 4 ] , 4 ) ;
if ( V_6 < 0 )
goto V_39;
F_3 ( V_130 L_19 \
L_20 , V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] ,
V_7 [ 4 ] , V_7 [ 5 ] , V_7 [ 6 ] , V_7 [ 7 ] ) ;
switch ( V_2 -> V_11 . V_42 ) {
case V_131 :
V_2 -> V_38 = true ;
break;
case V_56 :
V_2 -> V_37 = true ;
break;
case V_43 :
default:
break;
}
memcpy ( & V_2 -> V_28 . V_71 , & V_132 , sizeof( struct V_133 ) ) ;
V_2 -> V_28 . V_29 = V_2 ;
return & V_2 -> V_28 ;
V_39:
F_12 ( V_2 ) ;
return NULL ;
}
