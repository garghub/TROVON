static T_1
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 . V_5 ;
T_1 V_8 = F_2 ( V_5 , V_3 ) ;
if ( ! ( V_8 & 0x00000100 ) )
return F_3 ( & V_2 -> V_6 , V_9 ) ;
return F_3 ( & V_2 -> V_6 , V_10 ) ;
}
static T_1
F_4 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 . V_5 ;
T_1 V_12 = F_2 ( V_5 , V_11 + 0x00 ) ;
T_1 V_13 = F_2 ( V_5 , V_11 + 0x04 ) ;
T_1 V_14 = ( V_13 & 0x003f0000 ) >> 16 ;
T_1 V_15 = ( V_13 & 0x0000ff00 ) >> 8 ;
T_1 V_16 = ( V_13 & 0x000000ff ) >> 0 ;
T_1 V_17 ;
if ( ! ( V_12 & 0x00000001 ) )
return 0 ;
switch ( V_11 ) {
case 0x00e800 :
case 0x00e820 :
V_17 = V_5 -> V_18 ;
V_14 = 1 ;
break;
case 0x132000 :
V_17 = F_3 ( & V_2 -> V_6 , V_19 ) ;
break;
case 0x132020 :
V_17 = F_3 ( & V_2 -> V_6 , V_20 ) ;
break;
case 0x137000 :
case 0x137020 :
case 0x137040 :
case 0x1370e0 :
V_17 = F_5 ( V_2 , ( V_11 & 0xff ) / 0x20 , 0x137120 , 0x137140 ) ;
break;
default:
return 0 ;
}
return V_17 * V_15 / V_16 / V_14 ;
}
static T_1
F_5 ( struct V_1 * V_2 , int V_21 , T_1 V_3 , T_1 V_22 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 . V_5 ;
T_1 V_8 = F_2 ( V_5 , V_3 + ( V_21 * 4 ) ) ;
T_1 V_17 , V_23 , V_24 = 2 ;
switch ( V_8 & 0x00000003 ) {
case 0 :
if ( ( V_8 & 0x00030000 ) != 0x00030000 )
return V_5 -> V_18 ;
return 108000 ;
case 2 :
return 100000 ;
case 3 :
V_17 = F_1 ( V_2 , V_3 + ( V_21 * 4 ) ) ;
if ( V_21 <= 2 ) {
V_23 = F_2 ( V_5 , V_22 + ( V_21 * 4 ) ) ;
if ( V_23 & 0x80000000 ) {
if ( V_8 & 0x100 )
V_23 >>= 8 ;
V_24 = ( V_23 & 0x3f ) + 2 ;
}
}
return ( V_17 * 2 ) / V_24 ;
default:
return 0 ;
}
}
static T_1
F_6 ( struct V_1 * V_2 , int V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 . V_5 ;
T_1 V_23 = F_2 ( V_5 , 0x137250 + ( V_25 * 4 ) ) ;
T_1 V_26 = F_2 ( V_5 , 0x137100 ) ;
T_1 V_17 , V_24 ;
if ( V_26 & ( 1 << V_25 ) ) {
if ( V_25 < 7 )
V_17 = F_4 ( V_2 , 0x137000 + ( V_25 * 0x20 ) ) ;
else
V_17 = F_4 ( V_2 , 0x1370e0 ) ;
V_24 = ( ( V_23 & 0x00003f00 ) >> 8 ) + 2 ;
} else {
V_17 = F_5 ( V_2 , V_25 , 0x137160 , 0x1371d0 ) ;
V_24 = ( ( V_23 & 0x0000003f ) >> 0 ) + 2 ;
}
if ( V_23 & 0x80000000 )
return ( V_17 * 2 ) / V_24 ;
return V_17 ;
}
static int
F_7 ( struct V_27 * V_6 , enum V_28 V_29 )
{
struct V_1 * V_2 = V_1 ( V_6 ) ;
struct V_30 * V_7 = & V_2 -> V_6 . V_7 ;
struct V_4 * V_5 = V_7 -> V_5 ;
switch ( V_29 ) {
case V_31 :
return V_5 -> V_18 ;
case V_32 :
return 100000 ;
case V_9 :
return F_4 ( V_2 , 0x00e800 ) ;
case V_10 :
return F_4 ( V_2 , 0x00e820 ) ;
case V_20 :
return F_5 ( V_2 , 0 , 0x137320 , 0x137330 ) ;
case V_19 :
return F_4 ( V_2 , 0x132020 ) ;
case V_33 :
return F_4 ( V_2 , 0x132000 ) ;
case V_34 :
return F_5 ( V_2 , 0 , 0x137300 , 0x137310 ) ;
case V_35 :
if ( F_2 ( V_5 , 0x1373f0 ) & 0x00000002 )
return F_3 ( & V_2 -> V_6 , V_33 ) ;
return F_3 ( & V_2 -> V_6 , V_34 ) ;
case V_36 :
return F_6 ( V_2 , 0x00 ) ;
case V_37 :
return F_6 ( V_2 , 0x01 ) ;
case V_38 :
return F_6 ( V_2 , 0x02 ) ;
case V_39 :
return F_6 ( V_2 , 0x07 ) ;
case V_40 :
return F_6 ( V_2 , 0x08 ) ;
case V_41 :
return F_6 ( V_2 , 0x09 ) ;
case V_42 :
return F_6 ( V_2 , 0x0c ) ;
case V_43 :
return F_6 ( V_2 , 0x0e ) ;
default:
F_8 ( V_7 , L_1 , V_29 ) ;
return - V_44 ;
}
}
static T_1
F_9 ( struct V_1 * V_2 , int V_25 , T_1 V_45 , T_1 V_46 , T_1 * V_47 )
{
T_1 div = F_10 ( ( V_45 * 2 ) / V_46 , ( T_1 ) 65 ) ;
if ( div < 2 )
div = 2 ;
* V_47 = div - 2 ;
return ( V_45 * 2 ) / div ;
}
static T_1
F_11 ( struct V_1 * V_2 , int V_25 , T_1 V_46 , T_1 * V_3 , T_1 * V_47 )
{
T_1 V_17 ;
* V_47 = 0x00000000 ;
switch ( V_46 ) {
case 27000 :
case 108000 :
* V_3 = 0x00000000 ;
if ( V_46 == 108000 )
* V_3 |= 0x00030000 ;
return V_46 ;
case 100000 :
* V_3 = 0x00000002 ;
return V_46 ;
default:
* V_3 = 0x00000003 ;
break;
}
V_17 = F_1 ( V_2 , 0x137160 + ( V_25 * 4 ) ) ;
if ( V_25 < 7 )
V_17 = F_9 ( V_2 , V_25 , V_17 , V_46 , V_47 ) ;
return V_17 ;
}
static T_1
F_12 ( struct V_1 * V_2 , int V_25 , T_1 V_46 , T_1 * V_13 )
{
struct V_30 * V_7 = & V_2 -> V_6 . V_7 ;
struct V_48 * V_49 = V_7 -> V_5 -> V_49 ;
struct V_50 V_51 ;
int V_15 , V_16 , V_14 , V_52 ;
V_52 = F_13 ( V_49 , 0x137000 + ( V_25 * 0x20 ) , & V_51 ) ;
if ( V_52 )
return 0 ;
V_51 . V_53 = F_5 ( V_2 , V_25 , 0x137120 , 0x137140 ) ;
if ( ! V_51 . V_53 )
return 0 ;
V_52 = F_14 ( V_7 , & V_51 , V_46 , & V_15 , NULL , & V_16 , & V_14 ) ;
if ( V_52 <= 0 )
return 0 ;
* V_13 = ( V_14 << 16 ) | ( V_15 << 8 ) | V_16 ;
return V_52 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_54 * V_55 , int V_25 , int V_56 )
{
struct V_57 * V_58 = & V_2 -> V_59 [ V_25 ] ;
T_1 V_46 = V_55 -> V_60 [ V_56 ] ;
T_1 V_61 , V_62 , V_63 , V_64 = 0 ;
T_1 V_65 , V_66 = 0 ;
if ( ! V_46 )
return 0 ;
V_65 = F_11 ( V_2 , V_25 , V_46 , & V_61 , & V_62 ) ;
V_65 = F_9 ( V_2 , V_25 , V_65 , V_46 , & V_63 ) ;
if ( V_65 != V_46 && ( 0x00004387 & ( 1 << V_25 ) ) ) {
if ( V_25 <= 7 )
V_66 = F_12 ( V_2 , V_25 , V_46 , & V_58 -> V_13 ) ;
else
V_66 = V_55 -> V_60 [ V_39 ] ;
V_66 = F_9 ( V_2 , V_25 , V_66 , V_46 , & V_64 ) ;
}
if ( abs ( ( int ) V_46 - V_65 ) <= abs ( ( int ) V_46 - V_66 ) ) {
V_58 -> V_3 = V_61 ;
if ( V_62 ) {
V_58 -> V_47 |= 0x80000000 ;
V_58 -> V_47 |= V_62 << 8 ;
V_58 -> V_47 |= V_62 ;
}
if ( V_63 ) {
V_58 -> V_67 |= 0x80000000 ;
V_58 -> V_67 |= V_63 ;
}
V_58 -> V_26 = V_58 -> V_13 = 0 ;
V_58 -> V_46 = V_65 ;
} else {
if ( V_64 ) {
V_58 -> V_67 |= 0x80000000 ;
V_58 -> V_67 |= V_64 << 8 ;
}
V_58 -> V_26 = ( 1 << V_25 ) ;
V_58 -> V_46 = V_66 ;
}
return 0 ;
}
static int
F_16 ( struct V_27 * V_6 , struct V_54 * V_55 )
{
struct V_1 * V_2 = V_1 ( V_6 ) ;
int V_52 ;
if ( ( V_52 = F_15 ( V_2 , V_55 , 0x00 , V_36 ) ) ||
( V_52 = F_15 ( V_2 , V_55 , 0x01 , V_37 ) ) ||
( V_52 = F_15 ( V_2 , V_55 , 0x02 , V_38 ) ) ||
( V_52 = F_15 ( V_2 , V_55 , 0x07 , V_39 ) ) ||
( V_52 = F_15 ( V_2 , V_55 , 0x08 , V_40 ) ) ||
( V_52 = F_15 ( V_2 , V_55 , 0x09 , V_41 ) ) ||
( V_52 = F_15 ( V_2 , V_55 , 0x0c , V_42 ) ) ||
( V_52 = F_15 ( V_2 , V_55 , 0x0e , V_43 ) ) )
return V_52 ;
return 0 ;
}
static void
F_17 ( struct V_1 * V_2 , int V_25 )
{
struct V_57 * V_58 = & V_2 -> V_59 [ V_25 ] ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 . V_5 ;
if ( V_25 < 7 && ! V_58 -> V_26 ) {
F_18 ( V_5 , 0x1371d0 + ( V_25 * 0x04 ) , 0x80003f3f , V_58 -> V_47 ) ;
F_19 ( V_5 , 0x137160 + ( V_25 * 0x04 ) , V_58 -> V_3 ) ;
}
}
static void
F_20 ( struct V_1 * V_2 , int V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 . V_5 ;
F_18 ( V_5 , 0x137100 , ( 1 << V_25 ) , 0x00000000 ) ;
F_21 (device, 2000 ,
if (!(nvkm_rd32(device, 0x137100) & (1 << idx)))
break;
) ;
}
static void
F_22 ( struct V_1 * V_2 , int V_25 )
{
struct V_57 * V_58 = & V_2 -> V_59 [ V_25 ] ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 . V_5 ;
const T_1 V_68 = 0x137000 + ( V_25 * 0x20 ) ;
if ( V_25 <= 7 ) {
F_18 ( V_5 , V_68 + 0x00 , 0x00000004 , 0x00000000 ) ;
F_18 ( V_5 , V_68 + 0x00 , 0x00000001 , 0x00000000 ) ;
if ( V_58 -> V_13 ) {
F_19 ( V_5 , V_68 + 0x04 , V_58 -> V_13 ) ;
F_18 ( V_5 , V_68 + 0x00 , 0x00000001 , 0x00000001 ) ;
F_18 ( V_5 , V_68 + 0x00 , 0x00000010 , 0x00000000 ) ;
F_21 (device, 2000 ,
if (nvkm_rd32(device, addr + 0x00) & 0x00020000)
break;
) ;
F_18 ( V_5 , V_68 + 0x00 , 0x00000010 , 0x00000010 ) ;
F_18 ( V_5 , V_68 + 0x00 , 0x00000004 , 0x00000004 ) ;
}
}
}
static void
F_23 ( struct V_1 * V_2 , int V_25 )
{
struct V_57 * V_58 = & V_2 -> V_59 [ V_25 ] ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 . V_5 ;
if ( V_58 -> V_26 ) {
F_18 ( V_5 , 0x137100 , ( 1 << V_25 ) , V_58 -> V_26 ) ;
F_21 (device, 2000 ,
u32 tmp = nvkm_rd32(device, 0x137100) & (1 << idx);
if (tmp == info->ssel)
break;
) ;
}
}
static void
F_24 ( struct V_1 * V_2 , int V_25 )
{
struct V_57 * V_58 = & V_2 -> V_59 [ V_25 ] ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 . V_5 ;
F_18 ( V_5 , 0x137250 + ( V_25 * 0x04 ) , 0x00003f3f , V_58 -> V_67 ) ;
}
static int
F_25 ( struct V_27 * V_6 )
{
struct V_1 * V_2 = V_1 ( V_6 ) ;
struct {
void (* F_26)( struct V_1 * , int );
} V_69 [] = {
{ F_17 } ,
{ F_20 } ,
{ F_22 } ,
{ F_23 } ,
{ F_24 } ,
} ;
int V_70 , V_71 ;
for ( V_70 = 0 ; V_70 < F_27 ( V_69 ) ; V_70 ++ ) {
for ( V_71 = 0 ; V_71 < F_27 ( V_2 -> V_59 ) ; V_71 ++ ) {
if ( ! V_2 -> V_59 [ V_71 ] . V_46 )
continue;
V_69 [ V_70 ] . F_26 ( V_2 , V_71 ) ;
}
}
return 0 ;
}
static void
F_28 ( struct V_27 * V_6 )
{
struct V_1 * V_2 = V_1 ( V_6 ) ;
memset ( V_2 -> V_59 , 0x00 , sizeof( V_2 -> V_59 ) ) ;
}
int
F_29 ( struct V_4 * V_5 , int V_72 , struct V_27 * * V_73 )
{
struct V_1 * V_2 ;
if ( ! ( V_2 = F_30 ( sizeof( * V_2 ) , V_74 ) ) )
return - V_75 ;
* V_73 = & V_2 -> V_6 ;
return F_31 ( & V_1 , V_5 , V_72 , false , & V_2 -> V_6 ) ;
}
