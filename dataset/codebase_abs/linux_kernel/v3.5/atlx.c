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
static inline void F_22 ( struct V_11 * V_12 ,
unsigned int V_48 )
{
F_18 ( V_48 , V_12 -> V_20 . V_40 + V_49 ) ;
F_17 ( V_12 -> V_20 . V_40 + V_49 ) ;
}
static void F_23 ( struct V_11 * V_12 )
{
F_22 ( V_12 , V_50 ) ;
V_12 -> V_51 = true ;
}
static void F_24 ( struct V_11 * V_12 )
{
V_12 -> V_51 = false ;
F_22 ( V_12 , 0 ) ;
F_25 ( V_12 -> V_29 -> V_52 ) ;
}
static void F_26 ( struct V_11 * V_12 )
{
T_1 V_24 ;
unsigned long V_42 ;
F_27 ( & V_12 -> V_25 , V_42 ) ;
F_10 ( & V_12 -> V_20 , 19 , & V_24 ) ;
F_28 ( & V_12 -> V_25 , V_42 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
F_15 ( & V_12 -> V_53 ) ;
}
static void F_30 ( struct V_54 * V_55 )
{
struct V_11 * V_12 ;
unsigned long V_42 ;
V_12 = F_31 ( V_55 , struct V_11 , V_34 ) ;
F_27 ( & V_12 -> V_25 , V_42 ) ;
F_32 ( V_12 ) ;
F_28 ( & V_12 -> V_25 , V_42 ) ;
}
static void F_33 ( T_3 V_56 , T_2 * V_57 )
{
if ( V_56 & V_58 ) {
* V_57 |= V_59 ;
} else {
* V_57 &= ~ V_59 ;
}
}
static void F_34 ( struct V_1 * V_2 ,
T_3 V_56 )
{
struct V_11 * V_12 = F_4 ( V_2 ) ;
unsigned long V_42 ;
T_2 V_57 ;
F_27 ( & V_12 -> V_25 , V_42 ) ;
V_57 = F_17 ( V_12 -> V_20 . V_40 + V_41 ) ;
F_33 ( V_56 , & V_57 ) ;
F_18 ( V_57 , V_12 -> V_20 . V_40 + V_41 ) ;
F_28 ( & V_12 -> V_25 , V_42 ) ;
}
static void F_35 ( struct V_11 * V_12 )
{
F_34 ( V_12 -> V_2 , V_12 -> V_2 -> V_56 ) ;
}
static T_3 F_36 ( struct V_1 * V_2 ,
T_3 V_56 )
{
if ( V_56 & V_58 )
V_56 |= V_60 ;
else
V_56 &= ~ V_60 ;
return V_56 ;
}
static int F_37 ( struct V_1 * V_2 ,
T_3 V_56 )
{
T_3 V_61 = V_2 -> V_56 ^ V_56 ;
if ( V_61 & V_58 )
F_34 ( V_2 , V_56 ) ;
return 0 ;
}
