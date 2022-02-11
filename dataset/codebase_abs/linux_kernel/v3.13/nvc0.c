static T_1
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
T_1 V_7 = F_2 ( V_2 , V_3 ) ;
if ( ! ( V_7 & 0x00000100 ) )
return V_5 -> V_8 ( V_5 , V_9 ) ;
return V_5 -> V_8 ( V_5 , V_10 ) ;
}
static T_1
F_3 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
T_1 V_12 = F_2 ( V_2 , V_11 + 0x00 ) ;
T_1 V_13 = F_2 ( V_2 , V_11 + 0x04 ) ;
T_1 V_14 = ( V_13 & 0x003f0000 ) >> 16 ;
T_1 V_15 = ( V_13 & 0x0000ff00 ) >> 8 ;
T_1 V_16 = ( V_13 & 0x000000ff ) >> 0 ;
T_1 V_17 ;
if ( ! ( V_12 & 0x00000001 ) )
return 0 ;
switch ( V_11 ) {
case 0x00e800 :
case 0x00e820 :
V_17 = F_4 ( V_2 ) -> V_18 ;
V_14 = 1 ;
break;
case 0x132000 :
V_17 = V_5 -> V_8 ( V_5 , V_19 ) ;
break;
case 0x132020 :
V_17 = V_5 -> V_8 ( V_5 , V_20 ) ;
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
T_1 V_7 = F_2 ( V_2 , V_3 + ( V_21 * 4 ) ) ;
T_1 V_23 = F_2 ( V_2 , V_22 + ( V_21 * 4 ) ) ;
switch ( V_7 & 0x00000003 ) {
case 0 :
if ( ( V_7 & 0x00030000 ) != 0x00030000 )
return F_4 ( V_2 ) -> V_18 ;
return 108000 ;
case 2 :
return 100000 ;
case 3 :
if ( V_23 & 0x80000000 ) {
T_1 V_17 = F_1 ( V_2 , V_3 + ( V_21 * 4 ) ) ;
T_1 V_24 = ( V_23 & 0x0000003f ) + 2 ;
return ( V_17 * 2 ) / V_24 ;
}
return F_1 ( V_2 , V_3 + ( V_21 * 4 ) ) ;
default:
return 0 ;
}
}
static T_1
F_6 ( struct V_1 * V_2 , int V_5 )
{
T_1 V_23 = F_2 ( V_2 , 0x137250 + ( V_5 * 4 ) ) ;
T_1 V_25 = F_2 ( V_2 , 0x137100 ) ;
T_1 V_17 , V_24 ;
if ( V_25 & ( 1 << V_5 ) ) {
if ( V_5 < 7 )
V_17 = F_3 ( V_2 , 0x137000 + ( V_5 * 0x20 ) ) ;
else
V_17 = F_3 ( V_2 , 0x1370e0 ) ;
V_24 = ( ( V_23 & 0x00003f00 ) >> 8 ) + 2 ;
} else {
V_17 = F_5 ( V_2 , V_5 , 0x137160 , 0x1371d0 ) ;
V_24 = ( ( V_23 & 0x0000003f ) >> 0 ) + 2 ;
}
if ( V_23 & 0x80000000 )
return ( V_17 * 2 ) / V_24 ;
return V_17 ;
}
static int
F_7 ( struct V_4 * V_5 , enum V_26 V_27 )
{
struct V_28 * V_29 = F_4 ( V_5 ) ;
struct V_1 * V_2 = ( void * ) V_5 ;
switch ( V_27 ) {
case V_30 :
return V_29 -> V_18 ;
case V_31 :
return 100000 ;
case V_9 :
return F_3 ( V_2 , 0x00e800 ) ;
case V_10 :
return F_3 ( V_2 , 0x00e820 ) ;
case V_20 :
return F_5 ( V_2 , 0 , 0x137320 , 0x137330 ) ;
case V_19 :
return F_3 ( V_2 , 0x132020 ) ;
case V_32 :
return F_3 ( V_2 , 0x132000 ) ;
case V_33 :
return F_5 ( V_2 , 0 , 0x137300 , 0x137310 ) ;
case V_34 :
if ( F_2 ( V_2 , 0x1373f0 ) & 0x00000002 )
return V_5 -> V_8 ( V_5 , V_32 ) ;
return V_5 -> V_8 ( V_5 , V_33 ) ;
case V_35 :
return F_6 ( V_2 , 0x00 ) ;
case V_36 :
return F_6 ( V_2 , 0x01 ) ;
case V_37 :
return F_6 ( V_2 , 0x02 ) ;
case V_38 :
return F_6 ( V_2 , 0x07 ) ;
case V_39 :
return F_6 ( V_2 , 0x08 ) ;
case V_40 :
return F_6 ( V_2 , 0x09 ) ;
case V_41 :
return F_6 ( V_2 , 0x0c ) ;
case V_42 :
return F_6 ( V_2 , 0x0e ) ;
default:
F_8 ( V_5 , L_1 , V_27 ) ;
return - V_43 ;
}
}
static T_1
F_9 ( struct V_1 * V_2 , int V_5 , T_1 V_44 , T_1 V_45 , T_1 * V_46 )
{
T_1 div = F_10 ( ( V_44 * 2 ) / V_45 , ( T_1 ) 65 ) ;
if ( div < 2 )
div = 2 ;
* V_46 = div - 2 ;
return ( V_44 * 2 ) / div ;
}
static T_1
F_11 ( struct V_1 * V_2 , int V_5 , T_1 V_45 , T_1 * V_3 , T_1 * V_46 )
{
T_1 V_17 ;
* V_46 = 0x00000000 ;
switch ( V_45 ) {
case 27000 :
case 108000 :
* V_3 = 0x00000000 ;
if ( V_45 == 108000 )
* V_3 |= 0x00030000 ;
return V_45 ;
case 100000 :
* V_3 = 0x00000002 ;
return V_45 ;
default:
* V_3 = 0x00000003 ;
break;
}
V_17 = F_1 ( V_2 , 0x137160 + ( V_5 * 4 ) ) ;
if ( V_5 < 7 )
V_17 = F_9 ( V_2 , V_5 , V_17 , V_45 , V_46 ) ;
return V_17 ;
}
static T_1
F_12 ( struct V_1 * V_2 , int V_5 , T_1 V_45 , T_1 * V_13 )
{
struct V_47 * V_48 = V_47 ( V_2 ) ;
struct V_49 V_50 ;
int V_15 , V_16 , V_14 , V_51 ;
V_51 = F_13 ( V_48 , 0x137000 + ( V_5 * 0x20 ) , & V_50 ) ;
if ( V_51 )
return 0 ;
V_50 . V_52 = F_5 ( V_2 , V_5 , 0x137120 , 0x137140 ) ;
if ( ! V_50 . V_52 )
return 0 ;
V_51 = F_14 ( F_15 ( V_2 ) , & V_50 , V_45 , & V_15 , NULL , & V_16 , & V_14 ) ;
if ( V_51 <= 0 )
return 0 ;
* V_13 = ( V_14 << 16 ) | ( V_15 << 8 ) | V_16 ;
return V_51 ;
}
static int
F_16 ( struct V_1 * V_2 ,
struct V_53 * V_54 , int V_5 , int V_55 )
{
struct V_56 * V_57 = & V_2 -> V_58 [ V_5 ] ;
T_1 V_45 = V_54 -> V_59 [ V_55 ] ;
T_1 V_60 , V_61 , V_62 , V_63 = 0 ;
T_1 V_64 , V_65 = 0 ;
if ( ! V_45 )
return 0 ;
V_64 = F_11 ( V_2 , V_5 , V_45 , & V_60 , & V_61 ) ;
V_64 = F_9 ( V_2 , V_5 , V_64 , V_45 , & V_62 ) ;
if ( V_64 != V_45 && ( 0x00004387 & ( 1 << V_5 ) ) ) {
if ( V_5 <= 7 )
V_65 = F_12 ( V_2 , V_5 , V_45 , & V_57 -> V_13 ) ;
else
V_65 = V_54 -> V_59 [ V_38 ] ;
V_65 = F_9 ( V_2 , V_5 , V_65 , V_45 , & V_63 ) ;
}
if ( abs ( ( int ) V_45 - V_64 ) <= abs ( ( int ) V_45 - V_65 ) ) {
V_57 -> V_3 = V_60 ;
if ( V_61 ) {
V_57 -> V_46 |= 0x80000000 ;
V_57 -> V_46 |= V_61 << 8 ;
V_57 -> V_46 |= V_61 ;
}
if ( V_62 ) {
V_57 -> V_66 |= 0x80000000 ;
V_57 -> V_66 |= V_62 ;
}
V_57 -> V_25 = V_57 -> V_13 = 0 ;
V_57 -> V_45 = V_64 ;
} else {
if ( V_63 ) {
V_57 -> V_66 |= 0x80000000 ;
V_57 -> V_66 |= V_63 << 8 ;
}
V_57 -> V_25 = ( 1 << V_5 ) ;
V_57 -> V_45 = V_65 ;
}
return 0 ;
}
static int
F_17 ( struct V_4 * V_5 , struct V_53 * V_54 )
{
struct V_1 * V_2 = ( void * ) V_5 ;
int V_51 ;
if ( ( V_51 = F_16 ( V_2 , V_54 , 0x00 , V_35 ) ) ||
( V_51 = F_16 ( V_2 , V_54 , 0x01 , V_36 ) ) ||
( V_51 = F_16 ( V_2 , V_54 , 0x02 , V_37 ) ) ||
( V_51 = F_16 ( V_2 , V_54 , 0x07 , V_38 ) ) ||
( V_51 = F_16 ( V_2 , V_54 , 0x08 , V_39 ) ) ||
( V_51 = F_16 ( V_2 , V_54 , 0x09 , V_40 ) ) ||
( V_51 = F_16 ( V_2 , V_54 , 0x0c , V_41 ) ) ||
( V_51 = F_16 ( V_2 , V_54 , 0x0e , V_42 ) ) )
return V_51 ;
return 0 ;
}
static void
F_18 ( struct V_1 * V_2 , int V_5 )
{
struct V_56 * V_57 = & V_2 -> V_58 [ V_5 ] ;
if ( V_5 < 7 && ! V_57 -> V_25 ) {
F_19 ( V_2 , 0x1371d0 + ( V_5 * 0x04 ) , 0x80003f3f , V_57 -> V_46 ) ;
F_20 ( V_2 , 0x137160 + ( V_5 * 0x04 ) , V_57 -> V_3 ) ;
}
}
static void
F_21 ( struct V_1 * V_2 , int V_5 )
{
F_19 ( V_2 , 0x137100 , ( 1 << V_5 ) , 0x00000000 ) ;
F_22 ( V_2 , 0x137100 , ( 1 << V_5 ) , 0x00000000 ) ;
}
static void
F_23 ( struct V_1 * V_2 , int V_5 )
{
struct V_56 * V_57 = & V_2 -> V_58 [ V_5 ] ;
const T_1 V_67 = 0x137000 + ( V_5 * 0x20 ) ;
if ( V_5 <= 7 ) {
F_19 ( V_2 , V_67 + 0x00 , 0x00000004 , 0x00000000 ) ;
F_19 ( V_2 , V_67 + 0x00 , 0x00000001 , 0x00000000 ) ;
if ( V_57 -> V_13 ) {
F_20 ( V_2 , V_67 + 0x04 , V_57 -> V_13 ) ;
F_19 ( V_2 , V_67 + 0x00 , 0x00000001 , 0x00000001 ) ;
F_22 ( V_2 , V_67 + 0x00 , 0x00020000 , 0x00020000 ) ;
F_19 ( V_2 , V_67 + 0x00 , 0x00020004 , 0x00000004 ) ;
}
}
}
static void
F_24 ( struct V_1 * V_2 , int V_5 )
{
struct V_56 * V_57 = & V_2 -> V_58 [ V_5 ] ;
if ( V_57 -> V_25 ) {
F_19 ( V_2 , 0x137100 , ( 1 << V_5 ) , V_57 -> V_25 ) ;
F_22 ( V_2 , 0x137100 , ( 1 << V_5 ) , V_57 -> V_25 ) ;
}
}
static void
F_25 ( struct V_1 * V_2 , int V_5 )
{
struct V_56 * V_57 = & V_2 -> V_58 [ V_5 ] ;
F_19 ( V_2 , 0x137250 + ( V_5 * 0x04 ) , 0x00003f3f , V_57 -> V_66 ) ;
}
static int
F_26 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = ( void * ) V_5 ;
struct {
void (* F_27)( struct V_1 * , int );
} V_68 [] = {
{ F_18 } ,
{ F_21 } ,
{ F_23 } ,
{ F_24 } ,
{ F_25 } ,
} ;
int V_69 , V_70 ;
for ( V_69 = 0 ; V_69 < F_28 ( V_68 ) ; V_69 ++ ) {
for ( V_70 = 0 ; V_70 < F_28 ( V_2 -> V_58 ) ; V_70 ++ ) {
if ( ! V_2 -> V_58 [ V_70 ] . V_45 )
continue;
V_68 [ V_69 ] . F_27 ( V_2 , V_70 ) ;
}
}
return 0 ;
}
static void
F_29 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = ( void * ) V_5 ;
memset ( V_2 -> V_58 , 0x00 , sizeof( V_2 -> V_58 ) ) ;
}
static int
F_30 ( struct V_71 * V_72 , struct V_71 * V_73 ,
struct V_74 * V_75 , void * V_76 , T_1 V_77 ,
struct V_71 * * V_78 )
{
struct V_1 * V_2 ;
int V_51 ;
V_51 = F_31 ( V_72 , V_73 , V_75 , V_79 , & V_2 ) ;
* V_78 = F_32 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_6 . V_8 = F_7 ;
V_2 -> V_6 . V_80 = F_17 ;
V_2 -> V_6 . V_81 = F_26 ;
V_2 -> V_6 . V_82 = F_29 ;
return 0 ;
}
