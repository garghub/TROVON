static int F_1 ( struct V_1 * V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_4 -> V_7 & ( 1 << ( V_2 -> V_8 + 14 ) ) )
return V_9 ;
return V_10 ;
}
static int F_3 ( struct V_1 * V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_4 -> V_7 & ( 1 << ( V_2 -> V_8 + 14 ) ) )
return V_9 ;
return V_10 ;
}
static int F_4 ( struct V_1 * V_2 ) {
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 ) {
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
struct V_12 * V_13 = V_14 ;
while( V_13 -> V_15 ) {
if ( V_13 -> V_15 == V_4 -> V_15 &&
( V_13 -> V_16 == V_4 -> V_17 ||
V_13 -> V_16 == V_18 ) ) {
return V_13 -> V_14 ( V_2 ) ;
}
V_13 ++ ;
}
F_7 () ;
return - 1 ;
}
static T_1 F_8 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_15 ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
return 1 ;
default:
break;
}
return 0 ;
}
static unsigned long F_9 ( struct V_23 * V_24 , unsigned long V_25 )
{
if ( V_24 -> V_26 == V_27 )
V_25 &= ~ V_28 ;
return V_25 ;
}
static unsigned long F_10 ( struct V_23 * V_24 , unsigned long V_25 )
{
const char * V_29 ;
char V_30 [ V_31 + 1 ] ;
int V_32 ;
if ( V_24 -> V_26 != V_27 )
return V_25 ;
F_11 ( V_24 -> V_33 , V_30 , V_34 , sizeof( V_30 ) ) ;
for ( V_32 = 0 ; ( V_29 = V_35 [ V_32 ] ) != NULL ; V_32 ++ ) {
if ( ! strcmp ( V_29 , V_30 ) )
V_25 &= ~ ( 0xE0 << V_36 ) ;
}
return V_25 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
static const T_1 V_37 [] = { 0x5d , 0x47 , 0x34 , 0x22 , 0x20 } ;
int V_38 = 1 + 2 * V_2 -> V_8 - V_24 -> V_39 ;
int V_40 = ( 2 * V_2 -> V_8 + V_24 -> V_39 ) * 4 ;
T_2 V_41 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_42 = V_24 -> V_37 - V_43 ;
F_13 ( V_4 , 0x40 + V_38 , V_37 [ V_42 ] ) ;
if ( F_8 ( V_4 ) ) {
F_14 ( V_4 , 0x4A , & V_41 ) ;
V_41 &= ~ ( 0x0F << V_40 ) ;
F_15 ( V_4 , 0x4A , V_41 | ( V_42 << V_40 ) ) ;
}
}
static void F_16 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
static const T_1 V_44 [] = { 0x77 , 0x21 , 0x20 } ;
int V_38 = 1 + 2 * V_2 -> V_8 - V_24 -> V_39 ;
int V_40 = 2 * V_2 -> V_8 + V_24 -> V_39 ;
T_1 V_45 ;
T_1 V_46 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
F_17 ( V_4 , 0x54 , & V_46 ) ;
F_17 ( V_4 , 0x56 + V_2 -> V_8 , & V_45 ) ;
V_45 &= ~ ( 0x0F << ( V_24 -> V_39 * 4 ) ) ;
if ( V_24 -> V_44 >= V_47 ) {
F_13 ( V_4 , 0x44 + V_38 , 0x20 ) ;
V_45 |= ( V_24 -> V_44 - V_47 )
<< ( V_24 -> V_39 * 4 ) ;
V_46 |= ( 1 << V_40 ) ;
} else {
F_13 ( V_4 , 0x44 + V_38 ,
V_44 [ V_24 -> V_44 - V_48 ] ) ;
V_46 &= ~ ( 1 << V_40 ) ;
}
F_13 ( V_4 , 0x56 + V_2 -> V_8 , V_45 ) ;
F_13 ( V_4 , 0x54 , V_46 ) ;
}
static int F_18 ( struct V_3 * V_4 )
{
T_3 V_49 ;
struct V_3 * V_50 = F_19 ( V_51 ,
V_52 , NULL ) ;
if ( V_50 ) {
F_20 ( V_50 , 0x64 , & V_49 ) ;
V_49 &= ~ 0x00002000 ;
if ( ! ( V_49 & 0x00004000 ) )
F_21 (KERN_DEBUG DRV_NAME L_1 ) ;
V_49 |= 0x00004000 ;
F_22 ( V_50 , 0x64 , V_49 ) ;
F_23 ( V_50 ) ;
return 0 ;
}
F_21 (KERN_WARNING DRV_NAME L_2 ) ;
return - V_53 ;
}
static int F_24 ( struct V_3 * V_4 )
{
T_1 V_54 ;
if ( ! ( F_25 ( V_4 -> V_55 ) & 1 ) ) {
struct V_3 * V_56 = NULL ;
T_3 V_57 = 0 ;
V_56 = F_19 ( V_51 ,
V_58 , NULL ) ;
if ( V_56 ) {
F_20 ( V_56 , 0x4C , & V_57 ) ;
V_57 &= ~ 0x000007FF ;
V_57 |= 0x00000040 ;
V_57 |= 0x00000020 ;
F_22 ( V_56 , 0x4C , V_57 ) ;
F_23 ( V_56 ) ;
}
} else {
struct V_3 * V_56 = NULL ;
T_1 V_59 = 0 ;
V_56 = F_19 ( V_51 ,
V_60 , NULL ) ;
if ( V_56 ) {
F_17 ( V_56 , 0x41 , & V_59 ) ;
V_59 &= ~ 0x40 ;
F_13 ( V_56 , 0x41 , V_59 ) ;
F_23 ( V_56 ) ;
}
}
F_17 ( V_4 , 0x5A , & V_54 ) ;
V_54 &= ~ 0x40 ;
if ( ! ( F_25 ( V_4 -> V_55 ) & 1 ) )
V_54 |= 0x2 ;
else
V_54 |= ( V_4 -> V_61 >= V_62 ) ? 0x3 : 0x2 ;
F_13 ( V_4 , 0x5A , V_54 ) ;
return V_54 ;
}
static void F_26 ( struct V_3 * V_4 )
{
T_1 V_54 ;
F_17 ( V_4 , 0x5A , & V_54 ) ;
V_54 &= ~ 0x40 ;
V_54 |= 0x3 ;
F_13 ( V_4 , 0x5A , V_54 ) ;
}
static int F_27 ( struct V_3 * V_4 , const struct V_63 * V_33 )
{
static const struct V_64 V_65 [ 4 ] = {
{
. V_66 = V_67 ,
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_73 ,
. V_74 = & V_75
} , {
. V_66 = V_67 ,
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_74 = & V_75
} , {
. V_66 = V_67 ,
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_76 ,
. V_74 = & V_77
} , {
. V_66 = V_67 ,
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_78 ,
. V_74 = & V_77
}
} ;
const struct V_64 * V_79 [] = { & V_65 [ V_33 -> V_80 ] , NULL } ;
int V_81 ;
V_81 = F_28 ( V_4 ) ;
if ( V_81 )
return V_81 ;
F_13 ( V_4 , V_82 , 0x40 ) ;
if ( V_4 -> V_15 == V_83 ) {
if ( F_18 ( V_4 ) < 0 )
V_79 [ 0 ] = & V_65 [ 1 ] ;
}
else if ( ( V_4 -> V_15 == V_19 ) ||
( V_4 -> V_15 == V_20 ) ||
( V_4 -> V_15 == V_21 ) ) {
if ( F_24 ( V_4 ) == 3 )
V_79 [ 0 ] = & V_65 [ 3 ] ;
if ( V_4 -> V_15 == V_21 )
V_79 [ 1 ] = & V_84 ;
}
else if ( V_4 -> V_15 == V_22 )
F_26 ( V_4 ) ;
if ( V_4 -> V_15 == V_19 )
F_29 ( V_4 ) ;
return F_30 ( V_4 , V_79 , & V_85 , NULL , 0 ) ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_86 * V_5 = F_32 ( & V_4 -> V_6 ) ;
int V_81 ;
V_81 = F_33 ( V_4 ) ;
if ( V_81 )
return V_81 ;
F_13 ( V_4 , V_82 , 0x40 ) ;
switch ( V_4 -> V_15 ) {
case V_83 :
F_18 ( V_4 ) ;
break;
case V_19 :
F_29 ( V_4 ) ;
case V_20 :
case V_21 :
F_24 ( V_4 ) ;
break;
case V_22 :
F_26 ( V_4 ) ;
break;
}
F_34 ( V_5 ) ;
return 0 ;
}
static int T_4 F_35 ( void )
{
return F_36 ( & V_87 ) ;
}
static void T_5 F_37 ( void )
{
F_38 ( & V_87 ) ;
}
