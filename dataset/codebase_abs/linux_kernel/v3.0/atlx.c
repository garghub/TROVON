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
F_7 ( & V_12 -> V_20 ) ;
return 0 ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
T_1 V_22 = 0 ;
F_9 ( & V_12 -> V_23 ) ;
V_12 -> V_24 = false ;
F_10 ( & V_12 -> V_20 , V_25 , & V_22 ) ;
F_10 ( & V_12 -> V_20 , V_25 , & V_22 ) ;
F_11 ( & V_12 -> V_23 ) ;
if ( ! ( V_22 & V_26 ) ) {
if ( F_12 ( V_2 ) ) {
F_13 ( & V_12 -> V_27 -> V_28 , L_1 ,
V_2 -> V_29 ) ;
V_12 -> V_30 = V_31 ;
F_14 ( V_2 ) ;
}
}
F_15 ( & V_12 -> V_32 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
struct V_33 * V_20 = & V_12 -> V_20 ;
struct V_34 * V_35 ;
T_2 V_36 ;
T_2 V_37 ;
V_36 = F_17 ( V_20 -> V_38 + V_39 ) ;
if ( V_2 -> V_40 & V_41 )
V_36 |= V_42 ;
else if ( V_2 -> V_40 & V_43 ) {
V_36 |= V_44 ;
V_36 &= ~ V_42 ;
} else
V_36 &= ~ ( V_42 | V_44 ) ;
F_18 ( V_36 , V_20 -> V_38 + V_39 ) ;
F_18 ( 0 , V_20 -> V_38 + V_45 ) ;
F_18 ( 0 , ( V_20 -> V_38 + V_45 ) + ( 1 << 2 ) ) ;
F_19 (ha, netdev) {
V_37 = F_20 ( V_20 , V_35 -> V_14 ) ;
F_21 ( V_20 , V_37 ) ;
}
}
static void F_22 ( struct V_11 * V_12 )
{
F_18 ( V_46 , V_12 -> V_20 . V_38 + V_47 ) ;
F_17 ( V_12 -> V_20 . V_38 + V_47 ) ;
}
static void F_23 ( struct V_11 * V_12 )
{
F_18 ( 0 , V_12 -> V_20 . V_38 + V_47 ) ;
F_17 ( V_12 -> V_20 . V_38 + V_47 ) ;
F_24 ( V_12 -> V_27 -> V_48 ) ;
}
static void F_25 ( struct V_11 * V_12 )
{
T_1 V_22 ;
unsigned long V_40 ;
F_26 ( & V_12 -> V_23 , V_40 ) ;
F_10 ( & V_12 -> V_20 , 19 , & V_22 ) ;
F_27 ( & V_12 -> V_23 , V_40 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
F_15 ( & V_12 -> V_49 ) ;
}
static void F_29 ( struct V_50 * V_51 )
{
struct V_11 * V_12 ;
unsigned long V_40 ;
V_12 = F_30 ( V_51 , struct V_11 , V_32 ) ;
F_26 ( & V_12 -> V_23 , V_40 ) ;
F_31 ( V_12 ) ;
F_27 ( & V_12 -> V_23 , V_40 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
unsigned long V_40 ;
T_2 V_54 ;
F_26 ( & V_12 -> V_23 , V_40 ) ;
V_12 -> V_55 = V_53 ;
if ( V_53 ) {
V_54 = F_17 ( V_12 -> V_20 . V_38 + V_39 ) ;
V_54 |= V_56 ;
F_18 ( V_54 , V_12 -> V_20 . V_38 + V_39 ) ;
} else {
V_54 = F_17 ( V_12 -> V_20 . V_38 + V_39 ) ;
V_54 &= ~ V_56 ;
F_18 ( V_54 , V_12 -> V_20 . V_38 + V_39 ) ;
}
F_27 ( & V_12 -> V_23 , V_40 ) ;
}
static void F_33 ( struct V_11 * V_12 )
{
F_32 ( V_12 -> V_2 , V_12 -> V_55 ) ;
}
