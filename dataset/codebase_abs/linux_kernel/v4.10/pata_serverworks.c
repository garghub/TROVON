static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_4 -> V_7 & ( 1 << ( V_2 -> V_8 + 14 ) ) )
return V_9 ;
return V_10 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
struct V_11 * V_12 = V_13 ;
while( V_12 -> V_14 ) {
if ( V_12 -> V_14 == V_4 -> V_14 &&
( V_12 -> V_15 == V_4 -> V_16 ||
V_12 -> V_15 == V_17 ) ) {
return V_12 -> V_13 ( V_2 ) ;
}
V_12 ++ ;
}
F_4 () ;
return - 1 ;
}
static T_1 F_5 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_14 ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return 1 ;
default:
break;
}
return 0 ;
}
static unsigned long F_6 ( struct V_22 * V_23 , unsigned long V_24 )
{
if ( V_23 -> V_25 == V_26 )
V_24 &= ~ V_27 ;
return V_24 ;
}
static unsigned long F_7 ( struct V_22 * V_23 , unsigned long V_24 )
{
const char * V_28 ;
char V_29 [ V_30 + 1 ] ;
int V_31 ;
if ( V_23 -> V_25 != V_26 )
return V_24 ;
F_8 ( V_23 -> V_32 , V_29 , V_33 , sizeof( V_29 ) ) ;
for ( V_31 = 0 ; ( V_28 = V_34 [ V_31 ] ) != NULL ; V_31 ++ ) {
if ( ! strcmp ( V_28 , V_29 ) )
V_24 &= ~ ( 0xE0 << V_35 ) ;
}
return V_24 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
static const T_1 V_36 [] = { 0x5d , 0x47 , 0x34 , 0x22 , 0x20 } ;
int V_37 = 1 + 2 * V_2 -> V_8 - V_23 -> V_38 ;
int V_39 = ( 2 * V_2 -> V_8 + V_23 -> V_38 ) * 4 ;
T_2 V_40 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_41 = V_23 -> V_36 - V_42 ;
F_10 ( V_4 , 0x40 + V_37 , V_36 [ V_41 ] ) ;
if ( F_5 ( V_4 ) ) {
F_11 ( V_4 , 0x4A , & V_40 ) ;
V_40 &= ~ ( 0x0F << V_39 ) ;
F_12 ( V_4 , 0x4A , V_40 | ( V_41 << V_39 ) ) ;
}
}
static void F_13 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
static const T_1 V_43 [] = { 0x77 , 0x21 , 0x20 } ;
int V_37 = 1 + 2 * V_2 -> V_8 - V_23 -> V_38 ;
int V_39 = 2 * V_2 -> V_8 + V_23 -> V_38 ;
T_1 V_44 ;
T_1 V_45 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
F_14 ( V_4 , 0x54 , & V_45 ) ;
F_14 ( V_4 , 0x56 + V_2 -> V_8 , & V_44 ) ;
V_44 &= ~ ( 0x0F << ( V_23 -> V_38 * 4 ) ) ;
if ( V_23 -> V_43 >= V_46 ) {
F_10 ( V_4 , 0x44 + V_37 , 0x20 ) ;
V_44 |= ( V_23 -> V_43 - V_46 )
<< ( V_23 -> V_38 * 4 ) ;
V_45 |= ( 1 << V_39 ) ;
} else {
F_10 ( V_4 , 0x44 + V_37 ,
V_43 [ V_23 -> V_43 - V_47 ] ) ;
V_45 &= ~ ( 1 << V_39 ) ;
}
F_10 ( V_4 , 0x56 + V_2 -> V_8 , V_44 ) ;
F_10 ( V_4 , 0x54 , V_45 ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
T_3 V_48 ;
struct V_3 * V_49 = F_16 ( V_50 ,
V_51 , NULL ) ;
if ( V_49 ) {
F_17 ( V_49 , 0x64 , & V_48 ) ;
V_48 &= ~ 0x00002000 ;
if ( ! ( V_48 & 0x00004000 ) )
F_18 (KERN_DEBUG DRV_NAME L_1 ) ;
V_48 |= 0x00004000 ;
F_19 ( V_49 , 0x64 , V_48 ) ;
F_20 ( V_49 ) ;
return 0 ;
}
F_18 (KERN_WARNING DRV_NAME L_2 ) ;
return - V_52 ;
}
static int F_21 ( struct V_3 * V_4 )
{
T_1 V_53 ;
if ( ! ( F_22 ( V_4 -> V_54 ) & 1 ) ) {
struct V_3 * V_55 = NULL ;
T_3 V_56 = 0 ;
V_55 = F_16 ( V_50 ,
V_57 , NULL ) ;
if ( V_55 ) {
F_17 ( V_55 , 0x4C , & V_56 ) ;
V_56 &= ~ 0x000007FF ;
V_56 |= 0x00000040 ;
V_56 |= 0x00000020 ;
F_19 ( V_55 , 0x4C , V_56 ) ;
F_20 ( V_55 ) ;
}
} else {
struct V_3 * V_55 = NULL ;
T_1 V_58 = 0 ;
V_55 = F_16 ( V_50 ,
V_59 , NULL ) ;
if ( V_55 ) {
F_14 ( V_55 , 0x41 , & V_58 ) ;
V_58 &= ~ 0x40 ;
F_10 ( V_55 , 0x41 , V_58 ) ;
F_20 ( V_55 ) ;
}
}
F_14 ( V_4 , 0x5A , & V_53 ) ;
V_53 &= ~ 0x40 ;
if ( ! ( F_22 ( V_4 -> V_54 ) & 1 ) )
V_53 |= 0x2 ;
else
V_53 |= ( V_4 -> V_60 >= V_61 ) ? 0x3 : 0x2 ;
F_10 ( V_4 , 0x5A , V_53 ) ;
return V_53 ;
}
static void F_23 ( struct V_3 * V_4 )
{
T_1 V_53 ;
F_14 ( V_4 , 0x5A , & V_53 ) ;
V_53 &= ~ 0x40 ;
V_53 |= 0x3 ;
F_10 ( V_4 , 0x5A , V_53 ) ;
}
static int F_24 ( struct V_3 * V_4 )
{
int V_62 = 0 ;
F_10 ( V_4 , V_63 , 0x40 ) ;
switch ( V_4 -> V_14 ) {
case V_64 :
V_62 = F_15 ( V_4 ) ;
break;
case V_18 :
F_25 ( V_4 ) ;
case V_19 :
case V_20 :
V_62 = F_21 ( V_4 ) ;
break;
case V_21 :
F_23 ( V_4 ) ;
break;
}
return V_62 ;
}
static int F_26 ( struct V_3 * V_4 , const struct V_65 * V_32 )
{
static const struct V_66 V_67 [ 4 ] = {
{
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_73 ,
. V_74 = V_75 ,
. V_76 = & V_77
} , {
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_73 ,
. V_76 = & V_77
} , {
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_73 ,
. V_74 = V_78 ,
. V_76 = & V_79
} , {
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_73 ,
. V_74 = V_80 ,
. V_76 = & V_79
}
} ;
const struct V_66 * V_81 [] = { & V_67 [ V_32 -> V_82 ] , NULL } ;
struct V_83 * V_84 = & V_85 ;
int V_62 ;
V_62 = F_27 ( V_4 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_24 ( V_4 ) ;
if ( V_4 -> V_14 == V_64 ) {
if ( V_62 < 0 )
V_81 [ 0 ] = & V_67 [ 1 ] ;
V_84 = & V_86 ;
}
else if ( ( V_4 -> V_14 == V_18 ) ||
( V_4 -> V_14 == V_19 ) ||
( V_4 -> V_14 == V_20 ) ) {
if ( V_62 == 3 )
V_81 [ 0 ] = & V_67 [ 3 ] ;
if ( V_4 -> V_14 == V_20 )
V_81 [ 1 ] = & V_87 ;
}
return F_28 ( V_4 , V_81 , V_84 , NULL , 0 ) ;
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_88 * V_5 = F_30 ( V_4 ) ;
int V_62 ;
V_62 = F_31 ( V_4 ) ;
if ( V_62 )
return V_62 ;
( void ) F_24 ( V_4 ) ;
F_32 ( V_5 ) ;
return 0 ;
}
