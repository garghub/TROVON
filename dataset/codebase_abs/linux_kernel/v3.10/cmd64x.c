static void F_1 ( T_1 * V_1 , T_2 V_2 )
{
T_3 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_1 -> V_3 -> V_5 ) ;
int V_6 = V_7 ? V_7 : 33 ;
const unsigned long V_8 = 1000000 / V_6 ;
static const T_2 V_9 [] =
{ 15 , 15 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 0 } ;
static const T_2 V_10 [] = { 0x40 , 0x40 , 0x40 , 0x80 , 0 , 0xc0 } ;
static const T_2 V_11 [ 4 ] = { V_12 , V_13 , V_14 , V_14 } ;
static const T_2 V_15 [ 4 ] = { V_16 , V_17 , V_18 , V_19 } ;
struct V_20 V_21 ;
T_2 V_22 = 0 ;
F_3 ( V_1 , V_2 , & V_21 , V_8 , 0 ) ;
if ( V_21 . V_23 > 16 ) {
V_21 . V_24 += V_21 . V_23 - 16 ;
V_21 . V_23 = 16 ;
}
if ( V_21 . V_24 > 16 )
V_21 . V_24 = 16 ;
V_21 . V_23 = V_9 [ V_21 . V_23 ] ;
V_21 . V_24 &= 0x0f ;
F_4 ( V_5 , V_15 [ V_1 -> V_25 ] ,
( V_21 . V_24 << 4 ) | V_21 . V_23 ) ;
if ( V_3 -> V_26 ) {
T_1 * V_27 = F_5 ( V_1 ) ;
if ( V_27 ) {
struct V_20 V_28 ;
F_3 ( V_27 , V_27 -> V_29 , & V_28 , V_8 , 0 ) ;
F_6 ( & V_21 , & V_28 , & V_21 , V_30 ) ;
if ( V_27 -> V_31 ) {
F_3 ( V_27 , V_27 -> V_31 ,
& V_28 , V_8 , 0 ) ;
F_6 ( & V_28 , & V_21 , & V_21 , V_30 ) ;
}
}
}
if ( V_21 . V_32 > 5 )
V_21 . V_32 = 5 ;
( void ) F_7 ( V_5 , V_11 [ V_1 -> V_25 ] , & V_22 ) ;
if ( V_3 -> V_26 )
V_22 &= ~ V_33 ;
V_22 &= ~ 0xc0 ;
V_22 |= V_10 [ V_21 . V_32 ] ;
( void ) F_4 ( V_5 , V_11 [ V_1 -> V_25 ] , V_22 ) ;
}
static void F_8 ( T_3 * V_3 , T_1 * V_1 )
{
const T_2 V_34 = V_1 -> V_29 - V_35 ;
if ( V_34 == 8 || V_34 == 9 )
return;
F_1 ( V_1 , V_35 + V_34 ) ;
}
static void F_9 ( T_3 * V_3 , T_1 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_5 ) ;
T_2 V_36 = V_1 -> V_25 & 0x01 ;
T_2 V_37 = 0 , V_38 = V_3 -> V_26 ? V_39 : V_40 ;
const T_2 V_41 = V_1 -> V_31 ;
F_7 ( V_5 , V_38 , & V_37 ) ;
V_37 &= ~ ( V_36 ? 0xCA : 0x35 ) ;
switch( V_41 ) {
case V_42 :
V_37 |= V_36 ? 0x0A : 0x05 ;
break;
case V_43 :
V_37 |= V_36 ? 0x4A : 0x15 ;
break;
case V_44 :
V_37 |= V_36 ? 0x8A : 0x25 ;
break;
case V_45 :
V_37 |= V_36 ? 0x42 : 0x11 ;
break;
case V_46 :
V_37 |= V_36 ? 0x82 : 0x21 ;
break;
case V_47 :
V_37 |= V_36 ? 0xC2 : 0x31 ;
break;
case V_48 :
case V_49 :
case V_50 :
F_1 ( V_1 , V_41 ) ;
break;
}
F_4 ( V_5 , V_38 , V_37 ) ;
}
static void F_10 ( T_1 * V_1 )
{
T_3 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 -> V_5 ) ;
unsigned long V_51 = F_11 ( V_5 , 4 ) ;
T_2 V_52 = V_3 -> V_26 ? V_53 :
V_54 ;
T_2 V_55 = F_12 ( V_51 + 1 ) ;
F_13 ( ( V_55 & ~ ( V_54 | V_53 ) ) | V_52 ,
V_51 + 1 ) ;
}
static void F_14 ( T_1 * V_1 )
{
T_3 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 -> V_5 ) ;
int V_56 = V_3 -> V_26 ? V_14 : V_57 ;
T_2 V_52 = V_3 -> V_26 ? V_33 :
V_58 ;
T_2 V_59 = 0 ;
( void ) F_7 ( V_5 , V_56 , & V_59 ) ;
( void ) F_4 ( V_5 , V_56 , V_59 | V_52 ) ;
}
static int F_15 ( T_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_5 ) ;
unsigned long V_51 = F_11 ( V_5 , 4 ) ;
T_2 V_52 = V_3 -> V_26 ? V_53 :
V_54 ;
T_2 V_55 = F_12 ( V_51 + 1 ) ;
F_16 ( L_1 ,
V_3 -> V_60 , V_55 , V_52 ) ;
return ( V_55 & V_52 ) ? 1 : 0 ;
}
static int F_17 ( T_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_5 ) ;
int V_56 = V_3 -> V_26 ? V_14 : V_57 ;
T_2 V_52 = V_3 -> V_26 ? V_33 :
V_58 ;
T_2 V_59 = 0 ;
( void ) F_7 ( V_5 , V_56 , & V_59 ) ;
F_16 ( L_2 ,
V_3 -> V_60 , V_59 , V_52 ) ;
return ( V_59 & V_52 ) ? 1 : 0 ;
}
static int F_18 ( T_1 * V_1 )
{
T_3 * V_3 = V_1 -> V_3 ;
T_2 V_61 = 0 , V_62 = 0 ;
V_61 = F_12 ( V_3 -> V_63 + V_64 ) ;
V_62 = F_12 ( V_3 -> V_63 + V_65 ) ;
F_13 ( V_62 & ~ 1 , V_3 -> V_63 + V_65 ) ;
F_13 ( V_61 | 6 , V_3 -> V_63 + V_64 ) ;
return ( V_61 & 7 ) != 4 ;
}
static int F_19 ( struct V_4 * V_5 )
{
T_2 V_55 = 0 ;
( void ) F_4 ( V_5 , V_66 , 64 ) ;
( void ) F_7 ( V_5 , V_67 , & V_55 ) ;
V_55 &= ~ 0x30 ;
( void ) F_4 ( V_5 , V_67 , ( V_55 | 0x02 ) ) ;
return 0 ;
}
static T_2 F_20 ( T_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_5 ) ;
T_2 V_68 = 0 , V_69 = V_3 -> V_26 ? 0x02 : 0x01 ;
switch ( V_5 -> V_70 ) {
case V_71 :
case V_72 :
F_7 ( V_5 , V_73 , & V_68 ) ;
return ( V_68 & V_69 ) ? V_74 : V_75 ;
default:
return V_75 ;
}
}
static int F_21 ( struct V_4 * V_5 , const struct V_76 * V_77 )
{
struct V_78 V_79 ;
T_2 V_80 = V_77 -> V_81 ;
V_79 = V_82 [ V_80 ] ;
if ( V_80 == 1 ) {
if ( V_5 -> V_83 < 5 ) {
V_79 . V_84 = 0x00 ;
if ( V_5 -> V_83 < 3 ) {
V_79 . V_85 [ 0 ] . V_86 = 0 ;
V_79 . V_87 = & V_88 ;
if ( V_5 -> V_83 == 1 )
V_79 . V_89 = & V_90 ;
}
}
}
return F_22 ( V_5 , & V_79 , NULL ) ;
}
static int T_4 F_23 ( void )
{
return F_24 ( & V_91 ) ;
}
static void T_5 F_25 ( void )
{
F_26 ( & V_91 ) ;
}
