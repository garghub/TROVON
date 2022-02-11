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
F_3 ( & V_2 -> V_14 -> V_15 , L_1 \
L_2 , V_16 , V_6 , V_3 , V_5 ) ;
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
F_3 ( & V_2 -> V_14 -> V_15 , L_3 \
L_2 , V_16 , V_6 , V_3 , V_5 ) ;
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
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_22 , T_1 V_23 , T_1 V_24 )
{
T_1 V_25 = 0 , V_26 = 0 , V_21 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_27 , V_22 , V_23 , V_24 ) ;
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
F_10 ( & V_2 -> V_14 -> V_15 , L_5 ,
V_27 , V_22 , V_23 , V_24 , V_25 , V_25 ) ;
return V_25 ;
}
static void F_11 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
F_12 ( V_2 ) ;
}
static int F_13 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_6 , V_21 , V_5 ;
const struct V_31 * V_32 ;
T_2 V_7 [ 4 ] ;
T_1 V_33 , V_34 ;
struct V_35 V_36 [] = {
{ 0x80fb24 , 0x00 , 0x08 } ,
{ 0x80004c , 0x00 , 0xff } ,
{ 0x00f641 , V_2 -> V_11 . V_37 , 0xff } ,
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
{ 0x80f985 , V_2 -> V_38 , 0x01 } ,
{ 0x80f986 , V_2 -> V_39 , 0x01 } ,
{ 0x00d827 , 0x00 , 0xff } ,
{ 0x00d829 , 0x00 , 0xff } ,
} ;
V_34 = F_9 ( V_2 , V_2 -> V_11 . clock , 1000000ul , 19ul ) ;
V_7 [ 0 ] = ( V_34 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_34 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_34 >> 16 ) & 0xff ;
V_7 [ 3 ] = ( V_34 >> 24 ) & 0xff ;
F_10 ( & V_2 -> V_14 -> V_15 , L_6 ,
V_27 , V_2 -> V_11 . clock , V_34 ) ;
V_6 = F_1 ( V_2 , 0x800025 , V_7 , 4 ) ;
if ( V_6 < 0 )
goto V_40;
for ( V_21 = 0 ; V_21 < F_14 ( V_41 ) ; V_21 ++ ) {
if ( V_41 [ V_21 ] . clock == V_2 -> V_11 . clock )
break;
}
V_33 = F_9 ( V_2 , V_41 [ V_21 ] . V_42 , 1000000ul , 19ul ) ;
V_7 [ 0 ] = ( V_33 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_33 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_33 >> 16 ) & 0xff ;
F_10 ( & V_2 -> V_14 -> V_15 , L_7 ,
V_27 , V_41 [ V_21 ] . V_42 , V_33 ) ;
V_6 = F_1 ( V_2 , 0x80f1cd , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_40;
for ( V_21 = 0 ; V_21 < F_14 ( V_36 ) ; V_21 ++ ) {
V_6 = F_7 ( V_2 , V_36 [ V_21 ] . V_3 , V_36 [ V_21 ] . V_4 ,
V_36 [ V_21 ] . V_19 ) ;
if ( V_6 < 0 )
goto V_40;
}
if ( V_2 -> V_11 . V_43 == V_44 ) {
V_6 = F_7 ( V_2 , 0x80f9a5 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_7 ( V_2 , 0x80f9b5 , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
} else {
V_6 = F_7 ( V_2 , 0x80f990 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_7 ( V_2 , 0x80f9b5 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
}
F_10 ( & V_2 -> V_14 -> V_15 , L_8 , V_27 ) ;
V_5 = F_14 ( V_45 ) ;
V_32 = V_45 ;
for ( V_21 = 0 ; V_21 < V_5 ; V_21 ++ ) {
V_6 = F_5 ( V_2 , V_32 [ V_21 ] . V_3 , V_32 [ V_21 ] . V_4 ) ;
if ( V_6 < 0 )
goto V_40;
}
F_10 ( & V_2 -> V_14 -> V_15 , L_9 ,
V_27 ) ;
switch ( V_2 -> V_11 . V_37 ) {
case V_46 :
V_5 = F_14 ( V_47 ) ;
V_32 = V_47 ;
break;
case V_48 :
V_5 = F_14 ( V_49 ) ;
V_32 = V_49 ;
break;
case V_50 :
V_5 = F_14 ( V_51 ) ;
V_32 = V_51 ;
break;
case V_52 :
V_5 = F_14 ( V_53 ) ;
V_32 = V_53 ;
break;
case V_54 :
V_5 = F_14 ( V_55 ) ;
V_32 = V_55 ;
break;
case V_56 :
V_5 = F_14 ( V_57 ) ;
V_32 = V_57 ;
break;
default:
F_10 ( & V_2 -> V_14 -> V_15 , L_10 ,
V_27 , V_2 -> V_11 . V_37 ) ;
V_6 = - V_58 ;
goto V_40;
}
for ( V_21 = 0 ; V_21 < V_5 ; V_21 ++ ) {
V_6 = F_5 ( V_2 , V_32 [ V_21 ] . V_3 , V_32 [ V_21 ] . V_4 ) ;
if ( V_6 < 0 )
goto V_40;
}
if ( V_2 -> V_11 . V_43 == V_59 ) {
V_6 = F_7 ( V_2 , 0x00d91c , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_7 ( V_2 , 0x00d917 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_7 ( V_2 , 0x00d916 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
}
V_2 -> V_60 = 0 ;
return 0 ;
V_40:
F_10 ( & V_2 -> V_14 -> V_15 , L_11 , V_27 , V_6 ) ;
return V_6 ;
}
static int F_15 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_6 , V_21 ;
T_2 V_20 ;
V_6 = F_5 ( V_2 , 0x80004c , 1 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_5 ( V_2 , 0x800000 , 0 ) ;
if ( V_6 < 0 )
goto V_40;
for ( V_21 = 100 , V_20 = 1 ; V_21 && V_20 ; V_21 -- ) {
V_6 = F_6 ( V_2 , 0x80004c , & V_20 ) ;
if ( V_6 < 0 )
goto V_40;
F_16 ( 200 , 10000 ) ;
}
F_10 ( & V_2 -> V_14 -> V_15 , L_12 , V_27 , V_21 ) ;
if ( V_21 == 0 ) {
V_6 = - V_61 ;
goto V_40;
}
V_6 = F_7 ( V_2 , 0x80fb24 , 0x08 , 0x08 ) ;
if ( V_6 < 0 )
goto V_40;
if ( V_2 -> V_11 . V_43 == V_59 ) {
V_6 = F_7 ( V_2 , 0x00d917 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_7 ( V_2 , 0x00d916 , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
}
return 0 ;
V_40:
F_10 ( & V_2 -> V_14 -> V_15 , L_11 , V_27 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_28 * V_29 ,
struct V_62 * V_63 )
{
V_63 -> V_64 = 800 ;
V_63 -> V_65 = 0 ;
V_63 -> V_66 = 0 ;
return 0 ;
}
static int F_18 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
struct V_67 * V_26 = & V_29 -> V_68 ;
int V_6 , V_21 , V_69 , V_70 ;
T_2 V_20 , V_7 [ 3 ] , V_71 ;
T_1 V_72 , V_73 , V_74 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_13 ,
V_27 , V_26 -> V_75 , V_26 -> V_60 ) ;
switch ( V_26 -> V_60 ) {
case 6000000 :
V_71 = 0x00 ;
break;
case 7000000 :
V_71 = 0x01 ;
break;
case 8000000 :
V_71 = 0x02 ;
break;
default:
F_10 ( & V_2 -> V_14 -> V_15 , L_14 ,
V_27 ) ;
V_6 = - V_76 ;
goto V_40;
}
if ( V_29 -> V_77 . V_78 . V_79 )
V_29 -> V_77 . V_78 . V_79 ( V_29 ) ;
if ( V_26 -> V_60 != V_2 -> V_60 ) {
for ( V_21 = 0 ; V_21 < F_14 ( V_80 ) ; V_21 ++ ) {
if ( V_80 [ V_21 ] . clock == V_2 -> V_11 . clock &&
V_80 [ V_21 ] . V_60 == V_26 -> V_60 ) {
break;
}
}
V_6 = F_1 ( V_2 , 0x800001 ,
V_80 [ V_21 ] . V_4 , sizeof( V_80 [ V_21 ] . V_4 ) ) ;
}
if ( V_26 -> V_60 != V_2 -> V_60 ) {
V_69 = V_2 -> V_11 . V_69 ? - 1 : 1 ;
for ( V_21 = 0 ; V_21 < F_14 ( V_41 ) ; V_21 ++ ) {
if ( V_41 [ V_21 ] . clock == V_2 -> V_11 . clock )
break;
}
V_74 = V_41 [ V_21 ] . V_42 ;
if ( V_29 -> V_77 . V_78 . V_81 )
V_29 -> V_77 . V_78 . V_81 ( V_29 , & V_72 ) ;
else
V_72 = 0 ;
V_70 = V_72 ;
while ( V_70 > ( V_74 / 2 ) )
V_70 -= V_74 ;
if ( V_70 >= 0 )
V_69 *= - 1 ;
else
V_70 *= - 1 ;
V_73 = F_9 ( V_2 , V_70 , V_74 , 23ul ) ;
if ( V_69 == - 1 )
V_73 = 0x800000 - V_73 ;
V_6 = F_6 ( V_2 , 0x800045 , & V_20 ) ;
if ( V_6 < 0 )
goto V_40;
if ( V_20 == 1 )
V_73 /= 2 ;
V_7 [ 0 ] = ( V_73 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_73 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_73 >> 16 ) & 0x7f ;
V_6 = F_1 ( V_2 , 0x800029 , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_40;
V_2 -> V_60 = V_26 -> V_60 ;
}
V_6 = F_7 ( V_2 , 0x80f904 , V_71 , 0x03 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_5 ( V_2 , 0x800040 , 0x00 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_5 ( V_2 , 0x800047 , 0x00 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_7 ( V_2 , 0x80f999 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
if ( V_26 -> V_75 <= 230000000 )
V_20 = 0x00 ;
else
V_20 = 0x01 ;
V_6 = F_5 ( V_2 , 0x80004b , V_20 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_5 ( V_2 , 0x800000 , 0x00 ) ;
if ( V_6 < 0 )
goto V_40;
return 0 ;
V_40:
F_10 ( & V_2 -> V_14 -> V_15 , L_11 , V_27 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
struct V_67 * V_26 = & V_29 -> V_68 ;
int V_6 ;
T_2 V_7 [ 8 ] ;
F_10 ( & V_2 -> V_14 -> V_15 , L_15 , V_27 ) ;
V_6 = F_4 ( V_2 , 0x80f900 , V_7 , sizeof( V_7 ) ) ;
if ( V_6 < 0 )
goto V_40;
switch ( ( V_7 [ 0 ] >> 0 ) & 3 ) {
case 0 :
V_26 -> V_82 = V_83 ;
break;
case 1 :
V_26 -> V_82 = V_84 ;
break;
}
switch ( ( V_7 [ 1 ] >> 0 ) & 3 ) {
case 0 :
V_26 -> V_85 = V_86 ;
break;
case 1 :
V_26 -> V_85 = V_87 ;
break;
case 2 :
V_26 -> V_85 = V_88 ;
break;
case 3 :
V_26 -> V_85 = V_89 ;
break;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 7 ) {
case 0 :
V_26 -> V_90 = V_91 ;
break;
case 1 :
V_26 -> V_90 = V_92 ;
break;
case 2 :
V_26 -> V_90 = V_93 ;
break;
case 3 :
V_26 -> V_90 = V_94 ;
break;
}
switch ( ( V_7 [ 3 ] >> 0 ) & 3 ) {
case 0 :
V_26 -> V_95 = V_96 ;
break;
case 1 :
V_26 -> V_95 = V_97 ;
break;
case 2 :
V_26 -> V_95 = V_98 ;
break;
}
switch ( ( V_7 [ 4 ] >> 0 ) & 3 ) {
case 0 :
V_26 -> V_60 = 6000000 ;
break;
case 1 :
V_26 -> V_60 = 7000000 ;
break;
case 2 :
V_26 -> V_60 = 8000000 ;
break;
}
switch ( ( V_7 [ 6 ] >> 0 ) & 7 ) {
case 0 :
V_26 -> V_99 = V_100 ;
break;
case 1 :
V_26 -> V_99 = V_101 ;
break;
case 2 :
V_26 -> V_99 = V_102 ;
break;
case 3 :
V_26 -> V_99 = V_103 ;
break;
case 4 :
V_26 -> V_99 = V_104 ;
break;
case 5 :
V_26 -> V_99 = V_105 ;
break;
}
switch ( ( V_7 [ 7 ] >> 0 ) & 7 ) {
case 0 :
V_26 -> V_106 = V_100 ;
break;
case 1 :
V_26 -> V_106 = V_101 ;
break;
case 2 :
V_26 -> V_106 = V_102 ;
break;
case 3 :
V_26 -> V_106 = V_103 ;
break;
case 4 :
V_26 -> V_106 = V_104 ;
break;
case 5 :
V_26 -> V_106 = V_105 ;
break;
}
return 0 ;
V_40:
F_10 ( & V_2 -> V_14 -> V_15 , L_11 , V_27 , V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_28 * V_29 , T_3 * V_107 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_6 ;
T_2 V_20 ;
* V_107 = 0 ;
V_6 = F_6 ( V_2 , 0x800047 , & V_20 ) ;
if ( V_6 < 0 )
goto V_40;
if ( V_20 == 0x01 )
* V_107 |= V_108 ;
if ( V_20 != 0x02 ) {
V_6 = F_8 ( V_2 , 0x80f5a9 , & V_20 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
if ( V_20 )
* V_107 |= V_108 | V_109 |
V_110 ;
V_6 = F_8 ( V_2 , 0x80f999 , & V_20 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
if ( V_20 )
* V_107 |= V_108 | V_109 |
V_110 | V_111 |
V_112 ;
}
return 0 ;
V_40:
F_10 ( & V_2 -> V_14 -> V_15 , L_11 , V_27 , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_28 * V_29 , T_4 * V_113 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_6 , V_21 , V_5 ;
T_2 V_7 [ 3 ] , V_20 ;
T_1 V_114 ;
const struct V_115 * V_116 ( V_117 ) ;
V_6 = F_4 ( V_2 , 0x80002c , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_40;
V_114 = ( V_7 [ 2 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | V_7 [ 0 ] ;
V_6 = F_6 ( V_2 , 0x80f903 , & V_20 ) ;
if ( V_6 < 0 )
goto V_40;
switch ( ( V_20 >> 0 ) & 3 ) {
case 0 :
V_5 = F_14 ( V_118 ) ;
V_117 = V_118 ;
break;
case 1 :
V_5 = F_14 ( V_119 ) ;
V_117 = V_119 ;
break;
case 2 :
V_5 = F_14 ( V_120 ) ;
V_117 = V_120 ;
break;
default:
goto V_40;
}
for ( V_21 = 0 ; V_21 < V_5 ; V_21 ++ ) {
V_20 = V_117 [ V_21 ] . V_113 ;
if ( V_114 < V_117 [ V_21 ] . V_4 )
break;
}
* V_113 = V_20 * 10 ;
return 0 ;
V_40:
F_10 ( & V_2 -> V_14 -> V_15 , L_11 , V_27 , V_6 ) ;
return V_6 ;
}
static int F_22 ( struct V_28 * V_29 , T_4 * V_121 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_6 ;
T_2 V_122 ;
V_6 = F_6 ( V_2 , 0x800048 , & V_122 ) ;
if ( V_6 < 0 )
goto V_40;
* V_121 = V_122 * 0xffff / 100 ;
return 0 ;
V_40:
F_10 ( & V_2 -> V_14 -> V_15 , L_11 , V_27 , V_6 ) ;
return V_6 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
T_1 V_123 , V_124 ;
T_4 V_125 ;
T_2 V_7 [ 7 ] ;
if ( F_24 ( V_126 , V_2 -> V_127 + F_25 ( 500 ) ) ) {
V_6 = F_4 ( V_2 , 0x800032 , V_7 , sizeof( V_7 ) ) ;
if ( V_6 < 0 )
goto V_40;
V_125 = ( V_7 [ 1 ] << 8 ) + V_7 [ 0 ] ;
V_123 = ( V_7 [ 4 ] << 16 ) + ( V_7 [ 3 ] << 8 ) + V_7 [ 2 ] ;
V_124 = ( V_7 [ 6 ] << 8 ) + V_7 [ 5 ] ;
if ( V_124 < V_125 ) {
V_125 = 1000 ;
V_2 -> V_128 = 0xffffffff ;
} else {
V_124 -= ( T_1 ) V_125 ;
if ( V_124 == 0 ) {
V_2 -> V_128 = 0xffffffff ;
} else {
V_123 -= ( T_1 ) V_125 * 8 * 8 ;
V_124 *= 8 * 8 ;
V_2 -> V_128 = V_123 * ( 0xffffffff / V_124 ) ;
}
}
V_2 -> V_129 += V_125 ;
V_2 -> V_127 = V_126 ;
}
return 0 ;
V_40:
F_10 ( & V_2 -> V_14 -> V_15 , L_11 , V_27 , V_6 ) ;
return V_6 ;
}
static int F_26 ( struct V_28 * V_29 , T_1 * V_128 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_6 ;
V_6 = F_23 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_128 = V_2 -> V_128 ;
return 0 ;
}
static int F_27 ( struct V_28 * V_29 , T_1 * V_130 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_6 ;
V_6 = F_23 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_130 = V_2 -> V_129 ;
return 0 ;
}
static int F_28 ( struct V_28 * V_29 , int V_131 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_6 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_16 , V_27 , V_131 ) ;
V_6 = F_7 ( V_2 , 0x00fa04 , V_131 , 0x01 ) ;
if ( V_6 < 0 )
goto V_40;
return 0 ;
V_40:
F_10 ( & V_2 -> V_14 -> V_15 , L_11 , V_27 , V_6 ) ;
return V_6 ;
}
struct V_28 * F_29 ( const struct V_132 * V_133 ,
struct V_134 * V_14 )
{
int V_6 ;
struct V_1 * V_2 ;
T_2 V_7 [ 8 ] ;
F_10 ( & V_14 -> V_15 , L_15 , V_27 ) ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_135 ) ;
if ( V_2 == NULL )
goto V_40;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_11 , V_133 , sizeof( struct V_132 ) ) ;
if ( V_2 -> V_11 . clock != 12000000 ) {
F_31 ( & V_2 -> V_14 -> V_15 , L_17 \
L_18 ,
V_16 , V_2 -> V_11 . clock ) ;
goto V_40;
}
V_6 = F_4 ( V_2 , 0x0083e9 , & V_7 [ 0 ] , 4 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_4 ( V_2 , 0x804191 , & V_7 [ 4 ] , 4 ) ;
if ( V_6 < 0 )
goto V_40;
F_32 ( & V_2 -> V_14 -> V_15 , L_19 \
L_20 , V_16 , V_7 [ 0 ] , V_7 [ 1 ] ,
V_7 [ 2 ] , V_7 [ 3 ] , V_7 [ 4 ] , V_7 [ 5 ] , V_7 [ 6 ] , V_7 [ 7 ] ) ;
V_6 = F_5 ( V_2 , 0x80004c , 1 ) ;
if ( V_6 < 0 )
goto V_40;
V_6 = F_5 ( V_2 , 0x800000 , 0 ) ;
if ( V_6 < 0 )
goto V_40;
switch ( V_2 -> V_11 . V_43 ) {
case V_136 :
V_2 -> V_39 = true ;
break;
case V_59 :
V_2 -> V_38 = true ;
break;
case V_44 :
default:
break;
}
memcpy ( & V_2 -> V_29 . V_77 , & V_137 , sizeof( struct V_138 ) ) ;
V_2 -> V_29 . V_30 = V_2 ;
return & V_2 -> V_29 ;
V_40:
F_12 ( V_2 ) ;
return NULL ;
}
