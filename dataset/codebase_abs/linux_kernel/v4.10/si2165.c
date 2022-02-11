static int F_1 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_2 * V_4 , const int V_5 )
{
int V_6 ;
if ( V_7 & V_8 )
F_2 ( L_1 , V_3 , V_5 , V_4 ) ;
V_6 = F_3 ( V_2 -> V_9 , V_3 , V_4 , V_5 ) ;
if ( V_6 )
F_4 ( & V_2 -> V_10 -> V_11 , L_2 , V_12 , V_6 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 ,
const T_1 V_3 , T_2 * V_13 , const int V_5 )
{
int V_6 = F_6 ( V_2 -> V_9 , V_3 , V_13 , V_5 ) ;
if ( V_6 ) {
F_4 ( & V_2 -> V_10 -> V_11 , L_3 ,
V_12 , V_2 -> V_14 . V_15 , V_3 , V_6 ) ;
return V_6 ;
}
if ( V_7 & V_16 )
F_7 ( L_1 , V_3 , V_5 , V_13 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const T_1 V_3 , T_2 * V_13 )
{
unsigned int V_17 ;
int V_6 = F_9 ( V_2 -> V_9 , V_3 , & V_17 ) ;
* V_13 = ( T_2 ) V_17 ;
F_10 ( L_4 , V_3 , * V_13 ) ;
return V_6 ;
}
static int F_11 ( struct V_1 * V_2 ,
const T_1 V_3 , T_1 * V_13 )
{
T_2 V_18 [ 2 ] ;
int V_6 = F_5 ( V_2 , V_3 , V_18 , 2 ) ;
* V_13 = V_18 [ 0 ] | V_18 [ 1 ] << 8 ;
F_10 ( L_5 , V_3 , * V_13 ) ;
return V_6 ;
}
static int F_12 ( struct V_1 * V_2 , const T_1 V_3 , T_2 V_13 )
{
return F_13 ( V_2 -> V_9 , V_3 , V_13 ) ;
}
static int F_14 ( struct V_1 * V_2 , const T_1 V_3 , T_1 V_13 )
{
T_2 V_18 [ 2 ] = { V_13 & 0xff , ( V_13 >> 8 ) & 0xff } ;
return F_1 ( V_2 , V_3 , V_18 , 2 ) ;
}
static int F_15 ( struct V_1 * V_2 , const T_1 V_3 , T_3 V_13 )
{
T_2 V_18 [ 3 ] = { V_13 & 0xff , ( V_13 >> 8 ) & 0xff , ( V_13 >> 16 ) & 0xff } ;
return F_1 ( V_2 , V_3 , V_18 , 3 ) ;
}
static int F_16 ( struct V_1 * V_2 , const T_1 V_3 , T_3 V_13 )
{
T_2 V_18 [ 4 ] = {
V_13 & 0xff ,
( V_13 >> 8 ) & 0xff ,
( V_13 >> 16 ) & 0xff ,
( V_13 >> 24 ) & 0xff
} ;
return F_1 ( V_2 , V_3 , V_18 , 4 ) ;
}
static int F_17 ( struct V_1 * V_2 , const T_1 V_3 ,
T_2 V_13 , T_2 V_19 )
{
if ( V_19 != 0xff ) {
T_2 V_20 ;
int V_6 = F_8 ( V_2 , V_3 , & V_20 ) ;
if ( V_6 < 0 )
return V_6 ;
V_13 &= V_19 ;
V_20 &= ~ V_19 ;
V_13 |= V_20 ;
}
return F_12 ( V_2 , V_3 , V_13 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_21 * V_22 ,
int V_5 )
{
int V_23 ;
int V_6 ;
for ( V_23 = 0 ; V_23 < V_5 ; V_23 ++ ) {
V_6 = F_12 ( V_2 , V_22 [ V_23 ] . V_3 , V_22 [ V_23 ] . V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_19 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
V_27 -> V_28 = 1000 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_3 V_29 = V_2 -> V_14 . V_29 ;
T_2 V_30 = 1 ;
T_2 V_31 = 1 ;
T_2 V_32 = 56 ;
T_2 V_33 = 8 ;
T_2 V_34 = 12 ;
T_2 V_18 [ 4 ] ;
switch ( V_29 ) {
case 16000000u :
V_32 = 56 ;
break;
case 24000000u :
V_30 = 2 ;
V_31 = 4 ;
V_32 = 19 ;
break;
default:
if ( V_29 > 16000000u )
V_30 = 2 ;
if ( 1624000000u * V_30 > V_29 * 2u * 63u )
V_31 = 4 ;
V_32 = 1624000000u * V_30 / ( V_29 * 2u * V_31 ) ;
break;
}
V_2 -> V_35 = V_29 / V_30
* 2u * V_32 * V_31 ;
V_2 -> V_36 = V_2 -> V_35 / ( V_33 * 4u ) ;
V_2 -> V_37 = V_2 -> V_35 / ( V_34 * 2u ) ;
V_18 [ 0 ] = V_34 ;
V_18 [ 1 ] = V_33 ;
V_18 [ 2 ] = ( V_32 & 0x3f ) | ( ( V_31 == 1 ) ? 0x40 : 0x00 ) | 0x80 ;
V_18 [ 3 ] = V_30 ;
return F_1 ( V_2 , 0x00a0 , V_18 , 4 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_34 )
{
V_2 -> V_37 = V_2 -> V_35 / ( V_34 * 2u ) ;
return F_12 ( V_2 , 0x00a0 , V_34 ) ;
}
static T_3 F_22 ( struct V_1 * V_2 )
{
return V_2 -> V_36 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_6 = - V_38 ;
T_2 V_13 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 3 ; ++ V_23 ) {
F_8 ( V_2 , 0x0054 , & V_13 ) ;
if ( V_13 == 0x01 )
return 0 ;
F_24 ( 1000 , 50000 ) ;
}
F_4 ( & V_2 -> V_10 -> V_11 , L_6 ,
V_39 ) ;
return V_6 ;
}
static int F_25 ( struct V_1 * V_2 ,
const T_2 * V_40 , T_3 V_41 , T_3 * V_42 , T_3 V_43 )
{
int V_6 ;
T_2 V_44 [ 4 ] = { 0x00 , 0x00 , 0x00 , 0xc0 } ;
T_2 V_45 ;
T_3 V_46 = 0 ;
T_3 V_47 = V_42 ? * V_42 : 0 ;
if ( V_41 < 4 )
return - V_38 ;
if ( V_41 % 4 != 0 )
return - V_38 ;
F_26 (
L_7 ,
V_41 , V_47 , V_43 ) ;
while ( V_47 + 12 <= V_41 && V_46 < V_43 ) {
F_26 (
L_8 ,
V_41 , V_47 , V_46 , V_43 ) ;
V_45 = V_40 [ V_47 ] ;
if ( V_45 < 1 || V_40 [ V_47 + 1 ] ||
V_40 [ V_47 + 2 ] || V_40 [ V_47 + 3 ] ) {
F_27 ( & V_2 -> V_10 -> V_11 ,
L_9 ,
V_39 , 4 , V_40 ) ;
return - V_38 ;
}
if ( V_47 + 8 + V_45 * 4 > V_41 ) {
F_27 ( & V_2 -> V_10 -> V_11 ,
L_10 ,
V_39 , V_41 , V_45 ) ;
return - V_38 ;
}
V_44 [ 0 ] = V_45 - 1 ;
V_6 = F_1 ( V_2 , 0x0364 , V_44 , 4 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_1 ( V_2 , 0x0368 , V_40 + V_47 + 4 , 4 ) ;
if ( V_6 < 0 )
goto error;
V_47 += 8 ;
while ( V_45 > 0 ) {
V_6 = F_1 ( V_2 , 0x36c , V_40 + V_47 , 4 ) ;
if ( V_6 < 0 )
goto error;
V_45 -- ;
V_47 += 4 ;
}
V_46 ++ ;
}
F_26 (
L_11 ,
V_41 , V_47 , V_46 , V_43 ) ;
if ( V_42 )
* V_42 = V_47 ;
F_26 ( L_12 ,
V_47 ) ;
return 0 ;
error:
return V_6 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_2 V_13 [ 3 ] ;
T_1 V_48 ;
int V_6 ;
const struct V_49 * V_50 = NULL ;
T_2 * V_51 ;
const T_2 * V_40 ;
T_3 V_41 ;
T_3 V_47 ;
T_2 V_52 ;
T_2 V_43 ;
T_1 V_53 ;
switch ( V_2 -> V_54 ) {
case 0x03 :
V_51 = V_55 ;
break;
default:
F_29 ( & V_2 -> V_10 -> V_11 , L_13 ,
V_39 , V_2 -> V_54 ) ;
return 0 ;
}
V_6 = F_30 ( & V_50 , V_51 , & V_2 -> V_10 -> V_11 ) ;
if ( V_6 ) {
F_27 ( & V_2 -> V_10 -> V_11 , L_14 ,
V_39 , V_51 ) ;
goto error;
}
V_40 = V_50 -> V_40 ;
V_41 = V_50 -> V_56 ;
F_29 ( & V_2 -> V_10 -> V_11 , L_15 ,
V_39 , V_51 , V_41 ) ;
if ( V_41 % 4 != 0 ) {
F_27 ( & V_2 -> V_10 -> V_11 , L_16 ,
V_39 ) ;
V_6 = - V_38 ;
goto error;
}
if ( V_41 < 8 ) {
F_27 ( & V_2 -> V_10 -> V_11 , L_17 ,
V_39 ) ;
V_6 = - V_38 ;
goto error;
}
if ( V_40 [ 0 ] != 1 || V_40 [ 1 ] != 0 ) {
F_27 ( & V_2 -> V_10 -> V_11 , L_18 ,
V_39 ) ;
V_6 = - V_38 ;
goto error;
}
V_52 = V_40 [ 2 ] ;
V_43 = V_40 [ 4 ] ;
V_53 = V_40 [ 7 ] << 8 | V_40 [ 6 ] ;
V_6 = F_12 ( V_2 , 0x0341 , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x00c0 , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x0341 , V_13 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x035c , V_13 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x035c , V_13 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x035c , 0x02 ) ;
if ( V_6 < 0 )
goto error;
V_47 = 8 ;
F_29 ( & V_2 -> V_10 -> V_11 , L_19 ,
V_39 , V_52 , V_43 , V_53 ) ;
V_6 = F_25 ( V_2 , V_40 , V_41 , & V_47 , 1 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x0344 , V_52 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x0379 , 0x01 ) ;
if ( V_6 )
goto error;
V_6 = F_25 ( V_2 , V_40 , V_41 ,
& V_47 , V_43 ) ;
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_10 -> V_11 ,
L_20 ,
V_39 ) ;
goto error;
}
V_6 = F_11 ( V_2 , 0x037a , & V_48 ) ;
if ( V_6 )
goto error;
if ( V_48 != V_53 ) {
F_4 ( & V_2 -> V_10 -> V_11 ,
L_21 ,
V_39 , V_48 , V_53 ) ;
V_6 = - V_38 ;
goto error;
}
V_6 = F_25 ( V_2 , V_40 , V_41 , & V_47 , 5 ) ;
if ( V_6 )
goto error;
if ( V_41 != V_47 ) {
F_4 ( & V_2 -> V_10 -> V_11 ,
L_22 ,
V_39 , V_41 , V_47 ) ;
V_6 = - V_38 ;
goto error;
}
V_6 = F_17 ( V_2 , 0x0341 , 0x02 , 0x02 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_17 ( V_2 , 0x035c , 0x01 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
F_29 ( & V_2 -> V_10 -> V_11 , L_23 , V_39 ) ;
V_6 = 0 ;
V_2 -> V_57 = true ;
error:
if ( V_50 ) {
F_31 ( V_50 ) ;
V_50 = NULL ;
}
return V_6 ;
}
static int F_32 ( struct V_24 * V_25 )
{
int V_6 = 0 ;
struct V_1 * V_2 = V_25 -> V_58 ;
T_2 V_13 ;
T_2 V_52 = 0x00 ;
F_33 ( L_24 , V_12 ) ;
V_6 = F_12 ( V_2 , 0x0000 , V_2 -> V_14 . V_59 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x0104 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x0000 , & V_13 ) ;
if ( V_6 < 0 )
goto error;
if ( V_13 != V_2 -> V_14 . V_59 ) {
F_4 ( & V_2 -> V_10 -> V_11 , L_25 ,
V_39 ) ;
return - V_38 ;
}
V_6 = F_12 ( V_2 , 0x018b , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x0190 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x0170 , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x0171 , 0x07 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x0646 , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x0641 , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_20 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x0050 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x0096 , 0x01 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_23 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x0050 , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_14 ( V_2 , 0x0470 , 0x7530 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x0344 , & V_52 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_12 ( V_2 , 0x00cb , 0x00 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_16 ( V_2 , 0x0348 , 0xf4000000 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_2 , 0x0341 , & V_13 ) ;
if ( V_6 < 0 )
goto error;
if ( V_52 == 0x00 ) {
V_6 = F_28 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
}
V_6 = F_12 ( V_2 , 0x04e4 , 0x20 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_14 ( V_2 , 0x04ef , 0x00fe ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_15 ( V_2 , 0x04f4 , 0x555555 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_2 , 0x04e5 , 0x01 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
error:
return V_6 ;
}
static int F_34 ( struct V_24 * V_25 )
{
int V_6 ;
struct V_1 * V_2 = V_25 -> V_58 ;
V_6 = F_12 ( V_2 , 0x0104 , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_2 , 0x0000 , V_60 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_35 ( struct V_24 * V_25 , enum V_61 * V_62 )
{
int V_6 ;
T_2 V_63 = 0 ;
struct V_1 * V_2 = V_25 -> V_58 ;
if ( ! V_2 -> V_64 )
return - V_38 ;
V_6 = F_8 ( V_2 , 0x4e0 , & V_63 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_62 = 0 ;
if ( V_63 & 0x01 ) {
* V_62 |= V_65 ;
* V_62 |= V_66 ;
* V_62 |= V_67 ;
* V_62 |= V_68 ;
* V_62 |= V_69 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , T_3 V_70 )
{
T_4 V_71 ;
T_3 V_72 ;
if ( ! V_70 )
return - V_38 ;
V_71 = F_22 ( V_2 ) ;
V_71 <<= 23 ;
F_37 ( V_71 , V_70 ) ;
V_72 = V_71 & 0x3fffffff ;
F_33 ( L_26 , V_12 , V_72 ) ;
return F_16 ( V_2 , 0x00e4 , V_72 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = & V_2 -> V_25 ;
T_4 V_73 ;
T_5 V_72 = 0 ;
T_3 V_74 = F_22 ( V_2 ) ;
T_3 IF = 0 ;
if ( ! V_25 -> V_75 . V_76 . V_77 ) {
F_4 ( & V_2 -> V_10 -> V_11 ,
L_27 ,
V_39 ) ;
return - V_38 ;
}
if ( ! V_74 )
return - V_38 ;
V_25 -> V_75 . V_76 . V_77 ( V_25 , & IF ) ;
V_73 = IF ;
V_73 <<= 29 ;
F_37 ( V_73 , V_74 ) ;
V_72 = ( T_5 ) V_73 ;
if ( V_2 -> V_14 . V_78 )
V_72 = - V_72 ;
V_72 = V_72 & 0x1fffffff ;
return F_16 ( V_2 , 0x00e8 , V_72 ) ;
}
static int F_39 ( struct V_24 * V_25 )
{
int V_6 ;
struct V_79 * V_80 = & V_25 -> V_81 ;
struct V_1 * V_2 = V_25 -> V_58 ;
T_3 V_70 = 0 ;
T_1 V_82 ;
T_3 V_83 = V_80 -> V_84 ;
F_33 ( L_24 , V_12 ) ;
if ( ! V_2 -> V_64 )
return - V_38 ;
if ( V_83 == 0 )
return - V_38 ;
V_70 = V_83 * 8 / 7 ;
V_82 = V_83 / 10000 ;
V_6 = F_21 ( V_2 , 12 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_14 ( V_2 , 0x0308 , V_82 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_36 ( V_2 , V_70 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_18 ( V_2 , V_85 , F_40 ( V_85 ) ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_41 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_58 ;
int V_6 ;
struct V_79 * V_80 = & V_25 -> V_81 ;
const T_3 V_70 = V_80 -> V_86 ;
const T_3 V_83 = V_80 -> V_84 ;
if ( ! V_2 -> V_87 )
return - V_38 ;
if ( V_70 == 0 )
return - V_38 ;
V_6 = F_21 ( V_2 , 14 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_36 ( V_2 , V_70 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_16 ( V_2 , 0x00c4 , V_83 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_18 ( V_2 , V_88 , F_40 ( V_88 ) ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_42 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_58 ;
struct V_79 * V_80 = & V_25 -> V_81 ;
T_3 V_89 = V_80 -> V_90 ;
int V_6 ;
T_2 V_13 [ 3 ] ;
V_6 = F_38 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_89 ) {
case V_91 :
V_6 = F_39 ( V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
break;
case V_92 :
V_6 = F_41 ( V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
break;
default:
return - V_38 ;
}
V_6 = F_16 ( V_2 , 0x0348 , 0xf4000000 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_25 -> V_75 . V_76 . V_93 )
V_25 -> V_75 . V_76 . V_93 ( V_25 ) ;
V_6 = F_38 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_2 , 0x0341 , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_2 , 0x0341 , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_2 , 0x00c0 , 0x00 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_16 ( V_2 , 0x0384 , 0x00000000 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_18 ( V_2 , V_94 ,
F_40 ( V_94 ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_2 , 0x02e0 , 0x01 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_2 , 0x0341 , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_43 ( struct V_95 * V_10 ,
const struct V_96 * V_97 )
{
struct V_1 * V_2 = NULL ;
struct V_98 * V_99 = V_10 -> V_11 . V_100 ;
int V_101 ;
int V_6 = 0 ;
T_2 V_13 ;
char V_102 ;
const char * V_103 ;
static const struct V_104 V_104 = {
. V_105 = 16 ,
. V_106 = 8 ,
. V_107 = 0x08ff ,
} ;
V_2 = F_44 ( sizeof( struct V_1 ) , V_108 ) ;
if ( V_2 == NULL ) {
V_6 = - V_109 ;
goto error;
}
V_2 -> V_9 = F_45 ( V_10 , & V_104 ) ;
if ( F_46 ( V_2 -> V_9 ) ) {
V_6 = F_47 ( V_2 -> V_9 ) ;
goto error;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_14 . V_15 = V_10 -> V_110 ;
V_2 -> V_14 . V_59 = V_99 -> V_59 ;
V_2 -> V_14 . V_29 = V_99 -> V_29 ;
V_2 -> V_14 . V_78 = V_99 -> V_78 ;
if ( V_2 -> V_14 . V_29 < 4000000
|| V_2 -> V_14 . V_29 > 27000000 ) {
F_4 ( & V_2 -> V_10 -> V_11 , L_28 ,
V_39 , V_2 -> V_14 . V_29 ) ;
V_6 = - V_38 ;
goto error;
}
memcpy ( & V_2 -> V_25 . V_75 , & V_111 ,
sizeof( struct V_112 ) ) ;
V_2 -> V_25 . V_75 . V_113 = NULL ;
V_2 -> V_25 . V_58 = V_2 ;
F_48 ( V_10 , V_2 ) ;
V_6 = F_12 ( V_2 , 0x0000 , V_2 -> V_14 . V_59 ) ;
if ( V_6 < 0 )
goto V_114;
V_6 = F_8 ( V_2 , 0x0000 , & V_13 ) ;
if ( V_6 < 0 )
goto V_114;
if ( V_13 != V_2 -> V_14 . V_59 )
goto V_114;
V_6 = F_8 ( V_2 , 0x0023 , & V_2 -> V_54 ) ;
if ( V_6 < 0 )
goto V_114;
V_6 = F_8 ( V_2 , 0x0118 , & V_2 -> V_115 ) ;
if ( V_6 < 0 )
goto V_114;
V_6 = F_12 ( V_2 , 0x0000 , V_60 ) ;
if ( V_6 < 0 )
goto V_114;
if ( V_2 -> V_54 < 26 )
V_102 = 'A' + V_2 -> V_54 ;
else
V_102 = '?' ;
switch ( V_2 -> V_115 ) {
case 0x06 :
V_103 = L_29 ;
V_2 -> V_64 = true ;
break;
case 0x07 :
V_103 = L_30 ;
V_2 -> V_64 = true ;
V_2 -> V_87 = true ;
break;
default:
F_4 ( & V_2 -> V_10 -> V_11 , L_31 ,
V_39 , V_2 -> V_115 , V_2 -> V_54 ) ;
goto V_114;
}
F_29 ( & V_2 -> V_10 -> V_11 ,
L_32 ,
V_39 , V_103 , V_102 , V_2 -> V_115 ,
V_2 -> V_54 ) ;
F_49 ( V_2 -> V_25 . V_75 . V_116 . V_117 , V_103 ,
sizeof( V_2 -> V_25 . V_75 . V_116 . V_117 ) ) ;
V_101 = 0 ;
if ( V_2 -> V_64 ) {
V_2 -> V_25 . V_75 . V_89 [ V_101 ++ ] = V_91 ;
F_49 ( V_2 -> V_25 . V_75 . V_116 . V_117 , L_33 ,
sizeof( V_2 -> V_25 . V_75 . V_116 . V_117 ) ) ;
}
if ( V_2 -> V_87 ) {
V_2 -> V_25 . V_75 . V_89 [ V_101 ++ ] = V_92 ;
F_49 ( V_2 -> V_25 . V_75 . V_116 . V_117 , L_34 ,
sizeof( V_2 -> V_25 . V_75 . V_116 . V_117 ) ) ;
}
* V_99 -> V_25 = & V_2 -> V_25 ;
return 0 ;
V_114:
V_6 = - V_118 ;
error:
F_50 ( V_2 ) ;
F_51 ( & V_10 -> V_11 , L_35 , V_6 ) ;
return V_6 ;
}
static int F_52 ( struct V_95 * V_10 )
{
struct V_1 * V_2 = F_53 ( V_10 ) ;
F_51 ( & V_10 -> V_11 , L_36 ) ;
F_50 ( V_2 ) ;
return 0 ;
}
