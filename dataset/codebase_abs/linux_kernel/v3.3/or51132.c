static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 , int V_4 )
{
int V_5 ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 ,
. V_11 = 0 , . V_3 = ( T_1 * ) V_3 , . V_4 = V_4 } ;
if ( ( V_5 = F_2 ( V_2 -> V_12 , & V_7 , 1 ) ) != 1 ) {
F_3 ( V_13 L_1 ,
V_7 . V_8 , V_7 . V_4 , V_5 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
int V_5 ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 ,
. V_11 = V_15 , . V_3 = V_3 , . V_4 = V_4 } ;
if ( ( V_5 = F_2 ( V_2 -> V_12 , & V_7 , 1 ) ) != 1 ) {
F_3 ( V_13 L_2 ,
V_7 . V_8 , V_7 . V_4 , V_5 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_16 )
{
T_1 V_3 [ 2 ] = { 0x04 , V_16 } ;
struct V_6 V_7 [ 2 ] = {
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 ,
. V_3 = V_3 , . V_4 = 2 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_15 ,
. V_3 = V_3 , . V_4 = 2 } } ;
int V_5 ;
if ( ( V_5 = F_2 ( V_2 -> V_12 , V_7 , 2 ) ) != 2 ) {
F_3 ( V_13 L_3 ,
V_16 , V_5 ) ;
return - V_14 ;
}
return V_3 [ 0 ] | ( V_3 [ 1 ] << 8 ) ;
}
static int F_6 ( struct V_17 * V_18 , const struct V_19 * V_20 )
{
struct V_1 * V_2 = V_18 -> V_21 ;
static const T_1 V_22 [] = { 0x7F , 0x01 } ;
T_1 V_23 [ 8 ] ;
T_2 V_24 , V_25 ;
int V_26 , V_27 ;
F_7 ( L_4 , V_20 -> V_28 ) ;
V_24 = F_8 ( * ( ( V_29 * ) V_20 -> V_30 ) ) ;
F_7 ( L_5 , V_24 ) ;
V_25 = F_8 ( * ( ( V_29 * ) ( V_20 -> V_30 + 4 ) ) ) ;
F_7 ( L_6 , V_25 ) ;
if ( ( V_27 = F_1 ( V_2 , & V_20 -> V_30 [ 8 ] , V_24 ) ) ) {
F_3 ( V_13 L_7 ) ;
return V_27 ;
}
if ( ( V_27 = F_1 ( V_2 , & V_20 -> V_30 [ 8 + V_24 ] ,
V_25 ) ) ) {
F_3 ( V_13 L_8 ) ;
return V_27 ;
}
if ( ( V_27 = F_1 ( V_2 , V_22 , 2 ) ) ) {
F_3 ( V_13 L_9 ) ;
return V_27 ;
}
if ( ( V_27 = F_1 ( V_2 , V_22 , 2 ) ) ) {
F_3 ( V_13 L_10 ) ;
return V_27 ;
}
F_9 ( 50 ) ;
if ( ( V_27 = F_10 ( V_2 , 0x10 , 0x10 , 0x00 ) ) ) {
F_3 ( V_13 L_11 ) ;
return V_27 ;
}
if ( ( V_27 = F_10 ( V_2 , 0x04 , 0x17 ) ) ) {
F_3 ( V_13 L_12 ) ;
return V_27 ;
}
if ( ( V_27 = F_10 ( V_2 , 0x00 , 0x00 ) ) ) {
F_3 ( V_13 L_13 ) ;
return V_27 ;
}
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
if ( ( V_27 = F_4 ( V_2 , & V_23 [ V_26 * 2 ] , 2 ) ) ) {
F_3 ( V_13
L_14 , V_26 ) ;
return V_27 ;
}
}
F_3 ( V_13
L_15 ,
V_23 [ 1 ] , V_23 [ 0 ] , V_23 [ 3 ] , V_23 [ 2 ] ,
V_23 [ 5 ] , V_23 [ 4 ] , V_23 [ 7 ] , V_23 [ 6 ] ,
V_23 [ 3 ] , V_23 [ 2 ] >> 4 , V_23 [ 2 ] & 0x0f ,
V_23 [ 5 ] , V_23 [ 4 ] >> 4 , V_23 [ 4 ] & 0x0f ) ;
if ( ( V_27 = F_10 ( V_2 , 0x10 , 0x00 , 0x00 ) ) ) {
F_3 ( V_13 L_16 ) ;
return V_27 ;
}
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
return 0 ;
}
static int F_12 ( struct V_17 * V_18 , T_2 * V_31 )
{
* V_31 = 0 ;
return 0 ;
}
static int F_13 ( struct V_17 * V_18 , T_2 * V_32 )
{
* V_32 = 0 ;
return 0 ;
}
static int F_14 ( struct V_17 * V_18 )
{
return 0 ;
}
static int F_15 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_21 ;
T_1 V_33 [ 3 ] = { 0x04 , 0x01 , 0x5f } ;
T_1 V_34 [ 3 ] = { 0x1c , 0x00 , 0 } ;
F_7 ( L_17 , ( int ) V_2 -> V_35 ) ;
switch ( V_2 -> V_35 ) {
case V_36 :
V_33 [ 2 ] = 0x50 ;
V_34 [ 1 ] = 0x03 ;
V_34 [ 2 ] = 0x06 ;
break;
case V_37 :
V_34 [ 2 ] = 0x4f ;
break;
case V_38 :
V_34 [ 2 ] = 0x45 ;
break;
case V_39 :
V_34 [ 2 ] = 0x43 ;
break;
default:
F_3 ( V_13
L_18 ,
V_2 -> V_35 ) ;
return - V_40 ;
}
if ( F_1 ( V_2 , V_33 , 3 ) ) {
F_3 ( V_13 L_19 ) ;
return - V_14 ;
}
F_7 ( L_20 , V_33 [ 2 ] ) ;
if ( F_1 ( V_2 , V_34 , 3 ) ) {
F_3 ( V_13 L_21 ) ;
return - V_14 ;
}
F_7 ( L_22 , V_34 [ 1 ] , V_34 [ 2 ] ) ;
return 0 ;
}
static int F_16 ( T_3 V_41 )
{
switch( V_41 ) {
case V_36 :
return V_42 ;
case V_37 :
case V_39 :
case V_38 :
return V_43 ;
default:
return V_44 ;
}
}
static int F_17 ( struct V_17 * V_18 )
{
struct V_45 * V_46 = & V_18 -> V_47 ;
int V_27 ;
struct V_1 * V_2 = V_18 -> V_21 ;
const struct V_19 * V_20 ;
const char * V_48 ;
int V_49 ;
if ( F_16 ( V_2 -> V_35 ) !=
F_16 ( V_46 -> V_41 ) ) {
switch ( F_16 ( V_46 -> V_41 ) ) {
case V_42 :
F_7 ( L_23 ) ;
V_48 = V_50 ;
V_49 = 0 ;
break;
case V_43 :
F_7 ( L_24 ) ;
V_48 = V_51 ;
V_49 = 1 ;
break;
default:
F_3 ( L_25 ,
V_46 -> V_41 ) ;
return - 1 ;
}
F_3 ( L_26 ,
V_48 ) ;
V_27 = F_18 ( & V_20 , V_48 , V_2 -> V_12 -> V_52 . V_53 ) ;
if ( V_27 ) {
F_3 ( V_13 L_27
L_28 ) ;
return V_27 ;
}
V_27 = F_6 ( V_18 , V_20 ) ;
F_19 ( V_20 ) ;
if ( V_27 ) {
F_3 ( V_13 L_29
L_30 ) ;
return V_27 ;
}
F_3 ( L_31 ) ;
V_2 -> V_9 -> V_54 ( V_18 , V_49 ) ;
}
if ( V_2 -> V_35 != V_46 -> V_41 ) {
V_2 -> V_35 = V_46 -> V_41 ;
F_15 ( V_18 ) ;
}
if ( V_18 -> V_55 . V_56 . V_57 ) {
V_18 -> V_55 . V_56 . V_57 ( V_18 ) ;
if ( V_18 -> V_55 . V_58 ) V_18 -> V_55 . V_58 ( V_18 , 0 ) ;
}
F_15 ( V_18 ) ;
V_2 -> V_59 = V_46 -> V_60 ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 )
{
struct V_45 * V_46 = & V_18 -> V_47 ;
struct V_1 * V_2 = V_18 -> V_21 ;
int V_61 ;
int V_62 = 1 ;
V_63:
if ( ( V_61 = F_5 ( V_2 , 0x00 ) ) < 0 ) {
F_3 ( V_13 L_32 ) ;
return - V_14 ;
}
switch( V_61 & 0xff ) {
case 0x06 :
V_46 -> V_41 = V_36 ;
break;
case 0x43 :
V_46 -> V_41 = V_39 ;
break;
case 0x45 :
V_46 -> V_41 = V_38 ;
break;
default:
if ( V_62 -- )
goto V_63;
F_3 ( V_13 L_33 ,
V_61 & 0xff ) ;
return - V_14 ;
}
V_46 -> V_60 = V_2 -> V_59 ;
V_46 -> V_64 = V_65 ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 , T_4 * V_61 )
{
struct V_1 * V_2 = V_18 -> V_21 ;
int V_16 ;
if ( ( V_16 = F_5 ( V_2 , 0x00 ) ) < 0 ) {
F_3 ( V_13 L_34 , V_16 ) ;
* V_61 = 0 ;
return - V_14 ;
}
F_7 ( L_35 , V_66 , V_16 ) ;
if ( V_16 & 0x0100 )
* V_61 = V_67 | V_68 | V_69 |
V_70 | V_71 ;
else
* V_61 = 0 ;
return 0 ;
}
static T_2 F_22 ( T_2 V_72 , T_2 V_73 )
{
if ( V_72 == 0 )
return 0 ;
V_72 = 2 * F_23 ( V_72 ) ;
if ( V_72 > V_73 ) {
return 0 ;
}
return 10 * ( V_73 - V_72 ) ;
}
static int F_24 ( struct V_17 * V_18 , T_5 * V_74 )
{
struct V_1 * V_2 = V_18 -> V_21 ;
int V_75 , V_16 ;
T_2 V_73 , V_76 = 0 ;
int V_62 = 1 ;
V_63:
V_75 = F_5 ( V_2 , 0x02 ) ;
if ( V_75 < 0 ) {
F_3 ( V_13 L_36 ) ;
return - V_14 ;
}
F_7 ( L_37 , V_75 ) ;
V_16 = F_5 ( V_2 , 0x00 ) ;
if ( V_16 < 0 ) {
F_3 ( V_13 L_38 ) ;
return - V_14 ;
}
switch ( V_16 & 0xff ) {
case 0x06 :
if ( V_16 & 0x1000 ) V_76 = 3 << 24 ;
case 0x43 :
V_73 = 150204167 ;
break;
case 0x45 :
V_73 = 150290396 ;
break;
default:
F_3 ( V_13 L_33 , V_16 & 0xff ) ;
if ( V_62 -- ) goto V_63;
return - V_14 ;
}
F_7 ( L_39 , V_66 ,
V_16 & 0xff , V_16 & 0x1000 ? L_40 : L_41 ) ;
V_2 -> V_74 = F_22 ( V_75 , V_73 ) - V_76 ;
* V_74 = ( V_2 -> V_74 ) >> 16 ;
F_7 ( L_42 , V_66 , V_75 ,
V_2 -> V_74 >> 24 , ( ( ( V_2 -> V_74 >> 8 ) & 0xffff ) * 100 ) >> 16 ) ;
return 0 ;
}
static int F_25 ( struct V_17 * V_18 , T_5 * V_77 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_21 ;
T_5 V_74 ;
int V_27 ;
V_27 = V_18 -> V_55 . V_78 ( V_18 , & V_74 ) ;
if ( V_27 != 0 )
return V_27 ;
if ( V_2 -> V_74 >= 8960 * 0x10000 )
* V_77 = 0xffff ;
else
* V_77 = V_2 -> V_74 / 8960 ;
return 0 ;
}
static int F_26 ( struct V_17 * V_18 , struct V_79 * V_80 )
{
V_80 -> V_81 = 500 ;
V_80 -> V_82 = 0 ;
V_80 -> V_83 = 0 ;
return 0 ;
}
static void F_27 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_21 ;
F_28 ( V_2 ) ;
}
struct V_17 * F_29 ( const struct V_84 * V_9 ,
struct V_85 * V_12 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_86 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_9 = V_9 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_59 = - 1 ;
V_2 -> V_35 = - 1 ;
memcpy ( & V_2 -> V_87 . V_55 , & V_88 , sizeof( struct V_89 ) ) ;
V_2 -> V_87 . V_21 = V_2 ;
return & V_2 -> V_87 ;
}
