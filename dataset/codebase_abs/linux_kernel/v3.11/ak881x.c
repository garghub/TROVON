static int F_1 ( struct V_1 * V_2 , const T_1 V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 V_4 )
{
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 V_4 , T_1 V_5 )
{
int V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_3 ( V_2 , V_3 , ( V_6 & ~ V_5 ) | ( V_4 & V_5 ) ) ;
}
static struct V_7 * F_6 ( const struct V_1 * V_2 )
{
return F_7 ( F_8 ( V_2 ) , struct V_7 , V_8 ) ;
}
static int F_9 ( struct V_9 * V_10 ,
struct V_11 * V_3 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
if ( V_3 -> V_3 > 0x26 )
return - V_12 ;
V_3 -> V_13 = 1 ;
V_3 -> V_14 = F_1 ( V_2 , V_3 -> V_3 ) ;
if ( V_3 -> V_14 > 0xffff )
return - V_15 ;
return 0 ;
}
static int F_11 ( struct V_9 * V_10 ,
const struct V_11 * V_3 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
if ( V_3 -> V_3 > 0x26 )
return - V_12 ;
if ( F_3 ( V_2 , V_3 -> V_3 , V_3 -> V_14 ) < 0 )
return - V_15 ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
F_13 ( & V_17 -> V_18 , 0 , 720 , 2 ,
& V_17 -> V_19 , 0 , V_7 -> V_20 , 1 , 0 ) ;
V_17 -> V_21 = V_22 ;
V_17 -> V_23 = V_24 ;
V_17 -> V_25 = V_26 ;
return 0 ;
}
static int F_14 ( struct V_9 * V_10 ,
struct V_16 * V_17 )
{
if ( V_17 -> V_21 != V_22 ||
V_17 -> V_23 != V_24 )
return - V_12 ;
return F_12 ( V_10 , V_17 ) ;
}
static int F_15 ( struct V_9 * V_10 , unsigned int V_27 ,
enum V_28 * V_23 )
{
if ( V_27 )
return - V_12 ;
* V_23 = V_24 ;
return 0 ;
}
static int F_16 ( struct V_9 * V_10 , struct V_29 * V_30 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
V_30 -> V_31 . V_32 = 0 ;
V_30 -> V_31 . V_33 = 0 ;
V_30 -> V_31 . V_18 = 720 ;
V_30 -> V_31 . V_19 = V_7 -> V_20 ;
V_30 -> V_34 = V_30 -> V_31 ;
V_30 -> type = V_35 ;
V_30 -> V_36 . V_37 = 1 ;
V_30 -> V_36 . V_38 = 1 ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 , T_2 V_39 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
T_1 V_40 ;
if ( V_39 == V_41 ) {
V_40 = 3 ;
V_7 -> V_20 = 480 ;
} else if ( V_39 == V_42 ) {
V_40 = 5 ;
V_7 -> V_20 = 480 ;
} else if ( V_39 == V_43 ) {
V_40 = 7 ;
V_7 -> V_20 = 480 ;
} else if ( V_39 && ! ( V_39 & ~ V_44 ) ) {
V_40 = 0xf ;
V_7 -> V_20 = 576 ;
} else if ( V_39 && ! ( V_39 & ~ V_45 ) ) {
V_40 = 0 ;
V_7 -> V_20 = 480 ;
} else {
return - V_12 ;
}
F_5 ( V_2 , V_46 , V_40 , 0xf ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 , int V_47 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
if ( V_47 ) {
T_1 V_48 ;
if ( V_7 -> V_49 -> V_50 & V_51 )
V_48 = 3 ;
else
V_48 = 4 ;
F_3 ( V_2 , V_52 , V_48 ) ;
F_19 ( & V_2 -> V_53 , L_1 ,
F_1 ( V_2 , V_54 ) ) ;
} else {
F_3 ( V_2 , V_52 , 0 ) ;
F_19 ( & V_2 -> V_53 , L_1 ,
F_1 ( V_2 , V_54 ) ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_55 * V_56 )
{
struct V_57 * V_58 = F_21 ( V_2 -> V_53 . V_59 ) ;
struct V_7 * V_7 ;
T_1 V_60 , V_4 ;
if ( ! F_22 ( V_58 , V_61 ) ) {
F_23 ( & V_58 -> V_53 ,
L_2 ) ;
return - V_15 ;
}
V_7 = F_24 ( & V_2 -> V_53 , sizeof( * V_7 ) , V_62 ) ;
if ( ! V_7 )
return - V_63 ;
F_25 ( & V_7 -> V_8 , V_2 , & V_64 ) ;
V_4 = F_1 ( V_2 , V_65 ) ;
switch ( V_4 ) {
case 0x13 :
case 0x14 :
break;
default:
F_26 ( & V_2 -> V_53 ,
L_3 , V_4 ) ;
return - V_66 ;
}
V_7 -> V_67 = F_1 ( V_2 , V_68 ) ;
V_7 -> V_49 = V_2 -> V_53 . V_69 ;
if ( V_7 -> V_49 ) {
if ( V_7 -> V_49 -> V_50 & V_70 )
V_60 = 4 ;
else
V_60 = 0 ;
switch ( V_7 -> V_49 -> V_50 & V_71 ) {
case V_72 :
V_60 |= 1 ;
break;
case V_73 :
V_60 |= 2 ;
break;
case V_74 :
default:
break;
}
F_19 ( & V_2 -> V_53 , L_4 , V_60 ) ;
F_3 ( V_2 , V_75 , V_60 | ( 20 << 3 ) ) ;
}
V_7 -> V_20 = 480 ;
F_27 ( & V_2 -> V_53 , L_5 ,
V_4 , V_7 -> V_67 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_6 ( V_2 ) ;
F_29 ( & V_7 -> V_8 ) ;
return 0 ;
}
