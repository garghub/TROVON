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
if ( F_7 ( V_6 ) == V_21 )
V_9 |= V_22 | V_23 ;
else
V_9 |= V_24 | V_25 ;
V_12 = F_4 ( V_8 -> V_13 + V_8 -> V_14 -> V_15 . V_16 ) ;
if ( V_7 )
V_12 |= V_9 ;
else
V_12 &= ~ V_9 ;
F_5 ( V_12 , V_8 -> V_13 + V_8 -> V_14 -> V_15 . V_16 ) ;
}
static int F_8 ( struct V_2 * V_4 , struct V_5 * V_6 ,
int V_26 , int V_27 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
unsigned long V_28 , V_29 ;
T_2 V_30 , div ;
int V_31 ;
V_30 = F_9 ( V_8 -> V_32 ) ;
div = V_30 * V_27 ;
F_10 ( div , V_8 -> V_14 -> V_33 * V_34 ) ;
V_28 = div ;
div = V_30 * V_26 ;
F_10 ( div , V_8 -> V_14 -> V_33 * V_34 ) ;
V_29 = div ;
V_31 = F_11 ( V_8 -> V_32 ) ;
if ( V_31 )
return V_31 ;
F_12 ( V_28 , V_8 -> V_13 + V_8 -> V_14 -> V_15 . V_28 ) ;
F_12 ( V_29 , V_8 -> V_13 + V_8 -> V_14 -> V_15 . V_29 ) ;
F_12 ( 0 , V_8 -> V_13 + V_8 -> V_14 -> V_15 . V_35 ) ;
F_13 ( V_8 -> V_32 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_4 ,
struct V_5 * V_6 ,
enum V_36 V_37 )
{
return 0 ;
}
static int F_15 ( struct V_2 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
int V_31 ;
V_31 = F_11 ( V_8 -> V_32 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_14 -> V_38 ( V_4 , V_6 , true ) ;
return 0 ;
}
static void F_16 ( struct V_2 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
V_8 -> V_14 -> V_38 ( V_4 , V_6 , false ) ;
F_13 ( V_8 -> V_32 ) ;
}
static int F_17 ( struct V_39 * V_40 )
{
const struct V_41 * V_42 ;
struct V_1 * V_8 ;
struct V_43 * V_44 ;
int V_31 ;
V_42 = F_18 ( V_45 , & V_40 -> V_46 ) ;
if ( ! V_42 )
return - V_47 ;
V_8 = F_19 ( & V_40 -> V_46 , sizeof( * V_8 ) , V_48 ) ;
if ( ! V_8 )
return - V_49 ;
V_44 = F_20 ( V_40 , V_50 , 0 ) ;
V_8 -> V_13 = F_21 ( & V_40 -> V_46 , V_44 ) ;
if ( F_22 ( V_8 -> V_13 ) )
return F_23 ( V_8 -> V_13 ) ;
V_8 -> V_32 = F_24 ( & V_40 -> V_46 , NULL ) ;
if ( F_22 ( V_8 -> V_32 ) )
return F_23 ( V_8 -> V_32 ) ;
V_31 = F_25 ( V_8 -> V_32 ) ;
if ( V_31 )
return V_31 ;
F_26 ( V_40 , V_8 ) ;
V_8 -> V_14 = V_42 -> V_14 ;
V_8 -> V_4 . V_46 = & V_40 -> V_46 ;
V_8 -> V_4 . V_51 = V_8 -> V_14 -> V_51 ;
V_8 -> V_4 . V_13 = - 1 ;
V_8 -> V_4 . V_52 = 1 ;
if ( V_8 -> V_14 -> V_51 -> V_53 ) {
V_8 -> V_4 . V_54 = V_55 ;
V_8 -> V_4 . V_56 = 3 ;
}
V_31 = F_27 ( & V_8 -> V_4 ) ;
if ( V_31 < 0 ) {
F_28 ( V_8 -> V_32 ) ;
F_29 ( & V_40 -> V_46 , L_1 , V_31 ) ;
}
return V_31 ;
}
static int F_30 ( struct V_39 * V_40 )
{
struct V_1 * V_8 = F_31 ( V_40 ) ;
F_28 ( V_8 -> V_32 ) ;
return F_32 ( & V_8 -> V_4 ) ;
}
