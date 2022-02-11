static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return 1 ;
default:
return 0 ;
}
}
static int F_2 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 * V_13 = F_3 ( V_2 ) ;
T_1 V_14 ;
T_2 V_15 , V_16 ;
if ( ! V_13 -> V_17 )
return - V_18 ;
V_15 = ( F_4 ( V_2 , V_19 ) >> 2 ) + 1 ;
V_14 = ( 1 << 22 ) ;
V_14 *= F_5 ( V_9 ) ;
V_14 *= V_15 ;
F_6 ( V_14 , V_13 -> V_17 ) ;
F_7 ( V_2 , V_20 , ( V_14 >> 8 ) & 0x7f ) ;
F_7 ( V_2 , V_21 , V_14 & 0xff ) ;
switch ( F_8 ( V_9 ) ) {
case V_22 :
V_16 = 0 ;
break;
case V_23 :
V_16 = 0x2 ;
break;
case V_24 :
V_16 = 0x3 ;
break;
default:
return - V_18 ;
}
F_9 ( V_2 , V_25 , 0x3 , V_16 ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_26 ,
int V_27 , unsigned int V_28 , int V_29 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_12 * V_13 = F_3 ( V_2 ) ;
if ( V_28 <= 13000000 )
F_7 ( V_2 , V_19 , 0x0 ) ;
else if ( V_28 <= 26000000 )
F_7 ( V_2 , V_19 , 0x4 ) ;
else if ( V_28 <= 40000000 )
F_7 ( V_2 , V_19 , 0x8 ) ;
else
return - V_18 ;
V_13 -> V_17 = V_28 ;
return 0 ;
}
static int F_11 ( struct V_10 * V_26 , unsigned int V_30 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
T_2 V_16 = 0 ;
switch ( V_30 & V_31 ) {
case V_32 :
V_16 |= V_33 ;
break;
case V_34 :
break;
default:
return - V_18 ;
}
switch ( V_30 & V_35 ) {
case V_36 :
V_16 |= V_37 ;
break;
case V_38 :
V_16 |= V_39 ;
break;
case V_40 :
break;
default:
return - V_18 ;
}
switch ( V_30 & V_41 ) {
case V_42 :
break;
case V_43 :
V_16 |= V_44 | V_45 ;
break;
case V_46 :
V_16 |= V_44 ;
break;
case V_47 :
V_16 |= V_45 ;
break;
default:
return - V_18 ;
}
F_7 ( V_2 , V_25 , V_16 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
enum V_48 V_49 )
{
int V_50 ;
switch ( V_49 ) {
case V_51 :
break;
case V_52 :
break;
case V_53 :
if ( V_2 -> V_54 . V_55 == V_56 ) {
V_50 = F_13 ( V_2 ) ;
if ( V_50 ) {
F_14 ( V_2 -> V_57 ,
L_1 , V_50 ) ;
return V_50 ;
}
}
break;
case V_56 :
break;
}
V_2 -> V_54 . V_55 = V_49 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_3 V_58 )
{
F_12 ( V_2 , V_56 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_53 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_59 * V_54 = & V_2 -> V_54 ;
int V_50 ;
V_50 = F_18 ( V_2 , 8 , 8 , V_60 ) ;
if ( V_50 < 0 ) {
F_14 ( V_2 -> V_57 , L_2 , V_50 ) ;
return V_50 ;
}
F_9 ( V_2 , V_61 , 1 , 1 ) ;
F_9 ( V_2 , V_62 , 0x40 , 0x40 ) ;
F_9 ( V_2 , V_63 , 0xff , 0xc0 ) ;
F_19 ( V_54 , V_64 ,
F_20 ( V_64 ) ) ;
F_21 ( V_54 , V_65 , F_20 ( V_65 ) ) ;
F_22 ( V_2 , V_66 ,
F_20 ( V_66 ) ) ;
return 0 ;
}
static int T_4 F_23 ( struct V_67 * V_68 ,
const struct V_69 * V_70 )
{
struct V_12 * V_13 ;
int V_50 ;
V_13 = F_24 ( sizeof( struct V_12 ) , V_71 ) ;
if ( V_13 == NULL )
return - V_72 ;
F_25 ( V_68 , V_13 ) ;
V_50 = F_26 ( & V_68 -> V_57 ,
& V_73 , & V_74 , 1 ) ;
if ( V_50 < 0 )
F_27 ( V_13 ) ;
return V_50 ;
}
static T_5 int F_28 ( struct V_67 * V_75 )
{
F_29 ( & V_75 -> V_57 ) ;
F_27 ( F_30 ( V_75 ) ) ;
return 0 ;
}
static int T_6 F_31 ( void )
{
return F_32 ( & V_76 ) ;
}
static void T_7 F_33 ( void )
{
F_34 ( & V_76 ) ;
}
