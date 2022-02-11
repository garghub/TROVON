static int F_1 ( struct V_1 * V_2 , T_1 V_3 , const T_2 * V_4 ,
int V_5 )
{
int V_6 ;
T_2 V_7 [ V_8 ] ;
struct V_9 V_10 [ 1 ] = {
{
. V_11 = V_2 -> V_12 -> V_11 ,
. V_13 = 0 ,
. V_5 = 3 + V_5 ,
. V_7 = V_7 ,
}
} ;
if ( 3 + V_5 > sizeof( V_7 ) ) {
F_2 ( & V_2 -> V_12 -> V_2 ,
L_1 ,
V_3 , V_5 ) ;
return - V_14 ;
}
V_7 [ 0 ] = ( V_3 >> 16 ) & 0xff ;
V_7 [ 1 ] = ( V_3 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_3 >> 0 ) & 0xff ;
memcpy ( & V_7 [ 3 ] , V_4 , V_5 ) ;
V_6 = F_3 ( V_2 -> V_12 -> V_15 , V_10 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_12 -> V_2 , L_2 ,
V_6 , V_3 , V_5 ) ;
V_6 = - V_16 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 , int V_5 )
{
int V_6 ;
T_2 V_7 [ 3 ] = { ( V_3 >> 16 ) & 0xff , ( V_3 >> 8 ) & 0xff ,
( V_3 >> 0 ) & 0xff } ;
struct V_9 V_10 [ 2 ] = {
{
. V_11 = V_2 -> V_12 -> V_11 ,
. V_13 = 0 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7
} , {
. V_11 = V_2 -> V_12 -> V_11 ,
. V_13 = V_17 ,
. V_5 = V_5 ,
. V_7 = V_4
}
} ;
V_6 = F_3 ( V_2 -> V_12 -> V_15 , V_10 , 2 ) ;
if ( V_6 == 2 ) {
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_12 -> V_2 , L_3 ,
V_6 , V_3 , V_5 ) ;
V_6 = - V_16 ;
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
T_2 V_18 )
{
int V_6 ;
T_2 V_19 ;
if ( V_18 != 0xff ) {
V_6 = F_4 ( V_2 , V_3 , & V_19 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_18 ;
V_19 &= ~ V_18 ;
V_4 |= V_19 ;
}
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
T_2 V_18 )
{
int V_6 , V_20 ;
T_2 V_19 ;
V_6 = F_4 ( V_2 , V_3 , & V_19 , 1 ) ;
if ( V_6 )
return V_6 ;
V_19 &= V_18 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
if ( ( V_18 >> V_20 ) & 0x01 )
break;
}
* V_4 = V_19 >> V_20 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_21 * V_22 , int V_23 )
{
#define F_10 212
int V_6 , V_20 , V_24 ;
T_2 V_7 [ 1 + F_10 ] ;
F_11 ( & V_2 -> V_12 -> V_2 , L_4 , V_23 ) ;
if ( V_23 > sizeof( V_7 ) ) {
F_2 ( & V_2 -> V_12 -> V_2 , L_5 , V_23 ) ;
return - V_14 ;
}
for ( V_20 = 0 , V_24 = 0 ; V_20 < V_23 ; V_20 ++ ) {
V_7 [ V_24 ] = V_22 [ V_20 ] . V_4 ;
if ( V_20 == V_23 - 1 || V_22 [ V_20 ] . V_3 != V_22 [ V_20 + 1 ] . V_3 - 1 ) {
V_6 = F_1 ( V_2 , V_22 [ V_20 ] . V_3 - V_24 , V_7 , V_24 + 1 ) ;
if ( V_6 < 0 )
goto V_25;
V_24 = 0 ;
} else {
V_24 ++ ;
}
}
return 0 ;
V_25:
F_11 ( & V_2 -> V_12 -> V_2 , L_6 , V_6 ) ;
return V_6 ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_27 , T_1 V_28 )
{
T_1 V_29 = 0 , V_30 = 0 , V_20 ;
F_11 ( & V_2 -> V_12 -> V_2 , L_7 , V_26 , V_27 , V_28 ) ;
if ( V_26 > V_27 ) {
V_30 = V_26 / V_27 ;
V_26 = V_26 - V_30 * V_27 ;
}
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
if ( V_26 >= V_27 ) {
V_29 += 1 ;
V_26 -= V_27 ;
}
V_26 <<= 1 ;
V_29 <<= 1 ;
}
V_29 = ( V_30 << ( T_1 ) V_28 ) + V_29 ;
F_11 ( & V_2 -> V_12 -> V_2 , L_8 , V_26 , V_27 , V_28 , V_29 , V_29 ) ;
return V_29 ;
}
static int F_13 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
struct V_34 * V_30 = & V_32 -> V_35 ;
int V_6 , V_20 , V_5 ;
const struct V_21 * V_36 ;
T_2 V_7 [ 4 ] ;
T_1 V_37 , V_38 ;
struct V_39 V_22 [] = {
{ 0x80fb24 , 0x00 , 0x08 } ,
{ 0x80004c , 0x00 , 0xff } ,
{ 0x00f641 , V_2 -> V_40 . V_41 , 0xff } ,
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
{ 0x80f985 , V_2 -> V_42 , 0x01 } ,
{ 0x80f986 , V_2 -> V_43 , 0x01 } ,
{ 0x00d827 , 0x00 , 0xff } ,
{ 0x00d829 , 0x00 , 0xff } ,
{ 0x800045 , V_2 -> V_40 . V_44 , 0xff } ,
} ;
V_38 = F_12 ( V_2 , V_2 -> V_40 . clock , 1000000ul , 19ul ) ;
V_7 [ 0 ] = ( V_38 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_38 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_38 >> 16 ) & 0xff ;
V_7 [ 3 ] = ( V_38 >> 24 ) & 0xff ;
F_11 ( & V_2 -> V_12 -> V_2 , L_9 ,
V_2 -> V_40 . clock , V_38 ) ;
V_6 = F_1 ( V_2 , 0x800025 , V_7 , 4 ) ;
if ( V_6 < 0 )
goto V_25;
for ( V_20 = 0 ; V_20 < F_14 ( V_45 ) ; V_20 ++ ) {
if ( V_45 [ V_20 ] . clock == V_2 -> V_40 . clock )
break;
}
if ( V_20 == F_14 ( V_45 ) ) {
F_15 ( & V_2 -> V_12 -> V_2 ,
L_10 ,
V_2 -> V_40 . clock ) ;
goto V_25;
}
V_37 = F_12 ( V_2 , V_45 [ V_20 ] . V_46 , 1000000ul , 19ul ) ;
V_7 [ 0 ] = ( V_37 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_37 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_37 >> 16 ) & 0xff ;
F_11 ( & V_2 -> V_12 -> V_2 , L_11 ,
V_45 [ V_20 ] . V_46 , V_37 ) ;
V_6 = F_1 ( V_2 , 0x80f1cd , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_25;
for ( V_20 = 0 ; V_20 < F_14 ( V_22 ) ; V_20 ++ ) {
V_6 = F_7 ( V_2 , V_22 [ V_20 ] . V_3 , V_22 [ V_20 ] . V_4 ,
V_22 [ V_20 ] . V_18 ) ;
if ( V_6 < 0 )
goto V_25;
}
if ( V_2 -> V_40 . V_47 ) {
V_6 = F_5 ( V_2 , 0x80fba8 , 0x00 ) ;
if ( V_6 < 0 )
goto V_25;
}
if ( V_2 -> V_40 . V_48 == V_49 ) {
V_6 = F_7 ( V_2 , 0x80f9a5 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_7 ( V_2 , 0x80f9b5 , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
} else {
V_6 = F_7 ( V_2 , 0x80f990 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_7 ( V_2 , 0x80f9b5 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
}
F_11 ( & V_2 -> V_12 -> V_2 , L_12 ) ;
switch ( V_2 -> V_40 . V_41 ) {
case V_50 :
case V_51 :
case V_52 :
V_5 = F_14 ( V_53 ) ;
V_36 = V_53 ;
break;
case V_54 :
case V_55 :
case V_56 :
V_5 = F_14 ( V_57 ) ;
V_36 = V_57 ;
break;
default:
V_5 = F_14 ( V_58 ) ;
V_36 = V_58 ;
break;
}
V_6 = F_9 ( V_2 , V_36 , V_5 ) ;
if ( V_6 < 0 )
goto V_25;
F_11 ( & V_2 -> V_12 -> V_2 , L_13 ) ;
switch ( V_2 -> V_40 . V_41 ) {
case V_59 :
V_5 = F_14 ( V_60 ) ;
V_36 = V_60 ;
break;
case V_61 :
V_5 = F_14 ( V_62 ) ;
V_36 = V_62 ;
break;
case V_63 :
V_5 = F_14 ( V_64 ) ;
V_36 = V_64 ;
break;
case V_65 :
V_5 = F_14 ( V_66 ) ;
V_36 = V_66 ;
break;
case V_67 :
V_5 = F_14 ( V_68 ) ;
V_36 = V_68 ;
break;
case V_69 :
V_5 = F_14 ( V_70 ) ;
V_36 = V_70 ;
break;
case V_50 :
V_5 = F_14 ( V_71 ) ;
V_36 = V_71 ;
break;
case V_51 :
V_5 = F_14 ( V_72 ) ;
V_36 = V_72 ;
break;
case V_52 :
V_5 = F_14 ( V_73 ) ;
V_36 = V_73 ;
break;
case V_54 :
V_5 = F_14 ( V_74 ) ;
V_36 = V_74 ;
break;
case V_55 :
V_5 = F_14 ( V_75 ) ;
V_36 = V_75 ;
break;
case V_56 :
V_5 = F_14 ( V_76 ) ;
V_36 = V_76 ;
break;
default:
F_11 ( & V_2 -> V_12 -> V_2 , L_14 ,
V_2 -> V_40 . V_41 ) ;
V_6 = - V_77 ;
goto V_25;
}
V_6 = F_9 ( V_2 , V_36 , V_5 ) ;
if ( V_6 < 0 )
goto V_25;
if ( V_2 -> V_40 . V_48 == V_78 ) {
V_6 = F_7 ( V_2 , 0x00d91c , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_7 ( V_2 , 0x00d917 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_7 ( V_2 , 0x00d916 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
}
switch ( V_2 -> V_40 . V_41 ) {
case V_54 :
case V_55 :
case V_56 :
V_6 = F_5 ( V_2 , 0x800000 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
}
V_2 -> V_79 = 0 ;
V_30 -> V_80 . V_5 = 1 ;
V_30 -> V_80 . V_81 [ 0 ] . V_82 = V_83 ;
V_30 -> V_84 . V_5 = 1 ;
V_30 -> V_84 . V_81 [ 0 ] . V_82 = V_83 ;
V_30 -> V_85 . V_5 = 1 ;
V_30 -> V_85 . V_81 [ 0 ] . V_82 = V_83 ;
V_30 -> V_86 . V_5 = 1 ;
V_30 -> V_86 . V_81 [ 0 ] . V_82 = V_83 ;
V_30 -> V_87 . V_5 = 1 ;
V_30 -> V_87 . V_81 [ 0 ] . V_82 = V_83 ;
V_30 -> V_88 . V_5 = 1 ;
V_30 -> V_88 . V_81 [ 0 ] . V_82 = V_83 ;
F_16 ( & V_2 -> V_89 , F_17 ( 2000 ) ) ;
return 0 ;
V_25:
F_11 ( & V_2 -> V_12 -> V_2 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
int V_6 , V_20 ;
T_2 V_19 ;
F_19 ( & V_2 -> V_89 ) ;
V_6 = F_5 ( V_2 , 0x80004c , 1 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x800000 , 0 ) ;
if ( V_6 < 0 )
goto V_25;
for ( V_20 = 100 , V_19 = 1 ; V_20 && V_19 ; V_20 -- ) {
V_6 = F_6 ( V_2 , 0x80004c , & V_19 ) ;
if ( V_6 < 0 )
goto V_25;
F_20 ( 200 , 10000 ) ;
}
F_11 ( & V_2 -> V_12 -> V_2 , L_15 , V_20 ) ;
if ( V_20 == 0 ) {
V_6 = - V_90 ;
goto V_25;
}
V_6 = F_7 ( V_2 , 0x80fb24 , 0x08 , 0x08 ) ;
if ( V_6 < 0 )
goto V_25;
if ( V_2 -> V_40 . V_48 == V_78 ) {
V_6 = F_7 ( V_2 , 0x00d917 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_7 ( V_2 , 0x00d916 , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
}
return 0 ;
V_25:
F_11 ( & V_2 -> V_12 -> V_2 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_31 * V_32 ,
struct V_91 * V_92 )
{
V_92 -> V_93 = 2000 ;
V_92 -> V_94 = 0 ;
V_92 -> V_95 = 0 ;
return 0 ;
}
static int F_22 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
struct V_34 * V_30 = & V_32 -> V_35 ;
int V_6 , V_20 , V_96 , V_97 ;
T_2 V_19 , V_7 [ 3 ] , V_98 ;
T_1 V_99 , V_100 , V_101 ;
F_11 ( & V_2 -> V_12 -> V_2 , L_16 ,
V_30 -> V_102 , V_30 -> V_79 ) ;
switch ( V_30 -> V_79 ) {
case 6000000 :
V_98 = 0x00 ;
break;
case 7000000 :
V_98 = 0x01 ;
break;
case 8000000 :
V_98 = 0x02 ;
break;
default:
F_11 ( & V_2 -> V_12 -> V_2 , L_17 ) ;
V_6 = - V_14 ;
goto V_25;
}
if ( V_32 -> V_103 . V_104 . V_105 )
V_32 -> V_103 . V_104 . V_105 ( V_32 ) ;
if ( V_30 -> V_79 != V_2 -> V_79 ) {
for ( V_20 = 0 ; V_20 < F_14 ( V_106 ) ; V_20 ++ ) {
if ( V_106 [ V_20 ] . clock == V_2 -> V_40 . clock &&
V_106 [ V_20 ] . V_79 == V_30 -> V_79 ) {
break;
}
}
if ( V_20 == F_14 ( V_106 ) ) {
F_15 ( & V_2 -> V_12 -> V_2 ,
L_18 ,
V_2 -> V_40 . clock ) ;
V_6 = - V_14 ;
goto V_25;
}
V_6 = F_1 ( V_2 , 0x800001 ,
V_106 [ V_20 ] . V_4 , sizeof( V_106 [ V_20 ] . V_4 ) ) ;
}
if ( V_30 -> V_79 != V_2 -> V_79 ) {
V_96 = V_2 -> V_40 . V_96 ? - 1 : 1 ;
for ( V_20 = 0 ; V_20 < F_14 ( V_45 ) ; V_20 ++ ) {
if ( V_45 [ V_20 ] . clock == V_2 -> V_40 . clock )
break;
}
if ( V_20 == F_14 ( V_45 ) ) {
F_15 ( & V_2 -> V_12 -> V_2 ,
L_19 ,
V_2 -> V_40 . clock ) ;
V_6 = - V_14 ;
goto V_25;
}
V_101 = V_45 [ V_20 ] . V_46 ;
if ( V_32 -> V_103 . V_104 . V_107 )
V_32 -> V_103 . V_104 . V_107 ( V_32 , & V_99 ) ;
else
V_99 = 0 ;
V_97 = V_99 ;
while ( V_97 > ( V_101 / 2 ) )
V_97 -= V_101 ;
if ( V_97 >= 0 )
V_96 *= - 1 ;
else
V_97 *= - 1 ;
V_100 = F_12 ( V_2 , V_97 , V_101 , 23ul ) ;
if ( V_96 == - 1 )
V_100 = 0x800000 - V_100 ;
if ( V_2 -> V_40 . V_44 == V_108 )
V_100 /= 2 ;
V_7 [ 0 ] = ( V_100 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_100 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_100 >> 16 ) & 0x7f ;
if ( V_99 == 0 )
V_7 [ 2 ] = 0 ;
V_6 = F_1 ( V_2 , 0x800029 , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_25;
V_2 -> V_79 = V_30 -> V_79 ;
}
V_6 = F_7 ( V_2 , 0x80f904 , V_98 , 0x03 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x800040 , 0x00 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x800047 , 0x00 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_7 ( V_2 , 0x80f999 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
if ( V_30 -> V_102 <= 230000000 )
V_19 = 0x00 ;
else
V_19 = 0x01 ;
V_6 = F_5 ( V_2 , 0x80004b , V_19 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x800000 , 0x00 ) ;
if ( V_6 < 0 )
goto V_25;
return 0 ;
V_25:
F_11 ( & V_2 -> V_12 -> V_2 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_23 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
struct V_34 * V_30 = & V_32 -> V_35 ;
int V_6 ;
T_2 V_7 [ 8 ] ;
F_11 ( & V_2 -> V_12 -> V_2 , L_20 ) ;
V_6 = F_4 ( V_2 , 0x80f900 , V_7 , sizeof( V_7 ) ) ;
if ( V_6 < 0 )
goto V_25;
switch ( ( V_7 [ 0 ] >> 0 ) & 3 ) {
case 0 :
V_30 -> V_109 = V_110 ;
break;
case 1 :
V_30 -> V_109 = V_111 ;
break;
}
switch ( ( V_7 [ 1 ] >> 0 ) & 3 ) {
case 0 :
V_30 -> V_112 = V_113 ;
break;
case 1 :
V_30 -> V_112 = V_114 ;
break;
case 2 :
V_30 -> V_112 = V_115 ;
break;
case 3 :
V_30 -> V_112 = V_116 ;
break;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 7 ) {
case 0 :
V_30 -> V_117 = V_118 ;
break;
case 1 :
V_30 -> V_117 = V_119 ;
break;
case 2 :
V_30 -> V_117 = V_120 ;
break;
case 3 :
V_30 -> V_117 = V_121 ;
break;
}
switch ( ( V_7 [ 3 ] >> 0 ) & 3 ) {
case 0 :
V_30 -> V_122 = V_123 ;
break;
case 1 :
V_30 -> V_122 = V_124 ;
break;
case 2 :
V_30 -> V_122 = V_125 ;
break;
}
switch ( ( V_7 [ 4 ] >> 0 ) & 3 ) {
case 0 :
V_30 -> V_79 = 6000000 ;
break;
case 1 :
V_30 -> V_79 = 7000000 ;
break;
case 2 :
V_30 -> V_79 = 8000000 ;
break;
}
switch ( ( V_7 [ 6 ] >> 0 ) & 7 ) {
case 0 :
V_30 -> V_126 = V_127 ;
break;
case 1 :
V_30 -> V_126 = V_128 ;
break;
case 2 :
V_30 -> V_126 = V_129 ;
break;
case 3 :
V_30 -> V_126 = V_130 ;
break;
case 4 :
V_30 -> V_126 = V_131 ;
break;
case 5 :
V_30 -> V_126 = V_132 ;
break;
}
switch ( ( V_7 [ 7 ] >> 0 ) & 7 ) {
case 0 :
V_30 -> V_133 = V_127 ;
break;
case 1 :
V_30 -> V_133 = V_128 ;
break;
case 2 :
V_30 -> V_133 = V_129 ;
break;
case 3 :
V_30 -> V_133 = V_130 ;
break;
case 4 :
V_30 -> V_133 = V_131 ;
break;
case 5 :
V_30 -> V_133 = V_132 ;
break;
}
return 0 ;
V_25:
F_11 ( & V_2 -> V_12 -> V_2 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_24 ( struct V_31 * V_32 , T_3 * V_134 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
int V_6 ;
T_2 V_19 ;
* V_134 = 0 ;
V_6 = F_6 ( V_2 , 0x800047 , & V_19 ) ;
if ( V_6 < 0 )
goto V_25;
if ( V_19 == 0x01 )
* V_134 |= V_135 ;
if ( V_19 != 0x02 ) {
V_6 = F_8 ( V_2 , 0x80f5a9 , & V_19 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
if ( V_19 )
* V_134 |= V_135 | V_136 |
V_137 ;
V_6 = F_8 ( V_2 , 0x80f999 , & V_19 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
if ( V_19 )
* V_134 |= V_135 | V_136 |
V_137 | V_138 |
V_139 ;
}
V_2 -> V_140 = * V_134 ;
return 0 ;
V_25:
F_11 ( & V_2 -> V_12 -> V_2 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_25 ( struct V_31 * V_32 , T_4 * V_141 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
struct V_34 * V_30 = & V_2 -> V_32 . V_35 ;
int V_6 ;
T_2 V_142 ;
if ( V_30 -> V_84 . V_81 [ 0 ] . V_82 == V_143 ) {
if ( V_2 -> V_144 ) {
* V_141 = F_26 ( V_30 -> V_84 . V_81 [ 0 ] . V_145 , 100 ) ;
} else {
* V_141 = F_26 ( V_30 -> V_84 . V_81 [ 0 ] . V_145 , 1000 ) ;
V_6 = F_6 ( V_2 , 0x80f903 , & V_142 ) ;
if ( V_6 )
goto V_25;
switch ( ( V_142 >> 0 ) & 3 ) {
case 0 :
* V_141 = * V_141 * 0xffff / 23 ;
break;
case 1 :
* V_141 = * V_141 * 0xffff / 26 ;
break;
case 2 :
* V_141 = * V_141 * 0xffff / 32 ;
break;
default:
goto V_25;
}
}
} else {
* V_141 = 0 ;
}
return 0 ;
V_25:
F_11 ( & V_2 -> V_12 -> V_2 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_27 ( struct V_31 * V_32 , T_4 * V_80 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
struct V_34 * V_30 = & V_2 -> V_32 . V_35 ;
int V_6 , V_19 , V_146 ;
T_2 V_142 , V_147 , V_7 [ 7 ] ;
if ( V_2 -> V_144 ) {
V_6 = F_6 ( V_2 , 0x800048 , & V_142 ) ;
if ( V_6 < 0 )
goto V_25;
* V_80 = V_142 * 0xffff / 100 ;
} else {
V_6 = F_6 ( V_2 , 0x8000f7 , & V_142 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_4 ( V_2 , 0x80f900 , V_7 , 7 ) ;
if ( V_6 < 0 )
goto V_25;
if ( V_30 -> V_102 <= 300000000 )
V_147 = 7 ;
else
V_147 = 4 ;
V_146 = ( V_142 - 100 - V_147 ) -
V_148 [ ( ( V_7 [ 3 ] >> 0 ) & 3 ) ] [ ( ( V_7 [ 6 ] >> 0 ) & 7 ) ] ;
if ( V_146 < - 15 )
V_19 = 0 ;
else if ( ( V_146 >= - 15 ) && ( V_146 < 0 ) )
V_19 = ( 2 * ( V_146 + 15 ) ) / 3 ;
else if ( ( V_146 >= 0 ) && ( V_146 < 20 ) )
V_19 = 4 * V_146 + 10 ;
else if ( ( V_146 >= 20 ) && ( V_146 < 35 ) )
V_19 = ( 2 * ( V_146 - 20 ) ) / 3 + 90 ;
else
V_19 = 100 ;
* V_80 = V_19 * 0xffff / 100 ;
}
return 0 ;
V_25:
F_11 ( & V_2 -> V_12 -> V_2 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_28 ( struct V_31 * V_32 , T_1 * V_149 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
* V_149 = ( V_2 -> V_88 - V_2 -> V_150 ) ;
V_2 -> V_150 = V_2 -> V_88 ;
return 0 ;
}
static int F_29 ( struct V_31 * V_32 , T_1 * V_151 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
* V_151 = V_2 -> V_152 ;
return 0 ;
}
static int F_30 ( struct V_31 * V_32 , int V_153 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
int V_6 ;
F_11 ( & V_2 -> V_12 -> V_2 , L_21 , V_153 ) ;
V_6 = F_7 ( V_2 , 0x00fa04 , V_153 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
return 0 ;
V_25:
F_11 ( & V_2 -> V_12 -> V_2 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_31 ( struct V_31 * V_32 , int V_154 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
int V_6 ;
F_11 ( & V_2 -> V_12 -> V_2 , L_22 , V_154 ) ;
V_6 = F_7 ( V_2 , 0x80f993 , V_154 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
return 0 ;
V_25:
F_11 ( & V_2 -> V_12 -> V_2 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_32 ( struct V_31 * V_32 , int V_155 , T_4 V_156 ,
int V_154 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
int V_6 ;
T_2 V_157 [ 2 ] = { ( V_156 >> 0 ) & 0xff , ( V_156 >> 8 ) & 0xff } ;
F_11 ( & V_2 -> V_12 -> V_2 , L_23 ,
V_155 , V_156 , V_154 ) ;
if ( V_156 > 0x1fff )
return 0 ;
V_6 = F_1 ( V_2 , 0x80f996 , V_157 , 2 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x80f994 , V_154 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x80f995 , V_155 ) ;
if ( V_6 < 0 )
goto V_25;
return 0 ;
V_25:
F_11 ( & V_2 -> V_12 -> V_2 , L_6 , V_6 ) ;
return V_6 ;
}
static void F_33 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = F_34 ( V_159 , struct V_1 , V_89 . V_159 ) ;
struct V_34 * V_30 = & V_2 -> V_32 . V_35 ;
int V_6 , V_19 , V_20 , V_5 ;
T_2 V_142 , V_7 [ 7 ] ;
F_11 ( & V_2 -> V_12 -> V_2 , L_20 ) ;
if ( V_2 -> V_140 & V_135 ) {
if ( V_2 -> V_144 ) {
V_6 = F_6 ( V_2 , 0x80004a , & V_142 ) ;
V_19 = - V_142 * 1000 ;
} else {
V_6 = F_6 ( V_2 , 0x8000f7 , & V_142 ) ;
V_19 = ( V_142 - 100 ) * 1000 ;
}
if ( V_6 )
goto V_25;
V_30 -> V_80 . V_5 = 1 ;
V_30 -> V_80 . V_81 [ 0 ] . V_82 = V_143 ;
V_30 -> V_80 . V_81 [ 0 ] . V_145 = V_19 ;
} else {
V_30 -> V_80 . V_5 = 1 ;
V_30 -> V_80 . V_81 [ 0 ] . V_82 = V_83 ;
}
if ( V_2 -> V_140 & V_137 ) {
T_1 V_160 ;
const struct V_161 * V_162 ;
V_6 = F_4 ( V_2 , 0x80002c , V_7 , 3 ) ;
if ( V_6 )
goto V_25;
V_160 = ( V_7 [ 2 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | ( V_7 [ 0 ] << 0 ) ;
V_6 = F_6 ( V_2 , 0x80f78b , & V_142 ) ;
if ( V_6 )
goto V_25;
if ( V_142 )
V_160 /= V_142 ;
V_6 = F_6 ( V_2 , 0x80f900 , & V_142 ) ;
if ( V_6 )
goto V_25;
switch ( ( V_142 >> 0 ) & 3 ) {
case 0 :
V_160 *= 4 ;
break;
case 1 :
V_160 *= 1 ;
break;
case 2 :
V_160 *= 2 ;
break;
default:
goto V_163;
}
V_6 = F_6 ( V_2 , 0x80f903 , & V_142 ) ;
if ( V_6 )
goto V_25;
switch ( ( V_142 >> 0 ) & 3 ) {
case 0 :
V_5 = F_14 ( V_164 ) ;
V_162 = V_164 ;
break;
case 1 :
V_5 = F_14 ( V_165 ) ;
V_162 = V_165 ;
break;
case 2 :
V_5 = F_14 ( V_166 ) ;
V_162 = V_166 ;
break;
default:
goto V_163;
}
for ( V_20 = 0 ; V_20 < V_5 ; V_20 ++ ) {
V_19 = V_162 [ V_20 ] . V_141 * 1000 ;
if ( V_160 < V_162 [ V_20 ] . V_4 )
break;
}
V_30 -> V_84 . V_5 = 1 ;
V_30 -> V_84 . V_81 [ 0 ] . V_82 = V_143 ;
V_30 -> V_84 . V_81 [ 0 ] . V_145 = V_19 ;
} else {
V_30 -> V_84 . V_5 = 1 ;
V_30 -> V_84 . V_81 [ 0 ] . V_82 = V_83 ;
}
if ( V_2 -> V_140 & V_139 ) {
T_4 V_167 , V_168 ;
T_1 V_169 ;
V_6 = F_4 ( V_2 , 0x800032 , V_7 , 7 ) ;
if ( V_6 )
goto V_25;
V_167 = ( V_7 [ 1 ] << 8 ) | ( V_7 [ 0 ] << 0 ) ;
V_169 = ( V_7 [ 4 ] << 16 ) | ( V_7 [ 3 ] << 8 ) | V_7 [ 2 ] ;
V_168 = ( V_7 [ 6 ] << 8 ) | ( V_7 [ 5 ] << 0 ) ;
V_2 -> V_152 += V_167 ;
V_2 -> V_170 += V_168 ;
V_2 -> V_88 += V_169 ;
V_2 -> V_87 += V_168 * 204 * 8 ;
V_30 -> V_85 . V_5 = 1 ;
V_30 -> V_85 . V_81 [ 0 ] . V_82 = V_171 ;
V_30 -> V_85 . V_81 [ 0 ] . V_172 = V_2 -> V_170 ;
V_30 -> V_86 . V_5 = 1 ;
V_30 -> V_86 . V_81 [ 0 ] . V_82 = V_171 ;
V_30 -> V_86 . V_81 [ 0 ] . V_172 = V_2 -> V_152 ;
V_30 -> V_87 . V_5 = 1 ;
V_30 -> V_87 . V_81 [ 0 ] . V_82 = V_171 ;
V_30 -> V_87 . V_81 [ 0 ] . V_172 = V_2 -> V_87 ;
V_30 -> V_88 . V_5 = 1 ;
V_30 -> V_88 . V_81 [ 0 ] . V_82 = V_171 ;
V_30 -> V_88 . V_81 [ 0 ] . V_172 = V_2 -> V_88 ;
}
V_163:
F_16 ( & V_2 -> V_89 , F_17 ( 2000 ) ) ;
return;
V_25:
F_11 ( & V_2 -> V_12 -> V_2 , L_6 , V_6 ) ;
}
static int F_35 ( struct V_173 * V_12 ,
const struct V_174 * V_175 )
{
struct V_176 * V_40 = V_12 -> V_2 . V_177 ;
struct V_1 * V_2 ;
int V_6 ;
T_2 V_7 [ 8 ] ;
T_1 V_3 ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_178 ) ;
if ( V_2 == NULL ) {
V_6 = - V_179 ;
F_15 ( & V_12 -> V_2 , L_24 ) ;
goto V_25;
}
V_2 -> V_12 = V_12 ;
F_37 ( & V_2 -> V_89 , F_33 ) ;
memcpy ( & V_2 -> V_40 , V_40 , sizeof( struct V_176 ) ) ;
if ( V_2 -> V_40 . clock != 12000000 ) {
V_6 = - V_77 ;
F_15 ( & V_2 -> V_12 -> V_2 ,
L_25 ,
V_2 -> V_40 . clock ) ;
goto V_180;
}
switch ( V_2 -> V_40 . V_41 ) {
case V_50 :
case V_51 :
case V_52 :
case V_54 :
case V_55 :
case V_56 :
V_2 -> V_181 = true ;
V_3 = 0x004bfc ;
break;
default:
V_2 -> V_144 = true ;
V_3 = 0x0083e9 ;
break;
}
V_6 = F_4 ( V_2 , V_3 , & V_7 [ 0 ] , 4 ) ;
if ( V_6 < 0 )
goto V_180;
V_6 = F_4 ( V_2 , 0x804191 , & V_7 [ 4 ] , 4 ) ;
if ( V_6 < 0 )
goto V_180;
F_38 ( & V_2 -> V_12 -> V_2 ,
L_26 ,
V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] , V_7 [ 4 ] , V_7 [ 5 ] , V_7 [ 6 ] ,
V_7 [ 7 ] ) ;
switch ( V_2 -> V_40 . V_41 ) {
case V_50 :
case V_51 :
case V_52 :
case V_54 :
case V_55 :
case V_56 :
break;
default:
V_6 = F_5 ( V_2 , 0x80004c , 1 ) ;
if ( V_6 < 0 )
goto V_180;
V_6 = F_5 ( V_2 , 0x800000 , 0 ) ;
if ( V_6 < 0 )
goto V_180;
}
switch ( V_2 -> V_40 . V_48 ) {
case V_182 :
V_2 -> V_43 = true ;
break;
case V_78 :
V_2 -> V_42 = true ;
break;
case V_49 :
default:
break;
}
memcpy ( & V_2 -> V_32 . V_103 , & V_183 , sizeof( struct V_184 ) ) ;
V_2 -> V_32 . V_33 = V_2 ;
* V_40 -> V_32 = & V_2 -> V_32 ;
if ( V_40 -> V_103 ) {
V_40 -> V_103 -> V_185 = F_32 ;
V_40 -> V_103 -> V_186 = F_31 ;
}
F_39 ( V_12 , V_2 ) ;
F_38 ( & V_2 -> V_12 -> V_2 , L_27 ) ;
return 0 ;
V_180:
F_40 ( V_2 ) ;
V_25:
F_11 ( & V_12 -> V_2 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_41 ( struct V_173 * V_12 )
{
struct V_1 * V_2 = F_42 ( V_12 ) ;
F_11 ( & V_2 -> V_12 -> V_2 , L_20 ) ;
V_2 -> V_32 . V_103 . V_187 = NULL ;
V_2 -> V_32 . V_33 = NULL ;
F_40 ( V_2 ) ;
return 0 ;
}
