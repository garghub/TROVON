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
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
if ( V_12 -> V_13 . type != V_14 )
return - V_15 ;
if ( V_12 -> V_13 . V_16 != V_2 -> V_16 )
return - V_17 ;
V_12 -> V_18 = V_7 -> V_12 ;
V_12 -> V_19 = V_7 -> V_19 ;
return 0 ;
}
static int F_11 ( struct V_9 * V_10 ,
struct V_20 * V_3 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
if ( V_3 -> V_13 . type != V_14 || V_3 -> V_3 > 0x26 )
return - V_15 ;
if ( V_3 -> V_13 . V_16 != V_2 -> V_16 )
return - V_17 ;
V_3 -> V_21 = F_1 ( V_2 , V_3 -> V_3 ) ;
if ( V_3 -> V_21 > 0xffff )
return - V_22 ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
struct V_20 * V_3 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
if ( V_3 -> V_13 . type != V_14 || V_3 -> V_3 > 0x26 )
return - V_15 ;
if ( V_3 -> V_13 . V_16 != V_2 -> V_16 )
return - V_17 ;
if ( F_3 ( V_2 , V_3 -> V_3 , V_3 -> V_21 ) < 0 )
return - V_22 ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
F_14 ( & V_24 -> V_25 , 0 , 720 , 2 ,
& V_24 -> V_26 , 0 , V_7 -> V_27 , 1 , 0 ) ;
V_24 -> V_28 = V_29 ;
V_24 -> V_30 = V_31 ;
V_24 -> V_32 = V_33 ;
return 0 ;
}
static int F_15 ( struct V_9 * V_10 ,
struct V_23 * V_24 )
{
if ( V_24 -> V_28 != V_29 ||
V_24 -> V_30 != V_31 )
return - V_15 ;
return F_13 ( V_10 , V_24 ) ;
}
static int F_16 ( struct V_9 * V_10 , unsigned int V_34 ,
enum V_35 * V_30 )
{
if ( V_34 )
return - V_15 ;
* V_30 = V_31 ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
V_37 -> V_38 . V_39 = 0 ;
V_37 -> V_38 . V_40 = 0 ;
V_37 -> V_38 . V_25 = 720 ;
V_37 -> V_38 . V_26 = V_7 -> V_27 ;
V_37 -> V_41 = V_37 -> V_38 ;
V_37 -> type = V_42 ;
V_37 -> V_43 . V_44 = 1 ;
V_37 -> V_43 . V_45 = 1 ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 , T_2 V_46 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
T_1 V_47 ;
if ( V_46 == V_48 ) {
V_47 = 3 ;
V_7 -> V_27 = 480 ;
} else if ( V_46 == V_49 ) {
V_47 = 5 ;
V_7 -> V_27 = 480 ;
} else if ( V_46 == V_50 ) {
V_47 = 7 ;
V_7 -> V_27 = 480 ;
} else if ( V_46 && ! ( V_46 & ~ V_51 ) ) {
V_47 = 0xf ;
V_7 -> V_27 = 576 ;
} else if ( V_46 && ! ( V_46 & ~ V_52 ) ) {
V_47 = 0 ;
V_7 -> V_27 = 480 ;
} else {
return - V_15 ;
}
F_5 ( V_2 , V_53 , V_47 , 0xf ) ;
return 0 ;
}
static int F_19 ( struct V_9 * V_10 , int V_54 )
{
struct V_1 * V_2 = F_10 ( V_10 ) ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
if ( V_54 ) {
T_1 V_55 ;
if ( V_7 -> V_56 -> V_57 & V_58 )
V_55 = 3 ;
else
V_55 = 4 ;
F_3 ( V_2 , V_59 , V_55 ) ;
F_20 ( & V_2 -> V_60 , L_1 ,
F_1 ( V_2 , V_61 ) ) ;
} else {
F_3 ( V_2 , V_59 , 0 ) ;
F_20 ( & V_2 -> V_60 , L_1 ,
F_1 ( V_2 , V_61 ) ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
struct V_64 * V_65 = F_22 ( V_2 -> V_60 . V_66 ) ;
struct V_7 * V_7 ;
T_1 V_67 , V_4 ;
if ( ! F_23 ( V_65 , V_68 ) ) {
F_24 ( & V_65 -> V_60 ,
L_2 ) ;
return - V_22 ;
}
V_7 = F_25 ( sizeof( struct V_7 ) , V_69 ) ;
if ( ! V_7 )
return - V_70 ;
F_26 ( & V_7 -> V_8 , V_2 , & V_71 ) ;
V_4 = F_1 ( V_2 , V_72 ) ;
switch ( V_4 ) {
case 0x13 :
V_7 -> V_12 = V_73 ;
break;
case 0x14 :
V_7 -> V_12 = V_74 ;
break;
default:
F_27 ( & V_2 -> V_60 ,
L_3 , V_4 ) ;
F_28 ( V_7 ) ;
return - V_17 ;
}
V_7 -> V_19 = F_1 ( V_2 , V_75 ) ;
V_7 -> V_56 = V_2 -> V_60 . V_76 ;
if ( V_7 -> V_56 ) {
if ( V_7 -> V_56 -> V_57 & V_77 )
V_67 = 4 ;
else
V_67 = 0 ;
switch ( V_7 -> V_56 -> V_57 & V_78 ) {
case V_79 :
V_67 |= 1 ;
break;
case V_80 :
V_67 |= 2 ;
break;
case V_81 :
default:
break;
}
F_20 ( & V_2 -> V_60 , L_4 , V_67 ) ;
F_3 ( V_2 , V_82 , V_67 | ( 20 << 3 ) ) ;
}
V_7 -> V_27 = 480 ;
F_29 ( & V_2 -> V_60 , L_5 ,
V_4 , V_7 -> V_19 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_6 ( V_2 ) ;
F_31 ( & V_7 -> V_8 ) ;
F_28 ( V_7 ) ;
return 0 ;
}
