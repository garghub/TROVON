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
static int F_16 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
V_33 -> V_34 = 1000 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_3 V_35 = V_2 -> V_15 . V_35 ;
T_2 V_36 = 1 ;
T_2 V_37 = 1 ;
T_2 V_38 = 56 ;
T_2 V_39 = 8 ;
T_2 V_40 = 12 ;
T_2 V_9 [ 4 ] ;
switch ( V_35 ) {
case 16000000u :
V_38 = 56 ;
break;
case 24000000u :
V_36 = 2 ;
V_37 = 4 ;
V_38 = 19 ;
break;
default:
if ( V_35 > 16000000u )
V_36 = 2 ;
if ( 1624000000u * V_36 > V_35 * 2u * 63u )
V_37 = 4 ;
V_38 = 1624000000u * V_36 / ( V_35 * 2u * V_37 ) ;
break;
}
V_2 -> V_41 = V_35 / V_36
* 2u * V_38 * V_37 ;
V_2 -> V_42 = V_2 -> V_41 / ( V_39 * 4u ) ;
V_2 -> V_43 = V_2 -> V_41 / ( V_40 * 2u ) ;
V_9 [ 0 ] = V_40 ;
V_9 [ 1 ] = V_39 ;
V_9 [ 2 ] = ( V_38 & 0x3f ) | ( ( V_37 == 1 ) ? 0x40 : 0x00 ) | 0x80 ;
V_9 [ 3 ] = V_36 ;
return F_1 ( V_2 , 0x00a0 , V_9 , 4 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_2 V_40 )
{
V_2 -> V_43 = V_2 -> V_41 / ( V_40 * 2u ) ;
return F_11 ( V_2 , 0x00a0 , V_40 ) ;
}
static T_3 F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_42 ;
}
static bool F_20 ( struct V_1 * V_2 )
{
int V_6 = - V_13 ;
T_2 V_23 = 0 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < 3 ; ++ V_44 ) {
F_8 ( V_2 , 0x0054 , & V_23 ) ;
if ( V_23 == 0x01 )
return 0 ;
F_21 ( 1000 , 50000 ) ;
}
F_5 ( & V_2 -> V_10 -> V_11 , L_7 ,
V_12 ) ;
return V_6 ;
}
static int F_22 ( struct V_1 * V_2 ,
const T_2 * V_45 , T_3 V_18 , T_3 * V_46 , T_3 V_47 )
{
int V_6 ;
T_2 V_48 [ 4 ] = { 0x00 , 0x00 , 0x00 , 0xc0 } ;
T_2 V_49 ;
T_3 V_50 = 0 ;
T_3 V_51 = V_46 ? * V_46 : 0 ;
if ( V_18 < 4 )
return - V_13 ;
if ( V_18 % 4 != 0 )
return - V_13 ;
F_23 ( L_8 ,
V_18 , V_51 , V_47 ) ;
while ( V_51 + 12 <= V_18 && V_50 < V_47 ) {
F_23 ( L_9 ,
V_18 , V_51 , V_50 , V_47 ) ;
V_49 = V_45 [ V_51 ] ;
if ( V_49 < 1 || V_45 [ V_51 + 1 ] ||
V_45 [ V_51 + 2 ] || V_45 [ V_51 + 3 ] ) {
F_2 ( & V_2 -> V_10 -> V_11 ,
L_10 ,
V_12 , 4 , V_45 ) ;
return - V_13 ;
}
if ( V_51 + 8 + V_49 * 4 > V_18 ) {
F_2 ( & V_2 -> V_10 -> V_11 ,
L_11 ,
V_12 , V_18 , V_49 ) ;
return - V_13 ;
}
V_48 [ 0 ] = V_49 - 1 ;
V_6 = F_1 ( V_2 , 0x0364 , V_48 , 4 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_1 ( V_2 , 0x0368 , V_45 + V_51 + 4 , 4 ) ;
if ( V_6 < 0 )
goto error;
V_51 += 8 ;
while ( V_49 > 0 ) {
V_6 = F_1 ( V_2 , 0x36c , V_45 + V_51 , 4 ) ;
if ( V_6 < 0 )
goto error;
V_49 -- ;
V_51 += 4 ;
}
V_50 ++ ;
}
F_23 ( L_12 ,
V_18 , V_51 , V_50 , V_47 ) ;
if ( V_46 )
* V_46 = V_51 ;
F_23 ( L_13 ,
V_51 ) ;
return 0 ;
error:
return V_6 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_2 V_23 [ 3 ] ;
T_1 V_52 ;
int V_6 ;
const struct V_53 * V_54 = NULL ;
T_2 * V_55 = V_56 ;
const T_2 * V_45 ;
T_3 V_18 ;
T_3 V_51 ;
T_2 V_57 ;
T_2 V_47 ;
T_1 V_58 ;
V_6 = F_25 ( & V_54 , V_55 , V_2 -> V_10 -> V_11 . V_59 ) ;
if ( V_6 ) {
F_2 ( & V_2 -> V_10 -> V_11 , L_14 ,
V_12 , V_55 ) ;
goto error;
}
V_45 = V_54 -> V_45 ;
V_18 = V_54 -> V_60 ;
F_26 ( & V_2 -> V_10 -> V_11 , L_15 ,
V_12 , V_55 , V_18 ) ;
if ( V_18 % 4 != 0 ) {
F_2 ( & V_2 -> V_10 -> V_11 , L_16 ,
V_12 ) ;
V_6 = - V_13 ;
goto error;
}
if ( V_18 < 8 ) {
F_2 ( & V_2 -> V_10 -> V_11 , L_17 ,
V_12 ) ;
V_6 = - V_13 ;
goto error;
}
if ( V_45 [ 0 ] != 1 || V_45 [ 1 ] != 0 ) {
F_2 ( & V_2 -> V_10 -> V_11 , L_18 ,
V_12 ) ;
V_6 = - V_13 ;
goto error;
}
V_57 = V_45 [ 2 ] ;
V_47 = V_45 [ 4 ] ;
V_58 = V_45 [ 7 ] << 8 | V_45 [ 6 ] ;
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
V_51 = 8 ;
F_26 ( & V_2 -> V_10 -> V_11 , L_19 ,
V_12 , V_57 , V_47 , V_58 ) ;
V_6 = F_22 ( V_2 , V_45 , V_18 , & V_51 , 1 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0344 , V_57 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0379 , 0x01 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_22 ( V_2 , V_45 , V_18 ,
& V_51 , V_47 ) ;
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_10 -> V_11 ,
L_20 ,
V_12 ) ;
goto error;
}
V_6 = F_10 ( V_2 , 0x037a , & V_52 ) ;
if ( V_6 )
goto error;
if ( V_52 != V_58 ) {
F_5 ( & V_2 -> V_10 -> V_11 ,
L_21 ,
V_12 , V_52 , V_58 ) ;
V_6 = - V_13 ;
goto error;
}
V_6 = F_22 ( V_2 , V_45 , V_18 , & V_51 , 5 ) ;
if ( V_6 )
goto error;
if ( V_18 != V_51 ) {
F_5 ( & V_2 -> V_10 -> V_11 ,
L_22 ,
V_12 , V_18 , V_51 ) ;
V_6 = - V_13 ;
goto error;
}
V_6 = F_15 ( V_2 , 0x0341 , 0x02 , 0x02 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_15 ( V_2 , 0x035c , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
F_26 ( & V_2 -> V_10 -> V_11 , L_23 , V_12 ) ;
V_6 = 0 ;
V_2 -> V_61 = true ;
error:
if ( V_54 ) {
F_27 ( V_54 ) ;
V_54 = NULL ;
}
return V_6 ;
}
static int F_28 ( struct V_30 * V_31 )
{
int V_6 = 0 ;
struct V_1 * V_2 = V_31 -> V_62 ;
T_2 V_23 ;
T_2 V_57 = 0x00 ;
F_29 ( L_24 , V_21 ) ;
V_6 = F_11 ( V_2 , 0x0000 , V_2 -> V_15 . V_63 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0104 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x0000 , & V_23 ) ;
if ( V_6 < 0 )
goto error;
if ( V_23 != V_2 -> V_15 . V_63 ) {
F_5 ( & V_2 -> V_10 -> V_11 , L_25 ,
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
V_6 = F_17 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0050 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0096 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_20 ( V_2 ) ;
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
V_6 = F_24 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
}
V_6 = F_11 ( V_2 , 0x012a , 0x46 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x012c , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x012e , 0x0a ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x012f , 0xff ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 , 0x0123 , 0x70 ) ;
if ( V_6 < 0 )
goto error;
return 0 ;
error:
return V_6 ;
}
static int F_30 ( struct V_30 * V_31 )
{
int V_6 ;
struct V_1 * V_2 = V_31 -> V_62 ;
V_6 = F_11 ( V_2 , 0x0104 , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x0000 , V_64 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_31 ( struct V_30 * V_31 , T_4 * V_65 )
{
int V_6 ;
T_2 V_66 = 0 ;
struct V_1 * V_2 = V_31 -> V_62 ;
if ( ! V_2 -> V_67 )
return - V_13 ;
V_6 = F_8 ( V_2 , 0x4e0 , & V_66 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_65 = 0 ;
if ( V_66 & 0x01 ) {
* V_65 |= V_68 ;
* V_65 |= V_69 ;
* V_65 |= V_70 ;
* V_65 |= V_71 ;
* V_65 |= V_72 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , T_3 V_73 )
{
T_5 V_74 ;
T_3 V_75 ;
V_74 = F_19 ( V_2 ) ;
V_74 <<= 23 ;
F_33 ( V_74 , V_73 ) ;
V_75 = V_74 & 0x3fffffff ;
return F_14 ( V_2 , 0x00e4 , V_75 ) ;
}
static int F_34 ( struct V_1 * V_2 , T_3 IF )
{
T_5 V_76 ;
T_6 V_75 = 0 ;
T_3 V_77 = F_19 ( V_2 ) ;
V_76 = IF ;
V_76 <<= 29 ;
F_33 ( V_76 , V_77 ) ;
V_75 = ( T_6 ) V_76 ;
if ( V_2 -> V_15 . V_78 )
V_75 = - V_75 ;
V_75 = V_75 & 0x1fffffff ;
return F_14 ( V_2 , 0x00e8 , V_75 ) ;
}
static int F_35 ( struct V_30 * V_31 )
{
int V_6 ;
struct V_79 * V_80 = & V_31 -> V_81 ;
struct V_1 * V_2 = V_31 -> V_62 ;
T_2 V_23 [ 3 ] ;
T_3 IF ;
T_3 V_73 = 0 ;
T_1 V_82 ;
F_29 ( L_24 , V_21 ) ;
if ( ! V_31 -> V_83 . V_84 . V_85 ) {
F_5 ( & V_2 -> V_10 -> V_11 ,
L_26 ,
V_12 ) ;
return - V_13 ;
}
if ( ! V_2 -> V_67 )
return - V_13 ;
if ( V_80 -> V_86 > 0 ) {
V_73 = V_80 -> V_86 * 8 / 7 ;
V_82 = V_80 -> V_86 / 10000 ;
} else {
V_73 = 8 * 8 / 7 ;
V_82 = 800 ;
}
V_6 = F_11 ( V_2 , 0x00ec , 0x01 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_18 ( V_2 , 12 ) ;
if ( V_6 < 0 )
return V_6 ;
V_31 -> V_83 . V_84 . V_85 ( V_31 , & IF ) ;
V_6 = F_34 ( V_2 , IF ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x08f8 , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
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
V_6 = F_12 ( V_2 , 0x0308 , V_82 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_32 ( V_2 , V_73 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x031c , 0x01 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x00cb , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x016e , 0x41 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x016c , 0x0e ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x016d , 0x10 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x015b , 0x03 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x0150 , 0x78 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x01a0 , 0x78 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x01c8 , 0x68 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_2 , 0x030c , 0x0064 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_2 , 0x0387 , V_23 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 , 0x0387 , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_14 ( V_2 , 0x0348 , 0xf4000000 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_31 -> V_83 . V_84 . V_87 )
V_31 -> V_83 . V_84 . V_87 ( V_31 ) ;
V_31 -> V_83 . V_84 . V_85 ( V_31 , & IF ) ;
V_6 = F_34 ( V_2 , IF ) ;
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
V_6 = F_11 ( V_2 , 0x02e0 , 0x01 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_2 , 0x0341 , V_23 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static void F_36 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_62 ;
F_29 ( L_24 , V_21 ) ;
F_37 ( V_2 ) ;
}
struct V_30 * F_38 ( const struct V_88 * V_15 ,
struct V_89 * V_10 )
{
struct V_1 * V_2 = NULL ;
int V_90 ;
int V_91 ;
T_2 V_23 ;
if ( V_15 == NULL || V_10 == NULL )
goto error;
V_2 = F_39 ( sizeof( struct V_1 ) , V_92 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_15 = * V_15 ;
if ( V_2 -> V_15 . V_35 < 4000000
|| V_2 -> V_15 . V_35 > 27000000 ) {
F_5 ( & V_2 -> V_10 -> V_11 , L_27 ,
V_12 , V_2 -> V_15 . V_35 ) ;
goto error;
}
memcpy ( & V_2 -> V_93 . V_83 , & V_94 ,
sizeof( struct V_95 ) ) ;
V_2 -> V_93 . V_62 = V_2 ;
V_91 = F_11 ( V_2 , 0x0000 , V_2 -> V_15 . V_63 ) ;
if ( V_91 < 0 )
goto error;
V_91 = F_8 ( V_2 , 0x0000 , & V_23 ) ;
if ( V_91 < 0 )
goto error;
if ( V_23 != V_2 -> V_15 . V_63 )
goto error;
V_91 = F_8 ( V_2 , 0x0023 , & V_2 -> V_96 ) ;
if ( V_91 < 0 )
goto error;
V_91 = F_8 ( V_2 , 0x0118 , & V_2 -> V_97 ) ;
if ( V_91 < 0 )
goto error;
V_91 = F_11 ( V_2 , 0x0000 , V_64 ) ;
if ( V_91 < 0 )
goto error;
F_26 ( & V_2 -> V_10 -> V_11 , L_28 ,
V_12 , V_2 -> V_96 , V_2 -> V_97 ) ;
if ( V_2 -> V_96 == 0x03 && V_2 -> V_97 == 0x07 ) {
V_2 -> V_67 = true ;
V_2 -> V_98 = true ;
} else {
F_5 ( & V_2 -> V_10 -> V_11 , L_29 ,
V_12 ) ;
goto error;
}
V_90 = 0 ;
if ( V_2 -> V_67 ) {
V_2 -> V_93 . V_83 . V_99 [ V_90 ++ ] = V_100 ;
F_40 ( V_2 -> V_93 . V_83 . V_101 . V_102 , L_30 ,
sizeof( V_2 -> V_93 . V_83 . V_101 . V_102 ) ) ;
}
if ( V_2 -> V_98 )
F_2 ( & V_2 -> V_10 -> V_11 , L_31 ,
V_12 ) ;
return & V_2 -> V_93 ;
error:
F_37 ( V_2 ) ;
return NULL ;
}
