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
static int F_4 ( struct V_31 * V_18 , int V_32 )
{
struct V_1 * V_2 = V_18 -> V_33 ;
int V_34 ;
if ( V_32 ) {
F_5 ( & V_2 -> V_7 -> V_35 ) ;
V_34 = V_2 -> V_36 ( V_18 , 1 ) ;
} else {
V_34 = V_2 -> V_36 ( V_18 , 0 ) ;
F_6 ( & V_2 -> V_7 -> V_35 ) ;
}
return V_34 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_31 * V_18 ;
V_4 = & V_2 -> V_7 -> V_16 [ 0 ] . V_3 ;
if ( V_2 -> V_18 -> V_37 . V_38 )
V_2 -> V_18 -> V_37 . V_38 ( V_2 -> V_18 , 1 ) ;
V_18 = F_2 ( V_39 , V_2 -> V_18 , V_4 , 0x60 ) ;
if ( V_2 -> V_18 -> V_37 . V_38 )
V_2 -> V_18 -> V_37 . V_38 ( V_2 -> V_18 , 0 ) ;
if ( ! V_18 ) {
F_3 ( V_40 L_2 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 == 0 )
return F_1 ( V_2 ) ;
if ( V_2 -> V_41 == 1 )
return F_7 ( V_2 ) ;
return - V_42 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = (struct V_5 * )
V_2 -> V_7 -> V_8 -> V_9 [ V_2 -> V_10 ] ;
if ( V_2 -> V_10 < 2 )
V_4 = & V_2 -> V_7 -> V_16 [ 0 ] . V_3 ;
else
V_4 = & V_2 -> V_7 -> V_16 [ 1 ] . V_3 ;
V_2 -> V_18 = F_2 ( V_43 , V_6 , V_4 ,
( V_2 -> V_10 & 1 ) == 0 ? V_44
: V_45 ) ;
if ( V_2 -> V_18 == NULL ) {
F_3 (KERN_ERR DEVICE_NAME L_3 ) ;
return - V_19 ;
}
if ( V_6 -> V_46 )
V_2 -> V_18 -> V_47 = V_2 ;
if ( ! F_2 ( V_48 , V_2 -> V_18 , V_4 , 0 ,
0 , V_2 -> V_7 -> V_8 -> V_49 [ V_2 -> V_10 ] ) ) {
F_3 (KERN_ERR DEVICE_NAME L_4 ) ;
F_10 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
return - V_19 ;
}
return 0 ;
}
static void F_11 ( struct V_31 * V_18 , int V_50 )
{
struct V_1 * V_2 = V_18 -> V_47 ;
if ( V_50 )
F_5 ( & V_2 -> V_7 -> V_35 ) ;
else
F_6 ( & V_2 -> V_7 -> V_35 ) ;
}
static int F_12 ( struct V_3 * V_51 , T_1 V_52 , T_1 * V_53 )
{
struct V_54 V_55 [ 1 ] = { { . V_56 = V_52 , . V_57 = V_58 ,
. V_59 = V_53 , . V_60 = 1 } } ;
return ( F_13 ( V_51 , V_55 , 1 ) == 1 ) ? 0 : - 1 ;
}
static int F_14 ( struct V_3 * V_51 , T_1 V_52 ,
T_2 V_61 , T_1 * V_53 )
{
T_1 V_62 [ 2 ] = { V_61 >> 8 , V_61 & 0xff } ;
struct V_54 V_55 [ 2 ] = { { . V_56 = V_52 , . V_57 = 0 ,
. V_59 = V_62 , . V_60 = 2 } ,
{ . V_56 = V_52 , . V_57 = V_58 ,
. V_59 = V_53 , . V_60 = 1 } } ;
return ( F_13 ( V_51 , V_55 , 2 ) == 2 ) ? 0 : - 1 ;
}
static int F_15 ( struct V_3 * V_4 , int V_63 )
{
T_1 V_53 ;
if ( F_14 ( V_4 , 0x68 + V_63 / 2 , 0xf100 , & V_53 ) < 0 )
return 0 ;
return 1 ;
}
static int F_16 ( struct V_3 * V_4 , int V_63 )
{
T_1 V_53 ;
if ( F_12 ( V_4 , 0x29 + V_63 , & V_53 ) < 0 )
return 0 ;
return 1 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_64 V_65 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_66 = L_5 ;
V_65 . V_67 = 4 ;
V_65 . V_52 = 0x29 + ( V_2 -> V_10 ^ 2 ) ;
V_2 -> V_18 = F_2 ( V_68 , & V_65 , V_4 ) ;
if ( ! V_2 -> V_18 ) {
F_3 ( V_40 L_6 ) ;
return - V_19 ;
}
V_2 -> V_18 -> V_33 = V_2 ;
V_2 -> V_36 = V_2 -> V_18 -> V_37 . V_38 ;
V_2 -> V_18 -> V_37 . V_38 = F_4 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_69 ;
T_1 V_59 [ 3 ] ;
struct V_54 V_54 = { . V_57 = 0 , . V_59 = V_59 } ;
int V_70 ;
if ( V_2 -> V_10 < 2 )
V_4 = & V_2 -> V_7 -> V_16 [ 0 ] . V_3 ;
else
V_4 = & V_2 -> V_7 -> V_16 [ 1 ] . V_3 ;
if ( F_15 ( V_4 , V_2 -> V_10 ) ) {
V_2 -> V_41 = 0 ;
V_69 = V_2 -> V_7 -> V_8 -> V_9 [ V_2 -> V_10 ] ;
V_70 = F_9 ( V_2 ) ;
if ( V_70 < 0 || V_2 -> V_10 < 2 )
return V_70 ;
V_54 . V_56 = V_69 -> V_71 ;
V_54 . V_60 = 3 ;
V_59 [ 0 ] = 0xf1 ;
switch ( V_2 -> V_10 ) {
case 2 :
V_59 [ 1 ] = 0x5c ;
V_59 [ 2 ] = 0xc2 ;
break;
case 3 :
V_59 [ 1 ] = 0x61 ;
V_59 [ 2 ] = 0xcc ;
break;
default:
return - V_19 ;
}
V_70 = F_13 ( V_4 , & V_54 , 1 ) ;
if ( V_70 != 1 ) {
F_3 (KERN_ERR DEVICE_NAME L_7 ) ;
return - V_72 ;
}
} else if ( F_16 ( V_4 , V_2 -> V_10 ^ 2 ) ) {
V_2 -> V_41 = 1 ;
F_17 ( V_2 , V_4 ) ;
} else {
F_3 ( V_40 L_8 , V_2 -> V_10 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
V_2 -> V_18 = F_2 ( V_73 , & V_74 , & V_2 -> V_3 ) ;
if ( V_2 -> V_18 == NULL ) {
F_3 (KERN_ERR DEVICE_NAME L_9 ) ;
return - V_19 ;
}
F_2 ( V_75 , V_2 -> V_18 , & V_2 -> V_3 ,
& V_76 , 0 ) ;
return ( V_2 -> V_18 ) ? 0 : - V_19 ;
}
static T_3 F_20 ( struct V_77 * V_7 ,
enum V_78 V_79 )
{
F_3 (KERN_ERR DEVICE_NAME L_10 ) ;
if ( V_79 == V_80 )
return V_81 ;
if ( V_79 == V_82 )
return V_83 ;
return V_84 ;
}
static T_3 F_21 ( struct V_77 * V_7 )
{
F_3 (KERN_INFO DEVICE_NAME L_11 ) ;
return 0 ;
}
static T_3 F_22 ( struct V_77 * V_7 )
{
F_3 (KERN_INFO DEVICE_NAME L_12 ) ;
return 0 ;
}
static void F_23 ( struct V_77 * V_7 )
{
F_3 (KERN_INFO DEVICE_NAME L_13 ) ;
}
static T_4 int F_24 ( void )
{
F_3 ( V_85
L_14 ) ;
return F_25 ( & V_86 ) ;
}
static T_5 void F_26 ( void )
{
F_27 ( & V_86 ) ;
}
