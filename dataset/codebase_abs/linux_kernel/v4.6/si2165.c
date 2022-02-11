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
if ( V_27 != 0xff ) {
T_2 V_28 ;
int V_6 = F_8 ( V_2 , V_3 , & V_28 ) ;
if ( V_6 < 0 )
return V_6 ;
V_23 &= V_27 ;
V_28 &= ~ V_27 ;
V_23 |= V_28 ;
}
return F_11 ( V_2 , V_3 , V_23 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_29 * V_30 ,
int V_5 )
{
int V_31 ;
int V_6 ;
for ( V_31 = 0 ; V_31 < V_5 ; V_31 ++ ) {
V_6 = F_11 ( V_2 , V_30 [ V_31 ] . V_3 , V_30 [ V_31 ] . V_23 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_17 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
V_35 -> V_36 = 1000 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_3 V_37 = V_2 -> V_15 . V_37 ;
T_2 V_38 = 1 ;
T_2 V_39 = 1 ;
T_2 V_40 = 56 ;
T_2 V_41 = 8 ;
T_2 V_42 = 12 ;
T_2 V_9 [ 4 ] ;
switch ( V_37 ) {
case 16000000u :
V_40 = 56 ;
break;
case 24000000u :
V_38 = 2 ;
V_39 = 4 ;
V_40 = 19 ;
break;
default:
if ( V_37 > 16000000u )
V_38 = 2 ;
if ( 1624000000u * V_38 > V_37 * 2u * 63u )
V_39 = 4 ;
V_40 = 1624000000u * V_38 / ( V_37 * 2u * V_39 ) ;
break;
}
V_2 -> V_43 = V_37 / V_38
* 2u * V_40 * V_39 ;
V_2 -> V_44 = V_2 -> V_43 / ( V_41 * 4u ) ;
V_2 -> V_45 = V_2 -> V_43 / ( V_42 * 2u ) ;
V_9 [ 0 ] = V_42 ;
V_9 [ 1 ] = V_41 ;
V_9 [ 2 ] = ( V_40 & 0x3f ) | ( ( V_39 == 1 ) ? 0x40 : 0x00 ) | 0x80 ;
V_9 [ 3 ] = V_38 ;
return F_1 ( V_2 , 0x00a0 , V_9 , 4 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_42 )
{
V_2 -> V_45 = V_2 -> V_43 / ( V_42 * 2u ) ;
return F_11 ( V_2 , 0x00a0 , V_42 ) ;
}
static T_3 F_20 ( struct V_1 * V_2 )
{
return V_2 -> V_44 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_6 = - V_13 ;
T_2 V_23 = 0 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < 3 ; ++ V_31 ) {
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
const T_2 * V_46 , T_3 V_18 , T_3 * V_47 , T_3 V_48 )
{
int V_6 ;
T_2 V_49 [ 4 ] = { 0x00 , 0x00 , 0x00 , 0xc0 } ;
T_2 V_50 ;
T_3 V_51 = 0 ;
T_3 V_52 = V_47 ? * V_47 : 0 ;
if ( V_18 < 4 )
return - V_13 ;
if ( V_18 % 4 != 0 )
return - V_13 ;
F_24 (
L_8 ,
V_18 , V_52 , V_48 ) ;
while ( V_52 + 12 <= V_18 && V_51 < V_48 ) {
F_24 (
L_9 ,
V_18 , V_52 , V_51 , V_48 ) ;
V_50 = V_46 [ V_52 ] ;
if ( V_50 < 1 || V_46 [ V_52 + 1 ] ||
V_46 [ V_52 + 2 ] || V_46 [ V_52 + 3 ] ) {
F_2 ( & V_2 -> V_10 -> V_11 ,
L_10 ,
V_12 , 4 , V_46 ) ;
return - V_13 ;
}
if ( V_52 + 8 + V_50 * 4 > V_18 ) {
F_2 ( & V_2 -> V_10 -> V_11 ,
L_11 ,
V_12 , V_18 , V_50 ) ;
return - V_13 ;
}
V_49 [ 0 ] = V_50 - 1 ;
V_6 = F_1 ( V_2 , 0x0364 , V_49 , 4 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_1 ( V_2 , 0x0368 , V_46 + V_52 + 4 , 4 ) ;
if ( V_6 < 0 )
goto error;
V_52 += 8 ;
while ( V_50 > 0 ) {
V_6 = F_1 ( V_2 , 0x36c , V_46 + V_52 , 4 ) ;
if ( V_6 < 0 )
goto error;
V_50 -- ;
V_52 += 4 ;
}
V_51 ++ ;
}
F_24 (
L_12 ,
V_18 , V_52 , V_51 , V_48 ) ;
if ( V_47 )
* V_47 = V_52 ;
F_24 ( L_13 ,
V_52 ) ;
return 0 ;
error:
return V_6 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_2 V_23 [ 3 ] ;
T_1 V_53 ;
int V_6 ;
const struct V_54 * V_55 = NULL ;
T_2 * V_56 ;
const T_2 * V_46 ;
T_3 V_18 ;
T_3 V_52 ;
T_2 V_57 ;
T_2 V_48 ;
T_1 V_58 ;
switch ( V_2 -> V_59 ) {
case 0x03 :
V_56 = V_60 ;
break;
default:
F_26 ( & V_2 -> V_10 -> V_11 , L_14 ,
V_12 , V_2 -> V_59 ) ;
return 0 ;
}
V_6 = F_27 ( & V_55 , V_56 , V_2 -> V_10 -> V_11 . V_61 ) ;
if ( V_6 ) {
F_2 ( & V_2 -> V_10 -> V_11 , L_15 ,
V_12 , V_56 ) ;
goto error;
}
V_46 = V_55 -> V_46 ;
V_18 = V_55 -> V_62 ;
F_26 ( & V_2 -> V_10 -> V_11 , L_16 ,
V_12 , V_56 , V_18 ) ;
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
if ( V_46 [ 0 ] != 1 || V_46 [ 1 ] != 0 ) {
F_2 ( & V_2 -> V_10 -> V_11 , L_19 ,
V_12 ) ;
V_6 = - V_13 ;
goto error;
}
V_57 = V_46 [ 2 ] ;
V_48 = V_46 [ 4 ] ;
V_58 = V_46 [ 7 ] << 8 | V_46 [ 6 ] ;
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
V_52 = 8 ;
F_26 ( & V_2 -> V_10 -> V_11 , L_20 ,
V_12 , V_57 , V_48 , V_58 ) ;
V_6 = F_23 ( V_2 , V_46 , V_18 , & V_52 , 1 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0344 , V_57 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0379 , 0x01 ) ;
if ( V_6 )
goto error;
V_6 = F_23 ( V_2 , V_46 , V_18 ,
& V_52 , V_48 ) ;
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_10 -> V_11 ,
L_21 ,
V_12 ) ;
goto error;
}
V_6 = F_10 ( V_2 , 0x037a , & V_53 ) ;
if ( V_6 )
goto error;
if ( V_53 != V_58 ) {
F_5 ( & V_2 -> V_10 -> V_11 ,
L_22 ,
V_12 , V_53 , V_58 ) ;
V_6 = - V_13 ;
goto error;
}
V_6 = F_23 ( V_2 , V_46 , V_18 , & V_52 , 5 ) ;
if ( V_6 )
goto error;
if ( V_18 != V_52 ) {
F_5 ( & V_2 -> V_10 -> V_11 ,
L_23 ,
V_12 , V_18 , V_52 ) ;
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
V_2 -> V_63 = true ;
error:
if ( V_55 ) {
F_28 ( V_55 ) ;
V_55 = NULL ;
}
return V_6 ;
}
static int F_29 ( struct V_32 * V_33 )
{
int V_6 = 0 ;
struct V_1 * V_2 = V_33 -> V_64 ;
T_2 V_23 ;
T_2 V_57 = 0x00 ;
F_30 ( L_25 , V_21 ) ;
V_6 = F_11 ( V_2 , 0x0000 , V_2 -> V_15 . V_65 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0104 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x0000 , & V_23 ) ;
if ( V_6 < 0 )
goto error;
if ( V_23 != V_2 -> V_15 . V_65 ) {
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
V_6 = F_8 ( V_2 , 0x0344 , & V_57 ) ;
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
if ( V_57 == 0x00 ) {
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
static int F_31 ( struct V_32 * V_33 )
{
int V_6 ;
struct V_1 * V_2 = V_33 -> V_64 ;
V_6 = F_11 ( V_2 , 0x0104 , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x0000 , V_66 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_32 ( struct V_32 * V_33 , enum V_67 * V_68 )
{
int V_6 ;
T_2 V_69 = 0 ;
struct V_1 * V_2 = V_33 -> V_64 ;
if ( ! V_2 -> V_70 )
return - V_13 ;
V_6 = F_8 ( V_2 , 0x4e0 , & V_69 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_68 = 0 ;
if ( V_69 & 0x01 ) {
* V_68 |= V_71 ;
* V_68 |= V_72 ;
* V_68 |= V_73 ;
* V_68 |= V_74 ;
* V_68 |= V_75 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , T_3 V_76 )
{
T_4 V_77 ;
T_3 V_78 ;
V_77 = F_20 ( V_2 ) ;
V_77 <<= 23 ;
F_34 ( V_77 , V_76 ) ;
V_78 = V_77 & 0x3fffffff ;
F_30 ( L_27 , V_21 , V_78 ) ;
return F_14 ( V_2 , 0x00e4 , V_78 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = & V_2 -> V_33 ;
T_4 V_79 ;
T_5 V_78 = 0 ;
T_3 V_80 = F_20 ( V_2 ) ;
T_3 IF = 0 ;
if ( ! V_33 -> V_81 . V_82 . V_83 ) {
F_5 ( & V_2 -> V_10 -> V_11 ,
L_28 ,
V_12 ) ;
return - V_13 ;
}
V_33 -> V_81 . V_82 . V_83 ( V_33 , & IF ) ;
V_79 = IF ;
V_79 <<= 29 ;
F_34 ( V_79 , V_80 ) ;
V_78 = ( T_5 ) V_79 ;
if ( V_2 -> V_15 . V_84 )
V_78 = - V_78 ;
V_78 = V_78 & 0x1fffffff ;
return F_14 ( V_2 , 0x00e8 , V_78 ) ;
}
static int F_36 ( struct V_32 * V_33 )
{
int V_6 ;
struct V_85 * V_86 = & V_33 -> V_87 ;
struct V_1 * V_2 = V_33 -> V_64 ;
T_3 V_76 = 0 ;
T_1 V_88 ;
T_3 V_89 = V_86 -> V_90 ;
F_30 ( L_25 , V_21 ) ;
if ( ! V_2 -> V_70 )
return - V_13 ;
if ( V_89 == 0 )
return - V_13 ;
V_76 = V_89 * 8 / 7 ;
V_88 = V_89 / 10000 ;
V_6 = F_19 ( V_2 , 12 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_2 , 0x0308 , V_88 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_33 ( V_2 , V_76 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_16 ( V_2 , V_91 , F_37 ( V_91 ) ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_38 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_64 ;
int V_6 ;
struct V_85 * V_86 = & V_33 -> V_87 ;
const T_3 V_76 = V_86 -> V_92 ;
const T_3 V_89 = V_86 -> V_90 ;
if ( ! V_2 -> V_93 )
return - V_13 ;
if ( V_76 == 0 )
return - V_13 ;
V_6 = F_19 ( V_2 , 14 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_33 ( V_2 , V_76 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_14 ( V_2 , 0x00c4 , V_89 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_16 ( V_2 , V_94 , F_37 ( V_94 ) ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_39 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_64 ;
struct V_85 * V_86 = & V_33 -> V_87 ;
T_3 V_95 = V_86 -> V_96 ;
int V_6 ;
T_2 V_23 [ 3 ] ;
V_6 = F_35 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_95 ) {
case V_97 :
V_6 = F_36 ( V_33 ) ;
if ( V_6 < 0 )
return V_6 ;
break;
case V_98 :
V_6 = F_38 ( V_33 ) ;
if ( V_6 < 0 )
return V_6 ;
break;
default:
return - V_13 ;
}
V_6 = F_14 ( V_2 , 0x0348 , 0xf4000000 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_33 -> V_81 . V_82 . V_99 )
V_33 -> V_81 . V_82 . V_99 ( V_33 ) ;
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
V_6 = F_16 ( V_2 , V_100 ,
F_37 ( V_100 ) ) ;
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
static void F_40 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_64 ;
F_30 ( L_25 , V_21 ) ;
F_41 ( V_2 ) ;
}
struct V_32 * F_42 ( const struct V_101 * V_15 ,
struct V_102 * V_10 )
{
struct V_1 * V_2 = NULL ;
int V_103 ;
int V_104 ;
T_2 V_23 ;
char V_105 ;
const char * V_106 ;
if ( V_15 == NULL || V_10 == NULL )
goto error;
V_2 = F_43 ( sizeof( struct V_1 ) , V_107 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_15 = * V_15 ;
if ( V_2 -> V_15 . V_37 < 4000000
|| V_2 -> V_15 . V_37 > 27000000 ) {
F_5 ( & V_2 -> V_10 -> V_11 , L_29 ,
V_12 , V_2 -> V_15 . V_37 ) ;
goto error;
}
memcpy ( & V_2 -> V_33 . V_81 , & V_108 ,
sizeof( struct V_109 ) ) ;
V_2 -> V_33 . V_64 = V_2 ;
V_104 = F_11 ( V_2 , 0x0000 , V_2 -> V_15 . V_65 ) ;
if ( V_104 < 0 )
goto error;
V_104 = F_8 ( V_2 , 0x0000 , & V_23 ) ;
if ( V_104 < 0 )
goto error;
if ( V_23 != V_2 -> V_15 . V_65 )
goto error;
V_104 = F_8 ( V_2 , 0x0023 , & V_2 -> V_59 ) ;
if ( V_104 < 0 )
goto error;
V_104 = F_8 ( V_2 , 0x0118 , & V_2 -> V_110 ) ;
if ( V_104 < 0 )
goto error;
V_104 = F_11 ( V_2 , 0x0000 , V_66 ) ;
if ( V_104 < 0 )
goto error;
if ( V_2 -> V_59 < 26 )
V_105 = 'A' + V_2 -> V_59 ;
else
V_105 = '?' ;
switch ( V_2 -> V_110 ) {
case 0x06 :
V_106 = L_30 ;
V_2 -> V_70 = true ;
break;
case 0x07 :
V_106 = L_31 ;
V_2 -> V_70 = true ;
V_2 -> V_93 = true ;
break;
default:
F_5 ( & V_2 -> V_10 -> V_11 , L_32 ,
V_12 , V_2 -> V_110 , V_2 -> V_59 ) ;
goto error;
}
F_26 ( & V_2 -> V_10 -> V_11 ,
L_33 ,
V_12 , V_106 , V_105 , V_2 -> V_110 ,
V_2 -> V_59 ) ;
F_44 ( V_2 -> V_33 . V_81 . V_111 . V_112 , V_106 ,
sizeof( V_2 -> V_33 . V_81 . V_111 . V_112 ) ) ;
V_103 = 0 ;
if ( V_2 -> V_70 ) {
V_2 -> V_33 . V_81 . V_95 [ V_103 ++ ] = V_97 ;
F_44 ( V_2 -> V_33 . V_81 . V_111 . V_112 , L_34 ,
sizeof( V_2 -> V_33 . V_81 . V_111 . V_112 ) ) ;
}
if ( V_2 -> V_93 ) {
V_2 -> V_33 . V_81 . V_95 [ V_103 ++ ] = V_98 ;
F_44 ( V_2 -> V_33 . V_81 . V_111 . V_112 , L_35 ,
sizeof( V_2 -> V_33 . V_81 . V_111 . V_112 ) ) ;
}
return & V_2 -> V_33 ;
error:
F_41 ( V_2 ) ;
return NULL ;
}
