static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_2 V_5 )
{
int V_6 ;
T_1 V_7 [] = { V_4 , V_5 >> 8 , V_5 & 0xff } ;
struct V_8 V_9 = { . V_3 = V_3 , . V_10 = 0 , . V_7 = V_7 , . V_11 = 3 } ;
V_6 = F_2 ( V_2 -> V_12 , & V_9 , 1 ) ;
if ( V_6 != 1 )
F_3 ( V_13 L_1
L_2 , V_14 , V_3 , V_4 , V_5 , V_6 ) ;
return ( V_6 != 1 ) ? - 1 : 0 ;
}
static T_2 F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_6 ;
T_1 V_15 [] = { V_4 } ;
T_1 V_16 [] = { 0 , 0 } ;
struct V_8 V_9 [] = {
{ . V_3 = V_3 , . V_10 = 0 , . V_7 = V_15 , . V_11 = 1 } ,
{ . V_3 = V_3 , . V_10 = V_17 , . V_7 = V_16 , . V_11 = 2 } } ;
V_6 = F_2 ( V_2 -> V_12 , V_9 , 2 ) ;
if ( V_6 != 2 )
F_3 ( V_13 L_3 ,
V_14 , V_6 ) ;
return ( V_16 [ 0 ] << 8 ) | V_16 [ 1 ] ;
}
static int F_5 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_6 ( L_4 , V_14 ) ;
F_1 ( V_2 , V_21 , 0xf7 , 0 ) ;
F_1 ( V_2 , V_21 , 0xf7 , 1 ) ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 , int V_22 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_6 ( L_5 , V_14 , V_22 ) ;
switch ( V_22 ) {
case 3250 :
F_1 ( V_2 , V_21 , 0x38 , 0x10d5 ) ;
F_1 ( V_2 , V_21 , 0x39 , 0x5342 ) ;
F_1 ( V_2 , V_23 , 0x2c , 0x10d9 ) ;
break;
case 3500 :
F_1 ( V_2 , V_21 , 0x38 , 0x1225 ) ;
F_1 ( V_2 , V_21 , 0x39 , 0x1e96 ) ;
F_1 ( V_2 , V_23 , 0x2c , 0x1225 ) ;
break;
case 4000 :
F_1 ( V_2 , V_21 , 0x38 , 0x14bc ) ;
F_1 ( V_2 , V_21 , 0x39 , 0xb53e ) ;
F_1 ( V_2 , V_23 , 0x2c , 0x14bd ) ;
break;
default:
F_6 ( L_6 ,
V_14 , V_22 ) ;
case 5380 :
case 44000 :
F_1 ( V_2 , V_21 , 0x38 , 0x1be4 ) ;
F_1 ( V_2 , V_21 , 0x39 , 0x3655 ) ;
F_1 ( V_2 , V_23 , 0x2c , 0x1be4 ) ;
break;
}
V_2 -> V_24 = V_22 ;
return 0 ;
}
static int F_8 ( struct V_18 * V_19 , int V_25 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_2 V_26 ;
F_6 ( L_7 , V_14 , V_25 ) ;
V_26 = F_4 ( V_2 , V_21 , 0xbe ) & 0xcfff ;
switch ( V_25 ) {
case V_27 :
V_26 |= 0x0000 ;
break;
case V_28 :
F_6 ( L_8 , V_14 , V_25 ) ;
V_26 |= 0x1000 ;
break;
case V_29 :
V_26 |= 0x2000 ;
break;
case V_30 :
V_26 |= 0x3000 ;
break;
default:
return - V_31 ;
}
return F_1 ( V_2 , V_21 , 0xbe , V_26 ) ;
}
static int F_9 ( struct V_18 * V_19 , int V_32 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_2 V_26 ;
F_6 ( L_7 , V_14 , V_32 ) ;
V_26 = F_4 ( V_2 , V_21 , 0x24 ) & ~ 0x1000 ;
if ( V_32 == 1 )
V_26 |= 0x1000 ;
V_2 -> V_32 = V_32 ;
return F_1 ( V_2 , V_21 , 0x24 , V_26 ) ;
}
static int F_10 ( struct V_18 * V_19 , int V_33 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_2 V_26 ;
F_6 ( L_7 , V_14 , V_33 ) ;
V_26 = F_4 ( V_2 , V_21 , 0xbd ) & ~ 0x100 ;
if ( V_33 == 1 )
V_26 |= 0x100 ;
return F_1 ( V_2 , V_21 , 0xbd , V_26 ) ;
}
static int F_11 ( struct V_18 * V_19 ,
T_3 V_34 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_6 ( L_9 , V_14 , V_34 ) ;
if ( ( V_2 -> V_35 == 0 ) && ( V_34 == V_2 -> V_36 ) ) {
F_6 ( L_10 ,
V_14 ) ;
return 0 ;
}
switch ( V_34 ) {
case V_37 :
F_6 ( L_11 , V_14 ) ;
F_7 ( V_19 , V_2 -> V_38 -> V_39 ) ;
F_1 ( V_2 , V_21 , 0x00 , 0x71 ) ;
F_1 ( V_2 , V_21 , 0xf6 , 0x00 ) ;
F_1 ( V_2 , V_21 , 0xcd , 0xf1 ) ;
break;
case V_40 :
case V_41 :
case V_42 :
F_6 ( L_12 , V_14 ) ;
F_7 ( V_19 , V_2 -> V_38 -> V_43 ) ;
F_1 ( V_2 , V_21 , 0x00 , 0x0171 ) ;
F_1 ( V_2 , V_21 , 0xf6 , 0x0001 ) ;
F_1 ( V_2 , V_23 , 0x16 , 0x1101 ) ;
F_1 ( V_2 , V_21 , 0xcd , 0x00f0 ) ;
break;
default:
F_6 ( L_13 , V_14 ) ;
return - V_31 ;
}
V_2 -> V_36 = V_34 ;
V_2 -> V_35 = 0 ;
F_5 ( V_19 ) ;
return 0 ;
}
static int F_12 ( struct V_18 * V_19 , int V_44 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_6 ( L_7 , V_14 , V_44 ) ;
if ( V_44 )
return F_1 ( V_2 , V_21 , 0xf5 , 1 ) ;
else
return F_1 ( V_2 , V_21 , 0xf5 , 0 ) ;
}
static int F_13 ( struct V_18 * V_19 , int V_44 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_2 V_26 ;
F_6 ( L_7 , V_14 , V_44 ) ;
V_26 = F_4 ( V_2 , V_21 , 0xe0 ) & ~ 0x02 ;
if ( V_44 )
return F_1 ( V_2 , V_21 , 0xe0 ,
V_26 | 0x02 ) ;
else
return F_1 ( V_2 , V_21 , 0xe0 , V_26 ) ;
}
static int F_14 ( struct V_18 * V_19 , int V_44 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_6 ( L_7 , V_14 , V_44 ) ;
if ( V_44 )
F_1 ( V_2 , V_21 , 0xf4 , 1 ) ;
else {
F_1 ( V_2 , V_21 , 0xf4 , 0 ) ;
F_5 ( V_19 ) ;
}
return 0 ;
}
static int F_15 ( struct V_18 * V_19 )
{
return F_14 ( V_19 , 1 ) ;
}
static int F_16 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_6 ( L_4 , V_14 ) ;
return F_1 ( V_2 , V_21 , 0xf3 , 0 ) ;
}
static int F_17 ( struct V_18 * V_19 )
{
struct V_45 * V_46 = & V_19 -> V_47 ;
struct V_1 * V_2 = V_19 -> V_20 ;
F_6 ( L_14 , V_14 , V_46 -> V_48 ) ;
F_5 ( V_19 ) ;
V_2 -> V_49 = V_46 -> V_48 ;
F_11 ( V_19 , V_46 -> V_50 ) ;
if ( V_19 -> V_51 . V_52 . V_53 ) {
if ( V_19 -> V_51 . V_54 )
V_19 -> V_51 . V_54 ( V_19 , 1 ) ;
V_19 -> V_51 . V_52 . V_53 ( V_19 ) ;
if ( V_19 -> V_51 . V_54 )
V_19 -> V_51 . V_54 ( V_19 , 0 ) ;
}
F_5 ( V_19 ) ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
int V_55 ;
F_6 ( L_4 , V_14 ) ;
F_14 ( V_19 , 0 ) ;
F_16 ( V_19 ) ;
for ( V_55 = 0 ; V_55 < F_19 ( V_56 ) ; V_55 ++ )
F_1 ( V_2 , V_56 [ V_55 ] . V_3 ,
V_56 [ V_55 ] . V_4 ,
V_56 [ V_55 ] . V_5 ) ;
V_2 -> V_36 = V_37 ;
V_2 -> V_35 = 1 ;
if ( V_2 -> V_38 -> V_57 == V_58 )
F_10 ( V_19 , 1 ) ;
else
F_10 ( V_19 , 0 ) ;
F_9 ( V_19 , V_2 -> V_38 -> V_32 ) ;
F_7 ( V_19 , V_2 -> V_38 -> V_39 ) ;
F_13 ( V_19 , V_2 -> V_38 -> V_59 ) ;
F_8 ( V_19 , V_2 -> V_38 -> V_60 ) ;
F_5 ( V_19 ) ;
F_12 ( V_19 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 , T_4 * V_61 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_2 V_4 ;
T_5 V_62 = 0 ;
* V_61 = 0 ;
switch ( V_2 -> V_36 ) {
case V_40 :
case V_41 :
V_4 = F_4 ( V_2 , V_21 , 0xf0 ) ;
if ( V_4 & 0x10 )
* V_61 |= V_63 | V_64 ;
if ( V_4 & 0x100 )
* V_61 |= V_65 | V_66 | V_67 ;
break;
case V_37 :
V_4 = F_4 ( V_2 , V_21 , 0xf2 ) ;
if ( V_4 & 0x1000 )
* V_61 |= V_63 | V_64 ;
if ( V_4 & 0x2000 )
* V_61 |= V_65 | V_66 | V_67 ;
V_4 = F_4 ( V_2 , V_21 , 0x53 ) ;
if ( V_4 & 0x1 )
* V_61 |= V_67 ;
break;
default:
return - V_31 ;
}
switch ( V_2 -> V_38 -> V_68 ) {
case V_69 :
if ( * V_61 & V_65 )
* V_61 |= V_66 | V_67 ;
break;
case V_70 :
if ( V_19 -> V_51 . V_52 . V_71 ) {
if ( V_19 -> V_51 . V_54 )
V_19 -> V_51 . V_54 ( V_19 , 1 ) ;
V_19 -> V_51 . V_52 . V_71 ( V_19 , & V_62 ) ;
if ( V_19 -> V_51 . V_54 )
V_19 -> V_51 . V_54 ( V_19 , 0 ) ;
}
if ( V_62 )
* V_61 |= V_66 | V_67 ;
break;
}
F_6 ( L_15 , V_14 , * V_61 ) ;
return 0 ;
}
static int F_21 ( struct V_18 * V_19 , T_2 * V_72 , T_2 V_73 )
{
int V_55 , V_6 = - V_31 ;
F_6 ( L_4 , V_14 ) ;
for ( V_55 = 0 ; V_55 < F_19 ( V_74 ) ; V_55 ++ ) {
if ( V_73 < V_74 [ V_55 ] . V_26 ) {
* V_72 = V_74 [ V_55 ] . V_5 ;
V_6 = 0 ;
break;
}
}
return V_6 ;
}
static int F_22 ( struct V_18 * V_19 , T_2 * V_72 , T_2 V_73 )
{
int V_55 , V_6 = - V_31 ;
F_6 ( L_4 , V_14 ) ;
for ( V_55 = 0 ; V_55 < F_19 ( V_75 ) ; V_55 ++ ) {
if ( V_73 < V_75 [ V_55 ] . V_26 ) {
* V_72 = V_75 [ V_55 ] . V_5 ;
V_6 = 0 ;
break;
}
}
return V_6 ;
}
static int F_23 ( struct V_18 * V_19 , T_2 * V_72 , T_2 V_73 )
{
int V_55 , V_6 = - V_31 ;
F_6 ( L_4 , V_14 ) ;
for ( V_55 = 0 ; V_55 < F_19 ( V_76 ) ; V_55 ++ ) {
if ( V_73 > V_76 [ V_55 ] . V_26 ) {
* V_72 = V_76 [ V_55 ] . V_5 ;
V_6 = 0 ;
break;
}
}
F_6 ( L_16 , V_14 , * V_72 ) ;
return V_6 ;
}
static int F_24 ( struct V_18 * V_19 , T_2 * V_72 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_2 V_4 ;
F_6 ( L_4 , V_14 ) ;
switch ( V_2 -> V_36 ) {
case V_40 :
V_4 = F_4 ( V_2 , V_21 , 0xf1 ) ;
return F_22 ( V_19 , V_72 , V_4 ) ;
case V_41 :
V_4 = F_4 ( V_2 , V_21 , 0xf1 ) ;
return F_21 ( V_19 , V_72 , V_4 ) ;
case V_37 :
V_4 = F_4 ( V_2 , V_21 ,
0xf2 ) & 0x3ff ;
return F_23 ( V_19 , V_72 , V_4 ) ;
default:
break;
}
return - V_31 ;
}
static int F_25 ( struct V_18 * V_19 ,
T_2 * V_77 )
{
T_2 V_72 ;
T_5 V_78 ;
int V_6 = F_24 ( V_19 , & V_72 ) ;
* V_77 = 0 ;
if ( 0 == V_6 ) {
V_78 = ( V_72 * ( ( 1 << 24 ) / 10 ) ) ;
if ( V_78 >= 8960 * 0x10000 )
* V_77 = 0xffff ;
else
* V_77 = V_78 / 8960 ;
}
return V_6 ;
}
static int F_26 ( struct V_18 * V_19 , T_5 * V_79 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
* V_79 = F_4 ( V_2 , V_21 , 0xc9 ) ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 , T_5 * V_80 )
{
return F_26 ( V_19 , V_80 ) ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_45 * V_46 = & V_19 -> V_47 ;
struct V_1 * V_2 = V_19 -> V_20 ;
V_46 -> V_48 = V_2 -> V_49 ;
V_46 -> V_50 = V_2 -> V_36 ;
return 0 ;
}
static int F_29 ( struct V_18 * V_19 ,
struct V_81 * V_82 )
{
V_82 -> V_83 = 1000 ;
return 0 ;
}
static void F_30 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
F_31 ( V_2 ) ;
}
struct V_18 * F_32 ( const struct V_84 * V_38 ,
struct V_85 * V_12 )
{
struct V_1 * V_2 = NULL ;
T_2 V_4 ;
V_2 = F_33 ( sizeof( struct V_1 ) , V_86 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_38 = V_38 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_36 = V_37 ;
V_2 -> V_32 = V_2 -> V_38 -> V_32 ;
V_4 = F_4 ( V_2 , V_21 , 0x05 ) ;
if ( V_4 != 0x0066 )
goto error;
memcpy ( & V_2 -> V_87 . V_51 , & V_88 ,
sizeof( struct V_89 ) ) ;
V_2 -> V_87 . V_20 = V_2 ;
if ( F_18 ( & V_2 -> V_87 ) != 0 ) {
F_3 ( V_13 L_17 ,
V_14 ) ;
goto error;
}
F_1 ( V_2 , V_21 , 0xf5 , 1 ) ;
F_14 ( & V_2 -> V_87 , 1 ) ;
return & V_2 -> V_87 ;
error:
F_31 ( V_2 ) ;
return NULL ;
}
