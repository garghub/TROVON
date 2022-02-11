static int F_1 ( struct V_1 * V_2 , T_1 V_3 , const T_2 * V_4 ,
int V_5 )
{
int V_6 ;
T_2 V_7 [ V_8 ] ;
struct V_9 V_10 [ 1 ] = {
{
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_5 = 3 + V_5 ,
. V_7 = V_7 ,
}
} ;
if ( 3 + V_5 > sizeof( V_7 ) ) {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_1 ,
V_17 , V_3 , V_5 ) ;
return - V_18 ;
}
V_7 [ 0 ] = ( V_3 >> 16 ) & 0xff ;
V_7 [ 1 ] = ( V_3 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_3 >> 0 ) & 0xff ;
memcpy ( & V_7 [ 3 ] , V_4 , V_5 ) ;
V_6 = F_3 ( V_2 -> V_15 , V_10 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_15 -> V_16 , L_2 \
L_3 , V_17 , V_6 , V_3 , V_5 ) ;
V_6 = - V_19 ;
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
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7
} , {
. V_11 = V_2 -> V_12 . V_13 ,
. V_14 = V_20 ,
. V_5 = V_5 ,
. V_7 = V_4
}
} ;
V_6 = F_3 ( V_2 -> V_15 , V_10 , 2 ) ;
if ( V_6 == 2 ) {
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_15 -> V_16 , L_4 \
L_3 , V_17 , V_6 , V_3 , V_5 ) ;
V_6 = - V_19 ;
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
T_2 V_21 )
{
int V_6 ;
T_2 V_22 ;
if ( V_21 != 0xff ) {
V_6 = F_4 ( V_2 , V_3 , & V_22 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_21 ;
V_22 &= ~ V_21 ;
V_4 |= V_22 ;
}
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
T_2 V_21 )
{
int V_6 , V_23 ;
T_2 V_22 ;
V_6 = F_4 ( V_2 , V_3 , & V_22 , 1 ) ;
if ( V_6 )
return V_6 ;
V_22 &= V_21 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
if ( ( V_21 >> V_23 ) & 0x01 )
break;
}
* V_4 = V_22 >> V_23 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_24 * V_25 , int V_26 )
{
#define F_10 212
int V_6 , V_23 , V_27 ;
T_2 V_7 [ 1 + F_10 ] ;
F_11 ( & V_2 -> V_15 -> V_16 , L_5 , V_28 , V_26 ) ;
if ( V_26 > sizeof( V_7 ) ) {
F_2 ( & V_2 -> V_15 -> V_16 , L_6 ,
V_17 , V_26 ) ;
return - V_18 ;
}
for ( V_23 = 0 , V_27 = 0 ; V_23 < V_26 ; V_23 ++ ) {
V_7 [ V_27 ] = V_25 [ V_23 ] . V_4 ;
if ( V_23 == V_26 - 1 || V_25 [ V_23 ] . V_3 != V_25 [ V_23 + 1 ] . V_3 - 1 ) {
V_6 = F_1 ( V_2 , V_25 [ V_23 ] . V_3 - V_27 , V_7 , V_27 + 1 ) ;
if ( V_6 < 0 )
goto V_29;
V_27 = 0 ;
} else {
V_27 ++ ;
}
}
return 0 ;
V_29:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 , V_28 , V_6 ) ;
return V_6 ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_1 V_30 , T_1 V_31 , T_1 V_32 )
{
T_1 V_33 = 0 , V_34 = 0 , V_23 ;
F_11 ( & V_2 -> V_15 -> V_16 , L_8 , V_28 , V_30 , V_31 , V_32 ) ;
if ( V_30 > V_31 ) {
V_34 = V_30 / V_31 ;
V_30 = V_30 - V_34 * V_31 ;
}
for ( V_23 = 0 ; V_23 < V_32 ; V_23 ++ ) {
if ( V_30 >= V_31 ) {
V_33 += 1 ;
V_30 -= V_31 ;
}
V_30 <<= 1 ;
V_33 <<= 1 ;
}
V_33 = ( V_34 << ( T_1 ) V_32 ) + V_33 ;
F_11 ( & V_2 -> V_15 -> V_16 , L_9 ,
V_28 , V_30 , V_31 , V_32 , V_33 , V_33 ) ;
return V_33 ;
}
static void F_13 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
F_14 ( V_2 ) ;
}
static int F_15 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
int V_6 , V_23 , V_5 ;
const struct V_24 * V_38 ;
T_2 V_7 [ 4 ] ;
T_1 V_39 , V_40 ;
struct V_41 V_25 [] = {
{ 0x80fb24 , 0x00 , 0x08 } ,
{ 0x80004c , 0x00 , 0xff } ,
{ 0x00f641 , V_2 -> V_12 . V_42 , 0xff } ,
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
{ 0x80f985 , V_2 -> V_43 , 0x01 } ,
{ 0x80f986 , V_2 -> V_44 , 0x01 } ,
{ 0x00d827 , 0x00 , 0xff } ,
{ 0x00d829 , 0x00 , 0xff } ,
{ 0x800045 , V_2 -> V_12 . V_45 , 0xff } ,
} ;
V_40 = F_12 ( V_2 , V_2 -> V_12 . clock , 1000000ul , 19ul ) ;
V_7 [ 0 ] = ( V_40 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_40 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_40 >> 16 ) & 0xff ;
V_7 [ 3 ] = ( V_40 >> 24 ) & 0xff ;
F_11 ( & V_2 -> V_15 -> V_16 , L_10 ,
V_28 , V_2 -> V_12 . clock , V_40 ) ;
V_6 = F_1 ( V_2 , 0x800025 , V_7 , 4 ) ;
if ( V_6 < 0 )
goto V_29;
for ( V_23 = 0 ; V_23 < F_16 ( V_46 ) ; V_23 ++ ) {
if ( V_46 [ V_23 ] . clock == V_2 -> V_12 . clock )
break;
}
V_39 = F_12 ( V_2 , V_46 [ V_23 ] . V_47 , 1000000ul , 19ul ) ;
V_7 [ 0 ] = ( V_39 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_39 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_39 >> 16 ) & 0xff ;
F_11 ( & V_2 -> V_15 -> V_16 , L_11 ,
V_28 , V_46 [ V_23 ] . V_47 , V_39 ) ;
V_6 = F_1 ( V_2 , 0x80f1cd , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_29;
for ( V_23 = 0 ; V_23 < F_16 ( V_25 ) ; V_23 ++ ) {
V_6 = F_7 ( V_2 , V_25 [ V_23 ] . V_3 , V_25 [ V_23 ] . V_4 ,
V_25 [ V_23 ] . V_21 ) ;
if ( V_6 < 0 )
goto V_29;
}
if ( V_2 -> V_12 . V_48 == V_49 ) {
V_6 = F_7 ( V_2 , 0x80f9a5 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_7 ( V_2 , 0x80f9b5 , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
} else {
V_6 = F_7 ( V_2 , 0x80f990 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_7 ( V_2 , 0x80f9b5 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
}
F_11 ( & V_2 -> V_15 -> V_16 , L_12 , V_28 ) ;
switch ( V_2 -> V_12 . V_42 ) {
case V_50 :
case V_51 :
case V_52 :
V_5 = F_16 ( V_53 ) ;
V_38 = V_53 ;
break;
case V_54 :
case V_55 :
case V_56 :
V_5 = F_16 ( V_57 ) ;
V_38 = V_57 ;
break;
default:
V_5 = F_16 ( V_58 ) ;
V_38 = V_58 ;
break;
}
V_6 = F_9 ( V_2 , V_38 , V_5 ) ;
if ( V_6 < 0 )
goto V_29;
F_11 ( & V_2 -> V_15 -> V_16 , L_13 ,
V_28 ) ;
switch ( V_2 -> V_12 . V_42 ) {
case V_59 :
V_5 = F_16 ( V_60 ) ;
V_38 = V_60 ;
break;
case V_61 :
V_5 = F_16 ( V_62 ) ;
V_38 = V_62 ;
break;
case V_63 :
V_5 = F_16 ( V_64 ) ;
V_38 = V_64 ;
break;
case V_65 :
V_5 = F_16 ( V_66 ) ;
V_38 = V_66 ;
break;
case V_67 :
V_5 = F_16 ( V_68 ) ;
V_38 = V_68 ;
break;
case V_69 :
V_5 = F_16 ( V_70 ) ;
V_38 = V_70 ;
break;
case V_50 :
V_5 = F_16 ( V_71 ) ;
V_38 = V_71 ;
break;
case V_51 :
V_5 = F_16 ( V_72 ) ;
V_38 = V_72 ;
break;
case V_52 :
V_5 = F_16 ( V_73 ) ;
V_38 = V_73 ;
break;
case V_54 :
V_5 = F_16 ( V_74 ) ;
V_38 = V_74 ;
break;
case V_55 :
V_5 = F_16 ( V_75 ) ;
V_38 = V_75 ;
break;
case V_56 :
V_5 = F_16 ( V_76 ) ;
V_38 = V_76 ;
break;
default:
F_11 ( & V_2 -> V_15 -> V_16 , L_14 ,
V_28 , V_2 -> V_12 . V_42 ) ;
V_6 = - V_77 ;
goto V_29;
}
V_6 = F_9 ( V_2 , V_38 , V_5 ) ;
if ( V_6 < 0 )
goto V_29;
if ( V_2 -> V_12 . V_48 == V_78 ) {
V_6 = F_7 ( V_2 , 0x00d91c , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_7 ( V_2 , 0x00d917 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_7 ( V_2 , 0x00d916 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
}
switch ( V_2 -> V_12 . V_42 ) {
case V_54 :
case V_55 :
case V_56 :
V_6 = F_5 ( V_2 , 0x800000 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
}
V_2 -> V_79 = 0 ;
return 0 ;
V_29:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
int V_6 , V_23 ;
T_2 V_22 ;
V_6 = F_5 ( V_2 , 0x80004c , 1 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_5 ( V_2 , 0x800000 , 0 ) ;
if ( V_6 < 0 )
goto V_29;
for ( V_23 = 100 , V_22 = 1 ; V_23 && V_22 ; V_23 -- ) {
V_6 = F_6 ( V_2 , 0x80004c , & V_22 ) ;
if ( V_6 < 0 )
goto V_29;
F_18 ( 200 , 10000 ) ;
}
F_11 ( & V_2 -> V_15 -> V_16 , L_15 , V_28 , V_23 ) ;
if ( V_23 == 0 ) {
V_6 = - V_80 ;
goto V_29;
}
V_6 = F_7 ( V_2 , 0x80fb24 , 0x08 , 0x08 ) ;
if ( V_6 < 0 )
goto V_29;
if ( V_2 -> V_12 . V_48 == V_78 ) {
V_6 = F_7 ( V_2 , 0x00d917 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_7 ( V_2 , 0x00d916 , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
}
return 0 ;
V_29:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_35 * V_36 ,
struct V_81 * V_82 )
{
V_82 -> V_83 = 2000 ;
V_82 -> V_84 = 0 ;
V_82 -> V_85 = 0 ;
return 0 ;
}
static int F_20 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
struct V_86 * V_34 = & V_36 -> V_87 ;
int V_6 , V_23 , V_88 , V_89 ;
T_2 V_22 , V_7 [ 3 ] , V_90 ;
T_1 V_91 , V_92 , V_93 ;
F_11 ( & V_2 -> V_15 -> V_16 , L_16 ,
V_28 , V_34 -> V_94 , V_34 -> V_79 ) ;
switch ( V_34 -> V_79 ) {
case 6000000 :
V_90 = 0x00 ;
break;
case 7000000 :
V_90 = 0x01 ;
break;
case 8000000 :
V_90 = 0x02 ;
break;
default:
F_11 ( & V_2 -> V_15 -> V_16 , L_17 ,
V_28 ) ;
V_6 = - V_18 ;
goto V_29;
}
if ( V_36 -> V_95 . V_96 . V_97 )
V_36 -> V_95 . V_96 . V_97 ( V_36 ) ;
if ( V_34 -> V_79 != V_2 -> V_79 ) {
for ( V_23 = 0 ; V_23 < F_16 ( V_98 ) ; V_23 ++ ) {
if ( V_98 [ V_23 ] . clock == V_2 -> V_12 . clock &&
V_98 [ V_23 ] . V_79 == V_34 -> V_79 ) {
break;
}
}
V_6 = F_1 ( V_2 , 0x800001 ,
V_98 [ V_23 ] . V_4 , sizeof( V_98 [ V_23 ] . V_4 ) ) ;
}
if ( V_34 -> V_79 != V_2 -> V_79 ) {
V_88 = V_2 -> V_12 . V_88 ? - 1 : 1 ;
for ( V_23 = 0 ; V_23 < F_16 ( V_46 ) ; V_23 ++ ) {
if ( V_46 [ V_23 ] . clock == V_2 -> V_12 . clock )
break;
}
V_93 = V_46 [ V_23 ] . V_47 ;
if ( V_36 -> V_95 . V_96 . V_99 )
V_36 -> V_95 . V_96 . V_99 ( V_36 , & V_91 ) ;
else
V_91 = 0 ;
V_89 = V_91 ;
while ( V_89 > ( V_93 / 2 ) )
V_89 -= V_93 ;
if ( V_89 >= 0 )
V_88 *= - 1 ;
else
V_89 *= - 1 ;
V_92 = F_12 ( V_2 , V_89 , V_93 , 23ul ) ;
if ( V_88 == - 1 )
V_92 = 0x800000 - V_92 ;
if ( V_2 -> V_12 . V_45 == V_100 )
V_92 /= 2 ;
V_7 [ 0 ] = ( V_92 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_92 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_92 >> 16 ) & 0x7f ;
if ( V_91 == 0 )
V_7 [ 2 ] = 0 ;
V_6 = F_1 ( V_2 , 0x800029 , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_29;
V_2 -> V_79 = V_34 -> V_79 ;
}
V_6 = F_7 ( V_2 , 0x80f904 , V_90 , 0x03 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_5 ( V_2 , 0x800040 , 0x00 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_5 ( V_2 , 0x800047 , 0x00 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_7 ( V_2 , 0x80f999 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
if ( V_34 -> V_94 <= 230000000 )
V_22 = 0x00 ;
else
V_22 = 0x01 ;
V_6 = F_5 ( V_2 , 0x80004b , V_22 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_5 ( V_2 , 0x800000 , 0x00 ) ;
if ( V_6 < 0 )
goto V_29;
return 0 ;
V_29:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
struct V_86 * V_34 = & V_36 -> V_87 ;
int V_6 ;
T_2 V_7 [ 8 ] ;
F_11 ( & V_2 -> V_15 -> V_16 , L_18 , V_28 ) ;
V_6 = F_4 ( V_2 , 0x80f900 , V_7 , sizeof( V_7 ) ) ;
if ( V_6 < 0 )
goto V_29;
switch ( ( V_7 [ 0 ] >> 0 ) & 3 ) {
case 0 :
V_34 -> V_101 = V_102 ;
break;
case 1 :
V_34 -> V_101 = V_103 ;
break;
}
switch ( ( V_7 [ 1 ] >> 0 ) & 3 ) {
case 0 :
V_34 -> V_104 = V_105 ;
break;
case 1 :
V_34 -> V_104 = V_106 ;
break;
case 2 :
V_34 -> V_104 = V_107 ;
break;
case 3 :
V_34 -> V_104 = V_108 ;
break;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 7 ) {
case 0 :
V_34 -> V_109 = V_110 ;
break;
case 1 :
V_34 -> V_109 = V_111 ;
break;
case 2 :
V_34 -> V_109 = V_112 ;
break;
case 3 :
V_34 -> V_109 = V_113 ;
break;
}
switch ( ( V_7 [ 3 ] >> 0 ) & 3 ) {
case 0 :
V_34 -> V_114 = V_115 ;
break;
case 1 :
V_34 -> V_114 = V_116 ;
break;
case 2 :
V_34 -> V_114 = V_117 ;
break;
}
switch ( ( V_7 [ 4 ] >> 0 ) & 3 ) {
case 0 :
V_34 -> V_79 = 6000000 ;
break;
case 1 :
V_34 -> V_79 = 7000000 ;
break;
case 2 :
V_34 -> V_79 = 8000000 ;
break;
}
switch ( ( V_7 [ 6 ] >> 0 ) & 7 ) {
case 0 :
V_34 -> V_118 = V_119 ;
break;
case 1 :
V_34 -> V_118 = V_120 ;
break;
case 2 :
V_34 -> V_118 = V_121 ;
break;
case 3 :
V_34 -> V_118 = V_122 ;
break;
case 4 :
V_34 -> V_118 = V_123 ;
break;
case 5 :
V_34 -> V_118 = V_124 ;
break;
}
switch ( ( V_7 [ 7 ] >> 0 ) & 7 ) {
case 0 :
V_34 -> V_125 = V_119 ;
break;
case 1 :
V_34 -> V_125 = V_120 ;
break;
case 2 :
V_34 -> V_125 = V_121 ;
break;
case 3 :
V_34 -> V_125 = V_122 ;
break;
case 4 :
V_34 -> V_125 = V_123 ;
break;
case 5 :
V_34 -> V_125 = V_124 ;
break;
}
return 0 ;
V_29:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_22 ( struct V_35 * V_36 , T_3 * V_126 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
int V_6 ;
T_2 V_22 ;
* V_126 = 0 ;
V_6 = F_6 ( V_2 , 0x800047 , & V_22 ) ;
if ( V_6 < 0 )
goto V_29;
if ( V_22 == 0x01 )
* V_126 |= V_127 ;
if ( V_22 != 0x02 ) {
V_6 = F_8 ( V_2 , 0x80f5a9 , & V_22 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
if ( V_22 )
* V_126 |= V_127 | V_128 |
V_129 ;
V_6 = F_8 ( V_2 , 0x80f999 , & V_22 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
if ( V_22 )
* V_126 |= V_127 | V_128 |
V_129 | V_130 |
V_131 ;
}
return 0 ;
V_29:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_23 ( struct V_35 * V_36 , T_4 * V_132 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
int V_6 , V_23 , V_5 ;
T_2 V_7 [ 3 ] , V_22 ;
T_1 V_133 ;
const struct V_134 * V_135 ( V_136 ) ;
V_6 = F_4 ( V_2 , 0x80002c , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_29;
V_133 = ( V_7 [ 2 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | V_7 [ 0 ] ;
V_6 = F_6 ( V_2 , 0x80f903 , & V_22 ) ;
if ( V_6 < 0 )
goto V_29;
switch ( ( V_22 >> 0 ) & 3 ) {
case 0 :
V_5 = F_16 ( V_137 ) ;
V_136 = V_137 ;
break;
case 1 :
V_5 = F_16 ( V_138 ) ;
V_136 = V_138 ;
break;
case 2 :
V_5 = F_16 ( V_139 ) ;
V_136 = V_139 ;
break;
default:
goto V_29;
}
for ( V_23 = 0 ; V_23 < V_5 ; V_23 ++ ) {
V_22 = V_136 [ V_23 ] . V_132 ;
if ( V_133 < V_136 [ V_23 ] . V_4 )
break;
}
* V_132 = V_22 * 10 ;
return 0 ;
V_29:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_24 ( struct V_35 * V_36 , T_4 * V_140 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
int V_6 ;
T_2 V_141 ;
V_6 = F_6 ( V_2 , 0x800048 , & V_141 ) ;
if ( V_6 < 0 )
goto V_29;
* V_140 = V_141 * 0xffff / 100 ;
return 0 ;
V_29:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
T_1 V_142 , V_143 ;
T_4 V_144 ;
T_2 V_7 [ 7 ] ;
if ( F_26 ( V_145 , V_2 -> V_146 + F_27 ( 500 ) ) ) {
V_6 = F_4 ( V_2 , 0x800032 , V_7 , sizeof( V_7 ) ) ;
if ( V_6 < 0 )
goto V_29;
V_144 = ( V_7 [ 1 ] << 8 ) + V_7 [ 0 ] ;
V_142 = ( V_7 [ 4 ] << 16 ) + ( V_7 [ 3 ] << 8 ) + V_7 [ 2 ] ;
V_143 = ( V_7 [ 6 ] << 8 ) + V_7 [ 5 ] ;
if ( V_143 < V_144 ) {
V_144 = 1000 ;
V_2 -> V_147 = 0xffffffff ;
} else {
V_143 -= ( T_1 ) V_144 ;
if ( V_143 == 0 ) {
V_2 -> V_147 = 0xffffffff ;
} else {
V_142 -= ( T_1 ) V_144 * 8 * 8 ;
V_143 *= 8 * 8 ;
V_2 -> V_147 = V_142 * ( 0xffffffff / V_143 ) ;
}
}
V_2 -> V_148 += V_144 ;
V_2 -> V_146 = V_145 ;
}
return 0 ;
V_29:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_28 ( struct V_35 * V_36 , T_1 * V_147 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
int V_6 ;
V_6 = F_25 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_147 = V_2 -> V_147 ;
return 0 ;
}
static int F_29 ( struct V_35 * V_36 , T_1 * V_149 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
int V_6 ;
V_6 = F_25 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_149 = V_2 -> V_148 ;
return 0 ;
}
static int F_30 ( struct V_35 * V_36 , int V_150 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
int V_6 ;
F_11 ( & V_2 -> V_15 -> V_16 , L_19 , V_28 , V_150 ) ;
V_6 = F_7 ( V_2 , 0x00fa04 , V_150 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
return 0 ;
V_29:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_31 ( struct V_35 * V_36 , int V_151 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
int V_6 ;
F_11 ( & V_2 -> V_15 -> V_16 , L_20 , V_28 , V_151 ) ;
V_6 = F_7 ( V_2 , 0x80f993 , V_151 , 0x01 ) ;
if ( V_6 < 0 )
goto V_29;
return 0 ;
V_29:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 , V_28 , V_6 ) ;
return V_6 ;
}
static int F_32 ( struct V_35 * V_36 , int V_152 , T_4 V_153 , int V_151 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
int V_6 ;
T_2 V_154 [ 2 ] = { ( V_153 >> 0 ) & 0xff , ( V_153 >> 8 ) & 0xff } ;
F_11 ( & V_2 -> V_15 -> V_16 , L_21 ,
V_28 , V_152 , V_153 , V_151 ) ;
if ( V_153 > 0x1fff )
return 0 ;
V_6 = F_1 ( V_2 , 0x80f996 , V_154 , 2 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_5 ( V_2 , 0x80f994 , V_151 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_5 ( V_2 , 0x80f995 , V_152 ) ;
if ( V_6 < 0 )
goto V_29;
return 0 ;
V_29:
F_11 ( & V_2 -> V_15 -> V_16 , L_7 , V_28 , V_6 ) ;
return V_6 ;
}
struct V_35 * F_33 ( const struct V_155 * V_156 ,
struct V_157 * V_15 ,
struct V_158 * V_95 )
{
int V_6 ;
struct V_1 * V_2 ;
T_2 V_7 [ 8 ] ;
F_11 ( & V_15 -> V_16 , L_18 , V_28 ) ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_159 ) ;
if ( V_2 == NULL )
goto V_29;
V_2 -> V_15 = V_15 ;
memcpy ( & V_2 -> V_12 , V_156 , sizeof( struct V_155 ) ) ;
if ( V_2 -> V_12 . clock != 12000000 ) {
F_35 ( & V_2 -> V_15 -> V_16 , L_22 \
L_23 ,
V_17 , V_2 -> V_12 . clock ) ;
goto V_29;
}
V_6 = F_4 ( V_2 , 0x0083e9 , & V_7 [ 0 ] , 4 ) ;
if ( V_6 < 0 )
goto V_29;
V_6 = F_4 ( V_2 , 0x804191 , & V_7 [ 4 ] , 4 ) ;
if ( V_6 < 0 )
goto V_29;
F_36 ( & V_2 -> V_15 -> V_16 , L_24 \
L_25 , V_17 , V_7 [ 0 ] , V_7 [ 1 ] ,
V_7 [ 2 ] , V_7 [ 3 ] , V_7 [ 4 ] , V_7 [ 5 ] , V_7 [ 6 ] , V_7 [ 7 ] ) ;
switch ( V_2 -> V_12 . V_42 ) {
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
goto V_29;
V_6 = F_5 ( V_2 , 0x800000 , 0 ) ;
if ( V_6 < 0 )
goto V_29;
}
switch ( V_2 -> V_12 . V_48 ) {
case V_160 :
V_2 -> V_44 = true ;
break;
case V_78 :
V_2 -> V_43 = true ;
break;
case V_49 :
default:
break;
}
memcpy ( & V_2 -> V_36 . V_95 , & V_158 , sizeof( struct V_161 ) ) ;
V_2 -> V_36 . V_37 = V_2 ;
if ( V_95 ) {
V_95 -> V_162 = F_32 ;
V_95 -> V_163 = F_31 ;
}
return & V_2 -> V_36 ;
V_29:
F_14 ( V_2 ) ;
return NULL ;
}
