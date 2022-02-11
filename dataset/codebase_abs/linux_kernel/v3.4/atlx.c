static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
switch ( V_5 ) {
case V_6 :
case V_7 :
case V_8 :
return F_2 ( V_2 , V_4 , V_5 ) ;
default:
return - V_9 ;
}
}
static int F_3 ( struct V_1 * V_2 , void * V_10 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
struct V_13 * V_14 = V_10 ;
if ( F_5 ( V_2 ) )
return - V_15 ;
if ( ! F_6 ( V_14 -> V_16 ) )
return - V_17 ;
memcpy ( V_2 -> V_18 , V_14 -> V_16 , V_2 -> V_19 ) ;
memcpy ( V_12 -> V_20 . V_21 , V_14 -> V_16 , V_2 -> V_19 ) ;
V_2 -> V_22 &= ~ V_23 ;
F_7 ( & V_12 -> V_20 ) ;
return 0 ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
T_1 V_24 = 0 ;
F_9 ( & V_12 -> V_25 ) ;
V_12 -> V_26 = false ;
F_10 ( & V_12 -> V_20 , V_27 , & V_24 ) ;
F_10 ( & V_12 -> V_20 , V_27 , & V_24 ) ;
F_11 ( & V_12 -> V_25 ) ;
if ( ! ( V_24 & V_28 ) ) {
if ( F_12 ( V_2 ) ) {
F_13 ( & V_12 -> V_29 -> V_30 , L_1 ,
V_2 -> V_31 ) ;
V_12 -> V_32 = V_33 ;
F_14 ( V_2 ) ;
}
}
F_15 ( & V_12 -> V_34 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
struct V_35 * V_20 = & V_12 -> V_20 ;
struct V_36 * V_37 ;
T_2 V_38 ;
T_2 V_39 ;
V_38 = F_17 ( V_20 -> V_40 + V_41 ) ;
if ( V_2 -> V_42 & V_43 )
V_38 |= V_44 ;
else if ( V_2 -> V_42 & V_45 ) {
V_38 |= V_46 ;
V_38 &= ~ V_44 ;
} else
V_38 &= ~ ( V_44 | V_46 ) ;
F_18 ( V_38 , V_20 -> V_40 + V_41 ) ;
F_18 ( 0 , V_20 -> V_40 + V_47 ) ;
F_18 ( 0 , ( V_20 -> V_40 + V_47 ) + ( 1 << 2 ) ) ;
F_19 (ha, netdev) {
V_39 = F_20 ( V_20 , V_37 -> V_14 ) ;
F_21 ( V_20 , V_39 ) ;
}
}
static void F_22 ( struct V_11 * V_12 )
{
F_18 ( V_48 , V_12 -> V_20 . V_40 + V_49 ) ;
F_17 ( V_12 -> V_20 . V_40 + V_49 ) ;
}
static void F_23 ( struct V_11 * V_12 )
{
F_18 ( 0 , V_12 -> V_20 . V_40 + V_49 ) ;
F_17 ( V_12 -> V_20 . V_40 + V_49 ) ;
F_24 ( V_12 -> V_29 -> V_50 ) ;
}
static void F_25 ( struct V_11 * V_12 )
{
T_1 V_24 ;
unsigned long V_42 ;
F_26 ( & V_12 -> V_25 , V_42 ) ;
F_10 ( & V_12 -> V_20 , 19 , & V_24 ) ;
F_27 ( & V_12 -> V_25 , V_42 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
F_15 ( & V_12 -> V_51 ) ;
}
static void F_29 ( struct V_52 * V_53 )
{
struct V_11 * V_12 ;
unsigned long V_42 ;
V_12 = F_30 ( V_53 , struct V_11 , V_34 ) ;
F_26 ( & V_12 -> V_25 , V_42 ) ;
F_31 ( V_12 ) ;
F_27 ( & V_12 -> V_25 , V_42 ) ;
}
static void F_32 ( T_3 V_54 , T_2 * V_55 )
{
if ( V_54 & V_56 ) {
* V_55 |= V_57 ;
} else {
* V_55 &= ~ V_57 ;
}
}
static void F_33 ( struct V_1 * V_2 ,
T_3 V_54 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
unsigned long V_42 ;
T_2 V_55 ;
F_26 ( & V_12 -> V_25 , V_42 ) ;
V_55 = F_17 ( V_12 -> V_20 . V_40 + V_41 ) ;
F_32 ( V_54 , & V_55 ) ;
F_18 ( V_55 , V_12 -> V_20 . V_40 + V_41 ) ;
F_27 ( & V_12 -> V_25 , V_42 ) ;
}
static void F_34 ( struct V_11 * V_12 )
{
F_33 ( V_12 -> V_2 , V_12 -> V_2 -> V_54 ) ;
}
static T_3 F_35 ( struct V_1 * V_2 ,
T_3 V_54 )
{
if ( V_54 & V_56 )
V_54 |= V_58 ;
else
V_54 &= ~ V_58 ;
return V_54 ;
}
static int F_36 ( struct V_1 * V_2 ,
T_3 V_54 )
{
T_3 V_59 = V_2 -> V_54 ^ V_54 ;
if ( V_59 & V_56 )
F_33 ( V_2 , V_54 ) ;
return 0 ;
}
