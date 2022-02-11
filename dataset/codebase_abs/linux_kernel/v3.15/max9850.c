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
case 16 :
V_18 = 0 ;
break;
case 20 :
V_18 = 0x2 ;
break;
case 24 :
V_18 = 0x3 ;
break;
default:
return - V_20 ;
}
F_9 ( V_13 , V_24 , 0x3 , V_18 ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_25 ,
int V_26 , unsigned int V_27 , int V_28 )
{
struct V_12 * V_13 = V_25 -> V_13 ;
struct V_14 * V_15 = F_3 ( V_13 ) ;
if ( V_27 <= 13000000 )
F_7 ( V_13 , V_21 , 0x0 ) ;
else if ( V_27 <= 26000000 )
F_7 ( V_13 , V_21 , 0x4 ) ;
else if ( V_27 <= 40000000 )
F_7 ( V_13 , V_21 , 0x8 ) ;
else
return - V_20 ;
V_15 -> V_19 = V_27 ;
return 0 ;
}
static int F_11 ( struct V_10 * V_25 , unsigned int V_29 )
{
struct V_12 * V_13 = V_25 -> V_13 ;
T_2 V_18 = 0 ;
switch ( V_29 & V_30 ) {
case V_31 :
V_18 |= V_32 ;
break;
case V_33 :
break;
default:
return - V_20 ;
}
switch ( V_29 & V_34 ) {
case V_35 :
V_18 |= V_36 ;
break;
case V_37 :
V_18 |= V_38 ;
break;
case V_39 :
break;
default:
return - V_20 ;
}
switch ( V_29 & V_40 ) {
case V_41 :
break;
case V_42 :
V_18 |= V_43 | V_44 ;
break;
case V_45 :
V_18 |= V_43 ;
break;
case V_46 :
V_18 |= V_44 ;
break;
default:
return - V_20 ;
}
F_7 ( V_13 , V_24 , V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 ,
enum V_47 V_48 )
{
struct V_14 * V_15 = F_3 ( V_13 ) ;
int V_49 ;
switch ( V_48 ) {
case V_50 :
break;
case V_51 :
break;
case V_52 :
if ( V_13 -> V_53 . V_54 == V_55 ) {
V_49 = F_13 ( V_15 -> V_56 ) ;
if ( V_49 ) {
F_14 ( V_13 -> V_2 ,
L_1 , V_49 ) ;
return V_49 ;
}
}
break;
case V_55 :
break;
}
V_13 -> V_53 . V_54 = V_48 ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 )
{
F_12 ( V_13 , V_55 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 )
{
F_12 ( V_13 , V_52 ) ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 )
{
F_9 ( V_13 , V_57 , 1 , 1 ) ;
F_9 ( V_13 , V_58 , 0x40 , 0x40 ) ;
F_9 ( V_13 , V_59 , 0xff , 0xc0 ) ;
return 0 ;
}
static int F_18 ( struct V_60 * V_61 ,
const struct V_62 * V_63 )
{
struct V_14 * V_15 ;
int V_49 ;
V_15 = F_19 ( & V_61 -> V_2 , sizeof( struct V_14 ) ,
V_64 ) ;
if ( V_15 == NULL )
return - V_65 ;
V_15 -> V_56 = F_20 ( V_61 , & V_66 ) ;
if ( F_21 ( V_15 -> V_56 ) )
return F_22 ( V_15 -> V_56 ) ;
F_23 ( V_61 , V_15 ) ;
V_49 = F_24 ( & V_61 -> V_2 ,
& V_67 , & V_68 , 1 ) ;
return V_49 ;
}
static int F_25 ( struct V_60 * V_69 )
{
F_26 ( & V_69 -> V_2 ) ;
return 0 ;
}
