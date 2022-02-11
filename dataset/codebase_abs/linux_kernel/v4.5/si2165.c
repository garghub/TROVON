static int F_1 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_2 * V_4 , const int V_5 )
{
int V_6 ;
struct V_7 V_8 ;
T_2 V_9 [ 2 + 4 ] ;
if ( V_5 + 2 > sizeof( V_9 ) ) {
F_2 ( & V_2 -> V_10 -> V_11 ,
L_1 ,
V_12 , V_3 , V_5 ) ;
return - V_13 ;
}
V_9 [ 0 ] = V_3 >> 8 ;
V_9 [ 1 ] = V_3 & 0xff ;
memcpy ( V_9 + 2 , V_4 , V_5 ) ;
V_8 . V_14 = V_2 -> V_15 . V_16 ;
V_8 . V_17 = 0 ;
V_8 . V_9 = V_9 ;
V_8 . V_18 = V_5 + 2 ;
if ( V_19 & V_20 )
F_3 ( L_2 , V_3 , V_5 , V_4 ) ;
V_6 = F_4 ( V_2 -> V_10 , & V_8 , 1 ) ;
if ( V_6 != 1 ) {
F_5 ( & V_2 -> V_10 -> V_11 , L_3 , V_21 , V_6 ) ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_22 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const T_1 V_3 , T_2 * V_23 , const int V_5 )
{
int V_6 ;
T_2 V_24 [] = { V_3 >> 8 , V_3 & 0xff } ;
struct V_7 V_8 [] = {
{ . V_14 = V_2 -> V_15 . V_16 ,
. V_17 = 0 , . V_9 = V_24 , . V_18 = 2 } ,
{ . V_14 = V_2 -> V_15 . V_16 ,
. V_17 = V_25 , . V_9 = V_23 , . V_18 = V_5 } ,
} ;
V_6 = F_4 ( V_2 -> V_10 , V_8 , 2 ) ;
if ( V_6 != 2 ) {
F_5 ( & V_2 -> V_10 -> V_11 , L_4 ,
V_21 , V_2 -> V_15 . V_16 , V_3 , V_6 ) ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_22 ;
}
if ( V_19 & V_26 )
F_7 ( L_2 , V_3 , V_5 , V_23 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const T_1 V_3 , T_2 * V_23 )
{
int V_6 ;
V_6 = F_6 ( V_2 , V_3 , V_23 , 1 ) ;
F_9 ( L_5 , V_3 , * V_23 ) ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 ,
const T_1 V_3 , T_1 * V_23 )
{
T_2 V_9 [ 2 ] ;
int V_6 = F_6 ( V_2 , V_3 , V_9 , 2 ) ;
* V_23 = V_9 [ 0 ] | V_9 [ 1 ] << 8 ;
F_9 ( L_6 , V_3 , * V_23 ) ;
return V_6 ;
}
static int F_11 ( struct V_1 * V_2 , const T_1 V_3 , T_2 V_23 )
{
return F_1 ( V_2 , V_3 , & V_23 , 1 ) ;
}
static int F_12 ( struct V_1 * V_2 , const T_1 V_3 , T_1 V_23 )
{
T_2 V_9 [ 2 ] = { V_23 & 0xff , ( V_23 >> 8 ) & 0xff } ;
return F_1 ( V_2 , V_3 , V_9 , 2 ) ;
}
static int F_13 ( struct V_1 * V_2 , const T_1 V_3 , T_3 V_23 )
{
T_2 V_9 [ 3 ] = { V_23 & 0xff , ( V_23 >> 8 ) & 0xff , ( V_23 >> 16 ) & 0xff } ;
return F_1 ( V_2 , V_3 , V_9 , 3 ) ;
}
static int F_14 ( struct V_1 * V_2 , const T_1 V_3 , T_3 V_23 )
{
T_2 V_9 [ 4 ] = {
V_23 & 0xff ,
( V_23 >> 8 ) & 0xff ,
( V_23 >> 16 ) & 0xff ,
( V_23 >> 24 ) & 0xff
} ;
return F_1 ( V_2 , V_3 , V_9 , 4 ) ;
}
static int F_15 ( struct V_1 * V_2 , const T_1 V_3 ,
T_2 V_23 , T_2 V_27 )
{
int V_6 ;
T_2 V_28 ;
if ( V_27 != 0xff ) {
V_6 = F_8 ( V_2 , V_3 , & V_28 ) ;
if ( V_6 < 0 )
goto V_29;
V_23 &= V_27 ;
V_28 &= ~ V_27 ;
V_23 |= V_28 ;
}
V_6 = F_11 ( V_2 , V_3 , V_23 ) ;
V_29:
return V_6 ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_30 * V_31 ,
int V_5 )
{
int V_32 ;
int V_6 ;
for ( V_32 = 0 ; V_32 < V_5 ; V_32 ++ ) {
V_6 = F_11 ( V_2 , V_31 [ V_32 ] . V_3 , V_31 [ V_32 ] . V_23 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_17 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> V_37 = 1000 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_3 V_38 = V_2 -> V_15 . V_38 ;
T_2 V_39 = 1 ;
T_2 V_40 = 1 ;
T_2 V_41 = 56 ;
T_2 V_42 = 8 ;
T_2 V_43 = 12 ;
T_2 V_9 [ 4 ] ;
switch ( V_38 ) {
case 16000000u :
V_41 = 56 ;
break;
case 24000000u :
V_39 = 2 ;
V_40 = 4 ;
V_41 = 19 ;
break;
default:
if ( V_38 > 16000000u )
V_39 = 2 ;
if ( 1624000000u * V_39 > V_38 * 2u * 63u )
V_40 = 4 ;
V_41 = 1624000000u * V_39 / ( V_38 * 2u * V_40 ) ;
break;
}
V_2 -> V_44 = V_38 / V_39
* 2u * V_41 * V_40 ;
V_2 -> V_45 = V_2 -> V_44 / ( V_42 * 4u ) ;
V_2 -> V_46 = V_2 -> V_44 / ( V_43 * 2u ) ;
V_9 [ 0 ] = V_43 ;
V_9 [ 1 ] = V_42 ;
V_9 [ 2 ] = ( V_41 & 0x3f ) | ( ( V_40 == 1 ) ? 0x40 : 0x00 ) | 0x80 ;
V_9 [ 3 ] = V_39 ;
return F_1 ( V_2 , 0x00a0 , V_9 , 4 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_43 )
{
V_2 -> V_46 = V_2 -> V_44 / ( V_43 * 2u ) ;
return F_11 ( V_2 , 0x00a0 , V_43 ) ;
}
static T_3 F_20 ( struct V_1 * V_2 )
{
return V_2 -> V_45 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_6 = - V_13 ;
T_2 V_23 = 0 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < 3 ; ++ V_32 ) {
F_8 ( V_2 , 0x0054 , & V_23 ) ;
if ( V_23 == 0x01 )
return 0 ;
F_22 ( 1000 , 50000 ) ;
}
F_5 ( & V_2 -> V_10 -> V_11 , L_7 ,
V_12 ) ;
return V_6 ;
}
static int F_23 ( struct V_1 * V_2 ,
const T_2 * V_47 , T_3 V_18 , T_3 * V_48 , T_3 V_49 )
{
int V_6 ;
T_2 V_50 [ 4 ] = { 0x00 , 0x00 , 0x00 , 0xc0 } ;
T_2 V_51 ;
T_3 V_52 = 0 ;
T_3 V_53 = V_48 ? * V_48 : 0 ;
if ( V_18 < 4 )
return - V_13 ;
if ( V_18 % 4 != 0 )
return - V_13 ;
F_24 (
L_8 ,
V_18 , V_53 , V_49 ) ;
while ( V_53 + 12 <= V_18 && V_52 < V_49 ) {
F_24 (
L_9 ,
V_18 , V_53 , V_52 , V_49 ) ;
V_51 = V_47 [ V_53 ] ;
if ( V_51 < 1 || V_47 [ V_53 + 1 ] ||
V_47 [ V_53 + 2 ] || V_47 [ V_53 + 3 ] ) {
F_2 ( & V_2 -> V_10 -> V_11 ,
L_10 ,
V_12 , 4 , V_47 ) ;
return - V_13 ;
}
if ( V_53 + 8 + V_51 * 4 > V_18 ) {
F_2 ( & V_2 -> V_10 -> V_11 ,
L_11 ,
V_12 , V_18 , V_51 ) ;
return - V_13 ;
}
V_50 [ 0 ] = V_51 - 1 ;
V_6 = F_1 ( V_2 , 0x0364 , V_50 , 4 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_1 ( V_2 , 0x0368 , V_47 + V_53 + 4 , 4 ) ;
if ( V_6 < 0 )
goto error;
V_53 += 8 ;
while ( V_51 > 0 ) {
V_6 = F_1 ( V_2 , 0x36c , V_47 + V_53 , 4 ) ;
if ( V_6 < 0 )
goto error;
V_51 -- ;
V_53 += 4 ;
}
V_52 ++ ;
}
F_24 (
L_12 ,
V_18 , V_53 , V_52 , V_49 ) ;
if ( V_48 )
* V_48 = V_53 ;
F_24 ( L_13 ,
V_53 ) ;
return 0 ;
error:
return V_6 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_2 V_23 [ 3 ] ;
T_1 V_54 ;
int V_6 ;
const struct V_55 * V_56 = NULL ;
T_2 * V_57 ;
const T_2 * V_47 ;
T_3 V_18 ;
T_3 V_53 ;
T_2 V_58 ;
T_2 V_49 ;
T_1 V_59 ;
switch ( V_2 -> V_60 ) {
case 0x03 :
V_57 = V_61 ;
break;
default:
F_26 ( & V_2 -> V_10 -> V_11 , L_14 ,
V_12 , V_2 -> V_60 ) ;
return 0 ;
}
V_6 = F_27 ( & V_56 , V_57 , V_2 -> V_10 -> V_11 . V_62 ) ;
if ( V_6 ) {
F_2 ( & V_2 -> V_10 -> V_11 , L_15 ,
V_12 , V_57 ) ;
goto error;
}
V_47 = V_56 -> V_47 ;
V_18 = V_56 -> V_63 ;
F_26 ( & V_2 -> V_10 -> V_11 , L_16 ,
V_12 , V_57 , V_18 ) ;
if ( V_18 % 4 != 0 ) {
F_2 ( & V_2 -> V_10 -> V_11 , L_17 ,
V_12 ) ;
V_6 = - V_13 ;
goto error;
}
if ( V_18 < 8 ) {
F_2 ( & V_2 -> V_10 -> V_11 , L_18 ,
V_12 ) ;
V_6 = - V_13 ;
goto error;
}
if ( V_47 [ 0 ] != 1 || V_47 [ 1 ] != 0 ) {
F_2 ( & V_2 -> V_10 -> V_11 , L_19 ,
V_12 ) ;
V_6 = - V_13 ;
goto error;
}
V_58 = V_47 [ 2 ] ;
V_49 = V_47 [ 4 ] ;
V_59 = V_47 [ 7 ] << 8 | V_47 [ 6 ] ;
V_6 = F_11 ( V_2 , 0x0341 , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x00c0 , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x0341 , V_23 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x035c , V_23 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x035c , V_23 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x035c , 0x02 ) ;
if ( V_6 < 0 )
goto error;
V_53 = 8 ;
F_26 ( & V_2 -> V_10 -> V_11 , L_20 ,
V_12 , V_58 , V_49 , V_59 ) ;
V_6 = F_23 ( V_2 , V_47 , V_18 , & V_53 , 1 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0344 , V_58 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0379 , 0x01 ) ;
if ( V_6 )
goto error;
V_6 = F_23 ( V_2 , V_47 , V_18 ,
& V_53 , V_49 ) ;
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_10 -> V_11 ,
L_21 ,
V_12 ) ;
goto error;
}
V_6 = F_10 ( V_2 , 0x037a , & V_54 ) ;
if ( V_6 )
goto error;
if ( V_54 != V_59 ) {
F_5 ( & V_2 -> V_10 -> V_11 ,
L_22 ,
V_12 , V_54 , V_59 ) ;
V_6 = - V_13 ;
goto error;
}
V_6 = F_23 ( V_2 , V_47 , V_18 , & V_53 , 5 ) ;
if ( V_6 )
goto error;
if ( V_18 != V_53 ) {
F_5 ( & V_2 -> V_10 -> V_11 ,
L_23 ,
V_12 , V_18 , V_53 ) ;
V_6 = - V_13 ;
goto error;
}
V_6 = F_15 ( V_2 , 0x0341 , 0x02 , 0x02 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_15 ( V_2 , 0x035c , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
F_26 ( & V_2 -> V_10 -> V_11 , L_24 , V_12 ) ;
V_6 = 0 ;
V_2 -> V_64 = true ;
error:
if ( V_56 ) {
F_28 ( V_56 ) ;
V_56 = NULL ;
}
return V_6 ;
}
static int F_29 ( struct V_33 * V_34 )
{
int V_6 = 0 ;
struct V_1 * V_2 = V_34 -> V_65 ;
T_2 V_23 ;
T_2 V_58 = 0x00 ;
F_30 ( L_25 , V_21 ) ;
V_6 = F_11 ( V_2 , 0x0000 , V_2 -> V_15 . V_66 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0104 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x0000 , & V_23 ) ;
if ( V_6 < 0 )
goto error;
if ( V_23 != V_2 -> V_15 . V_66 ) {
F_5 ( & V_2 -> V_10 -> V_11 , L_26 ,
V_12 ) ;
return - V_13 ;
}
V_6 = F_11 ( V_2 , 0x018b , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0190 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0170 , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0171 , 0x07 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0646 , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0641 , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_18 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0050 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0096 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_21 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0050 , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x0470 , 0x7530 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x0344 , & V_58 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x00cb , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_14 ( V_2 , 0x0348 , 0xf4000000 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x0341 , & V_23 ) ;
if ( V_6 < 0 )
goto error;
if ( V_58 == 0x00 ) {
V_6 = F_25 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
}
V_6 = F_11 ( V_2 , 0x04e4 , 0x20 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_2 , 0x04ef , 0x00fe ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_13 ( V_2 , 0x04f4 , 0x555555 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x04e5 , 0x01 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
error:
return V_6 ;
}
static int F_31 ( struct V_33 * V_34 )
{
int V_6 ;
struct V_1 * V_2 = V_34 -> V_65 ;
V_6 = F_11 ( V_2 , 0x0104 , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x0000 , V_67 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_32 ( struct V_33 * V_34 , enum V_68 * V_69 )
{
int V_6 ;
T_2 V_70 = 0 ;
struct V_1 * V_2 = V_34 -> V_65 ;
if ( ! V_2 -> V_71 )
return - V_13 ;
V_6 = F_8 ( V_2 , 0x4e0 , & V_70 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_69 = 0 ;
if ( V_70 & 0x01 ) {
* V_69 |= V_72 ;
* V_69 |= V_73 ;
* V_69 |= V_74 ;
* V_69 |= V_75 ;
* V_69 |= V_76 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , T_3 V_77 )
{
T_4 V_78 ;
T_3 V_79 ;
V_78 = F_20 ( V_2 ) ;
V_78 <<= 23 ;
F_34 ( V_78 , V_77 ) ;
V_79 = V_78 & 0x3fffffff ;
F_30 ( L_27 , V_21 , V_79 ) ;
return F_14 ( V_2 , 0x00e4 , V_79 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = & V_2 -> V_34 ;
T_4 V_80 ;
T_5 V_79 = 0 ;
T_3 V_81 = F_20 ( V_2 ) ;
T_3 IF = 0 ;
if ( ! V_34 -> V_82 . V_83 . V_84 ) {
F_5 ( & V_2 -> V_10 -> V_11 ,
L_28 ,
V_12 ) ;
return - V_13 ;
}
V_34 -> V_82 . V_83 . V_84 ( V_34 , & IF ) ;
V_80 = IF ;
V_80 <<= 29 ;
F_34 ( V_80 , V_81 ) ;
V_79 = ( T_5 ) V_80 ;
if ( V_2 -> V_15 . V_85 )
V_79 = - V_79 ;
V_79 = V_79 & 0x1fffffff ;
return F_14 ( V_2 , 0x00e8 , V_79 ) ;
}
static int F_36 ( struct V_33 * V_34 )
{
int V_6 ;
struct V_86 * V_87 = & V_34 -> V_88 ;
struct V_1 * V_2 = V_34 -> V_65 ;
T_3 V_77 = 0 ;
T_1 V_89 ;
F_30 ( L_25 , V_21 ) ;
if ( ! V_2 -> V_71 )
return - V_13 ;
if ( V_87 -> V_90 > 0 ) {
V_77 = V_87 -> V_90 * 8 / 7 ;
V_89 = V_87 -> V_90 / 10000 ;
} else {
V_77 = 8 * 8 / 7 ;
V_89 = 800 ;
}
V_6 = F_19 ( V_2 , 12 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_2 , 0x0308 , V_89 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_33 ( V_2 , V_77 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_16 ( V_2 , V_91 , F_37 ( V_91 ) ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_38 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_65 ;
int V_6 ;
struct V_86 * V_87 = & V_34 -> V_88 ;
const T_3 V_77 = V_87 -> V_92 ;
const T_3 V_93 = V_87 -> V_90 ;
if ( ! V_2 -> V_94 )
return - V_13 ;
if ( V_77 == 0 )
return - V_13 ;
V_6 = F_19 ( V_2 , 14 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_33 ( V_2 , V_77 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_14 ( V_2 , 0x00c4 , V_93 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_16 ( V_2 , V_95 , F_37 ( V_95 ) ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_39 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_65 ;
struct V_86 * V_87 = & V_34 -> V_88 ;
T_3 V_96 = V_87 -> V_97 ;
int V_6 ;
T_2 V_23 [ 3 ] ;
V_6 = F_35 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_96 ) {
case V_98 :
V_6 = F_36 ( V_34 ) ;
if ( V_6 < 0 )
return V_6 ;
break;
case V_99 :
V_6 = F_38 ( V_34 ) ;
if ( V_6 < 0 )
return V_6 ;
break;
default:
return - V_13 ;
}
V_6 = F_14 ( V_2 , 0x0348 , 0xf4000000 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_34 -> V_82 . V_83 . V_100 )
V_34 -> V_82 . V_83 . V_100 ( V_34 ) ;
V_6 = F_35 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_2 , 0x0341 , V_23 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x0341 , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x00c0 , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_14 ( V_2 , 0x0384 , 0x00000000 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_16 ( V_2 , V_101 ,
F_37 ( V_101 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x02e0 , 0x01 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_2 , 0x0341 , V_23 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static void F_40 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_65 ;
F_30 ( L_25 , V_21 ) ;
F_41 ( V_2 ) ;
}
struct V_33 * F_42 ( const struct V_102 * V_15 ,
struct V_103 * V_10 )
{
struct V_1 * V_2 = NULL ;
int V_104 ;
int V_105 ;
T_2 V_23 ;
char V_106 ;
const char * V_107 ;
if ( V_15 == NULL || V_10 == NULL )
goto error;
V_2 = F_43 ( sizeof( struct V_1 ) , V_108 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_15 = * V_15 ;
if ( V_2 -> V_15 . V_38 < 4000000
|| V_2 -> V_15 . V_38 > 27000000 ) {
F_5 ( & V_2 -> V_10 -> V_11 , L_29 ,
V_12 , V_2 -> V_15 . V_38 ) ;
goto error;
}
memcpy ( & V_2 -> V_34 . V_82 , & V_109 ,
sizeof( struct V_110 ) ) ;
V_2 -> V_34 . V_65 = V_2 ;
V_105 = F_11 ( V_2 , 0x0000 , V_2 -> V_15 . V_66 ) ;
if ( V_105 < 0 )
goto error;
V_105 = F_8 ( V_2 , 0x0000 , & V_23 ) ;
if ( V_105 < 0 )
goto error;
if ( V_23 != V_2 -> V_15 . V_66 )
goto error;
V_105 = F_8 ( V_2 , 0x0023 , & V_2 -> V_60 ) ;
if ( V_105 < 0 )
goto error;
V_105 = F_8 ( V_2 , 0x0118 , & V_2 -> V_111 ) ;
if ( V_105 < 0 )
goto error;
V_105 = F_11 ( V_2 , 0x0000 , V_67 ) ;
if ( V_105 < 0 )
goto error;
if ( V_2 -> V_60 < 26 )
V_106 = 'A' + V_2 -> V_60 ;
else
V_106 = '?' ;
switch ( V_2 -> V_111 ) {
case 0x06 :
V_107 = L_30 ;
V_2 -> V_71 = true ;
break;
case 0x07 :
V_107 = L_31 ;
V_2 -> V_71 = true ;
V_2 -> V_94 = true ;
break;
default:
F_5 ( & V_2 -> V_10 -> V_11 , L_32 ,
V_12 , V_2 -> V_111 , V_2 -> V_60 ) ;
goto error;
}
F_26 ( & V_2 -> V_10 -> V_11 ,
L_33 ,
V_12 , V_107 , V_106 , V_2 -> V_111 ,
V_2 -> V_60 ) ;
F_44 ( V_2 -> V_34 . V_82 . V_112 . V_113 , V_107 ,
sizeof( V_2 -> V_34 . V_82 . V_112 . V_113 ) ) ;
V_104 = 0 ;
if ( V_2 -> V_71 ) {
V_2 -> V_34 . V_82 . V_96 [ V_104 ++ ] = V_98 ;
F_44 ( V_2 -> V_34 . V_82 . V_112 . V_113 , L_34 ,
sizeof( V_2 -> V_34 . V_82 . V_112 . V_113 ) ) ;
}
if ( V_2 -> V_94 ) {
V_2 -> V_34 . V_82 . V_96 [ V_104 ++ ] = V_99 ;
F_44 ( V_2 -> V_34 . V_82 . V_112 . V_113 , L_35 ,
sizeof( V_2 -> V_34 . V_82 . V_112 . V_113 ) ) ;
}
return & V_2 -> V_34 ;
error:
F_41 ( V_2 ) ;
return NULL ;
}
