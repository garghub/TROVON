static int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 && V_4 [ V_3 ] . V_1 == V_1 )
return V_3 ;
}
return - V_5 ;
}
static int F_3 ( struct V_6 * V_7 ,
int V_8 , unsigned int V_9 , int V_10 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
switch ( V_9 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_14 -> V_15 = V_9 ;
return 0 ;
}
return - V_5 ;
}
static int F_5 ( struct V_6 * V_7 ,
unsigned int V_16 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
T_1 V_17 = 0 ;
switch ( V_16 & V_18 ) {
case V_19 :
V_17 = 0x0040 ;
break;
case V_20 :
break;
default:
return - V_5 ;
}
switch ( V_16 & V_21 ) {
case V_22 :
V_17 |= 0x0002 ;
break;
case V_23 :
break;
case V_24 :
V_17 |= 0x0001 ;
break;
case V_25 :
V_17 |= 0x0003 ;
break;
case V_26 :
V_17 |= 0x0013 ;
break;
default:
return - V_5 ;
}
switch ( V_16 & V_27 ) {
case V_28 :
break;
case V_29 :
V_17 |= 0x0090 ;
break;
case V_30 :
V_17 |= 0x0080 ;
break;
case V_31 :
V_17 |= 0x0010 ;
break;
default:
return - V_5 ;
}
F_6 ( V_12 , V_32 , V_17 ) ;
return 0 ;
}
static int F_7 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_6 * V_37 )
{
struct V_38 * V_39 = V_34 -> V_40 ;
struct V_11 * V_12 = V_39 -> V_12 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
T_1 V_17 = F_8 ( V_12 , V_32 ) & 0x1f3 ;
T_1 V_41 = F_8 ( V_12 , V_42 ) & 0x1c0 ;
int V_43 = F_1 ( V_14 -> V_15 , F_9 ( V_36 ) ) ;
switch ( F_10 ( V_36 ) ) {
case V_44 :
break;
case V_45 :
V_17 |= 0x0004 ;
break;
case V_46 :
V_17 |= 0x0008 ;
break;
case V_47 :
V_17 |= 0x000c ;
break;
}
F_6 ( V_12 , V_32 , V_17 ) ;
if ( V_43 >= 0 )
F_6 ( V_12 , V_42 , V_41 |
( V_4 [ V_43 ] . V_48 << 1 ) | V_4 [ V_43 ] . V_49 ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_37 , int V_50 )
{
struct V_11 * V_12 = V_37 -> V_12 ;
T_1 V_51 = F_8 ( V_12 , V_52 ) & 0xfff7 ;
if ( V_50 )
F_6 ( V_12 , V_52 , V_51 | 0x8 ) ;
else
F_6 ( V_12 , V_52 , V_51 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 ,
enum V_53 V_54 )
{
T_1 V_55 = F_8 ( V_12 , V_56 ) & 0xfe3e ;
switch ( V_54 ) {
case V_57 :
F_6 ( V_12 , V_56 , V_55 | 0x00c1 ) ;
break;
case V_58 :
break;
case V_59 :
if ( V_12 -> V_60 . V_61 == V_62 )
F_13 ( V_12 ) ;
F_6 ( V_12 , V_56 , V_55 | 0x0140 ) ;
break;
case V_62 :
F_6 ( V_12 , V_56 , 0x0001 ) ;
break;
}
V_12 -> V_60 . V_61 = V_54 ;
return 0 ;
}
static void F_14 ( struct V_63 * V_64 )
{
struct V_65 * V_60 =
F_15 ( V_64 , struct V_65 ,
V_66 . V_64 ) ;
struct V_11 * V_12 = V_60 -> V_12 ;
F_12 ( V_12 , V_12 -> V_60 . V_61 ) ;
}
static int F_16 ( struct V_11 * V_12 )
{
F_12 ( V_12 , V_62 ) ;
return 0 ;
}
static int F_17 ( struct V_11 * V_12 )
{
T_1 V_67 ;
F_12 ( V_12 , V_59 ) ;
if ( V_12 -> V_60 . V_68 == V_57 ) {
V_67 = F_8 ( V_12 , V_56 ) & 0xfe3e ;
F_6 ( V_12 , V_56 , V_67 | 0x01c0 ) ;
V_12 -> V_60 . V_61 = V_57 ;
F_18 ( V_69 , & V_12 -> V_60 . V_66 ,
F_19 ( 1000 ) ) ;
}
return 0 ;
}
static int F_20 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
int V_70 = 0 ;
T_1 V_67 ;
V_70 = F_21 ( V_12 , 7 , 9 , V_14 -> V_71 ) ;
if ( V_70 < 0 ) {
F_22 ( V_72 L_1 , V_70 ) ;
return V_70 ;
}
F_23 ( & V_12 -> V_60 . V_66 , F_14 ) ;
V_69 = F_24 ( L_2 ) ;
if ( V_69 == NULL )
return - V_73 ;
F_25 ( V_12 ) ;
V_67 = F_8 ( V_12 , V_56 ) & 0xfe3e ;
F_6 ( V_12 , V_56 , V_67 | 0x01c0 ) ;
V_12 -> V_60 . V_61 = V_59 ;
F_18 ( V_69 , & V_12 -> V_60 . V_66 ,
F_19 ( 1000 ) ) ;
F_26 ( V_12 , V_74 , 0x0100 , 0x0100 ) ;
F_26 ( V_12 , V_75 , 0x0100 , 0x0100 ) ;
F_26 ( V_12 , V_76 , 0x0100 , 0x0100 ) ;
F_26 ( V_12 , V_77 , 0x0100 , 0x0100 ) ;
F_26 ( V_12 , V_78 , 0x0100 , 0x0100 ) ;
F_26 ( V_12 , V_79 , 0x0100 , 0x0100 ) ;
F_26 ( V_12 , V_80 , 0x0100 , 0x0100 ) ;
F_26 ( V_12 , V_81 , 0x0100 , 0x0100 ) ;
return V_70 ;
}
static int F_27 ( struct V_11 * V_12 )
{
F_12 ( V_12 , V_62 ) ;
if ( V_69 )
F_28 ( V_69 ) ;
return 0 ;
}
static T_2 int F_29 ( struct V_82 * V_83 ,
const struct V_84 * V_85 )
{
struct V_13 * V_14 ;
int V_70 ;
V_14 = F_30 ( & V_83 -> V_86 , sizeof( struct V_13 ) ,
V_87 ) ;
if ( V_14 == NULL )
return - V_73 ;
V_14 -> V_71 = V_88 ;
F_31 ( V_83 , V_14 ) ;
V_70 = F_32 ( & V_83 -> V_86 ,
& V_89 , & V_90 , 1 ) ;
return V_70 ;
}
static T_3 int F_33 ( struct V_82 * V_91 )
{
F_34 ( & V_91 -> V_86 ) ;
return 0 ;
}
static int T_4 F_35 ( void )
{
int V_70 = 0 ;
V_70 = F_36 ( & V_92 ) ;
if ( V_70 != 0 ) {
F_22 ( V_72 L_3 ,
V_70 ) ;
}
return V_70 ;
}
static void T_5 F_37 ( void )
{
F_38 ( & V_92 ) ;
}
