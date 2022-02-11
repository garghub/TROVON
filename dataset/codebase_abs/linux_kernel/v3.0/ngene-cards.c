static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = (struct V_5 * )
V_2 -> V_7 -> V_8 -> V_9 [ V_2 -> V_10 ] ;
struct V_11 * V_12 = (struct V_11 * )
V_2 -> V_7 -> V_8 -> V_13 [ V_2 -> V_10 ] ;
struct V_14 * V_15 ;
if ( V_2 -> V_10 < 2 )
V_4 = & V_2 -> V_7 -> V_16 [ 0 ] . V_3 ;
else
V_4 = & V_2 -> V_7 -> V_16 [ 1 ] . V_3 ;
V_15 = F_2 ( V_17 , V_2 -> V_18 , V_12 , V_4 ) ;
if ( V_15 == NULL ) {
F_3 (KERN_ERR DEVICE_NAME L_1 ) ;
return - V_19 ;
}
V_6 -> V_20 = V_15 -> V_20 ;
V_6 -> V_21 = V_15 -> V_21 ;
V_6 -> V_22 = V_15 -> V_22 ;
V_6 -> V_23 = V_15 -> V_23 ;
V_6 -> V_24 = V_15 -> V_24 ;
V_6 -> V_25 = V_15 -> V_25 ;
V_6 -> V_26 = V_15 -> V_26 ;
V_6 -> V_27 = V_15 -> V_27 ;
V_6 -> V_28 = V_15 -> V_28 ;
V_6 -> V_29 = V_15 -> V_29 ;
V_6 -> V_30 = V_15 -> V_30 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = (struct V_5 * )
V_2 -> V_7 -> V_8 -> V_9 [ V_2 -> V_10 ] ;
if ( V_2 -> V_10 < 2 )
V_4 = & V_2 -> V_7 -> V_16 [ 0 ] . V_3 ;
else
V_4 = & V_2 -> V_7 -> V_16 [ 1 ] . V_3 ;
V_2 -> V_18 = F_2 ( V_31 , V_6 , V_4 ,
( V_2 -> V_10 & 1 ) == 0 ? V_32
: V_33 ) ;
if ( V_2 -> V_18 == NULL ) {
F_3 (KERN_ERR DEVICE_NAME L_2 ) ;
return - V_19 ;
}
if ( V_6 -> V_34 )
V_2 -> V_18 -> V_35 = V_2 ;
if ( ! F_2 ( V_36 , V_2 -> V_18 , V_4 , 0 ,
0 , V_2 -> V_7 -> V_8 -> V_37 [ V_2 -> V_10 ] ) ) {
F_3 (KERN_ERR DEVICE_NAME L_3 ) ;
F_5 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
return - V_19 ;
}
return 0 ;
}
static void F_6 ( struct V_38 * V_18 , int V_39 )
{
struct V_1 * V_2 = V_18 -> V_35 ;
if ( V_39 )
F_7 ( & V_2 -> V_7 -> V_40 ) ;
else
F_8 ( & V_2 -> V_7 -> V_40 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_41 ;
T_1 V_42 [ 3 ] ;
struct V_43 V_43 = { . V_44 = 0 , . V_42 = V_42 } ;
int V_45 ;
if ( V_2 -> V_10 < 2 )
V_4 = & V_2 -> V_7 -> V_16 [ 0 ] . V_3 ;
else
V_4 = & V_2 -> V_7 -> V_16 [ 1 ] . V_3 ;
V_41 = V_2 -> V_7 -> V_8 -> V_9 [ V_2 -> V_10 ] ;
V_43 . V_46 = V_41 -> V_47 ;
V_43 . V_48 = 2 ;
V_42 [ 0 ] = 0xf1 ;
V_42 [ 1 ] = 0x00 ;
V_45 = F_10 ( V_4 , & V_43 , 1 ) ;
if ( V_45 != 1 )
return - V_19 ;
V_45 = F_4 ( V_2 ) ;
if ( V_45 < 0 || V_2 -> V_10 < 2 )
return V_45 ;
V_43 . V_48 = 3 ;
V_42 [ 0 ] = 0xf1 ;
switch ( V_2 -> V_10 ) {
case 2 :
V_42 [ 1 ] = 0x5c ;
V_42 [ 2 ] = 0xc2 ;
break;
case 3 :
V_42 [ 1 ] = 0x61 ;
V_42 [ 2 ] = 0xcc ;
break;
default:
return - V_19 ;
}
V_45 = F_10 ( V_4 , & V_43 , 1 ) ;
if ( V_45 != 1 ) {
F_3 (KERN_ERR DEVICE_NAME L_4 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
V_2 -> V_18 = F_2 ( V_50 , & V_51 , & V_2 -> V_3 ) ;
if ( V_2 -> V_18 == NULL ) {
F_3 (KERN_ERR DEVICE_NAME L_5 ) ;
return - V_19 ;
}
F_2 ( V_52 , V_2 -> V_18 , & V_2 -> V_3 ,
& V_53 , 0 ) ;
return ( V_2 -> V_18 ) ? 0 : - V_19 ;
}
static T_2 F_12 ( struct V_54 * V_7 ,
enum V_55 V_56 )
{
F_3 (KERN_ERR DEVICE_NAME L_6 ) ;
if ( V_56 == V_57 )
return V_58 ;
if ( V_56 == V_59 )
return V_60 ;
return V_61 ;
}
static T_2 F_13 ( struct V_54 * V_7 )
{
F_3 (KERN_INFO DEVICE_NAME L_7 ) ;
return 0 ;
}
static T_2 F_14 ( struct V_54 * V_7 )
{
F_3 (KERN_INFO DEVICE_NAME L_8 ) ;
return 0 ;
}
static void F_15 ( struct V_54 * V_7 )
{
F_3 (KERN_INFO DEVICE_NAME L_9 ) ;
}
static T_3 int F_16 ( void )
{
F_3 ( V_62
L_10 ) ;
return F_17 ( & V_63 ) ;
}
static T_4 void F_18 ( void )
{
F_19 ( & V_63 ) ;
}
