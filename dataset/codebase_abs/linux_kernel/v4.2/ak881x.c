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
struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_19 ;
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
if ( V_19 -> V_22 )
return - V_12 ;
F_13 ( & V_21 -> V_23 , 0 , 720 , 2 ,
& V_21 -> V_24 , 0 , V_7 -> V_25 , 1 , 0 ) ;
V_21 -> V_26 = V_27 ;
V_21 -> V_28 = V_29 ;
V_21 -> V_30 = V_31 ;
return 0 ;
}
static int F_14 ( struct V_9 * V_10 ,
struct V_16 * V_17 ,
struct V_32 * V_28 )
{
if ( V_28 -> V_22 || V_28 -> V_33 )
return - V_12 ;
V_28 -> V_28 = V_29 ;
return 0 ;
}
static int F_15 ( struct V_9 * V_10 , struct V_34 * V_35 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
V_35 -> V_36 . V_37 = 0 ;
V_35 -> V_36 . V_38 = 0 ;
V_35 -> V_36 . V_23 = 720 ;
V_35 -> V_36 . V_24 = V_7 -> V_25 ;
V_35 -> V_39 = V_35 -> V_36 ;
V_35 -> type = V_40 ;
V_35 -> V_41 . V_42 = 1 ;
V_35 -> V_41 . V_43 = 1 ;
return 0 ;
}
static int F_16 ( struct V_9 * V_10 , T_2 V_44 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
T_1 V_45 ;
if ( V_44 == V_46 ) {
V_45 = 3 ;
V_7 -> V_25 = 480 ;
} else if ( V_44 == V_47 ) {
V_45 = 5 ;
V_7 -> V_25 = 480 ;
} else if ( V_44 == V_48 ) {
V_45 = 7 ;
V_7 -> V_25 = 480 ;
} else if ( V_44 && ! ( V_44 & ~ V_49 ) ) {
V_45 = 0xf ;
V_7 -> V_25 = 576 ;
} else if ( V_44 && ! ( V_44 & ~ V_50 ) ) {
V_45 = 0 ;
V_7 -> V_25 = 480 ;
} else {
return - V_12 ;
}
F_5 ( V_2 , V_51 , V_45 , 0xf ) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 , int V_52 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
if ( V_52 ) {
T_1 V_53 ;
if ( V_7 -> V_54 -> V_55 & V_56 )
V_53 = 3 ;
else
V_53 = 4 ;
F_3 ( V_2 , V_57 , V_53 ) ;
F_18 ( & V_2 -> V_58 , L_1 ,
F_1 ( V_2 , V_59 ) ) ;
} else {
F_3 ( V_2 , V_57 , 0 ) ;
F_18 ( & V_2 -> V_58 , L_1 ,
F_1 ( V_2 , V_59 ) ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_60 * V_61 )
{
struct V_62 * V_63 = F_20 ( V_2 -> V_58 . V_64 ) ;
struct V_7 * V_7 ;
T_1 V_65 , V_4 ;
if ( ! F_21 ( V_63 , V_66 ) ) {
F_22 ( & V_63 -> V_58 ,
L_2 ) ;
return - V_15 ;
}
V_7 = F_23 ( & V_2 -> V_58 , sizeof( * V_7 ) , V_67 ) ;
if ( ! V_7 )
return - V_68 ;
F_24 ( & V_7 -> V_8 , V_2 , & V_69 ) ;
V_4 = F_1 ( V_2 , V_70 ) ;
switch ( V_4 ) {
case 0x13 :
case 0x14 :
break;
default:
F_25 ( & V_2 -> V_58 ,
L_3 , V_4 ) ;
return - V_71 ;
}
V_7 -> V_72 = F_1 ( V_2 , V_73 ) ;
V_7 -> V_54 = V_2 -> V_58 . V_74 ;
if ( V_7 -> V_54 ) {
if ( V_7 -> V_54 -> V_55 & V_75 )
V_65 = 4 ;
else
V_65 = 0 ;
switch ( V_7 -> V_54 -> V_55 & V_76 ) {
case V_77 :
V_65 |= 1 ;
break;
case V_78 :
V_65 |= 2 ;
break;
case V_79 :
default:
break;
}
F_18 ( & V_2 -> V_58 , L_4 , V_65 ) ;
F_3 ( V_2 , V_80 , V_65 | ( 20 << 3 ) ) ;
}
V_7 -> V_25 = 480 ;
F_26 ( & V_2 -> V_58 , L_5 ,
V_4 , V_7 -> V_72 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_6 ( V_2 ) ;
F_28 ( & V_7 -> V_8 ) ;
return 0 ;
}
