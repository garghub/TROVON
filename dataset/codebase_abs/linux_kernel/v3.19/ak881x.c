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
T_2 * V_23 )
{
if ( V_27 )
return - V_12 ;
* V_23 = V_24 ;
return 0 ;
}
static int F_16 ( struct V_9 * V_10 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
V_29 -> V_30 . V_31 = 0 ;
V_29 -> V_30 . V_32 = 0 ;
V_29 -> V_30 . V_18 = 720 ;
V_29 -> V_30 . V_19 = V_7 -> V_20 ;
V_29 -> V_33 = V_29 -> V_30 ;
V_29 -> type = V_34 ;
V_29 -> V_35 . V_36 = 1 ;
V_29 -> V_35 . V_37 = 1 ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 , T_3 V_38 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
T_1 V_39 ;
if ( V_38 == V_40 ) {
V_39 = 3 ;
V_7 -> V_20 = 480 ;
} else if ( V_38 == V_41 ) {
V_39 = 5 ;
V_7 -> V_20 = 480 ;
} else if ( V_38 == V_42 ) {
V_39 = 7 ;
V_7 -> V_20 = 480 ;
} else if ( V_38 && ! ( V_38 & ~ V_43 ) ) {
V_39 = 0xf ;
V_7 -> V_20 = 576 ;
} else if ( V_38 && ! ( V_38 & ~ V_44 ) ) {
V_39 = 0 ;
V_7 -> V_20 = 480 ;
} else {
return - V_12 ;
}
F_5 ( V_2 , V_45 , V_39 , 0xf ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 , int V_46 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
if ( V_46 ) {
T_1 V_47 ;
if ( V_7 -> V_48 -> V_49 & V_50 )
V_47 = 3 ;
else
V_47 = 4 ;
F_3 ( V_2 , V_51 , V_47 ) ;
F_19 ( & V_2 -> V_52 , L_1 ,
F_1 ( V_2 , V_53 ) ) ;
} else {
F_3 ( V_2 , V_51 , 0 ) ;
F_19 ( & V_2 -> V_52 , L_1 ,
F_1 ( V_2 , V_53 ) ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_54 * V_55 )
{
struct V_56 * V_57 = F_21 ( V_2 -> V_52 . V_58 ) ;
struct V_7 * V_7 ;
T_1 V_59 , V_4 ;
if ( ! F_22 ( V_57 , V_60 ) ) {
F_23 ( & V_57 -> V_52 ,
L_2 ) ;
return - V_15 ;
}
V_7 = F_24 ( & V_2 -> V_52 , sizeof( * V_7 ) , V_61 ) ;
if ( ! V_7 )
return - V_62 ;
F_25 ( & V_7 -> V_8 , V_2 , & V_63 ) ;
V_4 = F_1 ( V_2 , V_64 ) ;
switch ( V_4 ) {
case 0x13 :
case 0x14 :
break;
default:
F_26 ( & V_2 -> V_52 ,
L_3 , V_4 ) ;
return - V_65 ;
}
V_7 -> V_66 = F_1 ( V_2 , V_67 ) ;
V_7 -> V_48 = V_2 -> V_52 . V_68 ;
if ( V_7 -> V_48 ) {
if ( V_7 -> V_48 -> V_49 & V_69 )
V_59 = 4 ;
else
V_59 = 0 ;
switch ( V_7 -> V_48 -> V_49 & V_70 ) {
case V_71 :
V_59 |= 1 ;
break;
case V_72 :
V_59 |= 2 ;
break;
case V_73 :
default:
break;
}
F_19 ( & V_2 -> V_52 , L_4 , V_59 ) ;
F_3 ( V_2 , V_74 , V_59 | ( 20 << 3 ) ) ;
}
V_7 -> V_20 = 480 ;
F_27 ( & V_2 -> V_52 , L_5 ,
V_4 , V_7 -> V_66 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_6 ( V_2 ) ;
F_29 ( & V_7 -> V_8 ) ;
return 0 ;
}
