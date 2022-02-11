static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_4 , bool V_5 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
T_1 V_7 = V_8 | V_9 ;
T_1 V_10 ;
V_10 = F_4 ( V_6 -> V_11 + V_6 -> V_12 -> V_13 . V_14 ) ;
if ( V_5 )
V_10 |= V_7 ;
else
V_10 &= ~ V_7 ;
F_5 ( V_10 , V_6 -> V_11 + V_6 -> V_12 -> V_13 . V_14 ) ;
}
static void F_6 ( struct V_2 * V_4 , bool V_5 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
T_1 V_7 = V_15 | V_16 | V_17 |
V_18 | V_19 |
V_20 ;
T_1 V_10 ;
V_10 = F_4 ( V_6 -> V_11 + V_6 -> V_12 -> V_13 . V_14 ) ;
if ( V_5 )
V_10 |= V_7 ;
else
V_10 &= ~ V_7 ;
F_5 ( V_10 , V_6 -> V_11 + V_6 -> V_12 -> V_13 . V_14 ) ;
}
static int F_7 ( struct V_2 * V_4 , struct V_21 * V_22 ,
int V_23 , int V_24 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_25 , V_26 ;
T_2 V_27 , div ;
int V_28 ;
V_27 = F_8 ( V_6 -> V_29 ) ;
div = V_27 * V_24 ;
F_9 ( div , V_6 -> V_12 -> V_30 * V_31 ) ;
V_25 = div ;
div = V_27 * V_23 ;
F_9 ( div , V_6 -> V_12 -> V_30 * V_31 ) ;
V_26 = div ;
V_28 = F_10 ( V_6 -> V_29 ) ;
if ( V_28 )
return V_28 ;
F_11 ( V_25 , V_6 -> V_11 + V_6 -> V_12 -> V_13 . V_25 ) ;
F_11 ( V_26 , V_6 -> V_11 + V_6 -> V_12 -> V_13 . V_26 ) ;
F_11 ( 0 , V_6 -> V_11 + V_6 -> V_12 -> V_13 . V_32 ) ;
F_12 ( V_6 -> V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_4 , struct V_21 * V_22 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
int V_28 ;
V_28 = F_10 ( V_6 -> V_29 ) ;
if ( V_28 )
return V_28 ;
V_6 -> V_12 -> V_33 ( V_4 , true ) ;
return 0 ;
}
static void F_14 ( struct V_2 * V_4 , struct V_21 * V_22 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
V_6 -> V_12 -> V_33 ( V_4 , false ) ;
F_12 ( V_6 -> V_29 ) ;
}
static int F_15 ( struct V_34 * V_35 )
{
const struct V_36 * V_37 ;
struct V_1 * V_6 ;
struct V_38 * V_39 ;
int V_28 ;
V_37 = F_16 ( V_40 , & V_35 -> V_41 ) ;
if ( ! V_37 )
return - V_42 ;
V_6 = F_17 ( & V_35 -> V_41 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 )
return - V_44 ;
V_39 = F_18 ( V_35 , V_45 , 0 ) ;
V_6 -> V_11 = F_19 ( & V_35 -> V_41 , V_39 ) ;
if ( F_20 ( V_6 -> V_11 ) )
return F_21 ( V_6 -> V_11 ) ;
V_6 -> V_29 = F_22 ( & V_35 -> V_41 , NULL ) ;
if ( F_20 ( V_6 -> V_29 ) )
return F_21 ( V_6 -> V_29 ) ;
V_28 = F_23 ( V_6 -> V_29 ) ;
if ( V_28 )
return V_28 ;
F_24 ( V_35 , V_6 ) ;
V_6 -> V_12 = V_37 -> V_12 ;
V_6 -> V_4 . V_41 = & V_35 -> V_41 ;
V_6 -> V_4 . V_46 = & V_47 ;
V_6 -> V_4 . V_11 = - 1 ;
V_6 -> V_4 . V_48 = 1 ;
V_28 = F_25 ( & V_6 -> V_4 ) ;
if ( V_28 < 0 ) {
F_26 ( V_6 -> V_29 ) ;
F_27 ( & V_35 -> V_41 , L_1 , V_28 ) ;
}
return V_28 ;
}
static int F_28 ( struct V_34 * V_35 )
{
struct V_1 * V_6 = F_29 ( V_35 ) ;
F_26 ( V_6 -> V_29 ) ;
return F_30 ( & V_6 -> V_4 ) ;
}
