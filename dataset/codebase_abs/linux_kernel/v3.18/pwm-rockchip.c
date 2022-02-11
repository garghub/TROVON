static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_4 ,
struct V_5 * V_6 , bool V_7 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
T_1 V_9 = V_10 | V_11 ;
T_1 V_12 ;
V_12 = F_4 ( V_8 -> V_13 + V_8 -> V_14 -> V_15 . V_16 ) ;
if ( V_7 )
V_12 |= V_9 ;
else
V_12 &= ~ V_9 ;
F_5 ( V_12 , V_8 -> V_13 + V_8 -> V_14 -> V_15 . V_16 ) ;
}
static void F_6 ( struct V_2 * V_4 ,
struct V_5 * V_6 , bool V_7 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
T_1 V_9 = V_17 | V_18 | V_19 |
V_20 ;
T_1 V_12 ;
if ( V_6 -> V_21 == V_22 )
V_9 |= V_23 | V_24 ;
else
V_9 |= V_25 | V_26 ;
V_12 = F_4 ( V_8 -> V_13 + V_8 -> V_14 -> V_15 . V_16 ) ;
if ( V_7 )
V_12 |= V_9 ;
else
V_12 &= ~ V_9 ;
F_5 ( V_12 , V_8 -> V_13 + V_8 -> V_14 -> V_15 . V_16 ) ;
}
static int F_7 ( struct V_2 * V_4 , struct V_5 * V_6 ,
int V_27 , int V_28 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
unsigned long V_29 , V_30 ;
T_2 V_31 , div ;
int V_32 ;
V_31 = F_8 ( V_8 -> V_33 ) ;
div = V_31 * V_28 ;
F_9 ( div , V_8 -> V_14 -> V_34 * V_35 ) ;
V_29 = div ;
div = V_31 * V_27 ;
F_9 ( div , V_8 -> V_14 -> V_34 * V_35 ) ;
V_30 = div ;
V_32 = F_10 ( V_8 -> V_33 ) ;
if ( V_32 )
return V_32 ;
F_11 ( V_29 , V_8 -> V_13 + V_8 -> V_14 -> V_15 . V_29 ) ;
F_11 ( V_30 , V_8 -> V_13 + V_8 -> V_14 -> V_15 . V_30 ) ;
F_11 ( 0 , V_8 -> V_13 + V_8 -> V_14 -> V_15 . V_36 ) ;
F_12 ( V_8 -> V_33 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_4 ,
struct V_5 * V_6 ,
enum V_37 V_21 )
{
return 0 ;
}
static int F_14 ( struct V_2 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
int V_32 ;
V_32 = F_10 ( V_8 -> V_33 ) ;
if ( V_32 )
return V_32 ;
V_8 -> V_14 -> V_38 ( V_4 , V_6 , true ) ;
return 0 ;
}
static void F_15 ( struct V_2 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
V_8 -> V_14 -> V_38 ( V_4 , V_6 , false ) ;
F_12 ( V_8 -> V_33 ) ;
}
static int F_16 ( struct V_39 * V_40 )
{
const struct V_41 * V_42 ;
struct V_1 * V_8 ;
struct V_43 * V_44 ;
int V_32 ;
V_42 = F_17 ( V_45 , & V_40 -> V_46 ) ;
if ( ! V_42 )
return - V_47 ;
V_8 = F_18 ( & V_40 -> V_46 , sizeof( * V_8 ) , V_48 ) ;
if ( ! V_8 )
return - V_49 ;
V_44 = F_19 ( V_40 , V_50 , 0 ) ;
V_8 -> V_13 = F_20 ( & V_40 -> V_46 , V_44 ) ;
if ( F_21 ( V_8 -> V_13 ) )
return F_22 ( V_8 -> V_13 ) ;
V_8 -> V_33 = F_23 ( & V_40 -> V_46 , NULL ) ;
if ( F_21 ( V_8 -> V_33 ) )
return F_22 ( V_8 -> V_33 ) ;
V_32 = F_24 ( V_8 -> V_33 ) ;
if ( V_32 )
return V_32 ;
F_25 ( V_40 , V_8 ) ;
V_8 -> V_14 = V_42 -> V_14 ;
V_8 -> V_4 . V_46 = & V_40 -> V_46 ;
V_8 -> V_4 . V_51 = V_8 -> V_14 -> V_51 ;
V_8 -> V_4 . V_13 = - 1 ;
V_8 -> V_4 . V_52 = 1 ;
if ( V_8 -> V_14 -> V_51 -> V_53 ) {
V_8 -> V_4 . V_54 = V_55 ;
V_8 -> V_4 . V_56 = 3 ;
}
V_32 = F_26 ( & V_8 -> V_4 ) ;
if ( V_32 < 0 ) {
F_27 ( V_8 -> V_33 ) ;
F_28 ( & V_40 -> V_46 , L_1 , V_32 ) ;
}
return V_32 ;
}
static int F_29 ( struct V_39 * V_40 )
{
struct V_1 * V_8 = F_30 ( V_40 ) ;
F_27 ( V_8 -> V_33 ) ;
return F_31 ( & V_8 -> V_4 ) ;
}
