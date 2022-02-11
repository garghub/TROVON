static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
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
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = F_3 ( V_13 ) ;
T_1 V_16 ;
T_2 V_17 , V_18 ;
if ( ! V_15 -> V_19 )
return - V_20 ;
V_17 = ( F_4 ( V_13 , V_21 ) >> 2 ) + 1 ;
V_16 = ( 1 << 22 ) ;
V_16 *= F_5 ( V_9 ) ;
V_16 *= V_17 ;
F_6 ( V_16 , V_15 -> V_19 ) ;
F_7 ( V_13 , V_22 , ( V_16 >> 8 ) & 0x7f ) ;
F_7 ( V_13 , V_23 , V_16 & 0xff ) ;
switch ( F_8 ( V_9 ) ) {
case V_24 :
V_18 = 0 ;
break;
case V_25 :
V_18 = 0x2 ;
break;
case V_26 :
V_18 = 0x3 ;
break;
default:
return - V_20 ;
}
F_9 ( V_13 , V_27 , 0x3 , V_18 ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_28 ,
int V_29 , unsigned int V_30 , int V_31 )
{
struct V_12 * V_13 = V_28 -> V_13 ;
struct V_14 * V_15 = F_3 ( V_13 ) ;
if ( V_30 <= 13000000 )
F_7 ( V_13 , V_21 , 0x0 ) ;
else if ( V_30 <= 26000000 )
F_7 ( V_13 , V_21 , 0x4 ) ;
else if ( V_30 <= 40000000 )
F_7 ( V_13 , V_21 , 0x8 ) ;
else
return - V_20 ;
V_15 -> V_19 = V_30 ;
return 0 ;
}
static int F_11 ( struct V_10 * V_28 , unsigned int V_32 )
{
struct V_12 * V_13 = V_28 -> V_13 ;
T_2 V_18 = 0 ;
switch ( V_32 & V_33 ) {
case V_34 :
V_18 |= V_35 ;
break;
case V_36 :
break;
default:
return - V_20 ;
}
switch ( V_32 & V_37 ) {
case V_38 :
V_18 |= V_39 ;
break;
case V_40 :
V_18 |= V_41 ;
break;
case V_42 :
break;
default:
return - V_20 ;
}
switch ( V_32 & V_43 ) {
case V_44 :
break;
case V_45 :
V_18 |= V_46 | V_47 ;
break;
case V_48 :
V_18 |= V_46 ;
break;
case V_49 :
V_18 |= V_47 ;
break;
default:
return - V_20 ;
}
F_7 ( V_13 , V_27 , V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 ,
enum V_50 V_51 )
{
struct V_14 * V_15 = F_3 ( V_13 ) ;
int V_52 ;
switch ( V_51 ) {
case V_53 :
break;
case V_54 :
break;
case V_55 :
if ( V_13 -> V_56 . V_57 == V_58 ) {
V_52 = F_13 ( V_15 -> V_59 ) ;
if ( V_52 ) {
F_14 ( V_13 -> V_2 ,
L_1 , V_52 ) ;
return V_52 ;
}
}
break;
case V_58 :
break;
}
V_13 -> V_56 . V_57 = V_51 ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 )
{
F_12 ( V_13 , V_58 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 )
{
F_12 ( V_13 , V_55 ) ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 )
{
int V_52 ;
V_52 = F_18 ( V_13 , 8 , 8 , V_60 ) ;
if ( V_52 < 0 ) {
F_14 ( V_13 -> V_2 , L_2 , V_52 ) ;
return V_52 ;
}
F_9 ( V_13 , V_61 , 1 , 1 ) ;
F_9 ( V_13 , V_62 , 0x40 , 0x40 ) ;
F_9 ( V_13 , V_63 , 0xff , 0xc0 ) ;
return 0 ;
}
static int F_19 ( struct V_64 * V_65 ,
const struct V_66 * V_67 )
{
struct V_14 * V_15 ;
int V_52 ;
V_15 = F_20 ( & V_65 -> V_2 , sizeof( struct V_14 ) ,
V_68 ) ;
if ( V_15 == NULL )
return - V_69 ;
V_15 -> V_59 = F_21 ( V_65 , & V_70 ) ;
if ( F_22 ( V_15 -> V_59 ) )
return F_23 ( V_15 -> V_59 ) ;
F_24 ( V_65 , V_15 ) ;
V_52 = F_25 ( & V_65 -> V_2 ,
& V_71 , & V_72 , 1 ) ;
return V_52 ;
}
static int F_26 ( struct V_64 * V_73 )
{
F_27 ( & V_73 -> V_2 ) ;
return 0 ;
}
