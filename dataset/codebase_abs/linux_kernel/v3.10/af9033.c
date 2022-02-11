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
static int F_9 ( struct V_1 * V_2 ,
const struct V_22 * V_23 , int V_24 )
{
int V_6 , V_21 , V_25 ;
T_2 V_7 [ V_24 ] ;
F_10 ( & V_2 -> V_14 -> V_15 , L_4 , V_26 , V_24 ) ;
for ( V_21 = 0 , V_25 = 0 ; V_21 < V_24 ; V_21 ++ ) {
V_7 [ V_25 ] = V_23 [ V_21 ] . V_4 ;
if ( V_21 == V_24 - 1 || V_23 [ V_21 ] . V_3 != V_23 [ V_21 + 1 ] . V_3 - 1 ) {
V_6 = F_1 ( V_2 , V_23 [ V_21 ] . V_3 - V_25 , V_7 , V_25 + 1 ) ;
if ( V_6 < 0 )
goto V_27;
V_25 = 0 ;
} else {
V_25 ++ ;
}
}
return 0 ;
V_27:
F_10 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_1 V_28 , T_1 V_29 , T_1 V_30 )
{
T_1 V_31 = 0 , V_32 = 0 , V_21 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_6 , V_26 , V_28 , V_29 , V_30 ) ;
if ( V_28 > V_29 ) {
V_32 = V_28 / V_29 ;
V_28 = V_28 - V_32 * V_29 ;
}
for ( V_21 = 0 ; V_21 < V_30 ; V_21 ++ ) {
if ( V_28 >= V_29 ) {
V_31 += 1 ;
V_28 -= V_29 ;
}
V_28 <<= 1 ;
V_31 <<= 1 ;
}
V_31 = ( V_32 << ( T_1 ) V_30 ) + V_31 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_7 ,
V_26 , V_28 , V_29 , V_30 , V_31 , V_31 ) ;
return V_31 ;
}
static void F_12 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
F_13 ( V_2 ) ;
}
static int F_14 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
int V_6 , V_21 , V_5 ;
const struct V_22 * V_36 ;
T_2 V_7 [ 4 ] ;
T_1 V_37 , V_38 ;
struct V_39 V_23 [] = {
{ 0x80fb24 , 0x00 , 0x08 } ,
{ 0x80004c , 0x00 , 0xff } ,
{ 0x00f641 , V_2 -> V_11 . V_40 , 0xff } ,
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
{ 0x80f985 , V_2 -> V_41 , 0x01 } ,
{ 0x80f986 , V_2 -> V_42 , 0x01 } ,
{ 0x00d827 , 0x00 , 0xff } ,
{ 0x00d829 , 0x00 , 0xff } ,
{ 0x800045 , V_2 -> V_11 . V_43 , 0xff } ,
} ;
V_38 = F_11 ( V_2 , V_2 -> V_11 . clock , 1000000ul , 19ul ) ;
V_7 [ 0 ] = ( V_38 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_38 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_38 >> 16 ) & 0xff ;
V_7 [ 3 ] = ( V_38 >> 24 ) & 0xff ;
F_10 ( & V_2 -> V_14 -> V_15 , L_8 ,
V_26 , V_2 -> V_11 . clock , V_38 ) ;
V_6 = F_1 ( V_2 , 0x800025 , V_7 , 4 ) ;
if ( V_6 < 0 )
goto V_27;
for ( V_21 = 0 ; V_21 < F_15 ( V_44 ) ; V_21 ++ ) {
if ( V_44 [ V_21 ] . clock == V_2 -> V_11 . clock )
break;
}
V_37 = F_11 ( V_2 , V_44 [ V_21 ] . V_45 , 1000000ul , 19ul ) ;
V_7 [ 0 ] = ( V_37 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_37 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_37 >> 16 ) & 0xff ;
F_10 ( & V_2 -> V_14 -> V_15 , L_9 ,
V_26 , V_44 [ V_21 ] . V_45 , V_37 ) ;
V_6 = F_1 ( V_2 , 0x80f1cd , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_27;
for ( V_21 = 0 ; V_21 < F_15 ( V_23 ) ; V_21 ++ ) {
V_6 = F_7 ( V_2 , V_23 [ V_21 ] . V_3 , V_23 [ V_21 ] . V_4 ,
V_23 [ V_21 ] . V_19 ) ;
if ( V_6 < 0 )
goto V_27;
}
if ( V_2 -> V_11 . V_46 == V_47 ) {
V_6 = F_7 ( V_2 , 0x80f9a5 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_7 ( V_2 , 0x80f9b5 , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
} else {
V_6 = F_7 ( V_2 , 0x80f990 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_7 ( V_2 , 0x80f9b5 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
}
F_10 ( & V_2 -> V_14 -> V_15 , L_10 , V_26 ) ;
switch ( V_2 -> V_11 . V_40 ) {
case V_48 :
case V_49 :
case V_50 :
V_5 = F_15 ( V_51 ) ;
V_36 = V_51 ;
break;
case V_52 :
case V_53 :
case V_54 :
V_5 = F_15 ( V_55 ) ;
V_36 = V_55 ;
break;
default:
V_5 = F_15 ( V_56 ) ;
V_36 = V_56 ;
break;
}
V_6 = F_9 ( V_2 , V_36 , V_5 ) ;
if ( V_6 < 0 )
goto V_27;
F_10 ( & V_2 -> V_14 -> V_15 , L_11 ,
V_26 ) ;
switch ( V_2 -> V_11 . V_40 ) {
case V_57 :
V_5 = F_15 ( V_58 ) ;
V_36 = V_58 ;
break;
case V_59 :
V_5 = F_15 ( V_60 ) ;
V_36 = V_60 ;
break;
case V_61 :
V_5 = F_15 ( V_62 ) ;
V_36 = V_62 ;
break;
case V_63 :
V_5 = F_15 ( V_64 ) ;
V_36 = V_64 ;
break;
case V_65 :
V_5 = F_15 ( V_66 ) ;
V_36 = V_66 ;
break;
case V_67 :
V_5 = F_15 ( V_68 ) ;
V_36 = V_68 ;
break;
case V_48 :
V_5 = F_15 ( V_69 ) ;
V_36 = V_69 ;
break;
case V_49 :
V_5 = F_15 ( V_70 ) ;
V_36 = V_70 ;
break;
case V_50 :
V_5 = F_15 ( V_71 ) ;
V_36 = V_71 ;
break;
case V_52 :
V_5 = F_15 ( V_72 ) ;
V_36 = V_72 ;
break;
case V_53 :
V_5 = F_15 ( V_73 ) ;
V_36 = V_73 ;
break;
case V_54 :
V_5 = F_15 ( V_74 ) ;
V_36 = V_74 ;
break;
default:
F_10 ( & V_2 -> V_14 -> V_15 , L_12 ,
V_26 , V_2 -> V_11 . V_40 ) ;
V_6 = - V_75 ;
goto V_27;
}
V_6 = F_9 ( V_2 , V_36 , V_5 ) ;
if ( V_6 < 0 )
goto V_27;
if ( V_2 -> V_11 . V_46 == V_76 ) {
V_6 = F_7 ( V_2 , 0x00d91c , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_7 ( V_2 , 0x00d917 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_7 ( V_2 , 0x00d916 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
}
switch ( V_2 -> V_11 . V_40 ) {
case V_52 :
case V_53 :
case V_54 :
V_6 = F_5 ( V_2 , 0x800000 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
}
V_2 -> V_77 = 0 ;
return 0 ;
V_27:
F_10 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_16 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
int V_6 , V_21 ;
T_2 V_20 ;
V_6 = F_5 ( V_2 , 0x80004c , 1 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x800000 , 0 ) ;
if ( V_6 < 0 )
goto V_27;
for ( V_21 = 100 , V_20 = 1 ; V_21 && V_20 ; V_21 -- ) {
V_6 = F_6 ( V_2 , 0x80004c , & V_20 ) ;
if ( V_6 < 0 )
goto V_27;
F_17 ( 200 , 10000 ) ;
}
F_10 ( & V_2 -> V_14 -> V_15 , L_13 , V_26 , V_21 ) ;
if ( V_21 == 0 ) {
V_6 = - V_78 ;
goto V_27;
}
V_6 = F_7 ( V_2 , 0x80fb24 , 0x08 , 0x08 ) ;
if ( V_6 < 0 )
goto V_27;
if ( V_2 -> V_11 . V_46 == V_76 ) {
V_6 = F_7 ( V_2 , 0x00d917 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_7 ( V_2 , 0x00d916 , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
}
return 0 ;
V_27:
F_10 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_33 * V_34 ,
struct V_79 * V_80 )
{
V_80 -> V_81 = 2000 ;
V_80 -> V_82 = 0 ;
V_80 -> V_83 = 0 ;
return 0 ;
}
static int F_19 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
struct V_84 * V_32 = & V_34 -> V_85 ;
int V_6 , V_21 , V_86 , V_87 ;
T_2 V_20 , V_7 [ 3 ] , V_88 ;
T_1 V_89 , V_90 , V_91 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_14 ,
V_26 , V_32 -> V_92 , V_32 -> V_77 ) ;
switch ( V_32 -> V_77 ) {
case 6000000 :
V_88 = 0x00 ;
break;
case 7000000 :
V_88 = 0x01 ;
break;
case 8000000 :
V_88 = 0x02 ;
break;
default:
F_10 ( & V_2 -> V_14 -> V_15 , L_15 ,
V_26 ) ;
V_6 = - V_93 ;
goto V_27;
}
if ( V_34 -> V_94 . V_95 . V_96 )
V_34 -> V_94 . V_95 . V_96 ( V_34 ) ;
if ( V_32 -> V_77 != V_2 -> V_77 ) {
for ( V_21 = 0 ; V_21 < F_15 ( V_97 ) ; V_21 ++ ) {
if ( V_97 [ V_21 ] . clock == V_2 -> V_11 . clock &&
V_97 [ V_21 ] . V_77 == V_32 -> V_77 ) {
break;
}
}
V_6 = F_1 ( V_2 , 0x800001 ,
V_97 [ V_21 ] . V_4 , sizeof( V_97 [ V_21 ] . V_4 ) ) ;
}
if ( V_32 -> V_77 != V_2 -> V_77 ) {
V_86 = V_2 -> V_11 . V_86 ? - 1 : 1 ;
for ( V_21 = 0 ; V_21 < F_15 ( V_44 ) ; V_21 ++ ) {
if ( V_44 [ V_21 ] . clock == V_2 -> V_11 . clock )
break;
}
V_91 = V_44 [ V_21 ] . V_45 ;
if ( V_34 -> V_94 . V_95 . V_98 )
V_34 -> V_94 . V_95 . V_98 ( V_34 , & V_89 ) ;
else
V_89 = 0 ;
V_87 = V_89 ;
while ( V_87 > ( V_91 / 2 ) )
V_87 -= V_91 ;
if ( V_87 >= 0 )
V_86 *= - 1 ;
else
V_87 *= - 1 ;
V_90 = F_11 ( V_2 , V_87 , V_91 , 23ul ) ;
if ( V_86 == - 1 )
V_90 = 0x800000 - V_90 ;
if ( V_2 -> V_11 . V_43 == V_99 )
V_90 /= 2 ;
V_7 [ 0 ] = ( V_90 >> 0 ) & 0xff ;
V_7 [ 1 ] = ( V_90 >> 8 ) & 0xff ;
V_7 [ 2 ] = ( V_90 >> 16 ) & 0x7f ;
if ( V_89 == 0 )
V_7 [ 2 ] = 0 ;
V_6 = F_1 ( V_2 , 0x800029 , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_27;
V_2 -> V_77 = V_32 -> V_77 ;
}
V_6 = F_7 ( V_2 , 0x80f904 , V_88 , 0x03 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x800040 , 0x00 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x800047 , 0x00 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_7 ( V_2 , 0x80f999 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
if ( V_32 -> V_92 <= 230000000 )
V_20 = 0x00 ;
else
V_20 = 0x01 ;
V_6 = F_5 ( V_2 , 0x80004b , V_20 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x800000 , 0x00 ) ;
if ( V_6 < 0 )
goto V_27;
return 0 ;
V_27:
F_10 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
struct V_84 * V_32 = & V_34 -> V_85 ;
int V_6 ;
T_2 V_7 [ 8 ] ;
F_10 ( & V_2 -> V_14 -> V_15 , L_16 , V_26 ) ;
V_6 = F_4 ( V_2 , 0x80f900 , V_7 , sizeof( V_7 ) ) ;
if ( V_6 < 0 )
goto V_27;
switch ( ( V_7 [ 0 ] >> 0 ) & 3 ) {
case 0 :
V_32 -> V_100 = V_101 ;
break;
case 1 :
V_32 -> V_100 = V_102 ;
break;
}
switch ( ( V_7 [ 1 ] >> 0 ) & 3 ) {
case 0 :
V_32 -> V_103 = V_104 ;
break;
case 1 :
V_32 -> V_103 = V_105 ;
break;
case 2 :
V_32 -> V_103 = V_106 ;
break;
case 3 :
V_32 -> V_103 = V_107 ;
break;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 7 ) {
case 0 :
V_32 -> V_108 = V_109 ;
break;
case 1 :
V_32 -> V_108 = V_110 ;
break;
case 2 :
V_32 -> V_108 = V_111 ;
break;
case 3 :
V_32 -> V_108 = V_112 ;
break;
}
switch ( ( V_7 [ 3 ] >> 0 ) & 3 ) {
case 0 :
V_32 -> V_113 = V_114 ;
break;
case 1 :
V_32 -> V_113 = V_115 ;
break;
case 2 :
V_32 -> V_113 = V_116 ;
break;
}
switch ( ( V_7 [ 4 ] >> 0 ) & 3 ) {
case 0 :
V_32 -> V_77 = 6000000 ;
break;
case 1 :
V_32 -> V_77 = 7000000 ;
break;
case 2 :
V_32 -> V_77 = 8000000 ;
break;
}
switch ( ( V_7 [ 6 ] >> 0 ) & 7 ) {
case 0 :
V_32 -> V_117 = V_118 ;
break;
case 1 :
V_32 -> V_117 = V_119 ;
break;
case 2 :
V_32 -> V_117 = V_120 ;
break;
case 3 :
V_32 -> V_117 = V_121 ;
break;
case 4 :
V_32 -> V_117 = V_122 ;
break;
case 5 :
V_32 -> V_117 = V_123 ;
break;
}
switch ( ( V_7 [ 7 ] >> 0 ) & 7 ) {
case 0 :
V_32 -> V_124 = V_118 ;
break;
case 1 :
V_32 -> V_124 = V_119 ;
break;
case 2 :
V_32 -> V_124 = V_120 ;
break;
case 3 :
V_32 -> V_124 = V_121 ;
break;
case 4 :
V_32 -> V_124 = V_122 ;
break;
case 5 :
V_32 -> V_124 = V_123 ;
break;
}
return 0 ;
V_27:
F_10 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_33 * V_34 , T_3 * V_125 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
int V_6 ;
T_2 V_20 ;
* V_125 = 0 ;
V_6 = F_6 ( V_2 , 0x800047 , & V_20 ) ;
if ( V_6 < 0 )
goto V_27;
if ( V_20 == 0x01 )
* V_125 |= V_126 ;
if ( V_20 != 0x02 ) {
V_6 = F_8 ( V_2 , 0x80f5a9 , & V_20 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
if ( V_20 )
* V_125 |= V_126 | V_127 |
V_128 ;
V_6 = F_8 ( V_2 , 0x80f999 , & V_20 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
if ( V_20 )
* V_125 |= V_126 | V_127 |
V_128 | V_129 |
V_130 ;
}
return 0 ;
V_27:
F_10 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_22 ( struct V_33 * V_34 , T_4 * V_131 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
int V_6 , V_21 , V_5 ;
T_2 V_7 [ 3 ] , V_20 ;
T_1 V_132 ;
const struct V_133 * V_134 ( V_135 ) ;
V_6 = F_4 ( V_2 , 0x80002c , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_27;
V_132 = ( V_7 [ 2 ] << 16 ) | ( V_7 [ 1 ] << 8 ) | V_7 [ 0 ] ;
V_6 = F_6 ( V_2 , 0x80f903 , & V_20 ) ;
if ( V_6 < 0 )
goto V_27;
switch ( ( V_20 >> 0 ) & 3 ) {
case 0 :
V_5 = F_15 ( V_136 ) ;
V_135 = V_136 ;
break;
case 1 :
V_5 = F_15 ( V_137 ) ;
V_135 = V_137 ;
break;
case 2 :
V_5 = F_15 ( V_138 ) ;
V_135 = V_138 ;
break;
default:
goto V_27;
}
for ( V_21 = 0 ; V_21 < V_5 ; V_21 ++ ) {
V_20 = V_135 [ V_21 ] . V_131 ;
if ( V_132 < V_135 [ V_21 ] . V_4 )
break;
}
* V_131 = V_20 * 10 ;
return 0 ;
V_27:
F_10 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_23 ( struct V_33 * V_34 , T_4 * V_139 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
int V_6 ;
T_2 V_140 ;
V_6 = F_6 ( V_2 , 0x800048 , & V_140 ) ;
if ( V_6 < 0 )
goto V_27;
* V_139 = V_140 * 0xffff / 100 ;
return 0 ;
V_27:
F_10 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
T_1 V_141 , V_142 ;
T_4 V_143 ;
T_2 V_7 [ 7 ] ;
if ( F_25 ( V_144 , V_2 -> V_145 + F_26 ( 500 ) ) ) {
V_6 = F_4 ( V_2 , 0x800032 , V_7 , sizeof( V_7 ) ) ;
if ( V_6 < 0 )
goto V_27;
V_143 = ( V_7 [ 1 ] << 8 ) + V_7 [ 0 ] ;
V_141 = ( V_7 [ 4 ] << 16 ) + ( V_7 [ 3 ] << 8 ) + V_7 [ 2 ] ;
V_142 = ( V_7 [ 6 ] << 8 ) + V_7 [ 5 ] ;
if ( V_142 < V_143 ) {
V_143 = 1000 ;
V_2 -> V_146 = 0xffffffff ;
} else {
V_142 -= ( T_1 ) V_143 ;
if ( V_142 == 0 ) {
V_2 -> V_146 = 0xffffffff ;
} else {
V_141 -= ( T_1 ) V_143 * 8 * 8 ;
V_142 *= 8 * 8 ;
V_2 -> V_146 = V_141 * ( 0xffffffff / V_142 ) ;
}
}
V_2 -> V_147 += V_143 ;
V_2 -> V_145 = V_144 ;
}
return 0 ;
V_27:
F_10 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
static int F_27 ( struct V_33 * V_34 , T_1 * V_146 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
int V_6 ;
V_6 = F_24 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_146 = V_2 -> V_146 ;
return 0 ;
}
static int F_28 ( struct V_33 * V_34 , T_1 * V_148 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
int V_6 ;
V_6 = F_24 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_148 = V_2 -> V_147 ;
return 0 ;
}
static int F_29 ( struct V_33 * V_34 , int V_149 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
int V_6 ;
F_10 ( & V_2 -> V_14 -> V_15 , L_17 , V_26 , V_149 ) ;
V_6 = F_7 ( V_2 , 0x00fa04 , V_149 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
return 0 ;
V_27:
F_10 ( & V_2 -> V_14 -> V_15 , L_5 , V_26 , V_6 ) ;
return V_6 ;
}
struct V_33 * F_30 ( const struct V_150 * V_151 ,
struct V_152 * V_14 )
{
int V_6 ;
struct V_1 * V_2 ;
T_2 V_7 [ 8 ] ;
F_10 ( & V_14 -> V_15 , L_16 , V_26 ) ;
V_2 = F_31 ( sizeof( struct V_1 ) , V_153 ) ;
if ( V_2 == NULL )
goto V_27;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_11 , V_151 , sizeof( struct V_150 ) ) ;
if ( V_2 -> V_11 . clock != 12000000 ) {
F_32 ( & V_2 -> V_14 -> V_15 , L_18 \
L_19 ,
V_16 , V_2 -> V_11 . clock ) ;
goto V_27;
}
V_6 = F_4 ( V_2 , 0x0083e9 , & V_7 [ 0 ] , 4 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_4 ( V_2 , 0x804191 , & V_7 [ 4 ] , 4 ) ;
if ( V_6 < 0 )
goto V_27;
F_33 ( & V_2 -> V_14 -> V_15 , L_20 \
L_21 , V_16 , V_7 [ 0 ] , V_7 [ 1 ] ,
V_7 [ 2 ] , V_7 [ 3 ] , V_7 [ 4 ] , V_7 [ 5 ] , V_7 [ 6 ] , V_7 [ 7 ] ) ;
switch ( V_2 -> V_11 . V_40 ) {
case V_48 :
case V_49 :
case V_50 :
case V_52 :
case V_53 :
case V_54 :
break;
default:
V_6 = F_5 ( V_2 , 0x80004c , 1 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x800000 , 0 ) ;
if ( V_6 < 0 )
goto V_27;
}
switch ( V_2 -> V_11 . V_46 ) {
case V_154 :
V_2 -> V_42 = true ;
break;
case V_76 :
V_2 -> V_41 = true ;
break;
case V_47 :
default:
break;
}
memcpy ( & V_2 -> V_34 . V_94 , & V_155 , sizeof( struct V_156 ) ) ;
V_2 -> V_34 . V_35 = V_2 ;
return & V_2 -> V_34 ;
V_27:
F_13 ( V_2 ) ;
return NULL ;
}
